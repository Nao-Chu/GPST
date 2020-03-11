/********************************************************************
    > File Name: seqqueue.c
    > Author: zzp
    > Created Time: 2020年03月12日 星期五 1时36分22秒
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

SeqListNode* SeqList_Delete(SeqList* list,int pos)
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
	for(int i = pos; i < tlist->length; i++)
	{
		tlist->node[i] = tlist->node[i+1];
	}
	tlist->length--;
	return tmp;
}

typedef void SeqQueue; 
SeqQueue* SeqQueue_Create(int capacity)
{
	return SeqList_Create(capacity);
}

int SeqQueue_Length(SeqQueue* queue)
{
	return SeqList_Length(queue);
}

int SeqQueue_Append(SeqQueue* queue,void* item)
{
	return SeqList_Insert(queue,item,SeqQueue_Length(queue));
}

SeqQueue* SeqQueue_Header(SeqQueue* queue)
{
	return SeqList_Get(queue,0);
}

SeqQueue* SeqQueue_Retrieve(SeqQueue* queue)
{
	return SeqList_Delete(queue,0);
}
int main()
{
	int ret;
	int i = 0;
	int a[10];
	SeqQueue* queue = NULL;
	queue = SeqQueue_Create(10);
	if (queue == NULL)
	{
		return;
	}

	for (i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		ret = SeqQueue_Append(queue,&a[i]);
		
	}
	printf("len: %d \n",SeqQueue_Length(queue));
	printf("header: %d \n",*((int*)SeqQueue_Header(queue)));

	while (SeqQueue_Length(queue) > 0)
	{
		int tmp = *((int*)SeqQueue_Retrieve(queue));
		printf("tmp = %d \t",tmp);
	}
	
	return 0;
}
