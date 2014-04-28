#include <iostream>
#include <vector>
#include <algorithm>

#include "MountainData.h"
#include "Sort.h"
#include "BinarySearch.h"
#include "Vector.h"
#include "LinkedList.h"
#include "Queue.h"

int main()
{
	std::vector<int> aa;
	SegmentQueue <MountainData> mountains;

	mountains.Enqueue(MountainData("Dhaulagiri", 8167));
	mountains.Enqueue(MountainData("Manaslu", 8163));
	mountains.Enqueue(MountainData("Nanga Parbat", 8125));
	mountains.Enqueue(MountainData("Gasherbrum II", 8035));
	mountains.Enqueue(MountainData("Shishapangma", 8012));
	mountains.Enqueue(MountainData("K2", 8611));
	mountains.Enqueue(MountainData("Kangchenjunga", 8586));
	mountains.Enqueue(MountainData("Lhotse", 8516));
	mountains.Enqueue(MountainData("Makalu", 8463));
	mountains.Enqueue(MountainData("Everest", 8848));
	mountains.Enqueue(MountainData("Gasherbrum I", 8068));
	mountains.Enqueue(MountainData("Broad Peak", 8047));
	mountains.Enqueue(MountainData("Annapurna", 8091));
	mountains.Enqueue(MountainData("Cho Oyu", 8201));
	
	
	

	while (mountains.Count() > 0)
	{
		MountainData data = mountains.Dequeue();
		std::cout << data._name << " " << data._elevation << std::endl;
	}

	return 0;
}
