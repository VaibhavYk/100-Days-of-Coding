// Convert a lowercase string to uppercase without using built-in functions.

#include <stdio.h>

int main() {
    char str[100];
    int i;

    printf("Enter a lowercase string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
    }

    printf("Uppercase string: %s", str);

    return 0;
}
