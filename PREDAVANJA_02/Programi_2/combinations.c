#include <stdio.h>

int combs(int n);

int main() {
    printf("%d\n", combs(4));
}

int combs(int n) {
    int stKombinacij = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                printf("%d %d %d\n", i, j, k);
                stKombinacij++;
            }
        }
    }
    return stKombinacij;
}