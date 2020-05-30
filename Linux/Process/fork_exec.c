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

int main(int argc,char *argv[])
{
    pid_t pid = fork();
    if (pid == -1){
	perror("fork error");
	exit(1);
    } else if(pid == 0){
	//execlp("ls","ls","-l","-d","-h",NULL);
	execl("./fork","./fork",NULL);
    } else if (pid > 0){
	printf("I'm parent,pid:%d\n",getpid());
    }
    sleep(1);

    return 0;
}
