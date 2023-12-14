   #include <stdio.h>
   #include <stdlib.h>
   #include "../rails/rails.h"


struct Line {
    int num_segments;
    struct Rail segments[9]; // max size will always be 9 in our example route
};

 int calculate_departure_offset(struct Line *ICL_train_line, struct Line *HST_train_line) {
    int ICL_start_time = 0;
    int HST_start_time = 5;
    double HST_arrival_times[9]; 
    double HST_arrival_times[0] = HST_start_time; 

    for (int i = 1; i < HST_train_line->num_segments; ++i) {
        double HST_speed = HST_train_line->segments[i].top_speed;
        int HST_distance = HST_train_line->segments[i].length;

        // Calculate time taken to reach the current segment
        double time_taken = new_line[i-1];

         HST_arrival_times[i] = HST_arrival_times[i - 1] + time_taken; 
    }

         double ICL_arrival_times[9];  // the defined route will always have 9 stops in our example
         ICL_arrival_times[0] = ICL_start_time;
         for (int i = 1; i < ICL_train_line->num_segments; ++j) {
         double time_taken = ICL_line[i-1];

            ICL_arrival_times[i] = ICL_arrival_times[i - 1] + time_taken;
   }
     for (int i = 1; i < HST_train_line->num_segments; ++i) {
        int HST_arrival_time = HST_arrival_times[i];

        for (int j = 1; j < ICL_train_line->num_segments; ++j) {
            if (ICL_arrival_times[j] == HST_arrival_time) {
                return i;
            }
        }
    }
   }
     // Calculate the index where arrival times match
    int index = calculate_departure_offset(&ICL_train_line, &HST_train_line);

    if (index != -1) {
        printf("Matching segment index: %d\n", index);
    } else {
        printf("No matching segment found.\n");
    }

