/********************************************************************
    > File Name: link.c
    > Author: zzp
    > Created Time: 2020年05月29日 星期五 15时48分30秒
 *******************************************************************/

#include<stdio.h>
#include<unistd.h>


int main(int argc,char *argv[])
{
    link(argv[1],argv[2]);
//    unlink(argv[1]);
    return 0;
}
