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
struct Anon102935935Anon168903330Anon811555534;
struct Anon811555534;
struct Anon15765642;
struct Anon102935935;
struct Anon713865179Anon72918141Anon1268892766Anon168903330;
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
struct Anon325450556;
struct Anon1406772883Anon1268892766;
struct Anon920667905Anon713865179Anon72918141Anon1268892766Anon168903330Anon811555534;
struct Anon1406772883Anon102935935Anon168903330Anon811555534Anon920667905;
struct Anon102935935Anon168903330Anon811555534Anon920667905;
struct Anon1732223439;
struct Anon722854457;
struct Anon625264174;
struct Anon949908027;
struct Anon1711779607;
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
struct Anon325450556* left;
struct Anon168903330* right;
};

struct Anon1812879556 {
char* key;
struct Anon2052879266* aggs;
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
int x22762(struct Anon417859734* x20876, struct Anon417859734* x20875);
int x22768(struct Anon417859734* x22763, struct Anon417859734* x22764, struct Anon417859734** x22765);
int x22762(struct Anon417859734* x20876, struct Anon417859734* x20875) {
  struct Anon2052879266* x20877 = x20875->aggs;;
  double x20878 = x20877->_0;;
  struct Anon2052879266* x20879 = x20876->aggs;;
  double x20880 = x20879->_0;;
  bool x20881 = x20878 < x20880;
  int x21984;
  if (x20881) {
    x21984 = 1;
  } else {
    bool x20882 = x20878 > x20880;
    int x21982;
    if (x20882) {
      x21982 = -1;
    } else {
      x21982 = 0;
    }
    x21984 = x21982;
  }
  return x21984;
}
int x22768(struct Anon417859734* x22763, struct Anon417859734* x22764, struct Anon417859734** x22765) {
  *x22765 = x22764;
  return 0;
}

/************************ MAIN BODY **************************/
int main(int x20308, char** x20309) {
  FILE* x21554 = fopen("../databases/sf2/lineitem.tbl", "r");
  int x21555 = 1048576;
  int x21556 = 0;
  int* x21557 = (int*)malloc(1048576 * sizeof(int));
  int* x21558 = x21557;
  double* x21567 = (double*)malloc(1048576 * sizeof(double));
  double* x21568 = x21567;
  double* x21569 = (double*)malloc(1048576 * sizeof(double));
  double* x21570 = x21569;
  char* x21573 = (char*)malloc(1048576 * sizeof(char));
  char* x21574 = x21573;
  for (;;) {
    bool x21589 = !feof(x21554);
    if (!x21589) break;
    int x21591 = 0;
    if (fscanf(x21554,"%d|",&x21591) == EOF) break;
    int x21592 = 0;
    if (fscanf(x21554,"%d|",&x21592) == EOF) break;
    int x21593 = 0;
    if (fscanf(x21554,"%d|",&x21593) == EOF) break;
    int x21594 = 0;
    if (fscanf(x21554,"%d|",&x21594) == EOF) break;
    double x21595 = 0.0;
    if (fscanf(x21554,"%lf|",&x21595) == EOF) break;
    double x21596 = 0.0;
    if (fscanf(x21554,"%lf|",&x21596) == EOF) break;
    double x21597 = 0.0;
    if (fscanf(x21554,"%lf|",&x21597) == EOF) break;
    double x21598 = 0.0;
    if (fscanf(x21554,"%lf|",&x21598) == EOF) break;
    char x21599 = ' ';
    if (fscanf(x21554,"%c|",&x21599) == EOF) break;
    char x21600 = ' ';
    if (fscanf(x21554,"%c|",&x21600) == EOF) break;
    int x21601 = 0;
    int x21602 = 0;
    int x21603 = 0;
    fscanf(x21554, "%d-%d-%d|",&x21601, &x21602, &x21603);
    long x21604 = (x21601 * 10000) + (x21602 * 100) + x21603;
    int x21605 = 0;
    int x21606 = 0;
    int x21607 = 0;
    fscanf(x21554, "%d-%d-%d|",&x21605, &x21606, &x21607);
    long x21608 = (x21605 * 10000) + (x21606 * 100) + x21607;
    int x21609 = 0;
    int x21610 = 0;
    int x21611 = 0;
    fscanf(x21554, "%d-%d-%d|",&x21609, &x21610, &x21611);
    long x21612 = (x21609 * 10000) + (x21610 * 100) + x21611;
    char* x21613 = (char*)malloc(26 * sizeof(char));
    int x21615 = 0;
    char x21614 = ' ';
    while (1) {
      fscanf(x21554,"%c",&x21614);
      if (x21614=='|' || x21614=='\n') break;
      if (x21615>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x21615); break;}
      ((char*)x21613)[x21615] = x21614;
      x21615 += 1;
    }
    ((char*)x21613)[x21615] = '\0';
    char* x21618 = (char*)malloc(11 * sizeof(char));
    int x21620 = 0;
    char x21619 = ' ';
    while (1) {
      fscanf(x21554,"%c",&x21619);
      if (x21619=='|' || x21619=='\n') break;
      if (x21620>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x21620); break;}
      ((char*)x21618)[x21620] = x21619;
      x21620 += 1;
    }
    ((char*)x21618)[x21620] = '\0';
    char* x21623 = (char*)malloc(45 * sizeof(char));
    int x21625 = 0;
    char x21624 = ' ';
    while (1) {
      fscanf(x21554,"%c",&x21624);
      if (x21624=='|' || x21624=='\n') break;
      if (x21625>=44) { printf("ERROR: scanner.nextString reading past end of buffer %d",x21625); break;}
      ((char*)x21623)[x21625] = x21624;
      x21625 += 1;
    }
    ((char*)x21623)[x21625] = '\0';
    int x21628 = x21556;
    int x21629 = x21555;
    bool x21630 = x21628 == x21629;
    if (x21630) {
      int x21631 = x21629 * 4;
      x21555 = x21631;
      printf("buffer.resize %d\n",x21631);
      int* x21634 = x21558;
      int* x21635 = (int*)realloc(x21634,x21631 * sizeof(int));
      x21558 = x21635;
      double* x21649 = x21568;
      double* x21650 = (double*)realloc(x21649,x21631 * sizeof(double));
      x21568 = x21650;
      double* x21652 = x21570;
      double* x21653 = (double*)realloc(x21652,x21631 * sizeof(double));
      x21570 = x21653;
      char* x21658 = x21574;
      char* x21659 = (char*)realloc(x21658,x21631 * sizeof(char));
      x21574 = x21659;
    } else {
    }
    int* x21684 = x21558;
    x21684[x21628] = x21591;
    double* x21694 = x21568;
    x21694[x21628] = x21596;
    double* x21696 = x21570;
    x21696[x21628] = x21597;
    char* x21700 = x21574;
    x21700[x21628] = x21599;
    x21556 = x21556 + 1;
  }
  FILE* x21720 = fopen("../databases/sf2/nation.tbl", "r");
  int x21721 = 1048576;
  int x21722 = 0;
  int* x21723 = (int*)malloc(1048576 * sizeof(int));
  int* x21724 = x21723;
  char** x21725 = (char**)malloc(1048576 * sizeof(char*));
  char** x21726 = x21725;
  for (;;) {
    bool x21731 = !feof(x21720);
    if (!x21731) break;
    int x21733 = 0;
    if (fscanf(x21720,"%d|",&x21733) == EOF) break;
    char* x21734 = (char*)malloc(26 * sizeof(char));
    int x21736 = 0;
    char x21735 = ' ';
    while (1) {
      fscanf(x21720,"%c",&x21735);
      if (x21735=='|' || x21735=='\n') break;
      if (x21736>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x21736); break;}
      ((char*)x21734)[x21736] = x21735;
      x21736 += 1;
    }
    ((char*)x21734)[x21736] = '\0';
    char* x21738 = x21734; // unsafe immutable;
    int x21739 = 0;
    if (fscanf(x21720,"%d|",&x21739) == EOF) break;
    char* x21740 = (char*)malloc(153 * sizeof(char));
    int x21742 = 0;
    char x21741 = ' ';
    while (1) {
      fscanf(x21720,"%c",&x21741);
      if (x21741=='|' || x21741=='\n') break;
      if (x21742>=152) { printf("ERROR: scanner.nextString reading past end of buffer %d",x21742); break;}
      ((char*)x21740)[x21742] = x21741;
      x21742 += 1;
    }
    ((char*)x21740)[x21742] = '\0';
    int x21745 = x21722;
    int x21746 = x21721;
    bool x21747 = x21745 == x21746;
    if (x21747) {
      int x21748 = x21746 * 4;
      x21721 = x21748;
      printf("buffer.resize %d\n",x21748);
      int* x21751 = x21724;
      int* x21752 = (int*)realloc(x21751,x21748 * sizeof(int));
      x21724 = x21752;
      char** x21754 = x21726;
      char** x21755 = (char**)realloc(x21754,x21748 * sizeof(char*));
      x21726 = x21755;
    } else {
    }
    int* x21765 = x21724;
    x21765[x21745] = x21733;
    char** x21767 = x21726;
    x21767[x21745] = x21738;
    x21722 = x21722 + 1;
  }
  FILE* x21777 = fopen("../databases/sf2/customer.tbl", "r");
  int x21778 = 1048576;
  int x21779 = 0;
  int* x21780 = (int*)malloc(1048576 * sizeof(int));
  int* x21781 = x21780;
  char** x21782 = (char**)malloc(1048576 * sizeof(char*));
  char** x21783 = x21782;
  char** x21784 = (char**)malloc(1048576 * sizeof(char*));
  char** x21785 = x21784;
  int* x21786 = (int*)malloc(1048576 * sizeof(int));
  int* x21787 = x21786;
  char** x21788 = (char**)malloc(1048576 * sizeof(char*));
  char** x21789 = x21788;
  double* x21790 = (double*)malloc(1048576 * sizeof(double));
  double* x21791 = x21790;
  char** x21794 = (char**)malloc(1048576 * sizeof(char*));
  char** x21795 = x21794;
  for (;;) {
    bool x21796 = !feof(x21777);
    if (!x21796) break;
    int x21798 = 0;
    if (fscanf(x21777,"%d|",&x21798) == EOF) break;
    char* x21799 = (char*)malloc(26 * sizeof(char));
    int x21801 = 0;
    char x21800 = ' ';
    while (1) {
      fscanf(x21777,"%c",&x21800);
      if (x21800=='|' || x21800=='\n') break;
      if (x21801>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x21801); break;}
      ((char*)x21799)[x21801] = x21800;
      x21801 += 1;
    }
    ((char*)x21799)[x21801] = '\0';
    char* x21803 = x21799; // unsafe immutable;
    char* x21804 = (char*)malloc(41 * sizeof(char));
    int x21806 = 0;
    char x21805 = ' ';
    while (1) {
      fscanf(x21777,"%c",&x21805);
      if (x21805=='|' || x21805=='\n') break;
      if (x21806>=40) { printf("ERROR: scanner.nextString reading past end of buffer %d",x21806); break;}
      ((char*)x21804)[x21806] = x21805;
      x21806 += 1;
    }
    ((char*)x21804)[x21806] = '\0';
    char* x21808 = x21804; // unsafe immutable;
    int x21809 = 0;
    if (fscanf(x21777,"%d|",&x21809) == EOF) break;
    char* x21810 = (char*)malloc(16 * sizeof(char));
    int x21812 = 0;
    char x21811 = ' ';
    while (1) {
      fscanf(x21777,"%c",&x21811);
      if (x21811=='|' || x21811=='\n') break;
      if (x21812>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x21812); break;}
      ((char*)x21810)[x21812] = x21811;
      x21812 += 1;
    }
    ((char*)x21810)[x21812] = '\0';
    char* x21814 = x21810; // unsafe immutable;
    double x21815 = 0.0;
    if (fscanf(x21777,"%lf|",&x21815) == EOF) break;
    char* x21816 = (char*)malloc(11 * sizeof(char));
    int x21818 = 0;
    char x21817 = ' ';
    while (1) {
      fscanf(x21777,"%c",&x21817);
      if (x21817=='|' || x21817=='\n') break;
      if (x21818>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x21818); break;}
      ((char*)x21816)[x21818] = x21817;
      x21818 += 1;
    }
    ((char*)x21816)[x21818] = '\0';
    char* x21821 = (char*)malloc(118 * sizeof(char));
    int x21823 = 0;
    char x21822 = ' ';
    while (1) {
      fscanf(x21777,"%c",&x21822);
      if (x21822=='|' || x21822=='\n') break;
      if (x21823>=117) { printf("ERROR: scanner.nextString reading past end of buffer %d",x21823); break;}
      ((char*)x21821)[x21823] = x21822;
      x21823 += 1;
    }
    ((char*)x21821)[x21823] = '\0';
    char* x21825 = x21821; // unsafe immutable;
    int x21826 = x21779;
    int x21827 = x21778;
    bool x21828 = x21826 == x21827;
    if (x21828) {
      int x21829 = x21827 * 4;
      x21778 = x21829;
      printf("buffer.resize %d\n",x21829);
      int* x21832 = x21781;
      int* x21833 = (int*)realloc(x21832,x21829 * sizeof(int));
      x21781 = x21833;
      char** x21835 = x21783;
      char** x21836 = (char**)realloc(x21835,x21829 * sizeof(char*));
      x21783 = x21836;
      char** x21838 = x21785;
      char** x21839 = (char**)realloc(x21838,x21829 * sizeof(char*));
      x21785 = x21839;
      int* x21841 = x21787;
      int* x21842 = (int*)realloc(x21841,x21829 * sizeof(int));
      x21787 = x21842;
      char** x21844 = x21789;
      char** x21845 = (char**)realloc(x21844,x21829 * sizeof(char*));
      x21789 = x21845;
      double* x21847 = x21791;
      double* x21848 = (double*)realloc(x21847,x21829 * sizeof(double));
      x21791 = x21848;
      char** x21853 = x21795;
      char** x21854 = (char**)realloc(x21853,x21829 * sizeof(char*));
      x21795 = x21854;
    } else {
    }
    int* x21858 = x21781;
    x21858[x21826] = x21798;
    char** x21860 = x21783;
    x21860[x21826] = x21803;
    char** x21862 = x21785;
    x21862[x21826] = x21808;
    int* x21864 = x21787;
    x21864[x21826] = x21809;
    char** x21866 = x21789;
    x21866[x21826] = x21814;
    double* x21868 = x21791;
    x21868[x21826] = x21815;
    char** x21872 = x21795;
    x21872[x21826] = x21825;
    x21779 = x21779 + 1;
  }
  FILE* x21878 = fopen("../databases/sf2/orders.tbl", "r");
  int x21879 = 1048576;
  int x21880 = 0;
  int* x21881 = (int*)malloc(1048576 * sizeof(int));
  int* x21882 = x21881;
  int* x21883 = (int*)malloc(1048576 * sizeof(int));
  int* x21884 = x21883;
  long* x21889 = (long*)malloc(1048576 * sizeof(long));
  long* x21890 = x21889;
  for (;;) {
    bool x21899 = !feof(x21878);
    if (!x21899) break;
    int x21901 = 0;
    if (fscanf(x21878,"%d|",&x21901) == EOF) break;
    int x21902 = 0;
    if (fscanf(x21878,"%d|",&x21902) == EOF) break;
    char x21903 = ' ';
    if (fscanf(x21878,"%c|",&x21903) == EOF) break;
    double x21904 = 0.0;
    if (fscanf(x21878,"%lf|",&x21904) == EOF) break;
    int x21905 = 0;
    int x21906 = 0;
    int x21907 = 0;
    fscanf(x21878, "%d-%d-%d|",&x21905, &x21906, &x21907);
    long x21908 = (x21905 * 10000) + (x21906 * 100) + x21907;
    char* x21909 = (char*)malloc(16 * sizeof(char));
    int x21911 = 0;
    char x21910 = ' ';
    while (1) {
      fscanf(x21878,"%c",&x21910);
      if (x21910=='|' || x21910=='\n') break;
      if (x21911>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x21911); break;}
      ((char*)x21909)[x21911] = x21910;
      x21911 += 1;
    }
    ((char*)x21909)[x21911] = '\0';
    char* x21914 = (char*)malloc(16 * sizeof(char));
    int x21916 = 0;
    char x21915 = ' ';
    while (1) {
      fscanf(x21878,"%c",&x21915);
      if (x21915=='|' || x21915=='\n') break;
      if (x21916>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x21916); break;}
      ((char*)x21914)[x21916] = x21915;
      x21916 += 1;
    }
    ((char*)x21914)[x21916] = '\0';
    int x21919 = 0;
    if (fscanf(x21878,"%d|",&x21919) == EOF) break;
    char* x21920 = (char*)malloc(80 * sizeof(char));
    int x21922 = 0;
    char x21921 = ' ';
    while (1) {
      fscanf(x21878,"%c",&x21921);
      if (x21921=='|' || x21921=='\n') break;
      if (x21922>=79) { printf("ERROR: scanner.nextString reading past end of buffer %d",x21922); break;}
      ((char*)x21920)[x21922] = x21921;
      x21922 += 1;
    }
    ((char*)x21920)[x21922] = '\0';
    int x21925 = x21880;
    int x21926 = x21879;
    bool x21927 = x21925 == x21926;
    if (x21927) {
      int x21928 = x21926 * 4;
      x21879 = x21928;
      printf("buffer.resize %d\n",x21928);
      int* x21931 = x21882;
      int* x21932 = (int*)realloc(x21931,x21928 * sizeof(int));
      x21882 = x21932;
      int* x21934 = x21884;
      int* x21935 = (int*)realloc(x21934,x21928 * sizeof(int));
      x21884 = x21935;
      long* x21943 = x21890;
      long* x21944 = (long*)realloc(x21943,x21928 * sizeof(long));
      x21890 = x21944;
    } else {
    }
    int* x21960 = x21882;
    x21960[x21925] = x21901;
    int* x21962 = x21884;
    x21962[x21925] = x21902;
    long* x21968 = x21890;
    x21968[x21925] = x21908;
    x21880 = x21880 + 1;
  }
  GTree* x21986 = g_tree_new((GCompareFunc)x22762);;
  int x20738;
  for(x20738=0; x20738 < 1; x20738++) {
    bool x21987 = false;
    int x21988 = 0;
    bool x21990 = false;
    int x21991 = 0;
    int* x21993 = (int*)malloc(1073741824 * sizeof(int));
    int* x21994 = x21993;
    int* x21995 = (int*)malloc(1073741824 * sizeof(int));
    int* x21996 = x21995;
    int x22011 = 0;
    int* x22012 = (int*)malloc(1048576 * sizeof(int));
    int* x22013 = (int*)malloc(1073741824 * sizeof(int));
    int x20766;
    for(x20766=0; x20766 < 1048576; x20766++) {
      x22012[x20766] = -1;
    }
    bool x22018 = false;
    int x22019 = 0;
    int* x22021 = (int*)malloc(1073741824 * sizeof(int));
    int* x22022 = x22021;
    char** x22023 = (char**)malloc(1073741824 * sizeof(char*));
    char** x22024 = x22023;
    int x22029 = 0;
    int* x22030 = (int*)malloc(1048576 * sizeof(int));
    int* x22031 = (int*)malloc(1073741824 * sizeof(int));
    int x20785;
    for(x20785=0; x20785 < 1048576; x20785++) {
      x22030[x20785] = -1;
    }
    bool x22036 = false;
    int x22037 = 0;
    char** x22042 = (char**)malloc(1073741824 * sizeof(char*));
    char** x22043 = x22042;
    int* x22048 = (int*)malloc(1073741824 * sizeof(int));
    int* x22049 = x22048;
    int* x22066 = (int*)malloc(1073741824 * sizeof(int));
    int* x22067 = x22066;
    char** x22068 = (char**)malloc(1073741824 * sizeof(char*));
    char** x22069 = x22068;
    char** x22070 = (char**)malloc(1073741824 * sizeof(char*));
    char** x22071 = x22070;
    char** x22074 = (char**)malloc(1073741824 * sizeof(char*));
    char** x22075 = x22074;
    double* x22076 = (double*)malloc(1073741824 * sizeof(double));
    double* x22077 = x22076;
    char** x22080 = (char**)malloc(1073741824 * sizeof(char*));
    char** x22081 = x22080;
    int x22082 = 0;
    int* x22083 = (int*)malloc(1048576 * sizeof(int));
    int* x22084 = (int*)malloc(1073741824 * sizeof(int));
    int x20839;
    for(x20839=0; x20839 < 1048576; x20839++) {
      x22083[x20839] = -1;
    }
    int x22090 = 1048576;
    int x22091 = 0;
    int* x22092 = (int*)malloc(1048576 * sizeof(int));
    int* x22093 = x22092;
    char** x22094 = (char**)malloc(1048576 * sizeof(char*));
    char** x22095 = x22094;
    double* x22096 = (double*)malloc(1048576 * sizeof(double));
    double* x22097 = x22096;
    char** x22098 = (char**)malloc(1048576 * sizeof(char*));
    char** x22099 = x22098;
    char** x22100 = (char**)malloc(1048576 * sizeof(char*));
    char** x22101 = x22100;
    char** x22102 = (char**)malloc(1048576 * sizeof(char*));
    char** x22103 = x22102;
    char** x22104 = (char**)malloc(1048576 * sizeof(char*));
    char** x22105 = x22104;
    double* x22106 = (double*)malloc(1048576 * sizeof(double));
    double* x22107 = x22106;
    int x22108 = 4194304;
    int x22109 = 0;
    int* x22110 = (int*)malloc(4194304 * sizeof(int));
    int* x22111 = x22110;
    int x20867;
    for(x20867=0; x20867 < 4194304; x20867++) {
      int* x22112 = x22111;
      x22112[x20867] = -1;
    }
    int x22119 = 0;
    int x22121 = 0;
    struct timeval x21533, x21534, x22755;
    gettimeofday(&x21533, NULL);
    printf("((NATION X (ORDERS X CUSTOMER)) X LINEITEM): leftParent.next start\n");
    struct timeval x21161, x21162, x22388;
    gettimeofday(&x21161, NULL);
    printf("(NATION X (ORDERS X CUSTOMER)): leftParent.next start\n");
    struct timeval x20930, x20931, x22164;
    gettimeofday(&x20930, NULL);
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x22125 = x22018;
      bool x22126 = !x22125;
      bool x22131 = x22126;
      if (x22126) {
        int x22127 = x22019;
        int x22128 = x21722;
        bool x22129 = x22127 < x22128;
        x22131 = x22129;
      }
      bool x22132 = x22131;
      if (!x22132) break;
      int x22135 = x22019;
      int* x22136 = x21724;
      int x22137 = x22136[x22135];
      char** x22138 = x21726;
      char* x22139 = x22138[x22135];
      x22019 = x22019 + 1;
      int x22145 = x22029;
      int* x22146 = x22022;
      x22146[x22145] = x22137;
      char** x22148 = x22024;
      x22148[x22145] = x22139;
      x22029 = x22029 + 1;
      int x22155 = x22137 & 1048575;
      int x22156 = x22030[x22155];
      x22030[x22155] = x22145;
      x22031[x22145] = x22156;
    }
    printf("(NATION X (ORDERS X CUSTOMER)): leftParent.next done\n");
    gettimeofday(&x20931, NULL);
    timeval_subtract(&x22164, &x20931, &x20930);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x22164.tv_sec * 1000) + (x22164.tv_usec/1000)));
    printf("(NATION X (ORDERS X CUSTOMER)): rightParent.next start\n");
    struct timeval x21155, x21156, x22383;
    gettimeofday(&x21155, NULL);
    printf("(ORDERS X CUSTOMER): leftParent.next start\n");
    struct timeval x21001, x21002, x22235;
    gettimeofday(&x21001, NULL);
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x22169 = x21987;
      bool x22170 = !x22169;
      bool x22175 = x22170;
      if (x22170) {
        int x22171 = x21988;
        int x22172 = x21880;
        bool x22173 = x22171 < x22172;
        x22175 = x22173;
      }
      bool x22176 = x22175;
      if (!x22176) break;
      int x22179 = x21988;
      int* x22180 = x21882;
      int x22181 = x22180[x22179];
      int* x22182 = x21884;
      int x22183 = x22182[x22179];
      long* x22188 = x21890;
      long x22189 = x22188[x22179];
      x21988 = x21988 + 1;
      bool x22199 = x22189 >= 19941101L;
      bool x22201 = x22199;
      if (x22199) {
        bool x22200 = x22189 < 19950201L;
        x22201 = x22200;
      }
      bool x22202 = x22201;
      if (x22202) {
        int x22203 = x22011;
        int* x22204 = x21994;
        x22204[x22203] = x22181;
        int* x22206 = x21996;
        x22206[x22203] = x22183;
        x22011 = x22011 + 1;
        int x22223 = x22183 & 1048575;
        int x22224 = x22012[x22223];
        x22012[x22223] = x22203;
        x22013[x22203] = x22224;
      } else {
      }
    }
    printf("(ORDERS X CUSTOMER): leftParent.next done\n");
    gettimeofday(&x21002, NULL);
    timeval_subtract(&x22235, &x21002, &x21001);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x22235.tv_sec * 1000) + (x22235.tv_usec/1000)));
    printf("(ORDERS X CUSTOMER): rightParent.next start\n");
    struct timeval x21149, x21150, x22378;
    gettimeofday(&x21149, NULL);
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x22239 = x21990;
      bool x22240 = !x22239;
      bool x22245 = x22240;
      if (x22240) {
        int x22241 = x21991;
        int x22242 = x21779;
        bool x22243 = x22241 < x22242;
        x22245 = x22243;
      }
      bool x22246 = x22245;
      if (!x22246) break;
      int x22249 = x21991;
      int* x22250 = x21781;
      int x22251 = x22250[x22249];
      char** x22252 = x21783;
      char* x22253 = x22252[x22249];
      char** x22254 = x21785;
      char* x22255 = x22254[x22249];
      int* x22256 = x21787;
      int x22257 = x22256[x22249];
      char** x22258 = x21789;
      char* x22259 = x22258[x22249];
      double* x22260 = x21791;
      double x22261 = x22260[x22249];
      char** x22264 = x21795;
      char* x22265 = x22264[x22249];
      x21991 = x21991 + 1;
      int x22267 = x22251 & 1048575;
      int x22268 = x22012[x22267];
      int x22269 = x22268;
      int x22270 = x22257 & 1048575;
      for (;;) {
        int x22271 = x22269;
        bool x22272 = x22271 != -1;
        if (!x22272) break;
        int x22274 = x22269;
        int* x22275 = x21994;
        int x22276 = x22275[x22274];
        int* x22277 = x21996;
        int x22278 = x22277[x22274];
        int x22293 = x22013[x22274];
        x22269 = x22293;
        bool x22295 = x22278 == x22251;
        if (x22295) {
          int x22296 = x22030[x22270];
          int x22297 = x22296;
          int x22298 = x22276 & 1048575;
          for (;;) {
            int x22299 = x22297;
            bool x22300 = x22299 != -1;
            if (!x22300) break;
            int x22302 = x22297;
            int* x22303 = x22022;
            int x22304 = x22303[x22302];
            char** x22305 = x22024;
            char* x22306 = x22305[x22302];
            int x22311 = x22031[x22302];
            x22297 = x22311;
            bool x22313 = x22304 == x22257;
            if (x22313) {
              int x22314 = x22082;
              char** x22317 = x22043;
              x22317[x22314] = x22306;
              int* x22323 = x22049;
              x22323[x22314] = x22276;
              int* x22341 = x22067;
              x22341[x22314] = x22251;
              char** x22343 = x22069;
              x22343[x22314] = x22253;
              char** x22345 = x22071;
              x22345[x22314] = x22255;
              char** x22349 = x22075;
              x22349[x22314] = x22259;
              double* x22351 = x22077;
              x22351[x22314] = x22261;
              char** x22355 = x22081;
              x22355[x22314] = x22265;
              x22082 = x22082 + 1;
              int x22358 = x22083[x22298];
              x22083[x22298] = x22314;
              x22084[x22314] = x22358;
            } else {
            }
          }
        } else {
        }
      }
    }
    printf("(ORDERS X CUSTOMER): rightParent.next done\n");
    gettimeofday(&x21150, NULL);
    timeval_subtract(&x22378, &x21150, &x21149);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x22378.tv_sec * 1000) + (x22378.tv_usec/1000)));
    printf("(NATION X (ORDERS X CUSTOMER)): rightParent.next done\n");
    gettimeofday(&x21156, NULL);
    timeval_subtract(&x22383, &x21156, &x21155);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x22383.tv_sec * 1000) + (x22383.tv_usec/1000)));
    printf("((NATION X (ORDERS X CUSTOMER)) X LINEITEM): leftParent.next done\n");
    gettimeofday(&x21162, NULL);
    timeval_subtract(&x22388, &x21162, &x21161);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x22388.tv_sec * 1000) + (x22388.tv_usec/1000)));
    printf("((NATION X (ORDERS X CUSTOMER)) X LINEITEM): rightParent.next start\n");
    struct timeval x21474, x21475, x22698;
    gettimeofday(&x21474, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x22392 = x22036;
      bool x22393 = !x22392;
      bool x22398 = x22393;
      if (x22393) {
        int x22394 = x22037;
        int x22395 = x21556;
        bool x22396 = x22394 < x22395;
        x22398 = x22396;
      }
      bool x22399 = x22398;
      if (!x22399) break;
      int x22402 = x22037;
      int* x22403 = x21558;
      int x22404 = x22403[x22402];
      double* x22413 = x21568;
      double x22414 = x22413[x22402];
      double* x22415 = x21570;
      double x22416 = x22415[x22402];
      char* x22419 = x21574;
      char x22420 = x22419[x22402];
      x22037 = x22037 + 1;
      bool x22436 = x22420 == 'R';
      if (x22436) {
        int x22437 = x22404 & 1048575;
        int x22438 = x22083[x22437];
        int x22439 = x22438;
        double x22440 = 1.0 - x22416;
        double x22441 = x22414 * x22440;
        for (;;) {
          int x22442 = x22439;
          bool x22443 = x22442 != -1;
          if (!x22443) break;
          int x22445 = x22439;
          char** x22448 = x22043;
          char* x22449 = x22448[x22445];
          int* x22454 = x22049;
          int x22455 = x22454[x22445];
          int* x22472 = x22067;
          int x22473 = x22472[x22445];
          char** x22474 = x22069;
          char* x22475 = x22474[x22445];
          char** x22476 = x22071;
          char* x22477 = x22476[x22445];
          char** x22480 = x22075;
          char* x22481 = x22480[x22445];
          double* x22482 = x22077;
          double x22483 = x22482[x22445];
          char** x22486 = x22081;
          char* x22487 = x22486[x22445];
          int x22488 = x22084[x22445];
          x22439 = x22488;
          bool x22490 = x22455 == x22404;
          if (x22490) {
            int x22492 = x22108;
            int x22493 = x22492 - 1;
            char x22494 = x22449[0];
            char x22495 = x22481[0];
            char x22496 = x22475[0];
            char x22497 = x22487[0];
            char x22498 = x22477[0];
            int x22499 = 31857 + x22498;
            int x22500 = x22499 * 41;
            int x22501 = x22500 + x22497;
            int x22502 = x22501 * 41;
            int x22503 = x22502 + x22473;
            int x22504 = x22503 * 41;
            int x22505 = x22504 + x22496;
            int x22506 = x22505 * 41;
            int x22507 = x22506 + x22495;
            int x22508 = x22507 * 41;
            int x22509 = x22508 + x22494;
            int x22510 = x22509 * 2;
            int x22511 = x22510 * 3;
            int x22512 = x22511 & x22493;
            int x22513 = x22512;
            int* x22514 = x22111;
            int x22515 = x22514[x22512];
            int x22516 = x22515;
            int x22517 = x22512 + 1;
            int x22518 = x22514[x22517];
            int x22519 = x22518;
            for (;;) {
              int x22520 = x22516;
              bool x22521 = x22520 != -1;
              bool x22573 = x22521;
              if (x22521) {
                int x22522 = x22519;
                bool x22523 = x22522 != x22511;
                bool x22569 = x22523;
                if (x22523 == false) {
                  int x22524 = x22516;
                  int* x22525 = x22093;
                  int x22526 = x22525[x22524];
                  char** x22527 = x22095;
                  char* x22528 = x22527[x22524];
                  double* x22529 = x22097;
                  double x22530 = x22529[x22524];
                  char** x22531 = x22099;
                  char* x22532 = x22531[x22524];
                  char** x22533 = x22101;
                  char* x22534 = x22533[x22524];
                  char** x22535 = x22103;
                  char* x22536 = x22535[x22524];
                  char** x22537 = x22105;
                  char* x22538 = x22537[x22524];
                  bool x22541 = x22526 == x22473;
                  bool x22544 = x22541;
                  if (x22541) {
                    bool x22542 = strcmp(x22528,x22475) == 0;;
                    x22544 = x22542;
                  }
                  bool x22545 = x22544;
                  bool x22548 = x22545;
                  if (x22545) {
                    bool x22546 = x22530 == x22483;
                    x22548 = x22546;
                  }
                  bool x22549 = x22548;
                  bool x22552 = x22549;
                  if (x22549) {
                    bool x22550 = strcmp(x22532,x22481) == 0;;
                    x22552 = x22550;
                  }
                  bool x22553 = x22552;
                  bool x22556 = x22553;
                  if (x22553) {
                    bool x22554 = strcmp(x22534,x22449) == 0;;
                    x22556 = x22554;
                  }
                  bool x22557 = x22556;
                  bool x22560 = x22557;
                  if (x22557) {
                    bool x22558 = strcmp(x22536,x22477) == 0;;
                    x22560 = x22558;
                  }
                  bool x22561 = x22560;
                  bool x22564 = x22561;
                  if (x22561) {
                    bool x22562 = strcmp(x22538,x22487) == 0;;
                    x22564 = x22562;
                  }
                  bool x22565 = x22564;
                  bool x22566 = !x22565;
                  x22569 = x22566;
                }
                bool x22570 = x22569;
                x22573 = x22570;
              }
              bool x22574 = x22573;
              if (!x22574) break;
              int x22577 = x22513;
              int x22578 = x22577 + 2;
              int x22579 = x22578 & x22493;
              x22513 = x22579;
              int* x22581 = x22111;
              int x22582 = x22581[x22579];
              x22516 = x22582;
              int x22584 = x22579 + 1;
              int x22585 = x22581[x22584];
              x22519 = x22585;
            }
            int x22590 = x22516;
            bool x22591 = x22590 == -1;
            int x22657;
            if (x22591) {
              int x22592 = x22109;
              int x22593 = x22513;
              x22514[x22593] = x22592;
              int x22595 = x22593 + 1;
              x22514[x22595] = x22511;
              x22109 = x22109 + 1;
              int x22598 = x22091;
              int x22599 = x22090;
              bool x22600 = x22598 == x22599;
              if (x22600) {
                int x22601 = x22599 * 4;
                x22090 = x22601;
                printf("buffer.resize %d\n",x22601);
                printf("buffer.resize %d\n",x22601);
                int* x22605 = x22093;
                int* x22606 = (int*)realloc(x22605,x22601 * sizeof(int));
                x22093 = x22606;
                char** x22608 = x22095;
                char** x22609 = (char**)realloc(x22608,x22601 * sizeof(char*));
                x22095 = x22609;
                double* x22611 = x22097;
                double* x22612 = (double*)realloc(x22611,x22601 * sizeof(double));
                x22097 = x22612;
                char** x22614 = x22099;
                char** x22615 = (char**)realloc(x22614,x22601 * sizeof(char*));
                x22099 = x22615;
                char** x22617 = x22101;
                char** x22618 = (char**)realloc(x22617,x22601 * sizeof(char*));
                x22101 = x22618;
                char** x22620 = x22103;
                char** x22621 = (char**)realloc(x22620,x22601 * sizeof(char*));
                x22103 = x22621;
                char** x22623 = x22105;
                char** x22624 = (char**)realloc(x22623,x22601 * sizeof(char*));
                x22105 = x22624;
                printf("buffer.resize %d\n",x22601);
                double* x22627 = x22107;
                double* x22628 = (double*)realloc(x22627,x22601 * sizeof(double));
                x22107 = x22628;
              } else {
              }
              int* x22632 = x22093;
              x22632[x22598] = x22473;
              char** x22634 = x22095;
              x22634[x22598] = x22475;
              double* x22636 = x22097;
              x22636[x22598] = x22483;
              char** x22638 = x22099;
              x22638[x22598] = x22481;
              char** x22640 = x22101;
              x22640[x22598] = x22449;
              char** x22642 = x22103;
              x22642[x22598] = x22477;
              char** x22644 = x22105;
              x22644[x22598] = x22487;
              double* x22646 = x22107;
              x22646[x22598] = 0.0;
              x22091 = x22091 + 1;
              int x22649 = x22109;
              int x22650 = x22649 * 4;
              bool x22651 = x22650 > x22492;
              if (x22651) {
                printf("%s\n","ERROR: hash.resize not implemented");
              } else {
              }
              x22657 = x22592;
            } else {
              x22657 = x22590;
            }
            int* x22658 = x22093;
            int x22659 = x22658[x22657];
            char** x22660 = x22095;
            char* x22661 = x22660[x22657];
            double* x22662 = x22097;
            double x22663 = x22662[x22657];
            char** x22664 = x22099;
            char* x22665 = x22664[x22657];
            char** x22666 = x22101;
            char* x22667 = x22666[x22657];
            char** x22668 = x22103;
            char* x22669 = x22668[x22657];
            char** x22670 = x22105;
            char* x22671 = x22670[x22657];
            double* x22672 = x22107;
            double x22673 = x22672[x22657];
            x22658[x22657] = x22659;
            x22660[x22657] = x22661;
            x22662[x22657] = x22663;
            x22664[x22657] = x22665;
            x22666[x22657] = x22667;
            x22668[x22657] = x22669;
            x22670[x22657] = x22671;
            double x22681 = x22673 + x22441;
            x22672[x22657] = x22681;
          } else {
          }
        }
      } else {
      }
    }
    printf("((NATION X (ORDERS X CUSTOMER)) X LINEITEM): rightParent.next done\n");
    gettimeofday(&x21475, NULL);
    timeval_subtract(&x22698, &x21475, &x21474);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x22698.tv_sec * 1000) + (x22698.tv_usec/1000)));
    int x22700 = x22091;
    int x21480;
    for(x21480=0; x21480 < x22700; x21480++) {
      int* x22701 = x22093;
      int x22702 = x22701[x21480];
      char** x22703 = x22095;
      char* x22704 = x22703[x21480];
      double* x22705 = x22097;
      double x22706 = x22705[x21480];
      char** x22707 = x22099;
      char* x22708 = x22707[x21480];
      char** x22709 = x22101;
      char* x22710 = x22709[x21480];
      char** x22711 = x22103;
      char* x22712 = x22711[x21480];
      char** x22713 = x22105;
      char* x22714 = x22713[x21480];
      double* x22715 = x22107;
      double x22716 = x22715[x21480];
      struct Anon1711779607* x22717 = (struct Anon1711779607*)malloc(sizeof(struct Anon1711779607));
      x22717->C_CUSTKEY = x22702;
      x22717->C_NAME = x22704;
      x22717->C_ACCTBAL = x22706;
      x22717->C_PHONE = x22708;
      x22717->N_NAME = x22710;
      x22717->C_ADDRESS = x22712;
      x22717->C_COMMENT = x22714;
      struct Anon2052879266* x22718 = (struct Anon2052879266*)malloc(sizeof(struct Anon2052879266));
      x22718->_0 = x22716;
      struct Anon417859734* x22719 = (struct Anon417859734*)malloc(sizeof(struct Anon417859734));
      x22719->key = x22717;
      x22719->aggs = x22718;
      g_tree_insert(x21986,x22719,x22719);; // x22720
    }
    for (;;) {
      int x22723 = g_tree_nnodes(x21986);
      bool x22724 = x22723 != 0;
      if (!x22724) break;
      struct Anon417859734* x22726 = NULL;
      g_tree_foreach(x21986, (GTraverseFunc)x22768, &x22726);
      g_tree_remove(x21986,x22726);
      int x22728 = x22119;
      bool x22729 = x22728 < 20;
      bool x22730 = x22729 == false;
      if (x22730) {
      } else {
        struct Anon1711779607* x22733 = x22726->key;;
        int x22734 = x22733->C_CUSTKEY;;
        char* x22735 = x22733->C_NAME;;
        struct Anon2052879266* x22736 = x22726->aggs;;
        double x22737 = x22736->_0;;
        double x22738 = x22733->C_ACCTBAL;;
        char* x22739 = x22733->N_NAME;;
        char* x22740 = x22733->C_ADDRESS;;
        char* x22741 = x22733->C_PHONE;;
        char* x22742 = x22733->C_COMMENT;;
        printf("%d|%s|%.4f|%.2f|%s|%s|%s|%s\n",x22734,x22735,x22737,x22738,x22739,x22740,x22741,x22742);
        x22119 = x22119 + 1;
        x22121 = x22121 + 1;
      }
    }
    int x22751 = x22121;
    printf("(%d rows)\n",x22751);
    gettimeofday(&x21534, NULL);
    timeval_subtract(&x22755, &x21534, &x21533);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x22755.tv_sec * 1000) + (x22755.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
