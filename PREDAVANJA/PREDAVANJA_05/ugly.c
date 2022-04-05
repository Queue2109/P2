#include <stdio.h>

int a[10] = {0,1,2,3,4,5,6,7,8,9};

int main() {
    for(int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    int *p = &(a[0]);
    printf("a[0]=%d\n", *p);
    printf("a[1]=%d\n", p[1]);
    printf("p=%p\n", p);

    p++; // povečaj p za velikost podatka, na katerega p kaže
    printf("a[-1]=%d\n", p[-1]); //GRDO
    printf("a[0]=%d\n", *p);
    printf("a[1]=%d\n", p[1]);
    printf("p=%p\n", p);

    p = p + 1; // p = p + 1 * (sizeof (int)) ker je p kazalec na int
    printf("a[-1]=%d\n", p[-1]); 
    printf("a[0]=%d\n", *p);
    printf("a[1]=%d\n", p[1]);
    printf("p=%p\n", p);

    int *b = &(a[0]);
    b[0] = 100;
    b[1] = 200;
    b[2] = 300;
    *(b + 3) = 400; // GRDO
    *(4 + b) = 500; // ZELO GRDO
    5[b] = 600; // ZELO ZELO GRDO
    (2 * 3)[b] = 700; // ZELO ZELO ZELO GRDO

    for(int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");


    return 0;
}