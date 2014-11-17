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

struct Anon1993309635 {
int PS_PARTKEY;
int PS_SUPPKEY;
double PS_AVAILQTY;
};

struct Anon1574764725Anon1268892766 {
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

struct Anon1574764725 {
bool exists;
struct Anon1993309635 key;
double aggs;
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

struct Anon1587544425 {
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

struct Anon1858713264 {
int key;
struct Anon2052879266 aggs;
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

struct Anon532638341 {
bool exists;
struct Anon1465150758 key;
struct Anon2052879266 aggs;
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

struct Anon1506628547 {
bool exists;
struct Anon1548200872 key;
struct Anon2052879266 aggs;
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

struct Anon1621811895 {
char* C_NAME;
int C_CUSTKEY;
int O_ORDERKEY;
long O_ORDERDATE;
double O_TOTALPRICE;
};

struct Anon854324566 {
bool exists;
struct Anon1621811895 key;
struct Anon2052879266 aggs;
};

struct Anon1078540535 {
char* N_NAME;
int N_NATIONKEY;
};

struct Anon1285873738 {
int key;
struct Anon1023322325 wnd;
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

struct Anon0 {
struct Anon1406772883 left;
struct Anon1574764725Anon1268892766 right;
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

struct Anon1996247276Anon811555534Anon920667905 {
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

struct Anon1996247276Anon811555534 {
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

struct Anon668992598 {
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
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

struct Anon2025517469 {
bool exists;
char* key;
struct Anon189208763 aggs;
};

struct Anon1267496251 {
bool exists;
struct Anon1978526630 key;
struct Anon2052879266 aggs;
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

struct Anon1519494783 {
struct Anon625264174 key;
struct Anon1296044246 aggs;
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

struct Anon1406772883Anon1574764725Anon1268892766 {
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

struct Anon1724963693 {
bool exists;
struct Anon668992598 key;
struct Anon2052879266 aggs;
};

struct Anon1487164486 {
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

struct Anon801061462 {
bool exists;
char* key;
struct Anon2052879266 aggs;
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

/************************ FUNCTIONS **************************/

/************************ MAIN BODY **************************/
int main(int x33299, char** x33300) {
  long x33301 = 0L;
  long x6 = DEFAULT_INPUT_SIZE;
  long x33302 = x6;
  long x33303 = 0L;
  int* x33304 = (int*)malloc(x6 * sizeof(int));
  int* x33305 = x33304;
  char** x33306 = (char**)malloc(x6 * sizeof(char*));
  char** x33307 = x33306;
  int x998 = open("../databases/sf2/part.tbl",0);
  long x999 = fsize(x998);
  char* x1000 = mmap(0, x999, PROT_READ, MAP_FILE | MAP_SHARED, x998, 0);
  for (;;) {
    long x33323 = x33301;
    bool x33324 = x33323 < x999;
    if (!x33324) break;
    int x33327 = 0;
    for (;;) {
      long x33328 = x33301;
      char x33329 = x1000[x33328];
      bool x33330 = x33329 != '|';
      bool x33335 = x33330;
      if (x33330) {
        long x33331 = x33301;
        char x33332 = x1000[x33331];
        bool x33333 = x33332 != '\n';
        x33335 = x33333;
      }
      bool x33336 = x33335;
      if (!x33336) break;
      int x33338 = x33327;
      long x33340 = x33301;
      int x33339 = x33338 * 10;
      char x33341 = x1000[x33340];
      char x33342 = x33341 - '0';
      int x33343 = x33339 + x33342;
      x33327 = x33343;
      x33301 = x33301 + 1;
    }
    x33301 = x33301 + 1;
    int x33349 = x33327;
    long x33350 = x33301;
    for (;;) {
      long x33351 = x33301;
      char x33352 = x1000[x33351];
      bool x33353 = x33352 != '|';
      bool x33358 = x33353;
      if (x33353) {
        long x33354 = x33301;
        char x33355 = x1000[x33354];
        bool x33356 = x33355 != '\n';
        x33358 = x33356;
      }
      bool x33359 = x33358;
      if (!x33359) break;
      x33301 = x33301 + 1;
    }
    x33301 = x33301 + 1;
    for (;;) {
      long x33369 = x33301;
      char x33370 = x1000[x33369];
      bool x33371 = x33370 != '|';
      bool x33376 = x33371;
      if (x33371) {
        long x33372 = x33301;
        char x33373 = x1000[x33372];
        bool x33374 = x33373 != '\n';
        x33376 = x33374;
      }
      bool x33377 = x33376;
      if (!x33377) break;
      x33301 = x33301 + 1;
    }
    x33301 = x33301 + 1;
    for (;;) {
      long x33387 = x33301;
      char x33388 = x1000[x33387];
      bool x33389 = x33388 != '|';
      bool x33394 = x33389;
      if (x33389) {
        long x33390 = x33301;
        char x33391 = x1000[x33390];
        bool x33392 = x33391 != '\n';
        x33394 = x33392;
      }
      bool x33395 = x33394;
      if (!x33395) break;
      x33301 = x33301 + 1;
    }
    x33301 = x33301 + 1;
    for (;;) {
      long x33405 = x33301;
      char x33406 = x1000[x33405];
      bool x33407 = x33406 != '|';
      bool x33412 = x33407;
      if (x33407) {
        long x33408 = x33301;
        char x33409 = x1000[x33408];
        bool x33410 = x33409 != '\n';
        x33412 = x33410;
      }
      bool x33413 = x33412;
      if (!x33413) break;
      x33301 = x33301 + 1;
    }
    x33301 = x33301 + 1;
    for (;;) {
      long x33424 = x33301;
      char x33425 = x1000[x33424];
      bool x33426 = x33425 != '|';
      bool x33431 = x33426;
      if (x33426) {
        long x33427 = x33301;
        char x33428 = x1000[x33427];
        bool x33429 = x33428 != '\n';
        x33431 = x33429;
      }
      bool x33432 = x33431;
      if (!x33432) break;
      x33301 = x33301 + 1;
    }
    x33301 = x33301 + 1;
    for (;;) {
      long x33447 = x33301;
      char x33448 = x1000[x33447];
      bool x33449 = x33448 != '|';
      bool x33454 = x33449;
      if (x33449) {
        long x33450 = x33301;
        char x33451 = x1000[x33450];
        bool x33452 = x33451 != '\n';
        x33454 = x33452;
      }
      bool x33455 = x33454;
      if (!x33455) break;
      x33301 = x33301 + 1;
    }
    x33301 = x33301 + 1;
    for (;;) {
      long x33467 = x33301;
      char x33468 = x1000[x33467];
      bool x33469 = x33468 != '.';
      bool x33474 = x33469;
      if (x33469) {
        long x33470 = x33301;
        char x33471 = x1000[x33470];
        bool x33472 = x33471 != '|';
        x33474 = x33472;
      }
      bool x33475 = x33474;
      bool x33480 = x33475;
      if (x33475) {
        long x33476 = x33301;
        char x33477 = x1000[x33476];
        bool x33478 = x33477 != '\n';
        x33480 = x33478;
      }
      bool x33481 = x33480;
      if (!x33481) break;
      x33301 = x33301 + 1;
    }
    long x33493 = x33301;
    char x33494 = x1000[x33493];
    bool x33495 = x33494 == '.';
    if (x33495) {
      x33301 = x33301 + 1;
      for (;;) {
        long x33497 = x33301;
        char x33498 = x1000[x33497];
        bool x33499 = x33498 != '|';
        bool x33504 = x33499;
        if (x33499) {
          long x33500 = x33301;
          char x33501 = x1000[x33500];
          bool x33502 = x33501 != '\n';
          x33504 = x33502;
        }
        bool x33505 = x33504;
        if (!x33505) break;
        x33301 = x33301 + 1;
      }
    } else {
    }
    x33301 = x33301 + 1;
    for (;;) {
      long x33530 = x33301;
      char x33531 = x1000[x33530];
      bool x33532 = x33531 != '|';
      bool x33537 = x33532;
      if (x33532) {
        long x33533 = x33301;
        char x33534 = x1000[x33533];
        bool x33535 = x33534 != '\n';
        x33537 = x33535;
      }
      bool x33538 = x33537;
      if (!x33538) break;
      x33301 = x33301 + 1;
    }
    x33301 = x33301 + 1;
    long x33548 = x33303;
    long x33549 = x33302;
    bool x33550 = x33548 == x33549;
    if (x33550) {
      long x33551 = x33549 * 4L;
      x33302 = x33551;
      printf("buffer.resize %d\n",x33551);
      int* x33554 = x33305;
      int* x33555 = (int*)realloc(x33554,x33551 * sizeof(int));
      x33305 = x33555;
      char** x33557 = x33307;
      char** x33558 = (char**)realloc(x33557,x33551 * sizeof(char*));
      x33307 = x33558;
    } else {
    }
    int* x33583 = x33305;
    x33583[x33548] = x33349;
    char** x33585 = x33307;
    char* x33367 = x1000+x33350;
    x33585[x33548] = x33367;
    x33303 = x33303 + 1;
  }
  long x33604 = 0L;
  long x33605 = x6;
  long x33606 = 0L;
  int* x33607 = (int*)malloc(x6 * sizeof(int));
  int* x33608 = x33607;
  char** x33609 = (char**)malloc(x6 * sizeof(char*));
  char** x33610 = x33609;
  int x1515 = open("../databases/sf2/nation.tbl",0);
  long x1516 = fsize(x1515);
  char* x1517 = mmap(0, x1516, PROT_READ, MAP_FILE | MAP_SHARED, x1515, 0);
  for (;;) {
    long x33615 = x33604;
    bool x33616 = x33615 < x1516;
    if (!x33616) break;
    int x33619 = 0;
    for (;;) {
      long x33620 = x33604;
      char x33621 = x1517[x33620];
      bool x33622 = x33621 != '|';
      bool x33627 = x33622;
      if (x33622) {
        long x33623 = x33604;
        char x33624 = x1517[x33623];
        bool x33625 = x33624 != '\n';
        x33627 = x33625;
      }
      bool x33628 = x33627;
      if (!x33628) break;
      int x33630 = x33619;
      long x33632 = x33604;
      int x33631 = x33630 * 10;
      char x33633 = x1517[x33632];
      char x33634 = x33633 - '0';
      int x33635 = x33631 + x33634;
      x33619 = x33635;
      x33604 = x33604 + 1;
    }
    x33604 = x33604 + 1;
    int x33641 = x33619;
    long x33642 = x33604;
    for (;;) {
      long x33643 = x33604;
      char x33644 = x1517[x33643];
      bool x33645 = x33644 != '|';
      bool x33650 = x33645;
      if (x33645) {
        long x33646 = x33604;
        char x33647 = x1517[x33646];
        bool x33648 = x33647 != '\n';
        x33650 = x33648;
      }
      bool x33651 = x33650;
      if (!x33651) break;
      x33604 = x33604 + 1;
    }
    x33604 = x33604 + 1;
    for (;;) {
      long x33662 = x33604;
      char x33663 = x1517[x33662];
      bool x33664 = x33663 != '|';
      bool x33669 = x33664;
      if (x33664) {
        long x33665 = x33604;
        char x33666 = x1517[x33665];
        bool x33667 = x33666 != '\n';
        x33669 = x33667;
      }
      bool x33670 = x33669;
      if (!x33670) break;
      x33604 = x33604 + 1;
    }
    x33604 = x33604 + 1;
    for (;;) {
      long x33685 = x33604;
      char x33686 = x1517[x33685];
      bool x33687 = x33686 != '|';
      bool x33692 = x33687;
      if (x33687) {
        long x33688 = x33604;
        char x33689 = x1517[x33688];
        bool x33690 = x33689 != '\n';
        x33692 = x33690;
      }
      bool x33693 = x33692;
      if (!x33693) break;
      x33604 = x33604 + 1;
    }
    x33604 = x33604 + 1;
    long x33703 = x33606;
    long x33704 = x33605;
    bool x33705 = x33703 == x33704;
    if (x33705) {
      long x33706 = x33704 * 4L;
      x33605 = x33706;
      printf("buffer.resize %d\n",x33706);
      int* x33709 = x33608;
      int* x33710 = (int*)realloc(x33709,x33706 * sizeof(int));
      x33608 = x33710;
      char** x33712 = x33610;
      char** x33713 = (char**)realloc(x33712,x33706 * sizeof(char*));
      x33610 = x33713;
    } else {
    }
    int* x33723 = x33608;
    x33723[x33703] = x33641;
    char** x33725 = x33610;
    char* x33659 = x1517+x33642;
    x33725[x33703] = x33659;
    x33606 = x33606 + 1;
  }
  long x33734 = 0L;
  long x33735 = x6;
  long x33736 = 0L;
  int* x33737 = (int*)malloc(x6 * sizeof(int));
  int* x33738 = x33737;
  char** x33739 = (char**)malloc(x6 * sizeof(char*));
  char** x33740 = x33739;
  char** x33741 = (char**)malloc(x6 * sizeof(char*));
  char** x33742 = x33741;
  int* x33743 = (int*)malloc(x6 * sizeof(int));
  int* x33744 = x33743;
  int x1750 = open("../databases/sf2/supplier.tbl",0);
  long x1751 = fsize(x1750);
  char* x1752 = mmap(0, x1751, PROT_READ, MAP_FILE | MAP_SHARED, x1750, 0);
  for (;;) {
    long x33751 = x33734;
    bool x33752 = x33751 < x1751;
    if (!x33752) break;
    int x33755 = 0;
    for (;;) {
      long x33756 = x33734;
      char x33757 = x1752[x33756];
      bool x33758 = x33757 != '|';
      bool x33763 = x33758;
      if (x33758) {
        long x33759 = x33734;
        char x33760 = x1752[x33759];
        bool x33761 = x33760 != '\n';
        x33763 = x33761;
      }
      bool x33764 = x33763;
      if (!x33764) break;
      int x33766 = x33755;
      long x33768 = x33734;
      int x33767 = x33766 * 10;
      char x33769 = x1752[x33768];
      char x33770 = x33769 - '0';
      int x33771 = x33767 + x33770;
      x33755 = x33771;
      x33734 = x33734 + 1;
    }
    x33734 = x33734 + 1;
    int x33777 = x33755;
    long x33778 = x33734;
    for (;;) {
      long x33779 = x33734;
      char x33780 = x1752[x33779];
      bool x33781 = x33780 != '|';
      bool x33786 = x33781;
      if (x33781) {
        long x33782 = x33734;
        char x33783 = x1752[x33782];
        bool x33784 = x33783 != '\n';
        x33786 = x33784;
      }
      bool x33787 = x33786;
      if (!x33787) break;
      x33734 = x33734 + 1;
    }
    x33734 = x33734 + 1;
    long x33796 = x33734;
    for (;;) {
      long x33797 = x33734;
      char x33798 = x1752[x33797];
      bool x33799 = x33798 != '|';
      bool x33804 = x33799;
      if (x33799) {
        long x33800 = x33734;
        char x33801 = x1752[x33800];
        bool x33802 = x33801 != '\n';
        x33804 = x33802;
      }
      bool x33805 = x33804;
      if (!x33805) break;
      x33734 = x33734 + 1;
    }
    x33734 = x33734 + 1;
    int x33815 = 0;
    for (;;) {
      long x33816 = x33734;
      char x33817 = x1752[x33816];
      bool x33818 = x33817 != '|';
      bool x33823 = x33818;
      if (x33818) {
        long x33819 = x33734;
        char x33820 = x1752[x33819];
        bool x33821 = x33820 != '\n';
        x33823 = x33821;
      }
      bool x33824 = x33823;
      if (!x33824) break;
      int x33826 = x33815;
      long x33828 = x33734;
      int x33827 = x33826 * 10;
      char x33829 = x1752[x33828];
      char x33830 = x33829 - '0';
      int x33831 = x33827 + x33830;
      x33815 = x33831;
      x33734 = x33734 + 1;
    }
    x33734 = x33734 + 1;
    int x33837 = x33815;
    for (;;) {
      long x33839 = x33734;
      char x33840 = x1752[x33839];
      bool x33841 = x33840 != '|';
      bool x33846 = x33841;
      if (x33841) {
        long x33842 = x33734;
        char x33843 = x1752[x33842];
        bool x33844 = x33843 != '\n';
        x33846 = x33844;
      }
      bool x33847 = x33846;
      if (!x33847) break;
      x33734 = x33734 + 1;
    }
    x33734 = x33734 + 1;
    for (;;) {
      long x33859 = x33734;
      char x33860 = x1752[x33859];
      bool x33861 = x33860 != '.';
      bool x33866 = x33861;
      if (x33861) {
        long x33862 = x33734;
        char x33863 = x1752[x33862];
        bool x33864 = x33863 != '|';
        x33866 = x33864;
      }
      bool x33867 = x33866;
      bool x33872 = x33867;
      if (x33867) {
        long x33868 = x33734;
        char x33869 = x1752[x33868];
        bool x33870 = x33869 != '\n';
        x33872 = x33870;
      }
      bool x33873 = x33872;
      if (!x33873) break;
      x33734 = x33734 + 1;
    }
    long x33885 = x33734;
    char x33886 = x1752[x33885];
    bool x33887 = x33886 == '.';
    if (x33887) {
      x33734 = x33734 + 1;
      for (;;) {
        long x33889 = x33734;
        char x33890 = x1752[x33889];
        bool x33891 = x33890 != '|';
        bool x33896 = x33891;
        if (x33891) {
          long x33892 = x33734;
          char x33893 = x1752[x33892];
          bool x33894 = x33893 != '\n';
          x33896 = x33894;
        }
        bool x33897 = x33896;
        if (!x33897) break;
        x33734 = x33734 + 1;
      }
    } else {
    }
    x33734 = x33734 + 1;
    for (;;) {
      long x33922 = x33734;
      char x33923 = x1752[x33922];
      bool x33924 = x33923 != '|';
      bool x33929 = x33924;
      if (x33924) {
        long x33925 = x33734;
        char x33926 = x1752[x33925];
        bool x33927 = x33926 != '\n';
        x33929 = x33927;
      }
      bool x33930 = x33929;
      if (!x33930) break;
      x33734 = x33734 + 1;
    }
    x33734 = x33734 + 1;
    long x33940 = x33736;
    long x33941 = x33735;
    bool x33942 = x33940 == x33941;
    if (x33942) {
      long x33943 = x33941 * 4L;
      x33735 = x33943;
      printf("buffer.resize %d\n",x33943);
      int* x33946 = x33738;
      int* x33947 = (int*)realloc(x33946,x33943 * sizeof(int));
      x33738 = x33947;
      char** x33949 = x33740;
      char** x33950 = (char**)realloc(x33949,x33943 * sizeof(char*));
      x33740 = x33950;
      char** x33952 = x33742;
      char** x33953 = (char**)realloc(x33952,x33943 * sizeof(char*));
      x33742 = x33953;
      int* x33955 = x33744;
      int* x33956 = (int*)realloc(x33955,x33943 * sizeof(int));
      x33744 = x33956;
    } else {
    }
    int* x33969 = x33738;
    x33969[x33940] = x33777;
    char** x33971 = x33740;
    char* x33795 = x1752+x33778;
    x33971[x33940] = x33795;
    char** x33973 = x33742;
    char* x33813 = x1752+x33796;
    x33973[x33940] = x33813;
    int* x33975 = x33744;
    x33975[x33940] = x33837;
    x33736 = x33736 + 1;
  }
  long x33986 = 0L;
  long x33987 = x6;
  long x33988 = 0L;
  int* x33989 = (int*)malloc(x6 * sizeof(int));
  int* x33990 = x33989;
  int* x33991 = (int*)malloc(x6 * sizeof(int));
  int* x33992 = x33991;
  int* x33993 = (int*)malloc(x6 * sizeof(int));
  int* x33994 = x33993;
  int x1304 = open("../databases/sf2/partsupp.tbl",0);
  long x1305 = fsize(x1304);
  char* x1306 = mmap(0, x1305, PROT_READ, MAP_FILE | MAP_SHARED, x1304, 0);
  for (;;) {
    long x33999 = x33986;
    bool x34000 = x33999 < x1305;
    if (!x34000) break;
    int x34003 = 0;
    for (;;) {
      long x34004 = x33986;
      char x34005 = x1306[x34004];
      bool x34006 = x34005 != '|';
      bool x34011 = x34006;
      if (x34006) {
        long x34007 = x33986;
        char x34008 = x1306[x34007];
        bool x34009 = x34008 != '\n';
        x34011 = x34009;
      }
      bool x34012 = x34011;
      if (!x34012) break;
      int x34014 = x34003;
      long x34016 = x33986;
      int x34015 = x34014 * 10;
      char x34017 = x1306[x34016];
      char x34018 = x34017 - '0';
      int x34019 = x34015 + x34018;
      x34003 = x34019;
      x33986 = x33986 + 1;
    }
    x33986 = x33986 + 1;
    int x34025 = x34003;
    int x34027 = 0;
    for (;;) {
      long x34028 = x33986;
      char x34029 = x1306[x34028];
      bool x34030 = x34029 != '|';
      bool x34035 = x34030;
      if (x34030) {
        long x34031 = x33986;
        char x34032 = x1306[x34031];
        bool x34033 = x34032 != '\n';
        x34035 = x34033;
      }
      bool x34036 = x34035;
      if (!x34036) break;
      int x34038 = x34027;
      long x34040 = x33986;
      int x34039 = x34038 * 10;
      char x34041 = x1306[x34040];
      char x34042 = x34041 - '0';
      int x34043 = x34039 + x34042;
      x34027 = x34043;
      x33986 = x33986 + 1;
    }
    x33986 = x33986 + 1;
    int x34049 = x34027;
    int x34051 = 0;
    for (;;) {
      long x34052 = x33986;
      char x34053 = x1306[x34052];
      bool x34054 = x34053 != '|';
      bool x34059 = x34054;
      if (x34054) {
        long x34055 = x33986;
        char x34056 = x1306[x34055];
        bool x34057 = x34056 != '\n';
        x34059 = x34057;
      }
      bool x34060 = x34059;
      if (!x34060) break;
      int x34062 = x34051;
      long x34064 = x33986;
      int x34063 = x34062 * 10;
      char x34065 = x1306[x34064];
      char x34066 = x34065 - '0';
      int x34067 = x34063 + x34066;
      x34051 = x34067;
      x33986 = x33986 + 1;
    }
    x33986 = x33986 + 1;
    int x34073 = x34051;
    for (;;) {
      long x34077 = x33986;
      char x34078 = x1306[x34077];
      bool x34079 = x34078 != '.';
      bool x34084 = x34079;
      if (x34079) {
        long x34080 = x33986;
        char x34081 = x1306[x34080];
        bool x34082 = x34081 != '|';
        x34084 = x34082;
      }
      bool x34085 = x34084;
      bool x34090 = x34085;
      if (x34085) {
        long x34086 = x33986;
        char x34087 = x1306[x34086];
        bool x34088 = x34087 != '\n';
        x34090 = x34088;
      }
      bool x34091 = x34090;
      if (!x34091) break;
      x33986 = x33986 + 1;
    }
    long x34103 = x33986;
    char x34104 = x1306[x34103];
    bool x34105 = x34104 == '.';
    if (x34105) {
      x33986 = x33986 + 1;
      for (;;) {
        long x34107 = x33986;
        char x34108 = x1306[x34107];
        bool x34109 = x34108 != '|';
        bool x34114 = x34109;
        if (x34109) {
          long x34110 = x33986;
          char x34111 = x1306[x34110];
          bool x34112 = x34111 != '\n';
          x34114 = x34112;
        }
        bool x34115 = x34114;
        if (!x34115) break;
        x33986 = x33986 + 1;
      }
    } else {
    }
    x33986 = x33986 + 1;
    for (;;) {
      long x34140 = x33986;
      char x34141 = x1306[x34140];
      bool x34142 = x34141 != '|';
      bool x34147 = x34142;
      if (x34142) {
        long x34143 = x33986;
        char x34144 = x1306[x34143];
        bool x34145 = x34144 != '\n';
        x34147 = x34145;
      }
      bool x34148 = x34147;
      if (!x34148) break;
      x33986 = x33986 + 1;
    }
    x33986 = x33986 + 1;
    long x34158 = x33988;
    long x34159 = x33987;
    bool x34160 = x34158 == x34159;
    if (x34160) {
      long x34161 = x34159 * 4L;
      x33987 = x34161;
      printf("buffer.resize %d\n",x34161);
      int* x34164 = x33990;
      int* x34165 = (int*)realloc(x34164,x34161 * sizeof(int));
      x33990 = x34165;
      int* x34167 = x33992;
      int* x34168 = (int*)realloc(x34167,x34161 * sizeof(int));
      x33992 = x34168;
      int* x34170 = x33994;
      int* x34171 = (int*)realloc(x34170,x34161 * sizeof(int));
      x33994 = x34171;
    } else {
    }
    int* x34181 = x33990;
    x34181[x34158] = x34025;
    int* x34183 = x33992;
    x34183[x34158] = x34049;
    int* x34185 = x33994;
    x34185[x34158] = x34073;
    x33988 = x33988 + 1;
  }
  long x34194 = 0L;
  long x34195 = x6;
  long x34196 = 0L;
  int* x34199 = (int*)malloc(x6 * sizeof(int));
  int* x34200 = x34199;
  int* x34201 = (int*)malloc(x6 * sizeof(int));
  int* x34202 = x34201;
  double* x34205 = (double*)malloc(x6 * sizeof(double));
  double* x34206 = x34205;
  long* x34217 = (long*)malloc(x6 * sizeof(long));
  long* x34218 = x34217;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  long x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    long x34229 = x34194;
    bool x34230 = x34229 < x3;
    if (!x34230) break;
    for (;;) {
      long x34234 = x34194;
      char x34235 = x4[x34234];
      bool x34236 = x34235 != '|';
      bool x34241 = x34236;
      if (x34236) {
        long x34237 = x34194;
        char x34238 = x4[x34237];
        bool x34239 = x34238 != '\n';
        x34241 = x34239;
      }
      bool x34242 = x34241;
      if (!x34242) break;
      x34194 = x34194 + 1;
    }
    x34194 = x34194 + 1;
    int x34257 = 0;
    for (;;) {
      long x34258 = x34194;
      char x34259 = x4[x34258];
      bool x34260 = x34259 != '|';
      bool x34265 = x34260;
      if (x34260) {
        long x34261 = x34194;
        char x34262 = x4[x34261];
        bool x34263 = x34262 != '\n';
        x34265 = x34263;
      }
      bool x34266 = x34265;
      if (!x34266) break;
      int x34268 = x34257;
      long x34270 = x34194;
      int x34269 = x34268 * 10;
      char x34271 = x4[x34270];
      char x34272 = x34271 - '0';
      int x34273 = x34269 + x34272;
      x34257 = x34273;
      x34194 = x34194 + 1;
    }
    x34194 = x34194 + 1;
    int x34279 = x34257;
    int x34281 = 0;
    for (;;) {
      long x34282 = x34194;
      char x34283 = x4[x34282];
      bool x34284 = x34283 != '|';
      bool x34289 = x34284;
      if (x34284) {
        long x34285 = x34194;
        char x34286 = x4[x34285];
        bool x34287 = x34286 != '\n';
        x34289 = x34287;
      }
      bool x34290 = x34289;
      if (!x34290) break;
      int x34292 = x34281;
      long x34294 = x34194;
      int x34293 = x34292 * 10;
      char x34295 = x4[x34294];
      char x34296 = x34295 - '0';
      int x34297 = x34293 + x34296;
      x34281 = x34297;
      x34194 = x34194 + 1;
    }
    x34194 = x34194 + 1;
    int x34303 = x34281;
    for (;;) {
      long x34306 = x34194;
      char x34307 = x4[x34306];
      bool x34308 = x34307 != '|';
      bool x34313 = x34308;
      if (x34308) {
        long x34309 = x34194;
        char x34310 = x4[x34309];
        bool x34311 = x34310 != '\n';
        x34313 = x34311;
      }
      bool x34314 = x34313;
      if (!x34314) break;
      x34194 = x34194 + 1;
    }
    x34194 = x34194 + 1;
    int x34329 = 0;
    int x34330 = 1;
    for (;;) {
      long x34331 = x34194;
      char x34332 = x4[x34331];
      bool x34333 = x34332 != '.';
      bool x34338 = x34333;
      if (x34333) {
        long x34334 = x34194;
        char x34335 = x4[x34334];
        bool x34336 = x34335 != '|';
        x34338 = x34336;
      }
      bool x34339 = x34338;
      bool x34344 = x34339;
      if (x34339) {
        long x34340 = x34194;
        char x34341 = x4[x34340];
        bool x34342 = x34341 != '\n';
        x34344 = x34342;
      }
      bool x34345 = x34344;
      if (!x34345) break;
      int x34347 = x34329;
      long x34349 = x34194;
      int x34348 = x34347 * 10;
      char x34350 = x4[x34349];
      char x34351 = x34350 - '0';
      int x34352 = x34348 + x34351;
      x34329 = x34352;
      x34194 = x34194 + 1;
    }
    long x34357 = x34194;
    char x34358 = x4[x34357];
    bool x34359 = x34358 == '.';
    if (x34359) {
      x34194 = x34194 + 1;
      for (;;) {
        long x34361 = x34194;
        char x34362 = x4[x34361];
        bool x34363 = x34362 != '|';
        bool x34368 = x34363;
        if (x34363) {
          long x34364 = x34194;
          char x34365 = x4[x34364];
          bool x34366 = x34365 != '\n';
          x34368 = x34366;
        }
        bool x34369 = x34368;
        if (!x34369) break;
        int x34371 = x34329;
        long x34373 = x34194;
        int x34372 = x34371 * 10;
        char x34374 = x4[x34373];
        char x34375 = x34374 - '0';
        int x34376 = x34372 + x34375;
        x34329 = x34376;
        int x34378 = x34330;
        int x34379 = x34378 * 10;
        x34330 = x34379;
        x34194 = x34194 + 1;
      }
    } else {
    }
    x34194 = x34194 + 1;
    int x34388 = x34329;
    int x34390 = x34330;
    for (;;) {
      long x34396 = x34194;
      char x34397 = x4[x34396];
      bool x34398 = x34397 != '.';
      bool x34403 = x34398;
      if (x34398) {
        long x34399 = x34194;
        char x34400 = x4[x34399];
        bool x34401 = x34400 != '|';
        x34403 = x34401;
      }
      bool x34404 = x34403;
      bool x34409 = x34404;
      if (x34404) {
        long x34405 = x34194;
        char x34406 = x4[x34405];
        bool x34407 = x34406 != '\n';
        x34409 = x34407;
      }
      bool x34410 = x34409;
      if (!x34410) break;
      x34194 = x34194 + 1;
    }
    long x34422 = x34194;
    char x34423 = x4[x34422];
    bool x34424 = x34423 == '.';
    if (x34424) {
      x34194 = x34194 + 1;
      for (;;) {
        long x34426 = x34194;
        char x34427 = x4[x34426];
        bool x34428 = x34427 != '|';
        bool x34433 = x34428;
        if (x34428) {
          long x34429 = x34194;
          char x34430 = x4[x34429];
          bool x34431 = x34430 != '\n';
          x34433 = x34431;
        }
        bool x34434 = x34433;
        if (!x34434) break;
        x34194 = x34194 + 1;
      }
    } else {
    }
    x34194 = x34194 + 1;
    for (;;) {
      long x34461 = x34194;
      char x34462 = x4[x34461];
      bool x34463 = x34462 != '.';
      bool x34468 = x34463;
      if (x34463) {
        long x34464 = x34194;
        char x34465 = x4[x34464];
        bool x34466 = x34465 != '|';
        x34468 = x34466;
      }
      bool x34469 = x34468;
      bool x34474 = x34469;
      if (x34469) {
        long x34470 = x34194;
        char x34471 = x4[x34470];
        bool x34472 = x34471 != '\n';
        x34474 = x34472;
      }
      bool x34475 = x34474;
      if (!x34475) break;
      x34194 = x34194 + 1;
    }
    long x34487 = x34194;
    char x34488 = x4[x34487];
    bool x34489 = x34488 == '.';
    if (x34489) {
      x34194 = x34194 + 1;
      for (;;) {
        long x34491 = x34194;
        char x34492 = x4[x34491];
        bool x34493 = x34492 != '|';
        bool x34498 = x34493;
        if (x34493) {
          long x34494 = x34194;
          char x34495 = x4[x34494];
          bool x34496 = x34495 != '\n';
          x34498 = x34496;
        }
        bool x34499 = x34498;
        if (!x34499) break;
        x34194 = x34194 + 1;
      }
    } else {
    }
    x34194 = x34194 + 1;
    for (;;) {
      long x34526 = x34194;
      char x34527 = x4[x34526];
      bool x34528 = x34527 != '.';
      bool x34533 = x34528;
      if (x34528) {
        long x34529 = x34194;
        char x34530 = x4[x34529];
        bool x34531 = x34530 != '|';
        x34533 = x34531;
      }
      bool x34534 = x34533;
      bool x34539 = x34534;
      if (x34534) {
        long x34535 = x34194;
        char x34536 = x4[x34535];
        bool x34537 = x34536 != '\n';
        x34539 = x34537;
      }
      bool x34540 = x34539;
      if (!x34540) break;
      x34194 = x34194 + 1;
    }
    long x34552 = x34194;
    char x34553 = x4[x34552];
    bool x34554 = x34553 == '.';
    if (x34554) {
      x34194 = x34194 + 1;
      for (;;) {
        long x34556 = x34194;
        char x34557 = x4[x34556];
        bool x34558 = x34557 != '|';
        bool x34563 = x34558;
        if (x34558) {
          long x34559 = x34194;
          char x34560 = x4[x34559];
          bool x34561 = x34560 != '\n';
          x34563 = x34561;
        }
        bool x34564 = x34563;
        if (!x34564) break;
        x34194 = x34194 + 1;
      }
    } else {
    }
    x34194 = x34194 + 1;
    x34194 = x34194 + 2;
    x34194 = x34194 + 2;
    int x34595 = 0;
    for (;;) {
      long x34596 = x34194;
      char x34597 = x4[x34596];
      bool x34598 = x34597 != '-';
      bool x34603 = x34598;
      if (x34598) {
        long x34599 = x34194;
        char x34600 = x4[x34599];
        bool x34601 = x34600 != '\n';
        x34603 = x34601;
      }
      bool x34604 = x34603;
      if (!x34604) break;
      int x34606 = x34595;
      long x34608 = x34194;
      int x34607 = x34606 * 10;
      char x34609 = x4[x34608];
      char x34610 = x34609 - '0';
      int x34611 = x34607 + x34610;
      x34595 = x34611;
      x34194 = x34194 + 1;
    }
    x34194 = x34194 + 1;
    int x34617 = x34595;
    int x34619 = 0;
    for (;;) {
      long x34620 = x34194;
      char x34621 = x4[x34620];
      bool x34622 = x34621 != '-';
      bool x34627 = x34622;
      if (x34622) {
        long x34623 = x34194;
        char x34624 = x4[x34623];
        bool x34625 = x34624 != '\n';
        x34627 = x34625;
      }
      bool x34628 = x34627;
      if (!x34628) break;
      int x34630 = x34619;
      long x34632 = x34194;
      int x34631 = x34630 * 10;
      char x34633 = x4[x34632];
      char x34634 = x34633 - '0';
      int x34635 = x34631 + x34634;
      x34619 = x34635;
      x34194 = x34194 + 1;
    }
    x34194 = x34194 + 1;
    int x34641 = x34619;
    int x34643 = 0;
    for (;;) {
      long x34644 = x34194;
      char x34645 = x4[x34644];
      bool x34646 = x34645 != '|';
      bool x34651 = x34646;
      if (x34646) {
        long x34647 = x34194;
        char x34648 = x4[x34647];
        bool x34649 = x34648 != '\n';
        x34651 = x34649;
      }
      bool x34652 = x34651;
      if (!x34652) break;
      int x34654 = x34643;
      long x34656 = x34194;
      int x34655 = x34654 * 10;
      char x34657 = x4[x34656];
      char x34658 = x34657 - '0';
      int x34659 = x34655 + x34658;
      x34643 = x34659;
      x34194 = x34194 + 1;
    }
    x34194 = x34194 + 1;
    int x34665 = x34643;
    for (;;) {
      long x34672 = x34194;
      char x34673 = x4[x34672];
      bool x34674 = x34673 != '-';
      bool x34679 = x34674;
      if (x34674) {
        long x34675 = x34194;
        char x34676 = x4[x34675];
        bool x34677 = x34676 != '\n';
        x34679 = x34677;
      }
      bool x34680 = x34679;
      if (!x34680) break;
      x34194 = x34194 + 1;
    }
    x34194 = x34194 + 1;
    for (;;) {
      long x34696 = x34194;
      char x34697 = x4[x34696];
      bool x34698 = x34697 != '-';
      bool x34703 = x34698;
      if (x34698) {
        long x34699 = x34194;
        char x34700 = x4[x34699];
        bool x34701 = x34700 != '\n';
        x34703 = x34701;
      }
      bool x34704 = x34703;
      if (!x34704) break;
      x34194 = x34194 + 1;
    }
    x34194 = x34194 + 1;
    for (;;) {
      long x34720 = x34194;
      char x34721 = x4[x34720];
      bool x34722 = x34721 != '|';
      bool x34727 = x34722;
      if (x34722) {
        long x34723 = x34194;
        char x34724 = x4[x34723];
        bool x34725 = x34724 != '\n';
        x34727 = x34725;
      }
      bool x34728 = x34727;
      if (!x34728) break;
      x34194 = x34194 + 1;
    }
    x34194 = x34194 + 1;
    for (;;) {
      long x34748 = x34194;
      char x34749 = x4[x34748];
      bool x34750 = x34749 != '-';
      bool x34755 = x34750;
      if (x34750) {
        long x34751 = x34194;
        char x34752 = x4[x34751];
        bool x34753 = x34752 != '\n';
        x34755 = x34753;
      }
      bool x34756 = x34755;
      if (!x34756) break;
      x34194 = x34194 + 1;
    }
    x34194 = x34194 + 1;
    for (;;) {
      long x34772 = x34194;
      char x34773 = x4[x34772];
      bool x34774 = x34773 != '-';
      bool x34779 = x34774;
      if (x34774) {
        long x34775 = x34194;
        char x34776 = x4[x34775];
        bool x34777 = x34776 != '\n';
        x34779 = x34777;
      }
      bool x34780 = x34779;
      if (!x34780) break;
      x34194 = x34194 + 1;
    }
    x34194 = x34194 + 1;
    for (;;) {
      long x34796 = x34194;
      char x34797 = x4[x34796];
      bool x34798 = x34797 != '|';
      bool x34803 = x34798;
      if (x34798) {
        long x34799 = x34194;
        char x34800 = x4[x34799];
        bool x34801 = x34800 != '\n';
        x34803 = x34801;
      }
      bool x34804 = x34803;
      if (!x34804) break;
      x34194 = x34194 + 1;
    }
    x34194 = x34194 + 1;
    for (;;) {
      long x34823 = x34194;
      char x34824 = x4[x34823];
      bool x34825 = x34824 != '|';
      bool x34830 = x34825;
      if (x34825) {
        long x34826 = x34194;
        char x34827 = x4[x34826];
        bool x34828 = x34827 != '\n';
        x34830 = x34828;
      }
      bool x34831 = x34830;
      if (!x34831) break;
      x34194 = x34194 + 1;
    }
    x34194 = x34194 + 1;
    for (;;) {
      long x34841 = x34194;
      char x34842 = x4[x34841];
      bool x34843 = x34842 != '|';
      bool x34848 = x34843;
      if (x34843) {
        long x34844 = x34194;
        char x34845 = x4[x34844];
        bool x34846 = x34845 != '\n';
        x34848 = x34846;
      }
      bool x34849 = x34848;
      if (!x34849) break;
      x34194 = x34194 + 1;
    }
    x34194 = x34194 + 1;
    for (;;) {
      long x34859 = x34194;
      char x34860 = x4[x34859];
      bool x34861 = x34860 != '|';
      bool x34866 = x34861;
      if (x34861) {
        long x34862 = x34194;
        char x34863 = x4[x34862];
        bool x34864 = x34863 != '\n';
        x34866 = x34864;
      }
      bool x34867 = x34866;
      if (!x34867) break;
      x34194 = x34194 + 1;
    }
    x34194 = x34194 + 1;
    long x34877 = x34196;
    long x34878 = x34195;
    bool x34879 = x34877 == x34878;
    if (x34879) {
      long x34880 = x34878 * 4L;
      x34195 = x34880;
      printf("buffer.resize %d\n",x34880);
      int* x34886 = x34200;
      int* x34887 = (int*)realloc(x34886,x34880 * sizeof(int));
      x34200 = x34887;
      int* x34889 = x34202;
      int* x34890 = (int*)realloc(x34889,x34880 * sizeof(int));
      x34202 = x34890;
      double* x34895 = x34206;
      double* x34896 = (double*)realloc(x34895,x34880 * sizeof(double));
      x34206 = x34896;
      long* x34913 = x34218;
      long* x34914 = (long*)realloc(x34913,x34880 * sizeof(long));
      x34218 = x34914;
    } else {
    }
    int* x34935 = x34200;
    x34935[x34877] = x34279;
    int* x34937 = x34202;
    x34937[x34877] = x34303;
    double* x34941 = x34206;
    double x34389 = (double)x34388;
    double x34391 = (double)x34390;
    double x34392 = x34389 / x34391;
    x34941[x34877] = x34392;
    long* x34953 = x34218;
    long x34666 = x34617 * 10000L;
    long x34667 = x34641 * 100L;
    long x34668 = x34666 + x34667;
    long x34669 = x34668 + x34665;
    x34953[x34877] = x34669;
    x34196 = x34196 + 1;
  }
  long x2011 = DEFAULT_JOIN_HASH_SIZE;
  long x787 = DEFAULT_AGG_HASH_SIZE ;
  long x2034 = x2011 - 1L;
  long x802 = x787 - 1L;
  bool x975 = true == false;
  int x34968;
  for(x34968=0; x34968 < 5; x34968++) {
    bool x34969 = false;
    long x34970 = 0L;
    bool x34972 = false;
    long x34973 = 0L;
    int* x34975 = (int*)malloc(x2011 * sizeof(int));
    int* x34976 = x34975;
    long x34993 = 0L;
    long* x34994 = (long*)malloc(x2011 * sizeof(long));
    long* x34995 = (long*)malloc(x2011 * sizeof(long));
    long x34996;
    for(x34996=0L; x34996 < x2011; x34996++) {
      x34994[x34996] = -1L;
    }
    bool x35001 = false;
    long x35002 = 0L;
    int* x35023 = (int*)malloc(x2011 * sizeof(int));
    int* x35024 = x35023;
    int* x35025 = (int*)malloc(x2011 * sizeof(int));
    int* x35026 = x35025;
    int* x35027 = (int*)malloc(x2011 * sizeof(int));
    int* x35028 = x35027;
    long x35033 = 0L;
    long* x35034 = (long*)malloc(x2011 * sizeof(long));
    long* x35035 = (long*)malloc(x2011 * sizeof(long));
    long x35036;
    for(x35036=0L; x35036 < x2011; x35036++) {
      x35034[x35036] = -1L;
    }
    struct Anon1574764725* x35042 = (struct Anon1574764725*)malloc(x787 * sizeof(struct Anon1574764725));
    struct Anon1574764725* x35043 = x35042;
    long x35044 = 0L;
    long* x35045 = (long*)malloc(x787 * sizeof(long));
    long x35046;
    for(x35046=0L; x35046 < x787; x35046++) {
      struct Anon1574764725* x35047 = x35043;
      struct Anon1574764725 x35048 = x35047[x35046];
      struct Anon1993309635 x35049 = x35048.key;;
      double x35050 = x35048.aggs;;
      struct Anon1574764725 x35051;
      x35051.exists = false;
      x35051.key = x35049;
      x35051.aggs = x35050;
      x35047[x35046] = x35051;
    }
    bool x35056 = false;
    long x35057 = 0L;
    int* x35063 = (int*)malloc(x2011 * sizeof(int));
    int* x35064 = x35063;
    long x35069 = 0L;
    long* x35070 = (long*)malloc(x2011 * sizeof(long));
    long* x35071 = (long*)malloc(x2011 * sizeof(long));
    long x35072;
    for(x35072=0L; x35072 < x2011; x35072++) {
      x35070[x35072] = -1L;
    }
    bool x35077 = false;
    long x35078 = 0L;
    int* x35081 = (int*)malloc(x2011 * sizeof(int));
    int* x35082 = x35081;
    long x35089 = 0L;
    long* x35090 = (long*)malloc(x2011 * sizeof(long));
    long* x35091 = (long*)malloc(x2011 * sizeof(long));
    long x35092;
    for(x35092=0L; x35092 < x2011; x35092++) {
      x35090[x35092] = -1L;
    }
    long x35098 = 0L;
    struct timeval x35604, x35605, x35606;
    gettimeofday(&x35604, NULL);
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x35100 = x35077;
      bool x35101 = !x35100;
      bool x35106 = x35101;
      if (x35101) {
        long x35102 = x35078;
        long x35103 = x33606;
        bool x35104 = x35102 < x35103;
        x35106 = x35104;
      }
      bool x35107 = x35106;
      if (!x35107) break;
      long x35109 = x35078;
      int* x35110 = x33608;
      int x35111 = x35110[x35109];
      char** x35112 = x33610;
      char* x35113 = x35112[x35109];
      x35078 = x35078 + 1;
      bool x35120 = strcmp(x35113,"JORDAN") == 0;;
      if (x35120) {
        long x35121 = x35089;
        int* x35122 = x35082;
        x35122[x35121] = x35111;
        x35089 = x35089 + 1L;
        long x35131 = x35111 & x2034;
        long x35132 = x35090[x35131];
        x35090[x35131] = x35121;
        x35091[x35121] = x35132;
      } else {
      }
    }
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x35140 = x34969;
      bool x35141 = !x35140;
      bool x35146 = x35141;
      if (x35141) {
        long x35142 = x34970;
        long x35143 = x33303;
        bool x35144 = x35142 < x35143;
        x35146 = x35144;
      }
      bool x35147 = x35146;
      if (!x35147) break;
      long x35149 = x34970;
      int* x35150 = x33305;
      int x35151 = x35150[x35149];
      char** x35152 = x33307;
      char* x35153 = x35152[x35149];
      x34970 = x34970 + 1;
      bool x35170 = strncmp(x35153,"azure", strlen("azure")) == 0;;
      if (x35170) {
        long x35171 = x34993;
        int* x35172 = x34976;
        x35172[x35171] = x35151;
        x34993 = x34993 + 1L;
        long x35191 = x35151 & x2034;
        long x35192 = x34994[x35191];
        x34994[x35191] = x35171;
        x34995[x35171] = x35192;
      } else {
      }
    }
    printf("%s\n","begin scan PARTSUPP");
    for (;;) {
      bool x35200 = x34972;
      bool x35201 = !x35200;
      bool x35206 = x35201;
      if (x35201) {
        long x35202 = x34973;
        long x35203 = x33988;
        bool x35204 = x35202 < x35203;
        x35206 = x35204;
      }
      bool x35207 = x35206;
      if (!x35207) break;
      long x35209 = x34973;
      int* x35210 = x33990;
      int x35211 = x35210[x35209];
      int* x35212 = x33992;
      int x35213 = x35212[x35209];
      int* x35214 = x33994;
      int x35215 = x35214[x35209];
      x34973 = x34973 + 1;
      long x35222 = x35211 & x2034;
      long x35223 = x34994[x35222];
      long x35224 = x35223;
      for (;;) {
        long x35225 = x35224;
        bool x35226 = x35225 != -1;
        if (!x35226) break;
        long x35228 = x35224;
        int* x35229 = x34976;
        int x35230 = x35229[x35228];
        long x35248 = x34995[x35228];
        x35224 = x35248;
        bool x35250 = x35230 == x35211;
        if (x35250) {
          long x35254 = x35033;
          int* x35273 = x35024;
          x35273[x35254] = x35211;
          int* x35275 = x35026;
          x35275[x35254] = x35213;
          int* x35277 = x35028;
          x35277[x35254] = x35215;
          x35033 = x35033 + 1L;
          long x35284 = x35034[x35222];
          x35034[x35222] = x35254;
          x35035[x35254] = x35284;
        } else {
        }
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x35294 = x35001;
      bool x35295 = !x35294;
      bool x35300 = x35295;
      if (x35295) {
        long x35296 = x35002;
        long x35297 = x34196;
        bool x35298 = x35296 < x35297;
        x35300 = x35298;
      }
      bool x35301 = x35300;
      if (!x35301) break;
      long x35303 = x35002;
      int* x35306 = x34200;
      int x35307 = x35306[x35303];
      int* x35308 = x34202;
      int x35309 = x35308[x35303];
      double* x35312 = x34206;
      double x35313 = x35312[x35303];
      long* x35324 = x34218;
      long x35325 = x35324[x35303];
      x35002 = x35002 + 1;
      bool x35338 = x35325 >= 19960101L;
      bool x35340 = x35338;
      if (x35338) {
        bool x35339 = x35325 < 19970101L;
        x35340 = x35339;
      }
      bool x35341 = x35340;
      if (x35341) {
        long x35342 = x35307 & x2034;
        long x35343 = x35034[x35342];
        long x35344 = x35343;
        for (;;) {
          long x35345 = x35344;
          bool x35346 = x35345 != -1;
          if (!x35346) break;
          long x35348 = x35344;
          int* x35367 = x35024;
          int x35368 = x35367[x35348];
          int* x35369 = x35026;
          int x35370 = x35369[x35348];
          int* x35371 = x35028;
          int x35372 = x35371[x35348];
          long x35378 = x35035[x35348];
          x35344 = x35378;
          bool x35380 = x35368 == x35307;
          bool x35382 = x35380;
          if (x35380) {
            bool x35381 = x35370 == x35309;
            x35382 = x35381;
          }
          bool x35383 = x35382;
          if (x35383) {
            long x35388 = 31857L + x35368;
            long x35389 = x35388 * 41L;
            long x35390 = x35389 + x35370;
            long x35391 = x35390 & x802;
            long x35392 = x35391;
            struct Anon1574764725* x35393 = x35043;
            struct Anon1574764725 x35394 = x35393[x35391];
            struct Anon1574764725 x35395 = x35394;
            bool x35396 = x35394.exists;;
            bool x35410 = x35396;
            if (x35396) {
              struct Anon1574764725 x35397 = x35395;
              struct Anon1993309635 x35398 = x35397.key;;
              int x35399 = x35398.PS_PARTKEY;;
              bool x35400 = x35399 == x35368;
              bool x35405 = x35400;
              if (x35400) {
                int x35401 = x35398.PS_SUPPKEY;;
                bool x35402 = x35401 == x35370;
                x35405 = x35402;
              }
              bool x35406 = x35405;
              bool x35407 = x35406;
              if (x35406) {
                double x35403 = x35398.PS_AVAILQTY;;
                bool x35404 = x35403 == x35372;
                x35407 = x35404;
              }
              bool x35408 = x35407;
              x35410 = x35408;
            }
            bool x35411 = x35410;
            if (x35411) {
              double x35412 = x35394.aggs;;
              struct Anon1993309635 x35414 = x35394.key;;
              double x35413 = x35412 + x35313;
              struct Anon1574764725 x35415;
              x35415.exists = true;
              x35415.key = x35414;
              x35415.aggs = x35413;
              x35393[x35391] = x35415;
            } else {
              struct Anon1993309635 x35387;
              x35387.PS_PARTKEY = x35368;
              x35387.PS_SUPPKEY = x35370;
              x35387.PS_AVAILQTY = x35372;
              struct Anon1574764725 x35451;
              x35451.exists = true;
              x35451.key = x35387;
              x35451.aggs = x35313;
              for (;;) {
                struct Anon1574764725 x35418 = x35395;
                bool x35419 = x35418.exists;;
                bool x35460;
                if (x35419) {
                  struct Anon1993309635 x35420 = x35418.key;;
                  int x35421 = x35420.PS_PARTKEY;;
                  bool x35422 = x35421 == x35368;
                  bool x35427 = x35422;
                  if (x35422) {
                    int x35423 = x35420.PS_SUPPKEY;;
                    bool x35424 = x35423 == x35370;
                    x35427 = x35424;
                  }
                  bool x35428 = x35427;
                  bool x35429 = x35428;
                  if (x35428) {
                    double x35425 = x35420.PS_AVAILQTY;;
                    bool x35426 = x35425 == x35372;
                    x35429 = x35426;
                  }
                  bool x35430 = x35429;
                  bool x35448;
                  if (x35430) {
                    double x35431 = x35418.aggs;;
                    long x35433 = x35392;
                    struct Anon1574764725* x35435 = x35043;
                    double x35432 = x35431 + x35313;
                    struct Anon1574764725 x35434;
                    x35434.exists = true;
                    x35434.key = x35420;
                    x35434.aggs = x35432;
                    x35435[x35433] = x35434;
                    x35448 = false;
                  } else {
                    long x35438 = x35392;
                    long x35439 = x35438 + 1L;
                    long x35440 = x35439 % x802;
                    x35392 = x35440;
                    struct Anon1574764725* x35442 = x35043;
                    struct Anon1574764725 x35443 = x35442[x35440];
                    x35395 = x35443;
                    x35448 = true;
                  }
                  x35460 = x35448;
                } else {
                  long x35450 = x35392;
                  struct Anon1574764725* x35452 = x35043;
                  x35452[x35450] = x35451;
                  long x35454 = x35044;
                  x35045[x35454] = x35450;
                  x35044 = x35044 + 1L;
                  x35460 = false;
                }
                if (!x35460) break;
              }
            }
          } else {
          }
        }
      } else {
      }
    }
    long x35475 = x35044;
    long x35477;
    for(x35477=0L; x35477 < x35475; x35477++) {
      long x35478 = x35045[x35477];
      struct Anon1574764725* x35479 = x35043;
      struct Anon1574764725 x35480 = x35479[x35478];
      struct Anon1993309635 x35481 = x35480.key;;
      double x35483 = x35480.aggs;;
      double x35482 = x35481.PS_AVAILQTY;;
      double x35484 = 0.5 * x35483;
      bool x35485 = x35482 > x35484;
      if (x35485) {
        long x35487 = x35069;
        int* x35494 = x35064;
        int x35486 = x35481.PS_SUPPKEY;;
        x35494[x35487] = x35486;
        x35069 = x35069 + 1L;
        long x35501 = x35486 & x2034;
        long x35502 = x35070[x35501];
        x35070[x35501] = x35487;
        x35071[x35487] = x35502;
      } else {
      }
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x35510 = x35056;
      bool x35511 = !x35510;
      bool x35516 = x35511;
      if (x35511) {
        long x35512 = x35057;
        long x35513 = x33736;
        bool x35514 = x35512 < x35513;
        x35516 = x35514;
      }
      bool x35517 = x35516;
      if (!x35517) break;
      long x35519 = x35057;
      int* x35520 = x33738;
      int x35521 = x35520[x35519];
      char** x35522 = x33740;
      char* x35523 = x35522[x35519];
      char** x35524 = x33742;
      char* x35525 = x35524[x35519];
      int* x35526 = x33744;
      int x35527 = x35526[x35519];
      x35057 = x35057 + 1;
      long x35536 = x35521 & x2034;
      long x35537 = x35070[x35536];
      long x35538 = x35537;
      long x35561 = x35527 & x2034;
      int x35585 = strlen(x35523);
      int x35586 = strlen(x35525);
      for (;;) {
        long x35539 = x35538;
        bool x35540 = x35539 != -1;
        if (!x35540) break;
        long x35542 = x35538;
        int* x35547 = x35064;
        int x35548 = x35547[x35542];
        long x35555 = x35071[x35542];
        x35538 = x35555;
        bool x35557 = x35548 == x35521;
        if (x35557) {
          long x35562 = x35090[x35561];
          long x35563 = x35562;
          for (;;) {
            long x35564 = x35563;
            bool x35565 = x35564 != -1;
            if (!x35565) break;
            long x35567 = x35563;
            int* x35568 = x35082;
            int x35569 = x35568[x35567];
            long x35577 = x35091[x35567];
            x35563 = x35577;
            bool x35579 = x35569 == x35527;
            if (x35579) {
              if (x975) {
              } else {
                printf("%.*s|%.*s\n",x35585,x35523,x35586,x35525);
                x35098 = x35098 + 1L;
              }
            } else {
            }
          }
        } else {
        }
      }
    }
    long x35601 = x35098;
    printf("(%d rows)\n",x35601);
    gettimeofday(&x35605, NULL);
    timeval_subtract(&x35606, &x35605, &x35604);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x35606.tv_sec * 1000) + (x35606.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
