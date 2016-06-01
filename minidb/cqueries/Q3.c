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

struct Anon1495587458 {
int key;
struct Anon1023322325 wnd;
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

struct Anon1395358962 {
int PS_PARTKEY;
int PS_SUPPKEY;
int PS_AVAILQTY;
double PS_SUPPLYCOST;
char* PS_COMMENT;
};

/************************ FUNCTIONS **************************/
int x4808(struct Anon895445893* x4787, struct Anon895445893* x4788);
int x4808(struct Anon895445893* x4787, struct Anon895445893* x4788) {
  struct Anon895445893 x4789 = (*x4787);
  struct Anon895445893 x4790 = (*x4788);
  struct Anon2052879266 x4791 = x4789.aggs;;
  double x4792 = x4791._0;;
  struct Anon2052879266 x4793 = x4790.aggs;;
  double x4794 = x4793._0;;
  bool x4795 = x4792 < x4794;
  int x4806;
  if (x4795) {
    x4806 = 1;
  } else {
    bool x4796 = x4792 > x4794;
    int x4805;
    if (x4796) {
      x4805 = -1;
    } else {
      struct Anon1465150758 x4797 = x4789.key;;
      long x4798 = x4797.O_ORDERDATE;;
      struct Anon1465150758 x4799 = x4790.key;;
      long x4800 = x4799.O_ORDERDATE;;
      bool x4801 = x4798 < x4800;
      int x4804;
      if (x4801) {
        x4804 = -1;
      } else {
        bool x4802 = x4798 > x4800;
        int x4803;
        if (x4802) {
          x4803 = 1;
        } else {
          x4803 = 0;
        }
        x4804 = x4803;
      }
      x4805 = x4804;
    }
    x4806 = x4805;
  }
  return x4806;
}

/************************ MAIN BODY **************************/
int main(int x2837, char** x2838) {
  long x2839 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x2840 = x7;
  long x2841 = 0L;
  int* x2842 = (int*)malloc(x7 * sizeof(int));
  int* x2843 = x2842;
  double* x2852 = (double*)malloc(x7 * sizeof(double));
  double* x2853 = x2852;
  double* x2854 = (double*)malloc(x7 * sizeof(double));
  double* x2855 = x2854;
  long* x2862 = (long*)malloc(x7 * sizeof(long));
  long* x2863 = x2862;
  int x3 = open("XXXXXlineitem.tbl",0);
  long x4 = fsize(x3);
  char* x5 = mmap(0, x4, PROT_READ, MAP_FILE | MAP_SHARED, x3, 0);
  for (;;) {
    long x2874 = x2839;
    bool x2875 = x2874 < x4;
    if (!x2875) break;
    int x2878 = 0;
    for (;;) {
      long x2879 = x2839;
      char x2880 = x5[x2879];
      bool x2881 = x2880 != '|';
      bool x2886 = x2881;
      if (x2881) {
        long x2882 = x2839;
        char x2883 = x5[x2882];
        bool x2884 = x2883 != '\n';
        x2886 = x2884;
      }
      bool x2887 = x2886;
      if (!x2887) break;
      int x2889 = x2878;
      long x2891 = x2839;
      int x2890 = x2889 * 10;
      char x2892 = x5[x2891];
      char x2893 = x2892 - '0';
      int x2894 = x2890 + x2893;
      x2878 = x2894;
      x2839 = x2839 + 1;
    }
    x2839 = x2839 + 1;
    int x2900 = x2878;
    for (;;) {
      long x2903 = x2839;
      char x2904 = x5[x2903];
      bool x2905 = x2904 != '|';
      bool x2910 = x2905;
      if (x2905) {
        long x2906 = x2839;
        char x2907 = x5[x2906];
        bool x2908 = x2907 != '\n';
        x2910 = x2908;
      }
      bool x2911 = x2910;
      if (!x2911) break;
      x2839 = x2839 + 1;
    }
    x2839 = x2839 + 1;
    for (;;) {
      long x2927 = x2839;
      char x2928 = x5[x2927];
      bool x2929 = x2928 != '|';
      bool x2934 = x2929;
      if (x2929) {
        long x2930 = x2839;
        char x2931 = x5[x2930];
        bool x2932 = x2931 != '\n';
        x2934 = x2932;
      }
      bool x2935 = x2934;
      if (!x2935) break;
      x2839 = x2839 + 1;
    }
    x2839 = x2839 + 1;
    for (;;) {
      long x2951 = x2839;
      char x2952 = x5[x2951];
      bool x2953 = x2952 != '|';
      bool x2958 = x2953;
      if (x2953) {
        long x2954 = x2839;
        char x2955 = x5[x2954];
        bool x2956 = x2955 != '\n';
        x2958 = x2956;
      }
      bool x2959 = x2958;
      if (!x2959) break;
      x2839 = x2839 + 1;
    }
    x2839 = x2839 + 1;
    for (;;) {
      long x2976 = x2839;
      char x2977 = x5[x2976];
      bool x2978 = x2977 != '.';
      bool x2983 = x2978;
      if (x2978) {
        long x2979 = x2839;
        char x2980 = x5[x2979];
        bool x2981 = x2980 != '|';
        x2983 = x2981;
      }
      bool x2984 = x2983;
      bool x2989 = x2984;
      if (x2984) {
        long x2985 = x2839;
        char x2986 = x5[x2985];
        bool x2987 = x2986 != '\n';
        x2989 = x2987;
      }
      bool x2990 = x2989;
      if (!x2990) break;
      x2839 = x2839 + 1;
    }
    long x3002 = x2839;
    char x3003 = x5[x3002];
    bool x3004 = x3003 == '.';
    if (x3004) {
      x2839 = x2839 + 1;
      for (;;) {
        long x3006 = x2839;
        char x3007 = x5[x3006];
        bool x3008 = x3007 != '|';
        bool x3013 = x3008;
        if (x3008) {
          long x3009 = x2839;
          char x3010 = x5[x3009];
          bool x3011 = x3010 != '\n';
          x3013 = x3011;
        }
        bool x3014 = x3013;
        if (!x3014) break;
        x2839 = x2839 + 1;
      }
    } else {
    }
    x2839 = x2839 + 1;
    int x3039 = 0;
    int x3040 = 1;
    for (;;) {
      long x3041 = x2839;
      char x3042 = x5[x3041];
      bool x3043 = x3042 != '.';
      bool x3048 = x3043;
      if (x3043) {
        long x3044 = x2839;
        char x3045 = x5[x3044];
        bool x3046 = x3045 != '|';
        x3048 = x3046;
      }
      bool x3049 = x3048;
      bool x3054 = x3049;
      if (x3049) {
        long x3050 = x2839;
        char x3051 = x5[x3050];
        bool x3052 = x3051 != '\n';
        x3054 = x3052;
      }
      bool x3055 = x3054;
      if (!x3055) break;
      int x3057 = x3039;
      long x3059 = x2839;
      int x3058 = x3057 * 10;
      char x3060 = x5[x3059];
      char x3061 = x3060 - '0';
      int x3062 = x3058 + x3061;
      x3039 = x3062;
      x2839 = x2839 + 1;
    }
    long x3067 = x2839;
    char x3068 = x5[x3067];
    bool x3069 = x3068 == '.';
    if (x3069) {
      x2839 = x2839 + 1;
      for (;;) {
        long x3071 = x2839;
        char x3072 = x5[x3071];
        bool x3073 = x3072 != '|';
        bool x3078 = x3073;
        if (x3073) {
          long x3074 = x2839;
          char x3075 = x5[x3074];
          bool x3076 = x3075 != '\n';
          x3078 = x3076;
        }
        bool x3079 = x3078;
        if (!x3079) break;
        int x3081 = x3039;
        long x3083 = x2839;
        int x3082 = x3081 * 10;
        char x3084 = x5[x3083];
        char x3085 = x3084 - '0';
        int x3086 = x3082 + x3085;
        x3039 = x3086;
        int x3088 = x3040;
        int x3089 = x3088 * 10;
        x3040 = x3089;
        x2839 = x2839 + 1;
      }
    } else {
    }
    x2839 = x2839 + 1;
    int x3098 = x3039;
    int x3100 = x3040;
    int x3104 = 0;
    int x3105 = 1;
    for (;;) {
      long x3106 = x2839;
      char x3107 = x5[x3106];
      bool x3108 = x3107 != '.';
      bool x3113 = x3108;
      if (x3108) {
        long x3109 = x2839;
        char x3110 = x5[x3109];
        bool x3111 = x3110 != '|';
        x3113 = x3111;
      }
      bool x3114 = x3113;
      bool x3119 = x3114;
      if (x3114) {
        long x3115 = x2839;
        char x3116 = x5[x3115];
        bool x3117 = x3116 != '\n';
        x3119 = x3117;
      }
      bool x3120 = x3119;
      if (!x3120) break;
      int x3122 = x3104;
      long x3124 = x2839;
      int x3123 = x3122 * 10;
      char x3125 = x5[x3124];
      char x3126 = x3125 - '0';
      int x3127 = x3123 + x3126;
      x3104 = x3127;
      x2839 = x2839 + 1;
    }
    long x3132 = x2839;
    char x3133 = x5[x3132];
    bool x3134 = x3133 == '.';
    if (x3134) {
      x2839 = x2839 + 1;
      for (;;) {
        long x3136 = x2839;
        char x3137 = x5[x3136];
        bool x3138 = x3137 != '|';
        bool x3143 = x3138;
        if (x3138) {
          long x3139 = x2839;
          char x3140 = x5[x3139];
          bool x3141 = x3140 != '\n';
          x3143 = x3141;
        }
        bool x3144 = x3143;
        if (!x3144) break;
        int x3146 = x3104;
        long x3148 = x2839;
        int x3147 = x3146 * 10;
        char x3149 = x5[x3148];
        char x3150 = x3149 - '0';
        int x3151 = x3147 + x3150;
        x3104 = x3151;
        int x3153 = x3105;
        int x3154 = x3153 * 10;
        x3105 = x3154;
        x2839 = x2839 + 1;
      }
    } else {
    }
    x2839 = x2839 + 1;
    int x3163 = x3104;
    int x3165 = x3105;
    for (;;) {
      long x3171 = x2839;
      char x3172 = x5[x3171];
      bool x3173 = x3172 != '.';
      bool x3178 = x3173;
      if (x3173) {
        long x3174 = x2839;
        char x3175 = x5[x3174];
        bool x3176 = x3175 != '|';
        x3178 = x3176;
      }
      bool x3179 = x3178;
      bool x3184 = x3179;
      if (x3179) {
        long x3180 = x2839;
        char x3181 = x5[x3180];
        bool x3182 = x3181 != '\n';
        x3184 = x3182;
      }
      bool x3185 = x3184;
      if (!x3185) break;
      x2839 = x2839 + 1;
    }
    long x3197 = x2839;
    char x3198 = x5[x3197];
    bool x3199 = x3198 == '.';
    if (x3199) {
      x2839 = x2839 + 1;
      for (;;) {
        long x3201 = x2839;
        char x3202 = x5[x3201];
        bool x3203 = x3202 != '|';
        bool x3208 = x3203;
        if (x3203) {
          long x3204 = x2839;
          char x3205 = x5[x3204];
          bool x3206 = x3205 != '\n';
          x3208 = x3206;
        }
        bool x3209 = x3208;
        if (!x3209) break;
        x2839 = x2839 + 1;
      }
    } else {
    }
    x2839 = x2839 + 1;
    x2839 = x2839 + 2;
    x2839 = x2839 + 2;
    int x3240 = 0;
    for (;;) {
      long x3241 = x2839;
      char x3242 = x5[x3241];
      bool x3243 = x3242 != '-';
      bool x3248 = x3243;
      if (x3243) {
        long x3244 = x2839;
        char x3245 = x5[x3244];
        bool x3246 = x3245 != '\n';
        x3248 = x3246;
      }
      bool x3249 = x3248;
      if (!x3249) break;
      int x3251 = x3240;
      long x3253 = x2839;
      int x3252 = x3251 * 10;
      char x3254 = x5[x3253];
      char x3255 = x3254 - '0';
      int x3256 = x3252 + x3255;
      x3240 = x3256;
      x2839 = x2839 + 1;
    }
    x2839 = x2839 + 1;
    int x3262 = x3240;
    int x3264 = 0;
    for (;;) {
      long x3265 = x2839;
      char x3266 = x5[x3265];
      bool x3267 = x3266 != '-';
      bool x3272 = x3267;
      if (x3267) {
        long x3268 = x2839;
        char x3269 = x5[x3268];
        bool x3270 = x3269 != '\n';
        x3272 = x3270;
      }
      bool x3273 = x3272;
      if (!x3273) break;
      int x3275 = x3264;
      long x3277 = x2839;
      int x3276 = x3275 * 10;
      char x3278 = x5[x3277];
      char x3279 = x3278 - '0';
      int x3280 = x3276 + x3279;
      x3264 = x3280;
      x2839 = x2839 + 1;
    }
    x2839 = x2839 + 1;
    int x3286 = x3264;
    int x3288 = 0;
    for (;;) {
      long x3289 = x2839;
      char x3290 = x5[x3289];
      bool x3291 = x3290 != '|';
      bool x3296 = x3291;
      if (x3291) {
        long x3292 = x2839;
        char x3293 = x5[x3292];
        bool x3294 = x3293 != '\n';
        x3296 = x3294;
      }
      bool x3297 = x3296;
      if (!x3297) break;
      int x3299 = x3288;
      long x3301 = x2839;
      int x3300 = x3299 * 10;
      char x3302 = x5[x3301];
      char x3303 = x3302 - '0';
      int x3304 = x3300 + x3303;
      x3288 = x3304;
      x2839 = x2839 + 1;
    }
    x2839 = x2839 + 1;
    int x3310 = x3288;
    for (;;) {
      long x3317 = x2839;
      char x3318 = x5[x3317];
      bool x3319 = x3318 != '-';
      bool x3324 = x3319;
      if (x3319) {
        long x3320 = x2839;
        char x3321 = x5[x3320];
        bool x3322 = x3321 != '\n';
        x3324 = x3322;
      }
      bool x3325 = x3324;
      if (!x3325) break;
      x2839 = x2839 + 1;
    }
    x2839 = x2839 + 1;
    for (;;) {
      long x3341 = x2839;
      char x3342 = x5[x3341];
      bool x3343 = x3342 != '-';
      bool x3348 = x3343;
      if (x3343) {
        long x3344 = x2839;
        char x3345 = x5[x3344];
        bool x3346 = x3345 != '\n';
        x3348 = x3346;
      }
      bool x3349 = x3348;
      if (!x3349) break;
      x2839 = x2839 + 1;
    }
    x2839 = x2839 + 1;
    for (;;) {
      long x3365 = x2839;
      char x3366 = x5[x3365];
      bool x3367 = x3366 != '|';
      bool x3372 = x3367;
      if (x3367) {
        long x3368 = x2839;
        char x3369 = x5[x3368];
        bool x3370 = x3369 != '\n';
        x3372 = x3370;
      }
      bool x3373 = x3372;
      if (!x3373) break;
      x2839 = x2839 + 1;
    }
    x2839 = x2839 + 1;
    for (;;) {
      long x3393 = x2839;
      char x3394 = x5[x3393];
      bool x3395 = x3394 != '-';
      bool x3400 = x3395;
      if (x3395) {
        long x3396 = x2839;
        char x3397 = x5[x3396];
        bool x3398 = x3397 != '\n';
        x3400 = x3398;
      }
      bool x3401 = x3400;
      if (!x3401) break;
      x2839 = x2839 + 1;
    }
    x2839 = x2839 + 1;
    for (;;) {
      long x3417 = x2839;
      char x3418 = x5[x3417];
      bool x3419 = x3418 != '-';
      bool x3424 = x3419;
      if (x3419) {
        long x3420 = x2839;
        char x3421 = x5[x3420];
        bool x3422 = x3421 != '\n';
        x3424 = x3422;
      }
      bool x3425 = x3424;
      if (!x3425) break;
      x2839 = x2839 + 1;
    }
    x2839 = x2839 + 1;
    for (;;) {
      long x3441 = x2839;
      char x3442 = x5[x3441];
      bool x3443 = x3442 != '|';
      bool x3448 = x3443;
      if (x3443) {
        long x3444 = x2839;
        char x3445 = x5[x3444];
        bool x3446 = x3445 != '\n';
        x3448 = x3446;
      }
      bool x3449 = x3448;
      if (!x3449) break;
      x2839 = x2839 + 1;
    }
    x2839 = x2839 + 1;
    for (;;) {
      long x3468 = x2839;
      char x3469 = x5[x3468];
      bool x3470 = x3469 != '|';
      bool x3475 = x3470;
      if (x3470) {
        long x3471 = x2839;
        char x3472 = x5[x3471];
        bool x3473 = x3472 != '\n';
        x3475 = x3473;
      }
      bool x3476 = x3475;
      if (!x3476) break;
      x2839 = x2839 + 1;
    }
    x2839 = x2839 + 1;
    for (;;) {
      long x3486 = x2839;
      char x3487 = x5[x3486];
      bool x3488 = x3487 != '|';
      bool x3493 = x3488;
      if (x3488) {
        long x3489 = x2839;
        char x3490 = x5[x3489];
        bool x3491 = x3490 != '\n';
        x3493 = x3491;
      }
      bool x3494 = x3493;
      if (!x3494) break;
      x2839 = x2839 + 1;
    }
    x2839 = x2839 + 1;
    for (;;) {
      long x3504 = x2839;
      char x3505 = x5[x3504];
      bool x3506 = x3505 != '|';
      bool x3511 = x3506;
      if (x3506) {
        long x3507 = x2839;
        char x3508 = x5[x3507];
        bool x3509 = x3508 != '\n';
        x3511 = x3509;
      }
      bool x3512 = x3511;
      if (!x3512) break;
      x2839 = x2839 + 1;
    }
    x2839 = x2839 + 1;
    long x3522 = x2839;
    bool x3523 = x3522 > 0L;
    bool x3529 = x3523;
    if (x3523) {
      long x3524 = x2839;
      long x3525 = x3524 - 1L;
      char x3526 = x5[x3525];
      bool x3527 = x3526 != '\n';
      x3529 = x3527;
    }
    bool x3530 = x3529;
    if (x3530) {
      for (;;) {
        long x3531 = x2839;
        char x3532 = x5[x3531];
        bool x3533 = x3532 != '\n';
        if (!x3533) break;
        x2839 = x2839 + 1;
      }
    } else {
    }
    x2839 = x2839 + 1;
    long x3542 = x2841;
    long x3543 = x2840;
    bool x3544 = x3542 == x3543;
    if (x3544) {
      long x3545 = x3543 * 4L;
      x2840 = x3545;
      printf("buffer.resize %ld\n",x3545);
      int* x3548 = x2843;
      int* x3549 = (int*)realloc(x3548,x3545 * sizeof(int));
      x2843 = x3549;
      double* x3563 = x2853;
      double* x3564 = (double*)realloc(x3563,x3545 * sizeof(double));
      x2853 = x3564;
      double* x3566 = x2855;
      double* x3567 = (double*)realloc(x3566,x3545 * sizeof(double));
      x2855 = x3567;
      long* x3578 = x2863;
      long* x3579 = (long*)realloc(x3578,x3545 * sizeof(long));
      x2863 = x3579;
    } else {
    }
    int* x3598 = x2843;
    x3598[x3542] = x2900;
    double* x3608 = x2853;
    double x3099 = (double)x3098;
    double x3101 = (double)x3100;
    double x3102 = x3099 / x3101;
    x3608[x3542] = x3102;
    double* x3610 = x2855;
    double x3164 = (double)x3163;
    double x3166 = (double)x3165;
    double x3167 = x3164 / x3166;
    x3610[x3542] = x3167;
    long* x3618 = x2863;
    long x3311 = x3262 * 10000L;
    long x3312 = x3286 * 100L;
    long x3313 = x3311 + x3312;
    long x3314 = x3313 + x3310;
    x3618[x3542] = x3314;
    x2841 = x2841 + 1;
  }
  long x3636 = 0L;
  long x3637 = x7;
  long x3638 = 0L;
  int* x3639 = (int*)malloc(x7 * sizeof(int));
  int* x3640 = x3639;
  int* x3641 = (int*)malloc(x7 * sizeof(int));
  int* x3642 = x3641;
  long* x3647 = (long*)malloc(x7 * sizeof(long));
  long* x3648 = x3647;
  int* x3653 = (int*)malloc(x7 * sizeof(int));
  int* x3654 = x3653;
  int x3633 = open("XXXXXorders.tbl",0);
  long x3634 = fsize(x3633);
  char* x3635 = mmap(0, x3634, PROT_READ, MAP_FILE | MAP_SHARED, x3633, 0);
  for (;;) {
    long x3657 = x3636;
    bool x3658 = x3657 < x3634;
    if (!x3658) break;
    int x3661 = 0;
    for (;;) {
      long x3662 = x3636;
      char x3663 = x3635[x3662];
      bool x3664 = x3663 != '|';
      bool x3669 = x3664;
      if (x3664) {
        long x3665 = x3636;
        char x3666 = x3635[x3665];
        bool x3667 = x3666 != '\n';
        x3669 = x3667;
      }
      bool x3670 = x3669;
      if (!x3670) break;
      int x3672 = x3661;
      long x3674 = x3636;
      int x3673 = x3672 * 10;
      char x3675 = x3635[x3674];
      char x3676 = x3675 - '0';
      int x3677 = x3673 + x3676;
      x3661 = x3677;
      x3636 = x3636 + 1;
    }
    x3636 = x3636 + 1;
    int x3683 = x3661;
    int x3685 = 0;
    for (;;) {
      long x3686 = x3636;
      char x3687 = x3635[x3686];
      bool x3688 = x3687 != '|';
      bool x3693 = x3688;
      if (x3688) {
        long x3689 = x3636;
        char x3690 = x3635[x3689];
        bool x3691 = x3690 != '\n';
        x3693 = x3691;
      }
      bool x3694 = x3693;
      if (!x3694) break;
      int x3696 = x3685;
      long x3698 = x3636;
      int x3697 = x3696 * 10;
      char x3699 = x3635[x3698];
      char x3700 = x3699 - '0';
      int x3701 = x3697 + x3700;
      x3685 = x3701;
      x3636 = x3636 + 1;
    }
    x3636 = x3636 + 1;
    int x3707 = x3685;
    x3636 = x3636 + 2;
    for (;;) {
      long x3714 = x3636;
      char x3715 = x3635[x3714];
      bool x3716 = x3715 != '.';
      bool x3721 = x3716;
      if (x3716) {
        long x3717 = x3636;
        char x3718 = x3635[x3717];
        bool x3719 = x3718 != '|';
        x3721 = x3719;
      }
      bool x3722 = x3721;
      bool x3727 = x3722;
      if (x3722) {
        long x3723 = x3636;
        char x3724 = x3635[x3723];
        bool x3725 = x3724 != '\n';
        x3727 = x3725;
      }
      bool x3728 = x3727;
      if (!x3728) break;
      x3636 = x3636 + 1;
    }
    long x3740 = x3636;
    char x3741 = x3635[x3740];
    bool x3742 = x3741 == '.';
    if (x3742) {
      x3636 = x3636 + 1;
      for (;;) {
        long x3744 = x3636;
        char x3745 = x3635[x3744];
        bool x3746 = x3745 != '|';
        bool x3751 = x3746;
        if (x3746) {
          long x3747 = x3636;
          char x3748 = x3635[x3747];
          bool x3749 = x3748 != '\n';
          x3751 = x3749;
        }
        bool x3752 = x3751;
        if (!x3752) break;
        x3636 = x3636 + 1;
      }
    } else {
    }
    x3636 = x3636 + 1;
    int x3777 = 0;
    for (;;) {
      long x3778 = x3636;
      char x3779 = x3635[x3778];
      bool x3780 = x3779 != '-';
      bool x3785 = x3780;
      if (x3780) {
        long x3781 = x3636;
        char x3782 = x3635[x3781];
        bool x3783 = x3782 != '\n';
        x3785 = x3783;
      }
      bool x3786 = x3785;
      if (!x3786) break;
      int x3788 = x3777;
      long x3790 = x3636;
      int x3789 = x3788 * 10;
      char x3791 = x3635[x3790];
      char x3792 = x3791 - '0';
      int x3793 = x3789 + x3792;
      x3777 = x3793;
      x3636 = x3636 + 1;
    }
    x3636 = x3636 + 1;
    int x3799 = x3777;
    int x3801 = 0;
    for (;;) {
      long x3802 = x3636;
      char x3803 = x3635[x3802];
      bool x3804 = x3803 != '-';
      bool x3809 = x3804;
      if (x3804) {
        long x3805 = x3636;
        char x3806 = x3635[x3805];
        bool x3807 = x3806 != '\n';
        x3809 = x3807;
      }
      bool x3810 = x3809;
      if (!x3810) break;
      int x3812 = x3801;
      long x3814 = x3636;
      int x3813 = x3812 * 10;
      char x3815 = x3635[x3814];
      char x3816 = x3815 - '0';
      int x3817 = x3813 + x3816;
      x3801 = x3817;
      x3636 = x3636 + 1;
    }
    x3636 = x3636 + 1;
    int x3823 = x3801;
    int x3825 = 0;
    for (;;) {
      long x3826 = x3636;
      char x3827 = x3635[x3826];
      bool x3828 = x3827 != '|';
      bool x3833 = x3828;
      if (x3828) {
        long x3829 = x3636;
        char x3830 = x3635[x3829];
        bool x3831 = x3830 != '\n';
        x3833 = x3831;
      }
      bool x3834 = x3833;
      if (!x3834) break;
      int x3836 = x3825;
      long x3838 = x3636;
      int x3837 = x3836 * 10;
      char x3839 = x3635[x3838];
      char x3840 = x3839 - '0';
      int x3841 = x3837 + x3840;
      x3825 = x3841;
      x3636 = x3636 + 1;
    }
    x3636 = x3636 + 1;
    int x3847 = x3825;
    for (;;) {
      long x3853 = x3636;
      char x3854 = x3635[x3853];
      bool x3855 = x3854 != '|';
      bool x3860 = x3855;
      if (x3855) {
        long x3856 = x3636;
        char x3857 = x3635[x3856];
        bool x3858 = x3857 != '\n';
        x3860 = x3858;
      }
      bool x3861 = x3860;
      if (!x3861) break;
      x3636 = x3636 + 1;
    }
    x3636 = x3636 + 1;
    for (;;) {
      long x3871 = x3636;
      char x3872 = x3635[x3871];
      bool x3873 = x3872 != '|';
      bool x3878 = x3873;
      if (x3873) {
        long x3874 = x3636;
        char x3875 = x3635[x3874];
        bool x3876 = x3875 != '\n';
        x3878 = x3876;
      }
      bool x3879 = x3878;
      if (!x3879) break;
      x3636 = x3636 + 1;
    }
    x3636 = x3636 + 1;
    int x3889 = 0;
    for (;;) {
      long x3890 = x3636;
      char x3891 = x3635[x3890];
      bool x3892 = x3891 != '|';
      bool x3897 = x3892;
      if (x3892) {
        long x3893 = x3636;
        char x3894 = x3635[x3893];
        bool x3895 = x3894 != '\n';
        x3897 = x3895;
      }
      bool x3898 = x3897;
      if (!x3898) break;
      int x3900 = x3889;
      long x3902 = x3636;
      int x3901 = x3900 * 10;
      char x3903 = x3635[x3902];
      char x3904 = x3903 - '0';
      int x3905 = x3901 + x3904;
      x3889 = x3905;
      x3636 = x3636 + 1;
    }
    x3636 = x3636 + 1;
    int x3911 = x3889;
    for (;;) {
      long x3913 = x3636;
      char x3914 = x3635[x3913];
      bool x3915 = x3914 != '|';
      bool x3920 = x3915;
      if (x3915) {
        long x3916 = x3636;
        char x3917 = x3635[x3916];
        bool x3918 = x3917 != '\n';
        x3920 = x3918;
      }
      bool x3921 = x3920;
      if (!x3921) break;
      x3636 = x3636 + 1;
    }
    x3636 = x3636 + 1;
    long x3931 = x3636;
    bool x3932 = x3931 > 0L;
    bool x3938 = x3932;
    if (x3932) {
      long x3933 = x3636;
      long x3934 = x3933 - 1L;
      char x3935 = x3635[x3934];
      bool x3936 = x3935 != '\n';
      x3938 = x3936;
    }
    bool x3939 = x3938;
    if (x3939) {
      for (;;) {
        long x3940 = x3636;
        char x3941 = x3635[x3940];
        bool x3942 = x3941 != '\n';
        if (!x3942) break;
        x3636 = x3636 + 1;
      }
    } else {
    }
    x3636 = x3636 + 1;
    long x3951 = x3638;
    long x3952 = x3637;
    bool x3953 = x3951 == x3952;
    if (x3953) {
      long x3954 = x3952 * 4L;
      x3637 = x3954;
      printf("buffer.resize %ld\n",x3954);
      int* x3957 = x3640;
      int* x3958 = (int*)realloc(x3957,x3954 * sizeof(int));
      x3640 = x3958;
      int* x3960 = x3642;
      int* x3961 = (int*)realloc(x3960,x3954 * sizeof(int));
      x3642 = x3961;
      long* x3969 = x3648;
      long* x3970 = (long*)realloc(x3969,x3954 * sizeof(long));
      x3648 = x3970;
      int* x3978 = x3654;
      int* x3979 = (int*)realloc(x3978,x3954 * sizeof(int));
      x3654 = x3979;
    } else {
    }
    int* x3986 = x3640;
    x3986[x3951] = x3683;
    int* x3988 = x3642;
    x3988[x3951] = x3707;
    long* x3994 = x3648;
    long x3848 = x3799 * 10000L;
    long x3849 = x3823 * 100L;
    long x3850 = x3848 + x3849;
    long x3851 = x3850 + x3847;
    x3994[x3951] = x3851;
    int* x4000 = x3654;
    x4000[x3951] = x3911;
    x3638 = x3638 + 1;
  }
  long x4010 = 0L;
  long x4011 = x7;
  long x4012 = 0L;
  int* x4013 = (int*)malloc(x7 * sizeof(int));
  int* x4014 = x4013;
  char** x4025 = (char**)malloc(x7 * sizeof(char*));
  char** x4026 = x4025;
  int x4007 = open("XXXXXcustomer.tbl",0);
  long x4008 = fsize(x4007);
  char* x4009 = mmap(0, x4008, PROT_READ, MAP_FILE | MAP_SHARED, x4007, 0);
  for (;;) {
    long x4029 = x4010;
    bool x4030 = x4029 < x4008;
    if (!x4030) break;
    int x4033 = 0;
    for (;;) {
      long x4034 = x4010;
      char x4035 = x4009[x4034];
      bool x4036 = x4035 != '|';
      bool x4041 = x4036;
      if (x4036) {
        long x4037 = x4010;
        char x4038 = x4009[x4037];
        bool x4039 = x4038 != '\n';
        x4041 = x4039;
      }
      bool x4042 = x4041;
      if (!x4042) break;
      int x4044 = x4033;
      long x4046 = x4010;
      int x4045 = x4044 * 10;
      char x4047 = x4009[x4046];
      char x4048 = x4047 - '0';
      int x4049 = x4045 + x4048;
      x4033 = x4049;
      x4010 = x4010 + 1;
    }
    x4010 = x4010 + 1;
    int x4055 = x4033;
    for (;;) {
      long x4057 = x4010;
      char x4058 = x4009[x4057];
      bool x4059 = x4058 != '|';
      bool x4064 = x4059;
      if (x4059) {
        long x4060 = x4010;
        char x4061 = x4009[x4060];
        bool x4062 = x4061 != '\n';
        x4064 = x4062;
      }
      bool x4065 = x4064;
      if (!x4065) break;
      x4010 = x4010 + 1;
    }
    x4010 = x4010 + 1;
    for (;;) {
      long x4075 = x4010;
      char x4076 = x4009[x4075];
      bool x4077 = x4076 != '|';
      bool x4082 = x4077;
      if (x4077) {
        long x4078 = x4010;
        char x4079 = x4009[x4078];
        bool x4080 = x4079 != '\n';
        x4082 = x4080;
      }
      bool x4083 = x4082;
      if (!x4083) break;
      x4010 = x4010 + 1;
    }
    x4010 = x4010 + 1;
    for (;;) {
      long x4094 = x4010;
      char x4095 = x4009[x4094];
      bool x4096 = x4095 != '|';
      bool x4101 = x4096;
      if (x4096) {
        long x4097 = x4010;
        char x4098 = x4009[x4097];
        bool x4099 = x4098 != '\n';
        x4101 = x4099;
      }
      bool x4102 = x4101;
      if (!x4102) break;
      x4010 = x4010 + 1;
    }
    x4010 = x4010 + 1;
    for (;;) {
      long x4117 = x4010;
      char x4118 = x4009[x4117];
      bool x4119 = x4118 != '|';
      bool x4124 = x4119;
      if (x4119) {
        long x4120 = x4010;
        char x4121 = x4009[x4120];
        bool x4122 = x4121 != '\n';
        x4124 = x4122;
      }
      bool x4125 = x4124;
      if (!x4125) break;
      x4010 = x4010 + 1;
    }
    x4010 = x4010 + 1;
    for (;;) {
      long x4137 = x4010;
      char x4138 = x4009[x4137];
      bool x4139 = x4138 != '.';
      bool x4144 = x4139;
      if (x4139) {
        long x4140 = x4010;
        char x4141 = x4009[x4140];
        bool x4142 = x4141 != '|';
        x4144 = x4142;
      }
      bool x4145 = x4144;
      bool x4150 = x4145;
      if (x4145) {
        long x4146 = x4010;
        char x4147 = x4009[x4146];
        bool x4148 = x4147 != '\n';
        x4150 = x4148;
      }
      bool x4151 = x4150;
      if (!x4151) break;
      x4010 = x4010 + 1;
    }
    long x4163 = x4010;
    char x4164 = x4009[x4163];
    bool x4165 = x4164 == '.';
    if (x4165) {
      x4010 = x4010 + 1;
      for (;;) {
        long x4167 = x4010;
        char x4168 = x4009[x4167];
        bool x4169 = x4168 != '|';
        bool x4174 = x4169;
        if (x4169) {
          long x4170 = x4010;
          char x4171 = x4009[x4170];
          bool x4172 = x4171 != '\n';
          x4174 = x4172;
        }
        bool x4175 = x4174;
        if (!x4175) break;
        x4010 = x4010 + 1;
      }
    } else {
    }
    x4010 = x4010 + 1;
    long x4199 = x4010;
    for (;;) {
      long x4200 = x4010;
      char x4201 = x4009[x4200];
      bool x4202 = x4201 != '|';
      bool x4207 = x4202;
      if (x4202) {
        long x4203 = x4010;
        char x4204 = x4009[x4203];
        bool x4205 = x4204 != '\n';
        x4207 = x4205;
      }
      bool x4208 = x4207;
      if (!x4208) break;
      x4010 = x4010 + 1;
    }
    x4010 = x4010 + 1;
    for (;;) {
      long x4218 = x4010;
      char x4219 = x4009[x4218];
      bool x4220 = x4219 != '|';
      bool x4225 = x4220;
      if (x4220) {
        long x4221 = x4010;
        char x4222 = x4009[x4221];
        bool x4223 = x4222 != '\n';
        x4225 = x4223;
      }
      bool x4226 = x4225;
      if (!x4226) break;
      x4010 = x4010 + 1;
    }
    x4010 = x4010 + 1;
    long x4236 = x4010;
    bool x4237 = x4236 > 0L;
    bool x4243 = x4237;
    if (x4237) {
      long x4238 = x4010;
      long x4239 = x4238 - 1L;
      char x4240 = x4009[x4239];
      bool x4241 = x4240 != '\n';
      x4243 = x4241;
    }
    bool x4244 = x4243;
    if (x4244) {
      for (;;) {
        long x4245 = x4010;
        char x4246 = x4009[x4245];
        bool x4247 = x4246 != '\n';
        if (!x4247) break;
        x4010 = x4010 + 1;
      }
    } else {
    }
    x4010 = x4010 + 1;
    long x4256 = x4012;
    long x4257 = x4011;
    bool x4258 = x4256 == x4257;
    if (x4258) {
      long x4259 = x4257 * 4L;
      x4011 = x4259;
      printf("buffer.resize %ld\n",x4259);
      int* x4262 = x4014;
      int* x4263 = (int*)realloc(x4262,x4259 * sizeof(int));
      x4014 = x4263;
      char** x4280 = x4026;
      char** x4281 = (char**)realloc(x4280,x4259 * sizeof(char*));
      x4026 = x4281;
    } else {
    }
    int* x4288 = x4014;
    x4288[x4256] = x4055;
    char** x4300 = x4026;
    char* x4216 = x4009+x4199;
    x4300[x4256] = x4216;
    x4012 = x4012 + 1;
  }
  long x2189 = DEFAULT_JOIN_HASH_SIZE;
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  long x2212 = x2189 - 1L;
  long x823 = x808 - 1L;
  int x4307;
  for(x4307=0; x4307 < 5; x4307++) {
    bool x4308 = false;
    long x4309 = 0L;
    bool x4311 = false;
    long x4312 = 0L;
    bool x4314 = false;
    long x4315 = 0L;
    int* x4318 = (int*)malloc(x2189 * sizeof(int));
    int* x4319 = x4318;
    long x4334 = 0L;
    long* x4335 = (long*)malloc(x2189 * sizeof(long));
    long* x4336 = (long*)malloc(x2189 * sizeof(long));
    long x4337;
    for(x4337=0L; x4337 < x2189; x4337++) {
      x4335[x4337] = -1L;
    }
    int* x4359 = (int*)malloc(x2189 * sizeof(int));
    int* x4360 = x4359;
    long* x4367 = (long*)malloc(x2189 * sizeof(long));
    long* x4368 = x4367;
    int* x4373 = (int*)malloc(x2189 * sizeof(int));
    int* x4374 = x4373;
    long x4377 = 0L;
    long* x4378 = (long*)malloc(x2189 * sizeof(long));
    long* x4379 = (long*)malloc(x2189 * sizeof(long));
    long x4380;
    for(x4380=0L; x4380 < x2189; x4380++) {
      x4378[x4380] = -1L;
    }
    struct Anon895445893* x4387 = (struct Anon895445893*)malloc(x808 * sizeof(struct Anon895445893));
    struct Anon895445893* x4388 = x4387;
    long x4389 = 0L;
    long* x4390 = (long*)malloc(x808 * sizeof(long));
    long x4391;
    for(x4391=0L; x4391 < x808; x4391++) {
      struct Anon895445893* x4392 = x4388;
      struct Anon895445893 x4393 = x4392[x4391];
      struct Anon1465150758 x4394 = x4393.key;;
      struct Anon2052879266 x4395 = x4393.aggs;;
      struct Anon895445893 x4396;
      x4396.exists = false;
      x4396.key = x4394;
      x4396.aggs = x4395;
      x4392[x4391] = x4396;
    }
    long x4401 = 1024L;
    long x4402 = 0L;
    struct Anon895445893* x4403 = (struct Anon895445893*)malloc(1024L * sizeof(struct Anon895445893));
    struct Anon895445893* x4404 = x4403;
    int x4405 = 0;
    long x4407 = 0L;
    struct timeval x4836, x4837, x4838;
    gettimeofday(&x4836, NULL);
    printf("%s\n","begin scan CUSTOMER");
    for (;;) {
      bool x4409 = x4308;
      bool x4410 = !x4409;
      bool x4415 = x4410;
      if (x4410) {
        long x4411 = x4309;
        long x4412 = x4012;
        bool x4413 = x4411 < x4412;
        x4415 = x4413;
      }
      bool x4416 = x4415;
      if (!x4416) break;
      long x4418 = x4309;
      int* x4419 = x4014;
      int x4420 = x4419[x4418];
      char** x4431 = x4026;
      char* x4432 = x4431[x4418];
      x4309 = x4309 + 1;
      bool x4437 = tpch_strcmp(x4432,"BUILDING") == 0;;
      if (x4437) {
        long x4438 = x4334;
        int* x4439 = x4319;
        x4439[x4438] = x4420;
        x4334 = x4334 + 1L;
        long x4456 = x4420 & x2212;
        long x4457 = x4335[x4456];
        x4335[x4456] = x4438;
        x4336[x4438] = x4457;
      } else {
      }
    }
    printf("%s\n","begin scan ORDERS");
    for (;;) {
      bool x4465 = x4311;
      bool x4466 = !x4465;
      bool x4471 = x4466;
      if (x4466) {
        long x4467 = x4312;
        long x4468 = x3638;
        bool x4469 = x4467 < x4468;
        x4471 = x4469;
      }
      bool x4472 = x4471;
      if (!x4472) break;
      long x4474 = x4312;
      int* x4475 = x3640;
      int x4476 = x4475[x4474];
      int* x4477 = x3642;
      int x4478 = x4477[x4474];
      long* x4483 = x3648;
      long x4484 = x4483[x4474];
      int* x4489 = x3654;
      int x4490 = x4489[x4474];
      x4312 = x4312 + 1;
      bool x4495 = x4484 < 19950315L;
      if (x4495) {
        long x4496 = x4478 & x2212;
        long x4497 = x4335[x4496];
        long x4498 = x4497;
        long x4562 = x4476 & x2212;
        for (;;) {
          long x4499 = x4498;
          bool x4500 = x4499 != -1;
          if (!x4500) break;
          long x4502 = x4498;
          int* x4503 = x4319;
          int x4504 = x4503[x4502];
          long x4520 = x4336[x4502];
          x4498 = x4520;
          bool x4522 = x4504 == x4478;
          if (x4522) {
            long x4526 = x4377;
            int* x4543 = x4360;
            x4543[x4526] = x4476;
            long* x4551 = x4368;
            x4551[x4526] = x4484;
            int* x4557 = x4374;
            x4557[x4526] = x4490;
            x4377 = x4377 + 1L;
            long x4563 = x4378[x4562];
            x4378[x4562] = x4526;
            x4379[x4526] = x4563;
          } else {
          }
        }
      } else {
      }
    }
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x4575 = x4314;
      bool x4576 = !x4575;
      bool x4581 = x4576;
      if (x4576) {
        long x4577 = x4315;
        long x4578 = x2841;
        bool x4579 = x4577 < x4578;
        x4581 = x4579;
      }
      bool x4582 = x4581;
      if (!x4582) break;
      long x4584 = x4315;
      int* x4585 = x2843;
      int x4586 = x4585[x4584];
      double* x4595 = x2853;
      double x4596 = x4595[x4584];
      double* x4597 = x2855;
      double x4598 = x4597[x4584];
      long* x4605 = x2863;
      long x4606 = x4605[x4584];
      x4315 = x4315 + 1;
      bool x4619 = x4606 > 19950315L;
      if (x4619) {
        long x4620 = x4586 & x2212;
        long x4621 = x4378[x4620];
        long x4622 = x4621;
        long x4669 = x4586 * 41L;
        double x4696 = 1.0 - x4598;
        double x4697 = x4596 * x4696;
        struct Anon2052879266 x4739;
        x4739._0 = x4697;
        for (;;) {
          long x4623 = x4622;
          bool x4624 = x4623 != -1;
          if (!x4624) break;
          long x4626 = x4622;
          int* x4643 = x4360;
          int x4644 = x4643[x4626];
          long* x4651 = x4368;
          long x4652 = x4651[x4626];
          int* x4657 = x4374;
          int x4658 = x4657[x4626];
          long x4662 = x4379[x4626];
          x4622 = x4662;
          bool x4664 = x4644 == x4586;
          if (x4664) {
            long x4670 = x4669 + x4652;
            long x4671 = x4670 * 41L;
            long x4672 = x4671 + x4658;
            long x4673 = x4672 & x823;
            long x4674 = x4673;
            struct Anon895445893* x4675 = x4388;
            struct Anon895445893 x4676 = x4675[x4673];
            struct Anon895445893 x4677 = x4676;
            bool x4678 = x4676.exists;;
            bool x4692 = x4678;
            if (x4678) {
              struct Anon895445893 x4679 = x4677;
              struct Anon1465150758 x4680 = x4679.key;;
              int x4681 = x4680.L_ORDERKEY;;
              bool x4682 = x4681 == x4586;
              bool x4687 = x4682;
              if (x4682) {
                long x4683 = x4680.O_ORDERDATE;;
                bool x4684 = x4683 == x4652;
                x4687 = x4684;
              }
              bool x4688 = x4687;
              bool x4689 = x4688;
              if (x4688) {
                int x4685 = x4680.O_SHIPPRIORITY;;
                bool x4686 = x4685 == x4658;
                x4689 = x4686;
              }
              bool x4690 = x4689;
              x4692 = x4690;
            }
            bool x4693 = x4692;
            if (x4693) {
              struct Anon2052879266 x4694 = x4676.aggs;;
              struct Anon1465150758 x4700 = x4676.key;;
              double x4695 = x4694._0;;
              double x4698 = x4695 + x4697;
              struct Anon2052879266 x4699;
              x4699._0 = x4698;
              struct Anon895445893 x4701;
              x4701.exists = true;
              x4701.key = x4700;
              x4701.aggs = x4699;
              x4675[x4673] = x4701;
            } else {
              struct Anon1465150758 x4668;
              x4668.L_ORDERKEY = x4586;
              x4668.O_ORDERDATE = x4652;
              x4668.O_SHIPPRIORITY = x4658;
              struct Anon895445893 x4740;
              x4740.exists = true;
              x4740.key = x4668;
              x4740.aggs = x4739;
              for (;;) {
                struct Anon895445893 x4704 = x4677;
                bool x4705 = x4704.exists;;
                bool x4749;
                if (x4705) {
                  struct Anon1465150758 x4706 = x4704.key;;
                  int x4707 = x4706.L_ORDERKEY;;
                  bool x4708 = x4707 == x4586;
                  bool x4713 = x4708;
                  if (x4708) {
                    long x4709 = x4706.O_ORDERDATE;;
                    bool x4710 = x4709 == x4652;
                    x4713 = x4710;
                  }
                  bool x4714 = x4713;
                  bool x4715 = x4714;
                  if (x4714) {
                    int x4711 = x4706.O_SHIPPRIORITY;;
                    bool x4712 = x4711 == x4658;
                    x4715 = x4712;
                  }
                  bool x4716 = x4715;
                  bool x4736;
                  if (x4716) {
                    struct Anon2052879266 x4717 = x4704.aggs;;
                    long x4721 = x4674;
                    struct Anon895445893* x4723 = x4388;
                    double x4718 = x4717._0;;
                    double x4719 = x4718 + x4697;
                    struct Anon2052879266 x4720;
                    x4720._0 = x4719;
                    struct Anon895445893 x4722;
                    x4722.exists = true;
                    x4722.key = x4706;
                    x4722.aggs = x4720;
                    x4723[x4721] = x4722;
                    x4736 = false;
                  } else {
                    long x4726 = x4674;
                    long x4727 = x4726 + 1L;
                    long x4728 = x4727 & x823;
                    x4674 = x4728;
                    struct Anon895445893* x4730 = x4388;
                    struct Anon895445893 x4731 = x4730[x4728];
                    x4677 = x4731;
                    x4736 = true;
                  }
                  x4749 = x4736;
                } else {
                  long x4738 = x4674;
                  struct Anon895445893* x4741 = x4388;
                  x4741[x4738] = x4740;
                  long x4743 = x4389;
                  x4390[x4743] = x4738;
                  x4389 = x4389 + 1L;
                  x4749 = false;
                }
                if (!x4749) break;
              }
            }
          } else {
          }
        }
      } else {
      }
    }
    long x4764 = x4389;
    long x4766;
    for(x4766=0L; x4766 < x4764; x4766++) {
      long x4767 = x4390[x4766];
      struct Anon895445893* x4768 = x4388;
      struct Anon895445893 x4769 = x4768[x4767];
      long x4770 = x4402;
      long x4771 = x4401;
      bool x4772 = x4770 == x4771;
      if (x4772) {
        long x4773 = x4771 * 4L;
        x4401 = x4773;
        struct Anon895445893* x4775 = x4404;
        struct Anon895445893* x4776 = (struct Anon895445893 *)realloc(x4775,x4773* sizeof(struct Anon895445893));
        x4404 = x4776;
      } else {
      }
      struct Anon895445893* x4780 = x4404;
      x4780[x4770] = x4769;
      x4402 = x4402 + 1;
    }
    long x4785 = x4402;
    struct Anon895445893* x4786 = x4404;
    qsort((void *)x4786,x4785,sizeof(struct Anon895445893), (__compar_fn_t)x4808); // x4809
    long x4811;
    for(x4811=0L; x4811 < x4785; x4811++) {
      struct Anon895445893* x4812 = x4404;
      struct Anon895445893 x4813 = x4812[x4811];
      int x4814 = x4405;
      bool x4815 = x4814 < 10;
      bool x4816 = x4815 == false;
      if (x4816) {
      } else {
        struct Anon1465150758 x4819 = x4813.key;;
        struct Anon2052879266 x4821 = x4813.aggs;;
        int x4820 = x4819.L_ORDERKEY;;
        double x4822 = x4821._0;;
        long x4823 = x4819.O_ORDERDATE;;
        char* x4824 = (char*)malloc(9 * sizeof(char));;
        snprintf(x4824, 9, "%lu", x4823);
        int x4825 = x4819.O_SHIPPRIORITY;;
        printf("%d|%.4f|%s|%d\n",x4820,x4822,x4824,x4825);
        x4405 = x4405 + 1;
        x4407 = x4407 + 1L;
      }
    }
    long x4833 = x4407;
    printf("(%ld rows)\n",x4833);
    gettimeofday(&x4837, NULL);
    timeval_subtract(&x4838, &x4837, &x4836);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x4838.tv_sec * 1000) + (x4838.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
