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
struct Anon1268892766* left;
struct Anon1286901926* right;
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

/************************ MAIN BODY **************************/
int main(int x28560, char** x28561) {
  FILE* x29331 = fopen("../databases/sf2/lineitem.tbl", "r");
  int x29332 = 1048576;
  int x29333 = 0;
  int* x29338 = (int*)malloc(1048576 * sizeof(int));
  int* x29339 = x29338;
  double* x29344 = (double*)malloc(1048576 * sizeof(double));
  double* x29345 = x29344;
  double* x29346 = (double*)malloc(1048576 * sizeof(double));
  double* x29347 = x29346;
  long* x29354 = (long*)malloc(1048576 * sizeof(long));
  long* x29355 = x29354;
  for (;;) {
    bool x29366 = !feof(x29331);
    if (!x29366) break;
    int x29368 = 0;
    if (fscanf(x29331,"%d|",&x29368) == EOF) break;
    int x29369 = 0;
    if (fscanf(x29331,"%d|",&x29369) == EOF) break;
    int x29370 = 0;
    if (fscanf(x29331,"%d|",&x29370) == EOF) break;
    int x29371 = 0;
    if (fscanf(x29331,"%d|",&x29371) == EOF) break;
    double x29372 = 0.0;
    if (fscanf(x29331,"%lf|",&x29372) == EOF) break;
    double x29373 = 0.0;
    if (fscanf(x29331,"%lf|",&x29373) == EOF) break;
    double x29374 = 0.0;
    if (fscanf(x29331,"%lf|",&x29374) == EOF) break;
    double x29375 = 0.0;
    if (fscanf(x29331,"%lf|",&x29375) == EOF) break;
    char x29376 = ' ';
    if (fscanf(x29331,"%c|",&x29376) == EOF) break;
    char x29377 = ' ';
    if (fscanf(x29331,"%c|",&x29377) == EOF) break;
    int x29378 = 0;
    int x29379 = 0;
    int x29380 = 0;
    fscanf(x29331, "%d-%d-%d|",&x29378, &x29379, &x29380);
    long x29381 = (x29378 * 10000) + (x29379 * 100) + x29380;
    int x29382 = 0;
    int x29383 = 0;
    int x29384 = 0;
    fscanf(x29331, "%d-%d-%d|",&x29382, &x29383, &x29384);
    long x29385 = (x29382 * 10000) + (x29383 * 100) + x29384;
    int x29386 = 0;
    int x29387 = 0;
    int x29388 = 0;
    fscanf(x29331, "%d-%d-%d|",&x29386, &x29387, &x29388);
    long x29389 = (x29386 * 10000) + (x29387 * 100) + x29388;
    char* x29390 = (char*)malloc(26 * sizeof(char));
    int x29392 = 0;
    char x29391 = ' ';
    while (1) {
      fscanf(x29331,"%c",&x29391);
      if (x29391=='|' || x29391=='\n') break;
      if (x29392>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x29392); break;}
      ((char*)x29390)[x29392] = x29391;
      x29392 += 1;
    }
    ((char*)x29390)[x29392] = '\0';
    char* x29395 = (char*)malloc(11 * sizeof(char));
    int x29397 = 0;
    char x29396 = ' ';
    while (1) {
      fscanf(x29331,"%c",&x29396);
      if (x29396=='|' || x29396=='\n') break;
      if (x29397>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x29397); break;}
      ((char*)x29395)[x29397] = x29396;
      x29397 += 1;
    }
    ((char*)x29395)[x29397] = '\0';
    char* x29400 = (char*)malloc(45 * sizeof(char));
    int x29402 = 0;
    char x29401 = ' ';
    while (1) {
      fscanf(x29331,"%c",&x29401);
      if (x29401=='|' || x29401=='\n') break;
      if (x29402>=44) { printf("ERROR: scanner.nextString reading past end of buffer %d",x29402); break;}
      ((char*)x29400)[x29402] = x29401;
      x29402 += 1;
    }
    ((char*)x29400)[x29402] = '\0';
    int x29405 = x29333;
    int x29406 = x29332;
    bool x29407 = x29405 == x29406;
    if (x29407) {
      int x29408 = x29406 * 4;
      x29332 = x29408;
      printf("buffer.resize %d\n",x29408);
      int* x29417 = x29339;
      int* x29418 = (int*)realloc(x29417,x29408 * sizeof(int));
      x29339 = x29418;
      double* x29426 = x29345;
      double* x29427 = (double*)realloc(x29426,x29408 * sizeof(double));
      x29345 = x29427;
      double* x29429 = x29347;
      double* x29430 = (double*)realloc(x29429,x29408 * sizeof(double));
      x29347 = x29430;
      long* x29441 = x29355;
      long* x29442 = (long*)realloc(x29441,x29408 * sizeof(long));
      x29355 = x29442;
    } else {
    }
    int* x29465 = x29339;
    x29465[x29405] = x29370;
    double* x29471 = x29345;
    x29471[x29405] = x29373;
    double* x29473 = x29347;
    x29473[x29405] = x29374;
    long* x29481 = x29355;
    x29481[x29405] = x29381;
    x29333 = x29333 + 1;
  }
  FILE* x29497 = fopen("../databases/sf2/supplier.tbl", "r");
  int x29498 = 1048576;
  int x29499 = 0;
  int* x29500 = (int*)malloc(1048576 * sizeof(int));
  int* x29501 = x29500;
  char** x29502 = (char**)malloc(1048576 * sizeof(char*));
  char** x29503 = x29502;
  char** x29504 = (char**)malloc(1048576 * sizeof(char*));
  char** x29505 = x29504;
  char** x29508 = (char**)malloc(1048576 * sizeof(char*));
  char** x29509 = x29508;
  for (;;) {
    bool x29514 = !feof(x29497);
    if (!x29514) break;
    int x29516 = 0;
    if (fscanf(x29497,"%d|",&x29516) == EOF) break;
    char* x29517 = (char*)malloc(26 * sizeof(char));
    int x29519 = 0;
    char x29518 = ' ';
    while (1) {
      fscanf(x29497,"%c",&x29518);
      if (x29518=='|' || x29518=='\n') break;
      if (x29519>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x29519); break;}
      ((char*)x29517)[x29519] = x29518;
      x29519 += 1;
    }
    ((char*)x29517)[x29519] = '\0';
    char* x29521 = x29517; // unsafe immutable;
    char* x29522 = (char*)malloc(41 * sizeof(char));
    int x29524 = 0;
    char x29523 = ' ';
    while (1) {
      fscanf(x29497,"%c",&x29523);
      if (x29523=='|' || x29523=='\n') break;
      if (x29524>=40) { printf("ERROR: scanner.nextString reading past end of buffer %d",x29524); break;}
      ((char*)x29522)[x29524] = x29523;
      x29524 += 1;
    }
    ((char*)x29522)[x29524] = '\0';
    char* x29526 = x29522; // unsafe immutable;
    int x29527 = 0;
    if (fscanf(x29497,"%d|",&x29527) == EOF) break;
    char* x29528 = (char*)malloc(16 * sizeof(char));
    int x29530 = 0;
    char x29529 = ' ';
    while (1) {
      fscanf(x29497,"%c",&x29529);
      if (x29529=='|' || x29529=='\n') break;
      if (x29530>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x29530); break;}
      ((char*)x29528)[x29530] = x29529;
      x29530 += 1;
    }
    ((char*)x29528)[x29530] = '\0';
    char* x29532 = x29528; // unsafe immutable;
    double x29533 = 0.0;
    if (fscanf(x29497,"%lf|",&x29533) == EOF) break;
    char* x29534 = (char*)malloc(102 * sizeof(char));
    int x29536 = 0;
    char x29535 = ' ';
    while (1) {
      fscanf(x29497,"%c",&x29535);
      if (x29535=='|' || x29535=='\n') break;
      if (x29536>=101) { printf("ERROR: scanner.nextString reading past end of buffer %d",x29536); break;}
      ((char*)x29534)[x29536] = x29535;
      x29536 += 1;
    }
    ((char*)x29534)[x29536] = '\0';
    int x29539 = x29499;
    int x29540 = x29498;
    bool x29541 = x29539 == x29540;
    if (x29541) {
      int x29542 = x29540 * 4;
      x29498 = x29542;
      printf("buffer.resize %d\n",x29542);
      int* x29545 = x29501;
      int* x29546 = (int*)realloc(x29545,x29542 * sizeof(int));
      x29501 = x29546;
      char** x29548 = x29503;
      char** x29549 = (char**)realloc(x29548,x29542 * sizeof(char*));
      x29503 = x29549;
      char** x29551 = x29505;
      char** x29552 = (char**)realloc(x29551,x29542 * sizeof(char*));
      x29505 = x29552;
      char** x29557 = x29509;
      char** x29558 = (char**)realloc(x29557,x29542 * sizeof(char*));
      x29509 = x29558;
    } else {
    }
    int* x29568 = x29501;
    x29568[x29539] = x29516;
    char** x29570 = x29503;
    x29570[x29539] = x29521;
    char** x29572 = x29505;
    x29572[x29539] = x29526;
    char** x29576 = x29509;
    x29576[x29539] = x29532;
    x29499 = x29499 + 1;
  }
  bool x29586 = true == false;
  char x29149 = "MAXREVENUE"[0];
  int x29150 = x29149 * 2;
  int x29151 = x29150 * 3;
  int x28817;
  for(x28817=0; x28817 < 1; x28817++) {
    bool x29587 = false;
    int x29588 = 0;
    int x29591 = 1048576;
    int x29592 = 0;
    int* x29593 = (int*)malloc(1048576 * sizeof(int));
    int* x29594 = x29593;
    double* x29595 = (double*)malloc(1048576 * sizeof(double));
    double* x29596 = x29595;
    int x29597 = 4194304;
    int x29598 = 0;
    int* x29599 = (int*)malloc(4194304 * sizeof(int));
    int* x29600 = x29599;
    int x28832;
    for(x28832=0; x28832 < 4194304; x28832++) {
      int* x29601 = x29600;
      x29601[x28832] = -1;
    }
    int x29608 = 1048576;
    int x29609 = 0;
    int* x29610 = (int*)malloc(1048576 * sizeof(int));
    int* x29611 = x29610;
    double* x29612 = (double*)malloc(1048576 * sizeof(double));
    double* x29613 = x29612;
    int x29617 = 1048576;
    int x29618 = 0;
    char** x29619 = (char**)malloc(1048576 * sizeof(char*));
    char** x29620 = x29619;
    double* x29621 = (double*)malloc(1048576 * sizeof(double));
    double* x29622 = x29621;
    int x29623 = 4194304;
    int x29624 = 0;
    int* x29625 = (int*)malloc(4194304 * sizeof(int));
    int* x29626 = x29625;
    int x28859;
    for(x28859=0; x28859 < 4194304; x28859++) {
      int* x29627 = x29626;
      x29627[x28859] = -1;
    }
    struct Anon2131541195* x29636 = NULL;
    bool x29638 = false;
    int x29639 = 0;
    int* x29641 = (int*)malloc(1073741824 * sizeof(int));
    int* x29642 = x29641;
    char** x29643 = (char**)malloc(1073741824 * sizeof(char*));
    char** x29644 = x29643;
    char** x29645 = (char**)malloc(1073741824 * sizeof(char*));
    char** x29646 = x29645;
    char** x29649 = (char**)malloc(1073741824 * sizeof(char*));
    char** x29650 = x29649;
    int x29655 = 0;
    int* x29656 = (int*)malloc(1048576 * sizeof(int));
    int* x29657 = (int*)malloc(1073741824 * sizeof(int));
    int x28891;
    for(x28891=0; x28891 < 1048576; x28891++) {
      x29656[x28891] = -1;
    }
    int x29663 = 0;
    struct timeval x29323, x29324, x30063;
    gettimeofday(&x29323, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x29665 = x29587;
      bool x29666 = !x29665;
      bool x29671 = x29666;
      if (x29666) {
        int x29667 = x29588;
        int x29668 = x29333;
        bool x29669 = x29667 < x29668;
        x29671 = x29669;
      }
      bool x29672 = x29671;
      if (!x29672) break;
      int x29675 = x29588;
      int* x29680 = x29339;
      int x29681 = x29680[x29675];
      double* x29686 = x29345;
      double x29687 = x29686[x29675];
      double* x29688 = x29347;
      double x29689 = x29688[x29675];
      long* x29696 = x29355;
      long x29697 = x29696[x29675];
      x29588 = x29588 + 1;
      bool x29709 = x29697 >= 19930901L;
      bool x29711 = x29709;
      if (x29709) {
        bool x29710 = x29697 < 19931201L;
        x29711 = x29710;
      }
      bool x29712 = x29711;
      if (x29712) {
        int x29714 = x29597;
        int x29715 = x29714 - 1;
        int x29716 = x29681 * 2;
        int x29717 = x29716 * 3;
        int x29718 = x29717 & x29715;
        int x29719 = x29718;
        int* x29720 = x29600;
        int x29721 = x29720[x29718];
        int x29722 = x29721;
        int x29723 = x29718 + 1;
        int x29724 = x29720[x29723];
        int x29725 = x29724;
        for (;;) {
          int x29726 = x29722;
          bool x29727 = x29726 != -1;
          bool x29743 = x29727;
          if (x29727) {
            int x29728 = x29725;
            bool x29729 = x29728 != x29717;
            bool x29739 = x29729;
            if (x29729 == false) {
              int x29730 = x29722;
              int* x29731 = x29594;
              int x29732 = x29731[x29730];
              bool x29735 = x29732 == x29681;
              bool x29736 = !x29735;
              x29739 = x29736;
            }
            bool x29740 = x29739;
            x29743 = x29740;
          }
          bool x29744 = x29743;
          if (!x29744) break;
          int x29747 = x29719;
          int x29748 = x29747 + 2;
          int x29749 = x29748 & x29715;
          x29719 = x29749;
          int* x29751 = x29600;
          int x29752 = x29751[x29749];
          x29722 = x29752;
          int x29754 = x29749 + 1;
          int x29755 = x29751[x29754];
          x29725 = x29755;
        }
        int x29760 = x29722;
        bool x29761 = x29760 == -1;
        int x29796;
        if (x29761) {
          int x29762 = x29598;
          int x29763 = x29719;
          x29720[x29763] = x29762;
          int x29765 = x29763 + 1;
          x29720[x29765] = x29717;
          x29598 = x29598 + 1;
          int x29768 = x29592;
          int x29769 = x29591;
          bool x29770 = x29768 == x29769;
          if (x29770) {
            int x29771 = x29769 * 4;
            x29591 = x29771;
            printf("buffer.resize %d\n",x29771);
            int* x29774 = x29594;
            int* x29775 = (int*)realloc(x29774,x29771 * sizeof(int));
            x29594 = x29775;
            printf("buffer.resize %d\n",x29771);
            double* x29778 = x29596;
            double* x29779 = (double*)realloc(x29778,x29771 * sizeof(double));
            x29596 = x29779;
          } else {
          }
          int* x29783 = x29594;
          x29783[x29768] = x29681;
          double* x29785 = x29596;
          x29785[x29768] = 0.0;
          x29592 = x29592 + 1;
          int x29788 = x29598;
          int x29789 = x29788 * 4;
          bool x29790 = x29789 > x29714;
          if (x29790) {
            printf("%s\n","ERROR: hash.resize not implemented");
          } else {
          }
          x29796 = x29762;
        } else {
          x29796 = x29760;
        }
        int* x29797 = x29594;
        int x29798 = x29797[x29796];
        double* x29799 = x29596;
        double x29800 = x29799[x29796];
        x29797[x29796] = x29798;
        double x29802 = 1.0 - x29689;
        double x29803 = x29687 * x29802;
        double x29804 = x29800 + x29803;
        x29799[x29796] = x29804;
      } else {
      }
    }
    int x29812 = x29592;
    int x29051;
    for(x29051=0; x29051 < x29812; x29051++) {
      int* x29813 = x29594;
      int x29814 = x29813[x29051];
      double* x29815 = x29596;
      double x29816 = x29815[x29051];
      int x29817 = x29609;
      int x29818 = x29608;
      bool x29819 = x29817 == x29818;
      if (x29819) {
        int x29820 = x29818 * 4;
        x29608 = x29820;
        printf("buffer.resize %d\n",x29820);
        int* x29823 = x29611;
        int* x29824 = (int*)realloc(x29823,x29820 * sizeof(int));
        x29611 = x29824;
        printf("buffer.resize %d\n",x29820);
        double* x29827 = x29613;
        double* x29828 = (double*)realloc(x29827,x29820 * sizeof(double));
        x29613 = x29828;
      } else {
      }
      int* x29832 = x29611;
      x29832[x29817] = x29814;
      double* x29834 = x29613;
      x29834[x29817] = x29816;
      x29609 = x29609 + 1;
    }
    printf("(SUPPLIER X op(?)): leftParent.next start\n");
    struct timeval x29132, x29133, x29893;
    gettimeofday(&x29132, NULL);
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x29842 = x29638;
      bool x29843 = !x29842;
      bool x29848 = x29843;
      if (x29843) {
        int x29844 = x29639;
        int x29845 = x29499;
        bool x29846 = x29844 < x29845;
        x29848 = x29846;
      }
      bool x29849 = x29848;
      if (!x29849) break;
      int x29852 = x29639;
      int* x29853 = x29501;
      int x29854 = x29853[x29852];
      char** x29855 = x29503;
      char* x29856 = x29855[x29852];
      char** x29857 = x29505;
      char* x29858 = x29857[x29852];
      char** x29861 = x29509;
      char* x29862 = x29861[x29852];
      x29639 = x29639 + 1;
      int x29868 = x29655;
      int* x29869 = x29642;
      x29869[x29868] = x29854;
      char** x29871 = x29644;
      x29871[x29868] = x29856;
      char** x29873 = x29646;
      x29873[x29868] = x29858;
      char** x29877 = x29650;
      x29877[x29868] = x29862;
      x29655 = x29655 + 1;
      int x29884 = x29854 & 1048575;
      int x29885 = x29656[x29884];
      x29656[x29884] = x29868;
      x29657[x29868] = x29885;
    }
    printf("(SUPPLIER X op(?)): leftParent.next done\n");
    gettimeofday(&x29133, NULL);
    timeval_subtract(&x29893, &x29133, &x29132);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x29893.tv_sec * 1000) + (x29893.tv_usec/1000)));
    printf("(SUPPLIER X op(?)): rightParent.next start\n");
    struct timeval x29316, x29317, x30057;
    gettimeofday(&x29316, NULL);
    int x29896 = x29609;
    int x29139;
    for(x29139=0; x29139 < x29896; x29139++) {
      double* x29899 = x29613;
      double x29900 = x29899[x29139];
      int x29902 = x29623;
      int x29903 = x29902 - 1;
      int x29904 = x29151 & x29903;
      int x29905 = x29904;
      int* x29906 = x29626;
      int x29907 = x29906[x29904];
      int x29908 = x29907;
      int x29909 = x29904 + 1;
      int x29910 = x29906[x29909];
      int x29911 = x29910;
      for (;;) {
        int x29912 = x29908;
        bool x29913 = x29912 != -1;
        bool x29929 = x29913;
        if (x29913) {
          int x29914 = x29911;
          bool x29915 = x29914 != x29151;
          bool x29925 = x29915;
          if (x29915 == false) {
            int x29916 = x29908;
            char** x29917 = x29620;
            char* x29918 = x29917[x29916];
            bool x29921 = strcmp(x29918,"MAXREVENUE") == 0;;
            bool x29922 = !x29921;
            x29925 = x29922;
          }
          bool x29926 = x29925;
          x29929 = x29926;
        }
        bool x29930 = x29929;
        if (!x29930) break;
        int x29933 = x29905;
        int x29934 = x29933 + 2;
        int x29935 = x29934 & x29903;
        x29905 = x29935;
        int* x29937 = x29626;
        int x29938 = x29937[x29935];
        x29908 = x29938;
        int x29940 = x29935 + 1;
        int x29941 = x29937[x29940];
        x29911 = x29941;
      }
      int x29946 = x29908;
      bool x29947 = x29946 == -1;
      int x29982;
      if (x29947) {
        int x29948 = x29624;
        int x29949 = x29905;
        x29906[x29949] = x29948;
        int x29951 = x29949 + 1;
        x29906[x29951] = x29151;
        x29624 = x29624 + 1;
        int x29954 = x29618;
        int x29955 = x29617;
        bool x29956 = x29954 == x29955;
        if (x29956) {
          int x29957 = x29955 * 4;
          x29617 = x29957;
          printf("buffer.resize %d\n",x29957);
          char** x29960 = x29620;
          char** x29961 = (char**)realloc(x29960,x29957 * sizeof(char*));
          x29620 = x29961;
          printf("buffer.resize %d\n",x29957);
          double* x29964 = x29622;
          double* x29965 = (double*)realloc(x29964,x29957 * sizeof(double));
          x29622 = x29965;
        } else {
        }
        char** x29969 = x29620;
        x29969[x29954] = "MAXREVENUE";
        double* x29971 = x29622;
        x29971[x29954] = 0.0;
        x29618 = x29618 + 1;
        int x29974 = x29624;
        int x29975 = x29974 * 4;
        bool x29976 = x29975 > x29902;
        if (x29976) {
          printf("%s\n","ERROR: hash.resize not implemented");
        } else {
        }
        x29982 = x29948;
      } else {
        x29982 = x29946;
      }
      char** x29983 = x29620;
      char* x29984 = x29983[x29982];
      double* x29985 = x29622;
      double x29986 = x29985[x29982];
      x29983[x29982] = x29984;
      bool x29988 = x29986 < x29900;
      double x29989;
      if (x29988) {
        x29989 = x29900;
      } else {
        x29989 = x29986;
      }
      x29985[x29982] = x29989;
    }
    int x29994 = x29618;
    int x29248;
    for(x29248=0; x29248 < x29994; x29248++) {
      double* x29997 = x29622;
      double x29998 = x29997[x29248];
      struct Anon2131541195* x29999 = (struct Anon2131541195*)malloc(sizeof(struct Anon2131541195));
      x29999->total = x29998;
      x29636 = x29999;
      int x30001 = x29609;
      int x29259;
      for(x29259=0; x29259 < x30001; x29259++) {
        int* x30002 = x29611;
        int x30003 = x30002[x29259];
        double* x30004 = x29613;
        double x30005 = x30004[x29259];
        struct Anon2131541195* x30006 = x29636;
        double x30007 = x30006->total;;
        bool x30008 = x30005 == x30007;
        if (x30008) {
          int x30009 = x30003 & 1048575;
          int x30010 = x29656[x30009];
          int x30011 = x30010;
          for (;;) {
            int x30012 = x30011;
            bool x30013 = x30012 != -1;
            if (!x30013) break;
            int x30015 = x30011;
            int* x30016 = x29642;
            int x30017 = x30016[x30015];
            char** x30018 = x29644;
            char* x30019 = x30018[x30015];
            char** x30020 = x29646;
            char* x30021 = x30020[x30015];
            char** x30024 = x29650;
            char* x30025 = x30024[x30015];
            int x30030 = x29657[x30015];
            x30011 = x30030;
            bool x30032 = x30017 == x30003;
            if (x30032) {
              if (x29586) {
              } else {
                printf("%d|%s|%s|%s|%.4f\n",x30017,x30019,x30021,x30025,x30005);
                x29663 = x29663 + 1;
              }
            } else {
            }
          }
        } else {
        }
      }
    }
    printf("(SUPPLIER X op(?)): rightParent.next done\n");
    gettimeofday(&x29317, NULL);
    timeval_subtract(&x30057, &x29317, &x29316);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x30057.tv_sec * 1000) + (x30057.tv_usec/1000)));
    int x30059 = x29663;
    printf("(%d rows)\n",x30059);
    gettimeofday(&x29324, NULL);
    timeval_subtract(&x30063, &x29324, &x29323);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x30063.tv_sec * 1000) + (x30063.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
