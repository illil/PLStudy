#pragma once

#include "LinkedList.h"


template <typename T>
class QueueBase
{
public:
	virtual void Enqueue(T &data) = 0;
	virtual T Dequeue() = 0;
	virtual int Count() = 0;
};

template <typename T, typename Container = LinkedList<T>>
class Queue :public QueueBase<T>
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
class CircularQueue :public QueueBase<T>
{
public:
	CircularQueue(int capacity=32)
		:_capacity(capacity), _beginIndex(0), _endIndex(0)
	{
		_data = static_cast<T*>(operator new[](sizeof(T)*_capacity));
	}

	~CircularQueue()
	{
		for (int i = _beginIndex; i < _endIndex; ++i)
		{
			_data[i % _capacity].~T();
		}
		delete _data;
	}

	int Count()
	{
		return _endIndex - _beginIndex;
	}

	virtual void Enqueue(T &data)
	{
		if (Count() >= _capacity)
			throw std::exception("error");

		new (&_data[_endIndex % _capacity]) T(data);
		++_endIndex;
	}

	virtual T Dequeue()
	{
		if (Count() <= 0)
			throw std::exception("error");

		T result = _data[_beginIndex % _capacity];
		_data[_beginIndex % _capacity].~T();
		++_beginIndex;
		return result;
	}


private:
	int _capacity;
	int _beginIndex;
	int _endIndex;
	T * _data;
};



template <typename T>
class SegmentQueue :public QueueBase<T>
{
public:
	SegmentQueue(int segmentCapacity=8)
		:_segmentCapacity(segmentCapacity), _count(0)
	{
		_segmentList.PushBack(new Segment(_segmentCapacity));
	}

	virtual void Enqueue(T &data)
	{
		auto segment = _segmentList.Back();

		if (!segment->IsPushable())
		{
			_segmentList.PushBack(new Segment(_segmentCapacity));
			segment = _segmentList.Back();
		}

		segment->PushBack(data);
		++_count;
	}

	virtual T Dequeue()
	{
		auto segment = _segmentList.Front();

		if (!segment->IsPushable() && segment->Count() == 0)
		{
			_segmentList.PopFront();
			segment = _segmentList.Front();
		}

		--_count;
		return segment->PopFront();
	}

	virtual int Count()
	{
		return _count;
	}

	

private:  

	class Segment
	{
	public:
		Segment(int capacity)
			:_capacity(capacity), _beginIndex(0), _endIndex(0)
		{
			_data = static_cast<T*>(operator new[](sizeof(T)*_capacity));
		}

		~Segment()
		{
			for (int i = _beginIndex; i < _endIndex; ++i)
			{
				_data[i].~T();
			}
			delete _data;
		}

		void PushBack(T &data)
		{
			if (Count() >= _capacity || _endIndex > _capacity)
				throw std::exception("error");

			new (&_data[_endIndex]) T(data);
			++_endIndex;
		}

		T PopFront()
		{
			if (Count() <= 0)
				throw std::exception("error");

			T result = _data[_beginIndex];
			_data[_beginIndex].~T();
			++_beginIndex;
			return result;
		}

		int Count()
		{
			return _endIndex - _beginIndex;
		}

		bool IsPushable()
		{
			return _endIndex < _capacity - 1;
		}

	private:

		int _capacity;
		T * _data;
		int _beginIndex;
		int _endIndex;
	};

	int _segmentCapacity;
	LinkedList<Segment*> _segmentList;
	int _count;
};
