#ifndef RAILS
#define RAILS
typedef struct {
  int length, top_speed, station_number;
} Rail;
Rail* load_rails(const char* file_path, char** station_names,
                 int station_amount);
#endif
