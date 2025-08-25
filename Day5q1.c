//Write a program to calculate simple and compound interest for given principal, rate, and time.
#include <stdio.h>
#include<math.h>
int main()
{
    float p ,r, t, si, ci;
    printf("Enter the principal:\n");
    scanf("%f", &p);
    printf("Enter the rate:\n");
    scanf("%f", &r);
    printf("Enter the time:\n");
    scanf("%f", &t);

    si= p*r*t/100;
    ci= p*(pow((1+r/100),t)-1);

    printf("Simple interest=%.2f\n", si);
    printf("Compound interest=%.2f\n", ci);

    return 0;
}
