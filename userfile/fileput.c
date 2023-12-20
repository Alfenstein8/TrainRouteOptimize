#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../sim_file/sim_file.h"
#include "fileput.h"

int load_local_file(SimFile *sim_file, const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Failed to open file");
    return 1;
  }
  if (!fscanf(fp, "Origin: %49[^\n]\n", sim_file->origin))
    return 1;
  if (!fscanf(fp, "Destination: %49[^\n]\n", sim_file->destination))
    return 1;
  if (!fscanf(fp, "Start Airport: %49[^\n]\n", sim_file->start_airport))
    return 1;
  if (!fscanf(fp, "End Airport: %49[^\n]\n", sim_file->end_airport))
    return 1;
  if (!fscanf(fp, "Flight Time In Minutes: %d [^\n]\n", &sim_file->flight_time_min))
    return 1;
  if (!fscanf(fp, "Airport Preperation Time: %d [^\n]\n", &sim_file->airport_prep_time_min))
    return 1;
  if (!fscanf(fp, "Station Preperation Time: %d [^\n]\n", &sim_file->station_prep_time_min))
    return 1;
  if (!fscanf(fp, "Station Percent: %d [^\n]\n", &sim_file->station_removal_percentage))
    return 1;
  if (!fscanf(fp, "Station Turnover Time: %d [^\n]\n", &sim_file->turnover_time))
    return 1;
  if (!fscanf(fp, "High-Speed-Train (HST) Top Speed: %d [^\n]\n", &sim_file->hst_top_speed_kmt))
    return 1;
  if (!fscanf(fp, "High-Speed-Train (HST) Acceleration: %lf [^\n]\n", &sim_file->acceleration))
    return 1;
  if (!fscanf(fp, "ICL top speed: %d [^\n]\n", &sim_file->icl_top_speed))
    return 1;
  fclose(fp);
  return 0;
}
