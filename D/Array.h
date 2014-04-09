
template <typename T> class Array
{
public:

	Array(int size)
	{
		_count = size;
		_capacity = size;
		_data = new int[_capacity];
	}

	~Array()
	{
		if (_data != nullptr)
		{
			delete _data;
		}
	}

	T & operator [](int index)
	{
		return _data[index];
	}

	void PushBack(T data)
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
		_count++;
	}

	void PushFront(T data)
	{
		if (_capacity < _count + 1)
		{
			_capacity *= 2;
			T *oldData = _data;
			_data = new T[_capacity];
			memcpy(_data + 1, oldData, _count * sizeof(T));
			delete oldData;
		}
		else
		{
			memcpy(_data + 1, _data, _count * sizeof(T));
		}
		_data[0] = data;
		_count++;
	}

	T PopFront()
	{
		T result = _data[0];
		_count--;
		memcpy(_data, _data +1, _count * sizeof(T));
	}

	T PopBack()
	{
		_count--;
		return _data[_count];
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