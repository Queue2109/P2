#include <stdio.h>

int main() {
    for(int i = 0; i < 10; i++) {
        int j;
        fprintf(stdout, "OUT\n %d", i);
        scanf("%d", &j);
        fprintf(stderr, "ERR %d", i);
    }

    
    int n;
    for(int i = 0; i < 1000; i++) {
        fread(&n, sizeof(int), 1, stdin);
        printf("%d\n", n);
    }
    

    /*
    long int n;
    for(int i = 0; i < 1000; i++) {
        fread(&n, sizeof(long int), 1, stdin);
        printf("%ld\n", n);
    }
    */
   

    return 0;
}