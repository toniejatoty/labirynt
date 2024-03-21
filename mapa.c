#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
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

char **whereP(char ** maze, int l , int c, char * input, int *T)
{
        maze = load(maze, input, T);
        char a='K';
        while(a!='P')
	{if(T[2]==0&&T[3]==0)
{
                        for(int i=0; i<T[6]; i++)
                        {
                        if(maze[0][i]=='P'){a='P';T[7]=0; T[8]=i; }
                        }
                for(int j=0; j<T[4]; j++)
                {
        if(maze[j][0]=='P') // TU MOZE BYC BLAD bo nie koniecznie jest to spojne
        {
        a='P';
        T[7]=j;
        T[8]=0;
        }
        if(maze[j][T[6]]=='P')
        {
        a='P';
        T[7]=j;
        T[8]=T[6];
        }

                }for(int i=0; i<T[6]; i++)
                        {
                        if(maze[T[4]][i]=='P'){a='P';T[7]=T[4]; T[8]=i;}
                        }
}

        else if(T[2]==0){
                        for(int i=0; i<T[6]; i++)
                        {
                        if(maze[0][i]=='P'){a='P';T[7]=0; T[8]=i; }
                        }
                for(int j=0; j<100; j++)
                {
        if(maze[j][0]=='P')
        {
        a='P';
        T[7]=j;
        T[8]=0;
        }
        if(maze[j][T[6]]=='P')
        {
        a='P';
        T[7]=j;
        T[8]=T[6];
        }

                }
                }
                else if(T[2]==T[3]){
                        for(int i=0; i<T[6]; i++)
                        {
                        if(maze[T[4]][i]=='P'){a='P';T[7]=T[4]; T[8]=i;}
                        }
        for(int j=0; j<T[4]; j++)
                {
        if(maze[j][0]=='P')
        {
        a='P';
        T[7]=j;
        T[8]=0;
        }
        if(maze[j][T[6]]=='P')
        {
        a='P';
        T[7]=j;
        T[8]=T[6];
        }


                }}
        else if(T[2]!=T[3])
        {
        for(int j=0; j<100; j++)
        {
        if(maze[j][0]=='P')
        {
        a='P';
        T[7]=j+100*T[2];
        T[8]=0;
        }
        if(maze[j][T[6]]=='P')
        {
        a='P';
        T[7]=j+100*T[2];
        T[8]=T[6];
        }
        }


        }
        if(a!='P')
        {
                if(T[2]==T[3])T[2]=0;
                else T[2]++;
		maze=load(maze , input,T);

        }
}
T[9]=T[2];
        return maze;
}

