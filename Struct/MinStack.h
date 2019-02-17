#ifndef __MIN_STACK_H__
#define __MIN_STACK_H__

#include <stdlib.h>
#include <stdio.h>

struct MinStackElement 
{
	int data;
	int min;
};

struct MinStackNode 
{
	struct MinStackElement *data;
	int size;
	int top;
};

typedef struct MinStackNode *MinStack;

MinStack MinStackInit(MinStack stack ,int maxSize);

void MinStackFree(MinStack stack);

void MinStackPush(MinStack stack, int d);

int MinStackPop(MinStack stack);

int MinStackMin(MinStack stack);

void MinStackTest();

#endif //!__MIN_STACK_H__