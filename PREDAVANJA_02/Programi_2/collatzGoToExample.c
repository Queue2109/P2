#include <stdio.h>

//go-to example
int collatz(int n) {
    if(n % 2 == 0) {
        goto even;
    } 
    odd: 
        n = 3*n + 1;
        goto exit;
    even: 
        n = n/2;
        goto exit;
    exit:
        return n;
}

int collatz_length(int n) {
    int len = 1;
    while(n != 1) {
        n = collatz(n);
        len++;
    }
    return len;
}

int main() {
    int n = 2022;
    printf("%d\n", collatz_length(n));
    return 0;
}