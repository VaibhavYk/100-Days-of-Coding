//Write a program to input an integer and check whether it is positive, negative or zero using nested if–else.
#include<stdio.h>
int main()
{
    int num;
    printf("Enter the number:\n");
    scanf("%d", &num);

    if (num==0)
    printf("The number is zero");
    else{
        if (num>0)
        printf("The number is positive");

        else
        printf("The number is negative");
    }
    return 0;
}