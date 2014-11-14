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
struct Anon168903330;
struct Anon567626277;
struct Anon1406772883;
struct Anon1296044246;
struct Anon1866483359;
struct Anon1023322325;
struct Anon855148991;
struct Anon2134411685;
struct Anon0;
struct Anon15765642;
struct Anon102935935;
struct Anon1268892766;
struct Anon327816002;
struct Anon2131537536;
struct Anon722854457;
struct Anon625264174;
struct Anon1395358962;
struct Anon704530870;

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

struct Anon567626277 {
double _0;
double _1;
double _2;
double _3;
double _4;
double _5;
};

struct Anon1406772883 {
int N_NATIONKEY;
char* N_NAME;
int N_REGIONKEY;
char* N_COMMENT;
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

struct Anon2134411685 {
int key;
struct Anon1023322325* aggs;
};

struct Anon0 {
struct Anon1866483359* left;
struct Anon327816002* right;
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

struct Anon704530870 {
struct Anon625264174* key;
struct Anon567626277* aggs;
};

/************************ FUNCTIONS **************************/
int x3402(struct Anon2131537536* x1542, struct Anon2131537536* x1541);
int x3408(struct Anon2131537536* x3403, struct Anon2131537536* x3404, struct Anon2131537536** x3405);
int x3402(struct Anon2131537536* x1542, struct Anon2131537536* x1541) {
  struct Anon1023322325* x1543 = x1541->wnd;;
  double x1544 = x1543->S_ACCTBAL;;
  struct Anon1023322325* x1545 = x1542->wnd;;
  double x1546 = x1545->S_ACCTBAL;;
  bool x1547 = x1544 < x1546;
  int x2634;
  if (x1547) {
    x2634 = 1;
  } else {
    bool x1548 = x1544 > x1546;
    int x2632;
    if (x1548) {
      x2632 = -1;
    } else {
      char* x1549 = x1543->N_NAME;;
      char* x1550 = x1545->N_NAME;;
      int x1551 = strcmp(x1549,x1550);
      int x2619 = x1551;
      bool x2620 = x1551 == 0;
      if (x2620) {
        char* x1554 = x1543->S_NAME;;
        char* x1555 = x1545->S_NAME;;
        int x1556 = strcmp(x1554,x1555);
        x2619 = x1556;
        bool x2622 = x1556 == 0;
        if (x2622) {
          int x1559 = x1543->P_PARTKEY;;
          int x1560 = x1545->P_PARTKEY;;
          int x1561 = x1559 - x1560;
          x2619 = x1561;
        } else {
        }
      } else {
      }
      int x2629 = x2619;
      x2632 = x2629;
    }
    x2634 = x2632;
  }
  return x2634;
}
int x3408(struct Anon2131537536* x3403, struct Anon2131537536* x3404, struct Anon2131537536** x3405) {
  *x3405 = x3404;
  return 0;
}

/************************ MAIN BODY **************************/
int main(int x1036, char** x1037) {
  FILE* x2249 = fopen("../databases/sf2/part.tbl", "r");
  int x2250 = 1048576;
  int x2251 = 0;
  int* x2252 = (int*)malloc(1048576 * sizeof(int));
  int* x2253 = x2252;
  char** x2256 = (char**)malloc(1048576 * sizeof(char*));
  char** x2257 = x2256;
  char** x2260 = (char**)malloc(1048576 * sizeof(char*));
  char** x2261 = x2260;
  int* x2262 = (int*)malloc(1048576 * sizeof(int));
  int* x2263 = x2262;
  for (;;) {
    bool x2271 = !feof(x2249);
    if (!x2271) break;
    int x2273 = 0;
    if (fscanf(x2249,"%d|",&x2273) == EOF) break;
    char* x2274 = (char*)malloc(56 * sizeof(char));
    int x2276 = 0;
    char x2275 = ' ';
    while (1) {
      fscanf(x2249,"%c",&x2275);
      if (x2275=='|' || x2275=='\n') break;
      if (x2276>=55) { printf("ERROR: scanner.nextString reading past end of buffer %d",x2276); break;}
      ((char*)x2274)[x2276] = x2275;
      x2276 += 1;
    }
    ((char*)x2274)[x2276] = '\0';
    char* x2279 = (char*)malloc(26 * sizeof(char));
    int x2281 = 0;
    char x2280 = ' ';
    while (1) {
      fscanf(x2249,"%c",&x2280);
      if (x2280=='|' || x2280=='\n') break;
      if (x2281>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x2281); break;}
      ((char*)x2279)[x2281] = x2280;
      x2281 += 1;
    }
    ((char*)x2279)[x2281] = '\0';
    char* x2283 = x2279; // unsafe immutable;
    char* x2284 = (char*)malloc(11 * sizeof(char));
    int x2286 = 0;
    char x2285 = ' ';
    while (1) {
      fscanf(x2249,"%c",&x2285);
      if (x2285=='|' || x2285=='\n') break;
      if (x2286>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x2286); break;}
      ((char*)x2284)[x2286] = x2285;
      x2286 += 1;
    }
    ((char*)x2284)[x2286] = '\0';
    char* x2289 = (char*)malloc(26 * sizeof(char));
    int x2291 = 0;
    char x2290 = ' ';
    while (1) {
      fscanf(x2249,"%c",&x2290);
      if (x2290=='|' || x2290=='\n') break;
      if (x2291>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x2291); break;}
      ((char*)x2289)[x2291] = x2290;
      x2291 += 1;
    }
    ((char*)x2289)[x2291] = '\0';
    char* x2293 = x2289; // unsafe immutable;
    int x2294 = 0;
    if (fscanf(x2249,"%d|",&x2294) == EOF) break;
    char* x2295 = (char*)malloc(11 * sizeof(char));
    int x2297 = 0;
    char x2296 = ' ';
    while (1) {
      fscanf(x2249,"%c",&x2296);
      if (x2296=='|' || x2296=='\n') break;
      if (x2297>=10) { printf("ERROR: scanner.nextString reading past end of buffer %d",x2297); break;}
      ((char*)x2295)[x2297] = x2296;
      x2297 += 1;
    }
    ((char*)x2295)[x2297] = '\0';
    double x2300 = 0.0;
    if (fscanf(x2249,"%lf|",&x2300) == EOF) break;
    char* x2301 = (char*)malloc(24 * sizeof(char));
    int x2303 = 0;
    char x2302 = ' ';
    while (1) {
      fscanf(x2249,"%c",&x2302);
      if (x2302=='|' || x2302=='\n') break;
      if (x2303>=23) { printf("ERROR: scanner.nextString reading past end of buffer %d",x2303); break;}
      ((char*)x2301)[x2303] = x2302;
      x2303 += 1;
    }
    ((char*)x2301)[x2303] = '\0';
    int x2306 = x2251;
    int x2307 = x2250;
    bool x2308 = x2306 == x2307;
    if (x2308) {
      int x2309 = x2307 * 4;
      x2250 = x2309;
      printf("buffer.resize %d\n",x2309);
      int* x2312 = x2253;
      int* x2313 = (int*)realloc(x2312,x2309 * sizeof(int));
      x2253 = x2313;
      char** x2318 = x2257;
      char** x2319 = (char**)realloc(x2318,x2309 * sizeof(char*));
      x2257 = x2319;
      char** x2324 = x2261;
      char** x2325 = (char**)realloc(x2324,x2309 * sizeof(char*));
      x2261 = x2325;
      int* x2327 = x2263;
      int* x2328 = (int*)realloc(x2327,x2309 * sizeof(int));
      x2263 = x2328;
    } else {
    }
    int* x2341 = x2253;
    x2341[x2306] = x2273;
    char** x2345 = x2257;
    x2345[x2306] = x2283;
    char** x2349 = x2261;
    x2349[x2306] = x2293;
    int* x2351 = x2263;
    x2351[x2306] = x2294;
    x2251 = x2251 + 1;
  }
  FILE* x2363 = fopen("../databases/sf2/partsupp.tbl", "r");
  int x2364 = 1048576;
  int x2365 = 0;
  int* x2366 = (int*)malloc(1048576 * sizeof(int));
  int* x2367 = x2366;
  int* x2368 = (int*)malloc(1048576 * sizeof(int));
  int* x2369 = x2368;
  double* x2372 = (double*)malloc(1048576 * sizeof(double));
  double* x2373 = x2372;
  for (;;) {
    bool x2376 = !feof(x2363);
    if (!x2376) break;
    int x2378 = 0;
    if (fscanf(x2363,"%d|",&x2378) == EOF) break;
    int x2379 = 0;
    if (fscanf(x2363,"%d|",&x2379) == EOF) break;
    int x2380 = 0;
    if (fscanf(x2363,"%d|",&x2380) == EOF) break;
    double x2381 = 0.0;
    if (fscanf(x2363,"%lf|",&x2381) == EOF) break;
    char* x2382 = (char*)malloc(200 * sizeof(char));
    int x2384 = 0;
    char x2383 = ' ';
    while (1) {
      fscanf(x2363,"%c",&x2383);
      if (x2383=='|' || x2383=='\n') break;
      if (x2384>=199) { printf("ERROR: scanner.nextString reading past end of buffer %d",x2384); break;}
      ((char*)x2382)[x2384] = x2383;
      x2384 += 1;
    }
    ((char*)x2382)[x2384] = '\0';
    int x2387 = x2365;
    int x2388 = x2364;
    bool x2389 = x2387 == x2388;
    if (x2389) {
      int x2390 = x2388 * 4;
      x2364 = x2390;
      printf("buffer.resize %d\n",x2390);
      int* x2393 = x2367;
      int* x2394 = (int*)realloc(x2393,x2390 * sizeof(int));
      x2367 = x2394;
      int* x2396 = x2369;
      int* x2397 = (int*)realloc(x2396,x2390 * sizeof(int));
      x2369 = x2397;
      double* x2402 = x2373;
      double* x2403 = (double*)realloc(x2402,x2390 * sizeof(double));
      x2373 = x2403;
    } else {
    }
    int* x2410 = x2367;
    x2410[x2387] = x2378;
    int* x2412 = x2369;
    x2412[x2387] = x2379;
    double* x2416 = x2373;
    x2416[x2387] = x2381;
    x2365 = x2365 + 1;
  }
  FILE* x2424 = fopen("../databases/sf2/nation.tbl", "r");
  int x2425 = 1048576;
  int x2426 = 0;
  int* x2427 = (int*)malloc(1048576 * sizeof(int));
  int* x2428 = x2427;
  char** x2429 = (char**)malloc(1048576 * sizeof(char*));
  char** x2430 = x2429;
  int* x2431 = (int*)malloc(1048576 * sizeof(int));
  int* x2432 = x2431;
  for (;;) {
    bool x2435 = !feof(x2424);
    if (!x2435) break;
    int x2437 = 0;
    if (fscanf(x2424,"%d|",&x2437) == EOF) break;
    char* x2438 = (char*)malloc(26 * sizeof(char));
    int x2440 = 0;
    char x2439 = ' ';
    while (1) {
      fscanf(x2424,"%c",&x2439);
      if (x2439=='|' || x2439=='\n') break;
      if (x2440>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x2440); break;}
      ((char*)x2438)[x2440] = x2439;
      x2440 += 1;
    }
    ((char*)x2438)[x2440] = '\0';
    char* x2442 = x2438; // unsafe immutable;
    int x2443 = 0;
    if (fscanf(x2424,"%d|",&x2443) == EOF) break;
    char* x2444 = (char*)malloc(153 * sizeof(char));
    int x2446 = 0;
    char x2445 = ' ';
    while (1) {
      fscanf(x2424,"%c",&x2445);
      if (x2445=='|' || x2445=='\n') break;
      if (x2446>=152) { printf("ERROR: scanner.nextString reading past end of buffer %d",x2446); break;}
      ((char*)x2444)[x2446] = x2445;
      x2446 += 1;
    }
    ((char*)x2444)[x2446] = '\0';
    int x2449 = x2426;
    int x2450 = x2425;
    bool x2451 = x2449 == x2450;
    if (x2451) {
      int x2452 = x2450 * 4;
      x2425 = x2452;
      printf("buffer.resize %d\n",x2452);
      int* x2455 = x2428;
      int* x2456 = (int*)realloc(x2455,x2452 * sizeof(int));
      x2428 = x2456;
      char** x2458 = x2430;
      char** x2459 = (char**)realloc(x2458,x2452 * sizeof(char*));
      x2430 = x2459;
      int* x2461 = x2432;
      int* x2462 = (int*)realloc(x2461,x2452 * sizeof(int));
      x2432 = x2462;
    } else {
    }
    int* x2469 = x2428;
    x2469[x2449] = x2437;
    char** x2471 = x2430;
    x2471[x2449] = x2442;
    int* x2473 = x2432;
    x2473[x2449] = x2443;
    x2426 = x2426 + 1;
  }
  FILE* x2481 = fopen("../databases/sf2/region.tbl", "r");
  int x2482 = 1048576;
  int x2483 = 0;
  int* x2484 = (int*)malloc(1048576 * sizeof(int));
  int* x2485 = x2484;
  char** x2486 = (char**)malloc(1048576 * sizeof(char*));
  char** x2487 = x2486;
  for (;;) {
    bool x2490 = !feof(x2481);
    if (!x2490) break;
    int x2492 = 0;
    if (fscanf(x2481,"%d|",&x2492) == EOF) break;
    char* x2493 = (char*)malloc(26 * sizeof(char));
    int x2495 = 0;
    char x2494 = ' ';
    while (1) {
      fscanf(x2481,"%c",&x2494);
      if (x2494=='|' || x2494=='\n') break;
      if (x2495>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x2495); break;}
      ((char*)x2493)[x2495] = x2494;
      x2495 += 1;
    }
    ((char*)x2493)[x2495] = '\0';
    char* x2497 = x2493; // unsafe immutable;
    char* x2498 = (char*)malloc(153 * sizeof(char));
    int x2500 = 0;
    char x2499 = ' ';
    while (1) {
      fscanf(x2481,"%c",&x2499);
      if (x2499=='|' || x2499=='\n') break;
      if (x2500>=152) { printf("ERROR: scanner.nextString reading past end of buffer %d",x2500); break;}
      ((char*)x2498)[x2500] = x2499;
      x2500 += 1;
    }
    ((char*)x2498)[x2500] = '\0';
    int x2503 = x2483;
    int x2504 = x2482;
    bool x2505 = x2503 == x2504;
    if (x2505) {
      int x2506 = x2504 * 4;
      x2482 = x2506;
      printf("buffer.resize %d\n",x2506);
      int* x2509 = x2485;
      int* x2510 = (int*)realloc(x2509,x2506 * sizeof(int));
      x2485 = x2510;
      char** x2512 = x2487;
      char** x2513 = (char**)realloc(x2512,x2506 * sizeof(char*));
      x2487 = x2513;
    } else {
    }
    int* x2520 = x2485;
    x2520[x2503] = x2492;
    char** x2522 = x2487;
    x2522[x2503] = x2497;
    x2483 = x2483 + 1;
  }
  FILE* x2530 = fopen("../databases/sf2/supplier.tbl", "r");
  int x2531 = 1048576;
  int x2532 = 0;
  int* x2533 = (int*)malloc(1048576 * sizeof(int));
  int* x2534 = x2533;
  char** x2535 = (char**)malloc(1048576 * sizeof(char*));
  char** x2536 = x2535;
  char** x2537 = (char**)malloc(1048576 * sizeof(char*));
  char** x2538 = x2537;
  int* x2539 = (int*)malloc(1048576 * sizeof(int));
  int* x2540 = x2539;
  char** x2541 = (char**)malloc(1048576 * sizeof(char*));
  char** x2542 = x2541;
  double* x2543 = (double*)malloc(1048576 * sizeof(double));
  double* x2544 = x2543;
  char** x2545 = (char**)malloc(1048576 * sizeof(char*));
  char** x2546 = x2545;
  for (;;) {
    bool x2547 = !feof(x2530);
    if (!x2547) break;
    int x2549 = 0;
    if (fscanf(x2530,"%d|",&x2549) == EOF) break;
    char* x2550 = (char*)malloc(26 * sizeof(char));
    int x2552 = 0;
    char x2551 = ' ';
    while (1) {
      fscanf(x2530,"%c",&x2551);
      if (x2551=='|' || x2551=='\n') break;
      if (x2552>=25) { printf("ERROR: scanner.nextString reading past end of buffer %d",x2552); break;}
      ((char*)x2550)[x2552] = x2551;
      x2552 += 1;
    }
    ((char*)x2550)[x2552] = '\0';
    char* x2554 = x2550; // unsafe immutable;
    char* x2555 = (char*)malloc(41 * sizeof(char));
    int x2557 = 0;
    char x2556 = ' ';
    while (1) {
      fscanf(x2530,"%c",&x2556);
      if (x2556=='|' || x2556=='\n') break;
      if (x2557>=40) { printf("ERROR: scanner.nextString reading past end of buffer %d",x2557); break;}
      ((char*)x2555)[x2557] = x2556;
      x2557 += 1;
    }
    ((char*)x2555)[x2557] = '\0';
    char* x2559 = x2555; // unsafe immutable;
    int x2560 = 0;
    if (fscanf(x2530,"%d|",&x2560) == EOF) break;
    char* x2561 = (char*)malloc(16 * sizeof(char));
    int x2563 = 0;
    char x2562 = ' ';
    while (1) {
      fscanf(x2530,"%c",&x2562);
      if (x2562=='|' || x2562=='\n') break;
      if (x2563>=15) { printf("ERROR: scanner.nextString reading past end of buffer %d",x2563); break;}
      ((char*)x2561)[x2563] = x2562;
      x2563 += 1;
    }
    ((char*)x2561)[x2563] = '\0';
    char* x2565 = x2561; // unsafe immutable;
    double x2566 = 0.0;
    if (fscanf(x2530,"%lf|",&x2566) == EOF) break;
    char* x2567 = (char*)malloc(102 * sizeof(char));
    int x2569 = 0;
    char x2568 = ' ';
    while (1) {
      fscanf(x2530,"%c",&x2568);
      if (x2568=='|' || x2568=='\n') break;
      if (x2569>=101) { printf("ERROR: scanner.nextString reading past end of buffer %d",x2569); break;}
      ((char*)x2567)[x2569] = x2568;
      x2569 += 1;
    }
    ((char*)x2567)[x2569] = '\0';
    char* x2571 = x2567; // unsafe immutable;
    int x2572 = x2532;
    int x2573 = x2531;
    bool x2574 = x2572 == x2573;
    if (x2574) {
      int x2575 = x2573 * 4;
      x2531 = x2575;
      printf("buffer.resize %d\n",x2575);
      int* x2578 = x2534;
      int* x2579 = (int*)realloc(x2578,x2575 * sizeof(int));
      x2534 = x2579;
      char** x2581 = x2536;
      char** x2582 = (char**)realloc(x2581,x2575 * sizeof(char*));
      x2536 = x2582;
      char** x2584 = x2538;
      char** x2585 = (char**)realloc(x2584,x2575 * sizeof(char*));
      x2538 = x2585;
      int* x2587 = x2540;
      int* x2588 = (int*)realloc(x2587,x2575 * sizeof(int));
      x2540 = x2588;
      char** x2590 = x2542;
      char** x2591 = (char**)realloc(x2590,x2575 * sizeof(char*));
      x2542 = x2591;
      double* x2593 = x2544;
      double* x2594 = (double*)realloc(x2593,x2575 * sizeof(double));
      x2544 = x2594;
      char** x2596 = x2546;
      char** x2597 = (char**)realloc(x2596,x2575 * sizeof(char*));
      x2546 = x2597;
    } else {
    }
    int* x2601 = x2534;
    x2601[x2572] = x2549;
    char** x2603 = x2536;
    x2603[x2572] = x2554;
    char** x2605 = x2538;
    x2605[x2572] = x2559;
    int* x2607 = x2540;
    x2607[x2572] = x2560;
    char** x2609 = x2542;
    x2609[x2572] = x2565;
    double* x2611 = x2544;
    x2611[x2572] = x2566;
    char** x2613 = x2546;
    x2613[x2572] = x2571;
    x2532 = x2532 + 1;
  }
  GTree* x2636 = g_tree_new((GCompareFunc)x3402);;
  int x1408;
  for(x1408=0; x1408 < 1; x1408++) {
    bool x2637 = false;
    int x2638 = 0;
    bool x2639 = false;
    int x2640 = 0;
    int* x2642 = (int*)malloc(1073741824 * sizeof(int));
    int* x2643 = x2642;
    char** x2644 = (char**)malloc(1073741824 * sizeof(char*));
    char** x2645 = x2644;
    char** x2646 = (char**)malloc(1073741824 * sizeof(char*));
    char** x2647 = x2646;
    int* x2648 = (int*)malloc(1073741824 * sizeof(int));
    int* x2649 = x2648;
    char** x2650 = (char**)malloc(1073741824 * sizeof(char*));
    char** x2651 = x2650;
    double* x2652 = (double*)malloc(1073741824 * sizeof(double));
    double* x2653 = x2652;
    char** x2654 = (char**)malloc(1073741824 * sizeof(char*));
    char** x2655 = x2654;
    int x2656 = 0;
    int* x2657 = (int*)malloc(1048576 * sizeof(int));
    int* x2658 = (int*)malloc(1073741824 * sizeof(int));
    int x1432;
    for(x1432=0; x1432 < 1048576; x1432++) {
      x2657[x1432] = -1;
    }
    bool x2663 = false;
    int x2664 = 0;
    int* x2666 = (int*)malloc(1073741824 * sizeof(int));
    int* x2667 = x2666;
    char** x2668 = (char**)malloc(1073741824 * sizeof(char*));
    char** x2669 = x2668;
    int* x2670 = (int*)malloc(1073741824 * sizeof(int));
    int* x2671 = x2670;
    int x2674 = 0;
    int* x2675 = (int*)malloc(1048576 * sizeof(int));
    int* x2676 = (int*)malloc(1073741824 * sizeof(int));
    int x1451;
    for(x1451=0; x1451 < 1048576; x1451++) {
      x2675[x1451] = -1;
    }
    bool x2681 = false;
    int x2682 = 0;
    int* x2685 = (int*)malloc(1073741824 * sizeof(int));
    int* x2686 = x2685;
    char** x2689 = (char**)malloc(1073741824 * sizeof(char*));
    char** x2690 = x2689;
    int x2703 = 0;
    int* x2704 = (int*)malloc(1048576 * sizeof(int));
    int* x2705 = (int*)malloc(1073741824 * sizeof(int));
    int x1481;
    for(x1481=0; x1481 < 1048576; x1481++) {
      x2704[x1481] = -1;
    }
    bool x2710 = false;
    int x2711 = 0;
    int* x2714 = (int*)malloc(1073741824 * sizeof(int));
    int* x2715 = x2714;
    int x2720 = 0;
    int* x2721 = (int*)malloc(1048576 * sizeof(int));
    int* x2722 = (int*)malloc(1073741824 * sizeof(int));
    int x1499;
    for(x1499=0; x1499 < 1048576; x1499++) {
      x2721[x1499] = -1;
    }
    int x2728 = 1048576;
    int x2729 = 0;
    int* x2730 = (int*)malloc(1048576 * sizeof(int));
    int* x2731 = x2730;
    double* x2732 = (double*)malloc(1048576 * sizeof(double));
    double* x2733 = x2732;
    double* x2734 = (double*)malloc(1048576 * sizeof(double));
    double* x2735 = x2734;
    char** x2736 = (char**)malloc(1048576 * sizeof(char*));
    char** x2737 = x2736;
    char** x2738 = (char**)malloc(1048576 * sizeof(char*));
    char** x2739 = x2738;
    char** x2740 = (char**)malloc(1048576 * sizeof(char*));
    char** x2741 = x2740;
    char** x2742 = (char**)malloc(1048576 * sizeof(char*));
    char** x2743 = x2742;
    char** x2744 = (char**)malloc(1048576 * sizeof(char*));
    char** x2745 = x2744;
    int* x2746 = (int*)malloc(1048576 * sizeof(int));
    int* x2747 = x2746;
    char** x2748 = (char**)malloc(1048576 * sizeof(char*));
    char** x2749 = x2748;
    int x2750 = 4194304;
    int x2751 = 0;
    int* x2752 = (int*)malloc(4194304 * sizeof(int));
    int* x2753 = x2752;
    int x1532;
    for(x1532=0; x1532 < 4194304; x1532++) {
      int* x2754 = x2753;
      x2754[x1532] = -1;
    }
    int x2762 = 0;
    int x2764 = 0;
    struct timeval x2223, x2224, x3395;
    gettimeofday(&x2223, NULL);
    printf("(REGION X (PART X (NATION X (SUPPLIER X PARTSUPP)))): leftParent.next start\n");
    struct timeval x1616, x1617, x2806;
    gettimeofday(&x1616, NULL);
    printf("%s\n","begin scan REGION");
    for (;;) {
      bool x2767 = x2710;
      bool x2768 = !x2767;
      bool x2773 = x2768;
      if (x2768) {
        int x2769 = x2711;
        int x2770 = x2483;
        bool x2771 = x2769 < x2770;
        x2773 = x2771;
      }
      bool x2774 = x2773;
      if (!x2774) break;
      int x2777 = x2711;
      int* x2778 = x2485;
      int x2779 = x2778[x2777];
      char** x2780 = x2487;
      char* x2781 = x2780[x2777];
      x2711 = x2711 + 1;
      bool x2785 = strcmp(x2781,"AFRICA") == 0;;
      if (x2785) {
        int x2786 = x2720;
        int* x2787 = x2715;
        x2787[x2786] = x2779;
        x2720 = x2720 + 1;
        int x2794 = x2779 & 1048575;
        int x2795 = x2721[x2794];
        x2721[x2794] = x2786;
        x2722[x2786] = x2795;
      } else {
      }
    }
    printf("(REGION X (PART X (NATION X (SUPPLIER X PARTSUPP)))): leftParent.next done\n");
    gettimeofday(&x1617, NULL);
    timeval_subtract(&x2806, &x1617, &x1616);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x2806.tv_sec * 1000) + (x2806.tv_usec/1000)));
    printf("(REGION X (PART X (NATION X (SUPPLIER X PARTSUPP)))): rightParent.next start\n");
    struct timeval x2161, x2162, x3336;
    gettimeofday(&x2161, NULL);
    printf("(PART X (NATION X (SUPPLIER X PARTSUPP))): leftParent.next start\n");
    struct timeval x1689, x1690, x2879;
    gettimeofday(&x1689, NULL);
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x2811 = x2681;
      bool x2812 = !x2811;
      bool x2817 = x2812;
      if (x2812) {
        int x2813 = x2682;
        int x2814 = x2251;
        bool x2815 = x2813 < x2814;
        x2817 = x2815;
      }
      bool x2818 = x2817;
      if (!x2818) break;
      int x2821 = x2682;
      int* x2822 = x2253;
      int x2823 = x2822[x2821];
      char** x2826 = x2257;
      char* x2827 = x2826[x2821];
      char** x2830 = x2261;
      char* x2831 = x2830[x2821];
      int* x2832 = x2263;
      int x2833 = x2832[x2821];
      x2682 = x2682 + 1;
      bool x2841 = x2833 == 43;
      bool x2845 = x2841;
      if (x2841) {
        int x2843 = strlen(x2831);
        int x2842 = strlen("TIN");
        bool x2844 = strncmp(x2831+x2843-x2842,"TIN", x2842) == 0;;
        x2845 = x2844;
      }
      bool x2846 = x2845;
      if (x2846) {
        int x2847 = x2703;
        int* x2848 = x2686;
        x2848[x2847] = x2823;
        char** x2852 = x2690;
        x2852[x2847] = x2827;
        x2703 = x2703 + 1;
        int x2867 = x2823 & 1048575;
        int x2868 = x2704[x2867];
        x2704[x2867] = x2847;
        x2705[x2847] = x2868;
      } else {
      }
    }
    printf("(PART X (NATION X (SUPPLIER X PARTSUPP))): leftParent.next done\n");
    gettimeofday(&x1690, NULL);
    timeval_subtract(&x2879, &x1690, &x1689);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x2879.tv_sec * 1000) + (x2879.tv_usec/1000)));
    printf("(PART X (NATION X (SUPPLIER X PARTSUPP))): rightParent.next start\n");
    struct timeval x2155, x2156, x3331;
    gettimeofday(&x2155, NULL);
    printf("(NATION X (SUPPLIER X PARTSUPP)): leftParent.next start\n");
    struct timeval x1734, x1735, x2923;
    gettimeofday(&x1734, NULL);
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x2884 = x2663;
      bool x2885 = !x2884;
      bool x2890 = x2885;
      if (x2885) {
        int x2886 = x2664;
        int x2887 = x2426;
        bool x2888 = x2886 < x2887;
        x2890 = x2888;
      }
      bool x2891 = x2890;
      if (!x2891) break;
      int x2894 = x2664;
      int* x2895 = x2428;
      int x2896 = x2895[x2894];
      char** x2897 = x2430;
      char* x2898 = x2897[x2894];
      int* x2899 = x2432;
      int x2900 = x2899[x2894];
      x2664 = x2664 + 1;
      int x2904 = x2674;
      int* x2905 = x2667;
      x2905[x2904] = x2896;
      char** x2907 = x2669;
      x2907[x2904] = x2898;
      int* x2909 = x2671;
      x2909[x2904] = x2900;
      x2674 = x2674 + 1;
      int x2914 = x2896 & 1048575;
      int x2915 = x2675[x2914];
      x2675[x2914] = x2904;
      x2676[x2904] = x2915;
    }
    printf("(NATION X (SUPPLIER X PARTSUPP)): leftParent.next done\n");
    gettimeofday(&x1735, NULL);
    timeval_subtract(&x2923, &x1735, &x1734);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x2923.tv_sec * 1000) + (x2923.tv_usec/1000)));
    printf("(NATION X (SUPPLIER X PARTSUPP)): rightParent.next start\n");
    struct timeval x2149, x2150, x3326;
    gettimeofday(&x2149, NULL);
    printf("(SUPPLIER X PARTSUPP): leftParent.next start\n");
    struct timeval x1791, x1792, x2979;
    gettimeofday(&x1791, NULL);
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x2928 = x2639;
      bool x2929 = !x2928;
      bool x2934 = x2929;
      if (x2929) {
        int x2930 = x2640;
        int x2931 = x2532;
        bool x2932 = x2930 < x2931;
        x2934 = x2932;
      }
      bool x2935 = x2934;
      if (!x2935) break;
      int x2938 = x2640;
      int* x2939 = x2534;
      int x2940 = x2939[x2938];
      char** x2941 = x2536;
      char* x2942 = x2941[x2938];
      char** x2943 = x2538;
      char* x2944 = x2943[x2938];
      int* x2945 = x2540;
      int x2946 = x2945[x2938];
      char** x2947 = x2542;
      char* x2948 = x2947[x2938];
      double* x2949 = x2544;
      double x2950 = x2949[x2938];
      char** x2951 = x2546;
      char* x2952 = x2951[x2938];
      x2640 = x2640 + 1;
      int x2954 = x2656;
      int* x2955 = x2643;
      x2955[x2954] = x2940;
      char** x2957 = x2645;
      x2957[x2954] = x2942;
      char** x2959 = x2647;
      x2959[x2954] = x2944;
      int* x2961 = x2649;
      x2961[x2954] = x2946;
      char** x2963 = x2651;
      x2963[x2954] = x2948;
      double* x2965 = x2653;
      x2965[x2954] = x2950;
      char** x2967 = x2655;
      x2967[x2954] = x2952;
      x2656 = x2656 + 1;
      int x2970 = x2940 & 1048575;
      int x2971 = x2657[x2970];
      x2657[x2970] = x2954;
      x2658[x2954] = x2971;
    }
    printf("(SUPPLIER X PARTSUPP): leftParent.next done\n");
    gettimeofday(&x1792, NULL);
    timeval_subtract(&x2979, &x1792, &x1791);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x2979.tv_sec * 1000) + (x2979.tv_usec/1000)));
    printf("(SUPPLIER X PARTSUPP): rightParent.next start\n");
    struct timeval x2143, x2144, x3321;
    gettimeofday(&x2143, NULL);
    printf("%s\n","begin scan PARTSUPP");
    for (;;) {
      bool x2983 = x2637;
      bool x2984 = !x2983;
      bool x2989 = x2984;
      if (x2984) {
        int x2985 = x2638;
        int x2986 = x2365;
        bool x2987 = x2985 < x2986;
        x2989 = x2987;
      }
      bool x2990 = x2989;
      if (!x2990) break;
      int x2993 = x2638;
      int* x2994 = x2367;
      int x2995 = x2994[x2993];
      int* x2996 = x2369;
      int x2997 = x2996[x2993];
      double* x3000 = x2373;
      double x3001 = x3000[x2993];
      x2638 = x2638 + 1;
      int x3005 = x2997 & 1048575;
      int x3006 = x2657[x3005];
      int x3007 = x3006;
      int x3008 = x2995 & 1048575;
      for (;;) {
        int x3009 = x3007;
        bool x3010 = x3009 != -1;
        if (!x3010) break;
        int x3012 = x3007;
        int* x3013 = x2643;
        int x3014 = x3013[x3012];
        char** x3015 = x2645;
        char* x3016 = x3015[x3012];
        char** x3017 = x2647;
        char* x3018 = x3017[x3012];
        int* x3019 = x2649;
        int x3020 = x3019[x3012];
        char** x3021 = x2651;
        char* x3022 = x3021[x3012];
        double* x3023 = x2653;
        double x3024 = x3023[x3012];
        char** x3025 = x2655;
        char* x3026 = x3025[x3012];
        int x3027 = x2658[x3012];
        x3007 = x3027;
        bool x3029 = x3014 == x2997;
        if (x3029) {
          int x3030 = x3020 & 1048575;
          int x3031 = x2675[x3030];
          int x3032 = x3031;
          for (;;) {
            int x3033 = x3032;
            bool x3034 = x3033 != -1;
            if (!x3034) break;
            int x3036 = x3032;
            int* x3037 = x2667;
            int x3038 = x3037[x3036];
            char** x3039 = x2669;
            char* x3040 = x3039[x3036];
            int* x3041 = x2671;
            int x3042 = x3041[x3036];
            int x3045 = x2676[x3036];
            x3032 = x3045;
            bool x3047 = x3038 == x3020;
            if (x3047) {
              int x3048 = x2704[x3008];
              int x3049 = x3048;
              int x3050 = x3042 & 1048575;
              for (;;) {
                int x3051 = x3049;
                bool x3052 = x3051 != -1;
                if (!x3052) break;
                int x3054 = x3049;
                int* x3055 = x2686;
                int x3056 = x3055[x3054];
                char** x3059 = x2690;
                char* x3060 = x3059[x3054];
                int x3073 = x2705[x3054];
                x3049 = x3073;
                bool x3075 = x3056 == x2995;
                if (x3075) {
                  int x3076 = x2721[x3050];
                  int x3077 = x3076;
                  int x3078 = x3056 * 2;
                  int x3079 = x3078 * 3;
                  for (;;) {
                    int x3080 = x3077;
                    bool x3081 = x3080 != -1;
                    if (!x3081) break;
                    int x3083 = x3077;
                    int* x3084 = x2715;
                    int x3085 = x3084[x3083];
                    int x3090 = x2722[x3083];
                    x3077 = x3090;
                    bool x3092 = x3085 == x3042;
                    if (x3092) {
                      int x3094 = x2750;
                      int x3095 = x3094 - 1;
                      int x3096 = x3079 & x3095;
                      int x3097 = x3096;
                      int* x3098 = x2753;
                      int x3099 = x3098[x3096];
                      int x3100 = x3099;
                      int x3101 = x3096 + 1;
                      int x3102 = x3098[x3101];
                      int x3103 = x3102;
                      for (;;) {
                        int x3104 = x3100;
                        bool x3105 = x3104 != -1;
                        bool x3137 = x3105;
                        if (x3105) {
                          int x3106 = x3103;
                          bool x3107 = x3106 != x3079;
                          bool x3133 = x3107;
                          if (x3107 == false) {
                            int x3108 = x3100;
                            int* x3109 = x2731;
                            int x3110 = x3109[x3108];
                            bool x3129 = x3110 == x3056;
                            bool x3130 = !x3129;
                            x3133 = x3130;
                          }
                          bool x3134 = x3133;
                          x3137 = x3134;
                        }
                        bool x3138 = x3137;
                        if (!x3138) break;
                        int x3141 = x3097;
                        int x3142 = x3141 + 2;
                        int x3143 = x3142 & x3095;
                        x3097 = x3143;
                        int* x3145 = x2753;
                        int x3146 = x3145[x3143];
                        x3100 = x3146;
                        int x3148 = x3143 + 1;
                        int x3149 = x3145[x3148];
                        x3103 = x3149;
                      }
                      int x3154 = x3100;
                      bool x3155 = x3154 == -1;
                      int x3230;
                      if (x3155) {
                        int x3156 = x2751;
                        int x3157 = x3097;
                        x3098[x3157] = x3156;
                        int x3159 = x3157 + 1;
                        x3098[x3159] = x3079;
                        x2751 = x2751 + 1;
                        int x3162 = x2729;
                        int x3163 = x2728;
                        bool x3164 = x3162 == x3163;
                        if (x3164) {
                          int x3165 = x3163 * 4;
                          x2728 = x3165;
                          printf("buffer.resize %d\n",x3165);
                          int* x3168 = x2731;
                          int* x3169 = (int*)realloc(x3168,x3165 * sizeof(int));
                          x2731 = x3169;
                          printf("buffer.resize %d\n",x3165);
                          double* x3172 = x2733;
                          double* x3173 = (double*)realloc(x3172,x3165 * sizeof(double));
                          x2733 = x3173;
                          double* x3175 = x2735;
                          double* x3176 = (double*)realloc(x3175,x3165 * sizeof(double));
                          x2735 = x3176;
                          char** x3178 = x2737;
                          char** x3179 = (char**)realloc(x3178,x3165 * sizeof(char*));
                          x2737 = x3179;
                          char** x3181 = x2739;
                          char** x3182 = (char**)realloc(x3181,x3165 * sizeof(char*));
                          x2739 = x3182;
                          char** x3184 = x2741;
                          char** x3185 = (char**)realloc(x3184,x3165 * sizeof(char*));
                          x2741 = x3185;
                          char** x3187 = x2743;
                          char** x3188 = (char**)realloc(x3187,x3165 * sizeof(char*));
                          x2743 = x3188;
                          char** x3190 = x2745;
                          char** x3191 = (char**)realloc(x3190,x3165 * sizeof(char*));
                          x2745 = x3191;
                          int* x3193 = x2747;
                          int* x3194 = (int*)realloc(x3193,x3165 * sizeof(int));
                          x2747 = x3194;
                          char** x3196 = x2749;
                          char** x3197 = (char**)realloc(x3196,x3165 * sizeof(char*));
                          x2749 = x3197;
                        } else {
                        }
                        int* x3201 = x2731;
                        x3201[x3162] = x3056;
                        double* x3203 = x2733;
                        x3203[x3162] = 1.0E100;
                        double* x3205 = x2735;
                        x3205[x3162] = 0.0;
                        char** x3207 = x2737;
                        x3207[x3162] = "";
                        char** x3209 = x2739;
                        x3209[x3162] = "";
                        char** x3211 = x2741;
                        x3211[x3162] = "";
                        char** x3213 = x2743;
                        x3213[x3162] = "";
                        char** x3215 = x2745;
                        x3215[x3162] = "";
                        int* x3217 = x2747;
                        x3217[x3162] = 0;
                        char** x3219 = x2749;
                        x3219[x3162] = "";
                        x2729 = x2729 + 1;
                        int x3222 = x2751;
                        int x3223 = x3222 * 4;
                        bool x3224 = x3223 > x3094;
                        if (x3224) {
                          printf("%s\n","ERROR: hash.resize not implemented");
                        } else {
                        }
                        x3230 = x3156;
                      } else {
                        x3230 = x3154;
                      }
                      int* x3231 = x2731;
                      int x3232 = x3231[x3230];
                      double* x3233 = x2733;
                      double x3234 = x3233[x3230];
                      double* x3235 = x2735;
                      double x3236 = x3235[x3230];
                      char** x3237 = x2737;
                      char* x3238 = x3237[x3230];
                      char** x3239 = x2739;
                      char* x3240 = x3239[x3230];
                      char** x3241 = x2741;
                      char* x3242 = x3241[x3230];
                      char** x3243 = x2743;
                      char* x3244 = x3243[x3230];
                      char** x3245 = x2745;
                      char* x3246 = x3245[x3230];
                      int* x3247 = x2747;
                      int x3248 = x3247[x3230];
                      char** x3249 = x2749;
                      char* x3250 = x3249[x3230];
                      double x3251 = x3234;
                      double x3252 = x3236;
                      char* x3253 = x3238;
                      char* x3254 = x3240;
                      char* x3255 = x3242;
                      char* x3256 = x3244;
                      char* x3257 = x3246;
                      int x3258 = x3248;
                      char* x3259 = x3250;
                      bool x3260 = x3001 <= x3234;
                      if (x3260) {
                        x3251 = x3001;
                        x3252 = x3024;
                        x3253 = x3016;
                        x3254 = x3018;
                        x3255 = x3022;
                        x3256 = x3026;
                        x3257 = x3040;
                        x3258 = x3056;
                        x3259 = x3060;
                      } else {
                      }
                      double x3272 = x3251;
                      double x3273 = x3252;
                      char* x3274 = x3253;
                      char* x3275 = x3254;
                      char* x3276 = x3255;
                      char* x3277 = x3256;
                      char* x3278 = x3257;
                      int x3279 = x3258;
                      char* x3280 = x3259;
                      x3231[x3230] = x3232;
                      x3233[x3230] = x3272;
                      x3235[x3230] = x3273;
                      x3237[x3230] = x3274;
                      x3239[x3230] = x3275;
                      x3241[x3230] = x3276;
                      x3243[x3230] = x3277;
                      x3245[x3230] = x3278;
                      x3247[x3230] = x3279;
                      x3249[x3230] = x3280;
                    } else {
                    }
                  }
                } else {
                }
              }
            } else {
            }
          }
        } else {
        }
      }
    }
    printf("(SUPPLIER X PARTSUPP): rightParent.next done\n");
    gettimeofday(&x2144, NULL);
    timeval_subtract(&x3321, &x2144, &x2143);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x3321.tv_sec * 1000) + (x3321.tv_usec/1000)));
    printf("(NATION X (SUPPLIER X PARTSUPP)): rightParent.next done\n");
    gettimeofday(&x2150, NULL);
    timeval_subtract(&x3326, &x2150, &x2149);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x3326.tv_sec * 1000) + (x3326.tv_usec/1000)));
    printf("(PART X (NATION X (SUPPLIER X PARTSUPP))): rightParent.next done\n");
    gettimeofday(&x2156, NULL);
    timeval_subtract(&x3331, &x2156, &x2155);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x3331.tv_sec * 1000) + (x3331.tv_usec/1000)));
    printf("(REGION X (PART X (NATION X (SUPPLIER X PARTSUPP)))): rightParent.next done\n");
    gettimeofday(&x2162, NULL);
    timeval_subtract(&x3336, &x2162, &x2161);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x3336.tv_sec * 1000) + (x3336.tv_usec/1000)));
    int x3338 = x2729;
    int x2167;
    for(x2167=0; x2167 < x3338; x2167++) {
      int* x3339 = x2731;
      int x3340 = x3339[x2167];
      double* x3341 = x2733;
      double x3342 = x3341[x2167];
      double* x3343 = x2735;
      double x3344 = x3343[x2167];
      char** x3345 = x2737;
      char* x3346 = x3345[x2167];
      char** x3347 = x2739;
      char* x3348 = x3347[x2167];
      char** x3349 = x2741;
      char* x3350 = x3349[x2167];
      char** x3351 = x2743;
      char* x3352 = x3351[x2167];
      char** x3353 = x2745;
      char* x3354 = x3353[x2167];
      int* x3355 = x2747;
      int x3356 = x3355[x2167];
      char** x3357 = x2749;
      char* x3358 = x3357[x2167];
      struct Anon1023322325* x3359 = (struct Anon1023322325*)malloc(sizeof(struct Anon1023322325));
      x3359->PS_SUPPLYCOST = x3342;
      x3359->S_ACCTBAL = x3344;
      x3359->S_NAME = x3346;
      x3359->S_ADDRESS = x3348;
      x3359->S_PHONE = x3350;
      x3359->S_COMMENT = x3352;
      x3359->N_NAME = x3354;
      x3359->P_PARTKEY = x3356;
      x3359->P_MFGR = x3358;
      struct Anon2131537536* x3360 = (struct Anon2131537536*)malloc(sizeof(struct Anon2131537536));
      x3360->key = x3340;
      x3360->wnd = x3359;
      g_tree_insert(x2636,x3360,x3360);; // x3361
    }
    for (;;) {
      int x3364 = g_tree_nnodes(x2636);
      bool x3365 = x3364 != 0;
      if (!x3365) break;
      struct Anon2131537536* x3367 = NULL;
      g_tree_foreach(x2636, (GTraverseFunc)x3408, &x3367);
      g_tree_remove(x2636,x3367);
      int x3369 = x2762;
      bool x3370 = x3369 < 100;
      bool x3371 = x3370 == false;
      if (x3371) {
      } else {
        struct Anon1023322325* x3374 = x3367->wnd;;
        double x3375 = x3374->S_ACCTBAL;;
        char* x3376 = x3374->S_NAME;;
        char* x3377 = x3374->N_NAME;;
        int x3378 = x3374->P_PARTKEY;;
        char* x3379 = x3374->P_MFGR;;
        char* x3380 = x3374->S_ADDRESS;;
        char* x3381 = x3374->S_PHONE;;
        char* x3382 = x3374->S_COMMENT;;
        printf("%.2f|%s|%s|%d|%s|%s|%s|%s\n",x3375,x3376,x3377,x3378,x3379,x3380,x3381,x3382);
        x2762 = x2762 + 1;
        x2764 = x2764 + 1;
      }
    }
    int x3391 = x2764;
    printf("(%d rows)\n",x3391);
    gettimeofday(&x2224, NULL);
    timeval_subtract(&x3395, &x2224, &x2223);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x3395.tv_sec * 1000) + (x3395.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
