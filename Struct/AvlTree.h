#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__

typedef int ElementType;
struct AvlNode;
typedef struct AvlNode *AvlPosition;
typedef struct AvlNode *AvlTree;

struct AvlNode
{
	ElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

//not finish
AvlTree CreatAvlTree();

//not finish
AvlTree MakeEmpty(AvlTree T);


AvlPosition Find(ElementType ele, AvlTree T);
AvlPosition FindMin(AvlTree T);
AvlPosition FindMax(AvlTree T);

AvlTree Insert(ElementType ele, AvlTree T);

//not finish
AvlTree Delete(ElementType ele, AvlTree T);

//not finish
//ElementType Retrieve(AvlPosition p);

static int Height(AvlPosition p);

#endif // !__AVL_TREE_H__