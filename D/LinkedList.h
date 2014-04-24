#pragma once

template <typename T> class LinkedList
{
public:
	LinkedList() 
		:_begin(nullptr), _end(nullptr), _count(0)
	{

	}

	~LinkedList()
	{
		Clear();
	}

	void PushBack(T &data)
	{
		AddBefore(_begin, data);
	}

	void PushFront(T &data)
	{
		AddAfter(_end, data);
	}

	bool RemoveFirst()
	{
		if (_begin == nullptr)
			return false;		
		Remove(_begin);
		return true;
	}

	bool RemoveLast()
	{
		if (_begin == nullptr)
			return false;
		Remove(_end);
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


	class Node;

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

		Iterator operator +(int i)
		{
			auto node = _node;
			while (i-- && node)
			{
				node = node->_next;
			}

			return Iterator( node);
		}

		Iterator operator -(int i)
		{
			auto node = _node;
			while (i-- && node)
			{
				node = node->_prev;
			}

			return Iterator( node);
		}

		bool operator ==(Iterator & a)
		{
			return _node == a._node;
		}

		bool operator !=(Iterator & a)
		{
			return _node != a._node;
		}


		friend LinkedList;
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

	Iterator FindFirst(T& data)
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

	Iterator FindFirst(std::function<bool(T&)> predict)
	{
		for (auto i = Begin(); i != End(); ++i)
		{
			if (predict(*i))
			{
				return i;
			}
		}
		return End();
	}

	
	Iterator AddAfter(Iterator &iter, T &data)
	{
		CheckIter(iter);
		return Iterator(AddAfter(iter._node, data));
	}

	Iterator AddBefore(Iterator &iter, T &data)
	{
		CheckIter(iter);
		return Iterator(AddBefore(iter._node, data));
	}

	Iterator Remove(Iterator &iter)
	{
		CheckIter(iter);
		return Iterator(Remove(iter._node));
	}


	int Count()
	{
		return _count;
	}

private:

	void CheckIter(Iterator &iter)
	{
		if (iter._node->_list != this)
		{
			throw new std::exception("±è´öÀÏ °°´Ù");
		}
	}

	Node* AddBefore(Node * node, T&data)
	{
		auto newNode = new Node(this,data);

		if (node == nullptr)
		{
			_begin = _end = newNode;
		}
		else
		{
			Link(node->_prev, newNode);
			Link(newNode, node);

			if (node == _begin)
				_begin = newNode;
		}
		++_count;
		return newNode;
	}

	Node* AddAfter(Node * node, T&data)
	{
		auto newNode = new Node(this,data);

		if (node == nullptr)
		{
			_begin = _end = newNode;
		}
		else
		{
			auto next = node->_next;
			Link(node, newNode);
			Link(newNode, next);

			if (node == _end)
				_end = newNode;
		}

		++_count;
		return newNode;
	}

	void Link(Node *prev, Node *next)
	{		
		if (prev != nullptr)
		{
			prev->_next = next;
		}
		if (next != nullptr)
		{
			next->_prev = prev;
		}
	}

	Node* Remove(Node *node)
	{
		if (_begin == nullptr)
			return nullptr;

		auto next = node->_next;

		if (node->_prev == nullptr)
		{
			_begin = node->_next;
		}
		else
		{
			node->_prev->_next = node->_next;
		}

		if (node->_next == nullptr)
		{
			_end = node->_prev;
		}
		else
		{
			node->_next->_prev = node->_prev;
		}

		delete node;
		--_count;
		return next;
	}

	class Node
	{
	public:
		Node(LinkedList * list, T & data)
			:_list(list),_data(data), _next(nullptr), _prev(nullptr)
		{
		}

		LinkedList* _list;
		T _data;
		Node * _next;
		Node * _prev;
	};

	Node * _begin;
	Node * _end;
	int _count;

	
};