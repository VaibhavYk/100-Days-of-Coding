#include <stdio.h>
struct Student{char name[20]; int roll; float marks;};
int main(){ struct Student s[5];
for(int i=0;i<5;i++) scanf("%s%d%f",s[i].name,&s[i].roll,&s[i].marks);
for(int i=0;i<5;i++) printf("%s %d %.2f\n",s[i].name,s[i].roll,s[i].marks);}