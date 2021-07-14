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
		char* str = "hello\n";
		write(fd[1],str,strlen(str));
		close(fd[1]);
	}else if (pid == 0){
		close(fd[1]);
		char buf[1024];
		ret = read(fd[0],buf,sizeof(buf));
		write(STDOUT_FILENO,buf,ret);
		close(fd[0]);

	}
    return 0;
}
