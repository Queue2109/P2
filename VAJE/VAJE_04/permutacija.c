#include <stdio.h>

int permutacija(int a[], int n) {
    for(int i = 0; i < n; i++) {
        int obstaja = 0;
        for(int j = 0; j < n; j++) {
            if(a[j] == i) {
                obstaja = 1;
                break;
            }
        }
        if(!obstaja)
            return 0;
    }
    return 1;
}

int main() {
    
    int n;
    scanf("%d", &n);
    int a[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &(a[i]));
    }

    if(permutacija(a, n)) {
        printf("DA\n");
    } else {
        printf("NE\n");
    }
    
    return 0;

}