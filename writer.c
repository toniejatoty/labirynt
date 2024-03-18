#include "writer.h"

void save(int i, FILE *out, list_t *T) {
	if (i == 0)
		fprintf(out, "START\n");
	if(T[i] == NULL)
		exit(EXIT_FAILURE);
	while(T[i]->czy_min != 1) {
		if(T[i] == NULL)
			exit(EXIT_FAILURE);
		list_t pointer = malloc(sizeof*pointer);
		pointer->next = T[i];
		T[i]=T[i]->next;
		free(pointer->next);
		free(pointer);
	}
	switch(T[i]->kierunek) {
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
	fprintf(out, "FORWARD %d\n", T[i]->odl);
	
	if(T[i]->nr == -2) {
		fprintf(out, "STOP\n");
		exit(EXIT_SUCCESS);
	}
	save(T[i]->nr-1, out, T);
}
