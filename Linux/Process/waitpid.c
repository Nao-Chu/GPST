/********************************************************************
    > File Name: loop_fork.c
    > Author: zzp
    > Created Time: 2020年05月30日 星期六 11时15分34秒
 *******************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

int main(int argc,char *argv[])
{
    int i;
    for(i = 0; i < 5; i++){
		if (fork() == 0){
			break;
		}
    }
    if (i == 5){
		//sleep(5);
		// WNOHANG 非阻塞 0 阻塞
		pid_t pid;
		while((pid = waitpid(-1,NULL,WNOHANG)) != -1){
			if(pid > 0){
				printf("wait child %d\n",pid);
			} else if (pid == 0){
				sleep(1);
				printf("wait pid == 0,continue\n");
				continue;
			}
		}
    } else{
		sleep(i);
		printf("my child pid = %d,i = %d\n",getpid(),i + 1);
    }
    printf("pid:%d end\n",getpid());
    return 0;
}
