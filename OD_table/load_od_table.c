#include "load_od_table.h"
#include "../tools/tools.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_CHAR_LENGTH 2850
#define MAX_TO_STATIONS 290
#define MAX_STATION_NAME_LENGTH 50

int **load_od_table(char **stations, int stations_length, char filename[]) {
  int **loaded_od_table;
  loaded_od_table = (int **)malloc(stations_length * sizeof(int *));
  int i;
  for (i = 0; i < stations_length; i++) {
    loaded_od_table[i] = (int *)malloc(stations_length * sizeof(int));
  }

  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    printf("Error in opening of file \n");
    exit(EXIT_FAILURE);
  }

  char read_line[MAX_ROW_CHAR_LENGTH];
  int row_index = 0, col_index = 0;
  char to_stations[MAX_TO_STATIONS][MAX_STATION_NAME_LENGTH];
  char from_station[MAX_STATION_NAME_LENGTH];

  while (fgets(read_line, sizeof(read_line), f)) {
    char *station;
    char *line = strdup(read_line);

    col_index = 0;
    while ((station = strsep(&line, ";"))) {
      if (row_index == 0) {
        int index = strcspn(station, "\n");
        station[index] = '\0';
        strcpy(to_stations[col_index], station);
      } else if (col_index == 0) {
        if (!is_in_string_arr(station, stations, stations_length)) {
          break;
        }
        strcpy(from_station, station);
      } else {

        for (int n = 0; n < stations_length; n++) {
          for (int j = 0; j < stations_length; j++) {
            if (strcmp(from_station, stations[n]) == 0 &&
                strcmp(to_stations[col_index], stations[j]) == 0) {
              int s_int = atoi(station);
              loaded_od_table[n][j] = s_int;
            }
          }
        }
      }

      col_index++;
    }
    row_index++;
  }
  fclose(f);
  return loaded_od_table;
}
