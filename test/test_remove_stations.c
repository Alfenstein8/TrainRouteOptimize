#include "../remove_stations/remove_stations.h"
#include "CuTest.h"
#include <string.h>

void test_rm_stations_0to11(CuTest *tc) {
  int number_of_stations = 12;
  int test_route[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  int removal_percentage = 50;
  int new_route[number_of_stations];
  int new_route_size = remove_low_interaction_stations(test_route, number_of_stations,
                                                       removal_percentage, new_route);
  CuAssertIntEquals(tc, new_route_size, 7);
  CuAssertIntEquals(tc, 0, new_route[0]);
  for (int i = 1; i <= 6; ++i) {
    CuAssertIntEquals(tc, i + 5, new_route[i]);
  }
}

CuSuite *remove_stations_get_suite() {
  CuSuite *suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, test_rm_stations_0to11);

  return suite;
}

