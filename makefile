test_files := $(wildcard test/*.c)
generator_files := $(wildcard userfile_generator/*.c)
basefiles := $(wildcard *.c)
files := $(basefiles) $(generator_files) new_rails/new_rail.c rejseplan_fake_api/rejseplan_fake_api.c rails/rails.c remove_stations/remove_stations.c air_travel_time/air_travel_time.c tools/tools.c userfile/fileput.c calc_all_interaction_levels/calc_interaction.c
train_optimize: $(files) 
	gcc $(files)
tests: $(files) $(test_files)
	gcc $(filter-out main.c ,$(files)) $(test_files) -o runtests
