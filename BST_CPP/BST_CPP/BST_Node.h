#pragma once
#include "BST_Node.h"
#include <memory>

template <typename T>
class BST_Node
{
public:
	T Data;
	std::shared_ptr<BST_Node<T>> LeftChild;
	std::shared_ptr<BST_Node<T>> RightChild;
	std::shared_ptr<BST_Node<T>> Parent;

	 bool IsLeftChild = Parent == nullptr ? false : Parent->LeftChild == this;
	 bool IsRightChild = Parent == nullptr ? false : Parent->RightChild == this;

	int ChildCount()
	{
		int childCount = 0;
		if (LeftChild != nullptr)
		{
			childCount++;
			return childCount;
		}
		if (RightChild != nullptr)
		{
			childCount++;
			return childCount;
		}
		return childCount;
	}

	BST_Node<T>* FirstChild()
	{
		if (LeftChild != nullptr)
		{
			return LeftChild;
		}
		else if (RightChild != nullptr)
		{
			return RightChild;
		}
		else
		{
			return nullptr;
		}
	}
}

	BST_Node(T data, BST_Node<T> parent = nullptr)
	{
		Data = data;
		Parent = parent;
	}

private:

};