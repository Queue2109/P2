#include <stdio.h>

int elems[1000];

int combs(int *elems, int num_elems, int max_elems, int i) {
    if(i == num_elems) { // vsa mesta v trenutni kombinaciji
        //vsa mesta v trenutni komb so že določena
        for(int j = 0; j < num_elems; j++) {
            printf("%d ", elems[j]);
        }
        printf("\n");
    } else {
        // mesta od 1 do elems - 1 se niso določena

        for(int j = 1; j <= max_elems; j++) {
            elems[i] = j;
            combs(elems, num_elems, max_elems, i + 1);
        }
    }
}

int main() {

    combs(elems, 5, 5, 0);
    return 0;
}