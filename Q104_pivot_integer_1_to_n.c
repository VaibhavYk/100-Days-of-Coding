#include <stdio.h>
#include <math.h>

int main(){
    long long n;
    if(scanf(\"%lld\", &n)!=1) return 0;
    long double total = (long double)n*(n+1)/2.0L;
    long long x = (long long) floorl(sqrtl(total) + 0.5L);
    if((long double)x * (long double)x == total) printf(\"%lld\n\", x);
    else printf(\"-1\n\");
    return 0;
}
