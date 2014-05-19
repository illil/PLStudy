#pragma  once
#include "String.h"


template <typename T> class Vector
{
public:


	Vector(int capacity = 16)
		:_count(0), _capacity(capacity)
	{
		_data = static_cast<T*>(operator new[](sizeof(T)* _capacity));

	}

	Vector(Vector & vector)
		:_count(vector._count), _capacity(vector._capacity)
	{
		_data = static_cast<T*>(operator new[](sizeof(T)* _capacity));

		for (int i = 0; i < _count; ++i)
		{
			new (&_data[i]) T(vector._data[i]);
		}
	}


	Vector(Vector && vector)
		:_count(vector._count), _capacity(vector._capacity)
	{
		_data = vector._data; 
		vector._data = nullptr;
	}


	~Vector()
	{
		for (auto i : *this)
		{
			i.~T();
		}
		delete _data;
	}


	T & operator [](int index)
	{
		return _data[index];
	}

	void PushBack(const T& data)
	{
		Insert(_count, data);
	}

	void PushFront(const T& data)
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

	bool Insert(int index, const T& data)
	{
		if (index > _count || index < 0 )
		{
			return false;
		}

		if (_capacity < _count + 1)
		{
			_capacity *= 2;
			T *oldData = _data;

			_data = static_cast<T*>(operator new[](sizeof(T)* _capacity));

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

		new (&_data[index]) T(data);

		_count++;
		return true;
	}

	bool RemoveAt(int index)
	{
		if (index > _count -1 || index < 0)
		{
			return false;
		}

		_data[index].~T();

		if (_count > 1)
		{
			memcpy(_data + index, _data + index + 1, (_count - index) *sizeof(T));
		}

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

	class Iterator 
	{
	public:
		Iterator(Vector* arrayData, int index)
			:_array(arrayData), _index(index)
		{
		}

		T &operator *()
		{
			return (*_array)[_index];
		}

		Iterator& operator ++()
		{
			++_index;
			return *this;
		}

		Iterator& operator --()
		{
			--_index;
			return *this;
		}


		Iterator operator +(int i)
		{
			return Iterator(_array, _index + i);
		}

		Iterator operator -(int i)
		{
			return Iterator(_array, _index - i);
		}

		bool operator ==(Iterator & a)
		{
			return _array == a._array && _index == a._index;
		}

		bool operator !=(Iterator & a)
		{
			return _array != a._array || _index != a._index;
		}

		bool operator >=(Iterator & a)
		{
			return _array == a._array && _index >= a._index;
		}

	private:
		Vector* _array;
		int _index;
	};

	Iterator begin()
	{
		return Iterator(this, 0);
	}

	Iterator end()
	{
		return Iterator(this, _count);
	}

private:


	T* _data;
	int _count;
	int _capacity;
};