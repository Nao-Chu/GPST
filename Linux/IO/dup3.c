/********************************************************************
    > File Name: dup2.c
    > Author: zzp
    > Created Time: 2020年05月29日 星期五 18时08分20秒
 *******************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{
    int fd1 = open(argv[1],O_RDWR);
    printf("fd1 %d\n",fd1);

	/*
    int fdret = fcntl(fd1,F_DUPFD,0);
	得到>=0的可用的最小的描述符
    printf("fdret %d\n",fdret);
	*/
    int fdret = fcntl(fd1,F_DUPFD,7);
    printf("fdret %d\n",fdret);

    int ret = write(fdret,"hello",5);
    printf("ret = %d\n",ret);

    dup2(fd1,STDOUT_FILENO);
    printf("------------886\n");

    return 0;
}
