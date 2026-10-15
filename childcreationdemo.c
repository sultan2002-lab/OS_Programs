#include<stdio.h>
#include<unistd.h>
int main(int argc,char** argv){
	printf("starting of main function\n");
	pid_t p = fork();
	if(p>0){
		/*int i=0;
		while(i<50000)i++;*/
		waitpid(p,NULL);
		printf("parent process\n");
		/*printf("pid=%d\n",(int)getpid());*/
	}else if(p==0){
		printf("child process\n");
		printf("ppid = %d\n",(int)getppid());
	}else{
		printf("fork did not work\n");
	}
	printf("end of main\n");
	return 0;
}
