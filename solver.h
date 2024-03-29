#ifndef _SORVER_H_
#define _SOLVER_H_
#include <stdio.h>
#include "structure.h"
char **whereP(char ** maze, int l, int c, char * input, int *T);
char wasvisited(structure start, structure position, structure special);
void make(structure start, char ** maze, char * input, int *T, int from, structure position, structure finish, structure special);
structure way(char * input, int l, int c);

#endif
