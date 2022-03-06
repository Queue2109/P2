#include <stdio.h>
/* 
Izberem si neko zaporedje s semenom in ga 
iz koraka v korak spreminjam po formuli:
n sod: naslednji el. zaporedja je n/2
n lih: n*3 + 1
Slej ali prej se bo zaporedje končalo
z 1, ne zna pa tega nihče dokazat baje
*/

/*  deklaracija funkcije - ime, kaj vrne, 
    kaj sprejme
    če to narediš, lahko definiraš nekje 
    drugje, ni važno če jo kličeš najprej*/

int collatz(int n); // <- LEPO IN PRAV
//int collatz(int);    <- GRDO IN PRAV
//int collatz(n); int n; <- GRDO IN PRAV
int collatz_length(int n) {
    int len = 1;
    while(n != 1) {
        n = collatz(n);
        len++;
    }
    return len;
}

int collatz(int n) {
    if(n % 2 == 0) {
        return n / 2;
    } else {
        return n * 3 + 1;
    }
}

int main() {
    int n = 2022;
    printf("%d\n", collatz_length(n));
    return 0;
}