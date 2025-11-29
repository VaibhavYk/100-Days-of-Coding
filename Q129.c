#include <stdio.h>
int main(){ FILE *f=fopen("text.txt","r"); char ch; int v=0,c=0;
while((ch=fgetc(f))!=EOF){ if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
char x=ch|32;
if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u') v++; else c++;}}
printf("Vowels=%d Consonants=%d",v,c); fclose(f);}