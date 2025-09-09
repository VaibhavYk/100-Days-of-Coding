//Write a program to print the product of even numbers from 1 to n.
#include<stdio.h>
int main()
{
    int n, product=1;
    printf("Enter the value of n: \n");
    scanf("%d", &n);

    
        int i=2;
        while(i<=n){
            product= product*i;
            i = i+2;
            }

            printf("Product of even numbers from 1 to n= %d", product);
    
        return 0;
}