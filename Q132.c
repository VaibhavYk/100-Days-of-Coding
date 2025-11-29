#include <stdio.h>
enum light{RED,YELLOW,GREEN};
int main(){ enum light s=RED;
if(s==RED) puts("Stop"); else if(s==YELLOW) puts("Wait"); else puts("Go"); }