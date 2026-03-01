
#include "Tree.h"

using namespace std;
#include <iostream>
#include <vector>


Tree::Tree() {

	root = nullptr;
}

void Tree::inOrderHelper() {

	inOrderTraversal(root);

}

void Tree::inOrderTraversal(Node* currentNode) {

	if (currentNode == nullptr) {
		return;
	}

	inOrderTraversal(currentNode->left);
	cout << currentNode->data;
	inOrderTraversal(currentNode->right);
}

void Tree::insertHelper(string value) {

	root = insert(root, value);
}

Node* Tree::insert(Node* currentNode, string value) {

	if (currentNode == nullptr) {
		return new Node(value);
	}

	if (value < currentNode->data) {
		currentNode->left = insert(currentNode->left, value);
	}
	if (value > currentNode->data) {
		currentNode->right = insert(currentNode->right, value);
	}
	return currentNode;
}


Node* Tree::searchHelper(string value) {

	return search(root, value);
}

Node* Tree::search(Node* currentNode, string value) {

	if (currentNode == nullptr) {
		return nullptr;
	}

	if (currentNode->data == value) {
		return currentNode; // ??
	}

	if (value < currentNode->data) {
		return insert(currentNode->left, value);

	}
	if (value > currentNode->data) {
		return insert(currentNode->right, value);
	}
	// No return !!

}

Node* Tree::findMin(Node* currentNode) {

	while (currentNode->left != nullptr) {
		currentNode = currentNode->left;
		return currentNode;
	}
}

void Tree::deleteNodeHelper(string value) { // VOID 

	root = deleteNode(root, value); // ROOT = 
}

Node* Tree::deleteNode(Node* currentNode, string value) {

	if (currentNode == nullptr) {
		return nullptr;

	}

	// Recursion type A (like insert)

	if (value < currentNode->data) {
		currentNode->left = deleteNode(currentNode->left, value);
	}
	else if (value > currentNode->data) {
		currentNode->right = deleteNode(currentNode->right, value);
	}
	else {

		// Case 1 no children
		if (currentNode->left == nullptr && currentNode->right == nullptr) {
			delete currentNode;
			return nullptr;
		}
		
		// Case 2 a
		if (currentNode->left == nullptr) {
			Node* temp = currentNode->right;
			delete currentNode; // just delete the node nothing fancy 
			return temp; // and then reutrn temp 
		}

		if (currentNode->right == nullptr) {
			Node* temp = currentNode->left;
			delete currentNode;
			return temp;
		}
		if (currentNode->left != nullptr && currentNode->right != nullptr) {

			Node* successor = findMin(currentNode->right); // Go right and find the min
			currentNode->data = successor->data; // Put the succsors value in this node 
			currentNode->right = deleteNode(currentNode->right, successor->data); // find the successor and delete will be case 2 a or 2 b 

		}
		return currentNode;
	}
}