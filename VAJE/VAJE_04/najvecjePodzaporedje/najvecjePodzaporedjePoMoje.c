#include <stdio.h>

int najvecjePodzaporedje(int a[], int n, int start) {
    
    int novaVsota = 0;
    int vrniNajvecjo = -1000;
    for(int j = start; j < n; j++) {
        novaVsota += a[j];
        if(novaVsota > vrniNajvecjo)
            vrniNajvecjo = novaVsota;
    }

    return vrniNajvecjo;
}

int main() {

    int n;
    scanf("%d", &n);
    int a[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &(a[i]));
    }

    int najvecjiSestevek = -1000;

    for(int i = 0; i < n; i++) {
        int vsota = najvecjePodzaporedje(a, n, i);
        if(vsota > najvecjiSestevek)
            najvecjiSestevek = vsota;
    }
    printf("%d\n", najvecjiSestevek);
    return 0;

}