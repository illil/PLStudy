#include <iostream>
#include "String.h"
#include "Stack.h"


int main()
{

	Stack stack;
	stack.Push(3);
	stack.Push(2);
	stack.Push(12);
	
	while ( stack.Count()> 0)
	{
		std::cout << stack.Pop() << std::endl;
	}

	stack.Push(3);
	stack.Push(2);
	stack.Push(12);

	while (stack.Count()> 0)
	{
		std::cout << stack.Pop() << std::endl;
	}

	return 0;
}
