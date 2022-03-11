#include <stdio.h>
#include <math.h>

int pythagorean() {
    for(int a = 1; a < 100; a++) {
        for(int b = a + 1; b < 100; b++) {
            int vsota = pow(a, 2) + pow(b, 2);
            if(sqrt(vsota) == 0) {
                int sqrtA = sqrt(a);
                int sqrtB = sqrt(b);
                int sqrtC = sqrt(vsota);
                if((sqrtA + sqrtB + sqrtC) == 1000)
                    return sqrtA * sqrtB * sqrtC;  
            }

        }
    }
}

int main() {
    printf("%d\n", pythagorean());
    return 0;
}