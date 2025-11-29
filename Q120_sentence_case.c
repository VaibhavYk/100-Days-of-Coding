#include <stdio.h>
#include <string.h>

int main(){
    char s[10005];
    if(!fgets(s, sizeof(s), stdin)) return 0;
    size_t len = strlen(s);
    if(len>0 && s[len-1]=='\n') s[--len] = 0;
    int i=0;
    // find first alphabetic char
    for(; s[i] && !( (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') ); i++);
    if(s[i]){
        // make it uppercase
        if(s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
        // rest lowercase
        for(int j=i+1; s[j]; j++){
            if(s[j] >= 'A' && s[j] <= 'Z') s[j] = s[j] - 'A' + 'a';
        }
    }
    printf(\"%s\n\", s);
    return 0;
}
