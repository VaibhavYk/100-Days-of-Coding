#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *f = fopen(\"info.txt\", \"r\");
    if(!f){ printf(\"Cannot open info.txt\\n\"); return 0; }
    char line[1024];
    while(fgets(line, sizeof(line), f)){
        printf(\"%s\", line);
    }
    fclose(f);
    return 0;
}
