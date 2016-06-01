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
struct Anon811555534 left;
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
int x24456(struct Anon793459755* x24448, struct Anon793459755* x24449);
int x24456(struct Anon793459755* x24448, struct Anon793459755* x24449) {
  struct Anon793459755 x24450 = (*x24448);
  struct Anon793459755 x24451 = (*x24449);
  char* x24452 = x24450.key;;
  char* x24453 = x24451.key;;
  int x24454 = tpch_strcmp(x24452,x24453);
  return x24454;
}

/************************ MAIN BODY **************************/
int main(int x22954, char** x22955) {
  long x22956 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x22957 = x7;
  long x22958 = 0L;
  int* x22959 = (int*)malloc(x7 * sizeof(int));
  int* x22960 = x22959;
  long* x22979 = (long*)malloc(x7 * sizeof(long));
  long* x22980 = x22979;
  long* x22981 = (long*)malloc(x7 * sizeof(long));
  long* x22982 = x22981;
  long* x22983 = (long*)malloc(x7 * sizeof(long));
  long* x22984 = x22983;
  char** x22987 = (char**)malloc(x7 * sizeof(char*));
  char** x22988 = x22987;
  int x3 = open("XXXXXlineitem.tbl",0);
  long x4 = fsize(x3);
  char* x5 = mmap(0, x4, PROT_READ, MAP_FILE | MAP_SHARED, x3, 0);
  for (;;) {
    long x22991 = x22956;
    bool x22992 = x22991 < x4;
    if (!x22992) break;
    int x22995 = 0;
    for (;;) {
      long x22996 = x22956;
      char x22997 = x5[x22996];
      bool x22998 = x22997 != '|';
      bool x23003 = x22998;
      if (x22998) {
        long x22999 = x22956;
        char x23000 = x5[x22999];
        bool x23001 = x23000 != '\n';
        x23003 = x23001;
      }
      bool x23004 = x23003;
      if (!x23004) break;
      int x23006 = x22995;
      long x23008 = x22956;
      int x23007 = x23006 * 10;
      char x23009 = x5[x23008];
      char x23010 = x23009 - '0';
      int x23011 = x23007 + x23010;
      x22995 = x23011;
      x22956 = x22956 + 1;
    }
    x22956 = x22956 + 1;
    int x23017 = x22995;
    for (;;) {
      long x23020 = x22956;
      char x23021 = x5[x23020];
      bool x23022 = x23021 != '|';
      bool x23027 = x23022;
      if (x23022) {
        long x23023 = x22956;
        char x23024 = x5[x23023];
        bool x23025 = x23024 != '\n';
        x23027 = x23025;
      }
      bool x23028 = x23027;
      if (!x23028) break;
      x22956 = x22956 + 1;
    }
    x22956 = x22956 + 1;
    for (;;) {
      long x23044 = x22956;
      char x23045 = x5[x23044];
      bool x23046 = x23045 != '|';
      bool x23051 = x23046;
      if (x23046) {
        long x23047 = x22956;
        char x23048 = x5[x23047];
        bool x23049 = x23048 != '\n';
        x23051 = x23049;
      }
      bool x23052 = x23051;
      if (!x23052) break;
      x22956 = x22956 + 1;
    }
    x22956 = x22956 + 1;
    for (;;) {
      long x23068 = x22956;
      char x23069 = x5[x23068];
      bool x23070 = x23069 != '|';
      bool x23075 = x23070;
      if (x23070) {
        long x23071 = x22956;
        char x23072 = x5[x23071];
        bool x23073 = x23072 != '\n';
        x23075 = x23073;
      }
      bool x23076 = x23075;
      if (!x23076) break;
      x22956 = x22956 + 1;
    }
    x22956 = x22956 + 1;
    for (;;) {
      long x23093 = x22956;
      char x23094 = x5[x23093];
      bool x23095 = x23094 != '.';
      bool x23100 = x23095;
      if (x23095) {
        long x23096 = x22956;
        char x23097 = x5[x23096];
        bool x23098 = x23097 != '|';
        x23100 = x23098;
      }
      bool x23101 = x23100;
      bool x23106 = x23101;
      if (x23101) {
        long x23102 = x22956;
        char x23103 = x5[x23102];
        bool x23104 = x23103 != '\n';
        x23106 = x23104;
      }
      bool x23107 = x23106;
      if (!x23107) break;
      x22956 = x22956 + 1;
    }
    long x23119 = x22956;
    char x23120 = x5[x23119];
    bool x23121 = x23120 == '.';
    if (x23121) {
      x22956 = x22956 + 1;
      for (;;) {
        long x23123 = x22956;
        char x23124 = x5[x23123];
        bool x23125 = x23124 != '|';
        bool x23130 = x23125;
        if (x23125) {
          long x23126 = x22956;
          char x23127 = x5[x23126];
          bool x23128 = x23127 != '\n';
          x23130 = x23128;
        }
        bool x23131 = x23130;
        if (!x23131) break;
        x22956 = x22956 + 1;
      }
    } else {
    }
    x22956 = x22956 + 1;
    for (;;) {
      long x23158 = x22956;
      char x23159 = x5[x23158];
      bool x23160 = x23159 != '.';
      bool x23165 = x23160;
      if (x23160) {
        long x23161 = x22956;
        char x23162 = x5[x23161];
        bool x23163 = x23162 != '|';
        x23165 = x23163;
      }
      bool x23166 = x23165;
      bool x23171 = x23166;
      if (x23166) {
        long x23167 = x22956;
        char x23168 = x5[x23167];
        bool x23169 = x23168 != '\n';
        x23171 = x23169;
      }
      bool x23172 = x23171;
      if (!x23172) break;
      x22956 = x22956 + 1;
    }
    long x23184 = x22956;
    char x23185 = x5[x23184];
    bool x23186 = x23185 == '.';
    if (x23186) {
      x22956 = x22956 + 1;
      for (;;) {
        long x23188 = x22956;
        char x23189 = x5[x23188];
        bool x23190 = x23189 != '|';
        bool x23195 = x23190;
        if (x23190) {
          long x23191 = x22956;
          char x23192 = x5[x23191];
          bool x23193 = x23192 != '\n';
          x23195 = x23193;
        }
        bool x23196 = x23195;
        if (!x23196) break;
        x22956 = x22956 + 1;
      }
    } else {
    }
    x22956 = x22956 + 1;
    for (;;) {
      long x23223 = x22956;
      char x23224 = x5[x23223];
      bool x23225 = x23224 != '.';
      bool x23230 = x23225;
      if (x23225) {
        long x23226 = x22956;
        char x23227 = x5[x23226];
        bool x23228 = x23227 != '|';
        x23230 = x23228;
      }
      bool x23231 = x23230;
      bool x23236 = x23231;
      if (x23231) {
        long x23232 = x22956;
        char x23233 = x5[x23232];
        bool x23234 = x23233 != '\n';
        x23236 = x23234;
      }
      bool x23237 = x23236;
      if (!x23237) break;
      x22956 = x22956 + 1;
    }
    long x23249 = x22956;
    char x23250 = x5[x23249];
    bool x23251 = x23250 == '.';
    if (x23251) {
      x22956 = x22956 + 1;
      for (;;) {
        long x23253 = x22956;
        char x23254 = x5[x23253];
        bool x23255 = x23254 != '|';
        bool x23260 = x23255;
        if (x23255) {
          long x23256 = x22956;
          char x23257 = x5[x23256];
          bool x23258 = x23257 != '\n';
          x23260 = x23258;
        }
        bool x23261 = x23260;
        if (!x23261) break;
        x22956 = x22956 + 1;
      }
    } else {
    }
    x22956 = x22956 + 1;
    for (;;) {
      long x23288 = x22956;
      char x23289 = x5[x23288];
      bool x23290 = x23289 != '.';
      bool x23295 = x23290;
      if (x23290) {
        long x23291 = x22956;
        char x23292 = x5[x23291];
        bool x23293 = x23292 != '|';
        x23295 = x23293;
      }
      bool x23296 = x23295;
      bool x23301 = x23296;
      if (x23296) {
        long x23297 = x22956;
        char x23298 = x5[x23297];
        bool x23299 = x23298 != '\n';
        x23301 = x23299;
      }
      bool x23302 = x23301;
      if (!x23302) break;
      x22956 = x22956 + 1;
    }
    long x23314 = x22956;
    char x23315 = x5[x23314];
    bool x23316 = x23315 == '.';
    if (x23316) {
      x22956 = x22956 + 1;
      for (;;) {
        long x23318 = x22956;
        char x23319 = x5[x23318];
        bool x23320 = x23319 != '|';
        bool x23325 = x23320;
        if (x23320) {
          long x23321 = x22956;
          char x23322 = x5[x23321];
          bool x23323 = x23322 != '\n';
          x23325 = x23323;
        }
        bool x23326 = x23325;
        if (!x23326) break;
        x22956 = x22956 + 1;
      }
    } else {
    }
    x22956 = x22956 + 1;
    x22956 = x22956 + 2;
    x22956 = x22956 + 2;
    int x23357 = 0;
    for (;;) {
      long x23358 = x22956;
      char x23359 = x5[x23358];
      bool x23360 = x23359 != '-';
      bool x23365 = x23360;
      if (x23360) {
        long x23361 = x22956;
        char x23362 = x5[x23361];
        bool x23363 = x23362 != '\n';
        x23365 = x23363;
      }
      bool x23366 = x23365;
      if (!x23366) break;
      int x23368 = x23357;
      long x23370 = x22956;
      int x23369 = x23368 * 10;
      char x23371 = x5[x23370];
      char x23372 = x23371 - '0';
      int x23373 = x23369 + x23372;
      x23357 = x23373;
      x22956 = x22956 + 1;
    }
    x22956 = x22956 + 1;
    int x23379 = x23357;
    int x23381 = 0;
    for (;;) {
      long x23382 = x22956;
      char x23383 = x5[x23382];
      bool x23384 = x23383 != '-';
      bool x23389 = x23384;
      if (x23384) {
        long x23385 = x22956;
        char x23386 = x5[x23385];
        bool x23387 = x23386 != '\n';
        x23389 = x23387;
      }
      bool x23390 = x23389;
      if (!x23390) break;
      int x23392 = x23381;
      long x23394 = x22956;
      int x23393 = x23392 * 10;
      char x23395 = x5[x23394];
      char x23396 = x23395 - '0';
      int x23397 = x23393 + x23396;
      x23381 = x23397;
      x22956 = x22956 + 1;
    }
    x22956 = x22956 + 1;
    int x23403 = x23381;
    int x23405 = 0;
    for (;;) {
      long x23406 = x22956;
      char x23407 = x5[x23406];
      bool x23408 = x23407 != '|';
      bool x23413 = x23408;
      if (x23408) {
        long x23409 = x22956;
        char x23410 = x5[x23409];
        bool x23411 = x23410 != '\n';
        x23413 = x23411;
      }
      bool x23414 = x23413;
      if (!x23414) break;
      int x23416 = x23405;
      long x23418 = x22956;
      int x23417 = x23416 * 10;
      char x23419 = x5[x23418];
      char x23420 = x23419 - '0';
      int x23421 = x23417 + x23420;
      x23405 = x23421;
      x22956 = x22956 + 1;
    }
    x22956 = x22956 + 1;
    int x23427 = x23405;
    int x23433 = 0;
    for (;;) {
      long x23434 = x22956;
      char x23435 = x5[x23434];
      bool x23436 = x23435 != '-';
      bool x23441 = x23436;
      if (x23436) {
        long x23437 = x22956;
        char x23438 = x5[x23437];
        bool x23439 = x23438 != '\n';
        x23441 = x23439;
      }
      bool x23442 = x23441;
      if (!x23442) break;
      int x23444 = x23433;
      long x23446 = x22956;
      int x23445 = x23444 * 10;
      char x23447 = x5[x23446];
      char x23448 = x23447 - '0';
      int x23449 = x23445 + x23448;
      x23433 = x23449;
      x22956 = x22956 + 1;
    }
    x22956 = x22956 + 1;
    int x23455 = x23433;
    int x23457 = 0;
    for (;;) {
      long x23458 = x22956;
      char x23459 = x5[x23458];
      bool x23460 = x23459 != '-';
      bool x23465 = x23460;
      if (x23460) {
        long x23461 = x22956;
        char x23462 = x5[x23461];
        bool x23463 = x23462 != '\n';
        x23465 = x23463;
      }
      bool x23466 = x23465;
      if (!x23466) break;
      int x23468 = x23457;
      long x23470 = x22956;
      int x23469 = x23468 * 10;
      char x23471 = x5[x23470];
      char x23472 = x23471 - '0';
      int x23473 = x23469 + x23472;
      x23457 = x23473;
      x22956 = x22956 + 1;
    }
    x22956 = x22956 + 1;
    int x23479 = x23457;
    int x23481 = 0;
    for (;;) {
      long x23482 = x22956;
      char x23483 = x5[x23482];
      bool x23484 = x23483 != '|';
      bool x23489 = x23484;
      if (x23484) {
        long x23485 = x22956;
        char x23486 = x5[x23485];
        bool x23487 = x23486 != '\n';
        x23489 = x23487;
      }
      bool x23490 = x23489;
      if (!x23490) break;
      int x23492 = x23481;
      long x23494 = x22956;
      int x23493 = x23492 * 10;
      char x23495 = x5[x23494];
      char x23496 = x23495 - '0';
      int x23497 = x23493 + x23496;
      x23481 = x23497;
      x22956 = x22956 + 1;
    }
    x22956 = x22956 + 1;
    int x23503 = x23481;
    int x23509 = 0;
    for (;;) {
      long x23510 = x22956;
      char x23511 = x5[x23510];
      bool x23512 = x23511 != '-';
      bool x23517 = x23512;
      if (x23512) {
        long x23513 = x22956;
        char x23514 = x5[x23513];
        bool x23515 = x23514 != '\n';
        x23517 = x23515;
      }
      bool x23518 = x23517;
      if (!x23518) break;
      int x23520 = x23509;
      long x23522 = x22956;
      int x23521 = x23520 * 10;
      char x23523 = x5[x23522];
      char x23524 = x23523 - '0';
      int x23525 = x23521 + x23524;
      x23509 = x23525;
      x22956 = x22956 + 1;
    }
    x22956 = x22956 + 1;
    int x23531 = x23509;
    int x23533 = 0;
    for (;;) {
      long x23534 = x22956;
      char x23535 = x5[x23534];
      bool x23536 = x23535 != '-';
      bool x23541 = x23536;
      if (x23536) {
        long x23537 = x22956;
        char x23538 = x5[x23537];
        bool x23539 = x23538 != '\n';
        x23541 = x23539;
      }
      bool x23542 = x23541;
      if (!x23542) break;
      int x23544 = x23533;
      long x23546 = x22956;
      int x23545 = x23544 * 10;
      char x23547 = x5[x23546];
      char x23548 = x23547 - '0';
      int x23549 = x23545 + x23548;
      x23533 = x23549;
      x22956 = x22956 + 1;
    }
    x22956 = x22956 + 1;
    int x23555 = x23533;
    int x23557 = 0;
    for (;;) {
      long x23558 = x22956;
      char x23559 = x5[x23558];
      bool x23560 = x23559 != '|';
      bool x23565 = x23560;
      if (x23560) {
        long x23561 = x22956;
        char x23562 = x5[x23561];
        bool x23563 = x23562 != '\n';
        x23565 = x23563;
      }
      bool x23566 = x23565;
      if (!x23566) break;
      int x23568 = x23557;
      long x23570 = x22956;
      int x23569 = x23568 * 10;
      char x23571 = x5[x23570];
      char x23572 = x23571 - '0';
      int x23573 = x23569 + x23572;
      x23557 = x23573;
      x22956 = x22956 + 1;
    }
    x22956 = x22956 + 1;
    int x23579 = x23557;
    for (;;) {
      long x23585 = x22956;
      char x23586 = x5[x23585];
      bool x23587 = x23586 != '|';
      bool x23592 = x23587;
      if (x23587) {
        long x23588 = x22956;
        char x23589 = x5[x23588];
        bool x23590 = x23589 != '\n';
        x23592 = x23590;
      }
      bool x23593 = x23592;
      if (!x23593) break;
      x22956 = x22956 + 1;
    }
    x22956 = x22956 + 1;
    long x23602 = x22956;
    for (;;) {
      long x23603 = x22956;
      char x23604 = x5[x23603];
      bool x23605 = x23604 != '|';
      bool x23610 = x23605;
      if (x23605) {
        long x23606 = x22956;
        char x23607 = x5[x23606];
        bool x23608 = x23607 != '\n';
        x23610 = x23608;
      }
      bool x23611 = x23610;
      if (!x23611) break;
      x22956 = x22956 + 1;
    }
    x22956 = x22956 + 1;
    for (;;) {
      long x23621 = x22956;
      char x23622 = x5[x23621];
      bool x23623 = x23622 != '|';
      bool x23628 = x23623;
      if (x23623) {
        long x23624 = x22956;
        char x23625 = x5[x23624];
        bool x23626 = x23625 != '\n';
        x23628 = x23626;
      }
      bool x23629 = x23628;
      if (!x23629) break;
      x22956 = x22956 + 1;
    }
    x22956 = x22956 + 1;
    long x23639 = x22956;
    bool x23640 = x23639 > 0L;
    bool x23646 = x23640;
    if (x23640) {
      long x23641 = x22956;
      long x23642 = x23641 - 1L;
      char x23643 = x5[x23642];
      bool x23644 = x23643 != '\n';
      x23646 = x23644;
    }
    bool x23647 = x23646;
    if (x23647) {
      for (;;) {
        long x23648 = x22956;
        char x23649 = x5[x23648];
        bool x23650 = x23649 != '\n';
        if (!x23650) break;
        x22956 = x22956 + 1;
      }
    } else {
    }
    x22956 = x22956 + 1;
    long x23659 = x22958;
    long x23660 = x22957;
    bool x23661 = x23659 == x23660;
    if (x23661) {
      long x23662 = x23660 * 4L;
      x22957 = x23662;
      printf("buffer.resize %ld\n",x23662);
      int* x23665 = x22960;
      int* x23666 = (int*)realloc(x23665,x23662 * sizeof(int));
      x22960 = x23666;
      long* x23695 = x22980;
      long* x23696 = (long*)realloc(x23695,x23662 * sizeof(long));
      x22980 = x23696;
      long* x23698 = x22982;
      long* x23699 = (long*)realloc(x23698,x23662 * sizeof(long));
      x22982 = x23699;
      long* x23701 = x22984;
      long* x23702 = (long*)realloc(x23701,x23662 * sizeof(long));
      x22984 = x23702;
      char** x23707 = x22988;
      char** x23708 = (char**)realloc(x23707,x23662 * sizeof(char*));
      x22988 = x23708;
    } else {
    }
    int* x23715 = x22960;
    x23715[x23659] = x23017;
    long* x23735 = x22980;
    long x23428 = x23379 * 10000L;
    long x23429 = x23403 * 100L;
    long x23430 = x23428 + x23429;
    long x23431 = x23430 + x23427;
    x23735[x23659] = x23431;
    long* x23737 = x22982;
    long x23504 = x23455 * 10000L;
    long x23505 = x23479 * 100L;
    long x23506 = x23504 + x23505;
    long x23507 = x23506 + x23503;
    x23737[x23659] = x23507;
    long* x23739 = x22984;
    long x23580 = x23531 * 10000L;
    long x23581 = x23555 * 100L;
    long x23582 = x23580 + x23581;
    long x23583 = x23582 + x23579;
    x23739[x23659] = x23583;
    char** x23743 = x22988;
    char* x23619 = x5+x23602;
    x23743[x23659] = x23619;
    x22958 = x22958 + 1;
  }
  long x23750 = 0L;
  long x23751 = x7;
  long x23752 = 0L;
  int* x23753 = (int*)malloc(x7 * sizeof(int));
  int* x23754 = x23753;
  char** x23763 = (char**)malloc(x7 * sizeof(char*));
  char** x23764 = x23763;
  int x3633 = open("XXXXXorders.tbl",0);
  long x3634 = fsize(x3633);
  char* x3635 = mmap(0, x3634, PROT_READ, MAP_FILE | MAP_SHARED, x3633, 0);
  for (;;) {
    long x23771 = x23750;
    bool x23772 = x23771 < x3634;
    if (!x23772) break;
    int x23775 = 0;
    for (;;) {
      long x23776 = x23750;
      char x23777 = x3635[x23776];
      bool x23778 = x23777 != '|';
      bool x23783 = x23778;
      if (x23778) {
        long x23779 = x23750;
        char x23780 = x3635[x23779];
        bool x23781 = x23780 != '\n';
        x23783 = x23781;
      }
      bool x23784 = x23783;
      if (!x23784) break;
      int x23786 = x23775;
      long x23788 = x23750;
      int x23787 = x23786 * 10;
      char x23789 = x3635[x23788];
      char x23790 = x23789 - '0';
      int x23791 = x23787 + x23790;
      x23775 = x23791;
      x23750 = x23750 + 1;
    }
    x23750 = x23750 + 1;
    int x23797 = x23775;
    for (;;) {
      long x23800 = x23750;
      char x23801 = x3635[x23800];
      bool x23802 = x23801 != '|';
      bool x23807 = x23802;
      if (x23802) {
        long x23803 = x23750;
        char x23804 = x3635[x23803];
        bool x23805 = x23804 != '\n';
        x23807 = x23805;
      }
      bool x23808 = x23807;
      if (!x23808) break;
      x23750 = x23750 + 1;
    }
    x23750 = x23750 + 1;
    x23750 = x23750 + 2;
    for (;;) {
      long x23828 = x23750;
      char x23829 = x3635[x23828];
      bool x23830 = x23829 != '.';
      bool x23835 = x23830;
      if (x23830) {
        long x23831 = x23750;
        char x23832 = x3635[x23831];
        bool x23833 = x23832 != '|';
        x23835 = x23833;
      }
      bool x23836 = x23835;
      bool x23841 = x23836;
      if (x23836) {
        long x23837 = x23750;
        char x23838 = x3635[x23837];
        bool x23839 = x23838 != '\n';
        x23841 = x23839;
      }
      bool x23842 = x23841;
      if (!x23842) break;
      x23750 = x23750 + 1;
    }
    long x23854 = x23750;
    char x23855 = x3635[x23854];
    bool x23856 = x23855 == '.';
    if (x23856) {
      x23750 = x23750 + 1;
      for (;;) {
        long x23858 = x23750;
        char x23859 = x3635[x23858];
        bool x23860 = x23859 != '|';
        bool x23865 = x23860;
        if (x23860) {
          long x23861 = x23750;
          char x23862 = x3635[x23861];
          bool x23863 = x23862 != '\n';
          x23865 = x23863;
        }
        bool x23866 = x23865;
        if (!x23866) break;
        x23750 = x23750 + 1;
      }
    } else {
    }
    x23750 = x23750 + 1;
    for (;;) {
      long x23892 = x23750;
      char x23893 = x3635[x23892];
      bool x23894 = x23893 != '-';
      bool x23899 = x23894;
      if (x23894) {
        long x23895 = x23750;
        char x23896 = x3635[x23895];
        bool x23897 = x23896 != '\n';
        x23899 = x23897;
      }
      bool x23900 = x23899;
      if (!x23900) break;
      x23750 = x23750 + 1;
    }
    x23750 = x23750 + 1;
    for (;;) {
      long x23916 = x23750;
      char x23917 = x3635[x23916];
      bool x23918 = x23917 != '-';
      bool x23923 = x23918;
      if (x23918) {
        long x23919 = x23750;
        char x23920 = x3635[x23919];
        bool x23921 = x23920 != '\n';
        x23923 = x23921;
      }
      bool x23924 = x23923;
      if (!x23924) break;
      x23750 = x23750 + 1;
    }
    x23750 = x23750 + 1;
    for (;;) {
      long x23940 = x23750;
      char x23941 = x3635[x23940];
      bool x23942 = x23941 != '|';
      bool x23947 = x23942;
      if (x23942) {
        long x23943 = x23750;
        char x23944 = x3635[x23943];
        bool x23945 = x23944 != '\n';
        x23947 = x23945;
      }
      bool x23948 = x23947;
      if (!x23948) break;
      x23750 = x23750 + 1;
    }
    x23750 = x23750 + 1;
    long x23966 = x23750;
    for (;;) {
      long x23967 = x23750;
      char x23968 = x3635[x23967];
      bool x23969 = x23968 != '|';
      bool x23974 = x23969;
      if (x23969) {
        long x23970 = x23750;
        char x23971 = x3635[x23970];
        bool x23972 = x23971 != '\n';
        x23974 = x23972;
      }
      bool x23975 = x23974;
      if (!x23975) break;
      x23750 = x23750 + 1;
    }
    x23750 = x23750 + 1;
    for (;;) {
      long x23985 = x23750;
      char x23986 = x3635[x23985];
      bool x23987 = x23986 != '|';
      bool x23992 = x23987;
      if (x23987) {
        long x23988 = x23750;
        char x23989 = x3635[x23988];
        bool x23990 = x23989 != '\n';
        x23992 = x23990;
      }
      bool x23993 = x23992;
      if (!x23993) break;
      x23750 = x23750 + 1;
    }
    x23750 = x23750 + 1;
    for (;;) {
      long x24004 = x23750;
      char x24005 = x3635[x24004];
      bool x24006 = x24005 != '|';
      bool x24011 = x24006;
      if (x24006) {
        long x24007 = x23750;
        char x24008 = x3635[x24007];
        bool x24009 = x24008 != '\n';
        x24011 = x24009;
      }
      bool x24012 = x24011;
      if (!x24012) break;
      x23750 = x23750 + 1;
    }
    x23750 = x23750 + 1;
    for (;;) {
      long x24027 = x23750;
      char x24028 = x3635[x24027];
      bool x24029 = x24028 != '|';
      bool x24034 = x24029;
      if (x24029) {
        long x24030 = x23750;
        char x24031 = x3635[x24030];
        bool x24032 = x24031 != '\n';
        x24034 = x24032;
      }
      bool x24035 = x24034;
      if (!x24035) break;
      x23750 = x23750 + 1;
    }
    x23750 = x23750 + 1;
    long x24045 = x23750;
    bool x24046 = x24045 > 0L;
    bool x24052 = x24046;
    if (x24046) {
      long x24047 = x23750;
      long x24048 = x24047 - 1L;
      char x24049 = x3635[x24048];
      bool x24050 = x24049 != '\n';
      x24052 = x24050;
    }
    bool x24053 = x24052;
    if (x24053) {
      for (;;) {
        long x24054 = x23750;
        char x24055 = x3635[x24054];
        bool x24056 = x24055 != '\n';
        if (!x24056) break;
        x23750 = x23750 + 1;
      }
    } else {
    }
    x23750 = x23750 + 1;
    long x24065 = x23752;
    long x24066 = x23751;
    bool x24067 = x24065 == x24066;
    if (x24067) {
      long x24068 = x24066 * 4L;
      x23751 = x24068;
      printf("buffer.resize %ld\n",x24068);
      int* x24071 = x23754;
      int* x24072 = (int*)realloc(x24071,x24068 * sizeof(int));
      x23754 = x24072;
      char** x24086 = x23764;
      char** x24087 = (char**)realloc(x24086,x24068 * sizeof(char*));
      x23764 = x24087;
    } else {
    }
    int* x24100 = x23754;
    x24100[x24065] = x23797;
    char** x24110 = x23764;
    char* x23983 = x3635+x23966;
    x24110[x24065] = x23983;
    x23752 = x23752 + 1;
  }
  long x2189 = DEFAULT_JOIN_HASH_SIZE;
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  long x2212 = x2189 - 1L;
  long x823 = x808 - 1L;
  bool x1043 = true == false;
  int x24121;
  for(x24121=0; x24121 < 5; x24121++) {
    bool x24122 = false;
    long x24123 = 0L;
    bool x24124 = false;
    long x24125 = 0L;
    int* x24128 = (int*)malloc(x2189 * sizeof(int));
    int* x24129 = x24128;
    char** x24138 = (char**)malloc(x2189 * sizeof(char*));
    char** x24139 = x24138;
    long x24146 = 0L;
    long* x24147 = (long*)malloc(x2189 * sizeof(long));
    long* x24148 = (long*)malloc(x2189 * sizeof(long));
    long x24149;
    for(x24149=0L; x24149 < x2189; x24149++) {
      x24147[x24149] = -1L;
    }
    struct Anon793459755* x24155 = (struct Anon793459755*)malloc(x808 * sizeof(struct Anon793459755));
    struct Anon793459755* x24156 = x24155;
    long x24157 = 0L;
    long* x24158 = (long*)malloc(x808 * sizeof(long));
    long x24159;
    for(x24159=0L; x24159 < x808; x24159++) {
      struct Anon793459755* x24160 = x24156;
      struct Anon793459755 x24161 = x24160[x24159];
      char* x24162 = x24161.key;;
      struct Anon189208763 x24163 = x24161.aggs;;
      struct Anon793459755 x24164;
      x24164.exists = false;
      x24164.key = x24162;
      x24164.aggs = x24163;
      x24160[x24159] = x24164;
    }
    long x24169 = 1024L;
    long x24170 = 0L;
    struct Anon793459755* x24171 = (struct Anon793459755*)malloc(1024L * sizeof(struct Anon793459755));
    struct Anon793459755* x24172 = x24171;
    long x24174 = 0L;
    struct timeval x24478, x24479, x24480;
    gettimeofday(&x24478, NULL);
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x24176 = x24122;
      bool x24177 = !x24176;
      bool x24182 = x24177;
      if (x24177) {
        long x24178 = x24123;
        long x24179 = x23752;
        bool x24180 = x24178 < x24179;
        x24182 = x24180;
      }
      bool x24183 = x24182;
      if (!x24183) break;
      long x24185 = x24123;
      int* x24186 = x23754;
      int x24187 = x24186[x24185];
      char** x24196 = x23764;
      char* x24197 = x24196[x24185];
      x24123 = x24123 + 1;
      long x24206 = x24146;
      int* x24207 = x24129;
      x24207[x24206] = x24187;
      char** x24217 = x24139;
      x24217[x24206] = x24197;
      x24146 = x24146 + 1L;
      long x24226 = x24187 & x2212;
      long x24227 = x24147[x24226];
      x24147[x24226] = x24206;
      x24148[x24206] = x24227;
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x24233 = x24124;
      bool x24234 = !x24233;
      bool x24239 = x24234;
      if (x24234) {
        long x24235 = x24125;
        long x24236 = x22958;
        bool x24237 = x24235 < x24236;
        x24239 = x24237;
      }
      bool x24240 = x24239;
      if (!x24240) break;
      long x24242 = x24125;
      int* x24243 = x22960;
      int x24244 = x24243[x24242];
      long* x24263 = x22980;
      long x24264 = x24263[x24242];
      long* x24265 = x22982;
      long x24266 = x24265[x24242];
      long* x24267 = x22984;
      long x24268 = x24267[x24242];
      char** x24271 = x22988;
      char* x24272 = x24271[x24242];
      x24125 = x24125 + 1;
      bool x24277 = x24268 < 19950101L;
      bool x24279 = x24277;
      if (x24277) {
        bool x24278 = x24266 < 19950101L;
        x24279 = x24278;
      }
      bool x24280 = x24279;
      bool x24282 = x24280;
      if (x24280) {
        bool x24281 = x24264 < 19950101L;
        x24282 = x24281;
      }
      bool x24283 = x24282;
      bool x24285 = x24283;
      if (x24283) {
        bool x24284 = x24264 < x24266;
        x24285 = x24284;
      }
      bool x24286 = x24285;
      bool x24288 = x24286;
      if (x24286) {
        bool x24287 = x24266 < x24268;
        x24288 = x24287;
      }
      bool x24289 = x24288;
      bool x24291 = x24289;
      if (x24289) {
        bool x24290 = x24268 >= 19940101L;
        x24291 = x24290;
      }
      bool x24292 = x24291;
      bool x24297 = x24292;
      if (x24292) {
        bool x24293 = tpch_strcmp(x24272,"MAIL") == 0;;
        bool x24295 = x24293;
        if (x24293 == false) {
          bool x24294 = tpch_strcmp(x24272,"SHIP") == 0;;
          x24295 = x24294;
        }
        bool x24296 = x24295;
        x24297 = x24296;
      }
      bool x24298 = x24297;
      if (x24298) {
        long x24299 = x24244 & x2212;
        long x24300 = x24147[x24299];
        long x24301 = x24300;
        for (;;) {
          long x24302 = x24301;
          bool x24303 = x24302 != -1;
          if (!x24303) break;
          long x24305 = x24301;
          int* x24306 = x24129;
          int x24307 = x24306[x24305];
          char** x24316 = x24139;
          char* x24317 = x24316[x24305];
          long x24325 = x24148[x24305];
          x24301 = x24325;
          bool x24327 = x24307 == x24244;
          if (x24327) {
            long x24331 = hash(x24272, 10L);
            long x24332 = x24331 & x823;
            long x24333 = x24332;
            struct Anon793459755* x24334 = x24156;
            struct Anon793459755 x24335 = x24334[x24332];
            struct Anon793459755 x24336 = x24335;
            bool x24337 = x24335.exists;;
            bool x24342 = x24337;
            if (x24337) {
              struct Anon793459755 x24338 = x24336;
              char* x24339 = x24338.key;;
              bool x24340 = tpch_strcmp(x24339,x24272) == 0;;
              x24342 = x24340;
            }
            bool x24343 = x24342;
            if (x24343) {
              struct Anon189208763 x24344 = x24335.aggs;;
              char* x24360 = x24335.key;;
              bool x24345 = tpch_strcmp(x24317,"1-URGENT") == 0;;
              bool x24347 = x24345;
              if (x24345 == false) {
                bool x24346 = tpch_strcmp(x24317,"2-HIGH") == 0;;
                x24347 = x24346;
              }
              bool x24348 = x24347;
              double x24351;
              if (x24348) {
                double x24349 = x24344._0;;
                double x24350 = x24349 + 1.0;
                x24351 = x24350;
              } else {
                double x24349 = x24344._0;;
                x24351 = x24349;
              }
              bool x24352 = tpch_strcmp(x24317,"1-URGENT") != 0;;
              bool x24354 = x24352;
              if (x24352) {
                bool x24353 = tpch_strcmp(x24317,"2-HIGH") != 0;;
                x24354 = x24353;
              }
              bool x24355 = x24354;
              double x24358;
              if (x24355) {
                double x24356 = x24344._1;;
                double x24357 = x24356 + 1.0;
                x24358 = x24357;
              } else {
                double x24356 = x24344._1;;
                x24358 = x24356;
              }
              struct Anon189208763 x24359;
              x24359._0 = x24351;
              x24359._1 = x24358;
              struct Anon793459755 x24361;
              x24361.exists = true;
              x24361.key = x24360;
              x24361.aggs = x24359;
              x24334[x24332] = x24361;
            } else {
              bool x24345 = tpch_strcmp(x24317,"1-URGENT") == 0;;
              bool x24347 = x24345;
              if (x24345 == false) {
                bool x24346 = tpch_strcmp(x24317,"2-HIGH") == 0;;
                x24347 = x24346;
              }
              bool x24348 = x24347;
              bool x24352 = tpch_strcmp(x24317,"1-URGENT") != 0;;
              bool x24354 = x24352;
              if (x24352) {
                bool x24353 = tpch_strcmp(x24317,"2-HIGH") != 0;;
                x24354 = x24353;
              }
              bool x24355 = x24354;
              double x24397;
              if (x24348) {
                x24397 = 1.0;
              } else {
                x24397 = 0.0;
              }
              double x24399;
              if (x24355) {
                x24399 = 1.0;
              } else {
                x24399 = 0.0;
              }
              struct Anon189208763 x24400;
              x24400._0 = x24397;
              x24400._1 = x24399;
              struct Anon793459755 x24401;
              x24401.exists = true;
              x24401.key = x24272;
              x24401.aggs = x24400;
              for (;;) {
                struct Anon793459755 x24364 = x24336;
                bool x24365 = x24364.exists;;
                bool x24410;
                if (x24365) {
                  char* x24366 = x24364.key;;
                  bool x24367 = tpch_strcmp(x24366,x24272) == 0;;
                  bool x24393;
                  if (x24367) {
                    struct Anon189208763 x24368 = x24364.aggs;;
                    long x24378 = x24333;
                    struct Anon793459755* x24380 = x24156;
                    double x24372;
                    if (x24348) {
                      double x24370 = x24368._0;;
                      double x24371 = x24370 + 1.0;
                      x24372 = x24371;
                    } else {
                      double x24370 = x24368._0;;
                      x24372 = x24370;
                    }
                    double x24376;
                    if (x24355) {
                      double x24374 = x24368._1;;
                      double x24375 = x24374 + 1.0;
                      x24376 = x24375;
                    } else {
                      double x24374 = x24368._1;;
                      x24376 = x24374;
                    }
                    struct Anon189208763 x24377;
                    x24377._0 = x24372;
                    x24377._1 = x24376;
                    struct Anon793459755 x24379;
                    x24379.exists = true;
                    x24379.key = x24366;
                    x24379.aggs = x24377;
                    x24380[x24378] = x24379;
                    x24393 = false;
                  } else {
                    long x24383 = x24333;
                    long x24384 = x24383 + 1L;
                    long x24385 = x24384 & x823;
                    x24333 = x24385;
                    struct Anon793459755* x24387 = x24156;
                    struct Anon793459755 x24388 = x24387[x24385];
                    x24336 = x24388;
                    x24393 = true;
                  }
                  x24410 = x24393;
                } else {
                  long x24395 = x24333;
                  struct Anon793459755* x24402 = x24156;
                  x24402[x24395] = x24401;
                  long x24404 = x24157;
                  x24158[x24404] = x24395;
                  x24157 = x24157 + 1L;
                  x24410 = false;
                }
                if (!x24410) break;
              }
            }
          } else {
          }
        }
      } else {
      }
    }
    long x24425 = x24157;
    long x24427;
    for(x24427=0L; x24427 < x24425; x24427++) {
      long x24428 = x24158[x24427];
      struct Anon793459755* x24429 = x24156;
      struct Anon793459755 x24430 = x24429[x24428];
      long x24431 = x24170;
      long x24432 = x24169;
      bool x24433 = x24431 == x24432;
      if (x24433) {
        long x24434 = x24432 * 4L;
        x24169 = x24434;
        struct Anon793459755* x24436 = x24172;
        struct Anon793459755* x24437 = (struct Anon793459755 *)realloc(x24436,x24434* sizeof(struct Anon793459755));
        x24172 = x24437;
      } else {
      }
      struct Anon793459755* x24441 = x24172;
      x24441[x24431] = x24430;
      x24170 = x24170 + 1;
    }
    long x24446 = x24170;
    struct Anon793459755* x24447 = x24172;
    qsort((void *)x24447,x24446,sizeof(struct Anon793459755), (__compar_fn_t)x24456); // x24457
    long x24459;
    for(x24459=0L; x24459 < x24446; x24459++) {
      struct Anon793459755* x24460 = x24172;
      struct Anon793459755 x24461 = x24460[x24459];
      if (x1043) {
      } else {
        char* x24464 = x24461.key;;
        struct Anon189208763 x24466 = x24461.aggs;;
        int x24465 = tpch_strlen(x24464);
        double x24467 = x24466._0;;
        double x24468 = x24466._1;;
        printf("%.*s|%.0f|%.0f\n",x24465,x24464,x24467,x24468);
        x24174 = x24174 + 1L;
      }
    }
    long x24475 = x24174;
    printf("(%ld rows)\n",x24475);
    gettimeofday(&x24479, NULL);
    timeval_subtract(&x24480, &x24479, &x24478);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x24480.tv_sec * 1000) + (x24480.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
