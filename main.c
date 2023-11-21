#include <stdio.h>

typedef struct {
  int x, y;
} pos;

typedef struct {
  pos origin, destination;
  pos first_airport, last_airport;
  int flight_time, airport_prep_time;

  int train_cap, train_travel_time;

  char** stations;
  int station_amount;

  int ori_to_train, train_to_desti;
  int ori_to_airport, airport_to_desti;

  int train_convert, station_rm;

  int depart_offset;
} SimData;

typedef struct {
  int number, passengers;
} Station;

typedef struct {
  int train, time;
  Station station;
} Event;

typedef struct {
  int train_nr, passengers, capacity;
  Station* Line;
} Train;

/*Functions*/
void loadSimData(char* file_path, SimData*);
int** create_table(SimData*);
void fill_leaving_pros(int** table, int amount);
void create_lines(Station* slow_line, Station* fast_line, int station_amount);
Event* create_event_timetable(SimData,Station* slow_line, Station* fast_line);

int main(void) {
  SimData data;
  char* file_path; /*The file path that the user provides*/

  loadSimData(file_path, &data);

  int** leaving_pros_table = create_table(&data);
  fill_leaving_pros(leaving_pros_table, data.station_amount);

  Station slow_line[data.station_amount], fast_line[data.station_amount];
  create_lines(slow_line, fast_line, data.station_amount);

  Event* event_timetable = create_event_timetable(data,slow_line,fast_line);

  return 0;
}
