#include "../calc_all_interaction_levels/calc_interaction.h"
#include "CuTest.h"
#include <string.h>

void test_calc_interaction1to10(CuTest *tc) {
  int OD_table[10][10] = {
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
  };
  int *levels = calculate_all_interaction_levels(10, (int *)OD_table);
  for (int i = 0; i < 10; ++i) {
    CuAssertIntEquals(tc, (i + 1) * 10 + 55 - ((i + 1) * 2), levels[i]);
  }
}

void test_calc_interaction1(CuTest *tc) {
  int OD_table[10][10] = {
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  };
  int *levels = calculate_all_interaction_levels(10, (int *)OD_table);
  for (int i = 0; i < 10; ++i) {
    CuAssertIntEquals(tc, 18, levels[i]);
  }
}

CuSuite *calc_interaction_get_suite() {
  CuSuite *suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, test_calc_interaction1to10);
  SUITE_ADD_TEST(suite, test_calc_interaction1);

  return suite;
}
