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
int main(int x2590, char** x2591) {
  int x2592 = 0;
  int x2593 = 1048576;
  int x2594 = 0;
  int* x2595 = (int*)malloc(1048576 * sizeof(int));
  int* x2596 = x2595;
  double* x2605 = (double*)malloc(1048576 * sizeof(double));
  double* x2606 = x2605;
  double* x2607 = (double*)malloc(1048576 * sizeof(double));
  double* x2608 = x2607;
  long* x2615 = (long*)malloc(1048576 * sizeof(long));
  long* x2616 = x2615;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  int x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    int x2627 = x2592;
    bool x2628 = x2627 < x3;
    if (!x2628) break;
    int x2631 = 0;
    for (;;) {
      int x2632 = x2592;
      char x2633 = x4[x2632];
      bool x2634 = x2633 != '|';
      bool x2639 = x2634;
      if (x2634) {
        int x2635 = x2592;
        char x2636 = x4[x2635];
        bool x2637 = x2636 != '\n';
        x2639 = x2637;
      }
      bool x2640 = x2639;
      if (!x2640) break;
      int x2642 = x2631;
      int x2644 = x2592;
      int x2643 = x2642 * 10;
      char x2645 = x4[x2644];
      char x2646 = x2645 - '0';
      int x2647 = x2643 + x2646;
      x2631 = x2647;
      x2592 = x2592 + 1;
    }
    x2592 = x2592 + 1;
    int x2653 = x2631;
    for (;;) {
      int x2656 = x2592;
      char x2657 = x4[x2656];
      bool x2658 = x2657 != '|';
      bool x2663 = x2658;
      if (x2658) {
        int x2659 = x2592;
        char x2660 = x4[x2659];
        bool x2661 = x2660 != '\n';
        x2663 = x2661;
      }
      bool x2664 = x2663;
      if (!x2664) break;
      x2592 = x2592 + 1;
    }
    x2592 = x2592 + 1;
    for (;;) {
      int x2680 = x2592;
      char x2681 = x4[x2680];
      bool x2682 = x2681 != '|';
      bool x2687 = x2682;
      if (x2682) {
        int x2683 = x2592;
        char x2684 = x4[x2683];
        bool x2685 = x2684 != '\n';
        x2687 = x2685;
      }
      bool x2688 = x2687;
      if (!x2688) break;
      x2592 = x2592 + 1;
    }
    x2592 = x2592 + 1;
    for (;;) {
      int x2704 = x2592;
      char x2705 = x4[x2704];
      bool x2706 = x2705 != '|';
      bool x2711 = x2706;
      if (x2706) {
        int x2707 = x2592;
        char x2708 = x4[x2707];
        bool x2709 = x2708 != '\n';
        x2711 = x2709;
      }
      bool x2712 = x2711;
      if (!x2712) break;
      x2592 = x2592 + 1;
    }
    x2592 = x2592 + 1;
    for (;;) {
      int x2729 = x2592;
      char x2730 = x4[x2729];
      bool x2731 = x2730 != '.';
      bool x2736 = x2731;
      if (x2731) {
        int x2732 = x2592;
        char x2733 = x4[x2732];
        bool x2734 = x2733 != '|';
        x2736 = x2734;
      }
      bool x2737 = x2736;
      bool x2742 = x2737;
      if (x2737) {
        int x2738 = x2592;
        char x2739 = x4[x2738];
        bool x2740 = x2739 != '\n';
        x2742 = x2740;
      }
      bool x2743 = x2742;
      if (!x2743) break;
      x2592 = x2592 + 1;
    }
    int x2755 = x2592;
    char x2756 = x4[x2755];
    bool x2757 = x2756 == '.';
    if (x2757) {
      x2592 = x2592 + 1;
      for (;;) {
        int x2759 = x2592;
        char x2760 = x4[x2759];
        bool x2761 = x2760 != '|';
        bool x2766 = x2761;
        if (x2761) {
          int x2762 = x2592;
          char x2763 = x4[x2762];
          bool x2764 = x2763 != '\n';
          x2766 = x2764;
        }
        bool x2767 = x2766;
        if (!x2767) break;
        x2592 = x2592 + 1;
      }
    } else {
    }
    x2592 = x2592 + 1;
    int x2792 = 0;
    int x2793 = 1;
    for (;;) {
      int x2794 = x2592;
      char x2795 = x4[x2794];
      bool x2796 = x2795 != '.';
      bool x2801 = x2796;
      if (x2796) {
        int x2797 = x2592;
        char x2798 = x4[x2797];
        bool x2799 = x2798 != '|';
        x2801 = x2799;
      }
      bool x2802 = x2801;
      bool x2807 = x2802;
      if (x2802) {
        int x2803 = x2592;
        char x2804 = x4[x2803];
        bool x2805 = x2804 != '\n';
        x2807 = x2805;
      }
      bool x2808 = x2807;
      if (!x2808) break;
      int x2810 = x2792;
      int x2812 = x2592;
      int x2811 = x2810 * 10;
      char x2813 = x4[x2812];
      char x2814 = x2813 - '0';
      int x2815 = x2811 + x2814;
      x2792 = x2815;
      x2592 = x2592 + 1;
    }
    int x2820 = x2592;
    char x2821 = x4[x2820];
    bool x2822 = x2821 == '.';
    if (x2822) {
      x2592 = x2592 + 1;
      for (;;) {
        int x2824 = x2592;
        char x2825 = x4[x2824];
        bool x2826 = x2825 != '|';
        bool x2831 = x2826;
        if (x2826) {
          int x2827 = x2592;
          char x2828 = x4[x2827];
          bool x2829 = x2828 != '\n';
          x2831 = x2829;
        }
        bool x2832 = x2831;
        if (!x2832) break;
        int x2834 = x2792;
        int x2836 = x2592;
        int x2835 = x2834 * 10;
        char x2837 = x4[x2836];
        char x2838 = x2837 - '0';
        int x2839 = x2835 + x2838;
        x2792 = x2839;
        int x2841 = x2793;
        int x2842 = x2841 * 10;
        x2793 = x2842;
        x2592 = x2592 + 1;
      }
    } else {
    }
    x2592 = x2592 + 1;
    int x2851 = x2792;
    int x2853 = x2793;
    int x2857 = 0;
    int x2858 = 1;
    for (;;) {
      int x2859 = x2592;
      char x2860 = x4[x2859];
      bool x2861 = x2860 != '.';
      bool x2866 = x2861;
      if (x2861) {
        int x2862 = x2592;
        char x2863 = x4[x2862];
        bool x2864 = x2863 != '|';
        x2866 = x2864;
      }
      bool x2867 = x2866;
      bool x2872 = x2867;
      if (x2867) {
        int x2868 = x2592;
        char x2869 = x4[x2868];
        bool x2870 = x2869 != '\n';
        x2872 = x2870;
      }
      bool x2873 = x2872;
      if (!x2873) break;
      int x2875 = x2857;
      int x2877 = x2592;
      int x2876 = x2875 * 10;
      char x2878 = x4[x2877];
      char x2879 = x2878 - '0';
      int x2880 = x2876 + x2879;
      x2857 = x2880;
      x2592 = x2592 + 1;
    }
    int x2885 = x2592;
    char x2886 = x4[x2885];
    bool x2887 = x2886 == '.';
    if (x2887) {
      x2592 = x2592 + 1;
      for (;;) {
        int x2889 = x2592;
        char x2890 = x4[x2889];
        bool x2891 = x2890 != '|';
        bool x2896 = x2891;
        if (x2891) {
          int x2892 = x2592;
          char x2893 = x4[x2892];
          bool x2894 = x2893 != '\n';
          x2896 = x2894;
        }
        bool x2897 = x2896;
        if (!x2897) break;
        int x2899 = x2857;
        int x2901 = x2592;
        int x2900 = x2899 * 10;
        char x2902 = x4[x2901];
        char x2903 = x2902 - '0';
        int x2904 = x2900 + x2903;
        x2857 = x2904;
        int x2906 = x2858;
        int x2907 = x2906 * 10;
        x2858 = x2907;
        x2592 = x2592 + 1;
      }
    } else {
    }
    x2592 = x2592 + 1;
    int x2916 = x2857;
    int x2918 = x2858;
    for (;;) {
      int x2924 = x2592;
      char x2925 = x4[x2924];
      bool x2926 = x2925 != '.';
      bool x2931 = x2926;
      if (x2926) {
        int x2927 = x2592;
        char x2928 = x4[x2927];
        bool x2929 = x2928 != '|';
        x2931 = x2929;
      }
      bool x2932 = x2931;
      bool x2937 = x2932;
      if (x2932) {
        int x2933 = x2592;
        char x2934 = x4[x2933];
        bool x2935 = x2934 != '\n';
        x2937 = x2935;
      }
      bool x2938 = x2937;
      if (!x2938) break;
      x2592 = x2592 + 1;
    }
    int x2950 = x2592;
    char x2951 = x4[x2950];
    bool x2952 = x2951 == '.';
    if (x2952) {
      x2592 = x2592 + 1;
      for (;;) {
        int x2954 = x2592;
        char x2955 = x4[x2954];
        bool x2956 = x2955 != '|';
        bool x2961 = x2956;
        if (x2956) {
          int x2957 = x2592;
          char x2958 = x4[x2957];
          bool x2959 = x2958 != '\n';
          x2961 = x2959;
        }
        bool x2962 = x2961;
        if (!x2962) break;
        x2592 = x2592 + 1;
      }
    } else {
    }
    x2592 = x2592 + 1;
    x2592 = x2592 + 2;
    x2592 = x2592 + 2;
    int x2993 = 0;
    for (;;) {
      int x2994 = x2592;
      char x2995 = x4[x2994];
      bool x2996 = x2995 != '-';
      bool x3001 = x2996;
      if (x2996) {
        int x2997 = x2592;
        char x2998 = x4[x2997];
        bool x2999 = x2998 != '\n';
        x3001 = x2999;
      }
      bool x3002 = x3001;
      if (!x3002) break;
      int x3004 = x2993;
      int x3006 = x2592;
      int x3005 = x3004 * 10;
      char x3007 = x4[x3006];
      char x3008 = x3007 - '0';
      int x3009 = x3005 + x3008;
      x2993 = x3009;
      x2592 = x2592 + 1;
    }
    x2592 = x2592 + 1;
    int x3015 = x2993;
    int x3017 = 0;
    for (;;) {
      int x3018 = x2592;
      char x3019 = x4[x3018];
      bool x3020 = x3019 != '-';
      bool x3025 = x3020;
      if (x3020) {
        int x3021 = x2592;
        char x3022 = x4[x3021];
        bool x3023 = x3022 != '\n';
        x3025 = x3023;
      }
      bool x3026 = x3025;
      if (!x3026) break;
      int x3028 = x3017;
      int x3030 = x2592;
      int x3029 = x3028 * 10;
      char x3031 = x4[x3030];
      char x3032 = x3031 - '0';
      int x3033 = x3029 + x3032;
      x3017 = x3033;
      x2592 = x2592 + 1;
    }
    x2592 = x2592 + 1;
    int x3039 = x3017;
    int x3041 = 0;
    for (;;) {
      int x3042 = x2592;
      char x3043 = x4[x3042];
      bool x3044 = x3043 != '|';
      bool x3049 = x3044;
      if (x3044) {
        int x3045 = x2592;
        char x3046 = x4[x3045];
        bool x3047 = x3046 != '\n';
        x3049 = x3047;
      }
      bool x3050 = x3049;
      if (!x3050) break;
      int x3052 = x3041;
      int x3054 = x2592;
      int x3053 = x3052 * 10;
      char x3055 = x4[x3054];
      char x3056 = x3055 - '0';
      int x3057 = x3053 + x3056;
      x3041 = x3057;
      x2592 = x2592 + 1;
    }
    x2592 = x2592 + 1;
    int x3063 = x3041;
    for (;;) {
      int x3070 = x2592;
      char x3071 = x4[x3070];
      bool x3072 = x3071 != '-';
      bool x3077 = x3072;
      if (x3072) {
        int x3073 = x2592;
        char x3074 = x4[x3073];
        bool x3075 = x3074 != '\n';
        x3077 = x3075;
      }
      bool x3078 = x3077;
      if (!x3078) break;
      x2592 = x2592 + 1;
    }
    x2592 = x2592 + 1;
    for (;;) {
      int x3094 = x2592;
      char x3095 = x4[x3094];
      bool x3096 = x3095 != '-';
      bool x3101 = x3096;
      if (x3096) {
        int x3097 = x2592;
        char x3098 = x4[x3097];
        bool x3099 = x3098 != '\n';
        x3101 = x3099;
      }
      bool x3102 = x3101;
      if (!x3102) break;
      x2592 = x2592 + 1;
    }
    x2592 = x2592 + 1;
    for (;;) {
      int x3118 = x2592;
      char x3119 = x4[x3118];
      bool x3120 = x3119 != '|';
      bool x3125 = x3120;
      if (x3120) {
        int x3121 = x2592;
        char x3122 = x4[x3121];
        bool x3123 = x3122 != '\n';
        x3125 = x3123;
      }
      bool x3126 = x3125;
      if (!x3126) break;
      x2592 = x2592 + 1;
    }
    x2592 = x2592 + 1;
    for (;;) {
      int x3146 = x2592;
      char x3147 = x4[x3146];
      bool x3148 = x3147 != '-';
      bool x3153 = x3148;
      if (x3148) {
        int x3149 = x2592;
        char x3150 = x4[x3149];
        bool x3151 = x3150 != '\n';
        x3153 = x3151;
      }
      bool x3154 = x3153;
      if (!x3154) break;
      x2592 = x2592 + 1;
    }
    x2592 = x2592 + 1;
    for (;;) {
      int x3170 = x2592;
      char x3171 = x4[x3170];
      bool x3172 = x3171 != '-';
      bool x3177 = x3172;
      if (x3172) {
        int x3173 = x2592;
        char x3174 = x4[x3173];
        bool x3175 = x3174 != '\n';
        x3177 = x3175;
      }
      bool x3178 = x3177;
      if (!x3178) break;
      x2592 = x2592 + 1;
    }
    x2592 = x2592 + 1;
    for (;;) {
      int x3194 = x2592;
      char x3195 = x4[x3194];
      bool x3196 = x3195 != '|';
      bool x3201 = x3196;
      if (x3196) {
        int x3197 = x2592;
        char x3198 = x4[x3197];
        bool x3199 = x3198 != '\n';
        x3201 = x3199;
      }
      bool x3202 = x3201;
      if (!x3202) break;
      x2592 = x2592 + 1;
    }
    x2592 = x2592 + 1;
    for (;;) {
      int x3221 = x2592;
      char x3222 = x4[x3221];
      bool x3223 = x3222 != '|';
      bool x3228 = x3223;
      if (x3223) {
        int x3224 = x2592;
        char x3225 = x4[x3224];
        bool x3226 = x3225 != '\n';
        x3228 = x3226;
      }
      bool x3229 = x3228;
      if (!x3229) break;
      x2592 = x2592 + 1;
    }
    x2592 = x2592 + 1;
    for (;;) {
      int x3239 = x2592;
      char x3240 = x4[x3239];
      bool x3241 = x3240 != '|';
      bool x3246 = x3241;
      if (x3241) {
        int x3242 = x2592;
        char x3243 = x4[x3242];
        bool x3244 = x3243 != '\n';
        x3246 = x3244;
      }
      bool x3247 = x3246;
      if (!x3247) break;
      x2592 = x2592 + 1;
    }
    x2592 = x2592 + 1;
    for (;;) {
      int x3257 = x2592;
      char x3258 = x4[x3257];
      bool x3259 = x3258 != '|';
      bool x3264 = x3259;
      if (x3259) {
        int x3260 = x2592;
        char x3261 = x4[x3260];
        bool x3262 = x3261 != '\n';
        x3264 = x3262;
      }
      bool x3265 = x3264;
      if (!x3265) break;
      x2592 = x2592 + 1;
    }
    x2592 = x2592 + 1;
    int x3275 = x2594;
    int x3276 = x2593;
    bool x3277 = x3275 == x3276;
    if (x3277) {
      int x3278 = x3276 * 4;
      x2593 = x3278;
      printf("buffer.resize %d\n",x3278);
      int* x3281 = x2596;
      int* x3282 = (int*)realloc(x3281,x3278 * sizeof(int));
      x2596 = x3282;
      double* x3296 = x2606;
      double* x3297 = (double*)realloc(x3296,x3278 * sizeof(double));
      x2606 = x3297;
      double* x3299 = x2608;
      double* x3300 = (double*)realloc(x3299,x3278 * sizeof(double));
      x2608 = x3300;
      long* x3311 = x2616;
      long* x3312 = (long*)realloc(x3311,x3278 * sizeof(long));
      x2616 = x3312;
    } else {
    }
    int* x3331 = x2596;
    x3331[x3275] = x2653;
    double* x3341 = x2606;
    double x2852 = (double)x2851;
    double x2854 = (double)x2853;
    double x2855 = x2852 / x2854;
    x3341[x3275] = x2855;
    double* x3343 = x2608;
    double x2917 = (double)x2916;
    double x2919 = (double)x2918;
    double x2920 = x2917 / x2919;
    x3343[x3275] = x2920;
    long* x3351 = x2616;
    long x3064 = x3015 * 10000L;
    long x3065 = x3039 * 100L;
    long x3066 = x3064 + x3065;
    long x3067 = x3066 + x3063;
    x3351[x3275] = x3067;
    x2594 = x2594 + 1;
  }
  int x3369 = 0;
  int x3370 = 1048576;
  int x3371 = 0;
  int* x3372 = (int*)malloc(1048576 * sizeof(int));
  int* x3373 = x3372;
  int* x3374 = (int*)malloc(1048576 * sizeof(int));
  int* x3375 = x3374;
  long* x3380 = (long*)malloc(1048576 * sizeof(long));
  long* x3381 = x3380;
  int* x3386 = (int*)malloc(1048576 * sizeof(int));
  int* x3387 = x3386;
  int x3366 = open("../databases/sf2/orders.tbl",0);
  int x3367 = fsize(x3366);
  char* x3368 = mmap(0, x3367, PROT_READ, MAP_FILE | MAP_SHARED, x3366, 0);
  for (;;) {
    int x3390 = x3369;
    bool x3391 = x3390 < x3367;
    if (!x3391) break;
    int x3394 = 0;
    for (;;) {
      int x3395 = x3369;
      char x3396 = x3368[x3395];
      bool x3397 = x3396 != '|';
      bool x3402 = x3397;
      if (x3397) {
        int x3398 = x3369;
        char x3399 = x3368[x3398];
        bool x3400 = x3399 != '\n';
        x3402 = x3400;
      }
      bool x3403 = x3402;
      if (!x3403) break;
      int x3405 = x3394;
      int x3407 = x3369;
      int x3406 = x3405 * 10;
      char x3408 = x3368[x3407];
      char x3409 = x3408 - '0';
      int x3410 = x3406 + x3409;
      x3394 = x3410;
      x3369 = x3369 + 1;
    }
    x3369 = x3369 + 1;
    int x3416 = x3394;
    int x3418 = 0;
    for (;;) {
      int x3419 = x3369;
      char x3420 = x3368[x3419];
      bool x3421 = x3420 != '|';
      bool x3426 = x3421;
      if (x3421) {
        int x3422 = x3369;
        char x3423 = x3368[x3422];
        bool x3424 = x3423 != '\n';
        x3426 = x3424;
      }
      bool x3427 = x3426;
      if (!x3427) break;
      int x3429 = x3418;
      int x3431 = x3369;
      int x3430 = x3429 * 10;
      char x3432 = x3368[x3431];
      char x3433 = x3432 - '0';
      int x3434 = x3430 + x3433;
      x3418 = x3434;
      x3369 = x3369 + 1;
    }
    x3369 = x3369 + 1;
    int x3440 = x3418;
    x3369 = x3369 + 2;
    for (;;) {
      int x3447 = x3369;
      char x3448 = x3368[x3447];
      bool x3449 = x3448 != '.';
      bool x3454 = x3449;
      if (x3449) {
        int x3450 = x3369;
        char x3451 = x3368[x3450];
        bool x3452 = x3451 != '|';
        x3454 = x3452;
      }
      bool x3455 = x3454;
      bool x3460 = x3455;
      if (x3455) {
        int x3456 = x3369;
        char x3457 = x3368[x3456];
        bool x3458 = x3457 != '\n';
        x3460 = x3458;
      }
      bool x3461 = x3460;
      if (!x3461) break;
      x3369 = x3369 + 1;
    }
    int x3473 = x3369;
    char x3474 = x3368[x3473];
    bool x3475 = x3474 == '.';
    if (x3475) {
      x3369 = x3369 + 1;
      for (;;) {
        int x3477 = x3369;
        char x3478 = x3368[x3477];
        bool x3479 = x3478 != '|';
        bool x3484 = x3479;
        if (x3479) {
          int x3480 = x3369;
          char x3481 = x3368[x3480];
          bool x3482 = x3481 != '\n';
          x3484 = x3482;
        }
        bool x3485 = x3484;
        if (!x3485) break;
        x3369 = x3369 + 1;
      }
    } else {
    }
    x3369 = x3369 + 1;
    int x3510 = 0;
    for (;;) {
      int x3511 = x3369;
      char x3512 = x3368[x3511];
      bool x3513 = x3512 != '-';
      bool x3518 = x3513;
      if (x3513) {
        int x3514 = x3369;
        char x3515 = x3368[x3514];
        bool x3516 = x3515 != '\n';
        x3518 = x3516;
      }
      bool x3519 = x3518;
      if (!x3519) break;
      int x3521 = x3510;
      int x3523 = x3369;
      int x3522 = x3521 * 10;
      char x3524 = x3368[x3523];
      char x3525 = x3524 - '0';
      int x3526 = x3522 + x3525;
      x3510 = x3526;
      x3369 = x3369 + 1;
    }
    x3369 = x3369 + 1;
    int x3532 = x3510;
    int x3534 = 0;
    for (;;) {
      int x3535 = x3369;
      char x3536 = x3368[x3535];
      bool x3537 = x3536 != '-';
      bool x3542 = x3537;
      if (x3537) {
        int x3538 = x3369;
        char x3539 = x3368[x3538];
        bool x3540 = x3539 != '\n';
        x3542 = x3540;
      }
      bool x3543 = x3542;
      if (!x3543) break;
      int x3545 = x3534;
      int x3547 = x3369;
      int x3546 = x3545 * 10;
      char x3548 = x3368[x3547];
      char x3549 = x3548 - '0';
      int x3550 = x3546 + x3549;
      x3534 = x3550;
      x3369 = x3369 + 1;
    }
    x3369 = x3369 + 1;
    int x3556 = x3534;
    int x3558 = 0;
    for (;;) {
      int x3559 = x3369;
      char x3560 = x3368[x3559];
      bool x3561 = x3560 != '|';
      bool x3566 = x3561;
      if (x3561) {
        int x3562 = x3369;
        char x3563 = x3368[x3562];
        bool x3564 = x3563 != '\n';
        x3566 = x3564;
      }
      bool x3567 = x3566;
      if (!x3567) break;
      int x3569 = x3558;
      int x3571 = x3369;
      int x3570 = x3569 * 10;
      char x3572 = x3368[x3571];
      char x3573 = x3572 - '0';
      int x3574 = x3570 + x3573;
      x3558 = x3574;
      x3369 = x3369 + 1;
    }
    x3369 = x3369 + 1;
    int x3580 = x3558;
    for (;;) {
      int x3586 = x3369;
      char x3587 = x3368[x3586];
      bool x3588 = x3587 != '|';
      bool x3593 = x3588;
      if (x3588) {
        int x3589 = x3369;
        char x3590 = x3368[x3589];
        bool x3591 = x3590 != '\n';
        x3593 = x3591;
      }
      bool x3594 = x3593;
      if (!x3594) break;
      x3369 = x3369 + 1;
    }
    x3369 = x3369 + 1;
    for (;;) {
      int x3604 = x3369;
      char x3605 = x3368[x3604];
      bool x3606 = x3605 != '|';
      bool x3611 = x3606;
      if (x3606) {
        int x3607 = x3369;
        char x3608 = x3368[x3607];
        bool x3609 = x3608 != '\n';
        x3611 = x3609;
      }
      bool x3612 = x3611;
      if (!x3612) break;
      x3369 = x3369 + 1;
    }
    x3369 = x3369 + 1;
    int x3622 = 0;
    for (;;) {
      int x3623 = x3369;
      char x3624 = x3368[x3623];
      bool x3625 = x3624 != '|';
      bool x3630 = x3625;
      if (x3625) {
        int x3626 = x3369;
        char x3627 = x3368[x3626];
        bool x3628 = x3627 != '\n';
        x3630 = x3628;
      }
      bool x3631 = x3630;
      if (!x3631) break;
      int x3633 = x3622;
      int x3635 = x3369;
      int x3634 = x3633 * 10;
      char x3636 = x3368[x3635];
      char x3637 = x3636 - '0';
      int x3638 = x3634 + x3637;
      x3622 = x3638;
      x3369 = x3369 + 1;
    }
    x3369 = x3369 + 1;
    int x3644 = x3622;
    for (;;) {
      int x3646 = x3369;
      char x3647 = x3368[x3646];
      bool x3648 = x3647 != '|';
      bool x3653 = x3648;
      if (x3648) {
        int x3649 = x3369;
        char x3650 = x3368[x3649];
        bool x3651 = x3650 != '\n';
        x3653 = x3651;
      }
      bool x3654 = x3653;
      if (!x3654) break;
      x3369 = x3369 + 1;
    }
    x3369 = x3369 + 1;
    int x3664 = x3371;
    int x3665 = x3370;
    bool x3666 = x3664 == x3665;
    if (x3666) {
      int x3667 = x3665 * 4;
      x3370 = x3667;
      printf("buffer.resize %d\n",x3667);
      int* x3670 = x3373;
      int* x3671 = (int*)realloc(x3670,x3667 * sizeof(int));
      x3373 = x3671;
      int* x3673 = x3375;
      int* x3674 = (int*)realloc(x3673,x3667 * sizeof(int));
      x3375 = x3674;
      long* x3682 = x3381;
      long* x3683 = (long*)realloc(x3682,x3667 * sizeof(long));
      x3381 = x3683;
      int* x3691 = x3387;
      int* x3692 = (int*)realloc(x3691,x3667 * sizeof(int));
      x3387 = x3692;
    } else {
    }
    int* x3699 = x3373;
    x3699[x3664] = x3416;
    int* x3701 = x3375;
    x3701[x3664] = x3440;
    long* x3707 = x3381;
    long x3581 = x3532 * 10000L;
    long x3582 = x3556 * 100L;
    long x3583 = x3581 + x3582;
    long x3584 = x3583 + x3580;
    x3707[x3664] = x3584;
    int* x3713 = x3387;
    x3713[x3664] = x3644;
    x3371 = x3371 + 1;
  }
  int x3723 = 0;
  int x3724 = 1048576;
  int x3725 = 0;
  int* x3726 = (int*)malloc(1048576 * sizeof(int));
  int* x3727 = x3726;
  char** x3738 = (char**)malloc(1048576 * sizeof(char*));
  char** x3739 = x3738;
  int x3720 = open("../databases/sf2/customer.tbl",0);
  int x3721 = fsize(x3720);
  char* x3722 = mmap(0, x3721, PROT_READ, MAP_FILE | MAP_SHARED, x3720, 0);
  for (;;) {
    int x3742 = x3723;
    bool x3743 = x3742 < x3721;
    if (!x3743) break;
    int x3746 = 0;
    for (;;) {
      int x3747 = x3723;
      char x3748 = x3722[x3747];
      bool x3749 = x3748 != '|';
      bool x3754 = x3749;
      if (x3749) {
        int x3750 = x3723;
        char x3751 = x3722[x3750];
        bool x3752 = x3751 != '\n';
        x3754 = x3752;
      }
      bool x3755 = x3754;
      if (!x3755) break;
      int x3757 = x3746;
      int x3759 = x3723;
      int x3758 = x3757 * 10;
      char x3760 = x3722[x3759];
      char x3761 = x3760 - '0';
      int x3762 = x3758 + x3761;
      x3746 = x3762;
      x3723 = x3723 + 1;
    }
    x3723 = x3723 + 1;
    int x3768 = x3746;
    for (;;) {
      int x3770 = x3723;
      char x3771 = x3722[x3770];
      bool x3772 = x3771 != '|';
      bool x3777 = x3772;
      if (x3772) {
        int x3773 = x3723;
        char x3774 = x3722[x3773];
        bool x3775 = x3774 != '\n';
        x3777 = x3775;
      }
      bool x3778 = x3777;
      if (!x3778) break;
      x3723 = x3723 + 1;
    }
    x3723 = x3723 + 1;
    for (;;) {
      int x3788 = x3723;
      char x3789 = x3722[x3788];
      bool x3790 = x3789 != '|';
      bool x3795 = x3790;
      if (x3790) {
        int x3791 = x3723;
        char x3792 = x3722[x3791];
        bool x3793 = x3792 != '\n';
        x3795 = x3793;
      }
      bool x3796 = x3795;
      if (!x3796) break;
      x3723 = x3723 + 1;
    }
    x3723 = x3723 + 1;
    for (;;) {
      int x3807 = x3723;
      char x3808 = x3722[x3807];
      bool x3809 = x3808 != '|';
      bool x3814 = x3809;
      if (x3809) {
        int x3810 = x3723;
        char x3811 = x3722[x3810];
        bool x3812 = x3811 != '\n';
        x3814 = x3812;
      }
      bool x3815 = x3814;
      if (!x3815) break;
      x3723 = x3723 + 1;
    }
    x3723 = x3723 + 1;
    for (;;) {
      int x3830 = x3723;
      char x3831 = x3722[x3830];
      bool x3832 = x3831 != '|';
      bool x3837 = x3832;
      if (x3832) {
        int x3833 = x3723;
        char x3834 = x3722[x3833];
        bool x3835 = x3834 != '\n';
        x3837 = x3835;
      }
      bool x3838 = x3837;
      if (!x3838) break;
      x3723 = x3723 + 1;
    }
    x3723 = x3723 + 1;
    for (;;) {
      int x3850 = x3723;
      char x3851 = x3722[x3850];
      bool x3852 = x3851 != '.';
      bool x3857 = x3852;
      if (x3852) {
        int x3853 = x3723;
        char x3854 = x3722[x3853];
        bool x3855 = x3854 != '|';
        x3857 = x3855;
      }
      bool x3858 = x3857;
      bool x3863 = x3858;
      if (x3858) {
        int x3859 = x3723;
        char x3860 = x3722[x3859];
        bool x3861 = x3860 != '\n';
        x3863 = x3861;
      }
      bool x3864 = x3863;
      if (!x3864) break;
      x3723 = x3723 + 1;
    }
    int x3876 = x3723;
    char x3877 = x3722[x3876];
    bool x3878 = x3877 == '.';
    if (x3878) {
      x3723 = x3723 + 1;
      for (;;) {
        int x3880 = x3723;
        char x3881 = x3722[x3880];
        bool x3882 = x3881 != '|';
        bool x3887 = x3882;
        if (x3882) {
          int x3883 = x3723;
          char x3884 = x3722[x3883];
          bool x3885 = x3884 != '\n';
          x3887 = x3885;
        }
        bool x3888 = x3887;
        if (!x3888) break;
        x3723 = x3723 + 1;
      }
    } else {
    }
    x3723 = x3723 + 1;
    int x3912 = x3723;
    for (;;) {
      int x3913 = x3723;
      char x3914 = x3722[x3913];
      bool x3915 = x3914 != '|';
      bool x3920 = x3915;
      if (x3915) {
        int x3916 = x3723;
        char x3917 = x3722[x3916];
        bool x3918 = x3917 != '\n';
        x3920 = x3918;
      }
      bool x3921 = x3920;
      if (!x3921) break;
      x3723 = x3723 + 1;
    }
    x3723 = x3723 + 1;
    for (;;) {
      int x3931 = x3723;
      char x3932 = x3722[x3931];
      bool x3933 = x3932 != '|';
      bool x3938 = x3933;
      if (x3933) {
        int x3934 = x3723;
        char x3935 = x3722[x3934];
        bool x3936 = x3935 != '\n';
        x3938 = x3936;
      }
      bool x3939 = x3938;
      if (!x3939) break;
      x3723 = x3723 + 1;
    }
    x3723 = x3723 + 1;
    int x3949 = x3725;
    int x3950 = x3724;
    bool x3951 = x3949 == x3950;
    if (x3951) {
      int x3952 = x3950 * 4;
      x3724 = x3952;
      printf("buffer.resize %d\n",x3952);
      int* x3955 = x3727;
      int* x3956 = (int*)realloc(x3955,x3952 * sizeof(int));
      x3727 = x3956;
      char** x3973 = x3739;
      char** x3974 = (char**)realloc(x3973,x3952 * sizeof(char*));
      x3739 = x3974;
    } else {
    }
    int* x3981 = x3727;
    x3981[x3949] = x3768;
    char** x3993 = x3739;
    char* x3929 = x3722+x3912;
    x3993[x3949] = x3929;
    x3725 = x3725 + 1;
  }
  int x4000;
  for(x4000=0; x4000 < 5; x4000++) {
    bool x4001 = false;
    int x4002 = 0;
    bool x4004 = false;
    int x4005 = 0;
    bool x4007 = false;
    int x4008 = 0;
    int* x4011 = (int*)malloc(134217728 * sizeof(int));
    int* x4012 = x4011;
    int x4027 = 0;
    int* x4028 = (int*)malloc(67108864 * sizeof(int));
    int* x4029 = (int*)malloc(134217728 * sizeof(int));
    int x4030;
    for(x4030=0; x4030 < 67108864; x4030++) {
      x4028[x4030] = -1;
    }
    int* x4052 = (int*)malloc(134217728 * sizeof(int));
    int* x4053 = x4052;
    long* x4060 = (long*)malloc(134217728 * sizeof(long));
    long* x4061 = x4060;
    int* x4066 = (int*)malloc(134217728 * sizeof(int));
    int* x4067 = x4066;
    int x4070 = 0;
    int* x4071 = (int*)malloc(67108864 * sizeof(int));
    int* x4072 = (int*)malloc(134217728 * sizeof(int));
    int x4073;
    for(x4073=0; x4073 < 67108864; x4073++) {
      x4071[x4073] = -1;
    }
    struct Anon884569349* x4080 = (struct Anon884569349*)malloc(16777216 * sizeof(struct Anon884569349));
    struct Anon884569349* x4081 = x4080;
    int x4082 = 0;
    int* x4083 = (int*)malloc(16777216 * sizeof(int));
    int x4084;
    for(x4084=0; x4084 < 16777216; x4084++) {
      struct Anon884569349* x4085 = x4081;
      struct Anon884569349 x4086 = x4085[x4084];
      struct Anon1465150758 x4087 = x4086.key;;
      struct Anon2052879266 x4088 = x4086.aggs;;
      struct Anon884569349 x4089;
      x4089.exists = false;
      x4089.key = x4087;
      x4089.aggs = x4088;
      x4085[x4084] = x4089;
    }
    int x4093 = 0;
    int x4095 = 0;
    struct timeval x4481, x4482, x4483;
    gettimeofday(&x4481, NULL);
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x4097 = x4001;
      bool x4098 = !x4097;
      bool x4103 = x4098;
      if (x4098) {
        int x4099 = x4002;
        int x4100 = x3725;
        bool x4101 = x4099 < x4100;
        x4103 = x4101;
      }
      bool x4104 = x4103;
      if (!x4104) break;
      int x4106 = x4002;
      int* x4107 = x3727;
      int x4108 = x4107[x4106];
      char** x4119 = x3739;
      char* x4120 = x4119[x4106];
      x4002 = x4002 + 1;
      bool x4125 = strcmp(x4120,"HOUSEHOLD") == 0;;
      if (x4125) {
        int x4126 = x4027;
        int* x4127 = x4012;
        x4127[x4126] = x4108;
        x4027 = x4027 + 1;
        int x4144 = x4108 & 67108863;
        int x4145 = x4028[x4144];
        x4028[x4144] = x4126;
        x4029[x4126] = x4145;
      } else {
      }
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x4153 = x4004;
      bool x4154 = !x4153;
      bool x4159 = x4154;
      if (x4154) {
        int x4155 = x4005;
        int x4156 = x3371;
        bool x4157 = x4155 < x4156;
        x4159 = x4157;
      }
      bool x4160 = x4159;
      if (!x4160) break;
      int x4162 = x4005;
      int* x4163 = x3373;
      int x4164 = x4163[x4162];
      int* x4165 = x3375;
      int x4166 = x4165[x4162];
      long* x4171 = x3381;
      long x4172 = x4171[x4162];
      int* x4177 = x3387;
      int x4178 = x4177[x4162];
      x4005 = x4005 + 1;
      bool x4183 = x4172 < 19950304L;
      if (x4183) {
        int x4184 = x4166 & 67108863;
        int x4185 = x4028[x4184];
        int x4186 = x4185;
        int x4250 = x4164 & 67108863;
        for (;;) {
          int x4187 = x4186;
          bool x4188 = x4187 != -1;
          if (!x4188) break;
          int x4190 = x4186;
          int* x4191 = x4012;
          int x4192 = x4191[x4190];
          int x4208 = x4029[x4190];
          x4186 = x4208;
          bool x4210 = x4192 == x4166;
          if (x4210) {
            int x4214 = x4070;
            int* x4231 = x4053;
            x4231[x4214] = x4164;
            long* x4239 = x4061;
            x4239[x4214] = x4172;
            int* x4245 = x4067;
            x4245[x4214] = x4178;
            x4070 = x4070 + 1;
            int x4251 = x4071[x4250];
            x4071[x4250] = x4214;
            x4072[x4214] = x4251;
          } else {
          }
        }
      } else {
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x4263 = x4007;
      bool x4264 = !x4263;
      bool x4269 = x4264;
      if (x4264) {
        int x4265 = x4008;
        int x4266 = x2594;
        bool x4267 = x4265 < x4266;
        x4269 = x4267;
      }
      bool x4270 = x4269;
      if (!x4270) break;
      int x4272 = x4008;
      int* x4273 = x2596;
      int x4274 = x4273[x4272];
      double* x4283 = x2606;
      double x4284 = x4283[x4272];
      double* x4285 = x2608;
      double x4286 = x4285[x4272];
      long* x4293 = x2616;
      long x4294 = x4293[x4272];
      x4008 = x4008 + 1;
      bool x4307 = x4294 > 19950304L;
      if (x4307) {
        int x4308 = x4274 & 67108863;
        int x4309 = x4071[x4308];
        int x4310 = x4309;
        int x4358 = x4274 * 41;
        double x4385 = 1.0 - x4286;
        double x4386 = x4284 * x4385;
        struct Anon2052879266 x4428;
        x4428._0 = x4386;
        for (;;) {
          int x4311 = x4310;
          bool x4312 = x4311 != -1;
          if (!x4312) break;
          int x4314 = x4310;
          int* x4331 = x4053;
          int x4332 = x4331[x4314];
          long* x4339 = x4061;
          long x4340 = x4339[x4314];
          int* x4345 = x4067;
          int x4346 = x4345[x4314];
          int x4350 = x4072[x4314];
          x4310 = x4350;
          bool x4352 = x4332 == x4274;
          if (x4352) {
            int x4357 = (int)x4340;
            int x4359 = x4358 + x4357;
            int x4360 = x4359 * 41;
            int x4361 = x4360 + x4346;
            int x4362 = x4361 & 16777215;
            int x4363 = x4362;
            struct Anon884569349* x4364 = x4081;
            struct Anon884569349 x4365 = x4364[x4362];
            struct Anon884569349 x4366 = x4365;
            bool x4367 = x4365.exists;;
            bool x4381 = x4367;
            if (x4367) {
              struct Anon884569349 x4368 = x4366;
              struct Anon1465150758 x4369 = x4368.key;;
              int x4370 = x4369.L_ORDERKEY;;
              bool x4371 = x4370 == x4274;
              bool x4376 = x4371;
              if (x4371) {
                long x4372 = x4369.O_ORDERDATE;;
                bool x4373 = x4372 == x4340;
                x4376 = x4373;
              }
              bool x4377 = x4376;
              bool x4378 = x4377;
              if (x4377) {
                int x4374 = x4369.O_SHIPPRIORITY;;
                bool x4375 = x4374 == x4346;
                x4378 = x4375;
              }
              bool x4379 = x4378;
              x4381 = x4379;
            }
            bool x4382 = x4381;
            if (x4382) {
              struct Anon2052879266 x4383 = x4365.aggs;;
              struct Anon1465150758 x4389 = x4365.key;;
              double x4384 = x4383._0;;
              double x4387 = x4384 + x4386;
              struct Anon2052879266 x4388;
              x4388._0 = x4387;
              struct Anon884569349 x4390;
              x4390.exists = true;
              x4390.key = x4389;
              x4390.aggs = x4388;
              x4364[x4362] = x4390;
            } else {
              struct Anon1465150758 x4356;
              x4356.L_ORDERKEY = x4274;
              x4356.O_ORDERDATE = x4340;
              x4356.O_SHIPPRIORITY = x4346;
              struct Anon884569349 x4429;
              x4429.exists = true;
              x4429.key = x4356;
              x4429.aggs = x4428;
              for (;;) {
                struct Anon884569349 x4393 = x4366;
                bool x4394 = x4393.exists;;
                bool x4438;
                if (x4394) {
                  struct Anon1465150758 x4395 = x4393.key;;
                  int x4396 = x4395.L_ORDERKEY;;
                  bool x4397 = x4396 == x4274;
                  bool x4402 = x4397;
                  if (x4397) {
                    long x4398 = x4395.O_ORDERDATE;;
                    bool x4399 = x4398 == x4340;
                    x4402 = x4399;
                  }
                  bool x4403 = x4402;
                  bool x4404 = x4403;
                  if (x4403) {
                    int x4400 = x4395.O_SHIPPRIORITY;;
                    bool x4401 = x4400 == x4346;
                    x4404 = x4401;
                  }
                  bool x4405 = x4404;
                  bool x4425;
                  if (x4405) {
                    struct Anon2052879266 x4406 = x4393.aggs;;
                    int x4410 = x4363;
                    struct Anon884569349* x4412 = x4081;
                    double x4407 = x4406._0;;
                    double x4408 = x4407 + x4386;
                    struct Anon2052879266 x4409;
                    x4409._0 = x4408;
                    struct Anon884569349 x4411;
                    x4411.exists = true;
                    x4411.key = x4395;
                    x4411.aggs = x4409;
                    x4412[x4410] = x4411;
                    x4425 = false;
                  } else {
                    int x4415 = x4363;
                    int x4416 = x4415 + 1;
                    int x4417 = x4416 % 16777215;
                    x4363 = x4417;
                    struct Anon884569349* x4419 = x4081;
                    struct Anon884569349 x4420 = x4419[x4417];
                    x4366 = x4420;
                    x4425 = true;
                  }
                  x4438 = x4425;
                } else {
                  int x4427 = x4363;
                  struct Anon884569349* x4430 = x4081;
                  x4430[x4427] = x4429;
                  int x4432 = x4082;
                  x4083[x4432] = x4427;
                  x4082 = x4082 + 1;
                  x4438 = false;
                }
                if (!x4438) break;
              }
            }
          } else {
          }
        }
      } else {
      }
    }
    int x4453 = x4082;
    int x4455;
    for(x4455=0; x4455 < x4453; x4455++) {
      int x4456 = x4083[x4455];
      struct Anon884569349* x4457 = x4081;
      struct Anon884569349 x4458 = x4457[x4456];
      int x4459 = x4093;
      bool x4460 = x4459 < 10;
      bool x4461 = x4460 == false;
      if (x4461) {
      } else {
        struct Anon1465150758 x4464 = x4458.key;;
        struct Anon2052879266 x4466 = x4458.aggs;;
        int x4465 = x4464.L_ORDERKEY;;
        double x4467 = x4466._0;;
        long x4468 = x4464.O_ORDERDATE;;
        char* x4469 = (char*)malloc(9 * sizeof(char));;
        snprintf(x4469, 9, "%lu", x4468);
        int x4470 = x4464.O_SHIPPRIORITY;;
        printf("%d|%.4f|%.*s|%d\n",x4465,x4467,x4469,x4470);
        x4093 = x4093 + 1;
        x4095 = x4095 + 1;
      }
    }
    int x4478 = x4095;
    printf("(%d rows)\n",x4478);
    gettimeofday(&x4482, NULL);
    timeval_subtract(&x4483, &x4482, &x4481);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x4483.tv_sec * 1000) + (x4483.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
