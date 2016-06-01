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

/************************ MAIN BODY **************************/
int main(int x25642, char** x25643) {
  long x25644 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x25645 = x7;
  long x25646 = 0L;
  int* x25649 = (int*)malloc(x7 * sizeof(int));
  int* x25650 = x25649;
  double* x25657 = (double*)malloc(x7 * sizeof(double));
  double* x25658 = x25657;
  double* x25659 = (double*)malloc(x7 * sizeof(double));
  double* x25660 = x25659;
  long* x25667 = (long*)malloc(x7 * sizeof(long));
  long* x25668 = x25667;
  int x3 = open("XXXXXlineitem.tbl",0);
  long x4 = fsize(x3);
  char* x5 = mmap(0, x4, PROT_READ, MAP_FILE | MAP_SHARED, x3, 0);
  for (;;) {
    long x25679 = x25644;
    bool x25680 = x25679 < x4;
    if (!x25680) break;
    for (;;) {
      long x25684 = x25644;
      char x25685 = x5[x25684];
      bool x25686 = x25685 != '|';
      bool x25691 = x25686;
      if (x25686) {
        long x25687 = x25644;
        char x25688 = x5[x25687];
        bool x25689 = x25688 != '\n';
        x25691 = x25689;
      }
      bool x25692 = x25691;
      if (!x25692) break;
      x25644 = x25644 + 1;
    }
    x25644 = x25644 + 1;
    int x25707 = 0;
    for (;;) {
      long x25708 = x25644;
      char x25709 = x5[x25708];
      bool x25710 = x25709 != '|';
      bool x25715 = x25710;
      if (x25710) {
        long x25711 = x25644;
        char x25712 = x5[x25711];
        bool x25713 = x25712 != '\n';
        x25715 = x25713;
      }
      bool x25716 = x25715;
      if (!x25716) break;
      int x25718 = x25707;
      long x25720 = x25644;
      int x25719 = x25718 * 10;
      char x25721 = x5[x25720];
      char x25722 = x25721 - '0';
      int x25723 = x25719 + x25722;
      x25707 = x25723;
      x25644 = x25644 + 1;
    }
    x25644 = x25644 + 1;
    int x25729 = x25707;
    for (;;) {
      long x25732 = x25644;
      char x25733 = x5[x25732];
      bool x25734 = x25733 != '|';
      bool x25739 = x25734;
      if (x25734) {
        long x25735 = x25644;
        char x25736 = x5[x25735];
        bool x25737 = x25736 != '\n';
        x25739 = x25737;
      }
      bool x25740 = x25739;
      if (!x25740) break;
      x25644 = x25644 + 1;
    }
    x25644 = x25644 + 1;
    for (;;) {
      long x25756 = x25644;
      char x25757 = x5[x25756];
      bool x25758 = x25757 != '|';
      bool x25763 = x25758;
      if (x25758) {
        long x25759 = x25644;
        char x25760 = x5[x25759];
        bool x25761 = x25760 != '\n';
        x25763 = x25761;
      }
      bool x25764 = x25763;
      if (!x25764) break;
      x25644 = x25644 + 1;
    }
    x25644 = x25644 + 1;
    for (;;) {
      long x25781 = x25644;
      char x25782 = x5[x25781];
      bool x25783 = x25782 != '.';
      bool x25788 = x25783;
      if (x25783) {
        long x25784 = x25644;
        char x25785 = x5[x25784];
        bool x25786 = x25785 != '|';
        x25788 = x25786;
      }
      bool x25789 = x25788;
      bool x25794 = x25789;
      if (x25789) {
        long x25790 = x25644;
        char x25791 = x5[x25790];
        bool x25792 = x25791 != '\n';
        x25794 = x25792;
      }
      bool x25795 = x25794;
      if (!x25795) break;
      x25644 = x25644 + 1;
    }
    long x25807 = x25644;
    char x25808 = x5[x25807];
    bool x25809 = x25808 == '.';
    if (x25809) {
      x25644 = x25644 + 1;
      for (;;) {
        long x25811 = x25644;
        char x25812 = x5[x25811];
        bool x25813 = x25812 != '|';
        bool x25818 = x25813;
        if (x25813) {
          long x25814 = x25644;
          char x25815 = x5[x25814];
          bool x25816 = x25815 != '\n';
          x25818 = x25816;
        }
        bool x25819 = x25818;
        if (!x25819) break;
        x25644 = x25644 + 1;
      }
    } else {
    }
    x25644 = x25644 + 1;
    int x25844 = 0;
    int x25845 = 1;
    for (;;) {
      long x25846 = x25644;
      char x25847 = x5[x25846];
      bool x25848 = x25847 != '.';
      bool x25853 = x25848;
      if (x25848) {
        long x25849 = x25644;
        char x25850 = x5[x25849];
        bool x25851 = x25850 != '|';
        x25853 = x25851;
      }
      bool x25854 = x25853;
      bool x25859 = x25854;
      if (x25854) {
        long x25855 = x25644;
        char x25856 = x5[x25855];
        bool x25857 = x25856 != '\n';
        x25859 = x25857;
      }
      bool x25860 = x25859;
      if (!x25860) break;
      int x25862 = x25844;
      long x25864 = x25644;
      int x25863 = x25862 * 10;
      char x25865 = x5[x25864];
      char x25866 = x25865 - '0';
      int x25867 = x25863 + x25866;
      x25844 = x25867;
      x25644 = x25644 + 1;
    }
    long x25872 = x25644;
    char x25873 = x5[x25872];
    bool x25874 = x25873 == '.';
    if (x25874) {
      x25644 = x25644 + 1;
      for (;;) {
        long x25876 = x25644;
        char x25877 = x5[x25876];
        bool x25878 = x25877 != '|';
        bool x25883 = x25878;
        if (x25878) {
          long x25879 = x25644;
          char x25880 = x5[x25879];
          bool x25881 = x25880 != '\n';
          x25883 = x25881;
        }
        bool x25884 = x25883;
        if (!x25884) break;
        int x25886 = x25844;
        long x25888 = x25644;
        int x25887 = x25886 * 10;
        char x25889 = x5[x25888];
        char x25890 = x25889 - '0';
        int x25891 = x25887 + x25890;
        x25844 = x25891;
        int x25893 = x25845;
        int x25894 = x25893 * 10;
        x25845 = x25894;
        x25644 = x25644 + 1;
      }
    } else {
    }
    x25644 = x25644 + 1;
    int x25903 = x25844;
    int x25905 = x25845;
    int x25909 = 0;
    int x25910 = 1;
    for (;;) {
      long x25911 = x25644;
      char x25912 = x5[x25911];
      bool x25913 = x25912 != '.';
      bool x25918 = x25913;
      if (x25913) {
        long x25914 = x25644;
        char x25915 = x5[x25914];
        bool x25916 = x25915 != '|';
        x25918 = x25916;
      }
      bool x25919 = x25918;
      bool x25924 = x25919;
      if (x25919) {
        long x25920 = x25644;
        char x25921 = x5[x25920];
        bool x25922 = x25921 != '\n';
        x25924 = x25922;
      }
      bool x25925 = x25924;
      if (!x25925) break;
      int x25927 = x25909;
      long x25929 = x25644;
      int x25928 = x25927 * 10;
      char x25930 = x5[x25929];
      char x25931 = x25930 - '0';
      int x25932 = x25928 + x25931;
      x25909 = x25932;
      x25644 = x25644 + 1;
    }
    long x25937 = x25644;
    char x25938 = x5[x25937];
    bool x25939 = x25938 == '.';
    if (x25939) {
      x25644 = x25644 + 1;
      for (;;) {
        long x25941 = x25644;
        char x25942 = x5[x25941];
        bool x25943 = x25942 != '|';
        bool x25948 = x25943;
        if (x25943) {
          long x25944 = x25644;
          char x25945 = x5[x25944];
          bool x25946 = x25945 != '\n';
          x25948 = x25946;
        }
        bool x25949 = x25948;
        if (!x25949) break;
        int x25951 = x25909;
        long x25953 = x25644;
        int x25952 = x25951 * 10;
        char x25954 = x5[x25953];
        char x25955 = x25954 - '0';
        int x25956 = x25952 + x25955;
        x25909 = x25956;
        int x25958 = x25910;
        int x25959 = x25958 * 10;
        x25910 = x25959;
        x25644 = x25644 + 1;
      }
    } else {
    }
    x25644 = x25644 + 1;
    int x25968 = x25909;
    int x25970 = x25910;
    for (;;) {
      long x25976 = x25644;
      char x25977 = x5[x25976];
      bool x25978 = x25977 != '.';
      bool x25983 = x25978;
      if (x25978) {
        long x25979 = x25644;
        char x25980 = x5[x25979];
        bool x25981 = x25980 != '|';
        x25983 = x25981;
      }
      bool x25984 = x25983;
      bool x25989 = x25984;
      if (x25984) {
        long x25985 = x25644;
        char x25986 = x5[x25985];
        bool x25987 = x25986 != '\n';
        x25989 = x25987;
      }
      bool x25990 = x25989;
      if (!x25990) break;
      x25644 = x25644 + 1;
    }
    long x26002 = x25644;
    char x26003 = x5[x26002];
    bool x26004 = x26003 == '.';
    if (x26004) {
      x25644 = x25644 + 1;
      for (;;) {
        long x26006 = x25644;
        char x26007 = x5[x26006];
        bool x26008 = x26007 != '|';
        bool x26013 = x26008;
        if (x26008) {
          long x26009 = x25644;
          char x26010 = x5[x26009];
          bool x26011 = x26010 != '\n';
          x26013 = x26011;
        }
        bool x26014 = x26013;
        if (!x26014) break;
        x25644 = x25644 + 1;
      }
    } else {
    }
    x25644 = x25644 + 1;
    x25644 = x25644 + 2;
    x25644 = x25644 + 2;
    int x26045 = 0;
    for (;;) {
      long x26046 = x25644;
      char x26047 = x5[x26046];
      bool x26048 = x26047 != '-';
      bool x26053 = x26048;
      if (x26048) {
        long x26049 = x25644;
        char x26050 = x5[x26049];
        bool x26051 = x26050 != '\n';
        x26053 = x26051;
      }
      bool x26054 = x26053;
      if (!x26054) break;
      int x26056 = x26045;
      long x26058 = x25644;
      int x26057 = x26056 * 10;
      char x26059 = x5[x26058];
      char x26060 = x26059 - '0';
      int x26061 = x26057 + x26060;
      x26045 = x26061;
      x25644 = x25644 + 1;
    }
    x25644 = x25644 + 1;
    int x26067 = x26045;
    int x26069 = 0;
    for (;;) {
      long x26070 = x25644;
      char x26071 = x5[x26070];
      bool x26072 = x26071 != '-';
      bool x26077 = x26072;
      if (x26072) {
        long x26073 = x25644;
        char x26074 = x5[x26073];
        bool x26075 = x26074 != '\n';
        x26077 = x26075;
      }
      bool x26078 = x26077;
      if (!x26078) break;
      int x26080 = x26069;
      long x26082 = x25644;
      int x26081 = x26080 * 10;
      char x26083 = x5[x26082];
      char x26084 = x26083 - '0';
      int x26085 = x26081 + x26084;
      x26069 = x26085;
      x25644 = x25644 + 1;
    }
    x25644 = x25644 + 1;
    int x26091 = x26069;
    int x26093 = 0;
    for (;;) {
      long x26094 = x25644;
      char x26095 = x5[x26094];
      bool x26096 = x26095 != '|';
      bool x26101 = x26096;
      if (x26096) {
        long x26097 = x25644;
        char x26098 = x5[x26097];
        bool x26099 = x26098 != '\n';
        x26101 = x26099;
      }
      bool x26102 = x26101;
      if (!x26102) break;
      int x26104 = x26093;
      long x26106 = x25644;
      int x26105 = x26104 * 10;
      char x26107 = x5[x26106];
      char x26108 = x26107 - '0';
      int x26109 = x26105 + x26108;
      x26093 = x26109;
      x25644 = x25644 + 1;
    }
    x25644 = x25644 + 1;
    int x26115 = x26093;
    for (;;) {
      long x26122 = x25644;
      char x26123 = x5[x26122];
      bool x26124 = x26123 != '-';
      bool x26129 = x26124;
      if (x26124) {
        long x26125 = x25644;
        char x26126 = x5[x26125];
        bool x26127 = x26126 != '\n';
        x26129 = x26127;
      }
      bool x26130 = x26129;
      if (!x26130) break;
      x25644 = x25644 + 1;
    }
    x25644 = x25644 + 1;
    for (;;) {
      long x26146 = x25644;
      char x26147 = x5[x26146];
      bool x26148 = x26147 != '-';
      bool x26153 = x26148;
      if (x26148) {
        long x26149 = x25644;
        char x26150 = x5[x26149];
        bool x26151 = x26150 != '\n';
        x26153 = x26151;
      }
      bool x26154 = x26153;
      if (!x26154) break;
      x25644 = x25644 + 1;
    }
    x25644 = x25644 + 1;
    for (;;) {
      long x26170 = x25644;
      char x26171 = x5[x26170];
      bool x26172 = x26171 != '|';
      bool x26177 = x26172;
      if (x26172) {
        long x26173 = x25644;
        char x26174 = x5[x26173];
        bool x26175 = x26174 != '\n';
        x26177 = x26175;
      }
      bool x26178 = x26177;
      if (!x26178) break;
      x25644 = x25644 + 1;
    }
    x25644 = x25644 + 1;
    for (;;) {
      long x26198 = x25644;
      char x26199 = x5[x26198];
      bool x26200 = x26199 != '-';
      bool x26205 = x26200;
      if (x26200) {
        long x26201 = x25644;
        char x26202 = x5[x26201];
        bool x26203 = x26202 != '\n';
        x26205 = x26203;
      }
      bool x26206 = x26205;
      if (!x26206) break;
      x25644 = x25644 + 1;
    }
    x25644 = x25644 + 1;
    for (;;) {
      long x26222 = x25644;
      char x26223 = x5[x26222];
      bool x26224 = x26223 != '-';
      bool x26229 = x26224;
      if (x26224) {
        long x26225 = x25644;
        char x26226 = x5[x26225];
        bool x26227 = x26226 != '\n';
        x26229 = x26227;
      }
      bool x26230 = x26229;
      if (!x26230) break;
      x25644 = x25644 + 1;
    }
    x25644 = x25644 + 1;
    for (;;) {
      long x26246 = x25644;
      char x26247 = x5[x26246];
      bool x26248 = x26247 != '|';
      bool x26253 = x26248;
      if (x26248) {
        long x26249 = x25644;
        char x26250 = x5[x26249];
        bool x26251 = x26250 != '\n';
        x26253 = x26251;
      }
      bool x26254 = x26253;
      if (!x26254) break;
      x25644 = x25644 + 1;
    }
    x25644 = x25644 + 1;
    for (;;) {
      long x26273 = x25644;
      char x26274 = x5[x26273];
      bool x26275 = x26274 != '|';
      bool x26280 = x26275;
      if (x26275) {
        long x26276 = x25644;
        char x26277 = x5[x26276];
        bool x26278 = x26277 != '\n';
        x26280 = x26278;
      }
      bool x26281 = x26280;
      if (!x26281) break;
      x25644 = x25644 + 1;
    }
    x25644 = x25644 + 1;
    for (;;) {
      long x26291 = x25644;
      char x26292 = x5[x26291];
      bool x26293 = x26292 != '|';
      bool x26298 = x26293;
      if (x26293) {
        long x26294 = x25644;
        char x26295 = x5[x26294];
        bool x26296 = x26295 != '\n';
        x26298 = x26296;
      }
      bool x26299 = x26298;
      if (!x26299) break;
      x25644 = x25644 + 1;
    }
    x25644 = x25644 + 1;
    for (;;) {
      long x26309 = x25644;
      char x26310 = x5[x26309];
      bool x26311 = x26310 != '|';
      bool x26316 = x26311;
      if (x26311) {
        long x26312 = x25644;
        char x26313 = x5[x26312];
        bool x26314 = x26313 != '\n';
        x26316 = x26314;
      }
      bool x26317 = x26316;
      if (!x26317) break;
      x25644 = x25644 + 1;
    }
    x25644 = x25644 + 1;
    long x26327 = x25644;
    bool x26328 = x26327 > 0L;
    bool x26334 = x26328;
    if (x26328) {
      long x26329 = x25644;
      long x26330 = x26329 - 1L;
      char x26331 = x5[x26330];
      bool x26332 = x26331 != '\n';
      x26334 = x26332;
    }
    bool x26335 = x26334;
    if (x26335) {
      for (;;) {
        long x26336 = x25644;
        char x26337 = x5[x26336];
        bool x26338 = x26337 != '\n';
        if (!x26338) break;
        x25644 = x25644 + 1;
      }
    } else {
    }
    x25644 = x25644 + 1;
    long x26347 = x25646;
    long x26348 = x25645;
    bool x26349 = x26347 == x26348;
    if (x26349) {
      long x26350 = x26348 * 4L;
      x25645 = x26350;
      printf("buffer.resize %ld\n",x26350);
      int* x26356 = x25650;
      int* x26357 = (int*)realloc(x26356,x26350 * sizeof(int));
      x25650 = x26357;
      double* x26368 = x25658;
      double* x26369 = (double*)realloc(x26368,x26350 * sizeof(double));
      x25658 = x26369;
      double* x26371 = x25660;
      double* x26372 = (double*)realloc(x26371,x26350 * sizeof(double));
      x25660 = x26372;
      long* x26383 = x25668;
      long* x26384 = (long*)realloc(x26383,x26350 * sizeof(long));
      x25668 = x26384;
    } else {
    }
    int* x26405 = x25650;
    x26405[x26347] = x25729;
    double* x26413 = x25658;
    double x25904 = (double)x25903;
    double x25906 = (double)x25905;
    double x25907 = x25904 / x25906;
    x26413[x26347] = x25907;
    double* x26415 = x25660;
    double x25969 = (double)x25968;
    double x25971 = (double)x25970;
    double x25972 = x25969 / x25971;
    x26415[x26347] = x25972;
    long* x26423 = x25668;
    long x26116 = x26067 * 10000L;
    long x26117 = x26091 * 100L;
    long x26118 = x26116 + x26117;
    long x26119 = x26118 + x26115;
    x26423[x26347] = x26119;
    x25646 = x25646 + 1;
  }
  long x26438 = 0L;
  long x26439 = x7;
  long x26440 = 0L;
  int* x26441 = (int*)malloc(x7 * sizeof(int));
  int* x26442 = x26441;
  char** x26449 = (char**)malloc(x7 * sizeof(char*));
  char** x26450 = x26449;
  int x1076 = open("XXXXXpart.tbl",0);
  long x1077 = fsize(x1076);
  char* x1078 = mmap(0, x1077, PROT_READ, MAP_FILE | MAP_SHARED, x1076, 0);
  for (;;) {
    long x26460 = x26438;
    bool x26461 = x26460 < x1077;
    if (!x26461) break;
    int x26464 = 0;
    for (;;) {
      long x26465 = x26438;
      char x26466 = x1078[x26465];
      bool x26467 = x26466 != '|';
      bool x26472 = x26467;
      if (x26467) {
        long x26468 = x26438;
        char x26469 = x1078[x26468];
        bool x26470 = x26469 != '\n';
        x26472 = x26470;
      }
      bool x26473 = x26472;
      if (!x26473) break;
      int x26475 = x26464;
      long x26477 = x26438;
      int x26476 = x26475 * 10;
      char x26478 = x1078[x26477];
      char x26479 = x26478 - '0';
      int x26480 = x26476 + x26479;
      x26464 = x26480;
      x26438 = x26438 + 1;
    }
    x26438 = x26438 + 1;
    int x26486 = x26464;
    for (;;) {
      long x26488 = x26438;
      char x26489 = x1078[x26488];
      bool x26490 = x26489 != '|';
      bool x26495 = x26490;
      if (x26490) {
        long x26491 = x26438;
        char x26492 = x1078[x26491];
        bool x26493 = x26492 != '\n';
        x26495 = x26493;
      }
      bool x26496 = x26495;
      if (!x26496) break;
      x26438 = x26438 + 1;
    }
    x26438 = x26438 + 1;
    for (;;) {
      long x26506 = x26438;
      char x26507 = x1078[x26506];
      bool x26508 = x26507 != '|';
      bool x26513 = x26508;
      if (x26508) {
        long x26509 = x26438;
        char x26510 = x1078[x26509];
        bool x26511 = x26510 != '\n';
        x26513 = x26511;
      }
      bool x26514 = x26513;
      if (!x26514) break;
      x26438 = x26438 + 1;
    }
    x26438 = x26438 + 1;
    for (;;) {
      long x26524 = x26438;
      char x26525 = x1078[x26524];
      bool x26526 = x26525 != '|';
      bool x26531 = x26526;
      if (x26526) {
        long x26527 = x26438;
        char x26528 = x1078[x26527];
        bool x26529 = x26528 != '\n';
        x26531 = x26529;
      }
      bool x26532 = x26531;
      if (!x26532) break;
      x26438 = x26438 + 1;
    }
    x26438 = x26438 + 1;
    long x26541 = x26438;
    for (;;) {
      long x26542 = x26438;
      char x26543 = x1078[x26542];
      bool x26544 = x26543 != '|';
      bool x26549 = x26544;
      if (x26544) {
        long x26545 = x26438;
        char x26546 = x1078[x26545];
        bool x26547 = x26546 != '\n';
        x26549 = x26547;
      }
      bool x26550 = x26549;
      if (!x26550) break;
      x26438 = x26438 + 1;
    }
    x26438 = x26438 + 1;
    for (;;) {
      long x26561 = x26438;
      char x26562 = x1078[x26561];
      bool x26563 = x26562 != '|';
      bool x26568 = x26563;
      if (x26563) {
        long x26564 = x26438;
        char x26565 = x1078[x26564];
        bool x26566 = x26565 != '\n';
        x26568 = x26566;
      }
      bool x26569 = x26568;
      if (!x26569) break;
      x26438 = x26438 + 1;
    }
    x26438 = x26438 + 1;
    for (;;) {
      long x26584 = x26438;
      char x26585 = x1078[x26584];
      bool x26586 = x26585 != '|';
      bool x26591 = x26586;
      if (x26586) {
        long x26587 = x26438;
        char x26588 = x1078[x26587];
        bool x26589 = x26588 != '\n';
        x26591 = x26589;
      }
      bool x26592 = x26591;
      if (!x26592) break;
      x26438 = x26438 + 1;
    }
    x26438 = x26438 + 1;
    for (;;) {
      long x26604 = x26438;
      char x26605 = x1078[x26604];
      bool x26606 = x26605 != '.';
      bool x26611 = x26606;
      if (x26606) {
        long x26607 = x26438;
        char x26608 = x1078[x26607];
        bool x26609 = x26608 != '|';
        x26611 = x26609;
      }
      bool x26612 = x26611;
      bool x26617 = x26612;
      if (x26612) {
        long x26613 = x26438;
        char x26614 = x1078[x26613];
        bool x26615 = x26614 != '\n';
        x26617 = x26615;
      }
      bool x26618 = x26617;
      if (!x26618) break;
      x26438 = x26438 + 1;
    }
    long x26630 = x26438;
    char x26631 = x1078[x26630];
    bool x26632 = x26631 == '.';
    if (x26632) {
      x26438 = x26438 + 1;
      for (;;) {
        long x26634 = x26438;
        char x26635 = x1078[x26634];
        bool x26636 = x26635 != '|';
        bool x26641 = x26636;
        if (x26636) {
          long x26637 = x26438;
          char x26638 = x1078[x26637];
          bool x26639 = x26638 != '\n';
          x26641 = x26639;
        }
        bool x26642 = x26641;
        if (!x26642) break;
        x26438 = x26438 + 1;
      }
    } else {
    }
    x26438 = x26438 + 1;
    for (;;) {
      long x26667 = x26438;
      char x26668 = x1078[x26667];
      bool x26669 = x26668 != '|';
      bool x26674 = x26669;
      if (x26669) {
        long x26670 = x26438;
        char x26671 = x1078[x26670];
        bool x26672 = x26671 != '\n';
        x26674 = x26672;
      }
      bool x26675 = x26674;
      if (!x26675) break;
      x26438 = x26438 + 1;
    }
    x26438 = x26438 + 1;
    long x26685 = x26438;
    bool x26686 = x26685 > 0L;
    bool x26692 = x26686;
    if (x26686) {
      long x26687 = x26438;
      long x26688 = x26687 - 1L;
      char x26689 = x1078[x26688];
      bool x26690 = x26689 != '\n';
      x26692 = x26690;
    }
    bool x26693 = x26692;
    if (x26693) {
      for (;;) {
        long x26694 = x26438;
        char x26695 = x1078[x26694];
        bool x26696 = x26695 != '\n';
        if (!x26696) break;
        x26438 = x26438 + 1;
      }
    } else {
    }
    x26438 = x26438 + 1;
    long x26705 = x26440;
    long x26706 = x26439;
    bool x26707 = x26705 == x26706;
    if (x26707) {
      long x26708 = x26706 * 4L;
      x26439 = x26708;
      printf("buffer.resize %ld\n",x26708);
      int* x26711 = x26442;
      int* x26712 = (int*)realloc(x26711,x26708 * sizeof(int));
      x26442 = x26712;
      char** x26723 = x26450;
      char** x26724 = (char**)realloc(x26723,x26708 * sizeof(char*));
      x26450 = x26724;
    } else {
    }
    int* x26740 = x26442;
    x26740[x26705] = x26486;
    char** x26748 = x26450;
    char* x26558 = x1078+x26541;
    x26748[x26705] = x26558;
    x26440 = x26440 + 1;
  }
  long x2189 = DEFAULT_JOIN_HASH_SIZE;
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  long x2212 = x2189 - 1L;
  long x823 = x808 - 1L;
  bool x1043 = true == false;
  float x27039 = (float)100;
  double x27040 = (double)x27039;
  int x26761;
  for(x26761=0; x26761 < 5; x26761++) {
    bool x26762 = false;
    long x26763 = 0L;
    bool x26764 = false;
    long x26765 = 0L;
    int* x26768 = (int*)malloc(x2189 * sizeof(int));
    int* x26769 = x26768;
    char** x26776 = (char**)malloc(x2189 * sizeof(char*));
    char** x26777 = x26776;
    long x26786 = 0L;
    long* x26787 = (long*)malloc(x2189 * sizeof(long));
    long* x26788 = (long*)malloc(x2189 * sizeof(long));
    long x26789;
    for(x26789=0L; x26789 < x2189; x26789++) {
      x26787[x26789] = -1L;
    }
    struct Anon793459755* x26795 = (struct Anon793459755*)malloc(x808 * sizeof(struct Anon793459755));
    struct Anon793459755* x26796 = x26795;
    long x26797 = 0L;
    long* x26798 = (long*)malloc(x808 * sizeof(long));
    long x26799;
    for(x26799=0L; x26799 < x808; x26799++) {
      struct Anon793459755* x26800 = x26796;
      struct Anon793459755 x26801 = x26800[x26799];
      char* x26802 = x26801.key;;
      struct Anon189208763 x26803 = x26801.aggs;;
      struct Anon793459755 x26804;
      x26804.exists = false;
      x26804.key = x26802;
      x26804.aggs = x26803;
      x26800[x26799] = x26804;
    }
    long x26810 = 0L;
    struct timeval x27055, x27056, x27057;
    gettimeofday(&x27055, NULL);
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x26812 = x26762;
      bool x26813 = !x26812;
      bool x26818 = x26813;
      if (x26813) {
        long x26814 = x26763;
        long x26815 = x26440;
        bool x26816 = x26814 < x26815;
        x26818 = x26816;
      }
      bool x26819 = x26818;
      if (!x26819) break;
      long x26821 = x26763;
      int* x26822 = x26442;
      int x26823 = x26822[x26821];
      char** x26830 = x26450;
      char* x26831 = x26830[x26821];
      x26763 = x26763 + 1;
      long x26842 = x26786;
      int* x26843 = x26769;
      x26843[x26842] = x26823;
      char** x26851 = x26777;
      x26851[x26842] = x26831;
      x26786 = x26786 + 1L;
      long x26862 = x26823 & x2212;
      long x26863 = x26787[x26862];
      x26787[x26862] = x26842;
      x26788[x26842] = x26863;
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x26869 = x26764;
      bool x26870 = !x26869;
      bool x26875 = x26870;
      if (x26870) {
        long x26871 = x26765;
        long x26872 = x25646;
        bool x26873 = x26871 < x26872;
        x26875 = x26873;
      }
      bool x26876 = x26875;
      if (!x26876) break;
      long x26878 = x26765;
      int* x26881 = x25650;
      int x26882 = x26881[x26878];
      double* x26889 = x25658;
      double x26890 = x26889[x26878];
      double* x26891 = x25660;
      double x26892 = x26891[x26878];
      long* x26899 = x25668;
      long x26900 = x26899[x26878];
      x26765 = x26765 + 1;
      bool x26913 = x26900 >= 19950901L;
      bool x26915 = x26913;
      if (x26913) {
        bool x26914 = x26900 < 19951001L;
        x26915 = x26914;
      }
      bool x26916 = x26915;
      if (x26916) {
        long x26917 = x26882 & x2212;
        long x26918 = x26787[x26917];
        long x26919 = x26918;
        double x26965 = 1.0 - x26892;
        double x26966 = x26890 * x26965;
        for (;;) {
          long x26920 = x26919;
          bool x26921 = x26920 != -1;
          if (!x26921) break;
          long x26923 = x26919;
          int* x26924 = x26769;
          int x26925 = x26924[x26923];
          char** x26932 = x26777;
          char* x26933 = x26932[x26923];
          long x26943 = x26788[x26923];
          x26919 = x26943;
          bool x26945 = x26925 == x26882;
          if (x26945) {
            long x26949 = hash("Total", 10L);
            long x26950 = x26949 & x823;
            long x26951 = x26950;
            struct Anon793459755* x26952 = x26796;
            struct Anon793459755 x26953 = x26952[x26950];
            struct Anon793459755 x26954 = x26953;
            bool x26955 = x26953.exists;;
            bool x26960 = x26955;
            if (x26955) {
              struct Anon793459755 x26956 = x26954;
              char* x26957 = x26956.key;;
              bool x26958 = tpch_strcmp(x26957,"Total") == 0;;
              x26960 = x26958;
            }
            bool x26961 = x26960;
            if (x26961) {
              struct Anon189208763 x26962 = x26953.aggs;;
              char* x26972 = x26953.key;;
              bool x26963 = strncmp(x26933,"PROMO", tpch_strlen("PROMO")) == 0;;
              double x26968;
              if (x26963) {
                double x26964 = x26962._0;;
                double x26967 = x26964 + x26966;
                x26968 = x26967;
              } else {
                double x26964 = x26962._0;;
                x26968 = x26964;
              }
              double x26969 = x26962._1;;
              double x26970 = x26969 + x26966;
              struct Anon189208763 x26971;
              x26971._0 = x26968;
              x26971._1 = x26970;
              struct Anon793459755 x26973;
              x26973.exists = true;
              x26973.key = x26972;
              x26973.aggs = x26971;
              x26952[x26950] = x26973;
            } else {
              bool x26963 = strncmp(x26933,"PROMO", tpch_strlen("PROMO")) == 0;;
              double x27005;
              if (x26963) {
                x27005 = x26966;
              } else {
                x27005 = 0.0;
              }
              struct Anon189208763 x27006;
              x27006._0 = x27005;
              x27006._1 = x26966;
              struct Anon793459755 x27007;
              x27007.exists = true;
              x27007.key = "Total";
              x27007.aggs = x27006;
              for (;;) {
                struct Anon793459755 x26976 = x26954;
                bool x26977 = x26976.exists;;
                bool x27016;
                if (x26977) {
                  char* x26978 = x26976.key;;
                  bool x26979 = tpch_strcmp(x26978,"Total") == 0;;
                  bool x27002;
                  if (x26979) {
                    struct Anon189208763 x26980 = x26976.aggs;;
                    long x26987 = x26951;
                    struct Anon793459755* x26989 = x26796;
                    double x26983;
                    if (x26963) {
                      double x26981 = x26980._0;;
                      double x26982 = x26981 + x26966;
                      x26983 = x26982;
                    } else {
                      double x26981 = x26980._0;;
                      x26983 = x26981;
                    }
                    double x26984 = x26980._1;;
                    double x26985 = x26984 + x26966;
                    struct Anon189208763 x26986;
                    x26986._0 = x26983;
                    x26986._1 = x26985;
                    struct Anon793459755 x26988;
                    x26988.exists = true;
                    x26988.key = x26978;
                    x26988.aggs = x26986;
                    x26989[x26987] = x26988;
                    x27002 = false;
                  } else {
                    long x26992 = x26951;
                    long x26993 = x26992 + 1L;
                    long x26994 = x26993 & x823;
                    x26951 = x26994;
                    struct Anon793459755* x26996 = x26796;
                    struct Anon793459755 x26997 = x26996[x26994];
                    x26954 = x26997;
                    x27002 = true;
                  }
                  x27016 = x27002;
                } else {
                  long x27004 = x26951;
                  struct Anon793459755* x27008 = x26796;
                  x27008[x27004] = x27007;
                  long x27010 = x26797;
                  x26798[x27010] = x27004;
                  x26797 = x26797 + 1L;
                  x27016 = false;
                }
                if (!x27016) break;
              }
            }
          } else {
          }
        }
      } else {
      }
    }
    long x27031 = x26797;
    long x27033;
    for(x27033=0L; x27033 < x27031; x27033++) {
      long x27034 = x26798[x27033];
      struct Anon793459755* x27035 = x26796;
      struct Anon793459755 x27036 = x27035[x27034];
      struct Anon189208763 x27037 = x27036.aggs;;
      if (x1043) {
      } else {
        double x27038 = x27037._0;;
        double x27041 = x27038 * x27040;
        double x27042 = x27037._1;;
        double x27043 = x27041 / x27042;
        printf("%.4f\n",x27043);
        x26810 = x26810 + 1L;
      }
    }
    long x27052 = x26810;
    printf("(%ld rows)\n",x27052);
    gettimeofday(&x27056, NULL);
    timeval_subtract(&x27057, &x27056, &x27055);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x27057.tv_sec * 1000) + (x27057.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
