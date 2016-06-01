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

struct Anon1406772883 {
int N_NATIONKEY;
char* N_NAME;
int N_REGIONKEY;
char* N_COMMENT;
};

struct Anon567626277 {
double _0;
double _1;
double _2;
double _3;
double _4;
double _5;
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

struct Anon850505655Anon1251919804 {
char* REC1_N_NAME;
int REC1_N_NATIONKEY;
long REC2_O_ORDERDATE;
double REC2_L_DISCOUNT;
double REC2_L_EXTENDEDPRICE;
int REC2_S_NATIONKEY;
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

struct Anon2052879266 {
double _0;
};

struct Anon152692660Anon811555534Anon920667905 {
bool exists;
int key;
struct Anon2052879266 aggs;
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

struct Anon1866483359 {
int R_REGIONKEY;
char* R_NAME;
char* R_COMMENT;
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

struct Anon1711779607 {
int C_CUSTKEY;
char* C_NAME;
double C_ACCTBAL;
char* C_PHONE;
char* N_NAME;
char* C_ADDRESS;
char* C_COMMENT;
};

struct Anon1678583810 {
bool exists;
struct Anon1711779607 key;
struct Anon2052879266 aggs;
};

struct Anon2053173900 {
int key;
double wnd;
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

struct Anon1993309635 {
int PS_PARTKEY;
int PS_SUPPKEY;
double PS_AVAILQTY;
};

struct Anon443803923 {
bool exists;
struct Anon1993309635 key;
double aggs;
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

struct Anon152692660Anon811555534 {
bool exists;
int key;
struct Anon2052879266 aggs;
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

struct Anon713865179 {
int N1_N_NATIONKEY;
char* N1_N_NAME;
int N1_N_REGIONKEY;
char* N1_N_COMMENT;
};

struct Anon546410247 {
char* N_NAME;
int N_NATIONKEY;
int O_ORDERKEY;
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

struct Anon1268892766 {
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
};

struct Anon0 {
struct Anon1406772883 left;
struct Anon1268892766 right;
};

struct Anon1495587458 {
int key;
struct Anon1023322325 wnd;
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

struct Anon2101649069 {
bool exists;
struct Anon1548200872 key;
struct Anon2052879266 aggs;
};

struct Anon152692660 {
bool exists;
int key;
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

struct Anon1621811895 {
char* C_NAME;
int C_CUSTKEY;
int O_ORDERKEY;
long O_ORDERDATE;
double O_TOTALPRICE;
};

struct Anon2131541195 {
double total;
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

struct Anon1918636998 {
bool exists;
struct Anon1621811895 key;
struct Anon2052879266 aggs;
};

struct Anon1052706553 {
bool exists;
int key;
struct Anon1023322325 aggs;
};

struct Anon1900109934 {
bool exists;
double key;
struct Anon2052879266 aggs;
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

struct Anon964248194 {
bool exists;
int key;
struct Anon2052879266 aggs;
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

struct Anon1395358962Anon168903330 {
int PS_PARTKEY;
int PS_SUPPKEY;
int PS_AVAILQTY;
double PS_SUPPLYCOST;
char* PS_COMMENT;
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

struct Anon1251919804 {
long REC2_O_ORDERDATE;
double REC2_L_DISCOUNT;
double REC2_L_EXTENDEDPRICE;
int REC2_S_NATIONKEY;
};

struct Anon1395358962 {
int PS_PARTKEY;
int PS_SUPPKEY;
int PS_AVAILQTY;
double PS_SUPPLYCOST;
char* PS_COMMENT;
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

struct Anon1638440139 {
bool exists;
struct Anon1978526630 key;
struct Anon2052879266 aggs;
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
int main(int x35412, char** x35413) {
  long x35414 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x35415 = x7;
  long x35416 = 0L;
  int* x35417 = (int*)malloc(x7 * sizeof(int));
  int* x35418 = x35417;
  char** x35419 = (char**)malloc(x7 * sizeof(char*));
  char** x35420 = x35419;
  int x1076 = open("XXXXXpart.tbl",0);
  long x1077 = fsize(x1076);
  char* x1078 = mmap(0, x1077, PROT_READ, MAP_FILE | MAP_SHARED, x1076, 0);
  for (;;) {
    long x35436 = x35414;
    bool x35437 = x35436 < x1077;
    if (!x35437) break;
    int x35440 = 0;
    for (;;) {
      long x35441 = x35414;
      char x35442 = x1078[x35441];
      bool x35443 = x35442 != '|';
      bool x35448 = x35443;
      if (x35443) {
        long x35444 = x35414;
        char x35445 = x1078[x35444];
        bool x35446 = x35445 != '\n';
        x35448 = x35446;
      }
      bool x35449 = x35448;
      if (!x35449) break;
      int x35451 = x35440;
      long x35453 = x35414;
      int x35452 = x35451 * 10;
      char x35454 = x1078[x35453];
      char x35455 = x35454 - '0';
      int x35456 = x35452 + x35455;
      x35440 = x35456;
      x35414 = x35414 + 1;
    }
    x35414 = x35414 + 1;
    int x35462 = x35440;
    long x35463 = x35414;
    for (;;) {
      long x35464 = x35414;
      char x35465 = x1078[x35464];
      bool x35466 = x35465 != '|';
      bool x35471 = x35466;
      if (x35466) {
        long x35467 = x35414;
        char x35468 = x1078[x35467];
        bool x35469 = x35468 != '\n';
        x35471 = x35469;
      }
      bool x35472 = x35471;
      if (!x35472) break;
      x35414 = x35414 + 1;
    }
    x35414 = x35414 + 1;
    for (;;) {
      long x35482 = x35414;
      char x35483 = x1078[x35482];
      bool x35484 = x35483 != '|';
      bool x35489 = x35484;
      if (x35484) {
        long x35485 = x35414;
        char x35486 = x1078[x35485];
        bool x35487 = x35486 != '\n';
        x35489 = x35487;
      }
      bool x35490 = x35489;
      if (!x35490) break;
      x35414 = x35414 + 1;
    }
    x35414 = x35414 + 1;
    for (;;) {
      long x35500 = x35414;
      char x35501 = x1078[x35500];
      bool x35502 = x35501 != '|';
      bool x35507 = x35502;
      if (x35502) {
        long x35503 = x35414;
        char x35504 = x1078[x35503];
        bool x35505 = x35504 != '\n';
        x35507 = x35505;
      }
      bool x35508 = x35507;
      if (!x35508) break;
      x35414 = x35414 + 1;
    }
    x35414 = x35414 + 1;
    for (;;) {
      long x35518 = x35414;
      char x35519 = x1078[x35518];
      bool x35520 = x35519 != '|';
      bool x35525 = x35520;
      if (x35520) {
        long x35521 = x35414;
        char x35522 = x1078[x35521];
        bool x35523 = x35522 != '\n';
        x35525 = x35523;
      }
      bool x35526 = x35525;
      if (!x35526) break;
      x35414 = x35414 + 1;
    }
    x35414 = x35414 + 1;
    for (;;) {
      long x35537 = x35414;
      char x35538 = x1078[x35537];
      bool x35539 = x35538 != '|';
      bool x35544 = x35539;
      if (x35539) {
        long x35540 = x35414;
        char x35541 = x1078[x35540];
        bool x35542 = x35541 != '\n';
        x35544 = x35542;
      }
      bool x35545 = x35544;
      if (!x35545) break;
      x35414 = x35414 + 1;
    }
    x35414 = x35414 + 1;
    for (;;) {
      long x35560 = x35414;
      char x35561 = x1078[x35560];
      bool x35562 = x35561 != '|';
      bool x35567 = x35562;
      if (x35562) {
        long x35563 = x35414;
        char x35564 = x1078[x35563];
        bool x35565 = x35564 != '\n';
        x35567 = x35565;
      }
      bool x35568 = x35567;
      if (!x35568) break;
      x35414 = x35414 + 1;
    }
    x35414 = x35414 + 1;
    for (;;) {
      long x35580 = x35414;
      char x35581 = x1078[x35580];
      bool x35582 = x35581 != '.';
      bool x35587 = x35582;
      if (x35582) {
        long x35583 = x35414;
        char x35584 = x1078[x35583];
        bool x35585 = x35584 != '|';
        x35587 = x35585;
      }
      bool x35588 = x35587;
      bool x35593 = x35588;
      if (x35588) {
        long x35589 = x35414;
        char x35590 = x1078[x35589];
        bool x35591 = x35590 != '\n';
        x35593 = x35591;
      }
      bool x35594 = x35593;
      if (!x35594) break;
      x35414 = x35414 + 1;
    }
    long x35606 = x35414;
    char x35607 = x1078[x35606];
    bool x35608 = x35607 == '.';
    if (x35608) {
      x35414 = x35414 + 1;
      for (;;) {
        long x35610 = x35414;
        char x35611 = x1078[x35610];
        bool x35612 = x35611 != '|';
        bool x35617 = x35612;
        if (x35612) {
          long x35613 = x35414;
          char x35614 = x1078[x35613];
          bool x35615 = x35614 != '\n';
          x35617 = x35615;
        }
        bool x35618 = x35617;
        if (!x35618) break;
        x35414 = x35414 + 1;
      }
    } else {
    }
    x35414 = x35414 + 1;
    for (;;) {
      long x35643 = x35414;
      char x35644 = x1078[x35643];
      bool x35645 = x35644 != '|';
      bool x35650 = x35645;
      if (x35645) {
        long x35646 = x35414;
        char x35647 = x1078[x35646];
        bool x35648 = x35647 != '\n';
        x35650 = x35648;
      }
      bool x35651 = x35650;
      if (!x35651) break;
      x35414 = x35414 + 1;
    }
    x35414 = x35414 + 1;
    long x35661 = x35414;
    bool x35662 = x35661 > 0L;
    bool x35668 = x35662;
    if (x35662) {
      long x35663 = x35414;
      long x35664 = x35663 - 1L;
      char x35665 = x1078[x35664];
      bool x35666 = x35665 != '\n';
      x35668 = x35666;
    }
    bool x35669 = x35668;
    if (x35669) {
      for (;;) {
        long x35670 = x35414;
        char x35671 = x1078[x35670];
        bool x35672 = x35671 != '\n';
        if (!x35672) break;
        x35414 = x35414 + 1;
      }
    } else {
    }
    x35414 = x35414 + 1;
    long x35681 = x35416;
    long x35682 = x35415;
    bool x35683 = x35681 == x35682;
    if (x35683) {
      long x35684 = x35682 * 4L;
      x35415 = x35684;
      printf("buffer.resize %ld\n",x35684);
      int* x35687 = x35418;
      int* x35688 = (int*)realloc(x35687,x35684 * sizeof(int));
      x35418 = x35688;
      char** x35690 = x35420;
      char** x35691 = (char**)realloc(x35690,x35684 * sizeof(char*));
      x35420 = x35691;
    } else {
    }
    int* x35716 = x35418;
    x35716[x35681] = x35462;
    char** x35718 = x35420;
    char* x35480 = x1078+x35463;
    x35718[x35681] = x35480;
    x35416 = x35416 + 1;
  }
  long x35737 = 0L;
  long x35738 = x7;
  long x35739 = 0L;
  int* x35740 = (int*)malloc(x7 * sizeof(int));
  int* x35741 = x35740;
  char** x35742 = (char**)malloc(x7 * sizeof(char*));
  char** x35743 = x35742;
  int x1633 = open("XXXXXnation.tbl",0);
  long x1634 = fsize(x1633);
  char* x1635 = mmap(0, x1634, PROT_READ, MAP_FILE | MAP_SHARED, x1633, 0);
  for (;;) {
    long x35748 = x35737;
    bool x35749 = x35748 < x1634;
    if (!x35749) break;
    int x35752 = 0;
    for (;;) {
      long x35753 = x35737;
      char x35754 = x1635[x35753];
      bool x35755 = x35754 != '|';
      bool x35760 = x35755;
      if (x35755) {
        long x35756 = x35737;
        char x35757 = x1635[x35756];
        bool x35758 = x35757 != '\n';
        x35760 = x35758;
      }
      bool x35761 = x35760;
      if (!x35761) break;
      int x35763 = x35752;
      long x35765 = x35737;
      int x35764 = x35763 * 10;
      char x35766 = x1635[x35765];
      char x35767 = x35766 - '0';
      int x35768 = x35764 + x35767;
      x35752 = x35768;
      x35737 = x35737 + 1;
    }
    x35737 = x35737 + 1;
    int x35774 = x35752;
    long x35775 = x35737;
    for (;;) {
      long x35776 = x35737;
      char x35777 = x1635[x35776];
      bool x35778 = x35777 != '|';
      bool x35783 = x35778;
      if (x35778) {
        long x35779 = x35737;
        char x35780 = x1635[x35779];
        bool x35781 = x35780 != '\n';
        x35783 = x35781;
      }
      bool x35784 = x35783;
      if (!x35784) break;
      x35737 = x35737 + 1;
    }
    x35737 = x35737 + 1;
    for (;;) {
      long x35795 = x35737;
      char x35796 = x1635[x35795];
      bool x35797 = x35796 != '|';
      bool x35802 = x35797;
      if (x35797) {
        long x35798 = x35737;
        char x35799 = x1635[x35798];
        bool x35800 = x35799 != '\n';
        x35802 = x35800;
      }
      bool x35803 = x35802;
      if (!x35803) break;
      x35737 = x35737 + 1;
    }
    x35737 = x35737 + 1;
    for (;;) {
      long x35818 = x35737;
      char x35819 = x1635[x35818];
      bool x35820 = x35819 != '|';
      bool x35825 = x35820;
      if (x35820) {
        long x35821 = x35737;
        char x35822 = x1635[x35821];
        bool x35823 = x35822 != '\n';
        x35825 = x35823;
      }
      bool x35826 = x35825;
      if (!x35826) break;
      x35737 = x35737 + 1;
    }
    x35737 = x35737 + 1;
    long x35836 = x35737;
    bool x35837 = x35836 > 0L;
    bool x35843 = x35837;
    if (x35837) {
      long x35838 = x35737;
      long x35839 = x35838 - 1L;
      char x35840 = x1635[x35839];
      bool x35841 = x35840 != '\n';
      x35843 = x35841;
    }
    bool x35844 = x35843;
    if (x35844) {
      for (;;) {
        long x35845 = x35737;
        char x35846 = x1635[x35845];
        bool x35847 = x35846 != '\n';
        if (!x35847) break;
        x35737 = x35737 + 1;
      }
    } else {
    }
    x35737 = x35737 + 1;
    long x35856 = x35739;
    long x35857 = x35738;
    bool x35858 = x35856 == x35857;
    if (x35858) {
      long x35859 = x35857 * 4L;
      x35738 = x35859;
      printf("buffer.resize %ld\n",x35859);
      int* x35862 = x35741;
      int* x35863 = (int*)realloc(x35862,x35859 * sizeof(int));
      x35741 = x35863;
      char** x35865 = x35743;
      char** x35866 = (char**)realloc(x35865,x35859 * sizeof(char*));
      x35743 = x35866;
    } else {
    }
    int* x35876 = x35741;
    x35876[x35856] = x35774;
    char** x35878 = x35743;
    char* x35792 = x1635+x35775;
    x35878[x35856] = x35792;
    x35739 = x35739 + 1;
  }
  long x35887 = 0L;
  long x35888 = x7;
  long x35889 = 0L;
  int* x35890 = (int*)malloc(x7 * sizeof(int));
  int* x35891 = x35890;
  char** x35892 = (char**)malloc(x7 * sizeof(char*));
  char** x35893 = x35892;
  char** x35894 = (char**)malloc(x7 * sizeof(char*));
  char** x35895 = x35894;
  int* x35896 = (int*)malloc(x7 * sizeof(int));
  int* x35897 = x35896;
  int x1908 = open("XXXXXsupplier.tbl",0);
  long x1909 = fsize(x1908);
  char* x1910 = mmap(0, x1909, PROT_READ, MAP_FILE | MAP_SHARED, x1908, 0);
  for (;;) {
    long x35904 = x35887;
    bool x35905 = x35904 < x1909;
    if (!x35905) break;
    int x35908 = 0;
    for (;;) {
      long x35909 = x35887;
      char x35910 = x1910[x35909];
      bool x35911 = x35910 != '|';
      bool x35916 = x35911;
      if (x35911) {
        long x35912 = x35887;
        char x35913 = x1910[x35912];
        bool x35914 = x35913 != '\n';
        x35916 = x35914;
      }
      bool x35917 = x35916;
      if (!x35917) break;
      int x35919 = x35908;
      long x35921 = x35887;
      int x35920 = x35919 * 10;
      char x35922 = x1910[x35921];
      char x35923 = x35922 - '0';
      int x35924 = x35920 + x35923;
      x35908 = x35924;
      x35887 = x35887 + 1;
    }
    x35887 = x35887 + 1;
    int x35930 = x35908;
    long x35931 = x35887;
    for (;;) {
      long x35932 = x35887;
      char x35933 = x1910[x35932];
      bool x35934 = x35933 != '|';
      bool x35939 = x35934;
      if (x35934) {
        long x35935 = x35887;
        char x35936 = x1910[x35935];
        bool x35937 = x35936 != '\n';
        x35939 = x35937;
      }
      bool x35940 = x35939;
      if (!x35940) break;
      x35887 = x35887 + 1;
    }
    x35887 = x35887 + 1;
    long x35949 = x35887;
    for (;;) {
      long x35950 = x35887;
      char x35951 = x1910[x35950];
      bool x35952 = x35951 != '|';
      bool x35957 = x35952;
      if (x35952) {
        long x35953 = x35887;
        char x35954 = x1910[x35953];
        bool x35955 = x35954 != '\n';
        x35957 = x35955;
      }
      bool x35958 = x35957;
      if (!x35958) break;
      x35887 = x35887 + 1;
    }
    x35887 = x35887 + 1;
    int x35968 = 0;
    for (;;) {
      long x35969 = x35887;
      char x35970 = x1910[x35969];
      bool x35971 = x35970 != '|';
      bool x35976 = x35971;
      if (x35971) {
        long x35972 = x35887;
        char x35973 = x1910[x35972];
        bool x35974 = x35973 != '\n';
        x35976 = x35974;
      }
      bool x35977 = x35976;
      if (!x35977) break;
      int x35979 = x35968;
      long x35981 = x35887;
      int x35980 = x35979 * 10;
      char x35982 = x1910[x35981];
      char x35983 = x35982 - '0';
      int x35984 = x35980 + x35983;
      x35968 = x35984;
      x35887 = x35887 + 1;
    }
    x35887 = x35887 + 1;
    int x35990 = x35968;
    for (;;) {
      long x35992 = x35887;
      char x35993 = x1910[x35992];
      bool x35994 = x35993 != '|';
      bool x35999 = x35994;
      if (x35994) {
        long x35995 = x35887;
        char x35996 = x1910[x35995];
        bool x35997 = x35996 != '\n';
        x35999 = x35997;
      }
      bool x36000 = x35999;
      if (!x36000) break;
      x35887 = x35887 + 1;
    }
    x35887 = x35887 + 1;
    for (;;) {
      long x36012 = x35887;
      char x36013 = x1910[x36012];
      bool x36014 = x36013 != '.';
      bool x36019 = x36014;
      if (x36014) {
        long x36015 = x35887;
        char x36016 = x1910[x36015];
        bool x36017 = x36016 != '|';
        x36019 = x36017;
      }
      bool x36020 = x36019;
      bool x36025 = x36020;
      if (x36020) {
        long x36021 = x35887;
        char x36022 = x1910[x36021];
        bool x36023 = x36022 != '\n';
        x36025 = x36023;
      }
      bool x36026 = x36025;
      if (!x36026) break;
      x35887 = x35887 + 1;
    }
    long x36038 = x35887;
    char x36039 = x1910[x36038];
    bool x36040 = x36039 == '.';
    if (x36040) {
      x35887 = x35887 + 1;
      for (;;) {
        long x36042 = x35887;
        char x36043 = x1910[x36042];
        bool x36044 = x36043 != '|';
        bool x36049 = x36044;
        if (x36044) {
          long x36045 = x35887;
          char x36046 = x1910[x36045];
          bool x36047 = x36046 != '\n';
          x36049 = x36047;
        }
        bool x36050 = x36049;
        if (!x36050) break;
        x35887 = x35887 + 1;
      }
    } else {
    }
    x35887 = x35887 + 1;
    for (;;) {
      long x36075 = x35887;
      char x36076 = x1910[x36075];
      bool x36077 = x36076 != '|';
      bool x36082 = x36077;
      if (x36077) {
        long x36078 = x35887;
        char x36079 = x1910[x36078];
        bool x36080 = x36079 != '\n';
        x36082 = x36080;
      }
      bool x36083 = x36082;
      if (!x36083) break;
      x35887 = x35887 + 1;
    }
    x35887 = x35887 + 1;
    long x36093 = x35887;
    bool x36094 = x36093 > 0L;
    bool x36100 = x36094;
    if (x36094) {
      long x36095 = x35887;
      long x36096 = x36095 - 1L;
      char x36097 = x1910[x36096];
      bool x36098 = x36097 != '\n';
      x36100 = x36098;
    }
    bool x36101 = x36100;
    if (x36101) {
      for (;;) {
        long x36102 = x35887;
        char x36103 = x1910[x36102];
        bool x36104 = x36103 != '\n';
        if (!x36104) break;
        x35887 = x35887 + 1;
      }
    } else {
    }
    x35887 = x35887 + 1;
    long x36113 = x35889;
    long x36114 = x35888;
    bool x36115 = x36113 == x36114;
    if (x36115) {
      long x36116 = x36114 * 4L;
      x35888 = x36116;
      printf("buffer.resize %ld\n",x36116);
      int* x36119 = x35891;
      int* x36120 = (int*)realloc(x36119,x36116 * sizeof(int));
      x35891 = x36120;
      char** x36122 = x35893;
      char** x36123 = (char**)realloc(x36122,x36116 * sizeof(char*));
      x35893 = x36123;
      char** x36125 = x35895;
      char** x36126 = (char**)realloc(x36125,x36116 * sizeof(char*));
      x35895 = x36126;
      int* x36128 = x35897;
      int* x36129 = (int*)realloc(x36128,x36116 * sizeof(int));
      x35897 = x36129;
    } else {
    }
    int* x36142 = x35891;
    x36142[x36113] = x35930;
    char** x36144 = x35893;
    char* x35948 = x1910+x35931;
    x36144[x36113] = x35948;
    char** x36146 = x35895;
    char* x35966 = x1910+x35949;
    x36146[x36113] = x35966;
    int* x36148 = x35897;
    x36148[x36113] = x35990;
    x35889 = x35889 + 1;
  }
  long x36159 = 0L;
  long x36160 = x7;
  long x36161 = 0L;
  int* x36162 = (int*)malloc(x7 * sizeof(int));
  int* x36163 = x36162;
  int* x36164 = (int*)malloc(x7 * sizeof(int));
  int* x36165 = x36164;
  int* x36166 = (int*)malloc(x7 * sizeof(int));
  int* x36167 = x36166;
  int x1402 = open("XXXXXpartsupp.tbl",0);
  long x1403 = fsize(x1402);
  char* x1404 = mmap(0, x1403, PROT_READ, MAP_FILE | MAP_SHARED, x1402, 0);
  for (;;) {
    long x36172 = x36159;
    bool x36173 = x36172 < x1403;
    if (!x36173) break;
    int x36176 = 0;
    for (;;) {
      long x36177 = x36159;
      char x36178 = x1404[x36177];
      bool x36179 = x36178 != '|';
      bool x36184 = x36179;
      if (x36179) {
        long x36180 = x36159;
        char x36181 = x1404[x36180];
        bool x36182 = x36181 != '\n';
        x36184 = x36182;
      }
      bool x36185 = x36184;
      if (!x36185) break;
      int x36187 = x36176;
      long x36189 = x36159;
      int x36188 = x36187 * 10;
      char x36190 = x1404[x36189];
      char x36191 = x36190 - '0';
      int x36192 = x36188 + x36191;
      x36176 = x36192;
      x36159 = x36159 + 1;
    }
    x36159 = x36159 + 1;
    int x36198 = x36176;
    int x36200 = 0;
    for (;;) {
      long x36201 = x36159;
      char x36202 = x1404[x36201];
      bool x36203 = x36202 != '|';
      bool x36208 = x36203;
      if (x36203) {
        long x36204 = x36159;
        char x36205 = x1404[x36204];
        bool x36206 = x36205 != '\n';
        x36208 = x36206;
      }
      bool x36209 = x36208;
      if (!x36209) break;
      int x36211 = x36200;
      long x36213 = x36159;
      int x36212 = x36211 * 10;
      char x36214 = x1404[x36213];
      char x36215 = x36214 - '0';
      int x36216 = x36212 + x36215;
      x36200 = x36216;
      x36159 = x36159 + 1;
    }
    x36159 = x36159 + 1;
    int x36222 = x36200;
    int x36224 = 0;
    for (;;) {
      long x36225 = x36159;
      char x36226 = x1404[x36225];
      bool x36227 = x36226 != '|';
      bool x36232 = x36227;
      if (x36227) {
        long x36228 = x36159;
        char x36229 = x1404[x36228];
        bool x36230 = x36229 != '\n';
        x36232 = x36230;
      }
      bool x36233 = x36232;
      if (!x36233) break;
      int x36235 = x36224;
      long x36237 = x36159;
      int x36236 = x36235 * 10;
      char x36238 = x1404[x36237];
      char x36239 = x36238 - '0';
      int x36240 = x36236 + x36239;
      x36224 = x36240;
      x36159 = x36159 + 1;
    }
    x36159 = x36159 + 1;
    int x36246 = x36224;
    for (;;) {
      long x36250 = x36159;
      char x36251 = x1404[x36250];
      bool x36252 = x36251 != '.';
      bool x36257 = x36252;
      if (x36252) {
        long x36253 = x36159;
        char x36254 = x1404[x36253];
        bool x36255 = x36254 != '|';
        x36257 = x36255;
      }
      bool x36258 = x36257;
      bool x36263 = x36258;
      if (x36258) {
        long x36259 = x36159;
        char x36260 = x1404[x36259];
        bool x36261 = x36260 != '\n';
        x36263 = x36261;
      }
      bool x36264 = x36263;
      if (!x36264) break;
      x36159 = x36159 + 1;
    }
    long x36276 = x36159;
    char x36277 = x1404[x36276];
    bool x36278 = x36277 == '.';
    if (x36278) {
      x36159 = x36159 + 1;
      for (;;) {
        long x36280 = x36159;
        char x36281 = x1404[x36280];
        bool x36282 = x36281 != '|';
        bool x36287 = x36282;
        if (x36282) {
          long x36283 = x36159;
          char x36284 = x1404[x36283];
          bool x36285 = x36284 != '\n';
          x36287 = x36285;
        }
        bool x36288 = x36287;
        if (!x36288) break;
        x36159 = x36159 + 1;
      }
    } else {
    }
    x36159 = x36159 + 1;
    for (;;) {
      long x36313 = x36159;
      char x36314 = x1404[x36313];
      bool x36315 = x36314 != '|';
      bool x36320 = x36315;
      if (x36315) {
        long x36316 = x36159;
        char x36317 = x1404[x36316];
        bool x36318 = x36317 != '\n';
        x36320 = x36318;
      }
      bool x36321 = x36320;
      if (!x36321) break;
      x36159 = x36159 + 1;
    }
    x36159 = x36159 + 1;
    long x36331 = x36159;
    bool x36332 = x36331 > 0L;
    bool x36338 = x36332;
    if (x36332) {
      long x36333 = x36159;
      long x36334 = x36333 - 1L;
      char x36335 = x1404[x36334];
      bool x36336 = x36335 != '\n';
      x36338 = x36336;
    }
    bool x36339 = x36338;
    if (x36339) {
      for (;;) {
        long x36340 = x36159;
        char x36341 = x1404[x36340];
        bool x36342 = x36341 != '\n';
        if (!x36342) break;
        x36159 = x36159 + 1;
      }
    } else {
    }
    x36159 = x36159 + 1;
    long x36351 = x36161;
    long x36352 = x36160;
    bool x36353 = x36351 == x36352;
    if (x36353) {
      long x36354 = x36352 * 4L;
      x36160 = x36354;
      printf("buffer.resize %ld\n",x36354);
      int* x36357 = x36163;
      int* x36358 = (int*)realloc(x36357,x36354 * sizeof(int));
      x36163 = x36358;
      int* x36360 = x36165;
      int* x36361 = (int*)realloc(x36360,x36354 * sizeof(int));
      x36165 = x36361;
      int* x36363 = x36167;
      int* x36364 = (int*)realloc(x36363,x36354 * sizeof(int));
      x36167 = x36364;
    } else {
    }
    int* x36374 = x36163;
    x36374[x36351] = x36198;
    int* x36376 = x36165;
    x36376[x36351] = x36222;
    int* x36378 = x36167;
    x36378[x36351] = x36246;
    x36161 = x36161 + 1;
  }
  long x36387 = 0L;
  long x36388 = x7;
  long x36389 = 0L;
  int* x36392 = (int*)malloc(x7 * sizeof(int));
  int* x36393 = x36392;
  int* x36394 = (int*)malloc(x7 * sizeof(int));
  int* x36395 = x36394;
  double* x36398 = (double*)malloc(x7 * sizeof(double));
  double* x36399 = x36398;
  long* x36410 = (long*)malloc(x7 * sizeof(long));
  long* x36411 = x36410;
  int x3 = open("XXXXXlineitem.tbl",0);
  long x4 = fsize(x3);
  char* x5 = mmap(0, x4, PROT_READ, MAP_FILE | MAP_SHARED, x3, 0);
  for (;;) {
    long x36422 = x36387;
    bool x36423 = x36422 < x4;
    if (!x36423) break;
    for (;;) {
      long x36427 = x36387;
      char x36428 = x5[x36427];
      bool x36429 = x36428 != '|';
      bool x36434 = x36429;
      if (x36429) {
        long x36430 = x36387;
        char x36431 = x5[x36430];
        bool x36432 = x36431 != '\n';
        x36434 = x36432;
      }
      bool x36435 = x36434;
      if (!x36435) break;
      x36387 = x36387 + 1;
    }
    x36387 = x36387 + 1;
    int x36450 = 0;
    for (;;) {
      long x36451 = x36387;
      char x36452 = x5[x36451];
      bool x36453 = x36452 != '|';
      bool x36458 = x36453;
      if (x36453) {
        long x36454 = x36387;
        char x36455 = x5[x36454];
        bool x36456 = x36455 != '\n';
        x36458 = x36456;
      }
      bool x36459 = x36458;
      if (!x36459) break;
      int x36461 = x36450;
      long x36463 = x36387;
      int x36462 = x36461 * 10;
      char x36464 = x5[x36463];
      char x36465 = x36464 - '0';
      int x36466 = x36462 + x36465;
      x36450 = x36466;
      x36387 = x36387 + 1;
    }
    x36387 = x36387 + 1;
    int x36472 = x36450;
    int x36474 = 0;
    for (;;) {
      long x36475 = x36387;
      char x36476 = x5[x36475];
      bool x36477 = x36476 != '|';
      bool x36482 = x36477;
      if (x36477) {
        long x36478 = x36387;
        char x36479 = x5[x36478];
        bool x36480 = x36479 != '\n';
        x36482 = x36480;
      }
      bool x36483 = x36482;
      if (!x36483) break;
      int x36485 = x36474;
      long x36487 = x36387;
      int x36486 = x36485 * 10;
      char x36488 = x5[x36487];
      char x36489 = x36488 - '0';
      int x36490 = x36486 + x36489;
      x36474 = x36490;
      x36387 = x36387 + 1;
    }
    x36387 = x36387 + 1;
    int x36496 = x36474;
    for (;;) {
      long x36499 = x36387;
      char x36500 = x5[x36499];
      bool x36501 = x36500 != '|';
      bool x36506 = x36501;
      if (x36501) {
        long x36502 = x36387;
        char x36503 = x5[x36502];
        bool x36504 = x36503 != '\n';
        x36506 = x36504;
      }
      bool x36507 = x36506;
      if (!x36507) break;
      x36387 = x36387 + 1;
    }
    x36387 = x36387 + 1;
    int x36522 = 0;
    int x36523 = 1;
    for (;;) {
      long x36524 = x36387;
      char x36525 = x5[x36524];
      bool x36526 = x36525 != '.';
      bool x36531 = x36526;
      if (x36526) {
        long x36527 = x36387;
        char x36528 = x5[x36527];
        bool x36529 = x36528 != '|';
        x36531 = x36529;
      }
      bool x36532 = x36531;
      bool x36537 = x36532;
      if (x36532) {
        long x36533 = x36387;
        char x36534 = x5[x36533];
        bool x36535 = x36534 != '\n';
        x36537 = x36535;
      }
      bool x36538 = x36537;
      if (!x36538) break;
      int x36540 = x36522;
      long x36542 = x36387;
      int x36541 = x36540 * 10;
      char x36543 = x5[x36542];
      char x36544 = x36543 - '0';
      int x36545 = x36541 + x36544;
      x36522 = x36545;
      x36387 = x36387 + 1;
    }
    long x36550 = x36387;
    char x36551 = x5[x36550];
    bool x36552 = x36551 == '.';
    if (x36552) {
      x36387 = x36387 + 1;
      for (;;) {
        long x36554 = x36387;
        char x36555 = x5[x36554];
        bool x36556 = x36555 != '|';
        bool x36561 = x36556;
        if (x36556) {
          long x36557 = x36387;
          char x36558 = x5[x36557];
          bool x36559 = x36558 != '\n';
          x36561 = x36559;
        }
        bool x36562 = x36561;
        if (!x36562) break;
        int x36564 = x36522;
        long x36566 = x36387;
        int x36565 = x36564 * 10;
        char x36567 = x5[x36566];
        char x36568 = x36567 - '0';
        int x36569 = x36565 + x36568;
        x36522 = x36569;
        int x36571 = x36523;
        int x36572 = x36571 * 10;
        x36523 = x36572;
        x36387 = x36387 + 1;
      }
    } else {
    }
    x36387 = x36387 + 1;
    int x36581 = x36522;
    int x36583 = x36523;
    for (;;) {
      long x36589 = x36387;
      char x36590 = x5[x36589];
      bool x36591 = x36590 != '.';
      bool x36596 = x36591;
      if (x36591) {
        long x36592 = x36387;
        char x36593 = x5[x36592];
        bool x36594 = x36593 != '|';
        x36596 = x36594;
      }
      bool x36597 = x36596;
      bool x36602 = x36597;
      if (x36597) {
        long x36598 = x36387;
        char x36599 = x5[x36598];
        bool x36600 = x36599 != '\n';
        x36602 = x36600;
      }
      bool x36603 = x36602;
      if (!x36603) break;
      x36387 = x36387 + 1;
    }
    long x36615 = x36387;
    char x36616 = x5[x36615];
    bool x36617 = x36616 == '.';
    if (x36617) {
      x36387 = x36387 + 1;
      for (;;) {
        long x36619 = x36387;
        char x36620 = x5[x36619];
        bool x36621 = x36620 != '|';
        bool x36626 = x36621;
        if (x36621) {
          long x36622 = x36387;
          char x36623 = x5[x36622];
          bool x36624 = x36623 != '\n';
          x36626 = x36624;
        }
        bool x36627 = x36626;
        if (!x36627) break;
        x36387 = x36387 + 1;
      }
    } else {
    }
    x36387 = x36387 + 1;
    for (;;) {
      long x36654 = x36387;
      char x36655 = x5[x36654];
      bool x36656 = x36655 != '.';
      bool x36661 = x36656;
      if (x36656) {
        long x36657 = x36387;
        char x36658 = x5[x36657];
        bool x36659 = x36658 != '|';
        x36661 = x36659;
      }
      bool x36662 = x36661;
      bool x36667 = x36662;
      if (x36662) {
        long x36663 = x36387;
        char x36664 = x5[x36663];
        bool x36665 = x36664 != '\n';
        x36667 = x36665;
      }
      bool x36668 = x36667;
      if (!x36668) break;
      x36387 = x36387 + 1;
    }
    long x36680 = x36387;
    char x36681 = x5[x36680];
    bool x36682 = x36681 == '.';
    if (x36682) {
      x36387 = x36387 + 1;
      for (;;) {
        long x36684 = x36387;
        char x36685 = x5[x36684];
        bool x36686 = x36685 != '|';
        bool x36691 = x36686;
        if (x36686) {
          long x36687 = x36387;
          char x36688 = x5[x36687];
          bool x36689 = x36688 != '\n';
          x36691 = x36689;
        }
        bool x36692 = x36691;
        if (!x36692) break;
        x36387 = x36387 + 1;
      }
    } else {
    }
    x36387 = x36387 + 1;
    for (;;) {
      long x36719 = x36387;
      char x36720 = x5[x36719];
      bool x36721 = x36720 != '.';
      bool x36726 = x36721;
      if (x36721) {
        long x36722 = x36387;
        char x36723 = x5[x36722];
        bool x36724 = x36723 != '|';
        x36726 = x36724;
      }
      bool x36727 = x36726;
      bool x36732 = x36727;
      if (x36727) {
        long x36728 = x36387;
        char x36729 = x5[x36728];
        bool x36730 = x36729 != '\n';
        x36732 = x36730;
      }
      bool x36733 = x36732;
      if (!x36733) break;
      x36387 = x36387 + 1;
    }
    long x36745 = x36387;
    char x36746 = x5[x36745];
    bool x36747 = x36746 == '.';
    if (x36747) {
      x36387 = x36387 + 1;
      for (;;) {
        long x36749 = x36387;
        char x36750 = x5[x36749];
        bool x36751 = x36750 != '|';
        bool x36756 = x36751;
        if (x36751) {
          long x36752 = x36387;
          char x36753 = x5[x36752];
          bool x36754 = x36753 != '\n';
          x36756 = x36754;
        }
        bool x36757 = x36756;
        if (!x36757) break;
        x36387 = x36387 + 1;
      }
    } else {
    }
    x36387 = x36387 + 1;
    x36387 = x36387 + 2;
    x36387 = x36387 + 2;
    int x36788 = 0;
    for (;;) {
      long x36789 = x36387;
      char x36790 = x5[x36789];
      bool x36791 = x36790 != '-';
      bool x36796 = x36791;
      if (x36791) {
        long x36792 = x36387;
        char x36793 = x5[x36792];
        bool x36794 = x36793 != '\n';
        x36796 = x36794;
      }
      bool x36797 = x36796;
      if (!x36797) break;
      int x36799 = x36788;
      long x36801 = x36387;
      int x36800 = x36799 * 10;
      char x36802 = x5[x36801];
      char x36803 = x36802 - '0';
      int x36804 = x36800 + x36803;
      x36788 = x36804;
      x36387 = x36387 + 1;
    }
    x36387 = x36387 + 1;
    int x36810 = x36788;
    int x36812 = 0;
    for (;;) {
      long x36813 = x36387;
      char x36814 = x5[x36813];
      bool x36815 = x36814 != '-';
      bool x36820 = x36815;
      if (x36815) {
        long x36816 = x36387;
        char x36817 = x5[x36816];
        bool x36818 = x36817 != '\n';
        x36820 = x36818;
      }
      bool x36821 = x36820;
      if (!x36821) break;
      int x36823 = x36812;
      long x36825 = x36387;
      int x36824 = x36823 * 10;
      char x36826 = x5[x36825];
      char x36827 = x36826 - '0';
      int x36828 = x36824 + x36827;
      x36812 = x36828;
      x36387 = x36387 + 1;
    }
    x36387 = x36387 + 1;
    int x36834 = x36812;
    int x36836 = 0;
    for (;;) {
      long x36837 = x36387;
      char x36838 = x5[x36837];
      bool x36839 = x36838 != '|';
      bool x36844 = x36839;
      if (x36839) {
        long x36840 = x36387;
        char x36841 = x5[x36840];
        bool x36842 = x36841 != '\n';
        x36844 = x36842;
      }
      bool x36845 = x36844;
      if (!x36845) break;
      int x36847 = x36836;
      long x36849 = x36387;
      int x36848 = x36847 * 10;
      char x36850 = x5[x36849];
      char x36851 = x36850 - '0';
      int x36852 = x36848 + x36851;
      x36836 = x36852;
      x36387 = x36387 + 1;
    }
    x36387 = x36387 + 1;
    int x36858 = x36836;
    for (;;) {
      long x36865 = x36387;
      char x36866 = x5[x36865];
      bool x36867 = x36866 != '-';
      bool x36872 = x36867;
      if (x36867) {
        long x36868 = x36387;
        char x36869 = x5[x36868];
        bool x36870 = x36869 != '\n';
        x36872 = x36870;
      }
      bool x36873 = x36872;
      if (!x36873) break;
      x36387 = x36387 + 1;
    }
    x36387 = x36387 + 1;
    for (;;) {
      long x36889 = x36387;
      char x36890 = x5[x36889];
      bool x36891 = x36890 != '-';
      bool x36896 = x36891;
      if (x36891) {
        long x36892 = x36387;
        char x36893 = x5[x36892];
        bool x36894 = x36893 != '\n';
        x36896 = x36894;
      }
      bool x36897 = x36896;
      if (!x36897) break;
      x36387 = x36387 + 1;
    }
    x36387 = x36387 + 1;
    for (;;) {
      long x36913 = x36387;
      char x36914 = x5[x36913];
      bool x36915 = x36914 != '|';
      bool x36920 = x36915;
      if (x36915) {
        long x36916 = x36387;
        char x36917 = x5[x36916];
        bool x36918 = x36917 != '\n';
        x36920 = x36918;
      }
      bool x36921 = x36920;
      if (!x36921) break;
      x36387 = x36387 + 1;
    }
    x36387 = x36387 + 1;
    for (;;) {
      long x36941 = x36387;
      char x36942 = x5[x36941];
      bool x36943 = x36942 != '-';
      bool x36948 = x36943;
      if (x36943) {
        long x36944 = x36387;
        char x36945 = x5[x36944];
        bool x36946 = x36945 != '\n';
        x36948 = x36946;
      }
      bool x36949 = x36948;
      if (!x36949) break;
      x36387 = x36387 + 1;
    }
    x36387 = x36387 + 1;
    for (;;) {
      long x36965 = x36387;
      char x36966 = x5[x36965];
      bool x36967 = x36966 != '-';
      bool x36972 = x36967;
      if (x36967) {
        long x36968 = x36387;
        char x36969 = x5[x36968];
        bool x36970 = x36969 != '\n';
        x36972 = x36970;
      }
      bool x36973 = x36972;
      if (!x36973) break;
      x36387 = x36387 + 1;
    }
    x36387 = x36387 + 1;
    for (;;) {
      long x36989 = x36387;
      char x36990 = x5[x36989];
      bool x36991 = x36990 != '|';
      bool x36996 = x36991;
      if (x36991) {
        long x36992 = x36387;
        char x36993 = x5[x36992];
        bool x36994 = x36993 != '\n';
        x36996 = x36994;
      }
      bool x36997 = x36996;
      if (!x36997) break;
      x36387 = x36387 + 1;
    }
    x36387 = x36387 + 1;
    for (;;) {
      long x37016 = x36387;
      char x37017 = x5[x37016];
      bool x37018 = x37017 != '|';
      bool x37023 = x37018;
      if (x37018) {
        long x37019 = x36387;
        char x37020 = x5[x37019];
        bool x37021 = x37020 != '\n';
        x37023 = x37021;
      }
      bool x37024 = x37023;
      if (!x37024) break;
      x36387 = x36387 + 1;
    }
    x36387 = x36387 + 1;
    for (;;) {
      long x37034 = x36387;
      char x37035 = x5[x37034];
      bool x37036 = x37035 != '|';
      bool x37041 = x37036;
      if (x37036) {
        long x37037 = x36387;
        char x37038 = x5[x37037];
        bool x37039 = x37038 != '\n';
        x37041 = x37039;
      }
      bool x37042 = x37041;
      if (!x37042) break;
      x36387 = x36387 + 1;
    }
    x36387 = x36387 + 1;
    for (;;) {
      long x37052 = x36387;
      char x37053 = x5[x37052];
      bool x37054 = x37053 != '|';
      bool x37059 = x37054;
      if (x37054) {
        long x37055 = x36387;
        char x37056 = x5[x37055];
        bool x37057 = x37056 != '\n';
        x37059 = x37057;
      }
      bool x37060 = x37059;
      if (!x37060) break;
      x36387 = x36387 + 1;
    }
    x36387 = x36387 + 1;
    long x37070 = x36387;
    bool x37071 = x37070 > 0L;
    bool x37077 = x37071;
    if (x37071) {
      long x37072 = x36387;
      long x37073 = x37072 - 1L;
      char x37074 = x5[x37073];
      bool x37075 = x37074 != '\n';
      x37077 = x37075;
    }
    bool x37078 = x37077;
    if (x37078) {
      for (;;) {
        long x37079 = x36387;
        char x37080 = x5[x37079];
        bool x37081 = x37080 != '\n';
        if (!x37081) break;
        x36387 = x36387 + 1;
      }
    } else {
    }
    x36387 = x36387 + 1;
    long x37090 = x36389;
    long x37091 = x36388;
    bool x37092 = x37090 == x37091;
    if (x37092) {
      long x37093 = x37091 * 4L;
      x36388 = x37093;
      printf("buffer.resize %ld\n",x37093);
      int* x37099 = x36393;
      int* x37100 = (int*)realloc(x37099,x37093 * sizeof(int));
      x36393 = x37100;
      int* x37102 = x36395;
      int* x37103 = (int*)realloc(x37102,x37093 * sizeof(int));
      x36395 = x37103;
      double* x37108 = x36399;
      double* x37109 = (double*)realloc(x37108,x37093 * sizeof(double));
      x36399 = x37109;
      long* x37126 = x36411;
      long* x37127 = (long*)realloc(x37126,x37093 * sizeof(long));
      x36411 = x37127;
    } else {
    }
    int* x37148 = x36393;
    x37148[x37090] = x36472;
    int* x37150 = x36395;
    x37150[x37090] = x36496;
    double* x37154 = x36399;
    double x36582 = (double)x36581;
    double x36584 = (double)x36583;
    double x36585 = x36582 / x36584;
    x37154[x37090] = x36585;
    long* x37166 = x36411;
    long x36859 = x36810 * 10000L;
    long x36860 = x36834 * 100L;
    long x36861 = x36859 + x36860;
    long x36862 = x36861 + x36858;
    x37166[x37090] = x36862;
    x36389 = x36389 + 1;
  }
  long x2189 = DEFAULT_JOIN_HASH_SIZE;
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  long x2212 = x2189 - 1L;
  long x823 = x808 - 1L;
  bool x1043 = true == false;
  int x37181;
  for(x37181=0; x37181 < 5; x37181++) {
    bool x37182 = false;
    long x37183 = 0L;
    bool x37185 = false;
    long x37186 = 0L;
    int* x37188 = (int*)malloc(x2189 * sizeof(int));
    int* x37189 = x37188;
    long x37206 = 0L;
    long* x37207 = (long*)malloc(x2189 * sizeof(long));
    long* x37208 = (long*)malloc(x2189 * sizeof(long));
    long x37209;
    for(x37209=0L; x37209 < x2189; x37209++) {
      x37207[x37209] = -1L;
    }
    bool x37213 = false;
    long x37214 = 0L;
    int* x37217 = (int*)malloc(x2189 * sizeof(int));
    int* x37218 = x37217;
    int* x37219 = (int*)malloc(x2189 * sizeof(int));
    int* x37220 = x37219;
    int* x37221 = (int*)malloc(x2189 * sizeof(int));
    int* x37222 = x37221;
    long x37227 = 0L;
    long* x37228 = (long*)malloc(x2189 * sizeof(long));
    long* x37229 = (long*)malloc(x2189 * sizeof(long));
    long x37230;
    for(x37230=0L; x37230 < x2189; x37230++) {
      x37228[x37230] = -1L;
    }
    struct Anon443803923* x37236 = (struct Anon443803923*)malloc(x808 * sizeof(struct Anon443803923));
    struct Anon443803923* x37237 = x37236;
    long x37238 = 0L;
    long* x37239 = (long*)malloc(x808 * sizeof(long));
    long x37240;
    for(x37240=0L; x37240 < x808; x37240++) {
      struct Anon443803923* x37241 = x37237;
      struct Anon443803923 x37242 = x37241[x37240];
      struct Anon1993309635 x37243 = x37242.key;;
      double x37244 = x37242.aggs;;
      struct Anon443803923 x37245;
      x37245.exists = false;
      x37245.key = x37243;
      x37245.aggs = x37244;
      x37241[x37240] = x37245;
    }
    bool x37250 = false;
    long x37251 = 0L;
    bool x37252 = false;
    long x37253 = 0L;
    int* x37256 = (int*)malloc(x2189 * sizeof(int));
    int* x37257 = x37256;
    long x37264 = 0L;
    long* x37265 = (long*)malloc(x2189 * sizeof(long));
    long* x37266 = (long*)malloc(x2189 * sizeof(long));
    long x37267;
    for(x37267=0L; x37267 < x2189; x37267++) {
      x37265[x37267] = -1L;
    }
    int* x37277 = (int*)malloc(x2189 * sizeof(int));
    int* x37278 = x37277;
    long x37283 = 0L;
    long* x37284 = (long*)malloc(x2189 * sizeof(long));
    long* x37285 = (long*)malloc(x2189 * sizeof(long));
    long x37286;
    for(x37286=0L; x37286 < x2189; x37286++) {
      x37284[x37286] = -1L;
    }
    long x37291 = 0L;
    struct timeval x37779, x37780, x37781;
    gettimeofday(&x37779, NULL);
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x37293 = x37182;
      bool x37294 = !x37293;
      bool x37299 = x37294;
      if (x37294) {
        long x37295 = x37183;
        long x37296 = x35416;
        bool x37297 = x37295 < x37296;
        x37299 = x37297;
      }
      bool x37300 = x37299;
      if (!x37300) break;
      long x37302 = x37183;
      int* x37303 = x35418;
      int x37304 = x37303[x37302];
      char** x37305 = x35420;
      char* x37306 = x37305[x37302];
      x37183 = x37183 + 1;
      bool x37323 = strncmp(x37306,"forest", tpch_strlen("forest")) == 0;;
      if (x37323) {
        long x37324 = x37206;
        int* x37325 = x37189;
        x37325[x37324] = x37304;
        x37206 = x37206 + 1L;
        long x37344 = x37304 & x2212;
        long x37345 = x37207[x37344];
        x37207[x37344] = x37324;
        x37208[x37324] = x37345;
      } else {
      }
    }
    printf("%s\n","begin scan PARTSUPP");
    for (;;) {
      bool x37353 = x37185;
      bool x37354 = !x37353;
      bool x37359 = x37354;
      if (x37354) {
        long x37355 = x37186;
        long x37356 = x36161;
        bool x37357 = x37355 < x37356;
        x37359 = x37357;
      }
      bool x37360 = x37359;
      if (!x37360) break;
      long x37362 = x37186;
      int* x37363 = x36163;
      int x37364 = x37363[x37362];
      int* x37365 = x36165;
      int x37366 = x37365[x37362];
      int* x37367 = x36167;
      int x37368 = x37367[x37362];
      x37186 = x37186 + 1;
      long x37375 = x37364 & x2212;
      long x37376 = x37207[x37375];
      long x37377 = x37376;
      bool x37378 = x37376 == -1L;
      bool x37379 = x37378;
      for (;;) {
        bool x37380 = x37379;
        bool x37381 = !x37380;
        if (!x37381) break;
        long x37383 = x37377;
        int* x37384 = x37189;
        int x37385 = x37384[x37383];
        bool x37403 = x37385 == x37364;
        if (x37403) {
          x37379 = true;
        } else {
          long x37406 = x37208[x37383];
          x37377 = x37406;
          bool x37408 = x37406 == -1;
          x37379 = x37408;
        }
      }
      long x37414 = x37377;
      bool x37416 = x37414 == -1;
      if (x37416) {
      } else {
        long x37417 = x37227;
        int* x37418 = x37218;
        x37418[x37417] = x37364;
        int* x37420 = x37220;
        x37420[x37417] = x37366;
        int* x37422 = x37222;
        x37422[x37417] = x37368;
        x37227 = x37227 + 1L;
        long x37429 = x37228[x37375];
        x37228[x37375] = x37417;
        x37229[x37417] = x37429;
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x37437 = x37213;
      bool x37438 = !x37437;
      bool x37443 = x37438;
      if (x37438) {
        long x37439 = x37214;
        long x37440 = x36389;
        bool x37441 = x37439 < x37440;
        x37443 = x37441;
      }
      bool x37444 = x37443;
      if (!x37444) break;
      long x37446 = x37214;
      int* x37449 = x36393;
      int x37450 = x37449[x37446];
      int* x37451 = x36395;
      int x37452 = x37451[x37446];
      double* x37455 = x36399;
      double x37456 = x37455[x37446];
      long* x37467 = x36411;
      long x37468 = x37467[x37446];
      x37214 = x37214 + 1;
      bool x37481 = x37468 >= 19940101L;
      bool x37483 = x37481;
      if (x37481) {
        bool x37482 = x37468 < 19950101L;
        x37483 = x37482;
      }
      bool x37484 = x37483;
      if (x37484) {
        long x37485 = x37450 & x2212;
        long x37486 = x37228[x37485];
        long x37487 = x37486;
        for (;;) {
          long x37488 = x37487;
          bool x37489 = x37488 != -1;
          if (!x37489) break;
          long x37491 = x37487;
          int* x37492 = x37218;
          int x37493 = x37492[x37491];
          int* x37494 = x37220;
          int x37495 = x37494[x37491];
          int* x37496 = x37222;
          int x37497 = x37496[x37491];
          long x37503 = x37229[x37491];
          x37487 = x37503;
          bool x37505 = x37493 == x37450;
          bool x37507 = x37505;
          if (x37505) {
            bool x37506 = x37495 == x37452;
            x37507 = x37506;
          }
          bool x37508 = x37507;
          if (x37508) {
            long x37513 = (long) x37497;
            long x37514 = x37513 * 41L;
            long x37515 = x37514 + x37493;
            long x37516 = x37515 * 41L;
            long x37517 = x37516 + x37495;
            long x37518 = x37517 & x823;
            long x37519 = x37518;
            struct Anon443803923* x37520 = x37237;
            struct Anon443803923 x37521 = x37520[x37518];
            struct Anon443803923 x37522 = x37521;
            bool x37523 = x37521.exists;;
            bool x37537 = x37523;
            if (x37523) {
              struct Anon443803923 x37524 = x37522;
              struct Anon1993309635 x37525 = x37524.key;;
              int x37526 = x37525.PS_PARTKEY;;
              bool x37527 = x37526 == x37493;
              bool x37532 = x37527;
              if (x37527) {
                int x37528 = x37525.PS_SUPPKEY;;
                bool x37529 = x37528 == x37495;
                x37532 = x37529;
              }
              bool x37533 = x37532;
              bool x37534 = x37533;
              if (x37533) {
                double x37530 = x37525.PS_AVAILQTY;;
                bool x37531 = x37530 == x37497;
                x37534 = x37531;
              }
              bool x37535 = x37534;
              x37537 = x37535;
            }
            bool x37538 = x37537;
            if (x37538) {
              double x37539 = x37521.aggs;;
              struct Anon1993309635 x37541 = x37521.key;;
              double x37540 = x37539 + x37456;
              struct Anon443803923 x37542;
              x37542.exists = true;
              x37542.key = x37541;
              x37542.aggs = x37540;
              x37520[x37518] = x37542;
            } else {
              struct Anon1993309635 x37512;
              x37512.PS_PARTKEY = x37493;
              x37512.PS_SUPPKEY = x37495;
              x37512.PS_AVAILQTY = x37497;
              struct Anon443803923 x37578;
              x37578.exists = true;
              x37578.key = x37512;
              x37578.aggs = x37456;
              for (;;) {
                struct Anon443803923 x37545 = x37522;
                bool x37546 = x37545.exists;;
                bool x37587;
                if (x37546) {
                  struct Anon1993309635 x37547 = x37545.key;;
                  int x37548 = x37547.PS_PARTKEY;;
                  bool x37549 = x37548 == x37493;
                  bool x37554 = x37549;
                  if (x37549) {
                    int x37550 = x37547.PS_SUPPKEY;;
                    bool x37551 = x37550 == x37495;
                    x37554 = x37551;
                  }
                  bool x37555 = x37554;
                  bool x37556 = x37555;
                  if (x37555) {
                    double x37552 = x37547.PS_AVAILQTY;;
                    bool x37553 = x37552 == x37497;
                    x37556 = x37553;
                  }
                  bool x37557 = x37556;
                  bool x37575;
                  if (x37557) {
                    double x37558 = x37545.aggs;;
                    long x37560 = x37519;
                    struct Anon443803923* x37562 = x37237;
                    double x37559 = x37558 + x37456;
                    struct Anon443803923 x37561;
                    x37561.exists = true;
                    x37561.key = x37547;
                    x37561.aggs = x37559;
                    x37562[x37560] = x37561;
                    x37575 = false;
                  } else {
                    long x37565 = x37519;
                    long x37566 = x37565 + 1L;
                    long x37567 = x37566 & x823;
                    x37519 = x37567;
                    struct Anon443803923* x37569 = x37237;
                    struct Anon443803923 x37570 = x37569[x37567];
                    x37522 = x37570;
                    x37575 = true;
                  }
                  x37587 = x37575;
                } else {
                  long x37577 = x37519;
                  struct Anon443803923* x37579 = x37237;
                  x37579[x37577] = x37578;
                  long x37581 = x37238;
                  x37239[x37581] = x37577;
                  x37238 = x37238 + 1L;
                  x37587 = false;
                }
                if (!x37587) break;
              }
            }
          } else {
          }
        }
      } else {
      }
    }
    long x37602 = x37238;
    long x37604;
    for(x37604=0L; x37604 < x37602; x37604++) {
      long x37605 = x37239[x37604];
      struct Anon443803923* x37606 = x37237;
      struct Anon443803923 x37607 = x37606[x37605];
      struct Anon1993309635 x37608 = x37607.key;;
      double x37610 = x37607.aggs;;
      double x37609 = x37608.PS_AVAILQTY;;
      double x37611 = 0.5 * x37610;
      bool x37612 = x37609 > x37611;
      if (x37612) {
        long x37614 = x37283;
        int* x37621 = x37278;
        int x37613 = x37608.PS_SUPPKEY;;
        x37621[x37614] = x37613;
        x37283 = x37283 + 1L;
        long x37628 = x37613 & x2212;
        long x37629 = x37284[x37628];
        x37284[x37628] = x37614;
        x37285[x37614] = x37629;
      } else {
      }
    }
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x37637 = x37252;
      bool x37638 = !x37637;
      bool x37643 = x37638;
      if (x37638) {
        long x37639 = x37253;
        long x37640 = x35739;
        bool x37641 = x37639 < x37640;
        x37643 = x37641;
      }
      bool x37644 = x37643;
      if (!x37644) break;
      long x37646 = x37253;
      int* x37647 = x35741;
      int x37648 = x37647[x37646];
      char** x37649 = x35743;
      char* x37650 = x37649[x37646];
      x37253 = x37253 + 1;
      bool x37657 = tpch_strcmp(x37650,"CANADA") == 0;;
      if (x37657) {
        long x37658 = x37264;
        int* x37659 = x37257;
        x37659[x37658] = x37648;
        x37264 = x37264 + 1L;
        long x37668 = x37648 & x2212;
        long x37669 = x37265[x37668];
        x37265[x37668] = x37658;
        x37266[x37658] = x37669;
      } else {
      }
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x37677 = x37250;
      bool x37678 = !x37677;
      bool x37683 = x37678;
      if (x37678) {
        long x37679 = x37251;
        long x37680 = x35889;
        bool x37681 = x37679 < x37680;
        x37683 = x37681;
      }
      bool x37684 = x37683;
      if (!x37684) break;
      long x37686 = x37251;
      int* x37687 = x35891;
      int x37688 = x37687[x37686];
      char** x37689 = x35893;
      char* x37690 = x37689[x37686];
      char** x37691 = x35895;
      char* x37692 = x37691[x37686];
      int* x37693 = x35897;
      int x37694 = x37693[x37686];
      x37251 = x37251 + 1;
      long x37703 = x37694 & x2212;
      long x37704 = x37265[x37703];
      long x37705 = x37704;
      long x37725 = x37688 & x2212;
      int x37762 = tpch_strlen(x37690);
      int x37763 = tpch_strlen(x37692);
      for (;;) {
        long x37706 = x37705;
        bool x37707 = x37706 != -1;
        if (!x37707) break;
        long x37709 = x37705;
        int* x37710 = x37257;
        int x37711 = x37710[x37709];
        long x37719 = x37266[x37709];
        x37705 = x37719;
        bool x37721 = x37711 == x37694;
        if (x37721) {
          long x37726 = x37284[x37725];
          long x37727 = x37726;
          bool x37728 = x37726 == -1L;
          bool x37729 = x37728;
          for (;;) {
            bool x37730 = x37729;
            bool x37731 = !x37730;
            if (!x37731) break;
            long x37733 = x37727;
            int* x37738 = x37278;
            int x37739 = x37738[x37733];
            bool x37746 = x37688 == x37739;
            if (x37746) {
              x37729 = true;
            } else {
              long x37749 = x37285[x37733];
              x37727 = x37749;
              bool x37751 = x37749 == -1;
              x37729 = x37751;
            }
          }
          long x37757 = x37727;
          bool x37759 = x37757 == -1;
          if (x37759) {
          } else {
            if (x1043) {
            } else {
              printf("%.*s|%.*s\n",x37762,x37690,x37763,x37692);
              x37291 = x37291 + 1L;
            }
          }
        } else {
        }
      }
    }
    long x37776 = x37291;
    printf("(%ld rows)\n",x37776);
    gettimeofday(&x37780, NULL);
    timeval_subtract(&x37781, &x37780, &x37779);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x37781.tv_sec * 1000) + (x37781.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
