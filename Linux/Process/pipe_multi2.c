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
	
	int i = 0;
	for(i = 0; i < 2; ++i){
		if (fork() == 0){
			break;
		}

	}

	if (i == 2){
		close(fd[0]);
		write(fd[1],"hello world\n",12);
		wait(NULL);
		wait(NULL);
	} else if (i == 0){
		close(fd[1]);
		sleep(1);
		printf("child1 read\n");
		char buf[24];
		int ret = read(fd[0],buf,6);
		write(STDOUT_FILENO,buf,ret);
	} else{
		close(fd[1]);
		sleep(2);
		printf("\nchild2 read\n");
		char buf[24];
		int ret = read(fd[0],buf,6);
		write(STDOUT_FILENO,buf,ret);
	}
    return 0;
}
