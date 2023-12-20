#include "create_new_line.h"
#include "../rails/rails.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double create_line_segment(int top_speed, double acceleration, double distance);

double *create_new_line(double HST_acceleration, Rail *new_rails, int num_stations) {

  double *new_line = (double *)malloc(num_stations * sizeof(double));

  HST_acceleration *= 3.6; // convert from meter per second squared to kilometers per minute squated

  for (int i = 0; i < num_stations - 1; ++i) {
    int top_speed = (new_rails[i].top_speed) / 60; // convert from km/t to km/m
    int length = new_rails[i].length;

    new_line[i] = create_line_segment(top_speed, HST_acceleration, length);
  }

  return new_line;
}

double create_line_segment(int top_speed, double acceleration, double distance) {
  double segment;

  double time_not_at_top_speed = top_speed / acceleration;
  double distance_not_at_top_speed = 0.5 * acceleration * pow(time_not_at_top_speed, 2);
  double distance_at_top_speed = distance - 2 * distance_not_at_top_speed;
  double time_at_top_speed = distance_at_top_speed / top_speed;

  segment = 2 * time_not_at_top_speed + time_at_top_speed;

  return segment;
}
