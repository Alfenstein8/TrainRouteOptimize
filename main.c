#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sim_file/sim_file.h"
#include "air_travel_time/air_travel_time.h"
#include "rails/rails.h"
#include "remove_stations/remove_stations.h"

/*Functions*/
FILE* load_local_file(char* file_path);
int** load_od_table(int** interaction_table);

int main(void) {
  SimFile sim_file_data;
  char* file_path; /*The file path that the user provides*/
  char* stations[10] = {"København H", "Odense St.",  "Fredericia St.",
                        "Vejle St.",   "Horsens St.", "Skanderborg St.",
                        "Aahus St.",   "Randers St.", "Hobro St.",
                        "Aalborg St."};
  Rail* rails = load_rails("rails.csv", stations, 10);

struct TrainRoute train_route[] = {
        {"Station1", 50},
        {"Station2", 30},
        {"Station3", 70},
        // ... (indsæt flere stationer)
    };

    int num_stations = sizeof(train_route) / sizeof(train_route[0]);
    int removal_percentage = 30;

    remove_low_interaction_stations(train_route, num_stations, removal_percentage);

    int travel_time_origin_destination = 40;
    sim_file_data.airport_prep_time_min = 60;
    sim_file_data.flight_time_min = 70;

    int air = get_total_air_travel_time(sim_file_data , travel_time_origin_destination);

  return 0;
}
