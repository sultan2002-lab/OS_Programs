#include<stdio.h>
#include<stdarg.h>
int sumnum(int count,...){
	va_list args;
	va_start(args,count);/* initialize va_list with count as a last parameter*/
	int sum =0,i;
	for(i=0;i<count;i++){
		sum += va_arg(args,int);/*Reterive next arguments as int*/
	}
	va_end(args);/*clean up the va_list*/
	return sum;
}
int main(int argc,char** argv){
	printf("%d\n",sumnum(3,2,5,7));
	printf("%d\n",sumnum(2,10,20));
	return 0;
}
