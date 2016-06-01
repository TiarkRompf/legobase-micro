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

struct Anon546410247 {
char* N_NAME;
int N_NATIONKEY;
int O_ORDERKEY;
};

struct Anon1078540535 {
char* N_NAME;
int N_NATIONKEY;
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

/************************ FUNCTIONS **************************/

/************************ MAIN BODY **************************/
int main(int x9020, char** x9021) {
  long x9022 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x9023 = x7;
  long x9024 = 0L;
  double* x9033 = (double*)malloc(x7 * sizeof(double));
  double* x9034 = x9033;
  double* x9035 = (double*)malloc(x7 * sizeof(double));
  double* x9036 = x9035;
  double* x9037 = (double*)malloc(x7 * sizeof(double));
  double* x9038 = x9037;
  long* x9045 = (long*)malloc(x7 * sizeof(long));
  long* x9046 = x9045;
  int x3 = open("XXXXXlineitem.tbl",0);
  long x4 = fsize(x3);
  char* x5 = mmap(0, x4, PROT_READ, MAP_FILE | MAP_SHARED, x3, 0);
  for (;;) {
    long x9057 = x9022;
    bool x9058 = x9057 < x4;
    if (!x9058) break;
    for (;;) {
      long x9062 = x9022;
      char x9063 = x5[x9062];
      bool x9064 = x9063 != '|';
      bool x9069 = x9064;
      if (x9064) {
        long x9065 = x9022;
        char x9066 = x5[x9065];
        bool x9067 = x9066 != '\n';
        x9069 = x9067;
      }
      bool x9070 = x9069;
      if (!x9070) break;
      x9022 = x9022 + 1;
    }
    x9022 = x9022 + 1;
    for (;;) {
      long x9086 = x9022;
      char x9087 = x5[x9086];
      bool x9088 = x9087 != '|';
      bool x9093 = x9088;
      if (x9088) {
        long x9089 = x9022;
        char x9090 = x5[x9089];
        bool x9091 = x9090 != '\n';
        x9093 = x9091;
      }
      bool x9094 = x9093;
      if (!x9094) break;
      x9022 = x9022 + 1;
    }
    x9022 = x9022 + 1;
    for (;;) {
      long x9110 = x9022;
      char x9111 = x5[x9110];
      bool x9112 = x9111 != '|';
      bool x9117 = x9112;
      if (x9112) {
        long x9113 = x9022;
        char x9114 = x5[x9113];
        bool x9115 = x9114 != '\n';
        x9117 = x9115;
      }
      bool x9118 = x9117;
      if (!x9118) break;
      x9022 = x9022 + 1;
    }
    x9022 = x9022 + 1;
    for (;;) {
      long x9134 = x9022;
      char x9135 = x5[x9134];
      bool x9136 = x9135 != '|';
      bool x9141 = x9136;
      if (x9136) {
        long x9137 = x9022;
        char x9138 = x5[x9137];
        bool x9139 = x9138 != '\n';
        x9141 = x9139;
      }
      bool x9142 = x9141;
      if (!x9142) break;
      x9022 = x9022 + 1;
    }
    x9022 = x9022 + 1;
    int x9157 = 0;
    int x9158 = 1;
    for (;;) {
      long x9159 = x9022;
      char x9160 = x5[x9159];
      bool x9161 = x9160 != '.';
      bool x9166 = x9161;
      if (x9161) {
        long x9162 = x9022;
        char x9163 = x5[x9162];
        bool x9164 = x9163 != '|';
        x9166 = x9164;
      }
      bool x9167 = x9166;
      bool x9172 = x9167;
      if (x9167) {
        long x9168 = x9022;
        char x9169 = x5[x9168];
        bool x9170 = x9169 != '\n';
        x9172 = x9170;
      }
      bool x9173 = x9172;
      if (!x9173) break;
      int x9175 = x9157;
      long x9177 = x9022;
      int x9176 = x9175 * 10;
      char x9178 = x5[x9177];
      char x9179 = x9178 - '0';
      int x9180 = x9176 + x9179;
      x9157 = x9180;
      x9022 = x9022 + 1;
    }
    long x9185 = x9022;
    char x9186 = x5[x9185];
    bool x9187 = x9186 == '.';
    if (x9187) {
      x9022 = x9022 + 1;
      for (;;) {
        long x9189 = x9022;
        char x9190 = x5[x9189];
        bool x9191 = x9190 != '|';
        bool x9196 = x9191;
        if (x9191) {
          long x9192 = x9022;
          char x9193 = x5[x9192];
          bool x9194 = x9193 != '\n';
          x9196 = x9194;
        }
        bool x9197 = x9196;
        if (!x9197) break;
        int x9199 = x9157;
        long x9201 = x9022;
        int x9200 = x9199 * 10;
        char x9202 = x5[x9201];
        char x9203 = x9202 - '0';
        int x9204 = x9200 + x9203;
        x9157 = x9204;
        int x9206 = x9158;
        int x9207 = x9206 * 10;
        x9158 = x9207;
        x9022 = x9022 + 1;
      }
    } else {
    }
    x9022 = x9022 + 1;
    int x9216 = x9157;
    int x9218 = x9158;
    int x9222 = 0;
    int x9223 = 1;
    for (;;) {
      long x9224 = x9022;
      char x9225 = x5[x9224];
      bool x9226 = x9225 != '.';
      bool x9231 = x9226;
      if (x9226) {
        long x9227 = x9022;
        char x9228 = x5[x9227];
        bool x9229 = x9228 != '|';
        x9231 = x9229;
      }
      bool x9232 = x9231;
      bool x9237 = x9232;
      if (x9232) {
        long x9233 = x9022;
        char x9234 = x5[x9233];
        bool x9235 = x9234 != '\n';
        x9237 = x9235;
      }
      bool x9238 = x9237;
      if (!x9238) break;
      int x9240 = x9222;
      long x9242 = x9022;
      int x9241 = x9240 * 10;
      char x9243 = x5[x9242];
      char x9244 = x9243 - '0';
      int x9245 = x9241 + x9244;
      x9222 = x9245;
      x9022 = x9022 + 1;
    }
    long x9250 = x9022;
    char x9251 = x5[x9250];
    bool x9252 = x9251 == '.';
    if (x9252) {
      x9022 = x9022 + 1;
      for (;;) {
        long x9254 = x9022;
        char x9255 = x5[x9254];
        bool x9256 = x9255 != '|';
        bool x9261 = x9256;
        if (x9256) {
          long x9257 = x9022;
          char x9258 = x5[x9257];
          bool x9259 = x9258 != '\n';
          x9261 = x9259;
        }
        bool x9262 = x9261;
        if (!x9262) break;
        int x9264 = x9222;
        long x9266 = x9022;
        int x9265 = x9264 * 10;
        char x9267 = x5[x9266];
        char x9268 = x9267 - '0';
        int x9269 = x9265 + x9268;
        x9222 = x9269;
        int x9271 = x9223;
        int x9272 = x9271 * 10;
        x9223 = x9272;
        x9022 = x9022 + 1;
      }
    } else {
    }
    x9022 = x9022 + 1;
    int x9281 = x9222;
    int x9283 = x9223;
    int x9287 = 0;
    int x9288 = 1;
    for (;;) {
      long x9289 = x9022;
      char x9290 = x5[x9289];
      bool x9291 = x9290 != '.';
      bool x9296 = x9291;
      if (x9291) {
        long x9292 = x9022;
        char x9293 = x5[x9292];
        bool x9294 = x9293 != '|';
        x9296 = x9294;
      }
      bool x9297 = x9296;
      bool x9302 = x9297;
      if (x9297) {
        long x9298 = x9022;
        char x9299 = x5[x9298];
        bool x9300 = x9299 != '\n';
        x9302 = x9300;
      }
      bool x9303 = x9302;
      if (!x9303) break;
      int x9305 = x9287;
      long x9307 = x9022;
      int x9306 = x9305 * 10;
      char x9308 = x5[x9307];
      char x9309 = x9308 - '0';
      int x9310 = x9306 + x9309;
      x9287 = x9310;
      x9022 = x9022 + 1;
    }
    long x9315 = x9022;
    char x9316 = x5[x9315];
    bool x9317 = x9316 == '.';
    if (x9317) {
      x9022 = x9022 + 1;
      for (;;) {
        long x9319 = x9022;
        char x9320 = x5[x9319];
        bool x9321 = x9320 != '|';
        bool x9326 = x9321;
        if (x9321) {
          long x9322 = x9022;
          char x9323 = x5[x9322];
          bool x9324 = x9323 != '\n';
          x9326 = x9324;
        }
        bool x9327 = x9326;
        if (!x9327) break;
        int x9329 = x9287;
        long x9331 = x9022;
        int x9330 = x9329 * 10;
        char x9332 = x5[x9331];
        char x9333 = x9332 - '0';
        int x9334 = x9330 + x9333;
        x9287 = x9334;
        int x9336 = x9288;
        int x9337 = x9336 * 10;
        x9288 = x9337;
        x9022 = x9022 + 1;
      }
    } else {
    }
    x9022 = x9022 + 1;
    int x9346 = x9287;
    int x9348 = x9288;
    for (;;) {
      long x9354 = x9022;
      char x9355 = x5[x9354];
      bool x9356 = x9355 != '.';
      bool x9361 = x9356;
      if (x9356) {
        long x9357 = x9022;
        char x9358 = x5[x9357];
        bool x9359 = x9358 != '|';
        x9361 = x9359;
      }
      bool x9362 = x9361;
      bool x9367 = x9362;
      if (x9362) {
        long x9363 = x9022;
        char x9364 = x5[x9363];
        bool x9365 = x9364 != '\n';
        x9367 = x9365;
      }
      bool x9368 = x9367;
      if (!x9368) break;
      x9022 = x9022 + 1;
    }
    long x9380 = x9022;
    char x9381 = x5[x9380];
    bool x9382 = x9381 == '.';
    if (x9382) {
      x9022 = x9022 + 1;
      for (;;) {
        long x9384 = x9022;
        char x9385 = x5[x9384];
        bool x9386 = x9385 != '|';
        bool x9391 = x9386;
        if (x9386) {
          long x9387 = x9022;
          char x9388 = x5[x9387];
          bool x9389 = x9388 != '\n';
          x9391 = x9389;
        }
        bool x9392 = x9391;
        if (!x9392) break;
        x9022 = x9022 + 1;
      }
    } else {
    }
    x9022 = x9022 + 1;
    x9022 = x9022 + 2;
    x9022 = x9022 + 2;
    int x9423 = 0;
    for (;;) {
      long x9424 = x9022;
      char x9425 = x5[x9424];
      bool x9426 = x9425 != '-';
      bool x9431 = x9426;
      if (x9426) {
        long x9427 = x9022;
        char x9428 = x5[x9427];
        bool x9429 = x9428 != '\n';
        x9431 = x9429;
      }
      bool x9432 = x9431;
      if (!x9432) break;
      int x9434 = x9423;
      long x9436 = x9022;
      int x9435 = x9434 * 10;
      char x9437 = x5[x9436];
      char x9438 = x9437 - '0';
      int x9439 = x9435 + x9438;
      x9423 = x9439;
      x9022 = x9022 + 1;
    }
    x9022 = x9022 + 1;
    int x9445 = x9423;
    int x9447 = 0;
    for (;;) {
      long x9448 = x9022;
      char x9449 = x5[x9448];
      bool x9450 = x9449 != '-';
      bool x9455 = x9450;
      if (x9450) {
        long x9451 = x9022;
        char x9452 = x5[x9451];
        bool x9453 = x9452 != '\n';
        x9455 = x9453;
      }
      bool x9456 = x9455;
      if (!x9456) break;
      int x9458 = x9447;
      long x9460 = x9022;
      int x9459 = x9458 * 10;
      char x9461 = x5[x9460];
      char x9462 = x9461 - '0';
      int x9463 = x9459 + x9462;
      x9447 = x9463;
      x9022 = x9022 + 1;
    }
    x9022 = x9022 + 1;
    int x9469 = x9447;
    int x9471 = 0;
    for (;;) {
      long x9472 = x9022;
      char x9473 = x5[x9472];
      bool x9474 = x9473 != '|';
      bool x9479 = x9474;
      if (x9474) {
        long x9475 = x9022;
        char x9476 = x5[x9475];
        bool x9477 = x9476 != '\n';
        x9479 = x9477;
      }
      bool x9480 = x9479;
      if (!x9480) break;
      int x9482 = x9471;
      long x9484 = x9022;
      int x9483 = x9482 * 10;
      char x9485 = x5[x9484];
      char x9486 = x9485 - '0';
      int x9487 = x9483 + x9486;
      x9471 = x9487;
      x9022 = x9022 + 1;
    }
    x9022 = x9022 + 1;
    int x9493 = x9471;
    for (;;) {
      long x9500 = x9022;
      char x9501 = x5[x9500];
      bool x9502 = x9501 != '-';
      bool x9507 = x9502;
      if (x9502) {
        long x9503 = x9022;
        char x9504 = x5[x9503];
        bool x9505 = x9504 != '\n';
        x9507 = x9505;
      }
      bool x9508 = x9507;
      if (!x9508) break;
      x9022 = x9022 + 1;
    }
    x9022 = x9022 + 1;
    for (;;) {
      long x9524 = x9022;
      char x9525 = x5[x9524];
      bool x9526 = x9525 != '-';
      bool x9531 = x9526;
      if (x9526) {
        long x9527 = x9022;
        char x9528 = x5[x9527];
        bool x9529 = x9528 != '\n';
        x9531 = x9529;
      }
      bool x9532 = x9531;
      if (!x9532) break;
      x9022 = x9022 + 1;
    }
    x9022 = x9022 + 1;
    for (;;) {
      long x9548 = x9022;
      char x9549 = x5[x9548];
      bool x9550 = x9549 != '|';
      bool x9555 = x9550;
      if (x9550) {
        long x9551 = x9022;
        char x9552 = x5[x9551];
        bool x9553 = x9552 != '\n';
        x9555 = x9553;
      }
      bool x9556 = x9555;
      if (!x9556) break;
      x9022 = x9022 + 1;
    }
    x9022 = x9022 + 1;
    for (;;) {
      long x9576 = x9022;
      char x9577 = x5[x9576];
      bool x9578 = x9577 != '-';
      bool x9583 = x9578;
      if (x9578) {
        long x9579 = x9022;
        char x9580 = x5[x9579];
        bool x9581 = x9580 != '\n';
        x9583 = x9581;
      }
      bool x9584 = x9583;
      if (!x9584) break;
      x9022 = x9022 + 1;
    }
    x9022 = x9022 + 1;
    for (;;) {
      long x9600 = x9022;
      char x9601 = x5[x9600];
      bool x9602 = x9601 != '-';
      bool x9607 = x9602;
      if (x9602) {
        long x9603 = x9022;
        char x9604 = x5[x9603];
        bool x9605 = x9604 != '\n';
        x9607 = x9605;
      }
      bool x9608 = x9607;
      if (!x9608) break;
      x9022 = x9022 + 1;
    }
    x9022 = x9022 + 1;
    for (;;) {
      long x9624 = x9022;
      char x9625 = x5[x9624];
      bool x9626 = x9625 != '|';
      bool x9631 = x9626;
      if (x9626) {
        long x9627 = x9022;
        char x9628 = x5[x9627];
        bool x9629 = x9628 != '\n';
        x9631 = x9629;
      }
      bool x9632 = x9631;
      if (!x9632) break;
      x9022 = x9022 + 1;
    }
    x9022 = x9022 + 1;
    for (;;) {
      long x9651 = x9022;
      char x9652 = x5[x9651];
      bool x9653 = x9652 != '|';
      bool x9658 = x9653;
      if (x9653) {
        long x9654 = x9022;
        char x9655 = x5[x9654];
        bool x9656 = x9655 != '\n';
        x9658 = x9656;
      }
      bool x9659 = x9658;
      if (!x9659) break;
      x9022 = x9022 + 1;
    }
    x9022 = x9022 + 1;
    for (;;) {
      long x9669 = x9022;
      char x9670 = x5[x9669];
      bool x9671 = x9670 != '|';
      bool x9676 = x9671;
      if (x9671) {
        long x9672 = x9022;
        char x9673 = x5[x9672];
        bool x9674 = x9673 != '\n';
        x9676 = x9674;
      }
      bool x9677 = x9676;
      if (!x9677) break;
      x9022 = x9022 + 1;
    }
    x9022 = x9022 + 1;
    for (;;) {
      long x9687 = x9022;
      char x9688 = x5[x9687];
      bool x9689 = x9688 != '|';
      bool x9694 = x9689;
      if (x9689) {
        long x9690 = x9022;
        char x9691 = x5[x9690];
        bool x9692 = x9691 != '\n';
        x9694 = x9692;
      }
      bool x9695 = x9694;
      if (!x9695) break;
      x9022 = x9022 + 1;
    }
    x9022 = x9022 + 1;
    long x9705 = x9022;
    bool x9706 = x9705 > 0L;
    bool x9712 = x9706;
    if (x9706) {
      long x9707 = x9022;
      long x9708 = x9707 - 1L;
      char x9709 = x5[x9708];
      bool x9710 = x9709 != '\n';
      x9712 = x9710;
    }
    bool x9713 = x9712;
    if (x9713) {
      for (;;) {
        long x9714 = x9022;
        char x9715 = x5[x9714];
        bool x9716 = x9715 != '\n';
        if (!x9716) break;
        x9022 = x9022 + 1;
      }
    } else {
    }
    x9022 = x9022 + 1;
    long x9725 = x9024;
    long x9726 = x9023;
    bool x9727 = x9725 == x9726;
    if (x9727) {
      long x9728 = x9726 * 4L;
      x9023 = x9728;
      printf("buffer.resize %ld\n",x9728);
      double* x9743 = x9034;
      double* x9744 = (double*)realloc(x9743,x9728 * sizeof(double));
      x9034 = x9744;
      double* x9746 = x9036;
      double* x9747 = (double*)realloc(x9746,x9728 * sizeof(double));
      x9036 = x9747;
      double* x9749 = x9038;
      double* x9750 = (double*)realloc(x9749,x9728 * sizeof(double));
      x9038 = x9750;
      long* x9761 = x9046;
      long* x9762 = (long*)realloc(x9761,x9728 * sizeof(long));
      x9046 = x9762;
    } else {
    }
    double* x9789 = x9034;
    double x9217 = (double)x9216;
    double x9219 = (double)x9218;
    double x9220 = x9217 / x9219;
    x9789[x9725] = x9220;
    double* x9791 = x9036;
    double x9282 = (double)x9281;
    double x9284 = (double)x9283;
    double x9285 = x9282 / x9284;
    x9791[x9725] = x9285;
    double* x9793 = x9038;
    double x9347 = (double)x9346;
    double x9349 = (double)x9348;
    double x9350 = x9347 / x9349;
    x9793[x9725] = x9350;
    long* x9801 = x9046;
    long x9494 = x9445 * 10000L;
    long x9495 = x9469 * 100L;
    long x9496 = x9494 + x9495;
    long x9497 = x9496 + x9493;
    x9801[x9725] = x9497;
    x9024 = x9024 + 1;
  }
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  float x9891 = (float)24;
  double x9892 = (double)x9891;
  long x823 = x808 - 1L;
  bool x1043 = true == false;
  int x9816;
  for(x9816=0; x9816 < 5; x9816++) {
    bool x9817 = false;
    long x9818 = 0L;
    struct Anon1042493154* x9821 = (struct Anon1042493154*)malloc(x808 * sizeof(struct Anon1042493154));
    struct Anon1042493154* x9822 = x9821;
    long x9823 = 0L;
    long* x9824 = (long*)malloc(x808 * sizeof(long));
    long x9825;
    for(x9825=0L; x9825 < x808; x9825++) {
      struct Anon1042493154* x9826 = x9822;
      struct Anon1042493154 x9827 = x9826[x9825];
      char* x9828 = x9827.key;;
      struct Anon2052879266 x9829 = x9827.aggs;;
      struct Anon1042493154 x9830;
      x9830.exists = false;
      x9830.key = x9828;
      x9830.aggs = x9829;
      x9826[x9825] = x9830;
    }
    long x9835 = 0L;
    struct timeval x9984, x9985, x9986;
    gettimeofday(&x9984, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x9837 = x9817;
      bool x9838 = !x9837;
      bool x9843 = x9838;
      if (x9838) {
        long x9839 = x9818;
        long x9840 = x9024;
        bool x9841 = x9839 < x9840;
        x9843 = x9841;
      }
      bool x9844 = x9843;
      if (!x9844) break;
      long x9846 = x9818;
      double* x9855 = x9034;
      double x9856 = x9855[x9846];
      double* x9857 = x9036;
      double x9858 = x9857[x9846];
      double* x9859 = x9038;
      double x9860 = x9859[x9846];
      long* x9867 = x9046;
      long x9868 = x9867[x9846];
      x9818 = x9818 + 1;
      bool x9881 = x9868 >= 19940101L;
      bool x9883 = x9881;
      if (x9881) {
        bool x9882 = x9868 < 19950101L;
        x9883 = x9882;
      }
      bool x9884 = x9883;
      bool x9886 = x9884;
      if (x9884) {
        bool x9885 = x9860 >= 0.05;
        x9886 = x9885;
      }
      bool x9887 = x9886;
      bool x9889 = x9887;
      if (x9887) {
        bool x9888 = x9860 <= 0.07;
        x9889 = x9888;
      }
      bool x9890 = x9889;
      bool x9894 = x9890;
      if (x9890) {
        bool x9893 = x9856 < x9892;
        x9894 = x9893;
      }
      bool x9895 = x9894;
      if (x9895) {
        long x9896 = hash("Total", 10L);
        long x9897 = x9896 & x823;
        long x9898 = x9897;
        struct Anon1042493154* x9899 = x9822;
        struct Anon1042493154 x9900 = x9899[x9897];
        struct Anon1042493154 x9901 = x9900;
        bool x9902 = x9900.exists;;
        bool x9907 = x9902;
        if (x9902) {
          struct Anon1042493154 x9903 = x9901;
          char* x9904 = x9903.key;;
          bool x9905 = tpch_strcmp(x9904,"Total") == 0;;
          x9907 = x9905;
        }
        bool x9908 = x9907;
        if (x9908) {
          struct Anon2052879266 x9909 = x9900.aggs;;
          char* x9914 = x9900.key;;
          double x9910 = x9858 * x9860;
          double x9911 = x9909._0;;
          double x9912 = x9910 + x9911;
          struct Anon2052879266 x9913;
          x9913._0 = x9912;
          struct Anon1042493154 x9915;
          x9915.exists = true;
          x9915.key = x9914;
          x9915.aggs = x9913;
          x9899[x9897] = x9915;
        } else {
          double x9910 = x9858 * x9860;
          struct Anon2052879266 x9944;
          x9944._0 = x9910;
          struct Anon1042493154 x9945;
          x9945.exists = true;
          x9945.key = "Total";
          x9945.aggs = x9944;
          for (;;) {
            struct Anon1042493154 x9918 = x9901;
            bool x9919 = x9918.exists;;
            bool x9954;
            if (x9919) {
              char* x9920 = x9918.key;;
              bool x9921 = tpch_strcmp(x9920,"Total") == 0;;
              bool x9941;
              if (x9921) {
                struct Anon2052879266 x9922 = x9918.aggs;;
                long x9926 = x9898;
                struct Anon1042493154* x9928 = x9822;
                double x9923 = x9922._0;;
                double x9924 = x9910 + x9923;
                struct Anon2052879266 x9925;
                x9925._0 = x9924;
                struct Anon1042493154 x9927;
                x9927.exists = true;
                x9927.key = x9920;
                x9927.aggs = x9925;
                x9928[x9926] = x9927;
                x9941 = false;
              } else {
                long x9931 = x9898;
                long x9932 = x9931 + 1L;
                long x9933 = x9932 & x823;
                x9898 = x9933;
                struct Anon1042493154* x9935 = x9822;
                struct Anon1042493154 x9936 = x9935[x9933];
                x9901 = x9936;
                x9941 = true;
              }
              x9954 = x9941;
            } else {
              long x9943 = x9898;
              struct Anon1042493154* x9946 = x9822;
              x9946[x9943] = x9945;
              long x9948 = x9823;
              x9824[x9948] = x9943;
              x9823 = x9823 + 1L;
              x9954 = false;
            }
            if (!x9954) break;
          }
        }
      } else {
      }
    }
    long x9965 = x9823;
    long x9967;
    for(x9967=0L; x9967 < x9965; x9967++) {
      long x9968 = x9824[x9967];
      struct Anon1042493154* x9969 = x9822;
      struct Anon1042493154 x9970 = x9969[x9968];
      if (x1043) {
      } else {
        struct Anon2052879266 x9973 = x9970.aggs;;
        double x9974 = x9973._0;;
        printf("%.4f\n",x9974);
        x9835 = x9835 + 1L;
      }
    }
    long x9981 = x9835;
    printf("(%ld rows)\n",x9981);
    gettimeofday(&x9985, NULL);
    timeval_subtract(&x9986, &x9985, &x9984);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x9986.tv_sec * 1000) + (x9986.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
