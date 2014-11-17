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

struct Anon1230230422 {
int key;
struct Anon1023322325 wnd;
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

struct Anon1272074242 {
bool exists;
struct Anon625264174 key;
struct Anon567626277 aggs;
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
int main(int x993, char** x994) {
  int x998 = 0;
  int x999 = 1048576;
  int x1000 = 0;
  int* x1001 = (int*)malloc(1048576 * sizeof(int));
  int* x1002 = x1001;
  char** x1005 = (char**)malloc(1048576 * sizeof(char*));
  char** x1006 = x1005;
  char** x1009 = (char**)malloc(1048576 * sizeof(char*));
  char** x1010 = x1009;
  int* x1011 = (int*)malloc(1048576 * sizeof(int));
  int* x1012 = x1011;
  int x995 = open("../databases/sf2/part.tbl",0);
  int x996 = fsize(x995);
  char* x997 = mmap(0, x996, PROT_READ, MAP_FILE | MAP_SHARED, x995, 0);
  for (;;) {
    int x1020 = x998;
    bool x1021 = x1020 < x996;
    if (!x1021) break;
    int x1024 = 0;
    for (;;) {
      int x1025 = x998;
      char x1026 = x997[x1025];
      bool x1027 = x1026 != '|';
      bool x1032 = x1027;
      if (x1027) {
        int x1028 = x998;
        char x1029 = x997[x1028];
        bool x1030 = x1029 != '\n';
        x1032 = x1030;
      }
      bool x1033 = x1032;
      if (!x1033) break;
      int x1035 = x1024;
      int x1037 = x998;
      int x1036 = x1035 * 10;
      char x1038 = x997[x1037];
      char x1039 = x1038 - '0';
      int x1040 = x1036 + x1039;
      x1024 = x1040;
      x998 = x998 + 1;
    }
    x998 = x998 + 1;
    int x1046 = x1024;
    for (;;) {
      int x1048 = x998;
      char x1049 = x997[x1048];
      bool x1050 = x1049 != '|';
      bool x1055 = x1050;
      if (x1050) {
        int x1051 = x998;
        char x1052 = x997[x1051];
        bool x1053 = x1052 != '\n';
        x1055 = x1053;
      }
      bool x1056 = x1055;
      if (!x1056) break;
      x998 = x998 + 1;
    }
    x998 = x998 + 1;
    int x1065 = x998;
    for (;;) {
      int x1066 = x998;
      char x1067 = x997[x1066];
      bool x1068 = x1067 != '|';
      bool x1073 = x1068;
      if (x1068) {
        int x1069 = x998;
        char x1070 = x997[x1069];
        bool x1071 = x1070 != '\n';
        x1073 = x1071;
      }
      bool x1074 = x1073;
      if (!x1074) break;
      x998 = x998 + 1;
    }
    x998 = x998 + 1;
    for (;;) {
      int x1084 = x998;
      char x1085 = x997[x1084];
      bool x1086 = x1085 != '|';
      bool x1091 = x1086;
      if (x1086) {
        int x1087 = x998;
        char x1088 = x997[x1087];
        bool x1089 = x1088 != '\n';
        x1091 = x1089;
      }
      bool x1092 = x1091;
      if (!x1092) break;
      x998 = x998 + 1;
    }
    x998 = x998 + 1;
    int x1101 = x998;
    for (;;) {
      int x1102 = x998;
      char x1103 = x997[x1102];
      bool x1104 = x1103 != '|';
      bool x1109 = x1104;
      if (x1104) {
        int x1105 = x998;
        char x1106 = x997[x1105];
        bool x1107 = x1106 != '\n';
        x1109 = x1107;
      }
      bool x1110 = x1109;
      if (!x1110) break;
      x998 = x998 + 1;
    }
    x998 = x998 + 1;
    int x1120 = 0;
    for (;;) {
      int x1121 = x998;
      char x1122 = x997[x1121];
      bool x1123 = x1122 != '|';
      bool x1128 = x1123;
      if (x1123) {
        int x1124 = x998;
        char x1125 = x997[x1124];
        bool x1126 = x1125 != '\n';
        x1128 = x1126;
      }
      bool x1129 = x1128;
      if (!x1129) break;
      int x1131 = x1120;
      int x1133 = x998;
      int x1132 = x1131 * 10;
      char x1134 = x997[x1133];
      char x1135 = x1134 - '0';
      int x1136 = x1132 + x1135;
      x1120 = x1136;
      x998 = x998 + 1;
    }
    x998 = x998 + 1;
    int x1142 = x1120;
    for (;;) {
      int x1144 = x998;
      char x1145 = x997[x1144];
      bool x1146 = x1145 != '|';
      bool x1151 = x1146;
      if (x1146) {
        int x1147 = x998;
        char x1148 = x997[x1147];
        bool x1149 = x1148 != '\n';
        x1151 = x1149;
      }
      bool x1152 = x1151;
      if (!x1152) break;
      x998 = x998 + 1;
    }
    x998 = x998 + 1;
    for (;;) {
      int x1164 = x998;
      char x1165 = x997[x1164];
      bool x1166 = x1165 != '.';
      bool x1171 = x1166;
      if (x1166) {
        int x1167 = x998;
        char x1168 = x997[x1167];
        bool x1169 = x1168 != '|';
        x1171 = x1169;
      }
      bool x1172 = x1171;
      bool x1177 = x1172;
      if (x1172) {
        int x1173 = x998;
        char x1174 = x997[x1173];
        bool x1175 = x1174 != '\n';
        x1177 = x1175;
      }
      bool x1178 = x1177;
      if (!x1178) break;
      x998 = x998 + 1;
    }
    int x1190 = x998;
    char x1191 = x997[x1190];
    bool x1192 = x1191 == '.';
    if (x1192) {
      x998 = x998 + 1;
      for (;;) {
        int x1194 = x998;
        char x1195 = x997[x1194];
        bool x1196 = x1195 != '|';
        bool x1201 = x1196;
        if (x1196) {
          int x1197 = x998;
          char x1198 = x997[x1197];
          bool x1199 = x1198 != '\n';
          x1201 = x1199;
        }
        bool x1202 = x1201;
        if (!x1202) break;
        x998 = x998 + 1;
      }
    } else {
    }
    x998 = x998 + 1;
    for (;;) {
      int x1227 = x998;
      char x1228 = x997[x1227];
      bool x1229 = x1228 != '|';
      bool x1234 = x1229;
      if (x1229) {
        int x1230 = x998;
        char x1231 = x997[x1230];
        bool x1232 = x1231 != '\n';
        x1234 = x1232;
      }
      bool x1235 = x1234;
      if (!x1235) break;
      x998 = x998 + 1;
    }
    x998 = x998 + 1;
    int x1245 = x1000;
    int x1246 = x999;
    bool x1247 = x1245 == x1246;
    if (x1247) {
      int x1248 = x1246 * 4;
      x999 = x1248;
      printf("buffer.resize %d\n",x1248);
      int* x1251 = x1002;
      int* x1252 = (int*)realloc(x1251,x1248 * sizeof(int));
      x1002 = x1252;
      char** x1257 = x1006;
      char** x1258 = (char**)realloc(x1257,x1248 * sizeof(char*));
      x1006 = x1258;
      char** x1263 = x1010;
      char** x1264 = (char**)realloc(x1263,x1248 * sizeof(char*));
      x1010 = x1264;
      int* x1266 = x1012;
      int* x1267 = (int*)realloc(x1266,x1248 * sizeof(int));
      x1012 = x1267;
    } else {
    }
    int* x1280 = x1002;
    x1280[x1245] = x1046;
    char** x1284 = x1006;
    char* x1082 = x997+x1065;
    x1284[x1245] = x1082;
    char** x1288 = x1010;
    char* x1118 = x997+x1101;
    x1288[x1245] = x1118;
    int* x1290 = x1012;
    x1290[x1245] = x1142;
    x1000 = x1000 + 1;
  }
  int x1304 = 0;
  int x1305 = 1048576;
  int x1306 = 0;
  int* x1307 = (int*)malloc(1048576 * sizeof(int));
  int* x1308 = x1307;
  int* x1309 = (int*)malloc(1048576 * sizeof(int));
  int* x1310 = x1309;
  double* x1313 = (double*)malloc(1048576 * sizeof(double));
  double* x1314 = x1313;
  int x1301 = open("../databases/sf2/partsupp.tbl",0);
  int x1302 = fsize(x1301);
  char* x1303 = mmap(0, x1302, PROT_READ, MAP_FILE | MAP_SHARED, x1301, 0);
  for (;;) {
    int x1317 = x1304;
    bool x1318 = x1317 < x1302;
    if (!x1318) break;
    int x1321 = 0;
    for (;;) {
      int x1322 = x1304;
      char x1323 = x1303[x1322];
      bool x1324 = x1323 != '|';
      bool x1329 = x1324;
      if (x1324) {
        int x1325 = x1304;
        char x1326 = x1303[x1325];
        bool x1327 = x1326 != '\n';
        x1329 = x1327;
      }
      bool x1330 = x1329;
      if (!x1330) break;
      int x1332 = x1321;
      int x1334 = x1304;
      int x1333 = x1332 * 10;
      char x1335 = x1303[x1334];
      char x1336 = x1335 - '0';
      int x1337 = x1333 + x1336;
      x1321 = x1337;
      x1304 = x1304 + 1;
    }
    x1304 = x1304 + 1;
    int x1343 = x1321;
    int x1345 = 0;
    for (;;) {
      int x1346 = x1304;
      char x1347 = x1303[x1346];
      bool x1348 = x1347 != '|';
      bool x1353 = x1348;
      if (x1348) {
        int x1349 = x1304;
        char x1350 = x1303[x1349];
        bool x1351 = x1350 != '\n';
        x1353 = x1351;
      }
      bool x1354 = x1353;
      if (!x1354) break;
      int x1356 = x1345;
      int x1358 = x1304;
      int x1357 = x1356 * 10;
      char x1359 = x1303[x1358];
      char x1360 = x1359 - '0';
      int x1361 = x1357 + x1360;
      x1345 = x1361;
      x1304 = x1304 + 1;
    }
    x1304 = x1304 + 1;
    int x1367 = x1345;
    for (;;) {
      int x1370 = x1304;
      char x1371 = x1303[x1370];
      bool x1372 = x1371 != '|';
      bool x1377 = x1372;
      if (x1372) {
        int x1373 = x1304;
        char x1374 = x1303[x1373];
        bool x1375 = x1374 != '\n';
        x1377 = x1375;
      }
      bool x1378 = x1377;
      if (!x1378) break;
      x1304 = x1304 + 1;
    }
    x1304 = x1304 + 1;
    int x1393 = 0;
    int x1394 = 1;
    for (;;) {
      int x1395 = x1304;
      char x1396 = x1303[x1395];
      bool x1397 = x1396 != '.';
      bool x1402 = x1397;
      if (x1397) {
        int x1398 = x1304;
        char x1399 = x1303[x1398];
        bool x1400 = x1399 != '|';
        x1402 = x1400;
      }
      bool x1403 = x1402;
      bool x1408 = x1403;
      if (x1403) {
        int x1404 = x1304;
        char x1405 = x1303[x1404];
        bool x1406 = x1405 != '\n';
        x1408 = x1406;
      }
      bool x1409 = x1408;
      if (!x1409) break;
      int x1411 = x1393;
      int x1413 = x1304;
      int x1412 = x1411 * 10;
      char x1414 = x1303[x1413];
      char x1415 = x1414 - '0';
      int x1416 = x1412 + x1415;
      x1393 = x1416;
      x1304 = x1304 + 1;
    }
    int x1421 = x1304;
    char x1422 = x1303[x1421];
    bool x1423 = x1422 == '.';
    if (x1423) {
      x1304 = x1304 + 1;
      for (;;) {
        int x1425 = x1304;
        char x1426 = x1303[x1425];
        bool x1427 = x1426 != '|';
        bool x1432 = x1427;
        if (x1427) {
          int x1428 = x1304;
          char x1429 = x1303[x1428];
          bool x1430 = x1429 != '\n';
          x1432 = x1430;
        }
        bool x1433 = x1432;
        if (!x1433) break;
        int x1435 = x1393;
        int x1437 = x1304;
        int x1436 = x1435 * 10;
        char x1438 = x1303[x1437];
        char x1439 = x1438 - '0';
        int x1440 = x1436 + x1439;
        x1393 = x1440;
        int x1442 = x1394;
        int x1443 = x1442 * 10;
        x1394 = x1443;
        x1304 = x1304 + 1;
      }
    } else {
    }
    x1304 = x1304 + 1;
    int x1452 = x1393;
    int x1454 = x1394;
    for (;;) {
      int x1458 = x1304;
      char x1459 = x1303[x1458];
      bool x1460 = x1459 != '|';
      bool x1465 = x1460;
      if (x1460) {
        int x1461 = x1304;
        char x1462 = x1303[x1461];
        bool x1463 = x1462 != '\n';
        x1465 = x1463;
      }
      bool x1466 = x1465;
      if (!x1466) break;
      x1304 = x1304 + 1;
    }
    x1304 = x1304 + 1;
    int x1476 = x1306;
    int x1477 = x1305;
    bool x1478 = x1476 == x1477;
    if (x1478) {
      int x1479 = x1477 * 4;
      x1305 = x1479;
      printf("buffer.resize %d\n",x1479);
      int* x1482 = x1308;
      int* x1483 = (int*)realloc(x1482,x1479 * sizeof(int));
      x1308 = x1483;
      int* x1485 = x1310;
      int* x1486 = (int*)realloc(x1485,x1479 * sizeof(int));
      x1310 = x1486;
      double* x1491 = x1314;
      double* x1492 = (double*)realloc(x1491,x1479 * sizeof(double));
      x1314 = x1492;
    } else {
    }
    int* x1499 = x1308;
    x1499[x1476] = x1343;
    int* x1501 = x1310;
    x1501[x1476] = x1367;
    double* x1505 = x1314;
    double x1453 = (double)x1452;
    double x1455 = (double)x1454;
    double x1456 = x1453 / x1455;
    x1505[x1476] = x1456;
    x1306 = x1306 + 1;
  }
  int x1515 = 0;
  int x1516 = 1048576;
  int x1517 = 0;
  int* x1518 = (int*)malloc(1048576 * sizeof(int));
  int* x1519 = x1518;
  char** x1520 = (char**)malloc(1048576 * sizeof(char*));
  char** x1521 = x1520;
  int* x1522 = (int*)malloc(1048576 * sizeof(int));
  int* x1523 = x1522;
  int x1512 = open("../databases/sf2/nation.tbl",0);
  int x1513 = fsize(x1512);
  char* x1514 = mmap(0, x1513, PROT_READ, MAP_FILE | MAP_SHARED, x1512, 0);
  for (;;) {
    int x1526 = x1515;
    bool x1527 = x1526 < x1513;
    if (!x1527) break;
    int x1530 = 0;
    for (;;) {
      int x1531 = x1515;
      char x1532 = x1514[x1531];
      bool x1533 = x1532 != '|';
      bool x1538 = x1533;
      if (x1533) {
        int x1534 = x1515;
        char x1535 = x1514[x1534];
        bool x1536 = x1535 != '\n';
        x1538 = x1536;
      }
      bool x1539 = x1538;
      if (!x1539) break;
      int x1541 = x1530;
      int x1543 = x1515;
      int x1542 = x1541 * 10;
      char x1544 = x1514[x1543];
      char x1545 = x1544 - '0';
      int x1546 = x1542 + x1545;
      x1530 = x1546;
      x1515 = x1515 + 1;
    }
    x1515 = x1515 + 1;
    int x1552 = x1530;
    int x1553 = x1515;
    for (;;) {
      int x1554 = x1515;
      char x1555 = x1514[x1554];
      bool x1556 = x1555 != '|';
      bool x1561 = x1556;
      if (x1556) {
        int x1557 = x1515;
        char x1558 = x1514[x1557];
        bool x1559 = x1558 != '\n';
        x1561 = x1559;
      }
      bool x1562 = x1561;
      if (!x1562) break;
      x1515 = x1515 + 1;
    }
    x1515 = x1515 + 1;
    int x1572 = 0;
    for (;;) {
      int x1573 = x1515;
      char x1574 = x1514[x1573];
      bool x1575 = x1574 != '|';
      bool x1580 = x1575;
      if (x1575) {
        int x1576 = x1515;
        char x1577 = x1514[x1576];
        bool x1578 = x1577 != '\n';
        x1580 = x1578;
      }
      bool x1581 = x1580;
      if (!x1581) break;
      int x1583 = x1572;
      int x1585 = x1515;
      int x1584 = x1583 * 10;
      char x1586 = x1514[x1585];
      char x1587 = x1586 - '0';
      int x1588 = x1584 + x1587;
      x1572 = x1588;
      x1515 = x1515 + 1;
    }
    x1515 = x1515 + 1;
    int x1594 = x1572;
    for (;;) {
      int x1596 = x1515;
      char x1597 = x1514[x1596];
      bool x1598 = x1597 != '|';
      bool x1603 = x1598;
      if (x1598) {
        int x1599 = x1515;
        char x1600 = x1514[x1599];
        bool x1601 = x1600 != '\n';
        x1603 = x1601;
      }
      bool x1604 = x1603;
      if (!x1604) break;
      x1515 = x1515 + 1;
    }
    x1515 = x1515 + 1;
    int x1614 = x1517;
    int x1615 = x1516;
    bool x1616 = x1614 == x1615;
    if (x1616) {
      int x1617 = x1615 * 4;
      x1516 = x1617;
      printf("buffer.resize %d\n",x1617);
      int* x1620 = x1519;
      int* x1621 = (int*)realloc(x1620,x1617 * sizeof(int));
      x1519 = x1621;
      char** x1623 = x1521;
      char** x1624 = (char**)realloc(x1623,x1617 * sizeof(char*));
      x1521 = x1624;
      int* x1626 = x1523;
      int* x1627 = (int*)realloc(x1626,x1617 * sizeof(int));
      x1523 = x1627;
    } else {
    }
    int* x1634 = x1519;
    x1634[x1614] = x1552;
    char** x1636 = x1521;
    char* x1570 = x1514+x1553;
    x1636[x1614] = x1570;
    int* x1638 = x1523;
    x1638[x1614] = x1594;
    x1517 = x1517 + 1;
  }
  int x1648 = 0;
  int x1649 = 1048576;
  int x1650 = 0;
  int* x1651 = (int*)malloc(1048576 * sizeof(int));
  int* x1652 = x1651;
  char** x1653 = (char**)malloc(1048576 * sizeof(char*));
  char** x1654 = x1653;
  int x1645 = open("../databases/sf2/region.tbl",0);
  int x1646 = fsize(x1645);
  char* x1647 = mmap(0, x1646, PROT_READ, MAP_FILE | MAP_SHARED, x1645, 0);
  for (;;) {
    int x1657 = x1648;
    bool x1658 = x1657 < x1646;
    if (!x1658) break;
    int x1661 = 0;
    for (;;) {
      int x1662 = x1648;
      char x1663 = x1647[x1662];
      bool x1664 = x1663 != '|';
      bool x1669 = x1664;
      if (x1664) {
        int x1665 = x1648;
        char x1666 = x1647[x1665];
        bool x1667 = x1666 != '\n';
        x1669 = x1667;
      }
      bool x1670 = x1669;
      if (!x1670) break;
      int x1672 = x1661;
      int x1674 = x1648;
      int x1673 = x1672 * 10;
      char x1675 = x1647[x1674];
      char x1676 = x1675 - '0';
      int x1677 = x1673 + x1676;
      x1661 = x1677;
      x1648 = x1648 + 1;
    }
    x1648 = x1648 + 1;
    int x1683 = x1661;
    int x1684 = x1648;
    for (;;) {
      int x1685 = x1648;
      char x1686 = x1647[x1685];
      bool x1687 = x1686 != '|';
      bool x1692 = x1687;
      if (x1687) {
        int x1688 = x1648;
        char x1689 = x1647[x1688];
        bool x1690 = x1689 != '\n';
        x1692 = x1690;
      }
      bool x1693 = x1692;
      if (!x1693) break;
      x1648 = x1648 + 1;
    }
    x1648 = x1648 + 1;
    for (;;) {
      int x1703 = x1648;
      char x1704 = x1647[x1703];
      bool x1705 = x1704 != '|';
      bool x1710 = x1705;
      if (x1705) {
        int x1706 = x1648;
        char x1707 = x1647[x1706];
        bool x1708 = x1707 != '\n';
        x1710 = x1708;
      }
      bool x1711 = x1710;
      if (!x1711) break;
      x1648 = x1648 + 1;
    }
    x1648 = x1648 + 1;
    int x1721 = x1650;
    int x1722 = x1649;
    bool x1723 = x1721 == x1722;
    if (x1723) {
      int x1724 = x1722 * 4;
      x1649 = x1724;
      printf("buffer.resize %d\n",x1724);
      int* x1727 = x1652;
      int* x1728 = (int*)realloc(x1727,x1724 * sizeof(int));
      x1652 = x1728;
      char** x1730 = x1654;
      char** x1731 = (char**)realloc(x1730,x1724 * sizeof(char*));
      x1654 = x1731;
    } else {
    }
    int* x1738 = x1652;
    x1738[x1721] = x1683;
    char** x1740 = x1654;
    char* x1701 = x1647+x1684;
    x1740[x1721] = x1701;
    x1650 = x1650 + 1;
  }
  int x1750 = 0;
  int x1751 = 1048576;
  int x1752 = 0;
  int* x1753 = (int*)malloc(1048576 * sizeof(int));
  int* x1754 = x1753;
  char** x1755 = (char**)malloc(1048576 * sizeof(char*));
  char** x1756 = x1755;
  char** x1757 = (char**)malloc(1048576 * sizeof(char*));
  char** x1758 = x1757;
  int* x1759 = (int*)malloc(1048576 * sizeof(int));
  int* x1760 = x1759;
  char** x1761 = (char**)malloc(1048576 * sizeof(char*));
  char** x1762 = x1761;
  double* x1763 = (double*)malloc(1048576 * sizeof(double));
  double* x1764 = x1763;
  char** x1765 = (char**)malloc(1048576 * sizeof(char*));
  char** x1766 = x1765;
  int x1747 = open("../databases/sf2/supplier.tbl",0);
  int x1748 = fsize(x1747);
  char* x1749 = mmap(0, x1748, PROT_READ, MAP_FILE | MAP_SHARED, x1747, 0);
  for (;;) {
    int x1767 = x1750;
    bool x1768 = x1767 < x1748;
    if (!x1768) break;
    int x1771 = 0;
    for (;;) {
      int x1772 = x1750;
      char x1773 = x1749[x1772];
      bool x1774 = x1773 != '|';
      bool x1779 = x1774;
      if (x1774) {
        int x1775 = x1750;
        char x1776 = x1749[x1775];
        bool x1777 = x1776 != '\n';
        x1779 = x1777;
      }
      bool x1780 = x1779;
      if (!x1780) break;
      int x1782 = x1771;
      int x1784 = x1750;
      int x1783 = x1782 * 10;
      char x1785 = x1749[x1784];
      char x1786 = x1785 - '0';
      int x1787 = x1783 + x1786;
      x1771 = x1787;
      x1750 = x1750 + 1;
    }
    x1750 = x1750 + 1;
    int x1793 = x1771;
    int x1794 = x1750;
    for (;;) {
      int x1795 = x1750;
      char x1796 = x1749[x1795];
      bool x1797 = x1796 != '|';
      bool x1802 = x1797;
      if (x1797) {
        int x1798 = x1750;
        char x1799 = x1749[x1798];
        bool x1800 = x1799 != '\n';
        x1802 = x1800;
      }
      bool x1803 = x1802;
      if (!x1803) break;
      x1750 = x1750 + 1;
    }
    x1750 = x1750 + 1;
    int x1812 = x1750;
    for (;;) {
      int x1813 = x1750;
      char x1814 = x1749[x1813];
      bool x1815 = x1814 != '|';
      bool x1820 = x1815;
      if (x1815) {
        int x1816 = x1750;
        char x1817 = x1749[x1816];
        bool x1818 = x1817 != '\n';
        x1820 = x1818;
      }
      bool x1821 = x1820;
      if (!x1821) break;
      x1750 = x1750 + 1;
    }
    x1750 = x1750 + 1;
    int x1831 = 0;
    for (;;) {
      int x1832 = x1750;
      char x1833 = x1749[x1832];
      bool x1834 = x1833 != '|';
      bool x1839 = x1834;
      if (x1834) {
        int x1835 = x1750;
        char x1836 = x1749[x1835];
        bool x1837 = x1836 != '\n';
        x1839 = x1837;
      }
      bool x1840 = x1839;
      if (!x1840) break;
      int x1842 = x1831;
      int x1844 = x1750;
      int x1843 = x1842 * 10;
      char x1845 = x1749[x1844];
      char x1846 = x1845 - '0';
      int x1847 = x1843 + x1846;
      x1831 = x1847;
      x1750 = x1750 + 1;
    }
    x1750 = x1750 + 1;
    int x1853 = x1831;
    int x1854 = x1750;
    for (;;) {
      int x1855 = x1750;
      char x1856 = x1749[x1855];
      bool x1857 = x1856 != '|';
      bool x1862 = x1857;
      if (x1857) {
        int x1858 = x1750;
        char x1859 = x1749[x1858];
        bool x1860 = x1859 != '\n';
        x1862 = x1860;
      }
      bool x1863 = x1862;
      if (!x1863) break;
      x1750 = x1750 + 1;
    }
    x1750 = x1750 + 1;
    int x1873 = 0;
    int x1874 = 1;
    for (;;) {
      int x1875 = x1750;
      char x1876 = x1749[x1875];
      bool x1877 = x1876 != '.';
      bool x1882 = x1877;
      if (x1877) {
        int x1878 = x1750;
        char x1879 = x1749[x1878];
        bool x1880 = x1879 != '|';
        x1882 = x1880;
      }
      bool x1883 = x1882;
      bool x1888 = x1883;
      if (x1883) {
        int x1884 = x1750;
        char x1885 = x1749[x1884];
        bool x1886 = x1885 != '\n';
        x1888 = x1886;
      }
      bool x1889 = x1888;
      if (!x1889) break;
      int x1891 = x1873;
      int x1893 = x1750;
      int x1892 = x1891 * 10;
      char x1894 = x1749[x1893];
      char x1895 = x1894 - '0';
      int x1896 = x1892 + x1895;
      x1873 = x1896;
      x1750 = x1750 + 1;
    }
    int x1901 = x1750;
    char x1902 = x1749[x1901];
    bool x1903 = x1902 == '.';
    if (x1903) {
      x1750 = x1750 + 1;
      for (;;) {
        int x1905 = x1750;
        char x1906 = x1749[x1905];
        bool x1907 = x1906 != '|';
        bool x1912 = x1907;
        if (x1907) {
          int x1908 = x1750;
          char x1909 = x1749[x1908];
          bool x1910 = x1909 != '\n';
          x1912 = x1910;
        }
        bool x1913 = x1912;
        if (!x1913) break;
        int x1915 = x1873;
        int x1917 = x1750;
        int x1916 = x1915 * 10;
        char x1918 = x1749[x1917];
        char x1919 = x1918 - '0';
        int x1920 = x1916 + x1919;
        x1873 = x1920;
        int x1922 = x1874;
        int x1923 = x1922 * 10;
        x1874 = x1923;
        x1750 = x1750 + 1;
      }
    } else {
    }
    x1750 = x1750 + 1;
    int x1932 = x1873;
    int x1934 = x1874;
    int x1937 = x1750;
    for (;;) {
      int x1938 = x1750;
      char x1939 = x1749[x1938];
      bool x1940 = x1939 != '|';
      bool x1945 = x1940;
      if (x1940) {
        int x1941 = x1750;
        char x1942 = x1749[x1941];
        bool x1943 = x1942 != '\n';
        x1945 = x1943;
      }
      bool x1946 = x1945;
      if (!x1946) break;
      x1750 = x1750 + 1;
    }
    x1750 = x1750 + 1;
    int x1956 = x1752;
    int x1957 = x1751;
    bool x1958 = x1956 == x1957;
    if (x1958) {
      int x1959 = x1957 * 4;
      x1751 = x1959;
      printf("buffer.resize %d\n",x1959);
      int* x1962 = x1754;
      int* x1963 = (int*)realloc(x1962,x1959 * sizeof(int));
      x1754 = x1963;
      char** x1965 = x1756;
      char** x1966 = (char**)realloc(x1965,x1959 * sizeof(char*));
      x1756 = x1966;
      char** x1968 = x1758;
      char** x1969 = (char**)realloc(x1968,x1959 * sizeof(char*));
      x1758 = x1969;
      int* x1971 = x1760;
      int* x1972 = (int*)realloc(x1971,x1959 * sizeof(int));
      x1760 = x1972;
      char** x1974 = x1762;
      char** x1975 = (char**)realloc(x1974,x1959 * sizeof(char*));
      x1762 = x1975;
      double* x1977 = x1764;
      double* x1978 = (double*)realloc(x1977,x1959 * sizeof(double));
      x1764 = x1978;
      char** x1980 = x1766;
      char** x1981 = (char**)realloc(x1980,x1959 * sizeof(char*));
      x1766 = x1981;
    } else {
    }
    int* x1985 = x1754;
    x1985[x1956] = x1793;
    char** x1987 = x1756;
    char* x1811 = x1749+x1794;
    x1987[x1956] = x1811;
    char** x1989 = x1758;
    char* x1829 = x1749+x1812;
    x1989[x1956] = x1829;
    int* x1991 = x1760;
    x1991[x1956] = x1853;
    char** x1993 = x1762;
    char* x1871 = x1749+x1854;
    x1993[x1956] = x1871;
    double* x1995 = x1764;
    double x1933 = (double)x1932;
    double x1935 = (double)x1934;
    double x1936 = x1933 / x1935;
    x1995[x1956] = x1936;
    char** x1997 = x1766;
    char* x1954 = x1749+x1937;
    x1997[x1956] = x1954;
    x1752 = x1752 + 1;
  }
  int x2002;
  for(x2002=0; x2002 < 5; x2002++) {
    bool x2003 = false;
    int x2004 = 0;
    bool x2005 = false;
    int x2006 = 0;
    int* x2008 = (int*)malloc(134217728 * sizeof(int));
    int* x2009 = x2008;
    char** x2010 = (char**)malloc(134217728 * sizeof(char*));
    char** x2011 = x2010;
    char** x2012 = (char**)malloc(134217728 * sizeof(char*));
    char** x2013 = x2012;
    int* x2014 = (int*)malloc(134217728 * sizeof(int));
    int* x2015 = x2014;
    char** x2016 = (char**)malloc(134217728 * sizeof(char*));
    char** x2017 = x2016;
    double* x2018 = (double*)malloc(134217728 * sizeof(double));
    double* x2019 = x2018;
    char** x2020 = (char**)malloc(134217728 * sizeof(char*));
    char** x2021 = x2020;
    int x2022 = 0;
    int* x2023 = (int*)malloc(67108864 * sizeof(int));
    int* x2024 = (int*)malloc(134217728 * sizeof(int));
    int x2026;
    for(x2026=0; x2026 < 67108864; x2026++) {
      x2023[x2026] = -1;
    }
    bool x2031 = false;
    int x2032 = 0;
    int* x2034 = (int*)malloc(134217728 * sizeof(int));
    int* x2035 = x2034;
    char** x2036 = (char**)malloc(134217728 * sizeof(char*));
    char** x2037 = x2036;
    int* x2038 = (int*)malloc(134217728 * sizeof(int));
    int* x2039 = x2038;
    int x2042 = 0;
    int* x2043 = (int*)malloc(67108864 * sizeof(int));
    int* x2044 = (int*)malloc(134217728 * sizeof(int));
    int x2045;
    for(x2045=0; x2045 < 67108864; x2045++) {
      x2043[x2045] = -1;
    }
    bool x2050 = false;
    int x2051 = 0;
    int* x2054 = (int*)malloc(134217728 * sizeof(int));
    int* x2055 = x2054;
    char** x2058 = (char**)malloc(134217728 * sizeof(char*));
    char** x2059 = x2058;
    int x2072 = 0;
    int* x2073 = (int*)malloc(67108864 * sizeof(int));
    int* x2074 = (int*)malloc(134217728 * sizeof(int));
    int x2075;
    for(x2075=0; x2075 < 67108864; x2075++) {
      x2073[x2075] = -1;
    }
    bool x2080 = false;
    int x2081 = 0;
    int* x2084 = (int*)malloc(134217728 * sizeof(int));
    int* x2085 = x2084;
    int x2090 = 0;
    int* x2091 = (int*)malloc(67108864 * sizeof(int));
    int* x2092 = (int*)malloc(134217728 * sizeof(int));
    int x2093;
    for(x2093=0; x2093 < 67108864; x2093++) {
      x2091[x2093] = -1;
    }
    struct Anon787349517* x2100 = (struct Anon787349517*)malloc(16777216 * sizeof(struct Anon787349517));
    struct Anon787349517* x2101 = x2100;
    int x2102 = 0;
    int* x2103 = (int*)malloc(16777216 * sizeof(int));
    int x2104;
    for(x2104=0; x2104 < 16777216; x2104++) {
      struct Anon787349517* x2105 = x2101;
      struct Anon787349517 x2106 = x2105[x2104];
      int x2107 = x2106.key;;
      struct Anon1023322325 x2108 = x2106.aggs;;
      struct Anon787349517 x2109;
      x2109.exists = false;
      x2109.key = x2107;
      x2109.aggs = x2108;
      x2105[x2104] = x2109;
    }
    int x2114 = 0;
    int x2116 = 0;
    struct timeval x2583, x2584, x2585;
    gettimeofday(&x2583, NULL);
    printf("%s\n","begin scan REGION");
    for (;;) {
      bool x2118 = x2080;
      bool x2119 = !x2118;
      bool x2124 = x2119;
      if (x2119) {
        int x2120 = x2081;
        int x2121 = x1650;
        bool x2122 = x2120 < x2121;
        x2124 = x2122;
      }
      bool x2125 = x2124;
      if (!x2125) break;
      int x2127 = x2081;
      int* x2128 = x1652;
      int x2129 = x2128[x2127];
      char** x2130 = x1654;
      char* x2131 = x2130[x2127];
      x2081 = x2081 + 1;
      bool x2136 = strcmp(x2131,"AFRICA") == 0;;
      if (x2136) {
        int x2137 = x2090;
        int* x2138 = x2085;
        x2138[x2137] = x2129;
        x2090 = x2090 + 1;
        int x2145 = x2129 & 67108863;
        int x2146 = x2091[x2145];
        x2091[x2145] = x2137;
        x2092[x2137] = x2146;
      } else {
      }
    }
    printf("%s\n","begin scan PART");
    for (;;) {
      bool x2154 = x2050;
      bool x2155 = !x2154;
      bool x2160 = x2155;
      if (x2155) {
        int x2156 = x2051;
        int x2157 = x1000;
        bool x2158 = x2156 < x2157;
        x2160 = x2158;
      }
      bool x2161 = x2160;
      if (!x2161) break;
      int x2163 = x2051;
      int* x2164 = x1002;
      int x2165 = x2164[x2163];
      char** x2168 = x1006;
      char* x2169 = x2168[x2163];
      char** x2172 = x1010;
      char* x2173 = x2172[x2163];
      int* x2174 = x1012;
      int x2175 = x2174[x2163];
      x2051 = x2051 + 1;
      bool x2184 = x2175 == 43;
      bool x2188 = x2184;
      if (x2184) {
        int x2186 = strlen(x2173);
        int x2185 = strlen("TIN");
        bool x2187 = strncmp(x2173+x2186-x2185,"TIN", x2185) == 0;;
        x2188 = x2187;
      }
      bool x2189 = x2188;
      if (x2189) {
        int x2190 = x2072;
        int* x2191 = x2055;
        x2191[x2190] = x2165;
        char** x2195 = x2059;
        x2195[x2190] = x2169;
        x2072 = x2072 + 1;
        int x2210 = x2165 & 67108863;
        int x2211 = x2073[x2210];
        x2073[x2210] = x2190;
        x2074[x2190] = x2211;
      } else {
      }
    }
    printf("%s\n","begin scan NATION");
    for (;;) {
      bool x2219 = x2031;
      bool x2220 = !x2219;
      bool x2225 = x2220;
      if (x2220) {
        int x2221 = x2032;
        int x2222 = x1517;
        bool x2223 = x2221 < x2222;
        x2225 = x2223;
      }
      bool x2226 = x2225;
      if (!x2226) break;
      int x2228 = x2032;
      int* x2229 = x1519;
      int x2230 = x2229[x2228];
      char** x2231 = x1521;
      char* x2232 = x2231[x2228];
      int* x2233 = x1523;
      int x2234 = x2233[x2228];
      x2032 = x2032 + 1;
      int x2239 = x2042;
      int* x2240 = x2035;
      x2240[x2239] = x2230;
      char** x2242 = x2037;
      x2242[x2239] = x2232;
      int* x2244 = x2039;
      x2244[x2239] = x2234;
      x2042 = x2042 + 1;
      int x2249 = x2230 & 67108863;
      int x2250 = x2043[x2249];
      x2043[x2249] = x2239;
      x2044[x2239] = x2250;
    }
    printf("%s\n","begin scan SUPPLIER");
    for (;;) {
      bool x2256 = x2005;
      bool x2257 = !x2256;
      bool x2262 = x2257;
      if (x2257) {
        int x2258 = x2006;
        int x2259 = x1752;
        bool x2260 = x2258 < x2259;
        x2262 = x2260;
      }
      bool x2263 = x2262;
      if (!x2263) break;
      int x2265 = x2006;
      int* x2266 = x1754;
      int x2267 = x2266[x2265];
      char** x2268 = x1756;
      char* x2269 = x2268[x2265];
      char** x2270 = x1758;
      char* x2271 = x2270[x2265];
      int* x2272 = x1760;
      int x2273 = x2272[x2265];
      char** x2274 = x1762;
      char* x2275 = x2274[x2265];
      double* x2276 = x1764;
      double x2277 = x2276[x2265];
      char** x2278 = x1766;
      char* x2279 = x2278[x2265];
      x2006 = x2006 + 1;
      int x2282 = x2022;
      int* x2283 = x2009;
      x2283[x2282] = x2267;
      char** x2285 = x2011;
      x2285[x2282] = x2269;
      char** x2287 = x2013;
      x2287[x2282] = x2271;
      int* x2289 = x2015;
      x2289[x2282] = x2273;
      char** x2291 = x2017;
      x2291[x2282] = x2275;
      double* x2293 = x2019;
      x2293[x2282] = x2277;
      char** x2295 = x2021;
      x2295[x2282] = x2279;
      x2022 = x2022 + 1;
      int x2298 = x2267 & 67108863;
      int x2299 = x2023[x2298];
      x2023[x2298] = x2282;
      x2024[x2282] = x2299;
    }
    printf("%s\n","begin scan PARTSUPP");
    for (;;) {
      bool x2305 = x2003;
      bool x2306 = !x2305;
      bool x2311 = x2306;
      if (x2306) {
        int x2307 = x2004;
        int x2308 = x1306;
        bool x2309 = x2307 < x2308;
        x2311 = x2309;
      }
      bool x2312 = x2311;
      if (!x2312) break;
      int x2314 = x2004;
      int* x2315 = x1308;
      int x2316 = x2315[x2314];
      int* x2317 = x1310;
      int x2318 = x2317[x2314];
      double* x2321 = x1314;
      double x2322 = x2321[x2314];
      x2004 = x2004 + 1;
      int x2327 = x2318 & 67108863;
      int x2328 = x2023[x2327];
      int x2329 = x2328;
      int x2375 = x2316 & 67108863;
      bool x2489 = x2322 < 1.0E100;
      for (;;) {
        int x2330 = x2329;
        bool x2331 = x2330 != -1;
        if (!x2331) break;
        int x2333 = x2329;
        int* x2334 = x2009;
        int x2335 = x2334[x2333];
        char** x2336 = x2011;
        char* x2337 = x2336[x2333];
        char** x2338 = x2013;
        char* x2339 = x2338[x2333];
        int* x2340 = x2015;
        int x2341 = x2340[x2333];
        char** x2342 = x2017;
        char* x2343 = x2342[x2333];
        double* x2344 = x2019;
        double x2345 = x2344[x2333];
        char** x2346 = x2021;
        char* x2347 = x2346[x2333];
        int x2349 = x2024[x2333];
        x2329 = x2349;
        bool x2351 = x2335 == x2318;
        if (x2351) {
          int x2354 = x2341 & 67108863;
          int x2355 = x2043[x2354];
          int x2356 = x2355;
          for (;;) {
            int x2357 = x2356;
            bool x2358 = x2357 != -1;
            if (!x2358) break;
            int x2360 = x2356;
            int* x2361 = x2035;
            int x2362 = x2361[x2360];
            char** x2363 = x2037;
            char* x2364 = x2363[x2360];
            int* x2365 = x2039;
            int x2366 = x2365[x2360];
            int x2370 = x2044[x2360];
            x2356 = x2370;
            bool x2372 = x2362 == x2341;
            if (x2372) {
              int x2376 = x2073[x2375];
              int x2377 = x2376;
              int x2406 = x2366 & 67108863;
              for (;;) {
                int x2378 = x2377;
                bool x2379 = x2378 != -1;
                if (!x2379) break;
                int x2381 = x2377;
                int* x2382 = x2055;
                int x2383 = x2382[x2381];
                char** x2386 = x2059;
                char* x2387 = x2386[x2381];
                int x2401 = x2074[x2381];
                x2377 = x2401;
                bool x2403 = x2383 == x2316;
                if (x2403) {
                  int x2407 = x2091[x2406];
                  int x2408 = x2407;
                  int x2425 = x2383 & 16777215;
                  struct Anon1023322325 x2424;
                  x2424.PS_SUPPLYCOST = x2322;
                  x2424.S_ACCTBAL = x2345;
                  x2424.S_NAME = x2337;
                  x2424.S_ADDRESS = x2339;
                  x2424.S_PHONE = x2343;
                  x2424.S_COMMENT = x2347;
                  x2424.N_NAME = x2364;
                  x2424.P_PARTKEY = x2383;
                  x2424.P_MFGR = x2387;
                  for (;;) {
                    int x2409 = x2408;
                    bool x2410 = x2409 != -1;
                    if (!x2410) break;
                    int x2412 = x2408;
                    int* x2413 = x2085;
                    int x2414 = x2413[x2412];
                    int x2420 = x2092[x2412];
                    x2408 = x2420;
                    bool x2422 = x2414 == x2366;
                    if (x2422) {
                      int x2426 = x2425;
                      struct Anon787349517* x2427 = x2101;
                      struct Anon787349517 x2428 = x2427[x2425];
                      struct Anon787349517 x2429 = x2428;
                      bool x2430 = x2428.exists;;
                      bool x2435 = x2430;
                      if (x2430) {
                        struct Anon787349517 x2431 = x2429;
                        int x2432 = x2431.key;;
                        bool x2433 = x2432 == x2383;
                        x2435 = x2433;
                      }
                      bool x2436 = x2435;
                      if (x2436) {
                        struct Anon1023322325 x2437 = x2428.aggs;;
                        struct Anon1023322325 x2438 = x2437;
                        double x2439 = x2437.PS_SUPPLYCOST;;
                        bool x2440 = x2322 < x2439;
                        if (x2440) {
                          x2438 = x2424;
                        } else {
                        }
                        struct Anon1023322325 x2444 = x2438;
                        int x2445 = x2428.key;;
                        struct Anon787349517 x2446;
                        x2446.exists = true;
                        x2446.key = x2445;
                        x2446.aggs = x2444;
                        x2427[x2425] = x2446;
                      } else {
                        for (;;) {
                          struct Anon787349517 x2449 = x2429;
                          bool x2450 = x2449.exists;;
                          bool x2520;
                          if (x2450) {
                            int x2451 = x2449.key;;
                            bool x2452 = x2451 == x2383;
                            bool x2476;
                            if (x2452) {
                              struct Anon1023322325 x2453 = x2449.aggs;;
                              struct Anon1023322325 x2454 = x2453;
                              double x2455 = x2453.PS_SUPPLYCOST;;
                              bool x2456 = x2322 < x2455;
                              if (x2456) {
                                x2454 = x2424;
                              } else {
                              }
                              struct Anon1023322325 x2460 = x2454;
                              int x2461 = x2426;
                              struct Anon787349517* x2463 = x2101;
                              struct Anon787349517 x2462;
                              x2462.exists = true;
                              x2462.key = x2451;
                              x2462.aggs = x2460;
                              x2463[x2461] = x2462;
                              x2476 = false;
                            } else {
                              int x2466 = x2426;
                              int x2467 = x2466 + 1;
                              int x2468 = x2467 % 16777215;
                              x2426 = x2468;
                              struct Anon787349517* x2470 = x2101;
                              struct Anon787349517 x2471 = x2470[x2468];
                              x2429 = x2471;
                              x2476 = true;
                            }
                            x2520 = x2476;
                          } else {
                            int x2478 = x2426;
                            double x2479 = 1.0E100;
                            double x2480 = 0.0;
                            char* x2481 = "";
                            char* x2482 = "";
                            char* x2483 = "";
                            char* x2484 = "";
                            char* x2485 = "";
                            int x2486 = 0;
                            char* x2487 = "";
                            if (x2489) {
                              x2479 = x2322;
                              x2480 = x2345;
                              x2481 = x2337;
                              x2482 = x2339;
                              x2483 = x2343;
                              x2484 = x2347;
                              x2485 = x2364;
                              x2486 = x2383;
                              x2487 = x2387;
                            } else {
                            }
                            double x2501 = x2479;
                            double x2502 = x2480;
                            char* x2503 = x2481;
                            char* x2504 = x2482;
                            char* x2505 = x2483;
                            char* x2506 = x2484;
                            char* x2507 = x2485;
                            int x2508 = x2486;
                            char* x2509 = x2487;
                            struct Anon787349517* x2512 = x2101;
                            struct Anon1023322325 x2510;
                            x2510.PS_SUPPLYCOST = x2501;
                            x2510.S_ACCTBAL = x2502;
                            x2510.S_NAME = x2503;
                            x2510.S_ADDRESS = x2504;
                            x2510.S_PHONE = x2505;
                            x2510.S_COMMENT = x2506;
                            x2510.N_NAME = x2507;
                            x2510.P_PARTKEY = x2508;
                            x2510.P_MFGR = x2509;
                            struct Anon787349517 x2511;
                            x2511.exists = true;
                            x2511.key = x2383;
                            x2511.aggs = x2510;
                            x2512[x2478] = x2511;
                            int x2514 = x2102;
                            x2103[x2514] = x2478;
                            x2102 = x2102 + 1;
                            x2520 = false;
                          }
                          if (!x2520) break;
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
    int x2545 = x2102;
    int x2547;
    for(x2547=0; x2547 < x2545; x2547++) {
      int x2548 = x2103[x2547];
      struct Anon787349517* x2549 = x2101;
      struct Anon787349517 x2550 = x2549[x2548];
      struct Anon1023322325 x2552 = x2550.aggs;;
      int x2554 = x2114;
      bool x2555 = x2554 < 100;
      bool x2556 = x2555 == false;
      if (x2556) {
      } else {
        double x2559 = x2552.S_ACCTBAL;;
        char* x2560 = x2552.S_NAME;;
        int x2561 = strlen(x2560);
        char* x2562 = x2552.N_NAME;;
        int x2563 = strlen(x2562);
        int x2564 = x2552.P_PARTKEY;;
        char* x2565 = x2552.P_MFGR;;
        int x2566 = strlen(x2565);
        char* x2567 = x2552.S_ADDRESS;;
        int x2568 = strlen(x2567);
        char* x2569 = x2552.S_PHONE;;
        int x2570 = strlen(x2569);
        char* x2571 = x2552.S_COMMENT;;
        int x2572 = strlen(x2571);
        printf("%.2f|%.*s|%.*s|%d|%.*s|%.*s|%.*s|%.*s\n",x2559,x2561,x2560,x2563,x2562,x2564,x2566,x2565,x2568,x2567,x2570,x2569,x2572,x2571);
        x2114 = x2114 + 1;
        x2116 = x2116 + 1;
      }
    }
    int x2580 = x2116;
    printf("(%d rows)\n",x2580);
    gettimeofday(&x2584, NULL);
    timeval_subtract(&x2585, &x2584, &x2583);
    fprintf(stderr,"Generated Code Profiling Info: Operation completed in %ld milliseconds\n",((x2585.tv_sec * 1000) + (x2585.tv_usec/1000)));
  }
  return 0;
}
/*****************************************
 *  End of C Generated Code              *
 *****************************************/
