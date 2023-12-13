#include <stdio.h>

void print_travel_times(int hst_travel_time_min, int city_train_total_time_min, int plane_travel_time_min, int offset_time_min) {
    printf("High-Speed Train Travel Time: %d hour(s) and %d minutes\n", hst_travel_time_min / 60, hst_travel_time_min % 60);
    printf("City Train Total Travel Time: %d hour(s) and %d minutes\n", city_train_total_time_min / 60, city_train_total_time_min % 60);
    printf("Plane Travel Time:            %d hour(s) and %d minutes\n", plane_travel_time_min / 60, plane_travel_time_min % 60);
    printf("Offset Time:                  %d hour(s) and %d minutes\n", offset_time_min / 60, offset_time_min % 60);
}

int main() {
    // Test
    print_travel_times(127, 98, 60, 30);
    return 0;
}
