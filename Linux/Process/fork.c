/********************************************************************
    > File Name: fork.c
    > Author: zzp
    > Created Time: 2020年05月29日 星期五 19时51分34秒
 *******************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{
    printf("before fork-1\n");
    printf("before fork-2\n");
    printf("before fork-3\n");
    printf("before fork-4\n");
    printf("before fork-5\n");

    pid_t pid = fork();
    if (pid == -1){
	perror("fork error");
	exit(1);
    } else if (pid == 0){
	printf("I'm child; my pid is %d,my parent pid is %d\n ",getpid(),getppid());
    } else if (pid > 0){
	printf("I'm parent;my child pid is %d, my pid:%d,my parend pid:%d\n",pid,getpid(),getppid());
    }

    printf("-----------end----------\n");
    return 0;
}
