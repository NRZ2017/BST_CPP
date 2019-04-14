#pragma once
#include "BST_Node.h"
#include <memory>

template <typename T>
class BST_Node
{
public:
	T Data;
	std::unique_ptr<BST_Node<T>> LeftChild;
	std::unique_ptr<BST_Node<T>> RightChild;
	BST_Node<T>* Parent;

	bool IsLeftChild();
	bool IsRightChild();
	int ChildCount();
	std::unique_ptr<BST_Node<T>>& FirstChild();
	
	BST_Node(T data, BST_Node<T>* parent = nullptr)
	{
		Data = data;
		Parent = parent;
	}

private:

};

template <typename T>
bool BST_Node<T>::IsLeftChild()
{
	if (Parent == nullptr)
	{
		return false;
	}
	else
	{
		return Parent->LeftChild.get() == this;
	}
}

template <typename T>
bool BST_Node<T>::IsRightChild()
{
	if (Parent == nullptr)
	{
		return false;
	}
	else
	{
		return Parent->RightChild.get() == this;
	}
}

template <typename T>
int BST_Node<T>::ChildCount()
{
	int childCount = 0;
	if (LeftChild != nullptr)
	{
		childCount++;
	}
	if (RightChild != nullptr)
	{
		childCount++;
	}
	return childCount;
}
template <typename T>
std::unique_ptr<BST_Node<T>>& BST_Node<T>::FirstChild()
{
	if (LeftChild != nullptr)
	{
		return LeftChild;
	}
	else// if (RightChild != nullptr)
	{
		return RightChild;
	}
}
