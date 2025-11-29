#include <stdio.h>
enum menu{ADD=1,SUB,MUL};
int main(){ int a=5,b=3; enum menu m=ADD;
switch(m){case ADD:printf("%d",a+b);break;case SUB:printf("%d",a-b);break;case MUL:printf("%d",a*b);} }