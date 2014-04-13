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

template <typename T> void BubbleSort(std::vector<T>& datas, std::function<bool(T&,T&)> less)
{
	for (int i = 1; i < datas.size() - 1; i++)
	{
		for (int j = 0; j < datas.size() - i; j++)
		{
			if (less(datas[j], datas[j + 1]))
			{

				T temp = datas[j];
				datas[j] = datas[j + 1];
				datas[j + 1] = temp;
			}
		}
	}
}

template <typename T> void SelectionSort(std::vector<T>& datas, std::function<bool(T&, T&)> less)
{
	for (int i = 0; i < datas.size()-1; i++)
	{
		int minIndex = i;
		for (int j = i; j < datas.size(); j++)
		{
			if (less(datas[minIndex], datas[j]))
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			T temp = datas[i];
			datas[i] = datas[minIndex];
			datas[minIndex] = temp;
		}
	}
}

template <typename T> void InsertSort(std::vector<T>& datas, std::function<bool(T&, T&)> less)
{
	for (int i = 1; i < datas.size(); i++)
	{
		T insertData = datas[i];

		int j = i - 1;
		while (j >= 0 && less(datas[j], insertData))
		{
			datas[j + 1] = datas[j];
			j--;
		}
		datas[j + 1] = insertData;
	}
}