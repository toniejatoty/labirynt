#include "writer.h"

void save(int i, FILE *out, list_t *T) {
	if (i == 0)
		fprintf(out, "START\n");
	if(T[i] == NULL)
		exit(EXIT_FAILURE);
	list_t pointer = malloc(sizeof*pointer);
	pointer->next = T[i];
	pointer=pointer->next;
	while(pointer->czy_min != 1) {
		if(pointer == NULL)
			exit(EXIT_FAILURE);
		pointer=pointer->next;
	}
	switch(pointer->kierunek) {
		case -1:
			fprintf(out,"TURNLEFT\n");
			break;
		case 1:
			fprintf(out,"TURNRIGHT\n");
			break;
		case 0:
			break;
		default:
			fprintf(stderr, "Nie powinienem tu być!\n");
			break;	
	}
	fprintf(out, "FORWARD %d\n", pointer->odl);
	
	if(pointer->nr == -2) {
		fprintf(out, "STOP\n");
		exit(EXIT_SUCCESS);
	}
	save(pointer->nr-1, out, T);
}
