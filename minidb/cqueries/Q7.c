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

struct Anon2052879266 {
double _0;
};

struct Anon895445893 {
bool exists;
struct Anon1465150758 key;
struct Anon2052879266 aggs;
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

struct Anon1078540535 {
char* N_NAME;
int N_NATIONKEY;
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
struct Anon920667905 left;
struct Anon713865179Anon72918141Anon1268892766Anon168903330Anon811555534 right;
};

struct Anon1495587458 {
int key;
struct Anon1023322325 wnd;
};

struct Anon1042493154 {
bool exists;
char* key;
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

struct Anon1268892766 {
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
};

struct Anon625264174 {
char L_RETURNFLAG;
char L_LINESTATUS;
};

struct Anon631953537 {
struct Anon625264174 key;
struct Anon1296044246 aggs;
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

struct Anon1052706553 {
bool exists;
int key;
struct Anon1023322325 aggs;
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

struct Anon348455037 {
char* N_NAME;
int N_NATIONKEY;
int L_SUPPKEY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
};

struct Anon1395358962 {
int PS_PARTKEY;
int PS_SUPPKEY;
int PS_AVAILQTY;
double PS_SUPPLYCOST;
char* PS_COMMENT;
};

/************************ FUNCTIONS **************************/
int x12789(struct Anon197435497* x12764, struct Anon197435497* x12765);
int x12789(struct Anon197435497* x12764, struct Anon197435497* x12765) {
  struct Anon197435497 x12766 = (*x12764);
  struct Anon197435497 x12767 = (*x12765);
  struct Anon726278688 x12768 = x12766.key;;
  char* x12770 = x12768.SUPP_NATION;;
  struct Anon726278688 x12769 = x12767.key;;
  char* x12771 = x12769.SUPP_NATION;;
  int x12772 = tpch_strcmp(x12770,x12771);
  bool x12774 = x12772 == 0;
  int x12787;
  if (x12774) {
    char* x12775 = x12768.CUST_NATION;;
    char* x12776 = x12769.CUST_NATION;;
    int x12777 = tpch_strcmp(x12775,x12776);
    bool x12779 = x12777 == 0;
    int x12786;
    if (x12779) {
      int x12780 = x12768.L_YEAR;;
      int x12781 = x12769.L_YEAR;;
      bool x12782 = x12780 < x12781;
      int x12785;
      if (x12782) {
        x12785 = -1;
      } else {
        bool x12783 = x12780 > x12781;
        int x12784;
        if (x12783) {
          x12784 = 1;
        } else {
          x12784 = 0;
        }
        x12785 = x12784;
      }
      x12786 = x12785;
    } else {
      x12786 = x12777;
    }
    x12787 = x12786;
  } else {
    x12787 = x12772;
  }
  return x12787;
}

/************************ MAIN BODY **************************/
int main(int x9991, char** x9992) {
  long x9993 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x9994 = x7;
  long x9995 = 0L;
  int* x9996 = (int*)malloc(x7 * sizeof(int));
  int* x9997 = x9996;
  char** x9998 = (char**)malloc(x7 * sizeof(char*));
  char** x9999 = x9998;
  int x1633 = open("XXXXXnation.tbl",0);
  long x1634 = fsize(x1633);
  char* x1635 = mmap(0, x1634, PROT_READ, MAP_FILE | MAP_SHARED, x1633, 0);
  for (;;) {
    long x10004 = x9993;
    bool x10005 = x10004 < x1634;
    if (!x10005) break;
    int x10008 = 0;
    for (;;) {
      long x10009 = x9993;
      char x10010 = x1635[x10009];
      bool x10011 = x10010 != '|';
      bool x10016 = x10011;
      if (x10011) {
        long x10012 = x9993;
        char x10013 = x1635[x10012];
        bool x10014 = x10013 != '\n';
        x10016 = x10014;
      }
      bool x10017 = x10016;
      if (!x10017) break;
      int x10019 = x10008;
      long x10021 = x9993;
      int x10020 = x10019 * 10;
      char x10022 = x1635[x10021];
      char x10023 = x10022 - '0';
      int x10024 = x10020 + x10023;
      x10008 = x10024;
      x9993 = x9993 + 1;
    }
    x9993 = x9993 + 1;
    int x10030 = x10008;
    long x10031 = x9993;
    for (;;) {
      long x10032 = x9993;
      char x10033 = x1635[x10032];
      bool x10034 = x10033 != '|';
      bool x10039 = x10034;
      if (x10034) {
        long x10035 = x9993;
        char x10036 = x1635[x10035];
        bool x10037 = x10036 != '\n';
        x10039 = x10037;
      }
      bool x10040 = x10039;
      if (!x10040) break;
      x9993 = x9993 + 1;
    }
    x9993 = x9993 + 1;
    for (;;) {
      long x10051 = x9993;
      char x10052 = x1635[x10051];
      bool x10053 = x10052 != '|';
      bool x10058 = x10053;
      if (x10053) {
        long x10054 = x9993;
        char x10055 = x1635[x10054];
        bool x10056 = x10055 != '\n';
        x10058 = x10056;
      }
      bool x10059 = x10058;
      if (!x10059) break;
      x9993 = x9993 + 1;
    }
    x9993 = x9993 + 1;
    for (;;) {
      long x10074 = x9993;
      char x10075 = x1635[x10074];
      bool x10076 = x10075 != '|';
      bool x10081 = x10076;
      if (x10076) {
        long x10077 = x9993;
        char x10078 = x1635[x10077];
        bool x10079 = x10078 != '\n';
        x10081 = x10079;
      }
      bool x10082 = x10081;
      if (!x10082) break;
      x9993 = x9993 + 1;
    }
    x9993 = x9993 + 1;
    long x10092 = x9993;
    bool x10093 = x10092 > 0L;
    bool x10099 = x10093;
    if (x10093) {
      long x10094 = x9993;
      long x10095 = x10094 - 1L;
      char x10096 = x1635[x10095];
      bool x10097 = x10096 != '\n';
      x10099 = x10097;
    }
    bool x10100 = x10099;
    if (x10100) {
      for (;;) {
        long x10101 = x9993;
        char x10102 = x1635[x10101];
        bool x10103 = x10102 != '\n';
        if (!x10103) break;
        x9993 = x9993 + 1;
      }
    } else {
    }
    x9993 = x9993 + 1;
    long x10112 = x9995;
    long x10113 = x9994;
    bool x10114 = x10112 == x10113;
    if (x10114) {
      long x10115 = x10113 * 4L;
      x9994 = x10115;
      printf("buffer.resize %ld\n",x10115);
      int* x10118 = x9997;
      int* x10119 = (int*)realloc(x10118,x10115 * sizeof(int));
      x9997 = x10119;
      char** x10121 = x9999;
      char** x10122 = (char**)realloc(x10121,x10115 * sizeof(char*));
      x9999 = x10122;
    } else {
    }
    int* x10132 = x9997;
    x10132[x10112] = x10030;
    char** x10134 = x9999;
    char* x10048 = x1635+x10031;
    x10134[x10112] = x10048;
    x9995 = x9995 + 1;
  }
  long x10143 = 0L;
  long x10144 = x7;
  long x10145 = 0L;
  int* x10146 = (int*)malloc(x7 * sizeof(int));
  int* x10147 = x10146;
  int* x10148 = (int*)malloc(x7 * sizeof(int));
  int* x10149 = x10148;
  int x3633 = open("XXXXXorders.tbl",0);
  long x3634 = fsize(x3633);
  char* x3635 = mmap(0, x3634, PROT_READ, MAP_FILE | MAP_SHARED, x3633, 0);
  for (;;) {
    long x10164 = x10143;
    bool x10165 = x10164 < x3634;
    if (!x10165) break;
    int x10168 = 0;
    for (;;) {
      long x10169 = x10143;
      char x10170 = x3635[x10169];
      bool x10171 = x10170 != '|';
      bool x10176 = x10171;
      if (x10171) {
        long x10172 = x10143;
        char x10173 = x3635[x10172];
        bool x10174 = x10173 != '\n';
        x10176 = x10174;
      }
      bool x10177 = x10176;
      if (!x10177) break;
      int x10179 = x10168;
      long x10181 = x10143;
      int x10180 = x10179 * 10;
      char x10182 = x3635[x10181];
      char x10183 = x10182 - '0';
      int x10184 = x10180 + x10183;
      x10168 = x10184;
      x10143 = x10143 + 1;
    }
    x10143 = x10143 + 1;
    int x10190 = x10168;
    int x10192 = 0;
    for (;;) {
      long x10193 = x10143;
      char x10194 = x3635[x10193];
      bool x10195 = x10194 != '|';
      bool x10200 = x10195;
      if (x10195) {
        long x10196 = x10143;
        char x10197 = x3635[x10196];
        bool x10198 = x10197 != '\n';
        x10200 = x10198;
      }
      bool x10201 = x10200;
      if (!x10201) break;
      int x10203 = x10192;
      long x10205 = x10143;
      int x10204 = x10203 * 10;
      char x10206 = x3635[x10205];
      char x10207 = x10206 - '0';
      int x10208 = x10204 + x10207;
      x10192 = x10208;
      x10143 = x10143 + 1;
    }
    x10143 = x10143 + 1;
    int x10214 = x10192;
    x10143 = x10143 + 2;
    for (;;) {
      long x10221 = x10143;
      char x10222 = x3635[x10221];
      bool x10223 = x10222 != '.';
      bool x10228 = x10223;
      if (x10223) {
        long x10224 = x10143;
        char x10225 = x3635[x10224];
        bool x10226 = x10225 != '|';
        x10228 = x10226;
      }
      bool x10229 = x10228;
      bool x10234 = x10229;
      if (x10229) {
        long x10230 = x10143;
        char x10231 = x3635[x10230];
        bool x10232 = x10231 != '\n';
        x10234 = x10232;
      }
      bool x10235 = x10234;
      if (!x10235) break;
      x10143 = x10143 + 1;
    }
    long x10247 = x10143;
    char x10248 = x3635[x10247];
    bool x10249 = x10248 == '.';
    if (x10249) {
      x10143 = x10143 + 1;
      for (;;) {
        long x10251 = x10143;
        char x10252 = x3635[x10251];
        bool x10253 = x10252 != '|';
        bool x10258 = x10253;
        if (x10253) {
          long x10254 = x10143;
          char x10255 = x3635[x10254];
          bool x10256 = x10255 != '\n';
          x10258 = x10256;
        }
        bool x10259 = x10258;
        if (!x10259) break;
        x10143 = x10143 + 1;
      }
    } else {
    }
    x10143 = x10143 + 1;
    for (;;) {
      long x10285 = x10143;
      char x10286 = x3635[x10285];
      bool x10287 = x10286 != '-';
      bool x10292 = x10287;
      if (x10287) {
        long x10288 = x10143;
        char x10289 = x3635[x10288];
        bool x10290 = x10289 != '\n';
        x10292 = x10290;
      }
      bool x10293 = x10292;
      if (!x10293) break;
      x10143 = x10143 + 1;
    }
    x10143 = x10143 + 1;
    for (;;) {
      long x10309 = x10143;
      char x10310 = x3635[x10309];
      bool x10311 = x10310 != '-';
      bool x10316 = x10311;
      if (x10311) {
        long x10312 = x10143;
        char x10313 = x3635[x10312];
        bool x10314 = x10313 != '\n';
        x10316 = x10314;
      }
      bool x10317 = x10316;
      if (!x10317) break;
      x10143 = x10143 + 1;
    }
    x10143 = x10143 + 1;
    for (;;) {
      long x10333 = x10143;
      char x10334 = x3635[x10333];
      bool x10335 = x10334 != '|';
      bool x10340 = x10335;
      if (x10335) {
        long x10336 = x10143;
        char x10337 = x3635[x10336];
        bool x10338 = x10337 != '\n';
        x10340 = x10338;
      }
      bool x10341 = x10340;
      if (!x10341) break;
      x10143 = x10143 + 1;
    }
    x10143 = x10143 + 1;
    for (;;) {
      long x10360 = x10143;
      char x10361 = x3635[x10360];
      bool x10362 = x10361 != '|';
      bool x10367 = x10362;
      if (x10362) {
        long x10363 = x10143;
        char x10364 = x3635[x10363];
        bool x10365 = x10364 != '\n';
        x10367 = x10365;
      }
      bool x10368 = x10367;
      if (!x10368) break;
      x10143 = x10143 + 1;
    }
    x10143 = x10143 + 1;
    for (;;) {
      long x10378 = x10143;
      char x10379 = x3635[x10378];
      bool x10380 = x10379 != '|';
      bool x10385 = x10380;
      if (x10380) {
        long x10381 = x10143;
        char x10382 = x3635[x10381];
        bool x10383 = x10382 != '\n';
        x10385 = x10383;
      }
      bool x10386 = x10385;
      if (!x10386) break;
      x10143 = x10143 + 1;
    }
    x10143 = x10143 + 1;
    for (;;) {
      long x10397 = x10143;
      char x10398 = x3635[x10397];
      bool x10399 = x10398 != '|';
      bool x10404 = x10399;
      if (x10399) {
        long x10400 = x10143;
        char x10401 = x3635[x10400];
        bool x10402 = x10401 != '\n';
        x10404 = x10402;
      }
      bool x10405 = x10404;
      if (!x10405) break;
      x10143 = x10143 + 1;
    }
    x10143 = x10143 + 1;
    for (;;) {
      long x10420 = x10143;
      char x10421 = x3635[x10420];
      bool x10422 = x10421 != '|';
      bool x10427 = x10422;
      if (x10422) {
        long x10423 = x10143;
        char x10424 = x3635[x10423];
        bool x10425 = x10424 != '\n';
        x10427 = x10425;
      }
      bool x10428 = x10427;
      if (!x10428) break;
      x10143 = x10143 + 1;
    }
    x10143 = x10143 + 1;
    long x10438 = x10143;
    bool x10439 = x10438 > 0L;
    bool x10445 = x10439;
    if (x10439) {
      long x10440 = x10143;
      long x10441 = x10440 - 1L;
      char x10442 = x3635[x10441];
      bool x10443 = x10442 != '\n';
      x10445 = x10443;
    }
    bool x10446 = x10445;
    if (x10446) {
      for (;;) {
        long x10447 = x10143;
        char x10448 = x3635[x10447];
        bool x10449 = x10448 != '\n';
        if (!x10449) break;
        x10143 = x10143 + 1;
      }
    } else {
    }
    x10143 = x10143 + 1;
    long x10458 = x10145;
    long x10459 = x10144;
    bool x10460 = x10458 == x10459;
    if (x10460) {
      long x10461 = x10459 * 4L;
      x10144 = x10461;
      printf("buffer.resize %ld\n",x10461);
      int* x10464 = x10147;
      int* x10465 = (int*)realloc(x10464,x10461 * sizeof(int));
      x10147 = x10465;
      int* x10467 = x10149;
      int* x10468 = (int*)realloc(x10467,x10461 * sizeof(int));
      x10149 = x10468;
    } else {
    }
    int* x10493 = x10147;
    x10493[x10458] = x10190;
    int* x10495 = x10149;
    x10495[x10458] = x10214;
    x10145 = x10145 + 1;
  }
  long x10514 = 0L;
  long x10515 = x7;
  long x10516 = 0L;
  int* x10517 = (int*)malloc(x7 * sizeof(int));
  int* x10518 = x10517;
  int* x10521 = (int*)malloc(x7 * sizeof(int));
  int* x10522 = x10521;
  double* x10527 = (double*)malloc(x7 * sizeof(double));
  double* x10528 = x10527;
  double* x10529 = (double*)malloc(x7 * sizeof(double));
  double* x10530 = x10529;
  long* x10537 = (long*)malloc(x7 * sizeof(long));
  long* x10538 = x10537;
  int x3 = open("XXXXXlineitem.tbl",0);
  long x4 = fsize(x3);
  char* x5 = mmap(0, x4, PROT_READ, MAP_FILE | MAP_SHARED, x3, 0);
  for (;;) {
    long x10549 = x10514;
    bool x10550 = x10549 < x4;
    if (!x10550) break;
    int x10553 = 0;
    for (;;) {
      long x10554 = x10514;
      char x10555 = x5[x10554];
      bool x10556 = x10555 != '|';
      bool x10561 = x10556;
      if (x10556) {
        long x10557 = x10514;
        char x10558 = x5[x10557];
        bool x10559 = x10558 != '\n';
        x10561 = x10559;
      }
      bool x10562 = x10561;
      if (!x10562) break;
      int x10564 = x10553;
      long x10566 = x10514;
      int x10565 = x10564 * 10;
      char x10567 = x5[x10566];
      char x10568 = x10567 - '0';
      int x10569 = x10565 + x10568;
      x10553 = x10569;
      x10514 = x10514 + 1;
    }
    x10514 = x10514 + 1;
    int x10575 = x10553;
    for (;;) {
      long x10578 = x10514;
      char x10579 = x5[x10578];
      bool x10580 = x10579 != '|';
      bool x10585 = x10580;
      if (x10580) {
        long x10581 = x10514;
        char x10582 = x5[x10581];
        bool x10583 = x10582 != '\n';
        x10585 = x10583;
      }
      bool x10586 = x10585;
      if (!x10586) break;
      x10514 = x10514 + 1;
    }
    x10514 = x10514 + 1;
    int x10601 = 0;
    for (;;) {
      long x10602 = x10514;
      char x10603 = x5[x10602];
      bool x10604 = x10603 != '|';
      bool x10609 = x10604;
      if (x10604) {
        long x10605 = x10514;
        char x10606 = x5[x10605];
        bool x10607 = x10606 != '\n';
        x10609 = x10607;
      }
      bool x10610 = x10609;
      if (!x10610) break;
      int x10612 = x10601;
      long x10614 = x10514;
      int x10613 = x10612 * 10;
      char x10615 = x5[x10614];
      char x10616 = x10615 - '0';
      int x10617 = x10613 + x10616;
      x10601 = x10617;
      x10514 = x10514 + 1;
    }
    x10514 = x10514 + 1;
    int x10623 = x10601;
    for (;;) {
      long x10626 = x10514;
      char x10627 = x5[x10626];
      bool x10628 = x10627 != '|';
      bool x10633 = x10628;
      if (x10628) {
        long x10629 = x10514;
        char x10630 = x5[x10629];
        bool x10631 = x10630 != '\n';
        x10633 = x10631;
      }
      bool x10634 = x10633;
      if (!x10634) break;
      x10514 = x10514 + 1;
    }
    x10514 = x10514 + 1;
    for (;;) {
      long x10651 = x10514;
      char x10652 = x5[x10651];
      bool x10653 = x10652 != '.';
      bool x10658 = x10653;
      if (x10653) {
        long x10654 = x10514;
        char x10655 = x5[x10654];
        bool x10656 = x10655 != '|';
        x10658 = x10656;
      }
      bool x10659 = x10658;
      bool x10664 = x10659;
      if (x10659) {
        long x10660 = x10514;
        char x10661 = x5[x10660];
        bool x10662 = x10661 != '\n';
        x10664 = x10662;
      }
      bool x10665 = x10664;
      if (!x10665) break;
      x10514 = x10514 + 1;
    }
    long x10677 = x10514;
    char x10678 = x5[x10677];
    bool x10679 = x10678 == '.';
    if (x10679) {
      x10514 = x10514 + 1;
      for (;;) {
        long x10681 = x10514;
        char x10682 = x5[x10681];
        bool x10683 = x10682 != '|';
        bool x10688 = x10683;
        if (x10683) {
          long x10684 = x10514;
          char x10685 = x5[x10684];
          bool x10686 = x10685 != '\n';
          x10688 = x10686;
        }
        bool x10689 = x10688;
        if (!x10689) break;
        x10514 = x10514 + 1;
      }
    } else {
    }
    x10514 = x10514 + 1;
    int x10714 = 0;
    int x10715 = 1;
    for (;;) {
      long x10716 = x10514;
      char x10717 = x5[x10716];
      bool x10718 = x10717 != '.';
      bool x10723 = x10718;
      if (x10718) {
        long x10719 = x10514;
        char x10720 = x5[x10719];
        bool x10721 = x10720 != '|';
        x10723 = x10721;
      }
      bool x10724 = x10723;
      bool x10729 = x10724;
      if (x10724) {
        long x10725 = x10514;
        char x10726 = x5[x10725];
        bool x10727 = x10726 != '\n';
        x10729 = x10727;
      }
      bool x10730 = x10729;
      if (!x10730) break;
      int x10732 = x10714;
      long x10734 = x10514;
      int x10733 = x10732 * 10;
      char x10735 = x5[x10734];
      char x10736 = x10735 - '0';
      int x10737 = x10733 + x10736;
      x10714 = x10737;
      x10514 = x10514 + 1;
    }
    long x10742 = x10514;
    char x10743 = x5[x10742];
    bool x10744 = x10743 == '.';
    if (x10744) {
      x10514 = x10514 + 1;
      for (;;) {
        long x10746 = x10514;
        char x10747 = x5[x10746];
        bool x10748 = x10747 != '|';
        bool x10753 = x10748;
        if (x10748) {
          long x10749 = x10514;
          char x10750 = x5[x10749];
          bool x10751 = x10750 != '\n';
          x10753 = x10751;
        }
        bool x10754 = x10753;
        if (!x10754) break;
        int x10756 = x10714;
        long x10758 = x10514;
        int x10757 = x10756 * 10;
        char x10759 = x5[x10758];
        char x10760 = x10759 - '0';
        int x10761 = x10757 + x10760;
        x10714 = x10761;
        int x10763 = x10715;
        int x10764 = x10763 * 10;
        x10715 = x10764;
        x10514 = x10514 + 1;
      }
    } else {
    }
    x10514 = x10514 + 1;
    int x10773 = x10714;
    int x10775 = x10715;
    int x10779 = 0;
    int x10780 = 1;
    for (;;) {
      long x10781 = x10514;
      char x10782 = x5[x10781];
      bool x10783 = x10782 != '.';
      bool x10788 = x10783;
      if (x10783) {
        long x10784 = x10514;
        char x10785 = x5[x10784];
        bool x10786 = x10785 != '|';
        x10788 = x10786;
      }
      bool x10789 = x10788;
      bool x10794 = x10789;
      if (x10789) {
        long x10790 = x10514;
        char x10791 = x5[x10790];
        bool x10792 = x10791 != '\n';
        x10794 = x10792;
      }
      bool x10795 = x10794;
      if (!x10795) break;
      int x10797 = x10779;
      long x10799 = x10514;
      int x10798 = x10797 * 10;
      char x10800 = x5[x10799];
      char x10801 = x10800 - '0';
      int x10802 = x10798 + x10801;
      x10779 = x10802;
      x10514 = x10514 + 1;
    }
    long x10807 = x10514;
    char x10808 = x5[x10807];
    bool x10809 = x10808 == '.';
    if (x10809) {
      x10514 = x10514 + 1;
      for (;;) {
        long x10811 = x10514;
        char x10812 = x5[x10811];
        bool x10813 = x10812 != '|';
        bool x10818 = x10813;
        if (x10813) {
          long x10814 = x10514;
          char x10815 = x5[x10814];
          bool x10816 = x10815 != '\n';
          x10818 = x10816;
        }
        bool x10819 = x10818;
        if (!x10819) break;
        int x10821 = x10779;
        long x10823 = x10514;
        int x10822 = x10821 * 10;
        char x10824 = x5[x10823];
        char x10825 = x10824 - '0';
        int x10826 = x10822 + x10825;
        x10779 = x10826;
        int x10828 = x10780;
        int x10829 = x10828 * 10;
        x10780 = x10829;
        x10514 = x10514 + 1;
      }
    } else {
    }
    x10514 = x10514 + 1;
    int x10838 = x10779;
    int x10840 = x10780;
    for (;;) {
      long x10846 = x10514;
      char x10847 = x5[x10846];
      bool x10848 = x10847 != '.';
      bool x10853 = x10848;
      if (x10848) {
        long x10849 = x10514;
        char x10850 = x5[x10849];
        bool x10851 = x10850 != '|';
        x10853 = x10851;
      }
      bool x10854 = x10853;
      bool x10859 = x10854;
      if (x10854) {
        long x10855 = x10514;
        char x10856 = x5[x10855];
        bool x10857 = x10856 != '\n';
        x10859 = x10857;
      }
      bool x10860 = x10859;
      if (!x10860) break;
      x10514 = x10514 + 1;
    }
    long x10872 = x10514;
    char x10873 = x5[x10872];
    bool x10874 = x10873 == '.';
    if (x10874) {
      x10514 = x10514 + 1;
      for (;;) {
        long x10876 = x10514;
        char x10877 = x5[x10876];
        bool x10878 = x10877 != '|';
        bool x10883 = x10878;
        if (x10878) {
          long x10879 = x10514;
          char x10880 = x5[x10879];
          bool x10881 = x10880 != '\n';
          x10883 = x10881;
        }
        bool x10884 = x10883;
        if (!x10884) break;
        x10514 = x10514 + 1;
      }
    } else {
    }
    x10514 = x10514 + 1;
    x10514 = x10514 + 2;
    x10514 = x10514 + 2;
    int x10915 = 0;
    for (;;) {
      long x10916 = x10514;
      char x10917 = x5[x10916];
      bool x10918 = x10917 != '-';
      bool x10923 = x10918;
      if (x10918) {
        long x10919 = x10514;
        char x10920 = x5[x10919];
        bool x10921 = x10920 != '\n';
        x10923 = x10921;
      }
      bool x10924 = x10923;
      if (!x10924) break;
      int x10926 = x10915;
      long x10928 = x10514;
      int x10927 = x10926 * 10;
      char x10929 = x5[x10928];
      char x10930 = x10929 - '0';
      int x10931 = x10927 + x10930;
      x10915 = x10931;
      x10514 = x10514 + 1;
    }
    x10514 = x10514 + 1;
    int x10937 = x10915;
    int x10939 = 0;
    for (;;) {
      long x10940 = x10514;
      char x10941 = x5[x10940];
      bool x10942 = x10941 != '-';
      bool x10947 = x10942;
      if (x10942) {
        long x10943 = x10514;
        char x10944 = x5[x10943];
        bool x10945 = x10944 != '\n';
        x10947 = x10945;
      }
      bool x10948 = x10947;
      if (!x10948) break;
      int x10950 = x10939;
      long x10952 = x10514;
      int x10951 = x10950 * 10;
      char x10953 = x5[x10952];
      char x10954 = x10953 - '0';
      int x10955 = x10951 + x10954;
      x10939 = x10955;
      x10514 = x10514 + 1;
    }
    x10514 = x10514 + 1;
    int x10961 = x10939;
    int x10963 = 0;
    for (;;) {
      long x10964 = x10514;
      char x10965 = x5[x10964];
      bool x10966 = x10965 != '|';
      bool x10971 = x10966;
      if (x10966) {
        long x10967 = x10514;
        char x10968 = x5[x10967];
        bool x10969 = x10968 != '\n';
        x10971 = x10969;
      }
      bool x10972 = x10971;
      if (!x10972) break;
      int x10974 = x10963;
      long x10976 = x10514;
      int x10975 = x10974 * 10;
      char x10977 = x5[x10976];
      char x10978 = x10977 - '0';
      int x10979 = x10975 + x10978;
      x10963 = x10979;
      x10514 = x10514 + 1;
    }
    x10514 = x10514 + 1;
    int x10985 = x10963;
    for (;;) {
      long x10992 = x10514;
      char x10993 = x5[x10992];
      bool x10994 = x10993 != '-';
      bool x10999 = x10994;
      if (x10994) {
        long x10995 = x10514;
        char x10996 = x5[x10995];
        bool x10997 = x10996 != '\n';
        x10999 = x10997;
      }
      bool x11000 = x10999;
      if (!x11000) break;
      x10514 = x10514 + 1;
    }
    x10514 = x10514 + 1;
    for (;;) {
      long x11016 = x10514;
      char x11017 = x5[x11016];
      bool x11018 = x11017 != '-';
      bool x11023 = x11018;
      if (x11018) {
        long x11019 = x10514;
        char x11020 = x5[x11019];
        bool x11021 = x11020 != '\n';
        x11023 = x11021;
      }
      bool x11024 = x11023;
      if (!x11024) break;
      x10514 = x10514 + 1;
    }
    x10514 = x10514 + 1;
    for (;;) {
      long x11040 = x10514;
      char x11041 = x5[x11040];
      bool x11042 = x11041 != '|';
      bool x11047 = x11042;
      if (x11042) {
        long x11043 = x10514;
        char x11044 = x5[x11043];
        bool x11045 = x11044 != '\n';
        x11047 = x11045;
      }
      bool x11048 = x11047;
      if (!x11048) break;
      x10514 = x10514 + 1;
    }
    x10514 = x10514 + 1;
    for (;;) {
      long x11068 = x10514;
      char x11069 = x5[x11068];
      bool x11070 = x11069 != '-';
      bool x11075 = x11070;
      if (x11070) {
        long x11071 = x10514;
        char x11072 = x5[x11071];
        bool x11073 = x11072 != '\n';
        x11075 = x11073;
      }
      bool x11076 = x11075;
      if (!x11076) break;
      x10514 = x10514 + 1;
    }
    x10514 = x10514 + 1;
    for (;;) {
      long x11092 = x10514;
      char x11093 = x5[x11092];
      bool x11094 = x11093 != '-';
      bool x11099 = x11094;
      if (x11094) {
        long x11095 = x10514;
        char x11096 = x5[x11095];
        bool x11097 = x11096 != '\n';
        x11099 = x11097;
      }
      bool x11100 = x11099;
      if (!x11100) break;
      x10514 = x10514 + 1;
    }
    x10514 = x10514 + 1;
    for (;;) {
      long x11116 = x10514;
      char x11117 = x5[x11116];
      bool x11118 = x11117 != '|';
      bool x11123 = x11118;
      if (x11118) {
        long x11119 = x10514;
        char x11120 = x5[x11119];
        bool x11121 = x11120 != '\n';
        x11123 = x11121;
      }
      bool x11124 = x11123;
      if (!x11124) break;
      x10514 = x10514 + 1;
    }
    x10514 = x10514 + 1;
    for (;;) {
      long x11143 = x10514;
      char x11144 = x5[x11143];
      bool x11145 = x11144 != '|';
      bool x11150 = x11145;
      if (x11145) {
        long x11146 = x10514;
        char x11147 = x5[x11146];
        bool x11148 = x11147 != '\n';
        x11150 = x11148;
      }
      bool x11151 = x11150;
      if (!x11151) break;
      x10514 = x10514 + 1;
    }
    x10514 = x10514 + 1;
    for (;;) {
      long x11161 = x10514;
      char x11162 = x5[x11161];
      bool x11163 = x11162 != '|';
      bool x11168 = x11163;
      if (x11163) {
        long x11164 = x10514;
        char x11165 = x5[x11164];
        bool x11166 = x11165 != '\n';
        x11168 = x11166;
      }
      bool x11169 = x11168;
      if (!x11169) break;
      x10514 = x10514 + 1;
    }
    x10514 = x10514 + 1;
    for (;;) {
      long x11179 = x10514;
      char x11180 = x5[x11179];
      bool x11181 = x11180 != '|';
      bool x11186 = x11181;
      if (x11181) {
        long x11182 = x10514;
        char x11183 = x5[x11182];
        bool x11184 = x11183 != '\n';
        x11186 = x11184;
      }
      bool x11187 = x11186;
      if (!x11187) break;
      x10514 = x10514 + 1;
    }
    x10514 = x10514 + 1;
    long x11197 = x10514;
    bool x11198 = x11197 > 0L;
    bool x11204 = x11198;
    if (x11198) {
      long x11199 = x10514;
      long x11200 = x11199 - 1L;
      char x11201 = x5[x11200];
      bool x11202 = x11201 != '\n';
      x11204 = x11202;
    }
    bool x11205 = x11204;
    if (x11205) {
      for (;;) {
        long x11206 = x10514;
        char x11207 = x5[x11206];
        bool x11208 = x11207 != '\n';
        if (!x11208) break;
        x10514 = x10514 + 1;
      }
    } else {
    }
    x10514 = x10514 + 1;
    long x11217 = x10516;
    long x11218 = x10515;
    bool x11219 = x11217 == x11218;
    if (x11219) {
      long x11220 = x11218 * 4L;
      x10515 = x11220;
      printf("buffer.resize %ld\n",x11220);
      int* x11223 = x10518;
      int* x11224 = (int*)realloc(x11223,x11220 * sizeof(int));
      x10518 = x11224;
      int* x11229 = x10522;
      int* x11230 = (int*)realloc(x11229,x11220 * sizeof(int));
      x10522 = x11230;
      double* x11238 = x10528;
      double* x11239 = (double*)realloc(x11238,x11220 * sizeof(double));
      x10528 = x11239;
      double* x11241 = x10530;
      double* x11242 = (double*)realloc(x11241,x11220 * sizeof(double));
      x10530 = x11242;
      long* x11253 = x10538;
      long* x11254 = (long*)realloc(x11253,x11220 * sizeof(long));
      x10538 = x11254;
    } else {
    }
    int* x11273 = x10518;
    x11273[x11217] = x10575;
    int* x11277 = x10522;
    x11277[x11217] = x10623;
    double* x11283 = x10528;
    double x10774 = (double)x10773;
    double x10776 = (double)x10775;
    double x10777 = x10774 / x10776;
    x11283[x11217] = x10777;
    double* x11285 = x10530;
    double x10839 = (double)x10838;
    double x10841 = (double)x10840;
    double x10842 = x10839 / x10841;
    x11285[x11217] = x10842;
    long* x11293 = x10538;
    long x10986 = x10937 * 10000L;
    long x10987 = x10961 * 100L;
    long x10988 = x10986 + x10987;
    long x10989 = x10988 + x10985;
    x11293[x11217] = x10989;
    x10516 = x10516 + 1;
  }
  long x11308 = 0L;
  long x11309 = x7;
  long x11310 = 0L;
  int* x11311 = (int*)malloc(x7 * sizeof(int));
  int* x11312 = x11311;
  int* x11317 = (int*)malloc(x7 * sizeof(int));
  int* x11318 = x11317;
  int x4007 = open("XXXXXcustomer.tbl",0);
  long x4008 = fsize(x4007);
  char* x4009 = mmap(0, x4008, PROT_READ, MAP_FILE | MAP_SHARED, x4007, 0);
  for (;;) {
    long x11327 = x11308;
    bool x11328 = x11327 < x4008;
    if (!x11328) break;
    int x11331 = 0;
    for (;;) {
      long x11332 = x11308;
      char x11333 = x4009[x11332];
      bool x11334 = x11333 != '|';
      bool x11339 = x11334;
      if (x11334) {
        long x11335 = x11308;
        char x11336 = x4009[x11335];
        bool x11337 = x11336 != '\n';
        x11339 = x11337;
      }
      bool x11340 = x11339;
      if (!x11340) break;
      int x11342 = x11331;
      long x11344 = x11308;
      int x11343 = x11342 * 10;
      char x11345 = x4009[x11344];
      char x11346 = x11345 - '0';
      int x11347 = x11343 + x11346;
      x11331 = x11347;
      x11308 = x11308 + 1;
    }
    x11308 = x11308 + 1;
    int x11353 = x11331;
    for (;;) {
      long x11355 = x11308;
      char x11356 = x4009[x11355];
      bool x11357 = x11356 != '|';
      bool x11362 = x11357;
      if (x11357) {
        long x11358 = x11308;
        char x11359 = x4009[x11358];
        bool x11360 = x11359 != '\n';
        x11362 = x11360;
      }
      bool x11363 = x11362;
      if (!x11363) break;
      x11308 = x11308 + 1;
    }
    x11308 = x11308 + 1;
    for (;;) {
      long x11373 = x11308;
      char x11374 = x4009[x11373];
      bool x11375 = x11374 != '|';
      bool x11380 = x11375;
      if (x11375) {
        long x11376 = x11308;
        char x11377 = x4009[x11376];
        bool x11378 = x11377 != '\n';
        x11380 = x11378;
      }
      bool x11381 = x11380;
      if (!x11381) break;
      x11308 = x11308 + 1;
    }
    x11308 = x11308 + 1;
    int x11391 = 0;
    for (;;) {
      long x11392 = x11308;
      char x11393 = x4009[x11392];
      bool x11394 = x11393 != '|';
      bool x11399 = x11394;
      if (x11394) {
        long x11395 = x11308;
        char x11396 = x4009[x11395];
        bool x11397 = x11396 != '\n';
        x11399 = x11397;
      }
      bool x11400 = x11399;
      if (!x11400) break;
      int x11402 = x11391;
      long x11404 = x11308;
      int x11403 = x11402 * 10;
      char x11405 = x4009[x11404];
      char x11406 = x11405 - '0';
      int x11407 = x11403 + x11406;
      x11391 = x11407;
      x11308 = x11308 + 1;
    }
    x11308 = x11308 + 1;
    int x11413 = x11391;
    for (;;) {
      long x11415 = x11308;
      char x11416 = x4009[x11415];
      bool x11417 = x11416 != '|';
      bool x11422 = x11417;
      if (x11417) {
        long x11418 = x11308;
        char x11419 = x4009[x11418];
        bool x11420 = x11419 != '\n';
        x11422 = x11420;
      }
      bool x11423 = x11422;
      if (!x11423) break;
      x11308 = x11308 + 1;
    }
    x11308 = x11308 + 1;
    for (;;) {
      long x11435 = x11308;
      char x11436 = x4009[x11435];
      bool x11437 = x11436 != '.';
      bool x11442 = x11437;
      if (x11437) {
        long x11438 = x11308;
        char x11439 = x4009[x11438];
        bool x11440 = x11439 != '|';
        x11442 = x11440;
      }
      bool x11443 = x11442;
      bool x11448 = x11443;
      if (x11443) {
        long x11444 = x11308;
        char x11445 = x4009[x11444];
        bool x11446 = x11445 != '\n';
        x11448 = x11446;
      }
      bool x11449 = x11448;
      if (!x11449) break;
      x11308 = x11308 + 1;
    }
    long x11461 = x11308;
    char x11462 = x4009[x11461];
    bool x11463 = x11462 == '.';
    if (x11463) {
      x11308 = x11308 + 1;
      for (;;) {
        long x11465 = x11308;
        char x11466 = x4009[x11465];
        bool x11467 = x11466 != '|';
        bool x11472 = x11467;
        if (x11467) {
          long x11468 = x11308;
          char x11469 = x4009[x11468];
          bool x11470 = x11469 != '\n';
          x11472 = x11470;
        }
        bool x11473 = x11472;
        if (!x11473) break;
        x11308 = x11308 + 1;
      }
    } else {
    }
    x11308 = x11308 + 1;
    for (;;) {
      long x11498 = x11308;
      char x11499 = x4009[x11498];
      bool x11500 = x11499 != '|';
      bool x11505 = x11500;
      if (x11500) {
        long x11501 = x11308;
        char x11502 = x4009[x11501];
        bool x11503 = x11502 != '\n';
        x11505 = x11503;
      }
      bool x11506 = x11505;
      if (!x11506) break;
      x11308 = x11308 + 1;
    }
    x11308 = x11308 + 1;
    for (;;) {
      long x11516 = x11308;
      char x11517 = x4009[x11516];
      bool x11518 = x11517 != '|';
      bool x11523 = x11518;
      if (x11518) {
        long x11519 = x11308;
        char x11520 = x4009[x11519];
        bool x11521 = x11520 != '\n';
        x11523 = x11521;
      }
      bool x11524 = x11523;
      if (!x11524) break;
      x11308 = x11308 + 1;
    }
    x11308 = x11308 + 1;
    long x11534 = x11308;
    bool x11535 = x11534 > 0L;
    bool x11541 = x11535;
    if (x11535) {
      long x11536 = x11308;
      long x11537 = x11536 - 1L;
      char x11538 = x4009[x11537];
      bool x11539 = x11538 != '\n';
      x11541 = x11539;
    }
    bool x11542 = x11541;
    if (x11542) {
      for (;;) {
        long x11543 = x11308;
        char x11544 = x4009[x11543];
        bool x11545 = x11544 != '\n';
        if (!x11545) break;
        x11308 = x11308 + 1;
      }
    } else {
    }
    x11308 = x11308 + 1;
    long x11554 = x11310;
    long x11555 = x11309;
    bool x11556 = x11554 == x11555;
    if (x11556) {
      long x11557 = x11555 * 4L;
      x11309 = x11557;
      printf("buffer.resize %ld\n",x11557);
      int* x11560 = x11312;
      int* x11561 = (int*)realloc(x11560,x11557 * sizeof(int));
      x11312 = x11561;
      int* x11569 = x11318;
      int* x11570 = (int*)realloc(x11569,x11557 * sizeof(int));
      x11318 = x11570;
    } else {
    }
    int* x11586 = x11312;
    x11586[x11554] = x11353;
    int* x11592 = x11318;
    x11592[x11554] = x11413;
    x11310 = x11310 + 1;
  }
  long x11605 = 0L;
  long x11606 = x7;
  long x11607 = 0L;
  int* x11608 = (int*)malloc(x7 * sizeof(int));
  int* x11609 = x11608;
  int* x11614 = (int*)malloc(x7 * sizeof(int));
  int* x11615 = x11614;
  int x1908 = open("XXXXXsupplier.tbl",0);
  long x1909 = fsize(x1908);
  char* x1910 = mmap(0, x1909, PROT_READ, MAP_FILE | MAP_SHARED, x1908, 0);
  for (;;) {
    long x11622 = x11605;
    bool x11623 = x11622 < x1909;
    if (!x11623) break;
    int x11626 = 0;
    for (;;) {
      long x11627 = x11605;
      char x11628 = x1910[x11627];
      bool x11629 = x11628 != '|';
      bool x11634 = x11629;
      if (x11629) {
        long x11630 = x11605;
        char x11631 = x1910[x11630];
        bool x11632 = x11631 != '\n';
        x11634 = x11632;
      }
      bool x11635 = x11634;
      if (!x11635) break;
      int x11637 = x11626;
      long x11639 = x11605;
      int x11638 = x11637 * 10;
      char x11640 = x1910[x11639];
      char x11641 = x11640 - '0';
      int x11642 = x11638 + x11641;
      x11626 = x11642;
      x11605 = x11605 + 1;
    }
    x11605 = x11605 + 1;
    int x11648 = x11626;
    for (;;) {
      long x11650 = x11605;
      char x11651 = x1910[x11650];
      bool x11652 = x11651 != '|';
      bool x11657 = x11652;
      if (x11652) {
        long x11653 = x11605;
        char x11654 = x1910[x11653];
        bool x11655 = x11654 != '\n';
        x11657 = x11655;
      }
      bool x11658 = x11657;
      if (!x11658) break;
      x11605 = x11605 + 1;
    }
    x11605 = x11605 + 1;
    for (;;) {
      long x11668 = x11605;
      char x11669 = x1910[x11668];
      bool x11670 = x11669 != '|';
      bool x11675 = x11670;
      if (x11670) {
        long x11671 = x11605;
        char x11672 = x1910[x11671];
        bool x11673 = x11672 != '\n';
        x11675 = x11673;
      }
      bool x11676 = x11675;
      if (!x11676) break;
      x11605 = x11605 + 1;
    }
    x11605 = x11605 + 1;
    int x11686 = 0;
    for (;;) {
      long x11687 = x11605;
      char x11688 = x1910[x11687];
      bool x11689 = x11688 != '|';
      bool x11694 = x11689;
      if (x11689) {
        long x11690 = x11605;
        char x11691 = x1910[x11690];
        bool x11692 = x11691 != '\n';
        x11694 = x11692;
      }
      bool x11695 = x11694;
      if (!x11695) break;
      int x11697 = x11686;
      long x11699 = x11605;
      int x11698 = x11697 * 10;
      char x11700 = x1910[x11699];
      char x11701 = x11700 - '0';
      int x11702 = x11698 + x11701;
      x11686 = x11702;
      x11605 = x11605 + 1;
    }
    x11605 = x11605 + 1;
    int x11708 = x11686;
    for (;;) {
      long x11710 = x11605;
      char x11711 = x1910[x11710];
      bool x11712 = x11711 != '|';
      bool x11717 = x11712;
      if (x11712) {
        long x11713 = x11605;
        char x11714 = x1910[x11713];
        bool x11715 = x11714 != '\n';
        x11717 = x11715;
      }
      bool x11718 = x11717;
      if (!x11718) break;
      x11605 = x11605 + 1;
    }
    x11605 = x11605 + 1;
    for (;;) {
      long x11730 = x11605;
      char x11731 = x1910[x11730];
      bool x11732 = x11731 != '.';
      bool x11737 = x11732;
      if (x11732) {
        long x11733 = x11605;
        char x11734 = x1910[x11733];
        bool x11735 = x11734 != '|';
        x11737 = x11735;
      }
      bool x11738 = x11737;
      bool x11743 = x11738;
      if (x11738) {
        long x11739 = x11605;
        char x11740 = x1910[x11739];
        bool x11741 = x11740 != '\n';
        x11743 = x11741;
      }
      bool x11744 = x11743;
      if (!x11744) break;
      x11605 = x11605 + 1;
    }
    long x11756 = x11605;
    char x11757 = x1910[x11756];
    bool x11758 = x11757 == '.';
    if (x11758) {
      x11605 = x11605 + 1;
      for (;;) {
        long x11760 = x11605;
        char x11761 = x1910[x11760];
        bool x11762 = x11761 != '|';
        bool x11767 = x11762;
        if (x11762) {
          long x11763 = x11605;
          char x11764 = x1910[x11763];
          bool x11765 = x11764 != '\n';
          x11767 = x11765;
        }
        bool x11768 = x11767;
        if (!x11768) break;
        x11605 = x11605 + 1;
      }
    } else {
    }
    x11605 = x11605 + 1;
    for (;;) {
      long x11793 = x11605;
      char x11794 = x1910[x11793];
      bool x11795 = x11794 != '|';
      bool x11800 = x11795;
      if (x11795) {
        long x11796 = x11605;
        char x11797 = x1910[x11796];
        bool x11798 = x11797 != '\n';
        x11800 = x11798;
      }
      bool x11801 = x11800;
      if (!x11801) break;
      x11605 = x11605 + 1;
    }
    x11605 = x11605 + 1;
    long x11811 = x11605;
    bool x11812 = x11811 > 0L;
    bool x11818 = x11812;
    if (x11812) {
      long x11813 = x11605;
      long x11814 = x11813 - 1L;
      char x11815 = x1910[x11814];
      bool x11816 = x11815 != '\n';
      x11818 = x11816;
    }
    bool x11819 = x11818;
    if (x11819) {
      for (;;) {
        long x11820 = x11605;
        char x11821 = x1910[x11820];
        bool x11822 = x11821 != '\n';
        if (!x11822) break;
        x11605 = x11605 + 1;
      }
    } else {
    }
    x11605 = x11605 + 1;
    long x11831 = x11607;
    long x11832 = x11606;
    bool x11833 = x11831 == x11832;
    if (x11833) {
      long x11834 = x11832 * 4L;
      x11606 = x11834;
      printf("buffer.resize %ld\n",x11834);
      int* x11837 = x11609;
      int* x11838 = (int*)realloc(x11837,x11834 * sizeof(int));
      x11609 = x11838;
      int* x11846 = x11615;
      int* x11847 = (int*)realloc(x11846,x11834 * sizeof(int));
      x11615 = x11847;
    } else {
    }
    int* x11860 = x11609;
    x11860[x11831] = x11648;
    int* x11866 = x11615;
    x11866[x11831] = x11708;
    x11607 = x11607 + 1;
  }
  long x2189 = DEFAULT_JOIN_HASH_SIZE;
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  long x2212 = x2189 - 1L;
  long x823 = x808 - 1L;
  bool x1043 = true == false;
  int x11877;
  for(x11877=0; x11877 < 5; x11877++) {
    bool x11878 = false;
    long x11879 = 0L;
    bool x11881 = false;
    long x11882 = 0L;
    int x11886 = 0;
    char* x11887 = "";
    bool x11892 = false;
    long x11893 = 0L;
    int* x11895 = (int*)malloc(x2189 * sizeof(int));
    int* x11896 = x11895;
    char** x11897 = (char**)malloc(x2189 * sizeof(char*));
    char** x11898 = x11897;
    int* x11903 = (int*)malloc(x2189 * sizeof(int));
    int* x11904 = x11903;
    char** x11905 = (char**)malloc(x2189 * sizeof(char*));
    char** x11906 = x11905;
    long x11911 = 0L;
    long* x11912 = (long*)malloc(x2189 * sizeof(long));
    long* x11913 = (long*)malloc(x2189 * sizeof(long));
    long x11914;
    for(x11914=0L; x11914 < x2189; x11914++) {
      x11912[x11914] = -1L;
    }
    bool x11919 = false;
    long x11920 = 0L;
    char** x11925 = (char**)malloc(x2189 * sizeof(char*));
    char** x11926 = x11925;
    int* x11931 = (int*)malloc(x2189 * sizeof(int));
    int* x11932 = x11931;
    char** x11933 = (char**)malloc(x2189 * sizeof(char*));
    char** x11934 = x11933;
    int* x11939 = (int*)malloc(x2189 * sizeof(int));
    int* x11940 = x11939;
    long x11953 = 0L;
    long* x11954 = (long*)malloc(x2189 * sizeof(long));
    long* x11955 = (long*)malloc(x2189 * sizeof(long));
    long x11956;
    for(x11956=0L; x11956 < x2189; x11956++) {
      x11954[x11956] = -1L;
    }
    bool x11961 = false;
    long x11962 = 0L;
    char** x11966 = (char**)malloc(x2189 * sizeof(char*));
    char** x11967 = x11966;
    int* x11972 = (int*)malloc(x2189 * sizeof(int));
    int* x11973 = x11972;
    char** x11974 = (char**)malloc(x2189 * sizeof(char*));
    char** x11975 = x11974;
    int* x11994 = (int*)malloc(x2189 * sizeof(int));
    int* x11995 = x11994;
    double* x12004 = (double*)malloc(x2189 * sizeof(double));
    double* x12005 = x12004;
    double* x12006 = (double*)malloc(x2189 * sizeof(double));
    double* x12007 = x12006;
    long* x12014 = (long*)malloc(x2189 * sizeof(long));
    long* x12015 = x12014;
    long x12026 = 0L;
    long* x12027 = (long*)malloc(x2189 * sizeof(long));
    long* x12028 = (long*)malloc(x2189 * sizeof(long));
    long x12029;
    for(x12029=0L; x12029 < x2189; x12029++) {
      x12027[x12029] = -1L;
    }
    bool x12034 = false;
    long x12035 = 0L;
    int* x12037 = (int*)malloc(x2189 * sizeof(int));
    int* x12038 = x12037;
    int* x12043 = (int*)malloc(x2189 * sizeof(int));
    int* x12044 = x12043;
    long x12053 = 0L;
    long* x12054 = (long*)malloc(x2189 * sizeof(long));
    long* x12055 = (long*)malloc(x2189 * sizeof(long));
    long x12056;
    for(x12056=0L; x12056 < x2189; x12056++) {
      x12054[x12056] = -1L;
    }
    struct Anon197435497* x12062 = (struct Anon197435497*)malloc(x808 * sizeof(struct Anon197435497));
    struct Anon197435497* x12063 = x12062;
    long x12064 = 0L;
    long* x12065 = (long*)malloc(x808 * sizeof(long));
    long x12066;
    for(x12066=0L; x12066 < x808; x12066++) {
      struct Anon197435497* x12067 = x12063;
      struct Anon197435497 x12068 = x12067[x12066];
      struct Anon726278688 x12069 = x12068.key;;
      struct Anon2052879266 x12070 = x12068.aggs;;
      struct Anon197435497 x12071;
      x12071.exists = false;
      x12071.key = x12069;
      x12071.aggs = x12070;
      x12067[x12066] = x12071;
    }
    long x12076 = 1024L;
    long x12077 = 0L;
    struct Anon197435497* x12078 = (struct Anon197435497*)malloc(1024L * sizeof(struct Anon197435497));
    struct Anon197435497* x12079 = x12078;
    long x12081 = 0L;
    struct timeval x12814, x12815, x12816;
    gettimeofday(&x12814, NULL);
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x12083 = x12034;
      bool x12084 = !x12083;
      bool x12089 = x12084;
      if (x12084) {
        long x12085 = x12035;
        long x12086 = x11310;
        bool x12087 = x12085 < x12086;
        x12089 = x12087;
      }
      bool x12090 = x12089;
      if (!x12090) break;
      long x12092 = x12035;
      int* x12093 = x11312;
      int x12094 = x12093[x12092];
      int* x12099 = x11318;
      int x12100 = x12099[x12092];
      x12035 = x12035 + 1;
      long x12111 = x12053;
      int* x12112 = x12038;
      x12112[x12111] = x12094;
      int* x12118 = x12044;
      x12118[x12111] = x12100;
      x12053 = x12053 + 1L;
      long x12129 = x12094 & x2212;
      long x12130 = x12054[x12129];
      x12054[x12129] = x12111;
      x12055[x12111] = x12130;
    }
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x12136 = x11878;
      bool x12137 = !x12136;
      bool x12142 = x12137;
      if (x12137) {
        long x12138 = x11879;
        long x12139 = x9995;
        bool x12140 = x12138 < x12139;
        x12142 = x12140;
      }
      bool x12143 = x12142;
      if (!x12143) break;
      long x12145 = x11879;
      int* x12146 = x9997;
      int x12147 = x12146[x12145];
      char** x12148 = x9999;
      char* x12149 = x12148[x12145];
      x11879 = x11879 + 1;
      x11886 = x12147;
      x11887 = x12149;
      printf("%s\n","begin scan NATION");
      for (;;) {
        bool x12162 = x11881;
        bool x12163 = !x12162;
        bool x12168 = x12163;
        if (x12163) {
          long x12164 = x11882;
          long x12165 = x9995;
          bool x12166 = x12164 < x12165;
          x12168 = x12166;
        }
        bool x12169 = x12168;
        if (!x12169) break;
        long x12171 = x11882;
        int* x12172 = x9997;
        int x12173 = x12172[x12171];
        char** x12174 = x9999;
        char* x12175 = x12174[x12171];
        x11882 = x11882 + 1;
        int x12183 = x11886;
        char* x12184 = x11887;
        bool x12188 = tpch_strcmp(x12184,"FRANCE") == 0;;
        bool x12190 = x12188;
        if (x12188) {
          bool x12189 = tpch_strcmp(x12175,"GERMANY") == 0;;
          x12190 = x12189;
        }
        bool x12191 = x12190;
        bool x12196 = x12191;
        if (x12191 == false) {
          bool x12192 = tpch_strcmp(x12184,"GERMANY") == 0;;
          bool x12194 = x12192;
          if (x12192) {
            bool x12193 = tpch_strcmp(x12175,"FRANCE") == 0;;
            x12194 = x12193;
          }
          bool x12195 = x12194;
          x12196 = x12195;
        }
        bool x12197 = x12196;
        if (x12197) {
          long x12201 = x11911;
          int* x12202 = x11896;
          x12202[x12201] = x12183;
          char** x12204 = x11898;
          x12204[x12201] = x12184;
          int* x12210 = x11904;
          x12210[x12201] = x12173;
          char** x12212 = x11906;
          x12212[x12201] = x12175;
          x11911 = x11911 + 1L;
          long x12219 = x12183 & x2212;
          long x12220 = x11912[x12219];
          x11912[x12219] = x12201;
          x11913[x12201] = x12220;
        } else {
        }
      }
      x11882 = 0L;
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x12231 = x11892;
      bool x12232 = !x12231;
      bool x12237 = x12232;
      if (x12232) {
        long x12233 = x11893;
        long x12234 = x11607;
        bool x12235 = x12233 < x12234;
        x12237 = x12235;
      }
      bool x12238 = x12237;
      if (!x12238) break;
      long x12240 = x11893;
      int* x12241 = x11609;
      int x12242 = x12241[x12240];
      int* x12247 = x11615;
      int x12248 = x12247[x12240];
      x11893 = x11893 + 1;
      long x12257 = x12248 & x2212;
      long x12258 = x11912[x12257];
      long x12259 = x12258;
      long x12319 = x12242 & x2212;
      for (;;) {
        long x12260 = x12259;
        bool x12261 = x12260 != -1;
        if (!x12261) break;
        long x12263 = x12259;
        int* x12264 = x11896;
        int x12265 = x12264[x12263];
        char** x12266 = x11898;
        char* x12267 = x12266[x12263];
        int* x12272 = x11904;
        int x12273 = x12272[x12263];
        char** x12274 = x11906;
        char* x12275 = x12274[x12263];
        long x12281 = x11913[x12263];
        x12259 = x12281;
        bool x12283 = x12265 == x12248;
        if (x12283) {
          long x12287 = x11953;
          char** x12290 = x11926;
          x12290[x12287] = x12267;
          int* x12296 = x11932;
          x12296[x12287] = x12273;
          char** x12298 = x11934;
          x12298[x12287] = x12275;
          int* x12304 = x11940;
          x12304[x12287] = x12242;
          x11953 = x11953 + 1L;
          long x12320 = x11954[x12319];
          x11954[x12319] = x12287;
          x11955[x12287] = x12320;
        } else {
        }
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x12330 = x11919;
      bool x12331 = !x12330;
      bool x12336 = x12331;
      if (x12331) {
        long x12332 = x11920;
        long x12333 = x10516;
        bool x12334 = x12332 < x12333;
        x12336 = x12334;
      }
      bool x12337 = x12336;
      if (!x12337) break;
      long x12339 = x11920;
      int* x12340 = x10518;
      int x12341 = x12340[x12339];
      int* x12344 = x10522;
      int x12345 = x12344[x12339];
      double* x12350 = x10528;
      double x12351 = x12350[x12339];
      double* x12352 = x10530;
      double x12353 = x12352[x12339];
      long* x12360 = x10538;
      long x12361 = x12360[x12339];
      x11920 = x11920 + 1;
      bool x12374 = x12361 >= 19950101L;
      bool x12376 = x12374;
      if (x12374) {
        bool x12375 = x12361 <= 19961231L;
        x12376 = x12375;
      }
      bool x12377 = x12376;
      if (x12377) {
        long x12378 = x12345 & x2212;
        long x12379 = x11954[x12378];
        long x12380 = x12379;
        long x12486 = x12341 & x2212;
        for (;;) {
          long x12381 = x12380;
          bool x12382 = x12381 != -1;
          if (!x12382) break;
          long x12384 = x12380;
          char** x12387 = x11926;
          char* x12388 = x12387[x12384];
          int* x12393 = x11932;
          int x12394 = x12393[x12384];
          char** x12395 = x11934;
          char* x12396 = x12395[x12384];
          int* x12401 = x11940;
          int x12402 = x12401[x12384];
          long x12416 = x11955[x12384];
          x12380 = x12416;
          bool x12418 = x12402 == x12345;
          if (x12418) {
            long x12422 = x12026;
            char** x12425 = x11967;
            x12425[x12422] = x12388;
            int* x12431 = x11973;
            x12431[x12422] = x12394;
            char** x12433 = x11975;
            x12433[x12422] = x12396;
            int* x12453 = x11995;
            x12453[x12422] = x12341;
            double* x12463 = x12005;
            x12463[x12422] = x12351;
            double* x12465 = x12007;
            x12465[x12422] = x12353;
            long* x12473 = x12015;
            x12473[x12422] = x12361;
            x12026 = x12026 + 1L;
            long x12487 = x12027[x12486];
            x12027[x12486] = x12422;
            x12028[x12422] = x12487;
          } else {
          }
        }
      } else {
      }
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x12499 = x11961;
      bool x12500 = !x12499;
      bool x12505 = x12500;
      if (x12500) {
        long x12501 = x11962;
        long x12502 = x10145;
        bool x12503 = x12501 < x12502;
        x12505 = x12503;
      }
      bool x12506 = x12505;
      if (!x12506) break;
      long x12508 = x11962;
      int* x12509 = x10147;
      int x12510 = x12509[x12508];
      int* x12511 = x10149;
      int x12512 = x12511[x12508];
      x11962 = x11962 + 1;
      long x12529 = x12510 & x2212;
      long x12530 = x12027[x12529];
      long x12531 = x12530;
      long x12605 = x12512 & x2212;
      for (;;) {
        long x12532 = x12531;
        bool x12533 = x12532 != -1;
        if (!x12533) break;
        long x12535 = x12531;
        char** x12538 = x11967;
        char* x12539 = x12538[x12535];
        int* x12544 = x11973;
        int x12545 = x12544[x12535];
        char** x12546 = x11975;
        char* x12547 = x12546[x12535];
        int* x12566 = x11995;
        int x12567 = x12566[x12535];
        double* x12576 = x12005;
        double x12577 = x12576[x12535];
        double* x12578 = x12007;
        double x12579 = x12578[x12535];
        long* x12586 = x12015;
        long x12587 = x12586[x12535];
        long x12599 = x12028[x12535];
        x12531 = x12599;
        bool x12601 = x12567 == x12510;
        if (x12601) {
          long x12606 = x12054[x12605];
          long x12607 = x12606;
          long x12638 = x12587; // date
          long x12639 = x12638/10000;
          int x12640 = (int)x12639;
          double x12671 = 1.0 - x12579;
          double x12672 = x12577 * x12671;
          struct Anon726278688 x12641;
          x12641.SUPP_NATION = x12539;
          x12641.CUST_NATION = x12547;
          x12641.L_YEAR = x12640;
          struct Anon2052879266 x12714;
          x12714._0 = x12672;
          struct Anon197435497 x12715;
          x12715.exists = true;
          x12715.key = x12641;
          x12715.aggs = x12714;
          for (;;) {
            long x12608 = x12607;
            bool x12609 = x12608 != -1;
            if (!x12609) break;
            long x12611 = x12607;
            int* x12612 = x12038;
            int x12613 = x12612[x12611];
            int* x12618 = x12044;
            int x12619 = x12618[x12611];
            long x12629 = x12055[x12611];
            x12607 = x12629;
            bool x12631 = x12613 == x12512;
            bool x12633 = x12631;
            if (x12631) {
              bool x12632 = x12619 == x12545;
              x12633 = x12632;
            }
            bool x12634 = x12633;
            if (x12634) {
              long x12642 = hash(x12547, 10L);
              long x12643 = hash(x12539, 10L);
              long x12644 = x12642 * 41L;
              long x12645 = x12644 + x12640;
              long x12646 = x12645 * 41L;
              long x12647 = x12646 + x12643;
              long x12648 = x12647 & x823;
              long x12649 = x12648;
              struct Anon197435497* x12650 = x12063;
              struct Anon197435497 x12651 = x12650[x12648];
              struct Anon197435497 x12652 = x12651;
              bool x12653 = x12651.exists;;
              bool x12667 = x12653;
              if (x12653) {
                struct Anon197435497 x12654 = x12652;
                struct Anon726278688 x12655 = x12654.key;;
                char* x12656 = x12655.SUPP_NATION;;
                bool x12657 = tpch_strcmp(x12656,x12539) == 0;;
                bool x12662 = x12657;
                if (x12657) {
                  char* x12658 = x12655.CUST_NATION;;
                  bool x12659 = tpch_strcmp(x12658,x12547) == 0;;
                  x12662 = x12659;
                }
                bool x12663 = x12662;
                bool x12664 = x12663;
                if (x12663) {
                  int x12660 = x12655.L_YEAR;;
                  bool x12661 = x12660 == x12640;
                  x12664 = x12661;
                }
                bool x12665 = x12664;
                x12667 = x12665;
              }
              bool x12668 = x12667;
              if (x12668) {
                struct Anon2052879266 x12669 = x12651.aggs;;
                struct Anon726278688 x12675 = x12651.key;;
                double x12670 = x12669._0;;
                double x12673 = x12670 + x12672;
                struct Anon2052879266 x12674;
                x12674._0 = x12673;
                struct Anon197435497 x12676;
                x12676.exists = true;
                x12676.key = x12675;
                x12676.aggs = x12674;
                x12650[x12648] = x12676;
              } else {
                for (;;) {
                  struct Anon197435497 x12679 = x12652;
                  bool x12680 = x12679.exists;;
                  bool x12724;
                  if (x12680) {
                    struct Anon726278688 x12681 = x12679.key;;
                    char* x12682 = x12681.SUPP_NATION;;
                    bool x12683 = tpch_strcmp(x12682,x12539) == 0;;
                    bool x12688 = x12683;
                    if (x12683) {
                      char* x12684 = x12681.CUST_NATION;;
                      bool x12685 = tpch_strcmp(x12684,x12547) == 0;;
                      x12688 = x12685;
                    }
                    bool x12689 = x12688;
                    bool x12690 = x12689;
                    if (x12689) {
                      int x12686 = x12681.L_YEAR;;
                      bool x12687 = x12686 == x12640;
                      x12690 = x12687;
                    }
                    bool x12691 = x12690;
                    bool x12711;
                    if (x12691) {
                      struct Anon2052879266 x12692 = x12679.aggs;;
                      long x12696 = x12649;
                      struct Anon197435497* x12698 = x12063;
                      double x12693 = x12692._0;;
                      double x12694 = x12693 + x12672;
                      struct Anon2052879266 x12695;
                      x12695._0 = x12694;
                      struct Anon197435497 x12697;
                      x12697.exists = true;
                      x12697.key = x12681;
                      x12697.aggs = x12695;
                      x12698[x12696] = x12697;
                      x12711 = false;
                    } else {
                      long x12701 = x12649;
                      long x12702 = x12701 + 1L;
                      long x12703 = x12702 & x823;
                      x12649 = x12703;
                      struct Anon197435497* x12705 = x12063;
                      struct Anon197435497 x12706 = x12705[x12703];
                      x12652 = x12706;
                      x12711 = true;
                    }
                    x12724 = x12711;
                  } else {
                    long x12713 = x12649;
                    struct Anon197435497* x12716 = x12063;
                    x12716[x12713] = x12715;
                    long x12718 = x12064;
                    x12065[x12718] = x12713;
                    x12064 = x12064 + 1L;
                    x12724 = false;
                  }
                  if (!x12724) break;
                }
              }
            } else {
            }
          }
        } else {
        }
      }
    }
    long x12741 = x12064;
    long x12743;
    for(x12743=0L; x12743 < x12741; x12743++) {
      long x12744 = x12065[x12743];
      struct Anon197435497* x12745 = x12063;
      struct Anon197435497 x12746 = x12745[x12744];
      long x12747 = x12077;
      long x12748 = x12076;
      bool x12749 = x12747 == x12748;
      if (x12749) {
        long x12750 = x12748 * 4L;
        x12076 = x12750;
        struct Anon197435497* x12752 = x12079;
        struct Anon197435497* x12753 = (struct Anon197435497 *)realloc(x12752,x12750* sizeof(struct Anon197435497));
        x12079 = x12753;
      } else {
      }
      struct Anon197435497* x12757 = x12079;
      x12757[x12747] = x12746;
      x12077 = x12077 + 1;
    }
    long x12762 = x12077;
    struct Anon197435497* x12763 = x12079;
    qsort((void *)x12763,x12762,sizeof(struct Anon197435497), (__compar_fn_t)x12789); // x12790
    long x12792;
    for(x12792=0L; x12792 < x12762; x12792++) {
      struct Anon197435497* x12793 = x12079;
      struct Anon197435497 x12794 = x12793[x12792];
      if (x1043) {
      } else {
        struct Anon726278688 x12797 = x12794.key;;
        struct Anon2052879266 x12803 = x12794.aggs;;
        char* x12798 = x12797.SUPP_NATION;;
        int x12799 = tpch_strlen(x12798);
        char* x12800 = x12797.CUST_NATION;;
        int x12801 = tpch_strlen(x12800);
        int x12802 = x12797.L_YEAR;;
        double x12804 = x12803._0;;
        printf("%.*s|%.*s|%d|%.4f\n",x12799,x12798,x12801,x12800,x12802,x12804);
        x12081 = x12081 + 1L;
      }
    }
    long x12811 = x12081;
    printf("(%ld rows)\n",x12811);
    gettimeofday(&x12815, NULL);
    timeval_subtract(&x12816, &x12815, &x12814);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x12816.tv_sec * 1000) + (x12816.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
