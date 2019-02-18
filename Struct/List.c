#include "List.h"
#include <stdio.h>
#include <stdlib.h>
//#include <errno.h>

struct Node
{
	ElementType Element;
	Position Next;
};

//externed
List CreatList() {
	List l = (List)malloc(sizeof(struct Node));
	if (l == NULL)
	{
		printf("out of memory");
		return NULL;
	}
	l->Next = NULL;
	return l;
}
//externed

int IsListEmpty(List L)
{
	return L->Next == NULL;
}

int IsLast(Position P,List L)
{
	return P->Next == NULL;
}

List MakeListEmpty(List L);

Position FindListElement(ElementType ele, List L)
{
	Position pos;

	pos = L->Next;
	while (pos != NULL && pos->Element != ele) pos = pos->Next;
	return pos;
}

Position FindListPrevious(ElementType ele, List L)
{
	Position pos;
	pos = L;
	while (pos->Next != NULL && pos->Next->Element != ele) pos = pos->Next;
	return pos;
}

void ListDeleteElement(ElementType ele, List L)
{
	Position pos, tmpPos;
	pos = FindListPrevious(ele, L);
	if (!IsLast(pos,L))
	{
		tmpPos = pos->Next;
		pos->Next = tmpPos->Next;
		free(tmpPos);
	}
}

void InsertList(ElementType ele, List L, Position P)
{
	Position tmpPos;
	tmpPos = (Position)malloc(sizeof(struct Node));
	//if (tmpPos == NULL) stderr
}

void DeleteList(List L) 
{
	Position pos, tmp;
	pos = L->Next;
	L->Next = NULL;
	while (pos != NULL)
	{
		tmp = pos->Next;
		free(pos);
		pos = tmp;
	}
}

Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);