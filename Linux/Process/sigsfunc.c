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

int main(int argc,char *argv[])
{
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set,SIGINT);
	sigaddset(&set,SIGBUS);

	sigset_t oldset;
	sigprocmask(SIG_BLOCK,&set,&oldset);

	while(1){
		sigset_t pedset;
		sigpending(&pedset);
		for(int i = 1; i <= 32; ++i){
			if(sigismember(&pedset,i)){
				printf("1");
			}else{
				printf("0");
			}
		}
		printf("\n");
		sleep(1);

	}
    return 0;
}
