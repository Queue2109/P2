#include <stdio.h>

void perms(int *elems, int num_elems, int i) {

    if(i == num_elems) {
        for(int j = 0; j < num_elems; j++) {
            printf("%d ", elems[j]);
        }
        printf("\n");
        return;
    }

    for(int j = i; j < num_elems; j++) {
        int temp;
        temp = elems[i];
        elems[i] = elems[j];
        elems[j] = temp;
        perms(elems, num_elems, i + 1);
        // napišemo še enkrat, zato da damo v prvotno stanje in izpiše po vrsti
        temp = elems[i];
        elems[i] = elems[j];
        elems[j] = temp;
    }
}

int main() {

    static int elems[1000];
    int num_elems = 4;
    for(int j = 0; j < num_elems; j++) {
        elems[j] = j + 1;
    }
    perms(elems, num_elems, 0);

    return 0;
}

// razložen algoritem v word file-u