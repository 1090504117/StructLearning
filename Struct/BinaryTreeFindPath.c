#include "BinaryTree.h"
#include <stdlib.h>
#include "fatal.h"
#include "BinaryTreeFindPath.h"

 void BinaryTreeFindPathPrint(pPath L)//��ӡ���ڵ�
 {
	pPath p = L->next;
	while (NULL != p)
	{
		printf("%d ", p->tree->Element);
		p = p->next;
	}
	printf("\n");
}

pPath BinaryTreeFindPathInit() // ��ʼ��
{
	pPath p = (pPath)malloc(sizeof(struct Path));
	if(NULL == p)
	{
		Error("init_path malloc failure.\n");
	}
	p->next = NULL;
	return p;
}

void BinaryTreeFindPathPop(pPath L) //���ڵ� ��ջ
{
	pPath p = L->next;
	pPath q = L;

	if (NULL == p)
	{
		printf("pop_path stack is NULL!\n");
		return;
	}
	p = p->next;
	while (NULL != p)
	{
		p = p->next;
		q = q->next;
	}
	free(q->next); // ���ڵ��ջ
	q->next = NULL;
}


void BinaryTreeFindPathPush(pPath L, SearchTree T) //���ڵ� ��ջ
{
	pPath p = L->next;
	pPath q = L;

	while (NULL != p)
	{
		q = p;
		p = p->next;
	}
	p = (pPath)malloc(sizeof(struct Path));
	if (NULL == p)
	{
		printf("push_path malloc failure.\n");
	}
	p->tree = T;
	p->next = NULL;

	q->next = p; //���ڵ���ջ
}

void BinaryTreeFindPath(SearchTree T, int sum, pPath L,int record) //��������·��
{
	BinaryTreeFindPathPush(L, T); //�������ڵ���ջ
	record += T->Element;
	if ((sum == record) && (IsBinaryTreeLeftNode(T))) //�ݹ�+���� ���ҵ�����·��
		BinaryTreeFindPathPrint(L); // ��ӡ��Ӧ��·��
	
	if (NULL != T->Left) //��������������
		BinaryTreeFindPath(T->Left, sum, L, record);
	
	if (NULL != T->Right) // ��������������
		BinaryTreeFindPath(T->Right, sum, L, record);
	
	record -= T->Element; //����		ǰ�������˼·���ȸ��ڵ���ӽڵ㣬�ڵ���ɺ�ɾ�����ڵ�
	BinaryTreeFindPathPop(L);
}

void BinaryTreeFindPathTest()
{
	pPath p = BinaryTreeFindPathInit();
	SearchTree tree = NULL;
	int a[] = {10,5,4,7,12};
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
		tree = InsertBinaryTreeElement(a[i], tree);
	MiddleOrder(tree);
	printf("\n");
	int sum = 22;
	int record = 0;
	BinaryTreeFindPath(tree, sum, p,record);
}