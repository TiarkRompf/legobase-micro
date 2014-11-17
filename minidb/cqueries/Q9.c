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
struct Anon1599206474 left;
struct Anon811555534 right;
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

struct Anon1268892766 {
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
};

struct Anon1074264013 {
bool exists;
int key;
struct Anon189208763 aggs;
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
int main(int x15429, char** x15430) {
  long x15431 = 0L;
  long x6 = DEFAULT_INPUT_SIZE;
  long x15432 = x6;
  long x15433 = 0L;
  int* x15434 = (int*)malloc(x6 * sizeof(int));
  int* x15435 = x15434;
  char** x15436 = (char**)malloc(x6 * sizeof(char*));
  char** x15437 = x15436;
  int x998 = open("../databases/sf2/part.tbl",0);
  long x999 = fsize(x998);
  char* x1000 = mmap(0, x999, PROT_READ, MAP_FILE | MAP_SHARED, x998, 0);
  for (;;) {
    long x15453 = x15431;
    bool x15454 = x15453 < x999;
    if (!x15454) break;
    int x15457 = 0;
    for (;;) {
      long x15458 = x15431;
      char x15459 = x1000[x15458];
      bool x15460 = x15459 != '|';
      bool x15465 = x15460;
      if (x15460) {
        long x15461 = x15431;
        char x15462 = x1000[x15461];
        bool x15463 = x15462 != '\n';
        x15465 = x15463;
      }
      bool x15466 = x15465;
      if (!x15466) break;
      int x15468 = x15457;
      long x15470 = x15431;
      int x15469 = x15468 * 10;
      char x15471 = x1000[x15470];
      char x15472 = x15471 - '0';
      int x15473 = x15469 + x15472;
      x15457 = x15473;
      x15431 = x15431 + 1;
    }
    x15431 = x15431 + 1;
    int x15479 = x15457;
    long x15480 = x15431;
    for (;;) {
      long x15481 = x15431;
      char x15482 = x1000[x15481];
      bool x15483 = x15482 != '|';
      bool x15488 = x15483;
      if (x15483) {
        long x15484 = x15431;
        char x15485 = x1000[x15484];
        bool x15486 = x15485 != '\n';
        x15488 = x15486;
      }
      bool x15489 = x15488;
      if (!x15489) break;
      x15431 = x15431 + 1;
    }
    x15431 = x15431 + 1;
    for (;;) {
      long x15499 = x15431;
      char x15500 = x1000[x15499];
      bool x15501 = x15500 != '|';
      bool x15506 = x15501;
      if (x15501) {
        long x15502 = x15431;
        char x15503 = x1000[x15502];
        bool x15504 = x15503 != '\n';
        x15506 = x15504;
      }
      bool x15507 = x15506;
      if (!x15507) break;
      x15431 = x15431 + 1;
    }
    x15431 = x15431 + 1;
    for (;;) {
      long x15517 = x15431;
      char x15518 = x1000[x15517];
      bool x15519 = x15518 != '|';
      bool x15524 = x15519;
      if (x15519) {
        long x15520 = x15431;
        char x15521 = x1000[x15520];
        bool x15522 = x15521 != '\n';
        x15524 = x15522;
      }
      bool x15525 = x15524;
      if (!x15525) break;
      x15431 = x15431 + 1;
    }
    x15431 = x15431 + 1;
    for (;;) {
      long x15535 = x15431;
      char x15536 = x1000[x15535];
      bool x15537 = x15536 != '|';
      bool x15542 = x15537;
      if (x15537) {
        long x15538 = x15431;
        char x15539 = x1000[x15538];
        bool x15540 = x15539 != '\n';
        x15542 = x15540;
      }
      bool x15543 = x15542;
      if (!x15543) break;
      x15431 = x15431 + 1;
    }
    x15431 = x15431 + 1;
    for (;;) {
      long x15554 = x15431;
      char x15555 = x1000[x15554];
      bool x15556 = x15555 != '|';
      bool x15561 = x15556;
      if (x15556) {
        long x15557 = x15431;
        char x15558 = x1000[x15557];
        bool x15559 = x15558 != '\n';
        x15561 = x15559;
      }
      bool x15562 = x15561;
      if (!x15562) break;
      x15431 = x15431 + 1;
    }
    x15431 = x15431 + 1;
    for (;;) {
      long x15577 = x15431;
      char x15578 = x1000[x15577];
      bool x15579 = x15578 != '|';
      bool x15584 = x15579;
      if (x15579) {
        long x15580 = x15431;
        char x15581 = x1000[x15580];
        bool x15582 = x15581 != '\n';
        x15584 = x15582;
      }
      bool x15585 = x15584;
      if (!x15585) break;
      x15431 = x15431 + 1;
    }
    x15431 = x15431 + 1;
    for (;;) {
      long x15597 = x15431;
      char x15598 = x1000[x15597];
      bool x15599 = x15598 != '.';
      bool x15604 = x15599;
      if (x15599) {
        long x15600 = x15431;
        char x15601 = x1000[x15600];
        bool x15602 = x15601 != '|';
        x15604 = x15602;
      }
      bool x15605 = x15604;
      bool x15610 = x15605;
      if (x15605) {
        long x15606 = x15431;
        char x15607 = x1000[x15606];
        bool x15608 = x15607 != '\n';
        x15610 = x15608;
      }
      bool x15611 = x15610;
      if (!x15611) break;
      x15431 = x15431 + 1;
    }
    long x15623 = x15431;
    char x15624 = x1000[x15623];
    bool x15625 = x15624 == '.';
    if (x15625) {
      x15431 = x15431 + 1;
      for (;;) {
        long x15627 = x15431;
        char x15628 = x1000[x15627];
        bool x15629 = x15628 != '|';
        bool x15634 = x15629;
        if (x15629) {
          long x15630 = x15431;
          char x15631 = x1000[x15630];
          bool x15632 = x15631 != '\n';
          x15634 = x15632;
        }
        bool x15635 = x15634;
        if (!x15635) break;
        x15431 = x15431 + 1;
      }
    } else {
    }
    x15431 = x15431 + 1;
    for (;;) {
      long x15660 = x15431;
      char x15661 = x1000[x15660];
      bool x15662 = x15661 != '|';
      bool x15667 = x15662;
      if (x15662) {
        long x15663 = x15431;
        char x15664 = x1000[x15663];
        bool x15665 = x15664 != '\n';
        x15667 = x15665;
      }
      bool x15668 = x15667;
      if (!x15668) break;
      x15431 = x15431 + 1;
    }
    x15431 = x15431 + 1;
    long x15678 = x15433;
    long x15679 = x15432;
    bool x15680 = x15678 == x15679;
    if (x15680) {
      long x15681 = x15679 * 4L;
      x15432 = x15681;
      printf("buffer.resize %d\n",x15681);
      int* x15684 = x15435;
      int* x15685 = (int*)realloc(x15684,x15681 * sizeof(int));
      x15435 = x15685;
      char** x15687 = x15437;
      char** x15688 = (char**)realloc(x15687,x15681 * sizeof(char*));
      x15437 = x15688;
    } else {
    }
    int* x15713 = x15435;
    x15713[x15678] = x15479;
    char** x15715 = x15437;
    char* x15497 = x1000+x15480;
    x15715[x15678] = x15497;
    x15433 = x15433 + 1;
  }
  long x15734 = 0L;
  long x15735 = x6;
  long x15736 = 0L;
  int* x15737 = (int*)malloc(x6 * sizeof(int));
  int* x15738 = x15737;
  char** x15739 = (char**)malloc(x6 * sizeof(char*));
  char** x15740 = x15739;
  int x1515 = open("../databases/sf2/nation.tbl",0);
  long x1516 = fsize(x1515);
  char* x1517 = mmap(0, x1516, PROT_READ, MAP_FILE | MAP_SHARED, x1515, 0);
  for (;;) {
    long x15745 = x15734;
    bool x15746 = x15745 < x1516;
    if (!x15746) break;
    int x15749 = 0;
    for (;;) {
      long x15750 = x15734;
      char x15751 = x1517[x15750];
      bool x15752 = x15751 != '|';
      bool x15757 = x15752;
      if (x15752) {
        long x15753 = x15734;
        char x15754 = x1517[x15753];
        bool x15755 = x15754 != '\n';
        x15757 = x15755;
      }
      bool x15758 = x15757;
      if (!x15758) break;
      int x15760 = x15749;
      long x15762 = x15734;
      int x15761 = x15760 * 10;
      char x15763 = x1517[x15762];
      char x15764 = x15763 - '0';
      int x15765 = x15761 + x15764;
      x15749 = x15765;
      x15734 = x15734 + 1;
    }
    x15734 = x15734 + 1;
    int x15771 = x15749;
    long x15772 = x15734;
    for (;;) {
      long x15773 = x15734;
      char x15774 = x1517[x15773];
      bool x15775 = x15774 != '|';
      bool x15780 = x15775;
      if (x15775) {
        long x15776 = x15734;
        char x15777 = x1517[x15776];
        bool x15778 = x15777 != '\n';
        x15780 = x15778;
      }
      bool x15781 = x15780;
      if (!x15781) break;
      x15734 = x15734 + 1;
    }
    x15734 = x15734 + 1;
    for (;;) {
      long x15792 = x15734;
      char x15793 = x1517[x15792];
      bool x15794 = x15793 != '|';
      bool x15799 = x15794;
      if (x15794) {
        long x15795 = x15734;
        char x15796 = x1517[x15795];
        bool x15797 = x15796 != '\n';
        x15799 = x15797;
      }
      bool x15800 = x15799;
      if (!x15800) break;
      x15734 = x15734 + 1;
    }
    x15734 = x15734 + 1;
    for (;;) {
      long x15815 = x15734;
      char x15816 = x1517[x15815];
      bool x15817 = x15816 != '|';
      bool x15822 = x15817;
      if (x15817) {
        long x15818 = x15734;
        char x15819 = x1517[x15818];
        bool x15820 = x15819 != '\n';
        x15822 = x15820;
      }
      bool x15823 = x15822;
      if (!x15823) break;
      x15734 = x15734 + 1;
    }
    x15734 = x15734 + 1;
    long x15833 = x15736;
    long x15834 = x15735;
    bool x15835 = x15833 == x15834;
    if (x15835) {
      long x15836 = x15834 * 4L;
      x15735 = x15836;
      printf("buffer.resize %d\n",x15836);
      int* x15839 = x15738;
      int* x15840 = (int*)realloc(x15839,x15836 * sizeof(int));
      x15738 = x15840;
      char** x15842 = x15740;
      char** x15843 = (char**)realloc(x15842,x15836 * sizeof(char*));
      x15740 = x15843;
    } else {
    }
    int* x15853 = x15738;
    x15853[x15833] = x15771;
    char** x15855 = x15740;
    char* x15789 = x1517+x15772;
    x15855[x15833] = x15789;
    x15736 = x15736 + 1;
  }
  long x15864 = 0L;
  long x15865 = x6;
  long x15866 = 0L;
  int* x15867 = (int*)malloc(x6 * sizeof(int));
  int* x15868 = x15867;
  long* x15875 = (long*)malloc(x6 * sizeof(long));
  long* x15876 = x15875;
  int x3371 = open("../databases/sf2/orders.tbl",0);
  long x3372 = fsize(x3371);
  char* x3373 = mmap(0, x3372, PROT_READ, MAP_FILE | MAP_SHARED, x3371, 0);
  for (;;) {
    long x15885 = x15864;
    bool x15886 = x15885 < x3372;
    if (!x15886) break;
    int x15889 = 0;
    for (;;) {
      long x15890 = x15864;
      char x15891 = x3373[x15890];
      bool x15892 = x15891 != '|';
      bool x15897 = x15892;
      if (x15892) {
        long x15893 = x15864;
        char x15894 = x3373[x15893];
        bool x15895 = x15894 != '\n';
        x15897 = x15895;
      }
      bool x15898 = x15897;
      if (!x15898) break;
      int x15900 = x15889;
      long x15902 = x15864;
      int x15901 = x15900 * 10;
      char x15903 = x3373[x15902];
      char x15904 = x15903 - '0';
      int x15905 = x15901 + x15904;
      x15889 = x15905;
      x15864 = x15864 + 1;
    }
    x15864 = x15864 + 1;
    int x15911 = x15889;
    for (;;) {
      long x15914 = x15864;
      char x15915 = x3373[x15914];
      bool x15916 = x15915 != '|';
      bool x15921 = x15916;
      if (x15916) {
        long x15917 = x15864;
        char x15918 = x3373[x15917];
        bool x15919 = x15918 != '\n';
        x15921 = x15919;
      }
      bool x15922 = x15921;
      if (!x15922) break;
      x15864 = x15864 + 1;
    }
    x15864 = x15864 + 1;
    x15864 = x15864 + 2;
    for (;;) {
      long x15942 = x15864;
      char x15943 = x3373[x15942];
      bool x15944 = x15943 != '.';
      bool x15949 = x15944;
      if (x15944) {
        long x15945 = x15864;
        char x15946 = x3373[x15945];
        bool x15947 = x15946 != '|';
        x15949 = x15947;
      }
      bool x15950 = x15949;
      bool x15955 = x15950;
      if (x15950) {
        long x15951 = x15864;
        char x15952 = x3373[x15951];
        bool x15953 = x15952 != '\n';
        x15955 = x15953;
      }
      bool x15956 = x15955;
      if (!x15956) break;
      x15864 = x15864 + 1;
    }
    long x15968 = x15864;
    char x15969 = x3373[x15968];
    bool x15970 = x15969 == '.';
    if (x15970) {
      x15864 = x15864 + 1;
      for (;;) {
        long x15972 = x15864;
        char x15973 = x3373[x15972];
        bool x15974 = x15973 != '|';
        bool x15979 = x15974;
        if (x15974) {
          long x15975 = x15864;
          char x15976 = x3373[x15975];
          bool x15977 = x15976 != '\n';
          x15979 = x15977;
        }
        bool x15980 = x15979;
        if (!x15980) break;
        x15864 = x15864 + 1;
      }
    } else {
    }
    x15864 = x15864 + 1;
    int x16005 = 0;
    for (;;) {
      long x16006 = x15864;
      char x16007 = x3373[x16006];
      bool x16008 = x16007 != '-';
      bool x16013 = x16008;
      if (x16008) {
        long x16009 = x15864;
        char x16010 = x3373[x16009];
        bool x16011 = x16010 != '\n';
        x16013 = x16011;
      }
      bool x16014 = x16013;
      if (!x16014) break;
      int x16016 = x16005;
      long x16018 = x15864;
      int x16017 = x16016 * 10;
      char x16019 = x3373[x16018];
      char x16020 = x16019 - '0';
      int x16021 = x16017 + x16020;
      x16005 = x16021;
      x15864 = x15864 + 1;
    }
    x15864 = x15864 + 1;
    int x16027 = x16005;
    int x16029 = 0;
    for (;;) {
      long x16030 = x15864;
      char x16031 = x3373[x16030];
      bool x16032 = x16031 != '-';
      bool x16037 = x16032;
      if (x16032) {
        long x16033 = x15864;
        char x16034 = x3373[x16033];
        bool x16035 = x16034 != '\n';
        x16037 = x16035;
      }
      bool x16038 = x16037;
      if (!x16038) break;
      int x16040 = x16029;
      long x16042 = x15864;
      int x16041 = x16040 * 10;
      char x16043 = x3373[x16042];
      char x16044 = x16043 - '0';
      int x16045 = x16041 + x16044;
      x16029 = x16045;
      x15864 = x15864 + 1;
    }
    x15864 = x15864 + 1;
    int x16051 = x16029;
    int x16053 = 0;
    for (;;) {
      long x16054 = x15864;
      char x16055 = x3373[x16054];
      bool x16056 = x16055 != '|';
      bool x16061 = x16056;
      if (x16056) {
        long x16057 = x15864;
        char x16058 = x3373[x16057];
        bool x16059 = x16058 != '\n';
        x16061 = x16059;
      }
      bool x16062 = x16061;
      if (!x16062) break;
      int x16064 = x16053;
      long x16066 = x15864;
      int x16065 = x16064 * 10;
      char x16067 = x3373[x16066];
      char x16068 = x16067 - '0';
      int x16069 = x16065 + x16068;
      x16053 = x16069;
      x15864 = x15864 + 1;
    }
    x15864 = x15864 + 1;
    int x16075 = x16053;
    for (;;) {
      long x16081 = x15864;
      char x16082 = x3373[x16081];
      bool x16083 = x16082 != '|';
      bool x16088 = x16083;
      if (x16083) {
        long x16084 = x15864;
        char x16085 = x3373[x16084];
        bool x16086 = x16085 != '\n';
        x16088 = x16086;
      }
      bool x16089 = x16088;
      if (!x16089) break;
      x15864 = x15864 + 1;
    }
    x15864 = x15864 + 1;
    for (;;) {
      long x16099 = x15864;
      char x16100 = x3373[x16099];
      bool x16101 = x16100 != '|';
      bool x16106 = x16101;
      if (x16101) {
        long x16102 = x15864;
        char x16103 = x3373[x16102];
        bool x16104 = x16103 != '\n';
        x16106 = x16104;
      }
      bool x16107 = x16106;
      if (!x16107) break;
      x15864 = x15864 + 1;
    }
    x15864 = x15864 + 1;
    for (;;) {
      long x16118 = x15864;
      char x16119 = x3373[x16118];
      bool x16120 = x16119 != '|';
      bool x16125 = x16120;
      if (x16120) {
        long x16121 = x15864;
        char x16122 = x3373[x16121];
        bool x16123 = x16122 != '\n';
        x16125 = x16123;
      }
      bool x16126 = x16125;
      if (!x16126) break;
      x15864 = x15864 + 1;
    }
    x15864 = x15864 + 1;
    for (;;) {
      long x16141 = x15864;
      char x16142 = x3373[x16141];
      bool x16143 = x16142 != '|';
      bool x16148 = x16143;
      if (x16143) {
        long x16144 = x15864;
        char x16145 = x3373[x16144];
        bool x16146 = x16145 != '\n';
        x16148 = x16146;
      }
      bool x16149 = x16148;
      if (!x16149) break;
      x15864 = x15864 + 1;
    }
    x15864 = x15864 + 1;
    long x16159 = x15866;
    long x16160 = x15865;
    bool x16161 = x16159 == x16160;
    if (x16161) {
      long x16162 = x16160 * 4L;
      x15865 = x16162;
      printf("buffer.resize %d\n",x16162);
      int* x16165 = x15868;
      int* x16166 = (int*)realloc(x16165,x16162 * sizeof(int));
      x15868 = x16166;
      long* x16177 = x15876;
      long* x16178 = (long*)realloc(x16177,x16162 * sizeof(long));
      x15876 = x16178;
    } else {
    }
    int* x16194 = x15868;
    x16194[x16159] = x15911;
    long* x16202 = x15876;
    long x16076 = x16027 * 10000L;
    long x16077 = x16051 * 100L;
    long x16078 = x16076 + x16077;
    long x16079 = x16078 + x16075;
    x16202[x16159] = x16079;
    x15866 = x15866 + 1;
  }
  long x16215 = 0L;
  long x16216 = x6;
  long x16217 = 0L;
  int* x16218 = (int*)malloc(x6 * sizeof(int));
  int* x16219 = x16218;
  int* x16220 = (int*)malloc(x6 * sizeof(int));
  int* x16221 = x16220;
  double* x16224 = (double*)malloc(x6 * sizeof(double));
  double* x16225 = x16224;
  int x1304 = open("../databases/sf2/partsupp.tbl",0);
  long x1305 = fsize(x1304);
  char* x1306 = mmap(0, x1305, PROT_READ, MAP_FILE | MAP_SHARED, x1304, 0);
  for (;;) {
    long x16228 = x16215;
    bool x16229 = x16228 < x1305;
    if (!x16229) break;
    int x16232 = 0;
    for (;;) {
      long x16233 = x16215;
      char x16234 = x1306[x16233];
      bool x16235 = x16234 != '|';
      bool x16240 = x16235;
      if (x16235) {
        long x16236 = x16215;
        char x16237 = x1306[x16236];
        bool x16238 = x16237 != '\n';
        x16240 = x16238;
      }
      bool x16241 = x16240;
      if (!x16241) break;
      int x16243 = x16232;
      long x16245 = x16215;
      int x16244 = x16243 * 10;
      char x16246 = x1306[x16245];
      char x16247 = x16246 - '0';
      int x16248 = x16244 + x16247;
      x16232 = x16248;
      x16215 = x16215 + 1;
    }
    x16215 = x16215 + 1;
    int x16254 = x16232;
    int x16256 = 0;
    for (;;) {
      long x16257 = x16215;
      char x16258 = x1306[x16257];
      bool x16259 = x16258 != '|';
      bool x16264 = x16259;
      if (x16259) {
        long x16260 = x16215;
        char x16261 = x1306[x16260];
        bool x16262 = x16261 != '\n';
        x16264 = x16262;
      }
      bool x16265 = x16264;
      if (!x16265) break;
      int x16267 = x16256;
      long x16269 = x16215;
      int x16268 = x16267 * 10;
      char x16270 = x1306[x16269];
      char x16271 = x16270 - '0';
      int x16272 = x16268 + x16271;
      x16256 = x16272;
      x16215 = x16215 + 1;
    }
    x16215 = x16215 + 1;
    int x16278 = x16256;
    for (;;) {
      long x16281 = x16215;
      char x16282 = x1306[x16281];
      bool x16283 = x16282 != '|';
      bool x16288 = x16283;
      if (x16283) {
        long x16284 = x16215;
        char x16285 = x1306[x16284];
        bool x16286 = x16285 != '\n';
        x16288 = x16286;
      }
      bool x16289 = x16288;
      if (!x16289) break;
      x16215 = x16215 + 1;
    }
    x16215 = x16215 + 1;
    int x16304 = 0;
    int x16305 = 1;
    for (;;) {
      long x16306 = x16215;
      char x16307 = x1306[x16306];
      bool x16308 = x16307 != '.';
      bool x16313 = x16308;
      if (x16308) {
        long x16309 = x16215;
        char x16310 = x1306[x16309];
        bool x16311 = x16310 != '|';
        x16313 = x16311;
      }
      bool x16314 = x16313;
      bool x16319 = x16314;
      if (x16314) {
        long x16315 = x16215;
        char x16316 = x1306[x16315];
        bool x16317 = x16316 != '\n';
        x16319 = x16317;
      }
      bool x16320 = x16319;
      if (!x16320) break;
      int x16322 = x16304;
      long x16324 = x16215;
      int x16323 = x16322 * 10;
      char x16325 = x1306[x16324];
      char x16326 = x16325 - '0';
      int x16327 = x16323 + x16326;
      x16304 = x16327;
      x16215 = x16215 + 1;
    }
    long x16332 = x16215;
    char x16333 = x1306[x16332];
    bool x16334 = x16333 == '.';
    if (x16334) {
      x16215 = x16215 + 1;
      for (;;) {
        long x16336 = x16215;
        char x16337 = x1306[x16336];
        bool x16338 = x16337 != '|';
        bool x16343 = x16338;
        if (x16338) {
          long x16339 = x16215;
          char x16340 = x1306[x16339];
          bool x16341 = x16340 != '\n';
          x16343 = x16341;
        }
        bool x16344 = x16343;
        if (!x16344) break;
        int x16346 = x16304;
        long x16348 = x16215;
        int x16347 = x16346 * 10;
        char x16349 = x1306[x16348];
        char x16350 = x16349 - '0';
        int x16351 = x16347 + x16350;
        x16304 = x16351;
        int x16353 = x16305;
        int x16354 = x16353 * 10;
        x16305 = x16354;
        x16215 = x16215 + 1;
      }
    } else {
    }
    x16215 = x16215 + 1;
    int x16363 = x16304;
    int x16365 = x16305;
    for (;;) {
      long x16369 = x16215;
      char x16370 = x1306[x16369];
      bool x16371 = x16370 != '|';
      bool x16376 = x16371;
      if (x16371) {
        long x16372 = x16215;
        char x16373 = x1306[x16372];
        bool x16374 = x16373 != '\n';
        x16376 = x16374;
      }
      bool x16377 = x16376;
      if (!x16377) break;
      x16215 = x16215 + 1;
    }
    x16215 = x16215 + 1;
    long x16387 = x16217;
    long x16388 = x16216;
    bool x16389 = x16387 == x16388;
    if (x16389) {
      long x16390 = x16388 * 4L;
      x16216 = x16390;
      printf("buffer.resize %d\n",x16390);
      int* x16393 = x16219;
      int* x16394 = (int*)realloc(x16393,x16390 * sizeof(int));
      x16219 = x16394;
      int* x16396 = x16221;
      int* x16397 = (int*)realloc(x16396,x16390 * sizeof(int));
      x16221 = x16397;
      double* x16402 = x16225;
      double* x16403 = (double*)realloc(x16402,x16390 * sizeof(double));
      x16225 = x16403;
    } else {
    }
    int* x16410 = x16219;
    x16410[x16387] = x16254;
    int* x16412 = x16221;
    x16412[x16387] = x16278;
    double* x16416 = x16225;
    double x16364 = (double)x16363;
    double x16366 = (double)x16365;
    double x16367 = x16364 / x16366;
    x16416[x16387] = x16367;
    x16217 = x16217 + 1;
  }
  long x16423 = 0L;
  long x16424 = x6;
  long x16425 = 0L;
  int* x16426 = (int*)malloc(x6 * sizeof(int));
  int* x16427 = x16426;
  int* x16432 = (int*)malloc(x6 * sizeof(int));
  int* x16433 = x16432;
  int x1750 = open("../databases/sf2/supplier.tbl",0);
  long x1751 = fsize(x1750);
  char* x1752 = mmap(0, x1751, PROT_READ, MAP_FILE | MAP_SHARED, x1750, 0);
  for (;;) {
    long x16440 = x16423;
    bool x16441 = x16440 < x1751;
    if (!x16441) break;
    int x16444 = 0;
    for (;;) {
      long x16445 = x16423;
      char x16446 = x1752[x16445];
      bool x16447 = x16446 != '|';
      bool x16452 = x16447;
      if (x16447) {
        long x16448 = x16423;
        char x16449 = x1752[x16448];
        bool x16450 = x16449 != '\n';
        x16452 = x16450;
      }
      bool x16453 = x16452;
      if (!x16453) break;
      int x16455 = x16444;
      long x16457 = x16423;
      int x16456 = x16455 * 10;
      char x16458 = x1752[x16457];
      char x16459 = x16458 - '0';
      int x16460 = x16456 + x16459;
      x16444 = x16460;
      x16423 = x16423 + 1;
    }
    x16423 = x16423 + 1;
    int x16466 = x16444;
    for (;;) {
      long x16468 = x16423;
      char x16469 = x1752[x16468];
      bool x16470 = x16469 != '|';
      bool x16475 = x16470;
      if (x16470) {
        long x16471 = x16423;
        char x16472 = x1752[x16471];
        bool x16473 = x16472 != '\n';
        x16475 = x16473;
      }
      bool x16476 = x16475;
      if (!x16476) break;
      x16423 = x16423 + 1;
    }
    x16423 = x16423 + 1;
    for (;;) {
      long x16486 = x16423;
      char x16487 = x1752[x16486];
      bool x16488 = x16487 != '|';
      bool x16493 = x16488;
      if (x16488) {
        long x16489 = x16423;
        char x16490 = x1752[x16489];
        bool x16491 = x16490 != '\n';
        x16493 = x16491;
      }
      bool x16494 = x16493;
      if (!x16494) break;
      x16423 = x16423 + 1;
    }
    x16423 = x16423 + 1;
    int x16504 = 0;
    for (;;) {
      long x16505 = x16423;
      char x16506 = x1752[x16505];
      bool x16507 = x16506 != '|';
      bool x16512 = x16507;
      if (x16507) {
        long x16508 = x16423;
        char x16509 = x1752[x16508];
        bool x16510 = x16509 != '\n';
        x16512 = x16510;
      }
      bool x16513 = x16512;
      if (!x16513) break;
      int x16515 = x16504;
      long x16517 = x16423;
      int x16516 = x16515 * 10;
      char x16518 = x1752[x16517];
      char x16519 = x16518 - '0';
      int x16520 = x16516 + x16519;
      x16504 = x16520;
      x16423 = x16423 + 1;
    }
    x16423 = x16423 + 1;
    int x16526 = x16504;
    for (;;) {
      long x16528 = x16423;
      char x16529 = x1752[x16528];
      bool x16530 = x16529 != '|';
      bool x16535 = x16530;
      if (x16530) {
        long x16531 = x16423;
        char x16532 = x1752[x16531];
        bool x16533 = x16532 != '\n';
        x16535 = x16533;
      }
      bool x16536 = x16535;
      if (!x16536) break;
      x16423 = x16423 + 1;
    }
    x16423 = x16423 + 1;
    for (;;) {
      long x16548 = x16423;
      char x16549 = x1752[x16548];
      bool x16550 = x16549 != '.';
      bool x16555 = x16550;
      if (x16550) {
        long x16551 = x16423;
        char x16552 = x1752[x16551];
        bool x16553 = x16552 != '|';
        x16555 = x16553;
      }
      bool x16556 = x16555;
      bool x16561 = x16556;
      if (x16556) {
        long x16557 = x16423;
        char x16558 = x1752[x16557];
        bool x16559 = x16558 != '\n';
        x16561 = x16559;
      }
      bool x16562 = x16561;
      if (!x16562) break;
      x16423 = x16423 + 1;
    }
    long x16574 = x16423;
    char x16575 = x1752[x16574];
    bool x16576 = x16575 == '.';
    if (x16576) {
      x16423 = x16423 + 1;
      for (;;) {
        long x16578 = x16423;
        char x16579 = x1752[x16578];
        bool x16580 = x16579 != '|';
        bool x16585 = x16580;
        if (x16580) {
          long x16581 = x16423;
          char x16582 = x1752[x16581];
          bool x16583 = x16582 != '\n';
          x16585 = x16583;
        }
        bool x16586 = x16585;
        if (!x16586) break;
        x16423 = x16423 + 1;
      }
    } else {
    }
    x16423 = x16423 + 1;
    for (;;) {
      long x16611 = x16423;
      char x16612 = x1752[x16611];
      bool x16613 = x16612 != '|';
      bool x16618 = x16613;
      if (x16613) {
        long x16614 = x16423;
        char x16615 = x1752[x16614];
        bool x16616 = x16615 != '\n';
        x16618 = x16616;
      }
      bool x16619 = x16618;
      if (!x16619) break;
      x16423 = x16423 + 1;
    }
    x16423 = x16423 + 1;
    long x16629 = x16425;
    long x16630 = x16424;
    bool x16631 = x16629 == x16630;
    if (x16631) {
      long x16632 = x16630 * 4L;
      x16424 = x16632;
      printf("buffer.resize %d\n",x16632);
      int* x16635 = x16427;
      int* x16636 = (int*)realloc(x16635,x16632 * sizeof(int));
      x16427 = x16636;
      int* x16644 = x16433;
      int* x16645 = (int*)realloc(x16644,x16632 * sizeof(int));
      x16433 = x16645;
    } else {
    }
    int* x16658 = x16427;
    x16658[x16629] = x16466;
    int* x16664 = x16433;
    x16664[x16629] = x16526;
    x16425 = x16425 + 1;
  }
  long x16675 = 0L;
  long x16676 = x6;
  long x16677 = 0L;
  int* x16678 = (int*)malloc(x6 * sizeof(int));
  int* x16679 = x16678;
  int* x16680 = (int*)malloc(x6 * sizeof(int));
  int* x16681 = x16680;
  int* x16682 = (int*)malloc(x6 * sizeof(int));
  int* x16683 = x16682;
  double* x16686 = (double*)malloc(x6 * sizeof(double));
  double* x16687 = x16686;
  double* x16688 = (double*)malloc(x6 * sizeof(double));
  double* x16689 = x16688;
  double* x16690 = (double*)malloc(x6 * sizeof(double));
  double* x16691 = x16690;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  long x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    long x16710 = x16675;
    bool x16711 = x16710 < x3;
    if (!x16711) break;
    int x16714 = 0;
    for (;;) {
      long x16715 = x16675;
      char x16716 = x4[x16715];
      bool x16717 = x16716 != '|';
      bool x16722 = x16717;
      if (x16717) {
        long x16718 = x16675;
        char x16719 = x4[x16718];
        bool x16720 = x16719 != '\n';
        x16722 = x16720;
      }
      bool x16723 = x16722;
      if (!x16723) break;
      int x16725 = x16714;
      long x16727 = x16675;
      int x16726 = x16725 * 10;
      char x16728 = x4[x16727];
      char x16729 = x16728 - '0';
      int x16730 = x16726 + x16729;
      x16714 = x16730;
      x16675 = x16675 + 1;
    }
    x16675 = x16675 + 1;
    int x16736 = x16714;
    int x16738 = 0;
    for (;;) {
      long x16739 = x16675;
      char x16740 = x4[x16739];
      bool x16741 = x16740 != '|';
      bool x16746 = x16741;
      if (x16741) {
        long x16742 = x16675;
        char x16743 = x4[x16742];
        bool x16744 = x16743 != '\n';
        x16746 = x16744;
      }
      bool x16747 = x16746;
      if (!x16747) break;
      int x16749 = x16738;
      long x16751 = x16675;
      int x16750 = x16749 * 10;
      char x16752 = x4[x16751];
      char x16753 = x16752 - '0';
      int x16754 = x16750 + x16753;
      x16738 = x16754;
      x16675 = x16675 + 1;
    }
    x16675 = x16675 + 1;
    int x16760 = x16738;
    int x16762 = 0;
    for (;;) {
      long x16763 = x16675;
      char x16764 = x4[x16763];
      bool x16765 = x16764 != '|';
      bool x16770 = x16765;
      if (x16765) {
        long x16766 = x16675;
        char x16767 = x4[x16766];
        bool x16768 = x16767 != '\n';
        x16770 = x16768;
      }
      bool x16771 = x16770;
      if (!x16771) break;
      int x16773 = x16762;
      long x16775 = x16675;
      int x16774 = x16773 * 10;
      char x16776 = x4[x16775];
      char x16777 = x16776 - '0';
      int x16778 = x16774 + x16777;
      x16762 = x16778;
      x16675 = x16675 + 1;
    }
    x16675 = x16675 + 1;
    int x16784 = x16762;
    for (;;) {
      long x16787 = x16675;
      char x16788 = x4[x16787];
      bool x16789 = x16788 != '|';
      bool x16794 = x16789;
      if (x16789) {
        long x16790 = x16675;
        char x16791 = x4[x16790];
        bool x16792 = x16791 != '\n';
        x16794 = x16792;
      }
      bool x16795 = x16794;
      if (!x16795) break;
      x16675 = x16675 + 1;
    }
    x16675 = x16675 + 1;
    int x16810 = 0;
    int x16811 = 1;
    for (;;) {
      long x16812 = x16675;
      char x16813 = x4[x16812];
      bool x16814 = x16813 != '.';
      bool x16819 = x16814;
      if (x16814) {
        long x16815 = x16675;
        char x16816 = x4[x16815];
        bool x16817 = x16816 != '|';
        x16819 = x16817;
      }
      bool x16820 = x16819;
      bool x16825 = x16820;
      if (x16820) {
        long x16821 = x16675;
        char x16822 = x4[x16821];
        bool x16823 = x16822 != '\n';
        x16825 = x16823;
      }
      bool x16826 = x16825;
      if (!x16826) break;
      int x16828 = x16810;
      long x16830 = x16675;
      int x16829 = x16828 * 10;
      char x16831 = x4[x16830];
      char x16832 = x16831 - '0';
      int x16833 = x16829 + x16832;
      x16810 = x16833;
      x16675 = x16675 + 1;
    }
    long x16838 = x16675;
    char x16839 = x4[x16838];
    bool x16840 = x16839 == '.';
    if (x16840) {
      x16675 = x16675 + 1;
      for (;;) {
        long x16842 = x16675;
        char x16843 = x4[x16842];
        bool x16844 = x16843 != '|';
        bool x16849 = x16844;
        if (x16844) {
          long x16845 = x16675;
          char x16846 = x4[x16845];
          bool x16847 = x16846 != '\n';
          x16849 = x16847;
        }
        bool x16850 = x16849;
        if (!x16850) break;
        int x16852 = x16810;
        long x16854 = x16675;
        int x16853 = x16852 * 10;
        char x16855 = x4[x16854];
        char x16856 = x16855 - '0';
        int x16857 = x16853 + x16856;
        x16810 = x16857;
        int x16859 = x16811;
        int x16860 = x16859 * 10;
        x16811 = x16860;
        x16675 = x16675 + 1;
      }
    } else {
    }
    x16675 = x16675 + 1;
    int x16869 = x16810;
    int x16871 = x16811;
    int x16875 = 0;
    int x16876 = 1;
    for (;;) {
      long x16877 = x16675;
      char x16878 = x4[x16877];
      bool x16879 = x16878 != '.';
      bool x16884 = x16879;
      if (x16879) {
        long x16880 = x16675;
        char x16881 = x4[x16880];
        bool x16882 = x16881 != '|';
        x16884 = x16882;
      }
      bool x16885 = x16884;
      bool x16890 = x16885;
      if (x16885) {
        long x16886 = x16675;
        char x16887 = x4[x16886];
        bool x16888 = x16887 != '\n';
        x16890 = x16888;
      }
      bool x16891 = x16890;
      if (!x16891) break;
      int x16893 = x16875;
      long x16895 = x16675;
      int x16894 = x16893 * 10;
      char x16896 = x4[x16895];
      char x16897 = x16896 - '0';
      int x16898 = x16894 + x16897;
      x16875 = x16898;
      x16675 = x16675 + 1;
    }
    long x16903 = x16675;
    char x16904 = x4[x16903];
    bool x16905 = x16904 == '.';
    if (x16905) {
      x16675 = x16675 + 1;
      for (;;) {
        long x16907 = x16675;
        char x16908 = x4[x16907];
        bool x16909 = x16908 != '|';
        bool x16914 = x16909;
        if (x16909) {
          long x16910 = x16675;
          char x16911 = x4[x16910];
          bool x16912 = x16911 != '\n';
          x16914 = x16912;
        }
        bool x16915 = x16914;
        if (!x16915) break;
        int x16917 = x16875;
        long x16919 = x16675;
        int x16918 = x16917 * 10;
        char x16920 = x4[x16919];
        char x16921 = x16920 - '0';
        int x16922 = x16918 + x16921;
        x16875 = x16922;
        int x16924 = x16876;
        int x16925 = x16924 * 10;
        x16876 = x16925;
        x16675 = x16675 + 1;
      }
    } else {
    }
    x16675 = x16675 + 1;
    int x16934 = x16875;
    int x16936 = x16876;
    int x16940 = 0;
    int x16941 = 1;
    for (;;) {
      long x16942 = x16675;
      char x16943 = x4[x16942];
      bool x16944 = x16943 != '.';
      bool x16949 = x16944;
      if (x16944) {
        long x16945 = x16675;
        char x16946 = x4[x16945];
        bool x16947 = x16946 != '|';
        x16949 = x16947;
      }
      bool x16950 = x16949;
      bool x16955 = x16950;
      if (x16950) {
        long x16951 = x16675;
        char x16952 = x4[x16951];
        bool x16953 = x16952 != '\n';
        x16955 = x16953;
      }
      bool x16956 = x16955;
      if (!x16956) break;
      int x16958 = x16940;
      long x16960 = x16675;
      int x16959 = x16958 * 10;
      char x16961 = x4[x16960];
      char x16962 = x16961 - '0';
      int x16963 = x16959 + x16962;
      x16940 = x16963;
      x16675 = x16675 + 1;
    }
    long x16968 = x16675;
    char x16969 = x4[x16968];
    bool x16970 = x16969 == '.';
    if (x16970) {
      x16675 = x16675 + 1;
      for (;;) {
        long x16972 = x16675;
        char x16973 = x4[x16972];
        bool x16974 = x16973 != '|';
        bool x16979 = x16974;
        if (x16974) {
          long x16975 = x16675;
          char x16976 = x4[x16975];
          bool x16977 = x16976 != '\n';
          x16979 = x16977;
        }
        bool x16980 = x16979;
        if (!x16980) break;
        int x16982 = x16940;
        long x16984 = x16675;
        int x16983 = x16982 * 10;
        char x16985 = x4[x16984];
        char x16986 = x16985 - '0';
        int x16987 = x16983 + x16986;
        x16940 = x16987;
        int x16989 = x16941;
        int x16990 = x16989 * 10;
        x16941 = x16990;
        x16675 = x16675 + 1;
      }
    } else {
    }
    x16675 = x16675 + 1;
    int x16999 = x16940;
    int x17001 = x16941;
    for (;;) {
      long x17007 = x16675;
      char x17008 = x4[x17007];
      bool x17009 = x17008 != '.';
      bool x17014 = x17009;
      if (x17009) {
        long x17010 = x16675;
        char x17011 = x4[x17010];
        bool x17012 = x17011 != '|';
        x17014 = x17012;
      }
      bool x17015 = x17014;
      bool x17020 = x17015;
      if (x17015) {
        long x17016 = x16675;
        char x17017 = x4[x17016];
        bool x17018 = x17017 != '\n';
        x17020 = x17018;
      }
      bool x17021 = x17020;
      if (!x17021) break;
      x16675 = x16675 + 1;
    }
    long x17033 = x16675;
    char x17034 = x4[x17033];
    bool x17035 = x17034 == '.';
    if (x17035) {
      x16675 = x16675 + 1;
      for (;;) {
        long x17037 = x16675;
        char x17038 = x4[x17037];
        bool x17039 = x17038 != '|';
        bool x17044 = x17039;
        if (x17039) {
          long x17040 = x16675;
          char x17041 = x4[x17040];
          bool x17042 = x17041 != '\n';
          x17044 = x17042;
        }
        bool x17045 = x17044;
        if (!x17045) break;
        x16675 = x16675 + 1;
      }
    } else {
    }
    x16675 = x16675 + 1;
    x16675 = x16675 + 2;
    x16675 = x16675 + 2;
    for (;;) {
      long x17077 = x16675;
      char x17078 = x4[x17077];
      bool x17079 = x17078 != '-';
      bool x17084 = x17079;
      if (x17079) {
        long x17080 = x16675;
        char x17081 = x4[x17080];
        bool x17082 = x17081 != '\n';
        x17084 = x17082;
      }
      bool x17085 = x17084;
      if (!x17085) break;
      x16675 = x16675 + 1;
    }
    x16675 = x16675 + 1;
    for (;;) {
      long x17101 = x16675;
      char x17102 = x4[x17101];
      bool x17103 = x17102 != '-';
      bool x17108 = x17103;
      if (x17103) {
        long x17104 = x16675;
        char x17105 = x4[x17104];
        bool x17106 = x17105 != '\n';
        x17108 = x17106;
      }
      bool x17109 = x17108;
      if (!x17109) break;
      x16675 = x16675 + 1;
    }
    x16675 = x16675 + 1;
    for (;;) {
      long x17125 = x16675;
      char x17126 = x4[x17125];
      bool x17127 = x17126 != '|';
      bool x17132 = x17127;
      if (x17127) {
        long x17128 = x16675;
        char x17129 = x4[x17128];
        bool x17130 = x17129 != '\n';
        x17132 = x17130;
      }
      bool x17133 = x17132;
      if (!x17133) break;
      x16675 = x16675 + 1;
    }
    x16675 = x16675 + 1;
    for (;;) {
      long x17153 = x16675;
      char x17154 = x4[x17153];
      bool x17155 = x17154 != '-';
      bool x17160 = x17155;
      if (x17155) {
        long x17156 = x16675;
        char x17157 = x4[x17156];
        bool x17158 = x17157 != '\n';
        x17160 = x17158;
      }
      bool x17161 = x17160;
      if (!x17161) break;
      x16675 = x16675 + 1;
    }
    x16675 = x16675 + 1;
    for (;;) {
      long x17177 = x16675;
      char x17178 = x4[x17177];
      bool x17179 = x17178 != '-';
      bool x17184 = x17179;
      if (x17179) {
        long x17180 = x16675;
        char x17181 = x4[x17180];
        bool x17182 = x17181 != '\n';
        x17184 = x17182;
      }
      bool x17185 = x17184;
      if (!x17185) break;
      x16675 = x16675 + 1;
    }
    x16675 = x16675 + 1;
    for (;;) {
      long x17201 = x16675;
      char x17202 = x4[x17201];
      bool x17203 = x17202 != '|';
      bool x17208 = x17203;
      if (x17203) {
        long x17204 = x16675;
        char x17205 = x4[x17204];
        bool x17206 = x17205 != '\n';
        x17208 = x17206;
      }
      bool x17209 = x17208;
      if (!x17209) break;
      x16675 = x16675 + 1;
    }
    x16675 = x16675 + 1;
    for (;;) {
      long x17229 = x16675;
      char x17230 = x4[x17229];
      bool x17231 = x17230 != '-';
      bool x17236 = x17231;
      if (x17231) {
        long x17232 = x16675;
        char x17233 = x4[x17232];
        bool x17234 = x17233 != '\n';
        x17236 = x17234;
      }
      bool x17237 = x17236;
      if (!x17237) break;
      x16675 = x16675 + 1;
    }
    x16675 = x16675 + 1;
    for (;;) {
      long x17253 = x16675;
      char x17254 = x4[x17253];
      bool x17255 = x17254 != '-';
      bool x17260 = x17255;
      if (x17255) {
        long x17256 = x16675;
        char x17257 = x4[x17256];
        bool x17258 = x17257 != '\n';
        x17260 = x17258;
      }
      bool x17261 = x17260;
      if (!x17261) break;
      x16675 = x16675 + 1;
    }
    x16675 = x16675 + 1;
    for (;;) {
      long x17277 = x16675;
      char x17278 = x4[x17277];
      bool x17279 = x17278 != '|';
      bool x17284 = x17279;
      if (x17279) {
        long x17280 = x16675;
        char x17281 = x4[x17280];
        bool x17282 = x17281 != '\n';
        x17284 = x17282;
      }
      bool x17285 = x17284;
      if (!x17285) break;
      x16675 = x16675 + 1;
    }
    x16675 = x16675 + 1;
    for (;;) {
      long x17304 = x16675;
      char x17305 = x4[x17304];
      bool x17306 = x17305 != '|';
      bool x17311 = x17306;
      if (x17306) {
        long x17307 = x16675;
        char x17308 = x4[x17307];
        bool x17309 = x17308 != '\n';
        x17311 = x17309;
      }
      bool x17312 = x17311;
      if (!x17312) break;
      x16675 = x16675 + 1;
    }
    x16675 = x16675 + 1;
    for (;;) {
      long x17322 = x16675;
      char x17323 = x4[x17322];
      bool x17324 = x17323 != '|';
      bool x17329 = x17324;
      if (x17324) {
        long x17325 = x16675;
        char x17326 = x4[x17325];
        bool x17327 = x17326 != '\n';
        x17329 = x17327;
      }
      bool x17330 = x17329;
      if (!x17330) break;
      x16675 = x16675 + 1;
    }
    x16675 = x16675 + 1;
    for (;;) {
      long x17340 = x16675;
      char x17341 = x4[x17340];
      bool x17342 = x17341 != '|';
      bool x17347 = x17342;
      if (x17342) {
        long x17343 = x16675;
        char x17344 = x4[x17343];
        bool x17345 = x17344 != '\n';
        x17347 = x17345;
      }
      bool x17348 = x17347;
      if (!x17348) break;
      x16675 = x16675 + 1;
    }
    x16675 = x16675 + 1;
    long x17358 = x16677;
    long x17359 = x16676;
    bool x17360 = x17358 == x17359;
    if (x17360) {
      long x17361 = x17359 * 4L;
      x16676 = x17361;
      printf("buffer.resize %d\n",x17361);
      int* x17364 = x16679;
      int* x17365 = (int*)realloc(x17364,x17361 * sizeof(int));
      x16679 = x17365;
      int* x17367 = x16681;
      int* x17368 = (int*)realloc(x17367,x17361 * sizeof(int));
      x16681 = x17368;
      int* x17370 = x16683;
      int* x17371 = (int*)realloc(x17370,x17361 * sizeof(int));
      x16683 = x17371;
      double* x17376 = x16687;
      double* x17377 = (double*)realloc(x17376,x17361 * sizeof(double));
      x16687 = x17377;
      double* x17379 = x16689;
      double* x17380 = (double*)realloc(x17379,x17361 * sizeof(double));
      x16689 = x17380;
      double* x17382 = x16691;
      double* x17383 = (double*)realloc(x17382,x17361 * sizeof(double));
      x16691 = x17383;
    } else {
    }
    int* x17414 = x16679;
    x17414[x17358] = x16736;
    int* x17416 = x16681;
    x17416[x17358] = x16760;
    int* x17418 = x16683;
    x17418[x17358] = x16784;
    double* x17422 = x16687;
    double x16870 = (double)x16869;
    double x16872 = (double)x16871;
    double x16873 = x16870 / x16872;
    x17422[x17358] = x16873;
    double* x17424 = x16689;
    double x16935 = (double)x16934;
    double x16937 = (double)x16936;
    double x16938 = x16935 / x16937;
    x17424[x17358] = x16938;
    double* x17426 = x16691;
    double x17000 = (double)x16999;
    double x17002 = (double)x17001;
    double x17003 = x17000 / x17002;
    x17426[x17358] = x17003;
    x16677 = x16677 + 1;
  }
  long x2011 = DEFAULT_JOIN_HASH_SIZE;
  long x787 = DEFAULT_AGG_HASH_SIZE ;
  long x2034 = x2011 - 1L;
  long x802 = x787 - 1L;
  bool x975 = true == false;
  int x17449;
  for(x17449=0; x17449 < 5; x17449++) {
    bool x17450 = false;
    long x17451 = 0L;
    bool x17452 = false;
    long x17453 = 0L;
    bool x17454 = false;
    long x17455 = 0L;
    bool x17456 = false;
    long x17457 = 0L;
    bool x17459 = false;
    long x17460 = 0L;
    bool x17461 = false;
    long x17462 = 0L;
    int* x17464 = (int*)malloc(x2011 * sizeof(int));
    int* x17465 = x17464;
    char** x17466 = (char**)malloc(x2011 * sizeof(char*));
    char** x17467 = x17466;
    long x17472 = 0L;
    long* x17473 = (long*)malloc(x2011 * sizeof(long));
    long* x17474 = (long*)malloc(x2011 * sizeof(long));
    long x17475;
    for(x17475=0L; x17475 < x2011; x17475++) {
      x17473[x17475] = -1L;
    }
    char** x17483 = (char**)malloc(x2011 * sizeof(char*));
    char** x17484 = x17483;
    int* x17489 = (int*)malloc(x2011 * sizeof(int));
    int* x17490 = x17489;
    long x17503 = 0L;
    long* x17504 = (long*)malloc(x2011 * sizeof(long));
    long* x17505 = (long*)malloc(x2011 * sizeof(long));
    long x17506;
    for(x17506=0L; x17506 < x2011; x17506++) {
      x17504[x17506] = -1L;
    }
    int* x17512 = (int*)malloc(x2011 * sizeof(int));
    int* x17513 = x17512;
    long x17530 = 0L;
    long* x17531 = (long*)malloc(x2011 * sizeof(long));
    long* x17532 = (long*)malloc(x2011 * sizeof(long));
    long x17533;
    for(x17533=0L; x17533 < x2011; x17533++) {
      x17531[x17533] = -1L;
    }
    int* x17539 = (int*)malloc(x2011 * sizeof(int));
    int* x17540 = x17539;
    int* x17541 = (int*)malloc(x2011 * sizeof(int));
    int* x17542 = x17541;
    double* x17545 = (double*)malloc(x2011 * sizeof(double));
    double* x17546 = x17545;
    long x17549 = 0L;
    long* x17550 = (long*)malloc(x2011 * sizeof(long));
    long* x17551 = (long*)malloc(x2011 * sizeof(long));
    long x17552;
    for(x17552=0L; x17552 < x2011; x17552++) {
      x17550[x17552] = -1L;
    }
    double* x17564 = (double*)malloc(x2011 * sizeof(double));
    double* x17565 = x17564;
    char** x17588 = (char**)malloc(x2011 * sizeof(char*));
    char** x17589 = x17588;
    int* x17608 = (int*)malloc(x2011 * sizeof(int));
    int* x17609 = x17608;
    double* x17616 = (double*)malloc(x2011 * sizeof(double));
    double* x17617 = x17616;
    double* x17618 = (double*)malloc(x2011 * sizeof(double));
    double* x17619 = x17618;
    double* x17620 = (double*)malloc(x2011 * sizeof(double));
    double* x17621 = x17620;
    long x17640 = 0L;
    long* x17641 = (long*)malloc(x2011 * sizeof(long));
    long* x17642 = (long*)malloc(x2011 * sizeof(long));
    long x17643;
    for(x17643=0L; x17643 < x2011; x17643++) {
      x17641[x17643] = -1L;
    }
    struct Anon1506628547* x17649 = (struct Anon1506628547*)malloc(x787 * sizeof(struct Anon1506628547));
    struct Anon1506628547* x17650 = x17649;
    long x17651 = 0L;
    long* x17652 = (long*)malloc(x787 * sizeof(long));
    long x17653;
    for(x17653=0L; x17653 < x787; x17653++) {
      struct Anon1506628547* x17654 = x17650;
      struct Anon1506628547 x17655 = x17654[x17653];
      struct Anon1548200872 x17656 = x17655.key;;
      struct Anon2052879266 x17657 = x17655.aggs;;
      struct Anon1506628547 x17658;
      x17658.exists = false;
      x17658.key = x17656;
      x17658.aggs = x17657;
      x17654[x17653] = x17658;
    }
    long x17663 = 0L;
    struct timeval x18375, x18376, x18377;
    gettimeofday(&x18375, NULL);
    printf("%s\n","begin scan PARTSUPP");
    for (;;) {
      bool x17665 = x17459;
      bool x17666 = !x17665;
      bool x17671 = x17666;
      if (x17666) {
        long x17667 = x17460;
        long x17668 = x16217;
        bool x17669 = x17667 < x17668;
        x17671 = x17669;
      }
      bool x17672 = x17671;
      if (!x17672) break;
      long x17674 = x17460;
      int* x17675 = x16219;
      int x17676 = x17675[x17674];
      int* x17677 = x16221;
      int x17678 = x17677[x17674];
      double* x17681 = x16225;
      double x17682 = x17681[x17674];
      x17460 = x17460 + 1;
      long x17687 = x17549;
      int* x17688 = x17540;
      x17688[x17687] = x17676;
      int* x17690 = x17542;
      x17690[x17687] = x17678;
      double* x17694 = x17546;
      x17694[x17687] = x17682;
      x17549 = x17549 + 1L;
      long x17699 = x17676 & x2034;
      long x17700 = x17550[x17699];
      x17550[x17699] = x17687;
      x17551[x17687] = x17700;
    }
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x17706 = x17456;
      bool x17707 = !x17706;
      bool x17712 = x17707;
      if (x17707) {
        long x17708 = x17457;
        long x17709 = x15433;
        bool x17710 = x17708 < x17709;
        x17712 = x17710;
      }
      bool x17713 = x17712;
      if (!x17713) break;
      long x17715 = x17457;
      int* x17716 = x15435;
      int x17717 = x17716[x17715];
      char** x17718 = x15437;
      char* x17719 = x17718[x17715];
      x17457 = x17457 + 1;
      bool x17736 = strstr(x17719,"ghost") != NULL;
      if (x17736) {
        long x17737 = x17530;
        int* x17738 = x17513;
        x17738[x17737] = x17717;
        x17530 = x17530 + 1L;
        long x17757 = x17717 & x2034;
        long x17758 = x17531[x17757];
        x17531[x17757] = x17737;
        x17532[x17737] = x17758;
      } else {
      }
    }
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x17766 = x17450;
      bool x17767 = !x17766;
      bool x17772 = x17767;
      if (x17767) {
        long x17768 = x17451;
        long x17769 = x15736;
        bool x17770 = x17768 < x17769;
        x17772 = x17770;
      }
      bool x17773 = x17772;
      if (!x17773) break;
      long x17775 = x17451;
      int* x17776 = x15738;
      int x17777 = x17776[x17775];
      char** x17778 = x15740;
      char* x17779 = x17778[x17775];
      x17451 = x17451 + 1;
      long x17786 = x17472;
      int* x17787 = x17465;
      x17787[x17786] = x17777;
      char** x17789 = x17467;
      x17789[x17786] = x17779;
      x17472 = x17472 + 1L;
      long x17796 = x17777 & x2034;
      long x17797 = x17473[x17796];
      x17473[x17796] = x17786;
      x17474[x17786] = x17797;
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x17803 = x17452;
      bool x17804 = !x17803;
      bool x17809 = x17804;
      if (x17804) {
        long x17805 = x17453;
        long x17806 = x16425;
        bool x17807 = x17805 < x17806;
        x17809 = x17807;
      }
      bool x17810 = x17809;
      if (!x17810) break;
      long x17812 = x17453;
      int* x17813 = x16427;
      int x17814 = x17813[x17812];
      int* x17819 = x16433;
      int x17820 = x17819[x17812];
      x17453 = x17453 + 1;
      long x17829 = x17820 & x2034;
      long x17830 = x17473[x17829];
      long x17831 = x17830;
      long x17875 = x17814 & x2034;
      for (;;) {
        long x17832 = x17831;
        bool x17833 = x17832 != -1;
        if (!x17833) break;
        long x17835 = x17831;
        int* x17836 = x17465;
        int x17837 = x17836[x17835];
        char** x17838 = x17467;
        char* x17839 = x17838[x17835];
        long x17845 = x17474[x17835];
        x17831 = x17845;
        bool x17847 = x17837 == x17820;
        if (x17847) {
          long x17851 = x17503;
          char** x17854 = x17484;
          x17854[x17851] = x17839;
          int* x17860 = x17490;
          x17860[x17851] = x17814;
          x17503 = x17503 + 1L;
          long x17876 = x17504[x17875];
          x17504[x17875] = x17851;
          x17505[x17851] = x17876;
        } else {
        }
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x17886 = x17454;
      bool x17887 = !x17886;
      bool x17892 = x17887;
      if (x17887) {
        long x17888 = x17455;
        long x17889 = x16677;
        bool x17890 = x17888 < x17889;
        x17892 = x17890;
      }
      bool x17893 = x17892;
      if (!x17893) break;
      long x17895 = x17455;
      int* x17896 = x16679;
      int x17897 = x17896[x17895];
      int* x17898 = x16681;
      int x17899 = x17898[x17895];
      int* x17900 = x16683;
      int x17901 = x17900[x17895];
      double* x17904 = x16687;
      double x17905 = x17904[x17895];
      double* x17906 = x16689;
      double x17907 = x17906[x17895];
      double* x17908 = x16691;
      double x17909 = x17908[x17895];
      x17455 = x17455 + 1;
      long x17930 = x17901 & x2034;
      long x17931 = x17504[x17930];
      long x17932 = x17931;
      long x17966 = x17899 & x2034;
      long x18108 = x17897 & x2034;
      for (;;) {
        long x17933 = x17932;
        bool x17934 = x17933 != -1;
        if (!x17934) break;
        long x17936 = x17932;
        char** x17939 = x17484;
        char* x17940 = x17939[x17936];
        int* x17945 = x17490;
        int x17946 = x17945[x17936];
        long x17960 = x17505[x17936];
        x17932 = x17960;
        bool x17962 = x17946 == x17901;
        if (x17962) {
          long x17967 = x17531[x17966];
          long x17968 = x17967;
          for (;;) {
            long x17969 = x17968;
            bool x17970 = x17969 != -1;
            if (!x17970) break;
            long x17972 = x17968;
            int* x17973 = x17513;
            int x17974 = x17973[x17972];
            long x17992 = x17532[x17972];
            x17968 = x17992;
            bool x17994 = x17974 == x17899;
            if (x17994) {
              long x17998 = x17550[x17966];
              long x17999 = x17998;
              for (;;) {
                long x18000 = x17999;
                bool x18001 = x18000 != -1;
                if (!x18001) break;
                long x18003 = x17999;
                int* x18004 = x17540;
                int x18005 = x18004[x18003];
                int* x18006 = x17542;
                int x18007 = x18006[x18003];
                double* x18010 = x17546;
                double x18011 = x18010[x18003];
                long x18015 = x17551[x18003];
                x17999 = x18015;
                bool x18017 = x18005 == x17899;
                bool x18019 = x18017;
                if (x18017) {
                  bool x18018 = x18007 == x17901;
                  x18019 = x18018;
                }
                bool x18020 = x18019;
                if (x18020) {
                  long x18024 = x17640;
                  double* x18031 = x17565;
                  x18031[x18024] = x18011;
                  char** x18055 = x17589;
                  x18055[x18024] = x17940;
                  int* x18075 = x17609;
                  x18075[x18024] = x17897;
                  double* x18083 = x17617;
                  x18083[x18024] = x17905;
                  double* x18085 = x17619;
                  x18085[x18024] = x17907;
                  double* x18087 = x17621;
                  x18087[x18024] = x17909;
                  x17640 = x17640 + 1L;
                  long x18109 = x17641[x18108];
                  x17641[x18108] = x18024;
                  x17642[x18024] = x18109;
                } else {
                }
              }
            } else {
            }
          }
        } else {
        }
      }
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x18127 = x17461;
      bool x18128 = !x18127;
      bool x18133 = x18128;
      if (x18128) {
        long x18129 = x17462;
        long x18130 = x15866;
        bool x18131 = x18129 < x18130;
        x18133 = x18131;
      }
      bool x18134 = x18133;
      if (!x18134) break;
      long x18136 = x17462;
      int* x18137 = x15868;
      int x18138 = x18137[x18136];
      long* x18145 = x15876;
      long x18146 = x18145[x18136];
      x17462 = x17462 + 1;
      long x18157 = x18138 & x2034;
      long x18158 = x17641[x18157];
      long x18159 = x18158;
      long x18253 = x18146; // date
      long x18254 = x18253/10000;
      int x18255 = (int)x18254;
      for (;;) {
        long x18160 = x18159;
        bool x18161 = x18160 != -1;
        if (!x18161) break;
        long x18163 = x18159;
        double* x18170 = x17565;
        double x18171 = x18170[x18163];
        char** x18194 = x17589;
        char* x18195 = x18194[x18163];
        int* x18214 = x17609;
        int x18215 = x18214[x18163];
        double* x18222 = x17617;
        double x18223 = x18222[x18163];
        double* x18224 = x17619;
        double x18225 = x18224[x18163];
        double* x18226 = x17621;
        double x18227 = x18226[x18163];
        long x18247 = x17642[x18163];
        x18159 = x18247;
        bool x18249 = x18215 == x18138;
        if (x18249) {
          char x18257 = x18195[0L];
          long x18258 = x18257 * 41L;
          char x18259 = x18195[1L];
          long x18260 = x18258 + x18259;
          long x18261 = x18260 * 41L;
          char x18262 = x18195[2L];
          long x18263 = x18261 + x18262;
          long x18264 = x18263 * 41L;
          char x18265 = x18195[3L];
          long x18266 = x18264 + x18265;
          long x18267 = x18266 * 41L;
          long x18268 = x18267 + x18255;
          long x18269 = x18268 & x802;
          long x18270 = x18269;
          struct Anon1506628547* x18271 = x17650;
          struct Anon1506628547 x18272 = x18271[x18269];
          struct Anon1506628547 x18273 = x18272;
          bool x18274 = x18272.exists;;
          bool x18284 = x18274;
          if (x18274) {
            struct Anon1506628547 x18275 = x18273;
            struct Anon1548200872 x18276 = x18275.key;;
            char* x18277 = x18276.NATION;;
            bool x18278 = strcmp(x18277,x18195) == 0;;
            bool x18281 = x18278;
            if (x18278) {
              int x18279 = x18276.O_YEAR;;
              bool x18280 = x18279 == x18255;
              x18281 = x18280;
            }
            bool x18282 = x18281;
            x18284 = x18282;
          }
          bool x18285 = x18284;
          if (x18285) {
            struct Anon2052879266 x18286 = x18272.aggs;;
            struct Anon1548200872 x18294 = x18272.key;;
            double x18287 = x18286._0;;
            double x18288 = 1.0 - x18227;
            double x18289 = x18225 * x18288;
            double x18290 = x18171 * x18223;
            double x18291 = x18289 - x18290;
            double x18292 = x18287 + x18291;
            struct Anon2052879266 x18293;
            x18293._0 = x18292;
            struct Anon1506628547 x18295;
            x18295.exists = true;
            x18295.key = x18294;
            x18295.aggs = x18293;
            x18271[x18269] = x18295;
          } else {
            double x18288 = 1.0 - x18227;
            double x18289 = x18225 * x18288;
            double x18290 = x18171 * x18223;
            double x18291 = x18289 - x18290;
            struct Anon1548200872 x18256;
            x18256.NATION = x18195;
            x18256.O_YEAR = x18255;
            struct Anon2052879266 x18329;
            x18329._0 = x18291;
            struct Anon1506628547 x18330;
            x18330.exists = true;
            x18330.key = x18256;
            x18330.aggs = x18329;
            for (;;) {
              struct Anon1506628547 x18298 = x18273;
              bool x18299 = x18298.exists;;
              bool x18339;
              if (x18299) {
                struct Anon1548200872 x18300 = x18298.key;;
                char* x18301 = x18300.NATION;;
                bool x18302 = strcmp(x18301,x18195) == 0;;
                bool x18305 = x18302;
                if (x18302) {
                  int x18303 = x18300.O_YEAR;;
                  bool x18304 = x18303 == x18255;
                  x18305 = x18304;
                }
                bool x18306 = x18305;
                bool x18326;
                if (x18306) {
                  struct Anon2052879266 x18307 = x18298.aggs;;
                  long x18311 = x18270;
                  struct Anon1506628547* x18313 = x17650;
                  double x18308 = x18307._0;;
                  double x18309 = x18308 + x18291;
                  struct Anon2052879266 x18310;
                  x18310._0 = x18309;
                  struct Anon1506628547 x18312;
                  x18312.exists = true;
                  x18312.key = x18300;
                  x18312.aggs = x18310;
                  x18313[x18311] = x18312;
                  x18326 = false;
                } else {
                  long x18316 = x18270;
                  long x18317 = x18316 + 1L;
                  long x18318 = x18317 % x802;
                  x18270 = x18318;
                  struct Anon1506628547* x18320 = x17650;
                  struct Anon1506628547 x18321 = x18320[x18318];
                  x18273 = x18321;
                  x18326 = true;
                }
                x18339 = x18326;
              } else {
                long x18328 = x18270;
                struct Anon1506628547* x18331 = x17650;
                x18331[x18328] = x18330;
                long x18333 = x17651;
                x17652[x18333] = x18328;
                x17651 = x17651 + 1L;
                x18339 = false;
              }
              if (!x18339) break;
            }
          }
        } else {
        }
      }
    }
    long x18352 = x17651;
    long x18354;
    for(x18354=0L; x18354 < x18352; x18354++) {
      long x18355 = x17652[x18354];
      struct Anon1506628547* x18356 = x17650;
      struct Anon1506628547 x18357 = x18356[x18355];
      if (x975) {
      } else {
        struct Anon1548200872 x18360 = x18357.key;;
        struct Anon2052879266 x18364 = x18357.aggs;;
        char* x18361 = x18360.NATION;;
        int x18362 = strlen(x18361);
        int x18363 = x18360.O_YEAR;;
        double x18365 = x18364._0;;
        printf("%.*s|%d|%.4f\n",x18362,x18361,x18363,x18365);
        x17663 = x17663 + 1L;
      }
    }
    long x18372 = x17663;
    printf("(%d rows)\n",x18372);
    gettimeofday(&x18376, NULL);
    timeval_subtract(&x18377, &x18376, &x18375);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x18377.tv_sec * 1000) + (x18377.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
