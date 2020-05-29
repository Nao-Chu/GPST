/********************************************************************
    > File Name: dup.c
    > Author: zzp
    > Created Time: 2020年05月29日 星期五 17时57分35秒
 *******************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{
    int fd = open(argv[1],O_RDONLY);

    int newfd = dup(fd);

    write(newfd,"123456",6);
    printf("newfd = %d\n",newfd);

    return 0;
}
