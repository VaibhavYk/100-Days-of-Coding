//Write a program to input three numbers and find the largest among them using if–else.

#include<stdio.h>
int main()
{
    int x, y, z;

    printf("Enter the value of x:\n");
    scanf("%d", &x);
    printf("Enter the value of y:\n");
    scanf("%d", &y);
    printf("Enter the value of z:\n");
    scanf("%d", &z);

    if(x >= y && x >= z)
    printf("%d is the greatest of all", x);
    else if(y >= x && y >= z)
    printf("%d is the greatest of all", y);
    else
    printf("%d is the greatest of all", z);

    return 0;
}