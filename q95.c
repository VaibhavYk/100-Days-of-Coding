// Check if one string is a rotation of another.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int areRotations(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2)
        return 0;
    char *temp = (char *)malloc(sizeof(char) * (len1 * 2 + 1));
    strcpy(temp, str1);
    strcat(temp, str1);
    int result = (strstr(temp, str2) != NULL);

    free(temp); 
    return result;
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    gets(str1);

    printf("Enter second string: ");
    gets(str2);

    if (areRotations(str1, str2))
        printf("Strings are rotations of each other.\n");
    else
        printf("Strings are not rotations of each other.\n");

    return 0;
}



