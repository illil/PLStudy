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
	
	mountains.RemoveFirst();
	mountains.RemoveLast();


	for (auto i = mountains.Begin(); i != mountains.End(); i++)
	{
		std::cout << (*i)._name << " " << (*i)._elevation << std::endl;
	}
	return 0;
}
