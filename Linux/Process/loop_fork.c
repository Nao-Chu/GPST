/********************************************************************
    > File Name: loop_fork.c
    > Author: zzp
    > Created Time: 2020年05月30日 星期六 11时15分34秒
 *******************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{
    int i;
    for(i = 0; i < 5; i++){
	if (fork() == 0){
	    break;
	}
    }
    if (i == 5){
	sleep(1);
	printf("I'm parent\n");
    } else{
	printf("my child pid = %d,i = %d\n",getpid(),i + 1);
    }
    printf("pid:%d end\n",getpid());
    return 0;
}
