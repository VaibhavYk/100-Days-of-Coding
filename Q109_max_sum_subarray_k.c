#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,k;
    if(scanf(\"%d %d\", &n, &k)!=2) return 0;
    int *a = malloc(n * sizeof(int));
    for(int i=0;i<n;i++) scanf(\"%d\", &a[i]);
    if(k > n){ printf(\"0\n\"); free(a); return 0; }
    long long sum = 0;
    for(int i=0;i<k;i++) sum += a[i];
    long long best = sum;
    for(int i=k;i<n;i++){ sum += a[i]; sum -= a[i-k]; if(sum > best) best = sum; }
    printf(\"%lld\n\", best);
    free(a);
    return 0;
}
