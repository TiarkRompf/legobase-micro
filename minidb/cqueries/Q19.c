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
struct Anon1043733433;
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
struct Anon102935935* left;
struct Anon168903330* right;
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

struct Anon1043733433 {
char* key;
double aggs;
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

/************************ MAIN BODY **************************/
int main(int x32176, char** x32177) {
  FILE* x32945 = fopen("../databases/sf2/lineitem.tbl", "r");
  int x32946 = 1048576;
  int x32947 = 0;
  int* x32950 = (int*)malloc(1048576 * sizeof(int));
  int* x32951 = x32950;
  double* x32956 = (double*)malloc(1048576 * sizeof(double));
  double* x32957 = x32956;
  double* x32958 = (double*)malloc(1048576 * sizeof(double));
  double* x32959 = x32958;
  double* x32960 = (double*)malloc(1048576 * sizeof(double));
  double* x32961 = x32960;
  char** x32974 = (char**)malloc(1048576 * sizeof(char*));
  char** x32975 = x32974;
  char** x32976 = (char**)malloc(1048576 * sizeof(char*));
  char** x32977 = x32976;
  for (;;) {
    bool x32980 = !feof(x32945);
    if (!x32980) break;
    int x32982 = 0;
    if (fscanf(x32945,"%d|",&x32982) == EOF) break;
    int x32983 = 0;
    if (fscanf(x32945,"%d|",&x32983) == EOF) break;
    int x32984 = 0;
    if (fscanf(x32945,"%d|",&x32984) == EOF) break;
    int x32985 = 0;
    if (fscanf(x32945,"%d|",&x32985) == EOF) break;
    double x32986 = 0.0;
    if (fscanf(x32945,"%lf|",&x32986) == EOF) break;
    double x32987 = 0.0;
    if (fscanf(x32945,"%lf|",&x32987) == EOF) break;
    double x32988 = 0.0;
    if (fscanf(x32945,"%lf|",&x32988) == EOF) break;
    double x32989 = 0.0;
    if (fscanf(x32945,"%lf|",&x32989) == EOF) break;
    char x32990 = ' ';
    if (fscanf(x32945,"%c|",&x32990) == EOF) break;
    char x32991 = ' ';
    if (fscanf(x32945,"%c|",&x32991) == EOF) break;
    int x32992 = 0;
    int x32993 = 0;
    int x32994 = 0;
    fscanf(x32945, "%d-%d-%d|",&x32992, &x32993, &x32994);
    long x32995 = (x32992 * 10000) + (x32993 * 100) + x32994;
    int x32996 = 0;
    int x32997 = 0;
    int x32998 = 0;
    fscanf(x32945, "%d-%d-%d|",&x32996, &x32997, &x32998);
    long x32999 = (x32996 * 10000) + (x32997 * 100) + x32998;
    int x33000 = 0;
    int x33001 = 0;
    int x33002 = 0;
    fscanf(x32945, "%d-%d-%d|",&x33000, &x33001, &x33002);
    long x33003 = (x33000 * 10000) + (x33001 * 100) + x33002;
    char* x33004 = (char*)malloc(26 * sizeof(char));
    int x33006 = 0;
    char x33005 = ' ';
    while (1) {
      fscanf(x32945,"%c",&x33005);
      if (x33005=='|' || x33005=='\n') break;
      if (x33006>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x33006); break;}
      ((char*)x33004)[x33006] = x33005;
      x33006 += 1;
    }
    ((char*)x33004)[x33006] = '\0';
    char* x33008 = x33004; // unsafe immutable;
    char* x33009 = (char*)malloc(11 * sizeof(char));
    int x33011 = 0;
    char x33010 = ' ';
    while (1) {
      fscanf(x32945,"%c",&x33010);
      if (x33010=='|' || x33010=='\n') break;
      if (x33011>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x33011); break;}
      ((char*)x33009)[x33011] = x33010;
      x33011 += 1;
    }
    ((char*)x33009)[x33011] = '\0';
    char* x33013 = x33009; // unsafe immutable;
    char* x33014 = (char*)malloc(45 * sizeof(char));
    int x33016 = 0;
    char x33015 = ' ';
    while (1) {
      fscanf(x32945,"%c",&x33015);
      if (x33015=='|' || x33015=='\n') break;
      if (x33016>=44) { printf("ERROR: scanner.nextString reading past end of buffer %d",x33016); break;}
      ((char*)x33014)[x33016] = x33015;
      x33016 += 1;
    }
    ((char*)x33014)[x33016] = '\0';
    int x33019 = x32947;
    int x33020 = x32946;
    bool x33021 = x33019 == x33020;
    if (x33021) {
      int x33022 = x33020 * 4;
      x32946 = x33022;
      printf("buffer.resize %d\n",x33022);
      int* x33028 = x32951;
      int* x33029 = (int*)realloc(x33028,x33022 * sizeof(int));
      x32951 = x33029;
      double* x33037 = x32957;
      double* x33038 = (double*)realloc(x33037,x33022 * sizeof(double));
      x32957 = x33038;
      double* x33040 = x32959;
      double* x33041 = (double*)realloc(x33040,x33022 * sizeof(double));
      x32959 = x33041;
      double* x33043 = x32961;
      double* x33044 = (double*)realloc(x33043,x33022 * sizeof(double));
      x32961 = x33044;
      char** x33064 = x32975;
      char** x33065 = (char**)realloc(x33064,x33022 * sizeof(char*));
      x32975 = x33065;
      char** x33067 = x32977;
      char** x33068 = (char**)realloc(x33067,x33022 * sizeof(char*));
      x32977 = x33068;
    } else {
    }
    int* x33077 = x32951;
    x33077[x33019] = x32983;
    double* x33083 = x32957;
    x33083[x33019] = x32986;
    double* x33085 = x32959;
    x33085[x33019] = x32987;
    double* x33087 = x32961;
    x33087[x33019] = x32988;
    char** x33101 = x32975;
    x33101[x33019] = x33008;
    char** x33103 = x32977;
    x33103[x33019] = x33013;
    x32947 = x32947 + 1;
  }
  FILE* x33111 = fopen("../databases/sf2/part.tbl", "r");
  int x33112 = 1048576;
  int x33113 = 0;
  int* x33114 = (int*)malloc(1048576 * sizeof(int));
  int* x33115 = x33114;
  char** x33120 = (char**)malloc(1048576 * sizeof(char*));
  char** x33121 = x33120;
  int* x33124 = (int*)malloc(1048576 * sizeof(int));
  int* x33125 = x33124;
  char** x33126 = (char**)malloc(1048576 * sizeof(char*));
  char** x33127 = x33126;
  for (;;) {
    bool x33133 = !feof(x33111);
    if (!x33133) break;
    int x33135 = 0;
    if (fscanf(x33111,"%d|",&x33135) == EOF) break;
    char* x33136 = (char*)malloc(56 * sizeof(char));
    int x33138 = 0;
    char x33137 = ' ';
    while (1) {
      fscanf(x33111,"%c",&x33137);
      if (x33137=='|' || x33137=='\n') break;
      if (x33138>=55) { printf("ERROR: scanner.nextString reading past end of buffer %d",x33138); break;}
      ((char*)x33136)[x33138] = x33137;
      x33138 += 1;
    }
    ((char*)x33136)[x33138] = '\0';
    char* x33141 = (char*)malloc(26 * sizeof(char));
    int x33143 = 0;
    char x33142 = ' ';
    while (1) {
      fscanf(x33111,"%c",&x33142);
      if (x33142=='|' || x33142=='\n') break;
      if (x33143>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x33143); break;}
      ((char*)x33141)[x33143] = x33142;
      x33143 += 1;
    }
    ((char*)x33141)[x33143] = '\0';
    char* x33146 = (char*)malloc(11 * sizeof(char));
    int x33148 = 0;
    char x33147 = ' ';
    while (1) {
      fscanf(x33111,"%c",&x33147);
      if (x33147=='|' || x33147=='\n') break;
      if (x33148>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x33148); break;}
      ((char*)x33146)[x33148] = x33147;
      x33148 += 1;
    }
    ((char*)x33146)[x33148] = '\0';
    char* x33150 = x33146; // unsafe immutable;
    char* x33151 = (char*)malloc(26 * sizeof(char));
    int x33153 = 0;
    char x33152 = ' ';
    while (1) {
      fscanf(x33111,"%c",&x33152);
      if (x33152=='|' || x33152=='\n') break;
      if (x33153>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x33153); break;}
      ((char*)x33151)[x33153] = x33152;
      x33153 += 1;
    }
    ((char*)x33151)[x33153] = '\0';
    int x33156 = 0;
    if (fscanf(x33111,"%d|",&x33156) == EOF) break;
    char* x33157 = (char*)malloc(11 * sizeof(char));
    int x33159 = 0;
    char x33158 = ' ';
    while (1) {
      fscanf(x33111,"%c",&x33158);
      if (x33158=='|' || x33158=='\n') break;
      if (x33159>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x33159); break;}
      ((char*)x33157)[x33159] = x33158;
      x33159 += 1;
    }
    ((char*)x33157)[x33159] = '\0';
    char* x33161 = x33157; // unsafe immutable;
    double x33162 = 0.0;
    if (fscanf(x33111,"%lf|",&x33162) == EOF) break;
    char* x33163 = (char*)malloc(24 * sizeof(char));
    int x33165 = 0;
    char x33164 = ' ';
    while (1) {
      fscanf(x33111,"%c",&x33164);
      if (x33164=='|' || x33164=='\n') break;
      if (x33165>=23) { printf("ERROR: scanner.nextString reading past end of buffer %d",x33165); break;}
      ((char*)x33163)[x33165] = x33164;
      x33165 += 1;
    }
    ((char*)x33163)[x33165] = '\0';
    int x33168 = x33113;
    int x33169 = x33112;
    bool x33170 = x33168 == x33169;
    if (x33170) {
      int x33171 = x33169 * 4;
      x33112 = x33171;
      printf("buffer.resize %d\n",x33171);
      int* x33174 = x33115;
      int* x33175 = (int*)realloc(x33174,x33171 * sizeof(int));
      x33115 = x33175;
      char** x33183 = x33121;
      char** x33184 = (char**)realloc(x33183,x33171 * sizeof(char*));
      x33121 = x33184;
      int* x33189 = x33125;
      int* x33190 = (int*)realloc(x33189,x33171 * sizeof(int));
      x33125 = x33190;
      char** x33192 = x33127;
      char** x33193 = (char**)realloc(x33192,x33171 * sizeof(char*));
      x33127 = x33193;
    } else {
    }
    int* x33203 = x33115;
    x33203[x33168] = x33135;
    char** x33209 = x33121;
    x33209[x33168] = x33150;
    int* x33213 = x33125;
    x33213[x33168] = x33156;
    char** x33215 = x33127;
    x33215[x33168] = x33161;
    x33113 = x33113 + 1;
  }
  bool x33225 = true == false;
  float x32679 = (float)36;
  double x32680 = (double)x32679;
  float x32682 = (float)26;
  double x32683 = (double)x32682;
  float x32687 = (float)25;
  double x32688 = (double)x32687;
  float x32690 = (float)15;
  double x32691 = (double)x32690;
  float x32697 = (float)14;
  double x32698 = (double)x32697;
  float x32700 = (float)4;
  double x32701 = (double)x32700;
  char x9501 = "Total"[0];
  int x9502 = x9501 * 2;
  int x9503 = x9502 * 3;
  int x32458;
  for(x32458=0; x32458 < 1; x32458++) {
    bool x33226 = false;
    int x33227 = 0;
    bool x33229 = false;
    int x33230 = 0;
    int* x33233 = (int*)malloc(1073741824 * sizeof(int));
    int* x33234 = x33233;
    char** x33239 = (char**)malloc(1073741824 * sizeof(char*));
    char** x33240 = x33239;
    int* x33243 = (int*)malloc(1073741824 * sizeof(int));
    int* x33244 = x33243;
    char** x33245 = (char**)malloc(1073741824 * sizeof(char*));
    char** x33246 = x33245;
    int x33251 = 0;
    int* x33252 = (int*)malloc(1048576 * sizeof(int));
    int* x33253 = (int*)malloc(1073741824 * sizeof(int));
    int x32487;
    for(x32487=0; x32487 < 1048576; x32487++) {
      x33252[x32487] = -1;
    }
    int x33260 = 1048576;
    int x33261 = 0;
    char** x33262 = (char**)malloc(1048576 * sizeof(char*));
    char** x33263 = x33262;
    double* x33264 = (double*)malloc(1048576 * sizeof(double));
    double* x33265 = x33264;
    int x33266 = 4194304;
    int x33267 = 0;
    int* x33268 = (int*)malloc(4194304 * sizeof(int));
    int* x33269 = x33268;
    int x32504;
    for(x32504=0; x32504 < 4194304; x32504++) {
      int* x33270 = x33269;
      x33270[x32504] = -1;
    }
    int x33277 = 0;
    struct timeval x32938, x32939, x33727;
    gettimeofday(&x32938, NULL);
    printf("(PART X LINEITEM): leftParent.next start\n");
    struct timeval x32629, x32630, x33415;
    gettimeofday(&x32629, NULL);
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x33280 = x33226;
      bool x33281 = !x33280;
      bool x33286 = x33281;
      if (x33281) {
        int x33282 = x33227;
        int x33283 = x33113;
        bool x33284 = x33282 < x33283;
        x33286 = x33284;
      }
      bool x33287 = x33286;
      if (!x33287) break;
      int x33290 = x33227;
      int* x33291 = x33115;
      int x33292 = x33291[x33290];
      char** x33297 = x33121;
      char* x33298 = x33297[x33290];
      int* x33301 = x33125;
      int x33302 = x33301[x33290];
      char** x33303 = x33127;
      char* x33304 = x33303[x33290];
      x33227 = x33227 + 1;
      bool x33310 = x33302 >= 1;
      bool x33333 = x33310;
      if (x33310) {
        bool x33311 = x33302 <= 5;
        bool x33314 = x33311;
        if (x33311) {
          bool x33312 = strcmp(x33298,"Brand#31") == 0;;
          x33314 = x33312;
        }
        bool x33315 = x33314;
        bool x33330 = x33315;
        if (x33315) {
          bool x33316 = strcmp(x33304,"SM BOX") == 0;;
          bool x33319 = x33316;
          if (x33316 == false) {
            bool x33317 = strcmp(x33304,"SM CASE") == 0;;
            x33319 = x33317;
          }
          bool x33320 = x33319;
          bool x33323 = x33320;
          if (x33320 == false) {
            bool x33321 = strcmp(x33304,"SM PACK") == 0;;
            x33323 = x33321;
          }
          bool x33324 = x33323;
          bool x33327 = x33324;
          if (x33324 == false) {
            bool x33325 = strcmp(x33304,"SM PKG") == 0;;
            x33327 = x33325;
          }
          bool x33328 = x33327;
          x33330 = x33328;
        }
        bool x33331 = x33330;
        x33333 = x33331;
      }
      bool x33334 = x33333;
      bool x33357 = x33334;
      if (x33334 == false) {
        bool x33335 = x33302 <= 10;
        bool x33338 = x33335;
        if (x33335) {
          bool x33336 = strcmp(x33298,"Brand#43") == 0;;
          x33338 = x33336;
        }
        bool x33339 = x33338;
        bool x33354 = x33339;
        if (x33339) {
          bool x33340 = strcmp(x33304,"MED BAG") == 0;;
          bool x33343 = x33340;
          if (x33340 == false) {
            bool x33341 = strcmp(x33304,"MED BOX") == 0;;
            x33343 = x33341;
          }
          bool x33344 = x33343;
          bool x33347 = x33344;
          if (x33344 == false) {
            bool x33345 = strcmp(x33304,"MED PACK") == 0;;
            x33347 = x33345;
          }
          bool x33348 = x33347;
          bool x33351 = x33348;
          if (x33348 == false) {
            bool x33349 = strcmp(x33304,"MED PKG") == 0;;
            x33351 = x33349;
          }
          bool x33352 = x33351;
          x33354 = x33352;
        }
        bool x33355 = x33354;
        x33357 = x33355;
      }
      bool x33358 = x33357;
      bool x33381 = x33358;
      if (x33358 == false) {
        bool x33359 = x33302 <= 15;
        bool x33362 = x33359;
        if (x33359) {
          bool x33360 = strcmp(x33298,"Brand#43") == 0;;
          x33362 = x33360;
        }
        bool x33363 = x33362;
        bool x33378 = x33363;
        if (x33363) {
          bool x33364 = strcmp(x33304,"LG BOX") == 0;;
          bool x33367 = x33364;
          if (x33364 == false) {
            bool x33365 = strcmp(x33304,"LG CASE") == 0;;
            x33367 = x33365;
          }
          bool x33368 = x33367;
          bool x33371 = x33368;
          if (x33368 == false) {
            bool x33369 = strcmp(x33304,"LG PACK") == 0;;
            x33371 = x33369;
          }
          bool x33372 = x33371;
          bool x33375 = x33372;
          if (x33372 == false) {
            bool x33373 = strcmp(x33304,"LG PKG") == 0;;
            x33375 = x33373;
          }
          bool x33376 = x33375;
          x33378 = x33376;
        }
        bool x33379 = x33378;
        x33381 = x33379;
      }
      bool x33382 = x33381;
      if (x33382) {
        int x33383 = x33251;
        int* x33384 = x33234;
        x33384[x33383] = x33292;
        char** x33390 = x33240;
        x33390[x33383] = x33298;
        int* x33394 = x33244;
        x33394[x33383] = x33302;
        char** x33396 = x33246;
        x33396[x33383] = x33304;
        x33251 = x33251 + 1;
        int x33403 = x33292 & 1048575;
        int x33404 = x33252[x33403];
        x33252[x33403] = x33383;
        x33253[x33383] = x33404;
      } else {
      }
    }
    printf("(PART X LINEITEM): leftParent.next done\n");
    gettimeofday(&x32630, NULL);
    timeval_subtract(&x33415, &x32630, &x32629);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x33415.tv_sec * 1000) + (x33415.tv_usec/1000)));
    printf("(PART X LINEITEM): rightParent.next start\n");
    struct timeval x32915, x32916, x33707;
    gettimeofday(&x32915, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x33419 = x33229;
      bool x33420 = !x33419;
      bool x33425 = x33420;
      if (x33420) {
        int x33421 = x33230;
        int x33422 = x32947;
        bool x33423 = x33421 < x33422;
        x33425 = x33423;
      }
      bool x33426 = x33425;
      if (!x33426) break;
      int x33429 = x33230;
      int* x33432 = x32951;
      int x33433 = x33432[x33429];
      double* x33438 = x32957;
      double x33439 = x33438[x33429];
      double* x33440 = x32959;
      double x33441 = x33440[x33429];
      double* x33442 = x32961;
      double x33443 = x33442[x33429];
      char** x33456 = x32975;
      char* x33457 = x33456[x33429];
      char** x33458 = x32977;
      char* x33459 = x33458[x33429];
      x33230 = x33230 + 1;
      bool x33463 = x33439 <= x32680;
      bool x33465 = x33463;
      if (x33463) {
        bool x33464 = x33439 >= x32683;
        x33465 = x33464;
      }
      bool x33466 = x33465;
      bool x33472 = x33466;
      if (x33466 == false) {
        bool x33467 = x33439 <= x32688;
        bool x33469 = x33467;
        if (x33467) {
          bool x33468 = x33439 >= x32691;
          x33469 = x33468;
        }
        bool x33470 = x33469;
        x33472 = x33470;
      }
      bool x33473 = x33472;
      bool x33479 = x33473;
      if (x33473 == false) {
        bool x33474 = x33439 <= x32698;
        bool x33476 = x33474;
        if (x33474) {
          bool x33475 = x33439 >= x32701;
          x33476 = x33475;
        }
        bool x33477 = x33476;
        x33479 = x33477;
      }
      bool x33480 = x33479;
      bool x33483 = x33480;
      if (x33480) {
        bool x33481 = strcmp(x33457,"DELIVER IN PERSON") == 0;;
        x33483 = x33481;
      }
      bool x33484 = x33483;
      bool x33491 = x33484;
      if (x33484) {
        bool x33485 = strcmp(x33459,"AIR") == 0;;
        bool x33488 = x33485;
        if (x33485 == false) {
          bool x33486 = strcmp(x33459,"AIRREG") == 0;;
          x33488 = x33486;
        }
        bool x33489 = x33488;
        x33491 = x33489;
      }
      bool x33492 = x33491;
      if (x33492) {
        int x33493 = x33433 & 1048575;
        int x33494 = x33252[x33493];
        int x33495 = x33494;
        bool x33475 = x33439 >= x32701;
        bool x33474 = x33439 <= x32698;
        bool x33468 = x33439 >= x32691;
        bool x33467 = x33439 <= x32688;
        bool x33464 = x33439 >= x32683;
        double x33496 = 1.0 - x33443;
        double x33497 = x33441 * x33496;
        for (;;) {
          int x33498 = x33495;
          bool x33499 = x33498 != -1;
          if (!x33499) break;
          int x33501 = x33495;
          int* x33502 = x33234;
          int x33503 = x33502[x33501];
          char** x33508 = x33240;
          char* x33509 = x33508[x33501];
          int* x33512 = x33244;
          int x33513 = x33512[x33501];
          char** x33514 = x33246;
          char* x33515 = x33514[x33501];
          int x33520 = x33253[x33501];
          x33495 = x33520;
          bool x33522 = x33503 == x33433;
          if (x33522) {
            bool x33523 = strcmp(x33509,"Brand#31") == 0;;
            bool x33538 = x33523;
            if (x33523) {
              bool x33524 = strcmp(x33515,"SM BOX") == 0;;
              bool x33527 = x33524;
              if (x33524 == false) {
                bool x33525 = strcmp(x33515,"SM CASE") == 0;;
                x33527 = x33525;
              }
              bool x33528 = x33527;
              bool x33531 = x33528;
              if (x33528 == false) {
                bool x33529 = strcmp(x33515,"SM PACK") == 0;;
                x33531 = x33529;
              }
              bool x33532 = x33531;
              bool x33535 = x33532;
              if (x33532 == false) {
                bool x33533 = strcmp(x33515,"SM PKG") == 0;;
                x33535 = x33533;
              }
              bool x33536 = x33535;
              x33538 = x33536;
            }
            bool x33539 = x33538;
            bool x33540 = x33539;
            if (x33539) {
              x33540 = x33475;
            }
            bool x33541 = x33540;
            bool x33542 = x33541;
            if (x33541) {
              x33542 = x33474;
            }
            bool x33543 = x33542;
            bool x33545 = x33543;
            if (x33543) {
              bool x33544 = x33513 <= 5;
              x33545 = x33544;
            }
            bool x33546 = x33545;
            bool x33572 = x33546;
            if (x33546 == false) {
              bool x33547 = strcmp(x33509,"Brand#43") == 0;;
              bool x33562 = x33547;
              if (x33547) {
                bool x33548 = strcmp(x33515,"MED BAG") == 0;;
                bool x33551 = x33548;
                if (x33548 == false) {
                  bool x33549 = strcmp(x33515,"MED BOX") == 0;;
                  x33551 = x33549;
                }
                bool x33552 = x33551;
                bool x33555 = x33552;
                if (x33552 == false) {
                  bool x33553 = strcmp(x33515,"MED PACK") == 0;;
                  x33555 = x33553;
                }
                bool x33556 = x33555;
                bool x33559 = x33556;
                if (x33556 == false) {
                  bool x33557 = strcmp(x33515,"MED PKG") == 0;;
                  x33559 = x33557;
                }
                bool x33560 = x33559;
                x33562 = x33560;
              }
              bool x33563 = x33562;
              bool x33564 = x33563;
              if (x33563) {
                x33564 = x33468;
              }
              bool x33565 = x33564;
              bool x33566 = x33565;
              if (x33565) {
                x33566 = x33467;
              }
              bool x33567 = x33566;
              bool x33569 = x33567;
              if (x33567) {
                bool x33568 = x33513 <= 10;
                x33569 = x33568;
              }
              bool x33570 = x33569;
              x33572 = x33570;
            }
            bool x33573 = x33572;
            bool x33599 = x33573;
            if (x33573 == false) {
              bool x33574 = strcmp(x33509,"Brand#43") == 0;;
              bool x33589 = x33574;
              if (x33574) {
                bool x33575 = strcmp(x33515,"LG BOX") == 0;;
                bool x33578 = x33575;
                if (x33575 == false) {
                  bool x33576 = strcmp(x33515,"LG CASE") == 0;;
                  x33578 = x33576;
                }
                bool x33579 = x33578;
                bool x33582 = x33579;
                if (x33579 == false) {
                  bool x33580 = strcmp(x33515,"LG PACK") == 0;;
                  x33582 = x33580;
                }
                bool x33583 = x33582;
                bool x33586 = x33583;
                if (x33583 == false) {
                  bool x33584 = strcmp(x33515,"LG PKG") == 0;;
                  x33586 = x33584;
                }
                bool x33587 = x33586;
                x33589 = x33587;
              }
              bool x33590 = x33589;
              bool x33591 = x33590;
              if (x33590) {
                x33591 = x33464;
              }
              bool x33592 = x33591;
              bool x33593 = x33592;
              if (x33592) {
                x33593 = x33463;
              }
              bool x33594 = x33593;
              bool x33596 = x33594;
              if (x33594) {
                bool x33595 = x33513 <= 15;
                x33596 = x33595;
              }
              bool x33597 = x33596;
              x33599 = x33597;
            }
            bool x33600 = x33599;
            if (x33600) {
              int x33602 = x33266;
              int x33603 = x33602 - 1;
              int x33604 = x9503 & x33603;
              int x33605 = x33604;
              int* x33606 = x33269;
              int x33607 = x33606[x33604];
              int x33608 = x33607;
              int x33609 = x33604 + 1;
              int x33610 = x33606[x33609];
              int x33611 = x33610;
              for (;;) {
                int x33612 = x33608;
                bool x33613 = x33612 != -1;
                bool x33629 = x33613;
                if (x33613) {
                  int x33614 = x33611;
                  bool x33615 = x33614 != x9503;
                  bool x33625 = x33615;
                  if (x33615 == false) {
                    int x33616 = x33608;
                    char** x33617 = x33263;
                    char* x33618 = x33617[x33616];
                    bool x33621 = strcmp(x33618,"Total") == 0;;
                    bool x33622 = !x33621;
                    x33625 = x33622;
                  }
                  bool x33626 = x33625;
                  x33629 = x33626;
                }
                bool x33630 = x33629;
                if (!x33630) break;
                int x33633 = x33605;
                int x33634 = x33633 + 2;
                int x33635 = x33634 & x33603;
                x33605 = x33635;
                int* x33637 = x33269;
                int x33638 = x33637[x33635];
                x33608 = x33638;
                int x33640 = x33635 + 1;
                int x33641 = x33637[x33640];
                x33611 = x33641;
              }
              int x33646 = x33608;
              bool x33647 = x33646 == -1;
              int x33681;
              if (x33647) {
                int x33648 = x33267;
                int x33649 = x33605;
                x33606[x33649] = x33648;
                int x33651 = x33649 + 1;
                x33606[x33651] = x9503;
                x33267 = x33267 + 1;
                int x33654 = x33261;
                int x33655 = x33260;
                bool x33656 = x33654 == x33655;
                if (x33656) {
                  int x33657 = x33655 * 4;
                  x33260 = x33657;
                  printf("buffer.resize %d\n",x33657);
                  char** x33660 = x33263;
                  char** x33661 = (char**)realloc(x33660,x33657 * sizeof(char*));
                  x33263 = x33661;
                  double* x33663 = x33265;
                  double* x33664 = (double*)realloc(x33663,x33657 * sizeof(double));
                  x33265 = x33664;
                } else {
                }
                char** x33668 = x33263;
                x33668[x33654] = "Total";
                double* x33670 = x33265;
                x33670[x33654] = 0.0;
                x33261 = x33261 + 1;
                int x33673 = x33267;
                int x33674 = x33673 * 4;
                bool x33675 = x33674 > x33602;
                if (x33675) {
                  printf("%s\n","ERROR: hash.resize not implemented");
                } else {
                }
                x33681 = x33648;
              } else {
                x33681 = x33646;
              }
              char** x33682 = x33263;
              char* x33683 = x33682[x33681];
              double* x33684 = x33265;
              double x33685 = x33684[x33681];
              x33682[x33681] = x33683;
              double x33687 = x33685 + x33497;
              x33684[x33681] = x33687;
            } else {
            }
          } else {
          }
        }
      } else {
      }
    }
    printf("(PART X LINEITEM): rightParent.next done\n");
    gettimeofday(&x32916, NULL);
    timeval_subtract(&x33707, &x32916, &x32915);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x33707.tv_sec * 1000) + (x33707.tv_usec/1000)));
    int x33709 = x33261;
    int x32921;
    for(x32921=0; x32921 < x33709; x32921++) {
      double* x33712 = x33265;
      double x33713 = x33712[x32921];
      if (x33225) {
      } else {
        printf("%.4f\n",x33713);
        x33277 = x33277 + 1;
      }
    }
    int x33723 = x33277;
    printf("(%d rows)\n",x33723);
    gettimeofday(&x32939, NULL);
    timeval_subtract(&x33727, &x32939, &x32938);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x33727.tv_sec * 1000) + (x33727.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
