#include <stdio.h>
#include <stdlib.h>

// ce je spremenljivka definirana zunaj funkcije 
// je avtomatsko staticna in ni treba da pisemo static
// ce je definirana znotraj funkcije in hočemo da je 
// statična, jo označimo s static

int x;
static int y; // posebej zahtevamo, da je statična - ni potrebno

// REGISTER
int reg(int n) {
    register int f = 1; // prevajalniku rečemo, naj da f v register
    for(int i = 1; i <= n; i++) {
        f = f * i;
    }
    return f;
}

// KOPICA - HEAP
void heap() {
    // kako spravimo neeko stvar na kopico?
    int *d; // kazalec d je shranjen na skladu

    // malloc = memory allocation, spodaj za 100 intov. 
    // naslov, ki ga dobim nazaj je naslov na int
    d = (int*) malloc(100 * sizeof(int)); // d je kazalec na kopico,
                                          // kjer je 100 intov

    for(int i = 0; i < 100; i++) {
        printf("%d ", d[i]);
    }
    printf("\n");
    free(d); // sprostimo prostor na pomnilniku - POMEMBNO
}

int main() {
    int ax, a, b; //a, b, ax so na skladu
    static int by; //x, y, by so statične spremenljivke in niso na skladu 
    
    /*Za te definirane staticne spremenljivke velja,  
    da so ves cas izvajanja programa zive*/

    reg(3);
    heap();
    
    return 0;
}