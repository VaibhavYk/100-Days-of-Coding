#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int freq[26] = {0}; 
    int i;
    char result = '\0';
    
    printf("Enter a string: ");
    scanf("%s", str);
    for (i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {  
            freq[str[i] - 'a']++;
            if (freq[str[i] - 'a'] == 2) {
                result = str[i];
                break;
            }
        }
    }

    if (result)
        printf("First repeating lowercase alphabet: %c\n", result);
    else
        printf("No repeating lowercase alphabet found.\n");

    return 0;
}
