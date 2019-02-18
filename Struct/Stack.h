#ifndef __STACK_H__
#define __STACK_H__

struct Node;
typedef struct Node *PtrNode;
typedef PtrNode Stack;
typedef PtrNode Position;

typedef int ElementType;


//externed
Stack CreateStack();

//externed

void MakeStackEmpty(Stack S);
int IsEmpty(Stack S);
void DisposeStack(Stack S);
void Push(ElementType ele,Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

#endif // !__STACK_H__