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
        // for(int i=0; i<100; i++)
        // for(int j=0; j<22; j++)
        //{
        // printf("%c",maze[i][j]);
        // }
        // printf("\n\n\n");
        // printf("\n\n-->%c<--",maze[4][0]);
        // printf("\n\n-->%c<--",maze[4][1]);
        // printf("Drugi i 3 wiersz wygladaja nastepujaco:");
        // for(int j=0; j<100; j++)
        // printf("%c", maze[1][j]);
        // printf("\n\n\n");
        // for(int j=0; j<100; j++)
        // printf("%c", maze[2][j]);
        return maze;
}

