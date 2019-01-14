#include "List.h"
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	ElementType Element;
	Position Next;
};

int IsEmpty(List L)
{
	return L->Next == NULL;
}

int IsLast(Position P,List L)
{
	return P->Next == NULL;
}


List MakeEmepty(List L);

Position Find(ElementType ele, List L)
{
	Position pos;

	pos = L->Next;
	while (pos != NULL && pos->Element != ele) pos = pos->Next;
	return pos;
}

Position FindPrevious(ElementType ele, List L)
{
	Position pos;
	pos = L;
	while (pos->Next != NULL && pos->Next->Element != ele) pos = pos->Next;
	return pos;
}

void Delete(ElementType ele, List L)
{
	Position pos, tmpPos;
	pos = FindPrevious(ele, L);
	if (!IsLast(pos,L))
	{
		tmpPos = pos->Next;
		pos->Next = tmpPos->Next;
		free(tmpPos);
	}
}

void Insert(ElementType ele, List L, Position P)
{
	Position tmpPos;
	tmpPos = (Position)malloc(sizeof(struct Node));
	//if (tmpPos == NULL) stderr
}

void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);