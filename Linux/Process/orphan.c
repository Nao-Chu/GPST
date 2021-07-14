#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid = fork();
	if(pid == 0){
		while(1){
			printf("I'am child, my parent pid = %d\n",getppid());
			sleep(1);
		}
	} else if(pid >0){
		printf("I'am parent, my pid = %d\n",getpid());
		sleep(5);
		printf("---------------parent going to die---------------\n");
	} else {
		perror("fork");
		return 1;
	}

	return 0;
}
