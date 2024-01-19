#include "application.h"
#include "userfile_generator/userfile_generator.h"
#include <stdio.h>
#include <string.h>

int main(const int argc, char **argv) {

  if (argc <= 1) {
    printf("No file entered\n");
    return 0;
  }
  for (int i = 1; i < argc; ++i) {
    if (!strcmp(argv[i], "--gen")) {
      run_file_gen();
      return 0;
    }
  }
  int dash_r_index = argc;
  char *rails_file = "rails.csv";
  for (int i = 1; i < argc - 1; ++i) {
    if (!strcmp(argv[i], "-r")) {
      dash_r_index = i;
      rails_file = argv[i + 1];
      break;
    }
  }

  for (int i = 1; i < argc; ++i) {
    if(i != dash_r_index && i != dash_r_index + 1){
     run(argv[i], rails_file);
    }
  }
  return 0;
}
