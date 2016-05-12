package miniDB

import scala.virtualization.lms.common._
import scala.virtualization.lms.common
import scala.virtualization.lms.internal._
import scala.virtualization.lms.util._
import java.io.{PrintWriter,StringWriter,FileOutputStream}
import scala.collection.mutable.HashMap
import scala.collection.mutable.ListBuffer


trait Loader extends DSL with TPCHRelations with DataStruct {
  def loadLineitem1():LegoTable[LINEITEMRecord] = ???
  def loadRegion1(): 	LegoTable[REGIONRecord] = ???
  def loadOrders1():	LegoTable[ORDERSRecord] = ???
  def loadPart1(): 	LegoTable[PARTRecord] = ???
  def loadNation1(): 	LegoTable[NATIONRecord] = ???
  def loadCustomer1():LegoTable[CUSTOMERRecord] = ???
  def loadPartsupp1():LegoTable[PARTSUPPRecord] = ???
  def loadSupplier1():LegoTable[SUPPLIERRecord] = ???
  /*
  def loadLineitem(): Rep[Array[LINEITEMRecord]]
  def loadRegion(): 	Rep[Array[REGIONRecord]]
  def loadOrders():	Rep[Array[ORDERSRecord]]
  def loadPart(): 	Rep[Array[PARTRecord]]
  def loadNation(): 	Rep[Array[NATIONRecord]]
  def loadCustomer(): Rep[Array[CUSTOMERRecord]]
  def loadPartsupp(): Rep[Array[PARTSUPPRecord]]
  def loadSupplier(): Rep[Array[SUPPLIERRecord]]
   */
}


trait CSVLoader extends Loader {
  def loadString(size: Rep[Int], s: Scanner): Rep[LegoString] = {
    /*val NAME = NewArray[Byte](size+1) // +1 for null terminator
    s.nextString(NAME,size)
    //NAME.filter(y => y != 0)
    NAME.asInstanceOf[Rep[LegoString]].unsafeImmutable // HACK: depends on C string representation as char*
     */
    s.nextString(size)
  }
  override def loadLineitem1() = {
    val name = LINEITEM_NAME
    val file = dataFile(name)
    // Load Relation
    val s = new Scanner(file)
    val ab = LegoCollect[LINEITEMRecord](SizeDefaults.defaultInputBufferSize)
    while (s.hasNext) {
      val newEntry = newLINEITEMRecord(s.nextInt, s.nextInt, s.nextInt, s.nextInt,
        s.nextDouble, s.nextDouble, s.nextDouble, s.nextDouble,
        s.nextChar, s.nextChar, s.nextDate, s.nextDate, s.nextDate,
        loadString(25,s), loadString(10,s), loadString(44,s))
      s.skipLine()
      ab append newEntry
    }
    LegoTable(name,ab.result)
  }
  override def loadRegion1() = {
    val name = REGION_NAME
    val file = dataFile(name)
    /* Load Relation */
   val s = new Scanner(file)
   val ab = LegoCollect[REGIONRecord](SizeDefaults.defaultInputBufferSize)
   while (s.hasNext) {
     val newEntry = newREGIONRecord(s.nextInt, loadString(25,s), loadString(152,s))
      s.skipLine()
     ab append newEntry
   }
   ab.result
   LegoTable(name,ab.result)
  }
  override def loadOrders1() = {
    val name = ORDERS_NAME
    val file = dataFile(name)
    /* Load Relation */
   val s = new Scanner(file)
   val ab = LegoCollect[ORDERSRecord](SizeDefaults.defaultInputBufferSize)
   while (s.hasNext) {
     val newEntry = newORDERSRecord(s.nextInt, s.nextInt, s.nextChar, s.nextDouble, s.nextDate,
       loadString(15,s), loadString(15,s), s.nextInt, loadString(79,s))
      s.skipLine()
     ab append newEntry
   }
   ab.result
   LegoTable(name,ab.result)
  }
  override def loadPart1() = {
    val name = PART_NAME
    val file = dataFile(name)
    /* Load Relation */
   val s = new Scanner(file)
   val ab = LegoCollect[PARTRecord](SizeDefaults.defaultInputBufferSize)
   var i = 0
   while (s.hasNext) {
     val newEntry = newPARTRecord(s.nextInt, loadString(55,s), loadString(25,s), loadString(10,s), loadString(25,s),
       s.nextInt, loadString(10,s), s.nextDouble, loadString(23,s))
      s.skipLine()
     ab append newEntry
   }
   ab.result
   LegoTable(name,ab.result)
  }
  override def loadNation1() = {
    val name = NATION_NAME
    val file = dataFile(name)
    /* Load Relation */
   val s = new Scanner(file)
   val ab = LegoCollect[NATIONRecord](SizeDefaults.defaultInputBufferSize)
   while (s.hasNext) {
     val newEntry = newNATIONRecord(s.nextInt, loadString(25,s), s.nextInt, loadString(152,s))
      s.skipLine()
     ab append newEntry
   }
   ab.result
   LegoTable(name,ab.result)
  }
  override def loadCustomer1() = {
    val name = CUSTOMER_NAME
    val file = dataFile(name)
    /* Load Relation */
   val s = new Scanner(file)
   val ab = LegoCollect[CUSTOMERRecord](SizeDefaults.defaultInputBufferSize)
   while (s.hasNext) {
     val newEntry = newCUSTOMERRecord(s.nextInt, loadString(25,s), loadString(40,s), s.nextInt, loadString(15,s), s.nextDouble, loadString(10,s), loadString(117,s))
      s.skipLine()
     ab append newEntry
   }
   ab.result
   LegoTable(name,ab.result)
  }
  override def loadPartsupp1() = {
    val name = PARTSUPP_NAME
    val file = dataFile(name)
    /* Load Relation */
   val s = new Scanner(file)
   val ab = LegoCollect[PARTSUPPRecord](SizeDefaults.defaultInputBufferSize)
   while (s.hasNext) {
     val newEntry = newPARTSUPPRecord(s.nextInt, s.nextInt, s.nextInt, s.nextDouble, loadString(199,s))
      s.skipLine()
     ab append newEntry
   }
   ab.result
   LegoTable[PARTSUPPRecord](name,ab.result)
  }
  override def loadSupplier1() = {
    val name = SUPPLIER_NAME
    val file = dataFile(name)
    /* Load Relation */
   val s = new Scanner(file)
   val ab = LegoCollect[SUPPLIERRecord](SizeDefaults.defaultInputBufferSize)
   while (s.hasNext) {
     val newEntry = newSUPPLIERRecord(s.nextInt, loadString(25,s), loadString(40,s), s.nextInt, loadString(15,s), s.nextDouble, loadString(101,s))
      s.skipLine()
     ab append newEntry
   }
   ab.result
   LegoTable[SUPPLIERRecord](name,ab.result)
  }
}
