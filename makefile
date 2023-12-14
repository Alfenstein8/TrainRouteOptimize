test_files := $(wildcard test/*.c)
basefiles := $(wildcard *.c)
files := $(basefiles) rails/rails.c remove_stations/remove_stations.c air_travel_time/air_travel_time.c tools/tools.c userfile/fileput.c calc_all_interaction_levels/calc_interaction.c
train_optimize: $(files) 
	gcc $(files)
tests: $(files) $(test_files)
	gcc $(filter-out main.c ,$(files)) $(test_files) -o runtests
