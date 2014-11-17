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
struct Anon920667905 left;
struct Anon811555534 right;
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
int main(int x23182, char** x23183) {
  long x23184 = 0L;
  long x6 = DEFAULT_INPUT_SIZE;
  long x23185 = x6;
  long x23186 = 0L;
  int* x23187 = (int*)malloc(x6 * sizeof(int));
  int* x23188 = x23187;
  int x3725 = open("../databases/sf2/customer.tbl",0);
  long x3726 = fsize(x3725);
  char* x3727 = mmap(0, x3726, PROT_READ, MAP_FILE | MAP_SHARED, x3725, 0);
  for (;;) {
    long x23203 = x23184;
    bool x23204 = x23203 < x3726;
    if (!x23204) break;
    int x23207 = 0;
    for (;;) {
      long x23208 = x23184;
      char x23209 = x3727[x23208];
      bool x23210 = x23209 != '|';
      bool x23215 = x23210;
      if (x23210) {
        long x23211 = x23184;
        char x23212 = x3727[x23211];
        bool x23213 = x23212 != '\n';
        x23215 = x23213;
      }
      bool x23216 = x23215;
      if (!x23216) break;
      int x23218 = x23207;
      long x23220 = x23184;
      int x23219 = x23218 * 10;
      char x23221 = x3727[x23220];
      char x23222 = x23221 - '0';
      int x23223 = x23219 + x23222;
      x23207 = x23223;
      x23184 = x23184 + 1;
    }
    x23184 = x23184 + 1;
    int x23229 = x23207;
    for (;;) {
      long x23231 = x23184;
      char x23232 = x3727[x23231];
      bool x23233 = x23232 != '|';
      bool x23238 = x23233;
      if (x23233) {
        long x23234 = x23184;
        char x23235 = x3727[x23234];
        bool x23236 = x23235 != '\n';
        x23238 = x23236;
      }
      bool x23239 = x23238;
      if (!x23239) break;
      x23184 = x23184 + 1;
    }
    x23184 = x23184 + 1;
    for (;;) {
      long x23249 = x23184;
      char x23250 = x3727[x23249];
      bool x23251 = x23250 != '|';
      bool x23256 = x23251;
      if (x23251) {
        long x23252 = x23184;
        char x23253 = x3727[x23252];
        bool x23254 = x23253 != '\n';
        x23256 = x23254;
      }
      bool x23257 = x23256;
      if (!x23257) break;
      x23184 = x23184 + 1;
    }
    x23184 = x23184 + 1;
    for (;;) {
      long x23268 = x23184;
      char x23269 = x3727[x23268];
      bool x23270 = x23269 != '|';
      bool x23275 = x23270;
      if (x23270) {
        long x23271 = x23184;
        char x23272 = x3727[x23271];
        bool x23273 = x23272 != '\n';
        x23275 = x23273;
      }
      bool x23276 = x23275;
      if (!x23276) break;
      x23184 = x23184 + 1;
    }
    x23184 = x23184 + 1;
    for (;;) {
      long x23291 = x23184;
      char x23292 = x3727[x23291];
      bool x23293 = x23292 != '|';
      bool x23298 = x23293;
      if (x23293) {
        long x23294 = x23184;
        char x23295 = x3727[x23294];
        bool x23296 = x23295 != '\n';
        x23298 = x23296;
      }
      bool x23299 = x23298;
      if (!x23299) break;
      x23184 = x23184 + 1;
    }
    x23184 = x23184 + 1;
    for (;;) {
      long x23311 = x23184;
      char x23312 = x3727[x23311];
      bool x23313 = x23312 != '.';
      bool x23318 = x23313;
      if (x23313) {
        long x23314 = x23184;
        char x23315 = x3727[x23314];
        bool x23316 = x23315 != '|';
        x23318 = x23316;
      }
      bool x23319 = x23318;
      bool x23324 = x23319;
      if (x23319) {
        long x23320 = x23184;
        char x23321 = x3727[x23320];
        bool x23322 = x23321 != '\n';
        x23324 = x23322;
      }
      bool x23325 = x23324;
      if (!x23325) break;
      x23184 = x23184 + 1;
    }
    long x23337 = x23184;
    char x23338 = x3727[x23337];
    bool x23339 = x23338 == '.';
    if (x23339) {
      x23184 = x23184 + 1;
      for (;;) {
        long x23341 = x23184;
        char x23342 = x3727[x23341];
        bool x23343 = x23342 != '|';
        bool x23348 = x23343;
        if (x23343) {
          long x23344 = x23184;
          char x23345 = x3727[x23344];
          bool x23346 = x23345 != '\n';
          x23348 = x23346;
        }
        bool x23349 = x23348;
        if (!x23349) break;
        x23184 = x23184 + 1;
      }
    } else {
    }
    x23184 = x23184 + 1;
    for (;;) {
      long x23374 = x23184;
      char x23375 = x3727[x23374];
      bool x23376 = x23375 != '|';
      bool x23381 = x23376;
      if (x23376) {
        long x23377 = x23184;
        char x23378 = x3727[x23377];
        bool x23379 = x23378 != '\n';
        x23381 = x23379;
      }
      bool x23382 = x23381;
      if (!x23382) break;
      x23184 = x23184 + 1;
    }
    x23184 = x23184 + 1;
    for (;;) {
      long x23392 = x23184;
      char x23393 = x3727[x23392];
      bool x23394 = x23393 != '|';
      bool x23399 = x23394;
      if (x23394) {
        long x23395 = x23184;
        char x23396 = x3727[x23395];
        bool x23397 = x23396 != '\n';
        x23399 = x23397;
      }
      bool x23400 = x23399;
      if (!x23400) break;
      x23184 = x23184 + 1;
    }
    x23184 = x23184 + 1;
    long x23410 = x23186;
    long x23411 = x23185;
    bool x23412 = x23410 == x23411;
    if (x23412) {
      long x23413 = x23411 * 4L;
      x23185 = x23413;
      printf("buffer.resize %d\n",x23413);
      int* x23416 = x23188;
      int* x23417 = (int*)realloc(x23416,x23413 * sizeof(int));
      x23188 = x23417;
    } else {
    }
    int* x23442 = x23188;
    x23442[x23410] = x23229;
    x23186 = x23186 + 1;
  }
  long x23461 = 0L;
  long x23462 = x6;
  long x23463 = 0L;
  int* x23464 = (int*)malloc(x6 * sizeof(int));
  int* x23465 = x23464;
  int* x23466 = (int*)malloc(x6 * sizeof(int));
  int* x23467 = x23466;
  char** x23480 = (char**)malloc(x6 * sizeof(char*));
  char** x23481 = x23480;
  int x3371 = open("../databases/sf2/orders.tbl",0);
  long x3372 = fsize(x3371);
  char* x3373 = mmap(0, x3372, PROT_READ, MAP_FILE | MAP_SHARED, x3371, 0);
  for (;;) {
    long x23482 = x23461;
    bool x23483 = x23482 < x3372;
    if (!x23483) break;
    int x23486 = 0;
    for (;;) {
      long x23487 = x23461;
      char x23488 = x3373[x23487];
      bool x23489 = x23488 != '|';
      bool x23494 = x23489;
      if (x23489) {
        long x23490 = x23461;
        char x23491 = x3373[x23490];
        bool x23492 = x23491 != '\n';
        x23494 = x23492;
      }
      bool x23495 = x23494;
      if (!x23495) break;
      int x23497 = x23486;
      long x23499 = x23461;
      int x23498 = x23497 * 10;
      char x23500 = x3373[x23499];
      char x23501 = x23500 - '0';
      int x23502 = x23498 + x23501;
      x23486 = x23502;
      x23461 = x23461 + 1;
    }
    x23461 = x23461 + 1;
    int x23508 = x23486;
    int x23510 = 0;
    for (;;) {
      long x23511 = x23461;
      char x23512 = x3373[x23511];
      bool x23513 = x23512 != '|';
      bool x23518 = x23513;
      if (x23513) {
        long x23514 = x23461;
        char x23515 = x3373[x23514];
        bool x23516 = x23515 != '\n';
        x23518 = x23516;
      }
      bool x23519 = x23518;
      if (!x23519) break;
      int x23521 = x23510;
      long x23523 = x23461;
      int x23522 = x23521 * 10;
      char x23524 = x3373[x23523];
      char x23525 = x23524 - '0';
      int x23526 = x23522 + x23525;
      x23510 = x23526;
      x23461 = x23461 + 1;
    }
    x23461 = x23461 + 1;
    int x23532 = x23510;
    x23461 = x23461 + 2;
    for (;;) {
      long x23539 = x23461;
      char x23540 = x3373[x23539];
      bool x23541 = x23540 != '.';
      bool x23546 = x23541;
      if (x23541) {
        long x23542 = x23461;
        char x23543 = x3373[x23542];
        bool x23544 = x23543 != '|';
        x23546 = x23544;
      }
      bool x23547 = x23546;
      bool x23552 = x23547;
      if (x23547) {
        long x23548 = x23461;
        char x23549 = x3373[x23548];
        bool x23550 = x23549 != '\n';
        x23552 = x23550;
      }
      bool x23553 = x23552;
      if (!x23553) break;
      x23461 = x23461 + 1;
    }
    long x23565 = x23461;
    char x23566 = x3373[x23565];
    bool x23567 = x23566 == '.';
    if (x23567) {
      x23461 = x23461 + 1;
      for (;;) {
        long x23569 = x23461;
        char x23570 = x3373[x23569];
        bool x23571 = x23570 != '|';
        bool x23576 = x23571;
        if (x23571) {
          long x23572 = x23461;
          char x23573 = x3373[x23572];
          bool x23574 = x23573 != '\n';
          x23576 = x23574;
        }
        bool x23577 = x23576;
        if (!x23577) break;
        x23461 = x23461 + 1;
      }
    } else {
    }
    x23461 = x23461 + 1;
    for (;;) {
      long x23603 = x23461;
      char x23604 = x3373[x23603];
      bool x23605 = x23604 != '-';
      bool x23610 = x23605;
      if (x23605) {
        long x23606 = x23461;
        char x23607 = x3373[x23606];
        bool x23608 = x23607 != '\n';
        x23610 = x23608;
      }
      bool x23611 = x23610;
      if (!x23611) break;
      x23461 = x23461 + 1;
    }
    x23461 = x23461 + 1;
    for (;;) {
      long x23627 = x23461;
      char x23628 = x3373[x23627];
      bool x23629 = x23628 != '-';
      bool x23634 = x23629;
      if (x23629) {
        long x23630 = x23461;
        char x23631 = x3373[x23630];
        bool x23632 = x23631 != '\n';
        x23634 = x23632;
      }
      bool x23635 = x23634;
      if (!x23635) break;
      x23461 = x23461 + 1;
    }
    x23461 = x23461 + 1;
    for (;;) {
      long x23651 = x23461;
      char x23652 = x3373[x23651];
      bool x23653 = x23652 != '|';
      bool x23658 = x23653;
      if (x23653) {
        long x23654 = x23461;
        char x23655 = x3373[x23654];
        bool x23656 = x23655 != '\n';
        x23658 = x23656;
      }
      bool x23659 = x23658;
      if (!x23659) break;
      x23461 = x23461 + 1;
    }
    x23461 = x23461 + 1;
    for (;;) {
      long x23678 = x23461;
      char x23679 = x3373[x23678];
      bool x23680 = x23679 != '|';
      bool x23685 = x23680;
      if (x23680) {
        long x23681 = x23461;
        char x23682 = x3373[x23681];
        bool x23683 = x23682 != '\n';
        x23685 = x23683;
      }
      bool x23686 = x23685;
      if (!x23686) break;
      x23461 = x23461 + 1;
    }
    x23461 = x23461 + 1;
    for (;;) {
      long x23696 = x23461;
      char x23697 = x3373[x23696];
      bool x23698 = x23697 != '|';
      bool x23703 = x23698;
      if (x23698) {
        long x23699 = x23461;
        char x23700 = x3373[x23699];
        bool x23701 = x23700 != '\n';
        x23703 = x23701;
      }
      bool x23704 = x23703;
      if (!x23704) break;
      x23461 = x23461 + 1;
    }
    x23461 = x23461 + 1;
    for (;;) {
      long x23715 = x23461;
      char x23716 = x3373[x23715];
      bool x23717 = x23716 != '|';
      bool x23722 = x23717;
      if (x23717) {
        long x23718 = x23461;
        char x23719 = x3373[x23718];
        bool x23720 = x23719 != '\n';
        x23722 = x23720;
      }
      bool x23723 = x23722;
      if (!x23723) break;
      x23461 = x23461 + 1;
    }
    x23461 = x23461 + 1;
    long x23737 = x23461;
    for (;;) {
      long x23738 = x23461;
      char x23739 = x3373[x23738];
      bool x23740 = x23739 != '|';
      bool x23745 = x23740;
      if (x23740) {
        long x23741 = x23461;
        char x23742 = x3373[x23741];
        bool x23743 = x23742 != '\n';
        x23745 = x23743;
      }
      bool x23746 = x23745;
      if (!x23746) break;
      x23461 = x23461 + 1;
    }
    x23461 = x23461 + 1;
    long x23756 = x23463;
    long x23757 = x23462;
    bool x23758 = x23756 == x23757;
    if (x23758) {
      long x23759 = x23757 * 4L;
      x23462 = x23759;
      printf("buffer.resize %d\n",x23759);
      int* x23762 = x23465;
      int* x23763 = (int*)realloc(x23762,x23759 * sizeof(int));
      x23465 = x23763;
      int* x23765 = x23467;
      int* x23766 = (int*)realloc(x23765,x23759 * sizeof(int));
      x23467 = x23766;
      char** x23786 = x23481;
      char** x23787 = (char**)realloc(x23786,x23759 * sizeof(char*));
      x23481 = x23787;
    } else {
    }
    int* x23791 = x23465;
    x23791[x23756] = x23508;
    int* x23793 = x23467;
    x23793[x23756] = x23532;
    char** x23807 = x23481;
    char* x23754 = x3373+x23737;
    x23807[x23756] = x23754;
    x23463 = x23463 + 1;
  }
  long x2011 = DEFAULT_JOIN_HASH_SIZE;
  long x787 = DEFAULT_AGG_HASH_SIZE ;
  long x2034 = x2011 - 1L;
  long x802 = x787 - 1L;
  bool x24095 = 0 == 0.0;
  double x24131;
  if (x24095) {
    x24131 = 0.0;
  } else {
    x24131 = 1.0;
  }
  struct Anon2052879266 x24132;
  x24132._0 = x24131;
  long x24161 = 777L & x802;
  struct Anon2052879266 x5917;
  x5917._0 = 1.0;
  bool x975 = true == false;
  int x23812;
  for(x23812=0; x23812 < 5; x23812++) {
    bool x23813 = false;
    long x23814 = 0L;
    bool x23815 = false;
    long x23816 = 0L;
    int* x23819 = (int*)malloc(x2011 * sizeof(int));
    int* x23820 = x23819;
    int* x23821 = (int*)malloc(x2011 * sizeof(int));
    int* x23822 = x23821;
    long x23837 = 0L;
    long* x23838 = (long*)malloc(x2011 * sizeof(long));
    long* x23839 = (long*)malloc(x2011 * sizeof(long));
    long x23840;
    for(x23840=0L; x23840 < x2011; x23840++) {
      x23838[x23840] = -1L;
    }
    struct Anon1996247276* x23847 = (struct Anon1996247276*)malloc(x787 * sizeof(struct Anon1996247276));
    struct Anon1996247276* x23848 = x23847;
    long x23849 = 0L;
    long* x23850 = (long*)malloc(x787 * sizeof(long));
    long x23851;
    for(x23851=0L; x23851 < x787; x23851++) {
      struct Anon1996247276* x23852 = x23848;
      struct Anon1996247276 x23853 = x23852[x23851];
      int x23854 = x23853.key;;
      struct Anon2052879266 x23855 = x23853.aggs;;
      struct Anon1996247276 x23856;
      x23856.exists = false;
      x23856.key = x23854;
      x23856.aggs = x23855;
      x23852[x23851] = x23856;
    }
    struct Anon56555318* x23861 = (struct Anon56555318*)malloc(x787 * sizeof(struct Anon56555318));
    struct Anon56555318* x23862 = x23861;
    long x23863 = 0L;
    long* x23864 = (long*)malloc(x787 * sizeof(long));
    long x23865;
    for(x23865=0L; x23865 < x787; x23865++) {
      struct Anon56555318* x23866 = x23862;
      struct Anon56555318 x23867 = x23866[x23865];
      double x23868 = x23867.key;;
      struct Anon2052879266 x23869 = x23867.aggs;;
      struct Anon56555318 x23870;
      x23870.exists = false;
      x23870.key = x23868;
      x23870.aggs = x23869;
      x23866[x23865] = x23870;
    }
    long x23875 = 0L;
    struct timeval x24245, x24246, x24247;
    gettimeofday(&x24245, NULL);
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x23877 = x23815;
      bool x23878 = !x23877;
      bool x23883 = x23878;
      if (x23878) {
        long x23879 = x23816;
        long x23880 = x23463;
        bool x23881 = x23879 < x23880;
        x23883 = x23881;
      }
      bool x23884 = x23883;
      if (!x23884) break;
      long x23886 = x23816;
      int* x23887 = x23465;
      int x23888 = x23887[x23886];
      int* x23889 = x23467;
      int x23890 = x23889[x23886];
      char** x23903 = x23481;
      char* x23904 = x23903[x23886];
      x23816 = x23816 + 1;
      int x23907 = strstr(&x23904[0],"unusual") - x23904;
      if (x23907 < 0) x23907 = -1;
      bool x23909 = x23907 != -1;
      bool x23911 = x23909;
      if (x23909) {
        int x23908 = strstr(&x23904[x23907],"packages") - x23904;
        if (x23908 < 0) x23908 = -1;
        bool x23910 = x23908 != -1;
        x23911 = x23910;
      }
      bool x23912 = x23911;
      if (x23912) {
      } else {
        long x23914 = x23837;
        int* x23915 = x23820;
        x23915[x23914] = x23888;
        int* x23917 = x23822;
        x23917[x23914] = x23890;
        x23837 = x23837 + 1L;
        long x23934 = x23890 & x2034;
        long x23935 = x23838[x23934];
        x23838[x23934] = x23914;
        x23839[x23914] = x23935;
      }
    }
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x23943 = x23813;
      bool x23944 = !x23943;
      bool x23949 = x23944;
      if (x23944) {
        long x23945 = x23814;
        long x23946 = x23186;
        bool x23947 = x23945 < x23946;
        x23949 = x23947;
      }
      bool x23950 = x23949;
      if (!x23950) break;
      long x23952 = x23814;
      int* x23953 = x23188;
      int x23954 = x23953[x23952];
      x23814 = x23814 + 1;
      bool x23971 = false;
      long x23972 = x23954 & x2034;
      long x23973 = x23838[x23972];
      long x23974 = x23973;
      long x24005 = x23954 & x802;
      for (;;) {
        long x23975 = x23974;
        bool x23976 = x23975 != -1;
        if (!x23976) break;
        long x23978 = x23974;
        int* x23979 = x23820;
        int x23980 = x23979[x23978];
        int* x23981 = x23822;
        int x23982 = x23981[x23978];
        long x23998 = x23839[x23978];
        x23974 = x23998;
        bool x24000 = x23954 == x23982;
        if (x24000) {
          x23971 = true;
          long x24006 = x24005;
          struct Anon1996247276* x24007 = x23848;
          struct Anon1996247276 x24008 = x24007[x24005];
          struct Anon1996247276 x24009 = x24008;
          bool x24010 = x24008.exists;;
          bool x24015 = x24010;
          if (x24010) {
            struct Anon1996247276 x24011 = x24009;
            int x24012 = x24011.key;;
            bool x24013 = x24012 == x23954;
            x24015 = x24013;
          }
          bool x24016 = x24015;
          if (x24016) {
            struct Anon2052879266 x24017 = x24008.aggs;;
            int x24024 = x24008.key;;
            bool x24019 = x23980 == 0.0;
            double x24022;
            if (x24019) {
              double x24020 = x24017._0;;
              x24022 = x24020;
            } else {
              double x24020 = x24017._0;;
              double x24021 = x24020 + 1.0;
              x24022 = x24021;
            }
            struct Anon2052879266 x24023;
            x24023._0 = x24022;
            struct Anon1996247276 x24025;
            x24025.exists = true;
            x24025.key = x24024;
            x24025.aggs = x24023;
            x24007[x24005] = x24025;
          } else {
            bool x24019 = x23980 == 0.0;
            double x24055;
            if (x24019) {
              x24055 = 0.0;
            } else {
              x24055 = 1.0;
            }
            struct Anon2052879266 x24056;
            x24056._0 = x24055;
            struct Anon1996247276 x24057;
            x24057.exists = true;
            x24057.key = x23954;
            x24057.aggs = x24056;
            for (;;) {
              struct Anon1996247276 x24028 = x24009;
              bool x24029 = x24028.exists;;
              bool x24066;
              if (x24029) {
                int x24030 = x24028.key;;
                bool x24031 = x24030 == x23954;
                bool x24052;
                if (x24031) {
                  struct Anon2052879266 x24032 = x24028.aggs;;
                  long x24037 = x24006;
                  struct Anon1996247276* x24039 = x23848;
                  double x24035;
                  if (x24019) {
                    double x24033 = x24032._0;;
                    x24035 = x24033;
                  } else {
                    double x24033 = x24032._0;;
                    double x24034 = x24033 + 1.0;
                    x24035 = x24034;
                  }
                  struct Anon2052879266 x24036;
                  x24036._0 = x24035;
                  struct Anon1996247276 x24038;
                  x24038.exists = true;
                  x24038.key = x24030;
                  x24038.aggs = x24036;
                  x24039[x24037] = x24038;
                  x24052 = false;
                } else {
                  long x24042 = x24006;
                  long x24043 = x24042 + 1L;
                  long x24044 = x24043 % x802;
                  x24006 = x24044;
                  struct Anon1996247276* x24046 = x23848;
                  struct Anon1996247276 x24047 = x24046[x24044];
                  x24009 = x24047;
                  x24052 = true;
                }
                x24066 = x24052;
              } else {
                long x24054 = x24006;
                struct Anon1996247276* x24058 = x23848;
                x24058[x24054] = x24057;
                long x24060 = x23849;
                x23850[x24060] = x24054;
                x23849 = x23849 + 1L;
                x24066 = false;
              }
              if (!x24066) break;
            }
          }
        } else {
        }
      }
      bool x24077 = x23971;
      if (x24077) {
      } else {
        long x24082 = x24005;
        struct Anon1996247276* x24083 = x23848;
        struct Anon1996247276 x24084 = x24083[x24005];
        struct Anon1996247276 x24085 = x24084;
        bool x24086 = x24084.exists;;
        bool x24091 = x24086;
        if (x24086) {
          struct Anon1996247276 x24087 = x24085;
          int x24088 = x24087.key;;
          bool x24089 = x24088 == x23954;
          x24091 = x24089;
        }
        bool x24092 = x24091;
        if (x24092) {
          struct Anon2052879266 x24093 = x24084.aggs;;
          int x24100 = x24084.key;;
          double x24098;
          if (x24095) {
            double x24096 = x24093._0;;
            x24098 = x24096;
          } else {
            double x24096 = x24093._0;;
            double x24097 = x24096 + 1.0;
            x24098 = x24097;
          }
          struct Anon2052879266 x24099;
          x24099._0 = x24098;
          struct Anon1996247276 x24101;
          x24101.exists = true;
          x24101.key = x24100;
          x24101.aggs = x24099;
          x24083[x24005] = x24101;
        } else {
          struct Anon1996247276 x24133;
          x24133.exists = true;
          x24133.key = x23954;
          x24133.aggs = x24132;
          for (;;) {
            struct Anon1996247276 x24104 = x24085;
            bool x24105 = x24104.exists;;
            bool x24142;
            if (x24105) {
              int x24106 = x24104.key;;
              bool x24107 = x24106 == x23954;
              bool x24128;
              if (x24107) {
                struct Anon2052879266 x24108 = x24104.aggs;;
                long x24113 = x24082;
                struct Anon1996247276* x24115 = x23848;
                double x24111;
                if (x24095) {
                  double x24109 = x24108._0;;
                  x24111 = x24109;
                } else {
                  double x24109 = x24108._0;;
                  double x24110 = x24109 + 1.0;
                  x24111 = x24110;
                }
                struct Anon2052879266 x24112;
                x24112._0 = x24111;
                struct Anon1996247276 x24114;
                x24114.exists = true;
                x24114.key = x24106;
                x24114.aggs = x24112;
                x24115[x24113] = x24114;
                x24128 = false;
              } else {
                long x24118 = x24082;
                long x24119 = x24118 + 1L;
                long x24120 = x24119 % x802;
                x24082 = x24120;
                struct Anon1996247276* x24122 = x23848;
                struct Anon1996247276 x24123 = x24122[x24120];
                x24085 = x24123;
                x24128 = true;
              }
              x24142 = x24128;
            } else {
              long x24130 = x24082;
              struct Anon1996247276* x24134 = x23848;
              x24134[x24130] = x24133;
              long x24136 = x23849;
              x23850[x24136] = x24130;
              x23849 = x23849 + 1L;
              x24142 = false;
            }
            if (!x24142) break;
          }
        }
      }
    }
    long x24153 = x23849;
    long x24155;
    for(x24155=0L; x24155 < x24153; x24155++) {
      long x24156 = x23850[x24155];
      struct Anon1996247276* x24157 = x23848;
      struct Anon1996247276 x24158 = x24157[x24156];
      struct Anon2052879266 x24159 = x24158.aggs;;
      long x24162 = x24161;
      struct Anon56555318* x24163 = x23862;
      struct Anon56555318 x24164 = x24163[x24161];
      struct Anon56555318 x24165 = x24164;
      bool x24166 = x24164.exists;;
      bool x24171 = x24166;
      if (x24166) {
        struct Anon56555318 x24167 = x24165;
        double x24168 = x24167.key;;
        double x24160 = x24159._0;;
        bool x24169 = x24168 == x24160;
        x24171 = x24169;
      }
      bool x24172 = x24171;
      if (x24172) {
        struct Anon2052879266 x24173 = x24164.aggs;;
        double x24177 = x24164.key;;
        double x24174 = x24173._0;;
        double x24175 = x24174 + 1.0;
        struct Anon2052879266 x24176;
        x24176._0 = x24175;
        struct Anon56555318 x24178;
        x24178.exists = true;
        x24178.key = x24177;
        x24178.aggs = x24176;
        x24163[x24161] = x24178;
      } else {
        double x24160 = x24159._0;;
        struct Anon56555318 x24207;
        x24207.exists = true;
        x24207.key = x24160;
        x24207.aggs = x5917;
        for (;;) {
          struct Anon56555318 x24181 = x24165;
          bool x24182 = x24181.exists;;
          bool x24216;
          if (x24182) {
            double x24183 = x24181.key;;
            bool x24184 = x24183 == x24160;
            bool x24204;
            if (x24184) {
              struct Anon2052879266 x24185 = x24181.aggs;;
              long x24189 = x24162;
              struct Anon56555318* x24191 = x23862;
              double x24186 = x24185._0;;
              double x24187 = x24186 + 1.0;
              struct Anon2052879266 x24188;
              x24188._0 = x24187;
              struct Anon56555318 x24190;
              x24190.exists = true;
              x24190.key = x24183;
              x24190.aggs = x24188;
              x24191[x24189] = x24190;
              x24204 = false;
            } else {
              long x24194 = x24162;
              long x24195 = x24194 + 1L;
              long x24196 = x24195 % x802;
              x24162 = x24196;
              struct Anon56555318* x24198 = x23862;
              struct Anon56555318 x24199 = x24198[x24196];
              x24165 = x24199;
              x24204 = true;
            }
            x24216 = x24204;
          } else {
            long x24206 = x24162;
            struct Anon56555318* x24208 = x23862;
            x24208[x24206] = x24207;
            long x24210 = x23863;
            x23864[x24210] = x24206;
            x23863 = x23863 + 1L;
            x24216 = false;
          }
          if (!x24216) break;
        }
      }
    }
    long x24225 = x23863;
    long x24227;
    for(x24227=0L; x24227 < x24225; x24227++) {
      long x24228 = x23864[x24227];
      struct Anon56555318* x24229 = x23862;
      struct Anon56555318 x24230 = x24229[x24228];
      if (x975) {
      } else {
        double x24233 = x24230.key;;
        struct Anon2052879266 x24234 = x24230.aggs;;
        double x24235 = x24234._0;;
        printf("%.0f|%.0f\n",x24233,x24235);
        x23875 = x23875 + 1L;
      }
    }
    long x24242 = x23875;
    printf("(%d rows)\n",x24242);
    gettimeofday(&x24246, NULL);
    timeval_subtract(&x24247, &x24246, &x24245);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x24247.tv_sec * 1000) + (x24247.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
