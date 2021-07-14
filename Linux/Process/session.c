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
    pid_t pid = fork();
    if (pid == -1){
		perror("fork error");
		exit(1);
    } else if (pid == 0){
		printf("I'm child; My pid is %d\n ",getpid());
		printf("I'm child; Group pid is %d\n ",getpgid(0));
		printf("I'm child; Session pid is %d\n ",getsid(0));
		sleep(2);
		setsid();
		printf("Changed:\n");
		printf("I'm child; My pid is %d\n ",getpid());
		printf("I'm child; Group pid is %d\n ",getpgid(0));
		printf("I'm child; Session pid is %d\n ",getsid(0));
		sleep(5);
    } else if (pid > 0){
		printf("I'm parent;my child pid is %d, my pid:%d,my parend pid:%d\n",pid,getpid(),getppid());
    }

    printf("-----------end----------\n");
	sleep(10);
    return 0;
}
