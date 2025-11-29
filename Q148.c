#include <stdio.h>
#include <string.h>
struct T{char n[20]; int x;};
int main(){ struct T a={"ABC",1},b={"ABC",1};
if(strcmp(a.n,b.n)==0 && a.x==b.x) puts("Same"); else puts("Diff"); }