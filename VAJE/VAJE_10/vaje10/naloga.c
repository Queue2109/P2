
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int vsotaI(Vozlisce* zacetek) {
    Vozlisce *v = zacetek;
    int vsota = 0;
    while(v != NULL) {
        vsota += v->podatek;
        v = v->naslednje;
    }
    return vsota;
}

int vsotaR(Vozlisce* zacetek) {
    if(zacetek == NULL)
        return 0;
    return zacetek->podatek + vsotaR(zacetek->naslednje);
}

Vozlisce* vstaviUrejenoI(Vozlisce* zacetek, int element) {
    if(zacetek == NULL) {
        Vozlisce *new = malloc(sizeof(Vozlisce));
        new->podatek = element;
        new->naslednje = NULL;
        zacetek = new;
    } else {
        Vozlisce *iter = zacetek;
        while(iter->naslednje->podatek < element && iter->naslednje != NULL) {
            iter = iter->naslednje;
        }
        Vozlisce *new = malloc(sizeof(Vozlisce));
        new->naslednje = iter->naslednje;
        new->podatek = element;
        iter->naslednje = new;
    }
    return zacetek;
}

Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element) {
    if(zacetek == NULL || element <= zacetek->podatek) {
        Vozlisce *novo = malloc(sizeof(Vozlisce));
        novo->podatek = element;
        novo->naslednje = zacetek;
        return novo;
    }
    zacetek->naslednje = vstaviUrejenoR(zacetek->naslednje, element);
    return zacetek;
}

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}
