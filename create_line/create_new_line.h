#include "../rails/rails.h"

struct Linesegment {
    double speed; // Speed in km/min
    int total_time;  //min
};
typedef struct Linesegment Linesegment;


Linesegment create_line_segment(int top_speed, double acceleration, double distance, int turnover_time);
Linesegment* create_new_line(double HST_acceleration, Rail new_rails[], int num_stations,int turnover_time);