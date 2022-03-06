#include <stdio.h>

int main() {
    int n = getchar() - '0';
    getchar();
    int najvecje = 0;
    int drugoNajvecje = 0;

    for(int i = 0; i < n; i++) {
        int temporary = getchar() - '0';
        if(temporary >= najvecje) {
            drugoNajvecje = najvecje;
            najvecje = temporary;
        } else if(temporary > drugoNajvecje)
            drugoNajvecje = temporary;

        getchar();

    }
    putchar(drugoNajvecje + '0');
    return 0;
}