#include<stdio.h>
#include<pthread.h>
#define BUFFER_SIZE 10
int count=0;
void* producer(void*);
void* consumer(void*);
int main(int argc,char** argv){
	pthread_t tid1;
	pthread_t tid2;
	pthread_attr_t attr1;
	pthread_attr_t attr2;
	pthread_attr_init (&attr1);
	pthread_attr_init (&attr2);
	pthread_create (&tid1,&attr1,runner,NULL);
	pthread_create (&tid2,&attr2,share,NULL);
	printf("producer sends data ");
	printf("consumer recive data");
	return 0;
}
void* producer(void* sends){
	int next_produced=0;
	int in =0;
	while(1){
		while(count==BUFFER_SIZE);
		buffer[in]=next_produced++;
		in = (in+1)%BUFFER_SIZE;
		count++;
	}
}
void* consumer(void* recive){
	int out=0;
	while(1){
		while(count==0);
		int next_consumed = buffer[out];
		printf("%d\n",next_consumed);
		out=(out+1)%BUFFER_SIZE;
		count--;
	}
}
	
