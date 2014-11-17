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

/************************ FUNCTIONS **************************/

/************************ MAIN BODY **************************/
int main(int x2595, char** x2596) {
  long x2597 = 0L;
  long x6 = DEFAULT_INPUT_SIZE;
  long x2598 = x6;
  long x2599 = 0L;
  int* x2600 = (int*)malloc(x6 * sizeof(int));
  int* x2601 = x2600;
  double* x2610 = (double*)malloc(x6 * sizeof(double));
  double* x2611 = x2610;
  double* x2612 = (double*)malloc(x6 * sizeof(double));
  double* x2613 = x2612;
  long* x2620 = (long*)malloc(x6 * sizeof(long));
  long* x2621 = x2620;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  long x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    long x2632 = x2597;
    bool x2633 = x2632 < x3;
    if (!x2633) break;
    int x2636 = 0;
    for (;;) {
      long x2637 = x2597;
      char x2638 = x4[x2637];
      bool x2639 = x2638 != '|';
      bool x2644 = x2639;
      if (x2639) {
        long x2640 = x2597;
        char x2641 = x4[x2640];
        bool x2642 = x2641 != '\n';
        x2644 = x2642;
      }
      bool x2645 = x2644;
      if (!x2645) break;
      int x2647 = x2636;
      long x2649 = x2597;
      int x2648 = x2647 * 10;
      char x2650 = x4[x2649];
      char x2651 = x2650 - '0';
      int x2652 = x2648 + x2651;
      x2636 = x2652;
      x2597 = x2597 + 1;
    }
    x2597 = x2597 + 1;
    int x2658 = x2636;
    for (;;) {
      long x2661 = x2597;
      char x2662 = x4[x2661];
      bool x2663 = x2662 != '|';
      bool x2668 = x2663;
      if (x2663) {
        long x2664 = x2597;
        char x2665 = x4[x2664];
        bool x2666 = x2665 != '\n';
        x2668 = x2666;
      }
      bool x2669 = x2668;
      if (!x2669) break;
      x2597 = x2597 + 1;
    }
    x2597 = x2597 + 1;
    for (;;) {
      long x2685 = x2597;
      char x2686 = x4[x2685];
      bool x2687 = x2686 != '|';
      bool x2692 = x2687;
      if (x2687) {
        long x2688 = x2597;
        char x2689 = x4[x2688];
        bool x2690 = x2689 != '\n';
        x2692 = x2690;
      }
      bool x2693 = x2692;
      if (!x2693) break;
      x2597 = x2597 + 1;
    }
    x2597 = x2597 + 1;
    for (;;) {
      long x2709 = x2597;
      char x2710 = x4[x2709];
      bool x2711 = x2710 != '|';
      bool x2716 = x2711;
      if (x2711) {
        long x2712 = x2597;
        char x2713 = x4[x2712];
        bool x2714 = x2713 != '\n';
        x2716 = x2714;
      }
      bool x2717 = x2716;
      if (!x2717) break;
      x2597 = x2597 + 1;
    }
    x2597 = x2597 + 1;
    for (;;) {
      long x2734 = x2597;
      char x2735 = x4[x2734];
      bool x2736 = x2735 != '.';
      bool x2741 = x2736;
      if (x2736) {
        long x2737 = x2597;
        char x2738 = x4[x2737];
        bool x2739 = x2738 != '|';
        x2741 = x2739;
      }
      bool x2742 = x2741;
      bool x2747 = x2742;
      if (x2742) {
        long x2743 = x2597;
        char x2744 = x4[x2743];
        bool x2745 = x2744 != '\n';
        x2747 = x2745;
      }
      bool x2748 = x2747;
      if (!x2748) break;
      x2597 = x2597 + 1;
    }
    long x2760 = x2597;
    char x2761 = x4[x2760];
    bool x2762 = x2761 == '.';
    if (x2762) {
      x2597 = x2597 + 1;
      for (;;) {
        long x2764 = x2597;
        char x2765 = x4[x2764];
        bool x2766 = x2765 != '|';
        bool x2771 = x2766;
        if (x2766) {
          long x2767 = x2597;
          char x2768 = x4[x2767];
          bool x2769 = x2768 != '\n';
          x2771 = x2769;
        }
        bool x2772 = x2771;
        if (!x2772) break;
        x2597 = x2597 + 1;
      }
    } else {
    }
    x2597 = x2597 + 1;
    int x2797 = 0;
    int x2798 = 1;
    for (;;) {
      long x2799 = x2597;
      char x2800 = x4[x2799];
      bool x2801 = x2800 != '.';
      bool x2806 = x2801;
      if (x2801) {
        long x2802 = x2597;
        char x2803 = x4[x2802];
        bool x2804 = x2803 != '|';
        x2806 = x2804;
      }
      bool x2807 = x2806;
      bool x2812 = x2807;
      if (x2807) {
        long x2808 = x2597;
        char x2809 = x4[x2808];
        bool x2810 = x2809 != '\n';
        x2812 = x2810;
      }
      bool x2813 = x2812;
      if (!x2813) break;
      int x2815 = x2797;
      long x2817 = x2597;
      int x2816 = x2815 * 10;
      char x2818 = x4[x2817];
      char x2819 = x2818 - '0';
      int x2820 = x2816 + x2819;
      x2797 = x2820;
      x2597 = x2597 + 1;
    }
    long x2825 = x2597;
    char x2826 = x4[x2825];
    bool x2827 = x2826 == '.';
    if (x2827) {
      x2597 = x2597 + 1;
      for (;;) {
        long x2829 = x2597;
        char x2830 = x4[x2829];
        bool x2831 = x2830 != '|';
        bool x2836 = x2831;
        if (x2831) {
          long x2832 = x2597;
          char x2833 = x4[x2832];
          bool x2834 = x2833 != '\n';
          x2836 = x2834;
        }
        bool x2837 = x2836;
        if (!x2837) break;
        int x2839 = x2797;
        long x2841 = x2597;
        int x2840 = x2839 * 10;
        char x2842 = x4[x2841];
        char x2843 = x2842 - '0';
        int x2844 = x2840 + x2843;
        x2797 = x2844;
        int x2846 = x2798;
        int x2847 = x2846 * 10;
        x2798 = x2847;
        x2597 = x2597 + 1;
      }
    } else {
    }
    x2597 = x2597 + 1;
    int x2856 = x2797;
    int x2858 = x2798;
    int x2862 = 0;
    int x2863 = 1;
    for (;;) {
      long x2864 = x2597;
      char x2865 = x4[x2864];
      bool x2866 = x2865 != '.';
      bool x2871 = x2866;
      if (x2866) {
        long x2867 = x2597;
        char x2868 = x4[x2867];
        bool x2869 = x2868 != '|';
        x2871 = x2869;
      }
      bool x2872 = x2871;
      bool x2877 = x2872;
      if (x2872) {
        long x2873 = x2597;
        char x2874 = x4[x2873];
        bool x2875 = x2874 != '\n';
        x2877 = x2875;
      }
      bool x2878 = x2877;
      if (!x2878) break;
      int x2880 = x2862;
      long x2882 = x2597;
      int x2881 = x2880 * 10;
      char x2883 = x4[x2882];
      char x2884 = x2883 - '0';
      int x2885 = x2881 + x2884;
      x2862 = x2885;
      x2597 = x2597 + 1;
    }
    long x2890 = x2597;
    char x2891 = x4[x2890];
    bool x2892 = x2891 == '.';
    if (x2892) {
      x2597 = x2597 + 1;
      for (;;) {
        long x2894 = x2597;
        char x2895 = x4[x2894];
        bool x2896 = x2895 != '|';
        bool x2901 = x2896;
        if (x2896) {
          long x2897 = x2597;
          char x2898 = x4[x2897];
          bool x2899 = x2898 != '\n';
          x2901 = x2899;
        }
        bool x2902 = x2901;
        if (!x2902) break;
        int x2904 = x2862;
        long x2906 = x2597;
        int x2905 = x2904 * 10;
        char x2907 = x4[x2906];
        char x2908 = x2907 - '0';
        int x2909 = x2905 + x2908;
        x2862 = x2909;
        int x2911 = x2863;
        int x2912 = x2911 * 10;
        x2863 = x2912;
        x2597 = x2597 + 1;
      }
    } else {
    }
    x2597 = x2597 + 1;
    int x2921 = x2862;
    int x2923 = x2863;
    for (;;) {
      long x2929 = x2597;
      char x2930 = x4[x2929];
      bool x2931 = x2930 != '.';
      bool x2936 = x2931;
      if (x2931) {
        long x2932 = x2597;
        char x2933 = x4[x2932];
        bool x2934 = x2933 != '|';
        x2936 = x2934;
      }
      bool x2937 = x2936;
      bool x2942 = x2937;
      if (x2937) {
        long x2938 = x2597;
        char x2939 = x4[x2938];
        bool x2940 = x2939 != '\n';
        x2942 = x2940;
      }
      bool x2943 = x2942;
      if (!x2943) break;
      x2597 = x2597 + 1;
    }
    long x2955 = x2597;
    char x2956 = x4[x2955];
    bool x2957 = x2956 == '.';
    if (x2957) {
      x2597 = x2597 + 1;
      for (;;) {
        long x2959 = x2597;
        char x2960 = x4[x2959];
        bool x2961 = x2960 != '|';
        bool x2966 = x2961;
        if (x2961) {
          long x2962 = x2597;
          char x2963 = x4[x2962];
          bool x2964 = x2963 != '\n';
          x2966 = x2964;
        }
        bool x2967 = x2966;
        if (!x2967) break;
        x2597 = x2597 + 1;
      }
    } else {
    }
    x2597 = x2597 + 1;
    x2597 = x2597 + 2;
    x2597 = x2597 + 2;
    int x2998 = 0;
    for (;;) {
      long x2999 = x2597;
      char x3000 = x4[x2999];
      bool x3001 = x3000 != '-';
      bool x3006 = x3001;
      if (x3001) {
        long x3002 = x2597;
        char x3003 = x4[x3002];
        bool x3004 = x3003 != '\n';
        x3006 = x3004;
      }
      bool x3007 = x3006;
      if (!x3007) break;
      int x3009 = x2998;
      long x3011 = x2597;
      int x3010 = x3009 * 10;
      char x3012 = x4[x3011];
      char x3013 = x3012 - '0';
      int x3014 = x3010 + x3013;
      x2998 = x3014;
      x2597 = x2597 + 1;
    }
    x2597 = x2597 + 1;
    int x3020 = x2998;
    int x3022 = 0;
    for (;;) {
      long x3023 = x2597;
      char x3024 = x4[x3023];
      bool x3025 = x3024 != '-';
      bool x3030 = x3025;
      if (x3025) {
        long x3026 = x2597;
        char x3027 = x4[x3026];
        bool x3028 = x3027 != '\n';
        x3030 = x3028;
      }
      bool x3031 = x3030;
      if (!x3031) break;
      int x3033 = x3022;
      long x3035 = x2597;
      int x3034 = x3033 * 10;
      char x3036 = x4[x3035];
      char x3037 = x3036 - '0';
      int x3038 = x3034 + x3037;
      x3022 = x3038;
      x2597 = x2597 + 1;
    }
    x2597 = x2597 + 1;
    int x3044 = x3022;
    int x3046 = 0;
    for (;;) {
      long x3047 = x2597;
      char x3048 = x4[x3047];
      bool x3049 = x3048 != '|';
      bool x3054 = x3049;
      if (x3049) {
        long x3050 = x2597;
        char x3051 = x4[x3050];
        bool x3052 = x3051 != '\n';
        x3054 = x3052;
      }
      bool x3055 = x3054;
      if (!x3055) break;
      int x3057 = x3046;
      long x3059 = x2597;
      int x3058 = x3057 * 10;
      char x3060 = x4[x3059];
      char x3061 = x3060 - '0';
      int x3062 = x3058 + x3061;
      x3046 = x3062;
      x2597 = x2597 + 1;
    }
    x2597 = x2597 + 1;
    int x3068 = x3046;
    for (;;) {
      long x3075 = x2597;
      char x3076 = x4[x3075];
      bool x3077 = x3076 != '-';
      bool x3082 = x3077;
      if (x3077) {
        long x3078 = x2597;
        char x3079 = x4[x3078];
        bool x3080 = x3079 != '\n';
        x3082 = x3080;
      }
      bool x3083 = x3082;
      if (!x3083) break;
      x2597 = x2597 + 1;
    }
    x2597 = x2597 + 1;
    for (;;) {
      long x3099 = x2597;
      char x3100 = x4[x3099];
      bool x3101 = x3100 != '-';
      bool x3106 = x3101;
      if (x3101) {
        long x3102 = x2597;
        char x3103 = x4[x3102];
        bool x3104 = x3103 != '\n';
        x3106 = x3104;
      }
      bool x3107 = x3106;
      if (!x3107) break;
      x2597 = x2597 + 1;
    }
    x2597 = x2597 + 1;
    for (;;) {
      long x3123 = x2597;
      char x3124 = x4[x3123];
      bool x3125 = x3124 != '|';
      bool x3130 = x3125;
      if (x3125) {
        long x3126 = x2597;
        char x3127 = x4[x3126];
        bool x3128 = x3127 != '\n';
        x3130 = x3128;
      }
      bool x3131 = x3130;
      if (!x3131) break;
      x2597 = x2597 + 1;
    }
    x2597 = x2597 + 1;
    for (;;) {
      long x3151 = x2597;
      char x3152 = x4[x3151];
      bool x3153 = x3152 != '-';
      bool x3158 = x3153;
      if (x3153) {
        long x3154 = x2597;
        char x3155 = x4[x3154];
        bool x3156 = x3155 != '\n';
        x3158 = x3156;
      }
      bool x3159 = x3158;
      if (!x3159) break;
      x2597 = x2597 + 1;
    }
    x2597 = x2597 + 1;
    for (;;) {
      long x3175 = x2597;
      char x3176 = x4[x3175];
      bool x3177 = x3176 != '-';
      bool x3182 = x3177;
      if (x3177) {
        long x3178 = x2597;
        char x3179 = x4[x3178];
        bool x3180 = x3179 != '\n';
        x3182 = x3180;
      }
      bool x3183 = x3182;
      if (!x3183) break;
      x2597 = x2597 + 1;
    }
    x2597 = x2597 + 1;
    for (;;) {
      long x3199 = x2597;
      char x3200 = x4[x3199];
      bool x3201 = x3200 != '|';
      bool x3206 = x3201;
      if (x3201) {
        long x3202 = x2597;
        char x3203 = x4[x3202];
        bool x3204 = x3203 != '\n';
        x3206 = x3204;
      }
      bool x3207 = x3206;
      if (!x3207) break;
      x2597 = x2597 + 1;
    }
    x2597 = x2597 + 1;
    for (;;) {
      long x3226 = x2597;
      char x3227 = x4[x3226];
      bool x3228 = x3227 != '|';
      bool x3233 = x3228;
      if (x3228) {
        long x3229 = x2597;
        char x3230 = x4[x3229];
        bool x3231 = x3230 != '\n';
        x3233 = x3231;
      }
      bool x3234 = x3233;
      if (!x3234) break;
      x2597 = x2597 + 1;
    }
    x2597 = x2597 + 1;
    for (;;) {
      long x3244 = x2597;
      char x3245 = x4[x3244];
      bool x3246 = x3245 != '|';
      bool x3251 = x3246;
      if (x3246) {
        long x3247 = x2597;
        char x3248 = x4[x3247];
        bool x3249 = x3248 != '\n';
        x3251 = x3249;
      }
      bool x3252 = x3251;
      if (!x3252) break;
      x2597 = x2597 + 1;
    }
    x2597 = x2597 + 1;
    for (;;) {
      long x3262 = x2597;
      char x3263 = x4[x3262];
      bool x3264 = x3263 != '|';
      bool x3269 = x3264;
      if (x3264) {
        long x3265 = x2597;
        char x3266 = x4[x3265];
        bool x3267 = x3266 != '\n';
        x3269 = x3267;
      }
      bool x3270 = x3269;
      if (!x3270) break;
      x2597 = x2597 + 1;
    }
    x2597 = x2597 + 1;
    long x3280 = x2599;
    long x3281 = x2598;
    bool x3282 = x3280 == x3281;
    if (x3282) {
      long x3283 = x3281 * 4L;
      x2598 = x3283;
      printf("buffer.resize %d\n",x3283);
      int* x3286 = x2601;
      int* x3287 = (int*)realloc(x3286,x3283 * sizeof(int));
      x2601 = x3287;
      double* x3301 = x2611;
      double* x3302 = (double*)realloc(x3301,x3283 * sizeof(double));
      x2611 = x3302;
      double* x3304 = x2613;
      double* x3305 = (double*)realloc(x3304,x3283 * sizeof(double));
      x2613 = x3305;
      long* x3316 = x2621;
      long* x3317 = (long*)realloc(x3316,x3283 * sizeof(long));
      x2621 = x3317;
    } else {
    }
    int* x3336 = x2601;
    x3336[x3280] = x2658;
    double* x3346 = x2611;
    double x2857 = (double)x2856;
    double x2859 = (double)x2858;
    double x2860 = x2857 / x2859;
    x3346[x3280] = x2860;
    double* x3348 = x2613;
    double x2922 = (double)x2921;
    double x2924 = (double)x2923;
    double x2925 = x2922 / x2924;
    x3348[x3280] = x2925;
    long* x3356 = x2621;
    long x3069 = x3020 * 10000L;
    long x3070 = x3044 * 100L;
    long x3071 = x3069 + x3070;
    long x3072 = x3071 + x3068;
    x3356[x3280] = x3072;
    x2599 = x2599 + 1;
  }
  long x3374 = 0L;
  long x3375 = x6;
  long x3376 = 0L;
  int* x3377 = (int*)malloc(x6 * sizeof(int));
  int* x3378 = x3377;
  int* x3379 = (int*)malloc(x6 * sizeof(int));
  int* x3380 = x3379;
  long* x3385 = (long*)malloc(x6 * sizeof(long));
  long* x3386 = x3385;
  int* x3391 = (int*)malloc(x6 * sizeof(int));
  int* x3392 = x3391;
  int x3371 = open("../databases/sf2/orders.tbl",0);
  long x3372 = fsize(x3371);
  char* x3373 = mmap(0, x3372, PROT_READ, MAP_FILE | MAP_SHARED, x3371, 0);
  for (;;) {
    long x3395 = x3374;
    bool x3396 = x3395 < x3372;
    if (!x3396) break;
    int x3399 = 0;
    for (;;) {
      long x3400 = x3374;
      char x3401 = x3373[x3400];
      bool x3402 = x3401 != '|';
      bool x3407 = x3402;
      if (x3402) {
        long x3403 = x3374;
        char x3404 = x3373[x3403];
        bool x3405 = x3404 != '\n';
        x3407 = x3405;
      }
      bool x3408 = x3407;
      if (!x3408) break;
      int x3410 = x3399;
      long x3412 = x3374;
      int x3411 = x3410 * 10;
      char x3413 = x3373[x3412];
      char x3414 = x3413 - '0';
      int x3415 = x3411 + x3414;
      x3399 = x3415;
      x3374 = x3374 + 1;
    }
    x3374 = x3374 + 1;
    int x3421 = x3399;
    int x3423 = 0;
    for (;;) {
      long x3424 = x3374;
      char x3425 = x3373[x3424];
      bool x3426 = x3425 != '|';
      bool x3431 = x3426;
      if (x3426) {
        long x3427 = x3374;
        char x3428 = x3373[x3427];
        bool x3429 = x3428 != '\n';
        x3431 = x3429;
      }
      bool x3432 = x3431;
      if (!x3432) break;
      int x3434 = x3423;
      long x3436 = x3374;
      int x3435 = x3434 * 10;
      char x3437 = x3373[x3436];
      char x3438 = x3437 - '0';
      int x3439 = x3435 + x3438;
      x3423 = x3439;
      x3374 = x3374 + 1;
    }
    x3374 = x3374 + 1;
    int x3445 = x3423;
    x3374 = x3374 + 2;
    for (;;) {
      long x3452 = x3374;
      char x3453 = x3373[x3452];
      bool x3454 = x3453 != '.';
      bool x3459 = x3454;
      if (x3454) {
        long x3455 = x3374;
        char x3456 = x3373[x3455];
        bool x3457 = x3456 != '|';
        x3459 = x3457;
      }
      bool x3460 = x3459;
      bool x3465 = x3460;
      if (x3460) {
        long x3461 = x3374;
        char x3462 = x3373[x3461];
        bool x3463 = x3462 != '\n';
        x3465 = x3463;
      }
      bool x3466 = x3465;
      if (!x3466) break;
      x3374 = x3374 + 1;
    }
    long x3478 = x3374;
    char x3479 = x3373[x3478];
    bool x3480 = x3479 == '.';
    if (x3480) {
      x3374 = x3374 + 1;
      for (;;) {
        long x3482 = x3374;
        char x3483 = x3373[x3482];
        bool x3484 = x3483 != '|';
        bool x3489 = x3484;
        if (x3484) {
          long x3485 = x3374;
          char x3486 = x3373[x3485];
          bool x3487 = x3486 != '\n';
          x3489 = x3487;
        }
        bool x3490 = x3489;
        if (!x3490) break;
        x3374 = x3374 + 1;
      }
    } else {
    }
    x3374 = x3374 + 1;
    int x3515 = 0;
    for (;;) {
      long x3516 = x3374;
      char x3517 = x3373[x3516];
      bool x3518 = x3517 != '-';
      bool x3523 = x3518;
      if (x3518) {
        long x3519 = x3374;
        char x3520 = x3373[x3519];
        bool x3521 = x3520 != '\n';
        x3523 = x3521;
      }
      bool x3524 = x3523;
      if (!x3524) break;
      int x3526 = x3515;
      long x3528 = x3374;
      int x3527 = x3526 * 10;
      char x3529 = x3373[x3528];
      char x3530 = x3529 - '0';
      int x3531 = x3527 + x3530;
      x3515 = x3531;
      x3374 = x3374 + 1;
    }
    x3374 = x3374 + 1;
    int x3537 = x3515;
    int x3539 = 0;
    for (;;) {
      long x3540 = x3374;
      char x3541 = x3373[x3540];
      bool x3542 = x3541 != '-';
      bool x3547 = x3542;
      if (x3542) {
        long x3543 = x3374;
        char x3544 = x3373[x3543];
        bool x3545 = x3544 != '\n';
        x3547 = x3545;
      }
      bool x3548 = x3547;
      if (!x3548) break;
      int x3550 = x3539;
      long x3552 = x3374;
      int x3551 = x3550 * 10;
      char x3553 = x3373[x3552];
      char x3554 = x3553 - '0';
      int x3555 = x3551 + x3554;
      x3539 = x3555;
      x3374 = x3374 + 1;
    }
    x3374 = x3374 + 1;
    int x3561 = x3539;
    int x3563 = 0;
    for (;;) {
      long x3564 = x3374;
      char x3565 = x3373[x3564];
      bool x3566 = x3565 != '|';
      bool x3571 = x3566;
      if (x3566) {
        long x3567 = x3374;
        char x3568 = x3373[x3567];
        bool x3569 = x3568 != '\n';
        x3571 = x3569;
      }
      bool x3572 = x3571;
      if (!x3572) break;
      int x3574 = x3563;
      long x3576 = x3374;
      int x3575 = x3574 * 10;
      char x3577 = x3373[x3576];
      char x3578 = x3577 - '0';
      int x3579 = x3575 + x3578;
      x3563 = x3579;
      x3374 = x3374 + 1;
    }
    x3374 = x3374 + 1;
    int x3585 = x3563;
    for (;;) {
      long x3591 = x3374;
      char x3592 = x3373[x3591];
      bool x3593 = x3592 != '|';
      bool x3598 = x3593;
      if (x3593) {
        long x3594 = x3374;
        char x3595 = x3373[x3594];
        bool x3596 = x3595 != '\n';
        x3598 = x3596;
      }
      bool x3599 = x3598;
      if (!x3599) break;
      x3374 = x3374 + 1;
    }
    x3374 = x3374 + 1;
    for (;;) {
      long x3609 = x3374;
      char x3610 = x3373[x3609];
      bool x3611 = x3610 != '|';
      bool x3616 = x3611;
      if (x3611) {
        long x3612 = x3374;
        char x3613 = x3373[x3612];
        bool x3614 = x3613 != '\n';
        x3616 = x3614;
      }
      bool x3617 = x3616;
      if (!x3617) break;
      x3374 = x3374 + 1;
    }
    x3374 = x3374 + 1;
    int x3627 = 0;
    for (;;) {
      long x3628 = x3374;
      char x3629 = x3373[x3628];
      bool x3630 = x3629 != '|';
      bool x3635 = x3630;
      if (x3630) {
        long x3631 = x3374;
        char x3632 = x3373[x3631];
        bool x3633 = x3632 != '\n';
        x3635 = x3633;
      }
      bool x3636 = x3635;
      if (!x3636) break;
      int x3638 = x3627;
      long x3640 = x3374;
      int x3639 = x3638 * 10;
      char x3641 = x3373[x3640];
      char x3642 = x3641 - '0';
      int x3643 = x3639 + x3642;
      x3627 = x3643;
      x3374 = x3374 + 1;
    }
    x3374 = x3374 + 1;
    int x3649 = x3627;
    for (;;) {
      long x3651 = x3374;
      char x3652 = x3373[x3651];
      bool x3653 = x3652 != '|';
      bool x3658 = x3653;
      if (x3653) {
        long x3654 = x3374;
        char x3655 = x3373[x3654];
        bool x3656 = x3655 != '\n';
        x3658 = x3656;
      }
      bool x3659 = x3658;
      if (!x3659) break;
      x3374 = x3374 + 1;
    }
    x3374 = x3374 + 1;
    long x3669 = x3376;
    long x3670 = x3375;
    bool x3671 = x3669 == x3670;
    if (x3671) {
      long x3672 = x3670 * 4L;
      x3375 = x3672;
      printf("buffer.resize %d\n",x3672);
      int* x3675 = x3378;
      int* x3676 = (int*)realloc(x3675,x3672 * sizeof(int));
      x3378 = x3676;
      int* x3678 = x3380;
      int* x3679 = (int*)realloc(x3678,x3672 * sizeof(int));
      x3380 = x3679;
      long* x3687 = x3386;
      long* x3688 = (long*)realloc(x3687,x3672 * sizeof(long));
      x3386 = x3688;
      int* x3696 = x3392;
      int* x3697 = (int*)realloc(x3696,x3672 * sizeof(int));
      x3392 = x3697;
    } else {
    }
    int* x3704 = x3378;
    x3704[x3669] = x3421;
    int* x3706 = x3380;
    x3706[x3669] = x3445;
    long* x3712 = x3386;
    long x3586 = x3537 * 10000L;
    long x3587 = x3561 * 100L;
    long x3588 = x3586 + x3587;
    long x3589 = x3588 + x3585;
    x3712[x3669] = x3589;
    int* x3718 = x3392;
    x3718[x3669] = x3649;
    x3376 = x3376 + 1;
  }
  long x3728 = 0L;
  long x3729 = x6;
  long x3730 = 0L;
  int* x3731 = (int*)malloc(x6 * sizeof(int));
  int* x3732 = x3731;
  char** x3743 = (char**)malloc(x6 * sizeof(char*));
  char** x3744 = x3743;
  int x3725 = open("../databases/sf2/customer.tbl",0);
  long x3726 = fsize(x3725);
  char* x3727 = mmap(0, x3726, PROT_READ, MAP_FILE | MAP_SHARED, x3725, 0);
  for (;;) {
    long x3747 = x3728;
    bool x3748 = x3747 < x3726;
    if (!x3748) break;
    int x3751 = 0;
    for (;;) {
      long x3752 = x3728;
      char x3753 = x3727[x3752];
      bool x3754 = x3753 != '|';
      bool x3759 = x3754;
      if (x3754) {
        long x3755 = x3728;
        char x3756 = x3727[x3755];
        bool x3757 = x3756 != '\n';
        x3759 = x3757;
      }
      bool x3760 = x3759;
      if (!x3760) break;
      int x3762 = x3751;
      long x3764 = x3728;
      int x3763 = x3762 * 10;
      char x3765 = x3727[x3764];
      char x3766 = x3765 - '0';
      int x3767 = x3763 + x3766;
      x3751 = x3767;
      x3728 = x3728 + 1;
    }
    x3728 = x3728 + 1;
    int x3773 = x3751;
    for (;;) {
      long x3775 = x3728;
      char x3776 = x3727[x3775];
      bool x3777 = x3776 != '|';
      bool x3782 = x3777;
      if (x3777) {
        long x3778 = x3728;
        char x3779 = x3727[x3778];
        bool x3780 = x3779 != '\n';
        x3782 = x3780;
      }
      bool x3783 = x3782;
      if (!x3783) break;
      x3728 = x3728 + 1;
    }
    x3728 = x3728 + 1;
    for (;;) {
      long x3793 = x3728;
      char x3794 = x3727[x3793];
      bool x3795 = x3794 != '|';
      bool x3800 = x3795;
      if (x3795) {
        long x3796 = x3728;
        char x3797 = x3727[x3796];
        bool x3798 = x3797 != '\n';
        x3800 = x3798;
      }
      bool x3801 = x3800;
      if (!x3801) break;
      x3728 = x3728 + 1;
    }
    x3728 = x3728 + 1;
    for (;;) {
      long x3812 = x3728;
      char x3813 = x3727[x3812];
      bool x3814 = x3813 != '|';
      bool x3819 = x3814;
      if (x3814) {
        long x3815 = x3728;
        char x3816 = x3727[x3815];
        bool x3817 = x3816 != '\n';
        x3819 = x3817;
      }
      bool x3820 = x3819;
      if (!x3820) break;
      x3728 = x3728 + 1;
    }
    x3728 = x3728 + 1;
    for (;;) {
      long x3835 = x3728;
      char x3836 = x3727[x3835];
      bool x3837 = x3836 != '|';
      bool x3842 = x3837;
      if (x3837) {
        long x3838 = x3728;
        char x3839 = x3727[x3838];
        bool x3840 = x3839 != '\n';
        x3842 = x3840;
      }
      bool x3843 = x3842;
      if (!x3843) break;
      x3728 = x3728 + 1;
    }
    x3728 = x3728 + 1;
    for (;;) {
      long x3855 = x3728;
      char x3856 = x3727[x3855];
      bool x3857 = x3856 != '.';
      bool x3862 = x3857;
      if (x3857) {
        long x3858 = x3728;
        char x3859 = x3727[x3858];
        bool x3860 = x3859 != '|';
        x3862 = x3860;
      }
      bool x3863 = x3862;
      bool x3868 = x3863;
      if (x3863) {
        long x3864 = x3728;
        char x3865 = x3727[x3864];
        bool x3866 = x3865 != '\n';
        x3868 = x3866;
      }
      bool x3869 = x3868;
      if (!x3869) break;
      x3728 = x3728 + 1;
    }
    long x3881 = x3728;
    char x3882 = x3727[x3881];
    bool x3883 = x3882 == '.';
    if (x3883) {
      x3728 = x3728 + 1;
      for (;;) {
        long x3885 = x3728;
        char x3886 = x3727[x3885];
        bool x3887 = x3886 != '|';
        bool x3892 = x3887;
        if (x3887) {
          long x3888 = x3728;
          char x3889 = x3727[x3888];
          bool x3890 = x3889 != '\n';
          x3892 = x3890;
        }
        bool x3893 = x3892;
        if (!x3893) break;
        x3728 = x3728 + 1;
      }
    } else {
    }
    x3728 = x3728 + 1;
    long x3917 = x3728;
    for (;;) {
      long x3918 = x3728;
      char x3919 = x3727[x3918];
      bool x3920 = x3919 != '|';
      bool x3925 = x3920;
      if (x3920) {
        long x3921 = x3728;
        char x3922 = x3727[x3921];
        bool x3923 = x3922 != '\n';
        x3925 = x3923;
      }
      bool x3926 = x3925;
      if (!x3926) break;
      x3728 = x3728 + 1;
    }
    x3728 = x3728 + 1;
    for (;;) {
      long x3936 = x3728;
      char x3937 = x3727[x3936];
      bool x3938 = x3937 != '|';
      bool x3943 = x3938;
      if (x3938) {
        long x3939 = x3728;
        char x3940 = x3727[x3939];
        bool x3941 = x3940 != '\n';
        x3943 = x3941;
      }
      bool x3944 = x3943;
      if (!x3944) break;
      x3728 = x3728 + 1;
    }
    x3728 = x3728 + 1;
    long x3954 = x3730;
    long x3955 = x3729;
    bool x3956 = x3954 == x3955;
    if (x3956) {
      long x3957 = x3955 * 4L;
      x3729 = x3957;
      printf("buffer.resize %d\n",x3957);
      int* x3960 = x3732;
      int* x3961 = (int*)realloc(x3960,x3957 * sizeof(int));
      x3732 = x3961;
      char** x3978 = x3744;
      char** x3979 = (char**)realloc(x3978,x3957 * sizeof(char*));
      x3744 = x3979;
    } else {
    }
    int* x3986 = x3732;
    x3986[x3954] = x3773;
    char** x3998 = x3744;
    char* x3934 = x3727+x3917;
    x3998[x3954] = x3934;
    x3730 = x3730 + 1;
  }
  long x2011 = DEFAULT_JOIN_HASH_SIZE;
  long x787 = DEFAULT_AGG_HASH_SIZE ;
  long x2034 = x2011 - 1L;
  long x802 = x787 - 1L;
  int x4005;
  for(x4005=0; x4005 < 5; x4005++) {
    bool x4006 = false;
    long x4007 = 0L;
    bool x4009 = false;
    long x4010 = 0L;
    bool x4012 = false;
    long x4013 = 0L;
    int* x4016 = (int*)malloc(x2011 * sizeof(int));
    int* x4017 = x4016;
    long x4032 = 0L;
    long* x4033 = (long*)malloc(x2011 * sizeof(long));
    long* x4034 = (long*)malloc(x2011 * sizeof(long));
    long x4035;
    for(x4035=0L; x4035 < x2011; x4035++) {
      x4033[x4035] = -1L;
    }
    int* x4057 = (int*)malloc(x2011 * sizeof(int));
    int* x4058 = x4057;
    long* x4065 = (long*)malloc(x2011 * sizeof(long));
    long* x4066 = x4065;
    int* x4071 = (int*)malloc(x2011 * sizeof(int));
    int* x4072 = x4071;
    long x4075 = 0L;
    long* x4076 = (long*)malloc(x2011 * sizeof(long));
    long* x4077 = (long*)malloc(x2011 * sizeof(long));
    long x4078;
    for(x4078=0L; x4078 < x2011; x4078++) {
      x4076[x4078] = -1L;
    }
    struct Anon532638341* x4085 = (struct Anon532638341*)malloc(x787 * sizeof(struct Anon532638341));
    struct Anon532638341* x4086 = x4085;
    long x4087 = 0L;
    long* x4088 = (long*)malloc(x787 * sizeof(long));
    long x4089;
    for(x4089=0L; x4089 < x787; x4089++) {
      struct Anon532638341* x4090 = x4086;
      struct Anon532638341 x4091 = x4090[x4089];
      struct Anon1465150758 x4092 = x4091.key;;
      struct Anon2052879266 x4093 = x4091.aggs;;
      struct Anon532638341 x4094;
      x4094.exists = false;
      x4094.key = x4092;
      x4094.aggs = x4093;
      x4090[x4089] = x4094;
    }
    int x4098 = 0;
    long x4100 = 0L;
    struct timeval x4485, x4486, x4487;
    gettimeofday(&x4485, NULL);
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x4102 = x4006;
      bool x4103 = !x4102;
      bool x4108 = x4103;
      if (x4103) {
        long x4104 = x4007;
        long x4105 = x3730;
        bool x4106 = x4104 < x4105;
        x4108 = x4106;
      }
      bool x4109 = x4108;
      if (!x4109) break;
      long x4111 = x4007;
      int* x4112 = x3732;
      int x4113 = x4112[x4111];
      char** x4124 = x3744;
      char* x4125 = x4124[x4111];
      x4007 = x4007 + 1;
      bool x4130 = strcmp(x4125,"HOUSEHOLD") == 0;;
      if (x4130) {
        long x4131 = x4032;
        int* x4132 = x4017;
        x4132[x4131] = x4113;
        x4032 = x4032 + 1L;
        long x4149 = x4113 & x2034;
        long x4150 = x4033[x4149];
        x4033[x4149] = x4131;
        x4034[x4131] = x4150;
      } else {
      }
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x4158 = x4009;
      bool x4159 = !x4158;
      bool x4164 = x4159;
      if (x4159) {
        long x4160 = x4010;
        long x4161 = x3376;
        bool x4162 = x4160 < x4161;
        x4164 = x4162;
      }
      bool x4165 = x4164;
      if (!x4165) break;
      long x4167 = x4010;
      int* x4168 = x3378;
      int x4169 = x4168[x4167];
      int* x4170 = x3380;
      int x4171 = x4170[x4167];
      long* x4176 = x3386;
      long x4177 = x4176[x4167];
      int* x4182 = x3392;
      int x4183 = x4182[x4167];
      x4010 = x4010 + 1;
      bool x4188 = x4177 < 19950304L;
      if (x4188) {
        long x4189 = x4171 & x2034;
        long x4190 = x4033[x4189];
        long x4191 = x4190;
        long x4255 = x4169 & x2034;
        for (;;) {
          long x4192 = x4191;
          bool x4193 = x4192 != -1;
          if (!x4193) break;
          long x4195 = x4191;
          int* x4196 = x4017;
          int x4197 = x4196[x4195];
          long x4213 = x4034[x4195];
          x4191 = x4213;
          bool x4215 = x4197 == x4171;
          if (x4215) {
            long x4219 = x4075;
            int* x4236 = x4058;
            x4236[x4219] = x4169;
            long* x4244 = x4066;
            x4244[x4219] = x4177;
            int* x4250 = x4072;
            x4250[x4219] = x4183;
            x4075 = x4075 + 1L;
            long x4256 = x4076[x4255];
            x4076[x4255] = x4219;
            x4077[x4219] = x4256;
          } else {
          }
        }
      } else {
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x4268 = x4012;
      bool x4269 = !x4268;
      bool x4274 = x4269;
      if (x4269) {
        long x4270 = x4013;
        long x4271 = x2599;
        bool x4272 = x4270 < x4271;
        x4274 = x4272;
      }
      bool x4275 = x4274;
      if (!x4275) break;
      long x4277 = x4013;
      int* x4278 = x2601;
      int x4279 = x4278[x4277];
      double* x4288 = x2611;
      double x4289 = x4288[x4277];
      double* x4290 = x2613;
      double x4291 = x4290[x4277];
      long* x4298 = x2621;
      long x4299 = x4298[x4277];
      x4013 = x4013 + 1;
      bool x4312 = x4299 > 19950304L;
      if (x4312) {
        long x4313 = x4279 & x2034;
        long x4314 = x4076[x4313];
        long x4315 = x4314;
        long x4362 = x4279 * 41L;
        double x4389 = 1.0 - x4291;
        double x4390 = x4289 * x4389;
        struct Anon2052879266 x4432;
        x4432._0 = x4390;
        for (;;) {
          long x4316 = x4315;
          bool x4317 = x4316 != -1;
          if (!x4317) break;
          long x4319 = x4315;
          int* x4336 = x4058;
          int x4337 = x4336[x4319];
          long* x4344 = x4066;
          long x4345 = x4344[x4319];
          int* x4350 = x4072;
          int x4351 = x4350[x4319];
          long x4355 = x4077[x4319];
          x4315 = x4355;
          bool x4357 = x4337 == x4279;
          if (x4357) {
            long x4363 = x4362 + x4345;
            long x4364 = x4363 * 41L;
            long x4365 = x4364 + x4351;
            long x4366 = x4365 & x802;
            long x4367 = x4366;
            struct Anon532638341* x4368 = x4086;
            struct Anon532638341 x4369 = x4368[x4366];
            struct Anon532638341 x4370 = x4369;
            bool x4371 = x4369.exists;;
            bool x4385 = x4371;
            if (x4371) {
              struct Anon532638341 x4372 = x4370;
              struct Anon1465150758 x4373 = x4372.key;;
              int x4374 = x4373.L_ORDERKEY;;
              bool x4375 = x4374 == x4279;
              bool x4380 = x4375;
              if (x4375) {
                long x4376 = x4373.O_ORDERDATE;;
                bool x4377 = x4376 == x4345;
                x4380 = x4377;
              }
              bool x4381 = x4380;
              bool x4382 = x4381;
              if (x4381) {
                int x4378 = x4373.O_SHIPPRIORITY;;
                bool x4379 = x4378 == x4351;
                x4382 = x4379;
              }
              bool x4383 = x4382;
              x4385 = x4383;
            }
            bool x4386 = x4385;
            if (x4386) {
              struct Anon2052879266 x4387 = x4369.aggs;;
              struct Anon1465150758 x4393 = x4369.key;;
              double x4388 = x4387._0;;
              double x4391 = x4388 + x4390;
              struct Anon2052879266 x4392;
              x4392._0 = x4391;
              struct Anon532638341 x4394;
              x4394.exists = true;
              x4394.key = x4393;
              x4394.aggs = x4392;
              x4368[x4366] = x4394;
            } else {
              struct Anon1465150758 x4361;
              x4361.L_ORDERKEY = x4279;
              x4361.O_ORDERDATE = x4345;
              x4361.O_SHIPPRIORITY = x4351;
              struct Anon532638341 x4433;
              x4433.exists = true;
              x4433.key = x4361;
              x4433.aggs = x4432;
              for (;;) {
                struct Anon532638341 x4397 = x4370;
                bool x4398 = x4397.exists;;
                bool x4442;
                if (x4398) {
                  struct Anon1465150758 x4399 = x4397.key;;
                  int x4400 = x4399.L_ORDERKEY;;
                  bool x4401 = x4400 == x4279;
                  bool x4406 = x4401;
                  if (x4401) {
                    long x4402 = x4399.O_ORDERDATE;;
                    bool x4403 = x4402 == x4345;
                    x4406 = x4403;
                  }
                  bool x4407 = x4406;
                  bool x4408 = x4407;
                  if (x4407) {
                    int x4404 = x4399.O_SHIPPRIORITY;;
                    bool x4405 = x4404 == x4351;
                    x4408 = x4405;
                  }
                  bool x4409 = x4408;
                  bool x4429;
                  if (x4409) {
                    struct Anon2052879266 x4410 = x4397.aggs;;
                    long x4414 = x4367;
                    struct Anon532638341* x4416 = x4086;
                    double x4411 = x4410._0;;
                    double x4412 = x4411 + x4390;
                    struct Anon2052879266 x4413;
                    x4413._0 = x4412;
                    struct Anon532638341 x4415;
                    x4415.exists = true;
                    x4415.key = x4399;
                    x4415.aggs = x4413;
                    x4416[x4414] = x4415;
                    x4429 = false;
                  } else {
                    long x4419 = x4367;
                    long x4420 = x4419 + 1L;
                    long x4421 = x4420 % x802;
                    x4367 = x4421;
                    struct Anon532638341* x4423 = x4086;
                    struct Anon532638341 x4424 = x4423[x4421];
                    x4370 = x4424;
                    x4429 = true;
                  }
                  x4442 = x4429;
                } else {
                  long x4431 = x4367;
                  struct Anon532638341* x4434 = x4086;
                  x4434[x4431] = x4433;
                  long x4436 = x4087;
                  x4088[x4436] = x4431;
                  x4087 = x4087 + 1L;
                  x4442 = false;
                }
                if (!x4442) break;
              }
            }
          } else {
          }
        }
      } else {
      }
    }
    long x4457 = x4087;
    long x4459;
    for(x4459=0L; x4459 < x4457; x4459++) {
      long x4460 = x4088[x4459];
      struct Anon532638341* x4461 = x4086;
      struct Anon532638341 x4462 = x4461[x4460];
      int x4463 = x4098;
      bool x4464 = x4463 < 10;
      bool x4465 = x4464 == false;
      if (x4465) {
      } else {
        struct Anon1465150758 x4468 = x4462.key;;
        struct Anon2052879266 x4470 = x4462.aggs;;
        int x4469 = x4468.L_ORDERKEY;;
        double x4471 = x4470._0;;
        long x4472 = x4468.O_ORDERDATE;;
        char* x4473 = (char*)malloc(9 * sizeof(char));;
        snprintf(x4473, 9, "%lu", x4472);
        int x4474 = x4468.O_SHIPPRIORITY;;
        printf("%d|%.4f|%.*s|%d\n",x4469,x4471,x4473,x4474);
        x4098 = x4098 + 1;
        x4100 = x4100 + 1L;
      }
    }
    long x4482 = x4100;
    printf("(%d rows)\n",x4482);
    gettimeofday(&x4486, NULL);
    timeval_subtract(&x4487, &x4486, &x4485);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x4487.tv_sec * 1000) + (x4487.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
