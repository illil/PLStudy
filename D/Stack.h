#pragma once

class Stack
{
public:

	Stack()
	{
		_count = 0;
	}

	void Push(int data)
	{
		_data[_count] = data;
		_count = _count + 1;
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
	int _data[100];
	int _count;
};