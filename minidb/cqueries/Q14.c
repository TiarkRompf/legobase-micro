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
int main(int x24247, char** x24248) {
  int x24249 = 0;
  int x24250 = 1048576;
  int x24251 = 0;
  int* x24254 = (int*)malloc(1048576 * sizeof(int));
  int* x24255 = x24254;
  double* x24262 = (double*)malloc(1048576 * sizeof(double));
  double* x24263 = x24262;
  double* x24264 = (double*)malloc(1048576 * sizeof(double));
  double* x24265 = x24264;
  long* x24272 = (long*)malloc(1048576 * sizeof(long));
  long* x24273 = x24272;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  int x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    int x24284 = x24249;
    bool x24285 = x24284 < x3;
    if (!x24285) break;
    for (;;) {
      int x24289 = x24249;
      char x24290 = x4[x24289];
      bool x24291 = x24290 != '|';
      bool x24296 = x24291;
      if (x24291) {
        int x24292 = x24249;
        char x24293 = x4[x24292];
        bool x24294 = x24293 != '\n';
        x24296 = x24294;
      }
      bool x24297 = x24296;
      if (!x24297) break;
      x24249 = x24249 + 1;
    }
    x24249 = x24249 + 1;
    int x24312 = 0;
    for (;;) {
      int x24313 = x24249;
      char x24314 = x4[x24313];
      bool x24315 = x24314 != '|';
      bool x24320 = x24315;
      if (x24315) {
        int x24316 = x24249;
        char x24317 = x4[x24316];
        bool x24318 = x24317 != '\n';
        x24320 = x24318;
      }
      bool x24321 = x24320;
      if (!x24321) break;
      int x24323 = x24312;
      int x24325 = x24249;
      int x24324 = x24323 * 10;
      char x24326 = x4[x24325];
      char x24327 = x24326 - '0';
      int x24328 = x24324 + x24327;
      x24312 = x24328;
      x24249 = x24249 + 1;
    }
    x24249 = x24249 + 1;
    int x24334 = x24312;
    for (;;) {
      int x24337 = x24249;
      char x24338 = x4[x24337];
      bool x24339 = x24338 != '|';
      bool x24344 = x24339;
      if (x24339) {
        int x24340 = x24249;
        char x24341 = x4[x24340];
        bool x24342 = x24341 != '\n';
        x24344 = x24342;
      }
      bool x24345 = x24344;
      if (!x24345) break;
      x24249 = x24249 + 1;
    }
    x24249 = x24249 + 1;
    for (;;) {
      int x24361 = x24249;
      char x24362 = x4[x24361];
      bool x24363 = x24362 != '|';
      bool x24368 = x24363;
      if (x24363) {
        int x24364 = x24249;
        char x24365 = x4[x24364];
        bool x24366 = x24365 != '\n';
        x24368 = x24366;
      }
      bool x24369 = x24368;
      if (!x24369) break;
      x24249 = x24249 + 1;
    }
    x24249 = x24249 + 1;
    for (;;) {
      int x24386 = x24249;
      char x24387 = x4[x24386];
      bool x24388 = x24387 != '.';
      bool x24393 = x24388;
      if (x24388) {
        int x24389 = x24249;
        char x24390 = x4[x24389];
        bool x24391 = x24390 != '|';
        x24393 = x24391;
      }
      bool x24394 = x24393;
      bool x24399 = x24394;
      if (x24394) {
        int x24395 = x24249;
        char x24396 = x4[x24395];
        bool x24397 = x24396 != '\n';
        x24399 = x24397;
      }
      bool x24400 = x24399;
      if (!x24400) break;
      x24249 = x24249 + 1;
    }
    int x24412 = x24249;
    char x24413 = x4[x24412];
    bool x24414 = x24413 == '.';
    if (x24414) {
      x24249 = x24249 + 1;
      for (;;) {
        int x24416 = x24249;
        char x24417 = x4[x24416];
        bool x24418 = x24417 != '|';
        bool x24423 = x24418;
        if (x24418) {
          int x24419 = x24249;
          char x24420 = x4[x24419];
          bool x24421 = x24420 != '\n';
          x24423 = x24421;
        }
        bool x24424 = x24423;
        if (!x24424) break;
        x24249 = x24249 + 1;
      }
    } else {
    }
    x24249 = x24249 + 1;
    int x24449 = 0;
    int x24450 = 1;
    for (;;) {
      int x24451 = x24249;
      char x24452 = x4[x24451];
      bool x24453 = x24452 != '.';
      bool x24458 = x24453;
      if (x24453) {
        int x24454 = x24249;
        char x24455 = x4[x24454];
        bool x24456 = x24455 != '|';
        x24458 = x24456;
      }
      bool x24459 = x24458;
      bool x24464 = x24459;
      if (x24459) {
        int x24460 = x24249;
        char x24461 = x4[x24460];
        bool x24462 = x24461 != '\n';
        x24464 = x24462;
      }
      bool x24465 = x24464;
      if (!x24465) break;
      int x24467 = x24449;
      int x24469 = x24249;
      int x24468 = x24467 * 10;
      char x24470 = x4[x24469];
      char x24471 = x24470 - '0';
      int x24472 = x24468 + x24471;
      x24449 = x24472;
      x24249 = x24249 + 1;
    }
    int x24477 = x24249;
    char x24478 = x4[x24477];
    bool x24479 = x24478 == '.';
    if (x24479) {
      x24249 = x24249 + 1;
      for (;;) {
        int x24481 = x24249;
        char x24482 = x4[x24481];
        bool x24483 = x24482 != '|';
        bool x24488 = x24483;
        if (x24483) {
          int x24484 = x24249;
          char x24485 = x4[x24484];
          bool x24486 = x24485 != '\n';
          x24488 = x24486;
        }
        bool x24489 = x24488;
        if (!x24489) break;
        int x24491 = x24449;
        int x24493 = x24249;
        int x24492 = x24491 * 10;
        char x24494 = x4[x24493];
        char x24495 = x24494 - '0';
        int x24496 = x24492 + x24495;
        x24449 = x24496;
        int x24498 = x24450;
        int x24499 = x24498 * 10;
        x24450 = x24499;
        x24249 = x24249 + 1;
      }
    } else {
    }
    x24249 = x24249 + 1;
    int x24508 = x24449;
    int x24510 = x24450;
    int x24514 = 0;
    int x24515 = 1;
    for (;;) {
      int x24516 = x24249;
      char x24517 = x4[x24516];
      bool x24518 = x24517 != '.';
      bool x24523 = x24518;
      if (x24518) {
        int x24519 = x24249;
        char x24520 = x4[x24519];
        bool x24521 = x24520 != '|';
        x24523 = x24521;
      }
      bool x24524 = x24523;
      bool x24529 = x24524;
      if (x24524) {
        int x24525 = x24249;
        char x24526 = x4[x24525];
        bool x24527 = x24526 != '\n';
        x24529 = x24527;
      }
      bool x24530 = x24529;
      if (!x24530) break;
      int x24532 = x24514;
      int x24534 = x24249;
      int x24533 = x24532 * 10;
      char x24535 = x4[x24534];
      char x24536 = x24535 - '0';
      int x24537 = x24533 + x24536;
      x24514 = x24537;
      x24249 = x24249 + 1;
    }
    int x24542 = x24249;
    char x24543 = x4[x24542];
    bool x24544 = x24543 == '.';
    if (x24544) {
      x24249 = x24249 + 1;
      for (;;) {
        int x24546 = x24249;
        char x24547 = x4[x24546];
        bool x24548 = x24547 != '|';
        bool x24553 = x24548;
        if (x24548) {
          int x24549 = x24249;
          char x24550 = x4[x24549];
          bool x24551 = x24550 != '\n';
          x24553 = x24551;
        }
        bool x24554 = x24553;
        if (!x24554) break;
        int x24556 = x24514;
        int x24558 = x24249;
        int x24557 = x24556 * 10;
        char x24559 = x4[x24558];
        char x24560 = x24559 - '0';
        int x24561 = x24557 + x24560;
        x24514 = x24561;
        int x24563 = x24515;
        int x24564 = x24563 * 10;
        x24515 = x24564;
        x24249 = x24249 + 1;
      }
    } else {
    }
    x24249 = x24249 + 1;
    int x24573 = x24514;
    int x24575 = x24515;
    for (;;) {
      int x24581 = x24249;
      char x24582 = x4[x24581];
      bool x24583 = x24582 != '.';
      bool x24588 = x24583;
      if (x24583) {
        int x24584 = x24249;
        char x24585 = x4[x24584];
        bool x24586 = x24585 != '|';
        x24588 = x24586;
      }
      bool x24589 = x24588;
      bool x24594 = x24589;
      if (x24589) {
        int x24590 = x24249;
        char x24591 = x4[x24590];
        bool x24592 = x24591 != '\n';
        x24594 = x24592;
      }
      bool x24595 = x24594;
      if (!x24595) break;
      x24249 = x24249 + 1;
    }
    int x24607 = x24249;
    char x24608 = x4[x24607];
    bool x24609 = x24608 == '.';
    if (x24609) {
      x24249 = x24249 + 1;
      for (;;) {
        int x24611 = x24249;
        char x24612 = x4[x24611];
        bool x24613 = x24612 != '|';
        bool x24618 = x24613;
        if (x24613) {
          int x24614 = x24249;
          char x24615 = x4[x24614];
          bool x24616 = x24615 != '\n';
          x24618 = x24616;
        }
        bool x24619 = x24618;
        if (!x24619) break;
        x24249 = x24249 + 1;
      }
    } else {
    }
    x24249 = x24249 + 1;
    x24249 = x24249 + 2;
    x24249 = x24249 + 2;
    int x24650 = 0;
    for (;;) {
      int x24651 = x24249;
      char x24652 = x4[x24651];
      bool x24653 = x24652 != '-';
      bool x24658 = x24653;
      if (x24653) {
        int x24654 = x24249;
        char x24655 = x4[x24654];
        bool x24656 = x24655 != '\n';
        x24658 = x24656;
      }
      bool x24659 = x24658;
      if (!x24659) break;
      int x24661 = x24650;
      int x24663 = x24249;
      int x24662 = x24661 * 10;
      char x24664 = x4[x24663];
      char x24665 = x24664 - '0';
      int x24666 = x24662 + x24665;
      x24650 = x24666;
      x24249 = x24249 + 1;
    }
    x24249 = x24249 + 1;
    int x24672 = x24650;
    int x24674 = 0;
    for (;;) {
      int x24675 = x24249;
      char x24676 = x4[x24675];
      bool x24677 = x24676 != '-';
      bool x24682 = x24677;
      if (x24677) {
        int x24678 = x24249;
        char x24679 = x4[x24678];
        bool x24680 = x24679 != '\n';
        x24682 = x24680;
      }
      bool x24683 = x24682;
      if (!x24683) break;
      int x24685 = x24674;
      int x24687 = x24249;
      int x24686 = x24685 * 10;
      char x24688 = x4[x24687];
      char x24689 = x24688 - '0';
      int x24690 = x24686 + x24689;
      x24674 = x24690;
      x24249 = x24249 + 1;
    }
    x24249 = x24249 + 1;
    int x24696 = x24674;
    int x24698 = 0;
    for (;;) {
      int x24699 = x24249;
      char x24700 = x4[x24699];
      bool x24701 = x24700 != '|';
      bool x24706 = x24701;
      if (x24701) {
        int x24702 = x24249;
        char x24703 = x4[x24702];
        bool x24704 = x24703 != '\n';
        x24706 = x24704;
      }
      bool x24707 = x24706;
      if (!x24707) break;
      int x24709 = x24698;
      int x24711 = x24249;
      int x24710 = x24709 * 10;
      char x24712 = x4[x24711];
      char x24713 = x24712 - '0';
      int x24714 = x24710 + x24713;
      x24698 = x24714;
      x24249 = x24249 + 1;
    }
    x24249 = x24249 + 1;
    int x24720 = x24698;
    for (;;) {
      int x24727 = x24249;
      char x24728 = x4[x24727];
      bool x24729 = x24728 != '-';
      bool x24734 = x24729;
      if (x24729) {
        int x24730 = x24249;
        char x24731 = x4[x24730];
        bool x24732 = x24731 != '\n';
        x24734 = x24732;
      }
      bool x24735 = x24734;
      if (!x24735) break;
      x24249 = x24249 + 1;
    }
    x24249 = x24249 + 1;
    for (;;) {
      int x24751 = x24249;
      char x24752 = x4[x24751];
      bool x24753 = x24752 != '-';
      bool x24758 = x24753;
      if (x24753) {
        int x24754 = x24249;
        char x24755 = x4[x24754];
        bool x24756 = x24755 != '\n';
        x24758 = x24756;
      }
      bool x24759 = x24758;
      if (!x24759) break;
      x24249 = x24249 + 1;
    }
    x24249 = x24249 + 1;
    for (;;) {
      int x24775 = x24249;
      char x24776 = x4[x24775];
      bool x24777 = x24776 != '|';
      bool x24782 = x24777;
      if (x24777) {
        int x24778 = x24249;
        char x24779 = x4[x24778];
        bool x24780 = x24779 != '\n';
        x24782 = x24780;
      }
      bool x24783 = x24782;
      if (!x24783) break;
      x24249 = x24249 + 1;
    }
    x24249 = x24249 + 1;
    for (;;) {
      int x24803 = x24249;
      char x24804 = x4[x24803];
      bool x24805 = x24804 != '-';
      bool x24810 = x24805;
      if (x24805) {
        int x24806 = x24249;
        char x24807 = x4[x24806];
        bool x24808 = x24807 != '\n';
        x24810 = x24808;
      }
      bool x24811 = x24810;
      if (!x24811) break;
      x24249 = x24249 + 1;
    }
    x24249 = x24249 + 1;
    for (;;) {
      int x24827 = x24249;
      char x24828 = x4[x24827];
      bool x24829 = x24828 != '-';
      bool x24834 = x24829;
      if (x24829) {
        int x24830 = x24249;
        char x24831 = x4[x24830];
        bool x24832 = x24831 != '\n';
        x24834 = x24832;
      }
      bool x24835 = x24834;
      if (!x24835) break;
      x24249 = x24249 + 1;
    }
    x24249 = x24249 + 1;
    for (;;) {
      int x24851 = x24249;
      char x24852 = x4[x24851];
      bool x24853 = x24852 != '|';
      bool x24858 = x24853;
      if (x24853) {
        int x24854 = x24249;
        char x24855 = x4[x24854];
        bool x24856 = x24855 != '\n';
        x24858 = x24856;
      }
      bool x24859 = x24858;
      if (!x24859) break;
      x24249 = x24249 + 1;
    }
    x24249 = x24249 + 1;
    for (;;) {
      int x24878 = x24249;
      char x24879 = x4[x24878];
      bool x24880 = x24879 != '|';
      bool x24885 = x24880;
      if (x24880) {
        int x24881 = x24249;
        char x24882 = x4[x24881];
        bool x24883 = x24882 != '\n';
        x24885 = x24883;
      }
      bool x24886 = x24885;
      if (!x24886) break;
      x24249 = x24249 + 1;
    }
    x24249 = x24249 + 1;
    for (;;) {
      int x24896 = x24249;
      char x24897 = x4[x24896];
      bool x24898 = x24897 != '|';
      bool x24903 = x24898;
      if (x24898) {
        int x24899 = x24249;
        char x24900 = x4[x24899];
        bool x24901 = x24900 != '\n';
        x24903 = x24901;
      }
      bool x24904 = x24903;
      if (!x24904) break;
      x24249 = x24249 + 1;
    }
    x24249 = x24249 + 1;
    for (;;) {
      int x24914 = x24249;
      char x24915 = x4[x24914];
      bool x24916 = x24915 != '|';
      bool x24921 = x24916;
      if (x24916) {
        int x24917 = x24249;
        char x24918 = x4[x24917];
        bool x24919 = x24918 != '\n';
        x24921 = x24919;
      }
      bool x24922 = x24921;
      if (!x24922) break;
      x24249 = x24249 + 1;
    }
    x24249 = x24249 + 1;
    int x24932 = x24251;
    int x24933 = x24250;
    bool x24934 = x24932 == x24933;
    if (x24934) {
      int x24935 = x24933 * 4;
      x24250 = x24935;
      printf("buffer.resize %d\n",x24935);
      int* x24941 = x24255;
      int* x24942 = (int*)realloc(x24941,x24935 * sizeof(int));
      x24255 = x24942;
      double* x24953 = x24263;
      double* x24954 = (double*)realloc(x24953,x24935 * sizeof(double));
      x24263 = x24954;
      double* x24956 = x24265;
      double* x24957 = (double*)realloc(x24956,x24935 * sizeof(double));
      x24265 = x24957;
      long* x24968 = x24273;
      long* x24969 = (long*)realloc(x24968,x24935 * sizeof(long));
      x24273 = x24969;
    } else {
    }
    int* x24990 = x24255;
    x24990[x24932] = x24334;
    double* x24998 = x24263;
    double x24509 = (double)x24508;
    double x24511 = (double)x24510;
    double x24512 = x24509 / x24511;
    x24998[x24932] = x24512;
    double* x25000 = x24265;
    double x24574 = (double)x24573;
    double x24576 = (double)x24575;
    double x24577 = x24574 / x24576;
    x25000[x24932] = x24577;
    long* x25008 = x24273;
    long x24721 = x24672 * 10000L;
    long x24722 = x24696 * 100L;
    long x24723 = x24721 + x24722;
    long x24724 = x24723 + x24720;
    x25008[x24932] = x24724;
    x24251 = x24251 + 1;
  }
  int x25023 = 0;
  int x25024 = 1048576;
  int x25025 = 0;
  int* x25026 = (int*)malloc(1048576 * sizeof(int));
  int* x25027 = x25026;
  char** x25034 = (char**)malloc(1048576 * sizeof(char*));
  char** x25035 = x25034;
  int x995 = open("../databases/sf2/part.tbl",0);
  int x996 = fsize(x995);
  char* x997 = mmap(0, x996, PROT_READ, MAP_FILE | MAP_SHARED, x995, 0);
  for (;;) {
    int x25045 = x25023;
    bool x25046 = x25045 < x996;
    if (!x25046) break;
    int x25049 = 0;
    for (;;) {
      int x25050 = x25023;
      char x25051 = x997[x25050];
      bool x25052 = x25051 != '|';
      bool x25057 = x25052;
      if (x25052) {
        int x25053 = x25023;
        char x25054 = x997[x25053];
        bool x25055 = x25054 != '\n';
        x25057 = x25055;
      }
      bool x25058 = x25057;
      if (!x25058) break;
      int x25060 = x25049;
      int x25062 = x25023;
      int x25061 = x25060 * 10;
      char x25063 = x997[x25062];
      char x25064 = x25063 - '0';
      int x25065 = x25061 + x25064;
      x25049 = x25065;
      x25023 = x25023 + 1;
    }
    x25023 = x25023 + 1;
    int x25071 = x25049;
    for (;;) {
      int x25073 = x25023;
      char x25074 = x997[x25073];
      bool x25075 = x25074 != '|';
      bool x25080 = x25075;
      if (x25075) {
        int x25076 = x25023;
        char x25077 = x997[x25076];
        bool x25078 = x25077 != '\n';
        x25080 = x25078;
      }
      bool x25081 = x25080;
      if (!x25081) break;
      x25023 = x25023 + 1;
    }
    x25023 = x25023 + 1;
    for (;;) {
      int x25091 = x25023;
      char x25092 = x997[x25091];
      bool x25093 = x25092 != '|';
      bool x25098 = x25093;
      if (x25093) {
        int x25094 = x25023;
        char x25095 = x997[x25094];
        bool x25096 = x25095 != '\n';
        x25098 = x25096;
      }
      bool x25099 = x25098;
      if (!x25099) break;
      x25023 = x25023 + 1;
    }
    x25023 = x25023 + 1;
    for (;;) {
      int x25109 = x25023;
      char x25110 = x997[x25109];
      bool x25111 = x25110 != '|';
      bool x25116 = x25111;
      if (x25111) {
        int x25112 = x25023;
        char x25113 = x997[x25112];
        bool x25114 = x25113 != '\n';
        x25116 = x25114;
      }
      bool x25117 = x25116;
      if (!x25117) break;
      x25023 = x25023 + 1;
    }
    x25023 = x25023 + 1;
    int x25126 = x25023;
    for (;;) {
      int x25127 = x25023;
      char x25128 = x997[x25127];
      bool x25129 = x25128 != '|';
      bool x25134 = x25129;
      if (x25129) {
        int x25130 = x25023;
        char x25131 = x997[x25130];
        bool x25132 = x25131 != '\n';
        x25134 = x25132;
      }
      bool x25135 = x25134;
      if (!x25135) break;
      x25023 = x25023 + 1;
    }
    x25023 = x25023 + 1;
    for (;;) {
      int x25146 = x25023;
      char x25147 = x997[x25146];
      bool x25148 = x25147 != '|';
      bool x25153 = x25148;
      if (x25148) {
        int x25149 = x25023;
        char x25150 = x997[x25149];
        bool x25151 = x25150 != '\n';
        x25153 = x25151;
      }
      bool x25154 = x25153;
      if (!x25154) break;
      x25023 = x25023 + 1;
    }
    x25023 = x25023 + 1;
    for (;;) {
      int x25169 = x25023;
      char x25170 = x997[x25169];
      bool x25171 = x25170 != '|';
      bool x25176 = x25171;
      if (x25171) {
        int x25172 = x25023;
        char x25173 = x997[x25172];
        bool x25174 = x25173 != '\n';
        x25176 = x25174;
      }
      bool x25177 = x25176;
      if (!x25177) break;
      x25023 = x25023 + 1;
    }
    x25023 = x25023 + 1;
    for (;;) {
      int x25189 = x25023;
      char x25190 = x997[x25189];
      bool x25191 = x25190 != '.';
      bool x25196 = x25191;
      if (x25191) {
        int x25192 = x25023;
        char x25193 = x997[x25192];
        bool x25194 = x25193 != '|';
        x25196 = x25194;
      }
      bool x25197 = x25196;
      bool x25202 = x25197;
      if (x25197) {
        int x25198 = x25023;
        char x25199 = x997[x25198];
        bool x25200 = x25199 != '\n';
        x25202 = x25200;
      }
      bool x25203 = x25202;
      if (!x25203) break;
      x25023 = x25023 + 1;
    }
    int x25215 = x25023;
    char x25216 = x997[x25215];
    bool x25217 = x25216 == '.';
    if (x25217) {
      x25023 = x25023 + 1;
      for (;;) {
        int x25219 = x25023;
        char x25220 = x997[x25219];
        bool x25221 = x25220 != '|';
        bool x25226 = x25221;
        if (x25221) {
          int x25222 = x25023;
          char x25223 = x997[x25222];
          bool x25224 = x25223 != '\n';
          x25226 = x25224;
        }
        bool x25227 = x25226;
        if (!x25227) break;
        x25023 = x25023 + 1;
      }
    } else {
    }
    x25023 = x25023 + 1;
    for (;;) {
      int x25252 = x25023;
      char x25253 = x997[x25252];
      bool x25254 = x25253 != '|';
      bool x25259 = x25254;
      if (x25254) {
        int x25255 = x25023;
        char x25256 = x997[x25255];
        bool x25257 = x25256 != '\n';
        x25259 = x25257;
      }
      bool x25260 = x25259;
      if (!x25260) break;
      x25023 = x25023 + 1;
    }
    x25023 = x25023 + 1;
    int x25270 = x25025;
    int x25271 = x25024;
    bool x25272 = x25270 == x25271;
    if (x25272) {
      int x25273 = x25271 * 4;
      x25024 = x25273;
      printf("buffer.resize %d\n",x25273);
      int* x25276 = x25027;
      int* x25277 = (int*)realloc(x25276,x25273 * sizeof(int));
      x25027 = x25277;
      char** x25288 = x25035;
      char** x25289 = (char**)realloc(x25288,x25273 * sizeof(char*));
      x25035 = x25289;
    } else {
    }
    int* x25305 = x25027;
    x25305[x25270] = x25071;
    char** x25313 = x25035;
    char* x25143 = x997+x25126;
    x25313[x25270] = x25143;
    x25025 = x25025 + 1;
  }
  char x9302 = "Total"[0];
  int x9303 = x9302 * 41;
  char x9304 = "Total"[1];
  int x9305 = x9303 + x9304;
  int x9306 = x9305 * 41;
  char x9307 = "Total"[2];
  int x9308 = x9306 + x9307;
  int x9309 = x9308 * 41;
  char x9310 = "Total"[3];
  int x9311 = x9309 + x9310;
  int x9312 = x9311 & 16777215;
  bool x972 = true == false;
  float x25602 = (float)100;
  double x25603 = (double)x25602;
  int x25326;
  for(x25326=0; x25326 < 5; x25326++) {
    bool x25327 = false;
    int x25328 = 0;
    bool x25329 = false;
    int x25330 = 0;
    int* x25333 = (int*)malloc(134217728 * sizeof(int));
    int* x25334 = x25333;
    char** x25341 = (char**)malloc(134217728 * sizeof(char*));
    char** x25342 = x25341;
    int x25351 = 0;
    int* x25352 = (int*)malloc(67108864 * sizeof(int));
    int* x25353 = (int*)malloc(134217728 * sizeof(int));
    int x25354;
    for(x25354=0; x25354 < 67108864; x25354++) {
      x25352[x25354] = -1;
    }
    struct Anon984006423* x25360 = (struct Anon984006423*)malloc(16777216 * sizeof(struct Anon984006423));
    struct Anon984006423* x25361 = x25360;
    int x25362 = 0;
    int* x25363 = (int*)malloc(16777216 * sizeof(int));
    int x25364;
    for(x25364=0; x25364 < 16777216; x25364++) {
      struct Anon984006423* x25365 = x25361;
      struct Anon984006423 x25366 = x25365[x25364];
      char* x25367 = x25366.key;;
      struct Anon189208763 x25368 = x25366.aggs;;
      struct Anon984006423 x25369;
      x25369.exists = false;
      x25369.key = x25367;
      x25369.aggs = x25368;
      x25365[x25364] = x25369;
    }
    int x25375 = 0;
    struct timeval x25618, x25619, x25620;
    gettimeofday(&x25618, NULL);
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x25377 = x25327;
      bool x25378 = !x25377;
      bool x25383 = x25378;
      if (x25378) {
        int x25379 = x25328;
        int x25380 = x25025;
        bool x25381 = x25379 < x25380;
        x25383 = x25381;
      }
      bool x25384 = x25383;
      if (!x25384) break;
      int x25386 = x25328;
      int* x25387 = x25027;
      int x25388 = x25387[x25386];
      char** x25395 = x25035;
      char* x25396 = x25395[x25386];
      x25328 = x25328 + 1;
      int x25407 = x25351;
      int* x25408 = x25334;
      x25408[x25407] = x25388;
      char** x25416 = x25342;
      x25416[x25407] = x25396;
      x25351 = x25351 + 1;
      int x25427 = x25388 & 67108863;
      int x25428 = x25352[x25427];
      x25352[x25427] = x25407;
      x25353[x25407] = x25428;
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x25434 = x25329;
      bool x25435 = !x25434;
      bool x25440 = x25435;
      if (x25435) {
        int x25436 = x25330;
        int x25437 = x24251;
        bool x25438 = x25436 < x25437;
        x25440 = x25438;
      }
      bool x25441 = x25440;
      if (!x25441) break;
      int x25443 = x25330;
      int* x25446 = x24255;
      int x25447 = x25446[x25443];
      double* x25454 = x24263;
      double x25455 = x25454[x25443];
      double* x25456 = x24265;
      double x25457 = x25456[x25443];
      long* x25464 = x24273;
      long x25465 = x25464[x25443];
      x25330 = x25330 + 1;
      bool x25478 = x25465 >= 19940301L;
      bool x25480 = x25478;
      if (x25478) {
        bool x25479 = x25465 < 19940401L;
        x25480 = x25479;
      }
      bool x25481 = x25480;
      if (x25481) {
        int x25482 = x25447 & 67108863;
        int x25483 = x25352[x25482];
        int x25484 = x25483;
        double x25528 = 1.0 - x25457;
        double x25529 = x25455 * x25528;
        for (;;) {
          int x25485 = x25484;
          bool x25486 = x25485 != -1;
          if (!x25486) break;
          int x25488 = x25484;
          int* x25489 = x25334;
          int x25490 = x25489[x25488];
          char** x25497 = x25342;
          char* x25498 = x25497[x25488];
          int x25508 = x25353[x25488];
          x25484 = x25508;
          bool x25510 = x25490 == x25447;
          if (x25510) {
            int x25514 = x9312;
            struct Anon984006423* x25515 = x25361;
            struct Anon984006423 x25516 = x25515[x9312];
            struct Anon984006423 x25517 = x25516;
            bool x25518 = x25516.exists;;
            bool x25523 = x25518;
            if (x25518) {
              struct Anon984006423 x25519 = x25517;
              char* x25520 = x25519.key;;
              bool x25521 = strcmp(x25520,"Total") == 0;;
              x25523 = x25521;
            }
            bool x25524 = x25523;
            if (x25524) {
              struct Anon189208763 x25525 = x25516.aggs;;
              char* x25535 = x25516.key;;
              bool x25526 = strncmp(x25498,"PROMO", strlen("PROMO")) == 0;;
              double x25531;
              if (x25526) {
                double x25527 = x25525._0;;
                double x25530 = x25527 + x25529;
                x25531 = x25530;
              } else {
                double x25527 = x25525._0;;
                x25531 = x25527;
              }
              double x25532 = x25525._1;;
              double x25533 = x25532 + x25529;
              struct Anon189208763 x25534;
              x25534._0 = x25531;
              x25534._1 = x25533;
              struct Anon984006423 x25536;
              x25536.exists = true;
              x25536.key = x25535;
              x25536.aggs = x25534;
              x25515[x9312] = x25536;
            } else {
              bool x25526 = strncmp(x25498,"PROMO", strlen("PROMO")) == 0;;
              double x25568;
              if (x25526) {
                x25568 = x25529;
              } else {
                x25568 = 0.0;
              }
              struct Anon189208763 x25569;
              x25569._0 = x25568;
              x25569._1 = x25529;
              struct Anon984006423 x25570;
              x25570.exists = true;
              x25570.key = "Total";
              x25570.aggs = x25569;
              for (;;) {
                struct Anon984006423 x25539 = x25517;
                bool x25540 = x25539.exists;;
                bool x25579;
                if (x25540) {
                  char* x25541 = x25539.key;;
                  bool x25542 = strcmp(x25541,"Total") == 0;;
                  bool x25565;
                  if (x25542) {
                    struct Anon189208763 x25543 = x25539.aggs;;
                    int x25550 = x25514;
                    struct Anon984006423* x25552 = x25361;
                    double x25546;
                    if (x25526) {
                      double x25544 = x25543._0;;
                      double x25545 = x25544 + x25529;
                      x25546 = x25545;
                    } else {
                      double x25544 = x25543._0;;
                      x25546 = x25544;
                    }
                    double x25547 = x25543._1;;
                    double x25548 = x25547 + x25529;
                    struct Anon189208763 x25549;
                    x25549._0 = x25546;
                    x25549._1 = x25548;
                    struct Anon984006423 x25551;
                    x25551.exists = true;
                    x25551.key = x25541;
                    x25551.aggs = x25549;
                    x25552[x25550] = x25551;
                    x25565 = false;
                  } else {
                    int x25555 = x25514;
                    int x25556 = x25555 + 1;
                    int x25557 = x25556 % 16777215;
                    x25514 = x25557;
                    struct Anon984006423* x25559 = x25361;
                    struct Anon984006423 x25560 = x25559[x25557];
                    x25517 = x25560;
                    x25565 = true;
                  }
                  x25579 = x25565;
                } else {
                  int x25567 = x25514;
                  struct Anon984006423* x25571 = x25361;
                  x25571[x25567] = x25570;
                  int x25573 = x25362;
                  x25363[x25573] = x25567;
                  x25362 = x25362 + 1;
                  x25579 = false;
                }
                if (!x25579) break;
              }
            }
          } else {
          }
        }
      } else {
      }
    }
    int x25594 = x25362;
    int x25596;
    for(x25596=0; x25596 < x25594; x25596++) {
      int x25597 = x25363[x25596];
      struct Anon984006423* x25598 = x25361;
      struct Anon984006423 x25599 = x25598[x25597];
      struct Anon189208763 x25600 = x25599.aggs;;
      if (x972) {
      } else {
        double x25601 = x25600._0;;
        double x25604 = x25601 * x25603;
        double x25605 = x25600._1;;
        double x25606 = x25604 / x25605;
        printf("%.4f\n",x25606);
        x25375 = x25375 + 1;
      }
    }
    int x25615 = x25375;
    printf("(%d rows)\n",x25615);
    gettimeofday(&x25619, NULL);
    timeval_subtract(&x25620, &x25619, &x25618);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x25620.tv_sec * 1000) + (x25620.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
