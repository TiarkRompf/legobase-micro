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

struct Anon1711779607 {
int C_CUSTKEY;
char* C_NAME;
double C_ACCTBAL;
char* C_PHONE;
char* N_NAME;
char* C_ADDRESS;
char* C_COMMENT;
};

struct Anon2052879266 {
double _0;
};

struct Anon1678583810 {
bool exists;
struct Anon1711779607 key;
struct Anon2052879266 aggs;
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

struct Anon1548200872 {
char* NATION;
int O_YEAR;
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

struct Anon1495587458 {
int key;
struct Anon1023322325 wnd;
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

struct Anon2101649069 {
bool exists;
struct Anon1548200872 key;
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

struct Anon2052879268 {
double _2;
};

struct Anon108365162 {
int key;
struct Anon2052879268 aggs;
};

/************************ FUNCTIONS **************************/
int x21700(struct Anon1678583810* x21687, struct Anon1678583810* x21688);
int x21700(struct Anon1678583810* x21687, struct Anon1678583810* x21688) {
  struct Anon1678583810 x21689 = (*x21687);
  struct Anon1678583810 x21690 = (*x21688);
  struct Anon2052879266 x21691 = x21689.aggs;;
  double x21692 = x21691._0;;
  struct Anon2052879266 x21693 = x21690.aggs;;
  double x21694 = x21693._0;;
  bool x21695 = x21692 < x21694;
  int x21698;
  if (x21695) {
    x21698 = 1;
  } else {
    bool x21696 = x21692 > x21694;
    int x21697;
    if (x21696) {
      x21697 = -1;
    } else {
      x21697 = 0;
    }
    x21698 = x21697;
  }
  return x21698;
}

/************************ MAIN BODY **************************/
int main(int x19437, char** x19438) {
  long x19439 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x19440 = x7;
  long x19441 = 0L;
  int* x19442 = (int*)malloc(x7 * sizeof(int));
  int* x19443 = x19442;
  double* x19452 = (double*)malloc(x7 * sizeof(double));
  double* x19453 = x19452;
  double* x19454 = (double*)malloc(x7 * sizeof(double));
  double* x19455 = x19454;
  char* x19458 = (char*)malloc(x7 * sizeof(char));
  char* x19459 = x19458;
  int x3 = open("XXXXXlineitem.tbl",0);
  long x4 = fsize(x3);
  char* x5 = mmap(0, x4, PROT_READ, MAP_FILE | MAP_SHARED, x3, 0);
  for (;;) {
    long x19474 = x19439;
    bool x19475 = x19474 < x4;
    if (!x19475) break;
    int x19478 = 0;
    for (;;) {
      long x19479 = x19439;
      char x19480 = x5[x19479];
      bool x19481 = x19480 != '|';
      bool x19486 = x19481;
      if (x19481) {
        long x19482 = x19439;
        char x19483 = x5[x19482];
        bool x19484 = x19483 != '\n';
        x19486 = x19484;
      }
      bool x19487 = x19486;
      if (!x19487) break;
      int x19489 = x19478;
      long x19491 = x19439;
      int x19490 = x19489 * 10;
      char x19492 = x5[x19491];
      char x19493 = x19492 - '0';
      int x19494 = x19490 + x19493;
      x19478 = x19494;
      x19439 = x19439 + 1;
    }
    x19439 = x19439 + 1;
    int x19500 = x19478;
    for (;;) {
      long x19503 = x19439;
      char x19504 = x5[x19503];
      bool x19505 = x19504 != '|';
      bool x19510 = x19505;
      if (x19505) {
        long x19506 = x19439;
        char x19507 = x5[x19506];
        bool x19508 = x19507 != '\n';
        x19510 = x19508;
      }
      bool x19511 = x19510;
      if (!x19511) break;
      x19439 = x19439 + 1;
    }
    x19439 = x19439 + 1;
    for (;;) {
      long x19527 = x19439;
      char x19528 = x5[x19527];
      bool x19529 = x19528 != '|';
      bool x19534 = x19529;
      if (x19529) {
        long x19530 = x19439;
        char x19531 = x5[x19530];
        bool x19532 = x19531 != '\n';
        x19534 = x19532;
      }
      bool x19535 = x19534;
      if (!x19535) break;
      x19439 = x19439 + 1;
    }
    x19439 = x19439 + 1;
    for (;;) {
      long x19551 = x19439;
      char x19552 = x5[x19551];
      bool x19553 = x19552 != '|';
      bool x19558 = x19553;
      if (x19553) {
        long x19554 = x19439;
        char x19555 = x5[x19554];
        bool x19556 = x19555 != '\n';
        x19558 = x19556;
      }
      bool x19559 = x19558;
      if (!x19559) break;
      x19439 = x19439 + 1;
    }
    x19439 = x19439 + 1;
    for (;;) {
      long x19576 = x19439;
      char x19577 = x5[x19576];
      bool x19578 = x19577 != '.';
      bool x19583 = x19578;
      if (x19578) {
        long x19579 = x19439;
        char x19580 = x5[x19579];
        bool x19581 = x19580 != '|';
        x19583 = x19581;
      }
      bool x19584 = x19583;
      bool x19589 = x19584;
      if (x19584) {
        long x19585 = x19439;
        char x19586 = x5[x19585];
        bool x19587 = x19586 != '\n';
        x19589 = x19587;
      }
      bool x19590 = x19589;
      if (!x19590) break;
      x19439 = x19439 + 1;
    }
    long x19602 = x19439;
    char x19603 = x5[x19602];
    bool x19604 = x19603 == '.';
    if (x19604) {
      x19439 = x19439 + 1;
      for (;;) {
        long x19606 = x19439;
        char x19607 = x5[x19606];
        bool x19608 = x19607 != '|';
        bool x19613 = x19608;
        if (x19608) {
          long x19609 = x19439;
          char x19610 = x5[x19609];
          bool x19611 = x19610 != '\n';
          x19613 = x19611;
        }
        bool x19614 = x19613;
        if (!x19614) break;
        x19439 = x19439 + 1;
      }
    } else {
    }
    x19439 = x19439 + 1;
    int x19639 = 0;
    int x19640 = 1;
    for (;;) {
      long x19641 = x19439;
      char x19642 = x5[x19641];
      bool x19643 = x19642 != '.';
      bool x19648 = x19643;
      if (x19643) {
        long x19644 = x19439;
        char x19645 = x5[x19644];
        bool x19646 = x19645 != '|';
        x19648 = x19646;
      }
      bool x19649 = x19648;
      bool x19654 = x19649;
      if (x19649) {
        long x19650 = x19439;
        char x19651 = x5[x19650];
        bool x19652 = x19651 != '\n';
        x19654 = x19652;
      }
      bool x19655 = x19654;
      if (!x19655) break;
      int x19657 = x19639;
      long x19659 = x19439;
      int x19658 = x19657 * 10;
      char x19660 = x5[x19659];
      char x19661 = x19660 - '0';
      int x19662 = x19658 + x19661;
      x19639 = x19662;
      x19439 = x19439 + 1;
    }
    long x19667 = x19439;
    char x19668 = x5[x19667];
    bool x19669 = x19668 == '.';
    if (x19669) {
      x19439 = x19439 + 1;
      for (;;) {
        long x19671 = x19439;
        char x19672 = x5[x19671];
        bool x19673 = x19672 != '|';
        bool x19678 = x19673;
        if (x19673) {
          long x19674 = x19439;
          char x19675 = x5[x19674];
          bool x19676 = x19675 != '\n';
          x19678 = x19676;
        }
        bool x19679 = x19678;
        if (!x19679) break;
        int x19681 = x19639;
        long x19683 = x19439;
        int x19682 = x19681 * 10;
        char x19684 = x5[x19683];
        char x19685 = x19684 - '0';
        int x19686 = x19682 + x19685;
        x19639 = x19686;
        int x19688 = x19640;
        int x19689 = x19688 * 10;
        x19640 = x19689;
        x19439 = x19439 + 1;
      }
    } else {
    }
    x19439 = x19439 + 1;
    int x19698 = x19639;
    int x19700 = x19640;
    int x19704 = 0;
    int x19705 = 1;
    for (;;) {
      long x19706 = x19439;
      char x19707 = x5[x19706];
      bool x19708 = x19707 != '.';
      bool x19713 = x19708;
      if (x19708) {
        long x19709 = x19439;
        char x19710 = x5[x19709];
        bool x19711 = x19710 != '|';
        x19713 = x19711;
      }
      bool x19714 = x19713;
      bool x19719 = x19714;
      if (x19714) {
        long x19715 = x19439;
        char x19716 = x5[x19715];
        bool x19717 = x19716 != '\n';
        x19719 = x19717;
      }
      bool x19720 = x19719;
      if (!x19720) break;
      int x19722 = x19704;
      long x19724 = x19439;
      int x19723 = x19722 * 10;
      char x19725 = x5[x19724];
      char x19726 = x19725 - '0';
      int x19727 = x19723 + x19726;
      x19704 = x19727;
      x19439 = x19439 + 1;
    }
    long x19732 = x19439;
    char x19733 = x5[x19732];
    bool x19734 = x19733 == '.';
    if (x19734) {
      x19439 = x19439 + 1;
      for (;;) {
        long x19736 = x19439;
        char x19737 = x5[x19736];
        bool x19738 = x19737 != '|';
        bool x19743 = x19738;
        if (x19738) {
          long x19739 = x19439;
          char x19740 = x5[x19739];
          bool x19741 = x19740 != '\n';
          x19743 = x19741;
        }
        bool x19744 = x19743;
        if (!x19744) break;
        int x19746 = x19704;
        long x19748 = x19439;
        int x19747 = x19746 * 10;
        char x19749 = x5[x19748];
        char x19750 = x19749 - '0';
        int x19751 = x19747 + x19750;
        x19704 = x19751;
        int x19753 = x19705;
        int x19754 = x19753 * 10;
        x19705 = x19754;
        x19439 = x19439 + 1;
      }
    } else {
    }
    x19439 = x19439 + 1;
    int x19763 = x19704;
    int x19765 = x19705;
    for (;;) {
      long x19771 = x19439;
      char x19772 = x5[x19771];
      bool x19773 = x19772 != '.';
      bool x19778 = x19773;
      if (x19773) {
        long x19774 = x19439;
        char x19775 = x5[x19774];
        bool x19776 = x19775 != '|';
        x19778 = x19776;
      }
      bool x19779 = x19778;
      bool x19784 = x19779;
      if (x19779) {
        long x19780 = x19439;
        char x19781 = x5[x19780];
        bool x19782 = x19781 != '\n';
        x19784 = x19782;
      }
      bool x19785 = x19784;
      if (!x19785) break;
      x19439 = x19439 + 1;
    }
    long x19797 = x19439;
    char x19798 = x5[x19797];
    bool x19799 = x19798 == '.';
    if (x19799) {
      x19439 = x19439 + 1;
      for (;;) {
        long x19801 = x19439;
        char x19802 = x5[x19801];
        bool x19803 = x19802 != '|';
        bool x19808 = x19803;
        if (x19803) {
          long x19804 = x19439;
          char x19805 = x5[x19804];
          bool x19806 = x19805 != '\n';
          x19808 = x19806;
        }
        bool x19809 = x19808;
        if (!x19809) break;
        x19439 = x19439 + 1;
      }
    } else {
    }
    x19439 = x19439 + 1;
    long x19833 = x19439;
    x19439 = x19439 + 2;
    x19439 = x19439 + 2;
    for (;;) {
      long x19841 = x19439;
      char x19842 = x5[x19841];
      bool x19843 = x19842 != '-';
      bool x19848 = x19843;
      if (x19843) {
        long x19844 = x19439;
        char x19845 = x5[x19844];
        bool x19846 = x19845 != '\n';
        x19848 = x19846;
      }
      bool x19849 = x19848;
      if (!x19849) break;
      x19439 = x19439 + 1;
    }
    x19439 = x19439 + 1;
    for (;;) {
      long x19865 = x19439;
      char x19866 = x5[x19865];
      bool x19867 = x19866 != '-';
      bool x19872 = x19867;
      if (x19867) {
        long x19868 = x19439;
        char x19869 = x5[x19868];
        bool x19870 = x19869 != '\n';
        x19872 = x19870;
      }
      bool x19873 = x19872;
      if (!x19873) break;
      x19439 = x19439 + 1;
    }
    x19439 = x19439 + 1;
    for (;;) {
      long x19889 = x19439;
      char x19890 = x5[x19889];
      bool x19891 = x19890 != '|';
      bool x19896 = x19891;
      if (x19891) {
        long x19892 = x19439;
        char x19893 = x5[x19892];
        bool x19894 = x19893 != '\n';
        x19896 = x19894;
      }
      bool x19897 = x19896;
      if (!x19897) break;
      x19439 = x19439 + 1;
    }
    x19439 = x19439 + 1;
    for (;;) {
      long x19917 = x19439;
      char x19918 = x5[x19917];
      bool x19919 = x19918 != '-';
      bool x19924 = x19919;
      if (x19919) {
        long x19920 = x19439;
        char x19921 = x5[x19920];
        bool x19922 = x19921 != '\n';
        x19924 = x19922;
      }
      bool x19925 = x19924;
      if (!x19925) break;
      x19439 = x19439 + 1;
    }
    x19439 = x19439 + 1;
    for (;;) {
      long x19941 = x19439;
      char x19942 = x5[x19941];
      bool x19943 = x19942 != '-';
      bool x19948 = x19943;
      if (x19943) {
        long x19944 = x19439;
        char x19945 = x5[x19944];
        bool x19946 = x19945 != '\n';
        x19948 = x19946;
      }
      bool x19949 = x19948;
      if (!x19949) break;
      x19439 = x19439 + 1;
    }
    x19439 = x19439 + 1;
    for (;;) {
      long x19965 = x19439;
      char x19966 = x5[x19965];
      bool x19967 = x19966 != '|';
      bool x19972 = x19967;
      if (x19967) {
        long x19968 = x19439;
        char x19969 = x5[x19968];
        bool x19970 = x19969 != '\n';
        x19972 = x19970;
      }
      bool x19973 = x19972;
      if (!x19973) break;
      x19439 = x19439 + 1;
    }
    x19439 = x19439 + 1;
    for (;;) {
      long x19993 = x19439;
      char x19994 = x5[x19993];
      bool x19995 = x19994 != '-';
      bool x20000 = x19995;
      if (x19995) {
        long x19996 = x19439;
        char x19997 = x5[x19996];
        bool x19998 = x19997 != '\n';
        x20000 = x19998;
      }
      bool x20001 = x20000;
      if (!x20001) break;
      x19439 = x19439 + 1;
    }
    x19439 = x19439 + 1;
    for (;;) {
      long x20017 = x19439;
      char x20018 = x5[x20017];
      bool x20019 = x20018 != '-';
      bool x20024 = x20019;
      if (x20019) {
        long x20020 = x19439;
        char x20021 = x5[x20020];
        bool x20022 = x20021 != '\n';
        x20024 = x20022;
      }
      bool x20025 = x20024;
      if (!x20025) break;
      x19439 = x19439 + 1;
    }
    x19439 = x19439 + 1;
    for (;;) {
      long x20041 = x19439;
      char x20042 = x5[x20041];
      bool x20043 = x20042 != '|';
      bool x20048 = x20043;
      if (x20043) {
        long x20044 = x19439;
        char x20045 = x5[x20044];
        bool x20046 = x20045 != '\n';
        x20048 = x20046;
      }
      bool x20049 = x20048;
      if (!x20049) break;
      x19439 = x19439 + 1;
    }
    x19439 = x19439 + 1;
    for (;;) {
      long x20068 = x19439;
      char x20069 = x5[x20068];
      bool x20070 = x20069 != '|';
      bool x20075 = x20070;
      if (x20070) {
        long x20071 = x19439;
        char x20072 = x5[x20071];
        bool x20073 = x20072 != '\n';
        x20075 = x20073;
      }
      bool x20076 = x20075;
      if (!x20076) break;
      x19439 = x19439 + 1;
    }
    x19439 = x19439 + 1;
    for (;;) {
      long x20086 = x19439;
      char x20087 = x5[x20086];
      bool x20088 = x20087 != '|';
      bool x20093 = x20088;
      if (x20088) {
        long x20089 = x19439;
        char x20090 = x5[x20089];
        bool x20091 = x20090 != '\n';
        x20093 = x20091;
      }
      bool x20094 = x20093;
      if (!x20094) break;
      x19439 = x19439 + 1;
    }
    x19439 = x19439 + 1;
    for (;;) {
      long x20104 = x19439;
      char x20105 = x5[x20104];
      bool x20106 = x20105 != '|';
      bool x20111 = x20106;
      if (x20106) {
        long x20107 = x19439;
        char x20108 = x5[x20107];
        bool x20109 = x20108 != '\n';
        x20111 = x20109;
      }
      bool x20112 = x20111;
      if (!x20112) break;
      x19439 = x19439 + 1;
    }
    x19439 = x19439 + 1;
    long x20122 = x19439;
    bool x20123 = x20122 > 0L;
    bool x20129 = x20123;
    if (x20123) {
      long x20124 = x19439;
      long x20125 = x20124 - 1L;
      char x20126 = x5[x20125];
      bool x20127 = x20126 != '\n';
      x20129 = x20127;
    }
    bool x20130 = x20129;
    if (x20130) {
      for (;;) {
        long x20131 = x19439;
        char x20132 = x5[x20131];
        bool x20133 = x20132 != '\n';
        if (!x20133) break;
        x19439 = x19439 + 1;
      }
    } else {
    }
    x19439 = x19439 + 1;
    long x20142 = x19441;
    long x20143 = x19440;
    bool x20144 = x20142 == x20143;
    if (x20144) {
      long x20145 = x20143 * 4L;
      x19440 = x20145;
      printf("buffer.resize %ld\n",x20145);
      int* x20148 = x19443;
      int* x20149 = (int*)realloc(x20148,x20145 * sizeof(int));
      x19443 = x20149;
      double* x20163 = x19453;
      double* x20164 = (double*)realloc(x20163,x20145 * sizeof(double));
      x19453 = x20164;
      double* x20166 = x19455;
      double* x20167 = (double*)realloc(x20166,x20145 * sizeof(double));
      x19455 = x20167;
      char* x20172 = x19459;
      char* x20173 = (char*)realloc(x20172,x20145 * sizeof(char));
      x19459 = x20173;
    } else {
    }
    int* x20198 = x19443;
    x20198[x20142] = x19500;
    double* x20208 = x19453;
    double x19699 = (double)x19698;
    double x19701 = (double)x19700;
    double x19702 = x19699 / x19701;
    x20208[x20142] = x19702;
    double* x20210 = x19455;
    double x19764 = (double)x19763;
    double x19766 = (double)x19765;
    double x19767 = x19764 / x19766;
    x20210[x20142] = x19767;
    char* x20214 = x19459;
    char x19834 = x5[x19833];
    x20214[x20142] = x19834;
    x19441 = x19441 + 1;
  }
  long x20233 = 0L;
  long x20234 = x7;
  long x20235 = 0L;
  int* x20236 = (int*)malloc(x7 * sizeof(int));
  int* x20237 = x20236;
  char** x20238 = (char**)malloc(x7 * sizeof(char*));
  char** x20239 = x20238;
  int x1633 = open("XXXXXnation.tbl",0);
  long x1634 = fsize(x1633);
  char* x1635 = mmap(0, x1634, PROT_READ, MAP_FILE | MAP_SHARED, x1633, 0);
  for (;;) {
    long x20244 = x20233;
    bool x20245 = x20244 < x1634;
    if (!x20245) break;
    int x20248 = 0;
    for (;;) {
      long x20249 = x20233;
      char x20250 = x1635[x20249];
      bool x20251 = x20250 != '|';
      bool x20256 = x20251;
      if (x20251) {
        long x20252 = x20233;
        char x20253 = x1635[x20252];
        bool x20254 = x20253 != '\n';
        x20256 = x20254;
      }
      bool x20257 = x20256;
      if (!x20257) break;
      int x20259 = x20248;
      long x20261 = x20233;
      int x20260 = x20259 * 10;
      char x20262 = x1635[x20261];
      char x20263 = x20262 - '0';
      int x20264 = x20260 + x20263;
      x20248 = x20264;
      x20233 = x20233 + 1;
    }
    x20233 = x20233 + 1;
    int x20270 = x20248;
    long x20271 = x20233;
    for (;;) {
      long x20272 = x20233;
      char x20273 = x1635[x20272];
      bool x20274 = x20273 != '|';
      bool x20279 = x20274;
      if (x20274) {
        long x20275 = x20233;
        char x20276 = x1635[x20275];
        bool x20277 = x20276 != '\n';
        x20279 = x20277;
      }
      bool x20280 = x20279;
      if (!x20280) break;
      x20233 = x20233 + 1;
    }
    x20233 = x20233 + 1;
    for (;;) {
      long x20291 = x20233;
      char x20292 = x1635[x20291];
      bool x20293 = x20292 != '|';
      bool x20298 = x20293;
      if (x20293) {
        long x20294 = x20233;
        char x20295 = x1635[x20294];
        bool x20296 = x20295 != '\n';
        x20298 = x20296;
      }
      bool x20299 = x20298;
      if (!x20299) break;
      x20233 = x20233 + 1;
    }
    x20233 = x20233 + 1;
    for (;;) {
      long x20314 = x20233;
      char x20315 = x1635[x20314];
      bool x20316 = x20315 != '|';
      bool x20321 = x20316;
      if (x20316) {
        long x20317 = x20233;
        char x20318 = x1635[x20317];
        bool x20319 = x20318 != '\n';
        x20321 = x20319;
      }
      bool x20322 = x20321;
      if (!x20322) break;
      x20233 = x20233 + 1;
    }
    x20233 = x20233 + 1;
    long x20332 = x20233;
    bool x20333 = x20332 > 0L;
    bool x20339 = x20333;
    if (x20333) {
      long x20334 = x20233;
      long x20335 = x20334 - 1L;
      char x20336 = x1635[x20335];
      bool x20337 = x20336 != '\n';
      x20339 = x20337;
    }
    bool x20340 = x20339;
    if (x20340) {
      for (;;) {
        long x20341 = x20233;
        char x20342 = x1635[x20341];
        bool x20343 = x20342 != '\n';
        if (!x20343) break;
        x20233 = x20233 + 1;
      }
    } else {
    }
    x20233 = x20233 + 1;
    long x20352 = x20235;
    long x20353 = x20234;
    bool x20354 = x20352 == x20353;
    if (x20354) {
      long x20355 = x20353 * 4L;
      x20234 = x20355;
      printf("buffer.resize %ld\n",x20355);
      int* x20358 = x20237;
      int* x20359 = (int*)realloc(x20358,x20355 * sizeof(int));
      x20237 = x20359;
      char** x20361 = x20239;
      char** x20362 = (char**)realloc(x20361,x20355 * sizeof(char*));
      x20239 = x20362;
    } else {
    }
    int* x20372 = x20237;
    x20372[x20352] = x20270;
    char** x20374 = x20239;
    char* x20288 = x1635+x20271;
    x20374[x20352] = x20288;
    x20235 = x20235 + 1;
  }
  long x20383 = 0L;
  long x20384 = x7;
  long x20385 = 0L;
  int* x20386 = (int*)malloc(x7 * sizeof(int));
  int* x20387 = x20386;
  char** x20388 = (char**)malloc(x7 * sizeof(char*));
  char** x20389 = x20388;
  char** x20390 = (char**)malloc(x7 * sizeof(char*));
  char** x20391 = x20390;
  int* x20392 = (int*)malloc(x7 * sizeof(int));
  int* x20393 = x20392;
  char** x20394 = (char**)malloc(x7 * sizeof(char*));
  char** x20395 = x20394;
  double* x20396 = (double*)malloc(x7 * sizeof(double));
  double* x20397 = x20396;
  char** x20400 = (char**)malloc(x7 * sizeof(char*));
  char** x20401 = x20400;
  int x4007 = open("XXXXXcustomer.tbl",0);
  long x4008 = fsize(x4007);
  char* x4009 = mmap(0, x4008, PROT_READ, MAP_FILE | MAP_SHARED, x4007, 0);
  for (;;) {
    long x20402 = x20383;
    bool x20403 = x20402 < x4008;
    if (!x20403) break;
    int x20406 = 0;
    for (;;) {
      long x20407 = x20383;
      char x20408 = x4009[x20407];
      bool x20409 = x20408 != '|';
      bool x20414 = x20409;
      if (x20409) {
        long x20410 = x20383;
        char x20411 = x4009[x20410];
        bool x20412 = x20411 != '\n';
        x20414 = x20412;
      }
      bool x20415 = x20414;
      if (!x20415) break;
      int x20417 = x20406;
      long x20419 = x20383;
      int x20418 = x20417 * 10;
      char x20420 = x4009[x20419];
      char x20421 = x20420 - '0';
      int x20422 = x20418 + x20421;
      x20406 = x20422;
      x20383 = x20383 + 1;
    }
    x20383 = x20383 + 1;
    int x20428 = x20406;
    long x20429 = x20383;
    for (;;) {
      long x20430 = x20383;
      char x20431 = x4009[x20430];
      bool x20432 = x20431 != '|';
      bool x20437 = x20432;
      if (x20432) {
        long x20433 = x20383;
        char x20434 = x4009[x20433];
        bool x20435 = x20434 != '\n';
        x20437 = x20435;
      }
      bool x20438 = x20437;
      if (!x20438) break;
      x20383 = x20383 + 1;
    }
    x20383 = x20383 + 1;
    long x20447 = x20383;
    for (;;) {
      long x20448 = x20383;
      char x20449 = x4009[x20448];
      bool x20450 = x20449 != '|';
      bool x20455 = x20450;
      if (x20450) {
        long x20451 = x20383;
        char x20452 = x4009[x20451];
        bool x20453 = x20452 != '\n';
        x20455 = x20453;
      }
      bool x20456 = x20455;
      if (!x20456) break;
      x20383 = x20383 + 1;
    }
    x20383 = x20383 + 1;
    int x20466 = 0;
    for (;;) {
      long x20467 = x20383;
      char x20468 = x4009[x20467];
      bool x20469 = x20468 != '|';
      bool x20474 = x20469;
      if (x20469) {
        long x20470 = x20383;
        char x20471 = x4009[x20470];
        bool x20472 = x20471 != '\n';
        x20474 = x20472;
      }
      bool x20475 = x20474;
      if (!x20475) break;
      int x20477 = x20466;
      long x20479 = x20383;
      int x20478 = x20477 * 10;
      char x20480 = x4009[x20479];
      char x20481 = x20480 - '0';
      int x20482 = x20478 + x20481;
      x20466 = x20482;
      x20383 = x20383 + 1;
    }
    x20383 = x20383 + 1;
    int x20488 = x20466;
    long x20489 = x20383;
    for (;;) {
      long x20490 = x20383;
      char x20491 = x4009[x20490];
      bool x20492 = x20491 != '|';
      bool x20497 = x20492;
      if (x20492) {
        long x20493 = x20383;
        char x20494 = x4009[x20493];
        bool x20495 = x20494 != '\n';
        x20497 = x20495;
      }
      bool x20498 = x20497;
      if (!x20498) break;
      x20383 = x20383 + 1;
    }
    x20383 = x20383 + 1;
    int x20508 = 0;
    int x20509 = 1;
    for (;;) {
      long x20510 = x20383;
      char x20511 = x4009[x20510];
      bool x20512 = x20511 != '.';
      bool x20517 = x20512;
      if (x20512) {
        long x20513 = x20383;
        char x20514 = x4009[x20513];
        bool x20515 = x20514 != '|';
        x20517 = x20515;
      }
      bool x20518 = x20517;
      bool x20523 = x20518;
      if (x20518) {
        long x20519 = x20383;
        char x20520 = x4009[x20519];
        bool x20521 = x20520 != '\n';
        x20523 = x20521;
      }
      bool x20524 = x20523;
      if (!x20524) break;
      int x20526 = x20508;
      long x20528 = x20383;
      int x20527 = x20526 * 10;
      char x20529 = x4009[x20528];
      char x20530 = x20529 - '0';
      int x20531 = x20527 + x20530;
      x20508 = x20531;
      x20383 = x20383 + 1;
    }
    long x20536 = x20383;
    char x20537 = x4009[x20536];
    bool x20538 = x20537 == '.';
    if (x20538) {
      x20383 = x20383 + 1;
      for (;;) {
        long x20540 = x20383;
        char x20541 = x4009[x20540];
        bool x20542 = x20541 != '|';
        bool x20547 = x20542;
        if (x20542) {
          long x20543 = x20383;
          char x20544 = x4009[x20543];
          bool x20545 = x20544 != '\n';
          x20547 = x20545;
        }
        bool x20548 = x20547;
        if (!x20548) break;
        int x20550 = x20508;
        long x20552 = x20383;
        int x20551 = x20550 * 10;
        char x20553 = x4009[x20552];
        char x20554 = x20553 - '0';
        int x20555 = x20551 + x20554;
        x20508 = x20555;
        int x20557 = x20509;
        int x20558 = x20557 * 10;
        x20509 = x20558;
        x20383 = x20383 + 1;
      }
    } else {
    }
    x20383 = x20383 + 1;
    int x20567 = x20508;
    int x20569 = x20509;
    for (;;) {
      long x20573 = x20383;
      char x20574 = x4009[x20573];
      bool x20575 = x20574 != '|';
      bool x20580 = x20575;
      if (x20575) {
        long x20576 = x20383;
        char x20577 = x4009[x20576];
        bool x20578 = x20577 != '\n';
        x20580 = x20578;
      }
      bool x20581 = x20580;
      if (!x20581) break;
      x20383 = x20383 + 1;
    }
    x20383 = x20383 + 1;
    long x20590 = x20383;
    for (;;) {
      long x20591 = x20383;
      char x20592 = x4009[x20591];
      bool x20593 = x20592 != '|';
      bool x20598 = x20593;
      if (x20593) {
        long x20594 = x20383;
        char x20595 = x4009[x20594];
        bool x20596 = x20595 != '\n';
        x20598 = x20596;
      }
      bool x20599 = x20598;
      if (!x20599) break;
      x20383 = x20383 + 1;
    }
    x20383 = x20383 + 1;
    long x20609 = x20383;
    bool x20610 = x20609 > 0L;
    bool x20616 = x20610;
    if (x20610) {
      long x20611 = x20383;
      long x20612 = x20611 - 1L;
      char x20613 = x4009[x20612];
      bool x20614 = x20613 != '\n';
      x20616 = x20614;
    }
    bool x20617 = x20616;
    if (x20617) {
      for (;;) {
        long x20618 = x20383;
        char x20619 = x4009[x20618];
        bool x20620 = x20619 != '\n';
        if (!x20620) break;
        x20383 = x20383 + 1;
      }
    } else {
    }
    x20383 = x20383 + 1;
    long x20629 = x20385;
    long x20630 = x20384;
    bool x20631 = x20629 == x20630;
    if (x20631) {
      long x20632 = x20630 * 4L;
      x20384 = x20632;
      printf("buffer.resize %ld\n",x20632);
      int* x20635 = x20387;
      int* x20636 = (int*)realloc(x20635,x20632 * sizeof(int));
      x20387 = x20636;
      char** x20638 = x20389;
      char** x20639 = (char**)realloc(x20638,x20632 * sizeof(char*));
      x20389 = x20639;
      char** x20641 = x20391;
      char** x20642 = (char**)realloc(x20641,x20632 * sizeof(char*));
      x20391 = x20642;
      int* x20644 = x20393;
      int* x20645 = (int*)realloc(x20644,x20632 * sizeof(int));
      x20393 = x20645;
      char** x20647 = x20395;
      char** x20648 = (char**)realloc(x20647,x20632 * sizeof(char*));
      x20395 = x20648;
      double* x20650 = x20397;
      double* x20651 = (double*)realloc(x20650,x20632 * sizeof(double));
      x20397 = x20651;
      char** x20656 = x20401;
      char** x20657 = (char**)realloc(x20656,x20632 * sizeof(char*));
      x20401 = x20657;
    } else {
    }
    int* x20661 = x20387;
    x20661[x20629] = x20428;
    char** x20663 = x20389;
    char* x20446 = x4009+x20429;
    x20663[x20629] = x20446;
    char** x20665 = x20391;
    char* x20464 = x4009+x20447;
    x20665[x20629] = x20464;
    int* x20667 = x20393;
    x20667[x20629] = x20488;
    char** x20669 = x20395;
    char* x20506 = x4009+x20489;
    x20669[x20629] = x20506;
    double* x20671 = x20397;
    double x20568 = (double)x20567;
    double x20570 = (double)x20569;
    double x20571 = x20568 / x20570;
    x20671[x20629] = x20571;
    char** x20675 = x20401;
    char* x20607 = x4009+x20590;
    x20675[x20629] = x20607;
    x20385 = x20385 + 1;
  }
  long x20680 = 0L;
  long x20681 = x7;
  long x20682 = 0L;
  int* x20683 = (int*)malloc(x7 * sizeof(int));
  int* x20684 = x20683;
  int* x20685 = (int*)malloc(x7 * sizeof(int));
  int* x20686 = x20685;
  long* x20691 = (long*)malloc(x7 * sizeof(long));
  long* x20692 = x20691;
  int x3633 = open("XXXXXorders.tbl",0);
  long x3634 = fsize(x3633);
  char* x3635 = mmap(0, x3634, PROT_READ, MAP_FILE | MAP_SHARED, x3633, 0);
  for (;;) {
    long x20701 = x20680;
    bool x20702 = x20701 < x3634;
    if (!x20702) break;
    int x20705 = 0;
    for (;;) {
      long x20706 = x20680;
      char x20707 = x3635[x20706];
      bool x20708 = x20707 != '|';
      bool x20713 = x20708;
      if (x20708) {
        long x20709 = x20680;
        char x20710 = x3635[x20709];
        bool x20711 = x20710 != '\n';
        x20713 = x20711;
      }
      bool x20714 = x20713;
      if (!x20714) break;
      int x20716 = x20705;
      long x20718 = x20680;
      int x20717 = x20716 * 10;
      char x20719 = x3635[x20718];
      char x20720 = x20719 - '0';
      int x20721 = x20717 + x20720;
      x20705 = x20721;
      x20680 = x20680 + 1;
    }
    x20680 = x20680 + 1;
    int x20727 = x20705;
    int x20729 = 0;
    for (;;) {
      long x20730 = x20680;
      char x20731 = x3635[x20730];
      bool x20732 = x20731 != '|';
      bool x20737 = x20732;
      if (x20732) {
        long x20733 = x20680;
        char x20734 = x3635[x20733];
        bool x20735 = x20734 != '\n';
        x20737 = x20735;
      }
      bool x20738 = x20737;
      if (!x20738) break;
      int x20740 = x20729;
      long x20742 = x20680;
      int x20741 = x20740 * 10;
      char x20743 = x3635[x20742];
      char x20744 = x20743 - '0';
      int x20745 = x20741 + x20744;
      x20729 = x20745;
      x20680 = x20680 + 1;
    }
    x20680 = x20680 + 1;
    int x20751 = x20729;
    x20680 = x20680 + 2;
    for (;;) {
      long x20758 = x20680;
      char x20759 = x3635[x20758];
      bool x20760 = x20759 != '.';
      bool x20765 = x20760;
      if (x20760) {
        long x20761 = x20680;
        char x20762 = x3635[x20761];
        bool x20763 = x20762 != '|';
        x20765 = x20763;
      }
      bool x20766 = x20765;
      bool x20771 = x20766;
      if (x20766) {
        long x20767 = x20680;
        char x20768 = x3635[x20767];
        bool x20769 = x20768 != '\n';
        x20771 = x20769;
      }
      bool x20772 = x20771;
      if (!x20772) break;
      x20680 = x20680 + 1;
    }
    long x20784 = x20680;
    char x20785 = x3635[x20784];
    bool x20786 = x20785 == '.';
    if (x20786) {
      x20680 = x20680 + 1;
      for (;;) {
        long x20788 = x20680;
        char x20789 = x3635[x20788];
        bool x20790 = x20789 != '|';
        bool x20795 = x20790;
        if (x20790) {
          long x20791 = x20680;
          char x20792 = x3635[x20791];
          bool x20793 = x20792 != '\n';
          x20795 = x20793;
        }
        bool x20796 = x20795;
        if (!x20796) break;
        x20680 = x20680 + 1;
      }
    } else {
    }
    x20680 = x20680 + 1;
    int x20821 = 0;
    for (;;) {
      long x20822 = x20680;
      char x20823 = x3635[x20822];
      bool x20824 = x20823 != '-';
      bool x20829 = x20824;
      if (x20824) {
        long x20825 = x20680;
        char x20826 = x3635[x20825];
        bool x20827 = x20826 != '\n';
        x20829 = x20827;
      }
      bool x20830 = x20829;
      if (!x20830) break;
      int x20832 = x20821;
      long x20834 = x20680;
      int x20833 = x20832 * 10;
      char x20835 = x3635[x20834];
      char x20836 = x20835 - '0';
      int x20837 = x20833 + x20836;
      x20821 = x20837;
      x20680 = x20680 + 1;
    }
    x20680 = x20680 + 1;
    int x20843 = x20821;
    int x20845 = 0;
    for (;;) {
      long x20846 = x20680;
      char x20847 = x3635[x20846];
      bool x20848 = x20847 != '-';
      bool x20853 = x20848;
      if (x20848) {
        long x20849 = x20680;
        char x20850 = x3635[x20849];
        bool x20851 = x20850 != '\n';
        x20853 = x20851;
      }
      bool x20854 = x20853;
      if (!x20854) break;
      int x20856 = x20845;
      long x20858 = x20680;
      int x20857 = x20856 * 10;
      char x20859 = x3635[x20858];
      char x20860 = x20859 - '0';
      int x20861 = x20857 + x20860;
      x20845 = x20861;
      x20680 = x20680 + 1;
    }
    x20680 = x20680 + 1;
    int x20867 = x20845;
    int x20869 = 0;
    for (;;) {
      long x20870 = x20680;
      char x20871 = x3635[x20870];
      bool x20872 = x20871 != '|';
      bool x20877 = x20872;
      if (x20872) {
        long x20873 = x20680;
        char x20874 = x3635[x20873];
        bool x20875 = x20874 != '\n';
        x20877 = x20875;
      }
      bool x20878 = x20877;
      if (!x20878) break;
      int x20880 = x20869;
      long x20882 = x20680;
      int x20881 = x20880 * 10;
      char x20883 = x3635[x20882];
      char x20884 = x20883 - '0';
      int x20885 = x20881 + x20884;
      x20869 = x20885;
      x20680 = x20680 + 1;
    }
    x20680 = x20680 + 1;
    int x20891 = x20869;
    for (;;) {
      long x20897 = x20680;
      char x20898 = x3635[x20897];
      bool x20899 = x20898 != '|';
      bool x20904 = x20899;
      if (x20899) {
        long x20900 = x20680;
        char x20901 = x3635[x20900];
        bool x20902 = x20901 != '\n';
        x20904 = x20902;
      }
      bool x20905 = x20904;
      if (!x20905) break;
      x20680 = x20680 + 1;
    }
    x20680 = x20680 + 1;
    for (;;) {
      long x20915 = x20680;
      char x20916 = x3635[x20915];
      bool x20917 = x20916 != '|';
      bool x20922 = x20917;
      if (x20917) {
        long x20918 = x20680;
        char x20919 = x3635[x20918];
        bool x20920 = x20919 != '\n';
        x20922 = x20920;
      }
      bool x20923 = x20922;
      if (!x20923) break;
      x20680 = x20680 + 1;
    }
    x20680 = x20680 + 1;
    for (;;) {
      long x20934 = x20680;
      char x20935 = x3635[x20934];
      bool x20936 = x20935 != '|';
      bool x20941 = x20936;
      if (x20936) {
        long x20937 = x20680;
        char x20938 = x3635[x20937];
        bool x20939 = x20938 != '\n';
        x20941 = x20939;
      }
      bool x20942 = x20941;
      if (!x20942) break;
      x20680 = x20680 + 1;
    }
    x20680 = x20680 + 1;
    for (;;) {
      long x20957 = x20680;
      char x20958 = x3635[x20957];
      bool x20959 = x20958 != '|';
      bool x20964 = x20959;
      if (x20959) {
        long x20960 = x20680;
        char x20961 = x3635[x20960];
        bool x20962 = x20961 != '\n';
        x20964 = x20962;
      }
      bool x20965 = x20964;
      if (!x20965) break;
      x20680 = x20680 + 1;
    }
    x20680 = x20680 + 1;
    long x20975 = x20680;
    bool x20976 = x20975 > 0L;
    bool x20982 = x20976;
    if (x20976) {
      long x20977 = x20680;
      long x20978 = x20977 - 1L;
      char x20979 = x3635[x20978];
      bool x20980 = x20979 != '\n';
      x20982 = x20980;
    }
    bool x20983 = x20982;
    if (x20983) {
      for (;;) {
        long x20984 = x20680;
        char x20985 = x3635[x20984];
        bool x20986 = x20985 != '\n';
        if (!x20986) break;
        x20680 = x20680 + 1;
      }
    } else {
    }
    x20680 = x20680 + 1;
    long x20995 = x20682;
    long x20996 = x20681;
    bool x20997 = x20995 == x20996;
    if (x20997) {
      long x20998 = x20996 * 4L;
      x20681 = x20998;
      printf("buffer.resize %ld\n",x20998);
      int* x21001 = x20684;
      int* x21002 = (int*)realloc(x21001,x20998 * sizeof(int));
      x20684 = x21002;
      int* x21004 = x20686;
      int* x21005 = (int*)realloc(x21004,x20998 * sizeof(int));
      x20686 = x21005;
      long* x21013 = x20692;
      long* x21014 = (long*)realloc(x21013,x20998 * sizeof(long));
      x20692 = x21014;
    } else {
    }
    int* x21030 = x20684;
    x21030[x20995] = x20727;
    int* x21032 = x20686;
    x21032[x20995] = x20751;
    long* x21038 = x20692;
    long x20892 = x20843 * 10000L;
    long x20893 = x20867 * 100L;
    long x20894 = x20892 + x20893;
    long x20895 = x20894 + x20891;
    x21038[x20995] = x20895;
    x20682 = x20682 + 1;
  }
  long x2189 = DEFAULT_JOIN_HASH_SIZE;
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  long x2212 = x2189 - 1L;
  long x823 = x808 - 1L;
  int x21051;
  for(x21051=0; x21051 < 5; x21051++) {
    bool x21052 = false;
    long x21053 = 0L;
    bool x21055 = false;
    long x21056 = 0L;
    int* x21058 = (int*)malloc(x2189 * sizeof(int));
    int* x21059 = x21058;
    int* x21060 = (int*)malloc(x2189 * sizeof(int));
    int* x21061 = x21060;
    long x21076 = 0L;
    long* x21077 = (long*)malloc(x2189 * sizeof(long));
    long* x21078 = (long*)malloc(x2189 * sizeof(long));
    long x21079;
    for(x21079=0L; x21079 < x2189; x21079++) {
      x21077[x21079] = -1L;
    }
    bool x21084 = false;
    long x21085 = 0L;
    int* x21087 = (int*)malloc(x2189 * sizeof(int));
    int* x21088 = x21087;
    char** x21089 = (char**)malloc(x2189 * sizeof(char*));
    char** x21090 = x21089;
    long x21095 = 0L;
    long* x21096 = (long*)malloc(x2189 * sizeof(long));
    long* x21097 = (long*)malloc(x2189 * sizeof(long));
    long x21098;
    for(x21098=0L; x21098 < x2189; x21098++) {
      x21096[x21098] = -1L;
    }
    bool x21103 = false;
    long x21104 = 0L;
    char** x21109 = (char**)malloc(x2189 * sizeof(char*));
    char** x21110 = x21109;
    int* x21115 = (int*)malloc(x2189 * sizeof(int));
    int* x21116 = x21115;
    int* x21133 = (int*)malloc(x2189 * sizeof(int));
    int* x21134 = x21133;
    char** x21135 = (char**)malloc(x2189 * sizeof(char*));
    char** x21136 = x21135;
    char** x21137 = (char**)malloc(x2189 * sizeof(char*));
    char** x21138 = x21137;
    char** x21141 = (char**)malloc(x2189 * sizeof(char*));
    char** x21142 = x21141;
    double* x21143 = (double*)malloc(x2189 * sizeof(double));
    double* x21144 = x21143;
    char** x21147 = (char**)malloc(x2189 * sizeof(char*));
    char** x21148 = x21147;
    long x21149 = 0L;
    long* x21150 = (long*)malloc(x2189 * sizeof(long));
    long* x21151 = (long*)malloc(x2189 * sizeof(long));
    long x21152;
    for(x21152=0L; x21152 < x2189; x21152++) {
      x21150[x21152] = -1L;
    }
    struct Anon1678583810* x21158 = (struct Anon1678583810*)malloc(x808 * sizeof(struct Anon1678583810));
    struct Anon1678583810* x21159 = x21158;
    long x21160 = 0L;
    long* x21161 = (long*)malloc(x808 * sizeof(long));
    long x21162;
    for(x21162=0L; x21162 < x808; x21162++) {
      struct Anon1678583810* x21163 = x21159;
      struct Anon1678583810 x21164 = x21163[x21162];
      struct Anon1711779607 x21165 = x21164.key;;
      struct Anon2052879266 x21166 = x21164.aggs;;
      struct Anon1678583810 x21167;
      x21167.exists = false;
      x21167.key = x21165;
      x21167.aggs = x21166;
      x21163[x21162] = x21167;
    }
    long x21172 = 1024L;
    long x21173 = 0L;
    struct Anon1678583810* x21174 = (struct Anon1678583810*)malloc(1024L * sizeof(struct Anon1678583810));
    struct Anon1678583810* x21175 = x21174;
    int x21176 = 0;
    long x21178 = 0L;
    struct timeval x21736, x21737, x21738;
    gettimeofday(&x21736, NULL);
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x21180 = x21084;
      bool x21181 = !x21180;
      bool x21186 = x21181;
      if (x21181) {
        long x21182 = x21085;
        long x21183 = x20235;
        bool x21184 = x21182 < x21183;
        x21186 = x21184;
      }
      bool x21187 = x21186;
      if (!x21187) break;
      long x21189 = x21085;
      int* x21190 = x20237;
      int x21191 = x21190[x21189];
      char** x21192 = x20239;
      char* x21193 = x21192[x21189];
      x21085 = x21085 + 1;
      long x21200 = x21095;
      int* x21201 = x21088;
      x21201[x21200] = x21191;
      char** x21203 = x21090;
      x21203[x21200] = x21193;
      x21095 = x21095 + 1L;
      long x21210 = x21191 & x2212;
      long x21211 = x21096[x21210];
      x21096[x21210] = x21200;
      x21097[x21200] = x21211;
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x21217 = x21052;
      bool x21218 = !x21217;
      bool x21223 = x21218;
      if (x21218) {
        long x21219 = x21053;
        long x21220 = x20682;
        bool x21221 = x21219 < x21220;
        x21223 = x21221;
      }
      bool x21224 = x21223;
      if (!x21224) break;
      long x21226 = x21053;
      int* x21227 = x20684;
      int x21228 = x21227[x21226];
      int* x21229 = x20686;
      int x21230 = x21229[x21226];
      long* x21235 = x20692;
      long x21236 = x21235[x21226];
      x21053 = x21053 + 1;
      bool x21247 = x21236 >= 19931001L;
      bool x21249 = x21247;
      if (x21247) {
        bool x21248 = x21236 < 19940101L;
        x21249 = x21248;
      }
      bool x21250 = x21249;
      if (x21250) {
        long x21251 = x21076;
        int* x21252 = x21059;
        x21252[x21251] = x21228;
        int* x21254 = x21061;
        x21254[x21251] = x21230;
        x21076 = x21076 + 1L;
        long x21271 = x21230 & x2212;
        long x21272 = x21077[x21271];
        x21077[x21271] = x21251;
        x21078[x21251] = x21272;
      } else {
      }
    }
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x21280 = x21055;
      bool x21281 = !x21280;
      bool x21286 = x21281;
      if (x21281) {
        long x21282 = x21056;
        long x21283 = x20385;
        bool x21284 = x21282 < x21283;
        x21286 = x21284;
      }
      bool x21287 = x21286;
      if (!x21287) break;
      long x21289 = x21056;
      int* x21290 = x20387;
      int x21291 = x21290[x21289];
      char** x21292 = x20389;
      char* x21293 = x21292[x21289];
      char** x21294 = x20391;
      char* x21295 = x21294[x21289];
      int* x21296 = x20393;
      int x21297 = x21296[x21289];
      char** x21298 = x20395;
      char* x21299 = x21298[x21289];
      double* x21300 = x20397;
      double x21301 = x21300[x21289];
      char** x21304 = x20401;
      char* x21305 = x21304[x21289];
      x21056 = x21056 + 1;
      long x21308 = x21291 & x2212;
      long x21309 = x21077[x21308];
      long x21310 = x21309;
      long x21340 = x21297 & x2212;
      for (;;) {
        long x21311 = x21310;
        bool x21312 = x21311 != -1;
        if (!x21312) break;
        long x21314 = x21310;
        int* x21315 = x21059;
        int x21316 = x21315[x21314];
        int* x21317 = x21061;
        int x21318 = x21317[x21314];
        long x21334 = x21078[x21314];
        x21310 = x21334;
        bool x21336 = x21318 == x21291;
        if (x21336) {
          long x21341 = x21096[x21340];
          long x21342 = x21341;
          long x21406 = x21316 & x2212;
          for (;;) {
            long x21343 = x21342;
            bool x21344 = x21343 != -1;
            if (!x21344) break;
            long x21346 = x21342;
            int* x21347 = x21088;
            int x21348 = x21347[x21346];
            char** x21349 = x21090;
            char* x21350 = x21349[x21346];
            long x21356 = x21097[x21346];
            x21342 = x21356;
            bool x21358 = x21348 == x21297;
            if (x21358) {
              long x21362 = x21149;
              char** x21365 = x21110;
              x21365[x21362] = x21350;
              int* x21371 = x21116;
              x21371[x21362] = x21316;
              int* x21389 = x21134;
              x21389[x21362] = x21291;
              char** x21391 = x21136;
              x21391[x21362] = x21293;
              char** x21393 = x21138;
              x21393[x21362] = x21295;
              char** x21397 = x21142;
              x21397[x21362] = x21299;
              double* x21399 = x21144;
              x21399[x21362] = x21301;
              char** x21403 = x21148;
              x21403[x21362] = x21305;
              x21149 = x21149 + 1L;
              long x21407 = x21150[x21406];
              x21150[x21406] = x21362;
              x21151[x21362] = x21407;
            } else {
            }
          }
        } else {
        }
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x21421 = x21103;
      bool x21422 = !x21421;
      bool x21427 = x21422;
      if (x21422) {
        long x21423 = x21104;
        long x21424 = x19441;
        bool x21425 = x21423 < x21424;
        x21427 = x21425;
      }
      bool x21428 = x21427;
      if (!x21428) break;
      long x21430 = x21104;
      int* x21431 = x19443;
      int x21432 = x21431[x21430];
      double* x21441 = x19453;
      double x21442 = x21441[x21430];
      double* x21443 = x19455;
      double x21444 = x21443[x21430];
      char* x21447 = x19459;
      char x21448 = x21447[x21430];
      x21104 = x21104 + 1;
      bool x21465 = x21448 == 'R';
      if (x21465) {
        long x21466 = x21432 & x2212;
        long x21467 = x21150[x21466];
        long x21468 = x21467;
        double x21580 = 1.0 - x21444;
        double x21581 = x21442 * x21580;
        struct Anon2052879266 x21639;
        x21639._0 = x21581;
        for (;;) {
          long x21469 = x21468;
          bool x21470 = x21469 != -1;
          if (!x21470) break;
          long x21472 = x21468;
          char** x21475 = x21110;
          char* x21476 = x21475[x21472];
          int* x21481 = x21116;
          int x21482 = x21481[x21472];
          int* x21499 = x21134;
          int x21500 = x21499[x21472];
          char** x21501 = x21136;
          char* x21502 = x21501[x21472];
          char** x21503 = x21138;
          char* x21504 = x21503[x21472];
          char** x21507 = x21142;
          char* x21508 = x21507[x21472];
          double* x21509 = x21144;
          double x21510 = x21509[x21472];
          char** x21513 = x21148;
          char* x21514 = x21513[x21472];
          long x21516 = x21151[x21472];
          x21468 = x21516;
          bool x21518 = x21482 == x21432;
          if (x21518) {
            long x21523 = (long) x21510;
            long x21524 = hash(x21504, 10L);
            long x21525 = hash(x21514, 10L);
            long x21526 = hash(x21502, 10L);
            long x21527 = hash(x21508, 10L);
            long x21528 = hash(x21476, 10L);
            long x21529 = x21523 * 41L;
            long x21530 = x21529 + x21524;
            long x21531 = x21530 * 41L;
            long x21532 = x21531 + x21525;
            long x21533 = x21532 * 41L;
            long x21534 = x21533 + x21500;
            long x21535 = x21534 * 41L;
            long x21536 = x21535 + x21526;
            long x21537 = x21536 * 41L;
            long x21538 = x21537 + x21527;
            long x21539 = x21538 * 41L;
            long x21540 = x21539 + x21528;
            long x21541 = x21540 & x823;
            long x21542 = x21541;
            struct Anon1678583810* x21543 = x21159;
            struct Anon1678583810 x21544 = x21543[x21541];
            struct Anon1678583810 x21545 = x21544;
            bool x21546 = x21544.exists;;
            bool x21576 = x21546;
            if (x21546) {
              struct Anon1678583810 x21547 = x21545;
              struct Anon1711779607 x21548 = x21547.key;;
              int x21549 = x21548.C_CUSTKEY;;
              bool x21550 = x21549 == x21500;
              bool x21563 = x21550;
              if (x21550) {
                char* x21551 = x21548.C_NAME;;
                bool x21552 = tpch_strcmp(x21551,x21502) == 0;;
                x21563 = x21552;
              }
              bool x21564 = x21563;
              bool x21565 = x21564;
              if (x21564) {
                double x21553 = x21548.C_ACCTBAL;;
                bool x21554 = x21553 == x21510;
                x21565 = x21554;
              }
              bool x21566 = x21565;
              bool x21567 = x21566;
              if (x21566) {
                char* x21555 = x21548.C_PHONE;;
                bool x21556 = tpch_strcmp(x21555,x21508) == 0;;
                x21567 = x21556;
              }
              bool x21568 = x21567;
              bool x21569 = x21568;
              if (x21568) {
                char* x21557 = x21548.N_NAME;;
                bool x21558 = tpch_strcmp(x21557,x21476) == 0;;
                x21569 = x21558;
              }
              bool x21570 = x21569;
              bool x21571 = x21570;
              if (x21570) {
                char* x21559 = x21548.C_ADDRESS;;
                bool x21560 = tpch_strcmp(x21559,x21504) == 0;;
                x21571 = x21560;
              }
              bool x21572 = x21571;
              bool x21573 = x21572;
              if (x21572) {
                char* x21561 = x21548.C_COMMENT;;
                bool x21562 = tpch_strcmp(x21561,x21514) == 0;;
                x21573 = x21562;
              }
              bool x21574 = x21573;
              x21576 = x21574;
            }
            bool x21577 = x21576;
            if (x21577) {
              struct Anon2052879266 x21578 = x21544.aggs;;
              struct Anon1711779607 x21584 = x21544.key;;
              double x21579 = x21578._0;;
              double x21582 = x21579 + x21581;
              struct Anon2052879266 x21583;
              x21583._0 = x21582;
              struct Anon1678583810 x21585;
              x21585.exists = true;
              x21585.key = x21584;
              x21585.aggs = x21583;
              x21543[x21541] = x21585;
            } else {
              struct Anon1711779607 x21522;
              x21522.C_CUSTKEY = x21500;
              x21522.C_NAME = x21502;
              x21522.C_ACCTBAL = x21510;
              x21522.C_PHONE = x21508;
              x21522.N_NAME = x21476;
              x21522.C_ADDRESS = x21504;
              x21522.C_COMMENT = x21514;
              struct Anon1678583810 x21640;
              x21640.exists = true;
              x21640.key = x21522;
              x21640.aggs = x21639;
              for (;;) {
                struct Anon1678583810 x21588 = x21545;
                bool x21589 = x21588.exists;;
                bool x21649;
                if (x21589) {
                  struct Anon1711779607 x21590 = x21588.key;;
                  int x21591 = x21590.C_CUSTKEY;;
                  bool x21592 = x21591 == x21500;
                  bool x21605 = x21592;
                  if (x21592) {
                    char* x21593 = x21590.C_NAME;;
                    bool x21594 = tpch_strcmp(x21593,x21502) == 0;;
                    x21605 = x21594;
                  }
                  bool x21606 = x21605;
                  bool x21607 = x21606;
                  if (x21606) {
                    double x21595 = x21590.C_ACCTBAL;;
                    bool x21596 = x21595 == x21510;
                    x21607 = x21596;
                  }
                  bool x21608 = x21607;
                  bool x21609 = x21608;
                  if (x21608) {
                    char* x21597 = x21590.C_PHONE;;
                    bool x21598 = tpch_strcmp(x21597,x21508) == 0;;
                    x21609 = x21598;
                  }
                  bool x21610 = x21609;
                  bool x21611 = x21610;
                  if (x21610) {
                    char* x21599 = x21590.N_NAME;;
                    bool x21600 = tpch_strcmp(x21599,x21476) == 0;;
                    x21611 = x21600;
                  }
                  bool x21612 = x21611;
                  bool x21613 = x21612;
                  if (x21612) {
                    char* x21601 = x21590.C_ADDRESS;;
                    bool x21602 = tpch_strcmp(x21601,x21504) == 0;;
                    x21613 = x21602;
                  }
                  bool x21614 = x21613;
                  bool x21615 = x21614;
                  if (x21614) {
                    char* x21603 = x21590.C_COMMENT;;
                    bool x21604 = tpch_strcmp(x21603,x21514) == 0;;
                    x21615 = x21604;
                  }
                  bool x21616 = x21615;
                  bool x21636;
                  if (x21616) {
                    struct Anon2052879266 x21617 = x21588.aggs;;
                    long x21621 = x21542;
                    struct Anon1678583810* x21623 = x21159;
                    double x21618 = x21617._0;;
                    double x21619 = x21618 + x21581;
                    struct Anon2052879266 x21620;
                    x21620._0 = x21619;
                    struct Anon1678583810 x21622;
                    x21622.exists = true;
                    x21622.key = x21590;
                    x21622.aggs = x21620;
                    x21623[x21621] = x21622;
                    x21636 = false;
                  } else {
                    long x21626 = x21542;
                    long x21627 = x21626 + 1L;
                    long x21628 = x21627 & x823;
                    x21542 = x21628;
                    struct Anon1678583810* x21630 = x21159;
                    struct Anon1678583810 x21631 = x21630[x21628];
                    x21545 = x21631;
                    x21636 = true;
                  }
                  x21649 = x21636;
                } else {
                  long x21638 = x21542;
                  struct Anon1678583810* x21641 = x21159;
                  x21641[x21638] = x21640;
                  long x21643 = x21160;
                  x21161[x21643] = x21638;
                  x21160 = x21160 + 1L;
                  x21649 = false;
                }
                if (!x21649) break;
              }
            }
          } else {
          }
        }
      } else {
      }
    }
    long x21664 = x21160;
    long x21666;
    for(x21666=0L; x21666 < x21664; x21666++) {
      long x21667 = x21161[x21666];
      struct Anon1678583810* x21668 = x21159;
      struct Anon1678583810 x21669 = x21668[x21667];
      long x21670 = x21173;
      long x21671 = x21172;
      bool x21672 = x21670 == x21671;
      if (x21672) {
        long x21673 = x21671 * 4L;
        x21172 = x21673;
        struct Anon1678583810* x21675 = x21175;
        struct Anon1678583810* x21676 = (struct Anon1678583810 *)realloc(x21675,x21673* sizeof(struct Anon1678583810));
        x21175 = x21676;
      } else {
      }
      struct Anon1678583810* x21680 = x21175;
      x21680[x21670] = x21669;
      x21173 = x21173 + 1;
    }
    long x21685 = x21173;
    struct Anon1678583810* x21686 = x21175;
    qsort((void *)x21686,x21685,sizeof(struct Anon1678583810), (__compar_fn_t)x21700); // x21701
    long x21703;
    for(x21703=0L; x21703 < x21685; x21703++) {
      struct Anon1678583810* x21704 = x21175;
      struct Anon1678583810 x21705 = x21704[x21703];
      int x21706 = x21176;
      bool x21707 = x21706 < 20;
      bool x21708 = x21707 == false;
      if (x21708) {
      } else {
        struct Anon1711779607 x21711 = x21705.key;;
        struct Anon2052879266 x21715 = x21705.aggs;;
        int x21712 = x21711.C_CUSTKEY;;
        char* x21713 = x21711.C_NAME;;
        int x21714 = tpch_strlen(x21713);
        double x21716 = x21715._0;;
        double x21717 = x21711.C_ACCTBAL;;
        char* x21718 = x21711.N_NAME;;
        int x21719 = tpch_strlen(x21718);
        char* x21720 = x21711.C_ADDRESS;;
        int x21721 = tpch_strlen(x21720);
        char* x21722 = x21711.C_PHONE;;
        int x21723 = tpch_strlen(x21722);
        char* x21724 = x21711.C_COMMENT;;
        int x21725 = tpch_strlen(x21724);
        printf("%d|%.*s|%.4f|%.2f|%.*s|%.*s|%.*s|%.*s\n",x21712,x21714,x21713,x21716,x21717,x21719,x21718,x21721,x21720,x21723,x21722,x21725,x21724);
        x21176 = x21176 + 1;
        x21178 = x21178 + 1L;
      }
    }
    long x21733 = x21178;
    printf("(%ld rows)\n",x21733);
    gettimeofday(&x21737, NULL);
    timeval_subtract(&x21738, &x21737, &x21736);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x21738.tv_sec * 1000) + (x21738.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
