#include <stdio.h>

void f1(int n) {
    printf("f1: n=%d @ %p\n", n, &n);
    n = 2 * n;
    printf("f1: n=%d @ %p\n", n , &n);
}

void f2(int *n) {

    printf("f2: n=%d @ %p\n", *n, &n);
    (*n) = 2 * (*n);
    printf("f2: n=%d @ %p\n", *n , &n);
}

int main() {
    
    int n1 = 3;
    int n2 = 4;
    printf("n1=%d n2=%d\n", n1, n2);

    f1(n1);
    f2(&n2);
    printf("n1=%d n2=%d\n", n1, n2);
    // po klicu funkcije f1 ostane n1 enak
    // po klicu funkcije f2 pa se n2 spremeni 
    

    return 0;
}
