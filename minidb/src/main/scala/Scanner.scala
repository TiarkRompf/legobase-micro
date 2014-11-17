package miniDB

import scala.virtualization.lms.internal._
import scala.virtualization.lms.common._
import scala.reflect.SourceContext

trait Scanner extends ScalaOpsPkg with LiftVariables with LiftPrimitives  with LiftNumeric {

    class ScannerOps(x: Rep[java.util.Scanner]) {
        def apply() = scannerApply(x)
        def nextInt() = scannerNextInt(x)   
        def nextDouble() = scannerNextDouble(x) 
        def nextChar() = scannerNextChar(x) 
        def nextString(y: Rep[Any],limit: Rep[Int]) = scannerNextString(x,y,limit)
        def nextDate() = scannerNextDate(x)
        def hasNext() = scannerHasNext(x)
    }
    implicit def scanner2scannerOps(x: Rep[java.util.Scanner]) = new ScannerOps(x)

    def scannerApply(x: Rep[java.util.Scanner]): Rep[java.util.Scanner]
    def newScanner(x: Rep[String]): Rep[java.util.Scanner]
    def scannerNextInt(x: Rep[java.util.Scanner]): Rep[Int]
    def scannerNextDouble(x: Rep[java.util.Scanner]): Rep[Double]
    def scannerNextChar(x: Rep[java.util.Scanner]): Rep[java.lang.Character]
    def scannerNextString(x: Rep[java.util.Scanner], y: Rep[Any], z: Rep[Int]): Rep[String]
    def scannerNextDate(x: Rep[java.util.Scanner]): Rep[Long]
    def scannerHasNext(x: Rep[java.util.Scanner]): Rep[Boolean]


    def open(name: Rep[String]): Rep[Int]
    def fclose(fd: Rep[Int]): Rep[Unit]
    def filelen(fd: Rep[Int]): Rep[Int]
    def mmap[T:Manifest](fd: Rep[Int], len: Rep[Int]): Rep[Array[T]]
    def stringFromCharArray(buf: Rep[Array[Char]], pos: Rep[Int], len: Rep[Int]): Rep[String]
    def prints(s: Rep[String]): Rep[Int]
    def infix_toInt(c: Rep[Char]): Rep[Int] = c.asInstanceOf[Rep[Int]]
    def infix_toLong(c: Rep[Int]): Rep[Long] = c.asInstanceOf[Rep[Long]]

    class Scanner(name: Rep[String]) {
      val fd = open(name)
      val fl = filelen(fd)
      val data = mmap[Char](fd,fl)
      var pos = 0

      /*def next(d: Rep[Char]): Rep[String] = {
        val start = pos: Rep[Int] // force read
        while (data(pos) != d) pos += 1
        val len = pos - start
        pos += 1
        RString(stringFromCharArray(data,start,len), len)
      }*/

      def nextInt: Rep[Int] = nextInt('|')
      def nextDouble: Rep[Double] = nextDouble('|')
      def nextDate: Rep[Long] = nextDate('|')
      def nextChar: Rep[Character] = nextChar('|')

      def nextInt(d: Rep[Char] = '|'): Rep[Int] = {
        val start = pos: Rep[Int] // force read
        var num = 0
        while (boolean_and(data(pos) != d, data(pos) != '\n')) {
          num = num * 10 + (data(pos) - '0').toInt
          pos += 1
        }
        pos += 1
        //printf("nextInt %d\n",num)
        num
      }

      def nextDouble(d: Rep[Char] = '|'): Rep[Double] = {
        val start = pos: Rep[Int] // force read
        var num = 0
        var denom = 1
        while (boolean_and(data(pos) != '.', data(pos) != d) && data(pos) != '\n') {
          num = num * 10 + (data(pos) - '0').toInt
          pos += 1
        }
        if (data(pos) == '.') {
            pos += 1
            while (boolean_and(data(pos) != d, data(pos) != '\n')) {
              num = num * 10 + (data(pos) - '0').toInt
              denom = denom * 10
              pos += 1
            }
        }
        pos += 1
        val res = num.doubleValue / denom.doubleValue
        //printf("nextDouble %d/%d=%.2f\n",num,denom,res)
        res
      }

      def nextDate(d: Rep[Char] = '|'): Rep[Long] = {
        val year = nextInt('-')
        val month = nextInt('-')
        val day = nextInt(d)
        year.toLong * 10000L + month.toLong * 100L + day.toLong
      }

      def nextString(limit: Rep[Int], d: Rep[Char] = '|'): Rep[String] = {
        val start = pos: Rep[Int] // force read
        while (boolean_and(data(pos) != d, data(pos) != '\n')) pos += 1
        val len = pos - start
        pos += 1
        stringFromCharArray(data,start,len) //len
      }

      def nextChar(d: Rep[Char] = '|'): Rep[Character] = {
        val c = data(pos)
        pos += 2 // skip delim
        //printf("nextChar %c\n",c)
        c.asInstanceOf[Rep[Character]]
      }

      def hasNext = pos < fl
      def close = fclose(fd)
    }


}

trait ScannerExp extends Scanner with BaseExp with EffectExp with StructExp {

    def open(name: Rep[String]) = uncheckedPure[Int]("open(",name,",0)")
    def fclose(fd: Rep[Int]) = unchecked[Unit]("fclose(",fd,")")
    def filelen(fd: Rep[Int]) = uncheckedPure[Int]("fsize(",fd,")") // FIXME: fresh name
    def mmap[T:Manifest](fd: Rep[Int], len: Rep[Int]) = uncheckedPure[Array[T]]("mmap(0, ",len,", PROT_READ, MAP_FILE | MAP_SHARED, ",fd,", 0)")
    def stringFromCharArray(data: Rep[Array[Char]], pos: Rep[Int], len: Rep[Int]): Rep[String] = uncheckedPure[String](data,"+",pos)
    def prints(s: Rep[String]): Rep[Int] = unchecked[Int]("printll(",s,")")


    case class ScannerApply(x:Rep[java.util.Scanner]) extends Def[java.util.Scanner]
    case class NewScanner(x:Rep[String]) extends Def[java.util.Scanner]
    case class ScannerNextInt(x: Rep[java.util.Scanner]) extends Def[Int]
    case class ScannerNextDouble(x: Rep[java.util.Scanner]) extends Def[Double]
    case class ScannerNextChar(x: Rep[java.util.Scanner]) extends Def[java.lang.Character]
    case class ScannerNextString(x: Rep[java.util.Scanner], y: Rep[Any], z: Rep[Int]) extends Def[String] {
        // Used in C code generation
        val c = fresh[java.lang.Character]
        val cnt = fresh[Int]
    }
    case class ScannerNextDate(x: Rep[java.util.Scanner]) extends Def[Long] {
        // Used in C code generation
        val year = fresh[Int]
        val month = fresh[Int]
        val day = fresh[Int]
    }
    case class ScannerHasNext(x: Rep[java.util.Scanner]) extends Def[Boolean]

    def scannerApply(x: Rep[java.util.Scanner]) = ScannerApply(x)
    def newScanner(x: Rep[String]) = reflectEffect(NewScanner(x))
    def scannerNextInt(x: Rep[java.util.Scanner]) = reflectEffect(ScannerNextInt(x))
    def scannerNextDouble(x: Rep[java.util.Scanner]): Rep[Double] = reflectEffect(ScannerNextDouble(x))
    def scannerNextChar(x: Rep[java.util.Scanner]): Rep[java.lang.Character] = reflectEffect(ScannerNextChar(x))
    def scannerNextString(x: Rep[java.util.Scanner], y: Rep[Any], z: Rep[Int]): Rep[String] = reflectEffect(ScannerNextString(x,y,z))
    def scannerNextDate(x: Rep[java.util.Scanner]): Rep[Long] = reflectEffect(ScannerNextDate(x))
    def scannerHasNext(x: Rep[java.util.Scanner]): Rep[Boolean] = reflectEffect(ScannerHasNext(x))

    override def mirror[A:Manifest](e: Def[A], f: Transformer)(implicit pos: SourceContext): Exp[A] = (e match {
        case Reflect(NewScanner(s),u,ef) => reflectMirrored(Reflect(NewScanner(f(s)), mapOver(f,u), f(ef)))
        case Reflect(ScannerHasNext(s),u,ef) => reflectMirrored(Reflect(ScannerHasNext(f(s)), mapOver(f,u), f(ef)))
        case Reflect(ScannerNextInt(s),u,ef) => reflectMirrored(Reflect(ScannerNextInt(f(s)), mapOver(f,u), f(ef)))
        case Reflect(ScannerNextDouble(s),u,ef) => reflectMirrored(Reflect(ScannerNextDouble(f(s)), mapOver(f,u), f(ef)))
        case Reflect(ScannerNextChar(s),u,ef) => reflectMirrored(Reflect(ScannerNextChar(f(s)), mapOver(f,u), f(ef)))
        case Reflect(ScannerNextString(s,b,z),u,ef) => reflectMirrored(Reflect(ScannerNextString(f(s),f(b),f(z)), mapOver(f,u), f(ef)))
        case Reflect(ScannerNextDate(s),u,ef) => reflectMirrored(Reflect(ScannerNextDate(f(s)), mapOver(f,u), f(ef)))
        case _ => super.mirror(e,f)
    }).asInstanceOf[Exp[A]]
}

trait ScalaGenScanner extends ScalaGenBase {
    val IR: ScannerExp
    import IR._
  
    override def emitNode(sym: Sym[Any], rhs: Def[Any]) = rhs match {
        case ScannerApply(x) =>  emitValDef(sym, "" + quote(x) + ".apply()")
        case NewScanner(x) =>  emitValDef(sym, "new miniDB.K2DBScanner(" + quote(x) + ")")
        case ScannerNextInt(x) => emitValDef(sym, quote(x) + ".next_int")
        case ScannerNextDouble(x) => emitValDef(sym, quote(x) + ".next_double")
        case ScannerNextChar(x) => emitValDef(sym, quote(x) + ".next_char")
        case ScannerNextString(x,y,z) => emitValDef(sym, quote(x) + ".next(" + quote(y) + ")")
        case ScannerNextDate(x) => emitValDef(sym, quote(x) + ".next_date")
        case ScannerHasNext(x) => emitValDef(sym, quote(x) + ".hasNext")
        case _ => super.emitNode(sym, rhs)
    }
}

trait CGenScanner extends CGenBase with GenericNestedCodegen {
    val IR: ScannerExp
    import IR._
    
    /*override def lowerNode[T:Manifest](sym: Sym[T], rhs: Def[T]) = rhs match {
        case ScannerNextString(x,y) =>
            sym.atPhase(LIRLowering) {
                val ar = field[Array[T]](LIRLowering(y), "array")
                scannerNextString(LIRLowering(x), ar).asInstanceOf[Exp[T]]
            }
        case _ => super.lowerNode(sym, rhs)
    }*/

    def printScanf(x: Rep[java.util.Scanner], read: String, sym: Sym[Any]) {
        stream.println("if (fscanf(" + quote(x) + ",\"%" + read +"|\",&"+quote(sym)+") == EOF) break;")
    }
    def printString(x: Rep[java.util.Scanner], cnt: Sym[Int], c: Sym[java.lang.Character], y: Rep[Any], limit: Rep[Int]) {
        emitValDef(cnt, "0")
        emitValDef(c, "\' \'")
        stream.println("while (1) {")
        stream.println("fscanf(" + quote(x) + ",\"%c\",&"+quote(c) + ");")
        stream.println("if (" + quote(c) + "==\'|\' || " + quote(c) + "==\'\\n\') break;")
        stream.println("if (" + quote(cnt) + ">=" + quote(limit)+") { printf(\"ERROR: scanner.nextString reading past end of buffer %d\","+quote(cnt)+"); break;} ")
        stream.println("((char*)" + quote(y) + ")[" + quote(cnt) + "] = " + quote(c) + ";")
        stream.println(quote(cnt) + " += 1;")
        stream.println("}")
        stream.println("((char*)" + quote(y) + ")[" + quote(cnt) + "] = '\\0';")
    }

    override def remap[A](m: Manifest[A]) = {
        m match {
            case s if s == manifest[java.util.Scanner] => "FILE*"
            case _ => super.remap(m)
        }
    }

    override def emitNode(sym: Sym[Any], rhs: Def[Any]) = rhs match {
        case ScannerApply(x) =>  //emitValDef(sym, "" + quote(x) + ".apply()")
        case NewScanner(x) =>  emitValDef(sym, "fopen(" + quote(x) + ", \"r\")")
        case s@ScannerNextInt(x) => 
            emitValDef(sym, "0")
            printScanf(x,"d",sym)
        case s@ScannerNextDouble(x) => 
            emitValDef(sym, "0.0")
            printScanf(x,"lf",sym)
        case s@ScannerNextChar(x) => 
            emitValDef(sym, "\' \'")
            printScanf(x,"c",sym)
        case s@ScannerNextString(x,y,z) => printString(x, s.cnt, s.c, y,z)
        case s@ScannerNextDate(x) => {
            emitValDef(s.year,"0")
            emitValDef(s.month,"0")
            emitValDef(s.day,"0")
            stream.println("fscanf(" + quote(x) + ", \"%d-%d-%d|\",&" + quote(s.year) + ", &" + quote(s.month) + ", &" + quote(s.day) + ");")
            emitValDef(sym, "(" + quote(s.year) + " * 10000) + (" + quote(s.month) + " * 100) + " + quote(s.day))
        }
        case ScannerHasNext(x) => emitValDef(sym, "!feof(" + quote(x) +")")
        case _ => super.emitNode(sym, rhs)
    }
}
