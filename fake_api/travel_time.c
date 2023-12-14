#include <stdio.h>

// Average speed of different transportation options.
#define AVG_SPD_CAR 60      // km/h
#define AVG_SPD_TRAIN 40    // km/h
#define AVG_SPD_BIKE 15     // km/h

typedef struct{
    int flight_time_min;
    int airport_prep_time_min;          
    double ground_distance_origin;           // Distance from origin to first airport in km
    double ground_distance_destination;      // Distance from second airport to destination in km
    double time_of_day;                      // 00:00-24:00 format 
    enum transport_modes {car, train, bike} transport_modes;
} SimFile;

/*enum transport_modes {car, train, bike}; */

double get_total_air_time(SimFile *sim_data);
double calculate_ground_time(SimFile *sim_data, double distance);
double traffic(int time_of_day);
void test_print(double total_air_time);

int main(void){
    
    SimFile sim_data = {
    .flight_time_min = 70,
    .airport_prep_time_min = 60,
    .ground_distance_origin = 40,      // km
    .ground_distance_destination = 40, // km
    .time_of_day = 9,
    .transport_modes = car
    };
    /* Calculate total air travel time */
    double total_travel_time = get_total_air_time(&sim_data);
    test_print(total_travel_time);

    return 0;
}

/* Functions that takes loaded/provided simdata and calculates total travel time*/
double get_total_air_time(SimFile *sim_data){
    double total_travel_time = 0, ground_travel_time_origin = 0, ground_travel_time_destination = 0;

    /* calculates time from origin to first airport */
    ground_travel_time_origin = calculate_ground_time(sim_data, sim_data->ground_distance_origin);   
    
    /* Add flight time and airport prep time to total travel time */
    total_travel_time += sim_data->flight_time_min;
    total_travel_time += sim_data->airport_prep_time_min;

    /* Update time of day for when going to second destination */
    sim_data->time_of_day = total_travel_time + (ground_travel_time_origin / 60); // Convert travel time to hours 
    
    /* calculates time from second airport to destinatin */
    ground_travel_time_destination = calculate_ground_time(sim_data, sim_data->ground_distance_destination); 
    
    /* Sum of both travels */
    total_travel_time += ground_travel_time_origin + ground_travel_time_destination;  

    /* Test print*/
    printf("travel time to 1st airport: %.2lf mins\n", ground_travel_time_origin);
    printf("total travel to 2nd airport: %.2lf mins\n", ground_travel_time_destination);

    return total_travel_time;
    /* for(int i = 0; i < connections; i++){}  ----- idea*/
}

/* Function to calculate time for a single travel segment */
double calculate_ground_time(SimFile *sim_data, double distance_segment){

double speed = 0, ground_travel_time = 0;

/* Test to see if enum is working correctly */
printf("%d\n", sim_data->transport_modes);

/*Estimate the speed of the transport based on transport mode and levels of traffic */
switch(sim_data->transport_modes){
    case car: speed = AVG_SPD_CAR / traffic(sim_data->time_of_day); break;
    case train: speed = AVG_SPD_TRAIN;  break;
    case bike: speed = AVG_SPD_BIKE;    break;
    }
    // Calculates ground travel for this segment
    ground_travel_time = (distance_segment / speed) * 60;      // convert to min
    
    return ground_travel_time;
}

/* Function to adjust speed of transport mode based on traffic conditions */
double traffic(int time_of_day){
    if(time_of_day > 7 && time_of_day <= 9){
        return 1.3;
    } else if(time_of_day > 15 && time_of_day <= 17){
        return 1.3;
    }
    return 1.1; 
}

void test_print(double total_travel_time){
    printf("total travel time: %.2lf mins\n", total_travel_time);
}
