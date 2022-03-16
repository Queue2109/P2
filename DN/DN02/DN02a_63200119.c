#include <stdio.h>
#include <stdbool.h>

int predstavljaDesetisko() {
    char a = getchar();
    bool zacneSeZZnakom = true;
    bool samoEn = true;
    while(a != ' ' && a != '\n') {
        
        if(!zacneSeZZnakom && (a == '+' || a == '-')) {
            a = getchar();
            while(a != ' ' && a != '\n') {
                a = getchar();
            }
            if(a == '\n')
                return -2;
            return 0;
        }
        if(zacneSeZZnakom && (a == '+' || a == '-'))
            zacneSeZZnakom = false;
        char b = a;
        a = getchar();

        if(samoEn && ((a == ' ' || a == '\n') && b != '0')) {
            if(a == '\n')
                return -2;
            return 0;
        }
            
        else 
            samoEn = false;
    }
    if(a == '\n')
        return -1;
    return 1;
}   

int main() {

    int izpisi;
    do {
        int result = predstavljaDesetisko();
        izpisi = result;
        if(result == -2)
            result = 0;
        if(result == -1)
            result = 1;
        putchar(result + '0');
    } while (izpisi != -1 && izpisi != -2);
    putchar('\n');


    return 0;
}