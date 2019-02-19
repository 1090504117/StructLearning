#include <stdio.h>
#include <stdlib.h>
#include "QuickSort.h"
#include "QuickSelect.h"
#include "AvlTreeToDoubleList.h"
#include "MinStack.h"
#include "MaxArrayGroup.h"
#include "BinaryTreeFindPath.h"
#include "HeapSort.h"

int main()
{
	/*
	int data[10] = {4,3,5,6,21,1,11,35,36,23};
	QuickSort(data,0,9);
	for (int i = 0; i < 10; i++)
		printf("%d ",data[i]);
	printf("\n");
	*/


	/*
	int data[10] = { 4,3,5,6,21,1,11,35,36,23 };
	int k = 5;
	QuickSelect(data, k, 0, 9);
	printf("select num = %d", data[k]);
	*/

	//TestConvert();
	
	//MinStackTest();

	//MaxArrayGroupTest();

	//BinaryTreeFindPathTest();

	HeapSortTest();

	system("pause");
	return 0;
}