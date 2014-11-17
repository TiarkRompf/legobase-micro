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

      #include <sys/mman.h>
      #include <sys/stat.h>
      #ifndef MAP_FILE
      #define MAP_FILE MAP_SHARED
      #endif
      int fsize(int fd) {
        struct stat stat;
        int res = fstat(fd,&stat);
        return stat.st_size;
      }
      int printll(char* s) {
        while (*s != '\n' && *s != ',' && *s != '\t') {
          putchar(*s++);
        }
        return 0;
      }
      long hash(char *str0, int len)
      {
        unsigned char* str = (unsigned char*)str0;
        unsigned long hash = 5381;
        int c;

        while ((c = *str++) && len--)
          hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
      }
      size_t strlen(const char* str) {
        const char* start = str;
        while (*str != '\n' && (*str != '|') && (*str != '\0')) str++;
        return str - start;
      }
      int strcmp(const char *s1, const char *s2) {
        size_t l1 = strlen(s1);
        size_t l2 = strlen(s2);
        if (l1 != l2) return l2 - l1;
        return strncmp(s1,s2,l1);
      }
      char* strstr(const char *s1, const char *s2) {
        return strnstr(s1,s2,strlen(s1));
      }
      

struct Anon603726677 {
bool exists;
char* key;
double aggs;
};

struct Anon1406772883 {
int N_NATIONKEY;
char* N_NAME;
int N_REGIONKEY;
char* N_COMMENT;
};

struct Anon567626277 {
double _0;
double _1;
double _2;
double _3;
double _4;
double _5;
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

struct Anon850505655Anon1251919804 {
char* REC1_N_NAME;
int REC1_N_NATIONKEY;
long REC2_O_ORDERDATE;
double REC2_L_DISCOUNT;
double REC2_L_EXTENDEDPRICE;
int REC2_S_NATIONKEY;
};

struct Anon2052879266 {
double _0;
};

struct Anon2092052448Anon811555534Anon920667905 {
bool exists;
int key;
struct Anon2052879266 aggs;
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

struct Anon1866483359 {
int R_REGIONKEY;
char* R_NAME;
char* R_COMMENT;
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

struct Anon2053173900 {
int key;
double wnd;
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

struct Anon147418070 {
char* N_NAME;
int N_NATIONKEY;
int C_CUSTKEY;
};

struct Anon726278688 {
char* SUPP_NATION;
char* CUST_NATION;
int L_YEAR;
};

struct Anon1594456343 {
bool exists;
struct Anon726278688 key;
struct Anon2052879266 aggs;
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

struct Anon713865179 {
int N1_N_NATIONKEY;
char* N1_N_NAME;
int N1_N_REGIONKEY;
char* N1_N_COMMENT;
};

struct Anon546410247 {
char* N_NAME;
int N_NATIONKEY;
int O_ORDERKEY;
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

struct Anon150112254 {
bool exists;
double key;
struct Anon2052879266 aggs;
};

struct Anon1078540535 {
char* N_NAME;
int N_NATIONKEY;
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

struct Anon1993309635 {
int PS_PARTKEY;
int PS_SUPPKEY;
double PS_AVAILQTY;
};

struct Anon745367039Anon1268892766 {
bool exists;
struct Anon1993309635 key;
double aggs;
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
};

struct Anon0 {
struct Anon1406772883 left;
struct Anon745367039Anon1268892766 right;
};

struct Anon1406772883Anon745367039Anon1268892766 {
int N_NATIONKEY;
char* N_NAME;
int N_REGIONKEY;
char* N_COMMENT;
bool exists;
struct Anon1993309635 key;
double aggs;
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
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

struct Anon787349517 {
bool exists;
int key;
struct Anon1023322325 aggs;
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

struct Anon1268892766Anon1652045692 {
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
int key;
struct Anon2052879266 aggs;
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

struct Anon1621811895 {
char* C_NAME;
int C_CUSTKEY;
int O_ORDERKEY;
long O_ORDERDATE;
double O_TOTALPRICE;
};

struct Anon1652045692 {
int key;
struct Anon2052879266 aggs;
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

struct Anon1280496914 {
bool exists;
int key;
struct Anon2052879266 aggs;
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

struct Anon1007729034 {
bool exists;
char* key;
struct Anon2052879266 aggs;
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

struct Anon668992598 {
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
};

struct Anon2092052448Anon811555534 {
bool exists;
int key;
struct Anon2052879266 aggs;
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

struct Anon884569349 {
bool exists;
struct Anon1465150758 key;
struct Anon2052879266 aggs;
};

struct Anon2092052448 {
bool exists;
int key;
struct Anon2052879266 aggs;
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

struct Anon984006423 {
bool exists;
char* key;
struct Anon189208763 aggs;
};

struct Anon1230230422 {
int key;
struct Anon1023322325 wnd;
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

struct Anon133694426 {
bool exists;
struct Anon1711779607 key;
struct Anon2052879266 aggs;
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

struct Anon1978526630 {
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
GHashTable * PS_SUPPKEY;
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

struct Anon211179391 {
bool exists;
int key;
struct Anon189208763 aggs;
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

struct Anon745367039 {
bool exists;
struct Anon1993309635 key;
double aggs;
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

struct Anon625264174 {
char L_RETURNFLAG;
char L_LINESTATUS;
};

struct Anon1272074242 {
bool exists;
struct Anon625264174 key;
struct Anon567626277 aggs;
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

struct Anon1054882261 {
bool exists;
struct Anon668992598 key;
struct Anon2052879266 aggs;
};

struct Anon2052879268 {
double _2;
};

struct Anon1941857026 {
int key;
struct Anon2052879268 aggs;
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

struct Anon1124044545 {
struct Anon625264174 key;
struct Anon1296044246 aggs;
};

struct Anon800615186 {
bool exists;
struct Anon1621811895 key;
struct Anon2052879266 aggs;
};

struct Anon1251919804 {
long REC2_O_ORDERDATE;
double REC2_L_DISCOUNT;
double REC2_L_EXTENDEDPRICE;
int REC2_S_NATIONKEY;
};

struct Anon1395358962 {
int PS_PARTKEY;
int PS_SUPPKEY;
int PS_AVAILQTY;
double PS_SUPPLYCOST;
char* PS_COMMENT;
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

struct Anon2071559637 {
bool exists;
struct Anon1548200872 key;
struct Anon2052879266 aggs;
};

struct Anon1315812515 {
bool exists;
struct Anon1978526630 key;
struct Anon2052879266 aggs;
};

/************************ FUNCTIONS **************************/

/************************ MAIN BODY **************************/
int main(int x33295, char** x33296) {
  int x33297 = 0;
  int x33298 = 1048576;
  int x33299 = 0;
  int* x33300 = (int*)malloc(1048576 * sizeof(int));
  int* x33301 = x33300;
  char** x33302 = (char**)malloc(1048576 * sizeof(char*));
  char** x33303 = x33302;
  int x995 = open("../databases/sf2/part.tbl",0);
  int x996 = fsize(x995);
  char* x997 = mmap(0, x996, PROT_READ, MAP_FILE | MAP_SHARED, x995, 0);
  for (;;) {
    int x33319 = x33297;
    bool x33320 = x33319 < x996;
    if (!x33320) break;
    int x33323 = 0;
    for (;;) {
      int x33324 = x33297;
      char x33325 = x997[x33324];
      bool x33326 = x33325 != '|';
      bool x33331 = x33326;
      if (x33326) {
        int x33327 = x33297;
        char x33328 = x997[x33327];
        bool x33329 = x33328 != '\n';
        x33331 = x33329;
      }
      bool x33332 = x33331;
      if (!x33332) break;
      int x33334 = x33323;
      int x33336 = x33297;
      int x33335 = x33334 * 10;
      char x33337 = x997[x33336];
      char x33338 = x33337 - '0';
      int x33339 = x33335 + x33338;
      x33323 = x33339;
      x33297 = x33297 + 1;
    }
    x33297 = x33297 + 1;
    int x33345 = x33323;
    int x33346 = x33297;
    for (;;) {
      int x33347 = x33297;
      char x33348 = x997[x33347];
      bool x33349 = x33348 != '|';
      bool x33354 = x33349;
      if (x33349) {
        int x33350 = x33297;
        char x33351 = x997[x33350];
        bool x33352 = x33351 != '\n';
        x33354 = x33352;
      }
      bool x33355 = x33354;
      if (!x33355) break;
      x33297 = x33297 + 1;
    }
    x33297 = x33297 + 1;
    for (;;) {
      int x33365 = x33297;
      char x33366 = x997[x33365];
      bool x33367 = x33366 != '|';
      bool x33372 = x33367;
      if (x33367) {
        int x33368 = x33297;
        char x33369 = x997[x33368];
        bool x33370 = x33369 != '\n';
        x33372 = x33370;
      }
      bool x33373 = x33372;
      if (!x33373) break;
      x33297 = x33297 + 1;
    }
    x33297 = x33297 + 1;
    for (;;) {
      int x33383 = x33297;
      char x33384 = x997[x33383];
      bool x33385 = x33384 != '|';
      bool x33390 = x33385;
      if (x33385) {
        int x33386 = x33297;
        char x33387 = x997[x33386];
        bool x33388 = x33387 != '\n';
        x33390 = x33388;
      }
      bool x33391 = x33390;
      if (!x33391) break;
      x33297 = x33297 + 1;
    }
    x33297 = x33297 + 1;
    for (;;) {
      int x33401 = x33297;
      char x33402 = x997[x33401];
      bool x33403 = x33402 != '|';
      bool x33408 = x33403;
      if (x33403) {
        int x33404 = x33297;
        char x33405 = x997[x33404];
        bool x33406 = x33405 != '\n';
        x33408 = x33406;
      }
      bool x33409 = x33408;
      if (!x33409) break;
      x33297 = x33297 + 1;
    }
    x33297 = x33297 + 1;
    for (;;) {
      int x33420 = x33297;
      char x33421 = x997[x33420];
      bool x33422 = x33421 != '|';
      bool x33427 = x33422;
      if (x33422) {
        int x33423 = x33297;
        char x33424 = x997[x33423];
        bool x33425 = x33424 != '\n';
        x33427 = x33425;
      }
      bool x33428 = x33427;
      if (!x33428) break;
      x33297 = x33297 + 1;
    }
    x33297 = x33297 + 1;
    for (;;) {
      int x33443 = x33297;
      char x33444 = x997[x33443];
      bool x33445 = x33444 != '|';
      bool x33450 = x33445;
      if (x33445) {
        int x33446 = x33297;
        char x33447 = x997[x33446];
        bool x33448 = x33447 != '\n';
        x33450 = x33448;
      }
      bool x33451 = x33450;
      if (!x33451) break;
      x33297 = x33297 + 1;
    }
    x33297 = x33297 + 1;
    for (;;) {
      int x33463 = x33297;
      char x33464 = x997[x33463];
      bool x33465 = x33464 != '.';
      bool x33470 = x33465;
      if (x33465) {
        int x33466 = x33297;
        char x33467 = x997[x33466];
        bool x33468 = x33467 != '|';
        x33470 = x33468;
      }
      bool x33471 = x33470;
      bool x33476 = x33471;
      if (x33471) {
        int x33472 = x33297;
        char x33473 = x997[x33472];
        bool x33474 = x33473 != '\n';
        x33476 = x33474;
      }
      bool x33477 = x33476;
      if (!x33477) break;
      x33297 = x33297 + 1;
    }
    int x33489 = x33297;
    char x33490 = x997[x33489];
    bool x33491 = x33490 == '.';
    if (x33491) {
      x33297 = x33297 + 1;
      for (;;) {
        int x33493 = x33297;
        char x33494 = x997[x33493];
        bool x33495 = x33494 != '|';
        bool x33500 = x33495;
        if (x33495) {
          int x33496 = x33297;
          char x33497 = x997[x33496];
          bool x33498 = x33497 != '\n';
          x33500 = x33498;
        }
        bool x33501 = x33500;
        if (!x33501) break;
        x33297 = x33297 + 1;
      }
    } else {
    }
    x33297 = x33297 + 1;
    for (;;) {
      int x33526 = x33297;
      char x33527 = x997[x33526];
      bool x33528 = x33527 != '|';
      bool x33533 = x33528;
      if (x33528) {
        int x33529 = x33297;
        char x33530 = x997[x33529];
        bool x33531 = x33530 != '\n';
        x33533 = x33531;
      }
      bool x33534 = x33533;
      if (!x33534) break;
      x33297 = x33297 + 1;
    }
    x33297 = x33297 + 1;
    int x33544 = x33299;
    int x33545 = x33298;
    bool x33546 = x33544 == x33545;
    if (x33546) {
      int x33547 = x33545 * 4;
      x33298 = x33547;
      printf("buffer.resize %d\n",x33547);
      int* x33550 = x33301;
      int* x33551 = (int*)realloc(x33550,x33547 * sizeof(int));
      x33301 = x33551;
      char** x33553 = x33303;
      char** x33554 = (char**)realloc(x33553,x33547 * sizeof(char*));
      x33303 = x33554;
    } else {
    }
    int* x33579 = x33301;
    x33579[x33544] = x33345;
    char** x33581 = x33303;
    char* x33363 = x997+x33346;
    x33581[x33544] = x33363;
    x33299 = x33299 + 1;
  }
  int x33600 = 0;
  int x33601 = 1048576;
  int x33602 = 0;
  int* x33603 = (int*)malloc(1048576 * sizeof(int));
  int* x33604 = x33603;
  char** x33605 = (char**)malloc(1048576 * sizeof(char*));
  char** x33606 = x33605;
  int x1512 = open("../databases/sf2/nation.tbl",0);
  int x1513 = fsize(x1512);
  char* x1514 = mmap(0, x1513, PROT_READ, MAP_FILE | MAP_SHARED, x1512, 0);
  for (;;) {
    int x33611 = x33600;
    bool x33612 = x33611 < x1513;
    if (!x33612) break;
    int x33615 = 0;
    for (;;) {
      int x33616 = x33600;
      char x33617 = x1514[x33616];
      bool x33618 = x33617 != '|';
      bool x33623 = x33618;
      if (x33618) {
        int x33619 = x33600;
        char x33620 = x1514[x33619];
        bool x33621 = x33620 != '\n';
        x33623 = x33621;
      }
      bool x33624 = x33623;
      if (!x33624) break;
      int x33626 = x33615;
      int x33628 = x33600;
      int x33627 = x33626 * 10;
      char x33629 = x1514[x33628];
      char x33630 = x33629 - '0';
      int x33631 = x33627 + x33630;
      x33615 = x33631;
      x33600 = x33600 + 1;
    }
    x33600 = x33600 + 1;
    int x33637 = x33615;
    int x33638 = x33600;
    for (;;) {
      int x33639 = x33600;
      char x33640 = x1514[x33639];
      bool x33641 = x33640 != '|';
      bool x33646 = x33641;
      if (x33641) {
        int x33642 = x33600;
        char x33643 = x1514[x33642];
        bool x33644 = x33643 != '\n';
        x33646 = x33644;
      }
      bool x33647 = x33646;
      if (!x33647) break;
      x33600 = x33600 + 1;
    }
    x33600 = x33600 + 1;
    for (;;) {
      int x33658 = x33600;
      char x33659 = x1514[x33658];
      bool x33660 = x33659 != '|';
      bool x33665 = x33660;
      if (x33660) {
        int x33661 = x33600;
        char x33662 = x1514[x33661];
        bool x33663 = x33662 != '\n';
        x33665 = x33663;
      }
      bool x33666 = x33665;
      if (!x33666) break;
      x33600 = x33600 + 1;
    }
    x33600 = x33600 + 1;
    for (;;) {
      int x33681 = x33600;
      char x33682 = x1514[x33681];
      bool x33683 = x33682 != '|';
      bool x33688 = x33683;
      if (x33683) {
        int x33684 = x33600;
        char x33685 = x1514[x33684];
        bool x33686 = x33685 != '\n';
        x33688 = x33686;
      }
      bool x33689 = x33688;
      if (!x33689) break;
      x33600 = x33600 + 1;
    }
    x33600 = x33600 + 1;
    int x33699 = x33602;
    int x33700 = x33601;
    bool x33701 = x33699 == x33700;
    if (x33701) {
      int x33702 = x33700 * 4;
      x33601 = x33702;
      printf("buffer.resize %d\n",x33702);
      int* x33705 = x33604;
      int* x33706 = (int*)realloc(x33705,x33702 * sizeof(int));
      x33604 = x33706;
      char** x33708 = x33606;
      char** x33709 = (char**)realloc(x33708,x33702 * sizeof(char*));
      x33606 = x33709;
    } else {
    }
    int* x33719 = x33604;
    x33719[x33699] = x33637;
    char** x33721 = x33606;
    char* x33655 = x1514+x33638;
    x33721[x33699] = x33655;
    x33602 = x33602 + 1;
  }
  int x33730 = 0;
  int x33731 = 1048576;
  int x33732 = 0;
  int* x33733 = (int*)malloc(1048576 * sizeof(int));
  int* x33734 = x33733;
  char** x33735 = (char**)malloc(1048576 * sizeof(char*));
  char** x33736 = x33735;
  char** x33737 = (char**)malloc(1048576 * sizeof(char*));
  char** x33738 = x33737;
  int* x33739 = (int*)malloc(1048576 * sizeof(int));
  int* x33740 = x33739;
  int x1747 = open("../databases/sf2/supplier.tbl",0);
  int x1748 = fsize(x1747);
  char* x1749 = mmap(0, x1748, PROT_READ, MAP_FILE | MAP_SHARED, x1747, 0);
  for (;;) {
    int x33747 = x33730;
    bool x33748 = x33747 < x1748;
    if (!x33748) break;
    int x33751 = 0;
    for (;;) {
      int x33752 = x33730;
      char x33753 = x1749[x33752];
      bool x33754 = x33753 != '|';
      bool x33759 = x33754;
      if (x33754) {
        int x33755 = x33730;
        char x33756 = x1749[x33755];
        bool x33757 = x33756 != '\n';
        x33759 = x33757;
      }
      bool x33760 = x33759;
      if (!x33760) break;
      int x33762 = x33751;
      int x33764 = x33730;
      int x33763 = x33762 * 10;
      char x33765 = x1749[x33764];
      char x33766 = x33765 - '0';
      int x33767 = x33763 + x33766;
      x33751 = x33767;
      x33730 = x33730 + 1;
    }
    x33730 = x33730 + 1;
    int x33773 = x33751;
    int x33774 = x33730;
    for (;;) {
      int x33775 = x33730;
      char x33776 = x1749[x33775];
      bool x33777 = x33776 != '|';
      bool x33782 = x33777;
      if (x33777) {
        int x33778 = x33730;
        char x33779 = x1749[x33778];
        bool x33780 = x33779 != '\n';
        x33782 = x33780;
      }
      bool x33783 = x33782;
      if (!x33783) break;
      x33730 = x33730 + 1;
    }
    x33730 = x33730 + 1;
    int x33792 = x33730;
    for (;;) {
      int x33793 = x33730;
      char x33794 = x1749[x33793];
      bool x33795 = x33794 != '|';
      bool x33800 = x33795;
      if (x33795) {
        int x33796 = x33730;
        char x33797 = x1749[x33796];
        bool x33798 = x33797 != '\n';
        x33800 = x33798;
      }
      bool x33801 = x33800;
      if (!x33801) break;
      x33730 = x33730 + 1;
    }
    x33730 = x33730 + 1;
    int x33811 = 0;
    for (;;) {
      int x33812 = x33730;
      char x33813 = x1749[x33812];
      bool x33814 = x33813 != '|';
      bool x33819 = x33814;
      if (x33814) {
        int x33815 = x33730;
        char x33816 = x1749[x33815];
        bool x33817 = x33816 != '\n';
        x33819 = x33817;
      }
      bool x33820 = x33819;
      if (!x33820) break;
      int x33822 = x33811;
      int x33824 = x33730;
      int x33823 = x33822 * 10;
      char x33825 = x1749[x33824];
      char x33826 = x33825 - '0';
      int x33827 = x33823 + x33826;
      x33811 = x33827;
      x33730 = x33730 + 1;
    }
    x33730 = x33730 + 1;
    int x33833 = x33811;
    for (;;) {
      int x33835 = x33730;
      char x33836 = x1749[x33835];
      bool x33837 = x33836 != '|';
      bool x33842 = x33837;
      if (x33837) {
        int x33838 = x33730;
        char x33839 = x1749[x33838];
        bool x33840 = x33839 != '\n';
        x33842 = x33840;
      }
      bool x33843 = x33842;
      if (!x33843) break;
      x33730 = x33730 + 1;
    }
    x33730 = x33730 + 1;
    for (;;) {
      int x33855 = x33730;
      char x33856 = x1749[x33855];
      bool x33857 = x33856 != '.';
      bool x33862 = x33857;
      if (x33857) {
        int x33858 = x33730;
        char x33859 = x1749[x33858];
        bool x33860 = x33859 != '|';
        x33862 = x33860;
      }
      bool x33863 = x33862;
      bool x33868 = x33863;
      if (x33863) {
        int x33864 = x33730;
        char x33865 = x1749[x33864];
        bool x33866 = x33865 != '\n';
        x33868 = x33866;
      }
      bool x33869 = x33868;
      if (!x33869) break;
      x33730 = x33730 + 1;
    }
    int x33881 = x33730;
    char x33882 = x1749[x33881];
    bool x33883 = x33882 == '.';
    if (x33883) {
      x33730 = x33730 + 1;
      for (;;) {
        int x33885 = x33730;
        char x33886 = x1749[x33885];
        bool x33887 = x33886 != '|';
        bool x33892 = x33887;
        if (x33887) {
          int x33888 = x33730;
          char x33889 = x1749[x33888];
          bool x33890 = x33889 != '\n';
          x33892 = x33890;
        }
        bool x33893 = x33892;
        if (!x33893) break;
        x33730 = x33730 + 1;
      }
    } else {
    }
    x33730 = x33730 + 1;
    for (;;) {
      int x33918 = x33730;
      char x33919 = x1749[x33918];
      bool x33920 = x33919 != '|';
      bool x33925 = x33920;
      if (x33920) {
        int x33921 = x33730;
        char x33922 = x1749[x33921];
        bool x33923 = x33922 != '\n';
        x33925 = x33923;
      }
      bool x33926 = x33925;
      if (!x33926) break;
      x33730 = x33730 + 1;
    }
    x33730 = x33730 + 1;
    int x33936 = x33732;
    int x33937 = x33731;
    bool x33938 = x33936 == x33937;
    if (x33938) {
      int x33939 = x33937 * 4;
      x33731 = x33939;
      printf("buffer.resize %d\n",x33939);
      int* x33942 = x33734;
      int* x33943 = (int*)realloc(x33942,x33939 * sizeof(int));
      x33734 = x33943;
      char** x33945 = x33736;
      char** x33946 = (char**)realloc(x33945,x33939 * sizeof(char*));
      x33736 = x33946;
      char** x33948 = x33738;
      char** x33949 = (char**)realloc(x33948,x33939 * sizeof(char*));
      x33738 = x33949;
      int* x33951 = x33740;
      int* x33952 = (int*)realloc(x33951,x33939 * sizeof(int));
      x33740 = x33952;
    } else {
    }
    int* x33965 = x33734;
    x33965[x33936] = x33773;
    char** x33967 = x33736;
    char* x33791 = x1749+x33774;
    x33967[x33936] = x33791;
    char** x33969 = x33738;
    char* x33809 = x1749+x33792;
    x33969[x33936] = x33809;
    int* x33971 = x33740;
    x33971[x33936] = x33833;
    x33732 = x33732 + 1;
  }
  int x33982 = 0;
  int x33983 = 1048576;
  int x33984 = 0;
  int* x33985 = (int*)malloc(1048576 * sizeof(int));
  int* x33986 = x33985;
  int* x33987 = (int*)malloc(1048576 * sizeof(int));
  int* x33988 = x33987;
  int* x33989 = (int*)malloc(1048576 * sizeof(int));
  int* x33990 = x33989;
  int x1301 = open("../databases/sf2/partsupp.tbl",0);
  int x1302 = fsize(x1301);
  char* x1303 = mmap(0, x1302, PROT_READ, MAP_FILE | MAP_SHARED, x1301, 0);
  for (;;) {
    int x33995 = x33982;
    bool x33996 = x33995 < x1302;
    if (!x33996) break;
    int x33999 = 0;
    for (;;) {
      int x34000 = x33982;
      char x34001 = x1303[x34000];
      bool x34002 = x34001 != '|';
      bool x34007 = x34002;
      if (x34002) {
        int x34003 = x33982;
        char x34004 = x1303[x34003];
        bool x34005 = x34004 != '\n';
        x34007 = x34005;
      }
      bool x34008 = x34007;
      if (!x34008) break;
      int x34010 = x33999;
      int x34012 = x33982;
      int x34011 = x34010 * 10;
      char x34013 = x1303[x34012];
      char x34014 = x34013 - '0';
      int x34015 = x34011 + x34014;
      x33999 = x34015;
      x33982 = x33982 + 1;
    }
    x33982 = x33982 + 1;
    int x34021 = x33999;
    int x34023 = 0;
    for (;;) {
      int x34024 = x33982;
      char x34025 = x1303[x34024];
      bool x34026 = x34025 != '|';
      bool x34031 = x34026;
      if (x34026) {
        int x34027 = x33982;
        char x34028 = x1303[x34027];
        bool x34029 = x34028 != '\n';
        x34031 = x34029;
      }
      bool x34032 = x34031;
      if (!x34032) break;
      int x34034 = x34023;
      int x34036 = x33982;
      int x34035 = x34034 * 10;
      char x34037 = x1303[x34036];
      char x34038 = x34037 - '0';
      int x34039 = x34035 + x34038;
      x34023 = x34039;
      x33982 = x33982 + 1;
    }
    x33982 = x33982 + 1;
    int x34045 = x34023;
    int x34047 = 0;
    for (;;) {
      int x34048 = x33982;
      char x34049 = x1303[x34048];
      bool x34050 = x34049 != '|';
      bool x34055 = x34050;
      if (x34050) {
        int x34051 = x33982;
        char x34052 = x1303[x34051];
        bool x34053 = x34052 != '\n';
        x34055 = x34053;
      }
      bool x34056 = x34055;
      if (!x34056) break;
      int x34058 = x34047;
      int x34060 = x33982;
      int x34059 = x34058 * 10;
      char x34061 = x1303[x34060];
      char x34062 = x34061 - '0';
      int x34063 = x34059 + x34062;
      x34047 = x34063;
      x33982 = x33982 + 1;
    }
    x33982 = x33982 + 1;
    int x34069 = x34047;
    for (;;) {
      int x34073 = x33982;
      char x34074 = x1303[x34073];
      bool x34075 = x34074 != '.';
      bool x34080 = x34075;
      if (x34075) {
        int x34076 = x33982;
        char x34077 = x1303[x34076];
        bool x34078 = x34077 != '|';
        x34080 = x34078;
      }
      bool x34081 = x34080;
      bool x34086 = x34081;
      if (x34081) {
        int x34082 = x33982;
        char x34083 = x1303[x34082];
        bool x34084 = x34083 != '\n';
        x34086 = x34084;
      }
      bool x34087 = x34086;
      if (!x34087) break;
      x33982 = x33982 + 1;
    }
    int x34099 = x33982;
    char x34100 = x1303[x34099];
    bool x34101 = x34100 == '.';
    if (x34101) {
      x33982 = x33982 + 1;
      for (;;) {
        int x34103 = x33982;
        char x34104 = x1303[x34103];
        bool x34105 = x34104 != '|';
        bool x34110 = x34105;
        if (x34105) {
          int x34106 = x33982;
          char x34107 = x1303[x34106];
          bool x34108 = x34107 != '\n';
          x34110 = x34108;
        }
        bool x34111 = x34110;
        if (!x34111) break;
        x33982 = x33982 + 1;
      }
    } else {
    }
    x33982 = x33982 + 1;
    for (;;) {
      int x34136 = x33982;
      char x34137 = x1303[x34136];
      bool x34138 = x34137 != '|';
      bool x34143 = x34138;
      if (x34138) {
        int x34139 = x33982;
        char x34140 = x1303[x34139];
        bool x34141 = x34140 != '\n';
        x34143 = x34141;
      }
      bool x34144 = x34143;
      if (!x34144) break;
      x33982 = x33982 + 1;
    }
    x33982 = x33982 + 1;
    int x34154 = x33984;
    int x34155 = x33983;
    bool x34156 = x34154 == x34155;
    if (x34156) {
      int x34157 = x34155 * 4;
      x33983 = x34157;
      printf("buffer.resize %d\n",x34157);
      int* x34160 = x33986;
      int* x34161 = (int*)realloc(x34160,x34157 * sizeof(int));
      x33986 = x34161;
      int* x34163 = x33988;
      int* x34164 = (int*)realloc(x34163,x34157 * sizeof(int));
      x33988 = x34164;
      int* x34166 = x33990;
      int* x34167 = (int*)realloc(x34166,x34157 * sizeof(int));
      x33990 = x34167;
    } else {
    }
    int* x34177 = x33986;
    x34177[x34154] = x34021;
    int* x34179 = x33988;
    x34179[x34154] = x34045;
    int* x34181 = x33990;
    x34181[x34154] = x34069;
    x33984 = x33984 + 1;
  }
  int x34190 = 0;
  int x34191 = 1048576;
  int x34192 = 0;
  int* x34195 = (int*)malloc(1048576 * sizeof(int));
  int* x34196 = x34195;
  int* x34197 = (int*)malloc(1048576 * sizeof(int));
  int* x34198 = x34197;
  double* x34201 = (double*)malloc(1048576 * sizeof(double));
  double* x34202 = x34201;
  long* x34213 = (long*)malloc(1048576 * sizeof(long));
  long* x34214 = x34213;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  int x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    int x34225 = x34190;
    bool x34226 = x34225 < x3;
    if (!x34226) break;
    for (;;) {
      int x34230 = x34190;
      char x34231 = x4[x34230];
      bool x34232 = x34231 != '|';
      bool x34237 = x34232;
      if (x34232) {
        int x34233 = x34190;
        char x34234 = x4[x34233];
        bool x34235 = x34234 != '\n';
        x34237 = x34235;
      }
      bool x34238 = x34237;
      if (!x34238) break;
      x34190 = x34190 + 1;
    }
    x34190 = x34190 + 1;
    int x34253 = 0;
    for (;;) {
      int x34254 = x34190;
      char x34255 = x4[x34254];
      bool x34256 = x34255 != '|';
      bool x34261 = x34256;
      if (x34256) {
        int x34257 = x34190;
        char x34258 = x4[x34257];
        bool x34259 = x34258 != '\n';
        x34261 = x34259;
      }
      bool x34262 = x34261;
      if (!x34262) break;
      int x34264 = x34253;
      int x34266 = x34190;
      int x34265 = x34264 * 10;
      char x34267 = x4[x34266];
      char x34268 = x34267 - '0';
      int x34269 = x34265 + x34268;
      x34253 = x34269;
      x34190 = x34190 + 1;
    }
    x34190 = x34190 + 1;
    int x34275 = x34253;
    int x34277 = 0;
    for (;;) {
      int x34278 = x34190;
      char x34279 = x4[x34278];
      bool x34280 = x34279 != '|';
      bool x34285 = x34280;
      if (x34280) {
        int x34281 = x34190;
        char x34282 = x4[x34281];
        bool x34283 = x34282 != '\n';
        x34285 = x34283;
      }
      bool x34286 = x34285;
      if (!x34286) break;
      int x34288 = x34277;
      int x34290 = x34190;
      int x34289 = x34288 * 10;
      char x34291 = x4[x34290];
      char x34292 = x34291 - '0';
      int x34293 = x34289 + x34292;
      x34277 = x34293;
      x34190 = x34190 + 1;
    }
    x34190 = x34190 + 1;
    int x34299 = x34277;
    for (;;) {
      int x34302 = x34190;
      char x34303 = x4[x34302];
      bool x34304 = x34303 != '|';
      bool x34309 = x34304;
      if (x34304) {
        int x34305 = x34190;
        char x34306 = x4[x34305];
        bool x34307 = x34306 != '\n';
        x34309 = x34307;
      }
      bool x34310 = x34309;
      if (!x34310) break;
      x34190 = x34190 + 1;
    }
    x34190 = x34190 + 1;
    int x34325 = 0;
    int x34326 = 1;
    for (;;) {
      int x34327 = x34190;
      char x34328 = x4[x34327];
      bool x34329 = x34328 != '.';
      bool x34334 = x34329;
      if (x34329) {
        int x34330 = x34190;
        char x34331 = x4[x34330];
        bool x34332 = x34331 != '|';
        x34334 = x34332;
      }
      bool x34335 = x34334;
      bool x34340 = x34335;
      if (x34335) {
        int x34336 = x34190;
        char x34337 = x4[x34336];
        bool x34338 = x34337 != '\n';
        x34340 = x34338;
      }
      bool x34341 = x34340;
      if (!x34341) break;
      int x34343 = x34325;
      int x34345 = x34190;
      int x34344 = x34343 * 10;
      char x34346 = x4[x34345];
      char x34347 = x34346 - '0';
      int x34348 = x34344 + x34347;
      x34325 = x34348;
      x34190 = x34190 + 1;
    }
    int x34353 = x34190;
    char x34354 = x4[x34353];
    bool x34355 = x34354 == '.';
    if (x34355) {
      x34190 = x34190 + 1;
      for (;;) {
        int x34357 = x34190;
        char x34358 = x4[x34357];
        bool x34359 = x34358 != '|';
        bool x34364 = x34359;
        if (x34359) {
          int x34360 = x34190;
          char x34361 = x4[x34360];
          bool x34362 = x34361 != '\n';
          x34364 = x34362;
        }
        bool x34365 = x34364;
        if (!x34365) break;
        int x34367 = x34325;
        int x34369 = x34190;
        int x34368 = x34367 * 10;
        char x34370 = x4[x34369];
        char x34371 = x34370 - '0';
        int x34372 = x34368 + x34371;
        x34325 = x34372;
        int x34374 = x34326;
        int x34375 = x34374 * 10;
        x34326 = x34375;
        x34190 = x34190 + 1;
      }
    } else {
    }
    x34190 = x34190 + 1;
    int x34384 = x34325;
    int x34386 = x34326;
    for (;;) {
      int x34392 = x34190;
      char x34393 = x4[x34392];
      bool x34394 = x34393 != '.';
      bool x34399 = x34394;
      if (x34394) {
        int x34395 = x34190;
        char x34396 = x4[x34395];
        bool x34397 = x34396 != '|';
        x34399 = x34397;
      }
      bool x34400 = x34399;
      bool x34405 = x34400;
      if (x34400) {
        int x34401 = x34190;
        char x34402 = x4[x34401];
        bool x34403 = x34402 != '\n';
        x34405 = x34403;
      }
      bool x34406 = x34405;
      if (!x34406) break;
      x34190 = x34190 + 1;
    }
    int x34418 = x34190;
    char x34419 = x4[x34418];
    bool x34420 = x34419 == '.';
    if (x34420) {
      x34190 = x34190 + 1;
      for (;;) {
        int x34422 = x34190;
        char x34423 = x4[x34422];
        bool x34424 = x34423 != '|';
        bool x34429 = x34424;
        if (x34424) {
          int x34425 = x34190;
          char x34426 = x4[x34425];
          bool x34427 = x34426 != '\n';
          x34429 = x34427;
        }
        bool x34430 = x34429;
        if (!x34430) break;
        x34190 = x34190 + 1;
      }
    } else {
    }
    x34190 = x34190 + 1;
    for (;;) {
      int x34457 = x34190;
      char x34458 = x4[x34457];
      bool x34459 = x34458 != '.';
      bool x34464 = x34459;
      if (x34459) {
        int x34460 = x34190;
        char x34461 = x4[x34460];
        bool x34462 = x34461 != '|';
        x34464 = x34462;
      }
      bool x34465 = x34464;
      bool x34470 = x34465;
      if (x34465) {
        int x34466 = x34190;
        char x34467 = x4[x34466];
        bool x34468 = x34467 != '\n';
        x34470 = x34468;
      }
      bool x34471 = x34470;
      if (!x34471) break;
      x34190 = x34190 + 1;
    }
    int x34483 = x34190;
    char x34484 = x4[x34483];
    bool x34485 = x34484 == '.';
    if (x34485) {
      x34190 = x34190 + 1;
      for (;;) {
        int x34487 = x34190;
        char x34488 = x4[x34487];
        bool x34489 = x34488 != '|';
        bool x34494 = x34489;
        if (x34489) {
          int x34490 = x34190;
          char x34491 = x4[x34490];
          bool x34492 = x34491 != '\n';
          x34494 = x34492;
        }
        bool x34495 = x34494;
        if (!x34495) break;
        x34190 = x34190 + 1;
      }
    } else {
    }
    x34190 = x34190 + 1;
    for (;;) {
      int x34522 = x34190;
      char x34523 = x4[x34522];
      bool x34524 = x34523 != '.';
      bool x34529 = x34524;
      if (x34524) {
        int x34525 = x34190;
        char x34526 = x4[x34525];
        bool x34527 = x34526 != '|';
        x34529 = x34527;
      }
      bool x34530 = x34529;
      bool x34535 = x34530;
      if (x34530) {
        int x34531 = x34190;
        char x34532 = x4[x34531];
        bool x34533 = x34532 != '\n';
        x34535 = x34533;
      }
      bool x34536 = x34535;
      if (!x34536) break;
      x34190 = x34190 + 1;
    }
    int x34548 = x34190;
    char x34549 = x4[x34548];
    bool x34550 = x34549 == '.';
    if (x34550) {
      x34190 = x34190 + 1;
      for (;;) {
        int x34552 = x34190;
        char x34553 = x4[x34552];
        bool x34554 = x34553 != '|';
        bool x34559 = x34554;
        if (x34554) {
          int x34555 = x34190;
          char x34556 = x4[x34555];
          bool x34557 = x34556 != '\n';
          x34559 = x34557;
        }
        bool x34560 = x34559;
        if (!x34560) break;
        x34190 = x34190 + 1;
      }
    } else {
    }
    x34190 = x34190 + 1;
    x34190 = x34190 + 2;
    x34190 = x34190 + 2;
    int x34591 = 0;
    for (;;) {
      int x34592 = x34190;
      char x34593 = x4[x34592];
      bool x34594 = x34593 != '-';
      bool x34599 = x34594;
      if (x34594) {
        int x34595 = x34190;
        char x34596 = x4[x34595];
        bool x34597 = x34596 != '\n';
        x34599 = x34597;
      }
      bool x34600 = x34599;
      if (!x34600) break;
      int x34602 = x34591;
      int x34604 = x34190;
      int x34603 = x34602 * 10;
      char x34605 = x4[x34604];
      char x34606 = x34605 - '0';
      int x34607 = x34603 + x34606;
      x34591 = x34607;
      x34190 = x34190 + 1;
    }
    x34190 = x34190 + 1;
    int x34613 = x34591;
    int x34615 = 0;
    for (;;) {
      int x34616 = x34190;
      char x34617 = x4[x34616];
      bool x34618 = x34617 != '-';
      bool x34623 = x34618;
      if (x34618) {
        int x34619 = x34190;
        char x34620 = x4[x34619];
        bool x34621 = x34620 != '\n';
        x34623 = x34621;
      }
      bool x34624 = x34623;
      if (!x34624) break;
      int x34626 = x34615;
      int x34628 = x34190;
      int x34627 = x34626 * 10;
      char x34629 = x4[x34628];
      char x34630 = x34629 - '0';
      int x34631 = x34627 + x34630;
      x34615 = x34631;
      x34190 = x34190 + 1;
    }
    x34190 = x34190 + 1;
    int x34637 = x34615;
    int x34639 = 0;
    for (;;) {
      int x34640 = x34190;
      char x34641 = x4[x34640];
      bool x34642 = x34641 != '|';
      bool x34647 = x34642;
      if (x34642) {
        int x34643 = x34190;
        char x34644 = x4[x34643];
        bool x34645 = x34644 != '\n';
        x34647 = x34645;
      }
      bool x34648 = x34647;
      if (!x34648) break;
      int x34650 = x34639;
      int x34652 = x34190;
      int x34651 = x34650 * 10;
      char x34653 = x4[x34652];
      char x34654 = x34653 - '0';
      int x34655 = x34651 + x34654;
      x34639 = x34655;
      x34190 = x34190 + 1;
    }
    x34190 = x34190 + 1;
    int x34661 = x34639;
    for (;;) {
      int x34668 = x34190;
      char x34669 = x4[x34668];
      bool x34670 = x34669 != '-';
      bool x34675 = x34670;
      if (x34670) {
        int x34671 = x34190;
        char x34672 = x4[x34671];
        bool x34673 = x34672 != '\n';
        x34675 = x34673;
      }
      bool x34676 = x34675;
      if (!x34676) break;
      x34190 = x34190 + 1;
    }
    x34190 = x34190 + 1;
    for (;;) {
      int x34692 = x34190;
      char x34693 = x4[x34692];
      bool x34694 = x34693 != '-';
      bool x34699 = x34694;
      if (x34694) {
        int x34695 = x34190;
        char x34696 = x4[x34695];
        bool x34697 = x34696 != '\n';
        x34699 = x34697;
      }
      bool x34700 = x34699;
      if (!x34700) break;
      x34190 = x34190 + 1;
    }
    x34190 = x34190 + 1;
    for (;;) {
      int x34716 = x34190;
      char x34717 = x4[x34716];
      bool x34718 = x34717 != '|';
      bool x34723 = x34718;
      if (x34718) {
        int x34719 = x34190;
        char x34720 = x4[x34719];
        bool x34721 = x34720 != '\n';
        x34723 = x34721;
      }
      bool x34724 = x34723;
      if (!x34724) break;
      x34190 = x34190 + 1;
    }
    x34190 = x34190 + 1;
    for (;;) {
      int x34744 = x34190;
      char x34745 = x4[x34744];
      bool x34746 = x34745 != '-';
      bool x34751 = x34746;
      if (x34746) {
        int x34747 = x34190;
        char x34748 = x4[x34747];
        bool x34749 = x34748 != '\n';
        x34751 = x34749;
      }
      bool x34752 = x34751;
      if (!x34752) break;
      x34190 = x34190 + 1;
    }
    x34190 = x34190 + 1;
    for (;;) {
      int x34768 = x34190;
      char x34769 = x4[x34768];
      bool x34770 = x34769 != '-';
      bool x34775 = x34770;
      if (x34770) {
        int x34771 = x34190;
        char x34772 = x4[x34771];
        bool x34773 = x34772 != '\n';
        x34775 = x34773;
      }
      bool x34776 = x34775;
      if (!x34776) break;
      x34190 = x34190 + 1;
    }
    x34190 = x34190 + 1;
    for (;;) {
      int x34792 = x34190;
      char x34793 = x4[x34792];
      bool x34794 = x34793 != '|';
      bool x34799 = x34794;
      if (x34794) {
        int x34795 = x34190;
        char x34796 = x4[x34795];
        bool x34797 = x34796 != '\n';
        x34799 = x34797;
      }
      bool x34800 = x34799;
      if (!x34800) break;
      x34190 = x34190 + 1;
    }
    x34190 = x34190 + 1;
    for (;;) {
      int x34819 = x34190;
      char x34820 = x4[x34819];
      bool x34821 = x34820 != '|';
      bool x34826 = x34821;
      if (x34821) {
        int x34822 = x34190;
        char x34823 = x4[x34822];
        bool x34824 = x34823 != '\n';
        x34826 = x34824;
      }
      bool x34827 = x34826;
      if (!x34827) break;
      x34190 = x34190 + 1;
    }
    x34190 = x34190 + 1;
    for (;;) {
      int x34837 = x34190;
      char x34838 = x4[x34837];
      bool x34839 = x34838 != '|';
      bool x34844 = x34839;
      if (x34839) {
        int x34840 = x34190;
        char x34841 = x4[x34840];
        bool x34842 = x34841 != '\n';
        x34844 = x34842;
      }
      bool x34845 = x34844;
      if (!x34845) break;
      x34190 = x34190 + 1;
    }
    x34190 = x34190 + 1;
    for (;;) {
      int x34855 = x34190;
      char x34856 = x4[x34855];
      bool x34857 = x34856 != '|';
      bool x34862 = x34857;
      if (x34857) {
        int x34858 = x34190;
        char x34859 = x4[x34858];
        bool x34860 = x34859 != '\n';
        x34862 = x34860;
      }
      bool x34863 = x34862;
      if (!x34863) break;
      x34190 = x34190 + 1;
    }
    x34190 = x34190 + 1;
    int x34873 = x34192;
    int x34874 = x34191;
    bool x34875 = x34873 == x34874;
    if (x34875) {
      int x34876 = x34874 * 4;
      x34191 = x34876;
      printf("buffer.resize %d\n",x34876);
      int* x34882 = x34196;
      int* x34883 = (int*)realloc(x34882,x34876 * sizeof(int));
      x34196 = x34883;
      int* x34885 = x34198;
      int* x34886 = (int*)realloc(x34885,x34876 * sizeof(int));
      x34198 = x34886;
      double* x34891 = x34202;
      double* x34892 = (double*)realloc(x34891,x34876 * sizeof(double));
      x34202 = x34892;
      long* x34909 = x34214;
      long* x34910 = (long*)realloc(x34909,x34876 * sizeof(long));
      x34214 = x34910;
    } else {
    }
    int* x34931 = x34196;
    x34931[x34873] = x34275;
    int* x34933 = x34198;
    x34933[x34873] = x34299;
    double* x34937 = x34202;
    double x34385 = (double)x34384;
    double x34387 = (double)x34386;
    double x34388 = x34385 / x34387;
    x34937[x34873] = x34388;
    long* x34949 = x34214;
    long x34662 = x34613 * 10000L;
    long x34663 = x34637 * 100L;
    long x34664 = x34662 + x34663;
    long x34665 = x34664 + x34661;
    x34949[x34873] = x34665;
    x34192 = x34192 + 1;
  }
  bool x972 = true == false;
  int x34964;
  for(x34964=0; x34964 < 5; x34964++) {
    bool x34965 = false;
    int x34966 = 0;
    bool x34968 = false;
    int x34969 = 0;
    int* x34971 = (int*)malloc(134217728 * sizeof(int));
    int* x34972 = x34971;
    int x34989 = 0;
    int* x34990 = (int*)malloc(67108864 * sizeof(int));
    int* x34991 = (int*)malloc(134217728 * sizeof(int));
    int x34992;
    for(x34992=0; x34992 < 67108864; x34992++) {
      x34990[x34992] = -1;
    }
    bool x34997 = false;
    int x34998 = 0;
    int* x35019 = (int*)malloc(134217728 * sizeof(int));
    int* x35020 = x35019;
    int* x35021 = (int*)malloc(134217728 * sizeof(int));
    int* x35022 = x35021;
    int* x35023 = (int*)malloc(134217728 * sizeof(int));
    int* x35024 = x35023;
    int x35029 = 0;
    int* x35030 = (int*)malloc(67108864 * sizeof(int));
    int* x35031 = (int*)malloc(134217728 * sizeof(int));
    int x35032;
    for(x35032=0; x35032 < 67108864; x35032++) {
      x35030[x35032] = -1;
    }
    struct Anon745367039* x35038 = (struct Anon745367039*)malloc(16777216 * sizeof(struct Anon745367039));
    struct Anon745367039* x35039 = x35038;
    int x35040 = 0;
    int* x35041 = (int*)malloc(16777216 * sizeof(int));
    int x35042;
    for(x35042=0; x35042 < 16777216; x35042++) {
      struct Anon745367039* x35043 = x35039;
      struct Anon745367039 x35044 = x35043[x35042];
      struct Anon1993309635 x35045 = x35044.key;;
      double x35046 = x35044.aggs;;
      struct Anon745367039 x35047;
      x35047.exists = false;
      x35047.key = x35045;
      x35047.aggs = x35046;
      x35043[x35042] = x35047;
    }
    bool x35052 = false;
    int x35053 = 0;
    int* x35059 = (int*)malloc(134217728 * sizeof(int));
    int* x35060 = x35059;
    int x35065 = 0;
    int* x35066 = (int*)malloc(67108864 * sizeof(int));
    int* x35067 = (int*)malloc(134217728 * sizeof(int));
    int x35068;
    for(x35068=0; x35068 < 67108864; x35068++) {
      x35066[x35068] = -1;
    }
    bool x35073 = false;
    int x35074 = 0;
    int* x35077 = (int*)malloc(134217728 * sizeof(int));
    int* x35078 = x35077;
    int x35085 = 0;
    int* x35086 = (int*)malloc(67108864 * sizeof(int));
    int* x35087 = (int*)malloc(134217728 * sizeof(int));
    int x35088;
    for(x35088=0; x35088 < 67108864; x35088++) {
      x35086[x35088] = -1;
    }
    int x35094 = 0;
    struct timeval x35600, x35601, x35602;
    gettimeofday(&x35600, NULL);
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x35096 = x35073;
      bool x35097 = !x35096;
      bool x35102 = x35097;
      if (x35097) {
        int x35098 = x35074;
        int x35099 = x33602;
        bool x35100 = x35098 < x35099;
        x35102 = x35100;
      }
      bool x35103 = x35102;
      if (!x35103) break;
      int x35105 = x35074;
      int* x35106 = x33604;
      int x35107 = x35106[x35105];
      char** x35108 = x33606;
      char* x35109 = x35108[x35105];
      x35074 = x35074 + 1;
      bool x35116 = strcmp(x35109,"JORDAN") == 0;;
      if (x35116) {
        int x35117 = x35085;
        int* x35118 = x35078;
        x35118[x35117] = x35107;
        x35085 = x35085 + 1;
        int x35127 = x35107 & 67108863;
        int x35128 = x35086[x35127];
        x35086[x35127] = x35117;
        x35087[x35117] = x35128;
      } else {
      }
    }
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x35136 = x34965;
      bool x35137 = !x35136;
      bool x35142 = x35137;
      if (x35137) {
        int x35138 = x34966;
        int x35139 = x33299;
        bool x35140 = x35138 < x35139;
        x35142 = x35140;
      }
      bool x35143 = x35142;
      if (!x35143) break;
      int x35145 = x34966;
      int* x35146 = x33301;
      int x35147 = x35146[x35145];
      char** x35148 = x33303;
      char* x35149 = x35148[x35145];
      x34966 = x34966 + 1;
      bool x35166 = strncmp(x35149,"azure", strlen("azure")) == 0;;
      if (x35166) {
        int x35167 = x34989;
        int* x35168 = x34972;
        x35168[x35167] = x35147;
        x34989 = x34989 + 1;
        int x35187 = x35147 & 67108863;
        int x35188 = x34990[x35187];
        x34990[x35187] = x35167;
        x34991[x35167] = x35188;
      } else {
      }
    }
    printf("%s\n","begin scan PARTSUPP");
    for (;;) {
      bool x35196 = x34968;
      bool x35197 = !x35196;
      bool x35202 = x35197;
      if (x35197) {
        int x35198 = x34969;
        int x35199 = x33984;
        bool x35200 = x35198 < x35199;
        x35202 = x35200;
      }
      bool x35203 = x35202;
      if (!x35203) break;
      int x35205 = x34969;
      int* x35206 = x33986;
      int x35207 = x35206[x35205];
      int* x35208 = x33988;
      int x35209 = x35208[x35205];
      int* x35210 = x33990;
      int x35211 = x35210[x35205];
      x34969 = x34969 + 1;
      int x35218 = x35207 & 67108863;
      int x35219 = x34990[x35218];
      int x35220 = x35219;
      for (;;) {
        int x35221 = x35220;
        bool x35222 = x35221 != -1;
        if (!x35222) break;
        int x35224 = x35220;
        int* x35225 = x34972;
        int x35226 = x35225[x35224];
        int x35244 = x34991[x35224];
        x35220 = x35244;
        bool x35246 = x35226 == x35207;
        if (x35246) {
          int x35250 = x35029;
          int* x35269 = x35020;
          x35269[x35250] = x35207;
          int* x35271 = x35022;
          x35271[x35250] = x35209;
          int* x35273 = x35024;
          x35273[x35250] = x35211;
          x35029 = x35029 + 1;
          int x35280 = x35030[x35218];
          x35030[x35218] = x35250;
          x35031[x35250] = x35280;
        } else {
        }
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x35290 = x34997;
      bool x35291 = !x35290;
      bool x35296 = x35291;
      if (x35291) {
        int x35292 = x34998;
        int x35293 = x34192;
        bool x35294 = x35292 < x35293;
        x35296 = x35294;
      }
      bool x35297 = x35296;
      if (!x35297) break;
      int x35299 = x34998;
      int* x35302 = x34196;
      int x35303 = x35302[x35299];
      int* x35304 = x34198;
      int x35305 = x35304[x35299];
      double* x35308 = x34202;
      double x35309 = x35308[x35299];
      long* x35320 = x34214;
      long x35321 = x35320[x35299];
      x34998 = x34998 + 1;
      bool x35334 = x35321 >= 19960101L;
      bool x35336 = x35334;
      if (x35334) {
        bool x35335 = x35321 < 19970101L;
        x35336 = x35335;
      }
      bool x35337 = x35336;
      if (x35337) {
        int x35338 = x35303 & 67108863;
        int x35339 = x35030[x35338];
        int x35340 = x35339;
        for (;;) {
          int x35341 = x35340;
          bool x35342 = x35341 != -1;
          if (!x35342) break;
          int x35344 = x35340;
          int* x35363 = x35020;
          int x35364 = x35363[x35344];
          int* x35365 = x35022;
          int x35366 = x35365[x35344];
          int* x35367 = x35024;
          int x35368 = x35367[x35344];
          int x35374 = x35031[x35344];
          x35340 = x35374;
          bool x35376 = x35364 == x35303;
          bool x35378 = x35376;
          if (x35376) {
            bool x35377 = x35366 == x35305;
            x35378 = x35377;
          }
          bool x35379 = x35378;
          if (x35379) {
            int x35384 = 31857 + x35364;
            int x35385 = x35384 * 41;
            int x35386 = x35385 + x35366;
            int x35387 = x35386 & 16777215;
            int x35388 = x35387;
            struct Anon745367039* x35389 = x35039;
            struct Anon745367039 x35390 = x35389[x35387];
            struct Anon745367039 x35391 = x35390;
            bool x35392 = x35390.exists;;
            bool x35406 = x35392;
            if (x35392) {
              struct Anon745367039 x35393 = x35391;
              struct Anon1993309635 x35394 = x35393.key;;
              int x35395 = x35394.PS_PARTKEY;;
              bool x35396 = x35395 == x35364;
              bool x35401 = x35396;
              if (x35396) {
                int x35397 = x35394.PS_SUPPKEY;;
                bool x35398 = x35397 == x35366;
                x35401 = x35398;
              }
              bool x35402 = x35401;
              bool x35403 = x35402;
              if (x35402) {
                double x35399 = x35394.PS_AVAILQTY;;
                bool x35400 = x35399 == x35368;
                x35403 = x35400;
              }
              bool x35404 = x35403;
              x35406 = x35404;
            }
            bool x35407 = x35406;
            if (x35407) {
              double x35408 = x35390.aggs;;
              struct Anon1993309635 x35410 = x35390.key;;
              double x35409 = x35408 + x35309;
              struct Anon745367039 x35411;
              x35411.exists = true;
              x35411.key = x35410;
              x35411.aggs = x35409;
              x35389[x35387] = x35411;
            } else {
              struct Anon1993309635 x35383;
              x35383.PS_PARTKEY = x35364;
              x35383.PS_SUPPKEY = x35366;
              x35383.PS_AVAILQTY = x35368;
              struct Anon745367039 x35447;
              x35447.exists = true;
              x35447.key = x35383;
              x35447.aggs = x35309;
              for (;;) {
                struct Anon745367039 x35414 = x35391;
                bool x35415 = x35414.exists;;
                bool x35456;
                if (x35415) {
                  struct Anon1993309635 x35416 = x35414.key;;
                  int x35417 = x35416.PS_PARTKEY;;
                  bool x35418 = x35417 == x35364;
                  bool x35423 = x35418;
                  if (x35418) {
                    int x35419 = x35416.PS_SUPPKEY;;
                    bool x35420 = x35419 == x35366;
                    x35423 = x35420;
                  }
                  bool x35424 = x35423;
                  bool x35425 = x35424;
                  if (x35424) {
                    double x35421 = x35416.PS_AVAILQTY;;
                    bool x35422 = x35421 == x35368;
                    x35425 = x35422;
                  }
                  bool x35426 = x35425;
                  bool x35444;
                  if (x35426) {
                    double x35427 = x35414.aggs;;
                    int x35429 = x35388;
                    struct Anon745367039* x35431 = x35039;
                    double x35428 = x35427 + x35309;
                    struct Anon745367039 x35430;
                    x35430.exists = true;
                    x35430.key = x35416;
                    x35430.aggs = x35428;
                    x35431[x35429] = x35430;
                    x35444 = false;
                  } else {
                    int x35434 = x35388;
                    int x35435 = x35434 + 1;
                    int x35436 = x35435 % 16777215;
                    x35388 = x35436;
                    struct Anon745367039* x35438 = x35039;
                    struct Anon745367039 x35439 = x35438[x35436];
                    x35391 = x35439;
                    x35444 = true;
                  }
                  x35456 = x35444;
                } else {
                  int x35446 = x35388;
                  struct Anon745367039* x35448 = x35039;
                  x35448[x35446] = x35447;
                  int x35450 = x35040;
                  x35041[x35450] = x35446;
                  x35040 = x35040 + 1;
                  x35456 = false;
                }
                if (!x35456) break;
              }
            }
          } else {
          }
        }
      } else {
      }
    }
    int x35471 = x35040;
    int x35473;
    for(x35473=0; x35473 < x35471; x35473++) {
      int x35474 = x35041[x35473];
      struct Anon745367039* x35475 = x35039;
      struct Anon745367039 x35476 = x35475[x35474];
      struct Anon1993309635 x35477 = x35476.key;;
      double x35479 = x35476.aggs;;
      double x35478 = x35477.PS_AVAILQTY;;
      double x35480 = 0.5 * x35479;
      bool x35481 = x35478 > x35480;
      if (x35481) {
        int x35483 = x35065;
        int* x35490 = x35060;
        int x35482 = x35477.PS_SUPPKEY;;
        x35490[x35483] = x35482;
        x35065 = x35065 + 1;
        int x35497 = x35482 & 67108863;
        int x35498 = x35066[x35497];
        x35066[x35497] = x35483;
        x35067[x35483] = x35498;
      } else {
      }
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x35506 = x35052;
      bool x35507 = !x35506;
      bool x35512 = x35507;
      if (x35507) {
        int x35508 = x35053;
        int x35509 = x33732;
        bool x35510 = x35508 < x35509;
        x35512 = x35510;
      }
      bool x35513 = x35512;
      if (!x35513) break;
      int x35515 = x35053;
      int* x35516 = x33734;
      int x35517 = x35516[x35515];
      char** x35518 = x33736;
      char* x35519 = x35518[x35515];
      char** x35520 = x33738;
      char* x35521 = x35520[x35515];
      int* x35522 = x33740;
      int x35523 = x35522[x35515];
      x35053 = x35053 + 1;
      int x35532 = x35517 & 67108863;
      int x35533 = x35066[x35532];
      int x35534 = x35533;
      int x35557 = x35523 & 67108863;
      int x35581 = strlen(x35519);
      int x35582 = strlen(x35521);
      for (;;) {
        int x35535 = x35534;
        bool x35536 = x35535 != -1;
        if (!x35536) break;
        int x35538 = x35534;
        int* x35543 = x35060;
        int x35544 = x35543[x35538];
        int x35551 = x35067[x35538];
        x35534 = x35551;
        bool x35553 = x35544 == x35517;
        if (x35553) {
          int x35558 = x35086[x35557];
          int x35559 = x35558;
          for (;;) {
            int x35560 = x35559;
            bool x35561 = x35560 != -1;
            if (!x35561) break;
            int x35563 = x35559;
            int* x35564 = x35078;
            int x35565 = x35564[x35563];
            int x35573 = x35087[x35563];
            x35559 = x35573;
            bool x35575 = x35565 == x35523;
            if (x35575) {
              if (x972) {
              } else {
                printf("%.*s|%.*s\n",x35581,x35519,x35582,x35521);
                x35094 = x35094 + 1;
              }
            } else {
            }
          }
        } else {
        }
      }
    }
    int x35597 = x35094;
    printf("(%d rows)\n",x35597);
    gettimeofday(&x35601, NULL);
    timeval_subtract(&x35602, &x35601, &x35600);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x35602.tv_sec * 1000) + (x35602.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
