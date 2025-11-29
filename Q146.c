#include <stdio.h>
struct Date{int d,m,y;};
struct Emp{char n[20]; struct Date j;};
int main(){ struct Emp e={"ABC",{1,1,2024}}; 
printf("%s %d-%d-%d",e.n,e.j.d,e.j.m,e.j.y);}