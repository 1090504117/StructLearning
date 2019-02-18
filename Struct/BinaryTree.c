#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include "fatal.h"

void MiddleOrder(SearchTree node)
{
	if (node != NULL) {
		MiddleOrder(node->Left);
		printf("%d ", node->Element);
		MiddleOrder(node->Right);
	}
}

SearchTree CreateBinaryTree()
{
	SearchTree T = (SearchTree)malloc(sizeof(struct BinaryTreeNode));
	if (T == NULL) Error("there is not enough memory");
	return T;
}

SearchTree MakeBinaryTreeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeBinaryTreeEmpty(T->Left);
		MakeBinaryTreeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position FindBinaryTreeElement(ElementType ele, SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (ele < T->Element)
		return FindBinaryTreeElement(ele, T->Left);
	else
		if(ele > T->Element)
			return FindBinaryTreeElement(ele, T->Right);
	return T;
}
//最小元
Position FindBinaryTreeMin(SearchTree T)
{
	if (T == NULL)
		return NULL;
	else
		if (T->Left == NULL)
			return T;
		else
			return FindBinaryTreeMin(T->Left);
}

//最大元
Position FindBinaryTreeMax(SearchTree T)
{
	if(T != NULL)
		while (T->Right != NULL)
		{
			T = T->Right;
		}
	return T;
}

SearchTree InsertBinaryTreeElement(ElementType ele, SearchTree T)
{
	if (T == NULL)
	{
		T = (SearchTree)malloc(sizeof(struct BinaryTreeNode));
		if (T == NULL)
		{
			printf("Out of memory");
			return NULL;
		}
		else
		{
			T->Element = ele;
			T->Left = T->Right = NULL;
		}
	}
	else
	{
		if (ele < T->Element)
			T->Left = InsertBinaryTreeElement(ele, T->Left);
		else
			if(ele > T->Element)
				T->Right = InsertBinaryTreeElement(ele, T->Right);
	}
	return T;
}

SearchTree DeleteBinaryTreeNode(ElementType ele, SearchTree T)
{

}