//Q2 (User Inputs, Operations & Output)
//Write a program to input two numbers and display their sum, difference, product, and quotient.

#include <stdio.h>
int main()
{
    //S-Sum, D-Difference, P-Product, Q-Quotient
    int x, y, S, D, P, Q;
    printf("Enter the first number: \n");
    scanf("%d", &x);
    printf("Enter the second number: \n");
    scanf("%d", &y);

    S = x + y;
    D = x - y;
    P = x * y;
    
    if(y==0){
    printf("Division is undefined\n");
    }
    else{
    Q=x/y;
    printf("Quotient of the numbers: %d\n", Q);
    }


    printf("Sum of the numbers: %d\n", S);
    printf("Difference of the numbers: %d\n", D);
    printf("Products of the numbers: %d\n", P);
    
    
    return 0;
}
