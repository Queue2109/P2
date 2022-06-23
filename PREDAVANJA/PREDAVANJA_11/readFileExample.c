#include <stdio.h>
#include <stdlib.h>


int main() {
    
    FILE *in;
    char *ime = malloc(20 * sizeof(char));
    scanf("%s", ime);
    in = fopen(ime, "r");
    char *vrstica = malloc(150 * sizeof(char));
    
    while(!feof(in)) {
        fgets(vrstica, 150, in);
        puts(vrstica);
    }
    fclose(in);
    free(vrstica);
    free(ime);
    return  0;

    
}