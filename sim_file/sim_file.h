#ifndef sim_file
#define sim_file
typedef struct {
  int x, y;
} pos;

typedef struct {
  pos origin, destination;
  pos start_airport, end_airport;
  int flight_time_min, airport_prep_time_min;
  int station_removal_percentage;
  int depart_offset;
  int turnover_time;
  double acceleration;
  int hst_speed;
} SimFile;
#endif
