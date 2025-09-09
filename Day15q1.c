//Write a program to calculate the factorial of a number.
#include<stdio.h>
int main()
{
    int n, f=1;
    printf("Enter the value of n: \n");
    scanf("%d", &n);

    int i=1;
    while (i<=n){
    f=f*i;
    i = i+1;
    }

    printf("The factorial of the number %d = %d", n, f);
    return 0;
}