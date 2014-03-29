#include <iostream>
#include "hanoi.h"
#include "Stack.h"
#include <stack>

void HanoiResursive(Tower source, Tower temp, Tower dest, int i)
{
	if (i == 1)
	{
 		std::cout << source << " Move To " << dest << std::endl;
	}
	if (i > 1)
	{
		HanoiResursive(source, dest, temp, i - 1);
		HanoiResursive(source, temp, dest, 1);
		HanoiResursive(temp, source, dest, i - 1);
	}
}

void HanoiNonResursive(Tower source, Tower temp, Tower dest, int i)
{

	std::stack<HanoiData> stack;

	stack.push(HanoiData(source, temp, dest, i));

	while (!stack.empty())
	{
		HanoiData data = stack.top();
		stack.pop();

		if (data.height == 1)
		{
			std::cout << data.source << " Move to " << data.dest << std::endl;
		}
		else if (data.height > 1)
		{
			stack.push(HanoiData(data.temp, data.source, data.dest, data.height - 1));
			stack.push(HanoiData(data.source, data.temp, data.dest, 1));
			stack.push(HanoiData(data.source, data.dest, data.temp, data.height - 1));
		}
	}
}