#ifndef _STRTUCTURE_H_
#define _STRTUCTURE_H_

typedef struct elem
{
	int s;//odleglosc od poczatku do tego wiercholka
	struct elem *prev; //wskaznik skad przyszlismy
	struct elem *up;	//skaznik na element z gory 
	struct elem *right;	//wskaznik na element z prawa
	struct elem *down;
	struct elem *left;
int x;
int y; //wspolrzedne wierzcholka jak bedzie brakowac pamieci to bedzie peirwsza rzecz do usuniecia
}*structure;


#endif
