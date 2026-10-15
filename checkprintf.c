#include<stdio.h>
#include<setjmp.h>
jmp_buf jumpbuffer;
void printer(void);
int main(int argc,char** argv){
	printf("Hello integralites\n");
	if(setjmp(jumpbuffer)!=0){
		printf("End of main\n");
		return 0;
	}
	printer();
	return 0;
}
	void printer(){
		printf("printer call\n");
		longjmp(jumpbuffer,1);
		printf("end of printer\n");
	}
