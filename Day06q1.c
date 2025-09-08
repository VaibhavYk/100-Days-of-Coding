//Write a program to input an integer and check whether it is even or odd using if–else.
#include<stdio.h>
int main()
{
    int num;

    printf("Enter the number:\n");
    scanf("%d", &num);

    if(num%2==0)
    printf("The entered number %d is even\n", num);
    else 
    printf("The entered number %d is odd\n", num);

    return 0;
}   
