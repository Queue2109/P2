#include <stdio.h>
#include <stdlib.h>
int a[3][2] = {{0,1}, {2,3}, {4,5}};

int sum (int b[3][2]) {
    int s = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            s = s + b[i][j];
        }
    }
    return s;
}

int sum1(int b[][2], int n) {
    int s = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            s = s + b[i][j];
        }
    }
    return s;
}

/*int sum2(int b[][], int m, int n) {
    int s = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            s = s + b[i][j];
        }
    }
    return s;

}*/ // to ne bo delalo - multidimenzionalna tabela 
// mora imeti podane vse parametre, razen prvega

int sum2(int **b, int n, int m) {
    int s = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            s = s + b[i][j];
        }
    }
    return s;
}

int main() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // izpisemo 2d array kot 1d array
    int *p = &(a[0][0]);
    for(int i = 0; i < 6; i++) {
        printf("%d ", p[i]); 
    }
    printf("\n");

    printf("sum=%d\n", sum(a));
    printf("sum1=%d\n", sum1(a, 3));
    
    int **b;
    int n = 3;
    int m = 2;
    int k = 1;
    b = (int**) malloc (n * sizeof(int*)); // tabela kazalcev
    for(int i = 0; i < n; i++) {
        b[i] = (int*) malloc(n * sizeof(int)); // dejanske tabelice
        for(int j = 0; j < m; j++) {
            b[i][j] = k;
            k++; 
        }
    }
    //MALLOC (end)
    printf("sum=%d\n", sum2(b, n, m));
    //FREE (begin)
    for(int i = 0; i < n; i++) {
        free(b[i]); //sprostim tabelice
    }
    free(b); //sprostim kazalce na tabele
    //FREE (end)

    return 0;
}

/*
int *a;
a[5] = *(a + 5)
    int* 5 * sizeof(int)
    a vsebuje naslov 
    a + 5*sizeof(int) je naslov
    *(a + 5) ker je na naslovu a[5], oz. na naslovu a + 5*sizeof(int)

int **b;
    b je kazalec na kazalec na int
    *b je kazalec na int
    **b je int

b[1][2]
b[1] = *(b + 1) je začetek tabele
b[1][2] = *(*(b + 1) + 2)


b = naslov tabele kazalcev na int
b + 1 = naslov 2. elementa v tabeli kazalcev na int
*(b + 1) = vrednost 2. elementa v tabeli kazalcev na int = b[1]
*(b + 1) + 2 = naslov 3. elementa v tabeli intov
*(*(b + 1) + 2) = vrednost 3. elementa v tabeli intov

*/