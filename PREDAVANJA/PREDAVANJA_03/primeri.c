#include <stdio.h>

int main() {
// CELOŠTEVILSKI TIPI

    int i = 17; //desetiški zapis
    int j = 0x11; // šestnajstiški zapis
    int k = 021; // osmiški zapis

    char c = 65; // izpiše A
    char a = 'A';
    printf("Desetiško: %d\nŠestnajstiško:  %d\nOsmiško: %d\n\nChar s številom: %d\nChar z narekovaji: %d\n", i, j, k, c, a);
    

    if(('A' <= c) && (c <= 'F'))
        printf("Super, tako se dela\n");
    if((65 <= c) && (c <= 71))
        printf("Fuj, ne programirat tko!\n");

    // TIPI ZA ZAPIS S PLAVAJOČO VEJICO

    float x = 0.1;
    while(x != 1.0)
        x = x + 0.1; //ta zanka se bo zaciklala, saj 0.1 ni točno 0.1, 
                     // je neko realno število, ki je blizu temu
    
    float y = 1.0 / 3.0; // v y se zapiše 0.3333... 
    while(y != 1.0)
        y += y; //zopet se zacikla, ker če seštevaš 0.333 nikoli ne dobiš celega števila
    
    

   return 0;
}