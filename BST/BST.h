#ifndef BST_H
#define BST_H

#include "BSTNode.h"

class BST :public BSTNode{
	BSTNode *root;

	void insert(BSTNode *, BSTNode *);
	void destroySubTree(BSTNode *);
	void deleteNode(char, BSTNode *);
	void makeDeletion(BSTNode *);
	void displayInOrder(BSTNode*) const;
	void displayPreOrder(BSTNode*) const;
	void displayPostOrder(BSTNode *) const;

public:
	BST(): BSTNode() {
		root = nullptr;
	}

	//destructor
	~BST() {
		destroySubTree(root);
	}

	// Binary tree operations
	void insertNode(char ec, string mc);
	BSTNode* searchNode(char);
	void remove(char);

	void displayInOrder() const
	{
		displayInOrder(root);
	}

	void displayPreOrder() const
	{
		displayPreOrder(root);
	}

	void displayPostOrder() const
	{
		displayPostOrder(root);
	}



};


#endif
