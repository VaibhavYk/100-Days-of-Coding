// Write a program to check if a number is a palindrome.

#include <stdio.h>

int main()
{
    int num, original, reversed = 0, remainder;

    // Input number
    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;

    // Reverse the number
    while (num > 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num = num / 10;
    }

    // Check palindrome
    if (original == reversed) {
        printf("%d is a Palindrome number.\n", original);
    } else {
        printf("%d is NOT a Palindrome number.\n", original);
    }

    return 0;
}
