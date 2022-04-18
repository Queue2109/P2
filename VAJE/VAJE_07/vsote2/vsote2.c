#include <stdio.h>
#include <stdlib.h>

    // stNacinov(n - k, k) -> pogledamo na koliko nacinov se razdeli tisti preostanek
    // stNacinov(n, k - 1) -> podproblem

    void print(int *p, int *a) {
        for(int i = 0; i < a - p; i++) {
            if(i > 0) {
                printf(" + ");
            }
            printf("%d", p[i]);
        }
        printf("\n");
    }

    long stNacinov(int n, int k, int *p, int *a) {
        if(n < k) {
            k = n;
        }

        if(k == 0) {
            if(n == 0) {
                print(p, a);
                return 1;
            }
            return 0;
        }

        p[a - p] = k;
        long x = stNacinov(n - k, k, p, a + 1);
        long y = stNacinov(n, k - 1, p, a);
        return x + y;
    }

    int main() {

        int n;
        int k;
        scanf("%d%d", &n, &k);
        int *p = (int*) malloc(n * sizeof(int));
        stNacinov(n, k, p, p);
        free(p);

        return 0;
    }













/*#include <stdio.h>
int n, k;
int vsotaKonec = 0;
void vsota(int st, int sum, int prvic) {
    if(sum > n)
        return;
    if (prvic == 0)
        printf(" + %d", st);
    else if (prvic == 1)
        printf("%d", k);
    if(sum == n) {
        printf("\n");
        return;
    }
    
    for(int i = st; i >= 1; i--) {
        if(prvic == 2 && (sum + i) < n)
            printf("%d", k);
        vsota(i, sum + i, 0);
        prvic = 2;
    }
}

int main() {
    
    scanf("%d %d", &n, &k);
    for(int j = k; j >= 1; j--) {
        k = j;
        vsota(j, j, 1);
    }
    return 0;

}*/