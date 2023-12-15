#include "application.h"
#include "userfile_generator/userfile_generator.h"
#include <stdio.h>
#include <string.h>

int main(const int argc, char **argv) {

  if (argc <= 1) {
    printf("No file entered");
    return 0;
  }
  int found_gen = 0;
  for (int i = 1; i < argc; ++i) {
    if (!strcmp(argv[i], "--gen")) {
      found_gen = 1;
      run_file_gen();
    }
  }
  if (!found_gen) {
    for (int i = 1; i < argc; ++i) {
      run(argv[i]);
    }
  }
  return 0;
}
