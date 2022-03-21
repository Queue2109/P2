#include <stdio.h>

int i1, i2, i3;     // te spremenljivke zasedejo nek naslov (npr. 1000),      
char c1, c2, c3;    // ampak nadzor nad tem ima prevajalnik, 
double d1, d2, d3;  // int npr zasede 1000, 1001, 1002 in 1003 - 4 bite

// prevajalnik jih zloži tako, da da na nižje naslove 
// char, potem double in na koncu int
   
int main() {
    
    // %p izpiše v šestnajstiški obliki
    printf("int: %p %p %p\n", &i1, &i2, &i3); 
    printf("char: %p %p %p\n", &c1, &c2, &c3); 
    printf("double: %p %p %p\n", &d1, &d2, &d3); 
   

    
    int *pi;  // pi = kazalec na int
    char *pc; // pc = kazalec na char
    double *pd; // pd = kazalec na double

    pi = &i2; // pi vsebuje naslov spremenljivke i2
    printf("kazalec in i2: %p %p\n", pi, &i2); // sedaj sta ti dve številki enaki
    // načina spreminjanja:
    i2 = 5;
    printf("i2: %d\n", i2);
    *pi = 7;
    printf("pi: %d\n", *pi);
    *pi = 2 * (*pi); 
    printf("pi krat 2: %d\n", *pi);
    // Torej: na pi lahko daš naslov, na *pi pa dejansko vrednost
    

    return 0;
}