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
int x19407(struct Anon2101649069* x19389, struct Anon2101649069* x19390);
int x19407(struct Anon2101649069* x19389, struct Anon2101649069* x19390) {
  struct Anon2101649069 x19391 = (*x19389);
  struct Anon2101649069 x19392 = (*x19390);
  struct Anon1548200872 x19393 = x19391.key;;
  char* x19395 = x19393.NATION;;
  struct Anon1548200872 x19394 = x19392.key;;
  char* x19396 = x19394.NATION;;
  int x19397 = tpch_strcmp(x19395,x19396);
  bool x19398 = x19397 == 0;
  int x19405;
  if (x19398) {
    int x19399 = x19393.O_YEAR;;
    int x19400 = x19394.O_YEAR;;
    bool x19401 = x19399 < x19400;
    int x19404;
    if (x19401) {
      x19404 = 1;
    } else {
      bool x19402 = x19399 > x19400;
      int x19403;
      if (x19402) {
        x19403 = -1;
      } else {
        x19403 = 0;
      }
      x19404 = x19403;
    }
    x19405 = x19404;
  } else {
    x19405 = x19397;
  }
  return x19405;
}

/************************ MAIN BODY **************************/
int main(int x16327, char** x16328) {
  long x16329 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x16330 = x7;
  long x16331 = 0L;
  int* x16332 = (int*)malloc(x7 * sizeof(int));
  int* x16333 = x16332;
  char** x16334 = (char**)malloc(x7 * sizeof(char*));
  char** x16335 = x16334;
  int x1076 = open("XXXXXpart.tbl",0);
  long x1077 = fsize(x1076);
  char* x1078 = mmap(0, x1077, PROT_READ, MAP_FILE | MAP_SHARED, x1076, 0);
  for (;;) {
    long x16351 = x16329;
    bool x16352 = x16351 < x1077;
    if (!x16352) break;
    int x16355 = 0;
    for (;;) {
      long x16356 = x16329;
      char x16357 = x1078[x16356];
      bool x16358 = x16357 != '|';
      bool x16363 = x16358;
      if (x16358) {
        long x16359 = x16329;
        char x16360 = x1078[x16359];
        bool x16361 = x16360 != '\n';
        x16363 = x16361;
      }
      bool x16364 = x16363;
      if (!x16364) break;
      int x16366 = x16355;
      long x16368 = x16329;
      int x16367 = x16366 * 10;
      char x16369 = x1078[x16368];
      char x16370 = x16369 - '0';
      int x16371 = x16367 + x16370;
      x16355 = x16371;
      x16329 = x16329 + 1;
    }
    x16329 = x16329 + 1;
    int x16377 = x16355;
    long x16378 = x16329;
    for (;;) {
      long x16379 = x16329;
      char x16380 = x1078[x16379];
      bool x16381 = x16380 != '|';
      bool x16386 = x16381;
      if (x16381) {
        long x16382 = x16329;
        char x16383 = x1078[x16382];
        bool x16384 = x16383 != '\n';
        x16386 = x16384;
      }
      bool x16387 = x16386;
      if (!x16387) break;
      x16329 = x16329 + 1;
    }
    x16329 = x16329 + 1;
    for (;;) {
      long x16397 = x16329;
      char x16398 = x1078[x16397];
      bool x16399 = x16398 != '|';
      bool x16404 = x16399;
      if (x16399) {
        long x16400 = x16329;
        char x16401 = x1078[x16400];
        bool x16402 = x16401 != '\n';
        x16404 = x16402;
      }
      bool x16405 = x16404;
      if (!x16405) break;
      x16329 = x16329 + 1;
    }
    x16329 = x16329 + 1;
    for (;;) {
      long x16415 = x16329;
      char x16416 = x1078[x16415];
      bool x16417 = x16416 != '|';
      bool x16422 = x16417;
      if (x16417) {
        long x16418 = x16329;
        char x16419 = x1078[x16418];
        bool x16420 = x16419 != '\n';
        x16422 = x16420;
      }
      bool x16423 = x16422;
      if (!x16423) break;
      x16329 = x16329 + 1;
    }
    x16329 = x16329 + 1;
    for (;;) {
      long x16433 = x16329;
      char x16434 = x1078[x16433];
      bool x16435 = x16434 != '|';
      bool x16440 = x16435;
      if (x16435) {
        long x16436 = x16329;
        char x16437 = x1078[x16436];
        bool x16438 = x16437 != '\n';
        x16440 = x16438;
      }
      bool x16441 = x16440;
      if (!x16441) break;
      x16329 = x16329 + 1;
    }
    x16329 = x16329 + 1;
    for (;;) {
      long x16452 = x16329;
      char x16453 = x1078[x16452];
      bool x16454 = x16453 != '|';
      bool x16459 = x16454;
      if (x16454) {
        long x16455 = x16329;
        char x16456 = x1078[x16455];
        bool x16457 = x16456 != '\n';
        x16459 = x16457;
      }
      bool x16460 = x16459;
      if (!x16460) break;
      x16329 = x16329 + 1;
    }
    x16329 = x16329 + 1;
    for (;;) {
      long x16475 = x16329;
      char x16476 = x1078[x16475];
      bool x16477 = x16476 != '|';
      bool x16482 = x16477;
      if (x16477) {
        long x16478 = x16329;
        char x16479 = x1078[x16478];
        bool x16480 = x16479 != '\n';
        x16482 = x16480;
      }
      bool x16483 = x16482;
      if (!x16483) break;
      x16329 = x16329 + 1;
    }
    x16329 = x16329 + 1;
    for (;;) {
      long x16495 = x16329;
      char x16496 = x1078[x16495];
      bool x16497 = x16496 != '.';
      bool x16502 = x16497;
      if (x16497) {
        long x16498 = x16329;
        char x16499 = x1078[x16498];
        bool x16500 = x16499 != '|';
        x16502 = x16500;
      }
      bool x16503 = x16502;
      bool x16508 = x16503;
      if (x16503) {
        long x16504 = x16329;
        char x16505 = x1078[x16504];
        bool x16506 = x16505 != '\n';
        x16508 = x16506;
      }
      bool x16509 = x16508;
      if (!x16509) break;
      x16329 = x16329 + 1;
    }
    long x16521 = x16329;
    char x16522 = x1078[x16521];
    bool x16523 = x16522 == '.';
    if (x16523) {
      x16329 = x16329 + 1;
      for (;;) {
        long x16525 = x16329;
        char x16526 = x1078[x16525];
        bool x16527 = x16526 != '|';
        bool x16532 = x16527;
        if (x16527) {
          long x16528 = x16329;
          char x16529 = x1078[x16528];
          bool x16530 = x16529 != '\n';
          x16532 = x16530;
        }
        bool x16533 = x16532;
        if (!x16533) break;
        x16329 = x16329 + 1;
      }
    } else {
    }
    x16329 = x16329 + 1;
    for (;;) {
      long x16558 = x16329;
      char x16559 = x1078[x16558];
      bool x16560 = x16559 != '|';
      bool x16565 = x16560;
      if (x16560) {
        long x16561 = x16329;
        char x16562 = x1078[x16561];
        bool x16563 = x16562 != '\n';
        x16565 = x16563;
      }
      bool x16566 = x16565;
      if (!x16566) break;
      x16329 = x16329 + 1;
    }
    x16329 = x16329 + 1;
    long x16576 = x16329;
    bool x16577 = x16576 > 0L;
    bool x16583 = x16577;
    if (x16577) {
      long x16578 = x16329;
      long x16579 = x16578 - 1L;
      char x16580 = x1078[x16579];
      bool x16581 = x16580 != '\n';
      x16583 = x16581;
    }
    bool x16584 = x16583;
    if (x16584) {
      for (;;) {
        long x16585 = x16329;
        char x16586 = x1078[x16585];
        bool x16587 = x16586 != '\n';
        if (!x16587) break;
        x16329 = x16329 + 1;
      }
    } else {
    }
    x16329 = x16329 + 1;
    long x16596 = x16331;
    long x16597 = x16330;
    bool x16598 = x16596 == x16597;
    if (x16598) {
      long x16599 = x16597 * 4L;
      x16330 = x16599;
      printf("buffer.resize %ld\n",x16599);
      int* x16602 = x16333;
      int* x16603 = (int*)realloc(x16602,x16599 * sizeof(int));
      x16333 = x16603;
      char** x16605 = x16335;
      char** x16606 = (char**)realloc(x16605,x16599 * sizeof(char*));
      x16335 = x16606;
    } else {
    }
    int* x16631 = x16333;
    x16631[x16596] = x16377;
    char** x16633 = x16335;
    char* x16395 = x1078+x16378;
    x16633[x16596] = x16395;
    x16331 = x16331 + 1;
  }
  long x16652 = 0L;
  long x16653 = x7;
  long x16654 = 0L;
  int* x16655 = (int*)malloc(x7 * sizeof(int));
  int* x16656 = x16655;
  char** x16657 = (char**)malloc(x7 * sizeof(char*));
  char** x16658 = x16657;
  int x1633 = open("XXXXXnation.tbl",0);
  long x1634 = fsize(x1633);
  char* x1635 = mmap(0, x1634, PROT_READ, MAP_FILE | MAP_SHARED, x1633, 0);
  for (;;) {
    long x16663 = x16652;
    bool x16664 = x16663 < x1634;
    if (!x16664) break;
    int x16667 = 0;
    for (;;) {
      long x16668 = x16652;
      char x16669 = x1635[x16668];
      bool x16670 = x16669 != '|';
      bool x16675 = x16670;
      if (x16670) {
        long x16671 = x16652;
        char x16672 = x1635[x16671];
        bool x16673 = x16672 != '\n';
        x16675 = x16673;
      }
      bool x16676 = x16675;
      if (!x16676) break;
      int x16678 = x16667;
      long x16680 = x16652;
      int x16679 = x16678 * 10;
      char x16681 = x1635[x16680];
      char x16682 = x16681 - '0';
      int x16683 = x16679 + x16682;
      x16667 = x16683;
      x16652 = x16652 + 1;
    }
    x16652 = x16652 + 1;
    int x16689 = x16667;
    long x16690 = x16652;
    for (;;) {
      long x16691 = x16652;
      char x16692 = x1635[x16691];
      bool x16693 = x16692 != '|';
      bool x16698 = x16693;
      if (x16693) {
        long x16694 = x16652;
        char x16695 = x1635[x16694];
        bool x16696 = x16695 != '\n';
        x16698 = x16696;
      }
      bool x16699 = x16698;
      if (!x16699) break;
      x16652 = x16652 + 1;
    }
    x16652 = x16652 + 1;
    for (;;) {
      long x16710 = x16652;
      char x16711 = x1635[x16710];
      bool x16712 = x16711 != '|';
      bool x16717 = x16712;
      if (x16712) {
        long x16713 = x16652;
        char x16714 = x1635[x16713];
        bool x16715 = x16714 != '\n';
        x16717 = x16715;
      }
      bool x16718 = x16717;
      if (!x16718) break;
      x16652 = x16652 + 1;
    }
    x16652 = x16652 + 1;
    for (;;) {
      long x16733 = x16652;
      char x16734 = x1635[x16733];
      bool x16735 = x16734 != '|';
      bool x16740 = x16735;
      if (x16735) {
        long x16736 = x16652;
        char x16737 = x1635[x16736];
        bool x16738 = x16737 != '\n';
        x16740 = x16738;
      }
      bool x16741 = x16740;
      if (!x16741) break;
      x16652 = x16652 + 1;
    }
    x16652 = x16652 + 1;
    long x16751 = x16652;
    bool x16752 = x16751 > 0L;
    bool x16758 = x16752;
    if (x16752) {
      long x16753 = x16652;
      long x16754 = x16753 - 1L;
      char x16755 = x1635[x16754];
      bool x16756 = x16755 != '\n';
      x16758 = x16756;
    }
    bool x16759 = x16758;
    if (x16759) {
      for (;;) {
        long x16760 = x16652;
        char x16761 = x1635[x16760];
        bool x16762 = x16761 != '\n';
        if (!x16762) break;
        x16652 = x16652 + 1;
      }
    } else {
    }
    x16652 = x16652 + 1;
    long x16771 = x16654;
    long x16772 = x16653;
    bool x16773 = x16771 == x16772;
    if (x16773) {
      long x16774 = x16772 * 4L;
      x16653 = x16774;
      printf("buffer.resize %ld\n",x16774);
      int* x16777 = x16656;
      int* x16778 = (int*)realloc(x16777,x16774 * sizeof(int));
      x16656 = x16778;
      char** x16780 = x16658;
      char** x16781 = (char**)realloc(x16780,x16774 * sizeof(char*));
      x16658 = x16781;
    } else {
    }
    int* x16791 = x16656;
    x16791[x16771] = x16689;
    char** x16793 = x16658;
    char* x16707 = x1635+x16690;
    x16793[x16771] = x16707;
    x16654 = x16654 + 1;
  }
  long x16802 = 0L;
  long x16803 = x7;
  long x16804 = 0L;
  int* x16805 = (int*)malloc(x7 * sizeof(int));
  int* x16806 = x16805;
  long* x16813 = (long*)malloc(x7 * sizeof(long));
  long* x16814 = x16813;
  int x3633 = open("XXXXXorders.tbl",0);
  long x3634 = fsize(x3633);
  char* x3635 = mmap(0, x3634, PROT_READ, MAP_FILE | MAP_SHARED, x3633, 0);
  for (;;) {
    long x16823 = x16802;
    bool x16824 = x16823 < x3634;
    if (!x16824) break;
    int x16827 = 0;
    for (;;) {
      long x16828 = x16802;
      char x16829 = x3635[x16828];
      bool x16830 = x16829 != '|';
      bool x16835 = x16830;
      if (x16830) {
        long x16831 = x16802;
        char x16832 = x3635[x16831];
        bool x16833 = x16832 != '\n';
        x16835 = x16833;
      }
      bool x16836 = x16835;
      if (!x16836) break;
      int x16838 = x16827;
      long x16840 = x16802;
      int x16839 = x16838 * 10;
      char x16841 = x3635[x16840];
      char x16842 = x16841 - '0';
      int x16843 = x16839 + x16842;
      x16827 = x16843;
      x16802 = x16802 + 1;
    }
    x16802 = x16802 + 1;
    int x16849 = x16827;
    for (;;) {
      long x16852 = x16802;
      char x16853 = x3635[x16852];
      bool x16854 = x16853 != '|';
      bool x16859 = x16854;
      if (x16854) {
        long x16855 = x16802;
        char x16856 = x3635[x16855];
        bool x16857 = x16856 != '\n';
        x16859 = x16857;
      }
      bool x16860 = x16859;
      if (!x16860) break;
      x16802 = x16802 + 1;
    }
    x16802 = x16802 + 1;
    x16802 = x16802 + 2;
    for (;;) {
      long x16880 = x16802;
      char x16881 = x3635[x16880];
      bool x16882 = x16881 != '.';
      bool x16887 = x16882;
      if (x16882) {
        long x16883 = x16802;
        char x16884 = x3635[x16883];
        bool x16885 = x16884 != '|';
        x16887 = x16885;
      }
      bool x16888 = x16887;
      bool x16893 = x16888;
      if (x16888) {
        long x16889 = x16802;
        char x16890 = x3635[x16889];
        bool x16891 = x16890 != '\n';
        x16893 = x16891;
      }
      bool x16894 = x16893;
      if (!x16894) break;
      x16802 = x16802 + 1;
    }
    long x16906 = x16802;
    char x16907 = x3635[x16906];
    bool x16908 = x16907 == '.';
    if (x16908) {
      x16802 = x16802 + 1;
      for (;;) {
        long x16910 = x16802;
        char x16911 = x3635[x16910];
        bool x16912 = x16911 != '|';
        bool x16917 = x16912;
        if (x16912) {
          long x16913 = x16802;
          char x16914 = x3635[x16913];
          bool x16915 = x16914 != '\n';
          x16917 = x16915;
        }
        bool x16918 = x16917;
        if (!x16918) break;
        x16802 = x16802 + 1;
      }
    } else {
    }
    x16802 = x16802 + 1;
    int x16943 = 0;
    for (;;) {
      long x16944 = x16802;
      char x16945 = x3635[x16944];
      bool x16946 = x16945 != '-';
      bool x16951 = x16946;
      if (x16946) {
        long x16947 = x16802;
        char x16948 = x3635[x16947];
        bool x16949 = x16948 != '\n';
        x16951 = x16949;
      }
      bool x16952 = x16951;
      if (!x16952) break;
      int x16954 = x16943;
      long x16956 = x16802;
      int x16955 = x16954 * 10;
      char x16957 = x3635[x16956];
      char x16958 = x16957 - '0';
      int x16959 = x16955 + x16958;
      x16943 = x16959;
      x16802 = x16802 + 1;
    }
    x16802 = x16802 + 1;
    int x16965 = x16943;
    int x16967 = 0;
    for (;;) {
      long x16968 = x16802;
      char x16969 = x3635[x16968];
      bool x16970 = x16969 != '-';
      bool x16975 = x16970;
      if (x16970) {
        long x16971 = x16802;
        char x16972 = x3635[x16971];
        bool x16973 = x16972 != '\n';
        x16975 = x16973;
      }
      bool x16976 = x16975;
      if (!x16976) break;
      int x16978 = x16967;
      long x16980 = x16802;
      int x16979 = x16978 * 10;
      char x16981 = x3635[x16980];
      char x16982 = x16981 - '0';
      int x16983 = x16979 + x16982;
      x16967 = x16983;
      x16802 = x16802 + 1;
    }
    x16802 = x16802 + 1;
    int x16989 = x16967;
    int x16991 = 0;
    for (;;) {
      long x16992 = x16802;
      char x16993 = x3635[x16992];
      bool x16994 = x16993 != '|';
      bool x16999 = x16994;
      if (x16994) {
        long x16995 = x16802;
        char x16996 = x3635[x16995];
        bool x16997 = x16996 != '\n';
        x16999 = x16997;
      }
      bool x17000 = x16999;
      if (!x17000) break;
      int x17002 = x16991;
      long x17004 = x16802;
      int x17003 = x17002 * 10;
      char x17005 = x3635[x17004];
      char x17006 = x17005 - '0';
      int x17007 = x17003 + x17006;
      x16991 = x17007;
      x16802 = x16802 + 1;
    }
    x16802 = x16802 + 1;
    int x17013 = x16991;
    for (;;) {
      long x17019 = x16802;
      char x17020 = x3635[x17019];
      bool x17021 = x17020 != '|';
      bool x17026 = x17021;
      if (x17021) {
        long x17022 = x16802;
        char x17023 = x3635[x17022];
        bool x17024 = x17023 != '\n';
        x17026 = x17024;
      }
      bool x17027 = x17026;
      if (!x17027) break;
      x16802 = x16802 + 1;
    }
    x16802 = x16802 + 1;
    for (;;) {
      long x17037 = x16802;
      char x17038 = x3635[x17037];
      bool x17039 = x17038 != '|';
      bool x17044 = x17039;
      if (x17039) {
        long x17040 = x16802;
        char x17041 = x3635[x17040];
        bool x17042 = x17041 != '\n';
        x17044 = x17042;
      }
      bool x17045 = x17044;
      if (!x17045) break;
      x16802 = x16802 + 1;
    }
    x16802 = x16802 + 1;
    for (;;) {
      long x17056 = x16802;
      char x17057 = x3635[x17056];
      bool x17058 = x17057 != '|';
      bool x17063 = x17058;
      if (x17058) {
        long x17059 = x16802;
        char x17060 = x3635[x17059];
        bool x17061 = x17060 != '\n';
        x17063 = x17061;
      }
      bool x17064 = x17063;
      if (!x17064) break;
      x16802 = x16802 + 1;
    }
    x16802 = x16802 + 1;
    for (;;) {
      long x17079 = x16802;
      char x17080 = x3635[x17079];
      bool x17081 = x17080 != '|';
      bool x17086 = x17081;
      if (x17081) {
        long x17082 = x16802;
        char x17083 = x3635[x17082];
        bool x17084 = x17083 != '\n';
        x17086 = x17084;
      }
      bool x17087 = x17086;
      if (!x17087) break;
      x16802 = x16802 + 1;
    }
    x16802 = x16802 + 1;
    long x17097 = x16802;
    bool x17098 = x17097 > 0L;
    bool x17104 = x17098;
    if (x17098) {
      long x17099 = x16802;
      long x17100 = x17099 - 1L;
      char x17101 = x3635[x17100];
      bool x17102 = x17101 != '\n';
      x17104 = x17102;
    }
    bool x17105 = x17104;
    if (x17105) {
      for (;;) {
        long x17106 = x16802;
        char x17107 = x3635[x17106];
        bool x17108 = x17107 != '\n';
        if (!x17108) break;
        x16802 = x16802 + 1;
      }
    } else {
    }
    x16802 = x16802 + 1;
    long x17117 = x16804;
    long x17118 = x16803;
    bool x17119 = x17117 == x17118;
    if (x17119) {
      long x17120 = x17118 * 4L;
      x16803 = x17120;
      printf("buffer.resize %ld\n",x17120);
      int* x17123 = x16806;
      int* x17124 = (int*)realloc(x17123,x17120 * sizeof(int));
      x16806 = x17124;
      long* x17135 = x16814;
      long* x17136 = (long*)realloc(x17135,x17120 * sizeof(long));
      x16814 = x17136;
    } else {
    }
    int* x17152 = x16806;
    x17152[x17117] = x16849;
    long* x17160 = x16814;
    long x17014 = x16965 * 10000L;
    long x17015 = x16989 * 100L;
    long x17016 = x17014 + x17015;
    long x17017 = x17016 + x17013;
    x17160[x17117] = x17017;
    x16804 = x16804 + 1;
  }
  long x17173 = 0L;
  long x17174 = x7;
  long x17175 = 0L;
  int* x17176 = (int*)malloc(x7 * sizeof(int));
  int* x17177 = x17176;
  int* x17178 = (int*)malloc(x7 * sizeof(int));
  int* x17179 = x17178;
  double* x17182 = (double*)malloc(x7 * sizeof(double));
  double* x17183 = x17182;
  int x1402 = open("XXXXXpartsupp.tbl",0);
  long x1403 = fsize(x1402);
  char* x1404 = mmap(0, x1403, PROT_READ, MAP_FILE | MAP_SHARED, x1402, 0);
  for (;;) {
    long x17186 = x17173;
    bool x17187 = x17186 < x1403;
    if (!x17187) break;
    int x17190 = 0;
    for (;;) {
      long x17191 = x17173;
      char x17192 = x1404[x17191];
      bool x17193 = x17192 != '|';
      bool x17198 = x17193;
      if (x17193) {
        long x17194 = x17173;
        char x17195 = x1404[x17194];
        bool x17196 = x17195 != '\n';
        x17198 = x17196;
      }
      bool x17199 = x17198;
      if (!x17199) break;
      int x17201 = x17190;
      long x17203 = x17173;
      int x17202 = x17201 * 10;
      char x17204 = x1404[x17203];
      char x17205 = x17204 - '0';
      int x17206 = x17202 + x17205;
      x17190 = x17206;
      x17173 = x17173 + 1;
    }
    x17173 = x17173 + 1;
    int x17212 = x17190;
    int x17214 = 0;
    for (;;) {
      long x17215 = x17173;
      char x17216 = x1404[x17215];
      bool x17217 = x17216 != '|';
      bool x17222 = x17217;
      if (x17217) {
        long x17218 = x17173;
        char x17219 = x1404[x17218];
        bool x17220 = x17219 != '\n';
        x17222 = x17220;
      }
      bool x17223 = x17222;
      if (!x17223) break;
      int x17225 = x17214;
      long x17227 = x17173;
      int x17226 = x17225 * 10;
      char x17228 = x1404[x17227];
      char x17229 = x17228 - '0';
      int x17230 = x17226 + x17229;
      x17214 = x17230;
      x17173 = x17173 + 1;
    }
    x17173 = x17173 + 1;
    int x17236 = x17214;
    for (;;) {
      long x17239 = x17173;
      char x17240 = x1404[x17239];
      bool x17241 = x17240 != '|';
      bool x17246 = x17241;
      if (x17241) {
        long x17242 = x17173;
        char x17243 = x1404[x17242];
        bool x17244 = x17243 != '\n';
        x17246 = x17244;
      }
      bool x17247 = x17246;
      if (!x17247) break;
      x17173 = x17173 + 1;
    }
    x17173 = x17173 + 1;
    int x17262 = 0;
    int x17263 = 1;
    for (;;) {
      long x17264 = x17173;
      char x17265 = x1404[x17264];
      bool x17266 = x17265 != '.';
      bool x17271 = x17266;
      if (x17266) {
        long x17267 = x17173;
        char x17268 = x1404[x17267];
        bool x17269 = x17268 != '|';
        x17271 = x17269;
      }
      bool x17272 = x17271;
      bool x17277 = x17272;
      if (x17272) {
        long x17273 = x17173;
        char x17274 = x1404[x17273];
        bool x17275 = x17274 != '\n';
        x17277 = x17275;
      }
      bool x17278 = x17277;
      if (!x17278) break;
      int x17280 = x17262;
      long x17282 = x17173;
      int x17281 = x17280 * 10;
      char x17283 = x1404[x17282];
      char x17284 = x17283 - '0';
      int x17285 = x17281 + x17284;
      x17262 = x17285;
      x17173 = x17173 + 1;
    }
    long x17290 = x17173;
    char x17291 = x1404[x17290];
    bool x17292 = x17291 == '.';
    if (x17292) {
      x17173 = x17173 + 1;
      for (;;) {
        long x17294 = x17173;
        char x17295 = x1404[x17294];
        bool x17296 = x17295 != '|';
        bool x17301 = x17296;
        if (x17296) {
          long x17297 = x17173;
          char x17298 = x1404[x17297];
          bool x17299 = x17298 != '\n';
          x17301 = x17299;
        }
        bool x17302 = x17301;
        if (!x17302) break;
        int x17304 = x17262;
        long x17306 = x17173;
        int x17305 = x17304 * 10;
        char x17307 = x1404[x17306];
        char x17308 = x17307 - '0';
        int x17309 = x17305 + x17308;
        x17262 = x17309;
        int x17311 = x17263;
        int x17312 = x17311 * 10;
        x17263 = x17312;
        x17173 = x17173 + 1;
      }
    } else {
    }
    x17173 = x17173 + 1;
    int x17321 = x17262;
    int x17323 = x17263;
    for (;;) {
      long x17327 = x17173;
      char x17328 = x1404[x17327];
      bool x17329 = x17328 != '|';
      bool x17334 = x17329;
      if (x17329) {
        long x17330 = x17173;
        char x17331 = x1404[x17330];
        bool x17332 = x17331 != '\n';
        x17334 = x17332;
      }
      bool x17335 = x17334;
      if (!x17335) break;
      x17173 = x17173 + 1;
    }
    x17173 = x17173 + 1;
    long x17345 = x17173;
    bool x17346 = x17345 > 0L;
    bool x17352 = x17346;
    if (x17346) {
      long x17347 = x17173;
      long x17348 = x17347 - 1L;
      char x17349 = x1404[x17348];
      bool x17350 = x17349 != '\n';
      x17352 = x17350;
    }
    bool x17353 = x17352;
    if (x17353) {
      for (;;) {
        long x17354 = x17173;
        char x17355 = x1404[x17354];
        bool x17356 = x17355 != '\n';
        if (!x17356) break;
        x17173 = x17173 + 1;
      }
    } else {
    }
    x17173 = x17173 + 1;
    long x17365 = x17175;
    long x17366 = x17174;
    bool x17367 = x17365 == x17366;
    if (x17367) {
      long x17368 = x17366 * 4L;
      x17174 = x17368;
      printf("buffer.resize %ld\n",x17368);
      int* x17371 = x17177;
      int* x17372 = (int*)realloc(x17371,x17368 * sizeof(int));
      x17177 = x17372;
      int* x17374 = x17179;
      int* x17375 = (int*)realloc(x17374,x17368 * sizeof(int));
      x17179 = x17375;
      double* x17380 = x17183;
      double* x17381 = (double*)realloc(x17380,x17368 * sizeof(double));
      x17183 = x17381;
    } else {
    }
    int* x17388 = x17177;
    x17388[x17365] = x17212;
    int* x17390 = x17179;
    x17390[x17365] = x17236;
    double* x17394 = x17183;
    double x17322 = (double)x17321;
    double x17324 = (double)x17323;
    double x17325 = x17322 / x17324;
    x17394[x17365] = x17325;
    x17175 = x17175 + 1;
  }
  long x17401 = 0L;
  long x17402 = x7;
  long x17403 = 0L;
  int* x17404 = (int*)malloc(x7 * sizeof(int));
  int* x17405 = x17404;
  int* x17410 = (int*)malloc(x7 * sizeof(int));
  int* x17411 = x17410;
  int x1908 = open("XXXXXsupplier.tbl",0);
  long x1909 = fsize(x1908);
  char* x1910 = mmap(0, x1909, PROT_READ, MAP_FILE | MAP_SHARED, x1908, 0);
  for (;;) {
    long x17418 = x17401;
    bool x17419 = x17418 < x1909;
    if (!x17419) break;
    int x17422 = 0;
    for (;;) {
      long x17423 = x17401;
      char x17424 = x1910[x17423];
      bool x17425 = x17424 != '|';
      bool x17430 = x17425;
      if (x17425) {
        long x17426 = x17401;
        char x17427 = x1910[x17426];
        bool x17428 = x17427 != '\n';
        x17430 = x17428;
      }
      bool x17431 = x17430;
      if (!x17431) break;
      int x17433 = x17422;
      long x17435 = x17401;
      int x17434 = x17433 * 10;
      char x17436 = x1910[x17435];
      char x17437 = x17436 - '0';
      int x17438 = x17434 + x17437;
      x17422 = x17438;
      x17401 = x17401 + 1;
    }
    x17401 = x17401 + 1;
    int x17444 = x17422;
    for (;;) {
      long x17446 = x17401;
      char x17447 = x1910[x17446];
      bool x17448 = x17447 != '|';
      bool x17453 = x17448;
      if (x17448) {
        long x17449 = x17401;
        char x17450 = x1910[x17449];
        bool x17451 = x17450 != '\n';
        x17453 = x17451;
      }
      bool x17454 = x17453;
      if (!x17454) break;
      x17401 = x17401 + 1;
    }
    x17401 = x17401 + 1;
    for (;;) {
      long x17464 = x17401;
      char x17465 = x1910[x17464];
      bool x17466 = x17465 != '|';
      bool x17471 = x17466;
      if (x17466) {
        long x17467 = x17401;
        char x17468 = x1910[x17467];
        bool x17469 = x17468 != '\n';
        x17471 = x17469;
      }
      bool x17472 = x17471;
      if (!x17472) break;
      x17401 = x17401 + 1;
    }
    x17401 = x17401 + 1;
    int x17482 = 0;
    for (;;) {
      long x17483 = x17401;
      char x17484 = x1910[x17483];
      bool x17485 = x17484 != '|';
      bool x17490 = x17485;
      if (x17485) {
        long x17486 = x17401;
        char x17487 = x1910[x17486];
        bool x17488 = x17487 != '\n';
        x17490 = x17488;
      }
      bool x17491 = x17490;
      if (!x17491) break;
      int x17493 = x17482;
      long x17495 = x17401;
      int x17494 = x17493 * 10;
      char x17496 = x1910[x17495];
      char x17497 = x17496 - '0';
      int x17498 = x17494 + x17497;
      x17482 = x17498;
      x17401 = x17401 + 1;
    }
    x17401 = x17401 + 1;
    int x17504 = x17482;
    for (;;) {
      long x17506 = x17401;
      char x17507 = x1910[x17506];
      bool x17508 = x17507 != '|';
      bool x17513 = x17508;
      if (x17508) {
        long x17509 = x17401;
        char x17510 = x1910[x17509];
        bool x17511 = x17510 != '\n';
        x17513 = x17511;
      }
      bool x17514 = x17513;
      if (!x17514) break;
      x17401 = x17401 + 1;
    }
    x17401 = x17401 + 1;
    for (;;) {
      long x17526 = x17401;
      char x17527 = x1910[x17526];
      bool x17528 = x17527 != '.';
      bool x17533 = x17528;
      if (x17528) {
        long x17529 = x17401;
        char x17530 = x1910[x17529];
        bool x17531 = x17530 != '|';
        x17533 = x17531;
      }
      bool x17534 = x17533;
      bool x17539 = x17534;
      if (x17534) {
        long x17535 = x17401;
        char x17536 = x1910[x17535];
        bool x17537 = x17536 != '\n';
        x17539 = x17537;
      }
      bool x17540 = x17539;
      if (!x17540) break;
      x17401 = x17401 + 1;
    }
    long x17552 = x17401;
    char x17553 = x1910[x17552];
    bool x17554 = x17553 == '.';
    if (x17554) {
      x17401 = x17401 + 1;
      for (;;) {
        long x17556 = x17401;
        char x17557 = x1910[x17556];
        bool x17558 = x17557 != '|';
        bool x17563 = x17558;
        if (x17558) {
          long x17559 = x17401;
          char x17560 = x1910[x17559];
          bool x17561 = x17560 != '\n';
          x17563 = x17561;
        }
        bool x17564 = x17563;
        if (!x17564) break;
        x17401 = x17401 + 1;
      }
    } else {
    }
    x17401 = x17401 + 1;
    for (;;) {
      long x17589 = x17401;
      char x17590 = x1910[x17589];
      bool x17591 = x17590 != '|';
      bool x17596 = x17591;
      if (x17591) {
        long x17592 = x17401;
        char x17593 = x1910[x17592];
        bool x17594 = x17593 != '\n';
        x17596 = x17594;
      }
      bool x17597 = x17596;
      if (!x17597) break;
      x17401 = x17401 + 1;
    }
    x17401 = x17401 + 1;
    long x17607 = x17401;
    bool x17608 = x17607 > 0L;
    bool x17614 = x17608;
    if (x17608) {
      long x17609 = x17401;
      long x17610 = x17609 - 1L;
      char x17611 = x1910[x17610];
      bool x17612 = x17611 != '\n';
      x17614 = x17612;
    }
    bool x17615 = x17614;
    if (x17615) {
      for (;;) {
        long x17616 = x17401;
        char x17617 = x1910[x17616];
        bool x17618 = x17617 != '\n';
        if (!x17618) break;
        x17401 = x17401 + 1;
      }
    } else {
    }
    x17401 = x17401 + 1;
    long x17627 = x17403;
    long x17628 = x17402;
    bool x17629 = x17627 == x17628;
    if (x17629) {
      long x17630 = x17628 * 4L;
      x17402 = x17630;
      printf("buffer.resize %ld\n",x17630);
      int* x17633 = x17405;
      int* x17634 = (int*)realloc(x17633,x17630 * sizeof(int));
      x17405 = x17634;
      int* x17642 = x17411;
      int* x17643 = (int*)realloc(x17642,x17630 * sizeof(int));
      x17411 = x17643;
    } else {
    }
    int* x17656 = x17405;
    x17656[x17627] = x17444;
    int* x17662 = x17411;
    x17662[x17627] = x17504;
    x17403 = x17403 + 1;
  }
  long x17673 = 0L;
  long x17674 = x7;
  long x17675 = 0L;
  int* x17676 = (int*)malloc(x7 * sizeof(int));
  int* x17677 = x17676;
  int* x17678 = (int*)malloc(x7 * sizeof(int));
  int* x17679 = x17678;
  int* x17680 = (int*)malloc(x7 * sizeof(int));
  int* x17681 = x17680;
  double* x17684 = (double*)malloc(x7 * sizeof(double));
  double* x17685 = x17684;
  double* x17686 = (double*)malloc(x7 * sizeof(double));
  double* x17687 = x17686;
  double* x17688 = (double*)malloc(x7 * sizeof(double));
  double* x17689 = x17688;
  int x3 = open("XXXXXlineitem.tbl",0);
  long x4 = fsize(x3);
  char* x5 = mmap(0, x4, PROT_READ, MAP_FILE | MAP_SHARED, x3, 0);
  for (;;) {
    long x17708 = x17673;
    bool x17709 = x17708 < x4;
    if (!x17709) break;
    int x17712 = 0;
    for (;;) {
      long x17713 = x17673;
      char x17714 = x5[x17713];
      bool x17715 = x17714 != '|';
      bool x17720 = x17715;
      if (x17715) {
        long x17716 = x17673;
        char x17717 = x5[x17716];
        bool x17718 = x17717 != '\n';
        x17720 = x17718;
      }
      bool x17721 = x17720;
      if (!x17721) break;
      int x17723 = x17712;
      long x17725 = x17673;
      int x17724 = x17723 * 10;
      char x17726 = x5[x17725];
      char x17727 = x17726 - '0';
      int x17728 = x17724 + x17727;
      x17712 = x17728;
      x17673 = x17673 + 1;
    }
    x17673 = x17673 + 1;
    int x17734 = x17712;
    int x17736 = 0;
    for (;;) {
      long x17737 = x17673;
      char x17738 = x5[x17737];
      bool x17739 = x17738 != '|';
      bool x17744 = x17739;
      if (x17739) {
        long x17740 = x17673;
        char x17741 = x5[x17740];
        bool x17742 = x17741 != '\n';
        x17744 = x17742;
      }
      bool x17745 = x17744;
      if (!x17745) break;
      int x17747 = x17736;
      long x17749 = x17673;
      int x17748 = x17747 * 10;
      char x17750 = x5[x17749];
      char x17751 = x17750 - '0';
      int x17752 = x17748 + x17751;
      x17736 = x17752;
      x17673 = x17673 + 1;
    }
    x17673 = x17673 + 1;
    int x17758 = x17736;
    int x17760 = 0;
    for (;;) {
      long x17761 = x17673;
      char x17762 = x5[x17761];
      bool x17763 = x17762 != '|';
      bool x17768 = x17763;
      if (x17763) {
        long x17764 = x17673;
        char x17765 = x5[x17764];
        bool x17766 = x17765 != '\n';
        x17768 = x17766;
      }
      bool x17769 = x17768;
      if (!x17769) break;
      int x17771 = x17760;
      long x17773 = x17673;
      int x17772 = x17771 * 10;
      char x17774 = x5[x17773];
      char x17775 = x17774 - '0';
      int x17776 = x17772 + x17775;
      x17760 = x17776;
      x17673 = x17673 + 1;
    }
    x17673 = x17673 + 1;
    int x17782 = x17760;
    for (;;) {
      long x17785 = x17673;
      char x17786 = x5[x17785];
      bool x17787 = x17786 != '|';
      bool x17792 = x17787;
      if (x17787) {
        long x17788 = x17673;
        char x17789 = x5[x17788];
        bool x17790 = x17789 != '\n';
        x17792 = x17790;
      }
      bool x17793 = x17792;
      if (!x17793) break;
      x17673 = x17673 + 1;
    }
    x17673 = x17673 + 1;
    int x17808 = 0;
    int x17809 = 1;
    for (;;) {
      long x17810 = x17673;
      char x17811 = x5[x17810];
      bool x17812 = x17811 != '.';
      bool x17817 = x17812;
      if (x17812) {
        long x17813 = x17673;
        char x17814 = x5[x17813];
        bool x17815 = x17814 != '|';
        x17817 = x17815;
      }
      bool x17818 = x17817;
      bool x17823 = x17818;
      if (x17818) {
        long x17819 = x17673;
        char x17820 = x5[x17819];
        bool x17821 = x17820 != '\n';
        x17823 = x17821;
      }
      bool x17824 = x17823;
      if (!x17824) break;
      int x17826 = x17808;
      long x17828 = x17673;
      int x17827 = x17826 * 10;
      char x17829 = x5[x17828];
      char x17830 = x17829 - '0';
      int x17831 = x17827 + x17830;
      x17808 = x17831;
      x17673 = x17673 + 1;
    }
    long x17836 = x17673;
    char x17837 = x5[x17836];
    bool x17838 = x17837 == '.';
    if (x17838) {
      x17673 = x17673 + 1;
      for (;;) {
        long x17840 = x17673;
        char x17841 = x5[x17840];
        bool x17842 = x17841 != '|';
        bool x17847 = x17842;
        if (x17842) {
          long x17843 = x17673;
          char x17844 = x5[x17843];
          bool x17845 = x17844 != '\n';
          x17847 = x17845;
        }
        bool x17848 = x17847;
        if (!x17848) break;
        int x17850 = x17808;
        long x17852 = x17673;
        int x17851 = x17850 * 10;
        char x17853 = x5[x17852];
        char x17854 = x17853 - '0';
        int x17855 = x17851 + x17854;
        x17808 = x17855;
        int x17857 = x17809;
        int x17858 = x17857 * 10;
        x17809 = x17858;
        x17673 = x17673 + 1;
      }
    } else {
    }
    x17673 = x17673 + 1;
    int x17867 = x17808;
    int x17869 = x17809;
    int x17873 = 0;
    int x17874 = 1;
    for (;;) {
      long x17875 = x17673;
      char x17876 = x5[x17875];
      bool x17877 = x17876 != '.';
      bool x17882 = x17877;
      if (x17877) {
        long x17878 = x17673;
        char x17879 = x5[x17878];
        bool x17880 = x17879 != '|';
        x17882 = x17880;
      }
      bool x17883 = x17882;
      bool x17888 = x17883;
      if (x17883) {
        long x17884 = x17673;
        char x17885 = x5[x17884];
        bool x17886 = x17885 != '\n';
        x17888 = x17886;
      }
      bool x17889 = x17888;
      if (!x17889) break;
      int x17891 = x17873;
      long x17893 = x17673;
      int x17892 = x17891 * 10;
      char x17894 = x5[x17893];
      char x17895 = x17894 - '0';
      int x17896 = x17892 + x17895;
      x17873 = x17896;
      x17673 = x17673 + 1;
    }
    long x17901 = x17673;
    char x17902 = x5[x17901];
    bool x17903 = x17902 == '.';
    if (x17903) {
      x17673 = x17673 + 1;
      for (;;) {
        long x17905 = x17673;
        char x17906 = x5[x17905];
        bool x17907 = x17906 != '|';
        bool x17912 = x17907;
        if (x17907) {
          long x17908 = x17673;
          char x17909 = x5[x17908];
          bool x17910 = x17909 != '\n';
          x17912 = x17910;
        }
        bool x17913 = x17912;
        if (!x17913) break;
        int x17915 = x17873;
        long x17917 = x17673;
        int x17916 = x17915 * 10;
        char x17918 = x5[x17917];
        char x17919 = x17918 - '0';
        int x17920 = x17916 + x17919;
        x17873 = x17920;
        int x17922 = x17874;
        int x17923 = x17922 * 10;
        x17874 = x17923;
        x17673 = x17673 + 1;
      }
    } else {
    }
    x17673 = x17673 + 1;
    int x17932 = x17873;
    int x17934 = x17874;
    int x17938 = 0;
    int x17939 = 1;
    for (;;) {
      long x17940 = x17673;
      char x17941 = x5[x17940];
      bool x17942 = x17941 != '.';
      bool x17947 = x17942;
      if (x17942) {
        long x17943 = x17673;
        char x17944 = x5[x17943];
        bool x17945 = x17944 != '|';
        x17947 = x17945;
      }
      bool x17948 = x17947;
      bool x17953 = x17948;
      if (x17948) {
        long x17949 = x17673;
        char x17950 = x5[x17949];
        bool x17951 = x17950 != '\n';
        x17953 = x17951;
      }
      bool x17954 = x17953;
      if (!x17954) break;
      int x17956 = x17938;
      long x17958 = x17673;
      int x17957 = x17956 * 10;
      char x17959 = x5[x17958];
      char x17960 = x17959 - '0';
      int x17961 = x17957 + x17960;
      x17938 = x17961;
      x17673 = x17673 + 1;
    }
    long x17966 = x17673;
    char x17967 = x5[x17966];
    bool x17968 = x17967 == '.';
    if (x17968) {
      x17673 = x17673 + 1;
      for (;;) {
        long x17970 = x17673;
        char x17971 = x5[x17970];
        bool x17972 = x17971 != '|';
        bool x17977 = x17972;
        if (x17972) {
          long x17973 = x17673;
          char x17974 = x5[x17973];
          bool x17975 = x17974 != '\n';
          x17977 = x17975;
        }
        bool x17978 = x17977;
        if (!x17978) break;
        int x17980 = x17938;
        long x17982 = x17673;
        int x17981 = x17980 * 10;
        char x17983 = x5[x17982];
        char x17984 = x17983 - '0';
        int x17985 = x17981 + x17984;
        x17938 = x17985;
        int x17987 = x17939;
        int x17988 = x17987 * 10;
        x17939 = x17988;
        x17673 = x17673 + 1;
      }
    } else {
    }
    x17673 = x17673 + 1;
    int x17997 = x17938;
    int x17999 = x17939;
    for (;;) {
      long x18005 = x17673;
      char x18006 = x5[x18005];
      bool x18007 = x18006 != '.';
      bool x18012 = x18007;
      if (x18007) {
        long x18008 = x17673;
        char x18009 = x5[x18008];
        bool x18010 = x18009 != '|';
        x18012 = x18010;
      }
      bool x18013 = x18012;
      bool x18018 = x18013;
      if (x18013) {
        long x18014 = x17673;
        char x18015 = x5[x18014];
        bool x18016 = x18015 != '\n';
        x18018 = x18016;
      }
      bool x18019 = x18018;
      if (!x18019) break;
      x17673 = x17673 + 1;
    }
    long x18031 = x17673;
    char x18032 = x5[x18031];
    bool x18033 = x18032 == '.';
    if (x18033) {
      x17673 = x17673 + 1;
      for (;;) {
        long x18035 = x17673;
        char x18036 = x5[x18035];
        bool x18037 = x18036 != '|';
        bool x18042 = x18037;
        if (x18037) {
          long x18038 = x17673;
          char x18039 = x5[x18038];
          bool x18040 = x18039 != '\n';
          x18042 = x18040;
        }
        bool x18043 = x18042;
        if (!x18043) break;
        x17673 = x17673 + 1;
      }
    } else {
    }
    x17673 = x17673 + 1;
    x17673 = x17673 + 2;
    x17673 = x17673 + 2;
    for (;;) {
      long x18075 = x17673;
      char x18076 = x5[x18075];
      bool x18077 = x18076 != '-';
      bool x18082 = x18077;
      if (x18077) {
        long x18078 = x17673;
        char x18079 = x5[x18078];
        bool x18080 = x18079 != '\n';
        x18082 = x18080;
      }
      bool x18083 = x18082;
      if (!x18083) break;
      x17673 = x17673 + 1;
    }
    x17673 = x17673 + 1;
    for (;;) {
      long x18099 = x17673;
      char x18100 = x5[x18099];
      bool x18101 = x18100 != '-';
      bool x18106 = x18101;
      if (x18101) {
        long x18102 = x17673;
        char x18103 = x5[x18102];
        bool x18104 = x18103 != '\n';
        x18106 = x18104;
      }
      bool x18107 = x18106;
      if (!x18107) break;
      x17673 = x17673 + 1;
    }
    x17673 = x17673 + 1;
    for (;;) {
      long x18123 = x17673;
      char x18124 = x5[x18123];
      bool x18125 = x18124 != '|';
      bool x18130 = x18125;
      if (x18125) {
        long x18126 = x17673;
        char x18127 = x5[x18126];
        bool x18128 = x18127 != '\n';
        x18130 = x18128;
      }
      bool x18131 = x18130;
      if (!x18131) break;
      x17673 = x17673 + 1;
    }
    x17673 = x17673 + 1;
    for (;;) {
      long x18151 = x17673;
      char x18152 = x5[x18151];
      bool x18153 = x18152 != '-';
      bool x18158 = x18153;
      if (x18153) {
        long x18154 = x17673;
        char x18155 = x5[x18154];
        bool x18156 = x18155 != '\n';
        x18158 = x18156;
      }
      bool x18159 = x18158;
      if (!x18159) break;
      x17673 = x17673 + 1;
    }
    x17673 = x17673 + 1;
    for (;;) {
      long x18175 = x17673;
      char x18176 = x5[x18175];
      bool x18177 = x18176 != '-';
      bool x18182 = x18177;
      if (x18177) {
        long x18178 = x17673;
        char x18179 = x5[x18178];
        bool x18180 = x18179 != '\n';
        x18182 = x18180;
      }
      bool x18183 = x18182;
      if (!x18183) break;
      x17673 = x17673 + 1;
    }
    x17673 = x17673 + 1;
    for (;;) {
      long x18199 = x17673;
      char x18200 = x5[x18199];
      bool x18201 = x18200 != '|';
      bool x18206 = x18201;
      if (x18201) {
        long x18202 = x17673;
        char x18203 = x5[x18202];
        bool x18204 = x18203 != '\n';
        x18206 = x18204;
      }
      bool x18207 = x18206;
      if (!x18207) break;
      x17673 = x17673 + 1;
    }
    x17673 = x17673 + 1;
    for (;;) {
      long x18227 = x17673;
      char x18228 = x5[x18227];
      bool x18229 = x18228 != '-';
      bool x18234 = x18229;
      if (x18229) {
        long x18230 = x17673;
        char x18231 = x5[x18230];
        bool x18232 = x18231 != '\n';
        x18234 = x18232;
      }
      bool x18235 = x18234;
      if (!x18235) break;
      x17673 = x17673 + 1;
    }
    x17673 = x17673 + 1;
    for (;;) {
      long x18251 = x17673;
      char x18252 = x5[x18251];
      bool x18253 = x18252 != '-';
      bool x18258 = x18253;
      if (x18253) {
        long x18254 = x17673;
        char x18255 = x5[x18254];
        bool x18256 = x18255 != '\n';
        x18258 = x18256;
      }
      bool x18259 = x18258;
      if (!x18259) break;
      x17673 = x17673 + 1;
    }
    x17673 = x17673 + 1;
    for (;;) {
      long x18275 = x17673;
      char x18276 = x5[x18275];
      bool x18277 = x18276 != '|';
      bool x18282 = x18277;
      if (x18277) {
        long x18278 = x17673;
        char x18279 = x5[x18278];
        bool x18280 = x18279 != '\n';
        x18282 = x18280;
      }
      bool x18283 = x18282;
      if (!x18283) break;
      x17673 = x17673 + 1;
    }
    x17673 = x17673 + 1;
    for (;;) {
      long x18302 = x17673;
      char x18303 = x5[x18302];
      bool x18304 = x18303 != '|';
      bool x18309 = x18304;
      if (x18304) {
        long x18305 = x17673;
        char x18306 = x5[x18305];
        bool x18307 = x18306 != '\n';
        x18309 = x18307;
      }
      bool x18310 = x18309;
      if (!x18310) break;
      x17673 = x17673 + 1;
    }
    x17673 = x17673 + 1;
    for (;;) {
      long x18320 = x17673;
      char x18321 = x5[x18320];
      bool x18322 = x18321 != '|';
      bool x18327 = x18322;
      if (x18322) {
        long x18323 = x17673;
        char x18324 = x5[x18323];
        bool x18325 = x18324 != '\n';
        x18327 = x18325;
      }
      bool x18328 = x18327;
      if (!x18328) break;
      x17673 = x17673 + 1;
    }
    x17673 = x17673 + 1;
    for (;;) {
      long x18338 = x17673;
      char x18339 = x5[x18338];
      bool x18340 = x18339 != '|';
      bool x18345 = x18340;
      if (x18340) {
        long x18341 = x17673;
        char x18342 = x5[x18341];
        bool x18343 = x18342 != '\n';
        x18345 = x18343;
      }
      bool x18346 = x18345;
      if (!x18346) break;
      x17673 = x17673 + 1;
    }
    x17673 = x17673 + 1;
    long x18356 = x17673;
    bool x18357 = x18356 > 0L;
    bool x18363 = x18357;
    if (x18357) {
      long x18358 = x17673;
      long x18359 = x18358 - 1L;
      char x18360 = x5[x18359];
      bool x18361 = x18360 != '\n';
      x18363 = x18361;
    }
    bool x18364 = x18363;
    if (x18364) {
      for (;;) {
        long x18365 = x17673;
        char x18366 = x5[x18365];
        bool x18367 = x18366 != '\n';
        if (!x18367) break;
        x17673 = x17673 + 1;
      }
    } else {
    }
    x17673 = x17673 + 1;
    long x18376 = x17675;
    long x18377 = x17674;
    bool x18378 = x18376 == x18377;
    if (x18378) {
      long x18379 = x18377 * 4L;
      x17674 = x18379;
      printf("buffer.resize %ld\n",x18379);
      int* x18382 = x17677;
      int* x18383 = (int*)realloc(x18382,x18379 * sizeof(int));
      x17677 = x18383;
      int* x18385 = x17679;
      int* x18386 = (int*)realloc(x18385,x18379 * sizeof(int));
      x17679 = x18386;
      int* x18388 = x17681;
      int* x18389 = (int*)realloc(x18388,x18379 * sizeof(int));
      x17681 = x18389;
      double* x18394 = x17685;
      double* x18395 = (double*)realloc(x18394,x18379 * sizeof(double));
      x17685 = x18395;
      double* x18397 = x17687;
      double* x18398 = (double*)realloc(x18397,x18379 * sizeof(double));
      x17687 = x18398;
      double* x18400 = x17689;
      double* x18401 = (double*)realloc(x18400,x18379 * sizeof(double));
      x17689 = x18401;
    } else {
    }
    int* x18432 = x17677;
    x18432[x18376] = x17734;
    int* x18434 = x17679;
    x18434[x18376] = x17758;
    int* x18436 = x17681;
    x18436[x18376] = x17782;
    double* x18440 = x17685;
    double x17868 = (double)x17867;
    double x17870 = (double)x17869;
    double x17871 = x17868 / x17870;
    x18440[x18376] = x17871;
    double* x18442 = x17687;
    double x17933 = (double)x17932;
    double x17935 = (double)x17934;
    double x17936 = x17933 / x17935;
    x18442[x18376] = x17936;
    double* x18444 = x17689;
    double x17998 = (double)x17997;
    double x18000 = (double)x17999;
    double x18001 = x17998 / x18000;
    x18444[x18376] = x18001;
    x17675 = x17675 + 1;
  }
  long x2189 = DEFAULT_JOIN_HASH_SIZE;
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  long x2212 = x2189 - 1L;
  long x823 = x808 - 1L;
  bool x1043 = true == false;
  int x18467;
  for(x18467=0; x18467 < 5; x18467++) {
    bool x18468 = false;
    long x18469 = 0L;
    bool x18470 = false;
    long x18471 = 0L;
    bool x18472 = false;
    long x18473 = 0L;
    bool x18474 = false;
    long x18475 = 0L;
    bool x18477 = false;
    long x18478 = 0L;
    bool x18479 = false;
    long x18480 = 0L;
    int* x18482 = (int*)malloc(x2189 * sizeof(int));
    int* x18483 = x18482;
    char** x18484 = (char**)malloc(x2189 * sizeof(char*));
    char** x18485 = x18484;
    long x18490 = 0L;
    long* x18491 = (long*)malloc(x2189 * sizeof(long));
    long* x18492 = (long*)malloc(x2189 * sizeof(long));
    long x18493;
    for(x18493=0L; x18493 < x2189; x18493++) {
      x18491[x18493] = -1L;
    }
    char** x18501 = (char**)malloc(x2189 * sizeof(char*));
    char** x18502 = x18501;
    int* x18507 = (int*)malloc(x2189 * sizeof(int));
    int* x18508 = x18507;
    long x18521 = 0L;
    long* x18522 = (long*)malloc(x2189 * sizeof(long));
    long* x18523 = (long*)malloc(x2189 * sizeof(long));
    long x18524;
    for(x18524=0L; x18524 < x2189; x18524++) {
      x18522[x18524] = -1L;
    }
    int* x18530 = (int*)malloc(x2189 * sizeof(int));
    int* x18531 = x18530;
    long x18548 = 0L;
    long* x18549 = (long*)malloc(x2189 * sizeof(long));
    long* x18550 = (long*)malloc(x2189 * sizeof(long));
    long x18551;
    for(x18551=0L; x18551 < x2189; x18551++) {
      x18549[x18551] = -1L;
    }
    int* x18557 = (int*)malloc(x2189 * sizeof(int));
    int* x18558 = x18557;
    int* x18559 = (int*)malloc(x2189 * sizeof(int));
    int* x18560 = x18559;
    double* x18563 = (double*)malloc(x2189 * sizeof(double));
    double* x18564 = x18563;
    long x18567 = 0L;
    long* x18568 = (long*)malloc(x2189 * sizeof(long));
    long* x18569 = (long*)malloc(x2189 * sizeof(long));
    long x18570;
    for(x18570=0L; x18570 < x2189; x18570++) {
      x18568[x18570] = -1L;
    }
    double* x18582 = (double*)malloc(x2189 * sizeof(double));
    double* x18583 = x18582;
    char** x18606 = (char**)malloc(x2189 * sizeof(char*));
    char** x18607 = x18606;
    int* x18626 = (int*)malloc(x2189 * sizeof(int));
    int* x18627 = x18626;
    double* x18634 = (double*)malloc(x2189 * sizeof(double));
    double* x18635 = x18634;
    double* x18636 = (double*)malloc(x2189 * sizeof(double));
    double* x18637 = x18636;
    double* x18638 = (double*)malloc(x2189 * sizeof(double));
    double* x18639 = x18638;
    long x18658 = 0L;
    long* x18659 = (long*)malloc(x2189 * sizeof(long));
    long* x18660 = (long*)malloc(x2189 * sizeof(long));
    long x18661;
    for(x18661=0L; x18661 < x2189; x18661++) {
      x18659[x18661] = -1L;
    }
    struct Anon2101649069* x18667 = (struct Anon2101649069*)malloc(x808 * sizeof(struct Anon2101649069));
    struct Anon2101649069* x18668 = x18667;
    long x18669 = 0L;
    long* x18670 = (long*)malloc(x808 * sizeof(long));
    long x18671;
    for(x18671=0L; x18671 < x808; x18671++) {
      struct Anon2101649069* x18672 = x18668;
      struct Anon2101649069 x18673 = x18672[x18671];
      struct Anon1548200872 x18674 = x18673.key;;
      struct Anon2052879266 x18675 = x18673.aggs;;
      struct Anon2101649069 x18676;
      x18676.exists = false;
      x18676.key = x18674;
      x18676.aggs = x18675;
      x18672[x18671] = x18676;
    }
    long x18681 = 1024L;
    long x18682 = 0L;
    struct Anon2101649069* x18683 = (struct Anon2101649069*)malloc(1024L * sizeof(struct Anon2101649069));
    struct Anon2101649069* x18684 = x18683;
    long x18686 = 0L;
    struct timeval x19430, x19431, x19432;
    gettimeofday(&x19430, NULL);
    printf("%s\n","begin scan PARTSUPP");
    for (;;) {
      bool x18688 = x18477;
      bool x18689 = !x18688;
      bool x18694 = x18689;
      if (x18689) {
        long x18690 = x18478;
        long x18691 = x17175;
        bool x18692 = x18690 < x18691;
        x18694 = x18692;
      }
      bool x18695 = x18694;
      if (!x18695) break;
      long x18697 = x18478;
      int* x18698 = x17177;
      int x18699 = x18698[x18697];
      int* x18700 = x17179;
      int x18701 = x18700[x18697];
      double* x18704 = x17183;
      double x18705 = x18704[x18697];
      x18478 = x18478 + 1;
      long x18710 = x18567;
      int* x18711 = x18558;
      x18711[x18710] = x18699;
      int* x18713 = x18560;
      x18713[x18710] = x18701;
      double* x18717 = x18564;
      x18717[x18710] = x18705;
      x18567 = x18567 + 1L;
      long x18722 = x18699 & x2212;
      long x18723 = x18568[x18722];
      x18568[x18722] = x18710;
      x18569[x18710] = x18723;
    }
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x18729 = x18474;
      bool x18730 = !x18729;
      bool x18735 = x18730;
      if (x18730) {
        long x18731 = x18475;
        long x18732 = x16331;
        bool x18733 = x18731 < x18732;
        x18735 = x18733;
      }
      bool x18736 = x18735;
      if (!x18736) break;
      long x18738 = x18475;
      int* x18739 = x16333;
      int x18740 = x18739[x18738];
      char** x18741 = x16335;
      char* x18742 = x18741[x18738];
      x18475 = x18475 + 1;
      bool x18759 = tpch_strstr(x18742,"green") >= x18742;
      if (x18759) {
        long x18760 = x18548;
        int* x18761 = x18531;
        x18761[x18760] = x18740;
        x18548 = x18548 + 1L;
        long x18780 = x18740 & x2212;
        long x18781 = x18549[x18780];
        x18549[x18780] = x18760;
        x18550[x18760] = x18781;
      } else {
      }
    }
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x18789 = x18468;
      bool x18790 = !x18789;
      bool x18795 = x18790;
      if (x18790) {
        long x18791 = x18469;
        long x18792 = x16654;
        bool x18793 = x18791 < x18792;
        x18795 = x18793;
      }
      bool x18796 = x18795;
      if (!x18796) break;
      long x18798 = x18469;
      int* x18799 = x16656;
      int x18800 = x18799[x18798];
      char** x18801 = x16658;
      char* x18802 = x18801[x18798];
      x18469 = x18469 + 1;
      long x18809 = x18490;
      int* x18810 = x18483;
      x18810[x18809] = x18800;
      char** x18812 = x18485;
      x18812[x18809] = x18802;
      x18490 = x18490 + 1L;
      long x18819 = x18800 & x2212;
      long x18820 = x18491[x18819];
      x18491[x18819] = x18809;
      x18492[x18809] = x18820;
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x18826 = x18470;
      bool x18827 = !x18826;
      bool x18832 = x18827;
      if (x18827) {
        long x18828 = x18471;
        long x18829 = x17403;
        bool x18830 = x18828 < x18829;
        x18832 = x18830;
      }
      bool x18833 = x18832;
      if (!x18833) break;
      long x18835 = x18471;
      int* x18836 = x17405;
      int x18837 = x18836[x18835];
      int* x18842 = x17411;
      int x18843 = x18842[x18835];
      x18471 = x18471 + 1;
      long x18852 = x18843 & x2212;
      long x18853 = x18491[x18852];
      long x18854 = x18853;
      long x18898 = x18837 & x2212;
      for (;;) {
        long x18855 = x18854;
        bool x18856 = x18855 != -1;
        if (!x18856) break;
        long x18858 = x18854;
        int* x18859 = x18483;
        int x18860 = x18859[x18858];
        char** x18861 = x18485;
        char* x18862 = x18861[x18858];
        long x18868 = x18492[x18858];
        x18854 = x18868;
        bool x18870 = x18860 == x18843;
        if (x18870) {
          long x18874 = x18521;
          char** x18877 = x18502;
          x18877[x18874] = x18862;
          int* x18883 = x18508;
          x18883[x18874] = x18837;
          x18521 = x18521 + 1L;
          long x18899 = x18522[x18898];
          x18522[x18898] = x18874;
          x18523[x18874] = x18899;
        } else {
        }
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x18909 = x18472;
      bool x18910 = !x18909;
      bool x18915 = x18910;
      if (x18910) {
        long x18911 = x18473;
        long x18912 = x17675;
        bool x18913 = x18911 < x18912;
        x18915 = x18913;
      }
      bool x18916 = x18915;
      if (!x18916) break;
      long x18918 = x18473;
      int* x18919 = x17677;
      int x18920 = x18919[x18918];
      int* x18921 = x17679;
      int x18922 = x18921[x18918];
      int* x18923 = x17681;
      int x18924 = x18923[x18918];
      double* x18927 = x17685;
      double x18928 = x18927[x18918];
      double* x18929 = x17687;
      double x18930 = x18929[x18918];
      double* x18931 = x17689;
      double x18932 = x18931[x18918];
      x18473 = x18473 + 1;
      long x18953 = x18924 & x2212;
      long x18954 = x18522[x18953];
      long x18955 = x18954;
      long x18989 = x18922 & x2212;
      long x19131 = x18920 & x2212;
      for (;;) {
        long x18956 = x18955;
        bool x18957 = x18956 != -1;
        if (!x18957) break;
        long x18959 = x18955;
        char** x18962 = x18502;
        char* x18963 = x18962[x18959];
        int* x18968 = x18508;
        int x18969 = x18968[x18959];
        long x18983 = x18523[x18959];
        x18955 = x18983;
        bool x18985 = x18969 == x18924;
        if (x18985) {
          long x18990 = x18549[x18989];
          long x18991 = x18990;
          for (;;) {
            long x18992 = x18991;
            bool x18993 = x18992 != -1;
            if (!x18993) break;
            long x18995 = x18991;
            int* x18996 = x18531;
            int x18997 = x18996[x18995];
            long x19015 = x18550[x18995];
            x18991 = x19015;
            bool x19017 = x18997 == x18922;
            if (x19017) {
              long x19021 = x18568[x18989];
              long x19022 = x19021;
              for (;;) {
                long x19023 = x19022;
                bool x19024 = x19023 != -1;
                if (!x19024) break;
                long x19026 = x19022;
                int* x19027 = x18558;
                int x19028 = x19027[x19026];
                int* x19029 = x18560;
                int x19030 = x19029[x19026];
                double* x19033 = x18564;
                double x19034 = x19033[x19026];
                long x19038 = x18569[x19026];
                x19022 = x19038;
                bool x19040 = x19028 == x18922;
                bool x19042 = x19040;
                if (x19040) {
                  bool x19041 = x19030 == x18924;
                  x19042 = x19041;
                }
                bool x19043 = x19042;
                if (x19043) {
                  long x19047 = x18658;
                  double* x19054 = x18583;
                  x19054[x19047] = x19034;
                  char** x19078 = x18607;
                  x19078[x19047] = x18963;
                  int* x19098 = x18627;
                  x19098[x19047] = x18920;
                  double* x19106 = x18635;
                  x19106[x19047] = x18928;
                  double* x19108 = x18637;
                  x19108[x19047] = x18930;
                  double* x19110 = x18639;
                  x19110[x19047] = x18932;
                  x18658 = x18658 + 1L;
                  long x19132 = x18659[x19131];
                  x18659[x19131] = x19047;
                  x18660[x19047] = x19132;
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
      bool x19150 = x18479;
      bool x19151 = !x19150;
      bool x19156 = x19151;
      if (x19151) {
        long x19152 = x18480;
        long x19153 = x16804;
        bool x19154 = x19152 < x19153;
        x19156 = x19154;
      }
      bool x19157 = x19156;
      if (!x19157) break;
      long x19159 = x18480;
      int* x19160 = x16806;
      int x19161 = x19160[x19159];
      long* x19168 = x16814;
      long x19169 = x19168[x19159];
      x18480 = x18480 + 1;
      long x19180 = x19161 & x2212;
      long x19181 = x18659[x19180];
      long x19182 = x19181;
      long x19276 = x19169; // date
      long x19277 = x19276/10000;
      int x19278 = (int)x19277;
      for (;;) {
        long x19183 = x19182;
        bool x19184 = x19183 != -1;
        if (!x19184) break;
        long x19186 = x19182;
        double* x19193 = x18583;
        double x19194 = x19193[x19186];
        char** x19217 = x18607;
        char* x19218 = x19217[x19186];
        int* x19237 = x18627;
        int x19238 = x19237[x19186];
        double* x19245 = x18635;
        double x19246 = x19245[x19186];
        double* x19247 = x18637;
        double x19248 = x19247[x19186];
        double* x19249 = x18639;
        double x19250 = x19249[x19186];
        long x19270 = x18660[x19186];
        x19182 = x19270;
        bool x19272 = x19238 == x19161;
        if (x19272) {
          long x19280 = hash(x19218, 10L);
          long x19281 = x19280 * 41L;
          long x19282 = x19281 + x19278;
          long x19283 = x19282 & x823;
          long x19284 = x19283;
          struct Anon2101649069* x19285 = x18668;
          struct Anon2101649069 x19286 = x19285[x19283];
          struct Anon2101649069 x19287 = x19286;
          bool x19288 = x19286.exists;;
          bool x19298 = x19288;
          if (x19288) {
            struct Anon2101649069 x19289 = x19287;
            struct Anon1548200872 x19290 = x19289.key;;
            char* x19291 = x19290.NATION;;
            bool x19292 = tpch_strcmp(x19291,x19218) == 0;;
            bool x19295 = x19292;
            if (x19292) {
              int x19293 = x19290.O_YEAR;;
              bool x19294 = x19293 == x19278;
              x19295 = x19294;
            }
            bool x19296 = x19295;
            x19298 = x19296;
          }
          bool x19299 = x19298;
          if (x19299) {
            struct Anon2052879266 x19300 = x19286.aggs;;
            struct Anon1548200872 x19308 = x19286.key;;
            double x19301 = x19300._0;;
            double x19302 = 1.0 - x19250;
            double x19303 = x19248 * x19302;
            double x19304 = x19194 * x19246;
            double x19305 = x19303 - x19304;
            double x19306 = x19301 + x19305;
            struct Anon2052879266 x19307;
            x19307._0 = x19306;
            struct Anon2101649069 x19309;
            x19309.exists = true;
            x19309.key = x19308;
            x19309.aggs = x19307;
            x19285[x19283] = x19309;
          } else {
            double x19302 = 1.0 - x19250;
            double x19303 = x19248 * x19302;
            double x19304 = x19194 * x19246;
            double x19305 = x19303 - x19304;
            struct Anon1548200872 x19279;
            x19279.NATION = x19218;
            x19279.O_YEAR = x19278;
            struct Anon2052879266 x19343;
            x19343._0 = x19305;
            struct Anon2101649069 x19344;
            x19344.exists = true;
            x19344.key = x19279;
            x19344.aggs = x19343;
            for (;;) {
              struct Anon2101649069 x19312 = x19287;
              bool x19313 = x19312.exists;;
              bool x19353;
              if (x19313) {
                struct Anon1548200872 x19314 = x19312.key;;
                char* x19315 = x19314.NATION;;
                bool x19316 = tpch_strcmp(x19315,x19218) == 0;;
                bool x19319 = x19316;
                if (x19316) {
                  int x19317 = x19314.O_YEAR;;
                  bool x19318 = x19317 == x19278;
                  x19319 = x19318;
                }
                bool x19320 = x19319;
                bool x19340;
                if (x19320) {
                  struct Anon2052879266 x19321 = x19312.aggs;;
                  long x19325 = x19284;
                  struct Anon2101649069* x19327 = x18668;
                  double x19322 = x19321._0;;
                  double x19323 = x19322 + x19305;
                  struct Anon2052879266 x19324;
                  x19324._0 = x19323;
                  struct Anon2101649069 x19326;
                  x19326.exists = true;
                  x19326.key = x19314;
                  x19326.aggs = x19324;
                  x19327[x19325] = x19326;
                  x19340 = false;
                } else {
                  long x19330 = x19284;
                  long x19331 = x19330 + 1L;
                  long x19332 = x19331 & x823;
                  x19284 = x19332;
                  struct Anon2101649069* x19334 = x18668;
                  struct Anon2101649069 x19335 = x19334[x19332];
                  x19287 = x19335;
                  x19340 = true;
                }
                x19353 = x19340;
              } else {
                long x19342 = x19284;
                struct Anon2101649069* x19345 = x18668;
                x19345[x19342] = x19344;
                long x19347 = x18669;
                x18670[x19347] = x19342;
                x18669 = x18669 + 1L;
                x19353 = false;
              }
              if (!x19353) break;
            }
          }
        } else {
        }
      }
    }
    long x19366 = x18669;
    long x19368;
    for(x19368=0L; x19368 < x19366; x19368++) {
      long x19369 = x18670[x19368];
      struct Anon2101649069* x19370 = x18668;
      struct Anon2101649069 x19371 = x19370[x19369];
      long x19372 = x18682;
      long x19373 = x18681;
      bool x19374 = x19372 == x19373;
      if (x19374) {
        long x19375 = x19373 * 4L;
        x18681 = x19375;
        struct Anon2101649069* x19377 = x18684;
        struct Anon2101649069* x19378 = (struct Anon2101649069 *)realloc(x19377,x19375* sizeof(struct Anon2101649069));
        x18684 = x19378;
      } else {
      }
      struct Anon2101649069* x19382 = x18684;
      x19382[x19372] = x19371;
      x18682 = x18682 + 1;
    }
    long x19387 = x18682;
    struct Anon2101649069* x19388 = x18684;
    qsort((void *)x19388,x19387,sizeof(struct Anon2101649069), (__compar_fn_t)x19407); // x19408
    long x19410;
    for(x19410=0L; x19410 < x19387; x19410++) {
      struct Anon2101649069* x19411 = x18684;
      struct Anon2101649069 x19412 = x19411[x19410];
      if (x1043) {
      } else {
        struct Anon1548200872 x19415 = x19412.key;;
        struct Anon2052879266 x19419 = x19412.aggs;;
        char* x19416 = x19415.NATION;;
        int x19417 = tpch_strlen(x19416);
        int x19418 = x19415.O_YEAR;;
        double x19420 = x19419._0;;
        printf("%.*s|%d|%.4f\n",x19417,x19416,x19418,x19420);
        x18686 = x18686 + 1L;
      }
    }
    long x19427 = x18686;
    printf("(%ld rows)\n",x19427);
    gettimeofday(&x19431, NULL);
    timeval_subtract(&x19432, &x19431, &x19430);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x19432.tv_sec * 1000) + (x19432.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
