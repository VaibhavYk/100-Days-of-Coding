#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    if(scanf(\"%d\", &n)!=1) return 0;
    int *a = malloc(n * sizeof(int));
    for(int i=0;i<n;i++) scanf(\"%d\", &a[i]);
    long long *left = malloc(n * sizeof(long long));
    long long *right = malloc(n * sizeof(long long));
    left[0] = 1;
    for(int i=1;i<n;i++) left[i] = left[i-1] * a[i-1];
    right[n-1] = 1;
    for(int i=n-2;i>=0;i--) right[i] = right[i+1] * a[i+1];
    for(int i=0;i<n;i++){
        if(i) printf(\" \");
        printf(\"%lld\", left[i] * right[i]);
    }
    printf(\"\\n\");
    free(a); free(left); free(right);
    return 0;
}
