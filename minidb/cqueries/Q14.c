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
struct Anon713865179Anon72918141Anon1268892766Anon168903330;
struct Anon2131541195;
struct Anon1268892766;
struct Anon1406772883Anon811555534Anon920667905;
struct Anon1406772883Anon811555534Anon920667905Anon168903330;
struct Anon72918141;
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

/************************ MAIN BODY **************************/
int main(int x27295, char** x27296) {
  FILE* x27935 = fopen("../databases/sf2/lineitem.tbl", "r");
  int x27936 = 1048576;
  int x27937 = 0;
  int* x27940 = (int*)malloc(1048576 * sizeof(int));
  int* x27941 = x27940;
  double* x27948 = (double*)malloc(1048576 * sizeof(double));
  double* x27949 = x27948;
  double* x27950 = (double*)malloc(1048576 * sizeof(double));
  double* x27951 = x27950;
  long* x27958 = (long*)malloc(1048576 * sizeof(long));
  long* x27959 = x27958;
  for (;;) {
    bool x27970 = !feof(x27935);
    if (!x27970) break;
    int x27972 = 0;
    if (fscanf(x27935,"%d|",&x27972) == EOF) break;
    int x27973 = 0;
    if (fscanf(x27935,"%d|",&x27973) == EOF) break;
    int x27974 = 0;
    if (fscanf(x27935,"%d|",&x27974) == EOF) break;
    int x27975 = 0;
    if (fscanf(x27935,"%d|",&x27975) == EOF) break;
    double x27976 = 0.0;
    if (fscanf(x27935,"%lf|",&x27976) == EOF) break;
    double x27977 = 0.0;
    if (fscanf(x27935,"%lf|",&x27977) == EOF) break;
    double x27978 = 0.0;
    if (fscanf(x27935,"%lf|",&x27978) == EOF) break;
    double x27979 = 0.0;
    if (fscanf(x27935,"%lf|",&x27979) == EOF) break;
    char x27980 = ' ';
    if (fscanf(x27935,"%c|",&x27980) == EOF) break;
    char x27981 = ' ';
    if (fscanf(x27935,"%c|",&x27981) == EOF) break;
    int x27982 = 0;
    int x27983 = 0;
    int x27984 = 0;
    fscanf(x27935, "%d-%d-%d|",&x27982, &x27983, &x27984);
    long x27985 = (x27982 * 10000) + (x27983 * 100) + x27984;
    int x27986 = 0;
    int x27987 = 0;
    int x27988 = 0;
    fscanf(x27935, "%d-%d-%d|",&x27986, &x27987, &x27988);
    long x27989 = (x27986 * 10000) + (x27987 * 100) + x27988;
    int x27990 = 0;
    int x27991 = 0;
    int x27992 = 0;
    fscanf(x27935, "%d-%d-%d|",&x27990, &x27991, &x27992);
    long x27993 = (x27990 * 10000) + (x27991 * 100) + x27992;
    char* x27994 = (char*)malloc(26 * sizeof(char));
    int x27996 = 0;
    char x27995 = ' ';
    while (1) {
      fscanf(x27935,"%c",&x27995);
      if (x27995=='|' || x27995=='\n') break;
      if (x27996>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x27996); break;}
      ((char*)x27994)[x27996] = x27995;
      x27996 += 1;
    }
    ((char*)x27994)[x27996] = '\0';
    char* x27999 = (char*)malloc(11 * sizeof(char));
    int x28001 = 0;
    char x28000 = ' ';
    while (1) {
      fscanf(x27935,"%c",&x28000);
      if (x28000=='|' || x28000=='\n') break;
      if (x28001>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x28001); break;}
      ((char*)x27999)[x28001] = x28000;
      x28001 += 1;
    }
    ((char*)x27999)[x28001] = '\0';
    char* x28004 = (char*)malloc(45 * sizeof(char));
    int x28006 = 0;
    char x28005 = ' ';
    while (1) {
      fscanf(x27935,"%c",&x28005);
      if (x28005=='|' || x28005=='\n') break;
      if (x28006>=44) { printf("ERROR: scanner.nextString reading past end of buffer %d",x28006); break;}
      ((char*)x28004)[x28006] = x28005;
      x28006 += 1;
    }
    ((char*)x28004)[x28006] = '\0';
    int x28009 = x27937;
    int x28010 = x27936;
    bool x28011 = x28009 == x28010;
    if (x28011) {
      int x28012 = x28010 * 4;
      x27936 = x28012;
      printf("buffer.resize %d\n",x28012);
      int* x28018 = x27941;
      int* x28019 = (int*)realloc(x28018,x28012 * sizeof(int));
      x27941 = x28019;
      double* x28030 = x27949;
      double* x28031 = (double*)realloc(x28030,x28012 * sizeof(double));
      x27949 = x28031;
      double* x28033 = x27951;
      double* x28034 = (double*)realloc(x28033,x28012 * sizeof(double));
      x27951 = x28034;
      long* x28045 = x27959;
      long* x28046 = (long*)realloc(x28045,x28012 * sizeof(long));
      x27959 = x28046;
    } else {
    }
    int* x28067 = x27941;
    x28067[x28009] = x27973;
    double* x28075 = x27949;
    x28075[x28009] = x27977;
    double* x28077 = x27951;
    x28077[x28009] = x27978;
    long* x28085 = x27959;
    x28085[x28009] = x27985;
    x27937 = x27937 + 1;
  }
  FILE* x28101 = fopen("../databases/sf2/part.tbl", "r");
  int x28102 = 1048576;
  int x28103 = 0;
  int* x28104 = (int*)malloc(1048576 * sizeof(int));
  int* x28105 = x28104;
  char** x28112 = (char**)malloc(1048576 * sizeof(char*));
  char** x28113 = x28112;
  for (;;) {
    bool x28123 = !feof(x28101);
    if (!x28123) break;
    int x28125 = 0;
    if (fscanf(x28101,"%d|",&x28125) == EOF) break;
    char* x28126 = (char*)malloc(56 * sizeof(char));
    int x28128 = 0;
    char x28127 = ' ';
    while (1) {
      fscanf(x28101,"%c",&x28127);
      if (x28127=='|' || x28127=='\n') break;
      if (x28128>=55) { printf("ERROR: scanner.nextString reading past end of buffer %d",x28128); break;}
      ((char*)x28126)[x28128] = x28127;
      x28128 += 1;
    }
    ((char*)x28126)[x28128] = '\0';
    char* x28131 = (char*)malloc(26 * sizeof(char));
    int x28133 = 0;
    char x28132 = ' ';
    while (1) {
      fscanf(x28101,"%c",&x28132);
      if (x28132=='|' || x28132=='\n') break;
      if (x28133>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x28133); break;}
      ((char*)x28131)[x28133] = x28132;
      x28133 += 1;
    }
    ((char*)x28131)[x28133] = '\0';
    char* x28136 = (char*)malloc(11 * sizeof(char));
    int x28138 = 0;
    char x28137 = ' ';
    while (1) {
      fscanf(x28101,"%c",&x28137);
      if (x28137=='|' || x28137=='\n') break;
      if (x28138>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x28138); break;}
      ((char*)x28136)[x28138] = x28137;
      x28138 += 1;
    }
    ((char*)x28136)[x28138] = '\0';
    char* x28141 = (char*)malloc(26 * sizeof(char));
    int x28143 = 0;
    char x28142 = ' ';
    while (1) {
      fscanf(x28101,"%c",&x28142);
      if (x28142=='|' || x28142=='\n') break;
      if (x28143>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x28143); break;}
      ((char*)x28141)[x28143] = x28142;
      x28143 += 1;
    }
    ((char*)x28141)[x28143] = '\0';
    char* x28145 = x28141; // unsafe immutable;
    int x28146 = 0;
    if (fscanf(x28101,"%d|",&x28146) == EOF) break;
    char* x28147 = (char*)malloc(11 * sizeof(char));
    int x28149 = 0;
    char x28148 = ' ';
    while (1) {
      fscanf(x28101,"%c",&x28148);
      if (x28148=='|' || x28148=='\n') break;
      if (x28149>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x28149); break;}
      ((char*)x28147)[x28149] = x28148;
      x28149 += 1;
    }
    ((char*)x28147)[x28149] = '\0';
    double x28152 = 0.0;
    if (fscanf(x28101,"%lf|",&x28152) == EOF) break;
    char* x28153 = (char*)malloc(24 * sizeof(char));
    int x28155 = 0;
    char x28154 = ' ';
    while (1) {
      fscanf(x28101,"%c",&x28154);
      if (x28154=='|' || x28154=='\n') break;
      if (x28155>=23) { printf("ERROR: scanner.nextString reading past end of buffer %d",x28155); break;}
      ((char*)x28153)[x28155] = x28154;
      x28155 += 1;
    }
    ((char*)x28153)[x28155] = '\0';
    int x28158 = x28103;
    int x28159 = x28102;
    bool x28160 = x28158 == x28159;
    if (x28160) {
      int x28161 = x28159 * 4;
      x28102 = x28161;
      printf("buffer.resize %d\n",x28161);
      int* x28164 = x28105;
      int* x28165 = (int*)realloc(x28164,x28161 * sizeof(int));
      x28105 = x28165;
      char** x28176 = x28113;
      char** x28177 = (char**)realloc(x28176,x28161 * sizeof(char*));
      x28113 = x28177;
    } else {
    }
    int* x28193 = x28105;
    x28193[x28158] = x28125;
    char** x28201 = x28113;
    x28201[x28158] = x28145;
    x28103 = x28103 + 1;
  }
  bool x28215 = true == false;
  char x9501 = "Total"[0];
  int x9502 = x9501 * 2;
  int x9503 = x9502 * 3;
  float x27913 = (float)100;
  double x27914 = (double)x27913;
  int x27577;
  for(x27577=0; x27577 < 1; x27577++) {
    bool x28216 = false;
    int x28217 = 0;
    bool x28218 = false;
    int x28219 = 0;
    int* x28222 = (int*)malloc(1073741824 * sizeof(int));
    int* x28223 = x28222;
    char** x28230 = (char**)malloc(1073741824 * sizeof(char*));
    char** x28231 = x28230;
    int x28240 = 0;
    int* x28241 = (int*)malloc(1048576 * sizeof(int));
    int* x28242 = (int*)malloc(1073741824 * sizeof(int));
    int x27605;
    for(x27605=0; x27605 < 1048576; x27605++) {
      x28241[x27605] = -1;
    }
    int x28248 = 1048576;
    int x28249 = 0;
    char** x28250 = (char**)malloc(1048576 * sizeof(char*));
    char** x28251 = x28250;
    double* x28252 = (double*)malloc(1048576 * sizeof(double));
    double* x28253 = x28252;
    double* x28254 = (double*)malloc(1048576 * sizeof(double));
    double* x28255 = x28254;
    int x28256 = 4194304;
    int x28257 = 0;
    int* x28258 = (int*)malloc(4194304 * sizeof(int));
    int* x28259 = x28258;
    int x27623;
    for(x27623=0; x27623 < 4194304; x27623++) {
      int* x28260 = x28259;
      x28260[x27623] = -1;
    }
    int x28268 = 0;
    struct timeval x27928, x27929, x28553;
    gettimeofday(&x27928, NULL);
    printf("(PART X LINEITEM): leftParent.next start\n");
    struct timeval x27693, x27694, x28330;
    gettimeofday(&x27693, NULL);
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x28271 = x28216;
      bool x28272 = !x28271;
      bool x28277 = x28272;
      if (x28272) {
        int x28273 = x28217;
        int x28274 = x28103;
        bool x28275 = x28273 < x28274;
        x28277 = x28275;
      }
      bool x28278 = x28277;
      if (!x28278) break;
      int x28281 = x28217;
      int* x28282 = x28105;
      int x28283 = x28282[x28281];
      char** x28290 = x28113;
      char* x28291 = x28290[x28281];
      x28217 = x28217 + 1;
      int x28301 = x28240;
      int* x28302 = x28223;
      x28302[x28301] = x28283;
      char** x28310 = x28231;
      x28310[x28301] = x28291;
      x28240 = x28240 + 1;
      int x28321 = x28283 & 1048575;
      int x28322 = x28241[x28321];
      x28241[x28321] = x28301;
      x28242[x28301] = x28322;
    }
    printf("(PART X LINEITEM): leftParent.next done\n");
    gettimeofday(&x27694, NULL);
    timeval_subtract(&x28330, &x27694, &x27693);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x28330.tv_sec * 1000) + (x28330.tv_usec/1000)));
    printf("(PART X LINEITEM): rightParent.next start\n");
    struct timeval x27898, x27899, x28529;
    gettimeofday(&x27898, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x28334 = x28218;
      bool x28335 = !x28334;
      bool x28340 = x28335;
      if (x28335) {
        int x28336 = x28219;
        int x28337 = x27937;
        bool x28338 = x28336 < x28337;
        x28340 = x28338;
      }
      bool x28341 = x28340;
      if (!x28341) break;
      int x28344 = x28219;
      int* x28347 = x27941;
      int x28348 = x28347[x28344];
      double* x28355 = x27949;
      double x28356 = x28355[x28344];
      double* x28357 = x27951;
      double x28358 = x28357[x28344];
      long* x28365 = x27959;
      long x28366 = x28365[x28344];
      x28219 = x28219 + 1;
      bool x28378 = x28366 >= 19940301L;
      bool x28380 = x28378;
      if (x28378) {
        bool x28379 = x28366 < 19940401L;
        x28380 = x28379;
      }
      bool x28381 = x28380;
      if (x28381) {
        int x28382 = x28348 & 1048575;
        int x28383 = x28241[x28382];
        int x28384 = x28383;
        double x28385 = 1.0 - x28358;
        double x28386 = x28356 * x28385;
        for (;;) {
          int x28387 = x28384;
          bool x28388 = x28387 != -1;
          if (!x28388) break;
          int x28390 = x28384;
          int* x28391 = x28223;
          int x28392 = x28391[x28390];
          char** x28399 = x28231;
          char* x28400 = x28399[x28390];
          int x28409 = x28242[x28390];
          x28384 = x28409;
          bool x28411 = x28392 == x28348;
          if (x28411) {
            int x28413 = x28256;
            int x28414 = x28413 - 1;
            int x28415 = x9503 & x28414;
            int x28416 = x28415;
            int* x28417 = x28259;
            int x28418 = x28417[x28415];
            int x28419 = x28418;
            int x28420 = x28415 + 1;
            int x28421 = x28417[x28420];
            int x28422 = x28421;
            for (;;) {
              int x28423 = x28419;
              bool x28424 = x28423 != -1;
              bool x28442 = x28424;
              if (x28424) {
                int x28425 = x28422;
                bool x28426 = x28425 != x9503;
                bool x28438 = x28426;
                if (x28426 == false) {
                  int x28427 = x28419;
                  char** x28428 = x28251;
                  char* x28429 = x28428[x28427];
                  bool x28434 = strcmp(x28429,"Total") == 0;;
                  bool x28435 = !x28434;
                  x28438 = x28435;
                }
                bool x28439 = x28438;
                x28442 = x28439;
              }
              bool x28443 = x28442;
              if (!x28443) break;
              int x28446 = x28416;
              int x28447 = x28446 + 2;
              int x28448 = x28447 & x28414;
              x28416 = x28448;
              int* x28450 = x28259;
              int x28451 = x28450[x28448];
              x28419 = x28451;
              int x28453 = x28448 + 1;
              int x28454 = x28450[x28453];
              x28422 = x28454;
            }
            int x28459 = x28419;
            bool x28460 = x28459 == -1;
            int x28500;
            if (x28460) {
              int x28461 = x28257;
              int x28462 = x28416;
              x28417[x28462] = x28461;
              int x28464 = x28462 + 1;
              x28417[x28464] = x9503;
              x28257 = x28257 + 1;
              int x28467 = x28249;
              int x28468 = x28248;
              bool x28469 = x28467 == x28468;
              if (x28469) {
                int x28470 = x28468 * 4;
                x28248 = x28470;
                printf("buffer.resize %d\n",x28470);
                char** x28473 = x28251;
                char** x28474 = (char**)realloc(x28473,x28470 * sizeof(char*));
                x28251 = x28474;
                printf("buffer.resize %d\n",x28470);
                double* x28477 = x28253;
                double* x28478 = (double*)realloc(x28477,x28470 * sizeof(double));
                x28253 = x28478;
                double* x28480 = x28255;
                double* x28481 = (double*)realloc(x28480,x28470 * sizeof(double));
                x28255 = x28481;
              } else {
              }
              char** x28485 = x28251;
              x28485[x28467] = "Total";
              double* x28487 = x28253;
              x28487[x28467] = 0.0;
              double* x28489 = x28255;
              x28489[x28467] = 0.0;
              x28249 = x28249 + 1;
              int x28492 = x28257;
              int x28493 = x28492 * 4;
              bool x28494 = x28493 > x28413;
              if (x28494) {
                printf("%s\n","ERROR: hash.resize not implemented");
              } else {
              }
              x28500 = x28461;
            } else {
              x28500 = x28459;
            }
            char** x28501 = x28251;
            char* x28502 = x28501[x28500];
            double* x28503 = x28253;
            double x28504 = x28503[x28500];
            double* x28505 = x28255;
            double x28506 = x28505[x28500];
            x28501[x28500] = x28502;
            bool x28508 = strncmp(x28400,"PROMO", strlen("PROMO")) == 0;;
            double x28510;
            if (x28508) {
              double x28509 = x28504 + x28386;
              x28510 = x28509;
            } else {
              x28510 = x28504;
            }
            x28503[x28500] = x28510;
            double x28512 = x28506 + x28386;
            x28505[x28500] = x28512;
          } else {
          }
        }
      } else {
      }
    }
    printf("(PART X LINEITEM): rightParent.next done\n");
    gettimeofday(&x27899, NULL);
    timeval_subtract(&x28529, &x27899, &x27898);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x28529.tv_sec * 1000) + (x28529.tv_usec/1000)));
    int x28531 = x28249;
    int x27904;
    for(x27904=0; x27904 < x28531; x27904++) {
      double* x28534 = x28253;
      double x28535 = x28534[x27904];
      double* x28536 = x28255;
      double x28537 = x28536[x27904];
      if (x28215) {
      } else {
        double x28540 = x28535 * x27914;
        double x28541 = x28540 / x28537;
        printf("%.4f\n",x28541);
        x28268 = x28268 + 1;
      }
    }
    int x28549 = x28268;
    printf("(%d rows)\n",x28549);
    gettimeofday(&x27929, NULL);
    timeval_subtract(&x28553, &x27929, &x27928);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x28553.tv_sec * 1000) + (x28553.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
