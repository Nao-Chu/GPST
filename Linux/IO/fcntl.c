/********************************************************************
    > File Name: fcntl.c
    > Author: zzp
    > Created Time: 2020年05月29日 星期五 10时36分23秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>

int main()
{
    char buf[10];
    int flags,n;

    flags = fcntl(STDIN_FILENO,F_GETFL);
    if(flags == -1){
		perror("fcntl error");
		exit(1);
    }
    flags |= O_NONBLOCK;

    int ret = fcntl(STDIN_FILENO,F_SETFL,flags);
    if (ret == -1){
		perror("fcntl error");
		exit(1);
    }

    for (int i=0; i < 5; i++){
		n = read(STDIN_FILENO,buf,10);
		if (n < 0){
			if (errno != EAGAIN){
			perror("read /dev/tty");
			exit(1);
			}
			sleep(3);
			write(STDOUT_FILENO,"try again\n",strlen("try again\n"));
		}
    }
    return 0;
}
