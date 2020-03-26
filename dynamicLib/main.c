/********************************************************************
    > File Name: main.c
    > Author: zzp
    > Created Time: 2020年03月26日 星期四 18时38分11秒
 *******************************************************************/

#include<stdio.h>
#include"inc/add.h"

int main()
{
	int a = 10;
	int b = 20;
	printf("%d + %d = %d\n",a,b,add(a,b));
	return 0;
}
