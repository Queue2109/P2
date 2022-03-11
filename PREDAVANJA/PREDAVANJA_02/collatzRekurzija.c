#include <stdio.h>

int collatz(int n) {
    if(n % 2 == 0) {
        return n / 2;
    } else {
        return n * 3 + 1;
    }
}

//predpostavka: n=1
int collatz_length(int n) {
    if(n == 1)
        return 1;
    else {
        return 1 + collatz_length(collatz(n));
    }
}

int main() {
    int n = 2022;
    printf("%d\n", collatz_length(n));
    return 0;
}