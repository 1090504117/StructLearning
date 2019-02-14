#ifndef __LIST_H__
#define __LIST_H__

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

typedef int ElementType;

//externed
List CreatList();

//externed

List MakeEmpty(List L);
int IsListEmpty(List L);
int IsLast(Position P,List L);
Position Find(ElementType ele, List L);
void Delete(ElementType ele, List L);
Position FindPrevious(ElementType ele, List L);
void Insert(ElementType ele, List L,Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif // !__LIST_H__