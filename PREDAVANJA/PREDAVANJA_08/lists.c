#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int value;
    struct _node *next;
} node;     // node je struktura

typedef node *list; // list je kazalec na strukture

node *inserta(int n, node *lst) { // vstavim vrednost na zacetek seznama
    node *l = (node*) malloc(sizeof(node));
    l->value = n;
    l->next = lst;
    return l;
}

node *insertz_itrSKazalci(int n, node *lst) { // vstavimo na konec seznama
    // z dvojnimi kazalci
    node **l = &lst;
    while(*l != NULL) {
        l = &((*l)->next);
    }
    (*l) = (node*) malloc (sizeof(node));
    (*l)->value = n;
    (*l)->next = NULL;
    return lst;
}


node *insertz_itr(int n, node *lst) { // vstavimo na konec seznama
    if(lst == NULL) {
        lst = (node*) malloc(sizeof(node));
        lst->value = n;
        lst->next = NULL;
        return lst;
    } else {
        node *l = lst;
        while(l->next != NULL) {
            l = l->next;
        }
        l->next = (node*)malloc(sizeof(node));
        l = l->next;
        l->value = n;
        l->next = NULL;
        return lst;
    }
}

node *insertZ_rek(int n, node *lst) {
    if(lst == NULL) {
        lst = (node*) malloc(sizeof(node));
        lst->value = n;
        lst->next = NULL;
        return lst;
    } else {
        lst->next = insertZ_rek(n, lst->next);
        return lst;
    }
}

void printRek(node *lst) {
    if(lst == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", lst->value);
    printRek(lst->next);
}

void printListIterative(node *lst) {
    node *l = lst;
    while(l != NULL) {
        printf("%d ", l->value);
        l = l->next;
    }
    printf("\n");
}

void deleteAll(node *lst) {
    if(lst == NULL)
        return;

    // nujno v tem vrstnem redu:
    deleteAll(lst->next); // sprostimo rep
    free(lst); // sprostimo glavo
    
}

int main() {

    list l = NULL;
    l = inserta(2, l);
    l = inserta(3, l);
    l = inserta(4, l);
    printRek(l);
    l = insertz_itr(5, l);
    l = insertz_itr(7, l);
    l = insertZ_rek(9, l);
    printRek(l);
    deleteAll(l);
    return 0;
}
