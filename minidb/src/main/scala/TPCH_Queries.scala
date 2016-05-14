package miniDB


import scala.virtualization.lms.common._
import scala.virtualization.lms.common
import scala.virtualization.lms.internal._
import scala.virtualization.lms.util._
import java.io.{PrintWriter,StringWriter,FileOutputStream}
import scala.collection.mutable.HashMap
import scala.collection.mutable.ListBuffer
import scala.collection.mutable.ArrayBuffer
import scala.virtualization.lms.util.OverloadHack
import scala.reflect.{SourceContext, RefinedManifest}
/*
trait Queries extends Q1 with Q2 with Q3 with Q4 with Q5 with Q6 with Q7 with Q8 with Q9 with Q10 with Q11 with Q12
                         with Q13 with Q14 with Q15 with Q16 with Q17 with Q18 with Q19 with Q20 with Q21 with Q22
*/

trait GenericQuery extends Engine with Loader {
  def runQuery[A](block: => PrintOp[A]) = { numRuns: Int =>
    for (i <- 0 until numRuns: Rep[Range]) {
      val po = block
      timeGeneratedCode {
        po.open
        po.next
        printf("(%ld rows)\\n", po.numRows)
      }
    }
  }
}

trait Queries extends GenericQuery {
    def zero1 = new Record {
        val _0 = 0.0
    }
    def zero2 = new Record {
        val _0 = 0.0; val _1 = 0.0
    }
    def zero6 = new Record {
        val _0 = 0.0; val _1 = 0.0; val _2 = 0.0; val _3 = 0.0; val _4 = 0.0; val _5 = 0.0
    }

    def Q1 = {
        val lineitemTable = loadLineitem1()
        runQuery {
                val constantDate: Long = parseDate("1998-08-11")
                val lineitemScan = SelectOp(ScanOp2(lineitemTable))(x => x.L_SHIPDATE <= constantDate)
                val aggOp = AggOp1(lineitemScan)(x => new Record {
                    val L_RETURNFLAG = x.L_RETURNFLAG
                    val L_LINESTATUS = x.L_LINESTATUS
                })(zero6)((t,currAgg) => new Record {
                    val _0 = {t.L_DISCOUNT + currAgg._0}
                    val _1 = {t.L_QUANTITY + currAgg._1}
                    val _2 = {t.L_EXTENDEDPRICE + currAgg._2}
                    val _3 = {(t.L_EXTENDEDPRICE * (1.0-t.L_DISCOUNT)) + currAgg._3}
                    val _4 = {(t.L_EXTENDEDPRICE * (1.0-t.L_DISCOUNT) * (1.0+t.L_TAX)) + currAgg._4}
                    val _5 = {currAgg._5 + 1}
                })
                val mapOp = MapOp1(aggOp)(kv => new Record {
                    val key = kv.key
                    val aggs = new Record {
                        val _0 = kv.aggs._0; val _1 = kv.aggs._1; val _2 = kv.aggs._2
                        val _3 = kv.aggs._3; val _4 = kv.aggs._4; val _5 = kv.aggs._5
                        val _6 = kv.aggs._1/kv.aggs._5 // AVG(L_QUANTITY)
                        val _7 = kv.aggs._2/kv.aggs._5 // AVG(L_EXTENDEDPRICE)
                        val _8 = kv.aggs._0/kv.aggs._5 // AVG(L_DISCOUNT)
                    }
                })
                val sortOp = SortOp(mapOp)((kv1,kv2) => {
                    var res = kv1.key.L_RETURNFLAG - kv2.key.L_RETURNFLAG
                    if (res == 0)
                        res = kv1.key.L_LINESTATUS - kv2.key.L_LINESTATUS
                    res
                })
                val po = PrintOp(sortOp)(kv => printf("%c|%c|%.2f|%.2f|%.2f|%.2f|%.2f|%.2f|%.6f|%.0f\n",
                  kv.key.L_RETURNFLAG,kv.key.L_LINESTATUS,kv.aggs._1,kv.aggs._2,kv.aggs._3,kv.aggs._4,
                  kv.aggs._6,kv.aggs._7,kv.aggs._8,kv.aggs._5)
                )
                po
        }
    }
    def Q2 = {
        val partTable     = loadPart1()
        val partsuppTable = loadPartsupp1()
        val nationTable   = loadNation1()
        val regionTable   = loadRegion1()
        val supplierTable = loadSupplier1()
        runQuery {
                val africa = parseString("EUROPE")
                val tin = parseString("BRASS")
                val size = 15
                val partsuppScan = ScanOp2(partsuppTable)
                val supplierScan = ScanOp2(supplierTable)
                // XX unnecessary to name all the fields
                val jo1 = MapOp1(HashJoinOp2(supplierScan, partsuppScan)((x,y) => x.S_SUPPKEY == y.PS_SUPPKEY)(x => x.S_SUPPKEY)(x => x.PS_SUPPKEY)) { x => new Record {
                    val PS_SUPPLYCOST = x.right.PS_SUPPLYCOST
                    val PS_PARTKEY    = x.right.PS_PARTKEY
                    val S_NATIONKEY   = x.left.S_NATIONKEY
                    val S_ACCTBAL     = x.left.S_ACCTBAL
                    val S_NAME        = x.left.S_NAME
                    val S_ADDRESS     = x.left.S_ADDRESS
                    val S_PHONE       = x.left.S_PHONE
                    val S_COMMENT     = x.left.S_COMMENT
                }}
                val nationScan = ScanOp2(nationTable)
                val jo2 = MapOp1(HashJoinOp2(nationScan, jo1)((x,y) => x.N_NATIONKEY == y.S_NATIONKEY)(x => x.N_NATIONKEY)(x => x.S_NATIONKEY)) { x => new Record {
                    val PS_SUPPLYCOST = x.right.PS_SUPPLYCOST
                    val PS_PARTKEY    = x.right.PS_PARTKEY
                    val S_ACCTBAL     = x.right.S_ACCTBAL
                    val S_NAME        = x.right.S_NAME
                    val S_ADDRESS     = x.right.S_ADDRESS
                    val S_PHONE       = x.right.S_PHONE
                    val S_COMMENT     = x.right.S_COMMENT
                    val N_NAME        = x.left.N_NAME
                    val N_REGIONKEY   = x.left.N_REGIONKEY
                }}
                val partScan = SelectOp(ScanOp2(partTable))(x => x.P_SIZE == size && x.P_TYPE.endsWith(tin))
                val jo3 = MapOp1(HashJoinOp2(partScan, jo2)((x,y) => x.P_PARTKEY == y.PS_PARTKEY)(x => x.P_PARTKEY)(x => x.PS_PARTKEY)) { x => new Record {
                    val PS_SUPPLYCOST = x.right.PS_SUPPLYCOST
                    val S_ACCTBAL     = x.right.S_ACCTBAL
                    val S_NAME        = x.right.S_NAME
                    val S_ADDRESS     = x.right.S_ADDRESS
                    val S_PHONE       = x.right.S_PHONE
                    val S_COMMENT     = x.right.S_COMMENT
                    val N_NAME        = x.right.N_NAME
                    val N_REGIONKEY   = x.right.N_REGIONKEY
                    val P_PARTKEY     = x.left.P_PARTKEY
                    val P_MFGR        = x.left.P_MFGR
                }}
                val regionScan = SelectOp(ScanOp2(regionTable))(x => x.R_NAME == africa)
                val jo4 = MapOp1(HashJoinOp2(regionScan, jo3)((x,y) => x.R_REGIONKEY == y.N_REGIONKEY)(x => x.R_REGIONKEY)(x => x.N_REGIONKEY)) { x => new Record {
                    val PS_SUPPLYCOST = x.right.PS_SUPPLYCOST
                    val S_ACCTBAL     = x.right.S_ACCTBAL
                    val S_NAME        = x.right.S_NAME
                    val S_ADDRESS     = x.right.S_ADDRESS
                    val S_PHONE       = x.right.S_PHONE
                    val S_COMMENT     = x.right.S_COMMENT
                    val N_NAME        = x.right.N_NAME
                    val P_PARTKEY     = x.right.P_PARTKEY
                    val P_MFGR        = x.right.P_MFGR
                }}
                //val wo = WindowOp(jo4)(x => x.f.P_PARTKEY.asInstanceOf[Rep[Int]])(x => x.minBy(y => y.f.PS_SUPPLYCOST.asInstanceOf[Rep[Double]]))

                val wo = MapOp1(AggOp1(jo4)(x => x.P_PARTKEY)(new Record { /*zero*/
                    val PS_SUPPLYCOST = 1e100 // Double.MaxValue ?
                    val S_ACCTBAL = 0.0
                    val S_NAME    = ""
                    val S_ADDRESS = ""
                    val S_PHONE   = ""
                    val S_COMMENT = ""
                    val N_NAME    = ""
                    val P_PARTKEY = 0
                    val P_MFGR    = ""
                })((t, currAgg) => {
                    var res = currAgg
                    if (t.PS_SUPPLYCOST < currAgg.PS_SUPPLYCOST) res = t// else currAgg
                    res
                }))(x => new Record {
                    val key = x.key
                    val wnd = x.aggs
                })

                val so = SortOp(wo)((x,y) => {
                    if (x.wnd.S_ACCTBAL.asInstanceOf[Rep[Double]] < y.wnd.S_ACCTBAL) 1
                    else if (x.wnd.S_ACCTBAL.asInstanceOf[Rep[Double]] > y.wnd.S_ACCTBAL) -1
                    else {
                        var res = x.wnd.N_NAME compareTo y.wnd.N_NAME
                        if (res == 0) {
                            res = x.wnd.S_NAME compareTo y.wnd.S_NAME
                            if (res == 0) res = x.wnd.P_PARTKEY - y.wnd.P_PARTKEY
                        }
                        res
                    }
                })
                var j = 0
                val po = PrintOp(so)(e => {
                    val kv = e.wnd
                    printf("%.2f|%.*s|%.*s|%d|%.*s|%.*s|%.*s|%.*s\n",
                        kv.S_ACCTBAL,kv.S_NAME.length,kv.S_NAME,kv.N_NAME.length,kv.N_NAME,kv.P_PARTKEY,kv.P_MFGR.length,kv.P_MFGR,
                        kv.S_ADDRESS.length,kv.S_ADDRESS,kv.S_PHONE.length,kv.S_PHONE,kv.S_COMMENT.length,kv.S_COMMENT)
                    j+=1
                }, () => j < 100)
                po
        }
    }

    def Q3 = {
        val lineitemTable = loadLineitem1()
        val ordersTable = loadOrders1()
        val customerTable = loadCustomer1()
        runQuery {
                val constantDate = parseDate("1995-03-15")
                val scanCustomer = SelectOp(ScanOp2(customerTable))(x => x.C_MKTSEGMENT == parseString("BUILDING"))
                val scanOrders   = SelectOp(ScanOp2(ordersTable))(x => x.O_ORDERDATE < constantDate)
                val scanLineitem = SelectOp(ScanOp2(lineitemTable))(x => x.L_SHIPDATE > constantDate)
                val jo1 = MapCatOp(HashJoinOp2(scanCustomer, scanOrders)( (x,y) => x.C_CUSTKEY == y.O_CUSTKEY)(x => x.C_CUSTKEY)(x => x.O_CUSTKEY))
                val jo2 = MapCatOp(HashJoinOp2(jo1, scanLineitem)( (x,y) => x.f.O_ORDERKEY == y.L_ORDERKEY)(x => x.f.O_ORDERKEY)(x => x.L_ORDERKEY))
                val aggOp = AggOp1(jo2)(x => new Record {
                    val L_ORDERKEY  = x[Int]("L_ORDERKEY")
                    val O_ORDERDATE = x[Long]("O_ORDERDATE")
                    val O_SHIPPRIORITY = x[Int]("O_SHIPPRIORITY")
                })(zero1)((t, currAgg) => new Record {
                    val _0 = { currAgg._0 + t[Double]("L_EXTENDEDPRICE") * (1.0-t[Double]("L_DISCOUNT"))}
                })
                val sortOp = SortOp(aggOp)((kv1,kv2) => {
                    val agg1 = kv1.aggs._0; val agg2 = kv2.aggs._0
                    if (agg1 < agg2) 1
                    else if (agg1 > agg2) -1
                    else {
                        val k1 = kv1.key.O_ORDERDATE
                        val k2 = kv2.key.O_ORDERDATE
                        if (k1 < k2)  -1
                        else if (k1 > k2) 1
                        else 0
                    }
                })
                // SORT IS A BIG BOTTLENECK HERE: RESULT IS BIG, BUT WE ONLY TAKE THE TOP 10 ROWS BELOW
                var i = 0
                val po = PrintOp(sortOp)(kv => {
                    printf("%d|%.4f|%s|%d\n",kv.key.L_ORDERKEY,kv.aggs._0,getDateAsString(kv.key.O_ORDERDATE),kv.key.O_SHIPPRIORITY)
                    i+=1
                }, () => i < 10)
                po
        }
    }

    def Q4 = {
        val lineitemTable = loadLineitem1()
        val ordersTable = loadOrders1()
        runQuery {
                val constantDate1: Long = parseDate("1993-10-01")
                val constantDate2: Long = parseDate("1993-07-01")
                val scanOrders   = SelectOp(ScanOp2(ordersTable))(x => x.O_ORDERDATE < constantDate1 && x.O_ORDERDATE >= constantDate2)
                val scanLineitem = SelectOp(ScanOp2(lineitemTable))(x => x.L_COMMITDATE < x.L_RECEIPTDATE)
                val hj = LeftHashSemiJoinOp1(scanOrders, scanLineitem)((x,y) => x.O_ORDERKEY == y.L_ORDERKEY)(x => x.O_ORDERKEY)(x => x.L_ORDERKEY)
                val aggOp = AggOp1(hj)(x => x.O_ORDERPRIORITY)(zero1)(
                    (t,currAgg) => new Record { val _0 = currAgg._0 + 1 }
                )
                val sortOp = SortOp(aggOp)((kv1,kv2) => {
                    val k1 = kv1.key; val k2 = kv2.key
                    k1 compareTo k2
                })
                val po = PrintOp(sortOp)(kv => printf("%.*s|%.0f\n",kv.key.length,kv.key,kv.aggs._0))
                po
        }
    }

    // this is VERSION_3, see below for alternatives tried earlier
    def Q5 = {
        val lineitemTable = loadLineitem1()
        val nationTable = loadNation1()
        val customerTable = loadCustomer1()
        val supplierTable = loadSupplier1()
        val regionTable = loadRegion1()
        val ordersTable = loadOrders1()
        runQuery {
                val constantDate1 = parseDate("1994-01-01")
                val constantDate2 = parseDate("1995-01-01")
                val scanRegion = SelectOp(ScanOp2(regionTable))(x => x.R_NAME == parseString("ASIA"))
                val scanNation = ScanOp2(nationTable)
                val scanSupplier = ScanOp2(supplierTable)
                val scanCustomer = ScanOp2(customerTable)
                val scanLineitem = ScanOp2(lineitemTable)
                val scanOrders = SelectOp(ScanOp2(ordersTable))(x => x.O_ORDERDATE >= constantDate1 && x.O_ORDERDATE < constantDate2)
                /*--*/
                val jo1 = MapOp1(HashJoinOp1(scanRegion, scanNation)((x,y) => x.R_REGIONKEY == y.N_REGIONKEY)(x => x.R_REGIONKEY)(x => x.N_REGIONKEY) { x =>
                    new Record { val dummy = 7 }}) { x =>
                    new Record { val N_NAME      = x.right.N_NAME
                                 val N_NATIONKEY = x.right.N_NATIONKEY
                               }}

                val jo2 = MapOp1(HashJoinOp1(jo1, scanCustomer)((x,y) => x.N_NATIONKEY == y.C_NATIONKEY)(x => x.N_NATIONKEY)(x => x.C_NATIONKEY) { x =>
                    new Record { val N_NAME      = x.N_NAME
                                 val N_NATIONKEY = x.N_NATIONKEY
                               }}) { x =>
                    new Record { val N_NAME      = x.left.N_NAME
                                 val N_NATIONKEY = x.left.N_NATIONKEY
                                 val C_CUSTKEY   = x.right.C_CUSTKEY
                               }}

                val jo3 = MapOp1(HashJoinOp1(jo2, scanOrders)((x,y) => x.C_CUSTKEY == y.O_CUSTKEY)(x => x.C_CUSTKEY)(x => x.O_CUSTKEY) { x =>
                    new Record { val N_NAME      = x.N_NAME
                                 val N_NATIONKEY = x.N_NATIONKEY
                               }}) { x =>
                    new Record { val N_NAME      = x.left.N_NAME
                                 val N_NATIONKEY = x.left.N_NATIONKEY
                                 val O_ORDERKEY  = x.right.O_ORDERKEY
                               }}

                // (region X nation X customer X orders)  XX  lineitems  <--- match orderkey
                val jo4 = MapOp1(HashJoinOp1(jo3, scanLineitem)((x,y) => x.O_ORDERKEY == y.L_ORDERKEY)(x => x.O_ORDERKEY)(x => x.L_ORDERKEY) { x =>
                    new Record { val N_NAME      = x.N_NAME
                                 val N_NATIONKEY = x.N_NATIONKEY
                               }}) { x =>
                    new Record { val N_NAME      = x.left.N_NAME
                                 val N_NATIONKEY = x.left.N_NATIONKEY
                                 val L_SUPPKEY   = x.right.L_SUPPKEY
                                 val L_EXTENDEDPRICE  = x.right.L_EXTENDEDPRICE
                                 val L_DISCOUNT  = x.right.L_DISCOUNT
                               }}

                // suppler  XX  (region X nation X customer X orders X lineitems)  <--- match suppkey
                val jo5 = SelectOp(HashJoinOp1(scanSupplier, jo4)((x,y) => x.S_SUPPKEY == y.L_SUPPKEY)(x => x.S_SUPPKEY)(x => x.L_SUPPKEY) { x =>
                    new Record { val S_NATIONKEY = x.S_NATIONKEY }
                }){ x =>
                    x.left.S_NATIONKEY == x.right.N_NATIONKEY
                }

                val aggOp = AggOp1(jo5)(x => x.right.N_NAME)(new Record { val _0 = 0.0 })(
                    (t, currAgg) => new Record { val _0 = currAgg._0 + t.right.L_EXTENDEDPRICE * (1.0 - t.right.L_DISCOUNT) }
                )
                val sortOp = SortOp(aggOp)((x,y) => {
                    if (x.aggs._0 < y.aggs._0) 1
                    else if (x.aggs._0 > y.aggs._0) -1
                    else 0
                })
                PrintOp(sortOp) { kv =>
                    printf("%.*s|%.4f\n",kv.key.length,kv.key,kv.aggs._0)
                }
/*
original plan:

    ((((region X nation) X supplier) X customer) X orders) X lineitems   -->   match suppkey

second plan:

    (customer X (((region X nation) X supplier) X (orders X lineitems)))

this plan:

    (supplier X ((((region X nation) X customer) X orders) X lineitems))


struct REGIONRecord_NATIONRecord;
struct REGIONRecord_NATIONRecord_CUSTOMERRecord;
struct REGIONRecord_NATIONRecord_CUSTOMERRecord_ORDERSRecord;
struct REGIONRecord_NATIONRecord_CUSTOMERRecord_ORDERSRecord_LINEITEMRecord;
struct SUPPLIERRecord_REGIONRecord_NATIONRecord_CUSTOMERRecord_ORDERSRecord_LINEITEMRecord;
*/
        }
    }


    def Q5_VERSION_2 = {
        val lineitemTable = loadLineitem1()
        val nationTable = loadNation1()
        val customerTable = loadCustomer1()
        val supplierTable = loadSupplier1()
        val regionTable = loadRegion1()
        val ordersTable = loadOrders1()
        runQuery {
                val constantDate1 = parseDate("1996-01-01")
                val constantDate2 = parseDate("1997-01-01")
                val scanRegion = SelectOp(ScanOp2(regionTable))(x => x.R_NAME == parseString("ASIA"))
                val scanNation = ScanOp2(nationTable)
                val scanSupplier = ScanOp2(supplierTable)
                val scanCustomer = ScanOp2(customerTable)
                val scanLineitem = ScanOp2(lineitemTable)
                val scanOrders = SelectOp(ScanOp2(ordersTable))(x => x.O_ORDERDATE >= constantDate1 && x.O_ORDERDATE < constantDate2)
                /*--*/
                val jo1 = MapOp1(HashJoinOp1(scanRegion, scanNation)((x,y) => x.R_REGIONKEY == y.N_REGIONKEY)(x => x.R_REGIONKEY)(x => x.N_REGIONKEY) { x =>
                    new Record { val dummy = 7 }}) { x =>
                    new Record { val N_NAME      = x.right.N_NAME
                                 val N_NATIONKEY = x.right.N_NATIONKEY
                               }}

                val jo2 = MapOp1(HashJoinOp1(jo1, scanSupplier)((x,y) => x.N_NATIONKEY == y.S_NATIONKEY)(x => x.N_NATIONKEY)(x => x.S_NATIONKEY) { x =>
                    new Record { val N_NAME = x.N_NAME; val N_NATIONKEY = x.N_NATIONKEY }}) { x =>
                    new Record { val N_NAME      = x.left.N_NAME
                                 val N_NATIONKEY = x.left.N_NATIONKEY
                                 val S_SUPPKEY   = x.right.S_SUPPKEY
                               }}

                val jo3 = MapOp1(HashJoinOp1(scanOrders, scanLineitem)((x,y) => x.O_ORDERKEY == y.L_ORDERKEY)(x => x.O_ORDERKEY)(x => x.L_ORDERKEY) { x =>
                    new Record { val O_CUSTKEY  = x.O_CUSTKEY }}) { x =>
                    new Record { val O_CUSTKEY  = x.left.O_CUSTKEY
                                 val L_SUPPKEY  = x.right.L_SUPPKEY
                                 val L_EXTENDEDPRICE  = x.right.L_EXTENDEDPRICE
                                 val L_DISCOUNT  = x.right.L_DISCOUNT
                               }}

                // (region X nation X supplier)  XX  (orders X lineitems)  <--- match suppkey
                val jo4 = MapOp1(HashJoinOp1(jo2, jo3)((x,y) => x.S_SUPPKEY == y.L_SUPPKEY)(x => x.S_SUPPKEY)(x => x.L_SUPPKEY) { x =>
                    new Record { val N_NAME = x.N_NAME; val N_NATIONKEY = x.N_NATIONKEY }}) { x =>
                    new Record { val N_NAME      = x.left.N_NAME
                                 val N_NATIONKEY = x.left.N_NATIONKEY
                                 val O_CUSTKEY   = x.right.O_CUSTKEY
                                 val L_EXTENDEDPRICE  = x.right.L_EXTENDEDPRICE
                                 val L_DISCOUNT  = x.right.L_DISCOUNT
                               }}

                // customer  XX  (region X nation X supplier X orders X lineitems)  <--- match custkey, nationkey
                val jo5 = SelectOp(HashJoinOp1(scanCustomer, jo4)((x,y) => x.C_CUSTKEY == y.O_CUSTKEY)(x => x.C_CUSTKEY)(x => x.O_CUSTKEY){ x =>
                    new Record { val C_NATIONKEY = x.C_NATIONKEY }
                }){ x =>
                    x.left.C_NATIONKEY == x.right.N_NATIONKEY
                }

                val aggOp = AggOp1(jo5)(x => x.right.N_NAME)(new Record { val _0 = 0.0 })(
                    (t, currAgg) => new Record { val _0 = currAgg._0 + t.right.L_EXTENDEDPRICE * (1.0 - t.right.L_DISCOUNT) }
                )
                PrintOp(aggOp) { kv =>
                    printf("%.*s|%.4f\n",kv.key.length,kv.key,kv.aggs._0)
                }
/*

original plan:

    ((((region X nation) X supplier) X customer) X orders) X lineitems   -->   match suppkey

new plan:

    (customer X (((region X nation) X supplier) X (orders X lineitems)))
*/
        }
    }


    def Q5_VERSION_1 = {
        val lineitemTable = loadLineitem1()
        val nationTable = loadNation1()
        val customerTable = loadCustomer1()
        val supplierTable = loadSupplier1()
        val regionTable = loadRegion1()
        val ordersTable = loadOrders1()
        runQuery {
                val constantDate1 = parseDate("1996-01-01")
                val constantDate2 = parseDate("1997-01-01")
                val scanRegion = SelectOp(ScanOp2(regionTable))(x => x.R_NAME == parseString("ASIA"))
                val scanNation = ScanOp2(nationTable)
                val scanSupplier = ScanOp2(supplierTable)
                val scanCustomer = ScanOp2(customerTable)
                val scanLineitem = ScanOp2(lineitemTable)
                val scanOrders = SelectOp(ScanOp2(ordersTable))(x => x.O_ORDERDATE >= constantDate1 && x.O_ORDERDATE < constantDate2)
                /*--*/
                val jo1 = MapOp1(HashJoinOp1(scanRegion, scanNation)((x,y) => x.R_REGIONKEY == y.N_REGIONKEY)(x => x.R_REGIONKEY)(x => x.N_REGIONKEY) { x =>
                    new Record { val dummy = 7 }}) { x =>
                    new Record { val N_NATIONKEY = x.right.N_NATIONKEY; val N_NAME = x.right.N_NAME }}

                val jo2 = MapOp1(HashJoinOp1(jo1, scanSupplier)((x,y) => x.N_NATIONKEY == y.S_NATIONKEY)(x => x.N_NATIONKEY)(x => x.S_NATIONKEY) { x =>
                    new Record { val N_NAME = x.N_NAME }}) { x =>
                    new Record { val N_NAME = x.left.N_NAME; val S_SUPPKEY = x.right.S_SUPPKEY; val S_NATIONKEY = x.right.S_NATIONKEY }}

                val jo3 = MapOp1(HashJoinOp1(jo2, scanCustomer)((x,y) => x.S_NATIONKEY == y.C_NATIONKEY)(x => x.S_NATIONKEY)(x => x.C_NATIONKEY) { x =>
                    new Record { val N_NAME = x.N_NAME; val S_SUPPKEY = x.S_SUPPKEY }}) { x =>
                    new Record { val N_NAME = x.left.N_NAME; val S_SUPPKEY = x.left.S_SUPPKEY; val C_CUSTKEY = x.right.C_CUSTKEY }}

                val jo4 = MapOp1(HashJoinOp1(jo3, scanOrders)((x,y) => x.C_CUSTKEY == y.O_CUSTKEY)(x => x.C_CUSTKEY)(x => x.O_CUSTKEY) { x =>
                    new Record { val N_NAME = x.N_NAME; val S_SUPPKEY = x.S_SUPPKEY }}) { x =>
                    new Record { val N_NAME = x.left.N_NAME; val S_SUPPKEY = x.left.S_SUPPKEY; val O_ORDERKEY = x.right.O_ORDERKEY }}

                val jo5 = SelectOp(
                            HashJoinOp1(jo4, scanLineitem)((x,y) => x.O_ORDERKEY == y.L_ORDERKEY)(x => x.O_ORDERKEY)(x => x.L_ORDERKEY){x=>
                                    new Record { val N_NAME = x.N_NAME; val S_SUPPKEY = x.S_SUPPKEY }
                                })(x =>
                                x.left.S_SUPPKEY == x.right.L_SUPPKEY)

                val aggOp = AggOp1(jo5)(x => x.left.N_NAME)(new Record { val _0 = 0.0 })(
                    (t, currAgg) => new Record { val _0 = currAgg._0 + t.right.L_EXTENDEDPRICE * (1.0 - t.right.L_DISCOUNT) }
                )
                PrintOp(aggOp) { kv =>
                    printf("%.*s|%.4f\n",kv.key.length,kv.key,kv.aggs._0)
                }
        }
    }

    def Q6 = {
        val lineitemTable = loadLineitem1()
        runQuery {
                val constantDate1: Long = parseDate("1994-01-01")
                val constantDate2: Long = parseDate("1995-01-01")
                val lineitemScan = SelectOp(ScanOp2(lineitemTable))(x => x.L_SHIPDATE >= constantDate1 && x.L_SHIPDATE < constantDate2 && x.L_DISCOUNT >= 0.05 && x.L_DISCOUNT <= 0.07 && x.L_QUANTITY < 24)
                val aggOp = AggOp1(lineitemScan)(x => "Total")(zero1)((t,currAgg) => new Record{val _0 = (t.L_EXTENDEDPRICE * t.L_DISCOUNT) + currAgg._0})
                val po = PrintOp(aggOp)(kv => printf("%.4f\n",kv.aggs._0))
                po
        }
    }

    def Q7 = {
        val nationTable = loadNation1()
        val ordersTable = loadOrders1()
        val lineitemTable = loadLineitem1()
        val customerTable = loadCustomer1()
        val supplierTable = loadSupplier1()
        runQuery {
                val usa = parseString("FRANCE")
                val indonesia = parseString("GERMANY")
                val scanNation1 = MapOp1(ScanOp2(nationTable)){ x => new Record {
                    val N1_N_NATIONKEY = x.N_NATIONKEY
                    val N1_N_NAME      = x.N_NAME
                    val N1_N_REGIONKEY = x.N_REGIONKEY
                    val N1_N_COMMENT   = x.N_COMMENT
                }}
                val scanNation2 = MapOp1(ScanOp2(nationTable)){ x => new Record {
                    val N2_N_NATIONKEY = x.N_NATIONKEY
                    val N2_N_NAME      = x.N_NAME
                    val N2_N_REGIONKEY = x.N_REGIONKEY
                    val N2_N_COMMENT   = x.N_COMMENT
                }}
                val jo1 = MapCatOp(NestedLoopsJoinOp(scanNation1, scanNation2)((x,y) => ( (x.N1_N_NAME == usa && y.N2_N_NAME == indonesia) || (x.N1_N_NAME == indonesia && y.N2_N_NAME == usa))))
                val scanSupplier = ScanOp2(supplierTable)
                val jo2 = MapCatOp(HashJoinOp2(jo1, scanSupplier)((x,y) => x.f.N1_N_NATIONKEY == y.S_NATIONKEY)(x => x.f.N1_N_NATIONKEY)(x => x.S_NATIONKEY))
                val scanLineitem = SelectOp(ScanOp2(lineitemTable))(x => x.L_SHIPDATE >= parseDate("1995-01-01") && x.L_SHIPDATE <= parseDate("1996-12-31"))
                val jo3 = MapCatOp(HashJoinOp2(jo2, scanLineitem)((x,y) => x.f.S_SUPPKEY == y.L_SUPPKEY)(x => x.f.S_SUPPKEY)(x => x.L_SUPPKEY))
                val scanOrders = ScanOp2(ordersTable)
                val jo4 = MapCatOp(HashJoinOp2(jo3, scanOrders)((x,y) => x.f.L_ORDERKEY == y.O_ORDERKEY)(x => x.f.L_ORDERKEY)(x => x.O_ORDERKEY))
                val scanCustomer = ScanOp2(customerTable)
                val jo5 = MapCatOp(HashJoinOp2(scanCustomer, jo4)((x,y) => x.C_CUSTKEY == y.f.O_CUSTKEY && x.C_NATIONKEY == y.f.N2_N_NATIONKEY)(x => x.C_CUSTKEY)(x => x.f.O_CUSTKEY))
                val gb = AggOp1(jo5)( x => new Record {
                    val SUPP_NATION = x[LegoString]("N1_N_NAME")
                    val CUST_NATION = x[LegoString]("N2_N_NAME")
                    val L_YEAR = newDate(x[Long]("L_SHIPDATE")).getYear.toInt
                })(zero1)( (t, currAgg) => new Record { val _0 = currAgg._0 + t.f.L_EXTENDEDPRICE * (1.0 - t[Double]("L_DISCOUNT")) } )
                val so = SortOp(gb)((kv1,kv2) => {
                    val k1 = kv1.key; val k2 = kv2.key
                    val r1 = k1.SUPP_NATION compareTo k2.SUPP_NATION
                    if (r1 != 0) r1
                    else {
                        val r2 = k1.CUST_NATION compareTo k2.CUST_NATION
                        if (r2 != 0) r2
                        else {
                            if (k1.L_YEAR < k2.L_YEAR) -1
                            else if (k1.L_YEAR > k2.L_YEAR) 1
                            else 0
                        }
                    }
                })
                val po = PrintOp(so)(kv => printf("%.*s|%.*s|%d|%.4f\n",
                    kv.key.SUPP_NATION.length,kv.key.SUPP_NATION,kv.key.CUST_NATION.length,kv.key.CUST_NATION,
                    kv.key.L_YEAR,kv.aggs._0))
                po
        }
    }

    def Q8 = {
        val nationTable = loadNation1()
        val regionTable = loadRegion1()
        val partTable = loadPart1()
        val ordersTable = loadOrders1()
        val lineitemTable = loadLineitem1()
        val customerTable = loadCustomer1()
        val supplierTable = loadSupplier1()
        runQuery {
                val constantDate1 = parseDate("1995-01-01")
                val constantDate2 = parseDate("1996-12-31")
                val asia = parseString("AMERICA")
                val indonesia = parseString("BRAZIL")
                val medAnonNick = parseString("ECONOMY ANODIZED STEEL")
                val scanLineitem = ScanOp2(lineitemTable)
                val scanPart = SelectOp(ScanOp2(partTable))(x => x.P_TYPE == medAnonNick)
                val jo1 = MapCatOp(HashJoinOp2(scanPart, scanLineitem)((x,y) => x.P_PARTKEY == y.L_PARTKEY)(x => x.P_PARTKEY)(x => x.L_PARTKEY))
                val scanOrders = SelectOp(ScanOp2(ordersTable))(x => x.O_ORDERDATE >= constantDate1 && x.O_ORDERDATE <= constantDate2)
                val jo2 = MapCatOp(HashJoinOp2(jo1, scanOrders)((x,y) => x.f.L_ORDERKEY == y.O_ORDERKEY)(x => x.f.L_ORDERKEY)(x => x.O_ORDERKEY))
                val scanCustomer = ScanOp2(customerTable)
                val jo3 = MapCatOp(HashJoinOp2(jo2, scanCustomer)((x,y) => x.f.O_CUSTKEY == y.C_CUSTKEY)(x => x.f.O_CUSTKEY)(x => x.C_CUSTKEY))
                val scanNation1 = ScanOp2(nationTable)
                val jo4 = MapCatOp(HashJoinOp2(scanNation1, jo3)((x,y) => x.N_NATIONKEY == y.f.C_NATIONKEY)(x => x.N_NATIONKEY)(x => x.f.C_NATIONKEY))
                val scanRegion = SelectOp(ScanOp2(regionTable))(x => x.R_NAME == asia)
                val jo5 = MapCatOp(HashJoinOp2(scanRegion, jo4)((x,y) => x.R_REGIONKEY == y.f.N_REGIONKEY)(x => x.R_REGIONKEY)(x => x.f.N_REGIONKEY))
                val scanSupplier = ScanOp2(supplierTable)
                val jo6 = MapOp1(MapCatOp(HashJoinOp2(scanSupplier, jo5)((x,y) => x.S_SUPPKEY == y.f.L_SUPPKEY)(x => x.S_SUPPKEY)(x => x.f.L_SUPPKEY))) { x => new Record {
                    val REC2_O_ORDERDATE     = x[Long]("O_ORDERDATE")
                    val REC2_L_DISCOUNT      = x[Double]("L_DISCOUNT")
                    val REC2_L_EXTENDEDPRICE = x[Double]("L_EXTENDEDPRICE")
                    val REC2_S_NATIONKEY     = x[Int]("S_NATIONKEY")
                }}
                val scanNation2 = MapOp1(ScanOp2(nationTable)) { x => new Record {
                    val REC1_N_NAME          = x.N_NAME
                    val REC1_N_NATIONKEY     = x.N_NATIONKEY
                }}
                val jo7 = MapCatOp(HashJoinOp2(scanNation2, jo6, "REC1_","REC2_")((x,y) => x.REC1_N_NATIONKEY == y.f.REC2_S_NATIONKEY)(x => x.REC1_N_NATIONKEY)(x => x.f.REC2_S_NATIONKEY))
                val aggOp = AggOp1(jo7)(x => newDate(x[Long]("REC2_O_ORDERDATE")).getYear.toInt)(zero2)(
                    (t, currAgg) => new Record {
                        val _0 = { currAgg._0 + t.f.REC2_L_EXTENDEDPRICE * (1.0 - t[Double]("REC2_L_DISCOUNT")) }
                        val _1 = { if (t.f.REC1_N_NAME == indonesia) currAgg._1 + t.f.REC2_L_EXTENDEDPRICE * (1.0 - t[Double]("REC2_L_DISCOUNT"))
                                   else currAgg._1 }
                    }
                )
                val mapOp = MapOp1(aggOp)(x => new Record { val key = x.key; val aggs = new Record { val _2 = x.aggs._1 / x.aggs._0 }})
                val sortOp = SortOp(mapOp)((x,y) => {
                    if (x.key < y.key) -1
                    else if (x.key > y.key) 1
                    else 0
                })
                val po = PrintOp(sortOp)(kv => printf("%d|%.5f\n",kv.key,kv.aggs._2))
                po
        }
    }

    def Q9 = {
        val partTable = loadPart1()
        val nationTable = loadNation1()
        val ordersTable = loadOrders1()
        val partsuppTable = loadPartsupp1()
        val supplierTable = loadSupplier1()
        val lineitemTable = loadLineitem1()
        runQuery {
                val ghost = parseString("green")
                val soNation = ScanOp2(nationTable)
                val soSupplier = ScanOp2(supplierTable)
                val soLineitem = ScanOp2(lineitemTable)
                val soPart = SelectOp(ScanOp2(partTable))(x => x.P_NAME.containsSlice(ghost))
                val soPartsupp = ScanOp2(partsuppTable)
                val soOrders = ScanOp2(ordersTable)
                val hj1 = MapCatOp(HashJoinOp2(soNation, soSupplier)((x,y) => x.N_NATIONKEY == y.S_NATIONKEY)(x => x.N_NATIONKEY)(x => x.S_NATIONKEY))
                val hj2 = MapCatOp(HashJoinOp2(hj1, soLineitem)((x,y) => x.f.S_SUPPKEY == y.L_SUPPKEY)(x => x.f.S_SUPPKEY)(x => x.L_SUPPKEY))
                val hj3 = MapCatOp(HashJoinOp2(soPart, hj2)((x,y) => x.P_PARTKEY == y.f.L_PARTKEY)(x => x.P_PARTKEY)(x => x.f.L_PARTKEY))
                val hj4 = MapCatOp(HashJoinOp2(soPartsupp, hj3)((x,y) => x.PS_PARTKEY == y.f.L_PARTKEY && x.PS_SUPPKEY == y.f.L_SUPPKEY)(x => x.PS_PARTKEY)(x => x.f.L_PARTKEY))
                val hj5 = MapCatOp(HashJoinOp2(hj4, soOrders)((x,y) => x.f.L_ORDERKEY == y.O_ORDERKEY)(x => x.f.L_ORDERKEY)(x => x.O_ORDERKEY))
                val aggOp = AggOp1(hj5)(x => new Record {
                    val NATION = x[LegoString]("N_NAME")
                    val O_YEAR = newDate(x[Long]("O_ORDERDATE")).getYear.toInt
                })(zero1)(
                    (t,currAgg) => new Record { val _0 = currAgg._0 + ((t.f.L_EXTENDEDPRICE * (1.0 - t[Double]("L_DISCOUNT"))) - (1.0 * t[Double]("PS_SUPPLYCOST") * t.f.L_QUANTITY)) }
                )
                val sortOp = SortOp(aggOp)((kv1,kv2) => {
                    val k1 = kv1.key; val k2 = kv2.key
                    val r = k1.NATION compareTo k2.NATION
                    if (r == 0) {
                        if (k1.O_YEAR < k2.O_YEAR) 1
                        else if (k1.O_YEAR > k2.O_YEAR) -1
                        else 0
                    } else r
                })
                val po = PrintOp(sortOp)(kv => printf("%.*s|%d|%.4f\n",kv.key.NATION.length,kv.key.NATION,kv.key.O_YEAR,kv.aggs._0))
                po
        }
    }

    def Q10 = {
        val lineitemTable = loadLineitem1()
        val nationTable = loadNation1()
        val customerTable = loadCustomer1()
        val ordersTable = loadOrders1()
        runQuery {
                val constantDate1 = parseDate("1993-10-01")
                val constantDate2 = parseDate("1994-01-01")
                val so1 = SelectOp(ScanOp2(ordersTable))(x => x.O_ORDERDATE >= constantDate1 && x.O_ORDERDATE < constantDate2)
                val so2 = ScanOp2(customerTable)
                val hj1 = MapCatOp(HashJoinOp2(so1,so2)((x,y) => x.O_CUSTKEY == y.C_CUSTKEY)(x => x.O_CUSTKEY)(x => x.C_CUSTKEY))
                val so3 = ScanOp2(nationTable)
                val hj2 = MapCatOp(HashJoinOp2(so3,hj1)((x,y) => x.N_NATIONKEY == y.f.C_NATIONKEY)(x => x.N_NATIONKEY)(x => x.f.C_NATIONKEY))
                val so4 = SelectOp(ScanOp2(lineitemTable))(x => x.L_RETURNFLAG == 'R')
                val hj3 = MapCatOp(HashJoinOp2(hj2,so4)((x,y) => x.f.O_ORDERKEY == y.L_ORDERKEY)(x => x.f.O_ORDERKEY)(x => x.L_ORDERKEY))
                val aggOp = AggOp1(hj3)(x => new Record {
                    val C_CUSTKEY = x[Int]("C_CUSTKEY")
                    val C_NAME = x[LegoString]("C_NAME")
                    val C_ACCTBAL = x[Double]("C_ACCTBAL")
                    val C_PHONE = x[LegoString]("C_PHONE")
                    val N_NAME = x[LegoString]("N_NAME")
                    val C_ADDRESS = x[LegoString]("C_ADDRESS")
                    val C_COMMENT = x[LegoString]("C_COMMENT")
                })(zero1)((t,currAgg) => new Record { val _0 = currAgg._0 + (t[Double]("L_EXTENDEDPRICE") * (1.0-t[Double]("L_DISCOUNT"))).asInstanceOf[Rep[Double]]})
                val sortOp = SortOp(aggOp)((kv1,kv2) => {
                    val k1 = kv1.aggs._0; val k2 = kv2.aggs._0
                    if (k1 < k2) 1
                    else if (k1 > k2) -1
                    else 0
                })
                // LIMIT 20 -- SORT BOTTLENECK?
                var j = 0
                val po = PrintOp(sortOp)(kv => {
                    printf("%d|%.*s|%.4f|%.2f|%.*s|%.*s|%.*s|%.*s\n",kv.key.C_CUSTKEY,kv.key.C_NAME.length,(kv.key.C_NAME),kv.aggs._0,
                                kv.key.C_ACCTBAL,kv.key.N_NAME.length,(kv.key.N_NAME),kv.key.C_ADDRESS.length,(kv.key.C_ADDRESS),
                                kv.key.C_PHONE.length,(kv.key.C_PHONE),
                                kv.key.C_COMMENT.length,(kv.key.C_COMMENT))
                    j+=1
                }, () => j < 20)
                po
        }
    }

    def Q11 = {
        val partsuppTable = loadPartsupp1()
        val supplierTable = loadSupplier1()
        val nationTable = loadNation1()
        runQuery {
                val uk = parseString("GERMANY")
                val scanSupplier = ScanOp2(supplierTable)
                val scanNation   = SelectOp(ScanOp2(nationTable))(x => x.N_NAME == uk)
                val jo1 = MapCatOp(HashJoinOp2[NATIONRecord,SUPPLIERRecord,Int](scanNation, scanSupplier)((x,y) => x.N_NATIONKEY == y.S_NATIONKEY)(x => x.N_NATIONKEY)(y => y.S_NATIONKEY))
                val scanPartsupp = ScanOp2(partsuppTable)
                val jo2 = MapCatOp(HashJoinOp2[CompositeRecord[NATIONRecord,SUPPLIERRecord],PARTSUPPRecord,Int](jo1, scanPartsupp)((x,y) => x.f.S_SUPPKEY == y.PS_SUPPKEY)(x => x.f.S_SUPPKEY)(x => x.PS_SUPPKEY))
                val wo = AggOp1[CompositeRecord[CompositeRecord[NATIONRecord,SUPPLIERRecord],PARTSUPPRecord], Int, Record {val _0: Double}](jo2)(x => x[Int]("PS_PARTKEY"))(zero1)((e, cnt) =>
                    new Record { val _0 = cnt._0 + (e[Double]("PS_SUPPLYCOST") * e.f.PS_AVAILQTY) }
                )

                val vo = ViewOp(wo,2)
                // Calculate total sum
                val total = MapOp1(AggOp1(vo.sub(0))(x => "Total")(zero1)( (t,cnt) => new Record { val _0 = cnt._0 + t.aggs._0 } ))(x => new Record { val total = x.aggs._0 * 0.0001 })
                // Calculate final result
                val nl = MapOp1(NestedLoopsJoinOp(total,vo.sub(1))((x,y) => y.aggs._0 > x.total))(x => new Record { val key = x.right.key; val wnd = x.right.aggs._0 })
                val sortOp = SortOp(nl)((x,y) => {
                    if (x.wnd > y.wnd) -1
                    else if (x.wnd < y.wnd) 1
                    else 0
                })
                val po = PrintOp(sortOp)(kv => printf("%d|%.2f\n",kv.key,kv.wnd))
                po
        }
    }

    def Q12 = {
        val lineitemTable = loadLineitem1()
        val ordersTable = loadOrders1()
        runQuery {
                val mail = parseString("MAIL")
                val ship = parseString("SHIP")
                val constantDate = parseDate("1995-01-01")
                val constantDate2 = parseDate("1994-01-01")
                val so1 = ScanOp2(ordersTable)
                val so2 = SelectOp(ScanOp2(lineitemTable))(x =>
                    x.L_RECEIPTDATE < constantDate && x.L_COMMITDATE < constantDate && x.L_SHIPDATE < constantDate && x.L_SHIPDATE < x.L_COMMITDATE && x.L_COMMITDATE < x.L_RECEIPTDATE && x.L_RECEIPTDATE >= constantDate2 && (x.L_SHIPMODE == mail || x.L_SHIPMODE == ship)
                )
                val jo = MapCatOp(HashJoinOp2(so1, so2)( (x,y) => x.O_ORDERKEY == y.L_ORDERKEY )(x => x.O_ORDERKEY)(x => x.L_ORDERKEY))
                val URGENT = parseString("1-URGENT")
                val HIGH = parseString("2-HIGH")
                val aggOp = AggOp1(jo)(x => x[LegoString]("L_SHIPMODE"))(zero2)(
                    (t,currAgg) => new Record {
                        val _0 = { if (infix_||(t.f.O_ORDERPRIORITY == URGENT , t.f.O_ORDERPRIORITY == HIGH)) currAgg._0 + 1 else currAgg._0 }
                        val _1 = { if (infix_&&(t.f.O_ORDERPRIORITY != URGENT , t.f.O_ORDERPRIORITY != HIGH)) currAgg._1 + 1 else currAgg._1 }
                    }
                )
                val sortOp = SortOp(aggOp)((x,y) => x.key compareTo y.key)
                val po = PrintOp(sortOp)(kv => printf("%.*s|%.0f|%.0f\n",kv.key.length,(kv.key),kv.aggs._0,kv.aggs._1))
                po
        }
    }

    def Q13 = {
        val customerTable = loadCustomer1()
        val ordersTable = loadOrders1()
        runQuery {
                val unusual = parseString("special")
                val packages = parseString("requests")
                val scanCustomer = ScanOp2(customerTable)
                val scanOrders = SelectOp(ScanOp2(ordersTable))(x => {
                    val idxu = x.O_COMMENT.indexOfSlice(unusual, 0)
                    if (idxu >= 0) {
                      val idxp = x.O_COMMENT.indexOfSlice(packages, idxu + 7)
                      idxp == -1
                    } else {
                      true
                    }
                })
                val jo = MapCatOp(LeftOuterJoinOp1(scanCustomer, scanOrders)((x,y) => x.C_CUSTKEY == y.O_CUSTKEY)(x => x.C_CUSTKEY)(x => x.O_CUSTKEY))
                val aggOp1 = AggOp1(jo)(x => x[Int]("C_CUSTKEY"))(zero1)(
                    (t, currAgg) => new Record { val _0 = if (t.f.O_ORDERKEY != 0.0) currAgg._0 + 1 else currAgg._0 }
                )
                val aggOp2 = AggOp1(aggOp1)(x => x.aggs._0)(zero1)(
                    (t, currAgg) => new Record { val _0 = currAgg._0 + 1 }
                )
                val sortOp = SortOp(aggOp2)( (x,y) => {
                    if (x.aggs._0 < y.aggs._0) 1
                    else if (x.aggs._0 > y.aggs._0) -1
                    else {
                        if (x.key < y.key) 1
                        else if (x.key > y.key) -1
                        else 0
                    }
                })
                val po = PrintOp(sortOp)(kv => printf("%.0f|%.0f\n",kv.key,kv.aggs._0))
                po
        }
    }

    def Q14 = {
        val lineitemTable = loadLineitem1()
        val partTable = loadPart1()
        runQuery {
                val promo = parseString("PROMO")
                val constantDate = parseDate("1995-10-01")
                val constantDate2 = parseDate("1995-09-01")
                val so1 = ScanOp2(partTable)
                val so2 = SelectOp(ScanOp2(lineitemTable))(x => x.L_SHIPDATE >= constantDate2 && x.L_SHIPDATE < constantDate)
                val jo = MapCatOp(HashJoinOp2(so1, so2)( (x,y) => x.P_PARTKEY == y.L_PARTKEY )(x => x.P_PARTKEY)(x => x.L_PARTKEY))
                val aggOp = AggOp1(jo)(x => "Total")(zero2)(
                        (t,currAgg) => new Record {
                            val _0 = { if (string_startswith(t[LegoString]("P_TYPE") , promo))
                                         currAgg._0 + (t.f.L_EXTENDEDPRICE * (1.0 - t[Double]("L_DISCOUNT")))
                                       else currAgg._0 }
                            val _1 =  { currAgg._1 + (t.f.L_EXTENDEDPRICE * (1.0 - t[Double]("L_DISCOUNT"))) }
                })
                val mapOp = MapOp1(aggOp)(kv => (kv.aggs._0 * 100) / kv.aggs._1)
                val po = PrintOp(mapOp)(kv => printf("%.4f\n",kv))
                po
        }
    }

    def Q15 = {
        val lineitemTable = loadLineitem1()
        val supplierTable = loadSupplier1()
        runQuery {
                val constantDate = parseDate("1996-01-01")
                val constantDate2 = parseDate("1996-04-01")
                val scanLineitem = SelectOp(ScanOp2(lineitemTable))(x => x.L_SHIPDATE >= constantDate && x.L_SHIPDATE < constantDate2)
                val aggOp1 = AggOp1(scanLineitem)(x => x.L_SUPPKEY)(zero1)(
                    (t, currAgg) => new Record { val _0 = currAgg._0 + (t.L_EXTENDEDPRICE * (1.0 - t.L_DISCOUNT)) }
                )
                // Create view
                val vo = ViewOp(aggOp1,2)
                // Get max
                val aggOp2 = AggOp1(vo.sub(0))(x => "MAXREVENUE")(zero1)(
                    (t, currAgg) => new Record { val _0 = if (currAgg._0 < t.aggs._0) t.aggs._0 else currAgg._0 }
                )

                val maxRevenue = MapOp1(aggOp2)(x => new Record { val total = x.aggs._0 })

                val nl = MapOp1(NestedLoopsJoinOp(maxRevenue,vo.sub(1))((x,y) => y.aggs._0 == x.total))(x => new Record { val key = x.right.key; val aggs = x.right.aggs })

                // Calcuate result
                val scanSupplier = ScanOp2(supplierTable)
                val jo = MapCatOp(HashJoinOp2(scanSupplier, nl)((x,y) => x.S_SUPPKEY == y.key)(x => x.S_SUPPKEY)(x => x.key))
                val po = PrintOp(jo)(kv => printf("%d|%.*s|%.*s|%.*s|%.4f\n", kv.f.S_SUPPKEY,
                    kv.f.S_NAME.length,(kv.f.S_NAME),kv.f.S_ADDRESS.length,(kv.f.S_ADDRESS),kv.f.S_PHONE.length,(kv.f.S_PHONE),
                    kv.f.aggs.f._0:Rep[Double]))
                po
        }
    }

    def Q16 = {
        val supplierTable = loadSupplier1()
        val partTable = loadPart1()
        val partsuppTable = loadPartsupp1()
        runQuery {
                val str1 = parseString("Customer")
                val str2 = parseString("Complaints")
                val brand21 = parseString("Brand#45")
                val promoPlated = parseString("MEDIUM POLISHED")
                val partScan = SelectOp(ScanOp2(partTable))(x => x.P_BRAND != brand21 && !(x.P_TYPE startsWith promoPlated) &&
                                                                 (x.P_SIZE==49 || x.P_SIZE==14 || x.P_SIZE==23 || x.P_SIZE==45 ||
                                                                  x.P_SIZE==19 || x.P_SIZE==3 || x.P_SIZE==36 || x.P_SIZE==9))
                val partsuppScan = ScanOp2(partsuppTable)
                val jo1 = MapCatOp(HashJoinOp2(partScan, partsuppScan)((x,y) => x.P_PARTKEY == y.PS_PARTKEY)(x => x.P_PARTKEY)(x => x.PS_PARTKEY))
                val supplierScan = SelectOp(ScanOp2(supplierTable))(x => {
                    val idxu = x.S_COMMENT.indexOfSlice(str1, 0)
                    if (idxu != -1) {
                      val idxp = x.S_COMMENT.indexOfSlice(str2, idxu + 8)
                      idxp != -1
                    } else {
                      false
                    }
                })
                val jo2 = HashJoinAnti1(jo1, supplierScan)((x,y) => x[Int]("PS_SUPPKEY") == y[Int]("S_SUPPKEY"))(x => x[Int]("PS_SUPPKEY"))(x => x[Int]("S_SUPPKEY"))
                val aggOp = AggOp1(jo2)(x => new Record {
                    val P_BRAND = x[LegoString]("P_BRAND")
                    val P_TYPE  = x[LegoString]("P_TYPE")
                    val P_SIZE  = x[Int]("P_SIZE")
                    val PS_SUPPKEY = x[Int]("PS_SUPPKEY")
                })(zero1)((t,currAgg) => currAgg)
                val aggOp2 = AggOp1(aggOp)(x => new Record {
                    val P_BRAND = x.key.P_BRAND
                    val P_TYPE  = x.key.P_TYPE
                    val P_SIZE  = x.key.P_SIZE
                })(zero1)(
                  (t,currAgg) => new Record { val _0 = currAgg._0 + 1 }
                )
                val sortOp = SortOp(aggOp2)((x,y) => {
                    if (x.aggs._0 < y.aggs._0) 1
                    else if (x.aggs._0 > y.aggs._0) -1
                    else {
                        var res = x.key.P_BRAND compareTo y.key.P_BRAND
                        if (res == 0) {
                            res = x.key.P_TYPE compareTo y.key.P_TYPE
                            if (res == 0) res = x.key.P_SIZE - y.key.P_SIZE
                        }
                        res
                    }
                })
                var j = 0
                val po = PrintOp(sortOp)(x => {
                  printf("%.*s|%.*s|%d|%.0f\n",
                    x.key.P_BRAND.length,(x.key.P_BRAND),x.key.P_TYPE.length,(x.key.P_TYPE),
                    x.key.P_SIZE,x.aggs._0)
                  j += 1
                }, () => j < 20)
                po
        }
    }

    def Q17 = {
        val lineitemTable = loadLineitem1()
        val partTable = loadPart1()
        runQuery {
                val medbag = parseString("MED BOX")
                val brand15 = parseString("Brand#23")
                val scanLineitem = ScanOp2(lineitemTable)
                val scanPart = SelectOp(ScanOp2(partTable))(x => x.P_CONTAINER == medbag && x.P_BRAND == brand15)
                val jo = MapCatOp(HashJoinOp2(scanPart, scanLineitem)( (x,y) => x.P_PARTKEY == y.L_PARTKEY )(x => x.P_PARTKEY)(x => x.L_PARTKEY))
                // XXX: It seems like here window is more appropriate than Agg + View?
                val wo = WindowOp(jo)(x => x[Int]("L_PARTKEY"))(x => {
                    val sum = x.foldLeft(0.0)((cnt,e) => cnt + e[Double]("L_QUANTITY"))
                    val count = x.size
                    val avg = 0.2 * (sum / count)
                    x.foldLeft(0.0)((cnt,e) => {
                        if (e[Double]("L_QUANTITY") < avg) cnt + e[Double]("L_EXTENDEDPRICE")
                        else cnt
                    }) / 7.0
                })
                val aggOp = AggOp1(wo)(x => "Total")(0.0)((t, currAgg) => currAgg + t.wnd / 7.0)
                val po = PrintOp(aggOp)(kv => printf("%.6f\n",kv.aggs))
                po
        }
    }

    def Q18 = {
        val lineitemTable = loadLineitem1()
        val ordersTable = loadOrders1()
        val customerTable = loadCustomer1()
        runQuery {
                val scanOrders = ScanOp2(ordersTable)
                val scanCustomer = ScanOp2(customerTable)
                // Group aggregation on Lineitem
                val scanLineitem1 = ScanOp2(lineitemTable)
                val aggOp1 = SelectOp(AggOp1(scanLineitem1)(x => x.L_ORDERKEY)(zero1)(
                        (t,currAgg) => new Record { val _0 = currAgg._0 + t.L_QUANTITY }
                ))(x => x.aggs._0 > 300)
                // Hash Join with orders
                val jo1 = MapCatOp(HashJoinOp2(aggOp1, scanOrders)( (x,y) => y.O_ORDERKEY == x.key )(x => x[Double]("key"))(x => x.O_ORDERKEY))
                val jo2 = MapCatOp(HashJoinOp2(jo1, scanCustomer)( (x,y) => x.f.O_CUSTKEY == y.C_CUSTKEY)(x => x.f.O_CUSTKEY)(x => x.C_CUSTKEY))
                val aggOp2 = AggOp1(jo2)(x => new Record {
                    val C_NAME = x[LegoString]("C_NAME")
                    val C_CUSTKEY = x[Int]("C_CUSTKEY")
                    val O_ORDERKEY = x[Int]("O_ORDERKEY")
                    val O_ORDERDATE = x[Long]("O_ORDERDATE")
                    val O_TOTALPRICE = x[Double]("O_TOTALPRICE")
                })(zero1)(
                    (t,currAgg) => new Record { val _0 = currAgg._0 + t.f.aggs.f._0: Rep[Double] } // aggs(0) => L_QUANTITY"
                )
                val sortOp = SortOp(aggOp2)((kv1,kv2) => {
                    val k1 = kv1.key.O_TOTALPRICE; val k2 = kv2.key.O_TOTALPRICE
                    if (k1 < k2) 1
                    else if (k1 > k2) -1
                    else {
                        val d1 = kv1.key.O_ORDERDATE; val d2 = kv2.key.O_ORDERDATE;
                        if (d1 < d2) -1
                        else if (d1 > d2) 1
                        else 0
                    }
                })
                // LIMIT 100 -- SORT BOTTLENECK?
                var j = 0
                val po = PrintOp(sortOp)(kv => {
                    printf("%.*s|%d|%d|%s|%.2f|%.2f\n",
                        kv.key.C_NAME.length,(kv.key.C_NAME),
                        kv.key.C_CUSTKEY,kv.key.O_ORDERKEY,getDateAsString(kv.key.O_ORDERDATE),kv.key.O_TOTALPRICE,kv.aggs._0)
                    j+=1
                }, () => j < 100)
                po
        }
    }

    def Q19 = {
        val lineitemTable = loadLineitem1()
        val partTable = loadPart1()
        runQuery {
                val Brand12 = parseString("Brand#12")
                val Brand23 = parseString("Brand#23")
                val Brand34 = parseString("Brand#34")
                val SMBOX = parseString("SM BOX")
                val SMCASE = parseString("SM CASE")
                val SMPACK = parseString("SM PACK")
                val SMPKG = parseString("SM PKG")
                val MEDBAG = parseString("MED BAG")
                val MEDBOX = parseString("MED BOX")
                val MEDPACK = parseString("MED PACK")
                val MEDPKG = parseString("MED PKG")
                val LGBOX = parseString("LG BOX")
                val LGCASE = parseString("LG CASE")
                val LGPACK = parseString("LG PACK")
                val LGPKG = parseString("LG PKG")
                val DELIVERINPERSON = parseString("DELIVER IN PERSON")
                val AIR = parseString("AIR")
                val AIRREG = parseString("AIR REG")

                val so1 = SelectOp(ScanOp2(partTable))(x => x.P_SIZE >= 1 && (
                                (x.P_SIZE<=5 && x.P_BRAND==Brand12 && (x.P_CONTAINER==SMBOX  || x.P_CONTAINER==SMCASE ||
                                                                       x.P_CONTAINER==SMPACK || x.P_CONTAINER==SMPKG)) ||
                                (x.P_SIZE<=10 && x.P_BRAND==Brand23 && (x.P_CONTAINER==MEDBAG  || x.P_CONTAINER==MEDBOX ||
                                                                        x.P_CONTAINER==MEDPACK || x.P_CONTAINER==MEDPKG)) ||
                                (x.P_SIZE<=15 && x.P_BRAND==Brand34 && (x.P_CONTAINER==LGBOX  || x.P_CONTAINER==LGCASE ||
                                                                        x.P_CONTAINER==LGPACK || x.P_CONTAINER==LGPKG)))
                )
                 val so2 = SelectOp(ScanOp2(lineitemTable))(x =>
                                 ((x.L_QUANTITY<=30 && x.L_QUANTITY>=1) && x.L_SHIPINSTRUCT == DELIVERINPERSON &&
                                  (x.L_SHIPMODE==AIR || x.L_SHIPMODE==AIRREG))
                 )
                 val jo = SelectOp(MapCatOp(HashJoinOp2(so1, so2)((x,y) => x.P_PARTKEY == y.L_PARTKEY)(x => x.P_PARTKEY)(x => x.L_PARTKEY)))(
                     x => ((x.f.P_BRAND == Brand12 &&
                          (x.f.P_CONTAINER==SMBOX || x.f.P_CONTAINER==SMCASE || x.f.P_CONTAINER==SMPACK || x.f.P_CONTAINER==SMPKG) &&
                           x[Double]("L_QUANTITY")>=1 && x[Double]("L_QUANTITY")<=11 && x[Int]("P_SIZE")<=5) || (x.f.P_BRAND==Brand23 &&
                          (x.f.P_CONTAINER==MEDBAG || x.f.P_CONTAINER==MEDBOX || x.f.P_CONTAINER==MEDPACK || x.f.P_CONTAINER==MEDPKG) &&
                           x[Double]("L_QUANTITY")>=10 && x[Double]("L_QUANTITY")<=20 && x[Int]("P_SIZE")<=10) || (x.f.P_BRAND==Brand34 &&
                          (x.f.P_CONTAINER==LGBOX || x.f.P_CONTAINER==LGCASE || x.f.P_CONTAINER==LGPACK || x.f.P_CONTAINER==LGPKG) &&
                           x[Double]("L_QUANTITY")>=20 && x[Double]("L_QUANTITY")<=30 && x[Int]("P_SIZE")<=15))
                 )
                 val aggOp = AggOp1(jo)(x => "Total")(0.0)(
                     (t,currAgg) => { currAgg + (t[Double]("L_EXTENDEDPRICE") * (1.0 - t.f.L_DISCOUNT)) }
                 )
                 val po = PrintOp(aggOp)(kv => printf("%.4f\n",kv.aggs))
                po
        }
    }

   def Q20 = {
        val partTable = loadPart1()
        val nationTable = loadNation1()
        val supplierTable = loadSupplier1()
        val partsuppTable = loadPartsupp1()
        val lineitemTable = loadLineitem1()
        runQuery {
                val constantDate1 = parseDate("1994-01-01")
                val constantDate2 = parseDate("1995-01-01")
                val jordan = parseString("CANADA")
                val azure  = parseString("forest")
                val scanPart = SelectOp(ScanOp2(partTable))(x => x.P_NAME startsWith azure)
                val scanPartsupp = ScanOp2(partsuppTable)
                val jo1 = LeftHashSemiJoinOp1(scanPartsupp, scanPart)((x,y) => y.P_PARTKEY == x.PS_PARTKEY)(x=>x.PS_PARTKEY)(x=>x.P_PARTKEY)
                val scanLineitem = SelectOp(ScanOp2(lineitemTable))(x => x.L_SHIPDATE >= constantDate1 && x.L_SHIPDATE < constantDate2)
                val jo2 = MapCatOp(HashJoinOp2(jo1, scanLineitem)((x,y) => x.f.PS_PARTKEY == y.L_PARTKEY && x.f.PS_SUPPKEY == y.L_SUPPKEY)(x=>x.f.PS_PARTKEY)(x=>x.L_PARTKEY))
                val aggOp = AggOp1(jo2)(x => new Record {
                    val PS_PARTKEY = x[Int]("PS_PARTKEY")
                    val PS_SUPPKEY = x[Int]("PS_SUPPKEY")
                    val PS_AVAILQTY = x[Double]("PS_AVAILQTY")
                })(0.0)((t,currAgg) => { currAgg + t[Double]("L_QUANTITY") })
                val selOp = SelectOp(aggOp)(x => x.key.PS_AVAILQTY > 0.5 * x.aggs)
                val scanSupplier = ScanOp2(supplierTable)
                val scanNation = SelectOp(ScanOp2(nationTable))(x => x.N_NAME == jordan)
                val jo3 = MapCatOp(HashJoinOp2(scanNation, scanSupplier)((x,y) => x.N_NATIONKEY == y.S_NATIONKEY)(x => x.N_NATIONKEY)(x => x.S_NATIONKEY))
                val jo4 = LeftHashSemiJoinOp1(jo3, selOp)((x,y) => x.f.S_SUPPKEY == y.key.PS_SUPPKEY)(x => x.f.S_SUPPKEY)(x => x.key.PS_SUPPKEY)
                // FIXME useless because data is already sorted but lead to compilation error
                // val sortOp = SortOp(jo4)((x,y) => x[LegoString]("S_NAME") compareTo y.f.S_NAME)
                val po = PrintOp(jo4)(kv => printf("%.*s|%.*s\n",
                    kv[LegoString]("S_NAME").length,(kv[LegoString]("S_NAME")),kv.f.S_ADDRESS.length,(kv.f.S_ADDRESS)))
                po
        }
    }

    def Q21 = {
        val lineitemTable = loadLineitem1()
        val supplierTable = loadSupplier1()
        val ordersTable   = loadOrders1()
        val nationTable   = loadNation1()
        runQuery {
                val morocco = parseString("SAUDI ARABIA")
                val lineitemScan1 = SelectOp(ScanOp2(lineitemTable))(x => x.L_RECEIPTDATE > x.L_COMMITDATE)
                val lineitemScan2 = ScanOp2(lineitemTable)
                val lineitemScan3 = SelectOp(ScanOp2(lineitemTable))(x => x.L_RECEIPTDATE > x.L_COMMITDATE)
                val supplierScan  = ScanOp2(supplierTable)
                val nationScan    = SelectOp(ScanOp2(nationTable))(x => x.N_NAME == morocco)
                val ordersScan    = SelectOp(ScanOp2(ordersTable))(x => x.O_ORDERSTATUS == 'F')
                val jo1 = MapCatOp(HashJoinOp2(nationScan, supplierScan)((x,y) => x.N_NATIONKEY == y.S_NATIONKEY)(x => x.N_NATIONKEY)(x => x.S_NATIONKEY))
                val jo2 = MapCatOp(HashJoinOp2(jo1, lineitemScan1)((x,y) => x.f.S_SUPPKEY == y.L_SUPPKEY)(x => x.f.S_SUPPKEY)(x => x.L_SUPPKEY))
                val jo3 = MapCatOp(HashJoinOp2(jo2, ordersScan)((x,y) => y.O_ORDERKEY==x.f.L_ORDERKEY)(x => x.f.L_ORDERKEY)(x => x.O_ORDERKEY))
                val jo4 = HashJoinAnti1(jo3, lineitemScan3)((x,y) => x.f.L_ORDERKEY == y.L_ORDERKEY && x.f.L_SUPPKEY != y.L_SUPPKEY)(x => x.f.L_ORDERKEY)(x => x.L_ORDERKEY)
                val jo5 = LeftHashSemiJoinOp1(jo4, lineitemScan2)((x,y) => x.f.L_ORDERKEY == y.L_ORDERKEY && x.f.L_SUPPKEY != y.L_SUPPKEY)(x => x.f.L_ORDERKEY)(x => x.L_ORDERKEY)
                val aggOp = AggOp1(jo5)(x => x.f.S_NAME.asInstanceOf[Rep[LegoString]])(0.0)((t,currAgg) => {currAgg + 1})
                val sortOp = SortOp(aggOp)((x,y) => {
                    val a1 = x.aggs; val a2 = y.aggs
                    if (a1 < a2) 1
                    else if (a1 > a2) -1
                    else x.key compareTo y.key
                })
                // LIMIT 100 -- SORT BOTTLENECK?
                var i = 0
                val po = PrintOp(sortOp)(kv => {
                    printf("%.*s|%.0f\n",kv.key.length,(kv.key),kv.aggs)
                    i+=1
                }, () => i < 100)
                po
        }
    }

    def Q22 = {
        val customerTable = loadCustomer1()
        val ordersTable = loadOrders1()
        runQuery {
                val v23 = parseString("13")
                val v29 = parseString("31")
                val v22 = parseString("23")
                val v20 = parseString("29")
                val v24 = parseString("30")
                val v26 = parseString("18")
                val v25 = parseString("17")
                // Subquery
                val customerScan1 = SelectOp(ScanOp2(customerTable))(x => {
                    x.C_ACCTBAL > 0.00 && (
                        x.C_PHONE.startsWith(v23)  || (x.C_PHONE.startsWith(v29) || (x.C_PHONE.startsWith(v22) ||
                        (x.C_PHONE.startsWith(v20) || (x.C_PHONE.startsWith(v24) || (x.C_PHONE.startsWith(v26) ||
                        x.C_PHONE.startsWith(v25))))))
                    )
                })
                val aggOp1 = AggOp1(customerScan1)(x => "AVG_C_ACCTBAL")(zero2)(
                    (t,currAgg) => new Record {
                        val _0 = {t.C_ACCTBAL + currAgg._0}
                        val _1 = {currAgg._1 + 1}
                    }
                )
                val nestedAVG = MapOp1(aggOp1)(kv => new Record { val _0 = kv.aggs._0 / kv.aggs._1 })
                // External Query
                val customerScan2 = MapOp1(NestedLoopsJoinOp(nestedAVG,ScanOp2(customerTable))((nestedAVG,x) => {
                    x.C_ACCTBAL > nestedAVG._0 && (
                        x.C_PHONE.startsWith(v23)  || (x.C_PHONE.startsWith(v29) || (x.C_PHONE.startsWith(v22) ||
                        (x.C_PHONE.startsWith(v20) || (x.C_PHONE.startsWith(v24) || (x.C_PHONE.startsWith(v26) ||
                        x.C_PHONE.startsWith(v25))))))
                    )
                }))(x => new Record { val C_CUSTKEY = x.right.C_CUSTKEY; val C_ACCTBAL = x.right.C_ACCTBAL; val C_PHONE = x.right.C_PHONE })
                val ordersScan = ScanOp2(ordersTable)
                val jo = HashJoinAnti(customerScan2, ordersScan)((x,y) => x.C_CUSTKEY==y.O_CUSTKEY)(x => x.C_CUSTKEY)(x => x.O_CUSTKEY)
                val aggOp2 = AggOp1(jo)(x => new Record { val _0 = infix_charAt(x.C_PHONE,0L); val _1 = infix_charAt(x.C_PHONE,1L)})(zero2)(
                    (t, currAgg) => new Record {
                        val _0 = {t.C_ACCTBAL + currAgg._0}
                        val _1 = {currAgg._1 + 1}
                    }
                )
                val sortOp = SortOp(aggOp2)((x,y) => {
                    // We know that the substring has only two characters
                    var res = x.key._0 - y.key._0
                    if (res == 0) res = x.key._1 - y.key._1
                    res
                })
                val po = PrintOp(sortOp)(kv => printf("%c%c|%.0f|%.2f\n",kv.key._0,kv.key._1,kv.aggs._1,kv.aggs._0))
                po
        }
    }

}
