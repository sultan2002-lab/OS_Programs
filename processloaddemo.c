#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc,char** argv){
	printf("main process\n");
	pid_t p = fork();
	if(p>0){
		wait(NULL);
		printf("parent terminated\n");
	}else if(p==0){
		/*char* path="/bin/ls";
		char* args[] = {"ls","-l",NULL};
		execv(path,args);*/
		execl("/bin/ls","ls","-l",NULL);
	}else{
		printf("didnot work fork\n");
	}
	printf("end of main\n");
	return 0;
}
