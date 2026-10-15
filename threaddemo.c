#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int sum =0;
void* adder(void*);
int main(int argc,char** argv){
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init (&attr);
	pthread_create(&tid,&attr,adder,NULL);
	pthread_join(tid,NULL);
	printf("sum=%d\n",sum);
	return 0;
}
void* adder(void* ar){
	/*pthread_t tid=*((pthread_t*)ar);*/
	/*pthread_kill(tid,15);*/
	int i;
	for(i=0;i<=500;i++){
		sum+=i;
		if(i==200){
			pthread_exit(0);
		}
	}
	pthread_exit(0);
}
