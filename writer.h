#ifndef WRITER_H
#define WRITER_H
#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
void save(FILE *out, char *in , int*T, structure start, char ** maze);
void changedirector(int from, int fromorg, FILE * out,int *T);
void gofromvertextovertex(char **maze, FILE *out, char *in, int *T, int fromorg, structure start);
int wheretogo(structure start, int fromorg, FILE *out, int *T);

#endif
