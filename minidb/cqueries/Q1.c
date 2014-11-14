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
struct Anon567626277;
struct Anon168903330;
struct Anon1296044246;
struct Anon855148991;
struct Anon625264174;
struct Anon704530870;

struct Anon567626277 {
double _0;
double _1;
double _2;
double _3;
double _4;
double _5;
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

struct Anon855148991 {
struct Anon625264174* key;
struct Anon1296044246* aggs;
};

struct Anon625264174 {
char L_RETURNFLAG;
char L_LINESTATUS;
};

struct Anon704530870 {
struct Anon625264174* key;
struct Anon567626277* aggs;
};

/************************ FUNCTIONS **************************/
int x1029(struct Anon855148991* x208, struct Anon855148991* x207);
int x1035(struct Anon855148991* x1030, struct Anon855148991* x1031, struct Anon855148991** x1032);
int x1029(struct Anon855148991* x208, struct Anon855148991* x207) {
  struct Anon625264174* x209 = x207->key;;
  char x210 = x209->L_RETURNFLAG;;
  struct Anon625264174* x211 = x208->key;;
  char x212 = x211->L_RETURNFLAG;;
  int x213 = x210 - x212;
  int x701 = x213;
  bool x702 = x213 == 0;
  if (x702) {
    char x216 = x209->L_LINESTATUS;;
    char x217 = x211->L_LINESTATUS;;
    int x218 = x216 - x217;
    x701 = x218;
  } else {
  }
  int x706 = x701;
  return x706;
}
int x1035(struct Anon855148991* x1030, struct Anon855148991* x1031, struct Anon855148991** x1032) {
  *x1032 = x1031;
  return 0;
}

/************************ MAIN BODY **************************/
int main(int x0, char** x1) {
  FILE* x535 = fopen("../databases/sf2/lineitem.tbl", "r");
  int x536 = 1048576;
  int x537 = 0;
  double* x546 = (double*)malloc(1048576 * sizeof(double));
  double* x547 = x546;
  double* x548 = (double*)malloc(1048576 * sizeof(double));
  double* x549 = x548;
  double* x550 = (double*)malloc(1048576 * sizeof(double));
  double* x551 = x550;
  double* x552 = (double*)malloc(1048576 * sizeof(double));
  double* x553 = x552;
  char* x554 = (char*)malloc(1048576 * sizeof(char));
  char* x555 = x554;
  char* x556 = (char*)malloc(1048576 * sizeof(char));
  char* x557 = x556;
  long* x558 = (long*)malloc(1048576 * sizeof(long));
  long* x559 = x558;
  for (;;) {
    bool x570 = !feof(x535);
    if (!x570) break;
    int x572 = 0;
    if (fscanf(x535,"%d|",&x572) == EOF) break;
    int x573 = 0;
    if (fscanf(x535,"%d|",&x573) == EOF) break;
    int x574 = 0;
    if (fscanf(x535,"%d|",&x574) == EOF) break;
    int x575 = 0;
    if (fscanf(x535,"%d|",&x575) == EOF) break;
    double x576 = 0.0;
    if (fscanf(x535,"%lf|",&x576) == EOF) break;
    double x577 = 0.0;
    if (fscanf(x535,"%lf|",&x577) == EOF) break;
    double x578 = 0.0;
    if (fscanf(x535,"%lf|",&x578) == EOF) break;
    double x579 = 0.0;
    if (fscanf(x535,"%lf|",&x579) == EOF) break;
    char x580 = ' ';
    if (fscanf(x535,"%c|",&x580) == EOF) break;
    char x581 = ' ';
    if (fscanf(x535,"%c|",&x581) == EOF) break;
    int x582 = 0;
    int x583 = 0;
    int x584 = 0;
    fscanf(x535, "%d-%d-%d|",&x582, &x583, &x584);
    long x585 = (x582 * 10000) + (x583 * 100) + x584;
    int x586 = 0;
    int x587 = 0;
    int x588 = 0;
    fscanf(x535, "%d-%d-%d|",&x586, &x587, &x588);
    long x589 = (x586 * 10000) + (x587 * 100) + x588;
    int x590 = 0;
    int x591 = 0;
    int x592 = 0;
    fscanf(x535, "%d-%d-%d|",&x590, &x591, &x592);
    long x593 = (x590 * 10000) + (x591 * 100) + x592;
    char* x594 = (char*)malloc(26 * sizeof(char));
    int x596 = 0;
    char x595 = ' ';
    while (1) {
      fscanf(x535,"%c",&x595);
      if (x595=='|' || x595=='\n') break;
      if (x596>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x596); break;}
      ((char*)x594)[x596] = x595;
      x596 += 1;
    }
    ((char*)x594)[x596] = '\0';
    char* x599 = (char*)malloc(11 * sizeof(char));
    int x601 = 0;
    char x600 = ' ';
    while (1) {
      fscanf(x535,"%c",&x600);
      if (x600=='|' || x600=='\n') break;
      if (x601>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x601); break;}
      ((char*)x599)[x601] = x600;
      x601 += 1;
    }
    ((char*)x599)[x601] = '\0';
    char* x604 = (char*)malloc(45 * sizeof(char));
    int x606 = 0;
    char x605 = ' ';
    while (1) {
      fscanf(x535,"%c",&x605);
      if (x605=='|' || x605=='\n') break;
      if (x606>=44) { printf("ERROR: scanner.nextString reading past end of buffer %d",x606); break;}
      ((char*)x604)[x606] = x605;
      x606 += 1;
    }
    ((char*)x604)[x606] = '\0';
    int x609 = x537;
    int x610 = x536;
    bool x611 = x609 == x610;
    if (x611) {
      int x612 = x610 * 4;
      x536 = x612;
      printf("buffer.resize %d\n",x612);
      double* x627 = x547;
      double* x628 = (double*)realloc(x627,x612 * sizeof(double));
      x547 = x628;
      double* x630 = x549;
      double* x631 = (double*)realloc(x630,x612 * sizeof(double));
      x549 = x631;
      double* x633 = x551;
      double* x634 = (double*)realloc(x633,x612 * sizeof(double));
      x551 = x634;
      double* x636 = x553;
      double* x637 = (double*)realloc(x636,x612 * sizeof(double));
      x553 = x637;
      char* x639 = x555;
      char* x640 = (char*)realloc(x639,x612 * sizeof(char));
      x555 = x640;
      char* x642 = x557;
      char* x643 = (char*)realloc(x642,x612 * sizeof(char));
      x557 = x643;
      long* x645 = x559;
      long* x646 = (long*)realloc(x645,x612 * sizeof(long));
      x559 = x646;
    } else {
    }
    double* x673 = x547;
    x673[x609] = x576;
    double* x675 = x549;
    x675[x609] = x577;
    double* x677 = x551;
    x677[x609] = x578;
    double* x679 = x553;
    x679[x609] = x579;
    char* x681 = x555;
    x681[x609] = x580;
    char* x683 = x557;
    x683[x609] = x581;
    long* x685 = x559;
    x685[x609] = x585;
    x537 = x537 + 1;
  }
  GTree* x709 = g_tree_new((GCompareFunc)x1029);;
  bool x710 = true == false;
  int x169;
  for(x169=0; x169 < 1; x169++) {
    bool x711 = false;
    int x712 = 0;
    int x715 = 1048576;
    int x716 = 0;
    char* x717 = (char*)malloc(1048576 * sizeof(char));
    char* x718 = x717;
    char* x719 = (char*)malloc(1048576 * sizeof(char));
    char* x720 = x719;
    double* x721 = (double*)malloc(1048576 * sizeof(double));
    double* x722 = x721;
    double* x723 = (double*)malloc(1048576 * sizeof(double));
    double* x724 = x723;
    double* x725 = (double*)malloc(1048576 * sizeof(double));
    double* x726 = x725;
    double* x727 = (double*)malloc(1048576 * sizeof(double));
    double* x728 = x727;
    double* x729 = (double*)malloc(1048576 * sizeof(double));
    double* x730 = x729;
    double* x731 = (double*)malloc(1048576 * sizeof(double));
    double* x732 = x731;
    int x733 = 4194304;
    int x734 = 0;
    int* x735 = (int*)malloc(4194304 * sizeof(int));
    int* x736 = x735;
    int x198;
    for(x198=0; x198 < 4194304; x198++) {
      int* x737 = x736;
      x737[x198] = -1;
    }
    int x746 = 0;
    struct timeval x510, x511, x1022;
    gettimeofday(&x510, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x748 = x711;
      bool x749 = !x748;
      bool x754 = x749;
      if (x749) {
        int x750 = x712;
        int x751 = x537;
        bool x752 = x750 < x751;
        x754 = x752;
      }
      bool x755 = x754;
      if (!x755) break;
      int x758 = x712;
      double* x767 = x547;
      double x768 = x767[x758];
      double* x769 = x549;
      double x770 = x769[x758];
      double* x771 = x551;
      double x772 = x771[x758];
      double* x773 = x553;
      double x774 = x773[x758];
      char* x775 = x555;
      char x776 = x775[x758];
      char* x777 = x557;
      char x778 = x777[x758];
      long* x779 = x559;
      long x780 = x779[x758];
      x712 = x712 + 1;
      bool x792 = x780 <= 19980811L;
      if (x792) {
        int x794 = x733;
        int x795 = x794 - 1;
        int x796 = x778 * 41;
        int x797 = x796 + x776;
        int x798 = x797 * 2;
        int x799 = x798 * 3;
        int x800 = x799 & x795;
        int x801 = x800;
        int* x802 = x736;
        int x803 = x802[x800];
        int x804 = x803;
        int x805 = x800 + 1;
        int x806 = x802[x805];
        int x807 = x806;
        for (;;) {
          int x808 = x804;
          bool x809 = x808 != -1;
          bool x841 = x809;
          if (x809) {
            int x810 = x807;
            bool x811 = x810 != x799;
            bool x837 = x811;
            if (x811 == false) {
              int x812 = x804;
              char* x813 = x718;
              char x814 = x813[x812];
              char* x815 = x720;
              char x816 = x815[x812];
              bool x829 = x814 == x776;
              bool x832 = x829;
              if (x829) {
                bool x830 = x816 == x778;
                x832 = x830;
              }
              bool x833 = x832;
              bool x834 = !x833;
              x837 = x834;
            }
            bool x838 = x837;
            x841 = x838;
          }
          bool x842 = x841;
          if (!x842) break;
          int x845 = x801;
          int x846 = x845 + 2;
          int x847 = x846 & x795;
          x801 = x847;
          int* x849 = x736;
          int x850 = x849[x847];
          x804 = x850;
          int x852 = x847 + 1;
          int x853 = x849[x852];
          x807 = x853;
        }
        int x858 = x804;
        bool x859 = x858 == -1;
        int x925;
        if (x859) {
          int x860 = x734;
          int x861 = x801;
          x802[x861] = x860;
          int x863 = x861 + 1;
          x802[x863] = x799;
          x734 = x734 + 1;
          int x866 = x716;
          int x867 = x715;
          bool x868 = x866 == x867;
          if (x868) {
            int x869 = x867 * 4;
            x715 = x869;
            printf("buffer.resize %d\n",x869);
            printf("buffer.resize %d\n",x869);
            char* x873 = x718;
            char* x874 = (char*)realloc(x873,x869 * sizeof(char));
            x718 = x874;
            char* x876 = x720;
            char* x877 = (char*)realloc(x876,x869 * sizeof(char));
            x720 = x877;
            printf("buffer.resize %d\n",x869);
            double* x880 = x722;
            double* x881 = (double*)realloc(x880,x869 * sizeof(double));
            x722 = x881;
            double* x883 = x724;
            double* x884 = (double*)realloc(x883,x869 * sizeof(double));
            x724 = x884;
            double* x886 = x726;
            double* x887 = (double*)realloc(x886,x869 * sizeof(double));
            x726 = x887;
            double* x889 = x728;
            double* x890 = (double*)realloc(x889,x869 * sizeof(double));
            x728 = x890;
            double* x892 = x730;
            double* x893 = (double*)realloc(x892,x869 * sizeof(double));
            x730 = x893;
            double* x895 = x732;
            double* x896 = (double*)realloc(x895,x869 * sizeof(double));
            x732 = x896;
          } else {
          }
          char* x900 = x718;
          x900[x866] = x776;
          char* x902 = x720;
          x902[x866] = x778;
          double* x904 = x722;
          x904[x866] = 0.0;
          double* x906 = x724;
          x906[x866] = 0.0;
          double* x908 = x726;
          x908[x866] = 0.0;
          double* x910 = x728;
          x910[x866] = 0.0;
          double* x912 = x730;
          x912[x866] = 0.0;
          double* x914 = x732;
          x914[x866] = 0.0;
          x716 = x716 + 1;
          int x917 = x734;
          int x918 = x917 * 4;
          bool x919 = x918 > x794;
          if (x919) {
            printf("%s\n","ERROR: hash.resize not implemented");
          } else {
          }
          x925 = x860;
        } else {
          x925 = x858;
        }
        char* x926 = x718;
        char x927 = x926[x925];
        char* x928 = x720;
        char x929 = x928[x925];
        double* x930 = x722;
        double x931 = x930[x925];
        double* x932 = x724;
        double x933 = x932[x925];
        double* x934 = x726;
        double x935 = x934[x925];
        double* x936 = x728;
        double x937 = x936[x925];
        double* x938 = x730;
        double x939 = x938[x925];
        double* x940 = x732;
        double x941 = x940[x925];
        x926[x925] = x927;
        x928[x925] = x929;
        double x944 = x772 + x931;
        x930[x925] = x944;
        double x946 = x768 + x933;
        x932[x925] = x946;
        double x948 = x770 + x935;
        x934[x925] = x948;
        double x950 = 1.0 - x772;
        double x951 = x770 * x950;
        double x952 = x951 + x937;
        x936[x925] = x952;
        double x954 = 1.0 + x774;
        double x955 = x951 * x954;
        double x956 = x955 + x939;
        x938[x925] = x956;
        double x958 = x941 + 1.0;
        x940[x925] = x958;
      } else {
      }
    }
    int x966 = x716;
    int x453;
    for(x453=0; x453 < x966; x453++) {
      char* x967 = x718;
      char x968 = x967[x453];
      char* x969 = x720;
      char x970 = x969[x453];
      double* x971 = x722;
      double x972 = x971[x453];
      double* x973 = x724;
      double x974 = x973[x453];
      double* x975 = x726;
      double x976 = x975[x453];
      double* x977 = x728;
      double x978 = x977[x453];
      double* x979 = x730;
      double x980 = x979[x453];
      double* x981 = x732;
      double x982 = x981[x453];
      struct Anon625264174* x983 = (struct Anon625264174*)malloc(sizeof(struct Anon625264174));
      x983->L_RETURNFLAG = x968;
      x983->L_LINESTATUS = x970;
      double x984 = x974 / x982;
      double x985 = x976 / x982;
      double x986 = x972 / x982;
      struct Anon1296044246* x987 = (struct Anon1296044246*)malloc(sizeof(struct Anon1296044246));
      x987->_0 = x972;
      x987->_1 = x974;
      x987->_2 = x976;
      x987->_3 = x978;
      x987->_4 = x980;
      x987->_5 = x982;
      x987->_6 = x984;
      x987->_7 = x985;
      x987->_8 = x986;
      struct Anon855148991* x988 = (struct Anon855148991*)malloc(sizeof(struct Anon855148991));
      x988->key = x983;
      x988->aggs = x987;
      g_tree_insert(x709,x988,x988);; // x989
    }
    for (;;) {
      int x992 = g_tree_nnodes(x709);
      bool x993 = x992 != 0;
      if (!x993) break;
      struct Anon855148991* x995 = NULL;
      g_tree_foreach(x709, (GTraverseFunc)x1035, &x995);
      g_tree_remove(x709,x995);
      if (x710) {
      } else {
        struct Anon625264174* x999 = x995->key;;
        char x1000 = x999->L_RETURNFLAG;;
        char x1001 = x999->L_LINESTATUS;;
        struct Anon1296044246* x1002 = x995->aggs;;
        double x1003 = x1002->_1;;
        double x1004 = x1002->_2;;
        double x1005 = x1002->_3;;
        double x1006 = x1002->_4;;
        double x1007 = x1002->_6;;
        double x1008 = x1002->_7;;
        double x1009 = x1002->_8;;
        double x1010 = x1002->_5;;
        printf("%c|%c|%.2f|%.2f|%.2f|%.2f|%.2f|%.2f|%.6f|%.0f\n",x1000,x1001,x1003,x1004,x1005,x1006,x1007,x1008,x1009,x1010);
        x746 = x746 + 1;
      }
    }
    int x1018 = x746;
    printf("(%d rows)\n",x1018);
    gettimeofday(&x511, NULL);
    timeval_subtract(&x1022, &x511, &x510);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x1022.tv_sec * 1000) + (x1022.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
