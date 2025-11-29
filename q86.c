// Check if a string is a palindrome.

#include <stdio.h>

int main() {
    char str[100], rev[100];
    int i, len = 0, flag = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    while (str[len] != '\0') {
        len++;
    }
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            flag = 0;
            break;
        }
    }

    if (flag) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }

    return 0;
}
