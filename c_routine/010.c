#include <stdio.h>

void ShellSort(int a[],int length)
{
	int increment;
	int i,j;
	int temp;
	int count = 0;
	for(increment = length * 0.5; increment > 0;increment *= 0.5){
		for (i = increment; i < length;i++){
			temp = a[i];
			for (j = i - increment;j >= 0 && temp < a[j];j -= increment){
				a[j + increment] = a[j];
			}
			a[j + increment] = temp;
			printf("%d: ",++count);
			for(int i = 0;i < 10;i++){
					printf("%d ",a[i]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
int main()
{
	int a[] = {50,10,44,24,15,11,17,32,78,41};
	printf("   ");
	for(int i = 0;i < 10;i++){
			printf("%d ",a[i]);
	}
	printf("\n");
	ShellSort(a,10);
	for(int i = 0;i < 10;i++){
			printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
