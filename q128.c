#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char ch;
    int vowels = 0, consonants = 0;
    fp = fopen("input.txt", "r");   
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        return 1;
    }
    while ((ch = fgetc(fp)) != EOF) {
        ch = tolower(ch);
        if (ch >= 'a' && ch <= 'z') {   
            if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                vowels++;
            else
                consonants++;
        }
    }
    fclose(fp);
    printf("Total Vowels     : %d\n", vowels);
    printf("Total Consonants : %d\n", consonants);
    return 0;
}