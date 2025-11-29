#include <stdio.h>
#include <stdlib.h>

int first_occurrence(int a[], int n, int x){
    int l=0, r=n-1, ans=-1;
    while(l<=r){
        int m = l + (r-l)/2;
        if(a[m]==x){ ans=m; r=m-1; }
        else if(a[m]<x) l=m+1;
        else r=m-1;
    }
    return ans;
}
int last_occurrence(int a[], int n, int x){
    int l=0, r=n-1, ans=-1;
    while(l<=r){
        int m = l + (r-l)/2;
        if(a[m]==x){ ans=m; l=m+1; }
        else if(a[m]<x) l=m+1;
        else r=m-1;
    }
    return ans;
}
int main(){
    int n;
    if(scanf(\"%d\", &n)!=1) return 0;
    int *a = malloc(n * sizeof(int));
    for(int i=0;i<n;i++) scanf(\"%d\", &a[i]);
    int x; scanf(\"%d\", &x);
    int f = first_occurrence(a,n,x);
    int l = last_occurrence(a,n,x);
    if(f==-1) printf(\"-1 -1\n\"); else printf(\"%d %d\n\", f, l);
    free(a);
    return 0;
}
