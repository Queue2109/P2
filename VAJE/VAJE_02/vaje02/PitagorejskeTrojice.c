#include <stdio.h>
#include <math.h>

int pitagora(int num) {
    for(int a = 1; a <= num; a++) {
        for(int b = a; b <= num; b++) {
            if(pow(a, 2) + pow(b, 2) == pow(num, 2))
                return 1;
        }
    }
    return 0;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int stevec = 0;
    for(int i = m; i <= n; i++) {
        if(pitagora(i))
            stevec++;
    }
    printf("%d\n", stevec);


    return 0;
}