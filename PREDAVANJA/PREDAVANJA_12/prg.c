#include <stdio.h>

// definiramo, da je zunanju, saj pravo vrednost dobimo v prg.c
extern int num_nodes;

void lists();

int main(int argc, char *argv[]) {
    printf("Hello world\n");
    lists();
    printf("num nodes: %d\n", num_nodes);
    return 0;
}

// prevajanje programa v 2 fazah
// gcc -c prg.c
// se naredi datoteka prg.o
// gcc -o prg prg.o
// se naredi datoteka prg
// ./prg


// povežemo 2 programa: najprej prvega prevedeš ločeno,gcc -c prg.c
// potem drugega prevedeš ločeno, na koncu gcc -c lists.c
// pa oba skupaj povežeš gcc -o prg prg.o lists.o
// poženeš ./prg