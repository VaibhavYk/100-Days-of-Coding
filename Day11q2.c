//Write a program to find profit or loss percentage given cost price and selling price.
#include <stdio.h>
int main()
{
    float sp, cp, p, l;
    printf("Enter the cost price of the item: \n");
    scanf("%f", &cp);
    printf("Enter the selling price of the item: \n");
    scanf("%f", &sp);

    p= ((sp - cp)*100)/cp;
    l= ((cp - sp)*100)/cp;

    if(sp>cp)
    printf("We have earned a profit and the profit percentage is %.2f", p);
    else if(cp>sp)
    printf("We have suffered a loss and the loss percentage is %.2f", l);
    else
    printf("No profit or loss");

    return 0;
    
}