#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//fscanf, fprintf, errno

int main(int argc, char *argv[]) {

    if(argc < 3)
        return 1;

    //inp je kazalec na tip FILE
    FILE *inp;
    FILE *out;
    // r pomeni da jo odpre za branje 
    // DATOTEKO ODPREMO
    if(strcmp(argv[1], "-") == 0) {
        inp = stdin;
    } else {
        inp = fopen(argv[1], "r"); 
        if(inp == NULL){
            printf("ERROR inp!\n");
            return 1;
        }
    }

    // za pisanje
    if(strcmp(argv[2], "-") == 0) {
        out = stdout;
    } else {
        out = fopen(argv[2], "w");
        if(out == NULL) {
            fprintf(stderr, "ERROR out!\n");
            return 1;
        } 
    }
    static unsigned char block[1024];
    // s kazalcem int pokažemo na naslov začetka bloka
    int *iblock = ((int*)(&block[0]));
    int len = 0;

    while(1) {
        // vrne stevilo prebranih podatkov
        int n = fread(block, sizeof(unsigned char), 1024, inp); 
       
        //preberemo datoteko z kot zaporedje intov
        for(int i = 0; i < 256; i++) {
            printf("%d ", block[i]);
        }
        printf("\n");
        len = len + n;

        if(n < 1024) 
            break;
    }
    printf("LENGTH: %d\n", len);
    

    fclose(inp);
    fclose(out);
    
    return 0;
}
