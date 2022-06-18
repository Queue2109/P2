// ustvarili bomo ciklično strukturo, ki bo imela dvosmerne kazalce,
// v sebi pa bo hranila ali int ali float

#include <stdio.h>
#include <stdlib.h>

enum typ {
    t_int, t_float
};

union val {
    int v_int;
    float v_float;
};


typedef struct node {
    enum typ type;
    union val value;
    struct node *next;
    struct node *prev;
}node;

node *insert_next(enum typ t, union val v, node *n) {
    if(n == NULL) {
        n = (node*)malloc (sizeof(node));
        n->type = t;
        n->value = v;
        n->next = n; 
        n->prev = n;
        return n;
    } else {
        node *newNode = (node*)malloc (sizeof(node));
        newNode->type = t;
        newNode->value = v;
        newNode->next = n->next;
        newNode->prev = n;
        newNode->next->prev = newNode;
        newNode->prev->next = newNode;
        return n;
    }
}

node *insert_prev(enum typ t, union val v, node *n) {
    node *temp = n->prev;
    temp = insert_next(t, v, temp);
    return n;
}

void print(node *first, node *last) {
    if(first == NULL) return;
    if (last == NULL) {
        last = first->prev;
    }
    switch (first->type) {
        case t_int:
            printf("%d ", first->value.v_int);
            break;
        case t_float:
            printf("%f ", first->value.v_float);
            break;
    }
    if(first != last)
        print(first->next, last);
    else printf("\n");
}

int main() {

    node *n = NULL;
    n = insert_next(t_int, (union val)3, n);
    print(n, NULL);
    n = insert_next(t_float, (union val)3.14f, n);
    print(n, NULL);
    n = insert_next(t_int, (union val)12, n);
    print(n, NULL);
    n = insert_prev(t_int, (union val) 4, n);
    print(n, NULL);
    return 0;
}