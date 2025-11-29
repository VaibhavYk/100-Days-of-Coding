// Read and print elements of a one-dimensional array.

#include <stdio.h>

int main() {
    int n, i;
    printf("Input the size of the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Input %d elements (integer type) in the array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Elements in the array are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
