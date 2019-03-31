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
	bool IsLeftChild();
	bool IsRightChild();
	int ChildCount();
	BST_Node<T>* FirstChild();
	BST_Node<T>* child(BST_Node<T>* node);
	
	BST_Node(T data, std::shared_ptr<BST_Node<T>> parent = nullptr)
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
		Parent->LeftChild = this->LeftChild;
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
		Parent->RightChild = this->RightChild;
	}
}

template <typename T>
int BST_Node<T>::ChildCount()
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
template <typename T>
BST_Node<T>* BST_Node<T>::FirstChild()
{
	if (LeftChild != nullptr)
	{
		return LeftChild.get();
	}
	else if (RightChild != nullptr)
	{
		return RightChild.get();
	}
	else
	{
		return nullptr;
	}
}

template <typename T>
BST_Node<T>* BST_Node<T>::child(BST_Node<T>* node)
{
	if (node->LeftChild == nullptr)
	{
		return node->RightChild.get();
	}
	else
	{
		return node->RightChild.get();
	}
}