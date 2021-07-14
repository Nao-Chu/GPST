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
	pid_t pid = fork();

	if(pid > 0){
		while(1){
			printf("parent pid = %d\n",getpid());
			sleep(1);
		}
	}else if(pid == 0){
		int i = 0;
		while(++i){
			printf("child pid = %d,ppid = %d\n",getpid(),getppid());
			sleep(1);
			if(i == 10){
				break;
			}else if (i == 4){
				//kill(getppid(),SIGKILL);
				kill(-getppid(),SIGKILL);
				//kill(0,SIGKILL);
			}
		}
	}

    return 0;
}
