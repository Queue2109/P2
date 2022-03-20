#include <stdio.h>

int branjeVhoda() {
    int stevilo = 0;
    int minus = 0;
    while(1) {
        int temp = getchar();
        if(temp != 32 && temp != '\n') {
            if(temp != 45) {
                temp -= '0';
            
                stevilo += temp;
                stevilo *= 10;
            } else {
                minus = 1;
            }
        } else {
            if(minus)
                stevilo *= -1;
            return stevilo / 10;
        }
    }
    return 0;
}

void pisanjeIzhoda(int a, int b) {

    long long vsota = a + b;
    long long stMest = 1;
    

    if(vsota < 0) {
        putchar('-');
        vsota *= -1;
    }
    
    while((vsota / stMest) >= 10) {
        stMest *= 10;
    }
    
    while(stMest != 0) {
        long long izpis = vsota / stMest;
        putchar(izpis + '0');
        vsota -= (stMest * izpis);
        stMest /= 10;
    }
    putchar('\n');
}

int main() {

    int a = branjeVhoda();
    int b = branjeVhoda();
    pisanjeIzhoda(a, b);
    return 0;
}