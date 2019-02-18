#ifndef __CURSOR_H__
#define __CURSOR_H__
typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

typedef int ElementType;

void InitializeCursorSpace();
//externed
List CreatList();
//externed

void MakeEmepty(List L);
int IsEmpty(const List L);
int IsLast(const Position p, const List L);
//Position Find(ElementType ele, List L);
void Delete(ElementType ele, List L);
//Position FindPrevious(ElementType ele, List L);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif // !__STACK_H__