//Write a program to classify a triangle as Equilateral, Isosceles, or Scalene based on its side lengths.
#include<stdio.h>
int main()
{
    int a,b,c;

    printf("Enter the value of first side: ");
    scanf("%d", &a);
    printf("Enter the value of second side: ");
    scanf("%d", &b);
    printf("Enter the value of third side: ");
    scanf("%d", &c);

    if(a==b && b==c && c==a)
    printf("The triangle is an equilateral triangle");
    else if(a==b || b==c || c==a)
    printf("The triangle is an isoceles triangle");
    else
    printf("The triangle is a scalene triangle");

    return 0;
}    
    
