// Perform diagonal traversal of a matrix.

#include <stdio.h>

#define ROW 4
#define COL 4

void diagonalTraversal(int mat[ROW][COL]) {
    for (int k = 0; k < COL; k++) {
        int i = 0, j = k;
        while (i < ROW && j >= 0) {
            printf("%d ", mat[i][j]);
            i++;
            j--;
        }
    }
    for (int k = 1; k < ROW; k++) {
        int i = k, j = COL - 1;
        while (i < ROW && j >= 0) {
            printf("%d ", mat[i][j]);
            i++;
            j--;
        }
    }
}

int main() {
    int mat[ROW][COL] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };
    printf("Diagonal Traversal of matrix is:\n");
    diagonalTraversal(mat);
    return 0;
}
