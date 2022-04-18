#include <stdio.h>

// sintaksa za strukturo
struct person {
    char name[100];
    int age;
};

struct person p1 = { "Janez", 20 };
struct person p2 = { "Marko", 21 };
struct person *p3;

void print_person(struct person p) {
    p.age = p.age + 2;
    printf("[%s] %d\n", p.name, p.age);
}

void print_pointer_person(struct person *p) {
    p->age = p->age + 2;
    printf("[%s] %d\n", p->name, p->age);
}

int main() {
    printf("[%s] %d\n", p1.name, p1.age);
    printf("[%s] %d\n", p2.name, p2.age);
    
    p3 = &p1;
    printf("[%s] %d\n", (*p3).name, (*p3).age);
    p3 = &p2;
    // puščica -> je okrajšava za *, () in .
    printf("[%s] %d\n", p3->name, p3->age);
    

    print_person(p1);
    print_person(*p3);
    printf("[%s] %d\n", p1.name, p1.age);
    printf("[%s] %d\n", p3->name, p3->age);

    // lahko vidimo, da ker smo v funkcijo poslali naslov strukture
    // in posodobili starost, se potem izven funkcije tudi ohrani ta posodobljena starost
    print_pointer_person(&p1);
    print_pointer_person(p3);
    printf("[%s] %d\n", p1.name, p1.age);
    printf("[%s] %d\n", p3->name, p3->age);


    return 0;
}