#include<stdio.h>
#include<unistd.h>
int main(int argc,char** argv){
	printf("ppid=%d\n",(int)getppid());
	printf("pid=%d\n",(int)getpid());
	printf("uid=%d\n",(int)getuid());
	printf("gid=%d\n",(int)getgid());
	return 0;
}
