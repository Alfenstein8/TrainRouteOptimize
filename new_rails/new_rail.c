#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../rails/rails.h"

Rail *make_new_rails(Rail *rails, int *new_route, int new_route_size){

Rail *new_rails = (Rail *)malloc(sizeof(Rail) * (new_route_size));

/* Sorts the new route array one segment at a time */
for(int i = 0; i < new_route_size - 1; i++){
    new_rails[i].length = 0;        // km
    double weighted_speed = 0;      // km/h ??
    /* Runs through each rail segment, compacting the lengths 
     * from different segments into new combined lengths */
    for(int j = new_route[i]; j < new_route[i + 1]; j++){
        new_rails[i].length += rails[j].length;             
        weighted_speed += rails[j].top_speed * rails[j].length;
        }
    /* Calculates the average top for this segment using weighted arithmetic */
    new_rails[i].top_speed = weighted_speed / new_rails[i].length;
    new_rails[i].station_number = new_route[i];
    }
    return new_rails;
}