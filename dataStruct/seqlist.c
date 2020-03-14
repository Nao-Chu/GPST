/********************************************************************
    > File Name: seqlist.c
    > Author: zzp
    > Created Time: 2020年03月06日 星期五 16时06分26秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef void SeqList; 
typedef void SeqListNode; 

typedef struct _tag_SeqList
{
	int length;
	int capacity;
	unsigned long *node;
}TSeqList;

SeqList* SeqList_Create(int capacity)
{
	TSeqList* tmp;
	tmp = (TSeqList*)malloc(sizeof(TSeqList));
	if (tmp == NULL)
	{
		return NULL;
	}
	memset(tmp,0,sizeof(TSeqList));

	tmp->node = (unsigned long *)malloc(sizeof(unsigned long) * capacity);
	if (tmp->node == NULL)
	{
		return NULL;
	}
	tmp->capacity = capacity;
	tmp->length = 0;
	return tmp;
}

int SeqList_Insert(SeqList* list,SeqListNode* node,int pos)
{
	TSeqList* tlist = NULL;
	tlist = (TSeqList*)list;
	int ret = 0;
	if (tlist == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		return ret;
	}

	if (tlist->length >= tlist->capacity)
	{
		ret = -2;
		return ret;
	}

	if (pos >= tlist->capacity)
	{
		pos = tlist->length;
	}

	for(int i = tlist->length; i>pos; i--)
	{
		tlist->node[i] = tlist->node[i-1];
	}
	tlist->node[pos] = (unsigned long)node;
	tlist->length++;
	return ret;
}

int SeqList_Length(SeqList* list)
{
	TSeqList* tmp = (TSeqList*) list;
	if (tmp == NULL)
	{
		return -1;
	}

	return tmp->length;
}

SeqListNode* SeqList_Get(SeqList* list,int pos)
{
	TSeqList* tlist = (TSeqList*) list;
	SeqListNode* tmp = 0;
	if (tlist == NULL)
	{
		return NULL;
	}

	if (pos > tlist->length)
	{
		return NULL;
	}
	tmp = (SeqListNode *)tlist->node[pos];
	return tmp;
}

int SeqList_Delete(SeqList* list,int pos)
{
	TSeqList* tlist = NULL;
	tlist = (TSeqList*) list;
	int ret = 0;
	if (tlist == NULL)
	{
		ret = -1;
		return ret;
	}

	if (pos > tlist->length)
	{
		ret -2;
		return ret;
	}
	for(int i = pos; i < tlist->length; i++)
	{
		tlist->node[i] = tlist->node[i+1];
	}
	tlist->length--;
	return ret;
}

typedef struct Teacher
{
	int age;	
	char name[64];
}Teacher;

int main()
{
	SeqList* list = NULL;
	int ret;
	Teacher t1,t2,t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	list = SeqList_Create(10);
	if (list == NULL)
	{
		return -1;
	}

	ret = SeqList_Insert(list,(SeqListNode*) &t1,0);
	if (ret != 0)
	{
		return ret;
	}
	ret = SeqList_Insert(list,(SeqListNode*) &t2,1);
	if (ret != 0)
	{
		return ret;
	}
	ret = SeqList_Insert(list,(SeqListNode*) &t3,0);
	if (ret != 0)
	{
		return ret;
	}

	for (int i = 0; i < SeqList_Length(list); i++)
	{
		Teacher* tmp = (Teacher*) SeqList_Get(list,i);
		if(tmp == NULL)
		{
			return -2;
		}
		printf("age = %d \n",tmp->age);
	}

	
	while(SeqList_Length(list)>0)
	{
		SeqList_Delete(list,0);
	}
	
	return 0;
}
