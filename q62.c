// Reverse an array without taking extra space.

#include <stdio.h>

void reverseArray(int arr[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    reverseArray(arr, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
