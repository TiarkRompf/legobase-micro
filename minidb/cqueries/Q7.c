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

struct Anon726278688 {
char* SUPP_NATION;
char* CUST_NATION;
int L_YEAR;
};

struct Anon2052879266 {
double _0;
};

struct Anon1594456343 {
bool exists;
struct Anon726278688 key;
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

struct Anon1465150758 {
int L_ORDERKEY;
long O_ORDERDATE;
int O_SHIPPRIORITY;
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

struct Anon1007729034 {
bool exists;
char* key;
struct Anon2052879266 aggs;
};

struct Anon72918141 {
int N2_N_NATIONKEY;
char* N2_N_NAME;
int N2_N_REGIONKEY;
char* N2_N_COMMENT;
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

struct Anon348455037 {
char* N_NAME;
int N_NATIONKEY;
int L_SUPPKEY;
double L_EXTENDEDPRICE;
double L_DISCOUNT;
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
int main(int x9406, char** x9407) {
  int x9408 = 0;
  int x9409 = 1048576;
  int x9410 = 0;
  int* x9411 = (int*)malloc(1048576 * sizeof(int));
  int* x9412 = x9411;
  char** x9413 = (char**)malloc(1048576 * sizeof(char*));
  char** x9414 = x9413;
  int x1512 = open("../databases/sf2/nation.tbl",0);
  int x1513 = fsize(x1512);
  char* x1514 = mmap(0, x1513, PROT_READ, MAP_FILE | MAP_SHARED, x1512, 0);
  for (;;) {
    int x9419 = x9408;
    bool x9420 = x9419 < x1513;
    if (!x9420) break;
    int x9423 = 0;
    for (;;) {
      int x9424 = x9408;
      char x9425 = x1514[x9424];
      bool x9426 = x9425 != '|';
      bool x9431 = x9426;
      if (x9426) {
        int x9427 = x9408;
        char x9428 = x1514[x9427];
        bool x9429 = x9428 != '\n';
        x9431 = x9429;
      }
      bool x9432 = x9431;
      if (!x9432) break;
      int x9434 = x9423;
      int x9436 = x9408;
      int x9435 = x9434 * 10;
      char x9437 = x1514[x9436];
      char x9438 = x9437 - '0';
      int x9439 = x9435 + x9438;
      x9423 = x9439;
      x9408 = x9408 + 1;
    }
    x9408 = x9408 + 1;
    int x9445 = x9423;
    int x9446 = x9408;
    for (;;) {
      int x9447 = x9408;
      char x9448 = x1514[x9447];
      bool x9449 = x9448 != '|';
      bool x9454 = x9449;
      if (x9449) {
        int x9450 = x9408;
        char x9451 = x1514[x9450];
        bool x9452 = x9451 != '\n';
        x9454 = x9452;
      }
      bool x9455 = x9454;
      if (!x9455) break;
      x9408 = x9408 + 1;
    }
    x9408 = x9408 + 1;
    for (;;) {
      int x9466 = x9408;
      char x9467 = x1514[x9466];
      bool x9468 = x9467 != '|';
      bool x9473 = x9468;
      if (x9468) {
        int x9469 = x9408;
        char x9470 = x1514[x9469];
        bool x9471 = x9470 != '\n';
        x9473 = x9471;
      }
      bool x9474 = x9473;
      if (!x9474) break;
      x9408 = x9408 + 1;
    }
    x9408 = x9408 + 1;
    for (;;) {
      int x9489 = x9408;
      char x9490 = x1514[x9489];
      bool x9491 = x9490 != '|';
      bool x9496 = x9491;
      if (x9491) {
        int x9492 = x9408;
        char x9493 = x1514[x9492];
        bool x9494 = x9493 != '\n';
        x9496 = x9494;
      }
      bool x9497 = x9496;
      if (!x9497) break;
      x9408 = x9408 + 1;
    }
    x9408 = x9408 + 1;
    int x9507 = x9410;
    int x9508 = x9409;
    bool x9509 = x9507 == x9508;
    if (x9509) {
      int x9510 = x9508 * 4;
      x9409 = x9510;
      printf("buffer.resize %d\n",x9510);
      int* x9513 = x9412;
      int* x9514 = (int*)realloc(x9513,x9510 * sizeof(int));
      x9412 = x9514;
      char** x9516 = x9414;
      char** x9517 = (char**)realloc(x9516,x9510 * sizeof(char*));
      x9414 = x9517;
    } else {
    }
    int* x9527 = x9412;
    x9527[x9507] = x9445;
    char** x9529 = x9414;
    char* x9463 = x1514+x9446;
    x9529[x9507] = x9463;
    x9410 = x9410 + 1;
  }
  int x9538 = 0;
  int x9539 = 1048576;
  int x9540 = 0;
  int* x9541 = (int*)malloc(1048576 * sizeof(int));
  int* x9542 = x9541;
  int* x9543 = (int*)malloc(1048576 * sizeof(int));
  int* x9544 = x9543;
  int x3366 = open("../databases/sf2/orders.tbl",0);
  int x3367 = fsize(x3366);
  char* x3368 = mmap(0, x3367, PROT_READ, MAP_FILE | MAP_SHARED, x3366, 0);
  for (;;) {
    int x9559 = x9538;
    bool x9560 = x9559 < x3367;
    if (!x9560) break;
    int x9563 = 0;
    for (;;) {
      int x9564 = x9538;
      char x9565 = x3368[x9564];
      bool x9566 = x9565 != '|';
      bool x9571 = x9566;
      if (x9566) {
        int x9567 = x9538;
        char x9568 = x3368[x9567];
        bool x9569 = x9568 != '\n';
        x9571 = x9569;
      }
      bool x9572 = x9571;
      if (!x9572) break;
      int x9574 = x9563;
      int x9576 = x9538;
      int x9575 = x9574 * 10;
      char x9577 = x3368[x9576];
      char x9578 = x9577 - '0';
      int x9579 = x9575 + x9578;
      x9563 = x9579;
      x9538 = x9538 + 1;
    }
    x9538 = x9538 + 1;
    int x9585 = x9563;
    int x9587 = 0;
    for (;;) {
      int x9588 = x9538;
      char x9589 = x3368[x9588];
      bool x9590 = x9589 != '|';
      bool x9595 = x9590;
      if (x9590) {
        int x9591 = x9538;
        char x9592 = x3368[x9591];
        bool x9593 = x9592 != '\n';
        x9595 = x9593;
      }
      bool x9596 = x9595;
      if (!x9596) break;
      int x9598 = x9587;
      int x9600 = x9538;
      int x9599 = x9598 * 10;
      char x9601 = x3368[x9600];
      char x9602 = x9601 - '0';
      int x9603 = x9599 + x9602;
      x9587 = x9603;
      x9538 = x9538 + 1;
    }
    x9538 = x9538 + 1;
    int x9609 = x9587;
    x9538 = x9538 + 2;
    for (;;) {
      int x9616 = x9538;
      char x9617 = x3368[x9616];
      bool x9618 = x9617 != '.';
      bool x9623 = x9618;
      if (x9618) {
        int x9619 = x9538;
        char x9620 = x3368[x9619];
        bool x9621 = x9620 != '|';
        x9623 = x9621;
      }
      bool x9624 = x9623;
      bool x9629 = x9624;
      if (x9624) {
        int x9625 = x9538;
        char x9626 = x3368[x9625];
        bool x9627 = x9626 != '\n';
        x9629 = x9627;
      }
      bool x9630 = x9629;
      if (!x9630) break;
      x9538 = x9538 + 1;
    }
    int x9642 = x9538;
    char x9643 = x3368[x9642];
    bool x9644 = x9643 == '.';
    if (x9644) {
      x9538 = x9538 + 1;
      for (;;) {
        int x9646 = x9538;
        char x9647 = x3368[x9646];
        bool x9648 = x9647 != '|';
        bool x9653 = x9648;
        if (x9648) {
          int x9649 = x9538;
          char x9650 = x3368[x9649];
          bool x9651 = x9650 != '\n';
          x9653 = x9651;
        }
        bool x9654 = x9653;
        if (!x9654) break;
        x9538 = x9538 + 1;
      }
    } else {
    }
    x9538 = x9538 + 1;
    for (;;) {
      int x9680 = x9538;
      char x9681 = x3368[x9680];
      bool x9682 = x9681 != '-';
      bool x9687 = x9682;
      if (x9682) {
        int x9683 = x9538;
        char x9684 = x3368[x9683];
        bool x9685 = x9684 != '\n';
        x9687 = x9685;
      }
      bool x9688 = x9687;
      if (!x9688) break;
      x9538 = x9538 + 1;
    }
    x9538 = x9538 + 1;
    for (;;) {
      int x9704 = x9538;
      char x9705 = x3368[x9704];
      bool x9706 = x9705 != '-';
      bool x9711 = x9706;
      if (x9706) {
        int x9707 = x9538;
        char x9708 = x3368[x9707];
        bool x9709 = x9708 != '\n';
        x9711 = x9709;
      }
      bool x9712 = x9711;
      if (!x9712) break;
      x9538 = x9538 + 1;
    }
    x9538 = x9538 + 1;
    for (;;) {
      int x9728 = x9538;
      char x9729 = x3368[x9728];
      bool x9730 = x9729 != '|';
      bool x9735 = x9730;
      if (x9730) {
        int x9731 = x9538;
        char x9732 = x3368[x9731];
        bool x9733 = x9732 != '\n';
        x9735 = x9733;
      }
      bool x9736 = x9735;
      if (!x9736) break;
      x9538 = x9538 + 1;
    }
    x9538 = x9538 + 1;
    for (;;) {
      int x9755 = x9538;
      char x9756 = x3368[x9755];
      bool x9757 = x9756 != '|';
      bool x9762 = x9757;
      if (x9757) {
        int x9758 = x9538;
        char x9759 = x3368[x9758];
        bool x9760 = x9759 != '\n';
        x9762 = x9760;
      }
      bool x9763 = x9762;
      if (!x9763) break;
      x9538 = x9538 + 1;
    }
    x9538 = x9538 + 1;
    for (;;) {
      int x9773 = x9538;
      char x9774 = x3368[x9773];
      bool x9775 = x9774 != '|';
      bool x9780 = x9775;
      if (x9775) {
        int x9776 = x9538;
        char x9777 = x3368[x9776];
        bool x9778 = x9777 != '\n';
        x9780 = x9778;
      }
      bool x9781 = x9780;
      if (!x9781) break;
      x9538 = x9538 + 1;
    }
    x9538 = x9538 + 1;
    for (;;) {
      int x9792 = x9538;
      char x9793 = x3368[x9792];
      bool x9794 = x9793 != '|';
      bool x9799 = x9794;
      if (x9794) {
        int x9795 = x9538;
        char x9796 = x3368[x9795];
        bool x9797 = x9796 != '\n';
        x9799 = x9797;
      }
      bool x9800 = x9799;
      if (!x9800) break;
      x9538 = x9538 + 1;
    }
    x9538 = x9538 + 1;
    for (;;) {
      int x9815 = x9538;
      char x9816 = x3368[x9815];
      bool x9817 = x9816 != '|';
      bool x9822 = x9817;
      if (x9817) {
        int x9818 = x9538;
        char x9819 = x3368[x9818];
        bool x9820 = x9819 != '\n';
        x9822 = x9820;
      }
      bool x9823 = x9822;
      if (!x9823) break;
      x9538 = x9538 + 1;
    }
    x9538 = x9538 + 1;
    int x9833 = x9540;
    int x9834 = x9539;
    bool x9835 = x9833 == x9834;
    if (x9835) {
      int x9836 = x9834 * 4;
      x9539 = x9836;
      printf("buffer.resize %d\n",x9836);
      int* x9839 = x9542;
      int* x9840 = (int*)realloc(x9839,x9836 * sizeof(int));
      x9542 = x9840;
      int* x9842 = x9544;
      int* x9843 = (int*)realloc(x9842,x9836 * sizeof(int));
      x9544 = x9843;
    } else {
    }
    int* x9868 = x9542;
    x9868[x9833] = x9585;
    int* x9870 = x9544;
    x9870[x9833] = x9609;
    x9540 = x9540 + 1;
  }
  int x9889 = 0;
  int x9890 = 1048576;
  int x9891 = 0;
  int* x9892 = (int*)malloc(1048576 * sizeof(int));
  int* x9893 = x9892;
  int* x9896 = (int*)malloc(1048576 * sizeof(int));
  int* x9897 = x9896;
  double* x9902 = (double*)malloc(1048576 * sizeof(double));
  double* x9903 = x9902;
  double* x9904 = (double*)malloc(1048576 * sizeof(double));
  double* x9905 = x9904;
  long* x9912 = (long*)malloc(1048576 * sizeof(long));
  long* x9913 = x9912;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  int x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    int x9924 = x9889;
    bool x9925 = x9924 < x3;
    if (!x9925) break;
    int x9928 = 0;
    for (;;) {
      int x9929 = x9889;
      char x9930 = x4[x9929];
      bool x9931 = x9930 != '|';
      bool x9936 = x9931;
      if (x9931) {
        int x9932 = x9889;
        char x9933 = x4[x9932];
        bool x9934 = x9933 != '\n';
        x9936 = x9934;
      }
      bool x9937 = x9936;
      if (!x9937) break;
      int x9939 = x9928;
      int x9941 = x9889;
      int x9940 = x9939 * 10;
      char x9942 = x4[x9941];
      char x9943 = x9942 - '0';
      int x9944 = x9940 + x9943;
      x9928 = x9944;
      x9889 = x9889 + 1;
    }
    x9889 = x9889 + 1;
    int x9950 = x9928;
    for (;;) {
      int x9953 = x9889;
      char x9954 = x4[x9953];
      bool x9955 = x9954 != '|';
      bool x9960 = x9955;
      if (x9955) {
        int x9956 = x9889;
        char x9957 = x4[x9956];
        bool x9958 = x9957 != '\n';
        x9960 = x9958;
      }
      bool x9961 = x9960;
      if (!x9961) break;
      x9889 = x9889 + 1;
    }
    x9889 = x9889 + 1;
    int x9976 = 0;
    for (;;) {
      int x9977 = x9889;
      char x9978 = x4[x9977];
      bool x9979 = x9978 != '|';
      bool x9984 = x9979;
      if (x9979) {
        int x9980 = x9889;
        char x9981 = x4[x9980];
        bool x9982 = x9981 != '\n';
        x9984 = x9982;
      }
      bool x9985 = x9984;
      if (!x9985) break;
      int x9987 = x9976;
      int x9989 = x9889;
      int x9988 = x9987 * 10;
      char x9990 = x4[x9989];
      char x9991 = x9990 - '0';
      int x9992 = x9988 + x9991;
      x9976 = x9992;
      x9889 = x9889 + 1;
    }
    x9889 = x9889 + 1;
    int x9998 = x9976;
    for (;;) {
      int x10001 = x9889;
      char x10002 = x4[x10001];
      bool x10003 = x10002 != '|';
      bool x10008 = x10003;
      if (x10003) {
        int x10004 = x9889;
        char x10005 = x4[x10004];
        bool x10006 = x10005 != '\n';
        x10008 = x10006;
      }
      bool x10009 = x10008;
      if (!x10009) break;
      x9889 = x9889 + 1;
    }
    x9889 = x9889 + 1;
    for (;;) {
      int x10026 = x9889;
      char x10027 = x4[x10026];
      bool x10028 = x10027 != '.';
      bool x10033 = x10028;
      if (x10028) {
        int x10029 = x9889;
        char x10030 = x4[x10029];
        bool x10031 = x10030 != '|';
        x10033 = x10031;
      }
      bool x10034 = x10033;
      bool x10039 = x10034;
      if (x10034) {
        int x10035 = x9889;
        char x10036 = x4[x10035];
        bool x10037 = x10036 != '\n';
        x10039 = x10037;
      }
      bool x10040 = x10039;
      if (!x10040) break;
      x9889 = x9889 + 1;
    }
    int x10052 = x9889;
    char x10053 = x4[x10052];
    bool x10054 = x10053 == '.';
    if (x10054) {
      x9889 = x9889 + 1;
      for (;;) {
        int x10056 = x9889;
        char x10057 = x4[x10056];
        bool x10058 = x10057 != '|';
        bool x10063 = x10058;
        if (x10058) {
          int x10059 = x9889;
          char x10060 = x4[x10059];
          bool x10061 = x10060 != '\n';
          x10063 = x10061;
        }
        bool x10064 = x10063;
        if (!x10064) break;
        x9889 = x9889 + 1;
      }
    } else {
    }
    x9889 = x9889 + 1;
    int x10089 = 0;
    int x10090 = 1;
    for (;;) {
      int x10091 = x9889;
      char x10092 = x4[x10091];
      bool x10093 = x10092 != '.';
      bool x10098 = x10093;
      if (x10093) {
        int x10094 = x9889;
        char x10095 = x4[x10094];
        bool x10096 = x10095 != '|';
        x10098 = x10096;
      }
      bool x10099 = x10098;
      bool x10104 = x10099;
      if (x10099) {
        int x10100 = x9889;
        char x10101 = x4[x10100];
        bool x10102 = x10101 != '\n';
        x10104 = x10102;
      }
      bool x10105 = x10104;
      if (!x10105) break;
      int x10107 = x10089;
      int x10109 = x9889;
      int x10108 = x10107 * 10;
      char x10110 = x4[x10109];
      char x10111 = x10110 - '0';
      int x10112 = x10108 + x10111;
      x10089 = x10112;
      x9889 = x9889 + 1;
    }
    int x10117 = x9889;
    char x10118 = x4[x10117];
    bool x10119 = x10118 == '.';
    if (x10119) {
      x9889 = x9889 + 1;
      for (;;) {
        int x10121 = x9889;
        char x10122 = x4[x10121];
        bool x10123 = x10122 != '|';
        bool x10128 = x10123;
        if (x10123) {
          int x10124 = x9889;
          char x10125 = x4[x10124];
          bool x10126 = x10125 != '\n';
          x10128 = x10126;
        }
        bool x10129 = x10128;
        if (!x10129) break;
        int x10131 = x10089;
        int x10133 = x9889;
        int x10132 = x10131 * 10;
        char x10134 = x4[x10133];
        char x10135 = x10134 - '0';
        int x10136 = x10132 + x10135;
        x10089 = x10136;
        int x10138 = x10090;
        int x10139 = x10138 * 10;
        x10090 = x10139;
        x9889 = x9889 + 1;
      }
    } else {
    }
    x9889 = x9889 + 1;
    int x10148 = x10089;
    int x10150 = x10090;
    int x10154 = 0;
    int x10155 = 1;
    for (;;) {
      int x10156 = x9889;
      char x10157 = x4[x10156];
      bool x10158 = x10157 != '.';
      bool x10163 = x10158;
      if (x10158) {
        int x10159 = x9889;
        char x10160 = x4[x10159];
        bool x10161 = x10160 != '|';
        x10163 = x10161;
      }
      bool x10164 = x10163;
      bool x10169 = x10164;
      if (x10164) {
        int x10165 = x9889;
        char x10166 = x4[x10165];
        bool x10167 = x10166 != '\n';
        x10169 = x10167;
      }
      bool x10170 = x10169;
      if (!x10170) break;
      int x10172 = x10154;
      int x10174 = x9889;
      int x10173 = x10172 * 10;
      char x10175 = x4[x10174];
      char x10176 = x10175 - '0';
      int x10177 = x10173 + x10176;
      x10154 = x10177;
      x9889 = x9889 + 1;
    }
    int x10182 = x9889;
    char x10183 = x4[x10182];
    bool x10184 = x10183 == '.';
    if (x10184) {
      x9889 = x9889 + 1;
      for (;;) {
        int x10186 = x9889;
        char x10187 = x4[x10186];
        bool x10188 = x10187 != '|';
        bool x10193 = x10188;
        if (x10188) {
          int x10189 = x9889;
          char x10190 = x4[x10189];
          bool x10191 = x10190 != '\n';
          x10193 = x10191;
        }
        bool x10194 = x10193;
        if (!x10194) break;
        int x10196 = x10154;
        int x10198 = x9889;
        int x10197 = x10196 * 10;
        char x10199 = x4[x10198];
        char x10200 = x10199 - '0';
        int x10201 = x10197 + x10200;
        x10154 = x10201;
        int x10203 = x10155;
        int x10204 = x10203 * 10;
        x10155 = x10204;
        x9889 = x9889 + 1;
      }
    } else {
    }
    x9889 = x9889 + 1;
    int x10213 = x10154;
    int x10215 = x10155;
    for (;;) {
      int x10221 = x9889;
      char x10222 = x4[x10221];
      bool x10223 = x10222 != '.';
      bool x10228 = x10223;
      if (x10223) {
        int x10224 = x9889;
        char x10225 = x4[x10224];
        bool x10226 = x10225 != '|';
        x10228 = x10226;
      }
      bool x10229 = x10228;
      bool x10234 = x10229;
      if (x10229) {
        int x10230 = x9889;
        char x10231 = x4[x10230];
        bool x10232 = x10231 != '\n';
        x10234 = x10232;
      }
      bool x10235 = x10234;
      if (!x10235) break;
      x9889 = x9889 + 1;
    }
    int x10247 = x9889;
    char x10248 = x4[x10247];
    bool x10249 = x10248 == '.';
    if (x10249) {
      x9889 = x9889 + 1;
      for (;;) {
        int x10251 = x9889;
        char x10252 = x4[x10251];
        bool x10253 = x10252 != '|';
        bool x10258 = x10253;
        if (x10253) {
          int x10254 = x9889;
          char x10255 = x4[x10254];
          bool x10256 = x10255 != '\n';
          x10258 = x10256;
        }
        bool x10259 = x10258;
        if (!x10259) break;
        x9889 = x9889 + 1;
      }
    } else {
    }
    x9889 = x9889 + 1;
    x9889 = x9889 + 2;
    x9889 = x9889 + 2;
    int x10290 = 0;
    for (;;) {
      int x10291 = x9889;
      char x10292 = x4[x10291];
      bool x10293 = x10292 != '-';
      bool x10298 = x10293;
      if (x10293) {
        int x10294 = x9889;
        char x10295 = x4[x10294];
        bool x10296 = x10295 != '\n';
        x10298 = x10296;
      }
      bool x10299 = x10298;
      if (!x10299) break;
      int x10301 = x10290;
      int x10303 = x9889;
      int x10302 = x10301 * 10;
      char x10304 = x4[x10303];
      char x10305 = x10304 - '0';
      int x10306 = x10302 + x10305;
      x10290 = x10306;
      x9889 = x9889 + 1;
    }
    x9889 = x9889 + 1;
    int x10312 = x10290;
    int x10314 = 0;
    for (;;) {
      int x10315 = x9889;
      char x10316 = x4[x10315];
      bool x10317 = x10316 != '-';
      bool x10322 = x10317;
      if (x10317) {
        int x10318 = x9889;
        char x10319 = x4[x10318];
        bool x10320 = x10319 != '\n';
        x10322 = x10320;
      }
      bool x10323 = x10322;
      if (!x10323) break;
      int x10325 = x10314;
      int x10327 = x9889;
      int x10326 = x10325 * 10;
      char x10328 = x4[x10327];
      char x10329 = x10328 - '0';
      int x10330 = x10326 + x10329;
      x10314 = x10330;
      x9889 = x9889 + 1;
    }
    x9889 = x9889 + 1;
    int x10336 = x10314;
    int x10338 = 0;
    for (;;) {
      int x10339 = x9889;
      char x10340 = x4[x10339];
      bool x10341 = x10340 != '|';
      bool x10346 = x10341;
      if (x10341) {
        int x10342 = x9889;
        char x10343 = x4[x10342];
        bool x10344 = x10343 != '\n';
        x10346 = x10344;
      }
      bool x10347 = x10346;
      if (!x10347) break;
      int x10349 = x10338;
      int x10351 = x9889;
      int x10350 = x10349 * 10;
      char x10352 = x4[x10351];
      char x10353 = x10352 - '0';
      int x10354 = x10350 + x10353;
      x10338 = x10354;
      x9889 = x9889 + 1;
    }
    x9889 = x9889 + 1;
    int x10360 = x10338;
    for (;;) {
      int x10367 = x9889;
      char x10368 = x4[x10367];
      bool x10369 = x10368 != '-';
      bool x10374 = x10369;
      if (x10369) {
        int x10370 = x9889;
        char x10371 = x4[x10370];
        bool x10372 = x10371 != '\n';
        x10374 = x10372;
      }
      bool x10375 = x10374;
      if (!x10375) break;
      x9889 = x9889 + 1;
    }
    x9889 = x9889 + 1;
    for (;;) {
      int x10391 = x9889;
      char x10392 = x4[x10391];
      bool x10393 = x10392 != '-';
      bool x10398 = x10393;
      if (x10393) {
        int x10394 = x9889;
        char x10395 = x4[x10394];
        bool x10396 = x10395 != '\n';
        x10398 = x10396;
      }
      bool x10399 = x10398;
      if (!x10399) break;
      x9889 = x9889 + 1;
    }
    x9889 = x9889 + 1;
    for (;;) {
      int x10415 = x9889;
      char x10416 = x4[x10415];
      bool x10417 = x10416 != '|';
      bool x10422 = x10417;
      if (x10417) {
        int x10418 = x9889;
        char x10419 = x4[x10418];
        bool x10420 = x10419 != '\n';
        x10422 = x10420;
      }
      bool x10423 = x10422;
      if (!x10423) break;
      x9889 = x9889 + 1;
    }
    x9889 = x9889 + 1;
    for (;;) {
      int x10443 = x9889;
      char x10444 = x4[x10443];
      bool x10445 = x10444 != '-';
      bool x10450 = x10445;
      if (x10445) {
        int x10446 = x9889;
        char x10447 = x4[x10446];
        bool x10448 = x10447 != '\n';
        x10450 = x10448;
      }
      bool x10451 = x10450;
      if (!x10451) break;
      x9889 = x9889 + 1;
    }
    x9889 = x9889 + 1;
    for (;;) {
      int x10467 = x9889;
      char x10468 = x4[x10467];
      bool x10469 = x10468 != '-';
      bool x10474 = x10469;
      if (x10469) {
        int x10470 = x9889;
        char x10471 = x4[x10470];
        bool x10472 = x10471 != '\n';
        x10474 = x10472;
      }
      bool x10475 = x10474;
      if (!x10475) break;
      x9889 = x9889 + 1;
    }
    x9889 = x9889 + 1;
    for (;;) {
      int x10491 = x9889;
      char x10492 = x4[x10491];
      bool x10493 = x10492 != '|';
      bool x10498 = x10493;
      if (x10493) {
        int x10494 = x9889;
        char x10495 = x4[x10494];
        bool x10496 = x10495 != '\n';
        x10498 = x10496;
      }
      bool x10499 = x10498;
      if (!x10499) break;
      x9889 = x9889 + 1;
    }
    x9889 = x9889 + 1;
    for (;;) {
      int x10518 = x9889;
      char x10519 = x4[x10518];
      bool x10520 = x10519 != '|';
      bool x10525 = x10520;
      if (x10520) {
        int x10521 = x9889;
        char x10522 = x4[x10521];
        bool x10523 = x10522 != '\n';
        x10525 = x10523;
      }
      bool x10526 = x10525;
      if (!x10526) break;
      x9889 = x9889 + 1;
    }
    x9889 = x9889 + 1;
    for (;;) {
      int x10536 = x9889;
      char x10537 = x4[x10536];
      bool x10538 = x10537 != '|';
      bool x10543 = x10538;
      if (x10538) {
        int x10539 = x9889;
        char x10540 = x4[x10539];
        bool x10541 = x10540 != '\n';
        x10543 = x10541;
      }
      bool x10544 = x10543;
      if (!x10544) break;
      x9889 = x9889 + 1;
    }
    x9889 = x9889 + 1;
    for (;;) {
      int x10554 = x9889;
      char x10555 = x4[x10554];
      bool x10556 = x10555 != '|';
      bool x10561 = x10556;
      if (x10556) {
        int x10557 = x9889;
        char x10558 = x4[x10557];
        bool x10559 = x10558 != '\n';
        x10561 = x10559;
      }
      bool x10562 = x10561;
      if (!x10562) break;
      x9889 = x9889 + 1;
    }
    x9889 = x9889 + 1;
    int x10572 = x9891;
    int x10573 = x9890;
    bool x10574 = x10572 == x10573;
    if (x10574) {
      int x10575 = x10573 * 4;
      x9890 = x10575;
      printf("buffer.resize %d\n",x10575);
      int* x10578 = x9893;
      int* x10579 = (int*)realloc(x10578,x10575 * sizeof(int));
      x9893 = x10579;
      int* x10584 = x9897;
      int* x10585 = (int*)realloc(x10584,x10575 * sizeof(int));
      x9897 = x10585;
      double* x10593 = x9903;
      double* x10594 = (double*)realloc(x10593,x10575 * sizeof(double));
      x9903 = x10594;
      double* x10596 = x9905;
      double* x10597 = (double*)realloc(x10596,x10575 * sizeof(double));
      x9905 = x10597;
      long* x10608 = x9913;
      long* x10609 = (long*)realloc(x10608,x10575 * sizeof(long));
      x9913 = x10609;
    } else {
    }
    int* x10628 = x9893;
    x10628[x10572] = x9950;
    int* x10632 = x9897;
    x10632[x10572] = x9998;
    double* x10638 = x9903;
    double x10149 = (double)x10148;
    double x10151 = (double)x10150;
    double x10152 = x10149 / x10151;
    x10638[x10572] = x10152;
    double* x10640 = x9905;
    double x10214 = (double)x10213;
    double x10216 = (double)x10215;
    double x10217 = x10214 / x10216;
    x10640[x10572] = x10217;
    long* x10648 = x9913;
    long x10361 = x10312 * 10000L;
    long x10362 = x10336 * 100L;
    long x10363 = x10361 + x10362;
    long x10364 = x10363 + x10360;
    x10648[x10572] = x10364;
    x9891 = x9891 + 1;
  }
  int x10663 = 0;
  int x10664 = 1048576;
  int x10665 = 0;
  int* x10666 = (int*)malloc(1048576 * sizeof(int));
  int* x10667 = x10666;
  int* x10672 = (int*)malloc(1048576 * sizeof(int));
  int* x10673 = x10672;
  int x3720 = open("../databases/sf2/customer.tbl",0);
  int x3721 = fsize(x3720);
  char* x3722 = mmap(0, x3721, PROT_READ, MAP_FILE | MAP_SHARED, x3720, 0);
  for (;;) {
    int x10682 = x10663;
    bool x10683 = x10682 < x3721;
    if (!x10683) break;
    int x10686 = 0;
    for (;;) {
      int x10687 = x10663;
      char x10688 = x3722[x10687];
      bool x10689 = x10688 != '|';
      bool x10694 = x10689;
      if (x10689) {
        int x10690 = x10663;
        char x10691 = x3722[x10690];
        bool x10692 = x10691 != '\n';
        x10694 = x10692;
      }
      bool x10695 = x10694;
      if (!x10695) break;
      int x10697 = x10686;
      int x10699 = x10663;
      int x10698 = x10697 * 10;
      char x10700 = x3722[x10699];
      char x10701 = x10700 - '0';
      int x10702 = x10698 + x10701;
      x10686 = x10702;
      x10663 = x10663 + 1;
    }
    x10663 = x10663 + 1;
    int x10708 = x10686;
    for (;;) {
      int x10710 = x10663;
      char x10711 = x3722[x10710];
      bool x10712 = x10711 != '|';
      bool x10717 = x10712;
      if (x10712) {
        int x10713 = x10663;
        char x10714 = x3722[x10713];
        bool x10715 = x10714 != '\n';
        x10717 = x10715;
      }
      bool x10718 = x10717;
      if (!x10718) break;
      x10663 = x10663 + 1;
    }
    x10663 = x10663 + 1;
    for (;;) {
      int x10728 = x10663;
      char x10729 = x3722[x10728];
      bool x10730 = x10729 != '|';
      bool x10735 = x10730;
      if (x10730) {
        int x10731 = x10663;
        char x10732 = x3722[x10731];
        bool x10733 = x10732 != '\n';
        x10735 = x10733;
      }
      bool x10736 = x10735;
      if (!x10736) break;
      x10663 = x10663 + 1;
    }
    x10663 = x10663 + 1;
    int x10746 = 0;
    for (;;) {
      int x10747 = x10663;
      char x10748 = x3722[x10747];
      bool x10749 = x10748 != '|';
      bool x10754 = x10749;
      if (x10749) {
        int x10750 = x10663;
        char x10751 = x3722[x10750];
        bool x10752 = x10751 != '\n';
        x10754 = x10752;
      }
      bool x10755 = x10754;
      if (!x10755) break;
      int x10757 = x10746;
      int x10759 = x10663;
      int x10758 = x10757 * 10;
      char x10760 = x3722[x10759];
      char x10761 = x10760 - '0';
      int x10762 = x10758 + x10761;
      x10746 = x10762;
      x10663 = x10663 + 1;
    }
    x10663 = x10663 + 1;
    int x10768 = x10746;
    for (;;) {
      int x10770 = x10663;
      char x10771 = x3722[x10770];
      bool x10772 = x10771 != '|';
      bool x10777 = x10772;
      if (x10772) {
        int x10773 = x10663;
        char x10774 = x3722[x10773];
        bool x10775 = x10774 != '\n';
        x10777 = x10775;
      }
      bool x10778 = x10777;
      if (!x10778) break;
      x10663 = x10663 + 1;
    }
    x10663 = x10663 + 1;
    for (;;) {
      int x10790 = x10663;
      char x10791 = x3722[x10790];
      bool x10792 = x10791 != '.';
      bool x10797 = x10792;
      if (x10792) {
        int x10793 = x10663;
        char x10794 = x3722[x10793];
        bool x10795 = x10794 != '|';
        x10797 = x10795;
      }
      bool x10798 = x10797;
      bool x10803 = x10798;
      if (x10798) {
        int x10799 = x10663;
        char x10800 = x3722[x10799];
        bool x10801 = x10800 != '\n';
        x10803 = x10801;
      }
      bool x10804 = x10803;
      if (!x10804) break;
      x10663 = x10663 + 1;
    }
    int x10816 = x10663;
    char x10817 = x3722[x10816];
    bool x10818 = x10817 == '.';
    if (x10818) {
      x10663 = x10663 + 1;
      for (;;) {
        int x10820 = x10663;
        char x10821 = x3722[x10820];
        bool x10822 = x10821 != '|';
        bool x10827 = x10822;
        if (x10822) {
          int x10823 = x10663;
          char x10824 = x3722[x10823];
          bool x10825 = x10824 != '\n';
          x10827 = x10825;
        }
        bool x10828 = x10827;
        if (!x10828) break;
        x10663 = x10663 + 1;
      }
    } else {
    }
    x10663 = x10663 + 1;
    for (;;) {
      int x10853 = x10663;
      char x10854 = x3722[x10853];
      bool x10855 = x10854 != '|';
      bool x10860 = x10855;
      if (x10855) {
        int x10856 = x10663;
        char x10857 = x3722[x10856];
        bool x10858 = x10857 != '\n';
        x10860 = x10858;
      }
      bool x10861 = x10860;
      if (!x10861) break;
      x10663 = x10663 + 1;
    }
    x10663 = x10663 + 1;
    for (;;) {
      int x10871 = x10663;
      char x10872 = x3722[x10871];
      bool x10873 = x10872 != '|';
      bool x10878 = x10873;
      if (x10873) {
        int x10874 = x10663;
        char x10875 = x3722[x10874];
        bool x10876 = x10875 != '\n';
        x10878 = x10876;
      }
      bool x10879 = x10878;
      if (!x10879) break;
      x10663 = x10663 + 1;
    }
    x10663 = x10663 + 1;
    int x10889 = x10665;
    int x10890 = x10664;
    bool x10891 = x10889 == x10890;
    if (x10891) {
      int x10892 = x10890 * 4;
      x10664 = x10892;
      printf("buffer.resize %d\n",x10892);
      int* x10895 = x10667;
      int* x10896 = (int*)realloc(x10895,x10892 * sizeof(int));
      x10667 = x10896;
      int* x10904 = x10673;
      int* x10905 = (int*)realloc(x10904,x10892 * sizeof(int));
      x10673 = x10905;
    } else {
    }
    int* x10921 = x10667;
    x10921[x10889] = x10708;
    int* x10927 = x10673;
    x10927[x10889] = x10768;
    x10665 = x10665 + 1;
  }
  int x10940 = 0;
  int x10941 = 1048576;
  int x10942 = 0;
  int* x10943 = (int*)malloc(1048576 * sizeof(int));
  int* x10944 = x10943;
  int* x10949 = (int*)malloc(1048576 * sizeof(int));
  int* x10950 = x10949;
  int x1747 = open("../databases/sf2/supplier.tbl",0);
  int x1748 = fsize(x1747);
  char* x1749 = mmap(0, x1748, PROT_READ, MAP_FILE | MAP_SHARED, x1747, 0);
  for (;;) {
    int x10957 = x10940;
    bool x10958 = x10957 < x1748;
    if (!x10958) break;
    int x10961 = 0;
    for (;;) {
      int x10962 = x10940;
      char x10963 = x1749[x10962];
      bool x10964 = x10963 != '|';
      bool x10969 = x10964;
      if (x10964) {
        int x10965 = x10940;
        char x10966 = x1749[x10965];
        bool x10967 = x10966 != '\n';
        x10969 = x10967;
      }
      bool x10970 = x10969;
      if (!x10970) break;
      int x10972 = x10961;
      int x10974 = x10940;
      int x10973 = x10972 * 10;
      char x10975 = x1749[x10974];
      char x10976 = x10975 - '0';
      int x10977 = x10973 + x10976;
      x10961 = x10977;
      x10940 = x10940 + 1;
    }
    x10940 = x10940 + 1;
    int x10983 = x10961;
    for (;;) {
      int x10985 = x10940;
      char x10986 = x1749[x10985];
      bool x10987 = x10986 != '|';
      bool x10992 = x10987;
      if (x10987) {
        int x10988 = x10940;
        char x10989 = x1749[x10988];
        bool x10990 = x10989 != '\n';
        x10992 = x10990;
      }
      bool x10993 = x10992;
      if (!x10993) break;
      x10940 = x10940 + 1;
    }
    x10940 = x10940 + 1;
    for (;;) {
      int x11003 = x10940;
      char x11004 = x1749[x11003];
      bool x11005 = x11004 != '|';
      bool x11010 = x11005;
      if (x11005) {
        int x11006 = x10940;
        char x11007 = x1749[x11006];
        bool x11008 = x11007 != '\n';
        x11010 = x11008;
      }
      bool x11011 = x11010;
      if (!x11011) break;
      x10940 = x10940 + 1;
    }
    x10940 = x10940 + 1;
    int x11021 = 0;
    for (;;) {
      int x11022 = x10940;
      char x11023 = x1749[x11022];
      bool x11024 = x11023 != '|';
      bool x11029 = x11024;
      if (x11024) {
        int x11025 = x10940;
        char x11026 = x1749[x11025];
        bool x11027 = x11026 != '\n';
        x11029 = x11027;
      }
      bool x11030 = x11029;
      if (!x11030) break;
      int x11032 = x11021;
      int x11034 = x10940;
      int x11033 = x11032 * 10;
      char x11035 = x1749[x11034];
      char x11036 = x11035 - '0';
      int x11037 = x11033 + x11036;
      x11021 = x11037;
      x10940 = x10940 + 1;
    }
    x10940 = x10940 + 1;
    int x11043 = x11021;
    for (;;) {
      int x11045 = x10940;
      char x11046 = x1749[x11045];
      bool x11047 = x11046 != '|';
      bool x11052 = x11047;
      if (x11047) {
        int x11048 = x10940;
        char x11049 = x1749[x11048];
        bool x11050 = x11049 != '\n';
        x11052 = x11050;
      }
      bool x11053 = x11052;
      if (!x11053) break;
      x10940 = x10940 + 1;
    }
    x10940 = x10940 + 1;
    for (;;) {
      int x11065 = x10940;
      char x11066 = x1749[x11065];
      bool x11067 = x11066 != '.';
      bool x11072 = x11067;
      if (x11067) {
        int x11068 = x10940;
        char x11069 = x1749[x11068];
        bool x11070 = x11069 != '|';
        x11072 = x11070;
      }
      bool x11073 = x11072;
      bool x11078 = x11073;
      if (x11073) {
        int x11074 = x10940;
        char x11075 = x1749[x11074];
        bool x11076 = x11075 != '\n';
        x11078 = x11076;
      }
      bool x11079 = x11078;
      if (!x11079) break;
      x10940 = x10940 + 1;
    }
    int x11091 = x10940;
    char x11092 = x1749[x11091];
    bool x11093 = x11092 == '.';
    if (x11093) {
      x10940 = x10940 + 1;
      for (;;) {
        int x11095 = x10940;
        char x11096 = x1749[x11095];
        bool x11097 = x11096 != '|';
        bool x11102 = x11097;
        if (x11097) {
          int x11098 = x10940;
          char x11099 = x1749[x11098];
          bool x11100 = x11099 != '\n';
          x11102 = x11100;
        }
        bool x11103 = x11102;
        if (!x11103) break;
        x10940 = x10940 + 1;
      }
    } else {
    }
    x10940 = x10940 + 1;
    for (;;) {
      int x11128 = x10940;
      char x11129 = x1749[x11128];
      bool x11130 = x11129 != '|';
      bool x11135 = x11130;
      if (x11130) {
        int x11131 = x10940;
        char x11132 = x1749[x11131];
        bool x11133 = x11132 != '\n';
        x11135 = x11133;
      }
      bool x11136 = x11135;
      if (!x11136) break;
      x10940 = x10940 + 1;
    }
    x10940 = x10940 + 1;
    int x11146 = x10942;
    int x11147 = x10941;
    bool x11148 = x11146 == x11147;
    if (x11148) {
      int x11149 = x11147 * 4;
      x10941 = x11149;
      printf("buffer.resize %d\n",x11149);
      int* x11152 = x10944;
      int* x11153 = (int*)realloc(x11152,x11149 * sizeof(int));
      x10944 = x11153;
      int* x11161 = x10950;
      int* x11162 = (int*)realloc(x11161,x11149 * sizeof(int));
      x10950 = x11162;
    } else {
    }
    int* x11175 = x10944;
    x11175[x11146] = x10983;
    int* x11181 = x10950;
    x11181[x11146] = x11043;
    x10942 = x10942 + 1;
  }
  bool x972 = true == false;
  int x11192;
  for(x11192=0; x11192 < 5; x11192++) {
    bool x11193 = false;
    int x11194 = 0;
    bool x11196 = false;
    int x11197 = 0;
    int x11201 = 0;
    char* x11202 = "";
    bool x11207 = false;
    int x11208 = 0;
    int* x11210 = (int*)malloc(134217728 * sizeof(int));
    int* x11211 = x11210;
    char** x11212 = (char**)malloc(134217728 * sizeof(char*));
    char** x11213 = x11212;
    int* x11218 = (int*)malloc(134217728 * sizeof(int));
    int* x11219 = x11218;
    char** x11220 = (char**)malloc(134217728 * sizeof(char*));
    char** x11221 = x11220;
    int x11226 = 0;
    int* x11227 = (int*)malloc(67108864 * sizeof(int));
    int* x11228 = (int*)malloc(134217728 * sizeof(int));
    int x11229;
    for(x11229=0; x11229 < 67108864; x11229++) {
      x11227[x11229] = -1;
    }
    bool x11234 = false;
    int x11235 = 0;
    char** x11240 = (char**)malloc(134217728 * sizeof(char*));
    char** x11241 = x11240;
    int* x11246 = (int*)malloc(134217728 * sizeof(int));
    int* x11247 = x11246;
    char** x11248 = (char**)malloc(134217728 * sizeof(char*));
    char** x11249 = x11248;
    int* x11254 = (int*)malloc(134217728 * sizeof(int));
    int* x11255 = x11254;
    int x11268 = 0;
    int* x11269 = (int*)malloc(67108864 * sizeof(int));
    int* x11270 = (int*)malloc(134217728 * sizeof(int));
    int x11271;
    for(x11271=0; x11271 < 67108864; x11271++) {
      x11269[x11271] = -1;
    }
    bool x11276 = false;
    int x11277 = 0;
    char** x11281 = (char**)malloc(134217728 * sizeof(char*));
    char** x11282 = x11281;
    int* x11287 = (int*)malloc(134217728 * sizeof(int));
    int* x11288 = x11287;
    char** x11289 = (char**)malloc(134217728 * sizeof(char*));
    char** x11290 = x11289;
    int* x11309 = (int*)malloc(134217728 * sizeof(int));
    int* x11310 = x11309;
    double* x11319 = (double*)malloc(134217728 * sizeof(double));
    double* x11320 = x11319;
    double* x11321 = (double*)malloc(134217728 * sizeof(double));
    double* x11322 = x11321;
    long* x11329 = (long*)malloc(134217728 * sizeof(long));
    long* x11330 = x11329;
    int x11341 = 0;
    int* x11342 = (int*)malloc(67108864 * sizeof(int));
    int* x11343 = (int*)malloc(134217728 * sizeof(int));
    int x11344;
    for(x11344=0; x11344 < 67108864; x11344++) {
      x11342[x11344] = -1;
    }
    bool x11349 = false;
    int x11350 = 0;
    int* x11352 = (int*)malloc(134217728 * sizeof(int));
    int* x11353 = x11352;
    int* x11358 = (int*)malloc(134217728 * sizeof(int));
    int* x11359 = x11358;
    int x11368 = 0;
    int* x11369 = (int*)malloc(67108864 * sizeof(int));
    int* x11370 = (int*)malloc(134217728 * sizeof(int));
    int x11371;
    for(x11371=0; x11371 < 67108864; x11371++) {
      x11369[x11371] = -1;
    }
    struct Anon1594456343* x11377 = (struct Anon1594456343*)malloc(16777216 * sizeof(struct Anon1594456343));
    struct Anon1594456343* x11378 = x11377;
    int x11379 = 0;
    int* x11380 = (int*)malloc(16777216 * sizeof(int));
    int x11381;
    for(x11381=0; x11381 < 16777216; x11381++) {
      struct Anon1594456343* x11382 = x11378;
      struct Anon1594456343 x11383 = x11382[x11381];
      struct Anon726278688 x11384 = x11383.key;;
      struct Anon2052879266 x11385 = x11383.aggs;;
      struct Anon1594456343 x11386;
      x11386.exists = false;
      x11386.key = x11384;
      x11386.aggs = x11385;
      x11382[x11381] = x11386;
    }
    int x11391 = 0;
    struct timeval x12094, x12095, x12096;
    gettimeofday(&x12094, NULL);
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x11393 = x11349;
      bool x11394 = !x11393;
      bool x11399 = x11394;
      if (x11394) {
        int x11395 = x11350;
        int x11396 = x10665;
        bool x11397 = x11395 < x11396;
        x11399 = x11397;
      }
      bool x11400 = x11399;
      if (!x11400) break;
      int x11402 = x11350;
      int* x11403 = x10667;
      int x11404 = x11403[x11402];
      int* x11409 = x10673;
      int x11410 = x11409[x11402];
      x11350 = x11350 + 1;
      int x11421 = x11368;
      int* x11422 = x11353;
      x11422[x11421] = x11404;
      int* x11428 = x11359;
      x11428[x11421] = x11410;
      x11368 = x11368 + 1;
      int x11439 = x11404 & 67108863;
      int x11440 = x11369[x11439];
      x11369[x11439] = x11421;
      x11370[x11421] = x11440;
    }
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x11446 = x11193;
      bool x11447 = !x11446;
      bool x11452 = x11447;
      if (x11447) {
        int x11448 = x11194;
        int x11449 = x9410;
        bool x11450 = x11448 < x11449;
        x11452 = x11450;
      }
      bool x11453 = x11452;
      if (!x11453) break;
      int x11455 = x11194;
      int* x11456 = x9412;
      int x11457 = x11456[x11455];
      char** x11458 = x9414;
      char* x11459 = x11458[x11455];
      x11194 = x11194 + 1;
      x11201 = x11457;
      x11202 = x11459;
      printf("%s\n","begin scan NATION");
      for (;;) {
        bool x11472 = x11196;
        bool x11473 = !x11472;
        bool x11478 = x11473;
        if (x11473) {
          int x11474 = x11197;
          int x11475 = x9410;
          bool x11476 = x11474 < x11475;
          x11478 = x11476;
        }
        bool x11479 = x11478;
        if (!x11479) break;
        int x11481 = x11197;
        int* x11482 = x9412;
        int x11483 = x11482[x11481];
        char** x11484 = x9414;
        char* x11485 = x11484[x11481];
        x11197 = x11197 + 1;
        int x11493 = x11201;
        char* x11494 = x11202;
        bool x11498 = strcmp(x11494,"UNITED STATES") == 0;;
        bool x11500 = x11498;
        if (x11498) {
          bool x11499 = strcmp(x11485,"INDONESIA") == 0;;
          x11500 = x11499;
        }
        bool x11501 = x11500;
        bool x11506 = x11501;
        if (x11501 == false) {
          bool x11502 = strcmp(x11494,"INDONESIA") == 0;;
          bool x11504 = x11502;
          if (x11502) {
            bool x11503 = strcmp(x11485,"UNITED STATES") == 0;;
            x11504 = x11503;
          }
          bool x11505 = x11504;
          x11506 = x11505;
        }
        bool x11507 = x11506;
        if (x11507) {
          int x11511 = x11226;
          int* x11512 = x11211;
          x11512[x11511] = x11493;
          char** x11514 = x11213;
          x11514[x11511] = x11494;
          int* x11520 = x11219;
          x11520[x11511] = x11483;
          char** x11522 = x11221;
          x11522[x11511] = x11485;
          x11226 = x11226 + 1;
          int x11529 = x11493 & 67108863;
          int x11530 = x11227[x11529];
          x11227[x11529] = x11511;
          x11228[x11511] = x11530;
        } else {
        }
      }
      x11197 = 0;
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x11541 = x11207;
      bool x11542 = !x11541;
      bool x11547 = x11542;
      if (x11542) {
        int x11543 = x11208;
        int x11544 = x10942;
        bool x11545 = x11543 < x11544;
        x11547 = x11545;
      }
      bool x11548 = x11547;
      if (!x11548) break;
      int x11550 = x11208;
      int* x11551 = x10944;
      int x11552 = x11551[x11550];
      int* x11557 = x10950;
      int x11558 = x11557[x11550];
      x11208 = x11208 + 1;
      int x11567 = x11558 & 67108863;
      int x11568 = x11227[x11567];
      int x11569 = x11568;
      int x11629 = x11552 & 67108863;
      for (;;) {
        int x11570 = x11569;
        bool x11571 = x11570 != -1;
        if (!x11571) break;
        int x11573 = x11569;
        int* x11574 = x11211;
        int x11575 = x11574[x11573];
        char** x11576 = x11213;
        char* x11577 = x11576[x11573];
        int* x11582 = x11219;
        int x11583 = x11582[x11573];
        char** x11584 = x11221;
        char* x11585 = x11584[x11573];
        int x11591 = x11228[x11573];
        x11569 = x11591;
        bool x11593 = x11575 == x11558;
        if (x11593) {
          int x11597 = x11268;
          char** x11600 = x11241;
          x11600[x11597] = x11577;
          int* x11606 = x11247;
          x11606[x11597] = x11583;
          char** x11608 = x11249;
          x11608[x11597] = x11585;
          int* x11614 = x11255;
          x11614[x11597] = x11552;
          x11268 = x11268 + 1;
          int x11630 = x11269[x11629];
          x11269[x11629] = x11597;
          x11270[x11597] = x11630;
        } else {
        }
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x11640 = x11234;
      bool x11641 = !x11640;
      bool x11646 = x11641;
      if (x11641) {
        int x11642 = x11235;
        int x11643 = x9891;
        bool x11644 = x11642 < x11643;
        x11646 = x11644;
      }
      bool x11647 = x11646;
      if (!x11647) break;
      int x11649 = x11235;
      int* x11650 = x9893;
      int x11651 = x11650[x11649];
      int* x11654 = x9897;
      int x11655 = x11654[x11649];
      double* x11660 = x9903;
      double x11661 = x11660[x11649];
      double* x11662 = x9905;
      double x11663 = x11662[x11649];
      long* x11670 = x9913;
      long x11671 = x11670[x11649];
      x11235 = x11235 + 1;
      bool x11684 = x11671 >= 19950101L;
      bool x11686 = x11684;
      if (x11684) {
        bool x11685 = x11671 <= 19961231L;
        x11686 = x11685;
      }
      bool x11687 = x11686;
      if (x11687) {
        int x11688 = x11655 & 67108863;
        int x11689 = x11269[x11688];
        int x11690 = x11689;
        int x11796 = x11651 & 67108863;
        for (;;) {
          int x11691 = x11690;
          bool x11692 = x11691 != -1;
          if (!x11692) break;
          int x11694 = x11690;
          char** x11697 = x11241;
          char* x11698 = x11697[x11694];
          int* x11703 = x11247;
          int x11704 = x11703[x11694];
          char** x11705 = x11249;
          char* x11706 = x11705[x11694];
          int* x11711 = x11255;
          int x11712 = x11711[x11694];
          int x11726 = x11270[x11694];
          x11690 = x11726;
          bool x11728 = x11712 == x11655;
          if (x11728) {
            int x11732 = x11341;
            char** x11735 = x11282;
            x11735[x11732] = x11698;
            int* x11741 = x11288;
            x11741[x11732] = x11704;
            char** x11743 = x11290;
            x11743[x11732] = x11706;
            int* x11763 = x11310;
            x11763[x11732] = x11651;
            double* x11773 = x11320;
            x11773[x11732] = x11661;
            double* x11775 = x11322;
            x11775[x11732] = x11663;
            long* x11783 = x11330;
            x11783[x11732] = x11671;
            x11341 = x11341 + 1;
            int x11797 = x11342[x11796];
            x11342[x11796] = x11732;
            x11343[x11732] = x11797;
          } else {
          }
        }
      } else {
      }
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x11809 = x11276;
      bool x11810 = !x11809;
      bool x11815 = x11810;
      if (x11810) {
        int x11811 = x11277;
        int x11812 = x9540;
        bool x11813 = x11811 < x11812;
        x11815 = x11813;
      }
      bool x11816 = x11815;
      if (!x11816) break;
      int x11818 = x11277;
      int* x11819 = x9542;
      int x11820 = x11819[x11818];
      int* x11821 = x9544;
      int x11822 = x11821[x11818];
      x11277 = x11277 + 1;
      int x11839 = x11820 & 67108863;
      int x11840 = x11342[x11839];
      int x11841 = x11840;
      int x11915 = x11822 & 67108863;
      for (;;) {
        int x11842 = x11841;
        bool x11843 = x11842 != -1;
        if (!x11843) break;
        int x11845 = x11841;
        char** x11848 = x11282;
        char* x11849 = x11848[x11845];
        int* x11854 = x11288;
        int x11855 = x11854[x11845];
        char** x11856 = x11290;
        char* x11857 = x11856[x11845];
        int* x11876 = x11310;
        int x11877 = x11876[x11845];
        double* x11886 = x11320;
        double x11887 = x11886[x11845];
        double* x11888 = x11322;
        double x11889 = x11888[x11845];
        long* x11896 = x11330;
        long x11897 = x11896[x11845];
        int x11909 = x11343[x11845];
        x11841 = x11909;
        bool x11911 = x11877 == x11820;
        if (x11911) {
          int x11916 = x11369[x11915];
          int x11917 = x11916;
          char x11962 = x11849[0];
          int x11963 = x11962 * 41;
          char x11964 = x11849[1];
          int x11965 = x11963 + x11964;
          int x11966 = x11965 * 41;
          char x11967 = x11849[2];
          int x11968 = x11966 + x11967;
          int x11969 = x11968 * 41;
          char x11970 = x11849[3];
          int x11971 = x11969 + x11970;
          long x11948 = x11897; // date
          long x11949 = x11948/10000;
          int x11950 = (int)x11949;
          char x11952 = x11857[0];
          int x11953 = x11952 * 41;
          char x11954 = x11857[1];
          int x11955 = x11953 + x11954;
          int x11956 = x11955 * 41;
          char x11957 = x11857[2];
          int x11958 = x11956 + x11957;
          int x11959 = x11958 * 41;
          char x11960 = x11857[3];
          int x11961 = x11959 + x11960;
          int x11972 = x11961 * 41;
          int x11973 = x11972 + x11950;
          int x11974 = x11973 * 41;
          int x11975 = x11974 + x11971;
          int x11976 = x11975 & 16777215;
          double x11999 = 1.0 - x11889;
          double x12000 = x11887 * x11999;
          struct Anon726278688 x11951;
          x11951.SUPP_NATION = x11849;
          x11951.CUST_NATION = x11857;
          x11951.L_YEAR = x11950;
          struct Anon2052879266 x12042;
          x12042._0 = x12000;
          struct Anon1594456343 x12043;
          x12043.exists = true;
          x12043.key = x11951;
          x12043.aggs = x12042;
          for (;;) {
            int x11918 = x11917;
            bool x11919 = x11918 != -1;
            if (!x11919) break;
            int x11921 = x11917;
            int* x11922 = x11353;
            int x11923 = x11922[x11921];
            int* x11928 = x11359;
            int x11929 = x11928[x11921];
            int x11939 = x11370[x11921];
            x11917 = x11939;
            bool x11941 = x11923 == x11822;
            bool x11943 = x11941;
            if (x11941) {
              bool x11942 = x11929 == x11855;
              x11943 = x11942;
            }
            bool x11944 = x11943;
            if (x11944) {
              int x11977 = x11976;
              struct Anon1594456343* x11978 = x11378;
              struct Anon1594456343 x11979 = x11978[x11976];
              struct Anon1594456343 x11980 = x11979;
              bool x11981 = x11979.exists;;
              bool x11995 = x11981;
              if (x11981) {
                struct Anon1594456343 x11982 = x11980;
                struct Anon726278688 x11983 = x11982.key;;
                char* x11984 = x11983.SUPP_NATION;;
                bool x11985 = strcmp(x11984,x11849) == 0;;
                bool x11990 = x11985;
                if (x11985) {
                  char* x11986 = x11983.CUST_NATION;;
                  bool x11987 = strcmp(x11986,x11857) == 0;;
                  x11990 = x11987;
                }
                bool x11991 = x11990;
                bool x11992 = x11991;
                if (x11991) {
                  int x11988 = x11983.L_YEAR;;
                  bool x11989 = x11988 == x11950;
                  x11992 = x11989;
                }
                bool x11993 = x11992;
                x11995 = x11993;
              }
              bool x11996 = x11995;
              if (x11996) {
                struct Anon2052879266 x11997 = x11979.aggs;;
                struct Anon726278688 x12003 = x11979.key;;
                double x11998 = x11997._0;;
                double x12001 = x11998 + x12000;
                struct Anon2052879266 x12002;
                x12002._0 = x12001;
                struct Anon1594456343 x12004;
                x12004.exists = true;
                x12004.key = x12003;
                x12004.aggs = x12002;
                x11978[x11976] = x12004;
              } else {
                for (;;) {
                  struct Anon1594456343 x12007 = x11980;
                  bool x12008 = x12007.exists;;
                  bool x12052;
                  if (x12008) {
                    struct Anon726278688 x12009 = x12007.key;;
                    char* x12010 = x12009.SUPP_NATION;;
                    bool x12011 = strcmp(x12010,x11849) == 0;;
                    bool x12016 = x12011;
                    if (x12011) {
                      char* x12012 = x12009.CUST_NATION;;
                      bool x12013 = strcmp(x12012,x11857) == 0;;
                      x12016 = x12013;
                    }
                    bool x12017 = x12016;
                    bool x12018 = x12017;
                    if (x12017) {
                      int x12014 = x12009.L_YEAR;;
                      bool x12015 = x12014 == x11950;
                      x12018 = x12015;
                    }
                    bool x12019 = x12018;
                    bool x12039;
                    if (x12019) {
                      struct Anon2052879266 x12020 = x12007.aggs;;
                      int x12024 = x11977;
                      struct Anon1594456343* x12026 = x11378;
                      double x12021 = x12020._0;;
                      double x12022 = x12021 + x12000;
                      struct Anon2052879266 x12023;
                      x12023._0 = x12022;
                      struct Anon1594456343 x12025;
                      x12025.exists = true;
                      x12025.key = x12009;
                      x12025.aggs = x12023;
                      x12026[x12024] = x12025;
                      x12039 = false;
                    } else {
                      int x12029 = x11977;
                      int x12030 = x12029 + 1;
                      int x12031 = x12030 % 16777215;
                      x11977 = x12031;
                      struct Anon1594456343* x12033 = x11378;
                      struct Anon1594456343 x12034 = x12033[x12031];
                      x11980 = x12034;
                      x12039 = true;
                    }
                    x12052 = x12039;
                  } else {
                    int x12041 = x11977;
                    struct Anon1594456343* x12044 = x11378;
                    x12044[x12041] = x12043;
                    int x12046 = x11379;
                    x11380[x12046] = x12041;
                    x11379 = x11379 + 1;
                    x12052 = false;
                  }
                  if (!x12052) break;
                }
              }
            } else {
            }
          }
        } else {
        }
      }
    }
    int x12069 = x11379;
    int x12071;
    for(x12071=0; x12071 < x12069; x12071++) {
      int x12072 = x11380[x12071];
      struct Anon1594456343* x12073 = x11378;
      struct Anon1594456343 x12074 = x12073[x12072];
      if (x972) {
      } else {
        struct Anon726278688 x12077 = x12074.key;;
        struct Anon2052879266 x12083 = x12074.aggs;;
        char* x12078 = x12077.SUPP_NATION;;
        int x12079 = strlen(x12078);
        char* x12080 = x12077.CUST_NATION;;
        int x12081 = strlen(x12080);
        int x12082 = x12077.L_YEAR;;
        double x12084 = x12083._0;;
        printf("%.*s|%.*s|%d|%.4f\n",x12079,x12078,x12081,x12080,x12082,x12084);
        x11391 = x11391 + 1;
      }
    }
    int x12091 = x11391;
    printf("(%d rows)\n",x12091);
    gettimeofday(&x12095, NULL);
    timeval_subtract(&x12096, &x12095, &x12094);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x12096.tv_sec * 1000) + (x12096.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
