#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

typedef struct {
  char origin[MAX_INPUT_LENGTH];
  char destination[MAX_INPUT_LENGTH];
  char start_airport[MAX_INPUT_LENGTH];
  char end_airport[MAX_INPUT_LENGTH];
  int flight_time_min;
  int airport_prep_time_min;
  int station_prep_time_min;
  int station_removal_percentage;
  int turnover_time;
  int hst_top_speed_kmt;
  int acceleration;
} SimFile;

// function to load file
int load_local_file(SimFile *sim_file, const char *filename);

int main(void) {
char filename[100];

printf("Enter filename: ");
fgets(filename, sizeof(filename), stdin);
filename[strcspn(filename, "\n")] = 0;

  SimFile sim_file;

  if (load_local_file(&sim_file, filename) != 0){
    return 1;
  }

  //load_local_file(&sim_file, filename);
  printf("%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", sim_file.origin, sim_file.destination, 
  sim_file.start_airport, sim_file.end_airport, sim_file.flight_time_min, sim_file.airport_prep_time_min, 
  sim_file.station_prep_time_min, sim_file.station_removal_percentage, sim_file.turnover_time, 
  sim_file.hst_top_speed_kmt, sim_file.acceleration);
  return 0;
}

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
  fscanf(fp, "Flight Time In Minuets: %d [^\n]\n", &sim_file->flight_time_min);
  fscanf(fp, "Airport Preperaton Time: %d [^\n]\n", &sim_file->airport_prep_time_min);
  fscanf(fp, "Station Preperation Time: %d [^\n]\n", &sim_file->station_prep_time_min);
  fscanf(fp, "Station Percent: %d [^\n]\n", &sim_file->station_removal_percentage);
  fscanf(fp, "Station Turnover Time: %d [^\n]\n", &sim_file->turnover_time);
  fscanf(fp, "High-Speed-Train (HST) Top Speed: %d [^\n]\n", &sim_file->hst_top_speed_kmt);
  fscanf(fp, "High-Speed-Train (HST) Acceleration: %d [^\n]\n", &sim_file->acceleration);
  fclose(fp);
  return 0;
}