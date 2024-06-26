#include <limits.h>
#include "solver.h"
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "help.h"
#include "reader.h"
#include "structure.h"
#include "switch_writer.h"
#include "writer.h"
#include "binary_reader.h"
void freee(structure position)
{
if(position->up!=NULL && position->up->s!=-1){freee(position->up);}
if(position->down!=NULL && position->down->s!=-1){freee(position->down);}
if(position->right!=NULL && position->right->s!=-1){freee(position->right);}
if(position->left!=NULL && position->left->s!=-1){freee(position->left);}
free(position);
position=NULL;
}
int main(int argc, char ** argv)
{
int opt;
char h=0; char czybylom=0; char *zpliku = NULL; FILE * out=stdout; char * dopliku = NULL; char czybin = 0;
while((opt=getopt(argc, argv, "m:o:hb"))!=-1){
	switch(opt)
	{
	case 'm':
		zpliku=strdup(optarg);
	      czybylom = 1;
		break; 
	case 'o':
		dopliku=strdup(optarg);
		out = fopen(optarg, "w");
		break;  
	case 'h':
	if(optarg == NULL|| strcmp(optarg, "")==0)	
		h=4;
		break;
	case 'b':
		czybin=1;
		break;
	
	default:
	break;
	}
}
if(h==4)
	{
	help();
		return 0;
	}
if(czybylom == 0 )
	{
	printf("Nie zostala podana mapa z labiryntem przesze napisac '-m nazwapliku' aby program mogl dzialac normalnie \n");
	//+ instrukcja?
	return 1;
}
FILE * intest  =fopen(zpliku, "r");
if(intest==NULL)
{
fprintf(stderr, "Program nie posiada uprawnień do otwarcia podanego pliku %s", zpliku);
free(zpliku);
return 1;
}
fclose(intest);
if(out ==NULL)
{
fprintf(stderr,"Program nie posiada uprawnień do zapisania w podanym pliku rozwiązania %s",dopliku );
free(zpliku);
return 1;
}

int *T;
if(czybin != 0) {
	T=binary_read(zpliku);
	zpliku="binary_to_text";
}
if((czypoprawnylab(zpliku,argv[0]))!=0)
{
free(zpliku);
return 1;
//BYc moze tutaj eszcze cos zwolnic
}

T=rozmiar(zpliku);
structure start =way( zpliku, T[0], T[1] );
if(dopliku!=NULL)free(dopliku);
structure special = start->prev;
structure finish = special->prev;
T[2] = start->x;
T[3] = start->y;
if(finish->s !=INT_MAX){ 
fprintf(out, "\nSTART\n");
char ** maze = malloc(sizeof(*maze ) * T[7]);
for(int i=0; i<T[7]; i++)
maze[i] = malloc(sizeof(**maze)* 1025);
maze = load2(maze, zpliku, T );
go_start_first_vertex(out, zpliku,T,start,maze);
fprintf(out, "STOP");

for(int i=0; i<T[7]; i++)
free(maze[i]);
free(maze);
}
if(czybin==0)
	free(zpliku);
free(T);
freee(start);
//free(finish) nie rozumiem czemu jak to sie odblokuje to nie stwarza to bledow finish jest usuwane w freee a mimo ze jak jest odkomentowane to bledow nie robi aplikacja do badania pamieci pokazuje ze i z tym zakomentowanym i bez tego nie wplywa to na dzialanie programu

if(special!=NULL&& special->s==-1)free(special);
fclose(out);

return 0;
}

// Trzeba sprawdzic w tym readerze czy P jest w pierwszym segmencie
