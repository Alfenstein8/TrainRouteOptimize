#include <stdio.h>
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
  char** stations;
  load_rails("rails.csv", stations, 10);
  return 0;
}

Rail* load_rails(const char* file_path, char** station_names,
                 int station_amount) {
  Rail rails[100][100];
  FILE* file;
  file = fopen(file_path, "r");
  if (file == NULL) {
    printf("Invalid file path");
  }

  char line[1000];
  int destinations[100];
  int origins[100];

  printf("%s", line);
  int i = 0, j = 0;
  int d = 0, o = 0;

  while (fgets(line, sizeof(line), file)) {
    char* token;
    token = strtok(line, ",");
    while (token != NULL) {
      if (!i && !j) {
        continue;
      }
      if (i == 0 && str_exists(token, station_names, station_amount)) {
        sscanf(token, "%d", &destinations[d]);
        ++d;
        continue;
      }
      if (j == 0 && str_exists(token, station_names, station_amount)) {
        sscanf(token, "%d", &origins[o]);
        ++o;
        continue;
      }
      sscanf(token, "%d/%d", &rails[i][j].length, &rails[i][j].top_speed);
      printf("length: %d/ speed: %d\n ", rails[i][j].length, rails[i][j].top_speed);
      token = strtok(NULL, ",");
      ++j;
    }
    ++i;
  }
  printf("\n\n %d", rails[0][1].length);
  fclose(file);
  return rails;
}

int str_exists(char* str, char** strs, int size) { return 1; }
