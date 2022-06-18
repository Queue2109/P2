// če želimo imeti strukturo, 
// kjer uporabimo ali en ali drug podatek
#include <stdio.h>


/*struct i_or_f {
    int i;
    float f;
};*/

union i_or_f {
    int i; 
    float f;
};

void print (union i_or_f u) {
    printf("union function: i=%d f=%f\n", u.i, u.f);
}

int main() {
    union i_or_f x;
    printf("sizeof=%lu\n", sizeof(union i_or_f));
    //int in float zasedeta enaka naslova, saj vedno izberemo 
    //samo en element iz uniona
    printf("%p(%p, %p)\n", &x, &(x.i), &(x.f));

    x.i = 0;
    printf("i=%d f=%f\n", x.i, x.f);

    // tu se spremenita int in float, saj sta na istem naslovu
    x.f = 3.14;
    printf("i=%d f=%f\n", x.i, x.f);
    print(x);
    print((union i_or_f) 1234);
    print((union i_or_f)(float) 2.71);
    print((union i_or_f)2.71f);
    return 0;
}