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

int get_total_time(double *line, int size, int turnover_time);
void free_2darray(void **array, int size);

void run(const char *file_path, const char *rails_path) {
  SimFile sim_file;

  if(load_local_file(&sim_file, file_path)){
    printf("The simulation file '%s' does not exist or is not formatted correctly\n",file_path);
    exit(EXIT_FAILURE);
  }

  int icl_line_length;
  char **stations = api_get_route("København", "Aalborg", &icl_line_length);

  Rail all_rails[icl_line_length];
  if(load_rails(rails_path, stations, icl_line_length, all_rails)){
    printf("The rails file '%s' does not exist\n",rails_path);
    exit(EXIT_FAILURE);
  }

  int **od_table = load_od_table(stations, icl_line_length, "OD_modified.csv");
  int *interaction_levels = calculate_all_interaction_levels(icl_line_length, od_table);
  free_2darray((void **)od_table, icl_line_length);

  int hst_station_numbers[icl_line_length];
  int hst_line_length =
      remove_low_interaction_stations(interaction_levels, icl_line_length,
                                      sim_file.station_removal_percentage, hst_station_numbers);

  free_2darray((void **)stations, icl_line_length-1);
  Rail *hst_rails = make_new_rails(all_rails, hst_station_numbers, hst_line_length);

  double *hst_times = create_new_line(sim_file.acceleration, hst_rails, hst_line_length,
                                      sim_file.hst_top_speed_kmt);
  double *icl_times =
      create_new_line(sim_file.acceleration, all_rails, icl_line_length, sim_file.icl_top_speed);

  int misc_travel_time = get_od_time(); // miscellaneous travel time
  int air_travel_time = get_total_air_travel_time(sim_file, misc_travel_time);

  int offset_time =
      calculate_departure_offset(hst_rails, all_rails, hst_times, icl_times, hst_line_length,
                                 icl_line_length, sim_file.turnover_time);

  int new_line_time = get_total_time(hst_times, hst_line_length, sim_file.turnover_time);
  int original_line_time = get_total_time(icl_times, icl_line_length, sim_file.turnover_time);
  print_travel_times(file_path,new_line_time, original_line_time, air_travel_time, offset_time);

  free(hst_rails);
}

int get_total_time(double *line, int size, int turnover_time) {
  int time = 0;
  for (int i = 0; i < size; ++i) {
    time += line[i] + turnover_time;
  }
  return time;
}

void free_2darray(void **array, int size) {
  for (int i = 0; i < size; i++) {
    free(array[i]);
  }
  free(array);
}
