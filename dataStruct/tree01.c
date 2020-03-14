/********************************************************************
    > File Name: tree01.c
    > Author: zzp
    > Created Time: 2020��03��12�� ������ 03ʱ15��30��
 *******************************************************************/

#include<stdlib.h> 
#include<stdio.h>

typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode;

// �������� 
int main01()
{
	BiTNode t1,t2,t3,t4,t5;
	
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;
	
	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.lchild = &t5;
	
	BiTNode *p1,*p2,*p3,*p4,*p5;
	p1 = (BiTNode *)malloc(sizeof(BiTNode));
	p2 = (BiTNode *)malloc(sizeof(BiTNode));
	p3 = (BiTNode *)malloc(sizeof(BiTNode));
	p4 = (BiTNode *)malloc(sizeof(BiTNode));
	p5 = (BiTNode *)malloc(sizeof(BiTNode));
	
	p1->data = 1;
	p2->data = 2;
	p3->data = 3;
	p4->data = 4;
	p5->data = 5;
	
	p1->lchild = p2;
	p1->rchild = p3;
	p2->lchild = p4;
	p3->lchild = p5;
	return 0;
} 

// ˫������
typedef struct BPTNode
{
	int data;
	int parentPosition;
	char LRTag;
}BPTNode;

typedef struct BPTree
{
	BPTNode nodes[100];
	int num_node;
	int root;
}BPTree; 

int main()
{
	BPTree tree;
	tree.nodes[0].parentPosition = 1000;
	tree.nodes[1].parentPosition = 0;
	tree.nodes[1].data = 'B';
	tree.nodes[1].LRTag = 1;
	
	tree.nodes[2].parentPosition = 0;
	tree.nodes[2].data = 'C';
	tree.nodes[2].LRTag = 2;
	return 0;
} 
