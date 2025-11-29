#include <stdio.h>
#include <stdlib.h>

int main(){
    char name[256];
    int age;
    printf(\"Enter name: \"); fflush(stdout);
    if(!fgets(name, sizeof(name), stdin)) return 0;
    size_t ln = strlen(name); if(ln>0 && name[ln-1]=='\\n') name[ln-1]=0;
    printf(\"Enter age: \"); fflush(stdout);
    if(scanf(\"%d\", &age)!=1) return 0;
    FILE *f = fopen(\"info.txt\", \"w\");
    if(!f){ printf(\"Error opening file\\n\"); return 0; }
    fprintf(f, \"Name: %s\\nAge: %d\\n\", name, age);
    fclose(f);
    printf(\"Data saved to info.txt\\n\");
    return 0;
}
