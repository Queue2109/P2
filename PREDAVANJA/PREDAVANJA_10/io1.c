#include <stdio.h>
#include <string.h>

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
    int ch;
    do {
        ch = fgetc(inp);
        if(ch != EOF) fputc(ch, out);
        printf("%c", ch);
    } while(ch != EOF);


    fclose(inp);
    fclose(out);
    return 0;
}