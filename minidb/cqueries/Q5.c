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
int x8992(struct Anon1042493154* x8979, struct Anon1042493154* x8980);
int x8992(struct Anon1042493154* x8979, struct Anon1042493154* x8980) {
  struct Anon1042493154 x8981 = (*x8979);
  struct Anon1042493154 x8982 = (*x8980);
  struct Anon2052879266 x8983 = x8981.aggs;;
  double x8984 = x8983._0;;
  struct Anon2052879266 x8985 = x8982.aggs;;
  double x8986 = x8985._0;;
  bool x8987 = x8984 < x8986;
  int x8990;
  if (x8987) {
    x8990 = 1;
  } else {
    bool x8988 = x8984 > x8986;
    int x8989;
    if (x8988) {
      x8989 = -1;
    } else {
      x8989 = 0;
    }
    x8990 = x8989;
  }
  return x8990;
}

/************************ MAIN BODY **************************/
int main(int x6386, char** x6387) {
  long x6388 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x6389 = x7;
  long x6390 = 0L;
  int* x6391 = (int*)malloc(x7 * sizeof(int));
  int* x6392 = x6391;
  int* x6395 = (int*)malloc(x7 * sizeof(int));
  int* x6396 = x6395;
  double* x6401 = (double*)malloc(x7 * sizeof(double));
  double* x6402 = x6401;
  double* x6403 = (double*)malloc(x7 * sizeof(double));
  double* x6404 = x6403;
  int x3 = open("XXXXXlineitem.tbl",0);
  long x4 = fsize(x3);
  char* x5 = mmap(0, x4, PROT_READ, MAP_FILE | MAP_SHARED, x3, 0);
  for (;;) {
    long x6423 = x6388;
    bool x6424 = x6423 < x4;
    if (!x6424) break;
    int x6427 = 0;
    for (;;) {
      long x6428 = x6388;
      char x6429 = x5[x6428];
      bool x6430 = x6429 != '|';
      bool x6435 = x6430;
      if (x6430) {
        long x6431 = x6388;
        char x6432 = x5[x6431];
        bool x6433 = x6432 != '\n';
        x6435 = x6433;
      }
      bool x6436 = x6435;
      if (!x6436) break;
      int x6438 = x6427;
      long x6440 = x6388;
      int x6439 = x6438 * 10;
      char x6441 = x5[x6440];
      char x6442 = x6441 - '0';
      int x6443 = x6439 + x6442;
      x6427 = x6443;
      x6388 = x6388 + 1;
    }
    x6388 = x6388 + 1;
    int x6449 = x6427;
    for (;;) {
      long x6452 = x6388;
      char x6453 = x5[x6452];
      bool x6454 = x6453 != '|';
      bool x6459 = x6454;
      if (x6454) {
        long x6455 = x6388;
        char x6456 = x5[x6455];
        bool x6457 = x6456 != '\n';
        x6459 = x6457;
      }
      bool x6460 = x6459;
      if (!x6460) break;
      x6388 = x6388 + 1;
    }
    x6388 = x6388 + 1;
    int x6475 = 0;
    for (;;) {
      long x6476 = x6388;
      char x6477 = x5[x6476];
      bool x6478 = x6477 != '|';
      bool x6483 = x6478;
      if (x6478) {
        long x6479 = x6388;
        char x6480 = x5[x6479];
        bool x6481 = x6480 != '\n';
        x6483 = x6481;
      }
      bool x6484 = x6483;
      if (!x6484) break;
      int x6486 = x6475;
      long x6488 = x6388;
      int x6487 = x6486 * 10;
      char x6489 = x5[x6488];
      char x6490 = x6489 - '0';
      int x6491 = x6487 + x6490;
      x6475 = x6491;
      x6388 = x6388 + 1;
    }
    x6388 = x6388 + 1;
    int x6497 = x6475;
    for (;;) {
      long x6500 = x6388;
      char x6501 = x5[x6500];
      bool x6502 = x6501 != '|';
      bool x6507 = x6502;
      if (x6502) {
        long x6503 = x6388;
        char x6504 = x5[x6503];
        bool x6505 = x6504 != '\n';
        x6507 = x6505;
      }
      bool x6508 = x6507;
      if (!x6508) break;
      x6388 = x6388 + 1;
    }
    x6388 = x6388 + 1;
    for (;;) {
      long x6525 = x6388;
      char x6526 = x5[x6525];
      bool x6527 = x6526 != '.';
      bool x6532 = x6527;
      if (x6527) {
        long x6528 = x6388;
        char x6529 = x5[x6528];
        bool x6530 = x6529 != '|';
        x6532 = x6530;
      }
      bool x6533 = x6532;
      bool x6538 = x6533;
      if (x6533) {
        long x6534 = x6388;
        char x6535 = x5[x6534];
        bool x6536 = x6535 != '\n';
        x6538 = x6536;
      }
      bool x6539 = x6538;
      if (!x6539) break;
      x6388 = x6388 + 1;
    }
    long x6551 = x6388;
    char x6552 = x5[x6551];
    bool x6553 = x6552 == '.';
    if (x6553) {
      x6388 = x6388 + 1;
      for (;;) {
        long x6555 = x6388;
        char x6556 = x5[x6555];
        bool x6557 = x6556 != '|';
        bool x6562 = x6557;
        if (x6557) {
          long x6558 = x6388;
          char x6559 = x5[x6558];
          bool x6560 = x6559 != '\n';
          x6562 = x6560;
        }
        bool x6563 = x6562;
        if (!x6563) break;
        x6388 = x6388 + 1;
      }
    } else {
    }
    x6388 = x6388 + 1;
    int x6588 = 0;
    int x6589 = 1;
    for (;;) {
      long x6590 = x6388;
      char x6591 = x5[x6590];
      bool x6592 = x6591 != '.';
      bool x6597 = x6592;
      if (x6592) {
        long x6593 = x6388;
        char x6594 = x5[x6593];
        bool x6595 = x6594 != '|';
        x6597 = x6595;
      }
      bool x6598 = x6597;
      bool x6603 = x6598;
      if (x6598) {
        long x6599 = x6388;
        char x6600 = x5[x6599];
        bool x6601 = x6600 != '\n';
        x6603 = x6601;
      }
      bool x6604 = x6603;
      if (!x6604) break;
      int x6606 = x6588;
      long x6608 = x6388;
      int x6607 = x6606 * 10;
      char x6609 = x5[x6608];
      char x6610 = x6609 - '0';
      int x6611 = x6607 + x6610;
      x6588 = x6611;
      x6388 = x6388 + 1;
    }
    long x6616 = x6388;
    char x6617 = x5[x6616];
    bool x6618 = x6617 == '.';
    if (x6618) {
      x6388 = x6388 + 1;
      for (;;) {
        long x6620 = x6388;
        char x6621 = x5[x6620];
        bool x6622 = x6621 != '|';
        bool x6627 = x6622;
        if (x6622) {
          long x6623 = x6388;
          char x6624 = x5[x6623];
          bool x6625 = x6624 != '\n';
          x6627 = x6625;
        }
        bool x6628 = x6627;
        if (!x6628) break;
        int x6630 = x6588;
        long x6632 = x6388;
        int x6631 = x6630 * 10;
        char x6633 = x5[x6632];
        char x6634 = x6633 - '0';
        int x6635 = x6631 + x6634;
        x6588 = x6635;
        int x6637 = x6589;
        int x6638 = x6637 * 10;
        x6589 = x6638;
        x6388 = x6388 + 1;
      }
    } else {
    }
    x6388 = x6388 + 1;
    int x6647 = x6588;
    int x6649 = x6589;
    int x6653 = 0;
    int x6654 = 1;
    for (;;) {
      long x6655 = x6388;
      char x6656 = x5[x6655];
      bool x6657 = x6656 != '.';
      bool x6662 = x6657;
      if (x6657) {
        long x6658 = x6388;
        char x6659 = x5[x6658];
        bool x6660 = x6659 != '|';
        x6662 = x6660;
      }
      bool x6663 = x6662;
      bool x6668 = x6663;
      if (x6663) {
        long x6664 = x6388;
        char x6665 = x5[x6664];
        bool x6666 = x6665 != '\n';
        x6668 = x6666;
      }
      bool x6669 = x6668;
      if (!x6669) break;
      int x6671 = x6653;
      long x6673 = x6388;
      int x6672 = x6671 * 10;
      char x6674 = x5[x6673];
      char x6675 = x6674 - '0';
      int x6676 = x6672 + x6675;
      x6653 = x6676;
      x6388 = x6388 + 1;
    }
    long x6681 = x6388;
    char x6682 = x5[x6681];
    bool x6683 = x6682 == '.';
    if (x6683) {
      x6388 = x6388 + 1;
      for (;;) {
        long x6685 = x6388;
        char x6686 = x5[x6685];
        bool x6687 = x6686 != '|';
        bool x6692 = x6687;
        if (x6687) {
          long x6688 = x6388;
          char x6689 = x5[x6688];
          bool x6690 = x6689 != '\n';
          x6692 = x6690;
        }
        bool x6693 = x6692;
        if (!x6693) break;
        int x6695 = x6653;
        long x6697 = x6388;
        int x6696 = x6695 * 10;
        char x6698 = x5[x6697];
        char x6699 = x6698 - '0';
        int x6700 = x6696 + x6699;
        x6653 = x6700;
        int x6702 = x6654;
        int x6703 = x6702 * 10;
        x6654 = x6703;
        x6388 = x6388 + 1;
      }
    } else {
    }
    x6388 = x6388 + 1;
    int x6712 = x6653;
    int x6714 = x6654;
    for (;;) {
      long x6720 = x6388;
      char x6721 = x5[x6720];
      bool x6722 = x6721 != '.';
      bool x6727 = x6722;
      if (x6722) {
        long x6723 = x6388;
        char x6724 = x5[x6723];
        bool x6725 = x6724 != '|';
        x6727 = x6725;
      }
      bool x6728 = x6727;
      bool x6733 = x6728;
      if (x6728) {
        long x6729 = x6388;
        char x6730 = x5[x6729];
        bool x6731 = x6730 != '\n';
        x6733 = x6731;
      }
      bool x6734 = x6733;
      if (!x6734) break;
      x6388 = x6388 + 1;
    }
    long x6746 = x6388;
    char x6747 = x5[x6746];
    bool x6748 = x6747 == '.';
    if (x6748) {
      x6388 = x6388 + 1;
      for (;;) {
        long x6750 = x6388;
        char x6751 = x5[x6750];
        bool x6752 = x6751 != '|';
        bool x6757 = x6752;
        if (x6752) {
          long x6753 = x6388;
          char x6754 = x5[x6753];
          bool x6755 = x6754 != '\n';
          x6757 = x6755;
        }
        bool x6758 = x6757;
        if (!x6758) break;
        x6388 = x6388 + 1;
      }
    } else {
    }
    x6388 = x6388 + 1;
    x6388 = x6388 + 2;
    x6388 = x6388 + 2;
    for (;;) {
      long x6790 = x6388;
      char x6791 = x5[x6790];
      bool x6792 = x6791 != '-';
      bool x6797 = x6792;
      if (x6792) {
        long x6793 = x6388;
        char x6794 = x5[x6793];
        bool x6795 = x6794 != '\n';
        x6797 = x6795;
      }
      bool x6798 = x6797;
      if (!x6798) break;
      x6388 = x6388 + 1;
    }
    x6388 = x6388 + 1;
    for (;;) {
      long x6814 = x6388;
      char x6815 = x5[x6814];
      bool x6816 = x6815 != '-';
      bool x6821 = x6816;
      if (x6816) {
        long x6817 = x6388;
        char x6818 = x5[x6817];
        bool x6819 = x6818 != '\n';
        x6821 = x6819;
      }
      bool x6822 = x6821;
      if (!x6822) break;
      x6388 = x6388 + 1;
    }
    x6388 = x6388 + 1;
    for (;;) {
      long x6838 = x6388;
      char x6839 = x5[x6838];
      bool x6840 = x6839 != '|';
      bool x6845 = x6840;
      if (x6840) {
        long x6841 = x6388;
        char x6842 = x5[x6841];
        bool x6843 = x6842 != '\n';
        x6845 = x6843;
      }
      bool x6846 = x6845;
      if (!x6846) break;
      x6388 = x6388 + 1;
    }
    x6388 = x6388 + 1;
    for (;;) {
      long x6866 = x6388;
      char x6867 = x5[x6866];
      bool x6868 = x6867 != '-';
      bool x6873 = x6868;
      if (x6868) {
        long x6869 = x6388;
        char x6870 = x5[x6869];
        bool x6871 = x6870 != '\n';
        x6873 = x6871;
      }
      bool x6874 = x6873;
      if (!x6874) break;
      x6388 = x6388 + 1;
    }
    x6388 = x6388 + 1;
    for (;;) {
      long x6890 = x6388;
      char x6891 = x5[x6890];
      bool x6892 = x6891 != '-';
      bool x6897 = x6892;
      if (x6892) {
        long x6893 = x6388;
        char x6894 = x5[x6893];
        bool x6895 = x6894 != '\n';
        x6897 = x6895;
      }
      bool x6898 = x6897;
      if (!x6898) break;
      x6388 = x6388 + 1;
    }
    x6388 = x6388 + 1;
    for (;;) {
      long x6914 = x6388;
      char x6915 = x5[x6914];
      bool x6916 = x6915 != '|';
      bool x6921 = x6916;
      if (x6916) {
        long x6917 = x6388;
        char x6918 = x5[x6917];
        bool x6919 = x6918 != '\n';
        x6921 = x6919;
      }
      bool x6922 = x6921;
      if (!x6922) break;
      x6388 = x6388 + 1;
    }
    x6388 = x6388 + 1;
    for (;;) {
      long x6942 = x6388;
      char x6943 = x5[x6942];
      bool x6944 = x6943 != '-';
      bool x6949 = x6944;
      if (x6944) {
        long x6945 = x6388;
        char x6946 = x5[x6945];
        bool x6947 = x6946 != '\n';
        x6949 = x6947;
      }
      bool x6950 = x6949;
      if (!x6950) break;
      x6388 = x6388 + 1;
    }
    x6388 = x6388 + 1;
    for (;;) {
      long x6966 = x6388;
      char x6967 = x5[x6966];
      bool x6968 = x6967 != '-';
      bool x6973 = x6968;
      if (x6968) {
        long x6969 = x6388;
        char x6970 = x5[x6969];
        bool x6971 = x6970 != '\n';
        x6973 = x6971;
      }
      bool x6974 = x6973;
      if (!x6974) break;
      x6388 = x6388 + 1;
    }
    x6388 = x6388 + 1;
    for (;;) {
      long x6990 = x6388;
      char x6991 = x5[x6990];
      bool x6992 = x6991 != '|';
      bool x6997 = x6992;
      if (x6992) {
        long x6993 = x6388;
        char x6994 = x5[x6993];
        bool x6995 = x6994 != '\n';
        x6997 = x6995;
      }
      bool x6998 = x6997;
      if (!x6998) break;
      x6388 = x6388 + 1;
    }
    x6388 = x6388 + 1;
    for (;;) {
      long x7017 = x6388;
      char x7018 = x5[x7017];
      bool x7019 = x7018 != '|';
      bool x7024 = x7019;
      if (x7019) {
        long x7020 = x6388;
        char x7021 = x5[x7020];
        bool x7022 = x7021 != '\n';
        x7024 = x7022;
      }
      bool x7025 = x7024;
      if (!x7025) break;
      x6388 = x6388 + 1;
    }
    x6388 = x6388 + 1;
    for (;;) {
      long x7035 = x6388;
      char x7036 = x5[x7035];
      bool x7037 = x7036 != '|';
      bool x7042 = x7037;
      if (x7037) {
        long x7038 = x6388;
        char x7039 = x5[x7038];
        bool x7040 = x7039 != '\n';
        x7042 = x7040;
      }
      bool x7043 = x7042;
      if (!x7043) break;
      x6388 = x6388 + 1;
    }
    x6388 = x6388 + 1;
    for (;;) {
      long x7053 = x6388;
      char x7054 = x5[x7053];
      bool x7055 = x7054 != '|';
      bool x7060 = x7055;
      if (x7055) {
        long x7056 = x6388;
        char x7057 = x5[x7056];
        bool x7058 = x7057 != '\n';
        x7060 = x7058;
      }
      bool x7061 = x7060;
      if (!x7061) break;
      x6388 = x6388 + 1;
    }
    x6388 = x6388 + 1;
    long x7071 = x6388;
    bool x7072 = x7071 > 0L;
    bool x7078 = x7072;
    if (x7072) {
      long x7073 = x6388;
      long x7074 = x7073 - 1L;
      char x7075 = x5[x7074];
      bool x7076 = x7075 != '\n';
      x7078 = x7076;
    }
    bool x7079 = x7078;
    if (x7079) {
      for (;;) {
        long x7080 = x6388;
        char x7081 = x5[x7080];
        bool x7082 = x7081 != '\n';
        if (!x7082) break;
        x6388 = x6388 + 1;
      }
    } else {
    }
    x6388 = x6388 + 1;
    long x7091 = x6390;
    long x7092 = x6389;
    bool x7093 = x7091 == x7092;
    if (x7093) {
      long x7094 = x7092 * 4L;
      x6389 = x7094;
      printf("buffer.resize %ld\n",x7094);
      int* x7097 = x6392;
      int* x7098 = (int*)realloc(x7097,x7094 * sizeof(int));
      x6392 = x7098;
      int* x7103 = x6396;
      int* x7104 = (int*)realloc(x7103,x7094 * sizeof(int));
      x6396 = x7104;
      double* x7112 = x6402;
      double* x7113 = (double*)realloc(x7112,x7094 * sizeof(double));
      x6402 = x7113;
      double* x7115 = x6404;
      double* x7116 = (double*)realloc(x7115,x7094 * sizeof(double));
      x6404 = x7116;
    } else {
    }
    int* x7147 = x6392;
    x7147[x7091] = x6449;
    int* x7151 = x6396;
    x7151[x7091] = x6497;
    double* x7157 = x6402;
    double x6648 = (double)x6647;
    double x6650 = (double)x6649;
    double x6651 = x6648 / x6650;
    x7157[x7091] = x6651;
    double* x7159 = x6404;
    double x6713 = (double)x6712;
    double x6715 = (double)x6714;
    double x6716 = x6713 / x6715;
    x7159[x7091] = x6716;
    x6390 = x6390 + 1;
  }
  long x7182 = 0L;
  long x7183 = x7;
  long x7184 = 0L;
  int* x7185 = (int*)malloc(x7 * sizeof(int));
  int* x7186 = x7185;
  char** x7187 = (char**)malloc(x7 * sizeof(char*));
  char** x7188 = x7187;
  int* x7189 = (int*)malloc(x7 * sizeof(int));
  int* x7190 = x7189;
  int x1633 = open("XXXXXnation.tbl",0);
  long x1634 = fsize(x1633);
  char* x1635 = mmap(0, x1634, PROT_READ, MAP_FILE | MAP_SHARED, x1633, 0);
  for (;;) {
    long x7193 = x7182;
    bool x7194 = x7193 < x1634;
    if (!x7194) break;
    int x7197 = 0;
    for (;;) {
      long x7198 = x7182;
      char x7199 = x1635[x7198];
      bool x7200 = x7199 != '|';
      bool x7205 = x7200;
      if (x7200) {
        long x7201 = x7182;
        char x7202 = x1635[x7201];
        bool x7203 = x7202 != '\n';
        x7205 = x7203;
      }
      bool x7206 = x7205;
      if (!x7206) break;
      int x7208 = x7197;
      long x7210 = x7182;
      int x7209 = x7208 * 10;
      char x7211 = x1635[x7210];
      char x7212 = x7211 - '0';
      int x7213 = x7209 + x7212;
      x7197 = x7213;
      x7182 = x7182 + 1;
    }
    x7182 = x7182 + 1;
    int x7219 = x7197;
    long x7220 = x7182;
    for (;;) {
      long x7221 = x7182;
      char x7222 = x1635[x7221];
      bool x7223 = x7222 != '|';
      bool x7228 = x7223;
      if (x7223) {
        long x7224 = x7182;
        char x7225 = x1635[x7224];
        bool x7226 = x7225 != '\n';
        x7228 = x7226;
      }
      bool x7229 = x7228;
      if (!x7229) break;
      x7182 = x7182 + 1;
    }
    x7182 = x7182 + 1;
    int x7239 = 0;
    for (;;) {
      long x7240 = x7182;
      char x7241 = x1635[x7240];
      bool x7242 = x7241 != '|';
      bool x7247 = x7242;
      if (x7242) {
        long x7243 = x7182;
        char x7244 = x1635[x7243];
        bool x7245 = x7244 != '\n';
        x7247 = x7245;
      }
      bool x7248 = x7247;
      if (!x7248) break;
      int x7250 = x7239;
      long x7252 = x7182;
      int x7251 = x7250 * 10;
      char x7253 = x1635[x7252];
      char x7254 = x7253 - '0';
      int x7255 = x7251 + x7254;
      x7239 = x7255;
      x7182 = x7182 + 1;
    }
    x7182 = x7182 + 1;
    int x7261 = x7239;
    for (;;) {
      long x7263 = x7182;
      char x7264 = x1635[x7263];
      bool x7265 = x7264 != '|';
      bool x7270 = x7265;
      if (x7265) {
        long x7266 = x7182;
        char x7267 = x1635[x7266];
        bool x7268 = x7267 != '\n';
        x7270 = x7268;
      }
      bool x7271 = x7270;
      if (!x7271) break;
      x7182 = x7182 + 1;
    }
    x7182 = x7182 + 1;
    long x7281 = x7182;
    bool x7282 = x7281 > 0L;
    bool x7288 = x7282;
    if (x7282) {
      long x7283 = x7182;
      long x7284 = x7283 - 1L;
      char x7285 = x1635[x7284];
      bool x7286 = x7285 != '\n';
      x7288 = x7286;
    }
    bool x7289 = x7288;
    if (x7289) {
      for (;;) {
        long x7290 = x7182;
        char x7291 = x1635[x7290];
        bool x7292 = x7291 != '\n';
        if (!x7292) break;
        x7182 = x7182 + 1;
      }
    } else {
    }
    x7182 = x7182 + 1;
    long x7301 = x7184;
    long x7302 = x7183;
    bool x7303 = x7301 == x7302;
    if (x7303) {
      long x7304 = x7302 * 4L;
      x7183 = x7304;
      printf("buffer.resize %ld\n",x7304);
      int* x7307 = x7186;
      int* x7308 = (int*)realloc(x7307,x7304 * sizeof(int));
      x7186 = x7308;
      char** x7310 = x7188;
      char** x7311 = (char**)realloc(x7310,x7304 * sizeof(char*));
      x7188 = x7311;
      int* x7313 = x7190;
      int* x7314 = (int*)realloc(x7313,x7304 * sizeof(int));
      x7190 = x7314;
    } else {
    }
    int* x7321 = x7186;
    x7321[x7301] = x7219;
    char** x7323 = x7188;
    char* x7237 = x1635+x7220;
    x7323[x7301] = x7237;
    int* x7325 = x7190;
    x7325[x7301] = x7261;
    x7184 = x7184 + 1;
  }
  long x7332 = 0L;
  long x7333 = x7;
  long x7334 = 0L;
  int* x7335 = (int*)malloc(x7 * sizeof(int));
  int* x7336 = x7335;
  int* x7341 = (int*)malloc(x7 * sizeof(int));
  int* x7342 = x7341;
  int x4007 = open("XXXXXcustomer.tbl",0);
  long x4008 = fsize(x4007);
  char* x4009 = mmap(0, x4008, PROT_READ, MAP_FILE | MAP_SHARED, x4007, 0);
  for (;;) {
    long x7351 = x7332;
    bool x7352 = x7351 < x4008;
    if (!x7352) break;
    int x7355 = 0;
    for (;;) {
      long x7356 = x7332;
      char x7357 = x4009[x7356];
      bool x7358 = x7357 != '|';
      bool x7363 = x7358;
      if (x7358) {
        long x7359 = x7332;
        char x7360 = x4009[x7359];
        bool x7361 = x7360 != '\n';
        x7363 = x7361;
      }
      bool x7364 = x7363;
      if (!x7364) break;
      int x7366 = x7355;
      long x7368 = x7332;
      int x7367 = x7366 * 10;
      char x7369 = x4009[x7368];
      char x7370 = x7369 - '0';
      int x7371 = x7367 + x7370;
      x7355 = x7371;
      x7332 = x7332 + 1;
    }
    x7332 = x7332 + 1;
    int x7377 = x7355;
    for (;;) {
      long x7379 = x7332;
      char x7380 = x4009[x7379];
      bool x7381 = x7380 != '|';
      bool x7386 = x7381;
      if (x7381) {
        long x7382 = x7332;
        char x7383 = x4009[x7382];
        bool x7384 = x7383 != '\n';
        x7386 = x7384;
      }
      bool x7387 = x7386;
      if (!x7387) break;
      x7332 = x7332 + 1;
    }
    x7332 = x7332 + 1;
    for (;;) {
      long x7397 = x7332;
      char x7398 = x4009[x7397];
      bool x7399 = x7398 != '|';
      bool x7404 = x7399;
      if (x7399) {
        long x7400 = x7332;
        char x7401 = x4009[x7400];
        bool x7402 = x7401 != '\n';
        x7404 = x7402;
      }
      bool x7405 = x7404;
      if (!x7405) break;
      x7332 = x7332 + 1;
    }
    x7332 = x7332 + 1;
    int x7415 = 0;
    for (;;) {
      long x7416 = x7332;
      char x7417 = x4009[x7416];
      bool x7418 = x7417 != '|';
      bool x7423 = x7418;
      if (x7418) {
        long x7419 = x7332;
        char x7420 = x4009[x7419];
        bool x7421 = x7420 != '\n';
        x7423 = x7421;
      }
      bool x7424 = x7423;
      if (!x7424) break;
      int x7426 = x7415;
      long x7428 = x7332;
      int x7427 = x7426 * 10;
      char x7429 = x4009[x7428];
      char x7430 = x7429 - '0';
      int x7431 = x7427 + x7430;
      x7415 = x7431;
      x7332 = x7332 + 1;
    }
    x7332 = x7332 + 1;
    int x7437 = x7415;
    for (;;) {
      long x7439 = x7332;
      char x7440 = x4009[x7439];
      bool x7441 = x7440 != '|';
      bool x7446 = x7441;
      if (x7441) {
        long x7442 = x7332;
        char x7443 = x4009[x7442];
        bool x7444 = x7443 != '\n';
        x7446 = x7444;
      }
      bool x7447 = x7446;
      if (!x7447) break;
      x7332 = x7332 + 1;
    }
    x7332 = x7332 + 1;
    for (;;) {
      long x7459 = x7332;
      char x7460 = x4009[x7459];
      bool x7461 = x7460 != '.';
      bool x7466 = x7461;
      if (x7461) {
        long x7462 = x7332;
        char x7463 = x4009[x7462];
        bool x7464 = x7463 != '|';
        x7466 = x7464;
      }
      bool x7467 = x7466;
      bool x7472 = x7467;
      if (x7467) {
        long x7468 = x7332;
        char x7469 = x4009[x7468];
        bool x7470 = x7469 != '\n';
        x7472 = x7470;
      }
      bool x7473 = x7472;
      if (!x7473) break;
      x7332 = x7332 + 1;
    }
    long x7485 = x7332;
    char x7486 = x4009[x7485];
    bool x7487 = x7486 == '.';
    if (x7487) {
      x7332 = x7332 + 1;
      for (;;) {
        long x7489 = x7332;
        char x7490 = x4009[x7489];
        bool x7491 = x7490 != '|';
        bool x7496 = x7491;
        if (x7491) {
          long x7492 = x7332;
          char x7493 = x4009[x7492];
          bool x7494 = x7493 != '\n';
          x7496 = x7494;
        }
        bool x7497 = x7496;
        if (!x7497) break;
        x7332 = x7332 + 1;
      }
    } else {
    }
    x7332 = x7332 + 1;
    for (;;) {
      long x7522 = x7332;
      char x7523 = x4009[x7522];
      bool x7524 = x7523 != '|';
      bool x7529 = x7524;
      if (x7524) {
        long x7525 = x7332;
        char x7526 = x4009[x7525];
        bool x7527 = x7526 != '\n';
        x7529 = x7527;
      }
      bool x7530 = x7529;
      if (!x7530) break;
      x7332 = x7332 + 1;
    }
    x7332 = x7332 + 1;
    for (;;) {
      long x7540 = x7332;
      char x7541 = x4009[x7540];
      bool x7542 = x7541 != '|';
      bool x7547 = x7542;
      if (x7542) {
        long x7543 = x7332;
        char x7544 = x4009[x7543];
        bool x7545 = x7544 != '\n';
        x7547 = x7545;
      }
      bool x7548 = x7547;
      if (!x7548) break;
      x7332 = x7332 + 1;
    }
    x7332 = x7332 + 1;
    long x7558 = x7332;
    bool x7559 = x7558 > 0L;
    bool x7565 = x7559;
    if (x7559) {
      long x7560 = x7332;
      long x7561 = x7560 - 1L;
      char x7562 = x4009[x7561];
      bool x7563 = x7562 != '\n';
      x7565 = x7563;
    }
    bool x7566 = x7565;
    if (x7566) {
      for (;;) {
        long x7567 = x7332;
        char x7568 = x4009[x7567];
        bool x7569 = x7568 != '\n';
        if (!x7569) break;
        x7332 = x7332 + 1;
      }
    } else {
    }
    x7332 = x7332 + 1;
    long x7578 = x7334;
    long x7579 = x7333;
    bool x7580 = x7578 == x7579;
    if (x7580) {
      long x7581 = x7579 * 4L;
      x7333 = x7581;
      printf("buffer.resize %ld\n",x7581);
      int* x7584 = x7336;
      int* x7585 = (int*)realloc(x7584,x7581 * sizeof(int));
      x7336 = x7585;
      int* x7593 = x7342;
      int* x7594 = (int*)realloc(x7593,x7581 * sizeof(int));
      x7342 = x7594;
    } else {
    }
    int* x7610 = x7336;
    x7610[x7578] = x7377;
    int* x7616 = x7342;
    x7616[x7578] = x7437;
    x7334 = x7334 + 1;
  }
  long x7629 = 0L;
  long x7630 = x7;
  long x7631 = 0L;
  int* x7632 = (int*)malloc(x7 * sizeof(int));
  int* x7633 = x7632;
  int* x7638 = (int*)malloc(x7 * sizeof(int));
  int* x7639 = x7638;
  int x1908 = open("XXXXXsupplier.tbl",0);
  long x1909 = fsize(x1908);
  char* x1910 = mmap(0, x1909, PROT_READ, MAP_FILE | MAP_SHARED, x1908, 0);
  for (;;) {
    long x7646 = x7629;
    bool x7647 = x7646 < x1909;
    if (!x7647) break;
    int x7650 = 0;
    for (;;) {
      long x7651 = x7629;
      char x7652 = x1910[x7651];
      bool x7653 = x7652 != '|';
      bool x7658 = x7653;
      if (x7653) {
        long x7654 = x7629;
        char x7655 = x1910[x7654];
        bool x7656 = x7655 != '\n';
        x7658 = x7656;
      }
      bool x7659 = x7658;
      if (!x7659) break;
      int x7661 = x7650;
      long x7663 = x7629;
      int x7662 = x7661 * 10;
      char x7664 = x1910[x7663];
      char x7665 = x7664 - '0';
      int x7666 = x7662 + x7665;
      x7650 = x7666;
      x7629 = x7629 + 1;
    }
    x7629 = x7629 + 1;
    int x7672 = x7650;
    for (;;) {
      long x7674 = x7629;
      char x7675 = x1910[x7674];
      bool x7676 = x7675 != '|';
      bool x7681 = x7676;
      if (x7676) {
        long x7677 = x7629;
        char x7678 = x1910[x7677];
        bool x7679 = x7678 != '\n';
        x7681 = x7679;
      }
      bool x7682 = x7681;
      if (!x7682) break;
      x7629 = x7629 + 1;
    }
    x7629 = x7629 + 1;
    for (;;) {
      long x7692 = x7629;
      char x7693 = x1910[x7692];
      bool x7694 = x7693 != '|';
      bool x7699 = x7694;
      if (x7694) {
        long x7695 = x7629;
        char x7696 = x1910[x7695];
        bool x7697 = x7696 != '\n';
        x7699 = x7697;
      }
      bool x7700 = x7699;
      if (!x7700) break;
      x7629 = x7629 + 1;
    }
    x7629 = x7629 + 1;
    int x7710 = 0;
    for (;;) {
      long x7711 = x7629;
      char x7712 = x1910[x7711];
      bool x7713 = x7712 != '|';
      bool x7718 = x7713;
      if (x7713) {
        long x7714 = x7629;
        char x7715 = x1910[x7714];
        bool x7716 = x7715 != '\n';
        x7718 = x7716;
      }
      bool x7719 = x7718;
      if (!x7719) break;
      int x7721 = x7710;
      long x7723 = x7629;
      int x7722 = x7721 * 10;
      char x7724 = x1910[x7723];
      char x7725 = x7724 - '0';
      int x7726 = x7722 + x7725;
      x7710 = x7726;
      x7629 = x7629 + 1;
    }
    x7629 = x7629 + 1;
    int x7732 = x7710;
    for (;;) {
      long x7734 = x7629;
      char x7735 = x1910[x7734];
      bool x7736 = x7735 != '|';
      bool x7741 = x7736;
      if (x7736) {
        long x7737 = x7629;
        char x7738 = x1910[x7737];
        bool x7739 = x7738 != '\n';
        x7741 = x7739;
      }
      bool x7742 = x7741;
      if (!x7742) break;
      x7629 = x7629 + 1;
    }
    x7629 = x7629 + 1;
    for (;;) {
      long x7754 = x7629;
      char x7755 = x1910[x7754];
      bool x7756 = x7755 != '.';
      bool x7761 = x7756;
      if (x7756) {
        long x7757 = x7629;
        char x7758 = x1910[x7757];
        bool x7759 = x7758 != '|';
        x7761 = x7759;
      }
      bool x7762 = x7761;
      bool x7767 = x7762;
      if (x7762) {
        long x7763 = x7629;
        char x7764 = x1910[x7763];
        bool x7765 = x7764 != '\n';
        x7767 = x7765;
      }
      bool x7768 = x7767;
      if (!x7768) break;
      x7629 = x7629 + 1;
    }
    long x7780 = x7629;
    char x7781 = x1910[x7780];
    bool x7782 = x7781 == '.';
    if (x7782) {
      x7629 = x7629 + 1;
      for (;;) {
        long x7784 = x7629;
        char x7785 = x1910[x7784];
        bool x7786 = x7785 != '|';
        bool x7791 = x7786;
        if (x7786) {
          long x7787 = x7629;
          char x7788 = x1910[x7787];
          bool x7789 = x7788 != '\n';
          x7791 = x7789;
        }
        bool x7792 = x7791;
        if (!x7792) break;
        x7629 = x7629 + 1;
      }
    } else {
    }
    x7629 = x7629 + 1;
    for (;;) {
      long x7817 = x7629;
      char x7818 = x1910[x7817];
      bool x7819 = x7818 != '|';
      bool x7824 = x7819;
      if (x7819) {
        long x7820 = x7629;
        char x7821 = x1910[x7820];
        bool x7822 = x7821 != '\n';
        x7824 = x7822;
      }
      bool x7825 = x7824;
      if (!x7825) break;
      x7629 = x7629 + 1;
    }
    x7629 = x7629 + 1;
    long x7835 = x7629;
    bool x7836 = x7835 > 0L;
    bool x7842 = x7836;
    if (x7836) {
      long x7837 = x7629;
      long x7838 = x7837 - 1L;
      char x7839 = x1910[x7838];
      bool x7840 = x7839 != '\n';
      x7842 = x7840;
    }
    bool x7843 = x7842;
    if (x7843) {
      for (;;) {
        long x7844 = x7629;
        char x7845 = x1910[x7844];
        bool x7846 = x7845 != '\n';
        if (!x7846) break;
        x7629 = x7629 + 1;
      }
    } else {
    }
    x7629 = x7629 + 1;
    long x7855 = x7631;
    long x7856 = x7630;
    bool x7857 = x7855 == x7856;
    if (x7857) {
      long x7858 = x7856 * 4L;
      x7630 = x7858;
      printf("buffer.resize %ld\n",x7858);
      int* x7861 = x7633;
      int* x7862 = (int*)realloc(x7861,x7858 * sizeof(int));
      x7633 = x7862;
      int* x7870 = x7639;
      int* x7871 = (int*)realloc(x7870,x7858 * sizeof(int));
      x7639 = x7871;
    } else {
    }
    int* x7884 = x7633;
    x7884[x7855] = x7672;
    int* x7890 = x7639;
    x7890[x7855] = x7732;
    x7631 = x7631 + 1;
  }
  long x7901 = 0L;
  long x7902 = x7;
  long x7903 = 0L;
  int* x7904 = (int*)malloc(x7 * sizeof(int));
  int* x7905 = x7904;
  char** x7906 = (char**)malloc(x7 * sizeof(char*));
  char** x7907 = x7906;
  int x1786 = open("XXXXXregion.tbl",0);
  long x1787 = fsize(x1786);
  char* x1788 = mmap(0, x1787, PROT_READ, MAP_FILE | MAP_SHARED, x1786, 0);
  for (;;) {
    long x7910 = x7901;
    bool x7911 = x7910 < x1787;
    if (!x7911) break;
    int x7914 = 0;
    for (;;) {
      long x7915 = x7901;
      char x7916 = x1788[x7915];
      bool x7917 = x7916 != '|';
      bool x7922 = x7917;
      if (x7917) {
        long x7918 = x7901;
        char x7919 = x1788[x7918];
        bool x7920 = x7919 != '\n';
        x7922 = x7920;
      }
      bool x7923 = x7922;
      if (!x7923) break;
      int x7925 = x7914;
      long x7927 = x7901;
      int x7926 = x7925 * 10;
      char x7928 = x1788[x7927];
      char x7929 = x7928 - '0';
      int x7930 = x7926 + x7929;
      x7914 = x7930;
      x7901 = x7901 + 1;
    }
    x7901 = x7901 + 1;
    int x7936 = x7914;
    long x7937 = x7901;
    for (;;) {
      long x7938 = x7901;
      char x7939 = x1788[x7938];
      bool x7940 = x7939 != '|';
      bool x7945 = x7940;
      if (x7940) {
        long x7941 = x7901;
        char x7942 = x1788[x7941];
        bool x7943 = x7942 != '\n';
        x7945 = x7943;
      }
      bool x7946 = x7945;
      if (!x7946) break;
      x7901 = x7901 + 1;
    }
    x7901 = x7901 + 1;
    for (;;) {
      long x7956 = x7901;
      char x7957 = x1788[x7956];
      bool x7958 = x7957 != '|';
      bool x7963 = x7958;
      if (x7958) {
        long x7959 = x7901;
        char x7960 = x1788[x7959];
        bool x7961 = x7960 != '\n';
        x7963 = x7961;
      }
      bool x7964 = x7963;
      if (!x7964) break;
      x7901 = x7901 + 1;
    }
    x7901 = x7901 + 1;
    long x7974 = x7901;
    bool x7975 = x7974 > 0L;
    bool x7981 = x7975;
    if (x7975) {
      long x7976 = x7901;
      long x7977 = x7976 - 1L;
      char x7978 = x1788[x7977];
      bool x7979 = x7978 != '\n';
      x7981 = x7979;
    }
    bool x7982 = x7981;
    if (x7982) {
      for (;;) {
        long x7983 = x7901;
        char x7984 = x1788[x7983];
        bool x7985 = x7984 != '\n';
        if (!x7985) break;
        x7901 = x7901 + 1;
      }
    } else {
    }
    x7901 = x7901 + 1;
    long x7994 = x7903;
    long x7995 = x7902;
    bool x7996 = x7994 == x7995;
    if (x7996) {
      long x7997 = x7995 * 4L;
      x7902 = x7997;
      printf("buffer.resize %ld\n",x7997);
      int* x8000 = x7905;
      int* x8001 = (int*)realloc(x8000,x7997 * sizeof(int));
      x7905 = x8001;
      char** x8003 = x7907;
      char** x8004 = (char**)realloc(x8003,x7997 * sizeof(char*));
      x7907 = x8004;
    } else {
    }
    int* x8011 = x7905;
    x8011[x7994] = x7936;
    char** x8013 = x7907;
    char* x7954 = x1788+x7937;
    x8013[x7994] = x7954;
    x7903 = x7903 + 1;
  }
  long x8020 = 0L;
  long x8021 = x7;
  long x8022 = 0L;
  int* x8023 = (int*)malloc(x7 * sizeof(int));
  int* x8024 = x8023;
  int* x8025 = (int*)malloc(x7 * sizeof(int));
  int* x8026 = x8025;
  long* x8031 = (long*)malloc(x7 * sizeof(long));
  long* x8032 = x8031;
  int x3633 = open("XXXXXorders.tbl",0);
  long x3634 = fsize(x3633);
  char* x3635 = mmap(0, x3634, PROT_READ, MAP_FILE | MAP_SHARED, x3633, 0);
  for (;;) {
    long x8041 = x8020;
    bool x8042 = x8041 < x3634;
    if (!x8042) break;
    int x8045 = 0;
    for (;;) {
      long x8046 = x8020;
      char x8047 = x3635[x8046];
      bool x8048 = x8047 != '|';
      bool x8053 = x8048;
      if (x8048) {
        long x8049 = x8020;
        char x8050 = x3635[x8049];
        bool x8051 = x8050 != '\n';
        x8053 = x8051;
      }
      bool x8054 = x8053;
      if (!x8054) break;
      int x8056 = x8045;
      long x8058 = x8020;
      int x8057 = x8056 * 10;
      char x8059 = x3635[x8058];
      char x8060 = x8059 - '0';
      int x8061 = x8057 + x8060;
      x8045 = x8061;
      x8020 = x8020 + 1;
    }
    x8020 = x8020 + 1;
    int x8067 = x8045;
    int x8069 = 0;
    for (;;) {
      long x8070 = x8020;
      char x8071 = x3635[x8070];
      bool x8072 = x8071 != '|';
      bool x8077 = x8072;
      if (x8072) {
        long x8073 = x8020;
        char x8074 = x3635[x8073];
        bool x8075 = x8074 != '\n';
        x8077 = x8075;
      }
      bool x8078 = x8077;
      if (!x8078) break;
      int x8080 = x8069;
      long x8082 = x8020;
      int x8081 = x8080 * 10;
      char x8083 = x3635[x8082];
      char x8084 = x8083 - '0';
      int x8085 = x8081 + x8084;
      x8069 = x8085;
      x8020 = x8020 + 1;
    }
    x8020 = x8020 + 1;
    int x8091 = x8069;
    x8020 = x8020 + 2;
    for (;;) {
      long x8098 = x8020;
      char x8099 = x3635[x8098];
      bool x8100 = x8099 != '.';
      bool x8105 = x8100;
      if (x8100) {
        long x8101 = x8020;
        char x8102 = x3635[x8101];
        bool x8103 = x8102 != '|';
        x8105 = x8103;
      }
      bool x8106 = x8105;
      bool x8111 = x8106;
      if (x8106) {
        long x8107 = x8020;
        char x8108 = x3635[x8107];
        bool x8109 = x8108 != '\n';
        x8111 = x8109;
      }
      bool x8112 = x8111;
      if (!x8112) break;
      x8020 = x8020 + 1;
    }
    long x8124 = x8020;
    char x8125 = x3635[x8124];
    bool x8126 = x8125 == '.';
    if (x8126) {
      x8020 = x8020 + 1;
      for (;;) {
        long x8128 = x8020;
        char x8129 = x3635[x8128];
        bool x8130 = x8129 != '|';
        bool x8135 = x8130;
        if (x8130) {
          long x8131 = x8020;
          char x8132 = x3635[x8131];
          bool x8133 = x8132 != '\n';
          x8135 = x8133;
        }
        bool x8136 = x8135;
        if (!x8136) break;
        x8020 = x8020 + 1;
      }
    } else {
    }
    x8020 = x8020 + 1;
    int x8161 = 0;
    for (;;) {
      long x8162 = x8020;
      char x8163 = x3635[x8162];
      bool x8164 = x8163 != '-';
      bool x8169 = x8164;
      if (x8164) {
        long x8165 = x8020;
        char x8166 = x3635[x8165];
        bool x8167 = x8166 != '\n';
        x8169 = x8167;
      }
      bool x8170 = x8169;
      if (!x8170) break;
      int x8172 = x8161;
      long x8174 = x8020;
      int x8173 = x8172 * 10;
      char x8175 = x3635[x8174];
      char x8176 = x8175 - '0';
      int x8177 = x8173 + x8176;
      x8161 = x8177;
      x8020 = x8020 + 1;
    }
    x8020 = x8020 + 1;
    int x8183 = x8161;
    int x8185 = 0;
    for (;;) {
      long x8186 = x8020;
      char x8187 = x3635[x8186];
      bool x8188 = x8187 != '-';
      bool x8193 = x8188;
      if (x8188) {
        long x8189 = x8020;
        char x8190 = x3635[x8189];
        bool x8191 = x8190 != '\n';
        x8193 = x8191;
      }
      bool x8194 = x8193;
      if (!x8194) break;
      int x8196 = x8185;
      long x8198 = x8020;
      int x8197 = x8196 * 10;
      char x8199 = x3635[x8198];
      char x8200 = x8199 - '0';
      int x8201 = x8197 + x8200;
      x8185 = x8201;
      x8020 = x8020 + 1;
    }
    x8020 = x8020 + 1;
    int x8207 = x8185;
    int x8209 = 0;
    for (;;) {
      long x8210 = x8020;
      char x8211 = x3635[x8210];
      bool x8212 = x8211 != '|';
      bool x8217 = x8212;
      if (x8212) {
        long x8213 = x8020;
        char x8214 = x3635[x8213];
        bool x8215 = x8214 != '\n';
        x8217 = x8215;
      }
      bool x8218 = x8217;
      if (!x8218) break;
      int x8220 = x8209;
      long x8222 = x8020;
      int x8221 = x8220 * 10;
      char x8223 = x3635[x8222];
      char x8224 = x8223 - '0';
      int x8225 = x8221 + x8224;
      x8209 = x8225;
      x8020 = x8020 + 1;
    }
    x8020 = x8020 + 1;
    int x8231 = x8209;
    for (;;) {
      long x8237 = x8020;
      char x8238 = x3635[x8237];
      bool x8239 = x8238 != '|';
      bool x8244 = x8239;
      if (x8239) {
        long x8240 = x8020;
        char x8241 = x3635[x8240];
        bool x8242 = x8241 != '\n';
        x8244 = x8242;
      }
      bool x8245 = x8244;
      if (!x8245) break;
      x8020 = x8020 + 1;
    }
    x8020 = x8020 + 1;
    for (;;) {
      long x8255 = x8020;
      char x8256 = x3635[x8255];
      bool x8257 = x8256 != '|';
      bool x8262 = x8257;
      if (x8257) {
        long x8258 = x8020;
        char x8259 = x3635[x8258];
        bool x8260 = x8259 != '\n';
        x8262 = x8260;
      }
      bool x8263 = x8262;
      if (!x8263) break;
      x8020 = x8020 + 1;
    }
    x8020 = x8020 + 1;
    for (;;) {
      long x8274 = x8020;
      char x8275 = x3635[x8274];
      bool x8276 = x8275 != '|';
      bool x8281 = x8276;
      if (x8276) {
        long x8277 = x8020;
        char x8278 = x3635[x8277];
        bool x8279 = x8278 != '\n';
        x8281 = x8279;
      }
      bool x8282 = x8281;
      if (!x8282) break;
      x8020 = x8020 + 1;
    }
    x8020 = x8020 + 1;
    for (;;) {
      long x8297 = x8020;
      char x8298 = x3635[x8297];
      bool x8299 = x8298 != '|';
      bool x8304 = x8299;
      if (x8299) {
        long x8300 = x8020;
        char x8301 = x3635[x8300];
        bool x8302 = x8301 != '\n';
        x8304 = x8302;
      }
      bool x8305 = x8304;
      if (!x8305) break;
      x8020 = x8020 + 1;
    }
    x8020 = x8020 + 1;
    long x8315 = x8020;
    bool x8316 = x8315 > 0L;
    bool x8322 = x8316;
    if (x8316) {
      long x8317 = x8020;
      long x8318 = x8317 - 1L;
      char x8319 = x3635[x8318];
      bool x8320 = x8319 != '\n';
      x8322 = x8320;
    }
    bool x8323 = x8322;
    if (x8323) {
      for (;;) {
        long x8324 = x8020;
        char x8325 = x3635[x8324];
        bool x8326 = x8325 != '\n';
        if (!x8326) break;
        x8020 = x8020 + 1;
      }
    } else {
    }
    x8020 = x8020 + 1;
    long x8335 = x8022;
    long x8336 = x8021;
    bool x8337 = x8335 == x8336;
    if (x8337) {
      long x8338 = x8336 * 4L;
      x8021 = x8338;
      printf("buffer.resize %ld\n",x8338);
      int* x8341 = x8024;
      int* x8342 = (int*)realloc(x8341,x8338 * sizeof(int));
      x8024 = x8342;
      int* x8344 = x8026;
      int* x8345 = (int*)realloc(x8344,x8338 * sizeof(int));
      x8026 = x8345;
      long* x8353 = x8032;
      long* x8354 = (long*)realloc(x8353,x8338 * sizeof(long));
      x8032 = x8354;
    } else {
    }
    int* x8370 = x8024;
    x8370[x8335] = x8067;
    int* x8372 = x8026;
    x8372[x8335] = x8091;
    long* x8378 = x8032;
    long x8232 = x8183 * 10000L;
    long x8233 = x8207 * 100L;
    long x8234 = x8232 + x8233;
    long x8235 = x8234 + x8231;
    x8378[x8335] = x8235;
    x8022 = x8022 + 1;
  }
  long x2189 = DEFAULT_JOIN_HASH_SIZE;
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  long x2212 = x2189 - 1L;
  long x823 = x808 - 1L;
  bool x1043 = true == false;
  int x8391;
  for(x8391=0; x8391 < 5; x8391++) {
    bool x8392 = false;
    long x8393 = 0L;
    bool x8395 = false;
    long x8396 = 0L;
    bool x8397 = false;
    long x8398 = 0L;
    bool x8399 = false;
    long x8400 = 0L;
    bool x8401 = false;
    long x8402 = 0L;
    bool x8403 = false;
    long x8404 = 0L;
    int* x8407 = (int*)malloc(x2189 * sizeof(int));
    int* x8408 = x8407;
    long x8413 = 0L;
    long* x8414 = (long*)malloc(x2189 * sizeof(long));
    long* x8415 = (long*)malloc(x2189 * sizeof(long));
    long x8416;
    for(x8416=0L; x8416 < x2189; x8416++) {
      x8414[x8416] = -1L;
    }
    char** x8422 = (char**)malloc(x2189 * sizeof(char*));
    char** x8423 = x8422;
    int* x8424 = (int*)malloc(x2189 * sizeof(int));
    int* x8425 = x8424;
    long x8426 = 0L;
    long* x8427 = (long*)malloc(x2189 * sizeof(long));
    long* x8428 = (long*)malloc(x2189 * sizeof(long));
    long x8429;
    for(x8429=0L; x8429 < x2189; x8429++) {
      x8427[x8429] = -1L;
    }
    char** x8435 = (char**)malloc(x2189 * sizeof(char*));
    char** x8436 = x8435;
    int* x8437 = (int*)malloc(x2189 * sizeof(int));
    int* x8438 = x8437;
    int* x8439 = (int*)malloc(x2189 * sizeof(int));
    int* x8440 = x8439;
    long x8441 = 0L;
    long* x8442 = (long*)malloc(x2189 * sizeof(long));
    long* x8443 = (long*)malloc(x2189 * sizeof(long));
    long x8444;
    for(x8444=0L; x8444 < x2189; x8444++) {
      x8442[x8444] = -1L;
    }
    char** x8450 = (char**)malloc(x2189 * sizeof(char*));
    char** x8451 = x8450;
    int* x8452 = (int*)malloc(x2189 * sizeof(int));
    int* x8453 = x8452;
    int* x8454 = (int*)malloc(x2189 * sizeof(int));
    int* x8455 = x8454;
    long x8456 = 0L;
    long* x8457 = (long*)malloc(x2189 * sizeof(long));
    long* x8458 = (long*)malloc(x2189 * sizeof(long));
    long x8459;
    for(x8459=0L; x8459 < x2189; x8459++) {
      x8457[x8459] = -1L;
    }
    int* x8465 = (int*)malloc(x2189 * sizeof(int));
    int* x8466 = x8465;
    int* x8471 = (int*)malloc(x2189 * sizeof(int));
    int* x8472 = x8471;
    long x8479 = 0L;
    long* x8480 = (long*)malloc(x2189 * sizeof(long));
    long* x8481 = (long*)malloc(x2189 * sizeof(long));
    long x8482;
    for(x8482=0L; x8482 < x2189; x8482++) {
      x8480[x8482] = -1L;
    }
    struct Anon1042493154* x8488 = (struct Anon1042493154*)malloc(x808 * sizeof(struct Anon1042493154));
    struct Anon1042493154* x8489 = x8488;
    long x8490 = 0L;
    long* x8491 = (long*)malloc(x808 * sizeof(long));
    long x8492;
    for(x8492=0L; x8492 < x808; x8492++) {
      struct Anon1042493154* x8493 = x8489;
      struct Anon1042493154 x8494 = x8493[x8492];
      char* x8495 = x8494.key;;
      struct Anon2052879266 x8496 = x8494.aggs;;
      struct Anon1042493154 x8497;
      x8497.exists = false;
      x8497.key = x8495;
      x8497.aggs = x8496;
      x8493[x8492] = x8497;
    }
    long x8502 = 1024L;
    long x8503 = 0L;
    struct Anon1042493154* x8504 = (struct Anon1042493154*)malloc(1024L * sizeof(struct Anon1042493154));
    struct Anon1042493154* x8505 = x8504;
    long x8507 = 0L;
    struct timeval x9013, x9014, x9015;
    gettimeofday(&x9013, NULL);
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x8509 = x8397;
      bool x8510 = !x8509;
      bool x8515 = x8510;
      if (x8510) {
        long x8511 = x8398;
        long x8512 = x7631;
        bool x8513 = x8511 < x8512;
        x8515 = x8513;
      }
      bool x8516 = x8515;
      if (!x8516) break;
      long x8518 = x8398;
      int* x8519 = x7633;
      int x8520 = x8519[x8518];
      int* x8525 = x7639;
      int x8526 = x8525[x8518];
      x8398 = x8398 + 1;
      long x8535 = x8479;
      int* x8536 = x8466;
      x8536[x8535] = x8520;
      int* x8542 = x8472;
      x8542[x8535] = x8526;
      x8479 = x8479 + 1L;
      long x8551 = x8520 & x2212;
      long x8552 = x8480[x8551];
      x8480[x8551] = x8535;
      x8481[x8535] = x8552;
    }
    printf("%s\n","begin scan REGION");
    for (;;) {
      bool x8558 = x8392;
      bool x8559 = !x8558;
      bool x8564 = x8559;
      if (x8559) {
        long x8560 = x8393;
        long x8561 = x7903;
        bool x8562 = x8560 < x8561;
        x8564 = x8562;
      }
      bool x8565 = x8564;
      if (!x8565) break;
      long x8567 = x8393;
      int* x8568 = x7905;
      int x8569 = x8568[x8567];
      char** x8570 = x7907;
      char* x8571 = x8570[x8567];
      x8393 = x8393 + 1;
      bool x8576 = tpch_strcmp(x8571,"ASIA") == 0;;
      if (x8576) {
        long x8577 = x8413;
        int* x8578 = x8408;
        x8578[x8577] = x8569;
        x8413 = x8413 + 1L;
        long x8585 = x8569 & x2212;
        long x8586 = x8414[x8585];
        x8414[x8585] = x8577;
        x8415[x8577] = x8586;
      } else {
      }
    }
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x8594 = x8395;
      bool x8595 = !x8594;
      bool x8600 = x8595;
      if (x8595) {
        long x8596 = x8396;
        long x8597 = x7184;
        bool x8598 = x8596 < x8597;
        x8600 = x8598;
      }
      bool x8601 = x8600;
      if (!x8601) break;
      long x8603 = x8396;
      int* x8604 = x7186;
      int x8605 = x8604[x8603];
      char** x8606 = x7188;
      char* x8607 = x8606[x8603];
      int* x8608 = x7190;
      int x8609 = x8608[x8603];
      x8396 = x8396 + 1;
      long x8614 = x8609 & x2212;
      long x8615 = x8414[x8614];
      long x8616 = x8615;
      long x8639 = x8605 & x2212;
      for (;;) {
        long x8617 = x8616;
        bool x8618 = x8617 != -1;
        if (!x8618) break;
        long x8620 = x8616;
        int* x8621 = x8408;
        int x8622 = x8621[x8620];
        long x8628 = x8415[x8620];
        x8616 = x8628;
        bool x8630 = x8622 == x8609;
        if (x8630) {
          long x8633 = x8426;
          char** x8634 = x8423;
          x8634[x8633] = x8607;
          int* x8636 = x8425;
          x8636[x8633] = x8605;
          x8426 = x8426 + 1L;
          long x8640 = x8427[x8639];
          x8427[x8639] = x8633;
          x8428[x8633] = x8640;
        } else {
        }
      }
    }
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x8650 = x8399;
      bool x8651 = !x8650;
      bool x8656 = x8651;
      if (x8651) {
        long x8652 = x8400;
        long x8653 = x7334;
        bool x8654 = x8652 < x8653;
        x8656 = x8654;
      }
      bool x8657 = x8656;
      if (!x8657) break;
      long x8659 = x8400;
      int* x8660 = x7336;
      int x8661 = x8660[x8659];
      int* x8666 = x7342;
      int x8667 = x8666[x8659];
      x8400 = x8400 + 1;
      long x8678 = x8667 & x2212;
      long x8679 = x8427[x8678];
      long x8680 = x8679;
      long x8703 = x8661 & x2212;
      for (;;) {
        long x8681 = x8680;
        bool x8682 = x8681 != -1;
        if (!x8682) break;
        long x8684 = x8680;
        char** x8685 = x8423;
        char* x8686 = x8685[x8684];
        int* x8687 = x8425;
        int x8688 = x8687[x8684];
        long x8690 = x8428[x8684];
        x8680 = x8690;
        bool x8692 = x8688 == x8667;
        if (x8692) {
          long x8695 = x8441;
          char** x8696 = x8436;
          x8696[x8695] = x8686;
          int* x8698 = x8438;
          x8698[x8695] = x8688;
          int* x8700 = x8440;
          x8700[x8695] = x8661;
          x8441 = x8441 + 1L;
          long x8704 = x8442[x8703];
          x8442[x8703] = x8695;
          x8443[x8695] = x8704;
        } else {
        }
      }
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x8714 = x8403;
      bool x8715 = !x8714;
      bool x8720 = x8715;
      if (x8715) {
        long x8716 = x8404;
        long x8717 = x8022;
        bool x8718 = x8716 < x8717;
        x8720 = x8718;
      }
      bool x8721 = x8720;
      if (!x8721) break;
      long x8723 = x8404;
      int* x8724 = x8024;
      int x8725 = x8724[x8723];
      int* x8726 = x8026;
      int x8727 = x8726[x8723];
      long* x8732 = x8032;
      long x8733 = x8732[x8723];
      x8404 = x8404 + 1;
      bool x8744 = x8733 >= 19940101L;
      bool x8746 = x8744;
      if (x8744) {
        bool x8745 = x8733 < 19950101L;
        x8746 = x8745;
      }
      bool x8747 = x8746;
      if (x8747) {
        long x8748 = x8727 & x2212;
        long x8749 = x8442[x8748];
        long x8750 = x8749;
        long x8775 = x8725 & x2212;
        for (;;) {
          long x8751 = x8750;
          bool x8752 = x8751 != -1;
          if (!x8752) break;
          long x8754 = x8750;
          char** x8755 = x8436;
          char* x8756 = x8755[x8754];
          int* x8757 = x8438;
          int x8758 = x8757[x8754];
          int* x8759 = x8440;
          int x8760 = x8759[x8754];
          long x8762 = x8443[x8754];
          x8750 = x8762;
          bool x8764 = x8760 == x8727;
          if (x8764) {
            long x8767 = x8456;
            char** x8768 = x8451;
            x8768[x8767] = x8756;
            int* x8770 = x8453;
            x8770[x8767] = x8758;
            int* x8772 = x8455;
            x8772[x8767] = x8725;
            x8456 = x8456 + 1L;
            long x8776 = x8457[x8775];
            x8457[x8775] = x8767;
            x8458[x8767] = x8776;
          } else {
          }
        }
      } else {
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x8788 = x8401;
      bool x8789 = !x8788;
      bool x8794 = x8789;
      if (x8789) {
        long x8790 = x8402;
        long x8791 = x6390;
        bool x8792 = x8790 < x8791;
        x8794 = x8792;
      }
      bool x8795 = x8794;
      if (!x8795) break;
      long x8797 = x8402;
      int* x8798 = x6392;
      int x8799 = x8798[x8797];
      int* x8802 = x6396;
      int x8803 = x8802[x8797];
      double* x8808 = x6402;
      double x8809 = x8808[x8797];
      double* x8810 = x6404;
      double x8811 = x8810[x8797];
      x8402 = x8402 + 1;
      long x8832 = x8799 & x2212;
      long x8833 = x8457[x8832];
      long x8834 = x8833;
      long x8851 = x8803 & x2212;
      double x8893 = 1.0 - x8811;
      double x8894 = x8809 * x8893;
      struct Anon2052879266 x8927;
      x8927._0 = x8894;
      for (;;) {
        long x8835 = x8834;
        bool x8836 = x8835 != -1;
        if (!x8836) break;
        long x8838 = x8834;
        char** x8839 = x8451;
        char* x8840 = x8839[x8838];
        int* x8841 = x8453;
        int x8842 = x8841[x8838];
        int* x8843 = x8455;
        int x8844 = x8843[x8838];
        long x8846 = x8458[x8838];
        x8834 = x8846;
        bool x8848 = x8844 == x8799;
        if (x8848) {
          long x8852 = x8480[x8851];
          long x8853 = x8852;
          struct Anon1042493154 x8928;
          x8928.exists = true;
          x8928.key = x8840;
          x8928.aggs = x8927;
          for (;;) {
            long x8854 = x8853;
            bool x8855 = x8854 != -1;
            if (!x8855) break;
            long x8857 = x8853;
            int* x8858 = x8466;
            int x8859 = x8858[x8857];
            int* x8864 = x8472;
            int x8865 = x8864[x8857];
            long x8873 = x8481[x8857];
            x8853 = x8873;
            bool x8875 = x8859 == x8803;
            if (x8875) {
              bool x8877 = x8865 == x8842;
              if (x8877) {
                long x8878 = hash(x8840, 10L);
                long x8879 = x8878 & x823;
                long x8880 = x8879;
                struct Anon1042493154* x8881 = x8489;
                struct Anon1042493154 x8882 = x8881[x8879];
                struct Anon1042493154 x8883 = x8882;
                bool x8884 = x8882.exists;;
                bool x8889 = x8884;
                if (x8884) {
                  struct Anon1042493154 x8885 = x8883;
                  char* x8886 = x8885.key;;
                  bool x8887 = tpch_strcmp(x8886,x8840) == 0;;
                  x8889 = x8887;
                }
                bool x8890 = x8889;
                if (x8890) {
                  struct Anon2052879266 x8891 = x8882.aggs;;
                  char* x8897 = x8882.key;;
                  double x8892 = x8891._0;;
                  double x8895 = x8892 + x8894;
                  struct Anon2052879266 x8896;
                  x8896._0 = x8895;
                  struct Anon1042493154 x8898;
                  x8898.exists = true;
                  x8898.key = x8897;
                  x8898.aggs = x8896;
                  x8881[x8879] = x8898;
                } else {
                  for (;;) {
                    struct Anon1042493154 x8901 = x8883;
                    bool x8902 = x8901.exists;;
                    bool x8937;
                    if (x8902) {
                      char* x8903 = x8901.key;;
                      bool x8904 = tpch_strcmp(x8903,x8840) == 0;;
                      bool x8924;
                      if (x8904) {
                        struct Anon2052879266 x8905 = x8901.aggs;;
                        long x8909 = x8880;
                        struct Anon1042493154* x8911 = x8489;
                        double x8906 = x8905._0;;
                        double x8907 = x8906 + x8894;
                        struct Anon2052879266 x8908;
                        x8908._0 = x8907;
                        struct Anon1042493154 x8910;
                        x8910.exists = true;
                        x8910.key = x8903;
                        x8910.aggs = x8908;
                        x8911[x8909] = x8910;
                        x8924 = false;
                      } else {
                        long x8914 = x8880;
                        long x8915 = x8914 + 1L;
                        long x8916 = x8915 & x823;
                        x8880 = x8916;
                        struct Anon1042493154* x8918 = x8489;
                        struct Anon1042493154 x8919 = x8918[x8916];
                        x8883 = x8919;
                        x8924 = true;
                      }
                      x8937 = x8924;
                    } else {
                      long x8926 = x8880;
                      struct Anon1042493154* x8929 = x8489;
                      x8929[x8926] = x8928;
                      long x8931 = x8490;
                      x8491[x8931] = x8926;
                      x8490 = x8490 + 1L;
                      x8937 = false;
                    }
                    if (!x8937) break;
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
    long x8956 = x8490;
    long x8958;
    for(x8958=0L; x8958 < x8956; x8958++) {
      long x8959 = x8491[x8958];
      struct Anon1042493154* x8960 = x8489;
      struct Anon1042493154 x8961 = x8960[x8959];
      long x8962 = x8503;
      long x8963 = x8502;
      bool x8964 = x8962 == x8963;
      if (x8964) {
        long x8965 = x8963 * 4L;
        x8502 = x8965;
        struct Anon1042493154* x8967 = x8505;
        struct Anon1042493154* x8968 = (struct Anon1042493154 *)realloc(x8967,x8965* sizeof(struct Anon1042493154));
        x8505 = x8968;
      } else {
      }
      struct Anon1042493154* x8972 = x8505;
      x8972[x8962] = x8961;
      x8503 = x8503 + 1;
    }
    long x8977 = x8503;
    struct Anon1042493154* x8978 = x8505;
    qsort((void *)x8978,x8977,sizeof(struct Anon1042493154), (__compar_fn_t)x8992); // x8993
    long x8995;
    for(x8995=0L; x8995 < x8977; x8995++) {
      struct Anon1042493154* x8996 = x8505;
      struct Anon1042493154 x8997 = x8996[x8995];
      if (x1043) {
      } else {
        char* x9000 = x8997.key;;
        struct Anon2052879266 x9002 = x8997.aggs;;
        int x9001 = tpch_strlen(x9000);
        double x9003 = x9002._0;;
        printf("%.*s|%.4f\n",x9001,x9000,x9003);
        x8507 = x8507 + 1L;
      }
    }
    long x9010 = x8507;
    printf("(%ld rows)\n",x9010);
    gettimeofday(&x9014, NULL);
    timeval_subtract(&x9015, &x9014, &x9013);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x9015.tv_sec * 1000) + (x9015.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
