/*bin/bash: 3: command not found
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
#include<sys/wait.h>
#include<sys/types.h>

void catch_child(int signo)
{
	printf("catch signo : %d\n",signo);
	pid_t wpid;
	int status;
	while((wpid = waitpid(-1,&status,0)) != -1){
		if(WIFEXITED(status))
			printf("catch child id %d\n",wpid);
	}
}
int main(int argc,char *argv[])
{
	int i = 0;
	for(; i < 15; ++i){
		if(fork() == 0)
			break;
	}

    if(15 == i){
		struct sigaction act;
		act.sa_handler = catch_child;
		sigemptyset(&act.sa_mask);
		act.sa_flags = 0;
		sigaction(SIGCHLD,&act,NULL);
		printf("I'm parent,pid:%d\n",getpid());
		sleep(4);
    } else {
		printf("I'm child ,pid:%d\n",getpid());
    }

    return 0;
}
