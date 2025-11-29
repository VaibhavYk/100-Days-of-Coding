#include <stdio.h>
enum Gender{MALE,FEMALE};
struct Person{char name[20]; enum Gender g;};
int main(){ struct Person p={"ABC",MALE}; printf("%s %d",p.name,p.g);}