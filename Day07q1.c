//Write a program to input a year and check whether it is a leap year or not using conditional statements.
#include<stdio.h>
int main()
{
    int y;

    printf("Enter the year:\n");
    scanf("%d", &y);

    if ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0))
    {
        printf("This is a leap year = %d\n", y);
    }
    else
    {
        printf("This is not a leap year = %d\n", y);
    }
    
    return 0;
}
