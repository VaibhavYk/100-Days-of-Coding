// Delete an element from an array.

#include <stdio.h>

void deleteElement(int arr[], int *n, int key) {
    int i = 0;
    
    while (i < *n && arr[i] != key) 
        i++;

    if (i < *n) {
        for (int j = i; j < *n - 1; j++) {
            arr[j] = arr[j+1];
        }
        (*n)--; 
    } else {
        printf("Element not found\n");
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    deleteElement(arr, &n, key);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
