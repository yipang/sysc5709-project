CC=gcc
CFLAGS=-Wall
DIR =-I ./include

OBJ = main.o matrix_builder.o get_max.o get_align.o check_input.o

#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME
bin_folder := $(shell mkdir -p bin)
build_folder := $(shell mkdir -p build)

#TARGET TO COMPILE ALL THE TESTS TOGETHER
main.o: ./src/main.c ./include/matrix_builder.h 
	$(CC) -g -c $(CFLAGS) $(DIR) ./src/main.c -o ./build/main.o

matrix_builder.o: ./src/matrix_builder.c
	$(CC) -g -c $(CFLAGS) $(DIR) ./src/matrix_builder.c -o ./build/matrix_builder.o

get_max.o: ./src/get_max.c 
	$(CC) -g -c $(CFLAGS) $(DIR) ./src/get_max.c -o ./build/get_max.o

get_align.o: ./src/get_align.c
	$(CC) -g -c $(CFLAGS) $(DIR) ./src/get_align.c -o ./build/get_align.o

check_input.o: ./src/check_input.c 
	$(CC) -g -c $(CFLAGS) $(DIR) ./src/check_input.c -o ./build/check_input.o

unit_testing.o: test/src/unit_testing.c
	$(CC) -g -c $(CFLAGS) $(DIR) ./test/src/unit_testing.c -o ./build/unit_testing.o

tests: unit_testing.o get_align.o  get_max.o matrix_builder.o check_input.o
	$(CC) -g -o ./bin/tests ./build/unit_testing.o ./build/get_align.o  ./build/get_max.o ./build/matrix_builder.o ./build/check_input.o
		 
#TARGET TO COMPILE ONLY PROJECT
project: $(OBJ)
	$(CC) -g -o ./bin/project ./build/main.o ./build/matrix_builder.o ./build/get_max.o ./build/get_align.o ./build/check_input.o
	
#TARGET TO COMPILE EVERYTHING (PROJECT + TESTS TOGETHER)
all: project tests

#CLEAN COMMANDS
clean: 
	rm -f bin/* build/*