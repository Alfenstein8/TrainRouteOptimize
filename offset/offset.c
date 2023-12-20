#include "../rails/rails.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_OFFSET_ALLOWED_MINUTES 60

int calculate_departure_offset(Rail *new_rail, Rail *original_rail, double new_line[],
                               double original_line[], int new_station_amount,
                               int original_station_amount, int turnover_time) {

  double original_arrival_times[original_station_amount];
  int original_start_time = 0;
  original_arrival_times[0] = original_start_time;

  for (int i = 1; i < original_station_amount; ++i) {
    double time_taken = original_line[i - 1];

    original_arrival_times[i] = original_arrival_times[i - 1] + time_taken;
  }

  double new_arrival_times[new_station_amount];
  for (int k = turnover_time + 1; k < MAX_OFFSET_ALLOWED_MINUTES; k++) {
    int new_start_time = k;
    new_arrival_times[0] = new_start_time;

    for (int i = 1; i < new_station_amount; ++i) {
      // Calculate time taken to reach the current segment
      double time_taken = new_line[i - 1];

      new_arrival_times[i] = new_arrival_times[i - 1] + time_taken;
    }

    for (int i = 0; i < new_station_amount; ++i) {
      int new_arrival_time = new_arrival_times[i];

      for (int j = 0; j < new_station_amount; ++j) {
        if (new_rail[i].station_number == original_rail[j].station_number &&
            (new_arrival_time > original_arrival_times[j] &&
             new_arrival_time < original_arrival_times[j] + turnover_time)) {
          return k;
        }
      }
    }
  }

  printf("No crossing lane within max offset\n");
  return 0;
}
