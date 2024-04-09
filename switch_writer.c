#include "switch_writer.h"
#include <stdio.h>
char **load2(char **maze, char *input, int *T)
{
        // printf("LOAD JEST WYWOLYWANY");
        int cc = 0, ll = 0;
        char a;
        FILE *in = fopen(input, "r");
        int i = 0;
        if (T[6] != T[9])
        {
                int opposide = T[7] * T[1] * (T[6] + 1) + (T[7] * (T[6] + 1));
                int from = T[7] * T[1] * T[6] + (T[7] * T[6]);
                while (i <= opposide - 1)
                {
                        a = fgetc(in);
                        if (a == EOF)
                        {
                                fprintf(stderr, "WYCHODZE PRZEZ EOF");
                                return maze;
                        }
                        if (i >= from)
                        {
                                maze[ll % T[7]][cc] = a;
                        }
                        if (a == '\n')
                        {
                                cc = 0;
                                ll++;
                        }
                        else
                                cc++;
                        i++;
                }
        }
        else
        {
                int opposide = (T[7] * (T[6]) + T[8]) * T[1] + (T[7] * (T[6]) + T[8]);
                int from = T[7] * T[1] * T[6] + (T[7] * T[6]);
                while (i <= opposide - 1)
                {
                        a = fgetc(in);
                        if (a == EOF)
                        {
                                fprintf(stderr, "Wychodze przeez eof\n");
                                return maze;
                        }
                        if (i >= from)
                        {
                                maze[ll % T[7]][cc] = a;
				 }
                        if (a == '\n')
                        {
                                cc = 0;
                                ll++;
                        }
                        else
                                cc++;
                        i++;
                }
        }
        fclose(in);
        return maze;
}

