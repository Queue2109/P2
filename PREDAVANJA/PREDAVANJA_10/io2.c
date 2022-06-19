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

    // vzames en char iz datoteke
   
    while(1) {
        int i;
        int res = fscanf(inp, "%d", &i);
        if(errno != 0) {
            fprintf(stderr, "ERROR: errno!\n");
            if(errno == ERANGE) {
                fprintf(stderr, "errno = ERANGE\n");
            }
            break;
        }

        printf("res=%d\n", res);
        if(res == EOF)
            break;
        if(res == 0) {
            fprintf(stderr, "ERROR: read!\n");
            break;
        }
        fprintf(out, "READ*2: %d\n", i * 2);
        
    }



    fclose(inp);
    fclose(out);
    
    return 0;
}
