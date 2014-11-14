package miniDB

import scala.virtualization.lms.internal._
import scala.virtualization.lms.common._
import scala.reflect.SourceContext

trait Scanner extends Base {

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
}

trait ScannerExp extends Scanner with BaseExp with EffectExp with StructExp {
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
