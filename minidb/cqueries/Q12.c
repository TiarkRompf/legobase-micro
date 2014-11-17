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
int main(int x21718, char** x21719) {
  long x21720 = 0L;
  long x6 = DEFAULT_INPUT_SIZE;
  long x21721 = x6;
  long x21722 = 0L;
  int* x21723 = (int*)malloc(x6 * sizeof(int));
  int* x21724 = x21723;
  long* x21743 = (long*)malloc(x6 * sizeof(long));
  long* x21744 = x21743;
  long* x21745 = (long*)malloc(x6 * sizeof(long));
  long* x21746 = x21745;
  long* x21747 = (long*)malloc(x6 * sizeof(long));
  long* x21748 = x21747;
  char** x21751 = (char**)malloc(x6 * sizeof(char*));
  char** x21752 = x21751;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  long x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    long x21755 = x21720;
    bool x21756 = x21755 < x3;
    if (!x21756) break;
    int x21759 = 0;
    for (;;) {
      long x21760 = x21720;
      char x21761 = x4[x21760];
      bool x21762 = x21761 != '|';
      bool x21767 = x21762;
      if (x21762) {
        long x21763 = x21720;
        char x21764 = x4[x21763];
        bool x21765 = x21764 != '\n';
        x21767 = x21765;
      }
      bool x21768 = x21767;
      if (!x21768) break;
      int x21770 = x21759;
      long x21772 = x21720;
      int x21771 = x21770 * 10;
      char x21773 = x4[x21772];
      char x21774 = x21773 - '0';
      int x21775 = x21771 + x21774;
      x21759 = x21775;
      x21720 = x21720 + 1;
    }
    x21720 = x21720 + 1;
    int x21781 = x21759;
    for (;;) {
      long x21784 = x21720;
      char x21785 = x4[x21784];
      bool x21786 = x21785 != '|';
      bool x21791 = x21786;
      if (x21786) {
        long x21787 = x21720;
        char x21788 = x4[x21787];
        bool x21789 = x21788 != '\n';
        x21791 = x21789;
      }
      bool x21792 = x21791;
      if (!x21792) break;
      x21720 = x21720 + 1;
    }
    x21720 = x21720 + 1;
    for (;;) {
      long x21808 = x21720;
      char x21809 = x4[x21808];
      bool x21810 = x21809 != '|';
      bool x21815 = x21810;
      if (x21810) {
        long x21811 = x21720;
        char x21812 = x4[x21811];
        bool x21813 = x21812 != '\n';
        x21815 = x21813;
      }
      bool x21816 = x21815;
      if (!x21816) break;
      x21720 = x21720 + 1;
    }
    x21720 = x21720 + 1;
    for (;;) {
      long x21832 = x21720;
      char x21833 = x4[x21832];
      bool x21834 = x21833 != '|';
      bool x21839 = x21834;
      if (x21834) {
        long x21835 = x21720;
        char x21836 = x4[x21835];
        bool x21837 = x21836 != '\n';
        x21839 = x21837;
      }
      bool x21840 = x21839;
      if (!x21840) break;
      x21720 = x21720 + 1;
    }
    x21720 = x21720 + 1;
    for (;;) {
      long x21857 = x21720;
      char x21858 = x4[x21857];
      bool x21859 = x21858 != '.';
      bool x21864 = x21859;
      if (x21859) {
        long x21860 = x21720;
        char x21861 = x4[x21860];
        bool x21862 = x21861 != '|';
        x21864 = x21862;
      }
      bool x21865 = x21864;
      bool x21870 = x21865;
      if (x21865) {
        long x21866 = x21720;
        char x21867 = x4[x21866];
        bool x21868 = x21867 != '\n';
        x21870 = x21868;
      }
      bool x21871 = x21870;
      if (!x21871) break;
      x21720 = x21720 + 1;
    }
    long x21883 = x21720;
    char x21884 = x4[x21883];
    bool x21885 = x21884 == '.';
    if (x21885) {
      x21720 = x21720 + 1;
      for (;;) {
        long x21887 = x21720;
        char x21888 = x4[x21887];
        bool x21889 = x21888 != '|';
        bool x21894 = x21889;
        if (x21889) {
          long x21890 = x21720;
          char x21891 = x4[x21890];
          bool x21892 = x21891 != '\n';
          x21894 = x21892;
        }
        bool x21895 = x21894;
        if (!x21895) break;
        x21720 = x21720 + 1;
      }
    } else {
    }
    x21720 = x21720 + 1;
    for (;;) {
      long x21922 = x21720;
      char x21923 = x4[x21922];
      bool x21924 = x21923 != '.';
      bool x21929 = x21924;
      if (x21924) {
        long x21925 = x21720;
        char x21926 = x4[x21925];
        bool x21927 = x21926 != '|';
        x21929 = x21927;
      }
      bool x21930 = x21929;
      bool x21935 = x21930;
      if (x21930) {
        long x21931 = x21720;
        char x21932 = x4[x21931];
        bool x21933 = x21932 != '\n';
        x21935 = x21933;
      }
      bool x21936 = x21935;
      if (!x21936) break;
      x21720 = x21720 + 1;
    }
    long x21948 = x21720;
    char x21949 = x4[x21948];
    bool x21950 = x21949 == '.';
    if (x21950) {
      x21720 = x21720 + 1;
      for (;;) {
        long x21952 = x21720;
        char x21953 = x4[x21952];
        bool x21954 = x21953 != '|';
        bool x21959 = x21954;
        if (x21954) {
          long x21955 = x21720;
          char x21956 = x4[x21955];
          bool x21957 = x21956 != '\n';
          x21959 = x21957;
        }
        bool x21960 = x21959;
        if (!x21960) break;
        x21720 = x21720 + 1;
      }
    } else {
    }
    x21720 = x21720 + 1;
    for (;;) {
      long x21987 = x21720;
      char x21988 = x4[x21987];
      bool x21989 = x21988 != '.';
      bool x21994 = x21989;
      if (x21989) {
        long x21990 = x21720;
        char x21991 = x4[x21990];
        bool x21992 = x21991 != '|';
        x21994 = x21992;
      }
      bool x21995 = x21994;
      bool x22000 = x21995;
      if (x21995) {
        long x21996 = x21720;
        char x21997 = x4[x21996];
        bool x21998 = x21997 != '\n';
        x22000 = x21998;
      }
      bool x22001 = x22000;
      if (!x22001) break;
      x21720 = x21720 + 1;
    }
    long x22013 = x21720;
    char x22014 = x4[x22013];
    bool x22015 = x22014 == '.';
    if (x22015) {
      x21720 = x21720 + 1;
      for (;;) {
        long x22017 = x21720;
        char x22018 = x4[x22017];
        bool x22019 = x22018 != '|';
        bool x22024 = x22019;
        if (x22019) {
          long x22020 = x21720;
          char x22021 = x4[x22020];
          bool x22022 = x22021 != '\n';
          x22024 = x22022;
        }
        bool x22025 = x22024;
        if (!x22025) break;
        x21720 = x21720 + 1;
      }
    } else {
    }
    x21720 = x21720 + 1;
    for (;;) {
      long x22052 = x21720;
      char x22053 = x4[x22052];
      bool x22054 = x22053 != '.';
      bool x22059 = x22054;
      if (x22054) {
        long x22055 = x21720;
        char x22056 = x4[x22055];
        bool x22057 = x22056 != '|';
        x22059 = x22057;
      }
      bool x22060 = x22059;
      bool x22065 = x22060;
      if (x22060) {
        long x22061 = x21720;
        char x22062 = x4[x22061];
        bool x22063 = x22062 != '\n';
        x22065 = x22063;
      }
      bool x22066 = x22065;
      if (!x22066) break;
      x21720 = x21720 + 1;
    }
    long x22078 = x21720;
    char x22079 = x4[x22078];
    bool x22080 = x22079 == '.';
    if (x22080) {
      x21720 = x21720 + 1;
      for (;;) {
        long x22082 = x21720;
        char x22083 = x4[x22082];
        bool x22084 = x22083 != '|';
        bool x22089 = x22084;
        if (x22084) {
          long x22085 = x21720;
          char x22086 = x4[x22085];
          bool x22087 = x22086 != '\n';
          x22089 = x22087;
        }
        bool x22090 = x22089;
        if (!x22090) break;
        x21720 = x21720 + 1;
      }
    } else {
    }
    x21720 = x21720 + 1;
    x21720 = x21720 + 2;
    x21720 = x21720 + 2;
    int x22121 = 0;
    for (;;) {
      long x22122 = x21720;
      char x22123 = x4[x22122];
      bool x22124 = x22123 != '-';
      bool x22129 = x22124;
      if (x22124) {
        long x22125 = x21720;
        char x22126 = x4[x22125];
        bool x22127 = x22126 != '\n';
        x22129 = x22127;
      }
      bool x22130 = x22129;
      if (!x22130) break;
      int x22132 = x22121;
      long x22134 = x21720;
      int x22133 = x22132 * 10;
      char x22135 = x4[x22134];
      char x22136 = x22135 - '0';
      int x22137 = x22133 + x22136;
      x22121 = x22137;
      x21720 = x21720 + 1;
    }
    x21720 = x21720 + 1;
    int x22143 = x22121;
    int x22145 = 0;
    for (;;) {
      long x22146 = x21720;
      char x22147 = x4[x22146];
      bool x22148 = x22147 != '-';
      bool x22153 = x22148;
      if (x22148) {
        long x22149 = x21720;
        char x22150 = x4[x22149];
        bool x22151 = x22150 != '\n';
        x22153 = x22151;
      }
      bool x22154 = x22153;
      if (!x22154) break;
      int x22156 = x22145;
      long x22158 = x21720;
      int x22157 = x22156 * 10;
      char x22159 = x4[x22158];
      char x22160 = x22159 - '0';
      int x22161 = x22157 + x22160;
      x22145 = x22161;
      x21720 = x21720 + 1;
    }
    x21720 = x21720 + 1;
    int x22167 = x22145;
    int x22169 = 0;
    for (;;) {
      long x22170 = x21720;
      char x22171 = x4[x22170];
      bool x22172 = x22171 != '|';
      bool x22177 = x22172;
      if (x22172) {
        long x22173 = x21720;
        char x22174 = x4[x22173];
        bool x22175 = x22174 != '\n';
        x22177 = x22175;
      }
      bool x22178 = x22177;
      if (!x22178) break;
      int x22180 = x22169;
      long x22182 = x21720;
      int x22181 = x22180 * 10;
      char x22183 = x4[x22182];
      char x22184 = x22183 - '0';
      int x22185 = x22181 + x22184;
      x22169 = x22185;
      x21720 = x21720 + 1;
    }
    x21720 = x21720 + 1;
    int x22191 = x22169;
    int x22197 = 0;
    for (;;) {
      long x22198 = x21720;
      char x22199 = x4[x22198];
      bool x22200 = x22199 != '-';
      bool x22205 = x22200;
      if (x22200) {
        long x22201 = x21720;
        char x22202 = x4[x22201];
        bool x22203 = x22202 != '\n';
        x22205 = x22203;
      }
      bool x22206 = x22205;
      if (!x22206) break;
      int x22208 = x22197;
      long x22210 = x21720;
      int x22209 = x22208 * 10;
      char x22211 = x4[x22210];
      char x22212 = x22211 - '0';
      int x22213 = x22209 + x22212;
      x22197 = x22213;
      x21720 = x21720 + 1;
    }
    x21720 = x21720 + 1;
    int x22219 = x22197;
    int x22221 = 0;
    for (;;) {
      long x22222 = x21720;
      char x22223 = x4[x22222];
      bool x22224 = x22223 != '-';
      bool x22229 = x22224;
      if (x22224) {
        long x22225 = x21720;
        char x22226 = x4[x22225];
        bool x22227 = x22226 != '\n';
        x22229 = x22227;
      }
      bool x22230 = x22229;
      if (!x22230) break;
      int x22232 = x22221;
      long x22234 = x21720;
      int x22233 = x22232 * 10;
      char x22235 = x4[x22234];
      char x22236 = x22235 - '0';
      int x22237 = x22233 + x22236;
      x22221 = x22237;
      x21720 = x21720 + 1;
    }
    x21720 = x21720 + 1;
    int x22243 = x22221;
    int x22245 = 0;
    for (;;) {
      long x22246 = x21720;
      char x22247 = x4[x22246];
      bool x22248 = x22247 != '|';
      bool x22253 = x22248;
      if (x22248) {
        long x22249 = x21720;
        char x22250 = x4[x22249];
        bool x22251 = x22250 != '\n';
        x22253 = x22251;
      }
      bool x22254 = x22253;
      if (!x22254) break;
      int x22256 = x22245;
      long x22258 = x21720;
      int x22257 = x22256 * 10;
      char x22259 = x4[x22258];
      char x22260 = x22259 - '0';
      int x22261 = x22257 + x22260;
      x22245 = x22261;
      x21720 = x21720 + 1;
    }
    x21720 = x21720 + 1;
    int x22267 = x22245;
    int x22273 = 0;
    for (;;) {
      long x22274 = x21720;
      char x22275 = x4[x22274];
      bool x22276 = x22275 != '-';
      bool x22281 = x22276;
      if (x22276) {
        long x22277 = x21720;
        char x22278 = x4[x22277];
        bool x22279 = x22278 != '\n';
        x22281 = x22279;
      }
      bool x22282 = x22281;
      if (!x22282) break;
      int x22284 = x22273;
      long x22286 = x21720;
      int x22285 = x22284 * 10;
      char x22287 = x4[x22286];
      char x22288 = x22287 - '0';
      int x22289 = x22285 + x22288;
      x22273 = x22289;
      x21720 = x21720 + 1;
    }
    x21720 = x21720 + 1;
    int x22295 = x22273;
    int x22297 = 0;
    for (;;) {
      long x22298 = x21720;
      char x22299 = x4[x22298];
      bool x22300 = x22299 != '-';
      bool x22305 = x22300;
      if (x22300) {
        long x22301 = x21720;
        char x22302 = x4[x22301];
        bool x22303 = x22302 != '\n';
        x22305 = x22303;
      }
      bool x22306 = x22305;
      if (!x22306) break;
      int x22308 = x22297;
      long x22310 = x21720;
      int x22309 = x22308 * 10;
      char x22311 = x4[x22310];
      char x22312 = x22311 - '0';
      int x22313 = x22309 + x22312;
      x22297 = x22313;
      x21720 = x21720 + 1;
    }
    x21720 = x21720 + 1;
    int x22319 = x22297;
    int x22321 = 0;
    for (;;) {
      long x22322 = x21720;
      char x22323 = x4[x22322];
      bool x22324 = x22323 != '|';
      bool x22329 = x22324;
      if (x22324) {
        long x22325 = x21720;
        char x22326 = x4[x22325];
        bool x22327 = x22326 != '\n';
        x22329 = x22327;
      }
      bool x22330 = x22329;
      if (!x22330) break;
      int x22332 = x22321;
      long x22334 = x21720;
      int x22333 = x22332 * 10;
      char x22335 = x4[x22334];
      char x22336 = x22335 - '0';
      int x22337 = x22333 + x22336;
      x22321 = x22337;
      x21720 = x21720 + 1;
    }
    x21720 = x21720 + 1;
    int x22343 = x22321;
    for (;;) {
      long x22349 = x21720;
      char x22350 = x4[x22349];
      bool x22351 = x22350 != '|';
      bool x22356 = x22351;
      if (x22351) {
        long x22352 = x21720;
        char x22353 = x4[x22352];
        bool x22354 = x22353 != '\n';
        x22356 = x22354;
      }
      bool x22357 = x22356;
      if (!x22357) break;
      x21720 = x21720 + 1;
    }
    x21720 = x21720 + 1;
    long x22366 = x21720;
    for (;;) {
      long x22367 = x21720;
      char x22368 = x4[x22367];
      bool x22369 = x22368 != '|';
      bool x22374 = x22369;
      if (x22369) {
        long x22370 = x21720;
        char x22371 = x4[x22370];
        bool x22372 = x22371 != '\n';
        x22374 = x22372;
      }
      bool x22375 = x22374;
      if (!x22375) break;
      x21720 = x21720 + 1;
    }
    x21720 = x21720 + 1;
    for (;;) {
      long x22385 = x21720;
      char x22386 = x4[x22385];
      bool x22387 = x22386 != '|';
      bool x22392 = x22387;
      if (x22387) {
        long x22388 = x21720;
        char x22389 = x4[x22388];
        bool x22390 = x22389 != '\n';
        x22392 = x22390;
      }
      bool x22393 = x22392;
      if (!x22393) break;
      x21720 = x21720 + 1;
    }
    x21720 = x21720 + 1;
    long x22403 = x21722;
    long x22404 = x21721;
    bool x22405 = x22403 == x22404;
    if (x22405) {
      long x22406 = x22404 * 4L;
      x21721 = x22406;
      printf("buffer.resize %d\n",x22406);
      int* x22409 = x21724;
      int* x22410 = (int*)realloc(x22409,x22406 * sizeof(int));
      x21724 = x22410;
      long* x22439 = x21744;
      long* x22440 = (long*)realloc(x22439,x22406 * sizeof(long));
      x21744 = x22440;
      long* x22442 = x21746;
      long* x22443 = (long*)realloc(x22442,x22406 * sizeof(long));
      x21746 = x22443;
      long* x22445 = x21748;
      long* x22446 = (long*)realloc(x22445,x22406 * sizeof(long));
      x21748 = x22446;
      char** x22451 = x21752;
      char** x22452 = (char**)realloc(x22451,x22406 * sizeof(char*));
      x21752 = x22452;
    } else {
    }
    int* x22459 = x21724;
    x22459[x22403] = x21781;
    long* x22479 = x21744;
    long x22192 = x22143 * 10000L;
    long x22193 = x22167 * 100L;
    long x22194 = x22192 + x22193;
    long x22195 = x22194 + x22191;
    x22479[x22403] = x22195;
    long* x22481 = x21746;
    long x22268 = x22219 * 10000L;
    long x22269 = x22243 * 100L;
    long x22270 = x22268 + x22269;
    long x22271 = x22270 + x22267;
    x22481[x22403] = x22271;
    long* x22483 = x21748;
    long x22344 = x22295 * 10000L;
    long x22345 = x22319 * 100L;
    long x22346 = x22344 + x22345;
    long x22347 = x22346 + x22343;
    x22483[x22403] = x22347;
    char** x22487 = x21752;
    char* x22383 = x4+x22366;
    x22487[x22403] = x22383;
    x21722 = x21722 + 1;
  }
  long x22494 = 0L;
  long x22495 = x6;
  long x22496 = 0L;
  int* x22497 = (int*)malloc(x6 * sizeof(int));
  int* x22498 = x22497;
  char** x22507 = (char**)malloc(x6 * sizeof(char*));
  char** x22508 = x22507;
  int x3371 = open("../databases/sf2/orders.tbl",0);
  long x3372 = fsize(x3371);
  char* x3373 = mmap(0, x3372, PROT_READ, MAP_FILE | MAP_SHARED, x3371, 0);
  for (;;) {
    long x22515 = x22494;
    bool x22516 = x22515 < x3372;
    if (!x22516) break;
    int x22519 = 0;
    for (;;) {
      long x22520 = x22494;
      char x22521 = x3373[x22520];
      bool x22522 = x22521 != '|';
      bool x22527 = x22522;
      if (x22522) {
        long x22523 = x22494;
        char x22524 = x3373[x22523];
        bool x22525 = x22524 != '\n';
        x22527 = x22525;
      }
      bool x22528 = x22527;
      if (!x22528) break;
      int x22530 = x22519;
      long x22532 = x22494;
      int x22531 = x22530 * 10;
      char x22533 = x3373[x22532];
      char x22534 = x22533 - '0';
      int x22535 = x22531 + x22534;
      x22519 = x22535;
      x22494 = x22494 + 1;
    }
    x22494 = x22494 + 1;
    int x22541 = x22519;
    for (;;) {
      long x22544 = x22494;
      char x22545 = x3373[x22544];
      bool x22546 = x22545 != '|';
      bool x22551 = x22546;
      if (x22546) {
        long x22547 = x22494;
        char x22548 = x3373[x22547];
        bool x22549 = x22548 != '\n';
        x22551 = x22549;
      }
      bool x22552 = x22551;
      if (!x22552) break;
      x22494 = x22494 + 1;
    }
    x22494 = x22494 + 1;
    x22494 = x22494 + 2;
    for (;;) {
      long x22572 = x22494;
      char x22573 = x3373[x22572];
      bool x22574 = x22573 != '.';
      bool x22579 = x22574;
      if (x22574) {
        long x22575 = x22494;
        char x22576 = x3373[x22575];
        bool x22577 = x22576 != '|';
        x22579 = x22577;
      }
      bool x22580 = x22579;
      bool x22585 = x22580;
      if (x22580) {
        long x22581 = x22494;
        char x22582 = x3373[x22581];
        bool x22583 = x22582 != '\n';
        x22585 = x22583;
      }
      bool x22586 = x22585;
      if (!x22586) break;
      x22494 = x22494 + 1;
    }
    long x22598 = x22494;
    char x22599 = x3373[x22598];
    bool x22600 = x22599 == '.';
    if (x22600) {
      x22494 = x22494 + 1;
      for (;;) {
        long x22602 = x22494;
        char x22603 = x3373[x22602];
        bool x22604 = x22603 != '|';
        bool x22609 = x22604;
        if (x22604) {
          long x22605 = x22494;
          char x22606 = x3373[x22605];
          bool x22607 = x22606 != '\n';
          x22609 = x22607;
        }
        bool x22610 = x22609;
        if (!x22610) break;
        x22494 = x22494 + 1;
      }
    } else {
    }
    x22494 = x22494 + 1;
    for (;;) {
      long x22636 = x22494;
      char x22637 = x3373[x22636];
      bool x22638 = x22637 != '-';
      bool x22643 = x22638;
      if (x22638) {
        long x22639 = x22494;
        char x22640 = x3373[x22639];
        bool x22641 = x22640 != '\n';
        x22643 = x22641;
      }
      bool x22644 = x22643;
      if (!x22644) break;
      x22494 = x22494 + 1;
    }
    x22494 = x22494 + 1;
    for (;;) {
      long x22660 = x22494;
      char x22661 = x3373[x22660];
      bool x22662 = x22661 != '-';
      bool x22667 = x22662;
      if (x22662) {
        long x22663 = x22494;
        char x22664 = x3373[x22663];
        bool x22665 = x22664 != '\n';
        x22667 = x22665;
      }
      bool x22668 = x22667;
      if (!x22668) break;
      x22494 = x22494 + 1;
    }
    x22494 = x22494 + 1;
    for (;;) {
      long x22684 = x22494;
      char x22685 = x3373[x22684];
      bool x22686 = x22685 != '|';
      bool x22691 = x22686;
      if (x22686) {
        long x22687 = x22494;
        char x22688 = x3373[x22687];
        bool x22689 = x22688 != '\n';
        x22691 = x22689;
      }
      bool x22692 = x22691;
      if (!x22692) break;
      x22494 = x22494 + 1;
    }
    x22494 = x22494 + 1;
    long x22710 = x22494;
    for (;;) {
      long x22711 = x22494;
      char x22712 = x3373[x22711];
      bool x22713 = x22712 != '|';
      bool x22718 = x22713;
      if (x22713) {
        long x22714 = x22494;
        char x22715 = x3373[x22714];
        bool x22716 = x22715 != '\n';
        x22718 = x22716;
      }
      bool x22719 = x22718;
      if (!x22719) break;
      x22494 = x22494 + 1;
    }
    x22494 = x22494 + 1;
    for (;;) {
      long x22729 = x22494;
      char x22730 = x3373[x22729];
      bool x22731 = x22730 != '|';
      bool x22736 = x22731;
      if (x22731) {
        long x22732 = x22494;
        char x22733 = x3373[x22732];
        bool x22734 = x22733 != '\n';
        x22736 = x22734;
      }
      bool x22737 = x22736;
      if (!x22737) break;
      x22494 = x22494 + 1;
    }
    x22494 = x22494 + 1;
    for (;;) {
      long x22748 = x22494;
      char x22749 = x3373[x22748];
      bool x22750 = x22749 != '|';
      bool x22755 = x22750;
      if (x22750) {
        long x22751 = x22494;
        char x22752 = x3373[x22751];
        bool x22753 = x22752 != '\n';
        x22755 = x22753;
      }
      bool x22756 = x22755;
      if (!x22756) break;
      x22494 = x22494 + 1;
    }
    x22494 = x22494 + 1;
    for (;;) {
      long x22771 = x22494;
      char x22772 = x3373[x22771];
      bool x22773 = x22772 != '|';
      bool x22778 = x22773;
      if (x22773) {
        long x22774 = x22494;
        char x22775 = x3373[x22774];
        bool x22776 = x22775 != '\n';
        x22778 = x22776;
      }
      bool x22779 = x22778;
      if (!x22779) break;
      x22494 = x22494 + 1;
    }
    x22494 = x22494 + 1;
    long x22789 = x22496;
    long x22790 = x22495;
    bool x22791 = x22789 == x22790;
    if (x22791) {
      long x22792 = x22790 * 4L;
      x22495 = x22792;
      printf("buffer.resize %d\n",x22792);
      int* x22795 = x22498;
      int* x22796 = (int*)realloc(x22795,x22792 * sizeof(int));
      x22498 = x22796;
      char** x22810 = x22508;
      char** x22811 = (char**)realloc(x22810,x22792 * sizeof(char*));
      x22508 = x22811;
    } else {
    }
    int* x22824 = x22498;
    x22824[x22789] = x22541;
    char** x22834 = x22508;
    char* x22727 = x3373+x22710;
    x22834[x22789] = x22727;
    x22496 = x22496 + 1;
  }
  long x2011 = DEFAULT_JOIN_HASH_SIZE;
  long x787 = DEFAULT_AGG_HASH_SIZE ;
  long x2034 = x2011 - 1L;
  long x802 = x787 - 1L;
  bool x975 = true == false;
  int x22845;
  for(x22845=0; x22845 < 5; x22845++) {
    bool x22846 = false;
    long x22847 = 0L;
    bool x22848 = false;
    long x22849 = 0L;
    int* x22852 = (int*)malloc(x2011 * sizeof(int));
    int* x22853 = x22852;
    char** x22862 = (char**)malloc(x2011 * sizeof(char*));
    char** x22863 = x22862;
    long x22870 = 0L;
    long* x22871 = (long*)malloc(x2011 * sizeof(long));
    long* x22872 = (long*)malloc(x2011 * sizeof(long));
    long x22873;
    for(x22873=0L; x22873 < x2011; x22873++) {
      x22871[x22873] = -1L;
    }
    struct Anon2025517469* x22879 = (struct Anon2025517469*)malloc(x787 * sizeof(struct Anon2025517469));
    struct Anon2025517469* x22880 = x22879;
    long x22881 = 0L;
    long* x22882 = (long*)malloc(x787 * sizeof(long));
    long x22883;
    for(x22883=0L; x22883 < x787; x22883++) {
      struct Anon2025517469* x22884 = x22880;
      struct Anon2025517469 x22885 = x22884[x22883];
      char* x22886 = x22885.key;;
      struct Anon189208763 x22887 = x22885.aggs;;
      struct Anon2025517469 x22888;
      x22888.exists = false;
      x22888.key = x22886;
      x22888.aggs = x22887;
      x22884[x22883] = x22888;
    }
    long x22893 = 0L;
    struct timeval x23175, x23176, x23177;
    gettimeofday(&x23175, NULL);
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x22895 = x22846;
      bool x22896 = !x22895;
      bool x22901 = x22896;
      if (x22896) {
        long x22897 = x22847;
        long x22898 = x22496;
        bool x22899 = x22897 < x22898;
        x22901 = x22899;
      }
      bool x22902 = x22901;
      if (!x22902) break;
      long x22904 = x22847;
      int* x22905 = x22498;
      int x22906 = x22905[x22904];
      char** x22915 = x22508;
      char* x22916 = x22915[x22904];
      x22847 = x22847 + 1;
      long x22925 = x22870;
      int* x22926 = x22853;
      x22926[x22925] = x22906;
      char** x22936 = x22863;
      x22936[x22925] = x22916;
      x22870 = x22870 + 1L;
      long x22945 = x22906 & x2034;
      long x22946 = x22871[x22945];
      x22871[x22945] = x22925;
      x22872[x22925] = x22946;
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x22952 = x22848;
      bool x22953 = !x22952;
      bool x22958 = x22953;
      if (x22953) {
        long x22954 = x22849;
        long x22955 = x21722;
        bool x22956 = x22954 < x22955;
        x22958 = x22956;
      }
      bool x22959 = x22958;
      if (!x22959) break;
      long x22961 = x22849;
      int* x22962 = x21724;
      int x22963 = x22962[x22961];
      long* x22982 = x21744;
      long x22983 = x22982[x22961];
      long* x22984 = x21746;
      long x22985 = x22984[x22961];
      long* x22986 = x21748;
      long x22987 = x22986[x22961];
      char** x22990 = x21752;
      char* x22991 = x22990[x22961];
      x22849 = x22849 + 1;
      bool x22996 = x22987 < 19950101L;
      bool x22998 = x22996;
      if (x22996) {
        bool x22997 = x22985 < 19950101L;
        x22998 = x22997;
      }
      bool x22999 = x22998;
      bool x23001 = x22999;
      if (x22999) {
        bool x23000 = x22983 < 19950101L;
        x23001 = x23000;
      }
      bool x23002 = x23001;
      bool x23004 = x23002;
      if (x23002) {
        bool x23003 = x22983 < x22985;
        x23004 = x23003;
      }
      bool x23005 = x23004;
      bool x23007 = x23005;
      if (x23005) {
        bool x23006 = x22985 < x22987;
        x23007 = x23006;
      }
      bool x23008 = x23007;
      bool x23010 = x23008;
      if (x23008) {
        bool x23009 = x22987 >= 19940101L;
        x23010 = x23009;
      }
      bool x23011 = x23010;
      bool x23016 = x23011;
      if (x23011) {
        bool x23012 = strcmp(x22991,"MAIL") == 0;;
        bool x23014 = x23012;
        if (x23012 == false) {
          bool x23013 = strcmp(x22991,"SHIP") == 0;;
          x23014 = x23013;
        }
        bool x23015 = x23014;
        x23016 = x23015;
      }
      bool x23017 = x23016;
      if (x23017) {
        long x23018 = x22963 & x2034;
        long x23019 = x22871[x23018];
        long x23020 = x23019;
        char x23050 = x22991[0L];
        long x23051 = x23050 * 41L;
        char x23052 = x22991[1L];
        long x23053 = x23051 + x23052;
        long x23054 = x23053 * 41L;
        char x23055 = x22991[2L];
        long x23056 = x23054 + x23055;
        long x23057 = x23056 * 41L;
        char x23058 = x22991[3L];
        long x23059 = x23057 + x23058;
        long x23060 = x23059 & x802;
        for (;;) {
          long x23021 = x23020;
          bool x23022 = x23021 != -1;
          if (!x23022) break;
          long x23024 = x23020;
          int* x23025 = x22853;
          int x23026 = x23025[x23024];
          char** x23035 = x22863;
          char* x23036 = x23035[x23024];
          long x23044 = x22872[x23024];
          x23020 = x23044;
          bool x23046 = x23026 == x22963;
          if (x23046) {
            long x23061 = x23060;
            struct Anon2025517469* x23062 = x22880;
            struct Anon2025517469 x23063 = x23062[x23060];
            struct Anon2025517469 x23064 = x23063;
            bool x23065 = x23063.exists;;
            bool x23070 = x23065;
            if (x23065) {
              struct Anon2025517469 x23066 = x23064;
              char* x23067 = x23066.key;;
              bool x23068 = strcmp(x23067,x22991) == 0;;
              x23070 = x23068;
            }
            bool x23071 = x23070;
            if (x23071) {
              struct Anon189208763 x23072 = x23063.aggs;;
              char* x23088 = x23063.key;;
              bool x23073 = strcmp(x23036,"1-URGENT") == 0;;
              bool x23075 = x23073;
              if (x23073 == false) {
                bool x23074 = strcmp(x23036,"2-HIGH") == 0;;
                x23075 = x23074;
              }
              bool x23076 = x23075;
              double x23079;
              if (x23076) {
                double x23077 = x23072._0;;
                double x23078 = x23077 + 1.0;
                x23079 = x23078;
              } else {
                double x23077 = x23072._0;;
                x23079 = x23077;
              }
              bool x23080 = strcmp(x23036,"1-URGENT") != 0;;
              bool x23082 = x23080;
              if (x23080) {
                bool x23081 = strcmp(x23036,"2-HIGH") != 0;;
                x23082 = x23081;
              }
              bool x23083 = x23082;
              double x23086;
              if (x23083) {
                double x23084 = x23072._1;;
                double x23085 = x23084 + 1.0;
                x23086 = x23085;
              } else {
                double x23084 = x23072._1;;
                x23086 = x23084;
              }
              struct Anon189208763 x23087;
              x23087._0 = x23079;
              x23087._1 = x23086;
              struct Anon2025517469 x23089;
              x23089.exists = true;
              x23089.key = x23088;
              x23089.aggs = x23087;
              x23062[x23060] = x23089;
            } else {
              bool x23073 = strcmp(x23036,"1-URGENT") == 0;;
              bool x23075 = x23073;
              if (x23073 == false) {
                bool x23074 = strcmp(x23036,"2-HIGH") == 0;;
                x23075 = x23074;
              }
              bool x23076 = x23075;
              bool x23080 = strcmp(x23036,"1-URGENT") != 0;;
              bool x23082 = x23080;
              if (x23080) {
                bool x23081 = strcmp(x23036,"2-HIGH") != 0;;
                x23082 = x23081;
              }
              bool x23083 = x23082;
              double x23125;
              if (x23076) {
                x23125 = 1.0;
              } else {
                x23125 = 0.0;
              }
              double x23127;
              if (x23083) {
                x23127 = 1.0;
              } else {
                x23127 = 0.0;
              }
              struct Anon189208763 x23128;
              x23128._0 = x23125;
              x23128._1 = x23127;
              struct Anon2025517469 x23129;
              x23129.exists = true;
              x23129.key = x22991;
              x23129.aggs = x23128;
              for (;;) {
                struct Anon2025517469 x23092 = x23064;
                bool x23093 = x23092.exists;;
                bool x23138;
                if (x23093) {
                  char* x23094 = x23092.key;;
                  bool x23095 = strcmp(x23094,x22991) == 0;;
                  bool x23121;
                  if (x23095) {
                    struct Anon189208763 x23096 = x23092.aggs;;
                    long x23106 = x23061;
                    struct Anon2025517469* x23108 = x22880;
                    double x23100;
                    if (x23076) {
                      double x23098 = x23096._0;;
                      double x23099 = x23098 + 1.0;
                      x23100 = x23099;
                    } else {
                      double x23098 = x23096._0;;
                      x23100 = x23098;
                    }
                    double x23104;
                    if (x23083) {
                      double x23102 = x23096._1;;
                      double x23103 = x23102 + 1.0;
                      x23104 = x23103;
                    } else {
                      double x23102 = x23096._1;;
                      x23104 = x23102;
                    }
                    struct Anon189208763 x23105;
                    x23105._0 = x23100;
                    x23105._1 = x23104;
                    struct Anon2025517469 x23107;
                    x23107.exists = true;
                    x23107.key = x23094;
                    x23107.aggs = x23105;
                    x23108[x23106] = x23107;
                    x23121 = false;
                  } else {
                    long x23111 = x23061;
                    long x23112 = x23111 + 1L;
                    long x23113 = x23112 % x802;
                    x23061 = x23113;
                    struct Anon2025517469* x23115 = x22880;
                    struct Anon2025517469 x23116 = x23115[x23113];
                    x23064 = x23116;
                    x23121 = true;
                  }
                  x23138 = x23121;
                } else {
                  long x23123 = x23061;
                  struct Anon2025517469* x23130 = x22880;
                  x23130[x23123] = x23129;
                  long x23132 = x22881;
                  x22882[x23132] = x23123;
                  x22881 = x22881 + 1L;
                  x23138 = false;
                }
                if (!x23138) break;
              }
            }
          } else {
          }
        }
      } else {
      }
    }
    long x23153 = x22881;
    long x23155;
    for(x23155=0L; x23155 < x23153; x23155++) {
      long x23156 = x22882[x23155];
      struct Anon2025517469* x23157 = x22880;
      struct Anon2025517469 x23158 = x23157[x23156];
      if (x975) {
      } else {
        char* x23161 = x23158.key;;
        struct Anon189208763 x23163 = x23158.aggs;;
        int x23162 = strlen(x23161);
        double x23164 = x23163._0;;
        double x23165 = x23163._1;;
        printf("%.*s|%.0f|%.0f\n",x23162,x23161,x23164,x23165);
        x22893 = x22893 + 1L;
      }
    }
    long x23172 = x22893;
    printf("(%d rows)\n",x23172);
    gettimeofday(&x23176, NULL);
    timeval_subtract(&x23177, &x23176, &x23175);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x23177.tv_sec * 1000) + (x23177.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
