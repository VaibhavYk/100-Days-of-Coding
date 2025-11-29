#include <stdio.h>
struct Emp{char n[20]; int id;};
int main(){ struct Emp e={"ABC",1}; FILE *f=fopen("emp.bin","wb"); fwrite(&e,sizeof(e),1,f); fclose(f);
f=fopen("emp.bin","rb"); fread(&e,sizeof(e),1,f); printf("%s %d",e.n,e.id);}