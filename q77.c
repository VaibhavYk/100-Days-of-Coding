// Check if the elements on the diagonal of a matrix are distinct.

#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int main() {
    int n, matrix[MAX][MAX];
    bool distinct = true;

    printf("Enter the size of the square matrix (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("Size exceeds max limit.\n");
        return 1;
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][i] == matrix[j][j]) {
                distinct = false;
                break;
            }
        }
        if (!distinct) break;
    }

    if (distinct)
        printf("All diagonal elements are distinct.\n");
    else
        printf("Diagonal elements are not distinct.\n");

    return 0;
}
