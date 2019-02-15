#include "AvlTree.h"
#include <stdio.h>
#include <stdlib.h>

int Max(int a,int b)
{
	return a > b ? a : b;
}

AvlTree CreatAvlTree()
{
	AvlTree T = (AvlTree)malloc(sizeof(AvlNode));
	if (T == NULL)
	{
		printf("Out of memory");
		return NULL;
	}
	else
	{
		T->Left = T->Right = NULL;
		T->Height = 0;
	}
	return T;
}

AvlTree MakeEmpty(AvlTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

AvlPosition Find(ElementType ele, AvlTree T)
{
	if (T == NULL)
		return NULL;
	if (ele < T->Element)
		return Find(ele, T->Left);
	else
		if (ele > T->Element)
			return Find(ele, T->Right);
	return T;
}

AvlPosition FindPrevious(ElementType ele, AvlTree T)
{
	if (T == NULL || T->Left == NULL || T->Right == NULL) return NULL;

	if (ele < T->Left->Element)
		return FindPrevious(ele, T->Left);
	else
		if (ele > T->Element)
			return FindPrevious(ele, T->Right);
	return T;
}

//最小元
AvlPosition FindMin(AvlTree T)
{
	if (T == NULL)
		return NULL;
	else
		if (T->Left == NULL)
			return T;
		else
			return FindMin(T->Left);
}

//最大元
AvlPosition FindMax(AvlTree T)
{
	if (T != NULL)
		while (T->Right != NULL)
		{
			T = T->Right;
		}
	return T;
}

//左旋，树原先重心偏左，根节点偏右；现将根节点左移一个（取原根节点的左节点作为新的根节点）
static AvlPosition SingleRotateWithLeft(AvlPosition k2)
{
	AvlPosition k1;
	k1 = k2->Left;
	k2->Left = k1->Right;
	k1->Right = k2;
	k2->Height = Max(Height(k2->Left), Height(k2->Right)) + 1;
	k1->Height = Max(Height(k1->Left), k2->Height) + 1;
	return k1;
}

//右旋，树原先重心偏右，根节点偏左；现将根节点右移一个（取原根节点的右节点作为新的根节点）
static AvlPosition SingleRotateWithRight(AvlPosition k2)
{
	AvlPosition k1;
	k1 = k2->Right;
	k2->Right = k1->Left;
	k1->Left = k2;
	k2->Height = Max(Height(k2->Left), Height(k2->Right)) + 1;
	k1->Height = Max(Height(k1->Left),k2->Height) + 1;
	return k1;
}

//右旋左子树后再左旋根节点；右旋左子树是为了使重心变得更左，之后可以对整个根节点进行左旋
static AvlPosition DoubleRotateWithLeft(AvlPosition k3)
{
	/*Rotate between k1 and k2*/
	AvlPosition k1;
	k3->Left = SingleRotateWithRight(k3->Left);

	/*Rotate between k3 and k2*/
	return SingleRotateWithLeft(k3);
}

//左旋左子树后再右旋；左旋左子树是为了使重心变得更右，之后可以对整个根节点进行右旋
static AvlPosition DoubleRotateWithRight(AvlPosition k3)
{
	/*Rotate between k1 and k2*/
	AvlPosition k1;
	k3->Right = SingleRotateWithLeft(k3->Right);

	/*Rotate between k3 and k2*/
	return SingleRotateWithRight(k3);
}

AvlTree Insert(ElementType ele, AvlTree T)
{
	if (T == NULL)
	{
		T = (AvlTree)malloc(sizeof(AvlNode));
		if (T == NULL)
		{
			printf("Out of memory");
			return NULL;
		}
		else
		{
			T->Element = ele;
			T->Height = 0;
			T->Left = T->Right = NULL;
		}
	}
	else
	{
		if (ele < T->Element)
		{
			T->Left = Insert(ele, T->Left);
			if (Height(T->Left) - Height(T->Right) == 2)
				if (ele < T->Left->Element)
					T = SingleRotateWithLeft(T);
				else
					T = DoubleRotateWithLeft(T);
		}
		else
			if (ele > T->Element)
			{
				T->Right = Insert(ele, T->Right);
				if (Height(T->Left) - Height(T->Right) == 2)
					if (ele < T->Right->Element)
						T = SingleRotateWithRight(T);
					else
						T = DoubleRotateWithRight(T);
			}
	}
	T->Height = Max(Height(T->Left), Height(T->Right));
	return T;
}

static int Height(AvlPosition p)
{
	if (p == NULL)
		return -1;
	else
		return p->Height;
}


AvlTree Delete(ElementType ele, AvlTree T)
{
	AvlPosition pos = FindPrevious(ele, T);
	return pos;
}