/********************************************************************
    > File Name: fork_exec.c
    > Author: zzp
    > Created Time: 2020年05月30日 星期六 12时36分21秒
 *******************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int var = 100;

int main(int argc,char *argv[])
{
    pid_t pid = fork();
    if (pid == -1){
		perror("fork error");
		exit(1);
    } else if(pid > 0){
		var = 288;
		printf("parent, var = %d\n", var);
		printf("I'm parent,pid:%d, getppid = %d\n",getpid(),getppid());
    } else if (pid == 0){
		var = 200;
		printf("I'am child, var = %d\n", var);
		printf("pid:%d, getppid = %d\n",getpid(),getppid());
    }
    sleep(1);

    return 0;
}
