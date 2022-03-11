#include <stdio.h>
#include <stdlib.h>

int main()  {
    int n = 0;
    int c; // v c preberemo po 1 znak naenkrat
    do {
        c = getchar(); // preberi 1 char in ga shrani v c
        switch(c) {
            case '0': 
                n = n * 10 + 0; 
                break;
            case '1': 
                n = n * 10 + 1;
                break;
            case '2':
                n = n * 10 + 2;
                break;
            case '3':
                n = n * 10 + 3;
                break;
            case '4': 
                n = n * 10 + 4; 
                break;
            case '5': 
                n = n * 10 + 5;
                break;
            case '6':
                n = n * 10 + 6;
                break;
            case '7':
                n = n * 10 + 7;
                break;
            case '8': 
                n = n * 10 + 8;
                break;
            case '9':
                n = n * 10 + 9;
                break;
            case '\n':
                break;
            default:
                printf("ERROR \n");
                exit(1);
        
        }
    } while (c != '\n');{
        printf("%d\n", n); 
        return 0;
    }
    
    
}