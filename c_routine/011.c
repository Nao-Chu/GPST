#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void findcount(char *mstr,int *count,const char *findstr);
int main()
{
	char mystr[100] = "abcd111abcd333abcd123abc432abcd";
	const char *findstr = "abcd";
	int count = 0;
	printf("mystr = %s\n",mystr);
	findcount(mystr,&count,findstr);
	printf("num = %d\n",count);
	printf("mystr = %s\n",mystr);
	return 0;
}
void findcount(char *mstr,int *count,const char *findstr)
{
	char *p;
	const char *tarstr;
	char swap;
	int number = 0;
	p = mstr;
	tarstr = findstr;
	do
	{
		p = strstr(p,tarstr);
		if(p != NULL)
		{
			int len = strlen(tarstr);
			for (int i = 0; i < len / 2; i++)
			{
				swap = *(p+i);
				*(p+i) = *(p+len-i-1);
				*(p+len-i-1) = swap;
			} 
			number++;
			p += strlen(tarstr);
		}
		else
			break;
	}while(*p != 0);
	*count = number;
}
