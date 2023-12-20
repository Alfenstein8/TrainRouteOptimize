#include <stdio.h>
#include <stdlib.h>

int api_get_route(char *origin, char *destination, char *route[]) {
  route[0] = "Koebenhavn H";
  route[1] = "Odense";
  route[2] = "Fredericia";
  route[3] = "Vejle";
  route[4] = "Horsens";
  route[5] = "Skanderborg";
  route[6] = "Aarhus H";
  route[7] = "Randers";
  route[8] = "Hobro";
  route[9] = "Aalborg";
  return 10;
}
