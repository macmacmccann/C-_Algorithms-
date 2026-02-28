

#include "Tree.h";

Tree::Tree() {
	root = nullptr; // Start at the top root 
}


void Tree::insertHelper(int value) {

	root = insert(root, value);

}

Node* Tree::insert(Node* node, int value) {
	{


	} 