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

struct Anon0 {
struct Anon325450556 left;
struct Anon168903330 right;
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
int main(int x18382, char** x18383) {
  long x18384 = 0L;
  long x6 = DEFAULT_INPUT_SIZE;
  long x18385 = x6;
  long x18386 = 0L;
  int* x18387 = (int*)malloc(x6 * sizeof(int));
  int* x18388 = x18387;
  double* x18397 = (double*)malloc(x6 * sizeof(double));
  double* x18398 = x18397;
  double* x18399 = (double*)malloc(x6 * sizeof(double));
  double* x18400 = x18399;
  char* x18403 = (char*)malloc(x6 * sizeof(char));
  char* x18404 = x18403;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  long x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    long x18419 = x18384;
    bool x18420 = x18419 < x3;
    if (!x18420) break;
    int x18423 = 0;
    for (;;) {
      long x18424 = x18384;
      char x18425 = x4[x18424];
      bool x18426 = x18425 != '|';
      bool x18431 = x18426;
      if (x18426) {
        long x18427 = x18384;
        char x18428 = x4[x18427];
        bool x18429 = x18428 != '\n';
        x18431 = x18429;
      }
      bool x18432 = x18431;
      if (!x18432) break;
      int x18434 = x18423;
      long x18436 = x18384;
      int x18435 = x18434 * 10;
      char x18437 = x4[x18436];
      char x18438 = x18437 - '0';
      int x18439 = x18435 + x18438;
      x18423 = x18439;
      x18384 = x18384 + 1;
    }
    x18384 = x18384 + 1;
    int x18445 = x18423;
    for (;;) {
      long x18448 = x18384;
      char x18449 = x4[x18448];
      bool x18450 = x18449 != '|';
      bool x18455 = x18450;
      if (x18450) {
        long x18451 = x18384;
        char x18452 = x4[x18451];
        bool x18453 = x18452 != '\n';
        x18455 = x18453;
      }
      bool x18456 = x18455;
      if (!x18456) break;
      x18384 = x18384 + 1;
    }
    x18384 = x18384 + 1;
    for (;;) {
      long x18472 = x18384;
      char x18473 = x4[x18472];
      bool x18474 = x18473 != '|';
      bool x18479 = x18474;
      if (x18474) {
        long x18475 = x18384;
        char x18476 = x4[x18475];
        bool x18477 = x18476 != '\n';
        x18479 = x18477;
      }
      bool x18480 = x18479;
      if (!x18480) break;
      x18384 = x18384 + 1;
    }
    x18384 = x18384 + 1;
    for (;;) {
      long x18496 = x18384;
      char x18497 = x4[x18496];
      bool x18498 = x18497 != '|';
      bool x18503 = x18498;
      if (x18498) {
        long x18499 = x18384;
        char x18500 = x4[x18499];
        bool x18501 = x18500 != '\n';
        x18503 = x18501;
      }
      bool x18504 = x18503;
      if (!x18504) break;
      x18384 = x18384 + 1;
    }
    x18384 = x18384 + 1;
    for (;;) {
      long x18521 = x18384;
      char x18522 = x4[x18521];
      bool x18523 = x18522 != '.';
      bool x18528 = x18523;
      if (x18523) {
        long x18524 = x18384;
        char x18525 = x4[x18524];
        bool x18526 = x18525 != '|';
        x18528 = x18526;
      }
      bool x18529 = x18528;
      bool x18534 = x18529;
      if (x18529) {
        long x18530 = x18384;
        char x18531 = x4[x18530];
        bool x18532 = x18531 != '\n';
        x18534 = x18532;
      }
      bool x18535 = x18534;
      if (!x18535) break;
      x18384 = x18384 + 1;
    }
    long x18547 = x18384;
    char x18548 = x4[x18547];
    bool x18549 = x18548 == '.';
    if (x18549) {
      x18384 = x18384 + 1;
      for (;;) {
        long x18551 = x18384;
        char x18552 = x4[x18551];
        bool x18553 = x18552 != '|';
        bool x18558 = x18553;
        if (x18553) {
          long x18554 = x18384;
          char x18555 = x4[x18554];
          bool x18556 = x18555 != '\n';
          x18558 = x18556;
        }
        bool x18559 = x18558;
        if (!x18559) break;
        x18384 = x18384 + 1;
      }
    } else {
    }
    x18384 = x18384 + 1;
    int x18584 = 0;
    int x18585 = 1;
    for (;;) {
      long x18586 = x18384;
      char x18587 = x4[x18586];
      bool x18588 = x18587 != '.';
      bool x18593 = x18588;
      if (x18588) {
        long x18589 = x18384;
        char x18590 = x4[x18589];
        bool x18591 = x18590 != '|';
        x18593 = x18591;
      }
      bool x18594 = x18593;
      bool x18599 = x18594;
      if (x18594) {
        long x18595 = x18384;
        char x18596 = x4[x18595];
        bool x18597 = x18596 != '\n';
        x18599 = x18597;
      }
      bool x18600 = x18599;
      if (!x18600) break;
      int x18602 = x18584;
      long x18604 = x18384;
      int x18603 = x18602 * 10;
      char x18605 = x4[x18604];
      char x18606 = x18605 - '0';
      int x18607 = x18603 + x18606;
      x18584 = x18607;
      x18384 = x18384 + 1;
    }
    long x18612 = x18384;
    char x18613 = x4[x18612];
    bool x18614 = x18613 == '.';
    if (x18614) {
      x18384 = x18384 + 1;
      for (;;) {
        long x18616 = x18384;
        char x18617 = x4[x18616];
        bool x18618 = x18617 != '|';
        bool x18623 = x18618;
        if (x18618) {
          long x18619 = x18384;
          char x18620 = x4[x18619];
          bool x18621 = x18620 != '\n';
          x18623 = x18621;
        }
        bool x18624 = x18623;
        if (!x18624) break;
        int x18626 = x18584;
        long x18628 = x18384;
        int x18627 = x18626 * 10;
        char x18629 = x4[x18628];
        char x18630 = x18629 - '0';
        int x18631 = x18627 + x18630;
        x18584 = x18631;
        int x18633 = x18585;
        int x18634 = x18633 * 10;
        x18585 = x18634;
        x18384 = x18384 + 1;
      }
    } else {
    }
    x18384 = x18384 + 1;
    int x18643 = x18584;
    int x18645 = x18585;
    int x18649 = 0;
    int x18650 = 1;
    for (;;) {
      long x18651 = x18384;
      char x18652 = x4[x18651];
      bool x18653 = x18652 != '.';
      bool x18658 = x18653;
      if (x18653) {
        long x18654 = x18384;
        char x18655 = x4[x18654];
        bool x18656 = x18655 != '|';
        x18658 = x18656;
      }
      bool x18659 = x18658;
      bool x18664 = x18659;
      if (x18659) {
        long x18660 = x18384;
        char x18661 = x4[x18660];
        bool x18662 = x18661 != '\n';
        x18664 = x18662;
      }
      bool x18665 = x18664;
      if (!x18665) break;
      int x18667 = x18649;
      long x18669 = x18384;
      int x18668 = x18667 * 10;
      char x18670 = x4[x18669];
      char x18671 = x18670 - '0';
      int x18672 = x18668 + x18671;
      x18649 = x18672;
      x18384 = x18384 + 1;
    }
    long x18677 = x18384;
    char x18678 = x4[x18677];
    bool x18679 = x18678 == '.';
    if (x18679) {
      x18384 = x18384 + 1;
      for (;;) {
        long x18681 = x18384;
        char x18682 = x4[x18681];
        bool x18683 = x18682 != '|';
        bool x18688 = x18683;
        if (x18683) {
          long x18684 = x18384;
          char x18685 = x4[x18684];
          bool x18686 = x18685 != '\n';
          x18688 = x18686;
        }
        bool x18689 = x18688;
        if (!x18689) break;
        int x18691 = x18649;
        long x18693 = x18384;
        int x18692 = x18691 * 10;
        char x18694 = x4[x18693];
        char x18695 = x18694 - '0';
        int x18696 = x18692 + x18695;
        x18649 = x18696;
        int x18698 = x18650;
        int x18699 = x18698 * 10;
        x18650 = x18699;
        x18384 = x18384 + 1;
      }
    } else {
    }
    x18384 = x18384 + 1;
    int x18708 = x18649;
    int x18710 = x18650;
    for (;;) {
      long x18716 = x18384;
      char x18717 = x4[x18716];
      bool x18718 = x18717 != '.';
      bool x18723 = x18718;
      if (x18718) {
        long x18719 = x18384;
        char x18720 = x4[x18719];
        bool x18721 = x18720 != '|';
        x18723 = x18721;
      }
      bool x18724 = x18723;
      bool x18729 = x18724;
      if (x18724) {
        long x18725 = x18384;
        char x18726 = x4[x18725];
        bool x18727 = x18726 != '\n';
        x18729 = x18727;
      }
      bool x18730 = x18729;
      if (!x18730) break;
      x18384 = x18384 + 1;
    }
    long x18742 = x18384;
    char x18743 = x4[x18742];
    bool x18744 = x18743 == '.';
    if (x18744) {
      x18384 = x18384 + 1;
      for (;;) {
        long x18746 = x18384;
        char x18747 = x4[x18746];
        bool x18748 = x18747 != '|';
        bool x18753 = x18748;
        if (x18748) {
          long x18749 = x18384;
          char x18750 = x4[x18749];
          bool x18751 = x18750 != '\n';
          x18753 = x18751;
        }
        bool x18754 = x18753;
        if (!x18754) break;
        x18384 = x18384 + 1;
      }
    } else {
    }
    x18384 = x18384 + 1;
    long x18778 = x18384;
    x18384 = x18384 + 2;
    x18384 = x18384 + 2;
    for (;;) {
      long x18786 = x18384;
      char x18787 = x4[x18786];
      bool x18788 = x18787 != '-';
      bool x18793 = x18788;
      if (x18788) {
        long x18789 = x18384;
        char x18790 = x4[x18789];
        bool x18791 = x18790 != '\n';
        x18793 = x18791;
      }
      bool x18794 = x18793;
      if (!x18794) break;
      x18384 = x18384 + 1;
    }
    x18384 = x18384 + 1;
    for (;;) {
      long x18810 = x18384;
      char x18811 = x4[x18810];
      bool x18812 = x18811 != '-';
      bool x18817 = x18812;
      if (x18812) {
        long x18813 = x18384;
        char x18814 = x4[x18813];
        bool x18815 = x18814 != '\n';
        x18817 = x18815;
      }
      bool x18818 = x18817;
      if (!x18818) break;
      x18384 = x18384 + 1;
    }
    x18384 = x18384 + 1;
    for (;;) {
      long x18834 = x18384;
      char x18835 = x4[x18834];
      bool x18836 = x18835 != '|';
      bool x18841 = x18836;
      if (x18836) {
        long x18837 = x18384;
        char x18838 = x4[x18837];
        bool x18839 = x18838 != '\n';
        x18841 = x18839;
      }
      bool x18842 = x18841;
      if (!x18842) break;
      x18384 = x18384 + 1;
    }
    x18384 = x18384 + 1;
    for (;;) {
      long x18862 = x18384;
      char x18863 = x4[x18862];
      bool x18864 = x18863 != '-';
      bool x18869 = x18864;
      if (x18864) {
        long x18865 = x18384;
        char x18866 = x4[x18865];
        bool x18867 = x18866 != '\n';
        x18869 = x18867;
      }
      bool x18870 = x18869;
      if (!x18870) break;
      x18384 = x18384 + 1;
    }
    x18384 = x18384 + 1;
    for (;;) {
      long x18886 = x18384;
      char x18887 = x4[x18886];
      bool x18888 = x18887 != '-';
      bool x18893 = x18888;
      if (x18888) {
        long x18889 = x18384;
        char x18890 = x4[x18889];
        bool x18891 = x18890 != '\n';
        x18893 = x18891;
      }
      bool x18894 = x18893;
      if (!x18894) break;
      x18384 = x18384 + 1;
    }
    x18384 = x18384 + 1;
    for (;;) {
      long x18910 = x18384;
      char x18911 = x4[x18910];
      bool x18912 = x18911 != '|';
      bool x18917 = x18912;
      if (x18912) {
        long x18913 = x18384;
        char x18914 = x4[x18913];
        bool x18915 = x18914 != '\n';
        x18917 = x18915;
      }
      bool x18918 = x18917;
      if (!x18918) break;
      x18384 = x18384 + 1;
    }
    x18384 = x18384 + 1;
    for (;;) {
      long x18938 = x18384;
      char x18939 = x4[x18938];
      bool x18940 = x18939 != '-';
      bool x18945 = x18940;
      if (x18940) {
        long x18941 = x18384;
        char x18942 = x4[x18941];
        bool x18943 = x18942 != '\n';
        x18945 = x18943;
      }
      bool x18946 = x18945;
      if (!x18946) break;
      x18384 = x18384 + 1;
    }
    x18384 = x18384 + 1;
    for (;;) {
      long x18962 = x18384;
      char x18963 = x4[x18962];
      bool x18964 = x18963 != '-';
      bool x18969 = x18964;
      if (x18964) {
        long x18965 = x18384;
        char x18966 = x4[x18965];
        bool x18967 = x18966 != '\n';
        x18969 = x18967;
      }
      bool x18970 = x18969;
      if (!x18970) break;
      x18384 = x18384 + 1;
    }
    x18384 = x18384 + 1;
    for (;;) {
      long x18986 = x18384;
      char x18987 = x4[x18986];
      bool x18988 = x18987 != '|';
      bool x18993 = x18988;
      if (x18988) {
        long x18989 = x18384;
        char x18990 = x4[x18989];
        bool x18991 = x18990 != '\n';
        x18993 = x18991;
      }
      bool x18994 = x18993;
      if (!x18994) break;
      x18384 = x18384 + 1;
    }
    x18384 = x18384 + 1;
    for (;;) {
      long x19013 = x18384;
      char x19014 = x4[x19013];
      bool x19015 = x19014 != '|';
      bool x19020 = x19015;
      if (x19015) {
        long x19016 = x18384;
        char x19017 = x4[x19016];
        bool x19018 = x19017 != '\n';
        x19020 = x19018;
      }
      bool x19021 = x19020;
      if (!x19021) break;
      x18384 = x18384 + 1;
    }
    x18384 = x18384 + 1;
    for (;;) {
      long x19031 = x18384;
      char x19032 = x4[x19031];
      bool x19033 = x19032 != '|';
      bool x19038 = x19033;
      if (x19033) {
        long x19034 = x18384;
        char x19035 = x4[x19034];
        bool x19036 = x19035 != '\n';
        x19038 = x19036;
      }
      bool x19039 = x19038;
      if (!x19039) break;
      x18384 = x18384 + 1;
    }
    x18384 = x18384 + 1;
    for (;;) {
      long x19049 = x18384;
      char x19050 = x4[x19049];
      bool x19051 = x19050 != '|';
      bool x19056 = x19051;
      if (x19051) {
        long x19052 = x18384;
        char x19053 = x4[x19052];
        bool x19054 = x19053 != '\n';
        x19056 = x19054;
      }
      bool x19057 = x19056;
      if (!x19057) break;
      x18384 = x18384 + 1;
    }
    x18384 = x18384 + 1;
    long x19067 = x18386;
    long x19068 = x18385;
    bool x19069 = x19067 == x19068;
    if (x19069) {
      long x19070 = x19068 * 4L;
      x18385 = x19070;
      printf("buffer.resize %d\n",x19070);
      int* x19073 = x18388;
      int* x19074 = (int*)realloc(x19073,x19070 * sizeof(int));
      x18388 = x19074;
      double* x19088 = x18398;
      double* x19089 = (double*)realloc(x19088,x19070 * sizeof(double));
      x18398 = x19089;
      double* x19091 = x18400;
      double* x19092 = (double*)realloc(x19091,x19070 * sizeof(double));
      x18400 = x19092;
      char* x19097 = x18404;
      char* x19098 = (char*)realloc(x19097,x19070 * sizeof(char));
      x18404 = x19098;
    } else {
    }
    int* x19123 = x18388;
    x19123[x19067] = x18445;
    double* x19133 = x18398;
    double x18644 = (double)x18643;
    double x18646 = (double)x18645;
    double x18647 = x18644 / x18646;
    x19133[x19067] = x18647;
    double* x19135 = x18400;
    double x18709 = (double)x18708;
    double x18711 = (double)x18710;
    double x18712 = x18709 / x18711;
    x19135[x19067] = x18712;
    char* x19139 = x18404;
    char x18779 = x4[x18778];
    x19139[x19067] = x18779;
    x18386 = x18386 + 1;
  }
  long x19158 = 0L;
  long x19159 = x6;
  long x19160 = 0L;
  int* x19161 = (int*)malloc(x6 * sizeof(int));
  int* x19162 = x19161;
  char** x19163 = (char**)malloc(x6 * sizeof(char*));
  char** x19164 = x19163;
  int x1515 = open("../databases/sf2/nation.tbl",0);
  long x1516 = fsize(x1515);
  char* x1517 = mmap(0, x1516, PROT_READ, MAP_FILE | MAP_SHARED, x1515, 0);
  for (;;) {
    long x19169 = x19158;
    bool x19170 = x19169 < x1516;
    if (!x19170) break;
    int x19173 = 0;
    for (;;) {
      long x19174 = x19158;
      char x19175 = x1517[x19174];
      bool x19176 = x19175 != '|';
      bool x19181 = x19176;
      if (x19176) {
        long x19177 = x19158;
        char x19178 = x1517[x19177];
        bool x19179 = x19178 != '\n';
        x19181 = x19179;
      }
      bool x19182 = x19181;
      if (!x19182) break;
      int x19184 = x19173;
      long x19186 = x19158;
      int x19185 = x19184 * 10;
      char x19187 = x1517[x19186];
      char x19188 = x19187 - '0';
      int x19189 = x19185 + x19188;
      x19173 = x19189;
      x19158 = x19158 + 1;
    }
    x19158 = x19158 + 1;
    int x19195 = x19173;
    long x19196 = x19158;
    for (;;) {
      long x19197 = x19158;
      char x19198 = x1517[x19197];
      bool x19199 = x19198 != '|';
      bool x19204 = x19199;
      if (x19199) {
        long x19200 = x19158;
        char x19201 = x1517[x19200];
        bool x19202 = x19201 != '\n';
        x19204 = x19202;
      }
      bool x19205 = x19204;
      if (!x19205) break;
      x19158 = x19158 + 1;
    }
    x19158 = x19158 + 1;
    for (;;) {
      long x19216 = x19158;
      char x19217 = x1517[x19216];
      bool x19218 = x19217 != '|';
      bool x19223 = x19218;
      if (x19218) {
        long x19219 = x19158;
        char x19220 = x1517[x19219];
        bool x19221 = x19220 != '\n';
        x19223 = x19221;
      }
      bool x19224 = x19223;
      if (!x19224) break;
      x19158 = x19158 + 1;
    }
    x19158 = x19158 + 1;
    for (;;) {
      long x19239 = x19158;
      char x19240 = x1517[x19239];
      bool x19241 = x19240 != '|';
      bool x19246 = x19241;
      if (x19241) {
        long x19242 = x19158;
        char x19243 = x1517[x19242];
        bool x19244 = x19243 != '\n';
        x19246 = x19244;
      }
      bool x19247 = x19246;
      if (!x19247) break;
      x19158 = x19158 + 1;
    }
    x19158 = x19158 + 1;
    long x19257 = x19160;
    long x19258 = x19159;
    bool x19259 = x19257 == x19258;
    if (x19259) {
      long x19260 = x19258 * 4L;
      x19159 = x19260;
      printf("buffer.resize %d\n",x19260);
      int* x19263 = x19162;
      int* x19264 = (int*)realloc(x19263,x19260 * sizeof(int));
      x19162 = x19264;
      char** x19266 = x19164;
      char** x19267 = (char**)realloc(x19266,x19260 * sizeof(char*));
      x19164 = x19267;
    } else {
    }
    int* x19277 = x19162;
    x19277[x19257] = x19195;
    char** x19279 = x19164;
    char* x19213 = x1517+x19196;
    x19279[x19257] = x19213;
    x19160 = x19160 + 1;
  }
  long x19288 = 0L;
  long x19289 = x6;
  long x19290 = 0L;
  int* x19291 = (int*)malloc(x6 * sizeof(int));
  int* x19292 = x19291;
  char** x19293 = (char**)malloc(x6 * sizeof(char*));
  char** x19294 = x19293;
  char** x19295 = (char**)malloc(x6 * sizeof(char*));
  char** x19296 = x19295;
  int* x19297 = (int*)malloc(x6 * sizeof(int));
  int* x19298 = x19297;
  char** x19299 = (char**)malloc(x6 * sizeof(char*));
  char** x19300 = x19299;
  double* x19301 = (double*)malloc(x6 * sizeof(double));
  double* x19302 = x19301;
  char** x19305 = (char**)malloc(x6 * sizeof(char*));
  char** x19306 = x19305;
  int x3725 = open("../databases/sf2/customer.tbl",0);
  long x3726 = fsize(x3725);
  char* x3727 = mmap(0, x3726, PROT_READ, MAP_FILE | MAP_SHARED, x3725, 0);
  for (;;) {
    long x19307 = x19288;
    bool x19308 = x19307 < x3726;
    if (!x19308) break;
    int x19311 = 0;
    for (;;) {
      long x19312 = x19288;
      char x19313 = x3727[x19312];
      bool x19314 = x19313 != '|';
      bool x19319 = x19314;
      if (x19314) {
        long x19315 = x19288;
        char x19316 = x3727[x19315];
        bool x19317 = x19316 != '\n';
        x19319 = x19317;
      }
      bool x19320 = x19319;
      if (!x19320) break;
      int x19322 = x19311;
      long x19324 = x19288;
      int x19323 = x19322 * 10;
      char x19325 = x3727[x19324];
      char x19326 = x19325 - '0';
      int x19327 = x19323 + x19326;
      x19311 = x19327;
      x19288 = x19288 + 1;
    }
    x19288 = x19288 + 1;
    int x19333 = x19311;
    long x19334 = x19288;
    for (;;) {
      long x19335 = x19288;
      char x19336 = x3727[x19335];
      bool x19337 = x19336 != '|';
      bool x19342 = x19337;
      if (x19337) {
        long x19338 = x19288;
        char x19339 = x3727[x19338];
        bool x19340 = x19339 != '\n';
        x19342 = x19340;
      }
      bool x19343 = x19342;
      if (!x19343) break;
      x19288 = x19288 + 1;
    }
    x19288 = x19288 + 1;
    long x19352 = x19288;
    for (;;) {
      long x19353 = x19288;
      char x19354 = x3727[x19353];
      bool x19355 = x19354 != '|';
      bool x19360 = x19355;
      if (x19355) {
        long x19356 = x19288;
        char x19357 = x3727[x19356];
        bool x19358 = x19357 != '\n';
        x19360 = x19358;
      }
      bool x19361 = x19360;
      if (!x19361) break;
      x19288 = x19288 + 1;
    }
    x19288 = x19288 + 1;
    int x19371 = 0;
    for (;;) {
      long x19372 = x19288;
      char x19373 = x3727[x19372];
      bool x19374 = x19373 != '|';
      bool x19379 = x19374;
      if (x19374) {
        long x19375 = x19288;
        char x19376 = x3727[x19375];
        bool x19377 = x19376 != '\n';
        x19379 = x19377;
      }
      bool x19380 = x19379;
      if (!x19380) break;
      int x19382 = x19371;
      long x19384 = x19288;
      int x19383 = x19382 * 10;
      char x19385 = x3727[x19384];
      char x19386 = x19385 - '0';
      int x19387 = x19383 + x19386;
      x19371 = x19387;
      x19288 = x19288 + 1;
    }
    x19288 = x19288 + 1;
    int x19393 = x19371;
    long x19394 = x19288;
    for (;;) {
      long x19395 = x19288;
      char x19396 = x3727[x19395];
      bool x19397 = x19396 != '|';
      bool x19402 = x19397;
      if (x19397) {
        long x19398 = x19288;
        char x19399 = x3727[x19398];
        bool x19400 = x19399 != '\n';
        x19402 = x19400;
      }
      bool x19403 = x19402;
      if (!x19403) break;
      x19288 = x19288 + 1;
    }
    x19288 = x19288 + 1;
    int x19413 = 0;
    int x19414 = 1;
    for (;;) {
      long x19415 = x19288;
      char x19416 = x3727[x19415];
      bool x19417 = x19416 != '.';
      bool x19422 = x19417;
      if (x19417) {
        long x19418 = x19288;
        char x19419 = x3727[x19418];
        bool x19420 = x19419 != '|';
        x19422 = x19420;
      }
      bool x19423 = x19422;
      bool x19428 = x19423;
      if (x19423) {
        long x19424 = x19288;
        char x19425 = x3727[x19424];
        bool x19426 = x19425 != '\n';
        x19428 = x19426;
      }
      bool x19429 = x19428;
      if (!x19429) break;
      int x19431 = x19413;
      long x19433 = x19288;
      int x19432 = x19431 * 10;
      char x19434 = x3727[x19433];
      char x19435 = x19434 - '0';
      int x19436 = x19432 + x19435;
      x19413 = x19436;
      x19288 = x19288 + 1;
    }
    long x19441 = x19288;
    char x19442 = x3727[x19441];
    bool x19443 = x19442 == '.';
    if (x19443) {
      x19288 = x19288 + 1;
      for (;;) {
        long x19445 = x19288;
        char x19446 = x3727[x19445];
        bool x19447 = x19446 != '|';
        bool x19452 = x19447;
        if (x19447) {
          long x19448 = x19288;
          char x19449 = x3727[x19448];
          bool x19450 = x19449 != '\n';
          x19452 = x19450;
        }
        bool x19453 = x19452;
        if (!x19453) break;
        int x19455 = x19413;
        long x19457 = x19288;
        int x19456 = x19455 * 10;
        char x19458 = x3727[x19457];
        char x19459 = x19458 - '0';
        int x19460 = x19456 + x19459;
        x19413 = x19460;
        int x19462 = x19414;
        int x19463 = x19462 * 10;
        x19414 = x19463;
        x19288 = x19288 + 1;
      }
    } else {
    }
    x19288 = x19288 + 1;
    int x19472 = x19413;
    int x19474 = x19414;
    for (;;) {
      long x19478 = x19288;
      char x19479 = x3727[x19478];
      bool x19480 = x19479 != '|';
      bool x19485 = x19480;
      if (x19480) {
        long x19481 = x19288;
        char x19482 = x3727[x19481];
        bool x19483 = x19482 != '\n';
        x19485 = x19483;
      }
      bool x19486 = x19485;
      if (!x19486) break;
      x19288 = x19288 + 1;
    }
    x19288 = x19288 + 1;
    long x19495 = x19288;
    for (;;) {
      long x19496 = x19288;
      char x19497 = x3727[x19496];
      bool x19498 = x19497 != '|';
      bool x19503 = x19498;
      if (x19498) {
        long x19499 = x19288;
        char x19500 = x3727[x19499];
        bool x19501 = x19500 != '\n';
        x19503 = x19501;
      }
      bool x19504 = x19503;
      if (!x19504) break;
      x19288 = x19288 + 1;
    }
    x19288 = x19288 + 1;
    long x19514 = x19290;
    long x19515 = x19289;
    bool x19516 = x19514 == x19515;
    if (x19516) {
      long x19517 = x19515 * 4L;
      x19289 = x19517;
      printf("buffer.resize %d\n",x19517);
      int* x19520 = x19292;
      int* x19521 = (int*)realloc(x19520,x19517 * sizeof(int));
      x19292 = x19521;
      char** x19523 = x19294;
      char** x19524 = (char**)realloc(x19523,x19517 * sizeof(char*));
      x19294 = x19524;
      char** x19526 = x19296;
      char** x19527 = (char**)realloc(x19526,x19517 * sizeof(char*));
      x19296 = x19527;
      int* x19529 = x19298;
      int* x19530 = (int*)realloc(x19529,x19517 * sizeof(int));
      x19298 = x19530;
      char** x19532 = x19300;
      char** x19533 = (char**)realloc(x19532,x19517 * sizeof(char*));
      x19300 = x19533;
      double* x19535 = x19302;
      double* x19536 = (double*)realloc(x19535,x19517 * sizeof(double));
      x19302 = x19536;
      char** x19541 = x19306;
      char** x19542 = (char**)realloc(x19541,x19517 * sizeof(char*));
      x19306 = x19542;
    } else {
    }
    int* x19546 = x19292;
    x19546[x19514] = x19333;
    char** x19548 = x19294;
    char* x19351 = x3727+x19334;
    x19548[x19514] = x19351;
    char** x19550 = x19296;
    char* x19369 = x3727+x19352;
    x19550[x19514] = x19369;
    int* x19552 = x19298;
    x19552[x19514] = x19393;
    char** x19554 = x19300;
    char* x19411 = x3727+x19394;
    x19554[x19514] = x19411;
    double* x19556 = x19302;
    double x19473 = (double)x19472;
    double x19475 = (double)x19474;
    double x19476 = x19473 / x19475;
    x19556[x19514] = x19476;
    char** x19560 = x19306;
    char* x19512 = x3727+x19495;
    x19560[x19514] = x19512;
    x19290 = x19290 + 1;
  }
  long x19565 = 0L;
  long x19566 = x6;
  long x19567 = 0L;
  int* x19568 = (int*)malloc(x6 * sizeof(int));
  int* x19569 = x19568;
  int* x19570 = (int*)malloc(x6 * sizeof(int));
  int* x19571 = x19570;
  long* x19576 = (long*)malloc(x6 * sizeof(long));
  long* x19577 = x19576;
  int x3371 = open("../databases/sf2/orders.tbl",0);
  long x3372 = fsize(x3371);
  char* x3373 = mmap(0, x3372, PROT_READ, MAP_FILE | MAP_SHARED, x3371, 0);
  for (;;) {
    long x19586 = x19565;
    bool x19587 = x19586 < x3372;
    if (!x19587) break;
    int x19590 = 0;
    for (;;) {
      long x19591 = x19565;
      char x19592 = x3373[x19591];
      bool x19593 = x19592 != '|';
      bool x19598 = x19593;
      if (x19593) {
        long x19594 = x19565;
        char x19595 = x3373[x19594];
        bool x19596 = x19595 != '\n';
        x19598 = x19596;
      }
      bool x19599 = x19598;
      if (!x19599) break;
      int x19601 = x19590;
      long x19603 = x19565;
      int x19602 = x19601 * 10;
      char x19604 = x3373[x19603];
      char x19605 = x19604 - '0';
      int x19606 = x19602 + x19605;
      x19590 = x19606;
      x19565 = x19565 + 1;
    }
    x19565 = x19565 + 1;
    int x19612 = x19590;
    int x19614 = 0;
    for (;;) {
      long x19615 = x19565;
      char x19616 = x3373[x19615];
      bool x19617 = x19616 != '|';
      bool x19622 = x19617;
      if (x19617) {
        long x19618 = x19565;
        char x19619 = x3373[x19618];
        bool x19620 = x19619 != '\n';
        x19622 = x19620;
      }
      bool x19623 = x19622;
      if (!x19623) break;
      int x19625 = x19614;
      long x19627 = x19565;
      int x19626 = x19625 * 10;
      char x19628 = x3373[x19627];
      char x19629 = x19628 - '0';
      int x19630 = x19626 + x19629;
      x19614 = x19630;
      x19565 = x19565 + 1;
    }
    x19565 = x19565 + 1;
    int x19636 = x19614;
    x19565 = x19565 + 2;
    for (;;) {
      long x19643 = x19565;
      char x19644 = x3373[x19643];
      bool x19645 = x19644 != '.';
      bool x19650 = x19645;
      if (x19645) {
        long x19646 = x19565;
        char x19647 = x3373[x19646];
        bool x19648 = x19647 != '|';
        x19650 = x19648;
      }
      bool x19651 = x19650;
      bool x19656 = x19651;
      if (x19651) {
        long x19652 = x19565;
        char x19653 = x3373[x19652];
        bool x19654 = x19653 != '\n';
        x19656 = x19654;
      }
      bool x19657 = x19656;
      if (!x19657) break;
      x19565 = x19565 + 1;
    }
    long x19669 = x19565;
    char x19670 = x3373[x19669];
    bool x19671 = x19670 == '.';
    if (x19671) {
      x19565 = x19565 + 1;
      for (;;) {
        long x19673 = x19565;
        char x19674 = x3373[x19673];
        bool x19675 = x19674 != '|';
        bool x19680 = x19675;
        if (x19675) {
          long x19676 = x19565;
          char x19677 = x3373[x19676];
          bool x19678 = x19677 != '\n';
          x19680 = x19678;
        }
        bool x19681 = x19680;
        if (!x19681) break;
        x19565 = x19565 + 1;
      }
    } else {
    }
    x19565 = x19565 + 1;
    int x19706 = 0;
    for (;;) {
      long x19707 = x19565;
      char x19708 = x3373[x19707];
      bool x19709 = x19708 != '-';
      bool x19714 = x19709;
      if (x19709) {
        long x19710 = x19565;
        char x19711 = x3373[x19710];
        bool x19712 = x19711 != '\n';
        x19714 = x19712;
      }
      bool x19715 = x19714;
      if (!x19715) break;
      int x19717 = x19706;
      long x19719 = x19565;
      int x19718 = x19717 * 10;
      char x19720 = x3373[x19719];
      char x19721 = x19720 - '0';
      int x19722 = x19718 + x19721;
      x19706 = x19722;
      x19565 = x19565 + 1;
    }
    x19565 = x19565 + 1;
    int x19728 = x19706;
    int x19730 = 0;
    for (;;) {
      long x19731 = x19565;
      char x19732 = x3373[x19731];
      bool x19733 = x19732 != '-';
      bool x19738 = x19733;
      if (x19733) {
        long x19734 = x19565;
        char x19735 = x3373[x19734];
        bool x19736 = x19735 != '\n';
        x19738 = x19736;
      }
      bool x19739 = x19738;
      if (!x19739) break;
      int x19741 = x19730;
      long x19743 = x19565;
      int x19742 = x19741 * 10;
      char x19744 = x3373[x19743];
      char x19745 = x19744 - '0';
      int x19746 = x19742 + x19745;
      x19730 = x19746;
      x19565 = x19565 + 1;
    }
    x19565 = x19565 + 1;
    int x19752 = x19730;
    int x19754 = 0;
    for (;;) {
      long x19755 = x19565;
      char x19756 = x3373[x19755];
      bool x19757 = x19756 != '|';
      bool x19762 = x19757;
      if (x19757) {
        long x19758 = x19565;
        char x19759 = x3373[x19758];
        bool x19760 = x19759 != '\n';
        x19762 = x19760;
      }
      bool x19763 = x19762;
      if (!x19763) break;
      int x19765 = x19754;
      long x19767 = x19565;
      int x19766 = x19765 * 10;
      char x19768 = x3373[x19767];
      char x19769 = x19768 - '0';
      int x19770 = x19766 + x19769;
      x19754 = x19770;
      x19565 = x19565 + 1;
    }
    x19565 = x19565 + 1;
    int x19776 = x19754;
    for (;;) {
      long x19782 = x19565;
      char x19783 = x3373[x19782];
      bool x19784 = x19783 != '|';
      bool x19789 = x19784;
      if (x19784) {
        long x19785 = x19565;
        char x19786 = x3373[x19785];
        bool x19787 = x19786 != '\n';
        x19789 = x19787;
      }
      bool x19790 = x19789;
      if (!x19790) break;
      x19565 = x19565 + 1;
    }
    x19565 = x19565 + 1;
    for (;;) {
      long x19800 = x19565;
      char x19801 = x3373[x19800];
      bool x19802 = x19801 != '|';
      bool x19807 = x19802;
      if (x19802) {
        long x19803 = x19565;
        char x19804 = x3373[x19803];
        bool x19805 = x19804 != '\n';
        x19807 = x19805;
      }
      bool x19808 = x19807;
      if (!x19808) break;
      x19565 = x19565 + 1;
    }
    x19565 = x19565 + 1;
    for (;;) {
      long x19819 = x19565;
      char x19820 = x3373[x19819];
      bool x19821 = x19820 != '|';
      bool x19826 = x19821;
      if (x19821) {
        long x19822 = x19565;
        char x19823 = x3373[x19822];
        bool x19824 = x19823 != '\n';
        x19826 = x19824;
      }
      bool x19827 = x19826;
      if (!x19827) break;
      x19565 = x19565 + 1;
    }
    x19565 = x19565 + 1;
    for (;;) {
      long x19842 = x19565;
      char x19843 = x3373[x19842];
      bool x19844 = x19843 != '|';
      bool x19849 = x19844;
      if (x19844) {
        long x19845 = x19565;
        char x19846 = x3373[x19845];
        bool x19847 = x19846 != '\n';
        x19849 = x19847;
      }
      bool x19850 = x19849;
      if (!x19850) break;
      x19565 = x19565 + 1;
    }
    x19565 = x19565 + 1;
    long x19860 = x19567;
    long x19861 = x19566;
    bool x19862 = x19860 == x19861;
    if (x19862) {
      long x19863 = x19861 * 4L;
      x19566 = x19863;
      printf("buffer.resize %d\n",x19863);
      int* x19866 = x19569;
      int* x19867 = (int*)realloc(x19866,x19863 * sizeof(int));
      x19569 = x19867;
      int* x19869 = x19571;
      int* x19870 = (int*)realloc(x19869,x19863 * sizeof(int));
      x19571 = x19870;
      long* x19878 = x19577;
      long* x19879 = (long*)realloc(x19878,x19863 * sizeof(long));
      x19577 = x19879;
    } else {
    }
    int* x19895 = x19569;
    x19895[x19860] = x19612;
    int* x19897 = x19571;
    x19897[x19860] = x19636;
    long* x19903 = x19577;
    long x19777 = x19728 * 10000L;
    long x19778 = x19752 * 100L;
    long x19779 = x19777 + x19778;
    long x19780 = x19779 + x19776;
    x19903[x19860] = x19780;
    x19567 = x19567 + 1;
  }
  long x2011 = DEFAULT_JOIN_HASH_SIZE;
  long x787 = DEFAULT_AGG_HASH_SIZE ;
  long x2034 = x2011 - 1L;
  long x802 = x787 - 1L;
  int x19916;
  for(x19916=0; x19916 < 5; x19916++) {
    bool x19917 = false;
    long x19918 = 0L;
    bool x19920 = false;
    long x19921 = 0L;
    int* x19923 = (int*)malloc(x2011 * sizeof(int));
    int* x19924 = x19923;
    int* x19925 = (int*)malloc(x2011 * sizeof(int));
    int* x19926 = x19925;
    long x19941 = 0L;
    long* x19942 = (long*)malloc(x2011 * sizeof(long));
    long* x19943 = (long*)malloc(x2011 * sizeof(long));
    long x19944;
    for(x19944=0L; x19944 < x2011; x19944++) {
      x19942[x19944] = -1L;
    }
    bool x19949 = false;
    long x19950 = 0L;
    int* x19952 = (int*)malloc(x2011 * sizeof(int));
    int* x19953 = x19952;
    char** x19954 = (char**)malloc(x2011 * sizeof(char*));
    char** x19955 = x19954;
    long x19960 = 0L;
    long* x19961 = (long*)malloc(x2011 * sizeof(long));
    long* x19962 = (long*)malloc(x2011 * sizeof(long));
    long x19963;
    for(x19963=0L; x19963 < x2011; x19963++) {
      x19961[x19963] = -1L;
    }
    bool x19968 = false;
    long x19969 = 0L;
    char** x19974 = (char**)malloc(x2011 * sizeof(char*));
    char** x19975 = x19974;
    int* x19980 = (int*)malloc(x2011 * sizeof(int));
    int* x19981 = x19980;
    int* x19998 = (int*)malloc(x2011 * sizeof(int));
    int* x19999 = x19998;
    char** x20000 = (char**)malloc(x2011 * sizeof(char*));
    char** x20001 = x20000;
    char** x20002 = (char**)malloc(x2011 * sizeof(char*));
    char** x20003 = x20002;
    char** x20006 = (char**)malloc(x2011 * sizeof(char*));
    char** x20007 = x20006;
    double* x20008 = (double*)malloc(x2011 * sizeof(double));
    double* x20009 = x20008;
    char** x20012 = (char**)malloc(x2011 * sizeof(char*));
    char** x20013 = x20012;
    long x20014 = 0L;
    long* x20015 = (long*)malloc(x2011 * sizeof(long));
    long* x20016 = (long*)malloc(x2011 * sizeof(long));
    long x20017;
    for(x20017=0L; x20017 < x2011; x20017++) {
      x20015[x20017] = -1L;
    }
    struct Anon2041993102* x20023 = (struct Anon2041993102*)malloc(x787 * sizeof(struct Anon2041993102));
    struct Anon2041993102* x20024 = x20023;
    long x20025 = 0L;
    long* x20026 = (long*)malloc(x787 * sizeof(long));
    long x20027;
    for(x20027=0L; x20027 < x787; x20027++) {
      struct Anon2041993102* x20028 = x20024;
      struct Anon2041993102 x20029 = x20028[x20027];
      struct Anon1711779607 x20030 = x20029.key;;
      struct Anon2052879266 x20031 = x20029.aggs;;
      struct Anon2041993102 x20032;
      x20032.exists = false;
      x20032.key = x20030;
      x20032.aggs = x20031;
      x20028[x20027] = x20032;
    }
    int x20036 = 0;
    long x20038 = 0L;
    struct timeval x20603, x20604, x20605;
    gettimeofday(&x20603, NULL);
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x20040 = x19949;
      bool x20041 = !x20040;
      bool x20046 = x20041;
      if (x20041) {
        long x20042 = x19950;
        long x20043 = x19160;
        bool x20044 = x20042 < x20043;
        x20046 = x20044;
      }
      bool x20047 = x20046;
      if (!x20047) break;
      long x20049 = x19950;
      int* x20050 = x19162;
      int x20051 = x20050[x20049];
      char** x20052 = x19164;
      char* x20053 = x20052[x20049];
      x19950 = x19950 + 1;
      long x20060 = x19960;
      int* x20061 = x19953;
      x20061[x20060] = x20051;
      char** x20063 = x19955;
      x20063[x20060] = x20053;
      x19960 = x19960 + 1L;
      long x20070 = x20051 & x2034;
      long x20071 = x19961[x20070];
      x19961[x20070] = x20060;
      x19962[x20060] = x20071;
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x20077 = x19917;
      bool x20078 = !x20077;
      bool x20083 = x20078;
      if (x20078) {
        long x20079 = x19918;
        long x20080 = x19567;
        bool x20081 = x20079 < x20080;
        x20083 = x20081;
      }
      bool x20084 = x20083;
      if (!x20084) break;
      long x20086 = x19918;
      int* x20087 = x19569;
      int x20088 = x20087[x20086];
      int* x20089 = x19571;
      int x20090 = x20089[x20086];
      long* x20095 = x19577;
      long x20096 = x20095[x20086];
      x19918 = x19918 + 1;
      bool x20107 = x20096 >= 19941101L;
      bool x20109 = x20107;
      if (x20107) {
        bool x20108 = x20096 < 19950201L;
        x20109 = x20108;
      }
      bool x20110 = x20109;
      if (x20110) {
        long x20111 = x19941;
        int* x20112 = x19924;
        x20112[x20111] = x20088;
        int* x20114 = x19926;
        x20114[x20111] = x20090;
        x19941 = x19941 + 1L;
        long x20131 = x20090 & x2034;
        long x20132 = x19942[x20131];
        x19942[x20131] = x20111;
        x19943[x20111] = x20132;
      } else {
      }
    }
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x20140 = x19920;
      bool x20141 = !x20140;
      bool x20146 = x20141;
      if (x20141) {
        long x20142 = x19921;
        long x20143 = x19290;
        bool x20144 = x20142 < x20143;
        x20146 = x20144;
      }
      bool x20147 = x20146;
      if (!x20147) break;
      long x20149 = x19921;
      int* x20150 = x19292;
      int x20151 = x20150[x20149];
      char** x20152 = x19294;
      char* x20153 = x20152[x20149];
      char** x20154 = x19296;
      char* x20155 = x20154[x20149];
      int* x20156 = x19298;
      int x20157 = x20156[x20149];
      char** x20158 = x19300;
      char* x20159 = x20158[x20149];
      double* x20160 = x19302;
      double x20161 = x20160[x20149];
      char** x20164 = x19306;
      char* x20165 = x20164[x20149];
      x19921 = x19921 + 1;
      long x20168 = x20151 & x2034;
      long x20169 = x19942[x20168];
      long x20170 = x20169;
      long x20200 = x20157 & x2034;
      for (;;) {
        long x20171 = x20170;
        bool x20172 = x20171 != -1;
        if (!x20172) break;
        long x20174 = x20170;
        int* x20175 = x19924;
        int x20176 = x20175[x20174];
        int* x20177 = x19926;
        int x20178 = x20177[x20174];
        long x20194 = x19943[x20174];
        x20170 = x20194;
        bool x20196 = x20178 == x20151;
        if (x20196) {
          long x20201 = x19961[x20200];
          long x20202 = x20201;
          long x20266 = x20176 & x2034;
          for (;;) {
            long x20203 = x20202;
            bool x20204 = x20203 != -1;
            if (!x20204) break;
            long x20206 = x20202;
            int* x20207 = x19953;
            int x20208 = x20207[x20206];
            char** x20209 = x19955;
            char* x20210 = x20209[x20206];
            long x20216 = x19962[x20206];
            x20202 = x20216;
            bool x20218 = x20208 == x20157;
            if (x20218) {
              long x20222 = x20014;
              char** x20225 = x19975;
              x20225[x20222] = x20210;
              int* x20231 = x19981;
              x20231[x20222] = x20176;
              int* x20249 = x19999;
              x20249[x20222] = x20151;
              char** x20251 = x20001;
              x20251[x20222] = x20153;
              char** x20253 = x20003;
              x20253[x20222] = x20155;
              char** x20257 = x20007;
              x20257[x20222] = x20159;
              double* x20259 = x20009;
              x20259[x20222] = x20161;
              char** x20263 = x20013;
              x20263[x20222] = x20165;
              x20014 = x20014 + 1L;
              long x20267 = x20015[x20266];
              x20015[x20266] = x20222;
              x20016[x20222] = x20267;
            } else {
            }
          }
        } else {
        }
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x20281 = x19968;
      bool x20282 = !x20281;
      bool x20287 = x20282;
      if (x20282) {
        long x20283 = x19969;
        long x20284 = x18386;
        bool x20285 = x20283 < x20284;
        x20287 = x20285;
      }
      bool x20288 = x20287;
      if (!x20288) break;
      long x20290 = x19969;
      int* x20291 = x18388;
      int x20292 = x20291[x20290];
      double* x20301 = x18398;
      double x20302 = x20301[x20290];
      double* x20303 = x18400;
      double x20304 = x20303[x20290];
      char* x20307 = x18404;
      char x20308 = x20307[x20290];
      x19969 = x19969 + 1;
      bool x20325 = x20308 == 'R';
      if (x20325) {
        long x20326 = x20292 & x2034;
        long x20327 = x20015[x20326];
        long x20328 = x20327;
        double x20483 = 1.0 - x20304;
        double x20484 = x20302 * x20483;
        struct Anon2052879266 x20542;
        x20542._0 = x20484;
        for (;;) {
          long x20329 = x20328;
          bool x20330 = x20329 != -1;
          if (!x20330) break;
          long x20332 = x20328;
          char** x20335 = x19975;
          char* x20336 = x20335[x20332];
          int* x20341 = x19981;
          int x20342 = x20341[x20332];
          int* x20359 = x19999;
          int x20360 = x20359[x20332];
          char** x20361 = x20001;
          char* x20362 = x20361[x20332];
          char** x20363 = x20003;
          char* x20364 = x20363[x20332];
          char** x20367 = x20007;
          char* x20368 = x20367[x20332];
          double* x20369 = x20009;
          double x20370 = x20369[x20332];
          char** x20373 = x20013;
          char* x20374 = x20373[x20332];
          long x20376 = x20016[x20332];
          x20328 = x20376;
          bool x20378 = x20342 == x20292;
          if (x20378) {
            char x20423 = x20336[0L];
            long x20424 = x20423 * 41L;
            char x20425 = x20336[1L];
            long x20426 = x20424 + x20425;
            long x20427 = x20426 * 41L;
            char x20428 = x20336[2L];
            long x20429 = x20427 + x20428;
            long x20430 = x20429 * 41L;
            char x20431 = x20336[3L];
            long x20432 = x20430 + x20431;
            char x20413 = x20368[0L];
            long x20414 = x20413 * 41L;
            char x20415 = x20368[1L];
            long x20416 = x20414 + x20415;
            long x20417 = x20416 * 41L;
            char x20418 = x20368[2L];
            long x20419 = x20417 + x20418;
            long x20420 = x20419 * 41L;
            char x20421 = x20368[3L];
            long x20422 = x20420 + x20421;
            char x20403 = x20362[0L];
            long x20404 = x20403 * 41L;
            char x20405 = x20362[1L];
            long x20406 = x20404 + x20405;
            long x20407 = x20406 * 41L;
            char x20408 = x20362[2L];
            long x20409 = x20407 + x20408;
            long x20410 = x20409 * 41L;
            char x20411 = x20362[3L];
            long x20412 = x20410 + x20411;
            char x20393 = x20374[0L];
            long x20394 = x20393 * 41L;
            char x20395 = x20374[1L];
            long x20396 = x20394 + x20395;
            long x20397 = x20396 * 41L;
            char x20398 = x20374[2L];
            long x20399 = x20397 + x20398;
            long x20400 = x20399 * 41L;
            char x20401 = x20374[3L];
            long x20402 = x20400 + x20401;
            char x20383 = x20364[0L];
            long x20384 = x20383 * 41L;
            char x20385 = x20364[1L];
            long x20386 = x20384 + x20385;
            long x20387 = x20386 * 41L;
            char x20388 = x20364[2L];
            long x20389 = x20387 + x20388;
            long x20390 = x20389 * 41L;
            char x20391 = x20364[3L];
            long x20392 = x20390 + x20391;
            long x20433 = 31857L + x20392;
            long x20434 = x20433 * 41L;
            long x20435 = x20434 + x20402;
            long x20436 = x20435 * 41L;
            long x20437 = x20436 + x20360;
            long x20438 = x20437 * 41L;
            long x20439 = x20438 + x20412;
            long x20440 = x20439 * 41L;
            long x20441 = x20440 + x20422;
            long x20442 = x20441 * 41L;
            long x20443 = x20442 + x20432;
            long x20444 = x20443 & x802;
            long x20445 = x20444;
            struct Anon2041993102* x20446 = x20024;
            struct Anon2041993102 x20447 = x20446[x20444];
            struct Anon2041993102 x20448 = x20447;
            bool x20449 = x20447.exists;;
            bool x20479 = x20449;
            if (x20449) {
              struct Anon2041993102 x20450 = x20448;
              struct Anon1711779607 x20451 = x20450.key;;
              int x20452 = x20451.C_CUSTKEY;;
              bool x20453 = x20452 == x20360;
              bool x20466 = x20453;
              if (x20453) {
                char* x20454 = x20451.C_NAME;;
                bool x20455 = strcmp(x20454,x20362) == 0;;
                x20466 = x20455;
              }
              bool x20467 = x20466;
              bool x20468 = x20467;
              if (x20467) {
                double x20456 = x20451.C_ACCTBAL;;
                bool x20457 = x20456 == x20370;
                x20468 = x20457;
              }
              bool x20469 = x20468;
              bool x20470 = x20469;
              if (x20469) {
                char* x20458 = x20451.C_PHONE;;
                bool x20459 = strcmp(x20458,x20368) == 0;;
                x20470 = x20459;
              }
              bool x20471 = x20470;
              bool x20472 = x20471;
              if (x20471) {
                char* x20460 = x20451.N_NAME;;
                bool x20461 = strcmp(x20460,x20336) == 0;;
                x20472 = x20461;
              }
              bool x20473 = x20472;
              bool x20474 = x20473;
              if (x20473) {
                char* x20462 = x20451.C_ADDRESS;;
                bool x20463 = strcmp(x20462,x20364) == 0;;
                x20474 = x20463;
              }
              bool x20475 = x20474;
              bool x20476 = x20475;
              if (x20475) {
                char* x20464 = x20451.C_COMMENT;;
                bool x20465 = strcmp(x20464,x20374) == 0;;
                x20476 = x20465;
              }
              bool x20477 = x20476;
              x20479 = x20477;
            }
            bool x20480 = x20479;
            if (x20480) {
              struct Anon2052879266 x20481 = x20447.aggs;;
              struct Anon1711779607 x20487 = x20447.key;;
              double x20482 = x20481._0;;
              double x20485 = x20482 + x20484;
              struct Anon2052879266 x20486;
              x20486._0 = x20485;
              struct Anon2041993102 x20488;
              x20488.exists = true;
              x20488.key = x20487;
              x20488.aggs = x20486;
              x20446[x20444] = x20488;
            } else {
              struct Anon1711779607 x20382;
              x20382.C_CUSTKEY = x20360;
              x20382.C_NAME = x20362;
              x20382.C_ACCTBAL = x20370;
              x20382.C_PHONE = x20368;
              x20382.N_NAME = x20336;
              x20382.C_ADDRESS = x20364;
              x20382.C_COMMENT = x20374;
              struct Anon2041993102 x20543;
              x20543.exists = true;
              x20543.key = x20382;
              x20543.aggs = x20542;
              for (;;) {
                struct Anon2041993102 x20491 = x20448;
                bool x20492 = x20491.exists;;
                bool x20552;
                if (x20492) {
                  struct Anon1711779607 x20493 = x20491.key;;
                  int x20494 = x20493.C_CUSTKEY;;
                  bool x20495 = x20494 == x20360;
                  bool x20508 = x20495;
                  if (x20495) {
                    char* x20496 = x20493.C_NAME;;
                    bool x20497 = strcmp(x20496,x20362) == 0;;
                    x20508 = x20497;
                  }
                  bool x20509 = x20508;
                  bool x20510 = x20509;
                  if (x20509) {
                    double x20498 = x20493.C_ACCTBAL;;
                    bool x20499 = x20498 == x20370;
                    x20510 = x20499;
                  }
                  bool x20511 = x20510;
                  bool x20512 = x20511;
                  if (x20511) {
                    char* x20500 = x20493.C_PHONE;;
                    bool x20501 = strcmp(x20500,x20368) == 0;;
                    x20512 = x20501;
                  }
                  bool x20513 = x20512;
                  bool x20514 = x20513;
                  if (x20513) {
                    char* x20502 = x20493.N_NAME;;
                    bool x20503 = strcmp(x20502,x20336) == 0;;
                    x20514 = x20503;
                  }
                  bool x20515 = x20514;
                  bool x20516 = x20515;
                  if (x20515) {
                    char* x20504 = x20493.C_ADDRESS;;
                    bool x20505 = strcmp(x20504,x20364) == 0;;
                    x20516 = x20505;
                  }
                  bool x20517 = x20516;
                  bool x20518 = x20517;
                  if (x20517) {
                    char* x20506 = x20493.C_COMMENT;;
                    bool x20507 = strcmp(x20506,x20374) == 0;;
                    x20518 = x20507;
                  }
                  bool x20519 = x20518;
                  bool x20539;
                  if (x20519) {
                    struct Anon2052879266 x20520 = x20491.aggs;;
                    long x20524 = x20445;
                    struct Anon2041993102* x20526 = x20024;
                    double x20521 = x20520._0;;
                    double x20522 = x20521 + x20484;
                    struct Anon2052879266 x20523;
                    x20523._0 = x20522;
                    struct Anon2041993102 x20525;
                    x20525.exists = true;
                    x20525.key = x20493;
                    x20525.aggs = x20523;
                    x20526[x20524] = x20525;
                    x20539 = false;
                  } else {
                    long x20529 = x20445;
                    long x20530 = x20529 + 1L;
                    long x20531 = x20530 % x802;
                    x20445 = x20531;
                    struct Anon2041993102* x20533 = x20024;
                    struct Anon2041993102 x20534 = x20533[x20531];
                    x20448 = x20534;
                    x20539 = true;
                  }
                  x20552 = x20539;
                } else {
                  long x20541 = x20445;
                  struct Anon2041993102* x20544 = x20024;
                  x20544[x20541] = x20543;
                  long x20546 = x20025;
                  x20026[x20546] = x20541;
                  x20025 = x20025 + 1L;
                  x20552 = false;
                }
                if (!x20552) break;
              }
            }
          } else {
          }
        }
      } else {
      }
    }
    long x20567 = x20025;
    long x20569;
    for(x20569=0L; x20569 < x20567; x20569++) {
      long x20570 = x20026[x20569];
      struct Anon2041993102* x20571 = x20024;
      struct Anon2041993102 x20572 = x20571[x20570];
      int x20573 = x20036;
      bool x20574 = x20573 < 20;
      bool x20575 = x20574 == false;
      if (x20575) {
      } else {
        struct Anon1711779607 x20578 = x20572.key;;
        struct Anon2052879266 x20582 = x20572.aggs;;
        int x20579 = x20578.C_CUSTKEY;;
        char* x20580 = x20578.C_NAME;;
        int x20581 = strlen(x20580);
        double x20583 = x20582._0;;
        double x20584 = x20578.C_ACCTBAL;;
        char* x20585 = x20578.N_NAME;;
        int x20586 = strlen(x20585);
        char* x20587 = x20578.C_ADDRESS;;
        int x20588 = strlen(x20587);
        char* x20589 = x20578.C_PHONE;;
        int x20590 = strlen(x20589);
        char* x20591 = x20578.C_COMMENT;;
        int x20592 = strlen(x20591);
        printf("%d|%.*s|%.4f|%.2f|%.*s|%.*s|%.*s|%.*s\n",x20579,x20581,x20580,x20583,x20584,x20586,x20585,x20588,x20587,x20590,x20589,x20592,x20591);
        x20036 = x20036 + 1;
        x20038 = x20038 + 1L;
      }
    }
    long x20600 = x20038;
    printf("(%d rows)\n",x20600);
    gettimeofday(&x20604, NULL);
    timeval_subtract(&x20605, &x20604, &x20603);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x20605.tv_sec * 1000) + (x20605.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
