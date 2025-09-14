// Write a program to reverse a given number.

int main()
{
   int num, reversed = 0, temp, digit;
    printf("Enter a number: ");
    scanf("%d", &num);

    for (temp = num; temp != 0; temp /= 10)
    {
        digit = temp % 10;
        reversed = reversed * 10 + digit;
    }

    printf("Reversed number: %d\n", reversed);
    return 0;
}