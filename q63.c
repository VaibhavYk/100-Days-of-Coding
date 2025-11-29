// Merge two arrays.

#include <stdio.h>

int main() {
    int arr1[50], arr2[50], merged[100];
    int size1, size2, i, k;

    printf("Enter size of first array: ");
    scanf("%d", &size1);
    printf("Enter elements of first array: ");
    for(i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
        merged[i] = arr1[i]; 
    }

    k = i; 
    printf("Enter size of second array: "); 
    scanf("%d", &size2);
    printf("Enter elements of second array: ");
    for(i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
        merged[k] = arr2[i]; 
        k++;
    }

           
        printf("Merged array: ");
        for(i = 0; i < k; i++)
        printf("%d", merged[i]);

    return 0;
}
