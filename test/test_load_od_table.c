#include "../OD_table/load_od_table.h"
#include "CuTest.h"
#include <string.h>

void test_load_od_table_bred_arden(CuTest *tc) {
  char *stations[2] = {"Bred", "Arden"};
  int **od_table = load_od_table(stations, 2, "test/OD_table/OD_modified.csv");
  CuAssertIntEquals(tc, 0, od_table[0][0]);
  CuAssertIntEquals(tc, 3, od_table[0][1]);
  CuAssertIntEquals(tc, 3, od_table[1][0]);
  CuAssertIntEquals(tc, 0, od_table[1][1]);
}

void test_load_od_table_ddb(CuTest *tc) {
  char *stations[3] = {"Dybboelsbro", "Danshoej", "Bur"};
  int **od_table = load_od_table(stations, 3, "test/OD_table/OD_modified.csv");
  CuAssertIntEquals(tc, 0, od_table[0][0]);
  CuAssertIntEquals(tc, 8062, od_table[0][1]);
  CuAssertIntEquals(tc, 0, od_table[0][2]);
  CuAssertIntEquals(tc, 8062, od_table[1][0]);
  CuAssertIntEquals(tc, 0, od_table[1][1]);
  CuAssertIntEquals(tc, 0, od_table[1][2]);
  CuAssertIntEquals(tc, 0, od_table[2][0]);
  CuAssertIntEquals(tc, 0, od_table[2][1]);
  CuAssertIntEquals(tc, 0, od_table[2][2]);
}

CuSuite *load_od_table_get_suite() {
  CuSuite *suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, test_load_od_table_bred_arden);
  SUITE_ADD_TEST(suite, test_load_od_table_ddb);

  return suite;
}

