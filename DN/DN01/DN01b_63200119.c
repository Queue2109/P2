#include <stdio.h>

int preberiVhod() {
    int stevilo = 0;
    int temp = 0;
    while(temp != -38) {
        temp = getchar() - '0';
        if(temp == -38)
            break;
        stevilo += temp;
        stevilo *= 10;
    }
    return stevilo / 10;
}

int binaryToDecimal() {
    int a = preberiVhod();
    int decimal = 0;
    int mnozitelj = 1;

    while(1) {
        if((a % 10) == 1)
            decimal += mnozitelj;
        a /= 10;
        mnozitelj *= 2; 
        if(a == 0)
            break;   
    }

    return decimal;
}

int logaritem() {
    int a = binaryToDecimal();
    int logarithm = 0;
    while(a != 1) {
        if(a % 2 == 1)
            a = (a / 2) + 1;
        else 
            a /= 2;
        logarithm++;
    }
    return logarithm;
}

void pisanjeIzhoda() {
    int a = logaritem();
    int stMest = 1;
    while((a / stMest) > 10) {
        stMest *= 10;
    }
    while(stMest != 0) {
        int izpis = a / stMest;
        putchar(izpis + '0');
        a -= (stMest * izpis);
        stMest /= 10;
    }
    putchar('\n');
}

int main() {
    pisanjeIzhoda();
    return 0;
}