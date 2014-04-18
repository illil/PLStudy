#include <iostream>
#include <vector>
#include <algorithm>
#include "MountainData.h"
#include "Sort.h"
#include "BinarySearch.h"


std::function<void()> Test()
{
	int i=10;
	return[&]()
	{
		i = 11;
	};
}

int main()
{
	auto a = Test();

	a();
	/*

	
	std::vector<MountainData> mountains;

	mountains.push_back(MountainData("Dhaulagiri", 8167));
	mountains.push_back(MountainData("Manaslu", 8163));
	mountains.push_back(MountainData("Nanga Parbat", 8125));
	mountains.push_back(MountainData("Gasherbrum II", 8035));
	mountains.push_back(MountainData("Shishapangma", 8012));
	mountains.push_back(MountainData("K2", 8611));
	mountains.push_back(MountainData("Kangchenjunga", 8586));
	mountains.push_back(MountainData("Lhotse", 8516));
	mountains.push_back(MountainData("Makalu", 8463));
	mountains.push_back(MountainData("Everest", 8848));
	mountains.push_back(MountainData("Gasherbrum I", 8068));
	mountains.push_back(MountainData("Broad Peak", 8047));
	mountains.push_back(MountainData("Annapurna", 8091));
	mountains.push_back(MountainData("Cho Oyu", 8201));


	QuickSort<MountainData>(mountains,
		[](MountainData & a, MountainData& b)
		{
			return  a._elevation < b._elevation;
		}
	);

	/*int index;
	bool result = TryBinarySearch<MountainData, int>(sortedMountain, 8047,
		[](MountainData & a, int & b)
		{
			return b - a._elevation; 
		},
		index
	);
	*/

	return 0;
}
