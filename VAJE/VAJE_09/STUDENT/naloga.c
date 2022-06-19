#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga.h"

/*typedef struct _PO { // par predmet-ocena
    char predmet[4]; // enolična oznaka predmeta
    int ocena; // ocena pri tem predmetu
} PO;

typedef struct _Student { // podatki o študentu
    int vpisna; // vpisna številka
    PO* po; // kazalec na začetek tabele parov predmet-ocena
    int stPO; // število parov predmet-ocena
} Student;
*/
int poisciStudenta(Student** studentje, int stStudentov, int vpisna) {
    for(int i = 0; i < stStudentov; i++) {
        if(studentje[i]->vpisna == vpisna) {
            return i;
        }
    }
    
    return -1;
}

int poisciPO(Student* student, char* predmet) {
    PO *neki = student->po;
    for(int i = 0; i < student->stPO; i++) {
        if(strcmp(neki->predmet, predmet) == 0)
            return i;
        neki++;
    }
    return -1;
}


int dodaj(Student** studentje, int stStudentov, int vpisna, char* predmet, int ocena) {
    // popravite / dopolnite ...
    int j = poisciStudenta(studentje, stStudentov, vpisna);
        if(j != -1) {
            Student *novStudent = studentje[j];
            int k = poisciPO(novStudent, predmet);
            if(k == -1) {
                // to pomeni, da ne obstaja, torej nnaredimo novega.
                PO newPo;
                newPo.ocena = ocena;
                strcpy(newPo.predmet, predmet);
                novStudent->po[novStudent->stPO] = newPo;
                novStudent->stPO++;
            } else {
                novStudent->po[k].ocena = ocena;
            }

        } else {
            Student *novStudent = malloc(sizeof(Student));
            novStudent->vpisna = vpisna;
            novStudent->stPO = 1;
            novStudent->po = (PO*) malloc(10 * sizeof(PO));
            PO new;
            new.ocena = ocena;
            strcpy(new.predmet, predmet);
            novStudent->po[0] = new;
            studentje[stStudentov] = novStudent;
            stStudentov++;
        }

    
    return stStudentov;
}

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}
