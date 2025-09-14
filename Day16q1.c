// Write a program to take a number as input and print its equivalent binary representation.

#include <stdio.h>
int main()
{
    int num, temp, binary[32], i = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("Binary representation: 0\n");
        return 0;
    }

    temp = num;
    // Divide the number by 2 and store the remainder (bit) in an array
    while (temp > 0) {
        binary[i] = temp % 2;
        temp = temp / 2;
        i++;
    }
    printf("Binary representation: ");
    // Print the binary array in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
    return 0;
}