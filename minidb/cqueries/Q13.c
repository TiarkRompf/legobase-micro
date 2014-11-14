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
struct Anon920667905* left;
struct Anon811555534* right;
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
int x27288(struct Anon955262776* x26031, struct Anon955262776* x26030);
int x27294(struct Anon955262776* x27289, struct Anon955262776* x27290, struct Anon955262776** x27291);
int x27288(struct Anon955262776* x26031, struct Anon955262776* x26030) {
  struct Anon2052879266* x26032 = x26030->aggs;;
  double x26033 = x26032->_0;;
  struct Anon2052879266* x26034 = x26031->aggs;;
  double x26035 = x26034->_0;;
  bool x26036 = x26033 < x26035;
  int x26760;
  if (x26036) {
    x26760 = 1;
  } else {
    bool x26037 = x26033 > x26035;
    int x26758;
    if (x26037) {
      x26758 = -1;
    } else {
      double x26038 = x26030->key;;
      double x26039 = x26031->key;;
      bool x26040 = x26038 < x26039;
      int x26756;
      if (x26040) {
        x26756 = 1;
      } else {
        bool x26041 = x26038 > x26039;
        int x26754;
        if (x26041) {
          x26754 = -1;
        } else {
          x26754 = 0;
        }
        x26756 = x26754;
      }
      x26758 = x26756;
    }
    x26760 = x26758;
  }
  return x26760;
}
int x27294(struct Anon955262776* x27289, struct Anon955262776* x27290, struct Anon955262776** x27291) {
  *x27291 = x27290;
  return 0;
}

/************************ MAIN BODY **************************/
int main(int x25752, char** x25753) {
  FILE* x26548 = fopen("../databases/sf2/customer.tbl", "r");
  int x26549 = 1048576;
  int x26550 = 0;
  int* x26551 = (int*)malloc(1048576 * sizeof(int));
  int* x26552 = x26551;
  for (;;) {
    bool x26567 = !feof(x26548);
    if (!x26567) break;
    int x26569 = 0;
    if (fscanf(x26548,"%d|",&x26569) == EOF) break;
    char* x26570 = (char*)malloc(26 * sizeof(char));
    int x26572 = 0;
    char x26571 = ' ';
    while (1) {
      fscanf(x26548,"%c",&x26571);
      if (x26571=='|' || x26571=='\n') break;
      if (x26572>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x26572); break;}
      ((char*)x26570)[x26572] = x26571;
      x26572 += 1;
    }
    ((char*)x26570)[x26572] = '\0';
    char* x26575 = (char*)malloc(41 * sizeof(char));
    int x26577 = 0;
    char x26576 = ' ';
    while (1) {
      fscanf(x26548,"%c",&x26576);
      if (x26576=='|' || x26576=='\n') break;
      if (x26577>=40) { printf("ERROR: scanner.nextString reading past end of buffer %d",x26577); break;}
      ((char*)x26575)[x26577] = x26576;
      x26577 += 1;
    }
    ((char*)x26575)[x26577] = '\0';
    int x26580 = 0;
    if (fscanf(x26548,"%d|",&x26580) == EOF) break;
    char* x26581 = (char*)malloc(16 * sizeof(char));
    int x26583 = 0;
    char x26582 = ' ';
    while (1) {
      fscanf(x26548,"%c",&x26582);
      if (x26582=='|' || x26582=='\n') break;
      if (x26583>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x26583); break;}
      ((char*)x26581)[x26583] = x26582;
      x26583 += 1;
    }
    ((char*)x26581)[x26583] = '\0';
    double x26586 = 0.0;
    if (fscanf(x26548,"%lf|",&x26586) == EOF) break;
    char* x26587 = (char*)malloc(11 * sizeof(char));
    int x26589 = 0;
    char x26588 = ' ';
    while (1) {
      fscanf(x26548,"%c",&x26588);
      if (x26588=='|' || x26588=='\n') break;
      if (x26589>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x26589); break;}
      ((char*)x26587)[x26589] = x26588;
      x26589 += 1;
    }
    ((char*)x26587)[x26589] = '\0';
    char* x26592 = (char*)malloc(118 * sizeof(char));
    int x26594 = 0;
    char x26593 = ' ';
    while (1) {
      fscanf(x26548,"%c",&x26593);
      if (x26593=='|' || x26593=='\n') break;
      if (x26594>=117) { printf("ERROR: scanner.nextString reading past end of buffer %d",x26594); break;}
      ((char*)x26592)[x26594] = x26593;
      x26594 += 1;
    }
    ((char*)x26592)[x26594] = '\0';
    int x26597 = x26550;
    int x26598 = x26549;
    bool x26599 = x26597 == x26598;
    if (x26599) {
      int x26600 = x26598 * 4;
      x26549 = x26600;
      printf("buffer.resize %d\n",x26600);
      int* x26603 = x26552;
      int* x26604 = (int*)realloc(x26603,x26600 * sizeof(int));
      x26552 = x26604;
    } else {
    }
    int* x26629 = x26552;
    x26629[x26597] = x26569;
    x26550 = x26550 + 1;
  }
  FILE* x26649 = fopen("../databases/sf2/orders.tbl", "r");
  int x26650 = 1048576;
  int x26651 = 0;
  int* x26652 = (int*)malloc(1048576 * sizeof(int));
  int* x26653 = x26652;
  int* x26654 = (int*)malloc(1048576 * sizeof(int));
  int* x26655 = x26654;
  char** x26668 = (char**)malloc(1048576 * sizeof(char*));
  char** x26669 = x26668;
  for (;;) {
    bool x26670 = !feof(x26649);
    if (!x26670) break;
    int x26672 = 0;
    if (fscanf(x26649,"%d|",&x26672) == EOF) break;
    int x26673 = 0;
    if (fscanf(x26649,"%d|",&x26673) == EOF) break;
    char x26674 = ' ';
    if (fscanf(x26649,"%c|",&x26674) == EOF) break;
    double x26675 = 0.0;
    if (fscanf(x26649,"%lf|",&x26675) == EOF) break;
    int x26676 = 0;
    int x26677 = 0;
    int x26678 = 0;
    fscanf(x26649, "%d-%d-%d|",&x26676, &x26677, &x26678);
    long x26679 = (x26676 * 10000) + (x26677 * 100) + x26678;
    char* x26680 = (char*)malloc(16 * sizeof(char));
    int x26682 = 0;
    char x26681 = ' ';
    while (1) {
      fscanf(x26649,"%c",&x26681);
      if (x26681=='|' || x26681=='\n') break;
      if (x26682>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x26682); break;}
      ((char*)x26680)[x26682] = x26681;
      x26682 += 1;
    }
    ((char*)x26680)[x26682] = '\0';
    char* x26685 = (char*)malloc(16 * sizeof(char));
    int x26687 = 0;
    char x26686 = ' ';
    while (1) {
      fscanf(x26649,"%c",&x26686);
      if (x26686=='|' || x26686=='\n') break;
      if (x26687>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x26687); break;}
      ((char*)x26685)[x26687] = x26686;
      x26687 += 1;
    }
    ((char*)x26685)[x26687] = '\0';
    int x26690 = 0;
    if (fscanf(x26649,"%d|",&x26690) == EOF) break;
    char* x26691 = (char*)malloc(80 * sizeof(char));
    int x26693 = 0;
    char x26692 = ' ';
    while (1) {
      fscanf(x26649,"%c",&x26692);
      if (x26692=='|' || x26692=='\n') break;
      if (x26693>=79) { printf("ERROR: scanner.nextString reading past end of buffer %d",x26693); break;}
      ((char*)x26691)[x26693] = x26692;
      x26693 += 1;
    }
    ((char*)x26691)[x26693] = '\0';
    char* x26695 = x26691; // unsafe immutable;
    int x26696 = x26651;
    int x26697 = x26650;
    bool x26698 = x26696 == x26697;
    if (x26698) {
      int x26699 = x26697 * 4;
      x26650 = x26699;
      printf("buffer.resize %d\n",x26699);
      int* x26702 = x26653;
      int* x26703 = (int*)realloc(x26702,x26699 * sizeof(int));
      x26653 = x26703;
      int* x26705 = x26655;
      int* x26706 = (int*)realloc(x26705,x26699 * sizeof(int));
      x26655 = x26706;
      char** x26726 = x26669;
      char** x26727 = (char**)realloc(x26726,x26699 * sizeof(char*));
      x26669 = x26727;
    } else {
    }
    int* x26731 = x26653;
    x26731[x26696] = x26672;
    int* x26733 = x26655;
    x26733[x26696] = x26673;
    char** x26747 = x26669;
    x26747[x26696] = x26695;
    x26651 = x26651 + 1;
  }
  struct Anon811555534* x25991 = (struct Anon811555534*)malloc(sizeof(struct Anon811555534));
  x25991->O_ORDERKEY = 0;
  x25991->O_CUSTKEY = 0;
  x25991->O_ORDERSTATUS = NULL;
  x25991->O_TOTALPRICE = 0.0;
  x25991->O_ORDERDATE = 0;
  x25991->O_ORDERPRIORITY = NULL;
  x25991->O_CLERK = NULL;
  x25991->O_SHIPPRIORITY = 0;
  x25991->O_COMMENT = NULL;
  int x26285 = x25991->O_ORDERKEY;;
  bool x26753 = x26285 == 0.0;
  GTree* x26762 = g_tree_new((GCompareFunc)x27288);;
  bool x26763 = true == false;
  int x25959;
  for(x25959=0; x25959 < 1; x25959++) {
    bool x26764 = false;
    int x26765 = 0;
    bool x26766 = false;
    int x26767 = 0;
    int* x26770 = (int*)malloc(1073741824 * sizeof(int));
    int* x26771 = x26770;
    int* x26772 = (int*)malloc(1073741824 * sizeof(int));
    int* x26773 = x26772;
    int x26788 = 0;
    int* x26789 = (int*)malloc(1048576 * sizeof(int));
    int* x26790 = (int*)malloc(1073741824 * sizeof(int));
    int x25987;
    for(x25987=0; x25987 < 1048576; x25987++) {
      x26789[x25987] = -1;
    }
    int x26796 = 1048576;
    int x26797 = 0;
    int* x26798 = (int*)malloc(1048576 * sizeof(int));
    int* x26799 = x26798;
    double* x26800 = (double*)malloc(1048576 * sizeof(double));
    double* x26801 = x26800;
    int x26802 = 4194304;
    int x26803 = 0;
    int* x26804 = (int*)malloc(4194304 * sizeof(int));
    int* x26805 = x26804;
    int x26004;
    for(x26004=0; x26004 < 4194304; x26004++) {
      int* x26806 = x26805;
      x26806[x26004] = -1;
    }
    int x26813 = 1048576;
    int x26814 = 0;
    double* x26815 = (double*)malloc(1048576 * sizeof(double));
    double* x26816 = x26815;
    double* x26817 = (double*)malloc(1048576 * sizeof(double));
    double* x26818 = x26817;
    int x26819 = 4194304;
    int x26820 = 0;
    int* x26821 = (int*)malloc(4194304 * sizeof(int));
    int* x26822 = x26821;
    int x26022;
    for(x26022=0; x26022 < 4194304; x26022++) {
      int* x26823 = x26822;
      x26823[x26022] = -1;
    }
    int x26831 = 0;
    struct timeval x26531, x26532, x27281;
    gettimeofday(&x26531, NULL);
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x26833 = x26766;
      bool x26834 = !x26833;
      bool x26839 = x26834;
      if (x26834) {
        int x26835 = x26767;
        int x26836 = x26651;
        bool x26837 = x26835 < x26836;
        x26839 = x26837;
      }
      bool x26840 = x26839;
      if (!x26840) break;
      int x26843 = x26767;
      int* x26844 = x26653;
      int x26845 = x26844[x26843];
      int* x26846 = x26655;
      int x26847 = x26846[x26843];
      char** x26860 = x26669;
      char* x26861 = x26860[x26843];
      x26767 = x26767 + 1;
      int x26863 = strstr(&x26861[0],"unusual") - x26861;
      if (x26863 < 0) x26863 = -1;
      bool x26864 = x26863 != -1;
      bool x26867 = x26864;
      if (x26864) {
        int x26865 = strstr(&x26861[x26863],"packages") - x26861;
        if (x26865 < 0) x26865 = -1;
        bool x26866 = x26865 != -1;
        x26867 = x26866;
      }
      bool x26868 = x26867;
      if (x26868) {
      } else {
        int x26869 = x26788;
        int* x26870 = x26771;
        x26870[x26869] = x26845;
        int* x26872 = x26773;
        x26872[x26869] = x26847;
        x26788 = x26788 + 1;
        int x26889 = x26847 & 1048575;
        int x26890 = x26789[x26889];
        x26789[x26889] = x26869;
        x26790[x26869] = x26890;
      }
    }
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x26899 = x26764;
      bool x26900 = !x26899;
      bool x26905 = x26900;
      if (x26900) {
        int x26901 = x26765;
        int x26902 = x26550;
        bool x26903 = x26901 < x26902;
        x26905 = x26903;
      }
      bool x26906 = x26905;
      if (!x26906) break;
      int x26909 = x26765;
      int* x26910 = x26552;
      int x26911 = x26910[x26909];
      x26765 = x26765 + 1;
      bool x26927 = false;
      int x26928 = x26911 & 1048575;
      int x26929 = x26789[x26928];
      int x26930 = x26929;
      int x26931 = x26911 * 2;
      int x26932 = x26931 * 3;
      for (;;) {
        int x26933 = x26930;
        bool x26934 = x26933 != -1;
        if (!x26934) break;
        int x26936 = x26930;
        int* x26937 = x26771;
        int x26938 = x26937[x26936];
        int* x26939 = x26773;
        int x26940 = x26939[x26936];
        int x26955 = x26790[x26936];
        x26930 = x26955;
        bool x26957 = x26911 == x26940;
        if (x26957) {
          x26927 = true;
          int x26960 = x26802;
          int x26961 = x26960 - 1;
          int x26962 = x26932 & x26961;
          int x26963 = x26962;
          int* x26964 = x26805;
          int x26965 = x26964[x26962];
          int x26966 = x26965;
          int x26967 = x26962 + 1;
          int x26968 = x26964[x26967];
          int x26969 = x26968;
          for (;;) {
            int x26970 = x26966;
            bool x26971 = x26970 != -1;
            bool x26987 = x26971;
            if (x26971) {
              int x26972 = x26969;
              bool x26973 = x26972 != x26932;
              bool x26983 = x26973;
              if (x26973 == false) {
                int x26974 = x26966;
                int* x26975 = x26799;
                int x26976 = x26975[x26974];
                bool x26979 = x26976 == x26911;
                bool x26980 = !x26979;
                x26983 = x26980;
              }
              bool x26984 = x26983;
              x26987 = x26984;
            }
            bool x26988 = x26987;
            if (!x26988) break;
            int x26991 = x26963;
            int x26992 = x26991 + 2;
            int x26993 = x26992 & x26961;
            x26963 = x26993;
            int* x26995 = x26805;
            int x26996 = x26995[x26993];
            x26966 = x26996;
            int x26998 = x26993 + 1;
            int x26999 = x26995[x26998];
            x26969 = x26999;
          }
          int x27004 = x26966;
          bool x27005 = x27004 == -1;
          int x27040;
          if (x27005) {
            int x27006 = x26803;
            int x27007 = x26963;
            x26964[x27007] = x27006;
            int x27009 = x27007 + 1;
            x26964[x27009] = x26932;
            x26803 = x26803 + 1;
            int x27012 = x26797;
            int x27013 = x26796;
            bool x27014 = x27012 == x27013;
            if (x27014) {
              int x27015 = x27013 * 4;
              x26796 = x27015;
              printf("buffer.resize %d\n",x27015);
              int* x27018 = x26799;
              int* x27019 = (int*)realloc(x27018,x27015 * sizeof(int));
              x26799 = x27019;
              printf("buffer.resize %d\n",x27015);
              double* x27022 = x26801;
              double* x27023 = (double*)realloc(x27022,x27015 * sizeof(double));
              x26801 = x27023;
            } else {
            }
            int* x27027 = x26799;
            x27027[x27012] = x26911;
            double* x27029 = x26801;
            x27029[x27012] = 0.0;
            x26797 = x26797 + 1;
            int x27032 = x26803;
            int x27033 = x27032 * 4;
            bool x27034 = x27033 > x26960;
            if (x27034) {
              printf("%s\n","ERROR: hash.resize not implemented");
            } else {
            }
            x27040 = x27006;
          } else {
            x27040 = x27004;
          }
          int* x27041 = x26799;
          int x27042 = x27041[x27040];
          double* x27043 = x26801;
          double x27044 = x27043[x27040];
          x27041[x27040] = x27042;
          bool x27046 = x26938 == 0.0;
          double x27048;
          if (x27046) {
            x27048 = x27044;
          } else {
            double x27047 = x27044 + 1.0;
            x27048 = x27047;
          }
          x27043[x27040] = x27048;
        } else {
        }
      }
      bool x27056 = x26927;
      if (x27056) {
      } else {
        int x27058 = x26802;
        int x27059 = x27058 - 1;
        int x27060 = x26932 & x27059;
        int x27061 = x27060;
        int* x27062 = x26805;
        int x27063 = x27062[x27060];
        int x27064 = x27063;
        int x27065 = x27060 + 1;
        int x27066 = x27062[x27065];
        int x27067 = x27066;
        for (;;) {
          int x27068 = x27064;
          bool x27069 = x27068 != -1;
          bool x27085 = x27069;
          if (x27069) {
            int x27070 = x27067;
            bool x27071 = x27070 != x26932;
            bool x27081 = x27071;
            if (x27071 == false) {
              int x27072 = x27064;
              int* x27073 = x26799;
              int x27074 = x27073[x27072];
              bool x27077 = x27074 == x26911;
              bool x27078 = !x27077;
              x27081 = x27078;
            }
            bool x27082 = x27081;
            x27085 = x27082;
          }
          bool x27086 = x27085;
          if (!x27086) break;
          int x27089 = x27061;
          int x27090 = x27089 + 2;
          int x27091 = x27090 & x27059;
          x27061 = x27091;
          int* x27093 = x26805;
          int x27094 = x27093[x27091];
          x27064 = x27094;
          int x27096 = x27091 + 1;
          int x27097 = x27093[x27096];
          x27067 = x27097;
        }
        int x27102 = x27064;
        bool x27103 = x27102 == -1;
        int x27138;
        if (x27103) {
          int x27104 = x26803;
          int x27105 = x27061;
          x27062[x27105] = x27104;
          int x27107 = x27105 + 1;
          x27062[x27107] = x26932;
          x26803 = x26803 + 1;
          int x27110 = x26797;
          int x27111 = x26796;
          bool x27112 = x27110 == x27111;
          if (x27112) {
            int x27113 = x27111 * 4;
            x26796 = x27113;
            printf("buffer.resize %d\n",x27113);
            int* x27116 = x26799;
            int* x27117 = (int*)realloc(x27116,x27113 * sizeof(int));
            x26799 = x27117;
            printf("buffer.resize %d\n",x27113);
            double* x27120 = x26801;
            double* x27121 = (double*)realloc(x27120,x27113 * sizeof(double));
            x26801 = x27121;
          } else {
          }
          int* x27125 = x26799;
          x27125[x27110] = x26911;
          double* x27127 = x26801;
          x27127[x27110] = 0.0;
          x26797 = x26797 + 1;
          int x27130 = x26803;
          int x27131 = x27130 * 4;
          bool x27132 = x27131 > x27058;
          if (x27132) {
            printf("%s\n","ERROR: hash.resize not implemented");
          } else {
          }
          x27138 = x27104;
        } else {
          x27138 = x27102;
        }
        int* x27139 = x26799;
        int x27140 = x27139[x27138];
        double* x27141 = x26801;
        double x27142 = x27141[x27138];
        x27139[x27138] = x27140;
        double x27145;
        if (x26753) {
          x27145 = x27142;
        } else {
          double x27144 = x27142 + 1.0;
          x27145 = x27144;
        }
        x27141[x27138] = x27145;
      }
    }
    int x27153 = x26797;
    int x26397;
    for(x26397=0; x26397 < x27153; x26397++) {
      double* x27156 = x26801;
      double x27157 = x27156[x26397];
      int x27159 = x26819;
      int x27160 = x27159 - 1;
      int x27161 = 4662 & x27160;
      int x27162 = x27161;
      int* x27163 = x26822;
      int x27164 = x27163[x27161];
      int x27165 = x27164;
      int x27166 = x27161 + 1;
      int x27167 = x27163[x27166];
      int x27168 = x27167;
      for (;;) {
        int x27169 = x27165;
        bool x27170 = x27169 != -1;
        bool x27186 = x27170;
        if (x27170) {
          int x27171 = x27168;
          bool x27172 = x27171 != 4662;
          bool x27182 = x27172;
          if (x27172 == false) {
            int x27173 = x27165;
            double* x27174 = x26816;
            double x27175 = x27174[x27173];
            bool x27178 = x27175 == x27157;
            bool x27179 = !x27178;
            x27182 = x27179;
          }
          bool x27183 = x27182;
          x27186 = x27183;
        }
        bool x27187 = x27186;
        if (!x27187) break;
        int x27190 = x27162;
        int x27191 = x27190 + 2;
        int x27192 = x27191 & x27160;
        x27162 = x27192;
        int* x27194 = x26822;
        int x27195 = x27194[x27192];
        x27165 = x27195;
        int x27197 = x27192 + 1;
        int x27198 = x27194[x27197];
        x27168 = x27198;
      }
      int x27203 = x27165;
      bool x27204 = x27203 == -1;
      int x27239;
      if (x27204) {
        int x27205 = x26820;
        int x27206 = x27162;
        x27163[x27206] = x27205;
        int x27208 = x27206 + 1;
        x27163[x27208] = 4662;
        x26820 = x26820 + 1;
        int x27211 = x26814;
        int x27212 = x26813;
        bool x27213 = x27211 == x27212;
        if (x27213) {
          int x27214 = x27212 * 4;
          x26813 = x27214;
          printf("buffer.resize %d\n",x27214);
          double* x27217 = x26816;
          double* x27218 = (double*)realloc(x27217,x27214 * sizeof(double));
          x26816 = x27218;
          printf("buffer.resize %d\n",x27214);
          double* x27221 = x26818;
          double* x27222 = (double*)realloc(x27221,x27214 * sizeof(double));
          x26818 = x27222;
        } else {
        }
        double* x27226 = x26816;
        x27226[x27211] = x27157;
        double* x27228 = x26818;
        x27228[x27211] = 0.0;
        x26814 = x26814 + 1;
        int x27231 = x26820;
        int x27232 = x27231 * 4;
        bool x27233 = x27232 > x27159;
        if (x27233) {
          printf("%s\n","ERROR: hash.resize not implemented");
        } else {
        }
        x27239 = x27205;
      } else {
        x27239 = x27203;
      }
      double* x27240 = x26816;
      double x27241 = x27240[x27239];
      double* x27242 = x26818;
      double x27243 = x27242[x27239];
      x27240[x27239] = x27241;
      double x27245 = x27243 + 1.0;
      x27242[x27239] = x27245;
    }
    int x27250 = x26814;
    int x26502;
    for(x26502=0; x26502 < x27250; x26502++) {
      double* x27251 = x26816;
      double x27252 = x27251[x26502];
      double* x27253 = x26818;
      double x27254 = x27253[x26502];
      struct Anon2052879266* x27255 = (struct Anon2052879266*)malloc(sizeof(struct Anon2052879266));
      x27255->_0 = x27254;
      struct Anon955262776* x27256 = (struct Anon955262776*)malloc(sizeof(struct Anon955262776));
      x27256->key = x27252;
      x27256->aggs = x27255;
      g_tree_insert(x26762,x27256,x27256);; // x27257
    }
    for (;;) {
      int x27260 = g_tree_nnodes(x26762);
      bool x27261 = x27260 != 0;
      if (!x27261) break;
      struct Anon955262776* x27263 = NULL;
      g_tree_foreach(x26762, (GTraverseFunc)x27294, &x27263);
      g_tree_remove(x26762,x27263);
      if (x26763) {
      } else {
        double x27267 = x27263->key;;
        struct Anon2052879266* x27268 = x27263->aggs;;
        double x27269 = x27268->_0;;
        printf("%.0f|%.0f\n",x27267,x27269);
        x26831 = x26831 + 1;
      }
    }
    int x27277 = x26831;
    printf("(%d rows)\n",x27277);
    gettimeofday(&x26532, NULL);
    timeval_subtract(&x27281, &x26532, &x26531);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x27281.tv_sec * 1000) + (x27281.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
