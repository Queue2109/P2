#include <stdio.h>

void f1(int n) {
    printf("f1: n=%d @ %p\n", n, &n);
    n = 2 * n;
    printf("f1: n=%d @ %p\n", n , &n);
}

void f2(int n) {

    printf("f1: n=%d @ %p\n", n, &n);
    n = 2 * n;
    printf("f1: n=%d @ %p\n", n , &n);
}

int main() {

    int i; // v c-ju se na i nastavi random vrednost - PAZI
    
    printf("i=%d @ %p\n", i, &i);
    scanf("%d", &i);
    printf("i=%d @ %p\n", i , &i);

    return 0;
}