#include "application.h"
#include "userfile_generator/userfile_generator.h"
#include <stdio.h>
#include <string.h>

int main(const int argc, char **argv) {

  if (argc <= 1) {
    printf("No file entered\n");
    return 0;
  }
  int found_gen = 0;
  for (int i = 1; i < argc; ++i) {
    if (!strcmp(argv[i], "--gen")) {
      found_gen = 1;
      run_file_gen();
    }
  }
  if (found_gen) {
    return 0;
  }
  int sim_files_to = argc;
  char *rails_file = "rails.csv";
  for (int i = 1; i < argc - 1; ++i) {
    if (!strcmp(argv[i], "-r")) {
      sim_files_to = i;
      rails_file = argv[i + 1];
      break;
    }
  }

  for (int i = 1; i < sim_files_to; ++i) {
    run(argv[i], rails_file);
  }
  return 0;
}
