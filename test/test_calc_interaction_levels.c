#include "../calc_all_interaction_levels/calc_interaction.h"
#include "CuTest.h"
#include <string.h>
#include <stdlib.h>

void test_calc_interaction1to10(CuTest *tc) {

  int **OD_table;
  OD_table = (int **)malloc(10 * sizeof(int *));
  
  for (int i = 0; i < 10; i++){
      OD_table[i] = (int *)malloc(10 * sizeof(int));
  }

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      OD_table[i][j] = j+1; 
    }
  }


  int *levels = calculate_all_interaction_levels(10, OD_table);
  for (int i = 0; i < 10; ++i) {
    CuAssertIntEquals(tc, (i + 1) * 10 + 55 - ((i + 1) * 2), levels[i]);
  }


  
  for (int i = 0; i < 10; i++) {
      free(OD_table[i]);
  }free(OD_table);
}

void test_calc_interaction1(CuTest *tc) {
  int **OD_table;
  OD_table = (int **)malloc(10 * sizeof(int *));
  
  for (int i = 0; i < 10; i++){
      OD_table[i] = (int *)malloc(10 * sizeof(int));
  }

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      OD_table[i][j] = 1; 
    }
  }
  


  int *levels = calculate_all_interaction_levels(10, OD_table);
  for (int i = 0; i < 10; ++i) {
    CuAssertIntEquals(tc, 18, levels[i]);
  }


  for (int i = 0; i < 10; i++) {
      free(OD_table[i]);
  }free(OD_table);
}

CuSuite *calc_interaction_get_suite() {
  CuSuite *suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, test_calc_interaction1to10);
  SUITE_ADD_TEST(suite, test_calc_interaction1);

  return suite;
}
