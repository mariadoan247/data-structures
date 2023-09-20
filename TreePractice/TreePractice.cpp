// TreePractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Node
{
public:

	char SID = 'X';
	
	Node* left = NULL;

	Node* right = NULL;

	Node* parent = NULL;
};

// Returns 1 for if it is a leaf Node and 0 otherwise
int isLeaf(Node* ptr)
{
	if (ptr->left == NULL && ptr->right == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// Returns the depth of the passed in Node
// We are not actually modifying the original ptr only a copy
// because it is passing by value not by sharing
int depth(Node* ptr)
{
	int depth = 0;

	// Traverses the tree starting from the parent of the passed in Node
	while (ptr->parent != NULL)
	{
		ptr = ptr->parent; // Goes to the parent

		++depth; // Increments depth
	}

	return depth;
}

// Pre-Order Enumeration method
void PreOrder(Node* root)
{
	cout << root->SID;

	if (root->left != NULL)
	{
		PreOrder(root->left);
	}

	if (root->right != NULL)
	{
		PreOrder(root->right);
	}
}

// Pre-Order Enumeration method
void PostOrder(Node* root)
{
	if (root->left != NULL)
	{
		PostOrder(root->left);
	}

	if (root->right != NULL)
	{
		PostOrder(root->right);
	}
	
	cout << root->SID;
}

// In-Order Enumeration method
void InOrder(Node* root)
{
	if (root->left != NULL)
	{
		InOrder(root->left);
	}

	cout << root->SID;

	if (root->right != NULL)
	{
		InOrder(root->right);
	}
}

int main()
{
	Node A, B, C, D, E, F;

	A.SID = 'A';
	B.SID = 'B';
	C.SID = 'C';
	D.SID = 'D';
	E.SID = 'E';
	F.SID = 'F';
	
	A.left = &B;
	A.right = &C;

	B.right = &E;
	B.parent = &A;

	C.left = &D;
	C.parent = &A;

	D.parent = &C;

	E.right = &F;
	E.parent = &B;

	F.parent = &E;

	// Implementing Pre-Order Enumeration using Recursion
	PreOrder(&A);
	cout << endl;

	//Implementing Post-Order Enumeration using Recursion
	PostOrder(&A);
	cout << endl;

	//Implementing In-Order Enumeration using Recursion
	InOrder(&A);
	cout << endl;

	//cout << isLeaf(&C) << isLeaf(&F) << endl;

	//cout << depth(&F) << ' ' << depth(&B) << ' ' << depth(&A);

	return 0;
}