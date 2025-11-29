#include <stdio.h>
#include <stdlib.h>

int cmp(const void *p, const void *q){ return (*(int*)p) - (*(int*)q); }

int main(){
    int n,k;
    if(scanf(\"%d %d\", &n, &k)!=2) return 0;
    int *a = malloc(n * sizeof(int));
    for(int i=0;i<n;i++) scanf(\"%d\", &a[i]);
    if(k < 1 || k > n){ printf(\"-1\n\"); free(a); return 0; }
    qsort(a, n, sizeof(int), cmp);
    printf(\"%d\n\", a[k-1]);
    free(a);
    return 0;
}
