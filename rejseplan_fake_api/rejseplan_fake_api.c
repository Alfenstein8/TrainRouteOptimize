#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **api_get_route(char *origin, char *destination, int *length) {
  int size = 10;
  int max_name_length = 50;
  char **route = (char **)malloc(size * sizeof(char *));
  for (int i = 0; i < size; i++) {
    route[i] = (char *)malloc(max_name_length * sizeof(char));
  }
  strcpy(route[0], "Koebenhavn H");
  strcpy(route[1], "Odense");
  strcpy(route[2], "Fredericia");
  strcpy(route[3], "Vejle");
  strcpy(route[4], "Horsens");
  strcpy(route[5], "Skanderborg");
  strcpy(route[6], "Aarhus H");
  strcpy(route[7], "Randers");
  strcpy(route[8], "Hobro");
  strcpy(route[9], "Aalborg");
  *length = size;
  return route;
}

int get_od_time() {
  return 40;
}
