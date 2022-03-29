
/*

Prevajanje in poganjanje:

gcc -o test01 test01.c tranzitivnost.c -lm
./test01

*/

#include <stdio.h>
#include <stdbool.h>

#include "tranzitivnost.h"

int tranzitivna(int a, int b) {
    int tranzitivna = 1;
    for(int i = a; i <= b; i++) {
        for(int j = i + 1; j <= b; j++) {
            for(int z = j + 1; z <= b; z++) {
                
                tranzitivna = f(i, j) && f(j, z);
                if(tranzitivna)
                    tranzitivna = f(i, z);
                if(!tranzitivna)    
                    return 0;
            }
        }
    }
    return 1;
}

int antitranzitivna(int a, int b) {
    int antitranzitivna = 1;
    for(int i = a; i <= b; i++) {
        for(int j = i + 1; j <= b; j++) {
            for(int z = j + 1; z <= b; z++) {
                antitranzitivna = f(i, j) && f(j, z);
                if(antitranzitivna) {
                    antitranzitivna = !f(i, z);
                }
                if(!antitranzitivna)
                    return 0;
            }
        }
    }
    return 1;
}

int netranzitivna(int a, int b) {
    int netranzitivna = 0;
    for(int i = a; i <= b; i++) {
        for(int j = i + 1; j <= b; j++) {
            for(int z = j + 1; z <= b; z++) {
                netranzitivna = f(i, j) && f(j, z) && !f(i, z);
                if(netranzitivna)
                    return 1;
            }
        }
    }
    return 0;
}

int tranzitivnost(int a, int b) {
    int pogoj1 = tranzitivnost(a, b) && antitranzitivna(a, b);
    if(pogoj1)
        return 1;
    int pogoj2 = tranzitivnost(a, b) && !pogoj1;
    if(pogoj2)
        return 2;
    int pogoj3 = antitranzitivna(a, b) && !pogoj1 && !pogoj2;
    if(pogoj3)
        return 3;
    int pogoj4 = netranzitivna(a, b) && !pogoj1 && !pogoj2 && !pogoj3;
    if(pogoj4)
        return 4;
    return -1;
}



// Ta datoteka NE SME vsebovati funkcij main in f!
// Funkciji main in f sta definirani v datoteki test01.c.
