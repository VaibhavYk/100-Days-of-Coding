// Count spaces, digits, and special characters in a string.

#include <stdio.h>
#include <ctype.h>  

int main() {
    char str[1000];
    int spaceCount = 0, digitCount = 0, specialCount = 0;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); 
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            spaceCount++;
        } else if (isdigit(str[i])) {
            digitCount++;
        } else if (!isalnum(str[i])) {
            specialCount++;
        }
    }
    
    printf("Spaces: %d\n", spaceCount);
    printf("Digits: %d\n", digitCount);
    printf("Special characters: %d\n", specialCount);
    
    return 0;
}
