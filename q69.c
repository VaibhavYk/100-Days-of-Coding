// Find the second largest element in an array.

#include <stdio.h>
#include <limits.h>

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int largest = INT_MIN, second_largest = INT_MIN;

    for (i = 0; i < n; i++) {
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }

    if (second_largest == INT_MIN) {
        printf("The second largest element does not exist.\n");
    } else {
        printf("The second largest element is %d\n", second_largest);
    }

    return 0;
}
