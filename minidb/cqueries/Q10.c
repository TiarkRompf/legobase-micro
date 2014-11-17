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
int main(int x18378, char** x18379) {
  int x18380 = 0;
  int x18381 = 1048576;
  int x18382 = 0;
  int* x18383 = (int*)malloc(1048576 * sizeof(int));
  int* x18384 = x18383;
  double* x18393 = (double*)malloc(1048576 * sizeof(double));
  double* x18394 = x18393;
  double* x18395 = (double*)malloc(1048576 * sizeof(double));
  double* x18396 = x18395;
  char* x18399 = (char*)malloc(1048576 * sizeof(char));
  char* x18400 = x18399;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  int x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    int x18415 = x18380;
    bool x18416 = x18415 < x3;
    if (!x18416) break;
    int x18419 = 0;
    for (;;) {
      int x18420 = x18380;
      char x18421 = x4[x18420];
      bool x18422 = x18421 != '|';
      bool x18427 = x18422;
      if (x18422) {
        int x18423 = x18380;
        char x18424 = x4[x18423];
        bool x18425 = x18424 != '\n';
        x18427 = x18425;
      }
      bool x18428 = x18427;
      if (!x18428) break;
      int x18430 = x18419;
      int x18432 = x18380;
      int x18431 = x18430 * 10;
      char x18433 = x4[x18432];
      char x18434 = x18433 - '0';
      int x18435 = x18431 + x18434;
      x18419 = x18435;
      x18380 = x18380 + 1;
    }
    x18380 = x18380 + 1;
    int x18441 = x18419;
    for (;;) {
      int x18444 = x18380;
      char x18445 = x4[x18444];
      bool x18446 = x18445 != '|';
      bool x18451 = x18446;
      if (x18446) {
        int x18447 = x18380;
        char x18448 = x4[x18447];
        bool x18449 = x18448 != '\n';
        x18451 = x18449;
      }
      bool x18452 = x18451;
      if (!x18452) break;
      x18380 = x18380 + 1;
    }
    x18380 = x18380 + 1;
    for (;;) {
      int x18468 = x18380;
      char x18469 = x4[x18468];
      bool x18470 = x18469 != '|';
      bool x18475 = x18470;
      if (x18470) {
        int x18471 = x18380;
        char x18472 = x4[x18471];
        bool x18473 = x18472 != '\n';
        x18475 = x18473;
      }
      bool x18476 = x18475;
      if (!x18476) break;
      x18380 = x18380 + 1;
    }
    x18380 = x18380 + 1;
    for (;;) {
      int x18492 = x18380;
      char x18493 = x4[x18492];
      bool x18494 = x18493 != '|';
      bool x18499 = x18494;
      if (x18494) {
        int x18495 = x18380;
        char x18496 = x4[x18495];
        bool x18497 = x18496 != '\n';
        x18499 = x18497;
      }
      bool x18500 = x18499;
      if (!x18500) break;
      x18380 = x18380 + 1;
    }
    x18380 = x18380 + 1;
    for (;;) {
      int x18517 = x18380;
      char x18518 = x4[x18517];
      bool x18519 = x18518 != '.';
      bool x18524 = x18519;
      if (x18519) {
        int x18520 = x18380;
        char x18521 = x4[x18520];
        bool x18522 = x18521 != '|';
        x18524 = x18522;
      }
      bool x18525 = x18524;
      bool x18530 = x18525;
      if (x18525) {
        int x18526 = x18380;
        char x18527 = x4[x18526];
        bool x18528 = x18527 != '\n';
        x18530 = x18528;
      }
      bool x18531 = x18530;
      if (!x18531) break;
      x18380 = x18380 + 1;
    }
    int x18543 = x18380;
    char x18544 = x4[x18543];
    bool x18545 = x18544 == '.';
    if (x18545) {
      x18380 = x18380 + 1;
      for (;;) {
        int x18547 = x18380;
        char x18548 = x4[x18547];
        bool x18549 = x18548 != '|';
        bool x18554 = x18549;
        if (x18549) {
          int x18550 = x18380;
          char x18551 = x4[x18550];
          bool x18552 = x18551 != '\n';
          x18554 = x18552;
        }
        bool x18555 = x18554;
        if (!x18555) break;
        x18380 = x18380 + 1;
      }
    } else {
    }
    x18380 = x18380 + 1;
    int x18580 = 0;
    int x18581 = 1;
    for (;;) {
      int x18582 = x18380;
      char x18583 = x4[x18582];
      bool x18584 = x18583 != '.';
      bool x18589 = x18584;
      if (x18584) {
        int x18585 = x18380;
        char x18586 = x4[x18585];
        bool x18587 = x18586 != '|';
        x18589 = x18587;
      }
      bool x18590 = x18589;
      bool x18595 = x18590;
      if (x18590) {
        int x18591 = x18380;
        char x18592 = x4[x18591];
        bool x18593 = x18592 != '\n';
        x18595 = x18593;
      }
      bool x18596 = x18595;
      if (!x18596) break;
      int x18598 = x18580;
      int x18600 = x18380;
      int x18599 = x18598 * 10;
      char x18601 = x4[x18600];
      char x18602 = x18601 - '0';
      int x18603 = x18599 + x18602;
      x18580 = x18603;
      x18380 = x18380 + 1;
    }
    int x18608 = x18380;
    char x18609 = x4[x18608];
    bool x18610 = x18609 == '.';
    if (x18610) {
      x18380 = x18380 + 1;
      for (;;) {
        int x18612 = x18380;
        char x18613 = x4[x18612];
        bool x18614 = x18613 != '|';
        bool x18619 = x18614;
        if (x18614) {
          int x18615 = x18380;
          char x18616 = x4[x18615];
          bool x18617 = x18616 != '\n';
          x18619 = x18617;
        }
        bool x18620 = x18619;
        if (!x18620) break;
        int x18622 = x18580;
        int x18624 = x18380;
        int x18623 = x18622 * 10;
        char x18625 = x4[x18624];
        char x18626 = x18625 - '0';
        int x18627 = x18623 + x18626;
        x18580 = x18627;
        int x18629 = x18581;
        int x18630 = x18629 * 10;
        x18581 = x18630;
        x18380 = x18380 + 1;
      }
    } else {
    }
    x18380 = x18380 + 1;
    int x18639 = x18580;
    int x18641 = x18581;
    int x18645 = 0;
    int x18646 = 1;
    for (;;) {
      int x18647 = x18380;
      char x18648 = x4[x18647];
      bool x18649 = x18648 != '.';
      bool x18654 = x18649;
      if (x18649) {
        int x18650 = x18380;
        char x18651 = x4[x18650];
        bool x18652 = x18651 != '|';
        x18654 = x18652;
      }
      bool x18655 = x18654;
      bool x18660 = x18655;
      if (x18655) {
        int x18656 = x18380;
        char x18657 = x4[x18656];
        bool x18658 = x18657 != '\n';
        x18660 = x18658;
      }
      bool x18661 = x18660;
      if (!x18661) break;
      int x18663 = x18645;
      int x18665 = x18380;
      int x18664 = x18663 * 10;
      char x18666 = x4[x18665];
      char x18667 = x18666 - '0';
      int x18668 = x18664 + x18667;
      x18645 = x18668;
      x18380 = x18380 + 1;
    }
    int x18673 = x18380;
    char x18674 = x4[x18673];
    bool x18675 = x18674 == '.';
    if (x18675) {
      x18380 = x18380 + 1;
      for (;;) {
        int x18677 = x18380;
        char x18678 = x4[x18677];
        bool x18679 = x18678 != '|';
        bool x18684 = x18679;
        if (x18679) {
          int x18680 = x18380;
          char x18681 = x4[x18680];
          bool x18682 = x18681 != '\n';
          x18684 = x18682;
        }
        bool x18685 = x18684;
        if (!x18685) break;
        int x18687 = x18645;
        int x18689 = x18380;
        int x18688 = x18687 * 10;
        char x18690 = x4[x18689];
        char x18691 = x18690 - '0';
        int x18692 = x18688 + x18691;
        x18645 = x18692;
        int x18694 = x18646;
        int x18695 = x18694 * 10;
        x18646 = x18695;
        x18380 = x18380 + 1;
      }
    } else {
    }
    x18380 = x18380 + 1;
    int x18704 = x18645;
    int x18706 = x18646;
    for (;;) {
      int x18712 = x18380;
      char x18713 = x4[x18712];
      bool x18714 = x18713 != '.';
      bool x18719 = x18714;
      if (x18714) {
        int x18715 = x18380;
        char x18716 = x4[x18715];
        bool x18717 = x18716 != '|';
        x18719 = x18717;
      }
      bool x18720 = x18719;
      bool x18725 = x18720;
      if (x18720) {
        int x18721 = x18380;
        char x18722 = x4[x18721];
        bool x18723 = x18722 != '\n';
        x18725 = x18723;
      }
      bool x18726 = x18725;
      if (!x18726) break;
      x18380 = x18380 + 1;
    }
    int x18738 = x18380;
    char x18739 = x4[x18738];
    bool x18740 = x18739 == '.';
    if (x18740) {
      x18380 = x18380 + 1;
      for (;;) {
        int x18742 = x18380;
        char x18743 = x4[x18742];
        bool x18744 = x18743 != '|';
        bool x18749 = x18744;
        if (x18744) {
          int x18745 = x18380;
          char x18746 = x4[x18745];
          bool x18747 = x18746 != '\n';
          x18749 = x18747;
        }
        bool x18750 = x18749;
        if (!x18750) break;
        x18380 = x18380 + 1;
      }
    } else {
    }
    x18380 = x18380 + 1;
    int x18774 = x18380;
    x18380 = x18380 + 2;
    x18380 = x18380 + 2;
    for (;;) {
      int x18782 = x18380;
      char x18783 = x4[x18782];
      bool x18784 = x18783 != '-';
      bool x18789 = x18784;
      if (x18784) {
        int x18785 = x18380;
        char x18786 = x4[x18785];
        bool x18787 = x18786 != '\n';
        x18789 = x18787;
      }
      bool x18790 = x18789;
      if (!x18790) break;
      x18380 = x18380 + 1;
    }
    x18380 = x18380 + 1;
    for (;;) {
      int x18806 = x18380;
      char x18807 = x4[x18806];
      bool x18808 = x18807 != '-';
      bool x18813 = x18808;
      if (x18808) {
        int x18809 = x18380;
        char x18810 = x4[x18809];
        bool x18811 = x18810 != '\n';
        x18813 = x18811;
      }
      bool x18814 = x18813;
      if (!x18814) break;
      x18380 = x18380 + 1;
    }
    x18380 = x18380 + 1;
    for (;;) {
      int x18830 = x18380;
      char x18831 = x4[x18830];
      bool x18832 = x18831 != '|';
      bool x18837 = x18832;
      if (x18832) {
        int x18833 = x18380;
        char x18834 = x4[x18833];
        bool x18835 = x18834 != '\n';
        x18837 = x18835;
      }
      bool x18838 = x18837;
      if (!x18838) break;
      x18380 = x18380 + 1;
    }
    x18380 = x18380 + 1;
    for (;;) {
      int x18858 = x18380;
      char x18859 = x4[x18858];
      bool x18860 = x18859 != '-';
      bool x18865 = x18860;
      if (x18860) {
        int x18861 = x18380;
        char x18862 = x4[x18861];
        bool x18863 = x18862 != '\n';
        x18865 = x18863;
      }
      bool x18866 = x18865;
      if (!x18866) break;
      x18380 = x18380 + 1;
    }
    x18380 = x18380 + 1;
    for (;;) {
      int x18882 = x18380;
      char x18883 = x4[x18882];
      bool x18884 = x18883 != '-';
      bool x18889 = x18884;
      if (x18884) {
        int x18885 = x18380;
        char x18886 = x4[x18885];
        bool x18887 = x18886 != '\n';
        x18889 = x18887;
      }
      bool x18890 = x18889;
      if (!x18890) break;
      x18380 = x18380 + 1;
    }
    x18380 = x18380 + 1;
    for (;;) {
      int x18906 = x18380;
      char x18907 = x4[x18906];
      bool x18908 = x18907 != '|';
      bool x18913 = x18908;
      if (x18908) {
        int x18909 = x18380;
        char x18910 = x4[x18909];
        bool x18911 = x18910 != '\n';
        x18913 = x18911;
      }
      bool x18914 = x18913;
      if (!x18914) break;
      x18380 = x18380 + 1;
    }
    x18380 = x18380 + 1;
    for (;;) {
      int x18934 = x18380;
      char x18935 = x4[x18934];
      bool x18936 = x18935 != '-';
      bool x18941 = x18936;
      if (x18936) {
        int x18937 = x18380;
        char x18938 = x4[x18937];
        bool x18939 = x18938 != '\n';
        x18941 = x18939;
      }
      bool x18942 = x18941;
      if (!x18942) break;
      x18380 = x18380 + 1;
    }
    x18380 = x18380 + 1;
    for (;;) {
      int x18958 = x18380;
      char x18959 = x4[x18958];
      bool x18960 = x18959 != '-';
      bool x18965 = x18960;
      if (x18960) {
        int x18961 = x18380;
        char x18962 = x4[x18961];
        bool x18963 = x18962 != '\n';
        x18965 = x18963;
      }
      bool x18966 = x18965;
      if (!x18966) break;
      x18380 = x18380 + 1;
    }
    x18380 = x18380 + 1;
    for (;;) {
      int x18982 = x18380;
      char x18983 = x4[x18982];
      bool x18984 = x18983 != '|';
      bool x18989 = x18984;
      if (x18984) {
        int x18985 = x18380;
        char x18986 = x4[x18985];
        bool x18987 = x18986 != '\n';
        x18989 = x18987;
      }
      bool x18990 = x18989;
      if (!x18990) break;
      x18380 = x18380 + 1;
    }
    x18380 = x18380 + 1;
    for (;;) {
      int x19009 = x18380;
      char x19010 = x4[x19009];
      bool x19011 = x19010 != '|';
      bool x19016 = x19011;
      if (x19011) {
        int x19012 = x18380;
        char x19013 = x4[x19012];
        bool x19014 = x19013 != '\n';
        x19016 = x19014;
      }
      bool x19017 = x19016;
      if (!x19017) break;
      x18380 = x18380 + 1;
    }
    x18380 = x18380 + 1;
    for (;;) {
      int x19027 = x18380;
      char x19028 = x4[x19027];
      bool x19029 = x19028 != '|';
      bool x19034 = x19029;
      if (x19029) {
        int x19030 = x18380;
        char x19031 = x4[x19030];
        bool x19032 = x19031 != '\n';
        x19034 = x19032;
      }
      bool x19035 = x19034;
      if (!x19035) break;
      x18380 = x18380 + 1;
    }
    x18380 = x18380 + 1;
    for (;;) {
      int x19045 = x18380;
      char x19046 = x4[x19045];
      bool x19047 = x19046 != '|';
      bool x19052 = x19047;
      if (x19047) {
        int x19048 = x18380;
        char x19049 = x4[x19048];
        bool x19050 = x19049 != '\n';
        x19052 = x19050;
      }
      bool x19053 = x19052;
      if (!x19053) break;
      x18380 = x18380 + 1;
    }
    x18380 = x18380 + 1;
    int x19063 = x18382;
    int x19064 = x18381;
    bool x19065 = x19063 == x19064;
    if (x19065) {
      int x19066 = x19064 * 4;
      x18381 = x19066;
      printf("buffer.resize %d\n",x19066);
      int* x19069 = x18384;
      int* x19070 = (int*)realloc(x19069,x19066 * sizeof(int));
      x18384 = x19070;
      double* x19084 = x18394;
      double* x19085 = (double*)realloc(x19084,x19066 * sizeof(double));
      x18394 = x19085;
      double* x19087 = x18396;
      double* x19088 = (double*)realloc(x19087,x19066 * sizeof(double));
      x18396 = x19088;
      char* x19093 = x18400;
      char* x19094 = (char*)realloc(x19093,x19066 * sizeof(char));
      x18400 = x19094;
    } else {
    }
    int* x19119 = x18384;
    x19119[x19063] = x18441;
    double* x19129 = x18394;
    double x18640 = (double)x18639;
    double x18642 = (double)x18641;
    double x18643 = x18640 / x18642;
    x19129[x19063] = x18643;
    double* x19131 = x18396;
    double x18705 = (double)x18704;
    double x18707 = (double)x18706;
    double x18708 = x18705 / x18707;
    x19131[x19063] = x18708;
    char* x19135 = x18400;
    char x18775 = x4[x18774];
    x19135[x19063] = x18775;
    x18382 = x18382 + 1;
  }
  int x19154 = 0;
  int x19155 = 1048576;
  int x19156 = 0;
  int* x19157 = (int*)malloc(1048576 * sizeof(int));
  int* x19158 = x19157;
  char** x19159 = (char**)malloc(1048576 * sizeof(char*));
  char** x19160 = x19159;
  int x1512 = open("../databases/sf2/nation.tbl",0);
  int x1513 = fsize(x1512);
  char* x1514 = mmap(0, x1513, PROT_READ, MAP_FILE | MAP_SHARED, x1512, 0);
  for (;;) {
    int x19165 = x19154;
    bool x19166 = x19165 < x1513;
    if (!x19166) break;
    int x19169 = 0;
    for (;;) {
      int x19170 = x19154;
      char x19171 = x1514[x19170];
      bool x19172 = x19171 != '|';
      bool x19177 = x19172;
      if (x19172) {
        int x19173 = x19154;
        char x19174 = x1514[x19173];
        bool x19175 = x19174 != '\n';
        x19177 = x19175;
      }
      bool x19178 = x19177;
      if (!x19178) break;
      int x19180 = x19169;
      int x19182 = x19154;
      int x19181 = x19180 * 10;
      char x19183 = x1514[x19182];
      char x19184 = x19183 - '0';
      int x19185 = x19181 + x19184;
      x19169 = x19185;
      x19154 = x19154 + 1;
    }
    x19154 = x19154 + 1;
    int x19191 = x19169;
    int x19192 = x19154;
    for (;;) {
      int x19193 = x19154;
      char x19194 = x1514[x19193];
      bool x19195 = x19194 != '|';
      bool x19200 = x19195;
      if (x19195) {
        int x19196 = x19154;
        char x19197 = x1514[x19196];
        bool x19198 = x19197 != '\n';
        x19200 = x19198;
      }
      bool x19201 = x19200;
      if (!x19201) break;
      x19154 = x19154 + 1;
    }
    x19154 = x19154 + 1;
    for (;;) {
      int x19212 = x19154;
      char x19213 = x1514[x19212];
      bool x19214 = x19213 != '|';
      bool x19219 = x19214;
      if (x19214) {
        int x19215 = x19154;
        char x19216 = x1514[x19215];
        bool x19217 = x19216 != '\n';
        x19219 = x19217;
      }
      bool x19220 = x19219;
      if (!x19220) break;
      x19154 = x19154 + 1;
    }
    x19154 = x19154 + 1;
    for (;;) {
      int x19235 = x19154;
      char x19236 = x1514[x19235];
      bool x19237 = x19236 != '|';
      bool x19242 = x19237;
      if (x19237) {
        int x19238 = x19154;
        char x19239 = x1514[x19238];
        bool x19240 = x19239 != '\n';
        x19242 = x19240;
      }
      bool x19243 = x19242;
      if (!x19243) break;
      x19154 = x19154 + 1;
    }
    x19154 = x19154 + 1;
    int x19253 = x19156;
    int x19254 = x19155;
    bool x19255 = x19253 == x19254;
    if (x19255) {
      int x19256 = x19254 * 4;
      x19155 = x19256;
      printf("buffer.resize %d\n",x19256);
      int* x19259 = x19158;
      int* x19260 = (int*)realloc(x19259,x19256 * sizeof(int));
      x19158 = x19260;
      char** x19262 = x19160;
      char** x19263 = (char**)realloc(x19262,x19256 * sizeof(char*));
      x19160 = x19263;
    } else {
    }
    int* x19273 = x19158;
    x19273[x19253] = x19191;
    char** x19275 = x19160;
    char* x19209 = x1514+x19192;
    x19275[x19253] = x19209;
    x19156 = x19156 + 1;
  }
  int x19284 = 0;
  int x19285 = 1048576;
  int x19286 = 0;
  int* x19287 = (int*)malloc(1048576 * sizeof(int));
  int* x19288 = x19287;
  char** x19289 = (char**)malloc(1048576 * sizeof(char*));
  char** x19290 = x19289;
  char** x19291 = (char**)malloc(1048576 * sizeof(char*));
  char** x19292 = x19291;
  int* x19293 = (int*)malloc(1048576 * sizeof(int));
  int* x19294 = x19293;
  char** x19295 = (char**)malloc(1048576 * sizeof(char*));
  char** x19296 = x19295;
  double* x19297 = (double*)malloc(1048576 * sizeof(double));
  double* x19298 = x19297;
  char** x19301 = (char**)malloc(1048576 * sizeof(char*));
  char** x19302 = x19301;
  int x3720 = open("../databases/sf2/customer.tbl",0);
  int x3721 = fsize(x3720);
  char* x3722 = mmap(0, x3721, PROT_READ, MAP_FILE | MAP_SHARED, x3720, 0);
  for (;;) {
    int x19303 = x19284;
    bool x19304 = x19303 < x3721;
    if (!x19304) break;
    int x19307 = 0;
    for (;;) {
      int x19308 = x19284;
      char x19309 = x3722[x19308];
      bool x19310 = x19309 != '|';
      bool x19315 = x19310;
      if (x19310) {
        int x19311 = x19284;
        char x19312 = x3722[x19311];
        bool x19313 = x19312 != '\n';
        x19315 = x19313;
      }
      bool x19316 = x19315;
      if (!x19316) break;
      int x19318 = x19307;
      int x19320 = x19284;
      int x19319 = x19318 * 10;
      char x19321 = x3722[x19320];
      char x19322 = x19321 - '0';
      int x19323 = x19319 + x19322;
      x19307 = x19323;
      x19284 = x19284 + 1;
    }
    x19284 = x19284 + 1;
    int x19329 = x19307;
    int x19330 = x19284;
    for (;;) {
      int x19331 = x19284;
      char x19332 = x3722[x19331];
      bool x19333 = x19332 != '|';
      bool x19338 = x19333;
      if (x19333) {
        int x19334 = x19284;
        char x19335 = x3722[x19334];
        bool x19336 = x19335 != '\n';
        x19338 = x19336;
      }
      bool x19339 = x19338;
      if (!x19339) break;
      x19284 = x19284 + 1;
    }
    x19284 = x19284 + 1;
    int x19348 = x19284;
    for (;;) {
      int x19349 = x19284;
      char x19350 = x3722[x19349];
      bool x19351 = x19350 != '|';
      bool x19356 = x19351;
      if (x19351) {
        int x19352 = x19284;
        char x19353 = x3722[x19352];
        bool x19354 = x19353 != '\n';
        x19356 = x19354;
      }
      bool x19357 = x19356;
      if (!x19357) break;
      x19284 = x19284 + 1;
    }
    x19284 = x19284 + 1;
    int x19367 = 0;
    for (;;) {
      int x19368 = x19284;
      char x19369 = x3722[x19368];
      bool x19370 = x19369 != '|';
      bool x19375 = x19370;
      if (x19370) {
        int x19371 = x19284;
        char x19372 = x3722[x19371];
        bool x19373 = x19372 != '\n';
        x19375 = x19373;
      }
      bool x19376 = x19375;
      if (!x19376) break;
      int x19378 = x19367;
      int x19380 = x19284;
      int x19379 = x19378 * 10;
      char x19381 = x3722[x19380];
      char x19382 = x19381 - '0';
      int x19383 = x19379 + x19382;
      x19367 = x19383;
      x19284 = x19284 + 1;
    }
    x19284 = x19284 + 1;
    int x19389 = x19367;
    int x19390 = x19284;
    for (;;) {
      int x19391 = x19284;
      char x19392 = x3722[x19391];
      bool x19393 = x19392 != '|';
      bool x19398 = x19393;
      if (x19393) {
        int x19394 = x19284;
        char x19395 = x3722[x19394];
        bool x19396 = x19395 != '\n';
        x19398 = x19396;
      }
      bool x19399 = x19398;
      if (!x19399) break;
      x19284 = x19284 + 1;
    }
    x19284 = x19284 + 1;
    int x19409 = 0;
    int x19410 = 1;
    for (;;) {
      int x19411 = x19284;
      char x19412 = x3722[x19411];
      bool x19413 = x19412 != '.';
      bool x19418 = x19413;
      if (x19413) {
        int x19414 = x19284;
        char x19415 = x3722[x19414];
        bool x19416 = x19415 != '|';
        x19418 = x19416;
      }
      bool x19419 = x19418;
      bool x19424 = x19419;
      if (x19419) {
        int x19420 = x19284;
        char x19421 = x3722[x19420];
        bool x19422 = x19421 != '\n';
        x19424 = x19422;
      }
      bool x19425 = x19424;
      if (!x19425) break;
      int x19427 = x19409;
      int x19429 = x19284;
      int x19428 = x19427 * 10;
      char x19430 = x3722[x19429];
      char x19431 = x19430 - '0';
      int x19432 = x19428 + x19431;
      x19409 = x19432;
      x19284 = x19284 + 1;
    }
    int x19437 = x19284;
    char x19438 = x3722[x19437];
    bool x19439 = x19438 == '.';
    if (x19439) {
      x19284 = x19284 + 1;
      for (;;) {
        int x19441 = x19284;
        char x19442 = x3722[x19441];
        bool x19443 = x19442 != '|';
        bool x19448 = x19443;
        if (x19443) {
          int x19444 = x19284;
          char x19445 = x3722[x19444];
          bool x19446 = x19445 != '\n';
          x19448 = x19446;
        }
        bool x19449 = x19448;
        if (!x19449) break;
        int x19451 = x19409;
        int x19453 = x19284;
        int x19452 = x19451 * 10;
        char x19454 = x3722[x19453];
        char x19455 = x19454 - '0';
        int x19456 = x19452 + x19455;
        x19409 = x19456;
        int x19458 = x19410;
        int x19459 = x19458 * 10;
        x19410 = x19459;
        x19284 = x19284 + 1;
      }
    } else {
    }
    x19284 = x19284 + 1;
    int x19468 = x19409;
    int x19470 = x19410;
    for (;;) {
      int x19474 = x19284;
      char x19475 = x3722[x19474];
      bool x19476 = x19475 != '|';
      bool x19481 = x19476;
      if (x19476) {
        int x19477 = x19284;
        char x19478 = x3722[x19477];
        bool x19479 = x19478 != '\n';
        x19481 = x19479;
      }
      bool x19482 = x19481;
      if (!x19482) break;
      x19284 = x19284 + 1;
    }
    x19284 = x19284 + 1;
    int x19491 = x19284;
    for (;;) {
      int x19492 = x19284;
      char x19493 = x3722[x19492];
      bool x19494 = x19493 != '|';
      bool x19499 = x19494;
      if (x19494) {
        int x19495 = x19284;
        char x19496 = x3722[x19495];
        bool x19497 = x19496 != '\n';
        x19499 = x19497;
      }
      bool x19500 = x19499;
      if (!x19500) break;
      x19284 = x19284 + 1;
    }
    x19284 = x19284 + 1;
    int x19510 = x19286;
    int x19511 = x19285;
    bool x19512 = x19510 == x19511;
    if (x19512) {
      int x19513 = x19511 * 4;
      x19285 = x19513;
      printf("buffer.resize %d\n",x19513);
      int* x19516 = x19288;
      int* x19517 = (int*)realloc(x19516,x19513 * sizeof(int));
      x19288 = x19517;
      char** x19519 = x19290;
      char** x19520 = (char**)realloc(x19519,x19513 * sizeof(char*));
      x19290 = x19520;
      char** x19522 = x19292;
      char** x19523 = (char**)realloc(x19522,x19513 * sizeof(char*));
      x19292 = x19523;
      int* x19525 = x19294;
      int* x19526 = (int*)realloc(x19525,x19513 * sizeof(int));
      x19294 = x19526;
      char** x19528 = x19296;
      char** x19529 = (char**)realloc(x19528,x19513 * sizeof(char*));
      x19296 = x19529;
      double* x19531 = x19298;
      double* x19532 = (double*)realloc(x19531,x19513 * sizeof(double));
      x19298 = x19532;
      char** x19537 = x19302;
      char** x19538 = (char**)realloc(x19537,x19513 * sizeof(char*));
      x19302 = x19538;
    } else {
    }
    int* x19542 = x19288;
    x19542[x19510] = x19329;
    char** x19544 = x19290;
    char* x19347 = x3722+x19330;
    x19544[x19510] = x19347;
    char** x19546 = x19292;
    char* x19365 = x3722+x19348;
    x19546[x19510] = x19365;
    int* x19548 = x19294;
    x19548[x19510] = x19389;
    char** x19550 = x19296;
    char* x19407 = x3722+x19390;
    x19550[x19510] = x19407;
    double* x19552 = x19298;
    double x19469 = (double)x19468;
    double x19471 = (double)x19470;
    double x19472 = x19469 / x19471;
    x19552[x19510] = x19472;
    char** x19556 = x19302;
    char* x19508 = x3722+x19491;
    x19556[x19510] = x19508;
    x19286 = x19286 + 1;
  }
  int x19561 = 0;
  int x19562 = 1048576;
  int x19563 = 0;
  int* x19564 = (int*)malloc(1048576 * sizeof(int));
  int* x19565 = x19564;
  int* x19566 = (int*)malloc(1048576 * sizeof(int));
  int* x19567 = x19566;
  long* x19572 = (long*)malloc(1048576 * sizeof(long));
  long* x19573 = x19572;
  int x3366 = open("../databases/sf2/orders.tbl",0);
  int x3367 = fsize(x3366);
  char* x3368 = mmap(0, x3367, PROT_READ, MAP_FILE | MAP_SHARED, x3366, 0);
  for (;;) {
    int x19582 = x19561;
    bool x19583 = x19582 < x3367;
    if (!x19583) break;
    int x19586 = 0;
    for (;;) {
      int x19587 = x19561;
      char x19588 = x3368[x19587];
      bool x19589 = x19588 != '|';
      bool x19594 = x19589;
      if (x19589) {
        int x19590 = x19561;
        char x19591 = x3368[x19590];
        bool x19592 = x19591 != '\n';
        x19594 = x19592;
      }
      bool x19595 = x19594;
      if (!x19595) break;
      int x19597 = x19586;
      int x19599 = x19561;
      int x19598 = x19597 * 10;
      char x19600 = x3368[x19599];
      char x19601 = x19600 - '0';
      int x19602 = x19598 + x19601;
      x19586 = x19602;
      x19561 = x19561 + 1;
    }
    x19561 = x19561 + 1;
    int x19608 = x19586;
    int x19610 = 0;
    for (;;) {
      int x19611 = x19561;
      char x19612 = x3368[x19611];
      bool x19613 = x19612 != '|';
      bool x19618 = x19613;
      if (x19613) {
        int x19614 = x19561;
        char x19615 = x3368[x19614];
        bool x19616 = x19615 != '\n';
        x19618 = x19616;
      }
      bool x19619 = x19618;
      if (!x19619) break;
      int x19621 = x19610;
      int x19623 = x19561;
      int x19622 = x19621 * 10;
      char x19624 = x3368[x19623];
      char x19625 = x19624 - '0';
      int x19626 = x19622 + x19625;
      x19610 = x19626;
      x19561 = x19561 + 1;
    }
    x19561 = x19561 + 1;
    int x19632 = x19610;
    x19561 = x19561 + 2;
    for (;;) {
      int x19639 = x19561;
      char x19640 = x3368[x19639];
      bool x19641 = x19640 != '.';
      bool x19646 = x19641;
      if (x19641) {
        int x19642 = x19561;
        char x19643 = x3368[x19642];
        bool x19644 = x19643 != '|';
        x19646 = x19644;
      }
      bool x19647 = x19646;
      bool x19652 = x19647;
      if (x19647) {
        int x19648 = x19561;
        char x19649 = x3368[x19648];
        bool x19650 = x19649 != '\n';
        x19652 = x19650;
      }
      bool x19653 = x19652;
      if (!x19653) break;
      x19561 = x19561 + 1;
    }
    int x19665 = x19561;
    char x19666 = x3368[x19665];
    bool x19667 = x19666 == '.';
    if (x19667) {
      x19561 = x19561 + 1;
      for (;;) {
        int x19669 = x19561;
        char x19670 = x3368[x19669];
        bool x19671 = x19670 != '|';
        bool x19676 = x19671;
        if (x19671) {
          int x19672 = x19561;
          char x19673 = x3368[x19672];
          bool x19674 = x19673 != '\n';
          x19676 = x19674;
        }
        bool x19677 = x19676;
        if (!x19677) break;
        x19561 = x19561 + 1;
      }
    } else {
    }
    x19561 = x19561 + 1;
    int x19702 = 0;
    for (;;) {
      int x19703 = x19561;
      char x19704 = x3368[x19703];
      bool x19705 = x19704 != '-';
      bool x19710 = x19705;
      if (x19705) {
        int x19706 = x19561;
        char x19707 = x3368[x19706];
        bool x19708 = x19707 != '\n';
        x19710 = x19708;
      }
      bool x19711 = x19710;
      if (!x19711) break;
      int x19713 = x19702;
      int x19715 = x19561;
      int x19714 = x19713 * 10;
      char x19716 = x3368[x19715];
      char x19717 = x19716 - '0';
      int x19718 = x19714 + x19717;
      x19702 = x19718;
      x19561 = x19561 + 1;
    }
    x19561 = x19561 + 1;
    int x19724 = x19702;
    int x19726 = 0;
    for (;;) {
      int x19727 = x19561;
      char x19728 = x3368[x19727];
      bool x19729 = x19728 != '-';
      bool x19734 = x19729;
      if (x19729) {
        int x19730 = x19561;
        char x19731 = x3368[x19730];
        bool x19732 = x19731 != '\n';
        x19734 = x19732;
      }
      bool x19735 = x19734;
      if (!x19735) break;
      int x19737 = x19726;
      int x19739 = x19561;
      int x19738 = x19737 * 10;
      char x19740 = x3368[x19739];
      char x19741 = x19740 - '0';
      int x19742 = x19738 + x19741;
      x19726 = x19742;
      x19561 = x19561 + 1;
    }
    x19561 = x19561 + 1;
    int x19748 = x19726;
    int x19750 = 0;
    for (;;) {
      int x19751 = x19561;
      char x19752 = x3368[x19751];
      bool x19753 = x19752 != '|';
      bool x19758 = x19753;
      if (x19753) {
        int x19754 = x19561;
        char x19755 = x3368[x19754];
        bool x19756 = x19755 != '\n';
        x19758 = x19756;
      }
      bool x19759 = x19758;
      if (!x19759) break;
      int x19761 = x19750;
      int x19763 = x19561;
      int x19762 = x19761 * 10;
      char x19764 = x3368[x19763];
      char x19765 = x19764 - '0';
      int x19766 = x19762 + x19765;
      x19750 = x19766;
      x19561 = x19561 + 1;
    }
    x19561 = x19561 + 1;
    int x19772 = x19750;
    for (;;) {
      int x19778 = x19561;
      char x19779 = x3368[x19778];
      bool x19780 = x19779 != '|';
      bool x19785 = x19780;
      if (x19780) {
        int x19781 = x19561;
        char x19782 = x3368[x19781];
        bool x19783 = x19782 != '\n';
        x19785 = x19783;
      }
      bool x19786 = x19785;
      if (!x19786) break;
      x19561 = x19561 + 1;
    }
    x19561 = x19561 + 1;
    for (;;) {
      int x19796 = x19561;
      char x19797 = x3368[x19796];
      bool x19798 = x19797 != '|';
      bool x19803 = x19798;
      if (x19798) {
        int x19799 = x19561;
        char x19800 = x3368[x19799];
        bool x19801 = x19800 != '\n';
        x19803 = x19801;
      }
      bool x19804 = x19803;
      if (!x19804) break;
      x19561 = x19561 + 1;
    }
    x19561 = x19561 + 1;
    for (;;) {
      int x19815 = x19561;
      char x19816 = x3368[x19815];
      bool x19817 = x19816 != '|';
      bool x19822 = x19817;
      if (x19817) {
        int x19818 = x19561;
        char x19819 = x3368[x19818];
        bool x19820 = x19819 != '\n';
        x19822 = x19820;
      }
      bool x19823 = x19822;
      if (!x19823) break;
      x19561 = x19561 + 1;
    }
    x19561 = x19561 + 1;
    for (;;) {
      int x19838 = x19561;
      char x19839 = x3368[x19838];
      bool x19840 = x19839 != '|';
      bool x19845 = x19840;
      if (x19840) {
        int x19841 = x19561;
        char x19842 = x3368[x19841];
        bool x19843 = x19842 != '\n';
        x19845 = x19843;
      }
      bool x19846 = x19845;
      if (!x19846) break;
      x19561 = x19561 + 1;
    }
    x19561 = x19561 + 1;
    int x19856 = x19563;
    int x19857 = x19562;
    bool x19858 = x19856 == x19857;
    if (x19858) {
      int x19859 = x19857 * 4;
      x19562 = x19859;
      printf("buffer.resize %d\n",x19859);
      int* x19862 = x19565;
      int* x19863 = (int*)realloc(x19862,x19859 * sizeof(int));
      x19565 = x19863;
      int* x19865 = x19567;
      int* x19866 = (int*)realloc(x19865,x19859 * sizeof(int));
      x19567 = x19866;
      long* x19874 = x19573;
      long* x19875 = (long*)realloc(x19874,x19859 * sizeof(long));
      x19573 = x19875;
    } else {
    }
    int* x19891 = x19565;
    x19891[x19856] = x19608;
    int* x19893 = x19567;
    x19893[x19856] = x19632;
    long* x19899 = x19573;
    long x19773 = x19724 * 10000L;
    long x19774 = x19748 * 100L;
    long x19775 = x19773 + x19774;
    long x19776 = x19775 + x19772;
    x19899[x19856] = x19776;
    x19563 = x19563 + 1;
  }
  int x19912;
  for(x19912=0; x19912 < 5; x19912++) {
    bool x19913 = false;
    int x19914 = 0;
    bool x19916 = false;
    int x19917 = 0;
    int* x19919 = (int*)malloc(134217728 * sizeof(int));
    int* x19920 = x19919;
    int* x19921 = (int*)malloc(134217728 * sizeof(int));
    int* x19922 = x19921;
    int x19937 = 0;
    int* x19938 = (int*)malloc(67108864 * sizeof(int));
    int* x19939 = (int*)malloc(134217728 * sizeof(int));
    int x19940;
    for(x19940=0; x19940 < 67108864; x19940++) {
      x19938[x19940] = -1;
    }
    bool x19945 = false;
    int x19946 = 0;
    int* x19948 = (int*)malloc(134217728 * sizeof(int));
    int* x19949 = x19948;
    char** x19950 = (char**)malloc(134217728 * sizeof(char*));
    char** x19951 = x19950;
    int x19956 = 0;
    int* x19957 = (int*)malloc(67108864 * sizeof(int));
    int* x19958 = (int*)malloc(134217728 * sizeof(int));
    int x19959;
    for(x19959=0; x19959 < 67108864; x19959++) {
      x19957[x19959] = -1;
    }
    bool x19964 = false;
    int x19965 = 0;
    char** x19970 = (char**)malloc(134217728 * sizeof(char*));
    char** x19971 = x19970;
    int* x19976 = (int*)malloc(134217728 * sizeof(int));
    int* x19977 = x19976;
    int* x19994 = (int*)malloc(134217728 * sizeof(int));
    int* x19995 = x19994;
    char** x19996 = (char**)malloc(134217728 * sizeof(char*));
    char** x19997 = x19996;
    char** x19998 = (char**)malloc(134217728 * sizeof(char*));
    char** x19999 = x19998;
    char** x20002 = (char**)malloc(134217728 * sizeof(char*));
    char** x20003 = x20002;
    double* x20004 = (double*)malloc(134217728 * sizeof(double));
    double* x20005 = x20004;
    char** x20008 = (char**)malloc(134217728 * sizeof(char*));
    char** x20009 = x20008;
    int x20010 = 0;
    int* x20011 = (int*)malloc(67108864 * sizeof(int));
    int* x20012 = (int*)malloc(134217728 * sizeof(int));
    int x20013;
    for(x20013=0; x20013 < 67108864; x20013++) {
      x20011[x20013] = -1;
    }
    struct Anon133694426* x20019 = (struct Anon133694426*)malloc(16777216 * sizeof(struct Anon133694426));
    struct Anon133694426* x20020 = x20019;
    int x20021 = 0;
    int* x20022 = (int*)malloc(16777216 * sizeof(int));
    int x20023;
    for(x20023=0; x20023 < 16777216; x20023++) {
      struct Anon133694426* x20024 = x20020;
      struct Anon133694426 x20025 = x20024[x20023];
      struct Anon1711779607 x20026 = x20025.key;;
      struct Anon2052879266 x20027 = x20025.aggs;;
      struct Anon133694426 x20028;
      x20028.exists = false;
      x20028.key = x20026;
      x20028.aggs = x20027;
      x20024[x20023] = x20028;
    }
    int x20032 = 0;
    int x20034 = 0;
    struct timeval x20599, x20600, x20601;
    gettimeofday(&x20599, NULL);
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x20036 = x19945;
      bool x20037 = !x20036;
      bool x20042 = x20037;
      if (x20037) {
        int x20038 = x19946;
        int x20039 = x19156;
        bool x20040 = x20038 < x20039;
        x20042 = x20040;
      }
      bool x20043 = x20042;
      if (!x20043) break;
      int x20045 = x19946;
      int* x20046 = x19158;
      int x20047 = x20046[x20045];
      char** x20048 = x19160;
      char* x20049 = x20048[x20045];
      x19946 = x19946 + 1;
      int x20056 = x19956;
      int* x20057 = x19949;
      x20057[x20056] = x20047;
      char** x20059 = x19951;
      x20059[x20056] = x20049;
      x19956 = x19956 + 1;
      int x20066 = x20047 & 67108863;
      int x20067 = x19957[x20066];
      x19957[x20066] = x20056;
      x19958[x20056] = x20067;
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x20073 = x19913;
      bool x20074 = !x20073;
      bool x20079 = x20074;
      if (x20074) {
        int x20075 = x19914;
        int x20076 = x19563;
        bool x20077 = x20075 < x20076;
        x20079 = x20077;
      }
      bool x20080 = x20079;
      if (!x20080) break;
      int x20082 = x19914;
      int* x20083 = x19565;
      int x20084 = x20083[x20082];
      int* x20085 = x19567;
      int x20086 = x20085[x20082];
      long* x20091 = x19573;
      long x20092 = x20091[x20082];
      x19914 = x19914 + 1;
      bool x20103 = x20092 >= 19941101L;
      bool x20105 = x20103;
      if (x20103) {
        bool x20104 = x20092 < 19950201L;
        x20105 = x20104;
      }
      bool x20106 = x20105;
      if (x20106) {
        int x20107 = x19937;
        int* x20108 = x19920;
        x20108[x20107] = x20084;
        int* x20110 = x19922;
        x20110[x20107] = x20086;
        x19937 = x19937 + 1;
        int x20127 = x20086 & 67108863;
        int x20128 = x19938[x20127];
        x19938[x20127] = x20107;
        x19939[x20107] = x20128;
      } else {
      }
    }
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x20136 = x19916;
      bool x20137 = !x20136;
      bool x20142 = x20137;
      if (x20137) {
        int x20138 = x19917;
        int x20139 = x19286;
        bool x20140 = x20138 < x20139;
        x20142 = x20140;
      }
      bool x20143 = x20142;
      if (!x20143) break;
      int x20145 = x19917;
      int* x20146 = x19288;
      int x20147 = x20146[x20145];
      char** x20148 = x19290;
      char* x20149 = x20148[x20145];
      char** x20150 = x19292;
      char* x20151 = x20150[x20145];
      int* x20152 = x19294;
      int x20153 = x20152[x20145];
      char** x20154 = x19296;
      char* x20155 = x20154[x20145];
      double* x20156 = x19298;
      double x20157 = x20156[x20145];
      char** x20160 = x19302;
      char* x20161 = x20160[x20145];
      x19917 = x19917 + 1;
      int x20164 = x20147 & 67108863;
      int x20165 = x19938[x20164];
      int x20166 = x20165;
      int x20196 = x20153 & 67108863;
      for (;;) {
        int x20167 = x20166;
        bool x20168 = x20167 != -1;
        if (!x20168) break;
        int x20170 = x20166;
        int* x20171 = x19920;
        int x20172 = x20171[x20170];
        int* x20173 = x19922;
        int x20174 = x20173[x20170];
        int x20190 = x19939[x20170];
        x20166 = x20190;
        bool x20192 = x20174 == x20147;
        if (x20192) {
          int x20197 = x19957[x20196];
          int x20198 = x20197;
          int x20262 = x20172 & 67108863;
          for (;;) {
            int x20199 = x20198;
            bool x20200 = x20199 != -1;
            if (!x20200) break;
            int x20202 = x20198;
            int* x20203 = x19949;
            int x20204 = x20203[x20202];
            char** x20205 = x19951;
            char* x20206 = x20205[x20202];
            int x20212 = x19958[x20202];
            x20198 = x20212;
            bool x20214 = x20204 == x20153;
            if (x20214) {
              int x20218 = x20010;
              char** x20221 = x19971;
              x20221[x20218] = x20206;
              int* x20227 = x19977;
              x20227[x20218] = x20172;
              int* x20245 = x19995;
              x20245[x20218] = x20147;
              char** x20247 = x19997;
              x20247[x20218] = x20149;
              char** x20249 = x19999;
              x20249[x20218] = x20151;
              char** x20253 = x20003;
              x20253[x20218] = x20155;
              double* x20255 = x20005;
              x20255[x20218] = x20157;
              char** x20259 = x20009;
              x20259[x20218] = x20161;
              x20010 = x20010 + 1;
              int x20263 = x20011[x20262];
              x20011[x20262] = x20218;
              x20012[x20218] = x20263;
            } else {
            }
          }
        } else {
        }
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x20277 = x19964;
      bool x20278 = !x20277;
      bool x20283 = x20278;
      if (x20278) {
        int x20279 = x19965;
        int x20280 = x18382;
        bool x20281 = x20279 < x20280;
        x20283 = x20281;
      }
      bool x20284 = x20283;
      if (!x20284) break;
      int x20286 = x19965;
      int* x20287 = x18384;
      int x20288 = x20287[x20286];
      double* x20297 = x18394;
      double x20298 = x20297[x20286];
      double* x20299 = x18396;
      double x20300 = x20299[x20286];
      char* x20303 = x18400;
      char x20304 = x20303[x20286];
      x19965 = x19965 + 1;
      bool x20321 = x20304 == 'R';
      if (x20321) {
        int x20322 = x20288 & 67108863;
        int x20323 = x20011[x20322];
        int x20324 = x20323;
        double x20479 = 1.0 - x20300;
        double x20480 = x20298 * x20479;
        struct Anon2052879266 x20538;
        x20538._0 = x20480;
        for (;;) {
          int x20325 = x20324;
          bool x20326 = x20325 != -1;
          if (!x20326) break;
          int x20328 = x20324;
          char** x20331 = x19971;
          char* x20332 = x20331[x20328];
          int* x20337 = x19977;
          int x20338 = x20337[x20328];
          int* x20355 = x19995;
          int x20356 = x20355[x20328];
          char** x20357 = x19997;
          char* x20358 = x20357[x20328];
          char** x20359 = x19999;
          char* x20360 = x20359[x20328];
          char** x20363 = x20003;
          char* x20364 = x20363[x20328];
          double* x20365 = x20005;
          double x20366 = x20365[x20328];
          char** x20369 = x20009;
          char* x20370 = x20369[x20328];
          int x20372 = x20012[x20328];
          x20324 = x20372;
          bool x20374 = x20338 == x20288;
          if (x20374) {
            char x20419 = x20332[0];
            int x20420 = x20419 * 41;
            char x20421 = x20332[1];
            int x20422 = x20420 + x20421;
            int x20423 = x20422 * 41;
            char x20424 = x20332[2];
            int x20425 = x20423 + x20424;
            int x20426 = x20425 * 41;
            char x20427 = x20332[3];
            int x20428 = x20426 + x20427;
            char x20409 = x20364[0];
            int x20410 = x20409 * 41;
            char x20411 = x20364[1];
            int x20412 = x20410 + x20411;
            int x20413 = x20412 * 41;
            char x20414 = x20364[2];
            int x20415 = x20413 + x20414;
            int x20416 = x20415 * 41;
            char x20417 = x20364[3];
            int x20418 = x20416 + x20417;
            char x20399 = x20358[0];
            int x20400 = x20399 * 41;
            char x20401 = x20358[1];
            int x20402 = x20400 + x20401;
            int x20403 = x20402 * 41;
            char x20404 = x20358[2];
            int x20405 = x20403 + x20404;
            int x20406 = x20405 * 41;
            char x20407 = x20358[3];
            int x20408 = x20406 + x20407;
            char x20389 = x20370[0];
            int x20390 = x20389 * 41;
            char x20391 = x20370[1];
            int x20392 = x20390 + x20391;
            int x20393 = x20392 * 41;
            char x20394 = x20370[2];
            int x20395 = x20393 + x20394;
            int x20396 = x20395 * 41;
            char x20397 = x20370[3];
            int x20398 = x20396 + x20397;
            char x20379 = x20360[0];
            int x20380 = x20379 * 41;
            char x20381 = x20360[1];
            int x20382 = x20380 + x20381;
            int x20383 = x20382 * 41;
            char x20384 = x20360[2];
            int x20385 = x20383 + x20384;
            int x20386 = x20385 * 41;
            char x20387 = x20360[3];
            int x20388 = x20386 + x20387;
            int x20429 = 31857 + x20388;
            int x20430 = x20429 * 41;
            int x20431 = x20430 + x20398;
            int x20432 = x20431 * 41;
            int x20433 = x20432 + x20356;
            int x20434 = x20433 * 41;
            int x20435 = x20434 + x20408;
            int x20436 = x20435 * 41;
            int x20437 = x20436 + x20418;
            int x20438 = x20437 * 41;
            int x20439 = x20438 + x20428;
            int x20440 = x20439 & 16777215;
            int x20441 = x20440;
            struct Anon133694426* x20442 = x20020;
            struct Anon133694426 x20443 = x20442[x20440];
            struct Anon133694426 x20444 = x20443;
            bool x20445 = x20443.exists;;
            bool x20475 = x20445;
            if (x20445) {
              struct Anon133694426 x20446 = x20444;
              struct Anon1711779607 x20447 = x20446.key;;
              int x20448 = x20447.C_CUSTKEY;;
              bool x20449 = x20448 == x20356;
              bool x20462 = x20449;
              if (x20449) {
                char* x20450 = x20447.C_NAME;;
                bool x20451 = strcmp(x20450,x20358) == 0;;
                x20462 = x20451;
              }
              bool x20463 = x20462;
              bool x20464 = x20463;
              if (x20463) {
                double x20452 = x20447.C_ACCTBAL;;
                bool x20453 = x20452 == x20366;
                x20464 = x20453;
              }
              bool x20465 = x20464;
              bool x20466 = x20465;
              if (x20465) {
                char* x20454 = x20447.C_PHONE;;
                bool x20455 = strcmp(x20454,x20364) == 0;;
                x20466 = x20455;
              }
              bool x20467 = x20466;
              bool x20468 = x20467;
              if (x20467) {
                char* x20456 = x20447.N_NAME;;
                bool x20457 = strcmp(x20456,x20332) == 0;;
                x20468 = x20457;
              }
              bool x20469 = x20468;
              bool x20470 = x20469;
              if (x20469) {
                char* x20458 = x20447.C_ADDRESS;;
                bool x20459 = strcmp(x20458,x20360) == 0;;
                x20470 = x20459;
              }
              bool x20471 = x20470;
              bool x20472 = x20471;
              if (x20471) {
                char* x20460 = x20447.C_COMMENT;;
                bool x20461 = strcmp(x20460,x20370) == 0;;
                x20472 = x20461;
              }
              bool x20473 = x20472;
              x20475 = x20473;
            }
            bool x20476 = x20475;
            if (x20476) {
              struct Anon2052879266 x20477 = x20443.aggs;;
              struct Anon1711779607 x20483 = x20443.key;;
              double x20478 = x20477._0;;
              double x20481 = x20478 + x20480;
              struct Anon2052879266 x20482;
              x20482._0 = x20481;
              struct Anon133694426 x20484;
              x20484.exists = true;
              x20484.key = x20483;
              x20484.aggs = x20482;
              x20442[x20440] = x20484;
            } else {
              struct Anon1711779607 x20378;
              x20378.C_CUSTKEY = x20356;
              x20378.C_NAME = x20358;
              x20378.C_ACCTBAL = x20366;
              x20378.C_PHONE = x20364;
              x20378.N_NAME = x20332;
              x20378.C_ADDRESS = x20360;
              x20378.C_COMMENT = x20370;
              struct Anon133694426 x20539;
              x20539.exists = true;
              x20539.key = x20378;
              x20539.aggs = x20538;
              for (;;) {
                struct Anon133694426 x20487 = x20444;
                bool x20488 = x20487.exists;;
                bool x20548;
                if (x20488) {
                  struct Anon1711779607 x20489 = x20487.key;;
                  int x20490 = x20489.C_CUSTKEY;;
                  bool x20491 = x20490 == x20356;
                  bool x20504 = x20491;
                  if (x20491) {
                    char* x20492 = x20489.C_NAME;;
                    bool x20493 = strcmp(x20492,x20358) == 0;;
                    x20504 = x20493;
                  }
                  bool x20505 = x20504;
                  bool x20506 = x20505;
                  if (x20505) {
                    double x20494 = x20489.C_ACCTBAL;;
                    bool x20495 = x20494 == x20366;
                    x20506 = x20495;
                  }
                  bool x20507 = x20506;
                  bool x20508 = x20507;
                  if (x20507) {
                    char* x20496 = x20489.C_PHONE;;
                    bool x20497 = strcmp(x20496,x20364) == 0;;
                    x20508 = x20497;
                  }
                  bool x20509 = x20508;
                  bool x20510 = x20509;
                  if (x20509) {
                    char* x20498 = x20489.N_NAME;;
                    bool x20499 = strcmp(x20498,x20332) == 0;;
                    x20510 = x20499;
                  }
                  bool x20511 = x20510;
                  bool x20512 = x20511;
                  if (x20511) {
                    char* x20500 = x20489.C_ADDRESS;;
                    bool x20501 = strcmp(x20500,x20360) == 0;;
                    x20512 = x20501;
                  }
                  bool x20513 = x20512;
                  bool x20514 = x20513;
                  if (x20513) {
                    char* x20502 = x20489.C_COMMENT;;
                    bool x20503 = strcmp(x20502,x20370) == 0;;
                    x20514 = x20503;
                  }
                  bool x20515 = x20514;
                  bool x20535;
                  if (x20515) {
                    struct Anon2052879266 x20516 = x20487.aggs;;
                    int x20520 = x20441;
                    struct Anon133694426* x20522 = x20020;
                    double x20517 = x20516._0;;
                    double x20518 = x20517 + x20480;
                    struct Anon2052879266 x20519;
                    x20519._0 = x20518;
                    struct Anon133694426 x20521;
                    x20521.exists = true;
                    x20521.key = x20489;
                    x20521.aggs = x20519;
                    x20522[x20520] = x20521;
                    x20535 = false;
                  } else {
                    int x20525 = x20441;
                    int x20526 = x20525 + 1;
                    int x20527 = x20526 % 16777215;
                    x20441 = x20527;
                    struct Anon133694426* x20529 = x20020;
                    struct Anon133694426 x20530 = x20529[x20527];
                    x20444 = x20530;
                    x20535 = true;
                  }
                  x20548 = x20535;
                } else {
                  int x20537 = x20441;
                  struct Anon133694426* x20540 = x20020;
                  x20540[x20537] = x20539;
                  int x20542 = x20021;
                  x20022[x20542] = x20537;
                  x20021 = x20021 + 1;
                  x20548 = false;
                }
                if (!x20548) break;
              }
            }
          } else {
          }
        }
      } else {
      }
    }
    int x20563 = x20021;
    int x20565;
    for(x20565=0; x20565 < x20563; x20565++) {
      int x20566 = x20022[x20565];
      struct Anon133694426* x20567 = x20020;
      struct Anon133694426 x20568 = x20567[x20566];
      int x20569 = x20032;
      bool x20570 = x20569 < 20;
      bool x20571 = x20570 == false;
      if (x20571) {
      } else {
        struct Anon1711779607 x20574 = x20568.key;;
        struct Anon2052879266 x20578 = x20568.aggs;;
        int x20575 = x20574.C_CUSTKEY;;
        char* x20576 = x20574.C_NAME;;
        int x20577 = strlen(x20576);
        double x20579 = x20578._0;;
        double x20580 = x20574.C_ACCTBAL;;
        char* x20581 = x20574.N_NAME;;
        int x20582 = strlen(x20581);
        char* x20583 = x20574.C_ADDRESS;;
        int x20584 = strlen(x20583);
        char* x20585 = x20574.C_PHONE;;
        int x20586 = strlen(x20585);
        char* x20587 = x20574.C_COMMENT;;
        int x20588 = strlen(x20587);
        printf("%d|%.*s|%.4f|%.2f|%.*s|%.*s|%.*s|%.*s\n",x20575,x20577,x20576,x20579,x20580,x20582,x20581,x20584,x20583,x20586,x20585,x20588,x20587);
        x20032 = x20032 + 1;
        x20034 = x20034 + 1;
      }
    }
    int x20596 = x20034;
    printf("(%d rows)\n",x20596);
    gettimeofday(&x20600, NULL);
    timeval_subtract(&x20601, &x20600, &x20599);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x20601.tv_sec * 1000) + (x20601.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
