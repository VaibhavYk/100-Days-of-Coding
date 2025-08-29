//Write a program to find the roots of a quadratic equation and categorize them.
#include<stdio.h>
#include<math.h>
int main()
{
    float x1,x2,a,b,c,d;

    printf("Enter the value of a: ");
    scanf("%f", &a);
    printf("Enter the value of b: ");
    scanf("%f", &b);
    printf("Enter the value of c: ");
    scanf("%f", &c);

    x1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
    x2 = (-b - sqrt(b*b - 4*a*c))/(2*a);

    d = b*b - 4*a*c;       //to determine the nature of the roots

    if(d>0)
    printf("There are 2 distinct real roots and the roots are:%.2f,%.2f", x1, x2);
    else{
        if(d==0)
        printf("Roots are real and equal and that is: %.2f", x1);
        else 
        printf("Roots are complex");
    }

    return 0;
}