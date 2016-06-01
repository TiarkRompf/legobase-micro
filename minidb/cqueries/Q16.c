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

struct Anon102935935Anon1395358962 {
int P_PARTKEY;
char* P_NAME;
char* P_MFGR;
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
char* P_CONTAINER;
double P_RETAILPRICE;
char* P_COMMENT;
int PS_PARTKEY;
int PS_SUPPKEY;
int PS_AVAILQTY;
double PS_SUPPLYCOST;
char* PS_COMMENT;
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

struct Anon1268892766Anon592699416 {
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
int key;
struct Anon2052879266 aggs;
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

struct Anon1395358962 {
int PS_PARTKEY;
int PS_SUPPKEY;
int PS_AVAILQTY;
double PS_SUPPLYCOST;
char* PS_COMMENT;
};

struct Anon0 {
struct Anon102935935 left;
struct Anon1395358962 right;
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

struct Anon668992598 {
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
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

struct Anon1978526630 {
char* P_BRAND;
char* P_TYPE;
int P_SIZE;
int PS_SUPPKEY;
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

struct Anon284281085 {
bool exists;
struct Anon668992598 key;
struct Anon2052879266 aggs;
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

struct Anon1638440139 {
bool exists;
struct Anon1978526630 key;
struct Anon2052879266 aggs;
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

struct Anon592699416 {
int key;
struct Anon2052879266 aggs;
};

/************************ FUNCTIONS **************************/
int x29988(struct Anon284281085* x29951, struct Anon284281085* x29952);
int x29988(struct Anon284281085* x29951, struct Anon284281085* x29952) {
  struct Anon284281085 x29953 = (*x29951);
  struct Anon284281085 x29954 = (*x29952);
  struct Anon2052879266 x29955 = x29953.aggs;;
  double x29956 = x29955._0;;
  struct Anon2052879266 x29957 = x29954.aggs;;
  double x29958 = x29957._0;;
  bool x29959 = x29956 < x29958;
  int x29986;
  if (x29959) {
    x29986 = 1;
  } else {
    bool x29960 = x29956 > x29958;
    int x29985;
    if (x29960) {
      x29985 = -1;
    } else {
      struct Anon668992598 x29961 = x29953.key;;
      char* x29962 = x29961.P_BRAND;;
      struct Anon668992598 x29963 = x29954.key;;
      char* x29964 = x29963.P_BRAND;;
      int x29965 = tpch_strcmp(x29962,x29964);
      int x29966 = x29965;
      bool x29967 = x29965 == 0;
      if (x29967) {
        char* x29968 = x29961.P_TYPE;;
        char* x29969 = x29963.P_TYPE;;
        int x29970 = tpch_strcmp(x29968,x29969);
        x29966 = x29970;
        bool x29972 = x29970 == 0;
        if (x29972) {
          int x29973 = x29961.P_SIZE;;
          int x29974 = x29963.P_SIZE;;
          int x29975 = x29973 - x29974;
          x29966 = x29975;
        } else {
        }
      } else {
      }
      int x29982 = x29966;
      x29985 = x29982;
    }
    x29986 = x29985;
  }
  return x29986;
}

/************************ MAIN BODY **************************/
int main(int x28573, char** x28574) {
  long x28575 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x28576 = x7;
  long x28577 = 0L;
  int* x28578 = (int*)malloc(x7 * sizeof(int));
  int* x28579 = x28578;
  char** x28590 = (char**)malloc(x7 * sizeof(char*));
  char** x28591 = x28590;
  int x1908 = open("XXXXXsupplier.tbl",0);
  long x1909 = fsize(x1908);
  char* x1910 = mmap(0, x1909, PROT_READ, MAP_FILE | MAP_SHARED, x1908, 0);
  for (;;) {
    long x28592 = x28575;
    bool x28593 = x28592 < x1909;
    if (!x28593) break;
    int x28596 = 0;
    for (;;) {
      long x28597 = x28575;
      char x28598 = x1910[x28597];
      bool x28599 = x28598 != '|';
      bool x28604 = x28599;
      if (x28599) {
        long x28600 = x28575;
        char x28601 = x1910[x28600];
        bool x28602 = x28601 != '\n';
        x28604 = x28602;
      }
      bool x28605 = x28604;
      if (!x28605) break;
      int x28607 = x28596;
      long x28609 = x28575;
      int x28608 = x28607 * 10;
      char x28610 = x1910[x28609];
      char x28611 = x28610 - '0';
      int x28612 = x28608 + x28611;
      x28596 = x28612;
      x28575 = x28575 + 1;
    }
    x28575 = x28575 + 1;
    int x28618 = x28596;
    for (;;) {
      long x28620 = x28575;
      char x28621 = x1910[x28620];
      bool x28622 = x28621 != '|';
      bool x28627 = x28622;
      if (x28622) {
        long x28623 = x28575;
        char x28624 = x1910[x28623];
        bool x28625 = x28624 != '\n';
        x28627 = x28625;
      }
      bool x28628 = x28627;
      if (!x28628) break;
      x28575 = x28575 + 1;
    }
    x28575 = x28575 + 1;
    for (;;) {
      long x28638 = x28575;
      char x28639 = x1910[x28638];
      bool x28640 = x28639 != '|';
      bool x28645 = x28640;
      if (x28640) {
        long x28641 = x28575;
        char x28642 = x1910[x28641];
        bool x28643 = x28642 != '\n';
        x28645 = x28643;
      }
      bool x28646 = x28645;
      if (!x28646) break;
      x28575 = x28575 + 1;
    }
    x28575 = x28575 + 1;
    for (;;) {
      long x28657 = x28575;
      char x28658 = x1910[x28657];
      bool x28659 = x28658 != '|';
      bool x28664 = x28659;
      if (x28659) {
        long x28660 = x28575;
        char x28661 = x1910[x28660];
        bool x28662 = x28661 != '\n';
        x28664 = x28662;
      }
      bool x28665 = x28664;
      if (!x28665) break;
      x28575 = x28575 + 1;
    }
    x28575 = x28575 + 1;
    for (;;) {
      long x28680 = x28575;
      char x28681 = x1910[x28680];
      bool x28682 = x28681 != '|';
      bool x28687 = x28682;
      if (x28682) {
        long x28683 = x28575;
        char x28684 = x1910[x28683];
        bool x28685 = x28684 != '\n';
        x28687 = x28685;
      }
      bool x28688 = x28687;
      if (!x28688) break;
      x28575 = x28575 + 1;
    }
    x28575 = x28575 + 1;
    for (;;) {
      long x28700 = x28575;
      char x28701 = x1910[x28700];
      bool x28702 = x28701 != '.';
      bool x28707 = x28702;
      if (x28702) {
        long x28703 = x28575;
        char x28704 = x1910[x28703];
        bool x28705 = x28704 != '|';
        x28707 = x28705;
      }
      bool x28708 = x28707;
      bool x28713 = x28708;
      if (x28708) {
        long x28709 = x28575;
        char x28710 = x1910[x28709];
        bool x28711 = x28710 != '\n';
        x28713 = x28711;
      }
      bool x28714 = x28713;
      if (!x28714) break;
      x28575 = x28575 + 1;
    }
    long x28726 = x28575;
    char x28727 = x1910[x28726];
    bool x28728 = x28727 == '.';
    if (x28728) {
      x28575 = x28575 + 1;
      for (;;) {
        long x28730 = x28575;
        char x28731 = x1910[x28730];
        bool x28732 = x28731 != '|';
        bool x28737 = x28732;
        if (x28732) {
          long x28733 = x28575;
          char x28734 = x1910[x28733];
          bool x28735 = x28734 != '\n';
          x28737 = x28735;
        }
        bool x28738 = x28737;
        if (!x28738) break;
        x28575 = x28575 + 1;
      }
    } else {
    }
    x28575 = x28575 + 1;
    long x28762 = x28575;
    for (;;) {
      long x28763 = x28575;
      char x28764 = x1910[x28763];
      bool x28765 = x28764 != '|';
      bool x28770 = x28765;
      if (x28765) {
        long x28766 = x28575;
        char x28767 = x1910[x28766];
        bool x28768 = x28767 != '\n';
        x28770 = x28768;
      }
      bool x28771 = x28770;
      if (!x28771) break;
      x28575 = x28575 + 1;
    }
    x28575 = x28575 + 1;
    long x28781 = x28575;
    bool x28782 = x28781 > 0L;
    bool x28788 = x28782;
    if (x28782) {
      long x28783 = x28575;
      long x28784 = x28783 - 1L;
      char x28785 = x1910[x28784];
      bool x28786 = x28785 != '\n';
      x28788 = x28786;
    }
    bool x28789 = x28788;
    if (x28789) {
      for (;;) {
        long x28790 = x28575;
        char x28791 = x1910[x28790];
        bool x28792 = x28791 != '\n';
        if (!x28792) break;
        x28575 = x28575 + 1;
      }
    } else {
    }
    x28575 = x28575 + 1;
    long x28801 = x28577;
    long x28802 = x28576;
    bool x28803 = x28801 == x28802;
    if (x28803) {
      long x28804 = x28802 * 4L;
      x28576 = x28804;
      printf("buffer.resize %ld\n",x28804);
      int* x28807 = x28579;
      int* x28808 = (int*)realloc(x28807,x28804 * sizeof(int));
      x28579 = x28808;
      char** x28825 = x28591;
      char** x28826 = (char**)realloc(x28825,x28804 * sizeof(char*));
      x28591 = x28826;
    } else {
    }
    int* x28830 = x28579;
    x28830[x28801] = x28618;
    char** x28842 = x28591;
    char* x28779 = x1910+x28762;
    x28842[x28801] = x28779;
    x28577 = x28577 + 1;
  }
  long x28847 = 0L;
  long x28848 = x7;
  long x28849 = 0L;
  int* x28850 = (int*)malloc(x7 * sizeof(int));
  int* x28851 = x28850;
  char** x28856 = (char**)malloc(x7 * sizeof(char*));
  char** x28857 = x28856;
  char** x28858 = (char**)malloc(x7 * sizeof(char*));
  char** x28859 = x28858;
  int* x28860 = (int*)malloc(x7 * sizeof(int));
  int* x28861 = x28860;
  int x1076 = open("XXXXXpart.tbl",0);
  long x1077 = fsize(x1076);
  char* x1078 = mmap(0, x1077, PROT_READ, MAP_FILE | MAP_SHARED, x1076, 0);
  for (;;) {
    long x28869 = x28847;
    bool x28870 = x28869 < x1077;
    if (!x28870) break;
    int x28873 = 0;
    for (;;) {
      long x28874 = x28847;
      char x28875 = x1078[x28874];
      bool x28876 = x28875 != '|';
      bool x28881 = x28876;
      if (x28876) {
        long x28877 = x28847;
        char x28878 = x1078[x28877];
        bool x28879 = x28878 != '\n';
        x28881 = x28879;
      }
      bool x28882 = x28881;
      if (!x28882) break;
      int x28884 = x28873;
      long x28886 = x28847;
      int x28885 = x28884 * 10;
      char x28887 = x1078[x28886];
      char x28888 = x28887 - '0';
      int x28889 = x28885 + x28888;
      x28873 = x28889;
      x28847 = x28847 + 1;
    }
    x28847 = x28847 + 1;
    int x28895 = x28873;
    for (;;) {
      long x28897 = x28847;
      char x28898 = x1078[x28897];
      bool x28899 = x28898 != '|';
      bool x28904 = x28899;
      if (x28899) {
        long x28900 = x28847;
        char x28901 = x1078[x28900];
        bool x28902 = x28901 != '\n';
        x28904 = x28902;
      }
      bool x28905 = x28904;
      if (!x28905) break;
      x28847 = x28847 + 1;
    }
    x28847 = x28847 + 1;
    for (;;) {
      long x28915 = x28847;
      char x28916 = x1078[x28915];
      bool x28917 = x28916 != '|';
      bool x28922 = x28917;
      if (x28917) {
        long x28918 = x28847;
        char x28919 = x1078[x28918];
        bool x28920 = x28919 != '\n';
        x28922 = x28920;
      }
      bool x28923 = x28922;
      if (!x28923) break;
      x28847 = x28847 + 1;
    }
    x28847 = x28847 + 1;
    long x28932 = x28847;
    for (;;) {
      long x28933 = x28847;
      char x28934 = x1078[x28933];
      bool x28935 = x28934 != '|';
      bool x28940 = x28935;
      if (x28935) {
        long x28936 = x28847;
        char x28937 = x1078[x28936];
        bool x28938 = x28937 != '\n';
        x28940 = x28938;
      }
      bool x28941 = x28940;
      if (!x28941) break;
      x28847 = x28847 + 1;
    }
    x28847 = x28847 + 1;
    long x28950 = x28847;
    for (;;) {
      long x28951 = x28847;
      char x28952 = x1078[x28951];
      bool x28953 = x28952 != '|';
      bool x28958 = x28953;
      if (x28953) {
        long x28954 = x28847;
        char x28955 = x1078[x28954];
        bool x28956 = x28955 != '\n';
        x28958 = x28956;
      }
      bool x28959 = x28958;
      if (!x28959) break;
      x28847 = x28847 + 1;
    }
    x28847 = x28847 + 1;
    int x28969 = 0;
    for (;;) {
      long x28970 = x28847;
      char x28971 = x1078[x28970];
      bool x28972 = x28971 != '|';
      bool x28977 = x28972;
      if (x28972) {
        long x28973 = x28847;
        char x28974 = x1078[x28973];
        bool x28975 = x28974 != '\n';
        x28977 = x28975;
      }
      bool x28978 = x28977;
      if (!x28978) break;
      int x28980 = x28969;
      long x28982 = x28847;
      int x28981 = x28980 * 10;
      char x28983 = x1078[x28982];
      char x28984 = x28983 - '0';
      int x28985 = x28981 + x28984;
      x28969 = x28985;
      x28847 = x28847 + 1;
    }
    x28847 = x28847 + 1;
    int x28991 = x28969;
    for (;;) {
      long x28993 = x28847;
      char x28994 = x1078[x28993];
      bool x28995 = x28994 != '|';
      bool x29000 = x28995;
      if (x28995) {
        long x28996 = x28847;
        char x28997 = x1078[x28996];
        bool x28998 = x28997 != '\n';
        x29000 = x28998;
      }
      bool x29001 = x29000;
      if (!x29001) break;
      x28847 = x28847 + 1;
    }
    x28847 = x28847 + 1;
    for (;;) {
      long x29013 = x28847;
      char x29014 = x1078[x29013];
      bool x29015 = x29014 != '.';
      bool x29020 = x29015;
      if (x29015) {
        long x29016 = x28847;
        char x29017 = x1078[x29016];
        bool x29018 = x29017 != '|';
        x29020 = x29018;
      }
      bool x29021 = x29020;
      bool x29026 = x29021;
      if (x29021) {
        long x29022 = x28847;
        char x29023 = x1078[x29022];
        bool x29024 = x29023 != '\n';
        x29026 = x29024;
      }
      bool x29027 = x29026;
      if (!x29027) break;
      x28847 = x28847 + 1;
    }
    long x29039 = x28847;
    char x29040 = x1078[x29039];
    bool x29041 = x29040 == '.';
    if (x29041) {
      x28847 = x28847 + 1;
      for (;;) {
        long x29043 = x28847;
        char x29044 = x1078[x29043];
        bool x29045 = x29044 != '|';
        bool x29050 = x29045;
        if (x29045) {
          long x29046 = x28847;
          char x29047 = x1078[x29046];
          bool x29048 = x29047 != '\n';
          x29050 = x29048;
        }
        bool x29051 = x29050;
        if (!x29051) break;
        x28847 = x28847 + 1;
      }
    } else {
    }
    x28847 = x28847 + 1;
    for (;;) {
      long x29076 = x28847;
      char x29077 = x1078[x29076];
      bool x29078 = x29077 != '|';
      bool x29083 = x29078;
      if (x29078) {
        long x29079 = x28847;
        char x29080 = x1078[x29079];
        bool x29081 = x29080 != '\n';
        x29083 = x29081;
      }
      bool x29084 = x29083;
      if (!x29084) break;
      x28847 = x28847 + 1;
    }
    x28847 = x28847 + 1;
    long x29094 = x28847;
    bool x29095 = x29094 > 0L;
    bool x29101 = x29095;
    if (x29095) {
      long x29096 = x28847;
      long x29097 = x29096 - 1L;
      char x29098 = x1078[x29097];
      bool x29099 = x29098 != '\n';
      x29101 = x29099;
    }
    bool x29102 = x29101;
    if (x29102) {
      for (;;) {
        long x29103 = x28847;
        char x29104 = x1078[x29103];
        bool x29105 = x29104 != '\n';
        if (!x29105) break;
        x28847 = x28847 + 1;
      }
    } else {
    }
    x28847 = x28847 + 1;
    long x29114 = x28849;
    long x29115 = x28848;
    bool x29116 = x29114 == x29115;
    if (x29116) {
      long x29117 = x29115 * 4L;
      x28848 = x29117;
      printf("buffer.resize %ld\n",x29117);
      int* x29120 = x28851;
      int* x29121 = (int*)realloc(x29120,x29117 * sizeof(int));
      x28851 = x29121;
      char** x29129 = x28857;
      char** x29130 = (char**)realloc(x29129,x29117 * sizeof(char*));
      x28857 = x29130;
      char** x29132 = x28859;
      char** x29133 = (char**)realloc(x29132,x29117 * sizeof(char*));
      x28859 = x29133;
      int* x29135 = x28861;
      int* x29136 = (int*)realloc(x29135,x29117 * sizeof(int));
      x28861 = x29136;
    } else {
    }
    int* x29149 = x28851;
    x29149[x29114] = x28895;
    char** x29155 = x28857;
    char* x28949 = x1078+x28932;
    x29155[x29114] = x28949;
    char** x29157 = x28859;
    char* x28967 = x1078+x28950;
    x29157[x29114] = x28967;
    int* x29159 = x28861;
    x29159[x29114] = x28991;
    x28849 = x28849 + 1;
  }
  long x29170 = 0L;
  long x29171 = x7;
  long x29172 = 0L;
  int* x29173 = (int*)malloc(x7 * sizeof(int));
  int* x29174 = x29173;
  int* x29175 = (int*)malloc(x7 * sizeof(int));
  int* x29176 = x29175;
  int x1402 = open("XXXXXpartsupp.tbl",0);
  long x1403 = fsize(x1402);
  char* x1404 = mmap(0, x1403, PROT_READ, MAP_FILE | MAP_SHARED, x1402, 0);
  for (;;) {
    long x29183 = x29170;
    bool x29184 = x29183 < x1403;
    if (!x29184) break;
    int x29187 = 0;
    for (;;) {
      long x29188 = x29170;
      char x29189 = x1404[x29188];
      bool x29190 = x29189 != '|';
      bool x29195 = x29190;
      if (x29190) {
        long x29191 = x29170;
        char x29192 = x1404[x29191];
        bool x29193 = x29192 != '\n';
        x29195 = x29193;
      }
      bool x29196 = x29195;
      if (!x29196) break;
      int x29198 = x29187;
      long x29200 = x29170;
      int x29199 = x29198 * 10;
      char x29201 = x1404[x29200];
      char x29202 = x29201 - '0';
      int x29203 = x29199 + x29202;
      x29187 = x29203;
      x29170 = x29170 + 1;
    }
    x29170 = x29170 + 1;
    int x29209 = x29187;
    int x29211 = 0;
    for (;;) {
      long x29212 = x29170;
      char x29213 = x1404[x29212];
      bool x29214 = x29213 != '|';
      bool x29219 = x29214;
      if (x29214) {
        long x29215 = x29170;
        char x29216 = x1404[x29215];
        bool x29217 = x29216 != '\n';
        x29219 = x29217;
      }
      bool x29220 = x29219;
      if (!x29220) break;
      int x29222 = x29211;
      long x29224 = x29170;
      int x29223 = x29222 * 10;
      char x29225 = x1404[x29224];
      char x29226 = x29225 - '0';
      int x29227 = x29223 + x29226;
      x29211 = x29227;
      x29170 = x29170 + 1;
    }
    x29170 = x29170 + 1;
    int x29233 = x29211;
    for (;;) {
      long x29236 = x29170;
      char x29237 = x1404[x29236];
      bool x29238 = x29237 != '|';
      bool x29243 = x29238;
      if (x29238) {
        long x29239 = x29170;
        char x29240 = x1404[x29239];
        bool x29241 = x29240 != '\n';
        x29243 = x29241;
      }
      bool x29244 = x29243;
      if (!x29244) break;
      x29170 = x29170 + 1;
    }
    x29170 = x29170 + 1;
    for (;;) {
      long x29261 = x29170;
      char x29262 = x1404[x29261];
      bool x29263 = x29262 != '.';
      bool x29268 = x29263;
      if (x29263) {
        long x29264 = x29170;
        char x29265 = x1404[x29264];
        bool x29266 = x29265 != '|';
        x29268 = x29266;
      }
      bool x29269 = x29268;
      bool x29274 = x29269;
      if (x29269) {
        long x29270 = x29170;
        char x29271 = x1404[x29270];
        bool x29272 = x29271 != '\n';
        x29274 = x29272;
      }
      bool x29275 = x29274;
      if (!x29275) break;
      x29170 = x29170 + 1;
    }
    long x29287 = x29170;
    char x29288 = x1404[x29287];
    bool x29289 = x29288 == '.';
    if (x29289) {
      x29170 = x29170 + 1;
      for (;;) {
        long x29291 = x29170;
        char x29292 = x1404[x29291];
        bool x29293 = x29292 != '|';
        bool x29298 = x29293;
        if (x29293) {
          long x29294 = x29170;
          char x29295 = x1404[x29294];
          bool x29296 = x29295 != '\n';
          x29298 = x29296;
        }
        bool x29299 = x29298;
        if (!x29299) break;
        x29170 = x29170 + 1;
      }
    } else {
    }
    x29170 = x29170 + 1;
    for (;;) {
      long x29324 = x29170;
      char x29325 = x1404[x29324];
      bool x29326 = x29325 != '|';
      bool x29331 = x29326;
      if (x29326) {
        long x29327 = x29170;
        char x29328 = x1404[x29327];
        bool x29329 = x29328 != '\n';
        x29331 = x29329;
      }
      bool x29332 = x29331;
      if (!x29332) break;
      x29170 = x29170 + 1;
    }
    x29170 = x29170 + 1;
    long x29342 = x29170;
    bool x29343 = x29342 > 0L;
    bool x29349 = x29343;
    if (x29343) {
      long x29344 = x29170;
      long x29345 = x29344 - 1L;
      char x29346 = x1404[x29345];
      bool x29347 = x29346 != '\n';
      x29349 = x29347;
    }
    bool x29350 = x29349;
    if (x29350) {
      for (;;) {
        long x29351 = x29170;
        char x29352 = x1404[x29351];
        bool x29353 = x29352 != '\n';
        if (!x29353) break;
        x29170 = x29170 + 1;
      }
    } else {
    }
    x29170 = x29170 + 1;
    long x29362 = x29172;
    long x29363 = x29171;
    bool x29364 = x29362 == x29363;
    if (x29364) {
      long x29365 = x29363 * 4L;
      x29171 = x29365;
      printf("buffer.resize %ld\n",x29365);
      int* x29368 = x29174;
      int* x29369 = (int*)realloc(x29368,x29365 * sizeof(int));
      x29174 = x29369;
      int* x29371 = x29176;
      int* x29372 = (int*)realloc(x29371,x29365 * sizeof(int));
      x29176 = x29372;
    } else {
    }
    int* x29385 = x29174;
    x29385[x29362] = x29209;
    int* x29387 = x29176;
    x29387[x29362] = x29233;
    x29172 = x29172 + 1;
  }
  long x2189 = DEFAULT_JOIN_HASH_SIZE;
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  long x2212 = x2189 - 1L;
  long x823 = x808 - 1L;
  struct Anon2052879266 x4385;
  x4385._0 = 0.0;
  struct Anon2052879266 x6304;
  x6304._0 = 1.0;
  int x29398;
  for(x29398=0; x29398 < 5; x29398++) {
    bool x29399 = false;
    long x29400 = 0L;
    bool x29402 = false;
    long x29403 = 0L;
    int* x29405 = (int*)malloc(x2189 * sizeof(int));
    int* x29406 = x29405;
    char** x29411 = (char**)malloc(x2189 * sizeof(char*));
    char** x29412 = x29411;
    char** x29413 = (char**)malloc(x2189 * sizeof(char*));
    char** x29414 = x29413;
    int* x29415 = (int*)malloc(x2189 * sizeof(int));
    int* x29416 = x29415;
    long x29423 = 0L;
    long* x29424 = (long*)malloc(x2189 * sizeof(long));
    long* x29425 = (long*)malloc(x2189 * sizeof(long));
    long x29426;
    for(x29426=0L; x29426 < x2189; x29426++) {
      x29424[x29426] = -1L;
    }
    bool x29431 = false;
    long x29432 = 0L;
    int* x29435 = (int*)malloc(x2189 * sizeof(int));
    int* x29436 = x29435;
    long x29449 = 0L;
    long* x29450 = (long*)malloc(x2189 * sizeof(long));
    long* x29451 = (long*)malloc(x2189 * sizeof(long));
    long x29452;
    for(x29452=0L; x29452 < x2189; x29452++) {
      x29450[x29452] = -1L;
    }
    struct Anon1638440139* x29457 = (struct Anon1638440139*)malloc(x808 * sizeof(struct Anon1638440139));
    struct Anon1638440139* x29458 = x29457;
    long x29459 = 0L;
    long* x29460 = (long*)malloc(x808 * sizeof(long));
    long x29461;
    for(x29461=0L; x29461 < x808; x29461++) {
      struct Anon1638440139* x29462 = x29458;
      struct Anon1638440139 x29463 = x29462[x29461];
      struct Anon1978526630 x29464 = x29463.key;;
      struct Anon2052879266 x29465 = x29463.aggs;;
      struct Anon1638440139 x29466;
      x29466.exists = false;
      x29466.key = x29464;
      x29466.aggs = x29465;
      x29462[x29461] = x29466;
    }
    struct Anon284281085* x29471 = (struct Anon284281085*)malloc(x808 * sizeof(struct Anon284281085));
    struct Anon284281085* x29472 = x29471;
    long x29473 = 0L;
    long* x29474 = (long*)malloc(x808 * sizeof(long));
    long x29475;
    for(x29475=0L; x29475 < x808; x29475++) {
      struct Anon284281085* x29476 = x29472;
      struct Anon284281085 x29477 = x29476[x29475];
      struct Anon668992598 x29478 = x29477.key;;
      struct Anon2052879266 x29479 = x29477.aggs;;
      struct Anon284281085 x29480;
      x29480.exists = false;
      x29480.key = x29478;
      x29480.aggs = x29479;
      x29476[x29475] = x29480;
    }
    long x29485 = 1024L;
    long x29486 = 0L;
    struct Anon284281085* x29487 = (struct Anon284281085*)malloc(1024L * sizeof(struct Anon284281085));
    struct Anon284281085* x29488 = x29487;
    int x29489 = 0;
    long x29491 = 0L;
    struct timeval x30017, x30018, x30019;
    gettimeofday(&x30017, NULL);
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x29493 = x29431;
      bool x29494 = !x29493;
      bool x29499 = x29494;
      if (x29494) {
        long x29495 = x29432;
        long x29496 = x28577;
        bool x29497 = x29495 < x29496;
        x29499 = x29497;
      }
      bool x29500 = x29499;
      if (!x29500) break;
      long x29502 = x29432;
      int* x29503 = x28579;
      int x29504 = x29503[x29502];
      char** x29515 = x28591;
      char* x29516 = x29515[x29502];
      x29432 = x29432 + 1;
      int x29519 = tpch_strstr(&(x29516[0]),"Customer") - x29516;
      if (x29519 < 0) x29519 = -1;
      bool x29521 = x29519 == -1;
      bool x29525;
      if (x29521) {
        x29525 = false;
      } else {
        int x29522 = x29519 + 8;
        int x29523 = tpch_strstr(&(x29516[x29522]),"Complaints") - x29516;
        if (x29523 < 0) x29523 = -1;
        bool x29524 = x29523 != -1;
        x29525 = x29524;
      }
      if (x29525) {
        long x29526 = x29449;
        int* x29527 = x29436;
        x29527[x29526] = x29504;
        x29449 = x29449 + 1L;
        long x29542 = x29504 & x2212;
        long x29543 = x29450[x29542];
        x29450[x29542] = x29526;
        x29451[x29526] = x29543;
      } else {
      }
    }
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x29551 = x29399;
      bool x29552 = !x29551;
      bool x29557 = x29552;
      if (x29552) {
        long x29553 = x29400;
        long x29554 = x28849;
        bool x29555 = x29553 < x29554;
        x29557 = x29555;
      }
      bool x29558 = x29557;
      if (!x29558) break;
      long x29560 = x29400;
      int* x29561 = x28851;
      int x29562 = x29561[x29560];
      char** x29567 = x28857;
      char* x29568 = x29567[x29560];
      char** x29569 = x28859;
      char* x29570 = x29569[x29560];
      int* x29571 = x28861;
      int x29572 = x29571[x29560];
      x29400 = x29400 + 1;
      bool x29581 = tpch_strcmp(x29568,"Brand#45") != 0;;
      bool x29584 = x29581;
      if (x29581) {
        bool x29582 = strncmp(x29570,"MEDIUM POLISHED", tpch_strlen("MEDIUM POLISHED")) == 0;;
        bool x29583 = !x29582;
        x29584 = x29583;
      }
      bool x29585 = x29584;
      bool x29608 = x29585;
      if (x29585) {
        bool x29586 = x29572 == 49;
        bool x29588 = x29586;
        if (x29586 == false) {
          bool x29587 = x29572 == 14;
          x29588 = x29587;
        }
        bool x29589 = x29588;
        bool x29591 = x29589;
        if (x29589 == false) {
          bool x29590 = x29572 == 23;
          x29591 = x29590;
        }
        bool x29592 = x29591;
        bool x29594 = x29592;
        if (x29592 == false) {
          bool x29593 = x29572 == 45;
          x29594 = x29593;
        }
        bool x29595 = x29594;
        bool x29597 = x29595;
        if (x29595 == false) {
          bool x29596 = x29572 == 19;
          x29597 = x29596;
        }
        bool x29598 = x29597;
        bool x29600 = x29598;
        if (x29598 == false) {
          bool x29599 = x29572 == 3;
          x29600 = x29599;
        }
        bool x29601 = x29600;
        bool x29603 = x29601;
        if (x29601 == false) {
          bool x29602 = x29572 == 36;
          x29603 = x29602;
        }
        bool x29604 = x29603;
        bool x29606 = x29604;
        if (x29604 == false) {
          bool x29605 = x29572 == 9;
          x29606 = x29605;
        }
        bool x29607 = x29606;
        x29608 = x29607;
      }
      bool x29609 = x29608;
      if (x29609) {
        long x29610 = x29423;
        int* x29611 = x29406;
        x29611[x29610] = x29562;
        char** x29617 = x29412;
        x29617[x29610] = x29568;
        char** x29619 = x29414;
        x29619[x29610] = x29570;
        int* x29621 = x29416;
        x29621[x29610] = x29572;
        x29423 = x29423 + 1L;
        long x29630 = x29562 & x2212;
        long x29631 = x29424[x29630];
        x29424[x29630] = x29610;
        x29425[x29610] = x29631;
      } else {
      }
    }
    printf("%s\n","begin scan PARTSUPP");
    for (;;) {
      bool x29639 = x29402;
      bool x29640 = !x29639;
      bool x29645 = x29640;
      if (x29640) {
        long x29641 = x29403;
        long x29642 = x29172;
        bool x29643 = x29641 < x29642;
        x29645 = x29643;
      }
      bool x29646 = x29645;
      if (!x29646) break;
      long x29648 = x29403;
      int* x29649 = x29174;
      int x29650 = x29649[x29648];
      int* x29651 = x29176;
      int x29652 = x29651[x29648];
      x29403 = x29403 + 1;
      long x29661 = x29650 & x2212;
      long x29662 = x29424[x29661];
      long x29663 = x29662;
      long x29693 = x29652 & x2212;
      long x29733 = x29652 * 41L;
      for (;;) {
        long x29664 = x29663;
        bool x29665 = x29664 != -1;
        if (!x29665) break;
        long x29667 = x29663;
        int* x29668 = x29406;
        int x29669 = x29668[x29667];
        char** x29674 = x29412;
        char* x29675 = x29674[x29667];
        char** x29676 = x29414;
        char* x29677 = x29676[x29667];
        int* x29678 = x29416;
        int x29679 = x29678[x29667];
        long x29687 = x29425[x29667];
        x29663 = x29687;
        bool x29689 = x29669 == x29650;
        if (x29689) {
          long x29694 = x29450[x29693];
          long x29695 = x29694;
          bool x29696 = x29694 == -1L;
          bool x29697 = x29696;
          for (;;) {
            bool x29698 = x29697;
            bool x29699 = !x29698;
            if (!x29699) break;
            long x29701 = x29695;
            int* x29702 = x29436;
            int x29703 = x29702[x29701];
            bool x29717 = x29652 == x29703;
            if (x29717) {
              x29697 = true;
            } else {
              long x29720 = x29451[x29701];
              x29695 = x29720;
              bool x29722 = x29720 == -1;
              x29697 = x29722;
            }
          }
          long x29728 = x29695;
          bool x29729 = x29728 == -1;
          if (x29729) {
            long x29731 = hash(x29675, 10L);
            long x29732 = hash(x29677, 10L);
            long x29734 = x29733 + x29731;
            long x29735 = x29734 * 41L;
            long x29736 = x29735 + x29679;
            long x29737 = x29736 * 41L;
            long x29738 = x29737 + x29732;
            long x29739 = x29738 & x823;
            long x29740 = x29739;
            struct Anon1638440139* x29741 = x29458;
            struct Anon1638440139 x29742 = x29741[x29739];
            struct Anon1638440139 x29743 = x29742;
            bool x29744 = x29742.exists;;
            bool x29762 = x29744;
            if (x29744) {
              struct Anon1638440139 x29745 = x29743;
              struct Anon1978526630 x29746 = x29745.key;;
              char* x29747 = x29746.P_BRAND;;
              bool x29748 = tpch_strcmp(x29747,x29675) == 0;;
              bool x29755 = x29748;
              if (x29748) {
                char* x29749 = x29746.P_TYPE;;
                bool x29750 = tpch_strcmp(x29749,x29677) == 0;;
                x29755 = x29750;
              }
              bool x29756 = x29755;
              bool x29757 = x29756;
              if (x29756) {
                int x29751 = x29746.P_SIZE;;
                bool x29752 = x29751 == x29679;
                x29757 = x29752;
              }
              bool x29758 = x29757;
              bool x29759 = x29758;
              if (x29758) {
                int x29753 = x29746.PS_SUPPKEY;;
                bool x29754 = x29753 == x29652;
                x29759 = x29754;
              }
              bool x29760 = x29759;
              x29762 = x29760;
            }
            bool x29763 = x29762;
            if (x29763) {
              struct Anon2052879266 x29764 = x29742.aggs;;
              struct Anon1978526630 x29765 = x29742.key;;
              struct Anon1638440139 x29766;
              x29766.exists = true;
              x29766.key = x29765;
              x29766.aggs = x29764;
              x29741[x29739] = x29766;
            } else {
              struct Anon1978526630 x29730;
              x29730.P_BRAND = x29675;
              x29730.P_TYPE = x29677;
              x29730.P_SIZE = x29679;
              x29730.PS_SUPPKEY = x29652;
              struct Anon1638440139 x29805;
              x29805.exists = true;
              x29805.key = x29730;
              x29805.aggs = x4385;
              for (;;) {
                struct Anon1638440139 x29769 = x29743;
                bool x29770 = x29769.exists;;
                bool x29814;
                if (x29770) {
                  struct Anon1978526630 x29771 = x29769.key;;
                  char* x29772 = x29771.P_BRAND;;
                  bool x29773 = tpch_strcmp(x29772,x29675) == 0;;
                  bool x29780 = x29773;
                  if (x29773) {
                    char* x29774 = x29771.P_TYPE;;
                    bool x29775 = tpch_strcmp(x29774,x29677) == 0;;
                    x29780 = x29775;
                  }
                  bool x29781 = x29780;
                  bool x29782 = x29781;
                  if (x29781) {
                    int x29776 = x29771.P_SIZE;;
                    bool x29777 = x29776 == x29679;
                    x29782 = x29777;
                  }
                  bool x29783 = x29782;
                  bool x29784 = x29783;
                  if (x29783) {
                    int x29778 = x29771.PS_SUPPKEY;;
                    bool x29779 = x29778 == x29652;
                    x29784 = x29779;
                  }
                  bool x29785 = x29784;
                  bool x29802;
                  if (x29785) {
                    struct Anon2052879266 x29786 = x29769.aggs;;
                    long x29787 = x29740;
                    struct Anon1638440139* x29789 = x29458;
                    struct Anon1638440139 x29788;
                    x29788.exists = true;
                    x29788.key = x29771;
                    x29788.aggs = x29786;
                    x29789[x29787] = x29788;
                    x29802 = false;
                  } else {
                    long x29792 = x29740;
                    long x29793 = x29792 + 1L;
                    long x29794 = x29793 & x823;
                    x29740 = x29794;
                    struct Anon1638440139* x29796 = x29458;
                    struct Anon1638440139 x29797 = x29796[x29794];
                    x29743 = x29797;
                    x29802 = true;
                  }
                  x29814 = x29802;
                } else {
                  long x29804 = x29740;
                  struct Anon1638440139* x29806 = x29458;
                  x29806[x29804] = x29805;
                  long x29808 = x29459;
                  x29460[x29808] = x29804;
                  x29459 = x29459 + 1L;
                  x29814 = false;
                }
                if (!x29814) break;
              }
            }
          } else {
          }
        } else {
        }
      }
    }
    long x29829 = x29459;
    long x29831;
    for(x29831=0L; x29831 < x29829; x29831++) {
      long x29832 = x29460[x29831];
      struct Anon1638440139* x29833 = x29458;
      struct Anon1638440139 x29834 = x29833[x29832];
      struct Anon1978526630 x29835 = x29834.key;;
      char* x29836 = x29835.P_BRAND;;
      long x29840 = hash(x29836, 10L);
      char* x29837 = x29835.P_TYPE;;
      long x29841 = hash(x29837, 10L);
      int x29838 = x29835.P_SIZE;;
      long x29842 = x29840 * 41L;
      long x29843 = x29842 + x29838;
      long x29844 = x29843 * 41L;
      long x29845 = x29844 + x29841;
      long x29846 = x29845 & x823;
      long x29847 = x29846;
      struct Anon284281085* x29848 = x29472;
      struct Anon284281085 x29849 = x29848[x29846];
      struct Anon284281085 x29850 = x29849;
      bool x29851 = x29849.exists;;
      bool x29865 = x29851;
      if (x29851) {
        struct Anon284281085 x29852 = x29850;
        struct Anon668992598 x29853 = x29852.key;;
        char* x29854 = x29853.P_BRAND;;
        bool x29855 = tpch_strcmp(x29854,x29836) == 0;;
        bool x29860 = x29855;
        if (x29855) {
          char* x29856 = x29853.P_TYPE;;
          bool x29857 = tpch_strcmp(x29856,x29837) == 0;;
          x29860 = x29857;
        }
        bool x29861 = x29860;
        bool x29862 = x29861;
        if (x29861) {
          int x29858 = x29853.P_SIZE;;
          bool x29859 = x29858 == x29838;
          x29862 = x29859;
        }
        bool x29863 = x29862;
        x29865 = x29863;
      }
      bool x29866 = x29865;
      if (x29866) {
        struct Anon2052879266 x29867 = x29849.aggs;;
        struct Anon668992598 x29871 = x29849.key;;
        double x29868 = x29867._0;;
        double x29869 = x29868 + 1.0;
        struct Anon2052879266 x29870;
        x29870._0 = x29869;
        struct Anon284281085 x29872;
        x29872.exists = true;
        x29872.key = x29871;
        x29872.aggs = x29870;
        x29848[x29846] = x29872;
      } else {
        struct Anon668992598 x29839;
        x29839.P_BRAND = x29836;
        x29839.P_TYPE = x29837;
        x29839.P_SIZE = x29838;
        struct Anon284281085 x29910;
        x29910.exists = true;
        x29910.key = x29839;
        x29910.aggs = x6304;
        for (;;) {
          struct Anon284281085 x29875 = x29850;
          bool x29876 = x29875.exists;;
          bool x29919;
          if (x29876) {
            struct Anon668992598 x29877 = x29875.key;;
            char* x29878 = x29877.P_BRAND;;
            bool x29879 = tpch_strcmp(x29878,x29836) == 0;;
            bool x29884 = x29879;
            if (x29879) {
              char* x29880 = x29877.P_TYPE;;
              bool x29881 = tpch_strcmp(x29880,x29837) == 0;;
              x29884 = x29881;
            }
            bool x29885 = x29884;
            bool x29886 = x29885;
            if (x29885) {
              int x29882 = x29877.P_SIZE;;
              bool x29883 = x29882 == x29838;
              x29886 = x29883;
            }
            bool x29887 = x29886;
            bool x29907;
            if (x29887) {
              struct Anon2052879266 x29888 = x29875.aggs;;
              long x29892 = x29847;
              struct Anon284281085* x29894 = x29472;
              double x29889 = x29888._0;;
              double x29890 = x29889 + 1.0;
              struct Anon2052879266 x29891;
              x29891._0 = x29890;
              struct Anon284281085 x29893;
              x29893.exists = true;
              x29893.key = x29877;
              x29893.aggs = x29891;
              x29894[x29892] = x29893;
              x29907 = false;
            } else {
              long x29897 = x29847;
              long x29898 = x29897 + 1L;
              long x29899 = x29898 & x823;
              x29847 = x29899;
              struct Anon284281085* x29901 = x29472;
              struct Anon284281085 x29902 = x29901[x29899];
              x29850 = x29902;
              x29907 = true;
            }
            x29919 = x29907;
          } else {
            long x29909 = x29847;
            struct Anon284281085* x29911 = x29472;
            x29911[x29909] = x29910;
            long x29913 = x29473;
            x29474[x29913] = x29909;
            x29473 = x29473 + 1L;
            x29919 = false;
          }
          if (!x29919) break;
        }
      }
    }
    long x29928 = x29473;
    long x29930;
    for(x29930=0L; x29930 < x29928; x29930++) {
      long x29931 = x29474[x29930];
      struct Anon284281085* x29932 = x29472;
      struct Anon284281085 x29933 = x29932[x29931];
      long x29934 = x29486;
      long x29935 = x29485;
      bool x29936 = x29934 == x29935;
      if (x29936) {
        long x29937 = x29935 * 4L;
        x29485 = x29937;
        struct Anon284281085* x29939 = x29488;
        struct Anon284281085* x29940 = (struct Anon284281085 *)realloc(x29939,x29937* sizeof(struct Anon284281085));
        x29488 = x29940;
      } else {
      }
      struct Anon284281085* x29944 = x29488;
      x29944[x29934] = x29933;
      x29486 = x29486 + 1;
    }
    long x29949 = x29486;
    struct Anon284281085* x29950 = x29488;
    qsort((void *)x29950,x29949,sizeof(struct Anon284281085), (__compar_fn_t)x29988); // x29989
    long x29991;
    for(x29991=0L; x29991 < x29949; x29991++) {
      struct Anon284281085* x29992 = x29488;
      struct Anon284281085 x29993 = x29992[x29991];
      int x29994 = x29489;
      bool x29995 = x29994 < 20;
      bool x29996 = x29995 == false;
      if (x29996) {
      } else {
        struct Anon668992598 x29999 = x29993.key;;
        struct Anon2052879266 x30005 = x29993.aggs;;
        char* x30000 = x29999.P_BRAND;;
        int x30001 = tpch_strlen(x30000);
        char* x30002 = x29999.P_TYPE;;
        int x30003 = tpch_strlen(x30002);
        int x30004 = x29999.P_SIZE;;
        double x30006 = x30005._0;;
        printf("%.*s|%.*s|%d|%.0f\n",x30001,x30000,x30003,x30002,x30004,x30006);
        x29489 = x29489 + 1;
        x29491 = x29491 + 1L;
      }
    }
    long x30014 = x29491;
    printf("(%ld rows)\n",x30014);
    gettimeofday(&x30018, NULL);
    timeval_subtract(&x30019, &x30018, &x30017);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x30019.tv_sec * 1000) + (x30019.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
