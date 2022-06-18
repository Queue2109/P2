#include <stdio.h>


enum day {
    pon,
    tor, 
    sre,
    cet,
    pet=17,
    sob,
    ned
};

int main() {
    // ce damo petek na 17, so ostali od 17 naprej +1
    // ponavadi ne dolocamo sami, ker ni lepo

    enum day d = pet;
    printf("%d\n", pon);
    printf("%d\n", tor);
    printf("%d\n", sre);
    printf("%d\n", cet);
    printf("%d\n", pet);
    printf("%d\n", sob);
    printf("%d\n", ned);
    printf("%d\n", d);
    return 0;
}