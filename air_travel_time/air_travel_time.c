#include <stdio.h>
#include "air_travel_time.h"

int main(void){

/* Test data
SimFile test = {
    .flight_time_min = 70,
    .airport_prep_time_min = 60,
};
int travel_time_origin_destination = 40;

// Call function to get total air travel time
int total_travel_time_air = GetTotalAirTravelTime(test, travel_time_origin_destination);
printf("Test: %d\n", total_travel_time_air);


return 0;

} */
// Function to get the total air travel time
}
int get_total_air_travel_time(sim_file sim_data, int travel_time_origin_destination){ 

// Calculates the
int air_route_travel_time;

air_route_travel_time += sim_data.flight_time_min;
air_route_travel_time += sim_data.airport_prep_time_min;
air_route_travel_time += travel_time_origin_destination;

return air_route_travel_time;
}
