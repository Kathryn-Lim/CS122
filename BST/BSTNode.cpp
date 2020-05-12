#include "BSTNode.h"

//deletes node (pass node)
void BSTNode::deletenode(BSTNode* node) {

	node->left->right = node->right;
	node->right->left = node->left;

	return;
}

void BSTNode::set_en_char(char e) {
	this->en_char = e;
	return;
}

void BSTNode::set_mo_char(string m) {
	this->mo_char = m;
	return;
}

void BSTNode::set_left_ptr(BSTNode *node, BSTNode *newptr) {
	node->left = newptr;
	return;
}

void BSTNode::set_right_ptr(BSTNode *node, BSTNode *newptr) {
	node->right = newptr;
	return;
}

char BSTNode::get_en_char(void) {
	return en_char;
}

string BSTNode::get_mo_char(void) {
	return mo_char;
}

BSTNode* BSTNode::get_left_ptr(void) {
	return left;
}
BSTNode* BSTNode::get_right_ptr(void) {
	return right;
}