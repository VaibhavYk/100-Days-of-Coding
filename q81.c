// Count characters in a string without using built-in length functions.

#include <stdio.h>

int main() {
    char str[100];
    int i = 0, length = 0;
    
    printf("Enter a string: ");
    scanf("%s", str); 

    while (str[i] != '\0') {
        length++;
        i++;
    }

    printf("Length of input string: %d\n", length);
    return 0;
}
