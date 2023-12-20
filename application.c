#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "OD_table/load_od_table.h"
#include "air_travel_time/air_travel_time.h"
#include "calc_all_interaction_levels/calc_interaction.h"
#include "new_rails/new_rail.h"
#include "rails/rails.h"
#include "rejseplan_fake_api/rejseplan_fake_api.h"
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

  char *stations[10];
  const int num_of_stations = api_get_route("København", "Aalborg", stations);

  Rail *rails = load_rails("rails.csv", stations, num_of_stations);

  int **loaded_od_table = load_od_table(stations, num_of_stations, "OD_modified.csv");

  int d, p;
  for (d = 0; d < num_of_stations; d++) {
    for (p = 0; p < num_of_stations; p++) {
      printf("%d ", loaded_od_table[d][p]);
    }
    printf("\n");
  }

  int *interaction_levels = calculate_all_interaction_levels(num_of_stations, loaded_od_table);

  int removal_percentage = 100;

  int hst_route[num_of_stations];
  int hst_route_size = remove_low_interaction_stations(interaction_levels, num_of_stations,
                                                       removal_percentage, hst_route);

  Rail *new_rails_hst = make_new_rails(rails, hst_route, hst_route_size);
  free(rails);

  int travel_time_origin_destination = 40;

  int air = get_total_air_travel_time(sim_file_data, travel_time_origin_destination);

  free(new_rails_hst);

  int b;
  for (b = 0; b < num_of_stations; b++) {
    free(loaded_od_table[b]);
  }
  free(loaded_od_table);
}
