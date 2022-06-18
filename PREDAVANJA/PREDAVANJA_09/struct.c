#include <stdio.h>

struct s {
    int i;
    float f;
} s1;

int main() {
    printf("sizeof=%lu\n", sizeof(struct s));
    printf("%p(%p, %p)\n", &s1, &(s1.i), &(s1.f));
    return 0;
}