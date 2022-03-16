#include <stdio.h>

int konec = 0;

int veljavno() {
    char a = getchar();
    int vrni = 1;
    int sloCezZanko = 1;
    int dolzina = 0;

    if(a == '0') {
        a = getchar();
        
        if(a == 'x') {
            while(a != ' ' && a != '\n') {
                a = getchar();
                if(a != ' ' && a != '\n')
                    dolzina++;
                if(vrni && a != ' ' && a != '\n' && a < '0' || a > '9' && !(a >= 'A' && a <= 'F')) {
                    vrni = 0;
                }
            }
            if(!dolzina)
                vrni = 0;
        } else if(a == 'b') {
            while(a != ' ' && a != '\n') {
                a = getchar();
                if(a == ' ' || a == '\n')
                    dolzina++;
                if(vrni && a != '0' && a != '1' && a != ' ' && a != '\n') {
                    vrni = 0;
                }
            }
            if(!dolzina)
                vrni = 0;
        } else {
            while(a != ' ' && a != '\n') {
                if( vrni && a < '0' || a > '7' && a != ' ' && a != '\n') {
                    vrni = 0;
                }
                
                a = getchar();
            }
        }
    } else if(a >= '1' && a <= '9') {
        while(a != ' ' && a != '\n') {
            a = getchar();
            if(vrni && a < '0' && a > '9' && a != ' ' && a != '\n') {
                vrni = 0;
            }
        }
    } else {
        
        vrni = 0;
        while(a != ' ' && a != '\n') {
            a = getchar();
        }  
    }
    if(a == '\n')
        konec = 1;
    return vrni;
}

int main() {

    while(!konec) {
       int izpisi = veljavno(konec);
       putchar(izpisi + '0');
    }

    return 0;
}