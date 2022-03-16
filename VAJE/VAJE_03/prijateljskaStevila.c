#include <stdio.h>

int stDeliteljev(int stevilo) {
    int stevec = 0;
    
    for(int i = 1; i <= stevilo / 2; i++) {
        if(stevilo % i == 0)
            stevec += i;
    }
    return stevec;
}

int main() {
    int a; //220

    scanf("%d", &a);
    int prvi = stDeliteljev(a); //284
    int b = prvi;
    if(a == stDeliteljev(prvi)) {
        printf("%d\n", prvi);
    } else {
        printf("NIMA");
    }
    

    
    return 0;
}

