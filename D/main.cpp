#include <iostream>
#include "String.h"
#include "Stack.h"
#include "factorial.h"
#include "fibonacci.h"
#include "hanoi.h"
#include "figure.h"
#include <vector>


int main()
{
	Figure *a = new Rectangle(0, 0, 10, 10);
	Figure *b = new Rectangle(0, 0, 10, 10);

	float aa = a->GetArea();
	float bb = b->GetArea();

	delete a;
	return 0;
}
