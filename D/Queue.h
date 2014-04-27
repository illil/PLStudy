#pragma once

#include "LinkedList.h"

template <typename T, typename Container = LinkedList<T>>
class Queue 
{
public:
	
	void Enqueue(T &data)
	{
		_list.PushBack(data);
	}

	T Dequeue()
	{
		return _list.PopFront();
	}

	int Count()
	{
		return _list.Count();
	}

private:

	Container _list;
};


template <typename T>
class CircularQueue
{

};