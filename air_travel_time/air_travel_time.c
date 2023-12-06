#include <stdio.h>

#include "../sim_file/sim_file.h"

/* Function to get the total air travel time */
int get_total_air_travel_time(SimFile sim_data, int travel_time_origin_destination){ 

/* Calculates the total air time taking into account air flight time, air preparation time and..
*  travel time from origin to start airport & end airport to destination 
*/
int air_route_travel_time;

air_route_travel_time += sim_data.flight_time_min;
air_route_travel_time += sim_data.airport_prep_time_min;
air_route_travel_time += travel_time_origin_destination;

return air_route_travel_time;
}
