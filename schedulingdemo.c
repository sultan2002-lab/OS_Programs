#include<stdio.h>
#include<pthread.h>
#define NUM_THREADS 5
void* runner(void*);
int main(int argc,char** argv){
	int i,scope;
	pthread_t tid[NUM_THREADS];
	pthread_attr_t attr;
	pthread_attr_init (&attr);
	if(pthread_attr_getscope(&attr,&scope)!=0){
		printf("unable to fet scope\n");
	}else{
		if(scope==PTHREAD_SCOPE_PROCESS){
			printf("PTHREAD_SCOPE_PROCESS");
		}else if(scope==PTHREAD_SCOPE_SYSTEM){
			printf("PTHREAD_SCOPE_SYSTEM");
		}else{
			printf("Illegal scope value");
		}
	}
	pthread_attr_setscope(&attr,PTHREAD_SCOPE_SYSTEM);
	for(i=0;i<NUM_THREADS;i++){
		pthread_create(&tid[i],&attr,runner,NULL);
	}
	for(i=0;i<NUM_THREADS;i++){
		pthread_join(tid[i],NULL);
	}
	return 0;
}
void* runner(void* param){
	int i;
	int k=0;
	for(i=1;i<10;i++){
		k=k+i;
	}
	printf("%d\n",k);
	pthread_exit(0);
}
