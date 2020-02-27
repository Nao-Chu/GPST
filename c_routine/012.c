#include<stdio.h>
#include<string.h>
#include<stdlib.h>

	char tmp[10][30];
void split(char* str,char** p,char target);
int main()
{
	char* str = "abcd,efg,hijk";
	char target = ',';
	char** p;
	p = (char**) malloc(10 * sizeof(char*));
	for (int i = 0; i < 10; i++)
	{
		p[i] = (char*)malloc(30 * sizeof(char)); 
	}
	split(str,p,target);
	return 0;
}

void split(char* str,char** p,char target)
{
	char* mystr;
	char tstr = target;
	char* head;
	mystr = str;
	head = str;
	int num = 0;
	do{
		mystr = strchr(mystr,tstr);
		if(mystr!=NULL)
		{
			if (mystr-head > 0)
			{
				strncpy(p[num],head,mystr-head);
				p[num][mystr-head] = '\0';
				num++;
				mystr = head = mystr + 1;
			}
		}
		else
			break;
	}while(*mystr != '0');
	strncpy(p[num],head,strlen(head));
	p[num][strlen(head)] = '\0';
	
	for (int i = 0; i <= num;i++)
		printf("tmp = %s\n",p[i]);
}
