 #include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define N 1000
int main(int argc, char *argv[]) {

    if(argc < 3)
        return 1;

    FILE *inp;
    FILE *out;
    
    if(strcmp(argv[1], "-") == 0) {
        inp = stdin;
    } else {
        inp = fopen(argv[1], "r"); 
        if(inp == NULL){
            printf("ERROR inp\n");
            return 1;
        }
    }   
    
    // za pisanje
    if(strcmp(argv[2], "-") == 0) {
        out = stdout;
    } else {
        out = fopen(argv[2], "w");
        if(out == NULL) {
            printf("ERROR out\n");
            fprintf(stderr, "ERROR out!\n");
            return 1;
        } 
    }
    printf("OD 0 do %d:\n", N);
    #include "work.c"
    fclose(inp);
    fclose(out);
}