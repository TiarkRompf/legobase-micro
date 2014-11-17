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

struct Anon2052879266 {
double _0;
};

struct Anon2092052448Anon811555534Anon920667905 {
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

struct Anon1268892766Anon1652045692 {
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

struct Anon1621811895 {
char* C_NAME;
int C_CUSTKEY;
int O_ORDERKEY;
long O_ORDERDATE;
double O_TOTALPRICE;
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

struct Anon1652045692 {
int key;
struct Anon2052879266 aggs;
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

struct Anon1280496914 {
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

struct Anon668992598 {
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
};

struct Anon2092052448Anon811555534 {
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

struct Anon1054882261 {
bool exists;
struct Anon668992598 key;
struct Anon2052879266 aggs;
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

struct Anon800615186 {
bool exists;
struct Anon1621811895 key;
struct Anon2052879266 aggs;
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

struct Anon1315812515 {
bool exists;
struct Anon1978526630 key;
struct Anon2052879266 aggs;
};

/************************ FUNCTIONS **************************/

/************************ MAIN BODY **************************/
int main(int x31781, char** x31782) {
  int x31783 = 0;
  int x31784 = 1048576;
  int x31785 = 0;
  int* x31788 = (int*)malloc(1048576 * sizeof(int));
  int* x31789 = x31788;
  double* x31794 = (double*)malloc(1048576 * sizeof(double));
  double* x31795 = x31794;
  double* x31796 = (double*)malloc(1048576 * sizeof(double));
  double* x31797 = x31796;
  double* x31798 = (double*)malloc(1048576 * sizeof(double));
  double* x31799 = x31798;
  char** x31812 = (char**)malloc(1048576 * sizeof(char*));
  char** x31813 = x31812;
  char** x31814 = (char**)malloc(1048576 * sizeof(char*));
  char** x31815 = x31814;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  int x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    int x31818 = x31783;
    bool x31819 = x31818 < x3;
    if (!x31819) break;
    for (;;) {
      int x31823 = x31783;
      char x31824 = x4[x31823];
      bool x31825 = x31824 != '|';
      bool x31830 = x31825;
      if (x31825) {
        int x31826 = x31783;
        char x31827 = x4[x31826];
        bool x31828 = x31827 != '\n';
        x31830 = x31828;
      }
      bool x31831 = x31830;
      if (!x31831) break;
      x31783 = x31783 + 1;
    }
    x31783 = x31783 + 1;
    int x31846 = 0;
    for (;;) {
      int x31847 = x31783;
      char x31848 = x4[x31847];
      bool x31849 = x31848 != '|';
      bool x31854 = x31849;
      if (x31849) {
        int x31850 = x31783;
        char x31851 = x4[x31850];
        bool x31852 = x31851 != '\n';
        x31854 = x31852;
      }
      bool x31855 = x31854;
      if (!x31855) break;
      int x31857 = x31846;
      int x31859 = x31783;
      int x31858 = x31857 * 10;
      char x31860 = x4[x31859];
      char x31861 = x31860 - '0';
      int x31862 = x31858 + x31861;
      x31846 = x31862;
      x31783 = x31783 + 1;
    }
    x31783 = x31783 + 1;
    int x31868 = x31846;
    for (;;) {
      int x31871 = x31783;
      char x31872 = x4[x31871];
      bool x31873 = x31872 != '|';
      bool x31878 = x31873;
      if (x31873) {
        int x31874 = x31783;
        char x31875 = x4[x31874];
        bool x31876 = x31875 != '\n';
        x31878 = x31876;
      }
      bool x31879 = x31878;
      if (!x31879) break;
      x31783 = x31783 + 1;
    }
    x31783 = x31783 + 1;
    for (;;) {
      int x31895 = x31783;
      char x31896 = x4[x31895];
      bool x31897 = x31896 != '|';
      bool x31902 = x31897;
      if (x31897) {
        int x31898 = x31783;
        char x31899 = x4[x31898];
        bool x31900 = x31899 != '\n';
        x31902 = x31900;
      }
      bool x31903 = x31902;
      if (!x31903) break;
      x31783 = x31783 + 1;
    }
    x31783 = x31783 + 1;
    int x31918 = 0;
    int x31919 = 1;
    for (;;) {
      int x31920 = x31783;
      char x31921 = x4[x31920];
      bool x31922 = x31921 != '.';
      bool x31927 = x31922;
      if (x31922) {
        int x31923 = x31783;
        char x31924 = x4[x31923];
        bool x31925 = x31924 != '|';
        x31927 = x31925;
      }
      bool x31928 = x31927;
      bool x31933 = x31928;
      if (x31928) {
        int x31929 = x31783;
        char x31930 = x4[x31929];
        bool x31931 = x31930 != '\n';
        x31933 = x31931;
      }
      bool x31934 = x31933;
      if (!x31934) break;
      int x31936 = x31918;
      int x31938 = x31783;
      int x31937 = x31936 * 10;
      char x31939 = x4[x31938];
      char x31940 = x31939 - '0';
      int x31941 = x31937 + x31940;
      x31918 = x31941;
      x31783 = x31783 + 1;
    }
    int x31946 = x31783;
    char x31947 = x4[x31946];
    bool x31948 = x31947 == '.';
    if (x31948) {
      x31783 = x31783 + 1;
      for (;;) {
        int x31950 = x31783;
        char x31951 = x4[x31950];
        bool x31952 = x31951 != '|';
        bool x31957 = x31952;
        if (x31952) {
          int x31953 = x31783;
          char x31954 = x4[x31953];
          bool x31955 = x31954 != '\n';
          x31957 = x31955;
        }
        bool x31958 = x31957;
        if (!x31958) break;
        int x31960 = x31918;
        int x31962 = x31783;
        int x31961 = x31960 * 10;
        char x31963 = x4[x31962];
        char x31964 = x31963 - '0';
        int x31965 = x31961 + x31964;
        x31918 = x31965;
        int x31967 = x31919;
        int x31968 = x31967 * 10;
        x31919 = x31968;
        x31783 = x31783 + 1;
      }
    } else {
    }
    x31783 = x31783 + 1;
    int x31977 = x31918;
    int x31979 = x31919;
    int x31983 = 0;
    int x31984 = 1;
    for (;;) {
      int x31985 = x31783;
      char x31986 = x4[x31985];
      bool x31987 = x31986 != '.';
      bool x31992 = x31987;
      if (x31987) {
        int x31988 = x31783;
        char x31989 = x4[x31988];
        bool x31990 = x31989 != '|';
        x31992 = x31990;
      }
      bool x31993 = x31992;
      bool x31998 = x31993;
      if (x31993) {
        int x31994 = x31783;
        char x31995 = x4[x31994];
        bool x31996 = x31995 != '\n';
        x31998 = x31996;
      }
      bool x31999 = x31998;
      if (!x31999) break;
      int x32001 = x31983;
      int x32003 = x31783;
      int x32002 = x32001 * 10;
      char x32004 = x4[x32003];
      char x32005 = x32004 - '0';
      int x32006 = x32002 + x32005;
      x31983 = x32006;
      x31783 = x31783 + 1;
    }
    int x32011 = x31783;
    char x32012 = x4[x32011];
    bool x32013 = x32012 == '.';
    if (x32013) {
      x31783 = x31783 + 1;
      for (;;) {
        int x32015 = x31783;
        char x32016 = x4[x32015];
        bool x32017 = x32016 != '|';
        bool x32022 = x32017;
        if (x32017) {
          int x32018 = x31783;
          char x32019 = x4[x32018];
          bool x32020 = x32019 != '\n';
          x32022 = x32020;
        }
        bool x32023 = x32022;
        if (!x32023) break;
        int x32025 = x31983;
        int x32027 = x31783;
        int x32026 = x32025 * 10;
        char x32028 = x4[x32027];
        char x32029 = x32028 - '0';
        int x32030 = x32026 + x32029;
        x31983 = x32030;
        int x32032 = x31984;
        int x32033 = x32032 * 10;
        x31984 = x32033;
        x31783 = x31783 + 1;
      }
    } else {
    }
    x31783 = x31783 + 1;
    int x32042 = x31983;
    int x32044 = x31984;
    int x32048 = 0;
    int x32049 = 1;
    for (;;) {
      int x32050 = x31783;
      char x32051 = x4[x32050];
      bool x32052 = x32051 != '.';
      bool x32057 = x32052;
      if (x32052) {
        int x32053 = x31783;
        char x32054 = x4[x32053];
        bool x32055 = x32054 != '|';
        x32057 = x32055;
      }
      bool x32058 = x32057;
      bool x32063 = x32058;
      if (x32058) {
        int x32059 = x31783;
        char x32060 = x4[x32059];
        bool x32061 = x32060 != '\n';
        x32063 = x32061;
      }
      bool x32064 = x32063;
      if (!x32064) break;
      int x32066 = x32048;
      int x32068 = x31783;
      int x32067 = x32066 * 10;
      char x32069 = x4[x32068];
      char x32070 = x32069 - '0';
      int x32071 = x32067 + x32070;
      x32048 = x32071;
      x31783 = x31783 + 1;
    }
    int x32076 = x31783;
    char x32077 = x4[x32076];
    bool x32078 = x32077 == '.';
    if (x32078) {
      x31783 = x31783 + 1;
      for (;;) {
        int x32080 = x31783;
        char x32081 = x4[x32080];
        bool x32082 = x32081 != '|';
        bool x32087 = x32082;
        if (x32082) {
          int x32083 = x31783;
          char x32084 = x4[x32083];
          bool x32085 = x32084 != '\n';
          x32087 = x32085;
        }
        bool x32088 = x32087;
        if (!x32088) break;
        int x32090 = x32048;
        int x32092 = x31783;
        int x32091 = x32090 * 10;
        char x32093 = x4[x32092];
        char x32094 = x32093 - '0';
        int x32095 = x32091 + x32094;
        x32048 = x32095;
        int x32097 = x32049;
        int x32098 = x32097 * 10;
        x32049 = x32098;
        x31783 = x31783 + 1;
      }
    } else {
    }
    x31783 = x31783 + 1;
    int x32107 = x32048;
    int x32109 = x32049;
    for (;;) {
      int x32115 = x31783;
      char x32116 = x4[x32115];
      bool x32117 = x32116 != '.';
      bool x32122 = x32117;
      if (x32117) {
        int x32118 = x31783;
        char x32119 = x4[x32118];
        bool x32120 = x32119 != '|';
        x32122 = x32120;
      }
      bool x32123 = x32122;
      bool x32128 = x32123;
      if (x32123) {
        int x32124 = x31783;
        char x32125 = x4[x32124];
        bool x32126 = x32125 != '\n';
        x32128 = x32126;
      }
      bool x32129 = x32128;
      if (!x32129) break;
      x31783 = x31783 + 1;
    }
    int x32141 = x31783;
    char x32142 = x4[x32141];
    bool x32143 = x32142 == '.';
    if (x32143) {
      x31783 = x31783 + 1;
      for (;;) {
        int x32145 = x31783;
        char x32146 = x4[x32145];
        bool x32147 = x32146 != '|';
        bool x32152 = x32147;
        if (x32147) {
          int x32148 = x31783;
          char x32149 = x4[x32148];
          bool x32150 = x32149 != '\n';
          x32152 = x32150;
        }
        bool x32153 = x32152;
        if (!x32153) break;
        x31783 = x31783 + 1;
      }
    } else {
    }
    x31783 = x31783 + 1;
    x31783 = x31783 + 2;
    x31783 = x31783 + 2;
    for (;;) {
      int x32185 = x31783;
      char x32186 = x4[x32185];
      bool x32187 = x32186 != '-';
      bool x32192 = x32187;
      if (x32187) {
        int x32188 = x31783;
        char x32189 = x4[x32188];
        bool x32190 = x32189 != '\n';
        x32192 = x32190;
      }
      bool x32193 = x32192;
      if (!x32193) break;
      x31783 = x31783 + 1;
    }
    x31783 = x31783 + 1;
    for (;;) {
      int x32209 = x31783;
      char x32210 = x4[x32209];
      bool x32211 = x32210 != '-';
      bool x32216 = x32211;
      if (x32211) {
        int x32212 = x31783;
        char x32213 = x4[x32212];
        bool x32214 = x32213 != '\n';
        x32216 = x32214;
      }
      bool x32217 = x32216;
      if (!x32217) break;
      x31783 = x31783 + 1;
    }
    x31783 = x31783 + 1;
    for (;;) {
      int x32233 = x31783;
      char x32234 = x4[x32233];
      bool x32235 = x32234 != '|';
      bool x32240 = x32235;
      if (x32235) {
        int x32236 = x31783;
        char x32237 = x4[x32236];
        bool x32238 = x32237 != '\n';
        x32240 = x32238;
      }
      bool x32241 = x32240;
      if (!x32241) break;
      x31783 = x31783 + 1;
    }
    x31783 = x31783 + 1;
    for (;;) {
      int x32261 = x31783;
      char x32262 = x4[x32261];
      bool x32263 = x32262 != '-';
      bool x32268 = x32263;
      if (x32263) {
        int x32264 = x31783;
        char x32265 = x4[x32264];
        bool x32266 = x32265 != '\n';
        x32268 = x32266;
      }
      bool x32269 = x32268;
      if (!x32269) break;
      x31783 = x31783 + 1;
    }
    x31783 = x31783 + 1;
    for (;;) {
      int x32285 = x31783;
      char x32286 = x4[x32285];
      bool x32287 = x32286 != '-';
      bool x32292 = x32287;
      if (x32287) {
        int x32288 = x31783;
        char x32289 = x4[x32288];
        bool x32290 = x32289 != '\n';
        x32292 = x32290;
      }
      bool x32293 = x32292;
      if (!x32293) break;
      x31783 = x31783 + 1;
    }
    x31783 = x31783 + 1;
    for (;;) {
      int x32309 = x31783;
      char x32310 = x4[x32309];
      bool x32311 = x32310 != '|';
      bool x32316 = x32311;
      if (x32311) {
        int x32312 = x31783;
        char x32313 = x4[x32312];
        bool x32314 = x32313 != '\n';
        x32316 = x32314;
      }
      bool x32317 = x32316;
      if (!x32317) break;
      x31783 = x31783 + 1;
    }
    x31783 = x31783 + 1;
    for (;;) {
      int x32337 = x31783;
      char x32338 = x4[x32337];
      bool x32339 = x32338 != '-';
      bool x32344 = x32339;
      if (x32339) {
        int x32340 = x31783;
        char x32341 = x4[x32340];
        bool x32342 = x32341 != '\n';
        x32344 = x32342;
      }
      bool x32345 = x32344;
      if (!x32345) break;
      x31783 = x31783 + 1;
    }
    x31783 = x31783 + 1;
    for (;;) {
      int x32361 = x31783;
      char x32362 = x4[x32361];
      bool x32363 = x32362 != '-';
      bool x32368 = x32363;
      if (x32363) {
        int x32364 = x31783;
        char x32365 = x4[x32364];
        bool x32366 = x32365 != '\n';
        x32368 = x32366;
      }
      bool x32369 = x32368;
      if (!x32369) break;
      x31783 = x31783 + 1;
    }
    x31783 = x31783 + 1;
    for (;;) {
      int x32385 = x31783;
      char x32386 = x4[x32385];
      bool x32387 = x32386 != '|';
      bool x32392 = x32387;
      if (x32387) {
        int x32388 = x31783;
        char x32389 = x4[x32388];
        bool x32390 = x32389 != '\n';
        x32392 = x32390;
      }
      bool x32393 = x32392;
      if (!x32393) break;
      x31783 = x31783 + 1;
    }
    x31783 = x31783 + 1;
    int x32411 = x31783;
    for (;;) {
      int x32412 = x31783;
      char x32413 = x4[x32412];
      bool x32414 = x32413 != '|';
      bool x32419 = x32414;
      if (x32414) {
        int x32415 = x31783;
        char x32416 = x4[x32415];
        bool x32417 = x32416 != '\n';
        x32419 = x32417;
      }
      bool x32420 = x32419;
      if (!x32420) break;
      x31783 = x31783 + 1;
    }
    x31783 = x31783 + 1;
    int x32429 = x31783;
    for (;;) {
      int x32430 = x31783;
      char x32431 = x4[x32430];
      bool x32432 = x32431 != '|';
      bool x32437 = x32432;
      if (x32432) {
        int x32433 = x31783;
        char x32434 = x4[x32433];
        bool x32435 = x32434 != '\n';
        x32437 = x32435;
      }
      bool x32438 = x32437;
      if (!x32438) break;
      x31783 = x31783 + 1;
    }
    x31783 = x31783 + 1;
    for (;;) {
      int x32448 = x31783;
      char x32449 = x4[x32448];
      bool x32450 = x32449 != '|';
      bool x32455 = x32450;
      if (x32450) {
        int x32451 = x31783;
        char x32452 = x4[x32451];
        bool x32453 = x32452 != '\n';
        x32455 = x32453;
      }
      bool x32456 = x32455;
      if (!x32456) break;
      x31783 = x31783 + 1;
    }
    x31783 = x31783 + 1;
    int x32466 = x31785;
    int x32467 = x31784;
    bool x32468 = x32466 == x32467;
    if (x32468) {
      int x32469 = x32467 * 4;
      x31784 = x32469;
      printf("buffer.resize %d\n",x32469);
      int* x32475 = x31789;
      int* x32476 = (int*)realloc(x32475,x32469 * sizeof(int));
      x31789 = x32476;
      double* x32484 = x31795;
      double* x32485 = (double*)realloc(x32484,x32469 * sizeof(double));
      x31795 = x32485;
      double* x32487 = x31797;
      double* x32488 = (double*)realloc(x32487,x32469 * sizeof(double));
      x31797 = x32488;
      double* x32490 = x31799;
      double* x32491 = (double*)realloc(x32490,x32469 * sizeof(double));
      x31799 = x32491;
      char** x32511 = x31813;
      char** x32512 = (char**)realloc(x32511,x32469 * sizeof(char*));
      x31813 = x32512;
      char** x32514 = x31815;
      char** x32515 = (char**)realloc(x32514,x32469 * sizeof(char*));
      x31815 = x32515;
    } else {
    }
    int* x32524 = x31789;
    x32524[x32466] = x31868;
    double* x32530 = x31795;
    double x31978 = (double)x31977;
    double x31980 = (double)x31979;
    double x31981 = x31978 / x31980;
    x32530[x32466] = x31981;
    double* x32532 = x31797;
    double x32043 = (double)x32042;
    double x32045 = (double)x32044;
    double x32046 = x32043 / x32045;
    x32532[x32466] = x32046;
    double* x32534 = x31799;
    double x32108 = (double)x32107;
    double x32110 = (double)x32109;
    double x32111 = x32108 / x32110;
    x32534[x32466] = x32111;
    char** x32548 = x31813;
    char* x32428 = x4+x32411;
    x32548[x32466] = x32428;
    char** x32550 = x31815;
    char* x32446 = x4+x32429;
    x32550[x32466] = x32446;
    x31785 = x31785 + 1;
  }
  int x32557 = 0;
  int x32558 = 1048576;
  int x32559 = 0;
  int* x32560 = (int*)malloc(1048576 * sizeof(int));
  int* x32561 = x32560;
  char** x32566 = (char**)malloc(1048576 * sizeof(char*));
  char** x32567 = x32566;
  int* x32570 = (int*)malloc(1048576 * sizeof(int));
  int* x32571 = x32570;
  char** x32572 = (char**)malloc(1048576 * sizeof(char*));
  char** x32573 = x32572;
  int x995 = open("../databases/sf2/part.tbl",0);
  int x996 = fsize(x995);
  char* x997 = mmap(0, x996, PROT_READ, MAP_FILE | MAP_SHARED, x995, 0);
  for (;;) {
    int x32579 = x32557;
    bool x32580 = x32579 < x996;
    if (!x32580) break;
    int x32583 = 0;
    for (;;) {
      int x32584 = x32557;
      char x32585 = x997[x32584];
      bool x32586 = x32585 != '|';
      bool x32591 = x32586;
      if (x32586) {
        int x32587 = x32557;
        char x32588 = x997[x32587];
        bool x32589 = x32588 != '\n';
        x32591 = x32589;
      }
      bool x32592 = x32591;
      if (!x32592) break;
      int x32594 = x32583;
      int x32596 = x32557;
      int x32595 = x32594 * 10;
      char x32597 = x997[x32596];
      char x32598 = x32597 - '0';
      int x32599 = x32595 + x32598;
      x32583 = x32599;
      x32557 = x32557 + 1;
    }
    x32557 = x32557 + 1;
    int x32605 = x32583;
    for (;;) {
      int x32607 = x32557;
      char x32608 = x997[x32607];
      bool x32609 = x32608 != '|';
      bool x32614 = x32609;
      if (x32609) {
        int x32610 = x32557;
        char x32611 = x997[x32610];
        bool x32612 = x32611 != '\n';
        x32614 = x32612;
      }
      bool x32615 = x32614;
      if (!x32615) break;
      x32557 = x32557 + 1;
    }
    x32557 = x32557 + 1;
    for (;;) {
      int x32625 = x32557;
      char x32626 = x997[x32625];
      bool x32627 = x32626 != '|';
      bool x32632 = x32627;
      if (x32627) {
        int x32628 = x32557;
        char x32629 = x997[x32628];
        bool x32630 = x32629 != '\n';
        x32632 = x32630;
      }
      bool x32633 = x32632;
      if (!x32633) break;
      x32557 = x32557 + 1;
    }
    x32557 = x32557 + 1;
    int x32642 = x32557;
    for (;;) {
      int x32643 = x32557;
      char x32644 = x997[x32643];
      bool x32645 = x32644 != '|';
      bool x32650 = x32645;
      if (x32645) {
        int x32646 = x32557;
        char x32647 = x997[x32646];
        bool x32648 = x32647 != '\n';
        x32650 = x32648;
      }
      bool x32651 = x32650;
      if (!x32651) break;
      x32557 = x32557 + 1;
    }
    x32557 = x32557 + 1;
    for (;;) {
      int x32661 = x32557;
      char x32662 = x997[x32661];
      bool x32663 = x32662 != '|';
      bool x32668 = x32663;
      if (x32663) {
        int x32664 = x32557;
        char x32665 = x997[x32664];
        bool x32666 = x32665 != '\n';
        x32668 = x32666;
      }
      bool x32669 = x32668;
      if (!x32669) break;
      x32557 = x32557 + 1;
    }
    x32557 = x32557 + 1;
    int x32679 = 0;
    for (;;) {
      int x32680 = x32557;
      char x32681 = x997[x32680];
      bool x32682 = x32681 != '|';
      bool x32687 = x32682;
      if (x32682) {
        int x32683 = x32557;
        char x32684 = x997[x32683];
        bool x32685 = x32684 != '\n';
        x32687 = x32685;
      }
      bool x32688 = x32687;
      if (!x32688) break;
      int x32690 = x32679;
      int x32692 = x32557;
      int x32691 = x32690 * 10;
      char x32693 = x997[x32692];
      char x32694 = x32693 - '0';
      int x32695 = x32691 + x32694;
      x32679 = x32695;
      x32557 = x32557 + 1;
    }
    x32557 = x32557 + 1;
    int x32701 = x32679;
    int x32702 = x32557;
    for (;;) {
      int x32703 = x32557;
      char x32704 = x997[x32703];
      bool x32705 = x32704 != '|';
      bool x32710 = x32705;
      if (x32705) {
        int x32706 = x32557;
        char x32707 = x997[x32706];
        bool x32708 = x32707 != '\n';
        x32710 = x32708;
      }
      bool x32711 = x32710;
      if (!x32711) break;
      x32557 = x32557 + 1;
    }
    x32557 = x32557 + 1;
    for (;;) {
      int x32723 = x32557;
      char x32724 = x997[x32723];
      bool x32725 = x32724 != '.';
      bool x32730 = x32725;
      if (x32725) {
        int x32726 = x32557;
        char x32727 = x997[x32726];
        bool x32728 = x32727 != '|';
        x32730 = x32728;
      }
      bool x32731 = x32730;
      bool x32736 = x32731;
      if (x32731) {
        int x32732 = x32557;
        char x32733 = x997[x32732];
        bool x32734 = x32733 != '\n';
        x32736 = x32734;
      }
      bool x32737 = x32736;
      if (!x32737) break;
      x32557 = x32557 + 1;
    }
    int x32749 = x32557;
    char x32750 = x997[x32749];
    bool x32751 = x32750 == '.';
    if (x32751) {
      x32557 = x32557 + 1;
      for (;;) {
        int x32753 = x32557;
        char x32754 = x997[x32753];
        bool x32755 = x32754 != '|';
        bool x32760 = x32755;
        if (x32755) {
          int x32756 = x32557;
          char x32757 = x997[x32756];
          bool x32758 = x32757 != '\n';
          x32760 = x32758;
        }
        bool x32761 = x32760;
        if (!x32761) break;
        x32557 = x32557 + 1;
      }
    } else {
    }
    x32557 = x32557 + 1;
    for (;;) {
      int x32786 = x32557;
      char x32787 = x997[x32786];
      bool x32788 = x32787 != '|';
      bool x32793 = x32788;
      if (x32788) {
        int x32789 = x32557;
        char x32790 = x997[x32789];
        bool x32791 = x32790 != '\n';
        x32793 = x32791;
      }
      bool x32794 = x32793;
      if (!x32794) break;
      x32557 = x32557 + 1;
    }
    x32557 = x32557 + 1;
    int x32804 = x32559;
    int x32805 = x32558;
    bool x32806 = x32804 == x32805;
    if (x32806) {
      int x32807 = x32805 * 4;
      x32558 = x32807;
      printf("buffer.resize %d\n",x32807);
      int* x32810 = x32561;
      int* x32811 = (int*)realloc(x32810,x32807 * sizeof(int));
      x32561 = x32811;
      char** x32819 = x32567;
      char** x32820 = (char**)realloc(x32819,x32807 * sizeof(char*));
      x32567 = x32820;
      int* x32825 = x32571;
      int* x32826 = (int*)realloc(x32825,x32807 * sizeof(int));
      x32571 = x32826;
      char** x32828 = x32573;
      char** x32829 = (char**)realloc(x32828,x32807 * sizeof(char*));
      x32573 = x32829;
    } else {
    }
    int* x32839 = x32561;
    x32839[x32804] = x32605;
    char** x32845 = x32567;
    char* x32659 = x997+x32642;
    x32845[x32804] = x32659;
    int* x32849 = x32571;
    x32849[x32804] = x32701;
    char** x32851 = x32573;
    char* x32719 = x997+x32702;
    x32851[x32804] = x32719;
    x32559 = x32559 + 1;
  }
  float x33069 = (float)36;
  double x33070 = (double)x33069;
  float x33072 = (float)26;
  double x33073 = (double)x33072;
  float x33077 = (float)25;
  double x33078 = (double)x33077;
  float x33080 = (float)15;
  double x33081 = (double)x33080;
  float x33087 = (float)14;
  double x33088 = (double)x33087;
  float x33090 = (float)4;
  double x33091 = (double)x33090;
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
  int x32860;
  for(x32860=0; x32860 < 5; x32860++) {
    bool x32861 = false;
    int x32862 = 0;
    bool x32864 = false;
    int x32865 = 0;
    int* x32868 = (int*)malloc(134217728 * sizeof(int));
    int* x32869 = x32868;
    char** x32874 = (char**)malloc(134217728 * sizeof(char*));
    char** x32875 = x32874;
    int* x32878 = (int*)malloc(134217728 * sizeof(int));
    int* x32879 = x32878;
    char** x32880 = (char**)malloc(134217728 * sizeof(char*));
    char** x32881 = x32880;
    int x32886 = 0;
    int* x32887 = (int*)malloc(67108864 * sizeof(int));
    int* x32888 = (int*)malloc(134217728 * sizeof(int));
    int x32889;
    for(x32889=0; x32889 < 67108864; x32889++) {
      x32887[x32889] = -1;
    }
    struct Anon603726677* x32896 = (struct Anon603726677*)malloc(16777216 * sizeof(struct Anon603726677));
    struct Anon603726677* x32897 = x32896;
    int x32898 = 0;
    int* x32899 = (int*)malloc(16777216 * sizeof(int));
    int x32900;
    for(x32900=0; x32900 < 16777216; x32900++) {
      struct Anon603726677* x32901 = x32897;
      struct Anon603726677 x32902 = x32901[x32900];
      char* x32903 = x32902.key;;
      double x32904 = x32902.aggs;;
      struct Anon603726677 x32905;
      x32905.exists = false;
      x32905.key = x32903;
      x32905.aggs = x32904;
      x32901[x32900] = x32905;
    }
    int x32910 = 0;
    struct timeval x33288, x33289, x33290;
    gettimeofday(&x33288, NULL);
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x32912 = x32861;
      bool x32913 = !x32912;
      bool x32918 = x32913;
      if (x32913) {
        int x32914 = x32862;
        int x32915 = x32559;
        bool x32916 = x32914 < x32915;
        x32918 = x32916;
      }
      bool x32919 = x32918;
      if (!x32919) break;
      int x32921 = x32862;
      int* x32922 = x32561;
      int x32923 = x32922[x32921];
      char** x32928 = x32567;
      char* x32929 = x32928[x32921];
      int* x32932 = x32571;
      int x32933 = x32932[x32921];
      char** x32934 = x32573;
      char* x32935 = x32934[x32921];
      x32862 = x32862 + 1;
      bool x32942 = x32933 >= 1;
      bool x32959 = x32942;
      if (x32942) {
        bool x32943 = x32933 <= 5;
        bool x32945 = x32943;
        if (x32943) {
          bool x32944 = strcmp(x32929,"Brand#31") == 0;;
          x32945 = x32944;
        }
        bool x32946 = x32945;
        bool x32957 = x32946;
        if (x32946) {
          bool x32947 = strcmp(x32935,"SM BOX") == 0;;
          bool x32949 = x32947;
          if (x32947 == false) {
            bool x32948 = strcmp(x32935,"SM CASE") == 0;;
            x32949 = x32948;
          }
          bool x32950 = x32949;
          bool x32952 = x32950;
          if (x32950 == false) {
            bool x32951 = strcmp(x32935,"SM PACK") == 0;;
            x32952 = x32951;
          }
          bool x32953 = x32952;
          bool x32955 = x32953;
          if (x32953 == false) {
            bool x32954 = strcmp(x32935,"SM PKG") == 0;;
            x32955 = x32954;
          }
          bool x32956 = x32955;
          x32957 = x32956;
        }
        bool x32958 = x32957;
        x32959 = x32958;
      }
      bool x32960 = x32959;
      bool x32977 = x32960;
      if (x32960 == false) {
        bool x32961 = x32933 <= 10;
        bool x32963 = x32961;
        if (x32961) {
          bool x32962 = strcmp(x32929,"Brand#43") == 0;;
          x32963 = x32962;
        }
        bool x32964 = x32963;
        bool x32975 = x32964;
        if (x32964) {
          bool x32965 = strcmp(x32935,"MED BAG") == 0;;
          bool x32967 = x32965;
          if (x32965 == false) {
            bool x32966 = strcmp(x32935,"MED BOX") == 0;;
            x32967 = x32966;
          }
          bool x32968 = x32967;
          bool x32970 = x32968;
          if (x32968 == false) {
            bool x32969 = strcmp(x32935,"MED PACK") == 0;;
            x32970 = x32969;
          }
          bool x32971 = x32970;
          bool x32973 = x32971;
          if (x32971 == false) {
            bool x32972 = strcmp(x32935,"MED PKG") == 0;;
            x32973 = x32972;
          }
          bool x32974 = x32973;
          x32975 = x32974;
        }
        bool x32976 = x32975;
        x32977 = x32976;
      }
      bool x32978 = x32977;
      bool x32994 = x32978;
      if (x32978 == false) {
        bool x32979 = x32933 <= 15;
        bool x32980 = x32979;
        if (x32979) {
          bool x32962 = strcmp(x32929,"Brand#43") == 0;;
          x32980 = x32962;
        }
        bool x32981 = x32980;
        bool x32992 = x32981;
        if (x32981) {
          bool x32982 = strcmp(x32935,"LG BOX") == 0;;
          bool x32984 = x32982;
          if (x32982 == false) {
            bool x32983 = strcmp(x32935,"LG CASE") == 0;;
            x32984 = x32983;
          }
          bool x32985 = x32984;
          bool x32987 = x32985;
          if (x32985 == false) {
            bool x32986 = strcmp(x32935,"LG PACK") == 0;;
            x32987 = x32986;
          }
          bool x32988 = x32987;
          bool x32990 = x32988;
          if (x32988 == false) {
            bool x32989 = strcmp(x32935,"LG PKG") == 0;;
            x32990 = x32989;
          }
          bool x32991 = x32990;
          x32992 = x32991;
        }
        bool x32993 = x32992;
        x32994 = x32993;
      }
      bool x32995 = x32994;
      if (x32995) {
        int x32996 = x32886;
        int* x32997 = x32869;
        x32997[x32996] = x32923;
        char** x33003 = x32875;
        x33003[x32996] = x32929;
        int* x33007 = x32879;
        x33007[x32996] = x32933;
        char** x33009 = x32881;
        x33009[x32996] = x32935;
        x32886 = x32886 + 1;
        int x33016 = x32923 & 67108863;
        int x33017 = x32887[x33016];
        x32887[x33016] = x32996;
        x32888[x32996] = x33017;
      } else {
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x33025 = x32864;
      bool x33026 = !x33025;
      bool x33031 = x33026;
      if (x33026) {
        int x33027 = x32865;
        int x33028 = x31785;
        bool x33029 = x33027 < x33028;
        x33031 = x33029;
      }
      bool x33032 = x33031;
      if (!x33032) break;
      int x33034 = x32865;
      int* x33037 = x31789;
      int x33038 = x33037[x33034];
      double* x33043 = x31795;
      double x33044 = x33043[x33034];
      double* x33045 = x31797;
      double x33046 = x33045[x33034];
      double* x33047 = x31799;
      double x33048 = x33047[x33034];
      char** x33061 = x31813;
      char* x33062 = x33061[x33034];
      char** x33063 = x31815;
      char* x33064 = x33063[x33034];
      x32865 = x32865 + 1;
      bool x33071 = x33044 <= x33070;
      bool x33074 = x33044 >= x33073;
      bool x33075 = x33071;
      if (x33071) {
        x33075 = x33074;
      }
      bool x33076 = x33075;
      bool x33079 = x33044 <= x33078;
      bool x33082 = x33044 >= x33081;
      bool x33085 = x33076;
      if (x33076 == false) {
        bool x33083 = x33079;
        if (x33079) {
          x33083 = x33082;
        }
        bool x33084 = x33083;
        x33085 = x33084;
      }
      bool x33086 = x33085;
      bool x33089 = x33044 <= x33088;
      bool x33092 = x33044 >= x33091;
      bool x33095 = x33086;
      if (x33086 == false) {
        bool x33093 = x33089;
        if (x33089) {
          x33093 = x33092;
        }
        bool x33094 = x33093;
        x33095 = x33094;
      }
      bool x33096 = x33095;
      bool x33098 = x33096;
      if (x33096) {
        bool x33097 = strcmp(x33062,"DELIVER IN PERSON") == 0;;
        x33098 = x33097;
      }
      bool x33099 = x33098;
      bool x33104 = x33099;
      if (x33099) {
        bool x33100 = strcmp(x33064,"AIR") == 0;;
        bool x33102 = x33100;
        if (x33100 == false) {
          bool x33101 = strcmp(x33064,"AIRREG") == 0;;
          x33102 = x33101;
        }
        bool x33103 = x33102;
        x33104 = x33103;
      }
      bool x33105 = x33104;
      if (x33105) {
        int x33106 = x33038 & 67108863;
        int x33107 = x32887[x33106];
        int x33108 = x33107;
        double x33213 = 1.0 - x33048;
        double x33214 = x33046 * x33213;
        struct Anon603726677 x33244;
        x33244.exists = true;
        x33244.key = "Total";
        x33244.aggs = x33214;
        for (;;) {
          int x33109 = x33108;
          bool x33110 = x33109 != -1;
          if (!x33110) break;
          int x33112 = x33108;
          int* x33113 = x32869;
          int x33114 = x33113[x33112];
          char** x33119 = x32875;
          char* x33120 = x33119[x33112];
          int* x33123 = x32879;
          int x33124 = x33123[x33112];
          char** x33125 = x32881;
          char* x33126 = x33125[x33112];
          int x33132 = x32888[x33112];
          x33108 = x33132;
          bool x33134 = x33114 == x33038;
          if (x33134) {
            bool x33138 = strcmp(x33120,"Brand#31") == 0;;
            bool x33149 = x33138;
            if (x33138) {
              bool x33139 = strcmp(x33126,"SM BOX") == 0;;
              bool x33141 = x33139;
              if (x33139 == false) {
                bool x33140 = strcmp(x33126,"SM CASE") == 0;;
                x33141 = x33140;
              }
              bool x33142 = x33141;
              bool x33144 = x33142;
              if (x33142 == false) {
                bool x33143 = strcmp(x33126,"SM PACK") == 0;;
                x33144 = x33143;
              }
              bool x33145 = x33144;
              bool x33147 = x33145;
              if (x33145 == false) {
                bool x33146 = strcmp(x33126,"SM PKG") == 0;;
                x33147 = x33146;
              }
              bool x33148 = x33147;
              x33149 = x33148;
            }
            bool x33150 = x33149;
            bool x33151 = x33150;
            if (x33150) {
              x33151 = x33092;
            }
            bool x33152 = x33151;
            bool x33153 = x33152;
            if (x33152) {
              x33153 = x33089;
            }
            bool x33154 = x33153;
            bool x33156 = x33154;
            if (x33154) {
              bool x33155 = x33124 <= 5;
              x33156 = x33155;
            }
            bool x33157 = x33156;
            bool x33178 = x33157;
            if (x33157 == false) {
              bool x33158 = strcmp(x33120,"Brand#43") == 0;;
              bool x33169 = x33158;
              if (x33158) {
                bool x33159 = strcmp(x33126,"MED BAG") == 0;;
                bool x33161 = x33159;
                if (x33159 == false) {
                  bool x33160 = strcmp(x33126,"MED BOX") == 0;;
                  x33161 = x33160;
                }
                bool x33162 = x33161;
                bool x33164 = x33162;
                if (x33162 == false) {
                  bool x33163 = strcmp(x33126,"MED PACK") == 0;;
                  x33164 = x33163;
                }
                bool x33165 = x33164;
                bool x33167 = x33165;
                if (x33165 == false) {
                  bool x33166 = strcmp(x33126,"MED PKG") == 0;;
                  x33167 = x33166;
                }
                bool x33168 = x33167;
                x33169 = x33168;
              }
              bool x33170 = x33169;
              bool x33171 = x33170;
              if (x33170) {
                x33171 = x33082;
              }
              bool x33172 = x33171;
              bool x33173 = x33172;
              if (x33172) {
                x33173 = x33079;
              }
              bool x33174 = x33173;
              bool x33176 = x33174;
              if (x33174) {
                bool x33175 = x33124 <= 10;
                x33176 = x33175;
              }
              bool x33177 = x33176;
              x33178 = x33177;
            }
            bool x33179 = x33178;
            bool x33199 = x33179;
            if (x33179 == false) {
              bool x33158 = strcmp(x33120,"Brand#43") == 0;;
              bool x33190 = x33158;
              if (x33158) {
                bool x33180 = strcmp(x33126,"LG BOX") == 0;;
                bool x33182 = x33180;
                if (x33180 == false) {
                  bool x33181 = strcmp(x33126,"LG CASE") == 0;;
                  x33182 = x33181;
                }
                bool x33183 = x33182;
                bool x33185 = x33183;
                if (x33183 == false) {
                  bool x33184 = strcmp(x33126,"LG PACK") == 0;;
                  x33185 = x33184;
                }
                bool x33186 = x33185;
                bool x33188 = x33186;
                if (x33186 == false) {
                  bool x33187 = strcmp(x33126,"LG PKG") == 0;;
                  x33188 = x33187;
                }
                bool x33189 = x33188;
                x33190 = x33189;
              }
              bool x33191 = x33190;
              bool x33192 = x33191;
              if (x33191) {
                x33192 = x33074;
              }
              bool x33193 = x33192;
              bool x33194 = x33193;
              if (x33193) {
                x33194 = x33071;
              }
              bool x33195 = x33194;
              bool x33197 = x33195;
              if (x33195) {
                bool x33196 = x33124 <= 15;
                x33197 = x33196;
              }
              bool x33198 = x33197;
              x33199 = x33198;
            }
            bool x33200 = x33199;
            if (x33200) {
              int x33201 = x9312;
              struct Anon603726677* x33202 = x32897;
              struct Anon603726677 x33203 = x33202[x9312];
              struct Anon603726677 x33204 = x33203;
              bool x33205 = x33203.exists;;
              bool x33210 = x33205;
              if (x33205) {
                struct Anon603726677 x33206 = x33204;
                char* x33207 = x33206.key;;
                bool x33208 = strcmp(x33207,"Total") == 0;;
                x33210 = x33208;
              }
              bool x33211 = x33210;
              if (x33211) {
                double x33212 = x33203.aggs;;
                char* x33216 = x33203.key;;
                double x33215 = x33212 + x33214;
                struct Anon603726677 x33217;
                x33217.exists = true;
                x33217.key = x33216;
                x33217.aggs = x33215;
                x33202[x9312] = x33217;
              } else {
                for (;;) {
                  struct Anon603726677 x33220 = x33204;
                  bool x33221 = x33220.exists;;
                  bool x33253;
                  if (x33221) {
                    char* x33222 = x33220.key;;
                    bool x33223 = strcmp(x33222,"Total") == 0;;
                    bool x33241;
                    if (x33223) {
                      double x33224 = x33220.aggs;;
                      int x33226 = x33201;
                      struct Anon603726677* x33228 = x32897;
                      double x33225 = x33224 + x33214;
                      struct Anon603726677 x33227;
                      x33227.exists = true;
                      x33227.key = x33222;
                      x33227.aggs = x33225;
                      x33228[x33226] = x33227;
                      x33241 = false;
                    } else {
                      int x33231 = x33201;
                      int x33232 = x33231 + 1;
                      int x33233 = x33232 % 16777215;
                      x33201 = x33233;
                      struct Anon603726677* x33235 = x32897;
                      struct Anon603726677 x33236 = x33235[x33233];
                      x33204 = x33236;
                      x33241 = true;
                    }
                    x33253 = x33241;
                  } else {
                    int x33243 = x33201;
                    struct Anon603726677* x33245 = x32897;
                    x33245[x33243] = x33244;
                    int x33247 = x32898;
                    x32899[x33247] = x33243;
                    x32898 = x32898 + 1;
                    x33253 = false;
                  }
                  if (!x33253) break;
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
    int x33270 = x32898;
    int x33272;
    for(x33272=0; x33272 < x33270; x33272++) {
      int x33273 = x32899[x33272];
      struct Anon603726677* x33274 = x32897;
      struct Anon603726677 x33275 = x33274[x33273];
      if (x972) {
      } else {
        double x33278 = x33275.aggs;;
        printf("%.4f\n",x33278);
        x32910 = x32910 + 1;
      }
    }
    int x33285 = x32910;
    printf("(%d rows)\n",x33285);
    gettimeofday(&x33289, NULL);
    timeval_subtract(&x33290, &x33289, &x33288);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x33290.tv_sec * 1000) + (x33290.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
