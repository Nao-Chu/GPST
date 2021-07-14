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
#include<signal.h>
#include<sys/types.h>


int main(int argc,char *argv[])
{
	for(int i = 0; i < 5; ++i){
		pid_t pid = fork();
		if(pid == 0){
			while(1){
				printf("child pid = %d,ppid = %d\n",getpid(),getppid());
				sleep(1);
			}
			return;
		}
	}

	sleep(1);
	//kill(getppid(),SIGKILL);
	//printf("kill pid : %d\n",pid);
	kill(-getppid(),SIGKILL);
	//kill(0,SIGKILL);

    return 0;
}
