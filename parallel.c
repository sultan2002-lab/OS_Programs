#include<stdio.h>
#include<omp.h>
int main(int argc,char** argv){
	int i;
	kill(getpid(),15);
	#pragma omp parallel for
	for(i=0;i<500;i++){
		/*printf("first thread :%d\n",i);*/
		printf("thread no: %d,value=%d\n",omp_get_thread_num(),i);
	}
	return 0;
}
