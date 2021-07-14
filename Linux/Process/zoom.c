/********************************************************************
    > File Name: zoom_test.c
    > Author: zzp
    > Created Time: 2020年05月30日 星期六 13时41分43秒
 *******************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

int main(int argc,char *argv[])
{
    pid_t pid;
    pid = fork();
    if(pid == 0){
		printf("child\n");
		sleep(10);
		printf("child die\n");
    }else if (pid > 0){
		while(1){
			printf("I am parent\n");
			sleep(1);
		}
		printf("parent finsh\n");
    }else{
		perror("fork");
		return 1;
    }
    return 0;
}
