#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,k;
    if(scanf(\"%d %d\", &n, &k)!=2) return 0;
    int *a = malloc(n * sizeof(int));
    for(int i=0;i<n;i++) scanf(\"%d\", &a[i]);
    int *q = malloc(n * sizeof(int));
    int qh=0, qt=0;
    for(int i=0;i<n;i++){
        if(a[i] < 0) q[qt++] = i;
        if(i >= k){
            if(qh < qt && q[qh] <= i-k) qh++;
        }
        if(i >= k-1){
            if(qh < qt) printf(\"%d\", a[q[qh]]);
            else printf(\"0\");
            if(i < n-1) printf(\" \");
        }
    }
    printf(\"\\n\");
    free(a); free(q);
    return 0;
}
