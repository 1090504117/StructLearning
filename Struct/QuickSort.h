#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#define Cutoff 3

void Swap(int &x, int &y);

int Median3(int *data, int left, int right);

void QuickSort(int *a, int left, int right);

#endif // !__QUICK_SORT_H__
