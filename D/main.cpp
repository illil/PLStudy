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

	mountains.PushBack(MountainData("Dhaulagiri", 8167));
	mountains.PushBack(MountainData("Manaslu", 8163));
	mountains.PushBack(MountainData("Nanga Parbat", 8125));
	mountains.PushBack(MountainData("Gasherbrum II", 8035));
	mountains.PushBack(MountainData("Shishapangma", 8012));
	mountains.PushBack(MountainData("K2", 8611));
	mountains.PushBack(MountainData("Kangchenjunga", 8586));
	mountains.PushBack(MountainData("Lhotse", 8516));
	mountains.PushBack(MountainData("Makalu", 8463));
	mountains.PushBack(MountainData("Everest", 8848));
	mountains.PushBack(MountainData("Gasherbrum I", 8068));
	mountains.PushBack(MountainData("Broad Peak", 8047));
	mountains.PushBack(MountainData("Annapurna", 8091));
	mountains.PushBack(MountainData("Cho Oyu", 8201));
	
	
	InsertSort(mountains.Begin(), mountains.End(), [](MountainData& a, MountainData& b){return a._elevation > b._elevation; });
	return 0;
}
