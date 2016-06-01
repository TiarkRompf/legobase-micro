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

/************************ FUNCTIONS **************************/
int x1037(struct Anon631953537* x1018, struct Anon631953537* x1019);
int x1037(struct Anon631953537* x1018, struct Anon631953537* x1019) {
  struct Anon631953537 x1020 = (*x1018);
  struct Anon631953537 x1021 = (*x1019);
  struct Anon625264174 x1022 = x1020.key;;
  char x1023 = x1022.L_RETURNFLAG;;
  struct Anon625264174 x1024 = x1021.key;;
  char x1025 = x1024.L_RETURNFLAG;;
  int x1026 = x1023 - x1025;
  int x1027 = x1026;
  bool x1028 = x1026 == 0;
  if (x1028) {
    char x1029 = x1022.L_LINESTATUS;;
    char x1030 = x1024.L_LINESTATUS;;
    int x1031 = x1029 - x1030;
    x1027 = x1031;
  } else {
  }
  int x1035 = x1027;
  return x1035;
}

/************************ MAIN BODY **************************/
int main(int x1, char** x2) {
  long x6 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x8 = x7;
  long x9 = 0L;
  double* x18 = (double*)malloc(x7 * sizeof(double));
  double* x19 = x18;
  double* x20 = (double*)malloc(x7 * sizeof(double));
  double* x21 = x20;
  double* x22 = (double*)malloc(x7 * sizeof(double));
  double* x23 = x22;
  double* x24 = (double*)malloc(x7 * sizeof(double));
  double* x25 = x24;
  char* x26 = (char*)malloc(x7 * sizeof(char));
  char* x27 = x26;
  char* x28 = (char*)malloc(x7 * sizeof(char));
  char* x29 = x28;
  long* x30 = (long*)malloc(x7 * sizeof(long));
  long* x31 = x30;
  int x3 = open("XXXXXlineitem.tbl",0);
  long x4 = fsize(x3);
  char* x5 = mmap(0, x4, PROT_READ, MAP_FILE | MAP_SHARED, x3, 0);
  for (;;) {
    long x42 = x6;
    bool x43 = x42 < x4;
    if (!x43) break;
    for (;;) {
      long x47 = x6;
      char x48 = x5[x47];
      bool x49 = x48 != '|';
      bool x54 = x49;
      if (x49) {
        long x50 = x6;
        char x51 = x5[x50];
        bool x52 = x51 != '\n';
        x54 = x52;
      }
      bool x55 = x54;
      if (!x55) break;
      x6 = x6 + 1;
    }
    x6 = x6 + 1;
    for (;;) {
      long x71 = x6;
      char x72 = x5[x71];
      bool x73 = x72 != '|';
      bool x78 = x73;
      if (x73) {
        long x74 = x6;
        char x75 = x5[x74];
        bool x76 = x75 != '\n';
        x78 = x76;
      }
      bool x79 = x78;
      if (!x79) break;
      x6 = x6 + 1;
    }
    x6 = x6 + 1;
    for (;;) {
      long x95 = x6;
      char x96 = x5[x95];
      bool x97 = x96 != '|';
      bool x102 = x97;
      if (x97) {
        long x98 = x6;
        char x99 = x5[x98];
        bool x100 = x99 != '\n';
        x102 = x100;
      }
      bool x103 = x102;
      if (!x103) break;
      x6 = x6 + 1;
    }
    x6 = x6 + 1;
    for (;;) {
      long x119 = x6;
      char x120 = x5[x119];
      bool x121 = x120 != '|';
      bool x126 = x121;
      if (x121) {
        long x122 = x6;
        char x123 = x5[x122];
        bool x124 = x123 != '\n';
        x126 = x124;
      }
      bool x127 = x126;
      if (!x127) break;
      x6 = x6 + 1;
    }
    x6 = x6 + 1;
    int x142 = 0;
    int x143 = 1;
    for (;;) {
      long x144 = x6;
      char x145 = x5[x144];
      bool x146 = x145 != '.';
      bool x151 = x146;
      if (x146) {
        long x147 = x6;
        char x148 = x5[x147];
        bool x149 = x148 != '|';
        x151 = x149;
      }
      bool x152 = x151;
      bool x157 = x152;
      if (x152) {
        long x153 = x6;
        char x154 = x5[x153];
        bool x155 = x154 != '\n';
        x157 = x155;
      }
      bool x158 = x157;
      if (!x158) break;
      int x160 = x142;
      long x162 = x6;
      int x161 = x160 * 10;
      char x163 = x5[x162];
      char x164 = x163 - '0';
      int x165 = x161 + x164;
      x142 = x165;
      x6 = x6 + 1;
    }
    long x170 = x6;
    char x171 = x5[x170];
    bool x172 = x171 == '.';
    if (x172) {
      x6 = x6 + 1;
      for (;;) {
        long x174 = x6;
        char x175 = x5[x174];
        bool x176 = x175 != '|';
        bool x181 = x176;
        if (x176) {
          long x177 = x6;
          char x178 = x5[x177];
          bool x179 = x178 != '\n';
          x181 = x179;
        }
        bool x182 = x181;
        if (!x182) break;
        int x184 = x142;
        long x186 = x6;
        int x185 = x184 * 10;
        char x187 = x5[x186];
        char x188 = x187 - '0';
        int x189 = x185 + x188;
        x142 = x189;
        int x191 = x143;
        int x192 = x191 * 10;
        x143 = x192;
        x6 = x6 + 1;
      }
    } else {
    }
    x6 = x6 + 1;
    int x201 = x142;
    int x203 = x143;
    int x207 = 0;
    int x208 = 1;
    for (;;) {
      long x209 = x6;
      char x210 = x5[x209];
      bool x211 = x210 != '.';
      bool x216 = x211;
      if (x211) {
        long x212 = x6;
        char x213 = x5[x212];
        bool x214 = x213 != '|';
        x216 = x214;
      }
      bool x217 = x216;
      bool x222 = x217;
      if (x217) {
        long x218 = x6;
        char x219 = x5[x218];
        bool x220 = x219 != '\n';
        x222 = x220;
      }
      bool x223 = x222;
      if (!x223) break;
      int x225 = x207;
      long x227 = x6;
      int x226 = x225 * 10;
      char x228 = x5[x227];
      char x229 = x228 - '0';
      int x230 = x226 + x229;
      x207 = x230;
      x6 = x6 + 1;
    }
    long x235 = x6;
    char x236 = x5[x235];
    bool x237 = x236 == '.';
    if (x237) {
      x6 = x6 + 1;
      for (;;) {
        long x239 = x6;
        char x240 = x5[x239];
        bool x241 = x240 != '|';
        bool x246 = x241;
        if (x241) {
          long x242 = x6;
          char x243 = x5[x242];
          bool x244 = x243 != '\n';
          x246 = x244;
        }
        bool x247 = x246;
        if (!x247) break;
        int x249 = x207;
        long x251 = x6;
        int x250 = x249 * 10;
        char x252 = x5[x251];
        char x253 = x252 - '0';
        int x254 = x250 + x253;
        x207 = x254;
        int x256 = x208;
        int x257 = x256 * 10;
        x208 = x257;
        x6 = x6 + 1;
      }
    } else {
    }
    x6 = x6 + 1;
    int x266 = x207;
    int x268 = x208;
    int x272 = 0;
    int x273 = 1;
    for (;;) {
      long x274 = x6;
      char x275 = x5[x274];
      bool x276 = x275 != '.';
      bool x281 = x276;
      if (x276) {
        long x277 = x6;
        char x278 = x5[x277];
        bool x279 = x278 != '|';
        x281 = x279;
      }
      bool x282 = x281;
      bool x287 = x282;
      if (x282) {
        long x283 = x6;
        char x284 = x5[x283];
        bool x285 = x284 != '\n';
        x287 = x285;
      }
      bool x288 = x287;
      if (!x288) break;
      int x290 = x272;
      long x292 = x6;
      int x291 = x290 * 10;
      char x293 = x5[x292];
      char x294 = x293 - '0';
      int x295 = x291 + x294;
      x272 = x295;
      x6 = x6 + 1;
    }
    long x300 = x6;
    char x301 = x5[x300];
    bool x302 = x301 == '.';
    if (x302) {
      x6 = x6 + 1;
      for (;;) {
        long x304 = x6;
        char x305 = x5[x304];
        bool x306 = x305 != '|';
        bool x311 = x306;
        if (x306) {
          long x307 = x6;
          char x308 = x5[x307];
          bool x309 = x308 != '\n';
          x311 = x309;
        }
        bool x312 = x311;
        if (!x312) break;
        int x314 = x272;
        long x316 = x6;
        int x315 = x314 * 10;
        char x317 = x5[x316];
        char x318 = x317 - '0';
        int x319 = x315 + x318;
        x272 = x319;
        int x321 = x273;
        int x322 = x321 * 10;
        x273 = x322;
        x6 = x6 + 1;
      }
    } else {
    }
    x6 = x6 + 1;
    int x331 = x272;
    int x333 = x273;
    int x337 = 0;
    int x338 = 1;
    for (;;) {
      long x339 = x6;
      char x340 = x5[x339];
      bool x341 = x340 != '.';
      bool x346 = x341;
      if (x341) {
        long x342 = x6;
        char x343 = x5[x342];
        bool x344 = x343 != '|';
        x346 = x344;
      }
      bool x347 = x346;
      bool x352 = x347;
      if (x347) {
        long x348 = x6;
        char x349 = x5[x348];
        bool x350 = x349 != '\n';
        x352 = x350;
      }
      bool x353 = x352;
      if (!x353) break;
      int x355 = x337;
      long x357 = x6;
      int x356 = x355 * 10;
      char x358 = x5[x357];
      char x359 = x358 - '0';
      int x360 = x356 + x359;
      x337 = x360;
      x6 = x6 + 1;
    }
    long x365 = x6;
    char x366 = x5[x365];
    bool x367 = x366 == '.';
    if (x367) {
      x6 = x6 + 1;
      for (;;) {
        long x369 = x6;
        char x370 = x5[x369];
        bool x371 = x370 != '|';
        bool x376 = x371;
        if (x371) {
          long x372 = x6;
          char x373 = x5[x372];
          bool x374 = x373 != '\n';
          x376 = x374;
        }
        bool x377 = x376;
        if (!x377) break;
        int x379 = x337;
        long x381 = x6;
        int x380 = x379 * 10;
        char x382 = x5[x381];
        char x383 = x382 - '0';
        int x384 = x380 + x383;
        x337 = x384;
        int x386 = x338;
        int x387 = x386 * 10;
        x338 = x387;
        x6 = x6 + 1;
      }
    } else {
    }
    x6 = x6 + 1;
    int x396 = x337;
    int x398 = x338;
    long x401 = x6;
    x6 = x6 + 2;
    long x404 = x6;
    x6 = x6 + 2;
    int x408 = 0;
    for (;;) {
      long x409 = x6;
      char x410 = x5[x409];
      bool x411 = x410 != '-';
      bool x416 = x411;
      if (x411) {
        long x412 = x6;
        char x413 = x5[x412];
        bool x414 = x413 != '\n';
        x416 = x414;
      }
      bool x417 = x416;
      if (!x417) break;
      int x419 = x408;
      long x421 = x6;
      int x420 = x419 * 10;
      char x422 = x5[x421];
      char x423 = x422 - '0';
      int x424 = x420 + x423;
      x408 = x424;
      x6 = x6 + 1;
    }
    x6 = x6 + 1;
    int x430 = x408;
    int x432 = 0;
    for (;;) {
      long x433 = x6;
      char x434 = x5[x433];
      bool x435 = x434 != '-';
      bool x440 = x435;
      if (x435) {
        long x436 = x6;
        char x437 = x5[x436];
        bool x438 = x437 != '\n';
        x440 = x438;
      }
      bool x441 = x440;
      if (!x441) break;
      int x443 = x432;
      long x445 = x6;
      int x444 = x443 * 10;
      char x446 = x5[x445];
      char x447 = x446 - '0';
      int x448 = x444 + x447;
      x432 = x448;
      x6 = x6 + 1;
    }
    x6 = x6 + 1;
    int x454 = x432;
    int x456 = 0;
    for (;;) {
      long x457 = x6;
      char x458 = x5[x457];
      bool x459 = x458 != '|';
      bool x464 = x459;
      if (x459) {
        long x460 = x6;
        char x461 = x5[x460];
        bool x462 = x461 != '\n';
        x464 = x462;
      }
      bool x465 = x464;
      if (!x465) break;
      int x467 = x456;
      long x469 = x6;
      int x468 = x467 * 10;
      char x470 = x5[x469];
      char x471 = x470 - '0';
      int x472 = x468 + x471;
      x456 = x472;
      x6 = x6 + 1;
    }
    x6 = x6 + 1;
    int x478 = x456;
    for (;;) {
      long x485 = x6;
      char x486 = x5[x485];
      bool x487 = x486 != '-';
      bool x492 = x487;
      if (x487) {
        long x488 = x6;
        char x489 = x5[x488];
        bool x490 = x489 != '\n';
        x492 = x490;
      }
      bool x493 = x492;
      if (!x493) break;
      x6 = x6 + 1;
    }
    x6 = x6 + 1;
    for (;;) {
      long x509 = x6;
      char x510 = x5[x509];
      bool x511 = x510 != '-';
      bool x516 = x511;
      if (x511) {
        long x512 = x6;
        char x513 = x5[x512];
        bool x514 = x513 != '\n';
        x516 = x514;
      }
      bool x517 = x516;
      if (!x517) break;
      x6 = x6 + 1;
    }
    x6 = x6 + 1;
    for (;;) {
      long x533 = x6;
      char x534 = x5[x533];
      bool x535 = x534 != '|';
      bool x540 = x535;
      if (x535) {
        long x536 = x6;
        char x537 = x5[x536];
        bool x538 = x537 != '\n';
        x540 = x538;
      }
      bool x541 = x540;
      if (!x541) break;
      x6 = x6 + 1;
    }
    x6 = x6 + 1;
    for (;;) {
      long x561 = x6;
      char x562 = x5[x561];
      bool x563 = x562 != '-';
      bool x568 = x563;
      if (x563) {
        long x564 = x6;
        char x565 = x5[x564];
        bool x566 = x565 != '\n';
        x568 = x566;
      }
      bool x569 = x568;
      if (!x569) break;
      x6 = x6 + 1;
    }
    x6 = x6 + 1;
    for (;;) {
      long x585 = x6;
      char x586 = x5[x585];
      bool x587 = x586 != '-';
      bool x592 = x587;
      if (x587) {
        long x588 = x6;
        char x589 = x5[x588];
        bool x590 = x589 != '\n';
        x592 = x590;
      }
      bool x593 = x592;
      if (!x593) break;
      x6 = x6 + 1;
    }
    x6 = x6 + 1;
    for (;;) {
      long x609 = x6;
      char x610 = x5[x609];
      bool x611 = x610 != '|';
      bool x616 = x611;
      if (x611) {
        long x612 = x6;
        char x613 = x5[x612];
        bool x614 = x613 != '\n';
        x616 = x614;
      }
      bool x617 = x616;
      if (!x617) break;
      x6 = x6 + 1;
    }
    x6 = x6 + 1;
    for (;;) {
      long x636 = x6;
      char x637 = x5[x636];
      bool x638 = x637 != '|';
      bool x643 = x638;
      if (x638) {
        long x639 = x6;
        char x640 = x5[x639];
        bool x641 = x640 != '\n';
        x643 = x641;
      }
      bool x644 = x643;
      if (!x644) break;
      x6 = x6 + 1;
    }
    x6 = x6 + 1;
    for (;;) {
      long x654 = x6;
      char x655 = x5[x654];
      bool x656 = x655 != '|';
      bool x661 = x656;
      if (x656) {
        long x657 = x6;
        char x658 = x5[x657];
        bool x659 = x658 != '\n';
        x661 = x659;
      }
      bool x662 = x661;
      if (!x662) break;
      x6 = x6 + 1;
    }
    x6 = x6 + 1;
    for (;;) {
      long x672 = x6;
      char x673 = x5[x672];
      bool x674 = x673 != '|';
      bool x679 = x674;
      if (x674) {
        long x675 = x6;
        char x676 = x5[x675];
        bool x677 = x676 != '\n';
        x679 = x677;
      }
      bool x680 = x679;
      if (!x680) break;
      x6 = x6 + 1;
    }
    x6 = x6 + 1;
    long x690 = x6;
    bool x691 = x690 > 0L;
    bool x697 = x691;
    if (x691) {
      long x692 = x6;
      long x693 = x692 - 1L;
      char x694 = x5[x693];
      bool x695 = x694 != '\n';
      x697 = x695;
    }
    bool x698 = x697;
    if (x698) {
      for (;;) {
        long x699 = x6;
        char x700 = x5[x699];
        bool x701 = x700 != '\n';
        if (!x701) break;
        x6 = x6 + 1;
      }
    } else {
    }
    x6 = x6 + 1;
    long x710 = x9;
    long x711 = x8;
    bool x712 = x710 == x711;
    if (x712) {
      long x713 = x711 * 4L;
      x8 = x713;
      printf("buffer.resize %ld\n",x713);
      double* x728 = x19;
      double* x729 = (double*)realloc(x728,x713 * sizeof(double));
      x19 = x729;
      double* x731 = x21;
      double* x732 = (double*)realloc(x731,x713 * sizeof(double));
      x21 = x732;
      double* x734 = x23;
      double* x735 = (double*)realloc(x734,x713 * sizeof(double));
      x23 = x735;
      double* x737 = x25;
      double* x738 = (double*)realloc(x737,x713 * sizeof(double));
      x25 = x738;
      char* x740 = x27;
      char* x741 = (char*)realloc(x740,x713 * sizeof(char));
      x27 = x741;
      char* x743 = x29;
      char* x744 = (char*)realloc(x743,x713 * sizeof(char));
      x29 = x744;
      long* x746 = x31;
      long* x747 = (long*)realloc(x746,x713 * sizeof(long));
      x31 = x747;
    } else {
    }
    double* x774 = x19;
    double x202 = (double)x201;
    double x204 = (double)x203;
    double x205 = x202 / x204;
    x774[x710] = x205;
    double* x776 = x21;
    double x267 = (double)x266;
    double x269 = (double)x268;
    double x270 = x267 / x269;
    x776[x710] = x270;
    double* x778 = x23;
    double x332 = (double)x331;
    double x334 = (double)x333;
    double x335 = x332 / x334;
    x778[x710] = x335;
    double* x780 = x25;
    double x397 = (double)x396;
    double x399 = (double)x398;
    double x400 = x397 / x399;
    x780[x710] = x400;
    char* x782 = x27;
    char x402 = x5[x401];
    x782[x710] = x402;
    char* x784 = x29;
    char x405 = x5[x404];
    x784[x710] = x405;
    long* x786 = x31;
    long x479 = x430 * 10000L;
    long x480 = x454 * 100L;
    long x481 = x479 + x480;
    long x482 = x481 + x478;
    x786[x710] = x482;
    x9 = x9 + 1;
  }
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  long x823 = x808 - 1L;
  bool x1043 = true == false;
  int x802;
  for(x802=0; x802 < 5; x802++) {
    bool x803 = false;
    long x804 = 0L;
    struct Anon600063274* x809 = (struct Anon600063274*)malloc(x808 * sizeof(struct Anon600063274));
    struct Anon600063274* x810 = x809;
    long x811 = 0L;
    long* x812 = (long*)malloc(x808 * sizeof(long));
    long x814;
    for(x814=0L; x814 < x808; x814++) {
      struct Anon600063274* x815 = x810;
      struct Anon600063274 x816 = x815[x814];
      struct Anon625264174 x817 = x816.key;;
      struct Anon567626277 x818 = x816.aggs;;
      struct Anon600063274 x819;
      x819.exists = false;
      x819.key = x817;
      x819.aggs = x818;
      x815[x814] = x819;
    }
    long x826 = 1024L;
    long x827 = 0L;
    struct Anon631953537* x828 = (struct Anon631953537*)malloc(1024L * sizeof(struct Anon631953537));
    struct Anon631953537* x829 = x828;
    long x831 = 0L;
    struct timeval x1067, x1068, x1069;
    gettimeofday(&x1067, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x833 = x803;
      bool x834 = !x833;
      bool x839 = x834;
      if (x834) {
        long x835 = x804;
        long x836 = x9;
        bool x837 = x835 < x836;
        x839 = x837;
      }
      bool x840 = x839;
      if (!x840) break;
      long x842 = x804;
      double* x851 = x19;
      double x852 = x851[x842];
      double* x853 = x21;
      double x854 = x853[x842];
      double* x855 = x23;
      double x856 = x855[x842];
      double* x857 = x25;
      double x858 = x857[x842];
      char* x859 = x27;
      char x860 = x859[x842];
      char* x861 = x29;
      char x862 = x861[x842];
      long* x863 = x31;
      long x864 = x863[x842];
      x804 = x804 + 1;
      bool x877 = x864 <= 19980811L;
      if (x877) {
        long x879 = x862 * 41L;
        long x880 = x879 + x860;
        long x881 = x880 & x823;
        long x882 = x881;
        struct Anon600063274* x883 = x810;
        struct Anon600063274 x884 = x883[x881];
        struct Anon600063274 x885 = x884;
        bool x886 = x884.exists;;
        bool x896 = x886;
        if (x886) {
          struct Anon600063274 x887 = x885;
          struct Anon625264174 x888 = x887.key;;
          char x889 = x888.L_RETURNFLAG;;
          bool x890 = x889 == x860;
          bool x893 = x890;
          if (x890) {
            char x891 = x888.L_LINESTATUS;;
            bool x892 = x891 == x862;
            x893 = x892;
          }
          bool x894 = x893;
          x896 = x894;
        }
        bool x897 = x896;
        if (x897) {
          struct Anon567626277 x898 = x884.aggs;;
          struct Anon625264174 x916 = x884.key;;
          double x899 = x898._0;;
          double x900 = x856 + x899;
          double x901 = x898._1;;
          double x902 = x852 + x901;
          double x903 = x898._2;;
          double x904 = x854 + x903;
          double x905 = 1.0 - x856;
          double x906 = x854 * x905;
          double x907 = x898._3;;
          double x908 = x906 + x907;
          double x909 = 1.0 + x858;
          double x910 = x906 * x909;
          double x911 = x898._4;;
          double x912 = x910 + x911;
          double x913 = x898._5;;
          double x914 = x913 + 1.0;
          struct Anon567626277 x915;
          x915._0 = x900;
          x915._1 = x902;
          x915._2 = x904;
          x915._3 = x908;
          x915._4 = x912;
          x915._5 = x914;
          struct Anon600063274 x917;
          x917.exists = true;
          x917.key = x916;
          x917.aggs = x915;
          x883[x881] = x917;
        } else {
          double x905 = 1.0 - x856;
          double x906 = x854 * x905;
          double x909 = 1.0 + x858;
          double x910 = x906 * x909;
          struct Anon625264174 x878;
          x878.L_RETURNFLAG = x860;
          x878.L_LINESTATUS = x862;
          struct Anon567626277 x961;
          x961._0 = x856;
          x961._1 = x852;
          x961._2 = x854;
          x961._3 = x906;
          x961._4 = x910;
          x961._5 = 1.0;
          struct Anon600063274 x962;
          x962.exists = true;
          x962.key = x878;
          x962.aggs = x961;
          for (;;) {
            struct Anon600063274 x920 = x885;
            bool x921 = x920.exists;;
            bool x971;
            if (x921) {
              struct Anon625264174 x922 = x920.key;;
              char x923 = x922.L_RETURNFLAG;;
              bool x924 = x923 == x860;
              bool x927 = x924;
              if (x924) {
                char x925 = x922.L_LINESTATUS;;
                bool x926 = x925 == x862;
                x927 = x926;
              }
              bool x928 = x927;
              bool x958;
              if (x928) {
                struct Anon567626277 x929 = x920.aggs;;
                long x943 = x882;
                struct Anon600063274* x945 = x810;
                double x930 = x929._0;;
                double x931 = x856 + x930;
                double x932 = x929._1;;
                double x933 = x852 + x932;
                double x934 = x929._2;;
                double x935 = x854 + x934;
                double x936 = x929._3;;
                double x937 = x906 + x936;
                double x938 = x929._4;;
                double x939 = x910 + x938;
                double x940 = x929._5;;
                double x941 = x940 + 1.0;
                struct Anon567626277 x942;
                x942._0 = x931;
                x942._1 = x933;
                x942._2 = x935;
                x942._3 = x937;
                x942._4 = x939;
                x942._5 = x941;
                struct Anon600063274 x944;
                x944.exists = true;
                x944.key = x922;
                x944.aggs = x942;
                x945[x943] = x944;
                x958 = false;
              } else {
                long x948 = x882;
                long x949 = x948 + 1L;
                long x950 = x949 & x823;
                x882 = x950;
                struct Anon600063274* x952 = x810;
                struct Anon600063274 x953 = x952[x950];
                x885 = x953;
                x958 = true;
              }
              x971 = x958;
            } else {
              long x960 = x882;
              struct Anon600063274* x963 = x810;
              x963[x960] = x962;
              long x965 = x811;
              x812[x965] = x960;
              x811 = x811 + 1L;
              x971 = false;
            }
            if (!x971) break;
          }
        }
      } else {
      }
    }
    long x982 = x811;
    long x984;
    for(x984=0L; x984 < x982; x984++) {
      long x985 = x812[x984];
      struct Anon600063274* x986 = x810;
      struct Anon600063274 x987 = x986[x985];
      struct Anon625264174 x988 = x987.key;;
      struct Anon567626277 x989 = x987.aggs;;
      long x1001 = x827;
      long x1002 = x826;
      bool x1003 = x1001 == x1002;
      if (x1003) {
        long x1004 = x1002 * 4L;
        x826 = x1004;
        struct Anon631953537* x1006 = x829;
        struct Anon631953537* x1007 = (struct Anon631953537 *)realloc(x1006,x1004* sizeof(struct Anon631953537));
        x829 = x1007;
      } else {
      }
      struct Anon631953537* x1011 = x829;
      double x990 = x989._0;;
      double x991 = x989._1;;
      double x992 = x989._2;;
      double x993 = x989._3;;
      double x994 = x989._4;;
      double x995 = x989._5;;
      double x996 = x991 / x995;
      double x997 = x992 / x995;
      double x998 = x990 / x995;
      struct Anon1296044246 x999;
      x999._0 = x990;
      x999._1 = x991;
      x999._2 = x992;
      x999._3 = x993;
      x999._4 = x994;
      x999._5 = x995;
      x999._6 = x996;
      x999._7 = x997;
      x999._8 = x998;
      struct Anon631953537 x1000;
      x1000.key = x988;
      x1000.aggs = x999;
      x1011[x1001] = x1000;
      x827 = x827 + 1;
    }
    long x1016 = x827;
    struct Anon631953537* x1017 = x829;
    qsort((void *)x1017,x1016,sizeof(struct Anon631953537), (__compar_fn_t)x1037); // x1038
    long x1040;
    for(x1040=0L; x1040 < x1016; x1040++) {
      struct Anon631953537* x1041 = x829;
      struct Anon631953537 x1042 = x1041[x1040];
      if (x1043) {
      } else {
        struct Anon625264174 x1046 = x1042.key;;
        struct Anon1296044246 x1049 = x1042.aggs;;
        char x1047 = x1046.L_RETURNFLAG;;
        char x1048 = x1046.L_LINESTATUS;;
        double x1050 = x1049._1;;
        double x1051 = x1049._2;;
        double x1052 = x1049._3;;
        double x1053 = x1049._4;;
        double x1054 = x1049._6;;
        double x1055 = x1049._7;;
        double x1056 = x1049._8;;
        double x1057 = x1049._5;;
        printf("%c|%c|%.2f|%.2f|%.2f|%.2f|%.2f|%.2f|%.6f|%.0f\n",x1047,x1048,x1050,x1051,x1052,x1053,x1054,x1055,x1056,x1057);
        x831 = x831 + 1L;
      }
    }
    long x1064 = x831;
    printf("(%ld rows)\n",x1064);
    gettimeofday(&x1068, NULL);
    timeval_subtract(&x1069, &x1068, &x1067);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x1069.tv_sec * 1000) + (x1069.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
