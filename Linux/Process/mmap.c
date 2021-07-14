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
#include<sys/mman.h>

void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

int main(int argc,char *argv[])
{
	int fd = open("testmap",O_RDWR|O_CREAT|O_TRUNC,0644);
	if(fd == -1){
		sys_err("open error");
	}

	ftruncate(fd,20);
	int len = lseek(fd,0,SEEK_END);

	char* p = mmap(NULL,len,PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);
	if(p == MAP_FAILED){
		sys_err("mmap error");
	}

	strcpy(p,"hello mmap");
	printf("-----%s\n",p);
	
	int ret = munmap(p,len);
	if(ret == -1){
		sys_err("munmap error");
	}
    return 0;
}
