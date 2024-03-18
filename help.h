#ifndef HELP_H
#define HELP_H
#include <stdio.h>
void help();

void help() {
        printf("Aplikacja ta znajduje najkrótszą drogę z wejścia do wyjścia w podanym labiryncie\n");
        printf("Podany labirynt powinien:\n");
        printf("\t-Posiadać wejście oznaczone literą P oraz wyjście oznaczone literą K z ścianami oznaczonymi symbolem 'X'\n");
        printf("\t-Być rozmiaru maksymalnie 1024 x 1024 licząc po ścieżkach\n");
        printf("\t-Posiadać ściany o maksymalnej grubości jeden\n");
        printf("Zakłdamy również jedynie ruchy w płaszczyznach góra/dół oraz prawo/lewo\n\n");
        printf("OPCJE:\n\n");
        printf("\t-m [nazwa pliku] - Nazwa pliku z labiryntem\n");
        printf("\t-o [nazwa pliku] - Nazwa pliku do którego zostanie zapisany wynik, brak będzie oznaczał, że wynik zostanie wypisany na standardowe wyjście\n");
        printf("\t-h - Podaje pomoc odnośnie programu\n");
}


#endif
