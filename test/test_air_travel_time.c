#include "../air_travel_time/air_travel_time.h"
#include "../sim_file/sim_file.h"
#include "CuTest.h"
#include <string.h>

void test_air_travel_time_606060(CuTest *tc) {
  SimFile sim_file;
  sim_file.flight_time_min = 60;
  sim_file.airport_prep_time_min = 60;
  int travel_time_od = 60;
  int total_time = get_total_air_travel_time(sim_file, travel_time_od);

  CuAssertIntEquals(tc, 180, total_time);
}

CuSuite *air_travel_time_get_suite() {
  CuSuite *suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, test_air_travel_time_606060);

  return suite;
}

