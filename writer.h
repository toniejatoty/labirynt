#ifndef WRITER_H
#define WRITER_H
#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
void save(FILE *out, char *in , int*T, structure start, char ** maze, int count);
void changedirector(int from, int fromorg, FILE * out,int *T);
void gofromvertextovertex(char **maze, FILE *out, char *in, int *T, int fromorg, structure start, int count);
int wheretogo(structure start, int fromorg, FILE *out, int *T);
void go_start_first_vertex(FILE *out, char * in, int *T, structure start, char **maze);
#endif
