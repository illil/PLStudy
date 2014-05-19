#pragma  once

#include "Vector.h"


#define _HASH_SEED	(unsigned char)0xde

template<typename T> unsigned char hash_value(const T& value)
{
	return ((unsigned char)value ^ _HASH_SEED);
}

template<typename T> 
class HashFunctor
{
public:

	unsigned char operator ()(const T &value)
	{
		return hash_value(value);
	}
};



template <typename Key,typename Value,typename Hash = HashFunctor<Key>>
class HashTable
{

private:
	struct Pair
	{
	public:

		Pair(const Key &key, const Value& value)
			:_key(key), _value(value)
		{}

		Key _key;
		Value _value;
	};

public:

	HashTable(const Hash &hashFunctor = Hash())
		:_hashFunctor(hashFunctor)
	{
		//_tables = new Vector<Pair>*[256];
		memset(_tables, 0, sizeof(Vector<Pair>*) * 256);
	}


	~HashTable()
	{
		for (int i = 0; i < 256; ++i)
		{
			if (_tables[i] != nullptr)
				delete _tables[i];
		}

		//delete _tables;
	}


	bool Insert(const Key &key, const Value& value)
	{
		if (Exist(key))
		{
			return false;
		}

		unsigned char hash = _hashFunctor(key);

		if (_tables[hash] == nullptr)
		{
			_tables[hash] = new Vector<Pair>();
		}

		_tables[hash]->PushBack(Pair(key, value));
		return true;
	}


	bool Exist(const Key& key)
	{
		unsigned char hash = _hashFunctor(key);

		if (_tables[hash] == nullptr)
			return false;

		for (auto i : *_tables[hash])
		{
			if (i._key == key)
			{
				return true;
			}
		}

		return false;
	}

private:

	Vector<Pair> *_tables[256];
	Hash _hashFunctor;

};