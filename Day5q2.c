//Write a program to input time in seconds and convert it to hours:minutes:seconds format.

#include<stdio.h>
int main()
{
    int s, hr, min, time;
    printf("Enter the time in seconds:\n");
    scanf("%d", &s);

    hr= s/3600;
    min= (s%3600)/60;
    s= s%60;

    printf("Time in hours:minutes:seconds format:%d:%d;%d\n", hr, min, s);

    return 0;
    
}