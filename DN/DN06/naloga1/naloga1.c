
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

char* zdruzi(char** nizi, char* locilo) {
    
    char* kopija = malloc(1000 * sizeof(char));
    char** potuj = nizi;
    char* izhod = &(kopija[0]);
    while(*potuj != 0) {
        char* crke = *potuj;
        while(*crke != 0) {
            char crka = *crke;
            *kopija = crka;
            crke++;
            kopija++;
        }
        
        **potuj++;
        if(*potuj != 0) {
            char* backupLocilo = &(locilo[0]);
            while (*backupLocilo != 0) {
                *kopija = *backupLocilo;
                backupLocilo++;
                kopija++;
            }
            
        }
    }
    

    return izhod;
}


int main() {
}
