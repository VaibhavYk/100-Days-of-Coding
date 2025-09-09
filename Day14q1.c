// Write a program to print the sum of the first n odd numbers.

#include <stdio.h>
int main()
{
    int n, z, sum;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for(z = 1; z <= 2 * n; z += 2 )
    {
        sum += z;
    }

    printf("Sum of the first %d odd numbers is: %d", n, sum);
    return 0;


}