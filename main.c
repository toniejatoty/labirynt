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
char * zpliku2 =kopiuj_plik(zpliku, argv[0]);
if(zpliku2=="BLAD"){
free(zpliku);
free(zpliku2);
return 1;
//BYc moze tutaj eszcze cos zwolnic
}
char a;

FILE *in = fopen(zpliku, "r");
while((a=fgetc(in))!=EOF){
	printf("%c",a);
}
fclose(in);
free(zpliku);
//free(zpliku2); nie wiem czemu ale jest blad z tym	
return 0;

}
