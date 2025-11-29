#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    if(scanf(\"%d\", &n)!=1) return 0;
    int *a = malloc(n * sizeof(int));
    long long sum = 0;
    for(int i=0;i<n;i++){ scanf(\"%d\", &a[i]); sum += a[i]; }
    long long expected = (long long)n*(n+1)/2; // numbers 0..n so sum should be 0+...+n
    // But array size is n and contains numbers 0..n with one missing
    // expected - sum gives missing
    int missing = (int)(expected - sum);
    printf(\"%d\n\", missing);
    free(a);
    return 0;
}
