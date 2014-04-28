#pragma once
#include "Vector.h"

template <typename T, typename Container = Vector<T>> 
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