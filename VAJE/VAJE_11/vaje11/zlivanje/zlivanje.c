#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DOLZINA_IMENA 100


int main() {
    
    int stDatotek;
    scanf("%d", &stDatotek);
    FILE **datoteke = malloc(stDatotek * sizeof(FILE*));
    char *imeDatoteke = malloc(sizeof(char) * (MAX_DOLZINA_IMENA + 1));
    
    for(int i = 0; i < stDatotek; i++) {
        scanf("%s", imeDatoteke);
        datoteke[i] = fopen(imeDatoteke, "r");
    }
    scanf("%s", imeDatoteke);
    FILE *out = fopen(imeDatoteke, "w");

    bool *bool_blok = malloc(sizeof(bool) * stDatotek);
    int *blok = malloc(stDatotek * sizeof(int));
    int stKoncanih = 0;

    for(int i = 0; i < stDatotek; i++) {
        if(fscanf(datoteke[i], "%d", &blok[i]) < 1) {
            printf("if: %d ", blok[i]);
            bool_blok[i] = true;
            stKoncanih++;
        }
        printf("%d ", blok[i]);
    }
    
    while (stKoncanih < stDatotek) {
        int indeksMin = -1;
        for (int i = 0; i < stDatotek; i++) {
            if (!bool_blok[i]) {
                if (indeksMin == -1 || blok[i] < blok[indeksMin]) {
                    indeksMin = i;
                }
            }
        }

        for(int i = 0; i < stDatotek; i++) {
            printf("%p ", bool_blok);
        }

        fprintf(out, "%d\n", blok[indeksMin]);
        int novo;
        if (fscanf(datoteke[indeksMin], "%d", &novo) < 1) {
            bool_blok[indeksMin] = true;
            stKoncanih++;
        }
        else
            blok[indeksMin] = novo;
    }

    for (int i = 0; i < stDatotek; i++) {
        fclose(datoteke[i]);
    }

    free(imeDatoteke);
    free(datoteke);
    fclose(out);
    free(blok);
    free(bool_blok);

    return 0;

}