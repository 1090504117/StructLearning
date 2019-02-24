#ifndef __BUCKET_SORT_KEY_NODE_H__
#define __BUCKET_SORT_KEY_NODE_H__

typedef struct BucketSortKeyNode
{
	int key;
	struct BucketSortKeyNode *next;
} *pBucketSortKeyNode;

pBucketSortKeyNode* BucketSort(int keys[], int size, int bucket_size);

void BucketSortTest();

#endif // !__BUCKET_SORT_KEY_NODE_H__