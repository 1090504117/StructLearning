#include <iostream>
#include <time.h>
#include <vector>
#include <list>

#include <iostream>

using namespace std;

//80w数据删除vector 差不多花费19.04s
//80w数据删除list 花费时间1.53s
template <typename Container>
void RemoveEveryOtherItem(Container & lst)
{
	auto itr = lst.begin();		//itr is a Container::iterator
	while (itr != lst.end())
	{
		itr = lst.erase(itr);
		if (itr != lst.end())
			++itr;
	}
}

template <typename Container>
void PrepareList(Container &lst, int num)
{
	for (int i = 0; i < num; i++)
	{
		lst.push_back(i);
	}
}

template <typename Container>
auto begin(Container &c) -> decltype(c.begin())
{
	return c.begin();
}

template <typename Container>
auto begin(const Container &c) -> decltype(c.begin())
{
	return c.begin();
}

int ListAndVectorTest()
{

	//vector<int> lst = vector<int>();
	list<int> lst = list<int>();
	PrepareList(lst, 800000);


	clock_t startTime, endTime;
	startTime = clock();
	printf("startTime = %f\n", startTime);
	RemoveEveryOtherItem(lst);

	endTime = clock();
	printf("endTime = %f\n", endTime);
	printf("cost time = %f\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}