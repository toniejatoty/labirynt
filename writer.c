#include "writer.h"

void save(int i, FILE *out, list_t *T) {
	fprintf(out, "START\n");
	list_t pointer = T[i];
	while(pointer->czy_min != 1) {
		if(pointer->next == NULL)
			exit EXIT_FAILURE;
		pointer=pointer->next;
	}
	if (i == 0)
		fprintf(out, "FORWARD %d\n", pointer->odl);
	else {
		switch(pointer->kierunek) {
			case -1:
				fprintf(out,"TURNLEFT\n");
				break;
			case 1:
				fprintf(out,"TURNRIGHT\n");
				break;
			default:
				fprintf(stderr, "Nie powinienem tu być!\n");
				break;	
		}
		fprintf(out, "FORWARD %d\n", pointer->odl);
	}
	if(pointer->nr == -2) {
		fprintf(out, "STOP\n");
		exit EXIT_SUCCESS;
	}
	save(pointer->nr, out, T);
}
