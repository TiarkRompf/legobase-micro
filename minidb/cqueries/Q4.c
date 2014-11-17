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

struct Anon2052879266 {
double _0;
};

struct Anon532638341 {
bool exists;
struct Anon1465150758 key;
struct Anon2052879266 aggs;
};

struct Anon1285873738 {
int key;
struct Anon1023322325 wnd;
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

struct Anon0 {
struct Anon1732223439 left;
struct Anon168903330 right;
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
int main(int x4492, char** x4493) {
  long x4494 = 0L;
  long x6 = DEFAULT_INPUT_SIZE;
  long x4495 = x6;
  long x4496 = 0L;
  int* x4497 = (int*)malloc(x6 * sizeof(int));
  int* x4498 = x4497;
  long* x4519 = (long*)malloc(x6 * sizeof(long));
  long* x4520 = x4519;
  long* x4521 = (long*)malloc(x6 * sizeof(long));
  long* x4522 = x4521;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  long x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    long x4529 = x4494;
    bool x4530 = x4529 < x3;
    if (!x4530) break;
    int x4533 = 0;
    for (;;) {
      long x4534 = x4494;
      char x4535 = x4[x4534];
      bool x4536 = x4535 != '|';
      bool x4541 = x4536;
      if (x4536) {
        long x4537 = x4494;
        char x4538 = x4[x4537];
        bool x4539 = x4538 != '\n';
        x4541 = x4539;
      }
      bool x4542 = x4541;
      if (!x4542) break;
      int x4544 = x4533;
      long x4546 = x4494;
      int x4545 = x4544 * 10;
      char x4547 = x4[x4546];
      char x4548 = x4547 - '0';
      int x4549 = x4545 + x4548;
      x4533 = x4549;
      x4494 = x4494 + 1;
    }
    x4494 = x4494 + 1;
    int x4555 = x4533;
    for (;;) {
      long x4558 = x4494;
      char x4559 = x4[x4558];
      bool x4560 = x4559 != '|';
      bool x4565 = x4560;
      if (x4560) {
        long x4561 = x4494;
        char x4562 = x4[x4561];
        bool x4563 = x4562 != '\n';
        x4565 = x4563;
      }
      bool x4566 = x4565;
      if (!x4566) break;
      x4494 = x4494 + 1;
    }
    x4494 = x4494 + 1;
    for (;;) {
      long x4582 = x4494;
      char x4583 = x4[x4582];
      bool x4584 = x4583 != '|';
      bool x4589 = x4584;
      if (x4584) {
        long x4585 = x4494;
        char x4586 = x4[x4585];
        bool x4587 = x4586 != '\n';
        x4589 = x4587;
      }
      bool x4590 = x4589;
      if (!x4590) break;
      x4494 = x4494 + 1;
    }
    x4494 = x4494 + 1;
    for (;;) {
      long x4606 = x4494;
      char x4607 = x4[x4606];
      bool x4608 = x4607 != '|';
      bool x4613 = x4608;
      if (x4608) {
        long x4609 = x4494;
        char x4610 = x4[x4609];
        bool x4611 = x4610 != '\n';
        x4613 = x4611;
      }
      bool x4614 = x4613;
      if (!x4614) break;
      x4494 = x4494 + 1;
    }
    x4494 = x4494 + 1;
    for (;;) {
      long x4631 = x4494;
      char x4632 = x4[x4631];
      bool x4633 = x4632 != '.';
      bool x4638 = x4633;
      if (x4633) {
        long x4634 = x4494;
        char x4635 = x4[x4634];
        bool x4636 = x4635 != '|';
        x4638 = x4636;
      }
      bool x4639 = x4638;
      bool x4644 = x4639;
      if (x4639) {
        long x4640 = x4494;
        char x4641 = x4[x4640];
        bool x4642 = x4641 != '\n';
        x4644 = x4642;
      }
      bool x4645 = x4644;
      if (!x4645) break;
      x4494 = x4494 + 1;
    }
    long x4657 = x4494;
    char x4658 = x4[x4657];
    bool x4659 = x4658 == '.';
    if (x4659) {
      x4494 = x4494 + 1;
      for (;;) {
        long x4661 = x4494;
        char x4662 = x4[x4661];
        bool x4663 = x4662 != '|';
        bool x4668 = x4663;
        if (x4663) {
          long x4664 = x4494;
          char x4665 = x4[x4664];
          bool x4666 = x4665 != '\n';
          x4668 = x4666;
        }
        bool x4669 = x4668;
        if (!x4669) break;
        x4494 = x4494 + 1;
      }
    } else {
    }
    x4494 = x4494 + 1;
    for (;;) {
      long x4696 = x4494;
      char x4697 = x4[x4696];
      bool x4698 = x4697 != '.';
      bool x4703 = x4698;
      if (x4698) {
        long x4699 = x4494;
        char x4700 = x4[x4699];
        bool x4701 = x4700 != '|';
        x4703 = x4701;
      }
      bool x4704 = x4703;
      bool x4709 = x4704;
      if (x4704) {
        long x4705 = x4494;
        char x4706 = x4[x4705];
        bool x4707 = x4706 != '\n';
        x4709 = x4707;
      }
      bool x4710 = x4709;
      if (!x4710) break;
      x4494 = x4494 + 1;
    }
    long x4722 = x4494;
    char x4723 = x4[x4722];
    bool x4724 = x4723 == '.';
    if (x4724) {
      x4494 = x4494 + 1;
      for (;;) {
        long x4726 = x4494;
        char x4727 = x4[x4726];
        bool x4728 = x4727 != '|';
        bool x4733 = x4728;
        if (x4728) {
          long x4729 = x4494;
          char x4730 = x4[x4729];
          bool x4731 = x4730 != '\n';
          x4733 = x4731;
        }
        bool x4734 = x4733;
        if (!x4734) break;
        x4494 = x4494 + 1;
      }
    } else {
    }
    x4494 = x4494 + 1;
    for (;;) {
      long x4761 = x4494;
      char x4762 = x4[x4761];
      bool x4763 = x4762 != '.';
      bool x4768 = x4763;
      if (x4763) {
        long x4764 = x4494;
        char x4765 = x4[x4764];
        bool x4766 = x4765 != '|';
        x4768 = x4766;
      }
      bool x4769 = x4768;
      bool x4774 = x4769;
      if (x4769) {
        long x4770 = x4494;
        char x4771 = x4[x4770];
        bool x4772 = x4771 != '\n';
        x4774 = x4772;
      }
      bool x4775 = x4774;
      if (!x4775) break;
      x4494 = x4494 + 1;
    }
    long x4787 = x4494;
    char x4788 = x4[x4787];
    bool x4789 = x4788 == '.';
    if (x4789) {
      x4494 = x4494 + 1;
      for (;;) {
        long x4791 = x4494;
        char x4792 = x4[x4791];
        bool x4793 = x4792 != '|';
        bool x4798 = x4793;
        if (x4793) {
          long x4794 = x4494;
          char x4795 = x4[x4794];
          bool x4796 = x4795 != '\n';
          x4798 = x4796;
        }
        bool x4799 = x4798;
        if (!x4799) break;
        x4494 = x4494 + 1;
      }
    } else {
    }
    x4494 = x4494 + 1;
    for (;;) {
      long x4826 = x4494;
      char x4827 = x4[x4826];
      bool x4828 = x4827 != '.';
      bool x4833 = x4828;
      if (x4828) {
        long x4829 = x4494;
        char x4830 = x4[x4829];
        bool x4831 = x4830 != '|';
        x4833 = x4831;
      }
      bool x4834 = x4833;
      bool x4839 = x4834;
      if (x4834) {
        long x4835 = x4494;
        char x4836 = x4[x4835];
        bool x4837 = x4836 != '\n';
        x4839 = x4837;
      }
      bool x4840 = x4839;
      if (!x4840) break;
      x4494 = x4494 + 1;
    }
    long x4852 = x4494;
    char x4853 = x4[x4852];
    bool x4854 = x4853 == '.';
    if (x4854) {
      x4494 = x4494 + 1;
      for (;;) {
        long x4856 = x4494;
        char x4857 = x4[x4856];
        bool x4858 = x4857 != '|';
        bool x4863 = x4858;
        if (x4858) {
          long x4859 = x4494;
          char x4860 = x4[x4859];
          bool x4861 = x4860 != '\n';
          x4863 = x4861;
        }
        bool x4864 = x4863;
        if (!x4864) break;
        x4494 = x4494 + 1;
      }
    } else {
    }
    x4494 = x4494 + 1;
    x4494 = x4494 + 2;
    x4494 = x4494 + 2;
    for (;;) {
      long x4896 = x4494;
      char x4897 = x4[x4896];
      bool x4898 = x4897 != '-';
      bool x4903 = x4898;
      if (x4898) {
        long x4899 = x4494;
        char x4900 = x4[x4899];
        bool x4901 = x4900 != '\n';
        x4903 = x4901;
      }
      bool x4904 = x4903;
      if (!x4904) break;
      x4494 = x4494 + 1;
    }
    x4494 = x4494 + 1;
    for (;;) {
      long x4920 = x4494;
      char x4921 = x4[x4920];
      bool x4922 = x4921 != '-';
      bool x4927 = x4922;
      if (x4922) {
        long x4923 = x4494;
        char x4924 = x4[x4923];
        bool x4925 = x4924 != '\n';
        x4927 = x4925;
      }
      bool x4928 = x4927;
      if (!x4928) break;
      x4494 = x4494 + 1;
    }
    x4494 = x4494 + 1;
    for (;;) {
      long x4944 = x4494;
      char x4945 = x4[x4944];
      bool x4946 = x4945 != '|';
      bool x4951 = x4946;
      if (x4946) {
        long x4947 = x4494;
        char x4948 = x4[x4947];
        bool x4949 = x4948 != '\n';
        x4951 = x4949;
      }
      bool x4952 = x4951;
      if (!x4952) break;
      x4494 = x4494 + 1;
    }
    x4494 = x4494 + 1;
    int x4971 = 0;
    for (;;) {
      long x4972 = x4494;
      char x4973 = x4[x4972];
      bool x4974 = x4973 != '-';
      bool x4979 = x4974;
      if (x4974) {
        long x4975 = x4494;
        char x4976 = x4[x4975];
        bool x4977 = x4976 != '\n';
        x4979 = x4977;
      }
      bool x4980 = x4979;
      if (!x4980) break;
      int x4982 = x4971;
      long x4984 = x4494;
      int x4983 = x4982 * 10;
      char x4985 = x4[x4984];
      char x4986 = x4985 - '0';
      int x4987 = x4983 + x4986;
      x4971 = x4987;
      x4494 = x4494 + 1;
    }
    x4494 = x4494 + 1;
    int x4993 = x4971;
    int x4995 = 0;
    for (;;) {
      long x4996 = x4494;
      char x4997 = x4[x4996];
      bool x4998 = x4997 != '-';
      bool x5003 = x4998;
      if (x4998) {
        long x4999 = x4494;
        char x5000 = x4[x4999];
        bool x5001 = x5000 != '\n';
        x5003 = x5001;
      }
      bool x5004 = x5003;
      if (!x5004) break;
      int x5006 = x4995;
      long x5008 = x4494;
      int x5007 = x5006 * 10;
      char x5009 = x4[x5008];
      char x5010 = x5009 - '0';
      int x5011 = x5007 + x5010;
      x4995 = x5011;
      x4494 = x4494 + 1;
    }
    x4494 = x4494 + 1;
    int x5017 = x4995;
    int x5019 = 0;
    for (;;) {
      long x5020 = x4494;
      char x5021 = x4[x5020];
      bool x5022 = x5021 != '|';
      bool x5027 = x5022;
      if (x5022) {
        long x5023 = x4494;
        char x5024 = x4[x5023];
        bool x5025 = x5024 != '\n';
        x5027 = x5025;
      }
      bool x5028 = x5027;
      if (!x5028) break;
      int x5030 = x5019;
      long x5032 = x4494;
      int x5031 = x5030 * 10;
      char x5033 = x4[x5032];
      char x5034 = x5033 - '0';
      int x5035 = x5031 + x5034;
      x5019 = x5035;
      x4494 = x4494 + 1;
    }
    x4494 = x4494 + 1;
    int x5041 = x5019;
    int x5047 = 0;
    for (;;) {
      long x5048 = x4494;
      char x5049 = x4[x5048];
      bool x5050 = x5049 != '-';
      bool x5055 = x5050;
      if (x5050) {
        long x5051 = x4494;
        char x5052 = x4[x5051];
        bool x5053 = x5052 != '\n';
        x5055 = x5053;
      }
      bool x5056 = x5055;
      if (!x5056) break;
      int x5058 = x5047;
      long x5060 = x4494;
      int x5059 = x5058 * 10;
      char x5061 = x4[x5060];
      char x5062 = x5061 - '0';
      int x5063 = x5059 + x5062;
      x5047 = x5063;
      x4494 = x4494 + 1;
    }
    x4494 = x4494 + 1;
    int x5069 = x5047;
    int x5071 = 0;
    for (;;) {
      long x5072 = x4494;
      char x5073 = x4[x5072];
      bool x5074 = x5073 != '-';
      bool x5079 = x5074;
      if (x5074) {
        long x5075 = x4494;
        char x5076 = x4[x5075];
        bool x5077 = x5076 != '\n';
        x5079 = x5077;
      }
      bool x5080 = x5079;
      if (!x5080) break;
      int x5082 = x5071;
      long x5084 = x4494;
      int x5083 = x5082 * 10;
      char x5085 = x4[x5084];
      char x5086 = x5085 - '0';
      int x5087 = x5083 + x5086;
      x5071 = x5087;
      x4494 = x4494 + 1;
    }
    x4494 = x4494 + 1;
    int x5093 = x5071;
    int x5095 = 0;
    for (;;) {
      long x5096 = x4494;
      char x5097 = x4[x5096];
      bool x5098 = x5097 != '|';
      bool x5103 = x5098;
      if (x5098) {
        long x5099 = x4494;
        char x5100 = x4[x5099];
        bool x5101 = x5100 != '\n';
        x5103 = x5101;
      }
      bool x5104 = x5103;
      if (!x5104) break;
      int x5106 = x5095;
      long x5108 = x4494;
      int x5107 = x5106 * 10;
      char x5109 = x4[x5108];
      char x5110 = x5109 - '0';
      int x5111 = x5107 + x5110;
      x5095 = x5111;
      x4494 = x4494 + 1;
    }
    x4494 = x4494 + 1;
    int x5117 = x5095;
    for (;;) {
      long x5123 = x4494;
      char x5124 = x4[x5123];
      bool x5125 = x5124 != '|';
      bool x5130 = x5125;
      if (x5125) {
        long x5126 = x4494;
        char x5127 = x4[x5126];
        bool x5128 = x5127 != '\n';
        x5130 = x5128;
      }
      bool x5131 = x5130;
      if (!x5131) break;
      x4494 = x4494 + 1;
    }
    x4494 = x4494 + 1;
    for (;;) {
      long x5141 = x4494;
      char x5142 = x4[x5141];
      bool x5143 = x5142 != '|';
      bool x5148 = x5143;
      if (x5143) {
        long x5144 = x4494;
        char x5145 = x4[x5144];
        bool x5146 = x5145 != '\n';
        x5148 = x5146;
      }
      bool x5149 = x5148;
      if (!x5149) break;
      x4494 = x4494 + 1;
    }
    x4494 = x4494 + 1;
    for (;;) {
      long x5159 = x4494;
      char x5160 = x4[x5159];
      bool x5161 = x5160 != '|';
      bool x5166 = x5161;
      if (x5161) {
        long x5162 = x4494;
        char x5163 = x4[x5162];
        bool x5164 = x5163 != '\n';
        x5166 = x5164;
      }
      bool x5167 = x5166;
      if (!x5167) break;
      x4494 = x4494 + 1;
    }
    x4494 = x4494 + 1;
    long x5177 = x4496;
    long x5178 = x4495;
    bool x5179 = x5177 == x5178;
    if (x5179) {
      long x5180 = x5178 * 4L;
      x4495 = x5180;
      printf("buffer.resize %d\n",x5180);
      int* x5183 = x4498;
      int* x5184 = (int*)realloc(x5183,x5180 * sizeof(int));
      x4498 = x5184;
      long* x5216 = x4520;
      long* x5217 = (long*)realloc(x5216,x5180 * sizeof(long));
      x4520 = x5217;
      long* x5219 = x4522;
      long* x5220 = (long*)realloc(x5219,x5180 * sizeof(long));
      x4522 = x5220;
    } else {
    }
    int* x5233 = x4498;
    x5233[x5177] = x4555;
    long* x5255 = x4520;
    long x5042 = x4993 * 10000L;
    long x5043 = x5017 * 100L;
    long x5044 = x5042 + x5043;
    long x5045 = x5044 + x5041;
    x5255[x5177] = x5045;
    long* x5257 = x4522;
    long x5118 = x5069 * 10000L;
    long x5119 = x5093 * 100L;
    long x5120 = x5118 + x5119;
    long x5121 = x5120 + x5117;
    x5257[x5177] = x5121;
    x4496 = x4496 + 1;
  }
  long x5268 = 0L;
  long x5269 = x6;
  long x5270 = 0L;
  int* x5271 = (int*)malloc(x6 * sizeof(int));
  int* x5272 = x5271;
  long* x5279 = (long*)malloc(x6 * sizeof(long));
  long* x5280 = x5279;
  char** x5281 = (char**)malloc(x6 * sizeof(char*));
  char** x5282 = x5281;
  int x3371 = open("../databases/sf2/orders.tbl",0);
  long x3372 = fsize(x3371);
  char* x3373 = mmap(0, x3372, PROT_READ, MAP_FILE | MAP_SHARED, x3371, 0);
  for (;;) {
    long x5289 = x5268;
    bool x5290 = x5289 < x3372;
    if (!x5290) break;
    int x5293 = 0;
    for (;;) {
      long x5294 = x5268;
      char x5295 = x3373[x5294];
      bool x5296 = x5295 != '|';
      bool x5301 = x5296;
      if (x5296) {
        long x5297 = x5268;
        char x5298 = x3373[x5297];
        bool x5299 = x5298 != '\n';
        x5301 = x5299;
      }
      bool x5302 = x5301;
      if (!x5302) break;
      int x5304 = x5293;
      long x5306 = x5268;
      int x5305 = x5304 * 10;
      char x5307 = x3373[x5306];
      char x5308 = x5307 - '0';
      int x5309 = x5305 + x5308;
      x5293 = x5309;
      x5268 = x5268 + 1;
    }
    x5268 = x5268 + 1;
    int x5315 = x5293;
    for (;;) {
      long x5318 = x5268;
      char x5319 = x3373[x5318];
      bool x5320 = x5319 != '|';
      bool x5325 = x5320;
      if (x5320) {
        long x5321 = x5268;
        char x5322 = x3373[x5321];
        bool x5323 = x5322 != '\n';
        x5325 = x5323;
      }
      bool x5326 = x5325;
      if (!x5326) break;
      x5268 = x5268 + 1;
    }
    x5268 = x5268 + 1;
    x5268 = x5268 + 2;
    for (;;) {
      long x5346 = x5268;
      char x5347 = x3373[x5346];
      bool x5348 = x5347 != '.';
      bool x5353 = x5348;
      if (x5348) {
        long x5349 = x5268;
        char x5350 = x3373[x5349];
        bool x5351 = x5350 != '|';
        x5353 = x5351;
      }
      bool x5354 = x5353;
      bool x5359 = x5354;
      if (x5354) {
        long x5355 = x5268;
        char x5356 = x3373[x5355];
        bool x5357 = x5356 != '\n';
        x5359 = x5357;
      }
      bool x5360 = x5359;
      if (!x5360) break;
      x5268 = x5268 + 1;
    }
    long x5372 = x5268;
    char x5373 = x3373[x5372];
    bool x5374 = x5373 == '.';
    if (x5374) {
      x5268 = x5268 + 1;
      for (;;) {
        long x5376 = x5268;
        char x5377 = x3373[x5376];
        bool x5378 = x5377 != '|';
        bool x5383 = x5378;
        if (x5378) {
          long x5379 = x5268;
          char x5380 = x3373[x5379];
          bool x5381 = x5380 != '\n';
          x5383 = x5381;
        }
        bool x5384 = x5383;
        if (!x5384) break;
        x5268 = x5268 + 1;
      }
    } else {
    }
    x5268 = x5268 + 1;
    int x5409 = 0;
    for (;;) {
      long x5410 = x5268;
      char x5411 = x3373[x5410];
      bool x5412 = x5411 != '-';
      bool x5417 = x5412;
      if (x5412) {
        long x5413 = x5268;
        char x5414 = x3373[x5413];
        bool x5415 = x5414 != '\n';
        x5417 = x5415;
      }
      bool x5418 = x5417;
      if (!x5418) break;
      int x5420 = x5409;
      long x5422 = x5268;
      int x5421 = x5420 * 10;
      char x5423 = x3373[x5422];
      char x5424 = x5423 - '0';
      int x5425 = x5421 + x5424;
      x5409 = x5425;
      x5268 = x5268 + 1;
    }
    x5268 = x5268 + 1;
    int x5431 = x5409;
    int x5433 = 0;
    for (;;) {
      long x5434 = x5268;
      char x5435 = x3373[x5434];
      bool x5436 = x5435 != '-';
      bool x5441 = x5436;
      if (x5436) {
        long x5437 = x5268;
        char x5438 = x3373[x5437];
        bool x5439 = x5438 != '\n';
        x5441 = x5439;
      }
      bool x5442 = x5441;
      if (!x5442) break;
      int x5444 = x5433;
      long x5446 = x5268;
      int x5445 = x5444 * 10;
      char x5447 = x3373[x5446];
      char x5448 = x5447 - '0';
      int x5449 = x5445 + x5448;
      x5433 = x5449;
      x5268 = x5268 + 1;
    }
    x5268 = x5268 + 1;
    int x5455 = x5433;
    int x5457 = 0;
    for (;;) {
      long x5458 = x5268;
      char x5459 = x3373[x5458];
      bool x5460 = x5459 != '|';
      bool x5465 = x5460;
      if (x5460) {
        long x5461 = x5268;
        char x5462 = x3373[x5461];
        bool x5463 = x5462 != '\n';
        x5465 = x5463;
      }
      bool x5466 = x5465;
      if (!x5466) break;
      int x5468 = x5457;
      long x5470 = x5268;
      int x5469 = x5468 * 10;
      char x5471 = x3373[x5470];
      char x5472 = x5471 - '0';
      int x5473 = x5469 + x5472;
      x5457 = x5473;
      x5268 = x5268 + 1;
    }
    x5268 = x5268 + 1;
    int x5479 = x5457;
    long x5484 = x5268;
    for (;;) {
      long x5485 = x5268;
      char x5486 = x3373[x5485];
      bool x5487 = x5486 != '|';
      bool x5492 = x5487;
      if (x5487) {
        long x5488 = x5268;
        char x5489 = x3373[x5488];
        bool x5490 = x5489 != '\n';
        x5492 = x5490;
      }
      bool x5493 = x5492;
      if (!x5493) break;
      x5268 = x5268 + 1;
    }
    x5268 = x5268 + 1;
    for (;;) {
      long x5503 = x5268;
      char x5504 = x3373[x5503];
      bool x5505 = x5504 != '|';
      bool x5510 = x5505;
      if (x5505) {
        long x5506 = x5268;
        char x5507 = x3373[x5506];
        bool x5508 = x5507 != '\n';
        x5510 = x5508;
      }
      bool x5511 = x5510;
      if (!x5511) break;
      x5268 = x5268 + 1;
    }
    x5268 = x5268 + 1;
    for (;;) {
      long x5522 = x5268;
      char x5523 = x3373[x5522];
      bool x5524 = x5523 != '|';
      bool x5529 = x5524;
      if (x5524) {
        long x5525 = x5268;
        char x5526 = x3373[x5525];
        bool x5527 = x5526 != '\n';
        x5529 = x5527;
      }
      bool x5530 = x5529;
      if (!x5530) break;
      x5268 = x5268 + 1;
    }
    x5268 = x5268 + 1;
    for (;;) {
      long x5545 = x5268;
      char x5546 = x3373[x5545];
      bool x5547 = x5546 != '|';
      bool x5552 = x5547;
      if (x5547) {
        long x5548 = x5268;
        char x5549 = x3373[x5548];
        bool x5550 = x5549 != '\n';
        x5552 = x5550;
      }
      bool x5553 = x5552;
      if (!x5553) break;
      x5268 = x5268 + 1;
    }
    x5268 = x5268 + 1;
    long x5563 = x5270;
    long x5564 = x5269;
    bool x5565 = x5563 == x5564;
    if (x5565) {
      long x5566 = x5564 * 4L;
      x5269 = x5566;
      printf("buffer.resize %d\n",x5566);
      int* x5569 = x5272;
      int* x5570 = (int*)realloc(x5569,x5566 * sizeof(int));
      x5272 = x5570;
      long* x5581 = x5280;
      long* x5582 = (long*)realloc(x5581,x5566 * sizeof(long));
      x5280 = x5582;
      char** x5584 = x5282;
      char** x5585 = (char**)realloc(x5584,x5566 * sizeof(char*));
      x5282 = x5585;
    } else {
    }
    int* x5598 = x5272;
    x5598[x5563] = x5315;
    long* x5606 = x5280;
    long x5480 = x5431 * 10000L;
    long x5481 = x5455 * 100L;
    long x5482 = x5480 + x5481;
    long x5483 = x5482 + x5479;
    x5606[x5563] = x5483;
    char** x5608 = x5282;
    char* x5501 = x3373+x5484;
    x5608[x5563] = x5501;
    x5270 = x5270 + 1;
  }
  long x2011 = DEFAULT_JOIN_HASH_SIZE;
  long x787 = DEFAULT_AGG_HASH_SIZE ;
  long x2034 = x2011 - 1L;
  long x802 = x787 - 1L;
  struct Anon2052879266 x5917;
  x5917._0 = 1.0;
  bool x975 = true == false;
  int x5619;
  for(x5619=0; x5619 < 5; x5619++) {
    bool x5620 = false;
    long x5621 = 0L;
    bool x5623 = false;
    long x5624 = 0L;
    int* x5627 = (int*)malloc(x2011 * sizeof(int));
    int* x5628 = x5627;
    long x5659 = 0L;
    long* x5660 = (long*)malloc(x2011 * sizeof(long));
    long* x5661 = (long*)malloc(x2011 * sizeof(long));
    long x5662;
    for(x5662=0L; x5662 < x2011; x5662++) {
      x5660[x5662] = -1L;
    }
    struct Anon801061462* x5667 = (struct Anon801061462*)malloc(x787 * sizeof(struct Anon801061462));
    struct Anon801061462* x5668 = x5667;
    long x5669 = 0L;
    long* x5670 = (long*)malloc(x787 * sizeof(long));
    long x5671;
    for(x5671=0L; x5671 < x787; x5671++) {
      struct Anon801061462* x5672 = x5668;
      struct Anon801061462 x5673 = x5672[x5671];
      char* x5674 = x5673.key;;
      struct Anon2052879266 x5675 = x5673.aggs;;
      struct Anon801061462 x5676;
      x5676.exists = false;
      x5676.key = x5674;
      x5676.aggs = x5675;
      x5672[x5671] = x5676;
    }
    long x5681 = 0L;
    struct timeval x5961, x5962, x5963;
    gettimeofday(&x5961, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x5683 = x5623;
      bool x5684 = !x5683;
      bool x5689 = x5684;
      if (x5684) {
        long x5685 = x5624;
        long x5686 = x4496;
        bool x5687 = x5685 < x5686;
        x5689 = x5687;
      }
      bool x5690 = x5689;
      if (!x5690) break;
      long x5692 = x5624;
      int* x5693 = x4498;
      int x5694 = x5693[x5692];
      long* x5715 = x4520;
      long x5716 = x5715[x5692];
      long* x5717 = x4522;
      long x5718 = x5717[x5692];
      x5624 = x5624 + 1;
      bool x5727 = x5716 < x5718;
      if (x5727) {
        long x5728 = x5659;
        int* x5729 = x5628;
        x5729[x5728] = x5694;
        x5659 = x5659 + 1L;
        long x5762 = x5694 & x2034;
        long x5763 = x5660[x5762];
        x5660[x5762] = x5728;
        x5661[x5728] = x5763;
      } else {
      }
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x5771 = x5620;
      bool x5772 = !x5771;
      bool x5777 = x5772;
      if (x5772) {
        long x5773 = x5621;
        long x5774 = x5270;
        bool x5775 = x5773 < x5774;
        x5777 = x5775;
      }
      bool x5778 = x5777;
      if (!x5778) break;
      long x5780 = x5621;
      int* x5781 = x5272;
      int x5782 = x5781[x5780];
      long* x5789 = x5280;
      long x5790 = x5789[x5780];
      char** x5791 = x5282;
      char* x5792 = x5791[x5780];
      x5621 = x5621 + 1;
      bool x5801 = x5790 < 19931101L;
      bool x5803 = x5801;
      if (x5801) {
        bool x5802 = x5790 >= 19930801L;
        x5803 = x5802;
      }
      bool x5804 = x5803;
      if (x5804) {
        long x5805 = x5782 & x2034;
        long x5806 = x5660[x5805];
        long x5807 = x5806;
        bool x5808 = x5806 == -1L;
        bool x5809 = x5808;
        for (;;) {
          bool x5810 = x5809;
          bool x5811 = !x5810;
          if (!x5811) break;
          long x5813 = x5807;
          int* x5814 = x5628;
          int x5815 = x5814[x5813];
          bool x5847 = x5782 == x5815;
          if (x5847) {
            x5809 = true;
          } else {
            long x5850 = x5661[x5813];
            x5807 = x5850;
            bool x5852 = x5850 == -1;
            x5809 = x5852;
          }
        }
        long x5858 = x5807;
        bool x5860 = x5858 == -1;
        if (x5860) {
        } else {
          char x5861 = x5792[0L];
          long x5862 = x5861 * 41L;
          char x5863 = x5792[1L];
          long x5864 = x5862 + x5863;
          long x5865 = x5864 * 41L;
          char x5866 = x5792[2L];
          long x5867 = x5865 + x5866;
          long x5868 = x5867 * 41L;
          char x5869 = x5792[3L];
          long x5870 = x5868 + x5869;
          long x5871 = x5870 & x802;
          long x5872 = x5871;
          struct Anon801061462* x5873 = x5668;
          struct Anon801061462 x5874 = x5873[x5871];
          struct Anon801061462 x5875 = x5874;
          bool x5876 = x5874.exists;;
          bool x5881 = x5876;
          if (x5876) {
            struct Anon801061462 x5877 = x5875;
            char* x5878 = x5877.key;;
            bool x5879 = strcmp(x5878,x5792) == 0;;
            x5881 = x5879;
          }
          bool x5882 = x5881;
          if (x5882) {
            struct Anon2052879266 x5883 = x5874.aggs;;
            char* x5887 = x5874.key;;
            double x5884 = x5883._0;;
            double x5885 = x5884 + 1.0;
            struct Anon2052879266 x5886;
            x5886._0 = x5885;
            struct Anon801061462 x5888;
            x5888.exists = true;
            x5888.key = x5887;
            x5888.aggs = x5886;
            x5873[x5871] = x5888;
          } else {
            struct Anon801061462 x5918;
            x5918.exists = true;
            x5918.key = x5792;
            x5918.aggs = x5917;
            for (;;) {
              struct Anon801061462 x5891 = x5875;
              bool x5892 = x5891.exists;;
              bool x5927;
              if (x5892) {
                char* x5893 = x5891.key;;
                bool x5894 = strcmp(x5893,x5792) == 0;;
                bool x5914;
                if (x5894) {
                  struct Anon2052879266 x5895 = x5891.aggs;;
                  long x5899 = x5872;
                  struct Anon801061462* x5901 = x5668;
                  double x5896 = x5895._0;;
                  double x5897 = x5896 + 1.0;
                  struct Anon2052879266 x5898;
                  x5898._0 = x5897;
                  struct Anon801061462 x5900;
                  x5900.exists = true;
                  x5900.key = x5893;
                  x5900.aggs = x5898;
                  x5901[x5899] = x5900;
                  x5914 = false;
                } else {
                  long x5904 = x5872;
                  long x5905 = x5904 + 1L;
                  long x5906 = x5905 % x802;
                  x5872 = x5906;
                  struct Anon801061462* x5908 = x5668;
                  struct Anon801061462 x5909 = x5908[x5906];
                  x5875 = x5909;
                  x5914 = true;
                }
                x5927 = x5914;
              } else {
                long x5916 = x5872;
                struct Anon801061462* x5919 = x5668;
                x5919[x5916] = x5918;
                long x5921 = x5669;
                x5670[x5921] = x5916;
                x5669 = x5669 + 1L;
                x5927 = false;
              }
              if (!x5927) break;
            }
          }
        }
      } else {
      }
    }
    long x5940 = x5669;
    long x5942;
    for(x5942=0L; x5942 < x5940; x5942++) {
      long x5943 = x5670[x5942];
      struct Anon801061462* x5944 = x5668;
      struct Anon801061462 x5945 = x5944[x5943];
      if (x975) {
      } else {
        char* x5948 = x5945.key;;
        struct Anon2052879266 x5950 = x5945.aggs;;
        int x5949 = strlen(x5948);
        double x5951 = x5950._0;;
        printf("%.*s|%.0f\n",x5949,x5948,x5951);
        x5681 = x5681 + 1L;
      }
    }
    long x5958 = x5681;
    printf("(%d rows)\n",x5958);
    gettimeofday(&x5962, NULL);
    timeval_subtract(&x5963, &x5962, &x5961);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x5963.tv_sec * 1000) + (x5963.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
