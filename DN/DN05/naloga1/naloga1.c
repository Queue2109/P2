
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -e__main__ -o test01 test01.c naloga1.c
./test01

*/

#include <stdio.h>
#include <stdlib.h>

#include "naloga1.h"

int* poisci(int* t, int* dolzina, int** konec) {
    // popravite / dopolnite ...
    int dol = 0;
    int *trenutni = t;
     while(*(trenutni - 1) != 0) {
        trenutni--;
    }
    int *vrni = trenutni;

    while(*(trenutni + 1) != 0) {
        dol++;
        trenutni++;
    }
    dol++;
    *dolzina = dol;
    *konec = trenutni;
    return vrni;
}

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}
