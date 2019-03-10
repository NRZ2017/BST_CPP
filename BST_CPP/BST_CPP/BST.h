#pragma once
#include "BST_Node.h"
#include <memory>

template <typename T>
class BST
{
private:
	int count = 0;

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
		std::shared_ptr<BST_Node<T>> tempNode = Root;
		while (tempNode != nullptr)
		{
			if (value < tempNode->Data)
			{
				tempNode = tempNode->LeftChild;
				return;
			}
			else if (value > tempNode->Data)
			{
				tempNode = tempNode->RightChild;
				return;
			}
			else
			{
				count--;
				return true;
			}
		}
	}

};
