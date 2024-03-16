#include "solver.h"
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "reader.h"
int main(int argc, char ** argv)
{
int opt;
char h=0;
char czybylom=0;
char *zpliku = NULL;
char * dopliku = NULL;
while((opt=getopt(argc, argv, "m:o:h"))!=-1){
	switch(opt)
	{
	case 'm':
		zpliku=strdup(optarg);
	      czybylom = 1;
		break; 
	case 'o':
		dopliku=strdup(optarg);
		break;  
	case 'h':
	if(optarg == NULL|| strcmp(optarg, "")==0)	
		h=4;
		break;		
	
	default:
	//printf("wychodze defaultem");
	break;
	}}
if(h==4)
	{
	printf("intsrukcja");
	return 0;
	}
if(czybylom == 0 )
	{
	printf("Nie zostala podana mapa z labiryntem przesze napisac '-m nazwapliku' aby program mogl dzialac normalnie \n");
	//+ instrukcja?
	return 1;
}
//
//
//
//
//
char buf[10];
strcpy(buf, kopiuj_plik(zpliku, argv[0]));
char *zpliku2=malloc(sizeof(*zpliku)*strlen(buf)+1);
strcpy(zpliku2, buf);
if(strcmp(zpliku2, "BLAD")==0){
free(zpliku);
free(zpliku2);
return 1;
//BYc moze tutaj eszcze cos zwolnic
}
char a;

FILE *in = fopen(zpliku, "r");
int *T = malloc(sizeof(*T)*4);
T=rozmiar(zpliku2);
if(nazwijwierzcholki( zpliku, T[0], T[1])==0)
	printf("sukces");

fclose(in);
free(zpliku);
free(zpliku2);
return 0;

}
