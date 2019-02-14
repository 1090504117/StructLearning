#ifndef __TREE_H__
#define __TREE_H__

struct MyTreeNode;
typedef struct MyTreeNode *Position;
typedef struct MyTreeNode *SearchTree;

typedef int ElementType;

//not finish
void CreatTree();

//not finish
SearchTree MakeEmpty(SearchTree T);


Position Find(ElementType ele, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);

SearchTree Insert(ElementType ele, SearchTree T);

//not finish
SearchTree Delete(ElementType ele, SearchTree T);

//not finish
ElementType Retrieve(Position P);

#endif // !__TREE_H__