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
struct Anon920667905Anon811555534Anon168903330;
struct Anon1465150758;
struct Anon2134411685;
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

struct Anon2134411685 {
int key;
struct Anon1023322325* aggs;
};

struct Anon0 {
struct Anon1732223439* left;
struct Anon168903330* right;
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
int x5350(struct Anon1555625313* x3885, struct Anon1555625313* x3884);
int x5356(struct Anon1555625313* x5351, struct Anon1555625313* x5352, struct Anon1555625313** x5353);
int x5350(struct Anon1555625313* x3885, struct Anon1555625313* x3884) {
  struct Anon2052879266* x3886 = x3884->aggs;;
  double x3887 = x3886->_0;;
  struct Anon2052879266* x3888 = x3885->aggs;;
  double x3889 = x3888->_0;;
  bool x3890 = x3887 < x3889;
  int x4777;
  if (x3890) {
    x4777 = 1;
  } else {
    bool x3891 = x3887 > x3889;
    int x4775;
    if (x3891) {
      x4775 = -1;
    } else {
      struct Anon1465150758* x3892 = x3884->key;;
      long x3893 = x3892->O_ORDERDATE;;
      struct Anon1465150758* x3894 = x3885->key;;
      long x3895 = x3894->O_ORDERDATE;;
      bool x3896 = x3893 < x3895;
      int x4773;
      if (x3896) {
        x4773 = -1;
      } else {
        bool x3897 = x3893 > x3895;
        int x4771;
        if (x3897) {
          x4771 = 1;
        } else {
          x4771 = 0;
        }
        x4773 = x4771;
      }
      x4775 = x4773;
    }
    x4777 = x4775;
  }
  return x4777;
}
int x5356(struct Anon1555625313* x5351, struct Anon1555625313* x5352, struct Anon1555625313** x5353) {
  *x5353 = x5352;
  return 0;
}

/************************ MAIN BODY **************************/
int main(int x3409, char** x3410) {
  FILE* x4400 = fopen("../databases/sf2/lineitem.tbl", "r");
  int x4401 = 1048576;
  int x4402 = 0;
  int* x4403 = (int*)malloc(1048576 * sizeof(int));
  int* x4404 = x4403;
  double* x4413 = (double*)malloc(1048576 * sizeof(double));
  double* x4414 = x4413;
  double* x4415 = (double*)malloc(1048576 * sizeof(double));
  double* x4416 = x4415;
  long* x4423 = (long*)malloc(1048576 * sizeof(long));
  long* x4424 = x4423;
  for (;;) {
    bool x4435 = !feof(x4400);
    if (!x4435) break;
    int x4437 = 0;
    if (fscanf(x4400,"%d|",&x4437) == EOF) break;
    int x4438 = 0;
    if (fscanf(x4400,"%d|",&x4438) == EOF) break;
    int x4439 = 0;
    if (fscanf(x4400,"%d|",&x4439) == EOF) break;
    int x4440 = 0;
    if (fscanf(x4400,"%d|",&x4440) == EOF) break;
    double x4441 = 0.0;
    if (fscanf(x4400,"%lf|",&x4441) == EOF) break;
    double x4442 = 0.0;
    if (fscanf(x4400,"%lf|",&x4442) == EOF) break;
    double x4443 = 0.0;
    if (fscanf(x4400,"%lf|",&x4443) == EOF) break;
    double x4444 = 0.0;
    if (fscanf(x4400,"%lf|",&x4444) == EOF) break;
    char x4445 = ' ';
    if (fscanf(x4400,"%c|",&x4445) == EOF) break;
    char x4446 = ' ';
    if (fscanf(x4400,"%c|",&x4446) == EOF) break;
    int x4447 = 0;
    int x4448 = 0;
    int x4449 = 0;
    fscanf(x4400, "%d-%d-%d|",&x4447, &x4448, &x4449);
    long x4450 = (x4447 * 10000) + (x4448 * 100) + x4449;
    int x4451 = 0;
    int x4452 = 0;
    int x4453 = 0;
    fscanf(x4400, "%d-%d-%d|",&x4451, &x4452, &x4453);
    long x4454 = (x4451 * 10000) + (x4452 * 100) + x4453;
    int x4455 = 0;
    int x4456 = 0;
    int x4457 = 0;
    fscanf(x4400, "%d-%d-%d|",&x4455, &x4456, &x4457);
    long x4458 = (x4455 * 10000) + (x4456 * 100) + x4457;
    char* x4459 = (char*)malloc(26 * sizeof(char));
    int x4461 = 0;
    char x4460 = ' ';
    while (1) {
      fscanf(x4400,"%c",&x4460);
      if (x4460=='|' || x4460=='\n') break;
      if (x4461>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x4461); break;}
      ((char*)x4459)[x4461] = x4460;
      x4461 += 1;
    }
    ((char*)x4459)[x4461] = '\0';
    char* x4464 = (char*)malloc(11 * sizeof(char));
    int x4466 = 0;
    char x4465 = ' ';
    while (1) {
      fscanf(x4400,"%c",&x4465);
      if (x4465=='|' || x4465=='\n') break;
      if (x4466>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x4466); break;}
      ((char*)x4464)[x4466] = x4465;
      x4466 += 1;
    }
    ((char*)x4464)[x4466] = '\0';
    char* x4469 = (char*)malloc(45 * sizeof(char));
    int x4471 = 0;
    char x4470 = ' ';
    while (1) {
      fscanf(x4400,"%c",&x4470);
      if (x4470=='|' || x4470=='\n') break;
      if (x4471>=44) { printf("ERROR: scanner.nextString reading past end of buffer %d",x4471); break;}
      ((char*)x4469)[x4471] = x4470;
      x4471 += 1;
    }
    ((char*)x4469)[x4471] = '\0';
    int x4474 = x4402;
    int x4475 = x4401;
    bool x4476 = x4474 == x4475;
    if (x4476) {
      int x4477 = x4475 * 4;
      x4401 = x4477;
      printf("buffer.resize %d\n",x4477);
      int* x4480 = x4404;
      int* x4481 = (int*)realloc(x4480,x4477 * sizeof(int));
      x4404 = x4481;
      double* x4495 = x4414;
      double* x4496 = (double*)realloc(x4495,x4477 * sizeof(double));
      x4414 = x4496;
      double* x4498 = x4416;
      double* x4499 = (double*)realloc(x4498,x4477 * sizeof(double));
      x4416 = x4499;
      long* x4510 = x4424;
      long* x4511 = (long*)realloc(x4510,x4477 * sizeof(long));
      x4424 = x4511;
    } else {
    }
    int* x4530 = x4404;
    x4530[x4474] = x4437;
    double* x4540 = x4414;
    x4540[x4474] = x4442;
    double* x4542 = x4416;
    x4542[x4474] = x4443;
    long* x4550 = x4424;
    x4550[x4474] = x4450;
    x4402 = x4402 + 1;
  }
  FILE* x4566 = fopen("../databases/sf2/orders.tbl", "r");
  int x4567 = 1048576;
  int x4568 = 0;
  int* x4569 = (int*)malloc(1048576 * sizeof(int));
  int* x4570 = x4569;
  int* x4571 = (int*)malloc(1048576 * sizeof(int));
  int* x4572 = x4571;
  long* x4577 = (long*)malloc(1048576 * sizeof(long));
  long* x4578 = x4577;
  int* x4583 = (int*)malloc(1048576 * sizeof(int));
  int* x4584 = x4583;
  for (;;) {
    bool x4587 = !feof(x4566);
    if (!x4587) break;
    int x4589 = 0;
    if (fscanf(x4566,"%d|",&x4589) == EOF) break;
    int x4590 = 0;
    if (fscanf(x4566,"%d|",&x4590) == EOF) break;
    char x4591 = ' ';
    if (fscanf(x4566,"%c|",&x4591) == EOF) break;
    double x4592 = 0.0;
    if (fscanf(x4566,"%lf|",&x4592) == EOF) break;
    int x4593 = 0;
    int x4594 = 0;
    int x4595 = 0;
    fscanf(x4566, "%d-%d-%d|",&x4593, &x4594, &x4595);
    long x4596 = (x4593 * 10000) + (x4594 * 100) + x4595;
    char* x4597 = (char*)malloc(16 * sizeof(char));
    int x4599 = 0;
    char x4598 = ' ';
    while (1) {
      fscanf(x4566,"%c",&x4598);
      if (x4598=='|' || x4598=='\n') break;
      if (x4599>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x4599); break;}
      ((char*)x4597)[x4599] = x4598;
      x4599 += 1;
    }
    ((char*)x4597)[x4599] = '\0';
    char* x4602 = (char*)malloc(16 * sizeof(char));
    int x4604 = 0;
    char x4603 = ' ';
    while (1) {
      fscanf(x4566,"%c",&x4603);
      if (x4603=='|' || x4603=='\n') break;
      if (x4604>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x4604); break;}
      ((char*)x4602)[x4604] = x4603;
      x4604 += 1;
    }
    ((char*)x4602)[x4604] = '\0';
    int x4607 = 0;
    if (fscanf(x4566,"%d|",&x4607) == EOF) break;
    char* x4608 = (char*)malloc(80 * sizeof(char));
    int x4610 = 0;
    char x4609 = ' ';
    while (1) {
      fscanf(x4566,"%c",&x4609);
      if (x4609=='|' || x4609=='\n') break;
      if (x4610>=79) { printf("ERROR: scanner.nextString reading past end of buffer %d",x4610); break;}
      ((char*)x4608)[x4610] = x4609;
      x4610 += 1;
    }
    ((char*)x4608)[x4610] = '\0';
    int x4613 = x4568;
    int x4614 = x4567;
    bool x4615 = x4613 == x4614;
    if (x4615) {
      int x4616 = x4614 * 4;
      x4567 = x4616;
      printf("buffer.resize %d\n",x4616);
      int* x4619 = x4570;
      int* x4620 = (int*)realloc(x4619,x4616 * sizeof(int));
      x4570 = x4620;
      int* x4622 = x4572;
      int* x4623 = (int*)realloc(x4622,x4616 * sizeof(int));
      x4572 = x4623;
      long* x4631 = x4578;
      long* x4632 = (long*)realloc(x4631,x4616 * sizeof(long));
      x4578 = x4632;
      int* x4640 = x4584;
      int* x4641 = (int*)realloc(x4640,x4616 * sizeof(int));
      x4584 = x4641;
    } else {
    }
    int* x4648 = x4570;
    x4648[x4613] = x4589;
    int* x4650 = x4572;
    x4650[x4613] = x4590;
    long* x4656 = x4578;
    x4656[x4613] = x4596;
    int* x4662 = x4584;
    x4662[x4613] = x4607;
    x4568 = x4568 + 1;
  }
  FILE* x4670 = fopen("../databases/sf2/customer.tbl", "r");
  int x4671 = 1048576;
  int x4672 = 0;
  int* x4673 = (int*)malloc(1048576 * sizeof(int));
  int* x4674 = x4673;
  char** x4685 = (char**)malloc(1048576 * sizeof(char*));
  char** x4686 = x4685;
  for (;;) {
    bool x4689 = !feof(x4670);
    if (!x4689) break;
    int x4691 = 0;
    if (fscanf(x4670,"%d|",&x4691) == EOF) break;
    char* x4692 = (char*)malloc(26 * sizeof(char));
    int x4694 = 0;
    char x4693 = ' ';
    while (1) {
      fscanf(x4670,"%c",&x4693);
      if (x4693=='|' || x4693=='\n') break;
      if (x4694>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x4694); break;}
      ((char*)x4692)[x4694] = x4693;
      x4694 += 1;
    }
    ((char*)x4692)[x4694] = '\0';
    char* x4697 = (char*)malloc(41 * sizeof(char));
    int x4699 = 0;
    char x4698 = ' ';
    while (1) {
      fscanf(x4670,"%c",&x4698);
      if (x4698=='|' || x4698=='\n') break;
      if (x4699>=40) { printf("ERROR: scanner.nextString reading past end of buffer %d",x4699); break;}
      ((char*)x4697)[x4699] = x4698;
      x4699 += 1;
    }
    ((char*)x4697)[x4699] = '\0';
    int x4702 = 0;
    if (fscanf(x4670,"%d|",&x4702) == EOF) break;
    char* x4703 = (char*)malloc(16 * sizeof(char));
    int x4705 = 0;
    char x4704 = ' ';
    while (1) {
      fscanf(x4670,"%c",&x4704);
      if (x4704=='|' || x4704=='\n') break;
      if (x4705>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x4705); break;}
      ((char*)x4703)[x4705] = x4704;
      x4705 += 1;
    }
    ((char*)x4703)[x4705] = '\0';
    double x4708 = 0.0;
    if (fscanf(x4670,"%lf|",&x4708) == EOF) break;
    char* x4709 = (char*)malloc(11 * sizeof(char));
    int x4711 = 0;
    char x4710 = ' ';
    while (1) {
      fscanf(x4670,"%c",&x4710);
      if (x4710=='|' || x4710=='\n') break;
      if (x4711>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x4711); break;}
      ((char*)x4709)[x4711] = x4710;
      x4711 += 1;
    }
    ((char*)x4709)[x4711] = '\0';
    char* x4713 = x4709; // unsafe immutable;
    char* x4714 = (char*)malloc(118 * sizeof(char));
    int x4716 = 0;
    char x4715 = ' ';
    while (1) {
      fscanf(x4670,"%c",&x4715);
      if (x4715=='|' || x4715=='\n') break;
      if (x4716>=117) { printf("ERROR: scanner.nextString reading past end of buffer %d",x4716); break;}
      ((char*)x4714)[x4716] = x4715;
      x4716 += 1;
    }
    ((char*)x4714)[x4716] = '\0';
    int x4719 = x4672;
    int x4720 = x4671;
    bool x4721 = x4719 == x4720;
    if (x4721) {
      int x4722 = x4720 * 4;
      x4671 = x4722;
      printf("buffer.resize %d\n",x4722);
      int* x4725 = x4674;
      int* x4726 = (int*)realloc(x4725,x4722 * sizeof(int));
      x4674 = x4726;
      char** x4743 = x4686;
      char** x4744 = (char**)realloc(x4743,x4722 * sizeof(char*));
      x4686 = x4744;
    } else {
    }
    int* x4751 = x4674;
    x4751[x4719] = x4691;
    char** x4763 = x4686;
    x4763[x4719] = x4713;
    x4672 = x4672 + 1;
  }
  GTree* x4779 = g_tree_new((GCompareFunc)x5350);;
  int x3782;
  for(x3782=0; x3782 < 1; x3782++) {
    bool x4780 = false;
    int x4781 = 0;
    bool x4783 = false;
    int x4784 = 0;
    bool x4786 = false;
    int x4787 = 0;
    int* x4790 = (int*)malloc(1073741824 * sizeof(int));
    int* x4791 = x4790;
    int x4806 = 0;
    int* x4807 = (int*)malloc(1048576 * sizeof(int));
    int* x4808 = (int*)malloc(1073741824 * sizeof(int));
    int x3812;
    for(x3812=0; x3812 < 1048576; x3812++) {
      x4807[x3812] = -1;
    }
    int* x4830 = (int*)malloc(1073741824 * sizeof(int));
    int* x4831 = x4830;
    long* x4838 = (long*)malloc(1073741824 * sizeof(long));
    long* x4839 = x4838;
    int* x4844 = (int*)malloc(1073741824 * sizeof(int));
    int* x4845 = x4844;
    int x4848 = 0;
    int* x4849 = (int*)malloc(1048576 * sizeof(int));
    int* x4850 = (int*)malloc(1073741824 * sizeof(int));
    int x3855;
    for(x3855=0; x3855 < 1048576; x3855++) {
      x4849[x3855] = -1;
    }
    int x4856 = 1048576;
    int x4857 = 0;
    int* x4858 = (int*)malloc(1048576 * sizeof(int));
    int* x4859 = x4858;
    long* x4860 = (long*)malloc(1048576 * sizeof(long));
    long* x4861 = x4860;
    int* x4862 = (int*)malloc(1048576 * sizeof(int));
    int* x4863 = x4862;
    double* x4864 = (double*)malloc(1048576 * sizeof(double));
    double* x4865 = x4864;
    int x4866 = 4194304;
    int x4867 = 0;
    int* x4868 = (int*)malloc(4194304 * sizeof(int));
    int* x4869 = x4868;
    int x3876;
    for(x3876=0; x3876 < 4194304; x3876++) {
      int* x4870 = x4869;
      x4870[x3876] = -1;
    }
    int x4877 = 0;
    int x4879 = 0;
    struct timeval x4379, x4380, x5343;
    gettimeofday(&x4379, NULL);
    printf("((CUSTOMER X ORDERS) X LINEITEM): leftParent.next start\n");
    struct timeval x4089, x4090, x5062;
    gettimeofday(&x4089, NULL);
    printf("(CUSTOMER X ORDERS): leftParent.next start\n");
    struct timeval x3966, x3967, x4942;
    gettimeofday(&x3966, NULL);
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x4883 = x4780;
      bool x4884 = !x4883;
      bool x4889 = x4884;
      if (x4884) {
        int x4885 = x4781;
        int x4886 = x4672;
        bool x4887 = x4885 < x4886;
        x4889 = x4887;
      }
      bool x4890 = x4889;
      if (!x4890) break;
      int x4893 = x4781;
      int* x4894 = x4674;
      int x4895 = x4894[x4893];
      char** x4906 = x4686;
      char* x4907 = x4906[x4893];
      x4781 = x4781 + 1;
      bool x4911 = strcmp(x4907,"HOUSEHOLD") == 0;;
      if (x4911) {
        int x4912 = x4806;
        int* x4913 = x4791;
        x4913[x4912] = x4895;
        x4806 = x4806 + 1;
        int x4930 = x4895 & 1048575;
        int x4931 = x4807[x4930];
        x4807[x4930] = x4912;
        x4808[x4912] = x4931;
      } else {
      }
    }
    printf("(CUSTOMER X ORDERS): leftParent.next done\n");
    gettimeofday(&x3967, NULL);
    timeval_subtract(&x4942, &x3967, &x3966);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x4942.tv_sec * 1000) + (x4942.tv_usec/1000)));
    printf("(CUSTOMER X ORDERS): rightParent.next start\n");
    struct timeval x4083, x4084, x5057;
    gettimeofday(&x4083, NULL);
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x4946 = x4783;
      bool x4947 = !x4946;
      bool x4952 = x4947;
      if (x4947) {
        int x4948 = x4784;
        int x4949 = x4568;
        bool x4950 = x4948 < x4949;
        x4952 = x4950;
      }
      bool x4953 = x4952;
      if (!x4953) break;
      int x4956 = x4784;
      int* x4957 = x4570;
      int x4958 = x4957[x4956];
      int* x4959 = x4572;
      int x4960 = x4959[x4956];
      long* x4965 = x4578;
      long x4966 = x4965[x4956];
      int* x4971 = x4584;
      int x4972 = x4971[x4956];
      x4784 = x4784 + 1;
      bool x4976 = x4966 < 19950304L;
      if (x4976) {
        int x4977 = x4960 & 1048575;
        int x4978 = x4807[x4977];
        int x4979 = x4978;
        int x4980 = x4958 & 1048575;
        for (;;) {
          int x4981 = x4979;
          bool x4982 = x4981 != -1;
          if (!x4982) break;
          int x4984 = x4979;
          int* x4985 = x4791;
          int x4986 = x4985[x4984];
          int x5001 = x4808[x4984];
          x4979 = x5001;
          bool x5003 = x4986 == x4960;
          if (x5003) {
            int x5004 = x4848;
            int* x5021 = x4831;
            x5021[x5004] = x4958;
            long* x5029 = x4839;
            x5029[x5004] = x4966;
            int* x5035 = x4845;
            x5035[x5004] = x4972;
            x4848 = x4848 + 1;
            int x5040 = x4849[x4980];
            x4849[x4980] = x5004;
            x4850[x5004] = x5040;
          } else {
          }
        }
      } else {
      }
    }
    printf("(CUSTOMER X ORDERS): rightParent.next done\n");
    gettimeofday(&x4084, NULL);
    timeval_subtract(&x5057, &x4084, &x4083);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x5057.tv_sec * 1000) + (x5057.tv_usec/1000)));
    printf("((CUSTOMER X ORDERS) X LINEITEM): leftParent.next done\n");
    gettimeofday(&x4090, NULL);
    timeval_subtract(&x5062, &x4090, &x4089);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x5062.tv_sec * 1000) + (x5062.tv_usec/1000)));
    printf("((CUSTOMER X ORDERS) X LINEITEM): rightParent.next start\n");
    struct timeval x4331, x4332, x5297;
    gettimeofday(&x4331, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x5066 = x4786;
      bool x5067 = !x5066;
      bool x5072 = x5067;
      if (x5067) {
        int x5068 = x4787;
        int x5069 = x4402;
        bool x5070 = x5068 < x5069;
        x5072 = x5070;
      }
      bool x5073 = x5072;
      if (!x5073) break;
      int x5076 = x4787;
      int* x5077 = x4404;
      int x5078 = x5077[x5076];
      double* x5087 = x4414;
      double x5088 = x5087[x5076];
      double* x5089 = x4416;
      double x5090 = x5089[x5076];
      long* x5097 = x4424;
      long x5098 = x5097[x5076];
      x4787 = x4787 + 1;
      bool x5110 = x5098 > 19950304L;
      if (x5110) {
        int x5111 = x5078 & 1048575;
        int x5112 = x4849[x5111];
        int x5113 = x5112;
        int x5114 = x5078 * 41;
        double x5115 = 1.0 - x5090;
        double x5116 = x5088 * x5115;
        for (;;) {
          int x5117 = x5113;
          bool x5118 = x5117 != -1;
          if (!x5118) break;
          int x5120 = x5113;
          int* x5137 = x4831;
          int x5138 = x5137[x5120];
          long* x5145 = x4839;
          long x5146 = x5145[x5120];
          int* x5151 = x4845;
          int x5152 = x5151[x5120];
          int x5155 = x4850[x5120];
          x5113 = x5155;
          bool x5157 = x5138 == x5078;
          if (x5157) {
            int x5159 = x4866;
            int x5160 = x5159 - 1;
            int x5161 = (int)x5146;
            int x5162 = x5114 + x5161;
            int x5163 = x5162 * 41;
            int x5164 = x5163 + x5152;
            int x5165 = x5164 * 2;
            int x5166 = x5165 * 3;
            int x5167 = x5166 & x5160;
            int x5168 = x5167;
            int* x5169 = x4869;
            int x5170 = x5169[x5167];
            int x5171 = x5170;
            int x5172 = x5167 + 1;
            int x5173 = x5169[x5172];
            int x5174 = x5173;
            for (;;) {
              int x5175 = x5171;
              bool x5176 = x5175 != -1;
              bool x5204 = x5176;
              if (x5176) {
                int x5177 = x5174;
                bool x5178 = x5177 != x5166;
                bool x5200 = x5178;
                if (x5178 == false) {
                  int x5179 = x5171;
                  int* x5180 = x4859;
                  int x5181 = x5180[x5179];
                  long* x5182 = x4861;
                  long x5183 = x5182[x5179];
                  int* x5184 = x4863;
                  int x5185 = x5184[x5179];
                  bool x5188 = x5181 == x5078;
                  bool x5191 = x5188;
                  if (x5188) {
                    bool x5189 = x5183 == x5146;
                    x5191 = x5189;
                  }
                  bool x5192 = x5191;
                  bool x5195 = x5192;
                  if (x5192) {
                    bool x5193 = x5185 == x5152;
                    x5195 = x5193;
                  }
                  bool x5196 = x5195;
                  bool x5197 = !x5196;
                  x5200 = x5197;
                }
                bool x5201 = x5200;
                x5204 = x5201;
              }
              bool x5205 = x5204;
              if (!x5205) break;
              int x5208 = x5168;
              int x5209 = x5208 + 2;
              int x5210 = x5209 & x5160;
              x5168 = x5210;
              int* x5212 = x4869;
              int x5213 = x5212[x5210];
              x5171 = x5213;
              int x5215 = x5210 + 1;
              int x5216 = x5212[x5215];
              x5174 = x5216;
            }
            int x5221 = x5171;
            bool x5222 = x5221 == -1;
            int x5268;
            if (x5222) {
              int x5223 = x4867;
              int x5224 = x5168;
              x5169[x5224] = x5223;
              int x5226 = x5224 + 1;
              x5169[x5226] = x5166;
              x4867 = x4867 + 1;
              int x5229 = x4857;
              int x5230 = x4856;
              bool x5231 = x5229 == x5230;
              if (x5231) {
                int x5232 = x5230 * 4;
                x4856 = x5232;
                printf("buffer.resize %d\n",x5232);
                printf("buffer.resize %d\n",x5232);
                int* x5236 = x4859;
                int* x5237 = (int*)realloc(x5236,x5232 * sizeof(int));
                x4859 = x5237;
                long* x5239 = x4861;
                long* x5240 = (long*)realloc(x5239,x5232 * sizeof(long));
                x4861 = x5240;
                int* x5242 = x4863;
                int* x5243 = (int*)realloc(x5242,x5232 * sizeof(int));
                x4863 = x5243;
                printf("buffer.resize %d\n",x5232);
                double* x5246 = x4865;
                double* x5247 = (double*)realloc(x5246,x5232 * sizeof(double));
                x4865 = x5247;
              } else {
              }
              int* x5251 = x4859;
              x5251[x5229] = x5078;
              long* x5253 = x4861;
              x5253[x5229] = x5146;
              int* x5255 = x4863;
              x5255[x5229] = x5152;
              double* x5257 = x4865;
              x5257[x5229] = 0.0;
              x4857 = x4857 + 1;
              int x5260 = x4867;
              int x5261 = x5260 * 4;
              bool x5262 = x5261 > x5159;
              if (x5262) {
                printf("%s\n","ERROR: hash.resize not implemented");
              } else {
              }
              x5268 = x5223;
            } else {
              x5268 = x5221;
            }
            int* x5269 = x4859;
            int x5270 = x5269[x5268];
            long* x5271 = x4861;
            long x5272 = x5271[x5268];
            int* x5273 = x4863;
            int x5274 = x5273[x5268];
            double* x5275 = x4865;
            double x5276 = x5275[x5268];
            x5269[x5268] = x5270;
            x5271[x5268] = x5272;
            x5273[x5268] = x5274;
            double x5280 = x5276 + x5116;
            x5275[x5268] = x5280;
          } else {
          }
        }
      } else {
      }
    }
    printf("((CUSTOMER X ORDERS) X LINEITEM): rightParent.next done\n");
    gettimeofday(&x4332, NULL);
    timeval_subtract(&x5297, &x4332, &x4331);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x5297.tv_sec * 1000) + (x5297.tv_usec/1000)));
    int x5299 = x4857;
    int x4337;
    for(x4337=0; x4337 < x5299; x4337++) {
      int* x5300 = x4859;
      int x5301 = x5300[x4337];
      long* x5302 = x4861;
      long x5303 = x5302[x4337];
      int* x5304 = x4863;
      int x5305 = x5304[x4337];
      double* x5306 = x4865;
      double x5307 = x5306[x4337];
      struct Anon1465150758* x5308 = (struct Anon1465150758*)malloc(sizeof(struct Anon1465150758));
      x5308->L_ORDERKEY = x5301;
      x5308->O_ORDERDATE = x5303;
      x5308->O_SHIPPRIORITY = x5305;
      struct Anon2052879266* x5309 = (struct Anon2052879266*)malloc(sizeof(struct Anon2052879266));
      x5309->_0 = x5307;
      struct Anon1555625313* x5310 = (struct Anon1555625313*)malloc(sizeof(struct Anon1555625313));
      x5310->key = x5308;
      x5310->aggs = x5309;
      g_tree_insert(x4779,x5310,x5310);; // x5311
    }
    for (;;) {
      int x5314 = g_tree_nnodes(x4779);
      bool x5315 = x5314 != 0;
      if (!x5315) break;
      struct Anon1555625313* x5317 = NULL;
      g_tree_foreach(x4779, (GTraverseFunc)x5356, &x5317);
      g_tree_remove(x4779,x5317);
      int x5319 = x4877;
      bool x5320 = x5319 < 10;
      bool x5321 = x5320 == false;
      if (x5321) {
      } else {
        struct Anon1465150758* x5324 = x5317->key;;
        int x5325 = x5324->L_ORDERKEY;;
        struct Anon2052879266* x5326 = x5317->aggs;;
        double x5327 = x5326->_0;;
        long x5328 = x5324->O_ORDERDATE;;
        char* x5329 = (char*)malloc(9 * sizeof(char));;
        snprintf(x5329, 9, "%lu", x5328);
        int x5330 = x5324->O_SHIPPRIORITY;;
        printf("%d|%.4f|%s|%d\n",x5325,x5327,x5329,x5330);
        x4877 = x4877 + 1;
        x4879 = x4879 + 1;
      }
    }
    int x5339 = x4879;
    printf("(%d rows)\n",x5339);
    gettimeofday(&x4380, NULL);
    timeval_subtract(&x5343, &x4380, &x4379);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x5343.tv_sec * 1000) + (x5343.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
