//Write a program to input a character and check whether it is an uppercase alphabet, lowercase alphabet, digit, or special character.

#include<stdio.h>
int main()
{
    char input;
    
    printf("Enter the character:\n");
    scanf("%c", &input);

    if(input>='A' && input<='Z')
    printf("The character %c is uppercase", input);
    else if(input>='a' && input<='z')
    printf("The character %c is lowercase", input);
    else if(input>='0' && input<='9')
    printf("The character %c is a digit", input);
    else
    printf("The entered character %c is a special character", input);

    return 0;
}