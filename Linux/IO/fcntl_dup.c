/********************************************************************
    > File Name: fcntl_dup.c
    > Author: zzp
    > Created Time: 2020年05月29日 星期五 18时21分22秒
 *******************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{
    int fd1 = open(argv[1],O_RDWR);

    printf("fd1 = %d\n",fd1);

    int newfd = fcntl(fd1,F_DUPFD,0);
    printf("newfd = %d\n",newfd);
    
    int newfd2 = fcntl(fd1,F_DUPFD,7);
    printf("newfd2 = %d\n",newfd2);
    
    int ret = write(newfd2,"fcntl_dup\n",10);
    printf("ret = %d\n",ret);
    return 0;
}
