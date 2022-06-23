#include <stdio.h>

// oklepaji so pomembni, če multiplyaš rezultat
#define MAX(a, b) (((a)>(b))?(a):(b)) 

//gcc -E macro.c -----> kaj dobiš v predprocesorju

int max(int a, int b) {
    return (((a)>(b))?(a):(b)) ;
}

int f() {
    static int n = 0;
    n = n + 1;
    return n;
}

int main() {
    for(int i = 0; i < 10; i++) {
        printf("%d ", f());
    }
    printf("\n");
    printf("%d\n",max(getc(stdin), 5));

    return 0;
}