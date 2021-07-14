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
    pid_t pid,wpid;
    int status;
    pid = fork();
    if(pid == 0){
		printf("child\n");
		sleep(10);
		printf("child die\n");
		return 73;
    }else if (pid > 0){
		wpid = wait(&status);
		if(wpid == -1){
			perror("wait error\n");
			exit(1);
		}
		if (WIFEXITED(status)){
			printf("child exit with %d\n",WEXITSTATUS(status));
		}
		if (WIFSIGNALED(status)){
			printf("child signal with %d\n",WTERMSIG(status));
		}
		printf("parent finsh\n");
    }else{
		perror("fork");
		return 1;
    }
    return 0;
}
