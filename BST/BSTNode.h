#ifndef BSTNODE_H
#define BSTNODE_H

#include <iostream>
#include <cctype>
#include <string>
#include <fstream>

using namespace std;

//this is the definition for the node in the BST tree
class BSTNode{
	char en_char;
	string mo_char;
	BSTNode *left, *right;

public:
	
	BSTNode() {
		en_char = ' ';
		mo_char = " ";
		left = nullptr;
		right = nullptr;
	}

	virtual ~BSTNode() {}

	BSTNode(char ec, string mc) {
		en_char = ec;
		mo_char = mc;
	}

	//deletes node (pass node)
	void deletenode(BSTNode* node);

	void set_en_char(char e);

	void set_mo_char(string m);

	void set_left_ptr(BSTNode *node, BSTNode *newptr);

	void set_right_ptr(BSTNode *node, BSTNode *newptr);

	char get_en_char(void);

	string get_mo_char(void);

	BSTNode* get_left_ptr(void);

	BSTNode* get_right_ptr(void);


};



#endif
