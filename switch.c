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
char **load(char **maze ,char * input, int *T)
{
        int cc=0, ll=0;
        char a;
        FILE * in = fopen(input, "r");
        int i=0;
        if(T[2]!=T[3]){
        int opposide=100*T[6]*(T[2]+1)+(100*(T[2]+1));
        int from=100*T[6]*T[2]+(100*T[2]);
        while(i<=opposide-1)
        {
                a=fgetc(in);
                if(a==EOF)return maze;
if(i>=from)
{
maze[ll%100][cc]=a;
}
                if(a=='\n')
{
cc=0; ll++;
}
else cc++;
                i++;
        }
}
else
{
        int opposide=(100*(T[2])+T[4])*T[6]+(100*(T[2])+T[4]);
        int from=100*T[6]*T[2]+(100*T[2]);
        while(i<=opposide-1)
        {
                a=fgetc(in);
                if(a==EOF)return maze;
if(i>=from)
{
maze[ll%100][cc]=a;
}
                if(a=='\n')
{
cc=0; ll++;
}
else cc++;
                i++;
        }


}
fclose(in);
return maze;
}

