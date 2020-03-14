/********************************************************************
    > File Name: tree04.c
    > Author: zzp
    > Created Time: 2020年03月14日 星期六 16时12分54秒
 *******************************************************************/

#include<stdlib.h> 
#include<stdio.h>
#include<string.h>

typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode;

void preOrder(BiTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ",root->data);
	preOrder(root->lchild);
	preOrder(root->rchild);
}

BiTNode* CreateBiThrTree(BiTNode *T)
{
	BiTNode *node = NULL;
	BiTNode *pL = NULL;
	BiTNode *pR = NULL;
	char h;
	scanf("%c",&h);

	if (h == '#')
	{
		return NULL;
	}
	else
	{
		node = (BiTNode*)malloc(sizeof(BiTNode));
		T = (BiTNode*)malloc(sizeof(BiTNode));
		memset(node,0,sizeof(BiTNode));
		node->data = (int)h - 48;
		pL = CreateBiThrTree(T->lchild);
		if (pL != NULL)
		{
			node->lchild = pL;
		}
		pR = CreateBiThrTree(T->rchild);
		if (pR != NULL)
		{
			node->rchild = pR;
		}
	}

	return node;

}

int main()
{
	BiTNode *p = NULL; 
	p = CreateBiThrTree(p);
	preOrder(p);
	printf("\n");
	return 0;
} 
