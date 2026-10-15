#include<stdio.h>
int main(int argc,char* argv[]){
	/* it works well but we  can replace argc to argv*/
	/*if(argc==1){
		printf("No arguments pass\n");
		return 0;
	}
	int i;
	for(i=1;i<argc;i++){
		printf("%d argument=%s\n",i,argv[i]);
	}
	return 0;*/
	/* now we write replace with argv instead of argc*/
	if(argv[1]==NULL){
		printf("No arguments called\n");
		return 0;
	}
	int i=1;
	while(argv[i]!=NULL){
		printf("%d arguments = %s\n",i,argv[i]);
		i++;
	}
	return 0;
}
