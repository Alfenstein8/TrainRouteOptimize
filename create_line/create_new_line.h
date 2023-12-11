struct Linesegment {
    double speed; // Speed in km/min
    int total_time;  //min
};
typedef struct Linesegment Linesegment;

struct Rail {
    int length;     // km
    int top_speed; // km/min???
};
typedef struct Rail Rail;

Linesegment create_line_segment(int top_speed, double acceleration, double distance, int turnover_time);
Linesegment* create_new_line(double HST_acceleration, Rail new_rails[], int num_stations,int turnover_time);