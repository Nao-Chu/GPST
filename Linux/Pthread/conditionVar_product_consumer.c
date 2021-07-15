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


struct msg{
	struct msg* next;
	int num;
};

struct msg* head;

pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock	   = PTHREAD_MUTEX_INITIALIZER;

void *consumer(void *arg)
{
	struct msg *mp;
	while(1){
		pthread_mutex_lock(&lock);
		while(head == NULL){
			pthread_cond_wait(&has_product,&lock);
		}
		mp = head;
		head = mp->next;
		pthread_mutex_unlock(&lock);
		printf("Consume %lu -- %d\n\n",pthread_self(),mp->num);
		free(mp);
		sleep(rand()%5);
	}
	return NULL;
}

void *producer(void *arg)
{
	struct msg *mp;
	while(1){
		mp = malloc(sizeof(struct msg));
		mp->num = rand()%1000 + 1;
		printf("Produce%lu -- %d\n",pthread_self(),mp->num);

		pthread_mutex_lock(&lock);
		mp->next = head;
		head = mp;
		pthread_mutex_unlock(&lock);

		pthread_cond_signal(&has_product);
		sleep(rand()%5);
	}
	return NULL;
}

int main(int argc,char *argv[])
{
	srand(time(NULL));
	pthread_t pid;
	pthread_create(&pid, NULL, producer, NULL);
	pthread_t cid[10];
	for(int i = 0; i < 10; ++i)
		pthread_create(&cid[i], NULL, consumer, NULL);

	pthread_join(pid,NULL);
	for(int i = 0; i < 10; ++i)
		pthread_join(cid[i],NULL);
    return 0;
}
