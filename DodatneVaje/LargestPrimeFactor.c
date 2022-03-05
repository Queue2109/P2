#include <stdio.h>
#include <math.h>

int aliJePrastevilo(long stevilo) {
    long koren = sqrt(stevilo);
    for(long i = 3; i <= koren; i+=2) {
        if(stevilo % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    long number = 600851475143;
    long koren = sqrt(600851475143) - 1;
    long najvecji = 0;
    
    //prastevila
    for(long i = koren; najvecji != 1; i -= 2) {
        if(aliJePrastevilo(i) == 1) {
            najvecji = i;
            break;
        }
    }
    printf("%ld\n", najvecji);
    return 0;
}

