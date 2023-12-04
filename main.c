#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int x, y;
} pos;

typedef struct {
  pos origin, destination;
  pos start_airport, end_airport;
  int flight_time, airport_prep_time;
  int station_removal_percentage;
  int depart_offset;
  int turnover_time;
  int acceleration;
  int hst_speed;
} SimData;

typedef struct {
  int length, top_speed;
} Rail;

/*Functions*/
FILE* load_local_file(char* file_path);
int** load_od_table(int** interaction_table);
Rail* load_rails(const char* file_path, char** station_names,
                 int station_amount);
int str_exists(char* str, char** strs, int size);

int main(void) {
  SimData data;
  char* file_path; /*The file path that the user provides*/
  char* stations[10] = {"København H", "Odense St.",  "Fredericia St.",
                        "Vejle St.",   "Horsens St.", "Skanderborg St.",
                        "Aahus St.",   "Randers St.", "Hobro St.",
                        "Aalborg St."};
  load_rails("rails.csv", stations, 10);
  return 0;
}

Rail* load_rails(const char* file_path, char** station_names,
                 int station_amount) {
  Rail* rails = (Rail*)malloc(sizeof(Rail) * station_amount);
  FILE* file;
  file = fopen(file_path, "r");
  if (file == NULL) {
    printf("Invalid file path");
  }

  char read_line[500];
  char destinations[100][50];
  char origin[50];

  int i = 0, j = 0;

  while (fgets(read_line, sizeof(read_line), file)) {
    char* token;
    char* line = strdup(read_line);

    j = 0;
    while ((token = strsep(&line, ","))) {
      if (i == 0) {
        int index = strcspn(token, "\n"); // Remove trailing \n if any found 
        token[index] = '\0';
        strcpy(destinations[j], token);
      } else if (j == 0) {
        strcpy(origin, token);
      } else {
        for (int o = 0; o < station_amount; ++o) {
          if (!strcmp(origin, station_names[o]) &&
              !strcmp(destinations[j], station_names[o + 1])) {
            sscanf(token, " %d/%d ", &rails[o].length, &rails[o].top_speed);
          }
        }
      }
      ++j;
    }
    ++i;
  }
  fclose(file);
  return rails;
}

int str_exists(char* str, char** strs, int size) { return 1; }
