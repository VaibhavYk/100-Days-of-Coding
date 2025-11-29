#include <stdio.h>
struct S{char n[20]; int x;};
void print(struct S a){ printf("%s %d",a.n,a.x); }
int main(){ struct S s={"ABC",5}; print(s);}