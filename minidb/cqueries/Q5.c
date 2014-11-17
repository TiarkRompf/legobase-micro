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
      int fsize(int fd) {
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

struct Anon787349517 {
bool exists;
int key;
struct Anon1023322325 aggs;
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

struct Anon2052879266 {
double _0;
};

struct Anon1007729034 {
bool exists;
char* key;
struct Anon2052879266 aggs;
};

struct Anon884569349 {
bool exists;
struct Anon1465150758 key;
struct Anon2052879266 aggs;
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

struct Anon1230230422 {
int key;
struct Anon1023322325 wnd;
};

struct Anon625264174 {
char L_RETURNFLAG;
char L_LINESTATUS;
};

struct Anon1272074242 {
bool exists;
struct Anon625264174 key;
struct Anon567626277 aggs;
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

struct Anon1124044545 {
struct Anon625264174 key;
struct Anon1296044246 aggs;
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
int main(int x5964, char** x5965) {
  int x5966 = 0;
  int x5967 = 1048576;
  int x5968 = 0;
  int* x5969 = (int*)malloc(1048576 * sizeof(int));
  int* x5970 = x5969;
  int* x5973 = (int*)malloc(1048576 * sizeof(int));
  int* x5974 = x5973;
  double* x5979 = (double*)malloc(1048576 * sizeof(double));
  double* x5980 = x5979;
  double* x5981 = (double*)malloc(1048576 * sizeof(double));
  double* x5982 = x5981;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  int x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    int x6001 = x5966;
    bool x6002 = x6001 < x3;
    if (!x6002) break;
    int x6005 = 0;
    for (;;) {
      int x6006 = x5966;
      char x6007 = x4[x6006];
      bool x6008 = x6007 != '|';
      bool x6013 = x6008;
      if (x6008) {
        int x6009 = x5966;
        char x6010 = x4[x6009];
        bool x6011 = x6010 != '\n';
        x6013 = x6011;
      }
      bool x6014 = x6013;
      if (!x6014) break;
      int x6016 = x6005;
      int x6018 = x5966;
      int x6017 = x6016 * 10;
      char x6019 = x4[x6018];
      char x6020 = x6019 - '0';
      int x6021 = x6017 + x6020;
      x6005 = x6021;
      x5966 = x5966 + 1;
    }
    x5966 = x5966 + 1;
    int x6027 = x6005;
    for (;;) {
      int x6030 = x5966;
      char x6031 = x4[x6030];
      bool x6032 = x6031 != '|';
      bool x6037 = x6032;
      if (x6032) {
        int x6033 = x5966;
        char x6034 = x4[x6033];
        bool x6035 = x6034 != '\n';
        x6037 = x6035;
      }
      bool x6038 = x6037;
      if (!x6038) break;
      x5966 = x5966 + 1;
    }
    x5966 = x5966 + 1;
    int x6053 = 0;
    for (;;) {
      int x6054 = x5966;
      char x6055 = x4[x6054];
      bool x6056 = x6055 != '|';
      bool x6061 = x6056;
      if (x6056) {
        int x6057 = x5966;
        char x6058 = x4[x6057];
        bool x6059 = x6058 != '\n';
        x6061 = x6059;
      }
      bool x6062 = x6061;
      if (!x6062) break;
      int x6064 = x6053;
      int x6066 = x5966;
      int x6065 = x6064 * 10;
      char x6067 = x4[x6066];
      char x6068 = x6067 - '0';
      int x6069 = x6065 + x6068;
      x6053 = x6069;
      x5966 = x5966 + 1;
    }
    x5966 = x5966 + 1;
    int x6075 = x6053;
    for (;;) {
      int x6078 = x5966;
      char x6079 = x4[x6078];
      bool x6080 = x6079 != '|';
      bool x6085 = x6080;
      if (x6080) {
        int x6081 = x5966;
        char x6082 = x4[x6081];
        bool x6083 = x6082 != '\n';
        x6085 = x6083;
      }
      bool x6086 = x6085;
      if (!x6086) break;
      x5966 = x5966 + 1;
    }
    x5966 = x5966 + 1;
    for (;;) {
      int x6103 = x5966;
      char x6104 = x4[x6103];
      bool x6105 = x6104 != '.';
      bool x6110 = x6105;
      if (x6105) {
        int x6106 = x5966;
        char x6107 = x4[x6106];
        bool x6108 = x6107 != '|';
        x6110 = x6108;
      }
      bool x6111 = x6110;
      bool x6116 = x6111;
      if (x6111) {
        int x6112 = x5966;
        char x6113 = x4[x6112];
        bool x6114 = x6113 != '\n';
        x6116 = x6114;
      }
      bool x6117 = x6116;
      if (!x6117) break;
      x5966 = x5966 + 1;
    }
    int x6129 = x5966;
    char x6130 = x4[x6129];
    bool x6131 = x6130 == '.';
    if (x6131) {
      x5966 = x5966 + 1;
      for (;;) {
        int x6133 = x5966;
        char x6134 = x4[x6133];
        bool x6135 = x6134 != '|';
        bool x6140 = x6135;
        if (x6135) {
          int x6136 = x5966;
          char x6137 = x4[x6136];
          bool x6138 = x6137 != '\n';
          x6140 = x6138;
        }
        bool x6141 = x6140;
        if (!x6141) break;
        x5966 = x5966 + 1;
      }
    } else {
    }
    x5966 = x5966 + 1;
    int x6166 = 0;
    int x6167 = 1;
    for (;;) {
      int x6168 = x5966;
      char x6169 = x4[x6168];
      bool x6170 = x6169 != '.';
      bool x6175 = x6170;
      if (x6170) {
        int x6171 = x5966;
        char x6172 = x4[x6171];
        bool x6173 = x6172 != '|';
        x6175 = x6173;
      }
      bool x6176 = x6175;
      bool x6181 = x6176;
      if (x6176) {
        int x6177 = x5966;
        char x6178 = x4[x6177];
        bool x6179 = x6178 != '\n';
        x6181 = x6179;
      }
      bool x6182 = x6181;
      if (!x6182) break;
      int x6184 = x6166;
      int x6186 = x5966;
      int x6185 = x6184 * 10;
      char x6187 = x4[x6186];
      char x6188 = x6187 - '0';
      int x6189 = x6185 + x6188;
      x6166 = x6189;
      x5966 = x5966 + 1;
    }
    int x6194 = x5966;
    char x6195 = x4[x6194];
    bool x6196 = x6195 == '.';
    if (x6196) {
      x5966 = x5966 + 1;
      for (;;) {
        int x6198 = x5966;
        char x6199 = x4[x6198];
        bool x6200 = x6199 != '|';
        bool x6205 = x6200;
        if (x6200) {
          int x6201 = x5966;
          char x6202 = x4[x6201];
          bool x6203 = x6202 != '\n';
          x6205 = x6203;
        }
        bool x6206 = x6205;
        if (!x6206) break;
        int x6208 = x6166;
        int x6210 = x5966;
        int x6209 = x6208 * 10;
        char x6211 = x4[x6210];
        char x6212 = x6211 - '0';
        int x6213 = x6209 + x6212;
        x6166 = x6213;
        int x6215 = x6167;
        int x6216 = x6215 * 10;
        x6167 = x6216;
        x5966 = x5966 + 1;
      }
    } else {
    }
    x5966 = x5966 + 1;
    int x6225 = x6166;
    int x6227 = x6167;
    int x6231 = 0;
    int x6232 = 1;
    for (;;) {
      int x6233 = x5966;
      char x6234 = x4[x6233];
      bool x6235 = x6234 != '.';
      bool x6240 = x6235;
      if (x6235) {
        int x6236 = x5966;
        char x6237 = x4[x6236];
        bool x6238 = x6237 != '|';
        x6240 = x6238;
      }
      bool x6241 = x6240;
      bool x6246 = x6241;
      if (x6241) {
        int x6242 = x5966;
        char x6243 = x4[x6242];
        bool x6244 = x6243 != '\n';
        x6246 = x6244;
      }
      bool x6247 = x6246;
      if (!x6247) break;
      int x6249 = x6231;
      int x6251 = x5966;
      int x6250 = x6249 * 10;
      char x6252 = x4[x6251];
      char x6253 = x6252 - '0';
      int x6254 = x6250 + x6253;
      x6231 = x6254;
      x5966 = x5966 + 1;
    }
    int x6259 = x5966;
    char x6260 = x4[x6259];
    bool x6261 = x6260 == '.';
    if (x6261) {
      x5966 = x5966 + 1;
      for (;;) {
        int x6263 = x5966;
        char x6264 = x4[x6263];
        bool x6265 = x6264 != '|';
        bool x6270 = x6265;
        if (x6265) {
          int x6266 = x5966;
          char x6267 = x4[x6266];
          bool x6268 = x6267 != '\n';
          x6270 = x6268;
        }
        bool x6271 = x6270;
        if (!x6271) break;
        int x6273 = x6231;
        int x6275 = x5966;
        int x6274 = x6273 * 10;
        char x6276 = x4[x6275];
        char x6277 = x6276 - '0';
        int x6278 = x6274 + x6277;
        x6231 = x6278;
        int x6280 = x6232;
        int x6281 = x6280 * 10;
        x6232 = x6281;
        x5966 = x5966 + 1;
      }
    } else {
    }
    x5966 = x5966 + 1;
    int x6290 = x6231;
    int x6292 = x6232;
    for (;;) {
      int x6298 = x5966;
      char x6299 = x4[x6298];
      bool x6300 = x6299 != '.';
      bool x6305 = x6300;
      if (x6300) {
        int x6301 = x5966;
        char x6302 = x4[x6301];
        bool x6303 = x6302 != '|';
        x6305 = x6303;
      }
      bool x6306 = x6305;
      bool x6311 = x6306;
      if (x6306) {
        int x6307 = x5966;
        char x6308 = x4[x6307];
        bool x6309 = x6308 != '\n';
        x6311 = x6309;
      }
      bool x6312 = x6311;
      if (!x6312) break;
      x5966 = x5966 + 1;
    }
    int x6324 = x5966;
    char x6325 = x4[x6324];
    bool x6326 = x6325 == '.';
    if (x6326) {
      x5966 = x5966 + 1;
      for (;;) {
        int x6328 = x5966;
        char x6329 = x4[x6328];
        bool x6330 = x6329 != '|';
        bool x6335 = x6330;
        if (x6330) {
          int x6331 = x5966;
          char x6332 = x4[x6331];
          bool x6333 = x6332 != '\n';
          x6335 = x6333;
        }
        bool x6336 = x6335;
        if (!x6336) break;
        x5966 = x5966 + 1;
      }
    } else {
    }
    x5966 = x5966 + 1;
    x5966 = x5966 + 2;
    x5966 = x5966 + 2;
    for (;;) {
      int x6368 = x5966;
      char x6369 = x4[x6368];
      bool x6370 = x6369 != '-';
      bool x6375 = x6370;
      if (x6370) {
        int x6371 = x5966;
        char x6372 = x4[x6371];
        bool x6373 = x6372 != '\n';
        x6375 = x6373;
      }
      bool x6376 = x6375;
      if (!x6376) break;
      x5966 = x5966 + 1;
    }
    x5966 = x5966 + 1;
    for (;;) {
      int x6392 = x5966;
      char x6393 = x4[x6392];
      bool x6394 = x6393 != '-';
      bool x6399 = x6394;
      if (x6394) {
        int x6395 = x5966;
        char x6396 = x4[x6395];
        bool x6397 = x6396 != '\n';
        x6399 = x6397;
      }
      bool x6400 = x6399;
      if (!x6400) break;
      x5966 = x5966 + 1;
    }
    x5966 = x5966 + 1;
    for (;;) {
      int x6416 = x5966;
      char x6417 = x4[x6416];
      bool x6418 = x6417 != '|';
      bool x6423 = x6418;
      if (x6418) {
        int x6419 = x5966;
        char x6420 = x4[x6419];
        bool x6421 = x6420 != '\n';
        x6423 = x6421;
      }
      bool x6424 = x6423;
      if (!x6424) break;
      x5966 = x5966 + 1;
    }
    x5966 = x5966 + 1;
    for (;;) {
      int x6444 = x5966;
      char x6445 = x4[x6444];
      bool x6446 = x6445 != '-';
      bool x6451 = x6446;
      if (x6446) {
        int x6447 = x5966;
        char x6448 = x4[x6447];
        bool x6449 = x6448 != '\n';
        x6451 = x6449;
      }
      bool x6452 = x6451;
      if (!x6452) break;
      x5966 = x5966 + 1;
    }
    x5966 = x5966 + 1;
    for (;;) {
      int x6468 = x5966;
      char x6469 = x4[x6468];
      bool x6470 = x6469 != '-';
      bool x6475 = x6470;
      if (x6470) {
        int x6471 = x5966;
        char x6472 = x4[x6471];
        bool x6473 = x6472 != '\n';
        x6475 = x6473;
      }
      bool x6476 = x6475;
      if (!x6476) break;
      x5966 = x5966 + 1;
    }
    x5966 = x5966 + 1;
    for (;;) {
      int x6492 = x5966;
      char x6493 = x4[x6492];
      bool x6494 = x6493 != '|';
      bool x6499 = x6494;
      if (x6494) {
        int x6495 = x5966;
        char x6496 = x4[x6495];
        bool x6497 = x6496 != '\n';
        x6499 = x6497;
      }
      bool x6500 = x6499;
      if (!x6500) break;
      x5966 = x5966 + 1;
    }
    x5966 = x5966 + 1;
    for (;;) {
      int x6520 = x5966;
      char x6521 = x4[x6520];
      bool x6522 = x6521 != '-';
      bool x6527 = x6522;
      if (x6522) {
        int x6523 = x5966;
        char x6524 = x4[x6523];
        bool x6525 = x6524 != '\n';
        x6527 = x6525;
      }
      bool x6528 = x6527;
      if (!x6528) break;
      x5966 = x5966 + 1;
    }
    x5966 = x5966 + 1;
    for (;;) {
      int x6544 = x5966;
      char x6545 = x4[x6544];
      bool x6546 = x6545 != '-';
      bool x6551 = x6546;
      if (x6546) {
        int x6547 = x5966;
        char x6548 = x4[x6547];
        bool x6549 = x6548 != '\n';
        x6551 = x6549;
      }
      bool x6552 = x6551;
      if (!x6552) break;
      x5966 = x5966 + 1;
    }
    x5966 = x5966 + 1;
    for (;;) {
      int x6568 = x5966;
      char x6569 = x4[x6568];
      bool x6570 = x6569 != '|';
      bool x6575 = x6570;
      if (x6570) {
        int x6571 = x5966;
        char x6572 = x4[x6571];
        bool x6573 = x6572 != '\n';
        x6575 = x6573;
      }
      bool x6576 = x6575;
      if (!x6576) break;
      x5966 = x5966 + 1;
    }
    x5966 = x5966 + 1;
    for (;;) {
      int x6595 = x5966;
      char x6596 = x4[x6595];
      bool x6597 = x6596 != '|';
      bool x6602 = x6597;
      if (x6597) {
        int x6598 = x5966;
        char x6599 = x4[x6598];
        bool x6600 = x6599 != '\n';
        x6602 = x6600;
      }
      bool x6603 = x6602;
      if (!x6603) break;
      x5966 = x5966 + 1;
    }
    x5966 = x5966 + 1;
    for (;;) {
      int x6613 = x5966;
      char x6614 = x4[x6613];
      bool x6615 = x6614 != '|';
      bool x6620 = x6615;
      if (x6615) {
        int x6616 = x5966;
        char x6617 = x4[x6616];
        bool x6618 = x6617 != '\n';
        x6620 = x6618;
      }
      bool x6621 = x6620;
      if (!x6621) break;
      x5966 = x5966 + 1;
    }
    x5966 = x5966 + 1;
    for (;;) {
      int x6631 = x5966;
      char x6632 = x4[x6631];
      bool x6633 = x6632 != '|';
      bool x6638 = x6633;
      if (x6633) {
        int x6634 = x5966;
        char x6635 = x4[x6634];
        bool x6636 = x6635 != '\n';
        x6638 = x6636;
      }
      bool x6639 = x6638;
      if (!x6639) break;
      x5966 = x5966 + 1;
    }
    x5966 = x5966 + 1;
    int x6649 = x5968;
    int x6650 = x5967;
    bool x6651 = x6649 == x6650;
    if (x6651) {
      int x6652 = x6650 * 4;
      x5967 = x6652;
      printf("buffer.resize %d\n",x6652);
      int* x6655 = x5970;
      int* x6656 = (int*)realloc(x6655,x6652 * sizeof(int));
      x5970 = x6656;
      int* x6661 = x5974;
      int* x6662 = (int*)realloc(x6661,x6652 * sizeof(int));
      x5974 = x6662;
      double* x6670 = x5980;
      double* x6671 = (double*)realloc(x6670,x6652 * sizeof(double));
      x5980 = x6671;
      double* x6673 = x5982;
      double* x6674 = (double*)realloc(x6673,x6652 * sizeof(double));
      x5982 = x6674;
    } else {
    }
    int* x6705 = x5970;
    x6705[x6649] = x6027;
    int* x6709 = x5974;
    x6709[x6649] = x6075;
    double* x6715 = x5980;
    double x6226 = (double)x6225;
    double x6228 = (double)x6227;
    double x6229 = x6226 / x6228;
    x6715[x6649] = x6229;
    double* x6717 = x5982;
    double x6291 = (double)x6290;
    double x6293 = (double)x6292;
    double x6294 = x6291 / x6293;
    x6717[x6649] = x6294;
    x5968 = x5968 + 1;
  }
  int x6740 = 0;
  int x6741 = 1048576;
  int x6742 = 0;
  int* x6743 = (int*)malloc(1048576 * sizeof(int));
  int* x6744 = x6743;
  char** x6745 = (char**)malloc(1048576 * sizeof(char*));
  char** x6746 = x6745;
  int* x6747 = (int*)malloc(1048576 * sizeof(int));
  int* x6748 = x6747;
  int x1512 = open("../databases/sf2/nation.tbl",0);
  int x1513 = fsize(x1512);
  char* x1514 = mmap(0, x1513, PROT_READ, MAP_FILE | MAP_SHARED, x1512, 0);
  for (;;) {
    int x6751 = x6740;
    bool x6752 = x6751 < x1513;
    if (!x6752) break;
    int x6755 = 0;
    for (;;) {
      int x6756 = x6740;
      char x6757 = x1514[x6756];
      bool x6758 = x6757 != '|';
      bool x6763 = x6758;
      if (x6758) {
        int x6759 = x6740;
        char x6760 = x1514[x6759];
        bool x6761 = x6760 != '\n';
        x6763 = x6761;
      }
      bool x6764 = x6763;
      if (!x6764) break;
      int x6766 = x6755;
      int x6768 = x6740;
      int x6767 = x6766 * 10;
      char x6769 = x1514[x6768];
      char x6770 = x6769 - '0';
      int x6771 = x6767 + x6770;
      x6755 = x6771;
      x6740 = x6740 + 1;
    }
    x6740 = x6740 + 1;
    int x6777 = x6755;
    int x6778 = x6740;
    for (;;) {
      int x6779 = x6740;
      char x6780 = x1514[x6779];
      bool x6781 = x6780 != '|';
      bool x6786 = x6781;
      if (x6781) {
        int x6782 = x6740;
        char x6783 = x1514[x6782];
        bool x6784 = x6783 != '\n';
        x6786 = x6784;
      }
      bool x6787 = x6786;
      if (!x6787) break;
      x6740 = x6740 + 1;
    }
    x6740 = x6740 + 1;
    int x6797 = 0;
    for (;;) {
      int x6798 = x6740;
      char x6799 = x1514[x6798];
      bool x6800 = x6799 != '|';
      bool x6805 = x6800;
      if (x6800) {
        int x6801 = x6740;
        char x6802 = x1514[x6801];
        bool x6803 = x6802 != '\n';
        x6805 = x6803;
      }
      bool x6806 = x6805;
      if (!x6806) break;
      int x6808 = x6797;
      int x6810 = x6740;
      int x6809 = x6808 * 10;
      char x6811 = x1514[x6810];
      char x6812 = x6811 - '0';
      int x6813 = x6809 + x6812;
      x6797 = x6813;
      x6740 = x6740 + 1;
    }
    x6740 = x6740 + 1;
    int x6819 = x6797;
    for (;;) {
      int x6821 = x6740;
      char x6822 = x1514[x6821];
      bool x6823 = x6822 != '|';
      bool x6828 = x6823;
      if (x6823) {
        int x6824 = x6740;
        char x6825 = x1514[x6824];
        bool x6826 = x6825 != '\n';
        x6828 = x6826;
      }
      bool x6829 = x6828;
      if (!x6829) break;
      x6740 = x6740 + 1;
    }
    x6740 = x6740 + 1;
    int x6839 = x6742;
    int x6840 = x6741;
    bool x6841 = x6839 == x6840;
    if (x6841) {
      int x6842 = x6840 * 4;
      x6741 = x6842;
      printf("buffer.resize %d\n",x6842);
      int* x6845 = x6744;
      int* x6846 = (int*)realloc(x6845,x6842 * sizeof(int));
      x6744 = x6846;
      char** x6848 = x6746;
      char** x6849 = (char**)realloc(x6848,x6842 * sizeof(char*));
      x6746 = x6849;
      int* x6851 = x6748;
      int* x6852 = (int*)realloc(x6851,x6842 * sizeof(int));
      x6748 = x6852;
    } else {
    }
    int* x6859 = x6744;
    x6859[x6839] = x6777;
    char** x6861 = x6746;
    char* x6795 = x1514+x6778;
    x6861[x6839] = x6795;
    int* x6863 = x6748;
    x6863[x6839] = x6819;
    x6742 = x6742 + 1;
  }
  int x6870 = 0;
  int x6871 = 1048576;
  int x6872 = 0;
  int* x6873 = (int*)malloc(1048576 * sizeof(int));
  int* x6874 = x6873;
  int* x6879 = (int*)malloc(1048576 * sizeof(int));
  int* x6880 = x6879;
  int x3720 = open("../databases/sf2/customer.tbl",0);
  int x3721 = fsize(x3720);
  char* x3722 = mmap(0, x3721, PROT_READ, MAP_FILE | MAP_SHARED, x3720, 0);
  for (;;) {
    int x6889 = x6870;
    bool x6890 = x6889 < x3721;
    if (!x6890) break;
    int x6893 = 0;
    for (;;) {
      int x6894 = x6870;
      char x6895 = x3722[x6894];
      bool x6896 = x6895 != '|';
      bool x6901 = x6896;
      if (x6896) {
        int x6897 = x6870;
        char x6898 = x3722[x6897];
        bool x6899 = x6898 != '\n';
        x6901 = x6899;
      }
      bool x6902 = x6901;
      if (!x6902) break;
      int x6904 = x6893;
      int x6906 = x6870;
      int x6905 = x6904 * 10;
      char x6907 = x3722[x6906];
      char x6908 = x6907 - '0';
      int x6909 = x6905 + x6908;
      x6893 = x6909;
      x6870 = x6870 + 1;
    }
    x6870 = x6870 + 1;
    int x6915 = x6893;
    for (;;) {
      int x6917 = x6870;
      char x6918 = x3722[x6917];
      bool x6919 = x6918 != '|';
      bool x6924 = x6919;
      if (x6919) {
        int x6920 = x6870;
        char x6921 = x3722[x6920];
        bool x6922 = x6921 != '\n';
        x6924 = x6922;
      }
      bool x6925 = x6924;
      if (!x6925) break;
      x6870 = x6870 + 1;
    }
    x6870 = x6870 + 1;
    for (;;) {
      int x6935 = x6870;
      char x6936 = x3722[x6935];
      bool x6937 = x6936 != '|';
      bool x6942 = x6937;
      if (x6937) {
        int x6938 = x6870;
        char x6939 = x3722[x6938];
        bool x6940 = x6939 != '\n';
        x6942 = x6940;
      }
      bool x6943 = x6942;
      if (!x6943) break;
      x6870 = x6870 + 1;
    }
    x6870 = x6870 + 1;
    int x6953 = 0;
    for (;;) {
      int x6954 = x6870;
      char x6955 = x3722[x6954];
      bool x6956 = x6955 != '|';
      bool x6961 = x6956;
      if (x6956) {
        int x6957 = x6870;
        char x6958 = x3722[x6957];
        bool x6959 = x6958 != '\n';
        x6961 = x6959;
      }
      bool x6962 = x6961;
      if (!x6962) break;
      int x6964 = x6953;
      int x6966 = x6870;
      int x6965 = x6964 * 10;
      char x6967 = x3722[x6966];
      char x6968 = x6967 - '0';
      int x6969 = x6965 + x6968;
      x6953 = x6969;
      x6870 = x6870 + 1;
    }
    x6870 = x6870 + 1;
    int x6975 = x6953;
    for (;;) {
      int x6977 = x6870;
      char x6978 = x3722[x6977];
      bool x6979 = x6978 != '|';
      bool x6984 = x6979;
      if (x6979) {
        int x6980 = x6870;
        char x6981 = x3722[x6980];
        bool x6982 = x6981 != '\n';
        x6984 = x6982;
      }
      bool x6985 = x6984;
      if (!x6985) break;
      x6870 = x6870 + 1;
    }
    x6870 = x6870 + 1;
    for (;;) {
      int x6997 = x6870;
      char x6998 = x3722[x6997];
      bool x6999 = x6998 != '.';
      bool x7004 = x6999;
      if (x6999) {
        int x7000 = x6870;
        char x7001 = x3722[x7000];
        bool x7002 = x7001 != '|';
        x7004 = x7002;
      }
      bool x7005 = x7004;
      bool x7010 = x7005;
      if (x7005) {
        int x7006 = x6870;
        char x7007 = x3722[x7006];
        bool x7008 = x7007 != '\n';
        x7010 = x7008;
      }
      bool x7011 = x7010;
      if (!x7011) break;
      x6870 = x6870 + 1;
    }
    int x7023 = x6870;
    char x7024 = x3722[x7023];
    bool x7025 = x7024 == '.';
    if (x7025) {
      x6870 = x6870 + 1;
      for (;;) {
        int x7027 = x6870;
        char x7028 = x3722[x7027];
        bool x7029 = x7028 != '|';
        bool x7034 = x7029;
        if (x7029) {
          int x7030 = x6870;
          char x7031 = x3722[x7030];
          bool x7032 = x7031 != '\n';
          x7034 = x7032;
        }
        bool x7035 = x7034;
        if (!x7035) break;
        x6870 = x6870 + 1;
      }
    } else {
    }
    x6870 = x6870 + 1;
    for (;;) {
      int x7060 = x6870;
      char x7061 = x3722[x7060];
      bool x7062 = x7061 != '|';
      bool x7067 = x7062;
      if (x7062) {
        int x7063 = x6870;
        char x7064 = x3722[x7063];
        bool x7065 = x7064 != '\n';
        x7067 = x7065;
      }
      bool x7068 = x7067;
      if (!x7068) break;
      x6870 = x6870 + 1;
    }
    x6870 = x6870 + 1;
    for (;;) {
      int x7078 = x6870;
      char x7079 = x3722[x7078];
      bool x7080 = x7079 != '|';
      bool x7085 = x7080;
      if (x7080) {
        int x7081 = x6870;
        char x7082 = x3722[x7081];
        bool x7083 = x7082 != '\n';
        x7085 = x7083;
      }
      bool x7086 = x7085;
      if (!x7086) break;
      x6870 = x6870 + 1;
    }
    x6870 = x6870 + 1;
    int x7096 = x6872;
    int x7097 = x6871;
    bool x7098 = x7096 == x7097;
    if (x7098) {
      int x7099 = x7097 * 4;
      x6871 = x7099;
      printf("buffer.resize %d\n",x7099);
      int* x7102 = x6874;
      int* x7103 = (int*)realloc(x7102,x7099 * sizeof(int));
      x6874 = x7103;
      int* x7111 = x6880;
      int* x7112 = (int*)realloc(x7111,x7099 * sizeof(int));
      x6880 = x7112;
    } else {
    }
    int* x7128 = x6874;
    x7128[x7096] = x6915;
    int* x7134 = x6880;
    x7134[x7096] = x6975;
    x6872 = x6872 + 1;
  }
  int x7147 = 0;
  int x7148 = 1048576;
  int x7149 = 0;
  int* x7150 = (int*)malloc(1048576 * sizeof(int));
  int* x7151 = x7150;
  int* x7156 = (int*)malloc(1048576 * sizeof(int));
  int* x7157 = x7156;
  int x1747 = open("../databases/sf2/supplier.tbl",0);
  int x1748 = fsize(x1747);
  char* x1749 = mmap(0, x1748, PROT_READ, MAP_FILE | MAP_SHARED, x1747, 0);
  for (;;) {
    int x7164 = x7147;
    bool x7165 = x7164 < x1748;
    if (!x7165) break;
    int x7168 = 0;
    for (;;) {
      int x7169 = x7147;
      char x7170 = x1749[x7169];
      bool x7171 = x7170 != '|';
      bool x7176 = x7171;
      if (x7171) {
        int x7172 = x7147;
        char x7173 = x1749[x7172];
        bool x7174 = x7173 != '\n';
        x7176 = x7174;
      }
      bool x7177 = x7176;
      if (!x7177) break;
      int x7179 = x7168;
      int x7181 = x7147;
      int x7180 = x7179 * 10;
      char x7182 = x1749[x7181];
      char x7183 = x7182 - '0';
      int x7184 = x7180 + x7183;
      x7168 = x7184;
      x7147 = x7147 + 1;
    }
    x7147 = x7147 + 1;
    int x7190 = x7168;
    for (;;) {
      int x7192 = x7147;
      char x7193 = x1749[x7192];
      bool x7194 = x7193 != '|';
      bool x7199 = x7194;
      if (x7194) {
        int x7195 = x7147;
        char x7196 = x1749[x7195];
        bool x7197 = x7196 != '\n';
        x7199 = x7197;
      }
      bool x7200 = x7199;
      if (!x7200) break;
      x7147 = x7147 + 1;
    }
    x7147 = x7147 + 1;
    for (;;) {
      int x7210 = x7147;
      char x7211 = x1749[x7210];
      bool x7212 = x7211 != '|';
      bool x7217 = x7212;
      if (x7212) {
        int x7213 = x7147;
        char x7214 = x1749[x7213];
        bool x7215 = x7214 != '\n';
        x7217 = x7215;
      }
      bool x7218 = x7217;
      if (!x7218) break;
      x7147 = x7147 + 1;
    }
    x7147 = x7147 + 1;
    int x7228 = 0;
    for (;;) {
      int x7229 = x7147;
      char x7230 = x1749[x7229];
      bool x7231 = x7230 != '|';
      bool x7236 = x7231;
      if (x7231) {
        int x7232 = x7147;
        char x7233 = x1749[x7232];
        bool x7234 = x7233 != '\n';
        x7236 = x7234;
      }
      bool x7237 = x7236;
      if (!x7237) break;
      int x7239 = x7228;
      int x7241 = x7147;
      int x7240 = x7239 * 10;
      char x7242 = x1749[x7241];
      char x7243 = x7242 - '0';
      int x7244 = x7240 + x7243;
      x7228 = x7244;
      x7147 = x7147 + 1;
    }
    x7147 = x7147 + 1;
    int x7250 = x7228;
    for (;;) {
      int x7252 = x7147;
      char x7253 = x1749[x7252];
      bool x7254 = x7253 != '|';
      bool x7259 = x7254;
      if (x7254) {
        int x7255 = x7147;
        char x7256 = x1749[x7255];
        bool x7257 = x7256 != '\n';
        x7259 = x7257;
      }
      bool x7260 = x7259;
      if (!x7260) break;
      x7147 = x7147 + 1;
    }
    x7147 = x7147 + 1;
    for (;;) {
      int x7272 = x7147;
      char x7273 = x1749[x7272];
      bool x7274 = x7273 != '.';
      bool x7279 = x7274;
      if (x7274) {
        int x7275 = x7147;
        char x7276 = x1749[x7275];
        bool x7277 = x7276 != '|';
        x7279 = x7277;
      }
      bool x7280 = x7279;
      bool x7285 = x7280;
      if (x7280) {
        int x7281 = x7147;
        char x7282 = x1749[x7281];
        bool x7283 = x7282 != '\n';
        x7285 = x7283;
      }
      bool x7286 = x7285;
      if (!x7286) break;
      x7147 = x7147 + 1;
    }
    int x7298 = x7147;
    char x7299 = x1749[x7298];
    bool x7300 = x7299 == '.';
    if (x7300) {
      x7147 = x7147 + 1;
      for (;;) {
        int x7302 = x7147;
        char x7303 = x1749[x7302];
        bool x7304 = x7303 != '|';
        bool x7309 = x7304;
        if (x7304) {
          int x7305 = x7147;
          char x7306 = x1749[x7305];
          bool x7307 = x7306 != '\n';
          x7309 = x7307;
        }
        bool x7310 = x7309;
        if (!x7310) break;
        x7147 = x7147 + 1;
      }
    } else {
    }
    x7147 = x7147 + 1;
    for (;;) {
      int x7335 = x7147;
      char x7336 = x1749[x7335];
      bool x7337 = x7336 != '|';
      bool x7342 = x7337;
      if (x7337) {
        int x7338 = x7147;
        char x7339 = x1749[x7338];
        bool x7340 = x7339 != '\n';
        x7342 = x7340;
      }
      bool x7343 = x7342;
      if (!x7343) break;
      x7147 = x7147 + 1;
    }
    x7147 = x7147 + 1;
    int x7353 = x7149;
    int x7354 = x7148;
    bool x7355 = x7353 == x7354;
    if (x7355) {
      int x7356 = x7354 * 4;
      x7148 = x7356;
      printf("buffer.resize %d\n",x7356);
      int* x7359 = x7151;
      int* x7360 = (int*)realloc(x7359,x7356 * sizeof(int));
      x7151 = x7360;
      int* x7368 = x7157;
      int* x7369 = (int*)realloc(x7368,x7356 * sizeof(int));
      x7157 = x7369;
    } else {
    }
    int* x7382 = x7151;
    x7382[x7353] = x7190;
    int* x7388 = x7157;
    x7388[x7353] = x7250;
    x7149 = x7149 + 1;
  }
  int x7399 = 0;
  int x7400 = 1048576;
  int x7401 = 0;
  int* x7402 = (int*)malloc(1048576 * sizeof(int));
  int* x7403 = x7402;
  char** x7404 = (char**)malloc(1048576 * sizeof(char*));
  char** x7405 = x7404;
  int x1645 = open("../databases/sf2/region.tbl",0);
  int x1646 = fsize(x1645);
  char* x1647 = mmap(0, x1646, PROT_READ, MAP_FILE | MAP_SHARED, x1645, 0);
  for (;;) {
    int x7408 = x7399;
    bool x7409 = x7408 < x1646;
    if (!x7409) break;
    int x7412 = 0;
    for (;;) {
      int x7413 = x7399;
      char x7414 = x1647[x7413];
      bool x7415 = x7414 != '|';
      bool x7420 = x7415;
      if (x7415) {
        int x7416 = x7399;
        char x7417 = x1647[x7416];
        bool x7418 = x7417 != '\n';
        x7420 = x7418;
      }
      bool x7421 = x7420;
      if (!x7421) break;
      int x7423 = x7412;
      int x7425 = x7399;
      int x7424 = x7423 * 10;
      char x7426 = x1647[x7425];
      char x7427 = x7426 - '0';
      int x7428 = x7424 + x7427;
      x7412 = x7428;
      x7399 = x7399 + 1;
    }
    x7399 = x7399 + 1;
    int x7434 = x7412;
    int x7435 = x7399;
    for (;;) {
      int x7436 = x7399;
      char x7437 = x1647[x7436];
      bool x7438 = x7437 != '|';
      bool x7443 = x7438;
      if (x7438) {
        int x7439 = x7399;
        char x7440 = x1647[x7439];
        bool x7441 = x7440 != '\n';
        x7443 = x7441;
      }
      bool x7444 = x7443;
      if (!x7444) break;
      x7399 = x7399 + 1;
    }
    x7399 = x7399 + 1;
    for (;;) {
      int x7454 = x7399;
      char x7455 = x1647[x7454];
      bool x7456 = x7455 != '|';
      bool x7461 = x7456;
      if (x7456) {
        int x7457 = x7399;
        char x7458 = x1647[x7457];
        bool x7459 = x7458 != '\n';
        x7461 = x7459;
      }
      bool x7462 = x7461;
      if (!x7462) break;
      x7399 = x7399 + 1;
    }
    x7399 = x7399 + 1;
    int x7472 = x7401;
    int x7473 = x7400;
    bool x7474 = x7472 == x7473;
    if (x7474) {
      int x7475 = x7473 * 4;
      x7400 = x7475;
      printf("buffer.resize %d\n",x7475);
      int* x7478 = x7403;
      int* x7479 = (int*)realloc(x7478,x7475 * sizeof(int));
      x7403 = x7479;
      char** x7481 = x7405;
      char** x7482 = (char**)realloc(x7481,x7475 * sizeof(char*));
      x7405 = x7482;
    } else {
    }
    int* x7489 = x7403;
    x7489[x7472] = x7434;
    char** x7491 = x7405;
    char* x7452 = x1647+x7435;
    x7491[x7472] = x7452;
    x7401 = x7401 + 1;
  }
  int x7498 = 0;
  int x7499 = 1048576;
  int x7500 = 0;
  int* x7501 = (int*)malloc(1048576 * sizeof(int));
  int* x7502 = x7501;
  int* x7503 = (int*)malloc(1048576 * sizeof(int));
  int* x7504 = x7503;
  long* x7509 = (long*)malloc(1048576 * sizeof(long));
  long* x7510 = x7509;
  int x3366 = open("../databases/sf2/orders.tbl",0);
  int x3367 = fsize(x3366);
  char* x3368 = mmap(0, x3367, PROT_READ, MAP_FILE | MAP_SHARED, x3366, 0);
  for (;;) {
    int x7519 = x7498;
    bool x7520 = x7519 < x3367;
    if (!x7520) break;
    int x7523 = 0;
    for (;;) {
      int x7524 = x7498;
      char x7525 = x3368[x7524];
      bool x7526 = x7525 != '|';
      bool x7531 = x7526;
      if (x7526) {
        int x7527 = x7498;
        char x7528 = x3368[x7527];
        bool x7529 = x7528 != '\n';
        x7531 = x7529;
      }
      bool x7532 = x7531;
      if (!x7532) break;
      int x7534 = x7523;
      int x7536 = x7498;
      int x7535 = x7534 * 10;
      char x7537 = x3368[x7536];
      char x7538 = x7537 - '0';
      int x7539 = x7535 + x7538;
      x7523 = x7539;
      x7498 = x7498 + 1;
    }
    x7498 = x7498 + 1;
    int x7545 = x7523;
    int x7547 = 0;
    for (;;) {
      int x7548 = x7498;
      char x7549 = x3368[x7548];
      bool x7550 = x7549 != '|';
      bool x7555 = x7550;
      if (x7550) {
        int x7551 = x7498;
        char x7552 = x3368[x7551];
        bool x7553 = x7552 != '\n';
        x7555 = x7553;
      }
      bool x7556 = x7555;
      if (!x7556) break;
      int x7558 = x7547;
      int x7560 = x7498;
      int x7559 = x7558 * 10;
      char x7561 = x3368[x7560];
      char x7562 = x7561 - '0';
      int x7563 = x7559 + x7562;
      x7547 = x7563;
      x7498 = x7498 + 1;
    }
    x7498 = x7498 + 1;
    int x7569 = x7547;
    x7498 = x7498 + 2;
    for (;;) {
      int x7576 = x7498;
      char x7577 = x3368[x7576];
      bool x7578 = x7577 != '.';
      bool x7583 = x7578;
      if (x7578) {
        int x7579 = x7498;
        char x7580 = x3368[x7579];
        bool x7581 = x7580 != '|';
        x7583 = x7581;
      }
      bool x7584 = x7583;
      bool x7589 = x7584;
      if (x7584) {
        int x7585 = x7498;
        char x7586 = x3368[x7585];
        bool x7587 = x7586 != '\n';
        x7589 = x7587;
      }
      bool x7590 = x7589;
      if (!x7590) break;
      x7498 = x7498 + 1;
    }
    int x7602 = x7498;
    char x7603 = x3368[x7602];
    bool x7604 = x7603 == '.';
    if (x7604) {
      x7498 = x7498 + 1;
      for (;;) {
        int x7606 = x7498;
        char x7607 = x3368[x7606];
        bool x7608 = x7607 != '|';
        bool x7613 = x7608;
        if (x7608) {
          int x7609 = x7498;
          char x7610 = x3368[x7609];
          bool x7611 = x7610 != '\n';
          x7613 = x7611;
        }
        bool x7614 = x7613;
        if (!x7614) break;
        x7498 = x7498 + 1;
      }
    } else {
    }
    x7498 = x7498 + 1;
    int x7639 = 0;
    for (;;) {
      int x7640 = x7498;
      char x7641 = x3368[x7640];
      bool x7642 = x7641 != '-';
      bool x7647 = x7642;
      if (x7642) {
        int x7643 = x7498;
        char x7644 = x3368[x7643];
        bool x7645 = x7644 != '\n';
        x7647 = x7645;
      }
      bool x7648 = x7647;
      if (!x7648) break;
      int x7650 = x7639;
      int x7652 = x7498;
      int x7651 = x7650 * 10;
      char x7653 = x3368[x7652];
      char x7654 = x7653 - '0';
      int x7655 = x7651 + x7654;
      x7639 = x7655;
      x7498 = x7498 + 1;
    }
    x7498 = x7498 + 1;
    int x7661 = x7639;
    int x7663 = 0;
    for (;;) {
      int x7664 = x7498;
      char x7665 = x3368[x7664];
      bool x7666 = x7665 != '-';
      bool x7671 = x7666;
      if (x7666) {
        int x7667 = x7498;
        char x7668 = x3368[x7667];
        bool x7669 = x7668 != '\n';
        x7671 = x7669;
      }
      bool x7672 = x7671;
      if (!x7672) break;
      int x7674 = x7663;
      int x7676 = x7498;
      int x7675 = x7674 * 10;
      char x7677 = x3368[x7676];
      char x7678 = x7677 - '0';
      int x7679 = x7675 + x7678;
      x7663 = x7679;
      x7498 = x7498 + 1;
    }
    x7498 = x7498 + 1;
    int x7685 = x7663;
    int x7687 = 0;
    for (;;) {
      int x7688 = x7498;
      char x7689 = x3368[x7688];
      bool x7690 = x7689 != '|';
      bool x7695 = x7690;
      if (x7690) {
        int x7691 = x7498;
        char x7692 = x3368[x7691];
        bool x7693 = x7692 != '\n';
        x7695 = x7693;
      }
      bool x7696 = x7695;
      if (!x7696) break;
      int x7698 = x7687;
      int x7700 = x7498;
      int x7699 = x7698 * 10;
      char x7701 = x3368[x7700];
      char x7702 = x7701 - '0';
      int x7703 = x7699 + x7702;
      x7687 = x7703;
      x7498 = x7498 + 1;
    }
    x7498 = x7498 + 1;
    int x7709 = x7687;
    for (;;) {
      int x7715 = x7498;
      char x7716 = x3368[x7715];
      bool x7717 = x7716 != '|';
      bool x7722 = x7717;
      if (x7717) {
        int x7718 = x7498;
        char x7719 = x3368[x7718];
        bool x7720 = x7719 != '\n';
        x7722 = x7720;
      }
      bool x7723 = x7722;
      if (!x7723) break;
      x7498 = x7498 + 1;
    }
    x7498 = x7498 + 1;
    for (;;) {
      int x7733 = x7498;
      char x7734 = x3368[x7733];
      bool x7735 = x7734 != '|';
      bool x7740 = x7735;
      if (x7735) {
        int x7736 = x7498;
        char x7737 = x3368[x7736];
        bool x7738 = x7737 != '\n';
        x7740 = x7738;
      }
      bool x7741 = x7740;
      if (!x7741) break;
      x7498 = x7498 + 1;
    }
    x7498 = x7498 + 1;
    for (;;) {
      int x7752 = x7498;
      char x7753 = x3368[x7752];
      bool x7754 = x7753 != '|';
      bool x7759 = x7754;
      if (x7754) {
        int x7755 = x7498;
        char x7756 = x3368[x7755];
        bool x7757 = x7756 != '\n';
        x7759 = x7757;
      }
      bool x7760 = x7759;
      if (!x7760) break;
      x7498 = x7498 + 1;
    }
    x7498 = x7498 + 1;
    for (;;) {
      int x7775 = x7498;
      char x7776 = x3368[x7775];
      bool x7777 = x7776 != '|';
      bool x7782 = x7777;
      if (x7777) {
        int x7778 = x7498;
        char x7779 = x3368[x7778];
        bool x7780 = x7779 != '\n';
        x7782 = x7780;
      }
      bool x7783 = x7782;
      if (!x7783) break;
      x7498 = x7498 + 1;
    }
    x7498 = x7498 + 1;
    int x7793 = x7500;
    int x7794 = x7499;
    bool x7795 = x7793 == x7794;
    if (x7795) {
      int x7796 = x7794 * 4;
      x7499 = x7796;
      printf("buffer.resize %d\n",x7796);
      int* x7799 = x7502;
      int* x7800 = (int*)realloc(x7799,x7796 * sizeof(int));
      x7502 = x7800;
      int* x7802 = x7504;
      int* x7803 = (int*)realloc(x7802,x7796 * sizeof(int));
      x7504 = x7803;
      long* x7811 = x7510;
      long* x7812 = (long*)realloc(x7811,x7796 * sizeof(long));
      x7510 = x7812;
    } else {
    }
    int* x7828 = x7502;
    x7828[x7793] = x7545;
    int* x7830 = x7504;
    x7830[x7793] = x7569;
    long* x7836 = x7510;
    long x7710 = x7661 * 10000L;
    long x7711 = x7685 * 100L;
    long x7712 = x7710 + x7711;
    long x7713 = x7712 + x7709;
    x7836[x7793] = x7713;
    x7500 = x7500 + 1;
  }
  bool x972 = true == false;
  int x7849;
  for(x7849=0; x7849 < 5; x7849++) {
    bool x7850 = false;
    int x7851 = 0;
    bool x7853 = false;
    int x7854 = 0;
    bool x7855 = false;
    int x7856 = 0;
    bool x7857 = false;
    int x7858 = 0;
    bool x7859 = false;
    int x7860 = 0;
    bool x7861 = false;
    int x7862 = 0;
    int* x7865 = (int*)malloc(134217728 * sizeof(int));
    int* x7866 = x7865;
    int x7871 = 0;
    int* x7872 = (int*)malloc(67108864 * sizeof(int));
    int* x7873 = (int*)malloc(134217728 * sizeof(int));
    int x7874;
    for(x7874=0; x7874 < 67108864; x7874++) {
      x7872[x7874] = -1;
    }
    char** x7880 = (char**)malloc(134217728 * sizeof(char*));
    char** x7881 = x7880;
    int* x7882 = (int*)malloc(134217728 * sizeof(int));
    int* x7883 = x7882;
    int x7884 = 0;
    int* x7885 = (int*)malloc(67108864 * sizeof(int));
    int* x7886 = (int*)malloc(134217728 * sizeof(int));
    int x7887;
    for(x7887=0; x7887 < 67108864; x7887++) {
      x7885[x7887] = -1;
    }
    char** x7893 = (char**)malloc(134217728 * sizeof(char*));
    char** x7894 = x7893;
    int* x7895 = (int*)malloc(134217728 * sizeof(int));
    int* x7896 = x7895;
    int* x7897 = (int*)malloc(134217728 * sizeof(int));
    int* x7898 = x7897;
    int x7899 = 0;
    int* x7900 = (int*)malloc(67108864 * sizeof(int));
    int* x7901 = (int*)malloc(134217728 * sizeof(int));
    int x7902;
    for(x7902=0; x7902 < 67108864; x7902++) {
      x7900[x7902] = -1;
    }
    char** x7908 = (char**)malloc(134217728 * sizeof(char*));
    char** x7909 = x7908;
    int* x7910 = (int*)malloc(134217728 * sizeof(int));
    int* x7911 = x7910;
    int* x7912 = (int*)malloc(134217728 * sizeof(int));
    int* x7913 = x7912;
    int x7914 = 0;
    int* x7915 = (int*)malloc(67108864 * sizeof(int));
    int* x7916 = (int*)malloc(134217728 * sizeof(int));
    int x7917;
    for(x7917=0; x7917 < 67108864; x7917++) {
      x7915[x7917] = -1;
    }
    int* x7923 = (int*)malloc(134217728 * sizeof(int));
    int* x7924 = x7923;
    int* x7929 = (int*)malloc(134217728 * sizeof(int));
    int* x7930 = x7929;
    int x7937 = 0;
    int* x7938 = (int*)malloc(67108864 * sizeof(int));
    int* x7939 = (int*)malloc(134217728 * sizeof(int));
    int x7940;
    for(x7940=0; x7940 < 67108864; x7940++) {
      x7938[x7940] = -1;
    }
    struct Anon1007729034* x7946 = (struct Anon1007729034*)malloc(16777216 * sizeof(struct Anon1007729034));
    struct Anon1007729034* x7947 = x7946;
    int x7948 = 0;
    int* x7949 = (int*)malloc(16777216 * sizeof(int));
    int x7950;
    for(x7950=0; x7950 < 16777216; x7950++) {
      struct Anon1007729034* x7951 = x7947;
      struct Anon1007729034 x7952 = x7951[x7950];
      char* x7953 = x7952.key;;
      struct Anon2052879266 x7954 = x7952.aggs;;
      struct Anon1007729034 x7955;
      x7955.exists = false;
      x7955.key = x7953;
      x7955.aggs = x7954;
      x7951[x7950] = x7955;
    }
    int x7960 = 0;
    struct timeval x8439, x8440, x8441;
    gettimeofday(&x8439, NULL);
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x7962 = x7855;
      bool x7963 = !x7962;
      bool x7968 = x7963;
      if (x7963) {
        int x7964 = x7856;
        int x7965 = x7149;
        bool x7966 = x7964 < x7965;
        x7968 = x7966;
      }
      bool x7969 = x7968;
      if (!x7969) break;
      int x7971 = x7856;
      int* x7972 = x7151;
      int x7973 = x7972[x7971];
      int* x7978 = x7157;
      int x7979 = x7978[x7971];
      x7856 = x7856 + 1;
      int x7988 = x7937;
      int* x7989 = x7924;
      x7989[x7988] = x7973;
      int* x7995 = x7930;
      x7995[x7988] = x7979;
      x7937 = x7937 + 1;
      int x8004 = x7973 & 67108863;
      int x8005 = x7938[x8004];
      x7938[x8004] = x7988;
      x7939[x7988] = x8005;
    }
    printf("%s\n","begin scan REGION");
    for (;;) {
      bool x8011 = x7850;
      bool x8012 = !x8011;
      bool x8017 = x8012;
      if (x8012) {
        int x8013 = x7851;
        int x8014 = x7401;
        bool x8015 = x8013 < x8014;
        x8017 = x8015;
      }
      bool x8018 = x8017;
      if (!x8018) break;
      int x8020 = x7851;
      int* x8021 = x7403;
      int x8022 = x8021[x8020];
      char** x8023 = x7405;
      char* x8024 = x8023[x8020];
      x7851 = x7851 + 1;
      bool x8029 = strcmp(x8024,"ASIA") == 0;;
      if (x8029) {
        int x8030 = x7871;
        int* x8031 = x7866;
        x8031[x8030] = x8022;
        x7871 = x7871 + 1;
        int x8038 = x8022 & 67108863;
        int x8039 = x7872[x8038];
        x7872[x8038] = x8030;
        x7873[x8030] = x8039;
      } else {
      }
    }
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x8047 = x7853;
      bool x8048 = !x8047;
      bool x8053 = x8048;
      if (x8048) {
        int x8049 = x7854;
        int x8050 = x6742;
        bool x8051 = x8049 < x8050;
        x8053 = x8051;
      }
      bool x8054 = x8053;
      if (!x8054) break;
      int x8056 = x7854;
      int* x8057 = x6744;
      int x8058 = x8057[x8056];
      char** x8059 = x6746;
      char* x8060 = x8059[x8056];
      int* x8061 = x6748;
      int x8062 = x8061[x8056];
      x7854 = x7854 + 1;
      int x8067 = x8062 & 67108863;
      int x8068 = x7872[x8067];
      int x8069 = x8068;
      int x8092 = x8058 & 67108863;
      for (;;) {
        int x8070 = x8069;
        bool x8071 = x8070 != -1;
        if (!x8071) break;
        int x8073 = x8069;
        int* x8074 = x7866;
        int x8075 = x8074[x8073];
        int x8081 = x7873[x8073];
        x8069 = x8081;
        bool x8083 = x8075 == x8062;
        if (x8083) {
          int x8086 = x7884;
          char** x8087 = x7881;
          x8087[x8086] = x8060;
          int* x8089 = x7883;
          x8089[x8086] = x8058;
          x7884 = x7884 + 1;
          int x8093 = x7885[x8092];
          x7885[x8092] = x8086;
          x7886[x8086] = x8093;
        } else {
        }
      }
    }
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x8103 = x7857;
      bool x8104 = !x8103;
      bool x8109 = x8104;
      if (x8104) {
        int x8105 = x7858;
        int x8106 = x6872;
        bool x8107 = x8105 < x8106;
        x8109 = x8107;
      }
      bool x8110 = x8109;
      if (!x8110) break;
      int x8112 = x7858;
      int* x8113 = x6874;
      int x8114 = x8113[x8112];
      int* x8119 = x6880;
      int x8120 = x8119[x8112];
      x7858 = x7858 + 1;
      int x8131 = x8120 & 67108863;
      int x8132 = x7885[x8131];
      int x8133 = x8132;
      int x8156 = x8114 & 67108863;
      for (;;) {
        int x8134 = x8133;
        bool x8135 = x8134 != -1;
        if (!x8135) break;
        int x8137 = x8133;
        char** x8138 = x7881;
        char* x8139 = x8138[x8137];
        int* x8140 = x7883;
        int x8141 = x8140[x8137];
        int x8143 = x7886[x8137];
        x8133 = x8143;
        bool x8145 = x8141 == x8120;
        if (x8145) {
          int x8148 = x7899;
          char** x8149 = x7894;
          x8149[x8148] = x8139;
          int* x8151 = x7896;
          x8151[x8148] = x8141;
          int* x8153 = x7898;
          x8153[x8148] = x8114;
          x7899 = x7899 + 1;
          int x8157 = x7900[x8156];
          x7900[x8156] = x8148;
          x7901[x8148] = x8157;
        } else {
        }
      }
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x8167 = x7861;
      bool x8168 = !x8167;
      bool x8173 = x8168;
      if (x8168) {
        int x8169 = x7862;
        int x8170 = x7500;
        bool x8171 = x8169 < x8170;
        x8173 = x8171;
      }
      bool x8174 = x8173;
      if (!x8174) break;
      int x8176 = x7862;
      int* x8177 = x7502;
      int x8178 = x8177[x8176];
      int* x8179 = x7504;
      int x8180 = x8179[x8176];
      long* x8185 = x7510;
      long x8186 = x8185[x8176];
      x7862 = x7862 + 1;
      bool x8197 = x8186 >= 19960101L;
      bool x8199 = x8197;
      if (x8197) {
        bool x8198 = x8186 < 19970101L;
        x8199 = x8198;
      }
      bool x8200 = x8199;
      if (x8200) {
        int x8201 = x8180 & 67108863;
        int x8202 = x7900[x8201];
        int x8203 = x8202;
        int x8228 = x8178 & 67108863;
        for (;;) {
          int x8204 = x8203;
          bool x8205 = x8204 != -1;
          if (!x8205) break;
          int x8207 = x8203;
          char** x8208 = x7894;
          char* x8209 = x8208[x8207];
          int* x8210 = x7896;
          int x8211 = x8210[x8207];
          int* x8212 = x7898;
          int x8213 = x8212[x8207];
          int x8215 = x7901[x8207];
          x8203 = x8215;
          bool x8217 = x8213 == x8180;
          if (x8217) {
            int x8220 = x7914;
            char** x8221 = x7909;
            x8221[x8220] = x8209;
            int* x8223 = x7911;
            x8223[x8220] = x8211;
            int* x8225 = x7913;
            x8225[x8220] = x8178;
            x7914 = x7914 + 1;
            int x8229 = x7915[x8228];
            x7915[x8228] = x8220;
            x7916[x8220] = x8229;
          } else {
          }
        }
      } else {
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x8241 = x7859;
      bool x8242 = !x8241;
      bool x8247 = x8242;
      if (x8242) {
        int x8243 = x7860;
        int x8244 = x5968;
        bool x8245 = x8243 < x8244;
        x8247 = x8245;
      }
      bool x8248 = x8247;
      if (!x8248) break;
      int x8250 = x7860;
      int* x8251 = x5970;
      int x8252 = x8251[x8250];
      int* x8255 = x5974;
      int x8256 = x8255[x8250];
      double* x8261 = x5980;
      double x8262 = x8261[x8250];
      double* x8263 = x5982;
      double x8264 = x8263[x8250];
      x7860 = x7860 + 1;
      int x8285 = x8252 & 67108863;
      int x8286 = x7915[x8285];
      int x8287 = x8286;
      int x8304 = x8256 & 67108863;
      double x8355 = 1.0 - x8264;
      double x8356 = x8262 * x8355;
      struct Anon2052879266 x8389;
      x8389._0 = x8356;
      for (;;) {
        int x8288 = x8287;
        bool x8289 = x8288 != -1;
        if (!x8289) break;
        int x8291 = x8287;
        char** x8292 = x7909;
        char* x8293 = x8292[x8291];
        int* x8294 = x7911;
        int x8295 = x8294[x8291];
        int* x8296 = x7913;
        int x8297 = x8296[x8291];
        int x8299 = x7916[x8291];
        x8287 = x8299;
        bool x8301 = x8297 == x8252;
        if (x8301) {
          int x8305 = x7938[x8304];
          int x8306 = x8305;
          char x8331 = x8293[0];
          int x8332 = x8331 * 41;
          char x8333 = x8293[1];
          int x8334 = x8332 + x8333;
          int x8335 = x8334 * 41;
          char x8336 = x8293[2];
          int x8337 = x8335 + x8336;
          int x8338 = x8337 * 41;
          char x8339 = x8293[3];
          int x8340 = x8338 + x8339;
          int x8341 = x8340 & 16777215;
          struct Anon1007729034 x8390;
          x8390.exists = true;
          x8390.key = x8293;
          x8390.aggs = x8389;
          for (;;) {
            int x8307 = x8306;
            bool x8308 = x8307 != -1;
            if (!x8308) break;
            int x8310 = x8306;
            int* x8311 = x7924;
            int x8312 = x8311[x8310];
            int* x8317 = x7930;
            int x8318 = x8317[x8310];
            int x8326 = x7939[x8310];
            x8306 = x8326;
            bool x8328 = x8312 == x8256;
            if (x8328) {
              bool x8330 = x8318 == x8295;
              if (x8330) {
                int x8342 = x8341;
                struct Anon1007729034* x8343 = x7947;
                struct Anon1007729034 x8344 = x8343[x8341];
                struct Anon1007729034 x8345 = x8344;
                bool x8346 = x8344.exists;;
                bool x8351 = x8346;
                if (x8346) {
                  struct Anon1007729034 x8347 = x8345;
                  char* x8348 = x8347.key;;
                  bool x8349 = strcmp(x8348,x8293) == 0;;
                  x8351 = x8349;
                }
                bool x8352 = x8351;
                if (x8352) {
                  struct Anon2052879266 x8353 = x8344.aggs;;
                  char* x8359 = x8344.key;;
                  double x8354 = x8353._0;;
                  double x8357 = x8354 + x8356;
                  struct Anon2052879266 x8358;
                  x8358._0 = x8357;
                  struct Anon1007729034 x8360;
                  x8360.exists = true;
                  x8360.key = x8359;
                  x8360.aggs = x8358;
                  x8343[x8341] = x8360;
                } else {
                  for (;;) {
                    struct Anon1007729034 x8363 = x8345;
                    bool x8364 = x8363.exists;;
                    bool x8399;
                    if (x8364) {
                      char* x8365 = x8363.key;;
                      bool x8366 = strcmp(x8365,x8293) == 0;;
                      bool x8386;
                      if (x8366) {
                        struct Anon2052879266 x8367 = x8363.aggs;;
                        int x8371 = x8342;
                        struct Anon1007729034* x8373 = x7947;
                        double x8368 = x8367._0;;
                        double x8369 = x8368 + x8356;
                        struct Anon2052879266 x8370;
                        x8370._0 = x8369;
                        struct Anon1007729034 x8372;
                        x8372.exists = true;
                        x8372.key = x8365;
                        x8372.aggs = x8370;
                        x8373[x8371] = x8372;
                        x8386 = false;
                      } else {
                        int x8376 = x8342;
                        int x8377 = x8376 + 1;
                        int x8378 = x8377 % 16777215;
                        x8342 = x8378;
                        struct Anon1007729034* x8380 = x7947;
                        struct Anon1007729034 x8381 = x8380[x8378];
                        x8345 = x8381;
                        x8386 = true;
                      }
                      x8399 = x8386;
                    } else {
                      int x8388 = x8342;
                      struct Anon1007729034* x8391 = x7947;
                      x8391[x8388] = x8390;
                      int x8393 = x7948;
                      x7949[x8393] = x8388;
                      x7948 = x7948 + 1;
                      x8399 = false;
                    }
                    if (!x8399) break;
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
    int x8418 = x7948;
    int x8420;
    for(x8420=0; x8420 < x8418; x8420++) {
      int x8421 = x7949[x8420];
      struct Anon1007729034* x8422 = x7947;
      struct Anon1007729034 x8423 = x8422[x8421];
      if (x972) {
      } else {
        char* x8426 = x8423.key;;
        struct Anon2052879266 x8428 = x8423.aggs;;
        int x8427 = strlen(x8426);
        double x8429 = x8428._0;;
        printf("%.*s|%.4f\n",x8427,x8426,x8429);
        x7960 = x7960 + 1;
      }
    }
    int x8436 = x7960;
    printf("(%d rows)\n",x8436);
    gettimeofday(&x8440, NULL);
    timeval_subtract(&x8441, &x8440, &x8439);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x8441.tv_sec * 1000) + (x8441.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
