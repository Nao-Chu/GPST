#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Teather{
	char **name;
}teather;

void scanf_name(teather *wan,int num);
void sort_name (teather *wan,int num);
void print_name(teather *wan,int num);
void free_wan(teather *wan,int num);

int main()
{
	int num = 3;
	teather wan;
	wan = (teather*)malloc(num*sizeof(teather));
	for (int i = 0; i < num; i++)
		wan[i].name = (char*)malloc(10*sizeof(char));
	scanf_name(wan,num);
	sort_name(wan,num);
	print_name(wan,num);
	free_wan(wan,num);
	return 0;
}

void scanf_name(teather *wan,int num)
{
	if (wan == NULL)
		return;
	for (int i = 0; i < num; i++)
		scanf("%s",wan[i].name);
	printf("\n");
}

void sort_name (teather *wan,int num)
{
	if (wan == NULL)
		return;
	char *p;
	p = NULL;
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if(strcmp(wan[i].name,wan[j].name) > 0)
			{
				p = wan[i].name;
				wan[i].name = wan[j].name;
				wan[j].name = p;
			}
		}
	}
}

void print_name(teather *wan,int num)
{
	if (wan == NULL)
		return;
	for (int i = 0; i < num; i++)
		printf("%s\n",wan[i].name);
}

void free_wan(teather *wan,int num)
{
	if (wan == NULL)
		return;
	for (int i = 0; i < num; i++)
	{
		if (wan[i].name != NULL)
		{
			free(wan[i].name);
		}

		wan[i].name = NULL;
	}
}
