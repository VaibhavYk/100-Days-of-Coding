//Q6 (User Inputs, Operations & Output)
//Write a program to swap two numbers using a third variable.

#include <stdio.h>
int main()
{
    //z - It's the temporary variable
    int x, y, z;
    printf("Enter the first digit: \n");
    scanf("%d", &x);
    printf("Enter the second digit: \n");
    scanf("%d", &y);

    printf("Before swapping: x = %d, y = %d\n", x, y);
    
    z = x;
    x = y;
    y = z;

    printf("After swapping: x = %d, y = %d\n", x, y);
    return 0;
}
