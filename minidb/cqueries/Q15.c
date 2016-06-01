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

struct Anon1268892766 {
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
};

struct Anon592699416 {
int key;
struct Anon2052879266 aggs;
};

struct Anon0 {
struct Anon1268892766 left;
struct Anon592699416 right;
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
int main(int x27062, char** x27063) {
  long x27064 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x27065 = x7;
  long x27066 = 0L;
  int* x27071 = (int*)malloc(x7 * sizeof(int));
  int* x27072 = x27071;
  double* x27077 = (double*)malloc(x7 * sizeof(double));
  double* x27078 = x27077;
  double* x27079 = (double*)malloc(x7 * sizeof(double));
  double* x27080 = x27079;
  long* x27087 = (long*)malloc(x7 * sizeof(long));
  long* x27088 = x27087;
  int x3 = open("XXXXXlineitem.tbl",0);
  long x4 = fsize(x3);
  char* x5 = mmap(0, x4, PROT_READ, MAP_FILE | MAP_SHARED, x3, 0);
  for (;;) {
    long x27099 = x27064;
    bool x27100 = x27099 < x4;
    if (!x27100) break;
    for (;;) {
      long x27104 = x27064;
      char x27105 = x5[x27104];
      bool x27106 = x27105 != '|';
      bool x27111 = x27106;
      if (x27106) {
        long x27107 = x27064;
        char x27108 = x5[x27107];
        bool x27109 = x27108 != '\n';
        x27111 = x27109;
      }
      bool x27112 = x27111;
      if (!x27112) break;
      x27064 = x27064 + 1;
    }
    x27064 = x27064 + 1;
    for (;;) {
      long x27128 = x27064;
      char x27129 = x5[x27128];
      bool x27130 = x27129 != '|';
      bool x27135 = x27130;
      if (x27130) {
        long x27131 = x27064;
        char x27132 = x5[x27131];
        bool x27133 = x27132 != '\n';
        x27135 = x27133;
      }
      bool x27136 = x27135;
      if (!x27136) break;
      x27064 = x27064 + 1;
    }
    x27064 = x27064 + 1;
    int x27151 = 0;
    for (;;) {
      long x27152 = x27064;
      char x27153 = x5[x27152];
      bool x27154 = x27153 != '|';
      bool x27159 = x27154;
      if (x27154) {
        long x27155 = x27064;
        char x27156 = x5[x27155];
        bool x27157 = x27156 != '\n';
        x27159 = x27157;
      }
      bool x27160 = x27159;
      if (!x27160) break;
      int x27162 = x27151;
      long x27164 = x27064;
      int x27163 = x27162 * 10;
      char x27165 = x5[x27164];
      char x27166 = x27165 - '0';
      int x27167 = x27163 + x27166;
      x27151 = x27167;
      x27064 = x27064 + 1;
    }
    x27064 = x27064 + 1;
    int x27173 = x27151;
    for (;;) {
      long x27176 = x27064;
      char x27177 = x5[x27176];
      bool x27178 = x27177 != '|';
      bool x27183 = x27178;
      if (x27178) {
        long x27179 = x27064;
        char x27180 = x5[x27179];
        bool x27181 = x27180 != '\n';
        x27183 = x27181;
      }
      bool x27184 = x27183;
      if (!x27184) break;
      x27064 = x27064 + 1;
    }
    x27064 = x27064 + 1;
    for (;;) {
      long x27201 = x27064;
      char x27202 = x5[x27201];
      bool x27203 = x27202 != '.';
      bool x27208 = x27203;
      if (x27203) {
        long x27204 = x27064;
        char x27205 = x5[x27204];
        bool x27206 = x27205 != '|';
        x27208 = x27206;
      }
      bool x27209 = x27208;
      bool x27214 = x27209;
      if (x27209) {
        long x27210 = x27064;
        char x27211 = x5[x27210];
        bool x27212 = x27211 != '\n';
        x27214 = x27212;
      }
      bool x27215 = x27214;
      if (!x27215) break;
      x27064 = x27064 + 1;
    }
    long x27227 = x27064;
    char x27228 = x5[x27227];
    bool x27229 = x27228 == '.';
    if (x27229) {
      x27064 = x27064 + 1;
      for (;;) {
        long x27231 = x27064;
        char x27232 = x5[x27231];
        bool x27233 = x27232 != '|';
        bool x27238 = x27233;
        if (x27233) {
          long x27234 = x27064;
          char x27235 = x5[x27234];
          bool x27236 = x27235 != '\n';
          x27238 = x27236;
        }
        bool x27239 = x27238;
        if (!x27239) break;
        x27064 = x27064 + 1;
      }
    } else {
    }
    x27064 = x27064 + 1;
    int x27264 = 0;
    int x27265 = 1;
    for (;;) {
      long x27266 = x27064;
      char x27267 = x5[x27266];
      bool x27268 = x27267 != '.';
      bool x27273 = x27268;
      if (x27268) {
        long x27269 = x27064;
        char x27270 = x5[x27269];
        bool x27271 = x27270 != '|';
        x27273 = x27271;
      }
      bool x27274 = x27273;
      bool x27279 = x27274;
      if (x27274) {
        long x27275 = x27064;
        char x27276 = x5[x27275];
        bool x27277 = x27276 != '\n';
        x27279 = x27277;
      }
      bool x27280 = x27279;
      if (!x27280) break;
      int x27282 = x27264;
      long x27284 = x27064;
      int x27283 = x27282 * 10;
      char x27285 = x5[x27284];
      char x27286 = x27285 - '0';
      int x27287 = x27283 + x27286;
      x27264 = x27287;
      x27064 = x27064 + 1;
    }
    long x27292 = x27064;
    char x27293 = x5[x27292];
    bool x27294 = x27293 == '.';
    if (x27294) {
      x27064 = x27064 + 1;
      for (;;) {
        long x27296 = x27064;
        char x27297 = x5[x27296];
        bool x27298 = x27297 != '|';
        bool x27303 = x27298;
        if (x27298) {
          long x27299 = x27064;
          char x27300 = x5[x27299];
          bool x27301 = x27300 != '\n';
          x27303 = x27301;
        }
        bool x27304 = x27303;
        if (!x27304) break;
        int x27306 = x27264;
        long x27308 = x27064;
        int x27307 = x27306 * 10;
        char x27309 = x5[x27308];
        char x27310 = x27309 - '0';
        int x27311 = x27307 + x27310;
        x27264 = x27311;
        int x27313 = x27265;
        int x27314 = x27313 * 10;
        x27265 = x27314;
        x27064 = x27064 + 1;
      }
    } else {
    }
    x27064 = x27064 + 1;
    int x27323 = x27264;
    int x27325 = x27265;
    int x27329 = 0;
    int x27330 = 1;
    for (;;) {
      long x27331 = x27064;
      char x27332 = x5[x27331];
      bool x27333 = x27332 != '.';
      bool x27338 = x27333;
      if (x27333) {
        long x27334 = x27064;
        char x27335 = x5[x27334];
        bool x27336 = x27335 != '|';
        x27338 = x27336;
      }
      bool x27339 = x27338;
      bool x27344 = x27339;
      if (x27339) {
        long x27340 = x27064;
        char x27341 = x5[x27340];
        bool x27342 = x27341 != '\n';
        x27344 = x27342;
      }
      bool x27345 = x27344;
      if (!x27345) break;
      int x27347 = x27329;
      long x27349 = x27064;
      int x27348 = x27347 * 10;
      char x27350 = x5[x27349];
      char x27351 = x27350 - '0';
      int x27352 = x27348 + x27351;
      x27329 = x27352;
      x27064 = x27064 + 1;
    }
    long x27357 = x27064;
    char x27358 = x5[x27357];
    bool x27359 = x27358 == '.';
    if (x27359) {
      x27064 = x27064 + 1;
      for (;;) {
        long x27361 = x27064;
        char x27362 = x5[x27361];
        bool x27363 = x27362 != '|';
        bool x27368 = x27363;
        if (x27363) {
          long x27364 = x27064;
          char x27365 = x5[x27364];
          bool x27366 = x27365 != '\n';
          x27368 = x27366;
        }
        bool x27369 = x27368;
        if (!x27369) break;
        int x27371 = x27329;
        long x27373 = x27064;
        int x27372 = x27371 * 10;
        char x27374 = x5[x27373];
        char x27375 = x27374 - '0';
        int x27376 = x27372 + x27375;
        x27329 = x27376;
        int x27378 = x27330;
        int x27379 = x27378 * 10;
        x27330 = x27379;
        x27064 = x27064 + 1;
      }
    } else {
    }
    x27064 = x27064 + 1;
    int x27388 = x27329;
    int x27390 = x27330;
    for (;;) {
      long x27396 = x27064;
      char x27397 = x5[x27396];
      bool x27398 = x27397 != '.';
      bool x27403 = x27398;
      if (x27398) {
        long x27399 = x27064;
        char x27400 = x5[x27399];
        bool x27401 = x27400 != '|';
        x27403 = x27401;
      }
      bool x27404 = x27403;
      bool x27409 = x27404;
      if (x27404) {
        long x27405 = x27064;
        char x27406 = x5[x27405];
        bool x27407 = x27406 != '\n';
        x27409 = x27407;
      }
      bool x27410 = x27409;
      if (!x27410) break;
      x27064 = x27064 + 1;
    }
    long x27422 = x27064;
    char x27423 = x5[x27422];
    bool x27424 = x27423 == '.';
    if (x27424) {
      x27064 = x27064 + 1;
      for (;;) {
        long x27426 = x27064;
        char x27427 = x5[x27426];
        bool x27428 = x27427 != '|';
        bool x27433 = x27428;
        if (x27428) {
          long x27429 = x27064;
          char x27430 = x5[x27429];
          bool x27431 = x27430 != '\n';
          x27433 = x27431;
        }
        bool x27434 = x27433;
        if (!x27434) break;
        x27064 = x27064 + 1;
      }
    } else {
    }
    x27064 = x27064 + 1;
    x27064 = x27064 + 2;
    x27064 = x27064 + 2;
    int x27465 = 0;
    for (;;) {
      long x27466 = x27064;
      char x27467 = x5[x27466];
      bool x27468 = x27467 != '-';
      bool x27473 = x27468;
      if (x27468) {
        long x27469 = x27064;
        char x27470 = x5[x27469];
        bool x27471 = x27470 != '\n';
        x27473 = x27471;
      }
      bool x27474 = x27473;
      if (!x27474) break;
      int x27476 = x27465;
      long x27478 = x27064;
      int x27477 = x27476 * 10;
      char x27479 = x5[x27478];
      char x27480 = x27479 - '0';
      int x27481 = x27477 + x27480;
      x27465 = x27481;
      x27064 = x27064 + 1;
    }
    x27064 = x27064 + 1;
    int x27487 = x27465;
    int x27489 = 0;
    for (;;) {
      long x27490 = x27064;
      char x27491 = x5[x27490];
      bool x27492 = x27491 != '-';
      bool x27497 = x27492;
      if (x27492) {
        long x27493 = x27064;
        char x27494 = x5[x27493];
        bool x27495 = x27494 != '\n';
        x27497 = x27495;
      }
      bool x27498 = x27497;
      if (!x27498) break;
      int x27500 = x27489;
      long x27502 = x27064;
      int x27501 = x27500 * 10;
      char x27503 = x5[x27502];
      char x27504 = x27503 - '0';
      int x27505 = x27501 + x27504;
      x27489 = x27505;
      x27064 = x27064 + 1;
    }
    x27064 = x27064 + 1;
    int x27511 = x27489;
    int x27513 = 0;
    for (;;) {
      long x27514 = x27064;
      char x27515 = x5[x27514];
      bool x27516 = x27515 != '|';
      bool x27521 = x27516;
      if (x27516) {
        long x27517 = x27064;
        char x27518 = x5[x27517];
        bool x27519 = x27518 != '\n';
        x27521 = x27519;
      }
      bool x27522 = x27521;
      if (!x27522) break;
      int x27524 = x27513;
      long x27526 = x27064;
      int x27525 = x27524 * 10;
      char x27527 = x5[x27526];
      char x27528 = x27527 - '0';
      int x27529 = x27525 + x27528;
      x27513 = x27529;
      x27064 = x27064 + 1;
    }
    x27064 = x27064 + 1;
    int x27535 = x27513;
    for (;;) {
      long x27542 = x27064;
      char x27543 = x5[x27542];
      bool x27544 = x27543 != '-';
      bool x27549 = x27544;
      if (x27544) {
        long x27545 = x27064;
        char x27546 = x5[x27545];
        bool x27547 = x27546 != '\n';
        x27549 = x27547;
      }
      bool x27550 = x27549;
      if (!x27550) break;
      x27064 = x27064 + 1;
    }
    x27064 = x27064 + 1;
    for (;;) {
      long x27566 = x27064;
      char x27567 = x5[x27566];
      bool x27568 = x27567 != '-';
      bool x27573 = x27568;
      if (x27568) {
        long x27569 = x27064;
        char x27570 = x5[x27569];
        bool x27571 = x27570 != '\n';
        x27573 = x27571;
      }
      bool x27574 = x27573;
      if (!x27574) break;
      x27064 = x27064 + 1;
    }
    x27064 = x27064 + 1;
    for (;;) {
      long x27590 = x27064;
      char x27591 = x5[x27590];
      bool x27592 = x27591 != '|';
      bool x27597 = x27592;
      if (x27592) {
        long x27593 = x27064;
        char x27594 = x5[x27593];
        bool x27595 = x27594 != '\n';
        x27597 = x27595;
      }
      bool x27598 = x27597;
      if (!x27598) break;
      x27064 = x27064 + 1;
    }
    x27064 = x27064 + 1;
    for (;;) {
      long x27618 = x27064;
      char x27619 = x5[x27618];
      bool x27620 = x27619 != '-';
      bool x27625 = x27620;
      if (x27620) {
        long x27621 = x27064;
        char x27622 = x5[x27621];
        bool x27623 = x27622 != '\n';
        x27625 = x27623;
      }
      bool x27626 = x27625;
      if (!x27626) break;
      x27064 = x27064 + 1;
    }
    x27064 = x27064 + 1;
    for (;;) {
      long x27642 = x27064;
      char x27643 = x5[x27642];
      bool x27644 = x27643 != '-';
      bool x27649 = x27644;
      if (x27644) {
        long x27645 = x27064;
        char x27646 = x5[x27645];
        bool x27647 = x27646 != '\n';
        x27649 = x27647;
      }
      bool x27650 = x27649;
      if (!x27650) break;
      x27064 = x27064 + 1;
    }
    x27064 = x27064 + 1;
    for (;;) {
      long x27666 = x27064;
      char x27667 = x5[x27666];
      bool x27668 = x27667 != '|';
      bool x27673 = x27668;
      if (x27668) {
        long x27669 = x27064;
        char x27670 = x5[x27669];
        bool x27671 = x27670 != '\n';
        x27673 = x27671;
      }
      bool x27674 = x27673;
      if (!x27674) break;
      x27064 = x27064 + 1;
    }
    x27064 = x27064 + 1;
    for (;;) {
      long x27693 = x27064;
      char x27694 = x5[x27693];
      bool x27695 = x27694 != '|';
      bool x27700 = x27695;
      if (x27695) {
        long x27696 = x27064;
        char x27697 = x5[x27696];
        bool x27698 = x27697 != '\n';
        x27700 = x27698;
      }
      bool x27701 = x27700;
      if (!x27701) break;
      x27064 = x27064 + 1;
    }
    x27064 = x27064 + 1;
    for (;;) {
      long x27711 = x27064;
      char x27712 = x5[x27711];
      bool x27713 = x27712 != '|';
      bool x27718 = x27713;
      if (x27713) {
        long x27714 = x27064;
        char x27715 = x5[x27714];
        bool x27716 = x27715 != '\n';
        x27718 = x27716;
      }
      bool x27719 = x27718;
      if (!x27719) break;
      x27064 = x27064 + 1;
    }
    x27064 = x27064 + 1;
    for (;;) {
      long x27729 = x27064;
      char x27730 = x5[x27729];
      bool x27731 = x27730 != '|';
      bool x27736 = x27731;
      if (x27731) {
        long x27732 = x27064;
        char x27733 = x5[x27732];
        bool x27734 = x27733 != '\n';
        x27736 = x27734;
      }
      bool x27737 = x27736;
      if (!x27737) break;
      x27064 = x27064 + 1;
    }
    x27064 = x27064 + 1;
    long x27747 = x27064;
    bool x27748 = x27747 > 0L;
    bool x27754 = x27748;
    if (x27748) {
      long x27749 = x27064;
      long x27750 = x27749 - 1L;
      char x27751 = x5[x27750];
      bool x27752 = x27751 != '\n';
      x27754 = x27752;
    }
    bool x27755 = x27754;
    if (x27755) {
      for (;;) {
        long x27756 = x27064;
        char x27757 = x5[x27756];
        bool x27758 = x27757 != '\n';
        if (!x27758) break;
        x27064 = x27064 + 1;
      }
    } else {
    }
    x27064 = x27064 + 1;
    long x27767 = x27066;
    long x27768 = x27065;
    bool x27769 = x27767 == x27768;
    if (x27769) {
      long x27770 = x27768 * 4L;
      x27065 = x27770;
      printf("buffer.resize %ld\n",x27770);
      int* x27779 = x27072;
      int* x27780 = (int*)realloc(x27779,x27770 * sizeof(int));
      x27072 = x27780;
      double* x27788 = x27078;
      double* x27789 = (double*)realloc(x27788,x27770 * sizeof(double));
      x27078 = x27789;
      double* x27791 = x27080;
      double* x27792 = (double*)realloc(x27791,x27770 * sizeof(double));
      x27080 = x27792;
      long* x27803 = x27088;
      long* x27804 = (long*)realloc(x27803,x27770 * sizeof(long));
      x27088 = x27804;
    } else {
    }
    int* x27827 = x27072;
    x27827[x27767] = x27173;
    double* x27833 = x27078;
    double x27324 = (double)x27323;
    double x27326 = (double)x27325;
    double x27327 = x27324 / x27326;
    x27833[x27767] = x27327;
    double* x27835 = x27080;
    double x27389 = (double)x27388;
    double x27391 = (double)x27390;
    double x27392 = x27389 / x27391;
    x27835[x27767] = x27392;
    long* x27843 = x27088;
    long x27536 = x27487 * 10000L;
    long x27537 = x27511 * 100L;
    long x27538 = x27536 + x27537;
    long x27539 = x27538 + x27535;
    x27843[x27767] = x27539;
    x27066 = x27066 + 1;
  }
  long x27858 = 0L;
  long x27859 = x7;
  long x27860 = 0L;
  int* x27861 = (int*)malloc(x7 * sizeof(int));
  int* x27862 = x27861;
  char** x27863 = (char**)malloc(x7 * sizeof(char*));
  char** x27864 = x27863;
  char** x27865 = (char**)malloc(x7 * sizeof(char*));
  char** x27866 = x27865;
  char** x27869 = (char**)malloc(x7 * sizeof(char*));
  char** x27870 = x27869;
  int x1908 = open("XXXXXsupplier.tbl",0);
  long x1909 = fsize(x1908);
  char* x1910 = mmap(0, x1909, PROT_READ, MAP_FILE | MAP_SHARED, x1908, 0);
  for (;;) {
    long x27875 = x27858;
    bool x27876 = x27875 < x1909;
    if (!x27876) break;
    int x27879 = 0;
    for (;;) {
      long x27880 = x27858;
      char x27881 = x1910[x27880];
      bool x27882 = x27881 != '|';
      bool x27887 = x27882;
      if (x27882) {
        long x27883 = x27858;
        char x27884 = x1910[x27883];
        bool x27885 = x27884 != '\n';
        x27887 = x27885;
      }
      bool x27888 = x27887;
      if (!x27888) break;
      int x27890 = x27879;
      long x27892 = x27858;
      int x27891 = x27890 * 10;
      char x27893 = x1910[x27892];
      char x27894 = x27893 - '0';
      int x27895 = x27891 + x27894;
      x27879 = x27895;
      x27858 = x27858 + 1;
    }
    x27858 = x27858 + 1;
    int x27901 = x27879;
    long x27902 = x27858;
    for (;;) {
      long x27903 = x27858;
      char x27904 = x1910[x27903];
      bool x27905 = x27904 != '|';
      bool x27910 = x27905;
      if (x27905) {
        long x27906 = x27858;
        char x27907 = x1910[x27906];
        bool x27908 = x27907 != '\n';
        x27910 = x27908;
      }
      bool x27911 = x27910;
      if (!x27911) break;
      x27858 = x27858 + 1;
    }
    x27858 = x27858 + 1;
    long x27920 = x27858;
    for (;;) {
      long x27921 = x27858;
      char x27922 = x1910[x27921];
      bool x27923 = x27922 != '|';
      bool x27928 = x27923;
      if (x27923) {
        long x27924 = x27858;
        char x27925 = x1910[x27924];
        bool x27926 = x27925 != '\n';
        x27928 = x27926;
      }
      bool x27929 = x27928;
      if (!x27929) break;
      x27858 = x27858 + 1;
    }
    x27858 = x27858 + 1;
    for (;;) {
      long x27940 = x27858;
      char x27941 = x1910[x27940];
      bool x27942 = x27941 != '|';
      bool x27947 = x27942;
      if (x27942) {
        long x27943 = x27858;
        char x27944 = x1910[x27943];
        bool x27945 = x27944 != '\n';
        x27947 = x27945;
      }
      bool x27948 = x27947;
      if (!x27948) break;
      x27858 = x27858 + 1;
    }
    x27858 = x27858 + 1;
    long x27962 = x27858;
    for (;;) {
      long x27963 = x27858;
      char x27964 = x1910[x27963];
      bool x27965 = x27964 != '|';
      bool x27970 = x27965;
      if (x27965) {
        long x27966 = x27858;
        char x27967 = x1910[x27966];
        bool x27968 = x27967 != '\n';
        x27970 = x27968;
      }
      bool x27971 = x27970;
      if (!x27971) break;
      x27858 = x27858 + 1;
    }
    x27858 = x27858 + 1;
    for (;;) {
      long x27983 = x27858;
      char x27984 = x1910[x27983];
      bool x27985 = x27984 != '.';
      bool x27990 = x27985;
      if (x27985) {
        long x27986 = x27858;
        char x27987 = x1910[x27986];
        bool x27988 = x27987 != '|';
        x27990 = x27988;
      }
      bool x27991 = x27990;
      bool x27996 = x27991;
      if (x27991) {
        long x27992 = x27858;
        char x27993 = x1910[x27992];
        bool x27994 = x27993 != '\n';
        x27996 = x27994;
      }
      bool x27997 = x27996;
      if (!x27997) break;
      x27858 = x27858 + 1;
    }
    long x28009 = x27858;
    char x28010 = x1910[x28009];
    bool x28011 = x28010 == '.';
    if (x28011) {
      x27858 = x27858 + 1;
      for (;;) {
        long x28013 = x27858;
        char x28014 = x1910[x28013];
        bool x28015 = x28014 != '|';
        bool x28020 = x28015;
        if (x28015) {
          long x28016 = x27858;
          char x28017 = x1910[x28016];
          bool x28018 = x28017 != '\n';
          x28020 = x28018;
        }
        bool x28021 = x28020;
        if (!x28021) break;
        x27858 = x27858 + 1;
      }
    } else {
    }
    x27858 = x27858 + 1;
    for (;;) {
      long x28046 = x27858;
      char x28047 = x1910[x28046];
      bool x28048 = x28047 != '|';
      bool x28053 = x28048;
      if (x28048) {
        long x28049 = x27858;
        char x28050 = x1910[x28049];
        bool x28051 = x28050 != '\n';
        x28053 = x28051;
      }
      bool x28054 = x28053;
      if (!x28054) break;
      x27858 = x27858 + 1;
    }
    x27858 = x27858 + 1;
    long x28064 = x27858;
    bool x28065 = x28064 > 0L;
    bool x28071 = x28065;
    if (x28065) {
      long x28066 = x27858;
      long x28067 = x28066 - 1L;
      char x28068 = x1910[x28067];
      bool x28069 = x28068 != '\n';
      x28071 = x28069;
    }
    bool x28072 = x28071;
    if (x28072) {
      for (;;) {
        long x28073 = x27858;
        char x28074 = x1910[x28073];
        bool x28075 = x28074 != '\n';
        if (!x28075) break;
        x27858 = x27858 + 1;
      }
    } else {
    }
    x27858 = x27858 + 1;
    long x28084 = x27860;
    long x28085 = x27859;
    bool x28086 = x28084 == x28085;
    if (x28086) {
      long x28087 = x28085 * 4L;
      x27859 = x28087;
      printf("buffer.resize %ld\n",x28087);
      int* x28090 = x27862;
      int* x28091 = (int*)realloc(x28090,x28087 * sizeof(int));
      x27862 = x28091;
      char** x28093 = x27864;
      char** x28094 = (char**)realloc(x28093,x28087 * sizeof(char*));
      x27864 = x28094;
      char** x28096 = x27866;
      char** x28097 = (char**)realloc(x28096,x28087 * sizeof(char*));
      x27866 = x28097;
      char** x28102 = x27870;
      char** x28103 = (char**)realloc(x28102,x28087 * sizeof(char*));
      x27870 = x28103;
    } else {
    }
    int* x28113 = x27862;
    x28113[x28084] = x27901;
    char** x28115 = x27864;
    char* x27919 = x1910+x27902;
    x28115[x28084] = x27919;
    char** x28117 = x27866;
    char* x27937 = x1910+x27920;
    x28117[x28084] = x27937;
    char** x28121 = x27870;
    char* x27979 = x1910+x27962;
    x28121[x28084] = x27979;
    x27860 = x27860 + 1;
  }
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  long x22466 = DEFAULT_VIEW_SIZE;
  long x2189 = DEFAULT_JOIN_HASH_SIZE;
  long x823 = x808 - 1L;
  long x2212 = x2189 - 1L;
  bool x1043 = true == false;
  int x28130;
  for(x28130=0; x28130 < 5; x28130++) {
    bool x28131 = false;
    long x28132 = 0L;
    struct Anon152692660* x28135 = (struct Anon152692660*)malloc(x808 * sizeof(struct Anon152692660));
    struct Anon152692660* x28136 = x28135;
    long x28137 = 0L;
    long* x28138 = (long*)malloc(x808 * sizeof(long));
    long x28139;
    for(x28139=0L; x28139 < x808; x28139++) {
      struct Anon152692660* x28140 = x28136;
      struct Anon152692660 x28141 = x28140[x28139];
      int x28142 = x28141.key;;
      struct Anon2052879266 x28143 = x28141.aggs;;
      struct Anon152692660 x28144;
      x28144.exists = false;
      x28144.key = x28142;
      x28144.aggs = x28143;
      x28140[x28139] = x28144;
    }
    long x28149 = x22466;
    long x28150 = 0L;
    int* x28153 = (int*)malloc(x22466 * sizeof(int));
    int* x28154 = x28153;
    double* x28155 = (double*)malloc(x22466 * sizeof(double));
    double* x28156 = x28155;
    struct Anon1042493154* x28160 = (struct Anon1042493154*)malloc(x808 * sizeof(struct Anon1042493154));
    struct Anon1042493154* x28161 = x28160;
    long x28162 = 0L;
    long* x28163 = (long*)malloc(x808 * sizeof(long));
    long x28164;
    for(x28164=0L; x28164 < x808; x28164++) {
      struct Anon1042493154* x28165 = x28161;
      struct Anon1042493154 x28166 = x28165[x28164];
      char* x28167 = x28166.key;;
      struct Anon2052879266 x28168 = x28166.aggs;;
      struct Anon1042493154 x28169;
      x28169.exists = false;
      x28169.key = x28167;
      x28169.aggs = x28168;
      x28165[x28164] = x28169;
    }
    double x28175 = 0.0;
    bool x28178 = false;
    long x28179 = 0L;
    int* x28181 = (int*)malloc(x2189 * sizeof(int));
    int* x28182 = x28181;
    char** x28183 = (char**)malloc(x2189 * sizeof(char*));
    char** x28184 = x28183;
    char** x28185 = (char**)malloc(x2189 * sizeof(char*));
    char** x28186 = x28185;
    char** x28189 = (char**)malloc(x2189 * sizeof(char*));
    char** x28190 = x28189;
    long x28195 = 0L;
    long* x28196 = (long*)malloc(x2189 * sizeof(long));
    long* x28197 = (long*)malloc(x2189 * sizeof(long));
    long x28198;
    for(x28198=0L; x28198 < x2189; x28198++) {
      x28196[x28198] = -1L;
    }
    long x28204 = 0L;
    struct timeval x28566, x28567, x28568;
    gettimeofday(&x28566, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x28206 = x28131;
      bool x28207 = !x28206;
      bool x28212 = x28207;
      if (x28207) {
        long x28208 = x28132;
        long x28209 = x27066;
        bool x28210 = x28208 < x28209;
        x28212 = x28210;
      }
      bool x28213 = x28212;
      if (!x28213) break;
      long x28215 = x28132;
      int* x28220 = x27072;
      int x28221 = x28220[x28215];
      double* x28226 = x27078;
      double x28227 = x28226[x28215];
      double* x28228 = x27080;
      double x28229 = x28228[x28215];
      long* x28236 = x27088;
      long x28237 = x28236[x28215];
      x28132 = x28132 + 1;
      bool x28250 = x28237 >= 19960101L;
      bool x28252 = x28250;
      if (x28250) {
        bool x28251 = x28237 < 19960401L;
        x28252 = x28251;
      }
      bool x28253 = x28252;
      if (x28253) {
        long x28254 = x28221 & x823;
        long x28255 = x28254;
        struct Anon152692660* x28256 = x28136;
        struct Anon152692660 x28257 = x28256[x28254];
        struct Anon152692660 x28258 = x28257;
        bool x28259 = x28257.exists;;
        bool x28264 = x28259;
        if (x28259) {
          struct Anon152692660 x28260 = x28258;
          int x28261 = x28260.key;;
          bool x28262 = x28261 == x28221;
          x28264 = x28262;
        }
        bool x28265 = x28264;
        if (x28265) {
          struct Anon2052879266 x28266 = x28257.aggs;;
          int x28272 = x28257.key;;
          double x28267 = x28266._0;;
          double x28268 = 1.0 - x28229;
          double x28269 = x28227 * x28268;
          double x28270 = x28267 + x28269;
          struct Anon2052879266 x28271;
          x28271._0 = x28270;
          struct Anon152692660 x28273;
          x28273.exists = true;
          x28273.key = x28272;
          x28273.aggs = x28271;
          x28256[x28254] = x28273;
        } else {
          double x28268 = 1.0 - x28229;
          double x28269 = x28227 * x28268;
          struct Anon2052879266 x28302;
          x28302._0 = x28269;
          struct Anon152692660 x28303;
          x28303.exists = true;
          x28303.key = x28221;
          x28303.aggs = x28302;
          for (;;) {
            struct Anon152692660 x28276 = x28258;
            bool x28277 = x28276.exists;;
            bool x28312;
            if (x28277) {
              int x28278 = x28276.key;;
              bool x28279 = x28278 == x28221;
              bool x28299;
              if (x28279) {
                struct Anon2052879266 x28280 = x28276.aggs;;
                long x28284 = x28255;
                struct Anon152692660* x28286 = x28136;
                double x28281 = x28280._0;;
                double x28282 = x28281 + x28269;
                struct Anon2052879266 x28283;
                x28283._0 = x28282;
                struct Anon152692660 x28285;
                x28285.exists = true;
                x28285.key = x28278;
                x28285.aggs = x28283;
                x28286[x28284] = x28285;
                x28299 = false;
              } else {
                long x28289 = x28255;
                long x28290 = x28289 + 1L;
                long x28291 = x28290 & x823;
                x28255 = x28291;
                struct Anon152692660* x28293 = x28136;
                struct Anon152692660 x28294 = x28293[x28291];
                x28258 = x28294;
                x28299 = true;
              }
              x28312 = x28299;
            } else {
              long x28301 = x28255;
              struct Anon152692660* x28304 = x28136;
              x28304[x28301] = x28303;
              long x28306 = x28137;
              x28138[x28306] = x28301;
              x28137 = x28137 + 1L;
              x28312 = false;
            }
            if (!x28312) break;
          }
        }
      } else {
      }
    }
    long x28323 = x28137;
    long x28325;
    for(x28325=0L; x28325 < x28323; x28325++) {
      long x28326 = x28138[x28325];
      struct Anon152692660* x28327 = x28136;
      struct Anon152692660 x28328 = x28327[x28326];
      long x28329 = x28150;
      long x28330 = x28149;
      bool x28331 = x28329 == x28330;
      if (x28331) {
        long x28332 = x28330 * 4L;
        x28149 = x28332;
        printf("buffer.resize %ld\n",x28332);
        int* x28338 = x28154;
        int* x28339 = (int*)realloc(x28338,x28332 * sizeof(int));
        x28154 = x28339;
        printf("buffer.resize %ld\n",x28332);
        double* x28342 = x28156;
        double* x28343 = (double*)realloc(x28342,x28332 * sizeof(double));
        x28156 = x28343;
      } else {
      }
      int x28350 = x28328.key;;
      int* x28351 = x28154;
      x28351[x28329] = x28350;
      struct Anon2052879266 x28353 = x28328.aggs;;
      double* x28355 = x28156;
      double x28354 = x28353._0;;
      x28355[x28329] = x28354;
      x28150 = x28150 + 1;
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x28361 = x28178;
      bool x28362 = !x28361;
      bool x28367 = x28362;
      if (x28362) {
        long x28363 = x28179;
        long x28364 = x27860;
        bool x28365 = x28363 < x28364;
        x28367 = x28365;
      }
      bool x28368 = x28367;
      if (!x28368) break;
      long x28370 = x28179;
      int* x28371 = x27862;
      int x28372 = x28371[x28370];
      char** x28373 = x27864;
      char* x28374 = x28373[x28370];
      char** x28375 = x27866;
      char* x28376 = x28375[x28370];
      char** x28379 = x27870;
      char* x28380 = x28379[x28370];
      x28179 = x28179 + 1;
      long x28387 = x28195;
      int* x28388 = x28182;
      x28388[x28387] = x28372;
      char** x28390 = x28184;
      x28390[x28387] = x28374;
      char** x28392 = x28186;
      x28392[x28387] = x28376;
      char** x28396 = x28190;
      x28396[x28387] = x28380;
      x28195 = x28195 + 1L;
      long x28403 = x28372 & x2212;
      long x28404 = x28196[x28403];
      x28196[x28403] = x28387;
      x28197[x28387] = x28404;
    }
    long x28409 = x28150;
    long x28411;
    for(x28411=0L; x28411 < x28409; x28411++) {
      double* x28416 = x28156;
      double x28417 = x28416[x28411];
      long x28420 = hash("MAXREVENUE", 10L);
      long x28421 = x28420 & x823;
      long x28422 = x28421;
      struct Anon1042493154* x28423 = x28161;
      struct Anon1042493154 x28424 = x28423[x28421];
      struct Anon1042493154 x28425 = x28424;
      bool x28426 = x28424.exists;;
      bool x28431 = x28426;
      if (x28426) {
        struct Anon1042493154 x28427 = x28425;
        char* x28428 = x28427.key;;
        bool x28429 = tpch_strcmp(x28428,"MAXREVENUE") == 0;;
        x28431 = x28429;
      }
      bool x28432 = x28431;
      if (x28432) {
        struct Anon2052879266 x28433 = x28424.aggs;;
        char* x28438 = x28424.key;;
        double x28434 = x28433._0;;
        bool x28435 = x28434 < x28417;
        double x28436;
        if (x28435) {
          x28436 = x28417;
        } else {
          x28436 = x28434;
        }
        struct Anon2052879266 x28437;
        x28437._0 = x28436;
        struct Anon1042493154 x28439;
        x28439.exists = true;
        x28439.key = x28438;
        x28439.aggs = x28437;
        x28423[x28421] = x28439;
      } else {
        bool x28469 = 0.0 < x28417;
        double x28470;
        if (x28469) {
          x28470 = x28417;
        } else {
          x28470 = 0.0;
        }
        struct Anon2052879266 x28471;
        x28471._0 = x28470;
        struct Anon1042493154 x28472;
        x28472.exists = true;
        x28472.key = "MAXREVENUE";
        x28472.aggs = x28471;
        for (;;) {
          struct Anon1042493154 x28442 = x28425;
          bool x28443 = x28442.exists;;
          bool x28481;
          if (x28443) {
            char* x28444 = x28442.key;;
            bool x28445 = tpch_strcmp(x28444,"MAXREVENUE") == 0;;
            bool x28466;
            if (x28445) {
              struct Anon2052879266 x28446 = x28442.aggs;;
              long x28451 = x28422;
              struct Anon1042493154* x28453 = x28161;
              double x28447 = x28446._0;;
              bool x28448 = x28447 < x28417;
              double x28449;
              if (x28448) {
                x28449 = x28417;
              } else {
                x28449 = x28447;
              }
              struct Anon2052879266 x28450;
              x28450._0 = x28449;
              struct Anon1042493154 x28452;
              x28452.exists = true;
              x28452.key = x28444;
              x28452.aggs = x28450;
              x28453[x28451] = x28452;
              x28466 = false;
            } else {
              long x28456 = x28422;
              long x28457 = x28456 + 1L;
              long x28458 = x28457 & x823;
              x28422 = x28458;
              struct Anon1042493154* x28460 = x28161;
              struct Anon1042493154 x28461 = x28460[x28458];
              x28425 = x28461;
              x28466 = true;
            }
            x28481 = x28466;
          } else {
            long x28468 = x28422;
            struct Anon1042493154* x28473 = x28161;
            x28473[x28468] = x28472;
            long x28475 = x28162;
            x28163[x28475] = x28468;
            x28162 = x28162 + 1L;
            x28481 = false;
          }
          if (!x28481) break;
        }
      }
    }
    long x28490 = x28162;
    long x28492;
    for(x28492=0L; x28492 < x28490; x28492++) {
      long x28493 = x28163[x28492];
      struct Anon1042493154* x28494 = x28161;
      struct Anon1042493154 x28495 = x28494[x28493];
      struct Anon2052879266 x28496 = x28495.aggs;;
      double x28497 = x28496._0;;
      x28175 = x28497;
      long x28500 = x28150;
      long x28502;
      for(x28502=0L; x28502 < x28500; x28502++) {
        int* x28505 = x28154;
        int x28506 = x28505[x28502];
        double* x28507 = x28156;
        double x28508 = x28507[x28502];
        double x28511 = x28175;
        bool x28513 = x28508 == x28511;
        if (x28513) {
          long x28516 = x28506 & x2212;
          long x28517 = x28196[x28516];
          long x28518 = x28517;
          for (;;) {
            long x28519 = x28518;
            bool x28520 = x28519 != -1;
            if (!x28520) break;
            long x28522 = x28518;
            int* x28523 = x28182;
            int x28524 = x28523[x28522];
            char** x28525 = x28184;
            char* x28526 = x28525[x28522];
            char** x28527 = x28186;
            char* x28528 = x28527[x28522];
            char** x28531 = x28190;
            char* x28532 = x28531[x28522];
            long x28538 = x28197[x28522];
            x28518 = x28538;
            bool x28540 = x28524 == x28506;
            if (x28540) {
              if (x1043) {
              } else {
                int x28546 = tpch_strlen(x28526);
                int x28547 = tpch_strlen(x28528);
                int x28548 = tpch_strlen(x28532);
                printf("%d|%.*s|%.*s|%.*s|%.4f\n",x28524,x28546,x28526,x28547,x28528,x28548,x28532,x28508);
                x28204 = x28204 + 1L;
              }
            } else {
            }
          }
        } else {
        }
      }
    }
    long x28563 = x28204;
    printf("(%ld rows)\n",x28563);
    gettimeofday(&x28567, NULL);
    timeval_subtract(&x28568, &x28567, &x28566);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x28568.tv_sec * 1000) + (x28568.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
