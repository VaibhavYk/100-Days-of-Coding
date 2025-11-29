#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *f = fopen(\"input.txt\", \"r\");
    if(!f){ printf(\"Cannot open input.txt\\n\"); return 0; }
    int c;
    long long chars = 0, words = 0, lines = 0;
    int in_word = 0;
    while((c = fgetc(f)) != EOF){
        chars++;
        if(c == '\\n') lines++;
        if(c==' ' || c=='\\n' || c=='\\t') in_word = 0;
        else if(!in_word){ in_word = 1; words++; }
    }
    fclose(f);
    printf(\"Characters: %lld\\nWords: %lld\\nLines: %lld\\n\", chars, words, lines);
    return 0;
}
