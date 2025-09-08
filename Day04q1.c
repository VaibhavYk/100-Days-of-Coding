//Write a program to swap two numbers without using a third variable.
#include <stdio.h>
int main()
{
    int a,b;
    printf("Enter the value of a:\n");
    scanf("%d", &a);
    printf("Enter the value of b:\n");
    scanf("%d", &b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("Value of a=%d\n", a);
    printf("Value of b=%d\n", b);

    return 0;
}
