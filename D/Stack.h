#pragma once

template <typename T> class Stack
{
public:

	Stack()
	{
		_count = 0;
		_capacity = 16;
		_data = new int[_capacity];
	}

	~Stack()
	{
		if (_data != nullptr)
		{
			delete _data;
		}
	}


	void Push(T data)
	{
		if (_data != nullptr)
		{
			if (_capacity < _count + 1)
			{
				_capacity *= 2;
				T *oldData = _data;
				_data = new T[_capacity];
				memcpy(_data, oldData, _count * sizeof(T));
				delete oldData;

			}
		}

		_data[_count] = data;
		_count ++;
	}

	T Pop()
	{
		_count = _count - 1;
		return _data[_count];
	}

	bool TryPop(T& data)
	{
		if (_count > 0)
		{	
			data = Pop();
			return true;
		}
		return false;
	}

	T Peek()
	{
		return _data[_count - 1];
	}

	bool TryPeek(T& data)
	{
		if (_count > 0)
		{
			data = Peek();
			return true;
		}
		return false;
	}

	int Count()
	{
		return _count;
	}

private:
	T* _data;
	int _count;
	int _capacity;
};