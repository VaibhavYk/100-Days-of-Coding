// Rotate an array to the right by k positions.

#include <stdio.h>

void rotateArr(int arr[], int n, int k)
{
    for(int i = 0; i < k; i++)
    {
        int last = arr[n - 1];
        for(int j = n - 1; j > 0; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[0] = last;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    rotateArr(arr, n, k);

    printf("Array after rotating right by %d positions:\n", k);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
