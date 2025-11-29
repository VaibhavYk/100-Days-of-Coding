#include <stdio.h>
#include <string.h>

int main(){
    char fname[256];
    printf(\"Enter filename to append: \"); fflush(stdout);
    if(!fgets(fname, sizeof(fname), stdin)) return 0;
    size_t ln = strlen(fname); if(ln>0 && fname[ln-1]=='\\n') fname[ln-1]=0;
    FILE *f = fopen(fname, \"a\"); if(!f){ printf(\"Cannot open %s\\n\", fname); return 0; }
    char line[1024];
    printf(\"Enter text to append: \"); fflush(stdout);
    if(!fgets(line, sizeof(line), stdin)) line[0]=0;
    fprintf(f, \"%s\", line);
    fclose(f);
    printf(\"Appended\\n\"); return 0;
}
