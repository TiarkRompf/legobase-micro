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
struct Anon855148991;
struct Anon147418070;
struct Anon920667905Anon811555534Anon168903330;
struct Anon1465150758;
struct Anon482109446;
struct Anon546410247;
struct Anon713865179;
struct Anon786783320;
struct Anon1078540535;
struct Anon2134411685;
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
struct Anon2131537536;
struct Anon1987966504;
struct Anon637505587;
struct Anon2052879266;
struct Anon313206116;
struct Anon713865179Anon72918141Anon1268892766;
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

struct Anon1078540535 {
char* N_NAME;
int N_NATIONKEY;
};

struct Anon2134411685 {
int key;
struct Anon1023322325* aggs;
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
struct Anon850505655* left;
struct Anon1251919804* right;
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
int x17000(struct Anon1987966504* x14039, struct Anon1987966504* x14038);
int x17006(struct Anon1987966504* x17001, struct Anon1987966504* x17002, struct Anon1987966504** x17003);
int x17000(struct Anon1987966504* x14039, struct Anon1987966504* x14038) {
  int x14040 = x14038->key;;
  int x14041 = x14039->key;;
  bool x14042 = x14040 < x14041;
  int x15749;
  if (x14042) {
    x15749 = -1;
  } else {
    bool x14043 = x14040 > x14041;
    int x15747;
    if (x14043) {
      x15747 = 1;
    } else {
      x15747 = 0;
    }
    x15749 = x15747;
  }
  return x15749;
}
int x17006(struct Anon1987966504* x17001, struct Anon1987966504* x17002, struct Anon1987966504** x17003) {
  *x17003 = x17002;
  return 0;
}

/************************ MAIN BODY **************************/
int main(int x13080, char** x13081) {
  FILE* x15067 = fopen("../databases/sf2/nation.tbl", "r");
  int x15068 = 1048576;
  int x15069 = 0;
  int* x15070 = (int*)malloc(1048576 * sizeof(int));
  int* x15071 = x15070;
  char** x15072 = (char**)malloc(1048576 * sizeof(char*));
  char** x15073 = x15072;
  int* x15074 = (int*)malloc(1048576 * sizeof(int));
  int* x15075 = x15074;
  for (;;) {
    bool x15078 = !feof(x15067);
    if (!x15078) break;
    int x15080 = 0;
    if (fscanf(x15067,"%d|",&x15080) == EOF) break;
    char* x15081 = (char*)malloc(26 * sizeof(char));
    int x15083 = 0;
    char x15082 = ' ';
    while (1) {
      fscanf(x15067,"%c",&x15082);
      if (x15082=='|' || x15082=='\n') break;
      if (x15083>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15083); break;}
      ((char*)x15081)[x15083] = x15082;
      x15083 += 1;
    }
    ((char*)x15081)[x15083] = '\0';
    char* x15085 = x15081; // unsafe immutable;
    int x15086 = 0;
    if (fscanf(x15067,"%d|",&x15086) == EOF) break;
    char* x15087 = (char*)malloc(153 * sizeof(char));
    int x15089 = 0;
    char x15088 = ' ';
    while (1) {
      fscanf(x15067,"%c",&x15088);
      if (x15088=='|' || x15088=='\n') break;
      if (x15089>=152) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15089); break;}
      ((char*)x15087)[x15089] = x15088;
      x15089 += 1;
    }
    ((char*)x15087)[x15089] = '\0';
    int x15092 = x15069;
    int x15093 = x15068;
    bool x15094 = x15092 == x15093;
    if (x15094) {
      int x15095 = x15093 * 4;
      x15068 = x15095;
      printf("buffer.resize %d\n",x15095);
      int* x15098 = x15071;
      int* x15099 = (int*)realloc(x15098,x15095 * sizeof(int));
      x15071 = x15099;
      char** x15101 = x15073;
      char** x15102 = (char**)realloc(x15101,x15095 * sizeof(char*));
      x15073 = x15102;
      int* x15104 = x15075;
      int* x15105 = (int*)realloc(x15104,x15095 * sizeof(int));
      x15075 = x15105;
    } else {
    }
    int* x15112 = x15071;
    x15112[x15092] = x15080;
    char** x15114 = x15073;
    x15114[x15092] = x15085;
    int* x15116 = x15075;
    x15116[x15092] = x15086;
    x15069 = x15069 + 1;
  }
  FILE* x15124 = fopen("../databases/sf2/region.tbl", "r");
  int x15125 = 1048576;
  int x15126 = 0;
  int* x15127 = (int*)malloc(1048576 * sizeof(int));
  int* x15128 = x15127;
  char** x15129 = (char**)malloc(1048576 * sizeof(char*));
  char** x15130 = x15129;
  for (;;) {
    bool x15133 = !feof(x15124);
    if (!x15133) break;
    int x15135 = 0;
    if (fscanf(x15124,"%d|",&x15135) == EOF) break;
    char* x15136 = (char*)malloc(26 * sizeof(char));
    int x15138 = 0;
    char x15137 = ' ';
    while (1) {
      fscanf(x15124,"%c",&x15137);
      if (x15137=='|' || x15137=='\n') break;
      if (x15138>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15138); break;}
      ((char*)x15136)[x15138] = x15137;
      x15138 += 1;
    }
    ((char*)x15136)[x15138] = '\0';
    char* x15140 = x15136; // unsafe immutable;
    char* x15141 = (char*)malloc(153 * sizeof(char));
    int x15143 = 0;
    char x15142 = ' ';
    while (1) {
      fscanf(x15124,"%c",&x15142);
      if (x15142=='|' || x15142=='\n') break;
      if (x15143>=152) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15143); break;}
      ((char*)x15141)[x15143] = x15142;
      x15143 += 1;
    }
    ((char*)x15141)[x15143] = '\0';
    int x15146 = x15126;
    int x15147 = x15125;
    bool x15148 = x15146 == x15147;
    if (x15148) {
      int x15149 = x15147 * 4;
      x15125 = x15149;
      printf("buffer.resize %d\n",x15149);
      int* x15152 = x15128;
      int* x15153 = (int*)realloc(x15152,x15149 * sizeof(int));
      x15128 = x15153;
      char** x15155 = x15130;
      char** x15156 = (char**)realloc(x15155,x15149 * sizeof(char*));
      x15130 = x15156;
    } else {
    }
    int* x15163 = x15128;
    x15163[x15146] = x15135;
    char** x15165 = x15130;
    x15165[x15146] = x15140;
    x15126 = x15126 + 1;
  }
  FILE* x15173 = fopen("../databases/sf2/part.tbl", "r");
  int x15174 = 1048576;
  int x15175 = 0;
  int* x15176 = (int*)malloc(1048576 * sizeof(int));
  int* x15177 = x15176;
  char** x15184 = (char**)malloc(1048576 * sizeof(char*));
  char** x15185 = x15184;
  for (;;) {
    bool x15195 = !feof(x15173);
    if (!x15195) break;
    int x15197 = 0;
    if (fscanf(x15173,"%d|",&x15197) == EOF) break;
    char* x15198 = (char*)malloc(56 * sizeof(char));
    int x15200 = 0;
    char x15199 = ' ';
    while (1) {
      fscanf(x15173,"%c",&x15199);
      if (x15199=='|' || x15199=='\n') break;
      if (x15200>=55) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15200); break;}
      ((char*)x15198)[x15200] = x15199;
      x15200 += 1;
    }
    ((char*)x15198)[x15200] = '\0';
    char* x15203 = (char*)malloc(26 * sizeof(char));
    int x15205 = 0;
    char x15204 = ' ';
    while (1) {
      fscanf(x15173,"%c",&x15204);
      if (x15204=='|' || x15204=='\n') break;
      if (x15205>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15205); break;}
      ((char*)x15203)[x15205] = x15204;
      x15205 += 1;
    }
    ((char*)x15203)[x15205] = '\0';
    char* x15208 = (char*)malloc(11 * sizeof(char));
    int x15210 = 0;
    char x15209 = ' ';
    while (1) {
      fscanf(x15173,"%c",&x15209);
      if (x15209=='|' || x15209=='\n') break;
      if (x15210>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15210); break;}
      ((char*)x15208)[x15210] = x15209;
      x15210 += 1;
    }
    ((char*)x15208)[x15210] = '\0';
    char* x15213 = (char*)malloc(26 * sizeof(char));
    int x15215 = 0;
    char x15214 = ' ';
    while (1) {
      fscanf(x15173,"%c",&x15214);
      if (x15214=='|' || x15214=='\n') break;
      if (x15215>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15215); break;}
      ((char*)x15213)[x15215] = x15214;
      x15215 += 1;
    }
    ((char*)x15213)[x15215] = '\0';
    char* x15217 = x15213; // unsafe immutable;
    int x15218 = 0;
    if (fscanf(x15173,"%d|",&x15218) == EOF) break;
    char* x15219 = (char*)malloc(11 * sizeof(char));
    int x15221 = 0;
    char x15220 = ' ';
    while (1) {
      fscanf(x15173,"%c",&x15220);
      if (x15220=='|' || x15220=='\n') break;
      if (x15221>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15221); break;}
      ((char*)x15219)[x15221] = x15220;
      x15221 += 1;
    }
    ((char*)x15219)[x15221] = '\0';
    double x15224 = 0.0;
    if (fscanf(x15173,"%lf|",&x15224) == EOF) break;
    char* x15225 = (char*)malloc(24 * sizeof(char));
    int x15227 = 0;
    char x15226 = ' ';
    while (1) {
      fscanf(x15173,"%c",&x15226);
      if (x15226=='|' || x15226=='\n') break;
      if (x15227>=23) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15227); break;}
      ((char*)x15225)[x15227] = x15226;
      x15227 += 1;
    }
    ((char*)x15225)[x15227] = '\0';
    int x15230 = x15175;
    int x15231 = x15174;
    bool x15232 = x15230 == x15231;
    if (x15232) {
      int x15233 = x15231 * 4;
      x15174 = x15233;
      printf("buffer.resize %d\n",x15233);
      int* x15236 = x15177;
      int* x15237 = (int*)realloc(x15236,x15233 * sizeof(int));
      x15177 = x15237;
      char** x15248 = x15185;
      char** x15249 = (char**)realloc(x15248,x15233 * sizeof(char*));
      x15185 = x15249;
    } else {
    }
    int* x15265 = x15177;
    x15265[x15230] = x15197;
    char** x15273 = x15185;
    x15273[x15230] = x15217;
    x15175 = x15175 + 1;
  }
  FILE* x15287 = fopen("../databases/sf2/orders.tbl", "r");
  int x15288 = 1048576;
  int x15289 = 0;
  int* x15290 = (int*)malloc(1048576 * sizeof(int));
  int* x15291 = x15290;
  int* x15292 = (int*)malloc(1048576 * sizeof(int));
  int* x15293 = x15292;
  long* x15298 = (long*)malloc(1048576 * sizeof(long));
  long* x15299 = x15298;
  for (;;) {
    bool x15308 = !feof(x15287);
    if (!x15308) break;
    int x15310 = 0;
    if (fscanf(x15287,"%d|",&x15310) == EOF) break;
    int x15311 = 0;
    if (fscanf(x15287,"%d|",&x15311) == EOF) break;
    char x15312 = ' ';
    if (fscanf(x15287,"%c|",&x15312) == EOF) break;
    double x15313 = 0.0;
    if (fscanf(x15287,"%lf|",&x15313) == EOF) break;
    int x15314 = 0;
    int x15315 = 0;
    int x15316 = 0;
    fscanf(x15287, "%d-%d-%d|",&x15314, &x15315, &x15316);
    long x15317 = (x15314 * 10000) + (x15315 * 100) + x15316;
    char* x15318 = (char*)malloc(16 * sizeof(char));
    int x15320 = 0;
    char x15319 = ' ';
    while (1) {
      fscanf(x15287,"%c",&x15319);
      if (x15319=='|' || x15319=='\n') break;
      if (x15320>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15320); break;}
      ((char*)x15318)[x15320] = x15319;
      x15320 += 1;
    }
    ((char*)x15318)[x15320] = '\0';
    char* x15323 = (char*)malloc(16 * sizeof(char));
    int x15325 = 0;
    char x15324 = ' ';
    while (1) {
      fscanf(x15287,"%c",&x15324);
      if (x15324=='|' || x15324=='\n') break;
      if (x15325>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15325); break;}
      ((char*)x15323)[x15325] = x15324;
      x15325 += 1;
    }
    ((char*)x15323)[x15325] = '\0';
    int x15328 = 0;
    if (fscanf(x15287,"%d|",&x15328) == EOF) break;
    char* x15329 = (char*)malloc(80 * sizeof(char));
    int x15331 = 0;
    char x15330 = ' ';
    while (1) {
      fscanf(x15287,"%c",&x15330);
      if (x15330=='|' || x15330=='\n') break;
      if (x15331>=79) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15331); break;}
      ((char*)x15329)[x15331] = x15330;
      x15331 += 1;
    }
    ((char*)x15329)[x15331] = '\0';
    int x15334 = x15289;
    int x15335 = x15288;
    bool x15336 = x15334 == x15335;
    if (x15336) {
      int x15337 = x15335 * 4;
      x15288 = x15337;
      printf("buffer.resize %d\n",x15337);
      int* x15340 = x15291;
      int* x15341 = (int*)realloc(x15340,x15337 * sizeof(int));
      x15291 = x15341;
      int* x15343 = x15293;
      int* x15344 = (int*)realloc(x15343,x15337 * sizeof(int));
      x15293 = x15344;
      long* x15352 = x15299;
      long* x15353 = (long*)realloc(x15352,x15337 * sizeof(long));
      x15299 = x15353;
    } else {
    }
    int* x15369 = x15291;
    x15369[x15334] = x15310;
    int* x15371 = x15293;
    x15371[x15334] = x15311;
    long* x15377 = x15299;
    x15377[x15334] = x15317;
    x15289 = x15289 + 1;
  }
  FILE* x15391 = fopen("../databases/sf2/lineitem.tbl", "r");
  int x15392 = 1048576;
  int x15393 = 0;
  int* x15394 = (int*)malloc(1048576 * sizeof(int));
  int* x15395 = x15394;
  int* x15396 = (int*)malloc(1048576 * sizeof(int));
  int* x15397 = x15396;
  int* x15398 = (int*)malloc(1048576 * sizeof(int));
  int* x15399 = x15398;
  double* x15404 = (double*)malloc(1048576 * sizeof(double));
  double* x15405 = x15404;
  double* x15406 = (double*)malloc(1048576 * sizeof(double));
  double* x15407 = x15406;
  for (;;) {
    bool x15426 = !feof(x15391);
    if (!x15426) break;
    int x15428 = 0;
    if (fscanf(x15391,"%d|",&x15428) == EOF) break;
    int x15429 = 0;
    if (fscanf(x15391,"%d|",&x15429) == EOF) break;
    int x15430 = 0;
    if (fscanf(x15391,"%d|",&x15430) == EOF) break;
    int x15431 = 0;
    if (fscanf(x15391,"%d|",&x15431) == EOF) break;
    double x15432 = 0.0;
    if (fscanf(x15391,"%lf|",&x15432) == EOF) break;
    double x15433 = 0.0;
    if (fscanf(x15391,"%lf|",&x15433) == EOF) break;
    double x15434 = 0.0;
    if (fscanf(x15391,"%lf|",&x15434) == EOF) break;
    double x15435 = 0.0;
    if (fscanf(x15391,"%lf|",&x15435) == EOF) break;
    char x15436 = ' ';
    if (fscanf(x15391,"%c|",&x15436) == EOF) break;
    char x15437 = ' ';
    if (fscanf(x15391,"%c|",&x15437) == EOF) break;
    int x15438 = 0;
    int x15439 = 0;
    int x15440 = 0;
    fscanf(x15391, "%d-%d-%d|",&x15438, &x15439, &x15440);
    long x15441 = (x15438 * 10000) + (x15439 * 100) + x15440;
    int x15442 = 0;
    int x15443 = 0;
    int x15444 = 0;
    fscanf(x15391, "%d-%d-%d|",&x15442, &x15443, &x15444);
    long x15445 = (x15442 * 10000) + (x15443 * 100) + x15444;
    int x15446 = 0;
    int x15447 = 0;
    int x15448 = 0;
    fscanf(x15391, "%d-%d-%d|",&x15446, &x15447, &x15448);
    long x15449 = (x15446 * 10000) + (x15447 * 100) + x15448;
    char* x15450 = (char*)malloc(26 * sizeof(char));
    int x15452 = 0;
    char x15451 = ' ';
    while (1) {
      fscanf(x15391,"%c",&x15451);
      if (x15451=='|' || x15451=='\n') break;
      if (x15452>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15452); break;}
      ((char*)x15450)[x15452] = x15451;
      x15452 += 1;
    }
    ((char*)x15450)[x15452] = '\0';
    char* x15455 = (char*)malloc(11 * sizeof(char));
    int x15457 = 0;
    char x15456 = ' ';
    while (1) {
      fscanf(x15391,"%c",&x15456);
      if (x15456=='|' || x15456=='\n') break;
      if (x15457>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15457); break;}
      ((char*)x15455)[x15457] = x15456;
      x15457 += 1;
    }
    ((char*)x15455)[x15457] = '\0';
    char* x15460 = (char*)malloc(45 * sizeof(char));
    int x15462 = 0;
    char x15461 = ' ';
    while (1) {
      fscanf(x15391,"%c",&x15461);
      if (x15461=='|' || x15461=='\n') break;
      if (x15462>=44) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15462); break;}
      ((char*)x15460)[x15462] = x15461;
      x15462 += 1;
    }
    ((char*)x15460)[x15462] = '\0';
    int x15465 = x15393;
    int x15466 = x15392;
    bool x15467 = x15465 == x15466;
    if (x15467) {
      int x15468 = x15466 * 4;
      x15392 = x15468;
      printf("buffer.resize %d\n",x15468);
      int* x15471 = x15395;
      int* x15472 = (int*)realloc(x15471,x15468 * sizeof(int));
      x15395 = x15472;
      int* x15474 = x15397;
      int* x15475 = (int*)realloc(x15474,x15468 * sizeof(int));
      x15397 = x15475;
      int* x15477 = x15399;
      int* x15478 = (int*)realloc(x15477,x15468 * sizeof(int));
      x15399 = x15478;
      double* x15486 = x15405;
      double* x15487 = (double*)realloc(x15486,x15468 * sizeof(double));
      x15405 = x15487;
      double* x15489 = x15407;
      double* x15490 = (double*)realloc(x15489,x15468 * sizeof(double));
      x15407 = x15490;
    } else {
    }
    int* x15521 = x15395;
    x15521[x15465] = x15428;
    int* x15523 = x15397;
    x15523[x15465] = x15429;
    int* x15525 = x15399;
    x15525[x15465] = x15430;
    double* x15531 = x15405;
    x15531[x15465] = x15433;
    double* x15533 = x15407;
    x15533[x15465] = x15434;
    x15393 = x15393 + 1;
  }
  FILE* x15557 = fopen("../databases/sf2/customer.tbl", "r");
  int x15558 = 1048576;
  int x15559 = 0;
  int* x15560 = (int*)malloc(1048576 * sizeof(int));
  int* x15561 = x15560;
  int* x15566 = (int*)malloc(1048576 * sizeof(int));
  int* x15567 = x15566;
  for (;;) {
    bool x15576 = !feof(x15557);
    if (!x15576) break;
    int x15578 = 0;
    if (fscanf(x15557,"%d|",&x15578) == EOF) break;
    char* x15579 = (char*)malloc(26 * sizeof(char));
    int x15581 = 0;
    char x15580 = ' ';
    while (1) {
      fscanf(x15557,"%c",&x15580);
      if (x15580=='|' || x15580=='\n') break;
      if (x15581>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15581); break;}
      ((char*)x15579)[x15581] = x15580;
      x15581 += 1;
    }
    ((char*)x15579)[x15581] = '\0';
    char* x15584 = (char*)malloc(41 * sizeof(char));
    int x15586 = 0;
    char x15585 = ' ';
    while (1) {
      fscanf(x15557,"%c",&x15585);
      if (x15585=='|' || x15585=='\n') break;
      if (x15586>=40) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15586); break;}
      ((char*)x15584)[x15586] = x15585;
      x15586 += 1;
    }
    ((char*)x15584)[x15586] = '\0';
    int x15589 = 0;
    if (fscanf(x15557,"%d|",&x15589) == EOF) break;
    char* x15590 = (char*)malloc(16 * sizeof(char));
    int x15592 = 0;
    char x15591 = ' ';
    while (1) {
      fscanf(x15557,"%c",&x15591);
      if (x15591=='|' || x15591=='\n') break;
      if (x15592>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15592); break;}
      ((char*)x15590)[x15592] = x15591;
      x15592 += 1;
    }
    ((char*)x15590)[x15592] = '\0';
    double x15595 = 0.0;
    if (fscanf(x15557,"%lf|",&x15595) == EOF) break;
    char* x15596 = (char*)malloc(11 * sizeof(char));
    int x15598 = 0;
    char x15597 = ' ';
    while (1) {
      fscanf(x15557,"%c",&x15597);
      if (x15597=='|' || x15597=='\n') break;
      if (x15598>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15598); break;}
      ((char*)x15596)[x15598] = x15597;
      x15598 += 1;
    }
    ((char*)x15596)[x15598] = '\0';
    char* x15601 = (char*)malloc(118 * sizeof(char));
    int x15603 = 0;
    char x15602 = ' ';
    while (1) {
      fscanf(x15557,"%c",&x15602);
      if (x15602=='|' || x15602=='\n') break;
      if (x15603>=117) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15603); break;}
      ((char*)x15601)[x15603] = x15602;
      x15603 += 1;
    }
    ((char*)x15601)[x15603] = '\0';
    int x15606 = x15559;
    int x15607 = x15558;
    bool x15608 = x15606 == x15607;
    if (x15608) {
      int x15609 = x15607 * 4;
      x15558 = x15609;
      printf("buffer.resize %d\n",x15609);
      int* x15612 = x15561;
      int* x15613 = (int*)realloc(x15612,x15609 * sizeof(int));
      x15561 = x15613;
      int* x15621 = x15567;
      int* x15622 = (int*)realloc(x15621,x15609 * sizeof(int));
      x15567 = x15622;
    } else {
    }
    int* x15638 = x15561;
    x15638[x15606] = x15578;
    int* x15644 = x15567;
    x15644[x15606] = x15589;
    x15559 = x15559 + 1;
  }
  FILE* x15658 = fopen("../databases/sf2/supplier.tbl", "r");
  int x15659 = 1048576;
  int x15660 = 0;
  int* x15661 = (int*)malloc(1048576 * sizeof(int));
  int* x15662 = x15661;
  int* x15667 = (int*)malloc(1048576 * sizeof(int));
  int* x15668 = x15667;
  for (;;) {
    bool x15675 = !feof(x15658);
    if (!x15675) break;
    int x15677 = 0;
    if (fscanf(x15658,"%d|",&x15677) == EOF) break;
    char* x15678 = (char*)malloc(26 * sizeof(char));
    int x15680 = 0;
    char x15679 = ' ';
    while (1) {
      fscanf(x15658,"%c",&x15679);
      if (x15679=='|' || x15679=='\n') break;
      if (x15680>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15680); break;}
      ((char*)x15678)[x15680] = x15679;
      x15680 += 1;
    }
    ((char*)x15678)[x15680] = '\0';
    char* x15683 = (char*)malloc(41 * sizeof(char));
    int x15685 = 0;
    char x15684 = ' ';
    while (1) {
      fscanf(x15658,"%c",&x15684);
      if (x15684=='|' || x15684=='\n') break;
      if (x15685>=40) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15685); break;}
      ((char*)x15683)[x15685] = x15684;
      x15685 += 1;
    }
    ((char*)x15683)[x15685] = '\0';
    int x15688 = 0;
    if (fscanf(x15658,"%d|",&x15688) == EOF) break;
    char* x15689 = (char*)malloc(16 * sizeof(char));
    int x15691 = 0;
    char x15690 = ' ';
    while (1) {
      fscanf(x15658,"%c",&x15690);
      if (x15690=='|' || x15690=='\n') break;
      if (x15691>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15691); break;}
      ((char*)x15689)[x15691] = x15690;
      x15691 += 1;
    }
    ((char*)x15689)[x15691] = '\0';
    double x15694 = 0.0;
    if (fscanf(x15658,"%lf|",&x15694) == EOF) break;
    char* x15695 = (char*)malloc(102 * sizeof(char));
    int x15697 = 0;
    char x15696 = ' ';
    while (1) {
      fscanf(x15658,"%c",&x15696);
      if (x15696=='|' || x15696=='\n') break;
      if (x15697>=101) { printf("ERROR: scanner.nextString reading past end of buffer %d",x15697); break;}
      ((char*)x15695)[x15697] = x15696;
      x15697 += 1;
    }
    ((char*)x15695)[x15697] = '\0';
    int x15700 = x15660;
    int x15701 = x15659;
    bool x15702 = x15700 == x15701;
    if (x15702) {
      int x15703 = x15701 * 4;
      x15659 = x15703;
      printf("buffer.resize %d\n",x15703);
      int* x15706 = x15662;
      int* x15707 = (int*)realloc(x15706,x15703 * sizeof(int));
      x15662 = x15707;
      int* x15715 = x15668;
      int* x15716 = (int*)realloc(x15715,x15703 * sizeof(int));
      x15668 = x15716;
    } else {
    }
    int* x15729 = x15662;
    x15729[x15700] = x15677;
    int* x15735 = x15668;
    x15735[x15700] = x15688;
    x15660 = x15660 + 1;
  }
  GTree* x15751 = g_tree_new((GCompareFunc)x17000);;
  bool x15752 = true == false;
  int x13762;
  for(x13762=0; x13762 < 1; x13762++) {
    bool x15753 = false;
    int x15754 = 0;
    bool x15755 = false;
    int x15756 = 0;
    int* x15759 = (int*)malloc(1073741824 * sizeof(int));
    int* x15760 = x15759;
    int x15777 = 0;
    int* x15778 = (int*)malloc(1048576 * sizeof(int));
    int* x15779 = (int*)malloc(1073741824 * sizeof(int));
    int x13790;
    for(x13790=0; x13790 < 1048576; x13790++) {
      x15778[x13790] = -1;
    }
    bool x15784 = false;
    int x15785 = 0;
    int* x15806 = (int*)malloc(1073741824 * sizeof(int));
    int* x15807 = x15806;
    int* x15810 = (int*)malloc(1073741824 * sizeof(int));
    int* x15811 = x15810;
    double* x15816 = (double*)malloc(1073741824 * sizeof(double));
    double* x15817 = x15816;
    double* x15818 = (double*)malloc(1073741824 * sizeof(double));
    double* x15819 = x15818;
    int x15838 = 0;
    int* x15839 = (int*)malloc(1048576 * sizeof(int));
    int* x15840 = (int*)malloc(1073741824 * sizeof(int));
    int x13852;
    for(x13852=0; x13852 < 1048576; x13852++) {
      x15839[x13852] = -1;
    }
    bool x15845 = false;
    int x15846 = 0;
    int* x15870 = (int*)malloc(1073741824 * sizeof(int));
    int* x15871 = x15870;
    double* x15876 = (double*)malloc(1073741824 * sizeof(double));
    double* x15877 = x15876;
    double* x15878 = (double*)malloc(1073741824 * sizeof(double));
    double* x15879 = x15878;
    int* x15900 = (int*)malloc(1073741824 * sizeof(int));
    int* x15901 = x15900;
    long* x15906 = (long*)malloc(1073741824 * sizeof(long));
    long* x15907 = x15906;
    int x15916 = 0;
    int* x15917 = (int*)malloc(1048576 * sizeof(int));
    int* x15918 = (int*)malloc(1073741824 * sizeof(int));
    int x13931;
    for(x13931=0; x13931 < 1048576; x13931++) {
      x15917[x13931] = -1;
    }
    bool x15923 = false;
    int x15924 = 0;
    int* x15926 = (int*)malloc(1073741824 * sizeof(int));
    int* x15927 = x15926;
    int* x15930 = (int*)malloc(1073741824 * sizeof(int));
    int* x15931 = x15930;
    int x15934 = 0;
    int* x15935 = (int*)malloc(1048576 * sizeof(int));
    int* x15936 = (int*)malloc(1073741824 * sizeof(int));
    int x13950;
    for(x13950=0; x13950 < 1048576; x13950++) {
      x15935[x13950] = -1;
    }
    bool x15941 = false;
    int x15942 = 0;
    int* x15945 = (int*)malloc(1073741824 * sizeof(int));
    int* x15946 = x15945;
    int x15951 = 0;
    int* x15952 = (int*)malloc(1048576 * sizeof(int));
    int* x15953 = (int*)malloc(1073741824 * sizeof(int));
    int x13968;
    for(x13968=0; x13968 < 1048576; x13968++) {
      x15952[x13968] = -1;
    }
    bool x15958 = false;
    int x15959 = 0;
    int* x15961 = (int*)malloc(1073741824 * sizeof(int));
    int* x15962 = x15961;
    int* x15967 = (int*)malloc(1073741824 * sizeof(int));
    int* x15968 = x15967;
    int x15975 = 0;
    int* x15976 = (int*)malloc(1048576 * sizeof(int));
    int* x15977 = (int*)malloc(1073741824 * sizeof(int));
    int x13993;
    for(x13993=0; x13993 < 1048576; x13993++) {
      x15976[x13993] = -1;
    }
    bool x15983 = false;
    int x15984 = 0;
    char** x15987 = (char**)malloc(1073741824 * sizeof(char*));
    char** x15988 = x15987;
    int* x15989 = (int*)malloc(1073741824 * sizeof(int));
    int* x15990 = x15989;
    int x15991 = 0;
    int* x15992 = (int*)malloc(1048576 * sizeof(int));
    int* x15993 = (int*)malloc(1073741824 * sizeof(int));
    int x14010;
    for(x14010=0; x14010 < 1048576; x14010++) {
      x15992[x14010] = -1;
    }
    int x15999 = 1048576;
    int x16000 = 0;
    int* x16001 = (int*)malloc(1048576 * sizeof(int));
    int* x16002 = x16001;
    double* x16003 = (double*)malloc(1048576 * sizeof(double));
    double* x16004 = x16003;
    double* x16005 = (double*)malloc(1048576 * sizeof(double));
    double* x16006 = x16005;
    int x16007 = 4194304;
    int x16008 = 0;
    int* x16009 = (int*)malloc(4194304 * sizeof(int));
    int* x16010 = x16009;
    int x14029;
    for(x14029=0; x14029 < 4194304; x14029++) {
      int* x16011 = x16010;
      x16011[x14029] = -1;
    }
    int x16020 = 0;
    struct timeval x15055, x15056, x16993;
    gettimeofday(&x15055, NULL);
    printf("(NATION X (SUPPLIER X (REGION X (NATION X (((PART X LINEITEM) X ORDERS) X CUSTOMER))))): leftParent.next start\n");
    struct timeval x14086, x14087, x16058;
    gettimeofday(&x14086, NULL);
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x16023 = x15983;
      bool x16024 = !x16023;
      bool x16029 = x16024;
      if (x16024) {
        int x16025 = x15984;
        int x16026 = x15069;
        bool x16027 = x16025 < x16026;
        x16029 = x16027;
      }
      bool x16030 = x16029;
      if (!x16030) break;
      int x16033 = x15984;
      int* x16034 = x15071;
      int x16035 = x16034[x16033];
      char** x16036 = x15073;
      char* x16037 = x16036[x16033];
      x15984 = x15984 + 1;
      int x16043 = x15991;
      char** x16044 = x15988;
      x16044[x16043] = x16037;
      int* x16046 = x15990;
      x16046[x16043] = x16035;
      x15991 = x15991 + 1;
      int x16049 = x16035 & 1048575;
      int x16050 = x15992[x16049];
      x15992[x16049] = x16043;
      x15993[x16043] = x16050;
    }
    printf("(NATION X (SUPPLIER X (REGION X (NATION X (((PART X LINEITEM) X ORDERS) X CUSTOMER))))): leftParent.next done\n");
    gettimeofday(&x14087, NULL);
    timeval_subtract(&x16058, &x14087, &x14086);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x16058.tv_sec * 1000) + (x16058.tv_usec/1000)));
    printf("(NATION X (SUPPLIER X (REGION X (NATION X (((PART X LINEITEM) X ORDERS) X CUSTOMER))))): rightParent.next start\n");
    struct timeval x15015, x15016, x16957;
    gettimeofday(&x15015, NULL);
    printf("(SUPPLIER X (REGION X (NATION X (((PART X LINEITEM) X ORDERS) X CUSTOMER)))): leftParent.next start\n");
    struct timeval x14143, x14144, x16114;
    gettimeofday(&x14143, NULL);
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x16063 = x15958;
      bool x16064 = !x16063;
      bool x16069 = x16064;
      if (x16064) {
        int x16065 = x15959;
        int x16066 = x15660;
        bool x16067 = x16065 < x16066;
        x16069 = x16067;
      }
      bool x16070 = x16069;
      if (!x16070) break;
      int x16073 = x15959;
      int* x16074 = x15662;
      int x16075 = x16074[x16073];
      int* x16080 = x15668;
      int x16081 = x16080[x16073];
      x15959 = x15959 + 1;
      int x16089 = x15975;
      int* x16090 = x15962;
      x16090[x16089] = x16075;
      int* x16096 = x15968;
      x16096[x16089] = x16081;
      x15975 = x15975 + 1;
      int x16105 = x16075 & 1048575;
      int x16106 = x15976[x16105];
      x15976[x16105] = x16089;
      x15977[x16089] = x16106;
    }
    printf("(SUPPLIER X (REGION X (NATION X (((PART X LINEITEM) X ORDERS) X CUSTOMER)))): leftParent.next done\n");
    gettimeofday(&x14144, NULL);
    timeval_subtract(&x16114, &x14144, &x14143);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x16114.tv_sec * 1000) + (x16114.tv_usec/1000)));
    printf("(SUPPLIER X (REGION X (NATION X (((PART X LINEITEM) X ORDERS) X CUSTOMER)))): rightParent.next start\n");
    struct timeval x15009, x15010, x16952;
    gettimeofday(&x15009, NULL);
    printf("(REGION X (NATION X (((PART X LINEITEM) X ORDERS) X CUSTOMER))): leftParent.next start\n");
    struct timeval x14187, x14188, x16158;
    gettimeofday(&x14187, NULL);
    printf("%s\n","begin scan REGION");
    for (;;) {
      bool x16119 = x15941;
      bool x16120 = !x16119;
      bool x16125 = x16120;
      if (x16120) {
        int x16121 = x15942;
        int x16122 = x15126;
        bool x16123 = x16121 < x16122;
        x16125 = x16123;
      }
      bool x16126 = x16125;
      if (!x16126) break;
      int x16129 = x15942;
      int* x16130 = x15128;
      int x16131 = x16130[x16129];
      char** x16132 = x15130;
      char* x16133 = x16132[x16129];
      x15942 = x15942 + 1;
      bool x16137 = strcmp(x16133,"ASIA") == 0;;
      if (x16137) {
        int x16138 = x15951;
        int* x16139 = x15946;
        x16139[x16138] = x16131;
        x15951 = x15951 + 1;
        int x16146 = x16131 & 1048575;
        int x16147 = x15952[x16146];
        x15952[x16146] = x16138;
        x15953[x16138] = x16147;
      } else {
      }
    }
    printf("(REGION X (NATION X (((PART X LINEITEM) X ORDERS) X CUSTOMER))): leftParent.next done\n");
    gettimeofday(&x14188, NULL);
    timeval_subtract(&x16158, &x14188, &x14187);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x16158.tv_sec * 1000) + (x16158.tv_usec/1000)));
    printf("(REGION X (NATION X (((PART X LINEITEM) X ORDERS) X CUSTOMER))): rightParent.next start\n");
    struct timeval x15003, x15004, x16947;
    gettimeofday(&x15003, NULL);
    printf("(NATION X (((PART X LINEITEM) X ORDERS) X CUSTOMER)): leftParent.next start\n");
    struct timeval x14232, x14233, x16202;
    gettimeofday(&x14232, NULL);
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x16163 = x15923;
      bool x16164 = !x16163;
      bool x16169 = x16164;
      if (x16164) {
        int x16165 = x15924;
        int x16166 = x15069;
        bool x16167 = x16165 < x16166;
        x16169 = x16167;
      }
      bool x16170 = x16169;
      if (!x16170) break;
      int x16173 = x15924;
      int* x16174 = x15071;
      int x16175 = x16174[x16173];
      int* x16178 = x15075;
      int x16179 = x16178[x16173];
      x15924 = x15924 + 1;
      int x16183 = x15934;
      int* x16184 = x15927;
      x16184[x16183] = x16175;
      int* x16188 = x15931;
      x16188[x16183] = x16179;
      x15934 = x15934 + 1;
      int x16193 = x16175 & 1048575;
      int x16194 = x15935[x16193];
      x15935[x16193] = x16183;
      x15936[x16183] = x16194;
    }
    printf("(NATION X (((PART X LINEITEM) X ORDERS) X CUSTOMER)): leftParent.next done\n");
    gettimeofday(&x14233, NULL);
    timeval_subtract(&x16202, &x14233, &x14232);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x16202.tv_sec * 1000) + (x16202.tv_usec/1000)));
    printf("(NATION X (((PART X LINEITEM) X ORDERS) X CUSTOMER)): rightParent.next start\n");
    struct timeval x14997, x14998, x16942;
    gettimeofday(&x14997, NULL);
    printf("(((PART X LINEITEM) X ORDERS) X CUSTOMER): leftParent.next start\n");
    struct timeval x14648, x14649, x16611;
    gettimeofday(&x14648, NULL);
    printf("((PART X LINEITEM) X ORDERS): leftParent.next start\n");
    struct timeval x14454, x14455, x16420;
    gettimeofday(&x14454, NULL);
    printf("(PART X LINEITEM): leftParent.next start\n");
    struct timeval x14302, x14303, x16272;
    gettimeofday(&x14302, NULL);
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x16209 = x15755;
      bool x16210 = !x16209;
      bool x16215 = x16210;
      if (x16210) {
        int x16211 = x15756;
        int x16212 = x15175;
        bool x16213 = x16211 < x16212;
        x16215 = x16213;
      }
      bool x16216 = x16215;
      if (!x16216) break;
      int x16219 = x15756;
      int* x16220 = x15177;
      int x16221 = x16220[x16219];
      char** x16228 = x15185;
      char* x16229 = x16228[x16219];
      x15756 = x15756 + 1;
      bool x16239 = strcmp(x16229,"MEDIUM ANODIZED NICKEL") == 0;;
      if (x16239) {
        int x16240 = x15777;
        int* x16241 = x15760;
        x16241[x16240] = x16221;
        x15777 = x15777 + 1;
        int x16260 = x16221 & 1048575;
        int x16261 = x15778[x16260];
        x15778[x16260] = x16240;
        x15779[x16240] = x16261;
      } else {
      }
    }
    printf("(PART X LINEITEM): leftParent.next done\n");
    gettimeofday(&x14303, NULL);
    timeval_subtract(&x16272, &x14303, &x14302);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x16272.tv_sec * 1000) + (x16272.tv_usec/1000)));
    printf("(PART X LINEITEM): rightParent.next start\n");
    struct timeval x14448, x14449, x16415;
    gettimeofday(&x14448, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x16276 = x15753;
      bool x16277 = !x16276;
      bool x16282 = x16277;
      if (x16277) {
        int x16278 = x15754;
        int x16279 = x15393;
        bool x16280 = x16278 < x16279;
        x16282 = x16280;
      }
      bool x16283 = x16282;
      if (!x16283) break;
      int x16286 = x15754;
      int* x16287 = x15395;
      int x16288 = x16287[x16286];
      int* x16289 = x15397;
      int x16290 = x16289[x16286];
      int* x16291 = x15399;
      int x16292 = x16291[x16286];
      double* x16297 = x15405;
      double x16298 = x16297[x16286];
      double* x16299 = x15407;
      double x16300 = x16299[x16286];
      x15754 = x15754 + 1;
      int x16320 = x16290 & 1048575;
      int x16321 = x15778[x16320];
      int x16322 = x16321;
      int x16323 = x16288 & 1048575;
      for (;;) {
        int x16324 = x16322;
        bool x16325 = x16324 != -1;
        if (!x16325) break;
        int x16327 = x16322;
        int* x16328 = x15760;
        int x16329 = x16328[x16327];
        int x16346 = x15779[x16327];
        x16322 = x16346;
        bool x16348 = x16329 == x16290;
        if (x16348) {
          int x16349 = x15838;
          int* x16368 = x15807;
          x16368[x16349] = x16288;
          int* x16372 = x15811;
          x16372[x16349] = x16292;
          double* x16378 = x15817;
          x16378[x16349] = x16298;
          double* x16380 = x15819;
          x16380[x16349] = x16300;
          x15838 = x15838 + 1;
          int x16401 = x15839[x16323];
          x15839[x16323] = x16349;
          x15840[x16349] = x16401;
        } else {
        }
      }
    }
    printf("(PART X LINEITEM): rightParent.next done\n");
    gettimeofday(&x14449, NULL);
    timeval_subtract(&x16415, &x14449, &x14448);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x16415.tv_sec * 1000) + (x16415.tv_usec/1000)));
    printf("((PART X LINEITEM) X ORDERS): leftParent.next done\n");
    gettimeofday(&x14455, NULL);
    timeval_subtract(&x16420, &x14455, &x14454);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x16420.tv_sec * 1000) + (x16420.tv_usec/1000)));
    printf("((PART X LINEITEM) X ORDERS): rightParent.next start\n");
    struct timeval x14642, x14643, x16606;
    gettimeofday(&x14642, NULL);
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x16424 = x15784;
      bool x16425 = !x16424;
      bool x16430 = x16425;
      if (x16425) {
        int x16426 = x15785;
        int x16427 = x15289;
        bool x16428 = x16426 < x16427;
        x16430 = x16428;
      }
      bool x16431 = x16430;
      if (!x16431) break;
      int x16434 = x15785;
      int* x16435 = x15291;
      int x16436 = x16435[x16434];
      int* x16437 = x15293;
      int x16438 = x16437[x16434];
      long* x16443 = x15299;
      long x16444 = x16443[x16434];
      x15785 = x15785 + 1;
      bool x16454 = x16444 >= 19950101L;
      bool x16456 = x16454;
      if (x16454) {
        bool x16455 = x16444 <= 19961231L;
        x16456 = x16455;
      }
      bool x16457 = x16456;
      if (x16457) {
        int x16458 = x16436 & 1048575;
        int x16459 = x15839[x16458];
        int x16460 = x16459;
        int x16461 = x16438 & 1048575;
        for (;;) {
          int x16462 = x16460;
          bool x16463 = x16462 != -1;
          if (!x16463) break;
          int x16465 = x16460;
          int* x16484 = x15807;
          int x16485 = x16484[x16465];
          int* x16488 = x15811;
          int x16489 = x16488[x16465];
          double* x16494 = x15817;
          double x16495 = x16494[x16465];
          double* x16496 = x15819;
          double x16497 = x16496[x16465];
          int x16516 = x15840[x16465];
          x16460 = x16516;
          bool x16518 = x16485 == x16436;
          if (x16518) {
            int x16519 = x15916;
            int* x16542 = x15871;
            x16542[x16519] = x16489;
            double* x16548 = x15877;
            x16548[x16519] = x16495;
            double* x16550 = x15879;
            x16550[x16519] = x16497;
            int* x16572 = x15901;
            x16572[x16519] = x16438;
            long* x16578 = x15907;
            x16578[x16519] = x16444;
            x15916 = x15916 + 1;
            int x16589 = x15917[x16461];
            x15917[x16461] = x16519;
            x15918[x16519] = x16589;
          } else {
          }
        }
      } else {
      }
    }
    printf("((PART X LINEITEM) X ORDERS): rightParent.next done\n");
    gettimeofday(&x14643, NULL);
    timeval_subtract(&x16606, &x14643, &x14642);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x16606.tv_sec * 1000) + (x16606.tv_usec/1000)));
    printf("(((PART X LINEITEM) X ORDERS) X CUSTOMER): leftParent.next done\n");
    gettimeofday(&x14649, NULL);
    timeval_subtract(&x16611, &x14649, &x14648);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x16611.tv_sec * 1000) + (x16611.tv_usec/1000)));
    printf("(((PART X LINEITEM) X ORDERS) X CUSTOMER): rightParent.next start\n");
    struct timeval x14991, x14992, x16937;
    gettimeofday(&x14991, NULL);
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x16615 = x15845;
      bool x16616 = !x16615;
      bool x16621 = x16616;
      if (x16616) {
        int x16617 = x15846;
        int x16618 = x15559;
        bool x16619 = x16617 < x16618;
        x16621 = x16619;
      }
      bool x16622 = x16621;
      if (!x16622) break;
      int x16625 = x15846;
      int* x16626 = x15561;
      int x16627 = x16626[x16625];
      int* x16632 = x15567;
      int x16633 = x16632[x16625];
      x15846 = x15846 + 1;
      int x16643 = x16627 & 1048575;
      int x16644 = x15917[x16643];
      int x16645 = x16644;
      int x16646 = x16633 & 1048575;
      for (;;) {
        int x16647 = x16645;
        bool x16648 = x16647 != -1;
        if (!x16648) break;
        int x16650 = x16645;
        int* x16673 = x15871;
        int x16674 = x16673[x16650];
        double* x16679 = x15877;
        double x16680 = x16679[x16650];
        double* x16681 = x15879;
        double x16682 = x16681[x16650];
        int* x16703 = x15901;
        int x16704 = x16703[x16650];
        long* x16709 = x15907;
        long x16710 = x16709[x16650];
        int x16719 = x15918[x16650];
        x16645 = x16719;
        bool x16721 = x16704 == x16627;
        if (x16721) {
          int x16722 = x15935[x16646];
          int x16723 = x16722;
          int x16724 = x16674 & 1048575;
          long x16725 = x16710/10000;
          int x16726 = (int)x16725;
          int x16727 = x16726 * 2;
          int x16728 = x16727 * 3;
          double x16729 = 1.0 - x16682;
          double x16730 = x16680 * x16729;
          for (;;) {
            int x16731 = x16723;
            bool x16732 = x16731 != -1;
            if (!x16732) break;
            int x16734 = x16723;
            int* x16735 = x15927;
            int x16736 = x16735[x16734];
            int* x16739 = x15931;
            int x16740 = x16739[x16734];
            int x16743 = x15936[x16734];
            x16723 = x16743;
            bool x16745 = x16736 == x16633;
            if (x16745) {
              int x16746 = x16740 & 1048575;
              int x16747 = x15952[x16746];
              int x16748 = x16747;
              for (;;) {
                int x16749 = x16748;
                bool x16750 = x16749 != -1;
                if (!x16750) break;
                int x16752 = x16748;
                int* x16753 = x15946;
                int x16754 = x16753[x16752];
                int x16759 = x15953[x16752];
                x16748 = x16759;
                bool x16761 = x16754 == x16740;
                if (x16761) {
                  int x16762 = x15976[x16724];
                  int x16763 = x16762;
                  for (;;) {
                    int x16764 = x16763;
                    bool x16765 = x16764 != -1;
                    if (!x16765) break;
                    int x16767 = x16763;
                    int* x16768 = x15962;
                    int x16769 = x16768[x16767];
                    int* x16774 = x15968;
                    int x16775 = x16774[x16767];
                    int x16782 = x15977[x16767];
                    x16763 = x16782;
                    bool x16784 = x16769 == x16674;
                    if (x16784) {
                      int x16785 = x16775 & 1048575;
                      int x16786 = x15992[x16785];
                      int x16787 = x16786;
                      for (;;) {
                        int x16788 = x16787;
                        bool x16789 = x16788 != -1;
                        if (!x16789) break;
                        int x16791 = x16787;
                        char** x16792 = x15988;
                        char* x16793 = x16792[x16791];
                        int* x16794 = x15990;
                        int x16795 = x16794[x16791];
                        int x16796 = x15993[x16791];
                        x16787 = x16796;
                        bool x16798 = x16795 == x16775;
                        if (x16798) {
                          int x16800 = x16007;
                          int x16801 = x16800 - 1;
                          int x16802 = x16728 & x16801;
                          int x16803 = x16802;
                          int* x16804 = x16010;
                          int x16805 = x16804[x16802];
                          int x16806 = x16805;
                          int x16807 = x16802 + 1;
                          int x16808 = x16804[x16807];
                          int x16809 = x16808;
                          for (;;) {
                            int x16810 = x16806;
                            bool x16811 = x16810 != -1;
                            bool x16829 = x16811;
                            if (x16811) {
                              int x16812 = x16809;
                              bool x16813 = x16812 != x16728;
                              bool x16825 = x16813;
                              if (x16813 == false) {
                                int x16814 = x16806;
                                int* x16815 = x16002;
                                int x16816 = x16815[x16814];
                                bool x16821 = x16816 == x16726;
                                bool x16822 = !x16821;
                                x16825 = x16822;
                              }
                              bool x16826 = x16825;
                              x16829 = x16826;
                            }
                            bool x16830 = x16829;
                            if (!x16830) break;
                            int x16833 = x16803;
                            int x16834 = x16833 + 2;
                            int x16835 = x16834 & x16801;
                            x16803 = x16835;
                            int* x16837 = x16010;
                            int x16838 = x16837[x16835];
                            x16806 = x16838;
                            int x16840 = x16835 + 1;
                            int x16841 = x16837[x16840];
                            x16809 = x16841;
                          }
                          int x16846 = x16806;
                          bool x16847 = x16846 == -1;
                          int x16887;
                          if (x16847) {
                            int x16848 = x16008;
                            int x16849 = x16803;
                            x16804[x16849] = x16848;
                            int x16851 = x16849 + 1;
                            x16804[x16851] = x16728;
                            x16008 = x16008 + 1;
                            int x16854 = x16000;
                            int x16855 = x15999;
                            bool x16856 = x16854 == x16855;
                            if (x16856) {
                              int x16857 = x16855 * 4;
                              x15999 = x16857;
                              printf("buffer.resize %d\n",x16857);
                              int* x16860 = x16002;
                              int* x16861 = (int*)realloc(x16860,x16857 * sizeof(int));
                              x16002 = x16861;
                              printf("buffer.resize %d\n",x16857);
                              double* x16864 = x16004;
                              double* x16865 = (double*)realloc(x16864,x16857 * sizeof(double));
                              x16004 = x16865;
                              double* x16867 = x16006;
                              double* x16868 = (double*)realloc(x16867,x16857 * sizeof(double));
                              x16006 = x16868;
                            } else {
                            }
                            int* x16872 = x16002;
                            x16872[x16854] = x16726;
                            double* x16874 = x16004;
                            x16874[x16854] = 0.0;
                            double* x16876 = x16006;
                            x16876[x16854] = 0.0;
                            x16000 = x16000 + 1;
                            int x16879 = x16008;
                            int x16880 = x16879 * 4;
                            bool x16881 = x16880 > x16800;
                            if (x16881) {
                              printf("%s\n","ERROR: hash.resize not implemented");
                            } else {
                            }
                            x16887 = x16848;
                          } else {
                            x16887 = x16846;
                          }
                          int* x16888 = x16002;
                          int x16889 = x16888[x16887];
                          double* x16890 = x16004;
                          double x16891 = x16890[x16887];
                          double* x16892 = x16006;
                          double x16893 = x16892[x16887];
                          x16888[x16887] = x16889;
                          double x16895 = x16891 + x16730;
                          x16890[x16887] = x16895;
                          bool x16897 = strcmp(x16793,"INDONESIA") == 0;;
                          double x16899;
                          if (x16897) {
                            double x16898 = x16893 + x16730;
                            x16899 = x16898;
                          } else {
                            x16899 = x16893;
                          }
                          x16892[x16887] = x16899;
                        } else {
                        }
                      }
                    } else {
                    }
                  }
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
    printf("(((PART X LINEITEM) X ORDERS) X CUSTOMER): rightParent.next done\n");
    gettimeofday(&x14992, NULL);
    timeval_subtract(&x16937, &x14992, &x14991);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x16937.tv_sec * 1000) + (x16937.tv_usec/1000)));
    printf("(NATION X (((PART X LINEITEM) X ORDERS) X CUSTOMER)): rightParent.next done\n");
    gettimeofday(&x14998, NULL);
    timeval_subtract(&x16942, &x14998, &x14997);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x16942.tv_sec * 1000) + (x16942.tv_usec/1000)));
    printf("(REGION X (NATION X (((PART X LINEITEM) X ORDERS) X CUSTOMER))): rightParent.next done\n");
    gettimeofday(&x15004, NULL);
    timeval_subtract(&x16947, &x15004, &x15003);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x16947.tv_sec * 1000) + (x16947.tv_usec/1000)));
    printf("(SUPPLIER X (REGION X (NATION X (((PART X LINEITEM) X ORDERS) X CUSTOMER)))): rightParent.next done\n");
    gettimeofday(&x15010, NULL);
    timeval_subtract(&x16952, &x15010, &x15009);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x16952.tv_sec * 1000) + (x16952.tv_usec/1000)));
    printf("(NATION X (SUPPLIER X (REGION X (NATION X (((PART X LINEITEM) X ORDERS) X CUSTOMER))))): rightParent.next done\n");
    gettimeofday(&x15016, NULL);
    timeval_subtract(&x16957, &x15016, &x15015);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x16957.tv_sec * 1000) + (x16957.tv_usec/1000)));
    int x16959 = x16000;
    int x15021;
    for(x15021=0; x15021 < x16959; x15021++) {
      int* x16960 = x16002;
      int x16961 = x16960[x15021];
      double* x16962 = x16004;
      double x16963 = x16962[x15021];
      double* x16964 = x16006;
      double x16965 = x16964[x15021];
      double x16966 = x16965 / x16963;
      struct Anon2052879268* x16967 = (struct Anon2052879268*)malloc(sizeof(struct Anon2052879268));
      x16967->_2 = x16966;
      struct Anon1987966504* x16968 = (struct Anon1987966504*)malloc(sizeof(struct Anon1987966504));
      x16968->key = x16961;
      x16968->aggs = x16967;
      g_tree_insert(x15751,x16968,x16968);; // x16969
    }
    for (;;) {
      int x16972 = g_tree_nnodes(x15751);
      bool x16973 = x16972 != 0;
      if (!x16973) break;
      struct Anon1987966504* x16975 = NULL;
      g_tree_foreach(x15751, (GTraverseFunc)x17006, &x16975);
      g_tree_remove(x15751,x16975);
      if (x15752) {
      } else {
        int x16979 = x16975->key;;
        struct Anon2052879268* x16980 = x16975->aggs;;
        double x16981 = x16980->_2;;
        printf("%d|%.5f\n",x16979,x16981);
        x16020 = x16020 + 1;
      }
    }
    int x16989 = x16020;
    printf("(%d rows)\n",x16989);
    gettimeofday(&x15056, NULL);
    timeval_subtract(&x16993, &x15056, &x15055);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x16993.tv_sec * 1000) + (x16993.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
