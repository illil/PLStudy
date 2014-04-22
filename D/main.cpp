#include <iostream>
#include <vector>
#include <algorithm>
#include "MountainData.h"
#include "Sort.h"
#include "BinarySearch.h"
#include "Array.h"
#include "LinkedList.h"


int main()
{	
	LinkedList <MountainData> mountains;

	mountains.AddLast(MountainData("Dhaulagiri", 8167));

	mountains.RemoveLast();

	mountains.AddLast(MountainData("Manaslu", 8163));
	mountains.AddLast(MountainData("Nanga Parbat", 8125));
	mountains.AddLast(MountainData("Gasherbrum II", 8035));
	mountains.AddLast(MountainData("Shishapangma", 8012));
	mountains.AddLast(MountainData("K2", 8611));
	mountains.AddLast(MountainData("Kangchenjunga", 8586));
	mountains.AddLast(MountainData("Lhotse", 8516));
	mountains.AddLast(MountainData("Makalu", 8463));
	mountains.AddLast(MountainData("Everest", 8848));
	mountains.AddLast(MountainData("Gasherbrum I", 8068));
	mountains.AddLast(MountainData("Broad Peak", 8047));
	mountains.AddLast(MountainData("Annapurna", 8091));
	mountains.AddLast(MountainData("Cho Oyu", 8201));
	
	
	LinkedList <MountainData> aaa;
	mountains.Remove(aaa.Begin());

	auto find = mountains.FindFirst([](MountainData& m){return m._name == "Annapurna"; });

	for (auto i = mountains.Begin(); i != mountains.End();)
	{
		std::cout << (*i)._name << std::endl;
		if ((*i)._name == "K2")
		{
			i = mountains.Remove(i);
		}
		else
		{
			++i;
		}
	}
	
	return 0;
}
