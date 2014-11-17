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

struct Anon1268892766 {
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
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
int main(int x15425, char** x15426) {
  int x15427 = 0;
  int x15428 = 1048576;
  int x15429 = 0;
  int* x15430 = (int*)malloc(1048576 * sizeof(int));
  int* x15431 = x15430;
  char** x15432 = (char**)malloc(1048576 * sizeof(char*));
  char** x15433 = x15432;
  int x995 = open("../databases/sf2/part.tbl",0);
  int x996 = fsize(x995);
  char* x997 = mmap(0, x996, PROT_READ, MAP_FILE | MAP_SHARED, x995, 0);
  for (;;) {
    int x15449 = x15427;
    bool x15450 = x15449 < x996;
    if (!x15450) break;
    int x15453 = 0;
    for (;;) {
      int x15454 = x15427;
      char x15455 = x997[x15454];
      bool x15456 = x15455 != '|';
      bool x15461 = x15456;
      if (x15456) {
        int x15457 = x15427;
        char x15458 = x997[x15457];
        bool x15459 = x15458 != '\n';
        x15461 = x15459;
      }
      bool x15462 = x15461;
      if (!x15462) break;
      int x15464 = x15453;
      int x15466 = x15427;
      int x15465 = x15464 * 10;
      char x15467 = x997[x15466];
      char x15468 = x15467 - '0';
      int x15469 = x15465 + x15468;
      x15453 = x15469;
      x15427 = x15427 + 1;
    }
    x15427 = x15427 + 1;
    int x15475 = x15453;
    int x15476 = x15427;
    for (;;) {
      int x15477 = x15427;
      char x15478 = x997[x15477];
      bool x15479 = x15478 != '|';
      bool x15484 = x15479;
      if (x15479) {
        int x15480 = x15427;
        char x15481 = x997[x15480];
        bool x15482 = x15481 != '\n';
        x15484 = x15482;
      }
      bool x15485 = x15484;
      if (!x15485) break;
      x15427 = x15427 + 1;
    }
    x15427 = x15427 + 1;
    for (;;) {
      int x15495 = x15427;
      char x15496 = x997[x15495];
      bool x15497 = x15496 != '|';
      bool x15502 = x15497;
      if (x15497) {
        int x15498 = x15427;
        char x15499 = x997[x15498];
        bool x15500 = x15499 != '\n';
        x15502 = x15500;
      }
      bool x15503 = x15502;
      if (!x15503) break;
      x15427 = x15427 + 1;
    }
    x15427 = x15427 + 1;
    for (;;) {
      int x15513 = x15427;
      char x15514 = x997[x15513];
      bool x15515 = x15514 != '|';
      bool x15520 = x15515;
      if (x15515) {
        int x15516 = x15427;
        char x15517 = x997[x15516];
        bool x15518 = x15517 != '\n';
        x15520 = x15518;
      }
      bool x15521 = x15520;
      if (!x15521) break;
      x15427 = x15427 + 1;
    }
    x15427 = x15427 + 1;
    for (;;) {
      int x15531 = x15427;
      char x15532 = x997[x15531];
      bool x15533 = x15532 != '|';
      bool x15538 = x15533;
      if (x15533) {
        int x15534 = x15427;
        char x15535 = x997[x15534];
        bool x15536 = x15535 != '\n';
        x15538 = x15536;
      }
      bool x15539 = x15538;
      if (!x15539) break;
      x15427 = x15427 + 1;
    }
    x15427 = x15427 + 1;
    for (;;) {
      int x15550 = x15427;
      char x15551 = x997[x15550];
      bool x15552 = x15551 != '|';
      bool x15557 = x15552;
      if (x15552) {
        int x15553 = x15427;
        char x15554 = x997[x15553];
        bool x15555 = x15554 != '\n';
        x15557 = x15555;
      }
      bool x15558 = x15557;
      if (!x15558) break;
      x15427 = x15427 + 1;
    }
    x15427 = x15427 + 1;
    for (;;) {
      int x15573 = x15427;
      char x15574 = x997[x15573];
      bool x15575 = x15574 != '|';
      bool x15580 = x15575;
      if (x15575) {
        int x15576 = x15427;
        char x15577 = x997[x15576];
        bool x15578 = x15577 != '\n';
        x15580 = x15578;
      }
      bool x15581 = x15580;
      if (!x15581) break;
      x15427 = x15427 + 1;
    }
    x15427 = x15427 + 1;
    for (;;) {
      int x15593 = x15427;
      char x15594 = x997[x15593];
      bool x15595 = x15594 != '.';
      bool x15600 = x15595;
      if (x15595) {
        int x15596 = x15427;
        char x15597 = x997[x15596];
        bool x15598 = x15597 != '|';
        x15600 = x15598;
      }
      bool x15601 = x15600;
      bool x15606 = x15601;
      if (x15601) {
        int x15602 = x15427;
        char x15603 = x997[x15602];
        bool x15604 = x15603 != '\n';
        x15606 = x15604;
      }
      bool x15607 = x15606;
      if (!x15607) break;
      x15427 = x15427 + 1;
    }
    int x15619 = x15427;
    char x15620 = x997[x15619];
    bool x15621 = x15620 == '.';
    if (x15621) {
      x15427 = x15427 + 1;
      for (;;) {
        int x15623 = x15427;
        char x15624 = x997[x15623];
        bool x15625 = x15624 != '|';
        bool x15630 = x15625;
        if (x15625) {
          int x15626 = x15427;
          char x15627 = x997[x15626];
          bool x15628 = x15627 != '\n';
          x15630 = x15628;
        }
        bool x15631 = x15630;
        if (!x15631) break;
        x15427 = x15427 + 1;
      }
    } else {
    }
    x15427 = x15427 + 1;
    for (;;) {
      int x15656 = x15427;
      char x15657 = x997[x15656];
      bool x15658 = x15657 != '|';
      bool x15663 = x15658;
      if (x15658) {
        int x15659 = x15427;
        char x15660 = x997[x15659];
        bool x15661 = x15660 != '\n';
        x15663 = x15661;
      }
      bool x15664 = x15663;
      if (!x15664) break;
      x15427 = x15427 + 1;
    }
    x15427 = x15427 + 1;
    int x15674 = x15429;
    int x15675 = x15428;
    bool x15676 = x15674 == x15675;
    if (x15676) {
      int x15677 = x15675 * 4;
      x15428 = x15677;
      printf("buffer.resize %d\n",x15677);
      int* x15680 = x15431;
      int* x15681 = (int*)realloc(x15680,x15677 * sizeof(int));
      x15431 = x15681;
      char** x15683 = x15433;
      char** x15684 = (char**)realloc(x15683,x15677 * sizeof(char*));
      x15433 = x15684;
    } else {
    }
    int* x15709 = x15431;
    x15709[x15674] = x15475;
    char** x15711 = x15433;
    char* x15493 = x997+x15476;
    x15711[x15674] = x15493;
    x15429 = x15429 + 1;
  }
  int x15730 = 0;
  int x15731 = 1048576;
  int x15732 = 0;
  int* x15733 = (int*)malloc(1048576 * sizeof(int));
  int* x15734 = x15733;
  char** x15735 = (char**)malloc(1048576 * sizeof(char*));
  char** x15736 = x15735;
  int x1512 = open("../databases/sf2/nation.tbl",0);
  int x1513 = fsize(x1512);
  char* x1514 = mmap(0, x1513, PROT_READ, MAP_FILE | MAP_SHARED, x1512, 0);
  for (;;) {
    int x15741 = x15730;
    bool x15742 = x15741 < x1513;
    if (!x15742) break;
    int x15745 = 0;
    for (;;) {
      int x15746 = x15730;
      char x15747 = x1514[x15746];
      bool x15748 = x15747 != '|';
      bool x15753 = x15748;
      if (x15748) {
        int x15749 = x15730;
        char x15750 = x1514[x15749];
        bool x15751 = x15750 != '\n';
        x15753 = x15751;
      }
      bool x15754 = x15753;
      if (!x15754) break;
      int x15756 = x15745;
      int x15758 = x15730;
      int x15757 = x15756 * 10;
      char x15759 = x1514[x15758];
      char x15760 = x15759 - '0';
      int x15761 = x15757 + x15760;
      x15745 = x15761;
      x15730 = x15730 + 1;
    }
    x15730 = x15730 + 1;
    int x15767 = x15745;
    int x15768 = x15730;
    for (;;) {
      int x15769 = x15730;
      char x15770 = x1514[x15769];
      bool x15771 = x15770 != '|';
      bool x15776 = x15771;
      if (x15771) {
        int x15772 = x15730;
        char x15773 = x1514[x15772];
        bool x15774 = x15773 != '\n';
        x15776 = x15774;
      }
      bool x15777 = x15776;
      if (!x15777) break;
      x15730 = x15730 + 1;
    }
    x15730 = x15730 + 1;
    for (;;) {
      int x15788 = x15730;
      char x15789 = x1514[x15788];
      bool x15790 = x15789 != '|';
      bool x15795 = x15790;
      if (x15790) {
        int x15791 = x15730;
        char x15792 = x1514[x15791];
        bool x15793 = x15792 != '\n';
        x15795 = x15793;
      }
      bool x15796 = x15795;
      if (!x15796) break;
      x15730 = x15730 + 1;
    }
    x15730 = x15730 + 1;
    for (;;) {
      int x15811 = x15730;
      char x15812 = x1514[x15811];
      bool x15813 = x15812 != '|';
      bool x15818 = x15813;
      if (x15813) {
        int x15814 = x15730;
        char x15815 = x1514[x15814];
        bool x15816 = x15815 != '\n';
        x15818 = x15816;
      }
      bool x15819 = x15818;
      if (!x15819) break;
      x15730 = x15730 + 1;
    }
    x15730 = x15730 + 1;
    int x15829 = x15732;
    int x15830 = x15731;
    bool x15831 = x15829 == x15830;
    if (x15831) {
      int x15832 = x15830 * 4;
      x15731 = x15832;
      printf("buffer.resize %d\n",x15832);
      int* x15835 = x15734;
      int* x15836 = (int*)realloc(x15835,x15832 * sizeof(int));
      x15734 = x15836;
      char** x15838 = x15736;
      char** x15839 = (char**)realloc(x15838,x15832 * sizeof(char*));
      x15736 = x15839;
    } else {
    }
    int* x15849 = x15734;
    x15849[x15829] = x15767;
    char** x15851 = x15736;
    char* x15785 = x1514+x15768;
    x15851[x15829] = x15785;
    x15732 = x15732 + 1;
  }
  int x15860 = 0;
  int x15861 = 1048576;
  int x15862 = 0;
  int* x15863 = (int*)malloc(1048576 * sizeof(int));
  int* x15864 = x15863;
  long* x15871 = (long*)malloc(1048576 * sizeof(long));
  long* x15872 = x15871;
  int x3366 = open("../databases/sf2/orders.tbl",0);
  int x3367 = fsize(x3366);
  char* x3368 = mmap(0, x3367, PROT_READ, MAP_FILE | MAP_SHARED, x3366, 0);
  for (;;) {
    int x15881 = x15860;
    bool x15882 = x15881 < x3367;
    if (!x15882) break;
    int x15885 = 0;
    for (;;) {
      int x15886 = x15860;
      char x15887 = x3368[x15886];
      bool x15888 = x15887 != '|';
      bool x15893 = x15888;
      if (x15888) {
        int x15889 = x15860;
        char x15890 = x3368[x15889];
        bool x15891 = x15890 != '\n';
        x15893 = x15891;
      }
      bool x15894 = x15893;
      if (!x15894) break;
      int x15896 = x15885;
      int x15898 = x15860;
      int x15897 = x15896 * 10;
      char x15899 = x3368[x15898];
      char x15900 = x15899 - '0';
      int x15901 = x15897 + x15900;
      x15885 = x15901;
      x15860 = x15860 + 1;
    }
    x15860 = x15860 + 1;
    int x15907 = x15885;
    for (;;) {
      int x15910 = x15860;
      char x15911 = x3368[x15910];
      bool x15912 = x15911 != '|';
      bool x15917 = x15912;
      if (x15912) {
        int x15913 = x15860;
        char x15914 = x3368[x15913];
        bool x15915 = x15914 != '\n';
        x15917 = x15915;
      }
      bool x15918 = x15917;
      if (!x15918) break;
      x15860 = x15860 + 1;
    }
    x15860 = x15860 + 1;
    x15860 = x15860 + 2;
    for (;;) {
      int x15938 = x15860;
      char x15939 = x3368[x15938];
      bool x15940 = x15939 != '.';
      bool x15945 = x15940;
      if (x15940) {
        int x15941 = x15860;
        char x15942 = x3368[x15941];
        bool x15943 = x15942 != '|';
        x15945 = x15943;
      }
      bool x15946 = x15945;
      bool x15951 = x15946;
      if (x15946) {
        int x15947 = x15860;
        char x15948 = x3368[x15947];
        bool x15949 = x15948 != '\n';
        x15951 = x15949;
      }
      bool x15952 = x15951;
      if (!x15952) break;
      x15860 = x15860 + 1;
    }
    int x15964 = x15860;
    char x15965 = x3368[x15964];
    bool x15966 = x15965 == '.';
    if (x15966) {
      x15860 = x15860 + 1;
      for (;;) {
        int x15968 = x15860;
        char x15969 = x3368[x15968];
        bool x15970 = x15969 != '|';
        bool x15975 = x15970;
        if (x15970) {
          int x15971 = x15860;
          char x15972 = x3368[x15971];
          bool x15973 = x15972 != '\n';
          x15975 = x15973;
        }
        bool x15976 = x15975;
        if (!x15976) break;
        x15860 = x15860 + 1;
      }
    } else {
    }
    x15860 = x15860 + 1;
    int x16001 = 0;
    for (;;) {
      int x16002 = x15860;
      char x16003 = x3368[x16002];
      bool x16004 = x16003 != '-';
      bool x16009 = x16004;
      if (x16004) {
        int x16005 = x15860;
        char x16006 = x3368[x16005];
        bool x16007 = x16006 != '\n';
        x16009 = x16007;
      }
      bool x16010 = x16009;
      if (!x16010) break;
      int x16012 = x16001;
      int x16014 = x15860;
      int x16013 = x16012 * 10;
      char x16015 = x3368[x16014];
      char x16016 = x16015 - '0';
      int x16017 = x16013 + x16016;
      x16001 = x16017;
      x15860 = x15860 + 1;
    }
    x15860 = x15860 + 1;
    int x16023 = x16001;
    int x16025 = 0;
    for (;;) {
      int x16026 = x15860;
      char x16027 = x3368[x16026];
      bool x16028 = x16027 != '-';
      bool x16033 = x16028;
      if (x16028) {
        int x16029 = x15860;
        char x16030 = x3368[x16029];
        bool x16031 = x16030 != '\n';
        x16033 = x16031;
      }
      bool x16034 = x16033;
      if (!x16034) break;
      int x16036 = x16025;
      int x16038 = x15860;
      int x16037 = x16036 * 10;
      char x16039 = x3368[x16038];
      char x16040 = x16039 - '0';
      int x16041 = x16037 + x16040;
      x16025 = x16041;
      x15860 = x15860 + 1;
    }
    x15860 = x15860 + 1;
    int x16047 = x16025;
    int x16049 = 0;
    for (;;) {
      int x16050 = x15860;
      char x16051 = x3368[x16050];
      bool x16052 = x16051 != '|';
      bool x16057 = x16052;
      if (x16052) {
        int x16053 = x15860;
        char x16054 = x3368[x16053];
        bool x16055 = x16054 != '\n';
        x16057 = x16055;
      }
      bool x16058 = x16057;
      if (!x16058) break;
      int x16060 = x16049;
      int x16062 = x15860;
      int x16061 = x16060 * 10;
      char x16063 = x3368[x16062];
      char x16064 = x16063 - '0';
      int x16065 = x16061 + x16064;
      x16049 = x16065;
      x15860 = x15860 + 1;
    }
    x15860 = x15860 + 1;
    int x16071 = x16049;
    for (;;) {
      int x16077 = x15860;
      char x16078 = x3368[x16077];
      bool x16079 = x16078 != '|';
      bool x16084 = x16079;
      if (x16079) {
        int x16080 = x15860;
        char x16081 = x3368[x16080];
        bool x16082 = x16081 != '\n';
        x16084 = x16082;
      }
      bool x16085 = x16084;
      if (!x16085) break;
      x15860 = x15860 + 1;
    }
    x15860 = x15860 + 1;
    for (;;) {
      int x16095 = x15860;
      char x16096 = x3368[x16095];
      bool x16097 = x16096 != '|';
      bool x16102 = x16097;
      if (x16097) {
        int x16098 = x15860;
        char x16099 = x3368[x16098];
        bool x16100 = x16099 != '\n';
        x16102 = x16100;
      }
      bool x16103 = x16102;
      if (!x16103) break;
      x15860 = x15860 + 1;
    }
    x15860 = x15860 + 1;
    for (;;) {
      int x16114 = x15860;
      char x16115 = x3368[x16114];
      bool x16116 = x16115 != '|';
      bool x16121 = x16116;
      if (x16116) {
        int x16117 = x15860;
        char x16118 = x3368[x16117];
        bool x16119 = x16118 != '\n';
        x16121 = x16119;
      }
      bool x16122 = x16121;
      if (!x16122) break;
      x15860 = x15860 + 1;
    }
    x15860 = x15860 + 1;
    for (;;) {
      int x16137 = x15860;
      char x16138 = x3368[x16137];
      bool x16139 = x16138 != '|';
      bool x16144 = x16139;
      if (x16139) {
        int x16140 = x15860;
        char x16141 = x3368[x16140];
        bool x16142 = x16141 != '\n';
        x16144 = x16142;
      }
      bool x16145 = x16144;
      if (!x16145) break;
      x15860 = x15860 + 1;
    }
    x15860 = x15860 + 1;
    int x16155 = x15862;
    int x16156 = x15861;
    bool x16157 = x16155 == x16156;
    if (x16157) {
      int x16158 = x16156 * 4;
      x15861 = x16158;
      printf("buffer.resize %d\n",x16158);
      int* x16161 = x15864;
      int* x16162 = (int*)realloc(x16161,x16158 * sizeof(int));
      x15864 = x16162;
      long* x16173 = x15872;
      long* x16174 = (long*)realloc(x16173,x16158 * sizeof(long));
      x15872 = x16174;
    } else {
    }
    int* x16190 = x15864;
    x16190[x16155] = x15907;
    long* x16198 = x15872;
    long x16072 = x16023 * 10000L;
    long x16073 = x16047 * 100L;
    long x16074 = x16072 + x16073;
    long x16075 = x16074 + x16071;
    x16198[x16155] = x16075;
    x15862 = x15862 + 1;
  }
  int x16211 = 0;
  int x16212 = 1048576;
  int x16213 = 0;
  int* x16214 = (int*)malloc(1048576 * sizeof(int));
  int* x16215 = x16214;
  int* x16216 = (int*)malloc(1048576 * sizeof(int));
  int* x16217 = x16216;
  double* x16220 = (double*)malloc(1048576 * sizeof(double));
  double* x16221 = x16220;
  int x1301 = open("../databases/sf2/partsupp.tbl",0);
  int x1302 = fsize(x1301);
  char* x1303 = mmap(0, x1302, PROT_READ, MAP_FILE | MAP_SHARED, x1301, 0);
  for (;;) {
    int x16224 = x16211;
    bool x16225 = x16224 < x1302;
    if (!x16225) break;
    int x16228 = 0;
    for (;;) {
      int x16229 = x16211;
      char x16230 = x1303[x16229];
      bool x16231 = x16230 != '|';
      bool x16236 = x16231;
      if (x16231) {
        int x16232 = x16211;
        char x16233 = x1303[x16232];
        bool x16234 = x16233 != '\n';
        x16236 = x16234;
      }
      bool x16237 = x16236;
      if (!x16237) break;
      int x16239 = x16228;
      int x16241 = x16211;
      int x16240 = x16239 * 10;
      char x16242 = x1303[x16241];
      char x16243 = x16242 - '0';
      int x16244 = x16240 + x16243;
      x16228 = x16244;
      x16211 = x16211 + 1;
    }
    x16211 = x16211 + 1;
    int x16250 = x16228;
    int x16252 = 0;
    for (;;) {
      int x16253 = x16211;
      char x16254 = x1303[x16253];
      bool x16255 = x16254 != '|';
      bool x16260 = x16255;
      if (x16255) {
        int x16256 = x16211;
        char x16257 = x1303[x16256];
        bool x16258 = x16257 != '\n';
        x16260 = x16258;
      }
      bool x16261 = x16260;
      if (!x16261) break;
      int x16263 = x16252;
      int x16265 = x16211;
      int x16264 = x16263 * 10;
      char x16266 = x1303[x16265];
      char x16267 = x16266 - '0';
      int x16268 = x16264 + x16267;
      x16252 = x16268;
      x16211 = x16211 + 1;
    }
    x16211 = x16211 + 1;
    int x16274 = x16252;
    for (;;) {
      int x16277 = x16211;
      char x16278 = x1303[x16277];
      bool x16279 = x16278 != '|';
      bool x16284 = x16279;
      if (x16279) {
        int x16280 = x16211;
        char x16281 = x1303[x16280];
        bool x16282 = x16281 != '\n';
        x16284 = x16282;
      }
      bool x16285 = x16284;
      if (!x16285) break;
      x16211 = x16211 + 1;
    }
    x16211 = x16211 + 1;
    int x16300 = 0;
    int x16301 = 1;
    for (;;) {
      int x16302 = x16211;
      char x16303 = x1303[x16302];
      bool x16304 = x16303 != '.';
      bool x16309 = x16304;
      if (x16304) {
        int x16305 = x16211;
        char x16306 = x1303[x16305];
        bool x16307 = x16306 != '|';
        x16309 = x16307;
      }
      bool x16310 = x16309;
      bool x16315 = x16310;
      if (x16310) {
        int x16311 = x16211;
        char x16312 = x1303[x16311];
        bool x16313 = x16312 != '\n';
        x16315 = x16313;
      }
      bool x16316 = x16315;
      if (!x16316) break;
      int x16318 = x16300;
      int x16320 = x16211;
      int x16319 = x16318 * 10;
      char x16321 = x1303[x16320];
      char x16322 = x16321 - '0';
      int x16323 = x16319 + x16322;
      x16300 = x16323;
      x16211 = x16211 + 1;
    }
    int x16328 = x16211;
    char x16329 = x1303[x16328];
    bool x16330 = x16329 == '.';
    if (x16330) {
      x16211 = x16211 + 1;
      for (;;) {
        int x16332 = x16211;
        char x16333 = x1303[x16332];
        bool x16334 = x16333 != '|';
        bool x16339 = x16334;
        if (x16334) {
          int x16335 = x16211;
          char x16336 = x1303[x16335];
          bool x16337 = x16336 != '\n';
          x16339 = x16337;
        }
        bool x16340 = x16339;
        if (!x16340) break;
        int x16342 = x16300;
        int x16344 = x16211;
        int x16343 = x16342 * 10;
        char x16345 = x1303[x16344];
        char x16346 = x16345 - '0';
        int x16347 = x16343 + x16346;
        x16300 = x16347;
        int x16349 = x16301;
        int x16350 = x16349 * 10;
        x16301 = x16350;
        x16211 = x16211 + 1;
      }
    } else {
    }
    x16211 = x16211 + 1;
    int x16359 = x16300;
    int x16361 = x16301;
    for (;;) {
      int x16365 = x16211;
      char x16366 = x1303[x16365];
      bool x16367 = x16366 != '|';
      bool x16372 = x16367;
      if (x16367) {
        int x16368 = x16211;
        char x16369 = x1303[x16368];
        bool x16370 = x16369 != '\n';
        x16372 = x16370;
      }
      bool x16373 = x16372;
      if (!x16373) break;
      x16211 = x16211 + 1;
    }
    x16211 = x16211 + 1;
    int x16383 = x16213;
    int x16384 = x16212;
    bool x16385 = x16383 == x16384;
    if (x16385) {
      int x16386 = x16384 * 4;
      x16212 = x16386;
      printf("buffer.resize %d\n",x16386);
      int* x16389 = x16215;
      int* x16390 = (int*)realloc(x16389,x16386 * sizeof(int));
      x16215 = x16390;
      int* x16392 = x16217;
      int* x16393 = (int*)realloc(x16392,x16386 * sizeof(int));
      x16217 = x16393;
      double* x16398 = x16221;
      double* x16399 = (double*)realloc(x16398,x16386 * sizeof(double));
      x16221 = x16399;
    } else {
    }
    int* x16406 = x16215;
    x16406[x16383] = x16250;
    int* x16408 = x16217;
    x16408[x16383] = x16274;
    double* x16412 = x16221;
    double x16360 = (double)x16359;
    double x16362 = (double)x16361;
    double x16363 = x16360 / x16362;
    x16412[x16383] = x16363;
    x16213 = x16213 + 1;
  }
  int x16419 = 0;
  int x16420 = 1048576;
  int x16421 = 0;
  int* x16422 = (int*)malloc(1048576 * sizeof(int));
  int* x16423 = x16422;
  int* x16428 = (int*)malloc(1048576 * sizeof(int));
  int* x16429 = x16428;
  int x1747 = open("../databases/sf2/supplier.tbl",0);
  int x1748 = fsize(x1747);
  char* x1749 = mmap(0, x1748, PROT_READ, MAP_FILE | MAP_SHARED, x1747, 0);
  for (;;) {
    int x16436 = x16419;
    bool x16437 = x16436 < x1748;
    if (!x16437) break;
    int x16440 = 0;
    for (;;) {
      int x16441 = x16419;
      char x16442 = x1749[x16441];
      bool x16443 = x16442 != '|';
      bool x16448 = x16443;
      if (x16443) {
        int x16444 = x16419;
        char x16445 = x1749[x16444];
        bool x16446 = x16445 != '\n';
        x16448 = x16446;
      }
      bool x16449 = x16448;
      if (!x16449) break;
      int x16451 = x16440;
      int x16453 = x16419;
      int x16452 = x16451 * 10;
      char x16454 = x1749[x16453];
      char x16455 = x16454 - '0';
      int x16456 = x16452 + x16455;
      x16440 = x16456;
      x16419 = x16419 + 1;
    }
    x16419 = x16419 + 1;
    int x16462 = x16440;
    for (;;) {
      int x16464 = x16419;
      char x16465 = x1749[x16464];
      bool x16466 = x16465 != '|';
      bool x16471 = x16466;
      if (x16466) {
        int x16467 = x16419;
        char x16468 = x1749[x16467];
        bool x16469 = x16468 != '\n';
        x16471 = x16469;
      }
      bool x16472 = x16471;
      if (!x16472) break;
      x16419 = x16419 + 1;
    }
    x16419 = x16419 + 1;
    for (;;) {
      int x16482 = x16419;
      char x16483 = x1749[x16482];
      bool x16484 = x16483 != '|';
      bool x16489 = x16484;
      if (x16484) {
        int x16485 = x16419;
        char x16486 = x1749[x16485];
        bool x16487 = x16486 != '\n';
        x16489 = x16487;
      }
      bool x16490 = x16489;
      if (!x16490) break;
      x16419 = x16419 + 1;
    }
    x16419 = x16419 + 1;
    int x16500 = 0;
    for (;;) {
      int x16501 = x16419;
      char x16502 = x1749[x16501];
      bool x16503 = x16502 != '|';
      bool x16508 = x16503;
      if (x16503) {
        int x16504 = x16419;
        char x16505 = x1749[x16504];
        bool x16506 = x16505 != '\n';
        x16508 = x16506;
      }
      bool x16509 = x16508;
      if (!x16509) break;
      int x16511 = x16500;
      int x16513 = x16419;
      int x16512 = x16511 * 10;
      char x16514 = x1749[x16513];
      char x16515 = x16514 - '0';
      int x16516 = x16512 + x16515;
      x16500 = x16516;
      x16419 = x16419 + 1;
    }
    x16419 = x16419 + 1;
    int x16522 = x16500;
    for (;;) {
      int x16524 = x16419;
      char x16525 = x1749[x16524];
      bool x16526 = x16525 != '|';
      bool x16531 = x16526;
      if (x16526) {
        int x16527 = x16419;
        char x16528 = x1749[x16527];
        bool x16529 = x16528 != '\n';
        x16531 = x16529;
      }
      bool x16532 = x16531;
      if (!x16532) break;
      x16419 = x16419 + 1;
    }
    x16419 = x16419 + 1;
    for (;;) {
      int x16544 = x16419;
      char x16545 = x1749[x16544];
      bool x16546 = x16545 != '.';
      bool x16551 = x16546;
      if (x16546) {
        int x16547 = x16419;
        char x16548 = x1749[x16547];
        bool x16549 = x16548 != '|';
        x16551 = x16549;
      }
      bool x16552 = x16551;
      bool x16557 = x16552;
      if (x16552) {
        int x16553 = x16419;
        char x16554 = x1749[x16553];
        bool x16555 = x16554 != '\n';
        x16557 = x16555;
      }
      bool x16558 = x16557;
      if (!x16558) break;
      x16419 = x16419 + 1;
    }
    int x16570 = x16419;
    char x16571 = x1749[x16570];
    bool x16572 = x16571 == '.';
    if (x16572) {
      x16419 = x16419 + 1;
      for (;;) {
        int x16574 = x16419;
        char x16575 = x1749[x16574];
        bool x16576 = x16575 != '|';
        bool x16581 = x16576;
        if (x16576) {
          int x16577 = x16419;
          char x16578 = x1749[x16577];
          bool x16579 = x16578 != '\n';
          x16581 = x16579;
        }
        bool x16582 = x16581;
        if (!x16582) break;
        x16419 = x16419 + 1;
      }
    } else {
    }
    x16419 = x16419 + 1;
    for (;;) {
      int x16607 = x16419;
      char x16608 = x1749[x16607];
      bool x16609 = x16608 != '|';
      bool x16614 = x16609;
      if (x16609) {
        int x16610 = x16419;
        char x16611 = x1749[x16610];
        bool x16612 = x16611 != '\n';
        x16614 = x16612;
      }
      bool x16615 = x16614;
      if (!x16615) break;
      x16419 = x16419 + 1;
    }
    x16419 = x16419 + 1;
    int x16625 = x16421;
    int x16626 = x16420;
    bool x16627 = x16625 == x16626;
    if (x16627) {
      int x16628 = x16626 * 4;
      x16420 = x16628;
      printf("buffer.resize %d\n",x16628);
      int* x16631 = x16423;
      int* x16632 = (int*)realloc(x16631,x16628 * sizeof(int));
      x16423 = x16632;
      int* x16640 = x16429;
      int* x16641 = (int*)realloc(x16640,x16628 * sizeof(int));
      x16429 = x16641;
    } else {
    }
    int* x16654 = x16423;
    x16654[x16625] = x16462;
    int* x16660 = x16429;
    x16660[x16625] = x16522;
    x16421 = x16421 + 1;
  }
  int x16671 = 0;
  int x16672 = 1048576;
  int x16673 = 0;
  int* x16674 = (int*)malloc(1048576 * sizeof(int));
  int* x16675 = x16674;
  int* x16676 = (int*)malloc(1048576 * sizeof(int));
  int* x16677 = x16676;
  int* x16678 = (int*)malloc(1048576 * sizeof(int));
  int* x16679 = x16678;
  double* x16682 = (double*)malloc(1048576 * sizeof(double));
  double* x16683 = x16682;
  double* x16684 = (double*)malloc(1048576 * sizeof(double));
  double* x16685 = x16684;
  double* x16686 = (double*)malloc(1048576 * sizeof(double));
  double* x16687 = x16686;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  int x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    int x16706 = x16671;
    bool x16707 = x16706 < x3;
    if (!x16707) break;
    int x16710 = 0;
    for (;;) {
      int x16711 = x16671;
      char x16712 = x4[x16711];
      bool x16713 = x16712 != '|';
      bool x16718 = x16713;
      if (x16713) {
        int x16714 = x16671;
        char x16715 = x4[x16714];
        bool x16716 = x16715 != '\n';
        x16718 = x16716;
      }
      bool x16719 = x16718;
      if (!x16719) break;
      int x16721 = x16710;
      int x16723 = x16671;
      int x16722 = x16721 * 10;
      char x16724 = x4[x16723];
      char x16725 = x16724 - '0';
      int x16726 = x16722 + x16725;
      x16710 = x16726;
      x16671 = x16671 + 1;
    }
    x16671 = x16671 + 1;
    int x16732 = x16710;
    int x16734 = 0;
    for (;;) {
      int x16735 = x16671;
      char x16736 = x4[x16735];
      bool x16737 = x16736 != '|';
      bool x16742 = x16737;
      if (x16737) {
        int x16738 = x16671;
        char x16739 = x4[x16738];
        bool x16740 = x16739 != '\n';
        x16742 = x16740;
      }
      bool x16743 = x16742;
      if (!x16743) break;
      int x16745 = x16734;
      int x16747 = x16671;
      int x16746 = x16745 * 10;
      char x16748 = x4[x16747];
      char x16749 = x16748 - '0';
      int x16750 = x16746 + x16749;
      x16734 = x16750;
      x16671 = x16671 + 1;
    }
    x16671 = x16671 + 1;
    int x16756 = x16734;
    int x16758 = 0;
    for (;;) {
      int x16759 = x16671;
      char x16760 = x4[x16759];
      bool x16761 = x16760 != '|';
      bool x16766 = x16761;
      if (x16761) {
        int x16762 = x16671;
        char x16763 = x4[x16762];
        bool x16764 = x16763 != '\n';
        x16766 = x16764;
      }
      bool x16767 = x16766;
      if (!x16767) break;
      int x16769 = x16758;
      int x16771 = x16671;
      int x16770 = x16769 * 10;
      char x16772 = x4[x16771];
      char x16773 = x16772 - '0';
      int x16774 = x16770 + x16773;
      x16758 = x16774;
      x16671 = x16671 + 1;
    }
    x16671 = x16671 + 1;
    int x16780 = x16758;
    for (;;) {
      int x16783 = x16671;
      char x16784 = x4[x16783];
      bool x16785 = x16784 != '|';
      bool x16790 = x16785;
      if (x16785) {
        int x16786 = x16671;
        char x16787 = x4[x16786];
        bool x16788 = x16787 != '\n';
        x16790 = x16788;
      }
      bool x16791 = x16790;
      if (!x16791) break;
      x16671 = x16671 + 1;
    }
    x16671 = x16671 + 1;
    int x16806 = 0;
    int x16807 = 1;
    for (;;) {
      int x16808 = x16671;
      char x16809 = x4[x16808];
      bool x16810 = x16809 != '.';
      bool x16815 = x16810;
      if (x16810) {
        int x16811 = x16671;
        char x16812 = x4[x16811];
        bool x16813 = x16812 != '|';
        x16815 = x16813;
      }
      bool x16816 = x16815;
      bool x16821 = x16816;
      if (x16816) {
        int x16817 = x16671;
        char x16818 = x4[x16817];
        bool x16819 = x16818 != '\n';
        x16821 = x16819;
      }
      bool x16822 = x16821;
      if (!x16822) break;
      int x16824 = x16806;
      int x16826 = x16671;
      int x16825 = x16824 * 10;
      char x16827 = x4[x16826];
      char x16828 = x16827 - '0';
      int x16829 = x16825 + x16828;
      x16806 = x16829;
      x16671 = x16671 + 1;
    }
    int x16834 = x16671;
    char x16835 = x4[x16834];
    bool x16836 = x16835 == '.';
    if (x16836) {
      x16671 = x16671 + 1;
      for (;;) {
        int x16838 = x16671;
        char x16839 = x4[x16838];
        bool x16840 = x16839 != '|';
        bool x16845 = x16840;
        if (x16840) {
          int x16841 = x16671;
          char x16842 = x4[x16841];
          bool x16843 = x16842 != '\n';
          x16845 = x16843;
        }
        bool x16846 = x16845;
        if (!x16846) break;
        int x16848 = x16806;
        int x16850 = x16671;
        int x16849 = x16848 * 10;
        char x16851 = x4[x16850];
        char x16852 = x16851 - '0';
        int x16853 = x16849 + x16852;
        x16806 = x16853;
        int x16855 = x16807;
        int x16856 = x16855 * 10;
        x16807 = x16856;
        x16671 = x16671 + 1;
      }
    } else {
    }
    x16671 = x16671 + 1;
    int x16865 = x16806;
    int x16867 = x16807;
    int x16871 = 0;
    int x16872 = 1;
    for (;;) {
      int x16873 = x16671;
      char x16874 = x4[x16873];
      bool x16875 = x16874 != '.';
      bool x16880 = x16875;
      if (x16875) {
        int x16876 = x16671;
        char x16877 = x4[x16876];
        bool x16878 = x16877 != '|';
        x16880 = x16878;
      }
      bool x16881 = x16880;
      bool x16886 = x16881;
      if (x16881) {
        int x16882 = x16671;
        char x16883 = x4[x16882];
        bool x16884 = x16883 != '\n';
        x16886 = x16884;
      }
      bool x16887 = x16886;
      if (!x16887) break;
      int x16889 = x16871;
      int x16891 = x16671;
      int x16890 = x16889 * 10;
      char x16892 = x4[x16891];
      char x16893 = x16892 - '0';
      int x16894 = x16890 + x16893;
      x16871 = x16894;
      x16671 = x16671 + 1;
    }
    int x16899 = x16671;
    char x16900 = x4[x16899];
    bool x16901 = x16900 == '.';
    if (x16901) {
      x16671 = x16671 + 1;
      for (;;) {
        int x16903 = x16671;
        char x16904 = x4[x16903];
        bool x16905 = x16904 != '|';
        bool x16910 = x16905;
        if (x16905) {
          int x16906 = x16671;
          char x16907 = x4[x16906];
          bool x16908 = x16907 != '\n';
          x16910 = x16908;
        }
        bool x16911 = x16910;
        if (!x16911) break;
        int x16913 = x16871;
        int x16915 = x16671;
        int x16914 = x16913 * 10;
        char x16916 = x4[x16915];
        char x16917 = x16916 - '0';
        int x16918 = x16914 + x16917;
        x16871 = x16918;
        int x16920 = x16872;
        int x16921 = x16920 * 10;
        x16872 = x16921;
        x16671 = x16671 + 1;
      }
    } else {
    }
    x16671 = x16671 + 1;
    int x16930 = x16871;
    int x16932 = x16872;
    int x16936 = 0;
    int x16937 = 1;
    for (;;) {
      int x16938 = x16671;
      char x16939 = x4[x16938];
      bool x16940 = x16939 != '.';
      bool x16945 = x16940;
      if (x16940) {
        int x16941 = x16671;
        char x16942 = x4[x16941];
        bool x16943 = x16942 != '|';
        x16945 = x16943;
      }
      bool x16946 = x16945;
      bool x16951 = x16946;
      if (x16946) {
        int x16947 = x16671;
        char x16948 = x4[x16947];
        bool x16949 = x16948 != '\n';
        x16951 = x16949;
      }
      bool x16952 = x16951;
      if (!x16952) break;
      int x16954 = x16936;
      int x16956 = x16671;
      int x16955 = x16954 * 10;
      char x16957 = x4[x16956];
      char x16958 = x16957 - '0';
      int x16959 = x16955 + x16958;
      x16936 = x16959;
      x16671 = x16671 + 1;
    }
    int x16964 = x16671;
    char x16965 = x4[x16964];
    bool x16966 = x16965 == '.';
    if (x16966) {
      x16671 = x16671 + 1;
      for (;;) {
        int x16968 = x16671;
        char x16969 = x4[x16968];
        bool x16970 = x16969 != '|';
        bool x16975 = x16970;
        if (x16970) {
          int x16971 = x16671;
          char x16972 = x4[x16971];
          bool x16973 = x16972 != '\n';
          x16975 = x16973;
        }
        bool x16976 = x16975;
        if (!x16976) break;
        int x16978 = x16936;
        int x16980 = x16671;
        int x16979 = x16978 * 10;
        char x16981 = x4[x16980];
        char x16982 = x16981 - '0';
        int x16983 = x16979 + x16982;
        x16936 = x16983;
        int x16985 = x16937;
        int x16986 = x16985 * 10;
        x16937 = x16986;
        x16671 = x16671 + 1;
      }
    } else {
    }
    x16671 = x16671 + 1;
    int x16995 = x16936;
    int x16997 = x16937;
    for (;;) {
      int x17003 = x16671;
      char x17004 = x4[x17003];
      bool x17005 = x17004 != '.';
      bool x17010 = x17005;
      if (x17005) {
        int x17006 = x16671;
        char x17007 = x4[x17006];
        bool x17008 = x17007 != '|';
        x17010 = x17008;
      }
      bool x17011 = x17010;
      bool x17016 = x17011;
      if (x17011) {
        int x17012 = x16671;
        char x17013 = x4[x17012];
        bool x17014 = x17013 != '\n';
        x17016 = x17014;
      }
      bool x17017 = x17016;
      if (!x17017) break;
      x16671 = x16671 + 1;
    }
    int x17029 = x16671;
    char x17030 = x4[x17029];
    bool x17031 = x17030 == '.';
    if (x17031) {
      x16671 = x16671 + 1;
      for (;;) {
        int x17033 = x16671;
        char x17034 = x4[x17033];
        bool x17035 = x17034 != '|';
        bool x17040 = x17035;
        if (x17035) {
          int x17036 = x16671;
          char x17037 = x4[x17036];
          bool x17038 = x17037 != '\n';
          x17040 = x17038;
        }
        bool x17041 = x17040;
        if (!x17041) break;
        x16671 = x16671 + 1;
      }
    } else {
    }
    x16671 = x16671 + 1;
    x16671 = x16671 + 2;
    x16671 = x16671 + 2;
    for (;;) {
      int x17073 = x16671;
      char x17074 = x4[x17073];
      bool x17075 = x17074 != '-';
      bool x17080 = x17075;
      if (x17075) {
        int x17076 = x16671;
        char x17077 = x4[x17076];
        bool x17078 = x17077 != '\n';
        x17080 = x17078;
      }
      bool x17081 = x17080;
      if (!x17081) break;
      x16671 = x16671 + 1;
    }
    x16671 = x16671 + 1;
    for (;;) {
      int x17097 = x16671;
      char x17098 = x4[x17097];
      bool x17099 = x17098 != '-';
      bool x17104 = x17099;
      if (x17099) {
        int x17100 = x16671;
        char x17101 = x4[x17100];
        bool x17102 = x17101 != '\n';
        x17104 = x17102;
      }
      bool x17105 = x17104;
      if (!x17105) break;
      x16671 = x16671 + 1;
    }
    x16671 = x16671 + 1;
    for (;;) {
      int x17121 = x16671;
      char x17122 = x4[x17121];
      bool x17123 = x17122 != '|';
      bool x17128 = x17123;
      if (x17123) {
        int x17124 = x16671;
        char x17125 = x4[x17124];
        bool x17126 = x17125 != '\n';
        x17128 = x17126;
      }
      bool x17129 = x17128;
      if (!x17129) break;
      x16671 = x16671 + 1;
    }
    x16671 = x16671 + 1;
    for (;;) {
      int x17149 = x16671;
      char x17150 = x4[x17149];
      bool x17151 = x17150 != '-';
      bool x17156 = x17151;
      if (x17151) {
        int x17152 = x16671;
        char x17153 = x4[x17152];
        bool x17154 = x17153 != '\n';
        x17156 = x17154;
      }
      bool x17157 = x17156;
      if (!x17157) break;
      x16671 = x16671 + 1;
    }
    x16671 = x16671 + 1;
    for (;;) {
      int x17173 = x16671;
      char x17174 = x4[x17173];
      bool x17175 = x17174 != '-';
      bool x17180 = x17175;
      if (x17175) {
        int x17176 = x16671;
        char x17177 = x4[x17176];
        bool x17178 = x17177 != '\n';
        x17180 = x17178;
      }
      bool x17181 = x17180;
      if (!x17181) break;
      x16671 = x16671 + 1;
    }
    x16671 = x16671 + 1;
    for (;;) {
      int x17197 = x16671;
      char x17198 = x4[x17197];
      bool x17199 = x17198 != '|';
      bool x17204 = x17199;
      if (x17199) {
        int x17200 = x16671;
        char x17201 = x4[x17200];
        bool x17202 = x17201 != '\n';
        x17204 = x17202;
      }
      bool x17205 = x17204;
      if (!x17205) break;
      x16671 = x16671 + 1;
    }
    x16671 = x16671 + 1;
    for (;;) {
      int x17225 = x16671;
      char x17226 = x4[x17225];
      bool x17227 = x17226 != '-';
      bool x17232 = x17227;
      if (x17227) {
        int x17228 = x16671;
        char x17229 = x4[x17228];
        bool x17230 = x17229 != '\n';
        x17232 = x17230;
      }
      bool x17233 = x17232;
      if (!x17233) break;
      x16671 = x16671 + 1;
    }
    x16671 = x16671 + 1;
    for (;;) {
      int x17249 = x16671;
      char x17250 = x4[x17249];
      bool x17251 = x17250 != '-';
      bool x17256 = x17251;
      if (x17251) {
        int x17252 = x16671;
        char x17253 = x4[x17252];
        bool x17254 = x17253 != '\n';
        x17256 = x17254;
      }
      bool x17257 = x17256;
      if (!x17257) break;
      x16671 = x16671 + 1;
    }
    x16671 = x16671 + 1;
    for (;;) {
      int x17273 = x16671;
      char x17274 = x4[x17273];
      bool x17275 = x17274 != '|';
      bool x17280 = x17275;
      if (x17275) {
        int x17276 = x16671;
        char x17277 = x4[x17276];
        bool x17278 = x17277 != '\n';
        x17280 = x17278;
      }
      bool x17281 = x17280;
      if (!x17281) break;
      x16671 = x16671 + 1;
    }
    x16671 = x16671 + 1;
    for (;;) {
      int x17300 = x16671;
      char x17301 = x4[x17300];
      bool x17302 = x17301 != '|';
      bool x17307 = x17302;
      if (x17302) {
        int x17303 = x16671;
        char x17304 = x4[x17303];
        bool x17305 = x17304 != '\n';
        x17307 = x17305;
      }
      bool x17308 = x17307;
      if (!x17308) break;
      x16671 = x16671 + 1;
    }
    x16671 = x16671 + 1;
    for (;;) {
      int x17318 = x16671;
      char x17319 = x4[x17318];
      bool x17320 = x17319 != '|';
      bool x17325 = x17320;
      if (x17320) {
        int x17321 = x16671;
        char x17322 = x4[x17321];
        bool x17323 = x17322 != '\n';
        x17325 = x17323;
      }
      bool x17326 = x17325;
      if (!x17326) break;
      x16671 = x16671 + 1;
    }
    x16671 = x16671 + 1;
    for (;;) {
      int x17336 = x16671;
      char x17337 = x4[x17336];
      bool x17338 = x17337 != '|';
      bool x17343 = x17338;
      if (x17338) {
        int x17339 = x16671;
        char x17340 = x4[x17339];
        bool x17341 = x17340 != '\n';
        x17343 = x17341;
      }
      bool x17344 = x17343;
      if (!x17344) break;
      x16671 = x16671 + 1;
    }
    x16671 = x16671 + 1;
    int x17354 = x16673;
    int x17355 = x16672;
    bool x17356 = x17354 == x17355;
    if (x17356) {
      int x17357 = x17355 * 4;
      x16672 = x17357;
      printf("buffer.resize %d\n",x17357);
      int* x17360 = x16675;
      int* x17361 = (int*)realloc(x17360,x17357 * sizeof(int));
      x16675 = x17361;
      int* x17363 = x16677;
      int* x17364 = (int*)realloc(x17363,x17357 * sizeof(int));
      x16677 = x17364;
      int* x17366 = x16679;
      int* x17367 = (int*)realloc(x17366,x17357 * sizeof(int));
      x16679 = x17367;
      double* x17372 = x16683;
      double* x17373 = (double*)realloc(x17372,x17357 * sizeof(double));
      x16683 = x17373;
      double* x17375 = x16685;
      double* x17376 = (double*)realloc(x17375,x17357 * sizeof(double));
      x16685 = x17376;
      double* x17378 = x16687;
      double* x17379 = (double*)realloc(x17378,x17357 * sizeof(double));
      x16687 = x17379;
    } else {
    }
    int* x17410 = x16675;
    x17410[x17354] = x16732;
    int* x17412 = x16677;
    x17412[x17354] = x16756;
    int* x17414 = x16679;
    x17414[x17354] = x16780;
    double* x17418 = x16683;
    double x16866 = (double)x16865;
    double x16868 = (double)x16867;
    double x16869 = x16866 / x16868;
    x17418[x17354] = x16869;
    double* x17420 = x16685;
    double x16931 = (double)x16930;
    double x16933 = (double)x16932;
    double x16934 = x16931 / x16933;
    x17420[x17354] = x16934;
    double* x17422 = x16687;
    double x16996 = (double)x16995;
    double x16998 = (double)x16997;
    double x16999 = x16996 / x16998;
    x17422[x17354] = x16999;
    x16673 = x16673 + 1;
  }
  bool x972 = true == false;
  int x17445;
  for(x17445=0; x17445 < 5; x17445++) {
    bool x17446 = false;
    int x17447 = 0;
    bool x17448 = false;
    int x17449 = 0;
    bool x17450 = false;
    int x17451 = 0;
    bool x17452 = false;
    int x17453 = 0;
    bool x17455 = false;
    int x17456 = 0;
    bool x17457 = false;
    int x17458 = 0;
    int* x17460 = (int*)malloc(134217728 * sizeof(int));
    int* x17461 = x17460;
    char** x17462 = (char**)malloc(134217728 * sizeof(char*));
    char** x17463 = x17462;
    int x17468 = 0;
    int* x17469 = (int*)malloc(67108864 * sizeof(int));
    int* x17470 = (int*)malloc(134217728 * sizeof(int));
    int x17471;
    for(x17471=0; x17471 < 67108864; x17471++) {
      x17469[x17471] = -1;
    }
    char** x17479 = (char**)malloc(134217728 * sizeof(char*));
    char** x17480 = x17479;
    int* x17485 = (int*)malloc(134217728 * sizeof(int));
    int* x17486 = x17485;
    int x17499 = 0;
    int* x17500 = (int*)malloc(67108864 * sizeof(int));
    int* x17501 = (int*)malloc(134217728 * sizeof(int));
    int x17502;
    for(x17502=0; x17502 < 67108864; x17502++) {
      x17500[x17502] = -1;
    }
    int* x17508 = (int*)malloc(134217728 * sizeof(int));
    int* x17509 = x17508;
    int x17526 = 0;
    int* x17527 = (int*)malloc(67108864 * sizeof(int));
    int* x17528 = (int*)malloc(134217728 * sizeof(int));
    int x17529;
    for(x17529=0; x17529 < 67108864; x17529++) {
      x17527[x17529] = -1;
    }
    int* x17535 = (int*)malloc(134217728 * sizeof(int));
    int* x17536 = x17535;
    int* x17537 = (int*)malloc(134217728 * sizeof(int));
    int* x17538 = x17537;
    double* x17541 = (double*)malloc(134217728 * sizeof(double));
    double* x17542 = x17541;
    int x17545 = 0;
    int* x17546 = (int*)malloc(67108864 * sizeof(int));
    int* x17547 = (int*)malloc(134217728 * sizeof(int));
    int x17548;
    for(x17548=0; x17548 < 67108864; x17548++) {
      x17546[x17548] = -1;
    }
    double* x17560 = (double*)malloc(134217728 * sizeof(double));
    double* x17561 = x17560;
    char** x17584 = (char**)malloc(134217728 * sizeof(char*));
    char** x17585 = x17584;
    int* x17604 = (int*)malloc(134217728 * sizeof(int));
    int* x17605 = x17604;
    double* x17612 = (double*)malloc(134217728 * sizeof(double));
    double* x17613 = x17612;
    double* x17614 = (double*)malloc(134217728 * sizeof(double));
    double* x17615 = x17614;
    double* x17616 = (double*)malloc(134217728 * sizeof(double));
    double* x17617 = x17616;
    int x17636 = 0;
    int* x17637 = (int*)malloc(67108864 * sizeof(int));
    int* x17638 = (int*)malloc(134217728 * sizeof(int));
    int x17639;
    for(x17639=0; x17639 < 67108864; x17639++) {
      x17637[x17639] = -1;
    }
    struct Anon2071559637* x17645 = (struct Anon2071559637*)malloc(16777216 * sizeof(struct Anon2071559637));
    struct Anon2071559637* x17646 = x17645;
    int x17647 = 0;
    int* x17648 = (int*)malloc(16777216 * sizeof(int));
    int x17649;
    for(x17649=0; x17649 < 16777216; x17649++) {
      struct Anon2071559637* x17650 = x17646;
      struct Anon2071559637 x17651 = x17650[x17649];
      struct Anon1548200872 x17652 = x17651.key;;
      struct Anon2052879266 x17653 = x17651.aggs;;
      struct Anon2071559637 x17654;
      x17654.exists = false;
      x17654.key = x17652;
      x17654.aggs = x17653;
      x17650[x17649] = x17654;
    }
    int x17659 = 0;
    struct timeval x18371, x18372, x18373;
    gettimeofday(&x18371, NULL);
    printf("%s\n","begin scan PARTSUPP");
    for (;;) {
      bool x17661 = x17455;
      bool x17662 = !x17661;
      bool x17667 = x17662;
      if (x17662) {
        int x17663 = x17456;
        int x17664 = x16213;
        bool x17665 = x17663 < x17664;
        x17667 = x17665;
      }
      bool x17668 = x17667;
      if (!x17668) break;
      int x17670 = x17456;
      int* x17671 = x16215;
      int x17672 = x17671[x17670];
      int* x17673 = x16217;
      int x17674 = x17673[x17670];
      double* x17677 = x16221;
      double x17678 = x17677[x17670];
      x17456 = x17456 + 1;
      int x17683 = x17545;
      int* x17684 = x17536;
      x17684[x17683] = x17672;
      int* x17686 = x17538;
      x17686[x17683] = x17674;
      double* x17690 = x17542;
      x17690[x17683] = x17678;
      x17545 = x17545 + 1;
      int x17695 = x17672 & 67108863;
      int x17696 = x17546[x17695];
      x17546[x17695] = x17683;
      x17547[x17683] = x17696;
    }
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x17702 = x17452;
      bool x17703 = !x17702;
      bool x17708 = x17703;
      if (x17703) {
        int x17704 = x17453;
        int x17705 = x15429;
        bool x17706 = x17704 < x17705;
        x17708 = x17706;
      }
      bool x17709 = x17708;
      if (!x17709) break;
      int x17711 = x17453;
      int* x17712 = x15431;
      int x17713 = x17712[x17711];
      char** x17714 = x15433;
      char* x17715 = x17714[x17711];
      x17453 = x17453 + 1;
      bool x17732 = strstr(x17715,"ghost") != NULL;
      if (x17732) {
        int x17733 = x17526;
        int* x17734 = x17509;
        x17734[x17733] = x17713;
        x17526 = x17526 + 1;
        int x17753 = x17713 & 67108863;
        int x17754 = x17527[x17753];
        x17527[x17753] = x17733;
        x17528[x17733] = x17754;
      } else {
      }
    }
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x17762 = x17446;
      bool x17763 = !x17762;
      bool x17768 = x17763;
      if (x17763) {
        int x17764 = x17447;
        int x17765 = x15732;
        bool x17766 = x17764 < x17765;
        x17768 = x17766;
      }
      bool x17769 = x17768;
      if (!x17769) break;
      int x17771 = x17447;
      int* x17772 = x15734;
      int x17773 = x17772[x17771];
      char** x17774 = x15736;
      char* x17775 = x17774[x17771];
      x17447 = x17447 + 1;
      int x17782 = x17468;
      int* x17783 = x17461;
      x17783[x17782] = x17773;
      char** x17785 = x17463;
      x17785[x17782] = x17775;
      x17468 = x17468 + 1;
      int x17792 = x17773 & 67108863;
      int x17793 = x17469[x17792];
      x17469[x17792] = x17782;
      x17470[x17782] = x17793;
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x17799 = x17448;
      bool x17800 = !x17799;
      bool x17805 = x17800;
      if (x17800) {
        int x17801 = x17449;
        int x17802 = x16421;
        bool x17803 = x17801 < x17802;
        x17805 = x17803;
      }
      bool x17806 = x17805;
      if (!x17806) break;
      int x17808 = x17449;
      int* x17809 = x16423;
      int x17810 = x17809[x17808];
      int* x17815 = x16429;
      int x17816 = x17815[x17808];
      x17449 = x17449 + 1;
      int x17825 = x17816 & 67108863;
      int x17826 = x17469[x17825];
      int x17827 = x17826;
      int x17871 = x17810 & 67108863;
      for (;;) {
        int x17828 = x17827;
        bool x17829 = x17828 != -1;
        if (!x17829) break;
        int x17831 = x17827;
        int* x17832 = x17461;
        int x17833 = x17832[x17831];
        char** x17834 = x17463;
        char* x17835 = x17834[x17831];
        int x17841 = x17470[x17831];
        x17827 = x17841;
        bool x17843 = x17833 == x17816;
        if (x17843) {
          int x17847 = x17499;
          char** x17850 = x17480;
          x17850[x17847] = x17835;
          int* x17856 = x17486;
          x17856[x17847] = x17810;
          x17499 = x17499 + 1;
          int x17872 = x17500[x17871];
          x17500[x17871] = x17847;
          x17501[x17847] = x17872;
        } else {
        }
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x17882 = x17450;
      bool x17883 = !x17882;
      bool x17888 = x17883;
      if (x17883) {
        int x17884 = x17451;
        int x17885 = x16673;
        bool x17886 = x17884 < x17885;
        x17888 = x17886;
      }
      bool x17889 = x17888;
      if (!x17889) break;
      int x17891 = x17451;
      int* x17892 = x16675;
      int x17893 = x17892[x17891];
      int* x17894 = x16677;
      int x17895 = x17894[x17891];
      int* x17896 = x16679;
      int x17897 = x17896[x17891];
      double* x17900 = x16683;
      double x17901 = x17900[x17891];
      double* x17902 = x16685;
      double x17903 = x17902[x17891];
      double* x17904 = x16687;
      double x17905 = x17904[x17891];
      x17451 = x17451 + 1;
      int x17926 = x17897 & 67108863;
      int x17927 = x17500[x17926];
      int x17928 = x17927;
      int x17962 = x17895 & 67108863;
      int x18104 = x17893 & 67108863;
      for (;;) {
        int x17929 = x17928;
        bool x17930 = x17929 != -1;
        if (!x17930) break;
        int x17932 = x17928;
        char** x17935 = x17480;
        char* x17936 = x17935[x17932];
        int* x17941 = x17486;
        int x17942 = x17941[x17932];
        int x17956 = x17501[x17932];
        x17928 = x17956;
        bool x17958 = x17942 == x17897;
        if (x17958) {
          int x17963 = x17527[x17962];
          int x17964 = x17963;
          for (;;) {
            int x17965 = x17964;
            bool x17966 = x17965 != -1;
            if (!x17966) break;
            int x17968 = x17964;
            int* x17969 = x17509;
            int x17970 = x17969[x17968];
            int x17988 = x17528[x17968];
            x17964 = x17988;
            bool x17990 = x17970 == x17895;
            if (x17990) {
              int x17994 = x17546[x17962];
              int x17995 = x17994;
              for (;;) {
                int x17996 = x17995;
                bool x17997 = x17996 != -1;
                if (!x17997) break;
                int x17999 = x17995;
                int* x18000 = x17536;
                int x18001 = x18000[x17999];
                int* x18002 = x17538;
                int x18003 = x18002[x17999];
                double* x18006 = x17542;
                double x18007 = x18006[x17999];
                int x18011 = x17547[x17999];
                x17995 = x18011;
                bool x18013 = x18001 == x17895;
                bool x18015 = x18013;
                if (x18013) {
                  bool x18014 = x18003 == x17897;
                  x18015 = x18014;
                }
                bool x18016 = x18015;
                if (x18016) {
                  int x18020 = x17636;
                  double* x18027 = x17561;
                  x18027[x18020] = x18007;
                  char** x18051 = x17585;
                  x18051[x18020] = x17936;
                  int* x18071 = x17605;
                  x18071[x18020] = x17893;
                  double* x18079 = x17613;
                  x18079[x18020] = x17901;
                  double* x18081 = x17615;
                  x18081[x18020] = x17903;
                  double* x18083 = x17617;
                  x18083[x18020] = x17905;
                  x17636 = x17636 + 1;
                  int x18105 = x17637[x18104];
                  x17637[x18104] = x18020;
                  x17638[x18020] = x18105;
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
      bool x18123 = x17457;
      bool x18124 = !x18123;
      bool x18129 = x18124;
      if (x18124) {
        int x18125 = x17458;
        int x18126 = x15862;
        bool x18127 = x18125 < x18126;
        x18129 = x18127;
      }
      bool x18130 = x18129;
      if (!x18130) break;
      int x18132 = x17458;
      int* x18133 = x15864;
      int x18134 = x18133[x18132];
      long* x18141 = x15872;
      long x18142 = x18141[x18132];
      x17458 = x17458 + 1;
      int x18153 = x18134 & 67108863;
      int x18154 = x17637[x18153];
      int x18155 = x18154;
      long x18249 = x18142; // date
      long x18250 = x18249/10000;
      int x18251 = (int)x18250;
      for (;;) {
        int x18156 = x18155;
        bool x18157 = x18156 != -1;
        if (!x18157) break;
        int x18159 = x18155;
        double* x18166 = x17561;
        double x18167 = x18166[x18159];
        char** x18190 = x17585;
        char* x18191 = x18190[x18159];
        int* x18210 = x17605;
        int x18211 = x18210[x18159];
        double* x18218 = x17613;
        double x18219 = x18218[x18159];
        double* x18220 = x17615;
        double x18221 = x18220[x18159];
        double* x18222 = x17617;
        double x18223 = x18222[x18159];
        int x18243 = x17638[x18159];
        x18155 = x18243;
        bool x18245 = x18211 == x18134;
        if (x18245) {
          char x18253 = x18191[0];
          int x18254 = x18253 * 41;
          char x18255 = x18191[1];
          int x18256 = x18254 + x18255;
          int x18257 = x18256 * 41;
          char x18258 = x18191[2];
          int x18259 = x18257 + x18258;
          int x18260 = x18259 * 41;
          char x18261 = x18191[3];
          int x18262 = x18260 + x18261;
          int x18263 = x18262 * 41;
          int x18264 = x18263 + x18251;
          int x18265 = x18264 & 16777215;
          int x18266 = x18265;
          struct Anon2071559637* x18267 = x17646;
          struct Anon2071559637 x18268 = x18267[x18265];
          struct Anon2071559637 x18269 = x18268;
          bool x18270 = x18268.exists;;
          bool x18280 = x18270;
          if (x18270) {
            struct Anon2071559637 x18271 = x18269;
            struct Anon1548200872 x18272 = x18271.key;;
            char* x18273 = x18272.NATION;;
            bool x18274 = strcmp(x18273,x18191) == 0;;
            bool x18277 = x18274;
            if (x18274) {
              int x18275 = x18272.O_YEAR;;
              bool x18276 = x18275 == x18251;
              x18277 = x18276;
            }
            bool x18278 = x18277;
            x18280 = x18278;
          }
          bool x18281 = x18280;
          if (x18281) {
            struct Anon2052879266 x18282 = x18268.aggs;;
            struct Anon1548200872 x18290 = x18268.key;;
            double x18283 = x18282._0;;
            double x18284 = 1.0 - x18223;
            double x18285 = x18221 * x18284;
            double x18286 = x18167 * x18219;
            double x18287 = x18285 - x18286;
            double x18288 = x18283 + x18287;
            struct Anon2052879266 x18289;
            x18289._0 = x18288;
            struct Anon2071559637 x18291;
            x18291.exists = true;
            x18291.key = x18290;
            x18291.aggs = x18289;
            x18267[x18265] = x18291;
          } else {
            double x18284 = 1.0 - x18223;
            double x18285 = x18221 * x18284;
            double x18286 = x18167 * x18219;
            double x18287 = x18285 - x18286;
            struct Anon1548200872 x18252;
            x18252.NATION = x18191;
            x18252.O_YEAR = x18251;
            struct Anon2052879266 x18325;
            x18325._0 = x18287;
            struct Anon2071559637 x18326;
            x18326.exists = true;
            x18326.key = x18252;
            x18326.aggs = x18325;
            for (;;) {
              struct Anon2071559637 x18294 = x18269;
              bool x18295 = x18294.exists;;
              bool x18335;
              if (x18295) {
                struct Anon1548200872 x18296 = x18294.key;;
                char* x18297 = x18296.NATION;;
                bool x18298 = strcmp(x18297,x18191) == 0;;
                bool x18301 = x18298;
                if (x18298) {
                  int x18299 = x18296.O_YEAR;;
                  bool x18300 = x18299 == x18251;
                  x18301 = x18300;
                }
                bool x18302 = x18301;
                bool x18322;
                if (x18302) {
                  struct Anon2052879266 x18303 = x18294.aggs;;
                  int x18307 = x18266;
                  struct Anon2071559637* x18309 = x17646;
                  double x18304 = x18303._0;;
                  double x18305 = x18304 + x18287;
                  struct Anon2052879266 x18306;
                  x18306._0 = x18305;
                  struct Anon2071559637 x18308;
                  x18308.exists = true;
                  x18308.key = x18296;
                  x18308.aggs = x18306;
                  x18309[x18307] = x18308;
                  x18322 = false;
                } else {
                  int x18312 = x18266;
                  int x18313 = x18312 + 1;
                  int x18314 = x18313 % 16777215;
                  x18266 = x18314;
                  struct Anon2071559637* x18316 = x17646;
                  struct Anon2071559637 x18317 = x18316[x18314];
                  x18269 = x18317;
                  x18322 = true;
                }
                x18335 = x18322;
              } else {
                int x18324 = x18266;
                struct Anon2071559637* x18327 = x17646;
                x18327[x18324] = x18326;
                int x18329 = x17647;
                x17648[x18329] = x18324;
                x17647 = x17647 + 1;
                x18335 = false;
              }
              if (!x18335) break;
            }
          }
        } else {
        }
      }
    }
    int x18348 = x17647;
    int x18350;
    for(x18350=0; x18350 < x18348; x18350++) {
      int x18351 = x17648[x18350];
      struct Anon2071559637* x18352 = x17646;
      struct Anon2071559637 x18353 = x18352[x18351];
      if (x972) {
      } else {
        struct Anon1548200872 x18356 = x18353.key;;
        struct Anon2052879266 x18360 = x18353.aggs;;
        char* x18357 = x18356.NATION;;
        int x18358 = strlen(x18357);
        int x18359 = x18356.O_YEAR;;
        double x18361 = x18360._0;;
        printf("%.*s|%d|%.4f\n",x18358,x18357,x18359,x18361);
        x17659 = x17659 + 1;
      }
    }
    int x18368 = x17659;
    printf("(%d rows)\n",x18368);
    gettimeofday(&x18372, NULL);
    timeval_subtract(&x18373, &x18372, &x18371);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x18373.tv_sec * 1000) + (x18373.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
