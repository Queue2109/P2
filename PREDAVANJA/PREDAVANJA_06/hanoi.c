#include <stdio.h>

int num_moves; // 1 3 7 15 31 -> 2^n - 1

void hanoi1(char c1, char c2, char c3) {
    printf("%c --> %c\n", c1, c2);
}
void hanoi2(char c1, char c2, char c3) {

    printf("%c --> %c\n", c1, c2); // hanoi1(c1, c3, c2)
    printf("%c --> %c\n", c1, c3); // hanoi1(c1,c2,c3)
    printf("%c --> %c\n", c2, c3); // hanoi1(c2,c1,c3)
}

void hanoi3(char c1, char c2, char c3) {

    printf("%c --> %c\n", c1, c3); // hanoi1(c1,c3,c2)
    printf("%c --> %c\n", c1, c2); // hanoi1(c1,c3,c2) hanoi2(c1,c3,c2)
    printf("%c --> %c\n", c3, c2); // hanoi1(c3,c1,c2)

    printf("%c --> %c\n", c1, c3); // hanoi1(c1,c2,c3)
    
    printf("%c --> %c\n", c2, c1); // hanoi(c2,c3,c1)
    printf("%c --> %c\n", c2, c3); // hanoi(c2,c1,c3) hanoi2(c2,c1,c3)
    printf("%c --> %c\n", c1, c3); // hanoi(c1,c2,c3)

}

//NA SPLOŠNO
void hanoi(int n, char c1, char c2, char c3) {
    if(n==1) {
        printf("%c --> %c\n", c1, c3);
        num_moves++;
    } else {
        hanoi(n - 1, c1, c3, c2); // vse obrocke razen najvecjega umaknem na stolp B
        hanoi(1, c1, c2, c3); // na zacetnem je samo najvecji, prestavim ga na koncni stolp
        hanoi(n - 1, c2, c1, c3); // vse obrocke razen najvecjega prestavim na koncni stolp
    }
}


int main()  {
    num_moves = 0;
    hanoi(4, 'A', 'B', 'C');
    printf("%d\n", num_moves);
    return 0;
}

/*
ZGODBA O HANOISKIH STOLPIH:
imamo 3 stolpe, na stolpu A je n obročev
cilj je, da spravimo na stolp C vse obročke v istem vrstnem redu, 
pri čemer v 1 potezi lahko premaknemo le 1 obroč
*/