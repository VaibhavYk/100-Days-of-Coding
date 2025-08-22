//Q1 (User Inputs, Operations & Output)
//Write a program to input two numbers and display their sum.

#include <stdio.h>
int main()
{
    //x - N1, y - N2, S - Sum
    int x, y, S;
    printf("Enter the first number:\n");
    scanf("%d", &x);
    printf("Enter the second number:\n");
    scanf("%d", &y);

    S = x + y;

    printf("Sum of numbers = %d\n", S);
    return 0;
}

