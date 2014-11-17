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

struct Anon2052879266 {
double _0;
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

struct Anon1268892766 {
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
};

struct Anon1652045692 {
int key;
struct Anon2052879266 aggs;
};

struct Anon0 {
struct Anon1268892766 left;
struct Anon1652045692 right;
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

struct Anon787349517 {
bool exists;
int key;
struct Anon1023322325 aggs;
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

struct Anon2131541195 {
double total;
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

struct Anon1007729034 {
bool exists;
char* key;
struct Anon2052879266 aggs;
};

struct Anon72918141 {
int N2_N_NATIONKEY;
char* N2_N_NAME;
int N2_N_REGIONKEY;
char* N2_N_COMMENT;
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

struct Anon1272074242 {
bool exists;
struct Anon625264174 key;
struct Anon567626277 aggs;
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

struct Anon2071559637 {
bool exists;
struct Anon1548200872 key;
struct Anon2052879266 aggs;
};

/************************ FUNCTIONS **************************/

/************************ MAIN BODY **************************/
int main(int x25625, char** x25626) {
  int x25627 = 0;
  int x25628 = 1048576;
  int x25629 = 0;
  int* x25634 = (int*)malloc(1048576 * sizeof(int));
  int* x25635 = x25634;
  double* x25640 = (double*)malloc(1048576 * sizeof(double));
  double* x25641 = x25640;
  double* x25642 = (double*)malloc(1048576 * sizeof(double));
  double* x25643 = x25642;
  long* x25650 = (long*)malloc(1048576 * sizeof(long));
  long* x25651 = x25650;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  int x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    int x25662 = x25627;
    bool x25663 = x25662 < x3;
    if (!x25663) break;
    for (;;) {
      int x25667 = x25627;
      char x25668 = x4[x25667];
      bool x25669 = x25668 != '|';
      bool x25674 = x25669;
      if (x25669) {
        int x25670 = x25627;
        char x25671 = x4[x25670];
        bool x25672 = x25671 != '\n';
        x25674 = x25672;
      }
      bool x25675 = x25674;
      if (!x25675) break;
      x25627 = x25627 + 1;
    }
    x25627 = x25627 + 1;
    for (;;) {
      int x25691 = x25627;
      char x25692 = x4[x25691];
      bool x25693 = x25692 != '|';
      bool x25698 = x25693;
      if (x25693) {
        int x25694 = x25627;
        char x25695 = x4[x25694];
        bool x25696 = x25695 != '\n';
        x25698 = x25696;
      }
      bool x25699 = x25698;
      if (!x25699) break;
      x25627 = x25627 + 1;
    }
    x25627 = x25627 + 1;
    int x25714 = 0;
    for (;;) {
      int x25715 = x25627;
      char x25716 = x4[x25715];
      bool x25717 = x25716 != '|';
      bool x25722 = x25717;
      if (x25717) {
        int x25718 = x25627;
        char x25719 = x4[x25718];
        bool x25720 = x25719 != '\n';
        x25722 = x25720;
      }
      bool x25723 = x25722;
      if (!x25723) break;
      int x25725 = x25714;
      int x25727 = x25627;
      int x25726 = x25725 * 10;
      char x25728 = x4[x25727];
      char x25729 = x25728 - '0';
      int x25730 = x25726 + x25729;
      x25714 = x25730;
      x25627 = x25627 + 1;
    }
    x25627 = x25627 + 1;
    int x25736 = x25714;
    for (;;) {
      int x25739 = x25627;
      char x25740 = x4[x25739];
      bool x25741 = x25740 != '|';
      bool x25746 = x25741;
      if (x25741) {
        int x25742 = x25627;
        char x25743 = x4[x25742];
        bool x25744 = x25743 != '\n';
        x25746 = x25744;
      }
      bool x25747 = x25746;
      if (!x25747) break;
      x25627 = x25627 + 1;
    }
    x25627 = x25627 + 1;
    for (;;) {
      int x25764 = x25627;
      char x25765 = x4[x25764];
      bool x25766 = x25765 != '.';
      bool x25771 = x25766;
      if (x25766) {
        int x25767 = x25627;
        char x25768 = x4[x25767];
        bool x25769 = x25768 != '|';
        x25771 = x25769;
      }
      bool x25772 = x25771;
      bool x25777 = x25772;
      if (x25772) {
        int x25773 = x25627;
        char x25774 = x4[x25773];
        bool x25775 = x25774 != '\n';
        x25777 = x25775;
      }
      bool x25778 = x25777;
      if (!x25778) break;
      x25627 = x25627 + 1;
    }
    int x25790 = x25627;
    char x25791 = x4[x25790];
    bool x25792 = x25791 == '.';
    if (x25792) {
      x25627 = x25627 + 1;
      for (;;) {
        int x25794 = x25627;
        char x25795 = x4[x25794];
        bool x25796 = x25795 != '|';
        bool x25801 = x25796;
        if (x25796) {
          int x25797 = x25627;
          char x25798 = x4[x25797];
          bool x25799 = x25798 != '\n';
          x25801 = x25799;
        }
        bool x25802 = x25801;
        if (!x25802) break;
        x25627 = x25627 + 1;
      }
    } else {
    }
    x25627 = x25627 + 1;
    int x25827 = 0;
    int x25828 = 1;
    for (;;) {
      int x25829 = x25627;
      char x25830 = x4[x25829];
      bool x25831 = x25830 != '.';
      bool x25836 = x25831;
      if (x25831) {
        int x25832 = x25627;
        char x25833 = x4[x25832];
        bool x25834 = x25833 != '|';
        x25836 = x25834;
      }
      bool x25837 = x25836;
      bool x25842 = x25837;
      if (x25837) {
        int x25838 = x25627;
        char x25839 = x4[x25838];
        bool x25840 = x25839 != '\n';
        x25842 = x25840;
      }
      bool x25843 = x25842;
      if (!x25843) break;
      int x25845 = x25827;
      int x25847 = x25627;
      int x25846 = x25845 * 10;
      char x25848 = x4[x25847];
      char x25849 = x25848 - '0';
      int x25850 = x25846 + x25849;
      x25827 = x25850;
      x25627 = x25627 + 1;
    }
    int x25855 = x25627;
    char x25856 = x4[x25855];
    bool x25857 = x25856 == '.';
    if (x25857) {
      x25627 = x25627 + 1;
      for (;;) {
        int x25859 = x25627;
        char x25860 = x4[x25859];
        bool x25861 = x25860 != '|';
        bool x25866 = x25861;
        if (x25861) {
          int x25862 = x25627;
          char x25863 = x4[x25862];
          bool x25864 = x25863 != '\n';
          x25866 = x25864;
        }
        bool x25867 = x25866;
        if (!x25867) break;
        int x25869 = x25827;
        int x25871 = x25627;
        int x25870 = x25869 * 10;
        char x25872 = x4[x25871];
        char x25873 = x25872 - '0';
        int x25874 = x25870 + x25873;
        x25827 = x25874;
        int x25876 = x25828;
        int x25877 = x25876 * 10;
        x25828 = x25877;
        x25627 = x25627 + 1;
      }
    } else {
    }
    x25627 = x25627 + 1;
    int x25886 = x25827;
    int x25888 = x25828;
    int x25892 = 0;
    int x25893 = 1;
    for (;;) {
      int x25894 = x25627;
      char x25895 = x4[x25894];
      bool x25896 = x25895 != '.';
      bool x25901 = x25896;
      if (x25896) {
        int x25897 = x25627;
        char x25898 = x4[x25897];
        bool x25899 = x25898 != '|';
        x25901 = x25899;
      }
      bool x25902 = x25901;
      bool x25907 = x25902;
      if (x25902) {
        int x25903 = x25627;
        char x25904 = x4[x25903];
        bool x25905 = x25904 != '\n';
        x25907 = x25905;
      }
      bool x25908 = x25907;
      if (!x25908) break;
      int x25910 = x25892;
      int x25912 = x25627;
      int x25911 = x25910 * 10;
      char x25913 = x4[x25912];
      char x25914 = x25913 - '0';
      int x25915 = x25911 + x25914;
      x25892 = x25915;
      x25627 = x25627 + 1;
    }
    int x25920 = x25627;
    char x25921 = x4[x25920];
    bool x25922 = x25921 == '.';
    if (x25922) {
      x25627 = x25627 + 1;
      for (;;) {
        int x25924 = x25627;
        char x25925 = x4[x25924];
        bool x25926 = x25925 != '|';
        bool x25931 = x25926;
        if (x25926) {
          int x25927 = x25627;
          char x25928 = x4[x25927];
          bool x25929 = x25928 != '\n';
          x25931 = x25929;
        }
        bool x25932 = x25931;
        if (!x25932) break;
        int x25934 = x25892;
        int x25936 = x25627;
        int x25935 = x25934 * 10;
        char x25937 = x4[x25936];
        char x25938 = x25937 - '0';
        int x25939 = x25935 + x25938;
        x25892 = x25939;
        int x25941 = x25893;
        int x25942 = x25941 * 10;
        x25893 = x25942;
        x25627 = x25627 + 1;
      }
    } else {
    }
    x25627 = x25627 + 1;
    int x25951 = x25892;
    int x25953 = x25893;
    for (;;) {
      int x25959 = x25627;
      char x25960 = x4[x25959];
      bool x25961 = x25960 != '.';
      bool x25966 = x25961;
      if (x25961) {
        int x25962 = x25627;
        char x25963 = x4[x25962];
        bool x25964 = x25963 != '|';
        x25966 = x25964;
      }
      bool x25967 = x25966;
      bool x25972 = x25967;
      if (x25967) {
        int x25968 = x25627;
        char x25969 = x4[x25968];
        bool x25970 = x25969 != '\n';
        x25972 = x25970;
      }
      bool x25973 = x25972;
      if (!x25973) break;
      x25627 = x25627 + 1;
    }
    int x25985 = x25627;
    char x25986 = x4[x25985];
    bool x25987 = x25986 == '.';
    if (x25987) {
      x25627 = x25627 + 1;
      for (;;) {
        int x25989 = x25627;
        char x25990 = x4[x25989];
        bool x25991 = x25990 != '|';
        bool x25996 = x25991;
        if (x25991) {
          int x25992 = x25627;
          char x25993 = x4[x25992];
          bool x25994 = x25993 != '\n';
          x25996 = x25994;
        }
        bool x25997 = x25996;
        if (!x25997) break;
        x25627 = x25627 + 1;
      }
    } else {
    }
    x25627 = x25627 + 1;
    x25627 = x25627 + 2;
    x25627 = x25627 + 2;
    int x26028 = 0;
    for (;;) {
      int x26029 = x25627;
      char x26030 = x4[x26029];
      bool x26031 = x26030 != '-';
      bool x26036 = x26031;
      if (x26031) {
        int x26032 = x25627;
        char x26033 = x4[x26032];
        bool x26034 = x26033 != '\n';
        x26036 = x26034;
      }
      bool x26037 = x26036;
      if (!x26037) break;
      int x26039 = x26028;
      int x26041 = x25627;
      int x26040 = x26039 * 10;
      char x26042 = x4[x26041];
      char x26043 = x26042 - '0';
      int x26044 = x26040 + x26043;
      x26028 = x26044;
      x25627 = x25627 + 1;
    }
    x25627 = x25627 + 1;
    int x26050 = x26028;
    int x26052 = 0;
    for (;;) {
      int x26053 = x25627;
      char x26054 = x4[x26053];
      bool x26055 = x26054 != '-';
      bool x26060 = x26055;
      if (x26055) {
        int x26056 = x25627;
        char x26057 = x4[x26056];
        bool x26058 = x26057 != '\n';
        x26060 = x26058;
      }
      bool x26061 = x26060;
      if (!x26061) break;
      int x26063 = x26052;
      int x26065 = x25627;
      int x26064 = x26063 * 10;
      char x26066 = x4[x26065];
      char x26067 = x26066 - '0';
      int x26068 = x26064 + x26067;
      x26052 = x26068;
      x25627 = x25627 + 1;
    }
    x25627 = x25627 + 1;
    int x26074 = x26052;
    int x26076 = 0;
    for (;;) {
      int x26077 = x25627;
      char x26078 = x4[x26077];
      bool x26079 = x26078 != '|';
      bool x26084 = x26079;
      if (x26079) {
        int x26080 = x25627;
        char x26081 = x4[x26080];
        bool x26082 = x26081 != '\n';
        x26084 = x26082;
      }
      bool x26085 = x26084;
      if (!x26085) break;
      int x26087 = x26076;
      int x26089 = x25627;
      int x26088 = x26087 * 10;
      char x26090 = x4[x26089];
      char x26091 = x26090 - '0';
      int x26092 = x26088 + x26091;
      x26076 = x26092;
      x25627 = x25627 + 1;
    }
    x25627 = x25627 + 1;
    int x26098 = x26076;
    for (;;) {
      int x26105 = x25627;
      char x26106 = x4[x26105];
      bool x26107 = x26106 != '-';
      bool x26112 = x26107;
      if (x26107) {
        int x26108 = x25627;
        char x26109 = x4[x26108];
        bool x26110 = x26109 != '\n';
        x26112 = x26110;
      }
      bool x26113 = x26112;
      if (!x26113) break;
      x25627 = x25627 + 1;
    }
    x25627 = x25627 + 1;
    for (;;) {
      int x26129 = x25627;
      char x26130 = x4[x26129];
      bool x26131 = x26130 != '-';
      bool x26136 = x26131;
      if (x26131) {
        int x26132 = x25627;
        char x26133 = x4[x26132];
        bool x26134 = x26133 != '\n';
        x26136 = x26134;
      }
      bool x26137 = x26136;
      if (!x26137) break;
      x25627 = x25627 + 1;
    }
    x25627 = x25627 + 1;
    for (;;) {
      int x26153 = x25627;
      char x26154 = x4[x26153];
      bool x26155 = x26154 != '|';
      bool x26160 = x26155;
      if (x26155) {
        int x26156 = x25627;
        char x26157 = x4[x26156];
        bool x26158 = x26157 != '\n';
        x26160 = x26158;
      }
      bool x26161 = x26160;
      if (!x26161) break;
      x25627 = x25627 + 1;
    }
    x25627 = x25627 + 1;
    for (;;) {
      int x26181 = x25627;
      char x26182 = x4[x26181];
      bool x26183 = x26182 != '-';
      bool x26188 = x26183;
      if (x26183) {
        int x26184 = x25627;
        char x26185 = x4[x26184];
        bool x26186 = x26185 != '\n';
        x26188 = x26186;
      }
      bool x26189 = x26188;
      if (!x26189) break;
      x25627 = x25627 + 1;
    }
    x25627 = x25627 + 1;
    for (;;) {
      int x26205 = x25627;
      char x26206 = x4[x26205];
      bool x26207 = x26206 != '-';
      bool x26212 = x26207;
      if (x26207) {
        int x26208 = x25627;
        char x26209 = x4[x26208];
        bool x26210 = x26209 != '\n';
        x26212 = x26210;
      }
      bool x26213 = x26212;
      if (!x26213) break;
      x25627 = x25627 + 1;
    }
    x25627 = x25627 + 1;
    for (;;) {
      int x26229 = x25627;
      char x26230 = x4[x26229];
      bool x26231 = x26230 != '|';
      bool x26236 = x26231;
      if (x26231) {
        int x26232 = x25627;
        char x26233 = x4[x26232];
        bool x26234 = x26233 != '\n';
        x26236 = x26234;
      }
      bool x26237 = x26236;
      if (!x26237) break;
      x25627 = x25627 + 1;
    }
    x25627 = x25627 + 1;
    for (;;) {
      int x26256 = x25627;
      char x26257 = x4[x26256];
      bool x26258 = x26257 != '|';
      bool x26263 = x26258;
      if (x26258) {
        int x26259 = x25627;
        char x26260 = x4[x26259];
        bool x26261 = x26260 != '\n';
        x26263 = x26261;
      }
      bool x26264 = x26263;
      if (!x26264) break;
      x25627 = x25627 + 1;
    }
    x25627 = x25627 + 1;
    for (;;) {
      int x26274 = x25627;
      char x26275 = x4[x26274];
      bool x26276 = x26275 != '|';
      bool x26281 = x26276;
      if (x26276) {
        int x26277 = x25627;
        char x26278 = x4[x26277];
        bool x26279 = x26278 != '\n';
        x26281 = x26279;
      }
      bool x26282 = x26281;
      if (!x26282) break;
      x25627 = x25627 + 1;
    }
    x25627 = x25627 + 1;
    for (;;) {
      int x26292 = x25627;
      char x26293 = x4[x26292];
      bool x26294 = x26293 != '|';
      bool x26299 = x26294;
      if (x26294) {
        int x26295 = x25627;
        char x26296 = x4[x26295];
        bool x26297 = x26296 != '\n';
        x26299 = x26297;
      }
      bool x26300 = x26299;
      if (!x26300) break;
      x25627 = x25627 + 1;
    }
    x25627 = x25627 + 1;
    int x26310 = x25629;
    int x26311 = x25628;
    bool x26312 = x26310 == x26311;
    if (x26312) {
      int x26313 = x26311 * 4;
      x25628 = x26313;
      printf("buffer.resize %d\n",x26313);
      int* x26322 = x25635;
      int* x26323 = (int*)realloc(x26322,x26313 * sizeof(int));
      x25635 = x26323;
      double* x26331 = x25641;
      double* x26332 = (double*)realloc(x26331,x26313 * sizeof(double));
      x25641 = x26332;
      double* x26334 = x25643;
      double* x26335 = (double*)realloc(x26334,x26313 * sizeof(double));
      x25643 = x26335;
      long* x26346 = x25651;
      long* x26347 = (long*)realloc(x26346,x26313 * sizeof(long));
      x25651 = x26347;
    } else {
    }
    int* x26370 = x25635;
    x26370[x26310] = x25736;
    double* x26376 = x25641;
    double x25887 = (double)x25886;
    double x25889 = (double)x25888;
    double x25890 = x25887 / x25889;
    x26376[x26310] = x25890;
    double* x26378 = x25643;
    double x25952 = (double)x25951;
    double x25954 = (double)x25953;
    double x25955 = x25952 / x25954;
    x26378[x26310] = x25955;
    long* x26386 = x25651;
    long x26099 = x26050 * 10000L;
    long x26100 = x26074 * 100L;
    long x26101 = x26099 + x26100;
    long x26102 = x26101 + x26098;
    x26386[x26310] = x26102;
    x25629 = x25629 + 1;
  }
  int x26401 = 0;
  int x26402 = 1048576;
  int x26403 = 0;
  int* x26404 = (int*)malloc(1048576 * sizeof(int));
  int* x26405 = x26404;
  char** x26406 = (char**)malloc(1048576 * sizeof(char*));
  char** x26407 = x26406;
  char** x26408 = (char**)malloc(1048576 * sizeof(char*));
  char** x26409 = x26408;
  char** x26412 = (char**)malloc(1048576 * sizeof(char*));
  char** x26413 = x26412;
  int x1747 = open("../databases/sf2/supplier.tbl",0);
  int x1748 = fsize(x1747);
  char* x1749 = mmap(0, x1748, PROT_READ, MAP_FILE | MAP_SHARED, x1747, 0);
  for (;;) {
    int x26418 = x26401;
    bool x26419 = x26418 < x1748;
    if (!x26419) break;
    int x26422 = 0;
    for (;;) {
      int x26423 = x26401;
      char x26424 = x1749[x26423];
      bool x26425 = x26424 != '|';
      bool x26430 = x26425;
      if (x26425) {
        int x26426 = x26401;
        char x26427 = x1749[x26426];
        bool x26428 = x26427 != '\n';
        x26430 = x26428;
      }
      bool x26431 = x26430;
      if (!x26431) break;
      int x26433 = x26422;
      int x26435 = x26401;
      int x26434 = x26433 * 10;
      char x26436 = x1749[x26435];
      char x26437 = x26436 - '0';
      int x26438 = x26434 + x26437;
      x26422 = x26438;
      x26401 = x26401 + 1;
    }
    x26401 = x26401 + 1;
    int x26444 = x26422;
    int x26445 = x26401;
    for (;;) {
      int x26446 = x26401;
      char x26447 = x1749[x26446];
      bool x26448 = x26447 != '|';
      bool x26453 = x26448;
      if (x26448) {
        int x26449 = x26401;
        char x26450 = x1749[x26449];
        bool x26451 = x26450 != '\n';
        x26453 = x26451;
      }
      bool x26454 = x26453;
      if (!x26454) break;
      x26401 = x26401 + 1;
    }
    x26401 = x26401 + 1;
    int x26463 = x26401;
    for (;;) {
      int x26464 = x26401;
      char x26465 = x1749[x26464];
      bool x26466 = x26465 != '|';
      bool x26471 = x26466;
      if (x26466) {
        int x26467 = x26401;
        char x26468 = x1749[x26467];
        bool x26469 = x26468 != '\n';
        x26471 = x26469;
      }
      bool x26472 = x26471;
      if (!x26472) break;
      x26401 = x26401 + 1;
    }
    x26401 = x26401 + 1;
    for (;;) {
      int x26483 = x26401;
      char x26484 = x1749[x26483];
      bool x26485 = x26484 != '|';
      bool x26490 = x26485;
      if (x26485) {
        int x26486 = x26401;
        char x26487 = x1749[x26486];
        bool x26488 = x26487 != '\n';
        x26490 = x26488;
      }
      bool x26491 = x26490;
      if (!x26491) break;
      x26401 = x26401 + 1;
    }
    x26401 = x26401 + 1;
    int x26505 = x26401;
    for (;;) {
      int x26506 = x26401;
      char x26507 = x1749[x26506];
      bool x26508 = x26507 != '|';
      bool x26513 = x26508;
      if (x26508) {
        int x26509 = x26401;
        char x26510 = x1749[x26509];
        bool x26511 = x26510 != '\n';
        x26513 = x26511;
      }
      bool x26514 = x26513;
      if (!x26514) break;
      x26401 = x26401 + 1;
    }
    x26401 = x26401 + 1;
    for (;;) {
      int x26526 = x26401;
      char x26527 = x1749[x26526];
      bool x26528 = x26527 != '.';
      bool x26533 = x26528;
      if (x26528) {
        int x26529 = x26401;
        char x26530 = x1749[x26529];
        bool x26531 = x26530 != '|';
        x26533 = x26531;
      }
      bool x26534 = x26533;
      bool x26539 = x26534;
      if (x26534) {
        int x26535 = x26401;
        char x26536 = x1749[x26535];
        bool x26537 = x26536 != '\n';
        x26539 = x26537;
      }
      bool x26540 = x26539;
      if (!x26540) break;
      x26401 = x26401 + 1;
    }
    int x26552 = x26401;
    char x26553 = x1749[x26552];
    bool x26554 = x26553 == '.';
    if (x26554) {
      x26401 = x26401 + 1;
      for (;;) {
        int x26556 = x26401;
        char x26557 = x1749[x26556];
        bool x26558 = x26557 != '|';
        bool x26563 = x26558;
        if (x26558) {
          int x26559 = x26401;
          char x26560 = x1749[x26559];
          bool x26561 = x26560 != '\n';
          x26563 = x26561;
        }
        bool x26564 = x26563;
        if (!x26564) break;
        x26401 = x26401 + 1;
      }
    } else {
    }
    x26401 = x26401 + 1;
    for (;;) {
      int x26589 = x26401;
      char x26590 = x1749[x26589];
      bool x26591 = x26590 != '|';
      bool x26596 = x26591;
      if (x26591) {
        int x26592 = x26401;
        char x26593 = x1749[x26592];
        bool x26594 = x26593 != '\n';
        x26596 = x26594;
      }
      bool x26597 = x26596;
      if (!x26597) break;
      x26401 = x26401 + 1;
    }
    x26401 = x26401 + 1;
    int x26607 = x26403;
    int x26608 = x26402;
    bool x26609 = x26607 == x26608;
    if (x26609) {
      int x26610 = x26608 * 4;
      x26402 = x26610;
      printf("buffer.resize %d\n",x26610);
      int* x26613 = x26405;
      int* x26614 = (int*)realloc(x26613,x26610 * sizeof(int));
      x26405 = x26614;
      char** x26616 = x26407;
      char** x26617 = (char**)realloc(x26616,x26610 * sizeof(char*));
      x26407 = x26617;
      char** x26619 = x26409;
      char** x26620 = (char**)realloc(x26619,x26610 * sizeof(char*));
      x26409 = x26620;
      char** x26625 = x26413;
      char** x26626 = (char**)realloc(x26625,x26610 * sizeof(char*));
      x26413 = x26626;
    } else {
    }
    int* x26636 = x26405;
    x26636[x26607] = x26444;
    char** x26638 = x26407;
    char* x26462 = x1749+x26445;
    x26638[x26607] = x26462;
    char** x26640 = x26409;
    char* x26480 = x1749+x26463;
    x26640[x26607] = x26480;
    char** x26644 = x26413;
    char* x26522 = x1749+x26505;
    x26644[x26607] = x26522;
    x26403 = x26403 + 1;
  }
  char x26943 = "MAXREVENUE"[0];
  int x26944 = x26943 * 41;
  char x26945 = "MAXREVENUE"[1];
  int x26946 = x26944 + x26945;
  int x26947 = x26946 * 41;
  char x26948 = "MAXREVENUE"[2];
  int x26949 = x26947 + x26948;
  int x26950 = x26949 * 41;
  char x26951 = "MAXREVENUE"[3];
  int x26952 = x26950 + x26951;
  int x26953 = x26952 & 16777215;
  bool x972 = true == false;
  int x26653;
  for(x26653=0; x26653 < 5; x26653++) {
    bool x26654 = false;
    int x26655 = 0;
    struct Anon2092052448* x26658 = (struct Anon2092052448*)malloc(16777216 * sizeof(struct Anon2092052448));
    struct Anon2092052448* x26659 = x26658;
    int x26660 = 0;
    int* x26661 = (int*)malloc(16777216 * sizeof(int));
    int x26662;
    for(x26662=0; x26662 < 16777216; x26662++) {
      struct Anon2092052448* x26663 = x26659;
      struct Anon2092052448 x26664 = x26663[x26662];
      int x26665 = x26664.key;;
      struct Anon2052879266 x26666 = x26664.aggs;;
      struct Anon2092052448 x26667;
      x26667.exists = false;
      x26667.key = x26665;
      x26667.aggs = x26666;
      x26663[x26662] = x26667;
    }
    int x26672 = 1048576;
    int x26673 = 0;
    int* x26676 = (int*)malloc(1048576 * sizeof(int));
    int* x26677 = x26676;
    double* x26678 = (double*)malloc(1048576 * sizeof(double));
    double* x26679 = x26678;
    struct Anon1007729034* x26683 = (struct Anon1007729034*)malloc(16777216 * sizeof(struct Anon1007729034));
    struct Anon1007729034* x26684 = x26683;
    int x26685 = 0;
    int* x26686 = (int*)malloc(16777216 * sizeof(int));
    int x26687;
    for(x26687=0; x26687 < 16777216; x26687++) {
      struct Anon1007729034* x26688 = x26684;
      struct Anon1007729034 x26689 = x26688[x26687];
      char* x26690 = x26689.key;;
      struct Anon2052879266 x26691 = x26689.aggs;;
      struct Anon1007729034 x26692;
      x26692.exists = false;
      x26692.key = x26690;
      x26692.aggs = x26691;
      x26688[x26687] = x26692;
    }
    double x26698 = 0.0;
    bool x26701 = false;
    int x26702 = 0;
    int* x26704 = (int*)malloc(134217728 * sizeof(int));
    int* x26705 = x26704;
    char** x26706 = (char**)malloc(134217728 * sizeof(char*));
    char** x26707 = x26706;
    char** x26708 = (char**)malloc(134217728 * sizeof(char*));
    char** x26709 = x26708;
    char** x26712 = (char**)malloc(134217728 * sizeof(char*));
    char** x26713 = x26712;
    int x26718 = 0;
    int* x26719 = (int*)malloc(67108864 * sizeof(int));
    int* x26720 = (int*)malloc(134217728 * sizeof(int));
    int x26721;
    for(x26721=0; x26721 < 67108864; x26721++) {
      x26719[x26721] = -1;
    }
    int x26727 = 0;
    struct timeval x27098, x27099, x27100;
    gettimeofday(&x27098, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x26729 = x26654;
      bool x26730 = !x26729;
      bool x26735 = x26730;
      if (x26730) {
        int x26731 = x26655;
        int x26732 = x25629;
        bool x26733 = x26731 < x26732;
        x26735 = x26733;
      }
      bool x26736 = x26735;
      if (!x26736) break;
      int x26738 = x26655;
      int* x26743 = x25635;
      int x26744 = x26743[x26738];
      double* x26749 = x25641;
      double x26750 = x26749[x26738];
      double* x26751 = x25643;
      double x26752 = x26751[x26738];
      long* x26759 = x25651;
      long x26760 = x26759[x26738];
      x26655 = x26655 + 1;
      bool x26773 = x26760 >= 19930901L;
      bool x26775 = x26773;
      if (x26773) {
        bool x26774 = x26760 < 19931201L;
        x26775 = x26774;
      }
      bool x26776 = x26775;
      if (x26776) {
        int x26777 = x26744 & 16777215;
        int x26778 = x26777;
        struct Anon2092052448* x26779 = x26659;
        struct Anon2092052448 x26780 = x26779[x26777];
        struct Anon2092052448 x26781 = x26780;
        bool x26782 = x26780.exists;;
        bool x26787 = x26782;
        if (x26782) {
          struct Anon2092052448 x26783 = x26781;
          int x26784 = x26783.key;;
          bool x26785 = x26784 == x26744;
          x26787 = x26785;
        }
        bool x26788 = x26787;
        if (x26788) {
          struct Anon2052879266 x26789 = x26780.aggs;;
          int x26795 = x26780.key;;
          double x26790 = x26789._0;;
          double x26791 = 1.0 - x26752;
          double x26792 = x26750 * x26791;
          double x26793 = x26790 + x26792;
          struct Anon2052879266 x26794;
          x26794._0 = x26793;
          struct Anon2092052448 x26796;
          x26796.exists = true;
          x26796.key = x26795;
          x26796.aggs = x26794;
          x26779[x26777] = x26796;
        } else {
          double x26791 = 1.0 - x26752;
          double x26792 = x26750 * x26791;
          struct Anon2052879266 x26825;
          x26825._0 = x26792;
          struct Anon2092052448 x26826;
          x26826.exists = true;
          x26826.key = x26744;
          x26826.aggs = x26825;
          for (;;) {
            struct Anon2092052448 x26799 = x26781;
            bool x26800 = x26799.exists;;
            bool x26835;
            if (x26800) {
              int x26801 = x26799.key;;
              bool x26802 = x26801 == x26744;
              bool x26822;
              if (x26802) {
                struct Anon2052879266 x26803 = x26799.aggs;;
                int x26807 = x26778;
                struct Anon2092052448* x26809 = x26659;
                double x26804 = x26803._0;;
                double x26805 = x26804 + x26792;
                struct Anon2052879266 x26806;
                x26806._0 = x26805;
                struct Anon2092052448 x26808;
                x26808.exists = true;
                x26808.key = x26801;
                x26808.aggs = x26806;
                x26809[x26807] = x26808;
                x26822 = false;
              } else {
                int x26812 = x26778;
                int x26813 = x26812 + 1;
                int x26814 = x26813 % 16777215;
                x26778 = x26814;
                struct Anon2092052448* x26816 = x26659;
                struct Anon2092052448 x26817 = x26816[x26814];
                x26781 = x26817;
                x26822 = true;
              }
              x26835 = x26822;
            } else {
              int x26824 = x26778;
              struct Anon2092052448* x26827 = x26659;
              x26827[x26824] = x26826;
              int x26829 = x26660;
              x26661[x26829] = x26824;
              x26660 = x26660 + 1;
              x26835 = false;
            }
            if (!x26835) break;
          }
        }
      } else {
      }
    }
    int x26846 = x26660;
    int x26848;
    for(x26848=0; x26848 < x26846; x26848++) {
      int x26849 = x26661[x26848];
      struct Anon2092052448* x26850 = x26659;
      struct Anon2092052448 x26851 = x26850[x26849];
      int x26852 = x26673;
      int x26853 = x26672;
      bool x26854 = x26852 == x26853;
      if (x26854) {
        int x26855 = x26853 * 4;
        x26672 = x26855;
        printf("buffer.resize %d\n",x26855);
        int* x26861 = x26677;
        int* x26862 = (int*)realloc(x26861,x26855 * sizeof(int));
        x26677 = x26862;
        printf("buffer.resize %d\n",x26855);
        double* x26865 = x26679;
        double* x26866 = (double*)realloc(x26865,x26855 * sizeof(double));
        x26679 = x26866;
      } else {
      }
      int x26873 = x26851.key;;
      int* x26874 = x26677;
      x26874[x26852] = x26873;
      struct Anon2052879266 x26876 = x26851.aggs;;
      double* x26878 = x26679;
      double x26877 = x26876._0;;
      x26878[x26852] = x26877;
      x26673 = x26673 + 1;
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x26884 = x26701;
      bool x26885 = !x26884;
      bool x26890 = x26885;
      if (x26885) {
        int x26886 = x26702;
        int x26887 = x26403;
        bool x26888 = x26886 < x26887;
        x26890 = x26888;
      }
      bool x26891 = x26890;
      if (!x26891) break;
      int x26893 = x26702;
      int* x26894 = x26405;
      int x26895 = x26894[x26893];
      char** x26896 = x26407;
      char* x26897 = x26896[x26893];
      char** x26898 = x26409;
      char* x26899 = x26898[x26893];
      char** x26902 = x26413;
      char* x26903 = x26902[x26893];
      x26702 = x26702 + 1;
      int x26910 = x26718;
      int* x26911 = x26705;
      x26911[x26910] = x26895;
      char** x26913 = x26707;
      x26913[x26910] = x26897;
      char** x26915 = x26709;
      x26915[x26910] = x26899;
      char** x26919 = x26713;
      x26919[x26910] = x26903;
      x26718 = x26718 + 1;
      int x26926 = x26895 & 67108863;
      int x26927 = x26719[x26926];
      x26719[x26926] = x26910;
      x26720[x26910] = x26927;
    }
    int x26932 = x26673;
    int x26934;
    for(x26934=0; x26934 < x26932; x26934++) {
      double* x26939 = x26679;
      double x26940 = x26939[x26934];
      int x26954 = x26953;
      struct Anon1007729034* x26955 = x26684;
      struct Anon1007729034 x26956 = x26955[x26953];
      struct Anon1007729034 x26957 = x26956;
      bool x26958 = x26956.exists;;
      bool x26963 = x26958;
      if (x26958) {
        struct Anon1007729034 x26959 = x26957;
        char* x26960 = x26959.key;;
        bool x26961 = strcmp(x26960,"MAXREVENUE") == 0;;
        x26963 = x26961;
      }
      bool x26964 = x26963;
      if (x26964) {
        struct Anon2052879266 x26965 = x26956.aggs;;
        char* x26970 = x26956.key;;
        double x26966 = x26965._0;;
        bool x26967 = x26966 < x26940;
        double x26968;
        if (x26967) {
          x26968 = x26940;
        } else {
          x26968 = x26966;
        }
        struct Anon2052879266 x26969;
        x26969._0 = x26968;
        struct Anon1007729034 x26971;
        x26971.exists = true;
        x26971.key = x26970;
        x26971.aggs = x26969;
        x26955[x26953] = x26971;
      } else {
        bool x27001 = 0.0 < x26940;
        double x27002;
        if (x27001) {
          x27002 = x26940;
        } else {
          x27002 = 0.0;
        }
        struct Anon2052879266 x27003;
        x27003._0 = x27002;
        struct Anon1007729034 x27004;
        x27004.exists = true;
        x27004.key = "MAXREVENUE";
        x27004.aggs = x27003;
        for (;;) {
          struct Anon1007729034 x26974 = x26957;
          bool x26975 = x26974.exists;;
          bool x27013;
          if (x26975) {
            char* x26976 = x26974.key;;
            bool x26977 = strcmp(x26976,"MAXREVENUE") == 0;;
            bool x26998;
            if (x26977) {
              struct Anon2052879266 x26978 = x26974.aggs;;
              int x26983 = x26954;
              struct Anon1007729034* x26985 = x26684;
              double x26979 = x26978._0;;
              bool x26980 = x26979 < x26940;
              double x26981;
              if (x26980) {
                x26981 = x26940;
              } else {
                x26981 = x26979;
              }
              struct Anon2052879266 x26982;
              x26982._0 = x26981;
              struct Anon1007729034 x26984;
              x26984.exists = true;
              x26984.key = x26976;
              x26984.aggs = x26982;
              x26985[x26983] = x26984;
              x26998 = false;
            } else {
              int x26988 = x26954;
              int x26989 = x26988 + 1;
              int x26990 = x26989 % 16777215;
              x26954 = x26990;
              struct Anon1007729034* x26992 = x26684;
              struct Anon1007729034 x26993 = x26992[x26990];
              x26957 = x26993;
              x26998 = true;
            }
            x27013 = x26998;
          } else {
            int x27000 = x26954;
            struct Anon1007729034* x27005 = x26684;
            x27005[x27000] = x27004;
            int x27007 = x26685;
            x26686[x27007] = x27000;
            x26685 = x26685 + 1;
            x27013 = false;
          }
          if (!x27013) break;
        }
      }
    }
    int x27022 = x26685;
    int x27024;
    for(x27024=0; x27024 < x27022; x27024++) {
      int x27025 = x26686[x27024];
      struct Anon1007729034* x27026 = x26684;
      struct Anon1007729034 x27027 = x27026[x27025];
      struct Anon2052879266 x27028 = x27027.aggs;;
      double x27029 = x27028._0;;
      x26698 = x27029;
      int x27032 = x26673;
      int x27034;
      for(x27034=0; x27034 < x27032; x27034++) {
        int* x27037 = x26677;
        int x27038 = x27037[x27034];
        double* x27039 = x26679;
        double x27040 = x27039[x27034];
        double x27043 = x26698;
        bool x27045 = x27040 == x27043;
        if (x27045) {
          int x27048 = x27038 & 67108863;
          int x27049 = x26719[x27048];
          int x27050 = x27049;
          for (;;) {
            int x27051 = x27050;
            bool x27052 = x27051 != -1;
            if (!x27052) break;
            int x27054 = x27050;
            int* x27055 = x26705;
            int x27056 = x27055[x27054];
            char** x27057 = x26707;
            char* x27058 = x27057[x27054];
            char** x27059 = x26709;
            char* x27060 = x27059[x27054];
            char** x27063 = x26713;
            char* x27064 = x27063[x27054];
            int x27070 = x26720[x27054];
            x27050 = x27070;
            bool x27072 = x27056 == x27038;
            if (x27072) {
              if (x972) {
              } else {
                int x27078 = strlen(x27058);
                int x27079 = strlen(x27060);
                int x27080 = strlen(x27064);
                printf("%d|%.*s|%.*s|%.*s|%.4f\n",x27056,x27078,x27058,x27079,x27060,x27080,x27064,x27040);
                x26727 = x26727 + 1;
              }
            } else {
            }
          }
        } else {
        }
      }
    }
    int x27095 = x26727;
    printf("(%d rows)\n",x27095);
    gettimeofday(&x27099, NULL);
    timeval_subtract(&x27100, &x27099, &x27098);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x27100.tv_sec * 1000) + (x27100.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
