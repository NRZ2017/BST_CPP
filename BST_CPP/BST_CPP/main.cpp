#include "BST.h";
#include "BST_Node.h"

int main()
{
	//Fix Insert: add reference to parent
	//During delete, remove the parent refernce

	BST<int>* tree = new BST<int>();
	while (true)
	{
		for (int i = 0; i < 100; i++)
		{
			tree->Insert(i);
		}
		for (int i = 0; i < 100; i++)
		{
			tree->Delete(i);
		}
	}
};