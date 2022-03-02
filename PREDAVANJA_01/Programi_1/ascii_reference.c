#include <stdio.h>

int main() {
    int n = 0; 
    int c;
    do {
        c = getchar();
        if(('0' <= c) && (c <= '9'))
            n = n * 10 + (c - '0'); // ascii!
        else {
            if(c != '\n') {
                printf("ERROR \n");
                return 1;
            }
        }

    } while(c != '\n');
    
    printf("%d\n", n);
    return 0;
}