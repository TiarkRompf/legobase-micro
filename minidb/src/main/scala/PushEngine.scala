package miniDB


import scala.virtualization.lms.common._
import scala.virtualization.lms.common
import scala.virtualization.lms.internal._
import scala.virtualization.lms.util._
import java.io.{PrintWriter,StringWriter,FileOutputStream}
import scala.collection.mutable.HashMap
import scala.collection.mutable.ListBuffer
import scala.collection.mutable.ArrayBuffer



trait PushEngine extends DSL with DataStruct {
    abstract class Operator[+A:Manifest] {
        def desc: String = "op(?)"
        def open()
        def next()
        def reset()
        def consume(tuple: Rep[Record])
        var child: Operator[Any] = this
        var stop = unit(false)
    }
   
    case class ScanOp2[A<:Record:Manifest](table: LegoTable[A]) extends Operator[A] {
        override def desc = table.name
        var i = 0
        def open() {}
        def next() {
            println("begin scan "+table.name)
            while (!stop && i < table.data.length) {
                val v = table.data(i)
                i+=1
                child.consume(v)
            } 
        }
        def reset() { i = 0 }
        def consume(tuple: Rep[Record]) { throw new Exception("PUSH ENGINE BUG:: Consume function in ScanOp should never be called!!!!\n") }
    }

    case class PrintOp[A:Manifest](var parent: Operator[A])(printFunc: Rep[A] => Rep[Unit], limit: () => Rep[Boolean] = () => unit(true)) extends Operator[A] {
        var numRows = unit(0)
        def open() { parent.child = this; parent.open }
        def next() = parent.next
        def consume(tuple: Rep[Record]) {
            if (limit() == false) parent.stop = unit(true)
            else { 
                printFunc(tuple.asInstanceOf[Rep[A]]); 
                numRows += 1 
            }
        }
        def reset() { parent.reset }
    }

    case class SelectOp[A:Manifest](parent: Operator[A])(selectPred: Rep[A] => Rep[Boolean]) extends Operator[A] {
        override def desc = parent.desc
        def open() { parent.child = this; parent.open }
        def next() = parent.next
        def reset() { parent.reset }
        def consume(tuple: Rep[Record]) { 
            if (selectPred(tuple.asInstanceOf[Rep[A]])) child.consume(tuple) 
        }
    }
    

    case class AggOp1[A:Manifest, B:Manifest, C:Manifest](parent: Operator[A])(val grp: Rep[A] => Rep[B])(val init: Rep[C])(val aggFun: ((Rep[A], Rep[C]) => Rep[C])) extends Operator[AGGRecord1[B,C]] {
        override def desc = s"AGG(${parent.desc})"
 
        val elems = LegoCollect[AGGRecord1[B,C]]()
        val hash = LegoHash[B](1 << 22)(i => elems.buf(i).key)

        def open() { parent.child = this; parent.open }
        def next() {
            parent.next
            val res = elems.result
            for (i <- 0 until res.length) {
                child.consume(res(i))
            }
        }
        def reset() { parent.reset; printf("RESET / TODO"); open } // TODO / FIXME
        def consume(tuple: Rep[Record]) {
            val key = grp(tuple.asInstanceOf[Rep[A]])

            val ix = hash.put(key) { // new key
                elems.append(newAGGRecord1(key,init))
                // assert elems.len == hash.size
            }
            val cur = elems.buf(ix)
            val aggs = aggFun(tuple.asInstanceOf[Rep[A]], cur.aggs)
            elems.buf(ix) = newAGGRecord1(cur.key,aggs)
        }
    }

    // CURRENTLY UNUSED -- try linked hash table instead of open addressing
    case class AggOp2[A:Manifest, B:Manifest, C:Manifest](parent: Operator[A])(val grp: Rep[A] => Rep[B])(val init: Rep[C])(val aggFun: ((Rep[A], Rep[C]) => Rep[C])) extends Operator[AGGRecord1[B,C]] {
        override def desc = s"AGG(${parent.desc})"
 
        val hashSize = (1 << 20)
        val bucketSize = 1

        val dataSize = hashSize * bucketSize
        val data = LegoBuffer[AGGRecord1[B,C]](dataSize)
        val dataCount = var_new(0)

        val bucketHash = NewArray[Int](hashSize)
        val bucketNext = NewArray[Int](dataSize)

        for (i <- 0 until hashSize) {
            bucketHash(i) = -1
        }

        val hashMask = hashSize - 1

        def open() { parent.child = this; parent.open }
        def next() {
            parent.next
            for (i <- 0 until dataCount) {
                child.consume(data(i))
            }
        }
        def reset() { parent.reset; printf("RESET / TODO"); open } // TODO / FIXME
        def consume(tuple0: Rep[Record]) {
            val tuple = tuple0.asInstanceOf[Rep[A]]
            val k = grp(tuple)

            val h = calcHashCode(k)
            val bucket = h & hashMask

            var dataPos = bucketHash(bucket)
            while ({
              if (dataPos != -1) {
                val kcur = data(dataPos).key
                if (isEqual(kcur, k)) {
                  val cur = data(dataPos).aggs
                  val aggs = aggFun(tuple, cur)
                  data(dataPos) = newAGGRecord1(kcur,aggs)
                  false
                } else {
                  dataPos = bucketNext(dataPos)
                  true
                }
              } else {
                dataPos = dataCount: Rep[Int] // force read
                val aggs = aggFun(tuple, init)
                data(dataPos) = newAGGRecord1(k,aggs)
                dataCount += 1
                val next = bucketHash(bucket)
                bucketHash(bucket) = dataPos
                bucketNext(dataPos) = next
                false
              }
            }) {}

        }
    }


    case class MapOp1[A:Manifest,B:Manifest](parent: Operator[A])(aggFuncs: Rep[A] => Rep[B]) extends Operator[B] {
        override def desc = parent.desc
        def reset { parent.reset }
        def open() { parent.child = this; parent.open }
        def next() { parent.next }
        def consume(tuple: Rep[Record]) { 
            child.consume(aggFuncs(tuple.asInstanceOf[Rep[A]]).asInstanceOf[Rep[Record]])
        }
    }

    def MapCatOp[A<:Record:Manifest,B<:Record:Manifest](parent: Operator[CompositeRecord1[A,B]], leftAlias: String = "", rightAlias: String = ""): Operator[CompositeRecord[A,B]] = {
        import scala.reflect.{RefinedManifest,SourceContext}

        def union(left: Rep[A], right: Rep[B])(implicit pos: SourceContext) = {
            // register struct:
            left concatenate right
            val name1 = structName(manifest[A]).replace("CompositeRecord","")
            val name2 = structName(manifest[B]).replace("CompositeRecord","")

            val elemsA = recordFieldTypes[A] map { case (k,m) => (k,field(left,k)(m,pos)) }
            val elemsB = recordFieldTypes[B] map { case (k,m) => (k,field(right,k)(m,pos)) }
            record_new[CompositeRecord[A,B]](name1+name2, elemsA ++ elemsB)
        }

        MapOp1[CompositeRecord1[A,B],CompositeRecord[A,B]](parent)(xy => union(xy.left, xy.right))
    }

    
    case class SortOp[A:Manifest](parent: Operator[A])(orderingFunc: Function2[Rep[A],Rep[A],Rep[Int]]) extends Operator[A] {
        val sortedTree = TreeSet(orderingFunc)
        def next() = {
            parent.next
            while (sortedTree.size != 0) { 
                val elem = sortedTree.head
                sortedTree -= elem
                child.consume(elem.asInstanceOf[Rep[Record]])
            } 
        }
        def reset() { parent.reset; open } 
        def open() { parent.child = this; parent.open }
        def consume(tuple: Rep[Record]) { sortedTree insert tuple.asInstanceOf[Rep[A]] }
    }

    // not used except in Q17 -- otherwise just use agg
    case class WindowOp[A:Manifest,B:Manifest,C:Manifest](parent: Operator[A])(val grp: Function1[Rep[A], Rep[B]])(val wndf: Rep[ArrayBuffer[A]] => Rep[C]) extends Operator[ Record { val key: B; val wnd: C } ] {
        val hm = HashMap[B,ArrayBuffer[A]]()
        var keySet = hm.keySet

        def open() {
            parent.child = this
            parent.open
        }
        def reset() { parent.reset; hm.clear; open } 
        def next() {
            parent.next
            keySet = hm.keySet
            while (hm.size != 0) {
                val k = keySet.head
                keySet.remove(k)
                val elem = hashmap_remove(hm,k)
                child.consume(new Record {
                    val key = k
                    val wnd = wndf(elem)
                })
            }
        }
        def consume(tuple: Rep[Record]) {
            val t = tuple.asInstanceOf[Rep[A]]
            val key = grp(t)
            val v = hm.getOrElseUpdate(key, ArrayBuffer[A]())
            v.append(t)
        }
    }
    
    case class ViewOp[A<:Record:Manifest](parent: Operator[A], n: Int) extends Operator[A] { self =>
        var init: Boolean = false // static variable! *generate* code for self open only once
        val table = LegoCollect[A]()

        val sub = new Array[Operator[A]](n)
        for (i <- (0 until n):Range) {
            sub(i) = new Operator[A] {
                def open() { self.open() }
                def next() { 
                    val data = table.result
                    for (idx <- 0 until data.length) {
                        val e = data(idx)
                        child.consume(e)
                    }
                }
                def consume(tuple: PushEngine.this.Rep[PushEngine.this.Record]): Unit = { }
                def reset(): Unit = { }
            }
        }

        def open() {
            if (!init) {
                init = true
                parent.child = this
                parent.open
                parent.next
            }
        }
        def reset() { }
        def next() { }
        def consume(tuple: Rep[Record]) {
            table.append(tuple.asInstanceOf[Rep[A]])
        }
    }
 
    case class HashJoinAnti1[A<:Record:Manifest,B<:Record:Manifest,C:Manifest](leftParent: Operator[A], rightParent: Operator[B])(joinCond: (Rep[A],Rep[B])=>Rep[Boolean])(leftHash: Rep[A]=>Rep[C])(rightHash: Rep[B]=>Rep[C]) extends Operator[A] {
        override def desc = s"(${leftParent.desc} HJA-X ${rightParent.desc})"
        var mode: scala.Int = 0

        val hashSize = (1 << 20)
        val bucketSize = (1 << 10)

        val hm = new LegoLinkedHashMap[C,A](hashSize, bucketSize)

        def reset() { rightParent.reset; leftParent.reset; println("ERROR: hashjoin.reset not implemented")/*hm.clear;*/ }
        def open() = {
          leftParent.child = this
          rightParent.child = this
          leftParent.open
          rightParent.open
        }
        def next() {
          leftParent.next
          mode = 1
          rightParent.next

          println("ERROR: hashjoin-anti not yet implemented")
/*
            // Step 3: Return everything that left in the hash table
            keySet = hm.keySet
            while (hm.size != 0) {
                val k = keySet.head
                val elemList = hm(k)
                child.consume(removeFromList(elemList, elemList(0), 0))
            } 
*/
        }
        def consume(tuple0: Rep[Record]) {
            if (mode == 0) {
                val tuple = tuple0.asInstanceOf[Rep[A]]
                val k = leftHash(tuple)
                hm += (k,tuple) // leftStore(tuple) -- might reduce fields
            } else {
                val tuple = tuple0.asInstanceOf[Rep[B]]
                val k = rightHash(tuple)
                for (bufElem <- hm(k)) {
                    if (joinCond(bufElem, tuple)) {
                        // removeFromList
                    }
                }
            }
        }
    }

    // THIS ONE WILL GO AWAY
    case class HashJoinAnti[A<:Record:Manifest,B<:Record:Manifest,C:Manifest](leftParent: Operator[A], rightParent: Operator[B])(joinCond: (Rep[A],Rep[B])=>Rep[Boolean])(leftHash: Rep[A]=>Rep[C])(rightHash: Rep[B]=>Rep[C]) extends Operator[A] {
        var mode: scala.Int = 0
        val hm = HashMap[C, ArrayBuffer[A]]()
        var keySet = hm.keySet

        def removeFromList(elemList: Rep[ArrayBuffer[A]], e: Rep[A], idx: Rep[Int]) = {
            elemList -= idx
            if (elemList.size == 0) {
                val lh = leftHash(e)
                keySet.remove(lh)
                hm.remove(lh)
                ()
            }
            e
        }

        def open() { 
            leftParent.child = this
            leftParent.open 
            rightParent.child = this
            rightParent.open
        }
        def reset() { rightParent.reset; leftParent.reset; hm.clear; }
        def next() {
            leftParent.next
            mode = 1
            rightParent.next
            // Step 3: Return everything that left in the hash table
            keySet = hm.keySet
            while (hm.size != 0) {
                val k = keySet.head
                val elemList = hm(k)
                child.consume(removeFromList(elemList, elemList(0), 0))
            } 
        }
        def consume(tuple: Rep[Record]) {
            // Step 1: Prepare a hash table for the FROM side of the join
            if (mode == 0) {
                val t = tuple.asInstanceOf[Rep[A]]
                val k = leftHash(t)
                val v = hm.getOrElseUpdate(k, ArrayBuffer[A]())
                v.append(t)
            } else {
                val t = tuple.asInstanceOf[Rep[B]]
                val k = rightHash(t)
                if (hm.contains(k)) {
                    val elems = hm(k)
                    // Sligtly complex logic here: we want to remove while
                    // iterating. This is the simplest way to do it, while
                    // making it easy to generate C code as well (otherwise we
                    // could use filter in scala and assign the result to the hm)
                    var removed = 0
                    for (i <- 0 until elems.size: Rep[Range]) {
                        var idx = i - removed
                        val e = elems(idx)
                        if (joinCond(e, t)) { 
                            removeFromList(elems, e, idx);
                            removed += 1
                        }
                    }
                } 
            }
        }
    }

    type CompositeRecord1[A,B] = Record { val left: A; val right: B }

    def HashJoinOp1[A<:Record:Manifest,B:Manifest,C:Manifest,D:Manifest](leftParent: Operator[A], rightParent: Operator[B], leftAlias: String = "", rightAlias: String = "")(joinCond: (Rep[A],Rep[B]) => Rep[Boolean])(leftHash: Rep[A]=>Rep[C])(rightHash: Rep[B]=>Rep[C])(leftStore: Rep[A]=>Rep[D]) =
        HashJoinOp2[A,B,C](leftParent,rightParent,leftAlias,rightAlias)(joinCond)(leftHash)(rightHash)

    case class HashJoinOp2[A<:Record:Manifest,B:Manifest,C:Manifest](val leftParent: Operator[A], val rightParent: Operator[B], leftAlias: String = "", rightAlias: String = "")(val joinCond: (Rep[A],Rep[B]) => Rep[Boolean])(val leftHash: Rep[A]=>Rep[C])(val rightHash: Rep[B]=>Rep[C]) extends Operator[CompositeRecord1[A,B]]{
        override def desc = s"(${leftParent.desc} X ${rightParent.desc})"
        var mode: scala.Int = 0

        val hashSize = (1 << 20)
        val bucketSize = (1 << 10)

        val hm = new LegoLinkedHashMap[C,A](hashSize, bucketSize)

        def reset() { rightParent.reset; leftParent.reset; println("ERROR: hashjoin.reset not implemented")/*hm.clear;*/ }
        def open() = {
          leftParent.child = this
          rightParent.child = this
          leftParent.open
          rightParent.open
        }
        def next() {
          printf(s"$desc: leftParent.next start\n");
          timeGeneratedCode {
            leftParent.next
            printf(s"$desc: leftParent.next done\n");
          }

          mode = 1
  
          printf(s"$desc: rightParent.next start\n");
          timeGeneratedCode {
            rightParent.next
            printf(s"$desc: rightParent.next done\n");
          }
        }
        def consume(tuple0: Rep[Record]) {
            if (mode == 0) {
                val tuple = tuple0.asInstanceOf[Rep[A]]
                val k = leftHash(tuple)
                hm += (k,tuple) // leftStore(tuple) -- might reduce fields
            } else {
                val tuple = tuple0.asInstanceOf[Rep[B]]
                val k = rightHash(tuple)
                for (bufElem <- hm(k)) {
                    if (joinCond(bufElem, tuple)) {
                        val res = new CompositeRecord1[A,B] { 
                            val left = bufElem
                            val right = tuple
                        }
                        child.consume(res)
                    }
                }
            }
        }
    }
    
    case class LeftOuterJoinOp1[A<:Record:Manifest,B<:Record:Manifest,C:Manifest](leftParent: Operator[A], rightParent: Operator[B])(joinCond: (Rep[A],Rep[B])=>Rep[Boolean])(leftHash: Rep[A]=>Rep[C])(rightHash: Rep[B]=>Rep[C]) extends Operator[CompositeRecord1[A,B]] {
        override def desc = s"(${leftParent.desc} LO-X ${rightParent.desc})"
        var mode: scala.Int = 0

        val hashSize = (1 << 20)
        val bucketSize = (1 << 10)

        val hm = new LegoLinkedHashMap[C,B](hashSize, bucketSize)
        val defaultB = DefaultRecord[B]() // TODO: optimize

        def reset() { rightParent.reset; leftParent.reset; println("ERROR: lefthashsemijoin.reset not implemented")/*hm.clear;*/ }
        def open() = {
          leftParent.child = this
          rightParent.child = this
          leftParent.open
          rightParent.open
        }
        def next() {
            rightParent.next
            mode = 1
            leftParent.next
        }
        def consume(tuple0: Rep[Record]) {
            if (mode == 0) {
                val tuple = tuple0.asInstanceOf[Rep[B]]
                val k = rightHash(tuple)
                hm += (k,tuple) // rightStore(tuple) -- might reduce fields
            } else {
                val tuple = tuple0.asInstanceOf[Rep[A]]
                val k = leftHash(tuple)
                var hit = false
                for (bufElem <- hm(k)) {
                    if (joinCond(tuple, bufElem)) {
                        hit = true
                        val res = new CompositeRecord1[A,B] { 
                            val left = tuple
                            val right = bufElem
                        }
                        child.consume(res)
                    }
                }

                if (!hit) {
                    val res = new CompositeRecord1[A,B] { 
                        val left = tuple
                        val right = defaultB
                    }
                    child.consume(res)
                }
            }
        }
    }

    
    case class LeftHashSemiJoinOp1[A<:Record:Manifest,B<:Record:Manifest,C:Manifest](leftParent: Operator[A], rightParent: Operator[B])(joinCond: (Rep[A],Rep[B])=>Rep[Boolean])(leftHash: Rep[A]=>Rep[C])(rightHash: Rep[B]=>Rep[C]) extends Operator[A] {
        override def desc = s"(${leftParent.desc} LHS-X ${rightParent.desc})"
        var mode: scala.Int = 0

        val hashSize = (1 << 20)
        val bucketSize = (1 << 10)

        val hm = new LegoLinkedHashMap[C,B](hashSize, bucketSize)

        def reset() { rightParent.reset; leftParent.reset; println("ERROR: lefthashsemijoin.reset not implemented")/*hm.clear;*/ }
        def open() = {
          leftParent.child = this
          rightParent.child = this
          leftParent.open
          rightParent.open
        }
        def next() {
            rightParent.next
            mode = 1
            leftParent.next
        }
        def consume(tuple0: Rep[Record]) {
            if (mode == 0) {
                val tuple = tuple0.asInstanceOf[Rep[B]]
                val k = rightHash(tuple)
                hm += (k,tuple) // rightStore(tuple) -- might reduce fields
            } else {
                val tuple = tuple0.asInstanceOf[Rep[A]]
                val k = leftHash(tuple)
                val idx = hm(k).indexWhere(e => joinCond(tuple, e))
                if (idx != -1)
                    child.consume(tuple)
            }
        }
    }
    
    case class NestedLoopsJoinOp[A<:Record:Manifest, B<:Record:Manifest](leftParent: Operator[A], rightParent: Operator[B], leftAlias: String = "", rightAlias: String = "")(joinCond: (Rep[A],Rep[B])=>Rep[Boolean]) extends Operator[CompositeRecord1[A,B]] {
        var mode: scala.Int = 0
        var leftTuple = var_new[A](unit(null).asInstanceOf[Rep[A]])

        def open() {
            rightParent.child = this
            leftParent.child = this
            rightParent.open
            leftParent.open 
        }
        def reset() = { rightParent.reset; leftParent.reset; leftTuple = unit(null).asInstanceOf[Rep[A]] }
        def next() { leftParent.next }
        def consume(tuple0: Rep[Record]) {
            if (mode == 0) {
                leftTuple = tuple0.asInstanceOf[Rep[A]]
                mode = 1
                rightParent.next
                mode = 0
                rightParent.reset
            } else {
                val tuple = tuple0.asInstanceOf[Rep[B]]
                if (joinCond(leftTuple,tuple)) {
                    val res = new CompositeRecord1[A,B] {
                        val left = leftTuple:Rep[A] // force read
                        val right = tuple
                    }
                    child.consume(res)
                }
            }
        }
    }
}    

