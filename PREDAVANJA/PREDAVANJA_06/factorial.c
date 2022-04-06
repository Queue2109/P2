#include <stdio.h>

int fact_itr(int n) {
    int nf = 1;
    for(int i = 1; i <= n; i++) {
        nf = nf * i;
    }
    return nf;
}

int fact_rek(int n) {
    if(n == 0)
        return 1;
    return n * fact_rek(n - 1);
}

int main() {
    for(int i = 0; i < 10; i++) {
        printf("%4d! = %d\n", i, fact_rek(i));
    }
    return 0;
}