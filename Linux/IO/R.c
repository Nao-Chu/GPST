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
#include<sys/stat.h>

void ReadDir(char* dir_name);

void PrintName(char* path,char* file)
{
	struct stat sb;
	int ret = stat(path,&sb);
	if(ret == -1){
		perror("stat error");
		return;
	}
	printf("%s\t",file);
	if(S_ISDIR(sb.st_mode)){
		ReadDir(path);
	}
}

void ReadDir(char* dir_name)
{
    DIR * dp;
    dp = opendir(dir_name);
    if (dp == NULL){
		perror("opendir error");
		return;
    }

	printf("\n%s:\n",dir_name);
    struct dirent *sdp;
	char path[256];
    while((sdp = readdir(dp)) != NULL){
		if((strcmp(sdp->d_name,".") == 0) ||(strcmp(sdp->d_name,"..") == 0))
			continue;

		sprintf(path,"%s/%s",dir_name,sdp->d_name);
		PrintName(path,sdp->d_name);
	}
	printf("\n");
    closedir(dp);
}
int main(int argc,char *argv[])
{
	ReadDir(argv[1]);
    return 0;
}
