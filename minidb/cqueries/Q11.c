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
struct Anon2131541195* left;
struct Anon1286901926* right;
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
int x24403(struct Anon2053173900* x23086, struct Anon2053173900* x23085);
int x24409(struct Anon2053173900* x24404, struct Anon2053173900* x24405, struct Anon2053173900** x24406);
int x24403(struct Anon2053173900* x23086, struct Anon2053173900* x23085) {
  double x23087 = x23085->wnd;;
  double x23088 = x23086->wnd;;
  bool x23089 = x23087 > x23088;
  int x23816;
  if (x23089) {
    x23816 = -1;
  } else {
    bool x23090 = x23087 < x23088;
    int x23814;
    if (x23090) {
      x23814 = 1;
    } else {
      x23814 = 0;
    }
    x23816 = x23814;
  }
  return x23816;
}
int x24409(struct Anon2053173900* x24404, struct Anon2053173900* x24405, struct Anon2053173900** x24406) {
  *x24406 = x24405;
  return 0;
}

/************************ MAIN BODY **************************/
int main(int x22769, char** x22770) {
  FILE* x23607 = fopen("../databases/sf2/partsupp.tbl", "r");
  int x23608 = 1048576;
  int x23609 = 0;
  int* x23610 = (int*)malloc(1048576 * sizeof(int));
  int* x23611 = x23610;
  int* x23612 = (int*)malloc(1048576 * sizeof(int));
  int* x23613 = x23612;
  int* x23614 = (int*)malloc(1048576 * sizeof(int));
  int* x23615 = x23614;
  double* x23616 = (double*)malloc(1048576 * sizeof(double));
  double* x23617 = x23616;
  for (;;) {
    bool x23620 = !feof(x23607);
    if (!x23620) break;
    int x23622 = 0;
    if (fscanf(x23607,"%d|",&x23622) == EOF) break;
    int x23623 = 0;
    if (fscanf(x23607,"%d|",&x23623) == EOF) break;
    int x23624 = 0;
    if (fscanf(x23607,"%d|",&x23624) == EOF) break;
    double x23625 = 0.0;
    if (fscanf(x23607,"%lf|",&x23625) == EOF) break;
    char* x23626 = (char*)malloc(200 * sizeof(char));
    int x23628 = 0;
    char x23627 = ' ';
    while (1) {
      fscanf(x23607,"%c",&x23627);
      if (x23627=='|' || x23627=='\n') break;
      if (x23628>=199) { printf("ERROR: scanner.nextString reading past end of buffer %d",x23628); break;}
      ((char*)x23626)[x23628] = x23627;
      x23628 += 1;
    }
    ((char*)x23626)[x23628] = '\0';
    int x23631 = x23609;
    int x23632 = x23608;
    bool x23633 = x23631 == x23632;
    if (x23633) {
      int x23634 = x23632 * 4;
      x23608 = x23634;
      printf("buffer.resize %d\n",x23634);
      int* x23637 = x23611;
      int* x23638 = (int*)realloc(x23637,x23634 * sizeof(int));
      x23611 = x23638;
      int* x23640 = x23613;
      int* x23641 = (int*)realloc(x23640,x23634 * sizeof(int));
      x23613 = x23641;
      int* x23643 = x23615;
      int* x23644 = (int*)realloc(x23643,x23634 * sizeof(int));
      x23615 = x23644;
      double* x23646 = x23617;
      double* x23647 = (double*)realloc(x23646,x23634 * sizeof(double));
      x23617 = x23647;
    } else {
    }
    int* x23654 = x23611;
    x23654[x23631] = x23622;
    int* x23656 = x23613;
    x23656[x23631] = x23623;
    int* x23658 = x23615;
    x23658[x23631] = x23624;
    double* x23660 = x23617;
    x23660[x23631] = x23625;
    x23609 = x23609 + 1;
  }
  FILE* x23668 = fopen("../databases/sf2/supplier.tbl", "r");
  int x23669 = 1048576;
  int x23670 = 0;
  int* x23671 = (int*)malloc(1048576 * sizeof(int));
  int* x23672 = x23671;
  int* x23677 = (int*)malloc(1048576 * sizeof(int));
  int* x23678 = x23677;
  for (;;) {
    bool x23685 = !feof(x23668);
    if (!x23685) break;
    int x23687 = 0;
    if (fscanf(x23668,"%d|",&x23687) == EOF) break;
    char* x23688 = (char*)malloc(26 * sizeof(char));
    int x23690 = 0;
    char x23689 = ' ';
    while (1) {
      fscanf(x23668,"%c",&x23689);
      if (x23689=='|' || x23689=='\n') break;
      if (x23690>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x23690); break;}
      ((char*)x23688)[x23690] = x23689;
      x23690 += 1;
    }
    ((char*)x23688)[x23690] = '\0';
    char* x23693 = (char*)malloc(41 * sizeof(char));
    int x23695 = 0;
    char x23694 = ' ';
    while (1) {
      fscanf(x23668,"%c",&x23694);
      if (x23694=='|' || x23694=='\n') break;
      if (x23695>=40) { printf("ERROR: scanner.nextString reading past end of buffer %d",x23695); break;}
      ((char*)x23693)[x23695] = x23694;
      x23695 += 1;
    }
    ((char*)x23693)[x23695] = '\0';
    int x23698 = 0;
    if (fscanf(x23668,"%d|",&x23698) == EOF) break;
    char* x23699 = (char*)malloc(16 * sizeof(char));
    int x23701 = 0;
    char x23700 = ' ';
    while (1) {
      fscanf(x23668,"%c",&x23700);
      if (x23700=='|' || x23700=='\n') break;
      if (x23701>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x23701); break;}
      ((char*)x23699)[x23701] = x23700;
      x23701 += 1;
    }
    ((char*)x23699)[x23701] = '\0';
    double x23704 = 0.0;
    if (fscanf(x23668,"%lf|",&x23704) == EOF) break;
    char* x23705 = (char*)malloc(102 * sizeof(char));
    int x23707 = 0;
    char x23706 = ' ';
    while (1) {
      fscanf(x23668,"%c",&x23706);
      if (x23706=='|' || x23706=='\n') break;
      if (x23707>=101) { printf("ERROR: scanner.nextString reading past end of buffer %d",x23707); break;}
      ((char*)x23705)[x23707] = x23706;
      x23707 += 1;
    }
    ((char*)x23705)[x23707] = '\0';
    int x23710 = x23670;
    int x23711 = x23669;
    bool x23712 = x23710 == x23711;
    if (x23712) {
      int x23713 = x23711 * 4;
      x23669 = x23713;
      printf("buffer.resize %d\n",x23713);
      int* x23716 = x23672;
      int* x23717 = (int*)realloc(x23716,x23713 * sizeof(int));
      x23672 = x23717;
      int* x23725 = x23678;
      int* x23726 = (int*)realloc(x23725,x23713 * sizeof(int));
      x23678 = x23726;
    } else {
    }
    int* x23739 = x23672;
    x23739[x23710] = x23687;
    int* x23745 = x23678;
    x23745[x23710] = x23698;
    x23670 = x23670 + 1;
  }
  FILE* x23757 = fopen("../databases/sf2/nation.tbl", "r");
  int x23758 = 1048576;
  int x23759 = 0;
  int* x23760 = (int*)malloc(1048576 * sizeof(int));
  int* x23761 = x23760;
  char** x23762 = (char**)malloc(1048576 * sizeof(char*));
  char** x23763 = x23762;
  for (;;) {
    bool x23768 = !feof(x23757);
    if (!x23768) break;
    int x23770 = 0;
    if (fscanf(x23757,"%d|",&x23770) == EOF) break;
    char* x23771 = (char*)malloc(26 * sizeof(char));
    int x23773 = 0;
    char x23772 = ' ';
    while (1) {
      fscanf(x23757,"%c",&x23772);
      if (x23772=='|' || x23772=='\n') break;
      if (x23773>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x23773); break;}
      ((char*)x23771)[x23773] = x23772;
      x23773 += 1;
    }
    ((char*)x23771)[x23773] = '\0';
    char* x23775 = x23771; // unsafe immutable;
    int x23776 = 0;
    if (fscanf(x23757,"%d|",&x23776) == EOF) break;
    char* x23777 = (char*)malloc(153 * sizeof(char));
    int x23779 = 0;
    char x23778 = ' ';
    while (1) {
      fscanf(x23757,"%c",&x23778);
      if (x23778=='|' || x23778=='\n') break;
      if (x23779>=152) { printf("ERROR: scanner.nextString reading past end of buffer %d",x23779); break;}
      ((char*)x23777)[x23779] = x23778;
      x23779 += 1;
    }
    ((char*)x23777)[x23779] = '\0';
    int x23782 = x23759;
    int x23783 = x23758;
    bool x23784 = x23782 == x23783;
    if (x23784) {
      int x23785 = x23783 * 4;
      x23758 = x23785;
      printf("buffer.resize %d\n",x23785);
      int* x23788 = x23761;
      int* x23789 = (int*)realloc(x23788,x23785 * sizeof(int));
      x23761 = x23789;
      char** x23791 = x23763;
      char** x23792 = (char**)realloc(x23791,x23785 * sizeof(char*));
      x23763 = x23792;
    } else {
    }
    int* x23802 = x23761;
    x23802[x23782] = x23770;
    char** x23804 = x23763;
    x23804[x23782] = x23775;
    x23759 = x23759 + 1;
  }
  GTree* x23818 = g_tree_new((GCompareFunc)x24403);;
  bool x23819 = true == false;
  char x9501 = "Total"[0];
  int x9502 = x9501 * 2;
  int x9503 = x9502 * 3;
  int x22978;
  for(x22978=0; x22978 < 1; x22978++) {
    bool x23820 = false;
    int x23821 = 0;
    bool x23822 = false;
    int x23823 = 0;
    int* x23826 = (int*)malloc(1073741824 * sizeof(int));
    int* x23827 = x23826;
    int x23834 = 0;
    int* x23835 = (int*)malloc(1048576 * sizeof(int));
    int* x23836 = (int*)malloc(1073741824 * sizeof(int));
    int x22996;
    for(x22996=0; x22996 < 1048576; x22996++) {
      x23835[x22996] = -1;
    }
    bool x23841 = false;
    int x23842 = 0;
    int* x23852 = (int*)malloc(1073741824 * sizeof(int));
    int* x23853 = x23852;
    int x23866 = 0;
    int* x23867 = (int*)malloc(1048576 * sizeof(int));
    int* x23868 = (int*)malloc(1073741824 * sizeof(int));
    int x23029;
    for(x23029=0; x23029 < 1048576; x23029++) {
      x23867[x23029] = -1;
    }
    int x23874 = 1048576;
    int x23875 = 0;
    int* x23876 = (int*)malloc(1048576 * sizeof(int));
    int* x23877 = x23876;
    double* x23878 = (double*)malloc(1048576 * sizeof(double));
    double* x23879 = x23878;
    int x23880 = 4194304;
    int x23881 = 0;
    int* x23882 = (int*)malloc(4194304 * sizeof(int));
    int* x23883 = x23882;
    int x23045;
    for(x23045=0; x23045 < 4194304; x23045++) {
      int* x23884 = x23883;
      x23884[x23045] = -1;
    }
    int x23891 = 1048576;
    int x23892 = 0;
    int* x23893 = (int*)malloc(1048576 * sizeof(int));
    int* x23894 = x23893;
    double* x23895 = (double*)malloc(1048576 * sizeof(double));
    double* x23896 = x23895;
    int x23900 = 1048576;
    int x23901 = 0;
    char** x23902 = (char**)malloc(1048576 * sizeof(char*));
    char** x23903 = x23902;
    double* x23904 = (double*)malloc(1048576 * sizeof(double));
    double* x23905 = x23904;
    int x23906 = 4194304;
    int x23907 = 0;
    int* x23908 = (int*)malloc(4194304 * sizeof(int));
    int* x23909 = x23908;
    int x23072;
    for(x23072=0; x23072 < 4194304; x23072++) {
      int* x23910 = x23909;
      x23910[x23072] = -1;
    }
    struct Anon2131541195* x23919 = NULL;
    int x23923 = 0;
    struct timeval x23595, x23596, x24396;
    gettimeofday(&x23595, NULL);
    printf("((NATION X SUPPLIER) X PARTSUPP): leftParent.next start\n");
    struct timeval x23236, x23237, x24062;
    gettimeofday(&x23236, NULL);
    printf("(NATION X SUPPLIER): leftParent.next start\n");
    struct timeval x23140, x23141, x23970;
    gettimeofday(&x23140, NULL);
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x23927 = x23822;
      bool x23928 = !x23927;
      bool x23933 = x23928;
      if (x23928) {
        int x23929 = x23823;
        int x23930 = x23759;
        bool x23931 = x23929 < x23930;
        x23933 = x23931;
      }
      bool x23934 = x23933;
      if (!x23934) break;
      int x23937 = x23823;
      int* x23938 = x23761;
      int x23939 = x23938[x23937];
      char** x23940 = x23763;
      char* x23941 = x23940[x23937];
      x23823 = x23823 + 1;
      bool x23947 = strcmp(x23941,"UNITED KINGDOM") == 0;;
      if (x23947) {
        int x23948 = x23834;
        int* x23949 = x23827;
        x23949[x23948] = x23939;
        x23834 = x23834 + 1;
        int x23958 = x23939 & 1048575;
        int x23959 = x23835[x23958];
        x23835[x23958] = x23948;
        x23836[x23948] = x23959;
      } else {
      }
    }
    printf("(NATION X SUPPLIER): leftParent.next done\n");
    gettimeofday(&x23141, NULL);
    timeval_subtract(&x23970, &x23141, &x23140);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x23970.tv_sec * 1000) + (x23970.tv_usec/1000)));
    printf("(NATION X SUPPLIER): rightParent.next start\n");
    struct timeval x23230, x23231, x24057;
    gettimeofday(&x23230, NULL);
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x23974 = x23820;
      bool x23975 = !x23974;
      bool x23980 = x23975;
      if (x23975) {
        int x23976 = x23821;
        int x23977 = x23670;
        bool x23978 = x23976 < x23977;
        x23980 = x23978;
      }
      bool x23981 = x23980;
      if (!x23981) break;
      int x23984 = x23821;
      int* x23985 = x23672;
      int x23986 = x23985[x23984];
      int* x23991 = x23678;
      int x23992 = x23991[x23984];
      x23821 = x23821 + 1;
      int x24000 = x23992 & 1048575;
      int x24001 = x23835[x24000];
      int x24002 = x24001;
      int x24003 = x23986 & 1048575;
      for (;;) {
        int x24004 = x24002;
        bool x24005 = x24004 != -1;
        if (!x24005) break;
        int x24007 = x24002;
        int* x24008 = x23827;
        int x24009 = x24008[x24007];
        int x24016 = x23836[x24007];
        x24002 = x24016;
        bool x24018 = x24009 == x23992;
        if (x24018) {
          int x24019 = x23866;
          int* x24028 = x23853;
          x24028[x24019] = x23986;
          x23866 = x23866 + 1;
          int x24043 = x23867[x24003];
          x23867[x24003] = x24019;
          x23868[x24019] = x24043;
        } else {
        }
      }
    }
    printf("(NATION X SUPPLIER): rightParent.next done\n");
    gettimeofday(&x23231, NULL);
    timeval_subtract(&x24057, &x23231, &x23230);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x24057.tv_sec * 1000) + (x24057.tv_usec/1000)));
    printf("((NATION X SUPPLIER) X PARTSUPP): leftParent.next done\n");
    gettimeofday(&x23237, NULL);
    timeval_subtract(&x24062, &x23237, &x23236);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x24062.tv_sec * 1000) + (x24062.tv_usec/1000)));
    printf("((NATION X SUPPLIER) X PARTSUPP): rightParent.next start\n");
    struct timeval x23405, x23406, x24224;
    gettimeofday(&x23405, NULL);
    printf("%s\n","begin scan PARTSUPP");
    for (;;) {
      bool x24066 = x23841;
      bool x24067 = !x24066;
      bool x24072 = x24067;
      if (x24067) {
        int x24068 = x23842;
        int x24069 = x23609;
        bool x24070 = x24068 < x24069;
        x24072 = x24070;
      }
      bool x24073 = x24072;
      if (!x24073) break;
      int x24076 = x23842;
      int* x24077 = x23611;
      int x24078 = x24077[x24076];
      int* x24079 = x23613;
      int x24080 = x24079[x24076];
      int* x24081 = x23615;
      int x24082 = x24081[x24076];
      double* x24083 = x23617;
      double x24084 = x24083[x24076];
      x23842 = x23842 + 1;
      int x24088 = x24080 & 1048575;
      int x24089 = x23867[x24088];
      int x24090 = x24089;
      int x24091 = x24078 * 2;
      int x24092 = x24091 * 3;
      double x24093 = x24084 * x24082;
      for (;;) {
        int x24094 = x24090;
        bool x24095 = x24094 != -1;
        if (!x24095) break;
        int x24097 = x24090;
        int* x24106 = x23853;
        int x24107 = x24106[x24097];
        int x24120 = x23868[x24097];
        x24090 = x24120;
        bool x24122 = x24107 == x24080;
        if (x24122) {
          int x24124 = x23880;
          int x24125 = x24124 - 1;
          int x24126 = x24092 & x24125;
          int x24127 = x24126;
          int* x24128 = x23883;
          int x24129 = x24128[x24126];
          int x24130 = x24129;
          int x24131 = x24126 + 1;
          int x24132 = x24128[x24131];
          int x24133 = x24132;
          for (;;) {
            int x24134 = x24130;
            bool x24135 = x24134 != -1;
            bool x24151 = x24135;
            if (x24135) {
              int x24136 = x24133;
              bool x24137 = x24136 != x24092;
              bool x24147 = x24137;
              if (x24137 == false) {
                int x24138 = x24130;
                int* x24139 = x23877;
                int x24140 = x24139[x24138];
                bool x24143 = x24140 == x24078;
                bool x24144 = !x24143;
                x24147 = x24144;
              }
              bool x24148 = x24147;
              x24151 = x24148;
            }
            bool x24152 = x24151;
            if (!x24152) break;
            int x24155 = x24127;
            int x24156 = x24155 + 2;
            int x24157 = x24156 & x24125;
            x24127 = x24157;
            int* x24159 = x23883;
            int x24160 = x24159[x24157];
            x24130 = x24160;
            int x24162 = x24157 + 1;
            int x24163 = x24159[x24162];
            x24133 = x24163;
          }
          int x24168 = x24130;
          bool x24169 = x24168 == -1;
          int x24204;
          if (x24169) {
            int x24170 = x23881;
            int x24171 = x24127;
            x24128[x24171] = x24170;
            int x24173 = x24171 + 1;
            x24128[x24173] = x24092;
            x23881 = x23881 + 1;
            int x24176 = x23875;
            int x24177 = x23874;
            bool x24178 = x24176 == x24177;
            if (x24178) {
              int x24179 = x24177 * 4;
              x23874 = x24179;
              printf("buffer.resize %d\n",x24179);
              int* x24182 = x23877;
              int* x24183 = (int*)realloc(x24182,x24179 * sizeof(int));
              x23877 = x24183;
              printf("buffer.resize %d\n",x24179);
              double* x24186 = x23879;
              double* x24187 = (double*)realloc(x24186,x24179 * sizeof(double));
              x23879 = x24187;
            } else {
            }
            int* x24191 = x23877;
            x24191[x24176] = x24078;
            double* x24193 = x23879;
            x24193[x24176] = 0.0;
            x23875 = x23875 + 1;
            int x24196 = x23881;
            int x24197 = x24196 * 4;
            bool x24198 = x24197 > x24124;
            if (x24198) {
              printf("%s\n","ERROR: hash.resize not implemented");
            } else {
            }
            x24204 = x24170;
          } else {
            x24204 = x24168;
          }
          int* x24205 = x23877;
          int x24206 = x24205[x24204];
          double* x24207 = x23879;
          double x24208 = x24207[x24204];
          x24205[x24204] = x24206;
          double x24210 = x24208 + x24093;
          x24207[x24204] = x24210;
        } else {
        }
      }
    }
    printf("((NATION X SUPPLIER) X PARTSUPP): rightParent.next done\n");
    gettimeofday(&x23406, NULL);
    timeval_subtract(&x24224, &x23406, &x23405);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x24224.tv_sec * 1000) + (x24224.tv_usec/1000)));
    int x24226 = x23875;
    int x23411;
    for(x23411=0; x23411 < x24226; x23411++) {
      int* x24227 = x23877;
      int x24228 = x24227[x23411];
      double* x24229 = x23879;
      double x24230 = x24229[x23411];
      int x24231 = x23892;
      int x24232 = x23891;
      bool x24233 = x24231 == x24232;
      if (x24233) {
        int x24234 = x24232 * 4;
        x23891 = x24234;
        printf("buffer.resize %d\n",x24234);
        int* x24237 = x23894;
        int* x24238 = (int*)realloc(x24237,x24234 * sizeof(int));
        x23894 = x24238;
        printf("buffer.resize %d\n",x24234);
        double* x24241 = x23896;
        double* x24242 = (double*)realloc(x24241,x24234 * sizeof(double));
        x23896 = x24242;
      } else {
      }
      int* x24246 = x23894;
      x24246[x24231] = x24228;
      double* x24248 = x23896;
      x24248[x24231] = x24230;
      x23892 = x23892 + 1;
    }
    int x24254 = x23892;
    int x23442;
    for(x23442=0; x23442 < x24254; x23442++) {
      double* x24257 = x23896;
      double x24258 = x24257[x23442];
      int x24260 = x23906;
      int x24261 = x24260 - 1;
      int x24262 = x9503 & x24261;
      int x24263 = x24262;
      int* x24264 = x23909;
      int x24265 = x24264[x24262];
      int x24266 = x24265;
      int x24267 = x24262 + 1;
      int x24268 = x24264[x24267];
      int x24269 = x24268;
      for (;;) {
        int x24270 = x24266;
        bool x24271 = x24270 != -1;
        bool x24287 = x24271;
        if (x24271) {
          int x24272 = x24269;
          bool x24273 = x24272 != x9503;
          bool x24283 = x24273;
          if (x24273 == false) {
            int x24274 = x24266;
            char** x24275 = x23903;
            char* x24276 = x24275[x24274];
            bool x24279 = strcmp(x24276,"Total") == 0;;
            bool x24280 = !x24279;
            x24283 = x24280;
          }
          bool x24284 = x24283;
          x24287 = x24284;
        }
        bool x24288 = x24287;
        if (!x24288) break;
        int x24291 = x24263;
        int x24292 = x24291 + 2;
        int x24293 = x24292 & x24261;
        x24263 = x24293;
        int* x24295 = x23909;
        int x24296 = x24295[x24293];
        x24266 = x24296;
        int x24298 = x24293 + 1;
        int x24299 = x24295[x24298];
        x24269 = x24299;
      }
      int x24304 = x24266;
      bool x24305 = x24304 == -1;
      int x24340;
      if (x24305) {
        int x24306 = x23907;
        int x24307 = x24263;
        x24264[x24307] = x24306;
        int x24309 = x24307 + 1;
        x24264[x24309] = x9503;
        x23907 = x23907 + 1;
        int x24312 = x23901;
        int x24313 = x23900;
        bool x24314 = x24312 == x24313;
        if (x24314) {
          int x24315 = x24313 * 4;
          x23900 = x24315;
          printf("buffer.resize %d\n",x24315);
          char** x24318 = x23903;
          char** x24319 = (char**)realloc(x24318,x24315 * sizeof(char*));
          x23903 = x24319;
          printf("buffer.resize %d\n",x24315);
          double* x24322 = x23905;
          double* x24323 = (double*)realloc(x24322,x24315 * sizeof(double));
          x23905 = x24323;
        } else {
        }
        char** x24327 = x23903;
        x24327[x24312] = "Total";
        double* x24329 = x23905;
        x24329[x24312] = 0.0;
        x23901 = x23901 + 1;
        int x24332 = x23907;
        int x24333 = x24332 * 4;
        bool x24334 = x24333 > x24260;
        if (x24334) {
          printf("%s\n","ERROR: hash.resize not implemented");
        } else {
        }
        x24340 = x24306;
      } else {
        x24340 = x24304;
      }
      char** x24341 = x23903;
      char* x24342 = x24341[x24340];
      double* x24343 = x23905;
      double x24344 = x24343[x24340];
      x24341[x24340] = x24342;
      double x24346 = x24344 + x24258;
      x24343[x24340] = x24346;
    }
    int x24351 = x23901;
    int x23546;
    for(x23546=0; x23546 < x24351; x23546++) {
      double* x24354 = x23905;
      double x24355 = x24354[x23546];
      double x24356 = x24355 * 1.0E-4;
      struct Anon2131541195* x24357 = (struct Anon2131541195*)malloc(sizeof(struct Anon2131541195));
      x24357->total = x24356;
      x23919 = x24357;
      int x24359 = x23892;
      int x23558;
      for(x23558=0; x23558 < x24359; x23558++) {
        int* x24360 = x23894;
        int x24361 = x24360[x23558];
        double* x24362 = x23896;
        double x24363 = x24362[x23558];
        struct Anon2131541195* x24364 = x23919;
        double x24365 = x24364->total;;
        bool x24366 = x24363 > x24365;
        if (x24366) {
          struct Anon2053173900* x24367 = (struct Anon2053173900*)malloc(sizeof(struct Anon2053173900));
          x24367->key = x24361;
          x24367->wnd = x24363;
          g_tree_insert(x23818,x24367,x24367);; // x24368
        } else {
        }
      }
    }
    for (;;) {
      int x24376 = g_tree_nnodes(x23818);
      bool x24377 = x24376 != 0;
      if (!x24377) break;
      struct Anon2053173900* x24379 = NULL;
      g_tree_foreach(x23818, (GTraverseFunc)x24409, &x24379);
      g_tree_remove(x23818,x24379);
      if (x23819) {
      } else {
        int x24383 = x24379->key;;
        double x24384 = x24379->wnd;;
        printf("%d|%.2f\n",x24383,x24384);
        x23923 = x23923 + 1;
      }
    }
    int x24392 = x23923;
    printf("(%d rows)\n",x24392);
    gettimeofday(&x23596, NULL);
    timeval_subtract(&x24396, &x23596, &x23595);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x24396.tv_sec * 1000) + (x24396.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
