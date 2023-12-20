#include <stdio.h>
#include <stdlib.h>

int *calculate_all_interaction_levels(int table_size, int **OD_table) {
  /*Allocate memory for the the interaction levels*/
  int *interaction_levels = (int *)calloc(table_size, sizeof(int));

  if (interaction_levels == NULL) {
    printf("Could not allocate memory!");
    exit(EXIT_FAILURE);
  }

  /*Calculate interaction levels*/
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
