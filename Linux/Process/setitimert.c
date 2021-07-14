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
#include<sys/time.h>
#include<signal.h>

int var = 100;

int main(int argc,char *argv[])
{
	struct itimerval new_value;
	new_value.it_value.tv_sec = 1;
	new_value.it_value.tv_usec =0;

	new_value.it_interval.tv_sec = 1;
	new_value.it_interval.tv_usec =0;

	struct itimerval old_value;
	setitimer(ITIMER_REAL,&new_value,&old_value);
	int i = 0;
	while(1){
		printf("%d\n",i++);
	}

    return 0;
}
