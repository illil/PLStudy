#include <iostream>
#include "String.h"
#include "Stack.h"


int main()
{

	Stack stack;
	stack.Push(3);
	
	int data;
	stack.TryPeek(data);
	return 0;
}
