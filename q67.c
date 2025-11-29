// Insert an element in an array at a given position.

#include <stdio.h>

int main() {
    int arr[100], n, i, pos, element;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter position to insert element (1 to %d): ", n+1);
    scanf("%d", &pos);
    printf("Enter element to insert: ");
    scanf("%d", &element);

    if(pos < 1 || pos > n+1) {
        printf("Invalid position!\n");
        return 1;
    }

    for(i = n; i >= pos; i--) {
        arr[i] = arr[i-1];
    }

    arr[pos-1] = element;
    n++; 

    printf("Array after insertion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
