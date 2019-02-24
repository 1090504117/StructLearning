#include "BinaryTree.h"
#include <stdlib.h>
#include "fatal.h"
#include "BinaryTreeFindPath.h"

 void BinaryTreeFindPathPrint(pPath L)//打印树节点
 {
	pPath p = L->next;
	while (NULL != p)
	{
		printf("%d ", p->tree->Element);
		p = p->next;
	}
	printf("\n");
}

pPath BinaryTreeFindPathInit() // 初始化
{
	pPath p = (pPath)malloc(sizeof(struct Path));
	if(NULL == p)
	{
		Error("init_path malloc failure.\n");
	}
	p->next = NULL;
	return p;
}

void BinaryTreeFindPathPop(pPath L) //树节点 出栈
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
	free(q->next); // 树节点出栈
	q->next = NULL;
}


void BinaryTreeFindPathPush(pPath L, SearchTree T) //树节点 入栈
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

	q->next = p; //树节点入栈
}

void BinaryTreeFindPath(SearchTree T, int sum, pPath L,int record) //查找所有路径
{
	BinaryTreeFindPathPush(L, T); //将该树节点入栈
	record += T->Element;
	if ((sum == record) && (IsBinaryTreeLeftNode(T))) //递归+回溯 查找到合适路劲
		BinaryTreeFindPathPrint(L); // 打印相应的路径
	
	if (NULL != T->Left) //继续查找左子树
		BinaryTreeFindPath(T->Left, sum, L, record);
	
	if (NULL != T->Right) // 继续查找右子树
		BinaryTreeFindPath(T->Right, sum, L, record);
	
	record -= T->Element; //回溯		前序遍历的思路，先父节点后子节点，节点完成后删除父节点
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