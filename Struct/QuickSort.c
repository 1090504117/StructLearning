#include "QuickSort.h"
#include "BubbleSort.h"
#include "Utils.h"

int Median3(int *data, int left, int right)
{
	//ȡ���ݵ�ͷ��β���м����������������ǽ�������
	//������ֱ�ӱ�����������
	int center = (left + right) / 2;
	if (&data[left] > &data[center])
		Swap(&data[left], &data[center]);
	if (&data[left] > &data[right])
		Swap(&data[left], &data[right]);
	if (&data[center] > &data[right])
		Swap(&data[center], &data[right]);
	//����ֵ������Ŧ�����鵹���ڶ���Ԫ�ؽ���
	Swap(&data[center], &data[right - 1]);
	return data[right - 1];//������Ŧ
}


void QuickSort(int *data, int left, int right)
{
	if (right - left >= Cutoff)
	{
		//ȡ����Ŧ��ֵ
		int center = Median3(data, left, right);
		int begin = left;
		int end = right - 1;
		while (1)
		{
			//���ɨ������
			//������ѡ����Ŧʱ���Ѿ��ѱ���Ŧֵ������ݷ���rightλ��
			//���Բ���Խ��
			while (data[++begin] < center);
			//��ǰɨ������
			//������ѡ����Ŧʱ���Ѿ��ѱ���ŦֵС�����ݷ���leftλ��
			//���Բ���Խ��
			while (data[--end] > center);
			//�ѱ���ŦС�����ݷ���ǰ������ķŵ���
			if (begin < end)
				Swap(&data[begin], &data[end]);
			else
			{
				//�Ѿ���Ҫ��������ݶ�����Ŧ�Ƚ���һ��
				//������Ŧ�������ʵ���λ�ã���Ϊbegin����һ������Ŧ��
				//���԰�����������������
				//beginһ����center��begin-1һ����centerС��������ʱ�򽻻�center��begin��ֵ
				Swap(&data[begin], &data[right - 1]);
				break;
			}
		}


		QuickSort(data, left, begin - 1);
		QuickSort(data, begin + 1, right);
	}
	else //���Ҫ��������ݺ��٣����ڵ���3������ֱ��ʹ��ð������
	{
		BubbleSort(data + left, right - left + 1);
	}
}