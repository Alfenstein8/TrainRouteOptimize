#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "OD_table/load_od_table.h"
#include "air_travel_time/air_travel_time.h"
#include "calc_all_interaction_levels/calc_interaction.h"
#include "create_line/create_new_line.h"
#include "display/display.h"
#include "new_rails/new_rail.h"
#include "offset/offset.h"
#include "rails/rails.h"
#include "rejseplan_fake_api/rejseplan_fake_api.h"
#include "remove_stations/remove_stations.h"
#include "sim_file/sim_file.h"
#include "userfile/fileput.h"

#define MAX_NUMBER_OF_STATIONS 10

int get_total_time(double *line, int size, int turnover_time);

void run(const char *file_path) {
  SimFile sim_file_data;

  load_local_file(&sim_file_data, file_path);

  char *stations[MAX_NUMBER_OF_STATIONS];
  const int num_of_stations = api_get_route("København", "Aalborg", stations);

  Rail *rails = load_rails("rails.csv", stations, num_of_stations);

  int **loaded_od_table = load_od_table(stations, num_of_stations, "OD_modified.csv");

  int *interaction_levels = calculate_all_interaction_levels(num_of_stations, loaded_od_table);

  for (int i = 0; i < num_of_stations; i++) {
    free(loaded_od_table[i]);
  }
  free(loaded_od_table);

  int hst_route[num_of_stations];
  int hst_route_size = remove_low_interaction_stations(
      interaction_levels, num_of_stations, sim_file_data.station_removal_percentage, hst_route);

  Rail *new_rails_hst = make_new_rails(rails, hst_route, hst_route_size);

  double *hst_line = create_new_line(sim_file_data.acceleration, new_rails_hst, hst_route_size);

  for (int i = 0; i < hst_route_size; ++i) {
    // printf("length: %d\n",rails[i].length);
    // printf("speed: %lf\n",hst_line[i]);
  }

  double *icl_line = create_new_line(sim_file_data.acceleration, rails, num_of_stations);

  free(rails);

  int travel_time_origin_destination = get_od_time();

  int air_travel_time = get_total_air_travel_time(sim_file_data, travel_time_origin_destination);

  int offset_time =
      calculate_departure_offset(new_rails_hst, rails, hst_line, icl_line, hst_route_size,
                                 num_of_stations, sim_file_data.turnover_time);

  int new_line_time = get_total_time(hst_line,hst_route_size, sim_file_data.turnover_time);
  int original_line_time = get_total_time(icl_line,num_of_stations, sim_file_data.turnover_time);
  print_travel_times(new_line_time, original_line_time, air_travel_time, offset_time);

  free(new_rails_hst);
}

int get_total_time(double *line, int size, int turnover_time) {
  int time = 0;
  for (int i = 0; i < size; ++i) {
    time += line[i] + turnover_time;
  }
  return time;
}
