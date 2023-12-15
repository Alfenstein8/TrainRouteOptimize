#include "../rails/rails.h"
#include "CuTest.h"
#include <string.h>

void test_load_rails(CuTest *tc) {
  char *stations[10] = {"København H", "Odense St.",      "Fredericia St.", "Vejle St.",
                        "Horsens St.", "Skanderborg St.", "Aahus St.",      "Randers St.",
                        "Hobro St.",   "Aalborg St."};
  Rail *rails = load_rails("test/rails/rails.csv", stations, 10);
  CuAssertIntEquals(tc, 156, rails[0].length);
  CuAssertIntEquals(tc, 58, rails[1].length);
  CuAssertIntEquals(tc, 25, rails[2].length);
  CuAssertIntEquals(tc, 32, rails[3].length);
  CuAssertIntEquals(tc, 28, rails[4].length);
  CuAssertIntEquals(tc, 22, rails[5].length);
  CuAssertIntEquals(tc, 59, rails[6].length);
  CuAssertIntEquals(tc, 31, rails[7].length);
  CuAssertIntEquals(tc, 49, rails[8].length);
  CuAssertIntEquals(tc, 0, rails[9].length);
}

CuSuite *load_rails_get_suite() {
  CuSuite *suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, test_load_rails);

  return suite;
}

