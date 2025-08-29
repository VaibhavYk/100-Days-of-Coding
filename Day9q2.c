//Write a program to assign grades based on a percentage input.
#include<stdio.h>
int main()
{
    int per;

    printf("Enter the percentage: ");
    scanf("%d", &per);

    if(per>=90 && per<=100)
    printf("You've got an A grade");
    else if(per>=80 && per<=89)
    printf("You've got a B grade");
    else if(per>=70 && per<=79)
    printf("You've got a C grade");
    else if(per>=60 && per<=69)
    printf("You've got a D grade");
    else if(per>=51 && per<=59)
    printf("You've got an E grade");
    else
    printf("You've got a F grade");

    return 0;
    

}