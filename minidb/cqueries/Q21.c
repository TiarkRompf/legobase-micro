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

struct Anon306783447 {
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

struct Anon1406772883Anon1268892766Anon168903330Anon811555534 {
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
struct Anon306783447 left;
struct Anon811555534 right;
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
int x40375(struct Anon603726677* x40361, struct Anon603726677* x40362);
int x40375(struct Anon603726677* x40361, struct Anon603726677* x40362) {
  struct Anon603726677 x40363 = (*x40361);
  struct Anon603726677 x40364 = (*x40362);
  double x40365 = x40363.aggs;;
  double x40366 = x40364.aggs;;
  bool x40367 = x40365 < x40366;
  int x40373;
  if (x40367) {
    x40373 = 1;
  } else {
    bool x40368 = x40365 > x40366;
    int x40372;
    if (x40368) {
      x40372 = -1;
    } else {
      char* x40369 = x40363.key;;
      char* x40370 = x40364.key;;
      int x40371 = tpch_strcmp(x40369,x40370);
      x40372 = x40371;
    }
    x40373 = x40372;
  }
  return x40373;
}

/************************ MAIN BODY **************************/
int main(int x37786, char** x37787) {
  long x37788 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x37789 = x7;
  long x37790 = 0L;
  int* x37791 = (int*)malloc(x7 * sizeof(int));
  int* x37792 = x37791;
  int* x37795 = (int*)malloc(x7 * sizeof(int));
  int* x37796 = x37795;
  long* x37813 = (long*)malloc(x7 * sizeof(long));
  long* x37814 = x37813;
  long* x37815 = (long*)malloc(x7 * sizeof(long));
  long* x37816 = x37815;
  int x3 = open("XXXXXlineitem.tbl",0);
  long x4 = fsize(x3);
  char* x5 = mmap(0, x4, PROT_READ, MAP_FILE | MAP_SHARED, x3, 0);
  for (;;) {
    long x37823 = x37788;
    bool x37824 = x37823 < x4;
    if (!x37824) break;
    int x37827 = 0;
    for (;;) {
      long x37828 = x37788;
      char x37829 = x5[x37828];
      bool x37830 = x37829 != '|';
      bool x37835 = x37830;
      if (x37830) {
        long x37831 = x37788;
        char x37832 = x5[x37831];
        bool x37833 = x37832 != '\n';
        x37835 = x37833;
      }
      bool x37836 = x37835;
      if (!x37836) break;
      int x37838 = x37827;
      long x37840 = x37788;
      int x37839 = x37838 * 10;
      char x37841 = x5[x37840];
      char x37842 = x37841 - '0';
      int x37843 = x37839 + x37842;
      x37827 = x37843;
      x37788 = x37788 + 1;
    }
    x37788 = x37788 + 1;
    int x37849 = x37827;
    for (;;) {
      long x37852 = x37788;
      char x37853 = x5[x37852];
      bool x37854 = x37853 != '|';
      bool x37859 = x37854;
      if (x37854) {
        long x37855 = x37788;
        char x37856 = x5[x37855];
        bool x37857 = x37856 != '\n';
        x37859 = x37857;
      }
      bool x37860 = x37859;
      if (!x37860) break;
      x37788 = x37788 + 1;
    }
    x37788 = x37788 + 1;
    int x37875 = 0;
    for (;;) {
      long x37876 = x37788;
      char x37877 = x5[x37876];
      bool x37878 = x37877 != '|';
      bool x37883 = x37878;
      if (x37878) {
        long x37879 = x37788;
        char x37880 = x5[x37879];
        bool x37881 = x37880 != '\n';
        x37883 = x37881;
      }
      bool x37884 = x37883;
      if (!x37884) break;
      int x37886 = x37875;
      long x37888 = x37788;
      int x37887 = x37886 * 10;
      char x37889 = x5[x37888];
      char x37890 = x37889 - '0';
      int x37891 = x37887 + x37890;
      x37875 = x37891;
      x37788 = x37788 + 1;
    }
    x37788 = x37788 + 1;
    int x37897 = x37875;
    for (;;) {
      long x37900 = x37788;
      char x37901 = x5[x37900];
      bool x37902 = x37901 != '|';
      bool x37907 = x37902;
      if (x37902) {
        long x37903 = x37788;
        char x37904 = x5[x37903];
        bool x37905 = x37904 != '\n';
        x37907 = x37905;
      }
      bool x37908 = x37907;
      if (!x37908) break;
      x37788 = x37788 + 1;
    }
    x37788 = x37788 + 1;
    for (;;) {
      long x37925 = x37788;
      char x37926 = x5[x37925];
      bool x37927 = x37926 != '.';
      bool x37932 = x37927;
      if (x37927) {
        long x37928 = x37788;
        char x37929 = x5[x37928];
        bool x37930 = x37929 != '|';
        x37932 = x37930;
      }
      bool x37933 = x37932;
      bool x37938 = x37933;
      if (x37933) {
        long x37934 = x37788;
        char x37935 = x5[x37934];
        bool x37936 = x37935 != '\n';
        x37938 = x37936;
      }
      bool x37939 = x37938;
      if (!x37939) break;
      x37788 = x37788 + 1;
    }
    long x37951 = x37788;
    char x37952 = x5[x37951];
    bool x37953 = x37952 == '.';
    if (x37953) {
      x37788 = x37788 + 1;
      for (;;) {
        long x37955 = x37788;
        char x37956 = x5[x37955];
        bool x37957 = x37956 != '|';
        bool x37962 = x37957;
        if (x37957) {
          long x37958 = x37788;
          char x37959 = x5[x37958];
          bool x37960 = x37959 != '\n';
          x37962 = x37960;
        }
        bool x37963 = x37962;
        if (!x37963) break;
        x37788 = x37788 + 1;
      }
    } else {
    }
    x37788 = x37788 + 1;
    for (;;) {
      long x37990 = x37788;
      char x37991 = x5[x37990];
      bool x37992 = x37991 != '.';
      bool x37997 = x37992;
      if (x37992) {
        long x37993 = x37788;
        char x37994 = x5[x37993];
        bool x37995 = x37994 != '|';
        x37997 = x37995;
      }
      bool x37998 = x37997;
      bool x38003 = x37998;
      if (x37998) {
        long x37999 = x37788;
        char x38000 = x5[x37999];
        bool x38001 = x38000 != '\n';
        x38003 = x38001;
      }
      bool x38004 = x38003;
      if (!x38004) break;
      x37788 = x37788 + 1;
    }
    long x38016 = x37788;
    char x38017 = x5[x38016];
    bool x38018 = x38017 == '.';
    if (x38018) {
      x37788 = x37788 + 1;
      for (;;) {
        long x38020 = x37788;
        char x38021 = x5[x38020];
        bool x38022 = x38021 != '|';
        bool x38027 = x38022;
        if (x38022) {
          long x38023 = x37788;
          char x38024 = x5[x38023];
          bool x38025 = x38024 != '\n';
          x38027 = x38025;
        }
        bool x38028 = x38027;
        if (!x38028) break;
        x37788 = x37788 + 1;
      }
    } else {
    }
    x37788 = x37788 + 1;
    for (;;) {
      long x38055 = x37788;
      char x38056 = x5[x38055];
      bool x38057 = x38056 != '.';
      bool x38062 = x38057;
      if (x38057) {
        long x38058 = x37788;
        char x38059 = x5[x38058];
        bool x38060 = x38059 != '|';
        x38062 = x38060;
      }
      bool x38063 = x38062;
      bool x38068 = x38063;
      if (x38063) {
        long x38064 = x37788;
        char x38065 = x5[x38064];
        bool x38066 = x38065 != '\n';
        x38068 = x38066;
      }
      bool x38069 = x38068;
      if (!x38069) break;
      x37788 = x37788 + 1;
    }
    long x38081 = x37788;
    char x38082 = x5[x38081];
    bool x38083 = x38082 == '.';
    if (x38083) {
      x37788 = x37788 + 1;
      for (;;) {
        long x38085 = x37788;
        char x38086 = x5[x38085];
        bool x38087 = x38086 != '|';
        bool x38092 = x38087;
        if (x38087) {
          long x38088 = x37788;
          char x38089 = x5[x38088];
          bool x38090 = x38089 != '\n';
          x38092 = x38090;
        }
        bool x38093 = x38092;
        if (!x38093) break;
        x37788 = x37788 + 1;
      }
    } else {
    }
    x37788 = x37788 + 1;
    for (;;) {
      long x38120 = x37788;
      char x38121 = x5[x38120];
      bool x38122 = x38121 != '.';
      bool x38127 = x38122;
      if (x38122) {
        long x38123 = x37788;
        char x38124 = x5[x38123];
        bool x38125 = x38124 != '|';
        x38127 = x38125;
      }
      bool x38128 = x38127;
      bool x38133 = x38128;
      if (x38128) {
        long x38129 = x37788;
        char x38130 = x5[x38129];
        bool x38131 = x38130 != '\n';
        x38133 = x38131;
      }
      bool x38134 = x38133;
      if (!x38134) break;
      x37788 = x37788 + 1;
    }
    long x38146 = x37788;
    char x38147 = x5[x38146];
    bool x38148 = x38147 == '.';
    if (x38148) {
      x37788 = x37788 + 1;
      for (;;) {
        long x38150 = x37788;
        char x38151 = x5[x38150];
        bool x38152 = x38151 != '|';
        bool x38157 = x38152;
        if (x38152) {
          long x38153 = x37788;
          char x38154 = x5[x38153];
          bool x38155 = x38154 != '\n';
          x38157 = x38155;
        }
        bool x38158 = x38157;
        if (!x38158) break;
        x37788 = x37788 + 1;
      }
    } else {
    }
    x37788 = x37788 + 1;
    x37788 = x37788 + 2;
    x37788 = x37788 + 2;
    for (;;) {
      long x38190 = x37788;
      char x38191 = x5[x38190];
      bool x38192 = x38191 != '-';
      bool x38197 = x38192;
      if (x38192) {
        long x38193 = x37788;
        char x38194 = x5[x38193];
        bool x38195 = x38194 != '\n';
        x38197 = x38195;
      }
      bool x38198 = x38197;
      if (!x38198) break;
      x37788 = x37788 + 1;
    }
    x37788 = x37788 + 1;
    for (;;) {
      long x38214 = x37788;
      char x38215 = x5[x38214];
      bool x38216 = x38215 != '-';
      bool x38221 = x38216;
      if (x38216) {
        long x38217 = x37788;
        char x38218 = x5[x38217];
        bool x38219 = x38218 != '\n';
        x38221 = x38219;
      }
      bool x38222 = x38221;
      if (!x38222) break;
      x37788 = x37788 + 1;
    }
    x37788 = x37788 + 1;
    for (;;) {
      long x38238 = x37788;
      char x38239 = x5[x38238];
      bool x38240 = x38239 != '|';
      bool x38245 = x38240;
      if (x38240) {
        long x38241 = x37788;
        char x38242 = x5[x38241];
        bool x38243 = x38242 != '\n';
        x38245 = x38243;
      }
      bool x38246 = x38245;
      if (!x38246) break;
      x37788 = x37788 + 1;
    }
    x37788 = x37788 + 1;
    int x38265 = 0;
    for (;;) {
      long x38266 = x37788;
      char x38267 = x5[x38266];
      bool x38268 = x38267 != '-';
      bool x38273 = x38268;
      if (x38268) {
        long x38269 = x37788;
        char x38270 = x5[x38269];
        bool x38271 = x38270 != '\n';
        x38273 = x38271;
      }
      bool x38274 = x38273;
      if (!x38274) break;
      int x38276 = x38265;
      long x38278 = x37788;
      int x38277 = x38276 * 10;
      char x38279 = x5[x38278];
      char x38280 = x38279 - '0';
      int x38281 = x38277 + x38280;
      x38265 = x38281;
      x37788 = x37788 + 1;
    }
    x37788 = x37788 + 1;
    int x38287 = x38265;
    int x38289 = 0;
    for (;;) {
      long x38290 = x37788;
      char x38291 = x5[x38290];
      bool x38292 = x38291 != '-';
      bool x38297 = x38292;
      if (x38292) {
        long x38293 = x37788;
        char x38294 = x5[x38293];
        bool x38295 = x38294 != '\n';
        x38297 = x38295;
      }
      bool x38298 = x38297;
      if (!x38298) break;
      int x38300 = x38289;
      long x38302 = x37788;
      int x38301 = x38300 * 10;
      char x38303 = x5[x38302];
      char x38304 = x38303 - '0';
      int x38305 = x38301 + x38304;
      x38289 = x38305;
      x37788 = x37788 + 1;
    }
    x37788 = x37788 + 1;
    int x38311 = x38289;
    int x38313 = 0;
    for (;;) {
      long x38314 = x37788;
      char x38315 = x5[x38314];
      bool x38316 = x38315 != '|';
      bool x38321 = x38316;
      if (x38316) {
        long x38317 = x37788;
        char x38318 = x5[x38317];
        bool x38319 = x38318 != '\n';
        x38321 = x38319;
      }
      bool x38322 = x38321;
      if (!x38322) break;
      int x38324 = x38313;
      long x38326 = x37788;
      int x38325 = x38324 * 10;
      char x38327 = x5[x38326];
      char x38328 = x38327 - '0';
      int x38329 = x38325 + x38328;
      x38313 = x38329;
      x37788 = x37788 + 1;
    }
    x37788 = x37788 + 1;
    int x38335 = x38313;
    int x38341 = 0;
    for (;;) {
      long x38342 = x37788;
      char x38343 = x5[x38342];
      bool x38344 = x38343 != '-';
      bool x38349 = x38344;
      if (x38344) {
        long x38345 = x37788;
        char x38346 = x5[x38345];
        bool x38347 = x38346 != '\n';
        x38349 = x38347;
      }
      bool x38350 = x38349;
      if (!x38350) break;
      int x38352 = x38341;
      long x38354 = x37788;
      int x38353 = x38352 * 10;
      char x38355 = x5[x38354];
      char x38356 = x38355 - '0';
      int x38357 = x38353 + x38356;
      x38341 = x38357;
      x37788 = x37788 + 1;
    }
    x37788 = x37788 + 1;
    int x38363 = x38341;
    int x38365 = 0;
    for (;;) {
      long x38366 = x37788;
      char x38367 = x5[x38366];
      bool x38368 = x38367 != '-';
      bool x38373 = x38368;
      if (x38368) {
        long x38369 = x37788;
        char x38370 = x5[x38369];
        bool x38371 = x38370 != '\n';
        x38373 = x38371;
      }
      bool x38374 = x38373;
      if (!x38374) break;
      int x38376 = x38365;
      long x38378 = x37788;
      int x38377 = x38376 * 10;
      char x38379 = x5[x38378];
      char x38380 = x38379 - '0';
      int x38381 = x38377 + x38380;
      x38365 = x38381;
      x37788 = x37788 + 1;
    }
    x37788 = x37788 + 1;
    int x38387 = x38365;
    int x38389 = 0;
    for (;;) {
      long x38390 = x37788;
      char x38391 = x5[x38390];
      bool x38392 = x38391 != '|';
      bool x38397 = x38392;
      if (x38392) {
        long x38393 = x37788;
        char x38394 = x5[x38393];
        bool x38395 = x38394 != '\n';
        x38397 = x38395;
      }
      bool x38398 = x38397;
      if (!x38398) break;
      int x38400 = x38389;
      long x38402 = x37788;
      int x38401 = x38400 * 10;
      char x38403 = x5[x38402];
      char x38404 = x38403 - '0';
      int x38405 = x38401 + x38404;
      x38389 = x38405;
      x37788 = x37788 + 1;
    }
    x37788 = x37788 + 1;
    int x38411 = x38389;
    for (;;) {
      long x38417 = x37788;
      char x38418 = x5[x38417];
      bool x38419 = x38418 != '|';
      bool x38424 = x38419;
      if (x38419) {
        long x38420 = x37788;
        char x38421 = x5[x38420];
        bool x38422 = x38421 != '\n';
        x38424 = x38422;
      }
      bool x38425 = x38424;
      if (!x38425) break;
      x37788 = x37788 + 1;
    }
    x37788 = x37788 + 1;
    for (;;) {
      long x38435 = x37788;
      char x38436 = x5[x38435];
      bool x38437 = x38436 != '|';
      bool x38442 = x38437;
      if (x38437) {
        long x38438 = x37788;
        char x38439 = x5[x38438];
        bool x38440 = x38439 != '\n';
        x38442 = x38440;
      }
      bool x38443 = x38442;
      if (!x38443) break;
      x37788 = x37788 + 1;
    }
    x37788 = x37788 + 1;
    for (;;) {
      long x38453 = x37788;
      char x38454 = x5[x38453];
      bool x38455 = x38454 != '|';
      bool x38460 = x38455;
      if (x38455) {
        long x38456 = x37788;
        char x38457 = x5[x38456];
        bool x38458 = x38457 != '\n';
        x38460 = x38458;
      }
      bool x38461 = x38460;
      if (!x38461) break;
      x37788 = x37788 + 1;
    }
    x37788 = x37788 + 1;
    long x38471 = x37788;
    bool x38472 = x38471 > 0L;
    bool x38478 = x38472;
    if (x38472) {
      long x38473 = x37788;
      long x38474 = x38473 - 1L;
      char x38475 = x5[x38474];
      bool x38476 = x38475 != '\n';
      x38478 = x38476;
    }
    bool x38479 = x38478;
    if (x38479) {
      for (;;) {
        long x38480 = x37788;
        char x38481 = x5[x38480];
        bool x38482 = x38481 != '\n';
        if (!x38482) break;
        x37788 = x37788 + 1;
      }
    } else {
    }
    x37788 = x37788 + 1;
    long x38491 = x37790;
    long x38492 = x37789;
    bool x38493 = x38491 == x38492;
    if (x38493) {
      long x38494 = x38492 * 4L;
      x37789 = x38494;
      printf("buffer.resize %ld\n",x38494);
      int* x38497 = x37792;
      int* x38498 = (int*)realloc(x38497,x38494 * sizeof(int));
      x37792 = x38498;
      int* x38503 = x37796;
      int* x38504 = (int*)realloc(x38503,x38494 * sizeof(int));
      x37796 = x38504;
      long* x38530 = x37814;
      long* x38531 = (long*)realloc(x38530,x38494 * sizeof(long));
      x37814 = x38531;
      long* x38533 = x37816;
      long* x38534 = (long*)realloc(x38533,x38494 * sizeof(long));
      x37816 = x38534;
    } else {
    }
    int* x38547 = x37792;
    x38547[x38491] = x37849;
    int* x38551 = x37796;
    x38551[x38491] = x37897;
    long* x38569 = x37814;
    long x38336 = x38287 * 10000L;
    long x38337 = x38311 * 100L;
    long x38338 = x38336 + x38337;
    long x38339 = x38338 + x38335;
    x38569[x38491] = x38339;
    long* x38571 = x37816;
    long x38412 = x38363 * 10000L;
    long x38413 = x38387 * 100L;
    long x38414 = x38412 + x38413;
    long x38415 = x38414 + x38411;
    x38571[x38491] = x38415;
    x37790 = x37790 + 1;
  }
  long x38582 = 0L;
  long x38583 = x7;
  long x38584 = 0L;
  int* x38585 = (int*)malloc(x7 * sizeof(int));
  int* x38586 = x38585;
  char** x38587 = (char**)malloc(x7 * sizeof(char*));
  char** x38588 = x38587;
  int* x38591 = (int*)malloc(x7 * sizeof(int));
  int* x38592 = x38591;
  int x1908 = open("XXXXXsupplier.tbl",0);
  long x1909 = fsize(x1908);
  char* x1910 = mmap(0, x1909, PROT_READ, MAP_FILE | MAP_SHARED, x1908, 0);
  for (;;) {
    long x38599 = x38582;
    bool x38600 = x38599 < x1909;
    if (!x38600) break;
    int x38603 = 0;
    for (;;) {
      long x38604 = x38582;
      char x38605 = x1910[x38604];
      bool x38606 = x38605 != '|';
      bool x38611 = x38606;
      if (x38606) {
        long x38607 = x38582;
        char x38608 = x1910[x38607];
        bool x38609 = x38608 != '\n';
        x38611 = x38609;
      }
      bool x38612 = x38611;
      if (!x38612) break;
      int x38614 = x38603;
      long x38616 = x38582;
      int x38615 = x38614 * 10;
      char x38617 = x1910[x38616];
      char x38618 = x38617 - '0';
      int x38619 = x38615 + x38618;
      x38603 = x38619;
      x38582 = x38582 + 1;
    }
    x38582 = x38582 + 1;
    int x38625 = x38603;
    long x38626 = x38582;
    for (;;) {
      long x38627 = x38582;
      char x38628 = x1910[x38627];
      bool x38629 = x38628 != '|';
      bool x38634 = x38629;
      if (x38629) {
        long x38630 = x38582;
        char x38631 = x1910[x38630];
        bool x38632 = x38631 != '\n';
        x38634 = x38632;
      }
      bool x38635 = x38634;
      if (!x38635) break;
      x38582 = x38582 + 1;
    }
    x38582 = x38582 + 1;
    for (;;) {
      long x38645 = x38582;
      char x38646 = x1910[x38645];
      bool x38647 = x38646 != '|';
      bool x38652 = x38647;
      if (x38647) {
        long x38648 = x38582;
        char x38649 = x1910[x38648];
        bool x38650 = x38649 != '\n';
        x38652 = x38650;
      }
      bool x38653 = x38652;
      if (!x38653) break;
      x38582 = x38582 + 1;
    }
    x38582 = x38582 + 1;
    int x38663 = 0;
    for (;;) {
      long x38664 = x38582;
      char x38665 = x1910[x38664];
      bool x38666 = x38665 != '|';
      bool x38671 = x38666;
      if (x38666) {
        long x38667 = x38582;
        char x38668 = x1910[x38667];
        bool x38669 = x38668 != '\n';
        x38671 = x38669;
      }
      bool x38672 = x38671;
      if (!x38672) break;
      int x38674 = x38663;
      long x38676 = x38582;
      int x38675 = x38674 * 10;
      char x38677 = x1910[x38676];
      char x38678 = x38677 - '0';
      int x38679 = x38675 + x38678;
      x38663 = x38679;
      x38582 = x38582 + 1;
    }
    x38582 = x38582 + 1;
    int x38685 = x38663;
    for (;;) {
      long x38687 = x38582;
      char x38688 = x1910[x38687];
      bool x38689 = x38688 != '|';
      bool x38694 = x38689;
      if (x38689) {
        long x38690 = x38582;
        char x38691 = x1910[x38690];
        bool x38692 = x38691 != '\n';
        x38694 = x38692;
      }
      bool x38695 = x38694;
      if (!x38695) break;
      x38582 = x38582 + 1;
    }
    x38582 = x38582 + 1;
    for (;;) {
      long x38707 = x38582;
      char x38708 = x1910[x38707];
      bool x38709 = x38708 != '.';
      bool x38714 = x38709;
      if (x38709) {
        long x38710 = x38582;
        char x38711 = x1910[x38710];
        bool x38712 = x38711 != '|';
        x38714 = x38712;
      }
      bool x38715 = x38714;
      bool x38720 = x38715;
      if (x38715) {
        long x38716 = x38582;
        char x38717 = x1910[x38716];
        bool x38718 = x38717 != '\n';
        x38720 = x38718;
      }
      bool x38721 = x38720;
      if (!x38721) break;
      x38582 = x38582 + 1;
    }
    long x38733 = x38582;
    char x38734 = x1910[x38733];
    bool x38735 = x38734 == '.';
    if (x38735) {
      x38582 = x38582 + 1;
      for (;;) {
        long x38737 = x38582;
        char x38738 = x1910[x38737];
        bool x38739 = x38738 != '|';
        bool x38744 = x38739;
        if (x38739) {
          long x38740 = x38582;
          char x38741 = x1910[x38740];
          bool x38742 = x38741 != '\n';
          x38744 = x38742;
        }
        bool x38745 = x38744;
        if (!x38745) break;
        x38582 = x38582 + 1;
      }
    } else {
    }
    x38582 = x38582 + 1;
    for (;;) {
      long x38770 = x38582;
      char x38771 = x1910[x38770];
      bool x38772 = x38771 != '|';
      bool x38777 = x38772;
      if (x38772) {
        long x38773 = x38582;
        char x38774 = x1910[x38773];
        bool x38775 = x38774 != '\n';
        x38777 = x38775;
      }
      bool x38778 = x38777;
      if (!x38778) break;
      x38582 = x38582 + 1;
    }
    x38582 = x38582 + 1;
    long x38788 = x38582;
    bool x38789 = x38788 > 0L;
    bool x38795 = x38789;
    if (x38789) {
      long x38790 = x38582;
      long x38791 = x38790 - 1L;
      char x38792 = x1910[x38791];
      bool x38793 = x38792 != '\n';
      x38795 = x38793;
    }
    bool x38796 = x38795;
    if (x38796) {
      for (;;) {
        long x38797 = x38582;
        char x38798 = x1910[x38797];
        bool x38799 = x38798 != '\n';
        if (!x38799) break;
        x38582 = x38582 + 1;
      }
    } else {
    }
    x38582 = x38582 + 1;
    long x38808 = x38584;
    long x38809 = x38583;
    bool x38810 = x38808 == x38809;
    if (x38810) {
      long x38811 = x38809 * 4L;
      x38583 = x38811;
      printf("buffer.resize %ld\n",x38811);
      int* x38814 = x38586;
      int* x38815 = (int*)realloc(x38814,x38811 * sizeof(int));
      x38586 = x38815;
      char** x38817 = x38588;
      char** x38818 = (char**)realloc(x38817,x38811 * sizeof(char*));
      x38588 = x38818;
      int* x38823 = x38592;
      int* x38824 = (int*)realloc(x38823,x38811 * sizeof(int));
      x38592 = x38824;
    } else {
    }
    int* x38837 = x38586;
    x38837[x38808] = x38625;
    char** x38839 = x38588;
    char* x38643 = x1910+x38626;
    x38839[x38808] = x38643;
    int* x38843 = x38592;
    x38843[x38808] = x38685;
    x38584 = x38584 + 1;
  }
  long x38854 = 0L;
  long x38855 = x7;
  long x38856 = 0L;
  int* x38857 = (int*)malloc(x7 * sizeof(int));
  int* x38858 = x38857;
  char* x38861 = (char*)malloc(x7 * sizeof(char));
  char* x38862 = x38861;
  int x3633 = open("XXXXXorders.tbl",0);
  long x3634 = fsize(x3633);
  char* x3635 = mmap(0, x3634, PROT_READ, MAP_FILE | MAP_SHARED, x3633, 0);
  for (;;) {
    long x38875 = x38854;
    bool x38876 = x38875 < x3634;
    if (!x38876) break;
    int x38879 = 0;
    for (;;) {
      long x38880 = x38854;
      char x38881 = x3635[x38880];
      bool x38882 = x38881 != '|';
      bool x38887 = x38882;
      if (x38882) {
        long x38883 = x38854;
        char x38884 = x3635[x38883];
        bool x38885 = x38884 != '\n';
        x38887 = x38885;
      }
      bool x38888 = x38887;
      if (!x38888) break;
      int x38890 = x38879;
      long x38892 = x38854;
      int x38891 = x38890 * 10;
      char x38893 = x3635[x38892];
      char x38894 = x38893 - '0';
      int x38895 = x38891 + x38894;
      x38879 = x38895;
      x38854 = x38854 + 1;
    }
    x38854 = x38854 + 1;
    int x38901 = x38879;
    for (;;) {
      long x38904 = x38854;
      char x38905 = x3635[x38904];
      bool x38906 = x38905 != '|';
      bool x38911 = x38906;
      if (x38906) {
        long x38907 = x38854;
        char x38908 = x3635[x38907];
        bool x38909 = x38908 != '\n';
        x38911 = x38909;
      }
      bool x38912 = x38911;
      if (!x38912) break;
      x38854 = x38854 + 1;
    }
    x38854 = x38854 + 1;
    long x38926 = x38854;
    x38854 = x38854 + 2;
    for (;;) {
      long x38932 = x38854;
      char x38933 = x3635[x38932];
      bool x38934 = x38933 != '.';
      bool x38939 = x38934;
      if (x38934) {
        long x38935 = x38854;
        char x38936 = x3635[x38935];
        bool x38937 = x38936 != '|';
        x38939 = x38937;
      }
      bool x38940 = x38939;
      bool x38945 = x38940;
      if (x38940) {
        long x38941 = x38854;
        char x38942 = x3635[x38941];
        bool x38943 = x38942 != '\n';
        x38945 = x38943;
      }
      bool x38946 = x38945;
      if (!x38946) break;
      x38854 = x38854 + 1;
    }
    long x38958 = x38854;
    char x38959 = x3635[x38958];
    bool x38960 = x38959 == '.';
    if (x38960) {
      x38854 = x38854 + 1;
      for (;;) {
        long x38962 = x38854;
        char x38963 = x3635[x38962];
        bool x38964 = x38963 != '|';
        bool x38969 = x38964;
        if (x38964) {
          long x38965 = x38854;
          char x38966 = x3635[x38965];
          bool x38967 = x38966 != '\n';
          x38969 = x38967;
        }
        bool x38970 = x38969;
        if (!x38970) break;
        x38854 = x38854 + 1;
      }
    } else {
    }
    x38854 = x38854 + 1;
    for (;;) {
      long x38996 = x38854;
      char x38997 = x3635[x38996];
      bool x38998 = x38997 != '-';
      bool x39003 = x38998;
      if (x38998) {
        long x38999 = x38854;
        char x39000 = x3635[x38999];
        bool x39001 = x39000 != '\n';
        x39003 = x39001;
      }
      bool x39004 = x39003;
      if (!x39004) break;
      x38854 = x38854 + 1;
    }
    x38854 = x38854 + 1;
    for (;;) {
      long x39020 = x38854;
      char x39021 = x3635[x39020];
      bool x39022 = x39021 != '-';
      bool x39027 = x39022;
      if (x39022) {
        long x39023 = x38854;
        char x39024 = x3635[x39023];
        bool x39025 = x39024 != '\n';
        x39027 = x39025;
      }
      bool x39028 = x39027;
      if (!x39028) break;
      x38854 = x38854 + 1;
    }
    x38854 = x38854 + 1;
    for (;;) {
      long x39044 = x38854;
      char x39045 = x3635[x39044];
      bool x39046 = x39045 != '|';
      bool x39051 = x39046;
      if (x39046) {
        long x39047 = x38854;
        char x39048 = x3635[x39047];
        bool x39049 = x39048 != '\n';
        x39051 = x39049;
      }
      bool x39052 = x39051;
      if (!x39052) break;
      x38854 = x38854 + 1;
    }
    x38854 = x38854 + 1;
    for (;;) {
      long x39071 = x38854;
      char x39072 = x3635[x39071];
      bool x39073 = x39072 != '|';
      bool x39078 = x39073;
      if (x39073) {
        long x39074 = x38854;
        char x39075 = x3635[x39074];
        bool x39076 = x39075 != '\n';
        x39078 = x39076;
      }
      bool x39079 = x39078;
      if (!x39079) break;
      x38854 = x38854 + 1;
    }
    x38854 = x38854 + 1;
    for (;;) {
      long x39089 = x38854;
      char x39090 = x3635[x39089];
      bool x39091 = x39090 != '|';
      bool x39096 = x39091;
      if (x39091) {
        long x39092 = x38854;
        char x39093 = x3635[x39092];
        bool x39094 = x39093 != '\n';
        x39096 = x39094;
      }
      bool x39097 = x39096;
      if (!x39097) break;
      x38854 = x38854 + 1;
    }
    x38854 = x38854 + 1;
    for (;;) {
      long x39108 = x38854;
      char x39109 = x3635[x39108];
      bool x39110 = x39109 != '|';
      bool x39115 = x39110;
      if (x39110) {
        long x39111 = x38854;
        char x39112 = x3635[x39111];
        bool x39113 = x39112 != '\n';
        x39115 = x39113;
      }
      bool x39116 = x39115;
      if (!x39116) break;
      x38854 = x38854 + 1;
    }
    x38854 = x38854 + 1;
    for (;;) {
      long x39131 = x38854;
      char x39132 = x3635[x39131];
      bool x39133 = x39132 != '|';
      bool x39138 = x39133;
      if (x39133) {
        long x39134 = x38854;
        char x39135 = x3635[x39134];
        bool x39136 = x39135 != '\n';
        x39138 = x39136;
      }
      bool x39139 = x39138;
      if (!x39139) break;
      x38854 = x38854 + 1;
    }
    x38854 = x38854 + 1;
    long x39149 = x38854;
    bool x39150 = x39149 > 0L;
    bool x39156 = x39150;
    if (x39150) {
      long x39151 = x38854;
      long x39152 = x39151 - 1L;
      char x39153 = x3635[x39152];
      bool x39154 = x39153 != '\n';
      x39156 = x39154;
    }
    bool x39157 = x39156;
    if (x39157) {
      for (;;) {
        long x39158 = x38854;
        char x39159 = x3635[x39158];
        bool x39160 = x39159 != '\n';
        if (!x39160) break;
        x38854 = x38854 + 1;
      }
    } else {
    }
    x38854 = x38854 + 1;
    long x39169 = x38856;
    long x39170 = x38855;
    bool x39171 = x39169 == x39170;
    if (x39171) {
      long x39172 = x39170 * 4L;
      x38855 = x39172;
      printf("buffer.resize %ld\n",x39172);
      int* x39175 = x38858;
      int* x39176 = (int*)realloc(x39175,x39172 * sizeof(int));
      x38858 = x39176;
      char* x39181 = x38862;
      char* x39182 = (char*)realloc(x39181,x39172 * sizeof(char));
      x38862 = x39182;
    } else {
    }
    int* x39204 = x38858;
    x39204[x39169] = x38901;
    char* x39208 = x38862;
    char x38927 = x3635[x38926];
    x39208[x39169] = x38927;
    x38856 = x38856 + 1;
  }
  long x39225 = 0L;
  long x39226 = x7;
  long x39227 = 0L;
  int* x39228 = (int*)malloc(x7 * sizeof(int));
  int* x39229 = x39228;
  char** x39230 = (char**)malloc(x7 * sizeof(char*));
  char** x39231 = x39230;
  int x1633 = open("XXXXXnation.tbl",0);
  long x1634 = fsize(x1633);
  char* x1635 = mmap(0, x1634, PROT_READ, MAP_FILE | MAP_SHARED, x1633, 0);
  for (;;) {
    long x39236 = x39225;
    bool x39237 = x39236 < x1634;
    if (!x39237) break;
    int x39240 = 0;
    for (;;) {
      long x39241 = x39225;
      char x39242 = x1635[x39241];
      bool x39243 = x39242 != '|';
      bool x39248 = x39243;
      if (x39243) {
        long x39244 = x39225;
        char x39245 = x1635[x39244];
        bool x39246 = x39245 != '\n';
        x39248 = x39246;
      }
      bool x39249 = x39248;
      if (!x39249) break;
      int x39251 = x39240;
      long x39253 = x39225;
      int x39252 = x39251 * 10;
      char x39254 = x1635[x39253];
      char x39255 = x39254 - '0';
      int x39256 = x39252 + x39255;
      x39240 = x39256;
      x39225 = x39225 + 1;
    }
    x39225 = x39225 + 1;
    int x39262 = x39240;
    long x39263 = x39225;
    for (;;) {
      long x39264 = x39225;
      char x39265 = x1635[x39264];
      bool x39266 = x39265 != '|';
      bool x39271 = x39266;
      if (x39266) {
        long x39267 = x39225;
        char x39268 = x1635[x39267];
        bool x39269 = x39268 != '\n';
        x39271 = x39269;
      }
      bool x39272 = x39271;
      if (!x39272) break;
      x39225 = x39225 + 1;
    }
    x39225 = x39225 + 1;
    for (;;) {
      long x39283 = x39225;
      char x39284 = x1635[x39283];
      bool x39285 = x39284 != '|';
      bool x39290 = x39285;
      if (x39285) {
        long x39286 = x39225;
        char x39287 = x1635[x39286];
        bool x39288 = x39287 != '\n';
        x39290 = x39288;
      }
      bool x39291 = x39290;
      if (!x39291) break;
      x39225 = x39225 + 1;
    }
    x39225 = x39225 + 1;
    for (;;) {
      long x39306 = x39225;
      char x39307 = x1635[x39306];
      bool x39308 = x39307 != '|';
      bool x39313 = x39308;
      if (x39308) {
        long x39309 = x39225;
        char x39310 = x1635[x39309];
        bool x39311 = x39310 != '\n';
        x39313 = x39311;
      }
      bool x39314 = x39313;
      if (!x39314) break;
      x39225 = x39225 + 1;
    }
    x39225 = x39225 + 1;
    long x39324 = x39225;
    bool x39325 = x39324 > 0L;
    bool x39331 = x39325;
    if (x39325) {
      long x39326 = x39225;
      long x39327 = x39326 - 1L;
      char x39328 = x1635[x39327];
      bool x39329 = x39328 != '\n';
      x39331 = x39329;
    }
    bool x39332 = x39331;
    if (x39332) {
      for (;;) {
        long x39333 = x39225;
        char x39334 = x1635[x39333];
        bool x39335 = x39334 != '\n';
        if (!x39335) break;
        x39225 = x39225 + 1;
      }
    } else {
    }
    x39225 = x39225 + 1;
    long x39344 = x39227;
    long x39345 = x39226;
    bool x39346 = x39344 == x39345;
    if (x39346) {
      long x39347 = x39345 * 4L;
      x39226 = x39347;
      printf("buffer.resize %ld\n",x39347);
      int* x39350 = x39229;
      int* x39351 = (int*)realloc(x39350,x39347 * sizeof(int));
      x39229 = x39351;
      char** x39353 = x39231;
      char** x39354 = (char**)realloc(x39353,x39347 * sizeof(char*));
      x39231 = x39354;
    } else {
    }
    int* x39364 = x39229;
    x39364[x39344] = x39262;
    char** x39366 = x39231;
    char* x39280 = x1635+x39263;
    x39366[x39344] = x39280;
    x39227 = x39227 + 1;
  }
  long x2189 = DEFAULT_JOIN_HASH_SIZE;
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  long x2212 = x2189 - 1L;
  long x823 = x808 - 1L;
  int x39375;
  for(x39375=0; x39375 < 5; x39375++) {
    bool x39376 = false;
    long x39377 = 0L;
    bool x39379 = false;
    long x39380 = 0L;
    bool x39381 = false;
    long x39382 = 0L;
    bool x39384 = false;
    long x39385 = 0L;
    bool x39386 = false;
    long x39387 = 0L;
    bool x39389 = false;
    long x39390 = 0L;
    int* x39393 = (int*)malloc(x2189 * sizeof(int));
    int* x39394 = x39393;
    long x39401 = 0L;
    long* x39402 = (long*)malloc(x2189 * sizeof(long));
    long* x39403 = (long*)malloc(x2189 * sizeof(long));
    long x39404;
    for(x39404=0L; x39404 < x2189; x39404++) {
      x39402[x39404] = -1L;
    }
    int* x39418 = (int*)malloc(x2189 * sizeof(int));
    int* x39419 = x39418;
    char** x39420 = (char**)malloc(x2189 * sizeof(char*));
    char** x39421 = x39420;
    long x39432 = 0L;
    long* x39433 = (long*)malloc(x2189 * sizeof(long));
    long* x39434 = (long*)malloc(x2189 * sizeof(long));
    long x39435;
    for(x39435=0L; x39435 < x2189; x39435++) {
      x39433[x39435] = -1L;
    }
    char** x39451 = (char**)malloc(x2189 * sizeof(char*));
    char** x39452 = x39451;
    int* x39463 = (int*)malloc(x2189 * sizeof(int));
    int* x39464 = x39463;
    int* x39467 = (int*)malloc(x2189 * sizeof(int));
    int* x39468 = x39467;
    long x39495 = 0L;
    long* x39496 = (long*)malloc(x2189 * sizeof(long));
    long* x39497 = (long*)malloc(x2189 * sizeof(long));
    long x39498;
    for(x39498=0L; x39498 < x2189; x39498++) {
      x39496[x39498] = -1L;
    }
    int* x39504 = (int*)malloc(x2189 * sizeof(int));
    int* x39505 = x39504;
    int* x39508 = (int*)malloc(x2189 * sizeof(int));
    int* x39509 = x39508;
    long x39536 = 0L;
    long* x39537 = (long*)malloc(x2189 * sizeof(long));
    long* x39538 = (long*)malloc(x2189 * sizeof(long));
    long x39539;
    for(x39539=0L; x39539 < x2189; x39539++) {
      x39537[x39539] = -1L;
    }
    int* x39544 = (int*)malloc(x2189 * sizeof(int));
    int* x39545 = x39544;
    int* x39548 = (int*)malloc(x2189 * sizeof(int));
    int* x39549 = x39548;
    long x39576 = 0L;
    long* x39577 = (long*)malloc(x2189 * sizeof(long));
    long* x39578 = (long*)malloc(x2189 * sizeof(long));
    long x39579;
    for(x39579=0L; x39579 < x2189; x39579++) {
      x39577[x39579] = -1L;
    }
    struct Anon603726677* x39584 = (struct Anon603726677*)malloc(x808 * sizeof(struct Anon603726677));
    struct Anon603726677* x39585 = x39584;
    long x39586 = 0L;
    long* x39587 = (long*)malloc(x808 * sizeof(long));
    long x39588;
    for(x39588=0L; x39588 < x808; x39588++) {
      struct Anon603726677* x39589 = x39585;
      struct Anon603726677 x39590 = x39589[x39588];
      char* x39591 = x39590.key;;
      double x39592 = x39590.aggs;;
      struct Anon603726677 x39593;
      x39593.exists = false;
      x39593.key = x39591;
      x39593.aggs = x39592;
      x39589[x39588] = x39593;
    }
    long x39598 = 1024L;
    long x39599 = 0L;
    struct Anon603726677* x39600 = (struct Anon603726677*)malloc(1024L * sizeof(struct Anon603726677));
    struct Anon603726677* x39601 = x39600;
    int x39602 = 0;
    long x39604 = 0L;
    struct timeval x40399, x40400, x40401;
    gettimeofday(&x40399, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x39606 = x39379;
      bool x39607 = !x39606;
      bool x39612 = x39607;
      if (x39607) {
        long x39608 = x39380;
        long x39609 = x37790;
        bool x39610 = x39608 < x39609;
        x39612 = x39610;
      }
      bool x39613 = x39612;
      if (!x39613) break;
      long x39615 = x39380;
      int* x39616 = x37792;
      int x39617 = x39616[x39615];
      int* x39620 = x37796;
      int x39621 = x39620[x39615];
      x39380 = x39380 + 1;
      long x39650 = x39576;
      int* x39651 = x39545;
      x39651[x39650] = x39617;
      int* x39655 = x39549;
      x39655[x39650] = x39621;
      x39576 = x39576 + 1L;
      long x39684 = x39617 & x2212;
      long x39685 = x39577[x39684];
      x39577[x39684] = x39650;
      x39578[x39650] = x39685;
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x39691 = x39381;
      bool x39692 = !x39691;
      bool x39697 = x39692;
      if (x39692) {
        long x39693 = x39382;
        long x39694 = x37790;
        bool x39695 = x39693 < x39694;
        x39697 = x39695;
      }
      bool x39698 = x39697;
      if (!x39698) break;
      long x39700 = x39382;
      int* x39701 = x37792;
      int x39702 = x39701[x39700];
      int* x39705 = x37796;
      int x39706 = x39705[x39700];
      long* x39723 = x37814;
      long x39724 = x39723[x39700];
      long* x39725 = x37816;
      long x39726 = x39725[x39700];
      x39382 = x39382 + 1;
      bool x39735 = x39726 > x39724;
      if (x39735) {
        long x39736 = x39536;
        int* x39737 = x39505;
        x39737[x39736] = x39702;
        int* x39741 = x39509;
        x39741[x39736] = x39706;
        x39536 = x39536 + 1L;
        long x39770 = x39702 & x2212;
        long x39771 = x39537[x39770];
        x39537[x39770] = x39736;
        x39538[x39736] = x39771;
      } else {
      }
    }
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x39779 = x39386;
      bool x39780 = !x39779;
      bool x39785 = x39780;
      if (x39780) {
        long x39781 = x39387;
        long x39782 = x39227;
        bool x39783 = x39781 < x39782;
        x39785 = x39783;
      }
      bool x39786 = x39785;
      if (!x39786) break;
      long x39788 = x39387;
      int* x39789 = x39229;
      int x39790 = x39789[x39788];
      char** x39791 = x39231;
      char* x39792 = x39791[x39788];
      x39387 = x39387 + 1;
      bool x39799 = tpch_strcmp(x39792,"SAUDI ARABIA") == 0;;
      if (x39799) {
        long x39800 = x39401;
        int* x39801 = x39394;
        x39801[x39800] = x39790;
        x39401 = x39401 + 1L;
        long x39810 = x39790 & x2212;
        long x39811 = x39402[x39810];
        x39402[x39810] = x39800;
        x39403[x39800] = x39811;
      } else {
      }
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x39819 = x39384;
      bool x39820 = !x39819;
      bool x39825 = x39820;
      if (x39820) {
        long x39821 = x39385;
        long x39822 = x38584;
        bool x39823 = x39821 < x39822;
        x39825 = x39823;
      }
      bool x39826 = x39825;
      if (!x39826) break;
      long x39828 = x39385;
      int* x39829 = x38586;
      int x39830 = x39829[x39828];
      char** x39831 = x38588;
      char* x39832 = x39831[x39828];
      int* x39835 = x38592;
      int x39836 = x39835[x39828];
      x39385 = x39385 + 1;
      long x39845 = x39836 & x2212;
      long x39846 = x39402[x39845];
      long x39847 = x39846;
      long x39891 = x39830 & x2212;
      for (;;) {
        long x39848 = x39847;
        bool x39849 = x39848 != -1;
        if (!x39849) break;
        long x39851 = x39847;
        int* x39852 = x39394;
        int x39853 = x39852[x39851];
        long x39861 = x39403[x39851];
        x39847 = x39861;
        bool x39863 = x39853 == x39836;
        if (x39863) {
          long x39867 = x39432;
          int* x39876 = x39419;
          x39876[x39867] = x39830;
          char** x39878 = x39421;
          x39878[x39867] = x39832;
          x39432 = x39432 + 1L;
          long x39892 = x39433[x39891];
          x39433[x39891] = x39867;
          x39434[x39867] = x39892;
        } else {
        }
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x39902 = x39376;
      bool x39903 = !x39902;
      bool x39908 = x39903;
      if (x39903) {
        long x39904 = x39377;
        long x39905 = x37790;
        bool x39906 = x39904 < x39905;
        x39908 = x39906;
      }
      bool x39909 = x39908;
      if (!x39909) break;
      long x39911 = x39377;
      int* x39912 = x37792;
      int x39913 = x39912[x39911];
      int* x39916 = x37796;
      int x39917 = x39916[x39911];
      long* x39934 = x37814;
      long x39935 = x39934[x39911];
      long* x39936 = x37816;
      long x39937 = x39936[x39911];
      x39377 = x39377 + 1;
      bool x39946 = x39937 > x39935;
      if (x39946) {
        long x39947 = x39917 & x2212;
        long x39948 = x39433[x39947];
        long x39949 = x39948;
        long x40039 = x39913 & x2212;
        for (;;) {
          long x39950 = x39949;
          bool x39951 = x39950 != -1;
          if (!x39951) break;
          long x39953 = x39949;
          int* x39962 = x39419;
          int x39963 = x39962[x39953];
          char** x39964 = x39421;
          char* x39965 = x39964[x39953];
          long x39977 = x39434[x39953];
          x39949 = x39977;
          bool x39979 = x39963 == x39917;
          if (x39979) {
            long x39983 = x39495;
            char** x39994 = x39452;
            x39994[x39983] = x39965;
            int* x40006 = x39464;
            x40006[x39983] = x39913;
            int* x40010 = x39468;
            x40010[x39983] = x39917;
            x39495 = x39495 + 1L;
            long x40040 = x39496[x40039];
            x39496[x40039] = x39983;
            x39497[x39983] = x40040;
          } else {
          }
        }
      } else {
      }
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x40052 = x39389;
      bool x40053 = !x40052;
      bool x40058 = x40053;
      if (x40053) {
        long x40054 = x39390;
        long x40055 = x38856;
        bool x40056 = x40054 < x40055;
        x40058 = x40056;
      }
      bool x40059 = x40058;
      if (!x40059) break;
      long x40061 = x39390;
      int* x40062 = x38858;
      int x40063 = x40062[x40061];
      char* x40066 = x38862;
      char x40067 = x40066[x40061];
      x39390 = x39390 + 1;
      bool x40082 = x40067 == 'F';
      if (x40082) {
        long x40083 = x40063 & x2212;
        long x40084 = x39496[x40083];
        long x40085 = x40084;
        for (;;) {
          long x40086 = x40085;
          bool x40087 = x40086 != -1;
          if (!x40087) break;
          long x40089 = x40085;
          char** x40100 = x39452;
          char* x40101 = x40100[x40089];
          int* x40112 = x39464;
          int x40113 = x40112[x40089];
          int* x40116 = x39468;
          int x40117 = x40116[x40089];
          long x40145 = x39497[x40089];
          x40085 = x40145;
          bool x40147 = x40063 == x40113;
          if (x40147) {
            long x40151 = x40113 & x2212;
            long x40152 = x39537[x40151];
            long x40153 = x40152;
            bool x40154 = x40152 == -1L;
            bool x40155 = x40154;
            for (;;) {
              bool x40156 = x40155;
              bool x40157 = !x40156;
              if (!x40157) break;
              long x40159 = x40153;
              int* x40160 = x39505;
              int x40161 = x40160[x40159];
              int* x40164 = x39509;
              int x40165 = x40164[x40159];
              bool x40193 = x40113 == x40161;
              bool x40195 = x40193;
              if (x40193) {
                bool x40194 = x40117 != x40165;
                x40195 = x40194;
              }
              bool x40196 = x40195;
              if (x40196) {
                x40155 = true;
              } else {
                long x40199 = x39538[x40159];
                x40153 = x40199;
                bool x40201 = x40199 == -1;
                x40155 = x40201;
              }
            }
            long x40207 = x40153;
            bool x40208 = x40207 == -1;
            if (x40208) {
              long x40209 = x39577[x40151];
              long x40210 = x40209;
              bool x40211 = x40209 == -1L;
              bool x40212 = x40211;
              for (;;) {
                bool x40213 = x40212;
                bool x40214 = !x40213;
                if (!x40214) break;
                long x40216 = x40210;
                int* x40217 = x39545;
                int x40218 = x40217[x40216];
                int* x40221 = x39549;
                int x40222 = x40221[x40216];
                bool x40250 = x40113 == x40218;
                bool x40252 = x40250;
                if (x40250) {
                  bool x40251 = x40117 != x40222;
                  x40252 = x40251;
                }
                bool x40253 = x40252;
                if (x40253) {
                  x40212 = true;
                } else {
                  long x40256 = x39578[x40216];
                  x40210 = x40256;
                  bool x40258 = x40256 == -1;
                  x40212 = x40258;
                }
              }
              long x40264 = x40210;
              bool x40266 = x40264 == -1;
              if (x40266) {
              } else {
                long x40267 = hash(x40101, 10L);
                long x40268 = x40267 & x823;
                long x40269 = x40268;
                struct Anon603726677* x40270 = x39585;
                struct Anon603726677 x40271 = x40270[x40268];
                struct Anon603726677 x40272 = x40271;
                bool x40273 = x40271.exists;;
                bool x40278 = x40273;
                if (x40273) {
                  struct Anon603726677 x40274 = x40272;
                  char* x40275 = x40274.key;;
                  bool x40276 = tpch_strcmp(x40275,x40101) == 0;;
                  x40278 = x40276;
                }
                bool x40279 = x40278;
                if (x40279) {
                  double x40280 = x40271.aggs;;
                  char* x40282 = x40271.key;;
                  double x40281 = x40280 + 1.0;
                  struct Anon603726677 x40283;
                  x40283.exists = true;
                  x40283.key = x40282;
                  x40283.aggs = x40281;
                  x40270[x40268] = x40283;
                } else {
                  struct Anon603726677 x40310;
                  x40310.exists = true;
                  x40310.key = x40101;
                  x40310.aggs = 1.0;
                  for (;;) {
                    struct Anon603726677 x40286 = x40272;
                    bool x40287 = x40286.exists;;
                    bool x40319;
                    if (x40287) {
                      char* x40288 = x40286.key;;
                      bool x40289 = tpch_strcmp(x40288,x40101) == 0;;
                      bool x40307;
                      if (x40289) {
                        double x40290 = x40286.aggs;;
                        long x40292 = x40269;
                        struct Anon603726677* x40294 = x39585;
                        double x40291 = x40290 + 1.0;
                        struct Anon603726677 x40293;
                        x40293.exists = true;
                        x40293.key = x40288;
                        x40293.aggs = x40291;
                        x40294[x40292] = x40293;
                        x40307 = false;
                      } else {
                        long x40297 = x40269;
                        long x40298 = x40297 + 1L;
                        long x40299 = x40298 & x823;
                        x40269 = x40299;
                        struct Anon603726677* x40301 = x39585;
                        struct Anon603726677 x40302 = x40301[x40299];
                        x40272 = x40302;
                        x40307 = true;
                      }
                      x40319 = x40307;
                    } else {
                      long x40309 = x40269;
                      struct Anon603726677* x40311 = x39585;
                      x40311[x40309] = x40310;
                      long x40313 = x39586;
                      x39587[x40313] = x40309;
                      x39586 = x39586 + 1L;
                      x40319 = false;
                    }
                    if (!x40319) break;
                  }
                }
              }
            } else {
            }
          } else {
          }
        }
      } else {
      }
    }
    long x40338 = x39586;
    long x40340;
    for(x40340=0L; x40340 < x40338; x40340++) {
      long x40341 = x39587[x40340];
      struct Anon603726677* x40342 = x39585;
      struct Anon603726677 x40343 = x40342[x40341];
      long x40344 = x39599;
      long x40345 = x39598;
      bool x40346 = x40344 == x40345;
      if (x40346) {
        long x40347 = x40345 * 4L;
        x39598 = x40347;
        struct Anon603726677* x40349 = x39601;
        struct Anon603726677* x40350 = (struct Anon603726677 *)realloc(x40349,x40347* sizeof(struct Anon603726677));
        x39601 = x40350;
      } else {
      }
      struct Anon603726677* x40354 = x39601;
      x40354[x40344] = x40343;
      x39599 = x39599 + 1;
    }
    long x40359 = x39599;
    struct Anon603726677* x40360 = x39601;
    qsort((void *)x40360,x40359,sizeof(struct Anon603726677), (__compar_fn_t)x40375); // x40376
    long x40378;
    for(x40378=0L; x40378 < x40359; x40378++) {
      struct Anon603726677* x40379 = x39601;
      struct Anon603726677 x40380 = x40379[x40378];
      int x40381 = x39602;
      bool x40382 = x40381 < 100;
      bool x40383 = x40382 == false;
      if (x40383) {
      } else {
        char* x40386 = x40380.key;;
        double x40388 = x40380.aggs;;
        int x40387 = tpch_strlen(x40386);
        printf("%.*s|%.0f\n",x40387,x40386,x40388);
        x39602 = x39602 + 1;
        x39604 = x39604 + 1L;
      }
    }
    long x40396 = x39604;
    printf("(%ld rows)\n",x40396);
    gettimeofday(&x40400, NULL);
    timeval_subtract(&x40401, &x40400, &x40399);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x40401.tv_sec * 1000) + (x40401.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
