#pragma once
#include <vector>
#include <functional>
#include "MountainData.h"
#include "Swap.h"


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

template <typename T> std::vector<T>& QuickSortAllocation(std::vector<T>& datas, std::function<int(T&, T&)> comparer)
{
	if(datas.size() <= 1)
		return datas;

	int pivotIndex = datas.size()-1;
	T pivot = datas[pivotIndex];
	std::vector<T> less;
	std::vector<T> greater;

	for (int i = 0; i < datas.size() -1 ; i++)
	{
		if (comparer(datas[i], pivot) < 0)
		{
			greater.push_back(datas[i]);
		}
		else
		{
			less.push_back(datas[i]);
		}
	}

	less = QuickSort(less, comparer);
	greater = QuickSort(greater, comparer);

	less.push_back(pivot);
	less.insert(less.end(), greater.begin(), greater.end());

	return less;
}

template <typename T> void QuickSort(std::vector<T>& datas, std::function<bool(T&, T&)> less, int begin, int end)
{
	if (begin >= end)
		return;
	
	int pivotIndex = end;
	int i = begin;
	int j = end - 1;

	while (i < j)
	{
		while (less(datas[i], datas[pivotIndex]) && i < j)
		{
			++i;
		}

		while (less(datas[pivotIndex], datas[j]) && i < j)
		{
			--j;
		}

		if (i < j)
		{
			Swap(datas[i], datas[j]);
		}
	}

	if (less(datas[pivotIndex], datas[i]))
	{
		Swap(datas[i], datas[pivotIndex]);
		pivotIndex = i;
	}

	QuickSort(datas, less, begin, pivotIndex - 1);
	QuickSort(datas, less, pivotIndex + 1, end);
}

template <typename T> void QuickSort(std::vector<T>& datas, std::function<bool(T&, T&)> less)
{
	QuickSort<T>(datas, less, 0, datas.size() - 1);
	
}