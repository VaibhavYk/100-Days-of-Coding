// Find the longest word in a sentence.

#include <stdio.h>
#include <string.h>

int main() {
    char str[200], longest[200];
    int i = 0, j = 0, maxLen = 0, currLen = 0, start = 0, maxStart = 0;

    printf("Enter a sentence: ");
    gets(str);  

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\n') {
            if (currLen == 0)
                start = i; 
            currLen++;
        } else {
            if (currLen > maxLen) {
                maxLen = currLen;
                maxStart = start;
            }
            currLen = 0;
        }
        i++;
    }
    if (currLen > maxLen) {
        maxLen = currLen;
        maxStart = start;
    }
    for (i = 0; i < maxLen; i++)
        longest[i] = str[maxStart + i];
    longest[i] = '\0';

    printf("\nLongest word: %s", longest);
    printf("\nLength: %d\n", maxLen);

    return 0;
}
