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

struct Anon1268892766 {
int S_SUPPKEY;
char* S_NAME;
char* S_ADDRESS;
int S_NATIONKEY;
char* S_PHONE;
double S_ACCTBAL;
char* S_COMMENT;
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
int main(int x4488, char** x4489) {
  int x4490 = 0;
  int x4491 = 1048576;
  int x4492 = 0;
  int* x4493 = (int*)malloc(1048576 * sizeof(int));
  int* x4494 = x4493;
  long* x4515 = (long*)malloc(1048576 * sizeof(long));
  long* x4516 = x4515;
  long* x4517 = (long*)malloc(1048576 * sizeof(long));
  long* x4518 = x4517;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  int x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    int x4525 = x4490;
    bool x4526 = x4525 < x3;
    if (!x4526) break;
    int x4529 = 0;
    for (;;) {
      int x4530 = x4490;
      char x4531 = x4[x4530];
      bool x4532 = x4531 != '|';
      bool x4537 = x4532;
      if (x4532) {
        int x4533 = x4490;
        char x4534 = x4[x4533];
        bool x4535 = x4534 != '\n';
        x4537 = x4535;
      }
      bool x4538 = x4537;
      if (!x4538) break;
      int x4540 = x4529;
      int x4542 = x4490;
      int x4541 = x4540 * 10;
      char x4543 = x4[x4542];
      char x4544 = x4543 - '0';
      int x4545 = x4541 + x4544;
      x4529 = x4545;
      x4490 = x4490 + 1;
    }
    x4490 = x4490 + 1;
    int x4551 = x4529;
    for (;;) {
      int x4554 = x4490;
      char x4555 = x4[x4554];
      bool x4556 = x4555 != '|';
      bool x4561 = x4556;
      if (x4556) {
        int x4557 = x4490;
        char x4558 = x4[x4557];
        bool x4559 = x4558 != '\n';
        x4561 = x4559;
      }
      bool x4562 = x4561;
      if (!x4562) break;
      x4490 = x4490 + 1;
    }
    x4490 = x4490 + 1;
    for (;;) {
      int x4578 = x4490;
      char x4579 = x4[x4578];
      bool x4580 = x4579 != '|';
      bool x4585 = x4580;
      if (x4580) {
        int x4581 = x4490;
        char x4582 = x4[x4581];
        bool x4583 = x4582 != '\n';
        x4585 = x4583;
      }
      bool x4586 = x4585;
      if (!x4586) break;
      x4490 = x4490 + 1;
    }
    x4490 = x4490 + 1;
    for (;;) {
      int x4602 = x4490;
      char x4603 = x4[x4602];
      bool x4604 = x4603 != '|';
      bool x4609 = x4604;
      if (x4604) {
        int x4605 = x4490;
        char x4606 = x4[x4605];
        bool x4607 = x4606 != '\n';
        x4609 = x4607;
      }
      bool x4610 = x4609;
      if (!x4610) break;
      x4490 = x4490 + 1;
    }
    x4490 = x4490 + 1;
    for (;;) {
      int x4627 = x4490;
      char x4628 = x4[x4627];
      bool x4629 = x4628 != '.';
      bool x4634 = x4629;
      if (x4629) {
        int x4630 = x4490;
        char x4631 = x4[x4630];
        bool x4632 = x4631 != '|';
        x4634 = x4632;
      }
      bool x4635 = x4634;
      bool x4640 = x4635;
      if (x4635) {
        int x4636 = x4490;
        char x4637 = x4[x4636];
        bool x4638 = x4637 != '\n';
        x4640 = x4638;
      }
      bool x4641 = x4640;
      if (!x4641) break;
      x4490 = x4490 + 1;
    }
    int x4653 = x4490;
    char x4654 = x4[x4653];
    bool x4655 = x4654 == '.';
    if (x4655) {
      x4490 = x4490 + 1;
      for (;;) {
        int x4657 = x4490;
        char x4658 = x4[x4657];
        bool x4659 = x4658 != '|';
        bool x4664 = x4659;
        if (x4659) {
          int x4660 = x4490;
          char x4661 = x4[x4660];
          bool x4662 = x4661 != '\n';
          x4664 = x4662;
        }
        bool x4665 = x4664;
        if (!x4665) break;
        x4490 = x4490 + 1;
      }
    } else {
    }
    x4490 = x4490 + 1;
    for (;;) {
      int x4692 = x4490;
      char x4693 = x4[x4692];
      bool x4694 = x4693 != '.';
      bool x4699 = x4694;
      if (x4694) {
        int x4695 = x4490;
        char x4696 = x4[x4695];
        bool x4697 = x4696 != '|';
        x4699 = x4697;
      }
      bool x4700 = x4699;
      bool x4705 = x4700;
      if (x4700) {
        int x4701 = x4490;
        char x4702 = x4[x4701];
        bool x4703 = x4702 != '\n';
        x4705 = x4703;
      }
      bool x4706 = x4705;
      if (!x4706) break;
      x4490 = x4490 + 1;
    }
    int x4718 = x4490;
    char x4719 = x4[x4718];
    bool x4720 = x4719 == '.';
    if (x4720) {
      x4490 = x4490 + 1;
      for (;;) {
        int x4722 = x4490;
        char x4723 = x4[x4722];
        bool x4724 = x4723 != '|';
        bool x4729 = x4724;
        if (x4724) {
          int x4725 = x4490;
          char x4726 = x4[x4725];
          bool x4727 = x4726 != '\n';
          x4729 = x4727;
        }
        bool x4730 = x4729;
        if (!x4730) break;
        x4490 = x4490 + 1;
      }
    } else {
    }
    x4490 = x4490 + 1;
    for (;;) {
      int x4757 = x4490;
      char x4758 = x4[x4757];
      bool x4759 = x4758 != '.';
      bool x4764 = x4759;
      if (x4759) {
        int x4760 = x4490;
        char x4761 = x4[x4760];
        bool x4762 = x4761 != '|';
        x4764 = x4762;
      }
      bool x4765 = x4764;
      bool x4770 = x4765;
      if (x4765) {
        int x4766 = x4490;
        char x4767 = x4[x4766];
        bool x4768 = x4767 != '\n';
        x4770 = x4768;
      }
      bool x4771 = x4770;
      if (!x4771) break;
      x4490 = x4490 + 1;
    }
    int x4783 = x4490;
    char x4784 = x4[x4783];
    bool x4785 = x4784 == '.';
    if (x4785) {
      x4490 = x4490 + 1;
      for (;;) {
        int x4787 = x4490;
        char x4788 = x4[x4787];
        bool x4789 = x4788 != '|';
        bool x4794 = x4789;
        if (x4789) {
          int x4790 = x4490;
          char x4791 = x4[x4790];
          bool x4792 = x4791 != '\n';
          x4794 = x4792;
        }
        bool x4795 = x4794;
        if (!x4795) break;
        x4490 = x4490 + 1;
      }
    } else {
    }
    x4490 = x4490 + 1;
    for (;;) {
      int x4822 = x4490;
      char x4823 = x4[x4822];
      bool x4824 = x4823 != '.';
      bool x4829 = x4824;
      if (x4824) {
        int x4825 = x4490;
        char x4826 = x4[x4825];
        bool x4827 = x4826 != '|';
        x4829 = x4827;
      }
      bool x4830 = x4829;
      bool x4835 = x4830;
      if (x4830) {
        int x4831 = x4490;
        char x4832 = x4[x4831];
        bool x4833 = x4832 != '\n';
        x4835 = x4833;
      }
      bool x4836 = x4835;
      if (!x4836) break;
      x4490 = x4490 + 1;
    }
    int x4848 = x4490;
    char x4849 = x4[x4848];
    bool x4850 = x4849 == '.';
    if (x4850) {
      x4490 = x4490 + 1;
      for (;;) {
        int x4852 = x4490;
        char x4853 = x4[x4852];
        bool x4854 = x4853 != '|';
        bool x4859 = x4854;
        if (x4854) {
          int x4855 = x4490;
          char x4856 = x4[x4855];
          bool x4857 = x4856 != '\n';
          x4859 = x4857;
        }
        bool x4860 = x4859;
        if (!x4860) break;
        x4490 = x4490 + 1;
      }
    } else {
    }
    x4490 = x4490 + 1;
    x4490 = x4490 + 2;
    x4490 = x4490 + 2;
    for (;;) {
      int x4892 = x4490;
      char x4893 = x4[x4892];
      bool x4894 = x4893 != '-';
      bool x4899 = x4894;
      if (x4894) {
        int x4895 = x4490;
        char x4896 = x4[x4895];
        bool x4897 = x4896 != '\n';
        x4899 = x4897;
      }
      bool x4900 = x4899;
      if (!x4900) break;
      x4490 = x4490 + 1;
    }
    x4490 = x4490 + 1;
    for (;;) {
      int x4916 = x4490;
      char x4917 = x4[x4916];
      bool x4918 = x4917 != '-';
      bool x4923 = x4918;
      if (x4918) {
        int x4919 = x4490;
        char x4920 = x4[x4919];
        bool x4921 = x4920 != '\n';
        x4923 = x4921;
      }
      bool x4924 = x4923;
      if (!x4924) break;
      x4490 = x4490 + 1;
    }
    x4490 = x4490 + 1;
    for (;;) {
      int x4940 = x4490;
      char x4941 = x4[x4940];
      bool x4942 = x4941 != '|';
      bool x4947 = x4942;
      if (x4942) {
        int x4943 = x4490;
        char x4944 = x4[x4943];
        bool x4945 = x4944 != '\n';
        x4947 = x4945;
      }
      bool x4948 = x4947;
      if (!x4948) break;
      x4490 = x4490 + 1;
    }
    x4490 = x4490 + 1;
    int x4967 = 0;
    for (;;) {
      int x4968 = x4490;
      char x4969 = x4[x4968];
      bool x4970 = x4969 != '-';
      bool x4975 = x4970;
      if (x4970) {
        int x4971 = x4490;
        char x4972 = x4[x4971];
        bool x4973 = x4972 != '\n';
        x4975 = x4973;
      }
      bool x4976 = x4975;
      if (!x4976) break;
      int x4978 = x4967;
      int x4980 = x4490;
      int x4979 = x4978 * 10;
      char x4981 = x4[x4980];
      char x4982 = x4981 - '0';
      int x4983 = x4979 + x4982;
      x4967 = x4983;
      x4490 = x4490 + 1;
    }
    x4490 = x4490 + 1;
    int x4989 = x4967;
    int x4991 = 0;
    for (;;) {
      int x4992 = x4490;
      char x4993 = x4[x4992];
      bool x4994 = x4993 != '-';
      bool x4999 = x4994;
      if (x4994) {
        int x4995 = x4490;
        char x4996 = x4[x4995];
        bool x4997 = x4996 != '\n';
        x4999 = x4997;
      }
      bool x5000 = x4999;
      if (!x5000) break;
      int x5002 = x4991;
      int x5004 = x4490;
      int x5003 = x5002 * 10;
      char x5005 = x4[x5004];
      char x5006 = x5005 - '0';
      int x5007 = x5003 + x5006;
      x4991 = x5007;
      x4490 = x4490 + 1;
    }
    x4490 = x4490 + 1;
    int x5013 = x4991;
    int x5015 = 0;
    for (;;) {
      int x5016 = x4490;
      char x5017 = x4[x5016];
      bool x5018 = x5017 != '|';
      bool x5023 = x5018;
      if (x5018) {
        int x5019 = x4490;
        char x5020 = x4[x5019];
        bool x5021 = x5020 != '\n';
        x5023 = x5021;
      }
      bool x5024 = x5023;
      if (!x5024) break;
      int x5026 = x5015;
      int x5028 = x4490;
      int x5027 = x5026 * 10;
      char x5029 = x4[x5028];
      char x5030 = x5029 - '0';
      int x5031 = x5027 + x5030;
      x5015 = x5031;
      x4490 = x4490 + 1;
    }
    x4490 = x4490 + 1;
    int x5037 = x5015;
    int x5043 = 0;
    for (;;) {
      int x5044 = x4490;
      char x5045 = x4[x5044];
      bool x5046 = x5045 != '-';
      bool x5051 = x5046;
      if (x5046) {
        int x5047 = x4490;
        char x5048 = x4[x5047];
        bool x5049 = x5048 != '\n';
        x5051 = x5049;
      }
      bool x5052 = x5051;
      if (!x5052) break;
      int x5054 = x5043;
      int x5056 = x4490;
      int x5055 = x5054 * 10;
      char x5057 = x4[x5056];
      char x5058 = x5057 - '0';
      int x5059 = x5055 + x5058;
      x5043 = x5059;
      x4490 = x4490 + 1;
    }
    x4490 = x4490 + 1;
    int x5065 = x5043;
    int x5067 = 0;
    for (;;) {
      int x5068 = x4490;
      char x5069 = x4[x5068];
      bool x5070 = x5069 != '-';
      bool x5075 = x5070;
      if (x5070) {
        int x5071 = x4490;
        char x5072 = x4[x5071];
        bool x5073 = x5072 != '\n';
        x5075 = x5073;
      }
      bool x5076 = x5075;
      if (!x5076) break;
      int x5078 = x5067;
      int x5080 = x4490;
      int x5079 = x5078 * 10;
      char x5081 = x4[x5080];
      char x5082 = x5081 - '0';
      int x5083 = x5079 + x5082;
      x5067 = x5083;
      x4490 = x4490 + 1;
    }
    x4490 = x4490 + 1;
    int x5089 = x5067;
    int x5091 = 0;
    for (;;) {
      int x5092 = x4490;
      char x5093 = x4[x5092];
      bool x5094 = x5093 != '|';
      bool x5099 = x5094;
      if (x5094) {
        int x5095 = x4490;
        char x5096 = x4[x5095];
        bool x5097 = x5096 != '\n';
        x5099 = x5097;
      }
      bool x5100 = x5099;
      if (!x5100) break;
      int x5102 = x5091;
      int x5104 = x4490;
      int x5103 = x5102 * 10;
      char x5105 = x4[x5104];
      char x5106 = x5105 - '0';
      int x5107 = x5103 + x5106;
      x5091 = x5107;
      x4490 = x4490 + 1;
    }
    x4490 = x4490 + 1;
    int x5113 = x5091;
    for (;;) {
      int x5119 = x4490;
      char x5120 = x4[x5119];
      bool x5121 = x5120 != '|';
      bool x5126 = x5121;
      if (x5121) {
        int x5122 = x4490;
        char x5123 = x4[x5122];
        bool x5124 = x5123 != '\n';
        x5126 = x5124;
      }
      bool x5127 = x5126;
      if (!x5127) break;
      x4490 = x4490 + 1;
    }
    x4490 = x4490 + 1;
    for (;;) {
      int x5137 = x4490;
      char x5138 = x4[x5137];
      bool x5139 = x5138 != '|';
      bool x5144 = x5139;
      if (x5139) {
        int x5140 = x4490;
        char x5141 = x4[x5140];
        bool x5142 = x5141 != '\n';
        x5144 = x5142;
      }
      bool x5145 = x5144;
      if (!x5145) break;
      x4490 = x4490 + 1;
    }
    x4490 = x4490 + 1;
    for (;;) {
      int x5155 = x4490;
      char x5156 = x4[x5155];
      bool x5157 = x5156 != '|';
      bool x5162 = x5157;
      if (x5157) {
        int x5158 = x4490;
        char x5159 = x4[x5158];
        bool x5160 = x5159 != '\n';
        x5162 = x5160;
      }
      bool x5163 = x5162;
      if (!x5163) break;
      x4490 = x4490 + 1;
    }
    x4490 = x4490 + 1;
    int x5173 = x4492;
    int x5174 = x4491;
    bool x5175 = x5173 == x5174;
    if (x5175) {
      int x5176 = x5174 * 4;
      x4491 = x5176;
      printf("buffer.resize %d\n",x5176);
      int* x5179 = x4494;
      int* x5180 = (int*)realloc(x5179,x5176 * sizeof(int));
      x4494 = x5180;
      long* x5212 = x4516;
      long* x5213 = (long*)realloc(x5212,x5176 * sizeof(long));
      x4516 = x5213;
      long* x5215 = x4518;
      long* x5216 = (long*)realloc(x5215,x5176 * sizeof(long));
      x4518 = x5216;
    } else {
    }
    int* x5229 = x4494;
    x5229[x5173] = x4551;
    long* x5251 = x4516;
    long x5038 = x4989 * 10000L;
    long x5039 = x5013 * 100L;
    long x5040 = x5038 + x5039;
    long x5041 = x5040 + x5037;
    x5251[x5173] = x5041;
    long* x5253 = x4518;
    long x5114 = x5065 * 10000L;
    long x5115 = x5089 * 100L;
    long x5116 = x5114 + x5115;
    long x5117 = x5116 + x5113;
    x5253[x5173] = x5117;
    x4492 = x4492 + 1;
  }
  int x5264 = 0;
  int x5265 = 1048576;
  int x5266 = 0;
  int* x5267 = (int*)malloc(1048576 * sizeof(int));
  int* x5268 = x5267;
  long* x5275 = (long*)malloc(1048576 * sizeof(long));
  long* x5276 = x5275;
  char** x5277 = (char**)malloc(1048576 * sizeof(char*));
  char** x5278 = x5277;
  int x3366 = open("../databases/sf2/orders.tbl",0);
  int x3367 = fsize(x3366);
  char* x3368 = mmap(0, x3367, PROT_READ, MAP_FILE | MAP_SHARED, x3366, 0);
  for (;;) {
    int x5285 = x5264;
    bool x5286 = x5285 < x3367;
    if (!x5286) break;
    int x5289 = 0;
    for (;;) {
      int x5290 = x5264;
      char x5291 = x3368[x5290];
      bool x5292 = x5291 != '|';
      bool x5297 = x5292;
      if (x5292) {
        int x5293 = x5264;
        char x5294 = x3368[x5293];
        bool x5295 = x5294 != '\n';
        x5297 = x5295;
      }
      bool x5298 = x5297;
      if (!x5298) break;
      int x5300 = x5289;
      int x5302 = x5264;
      int x5301 = x5300 * 10;
      char x5303 = x3368[x5302];
      char x5304 = x5303 - '0';
      int x5305 = x5301 + x5304;
      x5289 = x5305;
      x5264 = x5264 + 1;
    }
    x5264 = x5264 + 1;
    int x5311 = x5289;
    for (;;) {
      int x5314 = x5264;
      char x5315 = x3368[x5314];
      bool x5316 = x5315 != '|';
      bool x5321 = x5316;
      if (x5316) {
        int x5317 = x5264;
        char x5318 = x3368[x5317];
        bool x5319 = x5318 != '\n';
        x5321 = x5319;
      }
      bool x5322 = x5321;
      if (!x5322) break;
      x5264 = x5264 + 1;
    }
    x5264 = x5264 + 1;
    x5264 = x5264 + 2;
    for (;;) {
      int x5342 = x5264;
      char x5343 = x3368[x5342];
      bool x5344 = x5343 != '.';
      bool x5349 = x5344;
      if (x5344) {
        int x5345 = x5264;
        char x5346 = x3368[x5345];
        bool x5347 = x5346 != '|';
        x5349 = x5347;
      }
      bool x5350 = x5349;
      bool x5355 = x5350;
      if (x5350) {
        int x5351 = x5264;
        char x5352 = x3368[x5351];
        bool x5353 = x5352 != '\n';
        x5355 = x5353;
      }
      bool x5356 = x5355;
      if (!x5356) break;
      x5264 = x5264 + 1;
    }
    int x5368 = x5264;
    char x5369 = x3368[x5368];
    bool x5370 = x5369 == '.';
    if (x5370) {
      x5264 = x5264 + 1;
      for (;;) {
        int x5372 = x5264;
        char x5373 = x3368[x5372];
        bool x5374 = x5373 != '|';
        bool x5379 = x5374;
        if (x5374) {
          int x5375 = x5264;
          char x5376 = x3368[x5375];
          bool x5377 = x5376 != '\n';
          x5379 = x5377;
        }
        bool x5380 = x5379;
        if (!x5380) break;
        x5264 = x5264 + 1;
      }
    } else {
    }
    x5264 = x5264 + 1;
    int x5405 = 0;
    for (;;) {
      int x5406 = x5264;
      char x5407 = x3368[x5406];
      bool x5408 = x5407 != '-';
      bool x5413 = x5408;
      if (x5408) {
        int x5409 = x5264;
        char x5410 = x3368[x5409];
        bool x5411 = x5410 != '\n';
        x5413 = x5411;
      }
      bool x5414 = x5413;
      if (!x5414) break;
      int x5416 = x5405;
      int x5418 = x5264;
      int x5417 = x5416 * 10;
      char x5419 = x3368[x5418];
      char x5420 = x5419 - '0';
      int x5421 = x5417 + x5420;
      x5405 = x5421;
      x5264 = x5264 + 1;
    }
    x5264 = x5264 + 1;
    int x5427 = x5405;
    int x5429 = 0;
    for (;;) {
      int x5430 = x5264;
      char x5431 = x3368[x5430];
      bool x5432 = x5431 != '-';
      bool x5437 = x5432;
      if (x5432) {
        int x5433 = x5264;
        char x5434 = x3368[x5433];
        bool x5435 = x5434 != '\n';
        x5437 = x5435;
      }
      bool x5438 = x5437;
      if (!x5438) break;
      int x5440 = x5429;
      int x5442 = x5264;
      int x5441 = x5440 * 10;
      char x5443 = x3368[x5442];
      char x5444 = x5443 - '0';
      int x5445 = x5441 + x5444;
      x5429 = x5445;
      x5264 = x5264 + 1;
    }
    x5264 = x5264 + 1;
    int x5451 = x5429;
    int x5453 = 0;
    for (;;) {
      int x5454 = x5264;
      char x5455 = x3368[x5454];
      bool x5456 = x5455 != '|';
      bool x5461 = x5456;
      if (x5456) {
        int x5457 = x5264;
        char x5458 = x3368[x5457];
        bool x5459 = x5458 != '\n';
        x5461 = x5459;
      }
      bool x5462 = x5461;
      if (!x5462) break;
      int x5464 = x5453;
      int x5466 = x5264;
      int x5465 = x5464 * 10;
      char x5467 = x3368[x5466];
      char x5468 = x5467 - '0';
      int x5469 = x5465 + x5468;
      x5453 = x5469;
      x5264 = x5264 + 1;
    }
    x5264 = x5264 + 1;
    int x5475 = x5453;
    int x5480 = x5264;
    for (;;) {
      int x5481 = x5264;
      char x5482 = x3368[x5481];
      bool x5483 = x5482 != '|';
      bool x5488 = x5483;
      if (x5483) {
        int x5484 = x5264;
        char x5485 = x3368[x5484];
        bool x5486 = x5485 != '\n';
        x5488 = x5486;
      }
      bool x5489 = x5488;
      if (!x5489) break;
      x5264 = x5264 + 1;
    }
    x5264 = x5264 + 1;
    for (;;) {
      int x5499 = x5264;
      char x5500 = x3368[x5499];
      bool x5501 = x5500 != '|';
      bool x5506 = x5501;
      if (x5501) {
        int x5502 = x5264;
        char x5503 = x3368[x5502];
        bool x5504 = x5503 != '\n';
        x5506 = x5504;
      }
      bool x5507 = x5506;
      if (!x5507) break;
      x5264 = x5264 + 1;
    }
    x5264 = x5264 + 1;
    for (;;) {
      int x5518 = x5264;
      char x5519 = x3368[x5518];
      bool x5520 = x5519 != '|';
      bool x5525 = x5520;
      if (x5520) {
        int x5521 = x5264;
        char x5522 = x3368[x5521];
        bool x5523 = x5522 != '\n';
        x5525 = x5523;
      }
      bool x5526 = x5525;
      if (!x5526) break;
      x5264 = x5264 + 1;
    }
    x5264 = x5264 + 1;
    for (;;) {
      int x5541 = x5264;
      char x5542 = x3368[x5541];
      bool x5543 = x5542 != '|';
      bool x5548 = x5543;
      if (x5543) {
        int x5544 = x5264;
        char x5545 = x3368[x5544];
        bool x5546 = x5545 != '\n';
        x5548 = x5546;
      }
      bool x5549 = x5548;
      if (!x5549) break;
      x5264 = x5264 + 1;
    }
    x5264 = x5264 + 1;
    int x5559 = x5266;
    int x5560 = x5265;
    bool x5561 = x5559 == x5560;
    if (x5561) {
      int x5562 = x5560 * 4;
      x5265 = x5562;
      printf("buffer.resize %d\n",x5562);
      int* x5565 = x5268;
      int* x5566 = (int*)realloc(x5565,x5562 * sizeof(int));
      x5268 = x5566;
      long* x5577 = x5276;
      long* x5578 = (long*)realloc(x5577,x5562 * sizeof(long));
      x5276 = x5578;
      char** x5580 = x5278;
      char** x5581 = (char**)realloc(x5580,x5562 * sizeof(char*));
      x5278 = x5581;
    } else {
    }
    int* x5594 = x5268;
    x5594[x5559] = x5311;
    long* x5602 = x5276;
    long x5476 = x5427 * 10000L;
    long x5477 = x5451 * 100L;
    long x5478 = x5476 + x5477;
    long x5479 = x5478 + x5475;
    x5602[x5559] = x5479;
    char** x5604 = x5278;
    char* x5497 = x3368+x5480;
    x5604[x5559] = x5497;
    x5266 = x5266 + 1;
  }
  struct Anon2052879266 x5913;
  x5913._0 = 1.0;
  bool x972 = true == false;
  int x5615;
  for(x5615=0; x5615 < 5; x5615++) {
    bool x5616 = false;
    int x5617 = 0;
    bool x5619 = false;
    int x5620 = 0;
    int* x5623 = (int*)malloc(134217728 * sizeof(int));
    int* x5624 = x5623;
    int x5655 = 0;
    int* x5656 = (int*)malloc(67108864 * sizeof(int));
    int* x5657 = (int*)malloc(134217728 * sizeof(int));
    int x5658;
    for(x5658=0; x5658 < 67108864; x5658++) {
      x5656[x5658] = -1;
    }
    struct Anon1007729034* x5663 = (struct Anon1007729034*)malloc(16777216 * sizeof(struct Anon1007729034));
    struct Anon1007729034* x5664 = x5663;
    int x5665 = 0;
    int* x5666 = (int*)malloc(16777216 * sizeof(int));
    int x5667;
    for(x5667=0; x5667 < 16777216; x5667++) {
      struct Anon1007729034* x5668 = x5664;
      struct Anon1007729034 x5669 = x5668[x5667];
      char* x5670 = x5669.key;;
      struct Anon2052879266 x5671 = x5669.aggs;;
      struct Anon1007729034 x5672;
      x5672.exists = false;
      x5672.key = x5670;
      x5672.aggs = x5671;
      x5668[x5667] = x5672;
    }
    int x5677 = 0;
    struct timeval x5957, x5958, x5959;
    gettimeofday(&x5957, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x5679 = x5619;
      bool x5680 = !x5679;
      bool x5685 = x5680;
      if (x5680) {
        int x5681 = x5620;
        int x5682 = x4492;
        bool x5683 = x5681 < x5682;
        x5685 = x5683;
      }
      bool x5686 = x5685;
      if (!x5686) break;
      int x5688 = x5620;
      int* x5689 = x4494;
      int x5690 = x5689[x5688];
      long* x5711 = x4516;
      long x5712 = x5711[x5688];
      long* x5713 = x4518;
      long x5714 = x5713[x5688];
      x5620 = x5620 + 1;
      bool x5723 = x5712 < x5714;
      if (x5723) {
        int x5724 = x5655;
        int* x5725 = x5624;
        x5725[x5724] = x5690;
        x5655 = x5655 + 1;
        int x5758 = x5690 & 67108863;
        int x5759 = x5656[x5758];
        x5656[x5758] = x5724;
        x5657[x5724] = x5759;
      } else {
      }
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x5767 = x5616;
      bool x5768 = !x5767;
      bool x5773 = x5768;
      if (x5768) {
        int x5769 = x5617;
        int x5770 = x5266;
        bool x5771 = x5769 < x5770;
        x5773 = x5771;
      }
      bool x5774 = x5773;
      if (!x5774) break;
      int x5776 = x5617;
      int* x5777 = x5268;
      int x5778 = x5777[x5776];
      long* x5785 = x5276;
      long x5786 = x5785[x5776];
      char** x5787 = x5278;
      char* x5788 = x5787[x5776];
      x5617 = x5617 + 1;
      bool x5797 = x5786 < 19931101L;
      bool x5799 = x5797;
      if (x5797) {
        bool x5798 = x5786 >= 19930801L;
        x5799 = x5798;
      }
      bool x5800 = x5799;
      if (x5800) {
        int x5801 = x5778 & 67108863;
        int x5802 = x5656[x5801];
        int x5803 = x5802;
        bool x5804 = x5802 == -1;
        bool x5805 = x5804;
        for (;;) {
          bool x5806 = x5805;
          bool x5807 = !x5806;
          if (!x5807) break;
          int x5809 = x5803;
          int* x5810 = x5624;
          int x5811 = x5810[x5809];
          bool x5843 = x5778 == x5811;
          if (x5843) {
            x5805 = true;
          } else {
            int x5846 = x5657[x5809];
            x5803 = x5846;
            bool x5848 = x5846 == -1;
            x5805 = x5848;
          }
        }
        int x5854 = x5803;
        bool x5856 = x5854 == -1;
        if (x5856) {
        } else {
          char x5857 = x5788[0];
          int x5858 = x5857 * 41;
          char x5859 = x5788[1];
          int x5860 = x5858 + x5859;
          int x5861 = x5860 * 41;
          char x5862 = x5788[2];
          int x5863 = x5861 + x5862;
          int x5864 = x5863 * 41;
          char x5865 = x5788[3];
          int x5866 = x5864 + x5865;
          int x5867 = x5866 & 16777215;
          int x5868 = x5867;
          struct Anon1007729034* x5869 = x5664;
          struct Anon1007729034 x5870 = x5869[x5867];
          struct Anon1007729034 x5871 = x5870;
          bool x5872 = x5870.exists;;
          bool x5877 = x5872;
          if (x5872) {
            struct Anon1007729034 x5873 = x5871;
            char* x5874 = x5873.key;;
            bool x5875 = strcmp(x5874,x5788) == 0;;
            x5877 = x5875;
          }
          bool x5878 = x5877;
          if (x5878) {
            struct Anon2052879266 x5879 = x5870.aggs;;
            char* x5883 = x5870.key;;
            double x5880 = x5879._0;;
            double x5881 = x5880 + 1.0;
            struct Anon2052879266 x5882;
            x5882._0 = x5881;
            struct Anon1007729034 x5884;
            x5884.exists = true;
            x5884.key = x5883;
            x5884.aggs = x5882;
            x5869[x5867] = x5884;
          } else {
            struct Anon1007729034 x5914;
            x5914.exists = true;
            x5914.key = x5788;
            x5914.aggs = x5913;
            for (;;) {
              struct Anon1007729034 x5887 = x5871;
              bool x5888 = x5887.exists;;
              bool x5923;
              if (x5888) {
                char* x5889 = x5887.key;;
                bool x5890 = strcmp(x5889,x5788) == 0;;
                bool x5910;
                if (x5890) {
                  struct Anon2052879266 x5891 = x5887.aggs;;
                  int x5895 = x5868;
                  struct Anon1007729034* x5897 = x5664;
                  double x5892 = x5891._0;;
                  double x5893 = x5892 + 1.0;
                  struct Anon2052879266 x5894;
                  x5894._0 = x5893;
                  struct Anon1007729034 x5896;
                  x5896.exists = true;
                  x5896.key = x5889;
                  x5896.aggs = x5894;
                  x5897[x5895] = x5896;
                  x5910 = false;
                } else {
                  int x5900 = x5868;
                  int x5901 = x5900 + 1;
                  int x5902 = x5901 % 16777215;
                  x5868 = x5902;
                  struct Anon1007729034* x5904 = x5664;
                  struct Anon1007729034 x5905 = x5904[x5902];
                  x5871 = x5905;
                  x5910 = true;
                }
                x5923 = x5910;
              } else {
                int x5912 = x5868;
                struct Anon1007729034* x5915 = x5664;
                x5915[x5912] = x5914;
                int x5917 = x5665;
                x5666[x5917] = x5912;
                x5665 = x5665 + 1;
                x5923 = false;
              }
              if (!x5923) break;
            }
          }
        }
      } else {
      }
    }
    int x5936 = x5665;
    int x5938;
    for(x5938=0; x5938 < x5936; x5938++) {
      int x5939 = x5666[x5938];
      struct Anon1007729034* x5940 = x5664;
      struct Anon1007729034 x5941 = x5940[x5939];
      if (x972) {
      } else {
        char* x5944 = x5941.key;;
        struct Anon2052879266 x5946 = x5941.aggs;;
        int x5945 = strlen(x5944);
        double x5947 = x5946._0;;
        printf("%.*s|%.0f\n",x5945,x5944,x5947);
        x5677 = x5677 + 1;
      }
    }
    int x5954 = x5677;
    printf("(%d rows)\n",x5954);
    gettimeofday(&x5958, NULL);
    timeval_subtract(&x5959, &x5958, &x5957);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x5959.tv_sec * 1000) + (x5959.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
