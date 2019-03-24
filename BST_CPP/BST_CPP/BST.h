#pragma once
#include "BST_Node.h"
#include <memory>

template <typename T>
class BST
{
private:
	int count = 0;

	bool Delete(BST_Node<T>* node)
	{
		if (node->ChildCount == 2)
		{
			BST_Node<T>* fin = Minimum(node->RightChild.get());
			node->Data = fin->Data;
			node = fin;
		}

		if (node->ChildCount == 1)
		{
			//connect parent to the 1 child

		}
		else if (node->ChildCount == 0)
		{
			if (node == Root.get())
			{
				Root == nullptr;
			}
			else if (node->IsLeftChild)
			{
				node->Parent->LeftChild = nullptr;
			}
			else if (node->IsRightChild)
			{
				node->Parent->RightChild = nullptr;
			}

		}
	}

	BST_Node<T>* Minimum(BST_Node<T>* node)
	{
		while (node->LeftChild != nullptr)
		{
			node = node->LeftChild.get();
		}
		return node;
	}

	BST_Node<T> Maximum(BST_Node<T> node)
	{
		while (node.RightChild != nullptr)
		{
			node = *node.RightChild;
		}
		return node;
	}

	BST_Node<T>* Find(T value)
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
	}
public:
	const int& Count = count;

	bool IsEmpty()
	{
		return count == 0;
	}

	std::shared_ptr<BST_Node<T>> Root;

	bool Contains(T key)
	{
		std::shared_ptr<BST_Node<T>> curr = Root;
		while (curr != nullptr)
		{
			if (key < curr->Data)
			{
				curr = curr->LeftChild;
				return;
			}
			else if (key > curr->Data)
			{
				curr = curr->RightChild;
				return;
			}
			else
			{
				return true;
			}
			return false;
		}
	}

	bool Delete(T value)
	{
		BST_Node<T>* toDelete = Find(value);
		if (toDelete == nullptr)
		{
			return false;
		}
		Delete(toDelete);
		count--;
		return true;
	}

	void Insert(T value)
	{
		count++;
		if (Root == nullptr)
		{
			Root = new BST_Node<T>(value);
			return;
		}
		BST_Node<T>* curr = Root.get();
		while (curr != nullptr)
		{
			if (value < curr->Data)
			{
				curr->LeftChild = new BST_Node<T>(value);
				break;
			}
			curr = curr->LeftChild.get();

			else
			{
				if (curr.RightChild != nullptr)
				{
					curr.RightChild = new BST_Node<T>(value);
					break;
				}
				curr = *curr.RightChild;
			}
		}





	}

};
