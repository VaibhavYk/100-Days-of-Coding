//Q24: Write a program to calculate electricity bill based on units consumed with these rates: 
//First 100 units at ₹5/unit 
//Next 100 units at ₹7/unit 
//Next 100 units at ₹10/unit 
//Above at ₹12/unit
#include <stdio.h>
int main()
{
    int x, f1, f2, f3, f4;
    printf("Enter the units of electricity consumed: \n");
    scanf("%d", &x);

    f1= x*5;
    f2= 500 + (x-100)*7;
    f3= 1200 + (x-200)*10;
    f4= 2200 + (x-300)*12;

    if(x<=100)
    printf("The electricity bill is Rs%d", f1);
    else if(x>100 && x<=200)
    printf("The electricity bill is Rs%d", f2);
    else if(x>200 && x<=300)
    printf("The electricity bill is Rs%d", f3);
    else
    printf("The electricity bill is Rs%d", f4);

    return 0;
}


