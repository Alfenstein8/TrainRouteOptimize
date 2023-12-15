#include "load_od_table.h"
#include "../tools/tools.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **load_od_table(char **route, int route_length, char filename[]){
    int **loaded_od_table;
    loaded_od_table = (int **)malloc(route_length * sizeof(int *));
    int i;
    for (i = 0; i < route_length; i++) {
        loaded_od_table[i] = (int *)malloc(route_length * sizeof(int));
    }
    
    char read_line[2850];
    int station_col_index[290];
    int row_index = 0;
    int j = 0;
    int e = 0;

    FILE *f = fopen(filename, "r");
    if (f == NULL){
        printf("Error in opening of file \n");
        exit(EXIT_FAILURE);
    }

    while (fgets(read_line, sizeof(read_line), f)){
        char *station;
        char *line = strdup(read_line);
        int col_index = 0;
        int n = 0;
        int m = 0;
        int station_int;
        int l = 0;
        while ((station = strsep(&line, ";"))){
            int index = strcspn(station, "\n");
            station[index] = '\0';
            if((strcmp(station, route[n]) == 0)){
                if(row_index == 0){
                    station_col_index[n] = col_index;
                }
                n++;
                }
                if(strcmp(station, route[j]) == 0 && row_index != 0
                && col_index == 0){
                    l = 1;
                    j++;

                    if(row_index != 1){
                        e++;
                    }
                }

                if(col_index == station_col_index[m] &&
                row_index != 0 && l == 1){
                    station_int = atoi(station);
                    loaded_od_table[e][m] = station_int;
                    m++;  
                }
            col_index++;
            }
    row_index++;
    }
    fclose(f);
    return loaded_od_table;
}
