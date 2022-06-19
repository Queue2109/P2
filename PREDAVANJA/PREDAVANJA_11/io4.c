 #include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

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
    int c = 0;
    while((c = fgetc(inp))!= 0) {
        if(('0' <= c) && ('9' >= c)) {
            fputc(c, out);
            fflush(out);
            printf("=> %c\n", c);
        }
    }
}
// i gave up with posnetki
