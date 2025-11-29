#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,k;
    if(scanf(\"%d %d\", &n, &k)!=2) return 0;
    int *a = malloc(n * sizeof(int));
    for(int i=0;i<n;i++) scanf(\"%d\", &a[i]);
    if(k > n){ free(a); return 0; }
    int *dq = malloc(n * sizeof(int));
    int head=0, tail=0;
    for(int i=0;i<n;i++){
        while(head<tail && dq[head] <= i-k) head++;
        while(head<tail && a[dq[tail-1]] <= a[i]) tail--;
        dq[tail++] = i;
        if(i >= k-1){
            if(i > k-1) printf(\" \");
            printf(\"%d\", a[dq[head]]);
        }
    }
    printf(\"\\n\");
    free(a); free(dq);
    return 0;
}
