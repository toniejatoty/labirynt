#ifndef _SORVER_H_
#define _SOLVER_H_
#include <stdio.h>

char **whereP(cahr ** maze, int l, int c, char * input, int *T);
char wasvisited(structure start, structure position, structure special);
void make(structure start, char ** maze, char * input, int *T, int from, structure position, structure finish, structure special);
int * way(char * input, int l, int c);

#endif
