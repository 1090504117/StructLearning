#include "QuickSort.h"
#include "BubbleSort.h"
#include "Utils.h"

int Median3(int *data, int left, int right)
{
	//取数据的头、尾和中间三个数，并对他们进行排序
	//排序结果直接保存在数组中
	int center = (left + right) / 2;
	if (&data[left] > &data[center])
		Swap(&data[left], &data[center]);
	if (&data[left] > &data[right])
		Swap(&data[left], &data[right]);
	if (&data[center] > &data[right])
		Swap(&data[center], &data[right]);
	//把中值，即枢纽与数组倒数第二个元素交换
	Swap(&data[center], &data[right - 1]);
	return data[right - 1];//返回枢纽
}


void QuickSort(int *data, int left, int right)
{
	if (right - left >= Cutoff)
	{
		//取得枢纽的值
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
				Swap(&data[begin], &data[end]);
			else
			{
				//已经对要排序的数据都与枢纽比较了一次
				//把中枢纽保存在适当的位置，因为begin的数一定比枢纽大
				//所以把这个数放在数组后面
				//begin一定比center大，begin-1一定比center小，所以这时候交换center和begin的值
				Swap(&data[begin], &data[right - 1]);
				break;
			}
		}


		QuickSort(data, left, begin - 1);
		QuickSort(data, begin + 1, right);
	}
	else //如果要排序的数据很少，少于等于3个，则直接使用冒泡排序
	{
		BubbleSort(data + left, right - left + 1);
	}
}