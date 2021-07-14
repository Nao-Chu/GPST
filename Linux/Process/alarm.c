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

int var = 100;

int main(int argc,char *argv[])
{
	int i = 0;
	alarm(1);
	while(1){
		printf("%d\n",i++);
	}

    return 0;
}
