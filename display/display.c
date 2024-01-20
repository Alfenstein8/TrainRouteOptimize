#include <stdio.h>

int total_time(double *line, int size);

void print_travel_times(const char *simfile_name, int new_line_time, int original_line_time,
                        int plane_travel_time_min, int offset_time_min) {
  printf("-------------------\n");
  printf("Simulation file: %s\n", simfile_name);

  printf("High-Speed Train Travel Time: %d hour(s) and %d minutes\n", new_line_time / 60,
         new_line_time % 60);
  printf("City Train Total Travel Time: %d hour(s) and %d minutes\n", original_line_time / 60,
         original_line_time % 60);
  printf("Plane Travel Time:            %d hour(s) and %d minutes\n", plane_travel_time_min / 60,
         plane_travel_time_min % 60);
  printf("Offset Time:                  %d hour(s) and %d minutes\n", offset_time_min / 60,
         offset_time_min % 60);
}

int total_time(double *line, int size) {
  int total_traveltime = 0;
  for (int i = 0; i < size; ++i) {
    total_traveltime += line[i];
  }
  return total_traveltime;
}
