#include <stdio.h>


int main() {
    
    int n;
    scanf("%d", &n);
    int a[n];
    int b[n + 1];
    b[n] = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &(a[i]));
    } 
    for(int i = 0; i < n; i++) {
        scanf("%d", &(b[i]));
    }

    int indeks = 0;
    int *trenutni = &(b[0]);
    int vrni = 0;
    while(1) {
        trenutni = &(b[indeks]);
        int vseSeUjema = 1;
        for(int i = 0; i < n; i++) { 
            if(*trenutni == 0) {
                trenutni = &(b[0]);
                vrni = i;
            }
            if(*trenutni != a[i]) {
                vseSeUjema = 0;
                break;
            }
            trenutni++;
        }
        if(vseSeUjema) {
            printf("%d\n", vrni);
            break;
        }
        indeks++;
    }
}
