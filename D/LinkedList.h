#pragma once

template <typename T> class LinkedList
{
public:
	LinkedList() 
		:_begin(nullptr), _end(nullptr)
	{

	}

	~LinkedList()
	{
		Clear();
	}

	void AddFirst(T &data)
	{
		if (_begin == nullptr)
		{
			_begin = new Node(data);
			_end = _begin;
		}
		else
		{
			Node * oldBegin = _begin;
			_begin = new Node(data);
			_begin->_next = oldBegin;
			oldBegin->_prev = _begin;
		}

	}

	void AddLast(T &data)
	{
		if (_begin == nullptr)
		{
			_begin = new Node(data);
			_end = _begin;
		}
		else
		{
			Node * oldEnd = _end;
			_end = new Node(data);
			_end->_prev = oldEnd;
			oldEnd->_next = _end;
		}
	}

	bool RemoveFirst()
	{
		if (_begin == nullptr)
			return false;

		Node * next = _begin->_next;

		delete _begin;

		_begin = next;

		if (_begin != nullptr)
		{
			_begin->_prev = nullptr;
		}
		else
		{
			_end = nullptr;
		}

		return true;

	}

	bool RemoveLast()
	{
		if (_begin == nullptr)
			return false;

		auto oldEnd = _end;
		_end = _end->_prev;
		
		delete oldEnd;

		if (_end == nullptr)
		{
			_begin = nullptr;
		}
		else
		{
			_end->_next = nullptr;
		}
		
		return true;
	}

	void Clear()
	{
		auto current = _begin;
		while (current != nullptr)
		{
			auto oldData = current;
			current = current->_next;
			delete oldData;
		}
		_begin = nullptr;
		_end = nullptr;
	}


	class Node
	{
	public:
		Node(T & data)
			:_data(data), _next(nullptr), _prev(nullptr)
		{			
		}

		T _data;
		Node * _next;
		Node * _prev;
	};

	class Iterator
	{
	public:
		Iterator(Node* node)
			:_node(node)
		{
		}

		T &operator *()
		{
			return _node->_data;
		}

		Iterator& operator ++()
		{
			_node = _node->_next;
			return *this;
		}

		Iterator& operator --()
		{
			_node = _node->_prev;
			return *this;
		}

		bool operator ==(Iterator & a)
		{
			return _node == a._node;
		}

		bool operator !=(Iterator & a)
		{
			return _node != a._node;
		}

	private:
		Node * _node;
	};

	Iterator Begin()
	{
		return Iterator(_begin);
	}

	Iterator End()
	{
		return Iterator(nullptr);
	}

	Iterator Find(T& data)
	{
		for (auto i = Begin(); i != End(); ++i)
		{
			if (*i == data)
			{
				return i;
			}
		}

		return End();
	}

	Iterator AddAfter(Iterator position, T &data)
	{

	}

	Iterator AddBefore(Iterator position, T &data)
	{

	}

private:
	Node * _begin;
	Node * _end;


	
};