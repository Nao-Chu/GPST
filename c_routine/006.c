#include <stdio.h>

void swap(int* a,int* b);
int main()
{
	int one = 10;
	int two = 20;
	int* a;
	int* b;
	a = &one;
	b = &two;
	printf("a = %d\t",*a);
	printf("b = %d\n\n",*b);
	swap(a,b);
	printf("(a--b) = (%d--%d)\n\n",*a,*b);

	swap(&one,&two);
	printf("(one--two) = (%d--%d)\n",one,two);
	return 0;
}

void swap(int* a,int* b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
	printf("(a,b) = (%d,%d)\n\n",*a,*b);
}
