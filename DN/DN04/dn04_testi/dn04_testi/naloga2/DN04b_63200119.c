#include <stdio.h>
int n, k;

int enako(int a, int b) {
    if(a + b == k)
        return 1;
    if(a + b > k)
        return -1;
    return 0;
}

int rek2(int a[], int* kazalec, int vrednost, int indeks) {
    if(indeks == n)
        return 0;
    int same = enako(vrednost, a[indeks]);
    if(same == -1)
        return 0;
    return same + rek2(a, kazalec + 1, vrednost, indeks + 1);
}

int rek1(int a[],  int* kazalec, int indeks) {
    if(indeks == n - 1)
        return 0;
    return rek2(a, &(a[indeks + 1]), a[indeks], indeks + 1) + rek1(a, kazalec + 1, indeks + 1);
}

int main() {

    
    scanf("%d %d", &n, &k);
    int a[n];
    
    for(int i = 1; i < n; i++) {
        scanf("%d ", &(a[i]));
    }
    
    printf("%d\n", rek1(a, &(a[0]), 0));
    return 0;
}