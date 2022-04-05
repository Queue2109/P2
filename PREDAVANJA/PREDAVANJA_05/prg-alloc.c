#include <stdio.h>
#include <stdlib.h>

int a[100]; // med statičnimi podatki

int main() {

    int b[100]; // na skladu
    static int c[100]; // med statičnimi podatki

    // ugotovimo, da so naslovi statičnih podatkov relativno blizu
    printf("&a=%p\n", a);
    printf("&b=%p\n", b);
    printf("&c=%p\n", c);

    int *d; // kazalec je shranjen na skladu
    //če kličem funkcijo malloc povem da naj bodo ti podatki na kopici
    d = (int*) malloc(100 * sizeof(int));
    // torej, 100 intov, na katere kaže d, je na kopici
    if(d == NULL) {
        printf("ERROR\n");
        exit(1);
    }
    for(int i = 0; i < 100; i++) {
        printf("%d ", d[i]); // ni nujno da bo vedno 0
    } 
    printf("\n");
    free(d);

    int *e;
    e = (int*) calloc(100, sizeof(int));
    if(e == NULL) {
        printf("ERROR\n");
        exit(1);
    }
    for(int i = 0; i < 100; i++) {
        printf("%d ", e[i]);
    } 
    printf("\n");
    free(e);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        e[i] = 2 * i;
        printf("%d ", e[i]); // ZELO NEVARNO
    }   
    int m;
    scanf("%d", &m);
   // static int f[m]; -> ne dela, ker prevajalnik ne ve, kako velika mora biti tabela f
    int f[m]; // dela, ker f sodi na sklad


    return 0;
}

// MALLOC - zahteva skupno št bajtov - ne pričakujem samih ničel
// CALLOC - zahteva koliko je podatkov in koliko je velik 1 podatek - pričakujem same ničle
// na kopici imamo veliko prostora za podatke, prav tako med statičnimi podatki
// na kopici so podatki dinamični
