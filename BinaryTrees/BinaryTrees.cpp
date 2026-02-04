
#include <iostream>
#include "BinaryTrees.h"
using namespace std;

int add(int a, int b) {

	return a + b;
}

double avg(double a, double b) {

	return (a + b) / 2; 
}


Node::Node(int value) // Constructor cpp for node 
{
	data = value;
	left = nullptr; // left right start empty 
	right = nullptr;
}


//Constructor for binary tree

BinaryTree::BinaryTree()
{
	root = nullptr; // Start tree empty 
}

// Manually create a simple tree
void BinaryTree::createSimpleTree()
{
	root = new Node(1);

	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);

}

// public function to begin inorder transerval  - lit moving to left 
void BinaryTree::inorder() {

	inOrderTraversal(root);
	cout << endl;
}


// RECURSIVE  - lit sped to left base case node == nullptr 
void BinaryTree::inOrderTraversal(Node* node) {

	
	if (node == nullptr)
		return;
	

	inOrderTraversal(node->left);

	//Once base clause reached do this code below 

	// Tell about current nodes why not sure look 
	cout << node->data << " ";

	inOrderTraversal(node->right);


}