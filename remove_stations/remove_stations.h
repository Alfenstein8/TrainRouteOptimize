
struct TrainRoute {
    char station_name[50];
    int interaction_level;
};

void remove_low_interaction_stations(struct TrainRoute *route, int num_stations, int removal_percentage);