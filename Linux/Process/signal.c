/********************************************************************
    > File Name: fork_exec.c
    > Author: zzp
    > Created Time: 2020年05月30日 星期六 12时36分21秒
 *******************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>

void sig_cath(int signo)
{
	printf("catch you!! %d\n",signo);
	if(signo == SIGINT){
		sleep(5);
	}

}

int main(int argc,char *argv[])
{
	/*
	signal(SIGINT,sig_cath);
	signal(SIGQUIT,sig_cath);
	*/
	struct sigaction act;
	act.sa_handler = sig_cath;
	sigemptyset(&(act.sa_mask));
	sigaddset(&act.sa_mask,SIGQUIT);
	act.sa_flags = 0;

	struct sigaction oldact;
	int ret = sigaction(SIGINT,&act,&oldact);
	if(ret == -1){
		perror("sigaction error");
	}
	while(1){

	}
    return 0;
}
