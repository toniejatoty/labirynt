#ifndef _PATHFINDER_H_
#define _PATHFINDER_H_
int *way(char * input, int l, int c);
char **load(char **maze,char * input,int*T);
char **whereP(char ** maze, int l , int c, char * input, int *T);
#endif
