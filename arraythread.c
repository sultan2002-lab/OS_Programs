#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define SIZE 7
int arr[SIZE]={5,2,7,15,28,9,3};
int max_value;
int min_value;
void* findmax_value(void* );
void* findmin_value(void* );
int main(int argc,char** argv){
	pthread_t tid1,tid2;
	pthread_attr_t attr1,attr2;
	pthread_attr_init (&attr1);
	pthread_attr_init (&attr2);
	pthread_create(&tid1,&attr1,findmax_value,NULL);
	pthread_create(&tid2,&attr2,findmin_value,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	printf("maximum thread=%d\n",max_value);
	printf("minimum thread=%d\n",min_value);
	return 0;
}
void* findmax_value(void* param){
	max_value=arr[0];
	int i;
	for(i=1;i<7;i++){
		if(max_value>arr[0]){
			max_value=arr[i];
		}
	}
	pthread_exit(0);
}
void* findmin_value(void* param){
	min_value=arr[0];
	int i;
	for( i=1;i<7;i++){
		if(min_value<arr[i]){
			min_value=arr[i];
		}
	}
	pthread_exit(0);
}
