// Write a program to implement a basic calculator using switch-case for +, -, *, /, %.

#include <stdio.h>
int main()
{
    int num1, num2;
    float r;
    char op;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Opretion you want to do: ");
    scanf(" %c", &op);

    switch (op)
    {
    case '+':
        r = num1 + num2;
        break;

    case '-':
       r = num1 - num2;
       break;

    case '*':
        r = num1 * num2;
        break;

    case '/':
        if(num2 != 0)
        r = num1 / num2;
        else
        printf("Invalid!");
        break;

    case '%':
        if(num2 != 0)
        r = num1 % num2;
        else
        printf("Invalid!");
        break;
    
    default:
        printf("Invalid Input!");
        break;
    }

    printf("Result: %.2f", r);

    return 0;

}