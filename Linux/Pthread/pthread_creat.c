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
	int i = *((int*)arg);
	printf("thread:i = %d,pid = %d,tid = %lu\n",i,getpid(),pthread_self());
	var = 200;
	return NULL;
}

int main(int argc,char *argv[])
{
	printf("main:pid = %d,tid = %lu\n",getpid(),pthread_self());
	for(int i = 0; i < 5; ++i){
		pthread_t tid;
		int ret = pthread_create(&tid, NULL, tfn, (void*)&i);
		if(ret != 0){
			perror("pthread_create error");
		}
	}

	sleep(1);
	printf("the pthread has changed,var = %d\n",var);
    return 0;
}
