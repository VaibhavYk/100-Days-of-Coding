#include <stdio.h>
#include <stdlib.h>

int main(){
    char src[256], dst[256];
    printf(\"Enter source filename: \"); fflush(stdout);
    if(!fgets(src, sizeof(src), stdin)) return 0;
    printf(\"Enter destination filename: \"); fflush(stdout);
    if(!fgets(dst, sizeof(dst), stdin)) return 0;
    size_t ln = strlen(src); if(ln>0 && src[ln-1]=='\\n') src[ln-1]=0;
    ln = strlen(dst); if(ln>0 && dst[ln-1]=='\\n') dst[ln-1]=0;
    FILE *fs = fopen(src, \"r\"); if(!fs){ printf(\"Cannot open %s\\n\", src); return 0; }
    FILE *fd = fopen(dst, \"w\"); if(!fd){ printf(\"Cannot open %s\\n\", dst); fclose(fs); return 0; }
    int ch;
    while((ch=fgetc(fs)) != EOF) fputc(ch, fd);
    fclose(fs); fclose(fd);
    printf(\"Copied successfully\\n\"); return 0;
}
