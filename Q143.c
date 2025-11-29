#include <stdio.h>
struct Student{char name[20]; int roll; float marks;};
int main(){ struct Student s[5],top; 
for(int i=0;i<5;i++) scanf("%s%d%f",s[i].name,&s[i].roll,&s[i].marks);
top=s[0]; for(int i=1;i<5;i++) if(s[i].marks>top.marks) top=s[i];
printf("Top: %s %d %.2f",top.name,top.roll,top.marks);}