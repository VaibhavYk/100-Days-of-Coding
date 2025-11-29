// Check if two strings are anagrams of each other.

#include <stdio.h>
#include <string.h>
int checkAnagram(char *str1, char *str2) {
    int count1[256] = {0};
    int count2[256] = {0};
    int i;
    if (strlen(str1) != strlen(str2))
        return 0;

    for (i = 0; str1[i] != '\0'; i++)
        count1[(unsigned char)str1[i]]++;

    for (i = 0; str2[i] != '\0'; i++)
        count2[(unsigned char)str2[i]]++;
    for (i = 0; i < 256; i++) {
        if (count1[i] != count2[i])
            return 0;
    }

    return 1;
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    if (checkAnagram(str1, str2))
        printf("The two strings are anagrams.\n");
    else
        printf("The two strings are not anagrams.\n");

    return 0;
    
    
}
