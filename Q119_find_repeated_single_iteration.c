#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    if(scanf(\"%d\", &n)!=1) return 0;
    int *a = malloc(n * sizeof(int));
    int maxv = 0;
    for(int i=0;i<n;i++){ scanf(\"%d\", &a[i]); if(a[i] > maxv) maxv = a[i]; }
    // Use visited array sized maxv+1 (may be larger but simple)
    int size = maxv + 1;
    int *vis = calloc(size, sizeof(int));
    int repeated = -1;
    for(int i=0;i<n;i++){
        if(a[i] >= 0 && a[i] < size){
            if(vis[a[i]]){ repeated = a[i]; break; }
            vis[a[i]] = 1;
        }
    }
    printf(\"%d\n\", repeated);
    free(a); free(vis);
    return 0;
}
