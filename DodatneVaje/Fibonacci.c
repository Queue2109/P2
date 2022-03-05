#include <stdio.h>

int main() {
    //TO-DO

    long first = 1;
    long second = 2;
    long sum = 2;
    for(long i = 0; second < 4000000; i++) {
        long temp = first + second;
        first = second;
        second = temp;
        if(temp % 2 == 0)
            sum += temp;
    }
    printf("%ld\n", sum);
    return 0;
}

