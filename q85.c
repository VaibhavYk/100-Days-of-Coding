// Reverse a string.

#include <stdio.h>

int main() {
    char str[100], temp;
    int i, j;

    printf("Enter a string: ");
    scanf("%s", str); 
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    printf("Reversed string: %s\n", str);

    return 0;
}
