#include "../sim_file/sim_file.h"
#include "../userfile/fileput.h"
#include "CuTest.h"
#include <string.h>

void test_local_file_CA(CuTest *tc) {
  SimFile sim_file;
  load_local_file(&sim_file, "test/userfiles/copen_aalborg.txt");
  CuAssertStrEquals(tc, "Copenhagen", sim_file.origin);
  CuAssertStrEquals(tc, "Aalborg", sim_file.destination);
  CuAssertStrEquals(tc, "Copenhagen", sim_file.start_airport);
  CuAssertStrEquals(tc, "Aalborg", sim_file.end_airport);
  CuAssertIntEquals(tc, 60, sim_file.flight_time_min);
  CuAssertIntEquals(tc, 60, sim_file.airport_prep_time_min);
  CuAssertIntEquals(tc, 0, sim_file.station_prep_time_min);
  CuAssertIntEquals(tc, 20, sim_file.station_removal_percentage);
  CuAssertIntEquals(tc, 10, sim_file.turnover_time);
  CuAssertIntEquals(tc, 250, sim_file.hst_top_speed_kmt);
  CuAssertIntEquals(tc, 40, sim_file.acceleration);
}

void test_local_file_RG(CuTest *tc) {
  SimFile sim_file;
  load_local_file(&sim_file, "test/userfiles/randers_grenaa.txt");
  CuAssertStrEquals(tc, "Randers St.", sim_file.origin);
  CuAssertStrEquals(tc, "Grenaa vej nummer 4", sim_file.destination);
  CuAssertStrEquals(tc, "Mums", sim_file.start_airport);
  CuAssertStrEquals(tc, "Grenaa lufthavn", sim_file.end_airport);
  CuAssertIntEquals(tc, 70, sim_file.flight_time_min);
  CuAssertIntEquals(tc, 30, sim_file.airport_prep_time_min);
  CuAssertIntEquals(tc, 10, sim_file.station_prep_time_min);
  CuAssertIntEquals(tc, 1, sim_file.station_removal_percentage);
  CuAssertIntEquals(tc, 5, sim_file.turnover_time);
  CuAssertIntEquals(tc, 180, sim_file.hst_top_speed_kmt);
  CuAssertIntEquals(tc, 1000, sim_file.acceleration);
}

void test_local_file_PF(CuTest *tc) {
  SimFile sim_file;
  load_local_file(&sim_file, "test/userfiles/praestoe_fanoe.txt");
  CuAssertStrEquals(tc, "Præstø", sim_file.origin);
  CuAssertStrEquals(tc, "Fanø", sim_file.destination);
  CuAssertStrEquals(tc, "præstø lufthavn", sim_file.start_airport);
  CuAssertStrEquals(tc, "Fanø lufthavn", sim_file.end_airport);
  CuAssertIntEquals(tc, 120, sim_file.flight_time_min);
  CuAssertIntEquals(tc, 1, sim_file.airport_prep_time_min);
  CuAssertIntEquals(tc, 999, sim_file.station_prep_time_min);
  CuAssertIntEquals(tc, 235, sim_file.station_removal_percentage);
  CuAssertIntEquals(tc, -10, sim_file.turnover_time);
  CuAssertIntEquals(tc, 155, sim_file.hst_top_speed_kmt);
  CuAssertIntEquals(tc, 1, sim_file.acceleration);
}

CuSuite *userfile_get_suite() {
  CuSuite *suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, test_local_file_CA);
  SUITE_ADD_TEST(suite, test_local_file_RG);
  SUITE_ADD_TEST(suite, test_local_file_PF);

  return suite;
}
