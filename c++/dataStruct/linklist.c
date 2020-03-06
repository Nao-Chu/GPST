/********************************************************************
    > File Name: linklist.c
    > Author: zzp
    > Created Time: 2020年03月06日 星期五 18时39分26秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef void LinkList; 
typedef void LinkListNode; 

typedef struct _tag_LinkList
{
	int length;
	int capacity;
	unsigned long *node;
}TLinkList;

LinkList* LinkList_Create(int capacity)
{
	TLinkList* tmp;
	tmp = (TLinkList*)malloc(sizeof(TLinkList));
	if (tmp == NULL)
	{
		return NULL;
	}
	memset(tmp,0,sizeof(TLinkList));

	tmp->node = (unsigned long *)malloc(sizeof(unsigned long) * capacity);
	if (tmp->node == NULL)
	{
		return NULL;
	}
	tmp->capacity = capacity;
	tmp->length = 0;
	return tmp;
}

int LinkList_Insert(LinkList* list,LinkListNode* node,int pos)
{
	TLinkList* tlist = NULL;
	tlist = (TLinkList*)list;
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

int LinkList_Length(LinkList* list)
{
	TLinkList* tmp = (TLinkList*) list;
	if (tmp == NULL)
	{
		return -1;
	}

	return tmp->length;
}

LinkListNode* LinkList_Get(LinkList* list,int pos)
{
	TLinkList* tlist = (TLinkList*) list;
	LinkListNode* tmp = 0;
	if (tlist == NULL)
	{
		return NULL;
	}

	if (pos > tlist->length)
	{
		return NULL;
	}
	tmp = (LinkListNode *)tlist->node[pos];
	return tmp;
}

int LinkList_Delete(LinkList* list,int pos)
{
	TLinkList* tlist = NULL;
	tlist = (TLinkList*) list;
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
	LinkList* list = NULL;
	int ret;
	Teacher t1,t2,t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	list = LinkList_Create(10);
	if (list == NULL)
	{
		return -1;
	}

	ret = LinkList_Insert(list,(LinkListNode*) &t1,0);
	if (ret != 0)
	{
		return ret;
	}
	ret = LinkList_Insert(list,(LinkListNode*) &t2,1);
	if (ret != 0)
	{
		return ret;
	}
	ret = LinkList_Insert(list,(LinkListNode*) &t3,0);
	if (ret != 0)
	{
		return ret;
	}

	for (int i = 0; i < LinkList_Length(list); i++)
	{
		Teacher* tmp = (Teacher*) LinkList_Get(list,i);
		if(tmp == NULL)
		{
			return -2;
		}
		printf("age = %d \n",tmp->age);
	}

	
	while(LinkList_Length(list)>0)
	{
		LinkList_Delete(list,0);
	}
	
	return 0;
}
