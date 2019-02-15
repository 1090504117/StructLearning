#ifndef __AVL_TREE_TO_LOOP_LIST_H__
#define __AVL_TREE_TO_LOOP_LIST_H__

#include "AvlTree.h"
#include <stdio.h>
#include <stdlib.h>


void Helper(AvlTree head, AvlTree tail, AvlTree root);

AvlTree TreeToLinkedList(AvlTree node);

void TestConvert();

#endif // !__AVL_TREE_TO_LOOP_LIST_H__

