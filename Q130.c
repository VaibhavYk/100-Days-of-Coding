#include <stdio.h>
int main(){ FILE *f=fopen("numbers.txt","r"); int x,sum=0,cnt=0;
while(fscanf(f,"%d",&x)==1){ sum+=x; cnt++; }
printf("Sum=%d Avg=%.2f",sum,(float)sum/cnt); fclose(f);}