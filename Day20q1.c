// Write a program to find the product of odd digits of a number.

#include <stdio.h>
int main() 
{
    int num, digit, product = 1, foundOdd = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    while (num != 0) 
    {
        digit = num % 10;
        if (digit % 2 != 0) 
        { 
            product *= digit;
            foundOdd = 1;
        }
        num /= 10;
    }

    if (foundOdd)
        printf("Product of odd digits is %d\n", product);
    else
        printf("No odd digits found in the number.\n");

    return 0;
}
