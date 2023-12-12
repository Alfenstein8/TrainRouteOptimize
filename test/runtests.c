#include <stdio.h>
#include "CuTest.h"

#include "test_userfile.h"
#include "test_remove_stations.h"


void run_all_tests();

int main(void){
  run_all_tests();
  return 0;
}

void run_all_tests(){
  CuString *output = CuStringNew();
  CuSuite *suite = CuSuiteNew();

  // Adding test suites:
  CuSuiteAddSuite(suite, (CuSuite *)userfile_get_suite());
  CuSuiteAddSuite(suite, (CuSuite *)remove_stations_get_suite());

  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);
  printf("%s\n", output->buffer);

}
