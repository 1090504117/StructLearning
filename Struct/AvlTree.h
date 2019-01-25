#ifndef __AVL_TREE_H__

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

typedef int ElementType;

//not finish
void CreatTree();

//not finish
AvlTree MakeEmepty(AvlTree T);


Position Find(ElementType ele, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);

AvlTree Insert(ElementType ele, AvlTree T);

//not finish
AvlTree Delete(ElementType ele, AvlTree T);

//not finish
ElementType Retrieve(Position p);

static int Height(Position p);

#endif // !__AVL_TREE_H__