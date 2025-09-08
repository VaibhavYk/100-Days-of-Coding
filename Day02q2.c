//Q4 (User Inputs, Operations & Output)
//Write a program to calculate the area and circumference of a circle given its radius.

#include<stdio.h>
int main()
{
    //R - Radius A - Area C - Circumferense
    float R, A, C;

    printf("Radius of the circle:\n");
    scanf("%f", &R);

    C= 2 * 3.14 * R;
    A= 3.14 * R * R;

    printf("P of C: %.2f\n", C);
    printf("A of C: %.2f\n", A);

    return 0;

}
