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
#include<semaphore.h>
#include<pthread.h>


struct msg{
	struct msg* next;
	int num;
};

struct msg* head;

sem_t blank_number,product_number;

void *consumer(void *arg)
{
	struct msg *mp;
	while(1){
		sem_wait(&product_number);
		sleep(12);
		mp = head;
		head = mp->next;
		sem_post(&blank_number);
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

		sem_wait(&blank_number);
		mp->next = head;
		head = mp;
		sem_post(&product_number);

		sleep(rand()%5);
	}
	return NULL;
}

int main(int argc,char *argv[])
{
	sem_init(&blank_number,0,5);
	sem_init(&product_number,0,0);
	srand(time(NULL));
	pthread_t pid;
	pthread_create(&pid, NULL, producer, NULL);
	pthread_t cid;
	pthread_create(&cid, NULL, consumer, NULL);

	pthread_join(pid,NULL);
	pthread_join(cid,NULL);
    return 0;
}
