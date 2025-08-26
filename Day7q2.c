//Write a program to input a character and check whether it is a vowel or consonant using if–else.
#include <stdio.h>
int main()
{
char input;

printf("Enter the character:\n");
scanf("%c", &input);

if(input== 'a'|| input=='e'|| input=='i'|| input=='o'|| input=='u')
printf("The entered character is a vowel");

else
printf("The entered character is a consonant");

return 0;
}