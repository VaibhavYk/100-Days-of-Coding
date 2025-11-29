#include <stdio.h>
enum status{SUCCESS,FAILURE,TIMEOUT};
int main(){ enum status s=SUCCESS;
switch(s){case SUCCESS:puts("Success");break;case FAILURE:puts("Fail");break;case TIMEOUT:puts("Timeout");}}