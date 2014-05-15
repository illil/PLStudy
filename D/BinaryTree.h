#pragma  once

#include <algorithm>

template <typename T,typename Less = std::less<T>>
class AVLTree
{

private:

	class Node
	{
	public:
		Node(const T &data)
			:_left(nullptr), _right(nullptr), _data(data),  _parent(nullptr), _height(0)
		{}

		void SetRoot()
		{
			_parent = nullptr;
		}
		
		void SetLeft(Node *node)
		{
			_left = node;
			if (node != nullptr)
				node->_parent = this;
		}

		void SetRight(Node *node)
		{
			_right = node;
			if (node != nullptr)
				node->_parent = this;
		}

		void ResetHeight()
		{
			_height = std::max(GetLeftHeight(), GetLeftHeight()) + 1;
		}


		void IncreasHeight()
		{
			_height++;

			if (_parent != nullptr &&
				_parent->_height <= _height + 1 &&
				_parent->IsBalance())
			{
				_parent->IncreasHeight();
			}
		}

		void AddLeft(const T &data)
		{
			SetLeft(new Node(data));
			if (_right == nullptr)
				IncreasHeight();
		}

		void AddRight(const T &data)
		{
			SetRight(new Node(data));
			if (_left == nullptr)
				IncreasHeight();
		}


		Node * AddChild(const T &data, Less & less)
		{
			if (less(data, _data))
			{
				if (_left == nullptr)
				{
					AddLeft(data);
					return _left;
				}
				else
				{
					return _left->AddChild(data, less);
				}
			}
			else if (less(_data, data))
			{
				if (_right == nullptr)
				{
					AddRight(data);
					return _right;
				}
				else
				{
					return _right->AddChild(data, less);
				}
			}
			else
			{
				throw std::exception("");
			}
		}


		Node * FindUnbalacedAncestor()
		{
			if (!IsBalance())
				return this;

			if (_parent == nullptr)
				return nullptr;

			return _parent->FindUnbalacedAncestor();
		}
		
		
		bool IsLeft()
		{
			return _parent->_left == this;
		}

		bool IsRight()
		{
			return _parent->_right == this;
		}

		bool IsBalance()
		{
			int balanace = GetBalance();
			return balanace < 2 && balanace >-2;
		}

		int GetBalance()
		{
			return GetLeftHeight() - GetRightHeight();
		}

		int GetLeftHeight()
		{
			return _left == nullptr ? -1 : _left->_height;
		}

		int GetRightHeight()
		{
			return _right == nullptr ? -1 : _right->_height;
		}


		T _data;
		Node * _left;
		Node * _right;
		Node * _parent;
		int _height;
	};

public:

	AVLTree(Less less=Less())
		:_root(nullptr), _less(less)
	{
	}


	void Add(const T & data)
	{
		if (_root == nullptr)
		{
			_root = new Node( data);
		}
		else
		{
			auto addedNode = _root->AddChild(data,_less);
			auto unbalancedNode = addedNode->FindUnbalacedAncestor();
				

			if (unbalancedNode != nullptr)
			{
				if (unbalancedNode->GetBalance() >= 2)
				{
					if (unbalancedNode->_left->GetBalance() > 0)
					{
						SingleRotation(unbalancedNode, true);
					}
					else
					{
						SingleRotation(unbalancedNode->_left, false);
						SingleRotation(unbalancedNode, true);
					}
				}
				else
				{
					if (unbalancedNode->_right->GetBalance() < 0)
					{
						SingleRotation(unbalancedNode, false);
					}
					else
					{
						SingleRotation(unbalancedNode->_right, true);
						SingleRotation(unbalancedNode, false);
					}
				}
			}
		}
	}	

private:


	void SetRoot(Node *node)
	{
		_root = node;
		node->SetRoot();
	}


	void SingleRotation(Node *axis, bool isRight)
	{
		Node* parent = axis->_parent;
		Node* newAxis = isRight ? axis->_left : axis->_right;

		if (parent != nullptr)		
		{
			if (parent->_left == axis)
				parent->SetLeft(newAxis);
			else
				parent->SetRight(newAxis);
		}

		if (axis == _root)
		{
			SetRoot(newAxis);
		}

		if (isRight)
		{
			axis->SetLeft(newAxis->_right);
			newAxis->SetRight(axis);
		}
		else
		{
			axis->SetRight(newAxis->_left);
			newAxis->SetLeft(axis);
		}

		axis->ResetHeight();
		newAxis->ResetHeight();
	}



	Node * _root;
	Less _less;
};