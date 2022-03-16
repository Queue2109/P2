#include <stdio.h>

long zrcali(long stevilo) {
    long novoStevilo = 0;
    while(stevilo > 0) {
        novoStevilo *= 10;
        novoStevilo += stevilo % 10;
        stevilo /= 10;
    }
    return novoStevilo;
}

long jePalindrom(long stevilo) {
    
    return stevilo == zrcali(stevilo);
}

long sestevanje(long stevilo, long k) {
    for(long i = 0; i < k; i++) {
        long novoStevilo = stevilo + zrcali(stevilo);
        
        if(jePalindrom(novoStevilo))
            return 0;
        stevilo = novoStevilo;
    }
    return 1;
}

int main() {
    long k, a, b;
    scanf("%ld %ld %ld", &k, &a, &b);
    long stevec = 0;

    for(long i = a; i <= b; i++) {
        stevec += sestevanje(i, k);
    }
    printf("%ld\n", stevec);
}