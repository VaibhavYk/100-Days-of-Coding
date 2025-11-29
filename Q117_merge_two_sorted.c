#include <stdio.h>
#include <stdlib.h>

int main(){
    int m,n;
    if(scanf(\"%d %d\", &m, &n)!=2) return 0;
    int *a = malloc(m * sizeof(int));
    int *b = malloc(n * sizeof(int));
    for(int i=0;i<m;i++) scanf(\"%d\", &a[i]);
    for(int i=0;i<n;i++) scanf(\"%d\", &b[i]);
    int *c = malloc((m+n) * sizeof(int));
    int i=0,j=0,k=0;
    while(i<m && j<n) c[k++] = (a[i] <= b[j]) ? a[i++] : b[j++];
    while(i<m) c[k++] = a[i++];
    while(j<n) c[k++] = b[j++];
    for(int p=0;p<k;p++){ if(p) printf(\" \"); printf(\"%d\", c[p]); }
    printf(\"\\n\");
    free(a); free(b); free(c);
    return 0;
}
