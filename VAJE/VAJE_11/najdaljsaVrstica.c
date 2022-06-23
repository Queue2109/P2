#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *in;
    FILE *out;
    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");
    if(in == NULL) {
        printf("Error!\n");
        exit(1);
    }

    int lineNum = 1;
    char *line = malloc((1000010) + sizeof(char));
    size_t len = 0;
    __ssize_t read;
    int najdaljsaVrstica = 0;
    char *vrstica;
    
    while((read = getline(&line, &len, in)) != -1) {
        if(read > najdaljsaVrstica) {
            najdaljsaVrstica = read;
            
            strcpy(vrstica, line);
            free(line);
        }
    }

    fprintf(out, vrstica, "%s");

    fclose(in);
    fclose(out);

}
// oboje dela
/*

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ZGORNJA_MEJA_DOLZINE 1000000

int main(int argc, char** argv) {
    // odpremo vhodno in izhodno datoteko
    FILE* vhod = fopen(argv[1], "rt");
    FILE* izhod = fopen(argv[2], "wt");

    // preberemo prvo vrstico
    char* vrstica = malloc((ZGORNJA_MEJA_DOLZINE + 10) * sizeof(char));

    int najDolzina = 0;   // doslej najve"cja dol"zina vrstice
    char* najVrstica = NULL;   // doslej najdalj"sa vrstica (kazalec na za"cetek niza)

    // beremo vrstice, dokler ne prispemo do konca datoteke
    while (fgets(vrstica, ZGORNJA_MEJA_DOLZINE + 1, vhod) != NULL) {
        int dolzina = strlen(vrstica);  // dol"zina pravkar prebrane vrstice

        if (dolzina > najDolzina) {
            // vrstica je dalj"sa od doslej najdalj"se, zato posodobimo
            // spremenljivko <najDolzina>, skopiramo vrstico in postavimo
            // kazalec <najVrstica> na za"cetek kopije
            najDolzina = dolzina;
            free(najVrstica);
            najVrstica = malloc((dolzina + 1) * sizeof(char));
            strcpy(najVrstica, vrstica);
        }
    }

    // izpi"semo rezultat, po"cistimo pomnilnik in zapremo datoteki

    free(vrstica);

    fprintf(izhod, "%s", najVrstica);
    free(najVrstica);

    fclose(vhod);
    fclose(izhod);

    return 0;
}
*/