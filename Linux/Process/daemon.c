/********************************************************************
    > File Name: fork.c
    > Author: zzp
    > Created Time: 2020年05月29日 星期五 19时51分34秒
 *******************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    pid_t pid = fork();
    if (pid == -1){
		perror("fork error");
		exit(1);
    } else if (pid == 0){
		setsid();
		chdir("/home/zzp");
		umask(0022);
		close(STDIN_FILENO);
		int fd = open("/dev/null",O_RDWR);
		if(fd == -1){
			perror("open error");
			exit(1);
		}
		dup2(fd,STDOUT_FILENO);
		dup2(fd,STDERR_FILENO);
		while(1);
    } 

    return 0;
}
