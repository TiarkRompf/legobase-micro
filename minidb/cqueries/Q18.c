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

struct Anon0 {
struct Anon964248194 left;
struct Anon920667905 right;
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

struct Anon1621811895 {
char* C_NAME;
int C_CUSTKEY;
int O_ORDERKEY;
long O_ORDERDATE;
double O_TOTALPRICE;
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

struct Anon1918636998 {
bool exists;
struct Anon1621811895 key;
struct Anon2052879266 aggs;
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
int x33826(struct Anon1918636998* x33807, struct Anon1918636998* x33808);
int x33826(struct Anon1918636998* x33807, struct Anon1918636998* x33808) {
  struct Anon1918636998 x33809 = (*x33807);
  struct Anon1918636998 x33810 = (*x33808);
  struct Anon1621811895 x33811 = x33809.key;;
  double x33812 = x33811.O_TOTALPRICE;;
  struct Anon1621811895 x33813 = x33810.key;;
  double x33814 = x33813.O_TOTALPRICE;;
  bool x33815 = x33812 < x33814;
  int x33824;
  if (x33815) {
    x33824 = 1;
  } else {
    bool x33816 = x33812 > x33814;
    int x33823;
    if (x33816) {
      x33823 = -1;
    } else {
      long x33817 = x33811.O_ORDERDATE;;
      long x33818 = x33813.O_ORDERDATE;;
      bool x33819 = x33817 < x33818;
      int x33822;
      if (x33819) {
        x33822 = -1;
      } else {
        bool x33820 = x33817 > x33818;
        int x33821;
        if (x33820) {
          x33821 = 1;
        } else {
          x33821 = 0;
        }
        x33822 = x33821;
      }
      x33823 = x33822;
    }
    x33824 = x33823;
  }
  return x33824;
}

/************************ MAIN BODY **************************/
int main(int x31817, char** x31818) {
  long x31819 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x31820 = x7;
  long x31821 = 0L;
  int* x31822 = (int*)malloc(x7 * sizeof(int));
  int* x31823 = x31822;
  double* x31830 = (double*)malloc(x7 * sizeof(double));
  double* x31831 = x31830;
  int x3 = open("XXXXXlineitem.tbl",0);
  long x4 = fsize(x3);
  char* x5 = mmap(0, x4, PROT_READ, MAP_FILE | MAP_SHARED, x3, 0);
  for (;;) {
    long x31854 = x31819;
    bool x31855 = x31854 < x4;
    if (!x31855) break;
    int x31858 = 0;
    for (;;) {
      long x31859 = x31819;
      char x31860 = x5[x31859];
      bool x31861 = x31860 != '|';
      bool x31866 = x31861;
      if (x31861) {
        long x31862 = x31819;
        char x31863 = x5[x31862];
        bool x31864 = x31863 != '\n';
        x31866 = x31864;
      }
      bool x31867 = x31866;
      if (!x31867) break;
      int x31869 = x31858;
      long x31871 = x31819;
      int x31870 = x31869 * 10;
      char x31872 = x5[x31871];
      char x31873 = x31872 - '0';
      int x31874 = x31870 + x31873;
      x31858 = x31874;
      x31819 = x31819 + 1;
    }
    x31819 = x31819 + 1;
    int x31880 = x31858;
    for (;;) {
      long x31883 = x31819;
      char x31884 = x5[x31883];
      bool x31885 = x31884 != '|';
      bool x31890 = x31885;
      if (x31885) {
        long x31886 = x31819;
        char x31887 = x5[x31886];
        bool x31888 = x31887 != '\n';
        x31890 = x31888;
      }
      bool x31891 = x31890;
      if (!x31891) break;
      x31819 = x31819 + 1;
    }
    x31819 = x31819 + 1;
    for (;;) {
      long x31907 = x31819;
      char x31908 = x5[x31907];
      bool x31909 = x31908 != '|';
      bool x31914 = x31909;
      if (x31909) {
        long x31910 = x31819;
        char x31911 = x5[x31910];
        bool x31912 = x31911 != '\n';
        x31914 = x31912;
      }
      bool x31915 = x31914;
      if (!x31915) break;
      x31819 = x31819 + 1;
    }
    x31819 = x31819 + 1;
    for (;;) {
      long x31931 = x31819;
      char x31932 = x5[x31931];
      bool x31933 = x31932 != '|';
      bool x31938 = x31933;
      if (x31933) {
        long x31934 = x31819;
        char x31935 = x5[x31934];
        bool x31936 = x31935 != '\n';
        x31938 = x31936;
      }
      bool x31939 = x31938;
      if (!x31939) break;
      x31819 = x31819 + 1;
    }
    x31819 = x31819 + 1;
    int x31954 = 0;
    int x31955 = 1;
    for (;;) {
      long x31956 = x31819;
      char x31957 = x5[x31956];
      bool x31958 = x31957 != '.';
      bool x31963 = x31958;
      if (x31958) {
        long x31959 = x31819;
        char x31960 = x5[x31959];
        bool x31961 = x31960 != '|';
        x31963 = x31961;
      }
      bool x31964 = x31963;
      bool x31969 = x31964;
      if (x31964) {
        long x31965 = x31819;
        char x31966 = x5[x31965];
        bool x31967 = x31966 != '\n';
        x31969 = x31967;
      }
      bool x31970 = x31969;
      if (!x31970) break;
      int x31972 = x31954;
      long x31974 = x31819;
      int x31973 = x31972 * 10;
      char x31975 = x5[x31974];
      char x31976 = x31975 - '0';
      int x31977 = x31973 + x31976;
      x31954 = x31977;
      x31819 = x31819 + 1;
    }
    long x31982 = x31819;
    char x31983 = x5[x31982];
    bool x31984 = x31983 == '.';
    if (x31984) {
      x31819 = x31819 + 1;
      for (;;) {
        long x31986 = x31819;
        char x31987 = x5[x31986];
        bool x31988 = x31987 != '|';
        bool x31993 = x31988;
        if (x31988) {
          long x31989 = x31819;
          char x31990 = x5[x31989];
          bool x31991 = x31990 != '\n';
          x31993 = x31991;
        }
        bool x31994 = x31993;
        if (!x31994) break;
        int x31996 = x31954;
        long x31998 = x31819;
        int x31997 = x31996 * 10;
        char x31999 = x5[x31998];
        char x32000 = x31999 - '0';
        int x32001 = x31997 + x32000;
        x31954 = x32001;
        int x32003 = x31955;
        int x32004 = x32003 * 10;
        x31955 = x32004;
        x31819 = x31819 + 1;
      }
    } else {
    }
    x31819 = x31819 + 1;
    int x32013 = x31954;
    int x32015 = x31955;
    for (;;) {
      long x32021 = x31819;
      char x32022 = x5[x32021];
      bool x32023 = x32022 != '.';
      bool x32028 = x32023;
      if (x32023) {
        long x32024 = x31819;
        char x32025 = x5[x32024];
        bool x32026 = x32025 != '|';
        x32028 = x32026;
      }
      bool x32029 = x32028;
      bool x32034 = x32029;
      if (x32029) {
        long x32030 = x31819;
        char x32031 = x5[x32030];
        bool x32032 = x32031 != '\n';
        x32034 = x32032;
      }
      bool x32035 = x32034;
      if (!x32035) break;
      x31819 = x31819 + 1;
    }
    long x32047 = x31819;
    char x32048 = x5[x32047];
    bool x32049 = x32048 == '.';
    if (x32049) {
      x31819 = x31819 + 1;
      for (;;) {
        long x32051 = x31819;
        char x32052 = x5[x32051];
        bool x32053 = x32052 != '|';
        bool x32058 = x32053;
        if (x32053) {
          long x32054 = x31819;
          char x32055 = x5[x32054];
          bool x32056 = x32055 != '\n';
          x32058 = x32056;
        }
        bool x32059 = x32058;
        if (!x32059) break;
        x31819 = x31819 + 1;
      }
    } else {
    }
    x31819 = x31819 + 1;
    for (;;) {
      long x32086 = x31819;
      char x32087 = x5[x32086];
      bool x32088 = x32087 != '.';
      bool x32093 = x32088;
      if (x32088) {
        long x32089 = x31819;
        char x32090 = x5[x32089];
        bool x32091 = x32090 != '|';
        x32093 = x32091;
      }
      bool x32094 = x32093;
      bool x32099 = x32094;
      if (x32094) {
        long x32095 = x31819;
        char x32096 = x5[x32095];
        bool x32097 = x32096 != '\n';
        x32099 = x32097;
      }
      bool x32100 = x32099;
      if (!x32100) break;
      x31819 = x31819 + 1;
    }
    long x32112 = x31819;
    char x32113 = x5[x32112];
    bool x32114 = x32113 == '.';
    if (x32114) {
      x31819 = x31819 + 1;
      for (;;) {
        long x32116 = x31819;
        char x32117 = x5[x32116];
        bool x32118 = x32117 != '|';
        bool x32123 = x32118;
        if (x32118) {
          long x32119 = x31819;
          char x32120 = x5[x32119];
          bool x32121 = x32120 != '\n';
          x32123 = x32121;
        }
        bool x32124 = x32123;
        if (!x32124) break;
        x31819 = x31819 + 1;
      }
    } else {
    }
    x31819 = x31819 + 1;
    for (;;) {
      long x32151 = x31819;
      char x32152 = x5[x32151];
      bool x32153 = x32152 != '.';
      bool x32158 = x32153;
      if (x32153) {
        long x32154 = x31819;
        char x32155 = x5[x32154];
        bool x32156 = x32155 != '|';
        x32158 = x32156;
      }
      bool x32159 = x32158;
      bool x32164 = x32159;
      if (x32159) {
        long x32160 = x31819;
        char x32161 = x5[x32160];
        bool x32162 = x32161 != '\n';
        x32164 = x32162;
      }
      bool x32165 = x32164;
      if (!x32165) break;
      x31819 = x31819 + 1;
    }
    long x32177 = x31819;
    char x32178 = x5[x32177];
    bool x32179 = x32178 == '.';
    if (x32179) {
      x31819 = x31819 + 1;
      for (;;) {
        long x32181 = x31819;
        char x32182 = x5[x32181];
        bool x32183 = x32182 != '|';
        bool x32188 = x32183;
        if (x32183) {
          long x32184 = x31819;
          char x32185 = x5[x32184];
          bool x32186 = x32185 != '\n';
          x32188 = x32186;
        }
        bool x32189 = x32188;
        if (!x32189) break;
        x31819 = x31819 + 1;
      }
    } else {
    }
    x31819 = x31819 + 1;
    x31819 = x31819 + 2;
    x31819 = x31819 + 2;
    for (;;) {
      long x32221 = x31819;
      char x32222 = x5[x32221];
      bool x32223 = x32222 != '-';
      bool x32228 = x32223;
      if (x32223) {
        long x32224 = x31819;
        char x32225 = x5[x32224];
        bool x32226 = x32225 != '\n';
        x32228 = x32226;
      }
      bool x32229 = x32228;
      if (!x32229) break;
      x31819 = x31819 + 1;
    }
    x31819 = x31819 + 1;
    for (;;) {
      long x32245 = x31819;
      char x32246 = x5[x32245];
      bool x32247 = x32246 != '-';
      bool x32252 = x32247;
      if (x32247) {
        long x32248 = x31819;
        char x32249 = x5[x32248];
        bool x32250 = x32249 != '\n';
        x32252 = x32250;
      }
      bool x32253 = x32252;
      if (!x32253) break;
      x31819 = x31819 + 1;
    }
    x31819 = x31819 + 1;
    for (;;) {
      long x32269 = x31819;
      char x32270 = x5[x32269];
      bool x32271 = x32270 != '|';
      bool x32276 = x32271;
      if (x32271) {
        long x32272 = x31819;
        char x32273 = x5[x32272];
        bool x32274 = x32273 != '\n';
        x32276 = x32274;
      }
      bool x32277 = x32276;
      if (!x32277) break;
      x31819 = x31819 + 1;
    }
    x31819 = x31819 + 1;
    for (;;) {
      long x32297 = x31819;
      char x32298 = x5[x32297];
      bool x32299 = x32298 != '-';
      bool x32304 = x32299;
      if (x32299) {
        long x32300 = x31819;
        char x32301 = x5[x32300];
        bool x32302 = x32301 != '\n';
        x32304 = x32302;
      }
      bool x32305 = x32304;
      if (!x32305) break;
      x31819 = x31819 + 1;
    }
    x31819 = x31819 + 1;
    for (;;) {
      long x32321 = x31819;
      char x32322 = x5[x32321];
      bool x32323 = x32322 != '-';
      bool x32328 = x32323;
      if (x32323) {
        long x32324 = x31819;
        char x32325 = x5[x32324];
        bool x32326 = x32325 != '\n';
        x32328 = x32326;
      }
      bool x32329 = x32328;
      if (!x32329) break;
      x31819 = x31819 + 1;
    }
    x31819 = x31819 + 1;
    for (;;) {
      long x32345 = x31819;
      char x32346 = x5[x32345];
      bool x32347 = x32346 != '|';
      bool x32352 = x32347;
      if (x32347) {
        long x32348 = x31819;
        char x32349 = x5[x32348];
        bool x32350 = x32349 != '\n';
        x32352 = x32350;
      }
      bool x32353 = x32352;
      if (!x32353) break;
      x31819 = x31819 + 1;
    }
    x31819 = x31819 + 1;
    for (;;) {
      long x32373 = x31819;
      char x32374 = x5[x32373];
      bool x32375 = x32374 != '-';
      bool x32380 = x32375;
      if (x32375) {
        long x32376 = x31819;
        char x32377 = x5[x32376];
        bool x32378 = x32377 != '\n';
        x32380 = x32378;
      }
      bool x32381 = x32380;
      if (!x32381) break;
      x31819 = x31819 + 1;
    }
    x31819 = x31819 + 1;
    for (;;) {
      long x32397 = x31819;
      char x32398 = x5[x32397];
      bool x32399 = x32398 != '-';
      bool x32404 = x32399;
      if (x32399) {
        long x32400 = x31819;
        char x32401 = x5[x32400];
        bool x32402 = x32401 != '\n';
        x32404 = x32402;
      }
      bool x32405 = x32404;
      if (!x32405) break;
      x31819 = x31819 + 1;
    }
    x31819 = x31819 + 1;
    for (;;) {
      long x32421 = x31819;
      char x32422 = x5[x32421];
      bool x32423 = x32422 != '|';
      bool x32428 = x32423;
      if (x32423) {
        long x32424 = x31819;
        char x32425 = x5[x32424];
        bool x32426 = x32425 != '\n';
        x32428 = x32426;
      }
      bool x32429 = x32428;
      if (!x32429) break;
      x31819 = x31819 + 1;
    }
    x31819 = x31819 + 1;
    for (;;) {
      long x32448 = x31819;
      char x32449 = x5[x32448];
      bool x32450 = x32449 != '|';
      bool x32455 = x32450;
      if (x32450) {
        long x32451 = x31819;
        char x32452 = x5[x32451];
        bool x32453 = x32452 != '\n';
        x32455 = x32453;
      }
      bool x32456 = x32455;
      if (!x32456) break;
      x31819 = x31819 + 1;
    }
    x31819 = x31819 + 1;
    for (;;) {
      long x32466 = x31819;
      char x32467 = x5[x32466];
      bool x32468 = x32467 != '|';
      bool x32473 = x32468;
      if (x32468) {
        long x32469 = x31819;
        char x32470 = x5[x32469];
        bool x32471 = x32470 != '\n';
        x32473 = x32471;
      }
      bool x32474 = x32473;
      if (!x32474) break;
      x31819 = x31819 + 1;
    }
    x31819 = x31819 + 1;
    for (;;) {
      long x32484 = x31819;
      char x32485 = x5[x32484];
      bool x32486 = x32485 != '|';
      bool x32491 = x32486;
      if (x32486) {
        long x32487 = x31819;
        char x32488 = x5[x32487];
        bool x32489 = x32488 != '\n';
        x32491 = x32489;
      }
      bool x32492 = x32491;
      if (!x32492) break;
      x31819 = x31819 + 1;
    }
    x31819 = x31819 + 1;
    long x32502 = x31819;
    bool x32503 = x32502 > 0L;
    bool x32509 = x32503;
    if (x32503) {
      long x32504 = x31819;
      long x32505 = x32504 - 1L;
      char x32506 = x5[x32505];
      bool x32507 = x32506 != '\n';
      x32509 = x32507;
    }
    bool x32510 = x32509;
    if (x32510) {
      for (;;) {
        long x32511 = x31819;
        char x32512 = x5[x32511];
        bool x32513 = x32512 != '\n';
        if (!x32513) break;
        x31819 = x31819 + 1;
      }
    } else {
    }
    x31819 = x31819 + 1;
    long x32522 = x31821;
    long x32523 = x31820;
    bool x32524 = x32522 == x32523;
    if (x32524) {
      long x32525 = x32523 * 4L;
      x31820 = x32525;
      printf("buffer.resize %ld\n",x32525);
      int* x32528 = x31823;
      int* x32529 = (int*)realloc(x32528,x32525 * sizeof(int));
      x31823 = x32529;
      double* x32540 = x31831;
      double* x32541 = (double*)realloc(x32540,x32525 * sizeof(double));
      x31831 = x32541;
    } else {
    }
    int* x32578 = x31823;
    x32578[x32522] = x31880;
    double* x32586 = x31831;
    double x32014 = (double)x32013;
    double x32016 = (double)x32015;
    double x32017 = x32014 / x32016;
    x32586[x32522] = x32017;
    x31821 = x31821 + 1;
  }
  long x32613 = 0L;
  long x32614 = x7;
  long x32615 = 0L;
  int* x32616 = (int*)malloc(x7 * sizeof(int));
  int* x32617 = x32616;
  int* x32618 = (int*)malloc(x7 * sizeof(int));
  int* x32619 = x32618;
  double* x32622 = (double*)malloc(x7 * sizeof(double));
  double* x32623 = x32622;
  long* x32624 = (long*)malloc(x7 * sizeof(long));
  long* x32625 = x32624;
  int x3633 = open("XXXXXorders.tbl",0);
  long x3634 = fsize(x3633);
  char* x3635 = mmap(0, x3634, PROT_READ, MAP_FILE | MAP_SHARED, x3633, 0);
  for (;;) {
    long x32634 = x32613;
    bool x32635 = x32634 < x3634;
    if (!x32635) break;
    int x32638 = 0;
    for (;;) {
      long x32639 = x32613;
      char x32640 = x3635[x32639];
      bool x32641 = x32640 != '|';
      bool x32646 = x32641;
      if (x32641) {
        long x32642 = x32613;
        char x32643 = x3635[x32642];
        bool x32644 = x32643 != '\n';
        x32646 = x32644;
      }
      bool x32647 = x32646;
      if (!x32647) break;
      int x32649 = x32638;
      long x32651 = x32613;
      int x32650 = x32649 * 10;
      char x32652 = x3635[x32651];
      char x32653 = x32652 - '0';
      int x32654 = x32650 + x32653;
      x32638 = x32654;
      x32613 = x32613 + 1;
    }
    x32613 = x32613 + 1;
    int x32660 = x32638;
    int x32662 = 0;
    for (;;) {
      long x32663 = x32613;
      char x32664 = x3635[x32663];
      bool x32665 = x32664 != '|';
      bool x32670 = x32665;
      if (x32665) {
        long x32666 = x32613;
        char x32667 = x3635[x32666];
        bool x32668 = x32667 != '\n';
        x32670 = x32668;
      }
      bool x32671 = x32670;
      if (!x32671) break;
      int x32673 = x32662;
      long x32675 = x32613;
      int x32674 = x32673 * 10;
      char x32676 = x3635[x32675];
      char x32677 = x32676 - '0';
      int x32678 = x32674 + x32677;
      x32662 = x32678;
      x32613 = x32613 + 1;
    }
    x32613 = x32613 + 1;
    int x32684 = x32662;
    x32613 = x32613 + 2;
    int x32689 = 0;
    int x32690 = 1;
    for (;;) {
      long x32691 = x32613;
      char x32692 = x3635[x32691];
      bool x32693 = x32692 != '.';
      bool x32698 = x32693;
      if (x32693) {
        long x32694 = x32613;
        char x32695 = x3635[x32694];
        bool x32696 = x32695 != '|';
        x32698 = x32696;
      }
      bool x32699 = x32698;
      bool x32704 = x32699;
      if (x32699) {
        long x32700 = x32613;
        char x32701 = x3635[x32700];
        bool x32702 = x32701 != '\n';
        x32704 = x32702;
      }
      bool x32705 = x32704;
      if (!x32705) break;
      int x32707 = x32689;
      long x32709 = x32613;
      int x32708 = x32707 * 10;
      char x32710 = x3635[x32709];
      char x32711 = x32710 - '0';
      int x32712 = x32708 + x32711;
      x32689 = x32712;
      x32613 = x32613 + 1;
    }
    long x32717 = x32613;
    char x32718 = x3635[x32717];
    bool x32719 = x32718 == '.';
    if (x32719) {
      x32613 = x32613 + 1;
      for (;;) {
        long x32721 = x32613;
        char x32722 = x3635[x32721];
        bool x32723 = x32722 != '|';
        bool x32728 = x32723;
        if (x32723) {
          long x32724 = x32613;
          char x32725 = x3635[x32724];
          bool x32726 = x32725 != '\n';
          x32728 = x32726;
        }
        bool x32729 = x32728;
        if (!x32729) break;
        int x32731 = x32689;
        long x32733 = x32613;
        int x32732 = x32731 * 10;
        char x32734 = x3635[x32733];
        char x32735 = x32734 - '0';
        int x32736 = x32732 + x32735;
        x32689 = x32736;
        int x32738 = x32690;
        int x32739 = x32738 * 10;
        x32690 = x32739;
        x32613 = x32613 + 1;
      }
    } else {
    }
    x32613 = x32613 + 1;
    int x32748 = x32689;
    int x32750 = x32690;
    int x32754 = 0;
    for (;;) {
      long x32755 = x32613;
      char x32756 = x3635[x32755];
      bool x32757 = x32756 != '-';
      bool x32762 = x32757;
      if (x32757) {
        long x32758 = x32613;
        char x32759 = x3635[x32758];
        bool x32760 = x32759 != '\n';
        x32762 = x32760;
      }
      bool x32763 = x32762;
      if (!x32763) break;
      int x32765 = x32754;
      long x32767 = x32613;
      int x32766 = x32765 * 10;
      char x32768 = x3635[x32767];
      char x32769 = x32768 - '0';
      int x32770 = x32766 + x32769;
      x32754 = x32770;
      x32613 = x32613 + 1;
    }
    x32613 = x32613 + 1;
    int x32776 = x32754;
    int x32778 = 0;
    for (;;) {
      long x32779 = x32613;
      char x32780 = x3635[x32779];
      bool x32781 = x32780 != '-';
      bool x32786 = x32781;
      if (x32781) {
        long x32782 = x32613;
        char x32783 = x3635[x32782];
        bool x32784 = x32783 != '\n';
        x32786 = x32784;
      }
      bool x32787 = x32786;
      if (!x32787) break;
      int x32789 = x32778;
      long x32791 = x32613;
      int x32790 = x32789 * 10;
      char x32792 = x3635[x32791];
      char x32793 = x32792 - '0';
      int x32794 = x32790 + x32793;
      x32778 = x32794;
      x32613 = x32613 + 1;
    }
    x32613 = x32613 + 1;
    int x32800 = x32778;
    int x32802 = 0;
    for (;;) {
      long x32803 = x32613;
      char x32804 = x3635[x32803];
      bool x32805 = x32804 != '|';
      bool x32810 = x32805;
      if (x32805) {
        long x32806 = x32613;
        char x32807 = x3635[x32806];
        bool x32808 = x32807 != '\n';
        x32810 = x32808;
      }
      bool x32811 = x32810;
      if (!x32811) break;
      int x32813 = x32802;
      long x32815 = x32613;
      int x32814 = x32813 * 10;
      char x32816 = x3635[x32815];
      char x32817 = x32816 - '0';
      int x32818 = x32814 + x32817;
      x32802 = x32818;
      x32613 = x32613 + 1;
    }
    x32613 = x32613 + 1;
    int x32824 = x32802;
    for (;;) {
      long x32830 = x32613;
      char x32831 = x3635[x32830];
      bool x32832 = x32831 != '|';
      bool x32837 = x32832;
      if (x32832) {
        long x32833 = x32613;
        char x32834 = x3635[x32833];
        bool x32835 = x32834 != '\n';
        x32837 = x32835;
      }
      bool x32838 = x32837;
      if (!x32838) break;
      x32613 = x32613 + 1;
    }
    x32613 = x32613 + 1;
    for (;;) {
      long x32848 = x32613;
      char x32849 = x3635[x32848];
      bool x32850 = x32849 != '|';
      bool x32855 = x32850;
      if (x32850) {
        long x32851 = x32613;
        char x32852 = x3635[x32851];
        bool x32853 = x32852 != '\n';
        x32855 = x32853;
      }
      bool x32856 = x32855;
      if (!x32856) break;
      x32613 = x32613 + 1;
    }
    x32613 = x32613 + 1;
    for (;;) {
      long x32867 = x32613;
      char x32868 = x3635[x32867];
      bool x32869 = x32868 != '|';
      bool x32874 = x32869;
      if (x32869) {
        long x32870 = x32613;
        char x32871 = x3635[x32870];
        bool x32872 = x32871 != '\n';
        x32874 = x32872;
      }
      bool x32875 = x32874;
      if (!x32875) break;
      x32613 = x32613 + 1;
    }
    x32613 = x32613 + 1;
    for (;;) {
      long x32890 = x32613;
      char x32891 = x3635[x32890];
      bool x32892 = x32891 != '|';
      bool x32897 = x32892;
      if (x32892) {
        long x32893 = x32613;
        char x32894 = x3635[x32893];
        bool x32895 = x32894 != '\n';
        x32897 = x32895;
      }
      bool x32898 = x32897;
      if (!x32898) break;
      x32613 = x32613 + 1;
    }
    x32613 = x32613 + 1;
    long x32908 = x32613;
    bool x32909 = x32908 > 0L;
    bool x32915 = x32909;
    if (x32909) {
      long x32910 = x32613;
      long x32911 = x32910 - 1L;
      char x32912 = x3635[x32911];
      bool x32913 = x32912 != '\n';
      x32915 = x32913;
    }
    bool x32916 = x32915;
    if (x32916) {
      for (;;) {
        long x32917 = x32613;
        char x32918 = x3635[x32917];
        bool x32919 = x32918 != '\n';
        if (!x32919) break;
        x32613 = x32613 + 1;
      }
    } else {
    }
    x32613 = x32613 + 1;
    long x32928 = x32615;
    long x32929 = x32614;
    bool x32930 = x32928 == x32929;
    if (x32930) {
      long x32931 = x32929 * 4L;
      x32614 = x32931;
      printf("buffer.resize %ld\n",x32931);
      int* x32934 = x32617;
      int* x32935 = (int*)realloc(x32934,x32931 * sizeof(int));
      x32617 = x32935;
      int* x32937 = x32619;
      int* x32938 = (int*)realloc(x32937,x32931 * sizeof(int));
      x32619 = x32938;
      double* x32943 = x32623;
      double* x32944 = (double*)realloc(x32943,x32931 * sizeof(double));
      x32623 = x32944;
      long* x32946 = x32625;
      long* x32947 = (long*)realloc(x32946,x32931 * sizeof(long));
      x32625 = x32947;
    } else {
    }
    int* x32963 = x32617;
    x32963[x32928] = x32660;
    int* x32965 = x32619;
    x32965[x32928] = x32684;
    double* x32969 = x32623;
    double x32749 = (double)x32748;
    double x32751 = (double)x32750;
    double x32752 = x32749 / x32751;
    x32969[x32928] = x32752;
    long* x32971 = x32625;
    long x32825 = x32776 * 10000L;
    long x32826 = x32800 * 100L;
    long x32827 = x32825 + x32826;
    long x32828 = x32827 + x32824;
    x32971[x32928] = x32828;
    x32615 = x32615 + 1;
  }
  long x32984 = 0L;
  long x32985 = x7;
  long x32986 = 0L;
  int* x32987 = (int*)malloc(x7 * sizeof(int));
  int* x32988 = x32987;
  char** x32989 = (char**)malloc(x7 * sizeof(char*));
  char** x32990 = x32989;
  int x4007 = open("XXXXXcustomer.tbl",0);
  long x4008 = fsize(x4007);
  char* x4009 = mmap(0, x4008, PROT_READ, MAP_FILE | MAP_SHARED, x4007, 0);
  for (;;) {
    long x33003 = x32984;
    bool x33004 = x33003 < x4008;
    if (!x33004) break;
    int x33007 = 0;
    for (;;) {
      long x33008 = x32984;
      char x33009 = x4009[x33008];
      bool x33010 = x33009 != '|';
      bool x33015 = x33010;
      if (x33010) {
        long x33011 = x32984;
        char x33012 = x4009[x33011];
        bool x33013 = x33012 != '\n';
        x33015 = x33013;
      }
      bool x33016 = x33015;
      if (!x33016) break;
      int x33018 = x33007;
      long x33020 = x32984;
      int x33019 = x33018 * 10;
      char x33021 = x4009[x33020];
      char x33022 = x33021 - '0';
      int x33023 = x33019 + x33022;
      x33007 = x33023;
      x32984 = x32984 + 1;
    }
    x32984 = x32984 + 1;
    int x33029 = x33007;
    long x33030 = x32984;
    for (;;) {
      long x33031 = x32984;
      char x33032 = x4009[x33031];
      bool x33033 = x33032 != '|';
      bool x33038 = x33033;
      if (x33033) {
        long x33034 = x32984;
        char x33035 = x4009[x33034];
        bool x33036 = x33035 != '\n';
        x33038 = x33036;
      }
      bool x33039 = x33038;
      if (!x33039) break;
      x32984 = x32984 + 1;
    }
    x32984 = x32984 + 1;
    for (;;) {
      long x33049 = x32984;
      char x33050 = x4009[x33049];
      bool x33051 = x33050 != '|';
      bool x33056 = x33051;
      if (x33051) {
        long x33052 = x32984;
        char x33053 = x4009[x33052];
        bool x33054 = x33053 != '\n';
        x33056 = x33054;
      }
      bool x33057 = x33056;
      if (!x33057) break;
      x32984 = x32984 + 1;
    }
    x32984 = x32984 + 1;
    for (;;) {
      long x33068 = x32984;
      char x33069 = x4009[x33068];
      bool x33070 = x33069 != '|';
      bool x33075 = x33070;
      if (x33070) {
        long x33071 = x32984;
        char x33072 = x4009[x33071];
        bool x33073 = x33072 != '\n';
        x33075 = x33073;
      }
      bool x33076 = x33075;
      if (!x33076) break;
      x32984 = x32984 + 1;
    }
    x32984 = x32984 + 1;
    for (;;) {
      long x33091 = x32984;
      char x33092 = x4009[x33091];
      bool x33093 = x33092 != '|';
      bool x33098 = x33093;
      if (x33093) {
        long x33094 = x32984;
        char x33095 = x4009[x33094];
        bool x33096 = x33095 != '\n';
        x33098 = x33096;
      }
      bool x33099 = x33098;
      if (!x33099) break;
      x32984 = x32984 + 1;
    }
    x32984 = x32984 + 1;
    for (;;) {
      long x33111 = x32984;
      char x33112 = x4009[x33111];
      bool x33113 = x33112 != '.';
      bool x33118 = x33113;
      if (x33113) {
        long x33114 = x32984;
        char x33115 = x4009[x33114];
        bool x33116 = x33115 != '|';
        x33118 = x33116;
      }
      bool x33119 = x33118;
      bool x33124 = x33119;
      if (x33119) {
        long x33120 = x32984;
        char x33121 = x4009[x33120];
        bool x33122 = x33121 != '\n';
        x33124 = x33122;
      }
      bool x33125 = x33124;
      if (!x33125) break;
      x32984 = x32984 + 1;
    }
    long x33137 = x32984;
    char x33138 = x4009[x33137];
    bool x33139 = x33138 == '.';
    if (x33139) {
      x32984 = x32984 + 1;
      for (;;) {
        long x33141 = x32984;
        char x33142 = x4009[x33141];
        bool x33143 = x33142 != '|';
        bool x33148 = x33143;
        if (x33143) {
          long x33144 = x32984;
          char x33145 = x4009[x33144];
          bool x33146 = x33145 != '\n';
          x33148 = x33146;
        }
        bool x33149 = x33148;
        if (!x33149) break;
        x32984 = x32984 + 1;
      }
    } else {
    }
    x32984 = x32984 + 1;
    for (;;) {
      long x33174 = x32984;
      char x33175 = x4009[x33174];
      bool x33176 = x33175 != '|';
      bool x33181 = x33176;
      if (x33176) {
        long x33177 = x32984;
        char x33178 = x4009[x33177];
        bool x33179 = x33178 != '\n';
        x33181 = x33179;
      }
      bool x33182 = x33181;
      if (!x33182) break;
      x32984 = x32984 + 1;
    }
    x32984 = x32984 + 1;
    for (;;) {
      long x33192 = x32984;
      char x33193 = x4009[x33192];
      bool x33194 = x33193 != '|';
      bool x33199 = x33194;
      if (x33194) {
        long x33195 = x32984;
        char x33196 = x4009[x33195];
        bool x33197 = x33196 != '\n';
        x33199 = x33197;
      }
      bool x33200 = x33199;
      if (!x33200) break;
      x32984 = x32984 + 1;
    }
    x32984 = x32984 + 1;
    long x33210 = x32984;
    bool x33211 = x33210 > 0L;
    bool x33217 = x33211;
    if (x33211) {
      long x33212 = x32984;
      long x33213 = x33212 - 1L;
      char x33214 = x4009[x33213];
      bool x33215 = x33214 != '\n';
      x33217 = x33215;
    }
    bool x33218 = x33217;
    if (x33218) {
      for (;;) {
        long x33219 = x32984;
        char x33220 = x4009[x33219];
        bool x33221 = x33220 != '\n';
        if (!x33221) break;
        x32984 = x32984 + 1;
      }
    } else {
    }
    x32984 = x32984 + 1;
    long x33230 = x32986;
    long x33231 = x32985;
    bool x33232 = x33230 == x33231;
    if (x33232) {
      long x33233 = x33231 * 4L;
      x32985 = x33233;
      printf("buffer.resize %ld\n",x33233);
      int* x33236 = x32988;
      int* x33237 = (int*)realloc(x33236,x33233 * sizeof(int));
      x32988 = x33237;
      char** x33239 = x32990;
      char** x33240 = (char**)realloc(x33239,x33233 * sizeof(char*));
      x32990 = x33240;
    } else {
    }
    int* x33262 = x32988;
    x33262[x33230] = x33029;
    char** x33264 = x32990;
    char* x33047 = x4009+x33030;
    x33264[x33230] = x33047;
    x32986 = x32986 + 1;
  }
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  long x2189 = DEFAULT_JOIN_HASH_SIZE;
  long x823 = x808 - 1L;
  float x33491 = (float)300;
  double x33492 = (double)x33491;
  long x2212 = x2189 - 1L;
  int x33281;
  for(x33281=0; x33281 < 5; x33281++) {
    bool x33282 = false;
    long x33283 = 0L;
    bool x33284 = false;
    long x33285 = 0L;
    bool x33286 = false;
    long x33287 = 0L;
    struct Anon152692660* x33289 = (struct Anon152692660*)malloc(x808 * sizeof(struct Anon152692660));
    struct Anon152692660* x33290 = x33289;
    long x33291 = 0L;
    long* x33292 = (long*)malloc(x808 * sizeof(long));
    long x33293;
    for(x33293=0L; x33293 < x808; x33293++) {
      struct Anon152692660* x33294 = x33290;
      struct Anon152692660 x33295 = x33294[x33293];
      int x33296 = x33295.key;;
      struct Anon2052879266 x33297 = x33295.aggs;;
      struct Anon152692660 x33298;
      x33298.exists = false;
      x33298.key = x33296;
      x33298.aggs = x33297;
      x33294[x33293] = x33298;
    }
    int* x33306 = (int*)malloc(x2189 * sizeof(int));
    int* x33307 = x33306;
    double* x33308 = (double*)malloc(x2189 * sizeof(double));
    double* x33309 = x33308;
    long x33310 = 0L;
    long* x33311 = (long*)malloc(x2189 * sizeof(long));
    long* x33312 = (long*)malloc(x2189 * sizeof(long));
    long x33313;
    for(x33313=0L; x33313 < x2189; x33313++) {
      x33311[x33313] = -1L;
    }
    double* x33323 = (double*)malloc(x2189 * sizeof(double));
    double* x33324 = x33323;
    int* x33325 = (int*)malloc(x2189 * sizeof(int));
    int* x33326 = x33325;
    int* x33327 = (int*)malloc(x2189 * sizeof(int));
    int* x33328 = x33327;
    double* x33331 = (double*)malloc(x2189 * sizeof(double));
    double* x33332 = x33331;
    long* x33333 = (long*)malloc(x2189 * sizeof(long));
    long* x33334 = x33333;
    long x33343 = 0L;
    long* x33344 = (long*)malloc(x2189 * sizeof(long));
    long* x33345 = (long*)malloc(x2189 * sizeof(long));
    long x33346;
    for(x33346=0L; x33346 < x2189; x33346++) {
      x33344[x33346] = -1L;
    }
    struct Anon1918636998* x33352 = (struct Anon1918636998*)malloc(x808 * sizeof(struct Anon1918636998));
    struct Anon1918636998* x33353 = x33352;
    long x33354 = 0L;
    long* x33355 = (long*)malloc(x808 * sizeof(long));
    long x33356;
    for(x33356=0L; x33356 < x808; x33356++) {
      struct Anon1918636998* x33357 = x33353;
      struct Anon1918636998 x33358 = x33357[x33356];
      struct Anon1621811895 x33359 = x33358.key;;
      struct Anon2052879266 x33360 = x33358.aggs;;
      struct Anon1918636998 x33361;
      x33361.exists = false;
      x33361.key = x33359;
      x33361.aggs = x33360;
      x33357[x33356] = x33361;
    }
    long x33366 = 1024L;
    long x33367 = 0L;
    struct Anon1918636998* x33368 = (struct Anon1918636998*)malloc(1024L * sizeof(struct Anon1918636998));
    struct Anon1918636998* x33369 = x33368;
    int x33370 = 0;
    long x33372 = 0L;
    struct timeval x33857, x33858, x33859;
    gettimeofday(&x33857, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x33374 = x33286;
      bool x33375 = !x33374;
      bool x33380 = x33375;
      if (x33375) {
        long x33376 = x33287;
        long x33377 = x31821;
        bool x33378 = x33376 < x33377;
        x33380 = x33378;
      }
      bool x33381 = x33380;
      if (!x33381) break;
      long x33383 = x33287;
      int* x33384 = x31823;
      int x33385 = x33384[x33383];
      double* x33392 = x31831;
      double x33393 = x33392[x33383];
      x33287 = x33287 + 1;
      long x33418 = x33385 & x823;
      long x33419 = x33418;
      struct Anon152692660* x33420 = x33290;
      struct Anon152692660 x33421 = x33420[x33418];
      struct Anon152692660 x33422 = x33421;
      bool x33423 = x33421.exists;;
      bool x33428 = x33423;
      if (x33423) {
        struct Anon152692660 x33424 = x33422;
        int x33425 = x33424.key;;
        bool x33426 = x33425 == x33385;
        x33428 = x33426;
      }
      bool x33429 = x33428;
      if (x33429) {
        struct Anon2052879266 x33430 = x33421.aggs;;
        int x33434 = x33421.key;;
        double x33431 = x33430._0;;
        double x33432 = x33431 + x33393;
        struct Anon2052879266 x33433;
        x33433._0 = x33432;
        struct Anon152692660 x33435;
        x33435.exists = true;
        x33435.key = x33434;
        x33435.aggs = x33433;
        x33420[x33418] = x33435;
      } else {
        struct Anon2052879266 x33464;
        x33464._0 = x33393;
        struct Anon152692660 x33465;
        x33465.exists = true;
        x33465.key = x33385;
        x33465.aggs = x33464;
        for (;;) {
          struct Anon152692660 x33438 = x33422;
          bool x33439 = x33438.exists;;
          bool x33474;
          if (x33439) {
            int x33440 = x33438.key;;
            bool x33441 = x33440 == x33385;
            bool x33461;
            if (x33441) {
              struct Anon2052879266 x33442 = x33438.aggs;;
              long x33446 = x33419;
              struct Anon152692660* x33448 = x33290;
              double x33443 = x33442._0;;
              double x33444 = x33443 + x33393;
              struct Anon2052879266 x33445;
              x33445._0 = x33444;
              struct Anon152692660 x33447;
              x33447.exists = true;
              x33447.key = x33440;
              x33447.aggs = x33445;
              x33448[x33446] = x33447;
              x33461 = false;
            } else {
              long x33451 = x33419;
              long x33452 = x33451 + 1L;
              long x33453 = x33452 & x823;
              x33419 = x33453;
              struct Anon152692660* x33455 = x33290;
              struct Anon152692660 x33456 = x33455[x33453];
              x33422 = x33456;
              x33461 = true;
            }
            x33474 = x33461;
          } else {
            long x33463 = x33419;
            struct Anon152692660* x33466 = x33290;
            x33466[x33463] = x33465;
            long x33468 = x33291;
            x33292[x33468] = x33463;
            x33291 = x33291 + 1L;
            x33474 = false;
          }
          if (!x33474) break;
        }
      }
    }
    long x33483 = x33291;
    long x33485;
    for(x33485=0L; x33485 < x33483; x33485++) {
      long x33486 = x33292[x33485];
      struct Anon152692660* x33487 = x33290;
      struct Anon152692660 x33488 = x33487[x33486];
      struct Anon2052879266 x33489 = x33488.aggs;;
      double x33490 = x33489._0;;
      bool x33493 = x33490 > x33492;
      if (x33493) {
        double x33494 = x33488.key;;
        long x33495 = x33310;
        int* x33499 = x33307;
        x33499[x33495] = x33494;
        double* x33501 = x33309;
        x33501[x33495] = x33490;
        x33310 = x33310 + 1L;
        long x33504 = (long) x33494;
        long x33505 = x33504 & x2212;
        long x33506 = x33311[x33505];
        x33311[x33505] = x33495;
        x33312[x33495] = x33506;
      } else {
      }
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x33514 = x33282;
      bool x33515 = !x33514;
      bool x33520 = x33515;
      if (x33515) {
        long x33516 = x33283;
        long x33517 = x32615;
        bool x33518 = x33516 < x33517;
        x33520 = x33518;
      }
      bool x33521 = x33520;
      if (!x33521) break;
      long x33523 = x33283;
      int* x33524 = x32617;
      int x33525 = x33524[x33523];
      int* x33526 = x32619;
      int x33527 = x33526[x33523];
      double* x33530 = x32623;
      double x33531 = x33530[x33523];
      long* x33532 = x32625;
      long x33533 = x33532[x33523];
      x33283 = x33283 + 1;
      double x33544 = (double)x33525;
      long x33545 = (long) x33544;
      long x33546 = x33545 & x2212;
      long x33547 = x33311[x33546];
      long x33548 = x33547;
      long x33593 = x33527 & x2212;
      for (;;) {
        long x33549 = x33548;
        bool x33550 = x33549 != -1;
        if (!x33550) break;
        long x33552 = x33548;
        int* x33555 = x33307;
        int x33556 = x33555[x33552];
        double* x33557 = x33309;
        double x33558 = x33557[x33552];
        long x33561 = x33312[x33552];
        x33548 = x33561;
        bool x33563 = x33525 == x33556;
        if (x33563) {
          long x33567 = x33343;
          double* x33572 = x33324;
          x33572[x33567] = x33558;
          int* x33574 = x33326;
          x33574[x33567] = x33525;
          int* x33576 = x33328;
          x33576[x33567] = x33527;
          double* x33580 = x33332;
          x33580[x33567] = x33531;
          long* x33582 = x33334;
          x33582[x33567] = x33533;
          x33343 = x33343 + 1L;
          long x33594 = x33344[x33593];
          x33344[x33593] = x33567;
          x33345[x33567] = x33594;
        } else {
        }
      }
    }
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x33604 = x33284;
      bool x33605 = !x33604;
      bool x33610 = x33605;
      if (x33605) {
        long x33606 = x33285;
        long x33607 = x32986;
        bool x33608 = x33606 < x33607;
        x33610 = x33608;
      }
      bool x33611 = x33610;
      if (!x33611) break;
      long x33613 = x33285;
      int* x33614 = x32988;
      int x33615 = x33614[x33613];
      char** x33616 = x32990;
      char* x33617 = x33616[x33613];
      x33285 = x33285 + 1;
      long x33632 = x33615 & x2212;
      long x33633 = x33344[x33632];
      long x33634 = x33633;
      long x33674 = x33615 * 41L;
      for (;;) {
        long x33635 = x33634;
        bool x33636 = x33635 != -1;
        if (!x33636) break;
        long x33638 = x33634;
        double* x33643 = x33324;
        double x33644 = x33643[x33638];
        int* x33646 = x33326;
        int x33647 = x33646[x33638];
        int* x33648 = x33328;
        int x33649 = x33648[x33638];
        double* x33652 = x33332;
        double x33653 = x33652[x33638];
        long* x33654 = x33334;
        long x33655 = x33654[x33638];
        long x33665 = x33345[x33638];
        x33634 = x33665;
        bool x33667 = x33649 == x33615;
        if (x33667) {
          long x33672 = hash(x33617, 10L);
          long x33673 = (long) x33653;
          long x33675 = x33674 + x33672;
          long x33676 = x33675 * 41L;
          long x33677 = x33676 + x33655;
          long x33678 = x33677 * 41L;
          long x33679 = x33678 + x33647;
          long x33680 = x33679 * 41L;
          long x33681 = x33680 + x33673;
          long x33682 = x33681 & x823;
          long x33683 = x33682;
          struct Anon1918636998* x33684 = x33353;
          struct Anon1918636998 x33685 = x33684[x33682];
          struct Anon1918636998 x33686 = x33685;
          bool x33687 = x33685.exists;;
          bool x33709 = x33687;
          if (x33687) {
            struct Anon1918636998 x33688 = x33686;
            struct Anon1621811895 x33689 = x33688.key;;
            char* x33690 = x33689.C_NAME;;
            bool x33691 = tpch_strcmp(x33690,x33617) == 0;;
            bool x33700 = x33691;
            if (x33691) {
              int x33692 = x33689.C_CUSTKEY;;
              bool x33693 = x33692 == x33615;
              x33700 = x33693;
            }
            bool x33701 = x33700;
            bool x33702 = x33701;
            if (x33701) {
              int x33694 = x33689.O_ORDERKEY;;
              bool x33695 = x33694 == x33647;
              x33702 = x33695;
            }
            bool x33703 = x33702;
            bool x33704 = x33703;
            if (x33703) {
              long x33696 = x33689.O_ORDERDATE;;
              bool x33697 = x33696 == x33655;
              x33704 = x33697;
            }
            bool x33705 = x33704;
            bool x33706 = x33705;
            if (x33705) {
              double x33698 = x33689.O_TOTALPRICE;;
              bool x33699 = x33698 == x33653;
              x33706 = x33699;
            }
            bool x33707 = x33706;
            x33709 = x33707;
          }
          bool x33710 = x33709;
          if (x33710) {
            struct Anon2052879266 x33711 = x33685.aggs;;
            struct Anon1621811895 x33715 = x33685.key;;
            double x33712 = x33711._0;;
            double x33713 = x33712 + x33644;
            struct Anon2052879266 x33714;
            x33714._0 = x33713;
            struct Anon1918636998 x33716;
            x33716.exists = true;
            x33716.key = x33715;
            x33716.aggs = x33714;
            x33684[x33682] = x33716;
          } else {
            struct Anon2052879266 x33645;
            x33645._0 = x33644;
            struct Anon1621811895 x33671;
            x33671.C_NAME = x33617;
            x33671.C_CUSTKEY = x33615;
            x33671.O_ORDERKEY = x33647;
            x33671.O_ORDERDATE = x33655;
            x33671.O_TOTALPRICE = x33653;
            struct Anon1918636998 x33762;
            x33762.exists = true;
            x33762.key = x33671;
            x33762.aggs = x33645;
            for (;;) {
              struct Anon1918636998 x33719 = x33686;
              bool x33720 = x33719.exists;;
              bool x33771;
              if (x33720) {
                struct Anon1621811895 x33721 = x33719.key;;
                char* x33722 = x33721.C_NAME;;
                bool x33723 = tpch_strcmp(x33722,x33617) == 0;;
                bool x33732 = x33723;
                if (x33723) {
                  int x33724 = x33721.C_CUSTKEY;;
                  bool x33725 = x33724 == x33615;
                  x33732 = x33725;
                }
                bool x33733 = x33732;
                bool x33734 = x33733;
                if (x33733) {
                  int x33726 = x33721.O_ORDERKEY;;
                  bool x33727 = x33726 == x33647;
                  x33734 = x33727;
                }
                bool x33735 = x33734;
                bool x33736 = x33735;
                if (x33735) {
                  long x33728 = x33721.O_ORDERDATE;;
                  bool x33729 = x33728 == x33655;
                  x33736 = x33729;
                }
                bool x33737 = x33736;
                bool x33738 = x33737;
                if (x33737) {
                  double x33730 = x33721.O_TOTALPRICE;;
                  bool x33731 = x33730 == x33653;
                  x33738 = x33731;
                }
                bool x33739 = x33738;
                bool x33759;
                if (x33739) {
                  struct Anon2052879266 x33740 = x33719.aggs;;
                  long x33744 = x33683;
                  struct Anon1918636998* x33746 = x33353;
                  double x33741 = x33740._0;;
                  double x33742 = x33741 + x33644;
                  struct Anon2052879266 x33743;
                  x33743._0 = x33742;
                  struct Anon1918636998 x33745;
                  x33745.exists = true;
                  x33745.key = x33721;
                  x33745.aggs = x33743;
                  x33746[x33744] = x33745;
                  x33759 = false;
                } else {
                  long x33749 = x33683;
                  long x33750 = x33749 + 1L;
                  long x33751 = x33750 & x823;
                  x33683 = x33751;
                  struct Anon1918636998* x33753 = x33353;
                  struct Anon1918636998 x33754 = x33753[x33751];
                  x33686 = x33754;
                  x33759 = true;
                }
                x33771 = x33759;
              } else {
                long x33761 = x33683;
                struct Anon1918636998* x33763 = x33353;
                x33763[x33761] = x33762;
                long x33765 = x33354;
                x33355[x33765] = x33761;
                x33354 = x33354 + 1L;
                x33771 = false;
              }
              if (!x33771) break;
            }
          }
        } else {
        }
      }
    }
    long x33784 = x33354;
    long x33786;
    for(x33786=0L; x33786 < x33784; x33786++) {
      long x33787 = x33355[x33786];
      struct Anon1918636998* x33788 = x33353;
      struct Anon1918636998 x33789 = x33788[x33787];
      long x33790 = x33367;
      long x33791 = x33366;
      bool x33792 = x33790 == x33791;
      if (x33792) {
        long x33793 = x33791 * 4L;
        x33366 = x33793;
        struct Anon1918636998* x33795 = x33369;
        struct Anon1918636998* x33796 = (struct Anon1918636998 *)realloc(x33795,x33793* sizeof(struct Anon1918636998));
        x33369 = x33796;
      } else {
      }
      struct Anon1918636998* x33800 = x33369;
      x33800[x33790] = x33789;
      x33367 = x33367 + 1;
    }
    long x33805 = x33367;
    struct Anon1918636998* x33806 = x33369;
    qsort((void *)x33806,x33805,sizeof(struct Anon1918636998), (__compar_fn_t)x33826); // x33827
    long x33829;
    for(x33829=0L; x33829 < x33805; x33829++) {
      struct Anon1918636998* x33830 = x33369;
      struct Anon1918636998 x33831 = x33830[x33829];
      int x33832 = x33370;
      bool x33833 = x33832 < 100;
      bool x33834 = x33833 == false;
      if (x33834) {
      } else {
        struct Anon1621811895 x33837 = x33831.key;;
        struct Anon2052879266 x33845 = x33831.aggs;;
        char* x33838 = x33837.C_NAME;;
        int x33839 = tpch_strlen(x33838);
        int x33840 = x33837.C_CUSTKEY;;
        int x33841 = x33837.O_ORDERKEY;;
        long x33842 = x33837.O_ORDERDATE;;
        char* x33843 = (char*)malloc(9 * sizeof(char));;
        snprintf(x33843, 9, "%lu", x33842);
        double x33844 = x33837.O_TOTALPRICE;;
        double x33846 = x33845._0;;
        printf("%.*s|%d|%d|%s|%.2f|%.2f\n",x33839,x33838,x33840,x33841,x33843,x33844,x33846);
        x33370 = x33370 + 1;
        x33372 = x33372 + 1L;
      }
    }
    long x33854 = x33372;
    printf("(%ld rows)\n",x33854);
    gettimeofday(&x33858, NULL);
    timeval_subtract(&x33859, &x33858, &x33857);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x33859.tv_sec * 1000) + (x33859.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
