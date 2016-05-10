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

    class MyPointer[T:Manifest]
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

    def array_realloc[T:Manifest](xs: Rep[Array[T]], size: Rep[Long]): Rep[Array[T]] = {
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

    def deref[T:Manifest](ptr: Rep[MyPointer[T]]): Rep[T] = {
      cg"(*$ptr)".as[T]
    }

    def array_quicksort[T:Manifest](xs: Rep[Array[T]], size: Rep[Long], comp: Function2[Rep[T],Rep[T],Rep[Int]]): Rep[Unit] = {
      // TODO: proper IR node
      val f = uninlinedFunc2((a:Rep[MyPointer[T]], b:Rep[MyPointer[T]]) => comp(deref(a), deref(b)))
      if (manifest[T] == manifest[Int])
        cg"qsort($xs,$size,sizeof(int),(__compar_fn_t)$f)".as[Unit]
      else if (manifest[T] == manifest[Long])
        cg"qsort($xs,$size,sizeof(long),(__compar_fn_t)$f)".as[Unit]
      else if (manifest[T] == manifest[Double])
        cg"qsort($xs,$size,sizeof(double),(__compar_fn_t)$f)".as[Unit]
      else if (manifest[T] == manifest[Character])
        cg"qsort($xs,$size,sizeof(char),(__compar_fn_t)$f)".as[Unit]
      else if (manifest[T] == manifest[String])
        cg"qsort($xs,$size,sizeof(char*),(__compar_fn_t)$f)".as[Unit]
      else if (manifest[T] <:< manifest[Record]) {
        val name = structName(manifest[T])
        rq(new StringContext("qsort((void *)", ",", s",sizeof(struct $name), (__compar_fn_t)", ")")).cg(xs, size, f).as[Unit]
      } else {
        cg"qsort((void *)$xs,$size,sizeof(void*),(__compar_fn_t)$f)".as[Unit]
      }
    }

}


trait DataStructExp extends DSLExp {
}


trait DataStruct extends DSL with UncheckedHelper {

  /* low level memory buffers: read / write access */

  abstract class LegoBuffer[T] {
    def apply(x: Rep[Long]): Rep[T]
    def update(x: Rep[Long], y: Rep[T]): Rep[Unit]
    def resize(x: Rep[Long]): Rep[Unit]
    def sort(comp: Function2[Rep[T],Rep[T],Rep[Int]], len: Rep[Long]): Rep[Unit]
  }

  class RecordBuffer[T](size: Rep[Long])(implicit rm: RefinedManifest[T]) extends LegoBuffer[T] {
    val elems = rm.fields map { case (k,m) => (k,m,LegoBuffer(size)(m)) }
    def apply(x: Rep[Long]) =
      record_new[T](structName(manifest[T]), elems map { case (k,m,v) => (k,v(x)) })
    def update(x: Rep[Long], y: Rep[T]): Rep[Unit] =
      elems foreach { case (k,m,v:LegoBuffer[t]) => v(x) = record_select(y,k)(manifest[T],m.asInstanceOf[Manifest[t]]) }
    def resize(x: Rep[Long]): Rep[Unit] = {
      printf("buffer.resize %d\n",x)
      elems foreach { case (k,m,v) => v.resize(x) }
    }
    def sort(comp: Function2[Rep[T],Rep[T],Rep[Int]], len: Rep[Long]): Rep[Unit] = {
      throw new RuntimeException("TODO buffer.sort")
    }
  }

  class ColumnBuffer[T:Manifest](size: Rep[Long]) extends LegoBuffer[T] {
    val buf = var_new(NewArray[T](size))
    def apply(x: Rep[Long]) = buf(x)
    def update(x: Rep[Long], y: Rep[T]): Rep[Unit] = buf(x) = y
    def resize(x: Rep[Long]): Rep[Unit] = {
     buf = array_realloc(buf,x)
    }
    def sort(comp: Function2[Rep[T],Rep[T],Rep[Int]], len: Rep[Long]): Rep[Unit] = {
      array_quicksort(buf, len, comp)
    }
  }

  def recordFieldTypes[T:Manifest]: List[(String,Manifest[_])] = manifest[T] match {
    case m: RefinedManifest[T] => m.fields
    case m if m.toString.contains("CompositeRecord") =>
      val (mA:Manifest[Record])::(mB:Manifest[Record])::Nil = m.typeArguments
      recordFieldTypes(mA) ++ recordFieldTypes(mB)
    // catch _ => MatchError!
  }

  def refinedManifest[T:Manifest]: RefinedManifest[T] = manifest[T] match {
    case m: RefinedManifest[T] => m
    case m0 if m0 <:< manifest[Record] => 
      new RefinedManifest[T] {
          val runtimeClass = classOf[Record]
          val fields = recordFieldTypes(m0)
      }
    // catch _ => MatchError!
  }

  def LegoBuffer[T:Manifest](size: Rep[Long]): LegoBuffer[T] = if (manifest[T] <:< manifest[Record]) {
    val rm = refinedManifest[T]
    new RecordBuffer(size)(rm)
  } else {
    new ColumnBuffer(size)
  }

  def LegoBufferFlat[T:Manifest](size: Rep[Long]) = new ColumnBuffer[T](size)


  /* read access */

  abstract class LegoArray[T] {
    def length: Rep[Long]
    def apply(x: Rep[Long]): Rep[T]
  }


  /* a table is a named array */
  case class LegoTable[A](val name: String, val data: LegoArray[A])


  /* array builder */

  abstract class LegoCollect[T] {
    def append(x: Rep[T]): Unit
    def result: LegoArray[T]
  }

  def LegoCollect[T:Manifest](cap0: Rep[Long]) = new LegoCollect[T] {
    val cap = var_new(cap0)
    val len = var_new(0L)
    val buf = LegoBuffer[T](cap0)

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
      def apply(x: Rep[Long]) = data(x)
    }

  }


  /* bucket collect: think of it as ArrayBuffer[ArrayBuffer[T]] */

  abstract class LegoBucketCollect[T] {
    def size: Rep[Long]
    def appendBucket(): Unit
    def bucket(i: Rep[Long]): LegoCollect[T]
  }


  def LegoBucketCollect[T:Manifest](): LegoBucketCollect[T] = ??? 

  /* hash code and equality */

  def recordHashCode[T](x: Rep[T])(implicit rm: RefinedManifest[T]): Rep[Long] = {
    val elems = rm.fields.sortBy(_._1) map { case (k,m:Manifest[t]) => calcHashCode(record_select[T,t](x,k)(rm,m))(m) }
    (unit(0L) /: elems) (_ * 41L + _)
  }

  def calcHashCode[T:Manifest](x: Rep[T]): Rep[Long] = if (manifest[T] <:< manifest[Record]) {
    recordHashCode(x)(refinedManifest[T])
  } else if (manifest[T] == manifest[Character]) {
    x.asInstanceOf[Rep[Long]]
  } else if (manifest[T] == manifest[Int]) {
    x.asInstanceOf[Rep[Long]]
  } else if (manifest[T] == manifest[Long]) {
    x.asInstanceOf[Rep[Long]]
  } else if (manifest[T] == manifest[String]) {
    // TODO: proper string hash ...
    (((x.asInstanceOf[Rep[String]].charAt(0L).asInstanceOf[Rep[Long]] * 41L + 
    x.asInstanceOf[Rep[String]].charAt(1L).asInstanceOf[Rep[Long]]) * 41L + 
    x.asInstanceOf[Rep[String]].charAt(2L).asInstanceOf[Rep[Long]]) * 41L + 
    x.asInstanceOf[Rep[String]].charAt(3L).asInstanceOf[Rep[Long]])
  } else {
    unit(777L) // not the best default, but hey ... 
  }


  def recordEquals[T](x: Rep[T], y: Rep[T])(implicit rm: RefinedManifest[T]): Rep[Boolean] = {
    val elems = rm.fields map { case (k,m:Manifest[t]) => isEqual(record_select[T,t](x,k)(rm,m),record_select[T,t](y,k)(rm,m))(m) }
    (unit(true) /: elems) (_ && _)
  }

  def isEqual[T:Manifest](x: Rep[T], y: Rep[T]): Rep[Boolean] = if (manifest[T] <:< manifest[Record]) {
    recordEquals(x,y)(refinedManifest[T])
  } else {
    __equal[T,T](x,y)
  }

  def defaultValue[T:Manifest]: Rep[T] = (if (manifest[T] <:< manifest[Record]) {
    val elems = recordFieldTypes[T]
    record_new[T](structName(manifest[T]), elems map { case (k,m) => (k,defaultValue(m)) })    
  } else if (manifest[T] == manifest[Character]) {
    unit('\0')
  } else if (manifest[T] == manifest[Int]) {
    unit(0)
  } else if (manifest[T] == manifest[Long]) {
    unit(0L)
  } else if (manifest[T] == manifest[Double]) {
    unit(0.0)
  } else if (manifest[T] == manifest[String]) {
    unit("")
  } else {
    unit(null.asInstanceOf[T])
  }).asInstanceOf[Rep[T]]


  /* hash builder */

  abstract class LegoHash[K] {
    def get(k: Rep[K]): Rep[Long]
    def put(k: Rep[K])(onInsert: => Rep[Unit]): Rep[Long]
    def size: Rep[Long]
  }

  def LegoHash[K:Manifest](cap0: Rep[Long])(keys: Rep[Long] => Rep[K]) = new LegoHash[K] {
    val cap = var_new(cap0)
    val sz  = var_new(0L)
    val hashtab = LegoBuffer[Long](cap0) // initial size must be a power of two
    //val relbits = var_new(8)

    for (i <- 0L until cap0)
      hashtab(i) = -1L

    val steps  = var_new(0L)
    val lkups  = var_new(0L)

    val space = 3L // space out hash values to make room for conflicts

    def size: Rep[Long] = sz

    def get(k: Rep[K]) = {
      lkups += 1
      val mask = cap - 1L
      //val hc = calcHashCode(k) * 0x9e3775cd
      //var pos = (hc >>> (32 - relbits)) * 2
      val hc = calcHashCode(k) * 2L * space
      var pos = (hc & mask)
      var currelem = hashtab(pos)
      var currhash = hashtab(pos + 1L)
      
      while (currelem != -1L && (currhash != hc || !isEqual(keys(currelem), k))) {
        pos = (pos + 2L) & mask
        currelem = hashtab(pos)
        currhash = hashtab(pos + 1L)
        steps += 1L
      }
      
      currelem: Rep[Long]
    }

    def put(k: Rep[K])(onInsert: => Rep[Unit]) = {
      lkups += 1L
      val mask = cap - 1L
      //val hc = calcHashCode(k) * 0x9e3775cd
      //var pos = (hc >>> (32 - relbits)) * 2
      val hc = calcHashCode(k) * 2L * space
      var pos = (hc & mask)
      var currelem = hashtab(pos)
      var currhash = hashtab(pos + 1L)
      
      while (currelem != -1L && (currhash != hc || !isEqual(keys(currelem), k))) {
        pos = (pos + 2L) & mask
        currelem = hashtab(pos)
        currhash = hashtab(pos + 1L)
        steps += 1L
      }
      
      if (currelem == -1L) {
        val datapos: Rep[Long] = sz // read var!
        hashtab(pos) = datapos
        hashtab(pos + 1L) = hc
        sz += 1L
        
        onInsert

        ensureSize()
        datapos
      } else {
        currelem: Rep[Long]
      }

    }

    def ensureSize() = {
      if (sz * 4L > cap) // grow
        println("ERROR: hash.resize not implemented") // TODO
    }    

  }


  class LegoLinkedHashMap[C:Manifest,A:Manifest](val hashSize: Rep[Long], val bucketSize: Rep[Long]) {
      val dataSize = hashSize * bucketSize

      val data = LegoBuffer[A](dataSize)
      val dataCount = var_new(0L)

      val bucketHash = NewArray[Long](hashSize)
      val bucketNext = NewArray[Long](dataSize)

      for (i <- 0L until hashSize) {
          bucketHash(i) = -1L
      }

      val hashMask = hashSize - 1L


      def += (k: Rep[C], tuple: Rep[A]) = {
          val dataPos = dataCount: Rep[Long] // force read
          data(dataPos) = tuple
          dataCount += 1L

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
          def indexWhere(f: Rep[A] => Rep[Boolean]): Rep[Long] = {
              val h = calcHashCode(k)
              val bucket = h & hashMask
              
              var dataPos = bucketHash(bucket)
              var done = dataPos == -1L
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