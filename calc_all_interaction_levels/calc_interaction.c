#include <stdio.h>
#include <stdlib.h>
/*#include "load_od_table.h"*/

int *calculate_all_interaction_levels(int table_size, int **OD_table);

/*
int main(void){
    char *route[4] = {"Albertslund", "Alleroed", "Avedoere", "Bernstorffsvej"};
    char filename[] = "OD_modified.csv";
    int *interaction_levels_table;
    int route_length = sizeof(route) / sizeof(route[0]);
    int **loaded_od_table = load_od_table(route, filename);
    interaction_levels_table = calculate_all_interaction_levels(route_length, loaded_od_table);

    for(int i = 0; i < route_length; i++){
    printf("%d\n", interaction_levels_table[i]);
    }

    int b;
    for (b = 0; b < 289; b++) {
        free(loaded_od_table[b]);
    }
    free(loaded_od_table);

    free(interaction_levels_table);

  return 0;
}
*/

int *calculate_all_interaction_levels(int table_size, int **OD_table) {
    
  /*Allokerer hukommelse til interationsniveauet*/
  int *interaction_levels = (int *)malloc(table_size * sizeof(int));

  if (interaction_levels == NULL) {
    printf("Could not allocate memory!");
    exit(EXIT_FAILURE);
  }

  /*Initialiserer løkken med nul-værdier for hver station, for reuseability*/
  for (int i = 0; i < table_size; ++i) {
    interaction_levels[i] = 0;
  }

  /*Beregner interaktionsniveauerne*/
  for (int i = 0; i < table_size; ++i) {
    for (int j = 0; j < table_size; ++j) {
      if (i == j) {
        continue;
      }
      interaction_levels[i] += OD_table[i][j];
      interaction_levels[j] += OD_table[i][j];
    }
  }

  return interaction_levels;
}
