
all:
	gcc -ggdb -pedantic -Wall help.h reader.h solver.h free_maze.h structure.h switch.h switch.c reader.c solver.c free_maze.c main.c -o results
