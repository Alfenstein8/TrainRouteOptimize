   #include <stdio.h>
   #include <stdlib.h>
   #include "../rails/rails.h"


 int calculate_departure_offset(double new_line[], double icl_line[]) {
    double HST_arrival_times[9]; 
      for (int k = 1; k < 60; k++){
         int HST_start_time = k;
         HST_arrival_times[0] = HST_start_time; 
     

      for (int i = 1; i  <9 ; ++i) {

        // Calculate time taken to reach the current segment

        double time_taken = new_line[i-1];

         HST_arrival_times[i] = HST_arrival_times[i - 1] + time_taken; 
    }

         double ICL_arrival_times[9];  // the defined route will always have 9 stops in our example
          int ICL_start_time = 0;
         ICL_arrival_times[0] = ICL_start_time;

         for (int i = 1; i < 9; ++i) {
         double time_taken = ICL_line[i-1];

            ICL_arrival_times[i] = ICL_arrival_times[i - 1] + time_taken;
   }
     for (int i = 1; i < 9; ++i) {
        int HST_arrival_time = HST_arrival_times[i];

        for (int j = 1; j < 9; ++j) {
            if (ICL_arrival_times[j] == HST_arrival_time) {
                return i;
            }
        }
    }
   }
     // Calculate the index where arrival times match
    int index = calculate_departure_offset(new_line[], icl_line[]);

    if (index != -1) {
        printf("Matching segment index: %d\n", index);
    } else {
        printf("No matching segment found.\n");
    }

 }