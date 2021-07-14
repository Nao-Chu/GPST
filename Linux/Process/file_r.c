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
	sleep(2);
	int fd = open(argv[1],O_RDWR,0644);
	if(fd < 0){
		sys_err("open");
	}

	char buf[1024];
	int ret = read(fd,buf,sizeof(buf));
	ret = write(STDOUT_FILENO,buf,ret);

	ret = write(fd,"world!\n",7);
	close(fd);
    return 0;
}
