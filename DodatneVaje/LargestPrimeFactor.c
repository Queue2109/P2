#include <stdio.h>

long primeFactorisation(long num) {
    long najvecja = 2;
    while(num % 2 == 0) {
        num /= 2;
    }
    for(long i = 3; num != 1; i++) {
        if(num % i == 0) {
            for(long j = 2; j < i; j ++) {
                if(i % j == 0)
                break;
                else {
                    while(num % i == 0) {
                        num /= i;
                        if(i > najvecja)
                            najvecja = i;
                    }
                }
            }
        }
    }

    return najvecja;
}

int main() {
    long number = 600851475143;

    printf("%ld\n", primeFactorisation(number));
    return 0;
}

