#include <stdio.h>

// to nam ni všeč, saj bi radi naredili funkcijo, 
// ki sprejme tabelo katerekoli velikosti 
void narediFiksno(int a[100000]) {
    for(int i = 0; i < 100000; i++) {
        a[i] = i;
    }
}

// funkciji dodamo še en parameter, ki hrani dolzino tabele 
void narediPoljubno(int a[], int n) {
    for(int i = 0; i < n; i++) {
        a[i] = i;
    }
}

void narediPoljubnoPointer(int *a, int n) {
    for(int i = 0; i < n; i++) {
        a[i] = i;
    }
}

// malo odkomentiraj in spreminjaj izpisovanje tabele itd

int main() {
    static int a[100000];
  //  narediFiksno(a);
   // narediPoljubno(a, 100000);
    // deluje tudi tako:
   // narediPoljubno(&(a[0]), 100000);
    narediPoljubnoPointer(&(a[10]), 100);
    for(int i = 0; i < 200; i += 1) {
        printf("a[%d]=%d\n", i, a[i]);
    }
    return 0;

}