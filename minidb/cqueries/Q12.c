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
struct Anon811555534* left;
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
int x25745(struct Anon1832691401* x24737, struct Anon1832691401* x24736);
int x25751(struct Anon1832691401* x25746, struct Anon1832691401* x25747, struct Anon1832691401** x25748);
int x25745(struct Anon1832691401* x24737, struct Anon1832691401* x24736) {
  char* x24738 = x24736->key;;
  char* x24739 = x24737->key;;
  int x24740 = strcmp(x24738,x24739);
  return x24740;
}
int x25751(struct Anon1832691401* x25746, struct Anon1832691401* x25747, struct Anon1832691401** x25748) {
  *x25748 = x25747;
  return 0;
}

/************************ MAIN BODY **************************/
int main(int x24410, char** x24411) {
  FILE* x25087 = fopen("../databases/sf2/lineitem.tbl", "r");
  int x25088 = 1048576;
  int x25089 = 0;
  int* x25090 = (int*)malloc(1048576 * sizeof(int));
  int* x25091 = x25090;
  long* x25110 = (long*)malloc(1048576 * sizeof(long));
  long* x25111 = x25110;
  long* x25112 = (long*)malloc(1048576 * sizeof(long));
  long* x25113 = x25112;
  long* x25114 = (long*)malloc(1048576 * sizeof(long));
  long* x25115 = x25114;
  char** x25118 = (char**)malloc(1048576 * sizeof(char*));
  char** x25119 = x25118;
  for (;;) {
    bool x25122 = !feof(x25087);
    if (!x25122) break;
    int x25124 = 0;
    if (fscanf(x25087,"%d|",&x25124) == EOF) break;
    int x25125 = 0;
    if (fscanf(x25087,"%d|",&x25125) == EOF) break;
    int x25126 = 0;
    if (fscanf(x25087,"%d|",&x25126) == EOF) break;
    int x25127 = 0;
    if (fscanf(x25087,"%d|",&x25127) == EOF) break;
    double x25128 = 0.0;
    if (fscanf(x25087,"%lf|",&x25128) == EOF) break;
    double x25129 = 0.0;
    if (fscanf(x25087,"%lf|",&x25129) == EOF) break;
    double x25130 = 0.0;
    if (fscanf(x25087,"%lf|",&x25130) == EOF) break;
    double x25131 = 0.0;
    if (fscanf(x25087,"%lf|",&x25131) == EOF) break;
    char x25132 = ' ';
    if (fscanf(x25087,"%c|",&x25132) == EOF) break;
    char x25133 = ' ';
    if (fscanf(x25087,"%c|",&x25133) == EOF) break;
    int x25134 = 0;
    int x25135 = 0;
    int x25136 = 0;
    fscanf(x25087, "%d-%d-%d|",&x25134, &x25135, &x25136);
    long x25137 = (x25134 * 10000) + (x25135 * 100) + x25136;
    int x25138 = 0;
    int x25139 = 0;
    int x25140 = 0;
    fscanf(x25087, "%d-%d-%d|",&x25138, &x25139, &x25140);
    long x25141 = (x25138 * 10000) + (x25139 * 100) + x25140;
    int x25142 = 0;
    int x25143 = 0;
    int x25144 = 0;
    fscanf(x25087, "%d-%d-%d|",&x25142, &x25143, &x25144);
    long x25145 = (x25142 * 10000) + (x25143 * 100) + x25144;
    char* x25146 = (char*)malloc(26 * sizeof(char));
    int x25148 = 0;
    char x25147 = ' ';
    while (1) {
      fscanf(x25087,"%c",&x25147);
      if (x25147=='|' || x25147=='\n') break;
      if (x25148>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x25148); break;}
      ((char*)x25146)[x25148] = x25147;
      x25148 += 1;
    }
    ((char*)x25146)[x25148] = '\0';
    char* x25151 = (char*)malloc(11 * sizeof(char));
    int x25153 = 0;
    char x25152 = ' ';
    while (1) {
      fscanf(x25087,"%c",&x25152);
      if (x25152=='|' || x25152=='\n') break;
      if (x25153>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x25153); break;}
      ((char*)x25151)[x25153] = x25152;
      x25153 += 1;
    }
    ((char*)x25151)[x25153] = '\0';
    char* x25155 = x25151; // unsafe immutable;
    char* x25156 = (char*)malloc(45 * sizeof(char));
    int x25158 = 0;
    char x25157 = ' ';
    while (1) {
      fscanf(x25087,"%c",&x25157);
      if (x25157=='|' || x25157=='\n') break;
      if (x25158>=44) { printf("ERROR: scanner.nextString reading past end of buffer %d",x25158); break;}
      ((char*)x25156)[x25158] = x25157;
      x25158 += 1;
    }
    ((char*)x25156)[x25158] = '\0';
    int x25161 = x25089;
    int x25162 = x25088;
    bool x25163 = x25161 == x25162;
    if (x25163) {
      int x25164 = x25162 * 4;
      x25088 = x25164;
      printf("buffer.resize %d\n",x25164);
      int* x25167 = x25091;
      int* x25168 = (int*)realloc(x25167,x25164 * sizeof(int));
      x25091 = x25168;
      long* x25197 = x25111;
      long* x25198 = (long*)realloc(x25197,x25164 * sizeof(long));
      x25111 = x25198;
      long* x25200 = x25113;
      long* x25201 = (long*)realloc(x25200,x25164 * sizeof(long));
      x25113 = x25201;
      long* x25203 = x25115;
      long* x25204 = (long*)realloc(x25203,x25164 * sizeof(long));
      x25115 = x25204;
      char** x25209 = x25119;
      char** x25210 = (char**)realloc(x25209,x25164 * sizeof(char*));
      x25119 = x25210;
    } else {
    }
    int* x25217 = x25091;
    x25217[x25161] = x25124;
    long* x25237 = x25111;
    x25237[x25161] = x25137;
    long* x25239 = x25113;
    x25239[x25161] = x25141;
    long* x25241 = x25115;
    x25241[x25161] = x25145;
    char** x25245 = x25119;
    x25245[x25161] = x25155;
    x25089 = x25089 + 1;
  }
  FILE* x25253 = fopen("../databases/sf2/orders.tbl", "r");
  int x25254 = 1048576;
  int x25255 = 0;
  int* x25256 = (int*)malloc(1048576 * sizeof(int));
  int* x25257 = x25256;
  char** x25266 = (char**)malloc(1048576 * sizeof(char*));
  char** x25267 = x25266;
  for (;;) {
    bool x25274 = !feof(x25253);
    if (!x25274) break;
    int x25276 = 0;
    if (fscanf(x25253,"%d|",&x25276) == EOF) break;
    int x25277 = 0;
    if (fscanf(x25253,"%d|",&x25277) == EOF) break;
    char x25278 = ' ';
    if (fscanf(x25253,"%c|",&x25278) == EOF) break;
    double x25279 = 0.0;
    if (fscanf(x25253,"%lf|",&x25279) == EOF) break;
    int x25280 = 0;
    int x25281 = 0;
    int x25282 = 0;
    fscanf(x25253, "%d-%d-%d|",&x25280, &x25281, &x25282);
    long x25283 = (x25280 * 10000) + (x25281 * 100) + x25282;
    char* x25284 = (char*)malloc(16 * sizeof(char));
    int x25286 = 0;
    char x25285 = ' ';
    while (1) {
      fscanf(x25253,"%c",&x25285);
      if (x25285=='|' || x25285=='\n') break;
      if (x25286>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x25286); break;}
      ((char*)x25284)[x25286] = x25285;
      x25286 += 1;
    }
    ((char*)x25284)[x25286] = '\0';
    char* x25288 = x25284; // unsafe immutable;
    char* x25289 = (char*)malloc(16 * sizeof(char));
    int x25291 = 0;
    char x25290 = ' ';
    while (1) {
      fscanf(x25253,"%c",&x25290);
      if (x25290=='|' || x25290=='\n') break;
      if (x25291>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x25291); break;}
      ((char*)x25289)[x25291] = x25290;
      x25291 += 1;
    }
    ((char*)x25289)[x25291] = '\0';
    int x25294 = 0;
    if (fscanf(x25253,"%d|",&x25294) == EOF) break;
    char* x25295 = (char*)malloc(80 * sizeof(char));
    int x25297 = 0;
    char x25296 = ' ';
    while (1) {
      fscanf(x25253,"%c",&x25296);
      if (x25296=='|' || x25296=='\n') break;
      if (x25297>=79) { printf("ERROR: scanner.nextString reading past end of buffer %d",x25297); break;}
      ((char*)x25295)[x25297] = x25296;
      x25297 += 1;
    }
    ((char*)x25295)[x25297] = '\0';
    int x25300 = x25255;
    int x25301 = x25254;
    bool x25302 = x25300 == x25301;
    if (x25302) {
      int x25303 = x25301 * 4;
      x25254 = x25303;
      printf("buffer.resize %d\n",x25303);
      int* x25306 = x25257;
      int* x25307 = (int*)realloc(x25306,x25303 * sizeof(int));
      x25257 = x25307;
      char** x25321 = x25267;
      char** x25322 = (char**)realloc(x25321,x25303 * sizeof(char*));
      x25267 = x25322;
    } else {
    }
    int* x25335 = x25257;
    x25335[x25300] = x25276;
    char** x25345 = x25267;
    x25345[x25300] = x25288;
    x25255 = x25255 + 1;
  }
  GTree* x25357 = g_tree_new((GCompareFunc)x25745);;
  bool x25358 = true == false;
  int x24682;
  for(x24682=0; x24682 < 1; x24682++) {
    bool x25359 = false;
    int x25360 = 0;
    bool x25361 = false;
    int x25362 = 0;
    int* x25365 = (int*)malloc(1073741824 * sizeof(int));
    int* x25366 = x25365;
    char** x25375 = (char**)malloc(1073741824 * sizeof(char*));
    char** x25376 = x25375;
    int x25383 = 0;
    int* x25384 = (int*)malloc(1048576 * sizeof(int));
    int* x25385 = (int*)malloc(1073741824 * sizeof(int));
    int x24710;
    for(x24710=0; x24710 < 1048576; x24710++) {
      x25384[x24710] = -1;
    }
    int x25391 = 1048576;
    int x25392 = 0;
    char** x25393 = (char**)malloc(1048576 * sizeof(char*));
    char** x25394 = x25393;
    double* x25395 = (double*)malloc(1048576 * sizeof(double));
    double* x25396 = x25395;
    double* x25397 = (double*)malloc(1048576 * sizeof(double));
    double* x25398 = x25397;
    int x25399 = 4194304;
    int x25400 = 0;
    int* x25401 = (int*)malloc(4194304 * sizeof(int));
    int* x25402 = x25401;
    int x24728;
    for(x24728=0; x24728 < 4194304; x24728++) {
      int* x25403 = x25402;
      x25403[x24728] = -1;
    }
    int x25411 = 0;
    struct timeval x25074, x25075, x25738;
    gettimeofday(&x25074, NULL);
    printf("(ORDERS X LINEITEM): leftParent.next start\n");
    struct timeval x24804, x24805, x25473;
    gettimeofday(&x24804, NULL);
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x25414 = x25359;
      bool x25415 = !x25414;
      bool x25420 = x25415;
      if (x25415) {
        int x25416 = x25360;
        int x25417 = x25255;
        bool x25418 = x25416 < x25417;
        x25420 = x25418;
      }
      bool x25421 = x25420;
      if (!x25421) break;
      int x25424 = x25360;
      int* x25425 = x25257;
      int x25426 = x25425[x25424];
      char** x25435 = x25267;
      char* x25436 = x25435[x25424];
      x25360 = x25360 + 1;
      int x25444 = x25383;
      int* x25445 = x25366;
      x25445[x25444] = x25426;
      char** x25455 = x25376;
      x25455[x25444] = x25436;
      x25383 = x25383 + 1;
      int x25464 = x25426 & 1048575;
      int x25465 = x25384[x25464];
      x25384[x25464] = x25444;
      x25385[x25444] = x25465;
    }
    printf("(ORDERS X LINEITEM): leftParent.next done\n");
    gettimeofday(&x24805, NULL);
    timeval_subtract(&x25473, &x24805, &x24804);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x25473.tv_sec * 1000) + (x25473.tv_usec/1000)));
    printf("(ORDERS X LINEITEM): rightParent.next start\n");
    struct timeval x25036, x25037, x25702;
    gettimeofday(&x25036, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x25477 = x25361;
      bool x25478 = !x25477;
      bool x25483 = x25478;
      if (x25478) {
        int x25479 = x25362;
        int x25480 = x25089;
        bool x25481 = x25479 < x25480;
        x25483 = x25481;
      }
      bool x25484 = x25483;
      if (!x25484) break;
      int x25487 = x25362;
      int* x25488 = x25091;
      int x25489 = x25488[x25487];
      long* x25508 = x25111;
      long x25509 = x25508[x25487];
      long* x25510 = x25113;
      long x25511 = x25510[x25487];
      long* x25512 = x25115;
      long x25513 = x25512[x25487];
      char** x25516 = x25119;
      char* x25517 = x25516[x25487];
      x25362 = x25362 + 1;
      bool x25521 = x25513 < 19950101L;
      bool x25523 = x25521;
      if (x25521) {
        bool x25522 = x25511 < 19950101L;
        x25523 = x25522;
      }
      bool x25524 = x25523;
      bool x25526 = x25524;
      if (x25524) {
        bool x25525 = x25509 < 19950101L;
        x25526 = x25525;
      }
      bool x25527 = x25526;
      bool x25529 = x25527;
      if (x25527) {
        bool x25528 = x25509 < x25511;
        x25529 = x25528;
      }
      bool x25530 = x25529;
      bool x25532 = x25530;
      if (x25530) {
        bool x25531 = x25511 < x25513;
        x25532 = x25531;
      }
      bool x25533 = x25532;
      bool x25535 = x25533;
      if (x25533) {
        bool x25534 = x25513 >= 19940101L;
        x25535 = x25534;
      }
      bool x25536 = x25535;
      bool x25543 = x25536;
      if (x25536) {
        bool x25537 = strcmp(x25517,"MAIL") == 0;;
        bool x25540 = x25537;
        if (x25537 == false) {
          bool x25538 = strcmp(x25517,"SHIP") == 0;;
          x25540 = x25538;
        }
        bool x25541 = x25540;
        x25543 = x25541;
      }
      bool x25544 = x25543;
      if (x25544) {
        int x25545 = x25489 & 1048575;
        int x25546 = x25384[x25545];
        int x25547 = x25546;
        char x25548 = x25517[0];
        int x25549 = x25548 * 2;
        int x25550 = x25549 * 3;
        for (;;) {
          int x25551 = x25547;
          bool x25552 = x25551 != -1;
          if (!x25552) break;
          int x25554 = x25547;
          int* x25555 = x25366;
          int x25556 = x25555[x25554];
          char** x25565 = x25376;
          char* x25566 = x25565[x25554];
          int x25573 = x25385[x25554];
          x25547 = x25573;
          bool x25575 = x25556 == x25489;
          if (x25575) {
            int x25577 = x25399;
            int x25578 = x25577 - 1;
            int x25579 = x25550 & x25578;
            int x25580 = x25579;
            int* x25581 = x25402;
            int x25582 = x25581[x25579];
            int x25583 = x25582;
            int x25584 = x25579 + 1;
            int x25585 = x25581[x25584];
            int x25586 = x25585;
            for (;;) {
              int x25587 = x25583;
              bool x25588 = x25587 != -1;
              bool x25606 = x25588;
              if (x25588) {
                int x25589 = x25586;
                bool x25590 = x25589 != x25550;
                bool x25602 = x25590;
                if (x25590 == false) {
                  int x25591 = x25583;
                  char** x25592 = x25394;
                  char* x25593 = x25592[x25591];
                  bool x25598 = strcmp(x25593,x25517) == 0;;
                  bool x25599 = !x25598;
                  x25602 = x25599;
                }
                bool x25603 = x25602;
                x25606 = x25603;
              }
              bool x25607 = x25606;
              if (!x25607) break;
              int x25610 = x25580;
              int x25611 = x25610 + 2;
              int x25612 = x25611 & x25578;
              x25580 = x25612;
              int* x25614 = x25402;
              int x25615 = x25614[x25612];
              x25583 = x25615;
              int x25617 = x25612 + 1;
              int x25618 = x25614[x25617];
              x25586 = x25618;
            }
            int x25623 = x25583;
            bool x25624 = x25623 == -1;
            int x25664;
            if (x25624) {
              int x25625 = x25400;
              int x25626 = x25580;
              x25581[x25626] = x25625;
              int x25628 = x25626 + 1;
              x25581[x25628] = x25550;
              x25400 = x25400 + 1;
              int x25631 = x25392;
              int x25632 = x25391;
              bool x25633 = x25631 == x25632;
              if (x25633) {
                int x25634 = x25632 * 4;
                x25391 = x25634;
                printf("buffer.resize %d\n",x25634);
                char** x25637 = x25394;
                char** x25638 = (char**)realloc(x25637,x25634 * sizeof(char*));
                x25394 = x25638;
                printf("buffer.resize %d\n",x25634);
                double* x25641 = x25396;
                double* x25642 = (double*)realloc(x25641,x25634 * sizeof(double));
                x25396 = x25642;
                double* x25644 = x25398;
                double* x25645 = (double*)realloc(x25644,x25634 * sizeof(double));
                x25398 = x25645;
              } else {
              }
              char** x25649 = x25394;
              x25649[x25631] = x25517;
              double* x25651 = x25396;
              x25651[x25631] = 0.0;
              double* x25653 = x25398;
              x25653[x25631] = 0.0;
              x25392 = x25392 + 1;
              int x25656 = x25400;
              int x25657 = x25656 * 4;
              bool x25658 = x25657 > x25577;
              if (x25658) {
                printf("%s\n","ERROR: hash.resize not implemented");
              } else {
              }
              x25664 = x25625;
            } else {
              x25664 = x25623;
            }
            char** x25665 = x25394;
            char* x25666 = x25665[x25664];
            double* x25667 = x25396;
            double x25668 = x25667[x25664];
            double* x25669 = x25398;
            double x25670 = x25669[x25664];
            x25665[x25664] = x25666;
            bool x25672 = strcmp(x25566,"1-URGENT") == 0;;
            bool x25675 = x25672;
            if (x25672 == false) {
              bool x25673 = strcmp(x25566,"2-HIGH") == 0;;
              x25675 = x25673;
            }
            bool x25676 = x25675;
            double x25678;
            if (x25676) {
              double x25677 = x25668 + 1.0;
              x25678 = x25677;
            } else {
              x25678 = x25668;
            }
            x25667[x25664] = x25678;
            bool x25680 = strcmp(x25566,"1-URGENT") != 0;;
            bool x25682 = x25680;
            if (x25680) {
              bool x25681 = strcmp(x25566,"2-HIGH") != 0;;
              x25682 = x25681;
            }
            bool x25683 = x25682;
            double x25685;
            if (x25683) {
              double x25684 = x25670 + 1.0;
              x25685 = x25684;
            } else {
              x25685 = x25670;
            }
            x25669[x25664] = x25685;
          } else {
          }
        }
      } else {
      }
    }
    printf("(ORDERS X LINEITEM): rightParent.next done\n");
    gettimeofday(&x25037, NULL);
    timeval_subtract(&x25702, &x25037, &x25036);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x25702.tv_sec * 1000) + (x25702.tv_usec/1000)));
    int x25704 = x25392;
    int x25042;
    for(x25042=0; x25042 < x25704; x25042++) {
      char** x25705 = x25394;
      char* x25706 = x25705[x25042];
      double* x25707 = x25396;
      double x25708 = x25707[x25042];
      double* x25709 = x25398;
      double x25710 = x25709[x25042];
      struct Anon189208763* x25711 = (struct Anon189208763*)malloc(sizeof(struct Anon189208763));
      x25711->_0 = x25708;
      x25711->_1 = x25710;
      struct Anon1832691401* x25712 = (struct Anon1832691401*)malloc(sizeof(struct Anon1832691401));
      x25712->key = x25706;
      x25712->aggs = x25711;
      g_tree_insert(x25357,x25712,x25712);; // x25713
    }
    for (;;) {
      int x25716 = g_tree_nnodes(x25357);
      bool x25717 = x25716 != 0;
      if (!x25717) break;
      struct Anon1832691401* x25719 = NULL;
      g_tree_foreach(x25357, (GTraverseFunc)x25751, &x25719);
      g_tree_remove(x25357,x25719);
      if (x25358) {
      } else {
        char* x25723 = x25719->key;;
        struct Anon189208763* x25724 = x25719->aggs;;
        double x25725 = x25724->_0;;
        double x25726 = x25724->_1;;
        printf("%s|%.0f|%.0f\n",x25723,x25725,x25726);
        x25411 = x25411 + 1;
      }
    }
    int x25734 = x25411;
    printf("(%d rows)\n",x25734);
    gettimeofday(&x25075, NULL);
    timeval_subtract(&x25738, &x25075, &x25074);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x25738.tv_sec * 1000) + (x25738.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
