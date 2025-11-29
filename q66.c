// Insert an element in a sorted array at the appropriate position.

#include <stdio.h>
int main() {
    int arr[100], n, num, i, pos = 0;

    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the sorted elements of the array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be inserted: ");
    scanf("%d", &num);

    for(i = 0; i < n; i++) {
        if(arr[i] < num)
            pos++;
        else
            break;
    }

    for(i = n-1; i >= pos; i--) {
        arr[i+1] = arr[i];
    }

    arr[pos] = num;
    n++; 

    printf("Array after insertion: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
