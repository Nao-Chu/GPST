/********************************************************************
    > File Name: mystat.c
    > Author: zzp
    > Created Time: 2020年05月29日 星期五 14时28分16秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>

#define _GNU_SOURCE

int main(int argc,char *argv[])
{
    struct stat sb;

    int ret = stat(argv[1],&sb);
    //int ret = lstat(argv[1],&sb);
    if(ret == -1){
		perror("stat eror");
		exit(1);
    }

	printf("file size is:%ld\n",sb.st_size);
    if (S_ISREG(sb.st_mode)){
	printf("It's a regular\n");
    } else if (S_ISDIR(sb.st_mode)){
	printf("It's a dir\n");
    } else if (S_ISFIFO(sb.st_mode)){
	printf("It's a pipe\n");
    } else if (S_ISLNK(sb.st_mode)){
	printf("It's a sym link\n");
    }
    return 0;
}
