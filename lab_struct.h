#ifndef STRUCT_LAB_H
#define STRUCT_LAB_H

typedef struct elem {
	int nr;			//nr wierzchołka, -2 = STOP
	int kierunek;		//zmiana kierunku w porównaniu do poprzedniego wierzchołka(pierwszego elementu listy): -1 - turn left, 1 - turn right, 0 - ten sam kierunek
	int odl;		//odległość między wierzchołkami
	int czy_min;		//czy następny na najkrótszej ścieżce: 1 - tak, 0 - nie
	struct elem *next;
} *list_t;

#endif
