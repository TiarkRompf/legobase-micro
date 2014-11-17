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

struct Anon1078540535 {
char* N_NAME;
int N_NATIONKEY;
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

struct Anon1251919804 {
long REC2_O_ORDERDATE;
double REC2_L_DISCOUNT;
double REC2_L_EXTENDEDPRICE;
int REC2_S_NATIONKEY;
};

struct Anon0 {
struct Anon850505655 left;
struct Anon1251919804 right;
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

struct Anon801061462 {
bool exists;
char* key;
struct Anon2052879266 aggs;
};

/************************ FUNCTIONS **************************/

/************************ MAIN BODY **************************/
int main(int x12105, char** x12106) {
  long x12107 = 0L;
  long x6 = DEFAULT_INPUT_SIZE;
  long x12108 = x6;
  long x12109 = 0L;
  int* x12110 = (int*)malloc(x6 * sizeof(int));
  int* x12111 = x12110;
  char** x12112 = (char**)malloc(x6 * sizeof(char*));
  char** x12113 = x12112;
  int* x12114 = (int*)malloc(x6 * sizeof(int));
  int* x12115 = x12114;
  int x1515 = open("../databases/sf2/nation.tbl",0);
  long x1516 = fsize(x1515);
  char* x1517 = mmap(0, x1516, PROT_READ, MAP_FILE | MAP_SHARED, x1515, 0);
  for (;;) {
    long x12118 = x12107;
    bool x12119 = x12118 < x1516;
    if (!x12119) break;
    int x12122 = 0;
    for (;;) {
      long x12123 = x12107;
      char x12124 = x1517[x12123];
      bool x12125 = x12124 != '|';
      bool x12130 = x12125;
      if (x12125) {
        long x12126 = x12107;
        char x12127 = x1517[x12126];
        bool x12128 = x12127 != '\n';
        x12130 = x12128;
      }
      bool x12131 = x12130;
      if (!x12131) break;
      int x12133 = x12122;
      long x12135 = x12107;
      int x12134 = x12133 * 10;
      char x12136 = x1517[x12135];
      char x12137 = x12136 - '0';
      int x12138 = x12134 + x12137;
      x12122 = x12138;
      x12107 = x12107 + 1;
    }
    x12107 = x12107 + 1;
    int x12144 = x12122;
    long x12145 = x12107;
    for (;;) {
      long x12146 = x12107;
      char x12147 = x1517[x12146];
      bool x12148 = x12147 != '|';
      bool x12153 = x12148;
      if (x12148) {
        long x12149 = x12107;
        char x12150 = x1517[x12149];
        bool x12151 = x12150 != '\n';
        x12153 = x12151;
      }
      bool x12154 = x12153;
      if (!x12154) break;
      x12107 = x12107 + 1;
    }
    x12107 = x12107 + 1;
    int x12164 = 0;
    for (;;) {
      long x12165 = x12107;
      char x12166 = x1517[x12165];
      bool x12167 = x12166 != '|';
      bool x12172 = x12167;
      if (x12167) {
        long x12168 = x12107;
        char x12169 = x1517[x12168];
        bool x12170 = x12169 != '\n';
        x12172 = x12170;
      }
      bool x12173 = x12172;
      if (!x12173) break;
      int x12175 = x12164;
      long x12177 = x12107;
      int x12176 = x12175 * 10;
      char x12178 = x1517[x12177];
      char x12179 = x12178 - '0';
      int x12180 = x12176 + x12179;
      x12164 = x12180;
      x12107 = x12107 + 1;
    }
    x12107 = x12107 + 1;
    int x12186 = x12164;
    for (;;) {
      long x12188 = x12107;
      char x12189 = x1517[x12188];
      bool x12190 = x12189 != '|';
      bool x12195 = x12190;
      if (x12190) {
        long x12191 = x12107;
        char x12192 = x1517[x12191];
        bool x12193 = x12192 != '\n';
        x12195 = x12193;
      }
      bool x12196 = x12195;
      if (!x12196) break;
      x12107 = x12107 + 1;
    }
    x12107 = x12107 + 1;
    long x12206 = x12109;
    long x12207 = x12108;
    bool x12208 = x12206 == x12207;
    if (x12208) {
      long x12209 = x12207 * 4L;
      x12108 = x12209;
      printf("buffer.resize %d\n",x12209);
      int* x12212 = x12111;
      int* x12213 = (int*)realloc(x12212,x12209 * sizeof(int));
      x12111 = x12213;
      char** x12215 = x12113;
      char** x12216 = (char**)realloc(x12215,x12209 * sizeof(char*));
      x12113 = x12216;
      int* x12218 = x12115;
      int* x12219 = (int*)realloc(x12218,x12209 * sizeof(int));
      x12115 = x12219;
    } else {
    }
    int* x12226 = x12111;
    x12226[x12206] = x12144;
    char** x12228 = x12113;
    char* x12162 = x1517+x12145;
    x12228[x12206] = x12162;
    int* x12230 = x12115;
    x12230[x12206] = x12186;
    x12109 = x12109 + 1;
  }
  long x12237 = 0L;
  long x12238 = x6;
  long x12239 = 0L;
  int* x12240 = (int*)malloc(x6 * sizeof(int));
  int* x12241 = x12240;
  char** x12242 = (char**)malloc(x6 * sizeof(char*));
  char** x12243 = x12242;
  int x1648 = open("../databases/sf2/region.tbl",0);
  long x1649 = fsize(x1648);
  char* x1650 = mmap(0, x1649, PROT_READ, MAP_FILE | MAP_SHARED, x1648, 0);
  for (;;) {
    long x12246 = x12237;
    bool x12247 = x12246 < x1649;
    if (!x12247) break;
    int x12250 = 0;
    for (;;) {
      long x12251 = x12237;
      char x12252 = x1650[x12251];
      bool x12253 = x12252 != '|';
      bool x12258 = x12253;
      if (x12253) {
        long x12254 = x12237;
        char x12255 = x1650[x12254];
        bool x12256 = x12255 != '\n';
        x12258 = x12256;
      }
      bool x12259 = x12258;
      if (!x12259) break;
      int x12261 = x12250;
      long x12263 = x12237;
      int x12262 = x12261 * 10;
      char x12264 = x1650[x12263];
      char x12265 = x12264 - '0';
      int x12266 = x12262 + x12265;
      x12250 = x12266;
      x12237 = x12237 + 1;
    }
    x12237 = x12237 + 1;
    int x12272 = x12250;
    long x12273 = x12237;
    for (;;) {
      long x12274 = x12237;
      char x12275 = x1650[x12274];
      bool x12276 = x12275 != '|';
      bool x12281 = x12276;
      if (x12276) {
        long x12277 = x12237;
        char x12278 = x1650[x12277];
        bool x12279 = x12278 != '\n';
        x12281 = x12279;
      }
      bool x12282 = x12281;
      if (!x12282) break;
      x12237 = x12237 + 1;
    }
    x12237 = x12237 + 1;
    for (;;) {
      long x12292 = x12237;
      char x12293 = x1650[x12292];
      bool x12294 = x12293 != '|';
      bool x12299 = x12294;
      if (x12294) {
        long x12295 = x12237;
        char x12296 = x1650[x12295];
        bool x12297 = x12296 != '\n';
        x12299 = x12297;
      }
      bool x12300 = x12299;
      if (!x12300) break;
      x12237 = x12237 + 1;
    }
    x12237 = x12237 + 1;
    long x12310 = x12239;
    long x12311 = x12238;
    bool x12312 = x12310 == x12311;
    if (x12312) {
      long x12313 = x12311 * 4L;
      x12238 = x12313;
      printf("buffer.resize %d\n",x12313);
      int* x12316 = x12241;
      int* x12317 = (int*)realloc(x12316,x12313 * sizeof(int));
      x12241 = x12317;
      char** x12319 = x12243;
      char** x12320 = (char**)realloc(x12319,x12313 * sizeof(char*));
      x12243 = x12320;
    } else {
    }
    int* x12327 = x12241;
    x12327[x12310] = x12272;
    char** x12329 = x12243;
    char* x12290 = x1650+x12273;
    x12329[x12310] = x12290;
    x12239 = x12239 + 1;
  }
  long x12336 = 0L;
  long x12337 = x6;
  long x12338 = 0L;
  int* x12339 = (int*)malloc(x6 * sizeof(int));
  int* x12340 = x12339;
  char** x12347 = (char**)malloc(x6 * sizeof(char*));
  char** x12348 = x12347;
  int x998 = open("../databases/sf2/part.tbl",0);
  long x999 = fsize(x998);
  char* x1000 = mmap(0, x999, PROT_READ, MAP_FILE | MAP_SHARED, x998, 0);
  for (;;) {
    long x12358 = x12336;
    bool x12359 = x12358 < x999;
    if (!x12359) break;
    int x12362 = 0;
    for (;;) {
      long x12363 = x12336;
      char x12364 = x1000[x12363];
      bool x12365 = x12364 != '|';
      bool x12370 = x12365;
      if (x12365) {
        long x12366 = x12336;
        char x12367 = x1000[x12366];
        bool x12368 = x12367 != '\n';
        x12370 = x12368;
      }
      bool x12371 = x12370;
      if (!x12371) break;
      int x12373 = x12362;
      long x12375 = x12336;
      int x12374 = x12373 * 10;
      char x12376 = x1000[x12375];
      char x12377 = x12376 - '0';
      int x12378 = x12374 + x12377;
      x12362 = x12378;
      x12336 = x12336 + 1;
    }
    x12336 = x12336 + 1;
    int x12384 = x12362;
    for (;;) {
      long x12386 = x12336;
      char x12387 = x1000[x12386];
      bool x12388 = x12387 != '|';
      bool x12393 = x12388;
      if (x12388) {
        long x12389 = x12336;
        char x12390 = x1000[x12389];
        bool x12391 = x12390 != '\n';
        x12393 = x12391;
      }
      bool x12394 = x12393;
      if (!x12394) break;
      x12336 = x12336 + 1;
    }
    x12336 = x12336 + 1;
    for (;;) {
      long x12404 = x12336;
      char x12405 = x1000[x12404];
      bool x12406 = x12405 != '|';
      bool x12411 = x12406;
      if (x12406) {
        long x12407 = x12336;
        char x12408 = x1000[x12407];
        bool x12409 = x12408 != '\n';
        x12411 = x12409;
      }
      bool x12412 = x12411;
      if (!x12412) break;
      x12336 = x12336 + 1;
    }
    x12336 = x12336 + 1;
    for (;;) {
      long x12422 = x12336;
      char x12423 = x1000[x12422];
      bool x12424 = x12423 != '|';
      bool x12429 = x12424;
      if (x12424) {
        long x12425 = x12336;
        char x12426 = x1000[x12425];
        bool x12427 = x12426 != '\n';
        x12429 = x12427;
      }
      bool x12430 = x12429;
      if (!x12430) break;
      x12336 = x12336 + 1;
    }
    x12336 = x12336 + 1;
    long x12439 = x12336;
    for (;;) {
      long x12440 = x12336;
      char x12441 = x1000[x12440];
      bool x12442 = x12441 != '|';
      bool x12447 = x12442;
      if (x12442) {
        long x12443 = x12336;
        char x12444 = x1000[x12443];
        bool x12445 = x12444 != '\n';
        x12447 = x12445;
      }
      bool x12448 = x12447;
      if (!x12448) break;
      x12336 = x12336 + 1;
    }
    x12336 = x12336 + 1;
    for (;;) {
      long x12459 = x12336;
      char x12460 = x1000[x12459];
      bool x12461 = x12460 != '|';
      bool x12466 = x12461;
      if (x12461) {
        long x12462 = x12336;
        char x12463 = x1000[x12462];
        bool x12464 = x12463 != '\n';
        x12466 = x12464;
      }
      bool x12467 = x12466;
      if (!x12467) break;
      x12336 = x12336 + 1;
    }
    x12336 = x12336 + 1;
    for (;;) {
      long x12482 = x12336;
      char x12483 = x1000[x12482];
      bool x12484 = x12483 != '|';
      bool x12489 = x12484;
      if (x12484) {
        long x12485 = x12336;
        char x12486 = x1000[x12485];
        bool x12487 = x12486 != '\n';
        x12489 = x12487;
      }
      bool x12490 = x12489;
      if (!x12490) break;
      x12336 = x12336 + 1;
    }
    x12336 = x12336 + 1;
    for (;;) {
      long x12502 = x12336;
      char x12503 = x1000[x12502];
      bool x12504 = x12503 != '.';
      bool x12509 = x12504;
      if (x12504) {
        long x12505 = x12336;
        char x12506 = x1000[x12505];
        bool x12507 = x12506 != '|';
        x12509 = x12507;
      }
      bool x12510 = x12509;
      bool x12515 = x12510;
      if (x12510) {
        long x12511 = x12336;
        char x12512 = x1000[x12511];
        bool x12513 = x12512 != '\n';
        x12515 = x12513;
      }
      bool x12516 = x12515;
      if (!x12516) break;
      x12336 = x12336 + 1;
    }
    long x12528 = x12336;
    char x12529 = x1000[x12528];
    bool x12530 = x12529 == '.';
    if (x12530) {
      x12336 = x12336 + 1;
      for (;;) {
        long x12532 = x12336;
        char x12533 = x1000[x12532];
        bool x12534 = x12533 != '|';
        bool x12539 = x12534;
        if (x12534) {
          long x12535 = x12336;
          char x12536 = x1000[x12535];
          bool x12537 = x12536 != '\n';
          x12539 = x12537;
        }
        bool x12540 = x12539;
        if (!x12540) break;
        x12336 = x12336 + 1;
      }
    } else {
    }
    x12336 = x12336 + 1;
    for (;;) {
      long x12565 = x12336;
      char x12566 = x1000[x12565];
      bool x12567 = x12566 != '|';
      bool x12572 = x12567;
      if (x12567) {
        long x12568 = x12336;
        char x12569 = x1000[x12568];
        bool x12570 = x12569 != '\n';
        x12572 = x12570;
      }
      bool x12573 = x12572;
      if (!x12573) break;
      x12336 = x12336 + 1;
    }
    x12336 = x12336 + 1;
    long x12583 = x12338;
    long x12584 = x12337;
    bool x12585 = x12583 == x12584;
    if (x12585) {
      long x12586 = x12584 * 4L;
      x12337 = x12586;
      printf("buffer.resize %d\n",x12586);
      int* x12589 = x12340;
      int* x12590 = (int*)realloc(x12589,x12586 * sizeof(int));
      x12340 = x12590;
      char** x12601 = x12348;
      char** x12602 = (char**)realloc(x12601,x12586 * sizeof(char*));
      x12348 = x12602;
    } else {
    }
    int* x12618 = x12340;
    x12618[x12583] = x12384;
    char** x12626 = x12348;
    char* x12456 = x1000+x12439;
    x12626[x12583] = x12456;
    x12338 = x12338 + 1;
  }
  long x12639 = 0L;
  long x12640 = x6;
  long x12641 = 0L;
  int* x12642 = (int*)malloc(x6 * sizeof(int));
  int* x12643 = x12642;
  int* x12644 = (int*)malloc(x6 * sizeof(int));
  int* x12645 = x12644;
  long* x12650 = (long*)malloc(x6 * sizeof(long));
  long* x12651 = x12650;
  int x3371 = open("../databases/sf2/orders.tbl",0);
  long x3372 = fsize(x3371);
  char* x3373 = mmap(0, x3372, PROT_READ, MAP_FILE | MAP_SHARED, x3371, 0);
  for (;;) {
    long x12660 = x12639;
    bool x12661 = x12660 < x3372;
    if (!x12661) break;
    int x12664 = 0;
    for (;;) {
      long x12665 = x12639;
      char x12666 = x3373[x12665];
      bool x12667 = x12666 != '|';
      bool x12672 = x12667;
      if (x12667) {
        long x12668 = x12639;
        char x12669 = x3373[x12668];
        bool x12670 = x12669 != '\n';
        x12672 = x12670;
      }
      bool x12673 = x12672;
      if (!x12673) break;
      int x12675 = x12664;
      long x12677 = x12639;
      int x12676 = x12675 * 10;
      char x12678 = x3373[x12677];
      char x12679 = x12678 - '0';
      int x12680 = x12676 + x12679;
      x12664 = x12680;
      x12639 = x12639 + 1;
    }
    x12639 = x12639 + 1;
    int x12686 = x12664;
    int x12688 = 0;
    for (;;) {
      long x12689 = x12639;
      char x12690 = x3373[x12689];
      bool x12691 = x12690 != '|';
      bool x12696 = x12691;
      if (x12691) {
        long x12692 = x12639;
        char x12693 = x3373[x12692];
        bool x12694 = x12693 != '\n';
        x12696 = x12694;
      }
      bool x12697 = x12696;
      if (!x12697) break;
      int x12699 = x12688;
      long x12701 = x12639;
      int x12700 = x12699 * 10;
      char x12702 = x3373[x12701];
      char x12703 = x12702 - '0';
      int x12704 = x12700 + x12703;
      x12688 = x12704;
      x12639 = x12639 + 1;
    }
    x12639 = x12639 + 1;
    int x12710 = x12688;
    x12639 = x12639 + 2;
    for (;;) {
      long x12717 = x12639;
      char x12718 = x3373[x12717];
      bool x12719 = x12718 != '.';
      bool x12724 = x12719;
      if (x12719) {
        long x12720 = x12639;
        char x12721 = x3373[x12720];
        bool x12722 = x12721 != '|';
        x12724 = x12722;
      }
      bool x12725 = x12724;
      bool x12730 = x12725;
      if (x12725) {
        long x12726 = x12639;
        char x12727 = x3373[x12726];
        bool x12728 = x12727 != '\n';
        x12730 = x12728;
      }
      bool x12731 = x12730;
      if (!x12731) break;
      x12639 = x12639 + 1;
    }
    long x12743 = x12639;
    char x12744 = x3373[x12743];
    bool x12745 = x12744 == '.';
    if (x12745) {
      x12639 = x12639 + 1;
      for (;;) {
        long x12747 = x12639;
        char x12748 = x3373[x12747];
        bool x12749 = x12748 != '|';
        bool x12754 = x12749;
        if (x12749) {
          long x12750 = x12639;
          char x12751 = x3373[x12750];
          bool x12752 = x12751 != '\n';
          x12754 = x12752;
        }
        bool x12755 = x12754;
        if (!x12755) break;
        x12639 = x12639 + 1;
      }
    } else {
    }
    x12639 = x12639 + 1;
    int x12780 = 0;
    for (;;) {
      long x12781 = x12639;
      char x12782 = x3373[x12781];
      bool x12783 = x12782 != '-';
      bool x12788 = x12783;
      if (x12783) {
        long x12784 = x12639;
        char x12785 = x3373[x12784];
        bool x12786 = x12785 != '\n';
        x12788 = x12786;
      }
      bool x12789 = x12788;
      if (!x12789) break;
      int x12791 = x12780;
      long x12793 = x12639;
      int x12792 = x12791 * 10;
      char x12794 = x3373[x12793];
      char x12795 = x12794 - '0';
      int x12796 = x12792 + x12795;
      x12780 = x12796;
      x12639 = x12639 + 1;
    }
    x12639 = x12639 + 1;
    int x12802 = x12780;
    int x12804 = 0;
    for (;;) {
      long x12805 = x12639;
      char x12806 = x3373[x12805];
      bool x12807 = x12806 != '-';
      bool x12812 = x12807;
      if (x12807) {
        long x12808 = x12639;
        char x12809 = x3373[x12808];
        bool x12810 = x12809 != '\n';
        x12812 = x12810;
      }
      bool x12813 = x12812;
      if (!x12813) break;
      int x12815 = x12804;
      long x12817 = x12639;
      int x12816 = x12815 * 10;
      char x12818 = x3373[x12817];
      char x12819 = x12818 - '0';
      int x12820 = x12816 + x12819;
      x12804 = x12820;
      x12639 = x12639 + 1;
    }
    x12639 = x12639 + 1;
    int x12826 = x12804;
    int x12828 = 0;
    for (;;) {
      long x12829 = x12639;
      char x12830 = x3373[x12829];
      bool x12831 = x12830 != '|';
      bool x12836 = x12831;
      if (x12831) {
        long x12832 = x12639;
        char x12833 = x3373[x12832];
        bool x12834 = x12833 != '\n';
        x12836 = x12834;
      }
      bool x12837 = x12836;
      if (!x12837) break;
      int x12839 = x12828;
      long x12841 = x12639;
      int x12840 = x12839 * 10;
      char x12842 = x3373[x12841];
      char x12843 = x12842 - '0';
      int x12844 = x12840 + x12843;
      x12828 = x12844;
      x12639 = x12639 + 1;
    }
    x12639 = x12639 + 1;
    int x12850 = x12828;
    for (;;) {
      long x12856 = x12639;
      char x12857 = x3373[x12856];
      bool x12858 = x12857 != '|';
      bool x12863 = x12858;
      if (x12858) {
        long x12859 = x12639;
        char x12860 = x3373[x12859];
        bool x12861 = x12860 != '\n';
        x12863 = x12861;
      }
      bool x12864 = x12863;
      if (!x12864) break;
      x12639 = x12639 + 1;
    }
    x12639 = x12639 + 1;
    for (;;) {
      long x12874 = x12639;
      char x12875 = x3373[x12874];
      bool x12876 = x12875 != '|';
      bool x12881 = x12876;
      if (x12876) {
        long x12877 = x12639;
        char x12878 = x3373[x12877];
        bool x12879 = x12878 != '\n';
        x12881 = x12879;
      }
      bool x12882 = x12881;
      if (!x12882) break;
      x12639 = x12639 + 1;
    }
    x12639 = x12639 + 1;
    for (;;) {
      long x12893 = x12639;
      char x12894 = x3373[x12893];
      bool x12895 = x12894 != '|';
      bool x12900 = x12895;
      if (x12895) {
        long x12896 = x12639;
        char x12897 = x3373[x12896];
        bool x12898 = x12897 != '\n';
        x12900 = x12898;
      }
      bool x12901 = x12900;
      if (!x12901) break;
      x12639 = x12639 + 1;
    }
    x12639 = x12639 + 1;
    for (;;) {
      long x12916 = x12639;
      char x12917 = x3373[x12916];
      bool x12918 = x12917 != '|';
      bool x12923 = x12918;
      if (x12918) {
        long x12919 = x12639;
        char x12920 = x3373[x12919];
        bool x12921 = x12920 != '\n';
        x12923 = x12921;
      }
      bool x12924 = x12923;
      if (!x12924) break;
      x12639 = x12639 + 1;
    }
    x12639 = x12639 + 1;
    long x12934 = x12641;
    long x12935 = x12640;
    bool x12936 = x12934 == x12935;
    if (x12936) {
      long x12937 = x12935 * 4L;
      x12640 = x12937;
      printf("buffer.resize %d\n",x12937);
      int* x12940 = x12643;
      int* x12941 = (int*)realloc(x12940,x12937 * sizeof(int));
      x12643 = x12941;
      int* x12943 = x12645;
      int* x12944 = (int*)realloc(x12943,x12937 * sizeof(int));
      x12645 = x12944;
      long* x12952 = x12651;
      long* x12953 = (long*)realloc(x12952,x12937 * sizeof(long));
      x12651 = x12953;
    } else {
    }
    int* x12969 = x12643;
    x12969[x12934] = x12686;
    int* x12971 = x12645;
    x12971[x12934] = x12710;
    long* x12977 = x12651;
    long x12851 = x12802 * 10000L;
    long x12852 = x12826 * 100L;
    long x12853 = x12851 + x12852;
    long x12854 = x12853 + x12850;
    x12977[x12934] = x12854;
    x12641 = x12641 + 1;
  }
  long x12990 = 0L;
  long x12991 = x6;
  long x12992 = 0L;
  int* x12993 = (int*)malloc(x6 * sizeof(int));
  int* x12994 = x12993;
  int* x12995 = (int*)malloc(x6 * sizeof(int));
  int* x12996 = x12995;
  int* x12997 = (int*)malloc(x6 * sizeof(int));
  int* x12998 = x12997;
  double* x13003 = (double*)malloc(x6 * sizeof(double));
  double* x13004 = x13003;
  double* x13005 = (double*)malloc(x6 * sizeof(double));
  double* x13006 = x13005;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  long x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    long x13025 = x12990;
    bool x13026 = x13025 < x3;
    if (!x13026) break;
    int x13029 = 0;
    for (;;) {
      long x13030 = x12990;
      char x13031 = x4[x13030];
      bool x13032 = x13031 != '|';
      bool x13037 = x13032;
      if (x13032) {
        long x13033 = x12990;
        char x13034 = x4[x13033];
        bool x13035 = x13034 != '\n';
        x13037 = x13035;
      }
      bool x13038 = x13037;
      if (!x13038) break;
      int x13040 = x13029;
      long x13042 = x12990;
      int x13041 = x13040 * 10;
      char x13043 = x4[x13042];
      char x13044 = x13043 - '0';
      int x13045 = x13041 + x13044;
      x13029 = x13045;
      x12990 = x12990 + 1;
    }
    x12990 = x12990 + 1;
    int x13051 = x13029;
    int x13053 = 0;
    for (;;) {
      long x13054 = x12990;
      char x13055 = x4[x13054];
      bool x13056 = x13055 != '|';
      bool x13061 = x13056;
      if (x13056) {
        long x13057 = x12990;
        char x13058 = x4[x13057];
        bool x13059 = x13058 != '\n';
        x13061 = x13059;
      }
      bool x13062 = x13061;
      if (!x13062) break;
      int x13064 = x13053;
      long x13066 = x12990;
      int x13065 = x13064 * 10;
      char x13067 = x4[x13066];
      char x13068 = x13067 - '0';
      int x13069 = x13065 + x13068;
      x13053 = x13069;
      x12990 = x12990 + 1;
    }
    x12990 = x12990 + 1;
    int x13075 = x13053;
    int x13077 = 0;
    for (;;) {
      long x13078 = x12990;
      char x13079 = x4[x13078];
      bool x13080 = x13079 != '|';
      bool x13085 = x13080;
      if (x13080) {
        long x13081 = x12990;
        char x13082 = x4[x13081];
        bool x13083 = x13082 != '\n';
        x13085 = x13083;
      }
      bool x13086 = x13085;
      if (!x13086) break;
      int x13088 = x13077;
      long x13090 = x12990;
      int x13089 = x13088 * 10;
      char x13091 = x4[x13090];
      char x13092 = x13091 - '0';
      int x13093 = x13089 + x13092;
      x13077 = x13093;
      x12990 = x12990 + 1;
    }
    x12990 = x12990 + 1;
    int x13099 = x13077;
    for (;;) {
      long x13102 = x12990;
      char x13103 = x4[x13102];
      bool x13104 = x13103 != '|';
      bool x13109 = x13104;
      if (x13104) {
        long x13105 = x12990;
        char x13106 = x4[x13105];
        bool x13107 = x13106 != '\n';
        x13109 = x13107;
      }
      bool x13110 = x13109;
      if (!x13110) break;
      x12990 = x12990 + 1;
    }
    x12990 = x12990 + 1;
    for (;;) {
      long x13127 = x12990;
      char x13128 = x4[x13127];
      bool x13129 = x13128 != '.';
      bool x13134 = x13129;
      if (x13129) {
        long x13130 = x12990;
        char x13131 = x4[x13130];
        bool x13132 = x13131 != '|';
        x13134 = x13132;
      }
      bool x13135 = x13134;
      bool x13140 = x13135;
      if (x13135) {
        long x13136 = x12990;
        char x13137 = x4[x13136];
        bool x13138 = x13137 != '\n';
        x13140 = x13138;
      }
      bool x13141 = x13140;
      if (!x13141) break;
      x12990 = x12990 + 1;
    }
    long x13153 = x12990;
    char x13154 = x4[x13153];
    bool x13155 = x13154 == '.';
    if (x13155) {
      x12990 = x12990 + 1;
      for (;;) {
        long x13157 = x12990;
        char x13158 = x4[x13157];
        bool x13159 = x13158 != '|';
        bool x13164 = x13159;
        if (x13159) {
          long x13160 = x12990;
          char x13161 = x4[x13160];
          bool x13162 = x13161 != '\n';
          x13164 = x13162;
        }
        bool x13165 = x13164;
        if (!x13165) break;
        x12990 = x12990 + 1;
      }
    } else {
    }
    x12990 = x12990 + 1;
    int x13190 = 0;
    int x13191 = 1;
    for (;;) {
      long x13192 = x12990;
      char x13193 = x4[x13192];
      bool x13194 = x13193 != '.';
      bool x13199 = x13194;
      if (x13194) {
        long x13195 = x12990;
        char x13196 = x4[x13195];
        bool x13197 = x13196 != '|';
        x13199 = x13197;
      }
      bool x13200 = x13199;
      bool x13205 = x13200;
      if (x13200) {
        long x13201 = x12990;
        char x13202 = x4[x13201];
        bool x13203 = x13202 != '\n';
        x13205 = x13203;
      }
      bool x13206 = x13205;
      if (!x13206) break;
      int x13208 = x13190;
      long x13210 = x12990;
      int x13209 = x13208 * 10;
      char x13211 = x4[x13210];
      char x13212 = x13211 - '0';
      int x13213 = x13209 + x13212;
      x13190 = x13213;
      x12990 = x12990 + 1;
    }
    long x13218 = x12990;
    char x13219 = x4[x13218];
    bool x13220 = x13219 == '.';
    if (x13220) {
      x12990 = x12990 + 1;
      for (;;) {
        long x13222 = x12990;
        char x13223 = x4[x13222];
        bool x13224 = x13223 != '|';
        bool x13229 = x13224;
        if (x13224) {
          long x13225 = x12990;
          char x13226 = x4[x13225];
          bool x13227 = x13226 != '\n';
          x13229 = x13227;
        }
        bool x13230 = x13229;
        if (!x13230) break;
        int x13232 = x13190;
        long x13234 = x12990;
        int x13233 = x13232 * 10;
        char x13235 = x4[x13234];
        char x13236 = x13235 - '0';
        int x13237 = x13233 + x13236;
        x13190 = x13237;
        int x13239 = x13191;
        int x13240 = x13239 * 10;
        x13191 = x13240;
        x12990 = x12990 + 1;
      }
    } else {
    }
    x12990 = x12990 + 1;
    int x13249 = x13190;
    int x13251 = x13191;
    int x13255 = 0;
    int x13256 = 1;
    for (;;) {
      long x13257 = x12990;
      char x13258 = x4[x13257];
      bool x13259 = x13258 != '.';
      bool x13264 = x13259;
      if (x13259) {
        long x13260 = x12990;
        char x13261 = x4[x13260];
        bool x13262 = x13261 != '|';
        x13264 = x13262;
      }
      bool x13265 = x13264;
      bool x13270 = x13265;
      if (x13265) {
        long x13266 = x12990;
        char x13267 = x4[x13266];
        bool x13268 = x13267 != '\n';
        x13270 = x13268;
      }
      bool x13271 = x13270;
      if (!x13271) break;
      int x13273 = x13255;
      long x13275 = x12990;
      int x13274 = x13273 * 10;
      char x13276 = x4[x13275];
      char x13277 = x13276 - '0';
      int x13278 = x13274 + x13277;
      x13255 = x13278;
      x12990 = x12990 + 1;
    }
    long x13283 = x12990;
    char x13284 = x4[x13283];
    bool x13285 = x13284 == '.';
    if (x13285) {
      x12990 = x12990 + 1;
      for (;;) {
        long x13287 = x12990;
        char x13288 = x4[x13287];
        bool x13289 = x13288 != '|';
        bool x13294 = x13289;
        if (x13289) {
          long x13290 = x12990;
          char x13291 = x4[x13290];
          bool x13292 = x13291 != '\n';
          x13294 = x13292;
        }
        bool x13295 = x13294;
        if (!x13295) break;
        int x13297 = x13255;
        long x13299 = x12990;
        int x13298 = x13297 * 10;
        char x13300 = x4[x13299];
        char x13301 = x13300 - '0';
        int x13302 = x13298 + x13301;
        x13255 = x13302;
        int x13304 = x13256;
        int x13305 = x13304 * 10;
        x13256 = x13305;
        x12990 = x12990 + 1;
      }
    } else {
    }
    x12990 = x12990 + 1;
    int x13314 = x13255;
    int x13316 = x13256;
    for (;;) {
      long x13322 = x12990;
      char x13323 = x4[x13322];
      bool x13324 = x13323 != '.';
      bool x13329 = x13324;
      if (x13324) {
        long x13325 = x12990;
        char x13326 = x4[x13325];
        bool x13327 = x13326 != '|';
        x13329 = x13327;
      }
      bool x13330 = x13329;
      bool x13335 = x13330;
      if (x13330) {
        long x13331 = x12990;
        char x13332 = x4[x13331];
        bool x13333 = x13332 != '\n';
        x13335 = x13333;
      }
      bool x13336 = x13335;
      if (!x13336) break;
      x12990 = x12990 + 1;
    }
    long x13348 = x12990;
    char x13349 = x4[x13348];
    bool x13350 = x13349 == '.';
    if (x13350) {
      x12990 = x12990 + 1;
      for (;;) {
        long x13352 = x12990;
        char x13353 = x4[x13352];
        bool x13354 = x13353 != '|';
        bool x13359 = x13354;
        if (x13354) {
          long x13355 = x12990;
          char x13356 = x4[x13355];
          bool x13357 = x13356 != '\n';
          x13359 = x13357;
        }
        bool x13360 = x13359;
        if (!x13360) break;
        x12990 = x12990 + 1;
      }
    } else {
    }
    x12990 = x12990 + 1;
    x12990 = x12990 + 2;
    x12990 = x12990 + 2;
    for (;;) {
      long x13392 = x12990;
      char x13393 = x4[x13392];
      bool x13394 = x13393 != '-';
      bool x13399 = x13394;
      if (x13394) {
        long x13395 = x12990;
        char x13396 = x4[x13395];
        bool x13397 = x13396 != '\n';
        x13399 = x13397;
      }
      bool x13400 = x13399;
      if (!x13400) break;
      x12990 = x12990 + 1;
    }
    x12990 = x12990 + 1;
    for (;;) {
      long x13416 = x12990;
      char x13417 = x4[x13416];
      bool x13418 = x13417 != '-';
      bool x13423 = x13418;
      if (x13418) {
        long x13419 = x12990;
        char x13420 = x4[x13419];
        bool x13421 = x13420 != '\n';
        x13423 = x13421;
      }
      bool x13424 = x13423;
      if (!x13424) break;
      x12990 = x12990 + 1;
    }
    x12990 = x12990 + 1;
    for (;;) {
      long x13440 = x12990;
      char x13441 = x4[x13440];
      bool x13442 = x13441 != '|';
      bool x13447 = x13442;
      if (x13442) {
        long x13443 = x12990;
        char x13444 = x4[x13443];
        bool x13445 = x13444 != '\n';
        x13447 = x13445;
      }
      bool x13448 = x13447;
      if (!x13448) break;
      x12990 = x12990 + 1;
    }
    x12990 = x12990 + 1;
    for (;;) {
      long x13468 = x12990;
      char x13469 = x4[x13468];
      bool x13470 = x13469 != '-';
      bool x13475 = x13470;
      if (x13470) {
        long x13471 = x12990;
        char x13472 = x4[x13471];
        bool x13473 = x13472 != '\n';
        x13475 = x13473;
      }
      bool x13476 = x13475;
      if (!x13476) break;
      x12990 = x12990 + 1;
    }
    x12990 = x12990 + 1;
    for (;;) {
      long x13492 = x12990;
      char x13493 = x4[x13492];
      bool x13494 = x13493 != '-';
      bool x13499 = x13494;
      if (x13494) {
        long x13495 = x12990;
        char x13496 = x4[x13495];
        bool x13497 = x13496 != '\n';
        x13499 = x13497;
      }
      bool x13500 = x13499;
      if (!x13500) break;
      x12990 = x12990 + 1;
    }
    x12990 = x12990 + 1;
    for (;;) {
      long x13516 = x12990;
      char x13517 = x4[x13516];
      bool x13518 = x13517 != '|';
      bool x13523 = x13518;
      if (x13518) {
        long x13519 = x12990;
        char x13520 = x4[x13519];
        bool x13521 = x13520 != '\n';
        x13523 = x13521;
      }
      bool x13524 = x13523;
      if (!x13524) break;
      x12990 = x12990 + 1;
    }
    x12990 = x12990 + 1;
    for (;;) {
      long x13544 = x12990;
      char x13545 = x4[x13544];
      bool x13546 = x13545 != '-';
      bool x13551 = x13546;
      if (x13546) {
        long x13547 = x12990;
        char x13548 = x4[x13547];
        bool x13549 = x13548 != '\n';
        x13551 = x13549;
      }
      bool x13552 = x13551;
      if (!x13552) break;
      x12990 = x12990 + 1;
    }
    x12990 = x12990 + 1;
    for (;;) {
      long x13568 = x12990;
      char x13569 = x4[x13568];
      bool x13570 = x13569 != '-';
      bool x13575 = x13570;
      if (x13570) {
        long x13571 = x12990;
        char x13572 = x4[x13571];
        bool x13573 = x13572 != '\n';
        x13575 = x13573;
      }
      bool x13576 = x13575;
      if (!x13576) break;
      x12990 = x12990 + 1;
    }
    x12990 = x12990 + 1;
    for (;;) {
      long x13592 = x12990;
      char x13593 = x4[x13592];
      bool x13594 = x13593 != '|';
      bool x13599 = x13594;
      if (x13594) {
        long x13595 = x12990;
        char x13596 = x4[x13595];
        bool x13597 = x13596 != '\n';
        x13599 = x13597;
      }
      bool x13600 = x13599;
      if (!x13600) break;
      x12990 = x12990 + 1;
    }
    x12990 = x12990 + 1;
    for (;;) {
      long x13619 = x12990;
      char x13620 = x4[x13619];
      bool x13621 = x13620 != '|';
      bool x13626 = x13621;
      if (x13621) {
        long x13622 = x12990;
        char x13623 = x4[x13622];
        bool x13624 = x13623 != '\n';
        x13626 = x13624;
      }
      bool x13627 = x13626;
      if (!x13627) break;
      x12990 = x12990 + 1;
    }
    x12990 = x12990 + 1;
    for (;;) {
      long x13637 = x12990;
      char x13638 = x4[x13637];
      bool x13639 = x13638 != '|';
      bool x13644 = x13639;
      if (x13639) {
        long x13640 = x12990;
        char x13641 = x4[x13640];
        bool x13642 = x13641 != '\n';
        x13644 = x13642;
      }
      bool x13645 = x13644;
      if (!x13645) break;
      x12990 = x12990 + 1;
    }
    x12990 = x12990 + 1;
    for (;;) {
      long x13655 = x12990;
      char x13656 = x4[x13655];
      bool x13657 = x13656 != '|';
      bool x13662 = x13657;
      if (x13657) {
        long x13658 = x12990;
        char x13659 = x4[x13658];
        bool x13660 = x13659 != '\n';
        x13662 = x13660;
      }
      bool x13663 = x13662;
      if (!x13663) break;
      x12990 = x12990 + 1;
    }
    x12990 = x12990 + 1;
    long x13673 = x12992;
    long x13674 = x12991;
    bool x13675 = x13673 == x13674;
    if (x13675) {
      long x13676 = x13674 * 4L;
      x12991 = x13676;
      printf("buffer.resize %d\n",x13676);
      int* x13679 = x12994;
      int* x13680 = (int*)realloc(x13679,x13676 * sizeof(int));
      x12994 = x13680;
      int* x13682 = x12996;
      int* x13683 = (int*)realloc(x13682,x13676 * sizeof(int));
      x12996 = x13683;
      int* x13685 = x12998;
      int* x13686 = (int*)realloc(x13685,x13676 * sizeof(int));
      x12998 = x13686;
      double* x13694 = x13004;
      double* x13695 = (double*)realloc(x13694,x13676 * sizeof(double));
      x13004 = x13695;
      double* x13697 = x13006;
      double* x13698 = (double*)realloc(x13697,x13676 * sizeof(double));
      x13006 = x13698;
    } else {
    }
    int* x13729 = x12994;
    x13729[x13673] = x13051;
    int* x13731 = x12996;
    x13731[x13673] = x13075;
    int* x13733 = x12998;
    x13733[x13673] = x13099;
    double* x13739 = x13004;
    double x13250 = (double)x13249;
    double x13252 = (double)x13251;
    double x13253 = x13250 / x13252;
    x13739[x13673] = x13253;
    double* x13741 = x13006;
    double x13315 = (double)x13314;
    double x13317 = (double)x13316;
    double x13318 = x13315 / x13317;
    x13741[x13673] = x13318;
    x12992 = x12992 + 1;
  }
  long x13764 = 0L;
  long x13765 = x6;
  long x13766 = 0L;
  int* x13767 = (int*)malloc(x6 * sizeof(int));
  int* x13768 = x13767;
  int* x13773 = (int*)malloc(x6 * sizeof(int));
  int* x13774 = x13773;
  int x3725 = open("../databases/sf2/customer.tbl",0);
  long x3726 = fsize(x3725);
  char* x3727 = mmap(0, x3726, PROT_READ, MAP_FILE | MAP_SHARED, x3725, 0);
  for (;;) {
    long x13783 = x13764;
    bool x13784 = x13783 < x3726;
    if (!x13784) break;
    int x13787 = 0;
    for (;;) {
      long x13788 = x13764;
      char x13789 = x3727[x13788];
      bool x13790 = x13789 != '|';
      bool x13795 = x13790;
      if (x13790) {
        long x13791 = x13764;
        char x13792 = x3727[x13791];
        bool x13793 = x13792 != '\n';
        x13795 = x13793;
      }
      bool x13796 = x13795;
      if (!x13796) break;
      int x13798 = x13787;
      long x13800 = x13764;
      int x13799 = x13798 * 10;
      char x13801 = x3727[x13800];
      char x13802 = x13801 - '0';
      int x13803 = x13799 + x13802;
      x13787 = x13803;
      x13764 = x13764 + 1;
    }
    x13764 = x13764 + 1;
    int x13809 = x13787;
    for (;;) {
      long x13811 = x13764;
      char x13812 = x3727[x13811];
      bool x13813 = x13812 != '|';
      bool x13818 = x13813;
      if (x13813) {
        long x13814 = x13764;
        char x13815 = x3727[x13814];
        bool x13816 = x13815 != '\n';
        x13818 = x13816;
      }
      bool x13819 = x13818;
      if (!x13819) break;
      x13764 = x13764 + 1;
    }
    x13764 = x13764 + 1;
    for (;;) {
      long x13829 = x13764;
      char x13830 = x3727[x13829];
      bool x13831 = x13830 != '|';
      bool x13836 = x13831;
      if (x13831) {
        long x13832 = x13764;
        char x13833 = x3727[x13832];
        bool x13834 = x13833 != '\n';
        x13836 = x13834;
      }
      bool x13837 = x13836;
      if (!x13837) break;
      x13764 = x13764 + 1;
    }
    x13764 = x13764 + 1;
    int x13847 = 0;
    for (;;) {
      long x13848 = x13764;
      char x13849 = x3727[x13848];
      bool x13850 = x13849 != '|';
      bool x13855 = x13850;
      if (x13850) {
        long x13851 = x13764;
        char x13852 = x3727[x13851];
        bool x13853 = x13852 != '\n';
        x13855 = x13853;
      }
      bool x13856 = x13855;
      if (!x13856) break;
      int x13858 = x13847;
      long x13860 = x13764;
      int x13859 = x13858 * 10;
      char x13861 = x3727[x13860];
      char x13862 = x13861 - '0';
      int x13863 = x13859 + x13862;
      x13847 = x13863;
      x13764 = x13764 + 1;
    }
    x13764 = x13764 + 1;
    int x13869 = x13847;
    for (;;) {
      long x13871 = x13764;
      char x13872 = x3727[x13871];
      bool x13873 = x13872 != '|';
      bool x13878 = x13873;
      if (x13873) {
        long x13874 = x13764;
        char x13875 = x3727[x13874];
        bool x13876 = x13875 != '\n';
        x13878 = x13876;
      }
      bool x13879 = x13878;
      if (!x13879) break;
      x13764 = x13764 + 1;
    }
    x13764 = x13764 + 1;
    for (;;) {
      long x13891 = x13764;
      char x13892 = x3727[x13891];
      bool x13893 = x13892 != '.';
      bool x13898 = x13893;
      if (x13893) {
        long x13894 = x13764;
        char x13895 = x3727[x13894];
        bool x13896 = x13895 != '|';
        x13898 = x13896;
      }
      bool x13899 = x13898;
      bool x13904 = x13899;
      if (x13899) {
        long x13900 = x13764;
        char x13901 = x3727[x13900];
        bool x13902 = x13901 != '\n';
        x13904 = x13902;
      }
      bool x13905 = x13904;
      if (!x13905) break;
      x13764 = x13764 + 1;
    }
    long x13917 = x13764;
    char x13918 = x3727[x13917];
    bool x13919 = x13918 == '.';
    if (x13919) {
      x13764 = x13764 + 1;
      for (;;) {
        long x13921 = x13764;
        char x13922 = x3727[x13921];
        bool x13923 = x13922 != '|';
        bool x13928 = x13923;
        if (x13923) {
          long x13924 = x13764;
          char x13925 = x3727[x13924];
          bool x13926 = x13925 != '\n';
          x13928 = x13926;
        }
        bool x13929 = x13928;
        if (!x13929) break;
        x13764 = x13764 + 1;
      }
    } else {
    }
    x13764 = x13764 + 1;
    for (;;) {
      long x13954 = x13764;
      char x13955 = x3727[x13954];
      bool x13956 = x13955 != '|';
      bool x13961 = x13956;
      if (x13956) {
        long x13957 = x13764;
        char x13958 = x3727[x13957];
        bool x13959 = x13958 != '\n';
        x13961 = x13959;
      }
      bool x13962 = x13961;
      if (!x13962) break;
      x13764 = x13764 + 1;
    }
    x13764 = x13764 + 1;
    for (;;) {
      long x13972 = x13764;
      char x13973 = x3727[x13972];
      bool x13974 = x13973 != '|';
      bool x13979 = x13974;
      if (x13974) {
        long x13975 = x13764;
        char x13976 = x3727[x13975];
        bool x13977 = x13976 != '\n';
        x13979 = x13977;
      }
      bool x13980 = x13979;
      if (!x13980) break;
      x13764 = x13764 + 1;
    }
    x13764 = x13764 + 1;
    long x13990 = x13766;
    long x13991 = x13765;
    bool x13992 = x13990 == x13991;
    if (x13992) {
      long x13993 = x13991 * 4L;
      x13765 = x13993;
      printf("buffer.resize %d\n",x13993);
      int* x13996 = x13768;
      int* x13997 = (int*)realloc(x13996,x13993 * sizeof(int));
      x13768 = x13997;
      int* x14005 = x13774;
      int* x14006 = (int*)realloc(x14005,x13993 * sizeof(int));
      x13774 = x14006;
    } else {
    }
    int* x14022 = x13768;
    x14022[x13990] = x13809;
    int* x14028 = x13774;
    x14028[x13990] = x13869;
    x13766 = x13766 + 1;
  }
  long x14041 = 0L;
  long x14042 = x6;
  long x14043 = 0L;
  int* x14044 = (int*)malloc(x6 * sizeof(int));
  int* x14045 = x14044;
  int* x14050 = (int*)malloc(x6 * sizeof(int));
  int* x14051 = x14050;
  int x1750 = open("../databases/sf2/supplier.tbl",0);
  long x1751 = fsize(x1750);
  char* x1752 = mmap(0, x1751, PROT_READ, MAP_FILE | MAP_SHARED, x1750, 0);
  for (;;) {
    long x14058 = x14041;
    bool x14059 = x14058 < x1751;
    if (!x14059) break;
    int x14062 = 0;
    for (;;) {
      long x14063 = x14041;
      char x14064 = x1752[x14063];
      bool x14065 = x14064 != '|';
      bool x14070 = x14065;
      if (x14065) {
        long x14066 = x14041;
        char x14067 = x1752[x14066];
        bool x14068 = x14067 != '\n';
        x14070 = x14068;
      }
      bool x14071 = x14070;
      if (!x14071) break;
      int x14073 = x14062;
      long x14075 = x14041;
      int x14074 = x14073 * 10;
      char x14076 = x1752[x14075];
      char x14077 = x14076 - '0';
      int x14078 = x14074 + x14077;
      x14062 = x14078;
      x14041 = x14041 + 1;
    }
    x14041 = x14041 + 1;
    int x14084 = x14062;
    for (;;) {
      long x14086 = x14041;
      char x14087 = x1752[x14086];
      bool x14088 = x14087 != '|';
      bool x14093 = x14088;
      if (x14088) {
        long x14089 = x14041;
        char x14090 = x1752[x14089];
        bool x14091 = x14090 != '\n';
        x14093 = x14091;
      }
      bool x14094 = x14093;
      if (!x14094) break;
      x14041 = x14041 + 1;
    }
    x14041 = x14041 + 1;
    for (;;) {
      long x14104 = x14041;
      char x14105 = x1752[x14104];
      bool x14106 = x14105 != '|';
      bool x14111 = x14106;
      if (x14106) {
        long x14107 = x14041;
        char x14108 = x1752[x14107];
        bool x14109 = x14108 != '\n';
        x14111 = x14109;
      }
      bool x14112 = x14111;
      if (!x14112) break;
      x14041 = x14041 + 1;
    }
    x14041 = x14041 + 1;
    int x14122 = 0;
    for (;;) {
      long x14123 = x14041;
      char x14124 = x1752[x14123];
      bool x14125 = x14124 != '|';
      bool x14130 = x14125;
      if (x14125) {
        long x14126 = x14041;
        char x14127 = x1752[x14126];
        bool x14128 = x14127 != '\n';
        x14130 = x14128;
      }
      bool x14131 = x14130;
      if (!x14131) break;
      int x14133 = x14122;
      long x14135 = x14041;
      int x14134 = x14133 * 10;
      char x14136 = x1752[x14135];
      char x14137 = x14136 - '0';
      int x14138 = x14134 + x14137;
      x14122 = x14138;
      x14041 = x14041 + 1;
    }
    x14041 = x14041 + 1;
    int x14144 = x14122;
    for (;;) {
      long x14146 = x14041;
      char x14147 = x1752[x14146];
      bool x14148 = x14147 != '|';
      bool x14153 = x14148;
      if (x14148) {
        long x14149 = x14041;
        char x14150 = x1752[x14149];
        bool x14151 = x14150 != '\n';
        x14153 = x14151;
      }
      bool x14154 = x14153;
      if (!x14154) break;
      x14041 = x14041 + 1;
    }
    x14041 = x14041 + 1;
    for (;;) {
      long x14166 = x14041;
      char x14167 = x1752[x14166];
      bool x14168 = x14167 != '.';
      bool x14173 = x14168;
      if (x14168) {
        long x14169 = x14041;
        char x14170 = x1752[x14169];
        bool x14171 = x14170 != '|';
        x14173 = x14171;
      }
      bool x14174 = x14173;
      bool x14179 = x14174;
      if (x14174) {
        long x14175 = x14041;
        char x14176 = x1752[x14175];
        bool x14177 = x14176 != '\n';
        x14179 = x14177;
      }
      bool x14180 = x14179;
      if (!x14180) break;
      x14041 = x14041 + 1;
    }
    long x14192 = x14041;
    char x14193 = x1752[x14192];
    bool x14194 = x14193 == '.';
    if (x14194) {
      x14041 = x14041 + 1;
      for (;;) {
        long x14196 = x14041;
        char x14197 = x1752[x14196];
        bool x14198 = x14197 != '|';
        bool x14203 = x14198;
        if (x14198) {
          long x14199 = x14041;
          char x14200 = x1752[x14199];
          bool x14201 = x14200 != '\n';
          x14203 = x14201;
        }
        bool x14204 = x14203;
        if (!x14204) break;
        x14041 = x14041 + 1;
      }
    } else {
    }
    x14041 = x14041 + 1;
    for (;;) {
      long x14229 = x14041;
      char x14230 = x1752[x14229];
      bool x14231 = x14230 != '|';
      bool x14236 = x14231;
      if (x14231) {
        long x14232 = x14041;
        char x14233 = x1752[x14232];
        bool x14234 = x14233 != '\n';
        x14236 = x14234;
      }
      bool x14237 = x14236;
      if (!x14237) break;
      x14041 = x14041 + 1;
    }
    x14041 = x14041 + 1;
    long x14247 = x14043;
    long x14248 = x14042;
    bool x14249 = x14247 == x14248;
    if (x14249) {
      long x14250 = x14248 * 4L;
      x14042 = x14250;
      printf("buffer.resize %d\n",x14250);
      int* x14253 = x14045;
      int* x14254 = (int*)realloc(x14253,x14250 * sizeof(int));
      x14045 = x14254;
      int* x14262 = x14051;
      int* x14263 = (int*)realloc(x14262,x14250 * sizeof(int));
      x14051 = x14263;
    } else {
    }
    int* x14276 = x14045;
    x14276[x14247] = x14084;
    int* x14282 = x14051;
    x14282[x14247] = x14144;
    x14043 = x14043 + 1;
  }
  long x2011 = DEFAULT_JOIN_HASH_SIZE;
  long x787 = DEFAULT_AGG_HASH_SIZE ;
  long x2034 = x2011 - 1L;
  long x802 = x787 - 1L;
  bool x975 = true == false;
  int x14293;
  for(x14293=0; x14293 < 5; x14293++) {
    bool x14294 = false;
    long x14295 = 0L;
    bool x14296 = false;
    long x14297 = 0L;
    int* x14300 = (int*)malloc(x2011 * sizeof(int));
    int* x14301 = x14300;
    long x14318 = 0L;
    long* x14319 = (long*)malloc(x2011 * sizeof(long));
    long* x14320 = (long*)malloc(x2011 * sizeof(long));
    long x14321;
    for(x14321=0L; x14321 < x2011; x14321++) {
      x14319[x14321] = -1L;
    }
    bool x14326 = false;
    long x14327 = 0L;
    int* x14348 = (int*)malloc(x2011 * sizeof(int));
    int* x14349 = x14348;
    int* x14352 = (int*)malloc(x2011 * sizeof(int));
    int* x14353 = x14352;
    double* x14358 = (double*)malloc(x2011 * sizeof(double));
    double* x14359 = x14358;
    double* x14360 = (double*)malloc(x2011 * sizeof(double));
    double* x14361 = x14360;
    long x14380 = 0L;
    long* x14381 = (long*)malloc(x2011 * sizeof(long));
    long* x14382 = (long*)malloc(x2011 * sizeof(long));
    long x14383;
    for(x14383=0L; x14383 < x2011; x14383++) {
      x14381[x14383] = -1L;
    }
    bool x14388 = false;
    long x14389 = 0L;
    int* x14413 = (int*)malloc(x2011 * sizeof(int));
    int* x14414 = x14413;
    double* x14419 = (double*)malloc(x2011 * sizeof(double));
    double* x14420 = x14419;
    double* x14421 = (double*)malloc(x2011 * sizeof(double));
    double* x14422 = x14421;
    int* x14443 = (int*)malloc(x2011 * sizeof(int));
    int* x14444 = x14443;
    long* x14449 = (long*)malloc(x2011 * sizeof(long));
    long* x14450 = x14449;
    long x14459 = 0L;
    long* x14460 = (long*)malloc(x2011 * sizeof(long));
    long* x14461 = (long*)malloc(x2011 * sizeof(long));
    long x14462;
    for(x14462=0L; x14462 < x2011; x14462++) {
      x14460[x14462] = -1L;
    }
    bool x14467 = false;
    long x14468 = 0L;
    int* x14470 = (int*)malloc(x2011 * sizeof(int));
    int* x14471 = x14470;
    int* x14474 = (int*)malloc(x2011 * sizeof(int));
    int* x14475 = x14474;
    long x14478 = 0L;
    long* x14479 = (long*)malloc(x2011 * sizeof(long));
    long* x14480 = (long*)malloc(x2011 * sizeof(long));
    long x14481;
    for(x14481=0L; x14481 < x2011; x14481++) {
      x14479[x14481] = -1L;
    }
    bool x14486 = false;
    long x14487 = 0L;
    int* x14490 = (int*)malloc(x2011 * sizeof(int));
    int* x14491 = x14490;
    long x14496 = 0L;
    long* x14497 = (long*)malloc(x2011 * sizeof(long));
    long* x14498 = (long*)malloc(x2011 * sizeof(long));
    long x14499;
    for(x14499=0L; x14499 < x2011; x14499++) {
      x14497[x14499] = -1L;
    }
    bool x14504 = false;
    long x14505 = 0L;
    int* x14507 = (int*)malloc(x2011 * sizeof(int));
    int* x14508 = x14507;
    int* x14513 = (int*)malloc(x2011 * sizeof(int));
    int* x14514 = x14513;
    long x14521 = 0L;
    long* x14522 = (long*)malloc(x2011 * sizeof(long));
    long* x14523 = (long*)malloc(x2011 * sizeof(long));
    long x14524;
    for(x14524=0L; x14524 < x2011; x14524++) {
      x14522[x14524] = -1L;
    }
    bool x14530 = false;
    long x14531 = 0L;
    char** x14534 = (char**)malloc(x2011 * sizeof(char*));
    char** x14535 = x14534;
    int* x14536 = (int*)malloc(x2011 * sizeof(int));
    int* x14537 = x14536;
    long x14538 = 0L;
    long* x14539 = (long*)malloc(x2011 * sizeof(long));
    long* x14540 = (long*)malloc(x2011 * sizeof(long));
    long x14541;
    for(x14541=0L; x14541 < x2011; x14541++) {
      x14539[x14541] = -1L;
    }
    struct Anon1074264013* x14548 = (struct Anon1074264013*)malloc(x787 * sizeof(struct Anon1074264013));
    struct Anon1074264013* x14549 = x14548;
    long x14550 = 0L;
    long* x14551 = (long*)malloc(x787 * sizeof(long));
    long x14552;
    for(x14552=0L; x14552 < x787; x14552++) {
      struct Anon1074264013* x14553 = x14549;
      struct Anon1074264013 x14554 = x14553[x14552];
      int x14555 = x14554.key;;
      struct Anon189208763 x14556 = x14554.aggs;;
      struct Anon1074264013 x14557;
      x14557.exists = false;
      x14557.key = x14555;
      x14557.aggs = x14556;
      x14553[x14552] = x14557;
    }
    long x14563 = 0L;
    struct timeval x15422, x15423, x15424;
    gettimeofday(&x15422, NULL);
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x14565 = x14530;
      bool x14566 = !x14565;
      bool x14571 = x14566;
      if (x14566) {
        long x14567 = x14531;
        long x14568 = x12109;
        bool x14569 = x14567 < x14568;
        x14571 = x14569;
      }
      bool x14572 = x14571;
      if (!x14572) break;
      long x14574 = x14531;
      int* x14575 = x12111;
      int x14576 = x14575[x14574];
      char** x14577 = x12113;
      char* x14578 = x14577[x14574];
      x14531 = x14531 + 1;
      long x14586 = x14538;
      char** x14587 = x14535;
      x14587[x14586] = x14578;
      int* x14589 = x14537;
      x14589[x14586] = x14576;
      x14538 = x14538 + 1L;
      long x14592 = x14576 & x2034;
      long x14593 = x14539[x14592];
      x14539[x14592] = x14586;
      x14540[x14586] = x14593;
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x14599 = x14504;
      bool x14600 = !x14599;
      bool x14605 = x14600;
      if (x14600) {
        long x14601 = x14505;
        long x14602 = x14043;
        bool x14603 = x14601 < x14602;
        x14605 = x14603;
      }
      bool x14606 = x14605;
      if (!x14606) break;
      long x14608 = x14505;
      int* x14609 = x14045;
      int x14610 = x14609[x14608];
      int* x14615 = x14051;
      int x14616 = x14615[x14608];
      x14505 = x14505 + 1;
      long x14625 = x14521;
      int* x14626 = x14508;
      x14626[x14625] = x14610;
      int* x14632 = x14514;
      x14632[x14625] = x14616;
      x14521 = x14521 + 1L;
      long x14641 = x14610 & x2034;
      long x14642 = x14522[x14641];
      x14522[x14641] = x14625;
      x14523[x14625] = x14642;
    }
    printf("%s\n","begin scan REGION");
    for (;;) {
      bool x14648 = x14486;
      bool x14649 = !x14648;
      bool x14654 = x14649;
      if (x14649) {
        long x14650 = x14487;
        long x14651 = x12239;
        bool x14652 = x14650 < x14651;
        x14654 = x14652;
      }
      bool x14655 = x14654;
      if (!x14655) break;
      long x14657 = x14487;
      int* x14658 = x12241;
      int x14659 = x14658[x14657];
      char** x14660 = x12243;
      char* x14661 = x14660[x14657];
      x14487 = x14487 + 1;
      bool x14666 = strcmp(x14661,"ASIA") == 0;;
      if (x14666) {
        long x14667 = x14496;
        int* x14668 = x14491;
        x14668[x14667] = x14659;
        x14496 = x14496 + 1L;
        long x14675 = x14659 & x2034;
        long x14676 = x14497[x14675];
        x14497[x14675] = x14667;
        x14498[x14667] = x14676;
      } else {
      }
    }
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x14684 = x14467;
      bool x14685 = !x14684;
      bool x14690 = x14685;
      if (x14685) {
        long x14686 = x14468;
        long x14687 = x12109;
        bool x14688 = x14686 < x14687;
        x14690 = x14688;
      }
      bool x14691 = x14690;
      if (!x14691) break;
      long x14693 = x14468;
      int* x14694 = x12111;
      int x14695 = x14694[x14693];
      int* x14698 = x12115;
      int x14699 = x14698[x14693];
      x14468 = x14468 + 1;
      long x14704 = x14478;
      int* x14705 = x14471;
      x14705[x14704] = x14695;
      int* x14709 = x14475;
      x14709[x14704] = x14699;
      x14478 = x14478 + 1L;
      long x14714 = x14695 & x2034;
      long x14715 = x14479[x14714];
      x14479[x14714] = x14704;
      x14480[x14704] = x14715;
    }
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x14721 = x14296;
      bool x14722 = !x14721;
      bool x14727 = x14722;
      if (x14722) {
        long x14723 = x14297;
        long x14724 = x12338;
        bool x14725 = x14723 < x14724;
        x14727 = x14725;
      }
      bool x14728 = x14727;
      if (!x14728) break;
      long x14730 = x14297;
      int* x14731 = x12340;
      int x14732 = x14731[x14730];
      char** x14739 = x12348;
      char* x14740 = x14739[x14730];
      x14297 = x14297 + 1;
      bool x14751 = strcmp(x14740,"MEDIUM ANODIZED NICKEL") == 0;;
      if (x14751) {
        long x14752 = x14318;
        int* x14753 = x14301;
        x14753[x14752] = x14732;
        x14318 = x14318 + 1L;
        long x14772 = x14732 & x2034;
        long x14773 = x14319[x14772];
        x14319[x14772] = x14752;
        x14320[x14752] = x14773;
      } else {
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x14781 = x14294;
      bool x14782 = !x14781;
      bool x14787 = x14782;
      if (x14782) {
        long x14783 = x14295;
        long x14784 = x12992;
        bool x14785 = x14783 < x14784;
        x14787 = x14785;
      }
      bool x14788 = x14787;
      if (!x14788) break;
      long x14790 = x14295;
      int* x14791 = x12994;
      int x14792 = x14791[x14790];
      int* x14793 = x12996;
      int x14794 = x14793[x14790];
      int* x14795 = x12998;
      int x14796 = x14795[x14790];
      double* x14801 = x13004;
      double x14802 = x14801[x14790];
      double* x14803 = x13006;
      double x14804 = x14803[x14790];
      x14295 = x14295 + 1;
      long x14825 = x14794 & x2034;
      long x14826 = x14319[x14825];
      long x14827 = x14826;
      long x14909 = x14792 & x2034;
      for (;;) {
        long x14828 = x14827;
        bool x14829 = x14828 != -1;
        if (!x14829) break;
        long x14831 = x14827;
        int* x14832 = x14301;
        int x14833 = x14832[x14831];
        long x14851 = x14320[x14831];
        x14827 = x14851;
        bool x14853 = x14833 == x14794;
        if (x14853) {
          long x14857 = x14380;
          int* x14876 = x14349;
          x14876[x14857] = x14792;
          int* x14880 = x14353;
          x14880[x14857] = x14796;
          double* x14886 = x14359;
          x14886[x14857] = x14802;
          double* x14888 = x14361;
          x14888[x14857] = x14804;
          x14380 = x14380 + 1L;
          long x14910 = x14381[x14909];
          x14381[x14909] = x14857;
          x14382[x14857] = x14910;
        } else {
        }
      }
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x14920 = x14326;
      bool x14921 = !x14920;
      bool x14926 = x14921;
      if (x14921) {
        long x14922 = x14327;
        long x14923 = x12641;
        bool x14924 = x14922 < x14923;
        x14926 = x14924;
      }
      bool x14927 = x14926;
      if (!x14927) break;
      long x14929 = x14327;
      int* x14930 = x12643;
      int x14931 = x14930[x14929];
      int* x14932 = x12645;
      int x14933 = x14932[x14929];
      long* x14938 = x12651;
      long x14939 = x14938[x14929];
      x14327 = x14327 + 1;
      bool x14950 = x14939 >= 19950101L;
      bool x14952 = x14950;
      if (x14950) {
        bool x14951 = x14939 <= 19961231L;
        x14952 = x14951;
      }
      bool x14953 = x14952;
      if (x14953) {
        long x14954 = x14931 & x2034;
        long x14955 = x14381[x14954];
        long x14956 = x14955;
        long x15088 = x14933 & x2034;
        for (;;) {
          long x14957 = x14956;
          bool x14958 = x14957 != -1;
          if (!x14958) break;
          long x14960 = x14956;
          int* x14979 = x14349;
          int x14980 = x14979[x14960];
          int* x14983 = x14353;
          int x14984 = x14983[x14960];
          double* x14989 = x14359;
          double x14990 = x14989[x14960];
          double* x14991 = x14361;
          double x14992 = x14991[x14960];
          long x15012 = x14382[x14960];
          x14956 = x15012;
          bool x15014 = x14980 == x14931;
          if (x15014) {
            long x15018 = x14459;
            int* x15041 = x14414;
            x15041[x15018] = x14984;
            double* x15047 = x14420;
            x15047[x15018] = x14990;
            double* x15049 = x14422;
            x15049[x15018] = x14992;
            int* x15071 = x14444;
            x15071[x15018] = x14933;
            long* x15077 = x14450;
            x15077[x15018] = x14939;
            x14459 = x14459 + 1L;
            long x15089 = x14460[x15088];
            x14460[x15088] = x15018;
            x14461[x15018] = x15089;
          } else {
          }
        }
      } else {
      }
    }
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x15101 = x14388;
      bool x15102 = !x15101;
      bool x15107 = x15102;
      if (x15102) {
        long x15103 = x14389;
        long x15104 = x13766;
        bool x15105 = x15103 < x15104;
        x15107 = x15105;
      }
      bool x15108 = x15107;
      if (!x15108) break;
      long x15110 = x14389;
      int* x15111 = x13768;
      int x15112 = x15111[x15110];
      int* x15117 = x13774;
      int x15118 = x15117[x15110];
      x14389 = x14389 + 1;
      long x15129 = x15112 & x2034;
      long x15130 = x14460[x15129];
      long x15131 = x15130;
      long x15211 = x15118 & x2034;
      for (;;) {
        long x15132 = x15131;
        bool x15133 = x15132 != -1;
        if (!x15133) break;
        long x15135 = x15131;
        int* x15158 = x14414;
        int x15159 = x15158[x15135];
        double* x15164 = x14420;
        double x15165 = x15164[x15135];
        double* x15166 = x14422;
        double x15167 = x15166[x15135];
        int* x15188 = x14444;
        int x15189 = x15188[x15135];
        long* x15194 = x14450;
        long x15195 = x15194[x15135];
        long x15205 = x14461[x15135];
        x15131 = x15205;
        bool x15207 = x15189 == x15112;
        if (x15207) {
          long x15212 = x14479[x15211];
          long x15213 = x15212;
          long x15253 = x15159 & x2034;
          long x15300 = x15195; // date
          long x15301 = x15300/10000;
          int x15302 = (int)x15301;
          long x15303 = x15302 & x802;
          double x15317 = 1.0 - x15167;
          double x15318 = x15165 * x15317;
          for (;;) {
            long x15214 = x15213;
            bool x15215 = x15214 != -1;
            if (!x15215) break;
            long x15217 = x15213;
            int* x15218 = x14471;
            int x15219 = x15218[x15217];
            int* x15222 = x14475;
            int x15223 = x15222[x15217];
            long x15227 = x14480[x15217];
            x15213 = x15227;
            bool x15229 = x15219 == x15118;
            if (x15229) {
              long x15233 = x15223 & x2034;
              long x15234 = x14497[x15233];
              long x15235 = x15234;
              for (;;) {
                long x15236 = x15235;
                bool x15237 = x15236 != -1;
                if (!x15237) break;
                long x15239 = x15235;
                int* x15240 = x14491;
                int x15241 = x15240[x15239];
                long x15247 = x14498[x15239];
                x15235 = x15247;
                bool x15249 = x15241 == x15223;
                if (x15249) {
                  long x15254 = x14522[x15253];
                  long x15255 = x15254;
                  for (;;) {
                    long x15256 = x15255;
                    bool x15257 = x15256 != -1;
                    if (!x15257) break;
                    long x15259 = x15255;
                    int* x15260 = x14508;
                    int x15261 = x15260[x15259];
                    int* x15266 = x14514;
                    int x15267 = x15266[x15259];
                    long x15275 = x14523[x15259];
                    x15255 = x15275;
                    bool x15277 = x15261 == x15159;
                    if (x15277) {
                      long x15282 = x15267 & x2034;
                      long x15283 = x14539[x15282];
                      long x15284 = x15283;
                      for (;;) {
                        long x15285 = x15284;
                        bool x15286 = x15285 != -1;
                        if (!x15286) break;
                        long x15288 = x15284;
                        char** x15289 = x14535;
                        char* x15290 = x15289[x15288];
                        int* x15291 = x14537;
                        int x15292 = x15291[x15288];
                        long x15294 = x14540[x15288];
                        x15284 = x15294;
                        bool x15296 = x15292 == x15267;
                        if (x15296) {
                          long x15304 = x15303;
                          struct Anon1074264013* x15305 = x14549;
                          struct Anon1074264013 x15306 = x15305[x15303];
                          struct Anon1074264013 x15307 = x15306;
                          bool x15308 = x15306.exists;;
                          bool x15313 = x15308;
                          if (x15308) {
                            struct Anon1074264013 x15309 = x15307;
                            int x15310 = x15309.key;;
                            bool x15311 = x15310 == x15302;
                            x15313 = x15311;
                          }
                          bool x15314 = x15313;
                          if (x15314) {
                            struct Anon189208763 x15315 = x15306.aggs;;
                            int x15325 = x15306.key;;
                            double x15316 = x15315._0;;
                            double x15319 = x15316 + x15318;
                            bool x15320 = strcmp(x15290,"INDONESIA") == 0;;
                            double x15323;
                            if (x15320) {
                              double x15321 = x15315._1;;
                              double x15322 = x15321 + x15318;
                              x15323 = x15322;
                            } else {
                              double x15321 = x15315._1;;
                              x15323 = x15321;
                            }
                            struct Anon189208763 x15324;
                            x15324._0 = x15319;
                            x15324._1 = x15323;
                            struct Anon1074264013 x15326;
                            x15326.exists = true;
                            x15326.key = x15325;
                            x15326.aggs = x15324;
                            x15305[x15303] = x15326;
                          } else {
                            bool x15320 = strcmp(x15290,"INDONESIA") == 0;;
                            double x15358;
                            if (x15320) {
                              x15358 = x15318;
                            } else {
                              x15358 = 0.0;
                            }
                            struct Anon189208763 x15359;
                            x15359._0 = x15318;
                            x15359._1 = x15358;
                            struct Anon1074264013 x15360;
                            x15360.exists = true;
                            x15360.key = x15302;
                            x15360.aggs = x15359;
                            for (;;) {
                              struct Anon1074264013 x15329 = x15307;
                              bool x15330 = x15329.exists;;
                              bool x15369;
                              if (x15330) {
                                int x15331 = x15329.key;;
                                bool x15332 = x15331 == x15302;
                                bool x15355;
                                if (x15332) {
                                  struct Anon189208763 x15333 = x15329.aggs;;
                                  long x15340 = x15304;
                                  struct Anon1074264013* x15342 = x14549;
                                  double x15334 = x15333._0;;
                                  double x15335 = x15334 + x15318;
                                  double x15338;
                                  if (x15320) {
                                    double x15336 = x15333._1;;
                                    double x15337 = x15336 + x15318;
                                    x15338 = x15337;
                                  } else {
                                    double x15336 = x15333._1;;
                                    x15338 = x15336;
                                  }
                                  struct Anon189208763 x15339;
                                  x15339._0 = x15335;
                                  x15339._1 = x15338;
                                  struct Anon1074264013 x15341;
                                  x15341.exists = true;
                                  x15341.key = x15331;
                                  x15341.aggs = x15339;
                                  x15342[x15340] = x15341;
                                  x15355 = false;
                                } else {
                                  long x15345 = x15304;
                                  long x15346 = x15345 + 1L;
                                  long x15347 = x15346 % x802;
                                  x15304 = x15347;
                                  struct Anon1074264013* x15349 = x14549;
                                  struct Anon1074264013 x15350 = x15349[x15347];
                                  x15307 = x15350;
                                  x15355 = true;
                                }
                                x15369 = x15355;
                              } else {
                                long x15357 = x15304;
                                struct Anon1074264013* x15361 = x14549;
                                x15361[x15357] = x15360;
                                long x15363 = x14550;
                                x14551[x15363] = x15357;
                                x14550 = x14550 + 1L;
                                x15369 = false;
                              }
                              if (!x15369) break;
                            }
                          }
                        } else {
                        }
                      }
                    } else {
                    }
                  }
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
    long x15398 = x14550;
    long x15400;
    for(x15400=0L; x15400 < x15398; x15400++) {
      long x15401 = x14551[x15400];
      struct Anon1074264013* x15402 = x14549;
      struct Anon1074264013 x15403 = x15402[x15401];
      int x15404 = x15403.key;;
      struct Anon189208763 x15405 = x15403.aggs;;
      if (x975) {
      } else {
        double x15406 = x15405._1;;
        double x15407 = x15405._0;;
        double x15408 = x15406 / x15407;
        printf("%d|%.5f\n",x15404,x15408);
        x14563 = x14563 + 1L;
      }
    }
    long x15419 = x14563;
    printf("(%d rows)\n",x15419);
    gettimeofday(&x15423, NULL);
    timeval_subtract(&x15424, &x15423, &x15422);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x15424.tv_sec * 1000) + (x15424.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
