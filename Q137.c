#include <stdio.h>
enum role{ADMIN,USER,GUEST};
int main(){ enum role r=USER;
if(r==ADMIN) puts("Admin"); else if(r==USER) puts("User"); else puts("Guest"); }