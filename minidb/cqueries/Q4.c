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

struct Anon0 {
struct Anon1732223439 left;
struct Anon168903330 right;
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

struct Anon1052706553 {
bool exists;
int key;
struct Anon1023322325 aggs;
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

struct Anon1395358962 {
int PS_PARTKEY;
int PS_SUPPKEY;
int PS_AVAILQTY;
double PS_SUPPLYCOST;
char* PS_COMMENT;
};

/************************ FUNCTIONS **************************/
int x6358(struct Anon1042493154* x6350, struct Anon1042493154* x6351);
int x6358(struct Anon1042493154* x6350, struct Anon1042493154* x6351) {
  struct Anon1042493154 x6352 = (*x6350);
  struct Anon1042493154 x6353 = (*x6351);
  char* x6354 = x6352.key;;
  char* x6355 = x6353.key;;
  int x6356 = tpch_strcmp(x6354,x6355);
  return x6356;
}

/************************ MAIN BODY **************************/
int main(int x4843, char** x4844) {
  long x4845 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x4846 = x7;
  long x4847 = 0L;
  int* x4848 = (int*)malloc(x7 * sizeof(int));
  int* x4849 = x4848;
  long* x4870 = (long*)malloc(x7 * sizeof(long));
  long* x4871 = x4870;
  long* x4872 = (long*)malloc(x7 * sizeof(long));
  long* x4873 = x4872;
  int x3 = open("XXXXXlineitem.tbl",0);
  long x4 = fsize(x3);
  char* x5 = mmap(0, x4, PROT_READ, MAP_FILE | MAP_SHARED, x3, 0);
  for (;;) {
    long x4880 = x4845;
    bool x4881 = x4880 < x4;
    if (!x4881) break;
    int x4884 = 0;
    for (;;) {
      long x4885 = x4845;
      char x4886 = x5[x4885];
      bool x4887 = x4886 != '|';
      bool x4892 = x4887;
      if (x4887) {
        long x4888 = x4845;
        char x4889 = x5[x4888];
        bool x4890 = x4889 != '\n';
        x4892 = x4890;
      }
      bool x4893 = x4892;
      if (!x4893) break;
      int x4895 = x4884;
      long x4897 = x4845;
      int x4896 = x4895 * 10;
      char x4898 = x5[x4897];
      char x4899 = x4898 - '0';
      int x4900 = x4896 + x4899;
      x4884 = x4900;
      x4845 = x4845 + 1;
    }
    x4845 = x4845 + 1;
    int x4906 = x4884;
    for (;;) {
      long x4909 = x4845;
      char x4910 = x5[x4909];
      bool x4911 = x4910 != '|';
      bool x4916 = x4911;
      if (x4911) {
        long x4912 = x4845;
        char x4913 = x5[x4912];
        bool x4914 = x4913 != '\n';
        x4916 = x4914;
      }
      bool x4917 = x4916;
      if (!x4917) break;
      x4845 = x4845 + 1;
    }
    x4845 = x4845 + 1;
    for (;;) {
      long x4933 = x4845;
      char x4934 = x5[x4933];
      bool x4935 = x4934 != '|';
      bool x4940 = x4935;
      if (x4935) {
        long x4936 = x4845;
        char x4937 = x5[x4936];
        bool x4938 = x4937 != '\n';
        x4940 = x4938;
      }
      bool x4941 = x4940;
      if (!x4941) break;
      x4845 = x4845 + 1;
    }
    x4845 = x4845 + 1;
    for (;;) {
      long x4957 = x4845;
      char x4958 = x5[x4957];
      bool x4959 = x4958 != '|';
      bool x4964 = x4959;
      if (x4959) {
        long x4960 = x4845;
        char x4961 = x5[x4960];
        bool x4962 = x4961 != '\n';
        x4964 = x4962;
      }
      bool x4965 = x4964;
      if (!x4965) break;
      x4845 = x4845 + 1;
    }
    x4845 = x4845 + 1;
    for (;;) {
      long x4982 = x4845;
      char x4983 = x5[x4982];
      bool x4984 = x4983 != '.';
      bool x4989 = x4984;
      if (x4984) {
        long x4985 = x4845;
        char x4986 = x5[x4985];
        bool x4987 = x4986 != '|';
        x4989 = x4987;
      }
      bool x4990 = x4989;
      bool x4995 = x4990;
      if (x4990) {
        long x4991 = x4845;
        char x4992 = x5[x4991];
        bool x4993 = x4992 != '\n';
        x4995 = x4993;
      }
      bool x4996 = x4995;
      if (!x4996) break;
      x4845 = x4845 + 1;
    }
    long x5008 = x4845;
    char x5009 = x5[x5008];
    bool x5010 = x5009 == '.';
    if (x5010) {
      x4845 = x4845 + 1;
      for (;;) {
        long x5012 = x4845;
        char x5013 = x5[x5012];
        bool x5014 = x5013 != '|';
        bool x5019 = x5014;
        if (x5014) {
          long x5015 = x4845;
          char x5016 = x5[x5015];
          bool x5017 = x5016 != '\n';
          x5019 = x5017;
        }
        bool x5020 = x5019;
        if (!x5020) break;
        x4845 = x4845 + 1;
      }
    } else {
    }
    x4845 = x4845 + 1;
    for (;;) {
      long x5047 = x4845;
      char x5048 = x5[x5047];
      bool x5049 = x5048 != '.';
      bool x5054 = x5049;
      if (x5049) {
        long x5050 = x4845;
        char x5051 = x5[x5050];
        bool x5052 = x5051 != '|';
        x5054 = x5052;
      }
      bool x5055 = x5054;
      bool x5060 = x5055;
      if (x5055) {
        long x5056 = x4845;
        char x5057 = x5[x5056];
        bool x5058 = x5057 != '\n';
        x5060 = x5058;
      }
      bool x5061 = x5060;
      if (!x5061) break;
      x4845 = x4845 + 1;
    }
    long x5073 = x4845;
    char x5074 = x5[x5073];
    bool x5075 = x5074 == '.';
    if (x5075) {
      x4845 = x4845 + 1;
      for (;;) {
        long x5077 = x4845;
        char x5078 = x5[x5077];
        bool x5079 = x5078 != '|';
        bool x5084 = x5079;
        if (x5079) {
          long x5080 = x4845;
          char x5081 = x5[x5080];
          bool x5082 = x5081 != '\n';
          x5084 = x5082;
        }
        bool x5085 = x5084;
        if (!x5085) break;
        x4845 = x4845 + 1;
      }
    } else {
    }
    x4845 = x4845 + 1;
    for (;;) {
      long x5112 = x4845;
      char x5113 = x5[x5112];
      bool x5114 = x5113 != '.';
      bool x5119 = x5114;
      if (x5114) {
        long x5115 = x4845;
        char x5116 = x5[x5115];
        bool x5117 = x5116 != '|';
        x5119 = x5117;
      }
      bool x5120 = x5119;
      bool x5125 = x5120;
      if (x5120) {
        long x5121 = x4845;
        char x5122 = x5[x5121];
        bool x5123 = x5122 != '\n';
        x5125 = x5123;
      }
      bool x5126 = x5125;
      if (!x5126) break;
      x4845 = x4845 + 1;
    }
    long x5138 = x4845;
    char x5139 = x5[x5138];
    bool x5140 = x5139 == '.';
    if (x5140) {
      x4845 = x4845 + 1;
      for (;;) {
        long x5142 = x4845;
        char x5143 = x5[x5142];
        bool x5144 = x5143 != '|';
        bool x5149 = x5144;
        if (x5144) {
          long x5145 = x4845;
          char x5146 = x5[x5145];
          bool x5147 = x5146 != '\n';
          x5149 = x5147;
        }
        bool x5150 = x5149;
        if (!x5150) break;
        x4845 = x4845 + 1;
      }
    } else {
    }
    x4845 = x4845 + 1;
    for (;;) {
      long x5177 = x4845;
      char x5178 = x5[x5177];
      bool x5179 = x5178 != '.';
      bool x5184 = x5179;
      if (x5179) {
        long x5180 = x4845;
        char x5181 = x5[x5180];
        bool x5182 = x5181 != '|';
        x5184 = x5182;
      }
      bool x5185 = x5184;
      bool x5190 = x5185;
      if (x5185) {
        long x5186 = x4845;
        char x5187 = x5[x5186];
        bool x5188 = x5187 != '\n';
        x5190 = x5188;
      }
      bool x5191 = x5190;
      if (!x5191) break;
      x4845 = x4845 + 1;
    }
    long x5203 = x4845;
    char x5204 = x5[x5203];
    bool x5205 = x5204 == '.';
    if (x5205) {
      x4845 = x4845 + 1;
      for (;;) {
        long x5207 = x4845;
        char x5208 = x5[x5207];
        bool x5209 = x5208 != '|';
        bool x5214 = x5209;
        if (x5209) {
          long x5210 = x4845;
          char x5211 = x5[x5210];
          bool x5212 = x5211 != '\n';
          x5214 = x5212;
        }
        bool x5215 = x5214;
        if (!x5215) break;
        x4845 = x4845 + 1;
      }
    } else {
    }
    x4845 = x4845 + 1;
    x4845 = x4845 + 2;
    x4845 = x4845 + 2;
    for (;;) {
      long x5247 = x4845;
      char x5248 = x5[x5247];
      bool x5249 = x5248 != '-';
      bool x5254 = x5249;
      if (x5249) {
        long x5250 = x4845;
        char x5251 = x5[x5250];
        bool x5252 = x5251 != '\n';
        x5254 = x5252;
      }
      bool x5255 = x5254;
      if (!x5255) break;
      x4845 = x4845 + 1;
    }
    x4845 = x4845 + 1;
    for (;;) {
      long x5271 = x4845;
      char x5272 = x5[x5271];
      bool x5273 = x5272 != '-';
      bool x5278 = x5273;
      if (x5273) {
        long x5274 = x4845;
        char x5275 = x5[x5274];
        bool x5276 = x5275 != '\n';
        x5278 = x5276;
      }
      bool x5279 = x5278;
      if (!x5279) break;
      x4845 = x4845 + 1;
    }
    x4845 = x4845 + 1;
    for (;;) {
      long x5295 = x4845;
      char x5296 = x5[x5295];
      bool x5297 = x5296 != '|';
      bool x5302 = x5297;
      if (x5297) {
        long x5298 = x4845;
        char x5299 = x5[x5298];
        bool x5300 = x5299 != '\n';
        x5302 = x5300;
      }
      bool x5303 = x5302;
      if (!x5303) break;
      x4845 = x4845 + 1;
    }
    x4845 = x4845 + 1;
    int x5322 = 0;
    for (;;) {
      long x5323 = x4845;
      char x5324 = x5[x5323];
      bool x5325 = x5324 != '-';
      bool x5330 = x5325;
      if (x5325) {
        long x5326 = x4845;
        char x5327 = x5[x5326];
        bool x5328 = x5327 != '\n';
        x5330 = x5328;
      }
      bool x5331 = x5330;
      if (!x5331) break;
      int x5333 = x5322;
      long x5335 = x4845;
      int x5334 = x5333 * 10;
      char x5336 = x5[x5335];
      char x5337 = x5336 - '0';
      int x5338 = x5334 + x5337;
      x5322 = x5338;
      x4845 = x4845 + 1;
    }
    x4845 = x4845 + 1;
    int x5344 = x5322;
    int x5346 = 0;
    for (;;) {
      long x5347 = x4845;
      char x5348 = x5[x5347];
      bool x5349 = x5348 != '-';
      bool x5354 = x5349;
      if (x5349) {
        long x5350 = x4845;
        char x5351 = x5[x5350];
        bool x5352 = x5351 != '\n';
        x5354 = x5352;
      }
      bool x5355 = x5354;
      if (!x5355) break;
      int x5357 = x5346;
      long x5359 = x4845;
      int x5358 = x5357 * 10;
      char x5360 = x5[x5359];
      char x5361 = x5360 - '0';
      int x5362 = x5358 + x5361;
      x5346 = x5362;
      x4845 = x4845 + 1;
    }
    x4845 = x4845 + 1;
    int x5368 = x5346;
    int x5370 = 0;
    for (;;) {
      long x5371 = x4845;
      char x5372 = x5[x5371];
      bool x5373 = x5372 != '|';
      bool x5378 = x5373;
      if (x5373) {
        long x5374 = x4845;
        char x5375 = x5[x5374];
        bool x5376 = x5375 != '\n';
        x5378 = x5376;
      }
      bool x5379 = x5378;
      if (!x5379) break;
      int x5381 = x5370;
      long x5383 = x4845;
      int x5382 = x5381 * 10;
      char x5384 = x5[x5383];
      char x5385 = x5384 - '0';
      int x5386 = x5382 + x5385;
      x5370 = x5386;
      x4845 = x4845 + 1;
    }
    x4845 = x4845 + 1;
    int x5392 = x5370;
    int x5398 = 0;
    for (;;) {
      long x5399 = x4845;
      char x5400 = x5[x5399];
      bool x5401 = x5400 != '-';
      bool x5406 = x5401;
      if (x5401) {
        long x5402 = x4845;
        char x5403 = x5[x5402];
        bool x5404 = x5403 != '\n';
        x5406 = x5404;
      }
      bool x5407 = x5406;
      if (!x5407) break;
      int x5409 = x5398;
      long x5411 = x4845;
      int x5410 = x5409 * 10;
      char x5412 = x5[x5411];
      char x5413 = x5412 - '0';
      int x5414 = x5410 + x5413;
      x5398 = x5414;
      x4845 = x4845 + 1;
    }
    x4845 = x4845 + 1;
    int x5420 = x5398;
    int x5422 = 0;
    for (;;) {
      long x5423 = x4845;
      char x5424 = x5[x5423];
      bool x5425 = x5424 != '-';
      bool x5430 = x5425;
      if (x5425) {
        long x5426 = x4845;
        char x5427 = x5[x5426];
        bool x5428 = x5427 != '\n';
        x5430 = x5428;
      }
      bool x5431 = x5430;
      if (!x5431) break;
      int x5433 = x5422;
      long x5435 = x4845;
      int x5434 = x5433 * 10;
      char x5436 = x5[x5435];
      char x5437 = x5436 - '0';
      int x5438 = x5434 + x5437;
      x5422 = x5438;
      x4845 = x4845 + 1;
    }
    x4845 = x4845 + 1;
    int x5444 = x5422;
    int x5446 = 0;
    for (;;) {
      long x5447 = x4845;
      char x5448 = x5[x5447];
      bool x5449 = x5448 != '|';
      bool x5454 = x5449;
      if (x5449) {
        long x5450 = x4845;
        char x5451 = x5[x5450];
        bool x5452 = x5451 != '\n';
        x5454 = x5452;
      }
      bool x5455 = x5454;
      if (!x5455) break;
      int x5457 = x5446;
      long x5459 = x4845;
      int x5458 = x5457 * 10;
      char x5460 = x5[x5459];
      char x5461 = x5460 - '0';
      int x5462 = x5458 + x5461;
      x5446 = x5462;
      x4845 = x4845 + 1;
    }
    x4845 = x4845 + 1;
    int x5468 = x5446;
    for (;;) {
      long x5474 = x4845;
      char x5475 = x5[x5474];
      bool x5476 = x5475 != '|';
      bool x5481 = x5476;
      if (x5476) {
        long x5477 = x4845;
        char x5478 = x5[x5477];
        bool x5479 = x5478 != '\n';
        x5481 = x5479;
      }
      bool x5482 = x5481;
      if (!x5482) break;
      x4845 = x4845 + 1;
    }
    x4845 = x4845 + 1;
    for (;;) {
      long x5492 = x4845;
      char x5493 = x5[x5492];
      bool x5494 = x5493 != '|';
      bool x5499 = x5494;
      if (x5494) {
        long x5495 = x4845;
        char x5496 = x5[x5495];
        bool x5497 = x5496 != '\n';
        x5499 = x5497;
      }
      bool x5500 = x5499;
      if (!x5500) break;
      x4845 = x4845 + 1;
    }
    x4845 = x4845 + 1;
    for (;;) {
      long x5510 = x4845;
      char x5511 = x5[x5510];
      bool x5512 = x5511 != '|';
      bool x5517 = x5512;
      if (x5512) {
        long x5513 = x4845;
        char x5514 = x5[x5513];
        bool x5515 = x5514 != '\n';
        x5517 = x5515;
      }
      bool x5518 = x5517;
      if (!x5518) break;
      x4845 = x4845 + 1;
    }
    x4845 = x4845 + 1;
    long x5528 = x4845;
    bool x5529 = x5528 > 0L;
    bool x5535 = x5529;
    if (x5529) {
      long x5530 = x4845;
      long x5531 = x5530 - 1L;
      char x5532 = x5[x5531];
      bool x5533 = x5532 != '\n';
      x5535 = x5533;
    }
    bool x5536 = x5535;
    if (x5536) {
      for (;;) {
        long x5537 = x4845;
        char x5538 = x5[x5537];
        bool x5539 = x5538 != '\n';
        if (!x5539) break;
        x4845 = x4845 + 1;
      }
    } else {
    }
    x4845 = x4845 + 1;
    long x5548 = x4847;
    long x5549 = x4846;
    bool x5550 = x5548 == x5549;
    if (x5550) {
      long x5551 = x5549 * 4L;
      x4846 = x5551;
      printf("buffer.resize %ld\n",x5551);
      int* x5554 = x4849;
      int* x5555 = (int*)realloc(x5554,x5551 * sizeof(int));
      x4849 = x5555;
      long* x5587 = x4871;
      long* x5588 = (long*)realloc(x5587,x5551 * sizeof(long));
      x4871 = x5588;
      long* x5590 = x4873;
      long* x5591 = (long*)realloc(x5590,x5551 * sizeof(long));
      x4873 = x5591;
    } else {
    }
    int* x5604 = x4849;
    x5604[x5548] = x4906;
    long* x5626 = x4871;
    long x5393 = x5344 * 10000L;
    long x5394 = x5368 * 100L;
    long x5395 = x5393 + x5394;
    long x5396 = x5395 + x5392;
    x5626[x5548] = x5396;
    long* x5628 = x4873;
    long x5469 = x5420 * 10000L;
    long x5470 = x5444 * 100L;
    long x5471 = x5469 + x5470;
    long x5472 = x5471 + x5468;
    x5628[x5548] = x5472;
    x4847 = x4847 + 1;
  }
  long x5639 = 0L;
  long x5640 = x7;
  long x5641 = 0L;
  int* x5642 = (int*)malloc(x7 * sizeof(int));
  int* x5643 = x5642;
  long* x5650 = (long*)malloc(x7 * sizeof(long));
  long* x5651 = x5650;
  char** x5652 = (char**)malloc(x7 * sizeof(char*));
  char** x5653 = x5652;
  int x3633 = open("XXXXXorders.tbl",0);
  long x3634 = fsize(x3633);
  char* x3635 = mmap(0, x3634, PROT_READ, MAP_FILE | MAP_SHARED, x3633, 0);
  for (;;) {
    long x5660 = x5639;
    bool x5661 = x5660 < x3634;
    if (!x5661) break;
    int x5664 = 0;
    for (;;) {
      long x5665 = x5639;
      char x5666 = x3635[x5665];
      bool x5667 = x5666 != '|';
      bool x5672 = x5667;
      if (x5667) {
        long x5668 = x5639;
        char x5669 = x3635[x5668];
        bool x5670 = x5669 != '\n';
        x5672 = x5670;
      }
      bool x5673 = x5672;
      if (!x5673) break;
      int x5675 = x5664;
      long x5677 = x5639;
      int x5676 = x5675 * 10;
      char x5678 = x3635[x5677];
      char x5679 = x5678 - '0';
      int x5680 = x5676 + x5679;
      x5664 = x5680;
      x5639 = x5639 + 1;
    }
    x5639 = x5639 + 1;
    int x5686 = x5664;
    for (;;) {
      long x5689 = x5639;
      char x5690 = x3635[x5689];
      bool x5691 = x5690 != '|';
      bool x5696 = x5691;
      if (x5691) {
        long x5692 = x5639;
        char x5693 = x3635[x5692];
        bool x5694 = x5693 != '\n';
        x5696 = x5694;
      }
      bool x5697 = x5696;
      if (!x5697) break;
      x5639 = x5639 + 1;
    }
    x5639 = x5639 + 1;
    x5639 = x5639 + 2;
    for (;;) {
      long x5717 = x5639;
      char x5718 = x3635[x5717];
      bool x5719 = x5718 != '.';
      bool x5724 = x5719;
      if (x5719) {
        long x5720 = x5639;
        char x5721 = x3635[x5720];
        bool x5722 = x5721 != '|';
        x5724 = x5722;
      }
      bool x5725 = x5724;
      bool x5730 = x5725;
      if (x5725) {
        long x5726 = x5639;
        char x5727 = x3635[x5726];
        bool x5728 = x5727 != '\n';
        x5730 = x5728;
      }
      bool x5731 = x5730;
      if (!x5731) break;
      x5639 = x5639 + 1;
    }
    long x5743 = x5639;
    char x5744 = x3635[x5743];
    bool x5745 = x5744 == '.';
    if (x5745) {
      x5639 = x5639 + 1;
      for (;;) {
        long x5747 = x5639;
        char x5748 = x3635[x5747];
        bool x5749 = x5748 != '|';
        bool x5754 = x5749;
        if (x5749) {
          long x5750 = x5639;
          char x5751 = x3635[x5750];
          bool x5752 = x5751 != '\n';
          x5754 = x5752;
        }
        bool x5755 = x5754;
        if (!x5755) break;
        x5639 = x5639 + 1;
      }
    } else {
    }
    x5639 = x5639 + 1;
    int x5780 = 0;
    for (;;) {
      long x5781 = x5639;
      char x5782 = x3635[x5781];
      bool x5783 = x5782 != '-';
      bool x5788 = x5783;
      if (x5783) {
        long x5784 = x5639;
        char x5785 = x3635[x5784];
        bool x5786 = x5785 != '\n';
        x5788 = x5786;
      }
      bool x5789 = x5788;
      if (!x5789) break;
      int x5791 = x5780;
      long x5793 = x5639;
      int x5792 = x5791 * 10;
      char x5794 = x3635[x5793];
      char x5795 = x5794 - '0';
      int x5796 = x5792 + x5795;
      x5780 = x5796;
      x5639 = x5639 + 1;
    }
    x5639 = x5639 + 1;
    int x5802 = x5780;
    int x5804 = 0;
    for (;;) {
      long x5805 = x5639;
      char x5806 = x3635[x5805];
      bool x5807 = x5806 != '-';
      bool x5812 = x5807;
      if (x5807) {
        long x5808 = x5639;
        char x5809 = x3635[x5808];
        bool x5810 = x5809 != '\n';
        x5812 = x5810;
      }
      bool x5813 = x5812;
      if (!x5813) break;
      int x5815 = x5804;
      long x5817 = x5639;
      int x5816 = x5815 * 10;
      char x5818 = x3635[x5817];
      char x5819 = x5818 - '0';
      int x5820 = x5816 + x5819;
      x5804 = x5820;
      x5639 = x5639 + 1;
    }
    x5639 = x5639 + 1;
    int x5826 = x5804;
    int x5828 = 0;
    for (;;) {
      long x5829 = x5639;
      char x5830 = x3635[x5829];
      bool x5831 = x5830 != '|';
      bool x5836 = x5831;
      if (x5831) {
        long x5832 = x5639;
        char x5833 = x3635[x5832];
        bool x5834 = x5833 != '\n';
        x5836 = x5834;
      }
      bool x5837 = x5836;
      if (!x5837) break;
      int x5839 = x5828;
      long x5841 = x5639;
      int x5840 = x5839 * 10;
      char x5842 = x3635[x5841];
      char x5843 = x5842 - '0';
      int x5844 = x5840 + x5843;
      x5828 = x5844;
      x5639 = x5639 + 1;
    }
    x5639 = x5639 + 1;
    int x5850 = x5828;
    long x5855 = x5639;
    for (;;) {
      long x5856 = x5639;
      char x5857 = x3635[x5856];
      bool x5858 = x5857 != '|';
      bool x5863 = x5858;
      if (x5858) {
        long x5859 = x5639;
        char x5860 = x3635[x5859];
        bool x5861 = x5860 != '\n';
        x5863 = x5861;
      }
      bool x5864 = x5863;
      if (!x5864) break;
      x5639 = x5639 + 1;
    }
    x5639 = x5639 + 1;
    for (;;) {
      long x5874 = x5639;
      char x5875 = x3635[x5874];
      bool x5876 = x5875 != '|';
      bool x5881 = x5876;
      if (x5876) {
        long x5877 = x5639;
        char x5878 = x3635[x5877];
        bool x5879 = x5878 != '\n';
        x5881 = x5879;
      }
      bool x5882 = x5881;
      if (!x5882) break;
      x5639 = x5639 + 1;
    }
    x5639 = x5639 + 1;
    for (;;) {
      long x5893 = x5639;
      char x5894 = x3635[x5893];
      bool x5895 = x5894 != '|';
      bool x5900 = x5895;
      if (x5895) {
        long x5896 = x5639;
        char x5897 = x3635[x5896];
        bool x5898 = x5897 != '\n';
        x5900 = x5898;
      }
      bool x5901 = x5900;
      if (!x5901) break;
      x5639 = x5639 + 1;
    }
    x5639 = x5639 + 1;
    for (;;) {
      long x5916 = x5639;
      char x5917 = x3635[x5916];
      bool x5918 = x5917 != '|';
      bool x5923 = x5918;
      if (x5918) {
        long x5919 = x5639;
        char x5920 = x3635[x5919];
        bool x5921 = x5920 != '\n';
        x5923 = x5921;
      }
      bool x5924 = x5923;
      if (!x5924) break;
      x5639 = x5639 + 1;
    }
    x5639 = x5639 + 1;
    long x5934 = x5639;
    bool x5935 = x5934 > 0L;
    bool x5941 = x5935;
    if (x5935) {
      long x5936 = x5639;
      long x5937 = x5936 - 1L;
      char x5938 = x3635[x5937];
      bool x5939 = x5938 != '\n';
      x5941 = x5939;
    }
    bool x5942 = x5941;
    if (x5942) {
      for (;;) {
        long x5943 = x5639;
        char x5944 = x3635[x5943];
        bool x5945 = x5944 != '\n';
        if (!x5945) break;
        x5639 = x5639 + 1;
      }
    } else {
    }
    x5639 = x5639 + 1;
    long x5954 = x5641;
    long x5955 = x5640;
    bool x5956 = x5954 == x5955;
    if (x5956) {
      long x5957 = x5955 * 4L;
      x5640 = x5957;
      printf("buffer.resize %ld\n",x5957);
      int* x5960 = x5643;
      int* x5961 = (int*)realloc(x5960,x5957 * sizeof(int));
      x5643 = x5961;
      long* x5972 = x5651;
      long* x5973 = (long*)realloc(x5972,x5957 * sizeof(long));
      x5651 = x5973;
      char** x5975 = x5653;
      char** x5976 = (char**)realloc(x5975,x5957 * sizeof(char*));
      x5653 = x5976;
    } else {
    }
    int* x5989 = x5643;
    x5989[x5954] = x5686;
    long* x5997 = x5651;
    long x5851 = x5802 * 10000L;
    long x5852 = x5826 * 100L;
    long x5853 = x5851 + x5852;
    long x5854 = x5853 + x5850;
    x5997[x5954] = x5854;
    char** x5999 = x5653;
    char* x5872 = x3635+x5855;
    x5999[x5954] = x5872;
    x5641 = x5641 + 1;
  }
  long x2189 = DEFAULT_JOIN_HASH_SIZE;
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  long x2212 = x2189 - 1L;
  long x823 = x808 - 1L;
  struct Anon2052879266 x6304;
  x6304._0 = 1.0;
  bool x1043 = true == false;
  int x6010;
  for(x6010=0; x6010 < 5; x6010++) {
    bool x6011 = false;
    long x6012 = 0L;
    bool x6014 = false;
    long x6015 = 0L;
    int* x6018 = (int*)malloc(x2189 * sizeof(int));
    int* x6019 = x6018;
    long x6050 = 0L;
    long* x6051 = (long*)malloc(x2189 * sizeof(long));
    long* x6052 = (long*)malloc(x2189 * sizeof(long));
    long x6053;
    for(x6053=0L; x6053 < x2189; x6053++) {
      x6051[x6053] = -1L;
    }
    struct Anon1042493154* x6058 = (struct Anon1042493154*)malloc(x808 * sizeof(struct Anon1042493154));
    struct Anon1042493154* x6059 = x6058;
    long x6060 = 0L;
    long* x6061 = (long*)malloc(x808 * sizeof(long));
    long x6062;
    for(x6062=0L; x6062 < x808; x6062++) {
      struct Anon1042493154* x6063 = x6059;
      struct Anon1042493154 x6064 = x6063[x6062];
      char* x6065 = x6064.key;;
      struct Anon2052879266 x6066 = x6064.aggs;;
      struct Anon1042493154 x6067;
      x6067.exists = false;
      x6067.key = x6065;
      x6067.aggs = x6066;
      x6063[x6062] = x6067;
    }
    long x6072 = 1024L;
    long x6073 = 0L;
    struct Anon1042493154* x6074 = (struct Anon1042493154*)malloc(1024L * sizeof(struct Anon1042493154));
    struct Anon1042493154* x6075 = x6074;
    long x6077 = 0L;
    struct timeval x6379, x6380, x6381;
    gettimeofday(&x6379, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x6079 = x6014;
      bool x6080 = !x6079;
      bool x6085 = x6080;
      if (x6080) {
        long x6081 = x6015;
        long x6082 = x4847;
        bool x6083 = x6081 < x6082;
        x6085 = x6083;
      }
      bool x6086 = x6085;
      if (!x6086) break;
      long x6088 = x6015;
      int* x6089 = x4849;
      int x6090 = x6089[x6088];
      long* x6111 = x4871;
      long x6112 = x6111[x6088];
      long* x6113 = x4873;
      long x6114 = x6113[x6088];
      x6015 = x6015 + 1;
      bool x6123 = x6112 < x6114;
      if (x6123) {
        long x6124 = x6050;
        int* x6125 = x6019;
        x6125[x6124] = x6090;
        x6050 = x6050 + 1L;
        long x6158 = x6090 & x2212;
        long x6159 = x6051[x6158];
        x6051[x6158] = x6124;
        x6052[x6124] = x6159;
      } else {
      }
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x6167 = x6011;
      bool x6168 = !x6167;
      bool x6173 = x6168;
      if (x6168) {
        long x6169 = x6012;
        long x6170 = x5641;
        bool x6171 = x6169 < x6170;
        x6173 = x6171;
      }
      bool x6174 = x6173;
      if (!x6174) break;
      long x6176 = x6012;
      int* x6177 = x5643;
      int x6178 = x6177[x6176];
      long* x6185 = x5651;
      long x6186 = x6185[x6176];
      char** x6187 = x5653;
      char* x6188 = x6187[x6176];
      x6012 = x6012 + 1;
      bool x6197 = x6186 < 19931001L;
      bool x6199 = x6197;
      if (x6197) {
        bool x6198 = x6186 >= 19930701L;
        x6199 = x6198;
      }
      bool x6200 = x6199;
      if (x6200) {
        long x6201 = x6178 & x2212;
        long x6202 = x6051[x6201];
        long x6203 = x6202;
        bool x6204 = x6202 == -1L;
        bool x6205 = x6204;
        for (;;) {
          bool x6206 = x6205;
          bool x6207 = !x6206;
          if (!x6207) break;
          long x6209 = x6203;
          int* x6210 = x6019;
          int x6211 = x6210[x6209];
          bool x6243 = x6178 == x6211;
          if (x6243) {
            x6205 = true;
          } else {
            long x6246 = x6052[x6209];
            x6203 = x6246;
            bool x6248 = x6246 == -1;
            x6205 = x6248;
          }
        }
        long x6254 = x6203;
        bool x6256 = x6254 == -1;
        if (x6256) {
        } else {
          long x6257 = hash(x6188, 10L);
          long x6258 = x6257 & x823;
          long x6259 = x6258;
          struct Anon1042493154* x6260 = x6059;
          struct Anon1042493154 x6261 = x6260[x6258];
          struct Anon1042493154 x6262 = x6261;
          bool x6263 = x6261.exists;;
          bool x6268 = x6263;
          if (x6263) {
            struct Anon1042493154 x6264 = x6262;
            char* x6265 = x6264.key;;
            bool x6266 = tpch_strcmp(x6265,x6188) == 0;;
            x6268 = x6266;
          }
          bool x6269 = x6268;
          if (x6269) {
            struct Anon2052879266 x6270 = x6261.aggs;;
            char* x6274 = x6261.key;;
            double x6271 = x6270._0;;
            double x6272 = x6271 + 1.0;
            struct Anon2052879266 x6273;
            x6273._0 = x6272;
            struct Anon1042493154 x6275;
            x6275.exists = true;
            x6275.key = x6274;
            x6275.aggs = x6273;
            x6260[x6258] = x6275;
          } else {
            struct Anon1042493154 x6305;
            x6305.exists = true;
            x6305.key = x6188;
            x6305.aggs = x6304;
            for (;;) {
              struct Anon1042493154 x6278 = x6262;
              bool x6279 = x6278.exists;;
              bool x6314;
              if (x6279) {
                char* x6280 = x6278.key;;
                bool x6281 = tpch_strcmp(x6280,x6188) == 0;;
                bool x6301;
                if (x6281) {
                  struct Anon2052879266 x6282 = x6278.aggs;;
                  long x6286 = x6259;
                  struct Anon1042493154* x6288 = x6059;
                  double x6283 = x6282._0;;
                  double x6284 = x6283 + 1.0;
                  struct Anon2052879266 x6285;
                  x6285._0 = x6284;
                  struct Anon1042493154 x6287;
                  x6287.exists = true;
                  x6287.key = x6280;
                  x6287.aggs = x6285;
                  x6288[x6286] = x6287;
                  x6301 = false;
                } else {
                  long x6291 = x6259;
                  long x6292 = x6291 + 1L;
                  long x6293 = x6292 & x823;
                  x6259 = x6293;
                  struct Anon1042493154* x6295 = x6059;
                  struct Anon1042493154 x6296 = x6295[x6293];
                  x6262 = x6296;
                  x6301 = true;
                }
                x6314 = x6301;
              } else {
                long x6303 = x6259;
                struct Anon1042493154* x6306 = x6059;
                x6306[x6303] = x6305;
                long x6308 = x6060;
                x6061[x6308] = x6303;
                x6060 = x6060 + 1L;
                x6314 = false;
              }
              if (!x6314) break;
            }
          }
        }
      } else {
      }
    }
    long x6327 = x6060;
    long x6329;
    for(x6329=0L; x6329 < x6327; x6329++) {
      long x6330 = x6061[x6329];
      struct Anon1042493154* x6331 = x6059;
      struct Anon1042493154 x6332 = x6331[x6330];
      long x6333 = x6073;
      long x6334 = x6072;
      bool x6335 = x6333 == x6334;
      if (x6335) {
        long x6336 = x6334 * 4L;
        x6072 = x6336;
        struct Anon1042493154* x6338 = x6075;
        struct Anon1042493154* x6339 = (struct Anon1042493154 *)realloc(x6338,x6336* sizeof(struct Anon1042493154));
        x6075 = x6339;
      } else {
      }
      struct Anon1042493154* x6343 = x6075;
      x6343[x6333] = x6332;
      x6073 = x6073 + 1;
    }
    long x6348 = x6073;
    struct Anon1042493154* x6349 = x6075;
    qsort((void *)x6349,x6348,sizeof(struct Anon1042493154), (__compar_fn_t)x6358); // x6359
    long x6361;
    for(x6361=0L; x6361 < x6348; x6361++) {
      struct Anon1042493154* x6362 = x6075;
      struct Anon1042493154 x6363 = x6362[x6361];
      if (x1043) {
      } else {
        char* x6366 = x6363.key;;
        struct Anon2052879266 x6368 = x6363.aggs;;
        int x6367 = tpch_strlen(x6366);
        double x6369 = x6368._0;;
        printf("%.*s|%.0f\n",x6367,x6366,x6369);
        x6077 = x6077 + 1L;
      }
    }
    long x6376 = x6077;
    printf("(%ld rows)\n",x6376);
    gettimeofday(&x6380, NULL);
    timeval_subtract(&x6381, &x6380, &x6379);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x6381.tv_sec * 1000) + (x6381.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
