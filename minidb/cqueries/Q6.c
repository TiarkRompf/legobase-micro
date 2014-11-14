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

/************************ MAIN BODY **************************/
int main(int x9246, char** x9247) {
  FILE* x9627 = fopen("../databases/sf2/lineitem.tbl", "r");
  int x9628 = 1048576;
  int x9629 = 0;
  double* x9638 = (double*)malloc(1048576 * sizeof(double));
  double* x9639 = x9638;
  double* x9640 = (double*)malloc(1048576 * sizeof(double));
  double* x9641 = x9640;
  double* x9642 = (double*)malloc(1048576 * sizeof(double));
  double* x9643 = x9642;
  long* x9650 = (long*)malloc(1048576 * sizeof(long));
  long* x9651 = x9650;
  for (;;) {
    bool x9662 = !feof(x9627);
    if (!x9662) break;
    int x9664 = 0;
    if (fscanf(x9627,"%d|",&x9664) == EOF) break;
    int x9665 = 0;
    if (fscanf(x9627,"%d|",&x9665) == EOF) break;
    int x9666 = 0;
    if (fscanf(x9627,"%d|",&x9666) == EOF) break;
    int x9667 = 0;
    if (fscanf(x9627,"%d|",&x9667) == EOF) break;
    double x9668 = 0.0;
    if (fscanf(x9627,"%lf|",&x9668) == EOF) break;
    double x9669 = 0.0;
    if (fscanf(x9627,"%lf|",&x9669) == EOF) break;
    double x9670 = 0.0;
    if (fscanf(x9627,"%lf|",&x9670) == EOF) break;
    double x9671 = 0.0;
    if (fscanf(x9627,"%lf|",&x9671) == EOF) break;
    char x9672 = ' ';
    if (fscanf(x9627,"%c|",&x9672) == EOF) break;
    char x9673 = ' ';
    if (fscanf(x9627,"%c|",&x9673) == EOF) break;
    int x9674 = 0;
    int x9675 = 0;
    int x9676 = 0;
    fscanf(x9627, "%d-%d-%d|",&x9674, &x9675, &x9676);
    long x9677 = (x9674 * 10000) + (x9675 * 100) + x9676;
    int x9678 = 0;
    int x9679 = 0;
    int x9680 = 0;
    fscanf(x9627, "%d-%d-%d|",&x9678, &x9679, &x9680);
    long x9681 = (x9678 * 10000) + (x9679 * 100) + x9680;
    int x9682 = 0;
    int x9683 = 0;
    int x9684 = 0;
    fscanf(x9627, "%d-%d-%d|",&x9682, &x9683, &x9684);
    long x9685 = (x9682 * 10000) + (x9683 * 100) + x9684;
    char* x9686 = (char*)malloc(26 * sizeof(char));
    int x9688 = 0;
    char x9687 = ' ';
    while (1) {
      fscanf(x9627,"%c",&x9687);
      if (x9687=='|' || x9687=='\n') break;
      if (x9688>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x9688); break;}
      ((char*)x9686)[x9688] = x9687;
      x9688 += 1;
    }
    ((char*)x9686)[x9688] = '\0';
    char* x9691 = (char*)malloc(11 * sizeof(char));
    int x9693 = 0;
    char x9692 = ' ';
    while (1) {
      fscanf(x9627,"%c",&x9692);
      if (x9692=='|' || x9692=='\n') break;
      if (x9693>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x9693); break;}
      ((char*)x9691)[x9693] = x9692;
      x9693 += 1;
    }
    ((char*)x9691)[x9693] = '\0';
    char* x9696 = (char*)malloc(45 * sizeof(char));
    int x9698 = 0;
    char x9697 = ' ';
    while (1) {
      fscanf(x9627,"%c",&x9697);
      if (x9697=='|' || x9697=='\n') break;
      if (x9698>=44) { printf("ERROR: scanner.nextString reading past end of buffer %d",x9698); break;}
      ((char*)x9696)[x9698] = x9697;
      x9698 += 1;
    }
    ((char*)x9696)[x9698] = '\0';
    int x9701 = x9629;
    int x9702 = x9628;
    bool x9703 = x9701 == x9702;
    if (x9703) {
      int x9704 = x9702 * 4;
      x9628 = x9704;
      printf("buffer.resize %d\n",x9704);
      double* x9719 = x9639;
      double* x9720 = (double*)realloc(x9719,x9704 * sizeof(double));
      x9639 = x9720;
      double* x9722 = x9641;
      double* x9723 = (double*)realloc(x9722,x9704 * sizeof(double));
      x9641 = x9723;
      double* x9725 = x9643;
      double* x9726 = (double*)realloc(x9725,x9704 * sizeof(double));
      x9643 = x9726;
      long* x9737 = x9651;
      long* x9738 = (long*)realloc(x9737,x9704 * sizeof(long));
      x9651 = x9738;
    } else {
    }
    double* x9765 = x9639;
    x9765[x9701] = x9668;
    double* x9767 = x9641;
    x9767[x9701] = x9669;
    double* x9769 = x9643;
    x9769[x9701] = x9670;
    long* x9777 = x9651;
    x9777[x9701] = x9677;
    x9629 = x9629 + 1;
  }
  bool x9793 = true == false;
  float x9493 = (float)24;
  double x9494 = (double)x9493;
  char x9501 = "Total"[0];
  int x9502 = x9501 * 2;
  int x9503 = x9502 * 3;
  int x9414;
  for(x9414=0; x9414 < 1; x9414++) {
    bool x9794 = false;
    int x9795 = 0;
    int x9798 = 1048576;
    int x9799 = 0;
    char** x9800 = (char**)malloc(1048576 * sizeof(char*));
    char** x9801 = x9800;
    double* x9802 = (double*)malloc(1048576 * sizeof(double));
    double* x9803 = x9802;
    int x9804 = 4194304;
    int x9805 = 0;
    int* x9806 = (int*)malloc(4194304 * sizeof(int));
    int* x9807 = x9806;
    int x9429;
    for(x9429=0; x9429 < 4194304; x9429++) {
      int* x9808 = x9807;
      x9808[x9429] = -1;
    }
    int x9815 = 0;
    struct timeval x9620, x9621, x9988;
    gettimeofday(&x9620, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x9817 = x9794;
      bool x9818 = !x9817;
      bool x9823 = x9818;
      if (x9818) {
        int x9819 = x9795;
        int x9820 = x9629;
        bool x9821 = x9819 < x9820;
        x9823 = x9821;
      }
      bool x9824 = x9823;
      if (!x9824) break;
      int x9827 = x9795;
      double* x9836 = x9639;
      double x9837 = x9836[x9827];
      double* x9838 = x9641;
      double x9839 = x9838[x9827];
      double* x9840 = x9643;
      double x9841 = x9840[x9827];
      long* x9848 = x9651;
      long x9849 = x9848[x9827];
      x9795 = x9795 + 1;
      bool x9861 = x9849 >= 19960101L;
      bool x9863 = x9861;
      if (x9861) {
        bool x9862 = x9849 < 19970101L;
        x9863 = x9862;
      }
      bool x9864 = x9863;
      bool x9866 = x9864;
      if (x9864) {
        bool x9865 = x9841 >= 0.08;
        x9866 = x9865;
      }
      bool x9867 = x9866;
      bool x9869 = x9867;
      if (x9867) {
        bool x9868 = x9841 <= 0.1;
        x9869 = x9868;
      }
      bool x9870 = x9869;
      bool x9872 = x9870;
      if (x9870) {
        bool x9871 = x9837 < x9494;
        x9872 = x9871;
      }
      bool x9873 = x9872;
      if (x9873) {
        int x9875 = x9804;
        int x9876 = x9875 - 1;
        int x9877 = x9503 & x9876;
        int x9878 = x9877;
        int* x9879 = x9807;
        int x9880 = x9879[x9877];
        int x9881 = x9880;
        int x9882 = x9877 + 1;
        int x9883 = x9879[x9882];
        int x9884 = x9883;
        for (;;) {
          int x9885 = x9881;
          bool x9886 = x9885 != -1;
          bool x9902 = x9886;
          if (x9886) {
            int x9887 = x9884;
            bool x9888 = x9887 != x9503;
            bool x9898 = x9888;
            if (x9888 == false) {
              int x9889 = x9881;
              char** x9890 = x9801;
              char* x9891 = x9890[x9889];
              bool x9894 = strcmp(x9891,"Total") == 0;;
              bool x9895 = !x9894;
              x9898 = x9895;
            }
            bool x9899 = x9898;
            x9902 = x9899;
          }
          bool x9903 = x9902;
          if (!x9903) break;
          int x9906 = x9878;
          int x9907 = x9906 + 2;
          int x9908 = x9907 & x9876;
          x9878 = x9908;
          int* x9910 = x9807;
          int x9911 = x9910[x9908];
          x9881 = x9911;
          int x9913 = x9908 + 1;
          int x9914 = x9910[x9913];
          x9884 = x9914;
        }
        int x9919 = x9881;
        bool x9920 = x9919 == -1;
        int x9955;
        if (x9920) {
          int x9921 = x9805;
          int x9922 = x9878;
          x9879[x9922] = x9921;
          int x9924 = x9922 + 1;
          x9879[x9924] = x9503;
          x9805 = x9805 + 1;
          int x9927 = x9799;
          int x9928 = x9798;
          bool x9929 = x9927 == x9928;
          if (x9929) {
            int x9930 = x9928 * 4;
            x9798 = x9930;
            printf("buffer.resize %d\n",x9930);
            char** x9933 = x9801;
            char** x9934 = (char**)realloc(x9933,x9930 * sizeof(char*));
            x9801 = x9934;
            printf("buffer.resize %d\n",x9930);
            double* x9937 = x9803;
            double* x9938 = (double*)realloc(x9937,x9930 * sizeof(double));
            x9803 = x9938;
          } else {
          }
          char** x9942 = x9801;
          x9942[x9927] = "Total";
          double* x9944 = x9803;
          x9944[x9927] = 0.0;
          x9799 = x9799 + 1;
          int x9947 = x9805;
          int x9948 = x9947 * 4;
          bool x9949 = x9948 > x9875;
          if (x9949) {
            printf("%s\n","ERROR: hash.resize not implemented");
          } else {
          }
          x9955 = x9921;
        } else {
          x9955 = x9919;
        }
        char** x9956 = x9801;
        char* x9957 = x9956[x9955];
        double* x9958 = x9803;
        double x9959 = x9958[x9955];
        x9956[x9955] = x9957;
        double x9961 = x9839 * x9841;
        double x9962 = x9961 + x9959;
        x9958[x9955] = x9962;
      } else {
      }
    }
    int x9970 = x9799;
    int x9602;
    for(x9602=0; x9602 < x9970; x9602++) {
      double* x9973 = x9803;
      double x9974 = x9973[x9602];
      if (x9793) {
      } else {
        printf("%.4f\n",x9974);
        x9815 = x9815 + 1;
      }
    }
    int x9984 = x9815;
    printf("(%d rows)\n",x9984);
    gettimeofday(&x9621, NULL);
    timeval_subtract(&x9988, &x9621, &x9620);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x9988.tv_sec * 1000) + (x9988.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
