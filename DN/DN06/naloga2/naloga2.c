
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

int TABELA[][N] = {
    { 5,  7, 12,  9,  8},
    { 1, 15,  3,  6, 14},
    {11, 10,  2, 13,  4}
};


int** ap2pp(int(*kazalec)[N], int izvornoStVrstic, int ciljnoStVrstic) {
    
    printf("%d ", kazalec[0]);

    return NULL;
}

int (*pp2ap(int** kazalec, int izvornoStVrstic, int* ciljnoStVrstic))[N] {
    // popravite / dopolnite
    return NULL;
}


int main() {
    int izvornoStVrstic = sizeof(TABELA) / sizeof(TABELA[0]);
    int ciljnoStVrstic = 5;
    int** rezultat = ap2pp(TABELA, izvornoStVrstic, ciljnoStVrstic);

    for (int i = 0;  i < ciljnoStVrstic;  i++) {
        int* p = rezultat[i];
        while (*p != 0) {
            printf("%3d", *p);
            p++;
        }
        printf("\n");
        free(rezultat[i]);
    }
    free(rezultat);

    exit(0);
    return 0;
}