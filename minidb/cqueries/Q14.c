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

struct Anon0 {
struct Anon102935935 left;
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
int main(int x24252, char** x24253) {
  long x24254 = 0L;
  long x6 = DEFAULT_INPUT_SIZE;
  long x24255 = x6;
  long x24256 = 0L;
  int* x24259 = (int*)malloc(x6 * sizeof(int));
  int* x24260 = x24259;
  double* x24267 = (double*)malloc(x6 * sizeof(double));
  double* x24268 = x24267;
  double* x24269 = (double*)malloc(x6 * sizeof(double));
  double* x24270 = x24269;
  long* x24277 = (long*)malloc(x6 * sizeof(long));
  long* x24278 = x24277;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  long x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    long x24289 = x24254;
    bool x24290 = x24289 < x3;
    if (!x24290) break;
    for (;;) {
      long x24294 = x24254;
      char x24295 = x4[x24294];
      bool x24296 = x24295 != '|';
      bool x24301 = x24296;
      if (x24296) {
        long x24297 = x24254;
        char x24298 = x4[x24297];
        bool x24299 = x24298 != '\n';
        x24301 = x24299;
      }
      bool x24302 = x24301;
      if (!x24302) break;
      x24254 = x24254 + 1;
    }
    x24254 = x24254 + 1;
    int x24317 = 0;
    for (;;) {
      long x24318 = x24254;
      char x24319 = x4[x24318];
      bool x24320 = x24319 != '|';
      bool x24325 = x24320;
      if (x24320) {
        long x24321 = x24254;
        char x24322 = x4[x24321];
        bool x24323 = x24322 != '\n';
        x24325 = x24323;
      }
      bool x24326 = x24325;
      if (!x24326) break;
      int x24328 = x24317;
      long x24330 = x24254;
      int x24329 = x24328 * 10;
      char x24331 = x4[x24330];
      char x24332 = x24331 - '0';
      int x24333 = x24329 + x24332;
      x24317 = x24333;
      x24254 = x24254 + 1;
    }
    x24254 = x24254 + 1;
    int x24339 = x24317;
    for (;;) {
      long x24342 = x24254;
      char x24343 = x4[x24342];
      bool x24344 = x24343 != '|';
      bool x24349 = x24344;
      if (x24344) {
        long x24345 = x24254;
        char x24346 = x4[x24345];
        bool x24347 = x24346 != '\n';
        x24349 = x24347;
      }
      bool x24350 = x24349;
      if (!x24350) break;
      x24254 = x24254 + 1;
    }
    x24254 = x24254 + 1;
    for (;;) {
      long x24366 = x24254;
      char x24367 = x4[x24366];
      bool x24368 = x24367 != '|';
      bool x24373 = x24368;
      if (x24368) {
        long x24369 = x24254;
        char x24370 = x4[x24369];
        bool x24371 = x24370 != '\n';
        x24373 = x24371;
      }
      bool x24374 = x24373;
      if (!x24374) break;
      x24254 = x24254 + 1;
    }
    x24254 = x24254 + 1;
    for (;;) {
      long x24391 = x24254;
      char x24392 = x4[x24391];
      bool x24393 = x24392 != '.';
      bool x24398 = x24393;
      if (x24393) {
        long x24394 = x24254;
        char x24395 = x4[x24394];
        bool x24396 = x24395 != '|';
        x24398 = x24396;
      }
      bool x24399 = x24398;
      bool x24404 = x24399;
      if (x24399) {
        long x24400 = x24254;
        char x24401 = x4[x24400];
        bool x24402 = x24401 != '\n';
        x24404 = x24402;
      }
      bool x24405 = x24404;
      if (!x24405) break;
      x24254 = x24254 + 1;
    }
    long x24417 = x24254;
    char x24418 = x4[x24417];
    bool x24419 = x24418 == '.';
    if (x24419) {
      x24254 = x24254 + 1;
      for (;;) {
        long x24421 = x24254;
        char x24422 = x4[x24421];
        bool x24423 = x24422 != '|';
        bool x24428 = x24423;
        if (x24423) {
          long x24424 = x24254;
          char x24425 = x4[x24424];
          bool x24426 = x24425 != '\n';
          x24428 = x24426;
        }
        bool x24429 = x24428;
        if (!x24429) break;
        x24254 = x24254 + 1;
      }
    } else {
    }
    x24254 = x24254 + 1;
    int x24454 = 0;
    int x24455 = 1;
    for (;;) {
      long x24456 = x24254;
      char x24457 = x4[x24456];
      bool x24458 = x24457 != '.';
      bool x24463 = x24458;
      if (x24458) {
        long x24459 = x24254;
        char x24460 = x4[x24459];
        bool x24461 = x24460 != '|';
        x24463 = x24461;
      }
      bool x24464 = x24463;
      bool x24469 = x24464;
      if (x24464) {
        long x24465 = x24254;
        char x24466 = x4[x24465];
        bool x24467 = x24466 != '\n';
        x24469 = x24467;
      }
      bool x24470 = x24469;
      if (!x24470) break;
      int x24472 = x24454;
      long x24474 = x24254;
      int x24473 = x24472 * 10;
      char x24475 = x4[x24474];
      char x24476 = x24475 - '0';
      int x24477 = x24473 + x24476;
      x24454 = x24477;
      x24254 = x24254 + 1;
    }
    long x24482 = x24254;
    char x24483 = x4[x24482];
    bool x24484 = x24483 == '.';
    if (x24484) {
      x24254 = x24254 + 1;
      for (;;) {
        long x24486 = x24254;
        char x24487 = x4[x24486];
        bool x24488 = x24487 != '|';
        bool x24493 = x24488;
        if (x24488) {
          long x24489 = x24254;
          char x24490 = x4[x24489];
          bool x24491 = x24490 != '\n';
          x24493 = x24491;
        }
        bool x24494 = x24493;
        if (!x24494) break;
        int x24496 = x24454;
        long x24498 = x24254;
        int x24497 = x24496 * 10;
        char x24499 = x4[x24498];
        char x24500 = x24499 - '0';
        int x24501 = x24497 + x24500;
        x24454 = x24501;
        int x24503 = x24455;
        int x24504 = x24503 * 10;
        x24455 = x24504;
        x24254 = x24254 + 1;
      }
    } else {
    }
    x24254 = x24254 + 1;
    int x24513 = x24454;
    int x24515 = x24455;
    int x24519 = 0;
    int x24520 = 1;
    for (;;) {
      long x24521 = x24254;
      char x24522 = x4[x24521];
      bool x24523 = x24522 != '.';
      bool x24528 = x24523;
      if (x24523) {
        long x24524 = x24254;
        char x24525 = x4[x24524];
        bool x24526 = x24525 != '|';
        x24528 = x24526;
      }
      bool x24529 = x24528;
      bool x24534 = x24529;
      if (x24529) {
        long x24530 = x24254;
        char x24531 = x4[x24530];
        bool x24532 = x24531 != '\n';
        x24534 = x24532;
      }
      bool x24535 = x24534;
      if (!x24535) break;
      int x24537 = x24519;
      long x24539 = x24254;
      int x24538 = x24537 * 10;
      char x24540 = x4[x24539];
      char x24541 = x24540 - '0';
      int x24542 = x24538 + x24541;
      x24519 = x24542;
      x24254 = x24254 + 1;
    }
    long x24547 = x24254;
    char x24548 = x4[x24547];
    bool x24549 = x24548 == '.';
    if (x24549) {
      x24254 = x24254 + 1;
      for (;;) {
        long x24551 = x24254;
        char x24552 = x4[x24551];
        bool x24553 = x24552 != '|';
        bool x24558 = x24553;
        if (x24553) {
          long x24554 = x24254;
          char x24555 = x4[x24554];
          bool x24556 = x24555 != '\n';
          x24558 = x24556;
        }
        bool x24559 = x24558;
        if (!x24559) break;
        int x24561 = x24519;
        long x24563 = x24254;
        int x24562 = x24561 * 10;
        char x24564 = x4[x24563];
        char x24565 = x24564 - '0';
        int x24566 = x24562 + x24565;
        x24519 = x24566;
        int x24568 = x24520;
        int x24569 = x24568 * 10;
        x24520 = x24569;
        x24254 = x24254 + 1;
      }
    } else {
    }
    x24254 = x24254 + 1;
    int x24578 = x24519;
    int x24580 = x24520;
    for (;;) {
      long x24586 = x24254;
      char x24587 = x4[x24586];
      bool x24588 = x24587 != '.';
      bool x24593 = x24588;
      if (x24588) {
        long x24589 = x24254;
        char x24590 = x4[x24589];
        bool x24591 = x24590 != '|';
        x24593 = x24591;
      }
      bool x24594 = x24593;
      bool x24599 = x24594;
      if (x24594) {
        long x24595 = x24254;
        char x24596 = x4[x24595];
        bool x24597 = x24596 != '\n';
        x24599 = x24597;
      }
      bool x24600 = x24599;
      if (!x24600) break;
      x24254 = x24254 + 1;
    }
    long x24612 = x24254;
    char x24613 = x4[x24612];
    bool x24614 = x24613 == '.';
    if (x24614) {
      x24254 = x24254 + 1;
      for (;;) {
        long x24616 = x24254;
        char x24617 = x4[x24616];
        bool x24618 = x24617 != '|';
        bool x24623 = x24618;
        if (x24618) {
          long x24619 = x24254;
          char x24620 = x4[x24619];
          bool x24621 = x24620 != '\n';
          x24623 = x24621;
        }
        bool x24624 = x24623;
        if (!x24624) break;
        x24254 = x24254 + 1;
      }
    } else {
    }
    x24254 = x24254 + 1;
    x24254 = x24254 + 2;
    x24254 = x24254 + 2;
    int x24655 = 0;
    for (;;) {
      long x24656 = x24254;
      char x24657 = x4[x24656];
      bool x24658 = x24657 != '-';
      bool x24663 = x24658;
      if (x24658) {
        long x24659 = x24254;
        char x24660 = x4[x24659];
        bool x24661 = x24660 != '\n';
        x24663 = x24661;
      }
      bool x24664 = x24663;
      if (!x24664) break;
      int x24666 = x24655;
      long x24668 = x24254;
      int x24667 = x24666 * 10;
      char x24669 = x4[x24668];
      char x24670 = x24669 - '0';
      int x24671 = x24667 + x24670;
      x24655 = x24671;
      x24254 = x24254 + 1;
    }
    x24254 = x24254 + 1;
    int x24677 = x24655;
    int x24679 = 0;
    for (;;) {
      long x24680 = x24254;
      char x24681 = x4[x24680];
      bool x24682 = x24681 != '-';
      bool x24687 = x24682;
      if (x24682) {
        long x24683 = x24254;
        char x24684 = x4[x24683];
        bool x24685 = x24684 != '\n';
        x24687 = x24685;
      }
      bool x24688 = x24687;
      if (!x24688) break;
      int x24690 = x24679;
      long x24692 = x24254;
      int x24691 = x24690 * 10;
      char x24693 = x4[x24692];
      char x24694 = x24693 - '0';
      int x24695 = x24691 + x24694;
      x24679 = x24695;
      x24254 = x24254 + 1;
    }
    x24254 = x24254 + 1;
    int x24701 = x24679;
    int x24703 = 0;
    for (;;) {
      long x24704 = x24254;
      char x24705 = x4[x24704];
      bool x24706 = x24705 != '|';
      bool x24711 = x24706;
      if (x24706) {
        long x24707 = x24254;
        char x24708 = x4[x24707];
        bool x24709 = x24708 != '\n';
        x24711 = x24709;
      }
      bool x24712 = x24711;
      if (!x24712) break;
      int x24714 = x24703;
      long x24716 = x24254;
      int x24715 = x24714 * 10;
      char x24717 = x4[x24716];
      char x24718 = x24717 - '0';
      int x24719 = x24715 + x24718;
      x24703 = x24719;
      x24254 = x24254 + 1;
    }
    x24254 = x24254 + 1;
    int x24725 = x24703;
    for (;;) {
      long x24732 = x24254;
      char x24733 = x4[x24732];
      bool x24734 = x24733 != '-';
      bool x24739 = x24734;
      if (x24734) {
        long x24735 = x24254;
        char x24736 = x4[x24735];
        bool x24737 = x24736 != '\n';
        x24739 = x24737;
      }
      bool x24740 = x24739;
      if (!x24740) break;
      x24254 = x24254 + 1;
    }
    x24254 = x24254 + 1;
    for (;;) {
      long x24756 = x24254;
      char x24757 = x4[x24756];
      bool x24758 = x24757 != '-';
      bool x24763 = x24758;
      if (x24758) {
        long x24759 = x24254;
        char x24760 = x4[x24759];
        bool x24761 = x24760 != '\n';
        x24763 = x24761;
      }
      bool x24764 = x24763;
      if (!x24764) break;
      x24254 = x24254 + 1;
    }
    x24254 = x24254 + 1;
    for (;;) {
      long x24780 = x24254;
      char x24781 = x4[x24780];
      bool x24782 = x24781 != '|';
      bool x24787 = x24782;
      if (x24782) {
        long x24783 = x24254;
        char x24784 = x4[x24783];
        bool x24785 = x24784 != '\n';
        x24787 = x24785;
      }
      bool x24788 = x24787;
      if (!x24788) break;
      x24254 = x24254 + 1;
    }
    x24254 = x24254 + 1;
    for (;;) {
      long x24808 = x24254;
      char x24809 = x4[x24808];
      bool x24810 = x24809 != '-';
      bool x24815 = x24810;
      if (x24810) {
        long x24811 = x24254;
        char x24812 = x4[x24811];
        bool x24813 = x24812 != '\n';
        x24815 = x24813;
      }
      bool x24816 = x24815;
      if (!x24816) break;
      x24254 = x24254 + 1;
    }
    x24254 = x24254 + 1;
    for (;;) {
      long x24832 = x24254;
      char x24833 = x4[x24832];
      bool x24834 = x24833 != '-';
      bool x24839 = x24834;
      if (x24834) {
        long x24835 = x24254;
        char x24836 = x4[x24835];
        bool x24837 = x24836 != '\n';
        x24839 = x24837;
      }
      bool x24840 = x24839;
      if (!x24840) break;
      x24254 = x24254 + 1;
    }
    x24254 = x24254 + 1;
    for (;;) {
      long x24856 = x24254;
      char x24857 = x4[x24856];
      bool x24858 = x24857 != '|';
      bool x24863 = x24858;
      if (x24858) {
        long x24859 = x24254;
        char x24860 = x4[x24859];
        bool x24861 = x24860 != '\n';
        x24863 = x24861;
      }
      bool x24864 = x24863;
      if (!x24864) break;
      x24254 = x24254 + 1;
    }
    x24254 = x24254 + 1;
    for (;;) {
      long x24883 = x24254;
      char x24884 = x4[x24883];
      bool x24885 = x24884 != '|';
      bool x24890 = x24885;
      if (x24885) {
        long x24886 = x24254;
        char x24887 = x4[x24886];
        bool x24888 = x24887 != '\n';
        x24890 = x24888;
      }
      bool x24891 = x24890;
      if (!x24891) break;
      x24254 = x24254 + 1;
    }
    x24254 = x24254 + 1;
    for (;;) {
      long x24901 = x24254;
      char x24902 = x4[x24901];
      bool x24903 = x24902 != '|';
      bool x24908 = x24903;
      if (x24903) {
        long x24904 = x24254;
        char x24905 = x4[x24904];
        bool x24906 = x24905 != '\n';
        x24908 = x24906;
      }
      bool x24909 = x24908;
      if (!x24909) break;
      x24254 = x24254 + 1;
    }
    x24254 = x24254 + 1;
    for (;;) {
      long x24919 = x24254;
      char x24920 = x4[x24919];
      bool x24921 = x24920 != '|';
      bool x24926 = x24921;
      if (x24921) {
        long x24922 = x24254;
        char x24923 = x4[x24922];
        bool x24924 = x24923 != '\n';
        x24926 = x24924;
      }
      bool x24927 = x24926;
      if (!x24927) break;
      x24254 = x24254 + 1;
    }
    x24254 = x24254 + 1;
    long x24937 = x24256;
    long x24938 = x24255;
    bool x24939 = x24937 == x24938;
    if (x24939) {
      long x24940 = x24938 * 4L;
      x24255 = x24940;
      printf("buffer.resize %d\n",x24940);
      int* x24946 = x24260;
      int* x24947 = (int*)realloc(x24946,x24940 * sizeof(int));
      x24260 = x24947;
      double* x24958 = x24268;
      double* x24959 = (double*)realloc(x24958,x24940 * sizeof(double));
      x24268 = x24959;
      double* x24961 = x24270;
      double* x24962 = (double*)realloc(x24961,x24940 * sizeof(double));
      x24270 = x24962;
      long* x24973 = x24278;
      long* x24974 = (long*)realloc(x24973,x24940 * sizeof(long));
      x24278 = x24974;
    } else {
    }
    int* x24995 = x24260;
    x24995[x24937] = x24339;
    double* x25003 = x24268;
    double x24514 = (double)x24513;
    double x24516 = (double)x24515;
    double x24517 = x24514 / x24516;
    x25003[x24937] = x24517;
    double* x25005 = x24270;
    double x24579 = (double)x24578;
    double x24581 = (double)x24580;
    double x24582 = x24579 / x24581;
    x25005[x24937] = x24582;
    long* x25013 = x24278;
    long x24726 = x24677 * 10000L;
    long x24727 = x24701 * 100L;
    long x24728 = x24726 + x24727;
    long x24729 = x24728 + x24725;
    x25013[x24937] = x24729;
    x24256 = x24256 + 1;
  }
  long x25028 = 0L;
  long x25029 = x6;
  long x25030 = 0L;
  int* x25031 = (int*)malloc(x6 * sizeof(int));
  int* x25032 = x25031;
  char** x25039 = (char**)malloc(x6 * sizeof(char*));
  char** x25040 = x25039;
  int x998 = open("../databases/sf2/part.tbl",0);
  long x999 = fsize(x998);
  char* x1000 = mmap(0, x999, PROT_READ, MAP_FILE | MAP_SHARED, x998, 0);
  for (;;) {
    long x25050 = x25028;
    bool x25051 = x25050 < x999;
    if (!x25051) break;
    int x25054 = 0;
    for (;;) {
      long x25055 = x25028;
      char x25056 = x1000[x25055];
      bool x25057 = x25056 != '|';
      bool x25062 = x25057;
      if (x25057) {
        long x25058 = x25028;
        char x25059 = x1000[x25058];
        bool x25060 = x25059 != '\n';
        x25062 = x25060;
      }
      bool x25063 = x25062;
      if (!x25063) break;
      int x25065 = x25054;
      long x25067 = x25028;
      int x25066 = x25065 * 10;
      char x25068 = x1000[x25067];
      char x25069 = x25068 - '0';
      int x25070 = x25066 + x25069;
      x25054 = x25070;
      x25028 = x25028 + 1;
    }
    x25028 = x25028 + 1;
    int x25076 = x25054;
    for (;;) {
      long x25078 = x25028;
      char x25079 = x1000[x25078];
      bool x25080 = x25079 != '|';
      bool x25085 = x25080;
      if (x25080) {
        long x25081 = x25028;
        char x25082 = x1000[x25081];
        bool x25083 = x25082 != '\n';
        x25085 = x25083;
      }
      bool x25086 = x25085;
      if (!x25086) break;
      x25028 = x25028 + 1;
    }
    x25028 = x25028 + 1;
    for (;;) {
      long x25096 = x25028;
      char x25097 = x1000[x25096];
      bool x25098 = x25097 != '|';
      bool x25103 = x25098;
      if (x25098) {
        long x25099 = x25028;
        char x25100 = x1000[x25099];
        bool x25101 = x25100 != '\n';
        x25103 = x25101;
      }
      bool x25104 = x25103;
      if (!x25104) break;
      x25028 = x25028 + 1;
    }
    x25028 = x25028 + 1;
    for (;;) {
      long x25114 = x25028;
      char x25115 = x1000[x25114];
      bool x25116 = x25115 != '|';
      bool x25121 = x25116;
      if (x25116) {
        long x25117 = x25028;
        char x25118 = x1000[x25117];
        bool x25119 = x25118 != '\n';
        x25121 = x25119;
      }
      bool x25122 = x25121;
      if (!x25122) break;
      x25028 = x25028 + 1;
    }
    x25028 = x25028 + 1;
    long x25131 = x25028;
    for (;;) {
      long x25132 = x25028;
      char x25133 = x1000[x25132];
      bool x25134 = x25133 != '|';
      bool x25139 = x25134;
      if (x25134) {
        long x25135 = x25028;
        char x25136 = x1000[x25135];
        bool x25137 = x25136 != '\n';
        x25139 = x25137;
      }
      bool x25140 = x25139;
      if (!x25140) break;
      x25028 = x25028 + 1;
    }
    x25028 = x25028 + 1;
    for (;;) {
      long x25151 = x25028;
      char x25152 = x1000[x25151];
      bool x25153 = x25152 != '|';
      bool x25158 = x25153;
      if (x25153) {
        long x25154 = x25028;
        char x25155 = x1000[x25154];
        bool x25156 = x25155 != '\n';
        x25158 = x25156;
      }
      bool x25159 = x25158;
      if (!x25159) break;
      x25028 = x25028 + 1;
    }
    x25028 = x25028 + 1;
    for (;;) {
      long x25174 = x25028;
      char x25175 = x1000[x25174];
      bool x25176 = x25175 != '|';
      bool x25181 = x25176;
      if (x25176) {
        long x25177 = x25028;
        char x25178 = x1000[x25177];
        bool x25179 = x25178 != '\n';
        x25181 = x25179;
      }
      bool x25182 = x25181;
      if (!x25182) break;
      x25028 = x25028 + 1;
    }
    x25028 = x25028 + 1;
    for (;;) {
      long x25194 = x25028;
      char x25195 = x1000[x25194];
      bool x25196 = x25195 != '.';
      bool x25201 = x25196;
      if (x25196) {
        long x25197 = x25028;
        char x25198 = x1000[x25197];
        bool x25199 = x25198 != '|';
        x25201 = x25199;
      }
      bool x25202 = x25201;
      bool x25207 = x25202;
      if (x25202) {
        long x25203 = x25028;
        char x25204 = x1000[x25203];
        bool x25205 = x25204 != '\n';
        x25207 = x25205;
      }
      bool x25208 = x25207;
      if (!x25208) break;
      x25028 = x25028 + 1;
    }
    long x25220 = x25028;
    char x25221 = x1000[x25220];
    bool x25222 = x25221 == '.';
    if (x25222) {
      x25028 = x25028 + 1;
      for (;;) {
        long x25224 = x25028;
        char x25225 = x1000[x25224];
        bool x25226 = x25225 != '|';
        bool x25231 = x25226;
        if (x25226) {
          long x25227 = x25028;
          char x25228 = x1000[x25227];
          bool x25229 = x25228 != '\n';
          x25231 = x25229;
        }
        bool x25232 = x25231;
        if (!x25232) break;
        x25028 = x25028 + 1;
      }
    } else {
    }
    x25028 = x25028 + 1;
    for (;;) {
      long x25257 = x25028;
      char x25258 = x1000[x25257];
      bool x25259 = x25258 != '|';
      bool x25264 = x25259;
      if (x25259) {
        long x25260 = x25028;
        char x25261 = x1000[x25260];
        bool x25262 = x25261 != '\n';
        x25264 = x25262;
      }
      bool x25265 = x25264;
      if (!x25265) break;
      x25028 = x25028 + 1;
    }
    x25028 = x25028 + 1;
    long x25275 = x25030;
    long x25276 = x25029;
    bool x25277 = x25275 == x25276;
    if (x25277) {
      long x25278 = x25276 * 4L;
      x25029 = x25278;
      printf("buffer.resize %d\n",x25278);
      int* x25281 = x25032;
      int* x25282 = (int*)realloc(x25281,x25278 * sizeof(int));
      x25032 = x25282;
      char** x25293 = x25040;
      char** x25294 = (char**)realloc(x25293,x25278 * sizeof(char*));
      x25040 = x25294;
    } else {
    }
    int* x25310 = x25032;
    x25310[x25275] = x25076;
    char** x25318 = x25040;
    char* x25148 = x1000+x25131;
    x25318[x25275] = x25148;
    x25030 = x25030 + 1;
  }
  long x2011 = DEFAULT_JOIN_HASH_SIZE;
  long x787 = DEFAULT_AGG_HASH_SIZE ;
  long x2034 = x2011 - 1L;
  long x802 = x787 - 1L;
  char x9306 = "Total"[0L];
  long x9307 = x9306 * 41L;
  char x9308 = "Total"[1L];
  long x9309 = x9307 + x9308;
  long x9310 = x9309 * 41L;
  char x9311 = "Total"[2L];
  long x9312 = x9310 + x9311;
  long x9313 = x9312 * 41L;
  char x9314 = "Total"[3L];
  long x9315 = x9313 + x9314;
  long x9316 = x9315 & x802;
  bool x975 = true == false;
  float x25607 = (float)100;
  double x25608 = (double)x25607;
  int x25331;
  for(x25331=0; x25331 < 5; x25331++) {
    bool x25332 = false;
    long x25333 = 0L;
    bool x25334 = false;
    long x25335 = 0L;
    int* x25338 = (int*)malloc(x2011 * sizeof(int));
    int* x25339 = x25338;
    char** x25346 = (char**)malloc(x2011 * sizeof(char*));
    char** x25347 = x25346;
    long x25356 = 0L;
    long* x25357 = (long*)malloc(x2011 * sizeof(long));
    long* x25358 = (long*)malloc(x2011 * sizeof(long));
    long x25359;
    for(x25359=0L; x25359 < x2011; x25359++) {
      x25357[x25359] = -1L;
    }
    struct Anon2025517469* x25365 = (struct Anon2025517469*)malloc(x787 * sizeof(struct Anon2025517469));
    struct Anon2025517469* x25366 = x25365;
    long x25367 = 0L;
    long* x25368 = (long*)malloc(x787 * sizeof(long));
    long x25369;
    for(x25369=0L; x25369 < x787; x25369++) {
      struct Anon2025517469* x25370 = x25366;
      struct Anon2025517469 x25371 = x25370[x25369];
      char* x25372 = x25371.key;;
      struct Anon189208763 x25373 = x25371.aggs;;
      struct Anon2025517469 x25374;
      x25374.exists = false;
      x25374.key = x25372;
      x25374.aggs = x25373;
      x25370[x25369] = x25374;
    }
    long x25380 = 0L;
    struct timeval x25623, x25624, x25625;
    gettimeofday(&x25623, NULL);
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x25382 = x25332;
      bool x25383 = !x25382;
      bool x25388 = x25383;
      if (x25383) {
        long x25384 = x25333;
        long x25385 = x25030;
        bool x25386 = x25384 < x25385;
        x25388 = x25386;
      }
      bool x25389 = x25388;
      if (!x25389) break;
      long x25391 = x25333;
      int* x25392 = x25032;
      int x25393 = x25392[x25391];
      char** x25400 = x25040;
      char* x25401 = x25400[x25391];
      x25333 = x25333 + 1;
      long x25412 = x25356;
      int* x25413 = x25339;
      x25413[x25412] = x25393;
      char** x25421 = x25347;
      x25421[x25412] = x25401;
      x25356 = x25356 + 1L;
      long x25432 = x25393 & x2034;
      long x25433 = x25357[x25432];
      x25357[x25432] = x25412;
      x25358[x25412] = x25433;
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x25439 = x25334;
      bool x25440 = !x25439;
      bool x25445 = x25440;
      if (x25440) {
        long x25441 = x25335;
        long x25442 = x24256;
        bool x25443 = x25441 < x25442;
        x25445 = x25443;
      }
      bool x25446 = x25445;
      if (!x25446) break;
      long x25448 = x25335;
      int* x25451 = x24260;
      int x25452 = x25451[x25448];
      double* x25459 = x24268;
      double x25460 = x25459[x25448];
      double* x25461 = x24270;
      double x25462 = x25461[x25448];
      long* x25469 = x24278;
      long x25470 = x25469[x25448];
      x25335 = x25335 + 1;
      bool x25483 = x25470 >= 19940301L;
      bool x25485 = x25483;
      if (x25483) {
        bool x25484 = x25470 < 19940401L;
        x25485 = x25484;
      }
      bool x25486 = x25485;
      if (x25486) {
        long x25487 = x25452 & x2034;
        long x25488 = x25357[x25487];
        long x25489 = x25488;
        double x25533 = 1.0 - x25462;
        double x25534 = x25460 * x25533;
        for (;;) {
          long x25490 = x25489;
          bool x25491 = x25490 != -1;
          if (!x25491) break;
          long x25493 = x25489;
          int* x25494 = x25339;
          int x25495 = x25494[x25493];
          char** x25502 = x25347;
          char* x25503 = x25502[x25493];
          long x25513 = x25358[x25493];
          x25489 = x25513;
          bool x25515 = x25495 == x25452;
          if (x25515) {
            long x25519 = x9316;
            struct Anon2025517469* x25520 = x25366;
            struct Anon2025517469 x25521 = x25520[x9316];
            struct Anon2025517469 x25522 = x25521;
            bool x25523 = x25521.exists;;
            bool x25528 = x25523;
            if (x25523) {
              struct Anon2025517469 x25524 = x25522;
              char* x25525 = x25524.key;;
              bool x25526 = strcmp(x25525,"Total") == 0;;
              x25528 = x25526;
            }
            bool x25529 = x25528;
            if (x25529) {
              struct Anon189208763 x25530 = x25521.aggs;;
              char* x25540 = x25521.key;;
              bool x25531 = strncmp(x25503,"PROMO", strlen("PROMO")) == 0;;
              double x25536;
              if (x25531) {
                double x25532 = x25530._0;;
                double x25535 = x25532 + x25534;
                x25536 = x25535;
              } else {
                double x25532 = x25530._0;;
                x25536 = x25532;
              }
              double x25537 = x25530._1;;
              double x25538 = x25537 + x25534;
              struct Anon189208763 x25539;
              x25539._0 = x25536;
              x25539._1 = x25538;
              struct Anon2025517469 x25541;
              x25541.exists = true;
              x25541.key = x25540;
              x25541.aggs = x25539;
              x25520[x9316] = x25541;
            } else {
              bool x25531 = strncmp(x25503,"PROMO", strlen("PROMO")) == 0;;
              double x25573;
              if (x25531) {
                x25573 = x25534;
              } else {
                x25573 = 0.0;
              }
              struct Anon189208763 x25574;
              x25574._0 = x25573;
              x25574._1 = x25534;
              struct Anon2025517469 x25575;
              x25575.exists = true;
              x25575.key = "Total";
              x25575.aggs = x25574;
              for (;;) {
                struct Anon2025517469 x25544 = x25522;
                bool x25545 = x25544.exists;;
                bool x25584;
                if (x25545) {
                  char* x25546 = x25544.key;;
                  bool x25547 = strcmp(x25546,"Total") == 0;;
                  bool x25570;
                  if (x25547) {
                    struct Anon189208763 x25548 = x25544.aggs;;
                    long x25555 = x25519;
                    struct Anon2025517469* x25557 = x25366;
                    double x25551;
                    if (x25531) {
                      double x25549 = x25548._0;;
                      double x25550 = x25549 + x25534;
                      x25551 = x25550;
                    } else {
                      double x25549 = x25548._0;;
                      x25551 = x25549;
                    }
                    double x25552 = x25548._1;;
                    double x25553 = x25552 + x25534;
                    struct Anon189208763 x25554;
                    x25554._0 = x25551;
                    x25554._1 = x25553;
                    struct Anon2025517469 x25556;
                    x25556.exists = true;
                    x25556.key = x25546;
                    x25556.aggs = x25554;
                    x25557[x25555] = x25556;
                    x25570 = false;
                  } else {
                    long x25560 = x25519;
                    long x25561 = x25560 + 1L;
                    long x25562 = x25561 % x802;
                    x25519 = x25562;
                    struct Anon2025517469* x25564 = x25366;
                    struct Anon2025517469 x25565 = x25564[x25562];
                    x25522 = x25565;
                    x25570 = true;
                  }
                  x25584 = x25570;
                } else {
                  long x25572 = x25519;
                  struct Anon2025517469* x25576 = x25366;
                  x25576[x25572] = x25575;
                  long x25578 = x25367;
                  x25368[x25578] = x25572;
                  x25367 = x25367 + 1L;
                  x25584 = false;
                }
                if (!x25584) break;
              }
            }
          } else {
          }
        }
      } else {
      }
    }
    long x25599 = x25367;
    long x25601;
    for(x25601=0L; x25601 < x25599; x25601++) {
      long x25602 = x25368[x25601];
      struct Anon2025517469* x25603 = x25366;
      struct Anon2025517469 x25604 = x25603[x25602];
      struct Anon189208763 x25605 = x25604.aggs;;
      if (x975) {
      } else {
        double x25606 = x25605._0;;
        double x25609 = x25606 * x25608;
        double x25610 = x25605._1;;
        double x25611 = x25609 / x25610;
        printf("%.4f\n",x25611);
        x25380 = x25380 + 1L;
      }
    }
    long x25620 = x25380;
    printf("(%d rows)\n",x25620);
    gettimeofday(&x25624, NULL);
    timeval_subtract(&x25625, &x25624, &x25623);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x25625.tv_sec * 1000) + (x25625.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
