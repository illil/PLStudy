#include <iostream>
#include "String.h"
#include "Stack.h"
#include "factorial.h"
#include "fibonacci.h"
#include "hanoi.h"

int main()
{
	HanoiResursive(source, temp, dest, 4);
	std::cout << "Tower of Hanoi" << std::endl;
	HanoiNonResursive(source, temp, dest, 4);
	return 0;
}
