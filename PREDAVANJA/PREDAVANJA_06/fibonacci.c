#include <stdio.h>
int num_calls;

int fib_rec(int n) {
    num_calls++;
    if(n == 0 || n == 1)
        return 1;
    else 
        return fib_rec(n - 1) + fib_rec(n - 2); 
}

int main() {
    for(int i = 0; i < 20; i++) {
        num_calls = 0;
        printf("fib(%d)= %d (%d)\n", i, fib_rec(i), num_calls);
    }
    return 0;
}
/*
fib(0) = 1
fib(1) = 1
fib(n) = fib(n - 1) + fib(n - 2)
*/