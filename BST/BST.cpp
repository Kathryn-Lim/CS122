
#include "BST.h"


void BST::insert(BSTNode *nodePtr, BSTNode *newNode)
{
	if (nodePtr == nullptr)
		nodePtr = newNode;                  // Insert the node.
	else if (newNode->get_en_char() < nodePtr->get_en_char())
		insert(nodePtr->get_left_ptr(), newNode);     // Search the left branch
	else
		insert(nodePtr->get_right_ptr(), newNode);    // Search the right branch
}

void BST::insertNode(char ec, string mc)
{
	BSTNode *newNode = nullptr;	// Pointer to a new node.

	newNode = new BSTNode;
	newNode->set_en_char(ec);
	newNode->set_left_ptr(newNode,nullptr);
	newNode->set_right_ptr(newNode,nullptr);

	// Insert the node.
	insert(root, newNode);
}


void BST::destroySubTree(BSTNode *nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->get_left_ptr())
			destroySubTree(nodePtr->get_left_ptr());
		if (nodePtr->get_right_ptr())
			destroySubTree(nodePtr->get_right_ptr());
		delete nodePtr;
	}
}


BSTNode* BST::searchNode(char ec)
{
	BSTNode *nodePtr = root;

	while (nodePtr)
	{
		if (nodePtr->get_en_char() == ec)
			return nodePtr;
		else if (ec < nodePtr->get_en_char())
			nodePtr = nodePtr->get_left_ptr();
		else
			nodePtr = nodePtr->get_right_ptr();
	}
	return nodePtr;
}

void BST::remove(char ec)
{
	deleteNode(ec, root);
}



void BST::deleteNode(char ec, BSTNode *nodePtr)
{
	if (ec < nodePtr->get_en_char())
		deleteNode(ec, nodePtr->get_left_ptr());
	else if (ec < nodePtr->get_en_char())
		deleteNode(ec, nodePtr->get_right_ptr());
	else
		makeDeletion(nodePtr);
}


void BST::makeDeletion(BSTNode *nodePtr)
{
	BSTNode *tempNodePtr = nullptr;

	if (nodePtr == nullptr)
		cout << "Cannot delete empty node.\n";
	else if (nodePtr->get_right_ptr()== nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->get_left_ptr();   // Reattach the left child
		delete tempNodePtr;
	}
	else if (nodePtr->get_left_ptr() == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->get_right_ptr();  // Reattach the right child
		delete tempNodePtr;
	}
	// If the node has two children.
	else
	{
		// Move one node the right.
		tempNodePtr = nodePtr->get_right_ptr();
		// Go to the end left node.
		while (tempNodePtr->get_left_ptr())
			tempNodePtr = tempNodePtr->get_left_ptr();
		// Reattach the left subtree.
		tempNodePtr->set_left_ptr(tempNodePtr,nodePtr->get_left_ptr());
		tempNodePtr = nodePtr;
		// Reattach the right subtree.
		nodePtr = nodePtr->get_right_ptr();
		delete tempNodePtr;
	}
}

void BST::displayInOrder(BSTNode *nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->get_left_ptr());
		cout << nodePtr->get_en_char() << endl;
		cout << nodePtr->get_mo_char() << endl;
		displayInOrder(nodePtr->get_right_ptr());
	}
}


void BST::displayPreOrder(BSTNode *nodePtr) const
{
	if (nodePtr)
	{
		cout << nodePtr->get_en_char() << endl;
		cout << nodePtr->get_mo_char() << endl;
		displayPreOrder(nodePtr->get_left_ptr());
		displayPreOrder(nodePtr->get_right_ptr());
	}
}


void BST::displayPostOrder(BSTNode *nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->get_left_ptr());
		displayPostOrder(nodePtr->get_right_ptr());
		cout << nodePtr->get_en_char() << endl;
		cout << nodePtr->get_mo_char() << endl;
	}
}