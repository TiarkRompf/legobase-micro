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

struct Anon1285873738 {
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

struct Anon1519494783 {
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
int main(int x996, char** x997) {
  long x1001 = 0L;
  long x6 = DEFAULT_INPUT_SIZE;
  long x1002 = x6;
  long x1003 = 0L;
  int* x1004 = (int*)malloc(x6 * sizeof(int));
  int* x1005 = x1004;
  char** x1008 = (char**)malloc(x6 * sizeof(char*));
  char** x1009 = x1008;
  char** x1012 = (char**)malloc(x6 * sizeof(char*));
  char** x1013 = x1012;
  int* x1014 = (int*)malloc(x6 * sizeof(int));
  int* x1015 = x1014;
  int x998 = open("../databases/sf2/part.tbl",0);
  long x999 = fsize(x998);
  char* x1000 = mmap(0, x999, PROT_READ, MAP_FILE | MAP_SHARED, x998, 0);
  for (;;) {
    long x1023 = x1001;
    bool x1024 = x1023 < x999;
    if (!x1024) break;
    int x1027 = 0;
    for (;;) {
      long x1028 = x1001;
      char x1029 = x1000[x1028];
      bool x1030 = x1029 != '|';
      bool x1035 = x1030;
      if (x1030) {
        long x1031 = x1001;
        char x1032 = x1000[x1031];
        bool x1033 = x1032 != '\n';
        x1035 = x1033;
      }
      bool x1036 = x1035;
      if (!x1036) break;
      int x1038 = x1027;
      long x1040 = x1001;
      int x1039 = x1038 * 10;
      char x1041 = x1000[x1040];
      char x1042 = x1041 - '0';
      int x1043 = x1039 + x1042;
      x1027 = x1043;
      x1001 = x1001 + 1;
    }
    x1001 = x1001 + 1;
    int x1049 = x1027;
    for (;;) {
      long x1051 = x1001;
      char x1052 = x1000[x1051];
      bool x1053 = x1052 != '|';
      bool x1058 = x1053;
      if (x1053) {
        long x1054 = x1001;
        char x1055 = x1000[x1054];
        bool x1056 = x1055 != '\n';
        x1058 = x1056;
      }
      bool x1059 = x1058;
      if (!x1059) break;
      x1001 = x1001 + 1;
    }
    x1001 = x1001 + 1;
    long x1068 = x1001;
    for (;;) {
      long x1069 = x1001;
      char x1070 = x1000[x1069];
      bool x1071 = x1070 != '|';
      bool x1076 = x1071;
      if (x1071) {
        long x1072 = x1001;
        char x1073 = x1000[x1072];
        bool x1074 = x1073 != '\n';
        x1076 = x1074;
      }
      bool x1077 = x1076;
      if (!x1077) break;
      x1001 = x1001 + 1;
    }
    x1001 = x1001 + 1;
    for (;;) {
      long x1087 = x1001;
      char x1088 = x1000[x1087];
      bool x1089 = x1088 != '|';
      bool x1094 = x1089;
      if (x1089) {
        long x1090 = x1001;
        char x1091 = x1000[x1090];
        bool x1092 = x1091 != '\n';
        x1094 = x1092;
      }
      bool x1095 = x1094;
      if (!x1095) break;
      x1001 = x1001 + 1;
    }
    x1001 = x1001 + 1;
    long x1104 = x1001;
    for (;;) {
      long x1105 = x1001;
      char x1106 = x1000[x1105];
      bool x1107 = x1106 != '|';
      bool x1112 = x1107;
      if (x1107) {
        long x1108 = x1001;
        char x1109 = x1000[x1108];
        bool x1110 = x1109 != '\n';
        x1112 = x1110;
      }
      bool x1113 = x1112;
      if (!x1113) break;
      x1001 = x1001 + 1;
    }
    x1001 = x1001 + 1;
    int x1123 = 0;
    for (;;) {
      long x1124 = x1001;
      char x1125 = x1000[x1124];
      bool x1126 = x1125 != '|';
      bool x1131 = x1126;
      if (x1126) {
        long x1127 = x1001;
        char x1128 = x1000[x1127];
        bool x1129 = x1128 != '\n';
        x1131 = x1129;
      }
      bool x1132 = x1131;
      if (!x1132) break;
      int x1134 = x1123;
      long x1136 = x1001;
      int x1135 = x1134 * 10;
      char x1137 = x1000[x1136];
      char x1138 = x1137 - '0';
      int x1139 = x1135 + x1138;
      x1123 = x1139;
      x1001 = x1001 + 1;
    }
    x1001 = x1001 + 1;
    int x1145 = x1123;
    for (;;) {
      long x1147 = x1001;
      char x1148 = x1000[x1147];
      bool x1149 = x1148 != '|';
      bool x1154 = x1149;
      if (x1149) {
        long x1150 = x1001;
        char x1151 = x1000[x1150];
        bool x1152 = x1151 != '\n';
        x1154 = x1152;
      }
      bool x1155 = x1154;
      if (!x1155) break;
      x1001 = x1001 + 1;
    }
    x1001 = x1001 + 1;
    for (;;) {
      long x1167 = x1001;
      char x1168 = x1000[x1167];
      bool x1169 = x1168 != '.';
      bool x1174 = x1169;
      if (x1169) {
        long x1170 = x1001;
        char x1171 = x1000[x1170];
        bool x1172 = x1171 != '|';
        x1174 = x1172;
      }
      bool x1175 = x1174;
      bool x1180 = x1175;
      if (x1175) {
        long x1176 = x1001;
        char x1177 = x1000[x1176];
        bool x1178 = x1177 != '\n';
        x1180 = x1178;
      }
      bool x1181 = x1180;
      if (!x1181) break;
      x1001 = x1001 + 1;
    }
    long x1193 = x1001;
    char x1194 = x1000[x1193];
    bool x1195 = x1194 == '.';
    if (x1195) {
      x1001 = x1001 + 1;
      for (;;) {
        long x1197 = x1001;
        char x1198 = x1000[x1197];
        bool x1199 = x1198 != '|';
        bool x1204 = x1199;
        if (x1199) {
          long x1200 = x1001;
          char x1201 = x1000[x1200];
          bool x1202 = x1201 != '\n';
          x1204 = x1202;
        }
        bool x1205 = x1204;
        if (!x1205) break;
        x1001 = x1001 + 1;
      }
    } else {
    }
    x1001 = x1001 + 1;
    for (;;) {
      long x1230 = x1001;
      char x1231 = x1000[x1230];
      bool x1232 = x1231 != '|';
      bool x1237 = x1232;
      if (x1232) {
        long x1233 = x1001;
        char x1234 = x1000[x1233];
        bool x1235 = x1234 != '\n';
        x1237 = x1235;
      }
      bool x1238 = x1237;
      if (!x1238) break;
      x1001 = x1001 + 1;
    }
    x1001 = x1001 + 1;
    long x1248 = x1003;
    long x1249 = x1002;
    bool x1250 = x1248 == x1249;
    if (x1250) {
      long x1251 = x1249 * 4L;
      x1002 = x1251;
      printf("buffer.resize %d\n",x1251);
      int* x1254 = x1005;
      int* x1255 = (int*)realloc(x1254,x1251 * sizeof(int));
      x1005 = x1255;
      char** x1260 = x1009;
      char** x1261 = (char**)realloc(x1260,x1251 * sizeof(char*));
      x1009 = x1261;
      char** x1266 = x1013;
      char** x1267 = (char**)realloc(x1266,x1251 * sizeof(char*));
      x1013 = x1267;
      int* x1269 = x1015;
      int* x1270 = (int*)realloc(x1269,x1251 * sizeof(int));
      x1015 = x1270;
    } else {
    }
    int* x1283 = x1005;
    x1283[x1248] = x1049;
    char** x1287 = x1009;
    char* x1085 = x1000+x1068;
    x1287[x1248] = x1085;
    char** x1291 = x1013;
    char* x1121 = x1000+x1104;
    x1291[x1248] = x1121;
    int* x1293 = x1015;
    x1293[x1248] = x1145;
    x1003 = x1003 + 1;
  }
  long x1307 = 0L;
  long x1308 = x6;
  long x1309 = 0L;
  int* x1310 = (int*)malloc(x6 * sizeof(int));
  int* x1311 = x1310;
  int* x1312 = (int*)malloc(x6 * sizeof(int));
  int* x1313 = x1312;
  double* x1316 = (double*)malloc(x6 * sizeof(double));
  double* x1317 = x1316;
  int x1304 = open("../databases/sf2/partsupp.tbl",0);
  long x1305 = fsize(x1304);
  char* x1306 = mmap(0, x1305, PROT_READ, MAP_FILE | MAP_SHARED, x1304, 0);
  for (;;) {
    long x1320 = x1307;
    bool x1321 = x1320 < x1305;
    if (!x1321) break;
    int x1324 = 0;
    for (;;) {
      long x1325 = x1307;
      char x1326 = x1306[x1325];
      bool x1327 = x1326 != '|';
      bool x1332 = x1327;
      if (x1327) {
        long x1328 = x1307;
        char x1329 = x1306[x1328];
        bool x1330 = x1329 != '\n';
        x1332 = x1330;
      }
      bool x1333 = x1332;
      if (!x1333) break;
      int x1335 = x1324;
      long x1337 = x1307;
      int x1336 = x1335 * 10;
      char x1338 = x1306[x1337];
      char x1339 = x1338 - '0';
      int x1340 = x1336 + x1339;
      x1324 = x1340;
      x1307 = x1307 + 1;
    }
    x1307 = x1307 + 1;
    int x1346 = x1324;
    int x1348 = 0;
    for (;;) {
      long x1349 = x1307;
      char x1350 = x1306[x1349];
      bool x1351 = x1350 != '|';
      bool x1356 = x1351;
      if (x1351) {
        long x1352 = x1307;
        char x1353 = x1306[x1352];
        bool x1354 = x1353 != '\n';
        x1356 = x1354;
      }
      bool x1357 = x1356;
      if (!x1357) break;
      int x1359 = x1348;
      long x1361 = x1307;
      int x1360 = x1359 * 10;
      char x1362 = x1306[x1361];
      char x1363 = x1362 - '0';
      int x1364 = x1360 + x1363;
      x1348 = x1364;
      x1307 = x1307 + 1;
    }
    x1307 = x1307 + 1;
    int x1370 = x1348;
    for (;;) {
      long x1373 = x1307;
      char x1374 = x1306[x1373];
      bool x1375 = x1374 != '|';
      bool x1380 = x1375;
      if (x1375) {
        long x1376 = x1307;
        char x1377 = x1306[x1376];
        bool x1378 = x1377 != '\n';
        x1380 = x1378;
      }
      bool x1381 = x1380;
      if (!x1381) break;
      x1307 = x1307 + 1;
    }
    x1307 = x1307 + 1;
    int x1396 = 0;
    int x1397 = 1;
    for (;;) {
      long x1398 = x1307;
      char x1399 = x1306[x1398];
      bool x1400 = x1399 != '.';
      bool x1405 = x1400;
      if (x1400) {
        long x1401 = x1307;
        char x1402 = x1306[x1401];
        bool x1403 = x1402 != '|';
        x1405 = x1403;
      }
      bool x1406 = x1405;
      bool x1411 = x1406;
      if (x1406) {
        long x1407 = x1307;
        char x1408 = x1306[x1407];
        bool x1409 = x1408 != '\n';
        x1411 = x1409;
      }
      bool x1412 = x1411;
      if (!x1412) break;
      int x1414 = x1396;
      long x1416 = x1307;
      int x1415 = x1414 * 10;
      char x1417 = x1306[x1416];
      char x1418 = x1417 - '0';
      int x1419 = x1415 + x1418;
      x1396 = x1419;
      x1307 = x1307 + 1;
    }
    long x1424 = x1307;
    char x1425 = x1306[x1424];
    bool x1426 = x1425 == '.';
    if (x1426) {
      x1307 = x1307 + 1;
      for (;;) {
        long x1428 = x1307;
        char x1429 = x1306[x1428];
        bool x1430 = x1429 != '|';
        bool x1435 = x1430;
        if (x1430) {
          long x1431 = x1307;
          char x1432 = x1306[x1431];
          bool x1433 = x1432 != '\n';
          x1435 = x1433;
        }
        bool x1436 = x1435;
        if (!x1436) break;
        int x1438 = x1396;
        long x1440 = x1307;
        int x1439 = x1438 * 10;
        char x1441 = x1306[x1440];
        char x1442 = x1441 - '0';
        int x1443 = x1439 + x1442;
        x1396 = x1443;
        int x1445 = x1397;
        int x1446 = x1445 * 10;
        x1397 = x1446;
        x1307 = x1307 + 1;
      }
    } else {
    }
    x1307 = x1307 + 1;
    int x1455 = x1396;
    int x1457 = x1397;
    for (;;) {
      long x1461 = x1307;
      char x1462 = x1306[x1461];
      bool x1463 = x1462 != '|';
      bool x1468 = x1463;
      if (x1463) {
        long x1464 = x1307;
        char x1465 = x1306[x1464];
        bool x1466 = x1465 != '\n';
        x1468 = x1466;
      }
      bool x1469 = x1468;
      if (!x1469) break;
      x1307 = x1307 + 1;
    }
    x1307 = x1307 + 1;
    long x1479 = x1309;
    long x1480 = x1308;
    bool x1481 = x1479 == x1480;
    if (x1481) {
      long x1482 = x1480 * 4L;
      x1308 = x1482;
      printf("buffer.resize %d\n",x1482);
      int* x1485 = x1311;
      int* x1486 = (int*)realloc(x1485,x1482 * sizeof(int));
      x1311 = x1486;
      int* x1488 = x1313;
      int* x1489 = (int*)realloc(x1488,x1482 * sizeof(int));
      x1313 = x1489;
      double* x1494 = x1317;
      double* x1495 = (double*)realloc(x1494,x1482 * sizeof(double));
      x1317 = x1495;
    } else {
    }
    int* x1502 = x1311;
    x1502[x1479] = x1346;
    int* x1504 = x1313;
    x1504[x1479] = x1370;
    double* x1508 = x1317;
    double x1456 = (double)x1455;
    double x1458 = (double)x1457;
    double x1459 = x1456 / x1458;
    x1508[x1479] = x1459;
    x1309 = x1309 + 1;
  }
  long x1518 = 0L;
  long x1519 = x6;
  long x1520 = 0L;
  int* x1521 = (int*)malloc(x6 * sizeof(int));
  int* x1522 = x1521;
  char** x1523 = (char**)malloc(x6 * sizeof(char*));
  char** x1524 = x1523;
  int* x1525 = (int*)malloc(x6 * sizeof(int));
  int* x1526 = x1525;
  int x1515 = open("../databases/sf2/nation.tbl",0);
  long x1516 = fsize(x1515);
  char* x1517 = mmap(0, x1516, PROT_READ, MAP_FILE | MAP_SHARED, x1515, 0);
  for (;;) {
    long x1529 = x1518;
    bool x1530 = x1529 < x1516;
    if (!x1530) break;
    int x1533 = 0;
    for (;;) {
      long x1534 = x1518;
      char x1535 = x1517[x1534];
      bool x1536 = x1535 != '|';
      bool x1541 = x1536;
      if (x1536) {
        long x1537 = x1518;
        char x1538 = x1517[x1537];
        bool x1539 = x1538 != '\n';
        x1541 = x1539;
      }
      bool x1542 = x1541;
      if (!x1542) break;
      int x1544 = x1533;
      long x1546 = x1518;
      int x1545 = x1544 * 10;
      char x1547 = x1517[x1546];
      char x1548 = x1547 - '0';
      int x1549 = x1545 + x1548;
      x1533 = x1549;
      x1518 = x1518 + 1;
    }
    x1518 = x1518 + 1;
    int x1555 = x1533;
    long x1556 = x1518;
    for (;;) {
      long x1557 = x1518;
      char x1558 = x1517[x1557];
      bool x1559 = x1558 != '|';
      bool x1564 = x1559;
      if (x1559) {
        long x1560 = x1518;
        char x1561 = x1517[x1560];
        bool x1562 = x1561 != '\n';
        x1564 = x1562;
      }
      bool x1565 = x1564;
      if (!x1565) break;
      x1518 = x1518 + 1;
    }
    x1518 = x1518 + 1;
    int x1575 = 0;
    for (;;) {
      long x1576 = x1518;
      char x1577 = x1517[x1576];
      bool x1578 = x1577 != '|';
      bool x1583 = x1578;
      if (x1578) {
        long x1579 = x1518;
        char x1580 = x1517[x1579];
        bool x1581 = x1580 != '\n';
        x1583 = x1581;
      }
      bool x1584 = x1583;
      if (!x1584) break;
      int x1586 = x1575;
      long x1588 = x1518;
      int x1587 = x1586 * 10;
      char x1589 = x1517[x1588];
      char x1590 = x1589 - '0';
      int x1591 = x1587 + x1590;
      x1575 = x1591;
      x1518 = x1518 + 1;
    }
    x1518 = x1518 + 1;
    int x1597 = x1575;
    for (;;) {
      long x1599 = x1518;
      char x1600 = x1517[x1599];
      bool x1601 = x1600 != '|';
      bool x1606 = x1601;
      if (x1601) {
        long x1602 = x1518;
        char x1603 = x1517[x1602];
        bool x1604 = x1603 != '\n';
        x1606 = x1604;
      }
      bool x1607 = x1606;
      if (!x1607) break;
      x1518 = x1518 + 1;
    }
    x1518 = x1518 + 1;
    long x1617 = x1520;
    long x1618 = x1519;
    bool x1619 = x1617 == x1618;
    if (x1619) {
      long x1620 = x1618 * 4L;
      x1519 = x1620;
      printf("buffer.resize %d\n",x1620);
      int* x1623 = x1522;
      int* x1624 = (int*)realloc(x1623,x1620 * sizeof(int));
      x1522 = x1624;
      char** x1626 = x1524;
      char** x1627 = (char**)realloc(x1626,x1620 * sizeof(char*));
      x1524 = x1627;
      int* x1629 = x1526;
      int* x1630 = (int*)realloc(x1629,x1620 * sizeof(int));
      x1526 = x1630;
    } else {
    }
    int* x1637 = x1522;
    x1637[x1617] = x1555;
    char** x1639 = x1524;
    char* x1573 = x1517+x1556;
    x1639[x1617] = x1573;
    int* x1641 = x1526;
    x1641[x1617] = x1597;
    x1520 = x1520 + 1;
  }
  long x1651 = 0L;
  long x1652 = x6;
  long x1653 = 0L;
  int* x1654 = (int*)malloc(x6 * sizeof(int));
  int* x1655 = x1654;
  char** x1656 = (char**)malloc(x6 * sizeof(char*));
  char** x1657 = x1656;
  int x1648 = open("../databases/sf2/region.tbl",0);
  long x1649 = fsize(x1648);
  char* x1650 = mmap(0, x1649, PROT_READ, MAP_FILE | MAP_SHARED, x1648, 0);
  for (;;) {
    long x1660 = x1651;
    bool x1661 = x1660 < x1649;
    if (!x1661) break;
    int x1664 = 0;
    for (;;) {
      long x1665 = x1651;
      char x1666 = x1650[x1665];
      bool x1667 = x1666 != '|';
      bool x1672 = x1667;
      if (x1667) {
        long x1668 = x1651;
        char x1669 = x1650[x1668];
        bool x1670 = x1669 != '\n';
        x1672 = x1670;
      }
      bool x1673 = x1672;
      if (!x1673) break;
      int x1675 = x1664;
      long x1677 = x1651;
      int x1676 = x1675 * 10;
      char x1678 = x1650[x1677];
      char x1679 = x1678 - '0';
      int x1680 = x1676 + x1679;
      x1664 = x1680;
      x1651 = x1651 + 1;
    }
    x1651 = x1651 + 1;
    int x1686 = x1664;
    long x1687 = x1651;
    for (;;) {
      long x1688 = x1651;
      char x1689 = x1650[x1688];
      bool x1690 = x1689 != '|';
      bool x1695 = x1690;
      if (x1690) {
        long x1691 = x1651;
        char x1692 = x1650[x1691];
        bool x1693 = x1692 != '\n';
        x1695 = x1693;
      }
      bool x1696 = x1695;
      if (!x1696) break;
      x1651 = x1651 + 1;
    }
    x1651 = x1651 + 1;
    for (;;) {
      long x1706 = x1651;
      char x1707 = x1650[x1706];
      bool x1708 = x1707 != '|';
      bool x1713 = x1708;
      if (x1708) {
        long x1709 = x1651;
        char x1710 = x1650[x1709];
        bool x1711 = x1710 != '\n';
        x1713 = x1711;
      }
      bool x1714 = x1713;
      if (!x1714) break;
      x1651 = x1651 + 1;
    }
    x1651 = x1651 + 1;
    long x1724 = x1653;
    long x1725 = x1652;
    bool x1726 = x1724 == x1725;
    if (x1726) {
      long x1727 = x1725 * 4L;
      x1652 = x1727;
      printf("buffer.resize %d\n",x1727);
      int* x1730 = x1655;
      int* x1731 = (int*)realloc(x1730,x1727 * sizeof(int));
      x1655 = x1731;
      char** x1733 = x1657;
      char** x1734 = (char**)realloc(x1733,x1727 * sizeof(char*));
      x1657 = x1734;
    } else {
    }
    int* x1741 = x1655;
    x1741[x1724] = x1686;
    char** x1743 = x1657;
    char* x1704 = x1650+x1687;
    x1743[x1724] = x1704;
    x1653 = x1653 + 1;
  }
  long x1753 = 0L;
  long x1754 = x6;
  long x1755 = 0L;
  int* x1756 = (int*)malloc(x6 * sizeof(int));
  int* x1757 = x1756;
  char** x1758 = (char**)malloc(x6 * sizeof(char*));
  char** x1759 = x1758;
  char** x1760 = (char**)malloc(x6 * sizeof(char*));
  char** x1761 = x1760;
  int* x1762 = (int*)malloc(x6 * sizeof(int));
  int* x1763 = x1762;
  char** x1764 = (char**)malloc(x6 * sizeof(char*));
  char** x1765 = x1764;
  double* x1766 = (double*)malloc(x6 * sizeof(double));
  double* x1767 = x1766;
  char** x1768 = (char**)malloc(x6 * sizeof(char*));
  char** x1769 = x1768;
  int x1750 = open("../databases/sf2/supplier.tbl",0);
  long x1751 = fsize(x1750);
  char* x1752 = mmap(0, x1751, PROT_READ, MAP_FILE | MAP_SHARED, x1750, 0);
  for (;;) {
    long x1770 = x1753;
    bool x1771 = x1770 < x1751;
    if (!x1771) break;
    int x1774 = 0;
    for (;;) {
      long x1775 = x1753;
      char x1776 = x1752[x1775];
      bool x1777 = x1776 != '|';
      bool x1782 = x1777;
      if (x1777) {
        long x1778 = x1753;
        char x1779 = x1752[x1778];
        bool x1780 = x1779 != '\n';
        x1782 = x1780;
      }
      bool x1783 = x1782;
      if (!x1783) break;
      int x1785 = x1774;
      long x1787 = x1753;
      int x1786 = x1785 * 10;
      char x1788 = x1752[x1787];
      char x1789 = x1788 - '0';
      int x1790 = x1786 + x1789;
      x1774 = x1790;
      x1753 = x1753 + 1;
    }
    x1753 = x1753 + 1;
    int x1796 = x1774;
    long x1797 = x1753;
    for (;;) {
      long x1798 = x1753;
      char x1799 = x1752[x1798];
      bool x1800 = x1799 != '|';
      bool x1805 = x1800;
      if (x1800) {
        long x1801 = x1753;
        char x1802 = x1752[x1801];
        bool x1803 = x1802 != '\n';
        x1805 = x1803;
      }
      bool x1806 = x1805;
      if (!x1806) break;
      x1753 = x1753 + 1;
    }
    x1753 = x1753 + 1;
    long x1815 = x1753;
    for (;;) {
      long x1816 = x1753;
      char x1817 = x1752[x1816];
      bool x1818 = x1817 != '|';
      bool x1823 = x1818;
      if (x1818) {
        long x1819 = x1753;
        char x1820 = x1752[x1819];
        bool x1821 = x1820 != '\n';
        x1823 = x1821;
      }
      bool x1824 = x1823;
      if (!x1824) break;
      x1753 = x1753 + 1;
    }
    x1753 = x1753 + 1;
    int x1834 = 0;
    for (;;) {
      long x1835 = x1753;
      char x1836 = x1752[x1835];
      bool x1837 = x1836 != '|';
      bool x1842 = x1837;
      if (x1837) {
        long x1838 = x1753;
        char x1839 = x1752[x1838];
        bool x1840 = x1839 != '\n';
        x1842 = x1840;
      }
      bool x1843 = x1842;
      if (!x1843) break;
      int x1845 = x1834;
      long x1847 = x1753;
      int x1846 = x1845 * 10;
      char x1848 = x1752[x1847];
      char x1849 = x1848 - '0';
      int x1850 = x1846 + x1849;
      x1834 = x1850;
      x1753 = x1753 + 1;
    }
    x1753 = x1753 + 1;
    int x1856 = x1834;
    long x1857 = x1753;
    for (;;) {
      long x1858 = x1753;
      char x1859 = x1752[x1858];
      bool x1860 = x1859 != '|';
      bool x1865 = x1860;
      if (x1860) {
        long x1861 = x1753;
        char x1862 = x1752[x1861];
        bool x1863 = x1862 != '\n';
        x1865 = x1863;
      }
      bool x1866 = x1865;
      if (!x1866) break;
      x1753 = x1753 + 1;
    }
    x1753 = x1753 + 1;
    int x1876 = 0;
    int x1877 = 1;
    for (;;) {
      long x1878 = x1753;
      char x1879 = x1752[x1878];
      bool x1880 = x1879 != '.';
      bool x1885 = x1880;
      if (x1880) {
        long x1881 = x1753;
        char x1882 = x1752[x1881];
        bool x1883 = x1882 != '|';
        x1885 = x1883;
      }
      bool x1886 = x1885;
      bool x1891 = x1886;
      if (x1886) {
        long x1887 = x1753;
        char x1888 = x1752[x1887];
        bool x1889 = x1888 != '\n';
        x1891 = x1889;
      }
      bool x1892 = x1891;
      if (!x1892) break;
      int x1894 = x1876;
      long x1896 = x1753;
      int x1895 = x1894 * 10;
      char x1897 = x1752[x1896];
      char x1898 = x1897 - '0';
      int x1899 = x1895 + x1898;
      x1876 = x1899;
      x1753 = x1753 + 1;
    }
    long x1904 = x1753;
    char x1905 = x1752[x1904];
    bool x1906 = x1905 == '.';
    if (x1906) {
      x1753 = x1753 + 1;
      for (;;) {
        long x1908 = x1753;
        char x1909 = x1752[x1908];
        bool x1910 = x1909 != '|';
        bool x1915 = x1910;
        if (x1910) {
          long x1911 = x1753;
          char x1912 = x1752[x1911];
          bool x1913 = x1912 != '\n';
          x1915 = x1913;
        }
        bool x1916 = x1915;
        if (!x1916) break;
        int x1918 = x1876;
        long x1920 = x1753;
        int x1919 = x1918 * 10;
        char x1921 = x1752[x1920];
        char x1922 = x1921 - '0';
        int x1923 = x1919 + x1922;
        x1876 = x1923;
        int x1925 = x1877;
        int x1926 = x1925 * 10;
        x1877 = x1926;
        x1753 = x1753 + 1;
      }
    } else {
    }
    x1753 = x1753 + 1;
    int x1935 = x1876;
    int x1937 = x1877;
    long x1940 = x1753;
    for (;;) {
      long x1941 = x1753;
      char x1942 = x1752[x1941];
      bool x1943 = x1942 != '|';
      bool x1948 = x1943;
      if (x1943) {
        long x1944 = x1753;
        char x1945 = x1752[x1944];
        bool x1946 = x1945 != '\n';
        x1948 = x1946;
      }
      bool x1949 = x1948;
      if (!x1949) break;
      x1753 = x1753 + 1;
    }
    x1753 = x1753 + 1;
    long x1959 = x1755;
    long x1960 = x1754;
    bool x1961 = x1959 == x1960;
    if (x1961) {
      long x1962 = x1960 * 4L;
      x1754 = x1962;
      printf("buffer.resize %d\n",x1962);
      int* x1965 = x1757;
      int* x1966 = (int*)realloc(x1965,x1962 * sizeof(int));
      x1757 = x1966;
      char** x1968 = x1759;
      char** x1969 = (char**)realloc(x1968,x1962 * sizeof(char*));
      x1759 = x1969;
      char** x1971 = x1761;
      char** x1972 = (char**)realloc(x1971,x1962 * sizeof(char*));
      x1761 = x1972;
      int* x1974 = x1763;
      int* x1975 = (int*)realloc(x1974,x1962 * sizeof(int));
      x1763 = x1975;
      char** x1977 = x1765;
      char** x1978 = (char**)realloc(x1977,x1962 * sizeof(char*));
      x1765 = x1978;
      double* x1980 = x1767;
      double* x1981 = (double*)realloc(x1980,x1962 * sizeof(double));
      x1767 = x1981;
      char** x1983 = x1769;
      char** x1984 = (char**)realloc(x1983,x1962 * sizeof(char*));
      x1769 = x1984;
    } else {
    }
    int* x1988 = x1757;
    x1988[x1959] = x1796;
    char** x1990 = x1759;
    char* x1814 = x1752+x1797;
    x1990[x1959] = x1814;
    char** x1992 = x1761;
    char* x1832 = x1752+x1815;
    x1992[x1959] = x1832;
    int* x1994 = x1763;
    x1994[x1959] = x1856;
    char** x1996 = x1765;
    char* x1874 = x1752+x1857;
    x1996[x1959] = x1874;
    double* x1998 = x1767;
    double x1936 = (double)x1935;
    double x1938 = (double)x1937;
    double x1939 = x1936 / x1938;
    x1998[x1959] = x1939;
    char** x2000 = x1769;
    char* x1957 = x1752+x1940;
    x2000[x1959] = x1957;
    x1755 = x1755 + 1;
  }
  long x2011 = DEFAULT_JOIN_HASH_SIZE;
  long x787 = DEFAULT_AGG_HASH_SIZE ;
  long x2034 = x2011 - 1L;
  long x802 = x787 - 1L;
  int x2005;
  for(x2005=0; x2005 < 5; x2005++) {
    bool x2006 = false;
    long x2007 = 0L;
    bool x2008 = false;
    long x2009 = 0L;
    int* x2012 = (int*)malloc(x2011 * sizeof(int));
    int* x2013 = x2012;
    char** x2014 = (char**)malloc(x2011 * sizeof(char*));
    char** x2015 = x2014;
    char** x2016 = (char**)malloc(x2011 * sizeof(char*));
    char** x2017 = x2016;
    int* x2018 = (int*)malloc(x2011 * sizeof(int));
    int* x2019 = x2018;
    char** x2020 = (char**)malloc(x2011 * sizeof(char*));
    char** x2021 = x2020;
    double* x2022 = (double*)malloc(x2011 * sizeof(double));
    double* x2023 = x2022;
    char** x2024 = (char**)malloc(x2011 * sizeof(char*));
    char** x2025 = x2024;
    long x2026 = 0L;
    long* x2027 = (long*)malloc(x2011 * sizeof(long));
    long* x2028 = (long*)malloc(x2011 * sizeof(long));
    long x2030;
    for(x2030=0L; x2030 < x2011; x2030++) {
      x2027[x2030] = -1L;
    }
    bool x2036 = false;
    long x2037 = 0L;
    int* x2039 = (int*)malloc(x2011 * sizeof(int));
    int* x2040 = x2039;
    char** x2041 = (char**)malloc(x2011 * sizeof(char*));
    char** x2042 = x2041;
    int* x2043 = (int*)malloc(x2011 * sizeof(int));
    int* x2044 = x2043;
    long x2047 = 0L;
    long* x2048 = (long*)malloc(x2011 * sizeof(long));
    long* x2049 = (long*)malloc(x2011 * sizeof(long));
    long x2050;
    for(x2050=0L; x2050 < x2011; x2050++) {
      x2048[x2050] = -1L;
    }
    bool x2055 = false;
    long x2056 = 0L;
    int* x2059 = (int*)malloc(x2011 * sizeof(int));
    int* x2060 = x2059;
    char** x2063 = (char**)malloc(x2011 * sizeof(char*));
    char** x2064 = x2063;
    long x2077 = 0L;
    long* x2078 = (long*)malloc(x2011 * sizeof(long));
    long* x2079 = (long*)malloc(x2011 * sizeof(long));
    long x2080;
    for(x2080=0L; x2080 < x2011; x2080++) {
      x2078[x2080] = -1L;
    }
    bool x2085 = false;
    long x2086 = 0L;
    int* x2089 = (int*)malloc(x2011 * sizeof(int));
    int* x2090 = x2089;
    long x2095 = 0L;
    long* x2096 = (long*)malloc(x2011 * sizeof(long));
    long* x2097 = (long*)malloc(x2011 * sizeof(long));
    long x2098;
    for(x2098=0L; x2098 < x2011; x2098++) {
      x2096[x2098] = -1L;
    }
    struct Anon842992833* x2105 = (struct Anon842992833*)malloc(x787 * sizeof(struct Anon842992833));
    struct Anon842992833* x2106 = x2105;
    long x2107 = 0L;
    long* x2108 = (long*)malloc(x787 * sizeof(long));
    long x2109;
    for(x2109=0L; x2109 < x787; x2109++) {
      struct Anon842992833* x2110 = x2106;
      struct Anon842992833 x2111 = x2110[x2109];
      int x2112 = x2111.key;;
      struct Anon1023322325 x2113 = x2111.aggs;;
      struct Anon842992833 x2114;
      x2114.exists = false;
      x2114.key = x2112;
      x2114.aggs = x2113;
      x2110[x2109] = x2114;
    }
    int x2119 = 0;
    long x2121 = 0L;
    struct timeval x2588, x2589, x2590;
    gettimeofday(&x2588, NULL);
    printf("%s\n","begin scan REGION");
    for (;;) {
      bool x2123 = x2085;
      bool x2124 = !x2123;
      bool x2129 = x2124;
      if (x2124) {
        long x2125 = x2086;
        long x2126 = x1653;
        bool x2127 = x2125 < x2126;
        x2129 = x2127;
      }
      bool x2130 = x2129;
      if (!x2130) break;
      long x2132 = x2086;
      int* x2133 = x1655;
      int x2134 = x2133[x2132];
      char** x2135 = x1657;
      char* x2136 = x2135[x2132];
      x2086 = x2086 + 1;
      bool x2141 = strcmp(x2136,"AFRICA") == 0;;
      if (x2141) {
        long x2142 = x2095;
        int* x2143 = x2090;
        x2143[x2142] = x2134;
        x2095 = x2095 + 1L;
        long x2150 = x2134 & x2034;
        long x2151 = x2096[x2150];
        x2096[x2150] = x2142;
        x2097[x2142] = x2151;
      } else {
      }
    }
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x2159 = x2055;
      bool x2160 = !x2159;
      bool x2165 = x2160;
      if (x2160) {
        long x2161 = x2056;
        long x2162 = x1003;
        bool x2163 = x2161 < x2162;
        x2165 = x2163;
      }
      bool x2166 = x2165;
      if (!x2166) break;
      long x2168 = x2056;
      int* x2169 = x1005;
      int x2170 = x2169[x2168];
      char** x2173 = x1009;
      char* x2174 = x2173[x2168];
      char** x2177 = x1013;
      char* x2178 = x2177[x2168];
      int* x2179 = x1015;
      int x2180 = x2179[x2168];
      x2056 = x2056 + 1;
      bool x2189 = x2180 == 43;
      bool x2193 = x2189;
      if (x2189) {
        int x2191 = strlen(x2178);
        int x2190 = strlen("TIN");
        bool x2192 = strncmp(x2178+x2191-x2190,"TIN", x2190) == 0;;
        x2193 = x2192;
      }
      bool x2194 = x2193;
      if (x2194) {
        long x2195 = x2077;
        int* x2196 = x2060;
        x2196[x2195] = x2170;
        char** x2200 = x2064;
        x2200[x2195] = x2174;
        x2077 = x2077 + 1L;
        long x2215 = x2170 & x2034;
        long x2216 = x2078[x2215];
        x2078[x2215] = x2195;
        x2079[x2195] = x2216;
      } else {
      }
    }
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x2224 = x2036;
      bool x2225 = !x2224;
      bool x2230 = x2225;
      if (x2225) {
        long x2226 = x2037;
        long x2227 = x1520;
        bool x2228 = x2226 < x2227;
        x2230 = x2228;
      }
      bool x2231 = x2230;
      if (!x2231) break;
      long x2233 = x2037;
      int* x2234 = x1522;
      int x2235 = x2234[x2233];
      char** x2236 = x1524;
      char* x2237 = x2236[x2233];
      int* x2238 = x1526;
      int x2239 = x2238[x2233];
      x2037 = x2037 + 1;
      long x2244 = x2047;
      int* x2245 = x2040;
      x2245[x2244] = x2235;
      char** x2247 = x2042;
      x2247[x2244] = x2237;
      int* x2249 = x2044;
      x2249[x2244] = x2239;
      x2047 = x2047 + 1L;
      long x2254 = x2235 & x2034;
      long x2255 = x2048[x2254];
      x2048[x2254] = x2244;
      x2049[x2244] = x2255;
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x2261 = x2008;
      bool x2262 = !x2261;
      bool x2267 = x2262;
      if (x2262) {
        long x2263 = x2009;
        long x2264 = x1755;
        bool x2265 = x2263 < x2264;
        x2267 = x2265;
      }
      bool x2268 = x2267;
      if (!x2268) break;
      long x2270 = x2009;
      int* x2271 = x1757;
      int x2272 = x2271[x2270];
      char** x2273 = x1759;
      char* x2274 = x2273[x2270];
      char** x2275 = x1761;
      char* x2276 = x2275[x2270];
      int* x2277 = x1763;
      int x2278 = x2277[x2270];
      char** x2279 = x1765;
      char* x2280 = x2279[x2270];
      double* x2281 = x1767;
      double x2282 = x2281[x2270];
      char** x2283 = x1769;
      char* x2284 = x2283[x2270];
      x2009 = x2009 + 1;
      long x2287 = x2026;
      int* x2288 = x2013;
      x2288[x2287] = x2272;
      char** x2290 = x2015;
      x2290[x2287] = x2274;
      char** x2292 = x2017;
      x2292[x2287] = x2276;
      int* x2294 = x2019;
      x2294[x2287] = x2278;
      char** x2296 = x2021;
      x2296[x2287] = x2280;
      double* x2298 = x2023;
      x2298[x2287] = x2282;
      char** x2300 = x2025;
      x2300[x2287] = x2284;
      x2026 = x2026 + 1L;
      long x2303 = x2272 & x2034;
      long x2304 = x2027[x2303];
      x2027[x2303] = x2287;
      x2028[x2287] = x2304;
    }
    printf("%s\n","begin scan PARTSUPP");
    for (;;) {
      bool x2310 = x2006;
      bool x2311 = !x2310;
      bool x2316 = x2311;
      if (x2311) {
        long x2312 = x2007;
        long x2313 = x1309;
        bool x2314 = x2312 < x2313;
        x2316 = x2314;
      }
      bool x2317 = x2316;
      if (!x2317) break;
      long x2319 = x2007;
      int* x2320 = x1311;
      int x2321 = x2320[x2319];
      int* x2322 = x1313;
      int x2323 = x2322[x2319];
      double* x2326 = x1317;
      double x2327 = x2326[x2319];
      x2007 = x2007 + 1;
      long x2332 = x2323 & x2034;
      long x2333 = x2027[x2332];
      long x2334 = x2333;
      long x2380 = x2321 & x2034;
      bool x2494 = x2327 < 1.0E100;
      for (;;) {
        long x2335 = x2334;
        bool x2336 = x2335 != -1;
        if (!x2336) break;
        long x2338 = x2334;
        int* x2339 = x2013;
        int x2340 = x2339[x2338];
        char** x2341 = x2015;
        char* x2342 = x2341[x2338];
        char** x2343 = x2017;
        char* x2344 = x2343[x2338];
        int* x2345 = x2019;
        int x2346 = x2345[x2338];
        char** x2347 = x2021;
        char* x2348 = x2347[x2338];
        double* x2349 = x2023;
        double x2350 = x2349[x2338];
        char** x2351 = x2025;
        char* x2352 = x2351[x2338];
        long x2354 = x2028[x2338];
        x2334 = x2354;
        bool x2356 = x2340 == x2323;
        if (x2356) {
          long x2359 = x2346 & x2034;
          long x2360 = x2048[x2359];
          long x2361 = x2360;
          for (;;) {
            long x2362 = x2361;
            bool x2363 = x2362 != -1;
            if (!x2363) break;
            long x2365 = x2361;
            int* x2366 = x2040;
            int x2367 = x2366[x2365];
            char** x2368 = x2042;
            char* x2369 = x2368[x2365];
            int* x2370 = x2044;
            int x2371 = x2370[x2365];
            long x2375 = x2049[x2365];
            x2361 = x2375;
            bool x2377 = x2367 == x2346;
            if (x2377) {
              long x2381 = x2078[x2380];
              long x2382 = x2381;
              long x2411 = x2371 & x2034;
              for (;;) {
                long x2383 = x2382;
                bool x2384 = x2383 != -1;
                if (!x2384) break;
                long x2386 = x2382;
                int* x2387 = x2060;
                int x2388 = x2387[x2386];
                char** x2391 = x2064;
                char* x2392 = x2391[x2386];
                long x2406 = x2079[x2386];
                x2382 = x2406;
                bool x2408 = x2388 == x2321;
                if (x2408) {
                  long x2412 = x2096[x2411];
                  long x2413 = x2412;
                  long x2430 = x2388 & x802;
                  struct Anon1023322325 x2429;
                  x2429.PS_SUPPLYCOST = x2327;
                  x2429.S_ACCTBAL = x2350;
                  x2429.S_NAME = x2342;
                  x2429.S_ADDRESS = x2344;
                  x2429.S_PHONE = x2348;
                  x2429.S_COMMENT = x2352;
                  x2429.N_NAME = x2369;
                  x2429.P_PARTKEY = x2388;
                  x2429.P_MFGR = x2392;
                  for (;;) {
                    long x2414 = x2413;
                    bool x2415 = x2414 != -1;
                    if (!x2415) break;
                    long x2417 = x2413;
                    int* x2418 = x2090;
                    int x2419 = x2418[x2417];
                    long x2425 = x2097[x2417];
                    x2413 = x2425;
                    bool x2427 = x2419 == x2371;
                    if (x2427) {
                      long x2431 = x2430;
                      struct Anon842992833* x2432 = x2106;
                      struct Anon842992833 x2433 = x2432[x2430];
                      struct Anon842992833 x2434 = x2433;
                      bool x2435 = x2433.exists;;
                      bool x2440 = x2435;
                      if (x2435) {
                        struct Anon842992833 x2436 = x2434;
                        int x2437 = x2436.key;;
                        bool x2438 = x2437 == x2388;
                        x2440 = x2438;
                      }
                      bool x2441 = x2440;
                      if (x2441) {
                        struct Anon1023322325 x2442 = x2433.aggs;;
                        struct Anon1023322325 x2443 = x2442;
                        double x2444 = x2442.PS_SUPPLYCOST;;
                        bool x2445 = x2327 < x2444;
                        if (x2445) {
                          x2443 = x2429;
                        } else {
                        }
                        struct Anon1023322325 x2449 = x2443;
                        int x2450 = x2433.key;;
                        struct Anon842992833 x2451;
                        x2451.exists = true;
                        x2451.key = x2450;
                        x2451.aggs = x2449;
                        x2432[x2430] = x2451;
                      } else {
                        for (;;) {
                          struct Anon842992833 x2454 = x2434;
                          bool x2455 = x2454.exists;;
                          bool x2525;
                          if (x2455) {
                            int x2456 = x2454.key;;
                            bool x2457 = x2456 == x2388;
                            bool x2481;
                            if (x2457) {
                              struct Anon1023322325 x2458 = x2454.aggs;;
                              struct Anon1023322325 x2459 = x2458;
                              double x2460 = x2458.PS_SUPPLYCOST;;
                              bool x2461 = x2327 < x2460;
                              if (x2461) {
                                x2459 = x2429;
                              } else {
                              }
                              struct Anon1023322325 x2465 = x2459;
                              long x2466 = x2431;
                              struct Anon842992833* x2468 = x2106;
                              struct Anon842992833 x2467;
                              x2467.exists = true;
                              x2467.key = x2456;
                              x2467.aggs = x2465;
                              x2468[x2466] = x2467;
                              x2481 = false;
                            } else {
                              long x2471 = x2431;
                              long x2472 = x2471 + 1L;
                              long x2473 = x2472 % x802;
                              x2431 = x2473;
                              struct Anon842992833* x2475 = x2106;
                              struct Anon842992833 x2476 = x2475[x2473];
                              x2434 = x2476;
                              x2481 = true;
                            }
                            x2525 = x2481;
                          } else {
                            long x2483 = x2431;
                            double x2484 = 1.0E100;
                            double x2485 = 0.0;
                            char* x2486 = "";
                            char* x2487 = "";
                            char* x2488 = "";
                            char* x2489 = "";
                            char* x2490 = "";
                            int x2491 = 0;
                            char* x2492 = "";
                            if (x2494) {
                              x2484 = x2327;
                              x2485 = x2350;
                              x2486 = x2342;
                              x2487 = x2344;
                              x2488 = x2348;
                              x2489 = x2352;
                              x2490 = x2369;
                              x2491 = x2388;
                              x2492 = x2392;
                            } else {
                            }
                            double x2506 = x2484;
                            double x2507 = x2485;
                            char* x2508 = x2486;
                            char* x2509 = x2487;
                            char* x2510 = x2488;
                            char* x2511 = x2489;
                            char* x2512 = x2490;
                            int x2513 = x2491;
                            char* x2514 = x2492;
                            struct Anon842992833* x2517 = x2106;
                            struct Anon1023322325 x2515;
                            x2515.PS_SUPPLYCOST = x2506;
                            x2515.S_ACCTBAL = x2507;
                            x2515.S_NAME = x2508;
                            x2515.S_ADDRESS = x2509;
                            x2515.S_PHONE = x2510;
                            x2515.S_COMMENT = x2511;
                            x2515.N_NAME = x2512;
                            x2515.P_PARTKEY = x2513;
                            x2515.P_MFGR = x2514;
                            struct Anon842992833 x2516;
                            x2516.exists = true;
                            x2516.key = x2388;
                            x2516.aggs = x2515;
                            x2517[x2483] = x2516;
                            long x2519 = x2107;
                            x2108[x2519] = x2483;
                            x2107 = x2107 + 1L;
                            x2525 = false;
                          }
                          if (!x2525) break;
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
    long x2550 = x2107;
    long x2552;
    for(x2552=0L; x2552 < x2550; x2552++) {
      long x2553 = x2108[x2552];
      struct Anon842992833* x2554 = x2106;
      struct Anon842992833 x2555 = x2554[x2553];
      struct Anon1023322325 x2557 = x2555.aggs;;
      int x2559 = x2119;
      bool x2560 = x2559 < 100;
      bool x2561 = x2560 == false;
      if (x2561) {
      } else {
        double x2564 = x2557.S_ACCTBAL;;
        char* x2565 = x2557.S_NAME;;
        int x2566 = strlen(x2565);
        char* x2567 = x2557.N_NAME;;
        int x2568 = strlen(x2567);
        int x2569 = x2557.P_PARTKEY;;
        char* x2570 = x2557.P_MFGR;;
        int x2571 = strlen(x2570);
        char* x2572 = x2557.S_ADDRESS;;
        int x2573 = strlen(x2572);
        char* x2574 = x2557.S_PHONE;;
        int x2575 = strlen(x2574);
        char* x2576 = x2557.S_COMMENT;;
        int x2577 = strlen(x2576);
        printf("%.2f|%.*s|%.*s|%d|%.*s|%.*s|%.*s|%.*s\n",x2564,x2566,x2565,x2568,x2567,x2569,x2571,x2570,x2573,x2572,x2575,x2574,x2577,x2576);
        x2119 = x2119 + 1;
        x2121 = x2121 + 1L;
      }
    }
    long x2585 = x2121;
    printf("(%d rows)\n",x2585);
    gettimeofday(&x2589, NULL);
    timeval_subtract(&x2590, &x2589, &x2588);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x2590.tv_sec * 1000) + (x2590.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
