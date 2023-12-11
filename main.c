#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "air_travel_time/air_travel_time.h"
#include "rails/rails.h"
#include "remove_stations/remove_stations.h"
#include "sim_file/sim_file.h"
#include "userfile/fileput.h"

int main(void) {
  SimFile sim_file_data;
  char *file_path; /*The file path that the user provides*/

  load_local_file(&sim_file_data);
  printf("%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", sim_file_data.origin, sim_file_data.destination, 
  sim_file_data.start_airport, sim_file_data.end_airport, sim_file_data.flight_time_min, sim_file_data.airport_prep_time_min, 
  sim_file_data.station_prep_time_min, sim_file_data.station_removal_percentage, sim_file_data.turnover_time, 
  sim_file_data.hst_top_speed_kmt, sim_file_data.acceleration);
  
  char *stations[10] = {"København H", "Odense St.",      "Fredericia St.", "Vejle St.",
                        "Horsens St.", "Skanderborg St.", "Aahus St.",      "Randers St.",
                        "Hobro St.",   "Aalborg St."};
  Rail *rails = load_rails("rails.csv", stations, 10);

  struct TrainRoute train_route[] = {
      {"Station1", 50}, {"Station2", 30}, {"Station3", 70},
      // ... (indsæt flere stationer)
  };

  int num_stations = sizeof(train_route) / sizeof(train_route[0]);

  remove_low_interaction_stations(train_route, num_stations, sim_file_data.station_removal_percentage);

  int travel_time_origin_destination = 40;

  int air = get_total_air_travel_time(sim_file_data, travel_time_origin_destination);


  return 0;
}
