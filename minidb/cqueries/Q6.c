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
int main(int x8450, char** x8451) {
  long x8452 = 0L;
  long x6 = DEFAULT_INPUT_SIZE;
  long x8453 = x6;
  long x8454 = 0L;
  double* x8463 = (double*)malloc(x6 * sizeof(double));
  double* x8464 = x8463;
  double* x8465 = (double*)malloc(x6 * sizeof(double));
  double* x8466 = x8465;
  double* x8467 = (double*)malloc(x6 * sizeof(double));
  double* x8468 = x8467;
  long* x8475 = (long*)malloc(x6 * sizeof(long));
  long* x8476 = x8475;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  long x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    long x8487 = x8452;
    bool x8488 = x8487 < x3;
    if (!x8488) break;
    for (;;) {
      long x8492 = x8452;
      char x8493 = x4[x8492];
      bool x8494 = x8493 != '|';
      bool x8499 = x8494;
      if (x8494) {
        long x8495 = x8452;
        char x8496 = x4[x8495];
        bool x8497 = x8496 != '\n';
        x8499 = x8497;
      }
      bool x8500 = x8499;
      if (!x8500) break;
      x8452 = x8452 + 1;
    }
    x8452 = x8452 + 1;
    for (;;) {
      long x8516 = x8452;
      char x8517 = x4[x8516];
      bool x8518 = x8517 != '|';
      bool x8523 = x8518;
      if (x8518) {
        long x8519 = x8452;
        char x8520 = x4[x8519];
        bool x8521 = x8520 != '\n';
        x8523 = x8521;
      }
      bool x8524 = x8523;
      if (!x8524) break;
      x8452 = x8452 + 1;
    }
    x8452 = x8452 + 1;
    for (;;) {
      long x8540 = x8452;
      char x8541 = x4[x8540];
      bool x8542 = x8541 != '|';
      bool x8547 = x8542;
      if (x8542) {
        long x8543 = x8452;
        char x8544 = x4[x8543];
        bool x8545 = x8544 != '\n';
        x8547 = x8545;
      }
      bool x8548 = x8547;
      if (!x8548) break;
      x8452 = x8452 + 1;
    }
    x8452 = x8452 + 1;
    for (;;) {
      long x8564 = x8452;
      char x8565 = x4[x8564];
      bool x8566 = x8565 != '|';
      bool x8571 = x8566;
      if (x8566) {
        long x8567 = x8452;
        char x8568 = x4[x8567];
        bool x8569 = x8568 != '\n';
        x8571 = x8569;
      }
      bool x8572 = x8571;
      if (!x8572) break;
      x8452 = x8452 + 1;
    }
    x8452 = x8452 + 1;
    int x8587 = 0;
    int x8588 = 1;
    for (;;) {
      long x8589 = x8452;
      char x8590 = x4[x8589];
      bool x8591 = x8590 != '.';
      bool x8596 = x8591;
      if (x8591) {
        long x8592 = x8452;
        char x8593 = x4[x8592];
        bool x8594 = x8593 != '|';
        x8596 = x8594;
      }
      bool x8597 = x8596;
      bool x8602 = x8597;
      if (x8597) {
        long x8598 = x8452;
        char x8599 = x4[x8598];
        bool x8600 = x8599 != '\n';
        x8602 = x8600;
      }
      bool x8603 = x8602;
      if (!x8603) break;
      int x8605 = x8587;
      long x8607 = x8452;
      int x8606 = x8605 * 10;
      char x8608 = x4[x8607];
      char x8609 = x8608 - '0';
      int x8610 = x8606 + x8609;
      x8587 = x8610;
      x8452 = x8452 + 1;
    }
    long x8615 = x8452;
    char x8616 = x4[x8615];
    bool x8617 = x8616 == '.';
    if (x8617) {
      x8452 = x8452 + 1;
      for (;;) {
        long x8619 = x8452;
        char x8620 = x4[x8619];
        bool x8621 = x8620 != '|';
        bool x8626 = x8621;
        if (x8621) {
          long x8622 = x8452;
          char x8623 = x4[x8622];
          bool x8624 = x8623 != '\n';
          x8626 = x8624;
        }
        bool x8627 = x8626;
        if (!x8627) break;
        int x8629 = x8587;
        long x8631 = x8452;
        int x8630 = x8629 * 10;
        char x8632 = x4[x8631];
        char x8633 = x8632 - '0';
        int x8634 = x8630 + x8633;
        x8587 = x8634;
        int x8636 = x8588;
        int x8637 = x8636 * 10;
        x8588 = x8637;
        x8452 = x8452 + 1;
      }
    } else {
    }
    x8452 = x8452 + 1;
    int x8646 = x8587;
    int x8648 = x8588;
    int x8652 = 0;
    int x8653 = 1;
    for (;;) {
      long x8654 = x8452;
      char x8655 = x4[x8654];
      bool x8656 = x8655 != '.';
      bool x8661 = x8656;
      if (x8656) {
        long x8657 = x8452;
        char x8658 = x4[x8657];
        bool x8659 = x8658 != '|';
        x8661 = x8659;
      }
      bool x8662 = x8661;
      bool x8667 = x8662;
      if (x8662) {
        long x8663 = x8452;
        char x8664 = x4[x8663];
        bool x8665 = x8664 != '\n';
        x8667 = x8665;
      }
      bool x8668 = x8667;
      if (!x8668) break;
      int x8670 = x8652;
      long x8672 = x8452;
      int x8671 = x8670 * 10;
      char x8673 = x4[x8672];
      char x8674 = x8673 - '0';
      int x8675 = x8671 + x8674;
      x8652 = x8675;
      x8452 = x8452 + 1;
    }
    long x8680 = x8452;
    char x8681 = x4[x8680];
    bool x8682 = x8681 == '.';
    if (x8682) {
      x8452 = x8452 + 1;
      for (;;) {
        long x8684 = x8452;
        char x8685 = x4[x8684];
        bool x8686 = x8685 != '|';
        bool x8691 = x8686;
        if (x8686) {
          long x8687 = x8452;
          char x8688 = x4[x8687];
          bool x8689 = x8688 != '\n';
          x8691 = x8689;
        }
        bool x8692 = x8691;
        if (!x8692) break;
        int x8694 = x8652;
        long x8696 = x8452;
        int x8695 = x8694 * 10;
        char x8697 = x4[x8696];
        char x8698 = x8697 - '0';
        int x8699 = x8695 + x8698;
        x8652 = x8699;
        int x8701 = x8653;
        int x8702 = x8701 * 10;
        x8653 = x8702;
        x8452 = x8452 + 1;
      }
    } else {
    }
    x8452 = x8452 + 1;
    int x8711 = x8652;
    int x8713 = x8653;
    int x8717 = 0;
    int x8718 = 1;
    for (;;) {
      long x8719 = x8452;
      char x8720 = x4[x8719];
      bool x8721 = x8720 != '.';
      bool x8726 = x8721;
      if (x8721) {
        long x8722 = x8452;
        char x8723 = x4[x8722];
        bool x8724 = x8723 != '|';
        x8726 = x8724;
      }
      bool x8727 = x8726;
      bool x8732 = x8727;
      if (x8727) {
        long x8728 = x8452;
        char x8729 = x4[x8728];
        bool x8730 = x8729 != '\n';
        x8732 = x8730;
      }
      bool x8733 = x8732;
      if (!x8733) break;
      int x8735 = x8717;
      long x8737 = x8452;
      int x8736 = x8735 * 10;
      char x8738 = x4[x8737];
      char x8739 = x8738 - '0';
      int x8740 = x8736 + x8739;
      x8717 = x8740;
      x8452 = x8452 + 1;
    }
    long x8745 = x8452;
    char x8746 = x4[x8745];
    bool x8747 = x8746 == '.';
    if (x8747) {
      x8452 = x8452 + 1;
      for (;;) {
        long x8749 = x8452;
        char x8750 = x4[x8749];
        bool x8751 = x8750 != '|';
        bool x8756 = x8751;
        if (x8751) {
          long x8752 = x8452;
          char x8753 = x4[x8752];
          bool x8754 = x8753 != '\n';
          x8756 = x8754;
        }
        bool x8757 = x8756;
        if (!x8757) break;
        int x8759 = x8717;
        long x8761 = x8452;
        int x8760 = x8759 * 10;
        char x8762 = x4[x8761];
        char x8763 = x8762 - '0';
        int x8764 = x8760 + x8763;
        x8717 = x8764;
        int x8766 = x8718;
        int x8767 = x8766 * 10;
        x8718 = x8767;
        x8452 = x8452 + 1;
      }
    } else {
    }
    x8452 = x8452 + 1;
    int x8776 = x8717;
    int x8778 = x8718;
    for (;;) {
      long x8784 = x8452;
      char x8785 = x4[x8784];
      bool x8786 = x8785 != '.';
      bool x8791 = x8786;
      if (x8786) {
        long x8787 = x8452;
        char x8788 = x4[x8787];
        bool x8789 = x8788 != '|';
        x8791 = x8789;
      }
      bool x8792 = x8791;
      bool x8797 = x8792;
      if (x8792) {
        long x8793 = x8452;
        char x8794 = x4[x8793];
        bool x8795 = x8794 != '\n';
        x8797 = x8795;
      }
      bool x8798 = x8797;
      if (!x8798) break;
      x8452 = x8452 + 1;
    }
    long x8810 = x8452;
    char x8811 = x4[x8810];
    bool x8812 = x8811 == '.';
    if (x8812) {
      x8452 = x8452 + 1;
      for (;;) {
        long x8814 = x8452;
        char x8815 = x4[x8814];
        bool x8816 = x8815 != '|';
        bool x8821 = x8816;
        if (x8816) {
          long x8817 = x8452;
          char x8818 = x4[x8817];
          bool x8819 = x8818 != '\n';
          x8821 = x8819;
        }
        bool x8822 = x8821;
        if (!x8822) break;
        x8452 = x8452 + 1;
      }
    } else {
    }
    x8452 = x8452 + 1;
    x8452 = x8452 + 2;
    x8452 = x8452 + 2;
    int x8853 = 0;
    for (;;) {
      long x8854 = x8452;
      char x8855 = x4[x8854];
      bool x8856 = x8855 != '-';
      bool x8861 = x8856;
      if (x8856) {
        long x8857 = x8452;
        char x8858 = x4[x8857];
        bool x8859 = x8858 != '\n';
        x8861 = x8859;
      }
      bool x8862 = x8861;
      if (!x8862) break;
      int x8864 = x8853;
      long x8866 = x8452;
      int x8865 = x8864 * 10;
      char x8867 = x4[x8866];
      char x8868 = x8867 - '0';
      int x8869 = x8865 + x8868;
      x8853 = x8869;
      x8452 = x8452 + 1;
    }
    x8452 = x8452 + 1;
    int x8875 = x8853;
    int x8877 = 0;
    for (;;) {
      long x8878 = x8452;
      char x8879 = x4[x8878];
      bool x8880 = x8879 != '-';
      bool x8885 = x8880;
      if (x8880) {
        long x8881 = x8452;
        char x8882 = x4[x8881];
        bool x8883 = x8882 != '\n';
        x8885 = x8883;
      }
      bool x8886 = x8885;
      if (!x8886) break;
      int x8888 = x8877;
      long x8890 = x8452;
      int x8889 = x8888 * 10;
      char x8891 = x4[x8890];
      char x8892 = x8891 - '0';
      int x8893 = x8889 + x8892;
      x8877 = x8893;
      x8452 = x8452 + 1;
    }
    x8452 = x8452 + 1;
    int x8899 = x8877;
    int x8901 = 0;
    for (;;) {
      long x8902 = x8452;
      char x8903 = x4[x8902];
      bool x8904 = x8903 != '|';
      bool x8909 = x8904;
      if (x8904) {
        long x8905 = x8452;
        char x8906 = x4[x8905];
        bool x8907 = x8906 != '\n';
        x8909 = x8907;
      }
      bool x8910 = x8909;
      if (!x8910) break;
      int x8912 = x8901;
      long x8914 = x8452;
      int x8913 = x8912 * 10;
      char x8915 = x4[x8914];
      char x8916 = x8915 - '0';
      int x8917 = x8913 + x8916;
      x8901 = x8917;
      x8452 = x8452 + 1;
    }
    x8452 = x8452 + 1;
    int x8923 = x8901;
    for (;;) {
      long x8930 = x8452;
      char x8931 = x4[x8930];
      bool x8932 = x8931 != '-';
      bool x8937 = x8932;
      if (x8932) {
        long x8933 = x8452;
        char x8934 = x4[x8933];
        bool x8935 = x8934 != '\n';
        x8937 = x8935;
      }
      bool x8938 = x8937;
      if (!x8938) break;
      x8452 = x8452 + 1;
    }
    x8452 = x8452 + 1;
    for (;;) {
      long x8954 = x8452;
      char x8955 = x4[x8954];
      bool x8956 = x8955 != '-';
      bool x8961 = x8956;
      if (x8956) {
        long x8957 = x8452;
        char x8958 = x4[x8957];
        bool x8959 = x8958 != '\n';
        x8961 = x8959;
      }
      bool x8962 = x8961;
      if (!x8962) break;
      x8452 = x8452 + 1;
    }
    x8452 = x8452 + 1;
    for (;;) {
      long x8978 = x8452;
      char x8979 = x4[x8978];
      bool x8980 = x8979 != '|';
      bool x8985 = x8980;
      if (x8980) {
        long x8981 = x8452;
        char x8982 = x4[x8981];
        bool x8983 = x8982 != '\n';
        x8985 = x8983;
      }
      bool x8986 = x8985;
      if (!x8986) break;
      x8452 = x8452 + 1;
    }
    x8452 = x8452 + 1;
    for (;;) {
      long x9006 = x8452;
      char x9007 = x4[x9006];
      bool x9008 = x9007 != '-';
      bool x9013 = x9008;
      if (x9008) {
        long x9009 = x8452;
        char x9010 = x4[x9009];
        bool x9011 = x9010 != '\n';
        x9013 = x9011;
      }
      bool x9014 = x9013;
      if (!x9014) break;
      x8452 = x8452 + 1;
    }
    x8452 = x8452 + 1;
    for (;;) {
      long x9030 = x8452;
      char x9031 = x4[x9030];
      bool x9032 = x9031 != '-';
      bool x9037 = x9032;
      if (x9032) {
        long x9033 = x8452;
        char x9034 = x4[x9033];
        bool x9035 = x9034 != '\n';
        x9037 = x9035;
      }
      bool x9038 = x9037;
      if (!x9038) break;
      x8452 = x8452 + 1;
    }
    x8452 = x8452 + 1;
    for (;;) {
      long x9054 = x8452;
      char x9055 = x4[x9054];
      bool x9056 = x9055 != '|';
      bool x9061 = x9056;
      if (x9056) {
        long x9057 = x8452;
        char x9058 = x4[x9057];
        bool x9059 = x9058 != '\n';
        x9061 = x9059;
      }
      bool x9062 = x9061;
      if (!x9062) break;
      x8452 = x8452 + 1;
    }
    x8452 = x8452 + 1;
    for (;;) {
      long x9081 = x8452;
      char x9082 = x4[x9081];
      bool x9083 = x9082 != '|';
      bool x9088 = x9083;
      if (x9083) {
        long x9084 = x8452;
        char x9085 = x4[x9084];
        bool x9086 = x9085 != '\n';
        x9088 = x9086;
      }
      bool x9089 = x9088;
      if (!x9089) break;
      x8452 = x8452 + 1;
    }
    x8452 = x8452 + 1;
    for (;;) {
      long x9099 = x8452;
      char x9100 = x4[x9099];
      bool x9101 = x9100 != '|';
      bool x9106 = x9101;
      if (x9101) {
        long x9102 = x8452;
        char x9103 = x4[x9102];
        bool x9104 = x9103 != '\n';
        x9106 = x9104;
      }
      bool x9107 = x9106;
      if (!x9107) break;
      x8452 = x8452 + 1;
    }
    x8452 = x8452 + 1;
    for (;;) {
      long x9117 = x8452;
      char x9118 = x4[x9117];
      bool x9119 = x9118 != '|';
      bool x9124 = x9119;
      if (x9119) {
        long x9120 = x8452;
        char x9121 = x4[x9120];
        bool x9122 = x9121 != '\n';
        x9124 = x9122;
      }
      bool x9125 = x9124;
      if (!x9125) break;
      x8452 = x8452 + 1;
    }
    x8452 = x8452 + 1;
    long x9135 = x8454;
    long x9136 = x8453;
    bool x9137 = x9135 == x9136;
    if (x9137) {
      long x9138 = x9136 * 4L;
      x8453 = x9138;
      printf("buffer.resize %d\n",x9138);
      double* x9153 = x8464;
      double* x9154 = (double*)realloc(x9153,x9138 * sizeof(double));
      x8464 = x9154;
      double* x9156 = x8466;
      double* x9157 = (double*)realloc(x9156,x9138 * sizeof(double));
      x8466 = x9157;
      double* x9159 = x8468;
      double* x9160 = (double*)realloc(x9159,x9138 * sizeof(double));
      x8468 = x9160;
      long* x9171 = x8476;
      long* x9172 = (long*)realloc(x9171,x9138 * sizeof(long));
      x8476 = x9172;
    } else {
    }
    double* x9199 = x8464;
    double x8647 = (double)x8646;
    double x8649 = (double)x8648;
    double x8650 = x8647 / x8649;
    x9199[x9135] = x8650;
    double* x9201 = x8466;
    double x8712 = (double)x8711;
    double x8714 = (double)x8713;
    double x8715 = x8712 / x8714;
    x9201[x9135] = x8715;
    double* x9203 = x8468;
    double x8777 = (double)x8776;
    double x8779 = (double)x8778;
    double x8780 = x8777 / x8779;
    x9203[x9135] = x8780;
    long* x9211 = x8476;
    long x8924 = x8875 * 10000L;
    long x8925 = x8899 * 100L;
    long x8926 = x8924 + x8925;
    long x8927 = x8926 + x8923;
    x9211[x9135] = x8927;
    x8454 = x8454 + 1;
  }
  long x787 = DEFAULT_AGG_HASH_SIZE ;
  float x9301 = (float)24;
  double x9302 = (double)x9301;
  long x802 = x787 - 1L;
  char x9306 = "Total"[0L];
  long x9307 = x9306 * 41L;
  char x9308 = "Total"[1L];
  long x9309 = x9307 + x9308;
  long x9310 = x9309 * 41L;
  char x9311 = "Total"[2L];
  long x9312 = x9310 + x9311;
  long x9313 = x9312 * 41L;
  char x9314 = "Total"[3L];
  long x9315 = x9313 + x9314;
  long x9316 = x9315 & x802;
  bool x975 = true == false;
  int x9226;
  for(x9226=0; x9226 < 5; x9226++) {
    bool x9227 = false;
    long x9228 = 0L;
    struct Anon801061462* x9231 = (struct Anon801061462*)malloc(x787 * sizeof(struct Anon801061462));
    struct Anon801061462* x9232 = x9231;
    long x9233 = 0L;
    long* x9234 = (long*)malloc(x787 * sizeof(long));
    long x9235;
    for(x9235=0L; x9235 < x787; x9235++) {
      struct Anon801061462* x9236 = x9232;
      struct Anon801061462 x9237 = x9236[x9235];
      char* x9238 = x9237.key;;
      struct Anon2052879266 x9239 = x9237.aggs;;
      struct Anon801061462 x9240;
      x9240.exists = false;
      x9240.key = x9238;
      x9240.aggs = x9239;
      x9236[x9235] = x9240;
    }
    long x9245 = 0L;
    struct timeval x9403, x9404, x9405;
    gettimeofday(&x9403, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x9247 = x9227;
      bool x9248 = !x9247;
      bool x9253 = x9248;
      if (x9248) {
        long x9249 = x9228;
        long x9250 = x8454;
        bool x9251 = x9249 < x9250;
        x9253 = x9251;
      }
      bool x9254 = x9253;
      if (!x9254) break;
      long x9256 = x9228;
      double* x9265 = x8464;
      double x9266 = x9265[x9256];
      double* x9267 = x8466;
      double x9268 = x9267[x9256];
      double* x9269 = x8468;
      double x9270 = x9269[x9256];
      long* x9277 = x8476;
      long x9278 = x9277[x9256];
      x9228 = x9228 + 1;
      bool x9291 = x9278 >= 19960101L;
      bool x9293 = x9291;
      if (x9291) {
        bool x9292 = x9278 < 19970101L;
        x9293 = x9292;
      }
      bool x9294 = x9293;
      bool x9296 = x9294;
      if (x9294) {
        bool x9295 = x9270 >= 0.08;
        x9296 = x9295;
      }
      bool x9297 = x9296;
      bool x9299 = x9297;
      if (x9297) {
        bool x9298 = x9270 <= 0.1;
        x9299 = x9298;
      }
      bool x9300 = x9299;
      bool x9304 = x9300;
      if (x9300) {
        bool x9303 = x9266 < x9302;
        x9304 = x9303;
      }
      bool x9305 = x9304;
      if (x9305) {
        long x9317 = x9316;
        struct Anon801061462* x9318 = x9232;
        struct Anon801061462 x9319 = x9318[x9316];
        struct Anon801061462 x9320 = x9319;
        bool x9321 = x9319.exists;;
        bool x9326 = x9321;
        if (x9321) {
          struct Anon801061462 x9322 = x9320;
          char* x9323 = x9322.key;;
          bool x9324 = strcmp(x9323,"Total") == 0;;
          x9326 = x9324;
        }
        bool x9327 = x9326;
        if (x9327) {
          struct Anon2052879266 x9328 = x9319.aggs;;
          char* x9333 = x9319.key;;
          double x9329 = x9268 * x9270;
          double x9330 = x9328._0;;
          double x9331 = x9329 + x9330;
          struct Anon2052879266 x9332;
          x9332._0 = x9331;
          struct Anon801061462 x9334;
          x9334.exists = true;
          x9334.key = x9333;
          x9334.aggs = x9332;
          x9318[x9316] = x9334;
        } else {
          double x9329 = x9268 * x9270;
          struct Anon2052879266 x9363;
          x9363._0 = x9329;
          struct Anon801061462 x9364;
          x9364.exists = true;
          x9364.key = "Total";
          x9364.aggs = x9363;
          for (;;) {
            struct Anon801061462 x9337 = x9320;
            bool x9338 = x9337.exists;;
            bool x9373;
            if (x9338) {
              char* x9339 = x9337.key;;
              bool x9340 = strcmp(x9339,"Total") == 0;;
              bool x9360;
              if (x9340) {
                struct Anon2052879266 x9341 = x9337.aggs;;
                long x9345 = x9317;
                struct Anon801061462* x9347 = x9232;
                double x9342 = x9341._0;;
                double x9343 = x9329 + x9342;
                struct Anon2052879266 x9344;
                x9344._0 = x9343;
                struct Anon801061462 x9346;
                x9346.exists = true;
                x9346.key = x9339;
                x9346.aggs = x9344;
                x9347[x9345] = x9346;
                x9360 = false;
              } else {
                long x9350 = x9317;
                long x9351 = x9350 + 1L;
                long x9352 = x9351 % x802;
                x9317 = x9352;
                struct Anon801061462* x9354 = x9232;
                struct Anon801061462 x9355 = x9354[x9352];
                x9320 = x9355;
                x9360 = true;
              }
              x9373 = x9360;
            } else {
              long x9362 = x9317;
              struct Anon801061462* x9365 = x9232;
              x9365[x9362] = x9364;
              long x9367 = x9233;
              x9234[x9367] = x9362;
              x9233 = x9233 + 1L;
              x9373 = false;
            }
            if (!x9373) break;
          }
        }
      } else {
      }
    }
    long x9384 = x9233;
    long x9386;
    for(x9386=0L; x9386 < x9384; x9386++) {
      long x9387 = x9234[x9386];
      struct Anon801061462* x9388 = x9232;
      struct Anon801061462 x9389 = x9388[x9387];
      if (x975) {
      } else {
        struct Anon2052879266 x9392 = x9389.aggs;;
        double x9393 = x9392._0;;
        printf("%.4f\n",x9393);
        x9245 = x9245 + 1L;
      }
    }
    long x9400 = x9245;
    printf("(%d rows)\n",x9400);
    gettimeofday(&x9404, NULL);
    timeval_subtract(&x9405, &x9404, &x9403);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x9405.tv_sec * 1000) + (x9405.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
