#ifndef SIM_FILE
#define SIM_FILE
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

#endif
