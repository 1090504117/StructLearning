#include "MinusZeroPlusSort.h"
#include "Utils.h"

void MyMinusZeroPlusSort(int a[], int n)
{
	int x, y, z;
	x = y = z = 0;
	for (int i = 0; i < n;i++)
	{
		if (a[i] < 0) x++;
		else if (a[i] == 0) y++;
		else z++;
	}
	y = x + y;
	int f = 0;
	int m = x;
	int b = y;
	while (f < x)
	{
		if (a[f] == 0)
		{
			while (a[m] == 0) m++;
			Swap(&a[f], &a[m++]);
		}
		else if (a[f] > 0)
		{
			while (a[b] != 0);
			Swap(&a[f], &a[b++]);
		}
		else
			f++;
	}
	while (b < n)
	{
		if (a[b] == 0)
		{
			while (a[m] == 0) m++;
			Swap(&a[b++], &a[m++]);
		}
		else
			b++;
	}
}

void MyMinusZeroPlusSortTest()
{
	int a[] = { 0,-3,-5,4,45,0,234,-34,0,0,0,4 };
	int num = ArrayIntNum(a);
	PrintArrayInt(a, num);
	MyMinusZeroPlusSort(a,num);
	PrintArrayInt(a, num);
}