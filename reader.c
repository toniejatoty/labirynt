#include "reader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char czypoprawnylab(char *input, char *aout);

char bledy(char *input, char a, int ktorywiersz, int ktorakolumna, int wspolrzednaPx, int wspolrzednaPy, int wspolrzednaKx, int wspolrzednaKy, char komunikat, int T[])
{
        switch (komunikat)
        {
        case 1:
                fprintf(stderr, "Podany plik %s w wierszu %d, kolumnie %d posiada niedozwolony znak %c. Proszę podać plik z mapą o poprawnym formacie, nieposiadającą niedozwolonych znaków\n", input, ktorywiersz, ktorakolumna, a);
                return 1;
                break;
        case 2:
                fprintf(stderr, "Podany plik %s w wierszu %d, kolumnie %d ma spacje a powinien być znak X. Proszę podać plik z mapą o poprawnym formacie, która będzie okrążona znakami X.\n", input, ktorywiersz, ktorakolumna);
                return 1;
                break;
        case 3:
                fprintf(stderr, "Podany plik %s w wierszu %d, kolumnie %d zawiera literę P, która została już zadeklarowana w wierszu %d, kolumnie %d. Proszę podać plik z mapą o poprawnym formacie, z tylko jedną literą P na krańcu labiryntu\n", input, ktorywiersz, ktorakolumna, wspolrzednaPx, wspolrzednaPy);
                return 1;
                break;
        case 4:
                fprintf(stderr, "Podany plik %s w wierszu %d, kolumnie %d zawiera literę K, która została już zadeklarowana w wierszu %d, kolumnie %d. Proszę podać plik z mapą o poprawnym formaciem, z tylko jedną literą K na krańcu labiryntu\n", input, ktorywiersz, ktorakolumna, wspolrzednaKx, wspolrzednaKy);
                return 1;
                break;
        case 5:
                fprintf(stderr, "Podany plik %s w wierszu %d zawiera %d kolumn gdzie w poprzednim wierszu bylo %d kolumn. Proszę podać plik z mapą o poprawnym formacie, z taka sama iloscia kolumn w kazdym wierszu\n", input, T[0], T[2], T[3]);
                return 1;
                break;
        case 6:
                fprintf(stderr, "Podany plik %s w wierszu %d kolumnie %d ma znak %c. Proszę podać plik z mapą o poprawnym formacie, ze znakiem X lub ' '\n", input, ktorywiersz, ktorakolumna, a);
                return 1;
                break;
        case 7:
                fprintf(stderr, "Podany plik %s nie zawiera litery P na granicy labiryntu. Proszę podać plik z mapą o poprawnym formacie, która będzie posiadać jedną literę P na krańcu labiryntu\n", input);
                return 1;
                break;
        case 8:
                fprintf(stderr, "Podany plik %s nie zawiera litery K na granicy labiryntu. Proszę podać plik z mapą o poprawnym formacie, która będzie posiadać jedną literę K na krańcu labiryntu\n", input);
                return 1;
                break;
        case 9:
                fprintf(stderr, "Podany plik %s zawiera labirynt o rozmiarze %d, %d, a maksymalny akceptowalny rozmiar to 1024×1024. Proszę podać plik z mapą o poprawnym formacie, z odpowiednim romziarem", input, T[0], T[1]);
                return 1;
                break;
        case 10:
                fprintf(stderr, "Podany plik %s zawiera labirynt o rozmiarze %d, %d, a minimalny akceptowalny rozmiar to 3×3. Proszę podać plik z mapą o poprawnym formacie, z odpowiednim romiarem", input, T[0], T[1]);
                return 1;
                break;

        default:
                return 0;
                break;
        }
        return 0;
}
//
//
//
//
int *rozmiar(char *input)
{
        int *T = calloc(10, sizeof(*T));
        char a;
        int w = 0;
        int k = 0;
        FILE *in = fopen(input, "r");
        if (in == NULL)
        {
                T[1] = -2;
                return T;
        }
        do
        {
                a = fgetc(in);
		if(a=='P')
		{
		T[4]=w;
		T[5]=k;
		}
                // if(a==' '||a=='X' || a=='P' || a=='K')
                if (a != '\n')
                        k++;
                if ((a == '\n') && (w == 0))
                {
                        T[1] = k;
                        w++;
                        k = 0;
                }
                else if (a == '\n')
                {
                        if (k != T[1])
                        {
                                T[3] = T[1];
                                T[1] = -1;
                                T[2] = k;
                                T[0] = w;
                                fclose(in);
                                return T;
                        }
                        w++;
                        k = 0;
                }
                T[0] = w;
        } while (a != EOF);
        fclose(in);
        // T[0]--;
        // T[1]--;
        // printf("ROZMIAR WYNOSI %d --> %d", T[0], T[1]);
	// T[2] T[3] do obslugi bledow i do aktualnej pozycji gdzie sie znajduje
        // T4 T5 do wspolrzednej P
	// T6 w ktorym segmencie sie znajduje
	// T7 ile max wierszy jest w segmencie
	// T8 ile jest linii w ostatnim segmencie
	// T9 ile jest segmentow
	T[6] = 0;
	T[7]=5;
	T[8] = T[0]%T[7]==0? T[7]:T[0]%T[7];//T[0]%T[7];
	T[9] = T[0]%T[7] == 0 ? T[0]/T[7] -1: T[0]/T[7];// T[0]/T[7];
	return T;
}

char czypoprawnylab(char *input, char *aout)
{
        int ktorywiersz = 0;
        int ktorakolumna = 0;
        int ilewierszy = 0;
        int ilekolumn = 0;
        int wspolrzednaPx = -1;
        int wspolrzednaPy = -1;
        int wspolrzednaKx = -1;
        int wspolrzednaKy = -1;
        char a;
        int *T;
        T = rozmiar(input);
        FILE *in = fopen(input, "r");
        if (T[0] > 1025 || T[1] > 1025)
        {
                return bledy(input, a, ktorywiersz, ktorakolumna, wspolrzednaPx, wspolrzednaPy, wspolrzednaKx, wspolrzednaKy, 9, T);
        }

        if (T[1] == -1)
                return bledy(input, a, ktorywiersz, ktorakolumna, wspolrzednaPx, wspolrzednaPy, wspolrzednaKx, wspolrzednaKy, 5, T);
        // nie rowna ilosc kolumn
        if (T[1] <= 2 || T[0] <= 2)
                return bledy(input, a, ktorywiersz, ktorakolumna, wspolrzednaPx, wspolrzednaPy, wspolrzednaKx, wspolrzednaKy, 10, T);

        while (((a = fgetc(in)) != EOF))
        {
                if (a != 'P' && a != 'K' && a != 'X' && a != ' ' && a != '\n')

                        return bledy(input, a, ktorywiersz, ktorakolumna, wspolrzednaPx, wspolrzednaPy, wspolrzednaKx, wspolrzednaKy, 1, T);
                // nieodzwolony znak
                if ((ktorywiersz == 0 || ktorakolumna == 0 || (ktorywiersz == (T[0] - 1)) || (ktorakolumna == (T[1] - 1)))
                    //&&(ktorywiersz!=0&&ktorakolumna!=0)
                )
                {
                        if (a != 'P' && a != 'K' && a != 'X' && a != '\n')
                        {
                                return bledy(input, a, ktorywiersz, ktorakolumna, wspolrzednaPx, wspolrzednaPy, wspolrzednaKx, wspolrzednaKy, 2, T);
                                //
                        }
                        else if (a == 'P')
                        {
                                if (wspolrzednaPx != -1)
                                        return bledy(input, a, ktorywiersz, ktorakolumna, wspolrzednaPx, wspolrzednaPy, wspolrzednaKx, wspolrzednaKy, 3, T);
                                else
                                {
                                        wspolrzednaPx = ktorywiersz;
                                        wspolrzednaPy = ktorakolumna;
                                }
                        }
                        else if (a == 'K')
                        {
                                if (wspolrzednaKx != -1)
                                        return bledy(input, a, ktorywiersz, ktorakolumna, wspolrzednaPx, wspolrzednaPy, wspolrzednaKx, wspolrzednaKy, 4, T);
                                else
                                {
                                        wspolrzednaKx = ktorywiersz;
                                        wspolrzednaKy = ktorakolumna;
                                }
                        }
                }
                if (!(ktorywiersz == 0 || ktorakolumna == 0 || (ktorywiersz == (T[0] - 1)) || (ktorakolumna == (T[1] - 1))) || (ktorywiersz == 0 && ktorakolumna == 0) || (ktorywiersz == 0 && (ktorakolumna == T[1] - 1) || (ktorywiersz == T[0] - 1 && ktorakolumna == 0) || (ktorywiersz == T[0] - 1 && ktorakolumna == T[1] - 1)))
                        if (a == 'P' || a == 'K')
                        {
                                return bledy(input, a, ktorywiersz, ktorakolumna, wspolrzednaPx, wspolrzednaPy, wspolrzednaKx, wspolrzednaKy, 6, T);
                        }

                if (a == '\n')
                {
                        ktorakolumna = 0;
                        ktorywiersz++;
                }
                else
                        ktorakolumna++;
        }
        // printf("------PX %d --> pY %d-->kX %d-->Ky %d",wspolrzednaPx, wspolrzednaPy, wspolrzednaKx, wspolrzednaKy );
        if (wspolrzednaPx == -1)
                return bledy(input, a, ktorywiersz, ktorakolumna, wspolrzednaPx, wspolrzednaPy, wspolrzednaKx, wspolrzednaKy, 7, T);
        if (wspolrzednaKx == -1)
                return bledy(input, a, ktorywiersz, ktorakolumna, wspolrzednaPx, wspolrzednaPy, wspolrzednaKx, wspolrzednaKy, 8, T);
fclose(in);
free(T);
        return 0;
}

