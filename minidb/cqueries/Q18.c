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

struct Anon0 {
struct Anon1280496914 left;
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
int main(int x29835, char** x29836) {
  int x29837 = 0;
  int x29838 = 1048576;
  int x29839 = 0;
  int* x29840 = (int*)malloc(1048576 * sizeof(int));
  int* x29841 = x29840;
  double* x29848 = (double*)malloc(1048576 * sizeof(double));
  double* x29849 = x29848;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  int x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    int x29872 = x29837;
    bool x29873 = x29872 < x3;
    if (!x29873) break;
    int x29876 = 0;
    for (;;) {
      int x29877 = x29837;
      char x29878 = x4[x29877];
      bool x29879 = x29878 != '|';
      bool x29884 = x29879;
      if (x29879) {
        int x29880 = x29837;
        char x29881 = x4[x29880];
        bool x29882 = x29881 != '\n';
        x29884 = x29882;
      }
      bool x29885 = x29884;
      if (!x29885) break;
      int x29887 = x29876;
      int x29889 = x29837;
      int x29888 = x29887 * 10;
      char x29890 = x4[x29889];
      char x29891 = x29890 - '0';
      int x29892 = x29888 + x29891;
      x29876 = x29892;
      x29837 = x29837 + 1;
    }
    x29837 = x29837 + 1;
    int x29898 = x29876;
    for (;;) {
      int x29901 = x29837;
      char x29902 = x4[x29901];
      bool x29903 = x29902 != '|';
      bool x29908 = x29903;
      if (x29903) {
        int x29904 = x29837;
        char x29905 = x4[x29904];
        bool x29906 = x29905 != '\n';
        x29908 = x29906;
      }
      bool x29909 = x29908;
      if (!x29909) break;
      x29837 = x29837 + 1;
    }
    x29837 = x29837 + 1;
    for (;;) {
      int x29925 = x29837;
      char x29926 = x4[x29925];
      bool x29927 = x29926 != '|';
      bool x29932 = x29927;
      if (x29927) {
        int x29928 = x29837;
        char x29929 = x4[x29928];
        bool x29930 = x29929 != '\n';
        x29932 = x29930;
      }
      bool x29933 = x29932;
      if (!x29933) break;
      x29837 = x29837 + 1;
    }
    x29837 = x29837 + 1;
    for (;;) {
      int x29949 = x29837;
      char x29950 = x4[x29949];
      bool x29951 = x29950 != '|';
      bool x29956 = x29951;
      if (x29951) {
        int x29952 = x29837;
        char x29953 = x4[x29952];
        bool x29954 = x29953 != '\n';
        x29956 = x29954;
      }
      bool x29957 = x29956;
      if (!x29957) break;
      x29837 = x29837 + 1;
    }
    x29837 = x29837 + 1;
    int x29972 = 0;
    int x29973 = 1;
    for (;;) {
      int x29974 = x29837;
      char x29975 = x4[x29974];
      bool x29976 = x29975 != '.';
      bool x29981 = x29976;
      if (x29976) {
        int x29977 = x29837;
        char x29978 = x4[x29977];
        bool x29979 = x29978 != '|';
        x29981 = x29979;
      }
      bool x29982 = x29981;
      bool x29987 = x29982;
      if (x29982) {
        int x29983 = x29837;
        char x29984 = x4[x29983];
        bool x29985 = x29984 != '\n';
        x29987 = x29985;
      }
      bool x29988 = x29987;
      if (!x29988) break;
      int x29990 = x29972;
      int x29992 = x29837;
      int x29991 = x29990 * 10;
      char x29993 = x4[x29992];
      char x29994 = x29993 - '0';
      int x29995 = x29991 + x29994;
      x29972 = x29995;
      x29837 = x29837 + 1;
    }
    int x30000 = x29837;
    char x30001 = x4[x30000];
    bool x30002 = x30001 == '.';
    if (x30002) {
      x29837 = x29837 + 1;
      for (;;) {
        int x30004 = x29837;
        char x30005 = x4[x30004];
        bool x30006 = x30005 != '|';
        bool x30011 = x30006;
        if (x30006) {
          int x30007 = x29837;
          char x30008 = x4[x30007];
          bool x30009 = x30008 != '\n';
          x30011 = x30009;
        }
        bool x30012 = x30011;
        if (!x30012) break;
        int x30014 = x29972;
        int x30016 = x29837;
        int x30015 = x30014 * 10;
        char x30017 = x4[x30016];
        char x30018 = x30017 - '0';
        int x30019 = x30015 + x30018;
        x29972 = x30019;
        int x30021 = x29973;
        int x30022 = x30021 * 10;
        x29973 = x30022;
        x29837 = x29837 + 1;
      }
    } else {
    }
    x29837 = x29837 + 1;
    int x30031 = x29972;
    int x30033 = x29973;
    for (;;) {
      int x30039 = x29837;
      char x30040 = x4[x30039];
      bool x30041 = x30040 != '.';
      bool x30046 = x30041;
      if (x30041) {
        int x30042 = x29837;
        char x30043 = x4[x30042];
        bool x30044 = x30043 != '|';
        x30046 = x30044;
      }
      bool x30047 = x30046;
      bool x30052 = x30047;
      if (x30047) {
        int x30048 = x29837;
        char x30049 = x4[x30048];
        bool x30050 = x30049 != '\n';
        x30052 = x30050;
      }
      bool x30053 = x30052;
      if (!x30053) break;
      x29837 = x29837 + 1;
    }
    int x30065 = x29837;
    char x30066 = x4[x30065];
    bool x30067 = x30066 == '.';
    if (x30067) {
      x29837 = x29837 + 1;
      for (;;) {
        int x30069 = x29837;
        char x30070 = x4[x30069];
        bool x30071 = x30070 != '|';
        bool x30076 = x30071;
        if (x30071) {
          int x30072 = x29837;
          char x30073 = x4[x30072];
          bool x30074 = x30073 != '\n';
          x30076 = x30074;
        }
        bool x30077 = x30076;
        if (!x30077) break;
        x29837 = x29837 + 1;
      }
    } else {
    }
    x29837 = x29837 + 1;
    for (;;) {
      int x30104 = x29837;
      char x30105 = x4[x30104];
      bool x30106 = x30105 != '.';
      bool x30111 = x30106;
      if (x30106) {
        int x30107 = x29837;
        char x30108 = x4[x30107];
        bool x30109 = x30108 != '|';
        x30111 = x30109;
      }
      bool x30112 = x30111;
      bool x30117 = x30112;
      if (x30112) {
        int x30113 = x29837;
        char x30114 = x4[x30113];
        bool x30115 = x30114 != '\n';
        x30117 = x30115;
      }
      bool x30118 = x30117;
      if (!x30118) break;
      x29837 = x29837 + 1;
    }
    int x30130 = x29837;
    char x30131 = x4[x30130];
    bool x30132 = x30131 == '.';
    if (x30132) {
      x29837 = x29837 + 1;
      for (;;) {
        int x30134 = x29837;
        char x30135 = x4[x30134];
        bool x30136 = x30135 != '|';
        bool x30141 = x30136;
        if (x30136) {
          int x30137 = x29837;
          char x30138 = x4[x30137];
          bool x30139 = x30138 != '\n';
          x30141 = x30139;
        }
        bool x30142 = x30141;
        if (!x30142) break;
        x29837 = x29837 + 1;
      }
    } else {
    }
    x29837 = x29837 + 1;
    for (;;) {
      int x30169 = x29837;
      char x30170 = x4[x30169];
      bool x30171 = x30170 != '.';
      bool x30176 = x30171;
      if (x30171) {
        int x30172 = x29837;
        char x30173 = x4[x30172];
        bool x30174 = x30173 != '|';
        x30176 = x30174;
      }
      bool x30177 = x30176;
      bool x30182 = x30177;
      if (x30177) {
        int x30178 = x29837;
        char x30179 = x4[x30178];
        bool x30180 = x30179 != '\n';
        x30182 = x30180;
      }
      bool x30183 = x30182;
      if (!x30183) break;
      x29837 = x29837 + 1;
    }
    int x30195 = x29837;
    char x30196 = x4[x30195];
    bool x30197 = x30196 == '.';
    if (x30197) {
      x29837 = x29837 + 1;
      for (;;) {
        int x30199 = x29837;
        char x30200 = x4[x30199];
        bool x30201 = x30200 != '|';
        bool x30206 = x30201;
        if (x30201) {
          int x30202 = x29837;
          char x30203 = x4[x30202];
          bool x30204 = x30203 != '\n';
          x30206 = x30204;
        }
        bool x30207 = x30206;
        if (!x30207) break;
        x29837 = x29837 + 1;
      }
    } else {
    }
    x29837 = x29837 + 1;
    x29837 = x29837 + 2;
    x29837 = x29837 + 2;
    for (;;) {
      int x30239 = x29837;
      char x30240 = x4[x30239];
      bool x30241 = x30240 != '-';
      bool x30246 = x30241;
      if (x30241) {
        int x30242 = x29837;
        char x30243 = x4[x30242];
        bool x30244 = x30243 != '\n';
        x30246 = x30244;
      }
      bool x30247 = x30246;
      if (!x30247) break;
      x29837 = x29837 + 1;
    }
    x29837 = x29837 + 1;
    for (;;) {
      int x30263 = x29837;
      char x30264 = x4[x30263];
      bool x30265 = x30264 != '-';
      bool x30270 = x30265;
      if (x30265) {
        int x30266 = x29837;
        char x30267 = x4[x30266];
        bool x30268 = x30267 != '\n';
        x30270 = x30268;
      }
      bool x30271 = x30270;
      if (!x30271) break;
      x29837 = x29837 + 1;
    }
    x29837 = x29837 + 1;
    for (;;) {
      int x30287 = x29837;
      char x30288 = x4[x30287];
      bool x30289 = x30288 != '|';
      bool x30294 = x30289;
      if (x30289) {
        int x30290 = x29837;
        char x30291 = x4[x30290];
        bool x30292 = x30291 != '\n';
        x30294 = x30292;
      }
      bool x30295 = x30294;
      if (!x30295) break;
      x29837 = x29837 + 1;
    }
    x29837 = x29837 + 1;
    for (;;) {
      int x30315 = x29837;
      char x30316 = x4[x30315];
      bool x30317 = x30316 != '-';
      bool x30322 = x30317;
      if (x30317) {
        int x30318 = x29837;
        char x30319 = x4[x30318];
        bool x30320 = x30319 != '\n';
        x30322 = x30320;
      }
      bool x30323 = x30322;
      if (!x30323) break;
      x29837 = x29837 + 1;
    }
    x29837 = x29837 + 1;
    for (;;) {
      int x30339 = x29837;
      char x30340 = x4[x30339];
      bool x30341 = x30340 != '-';
      bool x30346 = x30341;
      if (x30341) {
        int x30342 = x29837;
        char x30343 = x4[x30342];
        bool x30344 = x30343 != '\n';
        x30346 = x30344;
      }
      bool x30347 = x30346;
      if (!x30347) break;
      x29837 = x29837 + 1;
    }
    x29837 = x29837 + 1;
    for (;;) {
      int x30363 = x29837;
      char x30364 = x4[x30363];
      bool x30365 = x30364 != '|';
      bool x30370 = x30365;
      if (x30365) {
        int x30366 = x29837;
        char x30367 = x4[x30366];
        bool x30368 = x30367 != '\n';
        x30370 = x30368;
      }
      bool x30371 = x30370;
      if (!x30371) break;
      x29837 = x29837 + 1;
    }
    x29837 = x29837 + 1;
    for (;;) {
      int x30391 = x29837;
      char x30392 = x4[x30391];
      bool x30393 = x30392 != '-';
      bool x30398 = x30393;
      if (x30393) {
        int x30394 = x29837;
        char x30395 = x4[x30394];
        bool x30396 = x30395 != '\n';
        x30398 = x30396;
      }
      bool x30399 = x30398;
      if (!x30399) break;
      x29837 = x29837 + 1;
    }
    x29837 = x29837 + 1;
    for (;;) {
      int x30415 = x29837;
      char x30416 = x4[x30415];
      bool x30417 = x30416 != '-';
      bool x30422 = x30417;
      if (x30417) {
        int x30418 = x29837;
        char x30419 = x4[x30418];
        bool x30420 = x30419 != '\n';
        x30422 = x30420;
      }
      bool x30423 = x30422;
      if (!x30423) break;
      x29837 = x29837 + 1;
    }
    x29837 = x29837 + 1;
    for (;;) {
      int x30439 = x29837;
      char x30440 = x4[x30439];
      bool x30441 = x30440 != '|';
      bool x30446 = x30441;
      if (x30441) {
        int x30442 = x29837;
        char x30443 = x4[x30442];
        bool x30444 = x30443 != '\n';
        x30446 = x30444;
      }
      bool x30447 = x30446;
      if (!x30447) break;
      x29837 = x29837 + 1;
    }
    x29837 = x29837 + 1;
    for (;;) {
      int x30466 = x29837;
      char x30467 = x4[x30466];
      bool x30468 = x30467 != '|';
      bool x30473 = x30468;
      if (x30468) {
        int x30469 = x29837;
        char x30470 = x4[x30469];
        bool x30471 = x30470 != '\n';
        x30473 = x30471;
      }
      bool x30474 = x30473;
      if (!x30474) break;
      x29837 = x29837 + 1;
    }
    x29837 = x29837 + 1;
    for (;;) {
      int x30484 = x29837;
      char x30485 = x4[x30484];
      bool x30486 = x30485 != '|';
      bool x30491 = x30486;
      if (x30486) {
        int x30487 = x29837;
        char x30488 = x4[x30487];
        bool x30489 = x30488 != '\n';
        x30491 = x30489;
      }
      bool x30492 = x30491;
      if (!x30492) break;
      x29837 = x29837 + 1;
    }
    x29837 = x29837 + 1;
    for (;;) {
      int x30502 = x29837;
      char x30503 = x4[x30502];
      bool x30504 = x30503 != '|';
      bool x30509 = x30504;
      if (x30504) {
        int x30505 = x29837;
        char x30506 = x4[x30505];
        bool x30507 = x30506 != '\n';
        x30509 = x30507;
      }
      bool x30510 = x30509;
      if (!x30510) break;
      x29837 = x29837 + 1;
    }
    x29837 = x29837 + 1;
    int x30520 = x29839;
    int x30521 = x29838;
    bool x30522 = x30520 == x30521;
    if (x30522) {
      int x30523 = x30521 * 4;
      x29838 = x30523;
      printf("buffer.resize %d\n",x30523);
      int* x30526 = x29841;
      int* x30527 = (int*)realloc(x30526,x30523 * sizeof(int));
      x29841 = x30527;
      double* x30538 = x29849;
      double* x30539 = (double*)realloc(x30538,x30523 * sizeof(double));
      x29849 = x30539;
    } else {
    }
    int* x30576 = x29841;
    x30576[x30520] = x29898;
    double* x30584 = x29849;
    double x30032 = (double)x30031;
    double x30034 = (double)x30033;
    double x30035 = x30032 / x30034;
    x30584[x30520] = x30035;
    x29839 = x29839 + 1;
  }
  int x30611 = 0;
  int x30612 = 1048576;
  int x30613 = 0;
  int* x30614 = (int*)malloc(1048576 * sizeof(int));
  int* x30615 = x30614;
  int* x30616 = (int*)malloc(1048576 * sizeof(int));
  int* x30617 = x30616;
  double* x30620 = (double*)malloc(1048576 * sizeof(double));
  double* x30621 = x30620;
  long* x30622 = (long*)malloc(1048576 * sizeof(long));
  long* x30623 = x30622;
  int x3366 = open("../databases/sf2/orders.tbl",0);
  int x3367 = fsize(x3366);
  char* x3368 = mmap(0, x3367, PROT_READ, MAP_FILE | MAP_SHARED, x3366, 0);
  for (;;) {
    int x30632 = x30611;
    bool x30633 = x30632 < x3367;
    if (!x30633) break;
    int x30636 = 0;
    for (;;) {
      int x30637 = x30611;
      char x30638 = x3368[x30637];
      bool x30639 = x30638 != '|';
      bool x30644 = x30639;
      if (x30639) {
        int x30640 = x30611;
        char x30641 = x3368[x30640];
        bool x30642 = x30641 != '\n';
        x30644 = x30642;
      }
      bool x30645 = x30644;
      if (!x30645) break;
      int x30647 = x30636;
      int x30649 = x30611;
      int x30648 = x30647 * 10;
      char x30650 = x3368[x30649];
      char x30651 = x30650 - '0';
      int x30652 = x30648 + x30651;
      x30636 = x30652;
      x30611 = x30611 + 1;
    }
    x30611 = x30611 + 1;
    int x30658 = x30636;
    int x30660 = 0;
    for (;;) {
      int x30661 = x30611;
      char x30662 = x3368[x30661];
      bool x30663 = x30662 != '|';
      bool x30668 = x30663;
      if (x30663) {
        int x30664 = x30611;
        char x30665 = x3368[x30664];
        bool x30666 = x30665 != '\n';
        x30668 = x30666;
      }
      bool x30669 = x30668;
      if (!x30669) break;
      int x30671 = x30660;
      int x30673 = x30611;
      int x30672 = x30671 * 10;
      char x30674 = x3368[x30673];
      char x30675 = x30674 - '0';
      int x30676 = x30672 + x30675;
      x30660 = x30676;
      x30611 = x30611 + 1;
    }
    x30611 = x30611 + 1;
    int x30682 = x30660;
    x30611 = x30611 + 2;
    int x30687 = 0;
    int x30688 = 1;
    for (;;) {
      int x30689 = x30611;
      char x30690 = x3368[x30689];
      bool x30691 = x30690 != '.';
      bool x30696 = x30691;
      if (x30691) {
        int x30692 = x30611;
        char x30693 = x3368[x30692];
        bool x30694 = x30693 != '|';
        x30696 = x30694;
      }
      bool x30697 = x30696;
      bool x30702 = x30697;
      if (x30697) {
        int x30698 = x30611;
        char x30699 = x3368[x30698];
        bool x30700 = x30699 != '\n';
        x30702 = x30700;
      }
      bool x30703 = x30702;
      if (!x30703) break;
      int x30705 = x30687;
      int x30707 = x30611;
      int x30706 = x30705 * 10;
      char x30708 = x3368[x30707];
      char x30709 = x30708 - '0';
      int x30710 = x30706 + x30709;
      x30687 = x30710;
      x30611 = x30611 + 1;
    }
    int x30715 = x30611;
    char x30716 = x3368[x30715];
    bool x30717 = x30716 == '.';
    if (x30717) {
      x30611 = x30611 + 1;
      for (;;) {
        int x30719 = x30611;
        char x30720 = x3368[x30719];
        bool x30721 = x30720 != '|';
        bool x30726 = x30721;
        if (x30721) {
          int x30722 = x30611;
          char x30723 = x3368[x30722];
          bool x30724 = x30723 != '\n';
          x30726 = x30724;
        }
        bool x30727 = x30726;
        if (!x30727) break;
        int x30729 = x30687;
        int x30731 = x30611;
        int x30730 = x30729 * 10;
        char x30732 = x3368[x30731];
        char x30733 = x30732 - '0';
        int x30734 = x30730 + x30733;
        x30687 = x30734;
        int x30736 = x30688;
        int x30737 = x30736 * 10;
        x30688 = x30737;
        x30611 = x30611 + 1;
      }
    } else {
    }
    x30611 = x30611 + 1;
    int x30746 = x30687;
    int x30748 = x30688;
    int x30752 = 0;
    for (;;) {
      int x30753 = x30611;
      char x30754 = x3368[x30753];
      bool x30755 = x30754 != '-';
      bool x30760 = x30755;
      if (x30755) {
        int x30756 = x30611;
        char x30757 = x3368[x30756];
        bool x30758 = x30757 != '\n';
        x30760 = x30758;
      }
      bool x30761 = x30760;
      if (!x30761) break;
      int x30763 = x30752;
      int x30765 = x30611;
      int x30764 = x30763 * 10;
      char x30766 = x3368[x30765];
      char x30767 = x30766 - '0';
      int x30768 = x30764 + x30767;
      x30752 = x30768;
      x30611 = x30611 + 1;
    }
    x30611 = x30611 + 1;
    int x30774 = x30752;
    int x30776 = 0;
    for (;;) {
      int x30777 = x30611;
      char x30778 = x3368[x30777];
      bool x30779 = x30778 != '-';
      bool x30784 = x30779;
      if (x30779) {
        int x30780 = x30611;
        char x30781 = x3368[x30780];
        bool x30782 = x30781 != '\n';
        x30784 = x30782;
      }
      bool x30785 = x30784;
      if (!x30785) break;
      int x30787 = x30776;
      int x30789 = x30611;
      int x30788 = x30787 * 10;
      char x30790 = x3368[x30789];
      char x30791 = x30790 - '0';
      int x30792 = x30788 + x30791;
      x30776 = x30792;
      x30611 = x30611 + 1;
    }
    x30611 = x30611 + 1;
    int x30798 = x30776;
    int x30800 = 0;
    for (;;) {
      int x30801 = x30611;
      char x30802 = x3368[x30801];
      bool x30803 = x30802 != '|';
      bool x30808 = x30803;
      if (x30803) {
        int x30804 = x30611;
        char x30805 = x3368[x30804];
        bool x30806 = x30805 != '\n';
        x30808 = x30806;
      }
      bool x30809 = x30808;
      if (!x30809) break;
      int x30811 = x30800;
      int x30813 = x30611;
      int x30812 = x30811 * 10;
      char x30814 = x3368[x30813];
      char x30815 = x30814 - '0';
      int x30816 = x30812 + x30815;
      x30800 = x30816;
      x30611 = x30611 + 1;
    }
    x30611 = x30611 + 1;
    int x30822 = x30800;
    for (;;) {
      int x30828 = x30611;
      char x30829 = x3368[x30828];
      bool x30830 = x30829 != '|';
      bool x30835 = x30830;
      if (x30830) {
        int x30831 = x30611;
        char x30832 = x3368[x30831];
        bool x30833 = x30832 != '\n';
        x30835 = x30833;
      }
      bool x30836 = x30835;
      if (!x30836) break;
      x30611 = x30611 + 1;
    }
    x30611 = x30611 + 1;
    for (;;) {
      int x30846 = x30611;
      char x30847 = x3368[x30846];
      bool x30848 = x30847 != '|';
      bool x30853 = x30848;
      if (x30848) {
        int x30849 = x30611;
        char x30850 = x3368[x30849];
        bool x30851 = x30850 != '\n';
        x30853 = x30851;
      }
      bool x30854 = x30853;
      if (!x30854) break;
      x30611 = x30611 + 1;
    }
    x30611 = x30611 + 1;
    for (;;) {
      int x30865 = x30611;
      char x30866 = x3368[x30865];
      bool x30867 = x30866 != '|';
      bool x30872 = x30867;
      if (x30867) {
        int x30868 = x30611;
        char x30869 = x3368[x30868];
        bool x30870 = x30869 != '\n';
        x30872 = x30870;
      }
      bool x30873 = x30872;
      if (!x30873) break;
      x30611 = x30611 + 1;
    }
    x30611 = x30611 + 1;
    for (;;) {
      int x30888 = x30611;
      char x30889 = x3368[x30888];
      bool x30890 = x30889 != '|';
      bool x30895 = x30890;
      if (x30890) {
        int x30891 = x30611;
        char x30892 = x3368[x30891];
        bool x30893 = x30892 != '\n';
        x30895 = x30893;
      }
      bool x30896 = x30895;
      if (!x30896) break;
      x30611 = x30611 + 1;
    }
    x30611 = x30611 + 1;
    int x30906 = x30613;
    int x30907 = x30612;
    bool x30908 = x30906 == x30907;
    if (x30908) {
      int x30909 = x30907 * 4;
      x30612 = x30909;
      printf("buffer.resize %d\n",x30909);
      int* x30912 = x30615;
      int* x30913 = (int*)realloc(x30912,x30909 * sizeof(int));
      x30615 = x30913;
      int* x30915 = x30617;
      int* x30916 = (int*)realloc(x30915,x30909 * sizeof(int));
      x30617 = x30916;
      double* x30921 = x30621;
      double* x30922 = (double*)realloc(x30921,x30909 * sizeof(double));
      x30621 = x30922;
      long* x30924 = x30623;
      long* x30925 = (long*)realloc(x30924,x30909 * sizeof(long));
      x30623 = x30925;
    } else {
    }
    int* x30941 = x30615;
    x30941[x30906] = x30658;
    int* x30943 = x30617;
    x30943[x30906] = x30682;
    double* x30947 = x30621;
    double x30747 = (double)x30746;
    double x30749 = (double)x30748;
    double x30750 = x30747 / x30749;
    x30947[x30906] = x30750;
    long* x30949 = x30623;
    long x30823 = x30774 * 10000L;
    long x30824 = x30798 * 100L;
    long x30825 = x30823 + x30824;
    long x30826 = x30825 + x30822;
    x30949[x30906] = x30826;
    x30613 = x30613 + 1;
  }
  int x30962 = 0;
  int x30963 = 1048576;
  int x30964 = 0;
  int* x30965 = (int*)malloc(1048576 * sizeof(int));
  int* x30966 = x30965;
  char** x30967 = (char**)malloc(1048576 * sizeof(char*));
  char** x30968 = x30967;
  int x3720 = open("../databases/sf2/customer.tbl",0);
  int x3721 = fsize(x3720);
  char* x3722 = mmap(0, x3721, PROT_READ, MAP_FILE | MAP_SHARED, x3720, 0);
  for (;;) {
    int x30981 = x30962;
    bool x30982 = x30981 < x3721;
    if (!x30982) break;
    int x30985 = 0;
    for (;;) {
      int x30986 = x30962;
      char x30987 = x3722[x30986];
      bool x30988 = x30987 != '|';
      bool x30993 = x30988;
      if (x30988) {
        int x30989 = x30962;
        char x30990 = x3722[x30989];
        bool x30991 = x30990 != '\n';
        x30993 = x30991;
      }
      bool x30994 = x30993;
      if (!x30994) break;
      int x30996 = x30985;
      int x30998 = x30962;
      int x30997 = x30996 * 10;
      char x30999 = x3722[x30998];
      char x31000 = x30999 - '0';
      int x31001 = x30997 + x31000;
      x30985 = x31001;
      x30962 = x30962 + 1;
    }
    x30962 = x30962 + 1;
    int x31007 = x30985;
    int x31008 = x30962;
    for (;;) {
      int x31009 = x30962;
      char x31010 = x3722[x31009];
      bool x31011 = x31010 != '|';
      bool x31016 = x31011;
      if (x31011) {
        int x31012 = x30962;
        char x31013 = x3722[x31012];
        bool x31014 = x31013 != '\n';
        x31016 = x31014;
      }
      bool x31017 = x31016;
      if (!x31017) break;
      x30962 = x30962 + 1;
    }
    x30962 = x30962 + 1;
    for (;;) {
      int x31027 = x30962;
      char x31028 = x3722[x31027];
      bool x31029 = x31028 != '|';
      bool x31034 = x31029;
      if (x31029) {
        int x31030 = x30962;
        char x31031 = x3722[x31030];
        bool x31032 = x31031 != '\n';
        x31034 = x31032;
      }
      bool x31035 = x31034;
      if (!x31035) break;
      x30962 = x30962 + 1;
    }
    x30962 = x30962 + 1;
    for (;;) {
      int x31046 = x30962;
      char x31047 = x3722[x31046];
      bool x31048 = x31047 != '|';
      bool x31053 = x31048;
      if (x31048) {
        int x31049 = x30962;
        char x31050 = x3722[x31049];
        bool x31051 = x31050 != '\n';
        x31053 = x31051;
      }
      bool x31054 = x31053;
      if (!x31054) break;
      x30962 = x30962 + 1;
    }
    x30962 = x30962 + 1;
    for (;;) {
      int x31069 = x30962;
      char x31070 = x3722[x31069];
      bool x31071 = x31070 != '|';
      bool x31076 = x31071;
      if (x31071) {
        int x31072 = x30962;
        char x31073 = x3722[x31072];
        bool x31074 = x31073 != '\n';
        x31076 = x31074;
      }
      bool x31077 = x31076;
      if (!x31077) break;
      x30962 = x30962 + 1;
    }
    x30962 = x30962 + 1;
    for (;;) {
      int x31089 = x30962;
      char x31090 = x3722[x31089];
      bool x31091 = x31090 != '.';
      bool x31096 = x31091;
      if (x31091) {
        int x31092 = x30962;
        char x31093 = x3722[x31092];
        bool x31094 = x31093 != '|';
        x31096 = x31094;
      }
      bool x31097 = x31096;
      bool x31102 = x31097;
      if (x31097) {
        int x31098 = x30962;
        char x31099 = x3722[x31098];
        bool x31100 = x31099 != '\n';
        x31102 = x31100;
      }
      bool x31103 = x31102;
      if (!x31103) break;
      x30962 = x30962 + 1;
    }
    int x31115 = x30962;
    char x31116 = x3722[x31115];
    bool x31117 = x31116 == '.';
    if (x31117) {
      x30962 = x30962 + 1;
      for (;;) {
        int x31119 = x30962;
        char x31120 = x3722[x31119];
        bool x31121 = x31120 != '|';
        bool x31126 = x31121;
        if (x31121) {
          int x31122 = x30962;
          char x31123 = x3722[x31122];
          bool x31124 = x31123 != '\n';
          x31126 = x31124;
        }
        bool x31127 = x31126;
        if (!x31127) break;
        x30962 = x30962 + 1;
      }
    } else {
    }
    x30962 = x30962 + 1;
    for (;;) {
      int x31152 = x30962;
      char x31153 = x3722[x31152];
      bool x31154 = x31153 != '|';
      bool x31159 = x31154;
      if (x31154) {
        int x31155 = x30962;
        char x31156 = x3722[x31155];
        bool x31157 = x31156 != '\n';
        x31159 = x31157;
      }
      bool x31160 = x31159;
      if (!x31160) break;
      x30962 = x30962 + 1;
    }
    x30962 = x30962 + 1;
    for (;;) {
      int x31170 = x30962;
      char x31171 = x3722[x31170];
      bool x31172 = x31171 != '|';
      bool x31177 = x31172;
      if (x31172) {
        int x31173 = x30962;
        char x31174 = x3722[x31173];
        bool x31175 = x31174 != '\n';
        x31177 = x31175;
      }
      bool x31178 = x31177;
      if (!x31178) break;
      x30962 = x30962 + 1;
    }
    x30962 = x30962 + 1;
    int x31188 = x30964;
    int x31189 = x30963;
    bool x31190 = x31188 == x31189;
    if (x31190) {
      int x31191 = x31189 * 4;
      x30963 = x31191;
      printf("buffer.resize %d\n",x31191);
      int* x31194 = x30966;
      int* x31195 = (int*)realloc(x31194,x31191 * sizeof(int));
      x30966 = x31195;
      char** x31197 = x30968;
      char** x31198 = (char**)realloc(x31197,x31191 * sizeof(char*));
      x30968 = x31198;
    } else {
    }
    int* x31220 = x30966;
    x31220[x31188] = x31007;
    char** x31222 = x30968;
    char* x31025 = x3722+x31008;
    x31222[x31188] = x31025;
    x30964 = x30964 + 1;
  }
  float x31444 = (float)300;
  double x31445 = (double)x31444;
  int x31457 = 777 & 67108863;
  int x31239;
  for(x31239=0; x31239 < 5; x31239++) {
    bool x31240 = false;
    int x31241 = 0;
    bool x31242 = false;
    int x31243 = 0;
    bool x31244 = false;
    int x31245 = 0;
    struct Anon2092052448* x31247 = (struct Anon2092052448*)malloc(16777216 * sizeof(struct Anon2092052448));
    struct Anon2092052448* x31248 = x31247;
    int x31249 = 0;
    int* x31250 = (int*)malloc(16777216 * sizeof(int));
    int x31251;
    for(x31251=0; x31251 < 16777216; x31251++) {
      struct Anon2092052448* x31252 = x31248;
      struct Anon2092052448 x31253 = x31252[x31251];
      int x31254 = x31253.key;;
      struct Anon2052879266 x31255 = x31253.aggs;;
      struct Anon2092052448 x31256;
      x31256.exists = false;
      x31256.key = x31254;
      x31256.aggs = x31255;
      x31252[x31251] = x31256;
    }
    int* x31264 = (int*)malloc(134217728 * sizeof(int));
    int* x31265 = x31264;
    double* x31266 = (double*)malloc(134217728 * sizeof(double));
    double* x31267 = x31266;
    int x31268 = 0;
    int* x31269 = (int*)malloc(67108864 * sizeof(int));
    int* x31270 = (int*)malloc(134217728 * sizeof(int));
    int x31271;
    for(x31271=0; x31271 < 67108864; x31271++) {
      x31269[x31271] = -1;
    }
    double* x31281 = (double*)malloc(134217728 * sizeof(double));
    double* x31282 = x31281;
    int* x31283 = (int*)malloc(134217728 * sizeof(int));
    int* x31284 = x31283;
    int* x31285 = (int*)malloc(134217728 * sizeof(int));
    int* x31286 = x31285;
    double* x31289 = (double*)malloc(134217728 * sizeof(double));
    double* x31290 = x31289;
    long* x31291 = (long*)malloc(134217728 * sizeof(long));
    long* x31292 = x31291;
    int x31301 = 0;
    int* x31302 = (int*)malloc(67108864 * sizeof(int));
    int* x31303 = (int*)malloc(134217728 * sizeof(int));
    int x31304;
    for(x31304=0; x31304 < 67108864; x31304++) {
      x31302[x31304] = -1;
    }
    struct Anon800615186* x31310 = (struct Anon800615186*)malloc(16777216 * sizeof(struct Anon800615186));
    struct Anon800615186* x31311 = x31310;
    int x31312 = 0;
    int* x31313 = (int*)malloc(16777216 * sizeof(int));
    int x31314;
    for(x31314=0; x31314 < 16777216; x31314++) {
      struct Anon800615186* x31315 = x31311;
      struct Anon800615186 x31316 = x31315[x31314];
      struct Anon1621811895 x31317 = x31316.key;;
      struct Anon2052879266 x31318 = x31316.aggs;;
      struct Anon800615186 x31319;
      x31319.exists = false;
      x31319.key = x31317;
      x31319.aggs = x31318;
      x31315[x31314] = x31319;
    }
    int x31323 = 0;
    int x31325 = 0;
    struct timeval x31774, x31775, x31776;
    gettimeofday(&x31774, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x31327 = x31244;
      bool x31328 = !x31327;
      bool x31333 = x31328;
      if (x31328) {
        int x31329 = x31245;
        int x31330 = x29839;
        bool x31331 = x31329 < x31330;
        x31333 = x31331;
      }
      bool x31334 = x31333;
      if (!x31334) break;
      int x31336 = x31245;
      int* x31337 = x29841;
      int x31338 = x31337[x31336];
      double* x31345 = x29849;
      double x31346 = x31345[x31336];
      x31245 = x31245 + 1;
      int x31371 = x31338 & 16777215;
      int x31372 = x31371;
      struct Anon2092052448* x31373 = x31248;
      struct Anon2092052448 x31374 = x31373[x31371];
      struct Anon2092052448 x31375 = x31374;
      bool x31376 = x31374.exists;;
      bool x31381 = x31376;
      if (x31376) {
        struct Anon2092052448 x31377 = x31375;
        int x31378 = x31377.key;;
        bool x31379 = x31378 == x31338;
        x31381 = x31379;
      }
      bool x31382 = x31381;
      if (x31382) {
        struct Anon2052879266 x31383 = x31374.aggs;;
        int x31387 = x31374.key;;
        double x31384 = x31383._0;;
        double x31385 = x31384 + x31346;
        struct Anon2052879266 x31386;
        x31386._0 = x31385;
        struct Anon2092052448 x31388;
        x31388.exists = true;
        x31388.key = x31387;
        x31388.aggs = x31386;
        x31373[x31371] = x31388;
      } else {
        struct Anon2052879266 x31417;
        x31417._0 = x31346;
        struct Anon2092052448 x31418;
        x31418.exists = true;
        x31418.key = x31338;
        x31418.aggs = x31417;
        for (;;) {
          struct Anon2092052448 x31391 = x31375;
          bool x31392 = x31391.exists;;
          bool x31427;
          if (x31392) {
            int x31393 = x31391.key;;
            bool x31394 = x31393 == x31338;
            bool x31414;
            if (x31394) {
              struct Anon2052879266 x31395 = x31391.aggs;;
              int x31399 = x31372;
              struct Anon2092052448* x31401 = x31248;
              double x31396 = x31395._0;;
              double x31397 = x31396 + x31346;
              struct Anon2052879266 x31398;
              x31398._0 = x31397;
              struct Anon2092052448 x31400;
              x31400.exists = true;
              x31400.key = x31393;
              x31400.aggs = x31398;
              x31401[x31399] = x31400;
              x31414 = false;
            } else {
              int x31404 = x31372;
              int x31405 = x31404 + 1;
              int x31406 = x31405 % 16777215;
              x31372 = x31406;
              struct Anon2092052448* x31408 = x31248;
              struct Anon2092052448 x31409 = x31408[x31406];
              x31375 = x31409;
              x31414 = true;
            }
            x31427 = x31414;
          } else {
            int x31416 = x31372;
            struct Anon2092052448* x31419 = x31248;
            x31419[x31416] = x31418;
            int x31421 = x31249;
            x31250[x31421] = x31416;
            x31249 = x31249 + 1;
            x31427 = false;
          }
          if (!x31427) break;
        }
      }
    }
    int x31436 = x31249;
    int x31438;
    for(x31438=0; x31438 < x31436; x31438++) {
      int x31439 = x31250[x31438];
      struct Anon2092052448* x31440 = x31248;
      struct Anon2092052448 x31441 = x31440[x31439];
      struct Anon2052879266 x31442 = x31441.aggs;;
      double x31443 = x31442._0;;
      bool x31446 = x31443 > x31445;
      if (x31446) {
        double x31447 = x31441.key;;
        int x31448 = x31268;
        int* x31452 = x31265;
        x31452[x31448] = x31447;
        double* x31454 = x31267;
        x31454[x31448] = x31443;
        x31268 = x31268 + 1;
        int x31458 = x31269[x31457];
        x31269[x31457] = x31448;
        x31270[x31448] = x31458;
      } else {
      }
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x31466 = x31240;
      bool x31467 = !x31466;
      bool x31472 = x31467;
      if (x31467) {
        int x31468 = x31241;
        int x31469 = x30613;
        bool x31470 = x31468 < x31469;
        x31472 = x31470;
      }
      bool x31473 = x31472;
      if (!x31473) break;
      int x31475 = x31241;
      int* x31476 = x30615;
      int x31477 = x31476[x31475];
      int* x31478 = x30617;
      int x31479 = x31478[x31475];
      double* x31482 = x30621;
      double x31483 = x31482[x31475];
      long* x31484 = x30623;
      long x31485 = x31484[x31475];
      x31241 = x31241 + 1;
      int x31497 = x31269[x31457];
      int x31498 = x31497;
      int x31543 = x31479 & 67108863;
      for (;;) {
        int x31499 = x31498;
        bool x31500 = x31499 != -1;
        if (!x31500) break;
        int x31502 = x31498;
        int* x31505 = x31265;
        int x31506 = x31505[x31502];
        double* x31507 = x31267;
        double x31508 = x31507[x31502];
        int x31511 = x31270[x31502];
        x31498 = x31511;
        bool x31513 = x31477 == x31506;
        if (x31513) {
          int x31517 = x31301;
          double* x31522 = x31282;
          x31522[x31517] = x31508;
          int* x31524 = x31284;
          x31524[x31517] = x31477;
          int* x31526 = x31286;
          x31526[x31517] = x31479;
          double* x31530 = x31290;
          x31530[x31517] = x31483;
          long* x31532 = x31292;
          x31532[x31517] = x31485;
          x31301 = x31301 + 1;
          int x31544 = x31302[x31543];
          x31302[x31543] = x31517;
          x31303[x31517] = x31544;
        } else {
        }
      }
    }
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x31554 = x31242;
      bool x31555 = !x31554;
      bool x31560 = x31555;
      if (x31555) {
        int x31556 = x31243;
        int x31557 = x30964;
        bool x31558 = x31556 < x31557;
        x31560 = x31558;
      }
      bool x31561 = x31560;
      if (!x31561) break;
      int x31563 = x31243;
      int* x31564 = x30966;
      int x31565 = x31564[x31563];
      char** x31566 = x30968;
      char* x31567 = x31566[x31563];
      x31243 = x31243 + 1;
      int x31582 = x31565 & 67108863;
      int x31583 = x31302[x31582];
      int x31584 = x31583;
      char x31622 = x31567[0];
      int x31623 = x31622 * 41;
      char x31624 = x31567[1];
      int x31625 = x31623 + x31624;
      int x31626 = x31625 * 41;
      char x31627 = x31567[2];
      int x31628 = x31626 + x31627;
      int x31629 = x31628 * 41;
      char x31630 = x31567[3];
      int x31631 = x31629 + x31630;
      int x31633 = x31565 * 41;
      int x31634 = x31633 + x31631;
      int x31635 = x31634 * 41;
      for (;;) {
        int x31585 = x31584;
        bool x31586 = x31585 != -1;
        if (!x31586) break;
        int x31588 = x31584;
        double* x31593 = x31282;
        double x31594 = x31593[x31588];
        int* x31596 = x31284;
        int x31597 = x31596[x31588];
        int* x31598 = x31286;
        int x31599 = x31598[x31588];
        double* x31602 = x31290;
        double x31603 = x31602[x31588];
        long* x31604 = x31292;
        long x31605 = x31604[x31588];
        int x31615 = x31303[x31588];
        x31584 = x31615;
        bool x31617 = x31599 == x31565;
        if (x31617) {
          int x31632 = (int)x31605;
          int x31636 = x31635 + x31632;
          int x31637 = x31636 * 41;
          int x31638 = x31637 + x31597;
          int x31639 = x31638 * 41;
          int x31640 = x31639 + 777;
          int x31641 = x31640 & 16777215;
          int x31642 = x31641;
          struct Anon800615186* x31643 = x31311;
          struct Anon800615186 x31644 = x31643[x31641];
          struct Anon800615186 x31645 = x31644;
          bool x31646 = x31644.exists;;
          bool x31668 = x31646;
          if (x31646) {
            struct Anon800615186 x31647 = x31645;
            struct Anon1621811895 x31648 = x31647.key;;
            char* x31649 = x31648.C_NAME;;
            bool x31650 = strcmp(x31649,x31567) == 0;;
            bool x31659 = x31650;
            if (x31650) {
              int x31651 = x31648.C_CUSTKEY;;
              bool x31652 = x31651 == x31565;
              x31659 = x31652;
            }
            bool x31660 = x31659;
            bool x31661 = x31660;
            if (x31660) {
              int x31653 = x31648.O_ORDERKEY;;
              bool x31654 = x31653 == x31597;
              x31661 = x31654;
            }
            bool x31662 = x31661;
            bool x31663 = x31662;
            if (x31662) {
              long x31655 = x31648.O_ORDERDATE;;
              bool x31656 = x31655 == x31605;
              x31663 = x31656;
            }
            bool x31664 = x31663;
            bool x31665 = x31664;
            if (x31664) {
              double x31657 = x31648.O_TOTALPRICE;;
              bool x31658 = x31657 == x31603;
              x31665 = x31658;
            }
            bool x31666 = x31665;
            x31668 = x31666;
          }
          bool x31669 = x31668;
          if (x31669) {
            struct Anon2052879266 x31670 = x31644.aggs;;
            struct Anon1621811895 x31674 = x31644.key;;
            double x31671 = x31670._0;;
            double x31672 = x31671 + x31594;
            struct Anon2052879266 x31673;
            x31673._0 = x31672;
            struct Anon800615186 x31675;
            x31675.exists = true;
            x31675.key = x31674;
            x31675.aggs = x31673;
            x31643[x31641] = x31675;
          } else {
            struct Anon2052879266 x31595;
            x31595._0 = x31594;
            struct Anon1621811895 x31621;
            x31621.C_NAME = x31567;
            x31621.C_CUSTKEY = x31565;
            x31621.O_ORDERKEY = x31597;
            x31621.O_ORDERDATE = x31605;
            x31621.O_TOTALPRICE = x31603;
            struct Anon800615186 x31721;
            x31721.exists = true;
            x31721.key = x31621;
            x31721.aggs = x31595;
            for (;;) {
              struct Anon800615186 x31678 = x31645;
              bool x31679 = x31678.exists;;
              bool x31730;
              if (x31679) {
                struct Anon1621811895 x31680 = x31678.key;;
                char* x31681 = x31680.C_NAME;;
                bool x31682 = strcmp(x31681,x31567) == 0;;
                bool x31691 = x31682;
                if (x31682) {
                  int x31683 = x31680.C_CUSTKEY;;
                  bool x31684 = x31683 == x31565;
                  x31691 = x31684;
                }
                bool x31692 = x31691;
                bool x31693 = x31692;
                if (x31692) {
                  int x31685 = x31680.O_ORDERKEY;;
                  bool x31686 = x31685 == x31597;
                  x31693 = x31686;
                }
                bool x31694 = x31693;
                bool x31695 = x31694;
                if (x31694) {
                  long x31687 = x31680.O_ORDERDATE;;
                  bool x31688 = x31687 == x31605;
                  x31695 = x31688;
                }
                bool x31696 = x31695;
                bool x31697 = x31696;
                if (x31696) {
                  double x31689 = x31680.O_TOTALPRICE;;
                  bool x31690 = x31689 == x31603;
                  x31697 = x31690;
                }
                bool x31698 = x31697;
                bool x31718;
                if (x31698) {
                  struct Anon2052879266 x31699 = x31678.aggs;;
                  int x31703 = x31642;
                  struct Anon800615186* x31705 = x31311;
                  double x31700 = x31699._0;;
                  double x31701 = x31700 + x31594;
                  struct Anon2052879266 x31702;
                  x31702._0 = x31701;
                  struct Anon800615186 x31704;
                  x31704.exists = true;
                  x31704.key = x31680;
                  x31704.aggs = x31702;
                  x31705[x31703] = x31704;
                  x31718 = false;
                } else {
                  int x31708 = x31642;
                  int x31709 = x31708 + 1;
                  int x31710 = x31709 % 16777215;
                  x31642 = x31710;
                  struct Anon800615186* x31712 = x31311;
                  struct Anon800615186 x31713 = x31712[x31710];
                  x31645 = x31713;
                  x31718 = true;
                }
                x31730 = x31718;
              } else {
                int x31720 = x31642;
                struct Anon800615186* x31722 = x31311;
                x31722[x31720] = x31721;
                int x31724 = x31312;
                x31313[x31724] = x31720;
                x31312 = x31312 + 1;
                x31730 = false;
              }
              if (!x31730) break;
            }
          }
        } else {
        }
      }
    }
    int x31743 = x31312;
    int x31745;
    for(x31745=0; x31745 < x31743; x31745++) {
      int x31746 = x31313[x31745];
      struct Anon800615186* x31747 = x31311;
      struct Anon800615186 x31748 = x31747[x31746];
      int x31749 = x31323;
      bool x31750 = x31749 < 100;
      bool x31751 = x31750 == false;
      if (x31751) {
      } else {
        struct Anon1621811895 x31754 = x31748.key;;
        struct Anon2052879266 x31762 = x31748.aggs;;
        char* x31755 = x31754.C_NAME;;
        int x31756 = strlen(x31755);
        int x31757 = x31754.C_CUSTKEY;;
        int x31758 = x31754.O_ORDERKEY;;
        long x31759 = x31754.O_ORDERDATE;;
        char* x31760 = (char*)malloc(9 * sizeof(char));;
        snprintf(x31760, 9, "%lu", x31759);
        double x31761 = x31754.O_TOTALPRICE;;
        double x31763 = x31762._0;;
        printf("%.*s|%d|%d|%.*s|%.2f|%.2f\n",x31756,x31755,x31757,x31758,x31760,x31761,x31763);
        x31323 = x31323 + 1;
        x31325 = x31325 + 1;
      }
    }
    int x31771 = x31325;
    printf("(%d rows)\n",x31771);
    gettimeofday(&x31775, NULL);
    timeval_subtract(&x31776, &x31775, &x31774);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x31776.tv_sec * 1000) + (x31776.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
