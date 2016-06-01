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
int main(int x33864, char** x33865) {
  long x33866 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x33867 = x7;
  long x33868 = 0L;
  int* x33871 = (int*)malloc(x7 * sizeof(int));
  int* x33872 = x33871;
  double* x33877 = (double*)malloc(x7 * sizeof(double));
  double* x33878 = x33877;
  double* x33879 = (double*)malloc(x7 * sizeof(double));
  double* x33880 = x33879;
  double* x33881 = (double*)malloc(x7 * sizeof(double));
  double* x33882 = x33881;
  char** x33895 = (char**)malloc(x7 * sizeof(char*));
  char** x33896 = x33895;
  char** x33897 = (char**)malloc(x7 * sizeof(char*));
  char** x33898 = x33897;
  int x3 = open("XXXXXlineitem.tbl",0);
  long x4 = fsize(x3);
  char* x5 = mmap(0, x4, PROT_READ, MAP_FILE | MAP_SHARED, x3, 0);
  for (;;) {
    long x33901 = x33866;
    bool x33902 = x33901 < x4;
    if (!x33902) break;
    for (;;) {
      long x33906 = x33866;
      char x33907 = x5[x33906];
      bool x33908 = x33907 != '|';
      bool x33913 = x33908;
      if (x33908) {
        long x33909 = x33866;
        char x33910 = x5[x33909];
        bool x33911 = x33910 != '\n';
        x33913 = x33911;
      }
      bool x33914 = x33913;
      if (!x33914) break;
      x33866 = x33866 + 1;
    }
    x33866 = x33866 + 1;
    int x33929 = 0;
    for (;;) {
      long x33930 = x33866;
      char x33931 = x5[x33930];
      bool x33932 = x33931 != '|';
      bool x33937 = x33932;
      if (x33932) {
        long x33933 = x33866;
        char x33934 = x5[x33933];
        bool x33935 = x33934 != '\n';
        x33937 = x33935;
      }
      bool x33938 = x33937;
      if (!x33938) break;
      int x33940 = x33929;
      long x33942 = x33866;
      int x33941 = x33940 * 10;
      char x33943 = x5[x33942];
      char x33944 = x33943 - '0';
      int x33945 = x33941 + x33944;
      x33929 = x33945;
      x33866 = x33866 + 1;
    }
    x33866 = x33866 + 1;
    int x33951 = x33929;
    for (;;) {
      long x33954 = x33866;
      char x33955 = x5[x33954];
      bool x33956 = x33955 != '|';
      bool x33961 = x33956;
      if (x33956) {
        long x33957 = x33866;
        char x33958 = x5[x33957];
        bool x33959 = x33958 != '\n';
        x33961 = x33959;
      }
      bool x33962 = x33961;
      if (!x33962) break;
      x33866 = x33866 + 1;
    }
    x33866 = x33866 + 1;
    for (;;) {
      long x33978 = x33866;
      char x33979 = x5[x33978];
      bool x33980 = x33979 != '|';
      bool x33985 = x33980;
      if (x33980) {
        long x33981 = x33866;
        char x33982 = x5[x33981];
        bool x33983 = x33982 != '\n';
        x33985 = x33983;
      }
      bool x33986 = x33985;
      if (!x33986) break;
      x33866 = x33866 + 1;
    }
    x33866 = x33866 + 1;
    int x34001 = 0;
    int x34002 = 1;
    for (;;) {
      long x34003 = x33866;
      char x34004 = x5[x34003];
      bool x34005 = x34004 != '.';
      bool x34010 = x34005;
      if (x34005) {
        long x34006 = x33866;
        char x34007 = x5[x34006];
        bool x34008 = x34007 != '|';
        x34010 = x34008;
      }
      bool x34011 = x34010;
      bool x34016 = x34011;
      if (x34011) {
        long x34012 = x33866;
        char x34013 = x5[x34012];
        bool x34014 = x34013 != '\n';
        x34016 = x34014;
      }
      bool x34017 = x34016;
      if (!x34017) break;
      int x34019 = x34001;
      long x34021 = x33866;
      int x34020 = x34019 * 10;
      char x34022 = x5[x34021];
      char x34023 = x34022 - '0';
      int x34024 = x34020 + x34023;
      x34001 = x34024;
      x33866 = x33866 + 1;
    }
    long x34029 = x33866;
    char x34030 = x5[x34029];
    bool x34031 = x34030 == '.';
    if (x34031) {
      x33866 = x33866 + 1;
      for (;;) {
        long x34033 = x33866;
        char x34034 = x5[x34033];
        bool x34035 = x34034 != '|';
        bool x34040 = x34035;
        if (x34035) {
          long x34036 = x33866;
          char x34037 = x5[x34036];
          bool x34038 = x34037 != '\n';
          x34040 = x34038;
        }
        bool x34041 = x34040;
        if (!x34041) break;
        int x34043 = x34001;
        long x34045 = x33866;
        int x34044 = x34043 * 10;
        char x34046 = x5[x34045];
        char x34047 = x34046 - '0';
        int x34048 = x34044 + x34047;
        x34001 = x34048;
        int x34050 = x34002;
        int x34051 = x34050 * 10;
        x34002 = x34051;
        x33866 = x33866 + 1;
      }
    } else {
    }
    x33866 = x33866 + 1;
    int x34060 = x34001;
    int x34062 = x34002;
    int x34066 = 0;
    int x34067 = 1;
    for (;;) {
      long x34068 = x33866;
      char x34069 = x5[x34068];
      bool x34070 = x34069 != '.';
      bool x34075 = x34070;
      if (x34070) {
        long x34071 = x33866;
        char x34072 = x5[x34071];
        bool x34073 = x34072 != '|';
        x34075 = x34073;
      }
      bool x34076 = x34075;
      bool x34081 = x34076;
      if (x34076) {
        long x34077 = x33866;
        char x34078 = x5[x34077];
        bool x34079 = x34078 != '\n';
        x34081 = x34079;
      }
      bool x34082 = x34081;
      if (!x34082) break;
      int x34084 = x34066;
      long x34086 = x33866;
      int x34085 = x34084 * 10;
      char x34087 = x5[x34086];
      char x34088 = x34087 - '0';
      int x34089 = x34085 + x34088;
      x34066 = x34089;
      x33866 = x33866 + 1;
    }
    long x34094 = x33866;
    char x34095 = x5[x34094];
    bool x34096 = x34095 == '.';
    if (x34096) {
      x33866 = x33866 + 1;
      for (;;) {
        long x34098 = x33866;
        char x34099 = x5[x34098];
        bool x34100 = x34099 != '|';
        bool x34105 = x34100;
        if (x34100) {
          long x34101 = x33866;
          char x34102 = x5[x34101];
          bool x34103 = x34102 != '\n';
          x34105 = x34103;
        }
        bool x34106 = x34105;
        if (!x34106) break;
        int x34108 = x34066;
        long x34110 = x33866;
        int x34109 = x34108 * 10;
        char x34111 = x5[x34110];
        char x34112 = x34111 - '0';
        int x34113 = x34109 + x34112;
        x34066 = x34113;
        int x34115 = x34067;
        int x34116 = x34115 * 10;
        x34067 = x34116;
        x33866 = x33866 + 1;
      }
    } else {
    }
    x33866 = x33866 + 1;
    int x34125 = x34066;
    int x34127 = x34067;
    int x34131 = 0;
    int x34132 = 1;
    for (;;) {
      long x34133 = x33866;
      char x34134 = x5[x34133];
      bool x34135 = x34134 != '.';
      bool x34140 = x34135;
      if (x34135) {
        long x34136 = x33866;
        char x34137 = x5[x34136];
        bool x34138 = x34137 != '|';
        x34140 = x34138;
      }
      bool x34141 = x34140;
      bool x34146 = x34141;
      if (x34141) {
        long x34142 = x33866;
        char x34143 = x5[x34142];
        bool x34144 = x34143 != '\n';
        x34146 = x34144;
      }
      bool x34147 = x34146;
      if (!x34147) break;
      int x34149 = x34131;
      long x34151 = x33866;
      int x34150 = x34149 * 10;
      char x34152 = x5[x34151];
      char x34153 = x34152 - '0';
      int x34154 = x34150 + x34153;
      x34131 = x34154;
      x33866 = x33866 + 1;
    }
    long x34159 = x33866;
    char x34160 = x5[x34159];
    bool x34161 = x34160 == '.';
    if (x34161) {
      x33866 = x33866 + 1;
      for (;;) {
        long x34163 = x33866;
        char x34164 = x5[x34163];
        bool x34165 = x34164 != '|';
        bool x34170 = x34165;
        if (x34165) {
          long x34166 = x33866;
          char x34167 = x5[x34166];
          bool x34168 = x34167 != '\n';
          x34170 = x34168;
        }
        bool x34171 = x34170;
        if (!x34171) break;
        int x34173 = x34131;
        long x34175 = x33866;
        int x34174 = x34173 * 10;
        char x34176 = x5[x34175];
        char x34177 = x34176 - '0';
        int x34178 = x34174 + x34177;
        x34131 = x34178;
        int x34180 = x34132;
        int x34181 = x34180 * 10;
        x34132 = x34181;
        x33866 = x33866 + 1;
      }
    } else {
    }
    x33866 = x33866 + 1;
    int x34190 = x34131;
    int x34192 = x34132;
    for (;;) {
      long x34198 = x33866;
      char x34199 = x5[x34198];
      bool x34200 = x34199 != '.';
      bool x34205 = x34200;
      if (x34200) {
        long x34201 = x33866;
        char x34202 = x5[x34201];
        bool x34203 = x34202 != '|';
        x34205 = x34203;
      }
      bool x34206 = x34205;
      bool x34211 = x34206;
      if (x34206) {
        long x34207 = x33866;
        char x34208 = x5[x34207];
        bool x34209 = x34208 != '\n';
        x34211 = x34209;
      }
      bool x34212 = x34211;
      if (!x34212) break;
      x33866 = x33866 + 1;
    }
    long x34224 = x33866;
    char x34225 = x5[x34224];
    bool x34226 = x34225 == '.';
    if (x34226) {
      x33866 = x33866 + 1;
      for (;;) {
        long x34228 = x33866;
        char x34229 = x5[x34228];
        bool x34230 = x34229 != '|';
        bool x34235 = x34230;
        if (x34230) {
          long x34231 = x33866;
          char x34232 = x5[x34231];
          bool x34233 = x34232 != '\n';
          x34235 = x34233;
        }
        bool x34236 = x34235;
        if (!x34236) break;
        x33866 = x33866 + 1;
      }
    } else {
    }
    x33866 = x33866 + 1;
    x33866 = x33866 + 2;
    x33866 = x33866 + 2;
    for (;;) {
      long x34268 = x33866;
      char x34269 = x5[x34268];
      bool x34270 = x34269 != '-';
      bool x34275 = x34270;
      if (x34270) {
        long x34271 = x33866;
        char x34272 = x5[x34271];
        bool x34273 = x34272 != '\n';
        x34275 = x34273;
      }
      bool x34276 = x34275;
      if (!x34276) break;
      x33866 = x33866 + 1;
    }
    x33866 = x33866 + 1;
    for (;;) {
      long x34292 = x33866;
      char x34293 = x5[x34292];
      bool x34294 = x34293 != '-';
      bool x34299 = x34294;
      if (x34294) {
        long x34295 = x33866;
        char x34296 = x5[x34295];
        bool x34297 = x34296 != '\n';
        x34299 = x34297;
      }
      bool x34300 = x34299;
      if (!x34300) break;
      x33866 = x33866 + 1;
    }
    x33866 = x33866 + 1;
    for (;;) {
      long x34316 = x33866;
      char x34317 = x5[x34316];
      bool x34318 = x34317 != '|';
      bool x34323 = x34318;
      if (x34318) {
        long x34319 = x33866;
        char x34320 = x5[x34319];
        bool x34321 = x34320 != '\n';
        x34323 = x34321;
      }
      bool x34324 = x34323;
      if (!x34324) break;
      x33866 = x33866 + 1;
    }
    x33866 = x33866 + 1;
    for (;;) {
      long x34344 = x33866;
      char x34345 = x5[x34344];
      bool x34346 = x34345 != '-';
      bool x34351 = x34346;
      if (x34346) {
        long x34347 = x33866;
        char x34348 = x5[x34347];
        bool x34349 = x34348 != '\n';
        x34351 = x34349;
      }
      bool x34352 = x34351;
      if (!x34352) break;
      x33866 = x33866 + 1;
    }
    x33866 = x33866 + 1;
    for (;;) {
      long x34368 = x33866;
      char x34369 = x5[x34368];
      bool x34370 = x34369 != '-';
      bool x34375 = x34370;
      if (x34370) {
        long x34371 = x33866;
        char x34372 = x5[x34371];
        bool x34373 = x34372 != '\n';
        x34375 = x34373;
      }
      bool x34376 = x34375;
      if (!x34376) break;
      x33866 = x33866 + 1;
    }
    x33866 = x33866 + 1;
    for (;;) {
      long x34392 = x33866;
      char x34393 = x5[x34392];
      bool x34394 = x34393 != '|';
      bool x34399 = x34394;
      if (x34394) {
        long x34395 = x33866;
        char x34396 = x5[x34395];
        bool x34397 = x34396 != '\n';
        x34399 = x34397;
      }
      bool x34400 = x34399;
      if (!x34400) break;
      x33866 = x33866 + 1;
    }
    x33866 = x33866 + 1;
    for (;;) {
      long x34420 = x33866;
      char x34421 = x5[x34420];
      bool x34422 = x34421 != '-';
      bool x34427 = x34422;
      if (x34422) {
        long x34423 = x33866;
        char x34424 = x5[x34423];
        bool x34425 = x34424 != '\n';
        x34427 = x34425;
      }
      bool x34428 = x34427;
      if (!x34428) break;
      x33866 = x33866 + 1;
    }
    x33866 = x33866 + 1;
    for (;;) {
      long x34444 = x33866;
      char x34445 = x5[x34444];
      bool x34446 = x34445 != '-';
      bool x34451 = x34446;
      if (x34446) {
        long x34447 = x33866;
        char x34448 = x5[x34447];
        bool x34449 = x34448 != '\n';
        x34451 = x34449;
      }
      bool x34452 = x34451;
      if (!x34452) break;
      x33866 = x33866 + 1;
    }
    x33866 = x33866 + 1;
    for (;;) {
      long x34468 = x33866;
      char x34469 = x5[x34468];
      bool x34470 = x34469 != '|';
      bool x34475 = x34470;
      if (x34470) {
        long x34471 = x33866;
        char x34472 = x5[x34471];
        bool x34473 = x34472 != '\n';
        x34475 = x34473;
      }
      bool x34476 = x34475;
      if (!x34476) break;
      x33866 = x33866 + 1;
    }
    x33866 = x33866 + 1;
    long x34494 = x33866;
    for (;;) {
      long x34495 = x33866;
      char x34496 = x5[x34495];
      bool x34497 = x34496 != '|';
      bool x34502 = x34497;
      if (x34497) {
        long x34498 = x33866;
        char x34499 = x5[x34498];
        bool x34500 = x34499 != '\n';
        x34502 = x34500;
      }
      bool x34503 = x34502;
      if (!x34503) break;
      x33866 = x33866 + 1;
    }
    x33866 = x33866 + 1;
    long x34512 = x33866;
    for (;;) {
      long x34513 = x33866;
      char x34514 = x5[x34513];
      bool x34515 = x34514 != '|';
      bool x34520 = x34515;
      if (x34515) {
        long x34516 = x33866;
        char x34517 = x5[x34516];
        bool x34518 = x34517 != '\n';
        x34520 = x34518;
      }
      bool x34521 = x34520;
      if (!x34521) break;
      x33866 = x33866 + 1;
    }
    x33866 = x33866 + 1;
    for (;;) {
      long x34531 = x33866;
      char x34532 = x5[x34531];
      bool x34533 = x34532 != '|';
      bool x34538 = x34533;
      if (x34533) {
        long x34534 = x33866;
        char x34535 = x5[x34534];
        bool x34536 = x34535 != '\n';
        x34538 = x34536;
      }
      bool x34539 = x34538;
      if (!x34539) break;
      x33866 = x33866 + 1;
    }
    x33866 = x33866 + 1;
    long x34549 = x33866;
    bool x34550 = x34549 > 0L;
    bool x34556 = x34550;
    if (x34550) {
      long x34551 = x33866;
      long x34552 = x34551 - 1L;
      char x34553 = x5[x34552];
      bool x34554 = x34553 != '\n';
      x34556 = x34554;
    }
    bool x34557 = x34556;
    if (x34557) {
      for (;;) {
        long x34558 = x33866;
        char x34559 = x5[x34558];
        bool x34560 = x34559 != '\n';
        if (!x34560) break;
        x33866 = x33866 + 1;
      }
    } else {
    }
    x33866 = x33866 + 1;
    long x34569 = x33868;
    long x34570 = x33867;
    bool x34571 = x34569 == x34570;
    if (x34571) {
      long x34572 = x34570 * 4L;
      x33867 = x34572;
      printf("buffer.resize %ld\n",x34572);
      int* x34578 = x33872;
      int* x34579 = (int*)realloc(x34578,x34572 * sizeof(int));
      x33872 = x34579;
      double* x34587 = x33878;
      double* x34588 = (double*)realloc(x34587,x34572 * sizeof(double));
      x33878 = x34588;
      double* x34590 = x33880;
      double* x34591 = (double*)realloc(x34590,x34572 * sizeof(double));
      x33880 = x34591;
      double* x34593 = x33882;
      double* x34594 = (double*)realloc(x34593,x34572 * sizeof(double));
      x33882 = x34594;
      char** x34614 = x33896;
      char** x34615 = (char**)realloc(x34614,x34572 * sizeof(char*));
      x33896 = x34615;
      char** x34617 = x33898;
      char** x34618 = (char**)realloc(x34617,x34572 * sizeof(char*));
      x33898 = x34618;
    } else {
    }
    int* x34627 = x33872;
    x34627[x34569] = x33951;
    double* x34633 = x33878;
    double x34061 = (double)x34060;
    double x34063 = (double)x34062;
    double x34064 = x34061 / x34063;
    x34633[x34569] = x34064;
    double* x34635 = x33880;
    double x34126 = (double)x34125;
    double x34128 = (double)x34127;
    double x34129 = x34126 / x34128;
    x34635[x34569] = x34129;
    double* x34637 = x33882;
    double x34191 = (double)x34190;
    double x34193 = (double)x34192;
    double x34194 = x34191 / x34193;
    x34637[x34569] = x34194;
    char** x34651 = x33896;
    char* x34511 = x5+x34494;
    x34651[x34569] = x34511;
    char** x34653 = x33898;
    char* x34529 = x5+x34512;
    x34653[x34569] = x34529;
    x33868 = x33868 + 1;
  }
  long x34660 = 0L;
  long x34661 = x7;
  long x34662 = 0L;
  int* x34663 = (int*)malloc(x7 * sizeof(int));
  int* x34664 = x34663;
  char** x34669 = (char**)malloc(x7 * sizeof(char*));
  char** x34670 = x34669;
  int* x34673 = (int*)malloc(x7 * sizeof(int));
  int* x34674 = x34673;
  char** x34675 = (char**)malloc(x7 * sizeof(char*));
  char** x34676 = x34675;
  int x1076 = open("XXXXXpart.tbl",0);
  long x1077 = fsize(x1076);
  char* x1078 = mmap(0, x1077, PROT_READ, MAP_FILE | MAP_SHARED, x1076, 0);
  for (;;) {
    long x34682 = x34660;
    bool x34683 = x34682 < x1077;
    if (!x34683) break;
    int x34686 = 0;
    for (;;) {
      long x34687 = x34660;
      char x34688 = x1078[x34687];
      bool x34689 = x34688 != '|';
      bool x34694 = x34689;
      if (x34689) {
        long x34690 = x34660;
        char x34691 = x1078[x34690];
        bool x34692 = x34691 != '\n';
        x34694 = x34692;
      }
      bool x34695 = x34694;
      if (!x34695) break;
      int x34697 = x34686;
      long x34699 = x34660;
      int x34698 = x34697 * 10;
      char x34700 = x1078[x34699];
      char x34701 = x34700 - '0';
      int x34702 = x34698 + x34701;
      x34686 = x34702;
      x34660 = x34660 + 1;
    }
    x34660 = x34660 + 1;
    int x34708 = x34686;
    for (;;) {
      long x34710 = x34660;
      char x34711 = x1078[x34710];
      bool x34712 = x34711 != '|';
      bool x34717 = x34712;
      if (x34712) {
        long x34713 = x34660;
        char x34714 = x1078[x34713];
        bool x34715 = x34714 != '\n';
        x34717 = x34715;
      }
      bool x34718 = x34717;
      if (!x34718) break;
      x34660 = x34660 + 1;
    }
    x34660 = x34660 + 1;
    for (;;) {
      long x34728 = x34660;
      char x34729 = x1078[x34728];
      bool x34730 = x34729 != '|';
      bool x34735 = x34730;
      if (x34730) {
        long x34731 = x34660;
        char x34732 = x1078[x34731];
        bool x34733 = x34732 != '\n';
        x34735 = x34733;
      }
      bool x34736 = x34735;
      if (!x34736) break;
      x34660 = x34660 + 1;
    }
    x34660 = x34660 + 1;
    long x34745 = x34660;
    for (;;) {
      long x34746 = x34660;
      char x34747 = x1078[x34746];
      bool x34748 = x34747 != '|';
      bool x34753 = x34748;
      if (x34748) {
        long x34749 = x34660;
        char x34750 = x1078[x34749];
        bool x34751 = x34750 != '\n';
        x34753 = x34751;
      }
      bool x34754 = x34753;
      if (!x34754) break;
      x34660 = x34660 + 1;
    }
    x34660 = x34660 + 1;
    for (;;) {
      long x34764 = x34660;
      char x34765 = x1078[x34764];
      bool x34766 = x34765 != '|';
      bool x34771 = x34766;
      if (x34766) {
        long x34767 = x34660;
        char x34768 = x1078[x34767];
        bool x34769 = x34768 != '\n';
        x34771 = x34769;
      }
      bool x34772 = x34771;
      if (!x34772) break;
      x34660 = x34660 + 1;
    }
    x34660 = x34660 + 1;
    int x34782 = 0;
    for (;;) {
      long x34783 = x34660;
      char x34784 = x1078[x34783];
      bool x34785 = x34784 != '|';
      bool x34790 = x34785;
      if (x34785) {
        long x34786 = x34660;
        char x34787 = x1078[x34786];
        bool x34788 = x34787 != '\n';
        x34790 = x34788;
      }
      bool x34791 = x34790;
      if (!x34791) break;
      int x34793 = x34782;
      long x34795 = x34660;
      int x34794 = x34793 * 10;
      char x34796 = x1078[x34795];
      char x34797 = x34796 - '0';
      int x34798 = x34794 + x34797;
      x34782 = x34798;
      x34660 = x34660 + 1;
    }
    x34660 = x34660 + 1;
    int x34804 = x34782;
    long x34805 = x34660;
    for (;;) {
      long x34806 = x34660;
      char x34807 = x1078[x34806];
      bool x34808 = x34807 != '|';
      bool x34813 = x34808;
      if (x34808) {
        long x34809 = x34660;
        char x34810 = x1078[x34809];
        bool x34811 = x34810 != '\n';
        x34813 = x34811;
      }
      bool x34814 = x34813;
      if (!x34814) break;
      x34660 = x34660 + 1;
    }
    x34660 = x34660 + 1;
    for (;;) {
      long x34826 = x34660;
      char x34827 = x1078[x34826];
      bool x34828 = x34827 != '.';
      bool x34833 = x34828;
      if (x34828) {
        long x34829 = x34660;
        char x34830 = x1078[x34829];
        bool x34831 = x34830 != '|';
        x34833 = x34831;
      }
      bool x34834 = x34833;
      bool x34839 = x34834;
      if (x34834) {
        long x34835 = x34660;
        char x34836 = x1078[x34835];
        bool x34837 = x34836 != '\n';
        x34839 = x34837;
      }
      bool x34840 = x34839;
      if (!x34840) break;
      x34660 = x34660 + 1;
    }
    long x34852 = x34660;
    char x34853 = x1078[x34852];
    bool x34854 = x34853 == '.';
    if (x34854) {
      x34660 = x34660 + 1;
      for (;;) {
        long x34856 = x34660;
        char x34857 = x1078[x34856];
        bool x34858 = x34857 != '|';
        bool x34863 = x34858;
        if (x34858) {
          long x34859 = x34660;
          char x34860 = x1078[x34859];
          bool x34861 = x34860 != '\n';
          x34863 = x34861;
        }
        bool x34864 = x34863;
        if (!x34864) break;
        x34660 = x34660 + 1;
      }
    } else {
    }
    x34660 = x34660 + 1;
    for (;;) {
      long x34889 = x34660;
      char x34890 = x1078[x34889];
      bool x34891 = x34890 != '|';
      bool x34896 = x34891;
      if (x34891) {
        long x34892 = x34660;
        char x34893 = x1078[x34892];
        bool x34894 = x34893 != '\n';
        x34896 = x34894;
      }
      bool x34897 = x34896;
      if (!x34897) break;
      x34660 = x34660 + 1;
    }
    x34660 = x34660 + 1;
    long x34907 = x34660;
    bool x34908 = x34907 > 0L;
    bool x34914 = x34908;
    if (x34908) {
      long x34909 = x34660;
      long x34910 = x34909 - 1L;
      char x34911 = x1078[x34910];
      bool x34912 = x34911 != '\n';
      x34914 = x34912;
    }
    bool x34915 = x34914;
    if (x34915) {
      for (;;) {
        long x34916 = x34660;
        char x34917 = x1078[x34916];
        bool x34918 = x34917 != '\n';
        if (!x34918) break;
        x34660 = x34660 + 1;
      }
    } else {
    }
    x34660 = x34660 + 1;
    long x34927 = x34662;
    long x34928 = x34661;
    bool x34929 = x34927 == x34928;
    if (x34929) {
      long x34930 = x34928 * 4L;
      x34661 = x34930;
      printf("buffer.resize %ld\n",x34930);
      int* x34933 = x34664;
      int* x34934 = (int*)realloc(x34933,x34930 * sizeof(int));
      x34664 = x34934;
      char** x34942 = x34670;
      char** x34943 = (char**)realloc(x34942,x34930 * sizeof(char*));
      x34670 = x34943;
      int* x34948 = x34674;
      int* x34949 = (int*)realloc(x34948,x34930 * sizeof(int));
      x34674 = x34949;
      char** x34951 = x34676;
      char** x34952 = (char**)realloc(x34951,x34930 * sizeof(char*));
      x34676 = x34952;
    } else {
    }
    int* x34962 = x34664;
    x34962[x34927] = x34708;
    char** x34968 = x34670;
    char* x34762 = x1078+x34745;
    x34968[x34927] = x34762;
    int* x34972 = x34674;
    x34972[x34927] = x34804;
    char** x34974 = x34676;
    char* x34822 = x1078+x34805;
    x34974[x34927] = x34822;
    x34662 = x34662 + 1;
  }
  long x2189 = DEFAULT_JOIN_HASH_SIZE;
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  long x2212 = x2189 - 1L;
  float x35193 = (float)30;
  double x35194 = (double)x35193;
  float x35196 = (float)1;
  double x35197 = (double)x35196;
  float x35257 = (float)11;
  double x35258 = (double)x35257;
  float x35278 = (float)10;
  double x35279 = (double)x35278;
  float x35283 = (float)20;
  double x35284 = (double)x35283;
  long x823 = x808 - 1L;
  bool x1043 = true == false;
  int x34983;
  for(x34983=0; x34983 < 5; x34983++) {
    bool x34984 = false;
    long x34985 = 0L;
    bool x34987 = false;
    long x34988 = 0L;
    int* x34991 = (int*)malloc(x2189 * sizeof(int));
    int* x34992 = x34991;
    char** x34997 = (char**)malloc(x2189 * sizeof(char*));
    char** x34998 = x34997;
    int* x35001 = (int*)malloc(x2189 * sizeof(int));
    int* x35002 = x35001;
    char** x35003 = (char**)malloc(x2189 * sizeof(char*));
    char** x35004 = x35003;
    long x35009 = 0L;
    long* x35010 = (long*)malloc(x2189 * sizeof(long));
    long* x35011 = (long*)malloc(x2189 * sizeof(long));
    long x35012;
    for(x35012=0L; x35012 < x2189; x35012++) {
      x35010[x35012] = -1L;
    }
    struct Anon603726677* x35019 = (struct Anon603726677*)malloc(x808 * sizeof(struct Anon603726677));
    struct Anon603726677* x35020 = x35019;
    long x35021 = 0L;
    long* x35022 = (long*)malloc(x808 * sizeof(long));
    long x35023;
    for(x35023=0L; x35023 < x808; x35023++) {
      struct Anon603726677* x35024 = x35020;
      struct Anon603726677 x35025 = x35024[x35023];
      char* x35026 = x35025.key;;
      double x35027 = x35025.aggs;;
      struct Anon603726677 x35028;
      x35028.exists = false;
      x35028.key = x35026;
      x35028.aggs = x35027;
      x35024[x35023] = x35028;
    }
    long x35033 = 0L;
    struct timeval x35405, x35406, x35407;
    gettimeofday(&x35405, NULL);
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x35035 = x34984;
      bool x35036 = !x35035;
      bool x35041 = x35036;
      if (x35036) {
        long x35037 = x34985;
        long x35038 = x34662;
        bool x35039 = x35037 < x35038;
        x35041 = x35039;
      }
      bool x35042 = x35041;
      if (!x35042) break;
      long x35044 = x34985;
      int* x35045 = x34664;
      int x35046 = x35045[x35044];
      char** x35051 = x34670;
      char* x35052 = x35051[x35044];
      int* x35055 = x34674;
      int x35056 = x35055[x35044];
      char** x35057 = x34676;
      char* x35058 = x35057[x35044];
      x34985 = x34985 + 1;
      bool x35065 = x35056 >= 1;
      bool x35118 = x35065;
      if (x35065) {
        bool x35066 = x35056 <= 5;
        bool x35068 = x35066;
        if (x35066) {
          bool x35067 = tpch_strcmp(x35052,"Brand#12") == 0;;
          x35068 = x35067;
        }
        bool x35069 = x35068;
        bool x35080 = x35069;
        if (x35069) {
          bool x35070 = tpch_strcmp(x35058,"SM BOX") == 0;;
          bool x35072 = x35070;
          if (x35070 == false) {
            bool x35071 = tpch_strcmp(x35058,"SM CASE") == 0;;
            x35072 = x35071;
          }
          bool x35073 = x35072;
          bool x35075 = x35073;
          if (x35073 == false) {
            bool x35074 = tpch_strcmp(x35058,"SM PACK") == 0;;
            x35075 = x35074;
          }
          bool x35076 = x35075;
          bool x35078 = x35076;
          if (x35076 == false) {
            bool x35077 = tpch_strcmp(x35058,"SM PKG") == 0;;
            x35078 = x35077;
          }
          bool x35079 = x35078;
          x35080 = x35079;
        }
        bool x35081 = x35080;
        bool x35098 = x35081;
        if (x35081 == false) {
          bool x35082 = x35056 <= 10;
          bool x35084 = x35082;
          if (x35082) {
            bool x35083 = tpch_strcmp(x35052,"Brand#23") == 0;;
            x35084 = x35083;
          }
          bool x35085 = x35084;
          bool x35096 = x35085;
          if (x35085) {
            bool x35086 = tpch_strcmp(x35058,"MED BAG") == 0;;
            bool x35088 = x35086;
            if (x35086 == false) {
              bool x35087 = tpch_strcmp(x35058,"MED BOX") == 0;;
              x35088 = x35087;
            }
            bool x35089 = x35088;
            bool x35091 = x35089;
            if (x35089 == false) {
              bool x35090 = tpch_strcmp(x35058,"MED PACK") == 0;;
              x35091 = x35090;
            }
            bool x35092 = x35091;
            bool x35094 = x35092;
            if (x35092 == false) {
              bool x35093 = tpch_strcmp(x35058,"MED PKG") == 0;;
              x35094 = x35093;
            }
            bool x35095 = x35094;
            x35096 = x35095;
          }
          bool x35097 = x35096;
          x35098 = x35097;
        }
        bool x35099 = x35098;
        bool x35116 = x35099;
        if (x35099 == false) {
          bool x35100 = x35056 <= 15;
          bool x35102 = x35100;
          if (x35100) {
            bool x35101 = tpch_strcmp(x35052,"Brand#34") == 0;;
            x35102 = x35101;
          }
          bool x35103 = x35102;
          bool x35114 = x35103;
          if (x35103) {
            bool x35104 = tpch_strcmp(x35058,"LG BOX") == 0;;
            bool x35106 = x35104;
            if (x35104 == false) {
              bool x35105 = tpch_strcmp(x35058,"LG CASE") == 0;;
              x35106 = x35105;
            }
            bool x35107 = x35106;
            bool x35109 = x35107;
            if (x35107 == false) {
              bool x35108 = tpch_strcmp(x35058,"LG PACK") == 0;;
              x35109 = x35108;
            }
            bool x35110 = x35109;
            bool x35112 = x35110;
            if (x35110 == false) {
              bool x35111 = tpch_strcmp(x35058,"LG PKG") == 0;;
              x35112 = x35111;
            }
            bool x35113 = x35112;
            x35114 = x35113;
          }
          bool x35115 = x35114;
          x35116 = x35115;
        }
        bool x35117 = x35116;
        x35118 = x35117;
      }
      bool x35119 = x35118;
      if (x35119) {
        long x35120 = x35009;
        int* x35121 = x34992;
        x35121[x35120] = x35046;
        char** x35127 = x34998;
        x35127[x35120] = x35052;
        int* x35131 = x35002;
        x35131[x35120] = x35056;
        char** x35133 = x35004;
        x35133[x35120] = x35058;
        x35009 = x35009 + 1L;
        long x35140 = x35046 & x2212;
        long x35141 = x35010[x35140];
        x35010[x35140] = x35120;
        x35011[x35120] = x35141;
      } else {
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x35149 = x34987;
      bool x35150 = !x35149;
      bool x35155 = x35150;
      if (x35150) {
        long x35151 = x34988;
        long x35152 = x33868;
        bool x35153 = x35151 < x35152;
        x35155 = x35153;
      }
      bool x35156 = x35155;
      if (!x35156) break;
      long x35158 = x34988;
      int* x35161 = x33872;
      int x35162 = x35161[x35158];
      double* x35167 = x33878;
      double x35168 = x35167[x35158];
      double* x35169 = x33880;
      double x35170 = x35169[x35158];
      double* x35171 = x33882;
      double x35172 = x35171[x35158];
      char** x35185 = x33896;
      char* x35186 = x35185[x35158];
      char** x35187 = x33898;
      char* x35188 = x35187[x35158];
      x34988 = x34988 + 1;
      bool x35195 = x35168 <= x35194;
      bool x35198 = x35168 >= x35197;
      bool x35199 = x35195;
      if (x35195) {
        x35199 = x35198;
      }
      bool x35200 = x35199;
      bool x35202 = x35200;
      if (x35200) {
        bool x35201 = tpch_strcmp(x35186,"DELIVER IN PERSON") == 0;;
        x35202 = x35201;
      }
      bool x35203 = x35202;
      bool x35208 = x35203;
      if (x35203) {
        bool x35204 = tpch_strcmp(x35188,"AIR") == 0;;
        bool x35206 = x35204;
        if (x35204 == false) {
          bool x35205 = tpch_strcmp(x35188,"AIR REG") == 0;;
          x35206 = x35205;
        }
        bool x35207 = x35206;
        x35208 = x35207;
      }
      bool x35209 = x35208;
      if (x35209) {
        long x35210 = x35162 & x2212;
        long x35211 = x35010[x35210];
        long x35212 = x35211;
        bool x35259 = x35168 <= x35258;
        bool x35280 = x35168 >= x35279;
        bool x35285 = x35168 <= x35284;
        bool x35306 = x35168 >= x35284;
        double x35330 = 1.0 - x35172;
        double x35331 = x35170 * x35330;
        struct Anon603726677 x35361;
        x35361.exists = true;
        x35361.key = "Total";
        x35361.aggs = x35331;
        for (;;) {
          long x35213 = x35212;
          bool x35214 = x35213 != -1;
          if (!x35214) break;
          long x35216 = x35212;
          int* x35217 = x34992;
          int x35218 = x35217[x35216];
          char** x35223 = x34998;
          char* x35224 = x35223[x35216];
          int* x35227 = x35002;
          int x35228 = x35227[x35216];
          char** x35229 = x35004;
          char* x35230 = x35229[x35216];
          long x35236 = x35011[x35216];
          x35212 = x35236;
          bool x35238 = x35218 == x35162;
          if (x35238) {
            bool x35242 = tpch_strcmp(x35224,"Brand#12") == 0;;
            bool x35253 = x35242;
            if (x35242) {
              bool x35243 = tpch_strcmp(x35230,"SM BOX") == 0;;
              bool x35245 = x35243;
              if (x35243 == false) {
                bool x35244 = tpch_strcmp(x35230,"SM CASE") == 0;;
                x35245 = x35244;
              }
              bool x35246 = x35245;
              bool x35248 = x35246;
              if (x35246 == false) {
                bool x35247 = tpch_strcmp(x35230,"SM PACK") == 0;;
                x35248 = x35247;
              }
              bool x35249 = x35248;
              bool x35251 = x35249;
              if (x35249 == false) {
                bool x35250 = tpch_strcmp(x35230,"SM PKG") == 0;;
                x35251 = x35250;
              }
              bool x35252 = x35251;
              x35253 = x35252;
            }
            bool x35254 = x35253;
            bool x35255 = x35254;
            if (x35254) {
              x35255 = x35198;
            }
            bool x35256 = x35255;
            bool x35260 = x35256;
            if (x35256) {
              x35260 = x35259;
            }
            bool x35261 = x35260;
            bool x35263 = x35261;
            if (x35261) {
              bool x35262 = x35228 <= 5;
              x35263 = x35262;
            }
            bool x35264 = x35263;
            bool x35291 = x35264;
            if (x35264 == false) {
              bool x35265 = tpch_strcmp(x35224,"Brand#23") == 0;;
              bool x35276 = x35265;
              if (x35265) {
                bool x35266 = tpch_strcmp(x35230,"MED BAG") == 0;;
                bool x35268 = x35266;
                if (x35266 == false) {
                  bool x35267 = tpch_strcmp(x35230,"MED BOX") == 0;;
                  x35268 = x35267;
                }
                bool x35269 = x35268;
                bool x35271 = x35269;
                if (x35269 == false) {
                  bool x35270 = tpch_strcmp(x35230,"MED PACK") == 0;;
                  x35271 = x35270;
                }
                bool x35272 = x35271;
                bool x35274 = x35272;
                if (x35272 == false) {
                  bool x35273 = tpch_strcmp(x35230,"MED PKG") == 0;;
                  x35274 = x35273;
                }
                bool x35275 = x35274;
                x35276 = x35275;
              }
              bool x35277 = x35276;
              bool x35281 = x35277;
              if (x35277) {
                x35281 = x35280;
              }
              bool x35282 = x35281;
              bool x35286 = x35282;
              if (x35282) {
                x35286 = x35285;
              }
              bool x35287 = x35286;
              bool x35289 = x35287;
              if (x35287) {
                bool x35288 = x35228 <= 10;
                x35289 = x35288;
              }
              bool x35290 = x35289;
              x35291 = x35290;
            }
            bool x35292 = x35291;
            bool x35314 = x35292;
            if (x35292 == false) {
              bool x35293 = tpch_strcmp(x35224,"Brand#34") == 0;;
              bool x35304 = x35293;
              if (x35293) {
                bool x35294 = tpch_strcmp(x35230,"LG BOX") == 0;;
                bool x35296 = x35294;
                if (x35294 == false) {
                  bool x35295 = tpch_strcmp(x35230,"LG CASE") == 0;;
                  x35296 = x35295;
                }
                bool x35297 = x35296;
                bool x35299 = x35297;
                if (x35297 == false) {
                  bool x35298 = tpch_strcmp(x35230,"LG PACK") == 0;;
                  x35299 = x35298;
                }
                bool x35300 = x35299;
                bool x35302 = x35300;
                if (x35300 == false) {
                  bool x35301 = tpch_strcmp(x35230,"LG PKG") == 0;;
                  x35302 = x35301;
                }
                bool x35303 = x35302;
                x35304 = x35303;
              }
              bool x35305 = x35304;
              bool x35307 = x35305;
              if (x35305) {
                x35307 = x35306;
              }
              bool x35308 = x35307;
              bool x35309 = x35308;
              if (x35308) {
                x35309 = x35195;
              }
              bool x35310 = x35309;
              bool x35312 = x35310;
              if (x35310) {
                bool x35311 = x35228 <= 15;
                x35312 = x35311;
              }
              bool x35313 = x35312;
              x35314 = x35313;
            }
            bool x35315 = x35314;
            if (x35315) {
              long x35316 = hash("Total", 10L);
              long x35317 = x35316 & x823;
              long x35318 = x35317;
              struct Anon603726677* x35319 = x35020;
              struct Anon603726677 x35320 = x35319[x35317];
              struct Anon603726677 x35321 = x35320;
              bool x35322 = x35320.exists;;
              bool x35327 = x35322;
              if (x35322) {
                struct Anon603726677 x35323 = x35321;
                char* x35324 = x35323.key;;
                bool x35325 = tpch_strcmp(x35324,"Total") == 0;;
                x35327 = x35325;
              }
              bool x35328 = x35327;
              if (x35328) {
                double x35329 = x35320.aggs;;
                char* x35333 = x35320.key;;
                double x35332 = x35329 + x35331;
                struct Anon603726677 x35334;
                x35334.exists = true;
                x35334.key = x35333;
                x35334.aggs = x35332;
                x35319[x35317] = x35334;
              } else {
                for (;;) {
                  struct Anon603726677 x35337 = x35321;
                  bool x35338 = x35337.exists;;
                  bool x35370;
                  if (x35338) {
                    char* x35339 = x35337.key;;
                    bool x35340 = tpch_strcmp(x35339,"Total") == 0;;
                    bool x35358;
                    if (x35340) {
                      double x35341 = x35337.aggs;;
                      long x35343 = x35318;
                      struct Anon603726677* x35345 = x35020;
                      double x35342 = x35341 + x35331;
                      struct Anon603726677 x35344;
                      x35344.exists = true;
                      x35344.key = x35339;
                      x35344.aggs = x35342;
                      x35345[x35343] = x35344;
                      x35358 = false;
                    } else {
                      long x35348 = x35318;
                      long x35349 = x35348 + 1L;
                      long x35350 = x35349 & x823;
                      x35318 = x35350;
                      struct Anon603726677* x35352 = x35020;
                      struct Anon603726677 x35353 = x35352[x35350];
                      x35321 = x35353;
                      x35358 = true;
                    }
                    x35370 = x35358;
                  } else {
                    long x35360 = x35318;
                    struct Anon603726677* x35362 = x35020;
                    x35362[x35360] = x35361;
                    long x35364 = x35021;
                    x35022[x35364] = x35360;
                    x35021 = x35021 + 1L;
                    x35370 = false;
                  }
                  if (!x35370) break;
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
    long x35387 = x35021;
    long x35389;
    for(x35389=0L; x35389 < x35387; x35389++) {
      long x35390 = x35022[x35389];
      struct Anon603726677* x35391 = x35020;
      struct Anon603726677 x35392 = x35391[x35390];
      if (x1043) {
      } else {
        double x35395 = x35392.aggs;;
        printf("%.4f\n",x35395);
        x35033 = x35033 + 1L;
      }
    }
    long x35402 = x35033;
    printf("(%ld rows)\n",x35402);
    gettimeofday(&x35406, NULL);
    timeval_subtract(&x35407, &x35406, &x35405);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x35407.tv_sec * 1000) + (x35407.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
