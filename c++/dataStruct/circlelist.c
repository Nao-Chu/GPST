/********************************************************************
    > File Name: circlelist.c
    > Author: zzp
    > Created Time: 2020年03月06日 星期五 20时56分39秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef void CircleList; 
typedef struct _tag_CircleListNode
{
	struct _tag_CircleListNode* next;
}CircleListNode;

typedef struct _tag_CircleList
{
	CircleListNode header;
	CircleListNode* slider;
	int length;
}TCircleList;

CircleList* CircleList_Create()
{
	TCircleList* tmp = NULL;
	tmp = (TCircleList*)malloc(sizeof(TCircleList));
	if (tmp == NULL)
	{
		return NULL;
	}
	memset(tmp,0,sizeof(TCircleList));

	tmp->length = 0;
	tmp->header.next=NULL;
	tmp->slider = NULL;
	return tmp;
}

CircleListNode* CircleList_Get(CircleList* list,int pos)
{
	CircleListNode* current = NULL;
	TCircleList* tlist = (TCircleList*) list;
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

int CircleList_Insert(CircleList* list,CircleListNode* node,int pos)
{
	TCircleList* tlist = (TCircleList*)list;
	int ret = 0;
	if (tlist == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		return ret;
	}

	CircleListNode* current = (CircleListNode*)tlist;

	for(int i = 0; i < pos && (current->next!=NULL); i++)
	{
		current = current->next;
	}
	node->next = current->next;
	current->next = node; 

	if(tlist->length == 0)
	{
		tlist->slider = node;
	}
	tlist->length++;

	if (current == (CircleListNode*)tlist)
	{
		CircleListNode* last = CircleList_Get(tlist,tlist->length-1);
		last->next = current->next; 
	}
	return ret;
}

int CircleList_Length(CircleList* list)
{
	TCircleList* tmp = (TCircleList*) list;
	if (tmp == NULL)
	{
		return -1;
	}

	return tmp->length;
}

CircleListNode* CircleList_Delete(CircleList* list,int pos)
{
	CircleListNode* ret = NULL;
	TCircleList* tlist = NULL;
	tlist = (TCircleList*) list;
	if (tlist == NULL || pos < 0 || tlist->length < 0)
	{
		return NULL;
	}

	CircleListNode* current = (CircleListNode*)tlist;

	for(int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	ret = current->next;
	current->next = ret->next; 
	if (current == (CircleListNode*)tlist)
	{
		CircleListNode* last = CircleList_Get(tlist,tlist->length-1);
		last->next = ret->next;
	}
	tlist->length--;

	if (tlist->slider == ret)
	{
		tlist->slider = ret->next;
	}

	if (tlist->length == 0)
	{
		tlist->header.next == NULL;
		tlist->slider = NULL;
	}
	return ret;
}

CircleListNode* CircleList_DeleteNode(CircleList* list,CircleListNode* node)
{
	CircleListNode* ret = NULL;
	TCircleList* tlist = (TCircleList*) list;
	if (tlist == NULL) 
	{
		return NULL;
	}

	CircleListNode* current = (CircleListNode*)tlist;

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
		CircleList_Delete(tlist,tlist->length);
	}
	return ret;
}

typedef struct Teacher
{
	CircleListNode node;
	int age;	
	char name[64];
}Teacher;

int main()
{
	CircleList* list = NULL;
	int ret;
	Teacher t1,t2,t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	list = CircleList_Create();
	if (list == NULL)
	{
		return -1;
	}

	ret = CircleList_Insert(list,(CircleListNode*) &t1,1);
	if (ret != 0)
	{
		return ret;
	}
	ret = CircleList_Insert(list,(CircleListNode*) &t2,0);
	if (ret != 0)
	{
		return ret;
	}
	ret = CircleList_Insert(list,(CircleListNode*) &t3,1);
	if (ret != 0)
	{
		return ret;
	}

	for (int i = 0; i < CircleList_Length(list); i++)
	{
		Teacher* tmp = (Teacher*) CircleList_Get(list,i);
		if(tmp == NULL)
		{
			return -2;
		}
		printf("age = %d \n",tmp->age);
	}

	
	while(CircleList_Length(list)>0)
	{
		CircleList_Delete(list,0);
	}
	return 0;
}
