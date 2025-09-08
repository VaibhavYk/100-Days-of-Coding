//Q5 (User Inputs, Operations & Output)
//Write a program to convert temperature from Celsius to Fahrenheit.

#include<stdio.h>

int main ()
{
    float Cels, Fahr;

    printf("Temperature in Celsius: ");
    scanf("%f", &Cels);

    Fahr = (Cels * 9 / 5) + 32;

    printf("Temperature in Fahrenheit: %.2f", Fahr);

    return 0;
}
