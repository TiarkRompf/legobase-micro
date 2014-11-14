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
struct Anon1292423027;
struct Anon850505655;
struct Anon102935935Anon1395358962;
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
struct Anon318801231Anon1268892766;
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
struct Anon318801231;
struct Anon811555534Anon168903330;
struct Anon102935935Anon168903330Anon811555534;
struct Anon102935935Anon1395358962Anon168903330;
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
struct Anon1993309635;
struct Anon1406772883Anon318801231Anon1268892766;
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

struct Anon1292423027 {
int P_PARTKEY;
char* P_NAME;
char* P_MFGR;
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
char* P_CONTAINER;
double P_RETAILPRICE;
char* P_COMMENT;
int PS_PARTKEY;
int PS_SUPPKEY;
int PS_AVAILQTY;
double PS_SUPPLYCOST;
char* PS_COMMENT;
};

struct Anon850505655 {
char* REC1_N_NAME;
int REC1_N_NATIONKEY;
};

struct Anon102935935Anon1395358962 {
int P_PARTKEY;
char* P_NAME;
char* P_MFGR;
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
char* P_CONTAINER;
double P_RETAILPRICE;
char* P_COMMENT;
int PS_PARTKEY;
int PS_SUPPKEY;
int PS_AVAILQTY;
double PS_SUPPLYCOST;
char* PS_COMMENT;
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

struct Anon318801231Anon1268892766 {
struct Anon1993309635* key;
double aggs;
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
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
struct Anon1406772883* left;
struct Anon318801231Anon1268892766* right;
};

struct Anon1812879556 {
char* key;
struct Anon2052879266* aggs;
};

struct Anon318801231 {
struct Anon1993309635* key;
double aggs;
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

struct Anon102935935Anon1395358962Anon168903330 {
int P_PARTKEY;
char* P_NAME;
char* P_MFGR;
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
char* P_CONTAINER;
double P_RETAILPRICE;
char* P_COMMENT;
int PS_PARTKEY;
int PS_SUPPKEY;
int PS_AVAILQTY;
double PS_SUPPLYCOST;
char* PS_COMMENT;
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

struct Anon1993309635 {
int PS_PARTKEY;
int PS_SUPPKEY;
double PS_AVAILQTY;
};

struct Anon1406772883Anon318801231Anon1268892766 {
int N_NATIONKEY;
char* N_NAME;
int N_REGIONKEY;
char* N_COMMENT;
struct Anon1993309635* key;
double aggs;
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
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
int x36213(struct Anon1406772883Anon318801231Anon1268892766* x34360, struct Anon1406772883Anon318801231Anon1268892766* x34359);
int x36219(struct Anon1406772883Anon318801231Anon1268892766* x36214, struct Anon1406772883Anon318801231Anon1268892766* x36215, struct Anon1406772883Anon318801231Anon1268892766** x36216);
int x36213(struct Anon1406772883Anon318801231Anon1268892766* x34360, struct Anon1406772883Anon318801231Anon1268892766* x34359) {
  char* x34361 = x34359->S_NAME;;
  char* x34362 = x34360->S_NAME;;
  int x34363 = strcmp(x34361,x34362);
  return x34363;
}
int x36219(struct Anon1406772883Anon318801231Anon1268892766* x36214, struct Anon1406772883Anon318801231Anon1268892766* x36215, struct Anon1406772883Anon318801231Anon1268892766** x36216) {
  *x36216 = x36215;
  return 0;
}

/************************ MAIN BODY **************************/
int main(int x33734, char** x33735) {
  FILE* x34989 = fopen("../databases/sf2/part.tbl", "r");
  int x34990 = 1048576;
  int x34991 = 0;
  int* x34992 = (int*)malloc(1048576 * sizeof(int));
  int* x34993 = x34992;
  char** x34994 = (char**)malloc(1048576 * sizeof(char*));
  char** x34995 = x34994;
  for (;;) {
    bool x35011 = !feof(x34989);
    if (!x35011) break;
    int x35013 = 0;
    if (fscanf(x34989,"%d|",&x35013) == EOF) break;
    char* x35014 = (char*)malloc(56 * sizeof(char));
    int x35016 = 0;
    char x35015 = ' ';
    while (1) {
      fscanf(x34989,"%c",&x35015);
      if (x35015=='|' || x35015=='\n') break;
      if (x35016>=55) { printf("ERROR: scanner.nextString reading past end of buffer %d",x35016); break;}
      ((char*)x35014)[x35016] = x35015;
      x35016 += 1;
    }
    ((char*)x35014)[x35016] = '\0';
    char* x35018 = x35014; // unsafe immutable;
    char* x35019 = (char*)malloc(26 * sizeof(char));
    int x35021 = 0;
    char x35020 = ' ';
    while (1) {
      fscanf(x34989,"%c",&x35020);
      if (x35020=='|' || x35020=='\n') break;
      if (x35021>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x35021); break;}
      ((char*)x35019)[x35021] = x35020;
      x35021 += 1;
    }
    ((char*)x35019)[x35021] = '\0';
    char* x35024 = (char*)malloc(11 * sizeof(char));
    int x35026 = 0;
    char x35025 = ' ';
    while (1) {
      fscanf(x34989,"%c",&x35025);
      if (x35025=='|' || x35025=='\n') break;
      if (x35026>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x35026); break;}
      ((char*)x35024)[x35026] = x35025;
      x35026 += 1;
    }
    ((char*)x35024)[x35026] = '\0';
    char* x35029 = (char*)malloc(26 * sizeof(char));
    int x35031 = 0;
    char x35030 = ' ';
    while (1) {
      fscanf(x34989,"%c",&x35030);
      if (x35030=='|' || x35030=='\n') break;
      if (x35031>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x35031); break;}
      ((char*)x35029)[x35031] = x35030;
      x35031 += 1;
    }
    ((char*)x35029)[x35031] = '\0';
    int x35034 = 0;
    if (fscanf(x34989,"%d|",&x35034) == EOF) break;
    char* x35035 = (char*)malloc(11 * sizeof(char));
    int x35037 = 0;
    char x35036 = ' ';
    while (1) {
      fscanf(x34989,"%c",&x35036);
      if (x35036=='|' || x35036=='\n') break;
      if (x35037>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x35037); break;}
      ((char*)x35035)[x35037] = x35036;
      x35037 += 1;
    }
    ((char*)x35035)[x35037] = '\0';
    double x35040 = 0.0;
    if (fscanf(x34989,"%lf|",&x35040) == EOF) break;
    char* x35041 = (char*)malloc(24 * sizeof(char));
    int x35043 = 0;
    char x35042 = ' ';
    while (1) {
      fscanf(x34989,"%c",&x35042);
      if (x35042=='|' || x35042=='\n') break;
      if (x35043>=23) { printf("ERROR: scanner.nextString reading past end of buffer %d",x35043); break;}
      ((char*)x35041)[x35043] = x35042;
      x35043 += 1;
    }
    ((char*)x35041)[x35043] = '\0';
    int x35046 = x34991;
    int x35047 = x34990;
    bool x35048 = x35046 == x35047;
    if (x35048) {
      int x35049 = x35047 * 4;
      x34990 = x35049;
      printf("buffer.resize %d\n",x35049);
      int* x35052 = x34993;
      int* x35053 = (int*)realloc(x35052,x35049 * sizeof(int));
      x34993 = x35053;
      char** x35055 = x34995;
      char** x35056 = (char**)realloc(x35055,x35049 * sizeof(char*));
      x34995 = x35056;
    } else {
    }
    int* x35081 = x34993;
    x35081[x35046] = x35013;
    char** x35083 = x34995;
    x35083[x35046] = x35018;
    x34991 = x34991 + 1;
  }
  FILE* x35103 = fopen("../databases/sf2/nation.tbl", "r");
  int x35104 = 1048576;
  int x35105 = 0;
  int* x35106 = (int*)malloc(1048576 * sizeof(int));
  int* x35107 = x35106;
  char** x35108 = (char**)malloc(1048576 * sizeof(char*));
  char** x35109 = x35108;
  int* x35110 = (int*)malloc(1048576 * sizeof(int));
  int* x35111 = x35110;
  char** x35112 = (char**)malloc(1048576 * sizeof(char*));
  char** x35113 = x35112;
  for (;;) {
    bool x35114 = !feof(x35103);
    if (!x35114) break;
    int x35116 = 0;
    if (fscanf(x35103,"%d|",&x35116) == EOF) break;
    char* x35117 = (char*)malloc(26 * sizeof(char));
    int x35119 = 0;
    char x35118 = ' ';
    while (1) {
      fscanf(x35103,"%c",&x35118);
      if (x35118=='|' || x35118=='\n') break;
      if (x35119>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x35119); break;}
      ((char*)x35117)[x35119] = x35118;
      x35119 += 1;
    }
    ((char*)x35117)[x35119] = '\0';
    char* x35121 = x35117; // unsafe immutable;
    int x35122 = 0;
    if (fscanf(x35103,"%d|",&x35122) == EOF) break;
    char* x35123 = (char*)malloc(153 * sizeof(char));
    int x35125 = 0;
    char x35124 = ' ';
    while (1) {
      fscanf(x35103,"%c",&x35124);
      if (x35124=='|' || x35124=='\n') break;
      if (x35125>=152) { printf("ERROR: scanner.nextString reading past end of buffer %d",x35125); break;}
      ((char*)x35123)[x35125] = x35124;
      x35125 += 1;
    }
    ((char*)x35123)[x35125] = '\0';
    char* x35127 = x35123; // unsafe immutable;
    int x35128 = x35105;
    int x35129 = x35104;
    bool x35130 = x35128 == x35129;
    if (x35130) {
      int x35131 = x35129 * 4;
      x35104 = x35131;
      printf("buffer.resize %d\n",x35131);
      int* x35134 = x35107;
      int* x35135 = (int*)realloc(x35134,x35131 * sizeof(int));
      x35107 = x35135;
      char** x35137 = x35109;
      char** x35138 = (char**)realloc(x35137,x35131 * sizeof(char*));
      x35109 = x35138;
      int* x35140 = x35111;
      int* x35141 = (int*)realloc(x35140,x35131 * sizeof(int));
      x35111 = x35141;
      char** x35143 = x35113;
      char** x35144 = (char**)realloc(x35143,x35131 * sizeof(char*));
      x35113 = x35144;
    } else {
    }
    int* x35148 = x35107;
    x35148[x35128] = x35116;
    char** x35150 = x35109;
    x35150[x35128] = x35121;
    int* x35152 = x35111;
    x35152[x35128] = x35122;
    char** x35154 = x35113;
    x35154[x35128] = x35127;
    x35105 = x35105 + 1;
  }
  FILE* x35160 = fopen("../databases/sf2/supplier.tbl", "r");
  int x35161 = 1048576;
  int x35162 = 0;
  int* x35163 = (int*)malloc(1048576 * sizeof(int));
  int* x35164 = x35163;
  char** x35165 = (char**)malloc(1048576 * sizeof(char*));
  char** x35166 = x35165;
  char** x35167 = (char**)malloc(1048576 * sizeof(char*));
  char** x35168 = x35167;
  int* x35169 = (int*)malloc(1048576 * sizeof(int));
  int* x35170 = x35169;
  char** x35171 = (char**)malloc(1048576 * sizeof(char*));
  char** x35172 = x35171;
  double* x35173 = (double*)malloc(1048576 * sizeof(double));
  double* x35174 = x35173;
  char** x35175 = (char**)malloc(1048576 * sizeof(char*));
  char** x35176 = x35175;
  for (;;) {
    bool x35177 = !feof(x35160);
    if (!x35177) break;
    int x35179 = 0;
    if (fscanf(x35160,"%d|",&x35179) == EOF) break;
    char* x35180 = (char*)malloc(26 * sizeof(char));
    int x35182 = 0;
    char x35181 = ' ';
    while (1) {
      fscanf(x35160,"%c",&x35181);
      if (x35181=='|' || x35181=='\n') break;
      if (x35182>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x35182); break;}
      ((char*)x35180)[x35182] = x35181;
      x35182 += 1;
    }
    ((char*)x35180)[x35182] = '\0';
    char* x35184 = x35180; // unsafe immutable;
    char* x35185 = (char*)malloc(41 * sizeof(char));
    int x35187 = 0;
    char x35186 = ' ';
    while (1) {
      fscanf(x35160,"%c",&x35186);
      if (x35186=='|' || x35186=='\n') break;
      if (x35187>=40) { printf("ERROR: scanner.nextString reading past end of buffer %d",x35187); break;}
      ((char*)x35185)[x35187] = x35186;
      x35187 += 1;
    }
    ((char*)x35185)[x35187] = '\0';
    char* x35189 = x35185; // unsafe immutable;
    int x35190 = 0;
    if (fscanf(x35160,"%d|",&x35190) == EOF) break;
    char* x35191 = (char*)malloc(16 * sizeof(char));
    int x35193 = 0;
    char x35192 = ' ';
    while (1) {
      fscanf(x35160,"%c",&x35192);
      if (x35192=='|' || x35192=='\n') break;
      if (x35193>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x35193); break;}
      ((char*)x35191)[x35193] = x35192;
      x35193 += 1;
    }
    ((char*)x35191)[x35193] = '\0';
    char* x35195 = x35191; // unsafe immutable;
    double x35196 = 0.0;
    if (fscanf(x35160,"%lf|",&x35196) == EOF) break;
    char* x35197 = (char*)malloc(102 * sizeof(char));
    int x35199 = 0;
    char x35198 = ' ';
    while (1) {
      fscanf(x35160,"%c",&x35198);
      if (x35198=='|' || x35198=='\n') break;
      if (x35199>=101) { printf("ERROR: scanner.nextString reading past end of buffer %d",x35199); break;}
      ((char*)x35197)[x35199] = x35198;
      x35199 += 1;
    }
    ((char*)x35197)[x35199] = '\0';
    char* x35201 = x35197; // unsafe immutable;
    int x35202 = x35162;
    int x35203 = x35161;
    bool x35204 = x35202 == x35203;
    if (x35204) {
      int x35205 = x35203 * 4;
      x35161 = x35205;
      printf("buffer.resize %d\n",x35205);
      int* x35208 = x35164;
      int* x35209 = (int*)realloc(x35208,x35205 * sizeof(int));
      x35164 = x35209;
      char** x35211 = x35166;
      char** x35212 = (char**)realloc(x35211,x35205 * sizeof(char*));
      x35166 = x35212;
      char** x35214 = x35168;
      char** x35215 = (char**)realloc(x35214,x35205 * sizeof(char*));
      x35168 = x35215;
      int* x35217 = x35170;
      int* x35218 = (int*)realloc(x35217,x35205 * sizeof(int));
      x35170 = x35218;
      char** x35220 = x35172;
      char** x35221 = (char**)realloc(x35220,x35205 * sizeof(char*));
      x35172 = x35221;
      double* x35223 = x35174;
      double* x35224 = (double*)realloc(x35223,x35205 * sizeof(double));
      x35174 = x35224;
      char** x35226 = x35176;
      char** x35227 = (char**)realloc(x35226,x35205 * sizeof(char*));
      x35176 = x35227;
    } else {
    }
    int* x35231 = x35164;
    x35231[x35202] = x35179;
    char** x35233 = x35166;
    x35233[x35202] = x35184;
    char** x35235 = x35168;
    x35235[x35202] = x35189;
    int* x35237 = x35170;
    x35237[x35202] = x35190;
    char** x35239 = x35172;
    x35239[x35202] = x35195;
    double* x35241 = x35174;
    x35241[x35202] = x35196;
    char** x35243 = x35176;
    x35243[x35202] = x35201;
    x35162 = x35162 + 1;
  }
  FILE* x35249 = fopen("../databases/sf2/partsupp.tbl", "r");
  int x35250 = 1048576;
  int x35251 = 0;
  int* x35252 = (int*)malloc(1048576 * sizeof(int));
  int* x35253 = x35252;
  int* x35254 = (int*)malloc(1048576 * sizeof(int));
  int* x35255 = x35254;
  int* x35256 = (int*)malloc(1048576 * sizeof(int));
  int* x35257 = x35256;
  for (;;) {
    bool x35262 = !feof(x35249);
    if (!x35262) break;
    int x35264 = 0;
    if (fscanf(x35249,"%d|",&x35264) == EOF) break;
    int x35265 = 0;
    if (fscanf(x35249,"%d|",&x35265) == EOF) break;
    int x35266 = 0;
    if (fscanf(x35249,"%d|",&x35266) == EOF) break;
    double x35267 = 0.0;
    if (fscanf(x35249,"%lf|",&x35267) == EOF) break;
    char* x35268 = (char*)malloc(200 * sizeof(char));
    int x35270 = 0;
    char x35269 = ' ';
    while (1) {
      fscanf(x35249,"%c",&x35269);
      if (x35269=='|' || x35269=='\n') break;
      if (x35270>=199) { printf("ERROR: scanner.nextString reading past end of buffer %d",x35270); break;}
      ((char*)x35268)[x35270] = x35269;
      x35270 += 1;
    }
    ((char*)x35268)[x35270] = '\0';
    int x35273 = x35251;
    int x35274 = x35250;
    bool x35275 = x35273 == x35274;
    if (x35275) {
      int x35276 = x35274 * 4;
      x35250 = x35276;
      printf("buffer.resize %d\n",x35276);
      int* x35279 = x35253;
      int* x35280 = (int*)realloc(x35279,x35276 * sizeof(int));
      x35253 = x35280;
      int* x35282 = x35255;
      int* x35283 = (int*)realloc(x35282,x35276 * sizeof(int));
      x35255 = x35283;
      int* x35285 = x35257;
      int* x35286 = (int*)realloc(x35285,x35276 * sizeof(int));
      x35257 = x35286;
    } else {
    }
    int* x35296 = x35253;
    x35296[x35273] = x35264;
    int* x35298 = x35255;
    x35298[x35273] = x35265;
    int* x35300 = x35257;
    x35300[x35273] = x35266;
    x35251 = x35251 + 1;
  }
  FILE* x35310 = fopen("../databases/sf2/lineitem.tbl", "r");
  int x35311 = 1048576;
  int x35312 = 0;
  int* x35315 = (int*)malloc(1048576 * sizeof(int));
  int* x35316 = x35315;
  int* x35317 = (int*)malloc(1048576 * sizeof(int));
  int* x35318 = x35317;
  double* x35321 = (double*)malloc(1048576 * sizeof(double));
  double* x35322 = x35321;
  long* x35333 = (long*)malloc(1048576 * sizeof(long));
  long* x35334 = x35333;
  for (;;) {
    bool x35345 = !feof(x35310);
    if (!x35345) break;
    int x35347 = 0;
    if (fscanf(x35310,"%d|",&x35347) == EOF) break;
    int x35348 = 0;
    if (fscanf(x35310,"%d|",&x35348) == EOF) break;
    int x35349 = 0;
    if (fscanf(x35310,"%d|",&x35349) == EOF) break;
    int x35350 = 0;
    if (fscanf(x35310,"%d|",&x35350) == EOF) break;
    double x35351 = 0.0;
    if (fscanf(x35310,"%lf|",&x35351) == EOF) break;
    double x35352 = 0.0;
    if (fscanf(x35310,"%lf|",&x35352) == EOF) break;
    double x35353 = 0.0;
    if (fscanf(x35310,"%lf|",&x35353) == EOF) break;
    double x35354 = 0.0;
    if (fscanf(x35310,"%lf|",&x35354) == EOF) break;
    char x35355 = ' ';
    if (fscanf(x35310,"%c|",&x35355) == EOF) break;
    char x35356 = ' ';
    if (fscanf(x35310,"%c|",&x35356) == EOF) break;
    int x35357 = 0;
    int x35358 = 0;
    int x35359 = 0;
    fscanf(x35310, "%d-%d-%d|",&x35357, &x35358, &x35359);
    long x35360 = (x35357 * 10000) + (x35358 * 100) + x35359;
    int x35361 = 0;
    int x35362 = 0;
    int x35363 = 0;
    fscanf(x35310, "%d-%d-%d|",&x35361, &x35362, &x35363);
    long x35364 = (x35361 * 10000) + (x35362 * 100) + x35363;
    int x35365 = 0;
    int x35366 = 0;
    int x35367 = 0;
    fscanf(x35310, "%d-%d-%d|",&x35365, &x35366, &x35367);
    long x35368 = (x35365 * 10000) + (x35366 * 100) + x35367;
    char* x35369 = (char*)malloc(26 * sizeof(char));
    int x35371 = 0;
    char x35370 = ' ';
    while (1) {
      fscanf(x35310,"%c",&x35370);
      if (x35370=='|' || x35370=='\n') break;
      if (x35371>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x35371); break;}
      ((char*)x35369)[x35371] = x35370;
      x35371 += 1;
    }
    ((char*)x35369)[x35371] = '\0';
    char* x35374 = (char*)malloc(11 * sizeof(char));
    int x35376 = 0;
    char x35375 = ' ';
    while (1) {
      fscanf(x35310,"%c",&x35375);
      if (x35375=='|' || x35375=='\n') break;
      if (x35376>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x35376); break;}
      ((char*)x35374)[x35376] = x35375;
      x35376 += 1;
    }
    ((char*)x35374)[x35376] = '\0';
    char* x35379 = (char*)malloc(45 * sizeof(char));
    int x35381 = 0;
    char x35380 = ' ';
    while (1) {
      fscanf(x35310,"%c",&x35380);
      if (x35380=='|' || x35380=='\n') break;
      if (x35381>=44) { printf("ERROR: scanner.nextString reading past end of buffer %d",x35381); break;}
      ((char*)x35379)[x35381] = x35380;
      x35381 += 1;
    }
    ((char*)x35379)[x35381] = '\0';
    int x35384 = x35312;
    int x35385 = x35311;
    bool x35386 = x35384 == x35385;
    if (x35386) {
      int x35387 = x35385 * 4;
      x35311 = x35387;
      printf("buffer.resize %d\n",x35387);
      int* x35393 = x35316;
      int* x35394 = (int*)realloc(x35393,x35387 * sizeof(int));
      x35316 = x35394;
      int* x35396 = x35318;
      int* x35397 = (int*)realloc(x35396,x35387 * sizeof(int));
      x35318 = x35397;
      double* x35402 = x35322;
      double* x35403 = (double*)realloc(x35402,x35387 * sizeof(double));
      x35322 = x35403;
      long* x35420 = x35334;
      long* x35421 = (long*)realloc(x35420,x35387 * sizeof(long));
      x35334 = x35421;
    } else {
    }
    int* x35442 = x35316;
    x35442[x35384] = x35348;
    int* x35444 = x35318;
    x35444[x35384] = x35349;
    double* x35448 = x35322;
    x35448[x35384] = x35351;
    long* x35460 = x35334;
    x35460[x35384] = x35360;
    x35312 = x35312 + 1;
  }
  GTree* x35476 = g_tree_new((GCompareFunc)x36213);;
  bool x35477 = true == false;
  int x34223;
  for(x34223=0; x34223 < 1; x34223++) {
    bool x35478 = false;
    int x35479 = 0;
    bool x35481 = false;
    int x35482 = 0;
    int* x35484 = (int*)malloc(1073741824 * sizeof(int));
    int* x35485 = x35484;
    int x35502 = 0;
    int* x35503 = (int*)malloc(1048576 * sizeof(int));
    int* x35504 = (int*)malloc(1073741824 * sizeof(int));
    int x34251;
    for(x34251=0; x34251 < 1048576; x34251++) {
      x35503[x34251] = -1;
    }
    bool x35509 = false;
    int x35510 = 0;
    int* x35531 = (int*)malloc(1073741824 * sizeof(int));
    int* x35532 = x35531;
    int* x35533 = (int*)malloc(1073741824 * sizeof(int));
    int* x35534 = x35533;
    int* x35535 = (int*)malloc(1073741824 * sizeof(int));
    int* x35536 = x35535;
    int x35541 = 0;
    int* x35542 = (int*)malloc(1048576 * sizeof(int));
    int* x35543 = (int*)malloc(1073741824 * sizeof(int));
    int x34291;
    for(x34291=0; x34291 < 1048576; x34291++) {
      x35542[x34291] = -1;
    }
    int x35549 = 1048576;
    int x35550 = 0;
    int* x35551 = (int*)malloc(1048576 * sizeof(int));
    int* x35552 = x35551;
    int* x35553 = (int*)malloc(1048576 * sizeof(int));
    int* x35554 = x35553;
    double* x35555 = (double*)malloc(1048576 * sizeof(double));
    double* x35556 = x35555;
    double* x35557 = (double*)malloc(1048576 * sizeof(double));
    double* x35558 = x35557;
    int x35559 = 4194304;
    int x35560 = 0;
    int* x35561 = (int*)malloc(4194304 * sizeof(int));
    int* x35562 = x35561;
    int x34311;
    for(x34311=0; x34311 < 4194304; x34311++) {
      int* x35563 = x35562;
      x35563[x34311] = -1;
    }
    bool x35570 = false;
    int x35571 = 0;
    int* x35573 = (int*)malloc(1073741824 * sizeof(int));
    int* x35574 = x35573;
    int* x35575 = (int*)malloc(1073741824 * sizeof(int));
    int* x35576 = x35575;
    double* x35577 = (double*)malloc(1073741824 * sizeof(double));
    double* x35578 = x35577;
    double* x35579 = (double*)malloc(1073741824 * sizeof(double));
    double* x35580 = x35579;
    int x35581 = 0;
    int* x35582 = (int*)malloc(1048576 * sizeof(int));
    int* x35583 = (int*)malloc(1073741824 * sizeof(int));
    int x34333;
    for(x34333=0; x34333 < 1048576; x34333++) {
      x35582[x34333] = -1;
    }
    bool x35588 = false;
    int x35589 = 0;
    int* x35592 = (int*)malloc(1073741824 * sizeof(int));
    int* x35593 = x35592;
    char** x35594 = (char**)malloc(1073741824 * sizeof(char*));
    char** x35595 = x35594;
    int* x35596 = (int*)malloc(1073741824 * sizeof(int));
    int* x35597 = x35596;
    char** x35598 = (char**)malloc(1073741824 * sizeof(char*));
    char** x35599 = x35598;
    int x35600 = 0;
    int* x35601 = (int*)malloc(1048576 * sizeof(int));
    int* x35602 = (int*)malloc(1073741824 * sizeof(int));
    int x34353;
    for(x34353=0; x34353 < 1048576; x34353++) {
      x35601[x34353] = -1;
    }
    int x35609 = 0;
    struct timeval x34978, x34979, x36206;
    gettimeofday(&x34978, NULL);
    printf("(NATION X (AGG(((PART X PARTSUPP) X LINEITEM)) X SUPPLIER)): leftParent.next start\n");
    struct timeval x34410, x34411, x35655;
    gettimeofday(&x34410, NULL);
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x35612 = x35588;
      bool x35613 = !x35612;
      bool x35618 = x35613;
      if (x35613) {
        int x35614 = x35589;
        int x35615 = x35105;
        bool x35616 = x35614 < x35615;
        x35618 = x35616;
      }
      bool x35619 = x35618;
      if (!x35619) break;
      int x35622 = x35589;
      int* x35623 = x35107;
      int x35624 = x35623[x35622];
      char** x35625 = x35109;
      char* x35626 = x35625[x35622];
      int* x35627 = x35111;
      int x35628 = x35627[x35622];
      char** x35629 = x35113;
      char* x35630 = x35629[x35622];
      x35589 = x35589 + 1;
      bool x35632 = strcmp(x35626,"JORDAN") == 0;;
      if (x35632) {
        int x35633 = x35600;
        int* x35634 = x35593;
        x35634[x35633] = x35624;
        char** x35636 = x35595;
        x35636[x35633] = x35626;
        int* x35638 = x35597;
        x35638[x35633] = x35628;
        char** x35640 = x35599;
        x35640[x35633] = x35630;
        x35600 = x35600 + 1;
        int x35643 = x35624 & 1048575;
        int x35644 = x35601[x35643];
        x35601[x35643] = x35633;
        x35602[x35633] = x35644;
      } else {
      }
    }
    printf("(NATION X (AGG(((PART X PARTSUPP) X LINEITEM)) X SUPPLIER)): leftParent.next done\n");
    gettimeofday(&x34411, NULL);
    timeval_subtract(&x35655, &x34411, &x34410);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x35655.tv_sec * 1000) + (x35655.tv_usec/1000)));
    printf("(NATION X (AGG(((PART X PARTSUPP) X LINEITEM)) X SUPPLIER)): rightParent.next start\n");
    struct timeval x34956, x34957, x36184;
    gettimeofday(&x34956, NULL);
    printf("(AGG(((PART X PARTSUPP) X LINEITEM)) X SUPPLIER): leftParent.next start\n");
    struct timeval x34860, x34861, x36094;
    gettimeofday(&x34860, NULL);
    printf("((PART X PARTSUPP) X LINEITEM): leftParent.next start\n");
    struct timeval x34587, x34588, x35828;
    gettimeofday(&x34587, NULL);
    printf("(PART X PARTSUPP): leftParent.next start\n");
    struct timeval x34480, x34481, x35725;
    gettimeofday(&x34480, NULL);
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x35662 = x35478;
      bool x35663 = !x35662;
      bool x35668 = x35663;
      if (x35663) {
        int x35664 = x35479;
        int x35665 = x34991;
        bool x35666 = x35664 < x35665;
        x35668 = x35666;
      }
      bool x35669 = x35668;
      if (!x35669) break;
      int x35672 = x35479;
      int* x35673 = x34993;
      int x35674 = x35673[x35672];
      char** x35675 = x34995;
      char* x35676 = x35675[x35672];
      x35479 = x35479 + 1;
      bool x35692 = strncmp(x35676,"azure", strlen("azure")) == 0;;
      if (x35692) {
        int x35693 = x35502;
        int* x35694 = x35485;
        x35694[x35693] = x35674;
        x35502 = x35502 + 1;
        int x35713 = x35674 & 1048575;
        int x35714 = x35503[x35713];
        x35503[x35713] = x35693;
        x35504[x35693] = x35714;
      } else {
      }
    }
    printf("(PART X PARTSUPP): leftParent.next done\n");
    gettimeofday(&x34481, NULL);
    timeval_subtract(&x35725, &x34481, &x34480);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x35725.tv_sec * 1000) + (x35725.tv_usec/1000)));
    printf("(PART X PARTSUPP): rightParent.next start\n");
    struct timeval x34581, x34582, x35823;
    gettimeofday(&x34581, NULL);
    printf("%s\n","begin scan PARTSUPP");
    for (;;) {
      bool x35729 = x35481;
      bool x35730 = !x35729;
      bool x35735 = x35730;
      if (x35730) {
        int x35731 = x35482;
        int x35732 = x35251;
        bool x35733 = x35731 < x35732;
        x35735 = x35733;
      }
      bool x35736 = x35735;
      if (!x35736) break;
      int x35739 = x35482;
      int* x35740 = x35253;
      int x35741 = x35740[x35739];
      int* x35742 = x35255;
      int x35743 = x35742[x35739];
      int* x35744 = x35257;
      int x35745 = x35744[x35739];
      x35482 = x35482 + 1;
      int x35751 = x35741 & 1048575;
      int x35752 = x35503[x35751];
      int x35753 = x35752;
      for (;;) {
        int x35754 = x35753;
        bool x35755 = x35754 != -1;
        if (!x35755) break;
        int x35757 = x35753;
        int* x35758 = x35485;
        int x35759 = x35758[x35757];
        int x35776 = x35504[x35757];
        x35753 = x35776;
        bool x35778 = x35759 == x35741;
        if (x35778) {
          int x35779 = x35541;
          int* x35798 = x35532;
          x35798[x35779] = x35741;
          int* x35800 = x35534;
          x35800[x35779] = x35743;
          int* x35802 = x35536;
          x35802[x35779] = x35745;
          x35541 = x35541 + 1;
          int x35809 = x35542[x35751];
          x35542[x35751] = x35779;
          x35543[x35779] = x35809;
        } else {
        }
      }
    }
    printf("(PART X PARTSUPP): rightParent.next done\n");
    gettimeofday(&x34582, NULL);
    timeval_subtract(&x35823, &x34582, &x34581);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x35823.tv_sec * 1000) + (x35823.tv_usec/1000)));
    printf("((PART X PARTSUPP) X LINEITEM): leftParent.next done\n");
    gettimeofday(&x34588, NULL);
    timeval_subtract(&x35828, &x34588, &x34587);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x35828.tv_sec * 1000) + (x35828.tv_usec/1000)));
    printf("((PART X PARTSUPP) X LINEITEM): rightParent.next start\n");
    struct timeval x34821, x34822, x36059;
    gettimeofday(&x34821, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x35832 = x35509;
      bool x35833 = !x35832;
      bool x35838 = x35833;
      if (x35833) {
        int x35834 = x35510;
        int x35835 = x35312;
        bool x35836 = x35834 < x35835;
        x35838 = x35836;
      }
      bool x35839 = x35838;
      if (!x35839) break;
      int x35842 = x35510;
      int* x35845 = x35316;
      int x35846 = x35845[x35842];
      int* x35847 = x35318;
      int x35848 = x35847[x35842];
      double* x35851 = x35322;
      double x35852 = x35851[x35842];
      long* x35863 = x35334;
      long x35864 = x35863[x35842];
      x35510 = x35510 + 1;
      bool x35876 = x35864 >= 19960101L;
      bool x35878 = x35876;
      if (x35876) {
        bool x35877 = x35864 < 19970101L;
        x35878 = x35877;
      }
      bool x35879 = x35878;
      if (x35879) {
        int x35880 = x35846 & 1048575;
        int x35881 = x35542[x35880];
        int x35882 = x35881;
        for (;;) {
          int x35883 = x35882;
          bool x35884 = x35883 != -1;
          if (!x35884) break;
          int x35886 = x35882;
          int* x35905 = x35532;
          int x35906 = x35905[x35886];
          int* x35907 = x35534;
          int x35908 = x35907[x35886];
          int* x35909 = x35536;
          int x35910 = x35909[x35886];
          int x35915 = x35543[x35886];
          x35882 = x35915;
          bool x35917 = x35906 == x35846;
          bool x35920 = x35917;
          if (x35917) {
            bool x35918 = x35908 == x35848;
            x35920 = x35918;
          }
          bool x35921 = x35920;
          if (x35921) {
            int x35923 = x35559;
            int x35924 = x35923 - 1;
            int x35925 = 31857 + x35906;
            int x35926 = x35925 * 41;
            int x35927 = x35926 + x35908;
            int x35928 = x35927 * 2;
            int x35929 = x35928 * 3;
            int x35930 = x35929 & x35924;
            int x35931 = x35930;
            int* x35932 = x35562;
            int x35933 = x35932[x35930];
            int x35934 = x35933;
            int x35935 = x35930 + 1;
            int x35936 = x35932[x35935];
            int x35937 = x35936;
            for (;;) {
              int x35938 = x35934;
              bool x35939 = x35938 != -1;
              bool x35967 = x35939;
              if (x35939) {
                int x35940 = x35937;
                bool x35941 = x35940 != x35929;
                bool x35963 = x35941;
                if (x35941 == false) {
                  int x35942 = x35934;
                  int* x35943 = x35552;
                  int x35944 = x35943[x35942];
                  int* x35945 = x35554;
                  int x35946 = x35945[x35942];
                  double* x35947 = x35556;
                  double x35948 = x35947[x35942];
                  bool x35951 = x35944 == x35906;
                  bool x35954 = x35951;
                  if (x35951) {
                    bool x35952 = x35946 == x35908;
                    x35954 = x35952;
                  }
                  bool x35955 = x35954;
                  bool x35958 = x35955;
                  if (x35955) {
                    bool x35956 = x35948 == x35910;
                    x35958 = x35956;
                  }
                  bool x35959 = x35958;
                  bool x35960 = !x35959;
                  x35963 = x35960;
                }
                bool x35964 = x35963;
                x35967 = x35964;
              }
              bool x35968 = x35967;
              if (!x35968) break;
              int x35971 = x35931;
              int x35972 = x35971 + 2;
              int x35973 = x35972 & x35924;
              x35931 = x35973;
              int* x35975 = x35562;
              int x35976 = x35975[x35973];
              x35934 = x35976;
              int x35978 = x35973 + 1;
              int x35979 = x35975[x35978];
              x35937 = x35979;
            }
            int x35984 = x35934;
            bool x35985 = x35984 == -1;
            int x36030;
            if (x35985) {
              int x35986 = x35560;
              int x35987 = x35931;
              x35932[x35987] = x35986;
              int x35989 = x35987 + 1;
              x35932[x35989] = x35929;
              x35560 = x35560 + 1;
              int x35992 = x35550;
              int x35993 = x35549;
              bool x35994 = x35992 == x35993;
              if (x35994) {
                int x35995 = x35993 * 4;
                x35549 = x35995;
                printf("buffer.resize %d\n",x35995);
                printf("buffer.resize %d\n",x35995);
                int* x35999 = x35552;
                int* x36000 = (int*)realloc(x35999,x35995 * sizeof(int));
                x35552 = x36000;
                int* x36002 = x35554;
                int* x36003 = (int*)realloc(x36002,x35995 * sizeof(int));
                x35554 = x36003;
                double* x36005 = x35556;
                double* x36006 = (double*)realloc(x36005,x35995 * sizeof(double));
                x35556 = x36006;
                double* x36008 = x35558;
                double* x36009 = (double*)realloc(x36008,x35995 * sizeof(double));
                x35558 = x36009;
              } else {
              }
              int* x36013 = x35552;
              x36013[x35992] = x35906;
              int* x36015 = x35554;
              x36015[x35992] = x35908;
              double* x36017 = x35556;
              x36017[x35992] = x35910;
              double* x36019 = x35558;
              x36019[x35992] = 0.0;
              x35550 = x35550 + 1;
              int x36022 = x35560;
              int x36023 = x36022 * 4;
              bool x36024 = x36023 > x35923;
              if (x36024) {
                printf("%s\n","ERROR: hash.resize not implemented");
              } else {
              }
              x36030 = x35986;
            } else {
              x36030 = x35984;
            }
            int* x36031 = x35552;
            int x36032 = x36031[x36030];
            int* x36033 = x35554;
            int x36034 = x36033[x36030];
            double* x36035 = x35556;
            double x36036 = x36035[x36030];
            double* x36037 = x35558;
            double x36038 = x36037[x36030];
            x36031[x36030] = x36032;
            x36033[x36030] = x36034;
            x36035[x36030] = x36036;
            double x36042 = x36038 + x35852;
            x36037[x36030] = x36042;
          } else {
          }
        }
      } else {
      }
    }
    printf("((PART X PARTSUPP) X LINEITEM): rightParent.next done\n");
    gettimeofday(&x34822, NULL);
    timeval_subtract(&x36059, &x34822, &x34821);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x36059.tv_sec * 1000) + (x36059.tv_usec/1000)));
    int x36061 = x35550;
    int x34827;
    for(x34827=0; x34827 < x36061; x34827++) {
      int* x36062 = x35552;
      int x36063 = x36062[x34827];
      int* x36064 = x35554;
      int x36065 = x36064[x34827];
      double* x36066 = x35556;
      double x36067 = x36066[x34827];
      double* x36068 = x35558;
      double x36069 = x36068[x34827];
      double x36070 = 0.5 * x36069;
      bool x36071 = x36067 > x36070;
      if (x36071) {
        int x36072 = x35581;
        int* x36073 = x35574;
        x36073[x36072] = x36063;
        int* x36075 = x35576;
        x36075[x36072] = x36065;
        double* x36077 = x35578;
        x36077[x36072] = x36067;
        double* x36079 = x35580;
        x36079[x36072] = x36069;
        x35581 = x35581 + 1;
        int x36082 = x36065 & 1048575;
        int x36083 = x35582[x36082];
        x35582[x36082] = x36072;
        x35583[x36072] = x36083;
      } else {
      }
    }
    printf("(AGG(((PART X PARTSUPP) X LINEITEM)) X SUPPLIER): leftParent.next done\n");
    gettimeofday(&x34861, NULL);
    timeval_subtract(&x36094, &x34861, &x34860);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x36094.tv_sec * 1000) + (x36094.tv_usec/1000)));
    printf("(AGG(((PART X PARTSUPP) X LINEITEM)) X SUPPLIER): rightParent.next start\n");
    struct timeval x34950, x34951, x36179;
    gettimeofday(&x34950, NULL);
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x36098 = x35570;
      bool x36099 = !x36098;
      bool x36104 = x36099;
      if (x36099) {
        int x36100 = x35571;
        int x36101 = x35162;
        bool x36102 = x36100 < x36101;
        x36104 = x36102;
      }
      bool x36105 = x36104;
      if (!x36105) break;
      int x36108 = x35571;
      int* x36109 = x35164;
      int x36110 = x36109[x36108];
      char** x36111 = x35166;
      char* x36112 = x36111[x36108];
      char** x36113 = x35168;
      char* x36114 = x36113[x36108];
      int* x36115 = x35170;
      int x36116 = x36115[x36108];
      char** x36117 = x35172;
      char* x36118 = x36117[x36108];
      double* x36119 = x35174;
      double x36120 = x36119[x36108];
      char** x36121 = x35176;
      char* x36122 = x36121[x36108];
      x35571 = x35571 + 1;
      int x36124 = x36110 & 1048575;
      int x36125 = x35582[x36124];
      int x36126 = x36125;
      int x36127 = x36116 & 1048575;
      for (;;) {
        int x36128 = x36126;
        bool x36129 = x36128 != -1;
        if (!x36129) break;
        int x36131 = x36126;
        int* x36132 = x35574;
        int x36133 = x36132[x36131];
        int* x36134 = x35576;
        int x36135 = x36134[x36131];
        double* x36136 = x35578;
        double x36137 = x36136[x36131];
        double* x36138 = x35580;
        double x36139 = x36138[x36131];
        int x36140 = x35583[x36131];
        x36126 = x36140;
        bool x36142 = x36135 == x36110;
        if (x36142) {
          int x36143 = x35601[x36127];
          int x36144 = x36143;
          struct Anon1993309635* x36145 = (struct Anon1993309635*)malloc(sizeof(struct Anon1993309635));
          x36145->PS_PARTKEY = x36133;
          x36145->PS_SUPPKEY = x36135;
          x36145->PS_AVAILQTY = x36137;
          for (;;) {
            int x36146 = x36144;
            bool x36147 = x36146 != -1;
            if (!x36147) break;
            int x36149 = x36144;
            int* x36150 = x35593;
            int x36151 = x36150[x36149];
            char** x36152 = x35595;
            char* x36153 = x36152[x36149];
            int* x36154 = x35597;
            int x36155 = x36154[x36149];
            char** x36156 = x35599;
            char* x36157 = x36156[x36149];
            int x36158 = x35602[x36149];
            x36144 = x36158;
            bool x36160 = x36151 == x36116;
            if (x36160) {
              struct Anon1406772883Anon318801231Anon1268892766* x36161 = (struct Anon1406772883Anon318801231Anon1268892766*)malloc(sizeof(struct Anon1406772883Anon318801231Anon1268892766));
              x36161->N_NATIONKEY = x36151;
              x36161->N_NAME = x36153;
              x36161->N_REGIONKEY = x36155;
              x36161->N_COMMENT = x36157;
              x36161->key = x36145;
              x36161->aggs = x36139;
              x36161->S_SUPPKEY = x36110;
              x36161->S_NAME = x36112;
              x36161->S_ADDRESS = x36114;
              x36161->S_NATIONKEY = x36116;
              x36161->S_PHONE = x36118;
              x36161->S_ACCTBAL = x36120;
              x36161->S_COMMENT = x36122;
              g_tree_insert(x35476,x36161,x36161);; // x36162
            } else {
            }
          }
        } else {
        }
      }
    }
    printf("(AGG(((PART X PARTSUPP) X LINEITEM)) X SUPPLIER): rightParent.next done\n");
    gettimeofday(&x34951, NULL);
    timeval_subtract(&x36179, &x34951, &x34950);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x36179.tv_sec * 1000) + (x36179.tv_usec/1000)));
    printf("(NATION X (AGG(((PART X PARTSUPP) X LINEITEM)) X SUPPLIER)): rightParent.next done\n");
    gettimeofday(&x34957, NULL);
    timeval_subtract(&x36184, &x34957, &x34956);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x36184.tv_sec * 1000) + (x36184.tv_usec/1000)));
    for (;;) {
      int x36186 = g_tree_nnodes(x35476);
      bool x36187 = x36186 != 0;
      if (!x36187) break;
      struct Anon1406772883Anon318801231Anon1268892766* x36189 = NULL;
      g_tree_foreach(x35476, (GTraverseFunc)x36219, &x36189);
      g_tree_remove(x35476,x36189);
      if (x35477) {
      } else {
        char* x36193 = x36189->S_NAME;;
        char* x36194 = x36189->S_ADDRESS;;
        printf("%s|%s\n",x36193,x36194);
        x35609 = x35609 + 1;
      }
    }
    int x36202 = x35609;
    printf("(%d rows)\n",x36202);
    gettimeofday(&x34979, NULL);
    timeval_subtract(&x36206, &x34979, &x34978);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x36206.tv_sec * 1000) + (x36206.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
