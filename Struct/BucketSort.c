#include <stdio.h>
#include <stdlib.h>
#include "BucketSort.h"

pBucketSortKeyNode* BucketSort(int keys[], int arraySize, int bucketSize) {
	int i, j;
	pBucketSortKeyNode *bucket = (pBucketSortKeyNode *)malloc(bucketSize * sizeof(struct BucketSortKeyNode));
	for (i = 0; i < bucketSize; i++)
	{
		bucket[i] = (pBucketSortKeyNode)malloc(sizeof(struct BucketSortKeyNode));
		bucket[i]->key = 0;
		bucket[i]->next = NULL;
	}

	for (j = 0; j < arraySize; j++)
	{
		pBucketSortKeyNode insertNode = (pBucketSortKeyNode)malloc(sizeof(struct BucketSortKeyNode));
		insertNode->key = keys[j];
		insertNode->next = NULL;
		int index = keys[j] / bucketSize;
		pBucketSortKeyNode p = bucket[index];
		if (p->key == 0) {
			bucket[index]->next = insertNode;
			(bucket[index]->key)++;
		}
		else
		{
			//进行插入排序
			while (p->next != NULL && p->next->key <= insertNode->key)
				p = p->next;
			//下两句断链和重新链接
			insertNode->next = p->next;
			p->next = insertNode;

			//首key记录数量
			(bucket[index]->key)++;
		}
	}
	return bucket;
}

void BucketSortPrint(pBucketSortKeyNode *bucket,int bucketSize)
{
	pBucketSortKeyNode k = NULL;
	for (int i = 0; i < bucketSize; i++)
		for (k = bucket[i]->next; k != NULL; k = k->next)
			printf("%d ", k->key);
	printf("\n");
}


void BucketSortTest()
{
	int a[] = { 49,38,65,97,76,13,27,49 };
	int arraySize = sizeof(a) / sizeof(int);
	int bucketSize = 10;
	pBucketSortKeyNode *bucket = BucketSort(a, arraySize, bucketSize);
	BucketSortPrint(bucket, arraySize);
}