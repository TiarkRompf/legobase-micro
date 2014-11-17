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

struct Anon0 {
struct Anon811555534 left;
struct Anon168903330 right;
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
int main(int x21713, char** x21714) {
  int x21715 = 0;
  int x21716 = 1048576;
  int x21717 = 0;
  int* x21718 = (int*)malloc(1048576 * sizeof(int));
  int* x21719 = x21718;
  long* x21738 = (long*)malloc(1048576 * sizeof(long));
  long* x21739 = x21738;
  long* x21740 = (long*)malloc(1048576 * sizeof(long));
  long* x21741 = x21740;
  long* x21742 = (long*)malloc(1048576 * sizeof(long));
  long* x21743 = x21742;
  char** x21746 = (char**)malloc(1048576 * sizeof(char*));
  char** x21747 = x21746;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  int x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    int x21750 = x21715;
    bool x21751 = x21750 < x3;
    if (!x21751) break;
    int x21754 = 0;
    for (;;) {
      int x21755 = x21715;
      char x21756 = x4[x21755];
      bool x21757 = x21756 != '|';
      bool x21762 = x21757;
      if (x21757) {
        int x21758 = x21715;
        char x21759 = x4[x21758];
        bool x21760 = x21759 != '\n';
        x21762 = x21760;
      }
      bool x21763 = x21762;
      if (!x21763) break;
      int x21765 = x21754;
      int x21767 = x21715;
      int x21766 = x21765 * 10;
      char x21768 = x4[x21767];
      char x21769 = x21768 - '0';
      int x21770 = x21766 + x21769;
      x21754 = x21770;
      x21715 = x21715 + 1;
    }
    x21715 = x21715 + 1;
    int x21776 = x21754;
    for (;;) {
      int x21779 = x21715;
      char x21780 = x4[x21779];
      bool x21781 = x21780 != '|';
      bool x21786 = x21781;
      if (x21781) {
        int x21782 = x21715;
        char x21783 = x4[x21782];
        bool x21784 = x21783 != '\n';
        x21786 = x21784;
      }
      bool x21787 = x21786;
      if (!x21787) break;
      x21715 = x21715 + 1;
    }
    x21715 = x21715 + 1;
    for (;;) {
      int x21803 = x21715;
      char x21804 = x4[x21803];
      bool x21805 = x21804 != '|';
      bool x21810 = x21805;
      if (x21805) {
        int x21806 = x21715;
        char x21807 = x4[x21806];
        bool x21808 = x21807 != '\n';
        x21810 = x21808;
      }
      bool x21811 = x21810;
      if (!x21811) break;
      x21715 = x21715 + 1;
    }
    x21715 = x21715 + 1;
    for (;;) {
      int x21827 = x21715;
      char x21828 = x4[x21827];
      bool x21829 = x21828 != '|';
      bool x21834 = x21829;
      if (x21829) {
        int x21830 = x21715;
        char x21831 = x4[x21830];
        bool x21832 = x21831 != '\n';
        x21834 = x21832;
      }
      bool x21835 = x21834;
      if (!x21835) break;
      x21715 = x21715 + 1;
    }
    x21715 = x21715 + 1;
    for (;;) {
      int x21852 = x21715;
      char x21853 = x4[x21852];
      bool x21854 = x21853 != '.';
      bool x21859 = x21854;
      if (x21854) {
        int x21855 = x21715;
        char x21856 = x4[x21855];
        bool x21857 = x21856 != '|';
        x21859 = x21857;
      }
      bool x21860 = x21859;
      bool x21865 = x21860;
      if (x21860) {
        int x21861 = x21715;
        char x21862 = x4[x21861];
        bool x21863 = x21862 != '\n';
        x21865 = x21863;
      }
      bool x21866 = x21865;
      if (!x21866) break;
      x21715 = x21715 + 1;
    }
    int x21878 = x21715;
    char x21879 = x4[x21878];
    bool x21880 = x21879 == '.';
    if (x21880) {
      x21715 = x21715 + 1;
      for (;;) {
        int x21882 = x21715;
        char x21883 = x4[x21882];
        bool x21884 = x21883 != '|';
        bool x21889 = x21884;
        if (x21884) {
          int x21885 = x21715;
          char x21886 = x4[x21885];
          bool x21887 = x21886 != '\n';
          x21889 = x21887;
        }
        bool x21890 = x21889;
        if (!x21890) break;
        x21715 = x21715 + 1;
      }
    } else {
    }
    x21715 = x21715 + 1;
    for (;;) {
      int x21917 = x21715;
      char x21918 = x4[x21917];
      bool x21919 = x21918 != '.';
      bool x21924 = x21919;
      if (x21919) {
        int x21920 = x21715;
        char x21921 = x4[x21920];
        bool x21922 = x21921 != '|';
        x21924 = x21922;
      }
      bool x21925 = x21924;
      bool x21930 = x21925;
      if (x21925) {
        int x21926 = x21715;
        char x21927 = x4[x21926];
        bool x21928 = x21927 != '\n';
        x21930 = x21928;
      }
      bool x21931 = x21930;
      if (!x21931) break;
      x21715 = x21715 + 1;
    }
    int x21943 = x21715;
    char x21944 = x4[x21943];
    bool x21945 = x21944 == '.';
    if (x21945) {
      x21715 = x21715 + 1;
      for (;;) {
        int x21947 = x21715;
        char x21948 = x4[x21947];
        bool x21949 = x21948 != '|';
        bool x21954 = x21949;
        if (x21949) {
          int x21950 = x21715;
          char x21951 = x4[x21950];
          bool x21952 = x21951 != '\n';
          x21954 = x21952;
        }
        bool x21955 = x21954;
        if (!x21955) break;
        x21715 = x21715 + 1;
      }
    } else {
    }
    x21715 = x21715 + 1;
    for (;;) {
      int x21982 = x21715;
      char x21983 = x4[x21982];
      bool x21984 = x21983 != '.';
      bool x21989 = x21984;
      if (x21984) {
        int x21985 = x21715;
        char x21986 = x4[x21985];
        bool x21987 = x21986 != '|';
        x21989 = x21987;
      }
      bool x21990 = x21989;
      bool x21995 = x21990;
      if (x21990) {
        int x21991 = x21715;
        char x21992 = x4[x21991];
        bool x21993 = x21992 != '\n';
        x21995 = x21993;
      }
      bool x21996 = x21995;
      if (!x21996) break;
      x21715 = x21715 + 1;
    }
    int x22008 = x21715;
    char x22009 = x4[x22008];
    bool x22010 = x22009 == '.';
    if (x22010) {
      x21715 = x21715 + 1;
      for (;;) {
        int x22012 = x21715;
        char x22013 = x4[x22012];
        bool x22014 = x22013 != '|';
        bool x22019 = x22014;
        if (x22014) {
          int x22015 = x21715;
          char x22016 = x4[x22015];
          bool x22017 = x22016 != '\n';
          x22019 = x22017;
        }
        bool x22020 = x22019;
        if (!x22020) break;
        x21715 = x21715 + 1;
      }
    } else {
    }
    x21715 = x21715 + 1;
    for (;;) {
      int x22047 = x21715;
      char x22048 = x4[x22047];
      bool x22049 = x22048 != '.';
      bool x22054 = x22049;
      if (x22049) {
        int x22050 = x21715;
        char x22051 = x4[x22050];
        bool x22052 = x22051 != '|';
        x22054 = x22052;
      }
      bool x22055 = x22054;
      bool x22060 = x22055;
      if (x22055) {
        int x22056 = x21715;
        char x22057 = x4[x22056];
        bool x22058 = x22057 != '\n';
        x22060 = x22058;
      }
      bool x22061 = x22060;
      if (!x22061) break;
      x21715 = x21715 + 1;
    }
    int x22073 = x21715;
    char x22074 = x4[x22073];
    bool x22075 = x22074 == '.';
    if (x22075) {
      x21715 = x21715 + 1;
      for (;;) {
        int x22077 = x21715;
        char x22078 = x4[x22077];
        bool x22079 = x22078 != '|';
        bool x22084 = x22079;
        if (x22079) {
          int x22080 = x21715;
          char x22081 = x4[x22080];
          bool x22082 = x22081 != '\n';
          x22084 = x22082;
        }
        bool x22085 = x22084;
        if (!x22085) break;
        x21715 = x21715 + 1;
      }
    } else {
    }
    x21715 = x21715 + 1;
    x21715 = x21715 + 2;
    x21715 = x21715 + 2;
    int x22116 = 0;
    for (;;) {
      int x22117 = x21715;
      char x22118 = x4[x22117];
      bool x22119 = x22118 != '-';
      bool x22124 = x22119;
      if (x22119) {
        int x22120 = x21715;
        char x22121 = x4[x22120];
        bool x22122 = x22121 != '\n';
        x22124 = x22122;
      }
      bool x22125 = x22124;
      if (!x22125) break;
      int x22127 = x22116;
      int x22129 = x21715;
      int x22128 = x22127 * 10;
      char x22130 = x4[x22129];
      char x22131 = x22130 - '0';
      int x22132 = x22128 + x22131;
      x22116 = x22132;
      x21715 = x21715 + 1;
    }
    x21715 = x21715 + 1;
    int x22138 = x22116;
    int x22140 = 0;
    for (;;) {
      int x22141 = x21715;
      char x22142 = x4[x22141];
      bool x22143 = x22142 != '-';
      bool x22148 = x22143;
      if (x22143) {
        int x22144 = x21715;
        char x22145 = x4[x22144];
        bool x22146 = x22145 != '\n';
        x22148 = x22146;
      }
      bool x22149 = x22148;
      if (!x22149) break;
      int x22151 = x22140;
      int x22153 = x21715;
      int x22152 = x22151 * 10;
      char x22154 = x4[x22153];
      char x22155 = x22154 - '0';
      int x22156 = x22152 + x22155;
      x22140 = x22156;
      x21715 = x21715 + 1;
    }
    x21715 = x21715 + 1;
    int x22162 = x22140;
    int x22164 = 0;
    for (;;) {
      int x22165 = x21715;
      char x22166 = x4[x22165];
      bool x22167 = x22166 != '|';
      bool x22172 = x22167;
      if (x22167) {
        int x22168 = x21715;
        char x22169 = x4[x22168];
        bool x22170 = x22169 != '\n';
        x22172 = x22170;
      }
      bool x22173 = x22172;
      if (!x22173) break;
      int x22175 = x22164;
      int x22177 = x21715;
      int x22176 = x22175 * 10;
      char x22178 = x4[x22177];
      char x22179 = x22178 - '0';
      int x22180 = x22176 + x22179;
      x22164 = x22180;
      x21715 = x21715 + 1;
    }
    x21715 = x21715 + 1;
    int x22186 = x22164;
    int x22192 = 0;
    for (;;) {
      int x22193 = x21715;
      char x22194 = x4[x22193];
      bool x22195 = x22194 != '-';
      bool x22200 = x22195;
      if (x22195) {
        int x22196 = x21715;
        char x22197 = x4[x22196];
        bool x22198 = x22197 != '\n';
        x22200 = x22198;
      }
      bool x22201 = x22200;
      if (!x22201) break;
      int x22203 = x22192;
      int x22205 = x21715;
      int x22204 = x22203 * 10;
      char x22206 = x4[x22205];
      char x22207 = x22206 - '0';
      int x22208 = x22204 + x22207;
      x22192 = x22208;
      x21715 = x21715 + 1;
    }
    x21715 = x21715 + 1;
    int x22214 = x22192;
    int x22216 = 0;
    for (;;) {
      int x22217 = x21715;
      char x22218 = x4[x22217];
      bool x22219 = x22218 != '-';
      bool x22224 = x22219;
      if (x22219) {
        int x22220 = x21715;
        char x22221 = x4[x22220];
        bool x22222 = x22221 != '\n';
        x22224 = x22222;
      }
      bool x22225 = x22224;
      if (!x22225) break;
      int x22227 = x22216;
      int x22229 = x21715;
      int x22228 = x22227 * 10;
      char x22230 = x4[x22229];
      char x22231 = x22230 - '0';
      int x22232 = x22228 + x22231;
      x22216 = x22232;
      x21715 = x21715 + 1;
    }
    x21715 = x21715 + 1;
    int x22238 = x22216;
    int x22240 = 0;
    for (;;) {
      int x22241 = x21715;
      char x22242 = x4[x22241];
      bool x22243 = x22242 != '|';
      bool x22248 = x22243;
      if (x22243) {
        int x22244 = x21715;
        char x22245 = x4[x22244];
        bool x22246 = x22245 != '\n';
        x22248 = x22246;
      }
      bool x22249 = x22248;
      if (!x22249) break;
      int x22251 = x22240;
      int x22253 = x21715;
      int x22252 = x22251 * 10;
      char x22254 = x4[x22253];
      char x22255 = x22254 - '0';
      int x22256 = x22252 + x22255;
      x22240 = x22256;
      x21715 = x21715 + 1;
    }
    x21715 = x21715 + 1;
    int x22262 = x22240;
    int x22268 = 0;
    for (;;) {
      int x22269 = x21715;
      char x22270 = x4[x22269];
      bool x22271 = x22270 != '-';
      bool x22276 = x22271;
      if (x22271) {
        int x22272 = x21715;
        char x22273 = x4[x22272];
        bool x22274 = x22273 != '\n';
        x22276 = x22274;
      }
      bool x22277 = x22276;
      if (!x22277) break;
      int x22279 = x22268;
      int x22281 = x21715;
      int x22280 = x22279 * 10;
      char x22282 = x4[x22281];
      char x22283 = x22282 - '0';
      int x22284 = x22280 + x22283;
      x22268 = x22284;
      x21715 = x21715 + 1;
    }
    x21715 = x21715 + 1;
    int x22290 = x22268;
    int x22292 = 0;
    for (;;) {
      int x22293 = x21715;
      char x22294 = x4[x22293];
      bool x22295 = x22294 != '-';
      bool x22300 = x22295;
      if (x22295) {
        int x22296 = x21715;
        char x22297 = x4[x22296];
        bool x22298 = x22297 != '\n';
        x22300 = x22298;
      }
      bool x22301 = x22300;
      if (!x22301) break;
      int x22303 = x22292;
      int x22305 = x21715;
      int x22304 = x22303 * 10;
      char x22306 = x4[x22305];
      char x22307 = x22306 - '0';
      int x22308 = x22304 + x22307;
      x22292 = x22308;
      x21715 = x21715 + 1;
    }
    x21715 = x21715 + 1;
    int x22314 = x22292;
    int x22316 = 0;
    for (;;) {
      int x22317 = x21715;
      char x22318 = x4[x22317];
      bool x22319 = x22318 != '|';
      bool x22324 = x22319;
      if (x22319) {
        int x22320 = x21715;
        char x22321 = x4[x22320];
        bool x22322 = x22321 != '\n';
        x22324 = x22322;
      }
      bool x22325 = x22324;
      if (!x22325) break;
      int x22327 = x22316;
      int x22329 = x21715;
      int x22328 = x22327 * 10;
      char x22330 = x4[x22329];
      char x22331 = x22330 - '0';
      int x22332 = x22328 + x22331;
      x22316 = x22332;
      x21715 = x21715 + 1;
    }
    x21715 = x21715 + 1;
    int x22338 = x22316;
    for (;;) {
      int x22344 = x21715;
      char x22345 = x4[x22344];
      bool x22346 = x22345 != '|';
      bool x22351 = x22346;
      if (x22346) {
        int x22347 = x21715;
        char x22348 = x4[x22347];
        bool x22349 = x22348 != '\n';
        x22351 = x22349;
      }
      bool x22352 = x22351;
      if (!x22352) break;
      x21715 = x21715 + 1;
    }
    x21715 = x21715 + 1;
    int x22361 = x21715;
    for (;;) {
      int x22362 = x21715;
      char x22363 = x4[x22362];
      bool x22364 = x22363 != '|';
      bool x22369 = x22364;
      if (x22364) {
        int x22365 = x21715;
        char x22366 = x4[x22365];
        bool x22367 = x22366 != '\n';
        x22369 = x22367;
      }
      bool x22370 = x22369;
      if (!x22370) break;
      x21715 = x21715 + 1;
    }
    x21715 = x21715 + 1;
    for (;;) {
      int x22380 = x21715;
      char x22381 = x4[x22380];
      bool x22382 = x22381 != '|';
      bool x22387 = x22382;
      if (x22382) {
        int x22383 = x21715;
        char x22384 = x4[x22383];
        bool x22385 = x22384 != '\n';
        x22387 = x22385;
      }
      bool x22388 = x22387;
      if (!x22388) break;
      x21715 = x21715 + 1;
    }
    x21715 = x21715 + 1;
    int x22398 = x21717;
    int x22399 = x21716;
    bool x22400 = x22398 == x22399;
    if (x22400) {
      int x22401 = x22399 * 4;
      x21716 = x22401;
      printf("buffer.resize %d\n",x22401);
      int* x22404 = x21719;
      int* x22405 = (int*)realloc(x22404,x22401 * sizeof(int));
      x21719 = x22405;
      long* x22434 = x21739;
      long* x22435 = (long*)realloc(x22434,x22401 * sizeof(long));
      x21739 = x22435;
      long* x22437 = x21741;
      long* x22438 = (long*)realloc(x22437,x22401 * sizeof(long));
      x21741 = x22438;
      long* x22440 = x21743;
      long* x22441 = (long*)realloc(x22440,x22401 * sizeof(long));
      x21743 = x22441;
      char** x22446 = x21747;
      char** x22447 = (char**)realloc(x22446,x22401 * sizeof(char*));
      x21747 = x22447;
    } else {
    }
    int* x22454 = x21719;
    x22454[x22398] = x21776;
    long* x22474 = x21739;
    long x22187 = x22138 * 10000L;
    long x22188 = x22162 * 100L;
    long x22189 = x22187 + x22188;
    long x22190 = x22189 + x22186;
    x22474[x22398] = x22190;
    long* x22476 = x21741;
    long x22263 = x22214 * 10000L;
    long x22264 = x22238 * 100L;
    long x22265 = x22263 + x22264;
    long x22266 = x22265 + x22262;
    x22476[x22398] = x22266;
    long* x22478 = x21743;
    long x22339 = x22290 * 10000L;
    long x22340 = x22314 * 100L;
    long x22341 = x22339 + x22340;
    long x22342 = x22341 + x22338;
    x22478[x22398] = x22342;
    char** x22482 = x21747;
    char* x22378 = x4+x22361;
    x22482[x22398] = x22378;
    x21717 = x21717 + 1;
  }
  int x22489 = 0;
  int x22490 = 1048576;
  int x22491 = 0;
  int* x22492 = (int*)malloc(1048576 * sizeof(int));
  int* x22493 = x22492;
  char** x22502 = (char**)malloc(1048576 * sizeof(char*));
  char** x22503 = x22502;
  int x3366 = open("../databases/sf2/orders.tbl",0);
  int x3367 = fsize(x3366);
  char* x3368 = mmap(0, x3367, PROT_READ, MAP_FILE | MAP_SHARED, x3366, 0);
  for (;;) {
    int x22510 = x22489;
    bool x22511 = x22510 < x3367;
    if (!x22511) break;
    int x22514 = 0;
    for (;;) {
      int x22515 = x22489;
      char x22516 = x3368[x22515];
      bool x22517 = x22516 != '|';
      bool x22522 = x22517;
      if (x22517) {
        int x22518 = x22489;
        char x22519 = x3368[x22518];
        bool x22520 = x22519 != '\n';
        x22522 = x22520;
      }
      bool x22523 = x22522;
      if (!x22523) break;
      int x22525 = x22514;
      int x22527 = x22489;
      int x22526 = x22525 * 10;
      char x22528 = x3368[x22527];
      char x22529 = x22528 - '0';
      int x22530 = x22526 + x22529;
      x22514 = x22530;
      x22489 = x22489 + 1;
    }
    x22489 = x22489 + 1;
    int x22536 = x22514;
    for (;;) {
      int x22539 = x22489;
      char x22540 = x3368[x22539];
      bool x22541 = x22540 != '|';
      bool x22546 = x22541;
      if (x22541) {
        int x22542 = x22489;
        char x22543 = x3368[x22542];
        bool x22544 = x22543 != '\n';
        x22546 = x22544;
      }
      bool x22547 = x22546;
      if (!x22547) break;
      x22489 = x22489 + 1;
    }
    x22489 = x22489 + 1;
    x22489 = x22489 + 2;
    for (;;) {
      int x22567 = x22489;
      char x22568 = x3368[x22567];
      bool x22569 = x22568 != '.';
      bool x22574 = x22569;
      if (x22569) {
        int x22570 = x22489;
        char x22571 = x3368[x22570];
        bool x22572 = x22571 != '|';
        x22574 = x22572;
      }
      bool x22575 = x22574;
      bool x22580 = x22575;
      if (x22575) {
        int x22576 = x22489;
        char x22577 = x3368[x22576];
        bool x22578 = x22577 != '\n';
        x22580 = x22578;
      }
      bool x22581 = x22580;
      if (!x22581) break;
      x22489 = x22489 + 1;
    }
    int x22593 = x22489;
    char x22594 = x3368[x22593];
    bool x22595 = x22594 == '.';
    if (x22595) {
      x22489 = x22489 + 1;
      for (;;) {
        int x22597 = x22489;
        char x22598 = x3368[x22597];
        bool x22599 = x22598 != '|';
        bool x22604 = x22599;
        if (x22599) {
          int x22600 = x22489;
          char x22601 = x3368[x22600];
          bool x22602 = x22601 != '\n';
          x22604 = x22602;
        }
        bool x22605 = x22604;
        if (!x22605) break;
        x22489 = x22489 + 1;
      }
    } else {
    }
    x22489 = x22489 + 1;
    for (;;) {
      int x22631 = x22489;
      char x22632 = x3368[x22631];
      bool x22633 = x22632 != '-';
      bool x22638 = x22633;
      if (x22633) {
        int x22634 = x22489;
        char x22635 = x3368[x22634];
        bool x22636 = x22635 != '\n';
        x22638 = x22636;
      }
      bool x22639 = x22638;
      if (!x22639) break;
      x22489 = x22489 + 1;
    }
    x22489 = x22489 + 1;
    for (;;) {
      int x22655 = x22489;
      char x22656 = x3368[x22655];
      bool x22657 = x22656 != '-';
      bool x22662 = x22657;
      if (x22657) {
        int x22658 = x22489;
        char x22659 = x3368[x22658];
        bool x22660 = x22659 != '\n';
        x22662 = x22660;
      }
      bool x22663 = x22662;
      if (!x22663) break;
      x22489 = x22489 + 1;
    }
    x22489 = x22489 + 1;
    for (;;) {
      int x22679 = x22489;
      char x22680 = x3368[x22679];
      bool x22681 = x22680 != '|';
      bool x22686 = x22681;
      if (x22681) {
        int x22682 = x22489;
        char x22683 = x3368[x22682];
        bool x22684 = x22683 != '\n';
        x22686 = x22684;
      }
      bool x22687 = x22686;
      if (!x22687) break;
      x22489 = x22489 + 1;
    }
    x22489 = x22489 + 1;
    int x22705 = x22489;
    for (;;) {
      int x22706 = x22489;
      char x22707 = x3368[x22706];
      bool x22708 = x22707 != '|';
      bool x22713 = x22708;
      if (x22708) {
        int x22709 = x22489;
        char x22710 = x3368[x22709];
        bool x22711 = x22710 != '\n';
        x22713 = x22711;
      }
      bool x22714 = x22713;
      if (!x22714) break;
      x22489 = x22489 + 1;
    }
    x22489 = x22489 + 1;
    for (;;) {
      int x22724 = x22489;
      char x22725 = x3368[x22724];
      bool x22726 = x22725 != '|';
      bool x22731 = x22726;
      if (x22726) {
        int x22727 = x22489;
        char x22728 = x3368[x22727];
        bool x22729 = x22728 != '\n';
        x22731 = x22729;
      }
      bool x22732 = x22731;
      if (!x22732) break;
      x22489 = x22489 + 1;
    }
    x22489 = x22489 + 1;
    for (;;) {
      int x22743 = x22489;
      char x22744 = x3368[x22743];
      bool x22745 = x22744 != '|';
      bool x22750 = x22745;
      if (x22745) {
        int x22746 = x22489;
        char x22747 = x3368[x22746];
        bool x22748 = x22747 != '\n';
        x22750 = x22748;
      }
      bool x22751 = x22750;
      if (!x22751) break;
      x22489 = x22489 + 1;
    }
    x22489 = x22489 + 1;
    for (;;) {
      int x22766 = x22489;
      char x22767 = x3368[x22766];
      bool x22768 = x22767 != '|';
      bool x22773 = x22768;
      if (x22768) {
        int x22769 = x22489;
        char x22770 = x3368[x22769];
        bool x22771 = x22770 != '\n';
        x22773 = x22771;
      }
      bool x22774 = x22773;
      if (!x22774) break;
      x22489 = x22489 + 1;
    }
    x22489 = x22489 + 1;
    int x22784 = x22491;
    int x22785 = x22490;
    bool x22786 = x22784 == x22785;
    if (x22786) {
      int x22787 = x22785 * 4;
      x22490 = x22787;
      printf("buffer.resize %d\n",x22787);
      int* x22790 = x22493;
      int* x22791 = (int*)realloc(x22790,x22787 * sizeof(int));
      x22493 = x22791;
      char** x22805 = x22503;
      char** x22806 = (char**)realloc(x22805,x22787 * sizeof(char*));
      x22503 = x22806;
    } else {
    }
    int* x22819 = x22493;
    x22819[x22784] = x22536;
    char** x22829 = x22503;
    char* x22722 = x3368+x22705;
    x22829[x22784] = x22722;
    x22491 = x22491 + 1;
  }
  bool x972 = true == false;
  int x22840;
  for(x22840=0; x22840 < 5; x22840++) {
    bool x22841 = false;
    int x22842 = 0;
    bool x22843 = false;
    int x22844 = 0;
    int* x22847 = (int*)malloc(134217728 * sizeof(int));
    int* x22848 = x22847;
    char** x22857 = (char**)malloc(134217728 * sizeof(char*));
    char** x22858 = x22857;
    int x22865 = 0;
    int* x22866 = (int*)malloc(67108864 * sizeof(int));
    int* x22867 = (int*)malloc(134217728 * sizeof(int));
    int x22868;
    for(x22868=0; x22868 < 67108864; x22868++) {
      x22866[x22868] = -1;
    }
    struct Anon984006423* x22874 = (struct Anon984006423*)malloc(16777216 * sizeof(struct Anon984006423));
    struct Anon984006423* x22875 = x22874;
    int x22876 = 0;
    int* x22877 = (int*)malloc(16777216 * sizeof(int));
    int x22878;
    for(x22878=0; x22878 < 16777216; x22878++) {
      struct Anon984006423* x22879 = x22875;
      struct Anon984006423 x22880 = x22879[x22878];
      char* x22881 = x22880.key;;
      struct Anon189208763 x22882 = x22880.aggs;;
      struct Anon984006423 x22883;
      x22883.exists = false;
      x22883.key = x22881;
      x22883.aggs = x22882;
      x22879[x22878] = x22883;
    }
    int x22888 = 0;
    struct timeval x23170, x23171, x23172;
    gettimeofday(&x23170, NULL);
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x22890 = x22841;
      bool x22891 = !x22890;
      bool x22896 = x22891;
      if (x22891) {
        int x22892 = x22842;
        int x22893 = x22491;
        bool x22894 = x22892 < x22893;
        x22896 = x22894;
      }
      bool x22897 = x22896;
      if (!x22897) break;
      int x22899 = x22842;
      int* x22900 = x22493;
      int x22901 = x22900[x22899];
      char** x22910 = x22503;
      char* x22911 = x22910[x22899];
      x22842 = x22842 + 1;
      int x22920 = x22865;
      int* x22921 = x22848;
      x22921[x22920] = x22901;
      char** x22931 = x22858;
      x22931[x22920] = x22911;
      x22865 = x22865 + 1;
      int x22940 = x22901 & 67108863;
      int x22941 = x22866[x22940];
      x22866[x22940] = x22920;
      x22867[x22920] = x22941;
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x22947 = x22843;
      bool x22948 = !x22947;
      bool x22953 = x22948;
      if (x22948) {
        int x22949 = x22844;
        int x22950 = x21717;
        bool x22951 = x22949 < x22950;
        x22953 = x22951;
      }
      bool x22954 = x22953;
      if (!x22954) break;
      int x22956 = x22844;
      int* x22957 = x21719;
      int x22958 = x22957[x22956];
      long* x22977 = x21739;
      long x22978 = x22977[x22956];
      long* x22979 = x21741;
      long x22980 = x22979[x22956];
      long* x22981 = x21743;
      long x22982 = x22981[x22956];
      char** x22985 = x21747;
      char* x22986 = x22985[x22956];
      x22844 = x22844 + 1;
      bool x22991 = x22982 < 19950101L;
      bool x22993 = x22991;
      if (x22991) {
        bool x22992 = x22980 < 19950101L;
        x22993 = x22992;
      }
      bool x22994 = x22993;
      bool x22996 = x22994;
      if (x22994) {
        bool x22995 = x22978 < 19950101L;
        x22996 = x22995;
      }
      bool x22997 = x22996;
      bool x22999 = x22997;
      if (x22997) {
        bool x22998 = x22978 < x22980;
        x22999 = x22998;
      }
      bool x23000 = x22999;
      bool x23002 = x23000;
      if (x23000) {
        bool x23001 = x22980 < x22982;
        x23002 = x23001;
      }
      bool x23003 = x23002;
      bool x23005 = x23003;
      if (x23003) {
        bool x23004 = x22982 >= 19940101L;
        x23005 = x23004;
      }
      bool x23006 = x23005;
      bool x23011 = x23006;
      if (x23006) {
        bool x23007 = strcmp(x22986,"MAIL") == 0;;
        bool x23009 = x23007;
        if (x23007 == false) {
          bool x23008 = strcmp(x22986,"SHIP") == 0;;
          x23009 = x23008;
        }
        bool x23010 = x23009;
        x23011 = x23010;
      }
      bool x23012 = x23011;
      if (x23012) {
        int x23013 = x22958 & 67108863;
        int x23014 = x22866[x23013];
        int x23015 = x23014;
        char x23045 = x22986[0];
        int x23046 = x23045 * 41;
        char x23047 = x22986[1];
        int x23048 = x23046 + x23047;
        int x23049 = x23048 * 41;
        char x23050 = x22986[2];
        int x23051 = x23049 + x23050;
        int x23052 = x23051 * 41;
        char x23053 = x22986[3];
        int x23054 = x23052 + x23053;
        int x23055 = x23054 & 16777215;
        for (;;) {
          int x23016 = x23015;
          bool x23017 = x23016 != -1;
          if (!x23017) break;
          int x23019 = x23015;
          int* x23020 = x22848;
          int x23021 = x23020[x23019];
          char** x23030 = x22858;
          char* x23031 = x23030[x23019];
          int x23039 = x22867[x23019];
          x23015 = x23039;
          bool x23041 = x23021 == x22958;
          if (x23041) {
            int x23056 = x23055;
            struct Anon984006423* x23057 = x22875;
            struct Anon984006423 x23058 = x23057[x23055];
            struct Anon984006423 x23059 = x23058;
            bool x23060 = x23058.exists;;
            bool x23065 = x23060;
            if (x23060) {
              struct Anon984006423 x23061 = x23059;
              char* x23062 = x23061.key;;
              bool x23063 = strcmp(x23062,x22986) == 0;;
              x23065 = x23063;
            }
            bool x23066 = x23065;
            if (x23066) {
              struct Anon189208763 x23067 = x23058.aggs;;
              char* x23083 = x23058.key;;
              bool x23068 = strcmp(x23031,"1-URGENT") == 0;;
              bool x23070 = x23068;
              if (x23068 == false) {
                bool x23069 = strcmp(x23031,"2-HIGH") == 0;;
                x23070 = x23069;
              }
              bool x23071 = x23070;
              double x23074;
              if (x23071) {
                double x23072 = x23067._0;;
                double x23073 = x23072 + 1.0;
                x23074 = x23073;
              } else {
                double x23072 = x23067._0;;
                x23074 = x23072;
              }
              bool x23075 = strcmp(x23031,"1-URGENT") != 0;;
              bool x23077 = x23075;
              if (x23075) {
                bool x23076 = strcmp(x23031,"2-HIGH") != 0;;
                x23077 = x23076;
              }
              bool x23078 = x23077;
              double x23081;
              if (x23078) {
                double x23079 = x23067._1;;
                double x23080 = x23079 + 1.0;
                x23081 = x23080;
              } else {
                double x23079 = x23067._1;;
                x23081 = x23079;
              }
              struct Anon189208763 x23082;
              x23082._0 = x23074;
              x23082._1 = x23081;
              struct Anon984006423 x23084;
              x23084.exists = true;
              x23084.key = x23083;
              x23084.aggs = x23082;
              x23057[x23055] = x23084;
            } else {
              bool x23068 = strcmp(x23031,"1-URGENT") == 0;;
              bool x23070 = x23068;
              if (x23068 == false) {
                bool x23069 = strcmp(x23031,"2-HIGH") == 0;;
                x23070 = x23069;
              }
              bool x23071 = x23070;
              bool x23075 = strcmp(x23031,"1-URGENT") != 0;;
              bool x23077 = x23075;
              if (x23075) {
                bool x23076 = strcmp(x23031,"2-HIGH") != 0;;
                x23077 = x23076;
              }
              bool x23078 = x23077;
              double x23120;
              if (x23071) {
                x23120 = 1.0;
              } else {
                x23120 = 0.0;
              }
              double x23122;
              if (x23078) {
                x23122 = 1.0;
              } else {
                x23122 = 0.0;
              }
              struct Anon189208763 x23123;
              x23123._0 = x23120;
              x23123._1 = x23122;
              struct Anon984006423 x23124;
              x23124.exists = true;
              x23124.key = x22986;
              x23124.aggs = x23123;
              for (;;) {
                struct Anon984006423 x23087 = x23059;
                bool x23088 = x23087.exists;;
                bool x23133;
                if (x23088) {
                  char* x23089 = x23087.key;;
                  bool x23090 = strcmp(x23089,x22986) == 0;;
                  bool x23116;
                  if (x23090) {
                    struct Anon189208763 x23091 = x23087.aggs;;
                    int x23101 = x23056;
                    struct Anon984006423* x23103 = x22875;
                    double x23095;
                    if (x23071) {
                      double x23093 = x23091._0;;
                      double x23094 = x23093 + 1.0;
                      x23095 = x23094;
                    } else {
                      double x23093 = x23091._0;;
                      x23095 = x23093;
                    }
                    double x23099;
                    if (x23078) {
                      double x23097 = x23091._1;;
                      double x23098 = x23097 + 1.0;
                      x23099 = x23098;
                    } else {
                      double x23097 = x23091._1;;
                      x23099 = x23097;
                    }
                    struct Anon189208763 x23100;
                    x23100._0 = x23095;
                    x23100._1 = x23099;
                    struct Anon984006423 x23102;
                    x23102.exists = true;
                    x23102.key = x23089;
                    x23102.aggs = x23100;
                    x23103[x23101] = x23102;
                    x23116 = false;
                  } else {
                    int x23106 = x23056;
                    int x23107 = x23106 + 1;
                    int x23108 = x23107 % 16777215;
                    x23056 = x23108;
                    struct Anon984006423* x23110 = x22875;
                    struct Anon984006423 x23111 = x23110[x23108];
                    x23059 = x23111;
                    x23116 = true;
                  }
                  x23133 = x23116;
                } else {
                  int x23118 = x23056;
                  struct Anon984006423* x23125 = x22875;
                  x23125[x23118] = x23124;
                  int x23127 = x22876;
                  x22877[x23127] = x23118;
                  x22876 = x22876 + 1;
                  x23133 = false;
                }
                if (!x23133) break;
              }
            }
          } else {
          }
        }
      } else {
      }
    }
    int x23148 = x22876;
    int x23150;
    for(x23150=0; x23150 < x23148; x23150++) {
      int x23151 = x22877[x23150];
      struct Anon984006423* x23152 = x22875;
      struct Anon984006423 x23153 = x23152[x23151];
      if (x972) {
      } else {
        char* x23156 = x23153.key;;
        struct Anon189208763 x23158 = x23153.aggs;;
        int x23157 = strlen(x23156);
        double x23159 = x23158._0;;
        double x23160 = x23158._1;;
        printf("%.*s|%.0f|%.0f\n",x23157,x23156,x23159,x23160);
        x22888 = x22888 + 1;
      }
    }
    int x23167 = x22888;
    printf("(%d rows)\n",x23167);
    gettimeofday(&x23171, NULL);
    timeval_subtract(&x23172, &x23171, &x23170);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x23172.tv_sec * 1000) + (x23172.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
