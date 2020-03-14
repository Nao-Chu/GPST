/********************************************************************
    > File Name: linklist.c
    > Author: zzp
    > Created Time: 2020年03月06日 星期五 18时39分26秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef void LinkList; 
typedef struct _tag_LinkListNode
{
	struct _tag_LinkListNode* next;
}LinkListNode;

typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;
}TLinkList;

LinkList* LinkList_Create()
{
	TLinkList* tmp = NULL;
	tmp = (TLinkList*)malloc(sizeof(TLinkList));
	if (tmp == NULL)
	{
		return NULL;
	}
	memset(tmp,0,sizeof(TLinkList));

	tmp->length = 0;
	tmp->header.next=NULL;
	return tmp;
}

int LinkList_Insert(LinkList* list,LinkListNode* node,int pos)
{
	LinkListNode* current = NULL;
	TLinkList* tlist = (TLinkList*)list;
	int ret = 0;
	if (tlist == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		return ret;
	}

	current = &(tlist->header);

	for(int i = 0; i < pos && (current->next!=NULL); i++)
	{
		current = current->next;
	}
	node->next = current->next;
	current->next = node; 
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
	LinkListNode* current = NULL;
	TLinkList* tlist = (TLinkList*) list;
	if (tlist == NULL || pos < 0)
	{
		return NULL;
	}

	current = &(tlist->header);
	for(int i = 0; i < pos && (current->next!=NULL); i++)
	{
		current = current->next;
	}
	return current->next;
}

LinkListNode* LinkList_Delete(LinkList* list,int pos)
{
	LinkListNode* current = NULL;
	LinkListNode* ret = NULL;
	TLinkList* tlist = NULL;
	tlist = (TLinkList*) list;
	if (tlist == NULL || tlist->length == 0)
	{
		return NULL;
	}

	if (pos > tlist->length)
	{
		return NULL;
	}
	current = &(tlist->header);

	for(int i = 0; i < pos && (current->next!=NULL); i++)
	{
		current = current->next;
	}
	ret = current->next;
	current->next = ret->next; 
	tlist->length--;
	return ret;
}

typedef struct Teacher
{
	LinkListNode node;
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

	list = LinkList_Create();
	if (list == NULL)
	{
		return -1;
	}

	ret = LinkList_Insert(list,(LinkListNode*) &t1,0);
	if (ret != 0)
	{
		return ret;
	}
	ret = LinkList_Insert(list,(LinkListNode*) &t2,0);
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
