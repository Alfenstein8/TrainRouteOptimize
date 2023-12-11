#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "rails.h"

struct LineSegment {
    double speed; //  km/min
    double total_time; // min
};
typedef struct LineSegment LineSegment;

     LineSegment create_line_segment(int top_speed, double acceleration, double distance, int turnover_time) {
     LineSegment segment;

    double time_not_at_top_speed = top_speed / acceleration;
    double distance_not_at_top_speed = 0.5 * acceleration * pow(time_not_at_top_speed, 2);
    double distance_at_top_speed = distance - 2*distance_not_at_top_speed;
    double time_at_top_speed = distance_at_top_speed / top_speed;
    

    segment.speed = top_speed; 
    segment.total_time = 2*time_not_at_top_speed + time_at_top_speed + turnover_time; 

    return segment;
}

 LineSegment* create_new_line(double HST_acceleration, Rail new_rails[], int num_stations,int turnover_time) {

     LineSegment* new_line = (LineSegment *) malloc (num_stations * sizeof(LineSegment));

    for (int i = 0; i < num_stations; ++i) {
        int top_speed = new_rails[i].top_speed;
        int length = new_rails[i].length;

        new_line[i] = create_line_segment(top_speed, HST_acceleration, length, turnover_time);
    }

    return new_line;
}
