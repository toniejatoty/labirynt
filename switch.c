#include "switch.h"
#include <stdio.h>
char ** maze_switch(FILE * in, char ** mazeory, int c, int where)
{
int c2=0;
char a;
while(c2<=c)
{
a=fgetc(in);
mazeory[where][c2]=a;
c2++;}
return mazeory;
}
