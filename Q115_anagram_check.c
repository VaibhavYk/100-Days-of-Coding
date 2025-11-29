#include <stdio.h>
#include <string.h>

int main(){
    char s[10005], t[10005];
    if(!fgets(s, sizeof(s), stdin)) return 0;
    if(!fgets(t, sizeof(t), stdin)) return 0;
    size_t ls = strlen(s), lt = strlen(t);
    if(ls>0 && s[ls-1]=='\n') s[--ls]=0;
    if(lt>0 && t[lt-1]=='\n') t[--lt]=0;
    if(ls != lt){ printf(\"Not Anagram\n\"); return 0; }
    int cnt[26] = {0};
    for(size_t i=0;i<ls;i++) cnt[s[i]-'a']++;
    for(size_t i=0;i<lt;i++) cnt[t[i]-'a']--;
    for(int i=0;i<26;i++) if(cnt[i]!=0){ printf(\"Not Anagram\n\"); return 0; }
    printf(\"Anagram\n\"); return 0;
}
