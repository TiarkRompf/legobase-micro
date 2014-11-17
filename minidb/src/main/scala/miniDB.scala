package miniDB


import scala.virtualization.lms.common._
import scala.virtualization.lms.common
import scala.virtualization.lms.internal._
import scala.virtualization.lms.util._
import java.io.{PrintWriter,StringWriter,FileOutputStream}
import scala.collection.mutable.HashMap
import scala.collection.mutable.ListBuffer
import scala.collection.mutable.ArrayBuffer

object utilities {
  def time[A](a: => A, msg: String) = {
    val start = System.nanoTime
    val result = a
    val end = (System.nanoTime - start) / (1000 * 1000)
    System.out.println("Operation " + msg + " completed in %d milliseconds".format(end))
    result
  }
}

trait DSL extends ScalaOpsPkg with Functions with UncheckedOps with LiftBoolean with LiftPrimitives 
            with LiftString with LiftVariables with Scanner with Structs with RangeOps
            with HashMapOps with TupleOps with Loops with DateOps with While 
            with IfThenElse with TreeSet with VariableImplicits with IOOps with 
            BooleanOps with ArrayBufferOps with Timing with HashCodeOps with OrderingOps 
            with TPCHRelations {
  var datapath: java.lang.String
  def parseDate(x: String): Long
  def parseString(x: Rep[String]): Rep[LegoString]

  object SizeDefaults {
      def defaultInputBufferSize: Rep[Long] = uncheckedPure[Long]("DEFAULT_INPUT_SIZE")
      def defaultViewSize:        Rep[Long] = uncheckedPure[Long]("DEFAULT_VIEW_SIZE")
      def defaultAggHashSize:     Rep[Long] = uncheckedPure[Long]("DEFAULT_AGG_HASH_SIZE ")
      def defaultJoinHashSize:    Rep[Long] = uncheckedPure[Long]("DEFAULT_JOIN_HASH_SIZE")
  }  
}

trait DSLExp extends DSL with FunctionsExp with UncheckedOpsExp with ScannerExp 
        with StructExp with RangeOpsExp with TupleOpsExp with DateExp 
        with HashCodeOpsExp with ListBufferExp with TreeSetExp with IOOpsExp 
        with StringOpsExp with ArrayBufferOpsExp with TimingExp with HashMapOpsExp {
}

trait Engine extends PushEngine { self => }

trait ScalaImpl extends ScalaOpsPkgExp with FunctionsExp with UncheckedOpsExp with ScannerExp 
        with StructExp with RangeOpsExp with ListOpsExp with TupleOpsExp with DateExp 
        with HashCodeOpsExp with ScalaCompile with ListBufferExp with TreeSetExp with IOOpsExp 
        with StringOpsExp with ArrayBufferOpsExp with TimingExp with HashMapOpsExp with Loader { self => 
  val codegen = new ScalaCodeGenPkg with ScalaGenVariables with ScalaGenFunctions with ScalaGenUncheckedOps 
          with ScalaGenScanner with ScalaGenRangeOps with ScalaGenListOps 
          with ScalaGenHashCodeOps with ScalaGenTupleOps with ScalaGenHashMapOps
          with ScalaGenListBuffer with ScalaGenTreeSet with ScalaGenIOOps with ScalaGenDate 
          with ScalaGenArrayBufferOps with ScalaGenTiming with ScalaGenStruct {
    override val IR: self.type = self 
    override def emitFunctions() = {
      //if (checkResults)
        stream.println("Console.setOut(new java.io.PrintStream(\"" + getOutputName + "\"))")
      super.emitFunctions()
    }
  }
  override def initCompile = {
    super.initCompile
    getClassName
  }
  override def compile2[A1,A2,B](f: (Exp[A1],Exp[A2]) => Exp[B])(implicit mA1: Manifest[A1], mA2: Manifest[A2], mB: Manifest[B]): (A1,A2) =>B = {
    val x = super.compile2(f)
    val w = new PrintWriter(getSourceName)
    w.println(ScalaCompile.source)
    w.close
    x
  }
  def getClassName: String
  def getSourceName: String
  def getOutputName: String
  val sdf = new java.text.SimpleDateFormat("yyyy-MM-dd")  
  def parseDate(x: String): Long = { 
        sdf.parse(x).getTime
    //val d = x.split("-").map(x=> java.lang.Integer.parseInt(x))
    //d(0) * 10000 + d(1) * 100 + d(2)
    }
  //def parseString(x: Rep[String]): Rep[Array[Byte]] = x.getBytes
  def parseString(x: Rep[String]): Rep[LegoString] = x
}

trait ExtraDCE extends GenericNestedCodegen {
  val IR: VariablesExp
  import IR._

  val unused = new scala.collection.mutable.HashSet[Sym[_]]
  override def emitNode(sym: Sym[Any], rhs: Def[Any]) = {
    if (unused(sym)) {
      //stream.println(s"//${quote(sym)} = $rhs")
    } else
      super.emitNode(sym,rhs)
  }
  override def runTransformations[A:Manifest](body: Block[A]): Block[A] = {
    extraDCE(body/*super.runTransformations(body)*/)
  }
  def extraDCE[A](res: Block[A]): Block[A] = {
    import scala.collection.mutable
    val start = getSchedule(globalDefs)(res)

    val used = new mutable.HashSet[Sym[_]]
    val alloc = new mutable.HashSet[Sym[_]]
    val all = new mutable.HashSet[Sym[_]]

    getBlockResult(res) match {
      case s: Sym[_] => used += s
      case _ =>
    }

    while ({
      var size0 = used.size
      for (TP(sym,rhs) <- start) {
        all += sym
        rhs match {
          case Reflect(NewVar(s:Sym[_]),u,es) => 
            if (alloc(s)) alloc += sym
          case Reflect(ReadVar(Variable(s:Sym[_])),u,es) => 
            if (alloc(s)) alloc += sym
          case Reflect(Assign(Variable(v:Sym[_]),s:Sym[_]),u,es) => 
            if (alloc(s)) alloc += v
          case _ =>
        }
        rhs match {
          case Reflect(d,u,es) => 
            val realloc = d.toString.contains("realloc") // realloc should be reflectWrite, not reflectSimple
            if (maySimple(u) && !realloc) used += sym
            for (s <- u.mayWrite) {
              if (alloc(s)) used += sym
            }
            if (mustMutable(u)) if (used(sym)) alloc += sym
            if (used(sym)) used ++= syms(d)
          case Reify(s: Sym[_],_,_) if s.tp != manifest[Unit] => 
            if (used(sym)) used += s
          case Reify(_,_,_) =>
          case _ => 
            if (used(sym)) used ++= syms(rhs)
        }
      }

      used.size != size0
    }) {}

    unused.clear
    unused ++= (all diff used)
    res
  }
}

trait CImpl extends COpsPkgExp with UncheckedHelperExp with FunctionsExp with ScannerExp with StructExp 
    with RangeOpsExp with ListOpsExp with TupleOpsExp with ListBufferExp 
    with TreeSetExp with TimingExp with HashMapOpsExp with HashCodeOpsExp 
    with NumericOpsExpOpt
    with IfThenElseExpOpt with VariablesExpOpt with StructFatExpOptCommon { self => 
    val codegen = new CCodeGenPkg with CGenVariables with CGenFunctions with CGenUncheckedOps with CGenScanner
   with CGenRangeOps with CGenListOps with CGenTupleOps with CGenObjectOps  
   with CLikeGenIOOps with CGenTreeSet with CGenDate with CGenTiming with CGenHashMapOps with CGenHashCodeOps with ExtraDCE { 
    override val IR: self.type = self 
    override def emitDataStructures(out: PrintWriter) {
      out.println("""
      #include <sys/mman.h>
      #include <sys/stat.h>
      #ifndef MAP_FILE
      #define MAP_FILE MAP_SHARED
      #endif

      // buffer and hashtable sizes
      #define DEFAULT_INPUT_SIZE      (1L << 20)
      #define DEFAULT_VIEW_SIZE       (1L << 20)
      #define DEFAULT_AGG_HASH_SIZE   (1L << 24)
      #define DEFAULT_JOIN_HASH_SIZE  (1L << 26)


      long fsize(int fd) {
        struct stat stat;
        int res = fstat(fd,&stat);
        return stat.st_size;
      }
      int printll(char* s) {
        while (*s != '\n' && *s != ',' && *s != '\t') {
          putchar(*s++);
        }
        return 0;
      }
      long hash(char *str0, int len)
      {
        unsigned char* str = (unsigned char*)str0;
        unsigned long hash = 5381;
        int c;

        while ((c = *str++) && len--)
          hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
      }
      size_t strlen(const char* str) {
        const char* start = str;
        while (*str != '\n' && (*str != '|') && (*str != '\0')) str++;
        return str - start;
      }
      int strcmp(const char *s1, const char *s2) {
        size_t l1 = strlen(s1);
        size_t l2 = strlen(s2);
        if (l1 != l2) return l2 - l1;
        return strncmp(s1,s2,l1);
      }
      char* strstr(const char *s1, const char *s2) {
        return strnstr(s1,s2,strlen(s1));
      }
      """)
      super.emitDataStructures(out)
    }
    override def remap[A](m: Manifest[A]): String = m.toString match {
      case "java.lang.String" => "char*"
      case "Array[Char]" => "char*"
      case "Char" => "char"
      case _ => super.remap(m)
    }
    override def quote(x: Exp[Any]) = x match {
      case Const(s: String) => "\""+s.replace("\"", "\\\"").replace("\n", "\\n")+"\"" // TODO: more escapes?
      case Const('\n') if x.tp == manifest[Char] => "'\\n'"
      case Const('\t') if x.tp == manifest[Char] => "'\\t'"
      case Const('\0') if x.tp == manifest[Char] => "'\\0'"
      case _ => super.quote(x)
    }
  }
  def getSourceName: String
  def compile2[A1,A2,B](f: (Exp[A1],Exp[A2]) => Exp[B])(implicit mA1: Manifest[A1], mA2: Manifest[A2], mB: Manifest[B]): (A1,A2) =>B = {
    def dummy(x:A1,y:A2): B = null.asInstanceOf[B]
      val staticData = codegen.emitSource2(f, "main", new PrintWriter(getSourceName))
      codegen.emitDataStructures(ScalaCompile.writer)
    dummy
  }
  def parseDate(x: java.lang.String): Long = {
    val d = x.split("-").map(x=> java.lang.Integer.parseInt(x))
    d(0) * 10000 + d(1) * 100 + d(2)
  }
  def parseString(x: Rep[String]): Rep[LegoString] = x.asInstanceOf[Rep[LegoString]]
}

/*
"cqueries/" + self.currQuery + ".c")
*/

class miniDBScala extends ScalaImpl with CSVLoader {
  var datapath: java.lang.String = null
  var currQuery: java.lang.String = ""
  // TODO: This only works for scaling factor 0.1. Make it independent (file existence check needed)
  val checkResults = true
  def getClassName = currQuery + "Runner"
  def getSourceName = "squeries/" + currQuery + ".scala"
  def getOutputName = "output/" + currQuery + ".result"
  // TODO: Make this dependant on the scaling factor given
  def getResultFileName = "ref/" + currQuery + ".result"
}

class miniDBC extends CImpl with CSVLoader {
  var datapath: java.lang.String = null
  var currQuery: java.lang.String = ""
  val checkResults = false
  def getSourceName = "cqueries/" + currQuery + ".c"
  def getOutputName = "output/" + currQuery + ".result"
  // TODO: Make this dependant on the scaling factor given
  def getResultFileName = "ref/" + currQuery + ".result"
}

//object miniDBScala extends miniDBScala with Queries {
object miniDBC extends miniDBC with Queries {
  import utilities._
  val numRuns: scala.Int = 5
  
  def cmain(argc: Rep[Int], args: Rep[Array[String]]) = {
    val q = currQuery match {
      case "Q1"  => Q1(numRuns)
      case "Q2"  => Q2(numRuns)
      case "Q3"  => Q3(numRuns)
      case "Q4"  => Q4(numRuns)
      case "Q5"  => Q5(numRuns)
      case "Q6"  => Q6(numRuns)
      case "Q7"  => Q7(numRuns)
      case "Q8"  => Q8(numRuns)
      case "Q9"  => Q9(numRuns)
      case "Q10" => Q10(numRuns)
      case "Q11" => Q11(numRuns)
      case "Q12" => Q12(numRuns)
      case "Q13" => Q13(numRuns)
      case "Q14" => Q14(numRuns)
      case "Q15" => Q15(numRuns)
      case "Q16" => Q16(numRuns)
      case "Q17" => Q17(numRuns)
      case "Q18" => Q18(numRuns)
      case "Q19" => Q19(numRuns)
      case "Q20" => Q20(numRuns)
      case "Q21" => Q21(numRuns)
      case "Q22" => Q22(numRuns)
    }
    0
  }

  // TODO: should this be in LMS?
  override def isPrimitiveType[T](m: Manifest[T]) = (m == manifest[String]) || 
    (m == manifest[Character]) || (m.toString.contains("CompositeRecord")) || 
    super.isPrimitiveType(m)


  def main(args: Array[String]) {
    System.out.println("MINIDB")
    if (args.length < 2) {
        System.out.println("usage: datapath [all|Qn]")
        return
    }

    datapath = args(0)
    ScalaCompile.dumpGeneratedCode = false 

    val queries: scala.collection.immutable.List[String] = 
      if (args.length == 2 && args(1) == "all") (for (i <- 1 to 22) yield "Q" + i).toList
      else (args.drop(1).toList)
    for (q <- queries) {
      currQuery = q
      // Compile and run query
      try {
        val prog = time({ compile2(cmain) }, "Compiling " + currQuery)
        //globalDefs.foreach(System.out.println _)
        prog(args.length, args)
      } catch { case ex: Exception =>
        ex.printStackTrace
      }
      // Check results
      if (checkResults) {
        if (new java.io.File(getResultFileName).exists) {
          val resq = scala.io.Source.fromFile(getOutputName).mkString
          val resc = {
            val str = scala.io.Source.fromFile(getResultFileName).mkString
            str * numRuns 
          }
          if (resq != resc) {
            System.out.println("-----------------------------------------")
            System.out.println("QUERY" + q + " DID NOT RETURN CORRECT RESULT!!!")
            System.out.println("Correct result:")
            System.out.println(resc)
            System.out.println("Result obtained from execution:")
            System.out.println(resq)
            System.out.println("-----------------------------------------")
          } else System.out.println("CHECK RESULT FOR QUERY " + q + ": [OK]")
        } else System.out.println("Reference result file not found. Skipping checking of result")
      }
      // Cleanup
      for {
        files <- Option(new java.io.File("CompiledClasses").listFiles)
        file <- files if file.getName.endsWith(".class")
      } file.delete()
      /*for {
        files <- Option(new java.io.File("./").listFiles)
        file <- files if file.getName.endsWith("Output.txt")
      } file.delete()*/
    }
  }
}
