#ifndef _READER_H_ 
#define _READER_H_

char * kopiuj_plik(char * input, char *aout);
char czypoprawnylab(char *input, char *aout);
char bledy(char * input,char a, int ktorywiersz, int ktorakolumna, int wspolrzednaPx, int wspolrzednaPy, int wspolrzednaKx, int wspolrzednaKy, char komunikat, int T[] );
int *rozmiar(char * input);

#endif 
