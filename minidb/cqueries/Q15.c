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

      // buffer and hashtable sizes
      #define DEFAULT_INPUT_SIZE      (1L << 20)
      #define DEFAULT_VIEW_SIZE       (1L << 20)
      #define DEFAULT_AGG_HASH_SIZE   (1L << 24)
      #define DEFAULT_JOIN_HASH_SIZE  (1L << 26)


      long fsize(int fd) {
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

struct Anon842992833 {
bool exists;
int key;
struct Anon1023322325 aggs;
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

struct Anon1548200872 {
char* NATION;
int O_YEAR;
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

struct Anon726278688 {
char* SUPP_NATION;
char* CUST_NATION;
int L_YEAR;
};

struct Anon2052879266 {
double _0;
};

struct Anon1587544425 {
bool exists;
struct Anon726278688 key;
struct Anon2052879266 aggs;
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

struct Anon1858713264 {
int key;
struct Anon2052879266 aggs;
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

struct Anon532638341 {
bool exists;
struct Anon1465150758 key;
struct Anon2052879266 aggs;
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

struct Anon1506628547 {
bool exists;
struct Anon1548200872 key;
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

struct Anon1285873738 {
int key;
struct Anon1023322325 wnd;
};

struct Anon2052879268 {
double _2;
};

struct Anon1735189454 {
int key;
struct Anon2052879268 aggs;
};

struct Anon1996247276 {
bool exists;
int key;
struct Anon2052879266 aggs;
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

struct Anon0 {
struct Anon1268892766 left;
struct Anon1858713264 right;
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

struct Anon1268892766Anon1858713264 {
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

struct Anon625264174 {
char L_RETURNFLAG;
char L_LINESTATUS;
};

struct Anon1931420570 {
bool exists;
struct Anon625264174 key;
struct Anon567626277 aggs;
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

struct Anon1074264013 {
bool exists;
int key;
struct Anon189208763 aggs;
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

struct Anon2025517469 {
bool exists;
char* key;
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

struct Anon56555318 {
bool exists;
double key;
struct Anon2052879266 aggs;
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

struct Anon1711779607 {
int C_CUSTKEY;
char* C_NAME;
double C_ACCTBAL;
char* C_PHONE;
char* N_NAME;
char* C_ADDRESS;
char* C_COMMENT;
};

struct Anon2041993102 {
bool exists;
struct Anon1711779607 key;
struct Anon2052879266 aggs;
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

struct Anon1519494783 {
struct Anon625264174 key;
struct Anon1296044246 aggs;
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

struct Anon801061462 {
bool exists;
char* key;
struct Anon2052879266 aggs;
};

/************************ FUNCTIONS **************************/

/************************ MAIN BODY **************************/
int main(int x25630, char** x25631) {
  long x25632 = 0L;
  long x6 = DEFAULT_INPUT_SIZE;
  long x25633 = x6;
  long x25634 = 0L;
  int* x25639 = (int*)malloc(x6 * sizeof(int));
  int* x25640 = x25639;
  double* x25645 = (double*)malloc(x6 * sizeof(double));
  double* x25646 = x25645;
  double* x25647 = (double*)malloc(x6 * sizeof(double));
  double* x25648 = x25647;
  long* x25655 = (long*)malloc(x6 * sizeof(long));
  long* x25656 = x25655;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  long x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    long x25667 = x25632;
    bool x25668 = x25667 < x3;
    if (!x25668) break;
    for (;;) {
      long x25672 = x25632;
      char x25673 = x4[x25672];
      bool x25674 = x25673 != '|';
      bool x25679 = x25674;
      if (x25674) {
        long x25675 = x25632;
        char x25676 = x4[x25675];
        bool x25677 = x25676 != '\n';
        x25679 = x25677;
      }
      bool x25680 = x25679;
      if (!x25680) break;
      x25632 = x25632 + 1;
    }
    x25632 = x25632 + 1;
    for (;;) {
      long x25696 = x25632;
      char x25697 = x4[x25696];
      bool x25698 = x25697 != '|';
      bool x25703 = x25698;
      if (x25698) {
        long x25699 = x25632;
        char x25700 = x4[x25699];
        bool x25701 = x25700 != '\n';
        x25703 = x25701;
      }
      bool x25704 = x25703;
      if (!x25704) break;
      x25632 = x25632 + 1;
    }
    x25632 = x25632 + 1;
    int x25719 = 0;
    for (;;) {
      long x25720 = x25632;
      char x25721 = x4[x25720];
      bool x25722 = x25721 != '|';
      bool x25727 = x25722;
      if (x25722) {
        long x25723 = x25632;
        char x25724 = x4[x25723];
        bool x25725 = x25724 != '\n';
        x25727 = x25725;
      }
      bool x25728 = x25727;
      if (!x25728) break;
      int x25730 = x25719;
      long x25732 = x25632;
      int x25731 = x25730 * 10;
      char x25733 = x4[x25732];
      char x25734 = x25733 - '0';
      int x25735 = x25731 + x25734;
      x25719 = x25735;
      x25632 = x25632 + 1;
    }
    x25632 = x25632 + 1;
    int x25741 = x25719;
    for (;;) {
      long x25744 = x25632;
      char x25745 = x4[x25744];
      bool x25746 = x25745 != '|';
      bool x25751 = x25746;
      if (x25746) {
        long x25747 = x25632;
        char x25748 = x4[x25747];
        bool x25749 = x25748 != '\n';
        x25751 = x25749;
      }
      bool x25752 = x25751;
      if (!x25752) break;
      x25632 = x25632 + 1;
    }
    x25632 = x25632 + 1;
    for (;;) {
      long x25769 = x25632;
      char x25770 = x4[x25769];
      bool x25771 = x25770 != '.';
      bool x25776 = x25771;
      if (x25771) {
        long x25772 = x25632;
        char x25773 = x4[x25772];
        bool x25774 = x25773 != '|';
        x25776 = x25774;
      }
      bool x25777 = x25776;
      bool x25782 = x25777;
      if (x25777) {
        long x25778 = x25632;
        char x25779 = x4[x25778];
        bool x25780 = x25779 != '\n';
        x25782 = x25780;
      }
      bool x25783 = x25782;
      if (!x25783) break;
      x25632 = x25632 + 1;
    }
    long x25795 = x25632;
    char x25796 = x4[x25795];
    bool x25797 = x25796 == '.';
    if (x25797) {
      x25632 = x25632 + 1;
      for (;;) {
        long x25799 = x25632;
        char x25800 = x4[x25799];
        bool x25801 = x25800 != '|';
        bool x25806 = x25801;
        if (x25801) {
          long x25802 = x25632;
          char x25803 = x4[x25802];
          bool x25804 = x25803 != '\n';
          x25806 = x25804;
        }
        bool x25807 = x25806;
        if (!x25807) break;
        x25632 = x25632 + 1;
      }
    } else {
    }
    x25632 = x25632 + 1;
    int x25832 = 0;
    int x25833 = 1;
    for (;;) {
      long x25834 = x25632;
      char x25835 = x4[x25834];
      bool x25836 = x25835 != '.';
      bool x25841 = x25836;
      if (x25836) {
        long x25837 = x25632;
        char x25838 = x4[x25837];
        bool x25839 = x25838 != '|';
        x25841 = x25839;
      }
      bool x25842 = x25841;
      bool x25847 = x25842;
      if (x25842) {
        long x25843 = x25632;
        char x25844 = x4[x25843];
        bool x25845 = x25844 != '\n';
        x25847 = x25845;
      }
      bool x25848 = x25847;
      if (!x25848) break;
      int x25850 = x25832;
      long x25852 = x25632;
      int x25851 = x25850 * 10;
      char x25853 = x4[x25852];
      char x25854 = x25853 - '0';
      int x25855 = x25851 + x25854;
      x25832 = x25855;
      x25632 = x25632 + 1;
    }
    long x25860 = x25632;
    char x25861 = x4[x25860];
    bool x25862 = x25861 == '.';
    if (x25862) {
      x25632 = x25632 + 1;
      for (;;) {
        long x25864 = x25632;
        char x25865 = x4[x25864];
        bool x25866 = x25865 != '|';
        bool x25871 = x25866;
        if (x25866) {
          long x25867 = x25632;
          char x25868 = x4[x25867];
          bool x25869 = x25868 != '\n';
          x25871 = x25869;
        }
        bool x25872 = x25871;
        if (!x25872) break;
        int x25874 = x25832;
        long x25876 = x25632;
        int x25875 = x25874 * 10;
        char x25877 = x4[x25876];
        char x25878 = x25877 - '0';
        int x25879 = x25875 + x25878;
        x25832 = x25879;
        int x25881 = x25833;
        int x25882 = x25881 * 10;
        x25833 = x25882;
        x25632 = x25632 + 1;
      }
    } else {
    }
    x25632 = x25632 + 1;
    int x25891 = x25832;
    int x25893 = x25833;
    int x25897 = 0;
    int x25898 = 1;
    for (;;) {
      long x25899 = x25632;
      char x25900 = x4[x25899];
      bool x25901 = x25900 != '.';
      bool x25906 = x25901;
      if (x25901) {
        long x25902 = x25632;
        char x25903 = x4[x25902];
        bool x25904 = x25903 != '|';
        x25906 = x25904;
      }
      bool x25907 = x25906;
      bool x25912 = x25907;
      if (x25907) {
        long x25908 = x25632;
        char x25909 = x4[x25908];
        bool x25910 = x25909 != '\n';
        x25912 = x25910;
      }
      bool x25913 = x25912;
      if (!x25913) break;
      int x25915 = x25897;
      long x25917 = x25632;
      int x25916 = x25915 * 10;
      char x25918 = x4[x25917];
      char x25919 = x25918 - '0';
      int x25920 = x25916 + x25919;
      x25897 = x25920;
      x25632 = x25632 + 1;
    }
    long x25925 = x25632;
    char x25926 = x4[x25925];
    bool x25927 = x25926 == '.';
    if (x25927) {
      x25632 = x25632 + 1;
      for (;;) {
        long x25929 = x25632;
        char x25930 = x4[x25929];
        bool x25931 = x25930 != '|';
        bool x25936 = x25931;
        if (x25931) {
          long x25932 = x25632;
          char x25933 = x4[x25932];
          bool x25934 = x25933 != '\n';
          x25936 = x25934;
        }
        bool x25937 = x25936;
        if (!x25937) break;
        int x25939 = x25897;
        long x25941 = x25632;
        int x25940 = x25939 * 10;
        char x25942 = x4[x25941];
        char x25943 = x25942 - '0';
        int x25944 = x25940 + x25943;
        x25897 = x25944;
        int x25946 = x25898;
        int x25947 = x25946 * 10;
        x25898 = x25947;
        x25632 = x25632 + 1;
      }
    } else {
    }
    x25632 = x25632 + 1;
    int x25956 = x25897;
    int x25958 = x25898;
    for (;;) {
      long x25964 = x25632;
      char x25965 = x4[x25964];
      bool x25966 = x25965 != '.';
      bool x25971 = x25966;
      if (x25966) {
        long x25967 = x25632;
        char x25968 = x4[x25967];
        bool x25969 = x25968 != '|';
        x25971 = x25969;
      }
      bool x25972 = x25971;
      bool x25977 = x25972;
      if (x25972) {
        long x25973 = x25632;
        char x25974 = x4[x25973];
        bool x25975 = x25974 != '\n';
        x25977 = x25975;
      }
      bool x25978 = x25977;
      if (!x25978) break;
      x25632 = x25632 + 1;
    }
    long x25990 = x25632;
    char x25991 = x4[x25990];
    bool x25992 = x25991 == '.';
    if (x25992) {
      x25632 = x25632 + 1;
      for (;;) {
        long x25994 = x25632;
        char x25995 = x4[x25994];
        bool x25996 = x25995 != '|';
        bool x26001 = x25996;
        if (x25996) {
          long x25997 = x25632;
          char x25998 = x4[x25997];
          bool x25999 = x25998 != '\n';
          x26001 = x25999;
        }
        bool x26002 = x26001;
        if (!x26002) break;
        x25632 = x25632 + 1;
      }
    } else {
    }
    x25632 = x25632 + 1;
    x25632 = x25632 + 2;
    x25632 = x25632 + 2;
    int x26033 = 0;
    for (;;) {
      long x26034 = x25632;
      char x26035 = x4[x26034];
      bool x26036 = x26035 != '-';
      bool x26041 = x26036;
      if (x26036) {
        long x26037 = x25632;
        char x26038 = x4[x26037];
        bool x26039 = x26038 != '\n';
        x26041 = x26039;
      }
      bool x26042 = x26041;
      if (!x26042) break;
      int x26044 = x26033;
      long x26046 = x25632;
      int x26045 = x26044 * 10;
      char x26047 = x4[x26046];
      char x26048 = x26047 - '0';
      int x26049 = x26045 + x26048;
      x26033 = x26049;
      x25632 = x25632 + 1;
    }
    x25632 = x25632 + 1;
    int x26055 = x26033;
    int x26057 = 0;
    for (;;) {
      long x26058 = x25632;
      char x26059 = x4[x26058];
      bool x26060 = x26059 != '-';
      bool x26065 = x26060;
      if (x26060) {
        long x26061 = x25632;
        char x26062 = x4[x26061];
        bool x26063 = x26062 != '\n';
        x26065 = x26063;
      }
      bool x26066 = x26065;
      if (!x26066) break;
      int x26068 = x26057;
      long x26070 = x25632;
      int x26069 = x26068 * 10;
      char x26071 = x4[x26070];
      char x26072 = x26071 - '0';
      int x26073 = x26069 + x26072;
      x26057 = x26073;
      x25632 = x25632 + 1;
    }
    x25632 = x25632 + 1;
    int x26079 = x26057;
    int x26081 = 0;
    for (;;) {
      long x26082 = x25632;
      char x26083 = x4[x26082];
      bool x26084 = x26083 != '|';
      bool x26089 = x26084;
      if (x26084) {
        long x26085 = x25632;
        char x26086 = x4[x26085];
        bool x26087 = x26086 != '\n';
        x26089 = x26087;
      }
      bool x26090 = x26089;
      if (!x26090) break;
      int x26092 = x26081;
      long x26094 = x25632;
      int x26093 = x26092 * 10;
      char x26095 = x4[x26094];
      char x26096 = x26095 - '0';
      int x26097 = x26093 + x26096;
      x26081 = x26097;
      x25632 = x25632 + 1;
    }
    x25632 = x25632 + 1;
    int x26103 = x26081;
    for (;;) {
      long x26110 = x25632;
      char x26111 = x4[x26110];
      bool x26112 = x26111 != '-';
      bool x26117 = x26112;
      if (x26112) {
        long x26113 = x25632;
        char x26114 = x4[x26113];
        bool x26115 = x26114 != '\n';
        x26117 = x26115;
      }
      bool x26118 = x26117;
      if (!x26118) break;
      x25632 = x25632 + 1;
    }
    x25632 = x25632 + 1;
    for (;;) {
      long x26134 = x25632;
      char x26135 = x4[x26134];
      bool x26136 = x26135 != '-';
      bool x26141 = x26136;
      if (x26136) {
        long x26137 = x25632;
        char x26138 = x4[x26137];
        bool x26139 = x26138 != '\n';
        x26141 = x26139;
      }
      bool x26142 = x26141;
      if (!x26142) break;
      x25632 = x25632 + 1;
    }
    x25632 = x25632 + 1;
    for (;;) {
      long x26158 = x25632;
      char x26159 = x4[x26158];
      bool x26160 = x26159 != '|';
      bool x26165 = x26160;
      if (x26160) {
        long x26161 = x25632;
        char x26162 = x4[x26161];
        bool x26163 = x26162 != '\n';
        x26165 = x26163;
      }
      bool x26166 = x26165;
      if (!x26166) break;
      x25632 = x25632 + 1;
    }
    x25632 = x25632 + 1;
    for (;;) {
      long x26186 = x25632;
      char x26187 = x4[x26186];
      bool x26188 = x26187 != '-';
      bool x26193 = x26188;
      if (x26188) {
        long x26189 = x25632;
        char x26190 = x4[x26189];
        bool x26191 = x26190 != '\n';
        x26193 = x26191;
      }
      bool x26194 = x26193;
      if (!x26194) break;
      x25632 = x25632 + 1;
    }
    x25632 = x25632 + 1;
    for (;;) {
      long x26210 = x25632;
      char x26211 = x4[x26210];
      bool x26212 = x26211 != '-';
      bool x26217 = x26212;
      if (x26212) {
        long x26213 = x25632;
        char x26214 = x4[x26213];
        bool x26215 = x26214 != '\n';
        x26217 = x26215;
      }
      bool x26218 = x26217;
      if (!x26218) break;
      x25632 = x25632 + 1;
    }
    x25632 = x25632 + 1;
    for (;;) {
      long x26234 = x25632;
      char x26235 = x4[x26234];
      bool x26236 = x26235 != '|';
      bool x26241 = x26236;
      if (x26236) {
        long x26237 = x25632;
        char x26238 = x4[x26237];
        bool x26239 = x26238 != '\n';
        x26241 = x26239;
      }
      bool x26242 = x26241;
      if (!x26242) break;
      x25632 = x25632 + 1;
    }
    x25632 = x25632 + 1;
    for (;;) {
      long x26261 = x25632;
      char x26262 = x4[x26261];
      bool x26263 = x26262 != '|';
      bool x26268 = x26263;
      if (x26263) {
        long x26264 = x25632;
        char x26265 = x4[x26264];
        bool x26266 = x26265 != '\n';
        x26268 = x26266;
      }
      bool x26269 = x26268;
      if (!x26269) break;
      x25632 = x25632 + 1;
    }
    x25632 = x25632 + 1;
    for (;;) {
      long x26279 = x25632;
      char x26280 = x4[x26279];
      bool x26281 = x26280 != '|';
      bool x26286 = x26281;
      if (x26281) {
        long x26282 = x25632;
        char x26283 = x4[x26282];
        bool x26284 = x26283 != '\n';
        x26286 = x26284;
      }
      bool x26287 = x26286;
      if (!x26287) break;
      x25632 = x25632 + 1;
    }
    x25632 = x25632 + 1;
    for (;;) {
      long x26297 = x25632;
      char x26298 = x4[x26297];
      bool x26299 = x26298 != '|';
      bool x26304 = x26299;
      if (x26299) {
        long x26300 = x25632;
        char x26301 = x4[x26300];
        bool x26302 = x26301 != '\n';
        x26304 = x26302;
      }
      bool x26305 = x26304;
      if (!x26305) break;
      x25632 = x25632 + 1;
    }
    x25632 = x25632 + 1;
    long x26315 = x25634;
    long x26316 = x25633;
    bool x26317 = x26315 == x26316;
    if (x26317) {
      long x26318 = x26316 * 4L;
      x25633 = x26318;
      printf("buffer.resize %d\n",x26318);
      int* x26327 = x25640;
      int* x26328 = (int*)realloc(x26327,x26318 * sizeof(int));
      x25640 = x26328;
      double* x26336 = x25646;
      double* x26337 = (double*)realloc(x26336,x26318 * sizeof(double));
      x25646 = x26337;
      double* x26339 = x25648;
      double* x26340 = (double*)realloc(x26339,x26318 * sizeof(double));
      x25648 = x26340;
      long* x26351 = x25656;
      long* x26352 = (long*)realloc(x26351,x26318 * sizeof(long));
      x25656 = x26352;
    } else {
    }
    int* x26375 = x25640;
    x26375[x26315] = x25741;
    double* x26381 = x25646;
    double x25892 = (double)x25891;
    double x25894 = (double)x25893;
    double x25895 = x25892 / x25894;
    x26381[x26315] = x25895;
    double* x26383 = x25648;
    double x25957 = (double)x25956;
    double x25959 = (double)x25958;
    double x25960 = x25957 / x25959;
    x26383[x26315] = x25960;
    long* x26391 = x25656;
    long x26104 = x26055 * 10000L;
    long x26105 = x26079 * 100L;
    long x26106 = x26104 + x26105;
    long x26107 = x26106 + x26103;
    x26391[x26315] = x26107;
    x25634 = x25634 + 1;
  }
  long x26406 = 0L;
  long x26407 = x6;
  long x26408 = 0L;
  int* x26409 = (int*)malloc(x6 * sizeof(int));
  int* x26410 = x26409;
  char** x26411 = (char**)malloc(x6 * sizeof(char*));
  char** x26412 = x26411;
  char** x26413 = (char**)malloc(x6 * sizeof(char*));
  char** x26414 = x26413;
  char** x26417 = (char**)malloc(x6 * sizeof(char*));
  char** x26418 = x26417;
  int x1750 = open("../databases/sf2/supplier.tbl",0);
  long x1751 = fsize(x1750);
  char* x1752 = mmap(0, x1751, PROT_READ, MAP_FILE | MAP_SHARED, x1750, 0);
  for (;;) {
    long x26423 = x26406;
    bool x26424 = x26423 < x1751;
    if (!x26424) break;
    int x26427 = 0;
    for (;;) {
      long x26428 = x26406;
      char x26429 = x1752[x26428];
      bool x26430 = x26429 != '|';
      bool x26435 = x26430;
      if (x26430) {
        long x26431 = x26406;
        char x26432 = x1752[x26431];
        bool x26433 = x26432 != '\n';
        x26435 = x26433;
      }
      bool x26436 = x26435;
      if (!x26436) break;
      int x26438 = x26427;
      long x26440 = x26406;
      int x26439 = x26438 * 10;
      char x26441 = x1752[x26440];
      char x26442 = x26441 - '0';
      int x26443 = x26439 + x26442;
      x26427 = x26443;
      x26406 = x26406 + 1;
    }
    x26406 = x26406 + 1;
    int x26449 = x26427;
    long x26450 = x26406;
    for (;;) {
      long x26451 = x26406;
      char x26452 = x1752[x26451];
      bool x26453 = x26452 != '|';
      bool x26458 = x26453;
      if (x26453) {
        long x26454 = x26406;
        char x26455 = x1752[x26454];
        bool x26456 = x26455 != '\n';
        x26458 = x26456;
      }
      bool x26459 = x26458;
      if (!x26459) break;
      x26406 = x26406 + 1;
    }
    x26406 = x26406 + 1;
    long x26468 = x26406;
    for (;;) {
      long x26469 = x26406;
      char x26470 = x1752[x26469];
      bool x26471 = x26470 != '|';
      bool x26476 = x26471;
      if (x26471) {
        long x26472 = x26406;
        char x26473 = x1752[x26472];
        bool x26474 = x26473 != '\n';
        x26476 = x26474;
      }
      bool x26477 = x26476;
      if (!x26477) break;
      x26406 = x26406 + 1;
    }
    x26406 = x26406 + 1;
    for (;;) {
      long x26488 = x26406;
      char x26489 = x1752[x26488];
      bool x26490 = x26489 != '|';
      bool x26495 = x26490;
      if (x26490) {
        long x26491 = x26406;
        char x26492 = x1752[x26491];
        bool x26493 = x26492 != '\n';
        x26495 = x26493;
      }
      bool x26496 = x26495;
      if (!x26496) break;
      x26406 = x26406 + 1;
    }
    x26406 = x26406 + 1;
    long x26510 = x26406;
    for (;;) {
      long x26511 = x26406;
      char x26512 = x1752[x26511];
      bool x26513 = x26512 != '|';
      bool x26518 = x26513;
      if (x26513) {
        long x26514 = x26406;
        char x26515 = x1752[x26514];
        bool x26516 = x26515 != '\n';
        x26518 = x26516;
      }
      bool x26519 = x26518;
      if (!x26519) break;
      x26406 = x26406 + 1;
    }
    x26406 = x26406 + 1;
    for (;;) {
      long x26531 = x26406;
      char x26532 = x1752[x26531];
      bool x26533 = x26532 != '.';
      bool x26538 = x26533;
      if (x26533) {
        long x26534 = x26406;
        char x26535 = x1752[x26534];
        bool x26536 = x26535 != '|';
        x26538 = x26536;
      }
      bool x26539 = x26538;
      bool x26544 = x26539;
      if (x26539) {
        long x26540 = x26406;
        char x26541 = x1752[x26540];
        bool x26542 = x26541 != '\n';
        x26544 = x26542;
      }
      bool x26545 = x26544;
      if (!x26545) break;
      x26406 = x26406 + 1;
    }
    long x26557 = x26406;
    char x26558 = x1752[x26557];
    bool x26559 = x26558 == '.';
    if (x26559) {
      x26406 = x26406 + 1;
      for (;;) {
        long x26561 = x26406;
        char x26562 = x1752[x26561];
        bool x26563 = x26562 != '|';
        bool x26568 = x26563;
        if (x26563) {
          long x26564 = x26406;
          char x26565 = x1752[x26564];
          bool x26566 = x26565 != '\n';
          x26568 = x26566;
        }
        bool x26569 = x26568;
        if (!x26569) break;
        x26406 = x26406 + 1;
      }
    } else {
    }
    x26406 = x26406 + 1;
    for (;;) {
      long x26594 = x26406;
      char x26595 = x1752[x26594];
      bool x26596 = x26595 != '|';
      bool x26601 = x26596;
      if (x26596) {
        long x26597 = x26406;
        char x26598 = x1752[x26597];
        bool x26599 = x26598 != '\n';
        x26601 = x26599;
      }
      bool x26602 = x26601;
      if (!x26602) break;
      x26406 = x26406 + 1;
    }
    x26406 = x26406 + 1;
    long x26612 = x26408;
    long x26613 = x26407;
    bool x26614 = x26612 == x26613;
    if (x26614) {
      long x26615 = x26613 * 4L;
      x26407 = x26615;
      printf("buffer.resize %d\n",x26615);
      int* x26618 = x26410;
      int* x26619 = (int*)realloc(x26618,x26615 * sizeof(int));
      x26410 = x26619;
      char** x26621 = x26412;
      char** x26622 = (char**)realloc(x26621,x26615 * sizeof(char*));
      x26412 = x26622;
      char** x26624 = x26414;
      char** x26625 = (char**)realloc(x26624,x26615 * sizeof(char*));
      x26414 = x26625;
      char** x26630 = x26418;
      char** x26631 = (char**)realloc(x26630,x26615 * sizeof(char*));
      x26418 = x26631;
    } else {
    }
    int* x26641 = x26410;
    x26641[x26612] = x26449;
    char** x26643 = x26412;
    char* x26467 = x1752+x26450;
    x26643[x26612] = x26467;
    char** x26645 = x26414;
    char* x26485 = x1752+x26468;
    x26645[x26612] = x26485;
    char** x26649 = x26418;
    char* x26527 = x1752+x26510;
    x26649[x26612] = x26527;
    x26408 = x26408 + 1;
  }
  long x787 = DEFAULT_AGG_HASH_SIZE ;
  long x21273 = DEFAULT_VIEW_SIZE;
  long x2011 = DEFAULT_JOIN_HASH_SIZE;
  long x802 = x787 - 1L;
  long x2034 = x2011 - 1L;
  char x26948 = "MAXREVENUE"[0L];
  long x26949 = x26948 * 41L;
  char x26950 = "MAXREVENUE"[1L];
  long x26951 = x26949 + x26950;
  long x26952 = x26951 * 41L;
  char x26953 = "MAXREVENUE"[2L];
  long x26954 = x26952 + x26953;
  long x26955 = x26954 * 41L;
  char x26956 = "MAXREVENUE"[3L];
  long x26957 = x26955 + x26956;
  long x26958 = x26957 & x802;
  bool x975 = true == false;
  int x26658;
  for(x26658=0; x26658 < 5; x26658++) {
    bool x26659 = false;
    long x26660 = 0L;
    struct Anon1996247276* x26663 = (struct Anon1996247276*)malloc(x787 * sizeof(struct Anon1996247276));
    struct Anon1996247276* x26664 = x26663;
    long x26665 = 0L;
    long* x26666 = (long*)malloc(x787 * sizeof(long));
    long x26667;
    for(x26667=0L; x26667 < x787; x26667++) {
      struct Anon1996247276* x26668 = x26664;
      struct Anon1996247276 x26669 = x26668[x26667];
      int x26670 = x26669.key;;
      struct Anon2052879266 x26671 = x26669.aggs;;
      struct Anon1996247276 x26672;
      x26672.exists = false;
      x26672.key = x26670;
      x26672.aggs = x26671;
      x26668[x26667] = x26672;
    }
    long x26677 = x21273;
    long x26678 = 0L;
    int* x26681 = (int*)malloc(x21273 * sizeof(int));
    int* x26682 = x26681;
    double* x26683 = (double*)malloc(x21273 * sizeof(double));
    double* x26684 = x26683;
    struct Anon801061462* x26688 = (struct Anon801061462*)malloc(x787 * sizeof(struct Anon801061462));
    struct Anon801061462* x26689 = x26688;
    long x26690 = 0L;
    long* x26691 = (long*)malloc(x787 * sizeof(long));
    long x26692;
    for(x26692=0L; x26692 < x787; x26692++) {
      struct Anon801061462* x26693 = x26689;
      struct Anon801061462 x26694 = x26693[x26692];
      char* x26695 = x26694.key;;
      struct Anon2052879266 x26696 = x26694.aggs;;
      struct Anon801061462 x26697;
      x26697.exists = false;
      x26697.key = x26695;
      x26697.aggs = x26696;
      x26693[x26692] = x26697;
    }
    double x26703 = 0.0;
    bool x26706 = false;
    long x26707 = 0L;
    int* x26709 = (int*)malloc(x2011 * sizeof(int));
    int* x26710 = x26709;
    char** x26711 = (char**)malloc(x2011 * sizeof(char*));
    char** x26712 = x26711;
    char** x26713 = (char**)malloc(x2011 * sizeof(char*));
    char** x26714 = x26713;
    char** x26717 = (char**)malloc(x2011 * sizeof(char*));
    char** x26718 = x26717;
    long x26723 = 0L;
    long* x26724 = (long*)malloc(x2011 * sizeof(long));
    long* x26725 = (long*)malloc(x2011 * sizeof(long));
    long x26726;
    for(x26726=0L; x26726 < x2011; x26726++) {
      x26724[x26726] = -1L;
    }
    long x26732 = 0L;
    struct timeval x27103, x27104, x27105;
    gettimeofday(&x27103, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x26734 = x26659;
      bool x26735 = !x26734;
      bool x26740 = x26735;
      if (x26735) {
        long x26736 = x26660;
        long x26737 = x25634;
        bool x26738 = x26736 < x26737;
        x26740 = x26738;
      }
      bool x26741 = x26740;
      if (!x26741) break;
      long x26743 = x26660;
      int* x26748 = x25640;
      int x26749 = x26748[x26743];
      double* x26754 = x25646;
      double x26755 = x26754[x26743];
      double* x26756 = x25648;
      double x26757 = x26756[x26743];
      long* x26764 = x25656;
      long x26765 = x26764[x26743];
      x26660 = x26660 + 1;
      bool x26778 = x26765 >= 19930901L;
      bool x26780 = x26778;
      if (x26778) {
        bool x26779 = x26765 < 19931201L;
        x26780 = x26779;
      }
      bool x26781 = x26780;
      if (x26781) {
        long x26782 = x26749 & x802;
        long x26783 = x26782;
        struct Anon1996247276* x26784 = x26664;
        struct Anon1996247276 x26785 = x26784[x26782];
        struct Anon1996247276 x26786 = x26785;
        bool x26787 = x26785.exists;;
        bool x26792 = x26787;
        if (x26787) {
          struct Anon1996247276 x26788 = x26786;
          int x26789 = x26788.key;;
          bool x26790 = x26789 == x26749;
          x26792 = x26790;
        }
        bool x26793 = x26792;
        if (x26793) {
          struct Anon2052879266 x26794 = x26785.aggs;;
          int x26800 = x26785.key;;
          double x26795 = x26794._0;;
          double x26796 = 1.0 - x26757;
          double x26797 = x26755 * x26796;
          double x26798 = x26795 + x26797;
          struct Anon2052879266 x26799;
          x26799._0 = x26798;
          struct Anon1996247276 x26801;
          x26801.exists = true;
          x26801.key = x26800;
          x26801.aggs = x26799;
          x26784[x26782] = x26801;
        } else {
          double x26796 = 1.0 - x26757;
          double x26797 = x26755 * x26796;
          struct Anon2052879266 x26830;
          x26830._0 = x26797;
          struct Anon1996247276 x26831;
          x26831.exists = true;
          x26831.key = x26749;
          x26831.aggs = x26830;
          for (;;) {
            struct Anon1996247276 x26804 = x26786;
            bool x26805 = x26804.exists;;
            bool x26840;
            if (x26805) {
              int x26806 = x26804.key;;
              bool x26807 = x26806 == x26749;
              bool x26827;
              if (x26807) {
                struct Anon2052879266 x26808 = x26804.aggs;;
                long x26812 = x26783;
                struct Anon1996247276* x26814 = x26664;
                double x26809 = x26808._0;;
                double x26810 = x26809 + x26797;
                struct Anon2052879266 x26811;
                x26811._0 = x26810;
                struct Anon1996247276 x26813;
                x26813.exists = true;
                x26813.key = x26806;
                x26813.aggs = x26811;
                x26814[x26812] = x26813;
                x26827 = false;
              } else {
                long x26817 = x26783;
                long x26818 = x26817 + 1L;
                long x26819 = x26818 % x802;
                x26783 = x26819;
                struct Anon1996247276* x26821 = x26664;
                struct Anon1996247276 x26822 = x26821[x26819];
                x26786 = x26822;
                x26827 = true;
              }
              x26840 = x26827;
            } else {
              long x26829 = x26783;
              struct Anon1996247276* x26832 = x26664;
              x26832[x26829] = x26831;
              long x26834 = x26665;
              x26666[x26834] = x26829;
              x26665 = x26665 + 1L;
              x26840 = false;
            }
            if (!x26840) break;
          }
        }
      } else {
      }
    }
    long x26851 = x26665;
    long x26853;
    for(x26853=0L; x26853 < x26851; x26853++) {
      long x26854 = x26666[x26853];
      struct Anon1996247276* x26855 = x26664;
      struct Anon1996247276 x26856 = x26855[x26854];
      long x26857 = x26678;
      long x26858 = x26677;
      bool x26859 = x26857 == x26858;
      if (x26859) {
        long x26860 = x26858 * 4L;
        x26677 = x26860;
        printf("buffer.resize %d\n",x26860);
        int* x26866 = x26682;
        int* x26867 = (int*)realloc(x26866,x26860 * sizeof(int));
        x26682 = x26867;
        printf("buffer.resize %d\n",x26860);
        double* x26870 = x26684;
        double* x26871 = (double*)realloc(x26870,x26860 * sizeof(double));
        x26684 = x26871;
      } else {
      }
      int x26878 = x26856.key;;
      int* x26879 = x26682;
      x26879[x26857] = x26878;
      struct Anon2052879266 x26881 = x26856.aggs;;
      double* x26883 = x26684;
      double x26882 = x26881._0;;
      x26883[x26857] = x26882;
      x26678 = x26678 + 1;
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x26889 = x26706;
      bool x26890 = !x26889;
      bool x26895 = x26890;
      if (x26890) {
        long x26891 = x26707;
        long x26892 = x26408;
        bool x26893 = x26891 < x26892;
        x26895 = x26893;
      }
      bool x26896 = x26895;
      if (!x26896) break;
      long x26898 = x26707;
      int* x26899 = x26410;
      int x26900 = x26899[x26898];
      char** x26901 = x26412;
      char* x26902 = x26901[x26898];
      char** x26903 = x26414;
      char* x26904 = x26903[x26898];
      char** x26907 = x26418;
      char* x26908 = x26907[x26898];
      x26707 = x26707 + 1;
      long x26915 = x26723;
      int* x26916 = x26710;
      x26916[x26915] = x26900;
      char** x26918 = x26712;
      x26918[x26915] = x26902;
      char** x26920 = x26714;
      x26920[x26915] = x26904;
      char** x26924 = x26718;
      x26924[x26915] = x26908;
      x26723 = x26723 + 1L;
      long x26931 = x26900 & x2034;
      long x26932 = x26724[x26931];
      x26724[x26931] = x26915;
      x26725[x26915] = x26932;
    }
    long x26937 = x26678;
    long x26939;
    for(x26939=0L; x26939 < x26937; x26939++) {
      double* x26944 = x26684;
      double x26945 = x26944[x26939];
      long x26959 = x26958;
      struct Anon801061462* x26960 = x26689;
      struct Anon801061462 x26961 = x26960[x26958];
      struct Anon801061462 x26962 = x26961;
      bool x26963 = x26961.exists;;
      bool x26968 = x26963;
      if (x26963) {
        struct Anon801061462 x26964 = x26962;
        char* x26965 = x26964.key;;
        bool x26966 = strcmp(x26965,"MAXREVENUE") == 0;;
        x26968 = x26966;
      }
      bool x26969 = x26968;
      if (x26969) {
        struct Anon2052879266 x26970 = x26961.aggs;;
        char* x26975 = x26961.key;;
        double x26971 = x26970._0;;
        bool x26972 = x26971 < x26945;
        double x26973;
        if (x26972) {
          x26973 = x26945;
        } else {
          x26973 = x26971;
        }
        struct Anon2052879266 x26974;
        x26974._0 = x26973;
        struct Anon801061462 x26976;
        x26976.exists = true;
        x26976.key = x26975;
        x26976.aggs = x26974;
        x26960[x26958] = x26976;
      } else {
        bool x27006 = 0.0 < x26945;
        double x27007;
        if (x27006) {
          x27007 = x26945;
        } else {
          x27007 = 0.0;
        }
        struct Anon2052879266 x27008;
        x27008._0 = x27007;
        struct Anon801061462 x27009;
        x27009.exists = true;
        x27009.key = "MAXREVENUE";
        x27009.aggs = x27008;
        for (;;) {
          struct Anon801061462 x26979 = x26962;
          bool x26980 = x26979.exists;;
          bool x27018;
          if (x26980) {
            char* x26981 = x26979.key;;
            bool x26982 = strcmp(x26981,"MAXREVENUE") == 0;;
            bool x27003;
            if (x26982) {
              struct Anon2052879266 x26983 = x26979.aggs;;
              long x26988 = x26959;
              struct Anon801061462* x26990 = x26689;
              double x26984 = x26983._0;;
              bool x26985 = x26984 < x26945;
              double x26986;
              if (x26985) {
                x26986 = x26945;
              } else {
                x26986 = x26984;
              }
              struct Anon2052879266 x26987;
              x26987._0 = x26986;
              struct Anon801061462 x26989;
              x26989.exists = true;
              x26989.key = x26981;
              x26989.aggs = x26987;
              x26990[x26988] = x26989;
              x27003 = false;
            } else {
              long x26993 = x26959;
              long x26994 = x26993 + 1L;
              long x26995 = x26994 % x802;
              x26959 = x26995;
              struct Anon801061462* x26997 = x26689;
              struct Anon801061462 x26998 = x26997[x26995];
              x26962 = x26998;
              x27003 = true;
            }
            x27018 = x27003;
          } else {
            long x27005 = x26959;
            struct Anon801061462* x27010 = x26689;
            x27010[x27005] = x27009;
            long x27012 = x26690;
            x26691[x27012] = x27005;
            x26690 = x26690 + 1L;
            x27018 = false;
          }
          if (!x27018) break;
        }
      }
    }
    long x27027 = x26690;
    long x27029;
    for(x27029=0L; x27029 < x27027; x27029++) {
      long x27030 = x26691[x27029];
      struct Anon801061462* x27031 = x26689;
      struct Anon801061462 x27032 = x27031[x27030];
      struct Anon2052879266 x27033 = x27032.aggs;;
      double x27034 = x27033._0;;
      x26703 = x27034;
      long x27037 = x26678;
      long x27039;
      for(x27039=0L; x27039 < x27037; x27039++) {
        int* x27042 = x26682;
        int x27043 = x27042[x27039];
        double* x27044 = x26684;
        double x27045 = x27044[x27039];
        double x27048 = x26703;
        bool x27050 = x27045 == x27048;
        if (x27050) {
          long x27053 = x27043 & x2034;
          long x27054 = x26724[x27053];
          long x27055 = x27054;
          for (;;) {
            long x27056 = x27055;
            bool x27057 = x27056 != -1;
            if (!x27057) break;
            long x27059 = x27055;
            int* x27060 = x26710;
            int x27061 = x27060[x27059];
            char** x27062 = x26712;
            char* x27063 = x27062[x27059];
            char** x27064 = x26714;
            char* x27065 = x27064[x27059];
            char** x27068 = x26718;
            char* x27069 = x27068[x27059];
            long x27075 = x26725[x27059];
            x27055 = x27075;
            bool x27077 = x27061 == x27043;
            if (x27077) {
              if (x975) {
              } else {
                int x27083 = strlen(x27063);
                int x27084 = strlen(x27065);
                int x27085 = strlen(x27069);
                printf("%d|%.*s|%.*s|%.*s|%.4f\n",x27061,x27083,x27063,x27084,x27065,x27085,x27069,x27045);
                x26732 = x26732 + 1L;
              }
            } else {
            }
          }
        } else {
        }
      }
    }
    long x27100 = x26732;
    printf("(%d rows)\n",x27100);
    gettimeofday(&x27104, NULL);
    timeval_subtract(&x27105, &x27104, &x27103);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x27105.tv_sec * 1000) + (x27105.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
