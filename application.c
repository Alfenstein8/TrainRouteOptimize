#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "air_travel_time/air_travel_time.h"
#include "calc_all_interaction_levels/calc_interaction.h"
#include "rails/rails.h"
#include "remove_stations/remove_stations.h"
#include "sim_file/sim_file.h"
#include "userfile/fileput.h"

void run(const char *file_path) {
  SimFile sim_file_data;

  load_local_file(&sim_file_data, file_path);

  printf("%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", sim_file_data.origin,
         sim_file_data.destination, sim_file_data.start_airport, sim_file_data.end_airport,
         sim_file_data.flight_time_min, sim_file_data.airport_prep_time_min,
         sim_file_data.station_prep_time_min, sim_file_data.station_removal_percentage,
         sim_file_data.turnover_time, sim_file_data.hst_top_speed_kmt, sim_file_data.acceleration);

  int num_of_stations = 10;

  char *stations[] = {"København H", "Odense St.",      "Fredericia St.", "Vejle St.",
                      "Horsens St.", "Skanderborg St.", "Aahus St.",      "Randers St.",
                      "Hobro St.",   "Aalborg St."};
  Rail *rails = load_rails("rails.csv", stations, num_of_stations);

  /*Missing load_od_table()*/
  int OD_table[10][10] = {
      {5123, 164, 1436, 34, 632, 1235, 1235, 6423, 3456, 72},
      {5123, 164, 1436, 34, 632, 1235, 1235, 6423, 3456, 72},
      {5123, 164, 1436, 34, 632, 1235, 1235, 6423, 3456, 72},
      {5123, 164, 1436, 34, 632, 1235, 1235, 6423, 3456, 72},
      {5123, 164, 1436, 34, 632, 1235, 1235, 6423, 3456, 72},
      {5123, 164, 1436, 34, 632, 1235, 1235, 6423, 3456, 72},
      {5123, 164, 1436, 34, 632, 1235, 1235, 6423, 3456, 72},
      {5123, 164, 1436, 34, 632, 1235, 1235, 6423, 3456, 72},
      {5123, 164, 1436, 34, 632, 1235, 1235, 6423, 3456, 72},
      {5123, 164, 1436, 34, 632, 1235, 1235, 6423, 3456, 72},
  };

  int *interaction_levels = calculate_all_interaction_levels(num_of_stations, (int *)OD_table);

  int removal_percentage = 100;

  int hst_route[num_of_stations];
  int hst_route_size = remove_low_interaction_stations(interaction_levels, num_of_stations,
                                                       removal_percentage, hst_route);

  int travel_time_origin_destination = 40;

  int air = get_total_air_travel_time(sim_file_data, travel_time_origin_destination);
}
