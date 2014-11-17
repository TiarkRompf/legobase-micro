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

struct Anon2131541195 {
double total;
};

struct Anon0 {
struct Anon2131541195 left;
struct Anon1996247276 right;
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
int main(int x20610, char** x20611) {
  long x20612 = 0L;
  long x6 = DEFAULT_INPUT_SIZE;
  long x20613 = x6;
  long x20614 = 0L;
  int* x20615 = (int*)malloc(x6 * sizeof(int));
  int* x20616 = x20615;
  int* x20617 = (int*)malloc(x6 * sizeof(int));
  int* x20618 = x20617;
  int* x20619 = (int*)malloc(x6 * sizeof(int));
  int* x20620 = x20619;
  double* x20621 = (double*)malloc(x6 * sizeof(double));
  double* x20622 = x20621;
  int x1304 = open("../databases/sf2/partsupp.tbl",0);
  long x1305 = fsize(x1304);
  char* x1306 = mmap(0, x1305, PROT_READ, MAP_FILE | MAP_SHARED, x1304, 0);
  for (;;) {
    long x20625 = x20612;
    bool x20626 = x20625 < x1305;
    if (!x20626) break;
    int x20629 = 0;
    for (;;) {
      long x20630 = x20612;
      char x20631 = x1306[x20630];
      bool x20632 = x20631 != '|';
      bool x20637 = x20632;
      if (x20632) {
        long x20633 = x20612;
        char x20634 = x1306[x20633];
        bool x20635 = x20634 != '\n';
        x20637 = x20635;
      }
      bool x20638 = x20637;
      if (!x20638) break;
      int x20640 = x20629;
      long x20642 = x20612;
      int x20641 = x20640 * 10;
      char x20643 = x1306[x20642];
      char x20644 = x20643 - '0';
      int x20645 = x20641 + x20644;
      x20629 = x20645;
      x20612 = x20612 + 1;
    }
    x20612 = x20612 + 1;
    int x20651 = x20629;
    int x20653 = 0;
    for (;;) {
      long x20654 = x20612;
      char x20655 = x1306[x20654];
      bool x20656 = x20655 != '|';
      bool x20661 = x20656;
      if (x20656) {
        long x20657 = x20612;
        char x20658 = x1306[x20657];
        bool x20659 = x20658 != '\n';
        x20661 = x20659;
      }
      bool x20662 = x20661;
      if (!x20662) break;
      int x20664 = x20653;
      long x20666 = x20612;
      int x20665 = x20664 * 10;
      char x20667 = x1306[x20666];
      char x20668 = x20667 - '0';
      int x20669 = x20665 + x20668;
      x20653 = x20669;
      x20612 = x20612 + 1;
    }
    x20612 = x20612 + 1;
    int x20675 = x20653;
    int x20677 = 0;
    for (;;) {
      long x20678 = x20612;
      char x20679 = x1306[x20678];
      bool x20680 = x20679 != '|';
      bool x20685 = x20680;
      if (x20680) {
        long x20681 = x20612;
        char x20682 = x1306[x20681];
        bool x20683 = x20682 != '\n';
        x20685 = x20683;
      }
      bool x20686 = x20685;
      if (!x20686) break;
      int x20688 = x20677;
      long x20690 = x20612;
      int x20689 = x20688 * 10;
      char x20691 = x1306[x20690];
      char x20692 = x20691 - '0';
      int x20693 = x20689 + x20692;
      x20677 = x20693;
      x20612 = x20612 + 1;
    }
    x20612 = x20612 + 1;
    int x20699 = x20677;
    int x20701 = 0;
    int x20702 = 1;
    for (;;) {
      long x20703 = x20612;
      char x20704 = x1306[x20703];
      bool x20705 = x20704 != '.';
      bool x20710 = x20705;
      if (x20705) {
        long x20706 = x20612;
        char x20707 = x1306[x20706];
        bool x20708 = x20707 != '|';
        x20710 = x20708;
      }
      bool x20711 = x20710;
      bool x20716 = x20711;
      if (x20711) {
        long x20712 = x20612;
        char x20713 = x1306[x20712];
        bool x20714 = x20713 != '\n';
        x20716 = x20714;
      }
      bool x20717 = x20716;
      if (!x20717) break;
      int x20719 = x20701;
      long x20721 = x20612;
      int x20720 = x20719 * 10;
      char x20722 = x1306[x20721];
      char x20723 = x20722 - '0';
      int x20724 = x20720 + x20723;
      x20701 = x20724;
      x20612 = x20612 + 1;
    }
    long x20729 = x20612;
    char x20730 = x1306[x20729];
    bool x20731 = x20730 == '.';
    if (x20731) {
      x20612 = x20612 + 1;
      for (;;) {
        long x20733 = x20612;
        char x20734 = x1306[x20733];
        bool x20735 = x20734 != '|';
        bool x20740 = x20735;
        if (x20735) {
          long x20736 = x20612;
          char x20737 = x1306[x20736];
          bool x20738 = x20737 != '\n';
          x20740 = x20738;
        }
        bool x20741 = x20740;
        if (!x20741) break;
        int x20743 = x20701;
        long x20745 = x20612;
        int x20744 = x20743 * 10;
        char x20746 = x1306[x20745];
        char x20747 = x20746 - '0';
        int x20748 = x20744 + x20747;
        x20701 = x20748;
        int x20750 = x20702;
        int x20751 = x20750 * 10;
        x20702 = x20751;
        x20612 = x20612 + 1;
      }
    } else {
    }
    x20612 = x20612 + 1;
    int x20760 = x20701;
    int x20762 = x20702;
    for (;;) {
      long x20766 = x20612;
      char x20767 = x1306[x20766];
      bool x20768 = x20767 != '|';
      bool x20773 = x20768;
      if (x20768) {
        long x20769 = x20612;
        char x20770 = x1306[x20769];
        bool x20771 = x20770 != '\n';
        x20773 = x20771;
      }
      bool x20774 = x20773;
      if (!x20774) break;
      x20612 = x20612 + 1;
    }
    x20612 = x20612 + 1;
    long x20784 = x20614;
    long x20785 = x20613;
    bool x20786 = x20784 == x20785;
    if (x20786) {
      long x20787 = x20785 * 4L;
      x20613 = x20787;
      printf("buffer.resize %d\n",x20787);
      int* x20790 = x20616;
      int* x20791 = (int*)realloc(x20790,x20787 * sizeof(int));
      x20616 = x20791;
      int* x20793 = x20618;
      int* x20794 = (int*)realloc(x20793,x20787 * sizeof(int));
      x20618 = x20794;
      int* x20796 = x20620;
      int* x20797 = (int*)realloc(x20796,x20787 * sizeof(int));
      x20620 = x20797;
      double* x20799 = x20622;
      double* x20800 = (double*)realloc(x20799,x20787 * sizeof(double));
      x20622 = x20800;
    } else {
    }
    int* x20807 = x20616;
    x20807[x20784] = x20651;
    int* x20809 = x20618;
    x20809[x20784] = x20675;
    int* x20811 = x20620;
    x20811[x20784] = x20699;
    double* x20813 = x20622;
    double x20761 = (double)x20760;
    double x20763 = (double)x20762;
    double x20764 = x20761 / x20763;
    x20813[x20784] = x20764;
    x20614 = x20614 + 1;
  }
  long x20820 = 0L;
  long x20821 = x6;
  long x20822 = 0L;
  int* x20823 = (int*)malloc(x6 * sizeof(int));
  int* x20824 = x20823;
  int* x20829 = (int*)malloc(x6 * sizeof(int));
  int* x20830 = x20829;
  int x1750 = open("../databases/sf2/supplier.tbl",0);
  long x1751 = fsize(x1750);
  char* x1752 = mmap(0, x1751, PROT_READ, MAP_FILE | MAP_SHARED, x1750, 0);
  for (;;) {
    long x20837 = x20820;
    bool x20838 = x20837 < x1751;
    if (!x20838) break;
    int x20841 = 0;
    for (;;) {
      long x20842 = x20820;
      char x20843 = x1752[x20842];
      bool x20844 = x20843 != '|';
      bool x20849 = x20844;
      if (x20844) {
        long x20845 = x20820;
        char x20846 = x1752[x20845];
        bool x20847 = x20846 != '\n';
        x20849 = x20847;
      }
      bool x20850 = x20849;
      if (!x20850) break;
      int x20852 = x20841;
      long x20854 = x20820;
      int x20853 = x20852 * 10;
      char x20855 = x1752[x20854];
      char x20856 = x20855 - '0';
      int x20857 = x20853 + x20856;
      x20841 = x20857;
      x20820 = x20820 + 1;
    }
    x20820 = x20820 + 1;
    int x20863 = x20841;
    for (;;) {
      long x20865 = x20820;
      char x20866 = x1752[x20865];
      bool x20867 = x20866 != '|';
      bool x20872 = x20867;
      if (x20867) {
        long x20868 = x20820;
        char x20869 = x1752[x20868];
        bool x20870 = x20869 != '\n';
        x20872 = x20870;
      }
      bool x20873 = x20872;
      if (!x20873) break;
      x20820 = x20820 + 1;
    }
    x20820 = x20820 + 1;
    for (;;) {
      long x20883 = x20820;
      char x20884 = x1752[x20883];
      bool x20885 = x20884 != '|';
      bool x20890 = x20885;
      if (x20885) {
        long x20886 = x20820;
        char x20887 = x1752[x20886];
        bool x20888 = x20887 != '\n';
        x20890 = x20888;
      }
      bool x20891 = x20890;
      if (!x20891) break;
      x20820 = x20820 + 1;
    }
    x20820 = x20820 + 1;
    int x20901 = 0;
    for (;;) {
      long x20902 = x20820;
      char x20903 = x1752[x20902];
      bool x20904 = x20903 != '|';
      bool x20909 = x20904;
      if (x20904) {
        long x20905 = x20820;
        char x20906 = x1752[x20905];
        bool x20907 = x20906 != '\n';
        x20909 = x20907;
      }
      bool x20910 = x20909;
      if (!x20910) break;
      int x20912 = x20901;
      long x20914 = x20820;
      int x20913 = x20912 * 10;
      char x20915 = x1752[x20914];
      char x20916 = x20915 - '0';
      int x20917 = x20913 + x20916;
      x20901 = x20917;
      x20820 = x20820 + 1;
    }
    x20820 = x20820 + 1;
    int x20923 = x20901;
    for (;;) {
      long x20925 = x20820;
      char x20926 = x1752[x20925];
      bool x20927 = x20926 != '|';
      bool x20932 = x20927;
      if (x20927) {
        long x20928 = x20820;
        char x20929 = x1752[x20928];
        bool x20930 = x20929 != '\n';
        x20932 = x20930;
      }
      bool x20933 = x20932;
      if (!x20933) break;
      x20820 = x20820 + 1;
    }
    x20820 = x20820 + 1;
    for (;;) {
      long x20945 = x20820;
      char x20946 = x1752[x20945];
      bool x20947 = x20946 != '.';
      bool x20952 = x20947;
      if (x20947) {
        long x20948 = x20820;
        char x20949 = x1752[x20948];
        bool x20950 = x20949 != '|';
        x20952 = x20950;
      }
      bool x20953 = x20952;
      bool x20958 = x20953;
      if (x20953) {
        long x20954 = x20820;
        char x20955 = x1752[x20954];
        bool x20956 = x20955 != '\n';
        x20958 = x20956;
      }
      bool x20959 = x20958;
      if (!x20959) break;
      x20820 = x20820 + 1;
    }
    long x20971 = x20820;
    char x20972 = x1752[x20971];
    bool x20973 = x20972 == '.';
    if (x20973) {
      x20820 = x20820 + 1;
      for (;;) {
        long x20975 = x20820;
        char x20976 = x1752[x20975];
        bool x20977 = x20976 != '|';
        bool x20982 = x20977;
        if (x20977) {
          long x20978 = x20820;
          char x20979 = x1752[x20978];
          bool x20980 = x20979 != '\n';
          x20982 = x20980;
        }
        bool x20983 = x20982;
        if (!x20983) break;
        x20820 = x20820 + 1;
      }
    } else {
    }
    x20820 = x20820 + 1;
    for (;;) {
      long x21008 = x20820;
      char x21009 = x1752[x21008];
      bool x21010 = x21009 != '|';
      bool x21015 = x21010;
      if (x21010) {
        long x21011 = x20820;
        char x21012 = x1752[x21011];
        bool x21013 = x21012 != '\n';
        x21015 = x21013;
      }
      bool x21016 = x21015;
      if (!x21016) break;
      x20820 = x20820 + 1;
    }
    x20820 = x20820 + 1;
    long x21026 = x20822;
    long x21027 = x20821;
    bool x21028 = x21026 == x21027;
    if (x21028) {
      long x21029 = x21027 * 4L;
      x20821 = x21029;
      printf("buffer.resize %d\n",x21029);
      int* x21032 = x20824;
      int* x21033 = (int*)realloc(x21032,x21029 * sizeof(int));
      x20824 = x21033;
      int* x21041 = x20830;
      int* x21042 = (int*)realloc(x21041,x21029 * sizeof(int));
      x20830 = x21042;
    } else {
    }
    int* x21055 = x20824;
    x21055[x21026] = x20863;
    int* x21061 = x20830;
    x21061[x21026] = x20923;
    x20822 = x20822 + 1;
  }
  long x21072 = 0L;
  long x21073 = x6;
  long x21074 = 0L;
  int* x21075 = (int*)malloc(x6 * sizeof(int));
  int* x21076 = x21075;
  char** x21077 = (char**)malloc(x6 * sizeof(char*));
  char** x21078 = x21077;
  int x1515 = open("../databases/sf2/nation.tbl",0);
  long x1516 = fsize(x1515);
  char* x1517 = mmap(0, x1516, PROT_READ, MAP_FILE | MAP_SHARED, x1515, 0);
  for (;;) {
    long x21083 = x21072;
    bool x21084 = x21083 < x1516;
    if (!x21084) break;
    int x21087 = 0;
    for (;;) {
      long x21088 = x21072;
      char x21089 = x1517[x21088];
      bool x21090 = x21089 != '|';
      bool x21095 = x21090;
      if (x21090) {
        long x21091 = x21072;
        char x21092 = x1517[x21091];
        bool x21093 = x21092 != '\n';
        x21095 = x21093;
      }
      bool x21096 = x21095;
      if (!x21096) break;
      int x21098 = x21087;
      long x21100 = x21072;
      int x21099 = x21098 * 10;
      char x21101 = x1517[x21100];
      char x21102 = x21101 - '0';
      int x21103 = x21099 + x21102;
      x21087 = x21103;
      x21072 = x21072 + 1;
    }
    x21072 = x21072 + 1;
    int x21109 = x21087;
    long x21110 = x21072;
    for (;;) {
      long x21111 = x21072;
      char x21112 = x1517[x21111];
      bool x21113 = x21112 != '|';
      bool x21118 = x21113;
      if (x21113) {
        long x21114 = x21072;
        char x21115 = x1517[x21114];
        bool x21116 = x21115 != '\n';
        x21118 = x21116;
      }
      bool x21119 = x21118;
      if (!x21119) break;
      x21072 = x21072 + 1;
    }
    x21072 = x21072 + 1;
    for (;;) {
      long x21130 = x21072;
      char x21131 = x1517[x21130];
      bool x21132 = x21131 != '|';
      bool x21137 = x21132;
      if (x21132) {
        long x21133 = x21072;
        char x21134 = x1517[x21133];
        bool x21135 = x21134 != '\n';
        x21137 = x21135;
      }
      bool x21138 = x21137;
      if (!x21138) break;
      x21072 = x21072 + 1;
    }
    x21072 = x21072 + 1;
    for (;;) {
      long x21153 = x21072;
      char x21154 = x1517[x21153];
      bool x21155 = x21154 != '|';
      bool x21160 = x21155;
      if (x21155) {
        long x21156 = x21072;
        char x21157 = x1517[x21156];
        bool x21158 = x21157 != '\n';
        x21160 = x21158;
      }
      bool x21161 = x21160;
      if (!x21161) break;
      x21072 = x21072 + 1;
    }
    x21072 = x21072 + 1;
    long x21171 = x21074;
    long x21172 = x21073;
    bool x21173 = x21171 == x21172;
    if (x21173) {
      long x21174 = x21172 * 4L;
      x21073 = x21174;
      printf("buffer.resize %d\n",x21174);
      int* x21177 = x21076;
      int* x21178 = (int*)realloc(x21177,x21174 * sizeof(int));
      x21076 = x21178;
      char** x21180 = x21078;
      char** x21181 = (char**)realloc(x21180,x21174 * sizeof(char*));
      x21078 = x21181;
    } else {
    }
    int* x21191 = x21076;
    x21191[x21171] = x21109;
    char** x21193 = x21078;
    char* x21127 = x1517+x21110;
    x21193[x21171] = x21127;
    x21074 = x21074 + 1;
  }
  long x2011 = DEFAULT_JOIN_HASH_SIZE;
  long x787 = DEFAULT_AGG_HASH_SIZE ;
  long x21273 = DEFAULT_VIEW_SIZE;
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
  int x21202;
  for(x21202=0; x21202 < 5; x21202++) {
    bool x21203 = false;
    long x21204 = 0L;
    bool x21205 = false;
    long x21206 = 0L;
    int* x21209 = (int*)malloc(x2011 * sizeof(int));
    int* x21210 = x21209;
    long x21217 = 0L;
    long* x21218 = (long*)malloc(x2011 * sizeof(long));
    long* x21219 = (long*)malloc(x2011 * sizeof(long));
    long x21220;
    for(x21220=0L; x21220 < x2011; x21220++) {
      x21218[x21220] = -1L;
    }
    bool x21225 = false;
    long x21226 = 0L;
    int* x21236 = (int*)malloc(x2011 * sizeof(int));
    int* x21237 = x21236;
    long x21250 = 0L;
    long* x21251 = (long*)malloc(x2011 * sizeof(long));
    long* x21252 = (long*)malloc(x2011 * sizeof(long));
    long x21253;
    for(x21253=0L; x21253 < x2011; x21253++) {
      x21251[x21253] = -1L;
    }
    struct Anon1996247276* x21259 = (struct Anon1996247276*)malloc(x787 * sizeof(struct Anon1996247276));
    struct Anon1996247276* x21260 = x21259;
    long x21261 = 0L;
    long* x21262 = (long*)malloc(x787 * sizeof(long));
    long x21263;
    for(x21263=0L; x21263 < x787; x21263++) {
      struct Anon1996247276* x21264 = x21260;
      struct Anon1996247276 x21265 = x21264[x21263];
      int x21266 = x21265.key;;
      struct Anon2052879266 x21267 = x21265.aggs;;
      struct Anon1996247276 x21268;
      x21268.exists = false;
      x21268.key = x21266;
      x21268.aggs = x21267;
      x21264[x21263] = x21268;
    }
    long x21274 = x21273;
    long x21275 = 0L;
    int* x21278 = (int*)malloc(x21273 * sizeof(int));
    int* x21279 = x21278;
    double* x21280 = (double*)malloc(x21273 * sizeof(double));
    double* x21281 = x21280;
    struct Anon801061462* x21285 = (struct Anon801061462*)malloc(x787 * sizeof(struct Anon801061462));
    struct Anon801061462* x21286 = x21285;
    long x21287 = 0L;
    long* x21288 = (long*)malloc(x787 * sizeof(long));
    long x21289;
    for(x21289=0L; x21289 < x787; x21289++) {
      struct Anon801061462* x21290 = x21286;
      struct Anon801061462 x21291 = x21290[x21289];
      char* x21292 = x21291.key;;
      struct Anon2052879266 x21293 = x21291.aggs;;
      struct Anon801061462 x21294;
      x21294.exists = false;
      x21294.key = x21292;
      x21294.aggs = x21293;
      x21290[x21289] = x21294;
    }
    double x21301 = 0.0;
    long x21305 = 0L;
    struct timeval x21711, x21712, x21713;
    gettimeofday(&x21711, NULL);
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x21307 = x21205;
      bool x21308 = !x21307;
      bool x21313 = x21308;
      if (x21308) {
        long x21309 = x21206;
        long x21310 = x21074;
        bool x21311 = x21309 < x21310;
        x21313 = x21311;
      }
      bool x21314 = x21313;
      if (!x21314) break;
      long x21316 = x21206;
      int* x21317 = x21076;
      int x21318 = x21317[x21316];
      char** x21319 = x21078;
      char* x21320 = x21319[x21316];
      x21206 = x21206 + 1;
      bool x21327 = strcmp(x21320,"UNITED KINGDOM") == 0;;
      if (x21327) {
        long x21328 = x21217;
        int* x21329 = x21210;
        x21329[x21328] = x21318;
        x21217 = x21217 + 1L;
        long x21338 = x21318 & x2034;
        long x21339 = x21218[x21338];
        x21218[x21338] = x21328;
        x21219[x21328] = x21339;
      } else {
      }
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x21347 = x21203;
      bool x21348 = !x21347;
      bool x21353 = x21348;
      if (x21348) {
        long x21349 = x21204;
        long x21350 = x20822;
        bool x21351 = x21349 < x21350;
        x21353 = x21351;
      }
      bool x21354 = x21353;
      if (!x21354) break;
      long x21356 = x21204;
      int* x21357 = x20824;
      int x21358 = x21357[x21356];
      int* x21363 = x20830;
      int x21364 = x21363[x21356];
      x21204 = x21204 + 1;
      long x21373 = x21364 & x2034;
      long x21374 = x21218[x21373];
      long x21375 = x21374;
      long x21419 = x21358 & x2034;
      for (;;) {
        long x21376 = x21375;
        bool x21377 = x21376 != -1;
        if (!x21377) break;
        long x21379 = x21375;
        int* x21380 = x21210;
        int x21381 = x21380[x21379];
        long x21389 = x21219[x21379];
        x21375 = x21389;
        bool x21391 = x21381 == x21364;
        if (x21391) {
          long x21395 = x21250;
          int* x21404 = x21237;
          x21404[x21395] = x21358;
          x21250 = x21250 + 1L;
          long x21420 = x21251[x21419];
          x21251[x21419] = x21395;
          x21252[x21395] = x21420;
        } else {
        }
      }
    }
    printf("%s\n","begin scan PARTSUPP");
    for (;;) {
      bool x21430 = x21225;
      bool x21431 = !x21430;
      bool x21436 = x21431;
      if (x21431) {
        long x21432 = x21226;
        long x21433 = x20614;
        bool x21434 = x21432 < x21433;
        x21436 = x21434;
      }
      bool x21437 = x21436;
      if (!x21437) break;
      long x21439 = x21226;
      int* x21440 = x20616;
      int x21441 = x21440[x21439];
      int* x21442 = x20618;
      int x21443 = x21442[x21439];
      int* x21444 = x20620;
      int x21445 = x21444[x21439];
      double* x21446 = x20622;
      double x21447 = x21446[x21439];
      x21226 = x21226 + 1;
      long x21452 = x21443 & x2034;
      long x21453 = x21251[x21452];
      long x21454 = x21453;
      long x21488 = x21441 & x802;
      double x21502 = x21447 * x21445;
      struct Anon2052879266 x21535;
      x21535._0 = x21502;
      struct Anon1996247276 x21536;
      x21536.exists = true;
      x21536.key = x21441;
      x21536.aggs = x21535;
      for (;;) {
        long x21455 = x21454;
        bool x21456 = x21455 != -1;
        if (!x21456) break;
        long x21458 = x21454;
        int* x21467 = x21237;
        int x21468 = x21467[x21458];
        long x21482 = x21252[x21458];
        x21454 = x21482;
        bool x21484 = x21468 == x21443;
        if (x21484) {
          long x21489 = x21488;
          struct Anon1996247276* x21490 = x21260;
          struct Anon1996247276 x21491 = x21490[x21488];
          struct Anon1996247276 x21492 = x21491;
          bool x21493 = x21491.exists;;
          bool x21498 = x21493;
          if (x21493) {
            struct Anon1996247276 x21494 = x21492;
            int x21495 = x21494.key;;
            bool x21496 = x21495 == x21441;
            x21498 = x21496;
          }
          bool x21499 = x21498;
          if (x21499) {
            struct Anon2052879266 x21500 = x21491.aggs;;
            int x21505 = x21491.key;;
            double x21501 = x21500._0;;
            double x21503 = x21501 + x21502;
            struct Anon2052879266 x21504;
            x21504._0 = x21503;
            struct Anon1996247276 x21506;
            x21506.exists = true;
            x21506.key = x21505;
            x21506.aggs = x21504;
            x21490[x21488] = x21506;
          } else {
            for (;;) {
              struct Anon1996247276 x21509 = x21492;
              bool x21510 = x21509.exists;;
              bool x21545;
              if (x21510) {
                int x21511 = x21509.key;;
                bool x21512 = x21511 == x21441;
                bool x21532;
                if (x21512) {
                  struct Anon2052879266 x21513 = x21509.aggs;;
                  long x21517 = x21489;
                  struct Anon1996247276* x21519 = x21260;
                  double x21514 = x21513._0;;
                  double x21515 = x21514 + x21502;
                  struct Anon2052879266 x21516;
                  x21516._0 = x21515;
                  struct Anon1996247276 x21518;
                  x21518.exists = true;
                  x21518.key = x21511;
                  x21518.aggs = x21516;
                  x21519[x21517] = x21518;
                  x21532 = false;
                } else {
                  long x21522 = x21489;
                  long x21523 = x21522 + 1L;
                  long x21524 = x21523 % x802;
                  x21489 = x21524;
                  struct Anon1996247276* x21526 = x21260;
                  struct Anon1996247276 x21527 = x21526[x21524];
                  x21492 = x21527;
                  x21532 = true;
                }
                x21545 = x21532;
              } else {
                long x21534 = x21489;
                struct Anon1996247276* x21537 = x21260;
                x21537[x21534] = x21536;
                long x21539 = x21261;
                x21262[x21539] = x21534;
                x21261 = x21261 + 1L;
                x21545 = false;
              }
              if (!x21545) break;
            }
          }
        } else {
        }
      }
    }
    long x21558 = x21261;
    long x21560;
    for(x21560=0L; x21560 < x21558; x21560++) {
      long x21561 = x21262[x21560];
      struct Anon1996247276* x21562 = x21260;
      struct Anon1996247276 x21563 = x21562[x21561];
      long x21564 = x21275;
      long x21565 = x21274;
      bool x21566 = x21564 == x21565;
      if (x21566) {
        long x21567 = x21565 * 4L;
        x21274 = x21567;
        printf("buffer.resize %d\n",x21567);
        int* x21573 = x21279;
        int* x21574 = (int*)realloc(x21573,x21567 * sizeof(int));
        x21279 = x21574;
        printf("buffer.resize %d\n",x21567);
        double* x21577 = x21281;
        double* x21578 = (double*)realloc(x21577,x21567 * sizeof(double));
        x21281 = x21578;
      } else {
      }
      int x21585 = x21563.key;;
      int* x21586 = x21279;
      x21586[x21564] = x21585;
      struct Anon2052879266 x21588 = x21563.aggs;;
      double* x21590 = x21281;
      double x21589 = x21588._0;;
      x21590[x21564] = x21589;
      x21275 = x21275 + 1;
    }
    long x21595 = x21275;
    long x21597;
    for(x21597=0L; x21597 < x21595; x21597++) {
      double* x21602 = x21281;
      double x21603 = x21602[x21597];
      long x21606 = x9316;
      struct Anon801061462* x21607 = x21286;
      struct Anon801061462 x21608 = x21607[x9316];
      struct Anon801061462 x21609 = x21608;
      bool x21610 = x21608.exists;;
      bool x21615 = x21610;
      if (x21610) {
        struct Anon801061462 x21611 = x21609;
        char* x21612 = x21611.key;;
        bool x21613 = strcmp(x21612,"Total") == 0;;
        x21615 = x21613;
      }
      bool x21616 = x21615;
      if (x21616) {
        struct Anon2052879266 x21617 = x21608.aggs;;
        char* x21621 = x21608.key;;
        double x21618 = x21617._0;;
        double x21619 = x21618 + x21603;
        struct Anon2052879266 x21620;
        x21620._0 = x21619;
        struct Anon801061462 x21622;
        x21622.exists = true;
        x21622.key = x21621;
        x21622.aggs = x21620;
        x21607[x9316] = x21622;
      } else {
        struct Anon2052879266 x21604;
        x21604._0 = x21603;
        struct Anon801061462 x21651;
        x21651.exists = true;
        x21651.key = "Total";
        x21651.aggs = x21604;
        for (;;) {
          struct Anon801061462 x21625 = x21609;
          bool x21626 = x21625.exists;;
          bool x21660;
          if (x21626) {
            char* x21627 = x21625.key;;
            bool x21628 = strcmp(x21627,"Total") == 0;;
            bool x21648;
            if (x21628) {
              struct Anon2052879266 x21629 = x21625.aggs;;
              long x21633 = x21606;
              struct Anon801061462* x21635 = x21286;
              double x21630 = x21629._0;;
              double x21631 = x21630 + x21603;
              struct Anon2052879266 x21632;
              x21632._0 = x21631;
              struct Anon801061462 x21634;
              x21634.exists = true;
              x21634.key = x21627;
              x21634.aggs = x21632;
              x21635[x21633] = x21634;
              x21648 = false;
            } else {
              long x21638 = x21606;
              long x21639 = x21638 + 1L;
              long x21640 = x21639 % x802;
              x21606 = x21640;
              struct Anon801061462* x21642 = x21286;
              struct Anon801061462 x21643 = x21642[x21640];
              x21609 = x21643;
              x21648 = true;
            }
            x21660 = x21648;
          } else {
            long x21650 = x21606;
            struct Anon801061462* x21652 = x21286;
            x21652[x21650] = x21651;
            long x21654 = x21287;
            x21288[x21654] = x21650;
            x21287 = x21287 + 1L;
            x21660 = false;
          }
          if (!x21660) break;
        }
      }
    }
    long x21669 = x21287;
    long x21671;
    for(x21671=0L; x21671 < x21669; x21671++) {
      long x21672 = x21288[x21671];
      struct Anon801061462* x21673 = x21286;
      struct Anon801061462 x21674 = x21673[x21672];
      struct Anon2052879266 x21675 = x21674.aggs;;
      double x21676 = x21675._0;;
      double x21677 = x21676 * 1.0E-4;
      x21301 = x21677;
      long x21680 = x21275;
      long x21682;
      for(x21682=0L; x21682 < x21680; x21682++) {
        int* x21685 = x21279;
        int x21686 = x21685[x21682];
        double* x21687 = x21281;
        double x21688 = x21687[x21682];
        double x21691 = x21301;
        bool x21693 = x21688 > x21691;
        if (x21693) {
          if (x975) {
          } else {
            printf("%d|%.2f\n",x21686,x21688);
            x21305 = x21305 + 1L;
          }
        } else {
        }
      }
    }
    long x21708 = x21305;
    printf("(%d rows)\n",x21708);
    gettimeofday(&x21712, NULL);
    timeval_subtract(&x21713, &x21712, &x21711);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x21713.tv_sec * 1000) + (x21713.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
