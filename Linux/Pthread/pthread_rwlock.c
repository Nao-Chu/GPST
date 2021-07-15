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
pthread_rwlock_t rwlock;

void *th_write(void *arg)
{
	while(1){
		pthread_rwlock_wrlock(&rwlock);
		int t = var;
		usleep(1000);
		printf("write--- %lu: ret = %d ++ret = %d\n",pthread_self(),t,++var);
		sleep(1);
		pthread_rwlock_unlock(&rwlock);
		usleep(7000000);
	}
	return NULL;
}

void *th_read(void *arg)
{
	while(1){
		pthread_rwlock_rdlock(&rwlock);
		printf("read--- %lu: ret = %d \n",pthread_self(),var);
		sleep(10);
		pthread_rwlock_unlock(&rwlock);
		usleep(1000000);
	}
	return NULL;
}

int main(int argc,char *argv[])
{
	pthread_rwlock_init(&rwlock,NULL);

	pthread_t tid[8];
	for(int i = 0; i < 3; ++i)
		pthread_create(&tid[i], NULL, th_write, NULL);
	for(int i = 0; i < 5; ++i)
		pthread_create(&tid[i+3], NULL, th_read, NULL);

	for(int i = 0; i < 8; ++i)
		pthread_join(tid[i],NULL);
	pthread_rwlock_destroy(&rwlock);
    return 0;
}
