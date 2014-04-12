#pragma once
#include <vector>
#include <functional>
#include "MountainData.h"

template <typename T, typename Comparer> void BubbleSort(std::vector<T>& datas)
{
	Comparer comparer;
	for (int i = 1; i < datas.size() - 1; i++)
	{
		for (int j = 0; j < datas.size() - i; j++)
		{
			if (comparer(datas[j], datas[j + 1]))
			{
				
				T temp = datas[j];
				datas[j] = datas[j + 1];
				datas[j + 1] = temp;
			}
		}
	}
}

template <typename T> void BubbleSort(std::vector<T>& datas, std::function<bool(T&,T&)> comparer)
{
	for (int i = 1; i < datas.size() - 1; i++)
	{
		for (int j = 0; j < datas.size() - i; j++)
		{
			if (comparer(datas[j], datas[j + 1]))
			{

				T temp = datas[j];
				datas[j] = datas[j + 1];
				datas[j + 1] = temp;
			}
		}
	}
}