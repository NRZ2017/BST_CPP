#include "BST.h";
#include "BST_Node.h"

int main()
{
	BST<int>* tree = new BST<int>();
	tree->Insert(0);
	tree->Insert(1);
	tree->Insert(3);
	tree->Insert(4);
	tree->Insert(5);
	tree->Insert(6);
	tree->Insert(7);
	tree->Insert(8);
	tree->Insert(9);
	tree->Insert(10);
	tree->Delete(10);
	tree->Delete(9);
	tree->Delete(8);
	tree->Delete(7);
	tree->Delete(6);
	tree->Delete(5);
	tree->Delete(4);
	tree->Delete(3);
	tree->Delete(2);
	tree->Delete(1);
	tree->Delete(0);
};