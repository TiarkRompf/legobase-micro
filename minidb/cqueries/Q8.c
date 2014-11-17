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

struct Anon211179391 {
bool exists;
int key;
struct Anon189208763 aggs;
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

/************************ FUNCTIONS **************************/

/************************ MAIN BODY **************************/
int main(int x12101, char** x12102) {
  int x12103 = 0;
  int x12104 = 1048576;
  int x12105 = 0;
  int* x12106 = (int*)malloc(1048576 * sizeof(int));
  int* x12107 = x12106;
  char** x12108 = (char**)malloc(1048576 * sizeof(char*));
  char** x12109 = x12108;
  int* x12110 = (int*)malloc(1048576 * sizeof(int));
  int* x12111 = x12110;
  int x1512 = open("../databases/sf2/nation.tbl",0);
  int x1513 = fsize(x1512);
  char* x1514 = mmap(0, x1513, PROT_READ, MAP_FILE | MAP_SHARED, x1512, 0);
  for (;;) {
    int x12114 = x12103;
    bool x12115 = x12114 < x1513;
    if (!x12115) break;
    int x12118 = 0;
    for (;;) {
      int x12119 = x12103;
      char x12120 = x1514[x12119];
      bool x12121 = x12120 != '|';
      bool x12126 = x12121;
      if (x12121) {
        int x12122 = x12103;
        char x12123 = x1514[x12122];
        bool x12124 = x12123 != '\n';
        x12126 = x12124;
      }
      bool x12127 = x12126;
      if (!x12127) break;
      int x12129 = x12118;
      int x12131 = x12103;
      int x12130 = x12129 * 10;
      char x12132 = x1514[x12131];
      char x12133 = x12132 - '0';
      int x12134 = x12130 + x12133;
      x12118 = x12134;
      x12103 = x12103 + 1;
    }
    x12103 = x12103 + 1;
    int x12140 = x12118;
    int x12141 = x12103;
    for (;;) {
      int x12142 = x12103;
      char x12143 = x1514[x12142];
      bool x12144 = x12143 != '|';
      bool x12149 = x12144;
      if (x12144) {
        int x12145 = x12103;
        char x12146 = x1514[x12145];
        bool x12147 = x12146 != '\n';
        x12149 = x12147;
      }
      bool x12150 = x12149;
      if (!x12150) break;
      x12103 = x12103 + 1;
    }
    x12103 = x12103 + 1;
    int x12160 = 0;
    for (;;) {
      int x12161 = x12103;
      char x12162 = x1514[x12161];
      bool x12163 = x12162 != '|';
      bool x12168 = x12163;
      if (x12163) {
        int x12164 = x12103;
        char x12165 = x1514[x12164];
        bool x12166 = x12165 != '\n';
        x12168 = x12166;
      }
      bool x12169 = x12168;
      if (!x12169) break;
      int x12171 = x12160;
      int x12173 = x12103;
      int x12172 = x12171 * 10;
      char x12174 = x1514[x12173];
      char x12175 = x12174 - '0';
      int x12176 = x12172 + x12175;
      x12160 = x12176;
      x12103 = x12103 + 1;
    }
    x12103 = x12103 + 1;
    int x12182 = x12160;
    for (;;) {
      int x12184 = x12103;
      char x12185 = x1514[x12184];
      bool x12186 = x12185 != '|';
      bool x12191 = x12186;
      if (x12186) {
        int x12187 = x12103;
        char x12188 = x1514[x12187];
        bool x12189 = x12188 != '\n';
        x12191 = x12189;
      }
      bool x12192 = x12191;
      if (!x12192) break;
      x12103 = x12103 + 1;
    }
    x12103 = x12103 + 1;
    int x12202 = x12105;
    int x12203 = x12104;
    bool x12204 = x12202 == x12203;
    if (x12204) {
      int x12205 = x12203 * 4;
      x12104 = x12205;
      printf("buffer.resize %d\n",x12205);
      int* x12208 = x12107;
      int* x12209 = (int*)realloc(x12208,x12205 * sizeof(int));
      x12107 = x12209;
      char** x12211 = x12109;
      char** x12212 = (char**)realloc(x12211,x12205 * sizeof(char*));
      x12109 = x12212;
      int* x12214 = x12111;
      int* x12215 = (int*)realloc(x12214,x12205 * sizeof(int));
      x12111 = x12215;
    } else {
    }
    int* x12222 = x12107;
    x12222[x12202] = x12140;
    char** x12224 = x12109;
    char* x12158 = x1514+x12141;
    x12224[x12202] = x12158;
    int* x12226 = x12111;
    x12226[x12202] = x12182;
    x12105 = x12105 + 1;
  }
  int x12233 = 0;
  int x12234 = 1048576;
  int x12235 = 0;
  int* x12236 = (int*)malloc(1048576 * sizeof(int));
  int* x12237 = x12236;
  char** x12238 = (char**)malloc(1048576 * sizeof(char*));
  char** x12239 = x12238;
  int x1645 = open("../databases/sf2/region.tbl",0);
  int x1646 = fsize(x1645);
  char* x1647 = mmap(0, x1646, PROT_READ, MAP_FILE | MAP_SHARED, x1645, 0);
  for (;;) {
    int x12242 = x12233;
    bool x12243 = x12242 < x1646;
    if (!x12243) break;
    int x12246 = 0;
    for (;;) {
      int x12247 = x12233;
      char x12248 = x1647[x12247];
      bool x12249 = x12248 != '|';
      bool x12254 = x12249;
      if (x12249) {
        int x12250 = x12233;
        char x12251 = x1647[x12250];
        bool x12252 = x12251 != '\n';
        x12254 = x12252;
      }
      bool x12255 = x12254;
      if (!x12255) break;
      int x12257 = x12246;
      int x12259 = x12233;
      int x12258 = x12257 * 10;
      char x12260 = x1647[x12259];
      char x12261 = x12260 - '0';
      int x12262 = x12258 + x12261;
      x12246 = x12262;
      x12233 = x12233 + 1;
    }
    x12233 = x12233 + 1;
    int x12268 = x12246;
    int x12269 = x12233;
    for (;;) {
      int x12270 = x12233;
      char x12271 = x1647[x12270];
      bool x12272 = x12271 != '|';
      bool x12277 = x12272;
      if (x12272) {
        int x12273 = x12233;
        char x12274 = x1647[x12273];
        bool x12275 = x12274 != '\n';
        x12277 = x12275;
      }
      bool x12278 = x12277;
      if (!x12278) break;
      x12233 = x12233 + 1;
    }
    x12233 = x12233 + 1;
    for (;;) {
      int x12288 = x12233;
      char x12289 = x1647[x12288];
      bool x12290 = x12289 != '|';
      bool x12295 = x12290;
      if (x12290) {
        int x12291 = x12233;
        char x12292 = x1647[x12291];
        bool x12293 = x12292 != '\n';
        x12295 = x12293;
      }
      bool x12296 = x12295;
      if (!x12296) break;
      x12233 = x12233 + 1;
    }
    x12233 = x12233 + 1;
    int x12306 = x12235;
    int x12307 = x12234;
    bool x12308 = x12306 == x12307;
    if (x12308) {
      int x12309 = x12307 * 4;
      x12234 = x12309;
      printf("buffer.resize %d\n",x12309);
      int* x12312 = x12237;
      int* x12313 = (int*)realloc(x12312,x12309 * sizeof(int));
      x12237 = x12313;
      char** x12315 = x12239;
      char** x12316 = (char**)realloc(x12315,x12309 * sizeof(char*));
      x12239 = x12316;
    } else {
    }
    int* x12323 = x12237;
    x12323[x12306] = x12268;
    char** x12325 = x12239;
    char* x12286 = x1647+x12269;
    x12325[x12306] = x12286;
    x12235 = x12235 + 1;
  }
  int x12332 = 0;
  int x12333 = 1048576;
  int x12334 = 0;
  int* x12335 = (int*)malloc(1048576 * sizeof(int));
  int* x12336 = x12335;
  char** x12343 = (char**)malloc(1048576 * sizeof(char*));
  char** x12344 = x12343;
  int x995 = open("../databases/sf2/part.tbl",0);
  int x996 = fsize(x995);
  char* x997 = mmap(0, x996, PROT_READ, MAP_FILE | MAP_SHARED, x995, 0);
  for (;;) {
    int x12354 = x12332;
    bool x12355 = x12354 < x996;
    if (!x12355) break;
    int x12358 = 0;
    for (;;) {
      int x12359 = x12332;
      char x12360 = x997[x12359];
      bool x12361 = x12360 != '|';
      bool x12366 = x12361;
      if (x12361) {
        int x12362 = x12332;
        char x12363 = x997[x12362];
        bool x12364 = x12363 != '\n';
        x12366 = x12364;
      }
      bool x12367 = x12366;
      if (!x12367) break;
      int x12369 = x12358;
      int x12371 = x12332;
      int x12370 = x12369 * 10;
      char x12372 = x997[x12371];
      char x12373 = x12372 - '0';
      int x12374 = x12370 + x12373;
      x12358 = x12374;
      x12332 = x12332 + 1;
    }
    x12332 = x12332 + 1;
    int x12380 = x12358;
    for (;;) {
      int x12382 = x12332;
      char x12383 = x997[x12382];
      bool x12384 = x12383 != '|';
      bool x12389 = x12384;
      if (x12384) {
        int x12385 = x12332;
        char x12386 = x997[x12385];
        bool x12387 = x12386 != '\n';
        x12389 = x12387;
      }
      bool x12390 = x12389;
      if (!x12390) break;
      x12332 = x12332 + 1;
    }
    x12332 = x12332 + 1;
    for (;;) {
      int x12400 = x12332;
      char x12401 = x997[x12400];
      bool x12402 = x12401 != '|';
      bool x12407 = x12402;
      if (x12402) {
        int x12403 = x12332;
        char x12404 = x997[x12403];
        bool x12405 = x12404 != '\n';
        x12407 = x12405;
      }
      bool x12408 = x12407;
      if (!x12408) break;
      x12332 = x12332 + 1;
    }
    x12332 = x12332 + 1;
    for (;;) {
      int x12418 = x12332;
      char x12419 = x997[x12418];
      bool x12420 = x12419 != '|';
      bool x12425 = x12420;
      if (x12420) {
        int x12421 = x12332;
        char x12422 = x997[x12421];
        bool x12423 = x12422 != '\n';
        x12425 = x12423;
      }
      bool x12426 = x12425;
      if (!x12426) break;
      x12332 = x12332 + 1;
    }
    x12332 = x12332 + 1;
    int x12435 = x12332;
    for (;;) {
      int x12436 = x12332;
      char x12437 = x997[x12436];
      bool x12438 = x12437 != '|';
      bool x12443 = x12438;
      if (x12438) {
        int x12439 = x12332;
        char x12440 = x997[x12439];
        bool x12441 = x12440 != '\n';
        x12443 = x12441;
      }
      bool x12444 = x12443;
      if (!x12444) break;
      x12332 = x12332 + 1;
    }
    x12332 = x12332 + 1;
    for (;;) {
      int x12455 = x12332;
      char x12456 = x997[x12455];
      bool x12457 = x12456 != '|';
      bool x12462 = x12457;
      if (x12457) {
        int x12458 = x12332;
        char x12459 = x997[x12458];
        bool x12460 = x12459 != '\n';
        x12462 = x12460;
      }
      bool x12463 = x12462;
      if (!x12463) break;
      x12332 = x12332 + 1;
    }
    x12332 = x12332 + 1;
    for (;;) {
      int x12478 = x12332;
      char x12479 = x997[x12478];
      bool x12480 = x12479 != '|';
      bool x12485 = x12480;
      if (x12480) {
        int x12481 = x12332;
        char x12482 = x997[x12481];
        bool x12483 = x12482 != '\n';
        x12485 = x12483;
      }
      bool x12486 = x12485;
      if (!x12486) break;
      x12332 = x12332 + 1;
    }
    x12332 = x12332 + 1;
    for (;;) {
      int x12498 = x12332;
      char x12499 = x997[x12498];
      bool x12500 = x12499 != '.';
      bool x12505 = x12500;
      if (x12500) {
        int x12501 = x12332;
        char x12502 = x997[x12501];
        bool x12503 = x12502 != '|';
        x12505 = x12503;
      }
      bool x12506 = x12505;
      bool x12511 = x12506;
      if (x12506) {
        int x12507 = x12332;
        char x12508 = x997[x12507];
        bool x12509 = x12508 != '\n';
        x12511 = x12509;
      }
      bool x12512 = x12511;
      if (!x12512) break;
      x12332 = x12332 + 1;
    }
    int x12524 = x12332;
    char x12525 = x997[x12524];
    bool x12526 = x12525 == '.';
    if (x12526) {
      x12332 = x12332 + 1;
      for (;;) {
        int x12528 = x12332;
        char x12529 = x997[x12528];
        bool x12530 = x12529 != '|';
        bool x12535 = x12530;
        if (x12530) {
          int x12531 = x12332;
          char x12532 = x997[x12531];
          bool x12533 = x12532 != '\n';
          x12535 = x12533;
        }
        bool x12536 = x12535;
        if (!x12536) break;
        x12332 = x12332 + 1;
      }
    } else {
    }
    x12332 = x12332 + 1;
    for (;;) {
      int x12561 = x12332;
      char x12562 = x997[x12561];
      bool x12563 = x12562 != '|';
      bool x12568 = x12563;
      if (x12563) {
        int x12564 = x12332;
        char x12565 = x997[x12564];
        bool x12566 = x12565 != '\n';
        x12568 = x12566;
      }
      bool x12569 = x12568;
      if (!x12569) break;
      x12332 = x12332 + 1;
    }
    x12332 = x12332 + 1;
    int x12579 = x12334;
    int x12580 = x12333;
    bool x12581 = x12579 == x12580;
    if (x12581) {
      int x12582 = x12580 * 4;
      x12333 = x12582;
      printf("buffer.resize %d\n",x12582);
      int* x12585 = x12336;
      int* x12586 = (int*)realloc(x12585,x12582 * sizeof(int));
      x12336 = x12586;
      char** x12597 = x12344;
      char** x12598 = (char**)realloc(x12597,x12582 * sizeof(char*));
      x12344 = x12598;
    } else {
    }
    int* x12614 = x12336;
    x12614[x12579] = x12380;
    char** x12622 = x12344;
    char* x12452 = x997+x12435;
    x12622[x12579] = x12452;
    x12334 = x12334 + 1;
  }
  int x12635 = 0;
  int x12636 = 1048576;
  int x12637 = 0;
  int* x12638 = (int*)malloc(1048576 * sizeof(int));
  int* x12639 = x12638;
  int* x12640 = (int*)malloc(1048576 * sizeof(int));
  int* x12641 = x12640;
  long* x12646 = (long*)malloc(1048576 * sizeof(long));
  long* x12647 = x12646;
  int x3366 = open("../databases/sf2/orders.tbl",0);
  int x3367 = fsize(x3366);
  char* x3368 = mmap(0, x3367, PROT_READ, MAP_FILE | MAP_SHARED, x3366, 0);
  for (;;) {
    int x12656 = x12635;
    bool x12657 = x12656 < x3367;
    if (!x12657) break;
    int x12660 = 0;
    for (;;) {
      int x12661 = x12635;
      char x12662 = x3368[x12661];
      bool x12663 = x12662 != '|';
      bool x12668 = x12663;
      if (x12663) {
        int x12664 = x12635;
        char x12665 = x3368[x12664];
        bool x12666 = x12665 != '\n';
        x12668 = x12666;
      }
      bool x12669 = x12668;
      if (!x12669) break;
      int x12671 = x12660;
      int x12673 = x12635;
      int x12672 = x12671 * 10;
      char x12674 = x3368[x12673];
      char x12675 = x12674 - '0';
      int x12676 = x12672 + x12675;
      x12660 = x12676;
      x12635 = x12635 + 1;
    }
    x12635 = x12635 + 1;
    int x12682 = x12660;
    int x12684 = 0;
    for (;;) {
      int x12685 = x12635;
      char x12686 = x3368[x12685];
      bool x12687 = x12686 != '|';
      bool x12692 = x12687;
      if (x12687) {
        int x12688 = x12635;
        char x12689 = x3368[x12688];
        bool x12690 = x12689 != '\n';
        x12692 = x12690;
      }
      bool x12693 = x12692;
      if (!x12693) break;
      int x12695 = x12684;
      int x12697 = x12635;
      int x12696 = x12695 * 10;
      char x12698 = x3368[x12697];
      char x12699 = x12698 - '0';
      int x12700 = x12696 + x12699;
      x12684 = x12700;
      x12635 = x12635 + 1;
    }
    x12635 = x12635 + 1;
    int x12706 = x12684;
    x12635 = x12635 + 2;
    for (;;) {
      int x12713 = x12635;
      char x12714 = x3368[x12713];
      bool x12715 = x12714 != '.';
      bool x12720 = x12715;
      if (x12715) {
        int x12716 = x12635;
        char x12717 = x3368[x12716];
        bool x12718 = x12717 != '|';
        x12720 = x12718;
      }
      bool x12721 = x12720;
      bool x12726 = x12721;
      if (x12721) {
        int x12722 = x12635;
        char x12723 = x3368[x12722];
        bool x12724 = x12723 != '\n';
        x12726 = x12724;
      }
      bool x12727 = x12726;
      if (!x12727) break;
      x12635 = x12635 + 1;
    }
    int x12739 = x12635;
    char x12740 = x3368[x12739];
    bool x12741 = x12740 == '.';
    if (x12741) {
      x12635 = x12635 + 1;
      for (;;) {
        int x12743 = x12635;
        char x12744 = x3368[x12743];
        bool x12745 = x12744 != '|';
        bool x12750 = x12745;
        if (x12745) {
          int x12746 = x12635;
          char x12747 = x3368[x12746];
          bool x12748 = x12747 != '\n';
          x12750 = x12748;
        }
        bool x12751 = x12750;
        if (!x12751) break;
        x12635 = x12635 + 1;
      }
    } else {
    }
    x12635 = x12635 + 1;
    int x12776 = 0;
    for (;;) {
      int x12777 = x12635;
      char x12778 = x3368[x12777];
      bool x12779 = x12778 != '-';
      bool x12784 = x12779;
      if (x12779) {
        int x12780 = x12635;
        char x12781 = x3368[x12780];
        bool x12782 = x12781 != '\n';
        x12784 = x12782;
      }
      bool x12785 = x12784;
      if (!x12785) break;
      int x12787 = x12776;
      int x12789 = x12635;
      int x12788 = x12787 * 10;
      char x12790 = x3368[x12789];
      char x12791 = x12790 - '0';
      int x12792 = x12788 + x12791;
      x12776 = x12792;
      x12635 = x12635 + 1;
    }
    x12635 = x12635 + 1;
    int x12798 = x12776;
    int x12800 = 0;
    for (;;) {
      int x12801 = x12635;
      char x12802 = x3368[x12801];
      bool x12803 = x12802 != '-';
      bool x12808 = x12803;
      if (x12803) {
        int x12804 = x12635;
        char x12805 = x3368[x12804];
        bool x12806 = x12805 != '\n';
        x12808 = x12806;
      }
      bool x12809 = x12808;
      if (!x12809) break;
      int x12811 = x12800;
      int x12813 = x12635;
      int x12812 = x12811 * 10;
      char x12814 = x3368[x12813];
      char x12815 = x12814 - '0';
      int x12816 = x12812 + x12815;
      x12800 = x12816;
      x12635 = x12635 + 1;
    }
    x12635 = x12635 + 1;
    int x12822 = x12800;
    int x12824 = 0;
    for (;;) {
      int x12825 = x12635;
      char x12826 = x3368[x12825];
      bool x12827 = x12826 != '|';
      bool x12832 = x12827;
      if (x12827) {
        int x12828 = x12635;
        char x12829 = x3368[x12828];
        bool x12830 = x12829 != '\n';
        x12832 = x12830;
      }
      bool x12833 = x12832;
      if (!x12833) break;
      int x12835 = x12824;
      int x12837 = x12635;
      int x12836 = x12835 * 10;
      char x12838 = x3368[x12837];
      char x12839 = x12838 - '0';
      int x12840 = x12836 + x12839;
      x12824 = x12840;
      x12635 = x12635 + 1;
    }
    x12635 = x12635 + 1;
    int x12846 = x12824;
    for (;;) {
      int x12852 = x12635;
      char x12853 = x3368[x12852];
      bool x12854 = x12853 != '|';
      bool x12859 = x12854;
      if (x12854) {
        int x12855 = x12635;
        char x12856 = x3368[x12855];
        bool x12857 = x12856 != '\n';
        x12859 = x12857;
      }
      bool x12860 = x12859;
      if (!x12860) break;
      x12635 = x12635 + 1;
    }
    x12635 = x12635 + 1;
    for (;;) {
      int x12870 = x12635;
      char x12871 = x3368[x12870];
      bool x12872 = x12871 != '|';
      bool x12877 = x12872;
      if (x12872) {
        int x12873 = x12635;
        char x12874 = x3368[x12873];
        bool x12875 = x12874 != '\n';
        x12877 = x12875;
      }
      bool x12878 = x12877;
      if (!x12878) break;
      x12635 = x12635 + 1;
    }
    x12635 = x12635 + 1;
    for (;;) {
      int x12889 = x12635;
      char x12890 = x3368[x12889];
      bool x12891 = x12890 != '|';
      bool x12896 = x12891;
      if (x12891) {
        int x12892 = x12635;
        char x12893 = x3368[x12892];
        bool x12894 = x12893 != '\n';
        x12896 = x12894;
      }
      bool x12897 = x12896;
      if (!x12897) break;
      x12635 = x12635 + 1;
    }
    x12635 = x12635 + 1;
    for (;;) {
      int x12912 = x12635;
      char x12913 = x3368[x12912];
      bool x12914 = x12913 != '|';
      bool x12919 = x12914;
      if (x12914) {
        int x12915 = x12635;
        char x12916 = x3368[x12915];
        bool x12917 = x12916 != '\n';
        x12919 = x12917;
      }
      bool x12920 = x12919;
      if (!x12920) break;
      x12635 = x12635 + 1;
    }
    x12635 = x12635 + 1;
    int x12930 = x12637;
    int x12931 = x12636;
    bool x12932 = x12930 == x12931;
    if (x12932) {
      int x12933 = x12931 * 4;
      x12636 = x12933;
      printf("buffer.resize %d\n",x12933);
      int* x12936 = x12639;
      int* x12937 = (int*)realloc(x12936,x12933 * sizeof(int));
      x12639 = x12937;
      int* x12939 = x12641;
      int* x12940 = (int*)realloc(x12939,x12933 * sizeof(int));
      x12641 = x12940;
      long* x12948 = x12647;
      long* x12949 = (long*)realloc(x12948,x12933 * sizeof(long));
      x12647 = x12949;
    } else {
    }
    int* x12965 = x12639;
    x12965[x12930] = x12682;
    int* x12967 = x12641;
    x12967[x12930] = x12706;
    long* x12973 = x12647;
    long x12847 = x12798 * 10000L;
    long x12848 = x12822 * 100L;
    long x12849 = x12847 + x12848;
    long x12850 = x12849 + x12846;
    x12973[x12930] = x12850;
    x12637 = x12637 + 1;
  }
  int x12986 = 0;
  int x12987 = 1048576;
  int x12988 = 0;
  int* x12989 = (int*)malloc(1048576 * sizeof(int));
  int* x12990 = x12989;
  int* x12991 = (int*)malloc(1048576 * sizeof(int));
  int* x12992 = x12991;
  int* x12993 = (int*)malloc(1048576 * sizeof(int));
  int* x12994 = x12993;
  double* x12999 = (double*)malloc(1048576 * sizeof(double));
  double* x13000 = x12999;
  double* x13001 = (double*)malloc(1048576 * sizeof(double));
  double* x13002 = x13001;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  int x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    int x13021 = x12986;
    bool x13022 = x13021 < x3;
    if (!x13022) break;
    int x13025 = 0;
    for (;;) {
      int x13026 = x12986;
      char x13027 = x4[x13026];
      bool x13028 = x13027 != '|';
      bool x13033 = x13028;
      if (x13028) {
        int x13029 = x12986;
        char x13030 = x4[x13029];
        bool x13031 = x13030 != '\n';
        x13033 = x13031;
      }
      bool x13034 = x13033;
      if (!x13034) break;
      int x13036 = x13025;
      int x13038 = x12986;
      int x13037 = x13036 * 10;
      char x13039 = x4[x13038];
      char x13040 = x13039 - '0';
      int x13041 = x13037 + x13040;
      x13025 = x13041;
      x12986 = x12986 + 1;
    }
    x12986 = x12986 + 1;
    int x13047 = x13025;
    int x13049 = 0;
    for (;;) {
      int x13050 = x12986;
      char x13051 = x4[x13050];
      bool x13052 = x13051 != '|';
      bool x13057 = x13052;
      if (x13052) {
        int x13053 = x12986;
        char x13054 = x4[x13053];
        bool x13055 = x13054 != '\n';
        x13057 = x13055;
      }
      bool x13058 = x13057;
      if (!x13058) break;
      int x13060 = x13049;
      int x13062 = x12986;
      int x13061 = x13060 * 10;
      char x13063 = x4[x13062];
      char x13064 = x13063 - '0';
      int x13065 = x13061 + x13064;
      x13049 = x13065;
      x12986 = x12986 + 1;
    }
    x12986 = x12986 + 1;
    int x13071 = x13049;
    int x13073 = 0;
    for (;;) {
      int x13074 = x12986;
      char x13075 = x4[x13074];
      bool x13076 = x13075 != '|';
      bool x13081 = x13076;
      if (x13076) {
        int x13077 = x12986;
        char x13078 = x4[x13077];
        bool x13079 = x13078 != '\n';
        x13081 = x13079;
      }
      bool x13082 = x13081;
      if (!x13082) break;
      int x13084 = x13073;
      int x13086 = x12986;
      int x13085 = x13084 * 10;
      char x13087 = x4[x13086];
      char x13088 = x13087 - '0';
      int x13089 = x13085 + x13088;
      x13073 = x13089;
      x12986 = x12986 + 1;
    }
    x12986 = x12986 + 1;
    int x13095 = x13073;
    for (;;) {
      int x13098 = x12986;
      char x13099 = x4[x13098];
      bool x13100 = x13099 != '|';
      bool x13105 = x13100;
      if (x13100) {
        int x13101 = x12986;
        char x13102 = x4[x13101];
        bool x13103 = x13102 != '\n';
        x13105 = x13103;
      }
      bool x13106 = x13105;
      if (!x13106) break;
      x12986 = x12986 + 1;
    }
    x12986 = x12986 + 1;
    for (;;) {
      int x13123 = x12986;
      char x13124 = x4[x13123];
      bool x13125 = x13124 != '.';
      bool x13130 = x13125;
      if (x13125) {
        int x13126 = x12986;
        char x13127 = x4[x13126];
        bool x13128 = x13127 != '|';
        x13130 = x13128;
      }
      bool x13131 = x13130;
      bool x13136 = x13131;
      if (x13131) {
        int x13132 = x12986;
        char x13133 = x4[x13132];
        bool x13134 = x13133 != '\n';
        x13136 = x13134;
      }
      bool x13137 = x13136;
      if (!x13137) break;
      x12986 = x12986 + 1;
    }
    int x13149 = x12986;
    char x13150 = x4[x13149];
    bool x13151 = x13150 == '.';
    if (x13151) {
      x12986 = x12986 + 1;
      for (;;) {
        int x13153 = x12986;
        char x13154 = x4[x13153];
        bool x13155 = x13154 != '|';
        bool x13160 = x13155;
        if (x13155) {
          int x13156 = x12986;
          char x13157 = x4[x13156];
          bool x13158 = x13157 != '\n';
          x13160 = x13158;
        }
        bool x13161 = x13160;
        if (!x13161) break;
        x12986 = x12986 + 1;
      }
    } else {
    }
    x12986 = x12986 + 1;
    int x13186 = 0;
    int x13187 = 1;
    for (;;) {
      int x13188 = x12986;
      char x13189 = x4[x13188];
      bool x13190 = x13189 != '.';
      bool x13195 = x13190;
      if (x13190) {
        int x13191 = x12986;
        char x13192 = x4[x13191];
        bool x13193 = x13192 != '|';
        x13195 = x13193;
      }
      bool x13196 = x13195;
      bool x13201 = x13196;
      if (x13196) {
        int x13197 = x12986;
        char x13198 = x4[x13197];
        bool x13199 = x13198 != '\n';
        x13201 = x13199;
      }
      bool x13202 = x13201;
      if (!x13202) break;
      int x13204 = x13186;
      int x13206 = x12986;
      int x13205 = x13204 * 10;
      char x13207 = x4[x13206];
      char x13208 = x13207 - '0';
      int x13209 = x13205 + x13208;
      x13186 = x13209;
      x12986 = x12986 + 1;
    }
    int x13214 = x12986;
    char x13215 = x4[x13214];
    bool x13216 = x13215 == '.';
    if (x13216) {
      x12986 = x12986 + 1;
      for (;;) {
        int x13218 = x12986;
        char x13219 = x4[x13218];
        bool x13220 = x13219 != '|';
        bool x13225 = x13220;
        if (x13220) {
          int x13221 = x12986;
          char x13222 = x4[x13221];
          bool x13223 = x13222 != '\n';
          x13225 = x13223;
        }
        bool x13226 = x13225;
        if (!x13226) break;
        int x13228 = x13186;
        int x13230 = x12986;
        int x13229 = x13228 * 10;
        char x13231 = x4[x13230];
        char x13232 = x13231 - '0';
        int x13233 = x13229 + x13232;
        x13186 = x13233;
        int x13235 = x13187;
        int x13236 = x13235 * 10;
        x13187 = x13236;
        x12986 = x12986 + 1;
      }
    } else {
    }
    x12986 = x12986 + 1;
    int x13245 = x13186;
    int x13247 = x13187;
    int x13251 = 0;
    int x13252 = 1;
    for (;;) {
      int x13253 = x12986;
      char x13254 = x4[x13253];
      bool x13255 = x13254 != '.';
      bool x13260 = x13255;
      if (x13255) {
        int x13256 = x12986;
        char x13257 = x4[x13256];
        bool x13258 = x13257 != '|';
        x13260 = x13258;
      }
      bool x13261 = x13260;
      bool x13266 = x13261;
      if (x13261) {
        int x13262 = x12986;
        char x13263 = x4[x13262];
        bool x13264 = x13263 != '\n';
        x13266 = x13264;
      }
      bool x13267 = x13266;
      if (!x13267) break;
      int x13269 = x13251;
      int x13271 = x12986;
      int x13270 = x13269 * 10;
      char x13272 = x4[x13271];
      char x13273 = x13272 - '0';
      int x13274 = x13270 + x13273;
      x13251 = x13274;
      x12986 = x12986 + 1;
    }
    int x13279 = x12986;
    char x13280 = x4[x13279];
    bool x13281 = x13280 == '.';
    if (x13281) {
      x12986 = x12986 + 1;
      for (;;) {
        int x13283 = x12986;
        char x13284 = x4[x13283];
        bool x13285 = x13284 != '|';
        bool x13290 = x13285;
        if (x13285) {
          int x13286 = x12986;
          char x13287 = x4[x13286];
          bool x13288 = x13287 != '\n';
          x13290 = x13288;
        }
        bool x13291 = x13290;
        if (!x13291) break;
        int x13293 = x13251;
        int x13295 = x12986;
        int x13294 = x13293 * 10;
        char x13296 = x4[x13295];
        char x13297 = x13296 - '0';
        int x13298 = x13294 + x13297;
        x13251 = x13298;
        int x13300 = x13252;
        int x13301 = x13300 * 10;
        x13252 = x13301;
        x12986 = x12986 + 1;
      }
    } else {
    }
    x12986 = x12986 + 1;
    int x13310 = x13251;
    int x13312 = x13252;
    for (;;) {
      int x13318 = x12986;
      char x13319 = x4[x13318];
      bool x13320 = x13319 != '.';
      bool x13325 = x13320;
      if (x13320) {
        int x13321 = x12986;
        char x13322 = x4[x13321];
        bool x13323 = x13322 != '|';
        x13325 = x13323;
      }
      bool x13326 = x13325;
      bool x13331 = x13326;
      if (x13326) {
        int x13327 = x12986;
        char x13328 = x4[x13327];
        bool x13329 = x13328 != '\n';
        x13331 = x13329;
      }
      bool x13332 = x13331;
      if (!x13332) break;
      x12986 = x12986 + 1;
    }
    int x13344 = x12986;
    char x13345 = x4[x13344];
    bool x13346 = x13345 == '.';
    if (x13346) {
      x12986 = x12986 + 1;
      for (;;) {
        int x13348 = x12986;
        char x13349 = x4[x13348];
        bool x13350 = x13349 != '|';
        bool x13355 = x13350;
        if (x13350) {
          int x13351 = x12986;
          char x13352 = x4[x13351];
          bool x13353 = x13352 != '\n';
          x13355 = x13353;
        }
        bool x13356 = x13355;
        if (!x13356) break;
        x12986 = x12986 + 1;
      }
    } else {
    }
    x12986 = x12986 + 1;
    x12986 = x12986 + 2;
    x12986 = x12986 + 2;
    for (;;) {
      int x13388 = x12986;
      char x13389 = x4[x13388];
      bool x13390 = x13389 != '-';
      bool x13395 = x13390;
      if (x13390) {
        int x13391 = x12986;
        char x13392 = x4[x13391];
        bool x13393 = x13392 != '\n';
        x13395 = x13393;
      }
      bool x13396 = x13395;
      if (!x13396) break;
      x12986 = x12986 + 1;
    }
    x12986 = x12986 + 1;
    for (;;) {
      int x13412 = x12986;
      char x13413 = x4[x13412];
      bool x13414 = x13413 != '-';
      bool x13419 = x13414;
      if (x13414) {
        int x13415 = x12986;
        char x13416 = x4[x13415];
        bool x13417 = x13416 != '\n';
        x13419 = x13417;
      }
      bool x13420 = x13419;
      if (!x13420) break;
      x12986 = x12986 + 1;
    }
    x12986 = x12986 + 1;
    for (;;) {
      int x13436 = x12986;
      char x13437 = x4[x13436];
      bool x13438 = x13437 != '|';
      bool x13443 = x13438;
      if (x13438) {
        int x13439 = x12986;
        char x13440 = x4[x13439];
        bool x13441 = x13440 != '\n';
        x13443 = x13441;
      }
      bool x13444 = x13443;
      if (!x13444) break;
      x12986 = x12986 + 1;
    }
    x12986 = x12986 + 1;
    for (;;) {
      int x13464 = x12986;
      char x13465 = x4[x13464];
      bool x13466 = x13465 != '-';
      bool x13471 = x13466;
      if (x13466) {
        int x13467 = x12986;
        char x13468 = x4[x13467];
        bool x13469 = x13468 != '\n';
        x13471 = x13469;
      }
      bool x13472 = x13471;
      if (!x13472) break;
      x12986 = x12986 + 1;
    }
    x12986 = x12986 + 1;
    for (;;) {
      int x13488 = x12986;
      char x13489 = x4[x13488];
      bool x13490 = x13489 != '-';
      bool x13495 = x13490;
      if (x13490) {
        int x13491 = x12986;
        char x13492 = x4[x13491];
        bool x13493 = x13492 != '\n';
        x13495 = x13493;
      }
      bool x13496 = x13495;
      if (!x13496) break;
      x12986 = x12986 + 1;
    }
    x12986 = x12986 + 1;
    for (;;) {
      int x13512 = x12986;
      char x13513 = x4[x13512];
      bool x13514 = x13513 != '|';
      bool x13519 = x13514;
      if (x13514) {
        int x13515 = x12986;
        char x13516 = x4[x13515];
        bool x13517 = x13516 != '\n';
        x13519 = x13517;
      }
      bool x13520 = x13519;
      if (!x13520) break;
      x12986 = x12986 + 1;
    }
    x12986 = x12986 + 1;
    for (;;) {
      int x13540 = x12986;
      char x13541 = x4[x13540];
      bool x13542 = x13541 != '-';
      bool x13547 = x13542;
      if (x13542) {
        int x13543 = x12986;
        char x13544 = x4[x13543];
        bool x13545 = x13544 != '\n';
        x13547 = x13545;
      }
      bool x13548 = x13547;
      if (!x13548) break;
      x12986 = x12986 + 1;
    }
    x12986 = x12986 + 1;
    for (;;) {
      int x13564 = x12986;
      char x13565 = x4[x13564];
      bool x13566 = x13565 != '-';
      bool x13571 = x13566;
      if (x13566) {
        int x13567 = x12986;
        char x13568 = x4[x13567];
        bool x13569 = x13568 != '\n';
        x13571 = x13569;
      }
      bool x13572 = x13571;
      if (!x13572) break;
      x12986 = x12986 + 1;
    }
    x12986 = x12986 + 1;
    for (;;) {
      int x13588 = x12986;
      char x13589 = x4[x13588];
      bool x13590 = x13589 != '|';
      bool x13595 = x13590;
      if (x13590) {
        int x13591 = x12986;
        char x13592 = x4[x13591];
        bool x13593 = x13592 != '\n';
        x13595 = x13593;
      }
      bool x13596 = x13595;
      if (!x13596) break;
      x12986 = x12986 + 1;
    }
    x12986 = x12986 + 1;
    for (;;) {
      int x13615 = x12986;
      char x13616 = x4[x13615];
      bool x13617 = x13616 != '|';
      bool x13622 = x13617;
      if (x13617) {
        int x13618 = x12986;
        char x13619 = x4[x13618];
        bool x13620 = x13619 != '\n';
        x13622 = x13620;
      }
      bool x13623 = x13622;
      if (!x13623) break;
      x12986 = x12986 + 1;
    }
    x12986 = x12986 + 1;
    for (;;) {
      int x13633 = x12986;
      char x13634 = x4[x13633];
      bool x13635 = x13634 != '|';
      bool x13640 = x13635;
      if (x13635) {
        int x13636 = x12986;
        char x13637 = x4[x13636];
        bool x13638 = x13637 != '\n';
        x13640 = x13638;
      }
      bool x13641 = x13640;
      if (!x13641) break;
      x12986 = x12986 + 1;
    }
    x12986 = x12986 + 1;
    for (;;) {
      int x13651 = x12986;
      char x13652 = x4[x13651];
      bool x13653 = x13652 != '|';
      bool x13658 = x13653;
      if (x13653) {
        int x13654 = x12986;
        char x13655 = x4[x13654];
        bool x13656 = x13655 != '\n';
        x13658 = x13656;
      }
      bool x13659 = x13658;
      if (!x13659) break;
      x12986 = x12986 + 1;
    }
    x12986 = x12986 + 1;
    int x13669 = x12988;
    int x13670 = x12987;
    bool x13671 = x13669 == x13670;
    if (x13671) {
      int x13672 = x13670 * 4;
      x12987 = x13672;
      printf("buffer.resize %d\n",x13672);
      int* x13675 = x12990;
      int* x13676 = (int*)realloc(x13675,x13672 * sizeof(int));
      x12990 = x13676;
      int* x13678 = x12992;
      int* x13679 = (int*)realloc(x13678,x13672 * sizeof(int));
      x12992 = x13679;
      int* x13681 = x12994;
      int* x13682 = (int*)realloc(x13681,x13672 * sizeof(int));
      x12994 = x13682;
      double* x13690 = x13000;
      double* x13691 = (double*)realloc(x13690,x13672 * sizeof(double));
      x13000 = x13691;
      double* x13693 = x13002;
      double* x13694 = (double*)realloc(x13693,x13672 * sizeof(double));
      x13002 = x13694;
    } else {
    }
    int* x13725 = x12990;
    x13725[x13669] = x13047;
    int* x13727 = x12992;
    x13727[x13669] = x13071;
    int* x13729 = x12994;
    x13729[x13669] = x13095;
    double* x13735 = x13000;
    double x13246 = (double)x13245;
    double x13248 = (double)x13247;
    double x13249 = x13246 / x13248;
    x13735[x13669] = x13249;
    double* x13737 = x13002;
    double x13311 = (double)x13310;
    double x13313 = (double)x13312;
    double x13314 = x13311 / x13313;
    x13737[x13669] = x13314;
    x12988 = x12988 + 1;
  }
  int x13760 = 0;
  int x13761 = 1048576;
  int x13762 = 0;
  int* x13763 = (int*)malloc(1048576 * sizeof(int));
  int* x13764 = x13763;
  int* x13769 = (int*)malloc(1048576 * sizeof(int));
  int* x13770 = x13769;
  int x3720 = open("../databases/sf2/customer.tbl",0);
  int x3721 = fsize(x3720);
  char* x3722 = mmap(0, x3721, PROT_READ, MAP_FILE | MAP_SHARED, x3720, 0);
  for (;;) {
    int x13779 = x13760;
    bool x13780 = x13779 < x3721;
    if (!x13780) break;
    int x13783 = 0;
    for (;;) {
      int x13784 = x13760;
      char x13785 = x3722[x13784];
      bool x13786 = x13785 != '|';
      bool x13791 = x13786;
      if (x13786) {
        int x13787 = x13760;
        char x13788 = x3722[x13787];
        bool x13789 = x13788 != '\n';
        x13791 = x13789;
      }
      bool x13792 = x13791;
      if (!x13792) break;
      int x13794 = x13783;
      int x13796 = x13760;
      int x13795 = x13794 * 10;
      char x13797 = x3722[x13796];
      char x13798 = x13797 - '0';
      int x13799 = x13795 + x13798;
      x13783 = x13799;
      x13760 = x13760 + 1;
    }
    x13760 = x13760 + 1;
    int x13805 = x13783;
    for (;;) {
      int x13807 = x13760;
      char x13808 = x3722[x13807];
      bool x13809 = x13808 != '|';
      bool x13814 = x13809;
      if (x13809) {
        int x13810 = x13760;
        char x13811 = x3722[x13810];
        bool x13812 = x13811 != '\n';
        x13814 = x13812;
      }
      bool x13815 = x13814;
      if (!x13815) break;
      x13760 = x13760 + 1;
    }
    x13760 = x13760 + 1;
    for (;;) {
      int x13825 = x13760;
      char x13826 = x3722[x13825];
      bool x13827 = x13826 != '|';
      bool x13832 = x13827;
      if (x13827) {
        int x13828 = x13760;
        char x13829 = x3722[x13828];
        bool x13830 = x13829 != '\n';
        x13832 = x13830;
      }
      bool x13833 = x13832;
      if (!x13833) break;
      x13760 = x13760 + 1;
    }
    x13760 = x13760 + 1;
    int x13843 = 0;
    for (;;) {
      int x13844 = x13760;
      char x13845 = x3722[x13844];
      bool x13846 = x13845 != '|';
      bool x13851 = x13846;
      if (x13846) {
        int x13847 = x13760;
        char x13848 = x3722[x13847];
        bool x13849 = x13848 != '\n';
        x13851 = x13849;
      }
      bool x13852 = x13851;
      if (!x13852) break;
      int x13854 = x13843;
      int x13856 = x13760;
      int x13855 = x13854 * 10;
      char x13857 = x3722[x13856];
      char x13858 = x13857 - '0';
      int x13859 = x13855 + x13858;
      x13843 = x13859;
      x13760 = x13760 + 1;
    }
    x13760 = x13760 + 1;
    int x13865 = x13843;
    for (;;) {
      int x13867 = x13760;
      char x13868 = x3722[x13867];
      bool x13869 = x13868 != '|';
      bool x13874 = x13869;
      if (x13869) {
        int x13870 = x13760;
        char x13871 = x3722[x13870];
        bool x13872 = x13871 != '\n';
        x13874 = x13872;
      }
      bool x13875 = x13874;
      if (!x13875) break;
      x13760 = x13760 + 1;
    }
    x13760 = x13760 + 1;
    for (;;) {
      int x13887 = x13760;
      char x13888 = x3722[x13887];
      bool x13889 = x13888 != '.';
      bool x13894 = x13889;
      if (x13889) {
        int x13890 = x13760;
        char x13891 = x3722[x13890];
        bool x13892 = x13891 != '|';
        x13894 = x13892;
      }
      bool x13895 = x13894;
      bool x13900 = x13895;
      if (x13895) {
        int x13896 = x13760;
        char x13897 = x3722[x13896];
        bool x13898 = x13897 != '\n';
        x13900 = x13898;
      }
      bool x13901 = x13900;
      if (!x13901) break;
      x13760 = x13760 + 1;
    }
    int x13913 = x13760;
    char x13914 = x3722[x13913];
    bool x13915 = x13914 == '.';
    if (x13915) {
      x13760 = x13760 + 1;
      for (;;) {
        int x13917 = x13760;
        char x13918 = x3722[x13917];
        bool x13919 = x13918 != '|';
        bool x13924 = x13919;
        if (x13919) {
          int x13920 = x13760;
          char x13921 = x3722[x13920];
          bool x13922 = x13921 != '\n';
          x13924 = x13922;
        }
        bool x13925 = x13924;
        if (!x13925) break;
        x13760 = x13760 + 1;
      }
    } else {
    }
    x13760 = x13760 + 1;
    for (;;) {
      int x13950 = x13760;
      char x13951 = x3722[x13950];
      bool x13952 = x13951 != '|';
      bool x13957 = x13952;
      if (x13952) {
        int x13953 = x13760;
        char x13954 = x3722[x13953];
        bool x13955 = x13954 != '\n';
        x13957 = x13955;
      }
      bool x13958 = x13957;
      if (!x13958) break;
      x13760 = x13760 + 1;
    }
    x13760 = x13760 + 1;
    for (;;) {
      int x13968 = x13760;
      char x13969 = x3722[x13968];
      bool x13970 = x13969 != '|';
      bool x13975 = x13970;
      if (x13970) {
        int x13971 = x13760;
        char x13972 = x3722[x13971];
        bool x13973 = x13972 != '\n';
        x13975 = x13973;
      }
      bool x13976 = x13975;
      if (!x13976) break;
      x13760 = x13760 + 1;
    }
    x13760 = x13760 + 1;
    int x13986 = x13762;
    int x13987 = x13761;
    bool x13988 = x13986 == x13987;
    if (x13988) {
      int x13989 = x13987 * 4;
      x13761 = x13989;
      printf("buffer.resize %d\n",x13989);
      int* x13992 = x13764;
      int* x13993 = (int*)realloc(x13992,x13989 * sizeof(int));
      x13764 = x13993;
      int* x14001 = x13770;
      int* x14002 = (int*)realloc(x14001,x13989 * sizeof(int));
      x13770 = x14002;
    } else {
    }
    int* x14018 = x13764;
    x14018[x13986] = x13805;
    int* x14024 = x13770;
    x14024[x13986] = x13865;
    x13762 = x13762 + 1;
  }
  int x14037 = 0;
  int x14038 = 1048576;
  int x14039 = 0;
  int* x14040 = (int*)malloc(1048576 * sizeof(int));
  int* x14041 = x14040;
  int* x14046 = (int*)malloc(1048576 * sizeof(int));
  int* x14047 = x14046;
  int x1747 = open("../databases/sf2/supplier.tbl",0);
  int x1748 = fsize(x1747);
  char* x1749 = mmap(0, x1748, PROT_READ, MAP_FILE | MAP_SHARED, x1747, 0);
  for (;;) {
    int x14054 = x14037;
    bool x14055 = x14054 < x1748;
    if (!x14055) break;
    int x14058 = 0;
    for (;;) {
      int x14059 = x14037;
      char x14060 = x1749[x14059];
      bool x14061 = x14060 != '|';
      bool x14066 = x14061;
      if (x14061) {
        int x14062 = x14037;
        char x14063 = x1749[x14062];
        bool x14064 = x14063 != '\n';
        x14066 = x14064;
      }
      bool x14067 = x14066;
      if (!x14067) break;
      int x14069 = x14058;
      int x14071 = x14037;
      int x14070 = x14069 * 10;
      char x14072 = x1749[x14071];
      char x14073 = x14072 - '0';
      int x14074 = x14070 + x14073;
      x14058 = x14074;
      x14037 = x14037 + 1;
    }
    x14037 = x14037 + 1;
    int x14080 = x14058;
    for (;;) {
      int x14082 = x14037;
      char x14083 = x1749[x14082];
      bool x14084 = x14083 != '|';
      bool x14089 = x14084;
      if (x14084) {
        int x14085 = x14037;
        char x14086 = x1749[x14085];
        bool x14087 = x14086 != '\n';
        x14089 = x14087;
      }
      bool x14090 = x14089;
      if (!x14090) break;
      x14037 = x14037 + 1;
    }
    x14037 = x14037 + 1;
    for (;;) {
      int x14100 = x14037;
      char x14101 = x1749[x14100];
      bool x14102 = x14101 != '|';
      bool x14107 = x14102;
      if (x14102) {
        int x14103 = x14037;
        char x14104 = x1749[x14103];
        bool x14105 = x14104 != '\n';
        x14107 = x14105;
      }
      bool x14108 = x14107;
      if (!x14108) break;
      x14037 = x14037 + 1;
    }
    x14037 = x14037 + 1;
    int x14118 = 0;
    for (;;) {
      int x14119 = x14037;
      char x14120 = x1749[x14119];
      bool x14121 = x14120 != '|';
      bool x14126 = x14121;
      if (x14121) {
        int x14122 = x14037;
        char x14123 = x1749[x14122];
        bool x14124 = x14123 != '\n';
        x14126 = x14124;
      }
      bool x14127 = x14126;
      if (!x14127) break;
      int x14129 = x14118;
      int x14131 = x14037;
      int x14130 = x14129 * 10;
      char x14132 = x1749[x14131];
      char x14133 = x14132 - '0';
      int x14134 = x14130 + x14133;
      x14118 = x14134;
      x14037 = x14037 + 1;
    }
    x14037 = x14037 + 1;
    int x14140 = x14118;
    for (;;) {
      int x14142 = x14037;
      char x14143 = x1749[x14142];
      bool x14144 = x14143 != '|';
      bool x14149 = x14144;
      if (x14144) {
        int x14145 = x14037;
        char x14146 = x1749[x14145];
        bool x14147 = x14146 != '\n';
        x14149 = x14147;
      }
      bool x14150 = x14149;
      if (!x14150) break;
      x14037 = x14037 + 1;
    }
    x14037 = x14037 + 1;
    for (;;) {
      int x14162 = x14037;
      char x14163 = x1749[x14162];
      bool x14164 = x14163 != '.';
      bool x14169 = x14164;
      if (x14164) {
        int x14165 = x14037;
        char x14166 = x1749[x14165];
        bool x14167 = x14166 != '|';
        x14169 = x14167;
      }
      bool x14170 = x14169;
      bool x14175 = x14170;
      if (x14170) {
        int x14171 = x14037;
        char x14172 = x1749[x14171];
        bool x14173 = x14172 != '\n';
        x14175 = x14173;
      }
      bool x14176 = x14175;
      if (!x14176) break;
      x14037 = x14037 + 1;
    }
    int x14188 = x14037;
    char x14189 = x1749[x14188];
    bool x14190 = x14189 == '.';
    if (x14190) {
      x14037 = x14037 + 1;
      for (;;) {
        int x14192 = x14037;
        char x14193 = x1749[x14192];
        bool x14194 = x14193 != '|';
        bool x14199 = x14194;
        if (x14194) {
          int x14195 = x14037;
          char x14196 = x1749[x14195];
          bool x14197 = x14196 != '\n';
          x14199 = x14197;
        }
        bool x14200 = x14199;
        if (!x14200) break;
        x14037 = x14037 + 1;
      }
    } else {
    }
    x14037 = x14037 + 1;
    for (;;) {
      int x14225 = x14037;
      char x14226 = x1749[x14225];
      bool x14227 = x14226 != '|';
      bool x14232 = x14227;
      if (x14227) {
        int x14228 = x14037;
        char x14229 = x1749[x14228];
        bool x14230 = x14229 != '\n';
        x14232 = x14230;
      }
      bool x14233 = x14232;
      if (!x14233) break;
      x14037 = x14037 + 1;
    }
    x14037 = x14037 + 1;
    int x14243 = x14039;
    int x14244 = x14038;
    bool x14245 = x14243 == x14244;
    if (x14245) {
      int x14246 = x14244 * 4;
      x14038 = x14246;
      printf("buffer.resize %d\n",x14246);
      int* x14249 = x14041;
      int* x14250 = (int*)realloc(x14249,x14246 * sizeof(int));
      x14041 = x14250;
      int* x14258 = x14047;
      int* x14259 = (int*)realloc(x14258,x14246 * sizeof(int));
      x14047 = x14259;
    } else {
    }
    int* x14272 = x14041;
    x14272[x14243] = x14080;
    int* x14278 = x14047;
    x14278[x14243] = x14140;
    x14039 = x14039 + 1;
  }
  bool x972 = true == false;
  int x14289;
  for(x14289=0; x14289 < 5; x14289++) {
    bool x14290 = false;
    int x14291 = 0;
    bool x14292 = false;
    int x14293 = 0;
    int* x14296 = (int*)malloc(134217728 * sizeof(int));
    int* x14297 = x14296;
    int x14314 = 0;
    int* x14315 = (int*)malloc(67108864 * sizeof(int));
    int* x14316 = (int*)malloc(134217728 * sizeof(int));
    int x14317;
    for(x14317=0; x14317 < 67108864; x14317++) {
      x14315[x14317] = -1;
    }
    bool x14322 = false;
    int x14323 = 0;
    int* x14344 = (int*)malloc(134217728 * sizeof(int));
    int* x14345 = x14344;
    int* x14348 = (int*)malloc(134217728 * sizeof(int));
    int* x14349 = x14348;
    double* x14354 = (double*)malloc(134217728 * sizeof(double));
    double* x14355 = x14354;
    double* x14356 = (double*)malloc(134217728 * sizeof(double));
    double* x14357 = x14356;
    int x14376 = 0;
    int* x14377 = (int*)malloc(67108864 * sizeof(int));
    int* x14378 = (int*)malloc(134217728 * sizeof(int));
    int x14379;
    for(x14379=0; x14379 < 67108864; x14379++) {
      x14377[x14379] = -1;
    }
    bool x14384 = false;
    int x14385 = 0;
    int* x14409 = (int*)malloc(134217728 * sizeof(int));
    int* x14410 = x14409;
    double* x14415 = (double*)malloc(134217728 * sizeof(double));
    double* x14416 = x14415;
    double* x14417 = (double*)malloc(134217728 * sizeof(double));
    double* x14418 = x14417;
    int* x14439 = (int*)malloc(134217728 * sizeof(int));
    int* x14440 = x14439;
    long* x14445 = (long*)malloc(134217728 * sizeof(long));
    long* x14446 = x14445;
    int x14455 = 0;
    int* x14456 = (int*)malloc(67108864 * sizeof(int));
    int* x14457 = (int*)malloc(134217728 * sizeof(int));
    int x14458;
    for(x14458=0; x14458 < 67108864; x14458++) {
      x14456[x14458] = -1;
    }
    bool x14463 = false;
    int x14464 = 0;
    int* x14466 = (int*)malloc(134217728 * sizeof(int));
    int* x14467 = x14466;
    int* x14470 = (int*)malloc(134217728 * sizeof(int));
    int* x14471 = x14470;
    int x14474 = 0;
    int* x14475 = (int*)malloc(67108864 * sizeof(int));
    int* x14476 = (int*)malloc(134217728 * sizeof(int));
    int x14477;
    for(x14477=0; x14477 < 67108864; x14477++) {
      x14475[x14477] = -1;
    }
    bool x14482 = false;
    int x14483 = 0;
    int* x14486 = (int*)malloc(134217728 * sizeof(int));
    int* x14487 = x14486;
    int x14492 = 0;
    int* x14493 = (int*)malloc(67108864 * sizeof(int));
    int* x14494 = (int*)malloc(134217728 * sizeof(int));
    int x14495;
    for(x14495=0; x14495 < 67108864; x14495++) {
      x14493[x14495] = -1;
    }
    bool x14500 = false;
    int x14501 = 0;
    int* x14503 = (int*)malloc(134217728 * sizeof(int));
    int* x14504 = x14503;
    int* x14509 = (int*)malloc(134217728 * sizeof(int));
    int* x14510 = x14509;
    int x14517 = 0;
    int* x14518 = (int*)malloc(67108864 * sizeof(int));
    int* x14519 = (int*)malloc(134217728 * sizeof(int));
    int x14520;
    for(x14520=0; x14520 < 67108864; x14520++) {
      x14518[x14520] = -1;
    }
    bool x14526 = false;
    int x14527 = 0;
    char** x14530 = (char**)malloc(134217728 * sizeof(char*));
    char** x14531 = x14530;
    int* x14532 = (int*)malloc(134217728 * sizeof(int));
    int* x14533 = x14532;
    int x14534 = 0;
    int* x14535 = (int*)malloc(67108864 * sizeof(int));
    int* x14536 = (int*)malloc(134217728 * sizeof(int));
    int x14537;
    for(x14537=0; x14537 < 67108864; x14537++) {
      x14535[x14537] = -1;
    }
    struct Anon211179391* x14544 = (struct Anon211179391*)malloc(16777216 * sizeof(struct Anon211179391));
    struct Anon211179391* x14545 = x14544;
    int x14546 = 0;
    int* x14547 = (int*)malloc(16777216 * sizeof(int));
    int x14548;
    for(x14548=0; x14548 < 16777216; x14548++) {
      struct Anon211179391* x14549 = x14545;
      struct Anon211179391 x14550 = x14549[x14548];
      int x14551 = x14550.key;;
      struct Anon189208763 x14552 = x14550.aggs;;
      struct Anon211179391 x14553;
      x14553.exists = false;
      x14553.key = x14551;
      x14553.aggs = x14552;
      x14549[x14548] = x14553;
    }
    int x14559 = 0;
    struct timeval x15418, x15419, x15420;
    gettimeofday(&x15418, NULL);
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x14561 = x14526;
      bool x14562 = !x14561;
      bool x14567 = x14562;
      if (x14562) {
        int x14563 = x14527;
        int x14564 = x12105;
        bool x14565 = x14563 < x14564;
        x14567 = x14565;
      }
      bool x14568 = x14567;
      if (!x14568) break;
      int x14570 = x14527;
      int* x14571 = x12107;
      int x14572 = x14571[x14570];
      char** x14573 = x12109;
      char* x14574 = x14573[x14570];
      x14527 = x14527 + 1;
      int x14582 = x14534;
      char** x14583 = x14531;
      x14583[x14582] = x14574;
      int* x14585 = x14533;
      x14585[x14582] = x14572;
      x14534 = x14534 + 1;
      int x14588 = x14572 & 67108863;
      int x14589 = x14535[x14588];
      x14535[x14588] = x14582;
      x14536[x14582] = x14589;
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x14595 = x14500;
      bool x14596 = !x14595;
      bool x14601 = x14596;
      if (x14596) {
        int x14597 = x14501;
        int x14598 = x14039;
        bool x14599 = x14597 < x14598;
        x14601 = x14599;
      }
      bool x14602 = x14601;
      if (!x14602) break;
      int x14604 = x14501;
      int* x14605 = x14041;
      int x14606 = x14605[x14604];
      int* x14611 = x14047;
      int x14612 = x14611[x14604];
      x14501 = x14501 + 1;
      int x14621 = x14517;
      int* x14622 = x14504;
      x14622[x14621] = x14606;
      int* x14628 = x14510;
      x14628[x14621] = x14612;
      x14517 = x14517 + 1;
      int x14637 = x14606 & 67108863;
      int x14638 = x14518[x14637];
      x14518[x14637] = x14621;
      x14519[x14621] = x14638;
    }
    printf("%s\n","begin scan REGION");
    for (;;) {
      bool x14644 = x14482;
      bool x14645 = !x14644;
      bool x14650 = x14645;
      if (x14645) {
        int x14646 = x14483;
        int x14647 = x12235;
        bool x14648 = x14646 < x14647;
        x14650 = x14648;
      }
      bool x14651 = x14650;
      if (!x14651) break;
      int x14653 = x14483;
      int* x14654 = x12237;
      int x14655 = x14654[x14653];
      char** x14656 = x12239;
      char* x14657 = x14656[x14653];
      x14483 = x14483 + 1;
      bool x14662 = strcmp(x14657,"ASIA") == 0;;
      if (x14662) {
        int x14663 = x14492;
        int* x14664 = x14487;
        x14664[x14663] = x14655;
        x14492 = x14492 + 1;
        int x14671 = x14655 & 67108863;
        int x14672 = x14493[x14671];
        x14493[x14671] = x14663;
        x14494[x14663] = x14672;
      } else {
      }
    }
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x14680 = x14463;
      bool x14681 = !x14680;
      bool x14686 = x14681;
      if (x14681) {
        int x14682 = x14464;
        int x14683 = x12105;
        bool x14684 = x14682 < x14683;
        x14686 = x14684;
      }
      bool x14687 = x14686;
      if (!x14687) break;
      int x14689 = x14464;
      int* x14690 = x12107;
      int x14691 = x14690[x14689];
      int* x14694 = x12111;
      int x14695 = x14694[x14689];
      x14464 = x14464 + 1;
      int x14700 = x14474;
      int* x14701 = x14467;
      x14701[x14700] = x14691;
      int* x14705 = x14471;
      x14705[x14700] = x14695;
      x14474 = x14474 + 1;
      int x14710 = x14691 & 67108863;
      int x14711 = x14475[x14710];
      x14475[x14710] = x14700;
      x14476[x14700] = x14711;
    }
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x14717 = x14292;
      bool x14718 = !x14717;
      bool x14723 = x14718;
      if (x14718) {
        int x14719 = x14293;
        int x14720 = x12334;
        bool x14721 = x14719 < x14720;
        x14723 = x14721;
      }
      bool x14724 = x14723;
      if (!x14724) break;
      int x14726 = x14293;
      int* x14727 = x12336;
      int x14728 = x14727[x14726];
      char** x14735 = x12344;
      char* x14736 = x14735[x14726];
      x14293 = x14293 + 1;
      bool x14747 = strcmp(x14736,"MEDIUM ANODIZED NICKEL") == 0;;
      if (x14747) {
        int x14748 = x14314;
        int* x14749 = x14297;
        x14749[x14748] = x14728;
        x14314 = x14314 + 1;
        int x14768 = x14728 & 67108863;
        int x14769 = x14315[x14768];
        x14315[x14768] = x14748;
        x14316[x14748] = x14769;
      } else {
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x14777 = x14290;
      bool x14778 = !x14777;
      bool x14783 = x14778;
      if (x14778) {
        int x14779 = x14291;
        int x14780 = x12988;
        bool x14781 = x14779 < x14780;
        x14783 = x14781;
      }
      bool x14784 = x14783;
      if (!x14784) break;
      int x14786 = x14291;
      int* x14787 = x12990;
      int x14788 = x14787[x14786];
      int* x14789 = x12992;
      int x14790 = x14789[x14786];
      int* x14791 = x12994;
      int x14792 = x14791[x14786];
      double* x14797 = x13000;
      double x14798 = x14797[x14786];
      double* x14799 = x13002;
      double x14800 = x14799[x14786];
      x14291 = x14291 + 1;
      int x14821 = x14790 & 67108863;
      int x14822 = x14315[x14821];
      int x14823 = x14822;
      int x14905 = x14788 & 67108863;
      for (;;) {
        int x14824 = x14823;
        bool x14825 = x14824 != -1;
        if (!x14825) break;
        int x14827 = x14823;
        int* x14828 = x14297;
        int x14829 = x14828[x14827];
        int x14847 = x14316[x14827];
        x14823 = x14847;
        bool x14849 = x14829 == x14790;
        if (x14849) {
          int x14853 = x14376;
          int* x14872 = x14345;
          x14872[x14853] = x14788;
          int* x14876 = x14349;
          x14876[x14853] = x14792;
          double* x14882 = x14355;
          x14882[x14853] = x14798;
          double* x14884 = x14357;
          x14884[x14853] = x14800;
          x14376 = x14376 + 1;
          int x14906 = x14377[x14905];
          x14377[x14905] = x14853;
          x14378[x14853] = x14906;
        } else {
        }
      }
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x14916 = x14322;
      bool x14917 = !x14916;
      bool x14922 = x14917;
      if (x14917) {
        int x14918 = x14323;
        int x14919 = x12637;
        bool x14920 = x14918 < x14919;
        x14922 = x14920;
      }
      bool x14923 = x14922;
      if (!x14923) break;
      int x14925 = x14323;
      int* x14926 = x12639;
      int x14927 = x14926[x14925];
      int* x14928 = x12641;
      int x14929 = x14928[x14925];
      long* x14934 = x12647;
      long x14935 = x14934[x14925];
      x14323 = x14323 + 1;
      bool x14946 = x14935 >= 19950101L;
      bool x14948 = x14946;
      if (x14946) {
        bool x14947 = x14935 <= 19961231L;
        x14948 = x14947;
      }
      bool x14949 = x14948;
      if (x14949) {
        int x14950 = x14927 & 67108863;
        int x14951 = x14377[x14950];
        int x14952 = x14951;
        int x15084 = x14929 & 67108863;
        for (;;) {
          int x14953 = x14952;
          bool x14954 = x14953 != -1;
          if (!x14954) break;
          int x14956 = x14952;
          int* x14975 = x14345;
          int x14976 = x14975[x14956];
          int* x14979 = x14349;
          int x14980 = x14979[x14956];
          double* x14985 = x14355;
          double x14986 = x14985[x14956];
          double* x14987 = x14357;
          double x14988 = x14987[x14956];
          int x15008 = x14378[x14956];
          x14952 = x15008;
          bool x15010 = x14976 == x14927;
          if (x15010) {
            int x15014 = x14455;
            int* x15037 = x14410;
            x15037[x15014] = x14980;
            double* x15043 = x14416;
            x15043[x15014] = x14986;
            double* x15045 = x14418;
            x15045[x15014] = x14988;
            int* x15067 = x14440;
            x15067[x15014] = x14929;
            long* x15073 = x14446;
            x15073[x15014] = x14935;
            x14455 = x14455 + 1;
            int x15085 = x14456[x15084];
            x14456[x15084] = x15014;
            x14457[x15014] = x15085;
          } else {
          }
        }
      } else {
      }
    }
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x15097 = x14384;
      bool x15098 = !x15097;
      bool x15103 = x15098;
      if (x15098) {
        int x15099 = x14385;
        int x15100 = x13762;
        bool x15101 = x15099 < x15100;
        x15103 = x15101;
      }
      bool x15104 = x15103;
      if (!x15104) break;
      int x15106 = x14385;
      int* x15107 = x13764;
      int x15108 = x15107[x15106];
      int* x15113 = x13770;
      int x15114 = x15113[x15106];
      x14385 = x14385 + 1;
      int x15125 = x15108 & 67108863;
      int x15126 = x14456[x15125];
      int x15127 = x15126;
      int x15207 = x15114 & 67108863;
      for (;;) {
        int x15128 = x15127;
        bool x15129 = x15128 != -1;
        if (!x15129) break;
        int x15131 = x15127;
        int* x15154 = x14410;
        int x15155 = x15154[x15131];
        double* x15160 = x14416;
        double x15161 = x15160[x15131];
        double* x15162 = x14418;
        double x15163 = x15162[x15131];
        int* x15184 = x14440;
        int x15185 = x15184[x15131];
        long* x15190 = x14446;
        long x15191 = x15190[x15131];
        int x15201 = x14457[x15131];
        x15127 = x15201;
        bool x15203 = x15185 == x15108;
        if (x15203) {
          int x15208 = x14475[x15207];
          int x15209 = x15208;
          int x15249 = x15155 & 67108863;
          long x15296 = x15191; // date
          long x15297 = x15296/10000;
          int x15298 = (int)x15297;
          int x15299 = x15298 & 16777215;
          double x15313 = 1.0 - x15163;
          double x15314 = x15161 * x15313;
          for (;;) {
            int x15210 = x15209;
            bool x15211 = x15210 != -1;
            if (!x15211) break;
            int x15213 = x15209;
            int* x15214 = x14467;
            int x15215 = x15214[x15213];
            int* x15218 = x14471;
            int x15219 = x15218[x15213];
            int x15223 = x14476[x15213];
            x15209 = x15223;
            bool x15225 = x15215 == x15114;
            if (x15225) {
              int x15229 = x15219 & 67108863;
              int x15230 = x14493[x15229];
              int x15231 = x15230;
              for (;;) {
                int x15232 = x15231;
                bool x15233 = x15232 != -1;
                if (!x15233) break;
                int x15235 = x15231;
                int* x15236 = x14487;
                int x15237 = x15236[x15235];
                int x15243 = x14494[x15235];
                x15231 = x15243;
                bool x15245 = x15237 == x15219;
                if (x15245) {
                  int x15250 = x14518[x15249];
                  int x15251 = x15250;
                  for (;;) {
                    int x15252 = x15251;
                    bool x15253 = x15252 != -1;
                    if (!x15253) break;
                    int x15255 = x15251;
                    int* x15256 = x14504;
                    int x15257 = x15256[x15255];
                    int* x15262 = x14510;
                    int x15263 = x15262[x15255];
                    int x15271 = x14519[x15255];
                    x15251 = x15271;
                    bool x15273 = x15257 == x15155;
                    if (x15273) {
                      int x15278 = x15263 & 67108863;
                      int x15279 = x14535[x15278];
                      int x15280 = x15279;
                      for (;;) {
                        int x15281 = x15280;
                        bool x15282 = x15281 != -1;
                        if (!x15282) break;
                        int x15284 = x15280;
                        char** x15285 = x14531;
                        char* x15286 = x15285[x15284];
                        int* x15287 = x14533;
                        int x15288 = x15287[x15284];
                        int x15290 = x14536[x15284];
                        x15280 = x15290;
                        bool x15292 = x15288 == x15263;
                        if (x15292) {
                          int x15300 = x15299;
                          struct Anon211179391* x15301 = x14545;
                          struct Anon211179391 x15302 = x15301[x15299];
                          struct Anon211179391 x15303 = x15302;
                          bool x15304 = x15302.exists;;
                          bool x15309 = x15304;
                          if (x15304) {
                            struct Anon211179391 x15305 = x15303;
                            int x15306 = x15305.key;;
                            bool x15307 = x15306 == x15298;
                            x15309 = x15307;
                          }
                          bool x15310 = x15309;
                          if (x15310) {
                            struct Anon189208763 x15311 = x15302.aggs;;
                            int x15321 = x15302.key;;
                            double x15312 = x15311._0;;
                            double x15315 = x15312 + x15314;
                            bool x15316 = strcmp(x15286,"INDONESIA") == 0;;
                            double x15319;
                            if (x15316) {
                              double x15317 = x15311._1;;
                              double x15318 = x15317 + x15314;
                              x15319 = x15318;
                            } else {
                              double x15317 = x15311._1;;
                              x15319 = x15317;
                            }
                            struct Anon189208763 x15320;
                            x15320._0 = x15315;
                            x15320._1 = x15319;
                            struct Anon211179391 x15322;
                            x15322.exists = true;
                            x15322.key = x15321;
                            x15322.aggs = x15320;
                            x15301[x15299] = x15322;
                          } else {
                            bool x15316 = strcmp(x15286,"INDONESIA") == 0;;
                            double x15354;
                            if (x15316) {
                              x15354 = x15314;
                            } else {
                              x15354 = 0.0;
                            }
                            struct Anon189208763 x15355;
                            x15355._0 = x15314;
                            x15355._1 = x15354;
                            struct Anon211179391 x15356;
                            x15356.exists = true;
                            x15356.key = x15298;
                            x15356.aggs = x15355;
                            for (;;) {
                              struct Anon211179391 x15325 = x15303;
                              bool x15326 = x15325.exists;;
                              bool x15365;
                              if (x15326) {
                                int x15327 = x15325.key;;
                                bool x15328 = x15327 == x15298;
                                bool x15351;
                                if (x15328) {
                                  struct Anon189208763 x15329 = x15325.aggs;;
                                  int x15336 = x15300;
                                  struct Anon211179391* x15338 = x14545;
                                  double x15330 = x15329._0;;
                                  double x15331 = x15330 + x15314;
                                  double x15334;
                                  if (x15316) {
                                    double x15332 = x15329._1;;
                                    double x15333 = x15332 + x15314;
                                    x15334 = x15333;
                                  } else {
                                    double x15332 = x15329._1;;
                                    x15334 = x15332;
                                  }
                                  struct Anon189208763 x15335;
                                  x15335._0 = x15331;
                                  x15335._1 = x15334;
                                  struct Anon211179391 x15337;
                                  x15337.exists = true;
                                  x15337.key = x15327;
                                  x15337.aggs = x15335;
                                  x15338[x15336] = x15337;
                                  x15351 = false;
                                } else {
                                  int x15341 = x15300;
                                  int x15342 = x15341 + 1;
                                  int x15343 = x15342 % 16777215;
                                  x15300 = x15343;
                                  struct Anon211179391* x15345 = x14545;
                                  struct Anon211179391 x15346 = x15345[x15343];
                                  x15303 = x15346;
                                  x15351 = true;
                                }
                                x15365 = x15351;
                              } else {
                                int x15353 = x15300;
                                struct Anon211179391* x15357 = x14545;
                                x15357[x15353] = x15356;
                                int x15359 = x14546;
                                x14547[x15359] = x15353;
                                x14546 = x14546 + 1;
                                x15365 = false;
                              }
                              if (!x15365) break;
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
    int x15394 = x14546;
    int x15396;
    for(x15396=0; x15396 < x15394; x15396++) {
      int x15397 = x14547[x15396];
      struct Anon211179391* x15398 = x14545;
      struct Anon211179391 x15399 = x15398[x15397];
      int x15400 = x15399.key;;
      struct Anon189208763 x15401 = x15399.aggs;;
      if (x972) {
      } else {
        double x15402 = x15401._1;;
        double x15403 = x15401._0;;
        double x15404 = x15402 / x15403;
        printf("%d|%.5f\n",x15400,x15404);
        x14559 = x14559 + 1;
      }
    }
    int x15415 = x14559;
    printf("(%d rows)\n",x15415);
    gettimeofday(&x15419, NULL);
    timeval_subtract(&x15420, &x15419, &x15418);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x15420.tv_sec * 1000) + (x15420.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
