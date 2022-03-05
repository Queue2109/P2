#include <stdio.h>
//ta način je grd, ampak je za vajo:)
int combs(int n);

int main() {
    printf("%d\n", combs(4));
}

int inner(int i, int j, int k) {
     printf("%d %d %d\n", i, j, k);
     return 1; //vrne stevilo izpisanih kombinacij
}

int loop3(int n, int i, int j, int k) {
    if(k == n) {
        return 0; //vrne st izpisanih kombinacij, ampak tule ne izpišemo več, zato damo 0
    } else {
        return inner(i, j, k) + loop3(n, i, j, k + 1);
    }
}

int loop2(int n, int i, int j) {
    if(j == n)
        return 0;
    else  
        return loop3(n, i, j, 0) + loop2(n, i, j + 1);
}

int loop1(int n, int i) {
    if(i == n)
        return 0;
    else 
        return loop2(n, i, 0) + loop1(n, i + 1);
}

int combs(int n) {
    return loop1(n, 0);
}