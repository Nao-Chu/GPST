/********************************************************************
    > File Name: linkqueue.c
    > Author: zzp
    > Created Time: 2020年03月12日 星期四 02时18分34秒
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
	if (tlist == NULL)
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

void LinkList_Destory(LinkList* list)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
	return;
}

/**************************************** 
 **************************************** 
 ****************************************/
typedef void LinkQueue;
typedef struct _tag_LinkQueueNode
{
	LinkQueue* node;
	void* item;
}LinkQueueNode;

LinkQueue* LinkQueue_Create()
{
	return LinkList_Create();
}

int LinkQueue_Length(LinkQueue* queue)
{
	int size = LinkList_Length(queue);
	return size;
}

int LinkQueue_Append(LinkQueue* queue,void* item)
{
	LinkQueueNode *tmp = NULL;
	int ret = 0;
	tmp = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if (tmp == NULL)
	{
		return -1;
	}
	memset(tmp,0,sizeof(LinkQueueNode));
	tmp->item = item;
	ret = LinkList_Insert(queue,(LinkListNode *)tmp,LinkQueue_Length(queue));
	if (ret != 0)
	{
		printf("func\n");
		if (tmp != NULL)
		{
			free(tmp);
		}
	}
	return ret;
}

LinkQueue* LinkQueue_Header(LinkQueue* queue)
{
	LinkQueueNode *tmp = NULL;
	tmp = (LinkQueueNode *)LinkList_Get(queue,0);
	if (tmp == NULL)
	{
		return NULL;
	}
	return tmp->item;
}

LinkQueue* LinkQueue_Retrieve(LinkQueue* queue)
{
	LinkQueueNode *tmp = NULL;
	LinkQueueNode *ret = NULL;
	tmp = (LinkQueueNode *)LinkList_Delete(queue,0);
	if (tmp == NULL)
	{
		return NULL;
	}
	
	ret = tmp->item;
	if (tmp != NULL)
	{
		free(tmp);
	}
	
	return ret;
}

LinkQueue LinkQueue_Clear(LinkQueue* queue)
{
	if (queue == NULL)
	{
		return;
	}
	while(LinkQueue_Length(queue) > 0)
	{
		LinkQueue_Retrieve(queue);
	}
	return;
}

void LinkQueue_Destroy(LinkQueue* queue)
{
	LinkQueue_Clear(queue);
	LinkList_Destory(queue);
	return;
}

int main()
{
	int i = 0;
	int a[10];
	LinkQueue* queue = LinkQueue_Create();
	if (queue == NULL)
	{
		return -1;
	}

	for (int i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		LinkQueue_Append(queue,&a[i]);
	}
	printf("len: %d \n",LinkQueue_Length(queue));
	printf("top: %d \n",*((int*)LinkQueue_Header(queue)));

	while (LinkQueue_Length(queue) > 0)
	{
		int tmp = *((int*)LinkQueue_Retrieve(queue));
		printf("tmp = %d \t",tmp);
	}
	LinkQueue_Destroy(queue);
	return 0;
}
