// Print the initials of a name.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[100];
    int i;

    printf("Enter your full name: ");
    fgets(name, sizeof(name), stdin); 
    

    if (isalpha(name[0]))
        printf("%c", toupper(name[0]));
    for (i = 1; name[i] != '\0'; i++) {
        if (name[i - 1] == ' ' && isalpha(name[i]))
            printf(".%c", toupper(name[i]));
    }

    printf("\n");
    return 0;
}


