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

struct Anon2053173900 {
int key;
double wnd;
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

struct Anon2131541195 {
double total;
};

struct Anon152692660 {
bool exists;
int key;
struct Anon2052879266 aggs;
};

struct Anon0 {
struct Anon2131541195 left;
struct Anon152692660 right;
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
int x22928(struct Anon2053173900* x22917, struct Anon2053173900* x22918);
int x22928(struct Anon2053173900* x22917, struct Anon2053173900* x22918) {
  struct Anon2053173900 x22919 = (*x22917);
  struct Anon2053173900 x22920 = (*x22918);
  double x22921 = x22919.wnd;;
  double x22922 = x22920.wnd;;
  bool x22923 = x22921 > x22922;
  int x22926;
  if (x22923) {
    x22926 = -1;
  } else {
    bool x22924 = x22921 < x22922;
    int x22925;
    if (x22924) {
      x22925 = 1;
    } else {
      x22925 = 0;
    }
    x22926 = x22925;
  }
  return x22926;
}

/************************ MAIN BODY **************************/
int main(int x21743, char** x21744) {
  long x21745 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x21746 = x7;
  long x21747 = 0L;
  int* x21748 = (int*)malloc(x7 * sizeof(int));
  int* x21749 = x21748;
  int* x21750 = (int*)malloc(x7 * sizeof(int));
  int* x21751 = x21750;
  int* x21752 = (int*)malloc(x7 * sizeof(int));
  int* x21753 = x21752;
  double* x21754 = (double*)malloc(x7 * sizeof(double));
  double* x21755 = x21754;
  int x1402 = open("XXXXXpartsupp.tbl",0);
  long x1403 = fsize(x1402);
  char* x1404 = mmap(0, x1403, PROT_READ, MAP_FILE | MAP_SHARED, x1402, 0);
  for (;;) {
    long x21758 = x21745;
    bool x21759 = x21758 < x1403;
    if (!x21759) break;
    int x21762 = 0;
    for (;;) {
      long x21763 = x21745;
      char x21764 = x1404[x21763];
      bool x21765 = x21764 != '|';
      bool x21770 = x21765;
      if (x21765) {
        long x21766 = x21745;
        char x21767 = x1404[x21766];
        bool x21768 = x21767 != '\n';
        x21770 = x21768;
      }
      bool x21771 = x21770;
      if (!x21771) break;
      int x21773 = x21762;
      long x21775 = x21745;
      int x21774 = x21773 * 10;
      char x21776 = x1404[x21775];
      char x21777 = x21776 - '0';
      int x21778 = x21774 + x21777;
      x21762 = x21778;
      x21745 = x21745 + 1;
    }
    x21745 = x21745 + 1;
    int x21784 = x21762;
    int x21786 = 0;
    for (;;) {
      long x21787 = x21745;
      char x21788 = x1404[x21787];
      bool x21789 = x21788 != '|';
      bool x21794 = x21789;
      if (x21789) {
        long x21790 = x21745;
        char x21791 = x1404[x21790];
        bool x21792 = x21791 != '\n';
        x21794 = x21792;
      }
      bool x21795 = x21794;
      if (!x21795) break;
      int x21797 = x21786;
      long x21799 = x21745;
      int x21798 = x21797 * 10;
      char x21800 = x1404[x21799];
      char x21801 = x21800 - '0';
      int x21802 = x21798 + x21801;
      x21786 = x21802;
      x21745 = x21745 + 1;
    }
    x21745 = x21745 + 1;
    int x21808 = x21786;
    int x21810 = 0;
    for (;;) {
      long x21811 = x21745;
      char x21812 = x1404[x21811];
      bool x21813 = x21812 != '|';
      bool x21818 = x21813;
      if (x21813) {
        long x21814 = x21745;
        char x21815 = x1404[x21814];
        bool x21816 = x21815 != '\n';
        x21818 = x21816;
      }
      bool x21819 = x21818;
      if (!x21819) break;
      int x21821 = x21810;
      long x21823 = x21745;
      int x21822 = x21821 * 10;
      char x21824 = x1404[x21823];
      char x21825 = x21824 - '0';
      int x21826 = x21822 + x21825;
      x21810 = x21826;
      x21745 = x21745 + 1;
    }
    x21745 = x21745 + 1;
    int x21832 = x21810;
    int x21834 = 0;
    int x21835 = 1;
    for (;;) {
      long x21836 = x21745;
      char x21837 = x1404[x21836];
      bool x21838 = x21837 != '.';
      bool x21843 = x21838;
      if (x21838) {
        long x21839 = x21745;
        char x21840 = x1404[x21839];
        bool x21841 = x21840 != '|';
        x21843 = x21841;
      }
      bool x21844 = x21843;
      bool x21849 = x21844;
      if (x21844) {
        long x21845 = x21745;
        char x21846 = x1404[x21845];
        bool x21847 = x21846 != '\n';
        x21849 = x21847;
      }
      bool x21850 = x21849;
      if (!x21850) break;
      int x21852 = x21834;
      long x21854 = x21745;
      int x21853 = x21852 * 10;
      char x21855 = x1404[x21854];
      char x21856 = x21855 - '0';
      int x21857 = x21853 + x21856;
      x21834 = x21857;
      x21745 = x21745 + 1;
    }
    long x21862 = x21745;
    char x21863 = x1404[x21862];
    bool x21864 = x21863 == '.';
    if (x21864) {
      x21745 = x21745 + 1;
      for (;;) {
        long x21866 = x21745;
        char x21867 = x1404[x21866];
        bool x21868 = x21867 != '|';
        bool x21873 = x21868;
        if (x21868) {
          long x21869 = x21745;
          char x21870 = x1404[x21869];
          bool x21871 = x21870 != '\n';
          x21873 = x21871;
        }
        bool x21874 = x21873;
        if (!x21874) break;
        int x21876 = x21834;
        long x21878 = x21745;
        int x21877 = x21876 * 10;
        char x21879 = x1404[x21878];
        char x21880 = x21879 - '0';
        int x21881 = x21877 + x21880;
        x21834 = x21881;
        int x21883 = x21835;
        int x21884 = x21883 * 10;
        x21835 = x21884;
        x21745 = x21745 + 1;
      }
    } else {
    }
    x21745 = x21745 + 1;
    int x21893 = x21834;
    int x21895 = x21835;
    for (;;) {
      long x21899 = x21745;
      char x21900 = x1404[x21899];
      bool x21901 = x21900 != '|';
      bool x21906 = x21901;
      if (x21901) {
        long x21902 = x21745;
        char x21903 = x1404[x21902];
        bool x21904 = x21903 != '\n';
        x21906 = x21904;
      }
      bool x21907 = x21906;
      if (!x21907) break;
      x21745 = x21745 + 1;
    }
    x21745 = x21745 + 1;
    long x21917 = x21745;
    bool x21918 = x21917 > 0L;
    bool x21924 = x21918;
    if (x21918) {
      long x21919 = x21745;
      long x21920 = x21919 - 1L;
      char x21921 = x1404[x21920];
      bool x21922 = x21921 != '\n';
      x21924 = x21922;
    }
    bool x21925 = x21924;
    if (x21925) {
      for (;;) {
        long x21926 = x21745;
        char x21927 = x1404[x21926];
        bool x21928 = x21927 != '\n';
        if (!x21928) break;
        x21745 = x21745 + 1;
      }
    } else {
    }
    x21745 = x21745 + 1;
    long x21937 = x21747;
    long x21938 = x21746;
    bool x21939 = x21937 == x21938;
    if (x21939) {
      long x21940 = x21938 * 4L;
      x21746 = x21940;
      printf("buffer.resize %ld\n",x21940);
      int* x21943 = x21749;
      int* x21944 = (int*)realloc(x21943,x21940 * sizeof(int));
      x21749 = x21944;
      int* x21946 = x21751;
      int* x21947 = (int*)realloc(x21946,x21940 * sizeof(int));
      x21751 = x21947;
      int* x21949 = x21753;
      int* x21950 = (int*)realloc(x21949,x21940 * sizeof(int));
      x21753 = x21950;
      double* x21952 = x21755;
      double* x21953 = (double*)realloc(x21952,x21940 * sizeof(double));
      x21755 = x21953;
    } else {
    }
    int* x21960 = x21749;
    x21960[x21937] = x21784;
    int* x21962 = x21751;
    x21962[x21937] = x21808;
    int* x21964 = x21753;
    x21964[x21937] = x21832;
    double* x21966 = x21755;
    double x21894 = (double)x21893;
    double x21896 = (double)x21895;
    double x21897 = x21894 / x21896;
    x21966[x21937] = x21897;
    x21747 = x21747 + 1;
  }
  long x21973 = 0L;
  long x21974 = x7;
  long x21975 = 0L;
  int* x21976 = (int*)malloc(x7 * sizeof(int));
  int* x21977 = x21976;
  int* x21982 = (int*)malloc(x7 * sizeof(int));
  int* x21983 = x21982;
  int x1908 = open("XXXXXsupplier.tbl",0);
  long x1909 = fsize(x1908);
  char* x1910 = mmap(0, x1909, PROT_READ, MAP_FILE | MAP_SHARED, x1908, 0);
  for (;;) {
    long x21990 = x21973;
    bool x21991 = x21990 < x1909;
    if (!x21991) break;
    int x21994 = 0;
    for (;;) {
      long x21995 = x21973;
      char x21996 = x1910[x21995];
      bool x21997 = x21996 != '|';
      bool x22002 = x21997;
      if (x21997) {
        long x21998 = x21973;
        char x21999 = x1910[x21998];
        bool x22000 = x21999 != '\n';
        x22002 = x22000;
      }
      bool x22003 = x22002;
      if (!x22003) break;
      int x22005 = x21994;
      long x22007 = x21973;
      int x22006 = x22005 * 10;
      char x22008 = x1910[x22007];
      char x22009 = x22008 - '0';
      int x22010 = x22006 + x22009;
      x21994 = x22010;
      x21973 = x21973 + 1;
    }
    x21973 = x21973 + 1;
    int x22016 = x21994;
    for (;;) {
      long x22018 = x21973;
      char x22019 = x1910[x22018];
      bool x22020 = x22019 != '|';
      bool x22025 = x22020;
      if (x22020) {
        long x22021 = x21973;
        char x22022 = x1910[x22021];
        bool x22023 = x22022 != '\n';
        x22025 = x22023;
      }
      bool x22026 = x22025;
      if (!x22026) break;
      x21973 = x21973 + 1;
    }
    x21973 = x21973 + 1;
    for (;;) {
      long x22036 = x21973;
      char x22037 = x1910[x22036];
      bool x22038 = x22037 != '|';
      bool x22043 = x22038;
      if (x22038) {
        long x22039 = x21973;
        char x22040 = x1910[x22039];
        bool x22041 = x22040 != '\n';
        x22043 = x22041;
      }
      bool x22044 = x22043;
      if (!x22044) break;
      x21973 = x21973 + 1;
    }
    x21973 = x21973 + 1;
    int x22054 = 0;
    for (;;) {
      long x22055 = x21973;
      char x22056 = x1910[x22055];
      bool x22057 = x22056 != '|';
      bool x22062 = x22057;
      if (x22057) {
        long x22058 = x21973;
        char x22059 = x1910[x22058];
        bool x22060 = x22059 != '\n';
        x22062 = x22060;
      }
      bool x22063 = x22062;
      if (!x22063) break;
      int x22065 = x22054;
      long x22067 = x21973;
      int x22066 = x22065 * 10;
      char x22068 = x1910[x22067];
      char x22069 = x22068 - '0';
      int x22070 = x22066 + x22069;
      x22054 = x22070;
      x21973 = x21973 + 1;
    }
    x21973 = x21973 + 1;
    int x22076 = x22054;
    for (;;) {
      long x22078 = x21973;
      char x22079 = x1910[x22078];
      bool x22080 = x22079 != '|';
      bool x22085 = x22080;
      if (x22080) {
        long x22081 = x21973;
        char x22082 = x1910[x22081];
        bool x22083 = x22082 != '\n';
        x22085 = x22083;
      }
      bool x22086 = x22085;
      if (!x22086) break;
      x21973 = x21973 + 1;
    }
    x21973 = x21973 + 1;
    for (;;) {
      long x22098 = x21973;
      char x22099 = x1910[x22098];
      bool x22100 = x22099 != '.';
      bool x22105 = x22100;
      if (x22100) {
        long x22101 = x21973;
        char x22102 = x1910[x22101];
        bool x22103 = x22102 != '|';
        x22105 = x22103;
      }
      bool x22106 = x22105;
      bool x22111 = x22106;
      if (x22106) {
        long x22107 = x21973;
        char x22108 = x1910[x22107];
        bool x22109 = x22108 != '\n';
        x22111 = x22109;
      }
      bool x22112 = x22111;
      if (!x22112) break;
      x21973 = x21973 + 1;
    }
    long x22124 = x21973;
    char x22125 = x1910[x22124];
    bool x22126 = x22125 == '.';
    if (x22126) {
      x21973 = x21973 + 1;
      for (;;) {
        long x22128 = x21973;
        char x22129 = x1910[x22128];
        bool x22130 = x22129 != '|';
        bool x22135 = x22130;
        if (x22130) {
          long x22131 = x21973;
          char x22132 = x1910[x22131];
          bool x22133 = x22132 != '\n';
          x22135 = x22133;
        }
        bool x22136 = x22135;
        if (!x22136) break;
        x21973 = x21973 + 1;
      }
    } else {
    }
    x21973 = x21973 + 1;
    for (;;) {
      long x22161 = x21973;
      char x22162 = x1910[x22161];
      bool x22163 = x22162 != '|';
      bool x22168 = x22163;
      if (x22163) {
        long x22164 = x21973;
        char x22165 = x1910[x22164];
        bool x22166 = x22165 != '\n';
        x22168 = x22166;
      }
      bool x22169 = x22168;
      if (!x22169) break;
      x21973 = x21973 + 1;
    }
    x21973 = x21973 + 1;
    long x22179 = x21973;
    bool x22180 = x22179 > 0L;
    bool x22186 = x22180;
    if (x22180) {
      long x22181 = x21973;
      long x22182 = x22181 - 1L;
      char x22183 = x1910[x22182];
      bool x22184 = x22183 != '\n';
      x22186 = x22184;
    }
    bool x22187 = x22186;
    if (x22187) {
      for (;;) {
        long x22188 = x21973;
        char x22189 = x1910[x22188];
        bool x22190 = x22189 != '\n';
        if (!x22190) break;
        x21973 = x21973 + 1;
      }
    } else {
    }
    x21973 = x21973 + 1;
    long x22199 = x21975;
    long x22200 = x21974;
    bool x22201 = x22199 == x22200;
    if (x22201) {
      long x22202 = x22200 * 4L;
      x21974 = x22202;
      printf("buffer.resize %ld\n",x22202);
      int* x22205 = x21977;
      int* x22206 = (int*)realloc(x22205,x22202 * sizeof(int));
      x21977 = x22206;
      int* x22214 = x21983;
      int* x22215 = (int*)realloc(x22214,x22202 * sizeof(int));
      x21983 = x22215;
    } else {
    }
    int* x22228 = x21977;
    x22228[x22199] = x22016;
    int* x22234 = x21983;
    x22234[x22199] = x22076;
    x21975 = x21975 + 1;
  }
  long x22245 = 0L;
  long x22246 = x7;
  long x22247 = 0L;
  int* x22248 = (int*)malloc(x7 * sizeof(int));
  int* x22249 = x22248;
  char** x22250 = (char**)malloc(x7 * sizeof(char*));
  char** x22251 = x22250;
  int x1633 = open("XXXXXnation.tbl",0);
  long x1634 = fsize(x1633);
  char* x1635 = mmap(0, x1634, PROT_READ, MAP_FILE | MAP_SHARED, x1633, 0);
  for (;;) {
    long x22256 = x22245;
    bool x22257 = x22256 < x1634;
    if (!x22257) break;
    int x22260 = 0;
    for (;;) {
      long x22261 = x22245;
      char x22262 = x1635[x22261];
      bool x22263 = x22262 != '|';
      bool x22268 = x22263;
      if (x22263) {
        long x22264 = x22245;
        char x22265 = x1635[x22264];
        bool x22266 = x22265 != '\n';
        x22268 = x22266;
      }
      bool x22269 = x22268;
      if (!x22269) break;
      int x22271 = x22260;
      long x22273 = x22245;
      int x22272 = x22271 * 10;
      char x22274 = x1635[x22273];
      char x22275 = x22274 - '0';
      int x22276 = x22272 + x22275;
      x22260 = x22276;
      x22245 = x22245 + 1;
    }
    x22245 = x22245 + 1;
    int x22282 = x22260;
    long x22283 = x22245;
    for (;;) {
      long x22284 = x22245;
      char x22285 = x1635[x22284];
      bool x22286 = x22285 != '|';
      bool x22291 = x22286;
      if (x22286) {
        long x22287 = x22245;
        char x22288 = x1635[x22287];
        bool x22289 = x22288 != '\n';
        x22291 = x22289;
      }
      bool x22292 = x22291;
      if (!x22292) break;
      x22245 = x22245 + 1;
    }
    x22245 = x22245 + 1;
    for (;;) {
      long x22303 = x22245;
      char x22304 = x1635[x22303];
      bool x22305 = x22304 != '|';
      bool x22310 = x22305;
      if (x22305) {
        long x22306 = x22245;
        char x22307 = x1635[x22306];
        bool x22308 = x22307 != '\n';
        x22310 = x22308;
      }
      bool x22311 = x22310;
      if (!x22311) break;
      x22245 = x22245 + 1;
    }
    x22245 = x22245 + 1;
    for (;;) {
      long x22326 = x22245;
      char x22327 = x1635[x22326];
      bool x22328 = x22327 != '|';
      bool x22333 = x22328;
      if (x22328) {
        long x22329 = x22245;
        char x22330 = x1635[x22329];
        bool x22331 = x22330 != '\n';
        x22333 = x22331;
      }
      bool x22334 = x22333;
      if (!x22334) break;
      x22245 = x22245 + 1;
    }
    x22245 = x22245 + 1;
    long x22344 = x22245;
    bool x22345 = x22344 > 0L;
    bool x22351 = x22345;
    if (x22345) {
      long x22346 = x22245;
      long x22347 = x22346 - 1L;
      char x22348 = x1635[x22347];
      bool x22349 = x22348 != '\n';
      x22351 = x22349;
    }
    bool x22352 = x22351;
    if (x22352) {
      for (;;) {
        long x22353 = x22245;
        char x22354 = x1635[x22353];
        bool x22355 = x22354 != '\n';
        if (!x22355) break;
        x22245 = x22245 + 1;
      }
    } else {
    }
    x22245 = x22245 + 1;
    long x22364 = x22247;
    long x22365 = x22246;
    bool x22366 = x22364 == x22365;
    if (x22366) {
      long x22367 = x22365 * 4L;
      x22246 = x22367;
      printf("buffer.resize %ld\n",x22367);
      int* x22370 = x22249;
      int* x22371 = (int*)realloc(x22370,x22367 * sizeof(int));
      x22249 = x22371;
      char** x22373 = x22251;
      char** x22374 = (char**)realloc(x22373,x22367 * sizeof(char*));
      x22251 = x22374;
    } else {
    }
    int* x22384 = x22249;
    x22384[x22364] = x22282;
    char** x22386 = x22251;
    char* x22300 = x1635+x22283;
    x22386[x22364] = x22300;
    x22247 = x22247 + 1;
  }
  long x2189 = DEFAULT_JOIN_HASH_SIZE;
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  long x22466 = DEFAULT_VIEW_SIZE;
  long x2212 = x2189 - 1L;
  long x823 = x808 - 1L;
  bool x1043 = true == false;
  int x22395;
  for(x22395=0; x22395 < 5; x22395++) {
    bool x22396 = false;
    long x22397 = 0L;
    bool x22398 = false;
    long x22399 = 0L;
    int* x22402 = (int*)malloc(x2189 * sizeof(int));
    int* x22403 = x22402;
    long x22410 = 0L;
    long* x22411 = (long*)malloc(x2189 * sizeof(long));
    long* x22412 = (long*)malloc(x2189 * sizeof(long));
    long x22413;
    for(x22413=0L; x22413 < x2189; x22413++) {
      x22411[x22413] = -1L;
    }
    bool x22418 = false;
    long x22419 = 0L;
    int* x22429 = (int*)malloc(x2189 * sizeof(int));
    int* x22430 = x22429;
    long x22443 = 0L;
    long* x22444 = (long*)malloc(x2189 * sizeof(long));
    long* x22445 = (long*)malloc(x2189 * sizeof(long));
    long x22446;
    for(x22446=0L; x22446 < x2189; x22446++) {
      x22444[x22446] = -1L;
    }
    struct Anon152692660* x22452 = (struct Anon152692660*)malloc(x808 * sizeof(struct Anon152692660));
    struct Anon152692660* x22453 = x22452;
    long x22454 = 0L;
    long* x22455 = (long*)malloc(x808 * sizeof(long));
    long x22456;
    for(x22456=0L; x22456 < x808; x22456++) {
      struct Anon152692660* x22457 = x22453;
      struct Anon152692660 x22458 = x22457[x22456];
      int x22459 = x22458.key;;
      struct Anon2052879266 x22460 = x22458.aggs;;
      struct Anon152692660 x22461;
      x22461.exists = false;
      x22461.key = x22459;
      x22461.aggs = x22460;
      x22457[x22456] = x22461;
    }
    long x22467 = x22466;
    long x22468 = 0L;
    int* x22471 = (int*)malloc(x22466 * sizeof(int));
    int* x22472 = x22471;
    double* x22473 = (double*)malloc(x22466 * sizeof(double));
    double* x22474 = x22473;
    struct Anon1042493154* x22478 = (struct Anon1042493154*)malloc(x808 * sizeof(struct Anon1042493154));
    struct Anon1042493154* x22479 = x22478;
    long x22480 = 0L;
    long* x22481 = (long*)malloc(x808 * sizeof(long));
    long x22482;
    for(x22482=0L; x22482 < x808; x22482++) {
      struct Anon1042493154* x22483 = x22479;
      struct Anon1042493154 x22484 = x22483[x22482];
      char* x22485 = x22484.key;;
      struct Anon2052879266 x22486 = x22484.aggs;;
      struct Anon1042493154 x22487;
      x22487.exists = false;
      x22487.key = x22485;
      x22487.aggs = x22486;
      x22483[x22482] = x22487;
    }
    double x22494 = 0.0;
    long x22498 = 1024L;
    long x22499 = 0L;
    struct Anon2053173900* x22500 = (struct Anon2053173900*)malloc(1024L * sizeof(struct Anon2053173900));
    struct Anon2053173900* x22501 = x22500;
    long x22503 = 0L;
    struct timeval x22947, x22948, x22949;
    gettimeofday(&x22947, NULL);
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x22505 = x22398;
      bool x22506 = !x22505;
      bool x22511 = x22506;
      if (x22506) {
        long x22507 = x22399;
        long x22508 = x22247;
        bool x22509 = x22507 < x22508;
        x22511 = x22509;
      }
      bool x22512 = x22511;
      if (!x22512) break;
      long x22514 = x22399;
      int* x22515 = x22249;
      int x22516 = x22515[x22514];
      char** x22517 = x22251;
      char* x22518 = x22517[x22514];
      x22399 = x22399 + 1;
      bool x22525 = tpch_strcmp(x22518,"GERMANY") == 0;;
      if (x22525) {
        long x22526 = x22410;
        int* x22527 = x22403;
        x22527[x22526] = x22516;
        x22410 = x22410 + 1L;
        long x22536 = x22516 & x2212;
        long x22537 = x22411[x22536];
        x22411[x22536] = x22526;
        x22412[x22526] = x22537;
      } else {
      }
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x22545 = x22396;
      bool x22546 = !x22545;
      bool x22551 = x22546;
      if (x22546) {
        long x22547 = x22397;
        long x22548 = x21975;
        bool x22549 = x22547 < x22548;
        x22551 = x22549;
      }
      bool x22552 = x22551;
      if (!x22552) break;
      long x22554 = x22397;
      int* x22555 = x21977;
      int x22556 = x22555[x22554];
      int* x22561 = x21983;
      int x22562 = x22561[x22554];
      x22397 = x22397 + 1;
      long x22571 = x22562 & x2212;
      long x22572 = x22411[x22571];
      long x22573 = x22572;
      long x22617 = x22556 & x2212;
      for (;;) {
        long x22574 = x22573;
        bool x22575 = x22574 != -1;
        if (!x22575) break;
        long x22577 = x22573;
        int* x22578 = x22403;
        int x22579 = x22578[x22577];
        long x22587 = x22412[x22577];
        x22573 = x22587;
        bool x22589 = x22579 == x22562;
        if (x22589) {
          long x22593 = x22443;
          int* x22602 = x22430;
          x22602[x22593] = x22556;
          x22443 = x22443 + 1L;
          long x22618 = x22444[x22617];
          x22444[x22617] = x22593;
          x22445[x22593] = x22618;
        } else {
        }
      }
    }
    printf("%s\n","begin scan PARTSUPP");
    for (;;) {
      bool x22628 = x22418;
      bool x22629 = !x22628;
      bool x22634 = x22629;
      if (x22629) {
        long x22630 = x22419;
        long x22631 = x21747;
        bool x22632 = x22630 < x22631;
        x22634 = x22632;
      }
      bool x22635 = x22634;
      if (!x22635) break;
      long x22637 = x22419;
      int* x22638 = x21749;
      int x22639 = x22638[x22637];
      int* x22640 = x21751;
      int x22641 = x22640[x22637];
      int* x22642 = x21753;
      int x22643 = x22642[x22637];
      double* x22644 = x21755;
      double x22645 = x22644[x22637];
      x22419 = x22419 + 1;
      long x22650 = x22641 & x2212;
      long x22651 = x22444[x22650];
      long x22652 = x22651;
      long x22686 = x22639 & x823;
      double x22700 = x22645 * x22643;
      struct Anon2052879266 x22733;
      x22733._0 = x22700;
      struct Anon152692660 x22734;
      x22734.exists = true;
      x22734.key = x22639;
      x22734.aggs = x22733;
      for (;;) {
        long x22653 = x22652;
        bool x22654 = x22653 != -1;
        if (!x22654) break;
        long x22656 = x22652;
        int* x22665 = x22430;
        int x22666 = x22665[x22656];
        long x22680 = x22445[x22656];
        x22652 = x22680;
        bool x22682 = x22666 == x22641;
        if (x22682) {
          long x22687 = x22686;
          struct Anon152692660* x22688 = x22453;
          struct Anon152692660 x22689 = x22688[x22686];
          struct Anon152692660 x22690 = x22689;
          bool x22691 = x22689.exists;;
          bool x22696 = x22691;
          if (x22691) {
            struct Anon152692660 x22692 = x22690;
            int x22693 = x22692.key;;
            bool x22694 = x22693 == x22639;
            x22696 = x22694;
          }
          bool x22697 = x22696;
          if (x22697) {
            struct Anon2052879266 x22698 = x22689.aggs;;
            int x22703 = x22689.key;;
            double x22699 = x22698._0;;
            double x22701 = x22699 + x22700;
            struct Anon2052879266 x22702;
            x22702._0 = x22701;
            struct Anon152692660 x22704;
            x22704.exists = true;
            x22704.key = x22703;
            x22704.aggs = x22702;
            x22688[x22686] = x22704;
          } else {
            for (;;) {
              struct Anon152692660 x22707 = x22690;
              bool x22708 = x22707.exists;;
              bool x22743;
              if (x22708) {
                int x22709 = x22707.key;;
                bool x22710 = x22709 == x22639;
                bool x22730;
                if (x22710) {
                  struct Anon2052879266 x22711 = x22707.aggs;;
                  long x22715 = x22687;
                  struct Anon152692660* x22717 = x22453;
                  double x22712 = x22711._0;;
                  double x22713 = x22712 + x22700;
                  struct Anon2052879266 x22714;
                  x22714._0 = x22713;
                  struct Anon152692660 x22716;
                  x22716.exists = true;
                  x22716.key = x22709;
                  x22716.aggs = x22714;
                  x22717[x22715] = x22716;
                  x22730 = false;
                } else {
                  long x22720 = x22687;
                  long x22721 = x22720 + 1L;
                  long x22722 = x22721 & x823;
                  x22687 = x22722;
                  struct Anon152692660* x22724 = x22453;
                  struct Anon152692660 x22725 = x22724[x22722];
                  x22690 = x22725;
                  x22730 = true;
                }
                x22743 = x22730;
              } else {
                long x22732 = x22687;
                struct Anon152692660* x22735 = x22453;
                x22735[x22732] = x22734;
                long x22737 = x22454;
                x22455[x22737] = x22732;
                x22454 = x22454 + 1L;
                x22743 = false;
              }
              if (!x22743) break;
            }
          }
        } else {
        }
      }
    }
    long x22756 = x22454;
    long x22758;
    for(x22758=0L; x22758 < x22756; x22758++) {
      long x22759 = x22455[x22758];
      struct Anon152692660* x22760 = x22453;
      struct Anon152692660 x22761 = x22760[x22759];
      long x22762 = x22468;
      long x22763 = x22467;
      bool x22764 = x22762 == x22763;
      if (x22764) {
        long x22765 = x22763 * 4L;
        x22467 = x22765;
        printf("buffer.resize %ld\n",x22765);
        int* x22771 = x22472;
        int* x22772 = (int*)realloc(x22771,x22765 * sizeof(int));
        x22472 = x22772;
        printf("buffer.resize %ld\n",x22765);
        double* x22775 = x22474;
        double* x22776 = (double*)realloc(x22775,x22765 * sizeof(double));
        x22474 = x22776;
      } else {
      }
      int x22783 = x22761.key;;
      int* x22784 = x22472;
      x22784[x22762] = x22783;
      struct Anon2052879266 x22786 = x22761.aggs;;
      double* x22788 = x22474;
      double x22787 = x22786._0;;
      x22788[x22762] = x22787;
      x22468 = x22468 + 1;
    }
    long x22793 = x22468;
    long x22795;
    for(x22795=0L; x22795 < x22793; x22795++) {
      double* x22800 = x22474;
      double x22801 = x22800[x22795];
      long x22804 = hash("Total", 10L);
      long x22805 = x22804 & x823;
      long x22806 = x22805;
      struct Anon1042493154* x22807 = x22479;
      struct Anon1042493154 x22808 = x22807[x22805];
      struct Anon1042493154 x22809 = x22808;
      bool x22810 = x22808.exists;;
      bool x22815 = x22810;
      if (x22810) {
        struct Anon1042493154 x22811 = x22809;
        char* x22812 = x22811.key;;
        bool x22813 = tpch_strcmp(x22812,"Total") == 0;;
        x22815 = x22813;
      }
      bool x22816 = x22815;
      if (x22816) {
        struct Anon2052879266 x22817 = x22808.aggs;;
        char* x22821 = x22808.key;;
        double x22818 = x22817._0;;
        double x22819 = x22818 + x22801;
        struct Anon2052879266 x22820;
        x22820._0 = x22819;
        struct Anon1042493154 x22822;
        x22822.exists = true;
        x22822.key = x22821;
        x22822.aggs = x22820;
        x22807[x22805] = x22822;
      } else {
        struct Anon2052879266 x22802;
        x22802._0 = x22801;
        struct Anon1042493154 x22851;
        x22851.exists = true;
        x22851.key = "Total";
        x22851.aggs = x22802;
        for (;;) {
          struct Anon1042493154 x22825 = x22809;
          bool x22826 = x22825.exists;;
          bool x22860;
          if (x22826) {
            char* x22827 = x22825.key;;
            bool x22828 = tpch_strcmp(x22827,"Total") == 0;;
            bool x22848;
            if (x22828) {
              struct Anon2052879266 x22829 = x22825.aggs;;
              long x22833 = x22806;
              struct Anon1042493154* x22835 = x22479;
              double x22830 = x22829._0;;
              double x22831 = x22830 + x22801;
              struct Anon2052879266 x22832;
              x22832._0 = x22831;
              struct Anon1042493154 x22834;
              x22834.exists = true;
              x22834.key = x22827;
              x22834.aggs = x22832;
              x22835[x22833] = x22834;
              x22848 = false;
            } else {
              long x22838 = x22806;
              long x22839 = x22838 + 1L;
              long x22840 = x22839 & x823;
              x22806 = x22840;
              struct Anon1042493154* x22842 = x22479;
              struct Anon1042493154 x22843 = x22842[x22840];
              x22809 = x22843;
              x22848 = true;
            }
            x22860 = x22848;
          } else {
            long x22850 = x22806;
            struct Anon1042493154* x22852 = x22479;
            x22852[x22850] = x22851;
            long x22854 = x22480;
            x22481[x22854] = x22850;
            x22480 = x22480 + 1L;
            x22860 = false;
          }
          if (!x22860) break;
        }
      }
    }
    long x22869 = x22480;
    long x22871;
    for(x22871=0L; x22871 < x22869; x22871++) {
      long x22872 = x22481[x22871];
      struct Anon1042493154* x22873 = x22479;
      struct Anon1042493154 x22874 = x22873[x22872];
      struct Anon2052879266 x22875 = x22874.aggs;;
      double x22876 = x22875._0;;
      double x22877 = x22876 * 1.0E-4;
      x22494 = x22877;
      long x22880 = x22468;
      long x22882;
      for(x22882=0L; x22882 < x22880; x22882++) {
        int* x22885 = x22472;
        int x22886 = x22885[x22882];
        double* x22887 = x22474;
        double x22888 = x22887[x22882];
        double x22891 = x22494;
        bool x22893 = x22888 > x22891;
        if (x22893) {
          long x22896 = x22499;
          long x22897 = x22498;
          bool x22898 = x22896 == x22897;
          if (x22898) {
            long x22899 = x22897 * 4L;
            x22498 = x22899;
            struct Anon2053173900* x22901 = x22501;
            struct Anon2053173900* x22902 = (struct Anon2053173900 *)realloc(x22901,x22899* sizeof(struct Anon2053173900));
            x22501 = x22902;
          } else {
          }
          struct Anon2053173900* x22906 = x22501;
          struct Anon2053173900 x22895;
          x22895.key = x22886;
          x22895.wnd = x22888;
          x22906[x22896] = x22895;
          x22499 = x22499 + 1;
        } else {
        }
      }
    }
    long x22915 = x22499;
    struct Anon2053173900* x22916 = x22501;
    qsort((void *)x22916,x22915,sizeof(struct Anon2053173900), (__compar_fn_t)x22928); // x22929
    long x22931;
    for(x22931=0L; x22931 < x22915; x22931++) {
      struct Anon2053173900* x22932 = x22501;
      struct Anon2053173900 x22933 = x22932[x22931];
      if (x1043) {
      } else {
        int x22936 = x22933.key;;
        double x22937 = x22933.wnd;;
        printf("%d|%.2f\n",x22936,x22937);
        x22503 = x22503 + 1L;
      }
    }
    long x22944 = x22503;
    printf("(%ld rows)\n",x22944);
    gettimeofday(&x22948, NULL);
    timeval_subtract(&x22949, &x22948, &x22947);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x22949.tv_sec * 1000) + (x22949.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
