#include <stdio.h>

long primeFactorisation() {
    long prime = 0;
    int stevec = 1;
    int truth = 0;
    for(int i = 3; stevec <= 10001; i++) {
            for(int j = 2; j < i; j++) {
                if(i % j == 0) {
                   truth = 0; break;
                }
                else truth = 1;
            }
            if(truth) {
                stevec++;
                prime = i;
                if(stevec == 10001)
                    return prime;
            }
    }

    return prime;
}

int main() {
    printf("%ld\n", primeFactorisation());
    return 0;
}

