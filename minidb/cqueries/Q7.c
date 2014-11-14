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
struct Anon713865179Anon72918141;
struct Anon1023322325;
struct Anon855148991;
struct Anon147418070;
struct Anon920667905Anon811555534Anon168903330;
struct Anon482109446;
struct Anon1465150758;
struct Anon713865179;
struct Anon546410247;
struct Anon786783320;
struct Anon1078540535;
struct Anon2134411685;
struct Anon713865179Anon72918141Anon1268892766Anon168903330Anon811555534;
struct Anon1812879556;
struct Anon0;
struct Anon15765642;
struct Anon811555534;
struct Anon102935935;
struct Anon713865179Anon72918141Anon1268892766Anon168903330;
struct Anon1268892766;
struct Anon72918141;
struct Anon327816002;
struct Anon2131537536;
struct Anon313206116;
struct Anon2052879266;
struct Anon713865179Anon72918141Anon1268892766;
struct Anon920667905Anon713865179Anon72918141Anon1268892766Anon168903330Anon811555534;
struct Anon722854457;
struct Anon1732223439;
struct Anon949908027;
struct Anon625264174;
struct Anon348455037;
struct Anon1395358962;
struct Anon726278688;
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

struct Anon2134411685 {
int key;
struct Anon1023322325* aggs;
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

struct Anon1812879556 {
char* key;
struct Anon2052879266* aggs;
};

struct Anon0 {
struct Anon920667905* left;
struct Anon713865179Anon72918141Anon1268892766Anon168903330Anon811555534* right;
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

struct Anon2131537536 {
int key;
struct Anon1023322325* wnd;
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

struct Anon2052879266 {
double _0;
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

struct Anon949908027 {
struct Anon726278688* key;
struct Anon2052879266* aggs;
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

struct Anon726278688 {
char* SUPP_NATION;
char* CUST_NATION;
int L_YEAR;
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
int x13073(struct Anon949908027* x10718, struct Anon949908027* x10717);
int x13079(struct Anon949908027* x13074, struct Anon949908027* x13075, struct Anon949908027** x13076);
int x13073(struct Anon949908027* x10718, struct Anon949908027* x10717) {
  struct Anon726278688* x10719 = x10717->key;;
  char* x10721 = x10719->SUPP_NATION;;
  struct Anon726278688* x10720 = x10718->key;;
  char* x10722 = x10720->SUPP_NATION;;
  int x10723 = strcmp(x10721,x10722);
  bool x12079 = x10723 == 0;
  int x12087;
  if (x12079) {
    char* x10726 = x10719->CUST_NATION;;
    char* x10727 = x10720->CUST_NATION;;
    int x10728 = strcmp(x10726,x10727);
    bool x12080 = x10728 == 0;
    int x12085;
    if (x12080) {
      int x10731 = x10719->L_YEAR;;
      int x10732 = x10720->L_YEAR;;
      bool x10733 = x10731 < x10732;
      int x12083;
      if (x10733) {
        x12083 = -1;
      } else {
        bool x10734 = x10731 > x10732;
        int x12081;
        if (x10734) {
          x12081 = 1;
        } else {
          x12081 = 0;
        }
        x12083 = x12081;
      }
      x12085 = x12083;
    } else {
      x12085 = x10728;
    }
    x12087 = x12085;
  } else {
    x12087 = x10723;
  }
  return x12087;
}
int x13079(struct Anon949908027* x13074, struct Anon949908027* x13075, struct Anon949908027** x13076) {
  *x13076 = x13075;
  return 0;
}

/************************ MAIN BODY **************************/
int main(int x9995, char** x9996) {
  FILE* x11562 = fopen("../databases/sf2/nation.tbl", "r");
  int x11563 = 1048576;
  int x11564 = 0;
  int* x11565 = (int*)malloc(1048576 * sizeof(int));
  int* x11566 = x11565;
  char** x11567 = (char**)malloc(1048576 * sizeof(char*));
  char** x11568 = x11567;
  int* x11569 = (int*)malloc(1048576 * sizeof(int));
  int* x11570 = x11569;
  char** x11571 = (char**)malloc(1048576 * sizeof(char*));
  char** x11572 = x11571;
  for (;;) {
    bool x11573 = !feof(x11562);
    if (!x11573) break;
    int x11575 = 0;
    if (fscanf(x11562,"%d|",&x11575) == EOF) break;
    char* x11576 = (char*)malloc(26 * sizeof(char));
    int x11578 = 0;
    char x11577 = ' ';
    while (1) {
      fscanf(x11562,"%c",&x11577);
      if (x11577=='|' || x11577=='\n') break;
      if (x11578>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x11578); break;}
      ((char*)x11576)[x11578] = x11577;
      x11578 += 1;
    }
    ((char*)x11576)[x11578] = '\0';
    char* x11580 = x11576; // unsafe immutable;
    int x11581 = 0;
    if (fscanf(x11562,"%d|",&x11581) == EOF) break;
    char* x11582 = (char*)malloc(153 * sizeof(char));
    int x11584 = 0;
    char x11583 = ' ';
    while (1) {
      fscanf(x11562,"%c",&x11583);
      if (x11583=='|' || x11583=='\n') break;
      if (x11584>=152) { printf("ERROR: scanner.nextString reading past end of buffer %d",x11584); break;}
      ((char*)x11582)[x11584] = x11583;
      x11584 += 1;
    }
    ((char*)x11582)[x11584] = '\0';
    char* x11586 = x11582; // unsafe immutable;
    int x11587 = x11564;
    int x11588 = x11563;
    bool x11589 = x11587 == x11588;
    if (x11589) {
      int x11590 = x11588 * 4;
      x11563 = x11590;
      printf("buffer.resize %d\n",x11590);
      int* x11593 = x11566;
      int* x11594 = (int*)realloc(x11593,x11590 * sizeof(int));
      x11566 = x11594;
      char** x11596 = x11568;
      char** x11597 = (char**)realloc(x11596,x11590 * sizeof(char*));
      x11568 = x11597;
      int* x11599 = x11570;
      int* x11600 = (int*)realloc(x11599,x11590 * sizeof(int));
      x11570 = x11600;
      char** x11602 = x11572;
      char** x11603 = (char**)realloc(x11602,x11590 * sizeof(char*));
      x11572 = x11603;
    } else {
    }
    int* x11607 = x11566;
    x11607[x11587] = x11575;
    char** x11609 = x11568;
    x11609[x11587] = x11580;
    int* x11611 = x11570;
    x11611[x11587] = x11581;
    char** x11613 = x11572;
    x11613[x11587] = x11586;
    x11564 = x11564 + 1;
  }
  FILE* x11619 = fopen("../databases/sf2/orders.tbl", "r");
  int x11620 = 1048576;
  int x11621 = 0;
  int* x11622 = (int*)malloc(1048576 * sizeof(int));
  int* x11623 = x11622;
  int* x11624 = (int*)malloc(1048576 * sizeof(int));
  int* x11625 = x11624;
  for (;;) {
    bool x11640 = !feof(x11619);
    if (!x11640) break;
    int x11642 = 0;
    if (fscanf(x11619,"%d|",&x11642) == EOF) break;
    int x11643 = 0;
    if (fscanf(x11619,"%d|",&x11643) == EOF) break;
    char x11644 = ' ';
    if (fscanf(x11619,"%c|",&x11644) == EOF) break;
    double x11645 = 0.0;
    if (fscanf(x11619,"%lf|",&x11645) == EOF) break;
    int x11646 = 0;
    int x11647 = 0;
    int x11648 = 0;
    fscanf(x11619, "%d-%d-%d|",&x11646, &x11647, &x11648);
    long x11649 = (x11646 * 10000) + (x11647 * 100) + x11648;
    char* x11650 = (char*)malloc(16 * sizeof(char));
    int x11652 = 0;
    char x11651 = ' ';
    while (1) {
      fscanf(x11619,"%c",&x11651);
      if (x11651=='|' || x11651=='\n') break;
      if (x11652>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x11652); break;}
      ((char*)x11650)[x11652] = x11651;
      x11652 += 1;
    }
    ((char*)x11650)[x11652] = '\0';
    char* x11655 = (char*)malloc(16 * sizeof(char));
    int x11657 = 0;
    char x11656 = ' ';
    while (1) {
      fscanf(x11619,"%c",&x11656);
      if (x11656=='|' || x11656=='\n') break;
      if (x11657>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x11657); break;}
      ((char*)x11655)[x11657] = x11656;
      x11657 += 1;
    }
    ((char*)x11655)[x11657] = '\0';
    int x11660 = 0;
    if (fscanf(x11619,"%d|",&x11660) == EOF) break;
    char* x11661 = (char*)malloc(80 * sizeof(char));
    int x11663 = 0;
    char x11662 = ' ';
    while (1) {
      fscanf(x11619,"%c",&x11662);
      if (x11662=='|' || x11662=='\n') break;
      if (x11663>=79) { printf("ERROR: scanner.nextString reading past end of buffer %d",x11663); break;}
      ((char*)x11661)[x11663] = x11662;
      x11663 += 1;
    }
    ((char*)x11661)[x11663] = '\0';
    int x11666 = x11621;
    int x11667 = x11620;
    bool x11668 = x11666 == x11667;
    if (x11668) {
      int x11669 = x11667 * 4;
      x11620 = x11669;
      printf("buffer.resize %d\n",x11669);
      int* x11672 = x11623;
      int* x11673 = (int*)realloc(x11672,x11669 * sizeof(int));
      x11623 = x11673;
      int* x11675 = x11625;
      int* x11676 = (int*)realloc(x11675,x11669 * sizeof(int));
      x11625 = x11676;
    } else {
    }
    int* x11701 = x11623;
    x11701[x11666] = x11642;
    int* x11703 = x11625;
    x11703[x11666] = x11643;
    x11621 = x11621 + 1;
  }
  FILE* x11723 = fopen("../databases/sf2/lineitem.tbl", "r");
  int x11724 = 1048576;
  int x11725 = 0;
  int* x11726 = (int*)malloc(1048576 * sizeof(int));
  int* x11727 = x11726;
  int* x11730 = (int*)malloc(1048576 * sizeof(int));
  int* x11731 = x11730;
  double* x11736 = (double*)malloc(1048576 * sizeof(double));
  double* x11737 = x11736;
  double* x11738 = (double*)malloc(1048576 * sizeof(double));
  double* x11739 = x11738;
  long* x11746 = (long*)malloc(1048576 * sizeof(long));
  long* x11747 = x11746;
  for (;;) {
    bool x11758 = !feof(x11723);
    if (!x11758) break;
    int x11760 = 0;
    if (fscanf(x11723,"%d|",&x11760) == EOF) break;
    int x11761 = 0;
    if (fscanf(x11723,"%d|",&x11761) == EOF) break;
    int x11762 = 0;
    if (fscanf(x11723,"%d|",&x11762) == EOF) break;
    int x11763 = 0;
    if (fscanf(x11723,"%d|",&x11763) == EOF) break;
    double x11764 = 0.0;
    if (fscanf(x11723,"%lf|",&x11764) == EOF) break;
    double x11765 = 0.0;
    if (fscanf(x11723,"%lf|",&x11765) == EOF) break;
    double x11766 = 0.0;
    if (fscanf(x11723,"%lf|",&x11766) == EOF) break;
    double x11767 = 0.0;
    if (fscanf(x11723,"%lf|",&x11767) == EOF) break;
    char x11768 = ' ';
    if (fscanf(x11723,"%c|",&x11768) == EOF) break;
    char x11769 = ' ';
    if (fscanf(x11723,"%c|",&x11769) == EOF) break;
    int x11770 = 0;
    int x11771 = 0;
    int x11772 = 0;
    fscanf(x11723, "%d-%d-%d|",&x11770, &x11771, &x11772);
    long x11773 = (x11770 * 10000) + (x11771 * 100) + x11772;
    int x11774 = 0;
    int x11775 = 0;
    int x11776 = 0;
    fscanf(x11723, "%d-%d-%d|",&x11774, &x11775, &x11776);
    long x11777 = (x11774 * 10000) + (x11775 * 100) + x11776;
    int x11778 = 0;
    int x11779 = 0;
    int x11780 = 0;
    fscanf(x11723, "%d-%d-%d|",&x11778, &x11779, &x11780);
    long x11781 = (x11778 * 10000) + (x11779 * 100) + x11780;
    char* x11782 = (char*)malloc(26 * sizeof(char));
    int x11784 = 0;
    char x11783 = ' ';
    while (1) {
      fscanf(x11723,"%c",&x11783);
      if (x11783=='|' || x11783=='\n') break;
      if (x11784>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x11784); break;}
      ((char*)x11782)[x11784] = x11783;
      x11784 += 1;
    }
    ((char*)x11782)[x11784] = '\0';
    char* x11787 = (char*)malloc(11 * sizeof(char));
    int x11789 = 0;
    char x11788 = ' ';
    while (1) {
      fscanf(x11723,"%c",&x11788);
      if (x11788=='|' || x11788=='\n') break;
      if (x11789>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x11789); break;}
      ((char*)x11787)[x11789] = x11788;
      x11789 += 1;
    }
    ((char*)x11787)[x11789] = '\0';
    char* x11792 = (char*)malloc(45 * sizeof(char));
    int x11794 = 0;
    char x11793 = ' ';
    while (1) {
      fscanf(x11723,"%c",&x11793);
      if (x11793=='|' || x11793=='\n') break;
      if (x11794>=44) { printf("ERROR: scanner.nextString reading past end of buffer %d",x11794); break;}
      ((char*)x11792)[x11794] = x11793;
      x11794 += 1;
    }
    ((char*)x11792)[x11794] = '\0';
    int x11797 = x11725;
    int x11798 = x11724;
    bool x11799 = x11797 == x11798;
    if (x11799) {
      int x11800 = x11798 * 4;
      x11724 = x11800;
      printf("buffer.resize %d\n",x11800);
      int* x11803 = x11727;
      int* x11804 = (int*)realloc(x11803,x11800 * sizeof(int));
      x11727 = x11804;
      int* x11809 = x11731;
      int* x11810 = (int*)realloc(x11809,x11800 * sizeof(int));
      x11731 = x11810;
      double* x11818 = x11737;
      double* x11819 = (double*)realloc(x11818,x11800 * sizeof(double));
      x11737 = x11819;
      double* x11821 = x11739;
      double* x11822 = (double*)realloc(x11821,x11800 * sizeof(double));
      x11739 = x11822;
      long* x11833 = x11747;
      long* x11834 = (long*)realloc(x11833,x11800 * sizeof(long));
      x11747 = x11834;
    } else {
    }
    int* x11853 = x11727;
    x11853[x11797] = x11760;
    int* x11857 = x11731;
    x11857[x11797] = x11762;
    double* x11863 = x11737;
    x11863[x11797] = x11765;
    double* x11865 = x11739;
    x11865[x11797] = x11766;
    long* x11873 = x11747;
    x11873[x11797] = x11773;
    x11725 = x11725 + 1;
  }
  FILE* x11889 = fopen("../databases/sf2/customer.tbl", "r");
  int x11890 = 1048576;
  int x11891 = 0;
  int* x11892 = (int*)malloc(1048576 * sizeof(int));
  int* x11893 = x11892;
  int* x11898 = (int*)malloc(1048576 * sizeof(int));
  int* x11899 = x11898;
  for (;;) {
    bool x11908 = !feof(x11889);
    if (!x11908) break;
    int x11910 = 0;
    if (fscanf(x11889,"%d|",&x11910) == EOF) break;
    char* x11911 = (char*)malloc(26 * sizeof(char));
    int x11913 = 0;
    char x11912 = ' ';
    while (1) {
      fscanf(x11889,"%c",&x11912);
      if (x11912=='|' || x11912=='\n') break;
      if (x11913>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x11913); break;}
      ((char*)x11911)[x11913] = x11912;
      x11913 += 1;
    }
    ((char*)x11911)[x11913] = '\0';
    char* x11916 = (char*)malloc(41 * sizeof(char));
    int x11918 = 0;
    char x11917 = ' ';
    while (1) {
      fscanf(x11889,"%c",&x11917);
      if (x11917=='|' || x11917=='\n') break;
      if (x11918>=40) { printf("ERROR: scanner.nextString reading past end of buffer %d",x11918); break;}
      ((char*)x11916)[x11918] = x11917;
      x11918 += 1;
    }
    ((char*)x11916)[x11918] = '\0';
    int x11921 = 0;
    if (fscanf(x11889,"%d|",&x11921) == EOF) break;
    char* x11922 = (char*)malloc(16 * sizeof(char));
    int x11924 = 0;
    char x11923 = ' ';
    while (1) {
      fscanf(x11889,"%c",&x11923);
      if (x11923=='|' || x11923=='\n') break;
      if (x11924>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x11924); break;}
      ((char*)x11922)[x11924] = x11923;
      x11924 += 1;
    }
    ((char*)x11922)[x11924] = '\0';
    double x11927 = 0.0;
    if (fscanf(x11889,"%lf|",&x11927) == EOF) break;
    char* x11928 = (char*)malloc(11 * sizeof(char));
    int x11930 = 0;
    char x11929 = ' ';
    while (1) {
      fscanf(x11889,"%c",&x11929);
      if (x11929=='|' || x11929=='\n') break;
      if (x11930>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x11930); break;}
      ((char*)x11928)[x11930] = x11929;
      x11930 += 1;
    }
    ((char*)x11928)[x11930] = '\0';
    char* x11933 = (char*)malloc(118 * sizeof(char));
    int x11935 = 0;
    char x11934 = ' ';
    while (1) {
      fscanf(x11889,"%c",&x11934);
      if (x11934=='|' || x11934=='\n') break;
      if (x11935>=117) { printf("ERROR: scanner.nextString reading past end of buffer %d",x11935); break;}
      ((char*)x11933)[x11935] = x11934;
      x11935 += 1;
    }
    ((char*)x11933)[x11935] = '\0';
    int x11938 = x11891;
    int x11939 = x11890;
    bool x11940 = x11938 == x11939;
    if (x11940) {
      int x11941 = x11939 * 4;
      x11890 = x11941;
      printf("buffer.resize %d\n",x11941);
      int* x11944 = x11893;
      int* x11945 = (int*)realloc(x11944,x11941 * sizeof(int));
      x11893 = x11945;
      int* x11953 = x11899;
      int* x11954 = (int*)realloc(x11953,x11941 * sizeof(int));
      x11899 = x11954;
    } else {
    }
    int* x11970 = x11893;
    x11970[x11938] = x11910;
    int* x11976 = x11899;
    x11976[x11938] = x11921;
    x11891 = x11891 + 1;
  }
  FILE* x11990 = fopen("../databases/sf2/supplier.tbl", "r");
  int x11991 = 1048576;
  int x11992 = 0;
  int* x11993 = (int*)malloc(1048576 * sizeof(int));
  int* x11994 = x11993;
  int* x11999 = (int*)malloc(1048576 * sizeof(int));
  int* x12000 = x11999;
  for (;;) {
    bool x12007 = !feof(x11990);
    if (!x12007) break;
    int x12009 = 0;
    if (fscanf(x11990,"%d|",&x12009) == EOF) break;
    char* x12010 = (char*)malloc(26 * sizeof(char));
    int x12012 = 0;
    char x12011 = ' ';
    while (1) {
      fscanf(x11990,"%c",&x12011);
      if (x12011=='|' || x12011=='\n') break;
      if (x12012>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x12012); break;}
      ((char*)x12010)[x12012] = x12011;
      x12012 += 1;
    }
    ((char*)x12010)[x12012] = '\0';
    char* x12015 = (char*)malloc(41 * sizeof(char));
    int x12017 = 0;
    char x12016 = ' ';
    while (1) {
      fscanf(x11990,"%c",&x12016);
      if (x12016=='|' || x12016=='\n') break;
      if (x12017>=40) { printf("ERROR: scanner.nextString reading past end of buffer %d",x12017); break;}
      ((char*)x12015)[x12017] = x12016;
      x12017 += 1;
    }
    ((char*)x12015)[x12017] = '\0';
    int x12020 = 0;
    if (fscanf(x11990,"%d|",&x12020) == EOF) break;
    char* x12021 = (char*)malloc(16 * sizeof(char));
    int x12023 = 0;
    char x12022 = ' ';
    while (1) {
      fscanf(x11990,"%c",&x12022);
      if (x12022=='|' || x12022=='\n') break;
      if (x12023>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x12023); break;}
      ((char*)x12021)[x12023] = x12022;
      x12023 += 1;
    }
    ((char*)x12021)[x12023] = '\0';
    double x12026 = 0.0;
    if (fscanf(x11990,"%lf|",&x12026) == EOF) break;
    char* x12027 = (char*)malloc(102 * sizeof(char));
    int x12029 = 0;
    char x12028 = ' ';
    while (1) {
      fscanf(x11990,"%c",&x12028);
      if (x12028=='|' || x12028=='\n') break;
      if (x12029>=101) { printf("ERROR: scanner.nextString reading past end of buffer %d",x12029); break;}
      ((char*)x12027)[x12029] = x12028;
      x12029 += 1;
    }
    ((char*)x12027)[x12029] = '\0';
    int x12032 = x11992;
    int x12033 = x11991;
    bool x12034 = x12032 == x12033;
    if (x12034) {
      int x12035 = x12033 * 4;
      x11991 = x12035;
      printf("buffer.resize %d\n",x12035);
      int* x12038 = x11994;
      int* x12039 = (int*)realloc(x12038,x12035 * sizeof(int));
      x11994 = x12039;
      int* x12047 = x12000;
      int* x12048 = (int*)realloc(x12047,x12035 * sizeof(int));
      x12000 = x12048;
    } else {
    }
    int* x12061 = x11994;
    x12061[x12032] = x12009;
    int* x12067 = x12000;
    x12067[x12032] = x12020;
    x11992 = x11992 + 1;
  }
  GTree* x12089 = g_tree_new((GCompareFunc)x13073);;
  bool x12090 = true == false;
  int x10514;
  for(x10514=0; x10514 < 1; x10514++) {
    bool x12091 = false;
    int x12092 = 0;
    bool x12094 = false;
    int x12095 = 0;
    struct Anon713865179* x12099 = NULL;
    bool x12101 = false;
    int x12102 = 0;
    int* x12104 = (int*)malloc(1073741824 * sizeof(int));
    int* x12105 = x12104;
    char** x12106 = (char**)malloc(1073741824 * sizeof(char*));
    char** x12107 = x12106;
    int* x12112 = (int*)malloc(1073741824 * sizeof(int));
    int* x12113 = x12112;
    char** x12114 = (char**)malloc(1073741824 * sizeof(char*));
    char** x12115 = x12114;
    int x12120 = 0;
    int* x12121 = (int*)malloc(1048576 * sizeof(int));
    int* x12122 = (int*)malloc(1073741824 * sizeof(int));
    int x10547;
    for(x10547=0; x10547 < 1048576; x10547++) {
      x12121[x10547] = -1;
    }
    bool x12127 = false;
    int x12128 = 0;
    char** x12133 = (char**)malloc(1073741824 * sizeof(char*));
    char** x12134 = x12133;
    int* x12139 = (int*)malloc(1073741824 * sizeof(int));
    int* x12140 = x12139;
    char** x12141 = (char**)malloc(1073741824 * sizeof(char*));
    char** x12142 = x12141;
    int* x12147 = (int*)malloc(1073741824 * sizeof(int));
    int* x12148 = x12147;
    int x12161 = 0;
    int* x12162 = (int*)malloc(1048576 * sizeof(int));
    int* x12163 = (int*)malloc(1073741824 * sizeof(int));
    int x10589;
    for(x10589=0; x10589 < 1048576; x10589++) {
      x12162[x10589] = -1;
    }
    bool x12168 = false;
    int x12169 = 0;
    char** x12173 = (char**)malloc(1073741824 * sizeof(char*));
    char** x12174 = x12173;
    int* x12179 = (int*)malloc(1073741824 * sizeof(int));
    int* x12180 = x12179;
    char** x12181 = (char**)malloc(1073741824 * sizeof(char*));
    char** x12182 = x12181;
    int* x12201 = (int*)malloc(1073741824 * sizeof(int));
    int* x12202 = x12201;
    double* x12211 = (double*)malloc(1073741824 * sizeof(double));
    double* x12212 = x12211;
    double* x12213 = (double*)malloc(1073741824 * sizeof(double));
    double* x12214 = x12213;
    long* x12221 = (long*)malloc(1073741824 * sizeof(long));
    long* x12222 = x12221;
    int x12233 = 0;
    int* x12234 = (int*)malloc(1048576 * sizeof(int));
    int* x12235 = (int*)malloc(1073741824 * sizeof(int));
    int x10662;
    for(x10662=0; x10662 < 1048576; x10662++) {
      x12234[x10662] = -1;
    }
    bool x12240 = false;
    int x12241 = 0;
    int* x12243 = (int*)malloc(1073741824 * sizeof(int));
    int* x12244 = x12243;
    int* x12249 = (int*)malloc(1073741824 * sizeof(int));
    int* x12250 = x12249;
    int x12259 = 0;
    int* x12260 = (int*)malloc(1048576 * sizeof(int));
    int* x12261 = (int*)malloc(1073741824 * sizeof(int));
    int x10689;
    for(x10689=0; x10689 < 1048576; x10689++) {
      x12260[x10689] = -1;
    }
    int x12267 = 1048576;
    int x12268 = 0;
    char** x12269 = (char**)malloc(1048576 * sizeof(char*));
    char** x12270 = x12269;
    char** x12271 = (char**)malloc(1048576 * sizeof(char*));
    char** x12272 = x12271;
    int* x12273 = (int*)malloc(1048576 * sizeof(int));
    int* x12274 = x12273;
    double* x12275 = (double*)malloc(1048576 * sizeof(double));
    double* x12276 = x12275;
    int x12277 = 4194304;
    int x12278 = 0;
    int* x12279 = (int*)malloc(4194304 * sizeof(int));
    int* x12280 = x12279;
    int x10709;
    for(x10709=0; x10709 < 4194304; x10709++) {
      int* x12281 = x12280;
      x12281[x10709] = -1;
    }
    int x12289 = 0;
    struct timeval x11537, x11538, x13066;
    gettimeofday(&x11537, NULL);
    printf("(CUSTOMER X (((op(?) X SUPPLIER) X LINEITEM) X ORDERS)): leftParent.next start\n");
    struct timeval x10798, x10799, x12347;
    gettimeofday(&x10798, NULL);
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x12292 = x12240;
      bool x12293 = !x12292;
      bool x12298 = x12293;
      if (x12293) {
        int x12294 = x12241;
        int x12295 = x11891;
        bool x12296 = x12294 < x12295;
        x12298 = x12296;
      }
      bool x12299 = x12298;
      if (!x12299) break;
      int x12302 = x12241;
      int* x12303 = x11893;
      int x12304 = x12303[x12302];
      int* x12309 = x11899;
      int x12310 = x12309[x12302];
      x12241 = x12241 + 1;
      int x12320 = x12259;
      int* x12321 = x12244;
      x12321[x12320] = x12304;
      int* x12327 = x12250;
      x12327[x12320] = x12310;
      x12259 = x12259 + 1;
      int x12338 = x12304 & 1048575;
      int x12339 = x12260[x12338];
      x12260[x12338] = x12320;
      x12261[x12320] = x12339;
    }
    printf("(CUSTOMER X (((op(?) X SUPPLIER) X LINEITEM) X ORDERS)): leftParent.next done\n");
    gettimeofday(&x10799, NULL);
    timeval_subtract(&x12347, &x10799, &x10798);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x12347.tv_sec * 1000) + (x12347.tv_usec/1000)));
    printf("(CUSTOMER X (((op(?) X SUPPLIER) X LINEITEM) X ORDERS)): rightParent.next start\n");
    struct timeval x11494, x11495, x13025;
    gettimeofday(&x11494, NULL);
    printf("(((op(?) X SUPPLIER) X LINEITEM) X ORDERS): leftParent.next start\n");
    struct timeval x11194, x11195, x12736;
    gettimeofday(&x11194, NULL);
    printf("((op(?) X SUPPLIER) X LINEITEM): leftParent.next start\n");
    struct timeval x11012, x11013, x12557;
    gettimeofday(&x11012, NULL);
    printf("(op(?) X SUPPLIER): leftParent.next start\n");
    struct timeval x10900, x10901, x12449;
    gettimeofday(&x10900, NULL);
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x12354 = x12091;
      bool x12355 = !x12354;
      bool x12360 = x12355;
      if (x12355) {
        int x12356 = x12092;
        int x12357 = x11564;
        bool x12358 = x12356 < x12357;
        x12360 = x12358;
      }
      bool x12361 = x12360;
      if (!x12361) break;
      int x12364 = x12092;
      int* x12365 = x11566;
      int x12366 = x12365[x12364];
      char** x12367 = x11568;
      char* x12368 = x12367[x12364];
      int* x12369 = x11570;
      int x12370 = x12369[x12364];
      char** x12371 = x11572;
      char* x12372 = x12371[x12364];
      x12092 = x12092 + 1;
      struct Anon713865179* x12374 = (struct Anon713865179*)malloc(sizeof(struct Anon713865179));
      x12374->N1_N_NATIONKEY = x12366;
      x12374->N1_N_NAME = x12368;
      x12374->N1_N_REGIONKEY = x12370;
      x12374->N1_N_COMMENT = x12372;
      x12099 = x12374;
      printf("%s\n","begin scan NATION");
      for (;;) {
        bool x12377 = x12094;
        bool x12378 = !x12377;
        bool x12383 = x12378;
        if (x12378) {
          int x12379 = x12095;
          int x12380 = x11564;
          bool x12381 = x12379 < x12380;
          x12383 = x12381;
        }
        bool x12384 = x12383;
        if (!x12384) break;
        int x12387 = x12095;
        int* x12388 = x11566;
        int x12389 = x12388[x12387];
        char** x12390 = x11568;
        char* x12391 = x12390[x12387];
        x12095 = x12095 + 1;
        struct Anon713865179* x12397 = x12099;
        char* x12398 = x12397->N1_N_NAME;;
        bool x12399 = strcmp(x12398,"UNITED STATES") == 0;;
        bool x12402 = x12399;
        if (x12399) {
          bool x12400 = strcmp(x12391,"INDONESIA") == 0;;
          x12402 = x12400;
        }
        bool x12403 = x12402;
        bool x12410 = x12403;
        if (x12403 == false) {
          bool x12404 = strcmp(x12398,"INDONESIA") == 0;;
          bool x12407 = x12404;
          if (x12404) {
            bool x12405 = strcmp(x12391,"UNITED STATES") == 0;;
            x12407 = x12405;
          }
          bool x12408 = x12407;
          x12410 = x12408;
        }
        bool x12411 = x12410;
        if (x12411) {
          int x12412 = x12120;
          int* x12413 = x12105;
          int x12414 = x12397->N1_N_NATIONKEY;;
          x12413[x12412] = x12414;
          char** x12416 = x12107;
          x12416[x12412] = x12398;
          int* x12424 = x12113;
          x12424[x12412] = x12389;
          char** x12426 = x12115;
          x12426[x12412] = x12391;
          x12120 = x12120 + 1;
          int x12433 = x12414 & 1048575;
          int x12434 = x12121[x12433];
          x12121[x12433] = x12412;
          x12122[x12412] = x12434;
        } else {
        }
      }
      x12095 = 0;
    }
    printf("(op(?) X SUPPLIER): leftParent.next done\n");
    gettimeofday(&x10901, NULL);
    timeval_subtract(&x12449, &x10901, &x10900);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x12449.tv_sec * 1000) + (x12449.tv_usec/1000)));
    printf("(op(?) X SUPPLIER): rightParent.next start\n");
    struct timeval x11006, x11007, x12552;
    gettimeofday(&x11006, NULL);
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x12453 = x12101;
      bool x12454 = !x12453;
      bool x12459 = x12454;
      if (x12454) {
        int x12455 = x12102;
        int x12456 = x11992;
        bool x12457 = x12455 < x12456;
        x12459 = x12457;
      }
      bool x12460 = x12459;
      if (!x12460) break;
      int x12463 = x12102;
      int* x12464 = x11994;
      int x12465 = x12464[x12463];
      int* x12470 = x12000;
      int x12471 = x12470[x12463];
      x12102 = x12102 + 1;
      int x12479 = x12471 & 1048575;
      int x12480 = x12121[x12479];
      int x12481 = x12480;
      int x12482 = x12465 & 1048575;
      for (;;) {
        int x12483 = x12481;
        bool x12484 = x12483 != -1;
        if (!x12484) break;
        int x12486 = x12481;
        int* x12487 = x12105;
        int x12488 = x12487[x12486];
        char** x12489 = x12107;
        char* x12490 = x12489[x12486];
        int* x12495 = x12113;
        int x12496 = x12495[x12486];
        char** x12497 = x12115;
        char* x12498 = x12497[x12486];
        int x12503 = x12122[x12486];
        x12481 = x12503;
        bool x12505 = x12488 == x12471;
        if (x12505) {
          int x12506 = x12161;
          char** x12509 = x12134;
          x12509[x12506] = x12490;
          int* x12515 = x12140;
          x12515[x12506] = x12496;
          char** x12517 = x12142;
          x12517[x12506] = x12498;
          int* x12523 = x12148;
          x12523[x12506] = x12465;
          x12161 = x12161 + 1;
          int x12538 = x12162[x12482];
          x12162[x12482] = x12506;
          x12163[x12506] = x12538;
        } else {
        }
      }
    }
    printf("(op(?) X SUPPLIER): rightParent.next done\n");
    gettimeofday(&x11007, NULL);
    timeval_subtract(&x12552, &x11007, &x11006);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x12552.tv_sec * 1000) + (x12552.tv_usec/1000)));
    printf("((op(?) X SUPPLIER) X LINEITEM): leftParent.next done\n");
    gettimeofday(&x11013, NULL);
    timeval_subtract(&x12557, &x11013, &x11012);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x12557.tv_sec * 1000) + (x12557.tv_usec/1000)));
    printf("((op(?) X SUPPLIER) X LINEITEM): rightParent.next start\n");
    struct timeval x11188, x11189, x12731;
    gettimeofday(&x11188, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x12561 = x12127;
      bool x12562 = !x12561;
      bool x12567 = x12562;
      if (x12562) {
        int x12563 = x12128;
        int x12564 = x11725;
        bool x12565 = x12563 < x12564;
        x12567 = x12565;
      }
      bool x12568 = x12567;
      if (!x12568) break;
      int x12571 = x12128;
      int* x12572 = x11727;
      int x12573 = x12572[x12571];
      int* x12576 = x11731;
      int x12577 = x12576[x12571];
      double* x12582 = x11737;
      double x12583 = x12582[x12571];
      double* x12584 = x11739;
      double x12585 = x12584[x12571];
      long* x12592 = x11747;
      long x12593 = x12592[x12571];
      x12128 = x12128 + 1;
      bool x12605 = x12593 >= 19950101L;
      bool x12607 = x12605;
      if (x12605) {
        bool x12606 = x12593 <= 19961231L;
        x12607 = x12606;
      }
      bool x12608 = x12607;
      if (x12608) {
        int x12609 = x12577 & 1048575;
        int x12610 = x12162[x12609];
        int x12611 = x12610;
        int x12612 = x12573 & 1048575;
        for (;;) {
          int x12613 = x12611;
          bool x12614 = x12613 != -1;
          if (!x12614) break;
          int x12616 = x12611;
          char** x12619 = x12134;
          char* x12620 = x12619[x12616];
          int* x12625 = x12140;
          int x12626 = x12625[x12616];
          char** x12627 = x12142;
          char* x12628 = x12627[x12616];
          int* x12633 = x12148;
          int x12634 = x12633[x12616];
          int x12647 = x12163[x12616];
          x12611 = x12647;
          bool x12649 = x12634 == x12577;
          if (x12649) {
            int x12650 = x12233;
            char** x12653 = x12174;
            x12653[x12650] = x12620;
            int* x12659 = x12180;
            x12659[x12650] = x12626;
            char** x12661 = x12182;
            x12661[x12650] = x12628;
            int* x12681 = x12202;
            x12681[x12650] = x12573;
            double* x12691 = x12212;
            x12691[x12650] = x12583;
            double* x12693 = x12214;
            x12693[x12650] = x12585;
            long* x12701 = x12222;
            x12701[x12650] = x12593;
            x12233 = x12233 + 1;
            int x12714 = x12234[x12612];
            x12234[x12612] = x12650;
            x12235[x12650] = x12714;
          } else {
          }
        }
      } else {
      }
    }
    printf("((op(?) X SUPPLIER) X LINEITEM): rightParent.next done\n");
    gettimeofday(&x11189, NULL);
    timeval_subtract(&x12731, &x11189, &x11188);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x12731.tv_sec * 1000) + (x12731.tv_usec/1000)));
    printf("(((op(?) X SUPPLIER) X LINEITEM) X ORDERS): leftParent.next done\n");
    gettimeofday(&x11195, NULL);
    timeval_subtract(&x12736, &x11195, &x11194);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x12736.tv_sec * 1000) + (x12736.tv_usec/1000)));
    printf("(((op(?) X SUPPLIER) X LINEITEM) X ORDERS): rightParent.next start\n");
    struct timeval x11488, x11489, x13020;
    gettimeofday(&x11488, NULL);
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x12740 = x12168;
      bool x12741 = !x12740;
      bool x12746 = x12741;
      if (x12741) {
        int x12742 = x12169;
        int x12743 = x11621;
        bool x12744 = x12742 < x12743;
        x12746 = x12744;
      }
      bool x12747 = x12746;
      if (!x12747) break;
      int x12750 = x12169;
      int* x12751 = x11623;
      int x12752 = x12751[x12750];
      int* x12753 = x11625;
      int x12754 = x12753[x12750];
      x12169 = x12169 + 1;
      int x12770 = x12752 & 1048575;
      int x12771 = x12234[x12770];
      int x12772 = x12771;
      int x12773 = x12754 & 1048575;
      for (;;) {
        int x12774 = x12772;
        bool x12775 = x12774 != -1;
        if (!x12775) break;
        int x12777 = x12772;
        char** x12780 = x12174;
        char* x12781 = x12780[x12777];
        int* x12786 = x12180;
        int x12787 = x12786[x12777];
        char** x12788 = x12182;
        char* x12789 = x12788[x12777];
        int* x12808 = x12202;
        int x12809 = x12808[x12777];
        double* x12818 = x12212;
        double x12819 = x12818[x12777];
        double* x12820 = x12214;
        double x12821 = x12820[x12777];
        long* x12828 = x12222;
        long x12829 = x12828[x12777];
        int x12840 = x12235[x12777];
        x12772 = x12840;
        bool x12842 = x12809 == x12752;
        if (x12842) {
          int x12843 = x12260[x12773];
          int x12844 = x12843;
          char x12845 = x12781[0];
          long x12846 = x12829/10000;
          int x12847 = (int)x12846;
          char x12848 = x12789[0];
          int x12849 = x12848 * 41;
          int x12850 = x12849 + x12847;
          int x12851 = x12850 * 41;
          int x12852 = x12851 + x12845;
          int x12853 = x12852 * 2;
          int x12854 = x12853 * 3;
          double x12855 = 1.0 - x12821;
          double x12856 = x12819 * x12855;
          for (;;) {
            int x12857 = x12844;
            bool x12858 = x12857 != -1;
            if (!x12858) break;
            int x12860 = x12844;
            int* x12861 = x12244;
            int x12862 = x12861[x12860];
            int* x12867 = x12250;
            int x12868 = x12867[x12860];
            int x12877 = x12261[x12860];
            x12844 = x12877;
            bool x12879 = x12862 == x12754;
            bool x12882 = x12879;
            if (x12879) {
              bool x12880 = x12868 == x12787;
              x12882 = x12880;
            }
            bool x12883 = x12882;
            if (x12883) {
              int x12885 = x12277;
              int x12886 = x12885 - 1;
              int x12887 = x12854 & x12886;
              int x12888 = x12887;
              int* x12889 = x12280;
              int x12890 = x12889[x12887];
              int x12891 = x12890;
              int x12892 = x12887 + 1;
              int x12893 = x12889[x12892];
              int x12894 = x12893;
              for (;;) {
                int x12895 = x12891;
                bool x12896 = x12895 != -1;
                bool x12924 = x12896;
                if (x12896) {
                  int x12897 = x12894;
                  bool x12898 = x12897 != x12854;
                  bool x12920 = x12898;
                  if (x12898 == false) {
                    int x12899 = x12891;
                    char** x12900 = x12270;
                    char* x12901 = x12900[x12899];
                    char** x12902 = x12272;
                    char* x12903 = x12902[x12899];
                    int* x12904 = x12274;
                    int x12905 = x12904[x12899];
                    bool x12908 = strcmp(x12901,x12781) == 0;;
                    bool x12911 = x12908;
                    if (x12908) {
                      bool x12909 = strcmp(x12903,x12789) == 0;;
                      x12911 = x12909;
                    }
                    bool x12912 = x12911;
                    bool x12915 = x12912;
                    if (x12912) {
                      bool x12913 = x12905 == x12847;
                      x12915 = x12913;
                    }
                    bool x12916 = x12915;
                    bool x12917 = !x12916;
                    x12920 = x12917;
                  }
                  bool x12921 = x12920;
                  x12924 = x12921;
                }
                bool x12925 = x12924;
                if (!x12925) break;
                int x12928 = x12888;
                int x12929 = x12928 + 2;
                int x12930 = x12929 & x12886;
                x12888 = x12930;
                int* x12932 = x12280;
                int x12933 = x12932[x12930];
                x12891 = x12933;
                int x12935 = x12930 + 1;
                int x12936 = x12932[x12935];
                x12894 = x12936;
              }
              int x12941 = x12891;
              bool x12942 = x12941 == -1;
              int x12988;
              if (x12942) {
                int x12943 = x12278;
                int x12944 = x12888;
                x12889[x12944] = x12943;
                int x12946 = x12944 + 1;
                x12889[x12946] = x12854;
                x12278 = x12278 + 1;
                int x12949 = x12268;
                int x12950 = x12267;
                bool x12951 = x12949 == x12950;
                if (x12951) {
                  int x12952 = x12950 * 4;
                  x12267 = x12952;
                  printf("buffer.resize %d\n",x12952);
                  printf("buffer.resize %d\n",x12952);
                  char** x12956 = x12270;
                  char** x12957 = (char**)realloc(x12956,x12952 * sizeof(char*));
                  x12270 = x12957;
                  char** x12959 = x12272;
                  char** x12960 = (char**)realloc(x12959,x12952 * sizeof(char*));
                  x12272 = x12960;
                  int* x12962 = x12274;
                  int* x12963 = (int*)realloc(x12962,x12952 * sizeof(int));
                  x12274 = x12963;
                  printf("buffer.resize %d\n",x12952);
                  double* x12966 = x12276;
                  double* x12967 = (double*)realloc(x12966,x12952 * sizeof(double));
                  x12276 = x12967;
                } else {
                }
                char** x12971 = x12270;
                x12971[x12949] = x12781;
                char** x12973 = x12272;
                x12973[x12949] = x12789;
                int* x12975 = x12274;
                x12975[x12949] = x12847;
                double* x12977 = x12276;
                x12977[x12949] = 0.0;
                x12268 = x12268 + 1;
                int x12980 = x12278;
                int x12981 = x12980 * 4;
                bool x12982 = x12981 > x12885;
                if (x12982) {
                  printf("%s\n","ERROR: hash.resize not implemented");
                } else {
                }
                x12988 = x12943;
              } else {
                x12988 = x12941;
              }
              char** x12989 = x12270;
              char* x12990 = x12989[x12988];
              char** x12991 = x12272;
              char* x12992 = x12991[x12988];
              int* x12993 = x12274;
              int x12994 = x12993[x12988];
              double* x12995 = x12276;
              double x12996 = x12995[x12988];
              x12989[x12988] = x12990;
              x12991[x12988] = x12992;
              x12993[x12988] = x12994;
              double x13000 = x12996 + x12856;
              x12995[x12988] = x13000;
            } else {
            }
          }
        } else {
        }
      }
    }
    printf("(((op(?) X SUPPLIER) X LINEITEM) X ORDERS): rightParent.next done\n");
    gettimeofday(&x11489, NULL);
    timeval_subtract(&x13020, &x11489, &x11488);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x13020.tv_sec * 1000) + (x13020.tv_usec/1000)));
    printf("(CUSTOMER X (((op(?) X SUPPLIER) X LINEITEM) X ORDERS)): rightParent.next done\n");
    gettimeofday(&x11495, NULL);
    timeval_subtract(&x13025, &x11495, &x11494);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x13025.tv_sec * 1000) + (x13025.tv_usec/1000)));
    int x13027 = x12268;
    int x11500;
    for(x11500=0; x11500 < x13027; x11500++) {
      char** x13028 = x12270;
      char* x13029 = x13028[x11500];
      char** x13030 = x12272;
      char* x13031 = x13030[x11500];
      int* x13032 = x12274;
      int x13033 = x13032[x11500];
      double* x13034 = x12276;
      double x13035 = x13034[x11500];
      struct Anon726278688* x13036 = (struct Anon726278688*)malloc(sizeof(struct Anon726278688));
      x13036->SUPP_NATION = x13029;
      x13036->CUST_NATION = x13031;
      x13036->L_YEAR = x13033;
      struct Anon2052879266* x13037 = (struct Anon2052879266*)malloc(sizeof(struct Anon2052879266));
      x13037->_0 = x13035;
      struct Anon949908027* x13038 = (struct Anon949908027*)malloc(sizeof(struct Anon949908027));
      x13038->key = x13036;
      x13038->aggs = x13037;
      g_tree_insert(x12089,x13038,x13038);; // x13039
    }
    for (;;) {
      int x13042 = g_tree_nnodes(x12089);
      bool x13043 = x13042 != 0;
      if (!x13043) break;
      struct Anon949908027* x13045 = NULL;
      g_tree_foreach(x12089, (GTraverseFunc)x13079, &x13045);
      g_tree_remove(x12089,x13045);
      if (x12090) {
      } else {
        struct Anon726278688* x13049 = x13045->key;;
        char* x13050 = x13049->SUPP_NATION;;
        char* x13051 = x13049->CUST_NATION;;
        int x13052 = x13049->L_YEAR;;
        struct Anon2052879266* x13053 = x13045->aggs;;
        double x13054 = x13053->_0;;
        printf("%s|%s|%d|%.4f\n",x13050,x13051,x13052,x13054);
        x12289 = x12289 + 1;
      }
    }
    int x13062 = x12289;
    printf("(%d rows)\n",x13062);
    gettimeofday(&x11538, NULL);
    timeval_subtract(&x13066, &x11538, &x11537);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x13066.tv_sec * 1000) + (x13066.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
