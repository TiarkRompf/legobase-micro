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
struct Anon147418070;
struct Anon920667905Anon811555534Anon168903330;
struct Anon1465150758;
struct Anon546410247;
struct Anon1078540535;
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
struct Anon348455037;
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

struct Anon1078540535 {
char* N_NAME;
int N_NATIONKEY;
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
struct Anon1268892766* left;
struct Anon348455037* right;
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

struct Anon1555625313 {
struct Anon1465150758* key;
struct Anon2052879266* aggs;
};

struct Anon704530870 {
struct Anon625264174* key;
struct Anon567626277* aggs;
};

/************************ FUNCTIONS **************************/
int x9239(struct Anon1812879556* x7375, struct Anon1812879556* x7374);
int x9245(struct Anon1812879556* x9240, struct Anon1812879556* x9241, struct Anon1812879556** x9242);
int x9239(struct Anon1812879556* x7375, struct Anon1812879556* x7374) {
  struct Anon2052879266* x7376 = x7374->aggs;;
  double x7377 = x7376->_0;;
  struct Anon2052879266* x7378 = x7375->aggs;;
  double x7379 = x7378->_0;;
  bool x7380 = x7377 < x7379;
  int x8551;
  if (x7380) {
    x8551 = 1;
  } else {
    bool x7381 = x7377 > x7379;
    int x8549;
    if (x7381) {
      x8549 = -1;
    } else {
      x8549 = 0;
    }
    x8551 = x8549;
  }
  return x8551;
}
int x9245(struct Anon1812879556* x9240, struct Anon1812879556* x9241, struct Anon1812879556** x9242) {
  *x9242 = x9241;
  return 0;
}

/************************ MAIN BODY **************************/
int main(int x6691, char** x6692) {
  FILE* x7983 = fopen("../databases/sf2/lineitem.tbl", "r");
  int x7984 = 1048576;
  int x7985 = 0;
  int* x7986 = (int*)malloc(1048576 * sizeof(int));
  int* x7987 = x7986;
  int* x7990 = (int*)malloc(1048576 * sizeof(int));
  int* x7991 = x7990;
  double* x7996 = (double*)malloc(1048576 * sizeof(double));
  double* x7997 = x7996;
  double* x7998 = (double*)malloc(1048576 * sizeof(double));
  double* x7999 = x7998;
  for (;;) {
    bool x8018 = !feof(x7983);
    if (!x8018) break;
    int x8020 = 0;
    if (fscanf(x7983,"%d|",&x8020) == EOF) break;
    int x8021 = 0;
    if (fscanf(x7983,"%d|",&x8021) == EOF) break;
    int x8022 = 0;
    if (fscanf(x7983,"%d|",&x8022) == EOF) break;
    int x8023 = 0;
    if (fscanf(x7983,"%d|",&x8023) == EOF) break;
    double x8024 = 0.0;
    if (fscanf(x7983,"%lf|",&x8024) == EOF) break;
    double x8025 = 0.0;
    if (fscanf(x7983,"%lf|",&x8025) == EOF) break;
    double x8026 = 0.0;
    if (fscanf(x7983,"%lf|",&x8026) == EOF) break;
    double x8027 = 0.0;
    if (fscanf(x7983,"%lf|",&x8027) == EOF) break;
    char x8028 = ' ';
    if (fscanf(x7983,"%c|",&x8028) == EOF) break;
    char x8029 = ' ';
    if (fscanf(x7983,"%c|",&x8029) == EOF) break;
    int x8030 = 0;
    int x8031 = 0;
    int x8032 = 0;
    fscanf(x7983, "%d-%d-%d|",&x8030, &x8031, &x8032);
    long x8033 = (x8030 * 10000) + (x8031 * 100) + x8032;
    int x8034 = 0;
    int x8035 = 0;
    int x8036 = 0;
    fscanf(x7983, "%d-%d-%d|",&x8034, &x8035, &x8036);
    long x8037 = (x8034 * 10000) + (x8035 * 100) + x8036;
    int x8038 = 0;
    int x8039 = 0;
    int x8040 = 0;
    fscanf(x7983, "%d-%d-%d|",&x8038, &x8039, &x8040);
    long x8041 = (x8038 * 10000) + (x8039 * 100) + x8040;
    char* x8042 = (char*)malloc(26 * sizeof(char));
    int x8044 = 0;
    char x8043 = ' ';
    while (1) {
      fscanf(x7983,"%c",&x8043);
      if (x8043=='|' || x8043=='\n') break;
      if (x8044>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x8044); break;}
      ((char*)x8042)[x8044] = x8043;
      x8044 += 1;
    }
    ((char*)x8042)[x8044] = '\0';
    char* x8047 = (char*)malloc(11 * sizeof(char));
    int x8049 = 0;
    char x8048 = ' ';
    while (1) {
      fscanf(x7983,"%c",&x8048);
      if (x8048=='|' || x8048=='\n') break;
      if (x8049>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x8049); break;}
      ((char*)x8047)[x8049] = x8048;
      x8049 += 1;
    }
    ((char*)x8047)[x8049] = '\0';
    char* x8052 = (char*)malloc(45 * sizeof(char));
    int x8054 = 0;
    char x8053 = ' ';
    while (1) {
      fscanf(x7983,"%c",&x8053);
      if (x8053=='|' || x8053=='\n') break;
      if (x8054>=44) { printf("ERROR: scanner.nextString reading past end of buffer %d",x8054); break;}
      ((char*)x8052)[x8054] = x8053;
      x8054 += 1;
    }
    ((char*)x8052)[x8054] = '\0';
    int x8057 = x7985;
    int x8058 = x7984;
    bool x8059 = x8057 == x8058;
    if (x8059) {
      int x8060 = x8058 * 4;
      x7984 = x8060;
      printf("buffer.resize %d\n",x8060);
      int* x8063 = x7987;
      int* x8064 = (int*)realloc(x8063,x8060 * sizeof(int));
      x7987 = x8064;
      int* x8069 = x7991;
      int* x8070 = (int*)realloc(x8069,x8060 * sizeof(int));
      x7991 = x8070;
      double* x8078 = x7997;
      double* x8079 = (double*)realloc(x8078,x8060 * sizeof(double));
      x7997 = x8079;
      double* x8081 = x7999;
      double* x8082 = (double*)realloc(x8081,x8060 * sizeof(double));
      x7999 = x8082;
    } else {
    }
    int* x8113 = x7987;
    x8113[x8057] = x8020;
    int* x8117 = x7991;
    x8117[x8057] = x8022;
    double* x8123 = x7997;
    x8123[x8057] = x8025;
    double* x8125 = x7999;
    x8125[x8057] = x8026;
    x7985 = x7985 + 1;
  }
  FILE* x8149 = fopen("../databases/sf2/nation.tbl", "r");
  int x8150 = 1048576;
  int x8151 = 0;
  int* x8152 = (int*)malloc(1048576 * sizeof(int));
  int* x8153 = x8152;
  char** x8154 = (char**)malloc(1048576 * sizeof(char*));
  char** x8155 = x8154;
  int* x8156 = (int*)malloc(1048576 * sizeof(int));
  int* x8157 = x8156;
  for (;;) {
    bool x8160 = !feof(x8149);
    if (!x8160) break;
    int x8162 = 0;
    if (fscanf(x8149,"%d|",&x8162) == EOF) break;
    char* x8163 = (char*)malloc(26 * sizeof(char));
    int x8165 = 0;
    char x8164 = ' ';
    while (1) {
      fscanf(x8149,"%c",&x8164);
      if (x8164=='|' || x8164=='\n') break;
      if (x8165>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x8165); break;}
      ((char*)x8163)[x8165] = x8164;
      x8165 += 1;
    }
    ((char*)x8163)[x8165] = '\0';
    char* x8167 = x8163; // unsafe immutable;
    int x8168 = 0;
    if (fscanf(x8149,"%d|",&x8168) == EOF) break;
    char* x8169 = (char*)malloc(153 * sizeof(char));
    int x8171 = 0;
    char x8170 = ' ';
    while (1) {
      fscanf(x8149,"%c",&x8170);
      if (x8170=='|' || x8170=='\n') break;
      if (x8171>=152) { printf("ERROR: scanner.nextString reading past end of buffer %d",x8171); break;}
      ((char*)x8169)[x8171] = x8170;
      x8171 += 1;
    }
    ((char*)x8169)[x8171] = '\0';
    int x8174 = x8151;
    int x8175 = x8150;
    bool x8176 = x8174 == x8175;
    if (x8176) {
      int x8177 = x8175 * 4;
      x8150 = x8177;
      printf("buffer.resize %d\n",x8177);
      int* x8180 = x8153;
      int* x8181 = (int*)realloc(x8180,x8177 * sizeof(int));
      x8153 = x8181;
      char** x8183 = x8155;
      char** x8184 = (char**)realloc(x8183,x8177 * sizeof(char*));
      x8155 = x8184;
      int* x8186 = x8157;
      int* x8187 = (int*)realloc(x8186,x8177 * sizeof(int));
      x8157 = x8187;
    } else {
    }
    int* x8194 = x8153;
    x8194[x8174] = x8162;
    char** x8196 = x8155;
    x8196[x8174] = x8167;
    int* x8198 = x8157;
    x8198[x8174] = x8168;
    x8151 = x8151 + 1;
  }
  FILE* x8206 = fopen("../databases/sf2/customer.tbl", "r");
  int x8207 = 1048576;
  int x8208 = 0;
  int* x8209 = (int*)malloc(1048576 * sizeof(int));
  int* x8210 = x8209;
  int* x8215 = (int*)malloc(1048576 * sizeof(int));
  int* x8216 = x8215;
  for (;;) {
    bool x8225 = !feof(x8206);
    if (!x8225) break;
    int x8227 = 0;
    if (fscanf(x8206,"%d|",&x8227) == EOF) break;
    char* x8228 = (char*)malloc(26 * sizeof(char));
    int x8230 = 0;
    char x8229 = ' ';
    while (1) {
      fscanf(x8206,"%c",&x8229);
      if (x8229=='|' || x8229=='\n') break;
      if (x8230>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x8230); break;}
      ((char*)x8228)[x8230] = x8229;
      x8230 += 1;
    }
    ((char*)x8228)[x8230] = '\0';
    char* x8233 = (char*)malloc(41 * sizeof(char));
    int x8235 = 0;
    char x8234 = ' ';
    while (1) {
      fscanf(x8206,"%c",&x8234);
      if (x8234=='|' || x8234=='\n') break;
      if (x8235>=40) { printf("ERROR: scanner.nextString reading past end of buffer %d",x8235); break;}
      ((char*)x8233)[x8235] = x8234;
      x8235 += 1;
    }
    ((char*)x8233)[x8235] = '\0';
    int x8238 = 0;
    if (fscanf(x8206,"%d|",&x8238) == EOF) break;
    char* x8239 = (char*)malloc(16 * sizeof(char));
    int x8241 = 0;
    char x8240 = ' ';
    while (1) {
      fscanf(x8206,"%c",&x8240);
      if (x8240=='|' || x8240=='\n') break;
      if (x8241>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x8241); break;}
      ((char*)x8239)[x8241] = x8240;
      x8241 += 1;
    }
    ((char*)x8239)[x8241] = '\0';
    double x8244 = 0.0;
    if (fscanf(x8206,"%lf|",&x8244) == EOF) break;
    char* x8245 = (char*)malloc(11 * sizeof(char));
    int x8247 = 0;
    char x8246 = ' ';
    while (1) {
      fscanf(x8206,"%c",&x8246);
      if (x8246=='|' || x8246=='\n') break;
      if (x8247>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x8247); break;}
      ((char*)x8245)[x8247] = x8246;
      x8247 += 1;
    }
    ((char*)x8245)[x8247] = '\0';
    char* x8250 = (char*)malloc(118 * sizeof(char));
    int x8252 = 0;
    char x8251 = ' ';
    while (1) {
      fscanf(x8206,"%c",&x8251);
      if (x8251=='|' || x8251=='\n') break;
      if (x8252>=117) { printf("ERROR: scanner.nextString reading past end of buffer %d",x8252); break;}
      ((char*)x8250)[x8252] = x8251;
      x8252 += 1;
    }
    ((char*)x8250)[x8252] = '\0';
    int x8255 = x8208;
    int x8256 = x8207;
    bool x8257 = x8255 == x8256;
    if (x8257) {
      int x8258 = x8256 * 4;
      x8207 = x8258;
      printf("buffer.resize %d\n",x8258);
      int* x8261 = x8210;
      int* x8262 = (int*)realloc(x8261,x8258 * sizeof(int));
      x8210 = x8262;
      int* x8270 = x8216;
      int* x8271 = (int*)realloc(x8270,x8258 * sizeof(int));
      x8216 = x8271;
    } else {
    }
    int* x8287 = x8210;
    x8287[x8255] = x8227;
    int* x8293 = x8216;
    x8293[x8255] = x8238;
    x8208 = x8208 + 1;
  }
  FILE* x8307 = fopen("../databases/sf2/supplier.tbl", "r");
  int x8308 = 1048576;
  int x8309 = 0;
  int* x8310 = (int*)malloc(1048576 * sizeof(int));
  int* x8311 = x8310;
  int* x8316 = (int*)malloc(1048576 * sizeof(int));
  int* x8317 = x8316;
  for (;;) {
    bool x8324 = !feof(x8307);
    if (!x8324) break;
    int x8326 = 0;
    if (fscanf(x8307,"%d|",&x8326) == EOF) break;
    char* x8327 = (char*)malloc(26 * sizeof(char));
    int x8329 = 0;
    char x8328 = ' ';
    while (1) {
      fscanf(x8307,"%c",&x8328);
      if (x8328=='|' || x8328=='\n') break;
      if (x8329>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x8329); break;}
      ((char*)x8327)[x8329] = x8328;
      x8329 += 1;
    }
    ((char*)x8327)[x8329] = '\0';
    char* x8332 = (char*)malloc(41 * sizeof(char));
    int x8334 = 0;
    char x8333 = ' ';
    while (1) {
      fscanf(x8307,"%c",&x8333);
      if (x8333=='|' || x8333=='\n') break;
      if (x8334>=40) { printf("ERROR: scanner.nextString reading past end of buffer %d",x8334); break;}
      ((char*)x8332)[x8334] = x8333;
      x8334 += 1;
    }
    ((char*)x8332)[x8334] = '\0';
    int x8337 = 0;
    if (fscanf(x8307,"%d|",&x8337) == EOF) break;
    char* x8338 = (char*)malloc(16 * sizeof(char));
    int x8340 = 0;
    char x8339 = ' ';
    while (1) {
      fscanf(x8307,"%c",&x8339);
      if (x8339=='|' || x8339=='\n') break;
      if (x8340>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x8340); break;}
      ((char*)x8338)[x8340] = x8339;
      x8340 += 1;
    }
    ((char*)x8338)[x8340] = '\0';
    double x8343 = 0.0;
    if (fscanf(x8307,"%lf|",&x8343) == EOF) break;
    char* x8344 = (char*)malloc(102 * sizeof(char));
    int x8346 = 0;
    char x8345 = ' ';
    while (1) {
      fscanf(x8307,"%c",&x8345);
      if (x8345=='|' || x8345=='\n') break;
      if (x8346>=101) { printf("ERROR: scanner.nextString reading past end of buffer %d",x8346); break;}
      ((char*)x8344)[x8346] = x8345;
      x8346 += 1;
    }
    ((char*)x8344)[x8346] = '\0';
    int x8349 = x8309;
    int x8350 = x8308;
    bool x8351 = x8349 == x8350;
    if (x8351) {
      int x8352 = x8350 * 4;
      x8308 = x8352;
      printf("buffer.resize %d\n",x8352);
      int* x8355 = x8311;
      int* x8356 = (int*)realloc(x8355,x8352 * sizeof(int));
      x8311 = x8356;
      int* x8364 = x8317;
      int* x8365 = (int*)realloc(x8364,x8352 * sizeof(int));
      x8317 = x8365;
    } else {
    }
    int* x8378 = x8311;
    x8378[x8349] = x8326;
    int* x8384 = x8317;
    x8384[x8349] = x8337;
    x8309 = x8309 + 1;
  }
  FILE* x8396 = fopen("../databases/sf2/region.tbl", "r");
  int x8397 = 1048576;
  int x8398 = 0;
  int* x8399 = (int*)malloc(1048576 * sizeof(int));
  int* x8400 = x8399;
  char** x8401 = (char**)malloc(1048576 * sizeof(char*));
  char** x8402 = x8401;
  for (;;) {
    bool x8405 = !feof(x8396);
    if (!x8405) break;
    int x8407 = 0;
    if (fscanf(x8396,"%d|",&x8407) == EOF) break;
    char* x8408 = (char*)malloc(26 * sizeof(char));
    int x8410 = 0;
    char x8409 = ' ';
    while (1) {
      fscanf(x8396,"%c",&x8409);
      if (x8409=='|' || x8409=='\n') break;
      if (x8410>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x8410); break;}
      ((char*)x8408)[x8410] = x8409;
      x8410 += 1;
    }
    ((char*)x8408)[x8410] = '\0';
    char* x8412 = x8408; // unsafe immutable;
    char* x8413 = (char*)malloc(153 * sizeof(char));
    int x8415 = 0;
    char x8414 = ' ';
    while (1) {
      fscanf(x8396,"%c",&x8414);
      if (x8414=='|' || x8414=='\n') break;
      if (x8415>=152) { printf("ERROR: scanner.nextString reading past end of buffer %d",x8415); break;}
      ((char*)x8413)[x8415] = x8414;
      x8415 += 1;
    }
    ((char*)x8413)[x8415] = '\0';
    int x8418 = x8398;
    int x8419 = x8397;
    bool x8420 = x8418 == x8419;
    if (x8420) {
      int x8421 = x8419 * 4;
      x8397 = x8421;
      printf("buffer.resize %d\n",x8421);
      int* x8424 = x8400;
      int* x8425 = (int*)realloc(x8424,x8421 * sizeof(int));
      x8400 = x8425;
      char** x8427 = x8402;
      char** x8428 = (char**)realloc(x8427,x8421 * sizeof(char*));
      x8402 = x8428;
    } else {
    }
    int* x8435 = x8400;
    x8435[x8418] = x8407;
    char** x8437 = x8402;
    x8437[x8418] = x8412;
    x8398 = x8398 + 1;
  }
  FILE* x8445 = fopen("../databases/sf2/orders.tbl", "r");
  int x8446 = 1048576;
  int x8447 = 0;
  int* x8448 = (int*)malloc(1048576 * sizeof(int));
  int* x8449 = x8448;
  int* x8450 = (int*)malloc(1048576 * sizeof(int));
  int* x8451 = x8450;
  long* x8456 = (long*)malloc(1048576 * sizeof(long));
  long* x8457 = x8456;
  for (;;) {
    bool x8466 = !feof(x8445);
    if (!x8466) break;
    int x8468 = 0;
    if (fscanf(x8445,"%d|",&x8468) == EOF) break;
    int x8469 = 0;
    if (fscanf(x8445,"%d|",&x8469) == EOF) break;
    char x8470 = ' ';
    if (fscanf(x8445,"%c|",&x8470) == EOF) break;
    double x8471 = 0.0;
    if (fscanf(x8445,"%lf|",&x8471) == EOF) break;
    int x8472 = 0;
    int x8473 = 0;
    int x8474 = 0;
    fscanf(x8445, "%d-%d-%d|",&x8472, &x8473, &x8474);
    long x8475 = (x8472 * 10000) + (x8473 * 100) + x8474;
    char* x8476 = (char*)malloc(16 * sizeof(char));
    int x8478 = 0;
    char x8477 = ' ';
    while (1) {
      fscanf(x8445,"%c",&x8477);
      if (x8477=='|' || x8477=='\n') break;
      if (x8478>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x8478); break;}
      ((char*)x8476)[x8478] = x8477;
      x8478 += 1;
    }
    ((char*)x8476)[x8478] = '\0';
    char* x8481 = (char*)malloc(16 * sizeof(char));
    int x8483 = 0;
    char x8482 = ' ';
    while (1) {
      fscanf(x8445,"%c",&x8482);
      if (x8482=='|' || x8482=='\n') break;
      if (x8483>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x8483); break;}
      ((char*)x8481)[x8483] = x8482;
      x8483 += 1;
    }
    ((char*)x8481)[x8483] = '\0';
    int x8486 = 0;
    if (fscanf(x8445,"%d|",&x8486) == EOF) break;
    char* x8487 = (char*)malloc(80 * sizeof(char));
    int x8489 = 0;
    char x8488 = ' ';
    while (1) {
      fscanf(x8445,"%c",&x8488);
      if (x8488=='|' || x8488=='\n') break;
      if (x8489>=79) { printf("ERROR: scanner.nextString reading past end of buffer %d",x8489); break;}
      ((char*)x8487)[x8489] = x8488;
      x8489 += 1;
    }
    ((char*)x8487)[x8489] = '\0';
    int x8492 = x8447;
    int x8493 = x8446;
    bool x8494 = x8492 == x8493;
    if (x8494) {
      int x8495 = x8493 * 4;
      x8446 = x8495;
      printf("buffer.resize %d\n",x8495);
      int* x8498 = x8449;
      int* x8499 = (int*)realloc(x8498,x8495 * sizeof(int));
      x8449 = x8499;
      int* x8501 = x8451;
      int* x8502 = (int*)realloc(x8501,x8495 * sizeof(int));
      x8451 = x8502;
      long* x8510 = x8457;
      long* x8511 = (long*)realloc(x8510,x8495 * sizeof(long));
      x8457 = x8511;
    } else {
    }
    int* x8527 = x8449;
    x8527[x8492] = x8468;
    int* x8529 = x8451;
    x8529[x8492] = x8469;
    long* x8535 = x8457;
    x8535[x8492] = x8475;
    x8447 = x8447 + 1;
  }
  GTree* x8553 = g_tree_new((GCompareFunc)x9239);;
  bool x8554 = true == false;
  int x7259;
  for(x7259=0; x7259 < 1; x7259++) {
    bool x8555 = false;
    int x8556 = 0;
    bool x8558 = false;
    int x8559 = 0;
    bool x8560 = false;
    int x8561 = 0;
    bool x8562 = false;
    int x8563 = 0;
    bool x8564 = false;
    int x8565 = 0;
    bool x8566 = false;
    int x8567 = 0;
    int* x8570 = (int*)malloc(1073741824 * sizeof(int));
    int* x8571 = x8570;
    int x8576 = 0;
    int* x8577 = (int*)malloc(1048576 * sizeof(int));
    int* x8578 = (int*)malloc(1073741824 * sizeof(int));
    int x7284;
    for(x7284=0; x7284 < 1048576; x7284++) {
      x8577[x7284] = -1;
    }
    char** x8584 = (char**)malloc(1073741824 * sizeof(char*));
    char** x8585 = x8584;
    int* x8586 = (int*)malloc(1073741824 * sizeof(int));
    int* x8587 = x8586;
    int x8588 = 0;
    int* x8589 = (int*)malloc(1048576 * sizeof(int));
    int* x8590 = (int*)malloc(1073741824 * sizeof(int));
    int x7297;
    for(x7297=0; x7297 < 1048576; x7297++) {
      x8589[x7297] = -1;
    }
    char** x8596 = (char**)malloc(1073741824 * sizeof(char*));
    char** x8597 = x8596;
    int* x8598 = (int*)malloc(1073741824 * sizeof(int));
    int* x8599 = x8598;
    int* x8600 = (int*)malloc(1073741824 * sizeof(int));
    int* x8601 = x8600;
    int x8602 = 0;
    int* x8603 = (int*)malloc(1048576 * sizeof(int));
    int* x8604 = (int*)malloc(1073741824 * sizeof(int));
    int x7312;
    for(x7312=0; x7312 < 1048576; x7312++) {
      x8603[x7312] = -1;
    }
    char** x8610 = (char**)malloc(1073741824 * sizeof(char*));
    char** x8611 = x8610;
    int* x8612 = (int*)malloc(1073741824 * sizeof(int));
    int* x8613 = x8612;
    int* x8614 = (int*)malloc(1073741824 * sizeof(int));
    int* x8615 = x8614;
    int x8616 = 0;
    int* x8617 = (int*)malloc(1048576 * sizeof(int));
    int* x8618 = (int*)malloc(1073741824 * sizeof(int));
    int x7327;
    for(x7327=0; x7327 < 1048576; x7327++) {
      x8617[x7327] = -1;
    }
    int* x8624 = (int*)malloc(1073741824 * sizeof(int));
    int* x8625 = x8624;
    int* x8630 = (int*)malloc(1073741824 * sizeof(int));
    int* x8631 = x8630;
    int x8638 = 0;
    int* x8639 = (int*)malloc(1048576 * sizeof(int));
    int* x8640 = (int*)malloc(1073741824 * sizeof(int));
    int x7350;
    for(x7350=0; x7350 < 1048576; x7350++) {
      x8639[x7350] = -1;
    }
    int x8646 = 1048576;
    int x8647 = 0;
    char** x8648 = (char**)malloc(1048576 * sizeof(char*));
    char** x8649 = x8648;
    double* x8650 = (double*)malloc(1048576 * sizeof(double));
    double* x8651 = x8650;
    int x8652 = 4194304;
    int x8653 = 0;
    int* x8654 = (int*)malloc(4194304 * sizeof(int));
    int* x8655 = x8654;
    int x7366;
    for(x7366=0; x7366 < 4194304; x7366++) {
      int* x8656 = x8655;
      x8656[x7366] = -1;
    }
    int x8664 = 0;
    struct timeval x7969, x7970, x9232;
    gettimeofday(&x7969, NULL);
    printf("(SUPPLIER X ((((REGION X NATION) X CUSTOMER) X ORDERS) X LINEITEM)): leftParent.next start\n");
    struct timeval x7439, x7440, x8718;
    gettimeofday(&x7439, NULL);
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x8667 = x8560;
      bool x8668 = !x8667;
      bool x8673 = x8668;
      if (x8668) {
        int x8669 = x8561;
        int x8670 = x8309;
        bool x8671 = x8669 < x8670;
        x8673 = x8671;
      }
      bool x8674 = x8673;
      if (!x8674) break;
      int x8677 = x8561;
      int* x8678 = x8311;
      int x8679 = x8678[x8677];
      int* x8684 = x8317;
      int x8685 = x8684[x8677];
      x8561 = x8561 + 1;
      int x8693 = x8638;
      int* x8694 = x8625;
      x8694[x8693] = x8679;
      int* x8700 = x8631;
      x8700[x8693] = x8685;
      x8638 = x8638 + 1;
      int x8709 = x8679 & 1048575;
      int x8710 = x8639[x8709];
      x8639[x8709] = x8693;
      x8640[x8693] = x8710;
    }
    printf("(SUPPLIER X ((((REGION X NATION) X CUSTOMER) X ORDERS) X LINEITEM)): leftParent.next done\n");
    gettimeofday(&x7440, NULL);
    timeval_subtract(&x8718, &x7440, &x7439);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x8718.tv_sec * 1000) + (x8718.tv_usec/1000)));
    printf("(SUPPLIER X ((((REGION X NATION) X CUSTOMER) X ORDERS) X LINEITEM)): rightParent.next start\n");
    struct timeval x7934, x7935, x9199;
    gettimeofday(&x7934, NULL);
    printf("((((REGION X NATION) X CUSTOMER) X ORDERS) X LINEITEM): leftParent.next start\n");
    struct timeval x7719, x7720, x8990;
    gettimeofday(&x7719, NULL);
    printf("(((REGION X NATION) X CUSTOMER) X ORDERS): leftParent.next start\n");
    struct timeval x7632, x7633, x8905;
    gettimeofday(&x7632, NULL);
    printf("((REGION X NATION) X CUSTOMER): leftParent.next start\n");
    struct timeval x7555, x7556, x8831;
    gettimeofday(&x7555, NULL);
    printf("(REGION X NATION): leftParent.next start\n");
    struct timeval x7486, x7487, x8765;
    gettimeofday(&x7486, NULL);
    printf("%s\n","begin scan REGION");
    for (;;) {
      bool x8726 = x8555;
      bool x8727 = !x8726;
      bool x8732 = x8727;
      if (x8727) {
        int x8728 = x8556;
        int x8729 = x8398;
        bool x8730 = x8728 < x8729;
        x8732 = x8730;
      }
      bool x8733 = x8732;
      if (!x8733) break;
      int x8736 = x8556;
      int* x8737 = x8400;
      int x8738 = x8737[x8736];
      char** x8739 = x8402;
      char* x8740 = x8739[x8736];
      x8556 = x8556 + 1;
      bool x8744 = strcmp(x8740,"ASIA") == 0;;
      if (x8744) {
        int x8745 = x8576;
        int* x8746 = x8571;
        x8746[x8745] = x8738;
        x8576 = x8576 + 1;
        int x8753 = x8738 & 1048575;
        int x8754 = x8577[x8753];
        x8577[x8753] = x8745;
        x8578[x8745] = x8754;
      } else {
      }
    }
    printf("(REGION X NATION): leftParent.next done\n");
    gettimeofday(&x7487, NULL);
    timeval_subtract(&x8765, &x7487, &x7486);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x8765.tv_sec * 1000) + (x8765.tv_usec/1000)));
    printf("(REGION X NATION): rightParent.next start\n");
    struct timeval x7549, x7550, x8826;
    gettimeofday(&x7549, NULL);
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x8769 = x8558;
      bool x8770 = !x8769;
      bool x8775 = x8770;
      if (x8770) {
        int x8771 = x8559;
        int x8772 = x8151;
        bool x8773 = x8771 < x8772;
        x8775 = x8773;
      }
      bool x8776 = x8775;
      if (!x8776) break;
      int x8779 = x8559;
      int* x8780 = x8153;
      int x8781 = x8780[x8779];
      char** x8782 = x8155;
      char* x8783 = x8782[x8779];
      int* x8784 = x8157;
      int x8785 = x8784[x8779];
      x8559 = x8559 + 1;
      int x8789 = x8785 & 1048575;
      int x8790 = x8577[x8789];
      int x8791 = x8790;
      int x8792 = x8781 & 1048575;
      for (;;) {
        int x8793 = x8791;
        bool x8794 = x8793 != -1;
        if (!x8794) break;
        int x8796 = x8791;
        int* x8797 = x8571;
        int x8798 = x8797[x8796];
        int x8803 = x8578[x8796];
        x8791 = x8803;
        bool x8805 = x8798 == x8785;
        if (x8805) {
          int x8806 = x8588;
          char** x8807 = x8585;
          x8807[x8806] = x8783;
          int* x8809 = x8587;
          x8809[x8806] = x8781;
          x8588 = x8588 + 1;
          int x8812 = x8589[x8792];
          x8589[x8792] = x8806;
          x8590[x8806] = x8812;
        } else {
        }
      }
    }
    printf("(REGION X NATION): rightParent.next done\n");
    gettimeofday(&x7550, NULL);
    timeval_subtract(&x8826, &x7550, &x7549);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x8826.tv_sec * 1000) + (x8826.tv_usec/1000)));
    printf("((REGION X NATION) X CUSTOMER): leftParent.next done\n");
    gettimeofday(&x7556, NULL);
    timeval_subtract(&x8831, &x7556, &x7555);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x8831.tv_sec * 1000) + (x8831.tv_usec/1000)));
    printf("((REGION X NATION) X CUSTOMER): rightParent.next start\n");
    struct timeval x7626, x7627, x8900;
    gettimeofday(&x7626, NULL);
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x8835 = x8562;
      bool x8836 = !x8835;
      bool x8841 = x8836;
      if (x8836) {
        int x8837 = x8563;
        int x8838 = x8208;
        bool x8839 = x8837 < x8838;
        x8841 = x8839;
      }
      bool x8842 = x8841;
      if (!x8842) break;
      int x8845 = x8563;
      int* x8846 = x8210;
      int x8847 = x8846[x8845];
      int* x8852 = x8216;
      int x8853 = x8852[x8845];
      x8563 = x8563 + 1;
      int x8863 = x8853 & 1048575;
      int x8864 = x8589[x8863];
      int x8865 = x8864;
      int x8866 = x8847 & 1048575;
      for (;;) {
        int x8867 = x8865;
        bool x8868 = x8867 != -1;
        if (!x8868) break;
        int x8870 = x8865;
        char** x8871 = x8585;
        char* x8872 = x8871[x8870];
        int* x8873 = x8587;
        int x8874 = x8873[x8870];
        int x8875 = x8590[x8870];
        x8865 = x8875;
        bool x8877 = x8874 == x8853;
        if (x8877) {
          int x8878 = x8602;
          char** x8879 = x8597;
          x8879[x8878] = x8872;
          int* x8881 = x8599;
          x8881[x8878] = x8874;
          int* x8883 = x8601;
          x8883[x8878] = x8847;
          x8602 = x8602 + 1;
          int x8886 = x8603[x8866];
          x8603[x8866] = x8878;
          x8604[x8878] = x8886;
        } else {
        }
      }
    }
    printf("((REGION X NATION) X CUSTOMER): rightParent.next done\n");
    gettimeofday(&x7627, NULL);
    timeval_subtract(&x8900, &x7627, &x7626);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x8900.tv_sec * 1000) + (x8900.tv_usec/1000)));
    printf("(((REGION X NATION) X CUSTOMER) X ORDERS): leftParent.next done\n");
    gettimeofday(&x7633, NULL);
    timeval_subtract(&x8905, &x7633, &x7632);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x8905.tv_sec * 1000) + (x8905.tv_usec/1000)));
    printf("(((REGION X NATION) X CUSTOMER) X ORDERS): rightParent.next start\n");
    struct timeval x7713, x7714, x8985;
    gettimeofday(&x7713, NULL);
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x8909 = x8566;
      bool x8910 = !x8909;
      bool x8915 = x8910;
      if (x8910) {
        int x8911 = x8567;
        int x8912 = x8447;
        bool x8913 = x8911 < x8912;
        x8915 = x8913;
      }
      bool x8916 = x8915;
      if (!x8916) break;
      int x8919 = x8567;
      int* x8920 = x8449;
      int x8921 = x8920[x8919];
      int* x8922 = x8451;
      int x8923 = x8922[x8919];
      long* x8928 = x8457;
      long x8929 = x8928[x8919];
      x8567 = x8567 + 1;
      bool x8939 = x8929 >= 19960101L;
      bool x8941 = x8939;
      if (x8939) {
        bool x8940 = x8929 < 19970101L;
        x8941 = x8940;
      }
      bool x8942 = x8941;
      if (x8942) {
        int x8943 = x8923 & 1048575;
        int x8944 = x8603[x8943];
        int x8945 = x8944;
        int x8946 = x8921 & 1048575;
        for (;;) {
          int x8947 = x8945;
          bool x8948 = x8947 != -1;
          if (!x8948) break;
          int x8950 = x8945;
          char** x8951 = x8597;
          char* x8952 = x8951[x8950];
          int* x8953 = x8599;
          int x8954 = x8953[x8950];
          int* x8955 = x8601;
          int x8956 = x8955[x8950];
          int x8957 = x8604[x8950];
          x8945 = x8957;
          bool x8959 = x8956 == x8923;
          if (x8959) {
            int x8960 = x8616;
            char** x8961 = x8611;
            x8961[x8960] = x8952;
            int* x8963 = x8613;
            x8963[x8960] = x8954;
            int* x8965 = x8615;
            x8965[x8960] = x8921;
            x8616 = x8616 + 1;
            int x8968 = x8617[x8946];
            x8617[x8946] = x8960;
            x8618[x8960] = x8968;
          } else {
          }
        }
      } else {
      }
    }
    printf("(((REGION X NATION) X CUSTOMER) X ORDERS): rightParent.next done\n");
    gettimeofday(&x7714, NULL);
    timeval_subtract(&x8985, &x7714, &x7713);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x8985.tv_sec * 1000) + (x8985.tv_usec/1000)));
    printf("((((REGION X NATION) X CUSTOMER) X ORDERS) X LINEITEM): leftParent.next done\n");
    gettimeofday(&x7720, NULL);
    timeval_subtract(&x8990, &x7720, &x7719);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x8990.tv_sec * 1000) + (x8990.tv_usec/1000)));
    printf("((((REGION X NATION) X CUSTOMER) X ORDERS) X LINEITEM): rightParent.next start\n");
    struct timeval x7928, x7929, x9194;
    gettimeofday(&x7928, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x8994 = x8564;
      bool x8995 = !x8994;
      bool x9000 = x8995;
      if (x8995) {
        int x8996 = x8565;
        int x8997 = x7985;
        bool x8998 = x8996 < x8997;
        x9000 = x8998;
      }
      bool x9001 = x9000;
      if (!x9001) break;
      int x9004 = x8565;
      int* x9005 = x7987;
      int x9006 = x9005[x9004];
      int* x9009 = x7991;
      int x9010 = x9009[x9004];
      double* x9015 = x7997;
      double x9016 = x9015[x9004];
      double* x9017 = x7999;
      double x9018 = x9017[x9004];
      x8565 = x8565 + 1;
      int x9038 = x9006 & 1048575;
      int x9039 = x8617[x9038];
      int x9040 = x9039;
      int x9041 = x9010 & 1048575;
      double x9042 = 1.0 - x9018;
      double x9043 = x9016 * x9042;
      for (;;) {
        int x9044 = x9040;
        bool x9045 = x9044 != -1;
        if (!x9045) break;
        int x9047 = x9040;
        char** x9048 = x8611;
        char* x9049 = x9048[x9047];
        int* x9050 = x8613;
        int x9051 = x9050[x9047];
        int* x9052 = x8615;
        int x9053 = x9052[x9047];
        int x9054 = x8618[x9047];
        x9040 = x9054;
        bool x9056 = x9053 == x9006;
        if (x9056) {
          int x9057 = x8639[x9041];
          int x9058 = x9057;
          char x9059 = x9049[0];
          int x9060 = x9059 * 2;
          int x9061 = x9060 * 3;
          for (;;) {
            int x9062 = x9058;
            bool x9063 = x9062 != -1;
            if (!x9063) break;
            int x9065 = x9058;
            int* x9066 = x8625;
            int x9067 = x9066[x9065];
            int* x9072 = x8631;
            int x9073 = x9072[x9065];
            int x9080 = x8640[x9065];
            x9058 = x9080;
            bool x9082 = x9067 == x9010;
            if (x9082) {
              bool x9083 = x9073 == x9051;
              if (x9083) {
                int x9085 = x8652;
                int x9086 = x9085 - 1;
                int x9087 = x9061 & x9086;
                int x9088 = x9087;
                int* x9089 = x8655;
                int x9090 = x9089[x9087];
                int x9091 = x9090;
                int x9092 = x9087 + 1;
                int x9093 = x9089[x9092];
                int x9094 = x9093;
                for (;;) {
                  int x9095 = x9091;
                  bool x9096 = x9095 != -1;
                  bool x9112 = x9096;
                  if (x9096) {
                    int x9097 = x9094;
                    bool x9098 = x9097 != x9061;
                    bool x9108 = x9098;
                    if (x9098 == false) {
                      int x9099 = x9091;
                      char** x9100 = x8649;
                      char* x9101 = x9100[x9099];
                      bool x9104 = strcmp(x9101,x9049) == 0;;
                      bool x9105 = !x9104;
                      x9108 = x9105;
                    }
                    bool x9109 = x9108;
                    x9112 = x9109;
                  }
                  bool x9113 = x9112;
                  if (!x9113) break;
                  int x9116 = x9088;
                  int x9117 = x9116 + 2;
                  int x9118 = x9117 & x9086;
                  x9088 = x9118;
                  int* x9120 = x8655;
                  int x9121 = x9120[x9118];
                  x9091 = x9121;
                  int x9123 = x9118 + 1;
                  int x9124 = x9120[x9123];
                  x9094 = x9124;
                }
                int x9129 = x9091;
                bool x9130 = x9129 == -1;
                int x9165;
                if (x9130) {
                  int x9131 = x8653;
                  int x9132 = x9088;
                  x9089[x9132] = x9131;
                  int x9134 = x9132 + 1;
                  x9089[x9134] = x9061;
                  x8653 = x8653 + 1;
                  int x9137 = x8647;
                  int x9138 = x8646;
                  bool x9139 = x9137 == x9138;
                  if (x9139) {
                    int x9140 = x9138 * 4;
                    x8646 = x9140;
                    printf("buffer.resize %d\n",x9140);
                    char** x9143 = x8649;
                    char** x9144 = (char**)realloc(x9143,x9140 * sizeof(char*));
                    x8649 = x9144;
                    printf("buffer.resize %d\n",x9140);
                    double* x9147 = x8651;
                    double* x9148 = (double*)realloc(x9147,x9140 * sizeof(double));
                    x8651 = x9148;
                  } else {
                  }
                  char** x9152 = x8649;
                  x9152[x9137] = x9049;
                  double* x9154 = x8651;
                  x9154[x9137] = 0.0;
                  x8647 = x8647 + 1;
                  int x9157 = x8653;
                  int x9158 = x9157 * 4;
                  bool x9159 = x9158 > x9085;
                  if (x9159) {
                    printf("%s\n","ERROR: hash.resize not implemented");
                  } else {
                  }
                  x9165 = x9131;
                } else {
                  x9165 = x9129;
                }
                char** x9166 = x8649;
                char* x9167 = x9166[x9165];
                double* x9168 = x8651;
                double x9169 = x9168[x9165];
                x9166[x9165] = x9167;
                double x9171 = x9169 + x9043;
                x9168[x9165] = x9171;
              } else {
              }
            } else {
            }
          }
        } else {
        }
      }
    }
    printf("((((REGION X NATION) X CUSTOMER) X ORDERS) X LINEITEM): rightParent.next done\n");
    gettimeofday(&x7929, NULL);
    timeval_subtract(&x9194, &x7929, &x7928);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x9194.tv_sec * 1000) + (x9194.tv_usec/1000)));
    printf("(SUPPLIER X ((((REGION X NATION) X CUSTOMER) X ORDERS) X LINEITEM)): rightParent.next done\n");
    gettimeofday(&x7935, NULL);
    timeval_subtract(&x9199, &x7935, &x7934);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x9199.tv_sec * 1000) + (x9199.tv_usec/1000)));
    int x9201 = x8647;
    int x7940;
    for(x7940=0; x7940 < x9201; x7940++) {
      char** x9202 = x8649;
      char* x9203 = x9202[x7940];
      double* x9204 = x8651;
      double x9205 = x9204[x7940];
      struct Anon2052879266* x9206 = (struct Anon2052879266*)malloc(sizeof(struct Anon2052879266));
      x9206->_0 = x9205;
      struct Anon1812879556* x9207 = (struct Anon1812879556*)malloc(sizeof(struct Anon1812879556));
      x9207->key = x9203;
      x9207->aggs = x9206;
      g_tree_insert(x8553,x9207,x9207);; // x9208
    }
    for (;;) {
      int x9211 = g_tree_nnodes(x8553);
      bool x9212 = x9211 != 0;
      if (!x9212) break;
      struct Anon1812879556* x9214 = NULL;
      g_tree_foreach(x8553, (GTraverseFunc)x9245, &x9214);
      g_tree_remove(x8553,x9214);
      if (x8554) {
      } else {
        char* x9218 = x9214->key;;
        struct Anon2052879266* x9219 = x9214->aggs;;
        double x9220 = x9219->_0;;
        printf("%s|%.4f\n",x9218,x9220);
        x8664 = x8664 + 1;
      }
    }
    int x9228 = x8664;
    printf("(%d rows)\n",x9228);
    gettimeofday(&x7970, NULL);
    timeval_subtract(&x9232, &x7970, &x7969);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x9232.tv_sec * 1000) + (x9232.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
