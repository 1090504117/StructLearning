#ifndef __List_H__

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

typedef int ElementType;

List MakeEmepty(List L);
int IsEmpty(List L);
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

#endif // !__List_H__