#include <stdio.h>
#include <math.h>

long sumSquared() {
    long long vsota = 0;
    for(long long i = 1; i <= 100; i++) {
        vsota += i;
    }
    return pow(vsota, 2);
}

long long eachSquare() {
    long long vsota = 0;
    for(long long i = 100; i >= 1; i--) {
        vsota += pow(i, 2);
    }
    return vsota;
}
int main()  {
    printf("%lld\n", sumSquared() - eachSquare());
}