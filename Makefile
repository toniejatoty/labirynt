
all:
	gcc -ggdb -pedantic -Wall help.h reader.h solver.h zwalnianie.h structure.h switch.h switch.c reader.c solver.c zwalnianie.c main.c -o results
