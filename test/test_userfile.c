#include "../sim_file/sim_file.h"
#include "../userfile/fileput.h"
#include "CuTest.h"
#include <string.h>

void test_local_file_CA(CuTest *tc) {
  SimFile sim_file;
  load_local_file(&sim_file);
  CuAssertIntEquals(tc, 0, strcmp("Copenhagen", sim_file.origin));
  CuAssertIntEquals(tc, 0, strcmp("Aalborg", sim_file.destination));
  CuAssertIntEquals(tc, 0, strcmp("Copenhagen", sim_file.start_airport));
  CuAssertIntEquals(tc, 0, strcmp("Aalborg", sim_file.end_airport));
  CuAssertIntEquals(tc, 60, sim_file.flight_time_min);
  CuAssertIntEquals(tc, 60, sim_file.airport_prep_time_min);
  CuAssertIntEquals(tc, 0, sim_file.station_prep_time_min);
  CuAssertIntEquals(tc, 20, sim_file.station_removal_percentage);
  CuAssertIntEquals(tc, 10, sim_file.turnover_time);
  CuAssertIntEquals(tc, 250, sim_file.hst_top_speed_kmt);
  CuAssertIntEquals(tc, 40, sim_file.acceleration);
}

CuSuite *userfile_get_suite() {
  CuSuite *suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, test_local_file_CA);

  return suite;
}
