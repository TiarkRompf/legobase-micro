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
      

struct Anon603726677 {
bool exists;
char* key;
double aggs;
};

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

struct Anon0 {
int k;
struct Anon102935935Anon168903330 data;
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

struct Anon1851986981 {
int k;
struct Anon65967395 data;
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

struct Anon1395358962 {
int PS_PARTKEY;
int PS_SUPPKEY;
int PS_AVAILQTY;
double PS_SUPPLYCOST;
char* PS_COMMENT;
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

/************************ MAIN BODY **************************/
int main(int x30024, char** x30025) {
  long x30026 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x30027 = x7;
  long x30028 = 0L;
  int* x30031 = (int*)malloc(x7 * sizeof(int));
  int* x30032 = x30031;
  double* x30037 = (double*)malloc(x7 * sizeof(double));
  double* x30038 = x30037;
  double* x30039 = (double*)malloc(x7 * sizeof(double));
  double* x30040 = x30039;
  int x3 = open("XXXXXlineitem.tbl",0);
  long x4 = fsize(x3);
  char* x5 = mmap(0, x4, PROT_READ, MAP_FILE | MAP_SHARED, x3, 0);
  for (;;) {
    long x30061 = x30026;
    bool x30062 = x30061 < x4;
    if (!x30062) break;
    for (;;) {
      long x30066 = x30026;
      char x30067 = x5[x30066];
      bool x30068 = x30067 != '|';
      bool x30073 = x30068;
      if (x30068) {
        long x30069 = x30026;
        char x30070 = x5[x30069];
        bool x30071 = x30070 != '\n';
        x30073 = x30071;
      }
      bool x30074 = x30073;
      if (!x30074) break;
      x30026 = x30026 + 1;
    }
    x30026 = x30026 + 1;
    int x30089 = 0;
    for (;;) {
      long x30090 = x30026;
      char x30091 = x5[x30090];
      bool x30092 = x30091 != '|';
      bool x30097 = x30092;
      if (x30092) {
        long x30093 = x30026;
        char x30094 = x5[x30093];
        bool x30095 = x30094 != '\n';
        x30097 = x30095;
      }
      bool x30098 = x30097;
      if (!x30098) break;
      int x30100 = x30089;
      long x30102 = x30026;
      int x30101 = x30100 * 10;
      char x30103 = x5[x30102];
      char x30104 = x30103 - '0';
      int x30105 = x30101 + x30104;
      x30089 = x30105;
      x30026 = x30026 + 1;
    }
    x30026 = x30026 + 1;
    int x30111 = x30089;
    for (;;) {
      long x30114 = x30026;
      char x30115 = x5[x30114];
      bool x30116 = x30115 != '|';
      bool x30121 = x30116;
      if (x30116) {
        long x30117 = x30026;
        char x30118 = x5[x30117];
        bool x30119 = x30118 != '\n';
        x30121 = x30119;
      }
      bool x30122 = x30121;
      if (!x30122) break;
      x30026 = x30026 + 1;
    }
    x30026 = x30026 + 1;
    for (;;) {
      long x30138 = x30026;
      char x30139 = x5[x30138];
      bool x30140 = x30139 != '|';
      bool x30145 = x30140;
      if (x30140) {
        long x30141 = x30026;
        char x30142 = x5[x30141];
        bool x30143 = x30142 != '\n';
        x30145 = x30143;
      }
      bool x30146 = x30145;
      if (!x30146) break;
      x30026 = x30026 + 1;
    }
    x30026 = x30026 + 1;
    int x30161 = 0;
    int x30162 = 1;
    for (;;) {
      long x30163 = x30026;
      char x30164 = x5[x30163];
      bool x30165 = x30164 != '.';
      bool x30170 = x30165;
      if (x30165) {
        long x30166 = x30026;
        char x30167 = x5[x30166];
        bool x30168 = x30167 != '|';
        x30170 = x30168;
      }
      bool x30171 = x30170;
      bool x30176 = x30171;
      if (x30171) {
        long x30172 = x30026;
        char x30173 = x5[x30172];
        bool x30174 = x30173 != '\n';
        x30176 = x30174;
      }
      bool x30177 = x30176;
      if (!x30177) break;
      int x30179 = x30161;
      long x30181 = x30026;
      int x30180 = x30179 * 10;
      char x30182 = x5[x30181];
      char x30183 = x30182 - '0';
      int x30184 = x30180 + x30183;
      x30161 = x30184;
      x30026 = x30026 + 1;
    }
    long x30189 = x30026;
    char x30190 = x5[x30189];
    bool x30191 = x30190 == '.';
    if (x30191) {
      x30026 = x30026 + 1;
      for (;;) {
        long x30193 = x30026;
        char x30194 = x5[x30193];
        bool x30195 = x30194 != '|';
        bool x30200 = x30195;
        if (x30195) {
          long x30196 = x30026;
          char x30197 = x5[x30196];
          bool x30198 = x30197 != '\n';
          x30200 = x30198;
        }
        bool x30201 = x30200;
        if (!x30201) break;
        int x30203 = x30161;
        long x30205 = x30026;
        int x30204 = x30203 * 10;
        char x30206 = x5[x30205];
        char x30207 = x30206 - '0';
        int x30208 = x30204 + x30207;
        x30161 = x30208;
        int x30210 = x30162;
        int x30211 = x30210 * 10;
        x30162 = x30211;
        x30026 = x30026 + 1;
      }
    } else {
    }
    x30026 = x30026 + 1;
    int x30220 = x30161;
    int x30222 = x30162;
    int x30226 = 0;
    int x30227 = 1;
    for (;;) {
      long x30228 = x30026;
      char x30229 = x5[x30228];
      bool x30230 = x30229 != '.';
      bool x30235 = x30230;
      if (x30230) {
        long x30231 = x30026;
        char x30232 = x5[x30231];
        bool x30233 = x30232 != '|';
        x30235 = x30233;
      }
      bool x30236 = x30235;
      bool x30241 = x30236;
      if (x30236) {
        long x30237 = x30026;
        char x30238 = x5[x30237];
        bool x30239 = x30238 != '\n';
        x30241 = x30239;
      }
      bool x30242 = x30241;
      if (!x30242) break;
      int x30244 = x30226;
      long x30246 = x30026;
      int x30245 = x30244 * 10;
      char x30247 = x5[x30246];
      char x30248 = x30247 - '0';
      int x30249 = x30245 + x30248;
      x30226 = x30249;
      x30026 = x30026 + 1;
    }
    long x30254 = x30026;
    char x30255 = x5[x30254];
    bool x30256 = x30255 == '.';
    if (x30256) {
      x30026 = x30026 + 1;
      for (;;) {
        long x30258 = x30026;
        char x30259 = x5[x30258];
        bool x30260 = x30259 != '|';
        bool x30265 = x30260;
        if (x30260) {
          long x30261 = x30026;
          char x30262 = x5[x30261];
          bool x30263 = x30262 != '\n';
          x30265 = x30263;
        }
        bool x30266 = x30265;
        if (!x30266) break;
        int x30268 = x30226;
        long x30270 = x30026;
        int x30269 = x30268 * 10;
        char x30271 = x5[x30270];
        char x30272 = x30271 - '0';
        int x30273 = x30269 + x30272;
        x30226 = x30273;
        int x30275 = x30227;
        int x30276 = x30275 * 10;
        x30227 = x30276;
        x30026 = x30026 + 1;
      }
    } else {
    }
    x30026 = x30026 + 1;
    int x30285 = x30226;
    int x30287 = x30227;
    for (;;) {
      long x30293 = x30026;
      char x30294 = x5[x30293];
      bool x30295 = x30294 != '.';
      bool x30300 = x30295;
      if (x30295) {
        long x30296 = x30026;
        char x30297 = x5[x30296];
        bool x30298 = x30297 != '|';
        x30300 = x30298;
      }
      bool x30301 = x30300;
      bool x30306 = x30301;
      if (x30301) {
        long x30302 = x30026;
        char x30303 = x5[x30302];
        bool x30304 = x30303 != '\n';
        x30306 = x30304;
      }
      bool x30307 = x30306;
      if (!x30307) break;
      x30026 = x30026 + 1;
    }
    long x30319 = x30026;
    char x30320 = x5[x30319];
    bool x30321 = x30320 == '.';
    if (x30321) {
      x30026 = x30026 + 1;
      for (;;) {
        long x30323 = x30026;
        char x30324 = x5[x30323];
        bool x30325 = x30324 != '|';
        bool x30330 = x30325;
        if (x30325) {
          long x30326 = x30026;
          char x30327 = x5[x30326];
          bool x30328 = x30327 != '\n';
          x30330 = x30328;
        }
        bool x30331 = x30330;
        if (!x30331) break;
        x30026 = x30026 + 1;
      }
    } else {
    }
    x30026 = x30026 + 1;
    for (;;) {
      long x30358 = x30026;
      char x30359 = x5[x30358];
      bool x30360 = x30359 != '.';
      bool x30365 = x30360;
      if (x30360) {
        long x30361 = x30026;
        char x30362 = x5[x30361];
        bool x30363 = x30362 != '|';
        x30365 = x30363;
      }
      bool x30366 = x30365;
      bool x30371 = x30366;
      if (x30366) {
        long x30367 = x30026;
        char x30368 = x5[x30367];
        bool x30369 = x30368 != '\n';
        x30371 = x30369;
      }
      bool x30372 = x30371;
      if (!x30372) break;
      x30026 = x30026 + 1;
    }
    long x30384 = x30026;
    char x30385 = x5[x30384];
    bool x30386 = x30385 == '.';
    if (x30386) {
      x30026 = x30026 + 1;
      for (;;) {
        long x30388 = x30026;
        char x30389 = x5[x30388];
        bool x30390 = x30389 != '|';
        bool x30395 = x30390;
        if (x30390) {
          long x30391 = x30026;
          char x30392 = x5[x30391];
          bool x30393 = x30392 != '\n';
          x30395 = x30393;
        }
        bool x30396 = x30395;
        if (!x30396) break;
        x30026 = x30026 + 1;
      }
    } else {
    }
    x30026 = x30026 + 1;
    x30026 = x30026 + 2;
    x30026 = x30026 + 2;
    for (;;) {
      long x30428 = x30026;
      char x30429 = x5[x30428];
      bool x30430 = x30429 != '-';
      bool x30435 = x30430;
      if (x30430) {
        long x30431 = x30026;
        char x30432 = x5[x30431];
        bool x30433 = x30432 != '\n';
        x30435 = x30433;
      }
      bool x30436 = x30435;
      if (!x30436) break;
      x30026 = x30026 + 1;
    }
    x30026 = x30026 + 1;
    for (;;) {
      long x30452 = x30026;
      char x30453 = x5[x30452];
      bool x30454 = x30453 != '-';
      bool x30459 = x30454;
      if (x30454) {
        long x30455 = x30026;
        char x30456 = x5[x30455];
        bool x30457 = x30456 != '\n';
        x30459 = x30457;
      }
      bool x30460 = x30459;
      if (!x30460) break;
      x30026 = x30026 + 1;
    }
    x30026 = x30026 + 1;
    for (;;) {
      long x30476 = x30026;
      char x30477 = x5[x30476];
      bool x30478 = x30477 != '|';
      bool x30483 = x30478;
      if (x30478) {
        long x30479 = x30026;
        char x30480 = x5[x30479];
        bool x30481 = x30480 != '\n';
        x30483 = x30481;
      }
      bool x30484 = x30483;
      if (!x30484) break;
      x30026 = x30026 + 1;
    }
    x30026 = x30026 + 1;
    for (;;) {
      long x30504 = x30026;
      char x30505 = x5[x30504];
      bool x30506 = x30505 != '-';
      bool x30511 = x30506;
      if (x30506) {
        long x30507 = x30026;
        char x30508 = x5[x30507];
        bool x30509 = x30508 != '\n';
        x30511 = x30509;
      }
      bool x30512 = x30511;
      if (!x30512) break;
      x30026 = x30026 + 1;
    }
    x30026 = x30026 + 1;
    for (;;) {
      long x30528 = x30026;
      char x30529 = x5[x30528];
      bool x30530 = x30529 != '-';
      bool x30535 = x30530;
      if (x30530) {
        long x30531 = x30026;
        char x30532 = x5[x30531];
        bool x30533 = x30532 != '\n';
        x30535 = x30533;
      }
      bool x30536 = x30535;
      if (!x30536) break;
      x30026 = x30026 + 1;
    }
    x30026 = x30026 + 1;
    for (;;) {
      long x30552 = x30026;
      char x30553 = x5[x30552];
      bool x30554 = x30553 != '|';
      bool x30559 = x30554;
      if (x30554) {
        long x30555 = x30026;
        char x30556 = x5[x30555];
        bool x30557 = x30556 != '\n';
        x30559 = x30557;
      }
      bool x30560 = x30559;
      if (!x30560) break;
      x30026 = x30026 + 1;
    }
    x30026 = x30026 + 1;
    for (;;) {
      long x30580 = x30026;
      char x30581 = x5[x30580];
      bool x30582 = x30581 != '-';
      bool x30587 = x30582;
      if (x30582) {
        long x30583 = x30026;
        char x30584 = x5[x30583];
        bool x30585 = x30584 != '\n';
        x30587 = x30585;
      }
      bool x30588 = x30587;
      if (!x30588) break;
      x30026 = x30026 + 1;
    }
    x30026 = x30026 + 1;
    for (;;) {
      long x30604 = x30026;
      char x30605 = x5[x30604];
      bool x30606 = x30605 != '-';
      bool x30611 = x30606;
      if (x30606) {
        long x30607 = x30026;
        char x30608 = x5[x30607];
        bool x30609 = x30608 != '\n';
        x30611 = x30609;
      }
      bool x30612 = x30611;
      if (!x30612) break;
      x30026 = x30026 + 1;
    }
    x30026 = x30026 + 1;
    for (;;) {
      long x30628 = x30026;
      char x30629 = x5[x30628];
      bool x30630 = x30629 != '|';
      bool x30635 = x30630;
      if (x30630) {
        long x30631 = x30026;
        char x30632 = x5[x30631];
        bool x30633 = x30632 != '\n';
        x30635 = x30633;
      }
      bool x30636 = x30635;
      if (!x30636) break;
      x30026 = x30026 + 1;
    }
    x30026 = x30026 + 1;
    for (;;) {
      long x30655 = x30026;
      char x30656 = x5[x30655];
      bool x30657 = x30656 != '|';
      bool x30662 = x30657;
      if (x30657) {
        long x30658 = x30026;
        char x30659 = x5[x30658];
        bool x30660 = x30659 != '\n';
        x30662 = x30660;
      }
      bool x30663 = x30662;
      if (!x30663) break;
      x30026 = x30026 + 1;
    }
    x30026 = x30026 + 1;
    for (;;) {
      long x30673 = x30026;
      char x30674 = x5[x30673];
      bool x30675 = x30674 != '|';
      bool x30680 = x30675;
      if (x30675) {
        long x30676 = x30026;
        char x30677 = x5[x30676];
        bool x30678 = x30677 != '\n';
        x30680 = x30678;
      }
      bool x30681 = x30680;
      if (!x30681) break;
      x30026 = x30026 + 1;
    }
    x30026 = x30026 + 1;
    for (;;) {
      long x30691 = x30026;
      char x30692 = x5[x30691];
      bool x30693 = x30692 != '|';
      bool x30698 = x30693;
      if (x30693) {
        long x30694 = x30026;
        char x30695 = x5[x30694];
        bool x30696 = x30695 != '\n';
        x30698 = x30696;
      }
      bool x30699 = x30698;
      if (!x30699) break;
      x30026 = x30026 + 1;
    }
    x30026 = x30026 + 1;
    long x30709 = x30026;
    bool x30710 = x30709 > 0L;
    bool x30716 = x30710;
    if (x30710) {
      long x30711 = x30026;
      long x30712 = x30711 - 1L;
      char x30713 = x5[x30712];
      bool x30714 = x30713 != '\n';
      x30716 = x30714;
    }
    bool x30717 = x30716;
    if (x30717) {
      for (;;) {
        long x30718 = x30026;
        char x30719 = x5[x30718];
        bool x30720 = x30719 != '\n';
        if (!x30720) break;
        x30026 = x30026 + 1;
      }
    } else {
    }
    x30026 = x30026 + 1;
    long x30729 = x30028;
    long x30730 = x30027;
    bool x30731 = x30729 == x30730;
    if (x30731) {
      long x30732 = x30730 * 4L;
      x30027 = x30732;
      printf("buffer.resize %ld\n",x30732);
      int* x30738 = x30032;
      int* x30739 = (int*)realloc(x30738,x30732 * sizeof(int));
      x30032 = x30739;
      double* x30747 = x30038;
      double* x30748 = (double*)realloc(x30747,x30732 * sizeof(double));
      x30038 = x30748;
      double* x30750 = x30040;
      double* x30751 = (double*)realloc(x30750,x30732 * sizeof(double));
      x30040 = x30751;
    } else {
    }
    int* x30787 = x30032;
    x30787[x30729] = x30111;
    double* x30793 = x30038;
    double x30221 = (double)x30220;
    double x30223 = (double)x30222;
    double x30224 = x30221 / x30223;
    x30793[x30729] = x30224;
    double* x30795 = x30040;
    double x30286 = (double)x30285;
    double x30288 = (double)x30287;
    double x30289 = x30286 / x30288;
    x30795[x30729] = x30289;
    x30028 = x30028 + 1;
  }
  long x30820 = 0L;
  long x30821 = x7;
  long x30822 = 0L;
  int* x30823 = (int*)malloc(x7 * sizeof(int));
  int* x30824 = x30823;
  char** x30829 = (char**)malloc(x7 * sizeof(char*));
  char** x30830 = x30829;
  char** x30835 = (char**)malloc(x7 * sizeof(char*));
  char** x30836 = x30835;
  int x1076 = open("XXXXXpart.tbl",0);
  long x1077 = fsize(x1076);
  char* x1078 = mmap(0, x1077, PROT_READ, MAP_FILE | MAP_SHARED, x1076, 0);
  for (;;) {
    long x30842 = x30820;
    bool x30843 = x30842 < x1077;
    if (!x30843) break;
    int x30846 = 0;
    for (;;) {
      long x30847 = x30820;
      char x30848 = x1078[x30847];
      bool x30849 = x30848 != '|';
      bool x30854 = x30849;
      if (x30849) {
        long x30850 = x30820;
        char x30851 = x1078[x30850];
        bool x30852 = x30851 != '\n';
        x30854 = x30852;
      }
      bool x30855 = x30854;
      if (!x30855) break;
      int x30857 = x30846;
      long x30859 = x30820;
      int x30858 = x30857 * 10;
      char x30860 = x1078[x30859];
      char x30861 = x30860 - '0';
      int x30862 = x30858 + x30861;
      x30846 = x30862;
      x30820 = x30820 + 1;
    }
    x30820 = x30820 + 1;
    int x30868 = x30846;
    for (;;) {
      long x30870 = x30820;
      char x30871 = x1078[x30870];
      bool x30872 = x30871 != '|';
      bool x30877 = x30872;
      if (x30872) {
        long x30873 = x30820;
        char x30874 = x1078[x30873];
        bool x30875 = x30874 != '\n';
        x30877 = x30875;
      }
      bool x30878 = x30877;
      if (!x30878) break;
      x30820 = x30820 + 1;
    }
    x30820 = x30820 + 1;
    for (;;) {
      long x30888 = x30820;
      char x30889 = x1078[x30888];
      bool x30890 = x30889 != '|';
      bool x30895 = x30890;
      if (x30890) {
        long x30891 = x30820;
        char x30892 = x1078[x30891];
        bool x30893 = x30892 != '\n';
        x30895 = x30893;
      }
      bool x30896 = x30895;
      if (!x30896) break;
      x30820 = x30820 + 1;
    }
    x30820 = x30820 + 1;
    long x30905 = x30820;
    for (;;) {
      long x30906 = x30820;
      char x30907 = x1078[x30906];
      bool x30908 = x30907 != '|';
      bool x30913 = x30908;
      if (x30908) {
        long x30909 = x30820;
        char x30910 = x1078[x30909];
        bool x30911 = x30910 != '\n';
        x30913 = x30911;
      }
      bool x30914 = x30913;
      if (!x30914) break;
      x30820 = x30820 + 1;
    }
    x30820 = x30820 + 1;
    for (;;) {
      long x30924 = x30820;
      char x30925 = x1078[x30924];
      bool x30926 = x30925 != '|';
      bool x30931 = x30926;
      if (x30926) {
        long x30927 = x30820;
        char x30928 = x1078[x30927];
        bool x30929 = x30928 != '\n';
        x30931 = x30929;
      }
      bool x30932 = x30931;
      if (!x30932) break;
      x30820 = x30820 + 1;
    }
    x30820 = x30820 + 1;
    for (;;) {
      long x30943 = x30820;
      char x30944 = x1078[x30943];
      bool x30945 = x30944 != '|';
      bool x30950 = x30945;
      if (x30945) {
        long x30946 = x30820;
        char x30947 = x1078[x30946];
        bool x30948 = x30947 != '\n';
        x30950 = x30948;
      }
      bool x30951 = x30950;
      if (!x30951) break;
      x30820 = x30820 + 1;
    }
    x30820 = x30820 + 1;
    long x30965 = x30820;
    for (;;) {
      long x30966 = x30820;
      char x30967 = x1078[x30966];
      bool x30968 = x30967 != '|';
      bool x30973 = x30968;
      if (x30968) {
        long x30969 = x30820;
        char x30970 = x1078[x30969];
        bool x30971 = x30970 != '\n';
        x30973 = x30971;
      }
      bool x30974 = x30973;
      if (!x30974) break;
      x30820 = x30820 + 1;
    }
    x30820 = x30820 + 1;
    for (;;) {
      long x30986 = x30820;
      char x30987 = x1078[x30986];
      bool x30988 = x30987 != '.';
      bool x30993 = x30988;
      if (x30988) {
        long x30989 = x30820;
        char x30990 = x1078[x30989];
        bool x30991 = x30990 != '|';
        x30993 = x30991;
      }
      bool x30994 = x30993;
      bool x30999 = x30994;
      if (x30994) {
        long x30995 = x30820;
        char x30996 = x1078[x30995];
        bool x30997 = x30996 != '\n';
        x30999 = x30997;
      }
      bool x31000 = x30999;
      if (!x31000) break;
      x30820 = x30820 + 1;
    }
    long x31012 = x30820;
    char x31013 = x1078[x31012];
    bool x31014 = x31013 == '.';
    if (x31014) {
      x30820 = x30820 + 1;
      for (;;) {
        long x31016 = x30820;
        char x31017 = x1078[x31016];
        bool x31018 = x31017 != '|';
        bool x31023 = x31018;
        if (x31018) {
          long x31019 = x30820;
          char x31020 = x1078[x31019];
          bool x31021 = x31020 != '\n';
          x31023 = x31021;
        }
        bool x31024 = x31023;
        if (!x31024) break;
        x30820 = x30820 + 1;
      }
    } else {
    }
    x30820 = x30820 + 1;
    for (;;) {
      long x31049 = x30820;
      char x31050 = x1078[x31049];
      bool x31051 = x31050 != '|';
      bool x31056 = x31051;
      if (x31051) {
        long x31052 = x30820;
        char x31053 = x1078[x31052];
        bool x31054 = x31053 != '\n';
        x31056 = x31054;
      }
      bool x31057 = x31056;
      if (!x31057) break;
      x30820 = x30820 + 1;
    }
    x30820 = x30820 + 1;
    long x31067 = x30820;
    bool x31068 = x31067 > 0L;
    bool x31074 = x31068;
    if (x31068) {
      long x31069 = x30820;
      long x31070 = x31069 - 1L;
      char x31071 = x1078[x31070];
      bool x31072 = x31071 != '\n';
      x31074 = x31072;
    }
    bool x31075 = x31074;
    if (x31075) {
      for (;;) {
        long x31076 = x30820;
        char x31077 = x1078[x31076];
        bool x31078 = x31077 != '\n';
        if (!x31078) break;
        x30820 = x30820 + 1;
      }
    } else {
    }
    x30820 = x30820 + 1;
    long x31087 = x30822;
    long x31088 = x30821;
    bool x31089 = x31087 == x31088;
    if (x31089) {
      long x31090 = x31088 * 4L;
      x30821 = x31090;
      printf("buffer.resize %ld\n",x31090);
      int* x31093 = x30824;
      int* x31094 = (int*)realloc(x31093,x31090 * sizeof(int));
      x30824 = x31094;
      char** x31102 = x30830;
      char** x31103 = (char**)realloc(x31102,x31090 * sizeof(char*));
      x30830 = x31103;
      char** x31111 = x30836;
      char** x31112 = (char**)realloc(x31111,x31090 * sizeof(char*));
      x30836 = x31112;
    } else {
    }
    int* x31122 = x30824;
    x31122[x31087] = x30868;
    char** x31128 = x30830;
    char* x30922 = x1078+x30905;
    x31128[x31087] = x30922;
    char** x31134 = x30836;
    char* x30982 = x1078+x30965;
    x31134[x31087] = x30982;
    x30822 = x30822 + 1;
  }
  long x2189 = DEFAULT_JOIN_HASH_SIZE;
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  long x2212 = x2189 - 1L;
  long x823 = x808 - 1L;
  bool x1043 = true == false;
  int x31143;
  for(x31143=0; x31143 < 5; x31143++) {
    bool x31144 = false;
    long x31145 = 0L;
    bool x31146 = false;
    long x31147 = 0L;
    int* x31150 = (int*)malloc(x2189 * sizeof(int));
    int* x31151 = x31150;
    long x31168 = 0L;
    long* x31169 = (long*)malloc(x2189 * sizeof(long));
    long* x31170 = (long*)malloc(x2189 * sizeof(long));
    long x31171;
    for(x31171=0L; x31171 < x2189; x31171++) {
      x31169[x31171] = -1L;
    }
    int* x31177 = (int*)malloc(x2189 * sizeof(int));
    int* x31178 = x31177;
    double* x31205 = (double*)malloc(x2189 * sizeof(double));
    double* x31206 = x31205;
    double* x31207 = (double*)malloc(x2189 * sizeof(double));
    double* x31208 = x31207;
    long x31229 = 0L;
    long* x31230 = (long*)malloc(x2189 * sizeof(long));
    long* x31231 = (long*)malloc(x2189 * sizeof(long));
    long x31232;
    for(x31232=0L; x31232 < x2189; x31232++) {
      x31230[x31232] = -1L;
    }
    int* x31236 = (int*)malloc(x2189 * sizeof(int));
    int* x31237 = x31236;
    long x31238 = 0L;
    long* x31239 = (long*)malloc(x2189 * sizeof(long));
    long* x31240 = (long*)malloc(x2189 * sizeof(long));
    long x31241;
    for(x31241=0L; x31241 < x2189; x31241++) {
      x31239[x31241] = -1L;
    }
    struct Anon603726677* x31246 = (struct Anon603726677*)malloc(x808 * sizeof(struct Anon603726677));
    struct Anon603726677* x31247 = x31246;
    long x31248 = 0L;
    long* x31249 = (long*)malloc(x808 * sizeof(long));
    long x31250;
    for(x31250=0L; x31250 < x808; x31250++) {
      struct Anon603726677* x31251 = x31247;
      struct Anon603726677 x31252 = x31251[x31250];
      char* x31253 = x31252.key;;
      double x31254 = x31252.aggs;;
      struct Anon603726677 x31255;
      x31255.exists = false;
      x31255.key = x31253;
      x31255.aggs = x31254;
      x31251[x31250] = x31255;
    }
    long x31260 = 0L;
    struct timeval x31810, x31811, x31812;
    gettimeofday(&x31810, NULL);
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x31262 = x31146;
      bool x31263 = !x31262;
      bool x31268 = x31263;
      if (x31263) {
        long x31264 = x31147;
        long x31265 = x30822;
        bool x31266 = x31264 < x31265;
        x31268 = x31266;
      }
      bool x31269 = x31268;
      if (!x31269) break;
      long x31271 = x31147;
      int* x31272 = x30824;
      int x31273 = x31272[x31271];
      char** x31278 = x30830;
      char* x31279 = x31278[x31271];
      char** x31284 = x30836;
      char* x31285 = x31284[x31271];
      x31147 = x31147 + 1;
      bool x31292 = tpch_strcmp(x31285,"MED BOX") == 0;;
      bool x31294 = x31292;
      if (x31292) {
        bool x31293 = tpch_strcmp(x31279,"Brand#23") == 0;;
        x31294 = x31293;
      }
      bool x31295 = x31294;
      if (x31295) {
        long x31296 = x31168;
        int* x31297 = x31151;
        x31297[x31296] = x31273;
        x31168 = x31168 + 1L;
        long x31316 = x31273 & x2212;
        long x31317 = x31169[x31316];
        x31169[x31316] = x31296;
        x31170[x31296] = x31317;
      } else {
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x31325 = x31144;
      bool x31326 = !x31325;
      bool x31331 = x31326;
      if (x31326) {
        long x31327 = x31145;
        long x31328 = x30028;
        bool x31329 = x31327 < x31328;
        x31331 = x31329;
      }
      bool x31332 = x31331;
      if (!x31332) break;
      long x31334 = x31145;
      int* x31337 = x30032;
      int x31338 = x31337[x31334];
      double* x31343 = x30038;
      double x31344 = x31343[x31334];
      double* x31345 = x30040;
      double x31346 = x31345[x31334];
      x31145 = x31145 + 1;
      long x31369 = x31338 & x2212;
      long x31370 = x31169[x31369];
      long x31371 = x31370;
      for (;;) {
        long x31372 = x31371;
        bool x31373 = x31372 != -1;
        if (!x31373) break;
        long x31375 = x31371;
        int* x31376 = x31151;
        int x31377 = x31376[x31375];
        long x31395 = x31170[x31375];
        x31371 = x31395;
        bool x31397 = x31377 == x31338;
        if (x31397) {
          long x31401 = x31239[x31369];
          long x31402 = x31401;
          bool x31403 = x31401 == -1L;
          bool x31404 = x31403;
          for (;;) {
            bool x31405 = x31404;
            bool x31406 = !x31405;
            if (!x31406) break;
            long x31408 = x31402;
            int* x31409 = x31237;
            int x31410 = x31409[x31408];
            bool x31411 = x31410 == x31338;
            if (x31411) {
              x31404 = true;
            } else {
              long x31414 = x31240[x31408];
              x31402 = x31414;
              bool x31416 = x31414 == -1;
              x31404 = x31416;
            }
          }
          long x31422 = x31402;
          bool x31423 = x31422 == -1;
          if (x31423) {
            long x31424 = x31238;
            int* x31425 = x31237;
            x31425[x31424] = x31338;
            x31238 = x31238 + 1L;
            x31239[x31369] = x31424;
            x31240[x31424] = x31401;
          } else {
          }
          long x31434 = x31229;
          int* x31435 = x31178;
          x31435[x31434] = x31338;
          double* x31463 = x31206;
          x31463[x31434] = x31344;
          double* x31465 = x31208;
          x31465[x31434] = x31346;
          x31229 = x31229 + 1L;
          long x31488 = x31230[x31369];
          x31230[x31369] = x31434;
          x31231[x31434] = x31488;
        } else {
        }
      }
    }
    long x31497;
    for(x31497=0L; x31497 < x2189; x31497++) {
      long x31498 = x31239[x31497];
      long x31499 = x31498;
      for (;;) {
        long x31500 = x31499;
        bool x31501 = x31500 != -1;
        if (!x31501) break;
        long x31503 = x31499;
        int* x31504 = x31237;
        int x31505 = x31504[x31503];
        long x31506 = x31240[x31503];
        x31499 = x31506;
        long x31509 = 0L;
        long x31510 = x31505 & x2212;
        long x31511 = x31230[x31510];
        long x31512 = x31511;
        for (;;) {
          long x31513 = x31512;
          bool x31514 = x31513 != -1;
          if (!x31514) break;
          long x31516 = x31512;
          int* x31517 = x31178;
          int x31518 = x31517[x31516];
          long x31571 = x31231[x31516];
          x31512 = x31571;
          bool x31573 = x31505 == x31518;
          if (x31573) {
            x31509 = x31509 + 1L;
          } else {
          }
        }
        double x31579 = 0.0;
        long x31580 = x31511;
        for (;;) {
          long x31581 = x31580;
          bool x31582 = x31581 != -1;
          if (!x31582) break;
          long x31584 = x31580;
          int* x31585 = x31178;
          int x31586 = x31585[x31584];
          double* x31613 = x31206;
          double x31614 = x31613[x31584];
          long x31639 = x31231[x31584];
          x31580 = x31639;
          bool x31641 = x31505 == x31586;
          if (x31641) {
            double x31642 = x31579;
            double x31643 = x31642 + x31614;
            x31579 = x31643;
          } else {
          }
        }
        double x31649 = x31579;
        long x31650 = x31509;
        double x31654 = 0.0;
        long x31655 = x31511;
        double x31651 = (double)x31650;
        double x31652 = x31649 / x31651;
        double x31653 = 0.2 * x31652;
        for (;;) {
          long x31656 = x31655;
          bool x31657 = x31656 != -1;
          if (!x31657) break;
          long x31659 = x31655;
          int* x31660 = x31178;
          int x31661 = x31660[x31659];
          double* x31688 = x31206;
          double x31689 = x31688[x31659];
          double* x31690 = x31208;
          double x31691 = x31690[x31659];
          long x31714 = x31231[x31659];
          x31655 = x31714;
          bool x31716 = x31505 == x31661;
          if (x31716) {
            double x31717 = x31654;
            bool x31718 = x31689 < x31653;
            double x31720;
            if (x31718) {
              double x31719 = x31717 + x31691;
              x31720 = x31719;
            } else {
              x31720 = x31717;
            }
            x31654 = x31720;
          } else {
          }
        }
        double x31726 = x31654;
        long x31729 = hash("Total", 10L);
        long x31730 = x31729 & x823;
        long x31731 = x31730;
        struct Anon603726677* x31732 = x31247;
        struct Anon603726677 x31733 = x31732[x31730];
        struct Anon603726677 x31734 = x31733;
        bool x31735 = x31733.exists;;
        bool x31740 = x31735;
        if (x31735) {
          struct Anon603726677 x31736 = x31734;
          char* x31737 = x31736.key;;
          bool x31738 = tpch_strcmp(x31737,"Total") == 0;;
          x31740 = x31738;
        }
        bool x31741 = x31740;
        if (x31741) {
          double x31742 = x31733.aggs;;
          char* x31744 = x31733.key;;
          double x31727 = x31726 / 7.0;
          double x31743 = x31742 + x31727;
          struct Anon603726677 x31745;
          x31745.exists = true;
          x31745.key = x31744;
          x31745.aggs = x31743;
          x31732[x31730] = x31745;
        } else {
          double x31727 = x31726 / 7.0;
          struct Anon603726677 x31772;
          x31772.exists = true;
          x31772.key = "Total";
          x31772.aggs = x31727;
          for (;;) {
            struct Anon603726677 x31748 = x31734;
            bool x31749 = x31748.exists;;
            bool x31781;
            if (x31749) {
              char* x31750 = x31748.key;;
              bool x31751 = tpch_strcmp(x31750,"Total") == 0;;
              bool x31769;
              if (x31751) {
                double x31752 = x31748.aggs;;
                long x31754 = x31731;
                struct Anon603726677* x31756 = x31247;
                double x31753 = x31752 + x31727;
                struct Anon603726677 x31755;
                x31755.exists = true;
                x31755.key = x31750;
                x31755.aggs = x31753;
                x31756[x31754] = x31755;
                x31769 = false;
              } else {
                long x31759 = x31731;
                long x31760 = x31759 + 1L;
                long x31761 = x31760 & x823;
                x31731 = x31761;
                struct Anon603726677* x31763 = x31247;
                struct Anon603726677 x31764 = x31763[x31761];
                x31734 = x31764;
                x31769 = true;
              }
              x31781 = x31769;
            } else {
              long x31771 = x31731;
              struct Anon603726677* x31773 = x31247;
              x31773[x31771] = x31772;
              long x31775 = x31248;
              x31249[x31775] = x31771;
              x31248 = x31248 + 1L;
              x31781 = false;
            }
            if (!x31781) break;
          }
        }
      }
    }
    long x31792 = x31248;
    long x31794;
    for(x31794=0L; x31794 < x31792; x31794++) {
      long x31795 = x31249[x31794];
      struct Anon603726677* x31796 = x31247;
      struct Anon603726677 x31797 = x31796[x31795];
      if (x1043) {
      } else {
        double x31800 = x31797.aggs;;
        printf("%.6f\n",x31800);
        x31260 = x31260 + 1L;
      }
    }
    long x31807 = x31260;
    printf("(%ld rows)\n",x31807);
    gettimeofday(&x31811, NULL);
    timeval_subtract(&x31812, &x31811, &x31810);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x31812.tv_sec * 1000) + (x31812.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
