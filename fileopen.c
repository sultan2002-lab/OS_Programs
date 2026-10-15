#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 
int main(int argc, char** argv) {
    printf("main process\n");
    pid_t p = fork();
    if (p > 0) {
        wait(NULL);
        	printf("parent terminated\n");
    	} else if (p == 0) {
        char* path = "/bin/nano";
        execle(path, "nano", "./process.c",NULL,NULL);
    	} else {
        printf("did not work: fork failed\n");
    	}
    	printf("end of main\n");
    	return 0;
}
