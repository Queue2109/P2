#include <stdio.h>

int main() {
    //interval, na katerem je število
    int a, b;
    scanf("%d %d\n", &a, &b);

    int markovClue;
        scanf("%d", &markovClue);
    while(markovClue != 0) {
        
        int stevilo = 0;
        if((a + b) % 2 != 0)
            stevilo = ((a + b - 1) / 2);
        else   
            stevilo = (a + b) / 2;
        if(markovClue == -1) {
            b = stevilo - 1;
        } else if(markovClue == 1) {
            a = stevilo + 1;
        } else {
            break;
        }  
        
        scanf("%d", &markovClue);
    }
    if(a > b)
        printf("PROTISLOVJE\n");
    else if(a == b)
        printf("%d\n", a);
    else {
        printf("%d %d\n", a, b);
    }
    return 0;
}