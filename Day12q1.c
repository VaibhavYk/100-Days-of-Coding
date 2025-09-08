//Q23: Write a program to calculate library fine based on late days as follows: 
//First 5 days late: ₹2/day 
//Next 5 days late: ₹4/day 
//Next 20 days days late: ₹6/day 
//More than 30 days: Membership Cancelled.
#include <stdio.h>
int main()
{
    int x, f1, f2, f3;
    printf("Enter the number of days for which the book is being returned late: \n");
    scanf("%d", &x);

    f1= x*2;
    f2= 10 + (x-5)*4;
    f3= 30 + (x-10)*6;

    if(x<=5)
    printf("The fine is Rs%d", f1);
    else if(x>5 && x<=10)
    printf("The fine is Rs%d", f2);
    else if(x>10 && x<=30)
    printf("The fine is Rs%d", f3);
    else
    printf("Membership cancelled");

    return 0;
}


