// Write a program to check if a number is prime.

#include <stdio.h>
#include <math.h>

int main() 
{
    int a, i, b = 0;

    printf("Enter a number: ");
    scanf("%d", &a);

    if (a <= 1) {
        printf("%d is not a prime number.\n", a);
    } else {
        for (i = 2; i <= sqrt(a); i++) {
            if (a % i == 0) {
                b = 1;
                break;
            }
        }
        if (b == 0)
            printf("%d is a prime number.\n", a);
        else
            printf("%d is not a prime number.\n", a);
    }
    return 0;
}
