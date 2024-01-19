#ifndef RAILS
#define RAILS
typedef struct {
  int length, top_speed, station_number;
} Rail;
int load_rails(const char* file_path, char** station_names,
                 int station_amount, Rail *rails);
#endif
