/********************************************************************
    > File Name: unlink_exe.c
    > Author: zzp
    > Created Time: 2020年05月29日 星期五 15时59分47秒
 *******************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
    int fd;
    char *p1 = "test of unlink\n";
    char *p2 = "after write something.\n";

    fd = open("temp.txt",O_RDWR|O_CREAT|O_TRUNC,0644);
    if (fd < 0){
	perror("open temp error");
	exit(1);
    }

    int ret = write(fd,p1,strlen(p1));
    if (ret == -1){
	perror("-----write error");
    }
    printf("hi! Im printf\n");
    
    ret = write(fd,p2,strlen(p2));
    if (ret == -1){
	perror("-----write error");
    }
    printf("Enter anykey continue\n");
    getchar(); 

    close(fd);

    ret = unlink("temp.txt");
    if(ret < 0){
	perror("unlink error");
	exit(1);
    }

    return 0;
}

