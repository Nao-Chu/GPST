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

void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

int main(int argc,char *argv[])
{
	int fd[2];
	int ret = pipe(fd);
	if(ret == -1){
		sys_err("pipe error");
	}
	pid_t pid = fork();
	if(pid > 0){
		close(fd[0]);
		dup2(fd[1],STDOUT_FILENO);
		execlp("ls","ls",NULL);
	}else if (pid == 0){
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);
		execlp("wc","wc","-l",NULL);
	}
    return 0;
}
