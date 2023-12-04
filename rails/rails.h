typedef struct {
  int length, top_speed;
} Rail;
Rail* load_rails(const char* file_path, char** station_names,
                 int station_amount);
