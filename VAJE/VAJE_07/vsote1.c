#include <stdio.h>
int n, k;
int vsotaKonec = 0;
void vsota(int st, int sum) {
    if(sum > n)
        return;
    if(sum == n) {
        vsotaKonec++;
    }
    
    for(int i = st; i >= 1; i--) {
        vsota(i, sum + i);
    }
}

int main() {
    
    scanf("%d %d", &n, &k);
    for(int j = k; j >= 1; j--) {
        vsota(j, j);
    }
    printf("%d\n", vsotaKonec);
    return 0;

}