#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIELD_SIZE 12

enum types { INT, STRING, DOUBLE };

struct user_field {
  char *name;
  enum types type;
};
typedef struct user_field user_field;

user_field fields[FIELD_SIZE] = {{"Origin", STRING},
                                 {"Destination", STRING},
                                 {"Start Airport", STRING},
                                 {"End Airport", STRING},
                                 {"Flight Time In Minutes", INT},
                                 {"Airport Preperation Time", INT},
                                 {"Station Preperation Time", INT},
                                 {"Station Percent", INT},
                                 {"Station Turnover Time", INT},
                                 {"High-Speed-Train (HST) Top Speed", INT},
                                 {"High-Speed-Train (HST) Acceleration", DOUBLE},
                                 {"ICL top speed", INT}};

void run_file_gen(void) {
  char filename[100];

  printf("Name of new file: ");
  scanf(" %s", filename);

  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("Something went wrong!");
    exit(EXIT_FAILURE);
  }

  int int_value;
  double double_value;
  char string_value[100];
  for (int i = 0; i < FIELD_SIZE; ++i) {
    switch (fields[i].type) {
    case INT:
      printf("%s: ", fields[i].name);
      scanf(" %d", &int_value);
      fprintf(fp, "%s: %d\n", fields[i].name, int_value);
      break;
    case DOUBLE:
      printf("%s: ", fields[i].name);
      scanf(" %lf", &double_value);
      fprintf(fp, "%s: %lf\n", fields[i].name, double_value);
      break;
    case STRING:
      printf("%s: ", fields[i].name);
      scanf(" %[^\n]", string_value);
      fprintf(fp, "%s: %s\n", fields[i].name, string_value);
      break;
    }
  }
  fclose(fp);
}
