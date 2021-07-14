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
	int fd1 = open(argv[1],O_RDWR);
	dup2(fd1,STDOUT_FILENO);

	execlp("ps","ps","aux",NULL);
	perror("execpl, error");

    return 0;
}
