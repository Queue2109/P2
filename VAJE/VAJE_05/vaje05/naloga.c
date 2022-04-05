
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

int vsota(int* zac, int* kon) {
    int vsotaEl = 0;
    /*int *pi;
    pi = &(zac[0]);
    while(pi != kon) {
        vsotaEl += *pi;
        pi++;
    }*/
    while(zac <= kon) {
        vsotaEl += *zac;
        zac++;
    }
    return vsotaEl;
}

void indeksInKazalec(int* t, int* indeks, int** kazalec) {
   
    if(*indeks == -1) {
        int i = 0;
        while(1) {
            if((t + i) == *kazalec) {
                *indeks = i;
                break;
            }
            i++;
        } 
    } else {
        *kazalec = t + *indeks;
    }
    
}

void frekvenceCrk(char* niz, int** frekvence) {
    char *p = niz;

    int *pogostosti = calloc(26, sizeof(int));

    while(*p != '\0'){
        char znak = *p;

        if((znak >= 'A' && znak <= 'Z') || (znak >= 'a' && znak <= 'z')){
            int indeks = (znak >= 'a') ? (znak - 'a') : (znak - 'A');
            pogostosti[indeks]++;
        } 
        p++;
    }
    *frekvence = pogostosti;
}

int main() {
    // koda za ro"cno testiranje (po "zelji)
  
    return 0;
}
