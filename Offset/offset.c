   #include <stdio.h>
   #include <stdlib.h>
   #include "../rails/rails.h"

   #define MAX_OFFSET_ALLOWED_MINUTES 60 

 int calculate_departure_offset(double new_line[], double icl_line[], int HST_station_amount, int ICL_station_amount,int turnover_time) {
    double HST_arrival_times[HST_station_amount]; 
      for (int k = 1; k < MAX_OFFSET_ALLOWED_MINUTES; k++){
         int HST_start_time = k;
         HST_arrival_times[0] = HST_start_time; 
     

      for (int i = 1; i  <HST_station_amount ; ++i) {

        // Calculate time taken to reach the current segment

        double time_taken = new_line[i-1];

         HST_arrival_times[i] = HST_arrival_times[i - 1] + time_taken; 
    }

         double ICL_arrival_times[ICL_station_amount];  // the defined route will always have 9 stops in our example
          int ICL_start_time = 0;
         ICL_arrival_times[0] = ICL_start_time;

         for (int i = 1; i < HST_station_amount; ++i) {
         double time_taken = icl_line[i-1];

            ICL_arrival_times[i] = ICL_arrival_times[i - 1] + time_taken;
   }
     for (int i = 1; i < HST_station_amount; ++i) {
        int HST_arrival_time = HST_arrival_times[i];

        for (int j = 1; j < ICL_station_amount; ++j) {
            if (HST_arrival_time >= ICL_arrival_times[j] || HST_arrival_time <= ICL_arrival_times[j]+turnover_time ) {
                return i;
            }
        }
    }
   }
     // Calculate the index where arrival times match
    int index = calculate_departure_offset(new_line[], icl_line[], Hst_num_of_stop, ist_num_of_stop, turnover_time);

    if (index != -1) {
        printf("Matching segment index: %d\n", index);
    } else {
        printf("No matching segment found.\n");
    }

 }