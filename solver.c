#include "solver.h"
#include "switch.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "zwalnianie.h"
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

char wasvisited(structure start, structure position, structure special)
{ 
        char rreturn=1;
        if(position==NULL){printf("nie powinienem tu byc 19 linia w rozwiazywaniu"); return 1;}
        if(start==NULL){ return 1;}
        if(position==start) return 1;
if(position->x == start->x && position->y == start->y)
{
if((position->s < start->s)&&( position->s!=-1)&&(start->s!=-1)){
if(start->prev->up!=NULL &&start->prev->up==start) start->prev->up=special;
if(start->prev->right!=NULL &&start->prev->right==start) start->prev->right=special;
if(start->prev->down!=NULL &&start->prev->down==start) start->prev->down=special;
if(start->prev->left!=NULL &&start->prev->left==start) start->prev->left=special;
 // tutaj powinno byc zwolnione wszystko co jest podlaczone z start start->up/down... 
// ale narazie samo free(start) 
 free(start);
return 1;
// tutaj tez jestem w wywolanej funkcji rekurencyjnie make i zwalniam start byc moze byc sytuacja ze bede chcec miec do tego dostep
}
else if ((position->s > start->s) &&(position->s !=-1)&&(start->s!=-1) ){//free(position);
if(position->prev->up!=NULL && position->prev->up==position) position->prev->up = special;
if(position->prev->right!=NULL && position->prev->right==position) position->prev->right = special;
if(position->prev->down!=NULL && position->prev->down==position) position->prev->down = special;
if(position->prev->left!=NULL && position->prev->left==position) position->prev->left = special;
	free(position);
return 2;
}

}
else
{
if(start->up !=NULL)if(start->up->s!=-1)rreturn =wasvisited(start->up, position, special);
if(start->down!=NULL )if(rreturn!=2)if(start->down->s!=-1)rreturn = wasvisited(start->down, position, special);
if(start->right!=NULL)if(rreturn!=2)if(start->right->s!=-1)rreturn = wasvisited(start->right, position, special);
if(start->left!=NULL)if(rreturn!=2)if(start->left->s!=-1)rreturn = wasvisited(start->left, position, special);
//Tutaj sa jakies bledy ze zwalnianiem jak mam free(position) position = special i wracam do funkcji z której zostalem wywolany to tam normalnie position->x = prawdziwa wartosc position->y tak samo position->s = duza liczba a powinno byc position->x zero/losowa liczba tak samo y a position->s=-1 aktualnie po protsu wylaczam ta funckje nie dziala nie wiem czmeu
//printf("%d\n", position->s);
}

return rreturn;
printf("Jestem tu mimo ze przez return powinienm przejsc");
}

void make(structure start, char ** maze, char * input, int *T, int from, structure position, structure finish,structure special)
{ 
        int upp=0,rright=0, ddown=0, lleft=0; //to know what directories are possible to reach in wierzcholek 
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
{
	while(T[0]/100!=T[2]){
	if(T[0]/100<T[2]){T[2]--; load(maze, input, T);}
	else if(T[0]/100>T[2])
	{T[2]++; load(maze, input, T);}}
	corridors=0;
        upp=0; ddown=0; rright=0; lleft=0;
if(T[0]%100!=0){if(maze[(T[0]-1)%100][T[1]]==' '||maze[(T[0]-1)%100][T[1]]=='P'){corridors ++; upp++; }
if(maze[(T[0]-1)%100][T[1]]=='K'){Kon=1;}
}else{T[2]--; 
	maze=load(maze, input, T); 
	if(maze[(T[0]-1)%100][T[1]]==' '||maze[(T[0]-1)%100][T[1]]=='P'){corridors ++;upp++;}
 if(maze[T[0]%100][T[1]]=='K'){Kon=1;}
T[2]++; maze=load(maze,input,T);}
if(T[0]%100!=99){if(maze[(T[0]+1)%100][T[1]]==' '||(maze[(T[0]+1)%100][T[1]]=='P')){corridors ++;ddown++;}
if(maze[(T[0]+1)%100][T[1]]=='K')Kon=3;}
else{T[2]++; maze=load(maze, input, T); if(maze[(T[0]+1)%100][T[1]]==' '||(maze[(T[0]+1)%100][T[1]]=='P')){corridors ++;ddown++;}
if(maze[(T[0]+1)%100][T[1]]=='K')Kon=3;
T[2]--; maze=load(maze,input,T);}
if(maze[T[0]%100][T[1]-1]==' '||maze[T[0]%100][T[1]-1]=='P'){corridors ++;lleft++;}
if(maze[T[0]%100][T[1]-1]=='K')Kon=4;
if(maze[T[0]%100][T[1]+1]==' '||maze[T[0]%100][T[1]+1]=='P'){corridors ++;rright++;}
if(maze[T[0]%100][T[1]+1]=='K')Kon=2;
if(corridors==2&&Kon==-1){
if(upp==1&&from !=1){if(T[0]%100==0){T[2]--; maze=load(maze, input,T);}T[0]--;from=3;}
else if(ddown==1&&from !=3){if(T[0]%100==99){T[2]++; maze=load(maze, input, T);}T[0]++; from=1; }
else if(lleft==1&& from !=4 ){T[1]--; from =2; }
else if(rright==1&&from != 2){T[1]++; from =4;}
s++;
}
}
while(corridors==2&&Kon==-1);
//s++;
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
	//printf("ZNALAZLEM SIE wedlug programu w wierzczholku T[0] = %d, T[1] = %d\n", T[0], T[1]);
        position->x = T[0]; 
position->y = T[1];
structure tmp = start;
if(wasvisited(tmp, position,special)!=2){
        
	if(upp==1&&from!=1&& position != NULL &&position->s !=-1)
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
        make(start, maze, input, T, 3, position->up,finish, special);
        
	if(position->up->up!=NULL && position->up->up->s ==-1 && position->up->down!=NULL && position->up->down ->s ==-1 && position->up->right!=NULL &&position->up->right->s ==-1 && position->up->left!=NULL && position->up->left->s==-1){ 
		if(position->up!=NULL && position->up->s!=-1){free(position->up);} position->up = special; 
		//printf("OHO zwalniam T[0] = %d, T[1] = %d", T[0], T[1]);
	}
	
	// to moze powodowac bledy ten free na gorze
	T[0]=position->x;
        T[1]=position->y;
        if(T[0]%100==0)
        {T[2]++;
                maze=load(maze,input,T);
        }
        while(T[0]/100!=T[2]){
	if(T[0]/100<T[2]){T[2]--; load(maze, input, T);}
	else if(T[0]/100>T[2])
	{T[2]++; load(maze, input, T);}}

	}
        else {
		position->up = special;}
        if(ddown==1&&from!=3&&position!=NULL && position->s !=-1)
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
        make(start, maze, input, T, 1, position->down,finish, special);
   
if(position->down->up!=NULL && position->down->up->s ==-1 && position->down->down!=NULL && position->down->down ->s ==-1 && position->down->right!=NULL &&position->down->right->s ==-1 && position->down->left!=NULL && position->down->left->s==-1){if(position->down!=NULL && position->down->s !=-1)free(position->down); position->down = special; 
	//printf("OHO zwalniam T[0] = %d, T[1] = %d", T[0], T[1]);
}

	T[0]=position->x;
        T[1] = position->y;
        if(T[0]%100==99)
        {T[2]--;
                maze=load(maze,input,T);
        }
while(T[0]/100!=T[2]){
	if(T[0]/100<T[2]){T[2]--; load(maze, input, T);}
	else if(T[0]/100>T[2])
	{T[2]++; load(maze, input, T);}}

        }
        else position->down=special;
        if(rright==1&&from!=2)
        { T[1]++;
        position->right = malloc(sizeof(*position));
        position->right->s = s+1;
        position->right->prev=position;
        make(start, maze, input, T,4 , position->right, finish, special);

        if(position->right->up!=NULL && position->right->up->s ==-1 && position->right->down!=NULL && position->right->down ->s ==-1 && position->right->right!=NULL &&position->right->right->s ==-1 && position->right->left!=NULL && position->right->left->s==-1){
		if(position->right!=NULL&&position->right->s!=-1)free(position->right); position->right = special; 
		//printf("OHO zwalniam T[0] = %d, T[1] = %d", T[0], T[1]);
	}
	
	T[1]=position->y;
        T[0]=position->x;
        while(T[0]/100!=T[2]){
	if(T[0]/100<T[2]){T[2]--; load(maze, input, T);}
	else if(T[0]/100>T[2])
	{T[2]++; load(maze, input, T);}}

	}
        else position->right=special;
        if(lleft==1&&from!=4)
        {
                T[1]--;
        position->left = malloc(sizeof(*position));
        position->left->s = s+1;
        position->left->prev=position;
		make(start, maze, input, T, 2, position->left, finish,special );
        
        if(position->left->up!=NULL && position->left->up->s ==-1 && position->left->down!=NULL && position->left->down ->s ==-1 && position->left->right!=NULL &&position->left->right->s ==-1 && position->left->left!=NULL && position->left->left->s==-1){if(position->left!=NULL&&position->left->s!=-1)free(position->left); position->left = special; 
		//printf("OHO zwalniam T[0] = %d, T[1] = %d", T[0], T[1]);
		}
        T[1]=position->y;
        T[0]=position->x;
        while(T[0]/100!=T[2]){
	if(T[0]/100<T[2]){T[2]--; load(maze, input, T);}
	else if(T[0]/100>T[2])
	{T[2]++; load(maze, input, T);}}

	}
        else position->left = special;
}
//koniec wasvisited
}
 
       if(position->up!=NULL && position->up->s ==-1 && position->down!=NULL && position->down ->s ==-1 && position->right!=NULL &&position->right->s ==-1 && position->left!=NULL && position->left->s==-1){
	if(position->prev!=NULL){
      	if (position->prev->up !=NULL && position->prev->up == position) position->prev->up = special;
       	if (position->prev->down !=NULL && position->prev->down == position) position->prev->down = special;
       	if (position->prev->right !=NULL && position->prev->right == position) position->prev->right = special;
       	if (position->prev->left !=NULL && position->prev->left == position) position->prev->left = special;
	}
       free(position);
position=special;
       //printf("aha\n");
       }
       
	
else if(corridors==1&&Kon==-1&& position!=NULL && position->s!=-1)
{
        if(fromorg == 1)
        if(position->prev!=NULL)
                if((position->prev->down)!=NULL)
		{ 
        position->prev->down=special;
		}
        if(fromorg == 2)
                if(position->prev!=NULL)
		{
        position->prev->left=special;
		}
        if(fromorg == 3)
                if(position->prev!=NULL)
		{
        position->prev->up=special;
		}
        if(fromorg == 4)
                if(position->prev!=NULL){
        position->prev->right=special;
		}
        //printf("ZWALANIAM position->%d, position->%d\n",position->x, position->y);
	free(position);
	position=NULL;
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
        maze[i]=malloc(sizeof(**maze)*1026);
}
int from; //1 up 2 right 3 down 4 left
//maze=load(maze, input, T);
maze = whereP(maze, l ,c, input,T);
T[0]=T[7]+100*T[9];
T[1]=T[8]+100*T[9];
if(T[0]==0){T[0]++; from =1;} // w tym warunku i w 3 pod nim sprawdzic czy na pewno tam jest spacja
if(T[1]==0){T[1]++; from = 4; }
if(T[0]==T[5]){T[0]--; from =3;}//moze byc blad ze trzeba skorzystac z load fukcji
if(T[1]==T[6]){T[1]--;from=2;}
structure finish = malloc(sizeof(*finish));
finish->prev=NULL;
finish->s = INT_MAX;
structure start = malloc(sizeof(*start));
structure position=start ; // actual my position in structure
start->prev = NULL;
structure special = malloc(sizeof(*special)); // to differ null null when no checked special when no connection
special->s=-1;
special->up=NULL; special->down=NULL; special->right=NULL; special->left=NULL;
start->s=1;

make(start, maze, input, T, from, start, finish,special);
printf("%d", finish->s);
for(int i=0; i<100; i++)
        free(maze[i]);
free(maze);
return T;

}

