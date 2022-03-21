#include <stdio.h>

int i1, i2, i3;
int a[3];

int main() {

    printf("int:  %p %p %p\n", &i1, &i2, &i3);
    printf("int:  %p %p %p\n", &(a[0]), &(a[1]), &(a[3]));

    // način shranjevanja tabele na sklad, ki ni optimalen:
    for(int i = 0; i < 3; i++) {
        a[i] = i;
    }
    for(int i = 0; i < 3; i++) {
        printf("a[%d]=%d\n", i, a[i]);
    }
    // boljši način shranjevanja tabele - ker je statična, ni na skladu:
    static int b[1000000];
    for(int i = 0; i < 1000000; i += 100000) {
        b[i] = i;
    }
    for(int i = 0; i < 1000000; i += 100000) {
        printf("b[%d]=%d\n", i, b[i]);
    }

    return 0;
}