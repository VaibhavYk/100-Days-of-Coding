#include <stdio.h>
#include <limits.h>

int main(){
    int n;
    if(scanf(\"%d\", &n)!=1) return 0;
    long long max_ending = 0, max_so_far = LLONG_MIN;
    for(int i=0;i<n;i++){
        int x; scanf(\"%d\", &x);
        if(i==0){ max_ending = x; max_so_far = x; }
        else{
            if(max_ending + x > x) max_ending = max_ending + x; else max_ending = x;
            if(max_ending > max_so_far) max_so_far = max_ending;
        }
    }
    printf(\"%lld\n\", max_so_far);
    return 0;
}
