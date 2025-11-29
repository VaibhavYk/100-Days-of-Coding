#include <stdio.h>
#include <string.h>

int main(){
    char fname[256];
    printf(\"Enter filename: \"); fflush(stdout);
    if(!fgets(fname, sizeof(fname), stdin)) return 0;
    size_t ln = strlen(fname); if(ln>0 && fname[ln-1]=='\\n') fname[ln-1]=0;
    FILE *f = fopen(fname, \"r\"); if(!f){ printf(\"Error: File not found\\n\"); return 0; }
    char line[1024];
    while(fgets(line, sizeof(line), f)) printf(\"%s\", line);
    fclose(f);
    return 0;
}
