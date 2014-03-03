#pragma once

class Stack
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


	void Push(int data)
	{
		if (_data != nullptr)
		{
			if (_capacity < _count + 1)
			{
				_capacity *= 2;
				int *oldData = _data;
				_data = new int[_capacity];
				memcpy(_data, oldData, _count * sizeof(int));
				delete oldData;
				
			}
		}

		/*else
		{
			_data = new int[_count + 1];
		}
		*/

		_data[_count] = data;
		_count ++;
	}

	int Pop()
	{
		_count = _count - 1;
		return _data[_count];
	}

	bool TryPop(int& data)
	{
		if (_count > 0)
		{	
			data = Pop();
			return true;
		}
		return false;
	}

	int Peek()
	{
		return _data[_count - 1];
	}

	bool TryPeek(int& data)
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
	int* _data;
	int _count;
	int _capacity;
};