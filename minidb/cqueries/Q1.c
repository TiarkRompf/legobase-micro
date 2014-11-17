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

struct Anon1931420570 {
bool exists;
struct Anon625264174 key;
struct Anon567626277 aggs;
};

struct Anon1519494783 {
struct Anon625264174 key;
struct Anon1296044246 aggs;
};

/************************ FUNCTIONS **************************/

/************************ MAIN BODY **************************/
int main(int x0, char** x1) {
  long x5 = 0L;
  long x6 = DEFAULT_INPUT_SIZE;
  long x7 = x6;
  long x8 = 0L;
  double* x17 = (double*)malloc(x6 * sizeof(double));
  double* x18 = x17;
  double* x19 = (double*)malloc(x6 * sizeof(double));
  double* x20 = x19;
  double* x21 = (double*)malloc(x6 * sizeof(double));
  double* x22 = x21;
  double* x23 = (double*)malloc(x6 * sizeof(double));
  double* x24 = x23;
  char* x25 = (char*)malloc(x6 * sizeof(char));
  char* x26 = x25;
  char* x27 = (char*)malloc(x6 * sizeof(char));
  char* x28 = x27;
  long* x29 = (long*)malloc(x6 * sizeof(long));
  long* x30 = x29;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  long x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    long x41 = x5;
    bool x42 = x41 < x3;
    if (!x42) break;
    for (;;) {
      long x46 = x5;
      char x47 = x4[x46];
      bool x48 = x47 != '|';
      bool x53 = x48;
      if (x48) {
        long x49 = x5;
        char x50 = x4[x49];
        bool x51 = x50 != '\n';
        x53 = x51;
      }
      bool x54 = x53;
      if (!x54) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      long x70 = x5;
      char x71 = x4[x70];
      bool x72 = x71 != '|';
      bool x77 = x72;
      if (x72) {
        long x73 = x5;
        char x74 = x4[x73];
        bool x75 = x74 != '\n';
        x77 = x75;
      }
      bool x78 = x77;
      if (!x78) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      long x94 = x5;
      char x95 = x4[x94];
      bool x96 = x95 != '|';
      bool x101 = x96;
      if (x96) {
        long x97 = x5;
        char x98 = x4[x97];
        bool x99 = x98 != '\n';
        x101 = x99;
      }
      bool x102 = x101;
      if (!x102) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      long x118 = x5;
      char x119 = x4[x118];
      bool x120 = x119 != '|';
      bool x125 = x120;
      if (x120) {
        long x121 = x5;
        char x122 = x4[x121];
        bool x123 = x122 != '\n';
        x125 = x123;
      }
      bool x126 = x125;
      if (!x126) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    int x141 = 0;
    int x142 = 1;
    for (;;) {
      long x143 = x5;
      char x144 = x4[x143];
      bool x145 = x144 != '.';
      bool x150 = x145;
      if (x145) {
        long x146 = x5;
        char x147 = x4[x146];
        bool x148 = x147 != '|';
        x150 = x148;
      }
      bool x151 = x150;
      bool x156 = x151;
      if (x151) {
        long x152 = x5;
        char x153 = x4[x152];
        bool x154 = x153 != '\n';
        x156 = x154;
      }
      bool x157 = x156;
      if (!x157) break;
      int x159 = x141;
      long x161 = x5;
      int x160 = x159 * 10;
      char x162 = x4[x161];
      char x163 = x162 - '0';
      int x164 = x160 + x163;
      x141 = x164;
      x5 = x5 + 1;
    }
    long x169 = x5;
    char x170 = x4[x169];
    bool x171 = x170 == '.';
    if (x171) {
      x5 = x5 + 1;
      for (;;) {
        long x173 = x5;
        char x174 = x4[x173];
        bool x175 = x174 != '|';
        bool x180 = x175;
        if (x175) {
          long x176 = x5;
          char x177 = x4[x176];
          bool x178 = x177 != '\n';
          x180 = x178;
        }
        bool x181 = x180;
        if (!x181) break;
        int x183 = x141;
        long x185 = x5;
        int x184 = x183 * 10;
        char x186 = x4[x185];
        char x187 = x186 - '0';
        int x188 = x184 + x187;
        x141 = x188;
        int x190 = x142;
        int x191 = x190 * 10;
        x142 = x191;
        x5 = x5 + 1;
      }
    } else {
    }
    x5 = x5 + 1;
    int x200 = x141;
    int x202 = x142;
    int x206 = 0;
    int x207 = 1;
    for (;;) {
      long x208 = x5;
      char x209 = x4[x208];
      bool x210 = x209 != '.';
      bool x215 = x210;
      if (x210) {
        long x211 = x5;
        char x212 = x4[x211];
        bool x213 = x212 != '|';
        x215 = x213;
      }
      bool x216 = x215;
      bool x221 = x216;
      if (x216) {
        long x217 = x5;
        char x218 = x4[x217];
        bool x219 = x218 != '\n';
        x221 = x219;
      }
      bool x222 = x221;
      if (!x222) break;
      int x224 = x206;
      long x226 = x5;
      int x225 = x224 * 10;
      char x227 = x4[x226];
      char x228 = x227 - '0';
      int x229 = x225 + x228;
      x206 = x229;
      x5 = x5 + 1;
    }
    long x234 = x5;
    char x235 = x4[x234];
    bool x236 = x235 == '.';
    if (x236) {
      x5 = x5 + 1;
      for (;;) {
        long x238 = x5;
        char x239 = x4[x238];
        bool x240 = x239 != '|';
        bool x245 = x240;
        if (x240) {
          long x241 = x5;
          char x242 = x4[x241];
          bool x243 = x242 != '\n';
          x245 = x243;
        }
        bool x246 = x245;
        if (!x246) break;
        int x248 = x206;
        long x250 = x5;
        int x249 = x248 * 10;
        char x251 = x4[x250];
        char x252 = x251 - '0';
        int x253 = x249 + x252;
        x206 = x253;
        int x255 = x207;
        int x256 = x255 * 10;
        x207 = x256;
        x5 = x5 + 1;
      }
    } else {
    }
    x5 = x5 + 1;
    int x265 = x206;
    int x267 = x207;
    int x271 = 0;
    int x272 = 1;
    for (;;) {
      long x273 = x5;
      char x274 = x4[x273];
      bool x275 = x274 != '.';
      bool x280 = x275;
      if (x275) {
        long x276 = x5;
        char x277 = x4[x276];
        bool x278 = x277 != '|';
        x280 = x278;
      }
      bool x281 = x280;
      bool x286 = x281;
      if (x281) {
        long x282 = x5;
        char x283 = x4[x282];
        bool x284 = x283 != '\n';
        x286 = x284;
      }
      bool x287 = x286;
      if (!x287) break;
      int x289 = x271;
      long x291 = x5;
      int x290 = x289 * 10;
      char x292 = x4[x291];
      char x293 = x292 - '0';
      int x294 = x290 + x293;
      x271 = x294;
      x5 = x5 + 1;
    }
    long x299 = x5;
    char x300 = x4[x299];
    bool x301 = x300 == '.';
    if (x301) {
      x5 = x5 + 1;
      for (;;) {
        long x303 = x5;
        char x304 = x4[x303];
        bool x305 = x304 != '|';
        bool x310 = x305;
        if (x305) {
          long x306 = x5;
          char x307 = x4[x306];
          bool x308 = x307 != '\n';
          x310 = x308;
        }
        bool x311 = x310;
        if (!x311) break;
        int x313 = x271;
        long x315 = x5;
        int x314 = x313 * 10;
        char x316 = x4[x315];
        char x317 = x316 - '0';
        int x318 = x314 + x317;
        x271 = x318;
        int x320 = x272;
        int x321 = x320 * 10;
        x272 = x321;
        x5 = x5 + 1;
      }
    } else {
    }
    x5 = x5 + 1;
    int x330 = x271;
    int x332 = x272;
    int x336 = 0;
    int x337 = 1;
    for (;;) {
      long x338 = x5;
      char x339 = x4[x338];
      bool x340 = x339 != '.';
      bool x345 = x340;
      if (x340) {
        long x341 = x5;
        char x342 = x4[x341];
        bool x343 = x342 != '|';
        x345 = x343;
      }
      bool x346 = x345;
      bool x351 = x346;
      if (x346) {
        long x347 = x5;
        char x348 = x4[x347];
        bool x349 = x348 != '\n';
        x351 = x349;
      }
      bool x352 = x351;
      if (!x352) break;
      int x354 = x336;
      long x356 = x5;
      int x355 = x354 * 10;
      char x357 = x4[x356];
      char x358 = x357 - '0';
      int x359 = x355 + x358;
      x336 = x359;
      x5 = x5 + 1;
    }
    long x364 = x5;
    char x365 = x4[x364];
    bool x366 = x365 == '.';
    if (x366) {
      x5 = x5 + 1;
      for (;;) {
        long x368 = x5;
        char x369 = x4[x368];
        bool x370 = x369 != '|';
        bool x375 = x370;
        if (x370) {
          long x371 = x5;
          char x372 = x4[x371];
          bool x373 = x372 != '\n';
          x375 = x373;
        }
        bool x376 = x375;
        if (!x376) break;
        int x378 = x336;
        long x380 = x5;
        int x379 = x378 * 10;
        char x381 = x4[x380];
        char x382 = x381 - '0';
        int x383 = x379 + x382;
        x336 = x383;
        int x385 = x337;
        int x386 = x385 * 10;
        x337 = x386;
        x5 = x5 + 1;
      }
    } else {
    }
    x5 = x5 + 1;
    int x395 = x336;
    int x397 = x337;
    long x400 = x5;
    x5 = x5 + 2;
    long x403 = x5;
    x5 = x5 + 2;
    int x407 = 0;
    for (;;) {
      long x408 = x5;
      char x409 = x4[x408];
      bool x410 = x409 != '-';
      bool x415 = x410;
      if (x410) {
        long x411 = x5;
        char x412 = x4[x411];
        bool x413 = x412 != '\n';
        x415 = x413;
      }
      bool x416 = x415;
      if (!x416) break;
      int x418 = x407;
      long x420 = x5;
      int x419 = x418 * 10;
      char x421 = x4[x420];
      char x422 = x421 - '0';
      int x423 = x419 + x422;
      x407 = x423;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    int x429 = x407;
    int x431 = 0;
    for (;;) {
      long x432 = x5;
      char x433 = x4[x432];
      bool x434 = x433 != '-';
      bool x439 = x434;
      if (x434) {
        long x435 = x5;
        char x436 = x4[x435];
        bool x437 = x436 != '\n';
        x439 = x437;
      }
      bool x440 = x439;
      if (!x440) break;
      int x442 = x431;
      long x444 = x5;
      int x443 = x442 * 10;
      char x445 = x4[x444];
      char x446 = x445 - '0';
      int x447 = x443 + x446;
      x431 = x447;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    int x453 = x431;
    int x455 = 0;
    for (;;) {
      long x456 = x5;
      char x457 = x4[x456];
      bool x458 = x457 != '|';
      bool x463 = x458;
      if (x458) {
        long x459 = x5;
        char x460 = x4[x459];
        bool x461 = x460 != '\n';
        x463 = x461;
      }
      bool x464 = x463;
      if (!x464) break;
      int x466 = x455;
      long x468 = x5;
      int x467 = x466 * 10;
      char x469 = x4[x468];
      char x470 = x469 - '0';
      int x471 = x467 + x470;
      x455 = x471;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    int x477 = x455;
    for (;;) {
      long x484 = x5;
      char x485 = x4[x484];
      bool x486 = x485 != '-';
      bool x491 = x486;
      if (x486) {
        long x487 = x5;
        char x488 = x4[x487];
        bool x489 = x488 != '\n';
        x491 = x489;
      }
      bool x492 = x491;
      if (!x492) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      long x508 = x5;
      char x509 = x4[x508];
      bool x510 = x509 != '-';
      bool x515 = x510;
      if (x510) {
        long x511 = x5;
        char x512 = x4[x511];
        bool x513 = x512 != '\n';
        x515 = x513;
      }
      bool x516 = x515;
      if (!x516) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      long x532 = x5;
      char x533 = x4[x532];
      bool x534 = x533 != '|';
      bool x539 = x534;
      if (x534) {
        long x535 = x5;
        char x536 = x4[x535];
        bool x537 = x536 != '\n';
        x539 = x537;
      }
      bool x540 = x539;
      if (!x540) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      long x560 = x5;
      char x561 = x4[x560];
      bool x562 = x561 != '-';
      bool x567 = x562;
      if (x562) {
        long x563 = x5;
        char x564 = x4[x563];
        bool x565 = x564 != '\n';
        x567 = x565;
      }
      bool x568 = x567;
      if (!x568) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      long x584 = x5;
      char x585 = x4[x584];
      bool x586 = x585 != '-';
      bool x591 = x586;
      if (x586) {
        long x587 = x5;
        char x588 = x4[x587];
        bool x589 = x588 != '\n';
        x591 = x589;
      }
      bool x592 = x591;
      if (!x592) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      long x608 = x5;
      char x609 = x4[x608];
      bool x610 = x609 != '|';
      bool x615 = x610;
      if (x610) {
        long x611 = x5;
        char x612 = x4[x611];
        bool x613 = x612 != '\n';
        x615 = x613;
      }
      bool x616 = x615;
      if (!x616) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      long x635 = x5;
      char x636 = x4[x635];
      bool x637 = x636 != '|';
      bool x642 = x637;
      if (x637) {
        long x638 = x5;
        char x639 = x4[x638];
        bool x640 = x639 != '\n';
        x642 = x640;
      }
      bool x643 = x642;
      if (!x643) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      long x653 = x5;
      char x654 = x4[x653];
      bool x655 = x654 != '|';
      bool x660 = x655;
      if (x655) {
        long x656 = x5;
        char x657 = x4[x656];
        bool x658 = x657 != '\n';
        x660 = x658;
      }
      bool x661 = x660;
      if (!x661) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      long x671 = x5;
      char x672 = x4[x671];
      bool x673 = x672 != '|';
      bool x678 = x673;
      if (x673) {
        long x674 = x5;
        char x675 = x4[x674];
        bool x676 = x675 != '\n';
        x678 = x676;
      }
      bool x679 = x678;
      if (!x679) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    long x689 = x8;
    long x690 = x7;
    bool x691 = x689 == x690;
    if (x691) {
      long x692 = x690 * 4L;
      x7 = x692;
      printf("buffer.resize %d\n",x692);
      double* x707 = x18;
      double* x708 = (double*)realloc(x707,x692 * sizeof(double));
      x18 = x708;
      double* x710 = x20;
      double* x711 = (double*)realloc(x710,x692 * sizeof(double));
      x20 = x711;
      double* x713 = x22;
      double* x714 = (double*)realloc(x713,x692 * sizeof(double));
      x22 = x714;
      double* x716 = x24;
      double* x717 = (double*)realloc(x716,x692 * sizeof(double));
      x24 = x717;
      char* x719 = x26;
      char* x720 = (char*)realloc(x719,x692 * sizeof(char));
      x26 = x720;
      char* x722 = x28;
      char* x723 = (char*)realloc(x722,x692 * sizeof(char));
      x28 = x723;
      long* x725 = x30;
      long* x726 = (long*)realloc(x725,x692 * sizeof(long));
      x30 = x726;
    } else {
    }
    double* x753 = x18;
    double x201 = (double)x200;
    double x203 = (double)x202;
    double x204 = x201 / x203;
    x753[x689] = x204;
    double* x755 = x20;
    double x266 = (double)x265;
    double x268 = (double)x267;
    double x269 = x266 / x268;
    x755[x689] = x269;
    double* x757 = x22;
    double x331 = (double)x330;
    double x333 = (double)x332;
    double x334 = x331 / x333;
    x757[x689] = x334;
    double* x759 = x24;
    double x396 = (double)x395;
    double x398 = (double)x397;
    double x399 = x396 / x398;
    x759[x689] = x399;
    char* x761 = x26;
    char x401 = x4[x400];
    x761[x689] = x401;
    char* x763 = x28;
    char x404 = x4[x403];
    x763[x689] = x404;
    long* x765 = x30;
    long x478 = x429 * 10000L;
    long x479 = x453 * 100L;
    long x480 = x478 + x479;
    long x481 = x480 + x477;
    x765[x689] = x481;
    x8 = x8 + 1;
  }
  long x787 = DEFAULT_AGG_HASH_SIZE ;
  long x802 = x787 - 1L;
  bool x975 = true == false;
  int x781;
  for(x781=0; x781 < 5; x781++) {
    bool x782 = false;
    long x783 = 0L;
    struct Anon1931420570* x788 = (struct Anon1931420570*)malloc(x787 * sizeof(struct Anon1931420570));
    struct Anon1931420570* x789 = x788;
    long x790 = 0L;
    long* x791 = (long*)malloc(x787 * sizeof(long));
    long x793;
    for(x793=0L; x793 < x787; x793++) {
      struct Anon1931420570* x794 = x789;
      struct Anon1931420570 x795 = x794[x793];
      struct Anon625264174 x796 = x795.key;;
      struct Anon567626277 x797 = x795.aggs;;
      struct Anon1931420570 x798;
      x798.exists = false;
      x798.key = x796;
      x798.aggs = x797;
      x794[x793] = x798;
    }
    long x805 = 0L;
    struct timeval x989, x990, x991;
    gettimeofday(&x989, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x807 = x782;
      bool x808 = !x807;
      bool x813 = x808;
      if (x808) {
        long x809 = x783;
        long x810 = x8;
        bool x811 = x809 < x810;
        x813 = x811;
      }
      bool x814 = x813;
      if (!x814) break;
      long x816 = x783;
      double* x825 = x18;
      double x826 = x825[x816];
      double* x827 = x20;
      double x828 = x827[x816];
      double* x829 = x22;
      double x830 = x829[x816];
      double* x831 = x24;
      double x832 = x831[x816];
      char* x833 = x26;
      char x834 = x833[x816];
      char* x835 = x28;
      char x836 = x835[x816];
      long* x837 = x30;
      long x838 = x837[x816];
      x783 = x783 + 1;
      bool x851 = x838 <= 19980811L;
      if (x851) {
        long x853 = x836 * 41L;
        long x854 = x853 + x834;
        long x855 = x854 & x802;
        long x856 = x855;
        struct Anon1931420570* x857 = x789;
        struct Anon1931420570 x858 = x857[x855];
        struct Anon1931420570 x859 = x858;
        bool x860 = x858.exists;;
        bool x870 = x860;
        if (x860) {
          struct Anon1931420570 x861 = x859;
          struct Anon625264174 x862 = x861.key;;
          char x863 = x862.L_RETURNFLAG;;
          bool x864 = x863 == x834;
          bool x867 = x864;
          if (x864) {
            char x865 = x862.L_LINESTATUS;;
            bool x866 = x865 == x836;
            x867 = x866;
          }
          bool x868 = x867;
          x870 = x868;
        }
        bool x871 = x870;
        if (x871) {
          struct Anon567626277 x872 = x858.aggs;;
          struct Anon625264174 x890 = x858.key;;
          double x873 = x872._0;;
          double x874 = x830 + x873;
          double x875 = x872._1;;
          double x876 = x826 + x875;
          double x877 = x872._2;;
          double x878 = x828 + x877;
          double x879 = 1.0 - x830;
          double x880 = x828 * x879;
          double x881 = x872._3;;
          double x882 = x880 + x881;
          double x883 = 1.0 + x832;
          double x884 = x880 * x883;
          double x885 = x872._4;;
          double x886 = x884 + x885;
          double x887 = x872._5;;
          double x888 = x887 + 1.0;
          struct Anon567626277 x889;
          x889._0 = x874;
          x889._1 = x876;
          x889._2 = x878;
          x889._3 = x882;
          x889._4 = x886;
          x889._5 = x888;
          struct Anon1931420570 x891;
          x891.exists = true;
          x891.key = x890;
          x891.aggs = x889;
          x857[x855] = x891;
        } else {
          double x879 = 1.0 - x830;
          double x880 = x828 * x879;
          double x883 = 1.0 + x832;
          double x884 = x880 * x883;
          struct Anon625264174 x852;
          x852.L_RETURNFLAG = x834;
          x852.L_LINESTATUS = x836;
          struct Anon567626277 x935;
          x935._0 = x830;
          x935._1 = x826;
          x935._2 = x828;
          x935._3 = x880;
          x935._4 = x884;
          x935._5 = 1.0;
          struct Anon1931420570 x936;
          x936.exists = true;
          x936.key = x852;
          x936.aggs = x935;
          for (;;) {
            struct Anon1931420570 x894 = x859;
            bool x895 = x894.exists;;
            bool x945;
            if (x895) {
              struct Anon625264174 x896 = x894.key;;
              char x897 = x896.L_RETURNFLAG;;
              bool x898 = x897 == x834;
              bool x901 = x898;
              if (x898) {
                char x899 = x896.L_LINESTATUS;;
                bool x900 = x899 == x836;
                x901 = x900;
              }
              bool x902 = x901;
              bool x932;
              if (x902) {
                struct Anon567626277 x903 = x894.aggs;;
                long x917 = x856;
                struct Anon1931420570* x919 = x789;
                double x904 = x903._0;;
                double x905 = x830 + x904;
                double x906 = x903._1;;
                double x907 = x826 + x906;
                double x908 = x903._2;;
                double x909 = x828 + x908;
                double x910 = x903._3;;
                double x911 = x880 + x910;
                double x912 = x903._4;;
                double x913 = x884 + x912;
                double x914 = x903._5;;
                double x915 = x914 + 1.0;
                struct Anon567626277 x916;
                x916._0 = x905;
                x916._1 = x907;
                x916._2 = x909;
                x916._3 = x911;
                x916._4 = x913;
                x916._5 = x915;
                struct Anon1931420570 x918;
                x918.exists = true;
                x918.key = x896;
                x918.aggs = x916;
                x919[x917] = x918;
                x932 = false;
              } else {
                long x922 = x856;
                long x923 = x922 + 1L;
                long x924 = x923 % x802;
                x856 = x924;
                struct Anon1931420570* x926 = x789;
                struct Anon1931420570 x927 = x926[x924];
                x859 = x927;
                x932 = true;
              }
              x945 = x932;
            } else {
              long x934 = x856;
              struct Anon1931420570* x937 = x789;
              x937[x934] = x936;
              long x939 = x790;
              x791[x939] = x934;
              x790 = x790 + 1L;
              x945 = false;
            }
            if (!x945) break;
          }
        }
      } else {
      }
    }
    long x956 = x790;
    long x958;
    for(x958=0L; x958 < x956; x958++) {
      long x959 = x791[x958];
      struct Anon1931420570* x960 = x789;
      struct Anon1931420570 x961 = x960[x959];
      struct Anon625264174 x962 = x961.key;;
      struct Anon567626277 x963 = x961.aggs;;
      if (x975) {
      } else {
        double x965 = x963._1;;
        double x966 = x963._2;;
        double x967 = x963._3;;
        double x968 = x963._4;;
        double x969 = x963._5;;
        double x970 = x965 / x969;
        double x971 = x966 / x969;
        double x964 = x963._0;;
        double x972 = x964 / x969;
        char x978 = x962.L_RETURNFLAG;;
        char x979 = x962.L_LINESTATUS;;
        printf("%c|%c|%.2f|%.2f|%.2f|%.2f|%.2f|%.2f|%.6f|%.0f\n",x978,x979,x965,x966,x967,x968,x970,x971,x972,x969);
        x805 = x805 + 1L;
      }
    }
    long x986 = x805;
    printf("(%d rows)\n",x986);
    gettimeofday(&x990, NULL);
    timeval_subtract(&x991, &x990, &x989);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x991.tv_sec * 1000) + (x991.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
