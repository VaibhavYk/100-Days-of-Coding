// Print initials of a name with the surname displayed in full.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printInitials(char name[]) {
    int len = strlen(name);
    char temp[50];
    int i, j = 0;
    while (name[0] == ' ') memmove(name, name + 1, strlen(name));
    while (name[strlen(name) - 1] == ' ') name[strlen(name) - 1] = '\0';

    for (i = 0; i < len; i++) {
        if (name[i] != ' ')
            temp[j++] = name[i];
        else {
            temp[j] = '\0';
            printf("%c. ", toupper(temp[0]));
            j = 0;
        }
    }
    temp[j] = '\0';
    printf("%c", toupper(temp[0]));
    for (i = 1; i < j; i++)
        printf("%c", tolower(temp[i]));
}

int main() {
    char name[100];
    printf("Enter your full name: ");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0'; 

    printf("Formatted name: ");
    printInitials(name);
    return 0;
}
