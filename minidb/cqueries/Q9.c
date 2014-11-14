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
struct Anon713865179Anon72918141Anon1268892766Anon168903330Anon811555534;
struct Anon0;
struct Anon1812879556;
struct Anon102935935Anon168903330Anon811555534;
struct Anon811555534;
struct Anon15765642;
struct Anon102935935;
struct Anon713865179Anon72918141Anon1268892766Anon168903330;
struct Anon1268892766;
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
struct Anon1406772883Anon1268892766;
struct Anon920667905Anon713865179Anon72918141Anon1268892766Anon168903330Anon811555534;
struct Anon1406772883Anon102935935Anon168903330Anon811555534Anon920667905;
struct Anon102935935Anon168903330Anon811555534Anon920667905;
struct Anon1732223439;
struct Anon722854457;
struct Anon625264174;
struct Anon949908027;
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
struct Anon1599206474* left;
struct Anon811555534* right;
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

struct Anon704530870 {
struct Anon625264174* key;
struct Anon567626277* aggs;
};

/************************ FUNCTIONS **************************/
int x20301(struct Anon344387643* x17821, struct Anon344387643* x17820);
int x20307(struct Anon344387643* x20302, struct Anon344387643* x20303, struct Anon344387643** x20304);
int x20301(struct Anon344387643* x17821, struct Anon344387643* x17820) {
  struct Anon1548200872* x17822 = x17820->key;;
  char* x17824 = x17822->NATION;;
  struct Anon1548200872* x17823 = x17821->key;;
  char* x17825 = x17823->NATION;;
  int x17826 = strcmp(x17824,x17825);
  bool x19271 = x17826 == 0;
  int x19276;
  if (x19271) {
    int x17828 = x17822->O_YEAR;;
    int x17829 = x17823->O_YEAR;;
    bool x17830 = x17828 < x17829;
    int x19274;
    if (x17830) {
      x19274 = 1;
    } else {
      bool x17831 = x17828 > x17829;
      int x19272;
      if (x17831) {
        x19272 = -1;
      } else {
        x19272 = 0;
      }
      x19274 = x19272;
    }
    x19276 = x19274;
  } else {
    x19276 = x17826;
  }
  return x19276;
}
int x20307(struct Anon344387643* x20302, struct Anon344387643* x20303, struct Anon344387643** x20304) {
  *x20304 = x20303;
  return 0;
}

/************************ MAIN BODY **************************/
int main(int x17007, char** x17008) {
  FILE* x18680 = fopen("../databases/sf2/part.tbl", "r");
  int x18681 = 1048576;
  int x18682 = 0;
  int* x18683 = (int*)malloc(1048576 * sizeof(int));
  int* x18684 = x18683;
  char** x18685 = (char**)malloc(1048576 * sizeof(char*));
  char** x18686 = x18685;
  for (;;) {
    bool x18702 = !feof(x18680);
    if (!x18702) break;
    int x18704 = 0;
    if (fscanf(x18680,"%d|",&x18704) == EOF) break;
    char* x18705 = (char*)malloc(56 * sizeof(char));
    int x18707 = 0;
    char x18706 = ' ';
    while (1) {
      fscanf(x18680,"%c",&x18706);
      if (x18706=='|' || x18706=='\n') break;
      if (x18707>=55) { printf("ERROR: scanner.nextString reading past end of buffer %d",x18707); break;}
      ((char*)x18705)[x18707] = x18706;
      x18707 += 1;
    }
    ((char*)x18705)[x18707] = '\0';
    char* x18709 = x18705; // unsafe immutable;
    char* x18710 = (char*)malloc(26 * sizeof(char));
    int x18712 = 0;
    char x18711 = ' ';
    while (1) {
      fscanf(x18680,"%c",&x18711);
      if (x18711=='|' || x18711=='\n') break;
      if (x18712>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x18712); break;}
      ((char*)x18710)[x18712] = x18711;
      x18712 += 1;
    }
    ((char*)x18710)[x18712] = '\0';
    char* x18715 = (char*)malloc(11 * sizeof(char));
    int x18717 = 0;
    char x18716 = ' ';
    while (1) {
      fscanf(x18680,"%c",&x18716);
      if (x18716=='|' || x18716=='\n') break;
      if (x18717>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x18717); break;}
      ((char*)x18715)[x18717] = x18716;
      x18717 += 1;
    }
    ((char*)x18715)[x18717] = '\0';
    char* x18720 = (char*)malloc(26 * sizeof(char));
    int x18722 = 0;
    char x18721 = ' ';
    while (1) {
      fscanf(x18680,"%c",&x18721);
      if (x18721=='|' || x18721=='\n') break;
      if (x18722>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x18722); break;}
      ((char*)x18720)[x18722] = x18721;
      x18722 += 1;
    }
    ((char*)x18720)[x18722] = '\0';
    int x18725 = 0;
    if (fscanf(x18680,"%d|",&x18725) == EOF) break;
    char* x18726 = (char*)malloc(11 * sizeof(char));
    int x18728 = 0;
    char x18727 = ' ';
    while (1) {
      fscanf(x18680,"%c",&x18727);
      if (x18727=='|' || x18727=='\n') break;
      if (x18728>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x18728); break;}
      ((char*)x18726)[x18728] = x18727;
      x18728 += 1;
    }
    ((char*)x18726)[x18728] = '\0';
    double x18731 = 0.0;
    if (fscanf(x18680,"%lf|",&x18731) == EOF) break;
    char* x18732 = (char*)malloc(24 * sizeof(char));
    int x18734 = 0;
    char x18733 = ' ';
    while (1) {
      fscanf(x18680,"%c",&x18733);
      if (x18733=='|' || x18733=='\n') break;
      if (x18734>=23) { printf("ERROR: scanner.nextString reading past end of buffer %d",x18734); break;}
      ((char*)x18732)[x18734] = x18733;
      x18734 += 1;
    }
    ((char*)x18732)[x18734] = '\0';
    int x18737 = x18682;
    int x18738 = x18681;
    bool x18739 = x18737 == x18738;
    if (x18739) {
      int x18740 = x18738 * 4;
      x18681 = x18740;
      printf("buffer.resize %d\n",x18740);
      int* x18743 = x18684;
      int* x18744 = (int*)realloc(x18743,x18740 * sizeof(int));
      x18684 = x18744;
      char** x18746 = x18686;
      char** x18747 = (char**)realloc(x18746,x18740 * sizeof(char*));
      x18686 = x18747;
    } else {
    }
    int* x18772 = x18684;
    x18772[x18737] = x18704;
    char** x18774 = x18686;
    x18774[x18737] = x18709;
    x18682 = x18682 + 1;
  }
  FILE* x18794 = fopen("../databases/sf2/nation.tbl", "r");
  int x18795 = 1048576;
  int x18796 = 0;
  int* x18797 = (int*)malloc(1048576 * sizeof(int));
  int* x18798 = x18797;
  char** x18799 = (char**)malloc(1048576 * sizeof(char*));
  char** x18800 = x18799;
  for (;;) {
    bool x18805 = !feof(x18794);
    if (!x18805) break;
    int x18807 = 0;
    if (fscanf(x18794,"%d|",&x18807) == EOF) break;
    char* x18808 = (char*)malloc(26 * sizeof(char));
    int x18810 = 0;
    char x18809 = ' ';
    while (1) {
      fscanf(x18794,"%c",&x18809);
      if (x18809=='|' || x18809=='\n') break;
      if (x18810>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x18810); break;}
      ((char*)x18808)[x18810] = x18809;
      x18810 += 1;
    }
    ((char*)x18808)[x18810] = '\0';
    char* x18812 = x18808; // unsafe immutable;
    int x18813 = 0;
    if (fscanf(x18794,"%d|",&x18813) == EOF) break;
    char* x18814 = (char*)malloc(153 * sizeof(char));
    int x18816 = 0;
    char x18815 = ' ';
    while (1) {
      fscanf(x18794,"%c",&x18815);
      if (x18815=='|' || x18815=='\n') break;
      if (x18816>=152) { printf("ERROR: scanner.nextString reading past end of buffer %d",x18816); break;}
      ((char*)x18814)[x18816] = x18815;
      x18816 += 1;
    }
    ((char*)x18814)[x18816] = '\0';
    int x18819 = x18796;
    int x18820 = x18795;
    bool x18821 = x18819 == x18820;
    if (x18821) {
      int x18822 = x18820 * 4;
      x18795 = x18822;
      printf("buffer.resize %d\n",x18822);
      int* x18825 = x18798;
      int* x18826 = (int*)realloc(x18825,x18822 * sizeof(int));
      x18798 = x18826;
      char** x18828 = x18800;
      char** x18829 = (char**)realloc(x18828,x18822 * sizeof(char*));
      x18800 = x18829;
    } else {
    }
    int* x18839 = x18798;
    x18839[x18819] = x18807;
    char** x18841 = x18800;
    x18841[x18819] = x18812;
    x18796 = x18796 + 1;
  }
  FILE* x18851 = fopen("../databases/sf2/orders.tbl", "r");
  int x18852 = 1048576;
  int x18853 = 0;
  int* x18854 = (int*)malloc(1048576 * sizeof(int));
  int* x18855 = x18854;
  long* x18862 = (long*)malloc(1048576 * sizeof(long));
  long* x18863 = x18862;
  for (;;) {
    bool x18872 = !feof(x18851);
    if (!x18872) break;
    int x18874 = 0;
    if (fscanf(x18851,"%d|",&x18874) == EOF) break;
    int x18875 = 0;
    if (fscanf(x18851,"%d|",&x18875) == EOF) break;
    char x18876 = ' ';
    if (fscanf(x18851,"%c|",&x18876) == EOF) break;
    double x18877 = 0.0;
    if (fscanf(x18851,"%lf|",&x18877) == EOF) break;
    int x18878 = 0;
    int x18879 = 0;
    int x18880 = 0;
    fscanf(x18851, "%d-%d-%d|",&x18878, &x18879, &x18880);
    long x18881 = (x18878 * 10000) + (x18879 * 100) + x18880;
    char* x18882 = (char*)malloc(16 * sizeof(char));
    int x18884 = 0;
    char x18883 = ' ';
    while (1) {
      fscanf(x18851,"%c",&x18883);
      if (x18883=='|' || x18883=='\n') break;
      if (x18884>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x18884); break;}
      ((char*)x18882)[x18884] = x18883;
      x18884 += 1;
    }
    ((char*)x18882)[x18884] = '\0';
    char* x18887 = (char*)malloc(16 * sizeof(char));
    int x18889 = 0;
    char x18888 = ' ';
    while (1) {
      fscanf(x18851,"%c",&x18888);
      if (x18888=='|' || x18888=='\n') break;
      if (x18889>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x18889); break;}
      ((char*)x18887)[x18889] = x18888;
      x18889 += 1;
    }
    ((char*)x18887)[x18889] = '\0';
    int x18892 = 0;
    if (fscanf(x18851,"%d|",&x18892) == EOF) break;
    char* x18893 = (char*)malloc(80 * sizeof(char));
    int x18895 = 0;
    char x18894 = ' ';
    while (1) {
      fscanf(x18851,"%c",&x18894);
      if (x18894=='|' || x18894=='\n') break;
      if (x18895>=79) { printf("ERROR: scanner.nextString reading past end of buffer %d",x18895); break;}
      ((char*)x18893)[x18895] = x18894;
      x18895 += 1;
    }
    ((char*)x18893)[x18895] = '\0';
    int x18898 = x18853;
    int x18899 = x18852;
    bool x18900 = x18898 == x18899;
    if (x18900) {
      int x18901 = x18899 * 4;
      x18852 = x18901;
      printf("buffer.resize %d\n",x18901);
      int* x18904 = x18855;
      int* x18905 = (int*)realloc(x18904,x18901 * sizeof(int));
      x18855 = x18905;
      long* x18916 = x18863;
      long* x18917 = (long*)realloc(x18916,x18901 * sizeof(long));
      x18863 = x18917;
    } else {
    }
    int* x18933 = x18855;
    x18933[x18898] = x18874;
    long* x18941 = x18863;
    x18941[x18898] = x18881;
    x18853 = x18853 + 1;
  }
  FILE* x18955 = fopen("../databases/sf2/partsupp.tbl", "r");
  int x18956 = 1048576;
  int x18957 = 0;
  int* x18958 = (int*)malloc(1048576 * sizeof(int));
  int* x18959 = x18958;
  int* x18960 = (int*)malloc(1048576 * sizeof(int));
  int* x18961 = x18960;
  double* x18964 = (double*)malloc(1048576 * sizeof(double));
  double* x18965 = x18964;
  for (;;) {
    bool x18968 = !feof(x18955);
    if (!x18968) break;
    int x18970 = 0;
    if (fscanf(x18955,"%d|",&x18970) == EOF) break;
    int x18971 = 0;
    if (fscanf(x18955,"%d|",&x18971) == EOF) break;
    int x18972 = 0;
    if (fscanf(x18955,"%d|",&x18972) == EOF) break;
    double x18973 = 0.0;
    if (fscanf(x18955,"%lf|",&x18973) == EOF) break;
    char* x18974 = (char*)malloc(200 * sizeof(char));
    int x18976 = 0;
    char x18975 = ' ';
    while (1) {
      fscanf(x18955,"%c",&x18975);
      if (x18975=='|' || x18975=='\n') break;
      if (x18976>=199) { printf("ERROR: scanner.nextString reading past end of buffer %d",x18976); break;}
      ((char*)x18974)[x18976] = x18975;
      x18976 += 1;
    }
    ((char*)x18974)[x18976] = '\0';
    int x18979 = x18957;
    int x18980 = x18956;
    bool x18981 = x18979 == x18980;
    if (x18981) {
      int x18982 = x18980 * 4;
      x18956 = x18982;
      printf("buffer.resize %d\n",x18982);
      int* x18985 = x18959;
      int* x18986 = (int*)realloc(x18985,x18982 * sizeof(int));
      x18959 = x18986;
      int* x18988 = x18961;
      int* x18989 = (int*)realloc(x18988,x18982 * sizeof(int));
      x18961 = x18989;
      double* x18994 = x18965;
      double* x18995 = (double*)realloc(x18994,x18982 * sizeof(double));
      x18965 = x18995;
    } else {
    }
    int* x19002 = x18959;
    x19002[x18979] = x18970;
    int* x19004 = x18961;
    x19004[x18979] = x18971;
    double* x19008 = x18965;
    x19008[x18979] = x18973;
    x18957 = x18957 + 1;
  }
  FILE* x19016 = fopen("../databases/sf2/supplier.tbl", "r");
  int x19017 = 1048576;
  int x19018 = 0;
  int* x19019 = (int*)malloc(1048576 * sizeof(int));
  int* x19020 = x19019;
  int* x19025 = (int*)malloc(1048576 * sizeof(int));
  int* x19026 = x19025;
  for (;;) {
    bool x19033 = !feof(x19016);
    if (!x19033) break;
    int x19035 = 0;
    if (fscanf(x19016,"%d|",&x19035) == EOF) break;
    char* x19036 = (char*)malloc(26 * sizeof(char));
    int x19038 = 0;
    char x19037 = ' ';
    while (1) {
      fscanf(x19016,"%c",&x19037);
      if (x19037=='|' || x19037=='\n') break;
      if (x19038>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x19038); break;}
      ((char*)x19036)[x19038] = x19037;
      x19038 += 1;
    }
    ((char*)x19036)[x19038] = '\0';
    char* x19041 = (char*)malloc(41 * sizeof(char));
    int x19043 = 0;
    char x19042 = ' ';
    while (1) {
      fscanf(x19016,"%c",&x19042);
      if (x19042=='|' || x19042=='\n') break;
      if (x19043>=40) { printf("ERROR: scanner.nextString reading past end of buffer %d",x19043); break;}
      ((char*)x19041)[x19043] = x19042;
      x19043 += 1;
    }
    ((char*)x19041)[x19043] = '\0';
    int x19046 = 0;
    if (fscanf(x19016,"%d|",&x19046) == EOF) break;
    char* x19047 = (char*)malloc(16 * sizeof(char));
    int x19049 = 0;
    char x19048 = ' ';
    while (1) {
      fscanf(x19016,"%c",&x19048);
      if (x19048=='|' || x19048=='\n') break;
      if (x19049>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x19049); break;}
      ((char*)x19047)[x19049] = x19048;
      x19049 += 1;
    }
    ((char*)x19047)[x19049] = '\0';
    double x19052 = 0.0;
    if (fscanf(x19016,"%lf|",&x19052) == EOF) break;
    char* x19053 = (char*)malloc(102 * sizeof(char));
    int x19055 = 0;
    char x19054 = ' ';
    while (1) {
      fscanf(x19016,"%c",&x19054);
      if (x19054=='|' || x19054=='\n') break;
      if (x19055>=101) { printf("ERROR: scanner.nextString reading past end of buffer %d",x19055); break;}
      ((char*)x19053)[x19055] = x19054;
      x19055 += 1;
    }
    ((char*)x19053)[x19055] = '\0';
    int x19058 = x19018;
    int x19059 = x19017;
    bool x19060 = x19058 == x19059;
    if (x19060) {
      int x19061 = x19059 * 4;
      x19017 = x19061;
      printf("buffer.resize %d\n",x19061);
      int* x19064 = x19020;
      int* x19065 = (int*)realloc(x19064,x19061 * sizeof(int));
      x19020 = x19065;
      int* x19073 = x19026;
      int* x19074 = (int*)realloc(x19073,x19061 * sizeof(int));
      x19026 = x19074;
    } else {
    }
    int* x19087 = x19020;
    x19087[x19058] = x19035;
    int* x19093 = x19026;
    x19093[x19058] = x19046;
    x19018 = x19018 + 1;
  }
  FILE* x19105 = fopen("../databases/sf2/lineitem.tbl", "r");
  int x19106 = 1048576;
  int x19107 = 0;
  int* x19108 = (int*)malloc(1048576 * sizeof(int));
  int* x19109 = x19108;
  int* x19110 = (int*)malloc(1048576 * sizeof(int));
  int* x19111 = x19110;
  int* x19112 = (int*)malloc(1048576 * sizeof(int));
  int* x19113 = x19112;
  double* x19116 = (double*)malloc(1048576 * sizeof(double));
  double* x19117 = x19116;
  double* x19118 = (double*)malloc(1048576 * sizeof(double));
  double* x19119 = x19118;
  double* x19120 = (double*)malloc(1048576 * sizeof(double));
  double* x19121 = x19120;
  for (;;) {
    bool x19140 = !feof(x19105);
    if (!x19140) break;
    int x19142 = 0;
    if (fscanf(x19105,"%d|",&x19142) == EOF) break;
    int x19143 = 0;
    if (fscanf(x19105,"%d|",&x19143) == EOF) break;
    int x19144 = 0;
    if (fscanf(x19105,"%d|",&x19144) == EOF) break;
    int x19145 = 0;
    if (fscanf(x19105,"%d|",&x19145) == EOF) break;
    double x19146 = 0.0;
    if (fscanf(x19105,"%lf|",&x19146) == EOF) break;
    double x19147 = 0.0;
    if (fscanf(x19105,"%lf|",&x19147) == EOF) break;
    double x19148 = 0.0;
    if (fscanf(x19105,"%lf|",&x19148) == EOF) break;
    double x19149 = 0.0;
    if (fscanf(x19105,"%lf|",&x19149) == EOF) break;
    char x19150 = ' ';
    if (fscanf(x19105,"%c|",&x19150) == EOF) break;
    char x19151 = ' ';
    if (fscanf(x19105,"%c|",&x19151) == EOF) break;
    int x19152 = 0;
    int x19153 = 0;
    int x19154 = 0;
    fscanf(x19105, "%d-%d-%d|",&x19152, &x19153, &x19154);
    long x19155 = (x19152 * 10000) + (x19153 * 100) + x19154;
    int x19156 = 0;
    int x19157 = 0;
    int x19158 = 0;
    fscanf(x19105, "%d-%d-%d|",&x19156, &x19157, &x19158);
    long x19159 = (x19156 * 10000) + (x19157 * 100) + x19158;
    int x19160 = 0;
    int x19161 = 0;
    int x19162 = 0;
    fscanf(x19105, "%d-%d-%d|",&x19160, &x19161, &x19162);
    long x19163 = (x19160 * 10000) + (x19161 * 100) + x19162;
    char* x19164 = (char*)malloc(26 * sizeof(char));
    int x19166 = 0;
    char x19165 = ' ';
    while (1) {
      fscanf(x19105,"%c",&x19165);
      if (x19165=='|' || x19165=='\n') break;
      if (x19166>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x19166); break;}
      ((char*)x19164)[x19166] = x19165;
      x19166 += 1;
    }
    ((char*)x19164)[x19166] = '\0';
    char* x19169 = (char*)malloc(11 * sizeof(char));
    int x19171 = 0;
    char x19170 = ' ';
    while (1) {
      fscanf(x19105,"%c",&x19170);
      if (x19170=='|' || x19170=='\n') break;
      if (x19171>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x19171); break;}
      ((char*)x19169)[x19171] = x19170;
      x19171 += 1;
    }
    ((char*)x19169)[x19171] = '\0';
    char* x19174 = (char*)malloc(45 * sizeof(char));
    int x19176 = 0;
    char x19175 = ' ';
    while (1) {
      fscanf(x19105,"%c",&x19175);
      if (x19175=='|' || x19175=='\n') break;
      if (x19176>=44) { printf("ERROR: scanner.nextString reading past end of buffer %d",x19176); break;}
      ((char*)x19174)[x19176] = x19175;
      x19176 += 1;
    }
    ((char*)x19174)[x19176] = '\0';
    int x19179 = x19107;
    int x19180 = x19106;
    bool x19181 = x19179 == x19180;
    if (x19181) {
      int x19182 = x19180 * 4;
      x19106 = x19182;
      printf("buffer.resize %d\n",x19182);
      int* x19185 = x19109;
      int* x19186 = (int*)realloc(x19185,x19182 * sizeof(int));
      x19109 = x19186;
      int* x19188 = x19111;
      int* x19189 = (int*)realloc(x19188,x19182 * sizeof(int));
      x19111 = x19189;
      int* x19191 = x19113;
      int* x19192 = (int*)realloc(x19191,x19182 * sizeof(int));
      x19113 = x19192;
      double* x19197 = x19117;
      double* x19198 = (double*)realloc(x19197,x19182 * sizeof(double));
      x19117 = x19198;
      double* x19200 = x19119;
      double* x19201 = (double*)realloc(x19200,x19182 * sizeof(double));
      x19119 = x19201;
      double* x19203 = x19121;
      double* x19204 = (double*)realloc(x19203,x19182 * sizeof(double));
      x19121 = x19204;
    } else {
    }
    int* x19235 = x19109;
    x19235[x19179] = x19142;
    int* x19237 = x19111;
    x19237[x19179] = x19143;
    int* x19239 = x19113;
    x19239[x19179] = x19144;
    double* x19243 = x19117;
    x19243[x19179] = x19146;
    double* x19245 = x19119;
    x19245[x19179] = x19147;
    double* x19247 = x19121;
    x19247[x19179] = x19148;
    x19107 = x19107 + 1;
  }
  GTree* x19278 = g_tree_new((GCompareFunc)x20301);;
  bool x19279 = true == false;
  int x17600;
  for(x17600=0; x17600 < 1; x17600++) {
    bool x19280 = false;
    int x19281 = 0;
    bool x19282 = false;
    int x19283 = 0;
    bool x19284 = false;
    int x19285 = 0;
    bool x19286 = false;
    int x19287 = 0;
    bool x19289 = false;
    int x19290 = 0;
    bool x19291 = false;
    int x19292 = 0;
    int* x19294 = (int*)malloc(1073741824 * sizeof(int));
    int* x19295 = x19294;
    char** x19296 = (char**)malloc(1073741824 * sizeof(char*));
    char** x19297 = x19296;
    int x19302 = 0;
    int* x19303 = (int*)malloc(1048576 * sizeof(int));
    int* x19304 = (int*)malloc(1073741824 * sizeof(int));
    int x17626;
    for(x17626=0; x17626 < 1048576; x17626++) {
      x19303[x17626] = -1;
    }
    char** x19312 = (char**)malloc(1073741824 * sizeof(char*));
    char** x19313 = x19312;
    int* x19318 = (int*)malloc(1073741824 * sizeof(int));
    int* x19319 = x19318;
    int x19332 = 0;
    int* x19333 = (int*)malloc(1048576 * sizeof(int));
    int* x19334 = (int*)malloc(1073741824 * sizeof(int));
    int x17657;
    for(x17657=0; x17657 < 1048576; x17657++) {
      x19333[x17657] = -1;
    }
    int* x19340 = (int*)malloc(1073741824 * sizeof(int));
    int* x19341 = x19340;
    int x19358 = 0;
    int* x19359 = (int*)malloc(1048576 * sizeof(int));
    int* x19360 = (int*)malloc(1073741824 * sizeof(int));
    int x17684;
    for(x17684=0; x17684 < 1048576; x17684++) {
      x19359[x17684] = -1;
    }
    int* x19366 = (int*)malloc(1073741824 * sizeof(int));
    int* x19367 = x19366;
    int* x19368 = (int*)malloc(1073741824 * sizeof(int));
    int* x19369 = x19368;
    double* x19372 = (double*)malloc(1073741824 * sizeof(double));
    double* x19373 = x19372;
    int x19376 = 0;
    int* x19377 = (int*)malloc(1048576 * sizeof(int));
    int* x19378 = (int*)malloc(1073741824 * sizeof(int));
    int x17703;
    for(x17703=0; x17703 < 1048576; x17703++) {
      x19377[x17703] = -1;
    }
    double* x19390 = (double*)malloc(1073741824 * sizeof(double));
    double* x19391 = x19390;
    char** x19414 = (char**)malloc(1073741824 * sizeof(char*));
    char** x19415 = x19414;
    int* x19434 = (int*)malloc(1073741824 * sizeof(int));
    int* x19435 = x19434;
    double* x19442 = (double*)malloc(1073741824 * sizeof(double));
    double* x19443 = x19442;
    double* x19444 = (double*)malloc(1073741824 * sizeof(double));
    double* x19445 = x19444;
    double* x19446 = (double*)malloc(1073741824 * sizeof(double));
    double* x19447 = x19446;
    int x19466 = 0;
    int* x19467 = (int*)malloc(1048576 * sizeof(int));
    int* x19468 = (int*)malloc(1073741824 * sizeof(int));
    int x17794;
    for(x17794=0; x17794 < 1048576; x17794++) {
      x19467[x17794] = -1;
    }
    int x19474 = 1048576;
    int x19475 = 0;
    char** x19476 = (char**)malloc(1048576 * sizeof(char*));
    char** x19477 = x19476;
    int* x19478 = (int*)malloc(1048576 * sizeof(int));
    int* x19479 = x19478;
    double* x19480 = (double*)malloc(1048576 * sizeof(double));
    double* x19481 = x19480;
    int x19482 = 4194304;
    int x19483 = 0;
    int* x19484 = (int*)malloc(4194304 * sizeof(int));
    int* x19485 = x19484;
    int x17812;
    for(x17812=0; x17812 < 4194304; x17812++) {
      int* x19486 = x19485;
      x19486[x17812] = -1;
    }
    int x19494 = 0;
    struct timeval x18662, x18663, x20294;
    gettimeofday(&x18662, NULL);
    printf("((PARTSUPP X (PART X ((NATION X SUPPLIER) X LINEITEM))) X ORDERS): leftParent.next start\n");
    struct timeval x18359, x18360, x20003;
    gettimeofday(&x18359, NULL);
    printf("(PARTSUPP X (PART X ((NATION X SUPPLIER) X LINEITEM))): leftParent.next start\n");
    struct timeval x17883, x17884, x19541;
    gettimeofday(&x17883, NULL);
    printf("%s\n","begin scan PARTSUPP");
    for (;;) {
      bool x19498 = x19289;
      bool x19499 = !x19498;
      bool x19504 = x19499;
      if (x19499) {
        int x19500 = x19290;
        int x19501 = x18957;
        bool x19502 = x19500 < x19501;
        x19504 = x19502;
      }
      bool x19505 = x19504;
      if (!x19505) break;
      int x19508 = x19290;
      int* x19509 = x18959;
      int x19510 = x19509[x19508];
      int* x19511 = x18961;
      int x19512 = x19511[x19508];
      double* x19515 = x18965;
      double x19516 = x19515[x19508];
      x19290 = x19290 + 1;
      int x19520 = x19376;
      int* x19521 = x19367;
      x19521[x19520] = x19510;
      int* x19523 = x19369;
      x19523[x19520] = x19512;
      double* x19527 = x19373;
      x19527[x19520] = x19516;
      x19376 = x19376 + 1;
      int x19532 = x19510 & 1048575;
      int x19533 = x19377[x19532];
      x19377[x19532] = x19520;
      x19378[x19520] = x19533;
    }
    printf("(PARTSUPP X (PART X ((NATION X SUPPLIER) X LINEITEM))): leftParent.next done\n");
    gettimeofday(&x17884, NULL);
    timeval_subtract(&x19541, &x17884, &x17883);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x19541.tv_sec * 1000) + (x19541.tv_usec/1000)));
    printf("(PARTSUPP X (PART X ((NATION X SUPPLIER) X LINEITEM))): rightParent.next start\n");
    struct timeval x18353, x18354, x19998;
    gettimeofday(&x18353, NULL);
    printf("(PART X ((NATION X SUPPLIER) X LINEITEM)): leftParent.next start\n");
    struct timeval x17951, x17952, x19609;
    gettimeofday(&x17951, NULL);
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x19546 = x19286;
      bool x19547 = !x19546;
      bool x19552 = x19547;
      if (x19547) {
        int x19548 = x19287;
        int x19549 = x18682;
        bool x19550 = x19548 < x19549;
        x19552 = x19550;
      }
      bool x19553 = x19552;
      if (!x19553) break;
      int x19556 = x19287;
      int* x19557 = x18684;
      int x19558 = x19557[x19556];
      char** x19559 = x18686;
      char* x19560 = x19559[x19556];
      x19287 = x19287 + 1;
      bool x19576 = strstr(x19560,"ghost") != NULL;
      if (x19576) {
        int x19577 = x19358;
        int* x19578 = x19341;
        x19578[x19577] = x19558;
        x19358 = x19358 + 1;
        int x19597 = x19558 & 1048575;
        int x19598 = x19359[x19597];
        x19359[x19597] = x19577;
        x19360[x19577] = x19598;
      } else {
      }
    }
    printf("(PART X ((NATION X SUPPLIER) X LINEITEM)): leftParent.next done\n");
    gettimeofday(&x17952, NULL);
    timeval_subtract(&x19609, &x17952, &x17951);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x19609.tv_sec * 1000) + (x19609.tv_usec/1000)));
    printf("(PART X ((NATION X SUPPLIER) X LINEITEM)): rightParent.next start\n");
    struct timeval x18347, x18348, x19993;
    gettimeofday(&x18347, NULL);
    printf("((NATION X SUPPLIER) X LINEITEM): leftParent.next start\n");
    struct timeval x18093, x18094, x19746;
    gettimeofday(&x18093, NULL);
    printf("(NATION X SUPPLIER): leftParent.next start\n");
    struct timeval x17997, x17998, x19654;
    gettimeofday(&x17997, NULL);
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x19615 = x19280;
      bool x19616 = !x19615;
      bool x19621 = x19616;
      if (x19616) {
        int x19617 = x19281;
        int x19618 = x18796;
        bool x19619 = x19617 < x19618;
        x19621 = x19619;
      }
      bool x19622 = x19621;
      if (!x19622) break;
      int x19625 = x19281;
      int* x19626 = x18798;
      int x19627 = x19626[x19625];
      char** x19628 = x18800;
      char* x19629 = x19628[x19625];
      x19281 = x19281 + 1;
      int x19635 = x19302;
      int* x19636 = x19295;
      x19636[x19635] = x19627;
      char** x19638 = x19297;
      x19638[x19635] = x19629;
      x19302 = x19302 + 1;
      int x19645 = x19627 & 1048575;
      int x19646 = x19303[x19645];
      x19303[x19645] = x19635;
      x19304[x19635] = x19646;
    }
    printf("(NATION X SUPPLIER): leftParent.next done\n");
    gettimeofday(&x17998, NULL);
    timeval_subtract(&x19654, &x17998, &x17997);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x19654.tv_sec * 1000) + (x19654.tv_usec/1000)));
    printf("(NATION X SUPPLIER): rightParent.next start\n");
    struct timeval x18087, x18088, x19741;
    gettimeofday(&x18087, NULL);
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x19658 = x19282;
      bool x19659 = !x19658;
      bool x19664 = x19659;
      if (x19659) {
        int x19660 = x19283;
        int x19661 = x19018;
        bool x19662 = x19660 < x19661;
        x19664 = x19662;
      }
      bool x19665 = x19664;
      if (!x19665) break;
      int x19668 = x19283;
      int* x19669 = x19020;
      int x19670 = x19669[x19668];
      int* x19675 = x19026;
      int x19676 = x19675[x19668];
      x19283 = x19283 + 1;
      int x19684 = x19676 & 1048575;
      int x19685 = x19303[x19684];
      int x19686 = x19685;
      int x19687 = x19670 & 1048575;
      for (;;) {
        int x19688 = x19686;
        bool x19689 = x19688 != -1;
        if (!x19689) break;
        int x19691 = x19686;
        int* x19692 = x19295;
        int x19693 = x19692[x19691];
        char** x19694 = x19297;
        char* x19695 = x19694[x19691];
        int x19700 = x19304[x19691];
        x19686 = x19700;
        bool x19702 = x19693 == x19676;
        if (x19702) {
          int x19703 = x19332;
          char** x19706 = x19313;
          x19706[x19703] = x19695;
          int* x19712 = x19319;
          x19712[x19703] = x19670;
          x19332 = x19332 + 1;
          int x19727 = x19333[x19687];
          x19333[x19687] = x19703;
          x19334[x19703] = x19727;
        } else {
        }
      }
    }
    printf("(NATION X SUPPLIER): rightParent.next done\n");
    gettimeofday(&x18088, NULL);
    timeval_subtract(&x19741, &x18088, &x18087);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x19741.tv_sec * 1000) + (x19741.tv_usec/1000)));
    printf("((NATION X SUPPLIER) X LINEITEM): leftParent.next done\n");
    gettimeofday(&x18094, NULL);
    timeval_subtract(&x19746, &x18094, &x18093);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x19746.tv_sec * 1000) + (x19746.tv_usec/1000)));
    printf("((NATION X SUPPLIER) X LINEITEM): rightParent.next start\n");
    struct timeval x18341, x18342, x19988;
    gettimeofday(&x18341, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x19750 = x19284;
      bool x19751 = !x19750;
      bool x19756 = x19751;
      if (x19751) {
        int x19752 = x19285;
        int x19753 = x19107;
        bool x19754 = x19752 < x19753;
        x19756 = x19754;
      }
      bool x19757 = x19756;
      if (!x19757) break;
      int x19760 = x19285;
      int* x19761 = x19109;
      int x19762 = x19761[x19760];
      int* x19763 = x19111;
      int x19764 = x19763[x19760];
      int* x19765 = x19113;
      int x19766 = x19765[x19760];
      double* x19769 = x19117;
      double x19770 = x19769[x19760];
      double* x19771 = x19119;
      double x19772 = x19771[x19760];
      double* x19773 = x19121;
      double x19774 = x19773[x19760];
      x19285 = x19285 + 1;
      int x19794 = x19766 & 1048575;
      int x19795 = x19333[x19794];
      int x19796 = x19795;
      int x19797 = x19764 & 1048575;
      int x19798 = x19762 & 1048575;
      for (;;) {
        int x19799 = x19796;
        bool x19800 = x19799 != -1;
        if (!x19800) break;
        int x19802 = x19796;
        char** x19805 = x19313;
        char* x19806 = x19805[x19802];
        int* x19811 = x19319;
        int x19812 = x19811[x19802];
        int x19825 = x19334[x19802];
        x19796 = x19825;
        bool x19827 = x19812 == x19766;
        if (x19827) {
          int x19828 = x19359[x19797];
          int x19829 = x19828;
          for (;;) {
            int x19830 = x19829;
            bool x19831 = x19830 != -1;
            if (!x19831) break;
            int x19833 = x19829;
            int* x19834 = x19341;
            int x19835 = x19834[x19833];
            int x19852 = x19360[x19833];
            x19829 = x19852;
            bool x19854 = x19835 == x19764;
            if (x19854) {
              int x19855 = x19377[x19797];
              int x19856 = x19855;
              for (;;) {
                int x19857 = x19856;
                bool x19858 = x19857 != -1;
                if (!x19858) break;
                int x19860 = x19856;
                int* x19861 = x19367;
                int x19862 = x19861[x19860];
                int* x19863 = x19369;
                int x19864 = x19863[x19860];
                double* x19867 = x19373;
                double x19868 = x19867[x19860];
                int x19871 = x19378[x19860];
                x19856 = x19871;
                bool x19873 = x19862 == x19764;
                bool x19876 = x19873;
                if (x19873) {
                  bool x19874 = x19864 == x19766;
                  x19876 = x19874;
                }
                bool x19877 = x19876;
                if (x19877) {
                  int x19878 = x19466;
                  double* x19885 = x19391;
                  x19885[x19878] = x19868;
                  char** x19909 = x19415;
                  x19909[x19878] = x19806;
                  int* x19929 = x19435;
                  x19929[x19878] = x19762;
                  double* x19937 = x19443;
                  x19937[x19878] = x19770;
                  double* x19939 = x19445;
                  x19939[x19878] = x19772;
                  double* x19941 = x19447;
                  x19941[x19878] = x19774;
                  x19466 = x19466 + 1;
                  int x19962 = x19467[x19798];
                  x19467[x19798] = x19878;
                  x19468[x19878] = x19962;
                } else {
                }
              }
            } else {
            }
          }
        } else {
        }
      }
    }
    printf("((NATION X SUPPLIER) X LINEITEM): rightParent.next done\n");
    gettimeofday(&x18342, NULL);
    timeval_subtract(&x19988, &x18342, &x18341);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x19988.tv_sec * 1000) + (x19988.tv_usec/1000)));
    printf("(PART X ((NATION X SUPPLIER) X LINEITEM)): rightParent.next done\n");
    gettimeofday(&x18348, NULL);
    timeval_subtract(&x19993, &x18348, &x18347);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x19993.tv_sec * 1000) + (x19993.tv_usec/1000)));
    printf("(PARTSUPP X (PART X ((NATION X SUPPLIER) X LINEITEM))): rightParent.next done\n");
    gettimeofday(&x18354, NULL);
    timeval_subtract(&x19998, &x18354, &x18353);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x19998.tv_sec * 1000) + (x19998.tv_usec/1000)));
    printf("((PARTSUPP X (PART X ((NATION X SUPPLIER) X LINEITEM))) X ORDERS): leftParent.next done\n");
    gettimeofday(&x18360, NULL);
    timeval_subtract(&x20003, &x18360, &x18359);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x20003.tv_sec * 1000) + (x20003.tv_usec/1000)));
    printf("((PARTSUPP X (PART X ((NATION X SUPPLIER) X LINEITEM))) X ORDERS): rightParent.next start\n");
    struct timeval x18622, x18623, x20256;
    gettimeofday(&x18622, NULL);
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x20007 = x19291;
      bool x20008 = !x20007;
      bool x20013 = x20008;
      if (x20008) {
        int x20009 = x19292;
        int x20010 = x18853;
        bool x20011 = x20009 < x20010;
        x20013 = x20011;
      }
      bool x20014 = x20013;
      if (!x20014) break;
      int x20017 = x19292;
      int* x20018 = x18855;
      int x20019 = x20018[x20017];
      long* x20026 = x18863;
      long x20027 = x20026[x20017];
      x19292 = x19292 + 1;
      int x20037 = x20019 & 1048575;
      int x20038 = x19467[x20037];
      int x20039 = x20038;
      long x20040 = x20027/10000;
      int x20041 = (int)x20040;
      for (;;) {
        int x20042 = x20039;
        bool x20043 = x20042 != -1;
        if (!x20043) break;
        int x20045 = x20039;
        double* x20052 = x19391;
        double x20053 = x20052[x20045];
        char** x20076 = x19415;
        char* x20077 = x20076[x20045];
        int* x20096 = x19435;
        int x20097 = x20096[x20045];
        double* x20104 = x19443;
        double x20105 = x20104[x20045];
        double* x20106 = x19445;
        double x20107 = x20106[x20045];
        double* x20108 = x19447;
        double x20109 = x20108[x20045];
        int x20128 = x19468[x20045];
        x20039 = x20128;
        bool x20130 = x20097 == x20019;
        if (x20130) {
          int x20132 = x19482;
          int x20133 = x20132 - 1;
          char x20134 = x20077[0];
          int x20135 = x20134 * 41;
          int x20136 = x20135 + x20041;
          int x20137 = x20136 * 2;
          int x20138 = x20137 * 3;
          int x20139 = x20138 & x20133;
          int x20140 = x20139;
          int* x20141 = x19485;
          int x20142 = x20141[x20139];
          int x20143 = x20142;
          int x20144 = x20139 + 1;
          int x20145 = x20141[x20144];
          int x20146 = x20145;
          for (;;) {
            int x20147 = x20143;
            bool x20148 = x20147 != -1;
            bool x20170 = x20148;
            if (x20148) {
              int x20149 = x20146;
              bool x20150 = x20149 != x20138;
              bool x20166 = x20150;
              if (x20150 == false) {
                int x20151 = x20143;
                char** x20152 = x19477;
                char* x20153 = x20152[x20151];
                int* x20154 = x19479;
                int x20155 = x20154[x20151];
                bool x20158 = strcmp(x20153,x20077) == 0;;
                bool x20161 = x20158;
                if (x20158) {
                  bool x20159 = x20155 == x20041;
                  x20161 = x20159;
                }
                bool x20162 = x20161;
                bool x20163 = !x20162;
                x20166 = x20163;
              }
              bool x20167 = x20166;
              x20170 = x20167;
            }
            bool x20171 = x20170;
            if (!x20171) break;
            int x20174 = x20140;
            int x20175 = x20174 + 2;
            int x20176 = x20175 & x20133;
            x20140 = x20176;
            int* x20178 = x19485;
            int x20179 = x20178[x20176];
            x20143 = x20179;
            int x20181 = x20176 + 1;
            int x20182 = x20178[x20181];
            x20146 = x20182;
          }
          int x20187 = x20143;
          bool x20188 = x20187 == -1;
          int x20229;
          if (x20188) {
            int x20189 = x19483;
            int x20190 = x20140;
            x20141[x20190] = x20189;
            int x20192 = x20190 + 1;
            x20141[x20192] = x20138;
            x19483 = x19483 + 1;
            int x20195 = x19475;
            int x20196 = x19474;
            bool x20197 = x20195 == x20196;
            if (x20197) {
              int x20198 = x20196 * 4;
              x19474 = x20198;
              printf("buffer.resize %d\n",x20198);
              printf("buffer.resize %d\n",x20198);
              char** x20202 = x19477;
              char** x20203 = (char**)realloc(x20202,x20198 * sizeof(char*));
              x19477 = x20203;
              int* x20205 = x19479;
              int* x20206 = (int*)realloc(x20205,x20198 * sizeof(int));
              x19479 = x20206;
              printf("buffer.resize %d\n",x20198);
              double* x20209 = x19481;
              double* x20210 = (double*)realloc(x20209,x20198 * sizeof(double));
              x19481 = x20210;
            } else {
            }
            char** x20214 = x19477;
            x20214[x20195] = x20077;
            int* x20216 = x19479;
            x20216[x20195] = x20041;
            double* x20218 = x19481;
            x20218[x20195] = 0.0;
            x19475 = x19475 + 1;
            int x20221 = x19483;
            int x20222 = x20221 * 4;
            bool x20223 = x20222 > x20132;
            if (x20223) {
              printf("%s\n","ERROR: hash.resize not implemented");
            } else {
            }
            x20229 = x20189;
          } else {
            x20229 = x20187;
          }
          char** x20230 = x19477;
          char* x20231 = x20230[x20229];
          int* x20232 = x19479;
          int x20233 = x20232[x20229];
          double* x20234 = x19481;
          double x20235 = x20234[x20229];
          x20230[x20229] = x20231;
          x20232[x20229] = x20233;
          double x20238 = 1.0 - x20109;
          double x20239 = x20107 * x20238;
          double x20240 = x20053 * x20105;
          double x20241 = x20239 - x20240;
          double x20242 = x20235 + x20241;
          x20234[x20229] = x20242;
        } else {
        }
      }
    }
    printf("((PARTSUPP X (PART X ((NATION X SUPPLIER) X LINEITEM))) X ORDERS): rightParent.next done\n");
    gettimeofday(&x18623, NULL);
    timeval_subtract(&x20256, &x18623, &x18622);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x20256.tv_sec * 1000) + (x20256.tv_usec/1000)));
    int x20258 = x19475;
    int x18628;
    for(x18628=0; x18628 < x20258; x18628++) {
      char** x20259 = x19477;
      char* x20260 = x20259[x18628];
      int* x20261 = x19479;
      int x20262 = x20261[x18628];
      double* x20263 = x19481;
      double x20264 = x20263[x18628];
      struct Anon1548200872* x20265 = (struct Anon1548200872*)malloc(sizeof(struct Anon1548200872));
      x20265->NATION = x20260;
      x20265->O_YEAR = x20262;
      struct Anon2052879266* x20266 = (struct Anon2052879266*)malloc(sizeof(struct Anon2052879266));
      x20266->_0 = x20264;
      struct Anon344387643* x20267 = (struct Anon344387643*)malloc(sizeof(struct Anon344387643));
      x20267->key = x20265;
      x20267->aggs = x20266;
      g_tree_insert(x19278,x20267,x20267);; // x20268
    }
    for (;;) {
      int x20271 = g_tree_nnodes(x19278);
      bool x20272 = x20271 != 0;
      if (!x20272) break;
      struct Anon344387643* x20274 = NULL;
      g_tree_foreach(x19278, (GTraverseFunc)x20307, &x20274);
      g_tree_remove(x19278,x20274);
      if (x19279) {
      } else {
        struct Anon1548200872* x20278 = x20274->key;;
        char* x20279 = x20278->NATION;;
        int x20280 = x20278->O_YEAR;;
        struct Anon2052879266* x20281 = x20274->aggs;;
        double x20282 = x20281->_0;;
        printf("%s|%d|%.4f\n",x20279,x20280,x20282);
        x19494 = x19494 + 1;
      }
    }
    int x20290 = x19494;
    printf("(%d rows)\n",x20290);
    gettimeofday(&x18663, NULL);
    timeval_subtract(&x20294, &x18663, &x18662);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x20294.tv_sec * 1000) + (x20294.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
