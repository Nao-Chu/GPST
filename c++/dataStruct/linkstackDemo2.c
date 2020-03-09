/********************************************************************
    > File Name: linkstackDemo2.c
    > Author: zzp
    > Created Time: 2020年03月09日 星期一 21时39分43秒
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
	if (tlist == NULL || tlist->length <= 0 || pos > tlist->length)
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
typedef void LinkStack;
typedef struct _tag_LinkStackNode
{
	LinkListNode node;
	void* item;
}LinkStackNode;

LinkStack* LinkStack_Create()
{
	return LinkList_Create();
}

int LinkStack_Push(LinkStack* stack,void* item)
{
	LinkStackNode *tmp = NULL;
	int ret = 0;
	tmp = (LinkStackNode *)malloc(sizeof(LinkStackNode));
	if (tmp == NULL)
	{
		return -1;
	}
	memset(tmp,0,sizeof(LinkStackNode));
	tmp->item = item;
	ret = LinkList_Insert(stack,(LinkListNode *)tmp,0);
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

void* LinkStack_Pop(LinkStack* stack)
{
	void* item = NULL;
	LinkStackNode *tmp = NULL;
	tmp = (LinkStackNode *)LinkList_Delete(stack,0);
	if (tmp == NULL)
	{
		return NULL;
	}
	item = tmp->item;
	free(tmp);
	return item;
}

void* LinkStack_Top(LinkStack* stack)
{
	LinkStackNode *tmp = NULL;
	tmp = (LinkStackNode *)LinkList_Get(stack,0);
	if (tmp == NULL)
	{
		return NULL;
	}
	return tmp->item;
}

int LinkStack_Size(LinkStack* stack)
{
	int size = LinkList_Length(stack);
	return size;
}

void LinkStack_Clear(LinkStack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	while(LinkList_Length(stack) > 0)
	{
		LinkStack_Pop(stack);
	}
	return;
}

void LinkStack_Destroy(LinkStack* stack)
{
	LinkStack_Clear(stack);
	LinkList_Destory(stack);
	return;
}

bool isNumber(const char code)
{
	return (code >= '0' && code <= '9');
}

bool isLeft(const char code)
{
	return (code == '(');
}

bool isRight(const char code)
{
	return (code == ')');
}

bool isOperator(const char code)
{
	bool ret = false;
	switch(code)
	{
		case '+':
		case '-':
		case '*':
		case '/':
			ret = true;
			break;

		default:
			break;
	}
	return ret;
}

int priority(const char code)
{
	int ret = 0;
	if (code == '+' || code == '-')
	{
		ret = 1;
	}

	if (code == '*' || code == '/')
	{
		ret = 2;
	}

	return ret;
}

void output(const char code)
{
	printf("%c",code);
}

void transform(const char* code)
{
	LinkStack* stack = LinkStack_Create();
	int ret = 0;
	int i = 0;

	while (code[i] != '\0')
	{
		if (isNumber(code[i]))
		{
			output(code[i]);
		}
		else if (isOperator(code[i]))
		{
			char* a = (char*)LinkStack_Top(stack);
			if(a != NULL)
			{
				while(priority(code[i]) <= priority(*a))
				{
					output(*(char*)LinkStack_Pop(stack));
					a = (char*)LinkStack_Top(stack);
					if (a == NULL)
					{
						break;
					}
				}

			}
			LinkStack_Push(stack,(char*)(code + i));
		}
		else if (isLeft(code[i]))
		{
			LinkStack_Push(stack,(char*)(code + i));
		}
		else if (isRight(code[i]))
		{
			while(!isLeft(*(char*)LinkStack_Top(stack)))
			{
				output(*(char*)LinkStack_Pop(stack));
			}
			LinkStack_Pop(stack);
		}
		else
		{
			printf("Invalid expression!");
			break;
		}
		i++;
	}
	while (LinkStack_Size(stack) > 0 && code[i] == '\0')
	{
		output(*(char*)LinkStack_Pop(stack));
	}
}

int main()
{
	const char* code = "8*3-1+5";
	transform(code);
	return 0;
}
