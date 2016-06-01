/*****************************************
  Emitting C Generated Code                  
*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
int tpch_strcmp(const char *s1, const char *s2);
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

        while ((c = *str++) != '|' && c != '\0' && len--)
          hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
      }
      size_t tpch_strlen(const char* str) {
        const char* start = str;
        while (*str != '\n' && (*str != '|') && (*str != '\0')) str++;
        return str - start;
      }
      int tpch_strcmp(const char *s1, const char *s2) {
        size_t l1 = tpch_strlen(s1);
        size_t l2 = tpch_strlen(s2);
        if (l1 > l2) l1 = l2;
        return strncmp(s1,s2,l1);
      }
      char* tpch_strnstr(const char *s, const char *find, size_t slen) {
        char c, sc;
        size_t len;

        if ((c = *find++) != '\0') {
          len = tpch_strlen(find);
          do {
            do {
              if (slen-- < 1 || (sc = *s++) == '\0')
                return (NULL);
            } while (sc != c);
            if (len > slen)
              return (NULL);
          } while (strncmp(s, find, len) != 0);
          s--;
        }
        return ((char *)s);
      }
      char* tpch_strstr_bak(char *s1, char *s2) {
        char* tmp;
        if ((tmp = tpch_strnstr(s1,s2,tpch_strlen(s1))) == NULL) {
          return s1 - (1 << 10); // Hack
        }
        return tmp;
      }
      char* tpch_strstr(char* s, char* find) {
        char c, sc;
        char* wts, *wtf;

        c = *find++;
        do {
          do {
            if ((sc = *s++) == '|') {
              return s - (1 << 10);
            }
          } while (sc != c);

          wtf = find;
          wts = s;
          while (*wtf == *wts) {
            wtf++;
            wts++;
          }
          if (*wtf == '\0')
              return s - 1;
        } while (1);
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

struct Anon1465150758 {
int L_ORDERKEY;
long O_ORDERDATE;
int O_SHIPPRIORITY;
};

struct Anon2052879266 {
double _0;
};

struct Anon895445893 {
bool exists;
struct Anon1465150758 key;
struct Anon2052879266 aggs;
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

struct Anon1495587458 {
int key;
struct Anon1023322325 wnd;
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

struct Anon1042493154 {
bool exists;
char* key;
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

struct Anon625264174 {
char L_RETURNFLAG;
char L_LINESTATUS;
};

struct Anon631953537 {
struct Anon625264174 key;
struct Anon1296044246 aggs;
};

struct Anon401726059 {
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

struct Anon726278688 {
char* SUPP_NATION;
char* CUST_NATION;
int L_YEAR;
};

struct Anon197435497 {
bool exists;
struct Anon726278688 key;
struct Anon2052879266 aggs;
};

struct Anon600063274 {
bool exists;
struct Anon625264174 key;
struct Anon567626277 aggs;
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

struct Anon1052706553 {
bool exists;
int key;
struct Anon1023322325 aggs;
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

struct Anon2052879268 {
double _2;
};

struct Anon108365162 {
int key;
struct Anon2052879268 aggs;
};

/************************ FUNCTIONS **************************/
int x16300(struct Anon108365162* x16289, struct Anon108365162* x16290);
int x16300(struct Anon108365162* x16289, struct Anon108365162* x16290) {
  struct Anon108365162 x16291 = (*x16289);
  struct Anon108365162 x16292 = (*x16290);
  int x16293 = x16291.key;;
  int x16294 = x16292.key;;
  bool x16295 = x16293 < x16294;
  int x16298;
  if (x16295) {
    x16298 = -1;
  } else {
    bool x16296 = x16293 > x16294;
    int x16297;
    if (x16296) {
      x16297 = 1;
    } else {
      x16297 = 0;
    }
    x16298 = x16297;
  }
  return x16298;
}

/************************ MAIN BODY **************************/
int main(int x12821, char** x12822) {
  long x12823 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x12824 = x7;
  long x12825 = 0L;
  int* x12826 = (int*)malloc(x7 * sizeof(int));
  int* x12827 = x12826;
  char** x12828 = (char**)malloc(x7 * sizeof(char*));
  char** x12829 = x12828;
  int* x12830 = (int*)malloc(x7 * sizeof(int));
  int* x12831 = x12830;
  int x1633 = open("XXXXXnation.tbl",0);
  long x1634 = fsize(x1633);
  char* x1635 = mmap(0, x1634, PROT_READ, MAP_FILE | MAP_SHARED, x1633, 0);
  for (;;) {
    long x12834 = x12823;
    bool x12835 = x12834 < x1634;
    if (!x12835) break;
    int x12838 = 0;
    for (;;) {
      long x12839 = x12823;
      char x12840 = x1635[x12839];
      bool x12841 = x12840 != '|';
      bool x12846 = x12841;
      if (x12841) {
        long x12842 = x12823;
        char x12843 = x1635[x12842];
        bool x12844 = x12843 != '\n';
        x12846 = x12844;
      }
      bool x12847 = x12846;
      if (!x12847) break;
      int x12849 = x12838;
      long x12851 = x12823;
      int x12850 = x12849 * 10;
      char x12852 = x1635[x12851];
      char x12853 = x12852 - '0';
      int x12854 = x12850 + x12853;
      x12838 = x12854;
      x12823 = x12823 + 1;
    }
    x12823 = x12823 + 1;
    int x12860 = x12838;
    long x12861 = x12823;
    for (;;) {
      long x12862 = x12823;
      char x12863 = x1635[x12862];
      bool x12864 = x12863 != '|';
      bool x12869 = x12864;
      if (x12864) {
        long x12865 = x12823;
        char x12866 = x1635[x12865];
        bool x12867 = x12866 != '\n';
        x12869 = x12867;
      }
      bool x12870 = x12869;
      if (!x12870) break;
      x12823 = x12823 + 1;
    }
    x12823 = x12823 + 1;
    int x12880 = 0;
    for (;;) {
      long x12881 = x12823;
      char x12882 = x1635[x12881];
      bool x12883 = x12882 != '|';
      bool x12888 = x12883;
      if (x12883) {
        long x12884 = x12823;
        char x12885 = x1635[x12884];
        bool x12886 = x12885 != '\n';
        x12888 = x12886;
      }
      bool x12889 = x12888;
      if (!x12889) break;
      int x12891 = x12880;
      long x12893 = x12823;
      int x12892 = x12891 * 10;
      char x12894 = x1635[x12893];
      char x12895 = x12894 - '0';
      int x12896 = x12892 + x12895;
      x12880 = x12896;
      x12823 = x12823 + 1;
    }
    x12823 = x12823 + 1;
    int x12902 = x12880;
    for (;;) {
      long x12904 = x12823;
      char x12905 = x1635[x12904];
      bool x12906 = x12905 != '|';
      bool x12911 = x12906;
      if (x12906) {
        long x12907 = x12823;
        char x12908 = x1635[x12907];
        bool x12909 = x12908 != '\n';
        x12911 = x12909;
      }
      bool x12912 = x12911;
      if (!x12912) break;
      x12823 = x12823 + 1;
    }
    x12823 = x12823 + 1;
    long x12922 = x12823;
    bool x12923 = x12922 > 0L;
    bool x12929 = x12923;
    if (x12923) {
      long x12924 = x12823;
      long x12925 = x12924 - 1L;
      char x12926 = x1635[x12925];
      bool x12927 = x12926 != '\n';
      x12929 = x12927;
    }
    bool x12930 = x12929;
    if (x12930) {
      for (;;) {
        long x12931 = x12823;
        char x12932 = x1635[x12931];
        bool x12933 = x12932 != '\n';
        if (!x12933) break;
        x12823 = x12823 + 1;
      }
    } else {
    }
    x12823 = x12823 + 1;
    long x12942 = x12825;
    long x12943 = x12824;
    bool x12944 = x12942 == x12943;
    if (x12944) {
      long x12945 = x12943 * 4L;
      x12824 = x12945;
      printf("buffer.resize %ld\n",x12945);
      int* x12948 = x12827;
      int* x12949 = (int*)realloc(x12948,x12945 * sizeof(int));
      x12827 = x12949;
      char** x12951 = x12829;
      char** x12952 = (char**)realloc(x12951,x12945 * sizeof(char*));
      x12829 = x12952;
      int* x12954 = x12831;
      int* x12955 = (int*)realloc(x12954,x12945 * sizeof(int));
      x12831 = x12955;
    } else {
    }
    int* x12962 = x12827;
    x12962[x12942] = x12860;
    char** x12964 = x12829;
    char* x12878 = x1635+x12861;
    x12964[x12942] = x12878;
    int* x12966 = x12831;
    x12966[x12942] = x12902;
    x12825 = x12825 + 1;
  }
  long x12973 = 0L;
  long x12974 = x7;
  long x12975 = 0L;
  int* x12976 = (int*)malloc(x7 * sizeof(int));
  int* x12977 = x12976;
  char** x12978 = (char**)malloc(x7 * sizeof(char*));
  char** x12979 = x12978;
  int x1786 = open("XXXXXregion.tbl",0);
  long x1787 = fsize(x1786);
  char* x1788 = mmap(0, x1787, PROT_READ, MAP_FILE | MAP_SHARED, x1786, 0);
  for (;;) {
    long x12982 = x12973;
    bool x12983 = x12982 < x1787;
    if (!x12983) break;
    int x12986 = 0;
    for (;;) {
      long x12987 = x12973;
      char x12988 = x1788[x12987];
      bool x12989 = x12988 != '|';
      bool x12994 = x12989;
      if (x12989) {
        long x12990 = x12973;
        char x12991 = x1788[x12990];
        bool x12992 = x12991 != '\n';
        x12994 = x12992;
      }
      bool x12995 = x12994;
      if (!x12995) break;
      int x12997 = x12986;
      long x12999 = x12973;
      int x12998 = x12997 * 10;
      char x13000 = x1788[x12999];
      char x13001 = x13000 - '0';
      int x13002 = x12998 + x13001;
      x12986 = x13002;
      x12973 = x12973 + 1;
    }
    x12973 = x12973 + 1;
    int x13008 = x12986;
    long x13009 = x12973;
    for (;;) {
      long x13010 = x12973;
      char x13011 = x1788[x13010];
      bool x13012 = x13011 != '|';
      bool x13017 = x13012;
      if (x13012) {
        long x13013 = x12973;
        char x13014 = x1788[x13013];
        bool x13015 = x13014 != '\n';
        x13017 = x13015;
      }
      bool x13018 = x13017;
      if (!x13018) break;
      x12973 = x12973 + 1;
    }
    x12973 = x12973 + 1;
    for (;;) {
      long x13028 = x12973;
      char x13029 = x1788[x13028];
      bool x13030 = x13029 != '|';
      bool x13035 = x13030;
      if (x13030) {
        long x13031 = x12973;
        char x13032 = x1788[x13031];
        bool x13033 = x13032 != '\n';
        x13035 = x13033;
      }
      bool x13036 = x13035;
      if (!x13036) break;
      x12973 = x12973 + 1;
    }
    x12973 = x12973 + 1;
    long x13046 = x12973;
    bool x13047 = x13046 > 0L;
    bool x13053 = x13047;
    if (x13047) {
      long x13048 = x12973;
      long x13049 = x13048 - 1L;
      char x13050 = x1788[x13049];
      bool x13051 = x13050 != '\n';
      x13053 = x13051;
    }
    bool x13054 = x13053;
    if (x13054) {
      for (;;) {
        long x13055 = x12973;
        char x13056 = x1788[x13055];
        bool x13057 = x13056 != '\n';
        if (!x13057) break;
        x12973 = x12973 + 1;
      }
    } else {
    }
    x12973 = x12973 + 1;
    long x13066 = x12975;
    long x13067 = x12974;
    bool x13068 = x13066 == x13067;
    if (x13068) {
      long x13069 = x13067 * 4L;
      x12974 = x13069;
      printf("buffer.resize %ld\n",x13069);
      int* x13072 = x12977;
      int* x13073 = (int*)realloc(x13072,x13069 * sizeof(int));
      x12977 = x13073;
      char** x13075 = x12979;
      char** x13076 = (char**)realloc(x13075,x13069 * sizeof(char*));
      x12979 = x13076;
    } else {
    }
    int* x13083 = x12977;
    x13083[x13066] = x13008;
    char** x13085 = x12979;
    char* x13026 = x1788+x13009;
    x13085[x13066] = x13026;
    x12975 = x12975 + 1;
  }
  long x13092 = 0L;
  long x13093 = x7;
  long x13094 = 0L;
  int* x13095 = (int*)malloc(x7 * sizeof(int));
  int* x13096 = x13095;
  char** x13103 = (char**)malloc(x7 * sizeof(char*));
  char** x13104 = x13103;
  int x1076 = open("XXXXXpart.tbl",0);
  long x1077 = fsize(x1076);
  char* x1078 = mmap(0, x1077, PROT_READ, MAP_FILE | MAP_SHARED, x1076, 0);
  for (;;) {
    long x13114 = x13092;
    bool x13115 = x13114 < x1077;
    if (!x13115) break;
    int x13118 = 0;
    for (;;) {
      long x13119 = x13092;
      char x13120 = x1078[x13119];
      bool x13121 = x13120 != '|';
      bool x13126 = x13121;
      if (x13121) {
        long x13122 = x13092;
        char x13123 = x1078[x13122];
        bool x13124 = x13123 != '\n';
        x13126 = x13124;
      }
      bool x13127 = x13126;
      if (!x13127) break;
      int x13129 = x13118;
      long x13131 = x13092;
      int x13130 = x13129 * 10;
      char x13132 = x1078[x13131];
      char x13133 = x13132 - '0';
      int x13134 = x13130 + x13133;
      x13118 = x13134;
      x13092 = x13092 + 1;
    }
    x13092 = x13092 + 1;
    int x13140 = x13118;
    for (;;) {
      long x13142 = x13092;
      char x13143 = x1078[x13142];
      bool x13144 = x13143 != '|';
      bool x13149 = x13144;
      if (x13144) {
        long x13145 = x13092;
        char x13146 = x1078[x13145];
        bool x13147 = x13146 != '\n';
        x13149 = x13147;
      }
      bool x13150 = x13149;
      if (!x13150) break;
      x13092 = x13092 + 1;
    }
    x13092 = x13092 + 1;
    for (;;) {
      long x13160 = x13092;
      char x13161 = x1078[x13160];
      bool x13162 = x13161 != '|';
      bool x13167 = x13162;
      if (x13162) {
        long x13163 = x13092;
        char x13164 = x1078[x13163];
        bool x13165 = x13164 != '\n';
        x13167 = x13165;
      }
      bool x13168 = x13167;
      if (!x13168) break;
      x13092 = x13092 + 1;
    }
    x13092 = x13092 + 1;
    for (;;) {
      long x13178 = x13092;
      char x13179 = x1078[x13178];
      bool x13180 = x13179 != '|';
      bool x13185 = x13180;
      if (x13180) {
        long x13181 = x13092;
        char x13182 = x1078[x13181];
        bool x13183 = x13182 != '\n';
        x13185 = x13183;
      }
      bool x13186 = x13185;
      if (!x13186) break;
      x13092 = x13092 + 1;
    }
    x13092 = x13092 + 1;
    long x13195 = x13092;
    for (;;) {
      long x13196 = x13092;
      char x13197 = x1078[x13196];
      bool x13198 = x13197 != '|';
      bool x13203 = x13198;
      if (x13198) {
        long x13199 = x13092;
        char x13200 = x1078[x13199];
        bool x13201 = x13200 != '\n';
        x13203 = x13201;
      }
      bool x13204 = x13203;
      if (!x13204) break;
      x13092 = x13092 + 1;
    }
    x13092 = x13092 + 1;
    for (;;) {
      long x13215 = x13092;
      char x13216 = x1078[x13215];
      bool x13217 = x13216 != '|';
      bool x13222 = x13217;
      if (x13217) {
        long x13218 = x13092;
        char x13219 = x1078[x13218];
        bool x13220 = x13219 != '\n';
        x13222 = x13220;
      }
      bool x13223 = x13222;
      if (!x13223) break;
      x13092 = x13092 + 1;
    }
    x13092 = x13092 + 1;
    for (;;) {
      long x13238 = x13092;
      char x13239 = x1078[x13238];
      bool x13240 = x13239 != '|';
      bool x13245 = x13240;
      if (x13240) {
        long x13241 = x13092;
        char x13242 = x1078[x13241];
        bool x13243 = x13242 != '\n';
        x13245 = x13243;
      }
      bool x13246 = x13245;
      if (!x13246) break;
      x13092 = x13092 + 1;
    }
    x13092 = x13092 + 1;
    for (;;) {
      long x13258 = x13092;
      char x13259 = x1078[x13258];
      bool x13260 = x13259 != '.';
      bool x13265 = x13260;
      if (x13260) {
        long x13261 = x13092;
        char x13262 = x1078[x13261];
        bool x13263 = x13262 != '|';
        x13265 = x13263;
      }
      bool x13266 = x13265;
      bool x13271 = x13266;
      if (x13266) {
        long x13267 = x13092;
        char x13268 = x1078[x13267];
        bool x13269 = x13268 != '\n';
        x13271 = x13269;
      }
      bool x13272 = x13271;
      if (!x13272) break;
      x13092 = x13092 + 1;
    }
    long x13284 = x13092;
    char x13285 = x1078[x13284];
    bool x13286 = x13285 == '.';
    if (x13286) {
      x13092 = x13092 + 1;
      for (;;) {
        long x13288 = x13092;
        char x13289 = x1078[x13288];
        bool x13290 = x13289 != '|';
        bool x13295 = x13290;
        if (x13290) {
          long x13291 = x13092;
          char x13292 = x1078[x13291];
          bool x13293 = x13292 != '\n';
          x13295 = x13293;
        }
        bool x13296 = x13295;
        if (!x13296) break;
        x13092 = x13092 + 1;
      }
    } else {
    }
    x13092 = x13092 + 1;
    for (;;) {
      long x13321 = x13092;
      char x13322 = x1078[x13321];
      bool x13323 = x13322 != '|';
      bool x13328 = x13323;
      if (x13323) {
        long x13324 = x13092;
        char x13325 = x1078[x13324];
        bool x13326 = x13325 != '\n';
        x13328 = x13326;
      }
      bool x13329 = x13328;
      if (!x13329) break;
      x13092 = x13092 + 1;
    }
    x13092 = x13092 + 1;
    long x13339 = x13092;
    bool x13340 = x13339 > 0L;
    bool x13346 = x13340;
    if (x13340) {
      long x13341 = x13092;
      long x13342 = x13341 - 1L;
      char x13343 = x1078[x13342];
      bool x13344 = x13343 != '\n';
      x13346 = x13344;
    }
    bool x13347 = x13346;
    if (x13347) {
      for (;;) {
        long x13348 = x13092;
        char x13349 = x1078[x13348];
        bool x13350 = x13349 != '\n';
        if (!x13350) break;
        x13092 = x13092 + 1;
      }
    } else {
    }
    x13092 = x13092 + 1;
    long x13359 = x13094;
    long x13360 = x13093;
    bool x13361 = x13359 == x13360;
    if (x13361) {
      long x13362 = x13360 * 4L;
      x13093 = x13362;
      printf("buffer.resize %ld\n",x13362);
      int* x13365 = x13096;
      int* x13366 = (int*)realloc(x13365,x13362 * sizeof(int));
      x13096 = x13366;
      char** x13377 = x13104;
      char** x13378 = (char**)realloc(x13377,x13362 * sizeof(char*));
      x13104 = x13378;
    } else {
    }
    int* x13394 = x13096;
    x13394[x13359] = x13140;
    char** x13402 = x13104;
    char* x13212 = x1078+x13195;
    x13402[x13359] = x13212;
    x13094 = x13094 + 1;
  }
  long x13415 = 0L;
  long x13416 = x7;
  long x13417 = 0L;
  int* x13418 = (int*)malloc(x7 * sizeof(int));
  int* x13419 = x13418;
  int* x13420 = (int*)malloc(x7 * sizeof(int));
  int* x13421 = x13420;
  long* x13426 = (long*)malloc(x7 * sizeof(long));
  long* x13427 = x13426;
  int x3633 = open("XXXXXorders.tbl",0);
  long x3634 = fsize(x3633);
  char* x3635 = mmap(0, x3634, PROT_READ, MAP_FILE | MAP_SHARED, x3633, 0);
  for (;;) {
    long x13436 = x13415;
    bool x13437 = x13436 < x3634;
    if (!x13437) break;
    int x13440 = 0;
    for (;;) {
      long x13441 = x13415;
      char x13442 = x3635[x13441];
      bool x13443 = x13442 != '|';
      bool x13448 = x13443;
      if (x13443) {
        long x13444 = x13415;
        char x13445 = x3635[x13444];
        bool x13446 = x13445 != '\n';
        x13448 = x13446;
      }
      bool x13449 = x13448;
      if (!x13449) break;
      int x13451 = x13440;
      long x13453 = x13415;
      int x13452 = x13451 * 10;
      char x13454 = x3635[x13453];
      char x13455 = x13454 - '0';
      int x13456 = x13452 + x13455;
      x13440 = x13456;
      x13415 = x13415 + 1;
    }
    x13415 = x13415 + 1;
    int x13462 = x13440;
    int x13464 = 0;
    for (;;) {
      long x13465 = x13415;
      char x13466 = x3635[x13465];
      bool x13467 = x13466 != '|';
      bool x13472 = x13467;
      if (x13467) {
        long x13468 = x13415;
        char x13469 = x3635[x13468];
        bool x13470 = x13469 != '\n';
        x13472 = x13470;
      }
      bool x13473 = x13472;
      if (!x13473) break;
      int x13475 = x13464;
      long x13477 = x13415;
      int x13476 = x13475 * 10;
      char x13478 = x3635[x13477];
      char x13479 = x13478 - '0';
      int x13480 = x13476 + x13479;
      x13464 = x13480;
      x13415 = x13415 + 1;
    }
    x13415 = x13415 + 1;
    int x13486 = x13464;
    x13415 = x13415 + 2;
    for (;;) {
      long x13493 = x13415;
      char x13494 = x3635[x13493];
      bool x13495 = x13494 != '.';
      bool x13500 = x13495;
      if (x13495) {
        long x13496 = x13415;
        char x13497 = x3635[x13496];
        bool x13498 = x13497 != '|';
        x13500 = x13498;
      }
      bool x13501 = x13500;
      bool x13506 = x13501;
      if (x13501) {
        long x13502 = x13415;
        char x13503 = x3635[x13502];
        bool x13504 = x13503 != '\n';
        x13506 = x13504;
      }
      bool x13507 = x13506;
      if (!x13507) break;
      x13415 = x13415 + 1;
    }
    long x13519 = x13415;
    char x13520 = x3635[x13519];
    bool x13521 = x13520 == '.';
    if (x13521) {
      x13415 = x13415 + 1;
      for (;;) {
        long x13523 = x13415;
        char x13524 = x3635[x13523];
        bool x13525 = x13524 != '|';
        bool x13530 = x13525;
        if (x13525) {
          long x13526 = x13415;
          char x13527 = x3635[x13526];
          bool x13528 = x13527 != '\n';
          x13530 = x13528;
        }
        bool x13531 = x13530;
        if (!x13531) break;
        x13415 = x13415 + 1;
      }
    } else {
    }
    x13415 = x13415 + 1;
    int x13556 = 0;
    for (;;) {
      long x13557 = x13415;
      char x13558 = x3635[x13557];
      bool x13559 = x13558 != '-';
      bool x13564 = x13559;
      if (x13559) {
        long x13560 = x13415;
        char x13561 = x3635[x13560];
        bool x13562 = x13561 != '\n';
        x13564 = x13562;
      }
      bool x13565 = x13564;
      if (!x13565) break;
      int x13567 = x13556;
      long x13569 = x13415;
      int x13568 = x13567 * 10;
      char x13570 = x3635[x13569];
      char x13571 = x13570 - '0';
      int x13572 = x13568 + x13571;
      x13556 = x13572;
      x13415 = x13415 + 1;
    }
    x13415 = x13415 + 1;
    int x13578 = x13556;
    int x13580 = 0;
    for (;;) {
      long x13581 = x13415;
      char x13582 = x3635[x13581];
      bool x13583 = x13582 != '-';
      bool x13588 = x13583;
      if (x13583) {
        long x13584 = x13415;
        char x13585 = x3635[x13584];
        bool x13586 = x13585 != '\n';
        x13588 = x13586;
      }
      bool x13589 = x13588;
      if (!x13589) break;
      int x13591 = x13580;
      long x13593 = x13415;
      int x13592 = x13591 * 10;
      char x13594 = x3635[x13593];
      char x13595 = x13594 - '0';
      int x13596 = x13592 + x13595;
      x13580 = x13596;
      x13415 = x13415 + 1;
    }
    x13415 = x13415 + 1;
    int x13602 = x13580;
    int x13604 = 0;
    for (;;) {
      long x13605 = x13415;
      char x13606 = x3635[x13605];
      bool x13607 = x13606 != '|';
      bool x13612 = x13607;
      if (x13607) {
        long x13608 = x13415;
        char x13609 = x3635[x13608];
        bool x13610 = x13609 != '\n';
        x13612 = x13610;
      }
      bool x13613 = x13612;
      if (!x13613) break;
      int x13615 = x13604;
      long x13617 = x13415;
      int x13616 = x13615 * 10;
      char x13618 = x3635[x13617];
      char x13619 = x13618 - '0';
      int x13620 = x13616 + x13619;
      x13604 = x13620;
      x13415 = x13415 + 1;
    }
    x13415 = x13415 + 1;
    int x13626 = x13604;
    for (;;) {
      long x13632 = x13415;
      char x13633 = x3635[x13632];
      bool x13634 = x13633 != '|';
      bool x13639 = x13634;
      if (x13634) {
        long x13635 = x13415;
        char x13636 = x3635[x13635];
        bool x13637 = x13636 != '\n';
        x13639 = x13637;
      }
      bool x13640 = x13639;
      if (!x13640) break;
      x13415 = x13415 + 1;
    }
    x13415 = x13415 + 1;
    for (;;) {
      long x13650 = x13415;
      char x13651 = x3635[x13650];
      bool x13652 = x13651 != '|';
      bool x13657 = x13652;
      if (x13652) {
        long x13653 = x13415;
        char x13654 = x3635[x13653];
        bool x13655 = x13654 != '\n';
        x13657 = x13655;
      }
      bool x13658 = x13657;
      if (!x13658) break;
      x13415 = x13415 + 1;
    }
    x13415 = x13415 + 1;
    for (;;) {
      long x13669 = x13415;
      char x13670 = x3635[x13669];
      bool x13671 = x13670 != '|';
      bool x13676 = x13671;
      if (x13671) {
        long x13672 = x13415;
        char x13673 = x3635[x13672];
        bool x13674 = x13673 != '\n';
        x13676 = x13674;
      }
      bool x13677 = x13676;
      if (!x13677) break;
      x13415 = x13415 + 1;
    }
    x13415 = x13415 + 1;
    for (;;) {
      long x13692 = x13415;
      char x13693 = x3635[x13692];
      bool x13694 = x13693 != '|';
      bool x13699 = x13694;
      if (x13694) {
        long x13695 = x13415;
        char x13696 = x3635[x13695];
        bool x13697 = x13696 != '\n';
        x13699 = x13697;
      }
      bool x13700 = x13699;
      if (!x13700) break;
      x13415 = x13415 + 1;
    }
    x13415 = x13415 + 1;
    long x13710 = x13415;
    bool x13711 = x13710 > 0L;
    bool x13717 = x13711;
    if (x13711) {
      long x13712 = x13415;
      long x13713 = x13712 - 1L;
      char x13714 = x3635[x13713];
      bool x13715 = x13714 != '\n';
      x13717 = x13715;
    }
    bool x13718 = x13717;
    if (x13718) {
      for (;;) {
        long x13719 = x13415;
        char x13720 = x3635[x13719];
        bool x13721 = x13720 != '\n';
        if (!x13721) break;
        x13415 = x13415 + 1;
      }
    } else {
    }
    x13415 = x13415 + 1;
    long x13730 = x13417;
    long x13731 = x13416;
    bool x13732 = x13730 == x13731;
    if (x13732) {
      long x13733 = x13731 * 4L;
      x13416 = x13733;
      printf("buffer.resize %ld\n",x13733);
      int* x13736 = x13419;
      int* x13737 = (int*)realloc(x13736,x13733 * sizeof(int));
      x13419 = x13737;
      int* x13739 = x13421;
      int* x13740 = (int*)realloc(x13739,x13733 * sizeof(int));
      x13421 = x13740;
      long* x13748 = x13427;
      long* x13749 = (long*)realloc(x13748,x13733 * sizeof(long));
      x13427 = x13749;
    } else {
    }
    int* x13765 = x13419;
    x13765[x13730] = x13462;
    int* x13767 = x13421;
    x13767[x13730] = x13486;
    long* x13773 = x13427;
    long x13627 = x13578 * 10000L;
    long x13628 = x13602 * 100L;
    long x13629 = x13627 + x13628;
    long x13630 = x13629 + x13626;
    x13773[x13730] = x13630;
    x13417 = x13417 + 1;
  }
  long x13786 = 0L;
  long x13787 = x7;
  long x13788 = 0L;
  int* x13789 = (int*)malloc(x7 * sizeof(int));
  int* x13790 = x13789;
  int* x13791 = (int*)malloc(x7 * sizeof(int));
  int* x13792 = x13791;
  int* x13793 = (int*)malloc(x7 * sizeof(int));
  int* x13794 = x13793;
  double* x13799 = (double*)malloc(x7 * sizeof(double));
  double* x13800 = x13799;
  double* x13801 = (double*)malloc(x7 * sizeof(double));
  double* x13802 = x13801;
  int x3 = open("XXXXXlineitem.tbl",0);
  long x4 = fsize(x3);
  char* x5 = mmap(0, x4, PROT_READ, MAP_FILE | MAP_SHARED, x3, 0);
  for (;;) {
    long x13821 = x13786;
    bool x13822 = x13821 < x4;
    if (!x13822) break;
    int x13825 = 0;
    for (;;) {
      long x13826 = x13786;
      char x13827 = x5[x13826];
      bool x13828 = x13827 != '|';
      bool x13833 = x13828;
      if (x13828) {
        long x13829 = x13786;
        char x13830 = x5[x13829];
        bool x13831 = x13830 != '\n';
        x13833 = x13831;
      }
      bool x13834 = x13833;
      if (!x13834) break;
      int x13836 = x13825;
      long x13838 = x13786;
      int x13837 = x13836 * 10;
      char x13839 = x5[x13838];
      char x13840 = x13839 - '0';
      int x13841 = x13837 + x13840;
      x13825 = x13841;
      x13786 = x13786 + 1;
    }
    x13786 = x13786 + 1;
    int x13847 = x13825;
    int x13849 = 0;
    for (;;) {
      long x13850 = x13786;
      char x13851 = x5[x13850];
      bool x13852 = x13851 != '|';
      bool x13857 = x13852;
      if (x13852) {
        long x13853 = x13786;
        char x13854 = x5[x13853];
        bool x13855 = x13854 != '\n';
        x13857 = x13855;
      }
      bool x13858 = x13857;
      if (!x13858) break;
      int x13860 = x13849;
      long x13862 = x13786;
      int x13861 = x13860 * 10;
      char x13863 = x5[x13862];
      char x13864 = x13863 - '0';
      int x13865 = x13861 + x13864;
      x13849 = x13865;
      x13786 = x13786 + 1;
    }
    x13786 = x13786 + 1;
    int x13871 = x13849;
    int x13873 = 0;
    for (;;) {
      long x13874 = x13786;
      char x13875 = x5[x13874];
      bool x13876 = x13875 != '|';
      bool x13881 = x13876;
      if (x13876) {
        long x13877 = x13786;
        char x13878 = x5[x13877];
        bool x13879 = x13878 != '\n';
        x13881 = x13879;
      }
      bool x13882 = x13881;
      if (!x13882) break;
      int x13884 = x13873;
      long x13886 = x13786;
      int x13885 = x13884 * 10;
      char x13887 = x5[x13886];
      char x13888 = x13887 - '0';
      int x13889 = x13885 + x13888;
      x13873 = x13889;
      x13786 = x13786 + 1;
    }
    x13786 = x13786 + 1;
    int x13895 = x13873;
    for (;;) {
      long x13898 = x13786;
      char x13899 = x5[x13898];
      bool x13900 = x13899 != '|';
      bool x13905 = x13900;
      if (x13900) {
        long x13901 = x13786;
        char x13902 = x5[x13901];
        bool x13903 = x13902 != '\n';
        x13905 = x13903;
      }
      bool x13906 = x13905;
      if (!x13906) break;
      x13786 = x13786 + 1;
    }
    x13786 = x13786 + 1;
    for (;;) {
      long x13923 = x13786;
      char x13924 = x5[x13923];
      bool x13925 = x13924 != '.';
      bool x13930 = x13925;
      if (x13925) {
        long x13926 = x13786;
        char x13927 = x5[x13926];
        bool x13928 = x13927 != '|';
        x13930 = x13928;
      }
      bool x13931 = x13930;
      bool x13936 = x13931;
      if (x13931) {
        long x13932 = x13786;
        char x13933 = x5[x13932];
        bool x13934 = x13933 != '\n';
        x13936 = x13934;
      }
      bool x13937 = x13936;
      if (!x13937) break;
      x13786 = x13786 + 1;
    }
    long x13949 = x13786;
    char x13950 = x5[x13949];
    bool x13951 = x13950 == '.';
    if (x13951) {
      x13786 = x13786 + 1;
      for (;;) {
        long x13953 = x13786;
        char x13954 = x5[x13953];
        bool x13955 = x13954 != '|';
        bool x13960 = x13955;
        if (x13955) {
          long x13956 = x13786;
          char x13957 = x5[x13956];
          bool x13958 = x13957 != '\n';
          x13960 = x13958;
        }
        bool x13961 = x13960;
        if (!x13961) break;
        x13786 = x13786 + 1;
      }
    } else {
    }
    x13786 = x13786 + 1;
    int x13986 = 0;
    int x13987 = 1;
    for (;;) {
      long x13988 = x13786;
      char x13989 = x5[x13988];
      bool x13990 = x13989 != '.';
      bool x13995 = x13990;
      if (x13990) {
        long x13991 = x13786;
        char x13992 = x5[x13991];
        bool x13993 = x13992 != '|';
        x13995 = x13993;
      }
      bool x13996 = x13995;
      bool x14001 = x13996;
      if (x13996) {
        long x13997 = x13786;
        char x13998 = x5[x13997];
        bool x13999 = x13998 != '\n';
        x14001 = x13999;
      }
      bool x14002 = x14001;
      if (!x14002) break;
      int x14004 = x13986;
      long x14006 = x13786;
      int x14005 = x14004 * 10;
      char x14007 = x5[x14006];
      char x14008 = x14007 - '0';
      int x14009 = x14005 + x14008;
      x13986 = x14009;
      x13786 = x13786 + 1;
    }
    long x14014 = x13786;
    char x14015 = x5[x14014];
    bool x14016 = x14015 == '.';
    if (x14016) {
      x13786 = x13786 + 1;
      for (;;) {
        long x14018 = x13786;
        char x14019 = x5[x14018];
        bool x14020 = x14019 != '|';
        bool x14025 = x14020;
        if (x14020) {
          long x14021 = x13786;
          char x14022 = x5[x14021];
          bool x14023 = x14022 != '\n';
          x14025 = x14023;
        }
        bool x14026 = x14025;
        if (!x14026) break;
        int x14028 = x13986;
        long x14030 = x13786;
        int x14029 = x14028 * 10;
        char x14031 = x5[x14030];
        char x14032 = x14031 - '0';
        int x14033 = x14029 + x14032;
        x13986 = x14033;
        int x14035 = x13987;
        int x14036 = x14035 * 10;
        x13987 = x14036;
        x13786 = x13786 + 1;
      }
    } else {
    }
    x13786 = x13786 + 1;
    int x14045 = x13986;
    int x14047 = x13987;
    int x14051 = 0;
    int x14052 = 1;
    for (;;) {
      long x14053 = x13786;
      char x14054 = x5[x14053];
      bool x14055 = x14054 != '.';
      bool x14060 = x14055;
      if (x14055) {
        long x14056 = x13786;
        char x14057 = x5[x14056];
        bool x14058 = x14057 != '|';
        x14060 = x14058;
      }
      bool x14061 = x14060;
      bool x14066 = x14061;
      if (x14061) {
        long x14062 = x13786;
        char x14063 = x5[x14062];
        bool x14064 = x14063 != '\n';
        x14066 = x14064;
      }
      bool x14067 = x14066;
      if (!x14067) break;
      int x14069 = x14051;
      long x14071 = x13786;
      int x14070 = x14069 * 10;
      char x14072 = x5[x14071];
      char x14073 = x14072 - '0';
      int x14074 = x14070 + x14073;
      x14051 = x14074;
      x13786 = x13786 + 1;
    }
    long x14079 = x13786;
    char x14080 = x5[x14079];
    bool x14081 = x14080 == '.';
    if (x14081) {
      x13786 = x13786 + 1;
      for (;;) {
        long x14083 = x13786;
        char x14084 = x5[x14083];
        bool x14085 = x14084 != '|';
        bool x14090 = x14085;
        if (x14085) {
          long x14086 = x13786;
          char x14087 = x5[x14086];
          bool x14088 = x14087 != '\n';
          x14090 = x14088;
        }
        bool x14091 = x14090;
        if (!x14091) break;
        int x14093 = x14051;
        long x14095 = x13786;
        int x14094 = x14093 * 10;
        char x14096 = x5[x14095];
        char x14097 = x14096 - '0';
        int x14098 = x14094 + x14097;
        x14051 = x14098;
        int x14100 = x14052;
        int x14101 = x14100 * 10;
        x14052 = x14101;
        x13786 = x13786 + 1;
      }
    } else {
    }
    x13786 = x13786 + 1;
    int x14110 = x14051;
    int x14112 = x14052;
    for (;;) {
      long x14118 = x13786;
      char x14119 = x5[x14118];
      bool x14120 = x14119 != '.';
      bool x14125 = x14120;
      if (x14120) {
        long x14121 = x13786;
        char x14122 = x5[x14121];
        bool x14123 = x14122 != '|';
        x14125 = x14123;
      }
      bool x14126 = x14125;
      bool x14131 = x14126;
      if (x14126) {
        long x14127 = x13786;
        char x14128 = x5[x14127];
        bool x14129 = x14128 != '\n';
        x14131 = x14129;
      }
      bool x14132 = x14131;
      if (!x14132) break;
      x13786 = x13786 + 1;
    }
    long x14144 = x13786;
    char x14145 = x5[x14144];
    bool x14146 = x14145 == '.';
    if (x14146) {
      x13786 = x13786 + 1;
      for (;;) {
        long x14148 = x13786;
        char x14149 = x5[x14148];
        bool x14150 = x14149 != '|';
        bool x14155 = x14150;
        if (x14150) {
          long x14151 = x13786;
          char x14152 = x5[x14151];
          bool x14153 = x14152 != '\n';
          x14155 = x14153;
        }
        bool x14156 = x14155;
        if (!x14156) break;
        x13786 = x13786 + 1;
      }
    } else {
    }
    x13786 = x13786 + 1;
    x13786 = x13786 + 2;
    x13786 = x13786 + 2;
    for (;;) {
      long x14188 = x13786;
      char x14189 = x5[x14188];
      bool x14190 = x14189 != '-';
      bool x14195 = x14190;
      if (x14190) {
        long x14191 = x13786;
        char x14192 = x5[x14191];
        bool x14193 = x14192 != '\n';
        x14195 = x14193;
      }
      bool x14196 = x14195;
      if (!x14196) break;
      x13786 = x13786 + 1;
    }
    x13786 = x13786 + 1;
    for (;;) {
      long x14212 = x13786;
      char x14213 = x5[x14212];
      bool x14214 = x14213 != '-';
      bool x14219 = x14214;
      if (x14214) {
        long x14215 = x13786;
        char x14216 = x5[x14215];
        bool x14217 = x14216 != '\n';
        x14219 = x14217;
      }
      bool x14220 = x14219;
      if (!x14220) break;
      x13786 = x13786 + 1;
    }
    x13786 = x13786 + 1;
    for (;;) {
      long x14236 = x13786;
      char x14237 = x5[x14236];
      bool x14238 = x14237 != '|';
      bool x14243 = x14238;
      if (x14238) {
        long x14239 = x13786;
        char x14240 = x5[x14239];
        bool x14241 = x14240 != '\n';
        x14243 = x14241;
      }
      bool x14244 = x14243;
      if (!x14244) break;
      x13786 = x13786 + 1;
    }
    x13786 = x13786 + 1;
    for (;;) {
      long x14264 = x13786;
      char x14265 = x5[x14264];
      bool x14266 = x14265 != '-';
      bool x14271 = x14266;
      if (x14266) {
        long x14267 = x13786;
        char x14268 = x5[x14267];
        bool x14269 = x14268 != '\n';
        x14271 = x14269;
      }
      bool x14272 = x14271;
      if (!x14272) break;
      x13786 = x13786 + 1;
    }
    x13786 = x13786 + 1;
    for (;;) {
      long x14288 = x13786;
      char x14289 = x5[x14288];
      bool x14290 = x14289 != '-';
      bool x14295 = x14290;
      if (x14290) {
        long x14291 = x13786;
        char x14292 = x5[x14291];
        bool x14293 = x14292 != '\n';
        x14295 = x14293;
      }
      bool x14296 = x14295;
      if (!x14296) break;
      x13786 = x13786 + 1;
    }
    x13786 = x13786 + 1;
    for (;;) {
      long x14312 = x13786;
      char x14313 = x5[x14312];
      bool x14314 = x14313 != '|';
      bool x14319 = x14314;
      if (x14314) {
        long x14315 = x13786;
        char x14316 = x5[x14315];
        bool x14317 = x14316 != '\n';
        x14319 = x14317;
      }
      bool x14320 = x14319;
      if (!x14320) break;
      x13786 = x13786 + 1;
    }
    x13786 = x13786 + 1;
    for (;;) {
      long x14340 = x13786;
      char x14341 = x5[x14340];
      bool x14342 = x14341 != '-';
      bool x14347 = x14342;
      if (x14342) {
        long x14343 = x13786;
        char x14344 = x5[x14343];
        bool x14345 = x14344 != '\n';
        x14347 = x14345;
      }
      bool x14348 = x14347;
      if (!x14348) break;
      x13786 = x13786 + 1;
    }
    x13786 = x13786 + 1;
    for (;;) {
      long x14364 = x13786;
      char x14365 = x5[x14364];
      bool x14366 = x14365 != '-';
      bool x14371 = x14366;
      if (x14366) {
        long x14367 = x13786;
        char x14368 = x5[x14367];
        bool x14369 = x14368 != '\n';
        x14371 = x14369;
      }
      bool x14372 = x14371;
      if (!x14372) break;
      x13786 = x13786 + 1;
    }
    x13786 = x13786 + 1;
    for (;;) {
      long x14388 = x13786;
      char x14389 = x5[x14388];
      bool x14390 = x14389 != '|';
      bool x14395 = x14390;
      if (x14390) {
        long x14391 = x13786;
        char x14392 = x5[x14391];
        bool x14393 = x14392 != '\n';
        x14395 = x14393;
      }
      bool x14396 = x14395;
      if (!x14396) break;
      x13786 = x13786 + 1;
    }
    x13786 = x13786 + 1;
    for (;;) {
      long x14415 = x13786;
      char x14416 = x5[x14415];
      bool x14417 = x14416 != '|';
      bool x14422 = x14417;
      if (x14417) {
        long x14418 = x13786;
        char x14419 = x5[x14418];
        bool x14420 = x14419 != '\n';
        x14422 = x14420;
      }
      bool x14423 = x14422;
      if (!x14423) break;
      x13786 = x13786 + 1;
    }
    x13786 = x13786 + 1;
    for (;;) {
      long x14433 = x13786;
      char x14434 = x5[x14433];
      bool x14435 = x14434 != '|';
      bool x14440 = x14435;
      if (x14435) {
        long x14436 = x13786;
        char x14437 = x5[x14436];
        bool x14438 = x14437 != '\n';
        x14440 = x14438;
      }
      bool x14441 = x14440;
      if (!x14441) break;
      x13786 = x13786 + 1;
    }
    x13786 = x13786 + 1;
    for (;;) {
      long x14451 = x13786;
      char x14452 = x5[x14451];
      bool x14453 = x14452 != '|';
      bool x14458 = x14453;
      if (x14453) {
        long x14454 = x13786;
        char x14455 = x5[x14454];
        bool x14456 = x14455 != '\n';
        x14458 = x14456;
      }
      bool x14459 = x14458;
      if (!x14459) break;
      x13786 = x13786 + 1;
    }
    x13786 = x13786 + 1;
    long x14469 = x13786;
    bool x14470 = x14469 > 0L;
    bool x14476 = x14470;
    if (x14470) {
      long x14471 = x13786;
      long x14472 = x14471 - 1L;
      char x14473 = x5[x14472];
      bool x14474 = x14473 != '\n';
      x14476 = x14474;
    }
    bool x14477 = x14476;
    if (x14477) {
      for (;;) {
        long x14478 = x13786;
        char x14479 = x5[x14478];
        bool x14480 = x14479 != '\n';
        if (!x14480) break;
        x13786 = x13786 + 1;
      }
    } else {
    }
    x13786 = x13786 + 1;
    long x14489 = x13788;
    long x14490 = x13787;
    bool x14491 = x14489 == x14490;
    if (x14491) {
      long x14492 = x14490 * 4L;
      x13787 = x14492;
      printf("buffer.resize %ld\n",x14492);
      int* x14495 = x13790;
      int* x14496 = (int*)realloc(x14495,x14492 * sizeof(int));
      x13790 = x14496;
      int* x14498 = x13792;
      int* x14499 = (int*)realloc(x14498,x14492 * sizeof(int));
      x13792 = x14499;
      int* x14501 = x13794;
      int* x14502 = (int*)realloc(x14501,x14492 * sizeof(int));
      x13794 = x14502;
      double* x14510 = x13800;
      double* x14511 = (double*)realloc(x14510,x14492 * sizeof(double));
      x13800 = x14511;
      double* x14513 = x13802;
      double* x14514 = (double*)realloc(x14513,x14492 * sizeof(double));
      x13802 = x14514;
    } else {
    }
    int* x14545 = x13790;
    x14545[x14489] = x13847;
    int* x14547 = x13792;
    x14547[x14489] = x13871;
    int* x14549 = x13794;
    x14549[x14489] = x13895;
    double* x14555 = x13800;
    double x14046 = (double)x14045;
    double x14048 = (double)x14047;
    double x14049 = x14046 / x14048;
    x14555[x14489] = x14049;
    double* x14557 = x13802;
    double x14111 = (double)x14110;
    double x14113 = (double)x14112;
    double x14114 = x14111 / x14113;
    x14557[x14489] = x14114;
    x13788 = x13788 + 1;
  }
  long x14580 = 0L;
  long x14581 = x7;
  long x14582 = 0L;
  int* x14583 = (int*)malloc(x7 * sizeof(int));
  int* x14584 = x14583;
  int* x14589 = (int*)malloc(x7 * sizeof(int));
  int* x14590 = x14589;
  int x4007 = open("XXXXXcustomer.tbl",0);
  long x4008 = fsize(x4007);
  char* x4009 = mmap(0, x4008, PROT_READ, MAP_FILE | MAP_SHARED, x4007, 0);
  for (;;) {
    long x14599 = x14580;
    bool x14600 = x14599 < x4008;
    if (!x14600) break;
    int x14603 = 0;
    for (;;) {
      long x14604 = x14580;
      char x14605 = x4009[x14604];
      bool x14606 = x14605 != '|';
      bool x14611 = x14606;
      if (x14606) {
        long x14607 = x14580;
        char x14608 = x4009[x14607];
        bool x14609 = x14608 != '\n';
        x14611 = x14609;
      }
      bool x14612 = x14611;
      if (!x14612) break;
      int x14614 = x14603;
      long x14616 = x14580;
      int x14615 = x14614 * 10;
      char x14617 = x4009[x14616];
      char x14618 = x14617 - '0';
      int x14619 = x14615 + x14618;
      x14603 = x14619;
      x14580 = x14580 + 1;
    }
    x14580 = x14580 + 1;
    int x14625 = x14603;
    for (;;) {
      long x14627 = x14580;
      char x14628 = x4009[x14627];
      bool x14629 = x14628 != '|';
      bool x14634 = x14629;
      if (x14629) {
        long x14630 = x14580;
        char x14631 = x4009[x14630];
        bool x14632 = x14631 != '\n';
        x14634 = x14632;
      }
      bool x14635 = x14634;
      if (!x14635) break;
      x14580 = x14580 + 1;
    }
    x14580 = x14580 + 1;
    for (;;) {
      long x14645 = x14580;
      char x14646 = x4009[x14645];
      bool x14647 = x14646 != '|';
      bool x14652 = x14647;
      if (x14647) {
        long x14648 = x14580;
        char x14649 = x4009[x14648];
        bool x14650 = x14649 != '\n';
        x14652 = x14650;
      }
      bool x14653 = x14652;
      if (!x14653) break;
      x14580 = x14580 + 1;
    }
    x14580 = x14580 + 1;
    int x14663 = 0;
    for (;;) {
      long x14664 = x14580;
      char x14665 = x4009[x14664];
      bool x14666 = x14665 != '|';
      bool x14671 = x14666;
      if (x14666) {
        long x14667 = x14580;
        char x14668 = x4009[x14667];
        bool x14669 = x14668 != '\n';
        x14671 = x14669;
      }
      bool x14672 = x14671;
      if (!x14672) break;
      int x14674 = x14663;
      long x14676 = x14580;
      int x14675 = x14674 * 10;
      char x14677 = x4009[x14676];
      char x14678 = x14677 - '0';
      int x14679 = x14675 + x14678;
      x14663 = x14679;
      x14580 = x14580 + 1;
    }
    x14580 = x14580 + 1;
    int x14685 = x14663;
    for (;;) {
      long x14687 = x14580;
      char x14688 = x4009[x14687];
      bool x14689 = x14688 != '|';
      bool x14694 = x14689;
      if (x14689) {
        long x14690 = x14580;
        char x14691 = x4009[x14690];
        bool x14692 = x14691 != '\n';
        x14694 = x14692;
      }
      bool x14695 = x14694;
      if (!x14695) break;
      x14580 = x14580 + 1;
    }
    x14580 = x14580 + 1;
    for (;;) {
      long x14707 = x14580;
      char x14708 = x4009[x14707];
      bool x14709 = x14708 != '.';
      bool x14714 = x14709;
      if (x14709) {
        long x14710 = x14580;
        char x14711 = x4009[x14710];
        bool x14712 = x14711 != '|';
        x14714 = x14712;
      }
      bool x14715 = x14714;
      bool x14720 = x14715;
      if (x14715) {
        long x14716 = x14580;
        char x14717 = x4009[x14716];
        bool x14718 = x14717 != '\n';
        x14720 = x14718;
      }
      bool x14721 = x14720;
      if (!x14721) break;
      x14580 = x14580 + 1;
    }
    long x14733 = x14580;
    char x14734 = x4009[x14733];
    bool x14735 = x14734 == '.';
    if (x14735) {
      x14580 = x14580 + 1;
      for (;;) {
        long x14737 = x14580;
        char x14738 = x4009[x14737];
        bool x14739 = x14738 != '|';
        bool x14744 = x14739;
        if (x14739) {
          long x14740 = x14580;
          char x14741 = x4009[x14740];
          bool x14742 = x14741 != '\n';
          x14744 = x14742;
        }
        bool x14745 = x14744;
        if (!x14745) break;
        x14580 = x14580 + 1;
      }
    } else {
    }
    x14580 = x14580 + 1;
    for (;;) {
      long x14770 = x14580;
      char x14771 = x4009[x14770];
      bool x14772 = x14771 != '|';
      bool x14777 = x14772;
      if (x14772) {
        long x14773 = x14580;
        char x14774 = x4009[x14773];
        bool x14775 = x14774 != '\n';
        x14777 = x14775;
      }
      bool x14778 = x14777;
      if (!x14778) break;
      x14580 = x14580 + 1;
    }
    x14580 = x14580 + 1;
    for (;;) {
      long x14788 = x14580;
      char x14789 = x4009[x14788];
      bool x14790 = x14789 != '|';
      bool x14795 = x14790;
      if (x14790) {
        long x14791 = x14580;
        char x14792 = x4009[x14791];
        bool x14793 = x14792 != '\n';
        x14795 = x14793;
      }
      bool x14796 = x14795;
      if (!x14796) break;
      x14580 = x14580 + 1;
    }
    x14580 = x14580 + 1;
    long x14806 = x14580;
    bool x14807 = x14806 > 0L;
    bool x14813 = x14807;
    if (x14807) {
      long x14808 = x14580;
      long x14809 = x14808 - 1L;
      char x14810 = x4009[x14809];
      bool x14811 = x14810 != '\n';
      x14813 = x14811;
    }
    bool x14814 = x14813;
    if (x14814) {
      for (;;) {
        long x14815 = x14580;
        char x14816 = x4009[x14815];
        bool x14817 = x14816 != '\n';
        if (!x14817) break;
        x14580 = x14580 + 1;
      }
    } else {
    }
    x14580 = x14580 + 1;
    long x14826 = x14582;
    long x14827 = x14581;
    bool x14828 = x14826 == x14827;
    if (x14828) {
      long x14829 = x14827 * 4L;
      x14581 = x14829;
      printf("buffer.resize %ld\n",x14829);
      int* x14832 = x14584;
      int* x14833 = (int*)realloc(x14832,x14829 * sizeof(int));
      x14584 = x14833;
      int* x14841 = x14590;
      int* x14842 = (int*)realloc(x14841,x14829 * sizeof(int));
      x14590 = x14842;
    } else {
    }
    int* x14858 = x14584;
    x14858[x14826] = x14625;
    int* x14864 = x14590;
    x14864[x14826] = x14685;
    x14582 = x14582 + 1;
  }
  long x14877 = 0L;
  long x14878 = x7;
  long x14879 = 0L;
  int* x14880 = (int*)malloc(x7 * sizeof(int));
  int* x14881 = x14880;
  int* x14886 = (int*)malloc(x7 * sizeof(int));
  int* x14887 = x14886;
  int x1908 = open("XXXXXsupplier.tbl",0);
  long x1909 = fsize(x1908);
  char* x1910 = mmap(0, x1909, PROT_READ, MAP_FILE | MAP_SHARED, x1908, 0);
  for (;;) {
    long x14894 = x14877;
    bool x14895 = x14894 < x1909;
    if (!x14895) break;
    int x14898 = 0;
    for (;;) {
      long x14899 = x14877;
      char x14900 = x1910[x14899];
      bool x14901 = x14900 != '|';
      bool x14906 = x14901;
      if (x14901) {
        long x14902 = x14877;
        char x14903 = x1910[x14902];
        bool x14904 = x14903 != '\n';
        x14906 = x14904;
      }
      bool x14907 = x14906;
      if (!x14907) break;
      int x14909 = x14898;
      long x14911 = x14877;
      int x14910 = x14909 * 10;
      char x14912 = x1910[x14911];
      char x14913 = x14912 - '0';
      int x14914 = x14910 + x14913;
      x14898 = x14914;
      x14877 = x14877 + 1;
    }
    x14877 = x14877 + 1;
    int x14920 = x14898;
    for (;;) {
      long x14922 = x14877;
      char x14923 = x1910[x14922];
      bool x14924 = x14923 != '|';
      bool x14929 = x14924;
      if (x14924) {
        long x14925 = x14877;
        char x14926 = x1910[x14925];
        bool x14927 = x14926 != '\n';
        x14929 = x14927;
      }
      bool x14930 = x14929;
      if (!x14930) break;
      x14877 = x14877 + 1;
    }
    x14877 = x14877 + 1;
    for (;;) {
      long x14940 = x14877;
      char x14941 = x1910[x14940];
      bool x14942 = x14941 != '|';
      bool x14947 = x14942;
      if (x14942) {
        long x14943 = x14877;
        char x14944 = x1910[x14943];
        bool x14945 = x14944 != '\n';
        x14947 = x14945;
      }
      bool x14948 = x14947;
      if (!x14948) break;
      x14877 = x14877 + 1;
    }
    x14877 = x14877 + 1;
    int x14958 = 0;
    for (;;) {
      long x14959 = x14877;
      char x14960 = x1910[x14959];
      bool x14961 = x14960 != '|';
      bool x14966 = x14961;
      if (x14961) {
        long x14962 = x14877;
        char x14963 = x1910[x14962];
        bool x14964 = x14963 != '\n';
        x14966 = x14964;
      }
      bool x14967 = x14966;
      if (!x14967) break;
      int x14969 = x14958;
      long x14971 = x14877;
      int x14970 = x14969 * 10;
      char x14972 = x1910[x14971];
      char x14973 = x14972 - '0';
      int x14974 = x14970 + x14973;
      x14958 = x14974;
      x14877 = x14877 + 1;
    }
    x14877 = x14877 + 1;
    int x14980 = x14958;
    for (;;) {
      long x14982 = x14877;
      char x14983 = x1910[x14982];
      bool x14984 = x14983 != '|';
      bool x14989 = x14984;
      if (x14984) {
        long x14985 = x14877;
        char x14986 = x1910[x14985];
        bool x14987 = x14986 != '\n';
        x14989 = x14987;
      }
      bool x14990 = x14989;
      if (!x14990) break;
      x14877 = x14877 + 1;
    }
    x14877 = x14877 + 1;
    for (;;) {
      long x15002 = x14877;
      char x15003 = x1910[x15002];
      bool x15004 = x15003 != '.';
      bool x15009 = x15004;
      if (x15004) {
        long x15005 = x14877;
        char x15006 = x1910[x15005];
        bool x15007 = x15006 != '|';
        x15009 = x15007;
      }
      bool x15010 = x15009;
      bool x15015 = x15010;
      if (x15010) {
        long x15011 = x14877;
        char x15012 = x1910[x15011];
        bool x15013 = x15012 != '\n';
        x15015 = x15013;
      }
      bool x15016 = x15015;
      if (!x15016) break;
      x14877 = x14877 + 1;
    }
    long x15028 = x14877;
    char x15029 = x1910[x15028];
    bool x15030 = x15029 == '.';
    if (x15030) {
      x14877 = x14877 + 1;
      for (;;) {
        long x15032 = x14877;
        char x15033 = x1910[x15032];
        bool x15034 = x15033 != '|';
        bool x15039 = x15034;
        if (x15034) {
          long x15035 = x14877;
          char x15036 = x1910[x15035];
          bool x15037 = x15036 != '\n';
          x15039 = x15037;
        }
        bool x15040 = x15039;
        if (!x15040) break;
        x14877 = x14877 + 1;
      }
    } else {
    }
    x14877 = x14877 + 1;
    for (;;) {
      long x15065 = x14877;
      char x15066 = x1910[x15065];
      bool x15067 = x15066 != '|';
      bool x15072 = x15067;
      if (x15067) {
        long x15068 = x14877;
        char x15069 = x1910[x15068];
        bool x15070 = x15069 != '\n';
        x15072 = x15070;
      }
      bool x15073 = x15072;
      if (!x15073) break;
      x14877 = x14877 + 1;
    }
    x14877 = x14877 + 1;
    long x15083 = x14877;
    bool x15084 = x15083 > 0L;
    bool x15090 = x15084;
    if (x15084) {
      long x15085 = x14877;
      long x15086 = x15085 - 1L;
      char x15087 = x1910[x15086];
      bool x15088 = x15087 != '\n';
      x15090 = x15088;
    }
    bool x15091 = x15090;
    if (x15091) {
      for (;;) {
        long x15092 = x14877;
        char x15093 = x1910[x15092];
        bool x15094 = x15093 != '\n';
        if (!x15094) break;
        x14877 = x14877 + 1;
      }
    } else {
    }
    x14877 = x14877 + 1;
    long x15103 = x14879;
    long x15104 = x14878;
    bool x15105 = x15103 == x15104;
    if (x15105) {
      long x15106 = x15104 * 4L;
      x14878 = x15106;
      printf("buffer.resize %ld\n",x15106);
      int* x15109 = x14881;
      int* x15110 = (int*)realloc(x15109,x15106 * sizeof(int));
      x14881 = x15110;
      int* x15118 = x14887;
      int* x15119 = (int*)realloc(x15118,x15106 * sizeof(int));
      x14887 = x15119;
    } else {
    }
    int* x15132 = x14881;
    x15132[x15103] = x14920;
    int* x15138 = x14887;
    x15138[x15103] = x14980;
    x14879 = x14879 + 1;
  }
  long x2189 = DEFAULT_JOIN_HASH_SIZE;
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  long x2212 = x2189 - 1L;
  long x823 = x808 - 1L;
  bool x1043 = true == false;
  int x15149;
  for(x15149=0; x15149 < 5; x15149++) {
    bool x15150 = false;
    long x15151 = 0L;
    bool x15152 = false;
    long x15153 = 0L;
    int* x15156 = (int*)malloc(x2189 * sizeof(int));
    int* x15157 = x15156;
    long x15174 = 0L;
    long* x15175 = (long*)malloc(x2189 * sizeof(long));
    long* x15176 = (long*)malloc(x2189 * sizeof(long));
    long x15177;
    for(x15177=0L; x15177 < x2189; x15177++) {
      x15175[x15177] = -1L;
    }
    bool x15182 = false;
    long x15183 = 0L;
    int* x15204 = (int*)malloc(x2189 * sizeof(int));
    int* x15205 = x15204;
    int* x15208 = (int*)malloc(x2189 * sizeof(int));
    int* x15209 = x15208;
    double* x15214 = (double*)malloc(x2189 * sizeof(double));
    double* x15215 = x15214;
    double* x15216 = (double*)malloc(x2189 * sizeof(double));
    double* x15217 = x15216;
    long x15236 = 0L;
    long* x15237 = (long*)malloc(x2189 * sizeof(long));
    long* x15238 = (long*)malloc(x2189 * sizeof(long));
    long x15239;
    for(x15239=0L; x15239 < x2189; x15239++) {
      x15237[x15239] = -1L;
    }
    bool x15244 = false;
    long x15245 = 0L;
    int* x15269 = (int*)malloc(x2189 * sizeof(int));
    int* x15270 = x15269;
    double* x15275 = (double*)malloc(x2189 * sizeof(double));
    double* x15276 = x15275;
    double* x15277 = (double*)malloc(x2189 * sizeof(double));
    double* x15278 = x15277;
    int* x15299 = (int*)malloc(x2189 * sizeof(int));
    int* x15300 = x15299;
    long* x15305 = (long*)malloc(x2189 * sizeof(long));
    long* x15306 = x15305;
    long x15315 = 0L;
    long* x15316 = (long*)malloc(x2189 * sizeof(long));
    long* x15317 = (long*)malloc(x2189 * sizeof(long));
    long x15318;
    for(x15318=0L; x15318 < x2189; x15318++) {
      x15316[x15318] = -1L;
    }
    bool x15323 = false;
    long x15324 = 0L;
    int* x15326 = (int*)malloc(x2189 * sizeof(int));
    int* x15327 = x15326;
    int* x15330 = (int*)malloc(x2189 * sizeof(int));
    int* x15331 = x15330;
    long x15334 = 0L;
    long* x15335 = (long*)malloc(x2189 * sizeof(long));
    long* x15336 = (long*)malloc(x2189 * sizeof(long));
    long x15337;
    for(x15337=0L; x15337 < x2189; x15337++) {
      x15335[x15337] = -1L;
    }
    bool x15342 = false;
    long x15343 = 0L;
    int* x15346 = (int*)malloc(x2189 * sizeof(int));
    int* x15347 = x15346;
    long x15352 = 0L;
    long* x15353 = (long*)malloc(x2189 * sizeof(long));
    long* x15354 = (long*)malloc(x2189 * sizeof(long));
    long x15355;
    for(x15355=0L; x15355 < x2189; x15355++) {
      x15353[x15355] = -1L;
    }
    bool x15360 = false;
    long x15361 = 0L;
    int* x15363 = (int*)malloc(x2189 * sizeof(int));
    int* x15364 = x15363;
    int* x15369 = (int*)malloc(x2189 * sizeof(int));
    int* x15370 = x15369;
    long x15377 = 0L;
    long* x15378 = (long*)malloc(x2189 * sizeof(long));
    long* x15379 = (long*)malloc(x2189 * sizeof(long));
    long x15380;
    for(x15380=0L; x15380 < x2189; x15380++) {
      x15378[x15380] = -1L;
    }
    bool x15386 = false;
    long x15387 = 0L;
    char** x15390 = (char**)malloc(x2189 * sizeof(char*));
    char** x15391 = x15390;
    int* x15392 = (int*)malloc(x2189 * sizeof(int));
    int* x15393 = x15392;
    long x15394 = 0L;
    long* x15395 = (long*)malloc(x2189 * sizeof(long));
    long* x15396 = (long*)malloc(x2189 * sizeof(long));
    long x15397;
    for(x15397=0L; x15397 < x2189; x15397++) {
      x15395[x15397] = -1L;
    }
    struct Anon401726059* x15404 = (struct Anon401726059*)malloc(x808 * sizeof(struct Anon401726059));
    struct Anon401726059* x15405 = x15404;
    long x15406 = 0L;
    long* x15407 = (long*)malloc(x808 * sizeof(long));
    long x15408;
    for(x15408=0L; x15408 < x808; x15408++) {
      struct Anon401726059* x15409 = x15405;
      struct Anon401726059 x15410 = x15409[x15408];
      int x15411 = x15410.key;;
      struct Anon189208763 x15412 = x15410.aggs;;
      struct Anon401726059 x15413;
      x15413.exists = false;
      x15413.key = x15411;
      x15413.aggs = x15412;
      x15409[x15408] = x15413;
    }
    long x15419 = 1024L;
    long x15420 = 0L;
    struct Anon108365162* x15421 = (struct Anon108365162*)malloc(1024L * sizeof(struct Anon108365162));
    struct Anon108365162* x15422 = x15421;
    long x15424 = 0L;
    struct timeval x16320, x16321, x16322;
    gettimeofday(&x16320, NULL);
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x15426 = x15386;
      bool x15427 = !x15426;
      bool x15432 = x15427;
      if (x15427) {
        long x15428 = x15387;
        long x15429 = x12825;
        bool x15430 = x15428 < x15429;
        x15432 = x15430;
      }
      bool x15433 = x15432;
      if (!x15433) break;
      long x15435 = x15387;
      int* x15436 = x12827;
      int x15437 = x15436[x15435];
      char** x15438 = x12829;
      char* x15439 = x15438[x15435];
      x15387 = x15387 + 1;
      long x15447 = x15394;
      char** x15448 = x15391;
      x15448[x15447] = x15439;
      int* x15450 = x15393;
      x15450[x15447] = x15437;
      x15394 = x15394 + 1L;
      long x15453 = x15437 & x2212;
      long x15454 = x15395[x15453];
      x15395[x15453] = x15447;
      x15396[x15447] = x15454;
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x15460 = x15360;
      bool x15461 = !x15460;
      bool x15466 = x15461;
      if (x15461) {
        long x15462 = x15361;
        long x15463 = x14879;
        bool x15464 = x15462 < x15463;
        x15466 = x15464;
      }
      bool x15467 = x15466;
      if (!x15467) break;
      long x15469 = x15361;
      int* x15470 = x14881;
      int x15471 = x15470[x15469];
      int* x15476 = x14887;
      int x15477 = x15476[x15469];
      x15361 = x15361 + 1;
      long x15486 = x15377;
      int* x15487 = x15364;
      x15487[x15486] = x15471;
      int* x15493 = x15370;
      x15493[x15486] = x15477;
      x15377 = x15377 + 1L;
      long x15502 = x15471 & x2212;
      long x15503 = x15378[x15502];
      x15378[x15502] = x15486;
      x15379[x15486] = x15503;
    }
    printf("%s\n","begin scan REGION");
    for (;;) {
      bool x15509 = x15342;
      bool x15510 = !x15509;
      bool x15515 = x15510;
      if (x15510) {
        long x15511 = x15343;
        long x15512 = x12975;
        bool x15513 = x15511 < x15512;
        x15515 = x15513;
      }
      bool x15516 = x15515;
      if (!x15516) break;
      long x15518 = x15343;
      int* x15519 = x12977;
      int x15520 = x15519[x15518];
      char** x15521 = x12979;
      char* x15522 = x15521[x15518];
      x15343 = x15343 + 1;
      bool x15527 = tpch_strcmp(x15522,"AMERICA") == 0;;
      if (x15527) {
        long x15528 = x15352;
        int* x15529 = x15347;
        x15529[x15528] = x15520;
        x15352 = x15352 + 1L;
        long x15536 = x15520 & x2212;
        long x15537 = x15353[x15536];
        x15353[x15536] = x15528;
        x15354[x15528] = x15537;
      } else {
      }
    }
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x15545 = x15323;
      bool x15546 = !x15545;
      bool x15551 = x15546;
      if (x15546) {
        long x15547 = x15324;
        long x15548 = x12825;
        bool x15549 = x15547 < x15548;
        x15551 = x15549;
      }
      bool x15552 = x15551;
      if (!x15552) break;
      long x15554 = x15324;
      int* x15555 = x12827;
      int x15556 = x15555[x15554];
      int* x15559 = x12831;
      int x15560 = x15559[x15554];
      x15324 = x15324 + 1;
      long x15565 = x15334;
      int* x15566 = x15327;
      x15566[x15565] = x15556;
      int* x15570 = x15331;
      x15570[x15565] = x15560;
      x15334 = x15334 + 1L;
      long x15575 = x15556 & x2212;
      long x15576 = x15335[x15575];
      x15335[x15575] = x15565;
      x15336[x15565] = x15576;
    }
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x15582 = x15152;
      bool x15583 = !x15582;
      bool x15588 = x15583;
      if (x15583) {
        long x15584 = x15153;
        long x15585 = x13094;
        bool x15586 = x15584 < x15585;
        x15588 = x15586;
      }
      bool x15589 = x15588;
      if (!x15589) break;
      long x15591 = x15153;
      int* x15592 = x13096;
      int x15593 = x15592[x15591];
      char** x15600 = x13104;
      char* x15601 = x15600[x15591];
      x15153 = x15153 + 1;
      bool x15612 = tpch_strcmp(x15601,"ECONOMY ANODIZED STEEL") == 0;;
      if (x15612) {
        long x15613 = x15174;
        int* x15614 = x15157;
        x15614[x15613] = x15593;
        x15174 = x15174 + 1L;
        long x15633 = x15593 & x2212;
        long x15634 = x15175[x15633];
        x15175[x15633] = x15613;
        x15176[x15613] = x15634;
      } else {
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x15642 = x15150;
      bool x15643 = !x15642;
      bool x15648 = x15643;
      if (x15643) {
        long x15644 = x15151;
        long x15645 = x13788;
        bool x15646 = x15644 < x15645;
        x15648 = x15646;
      }
      bool x15649 = x15648;
      if (!x15649) break;
      long x15651 = x15151;
      int* x15652 = x13790;
      int x15653 = x15652[x15651];
      int* x15654 = x13792;
      int x15655 = x15654[x15651];
      int* x15656 = x13794;
      int x15657 = x15656[x15651];
      double* x15662 = x13800;
      double x15663 = x15662[x15651];
      double* x15664 = x13802;
      double x15665 = x15664[x15651];
      x15151 = x15151 + 1;
      long x15686 = x15655 & x2212;
      long x15687 = x15175[x15686];
      long x15688 = x15687;
      long x15770 = x15653 & x2212;
      for (;;) {
        long x15689 = x15688;
        bool x15690 = x15689 != -1;
        if (!x15690) break;
        long x15692 = x15688;
        int* x15693 = x15157;
        int x15694 = x15693[x15692];
        long x15712 = x15176[x15692];
        x15688 = x15712;
        bool x15714 = x15694 == x15655;
        if (x15714) {
          long x15718 = x15236;
          int* x15737 = x15205;
          x15737[x15718] = x15653;
          int* x15741 = x15209;
          x15741[x15718] = x15657;
          double* x15747 = x15215;
          x15747[x15718] = x15663;
          double* x15749 = x15217;
          x15749[x15718] = x15665;
          x15236 = x15236 + 1L;
          long x15771 = x15237[x15770];
          x15237[x15770] = x15718;
          x15238[x15718] = x15771;
        } else {
        }
      }
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x15781 = x15182;
      bool x15782 = !x15781;
      bool x15787 = x15782;
      if (x15782) {
        long x15783 = x15183;
        long x15784 = x13417;
        bool x15785 = x15783 < x15784;
        x15787 = x15785;
      }
      bool x15788 = x15787;
      if (!x15788) break;
      long x15790 = x15183;
      int* x15791 = x13419;
      int x15792 = x15791[x15790];
      int* x15793 = x13421;
      int x15794 = x15793[x15790];
      long* x15799 = x13427;
      long x15800 = x15799[x15790];
      x15183 = x15183 + 1;
      bool x15811 = x15800 >= 19950101L;
      bool x15813 = x15811;
      if (x15811) {
        bool x15812 = x15800 <= 19961231L;
        x15813 = x15812;
      }
      bool x15814 = x15813;
      if (x15814) {
        long x15815 = x15792 & x2212;
        long x15816 = x15237[x15815];
        long x15817 = x15816;
        long x15949 = x15794 & x2212;
        for (;;) {
          long x15818 = x15817;
          bool x15819 = x15818 != -1;
          if (!x15819) break;
          long x15821 = x15817;
          int* x15840 = x15205;
          int x15841 = x15840[x15821];
          int* x15844 = x15209;
          int x15845 = x15844[x15821];
          double* x15850 = x15215;
          double x15851 = x15850[x15821];
          double* x15852 = x15217;
          double x15853 = x15852[x15821];
          long x15873 = x15238[x15821];
          x15817 = x15873;
          bool x15875 = x15841 == x15792;
          if (x15875) {
            long x15879 = x15315;
            int* x15902 = x15270;
            x15902[x15879] = x15845;
            double* x15908 = x15276;
            x15908[x15879] = x15851;
            double* x15910 = x15278;
            x15910[x15879] = x15853;
            int* x15932 = x15300;
            x15932[x15879] = x15794;
            long* x15938 = x15306;
            x15938[x15879] = x15800;
            x15315 = x15315 + 1L;
            long x15950 = x15316[x15949];
            x15316[x15949] = x15879;
            x15317[x15879] = x15950;
          } else {
          }
        }
      } else {
      }
    }
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x15962 = x15244;
      bool x15963 = !x15962;
      bool x15968 = x15963;
      if (x15963) {
        long x15964 = x15245;
        long x15965 = x14582;
        bool x15966 = x15964 < x15965;
        x15968 = x15966;
      }
      bool x15969 = x15968;
      if (!x15969) break;
      long x15971 = x15245;
      int* x15972 = x14584;
      int x15973 = x15972[x15971];
      int* x15978 = x14590;
      int x15979 = x15978[x15971];
      x15245 = x15245 + 1;
      long x15990 = x15973 & x2212;
      long x15991 = x15316[x15990];
      long x15992 = x15991;
      long x16072 = x15979 & x2212;
      for (;;) {
        long x15993 = x15992;
        bool x15994 = x15993 != -1;
        if (!x15994) break;
        long x15996 = x15992;
        int* x16019 = x15270;
        int x16020 = x16019[x15996];
        double* x16025 = x15276;
        double x16026 = x16025[x15996];
        double* x16027 = x15278;
        double x16028 = x16027[x15996];
        int* x16049 = x15300;
        int x16050 = x16049[x15996];
        long* x16055 = x15306;
        long x16056 = x16055[x15996];
        long x16066 = x15317[x15996];
        x15992 = x16066;
        bool x16068 = x16050 == x15973;
        if (x16068) {
          long x16073 = x15335[x16072];
          long x16074 = x16073;
          long x16114 = x16020 & x2212;
          long x16161 = x16056; // date
          long x16162 = x16161/10000;
          int x16163 = (int)x16162;
          long x16164 = x16163 & x823;
          double x16178 = 1.0 - x16028;
          double x16179 = x16026 * x16178;
          for (;;) {
            long x16075 = x16074;
            bool x16076 = x16075 != -1;
            if (!x16076) break;
            long x16078 = x16074;
            int* x16079 = x15327;
            int x16080 = x16079[x16078];
            int* x16083 = x15331;
            int x16084 = x16083[x16078];
            long x16088 = x15336[x16078];
            x16074 = x16088;
            bool x16090 = x16080 == x15979;
            if (x16090) {
              long x16094 = x16084 & x2212;
              long x16095 = x15353[x16094];
              long x16096 = x16095;
              for (;;) {
                long x16097 = x16096;
                bool x16098 = x16097 != -1;
                if (!x16098) break;
                long x16100 = x16096;
                int* x16101 = x15347;
                int x16102 = x16101[x16100];
                long x16108 = x15354[x16100];
                x16096 = x16108;
                bool x16110 = x16102 == x16084;
                if (x16110) {
                  long x16115 = x15378[x16114];
                  long x16116 = x16115;
                  for (;;) {
                    long x16117 = x16116;
                    bool x16118 = x16117 != -1;
                    if (!x16118) break;
                    long x16120 = x16116;
                    int* x16121 = x15364;
                    int x16122 = x16121[x16120];
                    int* x16127 = x15370;
                    int x16128 = x16127[x16120];
                    long x16136 = x15379[x16120];
                    x16116 = x16136;
                    bool x16138 = x16122 == x16020;
                    if (x16138) {
                      long x16143 = x16128 & x2212;
                      long x16144 = x15395[x16143];
                      long x16145 = x16144;
                      for (;;) {
                        long x16146 = x16145;
                        bool x16147 = x16146 != -1;
                        if (!x16147) break;
                        long x16149 = x16145;
                        char** x16150 = x15391;
                        char* x16151 = x16150[x16149];
                        int* x16152 = x15393;
                        int x16153 = x16152[x16149];
                        long x16155 = x15396[x16149];
                        x16145 = x16155;
                        bool x16157 = x16153 == x16128;
                        if (x16157) {
                          long x16165 = x16164;
                          struct Anon401726059* x16166 = x15405;
                          struct Anon401726059 x16167 = x16166[x16164];
                          struct Anon401726059 x16168 = x16167;
                          bool x16169 = x16167.exists;;
                          bool x16174 = x16169;
                          if (x16169) {
                            struct Anon401726059 x16170 = x16168;
                            int x16171 = x16170.key;;
                            bool x16172 = x16171 == x16163;
                            x16174 = x16172;
                          }
                          bool x16175 = x16174;
                          if (x16175) {
                            struct Anon189208763 x16176 = x16167.aggs;;
                            int x16186 = x16167.key;;
                            double x16177 = x16176._0;;
                            double x16180 = x16177 + x16179;
                            bool x16181 = tpch_strcmp(x16151,"BRAZIL") == 0;;
                            double x16184;
                            if (x16181) {
                              double x16182 = x16176._1;;
                              double x16183 = x16182 + x16179;
                              x16184 = x16183;
                            } else {
                              double x16182 = x16176._1;;
                              x16184 = x16182;
                            }
                            struct Anon189208763 x16185;
                            x16185._0 = x16180;
                            x16185._1 = x16184;
                            struct Anon401726059 x16187;
                            x16187.exists = true;
                            x16187.key = x16186;
                            x16187.aggs = x16185;
                            x16166[x16164] = x16187;
                          } else {
                            bool x16181 = tpch_strcmp(x16151,"BRAZIL") == 0;;
                            double x16219;
                            if (x16181) {
                              x16219 = x16179;
                            } else {
                              x16219 = 0.0;
                            }
                            struct Anon189208763 x16220;
                            x16220._0 = x16179;
                            x16220._1 = x16219;
                            struct Anon401726059 x16221;
                            x16221.exists = true;
                            x16221.key = x16163;
                            x16221.aggs = x16220;
                            for (;;) {
                              struct Anon401726059 x16190 = x16168;
                              bool x16191 = x16190.exists;;
                              bool x16230;
                              if (x16191) {
                                int x16192 = x16190.key;;
                                bool x16193 = x16192 == x16163;
                                bool x16216;
                                if (x16193) {
                                  struct Anon189208763 x16194 = x16190.aggs;;
                                  long x16201 = x16165;
                                  struct Anon401726059* x16203 = x15405;
                                  double x16195 = x16194._0;;
                                  double x16196 = x16195 + x16179;
                                  double x16199;
                                  if (x16181) {
                                    double x16197 = x16194._1;;
                                    double x16198 = x16197 + x16179;
                                    x16199 = x16198;
                                  } else {
                                    double x16197 = x16194._1;;
                                    x16199 = x16197;
                                  }
                                  struct Anon189208763 x16200;
                                  x16200._0 = x16196;
                                  x16200._1 = x16199;
                                  struct Anon401726059 x16202;
                                  x16202.exists = true;
                                  x16202.key = x16192;
                                  x16202.aggs = x16200;
                                  x16203[x16201] = x16202;
                                  x16216 = false;
                                } else {
                                  long x16206 = x16165;
                                  long x16207 = x16206 + 1L;
                                  long x16208 = x16207 & x823;
                                  x16165 = x16208;
                                  struct Anon401726059* x16210 = x15405;
                                  struct Anon401726059 x16211 = x16210[x16208];
                                  x16168 = x16211;
                                  x16216 = true;
                                }
                                x16230 = x16216;
                              } else {
                                long x16218 = x16165;
                                struct Anon401726059* x16222 = x15405;
                                x16222[x16218] = x16221;
                                long x16224 = x15406;
                                x15407[x16224] = x16218;
                                x15406 = x15406 + 1L;
                                x16230 = false;
                              }
                              if (!x16230) break;
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
    long x16259 = x15406;
    long x16261;
    for(x16261=0L; x16261 < x16259; x16261++) {
      long x16262 = x15407[x16261];
      struct Anon401726059* x16263 = x15405;
      struct Anon401726059 x16264 = x16263[x16262];
      int x16265 = x16264.key;;
      struct Anon189208763 x16266 = x16264.aggs;;
      long x16272 = x15420;
      long x16273 = x15419;
      bool x16274 = x16272 == x16273;
      if (x16274) {
        long x16275 = x16273 * 4L;
        x15419 = x16275;
        struct Anon108365162* x16277 = x15422;
        struct Anon108365162* x16278 = (struct Anon108365162 *)realloc(x16277,x16275* sizeof(struct Anon108365162));
        x15422 = x16278;
      } else {
      }
      struct Anon108365162* x16282 = x15422;
      double x16267 = x16266._1;;
      double x16268 = x16266._0;;
      double x16269 = x16267 / x16268;
      struct Anon2052879268 x16270;
      x16270._2 = x16269;
      struct Anon108365162 x16271;
      x16271.key = x16265;
      x16271.aggs = x16270;
      x16282[x16272] = x16271;
      x15420 = x15420 + 1;
    }
    long x16287 = x15420;
    struct Anon108365162* x16288 = x15422;
    qsort((void *)x16288,x16287,sizeof(struct Anon108365162), (__compar_fn_t)x16300); // x16301
    long x16303;
    for(x16303=0L; x16303 < x16287; x16303++) {
      struct Anon108365162* x16304 = x15422;
      struct Anon108365162 x16305 = x16304[x16303];
      if (x1043) {
      } else {
        int x16308 = x16305.key;;
        struct Anon2052879268 x16309 = x16305.aggs;;
        double x16310 = x16309._2;;
        printf("%d|%.5f\n",x16308,x16310);
        x15424 = x15424 + 1L;
      }
    }
    long x16317 = x15424;
    printf("(%ld rows)\n",x16317);
    gettimeofday(&x16321, NULL);
    timeval_subtract(&x16322, &x16321, &x16320);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x16322.tv_sec * 1000) + (x16322.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
