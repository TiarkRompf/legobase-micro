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
      int fsize(int fd) {
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

struct Anon1594456343 {
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

struct Anon150112254 {
bool exists;
double key;
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

struct Anon787349517 {
bool exists;
int key;
struct Anon1023322325 aggs;
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

struct Anon1007729034 {
bool exists;
char* key;
struct Anon2052879266 aggs;
};

struct Anon72918141 {
int N2_N_NATIONKEY;
char* N2_N_NAME;
int N2_N_REGIONKEY;
char* N2_N_COMMENT;
};

struct Anon884569349 {
bool exists;
struct Anon1465150758 key;
struct Anon2052879266 aggs;
};

struct Anon2092052448 {
bool exists;
int key;
struct Anon2052879266 aggs;
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

struct Anon984006423 {
bool exists;
char* key;
struct Anon189208763 aggs;
};

struct Anon1230230422 {
int key;
struct Anon1023322325 wnd;
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

struct Anon133694426 {
bool exists;
struct Anon1711779607 key;
struct Anon2052879266 aggs;
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

struct Anon211179391 {
bool exists;
int key;
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

struct Anon625264174 {
char L_RETURNFLAG;
char L_LINESTATUS;
};

struct Anon1272074242 {
bool exists;
struct Anon625264174 key;
struct Anon567626277 aggs;
};

struct Anon2052879268 {
double _2;
};

struct Anon1941857026 {
int key;
struct Anon2052879268 aggs;
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

struct Anon1124044545 {
struct Anon625264174 key;
struct Anon1296044246 aggs;
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

struct Anon2071559637 {
bool exists;
struct Anon1548200872 key;
struct Anon2052879266 aggs;
};

/************************ FUNCTIONS **************************/

/************************ MAIN BODY **************************/
int main(int x23177, char** x23178) {
  int x23179 = 0;
  int x23180 = 1048576;
  int x23181 = 0;
  int* x23182 = (int*)malloc(1048576 * sizeof(int));
  int* x23183 = x23182;
  int x3720 = open("../databases/sf2/customer.tbl",0);
  int x3721 = fsize(x3720);
  char* x3722 = mmap(0, x3721, PROT_READ, MAP_FILE | MAP_SHARED, x3720, 0);
  for (;;) {
    int x23198 = x23179;
    bool x23199 = x23198 < x3721;
    if (!x23199) break;
    int x23202 = 0;
    for (;;) {
      int x23203 = x23179;
      char x23204 = x3722[x23203];
      bool x23205 = x23204 != '|';
      bool x23210 = x23205;
      if (x23205) {
        int x23206 = x23179;
        char x23207 = x3722[x23206];
        bool x23208 = x23207 != '\n';
        x23210 = x23208;
      }
      bool x23211 = x23210;
      if (!x23211) break;
      int x23213 = x23202;
      int x23215 = x23179;
      int x23214 = x23213 * 10;
      char x23216 = x3722[x23215];
      char x23217 = x23216 - '0';
      int x23218 = x23214 + x23217;
      x23202 = x23218;
      x23179 = x23179 + 1;
    }
    x23179 = x23179 + 1;
    int x23224 = x23202;
    for (;;) {
      int x23226 = x23179;
      char x23227 = x3722[x23226];
      bool x23228 = x23227 != '|';
      bool x23233 = x23228;
      if (x23228) {
        int x23229 = x23179;
        char x23230 = x3722[x23229];
        bool x23231 = x23230 != '\n';
        x23233 = x23231;
      }
      bool x23234 = x23233;
      if (!x23234) break;
      x23179 = x23179 + 1;
    }
    x23179 = x23179 + 1;
    for (;;) {
      int x23244 = x23179;
      char x23245 = x3722[x23244];
      bool x23246 = x23245 != '|';
      bool x23251 = x23246;
      if (x23246) {
        int x23247 = x23179;
        char x23248 = x3722[x23247];
        bool x23249 = x23248 != '\n';
        x23251 = x23249;
      }
      bool x23252 = x23251;
      if (!x23252) break;
      x23179 = x23179 + 1;
    }
    x23179 = x23179 + 1;
    for (;;) {
      int x23263 = x23179;
      char x23264 = x3722[x23263];
      bool x23265 = x23264 != '|';
      bool x23270 = x23265;
      if (x23265) {
        int x23266 = x23179;
        char x23267 = x3722[x23266];
        bool x23268 = x23267 != '\n';
        x23270 = x23268;
      }
      bool x23271 = x23270;
      if (!x23271) break;
      x23179 = x23179 + 1;
    }
    x23179 = x23179 + 1;
    for (;;) {
      int x23286 = x23179;
      char x23287 = x3722[x23286];
      bool x23288 = x23287 != '|';
      bool x23293 = x23288;
      if (x23288) {
        int x23289 = x23179;
        char x23290 = x3722[x23289];
        bool x23291 = x23290 != '\n';
        x23293 = x23291;
      }
      bool x23294 = x23293;
      if (!x23294) break;
      x23179 = x23179 + 1;
    }
    x23179 = x23179 + 1;
    for (;;) {
      int x23306 = x23179;
      char x23307 = x3722[x23306];
      bool x23308 = x23307 != '.';
      bool x23313 = x23308;
      if (x23308) {
        int x23309 = x23179;
        char x23310 = x3722[x23309];
        bool x23311 = x23310 != '|';
        x23313 = x23311;
      }
      bool x23314 = x23313;
      bool x23319 = x23314;
      if (x23314) {
        int x23315 = x23179;
        char x23316 = x3722[x23315];
        bool x23317 = x23316 != '\n';
        x23319 = x23317;
      }
      bool x23320 = x23319;
      if (!x23320) break;
      x23179 = x23179 + 1;
    }
    int x23332 = x23179;
    char x23333 = x3722[x23332];
    bool x23334 = x23333 == '.';
    if (x23334) {
      x23179 = x23179 + 1;
      for (;;) {
        int x23336 = x23179;
        char x23337 = x3722[x23336];
        bool x23338 = x23337 != '|';
        bool x23343 = x23338;
        if (x23338) {
          int x23339 = x23179;
          char x23340 = x3722[x23339];
          bool x23341 = x23340 != '\n';
          x23343 = x23341;
        }
        bool x23344 = x23343;
        if (!x23344) break;
        x23179 = x23179 + 1;
      }
    } else {
    }
    x23179 = x23179 + 1;
    for (;;) {
      int x23369 = x23179;
      char x23370 = x3722[x23369];
      bool x23371 = x23370 != '|';
      bool x23376 = x23371;
      if (x23371) {
        int x23372 = x23179;
        char x23373 = x3722[x23372];
        bool x23374 = x23373 != '\n';
        x23376 = x23374;
      }
      bool x23377 = x23376;
      if (!x23377) break;
      x23179 = x23179 + 1;
    }
    x23179 = x23179 + 1;
    for (;;) {
      int x23387 = x23179;
      char x23388 = x3722[x23387];
      bool x23389 = x23388 != '|';
      bool x23394 = x23389;
      if (x23389) {
        int x23390 = x23179;
        char x23391 = x3722[x23390];
        bool x23392 = x23391 != '\n';
        x23394 = x23392;
      }
      bool x23395 = x23394;
      if (!x23395) break;
      x23179 = x23179 + 1;
    }
    x23179 = x23179 + 1;
    int x23405 = x23181;
    int x23406 = x23180;
    bool x23407 = x23405 == x23406;
    if (x23407) {
      int x23408 = x23406 * 4;
      x23180 = x23408;
      printf("buffer.resize %d\n",x23408);
      int* x23411 = x23183;
      int* x23412 = (int*)realloc(x23411,x23408 * sizeof(int));
      x23183 = x23412;
    } else {
    }
    int* x23437 = x23183;
    x23437[x23405] = x23224;
    x23181 = x23181 + 1;
  }
  int x23456 = 0;
  int x23457 = 1048576;
  int x23458 = 0;
  int* x23459 = (int*)malloc(1048576 * sizeof(int));
  int* x23460 = x23459;
  int* x23461 = (int*)malloc(1048576 * sizeof(int));
  int* x23462 = x23461;
  char** x23475 = (char**)malloc(1048576 * sizeof(char*));
  char** x23476 = x23475;
  int x3366 = open("../databases/sf2/orders.tbl",0);
  int x3367 = fsize(x3366);
  char* x3368 = mmap(0, x3367, PROT_READ, MAP_FILE | MAP_SHARED, x3366, 0);
  for (;;) {
    int x23477 = x23456;
    bool x23478 = x23477 < x3367;
    if (!x23478) break;
    int x23481 = 0;
    for (;;) {
      int x23482 = x23456;
      char x23483 = x3368[x23482];
      bool x23484 = x23483 != '|';
      bool x23489 = x23484;
      if (x23484) {
        int x23485 = x23456;
        char x23486 = x3368[x23485];
        bool x23487 = x23486 != '\n';
        x23489 = x23487;
      }
      bool x23490 = x23489;
      if (!x23490) break;
      int x23492 = x23481;
      int x23494 = x23456;
      int x23493 = x23492 * 10;
      char x23495 = x3368[x23494];
      char x23496 = x23495 - '0';
      int x23497 = x23493 + x23496;
      x23481 = x23497;
      x23456 = x23456 + 1;
    }
    x23456 = x23456 + 1;
    int x23503 = x23481;
    int x23505 = 0;
    for (;;) {
      int x23506 = x23456;
      char x23507 = x3368[x23506];
      bool x23508 = x23507 != '|';
      bool x23513 = x23508;
      if (x23508) {
        int x23509 = x23456;
        char x23510 = x3368[x23509];
        bool x23511 = x23510 != '\n';
        x23513 = x23511;
      }
      bool x23514 = x23513;
      if (!x23514) break;
      int x23516 = x23505;
      int x23518 = x23456;
      int x23517 = x23516 * 10;
      char x23519 = x3368[x23518];
      char x23520 = x23519 - '0';
      int x23521 = x23517 + x23520;
      x23505 = x23521;
      x23456 = x23456 + 1;
    }
    x23456 = x23456 + 1;
    int x23527 = x23505;
    x23456 = x23456 + 2;
    for (;;) {
      int x23534 = x23456;
      char x23535 = x3368[x23534];
      bool x23536 = x23535 != '.';
      bool x23541 = x23536;
      if (x23536) {
        int x23537 = x23456;
        char x23538 = x3368[x23537];
        bool x23539 = x23538 != '|';
        x23541 = x23539;
      }
      bool x23542 = x23541;
      bool x23547 = x23542;
      if (x23542) {
        int x23543 = x23456;
        char x23544 = x3368[x23543];
        bool x23545 = x23544 != '\n';
        x23547 = x23545;
      }
      bool x23548 = x23547;
      if (!x23548) break;
      x23456 = x23456 + 1;
    }
    int x23560 = x23456;
    char x23561 = x3368[x23560];
    bool x23562 = x23561 == '.';
    if (x23562) {
      x23456 = x23456 + 1;
      for (;;) {
        int x23564 = x23456;
        char x23565 = x3368[x23564];
        bool x23566 = x23565 != '|';
        bool x23571 = x23566;
        if (x23566) {
          int x23567 = x23456;
          char x23568 = x3368[x23567];
          bool x23569 = x23568 != '\n';
          x23571 = x23569;
        }
        bool x23572 = x23571;
        if (!x23572) break;
        x23456 = x23456 + 1;
      }
    } else {
    }
    x23456 = x23456 + 1;
    for (;;) {
      int x23598 = x23456;
      char x23599 = x3368[x23598];
      bool x23600 = x23599 != '-';
      bool x23605 = x23600;
      if (x23600) {
        int x23601 = x23456;
        char x23602 = x3368[x23601];
        bool x23603 = x23602 != '\n';
        x23605 = x23603;
      }
      bool x23606 = x23605;
      if (!x23606) break;
      x23456 = x23456 + 1;
    }
    x23456 = x23456 + 1;
    for (;;) {
      int x23622 = x23456;
      char x23623 = x3368[x23622];
      bool x23624 = x23623 != '-';
      bool x23629 = x23624;
      if (x23624) {
        int x23625 = x23456;
        char x23626 = x3368[x23625];
        bool x23627 = x23626 != '\n';
        x23629 = x23627;
      }
      bool x23630 = x23629;
      if (!x23630) break;
      x23456 = x23456 + 1;
    }
    x23456 = x23456 + 1;
    for (;;) {
      int x23646 = x23456;
      char x23647 = x3368[x23646];
      bool x23648 = x23647 != '|';
      bool x23653 = x23648;
      if (x23648) {
        int x23649 = x23456;
        char x23650 = x3368[x23649];
        bool x23651 = x23650 != '\n';
        x23653 = x23651;
      }
      bool x23654 = x23653;
      if (!x23654) break;
      x23456 = x23456 + 1;
    }
    x23456 = x23456 + 1;
    for (;;) {
      int x23673 = x23456;
      char x23674 = x3368[x23673];
      bool x23675 = x23674 != '|';
      bool x23680 = x23675;
      if (x23675) {
        int x23676 = x23456;
        char x23677 = x3368[x23676];
        bool x23678 = x23677 != '\n';
        x23680 = x23678;
      }
      bool x23681 = x23680;
      if (!x23681) break;
      x23456 = x23456 + 1;
    }
    x23456 = x23456 + 1;
    for (;;) {
      int x23691 = x23456;
      char x23692 = x3368[x23691];
      bool x23693 = x23692 != '|';
      bool x23698 = x23693;
      if (x23693) {
        int x23694 = x23456;
        char x23695 = x3368[x23694];
        bool x23696 = x23695 != '\n';
        x23698 = x23696;
      }
      bool x23699 = x23698;
      if (!x23699) break;
      x23456 = x23456 + 1;
    }
    x23456 = x23456 + 1;
    for (;;) {
      int x23710 = x23456;
      char x23711 = x3368[x23710];
      bool x23712 = x23711 != '|';
      bool x23717 = x23712;
      if (x23712) {
        int x23713 = x23456;
        char x23714 = x3368[x23713];
        bool x23715 = x23714 != '\n';
        x23717 = x23715;
      }
      bool x23718 = x23717;
      if (!x23718) break;
      x23456 = x23456 + 1;
    }
    x23456 = x23456 + 1;
    int x23732 = x23456;
    for (;;) {
      int x23733 = x23456;
      char x23734 = x3368[x23733];
      bool x23735 = x23734 != '|';
      bool x23740 = x23735;
      if (x23735) {
        int x23736 = x23456;
        char x23737 = x3368[x23736];
        bool x23738 = x23737 != '\n';
        x23740 = x23738;
      }
      bool x23741 = x23740;
      if (!x23741) break;
      x23456 = x23456 + 1;
    }
    x23456 = x23456 + 1;
    int x23751 = x23458;
    int x23752 = x23457;
    bool x23753 = x23751 == x23752;
    if (x23753) {
      int x23754 = x23752 * 4;
      x23457 = x23754;
      printf("buffer.resize %d\n",x23754);
      int* x23757 = x23460;
      int* x23758 = (int*)realloc(x23757,x23754 * sizeof(int));
      x23460 = x23758;
      int* x23760 = x23462;
      int* x23761 = (int*)realloc(x23760,x23754 * sizeof(int));
      x23462 = x23761;
      char** x23781 = x23476;
      char** x23782 = (char**)realloc(x23781,x23754 * sizeof(char*));
      x23476 = x23782;
    } else {
    }
    int* x23786 = x23460;
    x23786[x23751] = x23503;
    int* x23788 = x23462;
    x23788[x23751] = x23527;
    char** x23802 = x23476;
    char* x23749 = x3368+x23732;
    x23802[x23751] = x23749;
    x23458 = x23458 + 1;
  }
  bool x24090 = 0 == 0.0;
  double x24126;
  if (x24090) {
    x24126 = 0.0;
  } else {
    x24126 = 1.0;
  }
  struct Anon2052879266 x24127;
  x24127._0 = x24126;
  int x24156 = 777 & 16777215;
  struct Anon2052879266 x5913;
  x5913._0 = 1.0;
  bool x972 = true == false;
  int x23807;
  for(x23807=0; x23807 < 5; x23807++) {
    bool x23808 = false;
    int x23809 = 0;
    bool x23810 = false;
    int x23811 = 0;
    int* x23814 = (int*)malloc(134217728 * sizeof(int));
    int* x23815 = x23814;
    int* x23816 = (int*)malloc(134217728 * sizeof(int));
    int* x23817 = x23816;
    int x23832 = 0;
    int* x23833 = (int*)malloc(67108864 * sizeof(int));
    int* x23834 = (int*)malloc(134217728 * sizeof(int));
    int x23835;
    for(x23835=0; x23835 < 67108864; x23835++) {
      x23833[x23835] = -1;
    }
    struct Anon2092052448* x23842 = (struct Anon2092052448*)malloc(16777216 * sizeof(struct Anon2092052448));
    struct Anon2092052448* x23843 = x23842;
    int x23844 = 0;
    int* x23845 = (int*)malloc(16777216 * sizeof(int));
    int x23846;
    for(x23846=0; x23846 < 16777216; x23846++) {
      struct Anon2092052448* x23847 = x23843;
      struct Anon2092052448 x23848 = x23847[x23846];
      int x23849 = x23848.key;;
      struct Anon2052879266 x23850 = x23848.aggs;;
      struct Anon2092052448 x23851;
      x23851.exists = false;
      x23851.key = x23849;
      x23851.aggs = x23850;
      x23847[x23846] = x23851;
    }
    struct Anon150112254* x23856 = (struct Anon150112254*)malloc(16777216 * sizeof(struct Anon150112254));
    struct Anon150112254* x23857 = x23856;
    int x23858 = 0;
    int* x23859 = (int*)malloc(16777216 * sizeof(int));
    int x23860;
    for(x23860=0; x23860 < 16777216; x23860++) {
      struct Anon150112254* x23861 = x23857;
      struct Anon150112254 x23862 = x23861[x23860];
      double x23863 = x23862.key;;
      struct Anon2052879266 x23864 = x23862.aggs;;
      struct Anon150112254 x23865;
      x23865.exists = false;
      x23865.key = x23863;
      x23865.aggs = x23864;
      x23861[x23860] = x23865;
    }
    int x23870 = 0;
    struct timeval x24240, x24241, x24242;
    gettimeofday(&x24240, NULL);
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x23872 = x23810;
      bool x23873 = !x23872;
      bool x23878 = x23873;
      if (x23873) {
        int x23874 = x23811;
        int x23875 = x23458;
        bool x23876 = x23874 < x23875;
        x23878 = x23876;
      }
      bool x23879 = x23878;
      if (!x23879) break;
      int x23881 = x23811;
      int* x23882 = x23460;
      int x23883 = x23882[x23881];
      int* x23884 = x23462;
      int x23885 = x23884[x23881];
      char** x23898 = x23476;
      char* x23899 = x23898[x23881];
      x23811 = x23811 + 1;
      int x23902 = strstr(&x23899[0],"unusual") - x23899;
      if (x23902 < 0) x23902 = -1;
      bool x23904 = x23902 != -1;
      bool x23906 = x23904;
      if (x23904) {
        int x23903 = strstr(&x23899[x23902],"packages") - x23899;
        if (x23903 < 0) x23903 = -1;
        bool x23905 = x23903 != -1;
        x23906 = x23905;
      }
      bool x23907 = x23906;
      if (x23907) {
      } else {
        int x23909 = x23832;
        int* x23910 = x23815;
        x23910[x23909] = x23883;
        int* x23912 = x23817;
        x23912[x23909] = x23885;
        x23832 = x23832 + 1;
        int x23929 = x23885 & 67108863;
        int x23930 = x23833[x23929];
        x23833[x23929] = x23909;
        x23834[x23909] = x23930;
      }
    }
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x23938 = x23808;
      bool x23939 = !x23938;
      bool x23944 = x23939;
      if (x23939) {
        int x23940 = x23809;
        int x23941 = x23181;
        bool x23942 = x23940 < x23941;
        x23944 = x23942;
      }
      bool x23945 = x23944;
      if (!x23945) break;
      int x23947 = x23809;
      int* x23948 = x23183;
      int x23949 = x23948[x23947];
      x23809 = x23809 + 1;
      bool x23966 = false;
      int x23967 = x23949 & 67108863;
      int x23968 = x23833[x23967];
      int x23969 = x23968;
      int x24000 = x23949 & 16777215;
      for (;;) {
        int x23970 = x23969;
        bool x23971 = x23970 != -1;
        if (!x23971) break;
        int x23973 = x23969;
        int* x23974 = x23815;
        int x23975 = x23974[x23973];
        int* x23976 = x23817;
        int x23977 = x23976[x23973];
        int x23993 = x23834[x23973];
        x23969 = x23993;
        bool x23995 = x23949 == x23977;
        if (x23995) {
          x23966 = true;
          int x24001 = x24000;
          struct Anon2092052448* x24002 = x23843;
          struct Anon2092052448 x24003 = x24002[x24000];
          struct Anon2092052448 x24004 = x24003;
          bool x24005 = x24003.exists;;
          bool x24010 = x24005;
          if (x24005) {
            struct Anon2092052448 x24006 = x24004;
            int x24007 = x24006.key;;
            bool x24008 = x24007 == x23949;
            x24010 = x24008;
          }
          bool x24011 = x24010;
          if (x24011) {
            struct Anon2052879266 x24012 = x24003.aggs;;
            int x24019 = x24003.key;;
            bool x24014 = x23975 == 0.0;
            double x24017;
            if (x24014) {
              double x24015 = x24012._0;;
              x24017 = x24015;
            } else {
              double x24015 = x24012._0;;
              double x24016 = x24015 + 1.0;
              x24017 = x24016;
            }
            struct Anon2052879266 x24018;
            x24018._0 = x24017;
            struct Anon2092052448 x24020;
            x24020.exists = true;
            x24020.key = x24019;
            x24020.aggs = x24018;
            x24002[x24000] = x24020;
          } else {
            bool x24014 = x23975 == 0.0;
            double x24050;
            if (x24014) {
              x24050 = 0.0;
            } else {
              x24050 = 1.0;
            }
            struct Anon2052879266 x24051;
            x24051._0 = x24050;
            struct Anon2092052448 x24052;
            x24052.exists = true;
            x24052.key = x23949;
            x24052.aggs = x24051;
            for (;;) {
              struct Anon2092052448 x24023 = x24004;
              bool x24024 = x24023.exists;;
              bool x24061;
              if (x24024) {
                int x24025 = x24023.key;;
                bool x24026 = x24025 == x23949;
                bool x24047;
                if (x24026) {
                  struct Anon2052879266 x24027 = x24023.aggs;;
                  int x24032 = x24001;
                  struct Anon2092052448* x24034 = x23843;
                  double x24030;
                  if (x24014) {
                    double x24028 = x24027._0;;
                    x24030 = x24028;
                  } else {
                    double x24028 = x24027._0;;
                    double x24029 = x24028 + 1.0;
                    x24030 = x24029;
                  }
                  struct Anon2052879266 x24031;
                  x24031._0 = x24030;
                  struct Anon2092052448 x24033;
                  x24033.exists = true;
                  x24033.key = x24025;
                  x24033.aggs = x24031;
                  x24034[x24032] = x24033;
                  x24047 = false;
                } else {
                  int x24037 = x24001;
                  int x24038 = x24037 + 1;
                  int x24039 = x24038 % 16777215;
                  x24001 = x24039;
                  struct Anon2092052448* x24041 = x23843;
                  struct Anon2092052448 x24042 = x24041[x24039];
                  x24004 = x24042;
                  x24047 = true;
                }
                x24061 = x24047;
              } else {
                int x24049 = x24001;
                struct Anon2092052448* x24053 = x23843;
                x24053[x24049] = x24052;
                int x24055 = x23844;
                x23845[x24055] = x24049;
                x23844 = x23844 + 1;
                x24061 = false;
              }
              if (!x24061) break;
            }
          }
        } else {
        }
      }
      bool x24072 = x23966;
      if (x24072) {
      } else {
        int x24077 = x24000;
        struct Anon2092052448* x24078 = x23843;
        struct Anon2092052448 x24079 = x24078[x24000];
        struct Anon2092052448 x24080 = x24079;
        bool x24081 = x24079.exists;;
        bool x24086 = x24081;
        if (x24081) {
          struct Anon2092052448 x24082 = x24080;
          int x24083 = x24082.key;;
          bool x24084 = x24083 == x23949;
          x24086 = x24084;
        }
        bool x24087 = x24086;
        if (x24087) {
          struct Anon2052879266 x24088 = x24079.aggs;;
          int x24095 = x24079.key;;
          double x24093;
          if (x24090) {
            double x24091 = x24088._0;;
            x24093 = x24091;
          } else {
            double x24091 = x24088._0;;
            double x24092 = x24091 + 1.0;
            x24093 = x24092;
          }
          struct Anon2052879266 x24094;
          x24094._0 = x24093;
          struct Anon2092052448 x24096;
          x24096.exists = true;
          x24096.key = x24095;
          x24096.aggs = x24094;
          x24078[x24000] = x24096;
        } else {
          struct Anon2092052448 x24128;
          x24128.exists = true;
          x24128.key = x23949;
          x24128.aggs = x24127;
          for (;;) {
            struct Anon2092052448 x24099 = x24080;
            bool x24100 = x24099.exists;;
            bool x24137;
            if (x24100) {
              int x24101 = x24099.key;;
              bool x24102 = x24101 == x23949;
              bool x24123;
              if (x24102) {
                struct Anon2052879266 x24103 = x24099.aggs;;
                int x24108 = x24077;
                struct Anon2092052448* x24110 = x23843;
                double x24106;
                if (x24090) {
                  double x24104 = x24103._0;;
                  x24106 = x24104;
                } else {
                  double x24104 = x24103._0;;
                  double x24105 = x24104 + 1.0;
                  x24106 = x24105;
                }
                struct Anon2052879266 x24107;
                x24107._0 = x24106;
                struct Anon2092052448 x24109;
                x24109.exists = true;
                x24109.key = x24101;
                x24109.aggs = x24107;
                x24110[x24108] = x24109;
                x24123 = false;
              } else {
                int x24113 = x24077;
                int x24114 = x24113 + 1;
                int x24115 = x24114 % 16777215;
                x24077 = x24115;
                struct Anon2092052448* x24117 = x23843;
                struct Anon2092052448 x24118 = x24117[x24115];
                x24080 = x24118;
                x24123 = true;
              }
              x24137 = x24123;
            } else {
              int x24125 = x24077;
              struct Anon2092052448* x24129 = x23843;
              x24129[x24125] = x24128;
              int x24131 = x23844;
              x23845[x24131] = x24125;
              x23844 = x23844 + 1;
              x24137 = false;
            }
            if (!x24137) break;
          }
        }
      }
    }
    int x24148 = x23844;
    int x24150;
    for(x24150=0; x24150 < x24148; x24150++) {
      int x24151 = x23845[x24150];
      struct Anon2092052448* x24152 = x23843;
      struct Anon2092052448 x24153 = x24152[x24151];
      struct Anon2052879266 x24154 = x24153.aggs;;
      int x24157 = x24156;
      struct Anon150112254* x24158 = x23857;
      struct Anon150112254 x24159 = x24158[x24156];
      struct Anon150112254 x24160 = x24159;
      bool x24161 = x24159.exists;;
      bool x24166 = x24161;
      if (x24161) {
        struct Anon150112254 x24162 = x24160;
        double x24163 = x24162.key;;
        double x24155 = x24154._0;;
        bool x24164 = x24163 == x24155;
        x24166 = x24164;
      }
      bool x24167 = x24166;
      if (x24167) {
        struct Anon2052879266 x24168 = x24159.aggs;;
        double x24172 = x24159.key;;
        double x24169 = x24168._0;;
        double x24170 = x24169 + 1.0;
        struct Anon2052879266 x24171;
        x24171._0 = x24170;
        struct Anon150112254 x24173;
        x24173.exists = true;
        x24173.key = x24172;
        x24173.aggs = x24171;
        x24158[x24156] = x24173;
      } else {
        double x24155 = x24154._0;;
        struct Anon150112254 x24202;
        x24202.exists = true;
        x24202.key = x24155;
        x24202.aggs = x5913;
        for (;;) {
          struct Anon150112254 x24176 = x24160;
          bool x24177 = x24176.exists;;
          bool x24211;
          if (x24177) {
            double x24178 = x24176.key;;
            bool x24179 = x24178 == x24155;
            bool x24199;
            if (x24179) {
              struct Anon2052879266 x24180 = x24176.aggs;;
              int x24184 = x24157;
              struct Anon150112254* x24186 = x23857;
              double x24181 = x24180._0;;
              double x24182 = x24181 + 1.0;
              struct Anon2052879266 x24183;
              x24183._0 = x24182;
              struct Anon150112254 x24185;
              x24185.exists = true;
              x24185.key = x24178;
              x24185.aggs = x24183;
              x24186[x24184] = x24185;
              x24199 = false;
            } else {
              int x24189 = x24157;
              int x24190 = x24189 + 1;
              int x24191 = x24190 % 16777215;
              x24157 = x24191;
              struct Anon150112254* x24193 = x23857;
              struct Anon150112254 x24194 = x24193[x24191];
              x24160 = x24194;
              x24199 = true;
            }
            x24211 = x24199;
          } else {
            int x24201 = x24157;
            struct Anon150112254* x24203 = x23857;
            x24203[x24201] = x24202;
            int x24205 = x23858;
            x23859[x24205] = x24201;
            x23858 = x23858 + 1;
            x24211 = false;
          }
          if (!x24211) break;
        }
      }
    }
    int x24220 = x23858;
    int x24222;
    for(x24222=0; x24222 < x24220; x24222++) {
      int x24223 = x23859[x24222];
      struct Anon150112254* x24224 = x23857;
      struct Anon150112254 x24225 = x24224[x24223];
      if (x972) {
      } else {
        double x24228 = x24225.key;;
        struct Anon2052879266 x24229 = x24225.aggs;;
        double x24230 = x24229._0;;
        printf("%.0f|%.0f\n",x24228,x24230);
        x23870 = x23870 + 1;
      }
    }
    int x24237 = x23870;
    printf("(%d rows)\n",x24237);
    gettimeofday(&x24241, NULL);
    timeval_subtract(&x24242, &x24241, &x24240);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x24242.tv_sec * 1000) + (x24242.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
