#include <stdio.h>
#include <stdlib.h>

struct predmet {
    int prostornina;
    int cena;
} predmet;

typedef struct _node {
    struct predmet predmet;
    struct _node *next;
} node;

typedef node *list;

void printRek(node *lst) {
    if(lst == NULL) {
        printf("\n");
        return;
    }
    printf("%d %d\n", lst->predmet.prostornina, lst->predmet.cena);
    printRek(lst->next);
}

node *insertElement(struct predmet predmet, node *seznam) {
    if(seznam == NULL) {
        seznam = (node*) malloc(sizeof(node));
        seznam->predmet = predmet;
        seznam->next = NULL;
        return seznam;
    } else {
        node *l = seznam;
        while(l->next != NULL) {
            l = l->next;
        }
        l->next = (node*)malloc(sizeof(node));
        l = l->next;
        l->predmet = predmet;
        l->next = NULL;
        return seznam;
    }
}

node *deleteElement(node *seznam, struct predmet p) {
    list l = seznam;
    while(l->next != NULL) {
        
        if(l->next->predmet.cena == p.cena && l->next->predmet.prostornina == p.prostornina) {
            l->next->next = l->next->next->next;
            l->next->predmet = l->next->next->predmet;
            break;
        }
    }
    return l;
}

node *optimizirajSeznam(node *seznam1, node *seznam2) {
    list l1 = seznam1;
    while(l1->next != NULL) {
        l1 = l1->next;
        list l2 = seznam2;
        while( l2->next != NULL) {
            if(l2->predmet.prostornina == l1->predmet.prostornina) {
                deleteElement(l2, l2->predmet);
            }
        }
    }
}

node *mergeLists(node *l1, node *l2) {
    list l = l1;
    list s = l2;
    while(s != NULL) {
        l = insertElement(s->predmet, l);
        s = s->next;
    }
    return l;
}
 //uredi nekak 
node *uredi(node *l1, node *l2, int V) {
    list a = l1;
    while(a != NULL) {
        list b = l2;
        int cena1 = a->predmet.cena;
        int prostornina1 = a->predmet.prostornina;
        while(b != NULL) {
            int cena2 = b->predmet.cena;
            int prostornina2 = b->predmet.prostornina;
            if(cena1 == cena2 && prostornina1 == prostornina2 || prostornina1 > prostornina2 && cena1 == cena2 || prostornina2 > V || cena1 > cena2 && prostornina1 == prostornina2) {
                l2 = deleteElement(l2, b->predmet);
            } else if(prostornina2 > prostornina1 && cena1 == cena2 || cena2 > cena1 && prostornina1 == prostornina2)  {
                l1 = deleteElement(l1, a->predmet);
            }
            b = b->next;
        }
        a = a->next;
    }
    return mergeLists(l1, l2);
}

void iteracije(struct predmet nahrbtnik[], int n, int V) {
    list l1 = NULL;
    
    struct predmet novPredmet;
    novPredmet.prostornina = 0;
    novPredmet.cena = 0;
    l1 = insertElement(novPredmet, l1);
    for(int i = 0; i <= 1; i++) {
        node *lIter = l1;
        list l2 = NULL;
        do {
            struct predmet novPredmet;
            novPredmet.prostornina = lIter->predmet.prostornina + nahrbtnik[i].prostornina;
            novPredmet.cena = lIter->predmet.cena + nahrbtnik[i].cena;
            l2 = insertElement(novPredmet, l2);
            lIter = lIter->next;
        }
        while(lIter != NULL);
        uredi(l1, l2, V);
        l1 = mergeLists(l1, l2);
        printRek(l1);
        
    }

}

int main() {
    int V, n;
    scanf("%d %d", &V, &n);
    struct predmet nahrbtnik[n];
    for(int i = 0; i < n; i++) {
        struct predmet nov;
        scanf("%d", &nov.prostornina);
        nahrbtnik[i] = nov;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &(nahrbtnik[i].cena));
    }
    for(int i = 0; i < n; i++) {
        printf("%d %d\n", nahrbtnik[i].prostornina, nahrbtnik[i].cena);
    }
    list l = NULL;
    l = insertElement(nahrbtnik[1], l);
    printRek(l);
    iteracije(nahrbtnik, n, V);

    return 0;
}
