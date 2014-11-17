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

struct Anon0 {
struct Anon1487164486 left;
struct Anon920667905 right;
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

struct Anon668992598 {
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
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

struct Anon1267496251 {
bool exists;
struct Anon1978526630 key;
struct Anon2052879266 aggs;
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

struct Anon1724963693 {
bool exists;
struct Anon668992598 key;
struct Anon2052879266 aggs;
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
int main(int x29840, char** x29841) {
  long x29842 = 0L;
  long x6 = DEFAULT_INPUT_SIZE;
  long x29843 = x6;
  long x29844 = 0L;
  int* x29845 = (int*)malloc(x6 * sizeof(int));
  int* x29846 = x29845;
  double* x29853 = (double*)malloc(x6 * sizeof(double));
  double* x29854 = x29853;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  long x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    long x29877 = x29842;
    bool x29878 = x29877 < x3;
    if (!x29878) break;
    int x29881 = 0;
    for (;;) {
      long x29882 = x29842;
      char x29883 = x4[x29882];
      bool x29884 = x29883 != '|';
      bool x29889 = x29884;
      if (x29884) {
        long x29885 = x29842;
        char x29886 = x4[x29885];
        bool x29887 = x29886 != '\n';
        x29889 = x29887;
      }
      bool x29890 = x29889;
      if (!x29890) break;
      int x29892 = x29881;
      long x29894 = x29842;
      int x29893 = x29892 * 10;
      char x29895 = x4[x29894];
      char x29896 = x29895 - '0';
      int x29897 = x29893 + x29896;
      x29881 = x29897;
      x29842 = x29842 + 1;
    }
    x29842 = x29842 + 1;
    int x29903 = x29881;
    for (;;) {
      long x29906 = x29842;
      char x29907 = x4[x29906];
      bool x29908 = x29907 != '|';
      bool x29913 = x29908;
      if (x29908) {
        long x29909 = x29842;
        char x29910 = x4[x29909];
        bool x29911 = x29910 != '\n';
        x29913 = x29911;
      }
      bool x29914 = x29913;
      if (!x29914) break;
      x29842 = x29842 + 1;
    }
    x29842 = x29842 + 1;
    for (;;) {
      long x29930 = x29842;
      char x29931 = x4[x29930];
      bool x29932 = x29931 != '|';
      bool x29937 = x29932;
      if (x29932) {
        long x29933 = x29842;
        char x29934 = x4[x29933];
        bool x29935 = x29934 != '\n';
        x29937 = x29935;
      }
      bool x29938 = x29937;
      if (!x29938) break;
      x29842 = x29842 + 1;
    }
    x29842 = x29842 + 1;
    for (;;) {
      long x29954 = x29842;
      char x29955 = x4[x29954];
      bool x29956 = x29955 != '|';
      bool x29961 = x29956;
      if (x29956) {
        long x29957 = x29842;
        char x29958 = x4[x29957];
        bool x29959 = x29958 != '\n';
        x29961 = x29959;
      }
      bool x29962 = x29961;
      if (!x29962) break;
      x29842 = x29842 + 1;
    }
    x29842 = x29842 + 1;
    int x29977 = 0;
    int x29978 = 1;
    for (;;) {
      long x29979 = x29842;
      char x29980 = x4[x29979];
      bool x29981 = x29980 != '.';
      bool x29986 = x29981;
      if (x29981) {
        long x29982 = x29842;
        char x29983 = x4[x29982];
        bool x29984 = x29983 != '|';
        x29986 = x29984;
      }
      bool x29987 = x29986;
      bool x29992 = x29987;
      if (x29987) {
        long x29988 = x29842;
        char x29989 = x4[x29988];
        bool x29990 = x29989 != '\n';
        x29992 = x29990;
      }
      bool x29993 = x29992;
      if (!x29993) break;
      int x29995 = x29977;
      long x29997 = x29842;
      int x29996 = x29995 * 10;
      char x29998 = x4[x29997];
      char x29999 = x29998 - '0';
      int x30000 = x29996 + x29999;
      x29977 = x30000;
      x29842 = x29842 + 1;
    }
    long x30005 = x29842;
    char x30006 = x4[x30005];
    bool x30007 = x30006 == '.';
    if (x30007) {
      x29842 = x29842 + 1;
      for (;;) {
        long x30009 = x29842;
        char x30010 = x4[x30009];
        bool x30011 = x30010 != '|';
        bool x30016 = x30011;
        if (x30011) {
          long x30012 = x29842;
          char x30013 = x4[x30012];
          bool x30014 = x30013 != '\n';
          x30016 = x30014;
        }
        bool x30017 = x30016;
        if (!x30017) break;
        int x30019 = x29977;
        long x30021 = x29842;
        int x30020 = x30019 * 10;
        char x30022 = x4[x30021];
        char x30023 = x30022 - '0';
        int x30024 = x30020 + x30023;
        x29977 = x30024;
        int x30026 = x29978;
        int x30027 = x30026 * 10;
        x29978 = x30027;
        x29842 = x29842 + 1;
      }
    } else {
    }
    x29842 = x29842 + 1;
    int x30036 = x29977;
    int x30038 = x29978;
    for (;;) {
      long x30044 = x29842;
      char x30045 = x4[x30044];
      bool x30046 = x30045 != '.';
      bool x30051 = x30046;
      if (x30046) {
        long x30047 = x29842;
        char x30048 = x4[x30047];
        bool x30049 = x30048 != '|';
        x30051 = x30049;
      }
      bool x30052 = x30051;
      bool x30057 = x30052;
      if (x30052) {
        long x30053 = x29842;
        char x30054 = x4[x30053];
        bool x30055 = x30054 != '\n';
        x30057 = x30055;
      }
      bool x30058 = x30057;
      if (!x30058) break;
      x29842 = x29842 + 1;
    }
    long x30070 = x29842;
    char x30071 = x4[x30070];
    bool x30072 = x30071 == '.';
    if (x30072) {
      x29842 = x29842 + 1;
      for (;;) {
        long x30074 = x29842;
        char x30075 = x4[x30074];
        bool x30076 = x30075 != '|';
        bool x30081 = x30076;
        if (x30076) {
          long x30077 = x29842;
          char x30078 = x4[x30077];
          bool x30079 = x30078 != '\n';
          x30081 = x30079;
        }
        bool x30082 = x30081;
        if (!x30082) break;
        x29842 = x29842 + 1;
      }
    } else {
    }
    x29842 = x29842 + 1;
    for (;;) {
      long x30109 = x29842;
      char x30110 = x4[x30109];
      bool x30111 = x30110 != '.';
      bool x30116 = x30111;
      if (x30111) {
        long x30112 = x29842;
        char x30113 = x4[x30112];
        bool x30114 = x30113 != '|';
        x30116 = x30114;
      }
      bool x30117 = x30116;
      bool x30122 = x30117;
      if (x30117) {
        long x30118 = x29842;
        char x30119 = x4[x30118];
        bool x30120 = x30119 != '\n';
        x30122 = x30120;
      }
      bool x30123 = x30122;
      if (!x30123) break;
      x29842 = x29842 + 1;
    }
    long x30135 = x29842;
    char x30136 = x4[x30135];
    bool x30137 = x30136 == '.';
    if (x30137) {
      x29842 = x29842 + 1;
      for (;;) {
        long x30139 = x29842;
        char x30140 = x4[x30139];
        bool x30141 = x30140 != '|';
        bool x30146 = x30141;
        if (x30141) {
          long x30142 = x29842;
          char x30143 = x4[x30142];
          bool x30144 = x30143 != '\n';
          x30146 = x30144;
        }
        bool x30147 = x30146;
        if (!x30147) break;
        x29842 = x29842 + 1;
      }
    } else {
    }
    x29842 = x29842 + 1;
    for (;;) {
      long x30174 = x29842;
      char x30175 = x4[x30174];
      bool x30176 = x30175 != '.';
      bool x30181 = x30176;
      if (x30176) {
        long x30177 = x29842;
        char x30178 = x4[x30177];
        bool x30179 = x30178 != '|';
        x30181 = x30179;
      }
      bool x30182 = x30181;
      bool x30187 = x30182;
      if (x30182) {
        long x30183 = x29842;
        char x30184 = x4[x30183];
        bool x30185 = x30184 != '\n';
        x30187 = x30185;
      }
      bool x30188 = x30187;
      if (!x30188) break;
      x29842 = x29842 + 1;
    }
    long x30200 = x29842;
    char x30201 = x4[x30200];
    bool x30202 = x30201 == '.';
    if (x30202) {
      x29842 = x29842 + 1;
      for (;;) {
        long x30204 = x29842;
        char x30205 = x4[x30204];
        bool x30206 = x30205 != '|';
        bool x30211 = x30206;
        if (x30206) {
          long x30207 = x29842;
          char x30208 = x4[x30207];
          bool x30209 = x30208 != '\n';
          x30211 = x30209;
        }
        bool x30212 = x30211;
        if (!x30212) break;
        x29842 = x29842 + 1;
      }
    } else {
    }
    x29842 = x29842 + 1;
    x29842 = x29842 + 2;
    x29842 = x29842 + 2;
    for (;;) {
      long x30244 = x29842;
      char x30245 = x4[x30244];
      bool x30246 = x30245 != '-';
      bool x30251 = x30246;
      if (x30246) {
        long x30247 = x29842;
        char x30248 = x4[x30247];
        bool x30249 = x30248 != '\n';
        x30251 = x30249;
      }
      bool x30252 = x30251;
      if (!x30252) break;
      x29842 = x29842 + 1;
    }
    x29842 = x29842 + 1;
    for (;;) {
      long x30268 = x29842;
      char x30269 = x4[x30268];
      bool x30270 = x30269 != '-';
      bool x30275 = x30270;
      if (x30270) {
        long x30271 = x29842;
        char x30272 = x4[x30271];
        bool x30273 = x30272 != '\n';
        x30275 = x30273;
      }
      bool x30276 = x30275;
      if (!x30276) break;
      x29842 = x29842 + 1;
    }
    x29842 = x29842 + 1;
    for (;;) {
      long x30292 = x29842;
      char x30293 = x4[x30292];
      bool x30294 = x30293 != '|';
      bool x30299 = x30294;
      if (x30294) {
        long x30295 = x29842;
        char x30296 = x4[x30295];
        bool x30297 = x30296 != '\n';
        x30299 = x30297;
      }
      bool x30300 = x30299;
      if (!x30300) break;
      x29842 = x29842 + 1;
    }
    x29842 = x29842 + 1;
    for (;;) {
      long x30320 = x29842;
      char x30321 = x4[x30320];
      bool x30322 = x30321 != '-';
      bool x30327 = x30322;
      if (x30322) {
        long x30323 = x29842;
        char x30324 = x4[x30323];
        bool x30325 = x30324 != '\n';
        x30327 = x30325;
      }
      bool x30328 = x30327;
      if (!x30328) break;
      x29842 = x29842 + 1;
    }
    x29842 = x29842 + 1;
    for (;;) {
      long x30344 = x29842;
      char x30345 = x4[x30344];
      bool x30346 = x30345 != '-';
      bool x30351 = x30346;
      if (x30346) {
        long x30347 = x29842;
        char x30348 = x4[x30347];
        bool x30349 = x30348 != '\n';
        x30351 = x30349;
      }
      bool x30352 = x30351;
      if (!x30352) break;
      x29842 = x29842 + 1;
    }
    x29842 = x29842 + 1;
    for (;;) {
      long x30368 = x29842;
      char x30369 = x4[x30368];
      bool x30370 = x30369 != '|';
      bool x30375 = x30370;
      if (x30370) {
        long x30371 = x29842;
        char x30372 = x4[x30371];
        bool x30373 = x30372 != '\n';
        x30375 = x30373;
      }
      bool x30376 = x30375;
      if (!x30376) break;
      x29842 = x29842 + 1;
    }
    x29842 = x29842 + 1;
    for (;;) {
      long x30396 = x29842;
      char x30397 = x4[x30396];
      bool x30398 = x30397 != '-';
      bool x30403 = x30398;
      if (x30398) {
        long x30399 = x29842;
        char x30400 = x4[x30399];
        bool x30401 = x30400 != '\n';
        x30403 = x30401;
      }
      bool x30404 = x30403;
      if (!x30404) break;
      x29842 = x29842 + 1;
    }
    x29842 = x29842 + 1;
    for (;;) {
      long x30420 = x29842;
      char x30421 = x4[x30420];
      bool x30422 = x30421 != '-';
      bool x30427 = x30422;
      if (x30422) {
        long x30423 = x29842;
        char x30424 = x4[x30423];
        bool x30425 = x30424 != '\n';
        x30427 = x30425;
      }
      bool x30428 = x30427;
      if (!x30428) break;
      x29842 = x29842 + 1;
    }
    x29842 = x29842 + 1;
    for (;;) {
      long x30444 = x29842;
      char x30445 = x4[x30444];
      bool x30446 = x30445 != '|';
      bool x30451 = x30446;
      if (x30446) {
        long x30447 = x29842;
        char x30448 = x4[x30447];
        bool x30449 = x30448 != '\n';
        x30451 = x30449;
      }
      bool x30452 = x30451;
      if (!x30452) break;
      x29842 = x29842 + 1;
    }
    x29842 = x29842 + 1;
    for (;;) {
      long x30471 = x29842;
      char x30472 = x4[x30471];
      bool x30473 = x30472 != '|';
      bool x30478 = x30473;
      if (x30473) {
        long x30474 = x29842;
        char x30475 = x4[x30474];
        bool x30476 = x30475 != '\n';
        x30478 = x30476;
      }
      bool x30479 = x30478;
      if (!x30479) break;
      x29842 = x29842 + 1;
    }
    x29842 = x29842 + 1;
    for (;;) {
      long x30489 = x29842;
      char x30490 = x4[x30489];
      bool x30491 = x30490 != '|';
      bool x30496 = x30491;
      if (x30491) {
        long x30492 = x29842;
        char x30493 = x4[x30492];
        bool x30494 = x30493 != '\n';
        x30496 = x30494;
      }
      bool x30497 = x30496;
      if (!x30497) break;
      x29842 = x29842 + 1;
    }
    x29842 = x29842 + 1;
    for (;;) {
      long x30507 = x29842;
      char x30508 = x4[x30507];
      bool x30509 = x30508 != '|';
      bool x30514 = x30509;
      if (x30509) {
        long x30510 = x29842;
        char x30511 = x4[x30510];
        bool x30512 = x30511 != '\n';
        x30514 = x30512;
      }
      bool x30515 = x30514;
      if (!x30515) break;
      x29842 = x29842 + 1;
    }
    x29842 = x29842 + 1;
    long x30525 = x29844;
    long x30526 = x29843;
    bool x30527 = x30525 == x30526;
    if (x30527) {
      long x30528 = x30526 * 4L;
      x29843 = x30528;
      printf("buffer.resize %d\n",x30528);
      int* x30531 = x29846;
      int* x30532 = (int*)realloc(x30531,x30528 * sizeof(int));
      x29846 = x30532;
      double* x30543 = x29854;
      double* x30544 = (double*)realloc(x30543,x30528 * sizeof(double));
      x29854 = x30544;
    } else {
    }
    int* x30581 = x29846;
    x30581[x30525] = x29903;
    double* x30589 = x29854;
    double x30037 = (double)x30036;
    double x30039 = (double)x30038;
    double x30040 = x30037 / x30039;
    x30589[x30525] = x30040;
    x29844 = x29844 + 1;
  }
  long x30616 = 0L;
  long x30617 = x6;
  long x30618 = 0L;
  int* x30619 = (int*)malloc(x6 * sizeof(int));
  int* x30620 = x30619;
  int* x30621 = (int*)malloc(x6 * sizeof(int));
  int* x30622 = x30621;
  double* x30625 = (double*)malloc(x6 * sizeof(double));
  double* x30626 = x30625;
  long* x30627 = (long*)malloc(x6 * sizeof(long));
  long* x30628 = x30627;
  int x3371 = open("../databases/sf2/orders.tbl",0);
  long x3372 = fsize(x3371);
  char* x3373 = mmap(0, x3372, PROT_READ, MAP_FILE | MAP_SHARED, x3371, 0);
  for (;;) {
    long x30637 = x30616;
    bool x30638 = x30637 < x3372;
    if (!x30638) break;
    int x30641 = 0;
    for (;;) {
      long x30642 = x30616;
      char x30643 = x3373[x30642];
      bool x30644 = x30643 != '|';
      bool x30649 = x30644;
      if (x30644) {
        long x30645 = x30616;
        char x30646 = x3373[x30645];
        bool x30647 = x30646 != '\n';
        x30649 = x30647;
      }
      bool x30650 = x30649;
      if (!x30650) break;
      int x30652 = x30641;
      long x30654 = x30616;
      int x30653 = x30652 * 10;
      char x30655 = x3373[x30654];
      char x30656 = x30655 - '0';
      int x30657 = x30653 + x30656;
      x30641 = x30657;
      x30616 = x30616 + 1;
    }
    x30616 = x30616 + 1;
    int x30663 = x30641;
    int x30665 = 0;
    for (;;) {
      long x30666 = x30616;
      char x30667 = x3373[x30666];
      bool x30668 = x30667 != '|';
      bool x30673 = x30668;
      if (x30668) {
        long x30669 = x30616;
        char x30670 = x3373[x30669];
        bool x30671 = x30670 != '\n';
        x30673 = x30671;
      }
      bool x30674 = x30673;
      if (!x30674) break;
      int x30676 = x30665;
      long x30678 = x30616;
      int x30677 = x30676 * 10;
      char x30679 = x3373[x30678];
      char x30680 = x30679 - '0';
      int x30681 = x30677 + x30680;
      x30665 = x30681;
      x30616 = x30616 + 1;
    }
    x30616 = x30616 + 1;
    int x30687 = x30665;
    x30616 = x30616 + 2;
    int x30692 = 0;
    int x30693 = 1;
    for (;;) {
      long x30694 = x30616;
      char x30695 = x3373[x30694];
      bool x30696 = x30695 != '.';
      bool x30701 = x30696;
      if (x30696) {
        long x30697 = x30616;
        char x30698 = x3373[x30697];
        bool x30699 = x30698 != '|';
        x30701 = x30699;
      }
      bool x30702 = x30701;
      bool x30707 = x30702;
      if (x30702) {
        long x30703 = x30616;
        char x30704 = x3373[x30703];
        bool x30705 = x30704 != '\n';
        x30707 = x30705;
      }
      bool x30708 = x30707;
      if (!x30708) break;
      int x30710 = x30692;
      long x30712 = x30616;
      int x30711 = x30710 * 10;
      char x30713 = x3373[x30712];
      char x30714 = x30713 - '0';
      int x30715 = x30711 + x30714;
      x30692 = x30715;
      x30616 = x30616 + 1;
    }
    long x30720 = x30616;
    char x30721 = x3373[x30720];
    bool x30722 = x30721 == '.';
    if (x30722) {
      x30616 = x30616 + 1;
      for (;;) {
        long x30724 = x30616;
        char x30725 = x3373[x30724];
        bool x30726 = x30725 != '|';
        bool x30731 = x30726;
        if (x30726) {
          long x30727 = x30616;
          char x30728 = x3373[x30727];
          bool x30729 = x30728 != '\n';
          x30731 = x30729;
        }
        bool x30732 = x30731;
        if (!x30732) break;
        int x30734 = x30692;
        long x30736 = x30616;
        int x30735 = x30734 * 10;
        char x30737 = x3373[x30736];
        char x30738 = x30737 - '0';
        int x30739 = x30735 + x30738;
        x30692 = x30739;
        int x30741 = x30693;
        int x30742 = x30741 * 10;
        x30693 = x30742;
        x30616 = x30616 + 1;
      }
    } else {
    }
    x30616 = x30616 + 1;
    int x30751 = x30692;
    int x30753 = x30693;
    int x30757 = 0;
    for (;;) {
      long x30758 = x30616;
      char x30759 = x3373[x30758];
      bool x30760 = x30759 != '-';
      bool x30765 = x30760;
      if (x30760) {
        long x30761 = x30616;
        char x30762 = x3373[x30761];
        bool x30763 = x30762 != '\n';
        x30765 = x30763;
      }
      bool x30766 = x30765;
      if (!x30766) break;
      int x30768 = x30757;
      long x30770 = x30616;
      int x30769 = x30768 * 10;
      char x30771 = x3373[x30770];
      char x30772 = x30771 - '0';
      int x30773 = x30769 + x30772;
      x30757 = x30773;
      x30616 = x30616 + 1;
    }
    x30616 = x30616 + 1;
    int x30779 = x30757;
    int x30781 = 0;
    for (;;) {
      long x30782 = x30616;
      char x30783 = x3373[x30782];
      bool x30784 = x30783 != '-';
      bool x30789 = x30784;
      if (x30784) {
        long x30785 = x30616;
        char x30786 = x3373[x30785];
        bool x30787 = x30786 != '\n';
        x30789 = x30787;
      }
      bool x30790 = x30789;
      if (!x30790) break;
      int x30792 = x30781;
      long x30794 = x30616;
      int x30793 = x30792 * 10;
      char x30795 = x3373[x30794];
      char x30796 = x30795 - '0';
      int x30797 = x30793 + x30796;
      x30781 = x30797;
      x30616 = x30616 + 1;
    }
    x30616 = x30616 + 1;
    int x30803 = x30781;
    int x30805 = 0;
    for (;;) {
      long x30806 = x30616;
      char x30807 = x3373[x30806];
      bool x30808 = x30807 != '|';
      bool x30813 = x30808;
      if (x30808) {
        long x30809 = x30616;
        char x30810 = x3373[x30809];
        bool x30811 = x30810 != '\n';
        x30813 = x30811;
      }
      bool x30814 = x30813;
      if (!x30814) break;
      int x30816 = x30805;
      long x30818 = x30616;
      int x30817 = x30816 * 10;
      char x30819 = x3373[x30818];
      char x30820 = x30819 - '0';
      int x30821 = x30817 + x30820;
      x30805 = x30821;
      x30616 = x30616 + 1;
    }
    x30616 = x30616 + 1;
    int x30827 = x30805;
    for (;;) {
      long x30833 = x30616;
      char x30834 = x3373[x30833];
      bool x30835 = x30834 != '|';
      bool x30840 = x30835;
      if (x30835) {
        long x30836 = x30616;
        char x30837 = x3373[x30836];
        bool x30838 = x30837 != '\n';
        x30840 = x30838;
      }
      bool x30841 = x30840;
      if (!x30841) break;
      x30616 = x30616 + 1;
    }
    x30616 = x30616 + 1;
    for (;;) {
      long x30851 = x30616;
      char x30852 = x3373[x30851];
      bool x30853 = x30852 != '|';
      bool x30858 = x30853;
      if (x30853) {
        long x30854 = x30616;
        char x30855 = x3373[x30854];
        bool x30856 = x30855 != '\n';
        x30858 = x30856;
      }
      bool x30859 = x30858;
      if (!x30859) break;
      x30616 = x30616 + 1;
    }
    x30616 = x30616 + 1;
    for (;;) {
      long x30870 = x30616;
      char x30871 = x3373[x30870];
      bool x30872 = x30871 != '|';
      bool x30877 = x30872;
      if (x30872) {
        long x30873 = x30616;
        char x30874 = x3373[x30873];
        bool x30875 = x30874 != '\n';
        x30877 = x30875;
      }
      bool x30878 = x30877;
      if (!x30878) break;
      x30616 = x30616 + 1;
    }
    x30616 = x30616 + 1;
    for (;;) {
      long x30893 = x30616;
      char x30894 = x3373[x30893];
      bool x30895 = x30894 != '|';
      bool x30900 = x30895;
      if (x30895) {
        long x30896 = x30616;
        char x30897 = x3373[x30896];
        bool x30898 = x30897 != '\n';
        x30900 = x30898;
      }
      bool x30901 = x30900;
      if (!x30901) break;
      x30616 = x30616 + 1;
    }
    x30616 = x30616 + 1;
    long x30911 = x30618;
    long x30912 = x30617;
    bool x30913 = x30911 == x30912;
    if (x30913) {
      long x30914 = x30912 * 4L;
      x30617 = x30914;
      printf("buffer.resize %d\n",x30914);
      int* x30917 = x30620;
      int* x30918 = (int*)realloc(x30917,x30914 * sizeof(int));
      x30620 = x30918;
      int* x30920 = x30622;
      int* x30921 = (int*)realloc(x30920,x30914 * sizeof(int));
      x30622 = x30921;
      double* x30926 = x30626;
      double* x30927 = (double*)realloc(x30926,x30914 * sizeof(double));
      x30626 = x30927;
      long* x30929 = x30628;
      long* x30930 = (long*)realloc(x30929,x30914 * sizeof(long));
      x30628 = x30930;
    } else {
    }
    int* x30946 = x30620;
    x30946[x30911] = x30663;
    int* x30948 = x30622;
    x30948[x30911] = x30687;
    double* x30952 = x30626;
    double x30752 = (double)x30751;
    double x30754 = (double)x30753;
    double x30755 = x30752 / x30754;
    x30952[x30911] = x30755;
    long* x30954 = x30628;
    long x30828 = x30779 * 10000L;
    long x30829 = x30803 * 100L;
    long x30830 = x30828 + x30829;
    long x30831 = x30830 + x30827;
    x30954[x30911] = x30831;
    x30618 = x30618 + 1;
  }
  long x30967 = 0L;
  long x30968 = x6;
  long x30969 = 0L;
  int* x30970 = (int*)malloc(x6 * sizeof(int));
  int* x30971 = x30970;
  char** x30972 = (char**)malloc(x6 * sizeof(char*));
  char** x30973 = x30972;
  int x3725 = open("../databases/sf2/customer.tbl",0);
  long x3726 = fsize(x3725);
  char* x3727 = mmap(0, x3726, PROT_READ, MAP_FILE | MAP_SHARED, x3725, 0);
  for (;;) {
    long x30986 = x30967;
    bool x30987 = x30986 < x3726;
    if (!x30987) break;
    int x30990 = 0;
    for (;;) {
      long x30991 = x30967;
      char x30992 = x3727[x30991];
      bool x30993 = x30992 != '|';
      bool x30998 = x30993;
      if (x30993) {
        long x30994 = x30967;
        char x30995 = x3727[x30994];
        bool x30996 = x30995 != '\n';
        x30998 = x30996;
      }
      bool x30999 = x30998;
      if (!x30999) break;
      int x31001 = x30990;
      long x31003 = x30967;
      int x31002 = x31001 * 10;
      char x31004 = x3727[x31003];
      char x31005 = x31004 - '0';
      int x31006 = x31002 + x31005;
      x30990 = x31006;
      x30967 = x30967 + 1;
    }
    x30967 = x30967 + 1;
    int x31012 = x30990;
    long x31013 = x30967;
    for (;;) {
      long x31014 = x30967;
      char x31015 = x3727[x31014];
      bool x31016 = x31015 != '|';
      bool x31021 = x31016;
      if (x31016) {
        long x31017 = x30967;
        char x31018 = x3727[x31017];
        bool x31019 = x31018 != '\n';
        x31021 = x31019;
      }
      bool x31022 = x31021;
      if (!x31022) break;
      x30967 = x30967 + 1;
    }
    x30967 = x30967 + 1;
    for (;;) {
      long x31032 = x30967;
      char x31033 = x3727[x31032];
      bool x31034 = x31033 != '|';
      bool x31039 = x31034;
      if (x31034) {
        long x31035 = x30967;
        char x31036 = x3727[x31035];
        bool x31037 = x31036 != '\n';
        x31039 = x31037;
      }
      bool x31040 = x31039;
      if (!x31040) break;
      x30967 = x30967 + 1;
    }
    x30967 = x30967 + 1;
    for (;;) {
      long x31051 = x30967;
      char x31052 = x3727[x31051];
      bool x31053 = x31052 != '|';
      bool x31058 = x31053;
      if (x31053) {
        long x31054 = x30967;
        char x31055 = x3727[x31054];
        bool x31056 = x31055 != '\n';
        x31058 = x31056;
      }
      bool x31059 = x31058;
      if (!x31059) break;
      x30967 = x30967 + 1;
    }
    x30967 = x30967 + 1;
    for (;;) {
      long x31074 = x30967;
      char x31075 = x3727[x31074];
      bool x31076 = x31075 != '|';
      bool x31081 = x31076;
      if (x31076) {
        long x31077 = x30967;
        char x31078 = x3727[x31077];
        bool x31079 = x31078 != '\n';
        x31081 = x31079;
      }
      bool x31082 = x31081;
      if (!x31082) break;
      x30967 = x30967 + 1;
    }
    x30967 = x30967 + 1;
    for (;;) {
      long x31094 = x30967;
      char x31095 = x3727[x31094];
      bool x31096 = x31095 != '.';
      bool x31101 = x31096;
      if (x31096) {
        long x31097 = x30967;
        char x31098 = x3727[x31097];
        bool x31099 = x31098 != '|';
        x31101 = x31099;
      }
      bool x31102 = x31101;
      bool x31107 = x31102;
      if (x31102) {
        long x31103 = x30967;
        char x31104 = x3727[x31103];
        bool x31105 = x31104 != '\n';
        x31107 = x31105;
      }
      bool x31108 = x31107;
      if (!x31108) break;
      x30967 = x30967 + 1;
    }
    long x31120 = x30967;
    char x31121 = x3727[x31120];
    bool x31122 = x31121 == '.';
    if (x31122) {
      x30967 = x30967 + 1;
      for (;;) {
        long x31124 = x30967;
        char x31125 = x3727[x31124];
        bool x31126 = x31125 != '|';
        bool x31131 = x31126;
        if (x31126) {
          long x31127 = x30967;
          char x31128 = x3727[x31127];
          bool x31129 = x31128 != '\n';
          x31131 = x31129;
        }
        bool x31132 = x31131;
        if (!x31132) break;
        x30967 = x30967 + 1;
      }
    } else {
    }
    x30967 = x30967 + 1;
    for (;;) {
      long x31157 = x30967;
      char x31158 = x3727[x31157];
      bool x31159 = x31158 != '|';
      bool x31164 = x31159;
      if (x31159) {
        long x31160 = x30967;
        char x31161 = x3727[x31160];
        bool x31162 = x31161 != '\n';
        x31164 = x31162;
      }
      bool x31165 = x31164;
      if (!x31165) break;
      x30967 = x30967 + 1;
    }
    x30967 = x30967 + 1;
    for (;;) {
      long x31175 = x30967;
      char x31176 = x3727[x31175];
      bool x31177 = x31176 != '|';
      bool x31182 = x31177;
      if (x31177) {
        long x31178 = x30967;
        char x31179 = x3727[x31178];
        bool x31180 = x31179 != '\n';
        x31182 = x31180;
      }
      bool x31183 = x31182;
      if (!x31183) break;
      x30967 = x30967 + 1;
    }
    x30967 = x30967 + 1;
    long x31193 = x30969;
    long x31194 = x30968;
    bool x31195 = x31193 == x31194;
    if (x31195) {
      long x31196 = x31194 * 4L;
      x30968 = x31196;
      printf("buffer.resize %d\n",x31196);
      int* x31199 = x30971;
      int* x31200 = (int*)realloc(x31199,x31196 * sizeof(int));
      x30971 = x31200;
      char** x31202 = x30973;
      char** x31203 = (char**)realloc(x31202,x31196 * sizeof(char*));
      x30973 = x31203;
    } else {
    }
    int* x31225 = x30971;
    x31225[x31193] = x31012;
    char** x31227 = x30973;
    char* x31030 = x3727+x31013;
    x31227[x31193] = x31030;
    x30969 = x30969 + 1;
  }
  long x787 = DEFAULT_AGG_HASH_SIZE ;
  long x2011 = DEFAULT_JOIN_HASH_SIZE;
  long x802 = x787 - 1L;
  float x31449 = (float)300;
  double x31450 = (double)x31449;
  long x2034 = x2011 - 1L;
  long x31462 = 777L & x2034;
  int x31244;
  for(x31244=0; x31244 < 5; x31244++) {
    bool x31245 = false;
    long x31246 = 0L;
    bool x31247 = false;
    long x31248 = 0L;
    bool x31249 = false;
    long x31250 = 0L;
    struct Anon1996247276* x31252 = (struct Anon1996247276*)malloc(x787 * sizeof(struct Anon1996247276));
    struct Anon1996247276* x31253 = x31252;
    long x31254 = 0L;
    long* x31255 = (long*)malloc(x787 * sizeof(long));
    long x31256;
    for(x31256=0L; x31256 < x787; x31256++) {
      struct Anon1996247276* x31257 = x31253;
      struct Anon1996247276 x31258 = x31257[x31256];
      int x31259 = x31258.key;;
      struct Anon2052879266 x31260 = x31258.aggs;;
      struct Anon1996247276 x31261;
      x31261.exists = false;
      x31261.key = x31259;
      x31261.aggs = x31260;
      x31257[x31256] = x31261;
    }
    int* x31269 = (int*)malloc(x2011 * sizeof(int));
    int* x31270 = x31269;
    double* x31271 = (double*)malloc(x2011 * sizeof(double));
    double* x31272 = x31271;
    long x31273 = 0L;
    long* x31274 = (long*)malloc(x2011 * sizeof(long));
    long* x31275 = (long*)malloc(x2011 * sizeof(long));
    long x31276;
    for(x31276=0L; x31276 < x2011; x31276++) {
      x31274[x31276] = -1L;
    }
    double* x31286 = (double*)malloc(x2011 * sizeof(double));
    double* x31287 = x31286;
    int* x31288 = (int*)malloc(x2011 * sizeof(int));
    int* x31289 = x31288;
    int* x31290 = (int*)malloc(x2011 * sizeof(int));
    int* x31291 = x31290;
    double* x31294 = (double*)malloc(x2011 * sizeof(double));
    double* x31295 = x31294;
    long* x31296 = (long*)malloc(x2011 * sizeof(long));
    long* x31297 = x31296;
    long x31306 = 0L;
    long* x31307 = (long*)malloc(x2011 * sizeof(long));
    long* x31308 = (long*)malloc(x2011 * sizeof(long));
    long x31309;
    for(x31309=0L; x31309 < x2011; x31309++) {
      x31307[x31309] = -1L;
    }
    struct Anon854324566* x31315 = (struct Anon854324566*)malloc(x787 * sizeof(struct Anon854324566));
    struct Anon854324566* x31316 = x31315;
    long x31317 = 0L;
    long* x31318 = (long*)malloc(x787 * sizeof(long));
    long x31319;
    for(x31319=0L; x31319 < x787; x31319++) {
      struct Anon854324566* x31320 = x31316;
      struct Anon854324566 x31321 = x31320[x31319];
      struct Anon1621811895 x31322 = x31321.key;;
      struct Anon2052879266 x31323 = x31321.aggs;;
      struct Anon854324566 x31324;
      x31324.exists = false;
      x31324.key = x31322;
      x31324.aggs = x31323;
      x31320[x31319] = x31324;
    }
    int x31328 = 0;
    long x31330 = 0L;
    struct timeval x31778, x31779, x31780;
    gettimeofday(&x31778, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x31332 = x31249;
      bool x31333 = !x31332;
      bool x31338 = x31333;
      if (x31333) {
        long x31334 = x31250;
        long x31335 = x29844;
        bool x31336 = x31334 < x31335;
        x31338 = x31336;
      }
      bool x31339 = x31338;
      if (!x31339) break;
      long x31341 = x31250;
      int* x31342 = x29846;
      int x31343 = x31342[x31341];
      double* x31350 = x29854;
      double x31351 = x31350[x31341];
      x31250 = x31250 + 1;
      long x31376 = x31343 & x802;
      long x31377 = x31376;
      struct Anon1996247276* x31378 = x31253;
      struct Anon1996247276 x31379 = x31378[x31376];
      struct Anon1996247276 x31380 = x31379;
      bool x31381 = x31379.exists;;
      bool x31386 = x31381;
      if (x31381) {
        struct Anon1996247276 x31382 = x31380;
        int x31383 = x31382.key;;
        bool x31384 = x31383 == x31343;
        x31386 = x31384;
      }
      bool x31387 = x31386;
      if (x31387) {
        struct Anon2052879266 x31388 = x31379.aggs;;
        int x31392 = x31379.key;;
        double x31389 = x31388._0;;
        double x31390 = x31389 + x31351;
        struct Anon2052879266 x31391;
        x31391._0 = x31390;
        struct Anon1996247276 x31393;
        x31393.exists = true;
        x31393.key = x31392;
        x31393.aggs = x31391;
        x31378[x31376] = x31393;
      } else {
        struct Anon2052879266 x31422;
        x31422._0 = x31351;
        struct Anon1996247276 x31423;
        x31423.exists = true;
        x31423.key = x31343;
        x31423.aggs = x31422;
        for (;;) {
          struct Anon1996247276 x31396 = x31380;
          bool x31397 = x31396.exists;;
          bool x31432;
          if (x31397) {
            int x31398 = x31396.key;;
            bool x31399 = x31398 == x31343;
            bool x31419;
            if (x31399) {
              struct Anon2052879266 x31400 = x31396.aggs;;
              long x31404 = x31377;
              struct Anon1996247276* x31406 = x31253;
              double x31401 = x31400._0;;
              double x31402 = x31401 + x31351;
              struct Anon2052879266 x31403;
              x31403._0 = x31402;
              struct Anon1996247276 x31405;
              x31405.exists = true;
              x31405.key = x31398;
              x31405.aggs = x31403;
              x31406[x31404] = x31405;
              x31419 = false;
            } else {
              long x31409 = x31377;
              long x31410 = x31409 + 1L;
              long x31411 = x31410 % x802;
              x31377 = x31411;
              struct Anon1996247276* x31413 = x31253;
              struct Anon1996247276 x31414 = x31413[x31411];
              x31380 = x31414;
              x31419 = true;
            }
            x31432 = x31419;
          } else {
            long x31421 = x31377;
            struct Anon1996247276* x31424 = x31253;
            x31424[x31421] = x31423;
            long x31426 = x31254;
            x31255[x31426] = x31421;
            x31254 = x31254 + 1L;
            x31432 = false;
          }
          if (!x31432) break;
        }
      }
    }
    long x31441 = x31254;
    long x31443;
    for(x31443=0L; x31443 < x31441; x31443++) {
      long x31444 = x31255[x31443];
      struct Anon1996247276* x31445 = x31253;
      struct Anon1996247276 x31446 = x31445[x31444];
      struct Anon2052879266 x31447 = x31446.aggs;;
      double x31448 = x31447._0;;
      bool x31451 = x31448 > x31450;
      if (x31451) {
        double x31452 = x31446.key;;
        long x31453 = x31273;
        int* x31457 = x31270;
        x31457[x31453] = x31452;
        double* x31459 = x31272;
        x31459[x31453] = x31448;
        x31273 = x31273 + 1L;
        long x31463 = x31274[x31462];
        x31274[x31462] = x31453;
        x31275[x31453] = x31463;
      } else {
      }
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x31471 = x31245;
      bool x31472 = !x31471;
      bool x31477 = x31472;
      if (x31472) {
        long x31473 = x31246;
        long x31474 = x30618;
        bool x31475 = x31473 < x31474;
        x31477 = x31475;
      }
      bool x31478 = x31477;
      if (!x31478) break;
      long x31480 = x31246;
      int* x31481 = x30620;
      int x31482 = x31481[x31480];
      int* x31483 = x30622;
      int x31484 = x31483[x31480];
      double* x31487 = x30626;
      double x31488 = x31487[x31480];
      long* x31489 = x30628;
      long x31490 = x31489[x31480];
      x31246 = x31246 + 1;
      long x31502 = x31274[x31462];
      long x31503 = x31502;
      long x31548 = x31484 & x2034;
      for (;;) {
        long x31504 = x31503;
        bool x31505 = x31504 != -1;
        if (!x31505) break;
        long x31507 = x31503;
        int* x31510 = x31270;
        int x31511 = x31510[x31507];
        double* x31512 = x31272;
        double x31513 = x31512[x31507];
        long x31516 = x31275[x31507];
        x31503 = x31516;
        bool x31518 = x31482 == x31511;
        if (x31518) {
          long x31522 = x31306;
          double* x31527 = x31287;
          x31527[x31522] = x31513;
          int* x31529 = x31289;
          x31529[x31522] = x31482;
          int* x31531 = x31291;
          x31531[x31522] = x31484;
          double* x31535 = x31295;
          x31535[x31522] = x31488;
          long* x31537 = x31297;
          x31537[x31522] = x31490;
          x31306 = x31306 + 1L;
          long x31549 = x31307[x31548];
          x31307[x31548] = x31522;
          x31308[x31522] = x31549;
        } else {
        }
      }
    }
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x31559 = x31247;
      bool x31560 = !x31559;
      bool x31565 = x31560;
      if (x31560) {
        long x31561 = x31248;
        long x31562 = x30969;
        bool x31563 = x31561 < x31562;
        x31565 = x31563;
      }
      bool x31566 = x31565;
      if (!x31566) break;
      long x31568 = x31248;
      int* x31569 = x30971;
      int x31570 = x31569[x31568];
      char** x31571 = x30973;
      char* x31572 = x31571[x31568];
      x31248 = x31248 + 1;
      long x31587 = x31570 & x2034;
      long x31588 = x31307[x31587];
      long x31589 = x31588;
      char x31627 = x31572[0L];
      long x31628 = x31627 * 41L;
      char x31629 = x31572[1L];
      long x31630 = x31628 + x31629;
      long x31631 = x31630 * 41L;
      char x31632 = x31572[2L];
      long x31633 = x31631 + x31632;
      long x31634 = x31633 * 41L;
      char x31635 = x31572[3L];
      long x31636 = x31634 + x31635;
      long x31637 = x31570 * 41L;
      long x31638 = x31637 + x31636;
      long x31639 = x31638 * 41L;
      for (;;) {
        long x31590 = x31589;
        bool x31591 = x31590 != -1;
        if (!x31591) break;
        long x31593 = x31589;
        double* x31598 = x31287;
        double x31599 = x31598[x31593];
        int* x31601 = x31289;
        int x31602 = x31601[x31593];
        int* x31603 = x31291;
        int x31604 = x31603[x31593];
        double* x31607 = x31295;
        double x31608 = x31607[x31593];
        long* x31609 = x31297;
        long x31610 = x31609[x31593];
        long x31620 = x31308[x31593];
        x31589 = x31620;
        bool x31622 = x31604 == x31570;
        if (x31622) {
          long x31640 = x31639 + x31610;
          long x31641 = x31640 * 41L;
          long x31642 = x31641 + x31602;
          long x31643 = x31642 * 41L;
          long x31644 = x31643 + 777L;
          long x31645 = x31644 & x802;
          long x31646 = x31645;
          struct Anon854324566* x31647 = x31316;
          struct Anon854324566 x31648 = x31647[x31645];
          struct Anon854324566 x31649 = x31648;
          bool x31650 = x31648.exists;;
          bool x31672 = x31650;
          if (x31650) {
            struct Anon854324566 x31651 = x31649;
            struct Anon1621811895 x31652 = x31651.key;;
            char* x31653 = x31652.C_NAME;;
            bool x31654 = strcmp(x31653,x31572) == 0;;
            bool x31663 = x31654;
            if (x31654) {
              int x31655 = x31652.C_CUSTKEY;;
              bool x31656 = x31655 == x31570;
              x31663 = x31656;
            }
            bool x31664 = x31663;
            bool x31665 = x31664;
            if (x31664) {
              int x31657 = x31652.O_ORDERKEY;;
              bool x31658 = x31657 == x31602;
              x31665 = x31658;
            }
            bool x31666 = x31665;
            bool x31667 = x31666;
            if (x31666) {
              long x31659 = x31652.O_ORDERDATE;;
              bool x31660 = x31659 == x31610;
              x31667 = x31660;
            }
            bool x31668 = x31667;
            bool x31669 = x31668;
            if (x31668) {
              double x31661 = x31652.O_TOTALPRICE;;
              bool x31662 = x31661 == x31608;
              x31669 = x31662;
            }
            bool x31670 = x31669;
            x31672 = x31670;
          }
          bool x31673 = x31672;
          if (x31673) {
            struct Anon2052879266 x31674 = x31648.aggs;;
            struct Anon1621811895 x31678 = x31648.key;;
            double x31675 = x31674._0;;
            double x31676 = x31675 + x31599;
            struct Anon2052879266 x31677;
            x31677._0 = x31676;
            struct Anon854324566 x31679;
            x31679.exists = true;
            x31679.key = x31678;
            x31679.aggs = x31677;
            x31647[x31645] = x31679;
          } else {
            struct Anon2052879266 x31600;
            x31600._0 = x31599;
            struct Anon1621811895 x31626;
            x31626.C_NAME = x31572;
            x31626.C_CUSTKEY = x31570;
            x31626.O_ORDERKEY = x31602;
            x31626.O_ORDERDATE = x31610;
            x31626.O_TOTALPRICE = x31608;
            struct Anon854324566 x31725;
            x31725.exists = true;
            x31725.key = x31626;
            x31725.aggs = x31600;
            for (;;) {
              struct Anon854324566 x31682 = x31649;
              bool x31683 = x31682.exists;;
              bool x31734;
              if (x31683) {
                struct Anon1621811895 x31684 = x31682.key;;
                char* x31685 = x31684.C_NAME;;
                bool x31686 = strcmp(x31685,x31572) == 0;;
                bool x31695 = x31686;
                if (x31686) {
                  int x31687 = x31684.C_CUSTKEY;;
                  bool x31688 = x31687 == x31570;
                  x31695 = x31688;
                }
                bool x31696 = x31695;
                bool x31697 = x31696;
                if (x31696) {
                  int x31689 = x31684.O_ORDERKEY;;
                  bool x31690 = x31689 == x31602;
                  x31697 = x31690;
                }
                bool x31698 = x31697;
                bool x31699 = x31698;
                if (x31698) {
                  long x31691 = x31684.O_ORDERDATE;;
                  bool x31692 = x31691 == x31610;
                  x31699 = x31692;
                }
                bool x31700 = x31699;
                bool x31701 = x31700;
                if (x31700) {
                  double x31693 = x31684.O_TOTALPRICE;;
                  bool x31694 = x31693 == x31608;
                  x31701 = x31694;
                }
                bool x31702 = x31701;
                bool x31722;
                if (x31702) {
                  struct Anon2052879266 x31703 = x31682.aggs;;
                  long x31707 = x31646;
                  struct Anon854324566* x31709 = x31316;
                  double x31704 = x31703._0;;
                  double x31705 = x31704 + x31599;
                  struct Anon2052879266 x31706;
                  x31706._0 = x31705;
                  struct Anon854324566 x31708;
                  x31708.exists = true;
                  x31708.key = x31684;
                  x31708.aggs = x31706;
                  x31709[x31707] = x31708;
                  x31722 = false;
                } else {
                  long x31712 = x31646;
                  long x31713 = x31712 + 1L;
                  long x31714 = x31713 % x802;
                  x31646 = x31714;
                  struct Anon854324566* x31716 = x31316;
                  struct Anon854324566 x31717 = x31716[x31714];
                  x31649 = x31717;
                  x31722 = true;
                }
                x31734 = x31722;
              } else {
                long x31724 = x31646;
                struct Anon854324566* x31726 = x31316;
                x31726[x31724] = x31725;
                long x31728 = x31317;
                x31318[x31728] = x31724;
                x31317 = x31317 + 1L;
                x31734 = false;
              }
              if (!x31734) break;
            }
          }
        } else {
        }
      }
    }
    long x31747 = x31317;
    long x31749;
    for(x31749=0L; x31749 < x31747; x31749++) {
      long x31750 = x31318[x31749];
      struct Anon854324566* x31751 = x31316;
      struct Anon854324566 x31752 = x31751[x31750];
      int x31753 = x31328;
      bool x31754 = x31753 < 100;
      bool x31755 = x31754 == false;
      if (x31755) {
      } else {
        struct Anon1621811895 x31758 = x31752.key;;
        struct Anon2052879266 x31766 = x31752.aggs;;
        char* x31759 = x31758.C_NAME;;
        int x31760 = strlen(x31759);
        int x31761 = x31758.C_CUSTKEY;;
        int x31762 = x31758.O_ORDERKEY;;
        long x31763 = x31758.O_ORDERDATE;;
        char* x31764 = (char*)malloc(9 * sizeof(char));;
        snprintf(x31764, 9, "%lu", x31763);
        double x31765 = x31758.O_TOTALPRICE;;
        double x31767 = x31766._0;;
        printf("%.*s|%d|%d|%.*s|%.2f|%.2f\n",x31760,x31759,x31761,x31762,x31764,x31765,x31767);
        x31328 = x31328 + 1;
        x31330 = x31330 + 1L;
      }
    }
    long x31775 = x31330;
    printf("(%d rows)\n",x31775);
    gettimeofday(&x31779, NULL);
    timeval_subtract(&x31780, &x31779, &x31778);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x31780.tv_sec * 1000) + (x31780.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
