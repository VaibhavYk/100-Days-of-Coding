// Search in a sorted array using binary search.

#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid; 
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}

int main() {
    int n, key;
    printf("Enter number of elements:\n");
    scanf("%d", &n);

    int arr[100];
    printf("Enter %d sorted integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter value to search:\n");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);
    if (result != -1)
        printf("%d found at index %d\n", key, result);
    else
        printf("%d not found in the array\n", key);

    return 0;
}
