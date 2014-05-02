#pragma  once

template <typename T,typename Less = std::less<T>>
class BinaryTree
{
public:

	BinaryTree(Less less=Less())
		:_root(nullptr), _less(less)
	{
	}

	bool IsExist(const T& data)
	{
		Node* current = _root;
		while (true)
		{
			if (_less(current->_data, data))
			{
				if (current->_right == nullptr)
				{
					return false;
				}
				current = current->_right;
			}
			else if (_less(data, current->_data))
			{
				if (current->_left == nullptr)
				{
					return false;
				}
				current = current->_left;
			}
			else
			{
				return true;
			}
		}
	}

	void Add(const T & data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
		}
		else
		{
			Node* current = _root;
			while (true)
			{
				if (_less(current->_data, data))
				{
					if (current->_right == nullptr)
					{
						current->_right = new Node(data);
						break;
					}
					current = current->_right;
				}
				else if (_less(data, current->_data))
				{
					if (current->_left == nullptr)
					{
						current->_left = new Node(data);
						break;
					}
					current = current->_left;
				}
				else
				{
					throw std::exception("");
				}
			}
		}
	}	

private:

	class Node
	{
	public:
		Node(const T &data)
			:_left(nullptr), _right(nullptr), _data(data)
		{}

		bool IsLeaf()
		{
			return _left == nullptr && _right == nullptr;
		}

		Node * _left;
		Node * _right;
		T _data;
	};

	Node * _root;
	Less _less;
};