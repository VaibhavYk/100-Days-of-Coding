#include <stdio.h>
#include <string.h>

int main(){
    char s[10005];
    if(!fgets(s, sizeof(s), stdin)) return 0;
    size_t len = strlen(s);
    if(len>0 && s[len-1]=='\n') s[--len] = 0;
    int last[256];
    for(int i=0;i<256;i++) last[i] = -1;
    int res = 0, start = 0;
    for(int i=0;i<len;i++){
        unsigned char c = s[i];
        if(last[c] >= start) start = last[c] + 1;
        last[c] = i;
        if(i - start + 1 > res) res = i - start + 1;
    }
    printf(\"%d\n\", res);
    return 0;
}
