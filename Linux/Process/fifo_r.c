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
	int fd = open(argv[1],O_RDONLY);
	if(fd < 0){
		sys_err("open");
	}
	char buf[1024];
	while(1){
		int len = read(fd,buf,sizeof(buf));
		write(STDOUT_FILENO,buf,len);
		sleep(1);
	}
	close(fd);
    return 0;
}
