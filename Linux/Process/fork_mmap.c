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
#include<sys/wait.h>

void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

int var = 100;

int main(int argc,char *argv[])
{
	//int fd = open("testmap",O_RDWR|O_CREAT|O_TRUNC,0644);
	int fd = open("/dev/zero",O_RDWR);
	if(fd == -1){
		sys_err("open error");
	}

	ftruncate(fd,4);
	int len = lseek(fd,0,SEEK_END);
//	int* p = mmap(NULL,len,PROT_READ|PROT_WRITE, MAP_SHARED | MAP_ANONMYOUS, -1,0);
	int* p = mmap(NULL,40,PROT_READ|PROT_WRITE,MAP_SHARED, fd,0);
	if(p == MAP_FAILED){
		sys_err("mmap error");
	}
	close(fd);

	pid_t pid = fork();
	if(pid == 0){
		*p = 2000;
		var = 1000;
		printf("child, *p = %d, var = %d\n",*p,var);
	}else{
		sleep(1);
		printf("parent, *p = %d, var = %d\n",*p,var);
		wait(NULL);

		int ret = munmap(p,4);
		if(ret == -1){
			sys_err("munmap error");
		}
	}

    return 0;
}
