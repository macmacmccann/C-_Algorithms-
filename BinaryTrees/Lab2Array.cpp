

#include "Lab2Array.h"
#include <iostream>
#include <vector>




Node::Node(char value)
{
	data = value;
	left = nullptr; // left right start empty 
	right = nullptr;
}


//Constructor for binary tree

BinaryTree::BinaryTree()
{
	root = nullptr;
}

BinaryTree::~BinaryTree() {
	destroy(root);
}

// post order delete 
// Why cos delete left and right before subtree root 
void BinaryTree::destroy(Node* node) {
	if (!node) return;

	destroy(node->left);
	destroy(node->right);
	delete node;
}



void BinaryTree::buildFromArray(const vector<char>& arr)
{

	root = buildFromArrayRec(arr, 0, arr.size() - 1);
}

// Divide conquer ( n log n ) 

// Rescurively choose the mid element of each subarray 
// Use elements before mid for left subtree
// use elements after mid for right subtree 
Node* BinaryTree::buildFromArrayRec(const vector<char>& arr, int start, int end) {

	if (start > end)
		return nullptr;

	// Get middle index 
	int mid = (start + end) / 2;

	// Create a node in the middle index - 
	// this is the root 
	Node* node = new Node(arr[mid]);

	// Build the left subtree 
	node->left = buildFromArrayRec(arr, start, mid - 1);

	// build the right subtree  
	node->right = buildFromArrayRec(arr, mid + 1, end);

	// return this node as the root 
	return node;

}



void BinaryTree::inorder()
{
	inOrderTraversal(root); // start traversal
	std::cout << std::endl;
}

// recursive inorder helper
void BinaryTree::inOrderTraversal(Node* node)
{
	if (node == nullptr)
		return;

	inOrderTraversal(node->left);
	std::cout << node->data << " ";
	inOrderTraversal(node->right);
}



// public search function use in main
bool BinaryTree::search(char value)
{
	return search(root, value);
}

// recursive search helper
bool BinaryTree::search(Node* node, char value)
{
	// if node is null, value not found
	if (node == nullptr)
		return false;

	// if value matches, return true
	if (node->data == value)
		return true;

	// search left or right depending on value
	if (value < node->data)
		return search(node->left, value);
	else
		return search(node->right, value);
}



// Show the shape of the tree 
void BinaryTree::display()
{
	display(root, 0);
}


// depth int uses to indent output so i can see 
void BinaryTree::display(Node* node, int depth)
{
	if (node == nullptr)
		return;

	display(node->right, depth + 1); //  " the right is 1 level deeper" print depth + four spaces  

	for (int i = 0; i < depth; i++) // if depth = 3 then 3 couts printed ( i) 
		cout << "    ";

	cout << node->data << endl; // Print data after spaces 

	display(node->left, depth + 1); // Then recusrively call left 
}