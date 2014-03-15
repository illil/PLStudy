#include <iostream>
#include "String.h"
#include "Stack.h"
#include "factorial.h"
#include "fibonacci.h"
#include "hanoi.h"

int main()
{
	std::cout << "Tower of Hanoi" << std::endl;
	Hanoi(source, temp, dest, 3);

	return 0;
}
