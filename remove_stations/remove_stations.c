#include <stdio.h>
#include <stdlib.h>
#include "remove_stations.h"


 //sammenlignignsfunktion der bruger qsort til at sortere stationerne alt efter deres interaktionsniveauer
int compare_stations(const void *a, const void *b) {
    return ((struct TrainRoute *)a)->interaction_level - ((struct TrainRoute *)b)->interaction_level;
}

void remove_low_interaction_stations(struct TrainRoute *route, int num_stations, int removal_percentage) {
    // Undgå at fjerne første og sidste station
    if (num_stations <= 2) {
        printf("Not enough stations to remove.\n");
        return;
    }


    // Sorter stationerne undtagen første og sidste station?? ikke helt sikker her:P
    qsort(route + 1, num_stations - 2, sizeof(struct TrainRoute), compare_stations);


    // Beregn det ønskede antal stationer, der skal fjernes baseret på fjernelsesprocenten
    int num_to_remove = (removal_percentage * (num_stations - 2)) / 100;
    // Undgå at fjerne flere stationer end der er til rådighed (undtagen den første og den sidste)
    num_to_remove = (num_to_remove >= num_stations - 2) ? num_stations - 2 : num_to_remove;

    printf("Removing %d stations with the lowest interaction levels:\n", num_to_remove);
    for (int i = 1; i <= num_to_remove; i++) {
        printf("%s - Interaction Level: %d\n", route[i].station_name, route[i].interaction_level);
    }

    // Fjerner de laveste interaktionsstationer 
    for (int i = 1; i <= num_to_remove; i++) {
        route[i] = route[i + num_to_remove];
    }

    printf("\nUpdated Train Route after removal:\n");
    for (int i = 0; i < num_stations - num_to_remove; i++) {
        printf("%s - Interaction Level: %d\n", route[i].station_name, route[i].interaction_level);
    }
}



