#include <stdio.h>
#include <stdbool.h>

int board[9][9] =
{
    {5,3,0, 0,7,0, 0,0,0},
    {6,0,0, 1,9,5, 0,0,0},
    {0,9,8, 0,0,0, 0,6,0},

    {8,0,0, 0,6,0, 0,0,3},
    {4,0,0, 8,0,3, 0,0,1},
    {7,0,0, 0,2,0, 0,0,6},

    {0,6,0, 8,0,0, 2,8,0},
    {0,0,0, 4,1,9, 0,0,5},
    {0,0,0, 0,8,0, 0,7,9}
};

void izpis() {
     for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

void sudoku(int x, int y) {
    //če je mesto že polno, se prestavimo naprej

    //izpis
    if(x==9) {
        izpis();
        return;
    }

    if(board[x][y] != 0) {
        if(y == 8) {
            sudoku(x + 1, 0);
        } else {
            sudoku(x, y + 1);
        }
        return;
    } 
    for(int n = 1; n <=9; n++) {
        bool n_found = false;
        //a je v tem stolpcu že ta številka
        for(int j = 0; j < 9; j++) {
            n_found = n_found || (board[x][j] == n);
        }
        //v tej vrstici
        for(int j = 0; j < 9; j++) {
            n_found = n_found || (board[j][y] == n);
        }
        //v kvadrantu
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                n_found = n_found || (board[3 * (x / 3) + i][3 * (y / 3) + j] == n);
            }
        }
        if(! n_found) {
            board[x][y] = n;
            if(y == 8)
                sudoku (x + 1, 0);
            else 
                sudoku(x, y + 1);
            board[x][y] = 0;
        }
    }

}

int main() {
    sudoku(0, 0);
    return 0;
}

// ideja je, da preverjamo s poskušanjem
// rekurzija poskrbi za lažje izvajanje