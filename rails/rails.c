#include "rails.h"
#include "../tools/tools.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 500
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_OF_STATIONS 100

void load_rails(const char *file_path, char **station_names, int station_amount, Rail *rails) {
  FILE *file;
  file = fopen(file_path, "r");
  if (file == NULL) {
    printf("Invalid file path");
  }

  char read_line[MAX_LINE_LENGTH];
  char destinations[MAX_AMOUNT_OF_STATIONS][MAX_NAME_LENGTH];
  char origin[MAX_NAME_LENGTH];

  int row = 0, column = 0;

  while (fgets(read_line, sizeof(read_line), file)) {
    char *token;                    // current cell value
    char *line = read_line; // Create a pointer to a duplicate of the string

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
            rails->station_number = i;
          }
        }
      }
      ++column;
    }
    ++row;
  }
  fclose(file);
  rails[station_amount - 1].length = 0;
  rails[station_amount - 1].top_speed = 0;
}

