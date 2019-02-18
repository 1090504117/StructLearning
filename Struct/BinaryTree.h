#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__


typedef int ElementType;

typedef struct BinaryTreeNode *Position;
typedef struct BinaryTreeNode *SearchTree;

struct BinaryTreeNode
{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};

void MiddleOrder(SearchTree node);

SearchTree CreateBinaryTree();

SearchTree MakeBinaryTreeEmpty(SearchTree T);


Position FindBinaryTreeElement(ElementType ele, SearchTree T);
Position FindBinaryTreeMin(SearchTree T);
Position FindBinaryTreeMax(SearchTree T);

SearchTree InsertBinaryTreeElement(ElementType ele, SearchTree T);

//not finish
SearchTree DeleteBinaryTreeNode(ElementType ele, SearchTree T);

//not finish
ElementType Retrieve(Position P);

#endif // !__BINARY_TREE_H__