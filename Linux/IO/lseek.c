/********************************************************************
    > File Name: lseek.c
    > Author: zzp
    > Created Time: 2020年05月29日 星期五 10时55分16秒
 *******************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
    int fd = open(argv[1],O_RDWR);
    if (fd == -1){
	perror("open error");
	exit(1);
    }

    int lenth = lseek(fd,111,SEEK_END);
    printf("file size:%d \n",lenth);

    write(fd,"a",1);
    close(fd);

    return 0;
}
