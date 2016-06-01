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

struct Anon310558733 {
char _0;
char _1;
};

struct Anon197582733 {
bool exists;
struct Anon310558733 key;
struct Anon189208763 aggs;
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

struct Anon0 {
struct Anon2052879266 left;
struct Anon920667905 right;
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

struct Anon1209778821 {
int C_CUSTKEY;
double C_ACCTBAL;
char* C_PHONE;
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
int x41571(struct Anon197582733* x41552, struct Anon197582733* x41553);
int x41571(struct Anon197582733* x41552, struct Anon197582733* x41553) {
  struct Anon197582733 x41554 = (*x41552);
  struct Anon197582733 x41555 = (*x41553);
  struct Anon310558733 x41556 = x41554.key;;
  char x41557 = x41556._0;;
  struct Anon310558733 x41558 = x41555.key;;
  char x41559 = x41558._0;;
  int x41560 = x41557 - x41559;
  int x41561 = x41560;
  bool x41562 = x41560 == 0;
  if (x41562) {
    char x41563 = x41556._1;;
    char x41564 = x41558._1;;
    int x41565 = x41563 - x41564;
    x41561 = x41565;
  } else {
  }
  int x41569 = x41561;
  return x41569;
}

/************************ MAIN BODY **************************/
int main(int x40406, char** x40407) {
  long x40408 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x40409 = x7;
  long x40410 = 0L;
  int* x40411 = (int*)malloc(x7 * sizeof(int));
  int* x40412 = x40411;
  char** x40419 = (char**)malloc(x7 * sizeof(char*));
  char** x40420 = x40419;
  double* x40421 = (double*)malloc(x7 * sizeof(double));
  double* x40422 = x40421;
  int x4007 = open("XXXXXcustomer.tbl",0);
  long x4008 = fsize(x4007);
  char* x4009 = mmap(0, x4008, PROT_READ, MAP_FILE | MAP_SHARED, x4007, 0);
  for (;;) {
    long x40427 = x40408;
    bool x40428 = x40427 < x4008;
    if (!x40428) break;
    int x40431 = 0;
    for (;;) {
      long x40432 = x40408;
      char x40433 = x4009[x40432];
      bool x40434 = x40433 != '|';
      bool x40439 = x40434;
      if (x40434) {
        long x40435 = x40408;
        char x40436 = x4009[x40435];
        bool x40437 = x40436 != '\n';
        x40439 = x40437;
      }
      bool x40440 = x40439;
      if (!x40440) break;
      int x40442 = x40431;
      long x40444 = x40408;
      int x40443 = x40442 * 10;
      char x40445 = x4009[x40444];
      char x40446 = x40445 - '0';
      int x40447 = x40443 + x40446;
      x40431 = x40447;
      x40408 = x40408 + 1;
    }
    x40408 = x40408 + 1;
    int x40453 = x40431;
    for (;;) {
      long x40455 = x40408;
      char x40456 = x4009[x40455];
      bool x40457 = x40456 != '|';
      bool x40462 = x40457;
      if (x40457) {
        long x40458 = x40408;
        char x40459 = x4009[x40458];
        bool x40460 = x40459 != '\n';
        x40462 = x40460;
      }
      bool x40463 = x40462;
      if (!x40463) break;
      x40408 = x40408 + 1;
    }
    x40408 = x40408 + 1;
    for (;;) {
      long x40473 = x40408;
      char x40474 = x4009[x40473];
      bool x40475 = x40474 != '|';
      bool x40480 = x40475;
      if (x40475) {
        long x40476 = x40408;
        char x40477 = x4009[x40476];
        bool x40478 = x40477 != '\n';
        x40480 = x40478;
      }
      bool x40481 = x40480;
      if (!x40481) break;
      x40408 = x40408 + 1;
    }
    x40408 = x40408 + 1;
    for (;;) {
      long x40492 = x40408;
      char x40493 = x4009[x40492];
      bool x40494 = x40493 != '|';
      bool x40499 = x40494;
      if (x40494) {
        long x40495 = x40408;
        char x40496 = x4009[x40495];
        bool x40497 = x40496 != '\n';
        x40499 = x40497;
      }
      bool x40500 = x40499;
      if (!x40500) break;
      x40408 = x40408 + 1;
    }
    x40408 = x40408 + 1;
    long x40514 = x40408;
    for (;;) {
      long x40515 = x40408;
      char x40516 = x4009[x40515];
      bool x40517 = x40516 != '|';
      bool x40522 = x40517;
      if (x40517) {
        long x40518 = x40408;
        char x40519 = x4009[x40518];
        bool x40520 = x40519 != '\n';
        x40522 = x40520;
      }
      bool x40523 = x40522;
      if (!x40523) break;
      x40408 = x40408 + 1;
    }
    x40408 = x40408 + 1;
    int x40533 = 0;
    int x40534 = 1;
    for (;;) {
      long x40535 = x40408;
      char x40536 = x4009[x40535];
      bool x40537 = x40536 != '.';
      bool x40542 = x40537;
      if (x40537) {
        long x40538 = x40408;
        char x40539 = x4009[x40538];
        bool x40540 = x40539 != '|';
        x40542 = x40540;
      }
      bool x40543 = x40542;
      bool x40548 = x40543;
      if (x40543) {
        long x40544 = x40408;
        char x40545 = x4009[x40544];
        bool x40546 = x40545 != '\n';
        x40548 = x40546;
      }
      bool x40549 = x40548;
      if (!x40549) break;
      int x40551 = x40533;
      long x40553 = x40408;
      int x40552 = x40551 * 10;
      char x40554 = x4009[x40553];
      char x40555 = x40554 - '0';
      int x40556 = x40552 + x40555;
      x40533 = x40556;
      x40408 = x40408 + 1;
    }
    long x40561 = x40408;
    char x40562 = x4009[x40561];
    bool x40563 = x40562 == '.';
    if (x40563) {
      x40408 = x40408 + 1;
      for (;;) {
        long x40565 = x40408;
        char x40566 = x4009[x40565];
        bool x40567 = x40566 != '|';
        bool x40572 = x40567;
        if (x40567) {
          long x40568 = x40408;
          char x40569 = x4009[x40568];
          bool x40570 = x40569 != '\n';
          x40572 = x40570;
        }
        bool x40573 = x40572;
        if (!x40573) break;
        int x40575 = x40533;
        long x40577 = x40408;
        int x40576 = x40575 * 10;
        char x40578 = x4009[x40577];
        char x40579 = x40578 - '0';
        int x40580 = x40576 + x40579;
        x40533 = x40580;
        int x40582 = x40534;
        int x40583 = x40582 * 10;
        x40534 = x40583;
        x40408 = x40408 + 1;
      }
    } else {
    }
    x40408 = x40408 + 1;
    int x40592 = x40533;
    int x40594 = x40534;
    for (;;) {
      long x40598 = x40408;
      char x40599 = x4009[x40598];
      bool x40600 = x40599 != '|';
      bool x40605 = x40600;
      if (x40600) {
        long x40601 = x40408;
        char x40602 = x4009[x40601];
        bool x40603 = x40602 != '\n';
        x40605 = x40603;
      }
      bool x40606 = x40605;
      if (!x40606) break;
      x40408 = x40408 + 1;
    }
    x40408 = x40408 + 1;
    for (;;) {
      long x40616 = x40408;
      char x40617 = x4009[x40616];
      bool x40618 = x40617 != '|';
      bool x40623 = x40618;
      if (x40618) {
        long x40619 = x40408;
        char x40620 = x4009[x40619];
        bool x40621 = x40620 != '\n';
        x40623 = x40621;
      }
      bool x40624 = x40623;
      if (!x40624) break;
      x40408 = x40408 + 1;
    }
    x40408 = x40408 + 1;
    long x40634 = x40408;
    bool x40635 = x40634 > 0L;
    bool x40641 = x40635;
    if (x40635) {
      long x40636 = x40408;
      long x40637 = x40636 - 1L;
      char x40638 = x4009[x40637];
      bool x40639 = x40638 != '\n';
      x40641 = x40639;
    }
    bool x40642 = x40641;
    if (x40642) {
      for (;;) {
        long x40643 = x40408;
        char x40644 = x4009[x40643];
        bool x40645 = x40644 != '\n';
        if (!x40645) break;
        x40408 = x40408 + 1;
      }
    } else {
    }
    x40408 = x40408 + 1;
    long x40654 = x40410;
    long x40655 = x40409;
    bool x40656 = x40654 == x40655;
    if (x40656) {
      long x40657 = x40655 * 4L;
      x40409 = x40657;
      printf("buffer.resize %ld\n",x40657);
      int* x40660 = x40412;
      int* x40661 = (int*)realloc(x40660,x40657 * sizeof(int));
      x40412 = x40661;
      char** x40672 = x40420;
      char** x40673 = (char**)realloc(x40672,x40657 * sizeof(char*));
      x40420 = x40673;
      double* x40675 = x40422;
      double* x40676 = (double*)realloc(x40675,x40657 * sizeof(double));
      x40422 = x40676;
    } else {
    }
    int* x40686 = x40412;
    x40686[x40654] = x40453;
    char** x40694 = x40420;
    char* x40531 = x4009+x40514;
    x40694[x40654] = x40531;
    double* x40696 = x40422;
    double x40593 = (double)x40592;
    double x40595 = (double)x40594;
    double x40596 = x40593 / x40595;
    x40696[x40654] = x40596;
    x40410 = x40410 + 1;
  }
  long x40705 = 0L;
  long x40706 = x7;
  long x40707 = 0L;
  int* x40710 = (int*)malloc(x7 * sizeof(int));
  int* x40711 = x40710;
  int x3633 = open("XXXXXorders.tbl",0);
  long x3634 = fsize(x3633);
  char* x3635 = mmap(0, x3634, PROT_READ, MAP_FILE | MAP_SHARED, x3633, 0);
  for (;;) {
    long x40726 = x40705;
    bool x40727 = x40726 < x3634;
    if (!x40727) break;
    for (;;) {
      long x40731 = x40705;
      char x40732 = x3635[x40731];
      bool x40733 = x40732 != '|';
      bool x40738 = x40733;
      if (x40733) {
        long x40734 = x40705;
        char x40735 = x3635[x40734];
        bool x40736 = x40735 != '\n';
        x40738 = x40736;
      }
      bool x40739 = x40738;
      if (!x40739) break;
      x40705 = x40705 + 1;
    }
    x40705 = x40705 + 1;
    int x40754 = 0;
    for (;;) {
      long x40755 = x40705;
      char x40756 = x3635[x40755];
      bool x40757 = x40756 != '|';
      bool x40762 = x40757;
      if (x40757) {
        long x40758 = x40705;
        char x40759 = x3635[x40758];
        bool x40760 = x40759 != '\n';
        x40762 = x40760;
      }
      bool x40763 = x40762;
      if (!x40763) break;
      int x40765 = x40754;
      long x40767 = x40705;
      int x40766 = x40765 * 10;
      char x40768 = x3635[x40767];
      char x40769 = x40768 - '0';
      int x40770 = x40766 + x40769;
      x40754 = x40770;
      x40705 = x40705 + 1;
    }
    x40705 = x40705 + 1;
    int x40776 = x40754;
    x40705 = x40705 + 2;
    for (;;) {
      long x40783 = x40705;
      char x40784 = x3635[x40783];
      bool x40785 = x40784 != '.';
      bool x40790 = x40785;
      if (x40785) {
        long x40786 = x40705;
        char x40787 = x3635[x40786];
        bool x40788 = x40787 != '|';
        x40790 = x40788;
      }
      bool x40791 = x40790;
      bool x40796 = x40791;
      if (x40791) {
        long x40792 = x40705;
        char x40793 = x3635[x40792];
        bool x40794 = x40793 != '\n';
        x40796 = x40794;
      }
      bool x40797 = x40796;
      if (!x40797) break;
      x40705 = x40705 + 1;
    }
    long x40809 = x40705;
    char x40810 = x3635[x40809];
    bool x40811 = x40810 == '.';
    if (x40811) {
      x40705 = x40705 + 1;
      for (;;) {
        long x40813 = x40705;
        char x40814 = x3635[x40813];
        bool x40815 = x40814 != '|';
        bool x40820 = x40815;
        if (x40815) {
          long x40816 = x40705;
          char x40817 = x3635[x40816];
          bool x40818 = x40817 != '\n';
          x40820 = x40818;
        }
        bool x40821 = x40820;
        if (!x40821) break;
        x40705 = x40705 + 1;
      }
    } else {
    }
    x40705 = x40705 + 1;
    for (;;) {
      long x40847 = x40705;
      char x40848 = x3635[x40847];
      bool x40849 = x40848 != '-';
      bool x40854 = x40849;
      if (x40849) {
        long x40850 = x40705;
        char x40851 = x3635[x40850];
        bool x40852 = x40851 != '\n';
        x40854 = x40852;
      }
      bool x40855 = x40854;
      if (!x40855) break;
      x40705 = x40705 + 1;
    }
    x40705 = x40705 + 1;
    for (;;) {
      long x40871 = x40705;
      char x40872 = x3635[x40871];
      bool x40873 = x40872 != '-';
      bool x40878 = x40873;
      if (x40873) {
        long x40874 = x40705;
        char x40875 = x3635[x40874];
        bool x40876 = x40875 != '\n';
        x40878 = x40876;
      }
      bool x40879 = x40878;
      if (!x40879) break;
      x40705 = x40705 + 1;
    }
    x40705 = x40705 + 1;
    for (;;) {
      long x40895 = x40705;
      char x40896 = x3635[x40895];
      bool x40897 = x40896 != '|';
      bool x40902 = x40897;
      if (x40897) {
        long x40898 = x40705;
        char x40899 = x3635[x40898];
        bool x40900 = x40899 != '\n';
        x40902 = x40900;
      }
      bool x40903 = x40902;
      if (!x40903) break;
      x40705 = x40705 + 1;
    }
    x40705 = x40705 + 1;
    for (;;) {
      long x40922 = x40705;
      char x40923 = x3635[x40922];
      bool x40924 = x40923 != '|';
      bool x40929 = x40924;
      if (x40924) {
        long x40925 = x40705;
        char x40926 = x3635[x40925];
        bool x40927 = x40926 != '\n';
        x40929 = x40927;
      }
      bool x40930 = x40929;
      if (!x40930) break;
      x40705 = x40705 + 1;
    }
    x40705 = x40705 + 1;
    for (;;) {
      long x40940 = x40705;
      char x40941 = x3635[x40940];
      bool x40942 = x40941 != '|';
      bool x40947 = x40942;
      if (x40942) {
        long x40943 = x40705;
        char x40944 = x3635[x40943];
        bool x40945 = x40944 != '\n';
        x40947 = x40945;
      }
      bool x40948 = x40947;
      if (!x40948) break;
      x40705 = x40705 + 1;
    }
    x40705 = x40705 + 1;
    for (;;) {
      long x40959 = x40705;
      char x40960 = x3635[x40959];
      bool x40961 = x40960 != '|';
      bool x40966 = x40961;
      if (x40961) {
        long x40962 = x40705;
        char x40963 = x3635[x40962];
        bool x40964 = x40963 != '\n';
        x40966 = x40964;
      }
      bool x40967 = x40966;
      if (!x40967) break;
      x40705 = x40705 + 1;
    }
    x40705 = x40705 + 1;
    for (;;) {
      long x40982 = x40705;
      char x40983 = x3635[x40982];
      bool x40984 = x40983 != '|';
      bool x40989 = x40984;
      if (x40984) {
        long x40985 = x40705;
        char x40986 = x3635[x40985];
        bool x40987 = x40986 != '\n';
        x40989 = x40987;
      }
      bool x40990 = x40989;
      if (!x40990) break;
      x40705 = x40705 + 1;
    }
    x40705 = x40705 + 1;
    long x41000 = x40705;
    bool x41001 = x41000 > 0L;
    bool x41007 = x41001;
    if (x41001) {
      long x41002 = x40705;
      long x41003 = x41002 - 1L;
      char x41004 = x3635[x41003];
      bool x41005 = x41004 != '\n';
      x41007 = x41005;
    }
    bool x41008 = x41007;
    if (x41008) {
      for (;;) {
        long x41009 = x40705;
        char x41010 = x3635[x41009];
        bool x41011 = x41010 != '\n';
        if (!x41011) break;
        x40705 = x40705 + 1;
      }
    } else {
    }
    x40705 = x40705 + 1;
    long x41020 = x40707;
    long x41021 = x40706;
    bool x41022 = x41020 == x41021;
    if (x41022) {
      long x41023 = x41021 * 4L;
      x40706 = x41023;
      printf("buffer.resize %ld\n",x41023);
      int* x41029 = x40711;
      int* x41030 = (int*)realloc(x41029,x41023 * sizeof(int));
      x40711 = x41030;
    } else {
    }
    int* x41057 = x40711;
    x41057[x41020] = x40776;
    x40707 = x40707 + 1;
  }
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  long x2189 = DEFAULT_JOIN_HASH_SIZE;
  long x2212 = x2189 - 1L;
  long x823 = x808 - 1L;
  bool x1043 = true == false;
  int x41076;
  for(x41076=0; x41076 < 5; x41076++) {
    bool x41077 = false;
    long x41078 = 0L;
    struct Anon793459755* x41081 = (struct Anon793459755*)malloc(x808 * sizeof(struct Anon793459755));
    struct Anon793459755* x41082 = x41081;
    long x41083 = 0L;
    long* x41084 = (long*)malloc(x808 * sizeof(long));
    long x41085;
    for(x41085=0L; x41085 < x808; x41085++) {
      struct Anon793459755* x41086 = x41082;
      struct Anon793459755 x41087 = x41086[x41085];
      char* x41088 = x41087.key;;
      struct Anon189208763 x41089 = x41087.aggs;;
      struct Anon793459755 x41090;
      x41090.exists = false;
      x41090.key = x41088;
      x41090.aggs = x41089;
      x41086[x41085] = x41090;
    }
    bool x41095 = false;
    long x41096 = 0L;
    double x41098 = 0.0;
    bool x41101 = false;
    long x41102 = 0L;
    int* x41106 = (int*)malloc(x2189 * sizeof(int));
    int* x41107 = x41106;
    long x41122 = 0L;
    long* x41123 = (long*)malloc(x2189 * sizeof(long));
    long* x41124 = (long*)malloc(x2189 * sizeof(long));
    long x41125;
    for(x41125=0L; x41125 < x2189; x41125++) {
      x41123[x41125] = -1L;
    }
    struct Anon197582733* x41130 = (struct Anon197582733*)malloc(x808 * sizeof(struct Anon197582733));
    struct Anon197582733* x41131 = x41130;
    long x41132 = 0L;
    long* x41133 = (long*)malloc(x808 * sizeof(long));
    long x41134;
    for(x41134=0L; x41134 < x808; x41134++) {
      struct Anon197582733* x41135 = x41131;
      struct Anon197582733 x41136 = x41135[x41134];
      struct Anon310558733 x41137 = x41136.key;;
      struct Anon189208763 x41138 = x41136.aggs;;
      struct Anon197582733 x41139;
      x41139.exists = false;
      x41139.key = x41137;
      x41139.aggs = x41138;
      x41135[x41134] = x41139;
    }
    long x41144 = 1024L;
    long x41145 = 0L;
    struct Anon197582733* x41146 = (struct Anon197582733*)malloc(1024L * sizeof(struct Anon197582733));
    struct Anon197582733* x41147 = x41146;
    long x41149 = 0L;
    struct timeval x41594, x41595, x41596;
    gettimeofday(&x41594, NULL);
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x41151 = x41101;
      bool x41152 = !x41151;
      bool x41157 = x41152;
      if (x41152) {
        long x41153 = x41102;
        long x41154 = x40707;
        bool x41155 = x41153 < x41154;
        x41157 = x41155;
      }
      bool x41158 = x41157;
      if (!x41158) break;
      long x41160 = x41102;
      int* x41163 = x40711;
      int x41164 = x41163[x41160];
      x41102 = x41102 + 1;
      long x41181 = x41122;
      int* x41184 = x41107;
      x41184[x41181] = x41164;
      x41122 = x41122 + 1L;
      long x41201 = x41164 & x2212;
      long x41202 = x41123[x41201];
      x41123[x41201] = x41181;
      x41124[x41181] = x41202;
    }
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x41208 = x41077;
      bool x41209 = !x41208;
      bool x41214 = x41209;
      if (x41209) {
        long x41210 = x41078;
        long x41211 = x40410;
        bool x41212 = x41210 < x41211;
        x41214 = x41212;
      }
      bool x41215 = x41214;
      if (!x41215) break;
      long x41217 = x41078;
      char** x41226 = x40420;
      char* x41227 = x41226[x41217];
      double* x41228 = x40422;
      double x41229 = x41228[x41217];
      x41078 = x41078 + 1;
      bool x41236 = x41229 > 0.0;
      bool x41256 = x41236;
      if (x41236) {
        bool x41237 = strncmp(x41227,"13", tpch_strlen("13")) == 0;;
        bool x41254 = x41237;
        if (x41237 == false) {
          bool x41238 = strncmp(x41227,"31", tpch_strlen("31")) == 0;;
          bool x41252 = x41238;
          if (x41238 == false) {
            bool x41239 = strncmp(x41227,"23", tpch_strlen("23")) == 0;;
            bool x41250 = x41239;
            if (x41239 == false) {
              bool x41240 = strncmp(x41227,"29", tpch_strlen("29")) == 0;;
              bool x41248 = x41240;
              if (x41240 == false) {
                bool x41241 = strncmp(x41227,"30", tpch_strlen("30")) == 0;;
                bool x41246 = x41241;
                if (x41241 == false) {
                  bool x41242 = strncmp(x41227,"18", tpch_strlen("18")) == 0;;
                  bool x41244 = x41242;
                  if (x41242 == false) {
                    bool x41243 = strncmp(x41227,"17", tpch_strlen("17")) == 0;;
                    x41244 = x41243;
                  }
                  bool x41245 = x41244;
                  x41246 = x41245;
                }
                bool x41247 = x41246;
                x41248 = x41247;
              }
              bool x41249 = x41248;
              x41250 = x41249;
            }
            bool x41251 = x41250;
            x41252 = x41251;
          }
          bool x41253 = x41252;
          x41254 = x41253;
        }
        bool x41255 = x41254;
        x41256 = x41255;
      }
      bool x41257 = x41256;
      if (x41257) {
        long x41258 = hash("AVG_C_ACCTBAL", 10L);
        long x41259 = x41258 & x823;
        long x41260 = x41259;
        struct Anon793459755* x41261 = x41082;
        struct Anon793459755 x41262 = x41261[x41259];
        struct Anon793459755 x41263 = x41262;
        bool x41264 = x41262.exists;;
        bool x41269 = x41264;
        if (x41264) {
          struct Anon793459755 x41265 = x41263;
          char* x41266 = x41265.key;;
          bool x41267 = tpch_strcmp(x41266,"AVG_C_ACCTBAL") == 0;;
          x41269 = x41267;
        }
        bool x41270 = x41269;
        if (x41270) {
          struct Anon189208763 x41271 = x41262.aggs;;
          char* x41277 = x41262.key;;
          double x41272 = x41271._0;;
          double x41273 = x41229 + x41272;
          double x41274 = x41271._1;;
          double x41275 = x41274 + 1.0;
          struct Anon189208763 x41276;
          x41276._0 = x41273;
          x41276._1 = x41275;
          struct Anon793459755 x41278;
          x41278.exists = true;
          x41278.key = x41277;
          x41278.aggs = x41276;
          x41261[x41259] = x41278;
        } else {
          struct Anon189208763 x41309;
          x41309._0 = x41229;
          x41309._1 = 1.0;
          struct Anon793459755 x41310;
          x41310.exists = true;
          x41310.key = "AVG_C_ACCTBAL";
          x41310.aggs = x41309;
          for (;;) {
            struct Anon793459755 x41281 = x41263;
            bool x41282 = x41281.exists;;
            bool x41319;
            if (x41282) {
              char* x41283 = x41281.key;;
              bool x41284 = tpch_strcmp(x41283,"AVG_C_ACCTBAL") == 0;;
              bool x41306;
              if (x41284) {
                struct Anon189208763 x41285 = x41281.aggs;;
                long x41291 = x41260;
                struct Anon793459755* x41293 = x41082;
                double x41286 = x41285._0;;
                double x41287 = x41229 + x41286;
                double x41288 = x41285._1;;
                double x41289 = x41288 + 1.0;
                struct Anon189208763 x41290;
                x41290._0 = x41287;
                x41290._1 = x41289;
                struct Anon793459755 x41292;
                x41292.exists = true;
                x41292.key = x41283;
                x41292.aggs = x41290;
                x41293[x41291] = x41292;
                x41306 = false;
              } else {
                long x41296 = x41260;
                long x41297 = x41296 + 1L;
                long x41298 = x41297 & x823;
                x41260 = x41298;
                struct Anon793459755* x41300 = x41082;
                struct Anon793459755 x41301 = x41300[x41298];
                x41263 = x41301;
                x41306 = true;
              }
              x41319 = x41306;
            } else {
              long x41308 = x41260;
              struct Anon793459755* x41311 = x41082;
              x41311[x41308] = x41310;
              long x41313 = x41083;
              x41084[x41313] = x41308;
              x41083 = x41083 + 1L;
              x41319 = false;
            }
            if (!x41319) break;
          }
        }
      } else {
      }
    }
    long x41330 = x41083;
    long x41332;
    for(x41332=0L; x41332 < x41330; x41332++) {
      long x41333 = x41084[x41332];
      struct Anon793459755* x41334 = x41082;
      struct Anon793459755 x41335 = x41334[x41333];
      struct Anon189208763 x41336 = x41335.aggs;;
      double x41337 = x41336._0;;
      double x41338 = x41336._1;;
      double x41339 = x41337 / x41338;
      x41098 = x41339;
      printf("%s\n","begin scan CUSTOMER");
      for (;;) {
        bool x41343 = x41095;
        bool x41344 = !x41343;
        bool x41349 = x41344;
        if (x41344) {
          long x41345 = x41096;
          long x41346 = x40410;
          bool x41347 = x41345 < x41346;
          x41349 = x41347;
        }
        bool x41350 = x41349;
        if (!x41350) break;
        long x41352 = x41096;
        int* x41353 = x40412;
        int x41354 = x41353[x41352];
        char** x41361 = x40420;
        char* x41362 = x41361[x41352];
        double* x41363 = x40422;
        double x41364 = x41363[x41352];
        x41096 = x41096 + 1;
        double x41371 = x41098;
        bool x41373 = x41364 > x41371;
        bool x41393 = x41373;
        if (x41373) {
          bool x41374 = strncmp(x41362,"13", tpch_strlen("13")) == 0;;
          bool x41391 = x41374;
          if (x41374 == false) {
            bool x41375 = strncmp(x41362,"31", tpch_strlen("31")) == 0;;
            bool x41389 = x41375;
            if (x41375 == false) {
              bool x41376 = strncmp(x41362,"23", tpch_strlen("23")) == 0;;
              bool x41387 = x41376;
              if (x41376 == false) {
                bool x41377 = strncmp(x41362,"29", tpch_strlen("29")) == 0;;
                bool x41385 = x41377;
                if (x41377 == false) {
                  bool x41378 = strncmp(x41362,"30", tpch_strlen("30")) == 0;;
                  bool x41383 = x41378;
                  if (x41378 == false) {
                    bool x41379 = strncmp(x41362,"18", tpch_strlen("18")) == 0;;
                    bool x41381 = x41379;
                    if (x41379 == false) {
                      bool x41380 = strncmp(x41362,"17", tpch_strlen("17")) == 0;;
                      x41381 = x41380;
                    }
                    bool x41382 = x41381;
                    x41383 = x41382;
                  }
                  bool x41384 = x41383;
                  x41385 = x41384;
                }
                bool x41386 = x41385;
                x41387 = x41386;
              }
              bool x41388 = x41387;
              x41389 = x41388;
            }
            bool x41390 = x41389;
            x41391 = x41390;
          }
          bool x41392 = x41391;
          x41393 = x41392;
        }
        bool x41394 = x41393;
        if (x41394) {
          long x41397 = x41354 & x2212;
          long x41398 = x41123[x41397];
          long x41399 = x41398;
          bool x41400 = x41398 == -1L;
          bool x41401 = x41400;
          for (;;) {
            bool x41402 = x41401;
            bool x41403 = !x41402;
            if (!x41403) break;
            long x41405 = x41399;
            int* x41408 = x41107;
            int x41409 = x41408[x41405];
            bool x41425 = x41354 == x41409;
            if (x41425) {
              x41401 = true;
            } else {
              long x41428 = x41124[x41405];
              x41399 = x41428;
              bool x41430 = x41428 == -1;
              x41401 = x41430;
            }
          }
          long x41436 = x41399;
          bool x41437 = x41436 == -1;
          if (x41437) {
            char x41439 = x41362[1L];
            char x41438 = x41362[0L];
            long x41441 = x41438 * 41L;
            long x41442 = x41441 + x41439;
            long x41443 = x41442 & x823;
            long x41444 = x41443;
            struct Anon197582733* x41445 = x41131;
            struct Anon197582733 x41446 = x41445[x41443];
            struct Anon197582733 x41447 = x41446;
            bool x41448 = x41446.exists;;
            bool x41458 = x41448;
            if (x41448) {
              struct Anon197582733 x41449 = x41447;
              struct Anon310558733 x41450 = x41449.key;;
              char x41451 = x41450._0;;
              bool x41452 = x41451 == x41438;
              bool x41455 = x41452;
              if (x41452) {
                char x41453 = x41450._1;;
                bool x41454 = x41453 == x41439;
                x41455 = x41454;
              }
              bool x41456 = x41455;
              x41458 = x41456;
            }
            bool x41459 = x41458;
            if (x41459) {
              struct Anon189208763 x41460 = x41446.aggs;;
              struct Anon310558733 x41466 = x41446.key;;
              double x41461 = x41460._0;;
              double x41462 = x41364 + x41461;
              double x41463 = x41460._1;;
              double x41464 = x41463 + 1.0;
              struct Anon189208763 x41465;
              x41465._0 = x41462;
              x41465._1 = x41464;
              struct Anon197582733 x41467;
              x41467.exists = true;
              x41467.key = x41466;
              x41467.aggs = x41465;
              x41445[x41443] = x41467;
            } else {
              struct Anon310558733 x41440;
              x41440._0 = x41438;
              x41440._1 = x41439;
              struct Anon189208763 x41503;
              x41503._0 = x41364;
              x41503._1 = 1.0;
              struct Anon197582733 x41504;
              x41504.exists = true;
              x41504.key = x41440;
              x41504.aggs = x41503;
              for (;;) {
                struct Anon197582733 x41470 = x41447;
                bool x41471 = x41470.exists;;
                bool x41513;
                if (x41471) {
                  struct Anon310558733 x41472 = x41470.key;;
                  char x41473 = x41472._0;;
                  bool x41474 = x41473 == x41438;
                  bool x41477 = x41474;
                  if (x41474) {
                    char x41475 = x41472._1;;
                    bool x41476 = x41475 == x41439;
                    x41477 = x41476;
                  }
                  bool x41478 = x41477;
                  bool x41500;
                  if (x41478) {
                    struct Anon189208763 x41479 = x41470.aggs;;
                    long x41485 = x41444;
                    struct Anon197582733* x41487 = x41131;
                    double x41480 = x41479._0;;
                    double x41481 = x41364 + x41480;
                    double x41482 = x41479._1;;
                    double x41483 = x41482 + 1.0;
                    struct Anon189208763 x41484;
                    x41484._0 = x41481;
                    x41484._1 = x41483;
                    struct Anon197582733 x41486;
                    x41486.exists = true;
                    x41486.key = x41472;
                    x41486.aggs = x41484;
                    x41487[x41485] = x41486;
                    x41500 = false;
                  } else {
                    long x41490 = x41444;
                    long x41491 = x41490 + 1L;
                    long x41492 = x41491 & x823;
                    x41444 = x41492;
                    struct Anon197582733* x41494 = x41131;
                    struct Anon197582733 x41495 = x41494[x41492];
                    x41447 = x41495;
                    x41500 = true;
                  }
                  x41513 = x41500;
                } else {
                  long x41502 = x41444;
                  struct Anon197582733* x41505 = x41131;
                  x41505[x41502] = x41504;
                  long x41507 = x41132;
                  x41133[x41507] = x41502;
                  x41132 = x41132 + 1L;
                  x41513 = false;
                }
                if (!x41513) break;
              }
            }
          } else {
          }
        } else {
        }
      }
      x41096 = 0L;
    }
    long x41529 = x41132;
    long x41531;
    for(x41531=0L; x41531 < x41529; x41531++) {
      long x41532 = x41133[x41531];
      struct Anon197582733* x41533 = x41131;
      struct Anon197582733 x41534 = x41533[x41532];
      long x41535 = x41145;
      long x41536 = x41144;
      bool x41537 = x41535 == x41536;
      if (x41537) {
        long x41538 = x41536 * 4L;
        x41144 = x41538;
        struct Anon197582733* x41540 = x41147;
        struct Anon197582733* x41541 = (struct Anon197582733 *)realloc(x41540,x41538* sizeof(struct Anon197582733));
        x41147 = x41541;
      } else {
      }
      struct Anon197582733* x41545 = x41147;
      x41545[x41535] = x41534;
      x41145 = x41145 + 1;
    }
    long x41550 = x41145;
    struct Anon197582733* x41551 = x41147;
    qsort((void *)x41551,x41550,sizeof(struct Anon197582733), (__compar_fn_t)x41571); // x41572
    long x41574;
    for(x41574=0L; x41574 < x41550; x41574++) {
      struct Anon197582733* x41575 = x41147;
      struct Anon197582733 x41576 = x41575[x41574];
      if (x1043) {
      } else {
        struct Anon310558733 x41579 = x41576.key;;
        struct Anon189208763 x41582 = x41576.aggs;;
        char x41580 = x41579._0;;
        char x41581 = x41579._1;;
        double x41583 = x41582._1;;
        double x41584 = x41582._0;;
        printf("%c%c|%.0f|%.2f\n",x41580,x41581,x41583,x41584);
        x41149 = x41149 + 1L;
      }
    }
    long x41591 = x41149;
    printf("(%ld rows)\n",x41591);
    gettimeofday(&x41595, NULL);
    timeval_subtract(&x41596, &x41595, &x41594);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x41596.tv_sec * 1000) + (x41596.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
