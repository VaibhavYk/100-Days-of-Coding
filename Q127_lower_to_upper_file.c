#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fin = fopen(\"input.txt\", \"r\");
    if(!fin){ printf(\"Cannot open input.txt\\n\"); return 0; }
    FILE *fout = fopen(\"output.txt\", \"w\");
    if(!fout){ printf(\"Cannot open output.txt\\n\"); fclose(fin); return 0; }
    int c;
    while((c = fgetc(fin)) != EOF){
        if(c >= 'a' && c <= 'z') c = c - 'a' + 'A';
        fputc(c, fout);
    }
    fclose(fin); fclose(fout);
    printf(\"Converted and saved to output.txt\\n\");
    return 0;
}
