#include "create_new_line.h"
#include "../rails/rails.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define M_TO_M_SQRT 3.6

double create_line_segment(double top_speed, double acceleration, double distance);

double *create_new_line(double acceleration, Rail *rails, int num_stations, int train_top_speed) {

  double *new_line = (double *)malloc(num_stations * sizeof(double));

  acceleration *= M_TO_M_SQRT; // convert from meter per second squared to kilometers per minute squated

  for (int i = 0; i < num_stations - 1; ++i) {
    int speed = train_top_speed > rails[i].top_speed ? rails[i].top_speed : train_top_speed; 
    double top_speed = speed / 60.0; // convert from km/t to km/m
    int length = rails[i].length;

    new_line[i] = create_line_segment(top_speed, acceleration, length);
  }

  return new_line;
}

double create_line_segment(double top_speed, double acceleration, double distance) {
  double segment;

  double time_not_at_top_speed = top_speed / acceleration;
  double distance_not_at_top_speed = 0.5 * acceleration * pow(time_not_at_top_speed, 2);
  double distance_at_top_speed = distance - 2 * distance_not_at_top_speed;
  double time_at_top_speed = distance_at_top_speed / top_speed;

  segment = 2 * time_not_at_top_speed + time_at_top_speed;

  return segment;
}
