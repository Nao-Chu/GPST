/********************************************************************
    > File Name: pthread_creat.c
    > Author: zzp
    > Created Time: 2021年07月14日 星期五 16时51分34秒
 *******************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

int var = 100;
void *tfn(void *arg)
{
	alarm(5);
	while(1){
		printf("thread:pid = %d,tid = %lu\n",getpid(),pthread_self());
	}
	var = 200;
	return NULL;
}

int main(int argc,char *argv[])
{
	printf("main:pid = %d,tid = %lu\n",getpid(),pthread_self());

	pthread_attr_t attr;
	pthread_attr_init(&attr);

	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	pthread_t tid;
	pthread_create(&tid, &attr, tfn, NULL);
	
	int ret = pthread_join(tid,NULL);
	if(ret != 0){
		fprintf(stderr,"join error:%s\n",strerror(ret));
		exit(0);
	}
	pthread_attr_destroy(&attr);
	printf("main:pid = %d,tid = %lu\n",getpid(),pthread_self());
    return 0;
}
