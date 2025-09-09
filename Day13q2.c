//Write a program to print numbers from 1 to n.

#include <stdio.h>
int main()
{
    int n, z;
    printf("Enter the number to which you want the count of: ");
    scanf("%d", &n);
    for(z = 1; z <= n; z++)
    printf("%d\n", z);
    return 0;
}