#pragma once

enum Tower
{
	source = 1,
	temp = 2,
	dest = 3
};

extern void HanoiResursive(Tower source, Tower temp, Tower dest, int i);
extern void HanoiNonResursive(Tower source, Tower temp, Tower dest, int i);

struct HanoiData
{
	HanoiData()
	{
	}

	HanoiData(Tower source, Tower temp, Tower dest, int i)
	{
		height = i;
		this->source = source;
		this->temp = temp;
		this->dest = dest;
	}

	int height;
	Tower source;
	Tower temp;
	Tower dest;
};

class HanoiStack
{
public:

	HanoiStack()
	{
		_count = 0;
		_capacity = 16;
		_data = new HanoiData[_capacity];
	}

	~HanoiStack()
	{
		if (_data != nullptr)
		{
			delete _data;
		}
	}


	void Push(HanoiData data)
	{
		if (_data != nullptr)
		{
			if (_capacity < _count + 1)
			{
				_capacity *= 2;
				HanoiData *oldData = _data;
				_data = new HanoiData[_capacity];
				memcpy(_data, oldData, _count * sizeof(HanoiData));
				delete oldData;

			}
		}

		_data[_count] = data;
		_count++;
	}

	HanoiData Pop()
	{
		_count = _count - 1;
		return _data[_count];
	}

	bool TryPop(HanoiData& data)
	{
		if (_count > 0)
		{
			data = Pop();
			return true;
		}
		return false;
	}

	HanoiData Peek()
	{
		return _data[_count - 1];
	}

	bool TryPeek(HanoiData& data)
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
	HanoiData* _data;
	int _count;
	int _capacity;
};