// Add two matrices.

#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int mat1[MAX_SIZE][MAX_SIZE];
    int mat2[MAX_SIZE][MAX_SIZE];
    int sum[MAX_SIZE][MAX_SIZE];
    int row, col, i, j;

    printf("Enter the number of rows (between 1 and %d): ", MAX_SIZE);
    scanf("%d", &row);
    printf("Enter the number of columns (between 1 and %d): ", MAX_SIZE);
    scanf("%d", &col);
    printf("\nEnter elements of 1st matrix:\n");
    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            printf("Enter element mat1_%d%d: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("\nEnter elements of 2nd matrix:\n");
    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            printf("Enter element mat2_%d%d: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }
    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    printf("\nSum of two matrices:\n");
    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
