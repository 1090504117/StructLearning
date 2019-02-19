#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "HeapSort.h"

void HeapSortMaxHeapify(int arr[], int start, int end)
{
	//�������ڵ�ָ����ӽڵ�ָ��
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end)
	{ //���ӽڵ�ָ���ڷ�Χ�ڲ����Ƚ�
		if (son + 1 <= end && arr[son] < arr[son + 1]) //�ȱȽ������ӽڵ��С��ѡ������
			son++;
		if (arr[dad] > arr[son]) //������ڵ����ӽڵ���������ϣ�ֱ����������
			return;
		else { //���򽻻����������ټ����ӽڵ����ڵ�Ƚ�
			Swap(&arr[dad], &arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void HeapSort(int arr[], int len)
{
	int i;
	//��ʼ����i������һ�����ڵ㿪ʼ����
	for (i = len / 2 - 1; i >= 0; i--)
		HeapSortMaxHeapify(arr, i, len - 1);

	//���Ƿֽ�㣬���
	//�Ƚ���һ��Ԫ�غ����ź�Ԫ��ǰһλ�������������µ�����ֱ���������
	for (i = len - 1; i > 0; i--) {
		Swap(&arr[0], &arr[i]);
		HeapSortMaxHeapify(arr, 0, i - 1);
	}
}

void HeapSortTest()
{
	int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
	int len = (int) sizeof(arr) / sizeof(*arr);
	HeapSort(arr, len);
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}