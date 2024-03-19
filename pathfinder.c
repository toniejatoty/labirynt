#include <limits.h>
#include "pathfinder.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
void backasfarasyoucan(structure finish, int * T)
{
	//return;
structure tmp2;
	if(finish->prev==NULL) return;
structure tmp= finish -> prev;
do
{tmp2=tmp;
	if(tmp->prev!=NULL)
tmp=tmp->prev;
free(tmp2); // TU MOGA BYC BLEDY ZE FREE UZYLEM A POTEM W CORRIDORS>=3 sie cofam a tu position==NULL
}
while(tmp->prev!=NULL && tmp->down!=NULL && tmp -> up !=NULL && tmp->right!=NULL && tmp-> left!=NULL&& tmp->down->s==-1&& tmp->up->s==-1 && tmp->right->s==-1 && tmp->left->s==-1);
}
void delasmuch(structure finish, int *T)
{
//return;
	if(finish->prev==NULL){printf("nie powinno byc bledu ale w razie czego to pathfindr backasfar"); return;}
structure tmp= finish;
do
{
	if(finish->prev!=NULL)
	tmp=finish;
		finish=finish->prev;
free(tmp); // TU MOGA BYC BLEDY ZE FREE UZYLEM A POTEM W CORRIDORS>=3 sie cofam a tu position==NULL
}
while(finish->prev!=NULL && finish->down!=NULL && finish -> up !=NULL && finish->right!=NULL && finish-> left!=NULL&& finish->down->s==-1&& finish->up->s==-1 && finish->right->s==-1 && finish->left->s==-1);
}
/*
void findwspolne(structure oldfinish, structure newfinish)
{
	structure old=finish;
	structure new=newfinish;
while(old->prev!=NULL)
{ old=old->prev;

while(new->prev!=NULL)
}
}*/
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
void make(char ** maze, char * input, int *T, int from, structure position, structure finish,structure special)
{int upp=0,rright=0, ddown=0, lleft=0; //to know what directories are possible to reach in wierzcholek 
int corridors = 0;
int fromorg = from;
int s = position->s;
position->up = NULL;
position->right = NULL;
position->down = NULL;
position->left = NULL;
int Pon=-1;
int Kon=-1; //if k is on up 1 right 2 ...
do
{corridors=0;
	upp=0; ddown=0; rright=0; lleft=0;
if(T[0]%100!=0){if(maze[(T[0]-1)%100][T[1]]==' '||maze[(T[0]-1)%100][T[1]]=='P'){corridors ++; upp++; }
if(maze[(T[0]-1)%100][T[1]]=='K'){Kon=1;}
}else{T[2]--; maze=load(maze, input, T); if(maze[(T[0]-1)%100][T[1]]==' '||maze[(T[0]-1)%100][T[1]]=='P'){corridors ++;upp++;}
 if(maze[(T[0]-1)%100][T[1]]=='K'){Kon=1;}
T[2]++; maze=load(maze,input,T);}
if(T[0]%100!=99){if(maze[(T[0]+1)%100][T[1]]==' '||(maze[(T[0]+1)%100][T[1]]=='P')){corridors ++;ddown++;}
if(maze[(T[0]+1)%100][T[1]]=='K')Kon=3;}
else{T[2]++; maze=load(maze, input, T); if(maze[(T[0]+1)%100][T[1]]==' '||(maze[(T[0]+1)%100][T[1]]=='P')){corridors ++;ddown++;}
if(maze[(T[0]+1)%100][T[1]]=='K')Kon=3;
T[2]--; maze=load(maze,input,T);}
if(maze[T[0]][T[1]-1]==' '||maze[T[0]][T[1]-1]=='P'){corridors ++;lleft++;}
if(maze[T[0]][T[1]-1]=='K')Kon=4;
if(maze[T[0]][T[1]+1]==' '||maze[T[0]][T[1]+1]=='P'){corridors ++;rright++;}
if(maze[T[0]][T[1]+1]=='K')Kon=2;
if(corridors==2&&Kon==-1){
if(upp==1&&from !=1){if(T[0]%100==0){T[2]--; maze=load(maze, input,T);}T[0]--;from=3;}
else if(ddown==1&&from !=3){if(T[0]%100==99){T[2]++; maze=load(maze, input, T);}T[0]++; from=1; }
else if(lleft==1&& from !=4 ){T[1]--; from =2; }
else if(rright==1&&from != 2){T[1]++; from =4;}
s++;
}
}
while(corridors==2&&Kon==-1);
s++;
if(Kon!=-1)
{
	printf("ZNALAZLEM SIE W K odl wynosi %d\n",s);
if(s < finish->s)
{
backasfarasyoucan(finish, T);
finish->s = s; 
finish ->prev = position;
}
else
{
delasmuch(position,T);
}
}	
if(corridors>=3&&Kon==-1)
{position->s = s;
	position->x = T[0]; // jak bedzie brakowac miejsca to bedzie pierwsza rzecz do odstrzalu wraz z y
position->y = T[1];
	if(upp==1&&from!=1)
	{
	position->up = malloc(sizeof(*position));
       	position->up->s = s+1; //tu chyba tez fromorg 
	if(T[0]%100==0)
	{
	T[2]--;
	maze=load(maze,input,T);
	}
	T[0]--;
	position->up->prev = position;
	make(maze, input, T, 3, position->up,finish, special);	
	T[0]=position->x;
	T[1]=position->y;
	if(T[0]%100==0)
	{T[2]++;
		maze=load(maze,input,T);
	}
	}
	else position->up = special;
	if(ddown==1&&from!=3)
	{
	if(T[0]%100==99)
	{
	T[2]++;
	maze=load(maze,input,T);
	}
	T[0]++;
	position->down = malloc(sizeof(*position));
       	position->down->s = s+1;
	position->down->prev=position;
	make(maze, input, T, 1, position->down,finish, special);	
	T[0]=position->x;
	T[1] = position->y;
	if(T[0]%100==99)
	{T[2]--;
		maze=load(maze,input,T);
	}
	}
	else position->down=special;
	if(rright==1&&from!=2)
	{ T[1]++;
	position->right = malloc(sizeof(*position));
       	position->right->s = s+1;
	position->right->prev=position;
	make(maze, input, T,4 , position->right, finish, special);	
	T[1]=position->y;
	T[0]=position->x;
	}
	else position->right=special;
	if(lleft==1&&from!=4)
	{
		T[1]--;
	position->left = malloc(sizeof(*position));
       	position->left->s = s+1;
	position->left->prev=position;
	make(maze, input, T, 2, position->left, finish,special );	
	T[1]=position->y;
	T[0]=position->x;
	}
	else position->left = special;
}

else if(corridors==1)
{
	if(fromorg == 1)
	if(position->prev!=NULL)
		if((position->prev->down)!=NULL)
	position->prev->down=special;
	if(fromorg == 2)
		if(position->prev!=NULL)
	position->prev->left=NULL;
	if(fromorg == 3)
		if(position->prev!=NULL)
	position->prev->up=NULL;
	if(fromorg == 4)
		if(position->prev!=NULL)
	position->prev->right=NULL;
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
structure finish = malloc(sizeof(*finish));
finish->prev=NULL;
finish->s = INT_MAX;
structure start = malloc(sizeof(*start));
structure position = start; // actual my position in structure
structure special = malloc(sizeof(*special)); // to differ null null when no checked special when no connection
special->s=-1;
start->s=0;
make(maze, input, T, from, start, finish,special);
printf("INT MAX wynosi %d \n", INT_MAX);
printf("%d", finish->s);
for(int i=0; i<100; i++)
	free(maze[i]);
free(maze);
return T;

}
