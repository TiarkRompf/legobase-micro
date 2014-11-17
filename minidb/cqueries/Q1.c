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

struct Anon1272074242 {
bool exists;
struct Anon625264174 key;
struct Anon567626277 aggs;
};

struct Anon1124044545 {
struct Anon625264174 key;
struct Anon1296044246 aggs;
};

/************************ FUNCTIONS **************************/

/************************ MAIN BODY **************************/
int main(int x0, char** x1) {
  int x5 = 0;
  int x6 = 1048576;
  int x7 = 0;
  double* x16 = (double*)malloc(1048576 * sizeof(double));
  double* x17 = x16;
  double* x18 = (double*)malloc(1048576 * sizeof(double));
  double* x19 = x18;
  double* x20 = (double*)malloc(1048576 * sizeof(double));
  double* x21 = x20;
  double* x22 = (double*)malloc(1048576 * sizeof(double));
  double* x23 = x22;
  char* x24 = (char*)malloc(1048576 * sizeof(char));
  char* x25 = x24;
  char* x26 = (char*)malloc(1048576 * sizeof(char));
  char* x27 = x26;
  long* x28 = (long*)malloc(1048576 * sizeof(long));
  long* x29 = x28;
  int x2 = open("../databases/sf2/lineitem.tbl",0);
  int x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    int x40 = x5;
    bool x41 = x40 < x3;
    if (!x41) break;
    for (;;) {
      int x45 = x5;
      char x46 = x4[x45];
      bool x47 = x46 != '|';
      bool x52 = x47;
      if (x47) {
        int x48 = x5;
        char x49 = x4[x48];
        bool x50 = x49 != '\n';
        x52 = x50;
      }
      bool x53 = x52;
      if (!x53) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      int x69 = x5;
      char x70 = x4[x69];
      bool x71 = x70 != '|';
      bool x76 = x71;
      if (x71) {
        int x72 = x5;
        char x73 = x4[x72];
        bool x74 = x73 != '\n';
        x76 = x74;
      }
      bool x77 = x76;
      if (!x77) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      int x93 = x5;
      char x94 = x4[x93];
      bool x95 = x94 != '|';
      bool x100 = x95;
      if (x95) {
        int x96 = x5;
        char x97 = x4[x96];
        bool x98 = x97 != '\n';
        x100 = x98;
      }
      bool x101 = x100;
      if (!x101) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      int x117 = x5;
      char x118 = x4[x117];
      bool x119 = x118 != '|';
      bool x124 = x119;
      if (x119) {
        int x120 = x5;
        char x121 = x4[x120];
        bool x122 = x121 != '\n';
        x124 = x122;
      }
      bool x125 = x124;
      if (!x125) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    int x140 = 0;
    int x141 = 1;
    for (;;) {
      int x142 = x5;
      char x143 = x4[x142];
      bool x144 = x143 != '.';
      bool x149 = x144;
      if (x144) {
        int x145 = x5;
        char x146 = x4[x145];
        bool x147 = x146 != '|';
        x149 = x147;
      }
      bool x150 = x149;
      bool x155 = x150;
      if (x150) {
        int x151 = x5;
        char x152 = x4[x151];
        bool x153 = x152 != '\n';
        x155 = x153;
      }
      bool x156 = x155;
      if (!x156) break;
      int x158 = x140;
      int x160 = x5;
      int x159 = x158 * 10;
      char x161 = x4[x160];
      char x162 = x161 - '0';
      int x163 = x159 + x162;
      x140 = x163;
      x5 = x5 + 1;
    }
    int x168 = x5;
    char x169 = x4[x168];
    bool x170 = x169 == '.';
    if (x170) {
      x5 = x5 + 1;
      for (;;) {
        int x172 = x5;
        char x173 = x4[x172];
        bool x174 = x173 != '|';
        bool x179 = x174;
        if (x174) {
          int x175 = x5;
          char x176 = x4[x175];
          bool x177 = x176 != '\n';
          x179 = x177;
        }
        bool x180 = x179;
        if (!x180) break;
        int x182 = x140;
        int x184 = x5;
        int x183 = x182 * 10;
        char x185 = x4[x184];
        char x186 = x185 - '0';
        int x187 = x183 + x186;
        x140 = x187;
        int x189 = x141;
        int x190 = x189 * 10;
        x141 = x190;
        x5 = x5 + 1;
      }
    } else {
    }
    x5 = x5 + 1;
    int x199 = x140;
    int x201 = x141;
    int x205 = 0;
    int x206 = 1;
    for (;;) {
      int x207 = x5;
      char x208 = x4[x207];
      bool x209 = x208 != '.';
      bool x214 = x209;
      if (x209) {
        int x210 = x5;
        char x211 = x4[x210];
        bool x212 = x211 != '|';
        x214 = x212;
      }
      bool x215 = x214;
      bool x220 = x215;
      if (x215) {
        int x216 = x5;
        char x217 = x4[x216];
        bool x218 = x217 != '\n';
        x220 = x218;
      }
      bool x221 = x220;
      if (!x221) break;
      int x223 = x205;
      int x225 = x5;
      int x224 = x223 * 10;
      char x226 = x4[x225];
      char x227 = x226 - '0';
      int x228 = x224 + x227;
      x205 = x228;
      x5 = x5 + 1;
    }
    int x233 = x5;
    char x234 = x4[x233];
    bool x235 = x234 == '.';
    if (x235) {
      x5 = x5 + 1;
      for (;;) {
        int x237 = x5;
        char x238 = x4[x237];
        bool x239 = x238 != '|';
        bool x244 = x239;
        if (x239) {
          int x240 = x5;
          char x241 = x4[x240];
          bool x242 = x241 != '\n';
          x244 = x242;
        }
        bool x245 = x244;
        if (!x245) break;
        int x247 = x205;
        int x249 = x5;
        int x248 = x247 * 10;
        char x250 = x4[x249];
        char x251 = x250 - '0';
        int x252 = x248 + x251;
        x205 = x252;
        int x254 = x206;
        int x255 = x254 * 10;
        x206 = x255;
        x5 = x5 + 1;
      }
    } else {
    }
    x5 = x5 + 1;
    int x264 = x205;
    int x266 = x206;
    int x270 = 0;
    int x271 = 1;
    for (;;) {
      int x272 = x5;
      char x273 = x4[x272];
      bool x274 = x273 != '.';
      bool x279 = x274;
      if (x274) {
        int x275 = x5;
        char x276 = x4[x275];
        bool x277 = x276 != '|';
        x279 = x277;
      }
      bool x280 = x279;
      bool x285 = x280;
      if (x280) {
        int x281 = x5;
        char x282 = x4[x281];
        bool x283 = x282 != '\n';
        x285 = x283;
      }
      bool x286 = x285;
      if (!x286) break;
      int x288 = x270;
      int x290 = x5;
      int x289 = x288 * 10;
      char x291 = x4[x290];
      char x292 = x291 - '0';
      int x293 = x289 + x292;
      x270 = x293;
      x5 = x5 + 1;
    }
    int x298 = x5;
    char x299 = x4[x298];
    bool x300 = x299 == '.';
    if (x300) {
      x5 = x5 + 1;
      for (;;) {
        int x302 = x5;
        char x303 = x4[x302];
        bool x304 = x303 != '|';
        bool x309 = x304;
        if (x304) {
          int x305 = x5;
          char x306 = x4[x305];
          bool x307 = x306 != '\n';
          x309 = x307;
        }
        bool x310 = x309;
        if (!x310) break;
        int x312 = x270;
        int x314 = x5;
        int x313 = x312 * 10;
        char x315 = x4[x314];
        char x316 = x315 - '0';
        int x317 = x313 + x316;
        x270 = x317;
        int x319 = x271;
        int x320 = x319 * 10;
        x271 = x320;
        x5 = x5 + 1;
      }
    } else {
    }
    x5 = x5 + 1;
    int x329 = x270;
    int x331 = x271;
    int x335 = 0;
    int x336 = 1;
    for (;;) {
      int x337 = x5;
      char x338 = x4[x337];
      bool x339 = x338 != '.';
      bool x344 = x339;
      if (x339) {
        int x340 = x5;
        char x341 = x4[x340];
        bool x342 = x341 != '|';
        x344 = x342;
      }
      bool x345 = x344;
      bool x350 = x345;
      if (x345) {
        int x346 = x5;
        char x347 = x4[x346];
        bool x348 = x347 != '\n';
        x350 = x348;
      }
      bool x351 = x350;
      if (!x351) break;
      int x353 = x335;
      int x355 = x5;
      int x354 = x353 * 10;
      char x356 = x4[x355];
      char x357 = x356 - '0';
      int x358 = x354 + x357;
      x335 = x358;
      x5 = x5 + 1;
    }
    int x363 = x5;
    char x364 = x4[x363];
    bool x365 = x364 == '.';
    if (x365) {
      x5 = x5 + 1;
      for (;;) {
        int x367 = x5;
        char x368 = x4[x367];
        bool x369 = x368 != '|';
        bool x374 = x369;
        if (x369) {
          int x370 = x5;
          char x371 = x4[x370];
          bool x372 = x371 != '\n';
          x374 = x372;
        }
        bool x375 = x374;
        if (!x375) break;
        int x377 = x335;
        int x379 = x5;
        int x378 = x377 * 10;
        char x380 = x4[x379];
        char x381 = x380 - '0';
        int x382 = x378 + x381;
        x335 = x382;
        int x384 = x336;
        int x385 = x384 * 10;
        x336 = x385;
        x5 = x5 + 1;
      }
    } else {
    }
    x5 = x5 + 1;
    int x394 = x335;
    int x396 = x336;
    int x399 = x5;
    x5 = x5 + 2;
    int x402 = x5;
    x5 = x5 + 2;
    int x406 = 0;
    for (;;) {
      int x407 = x5;
      char x408 = x4[x407];
      bool x409 = x408 != '-';
      bool x414 = x409;
      if (x409) {
        int x410 = x5;
        char x411 = x4[x410];
        bool x412 = x411 != '\n';
        x414 = x412;
      }
      bool x415 = x414;
      if (!x415) break;
      int x417 = x406;
      int x419 = x5;
      int x418 = x417 * 10;
      char x420 = x4[x419];
      char x421 = x420 - '0';
      int x422 = x418 + x421;
      x406 = x422;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    int x428 = x406;
    int x430 = 0;
    for (;;) {
      int x431 = x5;
      char x432 = x4[x431];
      bool x433 = x432 != '-';
      bool x438 = x433;
      if (x433) {
        int x434 = x5;
        char x435 = x4[x434];
        bool x436 = x435 != '\n';
        x438 = x436;
      }
      bool x439 = x438;
      if (!x439) break;
      int x441 = x430;
      int x443 = x5;
      int x442 = x441 * 10;
      char x444 = x4[x443];
      char x445 = x444 - '0';
      int x446 = x442 + x445;
      x430 = x446;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    int x452 = x430;
    int x454 = 0;
    for (;;) {
      int x455 = x5;
      char x456 = x4[x455];
      bool x457 = x456 != '|';
      bool x462 = x457;
      if (x457) {
        int x458 = x5;
        char x459 = x4[x458];
        bool x460 = x459 != '\n';
        x462 = x460;
      }
      bool x463 = x462;
      if (!x463) break;
      int x465 = x454;
      int x467 = x5;
      int x466 = x465 * 10;
      char x468 = x4[x467];
      char x469 = x468 - '0';
      int x470 = x466 + x469;
      x454 = x470;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    int x476 = x454;
    for (;;) {
      int x483 = x5;
      char x484 = x4[x483];
      bool x485 = x484 != '-';
      bool x490 = x485;
      if (x485) {
        int x486 = x5;
        char x487 = x4[x486];
        bool x488 = x487 != '\n';
        x490 = x488;
      }
      bool x491 = x490;
      if (!x491) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      int x507 = x5;
      char x508 = x4[x507];
      bool x509 = x508 != '-';
      bool x514 = x509;
      if (x509) {
        int x510 = x5;
        char x511 = x4[x510];
        bool x512 = x511 != '\n';
        x514 = x512;
      }
      bool x515 = x514;
      if (!x515) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      int x531 = x5;
      char x532 = x4[x531];
      bool x533 = x532 != '|';
      bool x538 = x533;
      if (x533) {
        int x534 = x5;
        char x535 = x4[x534];
        bool x536 = x535 != '\n';
        x538 = x536;
      }
      bool x539 = x538;
      if (!x539) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      int x559 = x5;
      char x560 = x4[x559];
      bool x561 = x560 != '-';
      bool x566 = x561;
      if (x561) {
        int x562 = x5;
        char x563 = x4[x562];
        bool x564 = x563 != '\n';
        x566 = x564;
      }
      bool x567 = x566;
      if (!x567) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      int x583 = x5;
      char x584 = x4[x583];
      bool x585 = x584 != '-';
      bool x590 = x585;
      if (x585) {
        int x586 = x5;
        char x587 = x4[x586];
        bool x588 = x587 != '\n';
        x590 = x588;
      }
      bool x591 = x590;
      if (!x591) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      int x607 = x5;
      char x608 = x4[x607];
      bool x609 = x608 != '|';
      bool x614 = x609;
      if (x609) {
        int x610 = x5;
        char x611 = x4[x610];
        bool x612 = x611 != '\n';
        x614 = x612;
      }
      bool x615 = x614;
      if (!x615) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      int x634 = x5;
      char x635 = x4[x634];
      bool x636 = x635 != '|';
      bool x641 = x636;
      if (x636) {
        int x637 = x5;
        char x638 = x4[x637];
        bool x639 = x638 != '\n';
        x641 = x639;
      }
      bool x642 = x641;
      if (!x642) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      int x652 = x5;
      char x653 = x4[x652];
      bool x654 = x653 != '|';
      bool x659 = x654;
      if (x654) {
        int x655 = x5;
        char x656 = x4[x655];
        bool x657 = x656 != '\n';
        x659 = x657;
      }
      bool x660 = x659;
      if (!x660) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    for (;;) {
      int x670 = x5;
      char x671 = x4[x670];
      bool x672 = x671 != '|';
      bool x677 = x672;
      if (x672) {
        int x673 = x5;
        char x674 = x4[x673];
        bool x675 = x674 != '\n';
        x677 = x675;
      }
      bool x678 = x677;
      if (!x678) break;
      x5 = x5 + 1;
    }
    x5 = x5 + 1;
    int x688 = x7;
    int x689 = x6;
    bool x690 = x688 == x689;
    if (x690) {
      int x691 = x689 * 4;
      x6 = x691;
      printf("buffer.resize %d\n",x691);
      double* x706 = x17;
      double* x707 = (double*)realloc(x706,x691 * sizeof(double));
      x17 = x707;
      double* x709 = x19;
      double* x710 = (double*)realloc(x709,x691 * sizeof(double));
      x19 = x710;
      double* x712 = x21;
      double* x713 = (double*)realloc(x712,x691 * sizeof(double));
      x21 = x713;
      double* x715 = x23;
      double* x716 = (double*)realloc(x715,x691 * sizeof(double));
      x23 = x716;
      char* x718 = x25;
      char* x719 = (char*)realloc(x718,x691 * sizeof(char));
      x25 = x719;
      char* x721 = x27;
      char* x722 = (char*)realloc(x721,x691 * sizeof(char));
      x27 = x722;
      long* x724 = x29;
      long* x725 = (long*)realloc(x724,x691 * sizeof(long));
      x29 = x725;
    } else {
    }
    double* x752 = x17;
    double x200 = (double)x199;
    double x202 = (double)x201;
    double x203 = x200 / x202;
    x752[x688] = x203;
    double* x754 = x19;
    double x265 = (double)x264;
    double x267 = (double)x266;
    double x268 = x265 / x267;
    x754[x688] = x268;
    double* x756 = x21;
    double x330 = (double)x329;
    double x332 = (double)x331;
    double x333 = x330 / x332;
    x756[x688] = x333;
    double* x758 = x23;
    double x395 = (double)x394;
    double x397 = (double)x396;
    double x398 = x395 / x397;
    x758[x688] = x398;
    char* x760 = x25;
    char x400 = x4[x399];
    x760[x688] = x400;
    char* x762 = x27;
    char x403 = x4[x402];
    x762[x688] = x403;
    long* x764 = x29;
    long x477 = x428 * 10000L;
    long x478 = x452 * 100L;
    long x479 = x477 + x478;
    long x480 = x479 + x476;
    x764[x688] = x480;
    x7 = x7 + 1;
  }
  bool x972 = true == false;
  int x780;
  for(x780=0; x780 < 5; x780++) {
    bool x781 = false;
    int x782 = 0;
    struct Anon1272074242* x786 = (struct Anon1272074242*)malloc(16777216 * sizeof(struct Anon1272074242));
    struct Anon1272074242* x787 = x786;
    int x788 = 0;
    int* x789 = (int*)malloc(16777216 * sizeof(int));
    int x791;
    for(x791=0; x791 < 16777216; x791++) {
      struct Anon1272074242* x792 = x787;
      struct Anon1272074242 x793 = x792[x791];
      struct Anon625264174 x794 = x793.key;;
      struct Anon567626277 x795 = x793.aggs;;
      struct Anon1272074242 x796;
      x796.exists = false;
      x796.key = x794;
      x796.aggs = x795;
      x792[x791] = x796;
    }
    int x802 = 0;
    struct timeval x986, x987, x988;
    gettimeofday(&x986, NULL);
    printf("%s\n","begin scan LINEITEM");
    for (;;) {
      bool x804 = x781;
      bool x805 = !x804;
      bool x810 = x805;
      if (x805) {
        int x806 = x782;
        int x807 = x7;
        bool x808 = x806 < x807;
        x810 = x808;
      }
      bool x811 = x810;
      if (!x811) break;
      int x813 = x782;
      double* x822 = x17;
      double x823 = x822[x813];
      double* x824 = x19;
      double x825 = x824[x813];
      double* x826 = x21;
      double x827 = x826[x813];
      double* x828 = x23;
      double x829 = x828[x813];
      char* x830 = x25;
      char x831 = x830[x813];
      char* x832 = x27;
      char x833 = x832[x813];
      long* x834 = x29;
      long x835 = x834[x813];
      x782 = x782 + 1;
      bool x848 = x835 <= 19980811L;
      if (x848) {
        int x850 = x833 * 41;
        int x851 = x850 + x831;
        int x852 = x851 & 16777215;
        int x853 = x852;
        struct Anon1272074242* x854 = x787;
        struct Anon1272074242 x855 = x854[x852];
        struct Anon1272074242 x856 = x855;
        bool x857 = x855.exists;;
        bool x867 = x857;
        if (x857) {
          struct Anon1272074242 x858 = x856;
          struct Anon625264174 x859 = x858.key;;
          char x860 = x859.L_RETURNFLAG;;
          bool x861 = x860 == x831;
          bool x864 = x861;
          if (x861) {
            char x862 = x859.L_LINESTATUS;;
            bool x863 = x862 == x833;
            x864 = x863;
          }
          bool x865 = x864;
          x867 = x865;
        }
        bool x868 = x867;
        if (x868) {
          struct Anon567626277 x869 = x855.aggs;;
          struct Anon625264174 x887 = x855.key;;
          double x870 = x869._0;;
          double x871 = x827 + x870;
          double x872 = x869._1;;
          double x873 = x823 + x872;
          double x874 = x869._2;;
          double x875 = x825 + x874;
          double x876 = 1.0 - x827;
          double x877 = x825 * x876;
          double x878 = x869._3;;
          double x879 = x877 + x878;
          double x880 = 1.0 + x829;
          double x881 = x877 * x880;
          double x882 = x869._4;;
          double x883 = x881 + x882;
          double x884 = x869._5;;
          double x885 = x884 + 1.0;
          struct Anon567626277 x886;
          x886._0 = x871;
          x886._1 = x873;
          x886._2 = x875;
          x886._3 = x879;
          x886._4 = x883;
          x886._5 = x885;
          struct Anon1272074242 x888;
          x888.exists = true;
          x888.key = x887;
          x888.aggs = x886;
          x854[x852] = x888;
        } else {
          double x876 = 1.0 - x827;
          double x877 = x825 * x876;
          double x880 = 1.0 + x829;
          double x881 = x877 * x880;
          struct Anon625264174 x849;
          x849.L_RETURNFLAG = x831;
          x849.L_LINESTATUS = x833;
          struct Anon567626277 x932;
          x932._0 = x827;
          x932._1 = x823;
          x932._2 = x825;
          x932._3 = x877;
          x932._4 = x881;
          x932._5 = 1.0;
          struct Anon1272074242 x933;
          x933.exists = true;
          x933.key = x849;
          x933.aggs = x932;
          for (;;) {
            struct Anon1272074242 x891 = x856;
            bool x892 = x891.exists;;
            bool x942;
            if (x892) {
              struct Anon625264174 x893 = x891.key;;
              char x894 = x893.L_RETURNFLAG;;
              bool x895 = x894 == x831;
              bool x898 = x895;
              if (x895) {
                char x896 = x893.L_LINESTATUS;;
                bool x897 = x896 == x833;
                x898 = x897;
              }
              bool x899 = x898;
              bool x929;
              if (x899) {
                struct Anon567626277 x900 = x891.aggs;;
                int x914 = x853;
                struct Anon1272074242* x916 = x787;
                double x901 = x900._0;;
                double x902 = x827 + x901;
                double x903 = x900._1;;
                double x904 = x823 + x903;
                double x905 = x900._2;;
                double x906 = x825 + x905;
                double x907 = x900._3;;
                double x908 = x877 + x907;
                double x909 = x900._4;;
                double x910 = x881 + x909;
                double x911 = x900._5;;
                double x912 = x911 + 1.0;
                struct Anon567626277 x913;
                x913._0 = x902;
                x913._1 = x904;
                x913._2 = x906;
                x913._3 = x908;
                x913._4 = x910;
                x913._5 = x912;
                struct Anon1272074242 x915;
                x915.exists = true;
                x915.key = x893;
                x915.aggs = x913;
                x916[x914] = x915;
                x929 = false;
              } else {
                int x919 = x853;
                int x920 = x919 + 1;
                int x921 = x920 % 16777215;
                x853 = x921;
                struct Anon1272074242* x923 = x787;
                struct Anon1272074242 x924 = x923[x921];
                x856 = x924;
                x929 = true;
              }
              x942 = x929;
            } else {
              int x931 = x853;
              struct Anon1272074242* x934 = x787;
              x934[x931] = x933;
              int x936 = x788;
              x789[x936] = x931;
              x788 = x788 + 1;
              x942 = false;
            }
            if (!x942) break;
          }
        }
      } else {
      }
    }
    int x953 = x788;
    int x955;
    for(x955=0; x955 < x953; x955++) {
      int x956 = x789[x955];
      struct Anon1272074242* x957 = x787;
      struct Anon1272074242 x958 = x957[x956];
      struct Anon625264174 x959 = x958.key;;
      struct Anon567626277 x960 = x958.aggs;;
      if (x972) {
      } else {
        double x962 = x960._1;;
        double x963 = x960._2;;
        double x964 = x960._3;;
        double x965 = x960._4;;
        double x966 = x960._5;;
        double x967 = x962 / x966;
        double x968 = x963 / x966;
        double x961 = x960._0;;
        double x969 = x961 / x966;
        char x975 = x959.L_RETURNFLAG;;
        char x976 = x959.L_LINESTATUS;;
        printf("%c|%c|%.2f|%.2f|%.2f|%.2f|%.2f|%.2f|%.6f|%.0f\n",x975,x976,x962,x963,x964,x965,x967,x968,x969,x966);
        x802 = x802 + 1;
      }
    }
    int x983 = x802;
    printf("(%d rows)\n",x983);
    gettimeofday(&x987, NULL);
    timeval_subtract(&x988, &x987, &x986);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x988.tv_sec * 1000) + (x988.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
