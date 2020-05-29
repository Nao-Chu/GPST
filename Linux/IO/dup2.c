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

    int fd2 = open(argv[2],O_RDWR);

    int fdret = dup2(fd1,fd2);
    printf("fdret %d\n",fdret);

    int ret = write(fd2,"hello",5);
    printf("ret = %d\n",ret);

    dup2(fd1,STDOUT_FILENO);
    printf("------------886\n");

    return 0;
}
