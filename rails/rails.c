#include "rails.h"
#include "../tools/tools.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_in_string_arr(const char *string, char **arr, int arr_size);

Rail *load_rails(const char *file_path, char **station_names, int station_amount) {
  Rail *rails = (Rail *)malloc(sizeof(Rail) * station_amount);
  FILE *file;
  file = fopen(file_path, "r");
  if (file == NULL) {
    printf("Invalid file path");
  }

  char read_line[500];
  char destinations[100][50];
  char origin[50];

  int row = 0, column = 0;

  while (fgets(read_line, sizeof(read_line), file)) {
    char *token;                    // current cell value
    char *line = strdup(read_line); // Create a pointer to a duplicate of the string

    column = 0;
    while ((token = strsep(&line, ","))) { // Go to next cell
      if (row == 0) {
        int index = strcspn(token, "\n"); // Remove trailing \n if any are found
        token[index] = '\0';
        strcpy(destinations[column], token);
      } else if (column == 0) {
        if (!is_in_string_arr(token, station_names, station_amount)) {
          break;
        }
        strcpy(origin, token);
      } else {
        for (int i = 0; i < station_amount; ++i) {
          if (!strcmp(origin, station_names[i]) &&
              !strcmp(destinations[column], station_names[i + 1])) {
            sscanf(token, " %d/%d ", &rails[i].length, &rails[i].top_speed);
          }
        }
      }
      ++column;
    }
    ++row;
  }
  fclose(file);
  rails[station_amount-1].length = 0;
  rails[station_amount-1].top_speed = 0;
  return rails;
}

int is_in_string_arr(const char *string, char **arr, int arr_size) {
  for (int i = 0; i < arr_size; ++i) {
    if (!strcmp(string, arr[i])) {
      return 1;
    }
  }
  return 0;
}
