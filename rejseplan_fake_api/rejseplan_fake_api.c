#include <stdio.h>
#include <stdlib.h>

int api_get_route(char *origin, char *destination, char *route[]) {
  route[0] = "Koebenhavn";
  route[1] = "Odense St.";
  route[2] = "Fredericia St.";
  route[3] = "Vejle St.";
  route[4] = "Horsens St.";
  route[5] = "Skanderborg St.";
  route[6] = "Aarhus St.";
  route[7] = "Randers St.";
  route[8] = "Hobro St.";
  route[9] = "Aalborg St.";
  return 10;
}
