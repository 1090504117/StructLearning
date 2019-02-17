#include "MinStack.h"
#include <stdlib.h>
#include <stdio.h>


//此stack的构建目前仍然有问题

MinStack CreateMinStack(int maxSize)
{
	MinStack stack = (MinStack)malloc(sizeof(struct MinStackNode));
	MinStackInit(stack, maxSize);
	return stack;
}

MinStack MinStackInit(MinStack stack,int maxSize)
{
	stack->size = maxSize;
	stack->data = (MinStackElement*)malloc(sizeof(MinStackElement)*maxSize);
	stack->top = 0;
	return stack;
}

void MinStackFree(MinStack stack)
{
	free(stack->data);
}

void MinStackPush(MinStack stack, int d)
{
	int top = stack->top;
	if (top == stack->size)
	{
		printf("out of stack space.");
		return;
	}
	MinStackElement *p = stack->data + top;
	p->data = d;
	p->min = top == 0 ? d : stack->data[top - 1].min;
	if (p->min > d) p->min = d;
	stack->top++;
}

int MinStackPop(MinStack stack) {
	if (stack->top == 0)
	{
		printf("stack is empty!");
		return 0;
	}
	return stack->data[--stack->top].data;
}

int MinStackMin(MinStack stack) {
	if (stack->top == 0)
	{
		printf("stack is empty!");
		return 0;
	}
	return stack->data[stack->top - 1].min;
}

void MinStackTest()
{
	int stackSize = 5;
	MinStack stack = CreateMinStack(stackSize);
	int a[] = { 4,5,7,56,1 };
	for (int i = 0; i < sizeof(a)/sizeof(int); i++)
	{
		MinStackPush(stack, a[i]);
	}
	printf("min = %d\n", MinStackMin(stack));
	MinStackPop(stack);
	printf("min = %d\n", MinStackMin(stack));
}