#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>


struct TreeNode
{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};

SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmepty(T->Left);
		MakeEmepty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(ElementType ele, SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (ele < T->Element)
		return Find(ele, T->Left);
	else
		if(ele > T->Element)
			return Find(ele, T->Right);
	return T;
}
//最小元
Position FindMin(SearchTree T)
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
Position FindMax(SearchTree T)
{
	if(T != NULL)
		while (T->Right != NULL)
		{
			T = T->Right;
		}
	return T;
}

SearchTree Insert(ElementType ele, SearchTree T)
{
	if (T == NULL)
	{
		T = (SearchTree)malloc(sizeof(SearchTree));
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
			T->Left = Insert(ele, T->Left);
		else
			if(ele > T->Element)
				T->Right = Insert(ele, T->Right);
	}
	return T;
}