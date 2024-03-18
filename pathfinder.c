#include "pathfinder.h"
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
maze[ll][cc]=a;
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
	int opposide=T[4]*T[6]*(T[2]+1)+(T[4]*(T[2]+1));
	int from=100*T[6]*T[2]+(100*T[2]);
	while(i<=opposide-1)
	{
		a=fgetc(in);
		if(a==EOF)return maze;
if(i>=from)
{
maze[ll][cc]=a;
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
	{
if(T[2]==0&&T[3]==0)
{
			for(int i=0; i<T[6]; i++)
			{
			if(maze[0][i]=='P'){a='P';T[7]=0; T[8]=i; }
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
void make(char ** maze, char * input, int *T, int from, structure position, structure special )
{int upp=0,rright=0, ddown=0, lleft=0; //to know what directories are possible to reach in wierzcholek 
int corridors = 0;
int fromorg = from;
int s = position->s;
position->up = NULL;
position->right = NULL;
position->down = NULL;
position->left = NULL;
do
{
if(T[2]%100!=0){if(maze[(T[2]-1)%100][T[3]]==' '){corridors ++; upp++; }
}else{T[2]--; maze=load(maze, input, T); if(maze[(T[2]-1)%100][T[3]]==' '){corridors ++;upp++;}
T[2]++; maze=load(maze,input,T);}
if(T[2]%100!=99){if(maze[(T[2]+1)%100][T[3]]==' '){corridors ++;ddown++;}}
else{T[2]++; maze=load(maze, input, T); if(maze[(T[2]+1)%100][T[3]]==' '){corridors ++;ddown++;}
T[2]--; maze=load(maze,input,T);}
if(maze[T[2]][T[3]-1]==' '){corridors ++;lleft++;}
if(maze[T[2]][T[3]+1]==' '){corridors ++;rright++;}
if(corridors==2){
if(upp==1&&from !=1){if(T[0]%100==0){T[2]--; maze=load(maze, input,T);}T[0]--;from=3;}
if(ddown==1&&from !=3){if(T[0]%100==99){T[2]++; maze=load(maze, input, T);}T[0]++; from=1; }
if(lleft==1&& from !=4 ){T[1]--; from =2; }
if(rright==1&&from != 2){T[1]++; from =4;}
s++;
}}
while(corridors==2);
if(corridors>=3)
{
	if(upp==1&&from!=1)
	{
	position->up = malloc(sizeof(*position));
       	position->up->s = s;
	make(maze, input, T, 3, position->up,special);	
	}
	else position->up = special;
	if(ddown==1&&from!=3)
	{
	position->down = malloc(sizeof(*position));
       	position->down->s = s;
	make(maze, input, T, 1, position->down,special);	
	}
	else position->down=special;
	if(rright==1&&from!=2)
	{
	position->right = malloc(sizeof(*position));
       	position->right->s = s;
	make(maze, input, T,4 , position->right,special);	
	}
	else position->right=special;
	if(lleft==1&&from!=4)
	{
	position->left = malloc(sizeof(*position));
       	position->left->s = s;
	make(maze, input, T, 2, position->left,special);	
	}
	else position->left = special;
}
	if(corridors==1)
{
	if(fromorg == 1)
	position->prev->down=special;
	if(fromorg == 2)
	position->prev->left=special;
	if(fromorg == 3)
	position->prev->up=special;
	if(fromorg == 4)
	position->prev->right=special;
	free(position);
}
	}
int *way(char * input, int l, int c)
{
	int s=0; // distance between wierzhcolki
int *T = malloc(sizeof(*T)*10);
T[0]=0;//wspolrzedna x gdzie sie znajduje aktualnie
T[1]=0;//wspolrzedna y
T[2]=0;//w ktorym segmencie sie znajduje
T[3]=l/100; // ile jest segmentow
T[4]=l%100;//ile jest linii w ostatnim segmencie
T[5]=l;//rozmiar lab
T[6]=c;//rozmiar lab
T[7]=-1; //wspolrzedna Px
T[8]=-1; // wspolrzedna Py
T[9]=0; // w ktorym segmencie jest P
char **maze = malloc(sizeof(*maze)*100);
for(int i=0; i<100; i++){
	maze[i]=malloc(sizeof(**maze)*1025);
}
int from; //1 up 2 right 3 down 4 left
maze=load(maze, input, T);
maze = whereP(maze, l ,c, input,T);
T[0]=T[7]+100*T[9];
T[1]=T[8]+100*T[9];
if(T[0]==0){T[0]++; from =1;}
if(T[1]==0){T[1]++; from = 4; }
if(T[0]==T[5]){T[0]--; from =3;}//moze byc blad ze trzeba skorzystac z load fukcji
if(T[1]==T[6]){T[1]--;from=2;}

structure start = malloc(sizeof(*start));
structure position = start; // actual my position in structure
structure special = malloc(sizeof(*special)); // special structure which will define that from wierzcholek is lack of connection
special->s = -1;
int upp=0,rright=0, ddown=0, lleft=0; //to know what directories are possible to reach in wierzcholek 
int corridors = 0;
if(T[2]!=T[3])
{
if(T[2]%100!=0){if(maze[(T[2]-1)%100][T[3]]==' '){corridors ++; upp++; }
}else{T[2]--; maze=load(maze, input, T); if(maze[(T[2]-1)%100][T[3]]==' '){corridors ++;upp++;}
T[2]++; maze=load(maze,input,T);}
if(T[2]%100!=99){if(maze[(T[2]+1)%100][T[3]]==' '){corridors ++;ddown++;}}
else{T[2]++; maze=load(maze, input, T); if(maze[(T[2]+1)%100][T[3]]==' '){corridors ++;ddown++;}
T[2]--; maze=load(maze,input,T);}
if(maze[T[2]][T[3]-1]==' '){corridors ++;lleft++;}
if(maze[T[2]][T[3]+1]==' '){corridors ++;rright++;}


if(corridors>=3)
{
	if(upp==1&&from!=1)
	{
	position->up = malloc(sizeof(*position));
       	position->up->s = s;	
	}
}

if(corridors==2)
{
if(upp==1&&from !=1){if(T[0]%100==0){T[2]--; maze=load(maze, input,T);}T[0]--;from=3;}
if(ddown==1&&from !=3){if(T[0]%100==99){T[2]++; maze=load(maze, input, T);}T[0]++; from=1; }
if(lleft==1&& from !=4 ){T[1]--; from =2; }
if(rright==1&&from != 2){T[1]++; from =4;}
s++;
}
	if(corridors==1)
;
	}
else if(T[2]==T[3])
{

}	

corridors=0;

for(int i=0; i<100; i++)
	free(maze[i]);
free(maze);
return T;

}
