/*****************************************
  Emitting C Generated Code                  
*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <glib.h>
#include <sys/time.h>
int strcmp(const char *s1, const char *s2);
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

        while ((c = *str++) && len--)
          hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
      }
      size_t strlen(const char* str) {
        const char* start = str;
        while (*str != '\n' && (*str != '|') && (*str != '\0')) str++;
        return str - start;
      }
      int strcmp(const char *s1, const char *s2) {
        size_t l1 = strlen(s1);
        size_t l2 = strlen(s2);
        if (l1 != l2) return l2 - l1;
        return strncmp(s1,s2,l1);
      }
      char* strstr(const char *s1, const char *s2) {
        return strnstr(s1,s2,strlen(s1));
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

struct Anon842992833 {
bool exists;
int key;
struct Anon1023322325 aggs;
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

struct Anon1465150758 {
int L_ORDERKEY;
long O_ORDERDATE;
int O_SHIPPRIORITY;
};

struct Anon546410247 {
char* N_NAME;
int N_NATIONKEY;
int O_ORDERKEY;
};

struct Anon2052879266 {
double _0;
};

struct Anon532638341 {
bool exists;
struct Anon1465150758 key;
struct Anon2052879266 aggs;
};

struct Anon1078540535 {
char* N_NAME;
int N_NATIONKEY;
};

struct Anon1285873738 {
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

struct Anon348455037 {
char* N_NAME;
int N_NATIONKEY;
int L_SUPPKEY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
};

struct Anon0 {
struct Anon1268892766 left;
struct Anon348455037 right;
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

struct Anon625264174 {
char L_RETURNFLAG;
char L_LINESTATUS;
};

struct Anon1931420570 {
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

struct Anon1519494783 {
struct Anon625264174 key;
struct Anon1296044246 aggs;
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

struct Anon1395358962 {
int PS_PARTKEY;
int PS_SUPPKEY;
int PS_AVAILQTY;
double PS_SUPPLYCOST;
char* PS_COMMENT;
};

struct Anon801061462 {
bool exists;
char* key;
struct Anon2052879266 aggs;
};

/************************ FUNCTIONS **************************/

/************************ MAIN BODY **************************/
int main(int x5968, char** x5969) {
  long x5970 = 0L;
  long x6 = DEFAULT_INPUT_SIZE;
  long x5971 = x6;
  long x5972 = 0L;
  int* x5973 = (int*)malloc(x6 * sizeof(int));
  int* x5974 = x5973;
  int* x5977 = (int*)malloc(x6 * sizeof(int));
  int* x5978 = x5977;
  double* x5983 = (double*)malloc(x6 * sizeof(double));
  double* x5984 = x5983;
  double* x5985 = (double*)malloc(x6 * sizeof(double));
  double* x5986 = x5985;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  long x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    long x6005 = x5970;
    bool x6006 = x6005 < x3;
    if (!x6006) break;
    int x6009 = 0;
    for (;;) {
      long x6010 = x5970;
      char x6011 = x4[x6010];
      bool x6012 = x6011 != '|';
      bool x6017 = x6012;
      if (x6012) {
        long x6013 = x5970;
        char x6014 = x4[x6013];
        bool x6015 = x6014 != '\n';
        x6017 = x6015;
      }
      bool x6018 = x6017;
      if (!x6018) break;
      int x6020 = x6009;
      long x6022 = x5970;
      int x6021 = x6020 * 10;
      char x6023 = x4[x6022];
      char x6024 = x6023 - '0';
      int x6025 = x6021 + x6024;
      x6009 = x6025;
      x5970 = x5970 + 1;
    }
    x5970 = x5970 + 1;
    int x6031 = x6009;
    for (;;) {
      long x6034 = x5970;
      char x6035 = x4[x6034];
      bool x6036 = x6035 != '|';
      bool x6041 = x6036;
      if (x6036) {
        long x6037 = x5970;
        char x6038 = x4[x6037];
        bool x6039 = x6038 != '\n';
        x6041 = x6039;
      }
      bool x6042 = x6041;
      if (!x6042) break;
      x5970 = x5970 + 1;
    }
    x5970 = x5970 + 1;
    int x6057 = 0;
    for (;;) {
      long x6058 = x5970;
      char x6059 = x4[x6058];
      bool x6060 = x6059 != '|';
      bool x6065 = x6060;
      if (x6060) {
        long x6061 = x5970;
        char x6062 = x4[x6061];
        bool x6063 = x6062 != '\n';
        x6065 = x6063;
      }
      bool x6066 = x6065;
      if (!x6066) break;
      int x6068 = x6057;
      long x6070 = x5970;
      int x6069 = x6068 * 10;
      char x6071 = x4[x6070];
      char x6072 = x6071 - '0';
      int x6073 = x6069 + x6072;
      x6057 = x6073;
      x5970 = x5970 + 1;
    }
    x5970 = x5970 + 1;
    int x6079 = x6057;
    for (;;) {
      long x6082 = x5970;
      char x6083 = x4[x6082];
      bool x6084 = x6083 != '|';
      bool x6089 = x6084;
      if (x6084) {
        long x6085 = x5970;
        char x6086 = x4[x6085];
        bool x6087 = x6086 != '\n';
        x6089 = x6087;
      }
      bool x6090 = x6089;
      if (!x6090) break;
      x5970 = x5970 + 1;
    }
    x5970 = x5970 + 1;
    for (;;) {
      long x6107 = x5970;
      char x6108 = x4[x6107];
      bool x6109 = x6108 != '.';
      bool x6114 = x6109;
      if (x6109) {
        long x6110 = x5970;
        char x6111 = x4[x6110];
        bool x6112 = x6111 != '|';
        x6114 = x6112;
      }
      bool x6115 = x6114;
      bool x6120 = x6115;
      if (x6115) {
        long x6116 = x5970;
        char x6117 = x4[x6116];
        bool x6118 = x6117 != '\n';
        x6120 = x6118;
      }
      bool x6121 = x6120;
      if (!x6121) break;
      x5970 = x5970 + 1;
    }
    long x6133 = x5970;
    char x6134 = x4[x6133];
    bool x6135 = x6134 == '.';
    if (x6135) {
      x5970 = x5970 + 1;
      for (;;) {
        long x6137 = x5970;
        char x6138 = x4[x6137];
        bool x6139 = x6138 != '|';
        bool x6144 = x6139;
        if (x6139) {
          long x6140 = x5970;
          char x6141 = x4[x6140];
          bool x6142 = x6141 != '\n';
          x6144 = x6142;
        }
        bool x6145 = x6144;
        if (!x6145) break;
        x5970 = x5970 + 1;
      }
    } else {
    }
    x5970 = x5970 + 1;
    int x6170 = 0;
    int x6171 = 1;
    for (;;) {
      long x6172 = x5970;
      char x6173 = x4[x6172];
      bool x6174 = x6173 != '.';
      bool x6179 = x6174;
      if (x6174) {
        long x6175 = x5970;
        char x6176 = x4[x6175];
        bool x6177 = x6176 != '|';
        x6179 = x6177;
      }
      bool x6180 = x6179;
      bool x6185 = x6180;
      if (x6180) {
        long x6181 = x5970;
        char x6182 = x4[x6181];
        bool x6183 = x6182 != '\n';
        x6185 = x6183;
      }
      bool x6186 = x6185;
      if (!x6186) break;
      int x6188 = x6170;
      long x6190 = x5970;
      int x6189 = x6188 * 10;
      char x6191 = x4[x6190];
      char x6192 = x6191 - '0';
      int x6193 = x6189 + x6192;
      x6170 = x6193;
      x5970 = x5970 + 1;
    }
    long x6198 = x5970;
    char x6199 = x4[x6198];
    bool x6200 = x6199 == '.';
    if (x6200) {
      x5970 = x5970 + 1;
      for (;;) {
        long x6202 = x5970;
        char x6203 = x4[x6202];
        bool x6204 = x6203 != '|';
        bool x6209 = x6204;
        if (x6204) {
          long x6205 = x5970;
          char x6206 = x4[x6205];
          bool x6207 = x6206 != '\n';
          x6209 = x6207;
        }
        bool x6210 = x6209;
        if (!x6210) break;
        int x6212 = x6170;
        long x6214 = x5970;
        int x6213 = x6212 * 10;
        char x6215 = x4[x6214];
        char x6216 = x6215 - '0';
        int x6217 = x6213 + x6216;
        x6170 = x6217;
        int x6219 = x6171;
        int x6220 = x6219 * 10;
        x6171 = x6220;
        x5970 = x5970 + 1;
      }
    } else {
    }
    x5970 = x5970 + 1;
    int x6229 = x6170;
    int x6231 = x6171;
    int x6235 = 0;
    int x6236 = 1;
    for (;;) {
      long x6237 = x5970;
      char x6238 = x4[x6237];
      bool x6239 = x6238 != '.';
      bool x6244 = x6239;
      if (x6239) {
        long x6240 = x5970;
        char x6241 = x4[x6240];
        bool x6242 = x6241 != '|';
        x6244 = x6242;
      }
      bool x6245 = x6244;
      bool x6250 = x6245;
      if (x6245) {
        long x6246 = x5970;
        char x6247 = x4[x6246];
        bool x6248 = x6247 != '\n';
        x6250 = x6248;
      }
      bool x6251 = x6250;
      if (!x6251) break;
      int x6253 = x6235;
      long x6255 = x5970;
      int x6254 = x6253 * 10;
      char x6256 = x4[x6255];
      char x6257 = x6256 - '0';
      int x6258 = x6254 + x6257;
      x6235 = x6258;
      x5970 = x5970 + 1;
    }
    long x6263 = x5970;
    char x6264 = x4[x6263];
    bool x6265 = x6264 == '.';
    if (x6265) {
      x5970 = x5970 + 1;
      for (;;) {
        long x6267 = x5970;
        char x6268 = x4[x6267];
        bool x6269 = x6268 != '|';
        bool x6274 = x6269;
        if (x6269) {
          long x6270 = x5970;
          char x6271 = x4[x6270];
          bool x6272 = x6271 != '\n';
          x6274 = x6272;
        }
        bool x6275 = x6274;
        if (!x6275) break;
        int x6277 = x6235;
        long x6279 = x5970;
        int x6278 = x6277 * 10;
        char x6280 = x4[x6279];
        char x6281 = x6280 - '0';
        int x6282 = x6278 + x6281;
        x6235 = x6282;
        int x6284 = x6236;
        int x6285 = x6284 * 10;
        x6236 = x6285;
        x5970 = x5970 + 1;
      }
    } else {
    }
    x5970 = x5970 + 1;
    int x6294 = x6235;
    int x6296 = x6236;
    for (;;) {
      long x6302 = x5970;
      char x6303 = x4[x6302];
      bool x6304 = x6303 != '.';
      bool x6309 = x6304;
      if (x6304) {
        long x6305 = x5970;
        char x6306 = x4[x6305];
        bool x6307 = x6306 != '|';
        x6309 = x6307;
      }
      bool x6310 = x6309;
      bool x6315 = x6310;
      if (x6310) {
        long x6311 = x5970;
        char x6312 = x4[x6311];
        bool x6313 = x6312 != '\n';
        x6315 = x6313;
      }
      bool x6316 = x6315;
      if (!x6316) break;
      x5970 = x5970 + 1;
    }
    long x6328 = x5970;
    char x6329 = x4[x6328];
    bool x6330 = x6329 == '.';
    if (x6330) {
      x5970 = x5970 + 1;
      for (;;) {
        long x6332 = x5970;
        char x6333 = x4[x6332];
        bool x6334 = x6333 != '|';
        bool x6339 = x6334;
        if (x6334) {
          long x6335 = x5970;
          char x6336 = x4[x6335];
          bool x6337 = x6336 != '\n';
          x6339 = x6337;
        }
        bool x6340 = x6339;
        if (!x6340) break;
        x5970 = x5970 + 1;
      }
    } else {
    }
    x5970 = x5970 + 1;
    x5970 = x5970 + 2;
    x5970 = x5970 + 2;
    for (;;) {
      long x6372 = x5970;
      char x6373 = x4[x6372];
      bool x6374 = x6373 != '-';
      bool x6379 = x6374;
      if (x6374) {
        long x6375 = x5970;
        char x6376 = x4[x6375];
        bool x6377 = x6376 != '\n';
        x6379 = x6377;
      }
      bool x6380 = x6379;
      if (!x6380) break;
      x5970 = x5970 + 1;
    }
    x5970 = x5970 + 1;
    for (;;) {
      long x6396 = x5970;
      char x6397 = x4[x6396];
      bool x6398 = x6397 != '-';
      bool x6403 = x6398;
      if (x6398) {
        long x6399 = x5970;
        char x6400 = x4[x6399];
        bool x6401 = x6400 != '\n';
        x6403 = x6401;
      }
      bool x6404 = x6403;
      if (!x6404) break;
      x5970 = x5970 + 1;
    }
    x5970 = x5970 + 1;
    for (;;) {
      long x6420 = x5970;
      char x6421 = x4[x6420];
      bool x6422 = x6421 != '|';
      bool x6427 = x6422;
      if (x6422) {
        long x6423 = x5970;
        char x6424 = x4[x6423];
        bool x6425 = x6424 != '\n';
        x6427 = x6425;
      }
      bool x6428 = x6427;
      if (!x6428) break;
      x5970 = x5970 + 1;
    }
    x5970 = x5970 + 1;
    for (;;) {
      long x6448 = x5970;
      char x6449 = x4[x6448];
      bool x6450 = x6449 != '-';
      bool x6455 = x6450;
      if (x6450) {
        long x6451 = x5970;
        char x6452 = x4[x6451];
        bool x6453 = x6452 != '\n';
        x6455 = x6453;
      }
      bool x6456 = x6455;
      if (!x6456) break;
      x5970 = x5970 + 1;
    }
    x5970 = x5970 + 1;
    for (;;) {
      long x6472 = x5970;
      char x6473 = x4[x6472];
      bool x6474 = x6473 != '-';
      bool x6479 = x6474;
      if (x6474) {
        long x6475 = x5970;
        char x6476 = x4[x6475];
        bool x6477 = x6476 != '\n';
        x6479 = x6477;
      }
      bool x6480 = x6479;
      if (!x6480) break;
      x5970 = x5970 + 1;
    }
    x5970 = x5970 + 1;
    for (;;) {
      long x6496 = x5970;
      char x6497 = x4[x6496];
      bool x6498 = x6497 != '|';
      bool x6503 = x6498;
      if (x6498) {
        long x6499 = x5970;
        char x6500 = x4[x6499];
        bool x6501 = x6500 != '\n';
        x6503 = x6501;
      }
      bool x6504 = x6503;
      if (!x6504) break;
      x5970 = x5970 + 1;
    }
    x5970 = x5970 + 1;
    for (;;) {
      long x6524 = x5970;
      char x6525 = x4[x6524];
      bool x6526 = x6525 != '-';
      bool x6531 = x6526;
      if (x6526) {
        long x6527 = x5970;
        char x6528 = x4[x6527];
        bool x6529 = x6528 != '\n';
        x6531 = x6529;
      }
      bool x6532 = x6531;
      if (!x6532) break;
      x5970 = x5970 + 1;
    }
    x5970 = x5970 + 1;
    for (;;) {
      long x6548 = x5970;
      char x6549 = x4[x6548];
      bool x6550 = x6549 != '-';
      bool x6555 = x6550;
      if (x6550) {
        long x6551 = x5970;
        char x6552 = x4[x6551];
        bool x6553 = x6552 != '\n';
        x6555 = x6553;
      }
      bool x6556 = x6555;
      if (!x6556) break;
      x5970 = x5970 + 1;
    }
    x5970 = x5970 + 1;
    for (;;) {
      long x6572 = x5970;
      char x6573 = x4[x6572];
      bool x6574 = x6573 != '|';
      bool x6579 = x6574;
      if (x6574) {
        long x6575 = x5970;
        char x6576 = x4[x6575];
        bool x6577 = x6576 != '\n';
        x6579 = x6577;
      }
      bool x6580 = x6579;
      if (!x6580) break;
      x5970 = x5970 + 1;
    }
    x5970 = x5970 + 1;
    for (;;) {
      long x6599 = x5970;
      char x6600 = x4[x6599];
      bool x6601 = x6600 != '|';
      bool x6606 = x6601;
      if (x6601) {
        long x6602 = x5970;
        char x6603 = x4[x6602];
        bool x6604 = x6603 != '\n';
        x6606 = x6604;
      }
      bool x6607 = x6606;
      if (!x6607) break;
      x5970 = x5970 + 1;
    }
    x5970 = x5970 + 1;
    for (;;) {
      long x6617 = x5970;
      char x6618 = x4[x6617];
      bool x6619 = x6618 != '|';
      bool x6624 = x6619;
      if (x6619) {
        long x6620 = x5970;
        char x6621 = x4[x6620];
        bool x6622 = x6621 != '\n';
        x6624 = x6622;
      }
      bool x6625 = x6624;
      if (!x6625) break;
      x5970 = x5970 + 1;
    }
    x5970 = x5970 + 1;
    for (;;) {
      long x6635 = x5970;
      char x6636 = x4[x6635];
      bool x6637 = x6636 != '|';
      bool x6642 = x6637;
      if (x6637) {
        long x6638 = x5970;
        char x6639 = x4[x6638];
        bool x6640 = x6639 != '\n';
        x6642 = x6640;
      }
      bool x6643 = x6642;
      if (!x6643) break;
      x5970 = x5970 + 1;
    }
    x5970 = x5970 + 1;
    long x6653 = x5972;
    long x6654 = x5971;
    bool x6655 = x6653 == x6654;
    if (x6655) {
      long x6656 = x6654 * 4L;
      x5971 = x6656;
      printf("buffer.resize %d\n",x6656);
      int* x6659 = x5974;
      int* x6660 = (int*)realloc(x6659,x6656 * sizeof(int));
      x5974 = x6660;
      int* x6665 = x5978;
      int* x6666 = (int*)realloc(x6665,x6656 * sizeof(int));
      x5978 = x6666;
      double* x6674 = x5984;
      double* x6675 = (double*)realloc(x6674,x6656 * sizeof(double));
      x5984 = x6675;
      double* x6677 = x5986;
      double* x6678 = (double*)realloc(x6677,x6656 * sizeof(double));
      x5986 = x6678;
    } else {
    }
    int* x6709 = x5974;
    x6709[x6653] = x6031;
    int* x6713 = x5978;
    x6713[x6653] = x6079;
    double* x6719 = x5984;
    double x6230 = (double)x6229;
    double x6232 = (double)x6231;
    double x6233 = x6230 / x6232;
    x6719[x6653] = x6233;
    double* x6721 = x5986;
    double x6295 = (double)x6294;
    double x6297 = (double)x6296;
    double x6298 = x6295 / x6297;
    x6721[x6653] = x6298;
    x5972 = x5972 + 1;
  }
  long x6744 = 0L;
  long x6745 = x6;
  long x6746 = 0L;
  int* x6747 = (int*)malloc(x6 * sizeof(int));
  int* x6748 = x6747;
  char** x6749 = (char**)malloc(x6 * sizeof(char*));
  char** x6750 = x6749;
  int* x6751 = (int*)malloc(x6 * sizeof(int));
  int* x6752 = x6751;
  int x1515 = open("../databases/sf2/nation.tbl",0);
  long x1516 = fsize(x1515);
  char* x1517 = mmap(0, x1516, PROT_READ, MAP_FILE | MAP_SHARED, x1515, 0);
  for (;;) {
    long x6755 = x6744;
    bool x6756 = x6755 < x1516;
    if (!x6756) break;
    int x6759 = 0;
    for (;;) {
      long x6760 = x6744;
      char x6761 = x1517[x6760];
      bool x6762 = x6761 != '|';
      bool x6767 = x6762;
      if (x6762) {
        long x6763 = x6744;
        char x6764 = x1517[x6763];
        bool x6765 = x6764 != '\n';
        x6767 = x6765;
      }
      bool x6768 = x6767;
      if (!x6768) break;
      int x6770 = x6759;
      long x6772 = x6744;
      int x6771 = x6770 * 10;
      char x6773 = x1517[x6772];
      char x6774 = x6773 - '0';
      int x6775 = x6771 + x6774;
      x6759 = x6775;
      x6744 = x6744 + 1;
    }
    x6744 = x6744 + 1;
    int x6781 = x6759;
    long x6782 = x6744;
    for (;;) {
      long x6783 = x6744;
      char x6784 = x1517[x6783];
      bool x6785 = x6784 != '|';
      bool x6790 = x6785;
      if (x6785) {
        long x6786 = x6744;
        char x6787 = x1517[x6786];
        bool x6788 = x6787 != '\n';
        x6790 = x6788;
      }
      bool x6791 = x6790;
      if (!x6791) break;
      x6744 = x6744 + 1;
    }
    x6744 = x6744 + 1;
    int x6801 = 0;
    for (;;) {
      long x6802 = x6744;
      char x6803 = x1517[x6802];
      bool x6804 = x6803 != '|';
      bool x6809 = x6804;
      if (x6804) {
        long x6805 = x6744;
        char x6806 = x1517[x6805];
        bool x6807 = x6806 != '\n';
        x6809 = x6807;
      }
      bool x6810 = x6809;
      if (!x6810) break;
      int x6812 = x6801;
      long x6814 = x6744;
      int x6813 = x6812 * 10;
      char x6815 = x1517[x6814];
      char x6816 = x6815 - '0';
      int x6817 = x6813 + x6816;
      x6801 = x6817;
      x6744 = x6744 + 1;
    }
    x6744 = x6744 + 1;
    int x6823 = x6801;
    for (;;) {
      long x6825 = x6744;
      char x6826 = x1517[x6825];
      bool x6827 = x6826 != '|';
      bool x6832 = x6827;
      if (x6827) {
        long x6828 = x6744;
        char x6829 = x1517[x6828];
        bool x6830 = x6829 != '\n';
        x6832 = x6830;
      }
      bool x6833 = x6832;
      if (!x6833) break;
      x6744 = x6744 + 1;
    }
    x6744 = x6744 + 1;
    long x6843 = x6746;
    long x6844 = x6745;
    bool x6845 = x6843 == x6844;
    if (x6845) {
      long x6846 = x6844 * 4L;
      x6745 = x6846;
      printf("buffer.resize %d\n",x6846);
      int* x6849 = x6748;
      int* x6850 = (int*)realloc(x6849,x6846 * sizeof(int));
      x6748 = x6850;
      char** x6852 = x6750;
      char** x6853 = (char**)realloc(x6852,x6846 * sizeof(char*));
      x6750 = x6853;
      int* x6855 = x6752;
      int* x6856 = (int*)realloc(x6855,x6846 * sizeof(int));
      x6752 = x6856;
    } else {
    }
    int* x6863 = x6748;
    x6863[x6843] = x6781;
    char** x6865 = x6750;
    char* x6799 = x1517+x6782;
    x6865[x6843] = x6799;
    int* x6867 = x6752;
    x6867[x6843] = x6823;
    x6746 = x6746 + 1;
  }
  long x6874 = 0L;
  long x6875 = x6;
  long x6876 = 0L;
  int* x6877 = (int*)malloc(x6 * sizeof(int));
  int* x6878 = x6877;
  int* x6883 = (int*)malloc(x6 * sizeof(int));
  int* x6884 = x6883;
  int x3725 = open("../databases/sf2/customer.tbl",0);
  long x3726 = fsize(x3725);
  char* x3727 = mmap(0, x3726, PROT_READ, MAP_FILE | MAP_SHARED, x3725, 0);
  for (;;) {
    long x6893 = x6874;
    bool x6894 = x6893 < x3726;
    if (!x6894) break;
    int x6897 = 0;
    for (;;) {
      long x6898 = x6874;
      char x6899 = x3727[x6898];
      bool x6900 = x6899 != '|';
      bool x6905 = x6900;
      if (x6900) {
        long x6901 = x6874;
        char x6902 = x3727[x6901];
        bool x6903 = x6902 != '\n';
        x6905 = x6903;
      }
      bool x6906 = x6905;
      if (!x6906) break;
      int x6908 = x6897;
      long x6910 = x6874;
      int x6909 = x6908 * 10;
      char x6911 = x3727[x6910];
      char x6912 = x6911 - '0';
      int x6913 = x6909 + x6912;
      x6897 = x6913;
      x6874 = x6874 + 1;
    }
    x6874 = x6874 + 1;
    int x6919 = x6897;
    for (;;) {
      long x6921 = x6874;
      char x6922 = x3727[x6921];
      bool x6923 = x6922 != '|';
      bool x6928 = x6923;
      if (x6923) {
        long x6924 = x6874;
        char x6925 = x3727[x6924];
        bool x6926 = x6925 != '\n';
        x6928 = x6926;
      }
      bool x6929 = x6928;
      if (!x6929) break;
      x6874 = x6874 + 1;
    }
    x6874 = x6874 + 1;
    for (;;) {
      long x6939 = x6874;
      char x6940 = x3727[x6939];
      bool x6941 = x6940 != '|';
      bool x6946 = x6941;
      if (x6941) {
        long x6942 = x6874;
        char x6943 = x3727[x6942];
        bool x6944 = x6943 != '\n';
        x6946 = x6944;
      }
      bool x6947 = x6946;
      if (!x6947) break;
      x6874 = x6874 + 1;
    }
    x6874 = x6874 + 1;
    int x6957 = 0;
    for (;;) {
      long x6958 = x6874;
      char x6959 = x3727[x6958];
      bool x6960 = x6959 != '|';
      bool x6965 = x6960;
      if (x6960) {
        long x6961 = x6874;
        char x6962 = x3727[x6961];
        bool x6963 = x6962 != '\n';
        x6965 = x6963;
      }
      bool x6966 = x6965;
      if (!x6966) break;
      int x6968 = x6957;
      long x6970 = x6874;
      int x6969 = x6968 * 10;
      char x6971 = x3727[x6970];
      char x6972 = x6971 - '0';
      int x6973 = x6969 + x6972;
      x6957 = x6973;
      x6874 = x6874 + 1;
    }
    x6874 = x6874 + 1;
    int x6979 = x6957;
    for (;;) {
      long x6981 = x6874;
      char x6982 = x3727[x6981];
      bool x6983 = x6982 != '|';
      bool x6988 = x6983;
      if (x6983) {
        long x6984 = x6874;
        char x6985 = x3727[x6984];
        bool x6986 = x6985 != '\n';
        x6988 = x6986;
      }
      bool x6989 = x6988;
      if (!x6989) break;
      x6874 = x6874 + 1;
    }
    x6874 = x6874 + 1;
    for (;;) {
      long x7001 = x6874;
      char x7002 = x3727[x7001];
      bool x7003 = x7002 != '.';
      bool x7008 = x7003;
      if (x7003) {
        long x7004 = x6874;
        char x7005 = x3727[x7004];
        bool x7006 = x7005 != '|';
        x7008 = x7006;
      }
      bool x7009 = x7008;
      bool x7014 = x7009;
      if (x7009) {
        long x7010 = x6874;
        char x7011 = x3727[x7010];
        bool x7012 = x7011 != '\n';
        x7014 = x7012;
      }
      bool x7015 = x7014;
      if (!x7015) break;
      x6874 = x6874 + 1;
    }
    long x7027 = x6874;
    char x7028 = x3727[x7027];
    bool x7029 = x7028 == '.';
    if (x7029) {
      x6874 = x6874 + 1;
      for (;;) {
        long x7031 = x6874;
        char x7032 = x3727[x7031];
        bool x7033 = x7032 != '|';
        bool x7038 = x7033;
        if (x7033) {
          long x7034 = x6874;
          char x7035 = x3727[x7034];
          bool x7036 = x7035 != '\n';
          x7038 = x7036;
        }
        bool x7039 = x7038;
        if (!x7039) break;
        x6874 = x6874 + 1;
      }
    } else {
    }
    x6874 = x6874 + 1;
    for (;;) {
      long x7064 = x6874;
      char x7065 = x3727[x7064];
      bool x7066 = x7065 != '|';
      bool x7071 = x7066;
      if (x7066) {
        long x7067 = x6874;
        char x7068 = x3727[x7067];
        bool x7069 = x7068 != '\n';
        x7071 = x7069;
      }
      bool x7072 = x7071;
      if (!x7072) break;
      x6874 = x6874 + 1;
    }
    x6874 = x6874 + 1;
    for (;;) {
      long x7082 = x6874;
      char x7083 = x3727[x7082];
      bool x7084 = x7083 != '|';
      bool x7089 = x7084;
      if (x7084) {
        long x7085 = x6874;
        char x7086 = x3727[x7085];
        bool x7087 = x7086 != '\n';
        x7089 = x7087;
      }
      bool x7090 = x7089;
      if (!x7090) break;
      x6874 = x6874 + 1;
    }
    x6874 = x6874 + 1;
    long x7100 = x6876;
    long x7101 = x6875;
    bool x7102 = x7100 == x7101;
    if (x7102) {
      long x7103 = x7101 * 4L;
      x6875 = x7103;
      printf("buffer.resize %d\n",x7103);
      int* x7106 = x6878;
      int* x7107 = (int*)realloc(x7106,x7103 * sizeof(int));
      x6878 = x7107;
      int* x7115 = x6884;
      int* x7116 = (int*)realloc(x7115,x7103 * sizeof(int));
      x6884 = x7116;
    } else {
    }
    int* x7132 = x6878;
    x7132[x7100] = x6919;
    int* x7138 = x6884;
    x7138[x7100] = x6979;
    x6876 = x6876 + 1;
  }
  long x7151 = 0L;
  long x7152 = x6;
  long x7153 = 0L;
  int* x7154 = (int*)malloc(x6 * sizeof(int));
  int* x7155 = x7154;
  int* x7160 = (int*)malloc(x6 * sizeof(int));
  int* x7161 = x7160;
  int x1750 = open("../databases/sf2/supplier.tbl",0);
  long x1751 = fsize(x1750);
  char* x1752 = mmap(0, x1751, PROT_READ, MAP_FILE | MAP_SHARED, x1750, 0);
  for (;;) {
    long x7168 = x7151;
    bool x7169 = x7168 < x1751;
    if (!x7169) break;
    int x7172 = 0;
    for (;;) {
      long x7173 = x7151;
      char x7174 = x1752[x7173];
      bool x7175 = x7174 != '|';
      bool x7180 = x7175;
      if (x7175) {
        long x7176 = x7151;
        char x7177 = x1752[x7176];
        bool x7178 = x7177 != '\n';
        x7180 = x7178;
      }
      bool x7181 = x7180;
      if (!x7181) break;
      int x7183 = x7172;
      long x7185 = x7151;
      int x7184 = x7183 * 10;
      char x7186 = x1752[x7185];
      char x7187 = x7186 - '0';
      int x7188 = x7184 + x7187;
      x7172 = x7188;
      x7151 = x7151 + 1;
    }
    x7151 = x7151 + 1;
    int x7194 = x7172;
    for (;;) {
      long x7196 = x7151;
      char x7197 = x1752[x7196];
      bool x7198 = x7197 != '|';
      bool x7203 = x7198;
      if (x7198) {
        long x7199 = x7151;
        char x7200 = x1752[x7199];
        bool x7201 = x7200 != '\n';
        x7203 = x7201;
      }
      bool x7204 = x7203;
      if (!x7204) break;
      x7151 = x7151 + 1;
    }
    x7151 = x7151 + 1;
    for (;;) {
      long x7214 = x7151;
      char x7215 = x1752[x7214];
      bool x7216 = x7215 != '|';
      bool x7221 = x7216;
      if (x7216) {
        long x7217 = x7151;
        char x7218 = x1752[x7217];
        bool x7219 = x7218 != '\n';
        x7221 = x7219;
      }
      bool x7222 = x7221;
      if (!x7222) break;
      x7151 = x7151 + 1;
    }
    x7151 = x7151 + 1;
    int x7232 = 0;
    for (;;) {
      long x7233 = x7151;
      char x7234 = x1752[x7233];
      bool x7235 = x7234 != '|';
      bool x7240 = x7235;
      if (x7235) {
        long x7236 = x7151;
        char x7237 = x1752[x7236];
        bool x7238 = x7237 != '\n';
        x7240 = x7238;
      }
      bool x7241 = x7240;
      if (!x7241) break;
      int x7243 = x7232;
      long x7245 = x7151;
      int x7244 = x7243 * 10;
      char x7246 = x1752[x7245];
      char x7247 = x7246 - '0';
      int x7248 = x7244 + x7247;
      x7232 = x7248;
      x7151 = x7151 + 1;
    }
    x7151 = x7151 + 1;
    int x7254 = x7232;
    for (;;) {
      long x7256 = x7151;
      char x7257 = x1752[x7256];
      bool x7258 = x7257 != '|';
      bool x7263 = x7258;
      if (x7258) {
        long x7259 = x7151;
        char x7260 = x1752[x7259];
        bool x7261 = x7260 != '\n';
        x7263 = x7261;
      }
      bool x7264 = x7263;
      if (!x7264) break;
      x7151 = x7151 + 1;
    }
    x7151 = x7151 + 1;
    for (;;) {
      long x7276 = x7151;
      char x7277 = x1752[x7276];
      bool x7278 = x7277 != '.';
      bool x7283 = x7278;
      if (x7278) {
        long x7279 = x7151;
        char x7280 = x1752[x7279];
        bool x7281 = x7280 != '|';
        x7283 = x7281;
      }
      bool x7284 = x7283;
      bool x7289 = x7284;
      if (x7284) {
        long x7285 = x7151;
        char x7286 = x1752[x7285];
        bool x7287 = x7286 != '\n';
        x7289 = x7287;
      }
      bool x7290 = x7289;
      if (!x7290) break;
      x7151 = x7151 + 1;
    }
    long x7302 = x7151;
    char x7303 = x1752[x7302];
    bool x7304 = x7303 == '.';
    if (x7304) {
      x7151 = x7151 + 1;
      for (;;) {
        long x7306 = x7151;
        char x7307 = x1752[x7306];
        bool x7308 = x7307 != '|';
        bool x7313 = x7308;
        if (x7308) {
          long x7309 = x7151;
          char x7310 = x1752[x7309];
          bool x7311 = x7310 != '\n';
          x7313 = x7311;
        }
        bool x7314 = x7313;
        if (!x7314) break;
        x7151 = x7151 + 1;
      }
    } else {
    }
    x7151 = x7151 + 1;
    for (;;) {
      long x7339 = x7151;
      char x7340 = x1752[x7339];
      bool x7341 = x7340 != '|';
      bool x7346 = x7341;
      if (x7341) {
        long x7342 = x7151;
        char x7343 = x1752[x7342];
        bool x7344 = x7343 != '\n';
        x7346 = x7344;
      }
      bool x7347 = x7346;
      if (!x7347) break;
      x7151 = x7151 + 1;
    }
    x7151 = x7151 + 1;
    long x7357 = x7153;
    long x7358 = x7152;
    bool x7359 = x7357 == x7358;
    if (x7359) {
      long x7360 = x7358 * 4L;
      x7152 = x7360;
      printf("buffer.resize %d\n",x7360);
      int* x7363 = x7155;
      int* x7364 = (int*)realloc(x7363,x7360 * sizeof(int));
      x7155 = x7364;
      int* x7372 = x7161;
      int* x7373 = (int*)realloc(x7372,x7360 * sizeof(int));
      x7161 = x7373;
    } else {
    }
    int* x7386 = x7155;
    x7386[x7357] = x7194;
    int* x7392 = x7161;
    x7392[x7357] = x7254;
    x7153 = x7153 + 1;
  }
  long x7403 = 0L;
  long x7404 = x6;
  long x7405 = 0L;
  int* x7406 = (int*)malloc(x6 * sizeof(int));
  int* x7407 = x7406;
  char** x7408 = (char**)malloc(x6 * sizeof(char*));
  char** x7409 = x7408;
  int x1648 = open("../databases/sf2/region.tbl",0);
  long x1649 = fsize(x1648);
  char* x1650 = mmap(0, x1649, PROT_READ, MAP_FILE | MAP_SHARED, x1648, 0);
  for (;;) {
    long x7412 = x7403;
    bool x7413 = x7412 < x1649;
    if (!x7413) break;
    int x7416 = 0;
    for (;;) {
      long x7417 = x7403;
      char x7418 = x1650[x7417];
      bool x7419 = x7418 != '|';
      bool x7424 = x7419;
      if (x7419) {
        long x7420 = x7403;
        char x7421 = x1650[x7420];
        bool x7422 = x7421 != '\n';
        x7424 = x7422;
      }
      bool x7425 = x7424;
      if (!x7425) break;
      int x7427 = x7416;
      long x7429 = x7403;
      int x7428 = x7427 * 10;
      char x7430 = x1650[x7429];
      char x7431 = x7430 - '0';
      int x7432 = x7428 + x7431;
      x7416 = x7432;
      x7403 = x7403 + 1;
    }
    x7403 = x7403 + 1;
    int x7438 = x7416;
    long x7439 = x7403;
    for (;;) {
      long x7440 = x7403;
      char x7441 = x1650[x7440];
      bool x7442 = x7441 != '|';
      bool x7447 = x7442;
      if (x7442) {
        long x7443 = x7403;
        char x7444 = x1650[x7443];
        bool x7445 = x7444 != '\n';
        x7447 = x7445;
      }
      bool x7448 = x7447;
      if (!x7448) break;
      x7403 = x7403 + 1;
    }
    x7403 = x7403 + 1;
    for (;;) {
      long x7458 = x7403;
      char x7459 = x1650[x7458];
      bool x7460 = x7459 != '|';
      bool x7465 = x7460;
      if (x7460) {
        long x7461 = x7403;
        char x7462 = x1650[x7461];
        bool x7463 = x7462 != '\n';
        x7465 = x7463;
      }
      bool x7466 = x7465;
      if (!x7466) break;
      x7403 = x7403 + 1;
    }
    x7403 = x7403 + 1;
    long x7476 = x7405;
    long x7477 = x7404;
    bool x7478 = x7476 == x7477;
    if (x7478) {
      long x7479 = x7477 * 4L;
      x7404 = x7479;
      printf("buffer.resize %d\n",x7479);
      int* x7482 = x7407;
      int* x7483 = (int*)realloc(x7482,x7479 * sizeof(int));
      x7407 = x7483;
      char** x7485 = x7409;
      char** x7486 = (char**)realloc(x7485,x7479 * sizeof(char*));
      x7409 = x7486;
    } else {
    }
    int* x7493 = x7407;
    x7493[x7476] = x7438;
    char** x7495 = x7409;
    char* x7456 = x1650+x7439;
    x7495[x7476] = x7456;
    x7405 = x7405 + 1;
  }
  long x7502 = 0L;
  long x7503 = x6;
  long x7504 = 0L;
  int* x7505 = (int*)malloc(x6 * sizeof(int));
  int* x7506 = x7505;
  int* x7507 = (int*)malloc(x6 * sizeof(int));
  int* x7508 = x7507;
  long* x7513 = (long*)malloc(x6 * sizeof(long));
  long* x7514 = x7513;
  int x3371 = open("../databases/sf2/orders.tbl",0);
  long x3372 = fsize(x3371);
  char* x3373 = mmap(0, x3372, PROT_READ, MAP_FILE | MAP_SHARED, x3371, 0);
  for (;;) {
    long x7523 = x7502;
    bool x7524 = x7523 < x3372;
    if (!x7524) break;
    int x7527 = 0;
    for (;;) {
      long x7528 = x7502;
      char x7529 = x3373[x7528];
      bool x7530 = x7529 != '|';
      bool x7535 = x7530;
      if (x7530) {
        long x7531 = x7502;
        char x7532 = x3373[x7531];
        bool x7533 = x7532 != '\n';
        x7535 = x7533;
      }
      bool x7536 = x7535;
      if (!x7536) break;
      int x7538 = x7527;
      long x7540 = x7502;
      int x7539 = x7538 * 10;
      char x7541 = x3373[x7540];
      char x7542 = x7541 - '0';
      int x7543 = x7539 + x7542;
      x7527 = x7543;
      x7502 = x7502 + 1;
    }
    x7502 = x7502 + 1;
    int x7549 = x7527;
    int x7551 = 0;
    for (;;) {
      long x7552 = x7502;
      char x7553 = x3373[x7552];
      bool x7554 = x7553 != '|';
      bool x7559 = x7554;
      if (x7554) {
        long x7555 = x7502;
        char x7556 = x3373[x7555];
        bool x7557 = x7556 != '\n';
        x7559 = x7557;
      }
      bool x7560 = x7559;
      if (!x7560) break;
      int x7562 = x7551;
      long x7564 = x7502;
      int x7563 = x7562 * 10;
      char x7565 = x3373[x7564];
      char x7566 = x7565 - '0';
      int x7567 = x7563 + x7566;
      x7551 = x7567;
      x7502 = x7502 + 1;
    }
    x7502 = x7502 + 1;
    int x7573 = x7551;
    x7502 = x7502 + 2;
    for (;;) {
      long x7580 = x7502;
      char x7581 = x3373[x7580];
      bool x7582 = x7581 != '.';
      bool x7587 = x7582;
      if (x7582) {
        long x7583 = x7502;
        char x7584 = x3373[x7583];
        bool x7585 = x7584 != '|';
        x7587 = x7585;
      }
      bool x7588 = x7587;
      bool x7593 = x7588;
      if (x7588) {
        long x7589 = x7502;
        char x7590 = x3373[x7589];
        bool x7591 = x7590 != '\n';
        x7593 = x7591;
      }
      bool x7594 = x7593;
      if (!x7594) break;
      x7502 = x7502 + 1;
    }
    long x7606 = x7502;
    char x7607 = x3373[x7606];
    bool x7608 = x7607 == '.';
    if (x7608) {
      x7502 = x7502 + 1;
      for (;;) {
        long x7610 = x7502;
        char x7611 = x3373[x7610];
        bool x7612 = x7611 != '|';
        bool x7617 = x7612;
        if (x7612) {
          long x7613 = x7502;
          char x7614 = x3373[x7613];
          bool x7615 = x7614 != '\n';
          x7617 = x7615;
        }
        bool x7618 = x7617;
        if (!x7618) break;
        x7502 = x7502 + 1;
      }
    } else {
    }
    x7502 = x7502 + 1;
    int x7643 = 0;
    for (;;) {
      long x7644 = x7502;
      char x7645 = x3373[x7644];
      bool x7646 = x7645 != '-';
      bool x7651 = x7646;
      if (x7646) {
        long x7647 = x7502;
        char x7648 = x3373[x7647];
        bool x7649 = x7648 != '\n';
        x7651 = x7649;
      }
      bool x7652 = x7651;
      if (!x7652) break;
      int x7654 = x7643;
      long x7656 = x7502;
      int x7655 = x7654 * 10;
      char x7657 = x3373[x7656];
      char x7658 = x7657 - '0';
      int x7659 = x7655 + x7658;
      x7643 = x7659;
      x7502 = x7502 + 1;
    }
    x7502 = x7502 + 1;
    int x7665 = x7643;
    int x7667 = 0;
    for (;;) {
      long x7668 = x7502;
      char x7669 = x3373[x7668];
      bool x7670 = x7669 != '-';
      bool x7675 = x7670;
      if (x7670) {
        long x7671 = x7502;
        char x7672 = x3373[x7671];
        bool x7673 = x7672 != '\n';
        x7675 = x7673;
      }
      bool x7676 = x7675;
      if (!x7676) break;
      int x7678 = x7667;
      long x7680 = x7502;
      int x7679 = x7678 * 10;
      char x7681 = x3373[x7680];
      char x7682 = x7681 - '0';
      int x7683 = x7679 + x7682;
      x7667 = x7683;
      x7502 = x7502 + 1;
    }
    x7502 = x7502 + 1;
    int x7689 = x7667;
    int x7691 = 0;
    for (;;) {
      long x7692 = x7502;
      char x7693 = x3373[x7692];
      bool x7694 = x7693 != '|';
      bool x7699 = x7694;
      if (x7694) {
        long x7695 = x7502;
        char x7696 = x3373[x7695];
        bool x7697 = x7696 != '\n';
        x7699 = x7697;
      }
      bool x7700 = x7699;
      if (!x7700) break;
      int x7702 = x7691;
      long x7704 = x7502;
      int x7703 = x7702 * 10;
      char x7705 = x3373[x7704];
      char x7706 = x7705 - '0';
      int x7707 = x7703 + x7706;
      x7691 = x7707;
      x7502 = x7502 + 1;
    }
    x7502 = x7502 + 1;
    int x7713 = x7691;
    for (;;) {
      long x7719 = x7502;
      char x7720 = x3373[x7719];
      bool x7721 = x7720 != '|';
      bool x7726 = x7721;
      if (x7721) {
        long x7722 = x7502;
        char x7723 = x3373[x7722];
        bool x7724 = x7723 != '\n';
        x7726 = x7724;
      }
      bool x7727 = x7726;
      if (!x7727) break;
      x7502 = x7502 + 1;
    }
    x7502 = x7502 + 1;
    for (;;) {
      long x7737 = x7502;
      char x7738 = x3373[x7737];
      bool x7739 = x7738 != '|';
      bool x7744 = x7739;
      if (x7739) {
        long x7740 = x7502;
        char x7741 = x3373[x7740];
        bool x7742 = x7741 != '\n';
        x7744 = x7742;
      }
      bool x7745 = x7744;
      if (!x7745) break;
      x7502 = x7502 + 1;
    }
    x7502 = x7502 + 1;
    for (;;) {
      long x7756 = x7502;
      char x7757 = x3373[x7756];
      bool x7758 = x7757 != '|';
      bool x7763 = x7758;
      if (x7758) {
        long x7759 = x7502;
        char x7760 = x3373[x7759];
        bool x7761 = x7760 != '\n';
        x7763 = x7761;
      }
      bool x7764 = x7763;
      if (!x7764) break;
      x7502 = x7502 + 1;
    }
    x7502 = x7502 + 1;
    for (;;) {
      long x7779 = x7502;
      char x7780 = x3373[x7779];
      bool x7781 = x7780 != '|';
      bool x7786 = x7781;
      if (x7781) {
        long x7782 = x7502;
        char x7783 = x3373[x7782];
        bool x7784 = x7783 != '\n';
        x7786 = x7784;
      }
      bool x7787 = x7786;
      if (!x7787) break;
      x7502 = x7502 + 1;
    }
    x7502 = x7502 + 1;
    long x7797 = x7504;
    long x7798 = x7503;
    bool x7799 = x7797 == x7798;
    if (x7799) {
      long x7800 = x7798 * 4L;
      x7503 = x7800;
      printf("buffer.resize %d\n",x7800);
      int* x7803 = x7506;
      int* x7804 = (int*)realloc(x7803,x7800 * sizeof(int));
      x7506 = x7804;
      int* x7806 = x7508;
      int* x7807 = (int*)realloc(x7806,x7800 * sizeof(int));
      x7508 = x7807;
      long* x7815 = x7514;
      long* x7816 = (long*)realloc(x7815,x7800 * sizeof(long));
      x7514 = x7816;
    } else {
    }
    int* x7832 = x7506;
    x7832[x7797] = x7549;
    int* x7834 = x7508;
    x7834[x7797] = x7573;
    long* x7840 = x7514;
    long x7714 = x7665 * 10000L;
    long x7715 = x7689 * 100L;
    long x7716 = x7714 + x7715;
    long x7717 = x7716 + x7713;
    x7840[x7797] = x7717;
    x7504 = x7504 + 1;
  }
  long x2011 = DEFAULT_JOIN_HASH_SIZE;
  long x787 = DEFAULT_AGG_HASH_SIZE ;
  long x2034 = x2011 - 1L;
  long x802 = x787 - 1L;
  bool x975 = true == false;
  int x7853;
  for(x7853=0; x7853 < 5; x7853++) {
    bool x7854 = false;
    long x7855 = 0L;
    bool x7857 = false;
    long x7858 = 0L;
    bool x7859 = false;
    long x7860 = 0L;
    bool x7861 = false;
    long x7862 = 0L;
    bool x7863 = false;
    long x7864 = 0L;
    bool x7865 = false;
    long x7866 = 0L;
    int* x7869 = (int*)malloc(x2011 * sizeof(int));
    int* x7870 = x7869;
    long x7875 = 0L;
    long* x7876 = (long*)malloc(x2011 * sizeof(long));
    long* x7877 = (long*)malloc(x2011 * sizeof(long));
    long x7878;
    for(x7878=0L; x7878 < x2011; x7878++) {
      x7876[x7878] = -1L;
    }
    char** x7884 = (char**)malloc(x2011 * sizeof(char*));
    char** x7885 = x7884;
    int* x7886 = (int*)malloc(x2011 * sizeof(int));
    int* x7887 = x7886;
    long x7888 = 0L;
    long* x7889 = (long*)malloc(x2011 * sizeof(long));
    long* x7890 = (long*)malloc(x2011 * sizeof(long));
    long x7891;
    for(x7891=0L; x7891 < x2011; x7891++) {
      x7889[x7891] = -1L;
    }
    char** x7897 = (char**)malloc(x2011 * sizeof(char*));
    char** x7898 = x7897;
    int* x7899 = (int*)malloc(x2011 * sizeof(int));
    int* x7900 = x7899;
    int* x7901 = (int*)malloc(x2011 * sizeof(int));
    int* x7902 = x7901;
    long x7903 = 0L;
    long* x7904 = (long*)malloc(x2011 * sizeof(long));
    long* x7905 = (long*)malloc(x2011 * sizeof(long));
    long x7906;
    for(x7906=0L; x7906 < x2011; x7906++) {
      x7904[x7906] = -1L;
    }
    char** x7912 = (char**)malloc(x2011 * sizeof(char*));
    char** x7913 = x7912;
    int* x7914 = (int*)malloc(x2011 * sizeof(int));
    int* x7915 = x7914;
    int* x7916 = (int*)malloc(x2011 * sizeof(int));
    int* x7917 = x7916;
    long x7918 = 0L;
    long* x7919 = (long*)malloc(x2011 * sizeof(long));
    long* x7920 = (long*)malloc(x2011 * sizeof(long));
    long x7921;
    for(x7921=0L; x7921 < x2011; x7921++) {
      x7919[x7921] = -1L;
    }
    int* x7927 = (int*)malloc(x2011 * sizeof(int));
    int* x7928 = x7927;
    int* x7933 = (int*)malloc(x2011 * sizeof(int));
    int* x7934 = x7933;
    long x7941 = 0L;
    long* x7942 = (long*)malloc(x2011 * sizeof(long));
    long* x7943 = (long*)malloc(x2011 * sizeof(long));
    long x7944;
    for(x7944=0L; x7944 < x2011; x7944++) {
      x7942[x7944] = -1L;
    }
    struct Anon801061462* x7950 = (struct Anon801061462*)malloc(x787 * sizeof(struct Anon801061462));
    struct Anon801061462* x7951 = x7950;
    long x7952 = 0L;
    long* x7953 = (long*)malloc(x787 * sizeof(long));
    long x7954;
    for(x7954=0L; x7954 < x787; x7954++) {
      struct Anon801061462* x7955 = x7951;
      struct Anon801061462 x7956 = x7955[x7954];
      char* x7957 = x7956.key;;
      struct Anon2052879266 x7958 = x7956.aggs;;
      struct Anon801061462 x7959;
      x7959.exists = false;
      x7959.key = x7957;
      x7959.aggs = x7958;
      x7955[x7954] = x7959;
    }
    long x7964 = 0L;
    struct timeval x8443, x8444, x8445;
    gettimeofday(&x8443, NULL);
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x7966 = x7859;
      bool x7967 = !x7966;
      bool x7972 = x7967;
      if (x7967) {
        long x7968 = x7860;
        long x7969 = x7153;
        bool x7970 = x7968 < x7969;
        x7972 = x7970;
      }
      bool x7973 = x7972;
      if (!x7973) break;
      long x7975 = x7860;
      int* x7976 = x7155;
      int x7977 = x7976[x7975];
      int* x7982 = x7161;
      int x7983 = x7982[x7975];
      x7860 = x7860 + 1;
      long x7992 = x7941;
      int* x7993 = x7928;
      x7993[x7992] = x7977;
      int* x7999 = x7934;
      x7999[x7992] = x7983;
      x7941 = x7941 + 1L;
      long x8008 = x7977 & x2034;
      long x8009 = x7942[x8008];
      x7942[x8008] = x7992;
      x7943[x7992] = x8009;
    }
    printf("%s\n","begin scan REGION");
    for (;;) {
      bool x8015 = x7854;
      bool x8016 = !x8015;
      bool x8021 = x8016;
      if (x8016) {
        long x8017 = x7855;
        long x8018 = x7405;
        bool x8019 = x8017 < x8018;
        x8021 = x8019;
      }
      bool x8022 = x8021;
      if (!x8022) break;
      long x8024 = x7855;
      int* x8025 = x7407;
      int x8026 = x8025[x8024];
      char** x8027 = x7409;
      char* x8028 = x8027[x8024];
      x7855 = x7855 + 1;
      bool x8033 = strcmp(x8028,"ASIA") == 0;;
      if (x8033) {
        long x8034 = x7875;
        int* x8035 = x7870;
        x8035[x8034] = x8026;
        x7875 = x7875 + 1L;
        long x8042 = x8026 & x2034;
        long x8043 = x7876[x8042];
        x7876[x8042] = x8034;
        x7877[x8034] = x8043;
      } else {
      }
    }
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x8051 = x7857;
      bool x8052 = !x8051;
      bool x8057 = x8052;
      if (x8052) {
        long x8053 = x7858;
        long x8054 = x6746;
        bool x8055 = x8053 < x8054;
        x8057 = x8055;
      }
      bool x8058 = x8057;
      if (!x8058) break;
      long x8060 = x7858;
      int* x8061 = x6748;
      int x8062 = x8061[x8060];
      char** x8063 = x6750;
      char* x8064 = x8063[x8060];
      int* x8065 = x6752;
      int x8066 = x8065[x8060];
      x7858 = x7858 + 1;
      long x8071 = x8066 & x2034;
      long x8072 = x7876[x8071];
      long x8073 = x8072;
      long x8096 = x8062 & x2034;
      for (;;) {
        long x8074 = x8073;
        bool x8075 = x8074 != -1;
        if (!x8075) break;
        long x8077 = x8073;
        int* x8078 = x7870;
        int x8079 = x8078[x8077];
        long x8085 = x7877[x8077];
        x8073 = x8085;
        bool x8087 = x8079 == x8066;
        if (x8087) {
          long x8090 = x7888;
          char** x8091 = x7885;
          x8091[x8090] = x8064;
          int* x8093 = x7887;
          x8093[x8090] = x8062;
          x7888 = x7888 + 1L;
          long x8097 = x7889[x8096];
          x7889[x8096] = x8090;
          x7890[x8090] = x8097;
        } else {
        }
      }
    }
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x8107 = x7861;
      bool x8108 = !x8107;
      bool x8113 = x8108;
      if (x8108) {
        long x8109 = x7862;
        long x8110 = x6876;
        bool x8111 = x8109 < x8110;
        x8113 = x8111;
      }
      bool x8114 = x8113;
      if (!x8114) break;
      long x8116 = x7862;
      int* x8117 = x6878;
      int x8118 = x8117[x8116];
      int* x8123 = x6884;
      int x8124 = x8123[x8116];
      x7862 = x7862 + 1;
      long x8135 = x8124 & x2034;
      long x8136 = x7889[x8135];
      long x8137 = x8136;
      long x8160 = x8118 & x2034;
      for (;;) {
        long x8138 = x8137;
        bool x8139 = x8138 != -1;
        if (!x8139) break;
        long x8141 = x8137;
        char** x8142 = x7885;
        char* x8143 = x8142[x8141];
        int* x8144 = x7887;
        int x8145 = x8144[x8141];
        long x8147 = x7890[x8141];
        x8137 = x8147;
        bool x8149 = x8145 == x8124;
        if (x8149) {
          long x8152 = x7903;
          char** x8153 = x7898;
          x8153[x8152] = x8143;
          int* x8155 = x7900;
          x8155[x8152] = x8145;
          int* x8157 = x7902;
          x8157[x8152] = x8118;
          x7903 = x7903 + 1L;
          long x8161 = x7904[x8160];
          x7904[x8160] = x8152;
          x7905[x8152] = x8161;
        } else {
        }
      }
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x8171 = x7865;
      bool x8172 = !x8171;
      bool x8177 = x8172;
      if (x8172) {
        long x8173 = x7866;
        long x8174 = x7504;
        bool x8175 = x8173 < x8174;
        x8177 = x8175;
      }
      bool x8178 = x8177;
      if (!x8178) break;
      long x8180 = x7866;
      int* x8181 = x7506;
      int x8182 = x8181[x8180];
      int* x8183 = x7508;
      int x8184 = x8183[x8180];
      long* x8189 = x7514;
      long x8190 = x8189[x8180];
      x7866 = x7866 + 1;
      bool x8201 = x8190 >= 19960101L;
      bool x8203 = x8201;
      if (x8201) {
        bool x8202 = x8190 < 19970101L;
        x8203 = x8202;
      }
      bool x8204 = x8203;
      if (x8204) {
        long x8205 = x8184 & x2034;
        long x8206 = x7904[x8205];
        long x8207 = x8206;
        long x8232 = x8182 & x2034;
        for (;;) {
          long x8208 = x8207;
          bool x8209 = x8208 != -1;
          if (!x8209) break;
          long x8211 = x8207;
          char** x8212 = x7898;
          char* x8213 = x8212[x8211];
          int* x8214 = x7900;
          int x8215 = x8214[x8211];
          int* x8216 = x7902;
          int x8217 = x8216[x8211];
          long x8219 = x7905[x8211];
          x8207 = x8219;
          bool x8221 = x8217 == x8184;
          if (x8221) {
            long x8224 = x7918;
            char** x8225 = x7913;
            x8225[x8224] = x8213;
            int* x8227 = x7915;
            x8227[x8224] = x8215;
            int* x8229 = x7917;
            x8229[x8224] = x8182;
            x7918 = x7918 + 1L;
            long x8233 = x7919[x8232];
            x7919[x8232] = x8224;
            x7920[x8224] = x8233;
          } else {
          }
        }
      } else {
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x8245 = x7863;
      bool x8246 = !x8245;
      bool x8251 = x8246;
      if (x8246) {
        long x8247 = x7864;
        long x8248 = x5972;
        bool x8249 = x8247 < x8248;
        x8251 = x8249;
      }
      bool x8252 = x8251;
      if (!x8252) break;
      long x8254 = x7864;
      int* x8255 = x5974;
      int x8256 = x8255[x8254];
      int* x8259 = x5978;
      int x8260 = x8259[x8254];
      double* x8265 = x5984;
      double x8266 = x8265[x8254];
      double* x8267 = x5986;
      double x8268 = x8267[x8254];
      x7864 = x7864 + 1;
      long x8289 = x8256 & x2034;
      long x8290 = x7919[x8289];
      long x8291 = x8290;
      long x8308 = x8260 & x2034;
      double x8359 = 1.0 - x8268;
      double x8360 = x8266 * x8359;
      struct Anon2052879266 x8393;
      x8393._0 = x8360;
      for (;;) {
        long x8292 = x8291;
        bool x8293 = x8292 != -1;
        if (!x8293) break;
        long x8295 = x8291;
        char** x8296 = x7913;
        char* x8297 = x8296[x8295];
        int* x8298 = x7915;
        int x8299 = x8298[x8295];
        int* x8300 = x7917;
        int x8301 = x8300[x8295];
        long x8303 = x7920[x8295];
        x8291 = x8303;
        bool x8305 = x8301 == x8256;
        if (x8305) {
          long x8309 = x7942[x8308];
          long x8310 = x8309;
          char x8335 = x8297[0L];
          long x8336 = x8335 * 41L;
          char x8337 = x8297[1L];
          long x8338 = x8336 + x8337;
          long x8339 = x8338 * 41L;
          char x8340 = x8297[2L];
          long x8341 = x8339 + x8340;
          long x8342 = x8341 * 41L;
          char x8343 = x8297[3L];
          long x8344 = x8342 + x8343;
          long x8345 = x8344 & x802;
          struct Anon801061462 x8394;
          x8394.exists = true;
          x8394.key = x8297;
          x8394.aggs = x8393;
          for (;;) {
            long x8311 = x8310;
            bool x8312 = x8311 != -1;
            if (!x8312) break;
            long x8314 = x8310;
            int* x8315 = x7928;
            int x8316 = x8315[x8314];
            int* x8321 = x7934;
            int x8322 = x8321[x8314];
            long x8330 = x7943[x8314];
            x8310 = x8330;
            bool x8332 = x8316 == x8260;
            if (x8332) {
              bool x8334 = x8322 == x8299;
              if (x8334) {
                long x8346 = x8345;
                struct Anon801061462* x8347 = x7951;
                struct Anon801061462 x8348 = x8347[x8345];
                struct Anon801061462 x8349 = x8348;
                bool x8350 = x8348.exists;;
                bool x8355 = x8350;
                if (x8350) {
                  struct Anon801061462 x8351 = x8349;
                  char* x8352 = x8351.key;;
                  bool x8353 = strcmp(x8352,x8297) == 0;;
                  x8355 = x8353;
                }
                bool x8356 = x8355;
                if (x8356) {
                  struct Anon2052879266 x8357 = x8348.aggs;;
                  char* x8363 = x8348.key;;
                  double x8358 = x8357._0;;
                  double x8361 = x8358 + x8360;
                  struct Anon2052879266 x8362;
                  x8362._0 = x8361;
                  struct Anon801061462 x8364;
                  x8364.exists = true;
                  x8364.key = x8363;
                  x8364.aggs = x8362;
                  x8347[x8345] = x8364;
                } else {
                  for (;;) {
                    struct Anon801061462 x8367 = x8349;
                    bool x8368 = x8367.exists;;
                    bool x8403;
                    if (x8368) {
                      char* x8369 = x8367.key;;
                      bool x8370 = strcmp(x8369,x8297) == 0;;
                      bool x8390;
                      if (x8370) {
                        struct Anon2052879266 x8371 = x8367.aggs;;
                        long x8375 = x8346;
                        struct Anon801061462* x8377 = x7951;
                        double x8372 = x8371._0;;
                        double x8373 = x8372 + x8360;
                        struct Anon2052879266 x8374;
                        x8374._0 = x8373;
                        struct Anon801061462 x8376;
                        x8376.exists = true;
                        x8376.key = x8369;
                        x8376.aggs = x8374;
                        x8377[x8375] = x8376;
                        x8390 = false;
                      } else {
                        long x8380 = x8346;
                        long x8381 = x8380 + 1L;
                        long x8382 = x8381 % x802;
                        x8346 = x8382;
                        struct Anon801061462* x8384 = x7951;
                        struct Anon801061462 x8385 = x8384[x8382];
                        x8349 = x8385;
                        x8390 = true;
                      }
                      x8403 = x8390;
                    } else {
                      long x8392 = x8346;
                      struct Anon801061462* x8395 = x7951;
                      x8395[x8392] = x8394;
                      long x8397 = x7952;
                      x7953[x8397] = x8392;
                      x7952 = x7952 + 1L;
                      x8403 = false;
                    }
                    if (!x8403) break;
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
    }
    long x8422 = x7952;
    long x8424;
    for(x8424=0L; x8424 < x8422; x8424++) {
      long x8425 = x7953[x8424];
      struct Anon801061462* x8426 = x7951;
      struct Anon801061462 x8427 = x8426[x8425];
      if (x975) {
      } else {
        char* x8430 = x8427.key;;
        struct Anon2052879266 x8432 = x8427.aggs;;
        int x8431 = strlen(x8430);
        double x8433 = x8432._0;;
        printf("%.*s|%.4f\n",x8431,x8430,x8433);
        x7964 = x7964 + 1L;
      }
    }
    long x8440 = x7964;
    printf("(%d rows)\n",x8440);
    gettimeofday(&x8444, NULL);
    timeval_subtract(&x8445, &x8444, &x8443);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x8445.tv_sec * 1000) + (x8445.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
