#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    if(scanf(\"%d\", &n)!=1) return 0;
    int *a = malloc(n * sizeof(int));
    long long total = 0;
    for(int i=0;i<n;i++){ scanf(\"%d\", &a[i]); total += a[i]; }
    long long left = 0;
    int ans = -1;
    for(int i=0;i<n;i++){
        if(left == total - left - a[i]){ ans = i; break; }
        left += a[i];
    }
    printf(\"%d\n\", ans);
    free(a);
    return 0;
}
