#include <string.h>
#include "CuTest.h"
#include "../userfile/fileput.h"
#include "../sim_file/sim_file.h"

void test_local_file_CA(CuTest *tc){
SimFile sim_file;
load_local_file(&sim_file);
CuAssertIntEquals(tc, strcmp("Copenhagen", sim_file.origin), 0);
CuAssertIntEquals(tc, strcmp("Aalborg", sim_file.destination), 0);
}


CuSuite *userfile_get_suite() {
  CuSuite *suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, test_local_file_CA);

  return suite;
}
