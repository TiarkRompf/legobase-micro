package miniDB

import scala.virtualization.lms.internal._
import scala.virtualization.lms.common._
import scala.reflect.SourceContext

trait Scanner extends ScalaOpsPkg with LiftVariables with LiftPrimitives  with LiftNumeric {

    def open(name: Rep[String]): Rep[Int]
    def fclose(fd: Rep[Int]): Rep[Unit]
    def filelen(fd: Rep[Int]): Rep[Long]
    def mmap[T:Manifest](fd: Rep[Int], len: Rep[Long]): Rep[Array[T]]
    def stringFromCharArray(buf: Rep[Array[Char]], pos: Rep[Long], len: Rep[Long]): Rep[String]
    def prints(s: Rep[String]): Rep[Int]
    def infix_toInt(c: Rep[Char]): Rep[Int] = c.asInstanceOf[Rep[Int]]
    def infix_toLong(c: Rep[Int]): Rep[Long] = c.asInstanceOf[Rep[Long]]

    class Scanner(name: Rep[String]) {
      val fd = open(name)
      val fl = filelen(fd)
      val data = mmap[Char](fd,fl)
      var pos = 0L

      /*def next(d: Rep[Char]): Rep[String] = {
        val start = pos: Rep[Long] // force read
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
        val start = pos: Rep[Long] // force read
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
        val start = pos: Rep[Long] // force read
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
        val start = pos: Rep[Long] // force read
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
    def filelen(fd: Rep[Int]) = uncheckedPure[Long]("fsize(",fd,")") // FIXME: fresh name
    def mmap[T:Manifest](fd: Rep[Int], len: Rep[Long]) = uncheckedPure[Array[T]]("mmap(0, ",len,", PROT_READ, MAP_FILE | MAP_SHARED, ",fd,", 0)")
    def stringFromCharArray(data: Rep[Array[Char]], pos: Rep[Long], len: Rep[Long]): Rep[String] = uncheckedPure[String](data,"+",pos)
    def prints(s: Rep[String]): Rep[Int] = unchecked[Int]("printll(",s,")")

}

trait ScalaGenScanner extends ScalaGenBase {
    val IR: ScannerExp
    import IR._
  
}

trait CGenScanner extends CGenBase with GenericNestedCodegen {
    val IR: ScannerExp
    import IR._
    
}
