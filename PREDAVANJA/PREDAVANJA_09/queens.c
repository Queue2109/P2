#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// postavim 8 kraljic na šahovnico, pri čemer se nobeni kraljici ne napadata

// argc ti pove število argumentov, argv pa dejanske argumente
// prvi argument... indeks 0 je ime programa, indeks 1 je prvi argument

int queens(int q, int num_queens, int board[]) {
    if(q == num_queens) {
        for(int r = 0; r < num_queens; r++) {
            for(int c = 0; c < q; c++) {
                if(board[c] == r) 
                    printf("Q");
                else   
                    printf(".");
            }
            printf("\n");
        }
        printf("\n");
        return 1;
    }
    int solutions = 0;
    // rows
    for(int r = 0; r < num_queens; r++) {
        bool conflict = false;
        // columns
        for(int c = 0; c < q; c++) {
            // preverimo vrstico
            conflict = conflict || (board[c] == r);
            // preverimo 1 diagonalo
            conflict = conflict || (r - board[c] == q - c);
            // preverimo 2 diagonalo
            conflict = conflict || (board[c] - r == q - c);
        }
        if(!conflict) {
            board[q] = r;
            solutions += queens (q + 1, num_queens, board);
        }
    }
    return solutions;
}

int main(int argc, char *argv[]) {

    int num_queens;
    if(argc != 2) exit (1);

    sscanf(argv[1], "%d", &num_queens);
    int *board = (int*) malloc (num_queens * sizeof(int));
    printf("# SOLUTIONS: %d\n", queens (0, num_queens, board));
    free(board);

    return 0;
}
 