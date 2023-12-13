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
  fscanf(fp, "Origin: %49[^\n]\n", sim_file->origin);
  fscanf(fp, "Destination: %49[^\n]\n", sim_file->destination);
  fscanf(fp, "Start Airport: %49[^\n]\n", sim_file->start_airport);
  fscanf(fp, "End Airport: %49[^\n]\n", sim_file->end_airport);
  fscanf(fp, "Flight Time In Minutes: %d [^\n]\n", &sim_file->flight_time_min);
  fscanf(fp, "Airport Preperaton Time: %d [^\n]\n", &sim_file->airport_prep_time_min);
  fscanf(fp, "Station Preperation Time: %d [^\n]\n", &sim_file->station_prep_time_min);
  fscanf(fp, "Station Percent: %d [^\n]\n", &sim_file->station_removal_percentage);
  fscanf(fp, "Station Turnover Time: %d [^\n]\n", &sim_file->turnover_time);
  fscanf(fp, "High-Speed-Train (HST) Top Speed: %d [^\n]\n", &sim_file->hst_top_speed_kmt);
  fscanf(fp, "High-Speed-Train (HST) Acceleration: %d [^\n]\n", &sim_file->acceleration);
  fclose(fp);
  return 0;
}
