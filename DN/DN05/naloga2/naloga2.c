
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -e__main__ -o test01 test01.c naloga2.c
./test01

*/

#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

void zamenjaj(int** a, int** b) {
    // dopolnite ...
    int prvaVrednost = **a;
    int drugaVrednost = **b;

    **a = drugaVrednost;
    **b = prvaVrednost;
    
}

int compare (const void* a, const void* b)
{
  return ( *(int*)a - *(int*)b );
}

void uredi(int** a, int** b, int** c) {
    // dopolnite ...
    int tab[3];
    tab[0] = **a;
    tab[1] = **b;
    tab[2] = **c;

    qsort(tab, 3, sizeof(int), compare);
    
    **a = tab[0];
    **b = tab[1];
    **c = tab[2];
}



int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}
