
template <typename T> class Array
{
public:

	Array(int capacity = 16)
	{
		_count = 0;
		_capacity = capacity;
		_data = static_cast<T>(operator new[](sizeof(T)* _capacity));
		memset(_data, 0, sizeof(T)* _capacity);
	}

	~Array()
	{
		delete _data;
	}


	T & operator [](int index)
	{
		return _data[index];
	}

	void PushBack(T& data)
	{
		Insert(_count, data);
	}

	void PushFront(T& data)
	{
		Insert(0, data);
	}

	T PopFront()
	{
		T result = _data[0];
		RemoveAt(0);
		return result;
	}

	T PopBack()
	{
		T result = _data[_count -1];
		RemoveAt(_count -1);
		return result;
	}
	
	int Count()
	{
		return _count;
	}

	bool Insert(int index, T& data)
	{
		if (index > _count || index < 0 )
		{
			return false;
		}

		if (_capacity < _count + 1)
		{
			_capacity *= 2;
			T *oldData = _data;

			_data = static_cast<T>(operator new[](sizeof(T)* _capacity));
			memset(_data, 0, sizeof(T)* _capacity);

			if (index > 0)
				memcpy(_data, oldData, index * sizeof(T));

			if (_count - index > 0)
				memcpy(_data + index + 1, oldData + index, (_count - index) *sizeof(T));

			delete oldData;
		}
		else
		{
			if (_count - index > 0)
				memcpy(_data + index + 1, _data + index, (_count - index) *sizeof(T));
		}
		_data[index] = data;
		_count++;
		return true;
	}

	bool RemoveAt(int index)
	{
		if (index > _count -1 || index < 0)
		{
			return false;
		}

		if (_count > 1)
		{
			memcpy(_data + index, _data + index + 1, (_count - index) *sizeof(T));
		}

		memset(_data + _count - 1, 0, sizeof(T));
		--_count;
		return true;
	}


	void ShrinkToFit()
	{
		Reserve(_count);
	}

	bool Reserve(int capacity)
	{
		if (capacity < _count)
			return false;

		_capacity = capacity;
		T *oldData = _data;
		_data = static_cast<T>(operator new[](sizeof(T)* _capacity));		
		memcpy(_data, oldData, _count *sizeof(T));

		if (_capacity - _count > 0)
			memset(_data + _count, 0, (_capacity - _count) * sizeof(T));
		delete oldData;

		return true;
	}

private:


	T* _data;
	int _count;
	int _capacity;
};