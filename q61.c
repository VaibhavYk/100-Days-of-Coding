// Search for an element in an array using linear search.

#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int arr[] = {10, 50, 30, 70, 80, 60, 20, 90, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    int index = linearSearch(arr, n, key);

    if (index != -1)
        printf("Key Found at Index: %d\n", index);
    else
        printf("Key Not Found\n");

    return 0;
}
