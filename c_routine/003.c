#include <stdio.h>

int main()
{
	int j = 0;
	int k = 0;
	for(int i =0;i < 3;i++){
		printf("i = %d\n",i);
	}
	printf("\n");
	while(j>3)
	{
		printf("j = %d\n",j);
		j++;
	}
	printf("最终 j = %d\n",j);
	printf("\n");
	do
	{
		printf("k = %d\n",k);
		k++;
	}while(k>3);
	printf("最终 k = %d\n",k);
	return 0;
}
