#include <stdio.h>
#include <string.h>

int main()
{
	char str1[12] = "Hello ";
	const char* str2 = "World";
	printf("str1 = %s\n",str1);
	printf("str2 = %s\n",str2);
	return 0;
}
