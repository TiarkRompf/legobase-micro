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

struct Anon2131541195 {
double total;
};

struct Anon2092052448 {
bool exists;
int key;
struct Anon2052879266 aggs;
};

struct Anon0 {
struct Anon2131541195 left;
struct Anon2092052448 right;
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
int main(int x20606, char** x20607) {
  int x20608 = 0;
  int x20609 = 1048576;
  int x20610 = 0;
  int* x20611 = (int*)malloc(1048576 * sizeof(int));
  int* x20612 = x20611;
  int* x20613 = (int*)malloc(1048576 * sizeof(int));
  int* x20614 = x20613;
  int* x20615 = (int*)malloc(1048576 * sizeof(int));
  int* x20616 = x20615;
  double* x20617 = (double*)malloc(1048576 * sizeof(double));
  double* x20618 = x20617;
  int x1301 = open("../databases/sf2/partsupp.tbl",0);
  int x1302 = fsize(x1301);
  char* x1303 = mmap(0, x1302, PROT_READ, MAP_FILE | MAP_SHARED, x1301, 0);
  for (;;) {
    int x20621 = x20608;
    bool x20622 = x20621 < x1302;
    if (!x20622) break;
    int x20625 = 0;
    for (;;) {
      int x20626 = x20608;
      char x20627 = x1303[x20626];
      bool x20628 = x20627 != '|';
      bool x20633 = x20628;
      if (x20628) {
        int x20629 = x20608;
        char x20630 = x1303[x20629];
        bool x20631 = x20630 != '\n';
        x20633 = x20631;
      }
      bool x20634 = x20633;
      if (!x20634) break;
      int x20636 = x20625;
      int x20638 = x20608;
      int x20637 = x20636 * 10;
      char x20639 = x1303[x20638];
      char x20640 = x20639 - '0';
      int x20641 = x20637 + x20640;
      x20625 = x20641;
      x20608 = x20608 + 1;
    }
    x20608 = x20608 + 1;
    int x20647 = x20625;
    int x20649 = 0;
    for (;;) {
      int x20650 = x20608;
      char x20651 = x1303[x20650];
      bool x20652 = x20651 != '|';
      bool x20657 = x20652;
      if (x20652) {
        int x20653 = x20608;
        char x20654 = x1303[x20653];
        bool x20655 = x20654 != '\n';
        x20657 = x20655;
      }
      bool x20658 = x20657;
      if (!x20658) break;
      int x20660 = x20649;
      int x20662 = x20608;
      int x20661 = x20660 * 10;
      char x20663 = x1303[x20662];
      char x20664 = x20663 - '0';
      int x20665 = x20661 + x20664;
      x20649 = x20665;
      x20608 = x20608 + 1;
    }
    x20608 = x20608 + 1;
    int x20671 = x20649;
    int x20673 = 0;
    for (;;) {
      int x20674 = x20608;
      char x20675 = x1303[x20674];
      bool x20676 = x20675 != '|';
      bool x20681 = x20676;
      if (x20676) {
        int x20677 = x20608;
        char x20678 = x1303[x20677];
        bool x20679 = x20678 != '\n';
        x20681 = x20679;
      }
      bool x20682 = x20681;
      if (!x20682) break;
      int x20684 = x20673;
      int x20686 = x20608;
      int x20685 = x20684 * 10;
      char x20687 = x1303[x20686];
      char x20688 = x20687 - '0';
      int x20689 = x20685 + x20688;
      x20673 = x20689;
      x20608 = x20608 + 1;
    }
    x20608 = x20608 + 1;
    int x20695 = x20673;
    int x20697 = 0;
    int x20698 = 1;
    for (;;) {
      int x20699 = x20608;
      char x20700 = x1303[x20699];
      bool x20701 = x20700 != '.';
      bool x20706 = x20701;
      if (x20701) {
        int x20702 = x20608;
        char x20703 = x1303[x20702];
        bool x20704 = x20703 != '|';
        x20706 = x20704;
      }
      bool x20707 = x20706;
      bool x20712 = x20707;
      if (x20707) {
        int x20708 = x20608;
        char x20709 = x1303[x20708];
        bool x20710 = x20709 != '\n';
        x20712 = x20710;
      }
      bool x20713 = x20712;
      if (!x20713) break;
      int x20715 = x20697;
      int x20717 = x20608;
      int x20716 = x20715 * 10;
      char x20718 = x1303[x20717];
      char x20719 = x20718 - '0';
      int x20720 = x20716 + x20719;
      x20697 = x20720;
      x20608 = x20608 + 1;
    }
    int x20725 = x20608;
    char x20726 = x1303[x20725];
    bool x20727 = x20726 == '.';
    if (x20727) {
      x20608 = x20608 + 1;
      for (;;) {
        int x20729 = x20608;
        char x20730 = x1303[x20729];
        bool x20731 = x20730 != '|';
        bool x20736 = x20731;
        if (x20731) {
          int x20732 = x20608;
          char x20733 = x1303[x20732];
          bool x20734 = x20733 != '\n';
          x20736 = x20734;
        }
        bool x20737 = x20736;
        if (!x20737) break;
        int x20739 = x20697;
        int x20741 = x20608;
        int x20740 = x20739 * 10;
        char x20742 = x1303[x20741];
        char x20743 = x20742 - '0';
        int x20744 = x20740 + x20743;
        x20697 = x20744;
        int x20746 = x20698;
        int x20747 = x20746 * 10;
        x20698 = x20747;
        x20608 = x20608 + 1;
      }
    } else {
    }
    x20608 = x20608 + 1;
    int x20756 = x20697;
    int x20758 = x20698;
    for (;;) {
      int x20762 = x20608;
      char x20763 = x1303[x20762];
      bool x20764 = x20763 != '|';
      bool x20769 = x20764;
      if (x20764) {
        int x20765 = x20608;
        char x20766 = x1303[x20765];
        bool x20767 = x20766 != '\n';
        x20769 = x20767;
      }
      bool x20770 = x20769;
      if (!x20770) break;
      x20608 = x20608 + 1;
    }
    x20608 = x20608 + 1;
    int x20780 = x20610;
    int x20781 = x20609;
    bool x20782 = x20780 == x20781;
    if (x20782) {
      int x20783 = x20781 * 4;
      x20609 = x20783;
      printf("buffer.resize %d\n",x20783);
      int* x20786 = x20612;
      int* x20787 = (int*)realloc(x20786,x20783 * sizeof(int));
      x20612 = x20787;
      int* x20789 = x20614;
      int* x20790 = (int*)realloc(x20789,x20783 * sizeof(int));
      x20614 = x20790;
      int* x20792 = x20616;
      int* x20793 = (int*)realloc(x20792,x20783 * sizeof(int));
      x20616 = x20793;
      double* x20795 = x20618;
      double* x20796 = (double*)realloc(x20795,x20783 * sizeof(double));
      x20618 = x20796;
    } else {
    }
    int* x20803 = x20612;
    x20803[x20780] = x20647;
    int* x20805 = x20614;
    x20805[x20780] = x20671;
    int* x20807 = x20616;
    x20807[x20780] = x20695;
    double* x20809 = x20618;
    double x20757 = (double)x20756;
    double x20759 = (double)x20758;
    double x20760 = x20757 / x20759;
    x20809[x20780] = x20760;
    x20610 = x20610 + 1;
  }
  int x20816 = 0;
  int x20817 = 1048576;
  int x20818 = 0;
  int* x20819 = (int*)malloc(1048576 * sizeof(int));
  int* x20820 = x20819;
  int* x20825 = (int*)malloc(1048576 * sizeof(int));
  int* x20826 = x20825;
  int x1747 = open("../databases/sf2/supplier.tbl",0);
  int x1748 = fsize(x1747);
  char* x1749 = mmap(0, x1748, PROT_READ, MAP_FILE | MAP_SHARED, x1747, 0);
  for (;;) {
    int x20833 = x20816;
    bool x20834 = x20833 < x1748;
    if (!x20834) break;
    int x20837 = 0;
    for (;;) {
      int x20838 = x20816;
      char x20839 = x1749[x20838];
      bool x20840 = x20839 != '|';
      bool x20845 = x20840;
      if (x20840) {
        int x20841 = x20816;
        char x20842 = x1749[x20841];
        bool x20843 = x20842 != '\n';
        x20845 = x20843;
      }
      bool x20846 = x20845;
      if (!x20846) break;
      int x20848 = x20837;
      int x20850 = x20816;
      int x20849 = x20848 * 10;
      char x20851 = x1749[x20850];
      char x20852 = x20851 - '0';
      int x20853 = x20849 + x20852;
      x20837 = x20853;
      x20816 = x20816 + 1;
    }
    x20816 = x20816 + 1;
    int x20859 = x20837;
    for (;;) {
      int x20861 = x20816;
      char x20862 = x1749[x20861];
      bool x20863 = x20862 != '|';
      bool x20868 = x20863;
      if (x20863) {
        int x20864 = x20816;
        char x20865 = x1749[x20864];
        bool x20866 = x20865 != '\n';
        x20868 = x20866;
      }
      bool x20869 = x20868;
      if (!x20869) break;
      x20816 = x20816 + 1;
    }
    x20816 = x20816 + 1;
    for (;;) {
      int x20879 = x20816;
      char x20880 = x1749[x20879];
      bool x20881 = x20880 != '|';
      bool x20886 = x20881;
      if (x20881) {
        int x20882 = x20816;
        char x20883 = x1749[x20882];
        bool x20884 = x20883 != '\n';
        x20886 = x20884;
      }
      bool x20887 = x20886;
      if (!x20887) break;
      x20816 = x20816 + 1;
    }
    x20816 = x20816 + 1;
    int x20897 = 0;
    for (;;) {
      int x20898 = x20816;
      char x20899 = x1749[x20898];
      bool x20900 = x20899 != '|';
      bool x20905 = x20900;
      if (x20900) {
        int x20901 = x20816;
        char x20902 = x1749[x20901];
        bool x20903 = x20902 != '\n';
        x20905 = x20903;
      }
      bool x20906 = x20905;
      if (!x20906) break;
      int x20908 = x20897;
      int x20910 = x20816;
      int x20909 = x20908 * 10;
      char x20911 = x1749[x20910];
      char x20912 = x20911 - '0';
      int x20913 = x20909 + x20912;
      x20897 = x20913;
      x20816 = x20816 + 1;
    }
    x20816 = x20816 + 1;
    int x20919 = x20897;
    for (;;) {
      int x20921 = x20816;
      char x20922 = x1749[x20921];
      bool x20923 = x20922 != '|';
      bool x20928 = x20923;
      if (x20923) {
        int x20924 = x20816;
        char x20925 = x1749[x20924];
        bool x20926 = x20925 != '\n';
        x20928 = x20926;
      }
      bool x20929 = x20928;
      if (!x20929) break;
      x20816 = x20816 + 1;
    }
    x20816 = x20816 + 1;
    for (;;) {
      int x20941 = x20816;
      char x20942 = x1749[x20941];
      bool x20943 = x20942 != '.';
      bool x20948 = x20943;
      if (x20943) {
        int x20944 = x20816;
        char x20945 = x1749[x20944];
        bool x20946 = x20945 != '|';
        x20948 = x20946;
      }
      bool x20949 = x20948;
      bool x20954 = x20949;
      if (x20949) {
        int x20950 = x20816;
        char x20951 = x1749[x20950];
        bool x20952 = x20951 != '\n';
        x20954 = x20952;
      }
      bool x20955 = x20954;
      if (!x20955) break;
      x20816 = x20816 + 1;
    }
    int x20967 = x20816;
    char x20968 = x1749[x20967];
    bool x20969 = x20968 == '.';
    if (x20969) {
      x20816 = x20816 + 1;
      for (;;) {
        int x20971 = x20816;
        char x20972 = x1749[x20971];
        bool x20973 = x20972 != '|';
        bool x20978 = x20973;
        if (x20973) {
          int x20974 = x20816;
          char x20975 = x1749[x20974];
          bool x20976 = x20975 != '\n';
          x20978 = x20976;
        }
        bool x20979 = x20978;
        if (!x20979) break;
        x20816 = x20816 + 1;
      }
    } else {
    }
    x20816 = x20816 + 1;
    for (;;) {
      int x21004 = x20816;
      char x21005 = x1749[x21004];
      bool x21006 = x21005 != '|';
      bool x21011 = x21006;
      if (x21006) {
        int x21007 = x20816;
        char x21008 = x1749[x21007];
        bool x21009 = x21008 != '\n';
        x21011 = x21009;
      }
      bool x21012 = x21011;
      if (!x21012) break;
      x20816 = x20816 + 1;
    }
    x20816 = x20816 + 1;
    int x21022 = x20818;
    int x21023 = x20817;
    bool x21024 = x21022 == x21023;
    if (x21024) {
      int x21025 = x21023 * 4;
      x20817 = x21025;
      printf("buffer.resize %d\n",x21025);
      int* x21028 = x20820;
      int* x21029 = (int*)realloc(x21028,x21025 * sizeof(int));
      x20820 = x21029;
      int* x21037 = x20826;
      int* x21038 = (int*)realloc(x21037,x21025 * sizeof(int));
      x20826 = x21038;
    } else {
    }
    int* x21051 = x20820;
    x21051[x21022] = x20859;
    int* x21057 = x20826;
    x21057[x21022] = x20919;
    x20818 = x20818 + 1;
  }
  int x21068 = 0;
  int x21069 = 1048576;
  int x21070 = 0;
  int* x21071 = (int*)malloc(1048576 * sizeof(int));
  int* x21072 = x21071;
  char** x21073 = (char**)malloc(1048576 * sizeof(char*));
  char** x21074 = x21073;
  int x1512 = open("../databases/sf2/nation.tbl",0);
  int x1513 = fsize(x1512);
  char* x1514 = mmap(0, x1513, PROT_READ, MAP_FILE | MAP_SHARED, x1512, 0);
  for (;;) {
    int x21079 = x21068;
    bool x21080 = x21079 < x1513;
    if (!x21080) break;
    int x21083 = 0;
    for (;;) {
      int x21084 = x21068;
      char x21085 = x1514[x21084];
      bool x21086 = x21085 != '|';
      bool x21091 = x21086;
      if (x21086) {
        int x21087 = x21068;
        char x21088 = x1514[x21087];
        bool x21089 = x21088 != '\n';
        x21091 = x21089;
      }
      bool x21092 = x21091;
      if (!x21092) break;
      int x21094 = x21083;
      int x21096 = x21068;
      int x21095 = x21094 * 10;
      char x21097 = x1514[x21096];
      char x21098 = x21097 - '0';
      int x21099 = x21095 + x21098;
      x21083 = x21099;
      x21068 = x21068 + 1;
    }
    x21068 = x21068 + 1;
    int x21105 = x21083;
    int x21106 = x21068;
    for (;;) {
      int x21107 = x21068;
      char x21108 = x1514[x21107];
      bool x21109 = x21108 != '|';
      bool x21114 = x21109;
      if (x21109) {
        int x21110 = x21068;
        char x21111 = x1514[x21110];
        bool x21112 = x21111 != '\n';
        x21114 = x21112;
      }
      bool x21115 = x21114;
      if (!x21115) break;
      x21068 = x21068 + 1;
    }
    x21068 = x21068 + 1;
    for (;;) {
      int x21126 = x21068;
      char x21127 = x1514[x21126];
      bool x21128 = x21127 != '|';
      bool x21133 = x21128;
      if (x21128) {
        int x21129 = x21068;
        char x21130 = x1514[x21129];
        bool x21131 = x21130 != '\n';
        x21133 = x21131;
      }
      bool x21134 = x21133;
      if (!x21134) break;
      x21068 = x21068 + 1;
    }
    x21068 = x21068 + 1;
    for (;;) {
      int x21149 = x21068;
      char x21150 = x1514[x21149];
      bool x21151 = x21150 != '|';
      bool x21156 = x21151;
      if (x21151) {
        int x21152 = x21068;
        char x21153 = x1514[x21152];
        bool x21154 = x21153 != '\n';
        x21156 = x21154;
      }
      bool x21157 = x21156;
      if (!x21157) break;
      x21068 = x21068 + 1;
    }
    x21068 = x21068 + 1;
    int x21167 = x21070;
    int x21168 = x21069;
    bool x21169 = x21167 == x21168;
    if (x21169) {
      int x21170 = x21168 * 4;
      x21069 = x21170;
      printf("buffer.resize %d\n",x21170);
      int* x21173 = x21072;
      int* x21174 = (int*)realloc(x21173,x21170 * sizeof(int));
      x21072 = x21174;
      char** x21176 = x21074;
      char** x21177 = (char**)realloc(x21176,x21170 * sizeof(char*));
      x21074 = x21177;
    } else {
    }
    int* x21187 = x21072;
    x21187[x21167] = x21105;
    char** x21189 = x21074;
    char* x21123 = x1514+x21106;
    x21189[x21167] = x21123;
    x21070 = x21070 + 1;
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
  int x21198;
  for(x21198=0; x21198 < 5; x21198++) {
    bool x21199 = false;
    int x21200 = 0;
    bool x21201 = false;
    int x21202 = 0;
    int* x21205 = (int*)malloc(134217728 * sizeof(int));
    int* x21206 = x21205;
    int x21213 = 0;
    int* x21214 = (int*)malloc(67108864 * sizeof(int));
    int* x21215 = (int*)malloc(134217728 * sizeof(int));
    int x21216;
    for(x21216=0; x21216 < 67108864; x21216++) {
      x21214[x21216] = -1;
    }
    bool x21221 = false;
    int x21222 = 0;
    int* x21232 = (int*)malloc(134217728 * sizeof(int));
    int* x21233 = x21232;
    int x21246 = 0;
    int* x21247 = (int*)malloc(67108864 * sizeof(int));
    int* x21248 = (int*)malloc(134217728 * sizeof(int));
    int x21249;
    for(x21249=0; x21249 < 67108864; x21249++) {
      x21247[x21249] = -1;
    }
    struct Anon2092052448* x21255 = (struct Anon2092052448*)malloc(16777216 * sizeof(struct Anon2092052448));
    struct Anon2092052448* x21256 = x21255;
    int x21257 = 0;
    int* x21258 = (int*)malloc(16777216 * sizeof(int));
    int x21259;
    for(x21259=0; x21259 < 16777216; x21259++) {
      struct Anon2092052448* x21260 = x21256;
      struct Anon2092052448 x21261 = x21260[x21259];
      int x21262 = x21261.key;;
      struct Anon2052879266 x21263 = x21261.aggs;;
      struct Anon2092052448 x21264;
      x21264.exists = false;
      x21264.key = x21262;
      x21264.aggs = x21263;
      x21260[x21259] = x21264;
    }
    int x21269 = 1048576;
    int x21270 = 0;
    int* x21273 = (int*)malloc(1048576 * sizeof(int));
    int* x21274 = x21273;
    double* x21275 = (double*)malloc(1048576 * sizeof(double));
    double* x21276 = x21275;
    struct Anon1007729034* x21280 = (struct Anon1007729034*)malloc(16777216 * sizeof(struct Anon1007729034));
    struct Anon1007729034* x21281 = x21280;
    int x21282 = 0;
    int* x21283 = (int*)malloc(16777216 * sizeof(int));
    int x21284;
    for(x21284=0; x21284 < 16777216; x21284++) {
      struct Anon1007729034* x21285 = x21281;
      struct Anon1007729034 x21286 = x21285[x21284];
      char* x21287 = x21286.key;;
      struct Anon2052879266 x21288 = x21286.aggs;;
      struct Anon1007729034 x21289;
      x21289.exists = false;
      x21289.key = x21287;
      x21289.aggs = x21288;
      x21285[x21284] = x21289;
    }
    double x21296 = 0.0;
    int x21300 = 0;
    struct timeval x21706, x21707, x21708;
    gettimeofday(&x21706, NULL);
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x21302 = x21201;
      bool x21303 = !x21302;
      bool x21308 = x21303;
      if (x21303) {
        int x21304 = x21202;
        int x21305 = x21070;
        bool x21306 = x21304 < x21305;
        x21308 = x21306;
      }
      bool x21309 = x21308;
      if (!x21309) break;
      int x21311 = x21202;
      int* x21312 = x21072;
      int x21313 = x21312[x21311];
      char** x21314 = x21074;
      char* x21315 = x21314[x21311];
      x21202 = x21202 + 1;
      bool x21322 = strcmp(x21315,"UNITED KINGDOM") == 0;;
      if (x21322) {
        int x21323 = x21213;
        int* x21324 = x21206;
        x21324[x21323] = x21313;
        x21213 = x21213 + 1;
        int x21333 = x21313 & 67108863;
        int x21334 = x21214[x21333];
        x21214[x21333] = x21323;
        x21215[x21323] = x21334;
      } else {
      }
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x21342 = x21199;
      bool x21343 = !x21342;
      bool x21348 = x21343;
      if (x21343) {
        int x21344 = x21200;
        int x21345 = x20818;
        bool x21346 = x21344 < x21345;
        x21348 = x21346;
      }
      bool x21349 = x21348;
      if (!x21349) break;
      int x21351 = x21200;
      int* x21352 = x20820;
      int x21353 = x21352[x21351];
      int* x21358 = x20826;
      int x21359 = x21358[x21351];
      x21200 = x21200 + 1;
      int x21368 = x21359 & 67108863;
      int x21369 = x21214[x21368];
      int x21370 = x21369;
      int x21414 = x21353 & 67108863;
      for (;;) {
        int x21371 = x21370;
        bool x21372 = x21371 != -1;
        if (!x21372) break;
        int x21374 = x21370;
        int* x21375 = x21206;
        int x21376 = x21375[x21374];
        int x21384 = x21215[x21374];
        x21370 = x21384;
        bool x21386 = x21376 == x21359;
        if (x21386) {
          int x21390 = x21246;
          int* x21399 = x21233;
          x21399[x21390] = x21353;
          x21246 = x21246 + 1;
          int x21415 = x21247[x21414];
          x21247[x21414] = x21390;
          x21248[x21390] = x21415;
        } else {
        }
      }
    }
    printf("%s\n","begin scan PARTSUPP");
    for (;;) {
      bool x21425 = x21221;
      bool x21426 = !x21425;
      bool x21431 = x21426;
      if (x21426) {
        int x21427 = x21222;
        int x21428 = x20610;
        bool x21429 = x21427 < x21428;
        x21431 = x21429;
      }
      bool x21432 = x21431;
      if (!x21432) break;
      int x21434 = x21222;
      int* x21435 = x20612;
      int x21436 = x21435[x21434];
      int* x21437 = x20614;
      int x21438 = x21437[x21434];
      int* x21439 = x20616;
      int x21440 = x21439[x21434];
      double* x21441 = x20618;
      double x21442 = x21441[x21434];
      x21222 = x21222 + 1;
      int x21447 = x21438 & 67108863;
      int x21448 = x21247[x21447];
      int x21449 = x21448;
      int x21483 = x21436 & 16777215;
      double x21497 = x21442 * x21440;
      struct Anon2052879266 x21530;
      x21530._0 = x21497;
      struct Anon2092052448 x21531;
      x21531.exists = true;
      x21531.key = x21436;
      x21531.aggs = x21530;
      for (;;) {
        int x21450 = x21449;
        bool x21451 = x21450 != -1;
        if (!x21451) break;
        int x21453 = x21449;
        int* x21462 = x21233;
        int x21463 = x21462[x21453];
        int x21477 = x21248[x21453];
        x21449 = x21477;
        bool x21479 = x21463 == x21438;
        if (x21479) {
          int x21484 = x21483;
          struct Anon2092052448* x21485 = x21256;
          struct Anon2092052448 x21486 = x21485[x21483];
          struct Anon2092052448 x21487 = x21486;
          bool x21488 = x21486.exists;;
          bool x21493 = x21488;
          if (x21488) {
            struct Anon2092052448 x21489 = x21487;
            int x21490 = x21489.key;;
            bool x21491 = x21490 == x21436;
            x21493 = x21491;
          }
          bool x21494 = x21493;
          if (x21494) {
            struct Anon2052879266 x21495 = x21486.aggs;;
            int x21500 = x21486.key;;
            double x21496 = x21495._0;;
            double x21498 = x21496 + x21497;
            struct Anon2052879266 x21499;
            x21499._0 = x21498;
            struct Anon2092052448 x21501;
            x21501.exists = true;
            x21501.key = x21500;
            x21501.aggs = x21499;
            x21485[x21483] = x21501;
          } else {
            for (;;) {
              struct Anon2092052448 x21504 = x21487;
              bool x21505 = x21504.exists;;
              bool x21540;
              if (x21505) {
                int x21506 = x21504.key;;
                bool x21507 = x21506 == x21436;
                bool x21527;
                if (x21507) {
                  struct Anon2052879266 x21508 = x21504.aggs;;
                  int x21512 = x21484;
                  struct Anon2092052448* x21514 = x21256;
                  double x21509 = x21508._0;;
                  double x21510 = x21509 + x21497;
                  struct Anon2052879266 x21511;
                  x21511._0 = x21510;
                  struct Anon2092052448 x21513;
                  x21513.exists = true;
                  x21513.key = x21506;
                  x21513.aggs = x21511;
                  x21514[x21512] = x21513;
                  x21527 = false;
                } else {
                  int x21517 = x21484;
                  int x21518 = x21517 + 1;
                  int x21519 = x21518 % 16777215;
                  x21484 = x21519;
                  struct Anon2092052448* x21521 = x21256;
                  struct Anon2092052448 x21522 = x21521[x21519];
                  x21487 = x21522;
                  x21527 = true;
                }
                x21540 = x21527;
              } else {
                int x21529 = x21484;
                struct Anon2092052448* x21532 = x21256;
                x21532[x21529] = x21531;
                int x21534 = x21257;
                x21258[x21534] = x21529;
                x21257 = x21257 + 1;
                x21540 = false;
              }
              if (!x21540) break;
            }
          }
        } else {
        }
      }
    }
    int x21553 = x21257;
    int x21555;
    for(x21555=0; x21555 < x21553; x21555++) {
      int x21556 = x21258[x21555];
      struct Anon2092052448* x21557 = x21256;
      struct Anon2092052448 x21558 = x21557[x21556];
      int x21559 = x21270;
      int x21560 = x21269;
      bool x21561 = x21559 == x21560;
      if (x21561) {
        int x21562 = x21560 * 4;
        x21269 = x21562;
        printf("buffer.resize %d\n",x21562);
        int* x21568 = x21274;
        int* x21569 = (int*)realloc(x21568,x21562 * sizeof(int));
        x21274 = x21569;
        printf("buffer.resize %d\n",x21562);
        double* x21572 = x21276;
        double* x21573 = (double*)realloc(x21572,x21562 * sizeof(double));
        x21276 = x21573;
      } else {
      }
      int x21580 = x21558.key;;
      int* x21581 = x21274;
      x21581[x21559] = x21580;
      struct Anon2052879266 x21583 = x21558.aggs;;
      double* x21585 = x21276;
      double x21584 = x21583._0;;
      x21585[x21559] = x21584;
      x21270 = x21270 + 1;
    }
    int x21590 = x21270;
    int x21592;
    for(x21592=0; x21592 < x21590; x21592++) {
      double* x21597 = x21276;
      double x21598 = x21597[x21592];
      int x21601 = x9312;
      struct Anon1007729034* x21602 = x21281;
      struct Anon1007729034 x21603 = x21602[x9312];
      struct Anon1007729034 x21604 = x21603;
      bool x21605 = x21603.exists;;
      bool x21610 = x21605;
      if (x21605) {
        struct Anon1007729034 x21606 = x21604;
        char* x21607 = x21606.key;;
        bool x21608 = strcmp(x21607,"Total") == 0;;
        x21610 = x21608;
      }
      bool x21611 = x21610;
      if (x21611) {
        struct Anon2052879266 x21612 = x21603.aggs;;
        char* x21616 = x21603.key;;
        double x21613 = x21612._0;;
        double x21614 = x21613 + x21598;
        struct Anon2052879266 x21615;
        x21615._0 = x21614;
        struct Anon1007729034 x21617;
        x21617.exists = true;
        x21617.key = x21616;
        x21617.aggs = x21615;
        x21602[x9312] = x21617;
      } else {
        struct Anon2052879266 x21599;
        x21599._0 = x21598;
        struct Anon1007729034 x21646;
        x21646.exists = true;
        x21646.key = "Total";
        x21646.aggs = x21599;
        for (;;) {
          struct Anon1007729034 x21620 = x21604;
          bool x21621 = x21620.exists;;
          bool x21655;
          if (x21621) {
            char* x21622 = x21620.key;;
            bool x21623 = strcmp(x21622,"Total") == 0;;
            bool x21643;
            if (x21623) {
              struct Anon2052879266 x21624 = x21620.aggs;;
              int x21628 = x21601;
              struct Anon1007729034* x21630 = x21281;
              double x21625 = x21624._0;;
              double x21626 = x21625 + x21598;
              struct Anon2052879266 x21627;
              x21627._0 = x21626;
              struct Anon1007729034 x21629;
              x21629.exists = true;
              x21629.key = x21622;
              x21629.aggs = x21627;
              x21630[x21628] = x21629;
              x21643 = false;
            } else {
              int x21633 = x21601;
              int x21634 = x21633 + 1;
              int x21635 = x21634 % 16777215;
              x21601 = x21635;
              struct Anon1007729034* x21637 = x21281;
              struct Anon1007729034 x21638 = x21637[x21635];
              x21604 = x21638;
              x21643 = true;
            }
            x21655 = x21643;
          } else {
            int x21645 = x21601;
            struct Anon1007729034* x21647 = x21281;
            x21647[x21645] = x21646;
            int x21649 = x21282;
            x21283[x21649] = x21645;
            x21282 = x21282 + 1;
            x21655 = false;
          }
          if (!x21655) break;
        }
      }
    }
    int x21664 = x21282;
    int x21666;
    for(x21666=0; x21666 < x21664; x21666++) {
      int x21667 = x21283[x21666];
      struct Anon1007729034* x21668 = x21281;
      struct Anon1007729034 x21669 = x21668[x21667];
      struct Anon2052879266 x21670 = x21669.aggs;;
      double x21671 = x21670._0;;
      double x21672 = x21671 * 1.0E-4;
      x21296 = x21672;
      int x21675 = x21270;
      int x21677;
      for(x21677=0; x21677 < x21675; x21677++) {
        int* x21680 = x21274;
        int x21681 = x21680[x21677];
        double* x21682 = x21276;
        double x21683 = x21682[x21677];
        double x21686 = x21296;
        bool x21688 = x21683 > x21686;
        if (x21688) {
          if (x972) {
          } else {
            printf("%d|%.2f\n",x21681,x21683);
            x21300 = x21300 + 1;
          }
        } else {
        }
      }
    }
    int x21703 = x21300;
    printf("(%d rows)\n",x21703);
    gettimeofday(&x21707, NULL);
    timeval_subtract(&x21708, &x21707, &x21706);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x21708.tv_sec * 1000) + (x21708.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
