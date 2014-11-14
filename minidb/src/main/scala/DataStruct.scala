package miniDB


import scala.virtualization.lms.common._
import scala.virtualization.lms.common
import scala.virtualization.lms.internal._
import scala.virtualization.lms.util._
import java.io.{PrintWriter,StringWriter,FileOutputStream}
import scala.collection.mutable.HashMap
import scala.collection.mutable.ListBuffer

import scala.reflect.{SourceContext, RefinedManifest}

trait UncheckedHelperExp extends DSL with UncheckedOpsExp {

  override def mirror[A:Manifest](e: Def[A], f: Transformer)(implicit pos: SourceContext): Exp[A] = (e match {
    case Reflect(Unchecked(s), u, es) => 
      def xform(x: Any): Any = x match {
        case e: Exp[Any] => f(e)
        case _ => x
      }
      reflectMirrored(Reflect(Unchecked(s.map(xform)), mapOver(f,u), f(es)))(mtype(manifest[A]))
    case _ => super.mirror(e,f)
  }).asInstanceOf[Exp[A]]

}

trait UncheckedHelper extends DSL with UncheckedOps {

    implicit def rq(c: StringContext) = new {
      def cg(args: Thunk[Rep[Any]]*) = new {
        def as[T:Manifest]: Rep[T] = {
          //reflect(c.s(args map (a => reify(a.eval())):_*))
          def merge(a: List[Any], b: List[Any]): List[Any] = a match {
            case Nil => Nil
            case x::xs => x::merge(b,xs)
          }
          unchecked[T](merge(c.parts.toList, args.toList.map(_.eval())):_*)
        }
      }
    }

    def array_realloc[T:Manifest](xs: Rep[Array[T]], size: Rep[Int]): Rep[Array[T]] = {
      // TODO: proper IR node
      if (manifest[T] == manifest[Int])
        cg"(int*)realloc($xs,$size * sizeof(int))".as[Array[T]]
      else if (manifest[T] == manifest[Long])
        cg"(long*)realloc($xs,$size * sizeof(long))".as[Array[T]]
      else if (manifest[T] == manifest[Double])
        cg"(double*)realloc($xs,$size * sizeof(double))".as[Array[T]]
      else if (manifest[T] == manifest[Character])
        cg"(char*)realloc($xs,$size * sizeof(char))".as[Array[T]]
      else if (manifest[T] == manifest[String])
        cg"(char**)realloc($xs,$size * sizeof(char*))".as[Array[T]]
      else if (manifest[T] == manifest[Array[Byte]])
        cg"(char**)realloc($xs,$size * sizeof(char*))".as[Array[T]]
      else if (manifest[T] == manifest[Array[Int]])
        cg"(int**)realloc($xs,$size * sizeof(int*))".as[Array[T]]
      else {
        printf(s"ERROR: realloc for type ${manifest[Array[T]]} not implemented\n")
        xs
      }
    }

    def strncpy[T:Manifest](xs: Rep[Array[Byte]], data: Rep[Long], size: Rep[Int]): Unit = 
      cg"""strncpy($xs->array,(char*)${data},$size)""".as[Unit]

}


trait DataStructExp extends DSLExp {
}


trait DataStruct extends DSL with UncheckedHelper {

  /* low level memory buffers: read / write access */

  abstract class LegoBuffer[T] {
    def apply(x: Rep[Int]): Rep[T]
    def update(x: Rep[Int], y: Rep[T]): Rep[Unit]
    def resize(x: Rep[Int]): Rep[Unit]
  }

  class RecordBuffer[T](size: Rep[Int])(implicit rm: RefinedManifest[T]) extends LegoBuffer[T] {
    val elems = rm.fields map { case (k,m) => (k,m,LegoBuffer(size)(m)) }
    def apply(x: Rep[Int]) = 
      record_new[T](structName(manifest[T]), elems map { case (k,m,v) => (k,v(x)) })
    def update(x: Rep[Int], y: Rep[T]): Rep[Unit] = 
      elems foreach { case (k,m,v:LegoBuffer[t]) => v(x) = record_select(y,k)(manifest[T],m.asInstanceOf[Manifest[t]]) }
    def resize(x: Rep[Int]): Rep[Unit] = {
      printf("buffer.resize %d\n",x)
      elems foreach { case (k,m,v) => v.resize(x) }
    }
  }

  class ColumnBuffer[T:Manifest](size: Rep[Int]) extends LegoBuffer[T] {
    val buf = var_new(NewArray[T](size))
    def apply(x: Rep[Int]) = buf(x)
    def update(x: Rep[Int], y: Rep[T]): Rep[Unit] = buf(x) = y
    def resize(x: Rep[Int]): Rep[Unit] = {
     buf = array_realloc(buf,x)
    }
  }

  def recordFieldTypes[T<:Record:Manifest]: List[(String,Manifest[_])] = manifest[T] match {
    case m: RefinedManifest[T] => m.fields
    case m if m.toString.contains("CompositeRecord") =>
      val (mA:Manifest[Record])::(mB:Manifest[Record])::Nil = m.typeArguments
      recordFieldTypes(mA) ++ recordFieldTypes(mB)
    // catch _ => MatchError!
  }

  def refinedManifest[T<:Record:Manifest]: RefinedManifest[T] = manifest[T] match {
    case m: RefinedManifest[T] => m
    case m0 => 
      new RefinedManifest[T] {
          val runtimeClass = classOf[Record]
          val fields = recordFieldTypes(m0)
      }
  }

  def LegoBuffer[T:Manifest](size: Rep[Int]): LegoBuffer[T] = if (manifest[T] <:< manifest[Record]) {
    val rm = refinedManifest[Record](manifest[T].asInstanceOf[Manifest[Record]]).asInstanceOf[RefinedManifest[T]]
    new RecordBuffer(size)(rm)
  } else {
    new ColumnBuffer(size)
  }


  /* read access */

  abstract class LegoArray[T] {
    def length: Rep[Int]
    def apply(x: Rep[Int]): Rep[T]
  }


  /* a table is a named array */
  case class LegoTable[A](val name: String, val data: LegoArray[A])


  /* array builder */

  abstract class LegoCollect[T] {
    def append(x: Rep[T]): Unit
    def result: LegoArray[T]
  }

  def LegoCollect[T:Manifest]() = new LegoCollect[T] {
    val cap = var_new(/*4096*/ 1 << 20)
    val len = var_new(0)
    val buf = LegoBuffer[T](/*4096*/ 1 << 20)

    def ensureSize() = {
      if (len == cap) {
        cap = cap * 4
        buf.resize(cap)
      }
    }

    def append(x: Rep[T]) = {
      ensureSize()
      buf(len) = x
      len += 1
    }

    def result = new LegoArray[T] {
      val data = buf // TODO: unsafeImmutable
      def length = len
      def apply(x: Rep[Int]) = data(x)
    }

  }


  /* bucket collect: think of it as ArrayBuffer[ArrayBuffer[T]] */

  abstract class LegoBucketCollect[T] {
    def size: Rep[Int]
    def appendBucket(): Unit
    def bucket(i: Rep[Int]): LegoCollect[T]
  }


  def LegoBucketCollect[T:Manifest](): LegoBucketCollect[T] = ??? 

  /* hash code and equality */

  def recordHashCode[T](x: Rep[T])(implicit rm: RefinedManifest[T]): Rep[Int] = {
    val elems = rm.fields.sortBy(_._1) map { case (k,m:Manifest[t]) => calcHashCode(record_select[T,t](x,k)(rm,m))(m) }
    (unit(0) /: elems) (_ * 41 + _)
  }

  def calcHashCode[T:Manifest](x: Rep[T]): Rep[Int] = if (manifest[T] <:< manifest[Record]) {
    recordHashCode(x)(manifest[T].asInstanceOf[RefinedManifest[T]])
  } else if (manifest[T] == manifest[Character]) {
    x.asInstanceOf[Rep[Int]]
  } else if (manifest[T] == manifest[Int]) {
    x.asInstanceOf[Rep[Int]]
  } else if (manifest[T] == manifest[Long]) {
    x.asInstanceOf[Rep[Long]].toInt
  } else if (manifest[T] == manifest[String]) {
    x.asInstanceOf[Rep[String]].charAt(0).asInstanceOf[Rep[Int]] // TODO: proper string hash ...
  } else {
    unit(777) // not the best default, but hey ... 
  }


  def recordEquals[T](x: Rep[T], y: Rep[T])(implicit rm: RefinedManifest[T]): Rep[Boolean] = {
    val elems = rm.fields map { case (k,m:Manifest[t]) => isEqual(record_select[T,t](x,k)(rm,m),record_select[T,t](y,k)(rm,m))(m) }
    (unit(true) /: elems) (_ && _)
  }

  def isEqual[T:Manifest](x: Rep[T], y: Rep[T]): Rep[Boolean] = if (manifest[T] <:< manifest[Record]) {
    recordEquals(x,y)(manifest[T].asInstanceOf[RefinedManifest[T]])
  } else {
    __equal[T,T](x,y)
  }


  /* hash builder */

  abstract class LegoHash[K] {
    def get(k: Rep[K]): Rep[Int]
    def put(k: Rep[K])(onInsert: => Rep[Unit]): Rep[Int]
    def size: Rep[Int]
  }

  def LegoHash[K:Manifest](cap0: Rep[Int])(keys: Rep[Int] => Rep[K]) = new LegoHash[K] {
    val cap = var_new(cap0)
    val sz  = var_new(0)
    val hashtab = LegoBuffer[Int](cap0) // initial size must be a power of two
    //val relbits = var_new(8)

    for (i <- 0 until cap0)
      hashtab(i) = -1

    val steps  = var_new(0)
    val lkups  = var_new(0)

    val space = 3 // space out hash values to make room for conflicts

    def size: Rep[Int] = sz

    def get(k: Rep[K]) = {
      lkups += 1
      val mask = cap - 1
      //val hc = calcHashCode(k) * 0x9e3775cd
      //var pos = (hc >>> (32 - relbits)) * 2
      val hc = calcHashCode(k) * 2 * space
      var pos = (hc & mask)
      var currelem = hashtab(pos)
      var currhash = hashtab(pos + 1)
      
      while (currelem != -1 && (currhash != hc || !isEqual(keys(currelem), k))) {
        pos = (pos + 2) & mask
        currelem = hashtab(pos)
        currhash = hashtab(pos + 1)
        steps += 1
      }
      
      currelem: Rep[Int]
    }

    def put(k: Rep[K])(onInsert: => Rep[Unit]) = {
      lkups += 1
      val mask = cap - 1
      //val hc = calcHashCode(k) * 0x9e3775cd
      //var pos = (hc >>> (32 - relbits)) * 2
      val hc = calcHashCode(k) * 2 * space
      var pos = (hc & mask)
      var currelem = hashtab(pos)
      var currhash = hashtab(pos + 1)
      
      while (currelem != -1 && (currhash != hc || !isEqual(keys(currelem), k))) {
        pos = (pos + 2) & mask
        currelem = hashtab(pos)
        currhash = hashtab(pos + 1)
        steps += 1
      }
      
      if (currelem == -1) {
        val datapos: Rep[Int] = sz // read var!
        hashtab(pos) = datapos
        hashtab(pos + 1) = hc
        sz += 1
        
        onInsert

        ensureSize()
        datapos
      } else {
        currelem: Rep[Int]
      }

    }

    def ensureSize() = {
      if (sz * 4 > cap) // grow
        println("ERROR: hash.resize not implemented") // TODO
    }    

  }


  class LegoLinkedHashMap[C:Manifest,A:Manifest](val hashSize: Int, val bucketSize: Int) {
      val dataSize = hashSize * bucketSize

      val data = LegoBuffer[A](dataSize)
      val dataCount = var_new(0)

      val bucketHash = NewArray[Int](hashSize)
      val bucketNext = NewArray[Int](dataSize)

      for (i <- 0 until hashSize) {
          bucketHash(i) = -1
      }

      val hashMask = hashSize - 1


      def += (k: Rep[C], tuple: Rep[A]) = {
          val dataPos = dataCount: Rep[Int] // force read
          data(dataPos) = tuple
          dataCount += 1

          val h = calcHashCode(k)
          val bucket = h & hashMask

          val next = bucketHash(bucket)
          bucketHash(bucket) = dataPos
          bucketNext(dataPos) = next
      }

      def apply(k: Rep[C]) = new {
          def foreach(f: Rep[A] => Rep[Unit]): Rep[Unit] = {
              val h = calcHashCode(k)
              val bucket = h & hashMask
              
              var dataPos = bucketHash(bucket)
              while (dataPos != -1) {
                  val bufElem = data(dataPos)
                  dataPos = bucketNext(dataPos)
                  // NOTE: we only know that hash codes match:
                  // client needs to check full keys.
                  f(bufElem)
              }
          }
          def indexWhere(f: Rep[A] => Rep[Boolean]): Rep[Int] = {
              val h = calcHashCode(k)
              val bucket = h & hashMask
              
              var dataPos = bucketHash(bucket)
              var done = dataPos == -1
              while (!done) {
                  val bufElem = data(dataPos)
                  // NOTE: we only know that hash codes match:
                  // client needs to check full keys.
                  if (f(bufElem)) {
                    done = true
                  } else {
                    dataPos = bucketNext(dataPos)
                    done = dataPos == -1
                  }
              }
              dataPos
          }
      }

  }


}