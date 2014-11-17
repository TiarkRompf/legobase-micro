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
int main(int x8446, char** x8447) {
  int x8448 = 0;
  int x8449 = 1048576;
  int x8450 = 0;
  double* x8459 = (double*)malloc(1048576 * sizeof(double));
  double* x8460 = x8459;
  double* x8461 = (double*)malloc(1048576 * sizeof(double));
  double* x8462 = x8461;
  double* x8463 = (double*)malloc(1048576 * sizeof(double));
  double* x8464 = x8463;
  long* x8471 = (long*)malloc(1048576 * sizeof(long));
  long* x8472 = x8471;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  int x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    int x8483 = x8448;
    bool x8484 = x8483 < x3;
    if (!x8484) break;
    for (;;) {
      int x8488 = x8448;
      char x8489 = x4[x8488];
      bool x8490 = x8489 != '|';
      bool x8495 = x8490;
      if (x8490) {
        int x8491 = x8448;
        char x8492 = x4[x8491];
        bool x8493 = x8492 != '\n';
        x8495 = x8493;
      }
      bool x8496 = x8495;
      if (!x8496) break;
      x8448 = x8448 + 1;
    }
    x8448 = x8448 + 1;
    for (;;) {
      int x8512 = x8448;
      char x8513 = x4[x8512];
      bool x8514 = x8513 != '|';
      bool x8519 = x8514;
      if (x8514) {
        int x8515 = x8448;
        char x8516 = x4[x8515];
        bool x8517 = x8516 != '\n';
        x8519 = x8517;
      }
      bool x8520 = x8519;
      if (!x8520) break;
      x8448 = x8448 + 1;
    }
    x8448 = x8448 + 1;
    for (;;) {
      int x8536 = x8448;
      char x8537 = x4[x8536];
      bool x8538 = x8537 != '|';
      bool x8543 = x8538;
      if (x8538) {
        int x8539 = x8448;
        char x8540 = x4[x8539];
        bool x8541 = x8540 != '\n';
        x8543 = x8541;
      }
      bool x8544 = x8543;
      if (!x8544) break;
      x8448 = x8448 + 1;
    }
    x8448 = x8448 + 1;
    for (;;) {
      int x8560 = x8448;
      char x8561 = x4[x8560];
      bool x8562 = x8561 != '|';
      bool x8567 = x8562;
      if (x8562) {
        int x8563 = x8448;
        char x8564 = x4[x8563];
        bool x8565 = x8564 != '\n';
        x8567 = x8565;
      }
      bool x8568 = x8567;
      if (!x8568) break;
      x8448 = x8448 + 1;
    }
    x8448 = x8448 + 1;
    int x8583 = 0;
    int x8584 = 1;
    for (;;) {
      int x8585 = x8448;
      char x8586 = x4[x8585];
      bool x8587 = x8586 != '.';
      bool x8592 = x8587;
      if (x8587) {
        int x8588 = x8448;
        char x8589 = x4[x8588];
        bool x8590 = x8589 != '|';
        x8592 = x8590;
      }
      bool x8593 = x8592;
      bool x8598 = x8593;
      if (x8593) {
        int x8594 = x8448;
        char x8595 = x4[x8594];
        bool x8596 = x8595 != '\n';
        x8598 = x8596;
      }
      bool x8599 = x8598;
      if (!x8599) break;
      int x8601 = x8583;
      int x8603 = x8448;
      int x8602 = x8601 * 10;
      char x8604 = x4[x8603];
      char x8605 = x8604 - '0';
      int x8606 = x8602 + x8605;
      x8583 = x8606;
      x8448 = x8448 + 1;
    }
    int x8611 = x8448;
    char x8612 = x4[x8611];
    bool x8613 = x8612 == '.';
    if (x8613) {
      x8448 = x8448 + 1;
      for (;;) {
        int x8615 = x8448;
        char x8616 = x4[x8615];
        bool x8617 = x8616 != '|';
        bool x8622 = x8617;
        if (x8617) {
          int x8618 = x8448;
          char x8619 = x4[x8618];
          bool x8620 = x8619 != '\n';
          x8622 = x8620;
        }
        bool x8623 = x8622;
        if (!x8623) break;
        int x8625 = x8583;
        int x8627 = x8448;
        int x8626 = x8625 * 10;
        char x8628 = x4[x8627];
        char x8629 = x8628 - '0';
        int x8630 = x8626 + x8629;
        x8583 = x8630;
        int x8632 = x8584;
        int x8633 = x8632 * 10;
        x8584 = x8633;
        x8448 = x8448 + 1;
      }
    } else {
    }
    x8448 = x8448 + 1;
    int x8642 = x8583;
    int x8644 = x8584;
    int x8648 = 0;
    int x8649 = 1;
    for (;;) {
      int x8650 = x8448;
      char x8651 = x4[x8650];
      bool x8652 = x8651 != '.';
      bool x8657 = x8652;
      if (x8652) {
        int x8653 = x8448;
        char x8654 = x4[x8653];
        bool x8655 = x8654 != '|';
        x8657 = x8655;
      }
      bool x8658 = x8657;
      bool x8663 = x8658;
      if (x8658) {
        int x8659 = x8448;
        char x8660 = x4[x8659];
        bool x8661 = x8660 != '\n';
        x8663 = x8661;
      }
      bool x8664 = x8663;
      if (!x8664) break;
      int x8666 = x8648;
      int x8668 = x8448;
      int x8667 = x8666 * 10;
      char x8669 = x4[x8668];
      char x8670 = x8669 - '0';
      int x8671 = x8667 + x8670;
      x8648 = x8671;
      x8448 = x8448 + 1;
    }
    int x8676 = x8448;
    char x8677 = x4[x8676];
    bool x8678 = x8677 == '.';
    if (x8678) {
      x8448 = x8448 + 1;
      for (;;) {
        int x8680 = x8448;
        char x8681 = x4[x8680];
        bool x8682 = x8681 != '|';
        bool x8687 = x8682;
        if (x8682) {
          int x8683 = x8448;
          char x8684 = x4[x8683];
          bool x8685 = x8684 != '\n';
          x8687 = x8685;
        }
        bool x8688 = x8687;
        if (!x8688) break;
        int x8690 = x8648;
        int x8692 = x8448;
        int x8691 = x8690 * 10;
        char x8693 = x4[x8692];
        char x8694 = x8693 - '0';
        int x8695 = x8691 + x8694;
        x8648 = x8695;
        int x8697 = x8649;
        int x8698 = x8697 * 10;
        x8649 = x8698;
        x8448 = x8448 + 1;
      }
    } else {
    }
    x8448 = x8448 + 1;
    int x8707 = x8648;
    int x8709 = x8649;
    int x8713 = 0;
    int x8714 = 1;
    for (;;) {
      int x8715 = x8448;
      char x8716 = x4[x8715];
      bool x8717 = x8716 != '.';
      bool x8722 = x8717;
      if (x8717) {
        int x8718 = x8448;
        char x8719 = x4[x8718];
        bool x8720 = x8719 != '|';
        x8722 = x8720;
      }
      bool x8723 = x8722;
      bool x8728 = x8723;
      if (x8723) {
        int x8724 = x8448;
        char x8725 = x4[x8724];
        bool x8726 = x8725 != '\n';
        x8728 = x8726;
      }
      bool x8729 = x8728;
      if (!x8729) break;
      int x8731 = x8713;
      int x8733 = x8448;
      int x8732 = x8731 * 10;
      char x8734 = x4[x8733];
      char x8735 = x8734 - '0';
      int x8736 = x8732 + x8735;
      x8713 = x8736;
      x8448 = x8448 + 1;
    }
    int x8741 = x8448;
    char x8742 = x4[x8741];
    bool x8743 = x8742 == '.';
    if (x8743) {
      x8448 = x8448 + 1;
      for (;;) {
        int x8745 = x8448;
        char x8746 = x4[x8745];
        bool x8747 = x8746 != '|';
        bool x8752 = x8747;
        if (x8747) {
          int x8748 = x8448;
          char x8749 = x4[x8748];
          bool x8750 = x8749 != '\n';
          x8752 = x8750;
        }
        bool x8753 = x8752;
        if (!x8753) break;
        int x8755 = x8713;
        int x8757 = x8448;
        int x8756 = x8755 * 10;
        char x8758 = x4[x8757];
        char x8759 = x8758 - '0';
        int x8760 = x8756 + x8759;
        x8713 = x8760;
        int x8762 = x8714;
        int x8763 = x8762 * 10;
        x8714 = x8763;
        x8448 = x8448 + 1;
      }
    } else {
    }
    x8448 = x8448 + 1;
    int x8772 = x8713;
    int x8774 = x8714;
    for (;;) {
      int x8780 = x8448;
      char x8781 = x4[x8780];
      bool x8782 = x8781 != '.';
      bool x8787 = x8782;
      if (x8782) {
        int x8783 = x8448;
        char x8784 = x4[x8783];
        bool x8785 = x8784 != '|';
        x8787 = x8785;
      }
      bool x8788 = x8787;
      bool x8793 = x8788;
      if (x8788) {
        int x8789 = x8448;
        char x8790 = x4[x8789];
        bool x8791 = x8790 != '\n';
        x8793 = x8791;
      }
      bool x8794 = x8793;
      if (!x8794) break;
      x8448 = x8448 + 1;
    }
    int x8806 = x8448;
    char x8807 = x4[x8806];
    bool x8808 = x8807 == '.';
    if (x8808) {
      x8448 = x8448 + 1;
      for (;;) {
        int x8810 = x8448;
        char x8811 = x4[x8810];
        bool x8812 = x8811 != '|';
        bool x8817 = x8812;
        if (x8812) {
          int x8813 = x8448;
          char x8814 = x4[x8813];
          bool x8815 = x8814 != '\n';
          x8817 = x8815;
        }
        bool x8818 = x8817;
        if (!x8818) break;
        x8448 = x8448 + 1;
      }
    } else {
    }
    x8448 = x8448 + 1;
    x8448 = x8448 + 2;
    x8448 = x8448 + 2;
    int x8849 = 0;
    for (;;) {
      int x8850 = x8448;
      char x8851 = x4[x8850];
      bool x8852 = x8851 != '-';
      bool x8857 = x8852;
      if (x8852) {
        int x8853 = x8448;
        char x8854 = x4[x8853];
        bool x8855 = x8854 != '\n';
        x8857 = x8855;
      }
      bool x8858 = x8857;
      if (!x8858) break;
      int x8860 = x8849;
      int x8862 = x8448;
      int x8861 = x8860 * 10;
      char x8863 = x4[x8862];
      char x8864 = x8863 - '0';
      int x8865 = x8861 + x8864;
      x8849 = x8865;
      x8448 = x8448 + 1;
    }
    x8448 = x8448 + 1;
    int x8871 = x8849;
    int x8873 = 0;
    for (;;) {
      int x8874 = x8448;
      char x8875 = x4[x8874];
      bool x8876 = x8875 != '-';
      bool x8881 = x8876;
      if (x8876) {
        int x8877 = x8448;
        char x8878 = x4[x8877];
        bool x8879 = x8878 != '\n';
        x8881 = x8879;
      }
      bool x8882 = x8881;
      if (!x8882) break;
      int x8884 = x8873;
      int x8886 = x8448;
      int x8885 = x8884 * 10;
      char x8887 = x4[x8886];
      char x8888 = x8887 - '0';
      int x8889 = x8885 + x8888;
      x8873 = x8889;
      x8448 = x8448 + 1;
    }
    x8448 = x8448 + 1;
    int x8895 = x8873;
    int x8897 = 0;
    for (;;) {
      int x8898 = x8448;
      char x8899 = x4[x8898];
      bool x8900 = x8899 != '|';
      bool x8905 = x8900;
      if (x8900) {
        int x8901 = x8448;
        char x8902 = x4[x8901];
        bool x8903 = x8902 != '\n';
        x8905 = x8903;
      }
      bool x8906 = x8905;
      if (!x8906) break;
      int x8908 = x8897;
      int x8910 = x8448;
      int x8909 = x8908 * 10;
      char x8911 = x4[x8910];
      char x8912 = x8911 - '0';
      int x8913 = x8909 + x8912;
      x8897 = x8913;
      x8448 = x8448 + 1;
    }
    x8448 = x8448 + 1;
    int x8919 = x8897;
    for (;;) {
      int x8926 = x8448;
      char x8927 = x4[x8926];
      bool x8928 = x8927 != '-';
      bool x8933 = x8928;
      if (x8928) {
        int x8929 = x8448;
        char x8930 = x4[x8929];
        bool x8931 = x8930 != '\n';
        x8933 = x8931;
      }
      bool x8934 = x8933;
      if (!x8934) break;
      x8448 = x8448 + 1;
    }
    x8448 = x8448 + 1;
    for (;;) {
      int x8950 = x8448;
      char x8951 = x4[x8950];
      bool x8952 = x8951 != '-';
      bool x8957 = x8952;
      if (x8952) {
        int x8953 = x8448;
        char x8954 = x4[x8953];
        bool x8955 = x8954 != '\n';
        x8957 = x8955;
      }
      bool x8958 = x8957;
      if (!x8958) break;
      x8448 = x8448 + 1;
    }
    x8448 = x8448 + 1;
    for (;;) {
      int x8974 = x8448;
      char x8975 = x4[x8974];
      bool x8976 = x8975 != '|';
      bool x8981 = x8976;
      if (x8976) {
        int x8977 = x8448;
        char x8978 = x4[x8977];
        bool x8979 = x8978 != '\n';
        x8981 = x8979;
      }
      bool x8982 = x8981;
      if (!x8982) break;
      x8448 = x8448 + 1;
    }
    x8448 = x8448 + 1;
    for (;;) {
      int x9002 = x8448;
      char x9003 = x4[x9002];
      bool x9004 = x9003 != '-';
      bool x9009 = x9004;
      if (x9004) {
        int x9005 = x8448;
        char x9006 = x4[x9005];
        bool x9007 = x9006 != '\n';
        x9009 = x9007;
      }
      bool x9010 = x9009;
      if (!x9010) break;
      x8448 = x8448 + 1;
    }
    x8448 = x8448 + 1;
    for (;;) {
      int x9026 = x8448;
      char x9027 = x4[x9026];
      bool x9028 = x9027 != '-';
      bool x9033 = x9028;
      if (x9028) {
        int x9029 = x8448;
        char x9030 = x4[x9029];
        bool x9031 = x9030 != '\n';
        x9033 = x9031;
      }
      bool x9034 = x9033;
      if (!x9034) break;
      x8448 = x8448 + 1;
    }
    x8448 = x8448 + 1;
    for (;;) {
      int x9050 = x8448;
      char x9051 = x4[x9050];
      bool x9052 = x9051 != '|';
      bool x9057 = x9052;
      if (x9052) {
        int x9053 = x8448;
        char x9054 = x4[x9053];
        bool x9055 = x9054 != '\n';
        x9057 = x9055;
      }
      bool x9058 = x9057;
      if (!x9058) break;
      x8448 = x8448 + 1;
    }
    x8448 = x8448 + 1;
    for (;;) {
      int x9077 = x8448;
      char x9078 = x4[x9077];
      bool x9079 = x9078 != '|';
      bool x9084 = x9079;
      if (x9079) {
        int x9080 = x8448;
        char x9081 = x4[x9080];
        bool x9082 = x9081 != '\n';
        x9084 = x9082;
      }
      bool x9085 = x9084;
      if (!x9085) break;
      x8448 = x8448 + 1;
    }
    x8448 = x8448 + 1;
    for (;;) {
      int x9095 = x8448;
      char x9096 = x4[x9095];
      bool x9097 = x9096 != '|';
      bool x9102 = x9097;
      if (x9097) {
        int x9098 = x8448;
        char x9099 = x4[x9098];
        bool x9100 = x9099 != '\n';
        x9102 = x9100;
      }
      bool x9103 = x9102;
      if (!x9103) break;
      x8448 = x8448 + 1;
    }
    x8448 = x8448 + 1;
    for (;;) {
      int x9113 = x8448;
      char x9114 = x4[x9113];
      bool x9115 = x9114 != '|';
      bool x9120 = x9115;
      if (x9115) {
        int x9116 = x8448;
        char x9117 = x4[x9116];
        bool x9118 = x9117 != '\n';
        x9120 = x9118;
      }
      bool x9121 = x9120;
      if (!x9121) break;
      x8448 = x8448 + 1;
    }
    x8448 = x8448 + 1;
    int x9131 = x8450;
    int x9132 = x8449;
    bool x9133 = x9131 == x9132;
    if (x9133) {
      int x9134 = x9132 * 4;
      x8449 = x9134;
      printf("buffer.resize %d\n",x9134);
      double* x9149 = x8460;
      double* x9150 = (double*)realloc(x9149,x9134 * sizeof(double));
      x8460 = x9150;
      double* x9152 = x8462;
      double* x9153 = (double*)realloc(x9152,x9134 * sizeof(double));
      x8462 = x9153;
      double* x9155 = x8464;
      double* x9156 = (double*)realloc(x9155,x9134 * sizeof(double));
      x8464 = x9156;
      long* x9167 = x8472;
      long* x9168 = (long*)realloc(x9167,x9134 * sizeof(long));
      x8472 = x9168;
    } else {
    }
    double* x9195 = x8460;
    double x8643 = (double)x8642;
    double x8645 = (double)x8644;
    double x8646 = x8643 / x8645;
    x9195[x9131] = x8646;
    double* x9197 = x8462;
    double x8708 = (double)x8707;
    double x8710 = (double)x8709;
    double x8711 = x8708 / x8710;
    x9197[x9131] = x8711;
    double* x9199 = x8464;
    double x8773 = (double)x8772;
    double x8775 = (double)x8774;
    double x8776 = x8773 / x8775;
    x9199[x9131] = x8776;
    long* x9207 = x8472;
    long x8920 = x8871 * 10000L;
    long x8921 = x8895 * 100L;
    long x8922 = x8920 + x8921;
    long x8923 = x8922 + x8919;
    x9207[x9131] = x8923;
    x8450 = x8450 + 1;
  }
  float x9297 = (float)24;
  double x9298 = (double)x9297;
  char x9302 = "Total"[0];
  int x9303 = x9302 * 41;
  char x9304 = "Total"[1];
  int x9305 = x9303 + x9304;
  int x9306 = x9305 * 41;
  char x9307 = "Total"[2];
  int x9308 = x9306 + x9307;
  int x9309 = x9308 * 41;
  char x9310 = "Total"[3];
  int x9311 = x9309 + x9310;
  int x9312 = x9311 & 16777215;
  bool x972 = true == false;
  int x9222;
  for(x9222=0; x9222 < 5; x9222++) {
    bool x9223 = false;
    int x9224 = 0;
    struct Anon1007729034* x9227 = (struct Anon1007729034*)malloc(16777216 * sizeof(struct Anon1007729034));
    struct Anon1007729034* x9228 = x9227;
    int x9229 = 0;
    int* x9230 = (int*)malloc(16777216 * sizeof(int));
    int x9231;
    for(x9231=0; x9231 < 16777216; x9231++) {
      struct Anon1007729034* x9232 = x9228;
      struct Anon1007729034 x9233 = x9232[x9231];
      char* x9234 = x9233.key;;
      struct Anon2052879266 x9235 = x9233.aggs;;
      struct Anon1007729034 x9236;
      x9236.exists = false;
      x9236.key = x9234;
      x9236.aggs = x9235;
      x9232[x9231] = x9236;
    }
    int x9241 = 0;
    struct timeval x9399, x9400, x9401;
    gettimeofday(&x9399, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x9243 = x9223;
      bool x9244 = !x9243;
      bool x9249 = x9244;
      if (x9244) {
        int x9245 = x9224;
        int x9246 = x8450;
        bool x9247 = x9245 < x9246;
        x9249 = x9247;
      }
      bool x9250 = x9249;
      if (!x9250) break;
      int x9252 = x9224;
      double* x9261 = x8460;
      double x9262 = x9261[x9252];
      double* x9263 = x8462;
      double x9264 = x9263[x9252];
      double* x9265 = x8464;
      double x9266 = x9265[x9252];
      long* x9273 = x8472;
      long x9274 = x9273[x9252];
      x9224 = x9224 + 1;
      bool x9287 = x9274 >= 19960101L;
      bool x9289 = x9287;
      if (x9287) {
        bool x9288 = x9274 < 19970101L;
        x9289 = x9288;
      }
      bool x9290 = x9289;
      bool x9292 = x9290;
      if (x9290) {
        bool x9291 = x9266 >= 0.08;
        x9292 = x9291;
      }
      bool x9293 = x9292;
      bool x9295 = x9293;
      if (x9293) {
        bool x9294 = x9266 <= 0.1;
        x9295 = x9294;
      }
      bool x9296 = x9295;
      bool x9300 = x9296;
      if (x9296) {
        bool x9299 = x9262 < x9298;
        x9300 = x9299;
      }
      bool x9301 = x9300;
      if (x9301) {
        int x9313 = x9312;
        struct Anon1007729034* x9314 = x9228;
        struct Anon1007729034 x9315 = x9314[x9312];
        struct Anon1007729034 x9316 = x9315;
        bool x9317 = x9315.exists;;
        bool x9322 = x9317;
        if (x9317) {
          struct Anon1007729034 x9318 = x9316;
          char* x9319 = x9318.key;;
          bool x9320 = strcmp(x9319,"Total") == 0;;
          x9322 = x9320;
        }
        bool x9323 = x9322;
        if (x9323) {
          struct Anon2052879266 x9324 = x9315.aggs;;
          char* x9329 = x9315.key;;
          double x9325 = x9264 * x9266;
          double x9326 = x9324._0;;
          double x9327 = x9325 + x9326;
          struct Anon2052879266 x9328;
          x9328._0 = x9327;
          struct Anon1007729034 x9330;
          x9330.exists = true;
          x9330.key = x9329;
          x9330.aggs = x9328;
          x9314[x9312] = x9330;
        } else {
          double x9325 = x9264 * x9266;
          struct Anon2052879266 x9359;
          x9359._0 = x9325;
          struct Anon1007729034 x9360;
          x9360.exists = true;
          x9360.key = "Total";
          x9360.aggs = x9359;
          for (;;) {
            struct Anon1007729034 x9333 = x9316;
            bool x9334 = x9333.exists;;
            bool x9369;
            if (x9334) {
              char* x9335 = x9333.key;;
              bool x9336 = strcmp(x9335,"Total") == 0;;
              bool x9356;
              if (x9336) {
                struct Anon2052879266 x9337 = x9333.aggs;;
                int x9341 = x9313;
                struct Anon1007729034* x9343 = x9228;
                double x9338 = x9337._0;;
                double x9339 = x9325 + x9338;
                struct Anon2052879266 x9340;
                x9340._0 = x9339;
                struct Anon1007729034 x9342;
                x9342.exists = true;
                x9342.key = x9335;
                x9342.aggs = x9340;
                x9343[x9341] = x9342;
                x9356 = false;
              } else {
                int x9346 = x9313;
                int x9347 = x9346 + 1;
                int x9348 = x9347 % 16777215;
                x9313 = x9348;
                struct Anon1007729034* x9350 = x9228;
                struct Anon1007729034 x9351 = x9350[x9348];
                x9316 = x9351;
                x9356 = true;
              }
              x9369 = x9356;
            } else {
              int x9358 = x9313;
              struct Anon1007729034* x9361 = x9228;
              x9361[x9358] = x9360;
              int x9363 = x9229;
              x9230[x9363] = x9358;
              x9229 = x9229 + 1;
              x9369 = false;
            }
            if (!x9369) break;
          }
        }
      } else {
      }
    }
    int x9380 = x9229;
    int x9382;
    for(x9382=0; x9382 < x9380; x9382++) {
      int x9383 = x9230[x9382];
      struct Anon1007729034* x9384 = x9228;
      struct Anon1007729034 x9385 = x9384[x9383];
      if (x972) {
      } else {
        struct Anon2052879266 x9388 = x9385.aggs;;
        double x9389 = x9388._0;;
        printf("%.4f\n",x9389);
        x9241 = x9241 + 1;
      }
    }
    int x9396 = x9241;
    printf("(%d rows)\n",x9396);
    gettimeofday(&x9400, NULL);
    timeval_subtract(&x9401, &x9400, &x9399);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x9401.tv_sec * 1000) + (x9401.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
