#include <stdio.h>

#define TEKST_SIZE 1024
#define DIFFERENCE 33
#define ZNAKI_ASCII 93 //126-33 rozmiar tablicy = ilosc rozpatrywanych znakow ascii.

int main(){

        char tekst[TEKST_SIZE];
        int histogram[ZNAKI_ASCII];
        char gwiazdki[ZNAKI_ASCII][TEKST_SIZE];

        int i, j, currentChar;

        for( i=0; i<ZNAKI_ASCII; ++i) //wpisujemy 0 do kazdego indeksu poniewaz poczatkowo zaden znak nie wystepuje ani razu.
        {
           histogram[i] = 0;
        }

        fgets(tekst, sizeof(tekst), stdin);  //do zmiennej tekst, o rozmiarze sizeof(tekst), wprowadz dane z stdin -> (klawiatura).

        i=0;

        while( tekst[i] !=10 ) //10 w ascii to Line Feed czyli znak oznaczajacy zakonczenie linii tekstu, czyli koniec tekstu.
        {
           currentChar = (int)tekst[i]; //do zmiennej typu int zrzutuj znak, czyli zdobadz kod ascii danej literki
           histogram[currentChar-DIFFERENCE] += 1; //zwieksz wystapienie znaku o 1.
           ++i;
        }

        printf("\nznak\tliczba znakow\n");
        printf("---------------------\n");

        for( i=0; i<ZNAKI_ASCII; ++i)
        {
           for( j=0; j<histogram[i]; ++j)
           {
              gwiazdki[i][j] = '*';
           }

           if( histogram[i] > 0 )
           {
              printf("%c:\t%d %s\n", i+DIFFERENCE, histogram[i], gwiazdki[i]);
           }
        }

printf("\n");

return 0;
}
