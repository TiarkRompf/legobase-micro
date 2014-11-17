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
int main(int x31785, char** x31786) {
  long x31787 = 0L;
  long x6 = DEFAULT_INPUT_SIZE;
  long x31788 = x6;
  long x31789 = 0L;
  int* x31792 = (int*)malloc(x6 * sizeof(int));
  int* x31793 = x31792;
  double* x31798 = (double*)malloc(x6 * sizeof(double));
  double* x31799 = x31798;
  double* x31800 = (double*)malloc(x6 * sizeof(double));
  double* x31801 = x31800;
  double* x31802 = (double*)malloc(x6 * sizeof(double));
  double* x31803 = x31802;
  char** x31816 = (char**)malloc(x6 * sizeof(char*));
  char** x31817 = x31816;
  char** x31818 = (char**)malloc(x6 * sizeof(char*));
  char** x31819 = x31818;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  long x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    long x31822 = x31787;
    bool x31823 = x31822 < x3;
    if (!x31823) break;
    for (;;) {
      long x31827 = x31787;
      char x31828 = x4[x31827];
      bool x31829 = x31828 != '|';
      bool x31834 = x31829;
      if (x31829) {
        long x31830 = x31787;
        char x31831 = x4[x31830];
        bool x31832 = x31831 != '\n';
        x31834 = x31832;
      }
      bool x31835 = x31834;
      if (!x31835) break;
      x31787 = x31787 + 1;
    }
    x31787 = x31787 + 1;
    int x31850 = 0;
    for (;;) {
      long x31851 = x31787;
      char x31852 = x4[x31851];
      bool x31853 = x31852 != '|';
      bool x31858 = x31853;
      if (x31853) {
        long x31854 = x31787;
        char x31855 = x4[x31854];
        bool x31856 = x31855 != '\n';
        x31858 = x31856;
      }
      bool x31859 = x31858;
      if (!x31859) break;
      int x31861 = x31850;
      long x31863 = x31787;
      int x31862 = x31861 * 10;
      char x31864 = x4[x31863];
      char x31865 = x31864 - '0';
      int x31866 = x31862 + x31865;
      x31850 = x31866;
      x31787 = x31787 + 1;
    }
    x31787 = x31787 + 1;
    int x31872 = x31850;
    for (;;) {
      long x31875 = x31787;
      char x31876 = x4[x31875];
      bool x31877 = x31876 != '|';
      bool x31882 = x31877;
      if (x31877) {
        long x31878 = x31787;
        char x31879 = x4[x31878];
        bool x31880 = x31879 != '\n';
        x31882 = x31880;
      }
      bool x31883 = x31882;
      if (!x31883) break;
      x31787 = x31787 + 1;
    }
    x31787 = x31787 + 1;
    for (;;) {
      long x31899 = x31787;
      char x31900 = x4[x31899];
      bool x31901 = x31900 != '|';
      bool x31906 = x31901;
      if (x31901) {
        long x31902 = x31787;
        char x31903 = x4[x31902];
        bool x31904 = x31903 != '\n';
        x31906 = x31904;
      }
      bool x31907 = x31906;
      if (!x31907) break;
      x31787 = x31787 + 1;
    }
    x31787 = x31787 + 1;
    int x31922 = 0;
    int x31923 = 1;
    for (;;) {
      long x31924 = x31787;
      char x31925 = x4[x31924];
      bool x31926 = x31925 != '.';
      bool x31931 = x31926;
      if (x31926) {
        long x31927 = x31787;
        char x31928 = x4[x31927];
        bool x31929 = x31928 != '|';
        x31931 = x31929;
      }
      bool x31932 = x31931;
      bool x31937 = x31932;
      if (x31932) {
        long x31933 = x31787;
        char x31934 = x4[x31933];
        bool x31935 = x31934 != '\n';
        x31937 = x31935;
      }
      bool x31938 = x31937;
      if (!x31938) break;
      int x31940 = x31922;
      long x31942 = x31787;
      int x31941 = x31940 * 10;
      char x31943 = x4[x31942];
      char x31944 = x31943 - '0';
      int x31945 = x31941 + x31944;
      x31922 = x31945;
      x31787 = x31787 + 1;
    }
    long x31950 = x31787;
    char x31951 = x4[x31950];
    bool x31952 = x31951 == '.';
    if (x31952) {
      x31787 = x31787 + 1;
      for (;;) {
        long x31954 = x31787;
        char x31955 = x4[x31954];
        bool x31956 = x31955 != '|';
        bool x31961 = x31956;
        if (x31956) {
          long x31957 = x31787;
          char x31958 = x4[x31957];
          bool x31959 = x31958 != '\n';
          x31961 = x31959;
        }
        bool x31962 = x31961;
        if (!x31962) break;
        int x31964 = x31922;
        long x31966 = x31787;
        int x31965 = x31964 * 10;
        char x31967 = x4[x31966];
        char x31968 = x31967 - '0';
        int x31969 = x31965 + x31968;
        x31922 = x31969;
        int x31971 = x31923;
        int x31972 = x31971 * 10;
        x31923 = x31972;
        x31787 = x31787 + 1;
      }
    } else {
    }
    x31787 = x31787 + 1;
    int x31981 = x31922;
    int x31983 = x31923;
    int x31987 = 0;
    int x31988 = 1;
    for (;;) {
      long x31989 = x31787;
      char x31990 = x4[x31989];
      bool x31991 = x31990 != '.';
      bool x31996 = x31991;
      if (x31991) {
        long x31992 = x31787;
        char x31993 = x4[x31992];
        bool x31994 = x31993 != '|';
        x31996 = x31994;
      }
      bool x31997 = x31996;
      bool x32002 = x31997;
      if (x31997) {
        long x31998 = x31787;
        char x31999 = x4[x31998];
        bool x32000 = x31999 != '\n';
        x32002 = x32000;
      }
      bool x32003 = x32002;
      if (!x32003) break;
      int x32005 = x31987;
      long x32007 = x31787;
      int x32006 = x32005 * 10;
      char x32008 = x4[x32007];
      char x32009 = x32008 - '0';
      int x32010 = x32006 + x32009;
      x31987 = x32010;
      x31787 = x31787 + 1;
    }
    long x32015 = x31787;
    char x32016 = x4[x32015];
    bool x32017 = x32016 == '.';
    if (x32017) {
      x31787 = x31787 + 1;
      for (;;) {
        long x32019 = x31787;
        char x32020 = x4[x32019];
        bool x32021 = x32020 != '|';
        bool x32026 = x32021;
        if (x32021) {
          long x32022 = x31787;
          char x32023 = x4[x32022];
          bool x32024 = x32023 != '\n';
          x32026 = x32024;
        }
        bool x32027 = x32026;
        if (!x32027) break;
        int x32029 = x31987;
        long x32031 = x31787;
        int x32030 = x32029 * 10;
        char x32032 = x4[x32031];
        char x32033 = x32032 - '0';
        int x32034 = x32030 + x32033;
        x31987 = x32034;
        int x32036 = x31988;
        int x32037 = x32036 * 10;
        x31988 = x32037;
        x31787 = x31787 + 1;
      }
    } else {
    }
    x31787 = x31787 + 1;
    int x32046 = x31987;
    int x32048 = x31988;
    int x32052 = 0;
    int x32053 = 1;
    for (;;) {
      long x32054 = x31787;
      char x32055 = x4[x32054];
      bool x32056 = x32055 != '.';
      bool x32061 = x32056;
      if (x32056) {
        long x32057 = x31787;
        char x32058 = x4[x32057];
        bool x32059 = x32058 != '|';
        x32061 = x32059;
      }
      bool x32062 = x32061;
      bool x32067 = x32062;
      if (x32062) {
        long x32063 = x31787;
        char x32064 = x4[x32063];
        bool x32065 = x32064 != '\n';
        x32067 = x32065;
      }
      bool x32068 = x32067;
      if (!x32068) break;
      int x32070 = x32052;
      long x32072 = x31787;
      int x32071 = x32070 * 10;
      char x32073 = x4[x32072];
      char x32074 = x32073 - '0';
      int x32075 = x32071 + x32074;
      x32052 = x32075;
      x31787 = x31787 + 1;
    }
    long x32080 = x31787;
    char x32081 = x4[x32080];
    bool x32082 = x32081 == '.';
    if (x32082) {
      x31787 = x31787 + 1;
      for (;;) {
        long x32084 = x31787;
        char x32085 = x4[x32084];
        bool x32086 = x32085 != '|';
        bool x32091 = x32086;
        if (x32086) {
          long x32087 = x31787;
          char x32088 = x4[x32087];
          bool x32089 = x32088 != '\n';
          x32091 = x32089;
        }
        bool x32092 = x32091;
        if (!x32092) break;
        int x32094 = x32052;
        long x32096 = x31787;
        int x32095 = x32094 * 10;
        char x32097 = x4[x32096];
        char x32098 = x32097 - '0';
        int x32099 = x32095 + x32098;
        x32052 = x32099;
        int x32101 = x32053;
        int x32102 = x32101 * 10;
        x32053 = x32102;
        x31787 = x31787 + 1;
      }
    } else {
    }
    x31787 = x31787 + 1;
    int x32111 = x32052;
    int x32113 = x32053;
    for (;;) {
      long x32119 = x31787;
      char x32120 = x4[x32119];
      bool x32121 = x32120 != '.';
      bool x32126 = x32121;
      if (x32121) {
        long x32122 = x31787;
        char x32123 = x4[x32122];
        bool x32124 = x32123 != '|';
        x32126 = x32124;
      }
      bool x32127 = x32126;
      bool x32132 = x32127;
      if (x32127) {
        long x32128 = x31787;
        char x32129 = x4[x32128];
        bool x32130 = x32129 != '\n';
        x32132 = x32130;
      }
      bool x32133 = x32132;
      if (!x32133) break;
      x31787 = x31787 + 1;
    }
    long x32145 = x31787;
    char x32146 = x4[x32145];
    bool x32147 = x32146 == '.';
    if (x32147) {
      x31787 = x31787 + 1;
      for (;;) {
        long x32149 = x31787;
        char x32150 = x4[x32149];
        bool x32151 = x32150 != '|';
        bool x32156 = x32151;
        if (x32151) {
          long x32152 = x31787;
          char x32153 = x4[x32152];
          bool x32154 = x32153 != '\n';
          x32156 = x32154;
        }
        bool x32157 = x32156;
        if (!x32157) break;
        x31787 = x31787 + 1;
      }
    } else {
    }
    x31787 = x31787 + 1;
    x31787 = x31787 + 2;
    x31787 = x31787 + 2;
    for (;;) {
      long x32189 = x31787;
      char x32190 = x4[x32189];
      bool x32191 = x32190 != '-';
      bool x32196 = x32191;
      if (x32191) {
        long x32192 = x31787;
        char x32193 = x4[x32192];
        bool x32194 = x32193 != '\n';
        x32196 = x32194;
      }
      bool x32197 = x32196;
      if (!x32197) break;
      x31787 = x31787 + 1;
    }
    x31787 = x31787 + 1;
    for (;;) {
      long x32213 = x31787;
      char x32214 = x4[x32213];
      bool x32215 = x32214 != '-';
      bool x32220 = x32215;
      if (x32215) {
        long x32216 = x31787;
        char x32217 = x4[x32216];
        bool x32218 = x32217 != '\n';
        x32220 = x32218;
      }
      bool x32221 = x32220;
      if (!x32221) break;
      x31787 = x31787 + 1;
    }
    x31787 = x31787 + 1;
    for (;;) {
      long x32237 = x31787;
      char x32238 = x4[x32237];
      bool x32239 = x32238 != '|';
      bool x32244 = x32239;
      if (x32239) {
        long x32240 = x31787;
        char x32241 = x4[x32240];
        bool x32242 = x32241 != '\n';
        x32244 = x32242;
      }
      bool x32245 = x32244;
      if (!x32245) break;
      x31787 = x31787 + 1;
    }
    x31787 = x31787 + 1;
    for (;;) {
      long x32265 = x31787;
      char x32266 = x4[x32265];
      bool x32267 = x32266 != '-';
      bool x32272 = x32267;
      if (x32267) {
        long x32268 = x31787;
        char x32269 = x4[x32268];
        bool x32270 = x32269 != '\n';
        x32272 = x32270;
      }
      bool x32273 = x32272;
      if (!x32273) break;
      x31787 = x31787 + 1;
    }
    x31787 = x31787 + 1;
    for (;;) {
      long x32289 = x31787;
      char x32290 = x4[x32289];
      bool x32291 = x32290 != '-';
      bool x32296 = x32291;
      if (x32291) {
        long x32292 = x31787;
        char x32293 = x4[x32292];
        bool x32294 = x32293 != '\n';
        x32296 = x32294;
      }
      bool x32297 = x32296;
      if (!x32297) break;
      x31787 = x31787 + 1;
    }
    x31787 = x31787 + 1;
    for (;;) {
      long x32313 = x31787;
      char x32314 = x4[x32313];
      bool x32315 = x32314 != '|';
      bool x32320 = x32315;
      if (x32315) {
        long x32316 = x31787;
        char x32317 = x4[x32316];
        bool x32318 = x32317 != '\n';
        x32320 = x32318;
      }
      bool x32321 = x32320;
      if (!x32321) break;
      x31787 = x31787 + 1;
    }
    x31787 = x31787 + 1;
    for (;;) {
      long x32341 = x31787;
      char x32342 = x4[x32341];
      bool x32343 = x32342 != '-';
      bool x32348 = x32343;
      if (x32343) {
        long x32344 = x31787;
        char x32345 = x4[x32344];
        bool x32346 = x32345 != '\n';
        x32348 = x32346;
      }
      bool x32349 = x32348;
      if (!x32349) break;
      x31787 = x31787 + 1;
    }
    x31787 = x31787 + 1;
    for (;;) {
      long x32365 = x31787;
      char x32366 = x4[x32365];
      bool x32367 = x32366 != '-';
      bool x32372 = x32367;
      if (x32367) {
        long x32368 = x31787;
        char x32369 = x4[x32368];
        bool x32370 = x32369 != '\n';
        x32372 = x32370;
      }
      bool x32373 = x32372;
      if (!x32373) break;
      x31787 = x31787 + 1;
    }
    x31787 = x31787 + 1;
    for (;;) {
      long x32389 = x31787;
      char x32390 = x4[x32389];
      bool x32391 = x32390 != '|';
      bool x32396 = x32391;
      if (x32391) {
        long x32392 = x31787;
        char x32393 = x4[x32392];
        bool x32394 = x32393 != '\n';
        x32396 = x32394;
      }
      bool x32397 = x32396;
      if (!x32397) break;
      x31787 = x31787 + 1;
    }
    x31787 = x31787 + 1;
    long x32415 = x31787;
    for (;;) {
      long x32416 = x31787;
      char x32417 = x4[x32416];
      bool x32418 = x32417 != '|';
      bool x32423 = x32418;
      if (x32418) {
        long x32419 = x31787;
        char x32420 = x4[x32419];
        bool x32421 = x32420 != '\n';
        x32423 = x32421;
      }
      bool x32424 = x32423;
      if (!x32424) break;
      x31787 = x31787 + 1;
    }
    x31787 = x31787 + 1;
    long x32433 = x31787;
    for (;;) {
      long x32434 = x31787;
      char x32435 = x4[x32434];
      bool x32436 = x32435 != '|';
      bool x32441 = x32436;
      if (x32436) {
        long x32437 = x31787;
        char x32438 = x4[x32437];
        bool x32439 = x32438 != '\n';
        x32441 = x32439;
      }
      bool x32442 = x32441;
      if (!x32442) break;
      x31787 = x31787 + 1;
    }
    x31787 = x31787 + 1;
    for (;;) {
      long x32452 = x31787;
      char x32453 = x4[x32452];
      bool x32454 = x32453 != '|';
      bool x32459 = x32454;
      if (x32454) {
        long x32455 = x31787;
        char x32456 = x4[x32455];
        bool x32457 = x32456 != '\n';
        x32459 = x32457;
      }
      bool x32460 = x32459;
      if (!x32460) break;
      x31787 = x31787 + 1;
    }
    x31787 = x31787 + 1;
    long x32470 = x31789;
    long x32471 = x31788;
    bool x32472 = x32470 == x32471;
    if (x32472) {
      long x32473 = x32471 * 4L;
      x31788 = x32473;
      printf("buffer.resize %d\n",x32473);
      int* x32479 = x31793;
      int* x32480 = (int*)realloc(x32479,x32473 * sizeof(int));
      x31793 = x32480;
      double* x32488 = x31799;
      double* x32489 = (double*)realloc(x32488,x32473 * sizeof(double));
      x31799 = x32489;
      double* x32491 = x31801;
      double* x32492 = (double*)realloc(x32491,x32473 * sizeof(double));
      x31801 = x32492;
      double* x32494 = x31803;
      double* x32495 = (double*)realloc(x32494,x32473 * sizeof(double));
      x31803 = x32495;
      char** x32515 = x31817;
      char** x32516 = (char**)realloc(x32515,x32473 * sizeof(char*));
      x31817 = x32516;
      char** x32518 = x31819;
      char** x32519 = (char**)realloc(x32518,x32473 * sizeof(char*));
      x31819 = x32519;
    } else {
    }
    int* x32528 = x31793;
    x32528[x32470] = x31872;
    double* x32534 = x31799;
    double x31982 = (double)x31981;
    double x31984 = (double)x31983;
    double x31985 = x31982 / x31984;
    x32534[x32470] = x31985;
    double* x32536 = x31801;
    double x32047 = (double)x32046;
    double x32049 = (double)x32048;
    double x32050 = x32047 / x32049;
    x32536[x32470] = x32050;
    double* x32538 = x31803;
    double x32112 = (double)x32111;
    double x32114 = (double)x32113;
    double x32115 = x32112 / x32114;
    x32538[x32470] = x32115;
    char** x32552 = x31817;
    char* x32432 = x4+x32415;
    x32552[x32470] = x32432;
    char** x32554 = x31819;
    char* x32450 = x4+x32433;
    x32554[x32470] = x32450;
    x31789 = x31789 + 1;
  }
  long x32561 = 0L;
  long x32562 = x6;
  long x32563 = 0L;
  int* x32564 = (int*)malloc(x6 * sizeof(int));
  int* x32565 = x32564;
  char** x32570 = (char**)malloc(x6 * sizeof(char*));
  char** x32571 = x32570;
  int* x32574 = (int*)malloc(x6 * sizeof(int));
  int* x32575 = x32574;
  char** x32576 = (char**)malloc(x6 * sizeof(char*));
  char** x32577 = x32576;
  int x998 = open("../databases/sf2/part.tbl",0);
  long x999 = fsize(x998);
  char* x1000 = mmap(0, x999, PROT_READ, MAP_FILE | MAP_SHARED, x998, 0);
  for (;;) {
    long x32583 = x32561;
    bool x32584 = x32583 < x999;
    if (!x32584) break;
    int x32587 = 0;
    for (;;) {
      long x32588 = x32561;
      char x32589 = x1000[x32588];
      bool x32590 = x32589 != '|';
      bool x32595 = x32590;
      if (x32590) {
        long x32591 = x32561;
        char x32592 = x1000[x32591];
        bool x32593 = x32592 != '\n';
        x32595 = x32593;
      }
      bool x32596 = x32595;
      if (!x32596) break;
      int x32598 = x32587;
      long x32600 = x32561;
      int x32599 = x32598 * 10;
      char x32601 = x1000[x32600];
      char x32602 = x32601 - '0';
      int x32603 = x32599 + x32602;
      x32587 = x32603;
      x32561 = x32561 + 1;
    }
    x32561 = x32561 + 1;
    int x32609 = x32587;
    for (;;) {
      long x32611 = x32561;
      char x32612 = x1000[x32611];
      bool x32613 = x32612 != '|';
      bool x32618 = x32613;
      if (x32613) {
        long x32614 = x32561;
        char x32615 = x1000[x32614];
        bool x32616 = x32615 != '\n';
        x32618 = x32616;
      }
      bool x32619 = x32618;
      if (!x32619) break;
      x32561 = x32561 + 1;
    }
    x32561 = x32561 + 1;
    for (;;) {
      long x32629 = x32561;
      char x32630 = x1000[x32629];
      bool x32631 = x32630 != '|';
      bool x32636 = x32631;
      if (x32631) {
        long x32632 = x32561;
        char x32633 = x1000[x32632];
        bool x32634 = x32633 != '\n';
        x32636 = x32634;
      }
      bool x32637 = x32636;
      if (!x32637) break;
      x32561 = x32561 + 1;
    }
    x32561 = x32561 + 1;
    long x32646 = x32561;
    for (;;) {
      long x32647 = x32561;
      char x32648 = x1000[x32647];
      bool x32649 = x32648 != '|';
      bool x32654 = x32649;
      if (x32649) {
        long x32650 = x32561;
        char x32651 = x1000[x32650];
        bool x32652 = x32651 != '\n';
        x32654 = x32652;
      }
      bool x32655 = x32654;
      if (!x32655) break;
      x32561 = x32561 + 1;
    }
    x32561 = x32561 + 1;
    for (;;) {
      long x32665 = x32561;
      char x32666 = x1000[x32665];
      bool x32667 = x32666 != '|';
      bool x32672 = x32667;
      if (x32667) {
        long x32668 = x32561;
        char x32669 = x1000[x32668];
        bool x32670 = x32669 != '\n';
        x32672 = x32670;
      }
      bool x32673 = x32672;
      if (!x32673) break;
      x32561 = x32561 + 1;
    }
    x32561 = x32561 + 1;
    int x32683 = 0;
    for (;;) {
      long x32684 = x32561;
      char x32685 = x1000[x32684];
      bool x32686 = x32685 != '|';
      bool x32691 = x32686;
      if (x32686) {
        long x32687 = x32561;
        char x32688 = x1000[x32687];
        bool x32689 = x32688 != '\n';
        x32691 = x32689;
      }
      bool x32692 = x32691;
      if (!x32692) break;
      int x32694 = x32683;
      long x32696 = x32561;
      int x32695 = x32694 * 10;
      char x32697 = x1000[x32696];
      char x32698 = x32697 - '0';
      int x32699 = x32695 + x32698;
      x32683 = x32699;
      x32561 = x32561 + 1;
    }
    x32561 = x32561 + 1;
    int x32705 = x32683;
    long x32706 = x32561;
    for (;;) {
      long x32707 = x32561;
      char x32708 = x1000[x32707];
      bool x32709 = x32708 != '|';
      bool x32714 = x32709;
      if (x32709) {
        long x32710 = x32561;
        char x32711 = x1000[x32710];
        bool x32712 = x32711 != '\n';
        x32714 = x32712;
      }
      bool x32715 = x32714;
      if (!x32715) break;
      x32561 = x32561 + 1;
    }
    x32561 = x32561 + 1;
    for (;;) {
      long x32727 = x32561;
      char x32728 = x1000[x32727];
      bool x32729 = x32728 != '.';
      bool x32734 = x32729;
      if (x32729) {
        long x32730 = x32561;
        char x32731 = x1000[x32730];
        bool x32732 = x32731 != '|';
        x32734 = x32732;
      }
      bool x32735 = x32734;
      bool x32740 = x32735;
      if (x32735) {
        long x32736 = x32561;
        char x32737 = x1000[x32736];
        bool x32738 = x32737 != '\n';
        x32740 = x32738;
      }
      bool x32741 = x32740;
      if (!x32741) break;
      x32561 = x32561 + 1;
    }
    long x32753 = x32561;
    char x32754 = x1000[x32753];
    bool x32755 = x32754 == '.';
    if (x32755) {
      x32561 = x32561 + 1;
      for (;;) {
        long x32757 = x32561;
        char x32758 = x1000[x32757];
        bool x32759 = x32758 != '|';
        bool x32764 = x32759;
        if (x32759) {
          long x32760 = x32561;
          char x32761 = x1000[x32760];
          bool x32762 = x32761 != '\n';
          x32764 = x32762;
        }
        bool x32765 = x32764;
        if (!x32765) break;
        x32561 = x32561 + 1;
      }
    } else {
    }
    x32561 = x32561 + 1;
    for (;;) {
      long x32790 = x32561;
      char x32791 = x1000[x32790];
      bool x32792 = x32791 != '|';
      bool x32797 = x32792;
      if (x32792) {
        long x32793 = x32561;
        char x32794 = x1000[x32793];
        bool x32795 = x32794 != '\n';
        x32797 = x32795;
      }
      bool x32798 = x32797;
      if (!x32798) break;
      x32561 = x32561 + 1;
    }
    x32561 = x32561 + 1;
    long x32808 = x32563;
    long x32809 = x32562;
    bool x32810 = x32808 == x32809;
    if (x32810) {
      long x32811 = x32809 * 4L;
      x32562 = x32811;
      printf("buffer.resize %d\n",x32811);
      int* x32814 = x32565;
      int* x32815 = (int*)realloc(x32814,x32811 * sizeof(int));
      x32565 = x32815;
      char** x32823 = x32571;
      char** x32824 = (char**)realloc(x32823,x32811 * sizeof(char*));
      x32571 = x32824;
      int* x32829 = x32575;
      int* x32830 = (int*)realloc(x32829,x32811 * sizeof(int));
      x32575 = x32830;
      char** x32832 = x32577;
      char** x32833 = (char**)realloc(x32832,x32811 * sizeof(char*));
      x32577 = x32833;
    } else {
    }
    int* x32843 = x32565;
    x32843[x32808] = x32609;
    char** x32849 = x32571;
    char* x32663 = x1000+x32646;
    x32849[x32808] = x32663;
    int* x32853 = x32575;
    x32853[x32808] = x32705;
    char** x32855 = x32577;
    char* x32723 = x1000+x32706;
    x32855[x32808] = x32723;
    x32563 = x32563 + 1;
  }
  long x2011 = DEFAULT_JOIN_HASH_SIZE;
  long x787 = DEFAULT_AGG_HASH_SIZE ;
  long x2034 = x2011 - 1L;
  float x33073 = (float)36;
  double x33074 = (double)x33073;
  float x33076 = (float)26;
  double x33077 = (double)x33076;
  float x33081 = (float)25;
  double x33082 = (double)x33081;
  float x33084 = (float)15;
  double x33085 = (double)x33084;
  float x33091 = (float)14;
  double x33092 = (double)x33091;
  float x33094 = (float)4;
  double x33095 = (double)x33094;
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
  int x32864;
  for(x32864=0; x32864 < 5; x32864++) {
    bool x32865 = false;
    long x32866 = 0L;
    bool x32868 = false;
    long x32869 = 0L;
    int* x32872 = (int*)malloc(x2011 * sizeof(int));
    int* x32873 = x32872;
    char** x32878 = (char**)malloc(x2011 * sizeof(char*));
    char** x32879 = x32878;
    int* x32882 = (int*)malloc(x2011 * sizeof(int));
    int* x32883 = x32882;
    char** x32884 = (char**)malloc(x2011 * sizeof(char*));
    char** x32885 = x32884;
    long x32890 = 0L;
    long* x32891 = (long*)malloc(x2011 * sizeof(long));
    long* x32892 = (long*)malloc(x2011 * sizeof(long));
    long x32893;
    for(x32893=0L; x32893 < x2011; x32893++) {
      x32891[x32893] = -1L;
    }
    struct Anon603726677* x32900 = (struct Anon603726677*)malloc(x787 * sizeof(struct Anon603726677));
    struct Anon603726677* x32901 = x32900;
    long x32902 = 0L;
    long* x32903 = (long*)malloc(x787 * sizeof(long));
    long x32904;
    for(x32904=0L; x32904 < x787; x32904++) {
      struct Anon603726677* x32905 = x32901;
      struct Anon603726677 x32906 = x32905[x32904];
      char* x32907 = x32906.key;;
      double x32908 = x32906.aggs;;
      struct Anon603726677 x32909;
      x32909.exists = false;
      x32909.key = x32907;
      x32909.aggs = x32908;
      x32905[x32904] = x32909;
    }
    long x32914 = 0L;
    struct timeval x33292, x33293, x33294;
    gettimeofday(&x33292, NULL);
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x32916 = x32865;
      bool x32917 = !x32916;
      bool x32922 = x32917;
      if (x32917) {
        long x32918 = x32866;
        long x32919 = x32563;
        bool x32920 = x32918 < x32919;
        x32922 = x32920;
      }
      bool x32923 = x32922;
      if (!x32923) break;
      long x32925 = x32866;
      int* x32926 = x32565;
      int x32927 = x32926[x32925];
      char** x32932 = x32571;
      char* x32933 = x32932[x32925];
      int* x32936 = x32575;
      int x32937 = x32936[x32925];
      char** x32938 = x32577;
      char* x32939 = x32938[x32925];
      x32866 = x32866 + 1;
      bool x32946 = x32937 >= 1;
      bool x32963 = x32946;
      if (x32946) {
        bool x32947 = x32937 <= 5;
        bool x32949 = x32947;
        if (x32947) {
          bool x32948 = strcmp(x32933,"Brand#31") == 0;;
          x32949 = x32948;
        }
        bool x32950 = x32949;
        bool x32961 = x32950;
        if (x32950) {
          bool x32951 = strcmp(x32939,"SM BOX") == 0;;
          bool x32953 = x32951;
          if (x32951 == false) {
            bool x32952 = strcmp(x32939,"SM CASE") == 0;;
            x32953 = x32952;
          }
          bool x32954 = x32953;
          bool x32956 = x32954;
          if (x32954 == false) {
            bool x32955 = strcmp(x32939,"SM PACK") == 0;;
            x32956 = x32955;
          }
          bool x32957 = x32956;
          bool x32959 = x32957;
          if (x32957 == false) {
            bool x32958 = strcmp(x32939,"SM PKG") == 0;;
            x32959 = x32958;
          }
          bool x32960 = x32959;
          x32961 = x32960;
        }
        bool x32962 = x32961;
        x32963 = x32962;
      }
      bool x32964 = x32963;
      bool x32981 = x32964;
      if (x32964 == false) {
        bool x32965 = x32937 <= 10;
        bool x32967 = x32965;
        if (x32965) {
          bool x32966 = strcmp(x32933,"Brand#43") == 0;;
          x32967 = x32966;
        }
        bool x32968 = x32967;
        bool x32979 = x32968;
        if (x32968) {
          bool x32969 = strcmp(x32939,"MED BAG") == 0;;
          bool x32971 = x32969;
          if (x32969 == false) {
            bool x32970 = strcmp(x32939,"MED BOX") == 0;;
            x32971 = x32970;
          }
          bool x32972 = x32971;
          bool x32974 = x32972;
          if (x32972 == false) {
            bool x32973 = strcmp(x32939,"MED PACK") == 0;;
            x32974 = x32973;
          }
          bool x32975 = x32974;
          bool x32977 = x32975;
          if (x32975 == false) {
            bool x32976 = strcmp(x32939,"MED PKG") == 0;;
            x32977 = x32976;
          }
          bool x32978 = x32977;
          x32979 = x32978;
        }
        bool x32980 = x32979;
        x32981 = x32980;
      }
      bool x32982 = x32981;
      bool x32998 = x32982;
      if (x32982 == false) {
        bool x32983 = x32937 <= 15;
        bool x32984 = x32983;
        if (x32983) {
          bool x32966 = strcmp(x32933,"Brand#43") == 0;;
          x32984 = x32966;
        }
        bool x32985 = x32984;
        bool x32996 = x32985;
        if (x32985) {
          bool x32986 = strcmp(x32939,"LG BOX") == 0;;
          bool x32988 = x32986;
          if (x32986 == false) {
            bool x32987 = strcmp(x32939,"LG CASE") == 0;;
            x32988 = x32987;
          }
          bool x32989 = x32988;
          bool x32991 = x32989;
          if (x32989 == false) {
            bool x32990 = strcmp(x32939,"LG PACK") == 0;;
            x32991 = x32990;
          }
          bool x32992 = x32991;
          bool x32994 = x32992;
          if (x32992 == false) {
            bool x32993 = strcmp(x32939,"LG PKG") == 0;;
            x32994 = x32993;
          }
          bool x32995 = x32994;
          x32996 = x32995;
        }
        bool x32997 = x32996;
        x32998 = x32997;
      }
      bool x32999 = x32998;
      if (x32999) {
        long x33000 = x32890;
        int* x33001 = x32873;
        x33001[x33000] = x32927;
        char** x33007 = x32879;
        x33007[x33000] = x32933;
        int* x33011 = x32883;
        x33011[x33000] = x32937;
        char** x33013 = x32885;
        x33013[x33000] = x32939;
        x32890 = x32890 + 1L;
        long x33020 = x32927 & x2034;
        long x33021 = x32891[x33020];
        x32891[x33020] = x33000;
        x32892[x33000] = x33021;
      } else {
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x33029 = x32868;
      bool x33030 = !x33029;
      bool x33035 = x33030;
      if (x33030) {
        long x33031 = x32869;
        long x33032 = x31789;
        bool x33033 = x33031 < x33032;
        x33035 = x33033;
      }
      bool x33036 = x33035;
      if (!x33036) break;
      long x33038 = x32869;
      int* x33041 = x31793;
      int x33042 = x33041[x33038];
      double* x33047 = x31799;
      double x33048 = x33047[x33038];
      double* x33049 = x31801;
      double x33050 = x33049[x33038];
      double* x33051 = x31803;
      double x33052 = x33051[x33038];
      char** x33065 = x31817;
      char* x33066 = x33065[x33038];
      char** x33067 = x31819;
      char* x33068 = x33067[x33038];
      x32869 = x32869 + 1;
      bool x33075 = x33048 <= x33074;
      bool x33078 = x33048 >= x33077;
      bool x33079 = x33075;
      if (x33075) {
        x33079 = x33078;
      }
      bool x33080 = x33079;
      bool x33083 = x33048 <= x33082;
      bool x33086 = x33048 >= x33085;
      bool x33089 = x33080;
      if (x33080 == false) {
        bool x33087 = x33083;
        if (x33083) {
          x33087 = x33086;
        }
        bool x33088 = x33087;
        x33089 = x33088;
      }
      bool x33090 = x33089;
      bool x33093 = x33048 <= x33092;
      bool x33096 = x33048 >= x33095;
      bool x33099 = x33090;
      if (x33090 == false) {
        bool x33097 = x33093;
        if (x33093) {
          x33097 = x33096;
        }
        bool x33098 = x33097;
        x33099 = x33098;
      }
      bool x33100 = x33099;
      bool x33102 = x33100;
      if (x33100) {
        bool x33101 = strcmp(x33066,"DELIVER IN PERSON") == 0;;
        x33102 = x33101;
      }
      bool x33103 = x33102;
      bool x33108 = x33103;
      if (x33103) {
        bool x33104 = strcmp(x33068,"AIR") == 0;;
        bool x33106 = x33104;
        if (x33104 == false) {
          bool x33105 = strcmp(x33068,"AIRREG") == 0;;
          x33106 = x33105;
        }
        bool x33107 = x33106;
        x33108 = x33107;
      }
      bool x33109 = x33108;
      if (x33109) {
        long x33110 = x33042 & x2034;
        long x33111 = x32891[x33110];
        long x33112 = x33111;
        double x33217 = 1.0 - x33052;
        double x33218 = x33050 * x33217;
        struct Anon603726677 x33248;
        x33248.exists = true;
        x33248.key = "Total";
        x33248.aggs = x33218;
        for (;;) {
          long x33113 = x33112;
          bool x33114 = x33113 != -1;
          if (!x33114) break;
          long x33116 = x33112;
          int* x33117 = x32873;
          int x33118 = x33117[x33116];
          char** x33123 = x32879;
          char* x33124 = x33123[x33116];
          int* x33127 = x32883;
          int x33128 = x33127[x33116];
          char** x33129 = x32885;
          char* x33130 = x33129[x33116];
          long x33136 = x32892[x33116];
          x33112 = x33136;
          bool x33138 = x33118 == x33042;
          if (x33138) {
            bool x33142 = strcmp(x33124,"Brand#31") == 0;;
            bool x33153 = x33142;
            if (x33142) {
              bool x33143 = strcmp(x33130,"SM BOX") == 0;;
              bool x33145 = x33143;
              if (x33143 == false) {
                bool x33144 = strcmp(x33130,"SM CASE") == 0;;
                x33145 = x33144;
              }
              bool x33146 = x33145;
              bool x33148 = x33146;
              if (x33146 == false) {
                bool x33147 = strcmp(x33130,"SM PACK") == 0;;
                x33148 = x33147;
              }
              bool x33149 = x33148;
              bool x33151 = x33149;
              if (x33149 == false) {
                bool x33150 = strcmp(x33130,"SM PKG") == 0;;
                x33151 = x33150;
              }
              bool x33152 = x33151;
              x33153 = x33152;
            }
            bool x33154 = x33153;
            bool x33155 = x33154;
            if (x33154) {
              x33155 = x33096;
            }
            bool x33156 = x33155;
            bool x33157 = x33156;
            if (x33156) {
              x33157 = x33093;
            }
            bool x33158 = x33157;
            bool x33160 = x33158;
            if (x33158) {
              bool x33159 = x33128 <= 5;
              x33160 = x33159;
            }
            bool x33161 = x33160;
            bool x33182 = x33161;
            if (x33161 == false) {
              bool x33162 = strcmp(x33124,"Brand#43") == 0;;
              bool x33173 = x33162;
              if (x33162) {
                bool x33163 = strcmp(x33130,"MED BAG") == 0;;
                bool x33165 = x33163;
                if (x33163 == false) {
                  bool x33164 = strcmp(x33130,"MED BOX") == 0;;
                  x33165 = x33164;
                }
                bool x33166 = x33165;
                bool x33168 = x33166;
                if (x33166 == false) {
                  bool x33167 = strcmp(x33130,"MED PACK") == 0;;
                  x33168 = x33167;
                }
                bool x33169 = x33168;
                bool x33171 = x33169;
                if (x33169 == false) {
                  bool x33170 = strcmp(x33130,"MED PKG") == 0;;
                  x33171 = x33170;
                }
                bool x33172 = x33171;
                x33173 = x33172;
              }
              bool x33174 = x33173;
              bool x33175 = x33174;
              if (x33174) {
                x33175 = x33086;
              }
              bool x33176 = x33175;
              bool x33177 = x33176;
              if (x33176) {
                x33177 = x33083;
              }
              bool x33178 = x33177;
              bool x33180 = x33178;
              if (x33178) {
                bool x33179 = x33128 <= 10;
                x33180 = x33179;
              }
              bool x33181 = x33180;
              x33182 = x33181;
            }
            bool x33183 = x33182;
            bool x33203 = x33183;
            if (x33183 == false) {
              bool x33162 = strcmp(x33124,"Brand#43") == 0;;
              bool x33194 = x33162;
              if (x33162) {
                bool x33184 = strcmp(x33130,"LG BOX") == 0;;
                bool x33186 = x33184;
                if (x33184 == false) {
                  bool x33185 = strcmp(x33130,"LG CASE") == 0;;
                  x33186 = x33185;
                }
                bool x33187 = x33186;
                bool x33189 = x33187;
                if (x33187 == false) {
                  bool x33188 = strcmp(x33130,"LG PACK") == 0;;
                  x33189 = x33188;
                }
                bool x33190 = x33189;
                bool x33192 = x33190;
                if (x33190 == false) {
                  bool x33191 = strcmp(x33130,"LG PKG") == 0;;
                  x33192 = x33191;
                }
                bool x33193 = x33192;
                x33194 = x33193;
              }
              bool x33195 = x33194;
              bool x33196 = x33195;
              if (x33195) {
                x33196 = x33078;
              }
              bool x33197 = x33196;
              bool x33198 = x33197;
              if (x33197) {
                x33198 = x33075;
              }
              bool x33199 = x33198;
              bool x33201 = x33199;
              if (x33199) {
                bool x33200 = x33128 <= 15;
                x33201 = x33200;
              }
              bool x33202 = x33201;
              x33203 = x33202;
            }
            bool x33204 = x33203;
            if (x33204) {
              long x33205 = x9316;
              struct Anon603726677* x33206 = x32901;
              struct Anon603726677 x33207 = x33206[x9316];
              struct Anon603726677 x33208 = x33207;
              bool x33209 = x33207.exists;;
              bool x33214 = x33209;
              if (x33209) {
                struct Anon603726677 x33210 = x33208;
                char* x33211 = x33210.key;;
                bool x33212 = strcmp(x33211,"Total") == 0;;
                x33214 = x33212;
              }
              bool x33215 = x33214;
              if (x33215) {
                double x33216 = x33207.aggs;;
                char* x33220 = x33207.key;;
                double x33219 = x33216 + x33218;
                struct Anon603726677 x33221;
                x33221.exists = true;
                x33221.key = x33220;
                x33221.aggs = x33219;
                x33206[x9316] = x33221;
              } else {
                for (;;) {
                  struct Anon603726677 x33224 = x33208;
                  bool x33225 = x33224.exists;;
                  bool x33257;
                  if (x33225) {
                    char* x33226 = x33224.key;;
                    bool x33227 = strcmp(x33226,"Total") == 0;;
                    bool x33245;
                    if (x33227) {
                      double x33228 = x33224.aggs;;
                      long x33230 = x33205;
                      struct Anon603726677* x33232 = x32901;
                      double x33229 = x33228 + x33218;
                      struct Anon603726677 x33231;
                      x33231.exists = true;
                      x33231.key = x33226;
                      x33231.aggs = x33229;
                      x33232[x33230] = x33231;
                      x33245 = false;
                    } else {
                      long x33235 = x33205;
                      long x33236 = x33235 + 1L;
                      long x33237 = x33236 % x802;
                      x33205 = x33237;
                      struct Anon603726677* x33239 = x32901;
                      struct Anon603726677 x33240 = x33239[x33237];
                      x33208 = x33240;
                      x33245 = true;
                    }
                    x33257 = x33245;
                  } else {
                    long x33247 = x33205;
                    struct Anon603726677* x33249 = x32901;
                    x33249[x33247] = x33248;
                    long x33251 = x32902;
                    x32903[x33251] = x33247;
                    x32902 = x32902 + 1L;
                    x33257 = false;
                  }
                  if (!x33257) break;
                }
              }
            } else {
            }
          } else {
          }
        }
      } else {
      }
    }
    long x33274 = x32902;
    long x33276;
    for(x33276=0L; x33276 < x33274; x33276++) {
      long x33277 = x32903[x33276];
      struct Anon603726677* x33278 = x32901;
      struct Anon603726677 x33279 = x33278[x33277];
      if (x975) {
      } else {
        double x33282 = x33279.aggs;;
        printf("%.4f\n",x33282);
        x32914 = x32914 + 1L;
      }
    }
    long x33289 = x32914;
    printf("(%d rows)\n",x33289);
    gettimeofday(&x33293, NULL);
    timeval_subtract(&x33294, &x33293, &x33292);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x33294.tv_sec * 1000) + (x33294.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
