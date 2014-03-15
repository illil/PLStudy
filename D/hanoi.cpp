#include <iostream>
#include "hanoi.h"

void Hanoi(Tower source, Tower temp, Tower dest, int i)
{
	if (i == 1)
	{
		std::cout << source << " Move To " << dest << std::endl;
	}
	if (i > 1)
	{
		Hanoi(source, dest, temp, i - 1);
		std::cout << source << " Move To " << dest << std::endl;
		Hanoi(temp, source, dest, i - 1);
	}
}