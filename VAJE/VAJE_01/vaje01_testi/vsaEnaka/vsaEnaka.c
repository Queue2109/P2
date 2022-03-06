#include <stdio.h>

int main() {
    int n = getchar() - '0';
    int theSame = 1;
    getchar();
    int first = getchar() - '0';
    for(int i = 0; i < n - 1; i++) {
        getchar();
        int temporary = getchar() - '0';
        if(temporary != first) {
            theSame = 0;
            break;
        }
    }
    if(theSame == 0) {
        putchar(0 + '0');
    } else
        putchar(1 + '0');
    return 0;
}