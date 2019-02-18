#include "QuickSelect.h"
#include "BubbleSort.h"
#include <stdlib.h>
#include <stdio.h>

void QuickSelect(int *data,int k, int left, int right)
{
	if (right - left >= Cutoff)
	{
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
				Swap(data[begin], data[end]);
			else
				//�Ѿ���Ҫ��������ݶ�����Ŧ�Ƚ���һ��
				//������Ŧ�������ʵ���λ�ã���Ϊbegin����һ������Ŧ��
				//���԰�����������������
				//beginһ����center��begin-1һ����centerС��������ʱ�򽻻�center��begin��ֵ
				break;
			Swap(data[begin], data[right - 1]);
		}

		if (k <= begin)
			QuickSelect(data, k, left, begin - 1);
		else if (k > begin + 1)
			QuickSelect(data, k, begin + 1, right);

		//��k=begin+1ʱ����ֹ����Ϊ����λ�ã�����ȫ������
	}
	else
		BubbleSort(data + left, right - left + 1);
}