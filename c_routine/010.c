#include <stdio.h>

void FastSort(int *a,int low,int high)
{
	if (low < high){
		int i = low;
		int j = high;
		int k = a[low];
		while(i < j){
			while(i < j && a[j] >= k){
				j--;
			}
			if (i < j){
				a[i++] = a[j];
			}

			while(i < j && a[i] < k){
				i++;
			}
			if (i < j){
				a[j--] = a[i];
			}
		}
		a[i] = k;
		FastSort(a,low,i - 1);
		FastSort(a,i + 1,high);
	}
}

void Print(int a[])
{
	for(int i = 0;i < 10;i++){
			printf("%d ",a[i]);
	}
	printf("\n");
}
int main()
{
	int a[] = {50,10,44,24,15,11,17,32,78,41};
	Print(a);
	FastSort(a,0,9);
	Print(a);
	return 0;
}
