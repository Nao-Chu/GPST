/********************************************************************
    > File Name: dlinklist.c
    > Author: zzp
    > Created Time: 2020年03月06日 星期五 23时17分25秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef void DLinkList; 
typedef struct _tag_DLinkListNode
{
	struct _tag_DLinkListNode* next;
	struct _tag_DLinkListNode* pre;
}DLinkListNode;

typedef struct _tag_DLinkList
{
	DLinkListNode header;
	DLinkListNode* slider;
	int length;
}TDLinkList;

DLinkList* DLinkList_Create()
{
	TDLinkList* tmp = NULL;
	tmp = (TDLinkList*)malloc(sizeof(TDLinkList));
	if (tmp == NULL)
	{
		return NULL;
	}
	memset(tmp,0,sizeof(TDLinkList));

	tmp->length = 0;
	tmp->header.next=NULL;
	tmp->header.pre=NULL;
	tmp->slider = NULL;
	return tmp;
}

DLinkListNode* DLinkList_Get(DLinkList* list,int pos)
{
	DLinkListNode* current = NULL;
	TDLinkList* tlist = (TDLinkList*) list;
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

int DLinkList_Insert(DLinkList* list,DLinkListNode* node,int pos)
{
	TDLinkList* tlist = (TDLinkList*)list;
	int ret = 0;
	if (tlist == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		return ret;
	}

	DLinkListNode* current = (DLinkListNode*)tlist;
	DLinkListNode* next = NULL; 

	for(int i = 0; i < pos && (current->next!=NULL); i++)
	{
		current = current->next;
	}
	next = current->next;
	node->next = next;
	current->next = node; 
	
	if (next != NULL)
	{
		next->pre = node;
	}
	node->pre = current;

	if(tlist->length == 0)
	{
		tlist->slider = node;
	}

	if (current == (DLinkListNode*)tlist)
	{
		node->pre = NULL; 
	}
	tlist->length++;
	return ret;
}

int DLinkList_Length(DLinkList* list)
{
	TDLinkList* tmp = (TDLinkList*) list;
	if (tmp == NULL)
	{
		return -1;
	}

	return tmp->length;
}

DLinkListNode* DLinkList_Delete(DLinkList* list,int pos)
{
	DLinkListNode* ret = NULL;
	TDLinkList* tlist = NULL;
	tlist = (TDLinkList*) list;
	if (tlist == NULL || pos < 0 || tlist->length <= 0)
	{
		return NULL;
	}

	DLinkListNode* current = (DLinkListNode*)tlist;
	DLinkListNode* next = NULL; 

	for(int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	ret = current->next;
	next = ret->next; 
	current->next = next;
	if(next != NULL)
	{
		next->pre = current;
		if (current == (DLinkListNode*)tlist)
		{
			next->pre = NULL;
		}
	}

	if (tlist->slider == ret)
	{
		tlist->slider = next;
	}

	tlist->length--;
	if (tlist->length == 0)
	{
		tlist->header.next == NULL;
		tlist->slider = NULL;
	}
	return ret;
}

DLinkListNode* DLinkList_DeleteNode(DLinkList* list,DLinkListNode* node)
{
	DLinkListNode* ret = NULL;
	TDLinkList* tlist = (TDLinkList*) list;
	if (tlist == NULL) 
	{
		return NULL;
	}

	DLinkListNode* current = (DLinkListNode*)tlist;

	for(int i = 0; i < tlist->length; i++)
	{
		if (current->next == node)
		{
			ret = current->next;
			break;
		}
		current = current->next;
	}
	
	if (ret != NULL)
	{
		DLinkList_Delete(tlist,tlist->length);
	}
	return ret;
}

typedef struct Teacher
{
	DLinkListNode node;
	int age;	
	char name[64];
}Teacher;

int main()
{
	DLinkList* list = NULL;
	int ret;
	Teacher t1,t2,t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	list = DLinkList_Create();
	if (list == NULL)
	{
		return -1;
	}

	ret = DLinkList_Insert(list,(DLinkListNode*) &t1,0);
	if (ret != 0)
	{
		return ret;
	}
	ret = DLinkList_Insert(list,(DLinkListNode*) &t2,1);
	if (ret != 0)
	{
		return ret;
	}
	ret = DLinkList_Insert(list,(DLinkListNode*) &t3,3);
	if (ret != 0)
	{
		return ret;
	}

	for (int i = 0; i < DLinkList_Length(list); i++)
	{
		Teacher* tmp = (Teacher*) DLinkList_Get(list,i);
		if(tmp == NULL)
		{
			printf("tmp == NULL\n");
			return -2;
		}
		printf("age = %d \n",tmp->age);
	}

	
	while(DLinkList_Length(list)>0)
	{
		DLinkList_Delete(list,0);
	}
	return 0;
}
