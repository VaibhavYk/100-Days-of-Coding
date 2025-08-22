//Q3 (User Inputs, Operations & Output)
//Write a program to calculate the area and perimeter of a rectangle given its length and breadth.

#include <stdio.h>
int main()
{
    //l - Length b - Breath P - Perimeter A - Area
    int l, b, P, A;
    printf("Enter the length of the rectangle: \n");
    scanf("%d", &l);
    printf("Enter the breath of the rectangle \n");
    scanf("%d", &b);

    P = 2 * (l + b);
    A = l * b;

    printf("Perimeter of the rectangle: %d\n", P);
    printf("Area of the rectangle: %d\n", A);
    return 0;
}