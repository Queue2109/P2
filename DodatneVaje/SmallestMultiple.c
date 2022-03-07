#include <stdio.h>

int divisible(int stevilo) {
    for(int i = 20; i >= 10; i--) {
        if(stevilo % i != 0)
            return 0;
    }
    return 1; 
}

int main() {
    int stevilo = 20;
    while(1) {
        if(divisible(stevilo)) {
            printf("%d\n", stevilo);
            return 0;
        }
        else 
            stevilo += 20;
    }
}