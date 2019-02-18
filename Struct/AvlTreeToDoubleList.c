#include <stdlib.h>
#include <stdio.h>
#include "AvlTree.h"
#include "BinaryTree.h"


void ConvertBSTree2List(AvlTree pTreeRoot/*树的根节点*/, AvlTree *pListHead/*双向链表的头指针*/, AvlTree *pListLast/*双向链表的尾指针*/)
{
	if (pTreeRoot == NULL) return;

	// 中序遍历左子树
	ConvertBSTree2List(pTreeRoot->Left, pListHead, pListLast);

	// 处理当前节点，把节点链到双向链表尾部

	// 修改当前节点左指针，指向上一次中序遍历左子树后的队尾指针
	pTreeRoot->Left = *pListLast;
	if (*pListLast)		// 非第一个节点即pListLast不为NULL的节点
	{
		(*pListLast)->Right = pTreeRoot;	//上一次中序遍历左子树后的队尾指针指向当前节点（双链接完成）
	}
	else				// 第一个节点
	{
		(*pListHead) = pTreeRoot;	//head为pListLast为NULL的时候，只有一次
	}

	*pListLast = pTreeRoot;	//修改队尾指针指向目前节点

	// 中序遍历右子树
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