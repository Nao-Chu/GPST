/********************************************************************
    > File Name: tree03.c
    > Author: zzp
    > Created Time: 2020年03月12日 星期四 04时31分32秒
 *******************************************************************/

#include<stdlib.h> 
#include<stdio.h>
#include<string.h>

// 二叉链表 
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

BiTNode* CopyTree(BiTNode* T)
{
	BiTNode *newT = NULL;
	BiTNode *newLp = NULL;
	BiTNode *newRp = NULL;
	if (T == NULL)
	{
		return NULL;
	}
	
	if (T->lchild)
	{
		newLp = CopyTree(T->lchild);
	}
	else
	{
		newLp = NULL;
	}
		
	if (T->rchild)
	{
		newRp = CopyTree(T->rchild);
	}
	else
	{
		newRp = NULL;
	}
	
	newT = (BiTNode *)malloc(sizeof(BiTNode));
	memset(newT,0,sizeof(BiTNode));
	newT->lchild = newLp;
	newT->rchild = newRp;
	newT->data = T->data;
	if (newT == NULL)
	{
		return NULL;
	}
	
	return newT;
}

int main()
{
	BiTNode t1,t2,t3,t4,t5;
	memset(&t1,0,sizeof(BiTNode));
	memset(&t2,0,sizeof(BiTNode));
	memset(&t3,0,sizeof(BiTNode));
	memset(&t4,0,sizeof(BiTNode));
	memset(&t5,0,sizeof(BiTNode));
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;
	
	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t2.rchild = &t5;
	
	BiTNode* CopyT;
	CopyT = CopyTree(&t1);
	preOrder(&t1);
	printf("\n");
	preOrder(CopyT);
	return 0;
} 
