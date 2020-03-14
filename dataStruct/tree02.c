/********************************************************************
    > File Name: tree02.c
    > Author: zzp
    > Created Time: 2020年03月12日 星期四 03时22分26秒
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

void inOrder(BiTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	inOrder(root->lchild);
	printf("%d ",root->data);
	inOrder(root->rchild);
}

void postOrder(BiTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%d ",root->data);
}

void countLeaf(BiTNode* T,int* sum)
{
	if (T != NULL)
	{
		if (T->lchild == NULL && T->rchild == NULL)
		{
			(*sum)++;
		}
		if (T->lchild)
		{
			countLeaf(T->lchild,sum);
		}
		if (T->rchild)
		{
			countLeaf(T->rchild,sum);
		}
	}
}

int lsum,rsum;
void Depth(BiTNode* T,int* lsum,int* rsum,int* hight)
{
	if (T == NULL)
	{
		hight = 0;
		return;
	}
	if (T->lchild)
	{
		(*lsum)++;
		Depth(T->lchild,lsum,rsum,hight);
	}
		
	if (T->rchild)
	{
		(*rsum)++;
		Depth(T->rchild,lsum,rsum,hight);
	}	
	*hight = (*lsum > *rsum ? *lsum : *rsum) + 1;
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
	
	preOrder(&t1);
	printf("\n");
	inOrder(&t1);
	printf("\n");
	postOrder(&t1);
	printf("\n");
	
	int sum = 0;
	countLeaf(&t1,&sum);
	printf("sum = %d\n",sum);
	
	int lsum = 0,rsum = 0,hight = 0;
	Depth(&t1,&lsum,&rsum,&hight);
	printf("hight =%d\n",hight);
	return 0;
} 
