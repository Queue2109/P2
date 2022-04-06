
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int steviloZnakov(char* niz, char znak) {
    char *p = (niz);
    int sum = 0;
    while(*p != '\0') {
        if(*p == znak)
            sum++;
        p++;
    }
    return sum;
}

char* kopirajDoZnaka(char* niz, char znak) {
    char *noviNiz = niz;
    while(*noviNiz != znak && *noviNiz != '\0') {
        noviNiz++;
    }
    int dolzinaPodniza = noviNiz - niz;
    char *kopija = malloc((dolzinaPodniza + 1) * sizeof(char));
    char *p = niz;
    char *q = kopija;
    for(int i = 0; i < dolzinaPodniza; i++) {
        *q = *p;
        q++;
        p++;
    }
    *q = '\0';
    return kopija;
}

char** razcleni(char* niz, char locilo, int* stOdsekov) {
    int stOds = steviloZnakov(niz, locilo) + 1;
    char **rezultati = malloc(stOds * sizeof(char*));
    for(int i = 0; i < stOds; i++) {
        rezultati[i] = kopirajDoZnaka(niz, locilo);
        niz += (strlen(rezultati[i]) + 1);
    }
    *stOdsekov = stOds;
    return rezultati;
}


int main() {

    return 0;
}
