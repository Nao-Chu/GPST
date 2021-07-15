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
#include<time.h>
#include<pthread.h>

int var = 100;
pthread_mutex_t mutex;

void *tfn(void *arg)
{
	srand(time(NULL));
	while(1){
		pthread_mutex_lock(&mutex);
		printf("hello ");
		sleep(rand()%3);
		printf("world\n");
		pthread_mutex_unlock(&mutex);
		//sleep(rand()%3);
	}
	return NULL;
}

int main(int argc,char *argv[])
{
	pthread_mutex_init(&mutex,NULL);

	pthread_t tid;
	int ret = pthread_create(&tid, NULL, tfn, NULL);
	if(ret != 0){
		perror("pthread_create error");
	}

	srand(time(NULL));
	while(1){
		pthread_mutex_lock(&mutex);
		printf("HELLO ");
		sleep(rand()%3);
		printf("WORLD\n");
		pthread_mutex_unlock(&mutex);
		//sleep(rand()%3);
	}

	pthread_join(tid,NULL);
	pthread_mutex_destroy(&mutex);
    return 0;
}
