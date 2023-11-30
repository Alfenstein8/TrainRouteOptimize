#include <stdio.h>

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


/*Functions*/
FILE *load_local_file(char* file_path);
int** load_od_table(int** interaction_table);

int main(void) {
  SimData data;
  char* file_path; /*The file path that the user provides*/

  return 0;
}
