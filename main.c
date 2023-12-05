#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rails/rails.h"
#include "air_travel_time/air_travel_time.h"

typedef struct {
  int x, y;
} pos;

typedef struct {
  pos origin, destination;
  pos start_airport, end_airport;
  int flight_time, airport_prep_time;
  int station_removal_percentage;
  int depart_offset;
  int turnover_time
  int acceleration;
  int hst_speed;
} SimData;

/*Functions*/
FILE* load_local_file(char* file_path);
int** load_od_table(int** interaction_table);

int main(void) {
  SimData data;
  char* file_path; /*The file path that the user provides*/
  char* stations[10] = {"København H", "Odense St.",  "Fredericia St.",
                        "Vejle St.",   "Horsens St.", "Skanderborg St.",
                        "Aahus St.",   "Randers St.", "Hobro St.",
                        "Aalborg St."};
  Rail* rails = load_rails("rails.csv", stations, 10);
  int air = get_total_air_travel_time(SimFile , int travel_time_origin_destination);

  return 0;
}

