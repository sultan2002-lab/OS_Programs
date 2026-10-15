#include<stdio.h>
#include<pthread.h>
#define BUFFER_SIZE 10
void* producer(void*);
void* consumer(void*);
int buffer[BUFFER_SIZE];
int count=0;
int main(int argc,char** argv){
	pthread_t tid1;
	pthread_t tid2;
	pthread_attr_t attr1;
	pthread_attr_t attr2;
	pthread_attr_init(&attr1);
	pthread_attr_init(&attr2);
	pthread_create(&tid1,&attr1,producer,NULL);
	pthread_create(&tid2,&attr2,consumer,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return 0;
}
void* producer(void* arg){
	int next_produced=0;
	int in =0;
	while(1){
		while(count==BUFFER_SIZE);
		printf("producer : %d\n",next_produced);
		buffer[in] = next_produced++;
		in=(in+1)%BUFFER_SIZE;
		count++;
	}
	pthread_exit(0);
}
void* consumer(void* arg){
	int out=0;
	while(1){
		while(count==0);
		int next_consumed=buffer[out];
		printf("consumer : %d\n",next_consumed);
		out=(out+1)%BUFFER_SIZE;
		count--;
	}
	pthread_exit(0);
}
