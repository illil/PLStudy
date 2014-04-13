#pragma once
#include <vector>


template <typename T, typename T2> bool TryBinarySearch(std::vector<T>& datas, T2 t, std::function<int(T&, T2&)> comparer, int& index)
{
	int start = 0;
	int end = datas.size();


	while (start != end)
	{
		int middle = (end + start) / 2;
		int compare = comparer(datas[middle], t);

		if (compare < 0)
		{
			end = middle;
		}
		else if (compare > 0)
		{
			start = middle;
		}
		else if (compare == 0)
		{
			index = middle;
			return true;
		}
	}
	return false;
}
