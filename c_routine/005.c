#include <stdio.h>
void swap(int a,int b);
int change(int a,int b);
int main()
{
	int a = 3;
	int b = 4;
	swap(a,b);
	printf("(a--b) = (%d--%d)\n",a,b);
	b = change(3,4);
	printf("(a++b) = (%d++%d)\n",a,b);
	return 0;
}

void swap(int a,int b)
{
	int t = 0;
	t = a;
	a = b;
	b = t;
	printf("(a,b) = (%d,%d)\n",a,b);
}

int change(int a,int b)
{
	b = a;	
	return b;
}
