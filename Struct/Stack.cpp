#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

struct Node
{
	ElementType Element;
	Position Next;
};

//externed
Stack CreateStack()
{
	Stack s;
	//c语言中这样返回一个指针
	s = (Stack)malloc(sizeof(struct Node));
	if (s == NULL)
	{
		printf("out of memory");
		return NULL;
	}
	s->Next = NULL;
	return s;
}

//externed

void MakeEmpty(Stack S)
{
	if (S == NULL)
	{
		printf("Must use CreateStack first");
		return;
	}
	else
		while (!IsEmpty(S))
			Pop(S);
}

int IsEmpty(Stack S)
{
	return S->Next == NULL;
}

void DisposeStack(Stack S)
{
	MakeEmpty(S);
	free(S);
}

void Push(ElementType ele, Stack S) 
{
	PtrNode TmpCell;
	TmpCell = (PtrNode)malloc(sizeof(PtrNode));
	if (TmpCell == NULL)
	{
		printf("out of memory");
		return;
	}
	else
	{
		TmpCell->Element = ele;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}

ElementType Top(Stack S)
{
	if (!IsEmpty(S))
	{
		return S->Next->Element;
	}
	printf("Empty stack");
	return 0;
}

void Pop(Stack S)
{
	PtrNode FirstCell;
	if (IsEmpty(S))
	{
		printf("Empty stack");
		return;
	}
	else
	{
		FirstCell = S->Next;
		S->Next = FirstCell->Next;
		free(FirstCell);
		//FirstCell = NULL;
	}
}