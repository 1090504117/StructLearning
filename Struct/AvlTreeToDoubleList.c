#include <stdlib.h>
#include <stdio.h>
#include "AvlTree.h"
#include "BinaryTree.h"


void ConvertBSTree2List(AvlTree pTreeRoot/*���ĸ��ڵ�*/, AvlTree *pListHead/*˫�������ͷָ��*/, AvlTree *pListLast/*˫�������βָ��*/)
{
	if (pTreeRoot == NULL) return;

	// �������������
	ConvertBSTree2List(pTreeRoot->Left, pListHead, pListLast);

	// ����ǰ�ڵ㣬�ѽڵ�����˫������β��

	// �޸ĵ�ǰ�ڵ���ָ�룬ָ����һ�����������������Ķ�βָ��
	pTreeRoot->Left = *pListLast;
	if (*pListLast)		// �ǵ�һ���ڵ㼴pListLast��ΪNULL�Ľڵ�
	{
		(*pListLast)->Right = pTreeRoot;	//��һ�����������������Ķ�βָ��ָ��ǰ�ڵ㣨˫������ɣ�
	}
	else				// ��һ���ڵ�
	{
		(*pListHead) = pTreeRoot;	//headΪpListLastΪNULL��ʱ��ֻ��һ��
	}

	*pListLast = pTreeRoot;	//�޸Ķ�βָ��ָ��Ŀǰ�ڵ�

	// �������������
	ConvertBSTree2List(pTreeRoot->Right, pListHead, pListLast);
}

void TestConvert()
{
	AvlTree root = CreatAvlTree();
	root->Element = 10;
	int num[] = { 7,5,4,3,8 };
	for (int i = 0; i < sizeof(num) / sizeof(int); i++)
	{
		Insert(num[i], root);
	}

	AvlPosition node = root;
	MiddleOrder((SearchTree)node);
	printf("\n");
	AvlTree head = NULL;
	AvlTree tail = NULL;
	ConvertBSTree2List(root, &head, &tail);

	node = root;
	while (node != NULL)
	{
		printf("%d ", node->Element);
		node = node->Left;
	}
	printf("\n");
}