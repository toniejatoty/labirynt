#include "solver.h"
#include "switch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pathfinder.h"
char nazwijwierzcholki(char * input, int lmax, int cmax)
{
FILE * in =fopen(input,"r");
char buf[10]="new_maze";
char *new_maze = malloc(sizeof(*new_maze)*strlen(buf));
strcpy(new_maze, buf);
char ** maze = malloc(sizeof(*maze)*3);
maze[0]=malloc(sizeof(**maze)*cmax);
maze[1]=malloc(sizeof(**maze)*cmax);
maze[2]=malloc(sizeof(**maze)*cmax);
FILE *out = fopen(new_maze, "w");
if(out==NULL)
{
fprintf(stderr, "Nie moge zapisac do pliku %s \n", new_maze);
free(new_maze);
fclose(in);
return 0;
}
int l=0;
int c=0;
unsigned char a;
while(l<=2)
{
a=fgetc(in);
if(a=='\n'){l++; c=0;}
else{
maze[l][c]=a;
c++;
}

}
int line=2;
int whichswitch=0;
int whichmid=1;
int whichup=0;
int whichdown=2;
int corridor=0;
int corner=2;
char up,down,right,left;
if(line==2)
	for(int i=0; i<cmax; i++)
	fprintf(out, "%c",'X');
	fprintf(out, "\n");
	while(line<=lmax-1)
{
for(int i=0; i<cmax; i++)
{
	a=maze[whichmid][i];
	if(a=='X')fprintf(out, "%c",'X');
	else if(a=='P') fprintf(out, "P");
	else if(a=='K') fprintf(out, "K");
	else if(a==' ')
	{
		up=maze[whichup][i];
		if(up==' ' || up=='K' || up=='P')corridor++;
		down=maze[whichdown][i];
		if(down==' ' || down=='K' || down=='P')corridor++;
		if(i!=0){
		left=maze[whichmid][i-1];
		if(left==' ' || left=='K'||left=='P')
			corridor++;
		}
		if(i!=cmax){
		right=maze[whichmid][i+1];
		if(right==' ' || right=='K'||right=='P')
			corridor++;
		}
	if(corridor>=3){
		fprintf(out,"%c", ' ');
	corner++;
	}
	else{fprintf(out, " ");}
	corridor=0;

}}
	if(whichmid==1)
{
whichmid=2;
whichup=1;
whichdown=0;
}
else if(whichmid==2)
{
whichmid=0;
whichdown=1;
whichup=2;
}
else if(whichmid==0)
{
whichmid=1;
whichdown=2;
whichup=0;
}
maze=maze_switch( in, maze, cmax,  whichdown);
line++;
	fprintf(out, "\n");


	}
if(line==lmax)
	for(int i=0; i<cmax; i++)
	fprintf(out, "%c", maze[whichmid][i]);

/*for(int i=0; i<=2; i++)
for(int j=0; j<=cmax; j++){
if(j!=cmax)fprintf(stderr,"%c",maze[i][j]);
if(j==cmax)printf("\n");
}*/
fclose(in);
fclose(out);
int *T;
T=way(input, lmax, cmax);
return 0;
}

