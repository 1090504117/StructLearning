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
			//向后扫描数组
			//由于在选择枢纽时，已经把比枢纽值大的数据放在right位置
			//所以不会越界
			while (data[++begin] < center);
			//向前扫描数组
			//由于在选择枢纽时，已经把比枢纽值小的数据放在left位置
			//所以不会越界
			while (data[--end] > center);
			//把比枢纽小的数据放在前部，大的放到后部
			if (begin < end)
				Swap(data[begin], data[end]);
			else
				//已经对要排序的数据都与枢纽比较了一次
				//把中枢纽保存在适当的位置，因为begin的数一定比枢纽大
				//所以把这个数放在数组后面
				//begin一定比center大，begin-1一定比center小，所以这时候交换center和begin的值
				break;
			Swap(data[begin], data[right - 1]);
		}

		if (k <= begin)
			QuickSelect(data, k, left, begin - 1);
		else if (k > begin + 1)
			QuickSelect(data, k, begin + 1, right);

		//在k=begin+1时即终止，即为所查位置，不用全部排序
	}
	else
		BubbleSort(data + left, right - left + 1);
}