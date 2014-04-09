#include <iostream>
#include "Array.h"


int main()
{
	int data1[10];

	Array<int> data(10);

	data[0] = 1;
	data.PushFront(0);
	data.PushBack(11);
	for (int i = 0; i < data.Count(); ++i)
	{
		std::cout << data[i] << std::endl;
	}
	return 0;
}
