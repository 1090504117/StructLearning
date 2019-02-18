#ifndef __BINARY_TREE_FIND_PATH_H__
#define __BINARY_TREE_FIND_PATH_H__

#include "BinaryTree.h"
#include <stdlib.h>
#include "fatal.h"

typedef struct Path // 定义路径节点
{
	Position tree;
	struct Path *next;
}*pPath;

void BinaryTreeFindPathPrint(pPath L);

pPath BinaryTreeFindPathInit();

void BinaryTreeFindPathPop(pPath L);

void BinaryTreeFindPathPush(pPath L, SearchTree T);

void BinaryTreeFindPath(SearchTree T, int sum, pPath L);

void BinaryTreeFindPathTest();

#endif // !__BINARY_TREE_FIND_PATH_H__
