/********************************************************************
    > File Name: myls.c
    > Author: zzp
    > Created Time: 2020年05月29日 星期五 17时27分44秒
 *******************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>

int main(int argc,char *argv[])
{
    DIR * dp;
    dp = opendir(argv[1]);
    if (dp == NULL){
		perror("opendir error");
		exit(1);
    }

    struct dirent *sdp;
	/*
	 * struct dirent{
	 *		inode;
	 *		dname;
	 * }
	 * */
    while((sdp = readdir(dp)) != NULL){
		if(strcmp(sdp->d_name,".") == 0)
			continue;
		printf("%s\n",sdp->d_name);
    }

    closedir(dp);

    return 0;
}
