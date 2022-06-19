#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * MEMO[ix][zeDodaliLiho][vNah]: "ze izra"cunana vrednost funkcije
 * poisci(..., ix, zeDodaliLiho, vNah) oziroma 0, "ce te vrednosti "se nismo
 * izra"cunali
 */
int MEMO[1001][2][1001];

/*
 * Vrne ceno optimalnega nahrbtnika s (preostalo) prostornino vNah, pri "cemer
 * lahko vanj dodajamo predmete z indeksi od vklju"cno ix naprej (predmete z
 * ni"zjimi indeksi smo obravnavali na prej"snjih nivojih rekurzije), poleg
 * tega pa moramo upo"stevati tudi parameter zeDodaliLiho.  "Ce ima ta
 * parameter vrednost true, potem smo v nahrbtnik "ze dodali predmet z liho
 * prostornino (in takega predmeta ne smemo ve"c dodati), sicer pa ga "se
 * nismo (zato tak predmet "se lahko dodamo).
 *
 * stPredmetov: "stevilo vseh predmetov
 * prostornine: prostornine vseh predmetov
 * cene: cene vseh predmetov
 * ix: indeks trenutno obravnavanega predmeta
 * zeDodaliLiho: true natanko v primeru, "ce nahrbtnik "ze vsebuje predmet z
 *               liho prostornino
 * vNah: preostala prostornina v nahrbtniku
 */

int poisci(int stPredmetov, int* prostornine, int* cene, int ix, bool zeDodaliLiho, int vNah) {
    // nimamo ve"c predmetov, ki bi jih "se lahko dodali v nahrbtnik, zato
    // cena takega nahrbtnika (oz. mno"zice predmetov) zna"sa 0
    if (ix == stPredmetov) {
        return 0;
    }

    // "ce smo vrednost funkcije poisci(..., ix, zeDodaliLiho, vNah) "ze
    // izra"cunali, jo kar vrnemo
    if (MEMO[ix][zeDodaliLiho][vNah] > 0) {
        return MEMO[ix][zeDodaliLiho][vNah];
    }

    // mo"znost 1: predmeta z indeksom ix ne dodamo v nahrbtnik
    int najCena = poisci(stPredmetov, prostornine, cene, ix + 1, zeDodaliLiho, vNah);

    bool lihaProstornina = (prostornine[ix] % 2 == 1);

    // mo"znost 2: predmet z indeksom ix dodamo v nahrbtnik, "ce sta
    // izpolnjena slede"ca pogoja:
    // -- v nahrbtniku je dovolj prostora za ta predmet
    // -- predmet ima sodo prostornino ali pa nahrbtnik "se ne vsebuje
    //    predmeta z liho prostornino

    if (prostornine[ix] <= vNah && (!lihaProstornina || !zeDodaliLiho)) {
        // mo"znost 2: predmet z indeksom ix dodamo v nahrbtnik
        int c = cene[ix] + poisci(stPredmetov, prostornine, cene, ix + 1,
                                  zeDodaliLiho || lihaProstornina, vNah - prostornine[ix]);

        // izberemo bolj"so izmed obeh mo"znosti
        if (c > najCena) {
            najCena = c;
        }
    }

    // memoiziramo
    MEMO[ix][zeDodaliLiho][vNah] = najCena;

    return najCena;
}

int main() {
    int vNah;
    scanf("%d", &vNah);

    int stPredmetov;
    scanf("%d", &stPredmetov);

    int* prostornine = malloc(stPredmetov * sizeof(int));
    for (int i = 0;  i < stPredmetov;  i++) {
        scanf("%d", &prostornine[i]);
    }

    int* cene = malloc(stPredmetov * sizeof(int));
    for (int i = 0;  i < stPredmetov;  i++) {
        scanf("%d", &cene[i]);
    }

    int najCena = poisci(stPredmetov, prostornine, cene, 0, false, vNah);
    printf("%d\n", najCena);

    free(prostornine);
    free(cene);

    return 0;
}