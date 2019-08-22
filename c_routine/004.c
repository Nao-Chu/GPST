#include <stdio.h>

int NUM = 10;
int main()
{
	int a[NUM] = {0};
	printf("数组a的值：\n");
	for (int i = 0; i < NUM; i++){
		printf("a[%d] = %d\t",i,a[i]);
		if ( (i+1) % 5 == 0){
			printf("\n");
		}
	}
	
	printf("\n重新输入数组a的值(数组a有%d个)：\n",NUM);
	for (int i = 0; i < NUM; i++){
		printf("%d:",i+1);
		scanf("%d",&a[i]);
	}

	printf("\n现在数组a的值：\n");
	for (int i = 0; i < NUM; i++){
		printf("a[%d] = %d\t",i,a[i]);
		if ( (i+1) % 5 == 0){
			printf("\n");
		}
	}
	return 0;
}
