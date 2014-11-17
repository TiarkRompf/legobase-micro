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

struct Anon147418070 {
char* N_NAME;
int N_NATIONKEY;
int C_CUSTKEY;
};

struct Anon726278688 {
char* SUPP_NATION;
char* CUST_NATION;
int L_YEAR;
};

struct Anon2052879266 {
double _0;
};

struct Anon1587544425 {
bool exists;
struct Anon726278688 key;
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

struct Anon625264174 {
char L_RETURNFLAG;
char L_LINESTATUS;
};

struct Anon1931420570 {
bool exists;
struct Anon625264174 key;
struct Anon567626277 aggs;
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

struct Anon72918141 {
int N2_N_NATIONKEY;
char* N2_N_NAME;
int N2_N_REGIONKEY;
char* N2_N_COMMENT;
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

struct Anon801061462 {
bool exists;
char* key;
struct Anon2052879266 aggs;
};

/************************ FUNCTIONS **************************/

/************************ MAIN BODY **************************/
int main(int x9410, char** x9411) {
  long x9412 = 0L;
  long x6 = DEFAULT_INPUT_SIZE;
  long x9413 = x6;
  long x9414 = 0L;
  int* x9415 = (int*)malloc(x6 * sizeof(int));
  int* x9416 = x9415;
  char** x9417 = (char**)malloc(x6 * sizeof(char*));
  char** x9418 = x9417;
  int x1515 = open("../databases/sf2/nation.tbl",0);
  long x1516 = fsize(x1515);
  char* x1517 = mmap(0, x1516, PROT_READ, MAP_FILE | MAP_SHARED, x1515, 0);
  for (;;) {
    long x9423 = x9412;
    bool x9424 = x9423 < x1516;
    if (!x9424) break;
    int x9427 = 0;
    for (;;) {
      long x9428 = x9412;
      char x9429 = x1517[x9428];
      bool x9430 = x9429 != '|';
      bool x9435 = x9430;
      if (x9430) {
        long x9431 = x9412;
        char x9432 = x1517[x9431];
        bool x9433 = x9432 != '\n';
        x9435 = x9433;
      }
      bool x9436 = x9435;
      if (!x9436) break;
      int x9438 = x9427;
      long x9440 = x9412;
      int x9439 = x9438 * 10;
      char x9441 = x1517[x9440];
      char x9442 = x9441 - '0';
      int x9443 = x9439 + x9442;
      x9427 = x9443;
      x9412 = x9412 + 1;
    }
    x9412 = x9412 + 1;
    int x9449 = x9427;
    long x9450 = x9412;
    for (;;) {
      long x9451 = x9412;
      char x9452 = x1517[x9451];
      bool x9453 = x9452 != '|';
      bool x9458 = x9453;
      if (x9453) {
        long x9454 = x9412;
        char x9455 = x1517[x9454];
        bool x9456 = x9455 != '\n';
        x9458 = x9456;
      }
      bool x9459 = x9458;
      if (!x9459) break;
      x9412 = x9412 + 1;
    }
    x9412 = x9412 + 1;
    for (;;) {
      long x9470 = x9412;
      char x9471 = x1517[x9470];
      bool x9472 = x9471 != '|';
      bool x9477 = x9472;
      if (x9472) {
        long x9473 = x9412;
        char x9474 = x1517[x9473];
        bool x9475 = x9474 != '\n';
        x9477 = x9475;
      }
      bool x9478 = x9477;
      if (!x9478) break;
      x9412 = x9412 + 1;
    }
    x9412 = x9412 + 1;
    for (;;) {
      long x9493 = x9412;
      char x9494 = x1517[x9493];
      bool x9495 = x9494 != '|';
      bool x9500 = x9495;
      if (x9495) {
        long x9496 = x9412;
        char x9497 = x1517[x9496];
        bool x9498 = x9497 != '\n';
        x9500 = x9498;
      }
      bool x9501 = x9500;
      if (!x9501) break;
      x9412 = x9412 + 1;
    }
    x9412 = x9412 + 1;
    long x9511 = x9414;
    long x9512 = x9413;
    bool x9513 = x9511 == x9512;
    if (x9513) {
      long x9514 = x9512 * 4L;
      x9413 = x9514;
      printf("buffer.resize %d\n",x9514);
      int* x9517 = x9416;
      int* x9518 = (int*)realloc(x9517,x9514 * sizeof(int));
      x9416 = x9518;
      char** x9520 = x9418;
      char** x9521 = (char**)realloc(x9520,x9514 * sizeof(char*));
      x9418 = x9521;
    } else {
    }
    int* x9531 = x9416;
    x9531[x9511] = x9449;
    char** x9533 = x9418;
    char* x9467 = x1517+x9450;
    x9533[x9511] = x9467;
    x9414 = x9414 + 1;
  }
  long x9542 = 0L;
  long x9543 = x6;
  long x9544 = 0L;
  int* x9545 = (int*)malloc(x6 * sizeof(int));
  int* x9546 = x9545;
  int* x9547 = (int*)malloc(x6 * sizeof(int));
  int* x9548 = x9547;
  int x3371 = open("../databases/sf2/orders.tbl",0);
  long x3372 = fsize(x3371);
  char* x3373 = mmap(0, x3372, PROT_READ, MAP_FILE | MAP_SHARED, x3371, 0);
  for (;;) {
    long x9563 = x9542;
    bool x9564 = x9563 < x3372;
    if (!x9564) break;
    int x9567 = 0;
    for (;;) {
      long x9568 = x9542;
      char x9569 = x3373[x9568];
      bool x9570 = x9569 != '|';
      bool x9575 = x9570;
      if (x9570) {
        long x9571 = x9542;
        char x9572 = x3373[x9571];
        bool x9573 = x9572 != '\n';
        x9575 = x9573;
      }
      bool x9576 = x9575;
      if (!x9576) break;
      int x9578 = x9567;
      long x9580 = x9542;
      int x9579 = x9578 * 10;
      char x9581 = x3373[x9580];
      char x9582 = x9581 - '0';
      int x9583 = x9579 + x9582;
      x9567 = x9583;
      x9542 = x9542 + 1;
    }
    x9542 = x9542 + 1;
    int x9589 = x9567;
    int x9591 = 0;
    for (;;) {
      long x9592 = x9542;
      char x9593 = x3373[x9592];
      bool x9594 = x9593 != '|';
      bool x9599 = x9594;
      if (x9594) {
        long x9595 = x9542;
        char x9596 = x3373[x9595];
        bool x9597 = x9596 != '\n';
        x9599 = x9597;
      }
      bool x9600 = x9599;
      if (!x9600) break;
      int x9602 = x9591;
      long x9604 = x9542;
      int x9603 = x9602 * 10;
      char x9605 = x3373[x9604];
      char x9606 = x9605 - '0';
      int x9607 = x9603 + x9606;
      x9591 = x9607;
      x9542 = x9542 + 1;
    }
    x9542 = x9542 + 1;
    int x9613 = x9591;
    x9542 = x9542 + 2;
    for (;;) {
      long x9620 = x9542;
      char x9621 = x3373[x9620];
      bool x9622 = x9621 != '.';
      bool x9627 = x9622;
      if (x9622) {
        long x9623 = x9542;
        char x9624 = x3373[x9623];
        bool x9625 = x9624 != '|';
        x9627 = x9625;
      }
      bool x9628 = x9627;
      bool x9633 = x9628;
      if (x9628) {
        long x9629 = x9542;
        char x9630 = x3373[x9629];
        bool x9631 = x9630 != '\n';
        x9633 = x9631;
      }
      bool x9634 = x9633;
      if (!x9634) break;
      x9542 = x9542 + 1;
    }
    long x9646 = x9542;
    char x9647 = x3373[x9646];
    bool x9648 = x9647 == '.';
    if (x9648) {
      x9542 = x9542 + 1;
      for (;;) {
        long x9650 = x9542;
        char x9651 = x3373[x9650];
        bool x9652 = x9651 != '|';
        bool x9657 = x9652;
        if (x9652) {
          long x9653 = x9542;
          char x9654 = x3373[x9653];
          bool x9655 = x9654 != '\n';
          x9657 = x9655;
        }
        bool x9658 = x9657;
        if (!x9658) break;
        x9542 = x9542 + 1;
      }
    } else {
    }
    x9542 = x9542 + 1;
    for (;;) {
      long x9684 = x9542;
      char x9685 = x3373[x9684];
      bool x9686 = x9685 != '-';
      bool x9691 = x9686;
      if (x9686) {
        long x9687 = x9542;
        char x9688 = x3373[x9687];
        bool x9689 = x9688 != '\n';
        x9691 = x9689;
      }
      bool x9692 = x9691;
      if (!x9692) break;
      x9542 = x9542 + 1;
    }
    x9542 = x9542 + 1;
    for (;;) {
      long x9708 = x9542;
      char x9709 = x3373[x9708];
      bool x9710 = x9709 != '-';
      bool x9715 = x9710;
      if (x9710) {
        long x9711 = x9542;
        char x9712 = x3373[x9711];
        bool x9713 = x9712 != '\n';
        x9715 = x9713;
      }
      bool x9716 = x9715;
      if (!x9716) break;
      x9542 = x9542 + 1;
    }
    x9542 = x9542 + 1;
    for (;;) {
      long x9732 = x9542;
      char x9733 = x3373[x9732];
      bool x9734 = x9733 != '|';
      bool x9739 = x9734;
      if (x9734) {
        long x9735 = x9542;
        char x9736 = x3373[x9735];
        bool x9737 = x9736 != '\n';
        x9739 = x9737;
      }
      bool x9740 = x9739;
      if (!x9740) break;
      x9542 = x9542 + 1;
    }
    x9542 = x9542 + 1;
    for (;;) {
      long x9759 = x9542;
      char x9760 = x3373[x9759];
      bool x9761 = x9760 != '|';
      bool x9766 = x9761;
      if (x9761) {
        long x9762 = x9542;
        char x9763 = x3373[x9762];
        bool x9764 = x9763 != '\n';
        x9766 = x9764;
      }
      bool x9767 = x9766;
      if (!x9767) break;
      x9542 = x9542 + 1;
    }
    x9542 = x9542 + 1;
    for (;;) {
      long x9777 = x9542;
      char x9778 = x3373[x9777];
      bool x9779 = x9778 != '|';
      bool x9784 = x9779;
      if (x9779) {
        long x9780 = x9542;
        char x9781 = x3373[x9780];
        bool x9782 = x9781 != '\n';
        x9784 = x9782;
      }
      bool x9785 = x9784;
      if (!x9785) break;
      x9542 = x9542 + 1;
    }
    x9542 = x9542 + 1;
    for (;;) {
      long x9796 = x9542;
      char x9797 = x3373[x9796];
      bool x9798 = x9797 != '|';
      bool x9803 = x9798;
      if (x9798) {
        long x9799 = x9542;
        char x9800 = x3373[x9799];
        bool x9801 = x9800 != '\n';
        x9803 = x9801;
      }
      bool x9804 = x9803;
      if (!x9804) break;
      x9542 = x9542 + 1;
    }
    x9542 = x9542 + 1;
    for (;;) {
      long x9819 = x9542;
      char x9820 = x3373[x9819];
      bool x9821 = x9820 != '|';
      bool x9826 = x9821;
      if (x9821) {
        long x9822 = x9542;
        char x9823 = x3373[x9822];
        bool x9824 = x9823 != '\n';
        x9826 = x9824;
      }
      bool x9827 = x9826;
      if (!x9827) break;
      x9542 = x9542 + 1;
    }
    x9542 = x9542 + 1;
    long x9837 = x9544;
    long x9838 = x9543;
    bool x9839 = x9837 == x9838;
    if (x9839) {
      long x9840 = x9838 * 4L;
      x9543 = x9840;
      printf("buffer.resize %d\n",x9840);
      int* x9843 = x9546;
      int* x9844 = (int*)realloc(x9843,x9840 * sizeof(int));
      x9546 = x9844;
      int* x9846 = x9548;
      int* x9847 = (int*)realloc(x9846,x9840 * sizeof(int));
      x9548 = x9847;
    } else {
    }
    int* x9872 = x9546;
    x9872[x9837] = x9589;
    int* x9874 = x9548;
    x9874[x9837] = x9613;
    x9544 = x9544 + 1;
  }
  long x9893 = 0L;
  long x9894 = x6;
  long x9895 = 0L;
  int* x9896 = (int*)malloc(x6 * sizeof(int));
  int* x9897 = x9896;
  int* x9900 = (int*)malloc(x6 * sizeof(int));
  int* x9901 = x9900;
  double* x9906 = (double*)malloc(x6 * sizeof(double));
  double* x9907 = x9906;
  double* x9908 = (double*)malloc(x6 * sizeof(double));
  double* x9909 = x9908;
  long* x9916 = (long*)malloc(x6 * sizeof(long));
  long* x9917 = x9916;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  long x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    long x9928 = x9893;
    bool x9929 = x9928 < x3;
    if (!x9929) break;
    int x9932 = 0;
    for (;;) {
      long x9933 = x9893;
      char x9934 = x4[x9933];
      bool x9935 = x9934 != '|';
      bool x9940 = x9935;
      if (x9935) {
        long x9936 = x9893;
        char x9937 = x4[x9936];
        bool x9938 = x9937 != '\n';
        x9940 = x9938;
      }
      bool x9941 = x9940;
      if (!x9941) break;
      int x9943 = x9932;
      long x9945 = x9893;
      int x9944 = x9943 * 10;
      char x9946 = x4[x9945];
      char x9947 = x9946 - '0';
      int x9948 = x9944 + x9947;
      x9932 = x9948;
      x9893 = x9893 + 1;
    }
    x9893 = x9893 + 1;
    int x9954 = x9932;
    for (;;) {
      long x9957 = x9893;
      char x9958 = x4[x9957];
      bool x9959 = x9958 != '|';
      bool x9964 = x9959;
      if (x9959) {
        long x9960 = x9893;
        char x9961 = x4[x9960];
        bool x9962 = x9961 != '\n';
        x9964 = x9962;
      }
      bool x9965 = x9964;
      if (!x9965) break;
      x9893 = x9893 + 1;
    }
    x9893 = x9893 + 1;
    int x9980 = 0;
    for (;;) {
      long x9981 = x9893;
      char x9982 = x4[x9981];
      bool x9983 = x9982 != '|';
      bool x9988 = x9983;
      if (x9983) {
        long x9984 = x9893;
        char x9985 = x4[x9984];
        bool x9986 = x9985 != '\n';
        x9988 = x9986;
      }
      bool x9989 = x9988;
      if (!x9989) break;
      int x9991 = x9980;
      long x9993 = x9893;
      int x9992 = x9991 * 10;
      char x9994 = x4[x9993];
      char x9995 = x9994 - '0';
      int x9996 = x9992 + x9995;
      x9980 = x9996;
      x9893 = x9893 + 1;
    }
    x9893 = x9893 + 1;
    int x10002 = x9980;
    for (;;) {
      long x10005 = x9893;
      char x10006 = x4[x10005];
      bool x10007 = x10006 != '|';
      bool x10012 = x10007;
      if (x10007) {
        long x10008 = x9893;
        char x10009 = x4[x10008];
        bool x10010 = x10009 != '\n';
        x10012 = x10010;
      }
      bool x10013 = x10012;
      if (!x10013) break;
      x9893 = x9893 + 1;
    }
    x9893 = x9893 + 1;
    for (;;) {
      long x10030 = x9893;
      char x10031 = x4[x10030];
      bool x10032 = x10031 != '.';
      bool x10037 = x10032;
      if (x10032) {
        long x10033 = x9893;
        char x10034 = x4[x10033];
        bool x10035 = x10034 != '|';
        x10037 = x10035;
      }
      bool x10038 = x10037;
      bool x10043 = x10038;
      if (x10038) {
        long x10039 = x9893;
        char x10040 = x4[x10039];
        bool x10041 = x10040 != '\n';
        x10043 = x10041;
      }
      bool x10044 = x10043;
      if (!x10044) break;
      x9893 = x9893 + 1;
    }
    long x10056 = x9893;
    char x10057 = x4[x10056];
    bool x10058 = x10057 == '.';
    if (x10058) {
      x9893 = x9893 + 1;
      for (;;) {
        long x10060 = x9893;
        char x10061 = x4[x10060];
        bool x10062 = x10061 != '|';
        bool x10067 = x10062;
        if (x10062) {
          long x10063 = x9893;
          char x10064 = x4[x10063];
          bool x10065 = x10064 != '\n';
          x10067 = x10065;
        }
        bool x10068 = x10067;
        if (!x10068) break;
        x9893 = x9893 + 1;
      }
    } else {
    }
    x9893 = x9893 + 1;
    int x10093 = 0;
    int x10094 = 1;
    for (;;) {
      long x10095 = x9893;
      char x10096 = x4[x10095];
      bool x10097 = x10096 != '.';
      bool x10102 = x10097;
      if (x10097) {
        long x10098 = x9893;
        char x10099 = x4[x10098];
        bool x10100 = x10099 != '|';
        x10102 = x10100;
      }
      bool x10103 = x10102;
      bool x10108 = x10103;
      if (x10103) {
        long x10104 = x9893;
        char x10105 = x4[x10104];
        bool x10106 = x10105 != '\n';
        x10108 = x10106;
      }
      bool x10109 = x10108;
      if (!x10109) break;
      int x10111 = x10093;
      long x10113 = x9893;
      int x10112 = x10111 * 10;
      char x10114 = x4[x10113];
      char x10115 = x10114 - '0';
      int x10116 = x10112 + x10115;
      x10093 = x10116;
      x9893 = x9893 + 1;
    }
    long x10121 = x9893;
    char x10122 = x4[x10121];
    bool x10123 = x10122 == '.';
    if (x10123) {
      x9893 = x9893 + 1;
      for (;;) {
        long x10125 = x9893;
        char x10126 = x4[x10125];
        bool x10127 = x10126 != '|';
        bool x10132 = x10127;
        if (x10127) {
          long x10128 = x9893;
          char x10129 = x4[x10128];
          bool x10130 = x10129 != '\n';
          x10132 = x10130;
        }
        bool x10133 = x10132;
        if (!x10133) break;
        int x10135 = x10093;
        long x10137 = x9893;
        int x10136 = x10135 * 10;
        char x10138 = x4[x10137];
        char x10139 = x10138 - '0';
        int x10140 = x10136 + x10139;
        x10093 = x10140;
        int x10142 = x10094;
        int x10143 = x10142 * 10;
        x10094 = x10143;
        x9893 = x9893 + 1;
      }
    } else {
    }
    x9893 = x9893 + 1;
    int x10152 = x10093;
    int x10154 = x10094;
    int x10158 = 0;
    int x10159 = 1;
    for (;;) {
      long x10160 = x9893;
      char x10161 = x4[x10160];
      bool x10162 = x10161 != '.';
      bool x10167 = x10162;
      if (x10162) {
        long x10163 = x9893;
        char x10164 = x4[x10163];
        bool x10165 = x10164 != '|';
        x10167 = x10165;
      }
      bool x10168 = x10167;
      bool x10173 = x10168;
      if (x10168) {
        long x10169 = x9893;
        char x10170 = x4[x10169];
        bool x10171 = x10170 != '\n';
        x10173 = x10171;
      }
      bool x10174 = x10173;
      if (!x10174) break;
      int x10176 = x10158;
      long x10178 = x9893;
      int x10177 = x10176 * 10;
      char x10179 = x4[x10178];
      char x10180 = x10179 - '0';
      int x10181 = x10177 + x10180;
      x10158 = x10181;
      x9893 = x9893 + 1;
    }
    long x10186 = x9893;
    char x10187 = x4[x10186];
    bool x10188 = x10187 == '.';
    if (x10188) {
      x9893 = x9893 + 1;
      for (;;) {
        long x10190 = x9893;
        char x10191 = x4[x10190];
        bool x10192 = x10191 != '|';
        bool x10197 = x10192;
        if (x10192) {
          long x10193 = x9893;
          char x10194 = x4[x10193];
          bool x10195 = x10194 != '\n';
          x10197 = x10195;
        }
        bool x10198 = x10197;
        if (!x10198) break;
        int x10200 = x10158;
        long x10202 = x9893;
        int x10201 = x10200 * 10;
        char x10203 = x4[x10202];
        char x10204 = x10203 - '0';
        int x10205 = x10201 + x10204;
        x10158 = x10205;
        int x10207 = x10159;
        int x10208 = x10207 * 10;
        x10159 = x10208;
        x9893 = x9893 + 1;
      }
    } else {
    }
    x9893 = x9893 + 1;
    int x10217 = x10158;
    int x10219 = x10159;
    for (;;) {
      long x10225 = x9893;
      char x10226 = x4[x10225];
      bool x10227 = x10226 != '.';
      bool x10232 = x10227;
      if (x10227) {
        long x10228 = x9893;
        char x10229 = x4[x10228];
        bool x10230 = x10229 != '|';
        x10232 = x10230;
      }
      bool x10233 = x10232;
      bool x10238 = x10233;
      if (x10233) {
        long x10234 = x9893;
        char x10235 = x4[x10234];
        bool x10236 = x10235 != '\n';
        x10238 = x10236;
      }
      bool x10239 = x10238;
      if (!x10239) break;
      x9893 = x9893 + 1;
    }
    long x10251 = x9893;
    char x10252 = x4[x10251];
    bool x10253 = x10252 == '.';
    if (x10253) {
      x9893 = x9893 + 1;
      for (;;) {
        long x10255 = x9893;
        char x10256 = x4[x10255];
        bool x10257 = x10256 != '|';
        bool x10262 = x10257;
        if (x10257) {
          long x10258 = x9893;
          char x10259 = x4[x10258];
          bool x10260 = x10259 != '\n';
          x10262 = x10260;
        }
        bool x10263 = x10262;
        if (!x10263) break;
        x9893 = x9893 + 1;
      }
    } else {
    }
    x9893 = x9893 + 1;
    x9893 = x9893 + 2;
    x9893 = x9893 + 2;
    int x10294 = 0;
    for (;;) {
      long x10295 = x9893;
      char x10296 = x4[x10295];
      bool x10297 = x10296 != '-';
      bool x10302 = x10297;
      if (x10297) {
        long x10298 = x9893;
        char x10299 = x4[x10298];
        bool x10300 = x10299 != '\n';
        x10302 = x10300;
      }
      bool x10303 = x10302;
      if (!x10303) break;
      int x10305 = x10294;
      long x10307 = x9893;
      int x10306 = x10305 * 10;
      char x10308 = x4[x10307];
      char x10309 = x10308 - '0';
      int x10310 = x10306 + x10309;
      x10294 = x10310;
      x9893 = x9893 + 1;
    }
    x9893 = x9893 + 1;
    int x10316 = x10294;
    int x10318 = 0;
    for (;;) {
      long x10319 = x9893;
      char x10320 = x4[x10319];
      bool x10321 = x10320 != '-';
      bool x10326 = x10321;
      if (x10321) {
        long x10322 = x9893;
        char x10323 = x4[x10322];
        bool x10324 = x10323 != '\n';
        x10326 = x10324;
      }
      bool x10327 = x10326;
      if (!x10327) break;
      int x10329 = x10318;
      long x10331 = x9893;
      int x10330 = x10329 * 10;
      char x10332 = x4[x10331];
      char x10333 = x10332 - '0';
      int x10334 = x10330 + x10333;
      x10318 = x10334;
      x9893 = x9893 + 1;
    }
    x9893 = x9893 + 1;
    int x10340 = x10318;
    int x10342 = 0;
    for (;;) {
      long x10343 = x9893;
      char x10344 = x4[x10343];
      bool x10345 = x10344 != '|';
      bool x10350 = x10345;
      if (x10345) {
        long x10346 = x9893;
        char x10347 = x4[x10346];
        bool x10348 = x10347 != '\n';
        x10350 = x10348;
      }
      bool x10351 = x10350;
      if (!x10351) break;
      int x10353 = x10342;
      long x10355 = x9893;
      int x10354 = x10353 * 10;
      char x10356 = x4[x10355];
      char x10357 = x10356 - '0';
      int x10358 = x10354 + x10357;
      x10342 = x10358;
      x9893 = x9893 + 1;
    }
    x9893 = x9893 + 1;
    int x10364 = x10342;
    for (;;) {
      long x10371 = x9893;
      char x10372 = x4[x10371];
      bool x10373 = x10372 != '-';
      bool x10378 = x10373;
      if (x10373) {
        long x10374 = x9893;
        char x10375 = x4[x10374];
        bool x10376 = x10375 != '\n';
        x10378 = x10376;
      }
      bool x10379 = x10378;
      if (!x10379) break;
      x9893 = x9893 + 1;
    }
    x9893 = x9893 + 1;
    for (;;) {
      long x10395 = x9893;
      char x10396 = x4[x10395];
      bool x10397 = x10396 != '-';
      bool x10402 = x10397;
      if (x10397) {
        long x10398 = x9893;
        char x10399 = x4[x10398];
        bool x10400 = x10399 != '\n';
        x10402 = x10400;
      }
      bool x10403 = x10402;
      if (!x10403) break;
      x9893 = x9893 + 1;
    }
    x9893 = x9893 + 1;
    for (;;) {
      long x10419 = x9893;
      char x10420 = x4[x10419];
      bool x10421 = x10420 != '|';
      bool x10426 = x10421;
      if (x10421) {
        long x10422 = x9893;
        char x10423 = x4[x10422];
        bool x10424 = x10423 != '\n';
        x10426 = x10424;
      }
      bool x10427 = x10426;
      if (!x10427) break;
      x9893 = x9893 + 1;
    }
    x9893 = x9893 + 1;
    for (;;) {
      long x10447 = x9893;
      char x10448 = x4[x10447];
      bool x10449 = x10448 != '-';
      bool x10454 = x10449;
      if (x10449) {
        long x10450 = x9893;
        char x10451 = x4[x10450];
        bool x10452 = x10451 != '\n';
        x10454 = x10452;
      }
      bool x10455 = x10454;
      if (!x10455) break;
      x9893 = x9893 + 1;
    }
    x9893 = x9893 + 1;
    for (;;) {
      long x10471 = x9893;
      char x10472 = x4[x10471];
      bool x10473 = x10472 != '-';
      bool x10478 = x10473;
      if (x10473) {
        long x10474 = x9893;
        char x10475 = x4[x10474];
        bool x10476 = x10475 != '\n';
        x10478 = x10476;
      }
      bool x10479 = x10478;
      if (!x10479) break;
      x9893 = x9893 + 1;
    }
    x9893 = x9893 + 1;
    for (;;) {
      long x10495 = x9893;
      char x10496 = x4[x10495];
      bool x10497 = x10496 != '|';
      bool x10502 = x10497;
      if (x10497) {
        long x10498 = x9893;
        char x10499 = x4[x10498];
        bool x10500 = x10499 != '\n';
        x10502 = x10500;
      }
      bool x10503 = x10502;
      if (!x10503) break;
      x9893 = x9893 + 1;
    }
    x9893 = x9893 + 1;
    for (;;) {
      long x10522 = x9893;
      char x10523 = x4[x10522];
      bool x10524 = x10523 != '|';
      bool x10529 = x10524;
      if (x10524) {
        long x10525 = x9893;
        char x10526 = x4[x10525];
        bool x10527 = x10526 != '\n';
        x10529 = x10527;
      }
      bool x10530 = x10529;
      if (!x10530) break;
      x9893 = x9893 + 1;
    }
    x9893 = x9893 + 1;
    for (;;) {
      long x10540 = x9893;
      char x10541 = x4[x10540];
      bool x10542 = x10541 != '|';
      bool x10547 = x10542;
      if (x10542) {
        long x10543 = x9893;
        char x10544 = x4[x10543];
        bool x10545 = x10544 != '\n';
        x10547 = x10545;
      }
      bool x10548 = x10547;
      if (!x10548) break;
      x9893 = x9893 + 1;
    }
    x9893 = x9893 + 1;
    for (;;) {
      long x10558 = x9893;
      char x10559 = x4[x10558];
      bool x10560 = x10559 != '|';
      bool x10565 = x10560;
      if (x10560) {
        long x10561 = x9893;
        char x10562 = x4[x10561];
        bool x10563 = x10562 != '\n';
        x10565 = x10563;
      }
      bool x10566 = x10565;
      if (!x10566) break;
      x9893 = x9893 + 1;
    }
    x9893 = x9893 + 1;
    long x10576 = x9895;
    long x10577 = x9894;
    bool x10578 = x10576 == x10577;
    if (x10578) {
      long x10579 = x10577 * 4L;
      x9894 = x10579;
      printf("buffer.resize %d\n",x10579);
      int* x10582 = x9897;
      int* x10583 = (int*)realloc(x10582,x10579 * sizeof(int));
      x9897 = x10583;
      int* x10588 = x9901;
      int* x10589 = (int*)realloc(x10588,x10579 * sizeof(int));
      x9901 = x10589;
      double* x10597 = x9907;
      double* x10598 = (double*)realloc(x10597,x10579 * sizeof(double));
      x9907 = x10598;
      double* x10600 = x9909;
      double* x10601 = (double*)realloc(x10600,x10579 * sizeof(double));
      x9909 = x10601;
      long* x10612 = x9917;
      long* x10613 = (long*)realloc(x10612,x10579 * sizeof(long));
      x9917 = x10613;
    } else {
    }
    int* x10632 = x9897;
    x10632[x10576] = x9954;
    int* x10636 = x9901;
    x10636[x10576] = x10002;
    double* x10642 = x9907;
    double x10153 = (double)x10152;
    double x10155 = (double)x10154;
    double x10156 = x10153 / x10155;
    x10642[x10576] = x10156;
    double* x10644 = x9909;
    double x10218 = (double)x10217;
    double x10220 = (double)x10219;
    double x10221 = x10218 / x10220;
    x10644[x10576] = x10221;
    long* x10652 = x9917;
    long x10365 = x10316 * 10000L;
    long x10366 = x10340 * 100L;
    long x10367 = x10365 + x10366;
    long x10368 = x10367 + x10364;
    x10652[x10576] = x10368;
    x9895 = x9895 + 1;
  }
  long x10667 = 0L;
  long x10668 = x6;
  long x10669 = 0L;
  int* x10670 = (int*)malloc(x6 * sizeof(int));
  int* x10671 = x10670;
  int* x10676 = (int*)malloc(x6 * sizeof(int));
  int* x10677 = x10676;
  int x3725 = open("../databases/sf2/customer.tbl",0);
  long x3726 = fsize(x3725);
  char* x3727 = mmap(0, x3726, PROT_READ, MAP_FILE | MAP_SHARED, x3725, 0);
  for (;;) {
    long x10686 = x10667;
    bool x10687 = x10686 < x3726;
    if (!x10687) break;
    int x10690 = 0;
    for (;;) {
      long x10691 = x10667;
      char x10692 = x3727[x10691];
      bool x10693 = x10692 != '|';
      bool x10698 = x10693;
      if (x10693) {
        long x10694 = x10667;
        char x10695 = x3727[x10694];
        bool x10696 = x10695 != '\n';
        x10698 = x10696;
      }
      bool x10699 = x10698;
      if (!x10699) break;
      int x10701 = x10690;
      long x10703 = x10667;
      int x10702 = x10701 * 10;
      char x10704 = x3727[x10703];
      char x10705 = x10704 - '0';
      int x10706 = x10702 + x10705;
      x10690 = x10706;
      x10667 = x10667 + 1;
    }
    x10667 = x10667 + 1;
    int x10712 = x10690;
    for (;;) {
      long x10714 = x10667;
      char x10715 = x3727[x10714];
      bool x10716 = x10715 != '|';
      bool x10721 = x10716;
      if (x10716) {
        long x10717 = x10667;
        char x10718 = x3727[x10717];
        bool x10719 = x10718 != '\n';
        x10721 = x10719;
      }
      bool x10722 = x10721;
      if (!x10722) break;
      x10667 = x10667 + 1;
    }
    x10667 = x10667 + 1;
    for (;;) {
      long x10732 = x10667;
      char x10733 = x3727[x10732];
      bool x10734 = x10733 != '|';
      bool x10739 = x10734;
      if (x10734) {
        long x10735 = x10667;
        char x10736 = x3727[x10735];
        bool x10737 = x10736 != '\n';
        x10739 = x10737;
      }
      bool x10740 = x10739;
      if (!x10740) break;
      x10667 = x10667 + 1;
    }
    x10667 = x10667 + 1;
    int x10750 = 0;
    for (;;) {
      long x10751 = x10667;
      char x10752 = x3727[x10751];
      bool x10753 = x10752 != '|';
      bool x10758 = x10753;
      if (x10753) {
        long x10754 = x10667;
        char x10755 = x3727[x10754];
        bool x10756 = x10755 != '\n';
        x10758 = x10756;
      }
      bool x10759 = x10758;
      if (!x10759) break;
      int x10761 = x10750;
      long x10763 = x10667;
      int x10762 = x10761 * 10;
      char x10764 = x3727[x10763];
      char x10765 = x10764 - '0';
      int x10766 = x10762 + x10765;
      x10750 = x10766;
      x10667 = x10667 + 1;
    }
    x10667 = x10667 + 1;
    int x10772 = x10750;
    for (;;) {
      long x10774 = x10667;
      char x10775 = x3727[x10774];
      bool x10776 = x10775 != '|';
      bool x10781 = x10776;
      if (x10776) {
        long x10777 = x10667;
        char x10778 = x3727[x10777];
        bool x10779 = x10778 != '\n';
        x10781 = x10779;
      }
      bool x10782 = x10781;
      if (!x10782) break;
      x10667 = x10667 + 1;
    }
    x10667 = x10667 + 1;
    for (;;) {
      long x10794 = x10667;
      char x10795 = x3727[x10794];
      bool x10796 = x10795 != '.';
      bool x10801 = x10796;
      if (x10796) {
        long x10797 = x10667;
        char x10798 = x3727[x10797];
        bool x10799 = x10798 != '|';
        x10801 = x10799;
      }
      bool x10802 = x10801;
      bool x10807 = x10802;
      if (x10802) {
        long x10803 = x10667;
        char x10804 = x3727[x10803];
        bool x10805 = x10804 != '\n';
        x10807 = x10805;
      }
      bool x10808 = x10807;
      if (!x10808) break;
      x10667 = x10667 + 1;
    }
    long x10820 = x10667;
    char x10821 = x3727[x10820];
    bool x10822 = x10821 == '.';
    if (x10822) {
      x10667 = x10667 + 1;
      for (;;) {
        long x10824 = x10667;
        char x10825 = x3727[x10824];
        bool x10826 = x10825 != '|';
        bool x10831 = x10826;
        if (x10826) {
          long x10827 = x10667;
          char x10828 = x3727[x10827];
          bool x10829 = x10828 != '\n';
          x10831 = x10829;
        }
        bool x10832 = x10831;
        if (!x10832) break;
        x10667 = x10667 + 1;
      }
    } else {
    }
    x10667 = x10667 + 1;
    for (;;) {
      long x10857 = x10667;
      char x10858 = x3727[x10857];
      bool x10859 = x10858 != '|';
      bool x10864 = x10859;
      if (x10859) {
        long x10860 = x10667;
        char x10861 = x3727[x10860];
        bool x10862 = x10861 != '\n';
        x10864 = x10862;
      }
      bool x10865 = x10864;
      if (!x10865) break;
      x10667 = x10667 + 1;
    }
    x10667 = x10667 + 1;
    for (;;) {
      long x10875 = x10667;
      char x10876 = x3727[x10875];
      bool x10877 = x10876 != '|';
      bool x10882 = x10877;
      if (x10877) {
        long x10878 = x10667;
        char x10879 = x3727[x10878];
        bool x10880 = x10879 != '\n';
        x10882 = x10880;
      }
      bool x10883 = x10882;
      if (!x10883) break;
      x10667 = x10667 + 1;
    }
    x10667 = x10667 + 1;
    long x10893 = x10669;
    long x10894 = x10668;
    bool x10895 = x10893 == x10894;
    if (x10895) {
      long x10896 = x10894 * 4L;
      x10668 = x10896;
      printf("buffer.resize %d\n",x10896);
      int* x10899 = x10671;
      int* x10900 = (int*)realloc(x10899,x10896 * sizeof(int));
      x10671 = x10900;
      int* x10908 = x10677;
      int* x10909 = (int*)realloc(x10908,x10896 * sizeof(int));
      x10677 = x10909;
    } else {
    }
    int* x10925 = x10671;
    x10925[x10893] = x10712;
    int* x10931 = x10677;
    x10931[x10893] = x10772;
    x10669 = x10669 + 1;
  }
  long x10944 = 0L;
  long x10945 = x6;
  long x10946 = 0L;
  int* x10947 = (int*)malloc(x6 * sizeof(int));
  int* x10948 = x10947;
  int* x10953 = (int*)malloc(x6 * sizeof(int));
  int* x10954 = x10953;
  int x1750 = open("../databases/sf2/supplier.tbl",0);
  long x1751 = fsize(x1750);
  char* x1752 = mmap(0, x1751, PROT_READ, MAP_FILE | MAP_SHARED, x1750, 0);
  for (;;) {
    long x10961 = x10944;
    bool x10962 = x10961 < x1751;
    if (!x10962) break;
    int x10965 = 0;
    for (;;) {
      long x10966 = x10944;
      char x10967 = x1752[x10966];
      bool x10968 = x10967 != '|';
      bool x10973 = x10968;
      if (x10968) {
        long x10969 = x10944;
        char x10970 = x1752[x10969];
        bool x10971 = x10970 != '\n';
        x10973 = x10971;
      }
      bool x10974 = x10973;
      if (!x10974) break;
      int x10976 = x10965;
      long x10978 = x10944;
      int x10977 = x10976 * 10;
      char x10979 = x1752[x10978];
      char x10980 = x10979 - '0';
      int x10981 = x10977 + x10980;
      x10965 = x10981;
      x10944 = x10944 + 1;
    }
    x10944 = x10944 + 1;
    int x10987 = x10965;
    for (;;) {
      long x10989 = x10944;
      char x10990 = x1752[x10989];
      bool x10991 = x10990 != '|';
      bool x10996 = x10991;
      if (x10991) {
        long x10992 = x10944;
        char x10993 = x1752[x10992];
        bool x10994 = x10993 != '\n';
        x10996 = x10994;
      }
      bool x10997 = x10996;
      if (!x10997) break;
      x10944 = x10944 + 1;
    }
    x10944 = x10944 + 1;
    for (;;) {
      long x11007 = x10944;
      char x11008 = x1752[x11007];
      bool x11009 = x11008 != '|';
      bool x11014 = x11009;
      if (x11009) {
        long x11010 = x10944;
        char x11011 = x1752[x11010];
        bool x11012 = x11011 != '\n';
        x11014 = x11012;
      }
      bool x11015 = x11014;
      if (!x11015) break;
      x10944 = x10944 + 1;
    }
    x10944 = x10944 + 1;
    int x11025 = 0;
    for (;;) {
      long x11026 = x10944;
      char x11027 = x1752[x11026];
      bool x11028 = x11027 != '|';
      bool x11033 = x11028;
      if (x11028) {
        long x11029 = x10944;
        char x11030 = x1752[x11029];
        bool x11031 = x11030 != '\n';
        x11033 = x11031;
      }
      bool x11034 = x11033;
      if (!x11034) break;
      int x11036 = x11025;
      long x11038 = x10944;
      int x11037 = x11036 * 10;
      char x11039 = x1752[x11038];
      char x11040 = x11039 - '0';
      int x11041 = x11037 + x11040;
      x11025 = x11041;
      x10944 = x10944 + 1;
    }
    x10944 = x10944 + 1;
    int x11047 = x11025;
    for (;;) {
      long x11049 = x10944;
      char x11050 = x1752[x11049];
      bool x11051 = x11050 != '|';
      bool x11056 = x11051;
      if (x11051) {
        long x11052 = x10944;
        char x11053 = x1752[x11052];
        bool x11054 = x11053 != '\n';
        x11056 = x11054;
      }
      bool x11057 = x11056;
      if (!x11057) break;
      x10944 = x10944 + 1;
    }
    x10944 = x10944 + 1;
    for (;;) {
      long x11069 = x10944;
      char x11070 = x1752[x11069];
      bool x11071 = x11070 != '.';
      bool x11076 = x11071;
      if (x11071) {
        long x11072 = x10944;
        char x11073 = x1752[x11072];
        bool x11074 = x11073 != '|';
        x11076 = x11074;
      }
      bool x11077 = x11076;
      bool x11082 = x11077;
      if (x11077) {
        long x11078 = x10944;
        char x11079 = x1752[x11078];
        bool x11080 = x11079 != '\n';
        x11082 = x11080;
      }
      bool x11083 = x11082;
      if (!x11083) break;
      x10944 = x10944 + 1;
    }
    long x11095 = x10944;
    char x11096 = x1752[x11095];
    bool x11097 = x11096 == '.';
    if (x11097) {
      x10944 = x10944 + 1;
      for (;;) {
        long x11099 = x10944;
        char x11100 = x1752[x11099];
        bool x11101 = x11100 != '|';
        bool x11106 = x11101;
        if (x11101) {
          long x11102 = x10944;
          char x11103 = x1752[x11102];
          bool x11104 = x11103 != '\n';
          x11106 = x11104;
        }
        bool x11107 = x11106;
        if (!x11107) break;
        x10944 = x10944 + 1;
      }
    } else {
    }
    x10944 = x10944 + 1;
    for (;;) {
      long x11132 = x10944;
      char x11133 = x1752[x11132];
      bool x11134 = x11133 != '|';
      bool x11139 = x11134;
      if (x11134) {
        long x11135 = x10944;
        char x11136 = x1752[x11135];
        bool x11137 = x11136 != '\n';
        x11139 = x11137;
      }
      bool x11140 = x11139;
      if (!x11140) break;
      x10944 = x10944 + 1;
    }
    x10944 = x10944 + 1;
    long x11150 = x10946;
    long x11151 = x10945;
    bool x11152 = x11150 == x11151;
    if (x11152) {
      long x11153 = x11151 * 4L;
      x10945 = x11153;
      printf("buffer.resize %d\n",x11153);
      int* x11156 = x10948;
      int* x11157 = (int*)realloc(x11156,x11153 * sizeof(int));
      x10948 = x11157;
      int* x11165 = x10954;
      int* x11166 = (int*)realloc(x11165,x11153 * sizeof(int));
      x10954 = x11166;
    } else {
    }
    int* x11179 = x10948;
    x11179[x11150] = x10987;
    int* x11185 = x10954;
    x11185[x11150] = x11047;
    x10946 = x10946 + 1;
  }
  long x2011 = DEFAULT_JOIN_HASH_SIZE;
  long x787 = DEFAULT_AGG_HASH_SIZE ;
  long x2034 = x2011 - 1L;
  long x802 = x787 - 1L;
  bool x975 = true == false;
  int x11196;
  for(x11196=0; x11196 < 5; x11196++) {
    bool x11197 = false;
    long x11198 = 0L;
    bool x11200 = false;
    long x11201 = 0L;
    int x11205 = 0;
    char* x11206 = "";
    bool x11211 = false;
    long x11212 = 0L;
    int* x11214 = (int*)malloc(x2011 * sizeof(int));
    int* x11215 = x11214;
    char** x11216 = (char**)malloc(x2011 * sizeof(char*));
    char** x11217 = x11216;
    int* x11222 = (int*)malloc(x2011 * sizeof(int));
    int* x11223 = x11222;
    char** x11224 = (char**)malloc(x2011 * sizeof(char*));
    char** x11225 = x11224;
    long x11230 = 0L;
    long* x11231 = (long*)malloc(x2011 * sizeof(long));
    long* x11232 = (long*)malloc(x2011 * sizeof(long));
    long x11233;
    for(x11233=0L; x11233 < x2011; x11233++) {
      x11231[x11233] = -1L;
    }
    bool x11238 = false;
    long x11239 = 0L;
    char** x11244 = (char**)malloc(x2011 * sizeof(char*));
    char** x11245 = x11244;
    int* x11250 = (int*)malloc(x2011 * sizeof(int));
    int* x11251 = x11250;
    char** x11252 = (char**)malloc(x2011 * sizeof(char*));
    char** x11253 = x11252;
    int* x11258 = (int*)malloc(x2011 * sizeof(int));
    int* x11259 = x11258;
    long x11272 = 0L;
    long* x11273 = (long*)malloc(x2011 * sizeof(long));
    long* x11274 = (long*)malloc(x2011 * sizeof(long));
    long x11275;
    for(x11275=0L; x11275 < x2011; x11275++) {
      x11273[x11275] = -1L;
    }
    bool x11280 = false;
    long x11281 = 0L;
    char** x11285 = (char**)malloc(x2011 * sizeof(char*));
    char** x11286 = x11285;
    int* x11291 = (int*)malloc(x2011 * sizeof(int));
    int* x11292 = x11291;
    char** x11293 = (char**)malloc(x2011 * sizeof(char*));
    char** x11294 = x11293;
    int* x11313 = (int*)malloc(x2011 * sizeof(int));
    int* x11314 = x11313;
    double* x11323 = (double*)malloc(x2011 * sizeof(double));
    double* x11324 = x11323;
    double* x11325 = (double*)malloc(x2011 * sizeof(double));
    double* x11326 = x11325;
    long* x11333 = (long*)malloc(x2011 * sizeof(long));
    long* x11334 = x11333;
    long x11345 = 0L;
    long* x11346 = (long*)malloc(x2011 * sizeof(long));
    long* x11347 = (long*)malloc(x2011 * sizeof(long));
    long x11348;
    for(x11348=0L; x11348 < x2011; x11348++) {
      x11346[x11348] = -1L;
    }
    bool x11353 = false;
    long x11354 = 0L;
    int* x11356 = (int*)malloc(x2011 * sizeof(int));
    int* x11357 = x11356;
    int* x11362 = (int*)malloc(x2011 * sizeof(int));
    int* x11363 = x11362;
    long x11372 = 0L;
    long* x11373 = (long*)malloc(x2011 * sizeof(long));
    long* x11374 = (long*)malloc(x2011 * sizeof(long));
    long x11375;
    for(x11375=0L; x11375 < x2011; x11375++) {
      x11373[x11375] = -1L;
    }
    struct Anon1587544425* x11381 = (struct Anon1587544425*)malloc(x787 * sizeof(struct Anon1587544425));
    struct Anon1587544425* x11382 = x11381;
    long x11383 = 0L;
    long* x11384 = (long*)malloc(x787 * sizeof(long));
    long x11385;
    for(x11385=0L; x11385 < x787; x11385++) {
      struct Anon1587544425* x11386 = x11382;
      struct Anon1587544425 x11387 = x11386[x11385];
      struct Anon726278688 x11388 = x11387.key;;
      struct Anon2052879266 x11389 = x11387.aggs;;
      struct Anon1587544425 x11390;
      x11390.exists = false;
      x11390.key = x11388;
      x11390.aggs = x11389;
      x11386[x11385] = x11390;
    }
    long x11395 = 0L;
    struct timeval x12098, x12099, x12100;
    gettimeofday(&x12098, NULL);
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x11397 = x11353;
      bool x11398 = !x11397;
      bool x11403 = x11398;
      if (x11398) {
        long x11399 = x11354;
        long x11400 = x10669;
        bool x11401 = x11399 < x11400;
        x11403 = x11401;
      }
      bool x11404 = x11403;
      if (!x11404) break;
      long x11406 = x11354;
      int* x11407 = x10671;
      int x11408 = x11407[x11406];
      int* x11413 = x10677;
      int x11414 = x11413[x11406];
      x11354 = x11354 + 1;
      long x11425 = x11372;
      int* x11426 = x11357;
      x11426[x11425] = x11408;
      int* x11432 = x11363;
      x11432[x11425] = x11414;
      x11372 = x11372 + 1L;
      long x11443 = x11408 & x2034;
      long x11444 = x11373[x11443];
      x11373[x11443] = x11425;
      x11374[x11425] = x11444;
    }
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x11450 = x11197;
      bool x11451 = !x11450;
      bool x11456 = x11451;
      if (x11451) {
        long x11452 = x11198;
        long x11453 = x9414;
        bool x11454 = x11452 < x11453;
        x11456 = x11454;
      }
      bool x11457 = x11456;
      if (!x11457) break;
      long x11459 = x11198;
      int* x11460 = x9416;
      int x11461 = x11460[x11459];
      char** x11462 = x9418;
      char* x11463 = x11462[x11459];
      x11198 = x11198 + 1;
      x11205 = x11461;
      x11206 = x11463;
      printf("%s\n","begin scan NATION");
      for (;;) {
        bool x11476 = x11200;
        bool x11477 = !x11476;
        bool x11482 = x11477;
        if (x11477) {
          long x11478 = x11201;
          long x11479 = x9414;
          bool x11480 = x11478 < x11479;
          x11482 = x11480;
        }
        bool x11483 = x11482;
        if (!x11483) break;
        long x11485 = x11201;
        int* x11486 = x9416;
        int x11487 = x11486[x11485];
        char** x11488 = x9418;
        char* x11489 = x11488[x11485];
        x11201 = x11201 + 1;
        int x11497 = x11205;
        char* x11498 = x11206;
        bool x11502 = strcmp(x11498,"UNITED STATES") == 0;;
        bool x11504 = x11502;
        if (x11502) {
          bool x11503 = strcmp(x11489,"INDONESIA") == 0;;
          x11504 = x11503;
        }
        bool x11505 = x11504;
        bool x11510 = x11505;
        if (x11505 == false) {
          bool x11506 = strcmp(x11498,"INDONESIA") == 0;;
          bool x11508 = x11506;
          if (x11506) {
            bool x11507 = strcmp(x11489,"UNITED STATES") == 0;;
            x11508 = x11507;
          }
          bool x11509 = x11508;
          x11510 = x11509;
        }
        bool x11511 = x11510;
        if (x11511) {
          long x11515 = x11230;
          int* x11516 = x11215;
          x11516[x11515] = x11497;
          char** x11518 = x11217;
          x11518[x11515] = x11498;
          int* x11524 = x11223;
          x11524[x11515] = x11487;
          char** x11526 = x11225;
          x11526[x11515] = x11489;
          x11230 = x11230 + 1L;
          long x11533 = x11497 & x2034;
          long x11534 = x11231[x11533];
          x11231[x11533] = x11515;
          x11232[x11515] = x11534;
        } else {
        }
      }
      x11201 = 0L;
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x11545 = x11211;
      bool x11546 = !x11545;
      bool x11551 = x11546;
      if (x11546) {
        long x11547 = x11212;
        long x11548 = x10946;
        bool x11549 = x11547 < x11548;
        x11551 = x11549;
      }
      bool x11552 = x11551;
      if (!x11552) break;
      long x11554 = x11212;
      int* x11555 = x10948;
      int x11556 = x11555[x11554];
      int* x11561 = x10954;
      int x11562 = x11561[x11554];
      x11212 = x11212 + 1;
      long x11571 = x11562 & x2034;
      long x11572 = x11231[x11571];
      long x11573 = x11572;
      long x11633 = x11556 & x2034;
      for (;;) {
        long x11574 = x11573;
        bool x11575 = x11574 != -1;
        if (!x11575) break;
        long x11577 = x11573;
        int* x11578 = x11215;
        int x11579 = x11578[x11577];
        char** x11580 = x11217;
        char* x11581 = x11580[x11577];
        int* x11586 = x11223;
        int x11587 = x11586[x11577];
        char** x11588 = x11225;
        char* x11589 = x11588[x11577];
        long x11595 = x11232[x11577];
        x11573 = x11595;
        bool x11597 = x11579 == x11562;
        if (x11597) {
          long x11601 = x11272;
          char** x11604 = x11245;
          x11604[x11601] = x11581;
          int* x11610 = x11251;
          x11610[x11601] = x11587;
          char** x11612 = x11253;
          x11612[x11601] = x11589;
          int* x11618 = x11259;
          x11618[x11601] = x11556;
          x11272 = x11272 + 1L;
          long x11634 = x11273[x11633];
          x11273[x11633] = x11601;
          x11274[x11601] = x11634;
        } else {
        }
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x11644 = x11238;
      bool x11645 = !x11644;
      bool x11650 = x11645;
      if (x11645) {
        long x11646 = x11239;
        long x11647 = x9895;
        bool x11648 = x11646 < x11647;
        x11650 = x11648;
      }
      bool x11651 = x11650;
      if (!x11651) break;
      long x11653 = x11239;
      int* x11654 = x9897;
      int x11655 = x11654[x11653];
      int* x11658 = x9901;
      int x11659 = x11658[x11653];
      double* x11664 = x9907;
      double x11665 = x11664[x11653];
      double* x11666 = x9909;
      double x11667 = x11666[x11653];
      long* x11674 = x9917;
      long x11675 = x11674[x11653];
      x11239 = x11239 + 1;
      bool x11688 = x11675 >= 19950101L;
      bool x11690 = x11688;
      if (x11688) {
        bool x11689 = x11675 <= 19961231L;
        x11690 = x11689;
      }
      bool x11691 = x11690;
      if (x11691) {
        long x11692 = x11659 & x2034;
        long x11693 = x11273[x11692];
        long x11694 = x11693;
        long x11800 = x11655 & x2034;
        for (;;) {
          long x11695 = x11694;
          bool x11696 = x11695 != -1;
          if (!x11696) break;
          long x11698 = x11694;
          char** x11701 = x11245;
          char* x11702 = x11701[x11698];
          int* x11707 = x11251;
          int x11708 = x11707[x11698];
          char** x11709 = x11253;
          char* x11710 = x11709[x11698];
          int* x11715 = x11259;
          int x11716 = x11715[x11698];
          long x11730 = x11274[x11698];
          x11694 = x11730;
          bool x11732 = x11716 == x11659;
          if (x11732) {
            long x11736 = x11345;
            char** x11739 = x11286;
            x11739[x11736] = x11702;
            int* x11745 = x11292;
            x11745[x11736] = x11708;
            char** x11747 = x11294;
            x11747[x11736] = x11710;
            int* x11767 = x11314;
            x11767[x11736] = x11655;
            double* x11777 = x11324;
            x11777[x11736] = x11665;
            double* x11779 = x11326;
            x11779[x11736] = x11667;
            long* x11787 = x11334;
            x11787[x11736] = x11675;
            x11345 = x11345 + 1L;
            long x11801 = x11346[x11800];
            x11346[x11800] = x11736;
            x11347[x11736] = x11801;
          } else {
          }
        }
      } else {
      }
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x11813 = x11280;
      bool x11814 = !x11813;
      bool x11819 = x11814;
      if (x11814) {
        long x11815 = x11281;
        long x11816 = x9544;
        bool x11817 = x11815 < x11816;
        x11819 = x11817;
      }
      bool x11820 = x11819;
      if (!x11820) break;
      long x11822 = x11281;
      int* x11823 = x9546;
      int x11824 = x11823[x11822];
      int* x11825 = x9548;
      int x11826 = x11825[x11822];
      x11281 = x11281 + 1;
      long x11843 = x11824 & x2034;
      long x11844 = x11346[x11843];
      long x11845 = x11844;
      long x11919 = x11826 & x2034;
      for (;;) {
        long x11846 = x11845;
        bool x11847 = x11846 != -1;
        if (!x11847) break;
        long x11849 = x11845;
        char** x11852 = x11286;
        char* x11853 = x11852[x11849];
        int* x11858 = x11292;
        int x11859 = x11858[x11849];
        char** x11860 = x11294;
        char* x11861 = x11860[x11849];
        int* x11880 = x11314;
        int x11881 = x11880[x11849];
        double* x11890 = x11324;
        double x11891 = x11890[x11849];
        double* x11892 = x11326;
        double x11893 = x11892[x11849];
        long* x11900 = x11334;
        long x11901 = x11900[x11849];
        long x11913 = x11347[x11849];
        x11845 = x11913;
        bool x11915 = x11881 == x11824;
        if (x11915) {
          long x11920 = x11373[x11919];
          long x11921 = x11920;
          char x11966 = x11853[0L];
          long x11967 = x11966 * 41L;
          char x11968 = x11853[1L];
          long x11969 = x11967 + x11968;
          long x11970 = x11969 * 41L;
          char x11971 = x11853[2L];
          long x11972 = x11970 + x11971;
          long x11973 = x11972 * 41L;
          char x11974 = x11853[3L];
          long x11975 = x11973 + x11974;
          long x11952 = x11901; // date
          long x11953 = x11952/10000;
          int x11954 = (int)x11953;
          char x11956 = x11861[0L];
          long x11957 = x11956 * 41L;
          char x11958 = x11861[1L];
          long x11959 = x11957 + x11958;
          long x11960 = x11959 * 41L;
          char x11961 = x11861[2L];
          long x11962 = x11960 + x11961;
          long x11963 = x11962 * 41L;
          char x11964 = x11861[3L];
          long x11965 = x11963 + x11964;
          long x11976 = x11965 * 41L;
          long x11977 = x11976 + x11954;
          long x11978 = x11977 * 41L;
          long x11979 = x11978 + x11975;
          long x11980 = x11979 & x802;
          double x12003 = 1.0 - x11893;
          double x12004 = x11891 * x12003;
          struct Anon726278688 x11955;
          x11955.SUPP_NATION = x11853;
          x11955.CUST_NATION = x11861;
          x11955.L_YEAR = x11954;
          struct Anon2052879266 x12046;
          x12046._0 = x12004;
          struct Anon1587544425 x12047;
          x12047.exists = true;
          x12047.key = x11955;
          x12047.aggs = x12046;
          for (;;) {
            long x11922 = x11921;
            bool x11923 = x11922 != -1;
            if (!x11923) break;
            long x11925 = x11921;
            int* x11926 = x11357;
            int x11927 = x11926[x11925];
            int* x11932 = x11363;
            int x11933 = x11932[x11925];
            long x11943 = x11374[x11925];
            x11921 = x11943;
            bool x11945 = x11927 == x11826;
            bool x11947 = x11945;
            if (x11945) {
              bool x11946 = x11933 == x11859;
              x11947 = x11946;
            }
            bool x11948 = x11947;
            if (x11948) {
              long x11981 = x11980;
              struct Anon1587544425* x11982 = x11382;
              struct Anon1587544425 x11983 = x11982[x11980];
              struct Anon1587544425 x11984 = x11983;
              bool x11985 = x11983.exists;;
              bool x11999 = x11985;
              if (x11985) {
                struct Anon1587544425 x11986 = x11984;
                struct Anon726278688 x11987 = x11986.key;;
                char* x11988 = x11987.SUPP_NATION;;
                bool x11989 = strcmp(x11988,x11853) == 0;;
                bool x11994 = x11989;
                if (x11989) {
                  char* x11990 = x11987.CUST_NATION;;
                  bool x11991 = strcmp(x11990,x11861) == 0;;
                  x11994 = x11991;
                }
                bool x11995 = x11994;
                bool x11996 = x11995;
                if (x11995) {
                  int x11992 = x11987.L_YEAR;;
                  bool x11993 = x11992 == x11954;
                  x11996 = x11993;
                }
                bool x11997 = x11996;
                x11999 = x11997;
              }
              bool x12000 = x11999;
              if (x12000) {
                struct Anon2052879266 x12001 = x11983.aggs;;
                struct Anon726278688 x12007 = x11983.key;;
                double x12002 = x12001._0;;
                double x12005 = x12002 + x12004;
                struct Anon2052879266 x12006;
                x12006._0 = x12005;
                struct Anon1587544425 x12008;
                x12008.exists = true;
                x12008.key = x12007;
                x12008.aggs = x12006;
                x11982[x11980] = x12008;
              } else {
                for (;;) {
                  struct Anon1587544425 x12011 = x11984;
                  bool x12012 = x12011.exists;;
                  bool x12056;
                  if (x12012) {
                    struct Anon726278688 x12013 = x12011.key;;
                    char* x12014 = x12013.SUPP_NATION;;
                    bool x12015 = strcmp(x12014,x11853) == 0;;
                    bool x12020 = x12015;
                    if (x12015) {
                      char* x12016 = x12013.CUST_NATION;;
                      bool x12017 = strcmp(x12016,x11861) == 0;;
                      x12020 = x12017;
                    }
                    bool x12021 = x12020;
                    bool x12022 = x12021;
                    if (x12021) {
                      int x12018 = x12013.L_YEAR;;
                      bool x12019 = x12018 == x11954;
                      x12022 = x12019;
                    }
                    bool x12023 = x12022;
                    bool x12043;
                    if (x12023) {
                      struct Anon2052879266 x12024 = x12011.aggs;;
                      long x12028 = x11981;
                      struct Anon1587544425* x12030 = x11382;
                      double x12025 = x12024._0;;
                      double x12026 = x12025 + x12004;
                      struct Anon2052879266 x12027;
                      x12027._0 = x12026;
                      struct Anon1587544425 x12029;
                      x12029.exists = true;
                      x12029.key = x12013;
                      x12029.aggs = x12027;
                      x12030[x12028] = x12029;
                      x12043 = false;
                    } else {
                      long x12033 = x11981;
                      long x12034 = x12033 + 1L;
                      long x12035 = x12034 % x802;
                      x11981 = x12035;
                      struct Anon1587544425* x12037 = x11382;
                      struct Anon1587544425 x12038 = x12037[x12035];
                      x11984 = x12038;
                      x12043 = true;
                    }
                    x12056 = x12043;
                  } else {
                    long x12045 = x11981;
                    struct Anon1587544425* x12048 = x11382;
                    x12048[x12045] = x12047;
                    long x12050 = x11383;
                    x11384[x12050] = x12045;
                    x11383 = x11383 + 1L;
                    x12056 = false;
                  }
                  if (!x12056) break;
                }
              }
            } else {
            }
          }
        } else {
        }
      }
    }
    long x12073 = x11383;
    long x12075;
    for(x12075=0L; x12075 < x12073; x12075++) {
      long x12076 = x11384[x12075];
      struct Anon1587544425* x12077 = x11382;
      struct Anon1587544425 x12078 = x12077[x12076];
      if (x975) {
      } else {
        struct Anon726278688 x12081 = x12078.key;;
        struct Anon2052879266 x12087 = x12078.aggs;;
        char* x12082 = x12081.SUPP_NATION;;
        int x12083 = strlen(x12082);
        char* x12084 = x12081.CUST_NATION;;
        int x12085 = strlen(x12084);
        int x12086 = x12081.L_YEAR;;
        double x12088 = x12087._0;;
        printf("%.*s|%.*s|%d|%.4f\n",x12083,x12082,x12085,x12084,x12086,x12088);
        x11395 = x11395 + 1L;
      }
    }
    long x12095 = x11395;
    printf("(%d rows)\n",x12095);
    gettimeofday(&x12099, NULL);
    timeval_subtract(&x12100, &x12099, &x12098);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x12100.tv_sec * 1000) + (x12100.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
