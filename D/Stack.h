#pragma once
#include "Array.h"

template <typename T, typename Container = Array<T>> 
class Stack
{
public:


	void Push(T data)
	{
		_container.Push(data);
	}

	T Pop()
	{
		return _container.Pop();
	}
	

	int Count()
	{
		return _container.Count();
	}

private:

	Container _container;
};