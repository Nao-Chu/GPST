/********************************************************************
    > File Name: block_readtty.c
    > Author: zzp
    > Created Time: 2020年05月29日 星期五 10时31分37秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    char buf[10];
    int n;
    n = read(STDIN_FILENO,buf,10); // define STDIN_FILENO STDOUT_FILENO STDERR_FILENO

    if (n < 0){
	perror("read STDIN_FILENO");
	exit(1);
    }
    write(STDOUT_FILENO,buf,n);

    return 0;
}
