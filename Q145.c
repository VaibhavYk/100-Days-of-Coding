#include <stdio.h>
struct Student{char n[20]; int roll; float m;};
struct Student top(struct Student a, struct Student b){
return (a.m>b.m)?a:b;}
int main(){ struct Student x={"A",1,90},y={"B",2,95}; 
struct Student t=top(x,y); printf("%s",t.n);}