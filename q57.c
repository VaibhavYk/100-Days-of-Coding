// Find the sum of array elements.

#include <stdio.h>
int main() {
    int n, i, sum = 0;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < n; i++)
        sum += arr[i];

    printf("Sum of the array is: %d\n", sum);
    return 0;
}
 
