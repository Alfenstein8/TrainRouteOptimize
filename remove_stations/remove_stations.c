#include "remove_stations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sort_item {
  int station_nr;
  int interaction_level;
};

/*Sort based on interaction levels*/
int compare_interaction_levels(const void *a, const void *b) {
  struct sort_item *sa = (struct sort_item *)a;
  struct sort_item *sb = (struct sort_item *)b;
  if (sa->interaction_level < sb->interaction_level) {
    return -1;
  } else if (sa->interaction_level > sb->interaction_level) {
    return 1;
  }
  return 0;
}

/*Sort based on station number*/
int compare_station_numbers(const void *a, const void *b) {
  struct sort_item *sa = (struct sort_item *)a;
  struct sort_item *sb = (struct sort_item *)b;
  if (sa->station_nr < sb->station_nr) {
    return -1;
  } else if (sa->station_nr > sb->station_nr) {
    return 1;
  }
  return 0;
}

int remove_low_interaction_stations(int *route, int num_stations, int removal_percentage,
                                    int *new_route) {
  if (num_stations <= 1) {
    printf("Not enough stations to remove.\n");
    return 0;
  }

  /*Make a temporary array which contains the station numbers, in order to keep track of the order*/
  struct sort_item sort_route[num_stations];
  for (int i = 0; i < num_stations; ++i) {
    sort_route[i].interaction_level = route[i];
    sort_route[i].station_nr = i;
  }

  /*Sort stations except for the first and last station, based on interaction_level*/
  qsort(sort_route + 1, num_stations - 2, sizeof(struct sort_item), compare_interaction_levels);

  /*Caps the removal_percentage at 100%*/
  removal_percentage = removal_percentage > 100 ? 100 : removal_percentage;
  /*Calculate amount of stations to be removed*/
  int num_to_remove = (removal_percentage * (num_stations - 2)) / 100;

  /*Sort back to original station order, based on sort_item station number*/
  qsort(sort_route + 1 + num_to_remove, num_stations - 2 - num_to_remove, sizeof(struct sort_item),
        compare_station_numbers);

  /*Moves all stations except for removed stations to new array*/
  int new_route_size = num_stations - num_to_remove;
  new_route[0] = sort_route[0].station_nr;
  new_route[new_route_size - 1] = sort_route[num_stations - 1].station_nr;
  for (int i = num_to_remove + 1; i < num_stations; i++) {
    new_route[i - num_to_remove] = sort_route[i].station_nr;
  }

  return num_stations - num_to_remove;
}

