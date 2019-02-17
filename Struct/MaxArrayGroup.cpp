#include "MaxArrayGroup.h"
#include <stdlib.h>
#include <stdio.h>

int GetArrayMax(int *data, int size)
{
	if (size == 0)
	{
		printf("no array!");
		return 0;
	}
	int max = data[0];
	for (int i = 1; i < size; i++)
	{
		if (max < data[i]) max = data[i];
	}
	return max;
}

int MaxSubArray(int a[], int size) {
	if (size <= 0) {
		printf("error array size");
		return 0;
	}
	int sum = 0;
	int maxNum;
	int max = maxNum = GetArrayMax(a,size);
	int cur = 0;
	while (cur < size) {
		sum += a[cur++];
		if (sum > max) {
			max = sum;
		}
		else if (sum < 0 && sum < maxNum) {
			sum = 0;
		}
	}
	return max;
}

void MaxArrayGroupTest()
{
	int a[] = {-139,-3,1,5,2,6,23,4,-13,3,-3};
	printf("maxValue = %d\n", MaxSubArray(a,sizeof(a)/sizeof(int)));
}