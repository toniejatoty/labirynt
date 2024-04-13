#include "switch.h"
#include <stdio.h>
char **load(char **maze, char *input, int *T)
{
        // printf("LOAD JEST WYWOLYWANY");
        int cc = 0, ll = 0;
        char a;
        FILE *in = fopen(input, "r");
        int i = 0;
        if (T[2] != T[3])
        {
                int opposide = T[10] * T[6] * (T[2] + 1) + (T[10] * (T[2] + 1));
                int from = T[10] * T[6] * T[2] + (T[10] * T[2]);
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
                                maze[ll % T[10]][cc] = a;
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
                int opposide = (T[10]* (T[2]) + T[4]) * T[6] + (T[10] * (T[2]) + T[4]);
                int from = T[10] * T[6] * T[2] + (T[10] * T[2]);
                while (i <= opposide - 1)
                {
                        a = fgetc(in);
                        if (a == EOF)
                        {
                                fprintf(stderr, "dasdad");
                                return maze;
                        }
                        if (i >= from)
                        {
                                maze[ll % T[10]][cc] = a;
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
