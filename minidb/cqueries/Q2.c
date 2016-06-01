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

struct Anon1495587458 {
int key;
struct Anon1023322325 wnd;
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

struct Anon0 {
struct Anon1866483359 left;
struct Anon327816002 right;
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

struct Anon625264174 {
char L_RETURNFLAG;
char L_LINESTATUS;
};

struct Anon631953537 {
struct Anon625264174 key;
struct Anon1296044246 aggs;
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

struct Anon600063274 {
bool exists;
struct Anon625264174 key;
struct Anon567626277 aggs;
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
int x2794(struct Anon1495587458* x2759, struct Anon1495587458* x2760);
int x2794(struct Anon1495587458* x2759, struct Anon1495587458* x2760) {
  struct Anon1495587458 x2761 = (*x2759);
  struct Anon1495587458 x2762 = (*x2760);
  struct Anon1023322325 x2763 = x2761.wnd;;
  double x2764 = x2763.S_ACCTBAL;;
  struct Anon1023322325 x2765 = x2762.wnd;;
  double x2766 = x2765.S_ACCTBAL;;
  bool x2767 = x2764 < x2766;
  int x2792;
  if (x2767) {
    x2792 = 1;
  } else {
    bool x2768 = x2764 > x2766;
    int x2791;
    if (x2768) {
      x2791 = -1;
    } else {
      char* x2769 = x2763.N_NAME;;
      char* x2770 = x2765.N_NAME;;
      int x2771 = tpch_strcmp(x2769,x2770);
      int x2772 = x2771;
      bool x2773 = x2771 == 0;
      if (x2773) {
        char* x2774 = x2763.S_NAME;;
        char* x2775 = x2765.S_NAME;;
        int x2776 = tpch_strcmp(x2774,x2775);
        x2772 = x2776;
        bool x2778 = x2776 == 0;
        if (x2778) {
          int x2779 = x2763.P_PARTKEY;;
          int x2780 = x2765.P_PARTKEY;;
          int x2781 = x2779 - x2780;
          x2772 = x2781;
        } else {
        }
      } else {
      }
      int x2788 = x2772;
      x2791 = x2788;
    }
    x2792 = x2791;
  }
  return x2792;
}

/************************ MAIN BODY **************************/
int main(int x1074, char** x1075) {
  long x1079 = 0L;
  long x7 = DEFAULT_INPUT_SIZE;
  long x1080 = x7;
  long x1081 = 0L;
  int* x1082 = (int*)malloc(x7 * sizeof(int));
  int* x1083 = x1082;
  char** x1086 = (char**)malloc(x7 * sizeof(char*));
  char** x1087 = x1086;
  char** x1090 = (char**)malloc(x7 * sizeof(char*));
  char** x1091 = x1090;
  int* x1092 = (int*)malloc(x7 * sizeof(int));
  int* x1093 = x1092;
  int x1076 = open("XXXXXpart.tbl",0);
  long x1077 = fsize(x1076);
  char* x1078 = mmap(0, x1077, PROT_READ, MAP_FILE | MAP_SHARED, x1076, 0);
  for (;;) {
    long x1101 = x1079;
    bool x1102 = x1101 < x1077;
    if (!x1102) break;
    int x1105 = 0;
    for (;;) {
      long x1106 = x1079;
      char x1107 = x1078[x1106];
      bool x1108 = x1107 != '|';
      bool x1113 = x1108;
      if (x1108) {
        long x1109 = x1079;
        char x1110 = x1078[x1109];
        bool x1111 = x1110 != '\n';
        x1113 = x1111;
      }
      bool x1114 = x1113;
      if (!x1114) break;
      int x1116 = x1105;
      long x1118 = x1079;
      int x1117 = x1116 * 10;
      char x1119 = x1078[x1118];
      char x1120 = x1119 - '0';
      int x1121 = x1117 + x1120;
      x1105 = x1121;
      x1079 = x1079 + 1;
    }
    x1079 = x1079 + 1;
    int x1127 = x1105;
    for (;;) {
      long x1129 = x1079;
      char x1130 = x1078[x1129];
      bool x1131 = x1130 != '|';
      bool x1136 = x1131;
      if (x1131) {
        long x1132 = x1079;
        char x1133 = x1078[x1132];
        bool x1134 = x1133 != '\n';
        x1136 = x1134;
      }
      bool x1137 = x1136;
      if (!x1137) break;
      x1079 = x1079 + 1;
    }
    x1079 = x1079 + 1;
    long x1146 = x1079;
    for (;;) {
      long x1147 = x1079;
      char x1148 = x1078[x1147];
      bool x1149 = x1148 != '|';
      bool x1154 = x1149;
      if (x1149) {
        long x1150 = x1079;
        char x1151 = x1078[x1150];
        bool x1152 = x1151 != '\n';
        x1154 = x1152;
      }
      bool x1155 = x1154;
      if (!x1155) break;
      x1079 = x1079 + 1;
    }
    x1079 = x1079 + 1;
    for (;;) {
      long x1165 = x1079;
      char x1166 = x1078[x1165];
      bool x1167 = x1166 != '|';
      bool x1172 = x1167;
      if (x1167) {
        long x1168 = x1079;
        char x1169 = x1078[x1168];
        bool x1170 = x1169 != '\n';
        x1172 = x1170;
      }
      bool x1173 = x1172;
      if (!x1173) break;
      x1079 = x1079 + 1;
    }
    x1079 = x1079 + 1;
    long x1182 = x1079;
    for (;;) {
      long x1183 = x1079;
      char x1184 = x1078[x1183];
      bool x1185 = x1184 != '|';
      bool x1190 = x1185;
      if (x1185) {
        long x1186 = x1079;
        char x1187 = x1078[x1186];
        bool x1188 = x1187 != '\n';
        x1190 = x1188;
      }
      bool x1191 = x1190;
      if (!x1191) break;
      x1079 = x1079 + 1;
    }
    x1079 = x1079 + 1;
    int x1201 = 0;
    for (;;) {
      long x1202 = x1079;
      char x1203 = x1078[x1202];
      bool x1204 = x1203 != '|';
      bool x1209 = x1204;
      if (x1204) {
        long x1205 = x1079;
        char x1206 = x1078[x1205];
        bool x1207 = x1206 != '\n';
        x1209 = x1207;
      }
      bool x1210 = x1209;
      if (!x1210) break;
      int x1212 = x1201;
      long x1214 = x1079;
      int x1213 = x1212 * 10;
      char x1215 = x1078[x1214];
      char x1216 = x1215 - '0';
      int x1217 = x1213 + x1216;
      x1201 = x1217;
      x1079 = x1079 + 1;
    }
    x1079 = x1079 + 1;
    int x1223 = x1201;
    for (;;) {
      long x1225 = x1079;
      char x1226 = x1078[x1225];
      bool x1227 = x1226 != '|';
      bool x1232 = x1227;
      if (x1227) {
        long x1228 = x1079;
        char x1229 = x1078[x1228];
        bool x1230 = x1229 != '\n';
        x1232 = x1230;
      }
      bool x1233 = x1232;
      if (!x1233) break;
      x1079 = x1079 + 1;
    }
    x1079 = x1079 + 1;
    for (;;) {
      long x1245 = x1079;
      char x1246 = x1078[x1245];
      bool x1247 = x1246 != '.';
      bool x1252 = x1247;
      if (x1247) {
        long x1248 = x1079;
        char x1249 = x1078[x1248];
        bool x1250 = x1249 != '|';
        x1252 = x1250;
      }
      bool x1253 = x1252;
      bool x1258 = x1253;
      if (x1253) {
        long x1254 = x1079;
        char x1255 = x1078[x1254];
        bool x1256 = x1255 != '\n';
        x1258 = x1256;
      }
      bool x1259 = x1258;
      if (!x1259) break;
      x1079 = x1079 + 1;
    }
    long x1271 = x1079;
    char x1272 = x1078[x1271];
    bool x1273 = x1272 == '.';
    if (x1273) {
      x1079 = x1079 + 1;
      for (;;) {
        long x1275 = x1079;
        char x1276 = x1078[x1275];
        bool x1277 = x1276 != '|';
        bool x1282 = x1277;
        if (x1277) {
          long x1278 = x1079;
          char x1279 = x1078[x1278];
          bool x1280 = x1279 != '\n';
          x1282 = x1280;
        }
        bool x1283 = x1282;
        if (!x1283) break;
        x1079 = x1079 + 1;
      }
    } else {
    }
    x1079 = x1079 + 1;
    for (;;) {
      long x1308 = x1079;
      char x1309 = x1078[x1308];
      bool x1310 = x1309 != '|';
      bool x1315 = x1310;
      if (x1310) {
        long x1311 = x1079;
        char x1312 = x1078[x1311];
        bool x1313 = x1312 != '\n';
        x1315 = x1313;
      }
      bool x1316 = x1315;
      if (!x1316) break;
      x1079 = x1079 + 1;
    }
    x1079 = x1079 + 1;
    long x1326 = x1079;
    bool x1327 = x1326 > 0L;
    bool x1333 = x1327;
    if (x1327) {
      long x1328 = x1079;
      long x1329 = x1328 - 1L;
      char x1330 = x1078[x1329];
      bool x1331 = x1330 != '\n';
      x1333 = x1331;
    }
    bool x1334 = x1333;
    if (x1334) {
      for (;;) {
        long x1335 = x1079;
        char x1336 = x1078[x1335];
        bool x1337 = x1336 != '\n';
        if (!x1337) break;
        x1079 = x1079 + 1;
      }
    } else {
    }
    x1079 = x1079 + 1;
    long x1346 = x1081;
    long x1347 = x1080;
    bool x1348 = x1346 == x1347;
    if (x1348) {
      long x1349 = x1347 * 4L;
      x1080 = x1349;
      printf("buffer.resize %ld\n",x1349);
      int* x1352 = x1083;
      int* x1353 = (int*)realloc(x1352,x1349 * sizeof(int));
      x1083 = x1353;
      char** x1358 = x1087;
      char** x1359 = (char**)realloc(x1358,x1349 * sizeof(char*));
      x1087 = x1359;
      char** x1364 = x1091;
      char** x1365 = (char**)realloc(x1364,x1349 * sizeof(char*));
      x1091 = x1365;
      int* x1367 = x1093;
      int* x1368 = (int*)realloc(x1367,x1349 * sizeof(int));
      x1093 = x1368;
    } else {
    }
    int* x1381 = x1083;
    x1381[x1346] = x1127;
    char** x1385 = x1087;
    char* x1163 = x1078+x1146;
    x1385[x1346] = x1163;
    char** x1389 = x1091;
    char* x1199 = x1078+x1182;
    x1389[x1346] = x1199;
    int* x1391 = x1093;
    x1391[x1346] = x1223;
    x1081 = x1081 + 1;
  }
  long x1405 = 0L;
  long x1406 = x7;
  long x1407 = 0L;
  int* x1408 = (int*)malloc(x7 * sizeof(int));
  int* x1409 = x1408;
  int* x1410 = (int*)malloc(x7 * sizeof(int));
  int* x1411 = x1410;
  double* x1414 = (double*)malloc(x7 * sizeof(double));
  double* x1415 = x1414;
  int x1402 = open("XXXXXpartsupp.tbl",0);
  long x1403 = fsize(x1402);
  char* x1404 = mmap(0, x1403, PROT_READ, MAP_FILE | MAP_SHARED, x1402, 0);
  for (;;) {
    long x1418 = x1405;
    bool x1419 = x1418 < x1403;
    if (!x1419) break;
    int x1422 = 0;
    for (;;) {
      long x1423 = x1405;
      char x1424 = x1404[x1423];
      bool x1425 = x1424 != '|';
      bool x1430 = x1425;
      if (x1425) {
        long x1426 = x1405;
        char x1427 = x1404[x1426];
        bool x1428 = x1427 != '\n';
        x1430 = x1428;
      }
      bool x1431 = x1430;
      if (!x1431) break;
      int x1433 = x1422;
      long x1435 = x1405;
      int x1434 = x1433 * 10;
      char x1436 = x1404[x1435];
      char x1437 = x1436 - '0';
      int x1438 = x1434 + x1437;
      x1422 = x1438;
      x1405 = x1405 + 1;
    }
    x1405 = x1405 + 1;
    int x1444 = x1422;
    int x1446 = 0;
    for (;;) {
      long x1447 = x1405;
      char x1448 = x1404[x1447];
      bool x1449 = x1448 != '|';
      bool x1454 = x1449;
      if (x1449) {
        long x1450 = x1405;
        char x1451 = x1404[x1450];
        bool x1452 = x1451 != '\n';
        x1454 = x1452;
      }
      bool x1455 = x1454;
      if (!x1455) break;
      int x1457 = x1446;
      long x1459 = x1405;
      int x1458 = x1457 * 10;
      char x1460 = x1404[x1459];
      char x1461 = x1460 - '0';
      int x1462 = x1458 + x1461;
      x1446 = x1462;
      x1405 = x1405 + 1;
    }
    x1405 = x1405 + 1;
    int x1468 = x1446;
    for (;;) {
      long x1471 = x1405;
      char x1472 = x1404[x1471];
      bool x1473 = x1472 != '|';
      bool x1478 = x1473;
      if (x1473) {
        long x1474 = x1405;
        char x1475 = x1404[x1474];
        bool x1476 = x1475 != '\n';
        x1478 = x1476;
      }
      bool x1479 = x1478;
      if (!x1479) break;
      x1405 = x1405 + 1;
    }
    x1405 = x1405 + 1;
    int x1494 = 0;
    int x1495 = 1;
    for (;;) {
      long x1496 = x1405;
      char x1497 = x1404[x1496];
      bool x1498 = x1497 != '.';
      bool x1503 = x1498;
      if (x1498) {
        long x1499 = x1405;
        char x1500 = x1404[x1499];
        bool x1501 = x1500 != '|';
        x1503 = x1501;
      }
      bool x1504 = x1503;
      bool x1509 = x1504;
      if (x1504) {
        long x1505 = x1405;
        char x1506 = x1404[x1505];
        bool x1507 = x1506 != '\n';
        x1509 = x1507;
      }
      bool x1510 = x1509;
      if (!x1510) break;
      int x1512 = x1494;
      long x1514 = x1405;
      int x1513 = x1512 * 10;
      char x1515 = x1404[x1514];
      char x1516 = x1515 - '0';
      int x1517 = x1513 + x1516;
      x1494 = x1517;
      x1405 = x1405 + 1;
    }
    long x1522 = x1405;
    char x1523 = x1404[x1522];
    bool x1524 = x1523 == '.';
    if (x1524) {
      x1405 = x1405 + 1;
      for (;;) {
        long x1526 = x1405;
        char x1527 = x1404[x1526];
        bool x1528 = x1527 != '|';
        bool x1533 = x1528;
        if (x1528) {
          long x1529 = x1405;
          char x1530 = x1404[x1529];
          bool x1531 = x1530 != '\n';
          x1533 = x1531;
        }
        bool x1534 = x1533;
        if (!x1534) break;
        int x1536 = x1494;
        long x1538 = x1405;
        int x1537 = x1536 * 10;
        char x1539 = x1404[x1538];
        char x1540 = x1539 - '0';
        int x1541 = x1537 + x1540;
        x1494 = x1541;
        int x1543 = x1495;
        int x1544 = x1543 * 10;
        x1495 = x1544;
        x1405 = x1405 + 1;
      }
    } else {
    }
    x1405 = x1405 + 1;
    int x1553 = x1494;
    int x1555 = x1495;
    for (;;) {
      long x1559 = x1405;
      char x1560 = x1404[x1559];
      bool x1561 = x1560 != '|';
      bool x1566 = x1561;
      if (x1561) {
        long x1562 = x1405;
        char x1563 = x1404[x1562];
        bool x1564 = x1563 != '\n';
        x1566 = x1564;
      }
      bool x1567 = x1566;
      if (!x1567) break;
      x1405 = x1405 + 1;
    }
    x1405 = x1405 + 1;
    long x1577 = x1405;
    bool x1578 = x1577 > 0L;
    bool x1584 = x1578;
    if (x1578) {
      long x1579 = x1405;
      long x1580 = x1579 - 1L;
      char x1581 = x1404[x1580];
      bool x1582 = x1581 != '\n';
      x1584 = x1582;
    }
    bool x1585 = x1584;
    if (x1585) {
      for (;;) {
        long x1586 = x1405;
        char x1587 = x1404[x1586];
        bool x1588 = x1587 != '\n';
        if (!x1588) break;
        x1405 = x1405 + 1;
      }
    } else {
    }
    x1405 = x1405 + 1;
    long x1597 = x1407;
    long x1598 = x1406;
    bool x1599 = x1597 == x1598;
    if (x1599) {
      long x1600 = x1598 * 4L;
      x1406 = x1600;
      printf("buffer.resize %ld\n",x1600);
      int* x1603 = x1409;
      int* x1604 = (int*)realloc(x1603,x1600 * sizeof(int));
      x1409 = x1604;
      int* x1606 = x1411;
      int* x1607 = (int*)realloc(x1606,x1600 * sizeof(int));
      x1411 = x1607;
      double* x1612 = x1415;
      double* x1613 = (double*)realloc(x1612,x1600 * sizeof(double));
      x1415 = x1613;
    } else {
    }
    int* x1620 = x1409;
    x1620[x1597] = x1444;
    int* x1622 = x1411;
    x1622[x1597] = x1468;
    double* x1626 = x1415;
    double x1554 = (double)x1553;
    double x1556 = (double)x1555;
    double x1557 = x1554 / x1556;
    x1626[x1597] = x1557;
    x1407 = x1407 + 1;
  }
  long x1636 = 0L;
  long x1637 = x7;
  long x1638 = 0L;
  int* x1639 = (int*)malloc(x7 * sizeof(int));
  int* x1640 = x1639;
  char** x1641 = (char**)malloc(x7 * sizeof(char*));
  char** x1642 = x1641;
  int* x1643 = (int*)malloc(x7 * sizeof(int));
  int* x1644 = x1643;
  int x1633 = open("XXXXXnation.tbl",0);
  long x1634 = fsize(x1633);
  char* x1635 = mmap(0, x1634, PROT_READ, MAP_FILE | MAP_SHARED, x1633, 0);
  for (;;) {
    long x1647 = x1636;
    bool x1648 = x1647 < x1634;
    if (!x1648) break;
    int x1651 = 0;
    for (;;) {
      long x1652 = x1636;
      char x1653 = x1635[x1652];
      bool x1654 = x1653 != '|';
      bool x1659 = x1654;
      if (x1654) {
        long x1655 = x1636;
        char x1656 = x1635[x1655];
        bool x1657 = x1656 != '\n';
        x1659 = x1657;
      }
      bool x1660 = x1659;
      if (!x1660) break;
      int x1662 = x1651;
      long x1664 = x1636;
      int x1663 = x1662 * 10;
      char x1665 = x1635[x1664];
      char x1666 = x1665 - '0';
      int x1667 = x1663 + x1666;
      x1651 = x1667;
      x1636 = x1636 + 1;
    }
    x1636 = x1636 + 1;
    int x1673 = x1651;
    long x1674 = x1636;
    for (;;) {
      long x1675 = x1636;
      char x1676 = x1635[x1675];
      bool x1677 = x1676 != '|';
      bool x1682 = x1677;
      if (x1677) {
        long x1678 = x1636;
        char x1679 = x1635[x1678];
        bool x1680 = x1679 != '\n';
        x1682 = x1680;
      }
      bool x1683 = x1682;
      if (!x1683) break;
      x1636 = x1636 + 1;
    }
    x1636 = x1636 + 1;
    int x1693 = 0;
    for (;;) {
      long x1694 = x1636;
      char x1695 = x1635[x1694];
      bool x1696 = x1695 != '|';
      bool x1701 = x1696;
      if (x1696) {
        long x1697 = x1636;
        char x1698 = x1635[x1697];
        bool x1699 = x1698 != '\n';
        x1701 = x1699;
      }
      bool x1702 = x1701;
      if (!x1702) break;
      int x1704 = x1693;
      long x1706 = x1636;
      int x1705 = x1704 * 10;
      char x1707 = x1635[x1706];
      char x1708 = x1707 - '0';
      int x1709 = x1705 + x1708;
      x1693 = x1709;
      x1636 = x1636 + 1;
    }
    x1636 = x1636 + 1;
    int x1715 = x1693;
    for (;;) {
      long x1717 = x1636;
      char x1718 = x1635[x1717];
      bool x1719 = x1718 != '|';
      bool x1724 = x1719;
      if (x1719) {
        long x1720 = x1636;
        char x1721 = x1635[x1720];
        bool x1722 = x1721 != '\n';
        x1724 = x1722;
      }
      bool x1725 = x1724;
      if (!x1725) break;
      x1636 = x1636 + 1;
    }
    x1636 = x1636 + 1;
    long x1735 = x1636;
    bool x1736 = x1735 > 0L;
    bool x1742 = x1736;
    if (x1736) {
      long x1737 = x1636;
      long x1738 = x1737 - 1L;
      char x1739 = x1635[x1738];
      bool x1740 = x1739 != '\n';
      x1742 = x1740;
    }
    bool x1743 = x1742;
    if (x1743) {
      for (;;) {
        long x1744 = x1636;
        char x1745 = x1635[x1744];
        bool x1746 = x1745 != '\n';
        if (!x1746) break;
        x1636 = x1636 + 1;
      }
    } else {
    }
    x1636 = x1636 + 1;
    long x1755 = x1638;
    long x1756 = x1637;
    bool x1757 = x1755 == x1756;
    if (x1757) {
      long x1758 = x1756 * 4L;
      x1637 = x1758;
      printf("buffer.resize %ld\n",x1758);
      int* x1761 = x1640;
      int* x1762 = (int*)realloc(x1761,x1758 * sizeof(int));
      x1640 = x1762;
      char** x1764 = x1642;
      char** x1765 = (char**)realloc(x1764,x1758 * sizeof(char*));
      x1642 = x1765;
      int* x1767 = x1644;
      int* x1768 = (int*)realloc(x1767,x1758 * sizeof(int));
      x1644 = x1768;
    } else {
    }
    int* x1775 = x1640;
    x1775[x1755] = x1673;
    char** x1777 = x1642;
    char* x1691 = x1635+x1674;
    x1777[x1755] = x1691;
    int* x1779 = x1644;
    x1779[x1755] = x1715;
    x1638 = x1638 + 1;
  }
  long x1789 = 0L;
  long x1790 = x7;
  long x1791 = 0L;
  int* x1792 = (int*)malloc(x7 * sizeof(int));
  int* x1793 = x1792;
  char** x1794 = (char**)malloc(x7 * sizeof(char*));
  char** x1795 = x1794;
  int x1786 = open("XXXXXregion.tbl",0);
  long x1787 = fsize(x1786);
  char* x1788 = mmap(0, x1787, PROT_READ, MAP_FILE | MAP_SHARED, x1786, 0);
  for (;;) {
    long x1798 = x1789;
    bool x1799 = x1798 < x1787;
    if (!x1799) break;
    int x1802 = 0;
    for (;;) {
      long x1803 = x1789;
      char x1804 = x1788[x1803];
      bool x1805 = x1804 != '|';
      bool x1810 = x1805;
      if (x1805) {
        long x1806 = x1789;
        char x1807 = x1788[x1806];
        bool x1808 = x1807 != '\n';
        x1810 = x1808;
      }
      bool x1811 = x1810;
      if (!x1811) break;
      int x1813 = x1802;
      long x1815 = x1789;
      int x1814 = x1813 * 10;
      char x1816 = x1788[x1815];
      char x1817 = x1816 - '0';
      int x1818 = x1814 + x1817;
      x1802 = x1818;
      x1789 = x1789 + 1;
    }
    x1789 = x1789 + 1;
    int x1824 = x1802;
    long x1825 = x1789;
    for (;;) {
      long x1826 = x1789;
      char x1827 = x1788[x1826];
      bool x1828 = x1827 != '|';
      bool x1833 = x1828;
      if (x1828) {
        long x1829 = x1789;
        char x1830 = x1788[x1829];
        bool x1831 = x1830 != '\n';
        x1833 = x1831;
      }
      bool x1834 = x1833;
      if (!x1834) break;
      x1789 = x1789 + 1;
    }
    x1789 = x1789 + 1;
    for (;;) {
      long x1844 = x1789;
      char x1845 = x1788[x1844];
      bool x1846 = x1845 != '|';
      bool x1851 = x1846;
      if (x1846) {
        long x1847 = x1789;
        char x1848 = x1788[x1847];
        bool x1849 = x1848 != '\n';
        x1851 = x1849;
      }
      bool x1852 = x1851;
      if (!x1852) break;
      x1789 = x1789 + 1;
    }
    x1789 = x1789 + 1;
    long x1862 = x1789;
    bool x1863 = x1862 > 0L;
    bool x1869 = x1863;
    if (x1863) {
      long x1864 = x1789;
      long x1865 = x1864 - 1L;
      char x1866 = x1788[x1865];
      bool x1867 = x1866 != '\n';
      x1869 = x1867;
    }
    bool x1870 = x1869;
    if (x1870) {
      for (;;) {
        long x1871 = x1789;
        char x1872 = x1788[x1871];
        bool x1873 = x1872 != '\n';
        if (!x1873) break;
        x1789 = x1789 + 1;
      }
    } else {
    }
    x1789 = x1789 + 1;
    long x1882 = x1791;
    long x1883 = x1790;
    bool x1884 = x1882 == x1883;
    if (x1884) {
      long x1885 = x1883 * 4L;
      x1790 = x1885;
      printf("buffer.resize %ld\n",x1885);
      int* x1888 = x1793;
      int* x1889 = (int*)realloc(x1888,x1885 * sizeof(int));
      x1793 = x1889;
      char** x1891 = x1795;
      char** x1892 = (char**)realloc(x1891,x1885 * sizeof(char*));
      x1795 = x1892;
    } else {
    }
    int* x1899 = x1793;
    x1899[x1882] = x1824;
    char** x1901 = x1795;
    char* x1842 = x1788+x1825;
    x1901[x1882] = x1842;
    x1791 = x1791 + 1;
  }
  long x1911 = 0L;
  long x1912 = x7;
  long x1913 = 0L;
  int* x1914 = (int*)malloc(x7 * sizeof(int));
  int* x1915 = x1914;
  char** x1916 = (char**)malloc(x7 * sizeof(char*));
  char** x1917 = x1916;
  char** x1918 = (char**)malloc(x7 * sizeof(char*));
  char** x1919 = x1918;
  int* x1920 = (int*)malloc(x7 * sizeof(int));
  int* x1921 = x1920;
  char** x1922 = (char**)malloc(x7 * sizeof(char*));
  char** x1923 = x1922;
  double* x1924 = (double*)malloc(x7 * sizeof(double));
  double* x1925 = x1924;
  char** x1926 = (char**)malloc(x7 * sizeof(char*));
  char** x1927 = x1926;
  int x1908 = open("XXXXXsupplier.tbl",0);
  long x1909 = fsize(x1908);
  char* x1910 = mmap(0, x1909, PROT_READ, MAP_FILE | MAP_SHARED, x1908, 0);
  for (;;) {
    long x1928 = x1911;
    bool x1929 = x1928 < x1909;
    if (!x1929) break;
    int x1932 = 0;
    for (;;) {
      long x1933 = x1911;
      char x1934 = x1910[x1933];
      bool x1935 = x1934 != '|';
      bool x1940 = x1935;
      if (x1935) {
        long x1936 = x1911;
        char x1937 = x1910[x1936];
        bool x1938 = x1937 != '\n';
        x1940 = x1938;
      }
      bool x1941 = x1940;
      if (!x1941) break;
      int x1943 = x1932;
      long x1945 = x1911;
      int x1944 = x1943 * 10;
      char x1946 = x1910[x1945];
      char x1947 = x1946 - '0';
      int x1948 = x1944 + x1947;
      x1932 = x1948;
      x1911 = x1911 + 1;
    }
    x1911 = x1911 + 1;
    int x1954 = x1932;
    long x1955 = x1911;
    for (;;) {
      long x1956 = x1911;
      char x1957 = x1910[x1956];
      bool x1958 = x1957 != '|';
      bool x1963 = x1958;
      if (x1958) {
        long x1959 = x1911;
        char x1960 = x1910[x1959];
        bool x1961 = x1960 != '\n';
        x1963 = x1961;
      }
      bool x1964 = x1963;
      if (!x1964) break;
      x1911 = x1911 + 1;
    }
    x1911 = x1911 + 1;
    long x1973 = x1911;
    for (;;) {
      long x1974 = x1911;
      char x1975 = x1910[x1974];
      bool x1976 = x1975 != '|';
      bool x1981 = x1976;
      if (x1976) {
        long x1977 = x1911;
        char x1978 = x1910[x1977];
        bool x1979 = x1978 != '\n';
        x1981 = x1979;
      }
      bool x1982 = x1981;
      if (!x1982) break;
      x1911 = x1911 + 1;
    }
    x1911 = x1911 + 1;
    int x1992 = 0;
    for (;;) {
      long x1993 = x1911;
      char x1994 = x1910[x1993];
      bool x1995 = x1994 != '|';
      bool x2000 = x1995;
      if (x1995) {
        long x1996 = x1911;
        char x1997 = x1910[x1996];
        bool x1998 = x1997 != '\n';
        x2000 = x1998;
      }
      bool x2001 = x2000;
      if (!x2001) break;
      int x2003 = x1992;
      long x2005 = x1911;
      int x2004 = x2003 * 10;
      char x2006 = x1910[x2005];
      char x2007 = x2006 - '0';
      int x2008 = x2004 + x2007;
      x1992 = x2008;
      x1911 = x1911 + 1;
    }
    x1911 = x1911 + 1;
    int x2014 = x1992;
    long x2015 = x1911;
    for (;;) {
      long x2016 = x1911;
      char x2017 = x1910[x2016];
      bool x2018 = x2017 != '|';
      bool x2023 = x2018;
      if (x2018) {
        long x2019 = x1911;
        char x2020 = x1910[x2019];
        bool x2021 = x2020 != '\n';
        x2023 = x2021;
      }
      bool x2024 = x2023;
      if (!x2024) break;
      x1911 = x1911 + 1;
    }
    x1911 = x1911 + 1;
    int x2034 = 0;
    int x2035 = 1;
    for (;;) {
      long x2036 = x1911;
      char x2037 = x1910[x2036];
      bool x2038 = x2037 != '.';
      bool x2043 = x2038;
      if (x2038) {
        long x2039 = x1911;
        char x2040 = x1910[x2039];
        bool x2041 = x2040 != '|';
        x2043 = x2041;
      }
      bool x2044 = x2043;
      bool x2049 = x2044;
      if (x2044) {
        long x2045 = x1911;
        char x2046 = x1910[x2045];
        bool x2047 = x2046 != '\n';
        x2049 = x2047;
      }
      bool x2050 = x2049;
      if (!x2050) break;
      int x2052 = x2034;
      long x2054 = x1911;
      int x2053 = x2052 * 10;
      char x2055 = x1910[x2054];
      char x2056 = x2055 - '0';
      int x2057 = x2053 + x2056;
      x2034 = x2057;
      x1911 = x1911 + 1;
    }
    long x2062 = x1911;
    char x2063 = x1910[x2062];
    bool x2064 = x2063 == '.';
    if (x2064) {
      x1911 = x1911 + 1;
      for (;;) {
        long x2066 = x1911;
        char x2067 = x1910[x2066];
        bool x2068 = x2067 != '|';
        bool x2073 = x2068;
        if (x2068) {
          long x2069 = x1911;
          char x2070 = x1910[x2069];
          bool x2071 = x2070 != '\n';
          x2073 = x2071;
        }
        bool x2074 = x2073;
        if (!x2074) break;
        int x2076 = x2034;
        long x2078 = x1911;
        int x2077 = x2076 * 10;
        char x2079 = x1910[x2078];
        char x2080 = x2079 - '0';
        int x2081 = x2077 + x2080;
        x2034 = x2081;
        int x2083 = x2035;
        int x2084 = x2083 * 10;
        x2035 = x2084;
        x1911 = x1911 + 1;
      }
    } else {
    }
    x1911 = x1911 + 1;
    int x2093 = x2034;
    int x2095 = x2035;
    long x2098 = x1911;
    for (;;) {
      long x2099 = x1911;
      char x2100 = x1910[x2099];
      bool x2101 = x2100 != '|';
      bool x2106 = x2101;
      if (x2101) {
        long x2102 = x1911;
        char x2103 = x1910[x2102];
        bool x2104 = x2103 != '\n';
        x2106 = x2104;
      }
      bool x2107 = x2106;
      if (!x2107) break;
      x1911 = x1911 + 1;
    }
    x1911 = x1911 + 1;
    long x2117 = x1911;
    bool x2118 = x2117 > 0L;
    bool x2124 = x2118;
    if (x2118) {
      long x2119 = x1911;
      long x2120 = x2119 - 1L;
      char x2121 = x1910[x2120];
      bool x2122 = x2121 != '\n';
      x2124 = x2122;
    }
    bool x2125 = x2124;
    if (x2125) {
      for (;;) {
        long x2126 = x1911;
        char x2127 = x1910[x2126];
        bool x2128 = x2127 != '\n';
        if (!x2128) break;
        x1911 = x1911 + 1;
      }
    } else {
    }
    x1911 = x1911 + 1;
    long x2137 = x1913;
    long x2138 = x1912;
    bool x2139 = x2137 == x2138;
    if (x2139) {
      long x2140 = x2138 * 4L;
      x1912 = x2140;
      printf("buffer.resize %ld\n",x2140);
      int* x2143 = x1915;
      int* x2144 = (int*)realloc(x2143,x2140 * sizeof(int));
      x1915 = x2144;
      char** x2146 = x1917;
      char** x2147 = (char**)realloc(x2146,x2140 * sizeof(char*));
      x1917 = x2147;
      char** x2149 = x1919;
      char** x2150 = (char**)realloc(x2149,x2140 * sizeof(char*));
      x1919 = x2150;
      int* x2152 = x1921;
      int* x2153 = (int*)realloc(x2152,x2140 * sizeof(int));
      x1921 = x2153;
      char** x2155 = x1923;
      char** x2156 = (char**)realloc(x2155,x2140 * sizeof(char*));
      x1923 = x2156;
      double* x2158 = x1925;
      double* x2159 = (double*)realloc(x2158,x2140 * sizeof(double));
      x1925 = x2159;
      char** x2161 = x1927;
      char** x2162 = (char**)realloc(x2161,x2140 * sizeof(char*));
      x1927 = x2162;
    } else {
    }
    int* x2166 = x1915;
    x2166[x2137] = x1954;
    char** x2168 = x1917;
    char* x1972 = x1910+x1955;
    x2168[x2137] = x1972;
    char** x2170 = x1919;
    char* x1990 = x1910+x1973;
    x2170[x2137] = x1990;
    int* x2172 = x1921;
    x2172[x2137] = x2014;
    char** x2174 = x1923;
    char* x2032 = x1910+x2015;
    x2174[x2137] = x2032;
    double* x2176 = x1925;
    double x2094 = (double)x2093;
    double x2096 = (double)x2095;
    double x2097 = x2094 / x2096;
    x2176[x2137] = x2097;
    char** x2178 = x1927;
    char* x2115 = x1910+x2098;
    x2178[x2137] = x2115;
    x1913 = x1913 + 1;
  }
  long x2189 = DEFAULT_JOIN_HASH_SIZE;
  long x808 = DEFAULT_AGG_HASH_SIZE ;
  long x2212 = x2189 - 1L;
  long x823 = x808 - 1L;
  int x2183;
  for(x2183=0; x2183 < 5; x2183++) {
    bool x2184 = false;
    long x2185 = 0L;
    bool x2186 = false;
    long x2187 = 0L;
    int* x2190 = (int*)malloc(x2189 * sizeof(int));
    int* x2191 = x2190;
    char** x2192 = (char**)malloc(x2189 * sizeof(char*));
    char** x2193 = x2192;
    char** x2194 = (char**)malloc(x2189 * sizeof(char*));
    char** x2195 = x2194;
    int* x2196 = (int*)malloc(x2189 * sizeof(int));
    int* x2197 = x2196;
    char** x2198 = (char**)malloc(x2189 * sizeof(char*));
    char** x2199 = x2198;
    double* x2200 = (double*)malloc(x2189 * sizeof(double));
    double* x2201 = x2200;
    char** x2202 = (char**)malloc(x2189 * sizeof(char*));
    char** x2203 = x2202;
    long x2204 = 0L;
    long* x2205 = (long*)malloc(x2189 * sizeof(long));
    long* x2206 = (long*)malloc(x2189 * sizeof(long));
    long x2208;
    for(x2208=0L; x2208 < x2189; x2208++) {
      x2205[x2208] = -1L;
    }
    bool x2214 = false;
    long x2215 = 0L;
    int* x2217 = (int*)malloc(x2189 * sizeof(int));
    int* x2218 = x2217;
    char** x2219 = (char**)malloc(x2189 * sizeof(char*));
    char** x2220 = x2219;
    int* x2221 = (int*)malloc(x2189 * sizeof(int));
    int* x2222 = x2221;
    long x2225 = 0L;
    long* x2226 = (long*)malloc(x2189 * sizeof(long));
    long* x2227 = (long*)malloc(x2189 * sizeof(long));
    long x2228;
    for(x2228=0L; x2228 < x2189; x2228++) {
      x2226[x2228] = -1L;
    }
    bool x2233 = false;
    long x2234 = 0L;
    int* x2237 = (int*)malloc(x2189 * sizeof(int));
    int* x2238 = x2237;
    char** x2241 = (char**)malloc(x2189 * sizeof(char*));
    char** x2242 = x2241;
    long x2255 = 0L;
    long* x2256 = (long*)malloc(x2189 * sizeof(long));
    long* x2257 = (long*)malloc(x2189 * sizeof(long));
    long x2258;
    for(x2258=0L; x2258 < x2189; x2258++) {
      x2256[x2258] = -1L;
    }
    bool x2263 = false;
    long x2264 = 0L;
    int* x2267 = (int*)malloc(x2189 * sizeof(int));
    int* x2268 = x2267;
    long x2273 = 0L;
    long* x2274 = (long*)malloc(x2189 * sizeof(long));
    long* x2275 = (long*)malloc(x2189 * sizeof(long));
    long x2276;
    for(x2276=0L; x2276 < x2189; x2276++) {
      x2274[x2276] = -1L;
    }
    struct Anon1052706553* x2283 = (struct Anon1052706553*)malloc(x808 * sizeof(struct Anon1052706553));
    struct Anon1052706553* x2284 = x2283;
    long x2285 = 0L;
    long* x2286 = (long*)malloc(x808 * sizeof(long));
    long x2287;
    for(x2287=0L; x2287 < x808; x2287++) {
      struct Anon1052706553* x2288 = x2284;
      struct Anon1052706553 x2289 = x2288[x2287];
      int x2290 = x2289.key;;
      struct Anon1023322325 x2291 = x2289.aggs;;
      struct Anon1052706553 x2292;
      x2292.exists = false;
      x2292.key = x2290;
      x2292.aggs = x2291;
      x2288[x2287] = x2292;
    }
    long x2298 = 1024L;
    long x2299 = 0L;
    struct Anon1495587458* x2300 = (struct Anon1495587458*)malloc(1024L * sizeof(struct Anon1495587458));
    struct Anon1495587458* x2301 = x2300;
    int x2302 = 0;
    long x2304 = 0L;
    struct timeval x2830, x2831, x2832;
    gettimeofday(&x2830, NULL);
    printf("%s\n","begin scan REGION");
    for (;;) {
      bool x2306 = x2263;
      bool x2307 = !x2306;
      bool x2312 = x2307;
      if (x2307) {
        long x2308 = x2264;
        long x2309 = x1791;
        bool x2310 = x2308 < x2309;
        x2312 = x2310;
      }
      bool x2313 = x2312;
      if (!x2313) break;
      long x2315 = x2264;
      int* x2316 = x1793;
      int x2317 = x2316[x2315];
      char** x2318 = x1795;
      char* x2319 = x2318[x2315];
      x2264 = x2264 + 1;
      bool x2324 = tpch_strcmp(x2319,"EUROPE") == 0;;
      if (x2324) {
        long x2325 = x2273;
        int* x2326 = x2268;
        x2326[x2325] = x2317;
        x2273 = x2273 + 1L;
        long x2333 = x2317 & x2212;
        long x2334 = x2274[x2333];
        x2274[x2333] = x2325;
        x2275[x2325] = x2334;
      } else {
      }
    }
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x2342 = x2233;
      bool x2343 = !x2342;
      bool x2348 = x2343;
      if (x2343) {
        long x2344 = x2234;
        long x2345 = x1081;
        bool x2346 = x2344 < x2345;
        x2348 = x2346;
      }
      bool x2349 = x2348;
      if (!x2349) break;
      long x2351 = x2234;
      int* x2352 = x1083;
      int x2353 = x2352[x2351];
      char** x2356 = x1087;
      char* x2357 = x2356[x2351];
      char** x2360 = x1091;
      char* x2361 = x2360[x2351];
      int* x2362 = x1093;
      int x2363 = x2362[x2351];
      x2234 = x2234 + 1;
      bool x2372 = x2363 == 15;
      bool x2376 = x2372;
      if (x2372) {
        int x2374 = tpch_strlen(x2361);
        int x2373 = tpch_strlen("BRASS");
        bool x2375 = strncmp(x2361+x2374-x2373,"BRASS", x2373) == 0;;
        x2376 = x2375;
      }
      bool x2377 = x2376;
      if (x2377) {
        long x2378 = x2255;
        int* x2379 = x2238;
        x2379[x2378] = x2353;
        char** x2383 = x2242;
        x2383[x2378] = x2357;
        x2255 = x2255 + 1L;
        long x2398 = x2353 & x2212;
        long x2399 = x2256[x2398];
        x2256[x2398] = x2378;
        x2257[x2378] = x2399;
      } else {
      }
    }
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x2407 = x2214;
      bool x2408 = !x2407;
      bool x2413 = x2408;
      if (x2408) {
        long x2409 = x2215;
        long x2410 = x1638;
        bool x2411 = x2409 < x2410;
        x2413 = x2411;
      }
      bool x2414 = x2413;
      if (!x2414) break;
      long x2416 = x2215;
      int* x2417 = x1640;
      int x2418 = x2417[x2416];
      char** x2419 = x1642;
      char* x2420 = x2419[x2416];
      int* x2421 = x1644;
      int x2422 = x2421[x2416];
      x2215 = x2215 + 1;
      long x2427 = x2225;
      int* x2428 = x2218;
      x2428[x2427] = x2418;
      char** x2430 = x2220;
      x2430[x2427] = x2420;
      int* x2432 = x2222;
      x2432[x2427] = x2422;
      x2225 = x2225 + 1L;
      long x2437 = x2418 & x2212;
      long x2438 = x2226[x2437];
      x2226[x2437] = x2427;
      x2227[x2427] = x2438;
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x2444 = x2186;
      bool x2445 = !x2444;
      bool x2450 = x2445;
      if (x2445) {
        long x2446 = x2187;
        long x2447 = x1913;
        bool x2448 = x2446 < x2447;
        x2450 = x2448;
      }
      bool x2451 = x2450;
      if (!x2451) break;
      long x2453 = x2187;
      int* x2454 = x1915;
      int x2455 = x2454[x2453];
      char** x2456 = x1917;
      char* x2457 = x2456[x2453];
      char** x2458 = x1919;
      char* x2459 = x2458[x2453];
      int* x2460 = x1921;
      int x2461 = x2460[x2453];
      char** x2462 = x1923;
      char* x2463 = x2462[x2453];
      double* x2464 = x1925;
      double x2465 = x2464[x2453];
      char** x2466 = x1927;
      char* x2467 = x2466[x2453];
      x2187 = x2187 + 1;
      long x2470 = x2204;
      int* x2471 = x2191;
      x2471[x2470] = x2455;
      char** x2473 = x2193;
      x2473[x2470] = x2457;
      char** x2475 = x2195;
      x2475[x2470] = x2459;
      int* x2477 = x2197;
      x2477[x2470] = x2461;
      char** x2479 = x2199;
      x2479[x2470] = x2463;
      double* x2481 = x2201;
      x2481[x2470] = x2465;
      char** x2483 = x2203;
      x2483[x2470] = x2467;
      x2204 = x2204 + 1L;
      long x2486 = x2455 & x2212;
      long x2487 = x2205[x2486];
      x2205[x2486] = x2470;
      x2206[x2470] = x2487;
    }
    printf("%s\n","begin scan PARTSUPP");
    for (;;) {
      bool x2493 = x2184;
      bool x2494 = !x2493;
      bool x2499 = x2494;
      if (x2494) {
        long x2495 = x2185;
        long x2496 = x1407;
        bool x2497 = x2495 < x2496;
        x2499 = x2497;
      }
      bool x2500 = x2499;
      if (!x2500) break;
      long x2502 = x2185;
      int* x2503 = x1409;
      int x2504 = x2503[x2502];
      int* x2505 = x1411;
      int x2506 = x2505[x2502];
      double* x2509 = x1415;
      double x2510 = x2509[x2502];
      x2185 = x2185 + 1;
      long x2515 = x2506 & x2212;
      long x2516 = x2205[x2515];
      long x2517 = x2516;
      long x2563 = x2504 & x2212;
      bool x2677 = x2510 < 1.0E100;
      for (;;) {
        long x2518 = x2517;
        bool x2519 = x2518 != -1;
        if (!x2519) break;
        long x2521 = x2517;
        int* x2522 = x2191;
        int x2523 = x2522[x2521];
        char** x2524 = x2193;
        char* x2525 = x2524[x2521];
        char** x2526 = x2195;
        char* x2527 = x2526[x2521];
        int* x2528 = x2197;
        int x2529 = x2528[x2521];
        char** x2530 = x2199;
        char* x2531 = x2530[x2521];
        double* x2532 = x2201;
        double x2533 = x2532[x2521];
        char** x2534 = x2203;
        char* x2535 = x2534[x2521];
        long x2537 = x2206[x2521];
        x2517 = x2537;
        bool x2539 = x2523 == x2506;
        if (x2539) {
          long x2542 = x2529 & x2212;
          long x2543 = x2226[x2542];
          long x2544 = x2543;
          for (;;) {
            long x2545 = x2544;
            bool x2546 = x2545 != -1;
            if (!x2546) break;
            long x2548 = x2544;
            int* x2549 = x2218;
            int x2550 = x2549[x2548];
            char** x2551 = x2220;
            char* x2552 = x2551[x2548];
            int* x2553 = x2222;
            int x2554 = x2553[x2548];
            long x2558 = x2227[x2548];
            x2544 = x2558;
            bool x2560 = x2550 == x2529;
            if (x2560) {
              long x2564 = x2256[x2563];
              long x2565 = x2564;
              long x2594 = x2554 & x2212;
              for (;;) {
                long x2566 = x2565;
                bool x2567 = x2566 != -1;
                if (!x2567) break;
                long x2569 = x2565;
                int* x2570 = x2238;
                int x2571 = x2570[x2569];
                char** x2574 = x2242;
                char* x2575 = x2574[x2569];
                long x2589 = x2257[x2569];
                x2565 = x2589;
                bool x2591 = x2571 == x2504;
                if (x2591) {
                  long x2595 = x2274[x2594];
                  long x2596 = x2595;
                  long x2613 = x2571 & x823;
                  struct Anon1023322325 x2612;
                  x2612.PS_SUPPLYCOST = x2510;
                  x2612.S_ACCTBAL = x2533;
                  x2612.S_NAME = x2525;
                  x2612.S_ADDRESS = x2527;
                  x2612.S_PHONE = x2531;
                  x2612.S_COMMENT = x2535;
                  x2612.N_NAME = x2552;
                  x2612.P_PARTKEY = x2571;
                  x2612.P_MFGR = x2575;
                  for (;;) {
                    long x2597 = x2596;
                    bool x2598 = x2597 != -1;
                    if (!x2598) break;
                    long x2600 = x2596;
                    int* x2601 = x2268;
                    int x2602 = x2601[x2600];
                    long x2608 = x2275[x2600];
                    x2596 = x2608;
                    bool x2610 = x2602 == x2554;
                    if (x2610) {
                      long x2614 = x2613;
                      struct Anon1052706553* x2615 = x2284;
                      struct Anon1052706553 x2616 = x2615[x2613];
                      struct Anon1052706553 x2617 = x2616;
                      bool x2618 = x2616.exists;;
                      bool x2623 = x2618;
                      if (x2618) {
                        struct Anon1052706553 x2619 = x2617;
                        int x2620 = x2619.key;;
                        bool x2621 = x2620 == x2571;
                        x2623 = x2621;
                      }
                      bool x2624 = x2623;
                      if (x2624) {
                        struct Anon1023322325 x2625 = x2616.aggs;;
                        struct Anon1023322325 x2626 = x2625;
                        double x2627 = x2625.PS_SUPPLYCOST;;
                        bool x2628 = x2510 < x2627;
                        if (x2628) {
                          x2626 = x2612;
                        } else {
                        }
                        struct Anon1023322325 x2632 = x2626;
                        int x2633 = x2616.key;;
                        struct Anon1052706553 x2634;
                        x2634.exists = true;
                        x2634.key = x2633;
                        x2634.aggs = x2632;
                        x2615[x2613] = x2634;
                      } else {
                        for (;;) {
                          struct Anon1052706553 x2637 = x2617;
                          bool x2638 = x2637.exists;;
                          bool x2708;
                          if (x2638) {
                            int x2639 = x2637.key;;
                            bool x2640 = x2639 == x2571;
                            bool x2664;
                            if (x2640) {
                              struct Anon1023322325 x2641 = x2637.aggs;;
                              struct Anon1023322325 x2642 = x2641;
                              double x2643 = x2641.PS_SUPPLYCOST;;
                              bool x2644 = x2510 < x2643;
                              if (x2644) {
                                x2642 = x2612;
                              } else {
                              }
                              struct Anon1023322325 x2648 = x2642;
                              long x2649 = x2614;
                              struct Anon1052706553* x2651 = x2284;
                              struct Anon1052706553 x2650;
                              x2650.exists = true;
                              x2650.key = x2639;
                              x2650.aggs = x2648;
                              x2651[x2649] = x2650;
                              x2664 = false;
                            } else {
                              long x2654 = x2614;
                              long x2655 = x2654 + 1L;
                              long x2656 = x2655 & x823;
                              x2614 = x2656;
                              struct Anon1052706553* x2658 = x2284;
                              struct Anon1052706553 x2659 = x2658[x2656];
                              x2617 = x2659;
                              x2664 = true;
                            }
                            x2708 = x2664;
                          } else {
                            long x2666 = x2614;
                            double x2667 = 1.0E100;
                            double x2668 = 0.0;
                            char* x2669 = "";
                            char* x2670 = "";
                            char* x2671 = "";
                            char* x2672 = "";
                            char* x2673 = "";
                            int x2674 = 0;
                            char* x2675 = "";
                            if (x2677) {
                              x2667 = x2510;
                              x2668 = x2533;
                              x2669 = x2525;
                              x2670 = x2527;
                              x2671 = x2531;
                              x2672 = x2535;
                              x2673 = x2552;
                              x2674 = x2571;
                              x2675 = x2575;
                            } else {
                            }
                            double x2689 = x2667;
                            double x2690 = x2668;
                            char* x2691 = x2669;
                            char* x2692 = x2670;
                            char* x2693 = x2671;
                            char* x2694 = x2672;
                            char* x2695 = x2673;
                            int x2696 = x2674;
                            char* x2697 = x2675;
                            struct Anon1052706553* x2700 = x2284;
                            struct Anon1023322325 x2698;
                            x2698.PS_SUPPLYCOST = x2689;
                            x2698.S_ACCTBAL = x2690;
                            x2698.S_NAME = x2691;
                            x2698.S_ADDRESS = x2692;
                            x2698.S_PHONE = x2693;
                            x2698.S_COMMENT = x2694;
                            x2698.N_NAME = x2695;
                            x2698.P_PARTKEY = x2696;
                            x2698.P_MFGR = x2697;
                            struct Anon1052706553 x2699;
                            x2699.exists = true;
                            x2699.key = x2571;
                            x2699.aggs = x2698;
                            x2700[x2666] = x2699;
                            long x2702 = x2285;
                            x2286[x2702] = x2666;
                            x2285 = x2285 + 1L;
                            x2708 = false;
                          }
                          if (!x2708) break;
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
        } else {
        }
      }
    }
    long x2733 = x2285;
    long x2735;
    for(x2735=0L; x2735 < x2733; x2735++) {
      long x2736 = x2286[x2735];
      struct Anon1052706553* x2737 = x2284;
      struct Anon1052706553 x2738 = x2737[x2736];
      int x2739 = x2738.key;;
      struct Anon1023322325 x2740 = x2738.aggs;;
      long x2742 = x2299;
      long x2743 = x2298;
      bool x2744 = x2742 == x2743;
      if (x2744) {
        long x2745 = x2743 * 4L;
        x2298 = x2745;
        struct Anon1495587458* x2747 = x2301;
        struct Anon1495587458* x2748 = (struct Anon1495587458 *)realloc(x2747,x2745* sizeof(struct Anon1495587458));
        x2301 = x2748;
      } else {
      }
      struct Anon1495587458* x2752 = x2301;
      struct Anon1495587458 x2741;
      x2741.key = x2739;
      x2741.wnd = x2740;
      x2752[x2742] = x2741;
      x2299 = x2299 + 1;
    }
    long x2757 = x2299;
    struct Anon1495587458* x2758 = x2301;
    qsort((void *)x2758,x2757,sizeof(struct Anon1495587458), (__compar_fn_t)x2794); // x2795
    long x2797;
    for(x2797=0L; x2797 < x2757; x2797++) {
      struct Anon1495587458* x2798 = x2301;
      struct Anon1495587458 x2799 = x2798[x2797];
      int x2800 = x2302;
      bool x2801 = x2800 < 100;
      bool x2802 = x2801 == false;
      if (x2802) {
      } else {
        struct Anon1023322325 x2805 = x2799.wnd;;
        double x2806 = x2805.S_ACCTBAL;;
        char* x2807 = x2805.S_NAME;;
        int x2808 = tpch_strlen(x2807);
        char* x2809 = x2805.N_NAME;;
        int x2810 = tpch_strlen(x2809);
        int x2811 = x2805.P_PARTKEY;;
        char* x2812 = x2805.P_MFGR;;
        int x2813 = tpch_strlen(x2812);
        char* x2814 = x2805.S_ADDRESS;;
        int x2815 = tpch_strlen(x2814);
        char* x2816 = x2805.S_PHONE;;
        int x2817 = tpch_strlen(x2816);
        char* x2818 = x2805.S_COMMENT;;
        int x2819 = tpch_strlen(x2818);
        printf("%.2f|%.*s|%.*s|%d|%.*s|%.*s|%.*s|%.*s\n",x2806,x2808,x2807,x2810,x2809,x2811,x2813,x2812,x2815,x2814,x2817,x2816,x2819,x2818);
        x2302 = x2302 + 1;
        x2304 = x2304 + 1L;
      }
    }
    long x2827 = x2304;
    printf("(%ld rows)\n",x2827);
    gettimeofday(&x2831, NULL);
    timeval_subtract(&x2832, &x2831, &x2830);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x2832.tv_sec * 1000) + (x2832.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
