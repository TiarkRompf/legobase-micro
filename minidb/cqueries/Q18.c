/*****************************************
  Emitting C Generated Code                  
*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <glib.h>
#include <sys/time.h>
int strcmp(const char *s1, const char *s2);
int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1) {
	long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec);
	result->tv_sec = diff / 1000000;
	result->tv_usec = diff % 1000000;
	return (diff<0);
}

/********************* DATA STRUCTURES ***********************/
struct Anon850505655Anon1251919804;
struct Anon920667905;
struct Anon567626277;
struct Anon1406772883;
struct Anon168903330;
struct Anon850505655;
struct Anon1296044246;
struct Anon920667905Anon811555534;
struct Anon1866483359;
struct Anon189208763;
struct Anon102935935Anon168903330;
struct Anon2053173900;
struct Anon713865179Anon72918141;
struct Anon1023322325;
struct Anon1286901926Anon811555534;
struct Anon1548200872;
struct Anon855148991;
struct Anon147418070;
struct Anon920667905Anon811555534Anon168903330;
struct Anon1465150758;
struct Anon482109446;
struct Anon546410247;
struct Anon713865179;
struct Anon1406772883Anon1268892766Anon168903330;
struct Anon786783320;
struct Anon1599206474;
struct Anon1078540535;
struct Anon2134411685;
struct Anon102935935Anon1406772883Anon1268892766Anon168903330;
struct Anon475346392;
struct Anon955262776;
struct Anon811555534Anon920667905;
struct Anon713865179Anon72918141Anon1268892766Anon168903330Anon811555534;
struct Anon0;
struct Anon1812879556;
struct Anon811555534Anon168903330;
struct Anon102935935Anon168903330Anon811555534;
struct Anon811555534;
struct Anon15765642;
struct Anon102935935;
struct Anon1826514910;
struct Anon1621811895;
struct Anon713865179Anon72918141Anon1268892766Anon168903330;
struct Anon2131541195;
struct Anon1268892766;
struct Anon1406772883Anon811555534Anon920667905;
struct Anon1406772883Anon811555534Anon920667905Anon168903330;
struct Anon72918141;
struct Anon1286901926Anon811555534Anon920667905;
struct Anon1268892766Anon1866483359Anon1406772883Anon102935935Anon168903330Anon811555534Anon920667905;
struct Anon327816002;
struct Anon137880117;
struct Anon2131537536;
struct Anon1987966504;
struct Anon637505587;
struct Anon344387643;
struct Anon2052879266;
struct Anon313206116;
struct Anon713865179Anon72918141Anon1268892766;
struct Anon1395358962Anon102935935Anon1406772883Anon1268892766Anon168903330Anon811555534;
struct Anon1286901926;
struct Anon325450556;
struct Anon1406772883Anon1268892766;
struct Anon920667905Anon713865179Anon72918141Anon1268892766Anon168903330Anon811555534;
struct Anon1406772883Anon1268892766Anon1395358962;
struct Anon1406772883Anon102935935Anon168903330Anon811555534Anon920667905;
struct Anon102935935Anon168903330Anon811555534Anon920667905;
struct Anon1732223439;
struct Anon722854457;
struct Anon625264174;
struct Anon949908027;
struct Anon1711779607;
struct Anon1832691401;
struct Anon1268892766Anon1286901926;
struct Anon348455037;
struct Anon745588139;
struct Anon1251919804;
struct Anon1866483359Anon1406772883Anon102935935Anon168903330Anon811555534Anon920667905;
struct Anon1395358962;
struct Anon65967395;
struct Anon1395358962Anon102935935Anon1406772883Anon1268892766Anon168903330;
struct Anon1555625313;
struct Anon726278688;
struct Anon2052879268;
struct Anon417859734;
struct Anon704530870;

struct Anon850505655Anon1251919804 {
char* REC1_N_NAME;
int REC1_N_NATIONKEY;
long REC2_O_ORDERDATE;
double REC2_L_DISCOUNT;
double REC2_L_EXTENDEDPRICE;
int REC2_S_NATIONKEY;
};

struct Anon920667905 {
int C_CUSTKEY;
char* C_NAME;
char* C_ADDRESS;
int C_NATIONKEY;
char* C_PHONE;
double C_ACCTBAL;
char* C_MKTSEGMENT;
char* C_COMMENT;
};

struct Anon567626277 {
double _0;
double _1;
double _2;
double _3;
double _4;
double _5;
};

struct Anon1406772883 {
int N_NATIONKEY;
char* N_NAME;
int N_REGIONKEY;
char* N_COMMENT;
};

struct Anon168903330 {
int L_ORDERKEY;
int L_PARTKEY;
int L_SUPPKEY;
int L_LINENUMBER;
double L_QUANTITY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
double L_TAX;
char L_RETURNFLAG;
char L_LINESTATUS;
long L_SHIPDATE;
long L_COMMITDATE;
long L_RECEIPTDATE;
char* L_SHIPINSTRUCT;
char* L_SHIPMODE;
char* L_COMMENT;
};

struct Anon850505655 {
char* REC1_N_NAME;
int REC1_N_NATIONKEY;
};

struct Anon1296044246 {
double _0;
double _1;
double _2;
double _3;
double _4;
double _5;
double _6;
double _7;
double _8;
};

struct Anon920667905Anon811555534 {
int C_CUSTKEY;
char* C_NAME;
char* C_ADDRESS;
int C_NATIONKEY;
char* C_PHONE;
double C_ACCTBAL;
char* C_MKTSEGMENT;
char* C_COMMENT;
int O_ORDERKEY;
int O_CUSTKEY;
char O_ORDERSTATUS;
double O_TOTALPRICE;
long O_ORDERDATE;
char* O_ORDERPRIORITY;
char* O_CLERK;
int O_SHIPPRIORITY;
char* O_COMMENT;
};

struct Anon1866483359 {
int R_REGIONKEY;
char* R_NAME;
char* R_COMMENT;
};

struct Anon189208763 {
double _0;
double _1;
};

struct Anon102935935Anon168903330 {
int P_PARTKEY;
char* P_NAME;
char* P_MFGR;
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
char* P_CONTAINER;
double P_RETAILPRICE;
char* P_COMMENT;
int L_ORDERKEY;
int L_PARTKEY;
int L_SUPPKEY;
int L_LINENUMBER;
double L_QUANTITY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
double L_TAX;
char L_RETURNFLAG;
char L_LINESTATUS;
long L_SHIPDATE;
long L_COMMITDATE;
long L_RECEIPTDATE;
char* L_SHIPINSTRUCT;
char* L_SHIPMODE;
char* L_COMMENT;
};

struct Anon2053173900 {
int key;
double wnd;
};

struct Anon713865179Anon72918141 {
int N1_N_NATIONKEY;
char* N1_N_NAME;
int N1_N_REGIONKEY;
char* N1_N_COMMENT;
int N2_N_NATIONKEY;
char* N2_N_NAME;
int N2_N_REGIONKEY;
char* N2_N_COMMENT;
};

struct Anon1023322325 {
double PS_SUPPLYCOST;
double S_ACCTBAL;
char* S_NAME;
char* S_ADDRESS;
char* S_PHONE;
char* S_COMMENT;
char* N_NAME;
int P_PARTKEY;
char* P_MFGR;
};

struct Anon1286901926Anon811555534 {
int key;
struct Anon2052879266* aggs;
int O_ORDERKEY;
int O_CUSTKEY;
char O_ORDERSTATUS;
double O_TOTALPRICE;
long O_ORDERDATE;
char* O_ORDERPRIORITY;
char* O_CLERK;
int O_SHIPPRIORITY;
char* O_COMMENT;
};

struct Anon1548200872 {
char* NATION;
int O_YEAR;
};

struct Anon855148991 {
struct Anon625264174* key;
struct Anon1296044246* aggs;
};

struct Anon147418070 {
char* N_NAME;
int N_NATIONKEY;
int C_CUSTKEY;
};

struct Anon920667905Anon811555534Anon168903330 {
int C_CUSTKEY;
char* C_NAME;
char* C_ADDRESS;
int C_NATIONKEY;
char* C_PHONE;
double C_ACCTBAL;
char* C_MKTSEGMENT;
char* C_COMMENT;
int O_ORDERKEY;
int O_CUSTKEY;
char O_ORDERSTATUS;
double O_TOTALPRICE;
long O_ORDERDATE;
char* O_ORDERPRIORITY;
char* O_CLERK;
int O_SHIPPRIORITY;
char* O_COMMENT;
int L_ORDERKEY;
int L_PARTKEY;
int L_SUPPKEY;
int L_LINENUMBER;
double L_QUANTITY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
double L_TAX;
char L_RETURNFLAG;
char L_LINESTATUS;
long L_SHIPDATE;
long L_COMMITDATE;
long L_RECEIPTDATE;
char* L_SHIPINSTRUCT;
char* L_SHIPMODE;
char* L_COMMENT;
};

struct Anon1465150758 {
int L_ORDERKEY;
long O_ORDERDATE;
int O_SHIPPRIORITY;
};

struct Anon482109446 {
int N1_N_NATIONKEY;
char* N1_N_NAME;
int N1_N_REGIONKEY;
char* N1_N_COMMENT;
int N2_N_NATIONKEY;
char* N2_N_NAME;
int N2_N_REGIONKEY;
char* N2_N_COMMENT;
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
};

struct Anon546410247 {
char* N_NAME;
int N_NATIONKEY;
int O_ORDERKEY;
};

struct Anon713865179 {
int N1_N_NATIONKEY;
char* N1_N_NAME;
int N1_N_REGIONKEY;
char* N1_N_COMMENT;
};

struct Anon1406772883Anon1268892766Anon168903330 {
int N_NATIONKEY;
char* N_NAME;
int N_REGIONKEY;
char* N_COMMENT;
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
int L_ORDERKEY;
int L_PARTKEY;
int L_SUPPKEY;
int L_LINENUMBER;
double L_QUANTITY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
double L_TAX;
char L_RETURNFLAG;
char L_LINESTATUS;
long L_SHIPDATE;
long L_COMMITDATE;
long L_RECEIPTDATE;
char* L_SHIPINSTRUCT;
char* L_SHIPMODE;
char* L_COMMENT;
};

struct Anon786783320 {
int N1_N_NATIONKEY;
char* N1_N_NAME;
int N1_N_REGIONKEY;
char* N1_N_COMMENT;
int N2_N_NATIONKEY;
char* N2_N_NAME;
int N2_N_REGIONKEY;
char* N2_N_COMMENT;
};

struct Anon1599206474 {
int PS_PARTKEY;
int PS_SUPPKEY;
int PS_AVAILQTY;
double PS_SUPPLYCOST;
char* PS_COMMENT;
int P_PARTKEY;
char* P_NAME;
char* P_MFGR;
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
char* P_CONTAINER;
double P_RETAILPRICE;
char* P_COMMENT;
int N_NATIONKEY;
char* N_NAME;
int N_REGIONKEY;
char* N_COMMENT;
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
int L_ORDERKEY;
int L_PARTKEY;
int L_SUPPKEY;
int L_LINENUMBER;
double L_QUANTITY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
double L_TAX;
char L_RETURNFLAG;
char L_LINESTATUS;
long L_SHIPDATE;
long L_COMMITDATE;
long L_RECEIPTDATE;
char* L_SHIPINSTRUCT;
char* L_SHIPMODE;
char* L_COMMENT;
};

struct Anon1078540535 {
char* N_NAME;
int N_NATIONKEY;
};

struct Anon2134411685 {
int key;
struct Anon1023322325* aggs;
};

struct Anon102935935Anon1406772883Anon1268892766Anon168903330 {
int P_PARTKEY;
char* P_NAME;
char* P_MFGR;
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
char* P_CONTAINER;
double P_RETAILPRICE;
char* P_COMMENT;
int N_NATIONKEY;
char* N_NAME;
int N_REGIONKEY;
char* N_COMMENT;
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
int L_ORDERKEY;
int L_PARTKEY;
int L_SUPPKEY;
int L_LINENUMBER;
double L_QUANTITY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
double L_TAX;
char L_RETURNFLAG;
char L_LINESTATUS;
long L_SHIPDATE;
long L_COMMITDATE;
long L_RECEIPTDATE;
char* L_SHIPINSTRUCT;
char* L_SHIPMODE;
char* L_COMMENT;
};

struct Anon475346392 {
int key;
struct Anon2052879266* aggs;
int O_ORDERKEY;
int O_CUSTKEY;
char O_ORDERSTATUS;
double O_TOTALPRICE;
long O_ORDERDATE;
char* O_ORDERPRIORITY;
char* O_CLERK;
int O_SHIPPRIORITY;
char* O_COMMENT;
};

struct Anon955262776 {
double key;
struct Anon2052879266* aggs;
};

struct Anon811555534Anon920667905 {
int O_ORDERKEY;
int O_CUSTKEY;
char O_ORDERSTATUS;
double O_TOTALPRICE;
long O_ORDERDATE;
char* O_ORDERPRIORITY;
char* O_CLERK;
int O_SHIPPRIORITY;
char* O_COMMENT;
int C_CUSTKEY;
char* C_NAME;
char* C_ADDRESS;
int C_NATIONKEY;
char* C_PHONE;
double C_ACCTBAL;
char* C_MKTSEGMENT;
char* C_COMMENT;
};

struct Anon713865179Anon72918141Anon1268892766Anon168903330Anon811555534 {
int N1_N_NATIONKEY;
char* N1_N_NAME;
int N1_N_REGIONKEY;
char* N1_N_COMMENT;
int N2_N_NATIONKEY;
char* N2_N_NAME;
int N2_N_REGIONKEY;
char* N2_N_COMMENT;
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
int L_ORDERKEY;
int L_PARTKEY;
int L_SUPPKEY;
int L_LINENUMBER;
double L_QUANTITY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
double L_TAX;
char L_RETURNFLAG;
char L_LINESTATUS;
long L_SHIPDATE;
long L_COMMITDATE;
long L_RECEIPTDATE;
char* L_SHIPINSTRUCT;
char* L_SHIPMODE;
char* L_COMMENT;
int O_ORDERKEY;
int O_CUSTKEY;
char O_ORDERSTATUS;
double O_TOTALPRICE;
long O_ORDERDATE;
char* O_ORDERPRIORITY;
char* O_CLERK;
int O_SHIPPRIORITY;
char* O_COMMENT;
};

struct Anon0 {
struct Anon475346392* left;
struct Anon920667905* right;
};

struct Anon1812879556 {
char* key;
struct Anon2052879266* aggs;
};

struct Anon811555534Anon168903330 {
int O_ORDERKEY;
int O_CUSTKEY;
char O_ORDERSTATUS;
double O_TOTALPRICE;
long O_ORDERDATE;
char* O_ORDERPRIORITY;
char* O_CLERK;
int O_SHIPPRIORITY;
char* O_COMMENT;
int L_ORDERKEY;
int L_PARTKEY;
int L_SUPPKEY;
int L_LINENUMBER;
double L_QUANTITY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
double L_TAX;
char L_RETURNFLAG;
char L_LINESTATUS;
long L_SHIPDATE;
long L_COMMITDATE;
long L_RECEIPTDATE;
char* L_SHIPINSTRUCT;
char* L_SHIPMODE;
char* L_COMMENT;
};

struct Anon102935935Anon168903330Anon811555534 {
int P_PARTKEY;
char* P_NAME;
char* P_MFGR;
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
char* P_CONTAINER;
double P_RETAILPRICE;
char* P_COMMENT;
int L_ORDERKEY;
int L_PARTKEY;
int L_SUPPKEY;
int L_LINENUMBER;
double L_QUANTITY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
double L_TAX;
char L_RETURNFLAG;
char L_LINESTATUS;
long L_SHIPDATE;
long L_COMMITDATE;
long L_RECEIPTDATE;
char* L_SHIPINSTRUCT;
char* L_SHIPMODE;
char* L_COMMENT;
int O_ORDERKEY;
int O_CUSTKEY;
char O_ORDERSTATUS;
double O_TOTALPRICE;
long O_ORDERDATE;
char* O_ORDERPRIORITY;
char* O_CLERK;
int O_SHIPPRIORITY;
char* O_COMMENT;
};

struct Anon811555534 {
int O_ORDERKEY;
int O_CUSTKEY;
char O_ORDERSTATUS;
double O_TOTALPRICE;
long O_ORDERDATE;
char* O_ORDERPRIORITY;
char* O_CLERK;
int O_SHIPPRIORITY;
char* O_COMMENT;
};

struct Anon15765642 {
double PS_SUPPLYCOST;
int PS_PARTKEY;
int S_NATIONKEY;
double S_ACCTBAL;
char* S_NAME;
char* S_ADDRESS;
char* S_PHONE;
char* S_COMMENT;
};

struct Anon102935935 {
int P_PARTKEY;
char* P_NAME;
char* P_MFGR;
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
char* P_CONTAINER;
double P_RETAILPRICE;
char* P_COMMENT;
};

struct Anon1826514910 {
struct Anon1621811895* key;
struct Anon2052879266* aggs;
};

struct Anon1621811895 {
char* C_NAME;
int C_CUSTKEY;
int O_ORDERKEY;
long O_ORDERDATE;
double O_TOTALPRICE;
};

struct Anon713865179Anon72918141Anon1268892766Anon168903330 {
int N1_N_NATIONKEY;
char* N1_N_NAME;
int N1_N_REGIONKEY;
char* N1_N_COMMENT;
int N2_N_NATIONKEY;
char* N2_N_NAME;
int N2_N_REGIONKEY;
char* N2_N_COMMENT;
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
int L_ORDERKEY;
int L_PARTKEY;
int L_SUPPKEY;
int L_LINENUMBER;
double L_QUANTITY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
double L_TAX;
char L_RETURNFLAG;
char L_LINESTATUS;
long L_SHIPDATE;
long L_COMMITDATE;
long L_RECEIPTDATE;
char* L_SHIPINSTRUCT;
char* L_SHIPMODE;
char* L_COMMENT;
};

struct Anon2131541195 {
double total;
};

struct Anon1268892766 {
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
};

struct Anon1406772883Anon811555534Anon920667905 {
int N_NATIONKEY;
char* N_NAME;
int N_REGIONKEY;
char* N_COMMENT;
int O_ORDERKEY;
int O_CUSTKEY;
char O_ORDERSTATUS;
double O_TOTALPRICE;
long O_ORDERDATE;
char* O_ORDERPRIORITY;
char* O_CLERK;
int O_SHIPPRIORITY;
char* O_COMMENT;
int C_CUSTKEY;
char* C_NAME;
char* C_ADDRESS;
int C_NATIONKEY;
char* C_PHONE;
double C_ACCTBAL;
char* C_MKTSEGMENT;
char* C_COMMENT;
};

struct Anon1406772883Anon811555534Anon920667905Anon168903330 {
int N_NATIONKEY;
char* N_NAME;
int N_REGIONKEY;
char* N_COMMENT;
int O_ORDERKEY;
int O_CUSTKEY;
char O_ORDERSTATUS;
double O_TOTALPRICE;
long O_ORDERDATE;
char* O_ORDERPRIORITY;
char* O_CLERK;
int O_SHIPPRIORITY;
char* O_COMMENT;
int C_CUSTKEY;
char* C_NAME;
char* C_ADDRESS;
int C_NATIONKEY;
char* C_PHONE;
double C_ACCTBAL;
char* C_MKTSEGMENT;
char* C_COMMENT;
int L_ORDERKEY;
int L_PARTKEY;
int L_SUPPKEY;
int L_LINENUMBER;
double L_QUANTITY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
double L_TAX;
char L_RETURNFLAG;
char L_LINESTATUS;
long L_SHIPDATE;
long L_COMMITDATE;
long L_RECEIPTDATE;
char* L_SHIPINSTRUCT;
char* L_SHIPMODE;
char* L_COMMENT;
};

struct Anon72918141 {
int N2_N_NATIONKEY;
char* N2_N_NAME;
int N2_N_REGIONKEY;
char* N2_N_COMMENT;
};

struct Anon1286901926Anon811555534Anon920667905 {
int key;
struct Anon2052879266* aggs;
int O_ORDERKEY;
int O_CUSTKEY;
char O_ORDERSTATUS;
double O_TOTALPRICE;
long O_ORDERDATE;
char* O_ORDERPRIORITY;
char* O_CLERK;
int O_SHIPPRIORITY;
char* O_COMMENT;
int C_CUSTKEY;
char* C_NAME;
char* C_ADDRESS;
int C_NATIONKEY;
char* C_PHONE;
double C_ACCTBAL;
char* C_MKTSEGMENT;
char* C_COMMENT;
};

struct Anon1268892766Anon1866483359Anon1406772883Anon102935935Anon168903330Anon811555534Anon920667905 {
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
int R_REGIONKEY;
char* R_NAME;
char* R_COMMENT;
int N_NATIONKEY;
char* N_NAME;
int N_REGIONKEY;
char* N_COMMENT;
int P_PARTKEY;
char* P_NAME;
char* P_MFGR;
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
char* P_CONTAINER;
double P_RETAILPRICE;
char* P_COMMENT;
int L_ORDERKEY;
int L_PARTKEY;
int L_SUPPKEY;
int L_LINENUMBER;
double L_QUANTITY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
double L_TAX;
char L_RETURNFLAG;
char L_LINESTATUS;
long L_SHIPDATE;
long L_COMMITDATE;
long L_RECEIPTDATE;
char* L_SHIPINSTRUCT;
char* L_SHIPMODE;
char* L_COMMENT;
int O_ORDERKEY;
int O_CUSTKEY;
char O_ORDERSTATUS;
double O_TOTALPRICE;
long O_ORDERDATE;
char* O_ORDERPRIORITY;
char* O_CLERK;
int O_SHIPPRIORITY;
char* O_COMMENT;
int C_CUSTKEY;
char* C_NAME;
char* C_ADDRESS;
int C_NATIONKEY;
char* C_PHONE;
double C_ACCTBAL;
char* C_MKTSEGMENT;
char* C_COMMENT;
};

struct Anon327816002 {
double PS_SUPPLYCOST;
double S_ACCTBAL;
char* S_NAME;
char* S_ADDRESS;
char* S_PHONE;
char* S_COMMENT;
char* N_NAME;
int N_REGIONKEY;
int P_PARTKEY;
char* P_MFGR;
};

struct Anon137880117 {
int N_NATIONKEY;
char* N_NAME;
int N_REGIONKEY;
char* N_COMMENT;
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
};

struct Anon2131537536 {
int key;
struct Anon1023322325* wnd;
};

struct Anon1987966504 {
int key;
struct Anon2052879268* aggs;
};

struct Anon637505587 {
int key;
struct Anon189208763* aggs;
};

struct Anon344387643 {
struct Anon1548200872* key;
struct Anon2052879266* aggs;
};

struct Anon2052879266 {
double _0;
};

struct Anon313206116 {
int N1_N_NATIONKEY;
char* N1_N_NAME;
int N1_N_REGIONKEY;
char* N1_N_COMMENT;
int N2_N_NATIONKEY;
char* N2_N_NAME;
int N2_N_REGIONKEY;
char* N2_N_COMMENT;
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
int L_ORDERKEY;
int L_PARTKEY;
int L_SUPPKEY;
int L_LINENUMBER;
double L_QUANTITY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
double L_TAX;
char L_RETURNFLAG;
char L_LINESTATUS;
long L_SHIPDATE;
long L_COMMITDATE;
long L_RECEIPTDATE;
char* L_SHIPINSTRUCT;
char* L_SHIPMODE;
char* L_COMMENT;
};

struct Anon713865179Anon72918141Anon1268892766 {
int N1_N_NATIONKEY;
char* N1_N_NAME;
int N1_N_REGIONKEY;
char* N1_N_COMMENT;
int N2_N_NATIONKEY;
char* N2_N_NAME;
int N2_N_REGIONKEY;
char* N2_N_COMMENT;
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
};

struct Anon1395358962Anon102935935Anon1406772883Anon1268892766Anon168903330Anon811555534 {
int PS_PARTKEY;
int PS_SUPPKEY;
int PS_AVAILQTY;
double PS_SUPPLYCOST;
char* PS_COMMENT;
int P_PARTKEY;
char* P_NAME;
char* P_MFGR;
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
char* P_CONTAINER;
double P_RETAILPRICE;
char* P_COMMENT;
int N_NATIONKEY;
char* N_NAME;
int N_REGIONKEY;
char* N_COMMENT;
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
int L_ORDERKEY;
int L_PARTKEY;
int L_SUPPKEY;
int L_LINENUMBER;
double L_QUANTITY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
double L_TAX;
char L_RETURNFLAG;
char L_LINESTATUS;
long L_SHIPDATE;
long L_COMMITDATE;
long L_RECEIPTDATE;
char* L_SHIPINSTRUCT;
char* L_SHIPMODE;
char* L_COMMENT;
int O_ORDERKEY;
int O_CUSTKEY;
char O_ORDERSTATUS;
double O_TOTALPRICE;
long O_ORDERDATE;
char* O_ORDERPRIORITY;
char* O_CLERK;
int O_SHIPPRIORITY;
char* O_COMMENT;
};

struct Anon1286901926 {
int key;
struct Anon2052879266* aggs;
};

struct Anon325450556 {
int N_NATIONKEY;
char* N_NAME;
int N_REGIONKEY;
char* N_COMMENT;
int O_ORDERKEY;
int O_CUSTKEY;
char O_ORDERSTATUS;
double O_TOTALPRICE;
long O_ORDERDATE;
char* O_ORDERPRIORITY;
char* O_CLERK;
int O_SHIPPRIORITY;
char* O_COMMENT;
int C_CUSTKEY;
char* C_NAME;
char* C_ADDRESS;
int C_NATIONKEY;
char* C_PHONE;
double C_ACCTBAL;
char* C_MKTSEGMENT;
char* C_COMMENT;
};

struct Anon1406772883Anon1268892766 {
int N_NATIONKEY;
char* N_NAME;
int N_REGIONKEY;
char* N_COMMENT;
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
};

struct Anon920667905Anon713865179Anon72918141Anon1268892766Anon168903330Anon811555534 {
int C_CUSTKEY;
char* C_NAME;
char* C_ADDRESS;
int C_NATIONKEY;
char* C_PHONE;
double C_ACCTBAL;
char* C_MKTSEGMENT;
char* C_COMMENT;
int N1_N_NATIONKEY;
char* N1_N_NAME;
int N1_N_REGIONKEY;
char* N1_N_COMMENT;
int N2_N_NATIONKEY;
char* N2_N_NAME;
int N2_N_REGIONKEY;
char* N2_N_COMMENT;
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
int L_ORDERKEY;
int L_PARTKEY;
int L_SUPPKEY;
int L_LINENUMBER;
double L_QUANTITY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
double L_TAX;
char L_RETURNFLAG;
char L_LINESTATUS;
long L_SHIPDATE;
long L_COMMITDATE;
long L_RECEIPTDATE;
char* L_SHIPINSTRUCT;
char* L_SHIPMODE;
char* L_COMMENT;
int O_ORDERKEY;
int O_CUSTKEY;
char O_ORDERSTATUS;
double O_TOTALPRICE;
long O_ORDERDATE;
char* O_ORDERPRIORITY;
char* O_CLERK;
int O_SHIPPRIORITY;
char* O_COMMENT;
};

struct Anon1406772883Anon1268892766Anon1395358962 {
int N_NATIONKEY;
char* N_NAME;
int N_REGIONKEY;
char* N_COMMENT;
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
int PS_PARTKEY;
int PS_SUPPKEY;
int PS_AVAILQTY;
double PS_SUPPLYCOST;
char* PS_COMMENT;
};

struct Anon1406772883Anon102935935Anon168903330Anon811555534Anon920667905 {
int N_NATIONKEY;
char* N_NAME;
int N_REGIONKEY;
char* N_COMMENT;
int P_PARTKEY;
char* P_NAME;
char* P_MFGR;
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
char* P_CONTAINER;
double P_RETAILPRICE;
char* P_COMMENT;
int L_ORDERKEY;
int L_PARTKEY;
int L_SUPPKEY;
int L_LINENUMBER;
double L_QUANTITY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
double L_TAX;
char L_RETURNFLAG;
char L_LINESTATUS;
long L_SHIPDATE;
long L_COMMITDATE;
long L_RECEIPTDATE;
char* L_SHIPINSTRUCT;
char* L_SHIPMODE;
char* L_COMMENT;
int O_ORDERKEY;
int O_CUSTKEY;
char O_ORDERSTATUS;
double O_TOTALPRICE;
long O_ORDERDATE;
char* O_ORDERPRIORITY;
char* O_CLERK;
int O_SHIPPRIORITY;
char* O_COMMENT;
int C_CUSTKEY;
char* C_NAME;
char* C_ADDRESS;
int C_NATIONKEY;
char* C_PHONE;
double C_ACCTBAL;
char* C_MKTSEGMENT;
char* C_COMMENT;
};

struct Anon102935935Anon168903330Anon811555534Anon920667905 {
int P_PARTKEY;
char* P_NAME;
char* P_MFGR;
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
char* P_CONTAINER;
double P_RETAILPRICE;
char* P_COMMENT;
int L_ORDERKEY;
int L_PARTKEY;
int L_SUPPKEY;
int L_LINENUMBER;
double L_QUANTITY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
double L_TAX;
char L_RETURNFLAG;
char L_LINESTATUS;
long L_SHIPDATE;
long L_COMMITDATE;
long L_RECEIPTDATE;
char* L_SHIPINSTRUCT;
char* L_SHIPMODE;
char* L_COMMENT;
int O_ORDERKEY;
int O_CUSTKEY;
char O_ORDERSTATUS;
double O_TOTALPRICE;
long O_ORDERDATE;
char* O_ORDERPRIORITY;
char* O_CLERK;
int O_SHIPPRIORITY;
char* O_COMMENT;
int C_CUSTKEY;
char* C_NAME;
char* C_ADDRESS;
int C_NATIONKEY;
char* C_PHONE;
double C_ACCTBAL;
char* C_MKTSEGMENT;
char* C_COMMENT;
};

struct Anon1732223439 {
int C_CUSTKEY;
char* C_NAME;
char* C_ADDRESS;
int C_NATIONKEY;
char* C_PHONE;
double C_ACCTBAL;
char* C_MKTSEGMENT;
char* C_COMMENT;
int O_ORDERKEY;
int O_CUSTKEY;
char O_ORDERSTATUS;
double O_TOTALPRICE;
long O_ORDERDATE;
char* O_ORDERPRIORITY;
char* O_CLERK;
int O_SHIPPRIORITY;
char* O_COMMENT;
};

struct Anon722854457 {
double PS_SUPPLYCOST;
int PS_PARTKEY;
double S_ACCTBAL;
char* S_NAME;
char* S_ADDRESS;
char* S_PHONE;
char* S_COMMENT;
char* N_NAME;
int N_REGIONKEY;
};

struct Anon625264174 {
char L_RETURNFLAG;
char L_LINESTATUS;
};

struct Anon949908027 {
struct Anon726278688* key;
struct Anon2052879266* aggs;
};

struct Anon1711779607 {
int C_CUSTKEY;
char* C_NAME;
double C_ACCTBAL;
char* C_PHONE;
char* N_NAME;
char* C_ADDRESS;
char* C_COMMENT;
};

struct Anon1832691401 {
char* key;
struct Anon189208763* aggs;
};

struct Anon1268892766Anon1286901926 {
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
int key;
struct Anon2052879266* aggs;
};

struct Anon348455037 {
char* N_NAME;
int N_NATIONKEY;
int L_SUPPKEY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
};

struct Anon745588139 {
int P_PARTKEY;
char* P_NAME;
char* P_MFGR;
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
char* P_CONTAINER;
double P_RETAILPRICE;
char* P_COMMENT;
int L_ORDERKEY;
int L_PARTKEY;
int L_SUPPKEY;
int L_LINENUMBER;
double L_QUANTITY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
double L_TAX;
char L_RETURNFLAG;
char L_LINESTATUS;
long L_SHIPDATE;
long L_COMMITDATE;
long L_RECEIPTDATE;
char* L_SHIPINSTRUCT;
char* L_SHIPMODE;
char* L_COMMENT;
int O_ORDERKEY;
int O_CUSTKEY;
char O_ORDERSTATUS;
double O_TOTALPRICE;
long O_ORDERDATE;
char* O_ORDERPRIORITY;
char* O_CLERK;
int O_SHIPPRIORITY;
char* O_COMMENT;
};

struct Anon1251919804 {
long REC2_O_ORDERDATE;
double REC2_L_DISCOUNT;
double REC2_L_EXTENDEDPRICE;
int REC2_S_NATIONKEY;
};

struct Anon1866483359Anon1406772883Anon102935935Anon168903330Anon811555534Anon920667905 {
int R_REGIONKEY;
char* R_NAME;
char* R_COMMENT;
int N_NATIONKEY;
char* N_NAME;
int N_REGIONKEY;
char* N_COMMENT;
int P_PARTKEY;
char* P_NAME;
char* P_MFGR;
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
char* P_CONTAINER;
double P_RETAILPRICE;
char* P_COMMENT;
int L_ORDERKEY;
int L_PARTKEY;
int L_SUPPKEY;
int L_LINENUMBER;
double L_QUANTITY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
double L_TAX;
char L_RETURNFLAG;
char L_LINESTATUS;
long L_SHIPDATE;
long L_COMMITDATE;
long L_RECEIPTDATE;
char* L_SHIPINSTRUCT;
char* L_SHIPMODE;
char* L_COMMENT;
int O_ORDERKEY;
int O_CUSTKEY;
char O_ORDERSTATUS;
double O_TOTALPRICE;
long O_ORDERDATE;
char* O_ORDERPRIORITY;
char* O_CLERK;
int O_SHIPPRIORITY;
char* O_COMMENT;
int C_CUSTKEY;
char* C_NAME;
char* C_ADDRESS;
int C_NATIONKEY;
char* C_PHONE;
double C_ACCTBAL;
char* C_MKTSEGMENT;
char* C_COMMENT;
};

struct Anon1395358962 {
int PS_PARTKEY;
int PS_SUPPKEY;
int PS_AVAILQTY;
double PS_SUPPLYCOST;
char* PS_COMMENT;
};

struct Anon65967395 {
int P_PARTKEY;
char* P_NAME;
char* P_MFGR;
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
char* P_CONTAINER;
double P_RETAILPRICE;
char* P_COMMENT;
int L_ORDERKEY;
int L_PARTKEY;
int L_SUPPKEY;
int L_LINENUMBER;
double L_QUANTITY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
double L_TAX;
char L_RETURNFLAG;
char L_LINESTATUS;
long L_SHIPDATE;
long L_COMMITDATE;
long L_RECEIPTDATE;
char* L_SHIPINSTRUCT;
char* L_SHIPMODE;
char* L_COMMENT;
};

struct Anon1395358962Anon102935935Anon1406772883Anon1268892766Anon168903330 {
int PS_PARTKEY;
int PS_SUPPKEY;
int PS_AVAILQTY;
double PS_SUPPLYCOST;
char* PS_COMMENT;
int P_PARTKEY;
char* P_NAME;
char* P_MFGR;
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
char* P_CONTAINER;
double P_RETAILPRICE;
char* P_COMMENT;
int N_NATIONKEY;
char* N_NAME;
int N_REGIONKEY;
char* N_COMMENT;
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
int L_ORDERKEY;
int L_PARTKEY;
int L_SUPPKEY;
int L_LINENUMBER;
double L_QUANTITY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
double L_TAX;
char L_RETURNFLAG;
char L_LINESTATUS;
long L_SHIPDATE;
long L_COMMITDATE;
long L_RECEIPTDATE;
char* L_SHIPINSTRUCT;
char* L_SHIPMODE;
char* L_COMMENT;
};

struct Anon1555625313 {
struct Anon1465150758* key;
struct Anon2052879266* aggs;
};

struct Anon726278688 {
char* SUPP_NATION;
char* CUST_NATION;
int L_YEAR;
};

struct Anon2052879268 {
double _2;
};

struct Anon417859734 {
struct Anon1711779607* key;
struct Anon2052879266* aggs;
};

struct Anon704530870 {
struct Anon625264174* key;
struct Anon567626277* aggs;
};

/************************ FUNCTIONS **************************/
int x32169(struct Anon1826514910* x30541, struct Anon1826514910* x30540);
int x32175(struct Anon1826514910* x32170, struct Anon1826514910* x32171, struct Anon1826514910** x32172);
int x32169(struct Anon1826514910* x30541, struct Anon1826514910* x30540) {
  struct Anon1621811895* x30542 = x30540->key;;
  double x30543 = x30542->O_TOTALPRICE;;
  struct Anon1621811895* x30544 = x30541->key;;
  double x30545 = x30544->O_TOTALPRICE;;
  bool x30546 = x30543 < x30545;
  int x31523;
  if (x30546) {
    x31523 = 1;
  } else {
    bool x30547 = x30543 > x30545;
    int x31521;
    if (x30547) {
      x31521 = -1;
    } else {
      long x30548 = x30542->O_ORDERDATE;;
      long x30549 = x30544->O_ORDERDATE;;
      bool x30550 = x30548 < x30549;
      int x31519;
      if (x30550) {
        x31519 = -1;
      } else {
        bool x30551 = x30548 > x30549;
        int x31517;
        if (x30551) {
          x31517 = 1;
        } else {
          x31517 = 0;
        }
        x31519 = x31517;
      }
      x31521 = x31519;
    }
    x31523 = x31521;
  }
  return x31523;
}
int x32175(struct Anon1826514910* x32170, struct Anon1826514910* x32171, struct Anon1826514910** x32172) {
  *x32172 = x32171;
  return 0;
}

/************************ MAIN BODY **************************/
int main(int x30070, char** x30071) {
  FILE* x31146 = fopen("../databases/sf2/lineitem.tbl", "r");
  int x31147 = 1048576;
  int x31148 = 0;
  int* x31149 = (int*)malloc(1048576 * sizeof(int));
  int* x31150 = x31149;
  double* x31157 = (double*)malloc(1048576 * sizeof(double));
  double* x31158 = x31157;
  for (;;) {
    bool x31181 = !feof(x31146);
    if (!x31181) break;
    int x31183 = 0;
    if (fscanf(x31146,"%d|",&x31183) == EOF) break;
    int x31184 = 0;
    if (fscanf(x31146,"%d|",&x31184) == EOF) break;
    int x31185 = 0;
    if (fscanf(x31146,"%d|",&x31185) == EOF) break;
    int x31186 = 0;
    if (fscanf(x31146,"%d|",&x31186) == EOF) break;
    double x31187 = 0.0;
    if (fscanf(x31146,"%lf|",&x31187) == EOF) break;
    double x31188 = 0.0;
    if (fscanf(x31146,"%lf|",&x31188) == EOF) break;
    double x31189 = 0.0;
    if (fscanf(x31146,"%lf|",&x31189) == EOF) break;
    double x31190 = 0.0;
    if (fscanf(x31146,"%lf|",&x31190) == EOF) break;
    char x31191 = ' ';
    if (fscanf(x31146,"%c|",&x31191) == EOF) break;
    char x31192 = ' ';
    if (fscanf(x31146,"%c|",&x31192) == EOF) break;
    int x31193 = 0;
    int x31194 = 0;
    int x31195 = 0;
    fscanf(x31146, "%d-%d-%d|",&x31193, &x31194, &x31195);
    long x31196 = (x31193 * 10000) + (x31194 * 100) + x31195;
    int x31197 = 0;
    int x31198 = 0;
    int x31199 = 0;
    fscanf(x31146, "%d-%d-%d|",&x31197, &x31198, &x31199);
    long x31200 = (x31197 * 10000) + (x31198 * 100) + x31199;
    int x31201 = 0;
    int x31202 = 0;
    int x31203 = 0;
    fscanf(x31146, "%d-%d-%d|",&x31201, &x31202, &x31203);
    long x31204 = (x31201 * 10000) + (x31202 * 100) + x31203;
    char* x31205 = (char*)malloc(26 * sizeof(char));
    int x31207 = 0;
    char x31206 = ' ';
    while (1) {
      fscanf(x31146,"%c",&x31206);
      if (x31206=='|' || x31206=='\n') break;
      if (x31207>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x31207); break;}
      ((char*)x31205)[x31207] = x31206;
      x31207 += 1;
    }
    ((char*)x31205)[x31207] = '\0';
    char* x31210 = (char*)malloc(11 * sizeof(char));
    int x31212 = 0;
    char x31211 = ' ';
    while (1) {
      fscanf(x31146,"%c",&x31211);
      if (x31211=='|' || x31211=='\n') break;
      if (x31212>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x31212); break;}
      ((char*)x31210)[x31212] = x31211;
      x31212 += 1;
    }
    ((char*)x31210)[x31212] = '\0';
    char* x31215 = (char*)malloc(45 * sizeof(char));
    int x31217 = 0;
    char x31216 = ' ';
    while (1) {
      fscanf(x31146,"%c",&x31216);
      if (x31216=='|' || x31216=='\n') break;
      if (x31217>=44) { printf("ERROR: scanner.nextString reading past end of buffer %d",x31217); break;}
      ((char*)x31215)[x31217] = x31216;
      x31217 += 1;
    }
    ((char*)x31215)[x31217] = '\0';
    int x31220 = x31148;
    int x31221 = x31147;
    bool x31222 = x31220 == x31221;
    if (x31222) {
      int x31223 = x31221 * 4;
      x31147 = x31223;
      printf("buffer.resize %d\n",x31223);
      int* x31226 = x31150;
      int* x31227 = (int*)realloc(x31226,x31223 * sizeof(int));
      x31150 = x31227;
      double* x31238 = x31158;
      double* x31239 = (double*)realloc(x31238,x31223 * sizeof(double));
      x31158 = x31239;
    } else {
    }
    int* x31276 = x31150;
    x31276[x31220] = x31183;
    double* x31284 = x31158;
    x31284[x31220] = x31187;
    x31148 = x31148 + 1;
  }
  FILE* x31312 = fopen("../databases/sf2/orders.tbl", "r");
  int x31313 = 1048576;
  int x31314 = 0;
  int* x31315 = (int*)malloc(1048576 * sizeof(int));
  int* x31316 = x31315;
  int* x31317 = (int*)malloc(1048576 * sizeof(int));
  int* x31318 = x31317;
  double* x31321 = (double*)malloc(1048576 * sizeof(double));
  double* x31322 = x31321;
  long* x31323 = (long*)malloc(1048576 * sizeof(long));
  long* x31324 = x31323;
  for (;;) {
    bool x31333 = !feof(x31312);
    if (!x31333) break;
    int x31335 = 0;
    if (fscanf(x31312,"%d|",&x31335) == EOF) break;
    int x31336 = 0;
    if (fscanf(x31312,"%d|",&x31336) == EOF) break;
    char x31337 = ' ';
    if (fscanf(x31312,"%c|",&x31337) == EOF) break;
    double x31338 = 0.0;
    if (fscanf(x31312,"%lf|",&x31338) == EOF) break;
    int x31339 = 0;
    int x31340 = 0;
    int x31341 = 0;
    fscanf(x31312, "%d-%d-%d|",&x31339, &x31340, &x31341);
    long x31342 = (x31339 * 10000) + (x31340 * 100) + x31341;
    char* x31343 = (char*)malloc(16 * sizeof(char));
    int x31345 = 0;
    char x31344 = ' ';
    while (1) {
      fscanf(x31312,"%c",&x31344);
      if (x31344=='|' || x31344=='\n') break;
      if (x31345>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x31345); break;}
      ((char*)x31343)[x31345] = x31344;
      x31345 += 1;
    }
    ((char*)x31343)[x31345] = '\0';
    char* x31348 = (char*)malloc(16 * sizeof(char));
    int x31350 = 0;
    char x31349 = ' ';
    while (1) {
      fscanf(x31312,"%c",&x31349);
      if (x31349=='|' || x31349=='\n') break;
      if (x31350>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x31350); break;}
      ((char*)x31348)[x31350] = x31349;
      x31350 += 1;
    }
    ((char*)x31348)[x31350] = '\0';
    int x31353 = 0;
    if (fscanf(x31312,"%d|",&x31353) == EOF) break;
    char* x31354 = (char*)malloc(80 * sizeof(char));
    int x31356 = 0;
    char x31355 = ' ';
    while (1) {
      fscanf(x31312,"%c",&x31355);
      if (x31355=='|' || x31355=='\n') break;
      if (x31356>=79) { printf("ERROR: scanner.nextString reading past end of buffer %d",x31356); break;}
      ((char*)x31354)[x31356] = x31355;
      x31356 += 1;
    }
    ((char*)x31354)[x31356] = '\0';
    int x31359 = x31314;
    int x31360 = x31313;
    bool x31361 = x31359 == x31360;
    if (x31361) {
      int x31362 = x31360 * 4;
      x31313 = x31362;
      printf("buffer.resize %d\n",x31362);
      int* x31365 = x31316;
      int* x31366 = (int*)realloc(x31365,x31362 * sizeof(int));
      x31316 = x31366;
      int* x31368 = x31318;
      int* x31369 = (int*)realloc(x31368,x31362 * sizeof(int));
      x31318 = x31369;
      double* x31374 = x31322;
      double* x31375 = (double*)realloc(x31374,x31362 * sizeof(double));
      x31322 = x31375;
      long* x31377 = x31324;
      long* x31378 = (long*)realloc(x31377,x31362 * sizeof(long));
      x31324 = x31378;
    } else {
    }
    int* x31394 = x31316;
    x31394[x31359] = x31335;
    int* x31396 = x31318;
    x31396[x31359] = x31336;
    double* x31400 = x31322;
    x31400[x31359] = x31338;
    long* x31402 = x31324;
    x31402[x31359] = x31342;
    x31314 = x31314 + 1;
  }
  FILE* x31416 = fopen("../databases/sf2/customer.tbl", "r");
  int x31417 = 1048576;
  int x31418 = 0;
  int* x31419 = (int*)malloc(1048576 * sizeof(int));
  int* x31420 = x31419;
  char** x31421 = (char**)malloc(1048576 * sizeof(char*));
  char** x31422 = x31421;
  for (;;) {
    bool x31435 = !feof(x31416);
    if (!x31435) break;
    int x31437 = 0;
    if (fscanf(x31416,"%d|",&x31437) == EOF) break;
    char* x31438 = (char*)malloc(26 * sizeof(char));
    int x31440 = 0;
    char x31439 = ' ';
    while (1) {
      fscanf(x31416,"%c",&x31439);
      if (x31439=='|' || x31439=='\n') break;
      if (x31440>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x31440); break;}
      ((char*)x31438)[x31440] = x31439;
      x31440 += 1;
    }
    ((char*)x31438)[x31440] = '\0';
    char* x31442 = x31438; // unsafe immutable;
    char* x31443 = (char*)malloc(41 * sizeof(char));
    int x31445 = 0;
    char x31444 = ' ';
    while (1) {
      fscanf(x31416,"%c",&x31444);
      if (x31444=='|' || x31444=='\n') break;
      if (x31445>=40) { printf("ERROR: scanner.nextString reading past end of buffer %d",x31445); break;}
      ((char*)x31443)[x31445] = x31444;
      x31445 += 1;
    }
    ((char*)x31443)[x31445] = '\0';
    int x31448 = 0;
    if (fscanf(x31416,"%d|",&x31448) == EOF) break;
    char* x31449 = (char*)malloc(16 * sizeof(char));
    int x31451 = 0;
    char x31450 = ' ';
    while (1) {
      fscanf(x31416,"%c",&x31450);
      if (x31450=='|' || x31450=='\n') break;
      if (x31451>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x31451); break;}
      ((char*)x31449)[x31451] = x31450;
      x31451 += 1;
    }
    ((char*)x31449)[x31451] = '\0';
    double x31454 = 0.0;
    if (fscanf(x31416,"%lf|",&x31454) == EOF) break;
    char* x31455 = (char*)malloc(11 * sizeof(char));
    int x31457 = 0;
    char x31456 = ' ';
    while (1) {
      fscanf(x31416,"%c",&x31456);
      if (x31456=='|' || x31456=='\n') break;
      if (x31457>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x31457); break;}
      ((char*)x31455)[x31457] = x31456;
      x31457 += 1;
    }
    ((char*)x31455)[x31457] = '\0';
    char* x31460 = (char*)malloc(118 * sizeof(char));
    int x31462 = 0;
    char x31461 = ' ';
    while (1) {
      fscanf(x31416,"%c",&x31461);
      if (x31461=='|' || x31461=='\n') break;
      if (x31462>=117) { printf("ERROR: scanner.nextString reading past end of buffer %d",x31462); break;}
      ((char*)x31460)[x31462] = x31461;
      x31462 += 1;
    }
    ((char*)x31460)[x31462] = '\0';
    int x31465 = x31418;
    int x31466 = x31417;
    bool x31467 = x31465 == x31466;
    if (x31467) {
      int x31468 = x31466 * 4;
      x31417 = x31468;
      printf("buffer.resize %d\n",x31468);
      int* x31471 = x31420;
      int* x31472 = (int*)realloc(x31471,x31468 * sizeof(int));
      x31420 = x31472;
      char** x31474 = x31422;
      char** x31475 = (char**)realloc(x31474,x31468 * sizeof(char*));
      x31422 = x31475;
    } else {
    }
    int* x31497 = x31420;
    x31497[x31465] = x31437;
    char** x31499 = x31422;
    x31499[x31465] = x31442;
    x31418 = x31418 + 1;
  }
  GTree* x31525 = g_tree_new((GCompareFunc)x32169);;
  float x30714 = (float)300;
  double x30715 = (double)x30714;
  int x30723 = 777 & 1048575;
  int x30443;
  for(x30443=0; x30443 < 1; x30443++) {
    bool x31526 = false;
    int x31527 = 0;
    bool x31528 = false;
    int x31529 = 0;
    bool x31530 = false;
    int x31531 = 0;
    int x31533 = 1048576;
    int x31534 = 0;
    int* x31535 = (int*)malloc(1048576 * sizeof(int));
    int* x31536 = x31535;
    double* x31537 = (double*)malloc(1048576 * sizeof(double));
    double* x31538 = x31537;
    int x31539 = 4194304;
    int x31540 = 0;
    int* x31541 = (int*)malloc(4194304 * sizeof(int));
    int* x31542 = x31541;
    int x30461;
    for(x30461=0; x30461 < 4194304; x30461++) {
      int* x31543 = x31542;
      x31543[x30461] = -1;
    }
    int* x31551 = (int*)malloc(1073741824 * sizeof(int));
    int* x31552 = x31551;
    double* x31553 = (double*)malloc(1073741824 * sizeof(double));
    double* x31554 = x31553;
    int x31555 = 0;
    int* x31556 = (int*)malloc(1048576 * sizeof(int));
    int* x31557 = (int*)malloc(1073741824 * sizeof(int));
    int x30477;
    for(x30477=0; x30477 < 1048576; x30477++) {
      x31556[x30477] = -1;
    }
    double* x31565 = (double*)malloc(1073741824 * sizeof(double));
    double* x31566 = x31565;
    int* x31567 = (int*)malloc(1073741824 * sizeof(int));
    int* x31568 = x31567;
    int* x31569 = (int*)malloc(1073741824 * sizeof(int));
    int* x31570 = x31569;
    double* x31573 = (double*)malloc(1073741824 * sizeof(double));
    double* x31574 = x31573;
    long* x31575 = (long*)malloc(1073741824 * sizeof(long));
    long* x31576 = x31575;
    int x31585 = 0;
    int* x31586 = (int*)malloc(1048576 * sizeof(int));
    int* x31587 = (int*)malloc(1073741824 * sizeof(int));
    int x30508;
    for(x30508=0; x30508 < 1048576; x30508++) {
      x31586[x30508] = -1;
    }
    int x31593 = 1048576;
    int x31594 = 0;
    char** x31595 = (char**)malloc(1048576 * sizeof(char*));
    char** x31596 = x31595;
    int* x31597 = (int*)malloc(1048576 * sizeof(int));
    int* x31598 = x31597;
    int* x31599 = (int*)malloc(1048576 * sizeof(int));
    int* x31600 = x31599;
    long* x31601 = (long*)malloc(1048576 * sizeof(long));
    long* x31602 = x31601;
    double* x31603 = (double*)malloc(1048576 * sizeof(double));
    double* x31604 = x31603;
    double* x31605 = (double*)malloc(1048576 * sizeof(double));
    double* x31606 = x31605;
    int x31607 = 4194304;
    int x31608 = 0;
    int* x31609 = (int*)malloc(4194304 * sizeof(int));
    int* x31610 = x31609;
    int x30532;
    for(x30532=0; x30532 < 4194304; x30532++) {
      int* x31611 = x31610;
      x31611[x30532] = -1;
    }
    int x31618 = 0;
    int x31620 = 0;
    struct timeval x31125, x31126, x32162;
    gettimeofday(&x31125, NULL);
    printf("((AGG(LINEITEM) X ORDERS) X CUSTOMER): leftParent.next start\n");
    struct timeval x30830, x30831, x31876;
    gettimeofday(&x30830, NULL);
    printf("(AGG(LINEITEM) X ORDERS): leftParent.next start\n");
    struct timeval x30733, x30734, x31785;
    gettimeofday(&x30733, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x31624 = x31530;
      bool x31625 = !x31624;
      bool x31630 = x31625;
      if (x31625) {
        int x31626 = x31531;
        int x31627 = x31148;
        bool x31628 = x31626 < x31627;
        x31630 = x31628;
      }
      bool x31631 = x31630;
      if (!x31631) break;
      int x31634 = x31531;
      int* x31635 = x31150;
      int x31636 = x31635[x31634];
      double* x31643 = x31158;
      double x31644 = x31643[x31634];
      x31531 = x31531 + 1;
      int x31669 = x31539;
      int x31670 = x31669 - 1;
      int x31671 = x31636 * 2;
      int x31672 = x31671 * 3;
      int x31673 = x31672 & x31670;
      int x31674 = x31673;
      int* x31675 = x31542;
      int x31676 = x31675[x31673];
      int x31677 = x31676;
      int x31678 = x31673 + 1;
      int x31679 = x31675[x31678];
      int x31680 = x31679;
      for (;;) {
        int x31681 = x31677;
        bool x31682 = x31681 != -1;
        bool x31698 = x31682;
        if (x31682) {
          int x31683 = x31680;
          bool x31684 = x31683 != x31672;
          bool x31694 = x31684;
          if (x31684 == false) {
            int x31685 = x31677;
            int* x31686 = x31536;
            int x31687 = x31686[x31685];
            bool x31690 = x31687 == x31636;
            bool x31691 = !x31690;
            x31694 = x31691;
          }
          bool x31695 = x31694;
          x31698 = x31695;
        }
        bool x31699 = x31698;
        if (!x31699) break;
        int x31702 = x31674;
        int x31703 = x31702 + 2;
        int x31704 = x31703 & x31670;
        x31674 = x31704;
        int* x31706 = x31542;
        int x31707 = x31706[x31704];
        x31677 = x31707;
        int x31709 = x31704 + 1;
        int x31710 = x31706[x31709];
        x31680 = x31710;
      }
      int x31715 = x31677;
      bool x31716 = x31715 == -1;
      int x31751;
      if (x31716) {
        int x31717 = x31540;
        int x31718 = x31674;
        x31675[x31718] = x31717;
        int x31720 = x31718 + 1;
        x31675[x31720] = x31672;
        x31540 = x31540 + 1;
        int x31723 = x31534;
        int x31724 = x31533;
        bool x31725 = x31723 == x31724;
        if (x31725) {
          int x31726 = x31724 * 4;
          x31533 = x31726;
          printf("buffer.resize %d\n",x31726);
          int* x31729 = x31536;
          int* x31730 = (int*)realloc(x31729,x31726 * sizeof(int));
          x31536 = x31730;
          printf("buffer.resize %d\n",x31726);
          double* x31733 = x31538;
          double* x31734 = (double*)realloc(x31733,x31726 * sizeof(double));
          x31538 = x31734;
        } else {
        }
        int* x31738 = x31536;
        x31738[x31723] = x31636;
        double* x31740 = x31538;
        x31740[x31723] = 0.0;
        x31534 = x31534 + 1;
        int x31743 = x31540;
        int x31744 = x31743 * 4;
        bool x31745 = x31744 > x31669;
        if (x31745) {
          printf("%s\n","ERROR: hash.resize not implemented");
        } else {
        }
        x31751 = x31717;
      } else {
        x31751 = x31715;
      }
      int* x31752 = x31536;
      int x31753 = x31752[x31751];
      double* x31754 = x31538;
      double x31755 = x31754[x31751];
      x31752[x31751] = x31753;
      double x31757 = x31755 + x31644;
      x31754[x31751] = x31757;
    }
    int x31762 = x31534;
    int x30707;
    for(x30707=0; x30707 < x31762; x30707++) {
      int* x31763 = x31536;
      int x31764 = x31763[x30707];
      double* x31765 = x31538;
      double x31766 = x31765[x30707];
      bool x31767 = x31766 > x30715;
      if (x31767) {
        int x31768 = x31555;
        int* x31769 = x31552;
        x31769[x31768] = x31764;
        double* x31771 = x31554;
        x31771[x31768] = x31766;
        x31555 = x31555 + 1;
        int x31774 = x31556[x30723];
        x31556[x30723] = x31768;
        x31557[x31768] = x31774;
      } else {
      }
    }
    printf("(AGG(LINEITEM) X ORDERS): leftParent.next done\n");
    gettimeofday(&x30734, NULL);
    timeval_subtract(&x31785, &x30734, &x30733);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x31785.tv_sec * 1000) + (x31785.tv_usec/1000)));
    printf("(AGG(LINEITEM) X ORDERS): rightParent.next start\n");
    struct timeval x30824, x30825, x31871;
    gettimeofday(&x30824, NULL);
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x31789 = x31526;
      bool x31790 = !x31789;
      bool x31795 = x31790;
      if (x31790) {
        int x31791 = x31527;
        int x31792 = x31314;
        bool x31793 = x31791 < x31792;
        x31795 = x31793;
      }
      bool x31796 = x31795;
      if (!x31796) break;
      int x31799 = x31527;
      int* x31800 = x31316;
      int x31801 = x31800[x31799];
      int* x31802 = x31318;
      int x31803 = x31802[x31799];
      double* x31806 = x31322;
      double x31807 = x31806[x31799];
      long* x31808 = x31324;
      long x31809 = x31808[x31799];
      x31527 = x31527 + 1;
      int x31819 = x31556[x30723];
      int x31820 = x31819;
      int x31821 = x31803 & 1048575;
      for (;;) {
        int x31822 = x31820;
        bool x31823 = x31822 != -1;
        if (!x31823) break;
        int x31825 = x31820;
        int* x31826 = x31552;
        int x31827 = x31826[x31825];
        double* x31828 = x31554;
        double x31829 = x31828[x31825];
        int x31830 = x31557[x31825];
        x31820 = x31830;
        bool x31832 = x31801 == x31827;
        if (x31832) {
          int x31833 = x31585;
          double* x31836 = x31566;
          x31836[x31833] = x31829;
          int* x31838 = x31568;
          x31838[x31833] = x31801;
          int* x31840 = x31570;
          x31840[x31833] = x31803;
          double* x31844 = x31574;
          x31844[x31833] = x31807;
          long* x31846 = x31576;
          x31846[x31833] = x31809;
          x31585 = x31585 + 1;
          int x31857 = x31586[x31821];
          x31586[x31821] = x31833;
          x31587[x31833] = x31857;
        } else {
        }
      }
    }
    printf("(AGG(LINEITEM) X ORDERS): rightParent.next done\n");
    gettimeofday(&x30825, NULL);
    timeval_subtract(&x31871, &x30825, &x30824);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x31871.tv_sec * 1000) + (x31871.tv_usec/1000)));
    printf("((AGG(LINEITEM) X ORDERS) X CUSTOMER): leftParent.next done\n");
    gettimeofday(&x30831, NULL);
    timeval_subtract(&x31876, &x30831, &x30830);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x31876.tv_sec * 1000) + (x31876.tv_usec/1000)));
    printf("((AGG(LINEITEM) X ORDERS) X CUSTOMER): rightParent.next start\n");
    struct timeval x31071, x31072, x32110;
    gettimeofday(&x31071, NULL);
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x31880 = x31528;
      bool x31881 = !x31880;
      bool x31886 = x31881;
      if (x31881) {
        int x31882 = x31529;
        int x31883 = x31418;
        bool x31884 = x31882 < x31883;
        x31886 = x31884;
      }
      bool x31887 = x31886;
      if (!x31887) break;
      int x31890 = x31529;
      int* x31891 = x31420;
      int x31892 = x31891[x31890];
      char** x31893 = x31422;
      char* x31894 = x31893[x31890];
      x31529 = x31529 + 1;
      int x31908 = x31892 & 1048575;
      int x31909 = x31586[x31908];
      int x31910 = x31909;
      char x31911 = x31894[0];
      int x31912 = x31892 * 41;
      int x31913 = x31912 + x31911;
      int x31914 = x31913 * 41;
      for (;;) {
        int x31915 = x31910;
        bool x31916 = x31915 != -1;
        if (!x31916) break;
        int x31918 = x31910;
        double* x31921 = x31566;
        double x31922 = x31921[x31918];
        int* x31923 = x31568;
        int x31924 = x31923[x31918];
        int* x31925 = x31570;
        int x31926 = x31925[x31918];
        double* x31929 = x31574;
        double x31930 = x31929[x31918];
        long* x31931 = x31576;
        long x31932 = x31931[x31918];
        int x31941 = x31587[x31918];
        x31910 = x31941;
        bool x31943 = x31926 == x31892;
        if (x31943) {
          int x31945 = x31607;
          int x31946 = x31945 - 1;
          int x31947 = (int)x31932;
          int x31948 = x31914 + x31947;
          int x31949 = x31948 * 41;
          int x31950 = x31949 + x31924;
          int x31951 = x31950 * 41;
          int x31952 = x31951 + 777;
          int x31953 = x31952 * 2;
          int x31954 = x31953 * 3;
          int x31955 = x31954 & x31946;
          int x31956 = x31955;
          int* x31957 = x31610;
          int x31958 = x31957[x31955];
          int x31959 = x31958;
          int x31960 = x31955 + 1;
          int x31961 = x31957[x31960];
          int x31962 = x31961;
          for (;;) {
            int x31963 = x31959;
            bool x31964 = x31963 != -1;
            bool x32004 = x31964;
            if (x31964) {
              int x31965 = x31962;
              bool x31966 = x31965 != x31954;
              bool x32000 = x31966;
              if (x31966 == false) {
                int x31967 = x31959;
                char** x31968 = x31596;
                char* x31969 = x31968[x31967];
                int* x31970 = x31598;
                int x31971 = x31970[x31967];
                int* x31972 = x31600;
                int x31973 = x31972[x31967];
                long* x31974 = x31602;
                long x31975 = x31974[x31967];
                double* x31976 = x31604;
                double x31977 = x31976[x31967];
                bool x31980 = strcmp(x31969,x31894) == 0;;
                bool x31983 = x31980;
                if (x31980) {
                  bool x31981 = x31971 == x31892;
                  x31983 = x31981;
                }
                bool x31984 = x31983;
                bool x31987 = x31984;
                if (x31984) {
                  bool x31985 = x31973 == x31924;
                  x31987 = x31985;
                }
                bool x31988 = x31987;
                bool x31991 = x31988;
                if (x31988) {
                  bool x31989 = x31975 == x31932;
                  x31991 = x31989;
                }
                bool x31992 = x31991;
                bool x31995 = x31992;
                if (x31992) {
                  bool x31993 = x31977 == x31930;
                  x31995 = x31993;
                }
                bool x31996 = x31995;
                bool x31997 = !x31996;
                x32000 = x31997;
              }
              bool x32001 = x32000;
              x32004 = x32001;
            }
            bool x32005 = x32004;
            if (!x32005) break;
            int x32008 = x31956;
            int x32009 = x32008 + 2;
            int x32010 = x32009 & x31946;
            x31956 = x32010;
            int* x32012 = x31610;
            int x32013 = x32012[x32010];
            x31959 = x32013;
            int x32015 = x32010 + 1;
            int x32016 = x32012[x32015];
            x31962 = x32016;
          }
          int x32021 = x31959;
          bool x32022 = x32021 == -1;
          int x32078;
          if (x32022) {
            int x32023 = x31608;
            int x32024 = x31956;
            x31957[x32024] = x32023;
            int x32026 = x32024 + 1;
            x31957[x32026] = x31954;
            x31608 = x31608 + 1;
            int x32029 = x31594;
            int x32030 = x31593;
            bool x32031 = x32029 == x32030;
            if (x32031) {
              int x32032 = x32030 * 4;
              x31593 = x32032;
              printf("buffer.resize %d\n",x32032);
              printf("buffer.resize %d\n",x32032);
              char** x32036 = x31596;
              char** x32037 = (char**)realloc(x32036,x32032 * sizeof(char*));
              x31596 = x32037;
              int* x32039 = x31598;
              int* x32040 = (int*)realloc(x32039,x32032 * sizeof(int));
              x31598 = x32040;
              int* x32042 = x31600;
              int* x32043 = (int*)realloc(x32042,x32032 * sizeof(int));
              x31600 = x32043;
              long* x32045 = x31602;
              long* x32046 = (long*)realloc(x32045,x32032 * sizeof(long));
              x31602 = x32046;
              double* x32048 = x31604;
              double* x32049 = (double*)realloc(x32048,x32032 * sizeof(double));
              x31604 = x32049;
              printf("buffer.resize %d\n",x32032);
              double* x32052 = x31606;
              double* x32053 = (double*)realloc(x32052,x32032 * sizeof(double));
              x31606 = x32053;
            } else {
            }
            char** x32057 = x31596;
            x32057[x32029] = x31894;
            int* x32059 = x31598;
            x32059[x32029] = x31892;
            int* x32061 = x31600;
            x32061[x32029] = x31924;
            long* x32063 = x31602;
            x32063[x32029] = x31932;
            double* x32065 = x31604;
            x32065[x32029] = x31930;
            double* x32067 = x31606;
            x32067[x32029] = 0.0;
            x31594 = x31594 + 1;
            int x32070 = x31608;
            int x32071 = x32070 * 4;
            bool x32072 = x32071 > x31945;
            if (x32072) {
              printf("%s\n","ERROR: hash.resize not implemented");
            } else {
            }
            x32078 = x32023;
          } else {
            x32078 = x32021;
          }
          char** x32079 = x31596;
          char* x32080 = x32079[x32078];
          int* x32081 = x31598;
          int x32082 = x32081[x32078];
          int* x32083 = x31600;
          int x32084 = x32083[x32078];
          long* x32085 = x31602;
          long x32086 = x32085[x32078];
          double* x32087 = x31604;
          double x32088 = x32087[x32078];
          double* x32089 = x31606;
          double x32090 = x32089[x32078];
          x32079[x32078] = x32080;
          x32081[x32078] = x32082;
          x32083[x32078] = x32084;
          x32085[x32078] = x32086;
          x32087[x32078] = x32088;
          double x32096 = x32090 + x31922;
          x32089[x32078] = x32096;
        } else {
        }
      }
    }
    printf("((AGG(LINEITEM) X ORDERS) X CUSTOMER): rightParent.next done\n");
    gettimeofday(&x31072, NULL);
    timeval_subtract(&x32110, &x31072, &x31071);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x32110.tv_sec * 1000) + (x32110.tv_usec/1000)));
    int x32112 = x31594;
    int x31077;
    for(x31077=0; x31077 < x32112; x31077++) {
      char** x32113 = x31596;
      char* x32114 = x32113[x31077];
      int* x32115 = x31598;
      int x32116 = x32115[x31077];
      int* x32117 = x31600;
      int x32118 = x32117[x31077];
      long* x32119 = x31602;
      long x32120 = x32119[x31077];
      double* x32121 = x31604;
      double x32122 = x32121[x31077];
      double* x32123 = x31606;
      double x32124 = x32123[x31077];
      struct Anon1621811895* x32125 = (struct Anon1621811895*)malloc(sizeof(struct Anon1621811895));
      x32125->C_NAME = x32114;
      x32125->C_CUSTKEY = x32116;
      x32125->O_ORDERKEY = x32118;
      x32125->O_ORDERDATE = x32120;
      x32125->O_TOTALPRICE = x32122;
      struct Anon2052879266* x32126 = (struct Anon2052879266*)malloc(sizeof(struct Anon2052879266));
      x32126->_0 = x32124;
      struct Anon1826514910* x32127 = (struct Anon1826514910*)malloc(sizeof(struct Anon1826514910));
      x32127->key = x32125;
      x32127->aggs = x32126;
      g_tree_insert(x31525,x32127,x32127);; // x32128
    }
    for (;;) {
      int x32131 = g_tree_nnodes(x31525);
      bool x32132 = x32131 != 0;
      if (!x32132) break;
      struct Anon1826514910* x32134 = NULL;
      g_tree_foreach(x31525, (GTraverseFunc)x32175, &x32134);
      g_tree_remove(x31525,x32134);
      int x32136 = x31618;
      bool x32137 = x32136 < 100;
      bool x32138 = x32137 == false;
      if (x32138) {
      } else {
        struct Anon1621811895* x32141 = x32134->key;;
        char* x32142 = x32141->C_NAME;;
        int x32143 = x32141->C_CUSTKEY;;
        int x32144 = x32141->O_ORDERKEY;;
        long x32145 = x32141->O_ORDERDATE;;
        char* x32146 = (char*)malloc(9 * sizeof(char));;
        snprintf(x32146, 9, "%lu", x32145);
        double x32147 = x32141->O_TOTALPRICE;;
        struct Anon2052879266* x32148 = x32134->aggs;;
        double x32149 = x32148->_0;;
        printf("%s|%d|%d|%s|%.2f|%.2f\n",x32142,x32143,x32144,x32146,x32147,x32149);
        x31618 = x31618 + 1;
        x31620 = x31620 + 1;
      }
    }
    int x32158 = x31620;
    printf("(%d rows)\n",x32158);
    gettimeofday(&x31126, NULL);
    timeval_subtract(&x32162, &x31126, &x31125);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x32162.tv_sec * 1000) + (x32162.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
