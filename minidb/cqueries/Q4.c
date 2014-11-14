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
struct Anon1406772883;
struct Anon567626277;
struct Anon920667905;
struct Anon168903330;
struct Anon1296044246;
struct Anon1866483359;
struct Anon920667905Anon811555534;
struct Anon1023322325;
struct Anon855148991;
struct Anon920667905Anon811555534Anon168903330;
struct Anon1465150758;
struct Anon2134411685;
struct Anon1812879556;
struct Anon0;
struct Anon15765642;
struct Anon811555534;
struct Anon102935935;
struct Anon1268892766;
struct Anon327816002;
struct Anon2131537536;
struct Anon2052879266;
struct Anon722854457;
struct Anon1732223439;
struct Anon625264174;
struct Anon1395358962;
struct Anon1555625313;
struct Anon704530870;

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

struct Anon855148991 {
struct Anon625264174* key;
struct Anon1296044246* aggs;
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

struct Anon2134411685 {
int key;
struct Anon1023322325* aggs;
};

struct Anon1812879556 {
char* key;
struct Anon2052879266* aggs;
};

struct Anon0 {
struct Anon1732223439* left;
struct Anon168903330* right;
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

struct Anon2131537536 {
int key;
struct Anon1023322325* wnd;
};

struct Anon2052879266 {
double _0;
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

struct Anon625264174 {
char L_RETURNFLAG;
char L_LINESTATUS;
};

struct Anon1395358962 {
int PS_PARTKEY;
int PS_SUPPKEY;
int PS_AVAILQTY;
double PS_SUPPLYCOST;
char* PS_COMMENT;
};

struct Anon1555625313 {
struct Anon1465150758* key;
struct Anon2052879266* aggs;
};

struct Anon704530870 {
struct Anon625264174* key;
struct Anon567626277* aggs;
};

/************************ FUNCTIONS **************************/
int x6684(struct Anon1812879556* x5696, struct Anon1812879556* x5695);
int x6690(struct Anon1812879556* x6685, struct Anon1812879556* x6686, struct Anon1812879556** x6687);
int x6684(struct Anon1812879556* x5696, struct Anon1812879556* x5695) {
  char* x5697 = x5695->key;;
  char* x5698 = x5696->key;;
  int x5699 = strcmp(x5697,x5698);
  return x5699;
}
int x6690(struct Anon1812879556* x6685, struct Anon1812879556* x6686, struct Anon1812879556** x6687) {
  *x6687 = x6686;
  return 0;
}

/************************ MAIN BODY **************************/
int main(int x5357, char** x5358) {
  FILE* x6028 = fopen("../databases/sf2/lineitem.tbl", "r");
  int x6029 = 1048576;
  int x6030 = 0;
  int* x6031 = (int*)malloc(1048576 * sizeof(int));
  int* x6032 = x6031;
  long* x6053 = (long*)malloc(1048576 * sizeof(long));
  long* x6054 = x6053;
  long* x6055 = (long*)malloc(1048576 * sizeof(long));
  long* x6056 = x6055;
  for (;;) {
    bool x6063 = !feof(x6028);
    if (!x6063) break;
    int x6065 = 0;
    if (fscanf(x6028,"%d|",&x6065) == EOF) break;
    int x6066 = 0;
    if (fscanf(x6028,"%d|",&x6066) == EOF) break;
    int x6067 = 0;
    if (fscanf(x6028,"%d|",&x6067) == EOF) break;
    int x6068 = 0;
    if (fscanf(x6028,"%d|",&x6068) == EOF) break;
    double x6069 = 0.0;
    if (fscanf(x6028,"%lf|",&x6069) == EOF) break;
    double x6070 = 0.0;
    if (fscanf(x6028,"%lf|",&x6070) == EOF) break;
    double x6071 = 0.0;
    if (fscanf(x6028,"%lf|",&x6071) == EOF) break;
    double x6072 = 0.0;
    if (fscanf(x6028,"%lf|",&x6072) == EOF) break;
    char x6073 = ' ';
    if (fscanf(x6028,"%c|",&x6073) == EOF) break;
    char x6074 = ' ';
    if (fscanf(x6028,"%c|",&x6074) == EOF) break;
    int x6075 = 0;
    int x6076 = 0;
    int x6077 = 0;
    fscanf(x6028, "%d-%d-%d|",&x6075, &x6076, &x6077);
    long x6078 = (x6075 * 10000) + (x6076 * 100) + x6077;
    int x6079 = 0;
    int x6080 = 0;
    int x6081 = 0;
    fscanf(x6028, "%d-%d-%d|",&x6079, &x6080, &x6081);
    long x6082 = (x6079 * 10000) + (x6080 * 100) + x6081;
    int x6083 = 0;
    int x6084 = 0;
    int x6085 = 0;
    fscanf(x6028, "%d-%d-%d|",&x6083, &x6084, &x6085);
    long x6086 = (x6083 * 10000) + (x6084 * 100) + x6085;
    char* x6087 = (char*)malloc(26 * sizeof(char));
    int x6089 = 0;
    char x6088 = ' ';
    while (1) {
      fscanf(x6028,"%c",&x6088);
      if (x6088=='|' || x6088=='\n') break;
      if (x6089>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x6089); break;}
      ((char*)x6087)[x6089] = x6088;
      x6089 += 1;
    }
    ((char*)x6087)[x6089] = '\0';
    char* x6092 = (char*)malloc(11 * sizeof(char));
    int x6094 = 0;
    char x6093 = ' ';
    while (1) {
      fscanf(x6028,"%c",&x6093);
      if (x6093=='|' || x6093=='\n') break;
      if (x6094>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x6094); break;}
      ((char*)x6092)[x6094] = x6093;
      x6094 += 1;
    }
    ((char*)x6092)[x6094] = '\0';
    char* x6097 = (char*)malloc(45 * sizeof(char));
    int x6099 = 0;
    char x6098 = ' ';
    while (1) {
      fscanf(x6028,"%c",&x6098);
      if (x6098=='|' || x6098=='\n') break;
      if (x6099>=44) { printf("ERROR: scanner.nextString reading past end of buffer %d",x6099); break;}
      ((char*)x6097)[x6099] = x6098;
      x6099 += 1;
    }
    ((char*)x6097)[x6099] = '\0';
    int x6102 = x6030;
    int x6103 = x6029;
    bool x6104 = x6102 == x6103;
    if (x6104) {
      int x6105 = x6103 * 4;
      x6029 = x6105;
      printf("buffer.resize %d\n",x6105);
      int* x6108 = x6032;
      int* x6109 = (int*)realloc(x6108,x6105 * sizeof(int));
      x6032 = x6109;
      long* x6141 = x6054;
      long* x6142 = (long*)realloc(x6141,x6105 * sizeof(long));
      x6054 = x6142;
      long* x6144 = x6056;
      long* x6145 = (long*)realloc(x6144,x6105 * sizeof(long));
      x6056 = x6145;
    } else {
    }
    int* x6158 = x6032;
    x6158[x6102] = x6065;
    long* x6180 = x6054;
    x6180[x6102] = x6082;
    long* x6182 = x6056;
    x6182[x6102] = x6086;
    x6030 = x6030 + 1;
  }
  FILE* x6194 = fopen("../databases/sf2/orders.tbl", "r");
  int x6195 = 1048576;
  int x6196 = 0;
  int* x6197 = (int*)malloc(1048576 * sizeof(int));
  int* x6198 = x6197;
  long* x6205 = (long*)malloc(1048576 * sizeof(long));
  long* x6206 = x6205;
  char** x6207 = (char**)malloc(1048576 * sizeof(char*));
  char** x6208 = x6207;
  for (;;) {
    bool x6215 = !feof(x6194);
    if (!x6215) break;
    int x6217 = 0;
    if (fscanf(x6194,"%d|",&x6217) == EOF) break;
    int x6218 = 0;
    if (fscanf(x6194,"%d|",&x6218) == EOF) break;
    char x6219 = ' ';
    if (fscanf(x6194,"%c|",&x6219) == EOF) break;
    double x6220 = 0.0;
    if (fscanf(x6194,"%lf|",&x6220) == EOF) break;
    int x6221 = 0;
    int x6222 = 0;
    int x6223 = 0;
    fscanf(x6194, "%d-%d-%d|",&x6221, &x6222, &x6223);
    long x6224 = (x6221 * 10000) + (x6222 * 100) + x6223;
    char* x6225 = (char*)malloc(16 * sizeof(char));
    int x6227 = 0;
    char x6226 = ' ';
    while (1) {
      fscanf(x6194,"%c",&x6226);
      if (x6226=='|' || x6226=='\n') break;
      if (x6227>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x6227); break;}
      ((char*)x6225)[x6227] = x6226;
      x6227 += 1;
    }
    ((char*)x6225)[x6227] = '\0';
    char* x6229 = x6225; // unsafe immutable;
    char* x6230 = (char*)malloc(16 * sizeof(char));
    int x6232 = 0;
    char x6231 = ' ';
    while (1) {
      fscanf(x6194,"%c",&x6231);
      if (x6231=='|' || x6231=='\n') break;
      if (x6232>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x6232); break;}
      ((char*)x6230)[x6232] = x6231;
      x6232 += 1;
    }
    ((char*)x6230)[x6232] = '\0';
    int x6235 = 0;
    if (fscanf(x6194,"%d|",&x6235) == EOF) break;
    char* x6236 = (char*)malloc(80 * sizeof(char));
    int x6238 = 0;
    char x6237 = ' ';
    while (1) {
      fscanf(x6194,"%c",&x6237);
      if (x6237=='|' || x6237=='\n') break;
      if (x6238>=79) { printf("ERROR: scanner.nextString reading past end of buffer %d",x6238); break;}
      ((char*)x6236)[x6238] = x6237;
      x6238 += 1;
    }
    ((char*)x6236)[x6238] = '\0';
    int x6241 = x6196;
    int x6242 = x6195;
    bool x6243 = x6241 == x6242;
    if (x6243) {
      int x6244 = x6242 * 4;
      x6195 = x6244;
      printf("buffer.resize %d\n",x6244);
      int* x6247 = x6198;
      int* x6248 = (int*)realloc(x6247,x6244 * sizeof(int));
      x6198 = x6248;
      long* x6259 = x6206;
      long* x6260 = (long*)realloc(x6259,x6244 * sizeof(long));
      x6206 = x6260;
      char** x6262 = x6208;
      char** x6263 = (char**)realloc(x6262,x6244 * sizeof(char*));
      x6208 = x6263;
    } else {
    }
    int* x6276 = x6198;
    x6276[x6241] = x6217;
    long* x6284 = x6206;
    x6284[x6241] = x6224;
    char** x6286 = x6208;
    x6286[x6241] = x6229;
    x6196 = x6196 + 1;
  }
  GTree* x6298 = g_tree_new((GCompareFunc)x6684);;
  bool x6299 = true == false;
  int x5629;
  for(x5629=0; x5629 < 1; x5629++) {
    bool x6300 = false;
    int x6301 = 0;
    bool x6303 = false;
    int x6304 = 0;
    int* x6307 = (int*)malloc(1073741824 * sizeof(int));
    int* x6308 = x6307;
    int x6339 = 0;
    int* x6340 = (int*)malloc(1048576 * sizeof(int));
    int* x6341 = (int*)malloc(1073741824 * sizeof(int));
    int x5672;
    for(x5672=0; x5672 < 1048576; x5672++) {
      x6340[x5672] = -1;
    }
    int x6346 = 1048576;
    int x6347 = 0;
    char** x6348 = (char**)malloc(1048576 * sizeof(char*));
    char** x6349 = x6348;
    double* x6350 = (double*)malloc(1048576 * sizeof(double));
    double* x6351 = x6350;
    int x6352 = 4194304;
    int x6353 = 0;
    int* x6354 = (int*)malloc(4194304 * sizeof(int));
    int* x6355 = x6354;
    int x5687;
    for(x5687=0; x5687 < 4194304; x5687++) {
      int* x6356 = x6355;
      x6356[x5687] = -1;
    }
    int x6364 = 0;
    struct timeval x6016, x6017, x6677;
    gettimeofday(&x6016, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x6366 = x6303;
      bool x6367 = !x6366;
      bool x6372 = x6367;
      if (x6367) {
        int x6368 = x6304;
        int x6369 = x6030;
        bool x6370 = x6368 < x6369;
        x6372 = x6370;
      }
      bool x6373 = x6372;
      if (!x6373) break;
      int x6376 = x6304;
      int* x6377 = x6032;
      int x6378 = x6377[x6376];
      long* x6399 = x6054;
      long x6400 = x6399[x6376];
      long* x6401 = x6056;
      long x6402 = x6401[x6376];
      x6304 = x6304 + 1;
      bool x6410 = x6400 < x6402;
      if (x6410) {
        int x6411 = x6339;
        int* x6412 = x6308;
        x6412[x6411] = x6378;
        x6339 = x6339 + 1;
        int x6445 = x6378 & 1048575;
        int x6446 = x6340[x6445];
        x6340[x6445] = x6411;
        x6341[x6411] = x6446;
      } else {
      }
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x6455 = x6300;
      bool x6456 = !x6455;
      bool x6461 = x6456;
      if (x6456) {
        int x6457 = x6301;
        int x6458 = x6196;
        bool x6459 = x6457 < x6458;
        x6461 = x6459;
      }
      bool x6462 = x6461;
      if (!x6462) break;
      int x6465 = x6301;
      int* x6466 = x6198;
      int x6467 = x6466[x6465];
      long* x6474 = x6206;
      long x6475 = x6474[x6465];
      char** x6476 = x6208;
      char* x6477 = x6476[x6465];
      x6301 = x6301 + 1;
      bool x6485 = x6475 < 19931101L;
      bool x6487 = x6485;
      if (x6485) {
        bool x6486 = x6475 >= 19930801L;
        x6487 = x6486;
      }
      bool x6488 = x6487;
      if (x6488) {
        int x6489 = x6467 & 1048575;
        int x6490 = x6340[x6489];
        int x6491 = x6490;
        bool x6492 = x6490 == -1;
        bool x6493 = x6492;
        for (;;) {
          bool x6494 = x6493;
          bool x6495 = !x6494;
          if (!x6495) break;
          int x6497 = x6491;
          int* x6498 = x6308;
          int x6499 = x6498[x6497];
          bool x6530 = x6467 == x6499;
          if (x6530) {
            x6493 = true;
          } else {
            int x6533 = x6341[x6497];
            x6491 = x6533;
            bool x6535 = x6533 == -1;
            x6493 = x6535;
          }
        }
        int x6543 = x6491;
        bool x6544 = x6543 == -1;
        if (x6544) {
        } else {
          int x6546 = x6352;
          int x6547 = x6546 - 1;
          char x6548 = x6477[0];
          int x6549 = x6548 * 2;
          int x6550 = x6549 * 3;
          int x6551 = x6550 & x6547;
          int x6552 = x6551;
          int* x6553 = x6355;
          int x6554 = x6553[x6551];
          int x6555 = x6554;
          int x6556 = x6551 + 1;
          int x6557 = x6553[x6556];
          int x6558 = x6557;
          for (;;) {
            int x6559 = x6555;
            bool x6560 = x6559 != -1;
            bool x6576 = x6560;
            if (x6560) {
              int x6561 = x6558;
              bool x6562 = x6561 != x6550;
              bool x6572 = x6562;
              if (x6562 == false) {
                int x6563 = x6555;
                char** x6564 = x6349;
                char* x6565 = x6564[x6563];
                bool x6568 = strcmp(x6565,x6477) == 0;;
                bool x6569 = !x6568;
                x6572 = x6569;
              }
              bool x6573 = x6572;
              x6576 = x6573;
            }
            bool x6577 = x6576;
            if (!x6577) break;
            int x6580 = x6552;
            int x6581 = x6580 + 2;
            int x6582 = x6581 & x6547;
            x6552 = x6582;
            int* x6584 = x6355;
            int x6585 = x6584[x6582];
            x6555 = x6585;
            int x6587 = x6582 + 1;
            int x6588 = x6584[x6587];
            x6558 = x6588;
          }
          int x6593 = x6555;
          bool x6594 = x6593 == -1;
          int x6629;
          if (x6594) {
            int x6595 = x6353;
            int x6596 = x6552;
            x6553[x6596] = x6595;
            int x6598 = x6596 + 1;
            x6553[x6598] = x6550;
            x6353 = x6353 + 1;
            int x6601 = x6347;
            int x6602 = x6346;
            bool x6603 = x6601 == x6602;
            if (x6603) {
              int x6604 = x6602 * 4;
              x6346 = x6604;
              printf("buffer.resize %d\n",x6604);
              char** x6607 = x6349;
              char** x6608 = (char**)realloc(x6607,x6604 * sizeof(char*));
              x6349 = x6608;
              printf("buffer.resize %d\n",x6604);
              double* x6611 = x6351;
              double* x6612 = (double*)realloc(x6611,x6604 * sizeof(double));
              x6351 = x6612;
            } else {
            }
            char** x6616 = x6349;
            x6616[x6601] = x6477;
            double* x6618 = x6351;
            x6618[x6601] = 0.0;
            x6347 = x6347 + 1;
            int x6621 = x6353;
            int x6622 = x6621 * 4;
            bool x6623 = x6622 > x6546;
            if (x6623) {
              printf("%s\n","ERROR: hash.resize not implemented");
            } else {
            }
            x6629 = x6595;
          } else {
            x6629 = x6593;
          }
          char** x6630 = x6349;
          char* x6631 = x6630[x6629];
          double* x6632 = x6351;
          double x6633 = x6632[x6629];
          x6630[x6629] = x6631;
          double x6635 = x6633 + 1.0;
          x6632[x6629] = x6635;
        }
      } else {
      }
    }
    int x6646 = x6347;
    int x5987;
    for(x5987=0; x5987 < x6646; x5987++) {
      char** x6647 = x6349;
      char* x6648 = x6647[x5987];
      double* x6649 = x6351;
      double x6650 = x6649[x5987];
      struct Anon2052879266* x6651 = (struct Anon2052879266*)malloc(sizeof(struct Anon2052879266));
      x6651->_0 = x6650;
      struct Anon1812879556* x6652 = (struct Anon1812879556*)malloc(sizeof(struct Anon1812879556));
      x6652->key = x6648;
      x6652->aggs = x6651;
      g_tree_insert(x6298,x6652,x6652);; // x6653
    }
    for (;;) {
      int x6656 = g_tree_nnodes(x6298);
      bool x6657 = x6656 != 0;
      if (!x6657) break;
      struct Anon1812879556* x6659 = NULL;
      g_tree_foreach(x6298, (GTraverseFunc)x6690, &x6659);
      g_tree_remove(x6298,x6659);
      if (x6299) {
      } else {
        char* x6663 = x6659->key;;
        struct Anon2052879266* x6664 = x6659->aggs;;
        double x6665 = x6664->_0;;
        printf("%s|%.0f\n",x6663,x6665);
        x6364 = x6364 + 1;
      }
    }
    int x6673 = x6364;
    printf("(%d rows)\n",x6673);
    gettimeofday(&x6017, NULL);
    timeval_subtract(&x6677, &x6017, &x6016);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x6677.tv_sec * 1000) + (x6677.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
