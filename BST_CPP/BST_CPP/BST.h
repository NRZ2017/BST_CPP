#pragma once
#include "BST_Node.h"
#include <memory>

template <typename T>
class BST
{
private:
	int count = 0;
	bool dElete(BST_Node<T>* node);
	BST_Node<T>* Minimum(BST_Node<T>* node);
	BST_Node<T>* Maximum(BST_Node<T>* node);
	BST_Node<T>* Find(T value);
public:
	const int& Count = count;
	bool IsEmpty();
	std::unique_ptr<BST_Node<T>> Root;
	bool Contains(T key);
	bool Delete(T value);
	void Insert(T value);
};

template< typename T>
bool BST<T>::dElete(BST_Node<T>* node)
{
	if (node->ChildCount() == 2)
	{
		BST_Node<T>* fin = Minimum(node->RightChild.get());
		node->Data = fin->Data;
		node = fin;
	}
	if (node->ChildCount() == 1)
	{
		if (node == Root.get())
		{
			Root = move(node->FirstChild());
			Root->Parent = nullptr;
		}
		else if (node->IsLeftChild())
		{
			node->FirstChild()->Parent = node->Parent;
			node->Parent->LeftChild = move(node->FirstChild());
		}
		else if (node->IsRightChild())
		{
			node->FirstChild()->Parent = node->Parent;
			node->Parent->RightChild = move(node->FirstChild());
		}
	}
	else if (node->ChildCount() == 0)
	{
		if (node == Root.get())
		{
			Root = nullptr;
		}
		else if (node->IsLeftChild())
		{
			node->Parent->LeftChild = nullptr;
		}
		else if (node->IsRightChild())
		{
			node->Parent->RightChild = nullptr;
		}
	}
	return true;
};


template< typename T>
BST_Node<T>* BST<T>::Minimum(BST_Node<T>* node)
{
	while (node->LeftChild != nullptr)
	{
		node = node->LeftChild.get();
	}
	return node;
};

template< typename T>
BST_Node<T>* BST<T>::Maximum(BST_Node<T>* node)
{
	while (node->RightChild != nullptr)
	{
		node = node->RightChild.get();
	}
	return node;
};

template< typename T>
BST_Node<T>* BST<T>::Find(T value)
{
	BST_Node<T>* curr = Root.get();
	while (curr != nullptr)
	{
		if (curr->Data < value)
		{
			curr = curr->LeftChild.get();
		}
		else if (curr->Data > value)
		{
			curr = curr->RightChild.get();
		}
		else if (curr->Data == 0)
		{
			return curr;
		}
	}
};

template< typename T>
bool BST<T>::IsEmpty()
{
	return count == 0;
};

template< typename T>
bool BST<T>::Contains(T key)
{
	return Find(key) != nullptr;
};

template< typename T>
bool BST<T>::Delete(T value)
{
	BST_Node<T>* toDelete = Find(value);
	if (toDelete == nullptr)
	{
		return false;
	}
	dElete(toDelete);
	count--;
	return true;
};

template<typename T>
void BST<T>::Insert(T value)
{
	count++;
	if (Root == nullptr)
	{
		Root = std::make_unique<BST_Node<T>>(value);
		return;
	}
	BST_Node<T>* curr = Root.get();
	while (curr != nullptr)
	{
		if (value < curr->Data)
		{
			if (curr->LeftChild == nullptr)
			{
				curr->LeftChild = std::make_unique<BST_Node<T>>(value, curr);
				break;
			}

			curr = curr->LeftChild.get();
		}
		else
		{
			if (curr->RightChild == nullptr)
			{
				curr->RightChild = std::make_unique<BST_Node<T>>(value, curr);
				break;
			}
			curr = curr->RightChild.get();
		}
	}
};





