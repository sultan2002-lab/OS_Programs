#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void f1();
void f2();
int main(){
	atexit(f1);
	atexit(f2);
	atexit(f2);
	printf("starts of main\n");
	printf("Hello\n");
	printf("end of main\n");
	/* return 0 ; isko skip kr rhe h program ko terminate krn ek liye;*/
	_exit(0);
}
void f1(){
	printf("f1 called\n");
}
void f2(){
	printf("f2 called\n");
}

