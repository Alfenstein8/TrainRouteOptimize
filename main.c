#include "application.h"
int main(const int argc, char **argv) {
  for (int i = 1; i < argc; ++i) {
    run(argv[i]);
  }
  return 0;
}
