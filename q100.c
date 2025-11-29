// Print all sub-strings of a string.

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j, k;
    printf("Enter a string: ");
    scanf("%s", str); 

    int len = strlen(str);

    printf("All substrings are:\n");
    for (i = 0; i < len; i++) {
        for (j = i; j < len; j++) {
            for (k = i; k <= j; k++) {
                printf("%c", str[k]);
            }
            printf("\n");
        }
    }
    return 0;
}
