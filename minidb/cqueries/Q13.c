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

struct Anon793459755 {
bool exists;
char* key;
struct Anon189208763 aggs;
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
struct Anon920667905 left;
struct Anon811555534 right;
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

struct Anon152692660 {
bool exists;
int key;
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

struct Anon1900109934 {
bool exists;
double key;
struct Anon2052879266 aggs;
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
int x25615(struct Anon1900109934* x25596, struct Anon1900109934* x25597);
int x25615(struct Anon1900109934* x25596, struct Anon1900109934* x25597) {
  struct Anon1900109934 x25598 = (*x25596);
  struct Anon1900109934 x25599 = (*x25597);
  struct Anon2052879266 x25600 = x25598.aggs;;
  double x25601 = x25600._0;;
  struct Anon2052879266 x25602 = x25599.aggs;;
  double x25603 = x25602._0;;
  bool x25604 = x25601 < x25603;
  int x25613;
  if (x25604) {
    x25613 = 1;
  } else {
    bool x25605 = x25601 > x25603;
    int x25612;
    if (x25605) {
      x25612 = -1;
    } else {
      double x25606 = x25598.key;;
      double x25607 = x25599.key;;
      bool x25608 = x25606 < x25607;
      int x25611;
      if (x25608) {
        x25611 = 1;
      } else {
        bool x25609 = x25606 > x25607;
        int x25610;
        if (x25609) {
          x25610 = -1;
        } else {
          x25610 = 0;
        }
        x25611 = x25610;
      }
      x25612 = x25611;
    }
    x25613 = x25612;
  }
  return x25613;
}

/************************ MAIN BODY **************************/
int main(int x24485, char** x24486) {
  long x24487 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x24488 = x7;
  long x24489 = 0L;
  int* x24490 = (int*)malloc(x7 * sizeof(int));
  int* x24491 = x24490;
  int x4007 = open("XXXXXcustomer.tbl",0);
  long x4008 = fsize(x4007);
  char* x4009 = mmap(0, x4008, PROT_READ, MAP_FILE | MAP_SHARED, x4007, 0);
  for (;;) {
    long x24506 = x24487;
    bool x24507 = x24506 < x4008;
    if (!x24507) break;
    int x24510 = 0;
    for (;;) {
      long x24511 = x24487;
      char x24512 = x4009[x24511];
      bool x24513 = x24512 != '|';
      bool x24518 = x24513;
      if (x24513) {
        long x24514 = x24487;
        char x24515 = x4009[x24514];
        bool x24516 = x24515 != '\n';
        x24518 = x24516;
      }
      bool x24519 = x24518;
      if (!x24519) break;
      int x24521 = x24510;
      long x24523 = x24487;
      int x24522 = x24521 * 10;
      char x24524 = x4009[x24523];
      char x24525 = x24524 - '0';
      int x24526 = x24522 + x24525;
      x24510 = x24526;
      x24487 = x24487 + 1;
    }
    x24487 = x24487 + 1;
    int x24532 = x24510;
    for (;;) {
      long x24534 = x24487;
      char x24535 = x4009[x24534];
      bool x24536 = x24535 != '|';
      bool x24541 = x24536;
      if (x24536) {
        long x24537 = x24487;
        char x24538 = x4009[x24537];
        bool x24539 = x24538 != '\n';
        x24541 = x24539;
      }
      bool x24542 = x24541;
      if (!x24542) break;
      x24487 = x24487 + 1;
    }
    x24487 = x24487 + 1;
    for (;;) {
      long x24552 = x24487;
      char x24553 = x4009[x24552];
      bool x24554 = x24553 != '|';
      bool x24559 = x24554;
      if (x24554) {
        long x24555 = x24487;
        char x24556 = x4009[x24555];
        bool x24557 = x24556 != '\n';
        x24559 = x24557;
      }
      bool x24560 = x24559;
      if (!x24560) break;
      x24487 = x24487 + 1;
    }
    x24487 = x24487 + 1;
    for (;;) {
      long x24571 = x24487;
      char x24572 = x4009[x24571];
      bool x24573 = x24572 != '|';
      bool x24578 = x24573;
      if (x24573) {
        long x24574 = x24487;
        char x24575 = x4009[x24574];
        bool x24576 = x24575 != '\n';
        x24578 = x24576;
      }
      bool x24579 = x24578;
      if (!x24579) break;
      x24487 = x24487 + 1;
    }
    x24487 = x24487 + 1;
    for (;;) {
      long x24594 = x24487;
      char x24595 = x4009[x24594];
      bool x24596 = x24595 != '|';
      bool x24601 = x24596;
      if (x24596) {
        long x24597 = x24487;
        char x24598 = x4009[x24597];
        bool x24599 = x24598 != '\n';
        x24601 = x24599;
      }
      bool x24602 = x24601;
      if (!x24602) break;
      x24487 = x24487 + 1;
    }
    x24487 = x24487 + 1;
    for (;;) {
      long x24614 = x24487;
      char x24615 = x4009[x24614];
      bool x24616 = x24615 != '.';
      bool x24621 = x24616;
      if (x24616) {
        long x24617 = x24487;
        char x24618 = x4009[x24617];
        bool x24619 = x24618 != '|';
        x24621 = x24619;
      }
      bool x24622 = x24621;
      bool x24627 = x24622;
      if (x24622) {
        long x24623 = x24487;
        char x24624 = x4009[x24623];
        bool x24625 = x24624 != '\n';
        x24627 = x24625;
      }
      bool x24628 = x24627;
      if (!x24628) break;
      x24487 = x24487 + 1;
    }
    long x24640 = x24487;
    char x24641 = x4009[x24640];
    bool x24642 = x24641 == '.';
    if (x24642) {
      x24487 = x24487 + 1;
      for (;;) {
        long x24644 = x24487;
        char x24645 = x4009[x24644];
        bool x24646 = x24645 != '|';
        bool x24651 = x24646;
        if (x24646) {
          long x24647 = x24487;
          char x24648 = x4009[x24647];
          bool x24649 = x24648 != '\n';
          x24651 = x24649;
        }
        bool x24652 = x24651;
        if (!x24652) break;
        x24487 = x24487 + 1;
      }
    } else {
    }
    x24487 = x24487 + 1;
    for (;;) {
      long x24677 = x24487;
      char x24678 = x4009[x24677];
      bool x24679 = x24678 != '|';
      bool x24684 = x24679;
      if (x24679) {
        long x24680 = x24487;
        char x24681 = x4009[x24680];
        bool x24682 = x24681 != '\n';
        x24684 = x24682;
      }
      bool x24685 = x24684;
      if (!x24685) break;
      x24487 = x24487 + 1;
    }
    x24487 = x24487 + 1;
    for (;;) {
      long x24695 = x24487;
      char x24696 = x4009[x24695];
      bool x24697 = x24696 != '|';
      bool x24702 = x24697;
      if (x24697) {
        long x24698 = x24487;
        char x24699 = x4009[x24698];
        bool x24700 = x24699 != '\n';
        x24702 = x24700;
      }
      bool x24703 = x24702;
      if (!x24703) break;
      x24487 = x24487 + 1;
    }
    x24487 = x24487 + 1;
    long x24713 = x24487;
    bool x24714 = x24713 > 0L;
    bool x24720 = x24714;
    if (x24714) {
      long x24715 = x24487;
      long x24716 = x24715 - 1L;
      char x24717 = x4009[x24716];
      bool x24718 = x24717 != '\n';
      x24720 = x24718;
    }
    bool x24721 = x24720;
    if (x24721) {
      for (;;) {
        long x24722 = x24487;
        char x24723 = x4009[x24722];
        bool x24724 = x24723 != '\n';
        if (!x24724) break;
        x24487 = x24487 + 1;
      }
    } else {
    }
    x24487 = x24487 + 1;
    long x24733 = x24489;
    long x24734 = x24488;
    bool x24735 = x24733 == x24734;
    if (x24735) {
      long x24736 = x24734 * 4L;
      x24488 = x24736;
      printf("buffer.resize %ld\n",x24736);
      int* x24739 = x24491;
      int* x24740 = (int*)realloc(x24739,x24736 * sizeof(int));
      x24491 = x24740;
    } else {
    }
    int* x24765 = x24491;
    x24765[x24733] = x24532;
    x24489 = x24489 + 1;
  }
  long x24784 = 0L;
  long x24785 = x7;
  long x24786 = 0L;
  int* x24787 = (int*)malloc(x7 * sizeof(int));
  int* x24788 = x24787;
  int* x24789 = (int*)malloc(x7 * sizeof(int));
  int* x24790 = x24789;
  char** x24803 = (char**)malloc(x7 * sizeof(char*));
  char** x24804 = x24803;
  int x3633 = open("XXXXXorders.tbl",0);
  long x3634 = fsize(x3633);
  char* x3635 = mmap(0, x3634, PROT_READ, MAP_FILE | MAP_SHARED, x3633, 0);
  for (;;) {
    long x24805 = x24784;
    bool x24806 = x24805 < x3634;
    if (!x24806) break;
    int x24809 = 0;
    for (;;) {
      long x24810 = x24784;
      char x24811 = x3635[x24810];
      bool x24812 = x24811 != '|';
      bool x24817 = x24812;
      if (x24812) {
        long x24813 = x24784;
        char x24814 = x3635[x24813];
        bool x24815 = x24814 != '\n';
        x24817 = x24815;
      }
      bool x24818 = x24817;
      if (!x24818) break;
      int x24820 = x24809;
      long x24822 = x24784;
      int x24821 = x24820 * 10;
      char x24823 = x3635[x24822];
      char x24824 = x24823 - '0';
      int x24825 = x24821 + x24824;
      x24809 = x24825;
      x24784 = x24784 + 1;
    }
    x24784 = x24784 + 1;
    int x24831 = x24809;
    int x24833 = 0;
    for (;;) {
      long x24834 = x24784;
      char x24835 = x3635[x24834];
      bool x24836 = x24835 != '|';
      bool x24841 = x24836;
      if (x24836) {
        long x24837 = x24784;
        char x24838 = x3635[x24837];
        bool x24839 = x24838 != '\n';
        x24841 = x24839;
      }
      bool x24842 = x24841;
      if (!x24842) break;
      int x24844 = x24833;
      long x24846 = x24784;
      int x24845 = x24844 * 10;
      char x24847 = x3635[x24846];
      char x24848 = x24847 - '0';
      int x24849 = x24845 + x24848;
      x24833 = x24849;
      x24784 = x24784 + 1;
    }
    x24784 = x24784 + 1;
    int x24855 = x24833;
    x24784 = x24784 + 2;
    for (;;) {
      long x24862 = x24784;
      char x24863 = x3635[x24862];
      bool x24864 = x24863 != '.';
      bool x24869 = x24864;
      if (x24864) {
        long x24865 = x24784;
        char x24866 = x3635[x24865];
        bool x24867 = x24866 != '|';
        x24869 = x24867;
      }
      bool x24870 = x24869;
      bool x24875 = x24870;
      if (x24870) {
        long x24871 = x24784;
        char x24872 = x3635[x24871];
        bool x24873 = x24872 != '\n';
        x24875 = x24873;
      }
      bool x24876 = x24875;
      if (!x24876) break;
      x24784 = x24784 + 1;
    }
    long x24888 = x24784;
    char x24889 = x3635[x24888];
    bool x24890 = x24889 == '.';
    if (x24890) {
      x24784 = x24784 + 1;
      for (;;) {
        long x24892 = x24784;
        char x24893 = x3635[x24892];
        bool x24894 = x24893 != '|';
        bool x24899 = x24894;
        if (x24894) {
          long x24895 = x24784;
          char x24896 = x3635[x24895];
          bool x24897 = x24896 != '\n';
          x24899 = x24897;
        }
        bool x24900 = x24899;
        if (!x24900) break;
        x24784 = x24784 + 1;
      }
    } else {
    }
    x24784 = x24784 + 1;
    for (;;) {
      long x24926 = x24784;
      char x24927 = x3635[x24926];
      bool x24928 = x24927 != '-';
      bool x24933 = x24928;
      if (x24928) {
        long x24929 = x24784;
        char x24930 = x3635[x24929];
        bool x24931 = x24930 != '\n';
        x24933 = x24931;
      }
      bool x24934 = x24933;
      if (!x24934) break;
      x24784 = x24784 + 1;
    }
    x24784 = x24784 + 1;
    for (;;) {
      long x24950 = x24784;
      char x24951 = x3635[x24950];
      bool x24952 = x24951 != '-';
      bool x24957 = x24952;
      if (x24952) {
        long x24953 = x24784;
        char x24954 = x3635[x24953];
        bool x24955 = x24954 != '\n';
        x24957 = x24955;
      }
      bool x24958 = x24957;
      if (!x24958) break;
      x24784 = x24784 + 1;
    }
    x24784 = x24784 + 1;
    for (;;) {
      long x24974 = x24784;
      char x24975 = x3635[x24974];
      bool x24976 = x24975 != '|';
      bool x24981 = x24976;
      if (x24976) {
        long x24977 = x24784;
        char x24978 = x3635[x24977];
        bool x24979 = x24978 != '\n';
        x24981 = x24979;
      }
      bool x24982 = x24981;
      if (!x24982) break;
      x24784 = x24784 + 1;
    }
    x24784 = x24784 + 1;
    for (;;) {
      long x25001 = x24784;
      char x25002 = x3635[x25001];
      bool x25003 = x25002 != '|';
      bool x25008 = x25003;
      if (x25003) {
        long x25004 = x24784;
        char x25005 = x3635[x25004];
        bool x25006 = x25005 != '\n';
        x25008 = x25006;
      }
      bool x25009 = x25008;
      if (!x25009) break;
      x24784 = x24784 + 1;
    }
    x24784 = x24784 + 1;
    for (;;) {
      long x25019 = x24784;
      char x25020 = x3635[x25019];
      bool x25021 = x25020 != '|';
      bool x25026 = x25021;
      if (x25021) {
        long x25022 = x24784;
        char x25023 = x3635[x25022];
        bool x25024 = x25023 != '\n';
        x25026 = x25024;
      }
      bool x25027 = x25026;
      if (!x25027) break;
      x24784 = x24784 + 1;
    }
    x24784 = x24784 + 1;
    for (;;) {
      long x25038 = x24784;
      char x25039 = x3635[x25038];
      bool x25040 = x25039 != '|';
      bool x25045 = x25040;
      if (x25040) {
        long x25041 = x24784;
        char x25042 = x3635[x25041];
        bool x25043 = x25042 != '\n';
        x25045 = x25043;
      }
      bool x25046 = x25045;
      if (!x25046) break;
      x24784 = x24784 + 1;
    }
    x24784 = x24784 + 1;
    long x25060 = x24784;
    for (;;) {
      long x25061 = x24784;
      char x25062 = x3635[x25061];
      bool x25063 = x25062 != '|';
      bool x25068 = x25063;
      if (x25063) {
        long x25064 = x24784;
        char x25065 = x3635[x25064];
        bool x25066 = x25065 != '\n';
        x25068 = x25066;
      }
      bool x25069 = x25068;
      if (!x25069) break;
      x24784 = x24784 + 1;
    }
    x24784 = x24784 + 1;
    long x25079 = x24784;
    bool x25080 = x25079 > 0L;
    bool x25086 = x25080;
    if (x25080) {
      long x25081 = x24784;
      long x25082 = x25081 - 1L;
      char x25083 = x3635[x25082];
      bool x25084 = x25083 != '\n';
      x25086 = x25084;
    }
    bool x25087 = x25086;
    if (x25087) {
      for (;;) {
        long x25088 = x24784;
        char x25089 = x3635[x25088];
        bool x25090 = x25089 != '\n';
        if (!x25090) break;
        x24784 = x24784 + 1;
      }
    } else {
    }
    x24784 = x24784 + 1;
    long x25099 = x24786;
    long x25100 = x24785;
    bool x25101 = x25099 == x25100;
    if (x25101) {
      long x25102 = x25100 * 4L;
      x24785 = x25102;
      printf("buffer.resize %ld\n",x25102);
      int* x25105 = x24788;
      int* x25106 = (int*)realloc(x25105,x25102 * sizeof(int));
      x24788 = x25106;
      int* x25108 = x24790;
      int* x25109 = (int*)realloc(x25108,x25102 * sizeof(int));
      x24790 = x25109;
      char** x25129 = x24804;
      char** x25130 = (char**)realloc(x25129,x25102 * sizeof(char*));
      x24804 = x25130;
    } else {
    }
    int* x25134 = x24788;
    x25134[x25099] = x24831;
    int* x25136 = x24790;
    x25136[x25099] = x24855;
    char** x25150 = x24804;
    char* x25077 = x3635+x25060;
    x25150[x25099] = x25077;
    x24786 = x24786 + 1;
  }
  long x2189 = DEFAULT_JOIN_HASH_SIZE;
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  long x2212 = x2189 - 1L;
  long x823 = x808 - 1L;
  bool x25442 = 0 == 0.0;
  double x25478;
  if (x25442) {
    x25478 = 0.0;
  } else {
    x25478 = 1.0;
  }
  struct Anon2052879266 x25479;
  x25479._0 = x25478;
  struct Anon2052879266 x6304;
  x6304._0 = 1.0;
  bool x1043 = true == false;
  int x25155;
  for(x25155=0; x25155 < 5; x25155++) {
    bool x25156 = false;
    long x25157 = 0L;
    bool x25158 = false;
    long x25159 = 0L;
    int* x25162 = (int*)malloc(x2189 * sizeof(int));
    int* x25163 = x25162;
    int* x25164 = (int*)malloc(x2189 * sizeof(int));
    int* x25165 = x25164;
    long x25180 = 0L;
    long* x25181 = (long*)malloc(x2189 * sizeof(long));
    long* x25182 = (long*)malloc(x2189 * sizeof(long));
    long x25183;
    for(x25183=0L; x25183 < x2189; x25183++) {
      x25181[x25183] = -1L;
    }
    struct Anon152692660* x25190 = (struct Anon152692660*)malloc(x808 * sizeof(struct Anon152692660));
    struct Anon152692660* x25191 = x25190;
    long x25192 = 0L;
    long* x25193 = (long*)malloc(x808 * sizeof(long));
    long x25194;
    for(x25194=0L; x25194 < x808; x25194++) {
      struct Anon152692660* x25195 = x25191;
      struct Anon152692660 x25196 = x25195[x25194];
      int x25197 = x25196.key;;
      struct Anon2052879266 x25198 = x25196.aggs;;
      struct Anon152692660 x25199;
      x25199.exists = false;
      x25199.key = x25197;
      x25199.aggs = x25198;
      x25195[x25194] = x25199;
    }
    struct Anon1900109934* x25204 = (struct Anon1900109934*)malloc(x808 * sizeof(struct Anon1900109934));
    struct Anon1900109934* x25205 = x25204;
    long x25206 = 0L;
    long* x25207 = (long*)malloc(x808 * sizeof(long));
    long x25208;
    for(x25208=0L; x25208 < x808; x25208++) {
      struct Anon1900109934* x25209 = x25205;
      struct Anon1900109934 x25210 = x25209[x25208];
      double x25211 = x25210.key;;
      struct Anon2052879266 x25212 = x25210.aggs;;
      struct Anon1900109934 x25213;
      x25213.exists = false;
      x25213.key = x25211;
      x25213.aggs = x25212;
      x25209[x25208] = x25213;
    }
    long x25218 = 1024L;
    long x25219 = 0L;
    struct Anon1900109934* x25220 = (struct Anon1900109934*)malloc(1024L * sizeof(struct Anon1900109934));
    struct Anon1900109934* x25221 = x25220;
    long x25223 = 0L;
    struct timeval x25635, x25636, x25637;
    gettimeofday(&x25635, NULL);
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x25225 = x25158;
      bool x25226 = !x25225;
      bool x25231 = x25226;
      if (x25226) {
        long x25227 = x25159;
        long x25228 = x24786;
        bool x25229 = x25227 < x25228;
        x25231 = x25229;
      }
      bool x25232 = x25231;
      if (!x25232) break;
      long x25234 = x25159;
      int* x25235 = x24788;
      int x25236 = x25235[x25234];
      int* x25237 = x24790;
      int x25238 = x25237[x25234];
      char** x25251 = x24804;
      char* x25252 = x25251[x25234];
      x25159 = x25159 + 1;
      int x25255 = tpch_strstr(&(x25252[0]),"special") - x25252;
      if (x25255 < 0) x25255 = -1;
      bool x25256 = x25255 >= 0;
      bool x25260;
      if (x25256) {
        int x25257 = x25255 + 7;
        int x25258 = tpch_strstr(&(x25252[x25257]),"requests") - x25252;
        if (x25258 < 0) x25258 = -1;
        bool x25259 = x25258 == -1;
        x25260 = x25259;
      } else {
        x25260 = true;
      }
      if (x25260) {
        long x25261 = x25180;
        int* x25262 = x25163;
        x25262[x25261] = x25236;
        int* x25264 = x25165;
        x25264[x25261] = x25238;
        x25180 = x25180 + 1L;
        long x25281 = x25238 & x2212;
        long x25282 = x25181[x25281];
        x25181[x25281] = x25261;
        x25182[x25261] = x25282;
      } else {
      }
    }
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x25290 = x25156;
      bool x25291 = !x25290;
      bool x25296 = x25291;
      if (x25291) {
        long x25292 = x25157;
        long x25293 = x24489;
        bool x25294 = x25292 < x25293;
        x25296 = x25294;
      }
      bool x25297 = x25296;
      if (!x25297) break;
      long x25299 = x25157;
      int* x25300 = x24491;
      int x25301 = x25300[x25299];
      x25157 = x25157 + 1;
      bool x25318 = false;
      long x25319 = x25301 & x2212;
      long x25320 = x25181[x25319];
      long x25321 = x25320;
      long x25352 = x25301 & x823;
      for (;;) {
        long x25322 = x25321;
        bool x25323 = x25322 != -1;
        if (!x25323) break;
        long x25325 = x25321;
        int* x25326 = x25163;
        int x25327 = x25326[x25325];
        int* x25328 = x25165;
        int x25329 = x25328[x25325];
        long x25345 = x25182[x25325];
        x25321 = x25345;
        bool x25347 = x25301 == x25329;
        if (x25347) {
          x25318 = true;
          long x25353 = x25352;
          struct Anon152692660* x25354 = x25191;
          struct Anon152692660 x25355 = x25354[x25352];
          struct Anon152692660 x25356 = x25355;
          bool x25357 = x25355.exists;;
          bool x25362 = x25357;
          if (x25357) {
            struct Anon152692660 x25358 = x25356;
            int x25359 = x25358.key;;
            bool x25360 = x25359 == x25301;
            x25362 = x25360;
          }
          bool x25363 = x25362;
          if (x25363) {
            struct Anon2052879266 x25364 = x25355.aggs;;
            int x25371 = x25355.key;;
            bool x25366 = x25327 == 0.0;
            double x25369;
            if (x25366) {
              double x25367 = x25364._0;;
              x25369 = x25367;
            } else {
              double x25367 = x25364._0;;
              double x25368 = x25367 + 1.0;
              x25369 = x25368;
            }
            struct Anon2052879266 x25370;
            x25370._0 = x25369;
            struct Anon152692660 x25372;
            x25372.exists = true;
            x25372.key = x25371;
            x25372.aggs = x25370;
            x25354[x25352] = x25372;
          } else {
            bool x25366 = x25327 == 0.0;
            double x25402;
            if (x25366) {
              x25402 = 0.0;
            } else {
              x25402 = 1.0;
            }
            struct Anon2052879266 x25403;
            x25403._0 = x25402;
            struct Anon152692660 x25404;
            x25404.exists = true;
            x25404.key = x25301;
            x25404.aggs = x25403;
            for (;;) {
              struct Anon152692660 x25375 = x25356;
              bool x25376 = x25375.exists;;
              bool x25413;
              if (x25376) {
                int x25377 = x25375.key;;
                bool x25378 = x25377 == x25301;
                bool x25399;
                if (x25378) {
                  struct Anon2052879266 x25379 = x25375.aggs;;
                  long x25384 = x25353;
                  struct Anon152692660* x25386 = x25191;
                  double x25382;
                  if (x25366) {
                    double x25380 = x25379._0;;
                    x25382 = x25380;
                  } else {
                    double x25380 = x25379._0;;
                    double x25381 = x25380 + 1.0;
                    x25382 = x25381;
                  }
                  struct Anon2052879266 x25383;
                  x25383._0 = x25382;
                  struct Anon152692660 x25385;
                  x25385.exists = true;
                  x25385.key = x25377;
                  x25385.aggs = x25383;
                  x25386[x25384] = x25385;
                  x25399 = false;
                } else {
                  long x25389 = x25353;
                  long x25390 = x25389 + 1L;
                  long x25391 = x25390 & x823;
                  x25353 = x25391;
                  struct Anon152692660* x25393 = x25191;
                  struct Anon152692660 x25394 = x25393[x25391];
                  x25356 = x25394;
                  x25399 = true;
                }
                x25413 = x25399;
              } else {
                long x25401 = x25353;
                struct Anon152692660* x25405 = x25191;
                x25405[x25401] = x25404;
                long x25407 = x25192;
                x25193[x25407] = x25401;
                x25192 = x25192 + 1L;
                x25413 = false;
              }
              if (!x25413) break;
            }
          }
        } else {
        }
      }
      bool x25424 = x25318;
      if (x25424) {
      } else {
        long x25429 = x25352;
        struct Anon152692660* x25430 = x25191;
        struct Anon152692660 x25431 = x25430[x25352];
        struct Anon152692660 x25432 = x25431;
        bool x25433 = x25431.exists;;
        bool x25438 = x25433;
        if (x25433) {
          struct Anon152692660 x25434 = x25432;
          int x25435 = x25434.key;;
          bool x25436 = x25435 == x25301;
          x25438 = x25436;
        }
        bool x25439 = x25438;
        if (x25439) {
          struct Anon2052879266 x25440 = x25431.aggs;;
          int x25447 = x25431.key;;
          double x25445;
          if (x25442) {
            double x25443 = x25440._0;;
            x25445 = x25443;
          } else {
            double x25443 = x25440._0;;
            double x25444 = x25443 + 1.0;
            x25445 = x25444;
          }
          struct Anon2052879266 x25446;
          x25446._0 = x25445;
          struct Anon152692660 x25448;
          x25448.exists = true;
          x25448.key = x25447;
          x25448.aggs = x25446;
          x25430[x25352] = x25448;
        } else {
          struct Anon152692660 x25480;
          x25480.exists = true;
          x25480.key = x25301;
          x25480.aggs = x25479;
          for (;;) {
            struct Anon152692660 x25451 = x25432;
            bool x25452 = x25451.exists;;
            bool x25489;
            if (x25452) {
              int x25453 = x25451.key;;
              bool x25454 = x25453 == x25301;
              bool x25475;
              if (x25454) {
                struct Anon2052879266 x25455 = x25451.aggs;;
                long x25460 = x25429;
                struct Anon152692660* x25462 = x25191;
                double x25458;
                if (x25442) {
                  double x25456 = x25455._0;;
                  x25458 = x25456;
                } else {
                  double x25456 = x25455._0;;
                  double x25457 = x25456 + 1.0;
                  x25458 = x25457;
                }
                struct Anon2052879266 x25459;
                x25459._0 = x25458;
                struct Anon152692660 x25461;
                x25461.exists = true;
                x25461.key = x25453;
                x25461.aggs = x25459;
                x25462[x25460] = x25461;
                x25475 = false;
              } else {
                long x25465 = x25429;
                long x25466 = x25465 + 1L;
                long x25467 = x25466 & x823;
                x25429 = x25467;
                struct Anon152692660* x25469 = x25191;
                struct Anon152692660 x25470 = x25469[x25467];
                x25432 = x25470;
                x25475 = true;
              }
              x25489 = x25475;
            } else {
              long x25477 = x25429;
              struct Anon152692660* x25481 = x25191;
              x25481[x25477] = x25480;
              long x25483 = x25192;
              x25193[x25483] = x25477;
              x25192 = x25192 + 1L;
              x25489 = false;
            }
            if (!x25489) break;
          }
        }
      }
    }
    long x25500 = x25192;
    long x25502;
    for(x25502=0L; x25502 < x25500; x25502++) {
      long x25503 = x25193[x25502];
      struct Anon152692660* x25504 = x25191;
      struct Anon152692660 x25505 = x25504[x25503];
      struct Anon2052879266 x25506 = x25505.aggs;;
      double x25507 = x25506._0;;
      long x25508 = (long) x25507;
      long x25509 = x25508 & x823;
      long x25510 = x25509;
      struct Anon1900109934* x25511 = x25205;
      struct Anon1900109934 x25512 = x25511[x25509];
      struct Anon1900109934 x25513 = x25512;
      bool x25514 = x25512.exists;;
      bool x25519 = x25514;
      if (x25514) {
        struct Anon1900109934 x25515 = x25513;
        double x25516 = x25515.key;;
        bool x25517 = x25516 == x25507;
        x25519 = x25517;
      }
      bool x25520 = x25519;
      if (x25520) {
        struct Anon2052879266 x25521 = x25512.aggs;;
        double x25525 = x25512.key;;
        double x25522 = x25521._0;;
        double x25523 = x25522 + 1.0;
        struct Anon2052879266 x25524;
        x25524._0 = x25523;
        struct Anon1900109934 x25526;
        x25526.exists = true;
        x25526.key = x25525;
        x25526.aggs = x25524;
        x25511[x25509] = x25526;
      } else {
        struct Anon1900109934 x25555;
        x25555.exists = true;
        x25555.key = x25507;
        x25555.aggs = x6304;
        for (;;) {
          struct Anon1900109934 x25529 = x25513;
          bool x25530 = x25529.exists;;
          bool x25564;
          if (x25530) {
            double x25531 = x25529.key;;
            bool x25532 = x25531 == x25507;
            bool x25552;
            if (x25532) {
              struct Anon2052879266 x25533 = x25529.aggs;;
              long x25537 = x25510;
              struct Anon1900109934* x25539 = x25205;
              double x25534 = x25533._0;;
              double x25535 = x25534 + 1.0;
              struct Anon2052879266 x25536;
              x25536._0 = x25535;
              struct Anon1900109934 x25538;
              x25538.exists = true;
              x25538.key = x25531;
              x25538.aggs = x25536;
              x25539[x25537] = x25538;
              x25552 = false;
            } else {
              long x25542 = x25510;
              long x25543 = x25542 + 1L;
              long x25544 = x25543 & x823;
              x25510 = x25544;
              struct Anon1900109934* x25546 = x25205;
              struct Anon1900109934 x25547 = x25546[x25544];
              x25513 = x25547;
              x25552 = true;
            }
            x25564 = x25552;
          } else {
            long x25554 = x25510;
            struct Anon1900109934* x25556 = x25205;
            x25556[x25554] = x25555;
            long x25558 = x25206;
            x25207[x25558] = x25554;
            x25206 = x25206 + 1L;
            x25564 = false;
          }
          if (!x25564) break;
        }
      }
    }
    long x25573 = x25206;
    long x25575;
    for(x25575=0L; x25575 < x25573; x25575++) {
      long x25576 = x25207[x25575];
      struct Anon1900109934* x25577 = x25205;
      struct Anon1900109934 x25578 = x25577[x25576];
      long x25579 = x25219;
      long x25580 = x25218;
      bool x25581 = x25579 == x25580;
      if (x25581) {
        long x25582 = x25580 * 4L;
        x25218 = x25582;
        struct Anon1900109934* x25584 = x25221;
        struct Anon1900109934* x25585 = (struct Anon1900109934 *)realloc(x25584,x25582* sizeof(struct Anon1900109934));
        x25221 = x25585;
      } else {
      }
      struct Anon1900109934* x25589 = x25221;
      x25589[x25579] = x25578;
      x25219 = x25219 + 1;
    }
    long x25594 = x25219;
    struct Anon1900109934* x25595 = x25221;
    qsort((void *)x25595,x25594,sizeof(struct Anon1900109934), (__compar_fn_t)x25615); // x25616
    long x25618;
    for(x25618=0L; x25618 < x25594; x25618++) {
      struct Anon1900109934* x25619 = x25221;
      struct Anon1900109934 x25620 = x25619[x25618];
      if (x1043) {
      } else {
        double x25623 = x25620.key;;
        struct Anon2052879266 x25624 = x25620.aggs;;
        double x25625 = x25624._0;;
        printf("%.0f|%.0f\n",x25623,x25625);
        x25223 = x25223 + 1L;
      }
    }
    long x25632 = x25223;
    printf("(%ld rows)\n",x25632);
    gettimeofday(&x25636, NULL);
    timeval_subtract(&x25637, &x25636, &x25635);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x25637.tv_sec * 1000) + (x25637.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
