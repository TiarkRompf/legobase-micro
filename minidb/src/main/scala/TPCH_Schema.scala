package miniDB


import scala.virtualization.lms.common._
import scala.virtualization.lms.common
import scala.virtualization.lms.internal._
import scala.virtualization.lms.util._
import java.io.{PrintWriter,StringWriter,FileOutputStream}
import scala.collection.mutable.HashMap
import scala.collection.mutable.ListBuffer
import scala.reflect.SourceContext

trait TPCHRelations extends ArrayOps with StringOps with LiftNumeric with Structs {
	lazy val LINEITEM_NAME = "LINEITEM"
	lazy val CUSTOMER_NAME = "CUSTOMER"
	lazy val ORDERS_NAME   = "ORDERS"
	lazy val PART_NAME     = "PART"
	lazy val REGION_NAME   = "REGION"
	lazy val NATION_NAME   = "NATION"
	lazy val SUPPLIER_NAME = "SUPPLIER"
	lazy val PARTSUPP_NAME = "PARTSUPP"

	def datapath: String
	def dataFile(s: String) = datapath + s.toLowerCase +  ".tbl"

	lazy val LINEITEMTABLE = dataFile(LINEITEM_NAME)
	lazy val CUSTOMERTABLE = dataFile(CUSTOMER_NAME)	
	lazy val ORDERSTABLE   = dataFile(ORDERS_NAME  )	
	lazy val PARTTABLE     = dataFile(PART_NAME    )
	lazy val REGIONTABLE   = dataFile(REGION_NAME  )	
	lazy val NATIONTABLE   = dataFile(NATION_NAME  )	
	lazy val SUPPLIERTABLE = dataFile(SUPPLIER_NAME)	
	lazy val PARTSUPPTABLE = dataFile(PARTSUPP_NAME)	
	
	// TODO: move to dataStruct
	type LegoString = String
	def infix_charAt(s1: Rep[String],idx:Rep[Long])(implicit pos: SourceContext): Rep[Character] = s1.asInstanceOf[Rep[Array[Character]]](idx)
	def infix_containsSlice(s1: Rep[String],s2:Rep[String])(implicit pos: SourceContext): Rep[Boolean] = string_containsSlice(s1,s2)
	def infix_compareTo(s1: Rep[String],s2:Rep[String])(implicit pos: SourceContext): Rep[Int] = string_compareTo(s1,s2)
	def infix_indexOfSlice(s1: Rep[String],s2:Rep[String],idx:Rep[Int])(implicit pos: SourceContext): Rep[Int] = string_indexOfSlice(s1,s2,idx)
	def string_new(s1: Rep[Character],s2:Rep[Character])(implicit pos: SourceContext): Rep[String] = {
		val buf = NewArray[Character](3L)
		buf(0L) = s1
		buf(1L) = s2
		buf.asInstanceOf[Rep[String]]
	}


    //implicit def recordTyp[T<:Record:RefinedManifest] = Schema[T](Map())
	type LINEITEMRecord = Record {
		val L_ORDERKEY: Int; 
		val L_PARTKEY: Int;
		val L_SUPPKEY: Int;
		val L_LINENUMBER: Int;
		val L_QUANTITY: Double;
		val L_EXTENDEDPRICE: Double;
		val L_DISCOUNT: Double;
		val L_TAX: Double;
		val L_RETURNFLAG: Character; 
		val L_LINESTATUS: Character;
		val L_SHIPDATE: Long;
		val L_COMMITDATE: Long;
		val L_RECEIPTDATE: Long;
		val L_SHIPINSTRUCT: LegoString;
		val L_SHIPMODE: LegoString; 
		val L_COMMENT: LegoString;
	}
	def newLINEITEMRecord(ORDERKEY: Rep[Int], PARTKEY: Rep[Int], SUPPKEY: Rep[Int], LINENUMBER: Rep[Int], 
					      QUANTITY: Rep[Double], EXTENDEDPRICE: Rep[Double], DISCOUNT: Rep[Double], TAX: Rep[Double], 
					      RETURNFLAG: Rep[Character], LINESTATUS: Rep[Character], SHIPDATE: Rep[Long], COMMITDATE: Rep[Long], 
						  RECEIPTDATE: Rep[Long], SHIPINSTRUCT: Rep[LegoString], SHIPMODE: Rep[LegoString], 
						  COMMENT: Rep[LegoString]): Rep[LINEITEMRecord] = {
		new Record {
			val L_ORDERKEY = ORDERKEY;
			val L_PARTKEY = PARTKEY;
			val L_SUPPKEY = SUPPKEY;
			val L_LINENUMBER = LINENUMBER;
			val L_QUANTITY = QUANTITY;
			val L_EXTENDEDPRICE = EXTENDEDPRICE;
			val L_DISCOUNT = DISCOUNT;
			val L_TAX = TAX;
			val L_RETURNFLAG = RETURNFLAG;
			val L_LINESTATUS = LINESTATUS;
			val L_SHIPDATE = SHIPDATE;
			val L_COMMITDATE = COMMITDATE;
			val L_RECEIPTDATE = RECEIPTDATE;
			val L_SHIPINSTRUCT = SHIPINSTRUCT;
			val L_SHIPMODE = SHIPMODE;
			val L_COMMENT = COMMENT;
		}
	}

	type ORDERSRecord = Record {
		val O_ORDERKEY : Int;
        val O_CUSTKEY  : Int;
        val O_ORDERSTATUS : Character;
        val O_TOTALPRICE : Double;
        val O_ORDERDATE : Long;
        val O_ORDERPRIORITY : LegoString;
        val O_CLERK : LegoString;
        val O_SHIPPRIORITY : Int;
        val O_COMMENT: LegoString;
	}
	def newORDERSRecord(ORDERKEY: Rep[Int], CUSTKEY: Rep[Int], ORDERSTATUS: Rep[Character], TOTALPRICE: Rep[Double], ORDERDATE: Rep[Long], ORDERPRIORITY: Rep[LegoString], CLERK: Rep[LegoString], SHIPPRIORITY: Rep[Int], COMMENT: Rep[LegoString]): Rep[ORDERSRecord] = {
		new Record {
			val O_ORDERKEY = ORDERKEY
    	    val O_CUSTKEY  = CUSTKEY
        	val O_ORDERSTATUS = ORDERSTATUS
	        val O_TOTALPRICE = TOTALPRICE
    	    val O_ORDERDATE = ORDERDATE
        	val O_ORDERPRIORITY = ORDERPRIORITY
	        val O_CLERK = CLERK
    	    val O_SHIPPRIORITY = SHIPPRIORITY
        	val O_COMMENT = COMMENT
		}
 	}

	type REGIONRecord = Record {
		val R_REGIONKEY: Int; 
		val R_NAME: LegoString;
		val R_COMMENT: LegoString;
	}
	def newREGIONRecord(REGIONKEY: Rep[Int], NAME: Rep[LegoString], COMMENT: Rep[LegoString]): Rep[REGIONRecord] = {
		new Record {
			val R_REGIONKEY = REGIONKEY;
			val R_NAME = NAME;
			val R_COMMENT = COMMENT;
		}
	}
	
	type NATIONRecord = Record {
		val N_NATIONKEY: Int; 
		val N_NAME: LegoString;
		val N_REGIONKEY: Int;
		val N_COMMENT: LegoString;
	}
	def newNATIONRecord(NATIONKEY: Rep[Int], NAME: Rep[LegoString], REGIONKEY: Rep[Int], COMMENT: Rep[LegoString] ): Rep[NATIONRecord] = {
		new Record {
			val N_NATIONKEY = NATIONKEY
			val N_NAME = NAME
			val N_REGIONKEY = REGIONKEY
			val N_COMMENT = COMMENT
		}
	}

	type PARTRecord = Record {
		val P_PARTKEY: Int;
		val P_NAME: LegoString;
		val P_MFGR: LegoString;
		val P_BRAND: LegoString;
		val P_TYPE: LegoString;
		val P_SIZE: Int;
		val P_CONTAINER: LegoString;
		val P_RETAILPRICE: Double;
		val P_COMMENT: LegoString;
	}
	def newPARTRecord(PARTKEY: Rep[Int], NAME: Rep[LegoString], MFGR: Rep[LegoString], BRAND: Rep[LegoString], TYPE: Rep[LegoString], SIZE: Rep[Int], CONTAINER: Rep[LegoString], RETAILPRICE: Rep[Double], COMMENT: Rep[LegoString]): Rep[PARTRecord] = {
		new Record {
			val P_PARTKEY = PARTKEY;
			val P_NAME = NAME;
			val P_MFGR = MFGR;
			val P_BRAND = BRAND;
			val P_TYPE = TYPE;
			val P_SIZE = SIZE;
			val P_CONTAINER = CONTAINER;
			val P_RETAILPRICE = RETAILPRICE;
			val P_COMMENT = COMMENT;
		}
	}

	type CUSTOMERRecord = Record {
		val C_CUSTKEY: Int;
		val C_NAME: LegoString;
		val C_ADDRESS: LegoString;
		val C_NATIONKEY: Int;
		val C_PHONE: LegoString;
		val C_ACCTBAL: Double;
		val C_MKTSEGMENT: LegoString;
		val C_COMMENT: LegoString;
	}
	def newCUSTOMERRecord(CUSTKEY: Rep[Int], NAME: Rep[LegoString], ADDRESS: Rep[LegoString], NATIONKEY: Rep[Int], PHONE: Rep[LegoString], ACCTBAL: Rep[Double], MKTSEGMENT: Rep[LegoString], COMMENT: Rep[LegoString]): Rep[CUSTOMERRecord] = {
		new Record {
			val C_CUSTKEY = CUSTKEY;
			val C_NAME = NAME;
			val C_ADDRESS = ADDRESS;
			val C_NATIONKEY = NATIONKEY;
			val C_PHONE = PHONE;
			val C_ACCTBAL = ACCTBAL;
			val C_MKTSEGMENT = MKTSEGMENT;
			val C_COMMENT = COMMENT;
		}
	}

	type SUPPLIERRecord = Record {
    	val S_SUPPKEY: Int;
        val S_NAME: LegoString;
        val S_ADDRESS: LegoString;
        val S_NATIONKEY: Int;
        val S_PHONE: LegoString;
        val S_ACCTBAL: Double;
        val S_COMMENT: LegoString;
	}
	def newSUPPLIERRecord(SUPPKEY: Rep[Int], NAME: Rep[LegoString], ADDRESS: Rep[LegoString], NATIONKEY: Rep[Int], PHONE: Rep[LegoString], ACCTBAL: Rep[Double], COMMENT: Rep[LegoString]): Rep[SUPPLIERRecord] = {
		new Record {
			val S_SUPPKEY = SUPPKEY;
        	val S_NAME = NAME;
	        val S_ADDRESS = ADDRESS;
    	    val S_NATIONKEY = NATIONKEY;
        	val S_PHONE = PHONE;
	        val S_ACCTBAL = ACCTBAL;
    	    val S_COMMENT = COMMENT;
		}
	}

	type PARTSUPPRecord = Record {
		val PS_PARTKEY: Int;
		val PS_SUPPKEY: Int;
		val PS_AVAILQTY: Int;
		val PS_SUPPLYCOST: Double;
		val PS_COMMENT: LegoString;
	}
	def newPARTSUPPRecord(PARTKEY: Rep[Int], SUPPKEY: Rep[Int], AVAILQTY: Rep[Int], SUPPLYCOST: Rep[Double], COMMENT: Rep[LegoString]): Rep[PARTSUPPRecord] = {
		new Record {
			val PS_PARTKEY = PARTKEY;
			val PS_SUPPKEY = SUPPKEY;
			val PS_AVAILQTY = AVAILQTY;	
			val PS_SUPPLYCOST = SUPPLYCOST;
			val PS_COMMENT = COMMENT;
		}
	}

	// Helper structs
	type AGGRecord[B] = Record {
		val key: B;
		val aggs: Array[Double];
	}
	def newAGGRecord[B:Manifest](k: Rep[B], a: Rep[Array[Double]]): Rep[AGGRecord[B]] = {
		new Record {
			val key = k;
			val aggs = a;
		}
	}

	type AGGRecord1[B,C] = Record {
		val exists: Boolean;
		val key: B;
		val aggs: C;
	}
	def newAGGRecord1[B:Manifest,C:Manifest](k: Rep[B], a: Rep[C]): Rep[AGGRecord1[B,C]] = {
		new Record {
			val exists = unit(true)
			val key = k;
			val aggs = a;
		}
	}

}

